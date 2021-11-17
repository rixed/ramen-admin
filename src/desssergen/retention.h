#ifndef DESSSER_GEN_retention
#define DESSSER_GEN_retention
#include <arpa/inet.h>
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
struct t6dbf61a16e6aaa200048c3b277abb230 : public std::tuple<
  std::shared_ptr<::dessser::gen::retention::t> ,
  Pointer
> {
  using tuple::tuple;
  t6dbf61a16e6aaa200048c3b277abb230(std::tuple<std::shared_ptr<::dessser::gen::retention::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::retention::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6dbf61a16e6aaa200048c3b277abb230 const &a, t6dbf61a16e6aaa200048c3b277abb230 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6dbf61a16e6aaa200048c3b277abb230 const &a, t6dbf61a16e6aaa200048c3b277abb230 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t6dbf61a16e6aaa200048c3b277abb230 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::retention::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::retention::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::retention::t6dbf61a16e6aaa200048c3b277abb230(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
