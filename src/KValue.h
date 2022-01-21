// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef KVALUE_H_190506
#define KVALUE_H_190506
#include <QString>
#include <memory>
#include <optional>
#include <string>

#include "UserIdentity.h"

namespace dessser {
namespace gen {
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

struct KValue {
  std::shared_ptr<dessser::gen::sync_value::t const> val;
  QString uid;  // Of the user who has set this value
  double mtime;
  QString owner;  // Empty for no locker
  double expiry;  // if owner above is set
  bool can_write, can_del;

  KValue(std::shared_ptr<dessser::gen::sync_value::t const> v, QString const &u,
         double mt, bool cw, bool cd)
      : val(v), uid(u), mtime(mt), expiry(0.), can_write(cw), can_del(cd) {}

  KValue() : mtime(0.), expiry(0.), can_write(false), can_del(false) {}

  void set(std::shared_ptr<dessser::gen::sync_value::t const> v,
           QString const &u, double mt) {
    val = v;
    uid = u;
    mtime = mt;
  }

  void setLock(QString const &o, double ex) {
    if (o.isEmpty()) qCritical("Setting a lock to empty username");
    owner = o;
    expiry = ex;
  }

  void setUnlock() {
    if (owner.isEmpty()) qCritical("Unlocking an unlocked value");
    owner.clear();
  }

  bool isLocked() const { return !owner.isEmpty(); }

  bool isMine() const { return owner == my_uid; }
};

Q_DECLARE_METATYPE(KValue);

#endif
