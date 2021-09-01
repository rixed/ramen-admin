#ifndef DESSSER_GEN_sync_server_msg
#define DESSSER_GEN_sync_server_msg
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_socket.h"

namespace dessser::gen::sync_server_msg {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tdede7dcfe50dc5829e84b1a223a9ca56 {
  dessser::gen::sync_key::t_ext SetKey_k;
  double SetKey_mtime;
  std::string SetKey_uid;
  dessser::gen::sync_value::t_ext SetKey_v;
  tdede7dcfe50dc5829e84b1a223a9ca56(dessser::gen::sync_key::t_ext SetKey_k_, double SetKey_mtime_, std::string SetKey_uid_, dessser::gen::sync_value::t_ext SetKey_v_) : SetKey_k(SetKey_k_), SetKey_mtime(SetKey_mtime_), SetKey_uid(SetKey_uid_), SetKey_v(SetKey_v_) {}
  tdede7dcfe50dc5829e84b1a223a9ca56() = default;
  bool operator==(tdede7dcfe50dc5829e84b1a223a9ca56 const &other) const {
    return SetKey_k == other.SetKey_k && SetKey_mtime == other.SetKey_mtime && SetKey_uid == other.SetKey_uid && SetKey_v == other.SetKey_v;
  }
};
inline std::ostream &operator<<(std::ostream &os, tdede7dcfe50dc5829e84b1a223a9ca56 const &r) {
  os << '{';
  os << "SetKey_k:" << r.SetKey_k << ',';
  os << "SetKey_mtime:" << r.SetKey_mtime << ',';
  os << "SetKey_uid:" << r.SetKey_uid << ',';
  os << "SetKey_v:" << r.SetKey_v;
  os << '}';
  return os;
}

struct t3a18f48c3a115a4f3bfc2673fde8256e {
  bool can_del;
  bool can_write;
  double NewKey_expiry;
  dessser::gen::sync_key::t_ext NewKey_k;
  double mtime;
  std::string NewKey_owner;
  std::string uid;
  dessser::gen::sync_value::t_ext v;
  t3a18f48c3a115a4f3bfc2673fde8256e(bool can_del_, bool can_write_, double NewKey_expiry_, dessser::gen::sync_key::t_ext NewKey_k_, double mtime_, std::string NewKey_owner_, std::string uid_, dessser::gen::sync_value::t_ext v_) : can_del(can_del_), can_write(can_write_), NewKey_expiry(NewKey_expiry_), NewKey_k(NewKey_k_), mtime(mtime_), NewKey_owner(NewKey_owner_), uid(uid_), v(v_) {}
  t3a18f48c3a115a4f3bfc2673fde8256e() = default;
  bool operator==(t3a18f48c3a115a4f3bfc2673fde8256e const &other) const {
    return can_del == other.can_del && can_write == other.can_write && NewKey_expiry == other.NewKey_expiry && NewKey_k == other.NewKey_k && mtime == other.mtime && NewKey_owner == other.NewKey_owner && uid == other.uid && v == other.v;
  }
};
inline std::ostream &operator<<(std::ostream &os, t3a18f48c3a115a4f3bfc2673fde8256e const &r) {
  os << '{';
  os << "can_del:" << r.can_del << ',';
  os << "can_write:" << r.can_write << ',';
  os << "NewKey_expiry:" << r.NewKey_expiry << ',';
  os << "NewKey_k:" << r.NewKey_k << ',';
  os << "mtime:" << r.mtime << ',';
  os << "NewKey_owner:" << r.NewKey_owner << ',';
  os << "uid:" << r.uid << ',';
  os << "v:" << r.v;
  os << '}';
  return os;
}

struct t029dea8edf53c9683800a1dd54e0f222 {
  double expiry;
  dessser::gen::sync_key::t_ext k;
  std::string owner;
  t029dea8edf53c9683800a1dd54e0f222(double expiry_, dessser::gen::sync_key::t_ext k_, std::string owner_) : expiry(expiry_), k(k_), owner(owner_) {}
  t029dea8edf53c9683800a1dd54e0f222() = default;
  bool operator==(t029dea8edf53c9683800a1dd54e0f222 const &other) const {
    return expiry == other.expiry && k == other.k && owner == other.owner;
  }
};
inline std::ostream &operator<<(std::ostream &os, t029dea8edf53c9683800a1dd54e0f222 const &r) {
  os << '{';
  os << "expiry:" << r.expiry << ',';
  os << "k:" << r.k << ',';
  os << "owner:" << r.owner;
  os << '}';
  return os;
}

struct t : public std::variant<
  dessser::gen::sync_socket::t_ext, // AuthOk
  std::string, // AuthErr
  ::dessser::gen::sync_server_msg::tdede7dcfe50dc5829e84b1a223a9ca56, // SetKey
  ::dessser::gen::sync_server_msg::t3a18f48c3a115a4f3bfc2673fde8256e, // NewKey
  dessser::gen::sync_key::t_ext, // DelKey
  ::dessser::gen::sync_server_msg::t029dea8edf53c9683800a1dd54e0f222, // LockKey
  dessser::gen::sync_key::t_ext // UnlockKey
> { using variant::variant; };

enum Constr_t {
  AuthOk,
  AuthErr,
  SetKey,
  NewKey,
  DelKey,
  LockKey,
  UnlockKey,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "AuthOk " << std::get<0>(v); break;
    case 1: os << "AuthErr " << std::get<1>(v); break;
    case 2: os << "SetKey " << std::get<2>(v); break;
    case 3: os << "NewKey " << std::get<3>(v); break;
    case 4: os << "DelKey " << std::get<4>(v); break;
    case 5: os << "LockKey " << std::get<5>(v); break;
    case 6: os << "UnlockKey " << std::get<6>(v); break;
  }
  return os;
}

typedef std::tuple<
  ::dessser::gen::sync_server_msg::t*,
  Pointer
> tc6c292a6f74c55e16d68a655860c47c2;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_server_msg::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_server_msg::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_server_msg::tc6c292a6f74c55e16d68a655860c47c2(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
