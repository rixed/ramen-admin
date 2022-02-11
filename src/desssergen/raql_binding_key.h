#ifndef DESSSER_GEN_raql_binding_key
#define DESSSER_GEN_raql_binding_key
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_variable.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_variable.h"

namespace dessser::gen::raql_binding_key {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t5dd86ec6b88e1a48a954458ba0bc58f0 : public std::tuple<
  dessser::gen::raql_variable::t_ext,
  dessser::gen::field_name::t_ext
> {
  using tuple::tuple;
};
inline bool operator==(t5dd86ec6b88e1a48a954458ba0bc58f0 const &a, t5dd86ec6b88e1a48a954458ba0bc58f0 const &b) {
  return ::dessser::gen::raql_variable::Deref(std::get<0>(a)) == ::dessser::gen::raql_variable::Deref(std::get<0>(b)) && ::dessser::gen::field_name::Deref(std::get<1>(a)) == ::dessser::gen::field_name::Deref(std::get<1>(b));
}
inline bool operator!=(t5dd86ec6b88e1a48a954458ba0bc58f0 const &a, t5dd86ec6b88e1a48a954458ba0bc58f0 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t5dd86ec6b88e1a48a954458ba0bc58f0 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t5dd86ec6b88e1a48a954458ba0bc58f0> const t) { os << *t; return os; }

struct t : public std::variant<
  uint32_t, // State
  ::dessser::gen::raql_binding_key::t5dd86ec6b88e1a48a954458ba0bc58f0, // RecordField
  dessser::gen::raql_variable::t_ext, // RecordValue
  std::string // Direct
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 4 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // State
    case 1: return std::get<1>(a) == std::get<1>(b); // RecordField
    case 2: return ::dessser::gen::raql_variable::Deref(std::get<2>(a)) == ::dessser::gen::raql_variable::Deref(std::get<2>(b)); // RecordValue
    case 3: return std::get<3>(a) == std::get<3>(b); // Direct
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
enum Constr_t {
  State,
  RecordField,
  RecordValue,
  Direct,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "State " << std::get<0>(v); break;
    case 1: os << "RecordField " << std::get<1>(v); break;
    case 2: os << "RecordValue " << std::get<2>(v); break;
    case 3: os << "Direct " << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct te0b81a441eb7e83e50aca86fda28d10f : public std::tuple<
  ::dessser::gen::raql_binding_key::t,
  Pointer
> {
  using tuple::tuple;
  te0b81a441eb7e83e50aca86fda28d10f(std::tuple<::dessser::gen::raql_binding_key::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_binding_key::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te0b81a441eb7e83e50aca86fda28d10f const &a, te0b81a441eb7e83e50aca86fda28d10f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te0b81a441eb7e83e50aca86fda28d10f const &a, te0b81a441eb7e83e50aca86fda28d10f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te0b81a441eb7e83e50aca86fda28d10f const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te0b81a441eb7e83e50aca86fda28d10f> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_binding_key::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_binding_key::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_binding_key::te0b81a441eb7e83e50aca86fda28d10f(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::raql_binding_key::te0b81a441eb7e83e50aca86fda28d10f(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::raql_binding_key::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
