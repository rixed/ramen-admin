#ifndef DESSSER_GEN_raql_select_field
#define DESSSER_GEN_raql_select_field
#include <functional>
#include <memory>
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
  dessser::gen::raql_expr::t_ext expr;
  dessser::gen::field_name::t_ext alias;
  std::string doc;
  std::optional<std::string> aggr;
  t(dessser::gen::raql_expr::t_ext expr_, dessser::gen::field_name::t_ext alias_, std::string doc_, std::optional<std::string> aggr_) : expr(expr_), alias(alias_), doc(doc_), aggr(aggr_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::raql_expr::Deref(a.expr) == ::dessser::gen::raql_expr::Deref(b.expr) && ::dessser::gen::field_name::Deref(a.alias) == ::dessser::gen::field_name::Deref(b.alias) && a.doc == b.doc && ((a.aggr && b.aggr && a.aggr.value() == b.aggr.value()) || (!a.aggr && !b.aggr));
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "expr:" << r.expr << ',';
  os << "alias:" << r.alias << ',';
  os << "doc:" << r.doc << ',';
  if (r.aggr) os << "aggr:" << r.aggr.value();
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tdf010ca5e9c34c62a5f22df13388fb5d : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_select_field::t> ,
  Pointer
> {
  using tuple::tuple;
  tdf010ca5e9c34c62a5f22df13388fb5d(std::tuple<std::shared_ptr<::dessser::gen::raql_select_field::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_select_field::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tdf010ca5e9c34c62a5f22df13388fb5d const &a, tdf010ca5e9c34c62a5f22df13388fb5d const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tdf010ca5e9c34c62a5f22df13388fb5d const &a, tdf010ca5e9c34c62a5f22df13388fb5d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tdf010ca5e9c34c62a5f22df13388fb5d const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tdf010ca5e9c34c62a5f22df13388fb5d> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_select_field::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_select_field::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_select_field::tdf010ca5e9c34c62a5f22df13388fb5d(Pointer)> of_row_binary;
extern std::function<::dessser::gen::raql_select_field::tdf010ca5e9c34c62a5f22df13388fb5d(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_select_field::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
