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
struct tf32344673bb22ed5e3097268b352679e {
  double since;
  double until;
  bool growing;
  bool operator==(tf32344673bb22ed5e3097268b352679e const &other) const {
    return since == other.since && until == other.until && growing == other.growing;
  }
};
inline std::ostream &operator<<(std::ostream &os, tf32344673bb22ed5e3097268b352679e const &r) {
  os << '{';
  os << "since:" << r.since << ',';
  os << "until:" << r.until << ',';
  os << "growing:" << r.growing;
  os << '}';
  return os;
}

typedef Arr<tf32344673bb22ed5e3097268b352679e> t;
typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary;
typedef t t_ext;

}
#endif
