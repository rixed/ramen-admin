// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "chart/TimeChartFunctionEditor.h"

#include <QCheckBox>
#include <QCompleter>
#include <QDebug>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QModelIndex>
#include <QPushButton>
#include <QTableView>
#include <QVBoxLayout>
#include <cstdlib>

#include "Automaton.h"
#include "ColorDelegate.h"
#include "ConfClient.h"
#include "FixedTableView.h"
#include "MakeSyncValue.h"
#include "Menu.h"
#include "Resources.h"
#include "RollButtonDelegate.h"
#include "chart/FactorsDelegate.h"
#include "chart/TimeChartAutomatonCustomize.h"
#include "chart/TimeChartFunctionFieldsModel.h"
#include "desssergen/dashboard_widget.h"
#include "desssergen/raql_value.h"
#include "desssergen/rc_entry.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "misc_dessser.h"
#include "source/SourcesWin.h"

static constexpr bool verbose{false};

namespace dessser {
namespace gen {
namespace program_run_parameter {
struct t;
}
}  // namespace gen
}  // namespace dessser

TimeChartFunctionEditor::TimeChartFunctionEditor(std::string const &site,
                                                 std::string const &program,
                                                 std::string const &function,
                                                 bool customizable,
                                                 QWidget *parent)
    : QWidget(parent) {
  visible = new QCheckBox(tr("Visible"));
  visible->setChecked(true);

  if (customizable) {
    customize = new QPushButton(tr("Customize"));
    connect(customize, &QPushButton::clicked, this,
            &TimeChartFunctionEditor::wantCustomize);
  } else {
    customize = nullptr;
  }

  openSource = new QPushButton(tr("Source…"));
  connect(openSource, &QPushButton::clicked, this,
          &TimeChartFunctionEditor::wantSource);

  Resources *r{Resources::get()};

  deleteButton = new QPushButton(r->deletePixmap, QString());
  connect(deleteButton, &QPushButton::clicked, this, &QWidget::deleteLater);

  model = new TimeChartFunctionFieldsModel(site, program, function);

  fields = new FixedTableView;
  fields->setModel(model);
  fields->setShowGrid(false);
  fields->setMinimumSize(80, 80);
  fields->resizeColumnsToContents();
  // Best thing after having all the editors open at once:
  fields->setEditTriggers(QAbstractItemView::AllEditTriggers);

  RollButtonDelegate *reprDelegate{new RollButtonDelegate};
  reprDelegate->addIcon(r->emptyIcon);
  reprDelegate->addIcon(r->lineChartIcon);
  reprDelegate->addIcon(r->stackedChartIcon);
  reprDelegate->addIcon(r->stackCenteredChartIcon);
  fields->setItemDelegateForColumn(
      TimeChartFunctionFieldsModel::ColRepresentation, reprDelegate);

  factorsDelegate = new FactorsDelegate(this);
  factorsDelegate->setColumns(model->factors);
  fields->setItemDelegateForColumn(TimeChartFunctionFieldsModel::ColFactors,
                                   factorsDelegate);

  ColorDelegate *colorDelegate{new ColorDelegate};
  fields->setItemDelegateForColumn(TimeChartFunctionFieldsModel::ColColor,
                                   colorDelegate);

  /*
   * Emit fieldChanged whenever the underlying model data is changed:
   */

  connect(model, &QAbstractTableModel::dataChanged, this,
          [this](QModelIndex const &topLeft, QModelIndex const &bottomRight) {
            if (verbose)
              qDebug() << "TimeChartFunctionEditor: model data changed from row"
                       << topLeft.row() << "to" << bottomRight.row();
            // First reset the factors used by the delegate:
            factorsDelegate->setColumns(model->factors);
            // Then emit fieldChanged for every changed fields:
            int const lastRow{bottomRight.row()};
            dessser::gen::dashboard_widget::source const &source{model->source};
            for (int row = topLeft.row(); row <= lastRow; row++) {
              /* Model row correspond to numericFields not source.fields! */
              if (row > model->numericFields.count()) {
                qCritical(
                    "TimeChartFunctionEditor: dataChanged on row %d but model "
                    "has only %d rows!",
                    row, int(model->numericFields.count()));
                break;
              }
              if (verbose)
                qDebug() << "TimeChartFunctionEditor: fieldChanged"
                         << model->numericFields[row];
              emit fieldChanged(source.name.site, source.name.program,
                                source.name.function,
                                model->numericFields[row].toStdString());
            }
          });

  connect(model, &QAbstractTableModel::modelReset, this, [this]() {
    if (verbose) qDebug() << "TimeChartFunctionEditor: model data reset";
    for (QString const &numericField : qAsConst(model->numericFields)) {
      if (verbose)
        qDebug() << "TimeChartFunctionEditor: fieldChanged" << numericField;
      dessser::gen::dashboard_widget::source const &source{model->source};
      emit fieldChanged(source.name.site, source.name.program,
                        source.name.function, numericField.toStdString());
    }
  });

  QHBoxLayout *topHBox{new QHBoxLayout};
  topHBox->setObjectName("topHBox");
  topHBox->addWidget(visible);
  topHBox->addStretch();
  if (customize) topHBox->addWidget(customize);
  topHBox->addWidget(openSource);
  topHBox->addWidget(deleteButton);

  QVBoxLayout *layout{new QVBoxLayout};
  layout->addLayout(topHBox);
  layout->addWidget(fields);
  setLayout(layout);
}

void TimeChartFunctionEditor::wantSource() {
  if (!Menu::sourcesWin) return;

  Menu::sourcesWin->showFile(
      srcPathFromProgramName(model->source.name.program));
  Menu::openSourceEditor();
}

/* Customization is a multi step process:
 * 1. Create a new source that selects everything from that function;
 * 2. Once created, displays it in the editor;
 * 3. Once compiled, run it on this site only where the original run;
 * 4. Once the worker is received, substitute the plotted function with
 *    this custom one. */

void TimeChartFunctionEditor::wantCustomize() {
  TimeChartAutomatonCustomize *automaton{new TimeChartAutomatonCustomize(
      model->source.name.site, model->source.name.program,
      model->source.name.function, this)};

  connect(automaton, &TimeChartAutomatonCustomize::transitionTo, this,
          &TimeChartFunctionEditor::automatonTransition);

  std::unique_ptr<dessser::gen::sync_value::t const> newSource{ofString(
      "DEFINE LAZY '" + automaton->customFunction +
      "' AS\n"
      "  SELECT\n"
      "    *\n"  // TODO: rather list the fields explicitly, with their doc
      "  FROM '" +
      model->source.name.program + "/" + model->source.name.function +
      "' ON THIS SITE;\n")};

  Menu::getClient()->sendNew(*automaton->sourceKey, *newSource);
}

void TimeChartFunctionEditor::automatonTransition(
    Automaton *automaton_, size_t state,
    std::shared_ptr<dessser::gen::sync_value::t const> val) {
  qInfo() << "TimeChartFunctionEditor: automaton entering state" << state;

  TimeChartAutomatonCustomize *automaton{
      dynamic_cast<TimeChartAutomatonCustomize *>(automaton_)};
  if (!automaton) {
    qCritical() << "TimeChartFunctionEditor::automatonTransition:"
                   " not a TimeChartAutomatonCustomize?!";
    return;
  }

  switch (state) {
    case TimeChartAutomatonCustomize::WaitSource:
      qFatal(
          "TimeChartFunctionEditor::automatonTransition: reached unreachable "
          "state");

    case TimeChartAutomatonCustomize::WaitInfo:
      qInfo() << "TimeChartFunctionEditor: displaying the customized source";
      Menu::sourcesWin->showFile(automaton->sourceKey);
      Menu::openSourceEditor();
      break;

    case TimeChartAutomatonCustomize::WaitLockRC:
      qInfo() << "TimeChartFunctionEditor: locking the target "
                 "running configuration";
      {
        // Check that compilation worked
        std::optional<dessser::gen::source_info::compiled_program const> comp{
            getCompiledProgram(*val)};
        if (!comp) {
          qCritical() << "key" << *automaton->infoKey
                      << "not a SourceInfo, or compilation failed?!";
          automaton->deleteLater();
          return;
        }
        // Lock target_config
        Menu::getClient()->sendLock(*targetConfig);
      }
      break;

    case TimeChartAutomatonCustomize::WaitWorkerOrGraph:
      qInfo() << "TimeChartFunctionEditor: running that program";
      {
        dessser::Arr<dessser::gen::rc_entry::t> const *rc{
            getTargetConfig(*val)};
        if (!rc) {
          qCritical() << "target_config not a TargetConfig?!";
          automaton->deleteLater();
          return;
        }
        // Look at the RC for this function for inspiration:
        std::optional<dessser::gen::rc_entry::t> sourceEntry;
        for (dessser::gen::rc_entry::t const &rce : *rc) {
          /* Ideally check also the site: */
          if (rce.program == model->source.name.program) {
            sourceEntry = rce;
            break;
          }
        }
        if (!sourceEntry) {
          qWarning() << "Cannot find program"
                     << QString::fromStdString(model->source.name.program)
                     << "in the RC file";
          automaton->deleteLater();
          return;
        }
        // Create a new array with all same entries (shared) + rce:
        dessser::Arr<dessser::gen::rc_entry::t_ext> rc2{*rc};
        rc2.emplace_back(automaton->customProgram,
                         true,  // enabled
                         sourceEntry->debug, sourceEntry->report_period,
                         sourceEntry->cwd,
                         dessser::Arr<dessser::gen::program_run_parameter::t>{},
                         model->source.name.site,
                         false);  // automatic
        dessser::gen::sync_value::t target_config{
            std::in_place_index<dessser::gen::sync_value::TargetConfig>, rc2};
        Menu::getClient()->sendSet(*targetConfig, target_config);
      }
      break;

    case TimeChartAutomatonCustomize::Done:
      qInfo() << "TimeChartFunctionEditor: Substituting customized function "
                 "in the current chart.";
      emit customizedFunction(automaton->site, automaton->customProgram,
                              automaton->customFunction);
      break;
  }
}

void TimeChartFunctionEditor::setEnabled(bool enabled) {
  visible->setEnabled(enabled);
  if (customize) customize->setEnabled(enabled);
  openSource->setEnabled(enabled);
}

bool TimeChartFunctionEditor::setValue(
    dessser::gen::dashboard_widget::source const &source) {
  if (source.visible != visible->isChecked()) {
    visible->setChecked(source.visible);
  }
  /* Will trigger QAbstractTableModel::resetModel and thus fieldChanged: */
  bool const ret{model->setValue(source)};

  /* Offer to delete (without confirmation dialog) a function as long as
   * it has no field drawn: */
  deleteButton->setEnabled(!model->hasSelection());

  return ret;
}

std::shared_ptr<dessser::gen::dashboard_widget::source>
TimeChartFunctionEditor::getValue() const {
  std::shared_ptr<dessser::gen::dashboard_widget::source> source{
      std::make_shared<dessser::gen::dashboard_widget::source>(model->source)};
  source->visible = visible->isChecked();
  return source;
}
