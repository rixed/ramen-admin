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
struct t2dfffd4312923e34e0c3ba0f8d708626 : public std::variant<
  uint32_t,
  uint128_t
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t2dfffd4312923e34e0c3ba0f8d708626 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t {
  t2dfffd4312923e34e0c3ba0f8d708626 ip;
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
