#include <QDebug>
#include <QStackedLayout>

#include "KVStore.h"
#include "misc_dessser.h"

#include "AtomicWidget.h"

static bool const verbose { false };

AtomicWidget::AtomicWidget(QWidget *parent) :
  QWidget(parent)
{
  connect(kvs.get(), &KVStore::keyChanged,
          this, &AtomicWidget::onChange);

  layout = new QStackedLayout;
  layout->setObjectName("AtomicStackedLayout");
  setLayout(layout);
}

void AtomicWidget::onChange(QList<ConfChange> const &changes)
{
  for (int i = 0; i < changes.length(); i++) {
    ConfChange const &change { changes.at(i) };
    switch (change.op) {
      case KeyCreated:
      case KeyChanged:
        setValueFromStore(change.key, change.kv);
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

void AtomicWidget::relayoutWidget(QWidget *w)
{
  /* Allows a user to relayout several different widgets, and we will switch
   * between them: */
  int const idx(layout->indexOf(w));
  if (idx >= 0) {
    layout->setCurrentIndex(idx);
  } else {
    layout->addWidget(w);
  }
}

QString AtomicWidget::dbgId() const
{
  return QString("AtomicWidget[") +
         (key() ? syncKeyToQString(*key()) : QString("unset")) +
         QString("]");
}

bool AtomicWidget::setKey(std::shared_ptr<dessser::gen::sync_key::t const> newKey)
{
  if (sameKey(newKey)) return true;

  if (verbose)
    qDebug() << dbgId() << ": changing key to"
             << (newKey ? syncKeyToQString(*newKey) : QString("unset"));

  std::shared_ptr<dessser::gen::sync_key::t const> oldKey { key() };
  saveKey(newKey);
  Q_ASSERT(sameKey(newKey));  // at least for now

  bool ok { true };

  if (newKey) {
    kvs->lock.lock_shared();
    auto it = kvs->map.find(newKey);
    if (it == kvs->map.end()) {
      if (verbose)
        qDebug() << dbgId() << ": ...which is not in the kvs yet";
      setEnabled(false);
    } else {
      ok = setValue(it->first, it->second.val);
      if (verbose)
        qDebug() << dbgId() << ": set value to" << *it->second.val << (ok ? " (ok)":" XXXXXX");
      if (ok) {
        setEnabled(it->second.isMine());
      } else {
        setEnabled(false);
      }
    }
    kvs->lock.unlock_shared();
  } else {
    // or set the value to nullptr?
    setEnabled(false);
    return true;
  }

  if (ok) emit keyChanged(oldKey, newKey);

  return ok;
}

void AtomicWidget::lockValue(dessser::gen::sync_key::t const &k, KValue const &kv)
{
  if (! sameKey(k)) return;

  setEnabled(my_uid && kv.isMine());
}

/* TODO: Couldn't we have a single lockChange signal, now that both lock
 * and unlock pass a PVPair? */
void AtomicWidget::unlockValue(dessser::gen::sync_key::t const &k, KValue const &)
{
  if (! sameKey(k)) return;

  setEnabled(false);
}

void AtomicWidget::forgetValue(dessser::gen::sync_key::t const &k, KValue const &)
{
  if (! sameKey(k)) return;

  if (verbose)
    qDebug() << dbgId() << ": forgetValue for key" << k;

  setKey(nullptr); // should also disable the widget
}

void AtomicWidget::setValueFromStore(
  std::shared_ptr<dessser::gen::sync_key::t const> k, KValue const &kv)
{
  Q_ASSERT(k);
  if (! sameKey(*k)) return;

  setValue(k, kv.val);
}
