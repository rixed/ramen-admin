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

}
#endif
