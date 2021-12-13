#ifndef DESSSER_GEN_units
#define DESSSER_GEN_units
#include <arpa/inet.h>
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
struct t269a713e7cffb6a948c359cf821188bc : public std::tuple<
  double,
  bool
> {
  using tuple::tuple;
  t269a713e7cffb6a948c359cf821188bc(std::tuple<double, bool> p)
    : std::tuple<double, bool>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t269a713e7cffb6a948c359cf821188bc const &a, t269a713e7cffb6a948c359cf821188bc const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t269a713e7cffb6a948c359cf821188bc const &a, t269a713e7cffb6a948c359cf821188bc const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t269a713e7cffb6a948c359cf821188bc const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t269a713e7cffb6a948c359cf821188bc> const t) { os << *t; return os; }

struct t6065e0c71fac083ca075217e1ad8299c : public std::tuple<
  std::string,
  ::dessser::gen::units::t269a713e7cffb6a948c359cf821188bc
> {
  using tuple::tuple;
  t6065e0c71fac083ca075217e1ad8299c(std::tuple<std::string, ::dessser::gen::units::t269a713e7cffb6a948c359cf821188bc> p)
    : std::tuple<std::string, ::dessser::gen::units::t269a713e7cffb6a948c359cf821188bc>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6065e0c71fac083ca075217e1ad8299c const &a, t6065e0c71fac083ca075217e1ad8299c const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6065e0c71fac083ca075217e1ad8299c const &a, t6065e0c71fac083ca075217e1ad8299c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t6065e0c71fac083ca075217e1ad8299c const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t6065e0c71fac083ca075217e1ad8299c> const t) { os << *t; return os; }

typedef Arr<::dessser::gen::units::t6065e0c71fac083ca075217e1ad8299c> t;
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
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer)> of_row_binary;
extern std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(t&,Pointer)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
