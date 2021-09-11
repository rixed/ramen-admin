#ifndef DESSSER_GEN_retention
#define DESSSER_GEN_retention
#include <arpa/inet.h>
#include <functional>
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
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "duration:" << ::dessser::gen::raql_expr::Deref(r.duration) << ',';
  os << "period:" << r.period;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::raql_expr::Deref(a.duration) == ::dessser::gen::raql_expr::Deref(b.duration) && a.period == b.period;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t3c1a4fa343f4d41a3f7803e33483ce83 : public std::tuple<
  ::dessser::gen::retention::t*,
  Pointer
> {
  using tuple::tuple;
  t3c1a4fa343f4d41a3f7803e33483ce83(std::tuple<::dessser::gen::retention::t*, Pointer> p)
    : std::tuple<::dessser::gen::retention::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3c1a4fa343f4d41a3f7803e33483ce83 const &a, t3c1a4fa343f4d41a3f7803e33483ce83 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3c1a4fa343f4d41a3f7803e33483ce83 const &a, t3c1a4fa343f4d41a3f7803e33483ce83 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t3c1a4fa343f4d41a3f7803e33483ce83 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::retention::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::retention::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::retention::t3c1a4fa343f4d41a3f7803e33483ce83(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
