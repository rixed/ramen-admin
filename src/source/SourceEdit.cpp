// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "source/SourceEdit.h"

#include <QComboBox>
#include <QDebug>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QtGlobal>

#include "KTextEdit.h"
#include "KVStore.h"
#include "ProgramItem.h"
#include "desssergen/source_info.h"
#include "desssergen/sync_value.h"
#include "misc.h"
#include "misc_dessser.h"
#include "source/AlertInfoEditor.h"
#include "source/SourceInfoViewer.h"

static constexpr bool verbose{false};

SourceEdit::SourceEdit(QWidget *parent) : QWidget(parent) {
  extensionsCombo = new QComboBox;
  extensionsCombo->setObjectName("extensionsCombo");
  connect(extensionsCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &SourceEdit::inputChanged);

  stackedLayout = new QStackedLayout;
  stackedLayout->setObjectName("stackedLayout");

  alertEditor = new AlertInfoEditor;
  alertEditor->setObjectName("alertEditor");
  connect(alertEditor, &AlertInfoEditor::inputChanged, this,
          &SourceEdit::inputChanged);

  /* Beware: Same indices are used to access currentWidget, stackedLayout,
   * extensionsCombo: */
  alertEditorIndex = stackedLayout->addWidget(alertEditor);
  extensionsCombo->addItem(tr("Simple Alert"), "alert");

  textEditor = new KTextEdit;
  textEditor->setObjectName("textEditor");
  connect(textEditor, &KTextEdit::inputChanged, this,
          &SourceEdit::inputChanged);

  textEditorIndex = stackedLayout->addWidget(textEditor);
  extensionsCombo->addItem(tr("Ramen Language (RaQL)"), "ramen");

  infoEditor = new SourceInfoViewer;
  infoEditor->setObjectName("infoEditor");
  infoEditorIndex = stackedLayout->addWidget(infoEditor);
  extensionsCombo->addItem(tr("Compiled Informations"), "info");

  QFormLayout *switcherLayout{new QFormLayout};
  switcherLayout->setObjectName("switcherLayout");
  switcherLayout->addRow(tr("At which level do you want to edit this program?"),
                         extensionsCombo);
  extensionSwitcher = new QWidget;
  extensionSwitcher->setObjectName("extensionSwitcher");
  extensionSwitcher->setLayout(switcherLayout);

  errorsBox = new QWidget;
  QVBoxLayout *errLayout{new QVBoxLayout};
  errLayout->addWidget(new QLabel(tr("Errors:")));
  compilationErrors = new QLabel;
  compilationErrors->setObjectName("compilationErrors");
  compilationErrors->setWordWrap(true);
  errLayout->addWidget(compilationErrors);
  errorsBox->setLayout(errLayout);
  errorsBox->hide();

  warningsBox = new QWidget;
  QVBoxLayout *wrnLayout{new QVBoxLayout};
  wrnLayout->addWidget(new QLabel(tr("Warnings:")));
  compilationWarnings = new QLabel;
  compilationWarnings->setObjectName("compilationWarnings");
  compilationWarnings->setWordWrap(true);
  wrnLayout->addWidget(compilationWarnings);
  warningsBox->setLayout(wrnLayout);
  warningsBox->hide();

  QVBoxLayout *layout{new QVBoxLayout};
  layout->setContentsMargins(QMargins());
  layout->addWidget(extensionSwitcher);
  layout->addLayout(stackedLayout);
  layout->addWidget(errorsBox);
  layout->addWidget(warningsBox);
  setLayout(layout);

  // Connect the error label to this hide/show slot
  connect(kvs.get(), &KVStore::keyChanged, this, &SourceEdit::onChange);

  // Display the corresponding widget when the extension combobox changes:
  connect(extensionsCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &SourceEdit::setLanguage);
}

void SourceEdit::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyCreated:
      case KeyChanged:
        setError(change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

AtomicWidget const *SourceEdit::currentWidget() const {
  int const editorIndex{extensionsCombo->currentIndex()};

  if (editorIndex == textEditorIndex) {
    return textEditor;
  } else if (editorIndex == alertEditorIndex) {
    return alertEditor;
  } else if (editorIndex == infoEditorIndex) {
    return infoEditor;
  }

  qFatal("SourceEdit: invalid editorIndex=%d", editorIndex);
}

std::shared_ptr<dessser::gen::sync_value::t const> SourceEdit::getValue()
    const {
  return currentWidget()->getValue();
}

bool SourceEdit::hasValidInput() const {
  return currentWidget()->hasValidInput();
}

void SourceEdit::enableLanguage(int index, bool enabled) {
  QStandardItemModel *model{
      static_cast<QStandardItemModel *>(extensionsCombo->model())};

  if (enabled != model->item(index)->isEnabled()) {
    if (verbose)
      qDebug() << "SourceEdit: language" << index
               << (extensionsCombo->currentIndex() == index ? " (current)" : "")
               << "is now" << enabled;

    model->item(index)->setEnabled(enabled);
  }

  /* As much as possible we want the current selected language to be enabled.
   * That's how the form switch to a valid language when selecting another
   * source. */
  if (!model->item(extensionsCombo->currentIndex())->isEnabled()) {
    for (int row = 0; row < model->rowCount(); row++) {
      if (model->item(row)->isEnabled()) {
        if (verbose) qDebug() << "SourceEdit: switching extension to" << row;
        extensionsCombo->setCurrentIndex(row);
        break;
      }
    }
  }
}

void SourceEdit::setLanguageKey(
    int index, AtomicWidget *editor,
    std::shared_ptr<dessser::gen::sync_key::t const> key) {
  if (verbose) {
    if (key)
      qDebug() << "SourceEdit: set language key for index" << index << "to"
               << *key;
    else
      qDebug() << "SourceEdit: no key for language index" << index;
  }

  enableLanguage(index, !!key);
  editor->setKey(key);
  editor->setValueFromStore();
}

void SourceEdit::setLanguage(int index) {
  if (verbose)
    qDebug() << "SourceEdit::setLanguage: Switching to language" << index;

  stackedLayout->setCurrentIndex(index);
  /* Useful when called by NewSourceDialog but not so much when signaling
   * currentIndexChanged: */
  extensionsCombo->setCurrentIndex(index);
}

void SourceEdit::setError(std::shared_ptr<dessser::gen::sync_key::t const> key,
                          KValue const &kv) {
  std::optional<std::pair<std::string const, std::string const> > src_path{
      srcPathOfKey(*key)};
  if (!src_path || src_path->first != srcPath || src_path->second != "info")
    return;
  doResetError(kv);
}

void SourceEdit::doResetError(KValue const &kv) {
  if (kv.val->index() != dessser::gen::sync_value::SourceInfo) {
    qCritical() << "SourceEdit::doResetError: Not a SourceInfo:" << *kv.val;
    return;
  }

  errorsBox->setVisible(false);
  warningsBox->setVisible(false);

  auto const &info_detail{
      std::get<dessser::gen::sync_value::SourceInfo>(*kv.val)->detail};

  switch (info_detail.index()) {
    case dessser::gen::source_info::Failed: {
      auto const &failed{
          std::get<dessser::gen::source_info::Failed>(info_detail)};
      QString err_msg;
      for (auto const &err : failed.errors)
        err_msg += raqlErrorToQString(*err) + '\n';
      if (!err_msg.isEmpty()) {
        compilationErrors->setText(stringOfDate(kv.mtime) + ":\n" + err_msg);
        errorsBox->setVisible(true);
      }
    } break;
    case dessser::gen::source_info::Compiled: {
      auto const &compiled{
          std::get<dessser::gen::source_info::Compiled>(info_detail)};
      QString warnings;
      for (auto const &warn : compiled->warnings)
        warnings += raqlWarningToQString(*warn) + '\n';
      if (!warnings.isEmpty()) {
        compilationWarnings->setText(stringOfDate(kv.mtime) + ":\n" + warnings);
        warningsBox->setVisible(true);
      }
    } break;
    default:
      qFatal("Invalid info_detail index");
      break;
  }
}

void SourceEdit::resetError(KValue const *kv) {
  if (kv) {
    doResetError(*kv);
  } else {
    compilationErrors->setText("");
    errorsBox->setVisible(false);
    compilationWarnings->setText(tr("Not compiled yet"));
    warningsBox->setVisible(true);
  }
}

void SourceEdit::setSrcPath(std::string const &path) {
  if (verbose)
    qDebug() << "SourceEdit::setSrcPath:" << QString::fromStdString(path)
             << "replacing " << QString::fromStdString(srcPath);

  if (path == srcPath) return;
  srcPath = path;

  std::shared_ptr<dessser::gen::sync_key::t const> alertKey{
      keyOfSrcPath(path, "alert")};
  std::shared_ptr<dessser::gen::sync_key::t const> ramenKey{
      keyOfSrcPath(path, "ramen")};
  std::shared_ptr<dessser::gen::sync_key::t const> infoKey{
      keyOfSrcPath(path, "info")};

  unsigned numSources{0};

  kvs->lock.lock_shared();
  KValue const *kv{nullptr};

  /* When the path is set (ie. the view switch to this source) select
   * by default the language that has been edited most recently by a human: */
  double latest_mtime{0};
  int latest_index{-1};
  std::function<void(double mtime, QString const &uid, int index)> const
      compete_latest = [&latest_mtime, &latest_index](
                           double mtime, QString const &uid, int index) {
        // Default on the higher level language that's defined:
        if (latest_index < 0) {
          latest_mtime = mtime;
          latest_index = index;
        } else if (uid.size() == 0 || uid.at(0) == '_') {
          // not a human
        } else if (mtime >= latest_mtime) {
          latest_mtime = mtime;
          latest_index = index;
        }
      };

  // Look for the alert first:
  auto it{kvs->map.find(alertKey)};
  if (it != kvs->map.end() &&
      /* Skip Null values that are created as placeholder during compilation:
       */
      !isNull(*it->second.val)) {
    if (verbose) qDebug() << "SourceEdit::setSrcPath: found an alert";
    setLanguageKey(alertEditorIndex, alertEditor, alertKey);
    numSources++;
    compete_latest(it->second.mtime, it->second.uid, alertEditorIndex);
  } else {
    setLanguageKey(alertEditorIndex, alertEditor, nullptr);
  }

  // Then look for the ramen source that is the second best option:
  it = kvs->map.find(ramenKey);
  if (it != kvs->map.end() &&
      /* Skip Null values that are created as placeholder during compilation:
       */
      !isNull(*it->second.val)) {
    if (verbose) qDebug() << "SourceEdit::setSrcPath: found ramen code";
    setLanguageKey(textEditorIndex, textEditor, ramenKey);
    numSources++;
    compete_latest(it->second.mtime, it->second.uid, textEditorIndex);
  } else {
    setLanguageKey(textEditorIndex, textEditor, nullptr);
  }

  // When all else fails, display the (non-editable) info:
  it = kvs->map.find(infoKey);
  if (it != kvs->map.end() &&
      /* Skip Null values that are created as placeholder during compilation:
       */
      !isNull(*it->second.val)) {
    if (verbose) qDebug() << "SourceEdit::setSrcPath: found info";
    setLanguageKey(infoEditorIndex, infoEditor, infoKey);
    numSources++;
    // To show error messages prominently regardless of the current editor:
    kv = &it->second;
    /* Info will be the latest edit but it's not a source language:
     * compete_latest(it->second.mtime, infoEditorIndex); */
  } else {
    // Disable that language
    setLanguageKey(infoEditorIndex, infoEditor, nullptr);
  }

  extensionSwitcher->setVisible(numSources > 1);
  setLanguage(latest_index);

  resetError(kv);
  kvs->lock.unlock_shared();
}

void SourceEdit::disableLanguageSwitch(bool disabled) {
  extensionsCombo->setEnabled(!disabled);
}
