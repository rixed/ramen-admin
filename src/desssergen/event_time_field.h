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
enum t168aeaddd2d2bd1c09c4d0fcc52d226f {
  OutputField,
  Parameter,
};

constexpr size_t t168aeaddd2d2bd1c09c4d0fcc52d226f_size { 2 };
inline std::ostream &operator<<(std::ostream &os, t168aeaddd2d2bd1c09c4d0fcc52d226f const &v) {
  switch (v) {
    case OutputField: os << "OutputField"; break;
    case Parameter: os << "Parameter"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t168aeaddd2d2bd1c09c4d0fcc52d226f> const v) { os << *v; return os; }

struct t : public std::tuple<
  dessser::gen::field_name::t_ext,
  ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f,
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
