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
struct t76a4eace0515e74e2f7158564887d6e2 : public std::tuple<
  dessser::gen::sync_user_id::t_ext,
  double
> {
  using tuple::tuple;
  t76a4eace0515e74e2f7158564887d6e2(std::tuple<dessser::gen::sync_user_id::t_ext, double> p)
    : std::tuple<dessser::gen::sync_user_id::t_ext, double>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t76a4eace0515e74e2f7158564887d6e2 const &a, t76a4eace0515e74e2f7158564887d6e2 const &b) {
  return ::dessser::gen::sync_user_id::Deref(std::get<0>(a)) == ::dessser::gen::sync_user_id::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t76a4eace0515e74e2f7158564887d6e2 const &a, t76a4eace0515e74e2f7158564887d6e2 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t76a4eace0515e74e2f7158564887d6e2 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t3d86b821c5091c6f135e0807d7d824a9 : public std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext
> {
  using tuple::tuple;
  t3d86b821c5091c6f135e0807d7d824a9(std::tuple<dessser::gen::sync_key::t_ext, dessser::gen::sync_value::t_ext> p)
    : std::tuple<dessser::gen::sync_key::t_ext, dessser::gen::sync_value::t_ext>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3d86b821c5091c6f135e0807d7d824a9 const &a, t3d86b821c5091c6f135e0807d7d824a9 const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && ::dessser::gen::sync_value::Deref(std::get<1>(a)) == ::dessser::gen::sync_value::Deref(std::get<1>(b));
}
inline bool operator!=(t3d86b821c5091c6f135e0807d7d824a9 const &a, t3d86b821c5091c6f135e0807d7d824a9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t3d86b821c5091c6f135e0807d7d824a9 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t4e5b196a7c2c025698938503da55021a : public std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext,
  double,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(t4e5b196a7c2c025698938503da55021a const &a, t4e5b196a7c2c025698938503da55021a const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && ::dessser::gen::sync_value::Deref(std::get<1>(a)) == ::dessser::gen::sync_value::Deref(std::get<1>(b)) && std::get<2>(a) == std::get<2>(b) && std::get<3>(a) == std::get<3>(b);
}
inline bool operator!=(t4e5b196a7c2c025698938503da55021a const &a, t4e5b196a7c2c025698938503da55021a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4e5b196a7c2c025698938503da55021a const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct tdc1bba9eed6e3f46c2e7e4e1c60d94bc : public std::tuple<
  dessser::gen::sync_key::t_ext,
  double,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(tdc1bba9eed6e3f46c2e7e4e1c60d94bc const &a, tdc1bba9eed6e3f46c2e7e4e1c60d94bc const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(tdc1bba9eed6e3f46c2e7e4e1c60d94bc const &a, tdc1bba9eed6e3f46c2e7e4e1c60d94bc const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tdc1bba9eed6e3f46c2e7e4e1c60d94bc const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t : public std::variant<
  ::dessser::gen::sync_client_cmd::t76a4eace0515e74e2f7158564887d6e2, // Auth
  dessser::gen::sync_selector::t_ext, // StartSync
  ::dessser::gen::sync_client_cmd::t3d86b821c5091c6f135e0807d7d824a9, // SetKey
  ::dessser::gen::sync_client_cmd::t4e5b196a7c2c025698938503da55021a, // NewKey
  ::dessser::gen::sync_client_cmd::t3d86b821c5091c6f135e0807d7d824a9, // UpdKey
  dessser::gen::sync_key::t_ext, // DelKey
  ::dessser::gen::sync_client_cmd::tdc1bba9eed6e3f46c2e7e4e1c60d94bc, // LockKey
  ::dessser::gen::sync_client_cmd::tdc1bba9eed6e3f46c2e7e4e1c60d94bc, // LockOrCreateKey
  dessser::gen::sync_key::t_ext, // UnlockKey
  Void // Bye
> { using variant::variant; };

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
    case 1: os << "StartSync " << ::dessser::gen::sync_selector::Deref(std::get<1>(v)); break;
    case 2: os << "SetKey " << std::get<2>(v); break;
    case 3: os << "NewKey " << std::get<3>(v); break;
    case 4: os << "UpdKey " << std::get<4>(v); break;
    case 5: os << "DelKey " << ::dessser::gen::sync_key::Deref(std::get<5>(v)); break;
    case 6: os << "LockKey " << std::get<6>(v); break;
    case 7: os << "LockOrCreateKey " << std::get<7>(v); break;
    case 8: os << "UnlockKey " << ::dessser::gen::sync_key::Deref(std::get<8>(v)); break;
    case 9: os << "Bye " << std::get<9>(v); break;
  }
  return os;
}

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
struct tfd5814032c8587486ba8d32ccdd5b703 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,
  Pointer
> {
  using tuple::tuple;
  tfd5814032c8587486ba8d32ccdd5b703(std::tuple<std::shared_ptr<::dessser::gen::sync_client_cmd::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_client_cmd::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tfd5814032c8587486ba8d32ccdd5b703 const &a, tfd5814032c8587486ba8d32ccdd5b703 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tfd5814032c8587486ba8d32ccdd5b703 const &a, tfd5814032c8587486ba8d32ccdd5b703 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tfd5814032c8587486ba8d32ccdd5b703 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_client_cmd::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_client_cmd::tfd5814032c8587486ba8d32ccdd5b703(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
