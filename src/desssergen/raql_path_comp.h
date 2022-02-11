#ifndef DESSSER_GEN_raql_path_comp
#define DESSSER_GEN_raql_path_comp
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"

namespace dessser::gen::raql_path_comp {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  uint32_t, // Idx
  dessser::gen::field_name::t_ext // Name
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Idx
    case 1: return ::dessser::gen::field_name::Deref(std::get<1>(a)) == ::dessser::gen::field_name::Deref(std::get<1>(b)); // Name
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
enum Constr_t {
  Idx,
  Name,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Idx " << std::get<0>(v); break;
    case 1: os << "Name " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t44f64b18392159636d8c1413aca19b57 : public std::tuple<
  ::dessser::gen::raql_path_comp::t,
  Pointer
> {
  using tuple::tuple;
  t44f64b18392159636d8c1413aca19b57(std::tuple<::dessser::gen::raql_path_comp::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_path_comp::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t44f64b18392159636d8c1413aca19b57 const &a, t44f64b18392159636d8c1413aca19b57 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t44f64b18392159636d8c1413aca19b57 const &a, t44f64b18392159636d8c1413aca19b57 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t44f64b18392159636d8c1413aca19b57 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t44f64b18392159636d8c1413aca19b57> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_path_comp::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_path_comp::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::raql_path_comp::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
