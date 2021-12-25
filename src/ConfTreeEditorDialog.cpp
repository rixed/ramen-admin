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
#include "KTextEdit.h"
#include "KValue.h"
#include "KVStore.h"
#include "Menu.h"
#include "misc.h"
#include "misc_dessser.h"

#include "ConfTreeEditorDialog.h"

ConfTreeEditorDialog::ConfTreeEditorDialog(
  std::shared_ptr<dessser::gen::sync_key::t const> key_,
  bool show_editor,
  QWidget *parent)
  : QDialog(parent),
    key(key_),
    showEditor(show_editor)
{
  /* Locate the value in the kvs: */
  KValue const *kv = nullptr;
  kvs->lock.lock_shared();
  auto it = kvs->map.find(key);
  if (it != kvs->map.end()) kv = &it->second;
  kvs->lock.unlock_shared();
  if (! kv) {
    qFatal("TODO: display a QLabel(error) instead");
  }
  canWrite = kv->can_write;

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

  /* When we do not want to show the editor we still want to see the value,
   * in raw form, and non editable. We get the raw form by forcing the "editor"
   * to be a KTextEdit editor, and we get it read-only by not locking that key. */
  if (showEditor) {
    editor = newEditorWidget(*kv->val, key);
  } else {
    editor = new KTextEdit(false, nullptr);
    editor->setKey(key);
    editor->setValueFromStore();
  }

  QDialogButtonBox *buttonBox {
    new QDialogButtonBox(
      canWrite && showEditor ?
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel :
        QDialogButtonBox::Close) };  // Note: Close will reject

  if (canWrite && showEditor)
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
  if (canWrite && showEditor) Menu::getClient()->sendLock(key);

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
  setWindowTitle(tr(showEditor ? "Value Editor" : "Value Details"));
  setSizeGripEnabled(true); // editors of various types vary largely in size
}

void ConfTreeEditorDialog::save()
{
  std::shared_ptr<dessser::gen::sync_value::t const> v { editor->getValue() };
  ConfClient *client = Menu::getClient();
  if (v) client->sendSet(key, v); // read-only editors return no value
  if (canWrite && showEditor) client->sendUnlock(key);
  QDialog::accept();
}

void ConfTreeEditorDialog::cancel()
{
  if (canWrite && showEditor) Menu::getClient()->sendUnlock(key);
}
