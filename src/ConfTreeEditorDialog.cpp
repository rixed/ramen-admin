#include <QLabel>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>

#include "AtomicWidget.h"
#include "ConfClient.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "EditorWidget.h"
#include "KValue.h"
#include "KVStore.h"
#include "Menu.h"
#include "misc.h"
#include "misc_dessser.h"

#include "ConfTreeEditorDialog.h"

ConfTreeEditorDialog::ConfTreeEditorDialog(
  std::shared_ptr<dessser::gen::sync_key::t const> key_, QWidget *parent)
  : QDialog(parent),
    key(key_)
{
  /* Locate the value in the kvs: */
  KValue const *kv = nullptr;
  kvs->lock.lock_shared();
  auto it = kvs->map.find(key);
  if (it != kvs->map.end()) kv = &it->second;
  kvs->lock.unlock_shared();
  if (! kv) {
    assert(!"TODO: display a QLabel(error) instead");
  }
  can_write = kv->can_write;

  /* The header: */
  QFormLayout *headerLayout = new QFormLayout;
  QLabel *keyName { new QLabel(syncKeyToQString(*key)) };
  keyName->setWordWrap(true);
  headerLayout->addRow(tr("Key:"), keyName);
  QLabel *setter { new QLabel(kv->uid) };
  headerLayout->addRow(tr("Last Modified By:"), setter);
  QLabel *mtime { new QLabel(stringOfDate(kv->mtime)) };
  headerLayout->addRow(tr("Last Modified At:"), mtime);
  if (kv->isLocked()) {
    QLabel *locker { new QLabel(kv->owner) };
    headerLayout->addRow(tr("Locked By:"), locker);
    QLabel *expiry { new QLabel(stringOfDate(kv->expiry)) };
    headerLayout->addRow(tr("Expiry:"), expiry);
  }

  editor = newEditorWidget(*kv->val, key);
  QDialogButtonBox *buttonBox {
    new QDialogButtonBox(
      can_write ? QDialogButtonBox::Ok | QDialogButtonBox::Cancel :
                  QDialogButtonBox::Close) };  // Note: Close will reject

  if (can_write)
    connect(buttonBox, &QDialogButtonBox::accepted,
            this, &ConfTreeEditorDialog::save);
  /* Connect first the cancel button to the normal reject signal, and
   * then this signal to our cancel slot, so that cancel is also called
   * when user presses the escape key: */
  connect(buttonBox, &QDialogButtonBox::rejected,
          this, &QDialog::reject);
  connect(this, &QDialog::rejected,
          this, &ConfTreeEditorDialog::cancel);

  /* The editor will start in read-only mode (unless we already own the
   * value). Reception of the lock ack from the confserver will turn it
   * into read-write mode: */
  if (can_write) Menu::getClient()->sendLock(key);

  /* Now the layout: */
  QVBoxLayout *mainLayout { new QVBoxLayout };
  QFrame* header { new QFrame };
  header->setFrameShape(QFrame::Panel);
  header->setFrameShadow(QFrame::Raised);
  header->setLayout(headerLayout);
  mainLayout->addWidget(header);
  mainLayout->addWidget(editor);
  mainLayout->addWidget(buttonBox);
  setLayout(mainLayout);

  /* Now that the layout is known, set window decorations, sizes etc: */
  setWindowTitle(tr("Value Editor"));
  setSizeGripEnabled(true); // editors of various types vary largely in size
}

void ConfTreeEditorDialog::save()
{
  std::shared_ptr<dessser::gen::sync_value::t const> v { editor->getValue() };
  ConfClient *client = Menu::getClient();
  if (v) client->sendSet(key, v); // read-only editors return no value
  if (can_write) client->sendUnlock(key);
  emit QDialog::accept();
}

void ConfTreeEditorDialog::cancel()
{
  if (can_write) Menu::getClient()->sendUnlock(key);
}
