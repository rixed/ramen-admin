#include "AtomicForm.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <algorithm>

#include "AtomicWidget.h"
#include "ConfClient.h"
#include "KVStore.h"
#include "Menu.h"
#include "Resources.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"

static bool const verbose{false};

AtomicForm::AtomicForm(bool visibleButtons, QWidget *parent) : QWidget(parent) {
  groupLayout = new QVBoxLayout(this);
  groupLayout->setObjectName("groupLayout");
  groupLayout->setContentsMargins(QMargins());
  setLayout(groupLayout);

  /* So we want 3 vertical areas:
   * - the "central widget" (to be set later)
   * - an error area
   * - the button bar "edit" / "cancel"+"submit"
   */
  // The central widget
  centralWidget = new QWidget;
  centralWidget->setObjectName("centralWidget");
  groupLayout->addWidget(centralWidget, 1);

  // The errors area
  errorArea = new QWidget;
  errorArea->setObjectName("errorArea");
  groupLayout->addWidget(errorArea);

  /* The button bar
   * According to MacOS UI guidelines, actions are supposed to be at right
   * and cancellation/going back on the left.
   * We keep the rightmost position for the "submit" action and keep
   * "delete" before it, in fear that users might go for the right-most
   * button out of habit. */
  buttonsLayout = new QHBoxLayout;
  Resources *r{Resources::get()};
  editButton = new QPushButton(r->settingsPixmap, tr("&edit"));
  buttonsLayout->addWidget(editButton);
  connect(editButton, &QPushButton::clicked, this, &AtomicForm::wantEdit);

  cancelButton = new QPushButton(tr("&cancel"));
  buttonsLayout->addWidget(cancelButton);
  connect(cancelButton, &QPushButton::clicked, this, &AtomicForm::wantCancel);
  cancelButton->setEnabled(false);

  deleteButton = new QPushButton(r->deletePixmap, tr("&delete"));
  buttonsLayout->addWidget(deleteButton);
  connect(deleteButton, &QPushButton::clicked, this, &AtomicForm::wantDelete);
  deleteButton->setEnabled(false);
  deleteButton->hide();  // until a deletable widget is added

  submitButton = new QPushButton(tr("&submit"));
  buttonsLayout->addWidget(submitButton);
  connect(submitButton, &QPushButton::clicked, this, &AtomicForm::wantSubmit);
  submitButton->setEnabled(false);

  if (visibleButtons) groupLayout->addLayout(buttonsLayout);

  /* Also prepare the confirmation dialogs: */
  confirmCancelDialog = new QMessageBox(this);
  confirmCancelDialog->setText("Some values have been modified.");
  confirmCancelDialog->setInformativeText("Are you sure you want to cancel?");
  confirmCancelDialog->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  confirmCancelDialog->setDefaultButton(QMessageBox::No);
  confirmCancelDialog->setIcon(QMessageBox::Warning);
  // Would crash:
  // confirmDeleteDialog->setWindowModality(Qt::WindowModal);

  confirmDeleteDialog = new QMessageBox(this);
  confirmDeleteDialog->setText("Are you sure you want to delete this?");
  confirmDeleteDialog->setStandardButtons(QMessageBox::Yes |
                                          QMessageBox::Cancel);
  confirmDeleteDialog->setDefaultButton(QMessageBox::Cancel);
  confirmDeleteDialog->setIcon(QMessageBox::Warning);
  // confirmDeleteDialog->setWindowModality(Qt::WindowModal);

  // Listen to kvs changes:
  connect(kvs.get(), &KVStore::keyChanged, this, &AtomicForm::onChange);
}

void AtomicForm::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    switch (change.op) {
      case KeyLocked:
        lockValue(change.key, change.kv);
        break;
      case KeyUnlocked:
      case KeyDeleted:
        unlockValue(change.key, change.kv);
        break;
      default:
        break;
    }
  }
}

AtomicForm::~AtomicForm() {
  if (verbose) qDebug() << "AtomicForm: destroying" << this;

  // Unlock everything that's locked:
  for (std::shared_ptr<dessser::gen::sync_key::t const> const &k : locked) {
    if (verbose) qDebug() << "AtomicForm: Unlocking" << *k;
    Menu::getClient()->sendUnlock(k);
  }
}

void AtomicForm::setCentralWidget(QWidget *w) {
  if (centralWidget == w) return;

  QLayoutItem *previous =
      groupLayout->replaceWidget(centralWidget, w, Qt::FindDirectChildrenOnly);
  Q_ASSERT(previous);
  centralWidget->deleteLater();
  centralWidget = w;
  delete previous;
  /* Do not automatically add to the widgets as the form central widget
   * need not be an AtomicWidget. */
}

static QString const key2str(
    std::shared_ptr<dessser::gen::sync_key::t const> k) {
  if (!k) return QString("unset");
  return syncKeyToQString(*k);
}

void AtomicForm::addWidget(AtomicWidget *aw, bool deletable) {
  widgets.emplace_back(aw);

  if (verbose)
    qDebug() << "AtomicForm::addWidget: added widget with key"
             << key2str(aw->key()) << ", now has" << widgets.size()
             << "widgets";

  connect(aw, &AtomicWidget::destroyed, this, &AtomicForm::removeWidget);

  if (deletable) {
    deletables.insert(aw);
    deleteButton->show();
  }

  connect(aw, &AtomicWidget::keyChanged, this, &AtomicForm::changeKey);

  connect(aw, &AtomicWidget::inputChanged, this, &AtomicForm::checkValidity);

  connect(aw, &AtomicWidget::valueChanged, this, &AtomicForm::checkValidity);

  // If key is already set, start from it:
  if (aw->key()) changeKey(nullptr, aw->key());

  setEnabled(allLocked());
}

void AtomicForm::changeKey(
    std::shared_ptr<dessser::gen::sync_key::t const> oldKey,
    std::shared_ptr<dessser::gen::sync_key::t const> newKey) {
  if (verbose)
    qDebug() << "AtomicForm: change key from" << key2str(oldKey) << "to"
             << key2str(newKey);

  /* Unlock the former key.
   * If oldKey has been deleted then we won't update the locked set by
   * merely calling sendUnlock(oldKey). Anyway, we won't recognize this key
   * with isMyKey() when the unlock is answered. So also forcibly remove that
   * key: */
  if (oldKey && locked.erase(oldKey) > 0) {
    Menu::getClient()->sendUnlock(oldKey);
  }

  if (!newKey) {
    setEnabled(allLocked());
    return;
  }

  std::optional<QString> owner;

  kvs->lock.lock_shared();
  auto it{kvs->map.find(newKey)};
  if (it != kvs->map.end())
    if (it->second.isLocked()) owner = it->second.owner;
  kvs->lock.unlock_shared();

  setOwner(newKey, owner);
}

void AtomicForm::wantEdit() {
  if (verbose) qDebug() << "AtomicForm: wantEdit, locking all keys...";

  // Lock all widgets that are not locked already:
  for (FormWidget const &w : widgets) {
    std::shared_ptr<dessser::gen::sync_key::t const> key{w.widget->key()};
    if (verbose) qDebug() << "AtomicForm: must I lock" << key2str(key) << "?";
    if (!key) continue;
    if (locked.find(key) == locked.end()) {
      if (verbose) qDebug() << "AtomicForm: yes";
      Menu::getClient()->sendLock(key);
    }
  }

  setEnabled(allLocked());
}

bool AtomicForm::someEdited() {
  for (FormWidget const &w : widgets) {
    std::shared_ptr<dessser::gen::sync_value::t const> v{w.widget->getValue()};
    if (!v) {
      if (verbose) qDebug() << "AtomicForm::someEdited: No value from widget";
      return false;
    }
    if (!w.initValue) {
      if (verbose)
        qDebug() << "AtomicForm: Value of" << key2str(w.widget->key())
                 << "has been set to " << *v;
      return true;
    }
    if (*w.initValue != *v) {
      if (verbose)
        qDebug() << "AtomicForm: Value of" << key2str(w.widget->key())
                 << "has changed from " << *w.initValue << "to" << *v;
      return true;
    }
  }
  return false;
}

void AtomicForm::doCancel() {
  for (FormWidget &w : widgets) {
    std::shared_ptr<dessser::gen::sync_key::t const> key{w.widget->key()};
    if (!key) continue;
    if (!w.initValue) continue;
    w.widget->setValue(w.initValue);
    Menu::getClient()->sendUnlock(key);
  }
}

void AtomicForm::wantCancel() {
  if (someEdited()) {
    if (QMessageBox::Yes == confirmCancelDialog->exec()) {
      doCancel();
    }
  } else {
    doCancel();
  }
}

void AtomicForm::wantDelete() {
  if (deletables.empty()) return;

  QString info(tr("Those keys will be lost forever:\n"));
  for (AtomicWidget *aw : deletables) {
    std::shared_ptr<dessser::gen::sync_key::t const> key{aw->key()};
    if (!key) continue;
    info.append(syncKeyToQString(*key));
    info.append("\n");
  }
  confirmDeleteDialog->setInformativeText(info);

  if (QMessageBox::Yes == confirmDeleteDialog->exec()) {
    for (AtomicWidget *aw : deletables) {
      std::shared_ptr<dessser::gen::sync_key::t const> key{aw->key()};
      if (!key) continue;
      // Start by detaching this key from the widget so this lock is no
      // longer needed
      aw->setKey(nullptr);
      Menu::getClient()->sendDel(key);
    }
  }
}

void AtomicForm::doSubmit() {
  for (FormWidget &w : widgets) {
    std::shared_ptr<dessser::gen::sync_key::t const> key{w.widget->key()};
    if (!key) continue;
    std::shared_ptr<dessser::gen::sync_value::t const> v{w.widget->getValue()};
    if (v && (!w.initValue || *v != *w.initValue))
      Menu::getClient()->sendSet(key, v);
    Menu::getClient()->sendUnlock(key);
  }
}

void AtomicForm::wantSubmit() {
  if (someEdited()) {
    doSubmit();
  } else {
    if (verbose)
      qDebug() << "AtomicForm: Cancelling rather, as no edition was done.";
    doCancel();
  }
}

/* Overwrite QWidget::isEnabled/setEnabled: */

bool AtomicForm::isEnabled() const { return cancelButton->isEnabled(); }

void AtomicForm::setEnabled(bool enabled) {
  bool const wasEnabled{isEnabled()};

  if (verbose)
    qDebug() << "AtomicForm::setEnabled(" << enabled << ", was" << wasEnabled
             << ")";

  if (enabled == wasEnabled) return;

  if (verbose) qDebug() << "AtomicForm::setEnabled(" << enabled << ")";

  /* Capture the widget initial value if we are enabling edition: */
  if (enabled)
    for (FormWidget &w : widgets) {
      w.initValue = w.widget->getValue();
      if (verbose) {
        if (w.initValue)
          qDebug() << "AtomicForm::setEnabled: Captured initValue"
                   << *w.initValue;
        else
          qDebug() << "AtomicForm::setEnabled: no initial value";
      }
    }

  // An enabled form is a form that's editable:
  editButton->setEnabled(!enabled);
  cancelButton->setEnabled(enabled);
  deleteButton->setEnabled(enabled);
  checkValidity();

  emit changeEnabled(enabled);
}

bool AtomicForm::isMyKey(
    std::shared_ptr<dessser::gen::sync_key::t const> k) const {
  Q_ASSERT(k);
  for (FormWidget const &w : widgets) {
    std::shared_ptr<dessser::gen::sync_key::t const> wk{w.widget->key()};
    if (wk && *wk == *k) return true;
  }
  return false;
}

void AtomicForm::lockValue(std::shared_ptr<dessser::gen::sync_key::t const> key,
                           KValue const &kv) {
  if (!isMyKey(key)) return;
  setOwner(key, kv.owner);
}

void AtomicForm::setOwner(std::shared_ptr<dessser::gen::sync_key::t const> k,
                          std::optional<QString> const &u) {
  bool const is_me = my_uid && u.has_value() && *my_uid == *u;

  if (verbose)
    qDebug() << "AtomicForm: Owner of" << *k << "is now"
             << (u.has_value() ? *u : "none") << "(I am" << *my_uid
             << ", so that is" << (is_me ? "" : "not") << "me)";

  if (is_me) {
    locked.insert(k);
  } else {
    locked.erase(k);
  }

  setEnabled(allLocked());
}

bool AtomicForm::allLocked() const {
  bool const ret{std::all_of(
      widgets.cbegin(), widgets.cend(), [this](FormWidget const &w) {
        std::shared_ptr<dessser::gen::sync_key::t const> key{w.widget->key()};
        return !key || locked.find(key) != locked.end();
      })};

  if (verbose) {
    if (ret) {
      qDebug() << "AtomicForm: all your keys are belong to us!";
    } else {
      for (FormWidget const &w : widgets) {
        std::shared_ptr<dessser::gen::sync_key::t const> key{w.widget->key()};
        if (!key) continue;
        if (locked.find(key) == locked.end()) {
          qDebug() << "AtomicForm: missing lock for" << *key;
        }
      }
    }
  }

  return ret;
}

void AtomicForm::unlockValue(
    std::shared_ptr<dessser::gen::sync_key::t const> key, KValue const &) {
  if (!isMyKey(key)) return;

  if (verbose) qDebug() << "AtomicForm:unlock (or del)" << *key;

  locked.erase(key);
  setEnabled(allLocked());
}

/* Note that the AtomicWidget might have already been (at least partially)
 * destructed, so for instance we cannot ask for its key. */
void AtomicForm::removeWidget(QObject *obj) {
  if (verbose)
    qDebug() << "AtomicForm: Removing destroyed AtomicWidget" << obj
             << "from form" << this;

  bool found(false);

  for (auto it = widgets.begin(); it != widgets.end(); it++) {
    if (it->widget == obj) {
      widgets.erase(it);
      found = true;
      break;
    }
  }

  if (!found) qCritical("AtomicForm: Cannot find destroyed object %p", obj);

  for (auto it = deletables.begin(); it != deletables.end(); it++) {
    if (*it == obj) {
      deletables.erase(it);
      break;
    }
  }
}

void AtomicForm::checkValidity() {
  if (!isEnabled()) {
    if (verbose) qDebug() << "AtomicForm: disabled therefore invalid";
    submitButton->setEnabled(false);
    return;
  }

  if (verbose) qDebug() << "AtomicForm: checkValidity";

  for (FormWidget const &w : widgets) {
    std::shared_ptr<dessser::gen::sync_key::t const> key{w.widget->key()};
    if (!key) continue;
    if (!w.widget->hasValidInput()) {
      if (verbose) qDebug() << "AtomicForm:" << w.widget << "is invalid";
      submitButton->setEnabled(false);
      return;
    }
  }

  if (verbose) qDebug() << "AtomicForm: is valid!";

  submitButton->setEnabled(true);
}
