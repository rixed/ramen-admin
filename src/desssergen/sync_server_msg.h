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
struct tdf5c8f0315e72acddb131eb06c27ddd0 {
  dessser::gen::sync_key::t_ext k;
  double mtime;
  std::string uid;
  dessser::gen::sync_value::t_ext v;
  bool operator==(tdf5c8f0315e72acddb131eb06c27ddd0 const &other) const {
    return k == other.k && mtime == other.mtime && uid == other.uid && v == other.v;
  }
};
inline std::ostream &operator<<(std::ostream &os, tdf5c8f0315e72acddb131eb06c27ddd0 const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "mtime:" << r.mtime << ',';
  os << "uid:" << r.uid << ',';
  os << "v:" << r.v;
  os << '}';
  return os;
}

struct t23d3fc58ccfe0cce25245c2b6a703c09 {
  bool can_del;
  bool can_write;
  double expiry;
  dessser::gen::sync_key::t_ext k;
  double mtime;
  std::string owner;
  std::string uid;
  dessser::gen::sync_value::t_ext v;
  bool operator==(t23d3fc58ccfe0cce25245c2b6a703c09 const &other) const {
    return can_del == other.can_del && can_write == other.can_write && expiry == other.expiry && k == other.k && mtime == other.mtime && owner == other.owner && uid == other.uid && v == other.v;
  }
};
inline std::ostream &operator<<(std::ostream &os, t23d3fc58ccfe0cce25245c2b6a703c09 const &r) {
  os << '{';
  os << "can_del:" << r.can_del << ',';
  os << "can_write:" << r.can_write << ',';
  os << "expiry:" << r.expiry << ',';
  os << "k:" << r.k << ',';
  os << "mtime:" << r.mtime << ',';
  os << "owner:" << r.owner << ',';
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
  dessser::gen::sync_socket::t_ext,
  std::string,
  ::dessser::gen::sync_server_msg::tdf5c8f0315e72acddb131eb06c27ddd0,
  ::dessser::gen::sync_server_msg::t23d3fc58ccfe0cce25245c2b6a703c09,
  dessser::gen::sync_key::t_ext,
  ::dessser::gen::sync_server_msg::ta33518bab5ce39f29507a4782b59d374,
  dessser::gen::sync_key::t_ext
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
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
