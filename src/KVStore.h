#ifndef KVSTORE_H_210812
#define KVSTORE_H_210812
#include <functional>
#include <memory>
#include <mutex>
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
  std::size_t operator()(dessser::gen::sync_key::t const &k) const noexcept
  {
    // Lazily convert the key to a string then hash this string:
    std::ostringstream str;
    str << k;
    return std::hash<std::string>{}(str.str());
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

  std::unordered_map<dessser::gen::sync_key::t const, KValue, HashKey> map;
  rec_shared_mutex lock;

  bool contains(dessser::gen::sync_key::t const &);
  std::shared_ptr<dessser::gen::sync_value::t const> get(dessser::gen::sync_key::t const &);

private slots:
  void signalChanges();

signals:
  void keyChanged(QList<ConfChange> const &changes) const;
};

Q_DECLARE_METATYPE(ConfChange);

/* There is a single one, created by main, so that QObjects can connect to it even
 * before connection to confserver is established: */
extern std::shared_ptr<KVStore> kvs;

#endif
