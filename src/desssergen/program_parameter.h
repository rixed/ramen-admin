#ifndef DESSSER_GEN_program_parameter
#define DESSSER_GEN_program_parameter
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
  os << "ptyp:" << r.ptyp << ',';
  os << "value:" << r.value;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_type::Deref(a.ptyp) == ::dessser::gen::field_type::Deref(b.ptyp) && ::dessser::gen::raql_value::Deref(a.value) == ::dessser::gen::raql_value::Deref(b.value);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tf064cb568ecd4c78e46c7b6418d30392 : public std::tuple<
  std::shared_ptr<::dessser::gen::program_parameter::t> ,
  Pointer
> {
  using tuple::tuple;
  tf064cb568ecd4c78e46c7b6418d30392(std::tuple<std::shared_ptr<::dessser::gen::program_parameter::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::program_parameter::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf064cb568ecd4c78e46c7b6418d30392 const &a, tf064cb568ecd4c78e46c7b6418d30392 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf064cb568ecd4c78e46c7b6418d30392 const &a, tf064cb568ecd4c78e46c7b6418d30392 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf064cb568ecd4c78e46c7b6418d30392 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::program_parameter::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::program_parameter::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::program_parameter::tf064cb568ecd4c78e46c7b6418d30392(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
