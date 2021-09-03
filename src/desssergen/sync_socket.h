#ifndef DESSSER_GEN_sync_socket
#define DESSSER_GEN_sync_socket
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::sync_socket {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tb689860ac91fca7822797a026958e891 : public std::variant<
  uint32_t, // v4
  uint128_t // v6
> { using variant::variant; };

enum Constr_tb689860ac91fca7822797a026958e891 {
  v4,
  v6,
};

inline bool operator==(tb689860ac91fca7822797a026958e891 const &a, tb689860ac91fca7822797a026958e891 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // v4
    case 1: return std::get<1>(a) == std::get<1>(b); // v6
  };
  return false;
}
inline bool operator!=(tb689860ac91fca7822797a026958e891 const &a, tb689860ac91fca7822797a026958e891 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb689860ac91fca7822797a026958e891 const &v) {
  switch (v.index()) {
    case 0: os << "v4 " << std::get<0>(v); break;
    case 1: os << "v6 " << std::get<1>(v); break;
  }
  return os;
}

struct t {
  ::dessser::gen::sync_socket::tb689860ac91fca7822797a026958e891 ip;
  uint16_t port;
  t(::dessser::gen::sync_socket::tb689860ac91fca7822797a026958e891 ip_, uint16_t port_) : ip(ip_), port(port_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "port:" << r.port;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.ip == b.ip && a.port == b.port;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  ::dessser::gen::sync_socket::t*,
  Pointer
> t886d61cb117071bcf543729e568957a2;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_socket::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_socket::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_socket::t886d61cb117071bcf543729e568957a2(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
