#ifndef DESSSER_GEN_event_time_field
#define DESSSER_GEN_event_time_field
#include <arpa/inet.h>
#include <functional>
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
struct t48a2d544f23c6703dc0a88c42484f480 : public std::variant<
  Void, // OutputField
  Void // Parameter
> { using variant::variant; };

enum Constr_t48a2d544f23c6703dc0a88c42484f480 {
  OutputField,
  Parameter,
};

inline std::ostream &operator<<(std::ostream &os, t48a2d544f23c6703dc0a88c42484f480 const &v) {
  switch (v.index()) {
    case 0: os << "OutputField " << std::get<0>(v); break;
    case 1: os << "Parameter " << std::get<1>(v); break;
  }
  return os;
}

inline bool operator==(t48a2d544f23c6703dc0a88c42484f480 const &a, t48a2d544f23c6703dc0a88c42484f480 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // OutputField
    case 1: return std::get<1>(a) == std::get<1>(b); // Parameter
  };
  return false;
}
inline bool operator!=(t48a2d544f23c6703dc0a88c42484f480 const &a, t48a2d544f23c6703dc0a88c42484f480 const &b) {
  return !operator==(a, b);
}
struct t : public std::tuple<
  dessser::gen::field_name::t_ext,
  ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480,
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
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct tb57f62e74d28e552b9450388f3904f11 : public std::tuple<
  ::dessser::gen::event_time_field::t*,
  Pointer
> {
  using tuple::tuple;
  tb57f62e74d28e552b9450388f3904f11(std::tuple<::dessser::gen::event_time_field::t*, Pointer> p)
    : std::tuple<::dessser::gen::event_time_field::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb57f62e74d28e552b9450388f3904f11 const &a, tb57f62e74d28e552b9450388f3904f11 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb57f62e74d28e552b9450388f3904f11 const &a, tb57f62e74d28e552b9450388f3904f11 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb57f62e74d28e552b9450388f3904f11 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::event_time_field::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::event_time_field::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif