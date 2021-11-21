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
struct tf2b1e55baf84ce749ce34e373ad06db6 {
  bool growing;
  double since;
  double until;
  tf2b1e55baf84ce749ce34e373ad06db6(bool growing_, double since_, double until_) : growing(growing_), since(since_), until(until_) {}
  tf2b1e55baf84ce749ce34e373ad06db6() = default;
};
inline std::ostream &operator<<(std::ostream &os, tf2b1e55baf84ce749ce34e373ad06db6 const &r) {
  os << '{';
  os << "growing:" << r.growing << ',';
  os << "since:" << r.since << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf2b1e55baf84ce749ce34e373ad06db6> const r) { os << *r; return os; }

inline bool operator==(tf2b1e55baf84ce749ce34e373ad06db6 const &a, tf2b1e55baf84ce749ce34e373ad06db6 const &b) {
  return a.growing == b.growing && a.since == b.since && a.until == b.until;
}

inline bool operator!=(tf2b1e55baf84ce749ce34e373ad06db6 const &a, tf2b1e55baf84ce749ce34e373ad06db6 const &b) {
  return !operator==(a, b);
}
typedef Arr<::dessser::gen::time_range::tf2b1e55baf84ce749ce34e373ad06db6> t;
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
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf6138ae5919ddcb1cb9a935a9dc7190a> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<::dessser::gen::time_range::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
