#ifndef DESSSER_GEN_raql_net_protocol
#define DESSSER_GEN_raql_net_protocol
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_net_protocol {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  Void, // Collectd
  Void, // NetflowV5
  Void // Graphite
> { using variant::variant; };

enum Constr_t {
  Collectd,
  NetflowV5,
  Graphite,
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Collectd
    case 1: return std::get<1>(a) == std::get<1>(b); // NetflowV5
    case 2: return std::get<2>(a) == std::get<2>(b); // Graphite
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Collectd " << std::get<0>(v); break;
    case 1: os << "NetflowV5 " << std::get<1>(v); break;
    case 2: os << "Graphite " << std::get<2>(v); break;
  }
  return os;
}

typedef std::tuple<
  ::dessser::gen::raql_net_protocol::t*,
  Pointer
> t50e4258f843117afd411316037767879;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_net_protocol::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_net_protocol::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_net_protocol::t50e4258f843117afd411316037767879(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
