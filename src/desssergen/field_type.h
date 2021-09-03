#ifndef DESSSER_GEN_field_type
#define DESSSER_GEN_field_type
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/units.h"
#include "desssergen/raql_type.h"
#include "desssergen/field_name.h"

namespace dessser::gen::field_type {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  std::optional<std::string> aggr;
  std::string doc;
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_type::t_ext typ;
  std::optional<dessser::gen::units::t_ext> units;
  t(std::optional<std::string> aggr_, std::string doc_, dessser::gen::field_name::t_ext name_, dessser::gen::raql_type::t_ext typ_, std::optional<dessser::gen::units::t_ext> units_) : aggr(aggr_), doc(doc_), name(name_), typ(typ_), units(units_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  if (r.aggr) os << "aggr:" << r.aggr.value() << ',';
  os << "doc:" << r.doc << ',';
  os << "name:" << ::dessser::gen::field_name::Deref(r.name) << ',';
  os << "typ:" << ::dessser::gen::raql_type::Deref(r.typ) << ',';
  if (r.units) os << "units:" << ::dessser::gen::units::Deref(r.units.value());
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ((a.aggr && b.aggr && a.aggr.value() == b.aggr.value()) || (!a.aggr && !b.aggr)) && a.doc == b.doc && ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ) && ((a.units && b.units && ::dessser::gen::units::Deref(a.units.value()) == ::dessser::gen::units::Deref(b.units.value())) || (!a.units && !b.units));
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  ::dessser::gen::field_type::t*,
  Pointer
> ta9083c6ab4999123f9c30be0def4cf3a;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::field_type::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::field_type::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::field_type::ta9083c6ab4999123f9c30be0def4cf3a(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
