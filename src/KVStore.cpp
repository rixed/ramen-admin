// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "KVStore.h"

#include <QDebug>
#include <QTimer>

static constexpr bool verbose{false};

std::shared_ptr<KVStore> kvs;

KVStore::KVStore(QObject *parent) : QObject(parent) {
  signalTimer = new QTimer(this);
  connect(signalTimer, &QTimer::timeout, this,
          QOverload<>::of(&KVStore::signalChanges));
  signalTimer->start(300);
}

void KVStore::signalChanges() {
  confChangesLock.lock();

  if (confChanges.isEmpty()) {
    confChangesLock.unlock();
    return;
  }

  if (verbose)
    qDebug() << "KVStore: signalChanges:" << confChanges.length() << "changes";

  QList<ConfChange> confChangesCopy{std::move(confChanges)};
  Q_ASSERT(confChanges.isEmpty());
  confChangesLock.unlock();

  emit keyChanged(confChangesCopy);
}

bool KVStore::contains(std::shared_ptr<dessser::gen::sync_key::t const> key) {
  lock.lock_shared();
  bool const ret{map.find(key) != map.end()};
  lock.unlock_shared();
  return ret;
}

std::shared_ptr<dessser::gen::sync_value::t const> KVStore::get(
    std::shared_ptr<dessser::gen::sync_key::t const> key) {
  std::shared_ptr<dessser::gen::sync_value::t const> ret;
  lock.lock_shared();
  auto it{map.find(std::shared_ptr<dessser::gen::sync_key::t const>(key))};
  if (it != map.end()) ret = it->second.val;
  lock.unlock_shared();
  return ret;
}

void KVStore::addIncident(std::shared_ptr<dessser::gen::sync_key::t const> k) {
  if (k->index() != dessser::gen::sync_key::Incidents) return;

  std::string const &incident_id{
      std::get<0>(std::get<dessser::gen::sync_key::Incidents>(*k))};
  incident_ids.insert(incident_id);
  /* Maybe also update the set of dialog ids: */
  dessser::gen::sync_key::incident_key const &incident_key{
      std::get<1>(std::get<dessser::gen::sync_key::Incidents>(*k))};
  if (incident_key.index() == dessser::gen::sync_key::Dialogs) {
    std::string const &dialog_id{
        std::get<0>(std::get<dessser::gen::sync_key::Dialogs>(incident_key))};
    dialog_ids.insert(std::make_pair(incident_id, dialog_id));
  } else if (incident_key.index() == dessser::gen::sync_key::Journal) {
    incident_logs.insert(std::make_pair(incident_id, k));
  }
}

void KVStore::delIncident(std::shared_ptr<dessser::gen::sync_key::t const> k) {
  if (k->index() != dessser::gen::sync_key::Incidents) return;

  std::string const &incident_id{
      std::get<0>(std::get<dessser::gen::sync_key::Incidents>(*k))};
  // Find the first occurrence and deletes it:
  auto it{incident_ids.find(incident_id)};
  Q_ASSERT(it != incident_ids.end());
  incident_ids.erase(it);

  /* Maybe also deletes a dialog: */
  dessser::gen::sync_key::incident_key const &incident_key{
      std::get<1>(std::get<dessser::gen::sync_key::Incidents>(*k))};
  if (incident_key.index() == dessser::gen::sync_key::Dialogs) {
    std::string const &dialog_id{
        std::get<0>(std::get<dessser::gen::sync_key::Dialogs>(incident_key))};
    // Remove again the first occurrence:
    bool deleted{false};
    auto range{dialog_ids.equal_range(incident_id)};
    for (auto it = range.first; it != range.second; ++it) {
      std::string const &this_incident_id{it->first};
      Q_ASSERT(this_incident_id == incident_id);
      std::string const &this_dialog_id{it->second};
      if (this_dialog_id == dialog_id) {
        dialog_ids.erase(it);
        deleted = true;
        break;
      }
    }
    Q_ASSERT(deleted);
  } else if (incident_key.index() == dessser::gen::sync_key::Journal) {
    bool deleted{false};
    auto range{incident_logs.equal_range(incident_id)};
    for (auto it = range.first; it != range.second; ++it) {
      std::string const &this_incident_id{it->first};
      Q_ASSERT(this_incident_id == incident_id);
      if (k.get() == it->second.get()) {
        Q_ASSERT(!deleted);
        incident_logs.erase(it);
        deleted = true;
#ifndef QT_DEBUG
        break;
#endif
      }
    }
    Q_ASSERT(deleted);
  }
}
