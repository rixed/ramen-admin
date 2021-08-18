#include <QDebug>
#include <QTimer>

#include "KVStore.h"

static bool const verbose { false };

KVStore::KVStore(QObject *parent) : QObject(parent)
{
  signalTimer = new QTimer(this);
  connect(signalTimer, &QTimer::timeout,
          this, QOverload<>::of(&KVStore::signalChanges));
  signalTimer->start(300);
}

void KVStore::signalChanges()
{
  confChangesLock.lock();

  if (confChanges.isEmpty()) {
    confChangesLock.unlock();
    return;
  }

  if (verbose)
    qDebug() << "KVStore: signalChanges:" << confChanges.length() << "changes";

  QList<ConfChange> confChangesCopy { std::move(confChanges) };
  assert(confChanges.isEmpty());
  confChangesLock.unlock();

  emit keyChanged(confChangesCopy);
}

bool KVStore::contains(dessser::gen::sync_key::t const &key)
{
  lock.lock_shared();
  bool const ret(map.find(key) != map.end());
  lock.unlock_shared();
  return ret;
}

std::shared_ptr<dessser::gen::sync_value::t const> KVStore::get(dessser::gen::sync_key::t const &key)
{
  std::shared_ptr<dessser::gen::sync_value::t const> ret;
  lock.lock_shared();
  auto it = map.find(key);
  if (it != map.end()) ret = it->second.val;
  lock.unlock_shared();
  return ret;
}
