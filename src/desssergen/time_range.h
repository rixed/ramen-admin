#ifndef DESSSER_GEN_time_range
#define DESSSER_GEN_time_range
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::time_range {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t0a5f0f32f40c91bcfe721c5930f07dd9 {
  bool growing;
  double since;
  double until;
  t0a5f0f32f40c91bcfe721c5930f07dd9(bool growing_, double since_, double until_) : growing(growing_), since(since_), until(until_) {}
  t0a5f0f32f40c91bcfe721c5930f07dd9() = default;
};
inline bool operator==(t0a5f0f32f40c91bcfe721c5930f07dd9 const &a, t0a5f0f32f40c91bcfe721c5930f07dd9 const &b) {
  return a.growing == b.growing && a.since == b.since && a.until == b.until;
}

inline bool operator!=(t0a5f0f32f40c91bcfe721c5930f07dd9 const &a, t0a5f0f32f40c91bcfe721c5930f07dd9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t0a5f0f32f40c91bcfe721c5930f07dd9 const &r) {
  os << '{';
  os << "growing:" << r.growing << ',';
  os << "since:" << r.since << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0a5f0f32f40c91bcfe721c5930f07dd9> const r) { os << *r; return os; }

typedef Arr<::dessser::gen::time_range::t0a5f0f32f40c91bcfe721c5930f07dd9> t;
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
extern std::function<::dessser::gen::time_range::ta30293a82943182cab78182f33b18016(Pointer)> of_row_binary;
extern std::function<::dessser::gen::time_range::ta30293a82943182cab78182f33b18016(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(t&,Pointer)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
