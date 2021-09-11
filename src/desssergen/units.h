#ifndef DESSSER_GEN_units
#define DESSSER_GEN_units
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::units {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t91f2e36eeb48a24e3d0e81b8fc2b2ee3 : public std::tuple<
  double,
  bool
> {
  using tuple::tuple;
  t91f2e36eeb48a24e3d0e81b8fc2b2ee3(std::tuple<double, bool> p)
    : std::tuple<double, bool>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t91f2e36eeb48a24e3d0e81b8fc2b2ee3 const &a, t91f2e36eeb48a24e3d0e81b8fc2b2ee3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t91f2e36eeb48a24e3d0e81b8fc2b2ee3 const &a, t91f2e36eeb48a24e3d0e81b8fc2b2ee3 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t91f2e36eeb48a24e3d0e81b8fc2b2ee3 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct tf1e686582fa50fe4bb8d464a3c3b3553 : public std::tuple<
  std::string,
  ::dessser::gen::units::t91f2e36eeb48a24e3d0e81b8fc2b2ee3
> {
  using tuple::tuple;
  tf1e686582fa50fe4bb8d464a3c3b3553(std::tuple<std::string, ::dessser::gen::units::t91f2e36eeb48a24e3d0e81b8fc2b2ee3> p)
    : std::tuple<std::string, ::dessser::gen::units::t91f2e36eeb48a24e3d0e81b8fc2b2ee3>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf1e686582fa50fe4bb8d464a3c3b3553 const &a, tf1e686582fa50fe4bb8d464a3c3b3553 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf1e686582fa50fe4bb8d464a3c3b3553 const &a, tf1e686582fa50fe4bb8d464a3c3b3553 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf1e686582fa50fe4bb8d464a3c3b3553 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

typedef Arr<::dessser::gen::units::tf1e686582fa50fe4bb8d464a3c3b3553> t;
struct tf6138ae5919ddcb1cb9a935a9dc7190a : public std::tuple<
  t,
  Pointer
> {
  using tuple::tuple;
  tf6138ae5919ddcb1cb9a935a9dc7190a(std::tuple<t, Pointer> p)
    : std::tuple<t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf6138ae5919ddcb1cb9a935a9dc7190a const &a, tf6138ae5919ddcb1cb9a935a9dc7190a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf6138ae5919ddcb1cb9a935a9dc7190a const &a, tf6138ae5919ddcb1cb9a935a9dc7190a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf6138ae5919ddcb1cb9a935a9dc7190a const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<::dessser::gen::units::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
