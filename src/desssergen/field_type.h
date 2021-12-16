#ifndef DESSSER_GEN_field_type
#define DESSSER_GEN_field_type
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_type::t_ext typ;
  std::optional<dessser::gen::units::t_ext> units;
  std::string doc;
  std::optional<std::string> aggr;
  t(dessser::gen::field_name::t_ext name_, dessser::gen::raql_type::t_ext typ_, std::optional<dessser::gen::units::t_ext> units_, std::string doc_, std::optional<std::string> aggr_) : name(name_), typ(typ_), units(units_), doc(doc_), aggr(aggr_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ) && ((a.units && b.units && ::dessser::gen::units::Deref(a.units.value()) == ::dessser::gen::units::Deref(b.units.value())) || (!a.units && !b.units)) && a.doc == b.doc && ((a.aggr && b.aggr && a.aggr.value() == b.aggr.value()) || (!a.aggr && !b.aggr));
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
  if (r.aggr) os << "aggr:" << r.aggr.value();
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t17783e9e04d504e04563e9d950fd4c39 : public std::tuple<
  std::shared_ptr<::dessser::gen::field_type::t> ,
  Pointer
> {
  using tuple::tuple;
  t17783e9e04d504e04563e9d950fd4c39(std::tuple<std::shared_ptr<::dessser::gen::field_type::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::field_type::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t17783e9e04d504e04563e9d950fd4c39 const &a, t17783e9e04d504e04563e9d950fd4c39 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t17783e9e04d504e04563e9d950fd4c39 const &a, t17783e9e04d504e04563e9d950fd4c39 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t17783e9e04d504e04563e9d950fd4c39 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t17783e9e04d504e04563e9d950fd4c39> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::field_type::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::field_type::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39(Pointer)> of_row_binary;
extern std::function<::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::field_type::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
