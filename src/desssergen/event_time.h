#ifndef DESSSER_GEN_event_time
#define DESSSER_GEN_event_time
#include <arpa/inet.h>
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
struct te56444ea7a5883cbac09e8c474932330 : public std::variant<
  double, // DurationConst
  dessser::gen::event_time_field::t_ext, // DurationField
  dessser::gen::event_time_field::t_ext // StopField
> { using variant::variant; };

inline bool operator==(te56444ea7a5883cbac09e8c474932330 const &a, te56444ea7a5883cbac09e8c474932330 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // DurationConst
    case 1: return ::dessser::gen::event_time_field::Deref(std::get<1>(a)) == ::dessser::gen::event_time_field::Deref(std::get<1>(b)); // DurationField
    case 2: return ::dessser::gen::event_time_field::Deref(std::get<2>(a)) == ::dessser::gen::event_time_field::Deref(std::get<2>(b)); // StopField
  };
  return false;
}
inline bool operator!=(te56444ea7a5883cbac09e8c474932330 const &a, te56444ea7a5883cbac09e8c474932330 const &b) {
  return !operator==(a, b);
}
enum Constr_te56444ea7a5883cbac09e8c474932330 {
  DurationConst,
  DurationField,
  StopField,
};

inline std::ostream &operator<<(std::ostream &os, te56444ea7a5883cbac09e8c474932330 const &v) {
  switch (v.index()) {
    case 0: os << "DurationConst " << std::get<0>(v); break;
    case 1: os << "DurationField " << std::get<1>(v); break;
    case 2: os << "StopField " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te56444ea7a5883cbac09e8c474932330> const v) { os << *v; return os; }

struct t : public std::tuple<
  dessser::gen::event_time_field::t_ext,
  ::dessser::gen::event_time::te56444ea7a5883cbac09e8c474932330
> {
  using tuple::tuple;
  t(std::tuple<dessser::gen::event_time_field::t_ext, ::dessser::gen::event_time::te56444ea7a5883cbac09e8c474932330> p)
    : std::tuple<dessser::gen::event_time_field::t_ext, ::dessser::gen::event_time::te56444ea7a5883cbac09e8c474932330>(std::get<0>(p), std::get<1>(p)) {}
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

struct tc5af49eea21f544f0c497da6c5af45dd : public std::tuple<
  std::shared_ptr<::dessser::gen::event_time::t> ,
  Pointer
> {
  using tuple::tuple;
  tc5af49eea21f544f0c497da6c5af45dd(std::tuple<std::shared_ptr<::dessser::gen::event_time::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::event_time::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc5af49eea21f544f0c497da6c5af45dd const &a, tc5af49eea21f544f0c497da6c5af45dd const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc5af49eea21f544f0c497da6c5af45dd const &a, tc5af49eea21f544f0c497da6c5af45dd const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc5af49eea21f544f0c497da6c5af45dd const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc5af49eea21f544f0c497da6c5af45dd> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::event_time::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::event_time::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::event_time::tc5af49eea21f544f0c497da6c5af45dd(Pointer)> of_row_binary;
extern std::function<::dessser::gen::event_time::tc5af49eea21f544f0c497da6c5af45dd(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::event_time::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
