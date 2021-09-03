#ifndef DESSSER_GEN_sync_client_cmd
#define DESSSER_GEN_sync_client_cmd
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
typedef std::tuple<
  dessser::gen::sync_user_id::t_ext,
  double
> td17298225a9b57dc7469fe7682403a40;

typedef std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext
> t08ff092200f210c10792e73a746a4bfd;

struct tfc0555375d80915de4624dcd8c201c5f : public std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext,
  double,
  bool
> { using tuple::tuple; };
inline bool operator==(tfc0555375d80915de4624dcd8c201c5f const &a, tfc0555375d80915de4624dcd8c201c5f const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && ::dessser::gen::sync_value::Deref(std::get<1>(a)) == ::dessser::gen::sync_value::Deref(std::get<1>(b)) && std::get<2>(a) == std::get<2>(b) && std::get<3>(a) == std::get<3>(b);
}
inline bool operator!=(tfc0555375d80915de4624dcd8c201c5f const &a, tfc0555375d80915de4624dcd8c201c5f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tfc0555375d80915de4624dcd8c201c5f const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct t81abd9e69301921b46b0f740c15d406c : public std::tuple<
  dessser::gen::sync_key::t_ext,
  double,
  bool
> { using tuple::tuple; };
inline bool operator==(t81abd9e69301921b46b0f740c15d406c const &a, t81abd9e69301921b46b0f740c15d406c const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t81abd9e69301921b46b0f740c15d406c const &a, t81abd9e69301921b46b0f740c15d406c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t81abd9e69301921b46b0f740c15d406c const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t : public std::variant<
  ::dessser::gen::sync_client_cmd::td17298225a9b57dc7469fe7682403a40, // Auth
  dessser::gen::sync_selector::t_ext, // StartSync
  ::dessser::gen::sync_client_cmd::t08ff092200f210c10792e73a746a4bfd, // SetKey
  ::dessser::gen::sync_client_cmd::tfc0555375d80915de4624dcd8c201c5f, // NewKey
  ::dessser::gen::sync_client_cmd::t08ff092200f210c10792e73a746a4bfd, // UpdKey
  dessser::gen::sync_key::t_ext, // DelKey
  ::dessser::gen::sync_client_cmd::t81abd9e69301921b46b0f740c15d406c, // LockKey
  ::dessser::gen::sync_client_cmd::t81abd9e69301921b46b0f740c15d406c, // LockOrCreateKey
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

typedef std::tuple<
  ::dessser::gen::sync_client_cmd::t*,
  Pointer
> t00ab01b091bd44a04eff4657d2007412;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_client_cmd::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_client_cmd::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_client_cmd::t00ab01b091bd44a04eff4657d2007412(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
