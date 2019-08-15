#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include "RCEntryEditor.h"
#include "conf.h"
#include "confValue.h"
#include "RamenValue.h"
#include "NewProgramDialog.h"

static bool const verbose = true;

static std::string rc_key("target_config");

NewProgramDialog::NewProgramDialog(QString const &sourceName, QWidget *parent) :
  QDialog(parent),
  mustSave(false)
{
  bool const sourceEditable = sourceName.isEmpty();
  editor = new RCEntryEditor(sourceEditable);
  editor->setSourceName(sourceName);

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
  okButton->setEnabled(false);
  QPushButton *cancelButton = new QPushButton(tr("Cancel"));
  cancelButton->setAutoDefault(false);
  cancelButton->setDefault(false);
  QHBoxLayout *buttonBox = new QHBoxLayout;
  buttonBox->addStretch();
  buttonBox->addWidget(cancelButton);
  buttonBox->addWidget(okButton);

  connect(editor, &RCEntryEditor::inputChanged,
          this, &NewProgramDialog::validate);
  connect(okButton, &QPushButton::clicked,
          this, &NewProgramDialog::createProgram);
  connect(cancelButton, &QPushButton::clicked,
          this, &QDialog::reject);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(editor);
  layout->addLayout(buttonBox);
  setLayout(layout);

  // Listen for all locks on the RC:
  connect(&kvs, &KVStore::valueLocked,
          this, &NewProgramDialog::mayWriteRC);

  setWindowTitle(tr("Start New Program"));
}

void NewProgramDialog::createProgram()
{
  if (verbose)
    std::cout << "NewProgramDialog: createProgram: editor is "
              << (editor->isValid() ? "" : "not ") << "valid" << std::endl;

  if (! editor->isValid()) return;

  mustSave = true;

  /* This is where having a single config entry for the whole RC is
   * inconvenient: We have to lock it, modify it, and unlock it.
   * Had we one entry per program we could simply use NewKey.
   * Here instead we write only if/when we obtain the lock. */
  std::shared_ptr<conf::Value> rc_value;
  kvs.lock.lock_shared();
  auto it = kvs.map.find(rc_key);
  if (it != kvs.map.end() && it->second.isMine())
    rc_value = it->second.val;
  kvs.lock.unlock_shared();

  if (rc_value) {
    appendEntry(rc_value);
  } else {
    if (verbose)
      std::cout << "NewProgramDialog: createProgram: must wait" << std::endl;
    askLock(rc_key);
  }
}

void NewProgramDialog::mayWriteRC(KVPair const &kvp)
{
  if (verbose)
    std::cout << "NewProgramDialog::mayWriteRC: key=" << kvp.first << std::endl;

  if (kvp.first != rc_key) return;

  if (mustSave && kvp.second.uid == my_uid)
    appendEntry(kvp.second.val); // else wait longer...
}

void NewProgramDialog::appendEntry(std::shared_ptr<conf::Value> rc_value)
{
  if (! mustSave) return;

  if (verbose)
    std::cout << "NewProgramDialog::appendEntry: Appending a new RC entry" << std::endl;

  conf::RCEntry *rce = editor->getValue();

  std::shared_ptr<conf::TargetConfig> rc =
    // No support for improper type here:
    std::dynamic_pointer_cast<conf::TargetConfig>(rc_value);

  if (rc) {
    rc->addEntry(rce);
    if (verbose)
      std::cout << "NewProgramDialog::appendEntry:Added entry with " << rce->params.size() << " params" << std::endl;
    askSet(rc_key, std::static_pointer_cast<conf::Value const>(rc));
  } else {
    std::cerr << "NewProgramDialog::appendEntry:Invalid type for the TargetConfig!?" << std::endl;
  }

  mustSave = false;
  askUnlock(rc_key);
  /* Maybe reset the editor? */
  emit QDialog::accept();
}

void NewProgramDialog::validate()
{
  okButton->setEnabled(editor->isValid());
}
