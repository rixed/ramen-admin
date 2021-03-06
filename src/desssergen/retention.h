#ifndef DESSSER_GEN_retention
#define DESSSER_GEN_retention
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_expr.h"

namespace dessser::gen::retention {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::raql_expr::t_ext duration;
  double period;
  t(dessser::gen::raql_expr::t_ext duration_, double period_) : duration(duration_), period(period_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::raql_expr::Deref(a.duration) == ::dessser::gen::raql_expr::Deref(b.duration) && a.period == b.period;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "duration:" << r.duration << ',';
  os << "period:" << r.period;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t8f9669ef3854b699ed61677e763b5473 : public std::tuple<
  ::dessser::gen::retention::t,
  Pointer
> {
  using tuple::tuple;
  t8f9669ef3854b699ed61677e763b5473(std::tuple<::dessser::gen::retention::t, Pointer> p)
    : std::tuple<::dessser::gen::retention::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8f9669ef3854b699ed61677e763b5473 const &a, t8f9669ef3854b699ed61677e763b5473 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8f9669ef3854b699ed61677e763b5473 const &a, t8f9669ef3854b699ed61677e763b5473 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t8f9669ef3854b699ed61677e763b5473 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t8f9669ef3854b699ed61677e763b5473> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::retention::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::retention::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::retention::t8f9669ef3854b699ed61677e763b5473(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::retention::t8f9669ef3854b699ed61677e763b5473(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::retention::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
