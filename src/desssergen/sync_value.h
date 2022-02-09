#ifndef DESSSER_GEN_sync_value
#define DESSSER_GEN_sync_value
#include <functional>
#include <memory>
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
#include "desssergen/pivot.h"
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
inline bool operator==(tuple const &a, tuple const &b) {
  return a.skipped == b.skipped && ::dessser::gen::raql_value::Deref(a.values) == ::dessser::gen::raql_value::Deref(b.values);
}

inline bool operator!=(tuple const &a, tuple const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tuple const &r) {
  os << '{';
  os << "skipped:" << r.skipped << ',';
  os << "values:" << r.values;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tuple> const r) { os << *r; return os; }

struct tbf54298650775373958fa9b35bb96a35 : public std::tuple<
  double,
  uint32_t,
  std::string
> {
  using tuple::tuple;
};
inline bool operator==(tbf54298650775373958fa9b35bb96a35 const &a, tbf54298650775373958fa9b35bb96a35 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(tbf54298650775373958fa9b35bb96a35 const &a, tbf54298650775373958fa9b35bb96a35 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tbf54298650775373958fa9b35bb96a35 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tbf54298650775373958fa9b35bb96a35> const t) { os << *t; return os; }

struct t : public std::variant<
  ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35, // Error
  dessser::gen::worker::t_ext, // Worker
  dessser::gen::retention::t_ext, // Retention
  dessser::gen::time_range::t_ext, // TimeRange
  Arr<std::shared_ptr<::dessser::gen::sync_value::tuple> >, // Tuples
  dessser::gen::raql_value::t_ext, // RamenValue
  Arr<dessser::gen::rc_entry::t_ext>, // TargetConfig
  dessser::gen::source_info::t_ext, // SourceInfo
  dessser::gen::runtime_stats::t_ext, // RuntimeStats
  dessser::gen::replay::t_ext, // Replay
  dessser::gen::replayer::t_ext, // Replayer
  dessser::gen::replay_request::t_ext, // ReplayRequest
  dessser::gen::alert::t_ext, // Alert
  dessser::gen::pivot::t_ext, // Pivot
  dessser::gen::output_specs::t_ext, // OutputSpecs
  dessser::gen::dashboard_widget::t_ext, // DashboardWidget
  dessser::gen::alerting_contact::t_ext, // AlertingContact
  dessser::gen::alerting_notification::t_ext, // Notification
  dessser::gen::alerting_delivery_status::t_ext, // DeliveryStatus
  dessser::gen::alerting_log::t_ext, // IncidentLog
  dessser::gen::alerting_inhibition::t_ext // Inhibition
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 21 };
};

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
    case 13: return ::dessser::gen::pivot::Deref(std::get<13>(a)) == ::dessser::gen::pivot::Deref(std::get<13>(b)); // Pivot
    case 14: return ::dessser::gen::output_specs::Deref(std::get<14>(a)) == ::dessser::gen::output_specs::Deref(std::get<14>(b)); // OutputSpecs
    case 15: return ::dessser::gen::dashboard_widget::Deref(std::get<15>(a)) == ::dessser::gen::dashboard_widget::Deref(std::get<15>(b)); // DashboardWidget
    case 16: return ::dessser::gen::alerting_contact::Deref(std::get<16>(a)) == ::dessser::gen::alerting_contact::Deref(std::get<16>(b)); // AlertingContact
    case 17: return ::dessser::gen::alerting_notification::Deref(std::get<17>(a)) == ::dessser::gen::alerting_notification::Deref(std::get<17>(b)); // Notification
    case 18: return ::dessser::gen::alerting_delivery_status::Deref(std::get<18>(a)) == ::dessser::gen::alerting_delivery_status::Deref(std::get<18>(b)); // DeliveryStatus
    case 19: return ::dessser::gen::alerting_log::Deref(std::get<19>(a)) == ::dessser::gen::alerting_log::Deref(std::get<19>(b)); // IncidentLog
    case 20: return ::dessser::gen::alerting_inhibition::Deref(std::get<20>(a)) == ::dessser::gen::alerting_inhibition::Deref(std::get<20>(b)); // Inhibition
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
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
  Pivot,
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
    case 13: os << "Pivot " << std::get<13>(v); break;
    case 14: os << "OutputSpecs " << std::get<14>(v); break;
    case 15: os << "DashboardWidget " << std::get<15>(v); break;
    case 16: os << "AlertingContact " << std::get<16>(v); break;
    case 17: os << "Notification " << std::get<17>(v); break;
    case 18: os << "DeliveryStatus " << std::get<18>(v); break;
    case 19: os << "IncidentLog " << std::get<19>(v); break;
    case 20: os << "Inhibition " << std::get<20>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t69580374758c5cd49d653ee83c7fa90f : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_value::tuple> ,
  Pointer
> {
  using tuple::tuple;
  t69580374758c5cd49d653ee83c7fa90f(std::tuple<std::shared_ptr<::dessser::gen::sync_value::tuple> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_value::tuple> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t69580374758c5cd49d653ee83c7fa90f const &a, t69580374758c5cd49d653ee83c7fa90f const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t69580374758c5cd49d653ee83c7fa90f const &a, t69580374758c5cd49d653ee83c7fa90f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t69580374758c5cd49d653ee83c7fa90f const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t69580374758c5cd49d653ee83c7fa90f> const t) { os << *t; return os; }

struct t15098b8456ebfe3bc6bbe8b1695dacf3 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_value::t> ,
  Pointer
> {
  using tuple::tuple;
  t15098b8456ebfe3bc6bbe8b1695dacf3(std::tuple<std::shared_ptr<::dessser::gen::sync_value::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_value::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t15098b8456ebfe3bc6bbe8b1695dacf3 const &a, t15098b8456ebfe3bc6bbe8b1695dacf3 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t15098b8456ebfe3bc6bbe8b1695dacf3 const &a, t15098b8456ebfe3bc6bbe8b1695dacf3 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t15098b8456ebfe3bc6bbe8b1695dacf3 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t15098b8456ebfe3bc6bbe8b1695dacf3> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::tuple> ,Pointer)> tuple_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_value::tuple> )> tuple_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_value::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_value::t69580374758c5cd49d653ee83c7fa90f(Pointer)> tuple_of_row_binary;
extern std::function<::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3(Pointer)> of_row_binary;
extern std::function<::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
