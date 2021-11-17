#ifndef DESSSER_GEN_sync_server_msg
#define DESSSER_GEN_sync_server_msg
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
struct tf2e49d651ffdc321ab5675abf4b1c554 {
  dessser::gen::sync_key::t_ext SetKey_k;
  double SetKey_mtime;
  std::string SetKey_uid;
  dessser::gen::sync_value::t_ext SetKey_v;
  tf2e49d651ffdc321ab5675abf4b1c554(dessser::gen::sync_key::t_ext SetKey_k_, double SetKey_mtime_, std::string SetKey_uid_, dessser::gen::sync_value::t_ext SetKey_v_) : SetKey_k(SetKey_k_), SetKey_mtime(SetKey_mtime_), SetKey_uid(SetKey_uid_), SetKey_v(SetKey_v_) {}
  tf2e49d651ffdc321ab5675abf4b1c554() = default;
};
inline std::ostream &operator<<(std::ostream &os, tf2e49d651ffdc321ab5675abf4b1c554 const &r) {
  os << '{';
  os << "SetKey_k:" << ::dessser::gen::sync_key::Deref(r.SetKey_k) << ',';
  os << "SetKey_mtime:" << r.SetKey_mtime << ',';
  os << "SetKey_uid:" << r.SetKey_uid << ',';
  os << "SetKey_v:" << ::dessser::gen::sync_value::Deref(r.SetKey_v);
  os << '}';
  return os;
}
inline bool operator==(tf2e49d651ffdc321ab5675abf4b1c554 const &a, tf2e49d651ffdc321ab5675abf4b1c554 const &b) {
  return ::dessser::gen::sync_key::Deref(a.SetKey_k) == ::dessser::gen::sync_key::Deref(b.SetKey_k) && a.SetKey_mtime == b.SetKey_mtime && a.SetKey_uid == b.SetKey_uid && ::dessser::gen::sync_value::Deref(a.SetKey_v) == ::dessser::gen::sync_value::Deref(b.SetKey_v);
}

inline bool operator!=(tf2e49d651ffdc321ab5675abf4b1c554 const &a, tf2e49d651ffdc321ab5675abf4b1c554 const &b) {
  return !operator==(a, b);
}
struct t95feeb4c05fbe296dbc45d08c9a46b94 {
  bool can_del;
  bool can_write;
  double NewKey_expiry;
  dessser::gen::sync_key::t_ext NewKey_k;
  double mtime;
  std::string NewKey_owner;
  std::string uid;
  dessser::gen::sync_value::t_ext v;
  t95feeb4c05fbe296dbc45d08c9a46b94(bool can_del_, bool can_write_, double NewKey_expiry_, dessser::gen::sync_key::t_ext NewKey_k_, double mtime_, std::string NewKey_owner_, std::string uid_, dessser::gen::sync_value::t_ext v_) : can_del(can_del_), can_write(can_write_), NewKey_expiry(NewKey_expiry_), NewKey_k(NewKey_k_), mtime(mtime_), NewKey_owner(NewKey_owner_), uid(uid_), v(v_) {}
  t95feeb4c05fbe296dbc45d08c9a46b94() = default;
};
inline std::ostream &operator<<(std::ostream &os, t95feeb4c05fbe296dbc45d08c9a46b94 const &r) {
  os << '{';
  os << "can_del:" << r.can_del << ',';
  os << "can_write:" << r.can_write << ',';
  os << "NewKey_expiry:" << r.NewKey_expiry << ',';
  os << "NewKey_k:" << ::dessser::gen::sync_key::Deref(r.NewKey_k) << ',';
  os << "mtime:" << r.mtime << ',';
  os << "NewKey_owner:" << r.NewKey_owner << ',';
  os << "uid:" << r.uid << ',';
  os << "v:" << ::dessser::gen::sync_value::Deref(r.v);
  os << '}';
  return os;
}
inline bool operator==(t95feeb4c05fbe296dbc45d08c9a46b94 const &a, t95feeb4c05fbe296dbc45d08c9a46b94 const &b) {
  return a.can_del == b.can_del && a.can_write == b.can_write && a.NewKey_expiry == b.NewKey_expiry && ::dessser::gen::sync_key::Deref(a.NewKey_k) == ::dessser::gen::sync_key::Deref(b.NewKey_k) && a.mtime == b.mtime && a.NewKey_owner == b.NewKey_owner && a.uid == b.uid && ::dessser::gen::sync_value::Deref(a.v) == ::dessser::gen::sync_value::Deref(b.v);
}

inline bool operator!=(t95feeb4c05fbe296dbc45d08c9a46b94 const &a, t95feeb4c05fbe296dbc45d08c9a46b94 const &b) {
  return !operator==(a, b);
}
struct t69cc6731c9f63b8423445eb8919b831d {
  double expiry;
  dessser::gen::sync_key::t_ext k;
  std::string owner;
  t69cc6731c9f63b8423445eb8919b831d(double expiry_, dessser::gen::sync_key::t_ext k_, std::string owner_) : expiry(expiry_), k(k_), owner(owner_) {}
  t69cc6731c9f63b8423445eb8919b831d() = default;
};
inline std::ostream &operator<<(std::ostream &os, t69cc6731c9f63b8423445eb8919b831d const &r) {
  os << '{';
  os << "expiry:" << r.expiry << ',';
  os << "k:" << ::dessser::gen::sync_key::Deref(r.k) << ',';
  os << "owner:" << r.owner;
  os << '}';
  return os;
}
inline bool operator==(t69cc6731c9f63b8423445eb8919b831d const &a, t69cc6731c9f63b8423445eb8919b831d const &b) {
  return a.expiry == b.expiry && ::dessser::gen::sync_key::Deref(a.k) == ::dessser::gen::sync_key::Deref(b.k) && a.owner == b.owner;
}

inline bool operator!=(t69cc6731c9f63b8423445eb8919b831d const &a, t69cc6731c9f63b8423445eb8919b831d const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  dessser::gen::sync_socket::t_ext, // AuthOk
  std::string, // AuthErr
  ::dessser::gen::sync_server_msg::tf2e49d651ffdc321ab5675abf4b1c554, // SetKey
  ::dessser::gen::sync_server_msg::t95feeb4c05fbe296dbc45d08c9a46b94, // NewKey
  dessser::gen::sync_key::t_ext, // DelKey
  ::dessser::gen::sync_server_msg::t69cc6731c9f63b8423445eb8919b831d, // LockKey
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
    case 0: os << "AuthOk " << ::dessser::gen::sync_socket::Deref(std::get<0>(v)); break;
    case 1: os << "AuthErr " << std::get<1>(v); break;
    case 2: os << "SetKey " << std::get<2>(v); break;
    case 3: os << "NewKey " << std::get<3>(v); break;
    case 4: os << "DelKey " << ::dessser::gen::sync_key::Deref(std::get<4>(v)); break;
    case 5: os << "LockKey " << std::get<5>(v); break;
    case 6: os << "UnlockKey " << ::dessser::gen::sync_key::Deref(std::get<6>(v)); break;
  }
  return os;
}

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)); // AuthOk
    case 1: return std::get<1>(a) == std::get<1>(b); // AuthErr
    case 2: return std::get<2>(a) == std::get<2>(b); // SetKey
    case 3: return std::get<3>(a) == std::get<3>(b); // NewKey
    case 4: return ::dessser::gen::sync_key::Deref(std::get<4>(a)) == ::dessser::gen::sync_key::Deref(std::get<4>(b)); // DelKey
    case 5: return std::get<5>(a) == std::get<5>(b); // LockKey
    case 6: return ::dessser::gen::sync_key::Deref(std::get<6>(a)) == ::dessser::gen::sync_key::Deref(std::get<6>(b)); // UnlockKey
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tc82ccaefb251651114fd50a5fd96cfe2 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_server_msg::t> ,
  Pointer
> {
  using tuple::tuple;
  tc82ccaefb251651114fd50a5fd96cfe2(std::tuple<std::shared_ptr<::dessser::gen::sync_server_msg::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_server_msg::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc82ccaefb251651114fd50a5fd96cfe2 const &a, tc82ccaefb251651114fd50a5fd96cfe2 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc82ccaefb251651114fd50a5fd96cfe2 const &a, tc82ccaefb251651114fd50a5fd96cfe2 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc82ccaefb251651114fd50a5fd96cfe2 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_server_msg::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_server_msg::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_server_msg::tc82ccaefb251651114fd50a5fd96cfe2(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
