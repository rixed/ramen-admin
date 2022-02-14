#ifndef DESSSER_GEN_raql_net_protocol
#define DESSSER_GEN_raql_net_protocol
#include <functional>
#include <memory>
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
enum t {
  Collectd,
  NetflowV5,
  Graphite,
};

constexpr size_t t_size { 3 };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v) {
    case Collectd: os << "Collectd"; break;
    case NetflowV5: os << "NetflowV5"; break;
    case Graphite: os << "Graphite"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t55bea3e51aa79e08de131e8d87a06294 : public std::tuple<
  ::dessser::gen::raql_net_protocol::t,
  Pointer
> {
  using tuple::tuple;
  t55bea3e51aa79e08de131e8d87a06294(std::tuple<::dessser::gen::raql_net_protocol::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_net_protocol::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t55bea3e51aa79e08de131e8d87a06294 const &a, t55bea3e51aa79e08de131e8d87a06294 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t55bea3e51aa79e08de131e8d87a06294 const &a, t55bea3e51aa79e08de131e8d87a06294 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t55bea3e51aa79e08de131e8d87a06294 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t55bea3e51aa79e08de131e8d87a06294> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_net_protocol::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_net_protocol::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_net_protocol::t55bea3e51aa79e08de131e8d87a06294(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::raql_net_protocol::t55bea3e51aa79e08de131e8d87a06294(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::raql_net_protocol::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
