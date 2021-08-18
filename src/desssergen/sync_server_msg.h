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
struct td69b18863d7c63937f8798ddedc78b80 {
  dessser::gen::sync_key::t_ext k;
  dessser::gen::sync_value::t_ext v;
  std::string uid;
  double mtime;
  bool operator==(td69b18863d7c63937f8798ddedc78b80 const &other) const {
    return k == other.k && v == other.v && uid == other.uid && mtime == other.mtime;
  }
};
inline std::ostream &operator<<(std::ostream &os, td69b18863d7c63937f8798ddedc78b80 const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "v:" << r.v << ',';
  os << "uid:" << r.uid << ',';
  os << "mtime:" << r.mtime;
  os << '}';
  return os;
}

struct tf4b1f78fa23e7e2322a6e3241589000c {
  dessser::gen::sync_key::t_ext k;
  dessser::gen::sync_value::t_ext v;
  std::string uid;
  double mtime;
  bool can_write;
  bool can_del;
  std::string owner;
  double expiry;
  bool operator==(tf4b1f78fa23e7e2322a6e3241589000c const &other) const {
    return k == other.k && v == other.v && uid == other.uid && mtime == other.mtime && can_write == other.can_write && can_del == other.can_del && owner == other.owner && expiry == other.expiry;
  }
};
inline std::ostream &operator<<(std::ostream &os, tf4b1f78fa23e7e2322a6e3241589000c const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "v:" << r.v << ',';
  os << "uid:" << r.uid << ',';
  os << "mtime:" << r.mtime << ',';
  os << "can_write:" << r.can_write << ',';
  os << "can_del:" << r.can_del << ',';
  os << "owner:" << r.owner << ',';
  os << "expiry:" << r.expiry;
  os << '}';
  return os;
}

struct t1861dadd357f09584a634ac54a194ddc {
  dessser::gen::sync_key::t_ext k;
  std::string owner;
  double expiry;
  bool operator==(t1861dadd357f09584a634ac54a194ddc const &other) const {
    return k == other.k && owner == other.owner && expiry == other.expiry;
  }
};
inline std::ostream &operator<<(std::ostream &os, t1861dadd357f09584a634ac54a194ddc const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "owner:" << r.owner << ',';
  os << "expiry:" << r.expiry;
  os << '}';
  return os;
}

struct t : public std::variant<
  dessser::gen::sync_socket::t_ext,
  std::string,
  td69b18863d7c63937f8798ddedc78b80,
  tf4b1f78fa23e7e2322a6e3241589000c,
  dessser::gen::sync_key::t_ext,
  t1861dadd357f09584a634ac54a194ddc,
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
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t*,Pointer)> to_row_binary;
extern std::function<Size(t*)> sersize_of_row_binary;
extern std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
