#ifndef DESSSER_GEN_units
#define DESSSER_GEN_units
#include <functional>
#include <memory>
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
struct t50c85374c162cc57eaa3ade6dd674504 : public std::tuple<
  double,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(t50c85374c162cc57eaa3ade6dd674504 const &a, t50c85374c162cc57eaa3ade6dd674504 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t50c85374c162cc57eaa3ade6dd674504 const &a, t50c85374c162cc57eaa3ade6dd674504 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t50c85374c162cc57eaa3ade6dd674504 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t50c85374c162cc57eaa3ade6dd674504> const t) { os << *t; return os; }

struct tb3d0892aa873a8666f6c0a9f27b98c5f : public std::tuple<
  std::string,
  ::dessser::gen::units::t50c85374c162cc57eaa3ade6dd674504
> {
  using tuple::tuple;
};
inline bool operator==(tb3d0892aa873a8666f6c0a9f27b98c5f const &a, tb3d0892aa873a8666f6c0a9f27b98c5f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb3d0892aa873a8666f6c0a9f27b98c5f const &a, tb3d0892aa873a8666f6c0a9f27b98c5f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb3d0892aa873a8666f6c0a9f27b98c5f const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tb3d0892aa873a8666f6c0a9f27b98c5f> const t) { os << *t; return os; }

typedef Arr<::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f> t;
struct ta30293a82943182cab78182f33b18016 : public std::tuple<
  t,
  Pointer
> {
  using tuple::tuple;
  ta30293a82943182cab78182f33b18016(std::tuple<t, Pointer> p)
    : std::tuple<t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta30293a82943182cab78182f33b18016 const &a, ta30293a82943182cab78182f33b18016 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta30293a82943182cab78182f33b18016 const &a, ta30293a82943182cab78182f33b18016 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta30293a82943182cab78182f33b18016 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta30293a82943182cab78182f33b18016> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t &,Pointer &)> to_row_binary;
extern std::function<Size(t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
