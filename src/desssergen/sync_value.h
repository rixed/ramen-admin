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
#include "desssergen/rc_entry.h"
#include "desssergen/raql_value.h"
#include "desssergen/raql_value.h"
#include "desssergen/time_range.h"
#include "desssergen/retention.h"
#include "desssergen/worker.h"

namespace dessser::gen::sync_value {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tuple {
  uint32_t skipped;
  dessser::gen::raql_value::t_ext values;
  tuple(uint32_t skipped_, dessser::gen::raql_value::t_ext values_) : skipped(skipped_), values(values_) {}
  tuple() = default;
};
inline std::ostream &operator<<(std::ostream &os, tuple const &r) {
  os << '{';
  os << "skipped:" << r.skipped << ',';
  os << "values:" << ::dessser::gen::raql_value::Deref(r.values);
  os << '}';
  return os;
}
inline bool operator==(tuple const &a, tuple const &b) {
  return a.skipped == b.skipped && ::dessser::gen::raql_value::Deref(a.values) == ::dessser::gen::raql_value::Deref(b.values);
}

inline bool operator!=(tuple const &a, tuple const &b) {
  return !operator==(a, b);
}
struct t4ec0da5161c08f29f8aed40b17a73ef5 : public std::tuple<
  double,
  uint32_t,
  std::string
> {
  using tuple::tuple;
};
inline bool operator==(t4ec0da5161c08f29f8aed40b17a73ef5 const &a, t4ec0da5161c08f29f8aed40b17a73ef5 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t4ec0da5161c08f29f8aed40b17a73ef5 const &a, t4ec0da5161c08f29f8aed40b17a73ef5 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4ec0da5161c08f29f8aed40b17a73ef5 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t : public std::variant<
  ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5, // Error
  dessser::gen::worker::t_ext, // Worker
  dessser::gen::retention::t_ext, // Retention
  dessser::gen::time_range::t_ext, // TimeRange
  Arr<::dessser::gen::sync_value::tuple*>, // Tuples
  dessser::gen::raql_value::t_ext, // RamenValue
  Arr<dessser::gen::rc_entry::t_ext>, // TargetConfig
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
    case 1: os << "Worker " << ::dessser::gen::worker::Deref(std::get<1>(v)); break;
    case 2: os << "Retention " << ::dessser::gen::retention::Deref(std::get<2>(v)); break;
    case 3: os << "TimeRange " << ::dessser::gen::time_range::Deref(std::get<3>(v)); break;
    case 4: os << "Tuples " << std::get<4>(v); break;
    case 5: os << "RamenValue " << ::dessser::gen::raql_value::Deref(std::get<5>(v)); break;
    case 6: os << "TargetConfig " << std::get<6>(v); break;
    case 7: os << "SourceInfo " << ::dessser::gen::source_info::Deref(std::get<7>(v)); break;
    case 8: os << "RuntimeStats " << ::dessser::gen::runtime_stats::Deref(std::get<8>(v)); break;
    case 9: os << "Replay " << ::dessser::gen::replay::Deref(std::get<9>(v)); break;
    case 10: os << "Replayer " << ::dessser::gen::replayer::Deref(std::get<10>(v)); break;
    case 11: os << "ReplayRequest " << ::dessser::gen::replay_request::Deref(std::get<11>(v)); break;
    case 12: os << "Alert " << ::dessser::gen::alert::Deref(std::get<12>(v)); break;
    case 13: os << "OutputSpecs " << ::dessser::gen::output_specs::Deref(std::get<13>(v)); break;
    case 14: os << "DashboardWidget " << ::dessser::gen::dashboard_widget::Deref(std::get<14>(v)); break;
    case 15: os << "AlertingContact " << ::dessser::gen::alerting_contact::Deref(std::get<15>(v)); break;
    case 16: os << "Notification " << ::dessser::gen::alerting_notification::Deref(std::get<16>(v)); break;
    case 17: os << "DeliveryStatus " << ::dessser::gen::alerting_delivery_status::Deref(std::get<17>(v)); break;
    case 18: os << "IncidentLog " << ::dessser::gen::alerting_log::Deref(std::get<18>(v)); break;
    case 19: os << "Inhibition " << ::dessser::gen::alerting_inhibition::Deref(std::get<19>(v)); break;
  }
  return os;
}

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Error
    case 1: return ::dessser::gen::worker::Deref(std::get<1>(a)) == ::dessser::gen::worker::Deref(std::get<1>(b)); // Worker
    case 2: return ::dessser::gen::retention::Deref(std::get<2>(a)) == ::dessser::gen::retention::Deref(std::get<2>(b)); // Retention
    case 3: return ::dessser::gen::time_range::Deref(std::get<3>(a)) == ::dessser::gen::time_range::Deref(std::get<3>(b)); // TimeRange
    case 4: return std::get<4>(a) == std::get<4>(b); // Tuples
    case 5: return ::dessser::gen::raql_value::Deref(std::get<5>(a)) == ::dessser::gen::raql_value::Deref(std::get<5>(b)); // RamenValue
    case 6: return std::get<6>(a) == std::get<6>(b); // TargetConfig
    case 7: return ::dessser::gen::source_info::Deref(std::get<7>(a)) == ::dessser::gen::source_info::Deref(std::get<7>(b)); // SourceInfo
    case 8: return ::dessser::gen::runtime_stats::Deref(std::get<8>(a)) == ::dessser::gen::runtime_stats::Deref(std::get<8>(b)); // RuntimeStats
    case 9: return ::dessser::gen::replay::Deref(std::get<9>(a)) == ::dessser::gen::replay::Deref(std::get<9>(b)); // Replay
    case 10: return ::dessser::gen::replayer::Deref(std::get<10>(a)) == ::dessser::gen::replayer::Deref(std::get<10>(b)); // Replayer
    case 11: return ::dessser::gen::replay_request::Deref(std::get<11>(a)) == ::dessser::gen::replay_request::Deref(std::get<11>(b)); // ReplayRequest
    case 12: return ::dessser::gen::alert::Deref(std::get<12>(a)) == ::dessser::gen::alert::Deref(std::get<12>(b)); // Alert
    case 13: return ::dessser::gen::output_specs::Deref(std::get<13>(a)) == ::dessser::gen::output_specs::Deref(std::get<13>(b)); // OutputSpecs
    case 14: return ::dessser::gen::dashboard_widget::Deref(std::get<14>(a)) == ::dessser::gen::dashboard_widget::Deref(std::get<14>(b)); // DashboardWidget
    case 15: return ::dessser::gen::alerting_contact::Deref(std::get<15>(a)) == ::dessser::gen::alerting_contact::Deref(std::get<15>(b)); // AlertingContact
    case 16: return ::dessser::gen::alerting_notification::Deref(std::get<16>(a)) == ::dessser::gen::alerting_notification::Deref(std::get<16>(b)); // Notification
    case 17: return ::dessser::gen::alerting_delivery_status::Deref(std::get<17>(a)) == ::dessser::gen::alerting_delivery_status::Deref(std::get<17>(b)); // DeliveryStatus
    case 18: return ::dessser::gen::alerting_log::Deref(std::get<18>(a)) == ::dessser::gen::alerting_log::Deref(std::get<18>(b)); // IncidentLog
    case 19: return ::dessser::gen::alerting_inhibition::Deref(std::get<19>(a)) == ::dessser::gen::alerting_inhibition::Deref(std::get<19>(b)); // Inhibition
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t750a477200d5d3da6135579fb33c1597 : public std::tuple<
  ::dessser::gen::sync_value::tuple*,
  Pointer
> {
  using tuple::tuple;
  t750a477200d5d3da6135579fb33c1597(std::tuple<::dessser::gen::sync_value::tuple*, Pointer> p)
    : std::tuple<::dessser::gen::sync_value::tuple*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t750a477200d5d3da6135579fb33c1597 const &a, t750a477200d5d3da6135579fb33c1597 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t750a477200d5d3da6135579fb33c1597 const &a, t750a477200d5d3da6135579fb33c1597 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t750a477200d5d3da6135579fb33c1597 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct tda69ebe48ca6c803b31d09dc9d524987 : public std::tuple<
  ::dessser::gen::sync_value::t*,
  Pointer
> {
  using tuple::tuple;
  tda69ebe48ca6c803b31d09dc9d524987(std::tuple<::dessser::gen::sync_value::t*, Pointer> p)
    : std::tuple<::dessser::gen::sync_value::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tda69ebe48ca6c803b31d09dc9d524987 const &a, tda69ebe48ca6c803b31d09dc9d524987 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tda69ebe48ca6c803b31d09dc9d524987 const &a, tda69ebe48ca6c803b31d09dc9d524987 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tda69ebe48ca6c803b31d09dc9d524987 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_value::tuple*,Pointer)> tuple_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_value::tuple*)> tuple_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_value::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597(Pointer)> tuple_of_row_binary;
extern std::function<::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
