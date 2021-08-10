#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::sync_socket {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct cc9ac153fc4d8a1128cc88896605e565 : public std::variant<
  uint32_t,
  uint128_t
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, cc9ac153fc4d8a1128cc88896605e565 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t {
  cc9ac153fc4d8a1128cc88896605e565 ip;
  uint16_t port;
  bool operator==(t const &other) const {
    return ip == other.ip && port == other.port;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "port:" << r.port;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
