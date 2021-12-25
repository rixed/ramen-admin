#include "AtomicWidget.h"

#include <QDebug>
#include <QStackedLayout>

#include "KVStore.h"
#include "misc_dessser.h"

static bool const verbose{false};

AtomicWidget::AtomicWidget(QWidget *parent) : QWidget(parent) {
  connect(kvs.get(), &KVStore::keyChanged, this, &AtomicWidget::onChange);

  layout = new QStackedLayout;
  layout->setObjectName("AtomicStackedLayout");
  setLayout(layout);
}

void AtomicWidget::onChange(QList<ConfChange> const &changes) {
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change{changes.at(i)};
    if (!sameKey(*change.key)) continue;
    switch (change.op) {
      case KeyCreated:
      case KeyChanged:
        setValue(change.kv.val);
        break;
      case KeyDeleted:
        forgetValue(*change.key, change.kv);
        break;
      case KeyLocked:
        lockValue(*change.key, change.kv);
        break;
      case KeyUnlocked:
        unlockValue(*change.key, change.kv);
        break;
    }
  }
}

void AtomicWidget::relayoutWidget(QWidget *w) {
  /* Allows a user to relayout several different widgets, and we will switch
   * between them: */
  int const idx(layout->indexOf(w));
  if (idx >= 0) {
    layout->setCurrentIndex(idx);
  } else {
    layout->addWidget(w);
  }
}

QString AtomicWidget::dbgId() const {
  return QString("AtomicWidget[") +
         (key() ? syncKeyToQString(*key()) : QString("unset")) + QString("]");
}

void AtomicWidget::setKey(
    std::shared_ptr<dessser::gen::sync_key::t const> newKey) {
  if (sameKey(newKey)) return;

  if (verbose)
    qDebug() << dbgId() << ": changing key to"
             << (newKey ? syncKeyToQString(*newKey) : QString("unset"));

  std::shared_ptr<dessser::gen::sync_key::t const> oldKey{key()};
  if (oldKey != newKey) {
    saveKey(newKey);
    Q_ASSERT(sameKey(newKey));  // at least for now
    emit keyChanged(oldKey, newKey);
  }
}

void AtomicWidget::lockValue(dessser::gen::sync_key::t const &,
                             KValue const &kv) {
  setEnabled(my_uid && kv.isMine());
}

/* TODO: Couldn't we have a single lockChange signal, now that both lock
 * and unlock pass a PVPair? */
void AtomicWidget::unlockValue(dessser::gen::sync_key::t const &,
                               KValue const &) {
  setEnabled(false);
}

void AtomicWidget::forgetValue(dessser::gen::sync_key::t const &k,
                               KValue const &) {
  if (verbose) qDebug() << dbgId() << ": forgetValue for key" << k;

  setKey(nullptr);  // should also disable the widget
}

bool AtomicWidget::setValueFromStore() {
  std::shared_ptr<dessser::gen::sync_key::t const> k{key()};
  if (k) {
    bool ok{true};
    kvs->lock.lock_shared();
    auto it = kvs->map.find(k);
    if (it == kvs->map.end()) {
      if (verbose) qDebug() << dbgId() << ": ...is not in the kvs yet";
      setEnabled(false);
    } else {
      ok = setValue(it->second.val);
      if (verbose)
        qDebug() << dbgId() << ": set value to" << *it->second.val
                 << (ok ? " (ok)" : " XXXXXX");
      if (ok) {
        setEnabled(it->second.isMine());
      } else {
        setEnabled(false);
      }
    }
    kvs->lock.unlock_shared();
    return ok;
  } else {
    // or set the value to nullptr?
    setEnabled(false);
    return true;
  }
}
