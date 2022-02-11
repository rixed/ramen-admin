#ifndef DESSSER_GEN_fieldmask
#define DESSSER_GEN_fieldmask
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::fieldmask {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::string t;
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
extern std::function<Pointer(t const &,Pointer &)> to_row_binary;
extern std::function<Size(t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::fieldmask::ta30293a82943182cab78182f33b18016(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::fieldmask::ta30293a82943182cab78182f33b18016(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
