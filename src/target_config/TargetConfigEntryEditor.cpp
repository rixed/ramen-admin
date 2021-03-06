// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "target_config/TargetConfigEntryEditor.h"

#include <QCheckBox>
#include <QComboBox>
#include <QDebug>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QtGlobal>
#include <memory>
#include <string>

#include "AtomicWidget.h"
#include "ConfClient.h"
#include "EditorWidget.h"
#include "KVStore.h"
#include "Menu.h"
#include "PathSuffixValidator.h"
#include "RangeDoubleValidator.h"
#include "desssergen/program_run_parameter.h"
#include "desssergen/raql_value.h"
#include "desssergen/rc_entry.h"
#include "desssergen/source_info.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "misc_dessser.h"
#include "source/SourcesModel.h"  // for baseNameOfKey and friends

static constexpr bool verbose{false};

QMap<std::string, std::shared_ptr<dessser::gen::raql_value::t const> >
    TargetConfigEntryEditor::setParamValues;

static bool isCompiledSource(KValue const &kv) {
  if (kv.val->index() != dessser::gen::sync_value::SourceInfo) return false;

  dessser::gen::source_info::t const &info{
      std::get<dessser::gen::sync_value::SourceInfo>(*kv.val)};

  return info.detail.index() == dessser::gen::source_info::Compiled;
}

static std::string const sourceExt(dessser::gen::sync_key::t const &key) {
  if (key.index() != dessser::gen::sync_key::Sources) return "";
  auto const &sources{std::get<dessser::gen::sync_key::Sources>(key)};
  return std::get<1>(sources);
}

static bool isSourceFile(dessser::gen::sync_key::t const &key) {
  return sourceExt(key) != "info";
}

static bool isInfoFile(dessser::gen::sync_key::t const &key) {
  return sourceExt(key) == "info";
}

TargetConfigEntryEditor::TargetConfigEntryEditor(bool sourceEditable_,
                                                 QWidget *parent)
    : QWidget(parent),
      sourceDoesExist(false),
      sourceIsCompiled(false),
      enabled(false),
      sourceEditable(sourceEditable_) {
  QFormLayout *layout{new QFormLayout};

  {  // source

    QVBoxLayout *sourceLayout{new QVBoxLayout};
    sourceBox = new QComboBox;
    sourceBox->setEnabled(sourceEditable);
    sourceBox->setInsertPolicy(QComboBox::InsertAlphabetically);

    sourceLayout->addWidget(sourceBox);

    connect(sourceBox, &QComboBox::currentTextChanged, this,
            &TargetConfigEntryEditor::sourceChanged);

    notCompiledSourceWarning =
        new QLabel(tr("This source is not compiled (yet?)"));
    notCompiledSourceWarning->setVisible(false);
    notCompiledSourceWarning->setStyleSheet("color: red;");
    sourceLayout->addWidget(notCompiledSourceWarning);
    deletedSourceWarning =
        new QLabel(tr("This source does not exist any longer!"));
    sourceLayout->addWidget(deletedSourceWarning);
    deletedSourceWarning->setVisible(false);
    deletedSourceWarning->setStyleSheet("color: red;");

    layout->addRow(tr("Source:"), sourceLayout);
  }

  {  // suffix
    suffixEdit = new QLineEdit;
    suffixEdit->setPlaceholderText(tr("Program Suffix"));
    suffixEdit->setValidator(new PathSuffixValidator(this));
    layout->addRow(tr("Program &Suffix:"), suffixEdit);
    connect(suffixEdit, &QLineEdit::textChanged, this,
            &TargetConfigEntryEditor::inputChanged);
  }

  {  // flags
    QVBoxLayout *flagsLayout{new QVBoxLayout};
    enabledBox = new QCheckBox(tr("enabled"));
    enabledBox->setChecked(true);
    connect(enabledBox, &QCheckBox::stateChanged, this,
            &TargetConfigEntryEditor::inputChanged);
    flagsLayout->addWidget(enabledBox);
    debugBox = new QCheckBox(tr("debug mode"));
    flagsLayout->addWidget(debugBox);
    connect(debugBox, &QCheckBox::stateChanged, this,
            &TargetConfigEntryEditor::inputChanged);
    automaticBox = new QCheckBox(tr("automatic"));
    automaticBox->setEnabled(false);
    flagsLayout->addWidget(automaticBox);
    layout->addRow(tr("Flags:"), flagsLayout);
  }

  sitesEdit = new QLineEdit;
  sitesEdit->setText("*");
  static QRegularExpression nonEmpty{"\\s*[^\\s]+\\s*"};
  sitesEdit->setValidator(new QRegularExpressionValidator(nonEmpty, this));
  connect(sitesEdit, &QLineEdit::textChanged, this,
          &TargetConfigEntryEditor::inputChanged);
  layout->addRow(tr("&Only on Sites:"), sitesEdit);

  reportEdit = new QLineEdit;
  reportEdit->setText("30");
  reportEdit->setValidator(RangeDoubleValidator::forRange(1, 99999));
  connect(reportEdit, &QLineEdit::textChanged, this,
          &TargetConfigEntryEditor::inputChanged);
  layout->addRow(tr("&Reporting Period:"), reportEdit);

  cwdEdit = new QLineEdit;
  connect(cwdEdit, &QLineEdit::textChanged, this,
          &TargetConfigEntryEditor::inputChanged);
  layout->addRow(tr("Working &Directory:"), cwdEdit);

  paramsOrInfo = new QStackedLayout;
  paramsForm = new QFormLayout;
  QWidget *paramsFormWidget{new QWidget};
  paramsFormWidget->setLayout(paramsForm);
  paramsFormIdx = paramsOrInfo->addWidget(paramsFormWidget);
  QLabel *noParamsInfo{new QLabel(tr("This program has no parameters"))};
  noParamsInfoIdx = paramsOrInfo->addWidget(noParamsInfo);
  layout->addRow(new QLabel(tr("Parameters:")), paramsOrInfo);
  paramsOrInfo->setCurrentIndex(noParamsInfoIdx);

  /* Make sure the above form is compressed vertically when parameters are
   * added/removed: */
  QVBoxLayout *vbox_layout{new QVBoxLayout};
  vbox_layout->addLayout(layout);
  vbox_layout->addStretch(1);
  setLayout(vbox_layout);

  setEnabled(enabled);

  /* Each creation/deletion of source files while this editor is alive should
   * refresh the source select box and its associated warnings: */
  connect(kvs.get(), &KVStore::keyChanged, this,
          &TargetConfigEntryEditor::onChange);
}

void TargetConfigEntryEditor::sourceChanged(QString const &text) {
  if (verbose) qDebug() << "TargetConfigEntryEditor::sourceChanged to" << text;
  setParamValues.clear();
  updateSourceWarnings();
  saveParams();
  resetParams();
  emit inputChanged();
}

void TargetConfigEntryEditor::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyCreated:
        addSourceFromStore(*change.key, change.kv);
        break;
      case KeyChanged:
        updateSourceFromStore(*change.key, change.kv);
        break;
      case KeyDeleted:
        removeSourceFromStore(*change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

void TargetConfigEntryEditor::addSourceFromStore(
    dessser::gen::sync_key::t const &key, KValue const &) {
  if (key.index() != dessser::gen::sync_key::Sources) return;

  if (verbose)
    qDebug() << "TargetConfigEntryEditor::addSourceFromStore: New key:" << key;

  if (isSourceFile(key)) {
    if (verbose)
      qDebug()
          << "TargetConfigEntryEditor::addSourceFromStore: ... is a source key";
    addSource(key);  // Won't change the selection but might change warnings
    updateSourceWarnings();
  } else if (isInfoFile(key)) {
    if (verbose)
      qDebug()
          << "TargetConfigEntryEditor::addSourceFromStore: ... is an info key";
    updateSourceWarnings();
  }
}

void TargetConfigEntryEditor::updateSourceFromStore(
    dessser::gen::sync_key::t const &key, KValue const &) {
  if (key.index() != dessser::gen::sync_key::Sources) return;

  if (verbose)
    qDebug() << "TargetConfigEntryEditor::updateSourceFromStore: Upd key:"
             << key;

  if (isInfoFile(key)) {
    if (verbose)
      qDebug() << "TargetConfigEntryEditor::updateSourceFromStore: ... is an "
                  "info key";
    updateSourceWarnings();
  }
}

void TargetConfigEntryEditor::removeSourceFromStore(
    dessser::gen::sync_key::t const &key, KValue const &) {
  if (key.index() != dessser::gen::sync_key::Sources) return;

  /* Do not remove anything, so keep the current selection.
   * Just update the warning: */
  updateSourceWarnings();
}

void TargetConfigEntryEditor::setProgramName(std::string const &programName) {
  /* Even if this sourceName does not exist we want to have it preselected
   * (with a warning displayed).
   * If several non-existing sourceNames are set, they will accumulate in
   * the box. Not a big deal as long as the warnings are properly displayed. */
  std::string const srcPath{srcPathFromProgramName(programName)};
  std::string const programSuffix{suffixFromProgramName(programName)};
  suffixEdit->setText(QString::fromStdString(programSuffix));

  int const idx{findOrAddSourceName(QString::fromStdString(srcPath))};
  if (idx >= 0) sourceBox->setCurrentIndex(idx);
}

void TargetConfigEntryEditor::setEnabled(bool enabled_) {
  if (verbose)
    qDebug() << "TargetConfigEntryEditor::setEnabled(" << enabled << ")";

  enabled = enabled_;  // Save it for resetParams

  suffixEdit->setEnabled(enabled);
  sourceBox->setEnabled(sourceEditable && enabled);
  enabledBox->setEnabled(enabled);
  debugBox->setEnabled(enabled);
  sitesEdit->setEnabled(enabled);
  reportEdit->setEnabled(enabled);
  cwdEdit->setEnabled(enabled);
  for (int row = 0; row < paramsForm->rowCount(); row++) {
    QLayoutItem *item = paramsForm->itemAt(row, QFormLayout::LabelRole);
    item = paramsForm->itemAt(row, QFormLayout::FieldRole);
    AtomicWidget *editor = dynamic_cast<AtomicWidget *>(item->widget());
    Q_ASSERT(editor);
    editor->setEnabled(enabled);
  }
}

int TargetConfigEntryEditor::addSource(dessser::gen::sync_key::t const &k) {
  return findOrAddSourceName(baseNameOfKey(k));
}

int TargetConfigEntryEditor::findOrAddSourceName(QString const &name) {
  if (name.isEmpty()) return -1;

  int i{sourceBox->findText(name)};
  if (i >= 0) return i;  // found

  /* Not found, insert it.
   * This must leave the selection on the same text as before, including if
   * nothing was selected then we must counter Qt's urge to select anything.
   * The caller will decide if the selection must change to that new entry. */
  int const idx{sourceBox->currentIndex()};
  sourceBox->addItem(name);
  i = sourceBox->findText(name);
  if (verbose)
    qDebug() << "TargetConfigEntryEditor::findOrAddSourceName: adding" << name
             << "at" << i << "(selection moved from index" << idx << "to"
             << sourceBox->currentIndex() << ")";

  return i;
}

void TargetConfigEntryEditor::updateSourceWarnings() {
  int const i{sourceBox->currentIndex()};
  if (i < 0 || i > sourceBox->count()) {
    /* No need to warn about the selected entry, the placeholder
     * text is enough. */
    sourceDoesExist = true;
    sourceIsCompiled = true;
  } else {
    QString const name{sourceBox->currentText()};
    std::shared_ptr<dessser::gen::sync_key::t const> info_key{
        keyOfSourceName(name, "info")};
    kvs->lock.lock_shared();
    std::shared_ptr<dessser::gen::sync_key::t const> ramen_src{
        keyOfSourceName(name, "ramen")};
    sourceDoesExist = kvs->map.find(ramen_src) != kvs->map.end();
    if (!sourceDoesExist) {
      std::shared_ptr<dessser::gen::sync_key::t const> ramen_alert{
          keyOfSourceName(name, "alert")};
      sourceDoesExist = kvs->map.find(ramen_alert) != kvs->map.end();
    }
    auto it{kvs->map.find(info_key)};
    sourceIsCompiled = it != kvs->map.end() && isCompiledSource(it->second);
    kvs->lock.unlock_shared();
  }

  deletedSourceWarning->setVisible(!sourceDoesExist);
  notCompiledSourceWarning->setVisible(sourceDoesExist && !sourceIsCompiled);
}

void TargetConfigEntryEditor::clearParams() {
  // Note: emptyLayout(paramsForm) won't update the QFormLayout rowCount :(
  while (paramsForm->rowCount() > 0)
    paramsForm->removeRow(0);  // Note: this also deletes the widgets
}

std::shared_ptr<dessser::gen::raql_value::t const>
TargetConfigEntryEditor::paramValue(
    dessser::gen::program_parameter::t const &p) const {
  /* Try to find a set parameter by that name, falling back on the
   * compiled default: */
  if (verbose)
    qDebug() << "TargetConfigEntryEditor: paramValue("
             << QString::fromStdString(p.name) << ") is"
             << (setParamValues.contains(p.name) ? "present" : "absent");
  return setParamValues.value(p.name, p.value);
}

/* Not the brightest idea to use labels as value store, but there you go: */
static QString const labelOfParamName(std::string const &pname) {
  return QString::fromStdString(pname) + ":";
}
static std::string const paramNameOfLabel(QString const &label) {
  Q_ASSERT(label.length() > 0);
  return removeAmp(label.left(label.length() - 1)).toStdString();
}

/* Save the values that are currently set (and that can be parsed) into
 * setParamValues, for later reuse (until source is changed). */
void TargetConfigEntryEditor::saveParams() {
  for (int row = 0; row < paramsForm->rowCount(); row++) {
    QLayoutItem *item{paramsForm->itemAt(row, QFormLayout::LabelRole)};
    QLabel *label{dynamic_cast<QLabel *>(item->widget())};
    Q_ASSERT(label);
    std::string const pname{paramNameOfLabel(label->text())};

    item = paramsForm->itemAt(row, QFormLayout::FieldRole);
    AtomicWidget *editor{dynamic_cast<AtomicWidget *>(item->widget())};
    Q_ASSERT(editor);
    std::shared_ptr<dessser::gen::sync_value::t const> val{editor->getValue()};
    if (val) {
      if (val->index() == dessser::gen::sync_value::RamenValue) {
        if (verbose)
          qDebug() << "TargetConfigEntryEditor: set paramValues["
                   << QString::fromStdString(pname) << "] to" << *val;
        setParamValues[pname] =
            std::get<dessser::gen::sync_value::RamenValue>(*val);
      } else {
        qCritical() << "AtomicWidget editor returned value for row" << row
                    << "(name" << QString::fromStdString(pname) << "):" << *val
                    << "that's not a RaQL value?!";
      }
    } else {
      qCritical() << "AtomicWidget editor returned no value for row" << row
                  << "(name" << QString::fromStdString(pname) << ")";
    }
  }
}

/* Rebuilt the parameters form, with one line per parameter, which current
 * value is taken from setParamValues or the default parameter value.
 * Called by setValue and when changing the source. */
void TargetConfigEntryEditor::resetParams() {
  /* Clear the paramsForm and rebuilt it, taking values from saved values */
  clearParams();

  QString const baseName{sourceBox->currentText()};
  if (baseName.isEmpty()) return;

  dessser::gen::sync_key::t const infoKey{
      std::in_place_index<dessser::gen::sync_key::Sources>,
      baseName.toStdString(), "info"};

  kvs->lock.lock_shared();
  dessser::gen::source_info::t const *info{nullptr};
  auto it{kvs->map.find(std::shared_ptr<dessser::gen::sync_key::t const>(
      &infoKey, /* No del */ [](dessser::gen::sync_key::t const *) {}))};
  if (it != kvs->map.end()) {
    if (it->second.val->index() == dessser::gen::sync_value::SourceInfo)
      info = &std::get<dessser::gen::sync_value::SourceInfo>(*it->second.val);
  }
  kvs->lock.unlock_shared();

  if (!info) {
    /* This can be normal during sync though: */
    if (!Menu::getClient()->isSynced()) {
      qDebug() << "TargetConfigEntryEditor: Cannot get info" << infoKey
               << ", more luck later when sync is complete.";
    } else if (it != kvs->map.end() && isNull(*it->second.val)) {
      /* Or if it's still being compiled */
      qDebug() << "TargetConfigEntryEditor: info" << infoKey << "is still NULL";
    } else {
      qWarning() << "Cannot get info" << infoKey;
      qWarning() << "conf map is:";
      for (auto &it : kvs->map) {
        qWarning() << "  " << *it.first << "->"
                   << syncValToQString(*it.second.val, it.first);
      }
    }
    return;
  }

  if (info->detail.index() != dessser::gen::source_info::Compiled) {
    qDebug() << "TargetConfigEntryEditor: Info is not compiled for" << infoKey;
    return;
  }

  dessser::gen::source_info::compiled_program const &prog{
      std::get<dessser::gen::source_info::Compiled>(info->detail)};

  bool has_params{false};
  for (dessser::gen::program_parameter::t const &p : prog.default_params) {
    // TODO: a tooltip with the parameter doc
    std::shared_ptr<dessser::gen::raql_value::t const> rval{paramValue(p)};
    /* paramEdit->setValue wants the value to be a shared_ptr<sync_value>,
     * but since sync_value store a pointer to the raql_value `rval`, we want
     * this new value to have the same lifespan as `rval`. */
    std::shared_ptr<dessser::gen::sync_value::t const> val{
        std::make_shared<dessser::gen::sync_value::t>(
            std::in_place_index<dessser::gen::sync_value::RamenValue>,
            std::const_pointer_cast<dessser::gen::raql_value::t>(rval))};
    // Get an editor for that type of value:
    AtomicWidget *paramEdit{newRaqlValueEditorWidget(*p.typ)};
    /* In theory, AtomicWidget got their value from the key. But here we
     * have no key but we know the value so let's just set it: */
    paramEdit->setValue(val);
    paramEdit->setEnabled(enabled);
    connect(paramEdit, &AtomicWidget::inputChanged, this,
            &TargetConfigEntryEditor::inputChanged);
    paramsForm->addRow(labelOfParamName(p.name), paramEdit);
    has_params = true;
  }

  paramsOrInfo->setCurrentIndex(has_params ? paramsFormIdx : noParamsInfoIdx);
}

void TargetConfigEntryEditor::setValue(dessser::gen::rc_entry::t const &entry) {
  if (verbose) qDebug() << "TargetConfigEntryEditor::setValue" << entry;
  if (entry.program.length() == 0) {
    suffixEdit->setEnabled(false);
    sourceBox->setEnabled(false);
  } else {
    std::string const srcPath{srcPathFromProgramName(entry.program)};
    std::string const programSuffix{suffixFromProgramName(entry.program)};
    suffixEdit->setText(QString::fromStdString(programSuffix));

    suffixEdit->setEnabled(enabled);
    sourceBox->setEnabled(sourceEditable && enabled);
    QString const source{QString::fromStdString(srcPath)};
    int const idx{findOrAddSourceName(source)};
    /* Will call resetParams, in theory only after this event is done, in
     * practice though much quicker: */
    sourceBox->setCurrentIndex(idx);
  }
  updateSourceWarnings();

  enabledBox->setCheckState(entry.enabled ? Qt::Checked : Qt::Unchecked);
  debugBox->setCheckState(entry.debug ? Qt::Checked : Qt::Unchecked);
  automaticBox->setCheckState(entry.automatic ? Qt::Checked : Qt::Unchecked);
  sitesEdit->setText(QString::fromStdString(entry.on_site));
  reportEdit->setText(QString::number(entry.report_period));
  cwdEdit->setText(QString::fromStdString(entry.cwd));

  // Also save the parameter values so that resetParams can find them:
  for (dessser::gen::program_run_parameter::t const &p : entry.params) {
    if (!p.value) continue;
    if (verbose)
      qDebug() << "TargetConfigEntryEditor: Save value" << *p.value
               << "for param" << QString::fromStdString(p.name);
    setParamValues[p.name] = p.value;
  }
  /* Call explicitly here because it's been called too early by sourceBox
   * currentTextChanged: */
  resetParams();
}

std::shared_ptr<dessser::gen::rc_entry::t> TargetConfigEntryEditor::getValue()
    const {
  bool ok;
  double reportPeriod = reportEdit->text().toDouble(&ok);
  if (!ok) {
    qCritical() << "Cannot convert report period" << reportEdit->text()
                << "into a double, using default";
    /* Use some default then. Would be nice if it were the same as
     * in RamenConsts. */
    reportPeriod = 30.;
  }

  std::string const cwd{cwdEdit->text().toStdString()};

  std::string const programName{suffixEdit->text().isEmpty()
                                    ? sourceBox->currentText().toStdString()
                                    : sourceBox->currentText().toStdString() +
                                          '#' +
                                          suffixEdit->text().toStdString()};

  std::shared_ptr<dessser::gen::rc_entry::t> entry{
      std::make_shared<dessser::gen::rc_entry::t>(
          programName, enabledBox->checkState() == Qt::Checked,
          debugBox->checkState() == Qt::Checked, reportPeriod, cwd,
          dessser::Arr<dessser::gen::program_run_parameter::t_ext>(),
          sitesEdit->text().toStdString(),
          automaticBox->checkState() == Qt::Checked)};

  // Add parameters (skipping those without a value):
  for (int row = 0; row < paramsForm->rowCount(); row++) {
    QLayoutItem *item = paramsForm->itemAt(row, QFormLayout::LabelRole);
    QLabel *label = dynamic_cast<QLabel *>(item->widget());
    Q_ASSERT(label);
    std::string const pname{paramNameOfLabel(label->text())};

    item = paramsForm->itemAt(row, QFormLayout::FieldRole);
    AtomicWidget *editor{dynamic_cast<AtomicWidget *>(item->widget())};
    Q_ASSERT(editor);
    std::shared_ptr<dessser::gen::sync_value::t const> val{editor->getValue()};
    if (!val) continue;
    // We need to steel the raql_value from this shared value:
    Q_ASSERT(val->index() == dessser::gen::sync_value::RamenValue);
    std::shared_ptr<dessser::gen::raql_value::t> pval{
        std::get<dessser::gen::sync_value::RamenValue>(*val)};
    entry->params.push_back(
        dessser::gen::program_run_parameter::t{pname, pval});
  }

  if (verbose) qDebug() << "TargetConfigEntryEditor::getValue" << *entry;

  return entry;
}

bool TargetConfigEntryEditor::isValid() const {
  if (!sourceDoesExist || !sourceIsCompiled) return false;
  if (!suffixEdit->hasAcceptableInput()) return false;
  if (!sitesEdit->hasAcceptableInput()) return false;
  if (!reportEdit->hasAcceptableInput()) return false;

  return true;
}
