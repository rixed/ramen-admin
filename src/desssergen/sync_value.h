#ifndef DESSSER_GEN_sync_value
#define DESSSER_GEN_sync_value
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/alerting_inhibition.h"
#include "desssergen/alerting_log.h"
#include "desssergen/alerting_delivery_status.h"
#include "desssergen/alerting_notification.h"
#include "desssergen/alerting_contact.h"
#include "desssergen/dashboard_widget.h"
#include "desssergen/output_specs.h"
#include "desssergen/alert.h"
#include "desssergen/replay_request.h"
#include "desssergen/replayer.h"
#include "desssergen/replay.h"
#include "desssergen/runtime_stats.h"
#include "desssergen/source_info.h"
#include "desssergen/target_config.h"
#include "desssergen/raql_value.h"
#include "desssergen/time_range.h"
#include "desssergen/retention.h"
#include "desssergen/worker.h"

namespace dessser::gen::sync_value {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t8503862224be821877d19a3abe14dd09 : public std::tuple<
  double,
  uint32_t,
  std::string
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t8503862224be821877d19a3abe14dd09 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct ta60101b15d1583586bdf843100adc51a {
  uint32_t skipped;
  Bytes values;
  bool operator==(ta60101b15d1583586bdf843100adc51a const &other) const {
    return skipped == other.skipped && values == other.values;
  }
};
inline std::ostream &operator<<(std::ostream &os, ta60101b15d1583586bdf843100adc51a const &r) {
  os << '{';
  os << "skipped:" << r.skipped << ',';
  os << "values:" << r.values;
  os << '}';
  return os;
}

struct t : public std::variant<
  t8503862224be821877d19a3abe14dd09,
  dessser::gen::worker::t_ext,
  dessser::gen::retention::t_ext,
  dessser::gen::time_range::t_ext,
  Arr<ta60101b15d1583586bdf843100adc51a>,
  dessser::gen::raql_value::t_ext,
  dessser::gen::target_config::t_ext,
  dessser::gen::source_info::t_ext,
  dessser::gen::runtime_stats::t_ext,
  dessser::gen::replay::t_ext,
  dessser::gen::replayer::t_ext,
  dessser::gen::replay_request::t_ext,
  dessser::gen::alert::t_ext,
  dessser::gen::output_specs::t_ext,
  dessser::gen::dashboard_widget::t_ext,
  dessser::gen::alerting_contact::t_ext,
  dessser::gen::alerting_notification::t_ext,
  dessser::gen::alerting_delivery_status::t_ext,
  dessser::gen::alerting_log::t_ext,
  dessser::gen::alerting_inhibition::t_ext
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
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
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t*,Pointer)> to_row_binary;
extern std::function<Size(t*)> sersize_of_row_binary;
extern std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
