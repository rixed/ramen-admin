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
struct tbc074f24e1fc732e4a138e805dac931f {
  bool growing;
  double since;
  double until;
  tbc074f24e1fc732e4a138e805dac931f(bool growing_, double since_, double until_) : growing(growing_), since(since_), until(until_) {}
  tbc074f24e1fc732e4a138e805dac931f() = default;
  bool operator==(tbc074f24e1fc732e4a138e805dac931f const &other) const {
    return growing == other.growing && since == other.since && until == other.until;
  }
};
inline std::ostream &operator<<(std::ostream &os, tbc074f24e1fc732e4a138e805dac931f const &r) {
  os << '{';
  os << "growing:" << r.growing << ',';
  os << "since:" << r.since << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}

typedef Arr<::dessser::gen::time_range::tbc074f24e1fc732e4a138e805dac931f> t;
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
