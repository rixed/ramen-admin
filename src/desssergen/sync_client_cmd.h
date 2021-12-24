#ifndef DESSSER_GEN_sync_client_cmd
#define DESSSER_GEN_sync_client_cmd
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
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_selector.h"
#include "desssergen/sync_user_id.h"

namespace dessser::gen::sync_client_cmd {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t805abd272f99387513a75eaf2be5b195 : public std::tuple<
  dessser::gen::sync_user_id::t_ext,
  double
> {
  using tuple::tuple;
};
inline bool operator==(t805abd272f99387513a75eaf2be5b195 const &a, t805abd272f99387513a75eaf2be5b195 const &b) {
  return ::dessser::gen::sync_user_id::Deref(std::get<0>(a)) == ::dessser::gen::sync_user_id::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t805abd272f99387513a75eaf2be5b195 const &a, t805abd272f99387513a75eaf2be5b195 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t805abd272f99387513a75eaf2be5b195 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t805abd272f99387513a75eaf2be5b195> const t) { os << *t; return os; }

struct ta760ad950ac6e9d5bb8cad673985521b : public std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext
> {
  using tuple::tuple;
};
inline bool operator==(ta760ad950ac6e9d5bb8cad673985521b const &a, ta760ad950ac6e9d5bb8cad673985521b const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && ::dessser::gen::sync_value::Deref(std::get<1>(a)) == ::dessser::gen::sync_value::Deref(std::get<1>(b));
}
inline bool operator!=(ta760ad950ac6e9d5bb8cad673985521b const &a, ta760ad950ac6e9d5bb8cad673985521b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta760ad950ac6e9d5bb8cad673985521b const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta760ad950ac6e9d5bb8cad673985521b> const t) { os << *t; return os; }

struct tb16878f6e292208107ef8273775c68d0 : public std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext,
  double,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(tb16878f6e292208107ef8273775c68d0 const &a, tb16878f6e292208107ef8273775c68d0 const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && ::dessser::gen::sync_value::Deref(std::get<1>(a)) == ::dessser::gen::sync_value::Deref(std::get<1>(b)) && std::get<2>(a) == std::get<2>(b) && std::get<3>(a) == std::get<3>(b);
}
inline bool operator!=(tb16878f6e292208107ef8273775c68d0 const &a, tb16878f6e292208107ef8273775c68d0 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb16878f6e292208107ef8273775c68d0 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tb16878f6e292208107ef8273775c68d0> const t) { os << *t; return os; }

struct t828d44a85b9c48d5ccb39d9b1a51ef22 : public std::tuple<
  dessser::gen::sync_key::t_ext,
  double,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(t828d44a85b9c48d5ccb39d9b1a51ef22 const &a, t828d44a85b9c48d5ccb39d9b1a51ef22 const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t828d44a85b9c48d5ccb39d9b1a51ef22 const &a, t828d44a85b9c48d5ccb39d9b1a51ef22 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t828d44a85b9c48d5ccb39d9b1a51ef22 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t828d44a85b9c48d5ccb39d9b1a51ef22> const t) { os << *t; return os; }

struct t : public std::variant<
  ::dessser::gen::sync_client_cmd::t805abd272f99387513a75eaf2be5b195, // Auth
  dessser::gen::sync_selector::t_ext, // StartSync
  ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b, // SetKey
  ::dessser::gen::sync_client_cmd::tb16878f6e292208107ef8273775c68d0, // NewKey
  ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b, // UpdKey
  dessser::gen::sync_key::t_ext, // DelKey
  ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22, // LockKey
  ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22, // LockOrCreateKey
  dessser::gen::sync_key::t_ext, // UnlockKey
  Void // Bye
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 10 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Auth
    case 1: return ::dessser::gen::sync_selector::Deref(std::get<1>(a)) == ::dessser::gen::sync_selector::Deref(std::get<1>(b)); // StartSync
    case 2: return std::get<2>(a) == std::get<2>(b); // SetKey
    case 3: return std::get<3>(a) == std::get<3>(b); // NewKey
    case 4: return std::get<4>(a) == std::get<4>(b); // UpdKey
    case 5: return ::dessser::gen::sync_key::Deref(std::get<5>(a)) == ::dessser::gen::sync_key::Deref(std::get<5>(b)); // DelKey
    case 6: return std::get<6>(a) == std::get<6>(b); // LockKey
    case 7: return std::get<7>(a) == std::get<7>(b); // LockOrCreateKey
    case 8: return ::dessser::gen::sync_key::Deref(std::get<8>(a)) == ::dessser::gen::sync_key::Deref(std::get<8>(b)); // UnlockKey
    case 9: return std::get<9>(a) == std::get<9>(b); // Bye
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
enum Constr_t {
  Auth,
  StartSync,
  SetKey,
  NewKey,
  UpdKey,
  DelKey,
  LockKey,
  LockOrCreateKey,
  UnlockKey,
  Bye,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Auth " << std::get<0>(v); break;
    case 1: os << "StartSync " << std::get<1>(v); break;
    case 2: os << "SetKey " << std::get<2>(v); break;
    case 3: os << "NewKey " << std::get<3>(v); break;
    case 4: os << "UpdKey " << std::get<4>(v); break;
    case 5: os << "DelKey " << std::get<5>(v); break;
    case 6: os << "LockKey " << std::get<6>(v); break;
    case 7: os << "LockOrCreateKey " << std::get<7>(v); break;
    case 8: os << "UnlockKey " << std::get<8>(v); break;
    case 9: os << "Bye" << std::get<9>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct tad950dfaea2a70b4ad0338105e6948fe : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,
  Pointer
> {
  using tuple::tuple;
  tad950dfaea2a70b4ad0338105e6948fe(std::tuple<std::shared_ptr<::dessser::gen::sync_client_cmd::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_client_cmd::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tad950dfaea2a70b4ad0338105e6948fe const &a, tad950dfaea2a70b4ad0338105e6948fe const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tad950dfaea2a70b4ad0338105e6948fe const &a, tad950dfaea2a70b4ad0338105e6948fe const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tad950dfaea2a70b4ad0338105e6948fe const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tad950dfaea2a70b4ad0338105e6948fe> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_client_cmd::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe(Pointer)> of_row_binary;
extern std::function<::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
