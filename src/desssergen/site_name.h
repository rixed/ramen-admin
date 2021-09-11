#ifndef DESSSER_GEN_site_name
#define DESSSER_GEN_site_name
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::site_name {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::string t;
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
extern std::function<Pointer(t,Pointer)> to_row_binary;
extern std::function<Size(t)> sersize_of_row_binary;
extern std::function<::dessser::gen::site_name::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
