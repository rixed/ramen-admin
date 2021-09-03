#ifndef DESSSER_GEN_program_run_parameter
#define DESSSER_GEN_program_run_parameter
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_value.h"
#include "desssergen/field_name.h"

namespace dessser::gen::program_run_parameter {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_value::t_ext value;
  t(dessser::gen::field_name::t_ext name_, dessser::gen::raql_value::t_ext value_) : name(name_), value(value_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << ::dessser::gen::field_name::Deref(r.name) << ',';
  os << "value:" << ::dessser::gen::raql_value::Deref(r.value);
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_value::Deref(a.value) == ::dessser::gen::raql_value::Deref(b.value);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  ::dessser::gen::program_run_parameter::t*,
  Pointer
> tc5822b22d45d47f34b2c7bbfc44824d9;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::program_run_parameter::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::program_run_parameter::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::program_run_parameter::tc5822b22d45d47f34b2c7bbfc44824d9(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
