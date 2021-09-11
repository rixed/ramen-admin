#ifndef DESSSER_GEN_raql_select_field
#define DESSSER_GEN_raql_select_field
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_expr.h"

namespace dessser::gen::raql_select_field {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  std::optional<std::string> aggr;
  dessser::gen::field_name::t_ext alias;
  std::string doc;
  dessser::gen::raql_expr::t_ext expr;
  t(std::optional<std::string> aggr_, dessser::gen::field_name::t_ext alias_, std::string doc_, dessser::gen::raql_expr::t_ext expr_) : aggr(aggr_), alias(alias_), doc(doc_), expr(expr_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  if (r.aggr) os << "aggr:" << r.aggr.value() << ',';
  os << "alias:" << ::dessser::gen::field_name::Deref(r.alias) << ',';
  os << "doc:" << r.doc << ',';
  os << "expr:" << ::dessser::gen::raql_expr::Deref(r.expr);
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ((a.aggr && b.aggr && a.aggr.value() == b.aggr.value()) || (!a.aggr && !b.aggr)) && ::dessser::gen::field_name::Deref(a.alias) == ::dessser::gen::field_name::Deref(b.alias) && a.doc == b.doc && ::dessser::gen::raql_expr::Deref(a.expr) == ::dessser::gen::raql_expr::Deref(b.expr);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tbc99a2463600e515e0f9491341a5f511 : public std::tuple<
  ::dessser::gen::raql_select_field::t*,
  Pointer
> {
  using tuple::tuple;
  tbc99a2463600e515e0f9491341a5f511(std::tuple<::dessser::gen::raql_select_field::t*, Pointer> p)
    : std::tuple<::dessser::gen::raql_select_field::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tbc99a2463600e515e0f9491341a5f511 const &a, tbc99a2463600e515e0f9491341a5f511 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tbc99a2463600e515e0f9491341a5f511 const &a, tbc99a2463600e515e0f9491341a5f511 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tbc99a2463600e515e0f9491341a5f511 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_select_field::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_select_field::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_select_field::tbc99a2463600e515e0f9491341a5f511(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
