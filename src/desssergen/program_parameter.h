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
struct td2a63c4a6d459d282fa7d9d9ae75b4d2 : public std::tuple<
  ::dessser::gen::program_parameter::t*,
  Pointer
> {
  using tuple::tuple;
  td2a63c4a6d459d282fa7d9d9ae75b4d2(std::tuple<::dessser::gen::program_parameter::t*, Pointer> p)
    : std::tuple<::dessser::gen::program_parameter::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td2a63c4a6d459d282fa7d9d9ae75b4d2 const &a, td2a63c4a6d459d282fa7d9d9ae75b4d2 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td2a63c4a6d459d282fa7d9d9ae75b4d2 const &a, td2a63c4a6d459d282fa7d9d9ae75b4d2 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td2a63c4a6d459d282fa7d9d9ae75b4d2 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::program_parameter::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::program_parameter::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::program_parameter::td2a63c4a6d459d282fa7d9d9ae75b4d2(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
