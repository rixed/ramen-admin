#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct v_13778ae74488ba3447259adc9816e04e {
  bool enabled;
  bool debug;
  double report_period;
  *file_path cwd;
  Arr<*program_run_parameter> params;
  std::string on_site;
  bool automatic;
  bool operator==(v_13778ae74488ba3447259adc9816e04e const &other) const {
    return enabled == other.enabled && debug == other.debug && report_period == other.report_period && cwd == other.cwd && params == other.params && on_site == other.on_site && automatic == other.automatic;
  }
};
std::ostream &operator<<(std::ostream &os, v_13778ae74488ba3447259adc9816e04e const &r) {
  os << '{';
  os << "enabled:" << r.enabled << ',';
  os << "debug:" << r.debug << ',';
  os << "report_period:" << r.report_period << ',';
  os << "cwd:" << r.cwd << ',';
  os << "params:" << r.params << ',';
  os << "on_site:" << r.on_site << ',';
  os << "automatic:" << r.automatic;
  os << '}';
  return os;
}

typedef std::tuple<
  *program_name,
  v_13778ae74488ba3447259adc9816e04e
> cc18b22dfb71145a271a6ff24f6a72b1;

typedef std::tuple<
  Arr<cc18b22dfb71145a271a6ff24f6a72b1>,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(Arr<cc18b22dfb71145a271a6ff24f6a72b1>&,Pointer)> to_row_binary;
std::function<Size(Arr<cc18b22dfb71145a271a6ff24f6a72b1>&)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
