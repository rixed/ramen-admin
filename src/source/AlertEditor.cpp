// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "AlertEditor.h"

#include <dessser/Arr.h>

#include <QCheckBox>
#include <QCompleter>
#include <QDebug>
#include <QDoubleValidator>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QRadioButton>
#include <QRegularExpressionValidator>
#include <QStringListModel>
#include <QVBoxLayout>
#include <cmath>

#include "FilterEditor.h"
#include "NamesTree.h"
#include "PopupListView.h"
#include "desssergen/alert.h"
#include "desssergen/sync_value.h"
#include "misc.h"

static constexpr bool verbose{false};

NameTreeView::NameTreeView(QWidget *parent) : QTreeView(parent) {
  setUniformRowHeights(true);
  setHeaderHidden(true);
  setSelectionMode(QAbstractItemView::SingleSelection);
}

void NameTreeView::currentChanged(QModelIndex const &current,
                                  QModelIndex const &previous) {
  QAbstractItemView::currentChanged(current, previous);
  emit selectedChanged(current);
}

AlertEditor::AlertEditor(QWidget *parent) : AtomicWidget(parent) {
  source = new NameTreeView;
  // TODO: restrict to numerical fields
  // QTreeView to select the parent function field (aka "table" + "column")
  source->setModel(NamesTree::globalNamesTreeAnySites);
  connect(source, &NameTreeView::selectedChanged, this,
          &AlertEditor::checkSource);
  connect(source, &NameTreeView::selectedChanged, this,
          &AlertEditor::inputChanged);
  /* connect(source->model(), &NamesTree::rowsInserted,
      source, &NameTreeView::expand);*/

  /* The text is reset with the proper table/column name when an
   * error is detected: */
  inexistantSourceError = new QLabel;
  inexistantSourceError->hide();
  inexistantSourceError->setStyleSheet("color: red;");

  mustSelectAField = new QLabel(tr("Please select a field name"));

  isEnabled = new QCheckBox(tr("enabled"));
  isEnabled->setChecked(true);
  connect(isEnabled, &QCheckBox::stateChanged, this,
          &AlertEditor::inputChanged);

  // TODO: list of FilterEditors rather
  where = new FilterEditor;
  connect(where, &FilterEditor::inputChanged, this, &AlertEditor::inputChanged);

  autoGroupBy = new QCheckBox(tr("automatic"));
  autoGroupBy->setChecked(true);
  connect(autoGroupBy, &QCheckBox::stateChanged, this,
          &AlertEditor::inputChanged);
  connect(autoGroupBy, &QCheckBox::stateChanged, this,
          &AlertEditor::toggleAutoGroupBy);
  tableFields = new QStringListModel;
  // Must set the parent explicitly as it is not in the layout:
  groupBy = new PopupListView(this);
  groupBy->setModel(tableFields);
  groupBy->setSelectionMode(QAbstractItemView::MultiSelection);
  openGroupBy = new QPushButton;
  connect(groupBy->selectionModel(), &QItemSelectionModel::selectionChanged,
          this, &AlertEditor::inputChanged);
  connect(source, &NameTreeView::selectedChanged, this,
          &AlertEditor::checkGroupBy);

  having = new FilterEditor;
  connect(having, &FilterEditor::inputChanged, this,
          &AlertEditor::inputChanged);

  threshold = new QLineEdit;
  threshold->setValidator(new QDoubleValidator);
  connect(threshold, &QLineEdit::textChanged, this, &AlertEditor::inputChanged);
  recovery = new QLineEdit;
  recovery->setValidator(new QDoubleValidator);
  connect(recovery, &QLineEdit::textChanged, this, &AlertEditor::inputChanged);
  duration = new QLineEdit;
  duration->setValidator(
      // TODO: DurationValidator
      new QDoubleValidator(0., std::numeric_limits<double>::max(), 5));
  duration->setPlaceholderText(tr("duration"));
  connect(duration, &QLineEdit::textChanged, this, &AlertEditor::inputChanged);
  percentage = new QLineEdit("100");
  percentage->setValidator(new QDoubleValidator(0., 100., 5));
  percentage->setPlaceholderText(tr("% of past measures"));
  connect(percentage, &QLineEdit::textChanged, this,
          &AlertEditor::inputChanged);
  timeStep = new QLineEdit;
  timeStep->setValidator(new QDoubleValidator(0., 999999., 6));
  timeStep->setPlaceholderText(tr("seconds"));
  id = new QLineEdit;

  descTitle = new QLineEdit;
  /* At least one char that's not a space. Beware that validators
   * automatically anchor the pattern: */
  QRegularExpression nonEmpty(".*\\S+.*");
  descTitle->setValidator(new QRegularExpressionValidator(nonEmpty));
  connect(descTitle, &QLineEdit::textChanged, this, &AlertEditor::inputChanged);
  descFiring = new QLineEdit;
  descFiring->setPlaceholderText(tr("alert!"));
  connect(descFiring, &QLineEdit::textChanged, this,
          &AlertEditor::inputChanged);
  descRecovery = new QLineEdit;
  descRecovery->setPlaceholderText(tr("recovered"));
  connect(descRecovery, &QLineEdit::textChanged, this,
          &AlertEditor::inputChanged);

  // TODO: List of tops/carry rather
  top = new QLineEdit;
  top->setValidator(new QRegularExpressionValidator(nonEmpty));
  top->setPlaceholderText(tr("feature major contributors"));
  carryFields = new QLineEdit;
  carryFields->setValidator(new QRegularExpressionValidator(nonEmpty));
  carryFields->setPlaceholderText(tr("field to carry along"));
  // TODO: CarryCsts

  description = new QLabel;

  /* Layout: Starts with a dynamic sentence describing the notification, and
   * then the form: */

  QVBoxLayout *outerLayout{new QVBoxLayout};
  {
    // The names and descriptions
    QGroupBox *namesBox{new QGroupBox(tr("Names"))};
    /* Use two QFormLayouts side by side to benefit from better
     * styling of those forms that one would get from a QGridLayout: */
    QHBoxLayout *namesLayout{new QHBoxLayout};
    QFormLayout *namesLayout1{new QFormLayout};  // 1st column
    QFormLayout *namesLayout2{new QFormLayout};  // 2nd column
    {
      namesLayout1->addRow(tr("Alert unique name:"), descTitle);
      namesLayout1->addRow(tr("Optional Identifier:"), id);
      namesLayout2->addRow(tr("Text when firing:"), descFiring);
      namesLayout2->addRow(tr("Text when recovering:"), descRecovery);
      namesLayout->addLayout(namesLayout1);
      namesLayout->addLayout(namesLayout2);
    }
    namesBox->setLayout(namesLayout);
    outerLayout->addWidget(namesBox);

    // The notification condition
    QGroupBox *condition{new QGroupBox(tr("Main Condition"))};
    QHBoxLayout *conditionLayout{new QHBoxLayout};
    {
      QFormLayout *metricForm{new QFormLayout};
      {
        QSizePolicy policy = source->sizePolicy();
        policy.setVerticalStretch(1);
        policy.setHorizontalStretch(2);
        source->setSizePolicy(policy);
        metricForm->addRow(tr("Metric:"), source);
        metricForm->addWidget(inexistantSourceError);
        metricForm->addWidget(mustSelectAField);
        metricForm->addRow(tr("Time Step:"), timeStep);
        metricForm->addRow(tr("Where:"), where);
      }
      conditionLayout->addLayout(metricForm);

      QFormLayout *limitLayout{new QFormLayout};
      {
        thresholdIsMax = new QRadioButton(tr("max"));
        thresholdIsMin = new QRadioButton(tr("min"));
        thresholdIsMax->setChecked(true);
        QHBoxLayout *minMaxLayout{new QHBoxLayout};
        minMaxLayout->addWidget(thresholdIsMax);
        minMaxLayout->addWidget(thresholdIsMin);
        minMaxLayout->addWidget(threshold);
        QWidget *minMaxBox{new QWidget};
        minMaxBox->setLayout(minMaxLayout);
        limitLayout->addRow(tr("Alerting threshold:"), minMaxBox);
        limitLayout->addRow(tr("Recovery threshold:"), recovery);
        limitLayout->addRow(tr("Measurements (%):"), percentage);
        limitLayout->addRow(tr("During the last (secs):"), duration);
        QHBoxLayout *groupByGroup{new QHBoxLayout};
        groupByGroup->addWidget(autoGroupBy);
        groupByGroup->addWidget(openGroupBy);
        limitLayout->addRow(tr("Group By:"), groupByGroup);
        /* Display the list below that button as a popup; */
        connect(openGroupBy, &QPushButton::clicked, this,
                &AlertEditor::toggleGroupByView);
        limitLayout->addRow(tr("Having:"), having);
      }
      conditionLayout->addLayout(limitLayout);
    }
    condition->setLayout(conditionLayout);
    outerLayout->addWidget(condition);

    // Additional information to add to alerts:
    QGroupBox *addFieldsBox{new QGroupBox(tr("Attach additional fields"))};
    QHBoxLayout *addFieldsBoxLayout{new QHBoxLayout};
    {
      addFieldsBoxLayout->addWidget(new QLabel(tr("Value of:")));
      addFieldsBoxLayout->addWidget(carryFields);
      addFieldsBoxLayout->addStretch();
      addFieldsBoxLayout->addWidget(new QLabel(tr("Breakdown of:")));
      addFieldsBoxLayout->addWidget(top);
    }
    addFieldsBox->setLayout(addFieldsBoxLayout);
    outerLayout->addWidget(addFieldsBox);

    // The description
    QGroupBox *descriptionBox{new QGroupBox(tr("Description"))};
    QVBoxLayout *descriptionBoxLayout{new QVBoxLayout};
    {
      descriptionBoxLayout->addWidget(description);
      description->setAlignment(Qt::AlignCenter);
    }
    descriptionBox->setLayout(descriptionBoxLayout);
    outerLayout->addWidget(descriptionBox);

    // Final
    outerLayout->addWidget(isEnabled);
  }

  QWidget *widget{new QWidget};
  widget->setLayout(outerLayout);
  relayoutWidget(widget);

  updateGroupByLabel();

  /* The values will be read from the various widgets when the OCaml value
   * is extracted from the form, yet we want to update the textual description
   * of the alert at every change: */
  connect(source, &NameTreeView::selectedChanged, this,
          &AlertEditor::updateDescription);
  /* When a new table is selected the possible LHS of where and having has
   * to adapt: */
  connect(source, &NameTreeView::selectedChanged, this,
          &AlertEditor::updateFilters);
  /* Update the openGroupBy button label whenever the selection changes: */
  connect(groupBy->selectionModel(), &QItemSelectionModel::selectionChanged,
          this, &AlertEditor::updateGroupByLabel);
  connect(thresholdIsMax, &QRadioButton::toggled, this,
          &AlertEditor::updateDescription);
  connect(threshold, &QLineEdit::textChanged, this,
          &AlertEditor::updateDescription);
  connect(recovery, &QLineEdit::textChanged, this,
          &AlertEditor::updateDescription);
  /* Whenever the recovery is set then the value of min/max radios becomes
   * read-only */
  connect(recovery, &QLineEdit::textChanged, this, &AlertEditor::updateMinMax);
  connect(duration, &QLineEdit::textChanged, this,
          &AlertEditor::updateDescription);
  connect(percentage, &QLineEdit::textChanged, this,
          &AlertEditor::updateDescription);
  connect(id, &QLineEdit::textChanged, this, &AlertEditor::updateDescription);
  connect(descTitle, &QLineEdit::textChanged, this,
          &AlertEditor::updateDescription);
  connect(descFiring, &QLineEdit::textChanged, this,
          &AlertEditor::updateDescription);
  connect(descRecovery, &QLineEdit::textChanged, this,
          &AlertEditor::updateDescription);
  connect(where, &FilterEditor::inputChanged, this,
          &AlertEditor::updateDescription);
  connect(having, &FilterEditor::inputChanged, this,
          &AlertEditor::updateDescription);
  connect(timeStep, &QLineEdit::textChanged, this,
          &AlertEditor::updateDescription);
  connect(top, &QLineEdit::textChanged, this, &AlertEditor::updateDescription);
  connect(carryFields, &QLineEdit::textChanged, this,
          &AlertEditor::updateDescription);
}

void AlertEditor::updateGroupByLabel() {
  QStringList const lst{getGroupByQStrings()};

  openGroupBy->setText(lst.isEmpty() ? tr("select fields")
                                     : abbrev(50, lst.join(", ")));
}

void AlertEditor::toggleGroupByView() {
  if (groupBy->isVisible()) {
    groupBy->hide();
  } else {
    QPoint const pos{
        openGroupBy->mapToGlobal(QPoint(0, openGroupBy->height()))};
    groupBy->move(pos.x(), pos.y());
    groupBy->show();
  }
}

void AlertEditor::toggleAutoGroupBy(int state) {
  bool const manualGroupBy{state == Qt::Unchecked};
  openGroupBy->setEnabled(manualGroupBy);
  groupBy->setEnabled(manualGroupBy);
  if (!manualGroupBy) groupBy->hide();
}

bool AlertEditor::hasRecovery() const { return !recovery->text().isEmpty(); }

void AlertEditor::updateMinMax() {
  if (!recovery->isEnabled()) return;  // wtv

  bool enabled{true};
  if (!recovery->text().isEmpty() && !threshold->text().isEmpty()) {
    double const threshold_val{threshold->text().toDouble()};
    double const recovery_val{recovery->text().toDouble()};
    if (threshold_val != recovery_val) {
      enabled = false;
      if (threshold_val > recovery_val) {
        thresholdIsMax->setChecked(true);
      } else {
        thresholdIsMin->setChecked(true);
      }
    }
  }
  thresholdIsMax->setEnabled(enabled);
  thresholdIsMin->setEnabled(enabled);
}

void AlertEditor::setEnabled(bool enabled) {
  source->setEnabled(enabled);
  isEnabled->setEnabled(enabled);
  threshold->setEnabled(enabled);
  recovery->setEnabled(enabled);
  duration->setEnabled(enabled);
  percentage->setEnabled(enabled);
  id->setEnabled(enabled);
  descTitle->setEnabled(enabled);
  descFiring->setEnabled(enabled);
  descRecovery->setEnabled(enabled);
  timeStep->setEnabled(enabled);
  where->setEnabled(enabled);
  autoGroupBy->setEnabled(enabled);
  bool const manualGroupBy{!autoGroupBy->isChecked()};
  openGroupBy->setEnabled(enabled && manualGroupBy);
  groupBy->setEnabled(enabled && manualGroupBy);
  having->setEnabled(enabled);
  top->setEnabled(enabled);
  carryFields->setEnabled(enabled);

  if (enabled) {
    checkSource(source->currentIndex());
    updateMinMax();
  } else {
    mustSelectAField->hide();
    thresholdIsMax->setEnabled(false);
    thresholdIsMin->setEnabled(false);
  }
}

bool AlertEditor::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  if (v->index() != dessser::gen::sync_value::Alert) {
    qCritical() << "Not a dessser::gen::alert::t?!";
    return false;
  }

  dessser::gen::alert::t const &alert{
      std::get<dessser::gen::sync_value::Alert>(*v)};

  /* Source:
   * Look for the name "$table/$column" and select it, but
   * also save the table and column names in case they are not
   * known (for instance if the program is not running (yet)). */
  table = alert.table;
  column = alert.column;
  NamesTree *model{static_cast<NamesTree *>(source->model())};
  std::string const path{alert.table + "/" + alert.column};
  QModelIndex index{model->find(path)};
  if (index.isValid()) {
    source->setCurrentIndex(index);
    /* FIXME: scrollTo is supposed to expand collapsed parents but does
     * not properly (maybe because of a bug in NamesTree::parent(), so for
     * now let's just expand everything: */
    source->expandAll();
    source->scrollTo(index);
    checkSource(index);
    checkGroupBy(index);
  } else {
    if (verbose)
      qDebug() << "Cannot find field" << QString::fromStdString(path);
    inexistantSourceError->setText(
        tr("Field %1/%2 does not exist")
            .arg(QString::fromStdString(alert.table),
                 QString::fromStdString(alert.column)));
    inexistantSourceError->show();
  }

  isEnabled->setChecked(alert.enabled);

  if (alert.where.empty()) {
    where->clear();
  } else {
    // TODO: support multiple where/having
    where->setValue(alert.where[0]);
  }

  _groupBy = alert.group_by;  // FIXME: unused?!
  QItemSelectionModel *selModel{groupBy->selectionModel()};
  selModel->clearSelection();
  if (alert.group_by) {
    autoGroupBy->setChecked(false);
    toggleAutoGroupBy(Qt::Unchecked);
    QStringList const fields{tableFields->stringList()};
    for (std::string const &s_ : *alert.group_by) {
      QString const s{QString::fromStdString(s_)};
      qsizetype const row{fields.indexOf(s)};
      if (row >= 0) {
        selModel->select(tableFields->index(row), QItemSelectionModel::Select);
      } else {
        qCritical() << "AlertEditor::setValue: Cannot find field " << s;
      }
    }
  } else {
    autoGroupBy->setChecked(true);
    toggleAutoGroupBy(Qt::Checked);
  }
  updateGroupByLabel();

  if (alert.having.empty()) {
    having->clear();
  } else {
    having->setValue(alert.having[0]);
  }

  // FIXME: threshold can optionally be a baseline now:
  if (alert.threshold.index() == dessser::gen::alert::Constant) {
    double const t{std::get<dessser::gen::alert::Constant>(alert.threshold)};
    threshold->setText(QString::number(t));
    recovery->setText(QString::number(t + alert.hysteresis));
  } else {
    threshold->setText("TODO");  // QString::number(alert.threshold));
    recovery->setText("TODO");
  }

  duration->setText(QString::number(alert.duration));

  percentage->setText(QString::number(100. * alert.ratio));

  timeStep->setText(alert.time_step > 0 ? QString::number(alert.time_step)
                                        : QString());

  id->setText(QString::fromStdString(alert.id));

  descTitle->setText(QString::fromStdString(alert.desc_title));

  descFiring->setText(QString::fromStdString(alert.desc_firing));

  descRecovery->setText(QString::fromStdString(alert.desc_recovery));

  if (alert.tops.empty()) {
    top->clear();
  } else {
    top->setText(QString::fromStdString(alert.tops[0]));
  }
  if (alert.carry_fields.empty()) {
    carryFields->clear();
  } else {
    carryFields->setText(QString::fromStdString(alert.carry_fields[0]));
  }

  return true;
}

std::string const AlertEditor::getTable() const {
  NamesTree const *model{static_cast<NamesTree const *>(source->model())};
  std::pair<std::string, std::string> const path{
      model->pathOfIndex(source->currentIndex())};
  return path.first.empty() ? table : path.first;
}

std::string const AlertEditor::getColumn() const {
  NamesTree const *model{static_cast<NamesTree const *>(source->model())};
  std::pair<std::string, std::string> const path{
      model->pathOfIndex(source->currentIndex())};
  return path.second.empty() ? column : path.second;
}

QStringList const AlertEditor::getGroupByQStrings() const {
  QItemSelectionModel const *selModel{groupBy->selectionModel()};
  QModelIndexList selIdxs{selModel->selectedRows()};
  QStringList lst;

  for (int i = 0; i < selIdxs.length(); i++) {
    lst += tableFields->data(selIdxs[i]).toString();
  }

  return lst;
}

std::optional<dessser::Arr<std::string> > const AlertEditor::getGroupBy()
    const {
  if (autoGroupBy->isChecked()) return std::nullopt;

  QStringList const lst{getGroupByQStrings()};
  dessser::Arr<std::string> ret;

  for (int i = 0; i < lst.length(); i++) ret.push_back(lst[i].toStdString());

  return ret;
}

std::shared_ptr<dessser::gen::sync_value::t const> AlertEditor::getValue()
    const {
  std::string const column{getColumn()};

  dessser::Arr<std::string> carry_fields;
  if (!carryFields->text().isEmpty())
    carry_fields = dessser::Arr<std::string>{carryFields->text().toStdString()};

  dessser::Arr<std::string> tops;
  if (!carryFields->text().isEmpty())
    tops = dessser::Arr<std::string>{top->text().toStdString()};

  dessser::Arr<dessser::gen::simple_filter::t> where_;
  if (!where->isEmpty() && where->hasValidInput())
    where_ = dessser::Arr<dessser::gen::simple_filter::t>{*where->getValue()};

  dessser::Arr<dessser::gen::simple_filter::t> having_;
  if (!having->isEmpty() && having->hasValidInput())
    having_ = dessser::Arr<dessser::gen::simple_filter::t>{*having->getValue()};

  dessser::Arr<dessser::gen::alert::constant> carry_csts_{};

  double const threshold_val{threshold->text().toDouble()};
  double const recovery_val{recovery->text().toDouble() - threshold_val};

  return std::make_shared<dessser::gen::sync_value::t const>(
      std::in_place_index<dessser::gen::sync_value::Alert>,
      dessser::gen::alert::t{
          getTable(), column, isEnabled->isChecked(), where_, getGroupBy(),
          having_,
          dessser::gen::alert::threshold{
              std::in_place_index<dessser::gen::alert::Constant>,
              threshold_val},
          recovery_val, duration->text().toDouble(),
          0.01 * percentage->text().toDouble(), timeStep->text().toDouble(),
          tops, carry_fields, carry_csts_, id->text().toStdString(),
          descTitle->text().toStdString(), descFiring->text().toStdString(),
          descRecovery->text().toStdString()});
}

/* This is called each time we change or set the source to some value: */
void AlertEditor::checkSource(QModelIndex const &current) const {
  inexistantSourceError->hide();
  NamesTree *model{static_cast<NamesTree *>(source->model())};
  mustSelectAField->setVisible(!model->isField(current));
}

void AlertEditor::checkGroupBy(QModelIndex const &current) {
  NamesTree *model{static_cast<NamesTree *>(source->model())};
  if (!model->isField(current)) return;

  /* Get the list of fields in this table, expunge from groupBy all unknown
   * fields, and if anything changed reset the model content and openGroupBy's
   * label: */
  QModelIndex const tableIdx{current.parent()};
  bool changedSel{false};
  QStringList const fieldList{tableFields->stringList()};
  if (verbose)
    qDebug() << "checkGroupBy: syncing" << model->rowCount(tableIdx)
             << "rows from the model with" << fieldList.length()
             << "rows from the groupBy list";
  int fieldListIdx{0};  // Iterates over the groupBy QStringListModel...
  int row{0};           // ...whereas row iterates over the NamesTree model
  while (row < model->rowCount(tableIdx) || fieldListIdx < fieldList.length()) {
    QString field;
    int cmp;
    if (row >= model->rowCount(tableIdx))
      // That trailing fieldList entry must be removed
      goto remove_extra;
    field = model->data(model->index(row, 0, tableIdx)).toString();
    if (fieldListIdx >= fieldList.length())
      // Must add that missing row into fieldList
      goto add_missing;
    // If we have both entries, compare them:
    cmp = fieldList[fieldListIdx].compare(field);
    if (cmp < 0) {  // fieldList[fieldListIdx] must be removed from tableFields
    remove_extra:
      changedSel = changedSel ||
                   groupBy->selectionModel()->isRowSelected(row, QModelIndex());
      tableFields->removeRows(row, 1);
      // Keep trying with next fieldListIdx
      fieldListIdx++;
    } else if (cmp > 0) {  // field must be inserted here
    add_missing:
      tableFields->insertRows(row, 1);
      tableFields->setData(tableFields->index(row, 0), field);
      // Keep looking for this fieldListIdx
      row++;
    } else {  // cmp == 0, move to next row
      fieldListIdx++;
      row++;
    }
  }

  // If we changed the *selection* then update openGroupBy's label: */
  if (changedSel) updateGroupByLabel();
}

void AlertEditor::updateDescription() {
  std::string const table{getTable()};
  std::string const column{getColumn()};
  bool const has_table{table.length() > 0};
  bool const has_column{has_table && column.length() > 0};
  bool const has_threshold{threshold->hasAcceptableInput()};
  bool const has_recovery{recovery->hasAcceptableInput()};
  bool const has_duration{duration->hasAcceptableInput()};
  bool const has_timeStep{timeStep->hasAcceptableInput()};
  bool const has_percentage{percentage->hasAcceptableInput()};
  QString const where_desc{
      where->description("\n(considering only values which ", "), ")};
  QString const having_desc{
      having->description("\nwhenever the aggregated ", ", ")};
  QString const recovery_str{recovery->text()};
  double const percentage_val{percentage->text().toDouble()};
  double const duration_val{duration->text().toDouble()};
  QString const timeStep_text{
      has_timeStep ? tr(" (aggregated by %1)")
                         .arg(stringOfDuration(timeStep->text().toDouble()))
                   : ""};
  QString const topFields{
      top->hasAcceptableInput()
          ? tr("the breakdown of the top contributing %1").arg(top->text())
          : ""};
  QString const carryFieldsStr{
      carryFields->hasAcceptableInput()
          ? tr("the value of %1").arg(carryFields->text())
          : ""};
  /* TODO: CarryCsts */
  QString const attachedFields{
      !topFields.isEmpty() && !carryFieldsStr.isEmpty()
          ? tr("%1 and %2").arg(carryFieldsStr, topFields)
      : !topFields.isEmpty() ? topFields
                             : carryFieldsStr};
  QString const attachedFields_text{
      !attachedFields.isEmpty()
          ? tr("In addition to the tracked metric, the notification will also "
               "feature %1")
                .arg(attachedFields)
          : ""};
  if (percentage_val >= 100. && duration_val == 0) {
    description->setText(
        tr("Fire notification \"%1%2\" when %3%4%5 is %6 %7%8%9\n"
           "and recover when back %10 %11.\n%12")
            .arg(descTitle->text(),
                 descTitle->hasAcceptableInput() ? QString() : QString("…"),
                 has_table ? QString::fromStdString(table) : QString("…"),
                 has_column ? QString("/") + QString::fromStdString(column)
                            : (has_table ? QString("…") : QString()),
                 timeStep_text,
                 thresholdIsMax->isChecked() ? tr("above") : tr("below"),
                 has_threshold ? threshold->text() : QString("…"), where_desc,
                 having_desc,
                 thresholdIsMax->isChecked() ? tr("below") : tr("above"),
                 has_threshold && has_recovery ? recovery_str : QString("…"),
                 attachedFields_text));
  } else if (percentage_val >= 100.) {
    description->setText(
        tr("Fire notification \"%1%2\" when %3%4%5 is consistently %6 %7\n"
           "for the last %8%9%10\n"
           "and recover when back %11 %12.\n%13")
            .arg(descTitle->text(),
                 descTitle->hasAcceptableInput() ? QString() : QString("…"),
                 has_table ? QString::fromStdString(table) : QString("…"),
                 has_column ? QString("/") + QString::fromStdString(column)
                            : (has_table ? QString("…") : QString()),
                 timeStep_text,
                 thresholdIsMax->isChecked() ? tr("above") : tr("below"),
                 has_threshold ? threshold->text() : QString("…"),
                 has_duration ? stringOfDuration(duration_val) : QString("…"),
                 where_desc, having_desc,
                 thresholdIsMax->isChecked() ? tr("below") : tr("above"),
                 has_threshold && has_recovery ? recovery_str : QString("…"),
                 attachedFields_text));
  } else {
    description->setText(
        tr("Fire notification \"%1%2\" when %3%4%5 is %6 %7%8\nfor at "
           "least "
           "%9% "
           "of the time during the last %10%11\nand recover when back %12 "
           "%13.\n"
           "%14")
            .arg(
                descTitle->text(),
                descTitle->hasAcceptableInput() ? QString() : QString("…"),
                has_table ? QString::fromStdString(table) : QString("…"),
                has_column ? QString("/") + QString::fromStdString(column)
                           : (has_table ? QString("…") : QString()),
                timeStep_text,
                thresholdIsMax->isChecked() ? tr("above") : tr("below"),
                has_threshold ? threshold->text() : QString("…"), where_desc,
                has_percentage ? QString::number(percentage_val) : QString("…"),
                has_duration ? stringOfDuration(duration_val) : QString("…"),
                having_desc,
                thresholdIsMax->isChecked() ? tr("below") : tr("above"),
                has_threshold && has_recovery ? recovery_str : QString("…"),
                attachedFields_text));
  }
}

/* Check that this index is a field and if so reset the where and filter
 * function with this field parent: */
void AlertEditor::updateFilters(QModelIndex const &current) {
  if (!current.isValid()) return;

  NamesTree const *model{static_cast<NamesTree const *>(source->model())};
  if (!model->isField(current)) {
    if (verbose) qDebug() << "AlertEditor: selected source is not in a field";
    return;
  }

  QModelIndex const parent{current.parent()};
  if (verbose)
    qDebug() << "AlertEditor: selecting parent" << model->data(parent, 0);
  if (!parent.isValid()) {
    qCritical() << "AlertEditor: field has no parent?!";
    return;
  }

  where->setFunction(parent);
  having->setFunction(parent);

  if (topCompleter) topCompleter->deleteLater();
  topCompleter =
      new NamesCompleter(NamesTree::globalNamesTreeAnySites, this, parent);
  topCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
  top->setCompleter(topCompleter);

  if (carryFieldsCompleter) carryFieldsCompleter->deleteLater();
  carryFieldsCompleter =
      new NamesCompleter(NamesTree::globalNamesTreeAnySites, this, parent);
  carryFieldsCompleter->setCompletionMode(
      QCompleter::UnfilteredPopupCompletion);
  carryFields->setCompleter(carryFieldsCompleter);
}

bool AlertEditor::hasValidInput() const {
  NamesTree const *model{static_cast<NamesTree *>(source->model())};
  if (!model->isField(source->currentIndex())) {
    if (verbose) qDebug() << "AlertEditor: selected source is not a field";
    return false;
  }
  if (!threshold->hasAcceptableInput()) {
    if (verbose) qDebug() << "AlertEditor: threshold invalid";
    return false;
  }
  if (!recovery->hasAcceptableInput()) {
    if (verbose) qDebug() << "AlertEditor: recovery invalid";
    return false;
  }
  if (!duration->text().isEmpty() && !duration->hasAcceptableInput()) {
    if (verbose) qDebug() << "AlertEditor: duration invalid";
    return false;
  }
  if (!timeStep->text().isEmpty() && !timeStep->hasAcceptableInput()) {
    if (verbose) qDebug() << "AlertEditor: time-step invalid";
    return false;
  }
  if (!percentage->hasAcceptableInput()) {
    if (verbose) qDebug() << "AlertEditor: percentage invalid";
    return false;
  }
  if (!descTitle->hasAcceptableInput()) {
    if (verbose) qDebug() << "AlertEditor: name invalid";
    return false;
  }
  if (!where->isEmpty() && !where->hasValidInput()) {
    if (verbose) qDebug() << "AlertEditor: where invalid";
    return false;
  }
  if (!having->isEmpty() && !having->hasValidInput()) {
    if (verbose) qDebug() << "AlertEditor: having invalid";
    return false;
  }

  if (verbose) qDebug() << "AlertEditor: is valid";

  return true;
}
