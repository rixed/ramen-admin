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
#include "desssergen/target_config.h"
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

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Error
    case 1: return ::dessser::gen::worker::Deref(std::get<1>(a)) == ::dessser::gen::worker::Deref(std::get<1>(b)); // Worker
    case 2: return ::dessser::gen::retention::Deref(std::get<2>(a)) == ::dessser::gen::retention::Deref(std::get<2>(b)); // Retention
    case 3: return ::dessser::gen::time_range::Deref(std::get<3>(a)) == ::dessser::gen::time_range::Deref(std::get<3>(b)); // TimeRange
    case 4: return std::get<4>(a) == std::get<4>(b); // Tuples
    case 5: return ::dessser::gen::raql_value::Deref(std::get<5>(a)) == ::dessser::gen::raql_value::Deref(std::get<5>(b)); // RamenValue
    case 6: return ::dessser::gen::target_config::Deref(std::get<6>(a)) == ::dessser::gen::target_config::Deref(std::get<6>(b)); // TargetConfig
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
struct t9ad85d9f0eecf718fb014d82f812c32a : public std::tuple<
  dessser::gen::target_config::t_ext,
  Pointer
> {
  using tuple::tuple;
  t9ad85d9f0eecf718fb014d82f812c32a(std::tuple<dessser::gen::target_config::t_ext, Pointer> p)
    : std::tuple<dessser::gen::target_config::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9ad85d9f0eecf718fb014d82f812c32a const &a, t9ad85d9f0eecf718fb014d82f812c32a const &b) {
  return ::dessser::gen::target_config::Deref(std::get<0>(a)) == ::dessser::gen::target_config::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9ad85d9f0eecf718fb014d82f812c32a const &a, t9ad85d9f0eecf718fb014d82f812c32a const &b) {
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
      (let "srec_dst_215" (write-u32 little-endian (param 1) (get-field "skipped" (param 0)))
        (write-bytes
          (let "leb128_sz_216" (make-vec (u32-of-size (bytes-length (get-field "values" (param 0)))))
            (let "leb128_ptr_217" (make-vec (identifier "srec_dst_215"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_217")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_217"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_216"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_216"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_216"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_216") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_216")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_216")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_217"))))) 
          (get-field "values" (param 0)))))
 */
static std::function<Pointer(::dessser::gen::sync_value::tuple*,Pointer)> tuple_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_value::tuple*,Pointer)> fun0 { [&fun0](::dessser::gen::sync_value::tuple* p_0, Pointer p_1) {
    uint32_t id_1 { (*p_0).skipped };
    Pointer id_2 { p_1.writeU32Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_215 { id_2 };
      Bytes id_4 { (*p_0).values };
      Size id_5 { id_4.length() };
      uint32_t id_6 { uint32_t(id_5) };
      Vec<1, uint32_t> id_7 {  id_6  };
      Pointer let_res_8;
      {
        Vec<1, uint32_t> leb128_sz_216 { id_7 };
        Vec<1, Pointer> id_9 {  srec_dst_215  };
        Pointer let_res_10;
        {
          Vec<1, Pointer> leb128_ptr_217 { id_9 };
          bool while_flag_11 { true };
          do {
            uint8_t id_12 { 0 };
            uint8_t id_13 { 0 };
            Pointer id_14 { leb128_ptr_217[id_13] };
            uint32_t id_15 { 128U };
            uint8_t id_16 { 0 };
            uint32_t id_17 { leb128_sz_216[id_16] };
            bool id_18 { bool(id_15 > id_17) };
            uint8_t choose_res_19;
            if (id_18) {
              uint8_t id_20 { 0 };
              uint32_t id_21 { leb128_sz_216[id_20] };
              uint8_t id_22 { uint8_t(id_21) };
              choose_res_19 = id_22;
            } else {
              uint8_t id_23 { 0 };
              uint32_t id_24 { leb128_sz_216[id_23] };
              uint8_t id_25 { uint8_t(id_24) };
              uint8_t id_26 { 128 };
              uint8_t id_27 { uint8_t(id_25 | id_26) };
              choose_res_19 = id_27;
            }
            Pointer id_28 { id_14.writeU8(choose_res_19) };
            Void id_29 { ((void)(leb128_ptr_217[id_12] = id_28), VOID) };
            (void)id_29;
            uint8_t id_30 { 0 };
            uint8_t id_31 { 0 };
            uint32_t id_32 { leb128_sz_216[id_31] };
            uint8_t id_33 { 7 };
            uint32_t id_34 { uint32_t(id_32 >> id_33) };
            Void id_35 { ((void)(leb128_sz_216[id_30] = id_34), VOID) };
            (void)id_35;
            uint8_t id_36 { 0 };
            uint32_t id_37 { leb128_sz_216[id_36] };
            uint32_t id_38 { 0U };
            bool id_39 { bool(id_37 > id_38) };
            while_flag_11 = id_39;
            if (while_flag_11) {
              (void)VOID;
            }
          } while (while_flag_11);
          (void)VOID;
          uint8_t id_40 { 0 };
          Pointer id_41 { leb128_ptr_217[id_40] };
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
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" "Ptr")
      (let "label1_218" (label-of (param 0))
        (let "ssum_dst_219" (write-u16 little-endian (param 1) (identifier "label1_218"))
          (if (eq (u16 0) (identifier "label1_218"))
            (let "stup_dst_226"
              (let "stup_dst_225" (write-u64 little-endian (identifier "ssum_dst_219") (u64-of-float (get-item 0 (get-alt "Error" (param 0)))))
                (write-u32 little-endian (identifier "stup_dst_225") (get-item 1 (get-alt "Error" (param 0)))))
              (write-bytes
                (let "leb128_sz_227" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                  (let "leb128_ptr_228" (make-vec (identifier "stup_dst_226"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_228")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_228"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_227"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_227"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_227"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_227") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_227")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_227")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_228"))))) 
                (bytes-of-string (get-item 2 (get-alt "Error" (param 0))))))
            (if (eq (u16 1) (identifier "label1_218")) (apply (ext-identifier worker to-row-binary) (get-alt "Worker" (param 0)) (identifier "ssum_dst_219"))
              (if (eq (u16 2) (identifier "label1_218")) (apply (ext-identifier retention to-row-binary) (get-alt "Retention" (param 0)) (identifier "ssum_dst_219"))
                (if (eq (u16 3) (identifier "label1_218")) (apply (ext-identifier time_range to-row-binary) (get-alt "TimeRange" (param 0)) (identifier "ssum_dst_219"))
                  (if (eq (u16 4) (identifier "label1_218"))
                    (let "dst_ref_222"
                      (make-vec
                        (let "leb128_sz_220" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "leb128_ptr_221" (make-vec (identifier "ssum_dst_219"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_221")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_221"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_220"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_220"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_220"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_220") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_220")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_220")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_221"))))))
                      (let "n_ref_223" (make-vec (i32 0))
                        (seq
                          (for-each "x_224" (get-alt "Tuples" (param 0))
                            (seq (set-vec (u8 0) (identifier "dst_ref_222") (apply (identifier "tuple-to-row-binary") (identifier "x_224") (unsafe-nth (u8 0) (identifier "dst_ref_222"))))
                              (set-vec (u8 0) (identifier "n_ref_223") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_223")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_222")))))
                    (if (eq (u16 5) (identifier "label1_218")) (apply (ext-identifier raql_value to-row-binary) (get-alt "RamenValue" (param 0)) (identifier "ssum_dst_219"))
                      (if (eq (u16 6) (identifier "label1_218")) (apply (ext-identifier target_config to-row-binary) (get-alt "TargetConfig" (param 0)) (identifier "ssum_dst_219"))
                        (if (eq (u16 7) (identifier "label1_218")) (apply (ext-identifier source_info to-row-binary) (get-alt "SourceInfo" (param 0)) (identifier "ssum_dst_219"))
                          (if (eq (u16 8) (identifier "label1_218")) 
                            (apply (ext-identifier runtime_stats to-row-binary) (get-alt "RuntimeStats" (param 0)) (identifier "ssum_dst_219"))
                            (if (eq (u16 9) (identifier "label1_218")) 
                              (apply (ext-identifier replay to-row-binary) (get-alt "Replay" (param 0)) (identifier "ssum_dst_219"))
                              (if (eq (u16 10) (identifier "label1_218")) 
                                (apply (ext-identifier replayer to-row-binary) (get-alt "Replayer" (param 0)) (identifier "ssum_dst_219"))
                                (if (eq (u16 11) (identifier "label1_218")) 
                                  (apply (ext-identifier replay_request to-row-binary) (get-alt "ReplayRequest" (param 0)) (identifier "ssum_dst_219"))
                                  (if (eq (u16 12) (identifier "label1_218")) 
                                    (apply (ext-identifier alert to-row-binary) (get-alt "Alert" (param 0)) (identifier "ssum_dst_219"))
                                    (if (eq (u16 13) (identifier "label1_218")) 
                                      (apply (ext-identifier output_specs to-row-binary) (get-alt "OutputSpecs" (param 0)) (identifier "ssum_dst_219"))
                                      (if (eq (u16 14) (identifier "label1_218")) 
                                        (apply (ext-identifier dashboard_widget to-row-binary) (get-alt "DashboardWidget" (param 0)) (identifier "ssum_dst_219"))
                                        (if (eq (u16 15) (identifier "label1_218")) 
                                          (apply (ext-identifier alerting_contact to-row-binary) (get-alt "AlertingContact" (param 0)) (identifier "ssum_dst_219"))
                                          (if (eq (u16 16) (identifier "label1_218")) 
                                            (apply (ext-identifier alerting_notification to-row-binary) (get-alt "Notification" (param 0)) (identifier "ssum_dst_219"))
                                            (if (eq (u16 17) (identifier "label1_218")) 
                                              (apply (ext-identifier alerting_delivery_status to-row-binary) (get-alt "DeliveryStatus" (param 0)) (identifier "ssum_dst_219"))
                                              (if (eq (u16 18) (identifier "label1_218")) 
                                                (apply (ext-identifier alerting_log to-row-binary) (get-alt "IncidentLog" (param 0)) (identifier "ssum_dst_219"))
                                                (seq (assert (eq (identifier "label1_218") (u16 19))) (apply (ext-identifier alerting_inhibition to-row-binary) (get-alt "Inhibition" (param 0)) (identifier "ssum_dst_219")))))))))))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> fun44 { [&fun44](::dessser::gen::sync_value::t* p_0, Pointer p_1) {
    uint16_t id_45 { uint16_t((*p_0).index()) };
    Pointer let_res_46;
    {
      uint16_t label1_218 { id_45 };
      Pointer id_47 { p_1.writeU16Le(label1_218) };
      Pointer let_res_48;
      {
        Pointer ssum_dst_219 { id_47 };
        uint16_t id_49 { 0 };
        bool id_50 { bool(id_49 == label1_218) };
        Pointer choose_res_51;
        if (id_50) {
          ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_52 { std::get<0 /* Error */>((*p_0)) };
          double id_53 { std::get<0>(id_52) };
          uint64_t id_54 { qword_of_float(id_53) };
          Pointer id_55 { ssum_dst_219.writeU64Le(id_54) };
          Pointer let_res_56;
          {
            Pointer stup_dst_225 { id_55 };
            ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_57 { std::get<0 /* Error */>((*p_0)) };
            uint32_t id_58 { std::get<1>(id_57) };
            Pointer id_59 { stup_dst_225.writeU32Le(id_58) };
            let_res_56 = id_59;
          }
          Pointer let_res_60;
          {
            Pointer stup_dst_226 { let_res_56 };
            ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_61 { std::get<0 /* Error */>((*p_0)) };
            std::string id_62 { std::get<2>(id_61) };
            uint32_t id_63 { (uint32_t)id_62.size() };
            Vec<1, uint32_t> id_64 {  id_63  };
            Pointer let_res_65;
            {
              Vec<1, uint32_t> leb128_sz_227 { id_64 };
              Vec<1, Pointer> id_66 {  stup_dst_226  };
              Pointer let_res_67;
              {
                Vec<1, Pointer> leb128_ptr_228 { id_66 };
                bool while_flag_68 { true };
                do {
                  uint8_t id_69 { 0 };
                  uint8_t id_70 { 0 };
                  Pointer id_71 { leb128_ptr_228[id_70] };
                  uint32_t id_72 { 128U };
                  uint8_t id_73 { 0 };
                  uint32_t id_74 { leb128_sz_227[id_73] };
                  bool id_75 { bool(id_72 > id_74) };
                  uint8_t choose_res_76;
                  if (id_75) {
                    uint8_t id_77 { 0 };
                    uint32_t id_78 { leb128_sz_227[id_77] };
                    uint8_t id_79 { uint8_t(id_78) };
                    choose_res_76 = id_79;
                  } else {
                    uint8_t id_80 { 0 };
                    uint32_t id_81 { leb128_sz_227[id_80] };
                    uint8_t id_82 { uint8_t(id_81) };
                    uint8_t id_83 { 128 };
                    uint8_t id_84 { uint8_t(id_82 | id_83) };
                    choose_res_76 = id_84;
                  }
                  Pointer id_85 { id_71.writeU8(choose_res_76) };
                  Void id_86 { ((void)(leb128_ptr_228[id_69] = id_85), VOID) };
                  (void)id_86;
                  uint8_t id_87 { 0 };
                  uint8_t id_88 { 0 };
                  uint32_t id_89 { leb128_sz_227[id_88] };
                  uint8_t id_90 { 7 };
                  uint32_t id_91 { uint32_t(id_89 >> id_90) };
                  Void id_92 { ((void)(leb128_sz_227[id_87] = id_91), VOID) };
                  (void)id_92;
                  uint8_t id_93 { 0 };
                  uint32_t id_94 { leb128_sz_227[id_93] };
                  uint32_t id_95 { 0U };
                  bool id_96 { bool(id_94 > id_95) };
                  while_flag_68 = id_96;
                  if (while_flag_68) {
                    (void)VOID;
                  }
                } while (while_flag_68);
                (void)VOID;
                uint8_t id_97 { 0 };
                Pointer id_98 { leb128_ptr_228[id_97] };
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
          bool id_104 { bool(id_103 == label1_218) };
          Pointer choose_res_105;
          if (id_104) {
            auto fun106 { dessser::gen::worker::to_row_binary };
            dessser::gen::worker::t_ext id_107 { std::get<1 /* Worker */>((*p_0)) };
            Pointer id_108 { fun106(id_107, ssum_dst_219) };
            choose_res_105 = id_108;
          } else {
            uint16_t id_109 { 2 };
            bool id_110 { bool(id_109 == label1_218) };
            Pointer choose_res_111;
            if (id_110) {
              auto fun112 { dessser::gen::retention::to_row_binary };
              dessser::gen::retention::t_ext id_113 { std::get<2 /* Retention */>((*p_0)) };
              Pointer id_114 { fun112(id_113, ssum_dst_219) };
              choose_res_111 = id_114;
            } else {
              uint16_t id_115 { 3 };
              bool id_116 { bool(id_115 == label1_218) };
              Pointer choose_res_117;
              if (id_116) {
                auto fun118 { dessser::gen::time_range::to_row_binary };
                dessser::gen::time_range::t_ext id_119 { std::get<3 /* TimeRange */>((*p_0)) };
                Pointer id_120 { fun118(id_119, ssum_dst_219) };
                choose_res_117 = id_120;
              } else {
                uint16_t id_121 { 4 };
                bool id_122 { bool(id_121 == label1_218) };
                Pointer choose_res_123;
                if (id_122) {
                  Arr<::dessser::gen::sync_value::tuple*> id_124 { std::get<4 /* Tuples */>((*p_0)) };
                  uint32_t id_125 { id_124.size() };
                  Vec<1, uint32_t> id_126 {  id_125  };
                  Pointer let_res_127;
                  {
                    Vec<1, uint32_t> leb128_sz_220 { id_126 };
                    Vec<1, Pointer> id_128 {  ssum_dst_219  };
                    Pointer let_res_129;
                    {
                      Vec<1, Pointer> leb128_ptr_221 { id_128 };
                      bool while_flag_130 { true };
                      do {
                        uint8_t id_131 { 0 };
                        uint8_t id_132 { 0 };
                        Pointer id_133 { leb128_ptr_221[id_132] };
                        uint32_t id_134 { 128U };
                        uint8_t id_135 { 0 };
                        uint32_t id_136 { leb128_sz_220[id_135] };
                        bool id_137 { bool(id_134 > id_136) };
                        uint8_t choose_res_138;
                        if (id_137) {
                          uint8_t id_139 { 0 };
                          uint32_t id_140 { leb128_sz_220[id_139] };
                          uint8_t id_141 { uint8_t(id_140) };
                          choose_res_138 = id_141;
                        } else {
                          uint8_t id_142 { 0 };
                          uint32_t id_143 { leb128_sz_220[id_142] };
                          uint8_t id_144 { uint8_t(id_143) };
                          uint8_t id_145 { 128 };
                          uint8_t id_146 { uint8_t(id_144 | id_145) };
                          choose_res_138 = id_146;
                        }
                        Pointer id_147 { id_133.writeU8(choose_res_138) };
                        Void id_148 { ((void)(leb128_ptr_221[id_131] = id_147), VOID) };
                        (void)id_148;
                        uint8_t id_149 { 0 };
                        uint8_t id_150 { 0 };
                        uint32_t id_151 { leb128_sz_220[id_150] };
                        uint8_t id_152 { 7 };
                        uint32_t id_153 { uint32_t(id_151 >> id_152) };
                        Void id_154 { ((void)(leb128_sz_220[id_149] = id_153), VOID) };
                        (void)id_154;
                        uint8_t id_155 { 0 };
                        uint32_t id_156 { leb128_sz_220[id_155] };
                        uint32_t id_157 { 0U };
                        bool id_158 { bool(id_156 > id_157) };
                        while_flag_130 = id_158;
                        if (while_flag_130) {
                          (void)VOID;
                        }
                      } while (while_flag_130);
                      (void)VOID;
                      uint8_t id_159 { 0 };
                      Pointer id_160 { leb128_ptr_221[id_159] };
                      let_res_129 = id_160;
                    }
                    let_res_127 = let_res_129;
                  }
                  Vec<1, Pointer> id_161 {  let_res_127  };
                  Pointer let_res_162;
                  {
                    Vec<1, Pointer> dst_ref_222 { id_161 };
                    int32_t id_163 { 0L };
                    Vec<1, int32_t> id_164 {  id_163  };
                    Pointer let_res_165;
                    {
                      Vec<1, int32_t> n_ref_223 { id_164 };
                      Arr<::dessser::gen::sync_value::tuple*> id_166 { std::get<4 /* Tuples */>((*p_0)) };
                      for (::dessser::gen::sync_value::tuple* x_224 : id_166) {
                        uint8_t id_167 { 0 };
                        uint8_t id_168 { 0 };
                        Pointer id_169 { dst_ref_222[id_168] };
                        Pointer id_170 { tuple_to_row_binary(x_224, id_169) };
                        Void id_171 { ((void)(dst_ref_222[id_167] = id_170), VOID) };
                        (void)id_171;
                        uint8_t id_172 { 0 };
                        int32_t id_173 { 1L };
                        uint8_t id_174 { 0 };
                        int32_t id_175 { n_ref_223[id_174] };
                        int32_t id_176 { int32_t(id_173 + id_175) };
                        Void id_177 { ((void)(n_ref_223[id_172] = id_176), VOID) };
                        (void)id_177;
                        (void)id_177;
                      }
                      (void)VOID;
                      uint8_t id_178 { 0 };
                      Pointer id_179 { dst_ref_222[id_178] };
                      let_res_165 = id_179;
                    }
                    let_res_162 = let_res_165;
                  }
                  choose_res_123 = let_res_162;
                } else {
                  uint16_t id_180 { 5 };
                  bool id_181 { bool(id_180 == label1_218) };
                  Pointer choose_res_182;
                  if (id_181) {
                    auto fun183 { dessser::gen::raql_value::to_row_binary };
                    dessser::gen::raql_value::t_ext id_184 { std::get<5 /* RamenValue */>((*p_0)) };
                    Pointer id_185 { fun183(id_184, ssum_dst_219) };
                    choose_res_182 = id_185;
                  } else {
                    uint16_t id_186 { 6 };
                    bool id_187 { bool(id_186 == label1_218) };
                    Pointer choose_res_188;
                    if (id_187) {
                      auto fun189 { dessser::gen::target_config::to_row_binary };
                      dessser::gen::target_config::t_ext id_190 { std::get<6 /* TargetConfig */>((*p_0)) };
                      Pointer id_191 { fun189(id_190, ssum_dst_219) };
                      choose_res_188 = id_191;
                    } else {
                      uint16_t id_192 { 7 };
                      bool id_193 { bool(id_192 == label1_218) };
                      Pointer choose_res_194;
                      if (id_193) {
                        auto fun195 { dessser::gen::source_info::to_row_binary };
                        dessser::gen::source_info::t_ext id_196 { std::get<7 /* SourceInfo */>((*p_0)) };
                        Pointer id_197 { fun195(id_196, ssum_dst_219) };
                        choose_res_194 = id_197;
                      } else {
                        uint16_t id_198 { 8 };
                        bool id_199 { bool(id_198 == label1_218) };
                        Pointer choose_res_200;
                        if (id_199) {
                          auto fun201 { dessser::gen::runtime_stats::to_row_binary };
                          dessser::gen::runtime_stats::t_ext id_202 { std::get<8 /* RuntimeStats */>((*p_0)) };
                          Pointer id_203 { fun201(id_202, ssum_dst_219) };
                          choose_res_200 = id_203;
                        } else {
                          uint16_t id_204 { 9 };
                          bool id_205 { bool(id_204 == label1_218) };
                          Pointer choose_res_206;
                          if (id_205) {
                            auto fun207 { dessser::gen::replay::to_row_binary };
                            dessser::gen::replay::t_ext id_208 { std::get<9 /* Replay */>((*p_0)) };
                            Pointer id_209 { fun207(id_208, ssum_dst_219) };
                            choose_res_206 = id_209;
                          } else {
                            uint16_t id_210 { 10 };
                            bool id_211 { bool(id_210 == label1_218) };
                            Pointer choose_res_212;
                            if (id_211) {
                              auto fun213 { dessser::gen::replayer::to_row_binary };
                              dessser::gen::replayer::t_ext id_214 { std::get<10 /* Replayer */>((*p_0)) };
                              Pointer id_215 { fun213(id_214, ssum_dst_219) };
                              choose_res_212 = id_215;
                            } else {
                              uint16_t id_216 { 11 };
                              bool id_217 { bool(id_216 == label1_218) };
                              Pointer choose_res_218;
                              if (id_217) {
                                auto fun219 { dessser::gen::replay_request::to_row_binary };
                                dessser::gen::replay_request::t_ext id_220 { std::get<11 /* ReplayRequest */>((*p_0)) };
                                Pointer id_221 { fun219(id_220, ssum_dst_219) };
                                choose_res_218 = id_221;
                              } else {
                                uint16_t id_222 { 12 };
                                bool id_223 { bool(id_222 == label1_218) };
                                Pointer choose_res_224;
                                if (id_223) {
                                  auto fun225 { dessser::gen::alert::to_row_binary };
                                  dessser::gen::alert::t_ext id_226 { std::get<12 /* Alert */>((*p_0)) };
                                  Pointer id_227 { fun225(id_226, ssum_dst_219) };
                                  choose_res_224 = id_227;
                                } else {
                                  uint16_t id_228 { 13 };
                                  bool id_229 { bool(id_228 == label1_218) };
                                  Pointer choose_res_230;
                                  if (id_229) {
                                    auto fun231 { dessser::gen::output_specs::to_row_binary };
                                    dessser::gen::output_specs::t_ext id_232 { std::get<13 /* OutputSpecs */>((*p_0)) };
                                    Pointer id_233 { fun231(id_232, ssum_dst_219) };
                                    choose_res_230 = id_233;
                                  } else {
                                    uint16_t id_234 { 14 };
                                    bool id_235 { bool(id_234 == label1_218) };
                                    Pointer choose_res_236;
                                    if (id_235) {
                                      auto fun237 { dessser::gen::dashboard_widget::to_row_binary };
                                      dessser::gen::dashboard_widget::t_ext id_238 { std::get<14 /* DashboardWidget */>((*p_0)) };
                                      Pointer id_239 { fun237(id_238, ssum_dst_219) };
                                      choose_res_236 = id_239;
                                    } else {
                                      uint16_t id_240 { 15 };
                                      bool id_241 { bool(id_240 == label1_218) };
                                      Pointer choose_res_242;
                                      if (id_241) {
                                        auto fun243 { dessser::gen::alerting_contact::to_row_binary };
                                        dessser::gen::alerting_contact::t_ext id_244 { std::get<15 /* AlertingContact */>((*p_0)) };
                                        Pointer id_245 { fun243(id_244, ssum_dst_219) };
                                        choose_res_242 = id_245;
                                      } else {
                                        uint16_t id_246 { 16 };
                                        bool id_247 { bool(id_246 == label1_218) };
                                        Pointer choose_res_248;
                                        if (id_247) {
                                          auto fun249 { dessser::gen::alerting_notification::to_row_binary };
                                          dessser::gen::alerting_notification::t_ext id_250 { std::get<16 /* Notification */>((*p_0)) };
                                          Pointer id_251 { fun249(id_250, ssum_dst_219) };
                                          choose_res_248 = id_251;
                                        } else {
                                          uint16_t id_252 { 17 };
                                          bool id_253 { bool(id_252 == label1_218) };
                                          Pointer choose_res_254;
                                          if (id_253) {
                                            auto fun255 { dessser::gen::alerting_delivery_status::to_row_binary };
                                            dessser::gen::alerting_delivery_status::t_ext id_256 { std::get<17 /* DeliveryStatus */>((*p_0)) };
                                            Pointer id_257 { fun255(id_256, ssum_dst_219) };
                                            choose_res_254 = id_257;
                                          } else {
                                            uint16_t id_258 { 18 };
                                            bool id_259 { bool(id_258 == label1_218) };
                                            Pointer choose_res_260;
                                            if (id_259) {
                                              auto fun261 { dessser::gen::alerting_log::to_row_binary };
                                              dessser::gen::alerting_log::t_ext id_262 { std::get<18 /* IncidentLog */>((*p_0)) };
                                              Pointer id_263 { fun261(id_262, ssum_dst_219) };
                                              choose_res_260 = id_263;
                                            } else {
                                              uint16_t id_264 { 19 };
                                              bool id_265 { bool(label1_218 == id_264) };
                                              Void id_266 { ((void)(assert(id_265)), VOID) };
                                              (void)id_266;
                                              auto fun267 { dessser::gen::alerting_inhibition::to_row_binary };
                                              dessser::gen::alerting_inhibition::t_ext id_268 { std::get<19 /* Inhibition */>((*p_0)) };
                                              Pointer id_269 { fun267(id_268, ssum_dst_219) };
                                              choose_res_260 = id_269;
                                            }
                                            choose_res_254 = choose_res_260;
                                          }
                                          choose_res_248 = choose_res_254;
                                        }
                                        choose_res_242 = choose_res_248;
                                      }
                                      choose_res_236 = choose_res_242;
                                    }
                                    choose_res_230 = choose_res_236;
                                  }
                                  choose_res_224 = choose_res_230;
                                }
                                choose_res_218 = choose_res_224;
                              }
                              choose_res_212 = choose_res_218;
                            }
                            choose_res_206 = choose_res_212;
                          }
                          choose_res_200 = choose_res_206;
                        }
                        choose_res_194 = choose_res_200;
                      }
                      choose_res_188 = choose_res_194;
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
          (let "n_ref_202" (make-vec (u32-of-size (bytes-length (get-field "values" (param 0)))))
            (let "lebsz_ref_203" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_202")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_203")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_203") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_203")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_203")))))) 
          (bytes-length (get-field "values" (param 0))))))
 */
static std::function<Size(::dessser::gen::sync_value::tuple*)> tuple_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_value::tuple*)> fun270 { [&fun270](::dessser::gen::sync_value::tuple* p_0) {
    Size id_271 { 4UL };
    Bytes id_272 { (*p_0).values };
    Size id_273 { id_272.length() };
    uint32_t id_274 { uint32_t(id_273) };
    Vec<1, uint32_t> id_275 {  id_274  };
    Size let_res_276;
    {
      Vec<1, uint32_t> n_ref_202 { id_275 };
      uint32_t id_277 { 1U };
      Vec<1, uint32_t> id_278 {  id_277  };
      Size let_res_279;
      {
        Vec<1, uint32_t> lebsz_ref_203 { id_278 };
        bool while_flag_280 { true };
        do {
          uint8_t id_281 { 0 };
          uint32_t id_282 { n_ref_202[id_281] };
          uint8_t id_283 { 0 };
          uint32_t id_284 { lebsz_ref_203[id_283] };
          uint8_t id_285 { 7 };
          uint32_t id_286 { uint32_t(id_284 << id_285) };
          bool id_287 { bool(id_282 >= id_286) };
          while_flag_280 = id_287;
          if (while_flag_280) {
            uint8_t id_288 { 0 };
            uint8_t id_289 { 0 };
            uint32_t id_290 { lebsz_ref_203[id_289] };
            uint32_t id_291 { 1U };
            uint32_t id_292 { uint32_t(id_290 + id_291) };
            Void id_293 { ((void)(lebsz_ref_203[id_288] = id_292), VOID) };
            (void)id_293;
          }
        } while (while_flag_280);
        (void)VOID;
        uint8_t id_294 { 0 };
        uint32_t id_295 { lebsz_ref_203[id_294] };
        Size id_296 { Size(id_295) };
        let_res_279 = id_296;
      }
      let_res_276 = let_res_279;
    }
    Bytes id_297 { (*p_0).values };
    Size id_298 { id_297.length() };
    Size id_299 { Size(let_res_276 + id_298) };
    Size id_300 { Size(id_271 + id_299) };
    return id_300;
  }
   };
  return fun270;
}
std::function<Size(::dessser::gen::sync_value::tuple*)> tuple_sersize_of_row_binary(tuple_sersize_of_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]")
      (let "label2_204" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_204"))
          (add (size 14)
            (add
              (let "n_ref_213" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                (let "lebsz_ref_214" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_213")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_214")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_214") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_214")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_214")))))) 
              (size-of-u32 (string-length (get-item 2 (get-alt "Error" (param 0)))))))
          (if (eq (u16 1) (identifier "label2_204")) (add (size 2) (apply (ext-identifier worker sersize-of-row-binary) (get-alt "Worker" (param 0))))
            (if (eq (u16 2) (identifier "label2_204")) (add (size 2) (apply (ext-identifier retention sersize-of-row-binary) (get-alt "Retention" (param 0))))
              (if (eq (u16 3) (identifier "label2_204")) (add (size 2) (apply (ext-identifier time_range sersize-of-row-binary) (get-alt "TimeRange" (param 0))))
                (if (eq (u16 4) (identifier "label2_204"))
                  (let "sz_ref_207"
                    (make-vec
                      (add (size 2)
                        (let "n_ref_205" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "lebsz_ref_206" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_205")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_206")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_206") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_206")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_206"))))))))
                    (seq
                      (let "repeat_n_208" (make-vec (i32 0))
                        (while (gt (to-i32 (cardinality (get-alt "Tuples" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_208")))
                          (seq
                            (set-vec (u8 0) (identifier "sz_ref_207")
                              (add (unsafe-nth (u8 0) (identifier "sz_ref_207")) (apply (identifier "tuple-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_208")) (get-alt "Tuples" (param 0))))))
                            (set-vec (u8 0) (identifier "repeat_n_208") (add (unsafe-nth (u8 0) (identifier "repeat_n_208")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "sz_ref_207"))))
                  (if (eq (u16 5) (identifier "label2_204")) (add (size 2) (apply (ext-identifier raql_value sersize-of-row-binary) (get-alt "RamenValue" (param 0))))
                    (if (eq (u16 6) (identifier "label2_204")) (add (size 2) (apply (ext-identifier target_config sersize-of-row-binary) (get-alt "TargetConfig" (param 0))))
                      (if (eq (u16 7) (identifier "label2_204")) (add (size 2) (apply (ext-identifier source_info sersize-of-row-binary) (get-alt "SourceInfo" (param 0))))
                        (if (eq (u16 8) (identifier "label2_204")) (add (size 2) (apply (ext-identifier runtime_stats sersize-of-row-binary) (get-alt "RuntimeStats" (param 0))))
                          (if (eq (u16 9) (identifier "label2_204")) 
                            (add (size 2) (apply (ext-identifier replay sersize-of-row-binary) (get-alt "Replay" (param 0))))
                            (if (eq (u16 10) (identifier "label2_204")) 
                              (add (size 2) (apply (ext-identifier replayer sersize-of-row-binary) (get-alt "Replayer" (param 0))))
                              (if (eq (u16 11) (identifier "label2_204")) 
                                (add (size 2) (apply (ext-identifier replay_request sersize-of-row-binary) (get-alt "ReplayRequest" (param 0))))
                                (if (eq (u16 12) (identifier "label2_204")) 
                                  (add (size 2) (apply (ext-identifier alert sersize-of-row-binary) (get-alt "Alert" (param 0))))
                                  (if (eq (u16 13) (identifier "label2_204")) 
                                    (add (size 2) (apply (ext-identifier output_specs sersize-of-row-binary) (get-alt "OutputSpecs" (param 0))))
                                    (if (eq (u16 14) (identifier "label2_204")) 
                                      (add (size 2) (apply (ext-identifier dashboard_widget sersize-of-row-binary) (get-alt "DashboardWidget" (param 0))))
                                      (if (eq (u16 15) (identifier "label2_204")) 
                                        (add (size 2) (apply (ext-identifier alerting_contact sersize-of-row-binary) (get-alt "AlertingContact" (param 0))))
                                        (if (eq (u16 16) (identifier "label2_204")) 
                                          (add (size 2) (apply (ext-identifier alerting_notification sersize-of-row-binary) (get-alt "Notification" (param 0))))
                                          (if (eq (u16 17) (identifier "label2_204")) 
                                            (add (size 2) (apply (ext-identifier alerting_delivery_status sersize-of-row-binary) (get-alt "DeliveryStatus" (param 0))))
                                            (if (eq (u16 18) (identifier "label2_204")) 
                                              (add (size 2) (apply (ext-identifier alerting_log sersize-of-row-binary) (get-alt "IncidentLog" (param 0))))
                                              (seq (assert (eq (identifier "label2_204") (u16 19))) (add (size 2) (apply (ext-identifier alerting_inhibition sersize-of-row-binary) (get-alt "Inhibition" (param 0))))))))))))))))))))))))))
 */
static std::function<Size(::dessser::gen::sync_value::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_value::t*)> fun301 { [&fun301](::dessser::gen::sync_value::t* p_0) {
    uint16_t id_302 { uint16_t((*p_0).index()) };
    Size let_res_303;
    {
      uint16_t label2_204 { id_302 };
      uint16_t id_304 { 0 };
      bool id_305 { bool(id_304 == label2_204) };
      Size choose_res_306;
      if (id_305) {
        Size id_307 { 14UL };
        ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_308 { std::get<0 /* Error */>((*p_0)) };
        std::string id_309 { std::get<2>(id_308) };
        uint32_t id_310 { (uint32_t)id_309.size() };
        Vec<1, uint32_t> id_311 {  id_310  };
        Size let_res_312;
        {
          Vec<1, uint32_t> n_ref_213 { id_311 };
          uint32_t id_313 { 1U };
          Vec<1, uint32_t> id_314 {  id_313  };
          Size let_res_315;
          {
            Vec<1, uint32_t> lebsz_ref_214 { id_314 };
            bool while_flag_316 { true };
            do {
              uint8_t id_317 { 0 };
              uint32_t id_318 { n_ref_213[id_317] };
              uint8_t id_319 { 0 };
              uint32_t id_320 { lebsz_ref_214[id_319] };
              uint8_t id_321 { 7 };
              uint32_t id_322 { uint32_t(id_320 << id_321) };
              bool id_323 { bool(id_318 >= id_322) };
              while_flag_316 = id_323;
              if (while_flag_316) {
                uint8_t id_324 { 0 };
                uint8_t id_325 { 0 };
                uint32_t id_326 { lebsz_ref_214[id_325] };
                uint32_t id_327 { 1U };
                uint32_t id_328 { uint32_t(id_326 + id_327) };
                Void id_329 { ((void)(lebsz_ref_214[id_324] = id_328), VOID) };
                (void)id_329;
              }
            } while (while_flag_316);
            (void)VOID;
            uint8_t id_330 { 0 };
            uint32_t id_331 { lebsz_ref_214[id_330] };
            Size id_332 { Size(id_331) };
            let_res_315 = id_332;
          }
          let_res_312 = let_res_315;
        }
        ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_333 { std::get<0 /* Error */>((*p_0)) };
        std::string id_334 { std::get<2>(id_333) };
        uint32_t id_335 { (uint32_t)id_334.size() };
        Size id_336 { Size(id_335) };
        Size id_337 { Size(let_res_312 + id_336) };
        Size id_338 { Size(id_307 + id_337) };
        choose_res_306 = id_338;
      } else {
        uint16_t id_339 { 1 };
        bool id_340 { bool(id_339 == label2_204) };
        Size choose_res_341;
        if (id_340) {
          Size id_342 { 2UL };
          auto fun343 { dessser::gen::worker::sersize_of_row_binary };
          dessser::gen::worker::t_ext id_344 { std::get<1 /* Worker */>((*p_0)) };
          Size id_345 { fun343(id_344) };
          Size id_346 { Size(id_342 + id_345) };
          choose_res_341 = id_346;
        } else {
          uint16_t id_347 { 2 };
          bool id_348 { bool(id_347 == label2_204) };
          Size choose_res_349;
          if (id_348) {
            Size id_350 { 2UL };
            auto fun351 { dessser::gen::retention::sersize_of_row_binary };
            dessser::gen::retention::t_ext id_352 { std::get<2 /* Retention */>((*p_0)) };
            Size id_353 { fun351(id_352) };
            Size id_354 { Size(id_350 + id_353) };
            choose_res_349 = id_354;
          } else {
            uint16_t id_355 { 3 };
            bool id_356 { bool(id_355 == label2_204) };
            Size choose_res_357;
            if (id_356) {
              Size id_358 { 2UL };
              auto fun359 { dessser::gen::time_range::sersize_of_row_binary };
              dessser::gen::time_range::t_ext id_360 { std::get<3 /* TimeRange */>((*p_0)) };
              Size id_361 { fun359(id_360) };
              Size id_362 { Size(id_358 + id_361) };
              choose_res_357 = id_362;
            } else {
              uint16_t id_363 { 4 };
              bool id_364 { bool(id_363 == label2_204) };
              Size choose_res_365;
              if (id_364) {
                Size id_366 { 2UL };
                Arr<::dessser::gen::sync_value::tuple*> id_367 { std::get<4 /* Tuples */>((*p_0)) };
                uint32_t id_368 { id_367.size() };
                Vec<1, uint32_t> id_369 {  id_368  };
                Size let_res_370;
                {
                  Vec<1, uint32_t> n_ref_205 { id_369 };
                  uint32_t id_371 { 1U };
                  Vec<1, uint32_t> id_372 {  id_371  };
                  Size let_res_373;
                  {
                    Vec<1, uint32_t> lebsz_ref_206 { id_372 };
                    bool while_flag_374 { true };
                    do {
                      uint8_t id_375 { 0 };
                      uint32_t id_376 { n_ref_205[id_375] };
                      uint8_t id_377 { 0 };
                      uint32_t id_378 { lebsz_ref_206[id_377] };
                      uint8_t id_379 { 7 };
                      uint32_t id_380 { uint32_t(id_378 << id_379) };
                      bool id_381 { bool(id_376 >= id_380) };
                      while_flag_374 = id_381;
                      if (while_flag_374) {
                        uint8_t id_382 { 0 };
                        uint8_t id_383 { 0 };
                        uint32_t id_384 { lebsz_ref_206[id_383] };
                        uint32_t id_385 { 1U };
                        uint32_t id_386 { uint32_t(id_384 + id_385) };
                        Void id_387 { ((void)(lebsz_ref_206[id_382] = id_386), VOID) };
                        (void)id_387;
                      }
                    } while (while_flag_374);
                    (void)VOID;
                    uint8_t id_388 { 0 };
                    uint32_t id_389 { lebsz_ref_206[id_388] };
                    Size id_390 { Size(id_389) };
                    let_res_373 = id_390;
                  }
                  let_res_370 = let_res_373;
                }
                Size id_391 { Size(id_366 + let_res_370) };
                Vec<1, Size> id_392 {  id_391  };
                Size let_res_393;
                {
                  Vec<1, Size> sz_ref_207 { id_392 };
                  int32_t id_394 { 0L };
                  Vec<1, int32_t> id_395 {  id_394  };
                  {
                    Vec<1, int32_t> repeat_n_208 { id_395 };
                    bool while_flag_396 { true };
                    do {
                      Arr<::dessser::gen::sync_value::tuple*> id_397 { std::get<4 /* Tuples */>((*p_0)) };
                      uint32_t id_398 { id_397.size() };
                      int32_t id_399 { int32_t(id_398) };
                      uint8_t id_400 { 0 };
                      int32_t id_401 { repeat_n_208[id_400] };
                      bool id_402 { bool(id_399 > id_401) };
                      while_flag_396 = id_402;
                      if (while_flag_396) {
                        uint8_t id_403 { 0 };
                        uint8_t id_404 { 0 };
                        Size id_405 { sz_ref_207[id_404] };
                        uint8_t id_406 { 0 };
                        int32_t id_407 { repeat_n_208[id_406] };
                        Arr<::dessser::gen::sync_value::tuple*> id_408 { std::get<4 /* Tuples */>((*p_0)) };
                        ::dessser::gen::sync_value::tuple* id_409 { id_408[id_407] };
                        Size id_410 { tuple_sersize_of_row_binary(id_409) };
                        Size id_411 { Size(id_405 + id_410) };
                        Void id_412 { ((void)(sz_ref_207[id_403] = id_411), VOID) };
                        (void)id_412;
                        uint8_t id_413 { 0 };
                        uint8_t id_414 { 0 };
                        int32_t id_415 { repeat_n_208[id_414] };
                        int32_t id_416 { 1L };
                        int32_t id_417 { int32_t(id_415 + id_416) };
                        Void id_418 { ((void)(repeat_n_208[id_413] = id_417), VOID) };
                        (void)id_418;
                        (void)id_418;
                      }
                    } while (while_flag_396);
                    (void)VOID;
                  }
                  (void)VOID;
                  uint8_t id_419 { 0 };
                  Size id_420 { sz_ref_207[id_419] };
                  let_res_393 = id_420;
                }
                choose_res_365 = let_res_393;
              } else {
                uint16_t id_421 { 5 };
                bool id_422 { bool(id_421 == label2_204) };
                Size choose_res_423;
                if (id_422) {
                  Size id_424 { 2UL };
                  auto fun425 { dessser::gen::raql_value::sersize_of_row_binary };
                  dessser::gen::raql_value::t_ext id_426 { std::get<5 /* RamenValue */>((*p_0)) };
                  Size id_427 { fun425(id_426) };
                  Size id_428 { Size(id_424 + id_427) };
                  choose_res_423 = id_428;
                } else {
                  uint16_t id_429 { 6 };
                  bool id_430 { bool(id_429 == label2_204) };
                  Size choose_res_431;
                  if (id_430) {
                    Size id_432 { 2UL };
                    auto fun433 { dessser::gen::target_config::sersize_of_row_binary };
                    dessser::gen::target_config::t_ext id_434 { std::get<6 /* TargetConfig */>((*p_0)) };
                    Size id_435 { fun433(id_434) };
                    Size id_436 { Size(id_432 + id_435) };
                    choose_res_431 = id_436;
                  } else {
                    uint16_t id_437 { 7 };
                    bool id_438 { bool(id_437 == label2_204) };
                    Size choose_res_439;
                    if (id_438) {
                      Size id_440 { 2UL };
                      auto fun441 { dessser::gen::source_info::sersize_of_row_binary };
                      dessser::gen::source_info::t_ext id_442 { std::get<7 /* SourceInfo */>((*p_0)) };
                      Size id_443 { fun441(id_442) };
                      Size id_444 { Size(id_440 + id_443) };
                      choose_res_439 = id_444;
                    } else {
                      uint16_t id_445 { 8 };
                      bool id_446 { bool(id_445 == label2_204) };
                      Size choose_res_447;
                      if (id_446) {
                        Size id_448 { 2UL };
                        auto fun449 { dessser::gen::runtime_stats::sersize_of_row_binary };
                        dessser::gen::runtime_stats::t_ext id_450 { std::get<8 /* RuntimeStats */>((*p_0)) };
                        Size id_451 { fun449(id_450) };
                        Size id_452 { Size(id_448 + id_451) };
                        choose_res_447 = id_452;
                      } else {
                        uint16_t id_453 { 9 };
                        bool id_454 { bool(id_453 == label2_204) };
                        Size choose_res_455;
                        if (id_454) {
                          Size id_456 { 2UL };
                          auto fun457 { dessser::gen::replay::sersize_of_row_binary };
                          dessser::gen::replay::t_ext id_458 { std::get<9 /* Replay */>((*p_0)) };
                          Size id_459 { fun457(id_458) };
                          Size id_460 { Size(id_456 + id_459) };
                          choose_res_455 = id_460;
                        } else {
                          uint16_t id_461 { 10 };
                          bool id_462 { bool(id_461 == label2_204) };
                          Size choose_res_463;
                          if (id_462) {
                            Size id_464 { 2UL };
                            auto fun465 { dessser::gen::replayer::sersize_of_row_binary };
                            dessser::gen::replayer::t_ext id_466 { std::get<10 /* Replayer */>((*p_0)) };
                            Size id_467 { fun465(id_466) };
                            Size id_468 { Size(id_464 + id_467) };
                            choose_res_463 = id_468;
                          } else {
                            uint16_t id_469 { 11 };
                            bool id_470 { bool(id_469 == label2_204) };
                            Size choose_res_471;
                            if (id_470) {
                              Size id_472 { 2UL };
                              auto fun473 { dessser::gen::replay_request::sersize_of_row_binary };
                              dessser::gen::replay_request::t_ext id_474 { std::get<11 /* ReplayRequest */>((*p_0)) };
                              Size id_475 { fun473(id_474) };
                              Size id_476 { Size(id_472 + id_475) };
                              choose_res_471 = id_476;
                            } else {
                              uint16_t id_477 { 12 };
                              bool id_478 { bool(id_477 == label2_204) };
                              Size choose_res_479;
                              if (id_478) {
                                Size id_480 { 2UL };
                                auto fun481 { dessser::gen::alert::sersize_of_row_binary };
                                dessser::gen::alert::t_ext id_482 { std::get<12 /* Alert */>((*p_0)) };
                                Size id_483 { fun481(id_482) };
                                Size id_484 { Size(id_480 + id_483) };
                                choose_res_479 = id_484;
                              } else {
                                uint16_t id_485 { 13 };
                                bool id_486 { bool(id_485 == label2_204) };
                                Size choose_res_487;
                                if (id_486) {
                                  Size id_488 { 2UL };
                                  auto fun489 { dessser::gen::output_specs::sersize_of_row_binary };
                                  dessser::gen::output_specs::t_ext id_490 { std::get<13 /* OutputSpecs */>((*p_0)) };
                                  Size id_491 { fun489(id_490) };
                                  Size id_492 { Size(id_488 + id_491) };
                                  choose_res_487 = id_492;
                                } else {
                                  uint16_t id_493 { 14 };
                                  bool id_494 { bool(id_493 == label2_204) };
                                  Size choose_res_495;
                                  if (id_494) {
                                    Size id_496 { 2UL };
                                    auto fun497 { dessser::gen::dashboard_widget::sersize_of_row_binary };
                                    dessser::gen::dashboard_widget::t_ext id_498 { std::get<14 /* DashboardWidget */>((*p_0)) };
                                    Size id_499 { fun497(id_498) };
                                    Size id_500 { Size(id_496 + id_499) };
                                    choose_res_495 = id_500;
                                  } else {
                                    uint16_t id_501 { 15 };
                                    bool id_502 { bool(id_501 == label2_204) };
                                    Size choose_res_503;
                                    if (id_502) {
                                      Size id_504 { 2UL };
                                      auto fun505 { dessser::gen::alerting_contact::sersize_of_row_binary };
                                      dessser::gen::alerting_contact::t_ext id_506 { std::get<15 /* AlertingContact */>((*p_0)) };
                                      Size id_507 { fun505(id_506) };
                                      Size id_508 { Size(id_504 + id_507) };
                                      choose_res_503 = id_508;
                                    } else {
                                      uint16_t id_509 { 16 };
                                      bool id_510 { bool(id_509 == label2_204) };
                                      Size choose_res_511;
                                      if (id_510) {
                                        Size id_512 { 2UL };
                                        auto fun513 { dessser::gen::alerting_notification::sersize_of_row_binary };
                                        dessser::gen::alerting_notification::t_ext id_514 { std::get<16 /* Notification */>((*p_0)) };
                                        Size id_515 { fun513(id_514) };
                                        Size id_516 { Size(id_512 + id_515) };
                                        choose_res_511 = id_516;
                                      } else {
                                        uint16_t id_517 { 17 };
                                        bool id_518 { bool(id_517 == label2_204) };
                                        Size choose_res_519;
                                        if (id_518) {
                                          Size id_520 { 2UL };
                                          auto fun521 { dessser::gen::alerting_delivery_status::sersize_of_row_binary };
                                          dessser::gen::alerting_delivery_status::t_ext id_522 { std::get<17 /* DeliveryStatus */>((*p_0)) };
                                          Size id_523 { fun521(id_522) };
                                          Size id_524 { Size(id_520 + id_523) };
                                          choose_res_519 = id_524;
                                        } else {
                                          uint16_t id_525 { 18 };
                                          bool id_526 { bool(id_525 == label2_204) };
                                          Size choose_res_527;
                                          if (id_526) {
                                            Size id_528 { 2UL };
                                            auto fun529 { dessser::gen::alerting_log::sersize_of_row_binary };
                                            dessser::gen::alerting_log::t_ext id_530 { std::get<18 /* IncidentLog */>((*p_0)) };
                                            Size id_531 { fun529(id_530) };
                                            Size id_532 { Size(id_528 + id_531) };
                                            choose_res_527 = id_532;
                                          } else {
                                            uint16_t id_533 { 19 };
                                            bool id_534 { bool(label2_204 == id_533) };
                                            Void id_535 { ((void)(assert(id_534)), VOID) };
                                            (void)id_535;
                                            Size id_536 { 2UL };
                                            auto fun537 { dessser::gen::alerting_inhibition::sersize_of_row_binary };
                                            dessser::gen::alerting_inhibition::t_ext id_538 { std::get<19 /* Inhibition */>((*p_0)) };
                                            Size id_539 { fun537(id_538) };
                                            Size id_540 { Size(id_536 + id_539) };
                                            choose_res_527 = id_540;
                                          }
                                          choose_res_519 = choose_res_527;
                                        }
                                        choose_res_511 = choose_res_519;
                                      }
                                      choose_res_503 = choose_res_511;
                                    }
                                    choose_res_495 = choose_res_503;
                                  }
                                  choose_res_487 = choose_res_495;
                                }
                                choose_res_479 = choose_res_487;
                              }
                              choose_res_471 = choose_res_479;
                            }
                            choose_res_463 = choose_res_471;
                          }
                          choose_res_455 = choose_res_463;
                        }
                        choose_res_447 = choose_res_455;
                      }
                      choose_res_439 = choose_res_447;
                    }
                    choose_res_431 = choose_res_439;
                  }
                  choose_res_423 = choose_res_431;
                }
                choose_res_365 = choose_res_423;
              }
              choose_res_357 = choose_res_365;
            }
            choose_res_349 = choose_res_357;
          }
          choose_res_341 = choose_res_349;
        }
        choose_res_306 = choose_res_341;
      }
      let_res_303 = choose_res_306;
    }
    return let_res_303;
  }
   };
  return fun301;
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
  std::function<::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597(Pointer)> fun541 { [&fun541](Pointer p_0) {
    ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_542 { p_0.readU32Le() };
    ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_543;
    {
      auto du32_fst_57 { std::get<0>(id_542) };
      auto du32_snd_58 { std::get<1>(id_542) };
      ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_544 { du32_fst_57, du32_snd_58 };
      letpair_res_543 = id_544;
    }
    ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 let_res_545;
    {
      ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 drec_59 { letpair_res_543 };
      ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 letpair_res_546;
      {
        auto drec_fst_60 { std::get<0>(drec_59) };
        auto drec_snd_61 { std::get<1>(drec_59) };
        uint32_t id_547 { 0U };
        Vec<1, uint32_t> id_548 {  id_547  };
        ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_549;
        {
          Vec<1, uint32_t> leb_ref_62 { id_548 };
          uint8_t id_550 { 0 };
          Vec<1, uint8_t> id_551 {  id_550  };
          ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_552;
          {
            Vec<1, uint8_t> shft_ref_63 { id_551 };
            Vec<1, Pointer> id_553 {  drec_snd_61  };
            ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_554;
            {
              Vec<1, Pointer> p_ref_64 { id_553 };
              bool while_flag_555 { true };
              do {
                uint8_t id_556 { 0 };
                Pointer id_557 { p_ref_64[id_556] };
                ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_558 { id_557.readU8() };
                bool let_res_559;
                {
                  ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_65 { id_558 };
                  bool letpair_res_560;
                  {
                    auto leb128_fst_66 { std::get<0>(leb128_65) };
                    auto leb128_snd_67 { std::get<1>(leb128_65) };
                    uint8_t id_561 { 0 };
                    Void id_562 { ((void)(p_ref_64[id_561] = leb128_snd_67), VOID) };
                    (void)id_562;
                    uint8_t id_563 { 0 };
                    uint8_t id_564 { 127 };
                    uint8_t id_565 { uint8_t(leb128_fst_66 & id_564) };
                    uint32_t id_566 { uint32_t(id_565) };
                    uint8_t id_567 { 0 };
                    uint8_t id_568 { shft_ref_63[id_567] };
                    uint32_t id_569 { uint32_t(id_566 << id_568) };
                    uint8_t id_570 { 0 };
                    uint32_t id_571 { leb_ref_62[id_570] };
                    uint32_t id_572 { uint32_t(id_569 | id_571) };
                    Void id_573 { ((void)(leb_ref_62[id_563] = id_572), VOID) };
                    (void)id_573;
                    uint8_t id_574 { 0 };
                    uint8_t id_575 { 0 };
                    uint8_t id_576 { shft_ref_63[id_575] };
                    uint8_t id_577 { 7 };
                    uint8_t id_578 { uint8_t(id_576 + id_577) };
                    Void id_579 { ((void)(shft_ref_63[id_574] = id_578), VOID) };
                    (void)id_579;
                    uint8_t id_580 { 128 };
                    bool id_581 { bool(leb128_fst_66 >= id_580) };
                    letpair_res_560 = id_581;
                  }
                  let_res_559 = letpair_res_560;
                }
                while_flag_555 = let_res_559;
                if (while_flag_555) {
                  (void)VOID;
                }
              } while (while_flag_555);
              (void)VOID;
              uint8_t id_582 { 0 };
              uint32_t id_583 { leb_ref_62[id_582] };
              Size id_584 { Size(id_583) };
              uint8_t id_585 { 0 };
              Pointer id_586 { p_ref_64[id_585] };
              ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 id_587 { id_584, id_586 };
              let_res_554 = id_587;
            }
            let_res_552 = let_res_554;
          }
          let_res_549 = let_res_552;
        }
        ::dessser::gen::sync_value::t5887709cc43c8c8e24d28211e8c970a2 let_res_588;
        {
          ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 dbytes1_68 { let_res_549 };
          ::dessser::gen::sync_value::t5887709cc43c8c8e24d28211e8c970a2 letpair_res_589;
          {
            auto dbytes1_fst_69 { std::get<0>(dbytes1_68) };
            auto dbytes1_snd_70 { std::get<1>(dbytes1_68) };
            ::dessser::gen::sync_value::t5887709cc43c8c8e24d28211e8c970a2 id_590 { dbytes1_snd_70.readBytes(dbytes1_fst_69) };
            letpair_res_589 = id_590;
          }
          let_res_588 = letpair_res_589;
        }
        ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 letpair_res_591;
        {
          auto drec_fst_72 { std::get<0>(let_res_588) };
          auto drec_snd_73 { std::get<1>(let_res_588) };
          ::dessser::gen::sync_value::tuple* id_592 { new ::dessser::gen::sync_value::tuple({ .skipped = drec_fst_60, .values = drec_fst_72 }) };
          ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 id_593 { id_592, drec_snd_73 };
          letpair_res_591 = id_593;
        }
        letpair_res_546 = letpair_res_591;
      }
      let_res_545 = letpair_res_546;
    }
    return let_res_545;
  }
   };
  return fun541;
}
std::function<::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597(Pointer)> tuple_of_row_binary(tuple_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_197" "make_snd_198"
        (let "dsum1_83" (let-pair "du16_fst_78" "du16_snd_79" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_78") (identifier "du16_snd_79")))
          (let-pair "dsum1_fst_84" "dsum1_snd_85" (identifier "dsum1_83")
            (if (eq (u16 0) (identifier "dsum1_fst_84"))
              (let "dtup_169" (let-pair "dfloat_fst_167" "dfloat_snd_168" (read-u64 little-endian (identifier "dsum1_snd_85")) (make-tup (float-of-u64 (identifier "dfloat_fst_167")) (identifier "dfloat_snd_168")))
                (let-pair "dtup_fst_170" "dtup_snd_171" (identifier "dtup_169")
                  (let "dtup_175" (let-pair "du32_fst_173" "du32_snd_174" (read-u32 little-endian (identifier "dtup_snd_171")) (make-tup (identifier "du32_fst_173") (identifier "du32_snd_174")))
                    (let-pair "dtup_fst_176" "dtup_snd_177" (identifier "dtup_175")
                      (let "dstring1_184"
                        (let "leb_ref_178" (make-vec (u32 0))
                          (let "shft_ref_179" (make-vec (u8 0))
                            (let "p_ref_180" (make-vec (identifier "dtup_snd_177"))
                              (seq
                                (while
                                  (let "leb128_181" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_180")))
                                    (let-pair "leb128_fst_182" "leb128_snd_183" 
                                      (identifier "leb128_181")
                                      (seq (set-vec (u8 0) (identifier "p_ref_180") (identifier "leb128_snd_183"))
                                        (set-vec (u8 0) (identifier "leb_ref_178")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_182") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_179"))) (unsafe-nth (u8 0) (identifier "leb_ref_178"))))
                                        (set-vec (u8 0) (identifier "shft_ref_179") (add (unsafe-nth (u8 0) (identifier "shft_ref_179")) (u8 7))) 
                                        (ge (identifier "leb128_fst_182") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_178"))) (unsafe-nth (u8 0) (identifier "p_ref_180")))))))
                        (let-pair "dstring1_fst_185" "dstring1_snd_186" 
                          (identifier "dstring1_184")
                          (let-pair "dstring2_fst_188" "dstring2_snd_189" 
                            (read-bytes (identifier "dstring1_snd_186") (identifier "dstring1_fst_185"))
                            (make-tup
                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 0
                                (make-tup (identifier "dtup_fst_170") (identifier "dtup_fst_176") (string-of-bytes (identifier "dstring2_fst_188")))) 
                              (identifier "dstring2_snd_189")))))))))
              (if (eq (u16 1) (identifier "dsum1_fst_84"))
                (let-pair "dsum2_fst_164" "dsum2_snd_165" (apply (ext-identifier worker of-row-binary) (identifier "dsum1_snd_85"))
                  (make-tup
                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 1
                      (identifier "dsum2_fst_164")) (identifier "dsum2_snd_165")))
                (if (eq (u16 2) (identifier "dsum1_fst_84"))
                  (let-pair "dsum2_fst_161" "dsum2_snd_162" (apply (ext-identifier retention of-row-binary) (identifier "dsum1_snd_85"))
                    (make-tup
                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 2
                        (identifier "dsum2_fst_161")) (identifier "dsum2_snd_162")))
                  (if (eq (u16 3) (identifier "dsum1_fst_84"))
                    (let-pair "dsum2_fst_158" "dsum2_snd_159" (apply (ext-identifier time_range of-row-binary) (identifier "dsum1_snd_85"))
                      (make-tup
                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 3
                          (identifier "dsum2_fst_158")) (identifier "dsum2_snd_159")))
                    (if (eq (u16 4) (identifier "dsum1_fst_84"))
                      (let-pair "dlist4_fst_152" "dlist4_snd_153"
                        (let "dlist1_140"
                          (let "leb_ref_131" (make-vec (u32 0))
                            (let "shft_ref_132" (make-vec (u8 0))
                              (let "p_ref_133" (make-vec (identifier "dsum1_snd_85"))
                                (seq
                                  (while
                                    (let "leb128_134" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_133")))
                                      (let-pair "leb128_fst_135" "leb128_snd_136" 
                                        (identifier "leb128_134")
                                        (seq (set-vec (u8 0) (identifier "p_ref_133") (identifier "leb128_snd_136"))
                                          (set-vec (u8 0) (identifier "leb_ref_131")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_135") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_132"))) (unsafe-nth (u8 0) (identifier "leb_ref_131"))))
                                          (set-vec (u8 0) (identifier "shft_ref_132") (add (unsafe-nth (u8 0) (identifier "shft_ref_132")) (u8 7))) 
                                          (ge (identifier "leb128_fst_135") (u8 128))))) 
                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_131")) (unsafe-nth (u8 0) (identifier "p_ref_133")))))))
                          (let-pair "dlist1_fst_141" "dlist1_snd_142" 
                            (identifier "dlist1_140")
                            (let "inits_src_ref_143" (make-vec (make-tup (end-of-list "(tuple AS {skipped: U32; values: Bytes})") (identifier "dlist1_snd_142")))
                              (seq
                                (let "repeat_n_144" (make-vec (i32 0))
                                  (while (gt (to-i32 (identifier "dlist1_fst_141")) (unsafe-nth (u8 0) (identifier "repeat_n_144")))
                                    (seq
                                      (let "dlist2_145" (unsafe-nth (u8 0) (identifier "inits_src_ref_143"))
                                        (let-pair "dlist2_fst_146" "dlist2_snd_147" 
                                          (identifier "dlist2_145")
                                          (set-vec (u8 0) (identifier "inits_src_ref_143")
                                            (let-pair "dlist3_fst_149" "dlist3_snd_150" 
                                              (apply (identifier "tuple-of-row-binary") (identifier "dlist2_snd_147")) 
                                              (make-tup (cons (identifier "dlist3_fst_149") (identifier "dlist2_fst_146")) (identifier "dlist3_snd_150"))))))
                                      (set-vec (u8 0) (identifier "repeat_n_144") (add (unsafe-nth (u8 0) (identifier "repeat_n_144")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "inits_src_ref_143"))))))
                        (make-tup
                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 4
                            (arr-of-lst-rev (identifier "dlist4_fst_152"))) 
                          (identifier "dlist4_snd_153")))
                      (if (eq (u16 5) (identifier "dsum1_fst_84"))
                        (let-pair "dsum2_fst_129" "dsum2_snd_130" (apply (ext-identifier raql_value of-row-binary) (identifier "dsum1_snd_85"))
                          (make-tup
                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 5
                              (identifier "dsum2_fst_129")) (identifier "dsum2_snd_130")))
                        (if (eq (u16 6) (identifier "dsum1_fst_84"))
                          (let-pair "dsum2_fst_126" "dsum2_snd_127" (apply (ext-identifier target_config of-row-binary) (identifier "dsum1_snd_85"))
                            (make-tup
                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 6
                                (identifier "dsum2_fst_126")) (identifier "dsum2_snd_127")))
                          (if (eq (u16 7) (identifier "dsum1_fst_84"))
                            (let-pair "dsum2_fst_123" "dsum2_snd_124" 
                              (apply (ext-identifier source_info of-row-binary) (identifier "dsum1_snd_85"))
                              (make-tup
                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 7
                                  (identifier "dsum2_fst_123")) (identifier "dsum2_snd_124")))
                            (if (eq (u16 8) (identifier "dsum1_fst_84"))
                              (let-pair "dsum2_fst_120" "dsum2_snd_121" 
                                (apply (ext-identifier runtime_stats of-row-binary) (identifier "dsum1_snd_85"))
                                (make-tup
                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 8
                                    (identifier "dsum2_fst_120")) (identifier "dsum2_snd_121")))
                              (if (eq (u16 9) (identifier "dsum1_fst_84"))
                                (let-pair "dsum2_fst_117" "dsum2_snd_118" 
                                  (apply (ext-identifier replay of-row-binary) (identifier "dsum1_snd_85"))
                                  (make-tup
                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 9
                                      (identifier "dsum2_fst_117")) (identifier "dsum2_snd_118")))
                                (if (eq (u16 10) (identifier "dsum1_fst_84"))
                                  (let-pair "dsum2_fst_114" "dsum2_snd_115" 
                                    (apply (ext-identifier replayer of-row-binary) (identifier "dsum1_snd_85"))
                                    (make-tup
                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 10
                                        (identifier "dsum2_fst_114")) 
                                      (identifier "dsum2_snd_115")))
                                  (if (eq (u16 11) (identifier "dsum1_fst_84"))
                                    (let-pair "dsum2_fst_111" "dsum2_snd_112" 
                                      (apply (ext-identifier replay_request of-row-binary) (identifier "dsum1_snd_85"))
                                      (make-tup
                                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 11
                                          (identifier "dsum2_fst_111")) 
                                        (identifier "dsum2_snd_112")))
                                    (if (eq (u16 12) (identifier "dsum1_fst_84"))
                                      (let-pair "dsum2_fst_108" "dsum2_snd_109" 
                                        (apply (ext-identifier alert of-row-binary) (identifier "dsum1_snd_85"))
                                        (make-tup
                                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 12
                                            (identifier "dsum2_fst_108")) 
                                          (identifier "dsum2_snd_109")))
                                      (if (eq (u16 13) (identifier "dsum1_fst_84"))
                                        (let-pair "dsum2_fst_105" "dsum2_snd_106" 
                                          (apply (ext-identifier output_specs of-row-binary) (identifier "dsum1_snd_85"))
                                          (make-tup
                                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 13
                                              (identifier "dsum2_fst_105")) 
                                            (identifier "dsum2_snd_106")))
                                        (if (eq (u16 14) (identifier "dsum1_fst_84"))
                                          (let-pair "dsum2_fst_102" "dsum2_snd_103" 
                                            (apply (ext-identifier dashboard_widget of-row-binary) (identifier "dsum1_snd_85"))
                                            (make-tup
                                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 14
                                                (identifier "dsum2_fst_102")) 
                                              (identifier "dsum2_snd_103")))
                                          (if (eq (u16 15) (identifier "dsum1_fst_84"))
                                            (let-pair "dsum2_fst_99" "dsum2_snd_100" 
                                              (apply (ext-identifier alerting_contact of-row-binary) (identifier "dsum1_snd_85"))
                                              (make-tup
                                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 15
                                                  (identifier "dsum2_fst_99")) 
                                                (identifier "dsum2_snd_100")))
                                            (if (eq (u16 16) (identifier "dsum1_fst_84"))
                                              (let-pair "dsum2_fst_96" "dsum2_snd_97" 
                                                (apply (ext-identifier alerting_notification of-row-binary) (identifier "dsum1_snd_85"))
                                                (make-tup
                                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 16
                                                    (identifier "dsum2_fst_96")) 
                                                  (identifier "dsum2_snd_97")))
                                              (if (eq (u16 17) (identifier "dsum1_fst_84"))
                                                (let-pair "dsum2_fst_93" "dsum2_snd_94" 
                                                  (apply (ext-identifier alerting_delivery_status of-row-binary) (identifier "dsum1_snd_85"))
                                                  (make-tup
                                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 17
                                                      (identifier "dsum2_fst_93")) 
                                                    (identifier "dsum2_snd_94")))
                                                (if (eq (u16 18) (identifier "dsum1_fst_84"))
                                                  (let-pair "dsum2_fst_90" "dsum2_snd_91" 
                                                    (apply (ext-identifier alerting_log of-row-binary) (identifier "dsum1_snd_85"))
                                                    (make-tup
                                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 18
                                                        (identifier "dsum2_fst_90")) 
                                                      (identifier "dsum2_snd_91")))
                                                  (seq (assert (eq (identifier "dsum1_fst_84") (u16 19)))
                                                    (let-pair "dsum2_fst_87" "dsum2_snd_88" 
                                                      (apply (ext-identifier alerting_inhibition of-row-binary) (identifier "dsum1_snd_85"))
                                                      (make-tup
                                                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: Bytes})[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 19
                                                          (identifier "dsum2_fst_87")) 
                                                        (identifier "dsum2_snd_88"))))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_197") (identifier "make_snd_198"))))
 */
static std::function<::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987(Pointer)> fun594 { [&fun594](Pointer p_0) {
    ::dessser::gen::sync_value::t7609d344c1ba69d0f80fec236d4c216b id_595 { p_0.readU16Le() };
    ::dessser::gen::sync_value::t7609d344c1ba69d0f80fec236d4c216b letpair_res_596;
    {
      auto du16_fst_78 { std::get<0>(id_595) };
      auto du16_snd_79 { std::get<1>(id_595) };
      ::dessser::gen::sync_value::t7609d344c1ba69d0f80fec236d4c216b id_597 { du16_fst_78, du16_snd_79 };
      letpair_res_596 = id_597;
    }
    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 let_res_598;
    {
      ::dessser::gen::sync_value::t7609d344c1ba69d0f80fec236d4c216b dsum1_83 { letpair_res_596 };
      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_599;
      {
        auto dsum1_fst_84 { std::get<0>(dsum1_83) };
        auto dsum1_snd_85 { std::get<1>(dsum1_83) };
        uint16_t id_600 { 0 };
        bool id_601 { bool(id_600 == dsum1_fst_84) };
        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_602;
        if (id_601) {
          ::dessser::gen::sync_value::tf568409f41c9c0a265f7302110fc9084 id_603 { dsum1_snd_85.readU64Le() };
          ::dessser::gen::sync_value::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_604;
          {
            auto dfloat_fst_167 { std::get<0>(id_603) };
            auto dfloat_snd_168 { std::get<1>(id_603) };
            double id_605 { float_of_qword(dfloat_fst_167) };
            ::dessser::gen::sync_value::t5375de390f9cb5ae2ee5880ea1674828 id_606 { id_605, dfloat_snd_168 };
            letpair_res_604 = id_606;
          }
          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 let_res_607;
          {
            ::dessser::gen::sync_value::t5375de390f9cb5ae2ee5880ea1674828 dtup_169 { letpair_res_604 };
            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_608;
            {
              auto dtup_fst_170 { std::get<0>(dtup_169) };
              auto dtup_snd_171 { std::get<1>(dtup_169) };
              ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_609 { dtup_snd_171.readU32Le() };
              ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_610;
              {
                auto du32_fst_173 { std::get<0>(id_609) };
                auto du32_snd_174 { std::get<1>(id_609) };
                ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_611 { du32_fst_173, du32_snd_174 };
                letpair_res_610 = id_611;
              }
              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 let_res_612;
              {
                ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 dtup_175 { letpair_res_610 };
                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_613;
                {
                  auto dtup_fst_176 { std::get<0>(dtup_175) };
                  auto dtup_snd_177 { std::get<1>(dtup_175) };
                  uint32_t id_614 { 0U };
                  Vec<1, uint32_t> id_615 {  id_614  };
                  ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_616;
                  {
                    Vec<1, uint32_t> leb_ref_178 { id_615 };
                    uint8_t id_617 { 0 };
                    Vec<1, uint8_t> id_618 {  id_617  };
                    ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_619;
                    {
                      Vec<1, uint8_t> shft_ref_179 { id_618 };
                      Vec<1, Pointer> id_620 {  dtup_snd_177  };
                      ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 let_res_621;
                      {
                        Vec<1, Pointer> p_ref_180 { id_620 };
                        bool while_flag_622 { true };
                        do {
                          uint8_t id_623 { 0 };
                          Pointer id_624 { p_ref_180[id_623] };
                          ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_625 { id_624.readU8() };
                          bool let_res_626;
                          {
                            ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_181 { id_625 };
                            bool letpair_res_627;
                            {
                              auto leb128_fst_182 { std::get<0>(leb128_181) };
                              auto leb128_snd_183 { std::get<1>(leb128_181) };
                              uint8_t id_628 { 0 };
                              Void id_629 { ((void)(p_ref_180[id_628] = leb128_snd_183), VOID) };
                              (void)id_629;
                              uint8_t id_630 { 0 };
                              uint8_t id_631 { 127 };
                              uint8_t id_632 { uint8_t(leb128_fst_182 & id_631) };
                              uint32_t id_633 { uint32_t(id_632) };
                              uint8_t id_634 { 0 };
                              uint8_t id_635 { shft_ref_179[id_634] };
                              uint32_t id_636 { uint32_t(id_633 << id_635) };
                              uint8_t id_637 { 0 };
                              uint32_t id_638 { leb_ref_178[id_637] };
                              uint32_t id_639 { uint32_t(id_636 | id_638) };
                              Void id_640 { ((void)(leb_ref_178[id_630] = id_639), VOID) };
                              (void)id_640;
                              uint8_t id_641 { 0 };
                              uint8_t id_642 { 0 };
                              uint8_t id_643 { shft_ref_179[id_642] };
                              uint8_t id_644 { 7 };
                              uint8_t id_645 { uint8_t(id_643 + id_644) };
                              Void id_646 { ((void)(shft_ref_179[id_641] = id_645), VOID) };
                              (void)id_646;
                              uint8_t id_647 { 128 };
                              bool id_648 { bool(leb128_fst_182 >= id_647) };
                              letpair_res_627 = id_648;
                            }
                            let_res_626 = letpair_res_627;
                          }
                          while_flag_622 = let_res_626;
                          if (while_flag_622) {
                            (void)VOID;
                          }
                        } while (while_flag_622);
                        (void)VOID;
                        uint8_t id_649 { 0 };
                        uint32_t id_650 { leb_ref_178[id_649] };
                        Size id_651 { Size(id_650) };
                        uint8_t id_652 { 0 };
                        Pointer id_653 { p_ref_180[id_652] };
                        ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 id_654 { id_651, id_653 };
                        let_res_621 = id_654;
                      }
                      let_res_619 = let_res_621;
                    }
                    let_res_616 = let_res_619;
                  }
                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 let_res_655;
                  {
                    ::dessser::gen::sync_value::t044960e524fd6ec1bfc06410ce526709 dstring1_184 { let_res_616 };
                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_656;
                    {
                      auto dstring1_fst_185 { std::get<0>(dstring1_184) };
                      auto dstring1_snd_186 { std::get<1>(dstring1_184) };
                      ::dessser::gen::sync_value::t5887709cc43c8c8e24d28211e8c970a2 id_657 { dstring1_snd_186.readBytes(dstring1_fst_185) };
                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_658;
                      {
                        auto dstring2_fst_188 { std::get<0>(id_657) };
                        auto dstring2_snd_189 { std::get<1>(id_657) };
                        std::string id_659 { dstring2_fst_188.toString() };
                        ::dessser::gen::sync_value::t4ec0da5161c08f29f8aed40b17a73ef5 id_660 { dtup_fst_170, dtup_fst_176, id_659 };
                        ::dessser::gen::sync_value::t* id_661 { new ::dessser::gen::sync_value::t(std::in_place_index<0>, id_660) };
                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_662 { id_661, dstring2_snd_189 };
                        letpair_res_658 = id_662;
                      }
                      letpair_res_656 = letpair_res_658;
                    }
                    let_res_655 = letpair_res_656;
                  }
                  letpair_res_613 = let_res_655;
                }
                let_res_612 = letpair_res_613;
              }
              letpair_res_608 = let_res_612;
            }
            let_res_607 = letpair_res_608;
          }
          choose_res_602 = let_res_607;
        } else {
          uint16_t id_663 { 1 };
          bool id_664 { bool(id_663 == dsum1_fst_84) };
          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_665;
          if (id_664) {
            auto fun666 { dessser::gen::worker::of_row_binary };
            ::dessser::gen::sync_value::t9833ef1b01f7f7d46ad878fb0cee5e03 id_667 { fun666(dsum1_snd_85) };
            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_668;
            {
              auto dsum2_fst_164 { std::get<0>(id_667) };
              auto dsum2_snd_165 { std::get<1>(id_667) };
              ::dessser::gen::sync_value::t* id_669 { new ::dessser::gen::sync_value::t(std::in_place_index<1>, dsum2_fst_164) };
              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_670 { id_669, dsum2_snd_165 };
              letpair_res_668 = id_670;
            }
            choose_res_665 = letpair_res_668;
          } else {
            uint16_t id_671 { 2 };
            bool id_672 { bool(id_671 == dsum1_fst_84) };
            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_673;
            if (id_672) {
              auto fun674 { dessser::gen::retention::of_row_binary };
              ::dessser::gen::sync_value::t6c4cb47132b52abf02e5ac7e5e40d7ce id_675 { fun674(dsum1_snd_85) };
              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_676;
              {
                auto dsum2_fst_161 { std::get<0>(id_675) };
                auto dsum2_snd_162 { std::get<1>(id_675) };
                ::dessser::gen::sync_value::t* id_677 { new ::dessser::gen::sync_value::t(std::in_place_index<2>, dsum2_fst_161) };
                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_678 { id_677, dsum2_snd_162 };
                letpair_res_676 = id_678;
              }
              choose_res_673 = letpair_res_676;
            } else {
              uint16_t id_679 { 3 };
              bool id_680 { bool(id_679 == dsum1_fst_84) };
              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_681;
              if (id_680) {
                auto fun682 { dessser::gen::time_range::of_row_binary };
                ::dessser::gen::sync_value::t12b2d6d50de8cb59e40a3787e527a60e id_683 { fun682(dsum1_snd_85) };
                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_684;
                {
                  auto dsum2_fst_158 { std::get<0>(id_683) };
                  auto dsum2_snd_159 { std::get<1>(id_683) };
                  ::dessser::gen::sync_value::t* id_685 { new ::dessser::gen::sync_value::t(std::in_place_index<3>, dsum2_fst_158) };
                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_686 { id_685, dsum2_snd_159 };
                  letpair_res_684 = id_686;
                }
                choose_res_681 = letpair_res_684;
              } else {
                uint16_t id_687 { 4 };
                bool id_688 { bool(id_687 == dsum1_fst_84) };
                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_689;
                if (id_688) {
                  uint32_t id_690 { 0U };
                  Vec<1, uint32_t> id_691 {  id_690  };
                  ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_692;
                  {
                    Vec<1, uint32_t> leb_ref_131 { id_691 };
                    uint8_t id_693 { 0 };
                    Vec<1, uint8_t> id_694 {  id_693  };
                    ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_695;
                    {
                      Vec<1, uint8_t> shft_ref_132 { id_694 };
                      Vec<1, Pointer> id_696 {  dsum1_snd_85  };
                      ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_697;
                      {
                        Vec<1, Pointer> p_ref_133 { id_696 };
                        bool while_flag_698 { true };
                        do {
                          uint8_t id_699 { 0 };
                          Pointer id_700 { p_ref_133[id_699] };
                          ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_701 { id_700.readU8() };
                          bool let_res_702;
                          {
                            ::dessser::gen::sync_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_134 { id_701 };
                            bool letpair_res_703;
                            {
                              auto leb128_fst_135 { std::get<0>(leb128_134) };
                              auto leb128_snd_136 { std::get<1>(leb128_134) };
                              uint8_t id_704 { 0 };
                              Void id_705 { ((void)(p_ref_133[id_704] = leb128_snd_136), VOID) };
                              (void)id_705;
                              uint8_t id_706 { 0 };
                              uint8_t id_707 { 127 };
                              uint8_t id_708 { uint8_t(leb128_fst_135 & id_707) };
                              uint32_t id_709 { uint32_t(id_708) };
                              uint8_t id_710 { 0 };
                              uint8_t id_711 { shft_ref_132[id_710] };
                              uint32_t id_712 { uint32_t(id_709 << id_711) };
                              uint8_t id_713 { 0 };
                              uint32_t id_714 { leb_ref_131[id_713] };
                              uint32_t id_715 { uint32_t(id_712 | id_714) };
                              Void id_716 { ((void)(leb_ref_131[id_706] = id_715), VOID) };
                              (void)id_716;
                              uint8_t id_717 { 0 };
                              uint8_t id_718 { 0 };
                              uint8_t id_719 { shft_ref_132[id_718] };
                              uint8_t id_720 { 7 };
                              uint8_t id_721 { uint8_t(id_719 + id_720) };
                              Void id_722 { ((void)(shft_ref_132[id_717] = id_721), VOID) };
                              (void)id_722;
                              uint8_t id_723 { 128 };
                              bool id_724 { bool(leb128_fst_135 >= id_723) };
                              letpair_res_703 = id_724;
                            }
                            let_res_702 = letpair_res_703;
                          }
                          while_flag_698 = let_res_702;
                          if (while_flag_698) {
                            (void)VOID;
                          }
                        } while (while_flag_698);
                        (void)VOID;
                        uint8_t id_725 { 0 };
                        uint32_t id_726 { leb_ref_131[id_725] };
                        uint8_t id_727 { 0 };
                        Pointer id_728 { p_ref_133[id_727] };
                        ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 id_729 { id_726, id_728 };
                        let_res_697 = id_729;
                      }
                      let_res_695 = let_res_697;
                    }
                    let_res_692 = let_res_695;
                  }
                  ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 let_res_730;
                  {
                    ::dessser::gen::sync_value::t883c6ffea47c0d7b950fe35881e3d737 dlist1_140 { let_res_692 };
                    ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 letpair_res_731;
                    {
                      auto dlist1_fst_141 { std::get<0>(dlist1_140) };
                      auto dlist1_snd_142 { std::get<1>(dlist1_140) };
                      Lst<::dessser::gen::sync_value::tuple*> endoflist_732;
                      ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 id_733 { endoflist_732, dlist1_snd_142 };
                      Vec<1, ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7> id_734 {  id_733  };
                      ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 let_res_735;
                      {
                        Vec<1, ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7> inits_src_ref_143 { id_734 };
                        int32_t id_736 { 0L };
                        Vec<1, int32_t> id_737 {  id_736  };
                        {
                          Vec<1, int32_t> repeat_n_144 { id_737 };
                          bool while_flag_738 { true };
                          do {
                            int32_t id_739 { int32_t(dlist1_fst_141) };
                            uint8_t id_740 { 0 };
                            int32_t id_741 { repeat_n_144[id_740] };
                            bool id_742 { bool(id_739 > id_741) };
                            while_flag_738 = id_742;
                            if (while_flag_738) {
                              uint8_t id_743 { 0 };
                              ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 id_744 { inits_src_ref_143[id_743] };
                              {
                                ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 dlist2_145 { id_744 };
                                {
                                  auto dlist2_fst_146 { std::get<0>(dlist2_145) };
                                  auto dlist2_snd_147 { std::get<1>(dlist2_145) };
                                  uint8_t id_745 { 0 };
                                  ::dessser::gen::sync_value::t750a477200d5d3da6135579fb33c1597 id_746 { tuple_of_row_binary(dlist2_snd_147) };
                                  ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 letpair_res_747;
                                  {
                                    auto dlist3_fst_149 { std::get<0>(id_746) };
                                    auto dlist3_snd_150 { std::get<1>(id_746) };
                                    Lst<::dessser::gen::sync_value::tuple*> id_748 { dlist3_fst_149, dlist2_fst_146 };
                                    ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 id_749 { id_748, dlist3_snd_150 };
                                    letpair_res_747 = id_749;
                                  }
                                  Void id_750 { ((void)(inits_src_ref_143[id_745] = letpair_res_747), VOID) };
                                  (void)id_750;
                                }
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_751 { 0 };
                              uint8_t id_752 { 0 };
                              int32_t id_753 { repeat_n_144[id_752] };
                              int32_t id_754 { 1L };
                              int32_t id_755 { int32_t(id_753 + id_754) };
                              Void id_756 { ((void)(repeat_n_144[id_751] = id_755), VOID) };
                              (void)id_756;
                              (void)id_756;
                            }
                          } while (while_flag_738);
                          (void)VOID;
                        }
                        (void)VOID;
                        uint8_t id_757 { 0 };
                        ::dessser::gen::sync_value::t669b86c36c6ec2a214e7091f475517d7 id_758 { inits_src_ref_143[id_757] };
                        let_res_735 = id_758;
                      }
                      letpair_res_731 = let_res_735;
                    }
                    let_res_730 = letpair_res_731;
                  }
                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_759;
                  {
                    auto dlist4_fst_152 { std::get<0>(let_res_730) };
                    auto dlist4_snd_153 { std::get<1>(let_res_730) };
                    Arr<::dessser::gen::sync_value::tuple*> id_760 { dlist4_fst_152.toListRev() };
                    ::dessser::gen::sync_value::t* id_761 { new ::dessser::gen::sync_value::t(std::in_place_index<4>, id_760) };
                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_762 { id_761, dlist4_snd_153 };
                    letpair_res_759 = id_762;
                  }
                  choose_res_689 = letpair_res_759;
                } else {
                  uint16_t id_763 { 5 };
                  bool id_764 { bool(id_763 == dsum1_fst_84) };
                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_765;
                  if (id_764) {
                    auto fun766 { dessser::gen::raql_value::of_row_binary };
                    ::dessser::gen::sync_value::td46b7b5194a84c2e11400d9ca5d84700 id_767 { fun766(dsum1_snd_85) };
                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_768;
                    {
                      auto dsum2_fst_129 { std::get<0>(id_767) };
                      auto dsum2_snd_130 { std::get<1>(id_767) };
                      ::dessser::gen::sync_value::t* id_769 { new ::dessser::gen::sync_value::t(std::in_place_index<5>, dsum2_fst_129) };
                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_770 { id_769, dsum2_snd_130 };
                      letpair_res_768 = id_770;
                    }
                    choose_res_765 = letpair_res_768;
                  } else {
                    uint16_t id_771 { 6 };
                    bool id_772 { bool(id_771 == dsum1_fst_84) };
                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_773;
                    if (id_772) {
                      auto fun774 { dessser::gen::target_config::of_row_binary };
                      ::dessser::gen::sync_value::t9ad85d9f0eecf718fb014d82f812c32a id_775 { fun774(dsum1_snd_85) };
                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_776;
                      {
                        auto dsum2_fst_126 { std::get<0>(id_775) };
                        auto dsum2_snd_127 { std::get<1>(id_775) };
                        ::dessser::gen::sync_value::t* id_777 { new ::dessser::gen::sync_value::t(std::in_place_index<6>, dsum2_fst_126) };
                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_778 { id_777, dsum2_snd_127 };
                        letpair_res_776 = id_778;
                      }
                      choose_res_773 = letpair_res_776;
                    } else {
                      uint16_t id_779 { 7 };
                      bool id_780 { bool(id_779 == dsum1_fst_84) };
                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_781;
                      if (id_780) {
                        auto fun782 { dessser::gen::source_info::of_row_binary };
                        ::dessser::gen::sync_value::t5ca88dae2022f5a9e0892d73f97aaa1a id_783 { fun782(dsum1_snd_85) };
                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_784;
                        {
                          auto dsum2_fst_123 { std::get<0>(id_783) };
                          auto dsum2_snd_124 { std::get<1>(id_783) };
                          ::dessser::gen::sync_value::t* id_785 { new ::dessser::gen::sync_value::t(std::in_place_index<7>, dsum2_fst_123) };
                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_786 { id_785, dsum2_snd_124 };
                          letpair_res_784 = id_786;
                        }
                        choose_res_781 = letpair_res_784;
                      } else {
                        uint16_t id_787 { 8 };
                        bool id_788 { bool(id_787 == dsum1_fst_84) };
                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_789;
                        if (id_788) {
                          auto fun790 { dessser::gen::runtime_stats::of_row_binary };
                          ::dessser::gen::sync_value::t287140549af6d490d4ffca187c95f6c7 id_791 { fun790(dsum1_snd_85) };
                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_792;
                          {
                            auto dsum2_fst_120 { std::get<0>(id_791) };
                            auto dsum2_snd_121 { std::get<1>(id_791) };
                            ::dessser::gen::sync_value::t* id_793 { new ::dessser::gen::sync_value::t(std::in_place_index<8>, dsum2_fst_120) };
                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_794 { id_793, dsum2_snd_121 };
                            letpair_res_792 = id_794;
                          }
                          choose_res_789 = letpair_res_792;
                        } else {
                          uint16_t id_795 { 9 };
                          bool id_796 { bool(id_795 == dsum1_fst_84) };
                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_797;
                          if (id_796) {
                            auto fun798 { dessser::gen::replay::of_row_binary };
                            ::dessser::gen::sync_value::t7853d7746da7c44760583c16a8bef7bc id_799 { fun798(dsum1_snd_85) };
                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_800;
                            {
                              auto dsum2_fst_117 { std::get<0>(id_799) };
                              auto dsum2_snd_118 { std::get<1>(id_799) };
                              ::dessser::gen::sync_value::t* id_801 { new ::dessser::gen::sync_value::t(std::in_place_index<9>, dsum2_fst_117) };
                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_802 { id_801, dsum2_snd_118 };
                              letpair_res_800 = id_802;
                            }
                            choose_res_797 = letpair_res_800;
                          } else {
                            uint16_t id_803 { 10 };
                            bool id_804 { bool(id_803 == dsum1_fst_84) };
                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_805;
                            if (id_804) {
                              auto fun806 { dessser::gen::replayer::of_row_binary };
                              ::dessser::gen::sync_value::t340c8c18d76359d202cd5c725fa85083 id_807 { fun806(dsum1_snd_85) };
                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_808;
                              {
                                auto dsum2_fst_114 { std::get<0>(id_807) };
                                auto dsum2_snd_115 { std::get<1>(id_807) };
                                ::dessser::gen::sync_value::t* id_809 { new ::dessser::gen::sync_value::t(std::in_place_index<10>, dsum2_fst_114) };
                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_810 { id_809, dsum2_snd_115 };
                                letpair_res_808 = id_810;
                              }
                              choose_res_805 = letpair_res_808;
                            } else {
                              uint16_t id_811 { 11 };
                              bool id_812 { bool(id_811 == dsum1_fst_84) };
                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_813;
                              if (id_812) {
                                auto fun814 { dessser::gen::replay_request::of_row_binary };
                                ::dessser::gen::sync_value::t71285b8736282d5c64d3d0b32f7411e1 id_815 { fun814(dsum1_snd_85) };
                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_816;
                                {
                                  auto dsum2_fst_111 { std::get<0>(id_815) };
                                  auto dsum2_snd_112 { std::get<1>(id_815) };
                                  ::dessser::gen::sync_value::t* id_817 { new ::dessser::gen::sync_value::t(std::in_place_index<11>, dsum2_fst_111) };
                                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_818 { id_817, dsum2_snd_112 };
                                  letpair_res_816 = id_818;
                                }
                                choose_res_813 = letpair_res_816;
                              } else {
                                uint16_t id_819 { 12 };
                                bool id_820 { bool(id_819 == dsum1_fst_84) };
                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_821;
                                if (id_820) {
                                  auto fun822 { dessser::gen::alert::of_row_binary };
                                  ::dessser::gen::sync_value::tab61b3acff25ef3507148f91d6ab4cb2 id_823 { fun822(dsum1_snd_85) };
                                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_824;
                                  {
                                    auto dsum2_fst_108 { std::get<0>(id_823) };
                                    auto dsum2_snd_109 { std::get<1>(id_823) };
                                    ::dessser::gen::sync_value::t* id_825 { new ::dessser::gen::sync_value::t(std::in_place_index<12>, dsum2_fst_108) };
                                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_826 { id_825, dsum2_snd_109 };
                                    letpair_res_824 = id_826;
                                  }
                                  choose_res_821 = letpair_res_824;
                                } else {
                                  uint16_t id_827 { 13 };
                                  bool id_828 { bool(id_827 == dsum1_fst_84) };
                                  ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_829;
                                  if (id_828) {
                                    auto fun830 { dessser::gen::output_specs::of_row_binary };
                                    ::dessser::gen::sync_value::t0dbd1333ba33cc4b2146173bff40c155 id_831 { fun830(dsum1_snd_85) };
                                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_832;
                                    {
                                      auto dsum2_fst_105 { std::get<0>(id_831) };
                                      auto dsum2_snd_106 { std::get<1>(id_831) };
                                      ::dessser::gen::sync_value::t* id_833 { new ::dessser::gen::sync_value::t(std::in_place_index<13>, dsum2_fst_105) };
                                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_834 { id_833, dsum2_snd_106 };
                                      letpair_res_832 = id_834;
                                    }
                                    choose_res_829 = letpair_res_832;
                                  } else {
                                    uint16_t id_835 { 14 };
                                    bool id_836 { bool(id_835 == dsum1_fst_84) };
                                    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_837;
                                    if (id_836) {
                                      auto fun838 { dessser::gen::dashboard_widget::of_row_binary };
                                      ::dessser::gen::sync_value::te2c79ccd282a8acd25a39e2a11a8f3c4 id_839 { fun838(dsum1_snd_85) };
                                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_840;
                                      {
                                        auto dsum2_fst_102 { std::get<0>(id_839) };
                                        auto dsum2_snd_103 { std::get<1>(id_839) };
                                        ::dessser::gen::sync_value::t* id_841 { new ::dessser::gen::sync_value::t(std::in_place_index<14>, dsum2_fst_102) };
                                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_842 { id_841, dsum2_snd_103 };
                                        letpair_res_840 = id_842;
                                      }
                                      choose_res_837 = letpair_res_840;
                                    } else {
                                      uint16_t id_843 { 15 };
                                      bool id_844 { bool(id_843 == dsum1_fst_84) };
                                      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_845;
                                      if (id_844) {
                                        auto fun846 { dessser::gen::alerting_contact::of_row_binary };
                                        ::dessser::gen::sync_value::t32b8e4236a53c9833f23e27968f8b877 id_847 { fun846(dsum1_snd_85) };
                                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_848;
                                        {
                                          auto dsum2_fst_99 { std::get<0>(id_847) };
                                          auto dsum2_snd_100 { std::get<1>(id_847) };
                                          ::dessser::gen::sync_value::t* id_849 { new ::dessser::gen::sync_value::t(std::in_place_index<15>, dsum2_fst_99) };
                                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_850 { id_849, dsum2_snd_100 };
                                          letpair_res_848 = id_850;
                                        }
                                        choose_res_845 = letpair_res_848;
                                      } else {
                                        uint16_t id_851 { 16 };
                                        bool id_852 { bool(id_851 == dsum1_fst_84) };
                                        ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_853;
                                        if (id_852) {
                                          auto fun854 { dessser::gen::alerting_notification::of_row_binary };
                                          ::dessser::gen::sync_value::ta4a3462726fd3c37388ebeb529d00cc7 id_855 { fun854(dsum1_snd_85) };
                                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_856;
                                          {
                                            auto dsum2_fst_96 { std::get<0>(id_855) };
                                            auto dsum2_snd_97 { std::get<1>(id_855) };
                                            ::dessser::gen::sync_value::t* id_857 { new ::dessser::gen::sync_value::t(std::in_place_index<16>, dsum2_fst_96) };
                                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_858 { id_857, dsum2_snd_97 };
                                            letpair_res_856 = id_858;
                                          }
                                          choose_res_853 = letpair_res_856;
                                        } else {
                                          uint16_t id_859 { 17 };
                                          bool id_860 { bool(id_859 == dsum1_fst_84) };
                                          ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_861;
                                          if (id_860) {
                                            auto fun862 { dessser::gen::alerting_delivery_status::of_row_binary };
                                            ::dessser::gen::sync_value::te8b9cf0e630562630cfdb05a697f6c6e id_863 { fun862(dsum1_snd_85) };
                                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_864;
                                            {
                                              auto dsum2_fst_93 { std::get<0>(id_863) };
                                              auto dsum2_snd_94 { std::get<1>(id_863) };
                                              ::dessser::gen::sync_value::t* id_865 { new ::dessser::gen::sync_value::t(std::in_place_index<17>, dsum2_fst_93) };
                                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_866 { id_865, dsum2_snd_94 };
                                              letpair_res_864 = id_866;
                                            }
                                            choose_res_861 = letpair_res_864;
                                          } else {
                                            uint16_t id_867 { 18 };
                                            bool id_868 { bool(id_867 == dsum1_fst_84) };
                                            ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 choose_res_869;
                                            if (id_868) {
                                              auto fun870 { dessser::gen::alerting_log::of_row_binary };
                                              ::dessser::gen::sync_value::t702f22585c26c8c19b7f28f9f255cb0f id_871 { fun870(dsum1_snd_85) };
                                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_872;
                                              {
                                                auto dsum2_fst_90 { std::get<0>(id_871) };
                                                auto dsum2_snd_91 { std::get<1>(id_871) };
                                                ::dessser::gen::sync_value::t* id_873 { new ::dessser::gen::sync_value::t(std::in_place_index<18>, dsum2_fst_90) };
                                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_874 { id_873, dsum2_snd_91 };
                                                letpair_res_872 = id_874;
                                              }
                                              choose_res_869 = letpair_res_872;
                                            } else {
                                              uint16_t id_875 { 19 };
                                              bool id_876 { bool(dsum1_fst_84 == id_875) };
                                              Void id_877 { ((void)(assert(id_876)), VOID) };
                                              (void)id_877;
                                              auto fun878 { dessser::gen::alerting_inhibition::of_row_binary };
                                              ::dessser::gen::sync_value::t4b1e322f083a1aee723bc1396a69d619 id_879 { fun878(dsum1_snd_85) };
                                              ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_880;
                                              {
                                                auto dsum2_fst_87 { std::get<0>(id_879) };
                                                auto dsum2_snd_88 { std::get<1>(id_879) };
                                                ::dessser::gen::sync_value::t* id_881 { new ::dessser::gen::sync_value::t(std::in_place_index<19>, dsum2_fst_87) };
                                                ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_882 { id_881, dsum2_snd_88 };
                                                letpair_res_880 = id_882;
                                              }
                                              choose_res_869 = letpair_res_880;
                                            }
                                            choose_res_861 = choose_res_869;
                                          }
                                          choose_res_853 = choose_res_861;
                                        }
                                        choose_res_845 = choose_res_853;
                                      }
                                      choose_res_837 = choose_res_845;
                                    }
                                    choose_res_829 = choose_res_837;
                                  }
                                  choose_res_821 = choose_res_829;
                                }
                                choose_res_813 = choose_res_821;
                              }
                              choose_res_805 = choose_res_813;
                            }
                            choose_res_797 = choose_res_805;
                          }
                          choose_res_789 = choose_res_797;
                        }
                        choose_res_781 = choose_res_789;
                      }
                      choose_res_773 = choose_res_781;
                    }
                    choose_res_765 = choose_res_773;
                  }
                  choose_res_689 = choose_res_765;
                }
                choose_res_681 = choose_res_689;
              }
              choose_res_673 = choose_res_681;
            }
            choose_res_665 = choose_res_673;
          }
          choose_res_602 = choose_res_665;
        }
        letpair_res_599 = choose_res_602;
      }
      let_res_598 = letpair_res_599;
    }
    ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 letpair_res_883;
    {
      auto make_fst_197 { std::get<0>(let_res_598) };
      auto make_snd_198 { std::get<1>(let_res_598) };
      ::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987 id_884 { make_fst_197, make_snd_198 };
      letpair_res_883 = id_884;
    }
    return letpair_res_883;
  }
   };
  return fun594;
}
std::function<::dessser::gen::sync_value::tda69ebe48ca6c803b31d09dc9d524987(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
