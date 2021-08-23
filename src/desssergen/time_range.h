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
struct tf7123493969c2e2f90159f6551344447 {
  bool growing;
  double since;
  double until;
  bool operator==(tf7123493969c2e2f90159f6551344447 const &other) const {
    return growing == other.growing && since == other.since && until == other.until;
  }
};
inline std::ostream &operator<<(std::ostream &os, tf7123493969c2e2f90159f6551344447 const &r) {
  os << '{';
  os << "growing:" << r.growing << ',';
  os << "since:" << r.since << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}

typedef Arr<::dessser::gen::time_range::tf7123493969c2e2f90159f6551344447> t;
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

}
#endif
