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
  double SetKey_mtime;
  std::string SetKey_uid;
  dessser::gen::sync_value::t_ext SetKey_v;
  t3f973b24e2e9a1d94d78f692da2d8ddd(dessser::gen::sync_key::t_ext SetKey_k_, double SetKey_mtime_, std::string SetKey_uid_, dessser::gen::sync_value::t_ext SetKey_v_) : SetKey_k(SetKey_k_), SetKey_mtime(SetKey_mtime_), SetKey_uid(SetKey_uid_), SetKey_v(SetKey_v_) {}
  t3f973b24e2e9a1d94d78f692da2d8ddd() = default;
};
inline bool operator==(t3f973b24e2e9a1d94d78f692da2d8ddd const &a, t3f973b24e2e9a1d94d78f692da2d8ddd const &b) {
  return ::dessser::gen::sync_key::Deref(a.SetKey_k) == ::dessser::gen::sync_key::Deref(b.SetKey_k) && a.SetKey_mtime == b.SetKey_mtime && a.SetKey_uid == b.SetKey_uid && ::dessser::gen::sync_value::Deref(a.SetKey_v) == ::dessser::gen::sync_value::Deref(b.SetKey_v);
}

inline bool operator!=(t3f973b24e2e9a1d94d78f692da2d8ddd const &a, t3f973b24e2e9a1d94d78f692da2d8ddd const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t3f973b24e2e9a1d94d78f692da2d8ddd const &r) {
  os << '{';
  os << "SetKey_k:" << r.SetKey_k << ',';
  os << "SetKey_mtime:" << r.SetKey_mtime << ',';
  os << "SetKey_uid:" << r.SetKey_uid << ',';
  os << "SetKey_v:" << r.SetKey_v;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t3f973b24e2e9a1d94d78f692da2d8ddd> const r) { os << *r; return os; }

struct t913da46d44b49d8b22bdcc9cc9e78fc1 {
  bool can_del;
  bool can_write;
  double NewKey_expiry;
  dessser::gen::sync_key::t_ext NewKey_k;
  double mtime;
  std::string NewKey_owner;
  std::string uid;
  dessser::gen::sync_value::t_ext v;
  t913da46d44b49d8b22bdcc9cc9e78fc1(bool can_del_, bool can_write_, double NewKey_expiry_, dessser::gen::sync_key::t_ext NewKey_k_, double mtime_, std::string NewKey_owner_, std::string uid_, dessser::gen::sync_value::t_ext v_) : can_del(can_del_), can_write(can_write_), NewKey_expiry(NewKey_expiry_), NewKey_k(NewKey_k_), mtime(mtime_), NewKey_owner(NewKey_owner_), uid(uid_), v(v_) {}
  t913da46d44b49d8b22bdcc9cc9e78fc1() = default;
};
inline bool operator==(t913da46d44b49d8b22bdcc9cc9e78fc1 const &a, t913da46d44b49d8b22bdcc9cc9e78fc1 const &b) {
  return a.can_del == b.can_del && a.can_write == b.can_write && a.NewKey_expiry == b.NewKey_expiry && ::dessser::gen::sync_key::Deref(a.NewKey_k) == ::dessser::gen::sync_key::Deref(b.NewKey_k) && a.mtime == b.mtime && a.NewKey_owner == b.NewKey_owner && a.uid == b.uid && ::dessser::gen::sync_value::Deref(a.v) == ::dessser::gen::sync_value::Deref(b.v);
}

inline bool operator!=(t913da46d44b49d8b22bdcc9cc9e78fc1 const &a, t913da46d44b49d8b22bdcc9cc9e78fc1 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t913da46d44b49d8b22bdcc9cc9e78fc1 const &r) {
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
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t913da46d44b49d8b22bdcc9cc9e78fc1> const r) { os << *r; return os; }

struct t675a4fdd830ddedd7d9ba746180c033f {
  double expiry;
  dessser::gen::sync_key::t_ext k;
  std::string owner;
  t675a4fdd830ddedd7d9ba746180c033f(double expiry_, dessser::gen::sync_key::t_ext k_, std::string owner_) : expiry(expiry_), k(k_), owner(owner_) {}
  t675a4fdd830ddedd7d9ba746180c033f() = default;
};
inline bool operator==(t675a4fdd830ddedd7d9ba746180c033f const &a, t675a4fdd830ddedd7d9ba746180c033f const &b) {
  return a.expiry == b.expiry && ::dessser::gen::sync_key::Deref(a.k) == ::dessser::gen::sync_key::Deref(b.k) && a.owner == b.owner;
}

inline bool operator!=(t675a4fdd830ddedd7d9ba746180c033f const &a, t675a4fdd830ddedd7d9ba746180c033f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t675a4fdd830ddedd7d9ba746180c033f const &r) {
  os << '{';
  os << "expiry:" << r.expiry << ',';
  os << "k:" << r.k << ',';
  os << "owner:" << r.owner;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t675a4fdd830ddedd7d9ba746180c033f> const r) { os << *r; return os; }

struct t : public std::variant<
  dessser::gen::sync_socket::t_ext, // AuthOk
  std::string, // AuthErr
  ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd, // SetKey
  ::dessser::gen::sync_server_msg::t913da46d44b49d8b22bdcc9cc9e78fc1, // NewKey
  dessser::gen::sync_key::t_ext, // DelKey
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
    case 4: return ::dessser::gen::sync_key::Deref(std::get<4>(a)) == ::dessser::gen::sync_key::Deref(std::get<4>(b)); // DelKey
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
