#include <algorithm>
#include <arpa/inet.h>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <random>
#include <tuple>
#include <utility>
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
#include "desssergen/time_range.h"
#include "desssergen/retention.h"
#include "desssergen/worker.h"


namespace dessser::gen::sync_value {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct tuple {
  uint32_t skipped;
  Bytes values;
  tuple(uint32_t skipped_, Bytes values_) : skipped(skipped_), values(values_) {}
  tuple() = default;
};
inline bool operator==(tuple const &a, tuple const &b) {
  return a.skipped == b.skipped && a.values == b.values;
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
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t883c6ffea47c0d7b950fe35881e3d737 const &a, t883c6ffea47c0d7b950fe35881e3d737 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t883c6ffea47c0d7b950fe35881e3d737 const &a, t883c6ffea47c0d7b950fe35881e3d737 const &b) {
  return !operator==(a, b);
}
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
  return !operator==(a, b);
}
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return !operator==(a, b);
}
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
  return !operator==(a, b);
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
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7609d344c1ba69d0f80fec236d4c216b const &a, t7609d344c1ba69d0f80fec236d4c216b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7609d344c1ba69d0f80fec236d4c216b const &a, t7609d344c1ba69d0f80fec236d4c216b const &b) {
  return !operator==(a, b);
}
struct tf568409f41c9c0a265f7302110fc9084 : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  tf568409f41c9c0a265f7302110fc9084(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf568409f41c9c0a265f7302110fc9084 const &a, tf568409f41c9c0a265f7302110fc9084 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf568409f41c9c0a265f7302110fc9084 const &a, tf568409f41c9c0a265f7302110fc9084 const &b) {
  return !operator==(a, b);
}
struct t5375de390f9cb5ae2ee5880ea1674828 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t5375de390f9cb5ae2ee5880ea1674828(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5375de390f9cb5ae2ee5880ea1674828 const &a, t5375de390f9cb5ae2ee5880ea1674828 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5375de390f9cb5ae2ee5880ea1674828 const &a, t5375de390f9cb5ae2ee5880ea1674828 const &b) {
  return !operator==(a, b);
}
struct t9833ef1b01f7f7d46ad878fb0cee5e03 : public std::tuple<
  dessser::gen::worker::t_ext,
  Pointer
> {
  using tuple::tuple;
  t9833ef1b01f7f7d46ad878fb0cee5e03(std::tuple<dessser::gen::worker::t_ext, Pointer> p)
    : std::tuple<dessser::gen::worker::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9833ef1b01f7f7d46ad878fb0cee5e03 const &a, t9833ef1b01f7f7d46ad878fb0cee5e03 const &b) {
  return ::dessser::gen::worker::Deref(std::get<0>(a)) == ::dessser::gen::worker::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9833ef1b01f7f7d46ad878fb0cee5e03 const &a, t9833ef1b01f7f7d46ad878fb0cee5e03 const &b) {
  return !operator==(a, b);
}
struct t6c4cb47132b52abf02e5ac7e5e40d7ce : public std::tuple<
  dessser::gen::retention::t_ext,
  Pointer
> {
  using tuple::tuple;
  t6c4cb47132b52abf02e5ac7e5e40d7ce(std::tuple<dessser::gen::retention::t_ext, Pointer> p)
    : std::tuple<dessser::gen::retention::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6c4cb47132b52abf02e5ac7e5e40d7ce const &a, t6c4cb47132b52abf02e5ac7e5e40d7ce const &b) {
  return ::dessser::gen::retention::Deref(std::get<0>(a)) == ::dessser::gen::retention::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6c4cb47132b52abf02e5ac7e5e40d7ce const &a, t6c4cb47132b52abf02e5ac7e5e40d7ce const &b) {
  return !operator==(a, b);
}
struct t12b2d6d50de8cb59e40a3787e527a60e : public std::tuple<
  dessser::gen::time_range::t_ext,
  Pointer
> {
  using tuple::tuple;
  t12b2d6d50de8cb59e40a3787e527a60e(std::tuple<dessser::gen::time_range::t_ext, Pointer> p)
    : std::tuple<dessser::gen::time_range::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12b2d6d50de8cb59e40a3787e527a60e const &a, t12b2d6d50de8cb59e40a3787e527a60e const &b) {
  return ::dessser::gen::time_range::Deref(std::get<0>(a)) == ::dessser::gen::time_range::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12b2d6d50de8cb59e40a3787e527a60e const &a, t12b2d6d50de8cb59e40a3787e527a60e const &b) {
  return !operator==(a, b);
}
struct t669b86c36c6ec2a214e7091f475517d7 : public std::tuple<
  Lst<::dessser::gen::sync_value::tuple*>,
  Pointer
> {
  using tuple::tuple;
  t669b86c36c6ec2a214e7091f475517d7(std::tuple<Lst<::dessser::gen::sync_value::tuple*>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::sync_value::tuple*>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t669b86c36c6ec2a214e7091f475517d7 const &a, t669b86c36c6ec2a214e7091f475517d7 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t669b86c36c6ec2a214e7091f475517d7 const &a, t669b86c36c6ec2a214e7091f475517d7 const &b) {
  return !operator==(a, b);
}
struct td46b7b5194a84c2e11400d9ca5d84700 : public std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> {
  using tuple::tuple;
  td46b7b5194a84c2e11400d9ca5d84700(std::tuple<dessser::gen::raql_value::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_value::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td46b7b5194a84c2e11400d9ca5d84700 const &a, td46b7b5194a84c2e11400d9ca5d84700 const &b) {
  return ::dessser::gen::raql_value::Deref(std::get<0>(a)) == ::dessser::gen::raql_value::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td46b7b5194a84c2e11400d9ca5d84700 const &a, td46b7b5194a84c2e11400d9ca5d84700 const &b) {
  return !operator==(a, b);
}
struct t00766d71c0212d72438b86a52d918f8d : public std::tuple<
  Lst<dessser::gen::rc_entry::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t00766d71c0212d72438b86a52d918f8d(std::tuple<Lst<dessser::gen::rc_entry::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::rc_entry::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t00766d71c0212d72438b86a52d918f8d const &a, t00766d71c0212d72438b86a52d918f8d const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t00766d71c0212d72438b86a52d918f8d const &a, t00766d71c0212d72438b86a52d918f8d const &b) {
  return !operator==(a, b);
}
struct t202b6f59dcbeb7de4acd5e3a8ac11097 : public std::tuple<
  dessser::gen::rc_entry::t_ext,
  Pointer
> {
  using tuple::tuple;
  t202b6f59dcbeb7de4acd5e3a8ac11097(std::tuple<dessser::gen::rc_entry::t_ext, Pointer> p)
    : std::tuple<dessser::gen::rc_entry::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t202b6f59dcbeb7de4acd5e3a8ac11097 const &a, t202b6f59dcbeb7de4acd5e3a8ac11097 const &b) {
  return ::dessser::gen::rc_entry::Deref(std::get<0>(a)) == ::dessser::gen::rc_entry::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t202b6f59dcbeb7de4acd5e3a8ac11097 const &a, t202b6f59dcbeb7de4acd5e3a8ac11097 const &b) {
  return !operator==(a, b);
}
struct t5ca88dae2022f5a9e0892d73f97aaa1a : public std::tuple<
  dessser::gen::source_info::t_ext,
  Pointer
> {
  using tuple::tuple;
  t5ca88dae2022f5a9e0892d73f97aaa1a(std::tuple<dessser::gen::source_info::t_ext, Pointer> p)
    : std::tuple<dessser::gen::source_info::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5ca88dae2022f5a9e0892d73f97aaa1a const &a, t5ca88dae2022f5a9e0892d73f97aaa1a const &b) {
  return ::dessser::gen::source_info::Deref(std::get<0>(a)) == ::dessser::gen::source_info::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5ca88dae2022f5a9e0892d73f97aaa1a const &a, t5ca88dae2022f5a9e0892d73f97aaa1a const &b) {
  return !operator==(a, b);
}
struct t287140549af6d490d4ffca187c95f6c7 : public std::tuple<
  dessser::gen::runtime_stats::t_ext,
  Pointer
> {
  using tuple::tuple;
  t287140549af6d490d4ffca187c95f6c7(std::tuple<dessser::gen::runtime_stats::t_ext, Pointer> p)
    : std::tuple<dessser::gen::runtime_stats::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t287140549af6d490d4ffca187c95f6c7 const &a, t287140549af6d490d4ffca187c95f6c7 const &b) {
  return ::dessser::gen::runtime_stats::Deref(std::get<0>(a)) == ::dessser::gen::runtime_stats::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t287140549af6d490d4ffca187c95f6c7 const &a, t287140549af6d490d4ffca187c95f6c7 const &b) {
  return !operator==(a, b);
}
struct t7853d7746da7c44760583c16a8bef7bc : public std::tuple<
  dessser::gen::replay::t_ext,
  Pointer
> {
  using tuple::tuple;
  t7853d7746da7c44760583c16a8bef7bc(std::tuple<dessser::gen::replay::t_ext, Pointer> p)
    : std::tuple<dessser::gen::replay::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7853d7746da7c44760583c16a8bef7bc const &a, t7853d7746da7c44760583c16a8bef7bc const &b) {
  return ::dessser::gen::replay::Deref(std::get<0>(a)) == ::dessser::gen::replay::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7853d7746da7c44760583c16a8bef7bc const &a, t7853d7746da7c44760583c16a8bef7bc const &b) {
  return !operator==(a, b);
}
struct t340c8c18d76359d202cd5c725fa85083 : public std::tuple<
  dessser::gen::replayer::t_ext,
  Pointer
> {
  using tuple::tuple;
  t340c8c18d76359d202cd5c725fa85083(std::tuple<dessser::gen::replayer::t_ext, Pointer> p)
    : std::tuple<dessser::gen::replayer::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t340c8c18d76359d202cd5c725fa85083 const &a, t340c8c18d76359d202cd5c725fa85083 const &b) {
  return ::dessser::gen::replayer::Deref(std::get<0>(a)) == ::dessser::gen::replayer::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t340c8c18d76359d202cd5c725fa85083 const &a, t340c8c18d76359d202cd5c725fa85083 const &b) {
  return !operator==(a, b);
}
struct t71285b8736282d5c64d3d0b32f7411e1 : public std::tuple<
  dessser::gen::replay_request::t_ext,
  Pointer
> {
  using tuple::tuple;
  t71285b8736282d5c64d3d0b32f7411e1(std::tuple<dessser::gen::replay_request::t_ext, Pointer> p)
    : std::tuple<dessser::gen::replay_request::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t71285b8736282d5c64d3d0b32f7411e1 const &a, t71285b8736282d5c64d3d0b32f7411e1 const &b) {
  return ::dessser::gen::replay_request::Deref(std::get<0>(a)) == ::dessser::gen::replay_request::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t71285b8736282d5c64d3d0b32f7411e1 const &a, t71285b8736282d5c64d3d0b32f7411e1 const &b) {
  return !operator==(a, b);
}
struct tab61b3acff25ef3507148f91d6ab4cb2 : public std::tuple<
  dessser::gen::alert::t_ext,
  Pointer
> {
  using tuple::tuple;
  tab61b3acff25ef3507148f91d6ab4cb2(std::tuple<dessser::gen::alert::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alert::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tab61b3acff25ef3507148f91d6ab4cb2 const &a, tab61b3acff25ef3507148f91d6ab4cb2 const &b) {
  return ::dessser::gen::alert::Deref(std::get<0>(a)) == ::dessser::gen::alert::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tab61b3acff25ef3507148f91d6ab4cb2 const &a, tab61b3acff25ef3507148f91d6ab4cb2 const &b) {
  return !operator==(a, b);
}
struct t0dbd1333ba33cc4b2146173bff40c155 : public std::tuple<
  dessser::gen::output_specs::t_ext,
  Pointer
> {
  using tuple::tuple;
  t0dbd1333ba33cc4b2146173bff40c155(std::tuple<dessser::gen::output_specs::t_ext, Pointer> p)
    : std::tuple<dessser::gen::output_specs::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0dbd1333ba33cc4b2146173bff40c155 const &a, t0dbd1333ba33cc4b2146173bff40c155 const &b) {
  return ::dessser::gen::output_specs::Deref(std::get<0>(a)) == ::dessser::gen::output_specs::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0dbd1333ba33cc4b2146173bff40c155 const &a, t0dbd1333ba33cc4b2146173bff40c155 const &b) {
  return !operator==(a, b);
}
struct te2c79ccd282a8acd25a39e2a11a8f3c4 : public std::tuple<
  dessser::gen::dashboard_widget::t_ext,
  Pointer
> {
  using tuple::tuple;
  te2c79ccd282a8acd25a39e2a11a8f3c4(std::tuple<dessser::gen::dashboard_widget::t_ext, Pointer> p)
    : std::tuple<dessser::gen::dashboard_widget::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te2c79ccd282a8acd25a39e2a11a8f3c4 const &a, te2c79ccd282a8acd25a39e2a11a8f3c4 const &b) {
  return ::dessser::gen::dashboard_widget::Deref(std::get<0>(a)) == ::dessser::gen::dashboard_widget::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te2c79ccd282a8acd25a39e2a11a8f3c4 const &a, te2c79ccd282a8acd25a39e2a11a8f3c4 const &b) {
  return !operator==(a, b);
}
struct t32b8e4236a53c9833f23e27968f8b877 : public std::tuple<
  dessser::gen::alerting_contact::t_ext,
  Pointer
> {
  using tuple::tuple;
  t32b8e4236a53c9833f23e27968f8b877(std::tuple<dessser::gen::alerting_contact::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_contact::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t32b8e4236a53c9833f23e27968f8b877 const &a, t32b8e4236a53c9833f23e27968f8b877 const &b) {
  return ::dessser::gen::alerting_contact::Deref(std::get<0>(a)) == ::dessser::gen::alerting_contact::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t32b8e4236a53c9833f23e27968f8b877 const &a, t32b8e4236a53c9833f23e27968f8b877 const &b) {
  return !operator==(a, b);
}
struct ta4a3462726fd3c37388ebeb529d00cc7 : public std::tuple<
  dessser::gen::alerting_notification::t_ext,
  Pointer
> {
  using tuple::tuple;
  ta4a3462726fd3c37388ebeb529d00cc7(std::tuple<dessser::gen::alerting_notification::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_notification::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta4a3462726fd3c37388ebeb529d00cc7 const &a, ta4a3462726fd3c37388ebeb529d00cc7 const &b) {
  return ::dessser::gen::alerting_notification::Deref(std::get<0>(a)) == ::dessser::gen::alerting_notification::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta4a3462726fd3c37388ebeb529d00cc7 const &a, ta4a3462726fd3c37388ebeb529d00cc7 const &b) {
  return !operator==(a, b);
}
struct te8b9cf0e630562630cfdb05a697f6c6e : public std::tuple<
  dessser::gen::alerting_delivery_status::t_ext,
  Pointer
> {
  using tuple::tuple;
  te8b9cf0e630562630cfdb05a697f6c6e(std::tuple<dessser::gen::alerting_delivery_status::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_delivery_status::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te8b9cf0e630562630cfdb05a697f6c6e const &a, te8b9cf0e630562630cfdb05a697f6c6e const &b) {
  return ::dessser::gen::alerting_delivery_status::Deref(std::get<0>(a)) == ::dessser::gen::alerting_delivery_status::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te8b9cf0e630562630cfdb05a697f6c6e const &a, te8b9cf0e630562630cfdb05a697f6c6e const &b) {
  return !operator==(a, b);
}
struct t702f22585c26c8c19b7f28f9f255cb0f : public std::tuple<
  dessser::gen::alerting_log::t_ext,
  Pointer
> {
  using tuple::tuple;
  t702f22585c26c8c19b7f28f9f255cb0f(std::tuple<dessser::gen::alerting_log::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_log::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t702f22585c26c8c19b7f28f9f255cb0f const &a, t702f22585c26c8c19b7f28f9f255cb0f const &b) {
  return ::dessser::gen::alerting_log::Deref(std::get<0>(a)) == ::dessser::gen::alerting_log::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t702f22585c26c8c19b7f28f9f255cb0f const &a, t702f22585c26c8c19b7f28f9f255cb0f const &b) {
  return !operator==(a, b);
}
struct t4b1e322f083a1aee723bc1396a69d619 : public std::tuple<
  dessser::gen::alerting_inhibition::t_ext,
  Pointer
> {
  using tuple::tuple;
  t4b1e322f083a1aee723bc1396a69d619(std::tuple<dessser::gen::alerting_inhibition::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_inhibition::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4b1e322f083a1aee723bc1396a69d619 const &a, t4b1e322f083a1aee723bc1396a69d619 const &b) {
  return ::dessser::gen::alerting_inhibition::Deref(std::get<0>(a)) == ::dessser::gen::alerting_inhibition::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4b1e322f083a1aee723bc1396a69d619 const &a, t4b1e322f083a1aee723bc1396a69d619 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{skipped: U32; values: Bytes}" "Ptr")
      (let "srec_dst_242" (write-u32 little-endian (param 1) (get-field "skipped" (param 0)))
        (write-bytes
          (let "leb128_sz_243" (make-vec (u32-of-size (bytes-length (get-field "values" (param 0)))))
            (let "leb128_ptr_244" (make-vec (identifier "srec_dst_242"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_244")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_244"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_243"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_243"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_243"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_243") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_243")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_243")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_244"))))) 
          (get-field "values" (param 0)))))
 */
static std::function<Pointer(::dessser::gen::sync_value::tuple*,Pointer)> tuple_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_value::tuple*,Pointer)> fun0 { [&fun0](::dessser::gen::sync_value::tuple* p_0, Pointer p_1) {
    uint32_t id_1 { (*p_0).skipped };
    Pointer id_2 { p_1.writeU32Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_242 { id_2 };
      Bytes id_4 { (*p_0).values };
      Size id_5 { id_4.length() };
      uint32_t id_6 { uint32_t(id_5) };
      Vec<1, uint32_t> id_7 {  id_6  };
      Pointer let_res_8;
      {
        Vec<1, uint32_t> leb128_sz_243 { id_7 };
        Vec<1, Pointer> id_9 {  srec_dst_242  };
        Pointer let_res_10;
        {
          Vec<1, Pointer> leb128_ptr_244 { id_9 };
          bool while_flag_11 { true };
          do {
            uint8_t id_12 { 0 };
            uint8_t id_13 { 0 };
            Pointer id_14 { leb128_ptr_244[id_13] };
            uint32_t id_15 { 128U };
            uint8_t id_16 { 0 };
            uint32_t id_17 { leb128_sz_243[id_16] };
            bool id_18 { bool(id_15 > id_17) };
            uint8_t choose_res_19;
            if (id_18) {
              uint8_t id_20 { 0 };
              uint32_t id_21 { leb128_sz_243[id_20] };
              uint8_t id_22 { uint8_t(id_21) };
              choose_res_19 = id_22;
            } else {
              uint8_t id_23 { 0 };
              uint32_t id_24 { leb128_sz_243[id_23] };
              uint8_t id_25 { uint8_t(id_24) };
              uint8_t id_26 { 128 };
              uint8_t id_27 { uint8_t(id_25 | id_26) };
              choose_res_19 = id_27;
            }
            Pointer id_28 { id_14.writeU8(choose_res_19) };
            Void id_29 { ((void)(leb128_ptr_244[id_12] = id_28), VOID) };
            (void)id_29;
            uint8_t id_30 { 0 };
            uint8_t id_31 { 0 };
            uint32_t id_32 { leb128_sz_243[id_31] };
            uint8_t id_33 { 7 };
            uint32_t id_34 { uint32_t(id_32 >> id_33) };
            Void id_35 { ((void)(leb128_sz_243[id_30] = id_34), VOID) };
            (void)id_35;
            uint8_t id_36 { 0 };
            uint32_t id_37 { leb128_sz_243[id_36] };
            uint32_t id_38 { 0U };
            bool id_39 { bool(id_37 > id_38) };
            while_flag_11 = id_39;
            if (while_flag_11) {
              (void)VOID;
            }
          } while (while_flag_11);
          (void)VOID;
          uint8_t id_40 { 0 };
          Pointer id_41 { leb128_ptr_244[id_40] };
          let_res_10 = id_41;
        }
        let_res_8 = let_res_10;
      }
      Bytes id_42 { (*p_0).values };
      Pointer id_43 { let_res_8.writeBytes(id_42) };
      let_res_3 = id_43;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::sync_value::tuple*,Pointer)> tuple_to_row_binary(tuple_to_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" "Ptr")
      (let "label1_245" (label-of (param 0))
        (let "ssum_dst_246" (write-u16 little-endian (param 1) (identifier "label1_245"))
          (if (eq (u16 0) (identifier "label1_245"))
            (let "stup_dst_258"
              (let "stup_dst_257" (write-u64 little-endian (identifier "ssum_dst_246") (u64-of-float (get-item 0 (get-alt "Error" (param 0)))))
                (write-u32 little-endian (identifier "stup_dst_257") (get-item 1 (get-alt "Error" (param 0)))))
              (write-bytes
                (let "leb128_sz_259" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                  (let "leb128_ptr_260" (make-vec (identifier "stup_dst_258"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_260")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_260"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_259"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_259"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_259"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_259") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_259")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_259")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_260"))))) 
                (bytes-of-string (get-item 2 (get-alt "Error" (param 0))))))
            (if (eq (u16 1) (identifier "label1_245")) (apply (ext-identifier worker to-row-binary) (get-alt "Worker" (param 0)) (identifier "ssum_dst_246"))
              (if (eq (u16 2) (identifier "label1_245")) (apply (ext-identifier retention to-row-binary) (get-alt "Retention" (param 0)) (identifier "ssum_dst_246"))
                (if (eq (u16 3) (identifier "label1_245")) (apply (ext-identifier time_range to-row-binary) (get-alt "TimeRange" (param 0)) (identifier "ssum_dst_246"))
                  (if (eq (u16 4) (identifier "label1_245"))
                    (let "dst_ref_254"
                      (make-vec
                        (let "leb128_sz_252" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "leb128_ptr_253" (make-vec (identifier "ssum_dst_246"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_253")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_253"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_252"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_252"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_252"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_252") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_252")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_252")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_253"))))))
                      (let "n_ref_255" (make-vec (i32 0))
                        (seq
                          (for-each "x_256" (get-alt "Tuples" (param 0))
                            (seq (set-vec (u8 0) (identifier "dst_ref_254") (apply (identifier "tuple-to-row-binary") (identifier "x_256") (unsafe-nth (u8 0) (identifier "dst_ref_254"))))
                              (set-vec (u8 0) (identifier "n_ref_255") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_255")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_254")))))
                    (if (eq (u16 5) (identifier "label1_245")) (apply (ext-identifier raql_value to-row-binary) (get-alt "RamenValue" (param 0)) (identifier "ssum_dst_246"))
                      (if (eq (u16 6) (identifier "label1_245"))
                        (let "dst_ref_249"
                          (make-vec
                            (let "leb128_sz_247" (make-vec (cardinality (get-alt "TargetConfig" (param 0))))
                              (let "leb128_ptr_248" (make-vec (identifier "ssum_dst_246"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_248")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_248"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_247"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_247"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_247"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_247") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_247")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_247")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_248"))))))
                          (let "n_ref_250" (make-vec (i32 0))
                            (seq
                              (for-each "x_251" (get-alt "TargetConfig" (param 0))
                                (seq (set-vec (u8 0) (identifier "dst_ref_249") (apply (ext-identifier rc_entry to-row-binary) (identifier "x_251") (unsafe-nth (u8 0) (identifier "dst_ref_249"))))
                                  (set-vec (u8 0) (identifier "n_ref_250") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_250")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_249")))))
                        (if (eq (u16 7) (identifier "label1_245")) (apply (ext-identifier source_info to-row-binary) (get-alt "SourceInfo" (param 0)) (identifier "ssum_dst_246"))
                          (if (eq (u16 8) (identifier "label1_245")) 
                            (apply (ext-identifier runtime_stats to-row-binary) (get-alt "RuntimeStats" (param 0)) (identifier "ssum_dst_246"))
                            (if (eq (u16 9) (identifier "label1_245")) 
                              (apply (ext-identifier replay to-row-binary) (get-alt "Replay" (param 0)) (identifier "ssum_dst_246"))
                              (if (eq (u16 10) (identifier "label1_245")) 
                                (apply (ext-identifier replayer to-row-binary) (get-alt "Replayer" (param 0)) (identifier "ssum_dst_246"))
                                (if (eq (u16 11) (identifier "label1_245")) 
                                  (apply (ext-identifier replay_request to-row-binary) (get-alt "ReplayRequest" (param 0)) (identifier "ssum_dst_246"))
                                  (if (eq (u16 12) (identifier "label1_245")) 
                                    (apply (ext-identifier alert to-row-binary) (get-alt "Alert" (param 0)) (identifier "ssum_dst_246"))
                                    (if (eq (u16 13) (identifier "label1_245")) 
                                      (apply (ext-identifier output_specs to-row-binary) (get-alt "OutputSpecs" (param 0)) (identifier "ssum_dst_246"))
                                      (if (eq (u16 14) (identifier "label1_245")) 
                                        (apply (ext-identifier dashboard_widget to-row-binary) (get-alt "DashboardWidget" (param 0)) (identifier "ssum_dst_246"))
                                        (if (eq (u16 15) (identifier "label1_245")) 
                                          (apply (ext-identifier alerting_contact to-row-binary) (get-alt "AlertingContact" (param 0)) (identifier "ssum_dst_246"))
                                          (if (eq (u16 16) (identifier "label1_245")) 
                                            (apply (ext-identifier alerting_notification to-row-binary) (get-alt "Notification" (param 0)) (identifier "ssum_dst_246"))
                                            (if (eq (u16 17) (identifier "label1_245")) 
                                              (apply (ext-identifier alerting_delivery_status to-row-binary) (get-alt "DeliveryStatus" (param 0)) (identifier "ssum_dst_246"))
                                              (if (eq (u16 18) (identifier "label1_245")) 
                                                (apply (ext-identifier alerting_log to-row-binary) (get-alt "IncidentLog" (param 0)) (identifier "ssum_dst_246"))
                                                (seq (assert (eq (identifier "label1_245") (u16 19))) (apply (ext-identifier alerting_inhibition to-row-binary) (get-alt "Inhibition" (param 0)) (identifier "ssum_dst_246")))))))))))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> fun44 { [&fun44](::dessser::gen::sync_value::t* p_0, Pointer p_1) {
    uint16_t id_45 { uint16_t((*p_0).index()) };
    Pointer let_res_46;
    {
      uint16_t label1_245 { id_45 };
      Pointer id_47 { p_1.writeU16Le(label1_245) };
      Pointer let_res_48;
      {
        Pointer ssum_dst_246 { id_47 };
        uint16_t id_49 { 0 };
        bool id_50 { bool(id_49 == label1_245) };
        Pointer choose_res_51;
        if (id_50) {
          ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_52 { std::get<0 /* Error */>((*p_0)) };
          double id_53 { std::get<0>(id_52) };
          uint64_t id_54 { qword_of_float(id_53) };
          Pointer id_55 { ssum_dst_246.writeU64Le(id_54) };
          Pointer let_res_56;
          {
            Pointer stup_dst_257 { id_55 };
            ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_57 { std::get<0 /* Error */>((*p_0)) };
            uint32_t id_58 { std::get<1>(id_57) };
            Pointer id_59 { stup_dst_257.writeU32Le(id_58) };
            let_res_56 = id_59;
          }
          Pointer let_res_60;
          {
            Pointer stup_dst_258 { let_res_56 };
            ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_61 { std::get<0 /* Error */>((*p_0)) };
            std::string id_62 { std::get<2>(id_61) };
            uint32_t id_63 { (uint32_t)id_62.size() };
            Vec<1, uint32_t> id_64 {  id_63  };
            Pointer let_res_65;
            {
              Vec<1, uint32_t> leb128_sz_259 { id_64 };
              Vec<1, Pointer> id_66 {  stup_dst_258  };
              Pointer let_res_67;
              {
                Vec<1, Pointer> leb128_ptr_260 { id_66 };
                bool while_flag_68 { true };
                do {
                  uint8_t id_69 { 0 };
                  uint8_t id_70 { 0 };
                  Pointer id_71 { leb128_ptr_260[id_70] };
                  uint32_t id_72 { 128U };
                  uint8_t id_73 { 0 };
                  uint32_t id_74 { leb128_sz_259[id_73] };
                  bool id_75 { bool(id_72 > id_74) };
                  uint8_t choose_res_76;
                  if (id_75) {
                    uint8_t id_77 { 0 };
                    uint32_t id_78 { leb128_sz_259[id_77] };
                    uint8_t id_79 { uint8_t(id_78) };
                    choose_res_76 = id_79;
                  } else {
                    uint8_t id_80 { 0 };
                    uint32_t id_81 { leb128_sz_259[id_80] };
                    uint8_t id_82 { uint8_t(id_81) };
                    uint8_t id_83 { 128 };
                    uint8_t id_84 { uint8_t(id_82 | id_83) };
                    choose_res_76 = id_84;
                  }
                  Pointer id_85 { id_71.writeU8(choose_res_76) };
                  Void id_86 { ((void)(leb128_ptr_260[id_69] = id_85), VOID) };
                  (void)id_86;
                  uint8_t id_87 { 0 };
                  uint8_t id_88 { 0 };
                  uint32_t id_89 { leb128_sz_259[id_88] };
                  uint8_t id_90 { 7 };
                  uint32_t id_91 { uint32_t(id_89 >> id_90) };
                  Void id_92 { ((void)(leb128_sz_259[id_87] = id_91), VOID) };
                  (void)id_92;
                  uint8_t id_93 { 0 };
                  uint32_t id_94 { leb128_sz_259[id_93] };
                  uint32_t id_95 { 0U };
                  bool id_96 { bool(id_94 > id_95) };
                  while_flag_68 = id_96;
                  if (while_flag_68) {
                    (void)VOID;
                  }
                } while (while_flag_68);
                (void)VOID;
                uint8_t id_97 { 0 };
                Pointer id_98 { leb128_ptr_260[id_97] };
                let_res_67 = id_98;
              }
              let_res_65 = let_res_67;
            }
            ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_99 { std::get<0 /* Error */>((*p_0)) };
            std::string id_100 { std::get<2>(id_99) };
            Bytes id_101 { id_100 };
            Pointer id_102 { let_res_65.writeBytes(id_101) };
            let_res_60 = id_102;
          }
          choose_res_51 = let_res_60;
        } else {
          uint16_t id_103 { 1 };
          bool id_104 { bool(id_103 == label1_245) };
          Pointer choose_res_105;
          if (id_104) {
            auto fun106 { dessser::gen::worker::to_row_binary };
            dessser::gen::worker::t_ext id_107 { std::get<1 /* Worker */>((*p_0)) };
            Pointer id_108 { fun106(id_107, ssum_dst_246) };
            choose_res_105 = id_108;
          } else {
            uint16_t id_109 { 2 };
            bool id_110 { bool(id_109 == label1_245) };
            Pointer choose_res_111;
            if (id_110) {
              auto fun112 { dessser::gen::retention::to_row_binary };
              dessser::gen::retention::t_ext id_113 { std::get<2 /* Retention */>((*p_0)) };
              Pointer id_114 { fun112(id_113, ssum_dst_246) };
              choose_res_111 = id_114;
            } else {
              uint16_t id_115 { 3 };
              bool id_116 { bool(id_115 == label1_245) };
              Pointer choose_res_117;
              if (id_116) {
                auto fun118 { dessser::gen::time_range::to_row_binary };
                dessser::gen::time_range::t_ext id_119 { std::get<3 /* TimeRange */>((*p_0)) };
                Pointer id_120 { fun118(id_119, ssum_dst_246) };
                choose_res_117 = id_120;
              } else {
                uint16_t id_121 { 4 };
                bool id_122 { bool(id_121 == label1_245) };
                Pointer choose_res_123;
                if (id_122) {
                  Arr<::dessser::gen::sync_value::tuple*> id_124 { std::get<4 /* Tuples */>((*p_0)) };
                  uint32_t id_125 { id_124.size() };
                  Vec<1, uint32_t> id_126 {  id_125  };
                  Pointer let_res_127;
                  {
                    Vec<1, uint32_t> leb128_sz_252 { id_126 };
                    Vec<1, Pointer> id_128 {  ssum_dst_246  };
                    Pointer let_res_129;
                    {
                      Vec<1, Pointer> leb128_ptr_253 { id_128 };
                      bool while_flag_130 { true };
                      do {
                        uint8_t id_131 { 0 };
                        uint8_t id_132 { 0 };
                        Pointer id_133 { leb128_ptr_253[id_132] };
                        uint32_t id_134 { 128U };
                        uint8_t id_135 { 0 };
                        uint32_t id_136 { leb128_sz_252[id_135] };
                        bool id_137 { bool(id_134 > id_136) };
                        uint8_t choose_res_138;
                        if (id_137) {
                          uint8_t id_139 { 0 };
                          uint32_t id_140 { leb128_sz_252[id_139] };
                          uint8_t id_141 { uint8_t(id_140) };
                          choose_res_138 = id_141;
                        } else {
                          uint8_t id_142 { 0 };
                          uint32_t id_143 { leb128_sz_252[id_142] };
                          uint8_t id_144 { uint8_t(id_143) };
                          uint8_t id_145 { 128 };
                          uint8_t id_146 { uint8_t(id_144 | id_145) };
                          choose_res_138 = id_146;
                        }
                        Pointer id_147 { id_133.writeU8(choose_res_138) };
                        Void id_148 { ((void)(leb128_ptr_253[id_131] = id_147), VOID) };
                        (void)id_148;
                        uint8_t id_149 { 0 };
                        uint8_t id_150 { 0 };
                        uint32_t id_151 { leb128_sz_252[id_150] };
                        uint8_t id_152 { 7 };
                        uint32_t id_153 { uint32_t(id_151 >> id_152) };
                        Void id_154 { ((void)(leb128_sz_252[id_149] = id_153), VOID) };
                        (void)id_154;
                        uint8_t id_155 { 0 };
                        uint32_t id_156 { leb128_sz_252[id_155] };
                        uint32_t id_157 { 0U };
                        bool id_158 { bool(id_156 > id_157) };
                        while_flag_130 = id_158;
                        if (while_flag_130) {
                          (void)VOID;
                        }
                      } while (while_flag_130);
                      (void)VOID;
                      uint8_t id_159 { 0 };
                      Pointer id_160 { leb128_ptr_253[id_159] };
                      let_res_129 = id_160;
                    }
                    let_res_127 = let_res_129;
                  }
                  Vec<1, Pointer> id_161 {  let_res_127  };
                  Pointer let_res_162;
                  {
                    Vec<1, Pointer> dst_ref_254 { id_161 };
                    int32_t id_163 { 0L };
                    Vec<1, int32_t> id_164 {  id_163  };
                    Pointer let_res_165;
                    {
                      Vec<1, int32_t> n_ref_255 { id_164 };
                      Arr<::dessser::gen::sync_value::tuple*> id_166 { std::get<4 /* Tuples */>((*p_0)) };
                      for (::dessser::gen::sync_value::tuple* x_256 : id_166) {
                        uint8_t id_167 { 0 };
                        uint8_t id_168 { 0 };
                        Pointer id_169 { dst_ref_254[id_168] };
                        Pointer id_170 { tuple_to_row_binary(x_256, id_169) };
                        Void id_171 { ((void)(dst_ref_254[id_167] = id_170), VOID) };
                        (void)id_171;
                        uint8_t id_172 { 0 };
                        int32_t id_173 { 1L };
                        uint8_t id_174 { 0 };
                        int32_t id_175 { n_ref_255[id_174] };
                        int32_t id_176 { int32_t(id_173 + id_175) };
                        Void id_177 { ((void)(n_ref_255[id_172] = id_176), VOID) };
                        (void)id_177;
                        (void)id_177;
                      }
                      (void)VOID;
                      uint8_t id_178 { 0 };
                      Pointer id_179 { dst_ref_254[id_178] };
                      let_res_165 = id_179;
                    }
                    let_res_162 = let_res_165;
                  }
                  choose_res_123 = let_res_162;
                } else {
                  uint16_t id_180 { 5 };
                  bool id_181 { bool(id_180 == label1_245) };
                  Pointer choose_res_182;
                  if (id_181) {
                    auto fun183 { dessser::gen::raql_value::to_row_binary };
                    dessser::gen::raql_value::t_ext id_184 { std::get<5 /* RamenValue */>((*p_0)) };
                    Pointer id_185 { fun183(id_184, ssum_dst_246) };
                    choose_res_182 = id_185;
                  } else {
                    uint16_t id_186 { 6 };
                    bool id_187 { bool(id_186 == label1_245) };
                    Pointer choose_res_188;
                    if (id_187) {
                      Arr<dessser::gen::rc_entry::t_ext> id_189 { std::get<6 /* TargetConfig */>((*p_0)) };
                      uint32_t id_190 { id_189.size() };
                      Vec<1, uint32_t> id_191 {  id_190  };
                      Pointer let_res_192;
                      {
                        Vec<1, uint32_t> leb128_sz_247 { id_191 };
                        Vec<1, Pointer> id_193 {  ssum_dst_246  };
                        Pointer let_res_194;
                        {
                          Vec<1, Pointer> leb128_ptr_248 { id_193 };
                          bool while_flag_195 { true };
                          do {
                            uint8_t id_196 { 0 };
                            uint8_t id_197 { 0 };
                            Pointer id_198 { leb128_ptr_248[id_197] };
                            uint32_t id_199 { 128U };
                            uint8_t id_200 { 0 };
                            uint32_t id_201 { leb128_sz_247[id_200] };
                            bool id_202 { bool(id_199 > id_201) };
                            uint8_t choose_res_203;
                            if (id_202) {
                              uint8_t id_204 { 0 };
                              uint32_t id_205 { leb128_sz_247[id_204] };
                              uint8_t id_206 { uint8_t(id_205) };
                              choose_res_203 = id_206;
                            } else {
                              uint8_t id_207 { 0 };
                              uint32_t id_208 { leb128_sz_247[id_207] };
                              uint8_t id_209 { uint8_t(id_208) };
                              uint8_t id_210 { 128 };
                              uint8_t id_211 { uint8_t(id_209 | id_210) };
                              choose_res_203 = id_211;
                            }
                            Pointer id_212 { id_198.writeU8(choose_res_203) };
                            Void id_213 { ((void)(leb128_ptr_248[id_196] = id_212), VOID) };
                            (void)id_213;
                            uint8_t id_214 { 0 };
                            uint8_t id_215 { 0 };
                            uint32_t id_216 { leb128_sz_247[id_215] };
                            uint8_t id_217 { 7 };
                            uint32_t id_218 { uint32_t(id_216 >> id_217) };
                            Void id_219 { ((void)(leb128_sz_247[id_214] = id_218), VOID) };
                            (void)id_219;
                            uint8_t id_220 { 0 };
                            uint32_t id_221 { leb128_sz_247[id_220] };
                            uint32_t id_222 { 0U };
                            bool id_223 { bool(id_221 > id_222) };
                            while_flag_195 = id_223;
                            if (while_flag_195) {
                              (void)VOID;
                            }
                          } while (while_flag_195);
                          (void)VOID;
                          uint8_t id_224 { 0 };
                          Pointer id_225 { leb128_ptr_248[id_224] };
                          let_res_194 = id_225;
                        }
                        let_res_192 = let_res_194;
                      }
                      Vec<1, Pointer> id_226 {  let_res_192  };
                      Pointer let_res_227;
                      {
                        Vec<1, Pointer> dst_ref_249 { id_226 };
                        int32_t id_228 { 0L };
                        Vec<1, int32_t> id_229 {  id_228  };
                        Pointer let_res_230;
                        {
                          Vec<1, int32_t> n_ref_250 { id_229 };
                          Arr<dessser::gen::rc_entry::t_ext> id_231 { std::get<6 /* TargetConfig */>((*p_0)) };
                          for (dessser::gen::rc_entry::t_ext x_251 : id_231) {
                            uint8_t id_232 { 0 };
                            auto fun233 { dessser::gen::rc_entry::to_row_binary };
                            uint8_t id_234 { 0 };
                            Pointer id_235 { dst_ref_249[id_234] };
                            Pointer id_236 { fun233(x_251, id_235) };
                            Void id_237 { ((void)(dst_ref_249[id_232] = id_236), VOID) };
                            (void)id_237;
                            uint8_t id_238 { 0 };
                            int32_t id_239 { 1L };
                            uint8_t id_240 { 0 };
                            int32_t id_241 { n_ref_250[id_240] };
                            int32_t id_242 { int32_t(id_239 + id_241) };
                            Void id_243 { ((void)(n_ref_250[id_238] = id_242), VOID) };
                            (void)id_243;
                            (void)id_243;
                          }
                          (void)VOID;
                          uint8_t id_244 { 0 };
                          Pointer id_245 { dst_ref_249[id_244] };
                          let_res_230 = id_245;
                        }
                        let_res_227 = let_res_230;
                      }
                      choose_res_188 = let_res_227;
                    } else {
                      uint16_t id_246 { 7 };
                      bool id_247 { bool(id_246 == label1_245) };
                      Pointer choose_res_248;
                      if (id_247) {
                        auto fun249 { dessser::gen::source_info::to_row_binary };
                        dessser::gen::source_info::t_ext id_250 { std::get<7 /* SourceInfo */>((*p_0)) };
                        Pointer id_251 { fun249(id_250, ssum_dst_246) };
                        choose_res_248 = id_251;
                      } else {
                        uint16_t id_252 { 8 };
                        bool id_253 { bool(id_252 == label1_245) };
                        Pointer choose_res_254;
                        if (id_253) {
                          auto fun255 { dessser::gen::runtime_stats::to_row_binary };
                          dessser::gen::runtime_stats::t_ext id_256 { std::get<8 /* RuntimeStats */>((*p_0)) };
                          Pointer id_257 { fun255(id_256, ssum_dst_246) };
                          choose_res_254 = id_257;
                        } else {
                          uint16_t id_258 { 9 };
                          bool id_259 { bool(id_258 == label1_245) };
                          Pointer choose_res_260;
                          if (id_259) {
                            auto fun261 { dessser::gen::replay::to_row_binary };
                            dessser::gen::replay::t_ext id_262 { std::get<9 /* Replay */>((*p_0)) };
                            Pointer id_263 { fun261(id_262, ssum_dst_246) };
                            choose_res_260 = id_263;
                          } else {
                            uint16_t id_264 { 10 };
                            bool id_265 { bool(id_264 == label1_245) };
                            Pointer choose_res_266;
                            if (id_265) {
                              auto fun267 { dessser::gen::replayer::to_row_binary };
                              dessser::gen::replayer::t_ext id_268 { std::get<10 /* Replayer */>((*p_0)) };
                              Pointer id_269 { fun267(id_268, ssum_dst_246) };
                              choose_res_266 = id_269;
                            } else {
                              uint16_t id_270 { 11 };
                              bool id_271 { bool(id_270 == label1_245) };
                              Pointer choose_res_272;
                              if (id_271) {
                                auto fun273 { dessser::gen::replay_request::to_row_binary };
                                dessser::gen::replay_request::t_ext id_274 { std::get<11 /* ReplayRequest */>((*p_0)) };
                                Pointer id_275 { fun273(id_274, ssum_dst_246) };
                                choose_res_272 = id_275;
                              } else {
                                uint16_t id_276 { 12 };
                                bool id_277 { bool(id_276 == label1_245) };
                                Pointer choose_res_278;
                                if (id_277) {
                                  auto fun279 { dessser::gen::alert::to_row_binary };
                                  dessser::gen::alert::t_ext id_280 { std::get<12 /* Alert */>((*p_0)) };
                                  Pointer id_281 { fun279(id_280, ssum_dst_246) };
                                  choose_res_278 = id_281;
                                } else {
                                  uint16_t id_282 { 13 };
                                  bool id_283 { bool(id_282 == label1_245) };
                                  Pointer choose_res_284;
                                  if (id_283) {
                                    auto fun285 { dessser::gen::output_specs::to_row_binary };
                                    dessser::gen::output_specs::t_ext id_286 { std::get<13 /* OutputSpecs */>((*p_0)) };
                                    Pointer id_287 { fun285(id_286, ssum_dst_246) };
                                    choose_res_284 = id_287;
                                  } else {
                                    uint16_t id_288 { 14 };
                                    bool id_289 { bool(id_288 == label1_245) };
                                    Pointer choose_res_290;
                                    if (id_289) {
                                      auto fun291 { dessser::gen::dashboard_widget::to_row_binary };
                                      dessser::gen::dashboard_widget::t_ext id_292 { std::get<14 /* DashboardWidget */>((*p_0)) };
                                      Pointer id_293 { fun291(id_292, ssum_dst_246) };
                                      choose_res_290 = id_293;
                                    } else {
                                      uint16_t id_294 { 15 };
                                      bool id_295 { bool(id_294 == label1_245) };
                                      Pointer choose_res_296;
                                      if (id_295) {
                                        auto fun297 { dessser::gen::alerting_contact::to_row_binary };
                                        dessser::gen::alerting_contact::t_ext id_298 { std::get<15 /* AlertingContact */>((*p_0)) };
                                        Pointer id_299 { fun297(id_298, ssum_dst_246) };
                                        choose_res_296 = id_299;
                                      } else {
                                        uint16_t id_300 { 16 };
                                        bool id_301 { bool(id_300 == label1_245) };
                                        Pointer choose_res_302;
                                        if (id_301) {
                                          auto fun303 { dessser::gen::alerting_notification::to_row_binary };
                                          dessser::gen::alerting_notification::t_ext id_304 { std::get<16 /* Notification */>((*p_0)) };
                                          Pointer id_305 { fun303(id_304, ssum_dst_246) };
                                          choose_res_302 = id_305;
                                        } else {
                                          uint16_t id_306 { 17 };
                                          bool id_307 { bool(id_306 == label1_245) };
                                          Pointer choose_res_308;
                                          if (id_307) {
                                            auto fun309 { dessser::gen::alerting_delivery_status::to_row_binary };
                                            dessser::gen::alerting_delivery_status::t_ext id_310 { std::get<17 /* DeliveryStatus */>((*p_0)) };
                                            Pointer id_311 { fun309(id_310, ssum_dst_246) };
                                            choose_res_308 = id_311;
                                          } else {
                                            uint16_t id_312 { 18 };
                                            bool id_313 { bool(id_312 == label1_245) };
                                            Pointer choose_res_314;
                                            if (id_313) {
                                              auto fun315 { dessser::gen::alerting_log::to_row_binary };
                                              dessser::gen::alerting_log::t_ext id_316 { std::get<18 /* IncidentLog */>((*p_0)) };
                                              Pointer id_317 { fun315(id_316, ssum_dst_246) };
                                              choose_res_314 = id_317;
                                            } else {
                                              uint16_t id_318 { 19 };
                                              bool id_319 { bool(label1_245 == id_318) };
                                              Void id_320 { ((void)(assert(id_319)), VOID) };
                                              (void)id_320;
                                              auto fun321 { dessser::gen::alerting_inhibition::to_row_binary };
                                              dessser::gen::alerting_inhibition::t_ext id_322 { std::get<19 /* Inhibition */>((*p_0)) };
                                              Pointer id_323 { fun321(id_322, ssum_dst_246) };
                                              choose_res_314 = id_323;
                                            }
                                            choose_res_308 = choose_res_314;
                                          }
                                          choose_res_302 = choose_res_308;
                                        }
                                        choose_res_296 = choose_res_302;
                                      }
                                      choose_res_290 = choose_res_296;
                                    }
                                    choose_res_284 = choose_res_290;
                                  }
                                  choose_res_278 = choose_res_284;
                                }
                                choose_res_272 = choose_res_278;
                              }
                              choose_res_266 = choose_res_272;
                            }
                            choose_res_260 = choose_res_266;
                          }
                          choose_res_254 = choose_res_260;
                        }
                        choose_res_248 = choose_res_254;
                      }
                      choose_res_188 = choose_res_248;
                    }
                    choose_res_182 = choose_res_188;
                  }
                  choose_res_123 = choose_res_182;
                }
                choose_res_117 = choose_res_123;
              }
              choose_res_111 = choose_res_117;
            }
            choose_res_105 = choose_res_111;
          }
          choose_res_51 = choose_res_105;
        }
        let_res_48 = choose_res_51;
      }
      let_res_46 = let_res_48;
    }
    return let_res_46;
  }
   };
  return fun44;
}
std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{skipped: U32; values: Bytes}")
      (add (size 4)
        (add
          (let "n_ref_225" (make-vec (u32-of-size (bytes-length (get-field "values" (param 0)))))
            (let "lebsz_ref_226" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_225")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_226")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_226") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_226")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_226")))))) 
          (bytes-length (get-field "values" (param 0))))))
 */
static std::function<Size(::dessser::gen::sync_value::tuple*)> tuple_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_value::tuple*)> fun324 { [&fun324](::dessser::gen::sync_value::tuple* p_0) {
    Size id_325 { 4UL };
    Bytes id_326 { (*p_0).values };
    Size id_327 { id_326.length() };
    uint32_t id_328 { uint32_t(id_327) };
    Vec<1, uint32_t> id_329 {  id_328  };
    Size let_res_330;
    {
      Vec<1, uint32_t> n_ref_225 { id_329 };
      uint32_t id_331 { 1U };
      Vec<1, uint32_t> id_332 {  id_331  };
      Size let_res_333;
      {
        Vec<1, uint32_t> lebsz_ref_226 { id_332 };
        bool while_flag_334 { true };
        do {
          uint8_t id_335 { 0 };
          uint32_t id_336 { n_ref_225[id_335] };
          uint8_t id_337 { 0 };
          uint32_t id_338 { lebsz_ref_226[id_337] };
          uint8_t id_339 { 7 };
          uint32_t id_340 { uint32_t(id_338 << id_339) };
          bool id_341 { bool(id_336 >= id_340) };
          while_flag_334 = id_341;
          if (while_flag_334) {
            uint8_t id_342 { 0 };
            uint8_t id_343 { 0 };
            uint32_t id_344 { lebsz_ref_226[id_343] };
            uint32_t id_345 { 1U };
            uint32_t id_346 { uint32_t(id_344 + id_345) };
            Void id_347 { ((void)(lebsz_ref_226[id_342] = id_346), VOID) };
            (void)id_347;
          }
        } while (while_flag_334);
        (void)VOID;
        uint8_t id_348 { 0 };
        uint32_t id_349 { lebsz_ref_226[id_348] };
        Size id_350 { Size(id_349) };
        let_res_333 = id_350;
      }
      let_res_330 = let_res_333;
    }
    Bytes id_351 { (*p_0).values };
    Size id_352 { id_351.length() };
    Size id_353 { Size(let_res_330 + id_352) };
    Size id_354 { Size(id_325 + id_353) };
    return id_354;
  }
   };
  return fun324;
}
std::function<Size(::dessser::gen::sync_value::tuple*)> tuple_sersize_of_row_binary(tuple_sersize_of_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]")
      (let "label2_227" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_227"))
          (add (size 14)
            (add
              (let "n_ref_240" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                (let "lebsz_ref_241" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_240")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_241")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_241") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_241")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_241")))))) 
              (size-of-u32 (string-length (get-item 2 (get-alt "Error" (param 0)))))))
          (if (eq (u16 1) (identifier "label2_227")) (add (size 2) (apply (ext-identifier worker sersize-of-row-binary) (get-alt "Worker" (param 0))))
            (if (eq (u16 2) (identifier "label2_227")) (add (size 2) (apply (ext-identifier retention sersize-of-row-binary) (get-alt "Retention" (param 0))))
              (if (eq (u16 3) (identifier "label2_227")) (add (size 2) (apply (ext-identifier time_range sersize-of-row-binary) (get-alt "TimeRange" (param 0))))
                (if (eq (u16 4) (identifier "label2_227"))
                  (let "sz_ref_234"
                    (make-vec
                      (add (size 2)
                        (let "n_ref_232" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "lebsz_ref_233" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_232")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_233")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_233") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_233")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_233"))))))))
                    (seq
                      (let "repeat_n_235" (make-vec (i32 0))
                        (while (gt (to-i32 (cardinality (get-alt "Tuples" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_235")))
                          (seq
                            (set-vec (u8 0) (identifier "sz_ref_234")
                              (add (unsafe-nth (u8 0) (identifier "sz_ref_234")) (apply (identifier "tuple-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_235")) (get-alt "Tuples" (param 0))))))
                            (set-vec (u8 0) (identifier "repeat_n_235") (add (unsafe-nth (u8 0) (identifier "repeat_n_235")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "sz_ref_234"))))
                  (if (eq (u16 5) (identifier "label2_227")) (add (size 2) (apply (ext-identifier raql_value sersize-of-row-binary) (get-alt "RamenValue" (param 0))))
                    (if (eq (u16 6) (identifier "label2_227"))
                      (let "sz_ref_230"
                        (make-vec
                          (add (size 2)
                            (let "n_ref_228" (make-vec (cardinality (get-alt "TargetConfig" (param 0))))
                              (let "lebsz_ref_229" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_228")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_229")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_229") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_229")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_229"))))))))
                        (seq
                          (let "repeat_n_231" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-alt "TargetConfig" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_231")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_230")
                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_230"))
                                    (apply (ext-identifier rc_entry sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_231")) (get-alt "TargetConfig" (param 0))))))
                                (set-vec (u8 0) (identifier "repeat_n_231") (add (unsafe-nth (u8 0) (identifier "repeat_n_231")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_230"))))
                      (if (eq (u16 7) (identifier "label2_227")) (add (size 2) (apply (ext-identifier source_info sersize-of-row-binary) (get-alt "SourceInfo" (param 0))))
                        (if (eq (u16 8) (identifier "label2_227")) (add (size 2) (apply (ext-identifier runtime_stats sersize-of-row-binary) (get-alt "RuntimeStats" (param 0))))
                          (if (eq (u16 9) (identifier "label2_227")) 
                            (add (size 2) (apply (ext-identifier replay sersize-of-row-binary) (get-alt "Replay" (param 0))))
                            (if (eq (u16 10) (identifier "label2_227")) 
                              (add (size 2) (apply (ext-identifier replayer sersize-of-row-binary) (get-alt "Replayer" (param 0))))
                              (if (eq (u16 11) (identifier "label2_227")) 
                                (add (size 2) (apply (ext-identifier replay_request sersize-of-row-binary) (get-alt "ReplayRequest" (param 0))))
                                (if (eq (u16 12) (identifier "label2_227")) 
                                  (add (size 2) (apply (ext-identifier alert sersize-of-row-binary) (get-alt "Alert" (param 0))))
                                  (if (eq (u16 13) (identifier "label2_227")) 
                                    (add (size 2) (apply (ext-identifier output_specs sersize-of-row-binary) (get-alt "OutputSpecs" (param 0))))
                                    (if (eq (u16 14) (identifier "label2_227")) 
                                      (add (size 2) (apply (ext-identifier dashboard_widget sersize-of-row-binary) (get-alt "DashboardWidget" (param 0))))
                                      (if (eq (u16 15) (identifier "label2_227")) 
                                        (add (size 2) (apply (ext-identifier alerting_contact sersize-of-row-binary) (get-alt "AlertingContact" (param 0))))
                                        (if (eq (u16 16) (identifier "label2_227")) 
                                          (add (size 2) (apply (ext-identifier alerting_notification sersize-of-row-binary) (get-alt "Notification" (param 0))))
                                          (if (eq (u16 17) (identifier "label2_227")) 
                                            (add (size 2) (apply (ext-identifier alerting_delivery_status sersize-of-row-binary) (get-alt "DeliveryStatus" (param 0))))
                                            (if (eq (u16 18) (identifier "label2_227")) 
                                              (add (size 2) (apply (ext-identifier alerting_log sersize-of-row-binary) (get-alt "IncidentLog" (param 0))))
                                              (seq (assert (eq (identifier "label2_227") (u16 19))) (add (size 2) (apply (ext-identifier alerting_inhibition sersize-of-row-binary) (get-alt "Inhibition" (param 0))))))))))))))))))))))))))
 */
static std::function<Size(::dessser::gen::sync_value::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_value::t*)> fun355 { [&fun355](::dessser::gen::sync_value::t* p_0) {
    uint16_t id_356 { uint16_t((*p_0).index()) };
    Size let_res_357;
    {
      uint16_t label2_227 { id_356 };
      uint16_t id_358 { 0 };
      bool id_359 { bool(id_358 == label2_227) };
      Size choose_res_360;
      if (id_359) {
        Size id_361 { 14UL };
        ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_362 { std::get<0 /* Error */>((*p_0)) };
        std::string id_363 { std::get<2>(id_362) };
        uint32_t id_364 { (uint32_t)id_363.size() };
        Vec<1, uint32_t> id_365 {  id_364  };
        Size let_res_366;
        {
          Vec<1, uint32_t> n_ref_240 { id_365 };
          uint32_t id_367 { 1U };
          Vec<1, uint32_t> id_368 {  id_367  };
          Size let_res_369;
          {
            Vec<1, uint32_t> lebsz_ref_241 { id_368 };
            bool while_flag_370 { true };
            do {
              uint8_t id_371 { 0 };
              uint32_t id_372 { n_ref_240[id_371] };
              uint8_t id_373 { 0 };
              uint32_t id_374 { lebsz_ref_241[id_373] };
              uint8_t id_375 { 7 };
              uint32_t id_376 { uint32_t(id_374 << id_375) };
              bool id_377 { bool(id_372 >= id_376) };
              while_flag_370 = id_377;
              if (while_flag_370) {
                uint8_t id_378 { 0 };
                uint8_t id_379 { 0 };
                uint32_t id_380 { lebsz_ref_241[id_379] };
                uint32_t id_381 { 1U };
                uint32_t id_382 { uint32_t(id_380 + id_381) };
                Void id_383 { ((void)(lebsz_ref_241[id_378] = id_382), VOID) };
                (void)id_383;
              }
            } while (while_flag_370);
            (void)VOID;
            uint8_t id_384 { 0 };
            uint32_t id_385 { lebsz_ref_241[id_384] };
            Size id_386 { Size(id_385) };
            let_res_369 = id_386;
          }
          let_res_366 = let_res_369;
        }
        ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_387 { std::get<0 /* Error */>((*p_0)) };
        std::string id_388 { std::get<2>(id_387) };
        uint32_t id_389 { (uint32_t)id_388.size() };
        Size id_390 { Size(id_389) };
        Size id_391 { Size(let_res_366 + id_390) };
        Size id_392 { Size(id_361 + id_391) };
        choose_res_360 = id_392;
      } else {
        uint16_t id_393 { 1 };
        bool id_394 { bool(id_393 == label2_227) };
        Size choose_res_395;
        if (id_394) {
          Size id_396 { 2UL };
          auto fun397 { dessser::gen::worker::sersize_of_row_binary };
          dessser::gen::worker::t_ext id_398 { std::get<1 /* Worker */>((*p_0)) };
          Size id_399 { fun397(id_398) };
          Size id_400 { Size(id_396 + id_399) };
          choose_res_395 = id_400;
        } else {
          uint16_t id_401 { 2 };
          bool id_402 { bool(id_401 == label2_227) };
          Size choose_res_403;
          if (id_402) {
            Size id_404 { 2UL };
            auto fun405 { dessser::gen::retention::sersize_of_row_binary };
            dessser::gen::retention::t_ext id_406 { std::get<2 /* Retention */>((*p_0)) };
            Size id_407 { fun405(id_406) };
            Size id_408 { Size(id_404 + id_407) };
            choose_res_403 = id_408;
          } else {
            uint16_t id_409 { 3 };
            bool id_410 { bool(id_409 == label2_227) };
            Size choose_res_411;
            if (id_410) {
              Size id_412 { 2UL };
              auto fun413 { dessser::gen::time_range::sersize_of_row_binary };
              dessser::gen::time_range::t_ext id_414 { std::get<3 /* TimeRange */>((*p_0)) };
              Size id_415 { fun413(id_414) };
              Size id_416 { Size(id_412 + id_415) };
              choose_res_411 = id_416;
            } else {
              uint16_t id_417 { 4 };
              bool id_418 { bool(id_417 == label2_227) };
              Size choose_res_419;
              if (id_418) {
                Size id_420 { 2UL };
                Arr<::dessser::gen::sync_value::tuple*> id_421 { std::get<4 /* Tuples */>((*p_0)) };
                uint32_t id_422 { id_421.size() };
                Vec<1, uint32_t> id_423 {  id_422  };
                Size let_res_424;
                {
                  Vec<1, uint32_t> n_ref_232 { id_423 };
                  uint32_t id_425 { 1U };
                  Vec<1, uint32_t> id_426 {  id_425  };
                  Size let_res_427;
                  {
                    Vec<1, uint32_t> lebsz_ref_233 { id_426 };
                    bool while_flag_428 { true };
                    do {
                      uint8_t id_429 { 0 };
                      uint32_t id_430 { n_ref_232[id_429] };
                      uint8_t id_431 { 0 };
                      uint32_t id_432 { lebsz_ref_233[id_431] };
                      uint8_t id_433 { 7 };
                      uint32_t id_434 { uint32_t(id_432 << id_433) };
                      bool id_435 { bool(id_430 >= id_434) };
                      while_flag_428 = id_435;
                      if (while_flag_428) {
                        uint8_t id_436 { 0 };
                        uint8_t id_437 { 0 };
                        uint32_t id_438 { lebsz_ref_233[id_437] };
                        uint32_t id_439 { 1U };
                        uint32_t id_440 { uint32_t(id_438 + id_439) };
                        Void id_441 { ((void)(lebsz_ref_233[id_436] = id_440), VOID) };
                        (void)id_441;
                      }
                    } while (while_flag_428);
                    (void)VOID;
                    uint8_t id_442 { 0 };
                    uint32_t id_443 { lebsz_ref_233[id_442] };
                    Size id_444 { Size(id_443) };
                    let_res_427 = id_444;
                  }
                  let_res_424 = let_res_427;
                }
                Size id_445 { Size(id_420 + let_res_424) };
                Vec<1, Size> id_446 {  id_445  };
                Size let_res_447;
                {
                  Vec<1, Size> sz_ref_234 { id_446 };
                  int32_t id_448 { 0L };
                  Vec<1, int32_t> id_449 {  id_448  };
                  {
                    Vec<1, int32_t> repeat_n_235 { id_449 };
                    bool while_flag_450 { true };
                    do {
                      Arr<::dessser::gen::sync_value::tuple*> id_451 { std::get<4 /* Tuples */>((*p_0)) };
                      uint32_t id_452 { id_451.size() };
                      int32_t id_453 { int32_t(id_452) };
                      uint8_t id_454 { 0 };
                      int32_t id_455 { repeat_n_235[id_454] };
                      bool id_456 { bool(id_453 > id_455) };
                      while_flag_450 = id_456;
                      if (while_flag_450) {
                        uint8_t id_457 { 0 };
                        uint8_t id_458 { 0 };
                        Size id_459 { sz_ref_234[id_458] };
                        uint8_t id_460 { 0 };
                        int32_t id_461 { repeat_n_235[id_460] };
                        Arr<::dessser::gen::sync_value::tuple*> id_462 { std::get<4 /* Tuples */>((*p_0)) };
                        ::dessser::gen::sync_value::tuple* id_463 { id_462[id_461] };
                        Size id_464 { tuple_sersize_of_row_binary(id_463) };
                        Size id_465 { Size(id_459 + id_464) };
                        Void id_466 { ((void)(sz_ref_234[id_457] = id_465), VOID) };
                        (void)id_466;
                        uint8_t id_467 { 0 };
                        uint8_t id_468 { 0 };
                        int32_t id_469 { repeat_n_235[id_468] };
                        int32_t id_470 { 1L };
                        int32_t id_471 { int32_t(id_469 + id_470) };
                        Void id_472 { ((void)(repeat_n_235[id_467] = id_471), VOID) };
                        (void)id_472;
                        (void)id_472;
                      }
                    } while (while_flag_450);
                    (void)VOID;
                  }
                  (void)VOID;
                  uint8_t id_473 { 0 };
                  Size id_474 { sz_ref_234[id_473] };
                  let_res_447 = id_474;
                }
                choose_res_419 = let_res_447;
              } else {
                uint16_t id_475 { 5 };
                bool id_476 { bool(id_475 == label2_227) };
                Size choose_res_477;
                if (id_476) {
                  Size id_478 { 2UL };
                  auto fun479 { dessser::gen::raql_value::sersize_of_row_binary };
                  dessser::gen::raql_value::t_ext id_480 { std::get<5 /* RamenValue */>((*p_0)) };
                  Size id_481 { fun479(id_480) };
                  Size id_482 { Size(id_478 + id_481) };
                  choose_res_477 = id_482;
                } else {
                  uint16_t id_483 { 6 };
                  bool id_484 { bool(id_483 == label2_227) };
                  Size choose_res_485;
                  if (id_484) {
                    Size id_486 { 2UL };
                    Arr<dessser::gen::rc_entry::t_ext> id_487 { std::get<6 /* TargetConfig */>((*p_0)) };
                    uint32_t id_488 { id_487.size() };
                    Vec<1, uint32_t> id_489 {  id_488  };
                    Size let_res_490;
                    {
                      Vec<1, uint32_t> n_ref_228 { id_489 };
                      uint32_t id_491 { 1U };
                      Vec<1, uint32_t> id_492 {  id_491  };
                      Size let_res_493;
                      {
                        Vec<1, uint32_t> lebsz_ref_229 { id_492 };
                        bool while_flag_494 { true };
                        do {
                          uint8_t id_495 { 0 };
                          uint32_t id_496 { n_ref_228[id_495] };
                          uint8_t id_497 { 0 };
                          uint32_t id_498 { lebsz_ref_229[id_497] };
                          uint8_t id_499 { 7 };
                          uint32_t id_500 { uint32_t(id_498 << id_499) };
                          bool id_501 { bool(id_496 >= id_500) };
                          while_flag_494 = id_501;
                          if (while_flag_494) {
                            uint8_t id_502 { 0 };
                            uint8_t id_503 { 0 };
                            uint32_t id_504 { lebsz_ref_229[id_503] };
                            uint32_t id_505 { 1U };
                            uint32_t id_506 { uint32_t(id_504 + id_505) };
                            Void id_507 { ((void)(lebsz_ref_229[id_502] = id_506), VOID) };
                            (void)id_507;
                          }
                        } while (while_flag_494);
                        (void)VOID;
                        uint8_t id_508 { 0 };
                        uint32_t id_509 { lebsz_ref_229[id_508] };
                        Size id_510 { Size(id_509) };
                        let_res_493 = id_510;
                      }
                      let_res_490 = let_res_493;
                    }
                    Size id_511 { Size(id_486 + let_res_490) };
                    Vec<1, Size> id_512 {  id_511  };
                    Size let_res_513;
                    {
                      Vec<1, Size> sz_ref_230 { id_512 };
                      int32_t id_514 { 0L };
                      Vec<1, int32_t> id_515 {  id_514  };
                      {
                        Vec<1, int32_t> repeat_n_231 { id_515 };
                        bool while_flag_516 { true };
                        do {
                          Arr<dessser::gen::rc_entry::t_ext> id_517 { std::get<6 /* TargetConfig */>((*p_0)) };
                          uint32_t id_518 { id_517.size() };
                          int32_t id_519 { int32_t(id_518) };
                          uint8_t id_520 { 0 };
                          int32_t id_521 { repeat_n_231[id_520] };
                          bool id_522 { bool(id_519 > id_521) };
                          while_flag_516 = id_522;
                          if (while_flag_516) {
                            uint8_t id_523 { 0 };
                            uint8_t id_524 { 0 };
                            Size id_525 { sz_ref_230[id_524] };
                            auto fun526 { dessser::gen::rc_entry::sersize_of_row_binary };
                            uint8_t id_527 { 0 };
                            int32_t id_528 { repeat_n_231[id_527] };
                            Arr<dessser::gen::rc_entry::t_ext> id_529 { std::get<6 /* TargetConfig */>((*p_0)) };
                            dessser::gen::rc_entry::t_ext id_530 { id_529[id_528] };
                            Size id_531 { fun526(id_530) };
                            Size id_532 { Size(id_525 + id_531) };
                            Void id_533 { ((void)(sz_ref_230[id_523] = id_532), VOID) };
                            (void)id_533;
                            uint8_t id_534 { 0 };
                            uint8_t id_535 { 0 };
                            int32_t id_536 { repeat_n_231[id_535] };
                            int32_t id_537 { 1L };
                            int32_t id_538 { int32_t(id_536 + id_537) };
                            Void id_539 { ((void)(repeat_n_231[id_534] = id_538), VOID) };
                            (void)id_539;
                            (void)id_539;
                          }
                        } while (while_flag_516);
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_540 { 0 };
                      Size id_541 { sz_ref_230[id_540] };
                      let_res_513 = id_541;
                    }
                    choose_res_485 = let_res_513;
                  } else {
                    uint16_t id_542 { 7 };
                    bool id_543 { bool(id_542 == label2_227) };
                    Size choose_res_544;
                    if (id_543) {
                      Size id_545 { 2UL };
                      auto fun546 { dessser::gen::source_info::sersize_of_row_binary };
                      dessser::gen::source_info::t_ext id_547 { std::get<7 /* SourceInfo */>((*p_0)) };
                      Size id_548 { fun546(id_547) };
                      Size id_549 { Size(id_545 + id_548) };
                      choose_res_544 = id_549;
                    } else {
                      uint16_t id_550 { 8 };
                      bool id_551 { bool(id_550 == label2_227) };
                      Size choose_res_552;
                      if (id_551) {
                        Size id_553 { 2UL };
                        auto fun554 { dessser::gen::runtime_stats::sersize_of_row_binary };
                        dessser::gen::runtime_stats::t_ext id_555 { std::get<8 /* RuntimeStats */>((*p_0)) };
                        Size id_556 { fun554(id_555) };
                        Size id_557 { Size(id_553 + id_556) };
                        choose_res_552 = id_557;
                      } else {
                        uint16_t id_558 { 9 };
                        bool id_559 { bool(id_558 == label2_227) };
                        Size choose_res_560;
                        if (id_559) {
                          Size id_561 { 2UL };
                          auto fun562 { dessser::gen::replay::sersize_of_row_binary };
                          dessser::gen::replay::t_ext id_563 { std::get<9 /* Replay */>((*p_0)) };
                          Size id_564 { fun562(id_563) };
                          Size id_565 { Size(id_561 + id_564) };
                          choose_res_560 = id_565;
                        } else {
                          uint16_t id_566 { 10 };
                          bool id_567 { bool(id_566 == label2_227) };
                          Size choose_res_568;
                          if (id_567) {
                            Size id_569 { 2UL };
                            auto fun570 { dessser::gen::replayer::sersize_of_row_binary };
                            dessser::gen::replayer::t_ext id_571 { std::get<10 /* Replayer */>((*p_0)) };
                            Size id_572 { fun570(id_571) };
                            Size id_573 { Size(id_569 + id_572) };
                            choose_res_568 = id_573;
                          } else {
                            uint16_t id_574 { 11 };
                            bool id_575 { bool(id_574 == label2_227) };
                            Size choose_res_576;
                            if (id_575) {
                              Size id_577 { 2UL };
                              auto fun578 { dessser::gen::replay_request::sersize_of_row_binary };
                              dessser::gen::replay_request::t_ext id_579 { std::get<11 /* ReplayRequest */>((*p_0)) };
                              Size id_580 { fun578(id_579) };
                              Size id_581 { Size(id_577 + id_580) };
                              choose_res_576 = id_581;
                            } else {
                              uint16_t id_582 { 12 };
                              bool id_583 { bool(id_582 == label2_227) };
                              Size choose_res_584;
                              if (id_583) {
                                Size id_585 { 2UL };
                                auto fun586 { dessser::gen::alert::sersize_of_row_binary };
                                dessser::gen::alert::t_ext id_587 { std::get<12 /* Alert */>((*p_0)) };
                                Size id_588 { fun586(id_587) };
                                Size id_589 { Size(id_585 + id_588) };
                                choose_res_584 = id_589;
                              } else {
                                uint16_t id_590 { 13 };
                                bool id_591 { bool(id_590 == label2_227) };
                                Size choose_res_592;
                                if (id_591) {
                                  Size id_593 { 2UL };
                                  auto fun594 { dessser::gen::output_specs::sersize_of_row_binary };
                                  dessser::gen::output_specs::t_ext id_595 { std::get<13 /* OutputSpecs */>((*p_0)) };
                                  Size id_596 { fun594(id_595) };
                                  Size id_597 { Size(id_593 + id_596) };
                                  choose_res_592 = id_597;
                                } else {
                                  uint16_t id_598 { 14 };
                                  bool id_599 { bool(id_598 == label2_227) };
                                  Size choose_res_600;
                                  if (id_599) {
                                    Size id_601 { 2UL };
                                    auto fun602 { dessser::gen::dashboard_widget::sersize_of_row_binary };
                                    dessser::gen::dashboard_widget::t_ext id_603 { std::get<14 /* DashboardWidget */>((*p_0)) };
                                    Size id_604 { fun602(id_603) };
                                    Size id_605 { Size(id_601 + id_604) };
                                    choose_res_600 = id_605;
                                  } else {
                                    uint16_t id_606 { 15 };
                                    bool id_607 { bool(id_606 == label2_227) };
                                    Size choose_res_608;
                                    if (id_607) {
                                      Size id_609 { 2UL };
                                      auto fun610 { dessser::gen::alerting_contact::sersize_of_row_binary };
                                      dessser::gen::alerting_contact::t_ext id_611 { std::get<15 /* AlertingContact */>((*p_0)) };
                                      Size id_612 { fun610(id_611) };
                                      Size id_613 { Size(id_609 + id_612) };
                                      choose_res_608 = id_613;
                                    } else {
                                      uint16_t id_614 { 16 };
                                      bool id_615 { bool(id_614 == label2_227) };
                                      Size choose_res_616;
                                      if (id_615) {
                                        Size id_617 { 2UL };
                                        auto fun618 { dessser::gen::alerting_notification::sersize_of_row_binary };
                                        dessser::gen::alerting_notification::t_ext id_619 { std::get<16 /* Notification */>((*p_0)) };
                                        Size id_620 { fun618(id_619) };
                                        Size id_621 { Size(id_617 + id_620) };
                                        choose_res_616 = id_621;
                                      } else {
                                        uint16_t id_622 { 17 };
                                        bool id_623 { bool(id_622 == label2_227) };
                                        Size choose_res_624;
                                        if (id_623) {
                                          Size id_625 { 2UL };
                                          auto fun626 { dessser::gen::alerting_delivery_status::sersize_of_row_binary };
                                          dessser::gen::alerting_delivery_status::t_ext id_627 { std::get<17 /* DeliveryStatus */>((*p_0)) };
                                          Size id_628 { fun626(id_627) };
                                          Size id_629 { Size(id_625 + id_628) };
                                          choose_res_624 = id_629;
                                        } else {
                                          uint16_t id_630 { 18 };
                                          bool id_631 { bool(id_630 == label2_227) };
                                          Size choose_res_632;
                                          if (id_631) {
                                            Size id_633 { 2UL };
                                            auto fun634 { dessser::gen::alerting_log::sersize_of_row_binary };
                                            dessser::gen::alerting_log::t_ext id_635 { std::get<18 /* IncidentLog */>((*p_0)) };
                                            Size id_636 { fun634(id_635) };
                                            Size id_637 { Size(id_633 + id_636) };
                                            choose_res_632 = id_637;
                                          } else {
                                            uint16_t id_638 { 19 };
                                            bool id_639 { bool(label2_227 == id_638) };
                                            Void id_640 { ((void)(assert(id_639)), VOID) };
                                            (void)id_640;
                                            Size id_641 { 2UL };
                                            auto fun642 { dessser::gen::alerting_inhibition::sersize_of_row_binary };
                                            dessser::gen::alerting_inhibition::t_ext id_643 { std::get<19 /* Inhibition */>((*p_0)) };
                                            Size id_644 { fun642(id_643) };
                                            Size id_645 { Size(id_641 + id_644) };
                                            choose_res_632 = id_645;
                                          }
                                          choose_res_624 = choose_res_632;
                                        }
                                        choose_res_616 = choose_res_624;
                                      }
                                      choose_res_608 = choose_res_616;
                                    }
                                    choose_res_600 = choose_res_608;
                                  }
                                  choose_res_592 = choose_res_600;
                                }
                                choose_res_584 = choose_res_592;
                              }
                              choose_res_576 = choose_res_584;
                            }
                            choose_res_568 = choose_res_576;
                          }
                          choose_res_560 = choose_res_568;
                        }
                        choose_res_552 = choose_res_560;
                      }
                      choose_res_544 = choose_res_552;
                    }
                    choose_res_485 = choose_res_544;
                  }
                  choose_res_477 = choose_res_485;
                }
                choose_res_419 = choose_res_477;
              }
              choose_res_411 = choose_res_419;
            }
            choose_res_403 = choose_res_411;
          }
          choose_res_395 = choose_res_403;
        }
        choose_res_360 = choose_res_395;
      }
      let_res_357 = choose_res_360;
    }
    return let_res_357;
  }
   };
  return fun355;
}
std::function<Size(::dessser::gen::sync_value::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_59" (let-pair "du32_fst_57" "du32_snd_58" (read-u32 little-endian (param 0)) (make-tup (identifier "du32_fst_57") (identifier "du32_snd_58")))
        (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
          (let-pair "drec_fst_72" "drec_snd_73"
            (let "dbytes1_68"
              (let "leb_ref_62" (make-vec (u32 0))
                (let "shft_ref_63" (make-vec (u8 0))
                  (let "p_ref_64" (make-vec (identifier "drec_snd_61"))
                    (seq
                      (while
                        (let "leb128_65" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_64")))
                          (let-pair "leb128_fst_66" "leb128_snd_67" (identifier "leb128_65")
                            (seq (set-vec (u8 0) (identifier "p_ref_64") (identifier "leb128_snd_67"))
                              (set-vec (u8 0) (identifier "leb_ref_62")
                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_66") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_63"))) (unsafe-nth (u8 0) (identifier "leb_ref_62"))))
                              (set-vec (u8 0) (identifier "shft_ref_63") (add (unsafe-nth (u8 0) (identifier "shft_ref_63")) (u8 7))) 
                              (ge (identifier "leb128_fst_66") (u8 128))))) 
                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_62"))) (unsafe-nth (u8 0) (identifier "p_ref_64")))))))
              (let-pair "dbytes1_fst_69" "dbytes1_snd_70" (identifier "dbytes1_68") (read-bytes (identifier "dbytes1_snd_70") (identifier "dbytes1_fst_69"))))
            (make-tup (make-rec (string "values") (identifier "drec_fst_72") (string "skipped") (identifier "drec_fst_60")) (identifier "drec_snd_73"))))))
 */
static std::function<::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597(Pointer)> tuple_of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597(Pointer)> fun646 { [&fun646](Pointer p_0) {
    ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_647 { p_0.readU32Le() };
    ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_648;
    {
      auto du32_fst_57 { std::get<0>(id_647) };
      auto du32_snd_58 { std::get<1>(id_647) };
      ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_649 { du32_fst_57, du32_snd_58 };
      letpair_res_648 = id_649;
    }
    ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 let_res_650;
    {
      ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 drec_59 { letpair_res_648 };
      ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 letpair_res_651;
      {
        auto drec_fst_60 { std::get<0>(drec_59) };
        auto drec_snd_61 { std::get<1>(drec_59) };
        uint32_t id_652 { 0U };
        Vec<1, uint32_t> id_653 {  id_652  };
        ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_654;
        {
          Vec<1, uint32_t> leb_ref_62 { id_653 };
          uint8_t id_655 { 0 };
          Vec<1, uint8_t> id_656 {  id_655  };
          ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_657;
          {
            Vec<1, uint8_t> shft_ref_63 { id_656 };
            Vec<1, Pointer> id_658 {  drec_snd_61  };
            ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_659;
            {
              Vec<1, Pointer> p_ref_64 { id_658 };
              bool while_flag_660 { true };
              do {
                uint8_t id_661 { 0 };
                Pointer id_662 { p_ref_64[id_661] };
                ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_663 { id_662.readU8() };
                bool let_res_664;
                {
                  ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_65 { id_663 };
                  bool letpair_res_665;
                  {
                    auto leb128_fst_66 { std::get<0>(leb128_65) };
                    auto leb128_snd_67 { std::get<1>(leb128_65) };
                    uint8_t id_666 { 0 };
                    Void id_667 { ((void)(p_ref_64[id_666] = leb128_snd_67), VOID) };
                    (void)id_667;
                    uint8_t id_668 { 0 };
                    uint8_t id_669 { 127 };
                    uint8_t id_670 { uint8_t(leb128_fst_66 & id_669) };
                    uint32_t id_671 { uint32_t(id_670) };
                    uint8_t id_672 { 0 };
                    uint8_t id_673 { shft_ref_63[id_672] };
                    uint32_t id_674 { uint32_t(id_671 << id_673) };
                    uint8_t id_675 { 0 };
                    uint32_t id_676 { leb_ref_62[id_675] };
                    uint32_t id_677 { uint32_t(id_674 | id_676) };
                    Void id_678 { ((void)(leb_ref_62[id_668] = id_677), VOID) };
                    (void)id_678;
                    uint8_t id_679 { 0 };
                    uint8_t id_680 { 0 };
                    uint8_t id_681 { shft_ref_63[id_680] };
                    uint8_t id_682 { 7 };
                    uint8_t id_683 { uint8_t(id_681 + id_682) };
                    Void id_684 { ((void)(shft_ref_63[id_679] = id_683), VOID) };
                    (void)id_684;
                    uint8_t id_685 { 128 };
                    bool id_686 { bool(leb128_fst_66 >= id_685) };
                    letpair_res_665 = id_686;
                  }
                  let_res_664 = letpair_res_665;
                }
                while_flag_660 = let_res_664;
                if (while_flag_660) {
                  (void)VOID;
                }
              } while (while_flag_660);
              (void)VOID;
              uint8_t id_687 { 0 };
              uint32_t id_688 { leb_ref_62[id_687] };
              Size id_689 { Size(id_688) };
              uint8_t id_690 { 0 };
              Pointer id_691 { p_ref_64[id_690] };
              ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 id_692 { id_689, id_691 };
              let_res_659 = id_692;
            }
            let_res_657 = let_res_659;
          }
          let_res_654 = let_res_657;
        }
        ::dessser::gen::sync_value::t5887709cc43c8c8e24d28211e8c970a2 let_res_693;
        {
          ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 dbytes1_68 { let_res_654 };
          ::dessser::gen::sync_value::t5887709cc43c8c8e24d28211e8c970a2 letpair_res_694;
          {
            auto dbytes1_fst_69 { std::get<0>(dbytes1_68) };
            auto dbytes1_snd_70 { std::get<1>(dbytes1_68) };
            ::dessser::gen::sync_value::t5887709cc43c8c8e24d28211e8c970a2 id_695 { dbytes1_snd_70.readBytes(dbytes1_fst_69) };
            letpair_res_694 = id_695;
          }
          let_res_693 = letpair_res_694;
        }
        ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 letpair_res_696;
        {
          auto drec_fst_72 { std::get<0>(let_res_693) };
          auto drec_snd_73 { std::get<1>(let_res_693) };
          ::dessser::gen::sync_value::tuple* id_697 { new ::dessser::gen::sync_value::tuple({ .skipped = drec_fst_60, .values = drec_fst_72 }) };
          ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 id_698 { id_697, drec_snd_73 };
          letpair_res_696 = id_698;
        }
        letpair_res_651 = letpair_res_696;
      }
      let_res_650 = letpair_res_651;
    }
    return let_res_650;
  }
   };
  return fun646;
}
std::function<::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597(Pointer)> tuple_of_row_binary(tuple_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_220" "make_snd_221"
        (let "dsum1_83" (let-pair "du16_fst_78" "du16_snd_79" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_78") (identifier "du16_snd_79")))
          (let-pair "dsum1_fst_84" "dsum1_snd_85" (identifier "dsum1_83")
            (if (eq (u16 0) (identifier "dsum1_fst_84"))
              (let "dtup_192" (let-pair "dfloat_fst_190" "dfloat_snd_191" (read-u64 little-endian (identifier "dsum1_snd_85")) (make-tup (float-of-u64 (identifier "dfloat_fst_190")) (identifier "dfloat_snd_191")))
                (let-pair "dtup_fst_193" "dtup_snd_194" (identifier "dtup_192")
                  (let "dtup_198" (let-pair "du32_fst_196" "du32_snd_197" (read-u32 little-endian (identifier "dtup_snd_194")) (make-tup (identifier "du32_fst_196") (identifier "du32_snd_197")))
                    (let-pair "dtup_fst_199" "dtup_snd_200" (identifier "dtup_198")
                      (let "dstring1_207"
                        (let "leb_ref_201" (make-vec (u32 0))
                          (let "shft_ref_202" (make-vec (u8 0))
                            (let "p_ref_203" (make-vec (identifier "dtup_snd_200"))
                              (seq
                                (while
                                  (let "leb128_204" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_203")))
                                    (let-pair "leb128_fst_205" "leb128_snd_206" 
                                      (identifier "leb128_204")
                                      (seq (set-vec (u8 0) (identifier "p_ref_203") (identifier "leb128_snd_206"))
                                        (set-vec (u8 0) (identifier "leb_ref_201")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_205") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_202"))) (unsafe-nth (u8 0) (identifier "leb_ref_201"))))
                                        (set-vec (u8 0) (identifier "shft_ref_202") (add (unsafe-nth (u8 0) (identifier "shft_ref_202")) (u8 7))) 
                                        (ge (identifier "leb128_fst_205") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_201"))) (unsafe-nth (u8 0) (identifier "p_ref_203")))))))
                        (let-pair "dstring1_fst_208" "dstring1_snd_209" 
                          (identifier "dstring1_207")
                          (let-pair "dstring2_fst_211" "dstring2_snd_212" 
                            (read-bytes (identifier "dstring1_snd_209") (identifier "dstring1_fst_208"))
                            (make-tup
                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 0
                                (make-tup (identifier "dtup_fst_193") (identifier "dtup_fst_199") (string-of-bytes (identifier "dstring2_fst_211")))) 
                              (identifier "dstring2_snd_212")))))))))
              (if (eq (u16 1) (identifier "dsum1_fst_84"))
                (let-pair "dsum2_fst_187" "dsum2_snd_188" (apply (ext-identifier worker of-row-binary) (identifier "dsum1_snd_85"))
                  (make-tup
                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 1
                      (identifier "dsum2_fst_187")) (identifier "dsum2_snd_188")))
                (if (eq (u16 2) (identifier "dsum1_fst_84"))
                  (let-pair "dsum2_fst_184" "dsum2_snd_185" (apply (ext-identifier retention of-row-binary) (identifier "dsum1_snd_85"))
                    (make-tup
                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 2
                        (identifier "dsum2_fst_184")) (identifier "dsum2_snd_185")))
                  (if (eq (u16 3) (identifier "dsum1_fst_84"))
                    (let-pair "dsum2_fst_181" "dsum2_snd_182" (apply (ext-identifier time_range of-row-binary) (identifier "dsum1_snd_85"))
                      (make-tup
                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 3
                          (identifier "dsum2_fst_181")) (identifier "dsum2_snd_182")))
                    (if (eq (u16 4) (identifier "dsum1_fst_84"))
                      (let-pair "dlist4_fst_175" "dlist4_snd_176"
                        (let "dlist1_163"
                          (let "leb_ref_154" (make-vec (u32 0))
                            (let "shft_ref_155" (make-vec (u8 0))
                              (let "p_ref_156" (make-vec (identifier "dsum1_snd_85"))
                                (seq
                                  (while
                                    (let "leb128_157" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_156")))
                                      (let-pair "leb128_fst_158" "leb128_snd_159" 
                                        (identifier "leb128_157")
                                        (seq (set-vec (u8 0) (identifier "p_ref_156") (identifier "leb128_snd_159"))
                                          (set-vec (u8 0) (identifier "leb_ref_154")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_158") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_155"))) (unsafe-nth (u8 0) (identifier "leb_ref_154"))))
                                          (set-vec (u8 0) (identifier "shft_ref_155") (add (unsafe-nth (u8 0) (identifier "shft_ref_155")) (u8 7))) 
                                          (ge (identifier "leb128_fst_158") (u8 128))))) 
                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_154")) (unsafe-nth (u8 0) (identifier "p_ref_156")))))))
                          (let-pair "dlist1_fst_164" "dlist1_snd_165" 
                            (identifier "dlist1_163")
                            (let "inits_src_ref_166" (make-vec (make-tup (end-of-list "(tuple AS {skipped: U32; values: Bytes})") (identifier "dlist1_snd_165")))
                              (seq
                                (let "repeat_n_167" (make-vec (i32 0))
                                  (while (gt (to-i32 (identifier "dlist1_fst_164")) (unsafe-nth (u8 0) (identifier "repeat_n_167")))
                                    (seq
                                      (let "dlist2_168" (unsafe-nth (u8 0) (identifier "inits_src_ref_166"))
                                        (let-pair "dlist2_fst_169" "dlist2_snd_170" 
                                          (identifier "dlist2_168")
                                          (set-vec (u8 0) (identifier "inits_src_ref_166")
                                            (let-pair "dlist3_fst_172" "dlist3_snd_173" 
                                              (apply (identifier "tuple-of-row-binary") (identifier "dlist2_snd_170")) 
                                              (make-tup (cons (identifier "dlist3_fst_172") (identifier "dlist2_fst_169")) (identifier "dlist3_snd_173"))))))
                                      (set-vec (u8 0) (identifier "repeat_n_167") (add (unsafe-nth (u8 0) (identifier "repeat_n_167")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "inits_src_ref_166"))))))
                        (make-tup
                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 4
                            (arr-of-lst-rev (identifier "dlist4_fst_175"))) 
                          (identifier "dlist4_snd_176")))
                      (if (eq (u16 5) (identifier "dsum1_fst_84"))
                        (let-pair "dsum2_fst_152" "dsum2_snd_153" (apply (ext-identifier raql_value of-row-binary) (identifier "dsum1_snd_85"))
                          (make-tup
                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 5
                              (identifier "dsum2_fst_152")) (identifier "dsum2_snd_153")))
                        (if (eq (u16 6) (identifier "dsum1_fst_84"))
                          (let-pair "dlist4_fst_146" "dlist4_snd_147"
                            (let "dlist1_134"
                              (let "leb_ref_125" (make-vec (u32 0))
                                (let "shft_ref_126" (make-vec (u8 0))
                                  (let "p_ref_127" (make-vec (identifier "dsum1_snd_85"))
                                    (seq
                                      (while
                                        (let "leb128_128" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_127")))
                                          (let-pair "leb128_fst_129" "leb128_snd_130" 
                                            (identifier "leb128_128")
                                            (seq (set-vec (u8 0) (identifier "p_ref_127") (identifier "leb128_snd_130"))
                                              (set-vec (u8 0) (identifier "leb_ref_125")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_129") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_126"))) (unsafe-nth (u8 0) (identifier "leb_ref_125"))))
                                              (set-vec (u8 0) (identifier "shft_ref_126") (add (unsafe-nth (u8 0) (identifier "shft_ref_126")) (u8 7))) 
                                              (ge (identifier "leb128_fst_129") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_125")) (unsafe-nth (u8 0) (identifier "p_ref_127")))))))
                              (let-pair "dlist1_fst_135" "dlist1_snd_136" 
                                (identifier "dlist1_134")
                                (let "inits_src_ref_137" (make-vec (make-tup (end-of-list "$rc_entry") (identifier "dlist1_snd_136")))
                                  (seq
                                    (let "repeat_n_138" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_135")) (unsafe-nth (u8 0) (identifier "repeat_n_138")))
                                        (seq
                                          (let "dlist2_139" (unsafe-nth (u8 0) (identifier "inits_src_ref_137"))
                                            (let-pair "dlist2_fst_140" "dlist2_snd_141" 
                                              (identifier "dlist2_139")
                                              (set-vec (u8 0) (identifier "inits_src_ref_137")
                                                (let-pair "dlist3_fst_143" "dlist3_snd_144" 
                                                  (apply (ext-identifier rc_entry of-row-binary) (identifier "dlist2_snd_141"))
                                                  (make-tup (cons (identifier "dlist3_fst_143") (identifier "dlist2_fst_140")) (identifier "dlist3_snd_144"))))))
                                          (set-vec (u8 0) (identifier "repeat_n_138") (add (unsafe-nth (u8 0) (identifier "repeat_n_138")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_137"))))))
                            (make-tup
                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 6
                                (arr-of-lst-rev (identifier "dlist4_fst_146"))) 
                              (identifier "dlist4_snd_147")))
                          (if (eq (u16 7) (identifier "dsum1_fst_84"))
                            (let-pair "dsum2_fst_123" "dsum2_snd_124" 
                              (apply (ext-identifier source_info of-row-binary) (identifier "dsum1_snd_85"))
                              (make-tup
                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 7
                                  (identifier "dsum2_fst_123")) (identifier "dsum2_snd_124")))
                            (if (eq (u16 8) (identifier "dsum1_fst_84"))
                              (let-pair "dsum2_fst_120" "dsum2_snd_121" 
                                (apply (ext-identifier runtime_stats of-row-binary) (identifier "dsum1_snd_85"))
                                (make-tup
                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 8
                                    (identifier "dsum2_fst_120")) (identifier "dsum2_snd_121")))
                              (if (eq (u16 9) (identifier "dsum1_fst_84"))
                                (let-pair "dsum2_fst_117" "dsum2_snd_118" 
                                  (apply (ext-identifier replay of-row-binary) (identifier "dsum1_snd_85"))
                                  (make-tup
                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 9
                                      (identifier "dsum2_fst_117")) (identifier "dsum2_snd_118")))
                                (if (eq (u16 10) (identifier "dsum1_fst_84"))
                                  (let-pair "dsum2_fst_114" "dsum2_snd_115" 
                                    (apply (ext-identifier replayer of-row-binary) (identifier "dsum1_snd_85"))
                                    (make-tup
                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 10
                                        (identifier "dsum2_fst_114")) 
                                      (identifier "dsum2_snd_115")))
                                  (if (eq (u16 11) (identifier "dsum1_fst_84"))
                                    (let-pair "dsum2_fst_111" "dsum2_snd_112" 
                                      (apply (ext-identifier replay_request of-row-binary) (identifier "dsum1_snd_85"))
                                      (make-tup
                                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 11
                                          (identifier "dsum2_fst_111")) 
                                        (identifier "dsum2_snd_112")))
                                    (if (eq (u16 12) (identifier "dsum1_fst_84"))
                                      (let-pair "dsum2_fst_108" "dsum2_snd_109" 
                                        (apply (ext-identifier alert of-row-binary) (identifier "dsum1_snd_85"))
                                        (make-tup
                                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 12
                                            (identifier "dsum2_fst_108")) 
                                          (identifier "dsum2_snd_109")))
                                      (if (eq (u16 13) (identifier "dsum1_fst_84"))
                                        (let-pair "dsum2_fst_105" "dsum2_snd_106" 
                                          (apply (ext-identifier output_specs of-row-binary) (identifier "dsum1_snd_85"))
                                          (make-tup
                                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 13
                                              (identifier "dsum2_fst_105")) 
                                            (identifier "dsum2_snd_106")))
                                        (if (eq (u16 14) (identifier "dsum1_fst_84"))
                                          (let-pair "dsum2_fst_102" "dsum2_snd_103" 
                                            (apply (ext-identifier dashboard_widget of-row-binary) (identifier "dsum1_snd_85"))
                                            (make-tup
                                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 14
                                                (identifier "dsum2_fst_102")) 
                                              (identifier "dsum2_snd_103")))
                                          (if (eq (u16 15) (identifier "dsum1_fst_84"))
                                            (let-pair "dsum2_fst_99" "dsum2_snd_100" 
                                              (apply (ext-identifier alerting_contact of-row-binary) (identifier "dsum1_snd_85"))
                                              (make-tup
                                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 15
                                                  (identifier "dsum2_fst_99")) 
                                                (identifier "dsum2_snd_100")))
                                            (if (eq (u16 16) (identifier "dsum1_fst_84"))
                                              (let-pair "dsum2_fst_96" "dsum2_snd_97" 
                                                (apply (ext-identifier alerting_notification of-row-binary) (identifier "dsum1_snd_85"))
                                                (make-tup
                                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 16
                                                    (identifier "dsum2_fst_96")) 
                                                  (identifier "dsum2_snd_97")))
                                              (if (eq (u16 17) (identifier "dsum1_fst_84"))
                                                (let-pair "dsum2_fst_93" "dsum2_snd_94" 
                                                  (apply (ext-identifier alerting_delivery_status of-row-binary) (identifier "dsum1_snd_85"))
                                                  (make-tup
                                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 17
                                                      (identifier "dsum2_fst_93")) 
                                                    (identifier "dsum2_snd_94")))
                                                (if (eq (u16 18) (identifier "dsum1_fst_84"))
                                                  (let-pair "dsum2_fst_90" "dsum2_snd_91" 
                                                    (apply (ext-identifier alerting_log of-row-binary) (identifier "dsum1_snd_85"))
                                                    (make-tup
                                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 18
                                                        (identifier "dsum2_fst_90")) 
                                                      (identifier "dsum2_snd_91")))
                                                  (seq (assert (eq (identifier "dsum1_fst_84") (u16 19)))
                                                    (let-pair "dsum2_fst_87" "dsum2_snd_88" 
                                                      (apply (ext-identifier alerting_inhibition of-row-binary) (identifier "dsum1_snd_85"))
                                                      (make-tup
                                                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 19
                                                          (identifier "dsum2_fst_87")) 
                                                        (identifier "dsum2_snd_88"))))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_220") (identifier "make_snd_221"))))
 */
static std::function<::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987(Pointer)> fun699 { [&fun699](Pointer p_0) {
    ::dessser::gen::sync_value::t7609d344c1ba69d0f80fec236d4c216b id_700 { p_0.readU16Le() };
    ::dessser::gen::sync_value::t7609d344c1ba69d0f80fec236d4c216b letpair_res_701;
    {
      auto du16_fst_78 { std::get<0>(id_700) };
      auto du16_snd_79 { std::get<1>(id_700) };
      ::dessser::gen::sync_value::t7609d344c1ba69d0f80fec236d4c216b id_702 { du16_fst_78, du16_snd_79 };
      letpair_res_701 = id_702;
    }
    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 let_res_703;
    {
      ::dessser::gen::sync_value::t7609d344c1ba69d0f80fec236d4c216b dsum1_83 { letpair_res_701 };
      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_704;
      {
        auto dsum1_fst_84 { std::get<0>(dsum1_83) };
        auto dsum1_snd_85 { std::get<1>(dsum1_83) };
        uint16_t id_705 { 0 };
        bool id_706 { bool(id_705 == dsum1_fst_84) };
        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_707;
        if (id_706) {
          ::dessser::gen::sync_value::tf568409f41c9c0a265f7302110fc9084 id_708 { dsum1_snd_85.readU64Le() };
          ::dessser::gen::sync_value::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_709;
          {
            auto dfloat_fst_190 { std::get<0>(id_708) };
            auto dfloat_snd_191 { std::get<1>(id_708) };
            double id_710 { float_of_qword(dfloat_fst_190) };
            ::dessser::gen::sync_value::t5375de390f9cb5ae2ee5880ea1674828 id_711 { id_710, dfloat_snd_191 };
            letpair_res_709 = id_711;
          }
          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 let_res_712;
          {
            ::dessser::gen::sync_value::t5375de390f9cb5ae2ee5880ea1674828 dtup_192 { letpair_res_709 };
            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_713;
            {
              auto dtup_fst_193 { std::get<0>(dtup_192) };
              auto dtup_snd_194 { std::get<1>(dtup_192) };
              ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_714 { dtup_snd_194.readU32Le() };
              ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_715;
              {
                auto du32_fst_196 { std::get<0>(id_714) };
                auto du32_snd_197 { std::get<1>(id_714) };
                ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_716 { du32_fst_196, du32_snd_197 };
                letpair_res_715 = id_716;
              }
              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 let_res_717;
              {
                ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 dtup_198 { letpair_res_715 };
                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_718;
                {
                  auto dtup_fst_199 { std::get<0>(dtup_198) };
                  auto dtup_snd_200 { std::get<1>(dtup_198) };
                  uint32_t id_719 { 0U };
                  Vec<1, uint32_t> id_720 {  id_719  };
                  ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_721;
                  {
                    Vec<1, uint32_t> leb_ref_201 { id_720 };
                    uint8_t id_722 { 0 };
                    Vec<1, uint8_t> id_723 {  id_722  };
                    ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_724;
                    {
                      Vec<1, uint8_t> shft_ref_202 { id_723 };
                      Vec<1, Pointer> id_725 {  dtup_snd_200  };
                      ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_726;
                      {
                        Vec<1, Pointer> p_ref_203 { id_725 };
                        bool while_flag_727 { true };
                        do {
                          uint8_t id_728 { 0 };
                          Pointer id_729 { p_ref_203[id_728] };
                          ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_730 { id_729.readU8() };
                          bool let_res_731;
                          {
                            ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_204 { id_730 };
                            bool letpair_res_732;
                            {
                              auto leb128_fst_205 { std::get<0>(leb128_204) };
                              auto leb128_snd_206 { std::get<1>(leb128_204) };
                              uint8_t id_733 { 0 };
                              Void id_734 { ((void)(p_ref_203[id_733] = leb128_snd_206), VOID) };
                              (void)id_734;
                              uint8_t id_735 { 0 };
                              uint8_t id_736 { 127 };
                              uint8_t id_737 { uint8_t(leb128_fst_205 & id_736) };
                              uint32_t id_738 { uint32_t(id_737) };
                              uint8_t id_739 { 0 };
                              uint8_t id_740 { shft_ref_202[id_739] };
                              uint32_t id_741 { uint32_t(id_738 << id_740) };
                              uint8_t id_742 { 0 };
                              uint32_t id_743 { leb_ref_201[id_742] };
                              uint32_t id_744 { uint32_t(id_741 | id_743) };
                              Void id_745 { ((void)(leb_ref_201[id_735] = id_744), VOID) };
                              (void)id_745;
                              uint8_t id_746 { 0 };
                              uint8_t id_747 { 0 };
                              uint8_t id_748 { shft_ref_202[id_747] };
                              uint8_t id_749 { 7 };
                              uint8_t id_750 { uint8_t(id_748 + id_749) };
                              Void id_751 { ((void)(shft_ref_202[id_746] = id_750), VOID) };
                              (void)id_751;
                              uint8_t id_752 { 128 };
                              bool id_753 { bool(leb128_fst_205 >= id_752) };
                              letpair_res_732 = id_753;
                            }
                            let_res_731 = letpair_res_732;
                          }
                          while_flag_727 = let_res_731;
                          if (while_flag_727) {
                            (void)VOID;
                          }
                        } while (while_flag_727);
                        (void)VOID;
                        uint8_t id_754 { 0 };
                        uint32_t id_755 { leb_ref_201[id_754] };
                        Size id_756 { Size(id_755) };
                        uint8_t id_757 { 0 };
                        Pointer id_758 { p_ref_203[id_757] };
                        ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 id_759 { id_756, id_758 };
                        let_res_726 = id_759;
                      }
                      let_res_724 = let_res_726;
                    }
                    let_res_721 = let_res_724;
                  }
                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 let_res_760;
                  {
                    ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 dstring1_207 { let_res_721 };
                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_761;
                    {
                      auto dstring1_fst_208 { std::get<0>(dstring1_207) };
                      auto dstring1_snd_209 { std::get<1>(dstring1_207) };
                      ::dessser::gen::sync_value::t5887709cc43c8c8e24d28211e8c970a2 id_762 { dstring1_snd_209.readBytes(dstring1_fst_208) };
                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_763;
                      {
                        auto dstring2_fst_211 { std::get<0>(id_762) };
                        auto dstring2_snd_212 { std::get<1>(id_762) };
                        std::string id_764 { dstring2_fst_211.toString() };
                        ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_765 { dtup_fst_193, dtup_fst_199, id_764 };
                        ::dessser::gen::sync_value::t* id_766 { new ::dessser::gen::sync_value::t(std::in_place_index<0>, id_765) };
                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_767 { id_766, dstring2_snd_212 };
                        letpair_res_763 = id_767;
                      }
                      letpair_res_761 = letpair_res_763;
                    }
                    let_res_760 = letpair_res_761;
                  }
                  letpair_res_718 = let_res_760;
                }
                let_res_717 = letpair_res_718;
              }
              letpair_res_713 = let_res_717;
            }
            let_res_712 = letpair_res_713;
          }
          choose_res_707 = let_res_712;
        } else {
          uint16_t id_768 { 1 };
          bool id_769 { bool(id_768 == dsum1_fst_84) };
          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_770;
          if (id_769) {
            auto fun771 { dessser::gen::worker::of_row_binary };
            ::dessser::gen::sync_value::t9833ef1b01f7f7d46ad878fb0cee5e03 id_772 { fun771(dsum1_snd_85) };
            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_773;
            {
              auto dsum2_fst_187 { std::get<0>(id_772) };
              auto dsum2_snd_188 { std::get<1>(id_772) };
              ::dessser::gen::sync_value::t* id_774 { new ::dessser::gen::sync_value::t(std::in_place_index<1>, dsum2_fst_187) };
              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_775 { id_774, dsum2_snd_188 };
              letpair_res_773 = id_775;
            }
            choose_res_770 = letpair_res_773;
          } else {
            uint16_t id_776 { 2 };
            bool id_777 { bool(id_776 == dsum1_fst_84) };
            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_778;
            if (id_777) {
              auto fun779 { dessser::gen::retention::of_row_binary };
              ::dessser::gen::sync_value::t6c4cb47132b52abf02e5ac7e5e40d7ce id_780 { fun779(dsum1_snd_85) };
              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_781;
              {
                auto dsum2_fst_184 { std::get<0>(id_780) };
                auto dsum2_snd_185 { std::get<1>(id_780) };
                ::dessser::gen::sync_value::t* id_782 { new ::dessser::gen::sync_value::t(std::in_place_index<2>, dsum2_fst_184) };
                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_783 { id_782, dsum2_snd_185 };
                letpair_res_781 = id_783;
              }
              choose_res_778 = letpair_res_781;
            } else {
              uint16_t id_784 { 3 };
              bool id_785 { bool(id_784 == dsum1_fst_84) };
              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_786;
              if (id_785) {
                auto fun787 { dessser::gen::time_range::of_row_binary };
                ::dessser::gen::sync_value::t12b2d6d50de8cb59e40a3787e527a60e id_788 { fun787(dsum1_snd_85) };
                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_789;
                {
                  auto dsum2_fst_181 { std::get<0>(id_788) };
                  auto dsum2_snd_182 { std::get<1>(id_788) };
                  ::dessser::gen::sync_value::t* id_790 { new ::dessser::gen::sync_value::t(std::in_place_index<3>, dsum2_fst_181) };
                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_791 { id_790, dsum2_snd_182 };
                  letpair_res_789 = id_791;
                }
                choose_res_786 = letpair_res_789;
              } else {
                uint16_t id_792 { 4 };
                bool id_793 { bool(id_792 == dsum1_fst_84) };
                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_794;
                if (id_793) {
                  uint32_t id_795 { 0U };
                  Vec<1, uint32_t> id_796 {  id_795  };
                  ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_797;
                  {
                    Vec<1, uint32_t> leb_ref_154 { id_796 };
                    uint8_t id_798 { 0 };
                    Vec<1, uint8_t> id_799 {  id_798  };
                    ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_800;
                    {
                      Vec<1, uint8_t> shft_ref_155 { id_799 };
                      Vec<1, Pointer> id_801 {  dsum1_snd_85  };
                      ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_802;
                      {
                        Vec<1, Pointer> p_ref_156 { id_801 };
                        bool while_flag_803 { true };
                        do {
                          uint8_t id_804 { 0 };
                          Pointer id_805 { p_ref_156[id_804] };
                          ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_806 { id_805.readU8() };
                          bool let_res_807;
                          {
                            ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_157 { id_806 };
                            bool letpair_res_808;
                            {
                              auto leb128_fst_158 { std::get<0>(leb128_157) };
                              auto leb128_snd_159 { std::get<1>(leb128_157) };
                              uint8_t id_809 { 0 };
                              Void id_810 { ((void)(p_ref_156[id_809] = leb128_snd_159), VOID) };
                              (void)id_810;
                              uint8_t id_811 { 0 };
                              uint8_t id_812 { 127 };
                              uint8_t id_813 { uint8_t(leb128_fst_158 & id_812) };
                              uint32_t id_814 { uint32_t(id_813) };
                              uint8_t id_815 { 0 };
                              uint8_t id_816 { shft_ref_155[id_815] };
                              uint32_t id_817 { uint32_t(id_814 << id_816) };
                              uint8_t id_818 { 0 };
                              uint32_t id_819 { leb_ref_154[id_818] };
                              uint32_t id_820 { uint32_t(id_817 | id_819) };
                              Void id_821 { ((void)(leb_ref_154[id_811] = id_820), VOID) };
                              (void)id_821;
                              uint8_t id_822 { 0 };
                              uint8_t id_823 { 0 };
                              uint8_t id_824 { shft_ref_155[id_823] };
                              uint8_t id_825 { 7 };
                              uint8_t id_826 { uint8_t(id_824 + id_825) };
                              Void id_827 { ((void)(shft_ref_155[id_822] = id_826), VOID) };
                              (void)id_827;
                              uint8_t id_828 { 128 };
                              bool id_829 { bool(leb128_fst_158 >= id_828) };
                              letpair_res_808 = id_829;
                            }
                            let_res_807 = letpair_res_808;
                          }
                          while_flag_803 = let_res_807;
                          if (while_flag_803) {
                            (void)VOID;
                          }
                        } while (while_flag_803);
                        (void)VOID;
                        uint8_t id_830 { 0 };
                        uint32_t id_831 { leb_ref_154[id_830] };
                        uint8_t id_832 { 0 };
                        Pointer id_833 { p_ref_156[id_832] };
                        ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_834 { id_831, id_833 };
                        let_res_802 = id_834;
                      }
                      let_res_800 = let_res_802;
                    }
                    let_res_797 = let_res_800;
                  }
                  ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 let_res_835;
                  {
                    ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 dlist1_163 { let_res_797 };
                    ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 letpair_res_836;
                    {
                      auto dlist1_fst_164 { std::get<0>(dlist1_163) };
                      auto dlist1_snd_165 { std::get<1>(dlist1_163) };
                      Lst<::dessser::gen::sync_value::tuple*> endoflist_837;
                      ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 id_838 { endoflist_837, dlist1_snd_165 };
                      Vec<1, ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7> id_839 {  id_838  };
                      ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 let_res_840;
                      {
                        Vec<1, ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7> inits_src_ref_166 { id_839 };
                        int32_t id_841 { 0L };
                        Vec<1, int32_t> id_842 {  id_841  };
                        {
                          Vec<1, int32_t> repeat_n_167 { id_842 };
                          bool while_flag_843 { true };
                          do {
                            int32_t id_844 { int32_t(dlist1_fst_164) };
                            uint8_t id_845 { 0 };
                            int32_t id_846 { repeat_n_167[id_845] };
                            bool id_847 { bool(id_844 > id_846) };
                            while_flag_843 = id_847;
                            if (while_flag_843) {
                              uint8_t id_848 { 0 };
                              ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 id_849 { inits_src_ref_166[id_848] };
                              {
                                ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 dlist2_168 { id_849 };
                                {
                                  auto dlist2_fst_169 { std::get<0>(dlist2_168) };
                                  auto dlist2_snd_170 { std::get<1>(dlist2_168) };
                                  uint8_t id_850 { 0 };
                                  ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 id_851 { tuple_of_row_binary(dlist2_snd_170) };
                                  ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 letpair_res_852;
                                  {
                                    auto dlist3_fst_172 { std::get<0>(id_851) };
                                    auto dlist3_snd_173 { std::get<1>(id_851) };
                                    Lst<::dessser::gen::sync_value::tuple*> id_853 { dlist3_fst_172, dlist2_fst_169 };
                                    ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 id_854 { id_853, dlist3_snd_173 };
                                    letpair_res_852 = id_854;
                                  }
                                  Void id_855 { ((void)(inits_src_ref_166[id_850] = letpair_res_852), VOID) };
                                  (void)id_855;
                                }
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_856 { 0 };
                              uint8_t id_857 { 0 };
                              int32_t id_858 { repeat_n_167[id_857] };
                              int32_t id_859 { 1L };
                              int32_t id_860 { int32_t(id_858 + id_859) };
                              Void id_861 { ((void)(repeat_n_167[id_856] = id_860), VOID) };
                              (void)id_861;
                              (void)id_861;
                            }
                          } while (while_flag_843);
                          (void)VOID;
                        }
                        (void)VOID;
                        uint8_t id_862 { 0 };
                        ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 id_863 { inits_src_ref_166[id_862] };
                        let_res_840 = id_863;
                      }
                      letpair_res_836 = let_res_840;
                    }
                    let_res_835 = letpair_res_836;
                  }
                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_864;
                  {
                    auto dlist4_fst_175 { std::get<0>(let_res_835) };
                    auto dlist4_snd_176 { std::get<1>(let_res_835) };
                    Arr<::dessser::gen::sync_value::tuple*> id_865 { dlist4_fst_175.toListRev() };
                    ::dessser::gen::sync_value::t* id_866 { new ::dessser::gen::sync_value::t(std::in_place_index<4>, id_865) };
                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_867 { id_866, dlist4_snd_176 };
                    letpair_res_864 = id_867;
                  }
                  choose_res_794 = letpair_res_864;
                } else {
                  uint16_t id_868 { 5 };
                  bool id_869 { bool(id_868 == dsum1_fst_84) };
                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_870;
                  if (id_869) {
                    auto fun871 { dessser::gen::raql_value::of_row_binary };
                    ::dessser::gen::sync_value::td46b7b5194a84c2e11400d9ca5d84700 id_872 { fun871(dsum1_snd_85) };
                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_873;
                    {
                      auto dsum2_fst_152 { std::get<0>(id_872) };
                      auto dsum2_snd_153 { std::get<1>(id_872) };
                      ::dessser::gen::sync_value::t* id_874 { new ::dessser::gen::sync_value::t(std::in_place_index<5>, dsum2_fst_152) };
                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_875 { id_874, dsum2_snd_153 };
                      letpair_res_873 = id_875;
                    }
                    choose_res_870 = letpair_res_873;
                  } else {
                    uint16_t id_876 { 6 };
                    bool id_877 { bool(id_876 == dsum1_fst_84) };
                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_878;
                    if (id_877) {
                      uint32_t id_879 { 0U };
                      Vec<1, uint32_t> id_880 {  id_879  };
                      ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_881;
                      {
                        Vec<1, uint32_t> leb_ref_125 { id_880 };
                        uint8_t id_882 { 0 };
                        Vec<1, uint8_t> id_883 {  id_882  };
                        ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_884;
                        {
                          Vec<1, uint8_t> shft_ref_126 { id_883 };
                          Vec<1, Pointer> id_885 {  dsum1_snd_85  };
                          ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_886;
                          {
                            Vec<1, Pointer> p_ref_127 { id_885 };
                            bool while_flag_887 { true };
                            do {
                              uint8_t id_888 { 0 };
                              Pointer id_889 { p_ref_127[id_888] };
                              ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_890 { id_889.readU8() };
                              bool let_res_891;
                              {
                                ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_128 { id_890 };
                                bool letpair_res_892;
                                {
                                  auto leb128_fst_129 { std::get<0>(leb128_128) };
                                  auto leb128_snd_130 { std::get<1>(leb128_128) };
                                  uint8_t id_893 { 0 };
                                  Void id_894 { ((void)(p_ref_127[id_893] = leb128_snd_130), VOID) };
                                  (void)id_894;
                                  uint8_t id_895 { 0 };
                                  uint8_t id_896 { 127 };
                                  uint8_t id_897 { uint8_t(leb128_fst_129 & id_896) };
                                  uint32_t id_898 { uint32_t(id_897) };
                                  uint8_t id_899 { 0 };
                                  uint8_t id_900 { shft_ref_126[id_899] };
                                  uint32_t id_901 { uint32_t(id_898 << id_900) };
                                  uint8_t id_902 { 0 };
                                  uint32_t id_903 { leb_ref_125[id_902] };
                                  uint32_t id_904 { uint32_t(id_901 | id_903) };
                                  Void id_905 { ((void)(leb_ref_125[id_895] = id_904), VOID) };
                                  (void)id_905;
                                  uint8_t id_906 { 0 };
                                  uint8_t id_907 { 0 };
                                  uint8_t id_908 { shft_ref_126[id_907] };
                                  uint8_t id_909 { 7 };
                                  uint8_t id_910 { uint8_t(id_908 + id_909) };
                                  Void id_911 { ((void)(shft_ref_126[id_906] = id_910), VOID) };
                                  (void)id_911;
                                  uint8_t id_912 { 128 };
                                  bool id_913 { bool(leb128_fst_129 >= id_912) };
                                  letpair_res_892 = id_913;
                                }
                                let_res_891 = letpair_res_892;
                              }
                              while_flag_887 = let_res_891;
                              if (while_flag_887) {
                                (void)VOID;
                              }
                            } while (while_flag_887);
                            (void)VOID;
                            uint8_t id_914 { 0 };
                            uint32_t id_915 { leb_ref_125[id_914] };
                            uint8_t id_916 { 0 };
                            Pointer id_917 { p_ref_127[id_916] };
                            ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_918 { id_915, id_917 };
                            let_res_886 = id_918;
                          }
                          let_res_884 = let_res_886;
                        }
                        let_res_881 = let_res_884;
                      }
                      ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d let_res_919;
                      {
                        ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 dlist1_134 { let_res_881 };
                        ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d letpair_res_920;
                        {
                          auto dlist1_fst_135 { std::get<0>(dlist1_134) };
                          auto dlist1_snd_136 { std::get<1>(dlist1_134) };
                          Lst<dessser::gen::rc_entry::t_ext> endoflist_921;
                          ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d id_922 { endoflist_921, dlist1_snd_136 };
                          Vec<1, ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d> id_923 {  id_922  };
                          ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d let_res_924;
                          {
                            Vec<1, ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d> inits_src_ref_137 { id_923 };
                            int32_t id_925 { 0L };
                            Vec<1, int32_t> id_926 {  id_925  };
                            {
                              Vec<1, int32_t> repeat_n_138 { id_926 };
                              bool while_flag_927 { true };
                              do {
                                int32_t id_928 { int32_t(dlist1_fst_135) };
                                uint8_t id_929 { 0 };
                                int32_t id_930 { repeat_n_138[id_929] };
                                bool id_931 { bool(id_928 > id_930) };
                                while_flag_927 = id_931;
                                if (while_flag_927) {
                                  uint8_t id_932 { 0 };
                                  ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d id_933 { inits_src_ref_137[id_932] };
                                  {
                                    ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d dlist2_139 { id_933 };
                                    {
                                      auto dlist2_fst_140 { std::get<0>(dlist2_139) };
                                      auto dlist2_snd_141 { std::get<1>(dlist2_139) };
                                      uint8_t id_934 { 0 };
                                      auto fun935 { dessser::gen::rc_entry::of_row_binary };
                                      ::dessser::gen::sync_value::t202b6f59dcbeb7de4acd5e3a8ac11097 id_936 { fun935(dlist2_snd_141) };
                                      ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d letpair_res_937;
                                      {
                                        auto dlist3_fst_143 { std::get<0>(id_936) };
                                        auto dlist3_snd_144 { std::get<1>(id_936) };
                                        Lst<dessser::gen::rc_entry::t_ext> id_938 { dlist3_fst_143, dlist2_fst_140 };
                                        ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d id_939 { id_938, dlist3_snd_144 };
                                        letpair_res_937 = id_939;
                                      }
                                      Void id_940 { ((void)(inits_src_ref_137[id_934] = letpair_res_937), VOID) };
                                      (void)id_940;
                                    }
                                    (void)VOID;
                                  }
                                  (void)VOID;
                                  uint8_t id_941 { 0 };
                                  uint8_t id_942 { 0 };
                                  int32_t id_943 { repeat_n_138[id_942] };
                                  int32_t id_944 { 1L };
                                  int32_t id_945 { int32_t(id_943 + id_944) };
                                  Void id_946 { ((void)(repeat_n_138[id_941] = id_945), VOID) };
                                  (void)id_946;
                                  (void)id_946;
                                }
                              } while (while_flag_927);
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_947 { 0 };
                            ::dessser::gen::sync_value::t00766d71c0212d72438b86a52d918f8d id_948 { inits_src_ref_137[id_947] };
                            let_res_924 = id_948;
                          }
                          letpair_res_920 = let_res_924;
                        }
                        let_res_919 = letpair_res_920;
                      }
                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_949;
                      {
                        auto dlist4_fst_146 { std::get<0>(let_res_919) };
                        auto dlist4_snd_147 { std::get<1>(let_res_919) };
                        Arr<dessser::gen::rc_entry::t_ext> id_950 { dlist4_fst_146.toListRev() };
                        ::dessser::gen::sync_value::t* id_951 { new ::dessser::gen::sync_value::t(std::in_place_index<6>, id_950) };
                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_952 { id_951, dlist4_snd_147 };
                        letpair_res_949 = id_952;
                      }
                      choose_res_878 = letpair_res_949;
                    } else {
                      uint16_t id_953 { 7 };
                      bool id_954 { bool(id_953 == dsum1_fst_84) };
                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_955;
                      if (id_954) {
                        auto fun956 { dessser::gen::source_info::of_row_binary };
                        ::dessser::gen::sync_value::t5ca88dae2022f5a9e0892d73f97aaa1a id_957 { fun956(dsum1_snd_85) };
                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_958;
                        {
                          auto dsum2_fst_123 { std::get<0>(id_957) };
                          auto dsum2_snd_124 { std::get<1>(id_957) };
                          ::dessser::gen::sync_value::t* id_959 { new ::dessser::gen::sync_value::t(std::in_place_index<7>, dsum2_fst_123) };
                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_960 { id_959, dsum2_snd_124 };
                          letpair_res_958 = id_960;
                        }
                        choose_res_955 = letpair_res_958;
                      } else {
                        uint16_t id_961 { 8 };
                        bool id_962 { bool(id_961 == dsum1_fst_84) };
                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_963;
                        if (id_962) {
                          auto fun964 { dessser::gen::runtime_stats::of_row_binary };
                          ::dessser::gen::sync_value::t287140549af6d490d4ffca187c95f6c7 id_965 { fun964(dsum1_snd_85) };
                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_966;
                          {
                            auto dsum2_fst_120 { std::get<0>(id_965) };
                            auto dsum2_snd_121 { std::get<1>(id_965) };
                            ::dessser::gen::sync_value::t* id_967 { new ::dessser::gen::sync_value::t(std::in_place_index<8>, dsum2_fst_120) };
                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_968 { id_967, dsum2_snd_121 };
                            letpair_res_966 = id_968;
                          }
                          choose_res_963 = letpair_res_966;
                        } else {
                          uint16_t id_969 { 9 };
                          bool id_970 { bool(id_969 == dsum1_fst_84) };
                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_971;
                          if (id_970) {
                            auto fun972 { dessser::gen::replay::of_row_binary };
                            ::dessser::gen::sync_value::t7853d7746da7c44760583c16a8bef7bc id_973 { fun972(dsum1_snd_85) };
                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_974;
                            {
                              auto dsum2_fst_117 { std::get<0>(id_973) };
                              auto dsum2_snd_118 { std::get<1>(id_973) };
                              ::dessser::gen::sync_value::t* id_975 { new ::dessser::gen::sync_value::t(std::in_place_index<9>, dsum2_fst_117) };
                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_976 { id_975, dsum2_snd_118 };
                              letpair_res_974 = id_976;
                            }
                            choose_res_971 = letpair_res_974;
                          } else {
                            uint16_t id_977 { 10 };
                            bool id_978 { bool(id_977 == dsum1_fst_84) };
                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_979;
                            if (id_978) {
                              auto fun980 { dessser::gen::replayer::of_row_binary };
                              ::dessser::gen::sync_value::t340c8c18d76359d202cd5c725fa85083 id_981 { fun980(dsum1_snd_85) };
                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_982;
                              {
                                auto dsum2_fst_114 { std::get<0>(id_981) };
                                auto dsum2_snd_115 { std::get<1>(id_981) };
                                ::dessser::gen::sync_value::t* id_983 { new ::dessser::gen::sync_value::t(std::in_place_index<10>, dsum2_fst_114) };
                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_984 { id_983, dsum2_snd_115 };
                                letpair_res_982 = id_984;
                              }
                              choose_res_979 = letpair_res_982;
                            } else {
                              uint16_t id_985 { 11 };
                              bool id_986 { bool(id_985 == dsum1_fst_84) };
                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_987;
                              if (id_986) {
                                auto fun988 { dessser::gen::replay_request::of_row_binary };
                                ::dessser::gen::sync_value::t71285b8736282d5c64d3d0b32f7411e1 id_989 { fun988(dsum1_snd_85) };
                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_990;
                                {
                                  auto dsum2_fst_111 { std::get<0>(id_989) };
                                  auto dsum2_snd_112 { std::get<1>(id_989) };
                                  ::dessser::gen::sync_value::t* id_991 { new ::dessser::gen::sync_value::t(std::in_place_index<11>, dsum2_fst_111) };
                                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_992 { id_991, dsum2_snd_112 };
                                  letpair_res_990 = id_992;
                                }
                                choose_res_987 = letpair_res_990;
                              } else {
                                uint16_t id_993 { 12 };
                                bool id_994 { bool(id_993 == dsum1_fst_84) };
                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_995;
                                if (id_994) {
                                  auto fun996 { dessser::gen::alert::of_row_binary };
                                  ::dessser::gen::sync_value::tab61b3acff25ef3507148f91d6ab4cb2 id_997 { fun996(dsum1_snd_85) };
                                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_998;
                                  {
                                    auto dsum2_fst_108 { std::get<0>(id_997) };
                                    auto dsum2_snd_109 { std::get<1>(id_997) };
                                    ::dessser::gen::sync_value::t* id_999 { new ::dessser::gen::sync_value::t(std::in_place_index<12>, dsum2_fst_108) };
                                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_1000 { id_999, dsum2_snd_109 };
                                    letpair_res_998 = id_1000;
                                  }
                                  choose_res_995 = letpair_res_998;
                                } else {
                                  uint16_t id_1001 { 13 };
                                  bool id_1002 { bool(id_1001 == dsum1_fst_84) };
                                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_1003;
                                  if (id_1002) {
                                    auto fun1004 { dessser::gen::output_specs::of_row_binary };
                                    ::dessser::gen::sync_value::t0dbd1333ba33cc4b2146173bff40c155 id_1005 { fun1004(dsum1_snd_85) };
                                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_1006;
                                    {
                                      auto dsum2_fst_105 { std::get<0>(id_1005) };
                                      auto dsum2_snd_106 { std::get<1>(id_1005) };
                                      ::dessser::gen::sync_value::t* id_1007 { new ::dessser::gen::sync_value::t(std::in_place_index<13>, dsum2_fst_105) };
                                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_1008 { id_1007, dsum2_snd_106 };
                                      letpair_res_1006 = id_1008;
                                    }
                                    choose_res_1003 = letpair_res_1006;
                                  } else {
                                    uint16_t id_1009 { 14 };
                                    bool id_1010 { bool(id_1009 == dsum1_fst_84) };
                                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_1011;
                                    if (id_1010) {
                                      auto fun1012 { dessser::gen::dashboard_widget::of_row_binary };
                                      ::dessser::gen::sync_value::te2c79ccd282a8acd25a39e2a11a8f3c4 id_1013 { fun1012(dsum1_snd_85) };
                                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_1014;
                                      {
                                        auto dsum2_fst_102 { std::get<0>(id_1013) };
                                        auto dsum2_snd_103 { std::get<1>(id_1013) };
                                        ::dessser::gen::sync_value::t* id_1015 { new ::dessser::gen::sync_value::t(std::in_place_index<14>, dsum2_fst_102) };
                                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_1016 { id_1015, dsum2_snd_103 };
                                        letpair_res_1014 = id_1016;
                                      }
                                      choose_res_1011 = letpair_res_1014;
                                    } else {
                                      uint16_t id_1017 { 15 };
                                      bool id_1018 { bool(id_1017 == dsum1_fst_84) };
                                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_1019;
                                      if (id_1018) {
                                        auto fun1020 { dessser::gen::alerting_contact::of_row_binary };
                                        ::dessser::gen::sync_value::t32b8e4236a53c9833f23e27968f8b877 id_1021 { fun1020(dsum1_snd_85) };
                                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_1022;
                                        {
                                          auto dsum2_fst_99 { std::get<0>(id_1021) };
                                          auto dsum2_snd_100 { std::get<1>(id_1021) };
                                          ::dessser::gen::sync_value::t* id_1023 { new ::dessser::gen::sync_value::t(std::in_place_index<15>, dsum2_fst_99) };
                                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_1024 { id_1023, dsum2_snd_100 };
                                          letpair_res_1022 = id_1024;
                                        }
                                        choose_res_1019 = letpair_res_1022;
                                      } else {
                                        uint16_t id_1025 { 16 };
                                        bool id_1026 { bool(id_1025 == dsum1_fst_84) };
                                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_1027;
                                        if (id_1026) {
                                          auto fun1028 { dessser::gen::alerting_notification::of_row_binary };
                                          ::dessser::gen::sync_value::ta4a3462726fd3c37388ebeb529d00cc7 id_1029 { fun1028(dsum1_snd_85) };
                                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_1030;
                                          {
                                            auto dsum2_fst_96 { std::get<0>(id_1029) };
                                            auto dsum2_snd_97 { std::get<1>(id_1029) };
                                            ::dessser::gen::sync_value::t* id_1031 { new ::dessser::gen::sync_value::t(std::in_place_index<16>, dsum2_fst_96) };
                                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_1032 { id_1031, dsum2_snd_97 };
                                            letpair_res_1030 = id_1032;
                                          }
                                          choose_res_1027 = letpair_res_1030;
                                        } else {
                                          uint16_t id_1033 { 17 };
                                          bool id_1034 { bool(id_1033 == dsum1_fst_84) };
                                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_1035;
                                          if (id_1034) {
                                            auto fun1036 { dessser::gen::alerting_delivery_status::of_row_binary };
                                            ::dessser::gen::sync_value::te8b9cf0e630562630cfdb05a697f6c6e id_1037 { fun1036(dsum1_snd_85) };
                                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_1038;
                                            {
                                              auto dsum2_fst_93 { std::get<0>(id_1037) };
                                              auto dsum2_snd_94 { std::get<1>(id_1037) };
                                              ::dessser::gen::sync_value::t* id_1039 { new ::dessser::gen::sync_value::t(std::in_place_index<17>, dsum2_fst_93) };
                                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_1040 { id_1039, dsum2_snd_94 };
                                              letpair_res_1038 = id_1040;
                                            }
                                            choose_res_1035 = letpair_res_1038;
                                          } else {
                                            uint16_t id_1041 { 18 };
                                            bool id_1042 { bool(id_1041 == dsum1_fst_84) };
                                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_1043;
                                            if (id_1042) {
                                              auto fun1044 { dessser::gen::alerting_log::of_row_binary };
                                              ::dessser::gen::sync_value::t702f22585c26c8c19b7f28f9f255cb0f id_1045 { fun1044(dsum1_snd_85) };
                                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_1046;
                                              {
                                                auto dsum2_fst_90 { std::get<0>(id_1045) };
                                                auto dsum2_snd_91 { std::get<1>(id_1045) };
                                                ::dessser::gen::sync_value::t* id_1047 { new ::dessser::gen::sync_value::t(std::in_place_index<18>, dsum2_fst_90) };
                                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_1048 { id_1047, dsum2_snd_91 };
                                                letpair_res_1046 = id_1048;
                                              }
                                              choose_res_1043 = letpair_res_1046;
                                            } else {
                                              uint16_t id_1049 { 19 };
                                              bool id_1050 { bool(dsum1_fst_84 == id_1049) };
                                              Void id_1051 { ((void)(assert(id_1050)), VOID) };
                                              (void)id_1051;
                                              auto fun1052 { dessser::gen::alerting_inhibition::of_row_binary };
                                              ::dessser::gen::sync_value::t4b1e322f083a1aee723bc1396a69d619 id_1053 { fun1052(dsum1_snd_85) };
                                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_1054;
                                              {
                                                auto dsum2_fst_87 { std::get<0>(id_1053) };
                                                auto dsum2_snd_88 { std::get<1>(id_1053) };
                                                ::dessser::gen::sync_value::t* id_1055 { new ::dessser::gen::sync_value::t(std::in_place_index<19>, dsum2_fst_87) };
                                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_1056 { id_1055, dsum2_snd_88 };
                                                letpair_res_1054 = id_1056;
                                              }
                                              choose_res_1043 = letpair_res_1054;
                                            }
                                            choose_res_1035 = choose_res_1043;
                                          }
                                          choose_res_1027 = choose_res_1035;
                                        }
                                        choose_res_1019 = choose_res_1027;
                                      }
                                      choose_res_1011 = choose_res_1019;
                                    }
                                    choose_res_1003 = choose_res_1011;
                                  }
                                  choose_res_995 = choose_res_1003;
                                }
                                choose_res_987 = choose_res_995;
                              }
                              choose_res_979 = choose_res_987;
                            }
                            choose_res_971 = choose_res_979;
                          }
                          choose_res_963 = choose_res_971;
                        }
                        choose_res_955 = choose_res_963;
                      }
                      choose_res_878 = choose_res_955;
                    }
                    choose_res_870 = choose_res_878;
                  }
                  choose_res_794 = choose_res_870;
                }
                choose_res_786 = choose_res_794;
              }
              choose_res_778 = choose_res_786;
            }
            choose_res_770 = choose_res_778;
          }
          choose_res_707 = choose_res_770;
        }
        letpair_res_704 = choose_res_707;
      }
      let_res_703 = letpair_res_704;
    }
    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_1057;
    {
      auto make_fst_220 { std::get<0>(let_res_703) };
      auto make_snd_221 { std::get<1>(let_res_703) };
      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_1058 { make_fst_220, make_snd_221 };
      letpair_res_1057 = id_1058;
    }
    return letpair_res_1057;
  }
   };
  return fun699;
}
std::function<::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
