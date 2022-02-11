#ifndef DESSSER_GEN_event_time
#define DESSSER_GEN_event_time
#include <functional>
#include <memory>
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
struct t52e26a57572ca91d707cdc0b7b472229 : public std::variant<
  double, // DurationConst
  dessser::gen::event_time_field::t_ext, // DurationField
  dessser::gen::event_time_field::t_ext // StopField
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

inline bool operator==(t52e26a57572ca91d707cdc0b7b472229 const &a, t52e26a57572ca91d707cdc0b7b472229 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // DurationConst
    case 1: return ::dessser::gen::event_time_field::Deref(std::get<1>(a)) == ::dessser::gen::event_time_field::Deref(std::get<1>(b)); // DurationField
    case 2: return ::dessser::gen::event_time_field::Deref(std::get<2>(a)) == ::dessser::gen::event_time_field::Deref(std::get<2>(b)); // StopField
  };
  return false;
}
inline bool operator!=(t52e26a57572ca91d707cdc0b7b472229 const &a, t52e26a57572ca91d707cdc0b7b472229 const &b) {
  return !operator==(a, b);
}
enum Constr_t52e26a57572ca91d707cdc0b7b472229 {
  DurationConst,
  DurationField,
  StopField,
};

inline std::ostream &operator<<(std::ostream &os, t52e26a57572ca91d707cdc0b7b472229 const &v) {
  switch (v.index()) {
    case 0: os << "DurationConst " << std::get<0>(v); break;
    case 1: os << "DurationField " << std::get<1>(v); break;
    case 2: os << "StopField " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t52e26a57572ca91d707cdc0b7b472229> const v) { os << *v; return os; }

struct t : public std::tuple<
  dessser::gen::event_time_field::t_ext,
  ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229
> {
  using tuple::tuple;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::event_time_field::Deref(std::get<0>(a)) == ::dessser::gen::event_time_field::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const t) { os << *t; return os; }

struct tcc7976c4e7ba96ee361470d862fd2d95 : public std::tuple<
  ::dessser::gen::event_time::t,
  Pointer
> {
  using tuple::tuple;
  tcc7976c4e7ba96ee361470d862fd2d95(std::tuple<::dessser::gen::event_time::t, Pointer> p)
    : std::tuple<::dessser::gen::event_time::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcc7976c4e7ba96ee361470d862fd2d95 const &a, tcc7976c4e7ba96ee361470d862fd2d95 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcc7976c4e7ba96ee361470d862fd2d95 const &a, tcc7976c4e7ba96ee361470d862fd2d95 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tcc7976c4e7ba96ee361470d862fd2d95 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tcc7976c4e7ba96ee361470d862fd2d95> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::event_time::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::event_time::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::event_time::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
