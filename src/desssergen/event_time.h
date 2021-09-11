#ifndef DESSSER_GEN_event_time
#define DESSSER_GEN_event_time
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/event_time_field.h"
#include "desssergen/event_time_field.h"
#include "desssergen/event_time_field.h"

namespace dessser::gen::event_time {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tb22291137390f6968b7c7852ed4b8408 : public std::variant<
  double, // DurationConst
  dessser::gen::event_time_field::t_ext, // DurationField
  dessser::gen::event_time_field::t_ext // StopField
> { using variant::variant; };

enum Constr_tb22291137390f6968b7c7852ed4b8408 {
  DurationConst,
  DurationField,
  StopField,
};

inline std::ostream &operator<<(std::ostream &os, tb22291137390f6968b7c7852ed4b8408 const &v) {
  switch (v.index()) {
    case 0: os << "DurationConst " << std::get<0>(v); break;
    case 1: os << "DurationField " << ::dessser::gen::event_time_field::Deref(std::get<1>(v)); break;
    case 2: os << "StopField " << ::dessser::gen::event_time_field::Deref(std::get<2>(v)); break;
  }
  return os;
}

inline bool operator==(tb22291137390f6968b7c7852ed4b8408 const &a, tb22291137390f6968b7c7852ed4b8408 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // DurationConst
    case 1: return ::dessser::gen::event_time_field::Deref(std::get<1>(a)) == ::dessser::gen::event_time_field::Deref(std::get<1>(b)); // DurationField
    case 2: return ::dessser::gen::event_time_field::Deref(std::get<2>(a)) == ::dessser::gen::event_time_field::Deref(std::get<2>(b)); // StopField
  };
  return false;
}
inline bool operator!=(tb22291137390f6968b7c7852ed4b8408 const &a, tb22291137390f6968b7c7852ed4b8408 const &b) {
  return !operator==(a, b);
}
struct t : public std::tuple<
  dessser::gen::event_time_field::t_ext,
  ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408
> {
  using tuple::tuple;
  t(std::tuple<dessser::gen::event_time_field::t_ext, ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408> p)
    : std::tuple<dessser::gen::event_time_field::t_ext, ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::event_time_field::Deref(std::get<0>(a)) == ::dessser::gen::event_time_field::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct tfe74fe03fd74a982eabab7a43795b12a : public std::tuple<
  ::dessser::gen::event_time::t*,
  Pointer
> {
  using tuple::tuple;
  tfe74fe03fd74a982eabab7a43795b12a(std::tuple<::dessser::gen::event_time::t*, Pointer> p)
    : std::tuple<::dessser::gen::event_time::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tfe74fe03fd74a982eabab7a43795b12a const &a, tfe74fe03fd74a982eabab7a43795b12a const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tfe74fe03fd74a982eabab7a43795b12a const &a, tfe74fe03fd74a982eabab7a43795b12a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tfe74fe03fd74a982eabab7a43795b12a const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::event_time::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::event_time::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::event_time::tfe74fe03fd74a982eabab7a43795b12a(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
