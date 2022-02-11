#ifndef DESSSER_GEN_event_time_field
#define DESSSER_GEN_event_time_field
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"

namespace dessser::gen::event_time_field {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t5ea188408f7fe865526a4b1d67aef6a3 : public std::variant<
  Void, // OutputField
  Void // Parameter
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t5ea188408f7fe865526a4b1d67aef6a3 const &a, t5ea188408f7fe865526a4b1d67aef6a3 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // OutputField
    case 1: return std::get<1>(a) == std::get<1>(b); // Parameter
  };
  return false;
}
inline bool operator!=(t5ea188408f7fe865526a4b1d67aef6a3 const &a, t5ea188408f7fe865526a4b1d67aef6a3 const &b) {
  return !operator==(a, b);
}
enum Constr_t5ea188408f7fe865526a4b1d67aef6a3 {
  OutputField,
  Parameter,
};

inline std::ostream &operator<<(std::ostream &os, t5ea188408f7fe865526a4b1d67aef6a3 const &v) {
  switch (v.index()) {
    case 0: os << "OutputField" << std::get<0>(v); break;
    case 1: os << "Parameter" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t5ea188408f7fe865526a4b1d67aef6a3> const v) { os << *v; return os; }

struct t : public std::tuple<
  dessser::gen::field_name::t_ext,
  ::dessser::gen::event_time_field::t5ea188408f7fe865526a4b1d67aef6a3,
  double
> {
  using tuple::tuple;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const t) { os << *t; return os; }

struct tc1fc09471ee4464e5fc85213a52a12e7 : public std::tuple<
  ::dessser::gen::event_time_field::t,
  Pointer
> {
  using tuple::tuple;
  tc1fc09471ee4464e5fc85213a52a12e7(std::tuple<::dessser::gen::event_time_field::t, Pointer> p)
    : std::tuple<::dessser::gen::event_time_field::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc1fc09471ee4464e5fc85213a52a12e7 const &a, tc1fc09471ee4464e5fc85213a52a12e7 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc1fc09471ee4464e5fc85213a52a12e7 const &a, tc1fc09471ee4464e5fc85213a52a12e7 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc1fc09471ee4464e5fc85213a52a12e7 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc1fc09471ee4464e5fc85213a52a12e7> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::event_time_field::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::event_time_field::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::event_time_field::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
