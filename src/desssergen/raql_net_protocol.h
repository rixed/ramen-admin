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
struct t : public std::variant<
  Void, // Collectd
  Void, // NetflowV5
  Void // Graphite
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
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
enum Constr_t {
  Collectd,
  NetflowV5,
  Graphite,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Collectd" << std::get<0>(v); break;
    case 1: os << "NetflowV5" << std::get<1>(v); break;
    case 2: os << "Graphite" << std::get<2>(v); break;
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
