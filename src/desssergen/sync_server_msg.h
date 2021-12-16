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
struct t3f973b24e2e9a1d94d78f692da2d8ddd {
  dessser::gen::sync_key::t_ext SetKey_k;
  dessser::gen::sync_value::t_ext SetKey_v;
  std::string SetKey_uid;
  double SetKey_mtime;
  t3f973b24e2e9a1d94d78f692da2d8ddd(dessser::gen::sync_key::t_ext SetKey_k_, dessser::gen::sync_value::t_ext SetKey_v_, std::string SetKey_uid_, double SetKey_mtime_) : SetKey_k(SetKey_k_), SetKey_v(SetKey_v_), SetKey_uid(SetKey_uid_), SetKey_mtime(SetKey_mtime_) {}
  t3f973b24e2e9a1d94d78f692da2d8ddd() = default;
};
inline bool operator==(t3f973b24e2e9a1d94d78f692da2d8ddd const &a, t3f973b24e2e9a1d94d78f692da2d8ddd const &b) {
  return ::dessser::gen::sync_key::Deref(a.SetKey_k) == ::dessser::gen::sync_key::Deref(b.SetKey_k) && ::dessser::gen::sync_value::Deref(a.SetKey_v) == ::dessser::gen::sync_value::Deref(b.SetKey_v) && a.SetKey_uid == b.SetKey_uid && a.SetKey_mtime == b.SetKey_mtime;
}

inline bool operator!=(t3f973b24e2e9a1d94d78f692da2d8ddd const &a, t3f973b24e2e9a1d94d78f692da2d8ddd const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t3f973b24e2e9a1d94d78f692da2d8ddd const &r) {
  os << '{';
  os << "SetKey_k:" << r.SetKey_k << ',';
  os << "SetKey_v:" << r.SetKey_v << ',';
  os << "SetKey_uid:" << r.SetKey_uid << ',';
  os << "SetKey_mtime:" << r.SetKey_mtime;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t3f973b24e2e9a1d94d78f692da2d8ddd> const r) { os << *r; return os; }

struct td4227ac047ed98f74e1d279b847d611e {
  dessser::gen::sync_key::t_ext NewKey_k;
  dessser::gen::sync_value::t_ext v;
  std::string NewKey_uid;
  double mtime;
  bool can_write;
  bool can_del;
  std::string NewKey_owner;
  double NewKey_expiry;
  td4227ac047ed98f74e1d279b847d611e(dessser::gen::sync_key::t_ext NewKey_k_, dessser::gen::sync_value::t_ext v_, std::string NewKey_uid_, double mtime_, bool can_write_, bool can_del_, std::string NewKey_owner_, double NewKey_expiry_) : NewKey_k(NewKey_k_), v(v_), NewKey_uid(NewKey_uid_), mtime(mtime_), can_write(can_write_), can_del(can_del_), NewKey_owner(NewKey_owner_), NewKey_expiry(NewKey_expiry_) {}
  td4227ac047ed98f74e1d279b847d611e() = default;
};
inline bool operator==(td4227ac047ed98f74e1d279b847d611e const &a, td4227ac047ed98f74e1d279b847d611e const &b) {
  return ::dessser::gen::sync_key::Deref(a.NewKey_k) == ::dessser::gen::sync_key::Deref(b.NewKey_k) && ::dessser::gen::sync_value::Deref(a.v) == ::dessser::gen::sync_value::Deref(b.v) && a.NewKey_uid == b.NewKey_uid && a.mtime == b.mtime && a.can_write == b.can_write && a.can_del == b.can_del && a.NewKey_owner == b.NewKey_owner && a.NewKey_expiry == b.NewKey_expiry;
}

inline bool operator!=(td4227ac047ed98f74e1d279b847d611e const &a, td4227ac047ed98f74e1d279b847d611e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td4227ac047ed98f74e1d279b847d611e const &r) {
  os << '{';
  os << "NewKey_k:" << r.NewKey_k << ',';
  os << "v:" << r.v << ',';
  os << "NewKey_uid:" << r.NewKey_uid << ',';
  os << "mtime:" << r.mtime << ',';
  os << "can_write:" << r.can_write << ',';
  os << "can_del:" << r.can_del << ',';
  os << "NewKey_owner:" << r.NewKey_owner << ',';
  os << "NewKey_expiry:" << r.NewKey_expiry;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td4227ac047ed98f74e1d279b847d611e> const r) { os << *r; return os; }

struct t08b27b0be3a89631db1d9e270c1e83bc {
  dessser::gen::sync_key::t_ext DelKey_k;
  std::string uid;
  t08b27b0be3a89631db1d9e270c1e83bc(dessser::gen::sync_key::t_ext DelKey_k_, std::string uid_) : DelKey_k(DelKey_k_), uid(uid_) {}
  t08b27b0be3a89631db1d9e270c1e83bc() = default;
};
inline bool operator==(t08b27b0be3a89631db1d9e270c1e83bc const &a, t08b27b0be3a89631db1d9e270c1e83bc const &b) {
  return ::dessser::gen::sync_key::Deref(a.DelKey_k) == ::dessser::gen::sync_key::Deref(b.DelKey_k) && a.uid == b.uid;
}

inline bool operator!=(t08b27b0be3a89631db1d9e270c1e83bc const &a, t08b27b0be3a89631db1d9e270c1e83bc const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t08b27b0be3a89631db1d9e270c1e83bc const &r) {
  os << '{';
  os << "DelKey_k:" << r.DelKey_k << ',';
  os << "uid:" << r.uid;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t08b27b0be3a89631db1d9e270c1e83bc> const r) { os << *r; return os; }

struct t675a4fdd830ddedd7d9ba746180c033f {
  dessser::gen::sync_key::t_ext k;
  std::string owner;
  double expiry;
  t675a4fdd830ddedd7d9ba746180c033f(dessser::gen::sync_key::t_ext k_, std::string owner_, double expiry_) : k(k_), owner(owner_), expiry(expiry_) {}
  t675a4fdd830ddedd7d9ba746180c033f() = default;
};
inline bool operator==(t675a4fdd830ddedd7d9ba746180c033f const &a, t675a4fdd830ddedd7d9ba746180c033f const &b) {
  return ::dessser::gen::sync_key::Deref(a.k) == ::dessser::gen::sync_key::Deref(b.k) && a.owner == b.owner && a.expiry == b.expiry;
}

inline bool operator!=(t675a4fdd830ddedd7d9ba746180c033f const &a, t675a4fdd830ddedd7d9ba746180c033f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t675a4fdd830ddedd7d9ba746180c033f const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "owner:" << r.owner << ',';
  os << "expiry:" << r.expiry;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t675a4fdd830ddedd7d9ba746180c033f> const r) { os << *r; return os; }

struct t : public std::variant<
  dessser::gen::sync_socket::t_ext, // AuthOk
  std::string, // AuthErr
  ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd, // SetKey
  ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e, // NewKey
  ::dessser::gen::sync_server_msg::t08b27b0be3a89631db1d9e270c1e83bc, // DelKey
  ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f, // LockKey
  dessser::gen::sync_key::t_ext // UnlockKey
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 7 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)); // AuthOk
    case 1: return std::get<1>(a) == std::get<1>(b); // AuthErr
    case 2: return std::get<2>(a) == std::get<2>(b); // SetKey
    case 3: return std::get<3>(a) == std::get<3>(b); // NewKey
    case 4: return std::get<4>(a) == std::get<4>(b); // DelKey
    case 5: return std::get<5>(a) == std::get<5>(b); // LockKey
    case 6: return ::dessser::gen::sync_key::Deref(std::get<6>(a)) == ::dessser::gen::sync_key::Deref(std::get<6>(b)); // UnlockKey
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t74e78fed6c064ccc52152cfa38842dd1 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_server_msg::t> ,
  Pointer
> {
  using tuple::tuple;
  t74e78fed6c064ccc52152cfa38842dd1(std::tuple<std::shared_ptr<::dessser::gen::sync_server_msg::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_server_msg::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t74e78fed6c064ccc52152cfa38842dd1 const &a, t74e78fed6c064ccc52152cfa38842dd1 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t74e78fed6c064ccc52152cfa38842dd1 const &a, t74e78fed6c064ccc52152cfa38842dd1 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t74e78fed6c064ccc52152cfa38842dd1 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t74e78fed6c064ccc52152cfa38842dd1> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_server_msg::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_server_msg::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1(Pointer)> of_row_binary;
extern std::function<::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_server_msg::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
