#ifndef KVSTORE_H_210812
#define KVSTORE_H_210812
#include <functional>
#include <memory>
#include <map>
#include <mutex>
#include <set>
#include <sstream>
#include <unordered_map>
#include <QList>
#include <QObject>
#include <QString>

#include "ConfChange.h"
#include "KValue.h"
#include "desssergen/sync_key.h"
#include "rec_shared_mutex.h"

/* For some reason the (better) technique of injecting a hash specialization
 * into the namespace std does not work, so the map is constructed explicitly
 * with this Hash "function": */
struct HashKey {
  std::size_t operator()(std::shared_ptr<dessser::gen::sync_key::t const> k) const noexcept
  {
    // Lazily convert the key to a string then hash this string: (FIXME)
    std::ostringstream str;
    if (k) str << *k;
    else str << "null";
    return std::hash<std::string>{}(str.str());
  }
};

struct EqualKey {
  // Compare the content of the shared pointer rather than the addresses
  bool operator()(std::shared_ptr<dessser::gen::sync_key::t const> const &k1,
                  std::shared_ptr<dessser::gen::sync_key::t const> const &k2) const noexcept
  {
    return (*k1 == *k2);
  }
};

class QTimer;

class KVStore : public QObject
{
  Q_OBJECT

  // Signal key changes every time this timer expires:
  QTimer *signalTimer;

public:
  // The changes waiting to be signaled
  QList<ConfChange> confChanges;
  std::mutex confChangesLock;

  KVStore(QObject *parent = nullptr);

  /* Key to value bindings are stored in a single hashtable, with some additional
   * views maintained for performance reasons.
   * These are actually maintained in sync by ConfClient.
   * All of those data containers are protected by this lock: */
  rec_shared_mutex lock;

  /* Cannot be an ordered map because dessserc does not generate comparators.
   * Protected by [lock]. */
  std::unordered_map<std::shared_ptr<dessser::gen::sync_key::t const>, KValue,
                     HashKey, EqualKey> map;
  /* Also the set of all existing incident identifiers, once for every occurrence
   * for easy deletion. Also protected by [lock]: */
  std::multiset<std::string> incident_ids;
  /* Similarly, a map of dialog identifiers per incident identifiers, also multimap
   * for easy deletion, and also protected by [lock]: */
  std::multimap<std::string, std::string> dialog_ids;
  /* Finally, a multimap of logs identifiers per incident identifiers. */
  std::multimap<std::string, std::shared_ptr<dessser::gen::sync_key::t const>> incident_logs;

  bool contains(std::shared_ptr<dessser::gen::sync_key::t const>);

  std::shared_ptr<dessser::gen::sync_value::t const> get(
    std::shared_ptr<dessser::gen::sync_key::t const>);

  /* Maybe update the set of incident and dialog ids.
   * Must be called with [lock]. */
  void addIncident(std::shared_ptr<dessser::gen::sync_key::t const>);

  void delIncident(std::shared_ptr<dessser::gen::sync_key::t const>);

private slots:
  void signalChanges();

signals:
  // Emitted for any changes (FIXME: rename)
  void keyChanged(QList<ConfChange> const &changes) const;
};

Q_DECLARE_METATYPE(ConfChange);

/* There is a single one, created by main, so that QObjects can connect to it even
 * before connection to confserver is established: */
extern std::shared_ptr<KVStore> kvs;

#endif
