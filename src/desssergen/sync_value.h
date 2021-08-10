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
struct v_07ada2d1213092d3daac69767fb06478 : public std::tuple<
  double,
  uint32_t,
  std::string
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_07ada2d1213092d3daac69767fb06478 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct c1f1a0a3126e49b1726165cc5452d8cb {
  uint32_t skipped;
  Bytes values;
  bool operator==(c1f1a0a3126e49b1726165cc5452d8cb const &other) const {
    return skipped == other.skipped && values == other.values;
  }
};
std::ostream &operator<<(std::ostream &os, c1f1a0a3126e49b1726165cc5452d8cb const &r) {
  os << '{';
  os << "skipped:" << r.skipped << ',';
  os << "values:" << r.values;
  os << '}';
  return os;
}

struct t : public std::variant<
  v_07ada2d1213092d3daac69767fb06478,
  *worker,
  *retention,
  *time_range,
  Arr<c1f1a0a3126e49b1726165cc5452d8cb>,
  *raql_value,
  *target_config,
  *source_info,
  *runtime_stats,
  *replay,
  *replayer,
  *replay_request,
  *alert,
  *output_specs,
  *dashboard_widget,
  *alerting_contact,
  *alerting_notification,
  *alerting_delivery_status,
  *alerting_log,
  *alerting_inhibition
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
    case 8: os << std::get<8>(v); break;
    case 9: os << std::get<9>(v); break;
    case 10: os << std::get<10>(v); break;
    case 11: os << std::get<11>(v); break;
    case 12: os << std::get<12>(v); break;
    case 13: os << std::get<13>(v); break;
    case 14: os << std::get<14>(v); break;
    case 15: os << std::get<15>(v); break;
    case 16: os << std::get<16>(v); break;
    case 17: os << std::get<17>(v); break;
    case 18: os << std::get<18>(v); break;
    case 19: os << std::get<19>(v); break;
  }
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
