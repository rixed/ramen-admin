#include "chart/TimeChartEditWidget.h"

#include <QCheckBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QTabWidget>
#include <QToolBox>
#include <QVBoxLayout>

#include "chart/TimeChartAxisEditor.h"
#include "chart/TimeChartFunctionEditor.h"
#include "chart/TimeChartFunctionFieldsModel.h"
#include "chart/TimeChartFunctionsEditor.h"
#include "chart/TimeChartOptionsEditor.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

static bool const verbose{false};

TimeChartEditWidget::TimeChartEditWidget(QPushButton *submitButton,
                                         QPushButton *cancelButton_,
                                         QPushButton *deleteButton_,
                                         QWidget *parent)
    : AtomicWidget(parent),
      cancelButton(cancelButton_),
      deleteButton(deleteButton_) {
  optionsEditor = new TimeChartOptionsEditor(this);
  functionsEditor = new TimeChartFunctionsEditor;

  /* Axis editor must know when a new axis is referenced in a function
   * editor, to offer to edit it: */
  connect(functionsEditor, &TimeChartFunctionsEditor::fieldChanged,
          optionsEditor, &TimeChartOptionsEditor::updateAfterFieldChange);

  // Forward some signals from the editors to the chart:
  connect(optionsEditor, &TimeChartOptionsEditor::axisChanged, this,
          &TimeChartEditWidget::axisChanged);
  connect(functionsEditor, &TimeChartFunctionsEditor::fieldChanged, this,
          &TimeChartEditWidget::fieldChanged);
  // TODO: connect those editors to our AtomicWidget::valueChanged signal?

  QHBoxLayout *buttonsLayout{new QHBoxLayout};
  buttonsLayout->addStretch();
  if (cancelButton) buttonsLayout->addWidget(cancelButton);
  if (submitButton) buttonsLayout->addWidget(submitButton);
  if (deleteButton) buttonsLayout->addWidget(deleteButton);

  QVBoxLayout *layout{new QVBoxLayout};
  layout->addWidget(optionsEditor, 0);
  layout->addWidget(functionsEditor, 1);
  layout->addLayout(buttonsLayout, 0);
  QWidget *w{new QWidget};
  w->setLayout(layout);
  relayoutWidget(w);
}

void TimeChartEditWidget::setEnabled(bool enabled) {
  optionsEditor->setEnabled(enabled);
  functionsEditor->setEnabled(enabled);
}

bool TimeChartEditWidget::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  if (v->index() != dessser::gen::sync_value::DashboardWidget) {
    /* Will happen if the underlying dashboard widget type changes.
     * Jut ignore it, the dashboard should notice and replace this
     * widget with a more appropriate one. */
  not_a_chart:
    qWarning() << "TimeChartEditWidget::setValue: "
               << "passed value is not a dessser::gen::dashboard_widget::chart";
    return false;
  }

  std::shared_ptr<dessser::gen::dashboard_widget::t const> widget{
      std::get<dessser::gen::sync_value::DashboardWidget>(*v)};
  if (widget->index() != dessser::gen::dashboard_widget::Chart)
    goto not_a_chart;
  std::shared_ptr<dessser::gen::dashboard_widget::chart const> conf{
      std::get<dessser::gen::dashboard_widget::Chart>(*widget)};

  if (verbose) {
    qDebug() << "TimeChartEditWidget::setValue: setting value" << *conf;
    if (key()) qDebug() << "(my key is " << *key() << ")";
  }

  optionsEditor->setValue(conf);
  functionsEditor->setValue(*conf);

  return true;
}

std::shared_ptr<dessser::gen::sync_value::t const>
TimeChartEditWidget::getValue() const {
  // Start from an empty configuration:
  std::shared_ptr<dessser::gen::dashboard_widget::chart> conf{std::make_shared<
      dessser::gen::dashboard_widget::chart>(
      optionsEditor->title->text().toStdString(),
      std::const_pointer_cast<dessser::gen::dashboard_widget::type>(
          chartPlotType),
      dessser::Arr<std::shared_ptr< ::dessser::gen::dashboard_widget::axis> >{},
      dessser::Arr<
          std::shared_ptr< ::dessser::gen::dashboard_widget::source> >{})};

  if (verbose)
    qDebug() << "TimeChartEditWidget::getValue: title ="
             << QString::fromStdString(conf->title);

  /* TODO: a signal from functionsEditor when a new axis is requested, that
   * would be connected to the AxisEditor.addAxis(where). */
  int const numAxes{optionsEditor->axes->count()};
  for (int a_idx = 0; a_idx < numAxes; a_idx++) {
    TimeChartAxisEditor const *axisEditor{
        static_cast<TimeChartAxisEditor const *>(
            optionsEditor->axes->widget(a_idx))};
    std::shared_ptr<dessser::gen::dashboard_widget::axis> axisConf{
        axisEditor->getValue()};
    conf->axes.push_back(axisConf);
  }

  int const numFunctions{functionsEditor->functions->count()};
  for (int f_idx = 0; f_idx < numFunctions; f_idx++) {
    TimeChartFunctionEditor const *funcEditor{
        static_cast<TimeChartFunctionEditor const *>(
            functionsEditor->functions->widget(f_idx))};
    conf->sources.push_back(funcEditor->getValue());
  }

  if (verbose)
    qDebug() << "TimeChartEditWidget::getValue: returning a value with"
             << conf->axes.size() << "axes and" << conf->sources.size()
             << "sources.";

  return std::make_shared<dessser::gen::sync_value::t>(
      std::in_place_index<dessser::gen::sync_value::DashboardWidget>,
      std::make_shared<dessser::gen::dashboard_widget::t>(
          std::in_place_index<dessser::gen::dashboard_widget::Chart>, conf));
}

int TimeChartEditWidget::axisCountOnSide(bool left) const {
  int count{0};
  int const tabCount{optionsEditor->axes->count()};
  for (int i = 0; i < tabCount; i++) {
    TimeChartAxisEditor const *axisEditor{
        static_cast<TimeChartAxisEditor const *>(
            optionsEditor->axes->widget(i))};
    if (axisEditor->left->isChecked() == left) count++;
  }
  return count;
}

std::optional<int> TimeChartEditWidget::firstAxisOnSide(bool left) const {
  int const tabCount{optionsEditor->axes->count()};
  for (int i = 0; i < tabCount; i++) {
    TimeChartAxisEditor const *axisEditor{
        static_cast<TimeChartAxisEditor const *>(
            optionsEditor->axes->widget(i))};
    if (axisEditor->left->isChecked() == left) return i;
  }
  return std::nullopt;
}

int TimeChartEditWidget::axisCount() const {
  return optionsEditor->axes->count();
}

std::shared_ptr<dessser::gen::dashboard_widget::axis const>
TimeChartEditWidget::axis(int num) const {
  if (num >= optionsEditor->axes->count()) {
    qWarning() << "TimeChartEditWidget: Asked axis number" << num
               << "but have only" << optionsEditor->axes->count();
    return nullptr;
  }

  TimeChartAxisEditor const *axisEditor{
      static_cast<TimeChartAxisEditor const *>(
          optionsEditor->axes->widget(num))};
  return axisEditor->getValue();
}

void TimeChartEditWidget::iterFields(
    std::function<void(std::string const &site, std::string const &program,
                       std::string const &function,
                       dessser::gen::dashboard_widget::field const &)>
        cb) const {
  int const numFunctions{functionsEditor->functions->count()};

  if (verbose)
    qDebug() << "TimeChartEditWidget: iter over" << numFunctions << "functions";

  for (int i = 0; i < numFunctions; i++) {
    TimeChartFunctionEditor const *funcEditor{
        static_cast<TimeChartFunctionEditor const *>(
            functionsEditor->functions->widget(i))};

    if (!funcEditor->visible->isChecked()) continue;

    dessser::gen::dashboard_widget::source const &source{
        funcEditor->model->source};
    for (std::shared_ptr<dessser::gen::dashboard_widget::field> const &field :
         source.fields) {
      if (field->representation->index() ==
          dessser::gen::dashboard_widget::Unused)
        continue;
      cb(source.name->site, source.name->program, source.name->function,
         *field);
    }
  }
}

void TimeChartEditWidget::closeEvent(QCloseEvent *event) {
  if (cancelButton && cancelButton->isEnabled()) {
    cancelButton->click();
  } else {
    // In some case the only option is to delete:
    if (deleteButton && deleteButton->isEnabled()) {
      deleteButton->click();
    }
  }
  AtomicWidget::closeEvent(event);
}
