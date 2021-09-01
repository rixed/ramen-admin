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
struct tde68d14dd253c0005e157424dd8fc48d : public std::tuple<
  double,
  uint32_t,
  std::string
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, tde68d14dd253c0005e157424dd8fc48d const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t953aab1fe1aba5b6c1cf1af5981bef40 {
  uint32_t skipped;
  Bytes values;
  t953aab1fe1aba5b6c1cf1af5981bef40(uint32_t skipped_, Bytes values_) : skipped(skipped_), values(values_) {}
  t953aab1fe1aba5b6c1cf1af5981bef40() = default;
  bool operator==(t953aab1fe1aba5b6c1cf1af5981bef40 const &other) const {
    return skipped == other.skipped && values == other.values;
  }
};
inline std::ostream &operator<<(std::ostream &os, t953aab1fe1aba5b6c1cf1af5981bef40 const &r) {
  os << '{';
  os << "skipped:" << r.skipped << ',';
  os << "values:" << r.values;
  os << '}';
  return os;
}

struct t : public std::variant<
  ::dessser::gen::sync_value::tde68d14dd253c0005e157424dd8fc48d, // Error
  dessser::gen::worker::t_ext, // Worker
  dessser::gen::retention::t_ext, // Retention
  dessser::gen::time_range::t_ext, // TimeRange
  Arr<::dessser::gen::sync_value::t953aab1fe1aba5b6c1cf1af5981bef40>, // Tuples
  dessser::gen::raql_value::t_ext, // RamenValue
  dessser::gen::target_config::t_ext, // TargetConfig
  dessser::gen::source_info::t_ext, // SourceInfo
  dessser::gen::runtime_stats::t_ext, // RuntimeStats
  dessser::gen::replay::t_ext, // Replay
  dessser::gen::replayer::t_ext, // Replayer
  dessser::gen::replay_request::t_ext, // ReplayRequest
  dessser::gen::alert::t_ext, // Alert
  dessser::gen::output_specs::t_ext, // OutputSpecs
  dessser::gen::dashboard_widget::t_ext, // DashboardWidget
  dessser::gen::alerting_contact::t_ext, // AlertingContact
  dessser::gen::alerting_notification::t_ext, // Notification
  dessser::gen::alerting_delivery_status::t_ext, // DeliveryStatus
  dessser::gen::alerting_log::t_ext, // IncidentLog
  dessser::gen::alerting_inhibition::t_ext // Inhibition
> { using variant::variant; };

enum Constr_t {
  Error,
  Worker,
  Retention,
  TimeRange,
  Tuples,
  RamenValue,
  TargetConfig,
  SourceInfo,
  RuntimeStats,
  Replay,
  Replayer,
  ReplayRequest,
  Alert,
  OutputSpecs,
  DashboardWidget,
  AlertingContact,
  Notification,
  DeliveryStatus,
  IncidentLog,
  Inhibition,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Error " << std::get<0>(v); break;
    case 1: os << "Worker " << std::get<1>(v); break;
    case 2: os << "Retention " << std::get<2>(v); break;
    case 3: os << "TimeRange " << std::get<3>(v); break;
    case 4: os << "Tuples " << std::get<4>(v); break;
    case 5: os << "RamenValue " << std::get<5>(v); break;
    case 6: os << "TargetConfig " << std::get<6>(v); break;
    case 7: os << "SourceInfo " << std::get<7>(v); break;
    case 8: os << "RuntimeStats " << std::get<8>(v); break;
    case 9: os << "Replay " << std::get<9>(v); break;
    case 10: os << "Replayer " << std::get<10>(v); break;
    case 11: os << "ReplayRequest " << std::get<11>(v); break;
    case 12: os << "Alert " << std::get<12>(v); break;
    case 13: os << "OutputSpecs " << std::get<13>(v); break;
    case 14: os << "DashboardWidget " << std::get<14>(v); break;
    case 15: os << "AlertingContact " << std::get<15>(v); break;
    case 16: os << "Notification " << std::get<16>(v); break;
    case 17: os << "DeliveryStatus " << std::get<17>(v); break;
    case 18: os << "IncidentLog " << std::get<18>(v); break;
    case 19: os << "Inhibition " << std::get<19>(v); break;
  }
  return os;
}

typedef std::tuple<
  ::dessser::gen::sync_value::t*,
  Pointer
> t5a4f9375f61f65c3413a01c7d782b657;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_value::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
