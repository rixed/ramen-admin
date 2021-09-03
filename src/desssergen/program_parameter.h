#ifndef DESSSER_GEN_program_parameter
#define DESSSER_GEN_program_parameter
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_value.h"
#include "desssergen/field_type.h"

namespace dessser::gen::program_parameter {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_type::t_ext ptyp;
  dessser::gen::raql_value::t_ext value;
  t(dessser::gen::field_type::t_ext ptyp_, dessser::gen::raql_value::t_ext value_) : ptyp(ptyp_), value(value_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "ptyp:" << ::dessser::gen::field_type::Deref(r.ptyp) << ',';
  os << "value:" << ::dessser::gen::raql_value::Deref(r.value);
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_type::Deref(a.ptyp) == ::dessser::gen::field_type::Deref(b.ptyp) && ::dessser::gen::raql_value::Deref(a.value) == ::dessser::gen::raql_value::Deref(b.value);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  ::dessser::gen::program_parameter::t*,
  Pointer
> t571f6c411143ec709060fca7e7f9ac08;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::program_parameter::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::program_parameter::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::program_parameter::t571f6c411143ec709060fca7e7f9ac08(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
