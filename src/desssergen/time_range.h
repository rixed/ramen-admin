#ifndef DESSSER_GEN_time_range
#define DESSSER_GEN_time_range
#include <arpa/inet.h>
#include <functional>
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
inline bool operator==(tf2b1e55baf84ce749ce34e373ad06db6 const &a, tf2b1e55baf84ce749ce34e373ad06db6 const &b) {
  return a.growing == b.growing && a.since == b.since && a.until == b.until;
}

inline bool operator!=(tf2b1e55baf84ce749ce34e373ad06db6 const &a, tf2b1e55baf84ce749ce34e373ad06db6 const &b) {
  return !operator==(a, b);
}
typedef Arr<::dessser::gen::time_range::tf2b1e55baf84ce749ce34e373ad06db6> t;
typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<::dessser::gen::time_range::t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
