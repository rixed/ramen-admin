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
struct t5164a104e605b6dce54d0f57d22a5894 {
  dessser::gen::sync_key::t_ext SetKey_k;
  double SetKey_mtime;
  std::string SetKey_uid;
  dessser::gen::sync_value::t_ext SetKey_v;
  bool operator==(t5164a104e605b6dce54d0f57d22a5894 const &other) const {
    return SetKey_k == other.SetKey_k && SetKey_mtime == other.SetKey_mtime && SetKey_uid == other.SetKey_uid && SetKey_v == other.SetKey_v;
  }
};
inline std::ostream &operator<<(std::ostream &os, t5164a104e605b6dce54d0f57d22a5894 const &r) {
  os << '{';
  os << "SetKey_k:" << r.SetKey_k << ',';
  os << "SetKey_mtime:" << r.SetKey_mtime << ',';
  os << "SetKey_uid:" << r.SetKey_uid << ',';
  os << "SetKey_v:" << r.SetKey_v;
  os << '}';
  return os;
}

struct td7f54760c6b35c56c79efedd08574240 {
  bool can_del;
  bool can_write;
  double NewKey_expiry;
  dessser::gen::sync_key::t_ext NewKey_k;
  double mtime;
  std::string NewKey_owner;
  std::string uid;
  dessser::gen::sync_value::t_ext v;
  bool operator==(td7f54760c6b35c56c79efedd08574240 const &other) const {
    return can_del == other.can_del && can_write == other.can_write && NewKey_expiry == other.NewKey_expiry && NewKey_k == other.NewKey_k && mtime == other.mtime && NewKey_owner == other.NewKey_owner && uid == other.uid && v == other.v;
  }
};
inline std::ostream &operator<<(std::ostream &os, td7f54760c6b35c56c79efedd08574240 const &r) {
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

struct ta33518bab5ce39f29507a4782b59d374 {
  double expiry;
  dessser::gen::sync_key::t_ext k;
  std::string owner;
  bool operator==(ta33518bab5ce39f29507a4782b59d374 const &other) const {
    return expiry == other.expiry && k == other.k && owner == other.owner;
  }
};
inline std::ostream &operator<<(std::ostream &os, ta33518bab5ce39f29507a4782b59d374 const &r) {
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
  ::dessser::gen::sync_server_msg::t5164a104e605b6dce54d0f57d22a5894, // SetKey
  ::dessser::gen::sync_server_msg::td7f54760c6b35c56c79efedd08574240, // NewKey
  dessser::gen::sync_key::t_ext, // DelKey
  ::dessser::gen::sync_server_msg::ta33518bab5ce39f29507a4782b59d374, // LockKey
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
