#ifndef DESSSER_GEN_program_parameter
#define DESSSER_GEN_program_parameter
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_value.h"
#include "desssergen/units.h"
#include "desssergen/raql_type.h"
#include "desssergen/field_name.h"

namespace dessser::gen::program_parameter {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_type::t_ext typ;
  std::optional<dessser::gen::units::t_ext> units;
  std::string doc;
  dessser::gen::raql_value::t_ext value;
  t(dessser::gen::field_name::t_ext name_, dessser::gen::raql_type::t_ext typ_, std::optional<dessser::gen::units::t_ext> units_, std::string doc_, dessser::gen::raql_value::t_ext value_) : name(name_), typ(typ_), units(units_), doc(doc_), value(value_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ) && ((a.units && b.units && ::dessser::gen::units::Deref(a.units.value()) == ::dessser::gen::units::Deref(b.units.value())) || (!a.units && !b.units)) && a.doc == b.doc && ::dessser::gen::raql_value::Deref(a.value) == ::dessser::gen::raql_value::Deref(b.value);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "typ:" << r.typ << ',';
  if (r.units) os << "units:" << r.units.value() << ',';
  os << "doc:" << r.doc << ',';
  os << "value:" << r.value;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t9b90f97bf6f5fbd106f227cd54c9acfb : public std::tuple<
  ::dessser::gen::program_parameter::t,
  Pointer
> {
  using tuple::tuple;
  t9b90f97bf6f5fbd106f227cd54c9acfb(std::tuple<::dessser::gen::program_parameter::t, Pointer> p)
    : std::tuple<::dessser::gen::program_parameter::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9b90f97bf6f5fbd106f227cd54c9acfb const &a, t9b90f97bf6f5fbd106f227cd54c9acfb const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9b90f97bf6f5fbd106f227cd54c9acfb const &a, t9b90f97bf6f5fbd106f227cd54c9acfb const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t9b90f97bf6f5fbd106f227cd54c9acfb const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t9b90f97bf6f5fbd106f227cd54c9acfb> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::program_parameter::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::program_parameter::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::program_parameter::t9b90f97bf6f5fbd106f227cd54c9acfb(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::program_parameter::t9b90f97bf6f5fbd106f227cd54c9acfb(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::program_parameter::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
