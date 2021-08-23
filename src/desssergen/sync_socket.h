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
struct t8ce7f646add6f67a97a24392bb6169f0 : public std::variant<
  uint32_t,
  uint128_t
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t8ce7f646add6f67a97a24392bb6169f0 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t {
  ::dessser::gen::sync_socket::t8ce7f646add6f67a97a24392bb6169f0 ip;
  uint16_t port;
  bool operator==(t const &other) const {
    return ip == other.ip && port == other.port;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "port:" << r.port;
  os << '}';
  return os;
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

}
#endif
