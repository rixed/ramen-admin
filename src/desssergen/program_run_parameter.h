#ifndef DESSSER_GEN_program_run_parameter
#define DESSSER_GEN_program_run_parameter
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_value::Deref(a.value) == ::dessser::gen::raql_value::Deref(b.value);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "value:" << r.value;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t62c3c742c99d7c40e6f6e70698ba71a5 : public std::tuple<
  std::shared_ptr<::dessser::gen::program_run_parameter::t> ,
  Pointer
> {
  using tuple::tuple;
  t62c3c742c99d7c40e6f6e70698ba71a5(std::tuple<std::shared_ptr<::dessser::gen::program_run_parameter::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::program_run_parameter::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t62c3c742c99d7c40e6f6e70698ba71a5 const &a, t62c3c742c99d7c40e6f6e70698ba71a5 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t62c3c742c99d7c40e6f6e70698ba71a5 const &a, t62c3c742c99d7c40e6f6e70698ba71a5 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t62c3c742c99d7c40e6f6e70698ba71a5 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t62c3c742c99d7c40e6f6e70698ba71a5> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::program_run_parameter::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::program_run_parameter::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5(Pointer)> of_row_binary;
extern std::function<::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::program_run_parameter::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
