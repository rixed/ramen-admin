// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "source/NewProgramDialog.h"

#include <QDebug>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtGlobal>
#include <cassert>
#include <ctime>
#include <string>

#include "ConfClient.h"
#include "Menu.h"
#include "RCEntryEditor.h"
#include "desssergen/rc_entry.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

static bool const verbose{false};

NewProgramDialog::NewProgramDialog(QString const &sourceName, QWidget *parent)
    : QDialog(parent), mustSave(false) {
  bool const sourceEditable{sourceName.isEmpty()};
  editor = new RCEntryEditor(sourceEditable);
  editor->setProgramName(sourceName.toStdString());
  editor->setEnabled(true);

  /* Cannot use a QDialogButtonBox because the form therein is leaking
   * all its keypress events and a mere enter would accept without validation
   * and a single press on escape would close the dialog and forget all user
   * edits with no second though.
   * Notice that even a button called "Cancel" may be set as the default,
   * but at least when not using QDialogButtonBox it is possible to remove
   * that default. */
  okButton = new QPushButton(tr("Submit"));
  okButton->setAutoDefault(false);
  okButton->setDefault(false);
  QPushButton *cancelButton{new QPushButton(tr("Cancel"))};
  cancelButton->setAutoDefault(false);
  cancelButton->setDefault(false);
  QHBoxLayout *buttonBox{new QHBoxLayout};
  buttonBox->addStretch();
  buttonBox->addWidget(cancelButton);
  buttonBox->addWidget(okButton);
  /* Find out the initial state of the buttons depending on the initial
   * validity of the form: */
  validate();

  connect(editor, &RCEntryEditor::inputChanged, this,
          &NewProgramDialog::validate);
  connect(okButton, &QPushButton::clicked, this,
          &NewProgramDialog::createProgram);
  connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

  QVBoxLayout *layout{new QVBoxLayout};
  layout->addWidget(editor);
  layout->addLayout(buttonBox);
  setLayout(layout);

  // Listen for all locks on the RC:
  connect(kvs.get(), &KVStore::keyChanged, this, &NewProgramDialog::onChange);

  setWindowTitle(tr("Start New Program"));
  setModal(true);
}

void NewProgramDialog::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyLocked:
        mayWriteRC(change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

void NewProgramDialog::createProgram() {
  if (verbose)
    qDebug() << "NewProgramDialog: createProgram: editor is"
             << (editor->isValid() ? "" : "not ") << "valid";

  if (!editor->isValid()) return;

  mustSave = true;

  /* This is where having a single config entry for the whole RC is
   * inconvenient: We have to lock it, modify it, and unlock it.
   * Had we one entry per program we could simply use NewKey.
   * Here instead we write only if/when we obtain the lock. */
  std::shared_ptr<dessser::gen::sync_value::t const> rc_value;
  kvs->lock.lock_shared();
  auto it{kvs->map.find(targetConfig)};
  if (it != kvs->map.end() && it->second.isMine()) rc_value = it->second.val;
  kvs->lock.unlock_shared();

  if (rc_value) {
    appendEntry(*rc_value);
  } else {
    if (verbose) qDebug() << "NewProgramDialog: createProgram: must wait";
    Menu::getClient()->sendLock(targetConfig);
  }
}

void NewProgramDialog::mayWriteRC(
    std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &kv) {
  if (*key != *targetConfig) return;
  if (!mustSave) return;

  if (verbose) qDebug() << "NewProgramDialog::mayWriteRC: key=" << *key;

  if (kv.uid == my_uid)
    appendEntry(*kv.val);  // else wait longer...
  else if (verbose)
    qDebug() << "NewProgramDialog::mayWriteRC: currently locked by" << kv.uid;
}

void NewProgramDialog::appendEntry(
    dessser::gen::sync_value::t const &rc_value) {
  if (!mustSave) return;

  if (rc_value.index() == dessser::gen::sync_value::TargetConfig) {
    std::shared_ptr<dessser::gen::rc_entry::t> rce{editor->getValue()};
    if (verbose)
      qDebug() << "NewProgramDialog::appendEntry: Appending new RC entry"
               << *rce;
    // Copy the array of rc-entries and append the new one:
    std::shared_ptr<dessser::gen::sync_value::t> new_rc_value{
        std::make_shared<dessser::gen::sync_value::t>(rc_value)};
    std::get<dessser::gen::sync_value::TargetConfig>(*new_rc_value)
        .push_back(rce);

    Menu::getClient()->sendSet(targetConfig, new_rc_value);
  } else {
    qCritical() << "NewProgramDialog::appendEntry:Invalid type for the "
                   "TargetConfig!?";
  }

  mustSave = false;
  Menu::getClient()->sendUnlock(targetConfig);
  /* Maybe reset the editor? */
  QDialog::accept();
}

void NewProgramDialog::validate() { okButton->setEnabled(editor->isValid()); }
