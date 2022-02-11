#include <algorithm>
#include <charconv>  // for from_chars
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
struct t : public std::variant<
  ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35, // Error
  dessser::gen::worker::t_ext, // Worker
  dessser::gen::retention::t_ext, // Retention
  dessser::gen::time_range::t_ext, // TimeRange
  Arr<::dessser::gen::sync_value::tuple>, // Tuples
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
struct tc689a7a5ea052f6c0e885d3374325d5b : public std::tuple<
  ::dessser::gen::sync_value::tuple,
  Pointer
> {
  using tuple::tuple;
  tc689a7a5ea052f6c0e885d3374325d5b(std::tuple<::dessser::gen::sync_value::tuple, Pointer> p)
    : std::tuple<::dessser::gen::sync_value::tuple, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc689a7a5ea052f6c0e885d3374325d5b const &a, tc689a7a5ea052f6c0e885d3374325d5b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc689a7a5ea052f6c0e885d3374325d5b const &a, tc689a7a5ea052f6c0e885d3374325d5b const &b) {
  return !operator==(a, b);
}
struct t491c44439106a32f896827242e8e76a1 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t491c44439106a32f896827242e8e76a1(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return !operator==(a, b);
}
struct tf3063cfb73e0f06d3ea99ebd15a86d50 : public std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> {
  using tuple::tuple;
  tf3063cfb73e0f06d3ea99ebd15a86d50(std::tuple<dessser::gen::raql_value::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_value::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf3063cfb73e0f06d3ea99ebd15a86d50 const &a, tf3063cfb73e0f06d3ea99ebd15a86d50 const &b) {
  return ::dessser::gen::raql_value::Deref(std::get<0>(a)) == ::dessser::gen::raql_value::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf3063cfb73e0f06d3ea99ebd15a86d50 const &a, tf3063cfb73e0f06d3ea99ebd15a86d50 const &b) {
  return !operator==(a, b);
}
struct t0fc9c7c3447925ba31ecb766cf775e79 : public std::tuple<
  ::dessser::gen::sync_value::t,
  Pointer
> {
  using tuple::tuple;
  t0fc9c7c3447925ba31ecb766cf775e79(std::tuple<::dessser::gen::sync_value::t, Pointer> p)
    : std::tuple<::dessser::gen::sync_value::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0fc9c7c3447925ba31ecb766cf775e79 const &a, t0fc9c7c3447925ba31ecb766cf775e79 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0fc9c7c3447925ba31ecb766cf775e79 const &a, t0fc9c7c3447925ba31ecb766cf775e79 const &b) {
  return !operator==(a, b);
}
struct ta97bb48ed75bbda6173555873826c8c6 : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  ta97bb48ed75bbda6173555873826c8c6(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return !operator==(a, b);
}
struct td2cd337bb3c8bc04d5603393d084985b : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  td2cd337bb3c8bc04d5603393d084985b(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return !operator==(a, b);
}
struct t9a758baeff17224a77e1a522010b4168 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t9a758baeff17224a77e1a522010b4168(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return !operator==(a, b);
}
struct t12fb9c475959b52bf7b17b155a955ffa : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t12fb9c475959b52bf7b17b155a955ffa(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return !operator==(a, b);
}
struct t1a5d74abf838df33f185a72a8912f5c9 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1a5d74abf838df33f185a72a8912f5c9(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return !operator==(a, b);
}
struct t9ef6882174ae71a34a3c5ef6b29242fb : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t9ef6882174ae71a34a3c5ef6b29242fb(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return !operator==(a, b);
}
struct tf1a9e54f73426165b2d5dbb064eb3fed : public std::tuple<
  dessser::gen::worker::t_ext,
  Pointer
> {
  using tuple::tuple;
  tf1a9e54f73426165b2d5dbb064eb3fed(std::tuple<dessser::gen::worker::t_ext, Pointer> p)
    : std::tuple<dessser::gen::worker::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf1a9e54f73426165b2d5dbb064eb3fed const &a, tf1a9e54f73426165b2d5dbb064eb3fed const &b) {
  return ::dessser::gen::worker::Deref(std::get<0>(a)) == ::dessser::gen::worker::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf1a9e54f73426165b2d5dbb064eb3fed const &a, tf1a9e54f73426165b2d5dbb064eb3fed const &b) {
  return !operator==(a, b);
}
struct tde821e6d031c399b029ea4a78810ecf6 : public std::tuple<
  dessser::gen::retention::t_ext,
  Pointer
> {
  using tuple::tuple;
  tde821e6d031c399b029ea4a78810ecf6(std::tuple<dessser::gen::retention::t_ext, Pointer> p)
    : std::tuple<dessser::gen::retention::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tde821e6d031c399b029ea4a78810ecf6 const &a, tde821e6d031c399b029ea4a78810ecf6 const &b) {
  return ::dessser::gen::retention::Deref(std::get<0>(a)) == ::dessser::gen::retention::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tde821e6d031c399b029ea4a78810ecf6 const &a, tde821e6d031c399b029ea4a78810ecf6 const &b) {
  return !operator==(a, b);
}
struct t7ed2098d1a18c9b684db63350a7b96cb : public std::tuple<
  dessser::gen::time_range::t_ext,
  Pointer
> {
  using tuple::tuple;
  t7ed2098d1a18c9b684db63350a7b96cb(std::tuple<dessser::gen::time_range::t_ext, Pointer> p)
    : std::tuple<dessser::gen::time_range::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7ed2098d1a18c9b684db63350a7b96cb const &a, t7ed2098d1a18c9b684db63350a7b96cb const &b) {
  return ::dessser::gen::time_range::Deref(std::get<0>(a)) == ::dessser::gen::time_range::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7ed2098d1a18c9b684db63350a7b96cb const &a, t7ed2098d1a18c9b684db63350a7b96cb const &b) {
  return !operator==(a, b);
}
struct tfce5b5f196eaf1540bed56507f219516 : public std::tuple<
  Lst<::dessser::gen::sync_value::tuple>,
  Pointer
> {
  using tuple::tuple;
  tfce5b5f196eaf1540bed56507f219516(std::tuple<Lst<::dessser::gen::sync_value::tuple>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::sync_value::tuple>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tfce5b5f196eaf1540bed56507f219516 const &a, tfce5b5f196eaf1540bed56507f219516 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tfce5b5f196eaf1540bed56507f219516 const &a, tfce5b5f196eaf1540bed56507f219516 const &b) {
  return !operator==(a, b);
}
struct t09ff74b441bf867176e1b0fd591831e9 : public std::tuple<
  Lst<dessser::gen::rc_entry::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t09ff74b441bf867176e1b0fd591831e9(std::tuple<Lst<dessser::gen::rc_entry::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::rc_entry::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t09ff74b441bf867176e1b0fd591831e9 const &a, t09ff74b441bf867176e1b0fd591831e9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t09ff74b441bf867176e1b0fd591831e9 const &a, t09ff74b441bf867176e1b0fd591831e9 const &b) {
  return !operator==(a, b);
}
struct t47e3362e539b61ad5bc0fe6744e49d62 : public std::tuple<
  dessser::gen::rc_entry::t_ext,
  Pointer
> {
  using tuple::tuple;
  t47e3362e539b61ad5bc0fe6744e49d62(std::tuple<dessser::gen::rc_entry::t_ext, Pointer> p)
    : std::tuple<dessser::gen::rc_entry::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t47e3362e539b61ad5bc0fe6744e49d62 const &a, t47e3362e539b61ad5bc0fe6744e49d62 const &b) {
  return ::dessser::gen::rc_entry::Deref(std::get<0>(a)) == ::dessser::gen::rc_entry::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t47e3362e539b61ad5bc0fe6744e49d62 const &a, t47e3362e539b61ad5bc0fe6744e49d62 const &b) {
  return !operator==(a, b);
}
struct tf1b07204c9c2214dfaf5f174f6300e9a : public std::tuple<
  dessser::gen::source_info::t_ext,
  Pointer
> {
  using tuple::tuple;
  tf1b07204c9c2214dfaf5f174f6300e9a(std::tuple<dessser::gen::source_info::t_ext, Pointer> p)
    : std::tuple<dessser::gen::source_info::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf1b07204c9c2214dfaf5f174f6300e9a const &a, tf1b07204c9c2214dfaf5f174f6300e9a const &b) {
  return ::dessser::gen::source_info::Deref(std::get<0>(a)) == ::dessser::gen::source_info::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf1b07204c9c2214dfaf5f174f6300e9a const &a, tf1b07204c9c2214dfaf5f174f6300e9a const &b) {
  return !operator==(a, b);
}
struct t0404418c5456e6c318afcd8cf14b75c1 : public std::tuple<
  dessser::gen::runtime_stats::t_ext,
  Pointer
> {
  using tuple::tuple;
  t0404418c5456e6c318afcd8cf14b75c1(std::tuple<dessser::gen::runtime_stats::t_ext, Pointer> p)
    : std::tuple<dessser::gen::runtime_stats::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0404418c5456e6c318afcd8cf14b75c1 const &a, t0404418c5456e6c318afcd8cf14b75c1 const &b) {
  return ::dessser::gen::runtime_stats::Deref(std::get<0>(a)) == ::dessser::gen::runtime_stats::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0404418c5456e6c318afcd8cf14b75c1 const &a, t0404418c5456e6c318afcd8cf14b75c1 const &b) {
  return !operator==(a, b);
}
struct t4f69e417cce4a8fd9a6492bd06fc9968 : public std::tuple<
  dessser::gen::replay::t_ext,
  Pointer
> {
  using tuple::tuple;
  t4f69e417cce4a8fd9a6492bd06fc9968(std::tuple<dessser::gen::replay::t_ext, Pointer> p)
    : std::tuple<dessser::gen::replay::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4f69e417cce4a8fd9a6492bd06fc9968 const &a, t4f69e417cce4a8fd9a6492bd06fc9968 const &b) {
  return ::dessser::gen::replay::Deref(std::get<0>(a)) == ::dessser::gen::replay::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4f69e417cce4a8fd9a6492bd06fc9968 const &a, t4f69e417cce4a8fd9a6492bd06fc9968 const &b) {
  return !operator==(a, b);
}
struct t0d3332e65eb58017bd9ce92925526fe1 : public std::tuple<
  dessser::gen::replayer::t_ext,
  Pointer
> {
  using tuple::tuple;
  t0d3332e65eb58017bd9ce92925526fe1(std::tuple<dessser::gen::replayer::t_ext, Pointer> p)
    : std::tuple<dessser::gen::replayer::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0d3332e65eb58017bd9ce92925526fe1 const &a, t0d3332e65eb58017bd9ce92925526fe1 const &b) {
  return ::dessser::gen::replayer::Deref(std::get<0>(a)) == ::dessser::gen::replayer::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0d3332e65eb58017bd9ce92925526fe1 const &a, t0d3332e65eb58017bd9ce92925526fe1 const &b) {
  return !operator==(a, b);
}
struct tb04e7483a47551f3c586f859338754a3 : public std::tuple<
  dessser::gen::replay_request::t_ext,
  Pointer
> {
  using tuple::tuple;
  tb04e7483a47551f3c586f859338754a3(std::tuple<dessser::gen::replay_request::t_ext, Pointer> p)
    : std::tuple<dessser::gen::replay_request::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb04e7483a47551f3c586f859338754a3 const &a, tb04e7483a47551f3c586f859338754a3 const &b) {
  return ::dessser::gen::replay_request::Deref(std::get<0>(a)) == ::dessser::gen::replay_request::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb04e7483a47551f3c586f859338754a3 const &a, tb04e7483a47551f3c586f859338754a3 const &b) {
  return !operator==(a, b);
}
struct t444e608a3269594da3e48ff9117a0d03 : public std::tuple<
  dessser::gen::alert::t_ext,
  Pointer
> {
  using tuple::tuple;
  t444e608a3269594da3e48ff9117a0d03(std::tuple<dessser::gen::alert::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alert::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t444e608a3269594da3e48ff9117a0d03 const &a, t444e608a3269594da3e48ff9117a0d03 const &b) {
  return ::dessser::gen::alert::Deref(std::get<0>(a)) == ::dessser::gen::alert::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t444e608a3269594da3e48ff9117a0d03 const &a, t444e608a3269594da3e48ff9117a0d03 const &b) {
  return !operator==(a, b);
}
struct t2a03b8ab7cecf56205c765b69d16f216 : public std::tuple<
  dessser::gen::pivot::t_ext,
  Pointer
> {
  using tuple::tuple;
  t2a03b8ab7cecf56205c765b69d16f216(std::tuple<dessser::gen::pivot::t_ext, Pointer> p)
    : std::tuple<dessser::gen::pivot::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2a03b8ab7cecf56205c765b69d16f216 const &a, t2a03b8ab7cecf56205c765b69d16f216 const &b) {
  return ::dessser::gen::pivot::Deref(std::get<0>(a)) == ::dessser::gen::pivot::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2a03b8ab7cecf56205c765b69d16f216 const &a, t2a03b8ab7cecf56205c765b69d16f216 const &b) {
  return !operator==(a, b);
}
struct tf66ee8ddea68e7658659620791429c2e : public std::tuple<
  dessser::gen::output_specs::t_ext,
  Pointer
> {
  using tuple::tuple;
  tf66ee8ddea68e7658659620791429c2e(std::tuple<dessser::gen::output_specs::t_ext, Pointer> p)
    : std::tuple<dessser::gen::output_specs::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf66ee8ddea68e7658659620791429c2e const &a, tf66ee8ddea68e7658659620791429c2e const &b) {
  return ::dessser::gen::output_specs::Deref(std::get<0>(a)) == ::dessser::gen::output_specs::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf66ee8ddea68e7658659620791429c2e const &a, tf66ee8ddea68e7658659620791429c2e const &b) {
  return !operator==(a, b);
}
struct t7b3e7c64daee99819044254f252b16cd : public std::tuple<
  dessser::gen::dashboard_widget::t_ext,
  Pointer
> {
  using tuple::tuple;
  t7b3e7c64daee99819044254f252b16cd(std::tuple<dessser::gen::dashboard_widget::t_ext, Pointer> p)
    : std::tuple<dessser::gen::dashboard_widget::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7b3e7c64daee99819044254f252b16cd const &a, t7b3e7c64daee99819044254f252b16cd const &b) {
  return ::dessser::gen::dashboard_widget::Deref(std::get<0>(a)) == ::dessser::gen::dashboard_widget::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7b3e7c64daee99819044254f252b16cd const &a, t7b3e7c64daee99819044254f252b16cd const &b) {
  return !operator==(a, b);
}
struct t63085be0ace05d30e702e98f7d406fb6 : public std::tuple<
  dessser::gen::alerting_contact::t_ext,
  Pointer
> {
  using tuple::tuple;
  t63085be0ace05d30e702e98f7d406fb6(std::tuple<dessser::gen::alerting_contact::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_contact::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t63085be0ace05d30e702e98f7d406fb6 const &a, t63085be0ace05d30e702e98f7d406fb6 const &b) {
  return ::dessser::gen::alerting_contact::Deref(std::get<0>(a)) == ::dessser::gen::alerting_contact::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t63085be0ace05d30e702e98f7d406fb6 const &a, t63085be0ace05d30e702e98f7d406fb6 const &b) {
  return !operator==(a, b);
}
struct t2587780bdb272f24e6438b12cbc61e92 : public std::tuple<
  dessser::gen::alerting_notification::t_ext,
  Pointer
> {
  using tuple::tuple;
  t2587780bdb272f24e6438b12cbc61e92(std::tuple<dessser::gen::alerting_notification::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_notification::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2587780bdb272f24e6438b12cbc61e92 const &a, t2587780bdb272f24e6438b12cbc61e92 const &b) {
  return ::dessser::gen::alerting_notification::Deref(std::get<0>(a)) == ::dessser::gen::alerting_notification::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2587780bdb272f24e6438b12cbc61e92 const &a, t2587780bdb272f24e6438b12cbc61e92 const &b) {
  return !operator==(a, b);
}
struct te49867912245e444e88027721575ec35 : public std::tuple<
  dessser::gen::alerting_delivery_status::t_ext,
  Pointer
> {
  using tuple::tuple;
  te49867912245e444e88027721575ec35(std::tuple<dessser::gen::alerting_delivery_status::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_delivery_status::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te49867912245e444e88027721575ec35 const &a, te49867912245e444e88027721575ec35 const &b) {
  return ::dessser::gen::alerting_delivery_status::Deref(std::get<0>(a)) == ::dessser::gen::alerting_delivery_status::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te49867912245e444e88027721575ec35 const &a, te49867912245e444e88027721575ec35 const &b) {
  return !operator==(a, b);
}
struct t555ce468db008991e3ea7cea3f54910f : public std::tuple<
  dessser::gen::alerting_log::t_ext,
  Pointer
> {
  using tuple::tuple;
  t555ce468db008991e3ea7cea3f54910f(std::tuple<dessser::gen::alerting_log::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_log::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t555ce468db008991e3ea7cea3f54910f const &a, t555ce468db008991e3ea7cea3f54910f const &b) {
  return ::dessser::gen::alerting_log::Deref(std::get<0>(a)) == ::dessser::gen::alerting_log::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t555ce468db008991e3ea7cea3f54910f const &a, t555ce468db008991e3ea7cea3f54910f const &b) {
  return !operator==(a, b);
}
struct t511ff94fe7190561084aee555c49cbe8 : public std::tuple<
  dessser::gen::alerting_inhibition::t_ext,
  Pointer
> {
  using tuple::tuple;
  t511ff94fe7190561084aee555c49cbe8(std::tuple<dessser::gen::alerting_inhibition::t_ext, Pointer> p)
    : std::tuple<dessser::gen::alerting_inhibition::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t511ff94fe7190561084aee555c49cbe8 const &a, t511ff94fe7190561084aee555c49cbe8 const &b) {
  return ::dessser::gen::alerting_inhibition::Deref(std::get<0>(a)) == ::dessser::gen::alerting_inhibition::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t511ff94fe7190561084aee555c49cbe8 const &a, t511ff94fe7190561084aee555c49cbe8 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{skipped: U32; values: $raql_value}" "Ptr")
      (let "srec_dst_231" (write-u32 little-endian (param 1) (get-field "skipped" (param 0))) (apply (ext-identifier raql_value to-row-binary) (get-field "values" (param 0)) (identifier "srec_dst_231"))))
 */
static std::function<Pointer(::dessser::gen::sync_value::tuple &,Pointer &)> tuple_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_value::tuple &,Pointer &)> fun0 { [&](::dessser::gen::sync_value::tuple p_0, Pointer p_1) {
    uint32_t id_1 { p_0.skipped };
    Pointer id_2 { p_1.writeU32Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_231 { id_2 };
      auto fun4 { dessser::gen::raql_value::to_row_binary };
      dessser::gen::raql_value::t_ext id_5 { p_0.values };
      Pointer id_6 { fun4(id_5, srec_dst_231) };
      let_res_3 = id_6;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::sync_value::tuple &,Pointer &)> tuple_to_row_binary(tuple_to_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" "Ptr")
      (let "label1_232" (label-of (param 0))
        (let "ssum_dst_233" (write-u16 little-endian (param 1) (identifier "label1_232"))
          (if (eq (u16 0) (identifier "label1_232"))
            (let "stup_dst_245"
              (let "stup_dst_244" (write-u64 little-endian (identifier "ssum_dst_233") (u64-of-float (get-item 0 (get-alt "Error" (param 0)))))
                (write-u32 little-endian (identifier "stup_dst_244") (get-item 1 (get-alt "Error" (param 0)))))
              (write-bytes
                (let "leb128_sz_246" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                  (let "leb128_ptr_247" (make-vec (identifier "stup_dst_245"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_247")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_247"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_246"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_246"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_246"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_246") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_246")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_246")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_247"))))) 
                (bytes-of-string (get-item 2 (get-alt "Error" (param 0))))))
            (if (eq (u16 1) (identifier "label1_232")) (apply (ext-identifier worker to-row-binary) (get-alt "Worker" (param 0)) (identifier "ssum_dst_233"))
              (if (eq (u16 2) (identifier "label1_232")) (apply (ext-identifier retention to-row-binary) (get-alt "Retention" (param 0)) (identifier "ssum_dst_233"))
                (if (eq (u16 3) (identifier "label1_232")) (apply (ext-identifier time_range to-row-binary) (get-alt "TimeRange" (param 0)) (identifier "ssum_dst_233"))
                  (if (eq (u16 4) (identifier "label1_232"))
                    (let "dst_ref_241"
                      (make-vec
                        (let "leb128_sz_239" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "leb128_ptr_240" (make-vec (identifier "ssum_dst_233"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_240")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_240"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_239"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_239"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_239"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_239") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_239")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_239")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_240"))))))
                      (let "n_ref_242" (make-vec (i32 0))
                        (seq
                          (for-each "x_243" (get-alt "Tuples" (param 0))
                            (seq (set-vec (u8 0) (identifier "dst_ref_241") (apply (identifier "tuple-to-row-binary") (identifier "x_243") (unsafe-nth (u8 0) (identifier "dst_ref_241"))))
                              (set-vec (u8 0) (identifier "n_ref_242") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_242")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_241")))))
                    (if (eq (u16 5) (identifier "label1_232")) (apply (ext-identifier raql_value to-row-binary) (get-alt "RamenValue" (param 0)) (identifier "ssum_dst_233"))
                      (if (eq (u16 6) (identifier "label1_232"))
                        (let "dst_ref_236"
                          (make-vec
                            (let "leb128_sz_234" (make-vec (cardinality (get-alt "TargetConfig" (param 0))))
                              (let "leb128_ptr_235" (make-vec (identifier "ssum_dst_233"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_235")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_235"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_234"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_234"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_234"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_234") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_234")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_234")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_235"))))))
                          (let "n_ref_237" (make-vec (i32 0))
                            (seq
                              (for-each "x_238" (get-alt "TargetConfig" (param 0))
                                (seq (set-vec (u8 0) (identifier "dst_ref_236") (apply (ext-identifier rc_entry to-row-binary) (identifier "x_238") (unsafe-nth (u8 0) (identifier "dst_ref_236"))))
                                  (set-vec (u8 0) (identifier "n_ref_237") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_237")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_236")))))
                        (if (eq (u16 7) (identifier "label1_232")) (apply (ext-identifier source_info to-row-binary) (get-alt "SourceInfo" (param 0)) (identifier "ssum_dst_233"))
                          (if (eq (u16 8) (identifier "label1_232")) 
                            (apply (ext-identifier runtime_stats to-row-binary) (get-alt "RuntimeStats" (param 0)) (identifier "ssum_dst_233"))
                            (if (eq (u16 9) (identifier "label1_232")) 
                              (apply (ext-identifier replay to-row-binary) (get-alt "Replay" (param 0)) (identifier "ssum_dst_233"))
                              (if (eq (u16 10) (identifier "label1_232")) 
                                (apply (ext-identifier replayer to-row-binary) (get-alt "Replayer" (param 0)) (identifier "ssum_dst_233"))
                                (if (eq (u16 11) (identifier "label1_232")) 
                                  (apply (ext-identifier replay_request to-row-binary) (get-alt "ReplayRequest" (param 0)) (identifier "ssum_dst_233"))
                                  (if (eq (u16 12) (identifier "label1_232")) 
                                    (apply (ext-identifier alert to-row-binary) (get-alt "Alert" (param 0)) (identifier "ssum_dst_233"))
                                    (if (eq (u16 13) (identifier "label1_232")) 
                                      (apply (ext-identifier pivot to-row-binary) (get-alt "Pivot" (param 0)) (identifier "ssum_dst_233"))
                                      (if (eq (u16 14) (identifier "label1_232")) 
                                        (apply (ext-identifier output_specs to-row-binary) (get-alt "OutputSpecs" (param 0)) (identifier "ssum_dst_233"))
                                        (if (eq (u16 15) (identifier "label1_232")) 
                                          (apply (ext-identifier dashboard_widget to-row-binary) (get-alt "DashboardWidget" (param 0)) (identifier "ssum_dst_233"))
                                          (if (eq (u16 16) (identifier "label1_232")) 
                                            (apply (ext-identifier alerting_contact to-row-binary) (get-alt "AlertingContact" (param 0)) (identifier "ssum_dst_233"))
                                            (if (eq (u16 17) (identifier "label1_232")) 
                                              (apply (ext-identifier alerting_notification to-row-binary) (get-alt "Notification" (param 0)) (identifier "ssum_dst_233"))
                                              (if (eq (u16 18) (identifier "label1_232")) 
                                                (apply (ext-identifier alerting_delivery_status to-row-binary) (get-alt "DeliveryStatus" (param 0)) (identifier "ssum_dst_233"))
                                                (if (eq (u16 19) (identifier "label1_232")) 
                                                  (apply (ext-identifier alerting_log to-row-binary) (get-alt "IncidentLog" (param 0)) (identifier "ssum_dst_233"))
                                                  (seq (assert (eq (identifier "label1_232") (u16 20))) (apply (ext-identifier alerting_inhibition to-row-binary) (get-alt "Inhibition" (param 0)) (identifier "ssum_dst_233"))))))))))))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_value::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_value::t &,Pointer &)> fun7 { [&](::dessser::gen::sync_value::t p_0, Pointer p_1) {
    uint16_t id_8 { uint16_t(p_0.index()) };
    Pointer let_res_9;
    {
      uint16_t label1_232 { id_8 };
      Pointer id_10 { p_1.writeU16Le(label1_232) };
      Pointer let_res_11;
      {
        Pointer ssum_dst_233 { id_10 };
        uint16_t id_12 { 0 };
        bool id_13 { bool(id_12 == label1_232) };
        Pointer choose_res_14;
        if (id_13) {
          ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_15 { std::get<0 /* Error */>(p_0) };
          double id_16 { std::get<0>(id_15) };
          uint64_t id_17 { qword_of_float(id_16) };
          Pointer id_18 { ssum_dst_233.writeU64Le(id_17) };
          Pointer let_res_19;
          {
            Pointer stup_dst_244 { id_18 };
            ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_20 { std::get<0 /* Error */>(p_0) };
            uint32_t id_21 { std::get<1>(id_20) };
            Pointer id_22 { stup_dst_244.writeU32Le(id_21) };
            let_res_19 = id_22;
          }
          Pointer let_res_23;
          {
            Pointer stup_dst_245 { let_res_19 };
            ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_24 { std::get<0 /* Error */>(p_0) };
            std::string id_25 { std::get<2>(id_24) };
            uint32_t id_26 { (uint32_t)id_25.size() };
            Vec<1, uint32_t> id_27 {  id_26  };
            Pointer let_res_28;
            {
              Vec<1, uint32_t> leb128_sz_246 { id_27 };
              Vec<1, Pointer> id_29 {  stup_dst_245  };
              Pointer let_res_30;
              {
                Vec<1, Pointer> leb128_ptr_247 { id_29 };
                bool while_flag_31 { true };
                do {
                  uint8_t id_32 { 0 };
                  uint8_t id_33 { 0 };
                  Pointer id_34 { leb128_ptr_247[id_33] };
                  uint32_t id_35 { 128U };
                  uint8_t id_36 { 0 };
                  uint32_t id_37 { leb128_sz_246[id_36] };
                  bool id_38 { bool(id_35 > id_37) };
                  uint8_t choose_res_39;
                  if (id_38) {
                    uint8_t id_40 { 0 };
                    uint32_t id_41 { leb128_sz_246[id_40] };
                    uint8_t id_42 { uint8_t(id_41) };
                    choose_res_39 = id_42;
                  } else {
                    uint8_t id_43 { 0 };
                    uint32_t id_44 { leb128_sz_246[id_43] };
                    uint8_t id_45 { uint8_t(id_44) };
                    uint8_t id_46 { 128 };
                    uint8_t id_47 { uint8_t(id_45 | id_46) };
                    choose_res_39 = id_47;
                  }
                  Pointer id_48 { id_34.writeU8(choose_res_39) };
                  Void id_49 { ((void)(leb128_ptr_247[id_32] = id_48), ::dessser::Void()) };
                  (void)id_49;
                  uint8_t id_50 { 0 };
                  uint8_t id_51 { 0 };
                  uint32_t id_52 { leb128_sz_246[id_51] };
                  uint8_t id_53 { 7 };
                  uint32_t id_54 { uint32_t(id_52 >> id_53) };
                  Void id_55 { ((void)(leb128_sz_246[id_50] = id_54), ::dessser::Void()) };
                  (void)id_55;
                  uint8_t id_56 { 0 };
                  uint32_t id_57 { leb128_sz_246[id_56] };
                  uint32_t id_58 { 0U };
                  bool id_59 { bool(id_57 > id_58) };
                  while_flag_31 = id_59;
                  if (while_flag_31) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_31);
                (void)::dessser::Void();
                uint8_t id_60 { 0 };
                Pointer id_61 { leb128_ptr_247[id_60] };
                let_res_30 = id_61;
              }
              let_res_28 = let_res_30;
            }
            ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_62 { std::get<0 /* Error */>(p_0) };
            std::string id_63 { std::get<2>(id_62) };
            Bytes id_64 { id_63 };
            Pointer id_65 { let_res_28.writeBytes(id_64) };
            let_res_23 = id_65;
          }
          choose_res_14 = let_res_23;
        } else {
          uint16_t id_66 { 1 };
          bool id_67 { bool(id_66 == label1_232) };
          Pointer choose_res_68;
          if (id_67) {
            auto fun69 { dessser::gen::worker::to_row_binary };
            dessser::gen::worker::t_ext id_70 { std::get<1 /* Worker */>(p_0) };
            Pointer id_71 { fun69(id_70, ssum_dst_233) };
            choose_res_68 = id_71;
          } else {
            uint16_t id_72 { 2 };
            bool id_73 { bool(id_72 == label1_232) };
            Pointer choose_res_74;
            if (id_73) {
              auto fun75 { dessser::gen::retention::to_row_binary };
              dessser::gen::retention::t_ext id_76 { std::get<2 /* Retention */>(p_0) };
              Pointer id_77 { fun75(id_76, ssum_dst_233) };
              choose_res_74 = id_77;
            } else {
              uint16_t id_78 { 3 };
              bool id_79 { bool(id_78 == label1_232) };
              Pointer choose_res_80;
              if (id_79) {
                auto fun81 { dessser::gen::time_range::to_row_binary };
                dessser::gen::time_range::t_ext id_82 { std::get<3 /* TimeRange */>(p_0) };
                Pointer id_83 { fun81(id_82, ssum_dst_233) };
                choose_res_80 = id_83;
              } else {
                uint16_t id_84 { 4 };
                bool id_85 { bool(id_84 == label1_232) };
                Pointer choose_res_86;
                if (id_85) {
                  Arr<::dessser::gen::sync_value::tuple> id_87 { std::get<4 /* Tuples */>(p_0) };
                  uint32_t id_88 { id_87.size() };
                  Vec<1, uint32_t> id_89 {  id_88  };
                  Pointer let_res_90;
                  {
                    Vec<1, uint32_t> leb128_sz_239 { id_89 };
                    Vec<1, Pointer> id_91 {  ssum_dst_233  };
                    Pointer let_res_92;
                    {
                      Vec<1, Pointer> leb128_ptr_240 { id_91 };
                      bool while_flag_93 { true };
                      do {
                        uint8_t id_94 { 0 };
                        uint8_t id_95 { 0 };
                        Pointer id_96 { leb128_ptr_240[id_95] };
                        uint32_t id_97 { 128U };
                        uint8_t id_98 { 0 };
                        uint32_t id_99 { leb128_sz_239[id_98] };
                        bool id_100 { bool(id_97 > id_99) };
                        uint8_t choose_res_101;
                        if (id_100) {
                          uint8_t id_102 { 0 };
                          uint32_t id_103 { leb128_sz_239[id_102] };
                          uint8_t id_104 { uint8_t(id_103) };
                          choose_res_101 = id_104;
                        } else {
                          uint8_t id_105 { 0 };
                          uint32_t id_106 { leb128_sz_239[id_105] };
                          uint8_t id_107 { uint8_t(id_106) };
                          uint8_t id_108 { 128 };
                          uint8_t id_109 { uint8_t(id_107 | id_108) };
                          choose_res_101 = id_109;
                        }
                        Pointer id_110 { id_96.writeU8(choose_res_101) };
                        Void id_111 { ((void)(leb128_ptr_240[id_94] = id_110), ::dessser::Void()) };
                        (void)id_111;
                        uint8_t id_112 { 0 };
                        uint8_t id_113 { 0 };
                        uint32_t id_114 { leb128_sz_239[id_113] };
                        uint8_t id_115 { 7 };
                        uint32_t id_116 { uint32_t(id_114 >> id_115) };
                        Void id_117 { ((void)(leb128_sz_239[id_112] = id_116), ::dessser::Void()) };
                        (void)id_117;
                        uint8_t id_118 { 0 };
                        uint32_t id_119 { leb128_sz_239[id_118] };
                        uint32_t id_120 { 0U };
                        bool id_121 { bool(id_119 > id_120) };
                        while_flag_93 = id_121;
                        if (while_flag_93) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_93);
                      (void)::dessser::Void();
                      uint8_t id_122 { 0 };
                      Pointer id_123 { leb128_ptr_240[id_122] };
                      let_res_92 = id_123;
                    }
                    let_res_90 = let_res_92;
                  }
                  Vec<1, Pointer> id_124 {  let_res_90  };
                  Pointer let_res_125;
                  {
                    Vec<1, Pointer> dst_ref_241 { id_124 };
                    int32_t id_126 { 0L };
                    Vec<1, int32_t> id_127 {  id_126  };
                    Pointer let_res_128;
                    {
                      Vec<1, int32_t> n_ref_242 { id_127 };
                      Arr<::dessser::gen::sync_value::tuple> id_129 { std::get<4 /* Tuples */>(p_0) };
                      for (::dessser::gen::sync_value::tuple &x_243 : id_129) {
                        uint8_t id_130 { 0 };
                        uint8_t id_131 { 0 };
                        Pointer id_132 { dst_ref_241[id_131] };
                        Pointer id_133 { tuple_to_row_binary(x_243, id_132) };
                        Void id_134 { ((void)(dst_ref_241[id_130] = id_133), ::dessser::Void()) };
                        (void)id_134;
                        uint8_t id_135 { 0 };
                        int32_t id_136 { 1L };
                        uint8_t id_137 { 0 };
                        int32_t id_138 { n_ref_242[id_137] };
                        int32_t id_139 { int32_t(id_136 + id_138) };
                        Void id_140 { ((void)(n_ref_242[id_135] = id_139), ::dessser::Void()) };
                        (void)id_140;
                        (void)id_140;
                      }
                      (void)::dessser::Void();
                      uint8_t id_141 { 0 };
                      Pointer id_142 { dst_ref_241[id_141] };
                      let_res_128 = id_142;
                    }
                    let_res_125 = let_res_128;
                  }
                  choose_res_86 = let_res_125;
                } else {
                  uint16_t id_143 { 5 };
                  bool id_144 { bool(id_143 == label1_232) };
                  Pointer choose_res_145;
                  if (id_144) {
                    auto fun146 { dessser::gen::raql_value::to_row_binary };
                    dessser::gen::raql_value::t_ext id_147 { std::get<5 /* RamenValue */>(p_0) };
                    Pointer id_148 { fun146(id_147, ssum_dst_233) };
                    choose_res_145 = id_148;
                  } else {
                    uint16_t id_149 { 6 };
                    bool id_150 { bool(id_149 == label1_232) };
                    Pointer choose_res_151;
                    if (id_150) {
                      Arr<dessser::gen::rc_entry::t_ext> id_152 { std::get<6 /* TargetConfig */>(p_0) };
                      uint32_t id_153 { id_152.size() };
                      Vec<1, uint32_t> id_154 {  id_153  };
                      Pointer let_res_155;
                      {
                        Vec<1, uint32_t> leb128_sz_234 { id_154 };
                        Vec<1, Pointer> id_156 {  ssum_dst_233  };
                        Pointer let_res_157;
                        {
                          Vec<1, Pointer> leb128_ptr_235 { id_156 };
                          bool while_flag_158 { true };
                          do {
                            uint8_t id_159 { 0 };
                            uint8_t id_160 { 0 };
                            Pointer id_161 { leb128_ptr_235[id_160] };
                            uint32_t id_162 { 128U };
                            uint8_t id_163 { 0 };
                            uint32_t id_164 { leb128_sz_234[id_163] };
                            bool id_165 { bool(id_162 > id_164) };
                            uint8_t choose_res_166;
                            if (id_165) {
                              uint8_t id_167 { 0 };
                              uint32_t id_168 { leb128_sz_234[id_167] };
                              uint8_t id_169 { uint8_t(id_168) };
                              choose_res_166 = id_169;
                            } else {
                              uint8_t id_170 { 0 };
                              uint32_t id_171 { leb128_sz_234[id_170] };
                              uint8_t id_172 { uint8_t(id_171) };
                              uint8_t id_173 { 128 };
                              uint8_t id_174 { uint8_t(id_172 | id_173) };
                              choose_res_166 = id_174;
                            }
                            Pointer id_175 { id_161.writeU8(choose_res_166) };
                            Void id_176 { ((void)(leb128_ptr_235[id_159] = id_175), ::dessser::Void()) };
                            (void)id_176;
                            uint8_t id_177 { 0 };
                            uint8_t id_178 { 0 };
                            uint32_t id_179 { leb128_sz_234[id_178] };
                            uint8_t id_180 { 7 };
                            uint32_t id_181 { uint32_t(id_179 >> id_180) };
                            Void id_182 { ((void)(leb128_sz_234[id_177] = id_181), ::dessser::Void()) };
                            (void)id_182;
                            uint8_t id_183 { 0 };
                            uint32_t id_184 { leb128_sz_234[id_183] };
                            uint32_t id_185 { 0U };
                            bool id_186 { bool(id_184 > id_185) };
                            while_flag_158 = id_186;
                            if (while_flag_158) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_158);
                          (void)::dessser::Void();
                          uint8_t id_187 { 0 };
                          Pointer id_188 { leb128_ptr_235[id_187] };
                          let_res_157 = id_188;
                        }
                        let_res_155 = let_res_157;
                      }
                      Vec<1, Pointer> id_189 {  let_res_155  };
                      Pointer let_res_190;
                      {
                        Vec<1, Pointer> dst_ref_236 { id_189 };
                        int32_t id_191 { 0L };
                        Vec<1, int32_t> id_192 {  id_191  };
                        Pointer let_res_193;
                        {
                          Vec<1, int32_t> n_ref_237 { id_192 };
                          Arr<dessser::gen::rc_entry::t_ext> id_194 { std::get<6 /* TargetConfig */>(p_0) };
                          for (dessser::gen::rc_entry::t_ext &x_238 : id_194) {
                            uint8_t id_195 { 0 };
                            auto fun196 { dessser::gen::rc_entry::to_row_binary };
                            uint8_t id_197 { 0 };
                            Pointer id_198 { dst_ref_236[id_197] };
                            Pointer id_199 { fun196(x_238, id_198) };
                            Void id_200 { ((void)(dst_ref_236[id_195] = id_199), ::dessser::Void()) };
                            (void)id_200;
                            uint8_t id_201 { 0 };
                            int32_t id_202 { 1L };
                            uint8_t id_203 { 0 };
                            int32_t id_204 { n_ref_237[id_203] };
                            int32_t id_205 { int32_t(id_202 + id_204) };
                            Void id_206 { ((void)(n_ref_237[id_201] = id_205), ::dessser::Void()) };
                            (void)id_206;
                            (void)id_206;
                          }
                          (void)::dessser::Void();
                          uint8_t id_207 { 0 };
                          Pointer id_208 { dst_ref_236[id_207] };
                          let_res_193 = id_208;
                        }
                        let_res_190 = let_res_193;
                      }
                      choose_res_151 = let_res_190;
                    } else {
                      uint16_t id_209 { 7 };
                      bool id_210 { bool(id_209 == label1_232) };
                      Pointer choose_res_211;
                      if (id_210) {
                        auto fun212 { dessser::gen::source_info::to_row_binary };
                        dessser::gen::source_info::t_ext id_213 { std::get<7 /* SourceInfo */>(p_0) };
                        Pointer id_214 { fun212(id_213, ssum_dst_233) };
                        choose_res_211 = id_214;
                      } else {
                        uint16_t id_215 { 8 };
                        bool id_216 { bool(id_215 == label1_232) };
                        Pointer choose_res_217;
                        if (id_216) {
                          auto fun218 { dessser::gen::runtime_stats::to_row_binary };
                          dessser::gen::runtime_stats::t_ext id_219 { std::get<8 /* RuntimeStats */>(p_0) };
                          Pointer id_220 { fun218(id_219, ssum_dst_233) };
                          choose_res_217 = id_220;
                        } else {
                          uint16_t id_221 { 9 };
                          bool id_222 { bool(id_221 == label1_232) };
                          Pointer choose_res_223;
                          if (id_222) {
                            auto fun224 { dessser::gen::replay::to_row_binary };
                            dessser::gen::replay::t_ext id_225 { std::get<9 /* Replay */>(p_0) };
                            Pointer id_226 { fun224(id_225, ssum_dst_233) };
                            choose_res_223 = id_226;
                          } else {
                            uint16_t id_227 { 10 };
                            bool id_228 { bool(id_227 == label1_232) };
                            Pointer choose_res_229;
                            if (id_228) {
                              auto fun230 { dessser::gen::replayer::to_row_binary };
                              dessser::gen::replayer::t_ext id_231 { std::get<10 /* Replayer */>(p_0) };
                              Pointer id_232 { fun230(id_231, ssum_dst_233) };
                              choose_res_229 = id_232;
                            } else {
                              uint16_t id_233 { 11 };
                              bool id_234 { bool(id_233 == label1_232) };
                              Pointer choose_res_235;
                              if (id_234) {
                                auto fun236 { dessser::gen::replay_request::to_row_binary };
                                dessser::gen::replay_request::t_ext id_237 { std::get<11 /* ReplayRequest */>(p_0) };
                                Pointer id_238 { fun236(id_237, ssum_dst_233) };
                                choose_res_235 = id_238;
                              } else {
                                uint16_t id_239 { 12 };
                                bool id_240 { bool(id_239 == label1_232) };
                                Pointer choose_res_241;
                                if (id_240) {
                                  auto fun242 { dessser::gen::alert::to_row_binary };
                                  dessser::gen::alert::t_ext id_243 { std::get<12 /* Alert */>(p_0) };
                                  Pointer id_244 { fun242(id_243, ssum_dst_233) };
                                  choose_res_241 = id_244;
                                } else {
                                  uint16_t id_245 { 13 };
                                  bool id_246 { bool(id_245 == label1_232) };
                                  Pointer choose_res_247;
                                  if (id_246) {
                                    auto fun248 { dessser::gen::pivot::to_row_binary };
                                    dessser::gen::pivot::t_ext id_249 { std::get<13 /* Pivot */>(p_0) };
                                    Pointer id_250 { fun248(id_249, ssum_dst_233) };
                                    choose_res_247 = id_250;
                                  } else {
                                    uint16_t id_251 { 14 };
                                    bool id_252 { bool(id_251 == label1_232) };
                                    Pointer choose_res_253;
                                    if (id_252) {
                                      auto fun254 { dessser::gen::output_specs::to_row_binary };
                                      dessser::gen::output_specs::t_ext id_255 { std::get<14 /* OutputSpecs */>(p_0) };
                                      Pointer id_256 { fun254(id_255, ssum_dst_233) };
                                      choose_res_253 = id_256;
                                    } else {
                                      uint16_t id_257 { 15 };
                                      bool id_258 { bool(id_257 == label1_232) };
                                      Pointer choose_res_259;
                                      if (id_258) {
                                        auto fun260 { dessser::gen::dashboard_widget::to_row_binary };
                                        dessser::gen::dashboard_widget::t_ext id_261 { std::get<15 /* DashboardWidget */>(p_0) };
                                        Pointer id_262 { fun260(id_261, ssum_dst_233) };
                                        choose_res_259 = id_262;
                                      } else {
                                        uint16_t id_263 { 16 };
                                        bool id_264 { bool(id_263 == label1_232) };
                                        Pointer choose_res_265;
                                        if (id_264) {
                                          auto fun266 { dessser::gen::alerting_contact::to_row_binary };
                                          dessser::gen::alerting_contact::t_ext id_267 { std::get<16 /* AlertingContact */>(p_0) };
                                          Pointer id_268 { fun266(id_267, ssum_dst_233) };
                                          choose_res_265 = id_268;
                                        } else {
                                          uint16_t id_269 { 17 };
                                          bool id_270 { bool(id_269 == label1_232) };
                                          Pointer choose_res_271;
                                          if (id_270) {
                                            auto fun272 { dessser::gen::alerting_notification::to_row_binary };
                                            dessser::gen::alerting_notification::t_ext id_273 { std::get<17 /* Notification */>(p_0) };
                                            Pointer id_274 { fun272(id_273, ssum_dst_233) };
                                            choose_res_271 = id_274;
                                          } else {
                                            uint16_t id_275 { 18 };
                                            bool id_276 { bool(id_275 == label1_232) };
                                            Pointer choose_res_277;
                                            if (id_276) {
                                              auto fun278 { dessser::gen::alerting_delivery_status::to_row_binary };
                                              dessser::gen::alerting_delivery_status::t_ext id_279 { std::get<18 /* DeliveryStatus */>(p_0) };
                                              Pointer id_280 { fun278(id_279, ssum_dst_233) };
                                              choose_res_277 = id_280;
                                            } else {
                                              uint16_t id_281 { 19 };
                                              bool id_282 { bool(id_281 == label1_232) };
                                              Pointer choose_res_283;
                                              if (id_282) {
                                                auto fun284 { dessser::gen::alerting_log::to_row_binary };
                                                dessser::gen::alerting_log::t_ext id_285 { std::get<19 /* IncidentLog */>(p_0) };
                                                Pointer id_286 { fun284(id_285, ssum_dst_233) };
                                                choose_res_283 = id_286;
                                              } else {
                                                uint16_t id_287 { 20 };
                                                bool id_288 { bool(label1_232 == id_287) };
                                                Void id_289 { ((void)(assert(id_288)), ::dessser::Void()) };
                                                (void)id_289;
                                                auto fun290 { dessser::gen::alerting_inhibition::to_row_binary };
                                                dessser::gen::alerting_inhibition::t_ext id_291 { std::get<20 /* Inhibition */>(p_0) };
                                                Pointer id_292 { fun290(id_291, ssum_dst_233) };
                                                choose_res_283 = id_292;
                                              }
                                              choose_res_277 = choose_res_283;
                                            }
                                            choose_res_271 = choose_res_277;
                                          }
                                          choose_res_265 = choose_res_271;
                                        }
                                        choose_res_259 = choose_res_265;
                                      }
                                      choose_res_253 = choose_res_259;
                                    }
                                    choose_res_247 = choose_res_253;
                                  }
                                  choose_res_241 = choose_res_247;
                                }
                                choose_res_235 = choose_res_241;
                              }
                              choose_res_229 = choose_res_235;
                            }
                            choose_res_223 = choose_res_229;
                          }
                          choose_res_217 = choose_res_223;
                        }
                        choose_res_211 = choose_res_217;
                      }
                      choose_res_151 = choose_res_211;
                    }
                    choose_res_145 = choose_res_151;
                  }
                  choose_res_86 = choose_res_145;
                }
                choose_res_80 = choose_res_86;
              }
              choose_res_74 = choose_res_80;
            }
            choose_res_68 = choose_res_74;
          }
          choose_res_14 = choose_res_68;
        }
        let_res_11 = choose_res_14;
      }
      let_res_9 = let_res_11;
    }
    return let_res_9;
  }
   };
  return fun7;
}
std::function<Pointer(::dessser::gen::sync_value::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{skipped: U32; values: $raql_value}") (add (size 4) (apply (ext-identifier raql_value sersize-of-row-binary) (get-field "values" (param 0)))))
 */
static std::function<Size(::dessser::gen::sync_value::tuple &)> tuple_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_value::tuple &)> fun293 { [&](::dessser::gen::sync_value::tuple p_0) {
    Size id_294 { 4UL };
    auto fun295 { dessser::gen::raql_value::sersize_of_row_binary };
    dessser::gen::raql_value::t_ext id_296 { p_0.values };
    Size id_297 { fun295(id_296) };
    Size id_298 { Size(id_294 + id_297) };
    return id_298;
  }
   };
  return fun293;
}
std::function<Size(::dessser::gen::sync_value::tuple &)> tuple_sersize_of_row_binary(tuple_sersize_of_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]")
      (let "label2_216" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_216"))
          (add (size 14)
            (add
              (let "n_ref_229" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                (let "lebsz_ref_230" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_229")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_230")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_230") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_230")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_230")))))) 
              (size-of-u32 (string-length (get-item 2 (get-alt "Error" (param 0)))))))
          (if (eq (u16 1) (identifier "label2_216")) (add (size 2) (apply (ext-identifier worker sersize-of-row-binary) (get-alt "Worker" (param 0))))
            (if (eq (u16 2) (identifier "label2_216")) (add (size 2) (apply (ext-identifier retention sersize-of-row-binary) (get-alt "Retention" (param 0))))
              (if (eq (u16 3) (identifier "label2_216")) (add (size 2) (apply (ext-identifier time_range sersize-of-row-binary) (get-alt "TimeRange" (param 0))))
                (if (eq (u16 4) (identifier "label2_216"))
                  (let "sz_ref_223"
                    (make-vec
                      (add (size 2)
                        (let "n_ref_221" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "lebsz_ref_222" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_221")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_222")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_222") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_222")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_222"))))))))
                    (seq
                      (let "repeat_n_224" (make-vec (i32 0))
                        (while (gt (to-i32 (cardinality (get-alt "Tuples" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_224")))
                          (seq
                            (set-vec (u8 0) (identifier "sz_ref_223")
                              (add (unsafe-nth (u8 0) (identifier "sz_ref_223")) (apply (identifier "tuple-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_224")) (get-alt "Tuples" (param 0))))))
                            (set-vec (u8 0) (identifier "repeat_n_224") (add (unsafe-nth (u8 0) (identifier "repeat_n_224")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "sz_ref_223"))))
                  (if (eq (u16 5) (identifier "label2_216")) (add (size 2) (apply (ext-identifier raql_value sersize-of-row-binary) (get-alt "RamenValue" (param 0))))
                    (if (eq (u16 6) (identifier "label2_216"))
                      (let "sz_ref_219"
                        (make-vec
                          (add (size 2)
                            (let "n_ref_217" (make-vec (cardinality (get-alt "TargetConfig" (param 0))))
                              (let "lebsz_ref_218" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_217")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_218")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_218") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_218")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_218"))))))))
                        (seq
                          (let "repeat_n_220" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-alt "TargetConfig" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_220")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_219")
                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_219"))
                                    (apply (ext-identifier rc_entry sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_220")) (get-alt "TargetConfig" (param 0))))))
                                (set-vec (u8 0) (identifier "repeat_n_220") (add (unsafe-nth (u8 0) (identifier "repeat_n_220")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_219"))))
                      (if (eq (u16 7) (identifier "label2_216")) (add (size 2) (apply (ext-identifier source_info sersize-of-row-binary) (get-alt "SourceInfo" (param 0))))
                        (if (eq (u16 8) (identifier "label2_216")) (add (size 2) (apply (ext-identifier runtime_stats sersize-of-row-binary) (get-alt "RuntimeStats" (param 0))))
                          (if (eq (u16 9) (identifier "label2_216")) 
                            (add (size 2) (apply (ext-identifier replay sersize-of-row-binary) (get-alt "Replay" (param 0))))
                            (if (eq (u16 10) (identifier "label2_216")) 
                              (add (size 2) (apply (ext-identifier replayer sersize-of-row-binary) (get-alt "Replayer" (param 0))))
                              (if (eq (u16 11) (identifier "label2_216")) 
                                (add (size 2) (apply (ext-identifier replay_request sersize-of-row-binary) (get-alt "ReplayRequest" (param 0))))
                                (if (eq (u16 12) (identifier "label2_216")) 
                                  (add (size 2) (apply (ext-identifier alert sersize-of-row-binary) (get-alt "Alert" (param 0))))
                                  (if (eq (u16 13) (identifier "label2_216")) 
                                    (add (size 2) (apply (ext-identifier pivot sersize-of-row-binary) (get-alt "Pivot" (param 0))))
                                    (if (eq (u16 14) (identifier "label2_216")) 
                                      (add (size 2) (apply (ext-identifier output_specs sersize-of-row-binary) (get-alt "OutputSpecs" (param 0))))
                                      (if (eq (u16 15) (identifier "label2_216")) 
                                        (add (size 2) (apply (ext-identifier dashboard_widget sersize-of-row-binary) (get-alt "DashboardWidget" (param 0))))
                                        (if (eq (u16 16) (identifier "label2_216")) 
                                          (add (size 2) (apply (ext-identifier alerting_contact sersize-of-row-binary) (get-alt "AlertingContact" (param 0))))
                                          (if (eq (u16 17) (identifier "label2_216")) 
                                            (add (size 2) (apply (ext-identifier alerting_notification sersize-of-row-binary) (get-alt "Notification" (param 0))))
                                            (if (eq (u16 18) (identifier "label2_216")) 
                                              (add (size 2) (apply (ext-identifier alerting_delivery_status sersize-of-row-binary) (get-alt "DeliveryStatus" (param 0))))
                                              (if (eq (u16 19) (identifier "label2_216")) 
                                                (add (size 2) (apply (ext-identifier alerting_log sersize-of-row-binary) (get-alt "IncidentLog" (param 0))))
                                                (seq (assert (eq (identifier "label2_216") (u16 20))) (add (size 2) (apply (ext-identifier alerting_inhibition sersize-of-row-binary) (get-alt "Inhibition" (param 0)))))))))))))))))))))))))))
 */
static std::function<Size(::dessser::gen::sync_value::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_value::t &)> fun299 { [&](::dessser::gen::sync_value::t p_0) {
    uint16_t id_300 { uint16_t(p_0.index()) };
    Size let_res_301;
    {
      uint16_t label2_216 { id_300 };
      uint16_t id_302 { 0 };
      bool id_303 { bool(id_302 == label2_216) };
      Size choose_res_304;
      if (id_303) {
        Size id_305 { 14UL };
        ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_306 { std::get<0 /* Error */>(p_0) };
        std::string id_307 { std::get<2>(id_306) };
        uint32_t id_308 { (uint32_t)id_307.size() };
        Vec<1, uint32_t> id_309 {  id_308  };
        Size let_res_310;
        {
          Vec<1, uint32_t> n_ref_229 { id_309 };
          uint32_t id_311 { 1U };
          Vec<1, uint32_t> id_312 {  id_311  };
          Size let_res_313;
          {
            Vec<1, uint32_t> lebsz_ref_230 { id_312 };
            bool while_flag_314 { true };
            do {
              uint8_t id_315 { 0 };
              uint32_t id_316 { n_ref_229[id_315] };
              uint8_t id_317 { 0 };
              uint32_t id_318 { lebsz_ref_230[id_317] };
              uint8_t id_319 { 7 };
              uint32_t id_320 { uint32_t(id_318 << id_319) };
              bool id_321 { bool(id_316 >= id_320) };
              while_flag_314 = id_321;
              if (while_flag_314) {
                uint8_t id_322 { 0 };
                uint8_t id_323 { 0 };
                uint32_t id_324 { lebsz_ref_230[id_323] };
                uint32_t id_325 { 1U };
                uint32_t id_326 { uint32_t(id_324 + id_325) };
                Void id_327 { ((void)(lebsz_ref_230[id_322] = id_326), ::dessser::Void()) };
                (void)id_327;
              }
            } while (while_flag_314);
            (void)::dessser::Void();
            uint8_t id_328 { 0 };
            uint32_t id_329 { lebsz_ref_230[id_328] };
            Size id_330 { Size(id_329) };
            let_res_313 = id_330;
          }
          let_res_310 = let_res_313;
        }
        ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_331 { std::get<0 /* Error */>(p_0) };
        std::string id_332 { std::get<2>(id_331) };
        uint32_t id_333 { (uint32_t)id_332.size() };
        Size id_334 { Size(id_333) };
        Size id_335 { Size(let_res_310 + id_334) };
        Size id_336 { Size(id_305 + id_335) };
        choose_res_304 = id_336;
      } else {
        uint16_t id_337 { 1 };
        bool id_338 { bool(id_337 == label2_216) };
        Size choose_res_339;
        if (id_338) {
          Size id_340 { 2UL };
          auto fun341 { dessser::gen::worker::sersize_of_row_binary };
          dessser::gen::worker::t_ext id_342 { std::get<1 /* Worker */>(p_0) };
          Size id_343 { fun341(id_342) };
          Size id_344 { Size(id_340 + id_343) };
          choose_res_339 = id_344;
        } else {
          uint16_t id_345 { 2 };
          bool id_346 { bool(id_345 == label2_216) };
          Size choose_res_347;
          if (id_346) {
            Size id_348 { 2UL };
            auto fun349 { dessser::gen::retention::sersize_of_row_binary };
            dessser::gen::retention::t_ext id_350 { std::get<2 /* Retention */>(p_0) };
            Size id_351 { fun349(id_350) };
            Size id_352 { Size(id_348 + id_351) };
            choose_res_347 = id_352;
          } else {
            uint16_t id_353 { 3 };
            bool id_354 { bool(id_353 == label2_216) };
            Size choose_res_355;
            if (id_354) {
              Size id_356 { 2UL };
              auto fun357 { dessser::gen::time_range::sersize_of_row_binary };
              dessser::gen::time_range::t_ext id_358 { std::get<3 /* TimeRange */>(p_0) };
              Size id_359 { fun357(id_358) };
              Size id_360 { Size(id_356 + id_359) };
              choose_res_355 = id_360;
            } else {
              uint16_t id_361 { 4 };
              bool id_362 { bool(id_361 == label2_216) };
              Size choose_res_363;
              if (id_362) {
                Size id_364 { 2UL };
                Arr<::dessser::gen::sync_value::tuple> id_365 { std::get<4 /* Tuples */>(p_0) };
                uint32_t id_366 { id_365.size() };
                Vec<1, uint32_t> id_367 {  id_366  };
                Size let_res_368;
                {
                  Vec<1, uint32_t> n_ref_221 { id_367 };
                  uint32_t id_369 { 1U };
                  Vec<1, uint32_t> id_370 {  id_369  };
                  Size let_res_371;
                  {
                    Vec<1, uint32_t> lebsz_ref_222 { id_370 };
                    bool while_flag_372 { true };
                    do {
                      uint8_t id_373 { 0 };
                      uint32_t id_374 { n_ref_221[id_373] };
                      uint8_t id_375 { 0 };
                      uint32_t id_376 { lebsz_ref_222[id_375] };
                      uint8_t id_377 { 7 };
                      uint32_t id_378 { uint32_t(id_376 << id_377) };
                      bool id_379 { bool(id_374 >= id_378) };
                      while_flag_372 = id_379;
                      if (while_flag_372) {
                        uint8_t id_380 { 0 };
                        uint8_t id_381 { 0 };
                        uint32_t id_382 { lebsz_ref_222[id_381] };
                        uint32_t id_383 { 1U };
                        uint32_t id_384 { uint32_t(id_382 + id_383) };
                        Void id_385 { ((void)(lebsz_ref_222[id_380] = id_384), ::dessser::Void()) };
                        (void)id_385;
                      }
                    } while (while_flag_372);
                    (void)::dessser::Void();
                    uint8_t id_386 { 0 };
                    uint32_t id_387 { lebsz_ref_222[id_386] };
                    Size id_388 { Size(id_387) };
                    let_res_371 = id_388;
                  }
                  let_res_368 = let_res_371;
                }
                Size id_389 { Size(id_364 + let_res_368) };
                Vec<1, Size> id_390 {  id_389  };
                Size let_res_391;
                {
                  Vec<1, Size> sz_ref_223 { id_390 };
                  int32_t id_392 { 0L };
                  Vec<1, int32_t> id_393 {  id_392  };
                  {
                    Vec<1, int32_t> repeat_n_224 { id_393 };
                    bool while_flag_394 { true };
                    do {
                      Arr<::dessser::gen::sync_value::tuple> id_395 { std::get<4 /* Tuples */>(p_0) };
                      uint32_t id_396 { id_395.size() };
                      int32_t id_397 { int32_t(id_396) };
                      uint8_t id_398 { 0 };
                      int32_t id_399 { repeat_n_224[id_398] };
                      bool id_400 { bool(id_397 > id_399) };
                      while_flag_394 = id_400;
                      if (while_flag_394) {
                        uint8_t id_401 { 0 };
                        uint8_t id_402 { 0 };
                        Size id_403 { sz_ref_223[id_402] };
                        uint8_t id_404 { 0 };
                        int32_t id_405 { repeat_n_224[id_404] };
                        Arr<::dessser::gen::sync_value::tuple> id_406 { std::get<4 /* Tuples */>(p_0) };
                        ::dessser::gen::sync_value::tuple id_407 { id_406[id_405] };
                        Size id_408 { tuple_sersize_of_row_binary(id_407) };
                        Size id_409 { Size(id_403 + id_408) };
                        Void id_410 { ((void)(sz_ref_223[id_401] = id_409), ::dessser::Void()) };
                        (void)id_410;
                        uint8_t id_411 { 0 };
                        uint8_t id_412 { 0 };
                        int32_t id_413 { repeat_n_224[id_412] };
                        int32_t id_414 { 1L };
                        int32_t id_415 { int32_t(id_413 + id_414) };
                        Void id_416 { ((void)(repeat_n_224[id_411] = id_415), ::dessser::Void()) };
                        (void)id_416;
                        (void)id_416;
                      }
                    } while (while_flag_394);
                    (void)::dessser::Void();
                  }
                  (void)::dessser::Void();
                  uint8_t id_417 { 0 };
                  Size id_418 { sz_ref_223[id_417] };
                  let_res_391 = id_418;
                }
                choose_res_363 = let_res_391;
              } else {
                uint16_t id_419 { 5 };
                bool id_420 { bool(id_419 == label2_216) };
                Size choose_res_421;
                if (id_420) {
                  Size id_422 { 2UL };
                  auto fun423 { dessser::gen::raql_value::sersize_of_row_binary };
                  dessser::gen::raql_value::t_ext id_424 { std::get<5 /* RamenValue */>(p_0) };
                  Size id_425 { fun423(id_424) };
                  Size id_426 { Size(id_422 + id_425) };
                  choose_res_421 = id_426;
                } else {
                  uint16_t id_427 { 6 };
                  bool id_428 { bool(id_427 == label2_216) };
                  Size choose_res_429;
                  if (id_428) {
                    Size id_430 { 2UL };
                    Arr<dessser::gen::rc_entry::t_ext> id_431 { std::get<6 /* TargetConfig */>(p_0) };
                    uint32_t id_432 { id_431.size() };
                    Vec<1, uint32_t> id_433 {  id_432  };
                    Size let_res_434;
                    {
                      Vec<1, uint32_t> n_ref_217 { id_433 };
                      uint32_t id_435 { 1U };
                      Vec<1, uint32_t> id_436 {  id_435  };
                      Size let_res_437;
                      {
                        Vec<1, uint32_t> lebsz_ref_218 { id_436 };
                        bool while_flag_438 { true };
                        do {
                          uint8_t id_439 { 0 };
                          uint32_t id_440 { n_ref_217[id_439] };
                          uint8_t id_441 { 0 };
                          uint32_t id_442 { lebsz_ref_218[id_441] };
                          uint8_t id_443 { 7 };
                          uint32_t id_444 { uint32_t(id_442 << id_443) };
                          bool id_445 { bool(id_440 >= id_444) };
                          while_flag_438 = id_445;
                          if (while_flag_438) {
                            uint8_t id_446 { 0 };
                            uint8_t id_447 { 0 };
                            uint32_t id_448 { lebsz_ref_218[id_447] };
                            uint32_t id_449 { 1U };
                            uint32_t id_450 { uint32_t(id_448 + id_449) };
                            Void id_451 { ((void)(lebsz_ref_218[id_446] = id_450), ::dessser::Void()) };
                            (void)id_451;
                          }
                        } while (while_flag_438);
                        (void)::dessser::Void();
                        uint8_t id_452 { 0 };
                        uint32_t id_453 { lebsz_ref_218[id_452] };
                        Size id_454 { Size(id_453) };
                        let_res_437 = id_454;
                      }
                      let_res_434 = let_res_437;
                    }
                    Size id_455 { Size(id_430 + let_res_434) };
                    Vec<1, Size> id_456 {  id_455  };
                    Size let_res_457;
                    {
                      Vec<1, Size> sz_ref_219 { id_456 };
                      int32_t id_458 { 0L };
                      Vec<1, int32_t> id_459 {  id_458  };
                      {
                        Vec<1, int32_t> repeat_n_220 { id_459 };
                        bool while_flag_460 { true };
                        do {
                          Arr<dessser::gen::rc_entry::t_ext> id_461 { std::get<6 /* TargetConfig */>(p_0) };
                          uint32_t id_462 { id_461.size() };
                          int32_t id_463 { int32_t(id_462) };
                          uint8_t id_464 { 0 };
                          int32_t id_465 { repeat_n_220[id_464] };
                          bool id_466 { bool(id_463 > id_465) };
                          while_flag_460 = id_466;
                          if (while_flag_460) {
                            uint8_t id_467 { 0 };
                            uint8_t id_468 { 0 };
                            Size id_469 { sz_ref_219[id_468] };
                            auto fun470 { dessser::gen::rc_entry::sersize_of_row_binary };
                            uint8_t id_471 { 0 };
                            int32_t id_472 { repeat_n_220[id_471] };
                            Arr<dessser::gen::rc_entry::t_ext> id_473 { std::get<6 /* TargetConfig */>(p_0) };
                            dessser::gen::rc_entry::t_ext id_474 { id_473[id_472] };
                            Size id_475 { fun470(id_474) };
                            Size id_476 { Size(id_469 + id_475) };
                            Void id_477 { ((void)(sz_ref_219[id_467] = id_476), ::dessser::Void()) };
                            (void)id_477;
                            uint8_t id_478 { 0 };
                            uint8_t id_479 { 0 };
                            int32_t id_480 { repeat_n_220[id_479] };
                            int32_t id_481 { 1L };
                            int32_t id_482 { int32_t(id_480 + id_481) };
                            Void id_483 { ((void)(repeat_n_220[id_478] = id_482), ::dessser::Void()) };
                            (void)id_483;
                            (void)id_483;
                          }
                        } while (while_flag_460);
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_484 { 0 };
                      Size id_485 { sz_ref_219[id_484] };
                      let_res_457 = id_485;
                    }
                    choose_res_429 = let_res_457;
                  } else {
                    uint16_t id_486 { 7 };
                    bool id_487 { bool(id_486 == label2_216) };
                    Size choose_res_488;
                    if (id_487) {
                      Size id_489 { 2UL };
                      auto fun490 { dessser::gen::source_info::sersize_of_row_binary };
                      dessser::gen::source_info::t_ext id_491 { std::get<7 /* SourceInfo */>(p_0) };
                      Size id_492 { fun490(id_491) };
                      Size id_493 { Size(id_489 + id_492) };
                      choose_res_488 = id_493;
                    } else {
                      uint16_t id_494 { 8 };
                      bool id_495 { bool(id_494 == label2_216) };
                      Size choose_res_496;
                      if (id_495) {
                        Size id_497 { 2UL };
                        auto fun498 { dessser::gen::runtime_stats::sersize_of_row_binary };
                        dessser::gen::runtime_stats::t_ext id_499 { std::get<8 /* RuntimeStats */>(p_0) };
                        Size id_500 { fun498(id_499) };
                        Size id_501 { Size(id_497 + id_500) };
                        choose_res_496 = id_501;
                      } else {
                        uint16_t id_502 { 9 };
                        bool id_503 { bool(id_502 == label2_216) };
                        Size choose_res_504;
                        if (id_503) {
                          Size id_505 { 2UL };
                          auto fun506 { dessser::gen::replay::sersize_of_row_binary };
                          dessser::gen::replay::t_ext id_507 { std::get<9 /* Replay */>(p_0) };
                          Size id_508 { fun506(id_507) };
                          Size id_509 { Size(id_505 + id_508) };
                          choose_res_504 = id_509;
                        } else {
                          uint16_t id_510 { 10 };
                          bool id_511 { bool(id_510 == label2_216) };
                          Size choose_res_512;
                          if (id_511) {
                            Size id_513 { 2UL };
                            auto fun514 { dessser::gen::replayer::sersize_of_row_binary };
                            dessser::gen::replayer::t_ext id_515 { std::get<10 /* Replayer */>(p_0) };
                            Size id_516 { fun514(id_515) };
                            Size id_517 { Size(id_513 + id_516) };
                            choose_res_512 = id_517;
                          } else {
                            uint16_t id_518 { 11 };
                            bool id_519 { bool(id_518 == label2_216) };
                            Size choose_res_520;
                            if (id_519) {
                              Size id_521 { 2UL };
                              auto fun522 { dessser::gen::replay_request::sersize_of_row_binary };
                              dessser::gen::replay_request::t_ext id_523 { std::get<11 /* ReplayRequest */>(p_0) };
                              Size id_524 { fun522(id_523) };
                              Size id_525 { Size(id_521 + id_524) };
                              choose_res_520 = id_525;
                            } else {
                              uint16_t id_526 { 12 };
                              bool id_527 { bool(id_526 == label2_216) };
                              Size choose_res_528;
                              if (id_527) {
                                Size id_529 { 2UL };
                                auto fun530 { dessser::gen::alert::sersize_of_row_binary };
                                dessser::gen::alert::t_ext id_531 { std::get<12 /* Alert */>(p_0) };
                                Size id_532 { fun530(id_531) };
                                Size id_533 { Size(id_529 + id_532) };
                                choose_res_528 = id_533;
                              } else {
                                uint16_t id_534 { 13 };
                                bool id_535 { bool(id_534 == label2_216) };
                                Size choose_res_536;
                                if (id_535) {
                                  Size id_537 { 2UL };
                                  auto fun538 { dessser::gen::pivot::sersize_of_row_binary };
                                  dessser::gen::pivot::t_ext id_539 { std::get<13 /* Pivot */>(p_0) };
                                  Size id_540 { fun538(id_539) };
                                  Size id_541 { Size(id_537 + id_540) };
                                  choose_res_536 = id_541;
                                } else {
                                  uint16_t id_542 { 14 };
                                  bool id_543 { bool(id_542 == label2_216) };
                                  Size choose_res_544;
                                  if (id_543) {
                                    Size id_545 { 2UL };
                                    auto fun546 { dessser::gen::output_specs::sersize_of_row_binary };
                                    dessser::gen::output_specs::t_ext id_547 { std::get<14 /* OutputSpecs */>(p_0) };
                                    Size id_548 { fun546(id_547) };
                                    Size id_549 { Size(id_545 + id_548) };
                                    choose_res_544 = id_549;
                                  } else {
                                    uint16_t id_550 { 15 };
                                    bool id_551 { bool(id_550 == label2_216) };
                                    Size choose_res_552;
                                    if (id_551) {
                                      Size id_553 { 2UL };
                                      auto fun554 { dessser::gen::dashboard_widget::sersize_of_row_binary };
                                      dessser::gen::dashboard_widget::t_ext id_555 { std::get<15 /* DashboardWidget */>(p_0) };
                                      Size id_556 { fun554(id_555) };
                                      Size id_557 { Size(id_553 + id_556) };
                                      choose_res_552 = id_557;
                                    } else {
                                      uint16_t id_558 { 16 };
                                      bool id_559 { bool(id_558 == label2_216) };
                                      Size choose_res_560;
                                      if (id_559) {
                                        Size id_561 { 2UL };
                                        auto fun562 { dessser::gen::alerting_contact::sersize_of_row_binary };
                                        dessser::gen::alerting_contact::t_ext id_563 { std::get<16 /* AlertingContact */>(p_0) };
                                        Size id_564 { fun562(id_563) };
                                        Size id_565 { Size(id_561 + id_564) };
                                        choose_res_560 = id_565;
                                      } else {
                                        uint16_t id_566 { 17 };
                                        bool id_567 { bool(id_566 == label2_216) };
                                        Size choose_res_568;
                                        if (id_567) {
                                          Size id_569 { 2UL };
                                          auto fun570 { dessser::gen::alerting_notification::sersize_of_row_binary };
                                          dessser::gen::alerting_notification::t_ext id_571 { std::get<17 /* Notification */>(p_0) };
                                          Size id_572 { fun570(id_571) };
                                          Size id_573 { Size(id_569 + id_572) };
                                          choose_res_568 = id_573;
                                        } else {
                                          uint16_t id_574 { 18 };
                                          bool id_575 { bool(id_574 == label2_216) };
                                          Size choose_res_576;
                                          if (id_575) {
                                            Size id_577 { 2UL };
                                            auto fun578 { dessser::gen::alerting_delivery_status::sersize_of_row_binary };
                                            dessser::gen::alerting_delivery_status::t_ext id_579 { std::get<18 /* DeliveryStatus */>(p_0) };
                                            Size id_580 { fun578(id_579) };
                                            Size id_581 { Size(id_577 + id_580) };
                                            choose_res_576 = id_581;
                                          } else {
                                            uint16_t id_582 { 19 };
                                            bool id_583 { bool(id_582 == label2_216) };
                                            Size choose_res_584;
                                            if (id_583) {
                                              Size id_585 { 2UL };
                                              auto fun586 { dessser::gen::alerting_log::sersize_of_row_binary };
                                              dessser::gen::alerting_log::t_ext id_587 { std::get<19 /* IncidentLog */>(p_0) };
                                              Size id_588 { fun586(id_587) };
                                              Size id_589 { Size(id_585 + id_588) };
                                              choose_res_584 = id_589;
                                            } else {
                                              uint16_t id_590 { 20 };
                                              bool id_591 { bool(label2_216 == id_590) };
                                              Void id_592 { ((void)(assert(id_591)), ::dessser::Void()) };
                                              (void)id_592;
                                              Size id_593 { 2UL };
                                              auto fun594 { dessser::gen::alerting_inhibition::sersize_of_row_binary };
                                              dessser::gen::alerting_inhibition::t_ext id_595 { std::get<20 /* Inhibition */>(p_0) };
                                              Size id_596 { fun594(id_595) };
                                              Size id_597 { Size(id_593 + id_596) };
                                              choose_res_584 = id_597;
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
                                  choose_res_536 = choose_res_544;
                                }
                                choose_res_528 = choose_res_536;
                              }
                              choose_res_520 = choose_res_528;
                            }
                            choose_res_512 = choose_res_520;
                          }
                          choose_res_504 = choose_res_512;
                        }
                        choose_res_496 = choose_res_504;
                      }
                      choose_res_488 = choose_res_496;
                    }
                    choose_res_429 = choose_res_488;
                  }
                  choose_res_421 = choose_res_429;
                }
                choose_res_363 = choose_res_421;
              }
              choose_res_355 = choose_res_363;
            }
            choose_res_347 = choose_res_355;
          }
          choose_res_339 = choose_res_347;
        }
        choose_res_304 = choose_res_339;
      }
      let_res_301 = choose_res_304;
    }
    return let_res_301;
  }
   };
  return fun299;
}
std::function<Size(::dessser::gen::sync_value::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_60" (let-pair "du32_fst_58" "du32_snd_59" (read-u32 little-endian (param 0)) (make-tup (identifier "du32_fst_58") (identifier "du32_snd_59")))
        (let-pair "drec_fst_61" "drec_snd_62" (identifier "drec_60")
          (let-pair "drec_fst_64" "drec_snd_65" (apply (ext-identifier raql_value of-row-binary) (identifier "drec_snd_62"))
            (make-tup (make-rec (string "values") (identifier "drec_fst_64") (string "skipped") (identifier "drec_fst_61")) (identifier "drec_snd_65"))))))
 */
static std::function<::dessser::gen::sync_value::tc689a7a5ea052f6c0e885d3374325d5b(Pointer &)> tuple_of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::tc689a7a5ea052f6c0e885d3374325d5b(Pointer &)> fun598 { [&](Pointer p_0) {
    ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_599 { p_0.readU32Le() };
    ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 letpair_res_600;
    {
      auto du32_fst_58 { std::get<0>(id_599) };
      auto du32_snd_59 { std::get<1>(id_599) };
      ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_601 { du32_fst_58, du32_snd_59 };
      letpair_res_600 = id_601;
    }
    ::dessser::gen::sync_value::tc689a7a5ea052f6c0e885d3374325d5b let_res_602;
    {
      ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 drec_60 { letpair_res_600 };
      ::dessser::gen::sync_value::tc689a7a5ea052f6c0e885d3374325d5b letpair_res_603;
      {
        auto drec_fst_61 { std::get<0>(drec_60) };
        auto drec_snd_62 { std::get<1>(drec_60) };
        auto fun604 { dessser::gen::raql_value::of_row_binary };
        ::dessser::gen::sync_value::tf3063cfb73e0f06d3ea99ebd15a86d50 id_605 { fun604(drec_snd_62) };
        ::dessser::gen::sync_value::tc689a7a5ea052f6c0e885d3374325d5b letpair_res_606;
        {
          auto drec_fst_64 { std::get<0>(id_605) };
          auto drec_snd_65 { std::get<1>(id_605) };
          ::dessser::gen::sync_value::tuple id_607 { drec_fst_61, drec_fst_64 };
          ::dessser::gen::sync_value::tc689a7a5ea052f6c0e885d3374325d5b id_608 { id_607, drec_snd_65 };
          letpair_res_606 = id_608;
        }
        letpair_res_603 = letpair_res_606;
      }
      let_res_602 = letpair_res_603;
    }
    return let_res_602;
  }
   };
  return fun598;
}
std::function<::dessser::gen::sync_value::tc689a7a5ea052f6c0e885d3374325d5b(Pointer &)> tuple_of_row_binary(tuple_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_72" (let-pair "du16_fst_67" "du16_snd_68" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_67") (identifier "du16_snd_68")))
        (let-pair "dsum1_fst_73" "dsum1_snd_74" (identifier "dsum1_72")
          (if (eq (u16 0) (identifier "dsum1_fst_73"))
            (let "dtup_184" (let-pair "dfloat_fst_182" "dfloat_snd_183" (read-u64 little-endian (identifier "dsum1_snd_74")) (make-tup (float-of-u64 (identifier "dfloat_fst_182")) (identifier "dfloat_snd_183")))
              (let-pair "dtup_fst_185" "dtup_snd_186" (identifier "dtup_184")
                (let "dtup_190" (let-pair "du32_fst_188" "du32_snd_189" (read-u32 little-endian (identifier "dtup_snd_186")) (make-tup (identifier "du32_fst_188") (identifier "du32_snd_189")))
                  (let-pair "dtup_fst_191" "dtup_snd_192" (identifier "dtup_190")
                    (let "dstring1_199"
                      (let "leb_ref_193" (make-vec (u32 0))
                        (let "shft_ref_194" (make-vec (u8 0))
                          (let "p_ref_195" (make-vec (identifier "dtup_snd_192"))
                            (seq
                              (while
                                (let "leb128_196" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_195")))
                                  (let-pair "leb128_fst_197" "leb128_snd_198" 
                                    (identifier "leb128_196")
                                    (seq (set-vec (u8 0) (identifier "p_ref_195") (identifier "leb128_snd_198"))
                                      (set-vec (u8 0) (identifier "leb_ref_193")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_197") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_194"))) (unsafe-nth (u8 0) (identifier "leb_ref_193"))))
                                      (set-vec (u8 0) (identifier "shft_ref_194") (add (unsafe-nth (u8 0) (identifier "shft_ref_194")) (u8 7))) 
                                      (ge (identifier "leb128_fst_197") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_193"))) (unsafe-nth (u8 0) (identifier "p_ref_195")))))))
                      (let-pair "dstring1_fst_200" "dstring1_snd_201" 
                        (identifier "dstring1_199")
                        (let-pair "dstring2_fst_203" "dstring2_snd_204" 
                          (read-bytes (identifier "dstring1_snd_201") (identifier "dstring1_fst_200"))
                          (make-tup
                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 0
                              (make-tup (identifier "dtup_fst_185") (identifier "dtup_fst_191") (string-of-bytes (identifier "dstring2_fst_203")))) 
                            (identifier "dstring2_snd_204")))))))))
            (if (eq (u16 1) (identifier "dsum1_fst_73"))
              (let-pair "dsum2_fst_179" "dsum2_snd_180" (apply (ext-identifier worker of-row-binary) (identifier "dsum1_snd_74"))
                (make-tup
                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 1
                    (identifier "dsum2_fst_179")) (identifier "dsum2_snd_180")))
              (if (eq (u16 2) (identifier "dsum1_fst_73"))
                (let-pair "dsum2_fst_176" "dsum2_snd_177" (apply (ext-identifier retention of-row-binary) (identifier "dsum1_snd_74"))
                  (make-tup
                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 2
                      (identifier "dsum2_fst_176")) (identifier "dsum2_snd_177")))
                (if (eq (u16 3) (identifier "dsum1_fst_73"))
                  (let-pair "dsum2_fst_173" "dsum2_snd_174" (apply (ext-identifier time_range of-row-binary) (identifier "dsum1_snd_74"))
                    (make-tup
                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 3
                        (identifier "dsum2_fst_173")) (identifier "dsum2_snd_174")))
                  (if (eq (u16 4) (identifier "dsum1_fst_73"))
                    (let-pair "dlist4_fst_167" "dlist4_snd_168"
                      (let "dlist1_155"
                        (let "leb_ref_146" (make-vec (u32 0))
                          (let "shft_ref_147" (make-vec (u8 0))
                            (let "p_ref_148" (make-vec (identifier "dsum1_snd_74"))
                              (seq
                                (while
                                  (let "leb128_149" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_148")))
                                    (let-pair "leb128_fst_150" "leb128_snd_151" 
                                      (identifier "leb128_149")
                                      (seq (set-vec (u8 0) (identifier "p_ref_148") (identifier "leb128_snd_151"))
                                        (set-vec (u8 0) (identifier "leb_ref_146")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_150") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_147"))) (unsafe-nth (u8 0) (identifier "leb_ref_146"))))
                                        (set-vec (u8 0) (identifier "shft_ref_147") (add (unsafe-nth (u8 0) (identifier "shft_ref_147")) (u8 7))) 
                                        (ge (identifier "leb128_fst_150") (u8 128))))) 
                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_146")) (unsafe-nth (u8 0) (identifier "p_ref_148")))))))
                        (let-pair "dlist1_fst_156" "dlist1_snd_157" (identifier "dlist1_155")
                          (let "inits_src_ref_158" (make-vec (make-tup (end-of-list "(tuple AS {skipped: U32; values: $raql_value})") (identifier "dlist1_snd_157")))
                            (seq
                              (let "repeat_n_159" (make-vec (i32 0))
                                (while (gt (to-i32 (identifier "dlist1_fst_156")) (unsafe-nth (u8 0) (identifier "repeat_n_159")))
                                  (seq
                                    (let "dlist2_160" (unsafe-nth (u8 0) (identifier "inits_src_ref_158"))
                                      (let-pair "dlist2_fst_161" "dlist2_snd_162" 
                                        (identifier "dlist2_160")
                                        (set-vec (u8 0) (identifier "inits_src_ref_158")
                                          (let-pair "dlist3_fst_164" "dlist3_snd_165" 
                                            (apply (identifier "tuple-of-row-binary") (identifier "dlist2_snd_162")) 
                                            (make-tup (cons (identifier "dlist3_fst_164") (identifier "dlist2_fst_161")) (identifier "dlist3_snd_165"))))))
                                    (set-vec (u8 0) (identifier "repeat_n_159") (add (unsafe-nth (u8 0) (identifier "repeat_n_159")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "inits_src_ref_158"))))))
                      (make-tup
                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 4
                          (arr-of-lst-rev (identifier "dlist4_fst_167"))) 
                        (identifier "dlist4_snd_168")))
                    (if (eq (u16 5) (identifier "dsum1_fst_73"))
                      (let-pair "dsum2_fst_144" "dsum2_snd_145" (apply (ext-identifier raql_value of-row-binary) (identifier "dsum1_snd_74"))
                        (make-tup
                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 5
                            (identifier "dsum2_fst_144")) (identifier "dsum2_snd_145")))
                      (if (eq (u16 6) (identifier "dsum1_fst_73"))
                        (let-pair "dlist4_fst_138" "dlist4_snd_139"
                          (let "dlist1_126"
                            (let "leb_ref_117" (make-vec (u32 0))
                              (let "shft_ref_118" (make-vec (u8 0))
                                (let "p_ref_119" (make-vec (identifier "dsum1_snd_74"))
                                  (seq
                                    (while
                                      (let "leb128_120" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_119")))
                                        (let-pair "leb128_fst_121" "leb128_snd_122" 
                                          (identifier "leb128_120")
                                          (seq (set-vec (u8 0) (identifier "p_ref_119") (identifier "leb128_snd_122"))
                                            (set-vec (u8 0) (identifier "leb_ref_117")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_121") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_118"))) (unsafe-nth (u8 0) (identifier "leb_ref_117"))))
                                            (set-vec (u8 0) (identifier "shft_ref_118") (add (unsafe-nth (u8 0) (identifier "shft_ref_118")) (u8 7))) 
                                            (ge (identifier "leb128_fst_121") (u8 128))))) 
                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_117")) (unsafe-nth (u8 0) (identifier "p_ref_119")))))))
                            (let-pair "dlist1_fst_127" "dlist1_snd_128" 
                              (identifier "dlist1_126")
                              (let "inits_src_ref_129" (make-vec (make-tup (end-of-list "$rc_entry") (identifier "dlist1_snd_128")))
                                (seq
                                  (let "repeat_n_130" (make-vec (i32 0))
                                    (while (gt (to-i32 (identifier "dlist1_fst_127")) (unsafe-nth (u8 0) (identifier "repeat_n_130")))
                                      (seq
                                        (let "dlist2_131" (unsafe-nth (u8 0) (identifier "inits_src_ref_129"))
                                          (let-pair "dlist2_fst_132" "dlist2_snd_133" 
                                            (identifier "dlist2_131")
                                            (set-vec (u8 0) (identifier "inits_src_ref_129")
                                              (let-pair "dlist3_fst_135" "dlist3_snd_136" 
                                                (apply (ext-identifier rc_entry of-row-binary) (identifier "dlist2_snd_133"))
                                                (make-tup (cons (identifier "dlist3_fst_135") (identifier "dlist2_fst_132")) (identifier "dlist3_snd_136"))))))
                                        (set-vec (u8 0) (identifier "repeat_n_130") (add (unsafe-nth (u8 0) (identifier "repeat_n_130")) (i32 1)))))) 
                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_129"))))))
                          (make-tup
                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 6
                              (arr-of-lst-rev (identifier "dlist4_fst_138"))) 
                            (identifier "dlist4_snd_139")))
                        (if (eq (u16 7) (identifier "dsum1_fst_73"))
                          (let-pair "dsum2_fst_115" "dsum2_snd_116" (apply (ext-identifier source_info of-row-binary) (identifier "dsum1_snd_74"))
                            (make-tup
                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 7
                                (identifier "dsum2_fst_115")) (identifier "dsum2_snd_116")))
                          (if (eq (u16 8) (identifier "dsum1_fst_73"))
                            (let-pair "dsum2_fst_112" "dsum2_snd_113" 
                              (apply (ext-identifier runtime_stats of-row-binary) (identifier "dsum1_snd_74"))
                              (make-tup
                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 8
                                  (identifier "dsum2_fst_112")) (identifier "dsum2_snd_113")))
                            (if (eq (u16 9) (identifier "dsum1_fst_73"))
                              (let-pair "dsum2_fst_109" "dsum2_snd_110" 
                                (apply (ext-identifier replay of-row-binary) (identifier "dsum1_snd_74"))
                                (make-tup
                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 9
                                    (identifier "dsum2_fst_109")) (identifier "dsum2_snd_110")))
                              (if (eq (u16 10) (identifier "dsum1_fst_73"))
                                (let-pair "dsum2_fst_106" "dsum2_snd_107" 
                                  (apply (ext-identifier replayer of-row-binary) (identifier "dsum1_snd_74"))
                                  (make-tup
                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 10
                                      (identifier "dsum2_fst_106")) (identifier "dsum2_snd_107")))
                                (if (eq (u16 11) (identifier "dsum1_fst_73"))
                                  (let-pair "dsum2_fst_103" "dsum2_snd_104" 
                                    (apply (ext-identifier replay_request of-row-binary) (identifier "dsum1_snd_74"))
                                    (make-tup
                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 11
                                        (identifier "dsum2_fst_103")) 
                                      (identifier "dsum2_snd_104")))
                                  (if (eq (u16 12) (identifier "dsum1_fst_73"))
                                    (let-pair "dsum2_fst_100" "dsum2_snd_101" 
                                      (apply (ext-identifier alert of-row-binary) (identifier "dsum1_snd_74"))
                                      (make-tup
                                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 12
                                          (identifier "dsum2_fst_100")) 
                                        (identifier "dsum2_snd_101")))
                                    (if (eq (u16 13) (identifier "dsum1_fst_73"))
                                      (let-pair "dsum2_fst_97" "dsum2_snd_98" 
                                        (apply (ext-identifier pivot of-row-binary) (identifier "dsum1_snd_74"))
                                        (make-tup
                                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 13
                                            (identifier "dsum2_fst_97")) 
                                          (identifier "dsum2_snd_98")))
                                      (if (eq (u16 14) (identifier "dsum1_fst_73"))
                                        (let-pair "dsum2_fst_94" "dsum2_snd_95" 
                                          (apply (ext-identifier output_specs of-row-binary) (identifier "dsum1_snd_74"))
                                          (make-tup
                                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 14
                                              (identifier "dsum2_fst_94")) 
                                            (identifier "dsum2_snd_95")))
                                        (if (eq (u16 15) (identifier "dsum1_fst_73"))
                                          (let-pair "dsum2_fst_91" "dsum2_snd_92" 
                                            (apply (ext-identifier dashboard_widget of-row-binary) (identifier "dsum1_snd_74"))
                                            (make-tup
                                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 15
                                                (identifier "dsum2_fst_91")) 
                                              (identifier "dsum2_snd_92")))
                                          (if (eq (u16 16) (identifier "dsum1_fst_73"))
                                            (let-pair "dsum2_fst_88" "dsum2_snd_89" 
                                              (apply (ext-identifier alerting_contact of-row-binary) (identifier "dsum1_snd_74"))
                                              (make-tup
                                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 16
                                                  (identifier "dsum2_fst_88")) 
                                                (identifier "dsum2_snd_89")))
                                            (if (eq (u16 17) (identifier "dsum1_fst_73"))
                                              (let-pair "dsum2_fst_85" "dsum2_snd_86" 
                                                (apply (ext-identifier alerting_notification of-row-binary) (identifier "dsum1_snd_74"))
                                                (make-tup
                                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 17
                                                    (identifier "dsum2_fst_85")) 
                                                  (identifier "dsum2_snd_86")))
                                              (if (eq (u16 18) (identifier "dsum1_fst_73"))
                                                (let-pair "dsum2_fst_82" "dsum2_snd_83" 
                                                  (apply (ext-identifier alerting_delivery_status of-row-binary) (identifier "dsum1_snd_74"))
                                                  (make-tup
                                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 18
                                                      (identifier "dsum2_fst_82")) 
                                                    (identifier "dsum2_snd_83")))
                                                (if (eq (u16 19) (identifier "dsum1_fst_73"))
                                                  (let-pair "dsum2_fst_79" "dsum2_snd_80" 
                                                    (apply (ext-identifier alerting_log of-row-binary) (identifier "dsum1_snd_74"))
                                                    (make-tup
                                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 19
                                                        (identifier "dsum2_fst_79")) 
                                                      (identifier "dsum2_snd_80")))
                                                  (seq (assert (eq (identifier "dsum1_fst_73") (u16 20)))
                                                    (let-pair "dsum2_fst_76" "dsum2_snd_77" 
                                                      (apply (ext-identifier alerting_inhibition of-row-binary) (identifier "dsum1_snd_74"))
                                                      (make-tup
                                                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 20
                                                          (identifier "dsum2_fst_76")) 
                                                        (identifier "dsum2_snd_77")))))))))))))))))))))))))))
 */
static std::function<::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79(Pointer &)> fun609 { [&](Pointer p_0) {
    ::dessser::gen::sync_value::ta97bb48ed75bbda6173555873826c8c6 id_610 { p_0.readU16Le() };
    ::dessser::gen::sync_value::ta97bb48ed75bbda6173555873826c8c6 letpair_res_611;
    {
      auto du16_fst_67 { std::get<0>(id_610) };
      auto du16_snd_68 { std::get<1>(id_610) };
      ::dessser::gen::sync_value::ta97bb48ed75bbda6173555873826c8c6 id_612 { du16_fst_67, du16_snd_68 };
      letpair_res_611 = id_612;
    }
    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 let_res_613;
    {
      ::dessser::gen::sync_value::ta97bb48ed75bbda6173555873826c8c6 dsum1_72 { letpair_res_611 };
      ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_614;
      {
        auto dsum1_fst_73 { std::get<0>(dsum1_72) };
        auto dsum1_snd_74 { std::get<1>(dsum1_72) };
        uint16_t id_615 { 0 };
        bool id_616 { bool(id_615 == dsum1_fst_73) };
        ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_617;
        if (id_616) {
          ::dessser::gen::sync_value::td2cd337bb3c8bc04d5603393d084985b id_618 { dsum1_snd_74.readU64Le() };
          ::dessser::gen::sync_value::t9a758baeff17224a77e1a522010b4168 letpair_res_619;
          {
            auto dfloat_fst_182 { std::get<0>(id_618) };
            auto dfloat_snd_183 { std::get<1>(id_618) };
            double id_620 { float_of_qword(dfloat_fst_182) };
            ::dessser::gen::sync_value::t9a758baeff17224a77e1a522010b4168 id_621 { id_620, dfloat_snd_183 };
            letpair_res_619 = id_621;
          }
          ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 let_res_622;
          {
            ::dessser::gen::sync_value::t9a758baeff17224a77e1a522010b4168 dtup_184 { letpair_res_619 };
            ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_623;
            {
              auto dtup_fst_185 { std::get<0>(dtup_184) };
              auto dtup_snd_186 { std::get<1>(dtup_184) };
              ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_624 { dtup_snd_186.readU32Le() };
              ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 letpair_res_625;
              {
                auto du32_fst_188 { std::get<0>(id_624) };
                auto du32_snd_189 { std::get<1>(id_624) };
                ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_626 { du32_fst_188, du32_snd_189 };
                letpair_res_625 = id_626;
              }
              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 let_res_627;
              {
                ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 dtup_190 { letpair_res_625 };
                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_628;
                {
                  auto dtup_fst_191 { std::get<0>(dtup_190) };
                  auto dtup_snd_192 { std::get<1>(dtup_190) };
                  uint32_t id_629 { 0U };
                  Vec<1, uint32_t> id_630 {  id_629  };
                  ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa let_res_631;
                  {
                    Vec<1, uint32_t> leb_ref_193 { id_630 };
                    uint8_t id_632 { 0 };
                    Vec<1, uint8_t> id_633 {  id_632  };
                    ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa let_res_634;
                    {
                      Vec<1, uint8_t> shft_ref_194 { id_633 };
                      Vec<1, Pointer> id_635 {  dtup_snd_192  };
                      ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa let_res_636;
                      {
                        Vec<1, Pointer> p_ref_195 { id_635 };
                        bool while_flag_637 { true };
                        do {
                          uint8_t id_638 { 0 };
                          Pointer id_639 { p_ref_195[id_638] };
                          ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 id_640 { id_639.readU8() };
                          bool let_res_641;
                          {
                            ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_196 { id_640 };
                            bool letpair_res_642;
                            {
                              auto leb128_fst_197 { std::get<0>(leb128_196) };
                              auto leb128_snd_198 { std::get<1>(leb128_196) };
                              uint8_t id_643 { 0 };
                              Void id_644 { ((void)(p_ref_195[id_643] = leb128_snd_198), ::dessser::Void()) };
                              (void)id_644;
                              uint8_t id_645 { 0 };
                              uint8_t id_646 { 127 };
                              uint8_t id_647 { uint8_t(leb128_fst_197 & id_646) };
                              uint32_t id_648 { uint32_t(id_647) };
                              uint8_t id_649 { 0 };
                              uint8_t id_650 { shft_ref_194[id_649] };
                              uint32_t id_651 { uint32_t(id_648 << id_650) };
                              uint8_t id_652 { 0 };
                              uint32_t id_653 { leb_ref_193[id_652] };
                              uint32_t id_654 { uint32_t(id_651 | id_653) };
                              Void id_655 { ((void)(leb_ref_193[id_645] = id_654), ::dessser::Void()) };
                              (void)id_655;
                              uint8_t id_656 { 0 };
                              uint8_t id_657 { 0 };
                              uint8_t id_658 { shft_ref_194[id_657] };
                              uint8_t id_659 { 7 };
                              uint8_t id_660 { uint8_t(id_658 + id_659) };
                              Void id_661 { ((void)(shft_ref_194[id_656] = id_660), ::dessser::Void()) };
                              (void)id_661;
                              uint8_t id_662 { 128 };
                              bool id_663 { bool(leb128_fst_197 >= id_662) };
                              letpair_res_642 = id_663;
                            }
                            let_res_641 = letpair_res_642;
                          }
                          while_flag_637 = let_res_641;
                          if (while_flag_637) {
                            (void)::dessser::Void();
                          }
                        } while (while_flag_637);
                        (void)::dessser::Void();
                        uint8_t id_664 { 0 };
                        uint32_t id_665 { leb_ref_193[id_664] };
                        Size id_666 { Size(id_665) };
                        uint8_t id_667 { 0 };
                        Pointer id_668 { p_ref_195[id_667] };
                        ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa id_669 { id_666, id_668 };
                        let_res_636 = id_669;
                      }
                      let_res_634 = let_res_636;
                    }
                    let_res_631 = let_res_634;
                  }
                  ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 let_res_670;
                  {
                    ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa dstring1_199 { let_res_631 };
                    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_671;
                    {
                      auto dstring1_fst_200 { std::get<0>(dstring1_199) };
                      auto dstring1_snd_201 { std::get<1>(dstring1_199) };
                      ::dessser::gen::sync_value::t9ef6882174ae71a34a3c5ef6b29242fb id_672 { dstring1_snd_201.readBytes(dstring1_fst_200) };
                      ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_673;
                      {
                        auto dstring2_fst_203 { std::get<0>(id_672) };
                        auto dstring2_snd_204 { std::get<1>(id_672) };
                        std::string id_674 { dstring2_fst_203.toString() };
                        ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_675 { dtup_fst_185, dtup_fst_191, id_674 };
                        ::dessser::gen::sync_value::t id_676 { std::in_place_index<0>, id_675 };
                        ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_677 { id_676, dstring2_snd_204 };
                        letpair_res_673 = id_677;
                      }
                      letpair_res_671 = letpair_res_673;
                    }
                    let_res_670 = letpair_res_671;
                  }
                  letpair_res_628 = let_res_670;
                }
                let_res_627 = letpair_res_628;
              }
              letpair_res_623 = let_res_627;
            }
            let_res_622 = letpair_res_623;
          }
          choose_res_617 = let_res_622;
        } else {
          uint16_t id_678 { 1 };
          bool id_679 { bool(id_678 == dsum1_fst_73) };
          ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_680;
          if (id_679) {
            auto fun681 { dessser::gen::worker::of_row_binary };
            ::dessser::gen::sync_value::tf1a9e54f73426165b2d5dbb064eb3fed id_682 { fun681(dsum1_snd_74) };
            ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_683;
            {
              auto dsum2_fst_179 { std::get<0>(id_682) };
              auto dsum2_snd_180 { std::get<1>(id_682) };
              ::dessser::gen::sync_value::t id_684 { std::in_place_index<1>, dsum2_fst_179 };
              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_685 { id_684, dsum2_snd_180 };
              letpair_res_683 = id_685;
            }
            choose_res_680 = letpair_res_683;
          } else {
            uint16_t id_686 { 2 };
            bool id_687 { bool(id_686 == dsum1_fst_73) };
            ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_688;
            if (id_687) {
              auto fun689 { dessser::gen::retention::of_row_binary };
              ::dessser::gen::sync_value::tde821e6d031c399b029ea4a78810ecf6 id_690 { fun689(dsum1_snd_74) };
              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_691;
              {
                auto dsum2_fst_176 { std::get<0>(id_690) };
                auto dsum2_snd_177 { std::get<1>(id_690) };
                ::dessser::gen::sync_value::t id_692 { std::in_place_index<2>, dsum2_fst_176 };
                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_693 { id_692, dsum2_snd_177 };
                letpair_res_691 = id_693;
              }
              choose_res_688 = letpair_res_691;
            } else {
              uint16_t id_694 { 3 };
              bool id_695 { bool(id_694 == dsum1_fst_73) };
              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_696;
              if (id_695) {
                auto fun697 { dessser::gen::time_range::of_row_binary };
                ::dessser::gen::sync_value::t7ed2098d1a18c9b684db63350a7b96cb id_698 { fun697(dsum1_snd_74) };
                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_699;
                {
                  auto dsum2_fst_173 { std::get<0>(id_698) };
                  auto dsum2_snd_174 { std::get<1>(id_698) };
                  ::dessser::gen::sync_value::t id_700 { std::in_place_index<3>, dsum2_fst_173 };
                  ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_701 { id_700, dsum2_snd_174 };
                  letpair_res_699 = id_701;
                }
                choose_res_696 = letpair_res_699;
              } else {
                uint16_t id_702 { 4 };
                bool id_703 { bool(id_702 == dsum1_fst_73) };
                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_704;
                if (id_703) {
                  uint32_t id_705 { 0U };
                  Vec<1, uint32_t> id_706 {  id_705  };
                  ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_707;
                  {
                    Vec<1, uint32_t> leb_ref_146 { id_706 };
                    uint8_t id_708 { 0 };
                    Vec<1, uint8_t> id_709 {  id_708  };
                    ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_710;
                    {
                      Vec<1, uint8_t> shft_ref_147 { id_709 };
                      Vec<1, Pointer> id_711 {  dsum1_snd_74  };
                      ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_712;
                      {
                        Vec<1, Pointer> p_ref_148 { id_711 };
                        bool while_flag_713 { true };
                        do {
                          uint8_t id_714 { 0 };
                          Pointer id_715 { p_ref_148[id_714] };
                          ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 id_716 { id_715.readU8() };
                          bool let_res_717;
                          {
                            ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_149 { id_716 };
                            bool letpair_res_718;
                            {
                              auto leb128_fst_150 { std::get<0>(leb128_149) };
                              auto leb128_snd_151 { std::get<1>(leb128_149) };
                              uint8_t id_719 { 0 };
                              Void id_720 { ((void)(p_ref_148[id_719] = leb128_snd_151), ::dessser::Void()) };
                              (void)id_720;
                              uint8_t id_721 { 0 };
                              uint8_t id_722 { 127 };
                              uint8_t id_723 { uint8_t(leb128_fst_150 & id_722) };
                              uint32_t id_724 { uint32_t(id_723) };
                              uint8_t id_725 { 0 };
                              uint8_t id_726 { shft_ref_147[id_725] };
                              uint32_t id_727 { uint32_t(id_724 << id_726) };
                              uint8_t id_728 { 0 };
                              uint32_t id_729 { leb_ref_146[id_728] };
                              uint32_t id_730 { uint32_t(id_727 | id_729) };
                              Void id_731 { ((void)(leb_ref_146[id_721] = id_730), ::dessser::Void()) };
                              (void)id_731;
                              uint8_t id_732 { 0 };
                              uint8_t id_733 { 0 };
                              uint8_t id_734 { shft_ref_147[id_733] };
                              uint8_t id_735 { 7 };
                              uint8_t id_736 { uint8_t(id_734 + id_735) };
                              Void id_737 { ((void)(shft_ref_147[id_732] = id_736), ::dessser::Void()) };
                              (void)id_737;
                              uint8_t id_738 { 128 };
                              bool id_739 { bool(leb128_fst_150 >= id_738) };
                              letpair_res_718 = id_739;
                            }
                            let_res_717 = letpair_res_718;
                          }
                          while_flag_713 = let_res_717;
                          if (while_flag_713) {
                            (void)::dessser::Void();
                          }
                        } while (while_flag_713);
                        (void)::dessser::Void();
                        uint8_t id_740 { 0 };
                        uint32_t id_741 { leb_ref_146[id_740] };
                        uint8_t id_742 { 0 };
                        Pointer id_743 { p_ref_148[id_742] };
                        ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_744 { id_741, id_743 };
                        let_res_712 = id_744;
                      }
                      let_res_710 = let_res_712;
                    }
                    let_res_707 = let_res_710;
                  }
                  ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516 let_res_745;
                  {
                    ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 dlist1_155 { let_res_707 };
                    ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516 letpair_res_746;
                    {
                      auto dlist1_fst_156 { std::get<0>(dlist1_155) };
                      auto dlist1_snd_157 { std::get<1>(dlist1_155) };
                      Lst<::dessser::gen::sync_value::tuple> endoflist_747;
                      ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516 id_748 { endoflist_747, dlist1_snd_157 };
                      Vec<1, ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516> id_749 {  id_748  };
                      ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516 let_res_750;
                      {
                        Vec<1, ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516> inits_src_ref_158 { id_749 };
                        int32_t id_751 { 0L };
                        Vec<1, int32_t> id_752 {  id_751  };
                        {
                          Vec<1, int32_t> repeat_n_159 { id_752 };
                          bool while_flag_753 { true };
                          do {
                            int32_t id_754 { int32_t(dlist1_fst_156) };
                            uint8_t id_755 { 0 };
                            int32_t id_756 { repeat_n_159[id_755] };
                            bool id_757 { bool(id_754 > id_756) };
                            while_flag_753 = id_757;
                            if (while_flag_753) {
                              uint8_t id_758 { 0 };
                              ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516 id_759 { inits_src_ref_158[id_758] };
                              {
                                ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516 dlist2_160 { id_759 };
                                {
                                  auto dlist2_fst_161 { std::get<0>(dlist2_160) };
                                  auto dlist2_snd_162 { std::get<1>(dlist2_160) };
                                  uint8_t id_760 { 0 };
                                  ::dessser::gen::sync_value::tc689a7a5ea052f6c0e885d3374325d5b id_761 { tuple_of_row_binary(dlist2_snd_162) };
                                  ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516 letpair_res_762;
                                  {
                                    auto dlist3_fst_164 { std::get<0>(id_761) };
                                    auto dlist3_snd_165 { std::get<1>(id_761) };
                                    Lst<::dessser::gen::sync_value::tuple> id_763 { dlist3_fst_164, dlist2_fst_161 };
                                    ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516 id_764 { id_763, dlist3_snd_165 };
                                    letpair_res_762 = id_764;
                                  }
                                  Void id_765 { ((void)(inits_src_ref_158[id_760] = letpair_res_762), ::dessser::Void()) };
                                  (void)id_765;
                                }
                                (void)::dessser::Void();
                              }
                              (void)::dessser::Void();
                              uint8_t id_766 { 0 };
                              uint8_t id_767 { 0 };
                              int32_t id_768 { repeat_n_159[id_767] };
                              int32_t id_769 { 1L };
                              int32_t id_770 { int32_t(id_768 + id_769) };
                              Void id_771 { ((void)(repeat_n_159[id_766] = id_770), ::dessser::Void()) };
                              (void)id_771;
                              (void)id_771;
                            }
                          } while (while_flag_753);
                          (void)::dessser::Void();
                        }
                        (void)::dessser::Void();
                        uint8_t id_772 { 0 };
                        ::dessser::gen::sync_value::tfce5b5f196eaf1540bed56507f219516 id_773 { inits_src_ref_158[id_772] };
                        let_res_750 = id_773;
                      }
                      letpair_res_746 = let_res_750;
                    }
                    let_res_745 = letpair_res_746;
                  }
                  ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_774;
                  {
                    auto dlist4_fst_167 { std::get<0>(let_res_745) };
                    auto dlist4_snd_168 { std::get<1>(let_res_745) };
                    Arr<::dessser::gen::sync_value::tuple> id_775 { dlist4_fst_167.toArrRev() };
                    ::dessser::gen::sync_value::t id_776 { std::in_place_index<4>, id_775 };
                    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_777 { id_776, dlist4_snd_168 };
                    letpair_res_774 = id_777;
                  }
                  choose_res_704 = letpair_res_774;
                } else {
                  uint16_t id_778 { 5 };
                  bool id_779 { bool(id_778 == dsum1_fst_73) };
                  ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_780;
                  if (id_779) {
                    auto fun781 { dessser::gen::raql_value::of_row_binary };
                    ::dessser::gen::sync_value::tf3063cfb73e0f06d3ea99ebd15a86d50 id_782 { fun781(dsum1_snd_74) };
                    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_783;
                    {
                      auto dsum2_fst_144 { std::get<0>(id_782) };
                      auto dsum2_snd_145 { std::get<1>(id_782) };
                      ::dessser::gen::sync_value::t id_784 { std::in_place_index<5>, dsum2_fst_144 };
                      ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_785 { id_784, dsum2_snd_145 };
                      letpair_res_783 = id_785;
                    }
                    choose_res_780 = letpair_res_783;
                  } else {
                    uint16_t id_786 { 6 };
                    bool id_787 { bool(id_786 == dsum1_fst_73) };
                    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_788;
                    if (id_787) {
                      uint32_t id_789 { 0U };
                      Vec<1, uint32_t> id_790 {  id_789  };
                      ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_791;
                      {
                        Vec<1, uint32_t> leb_ref_117 { id_790 };
                        uint8_t id_792 { 0 };
                        Vec<1, uint8_t> id_793 {  id_792  };
                        ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_794;
                        {
                          Vec<1, uint8_t> shft_ref_118 { id_793 };
                          Vec<1, Pointer> id_795 {  dsum1_snd_74  };
                          ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_796;
                          {
                            Vec<1, Pointer> p_ref_119 { id_795 };
                            bool while_flag_797 { true };
                            do {
                              uint8_t id_798 { 0 };
                              Pointer id_799 { p_ref_119[id_798] };
                              ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 id_800 { id_799.readU8() };
                              bool let_res_801;
                              {
                                ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_120 { id_800 };
                                bool letpair_res_802;
                                {
                                  auto leb128_fst_121 { std::get<0>(leb128_120) };
                                  auto leb128_snd_122 { std::get<1>(leb128_120) };
                                  uint8_t id_803 { 0 };
                                  Void id_804 { ((void)(p_ref_119[id_803] = leb128_snd_122), ::dessser::Void()) };
                                  (void)id_804;
                                  uint8_t id_805 { 0 };
                                  uint8_t id_806 { 127 };
                                  uint8_t id_807 { uint8_t(leb128_fst_121 & id_806) };
                                  uint32_t id_808 { uint32_t(id_807) };
                                  uint8_t id_809 { 0 };
                                  uint8_t id_810 { shft_ref_118[id_809] };
                                  uint32_t id_811 { uint32_t(id_808 << id_810) };
                                  uint8_t id_812 { 0 };
                                  uint32_t id_813 { leb_ref_117[id_812] };
                                  uint32_t id_814 { uint32_t(id_811 | id_813) };
                                  Void id_815 { ((void)(leb_ref_117[id_805] = id_814), ::dessser::Void()) };
                                  (void)id_815;
                                  uint8_t id_816 { 0 };
                                  uint8_t id_817 { 0 };
                                  uint8_t id_818 { shft_ref_118[id_817] };
                                  uint8_t id_819 { 7 };
                                  uint8_t id_820 { uint8_t(id_818 + id_819) };
                                  Void id_821 { ((void)(shft_ref_118[id_816] = id_820), ::dessser::Void()) };
                                  (void)id_821;
                                  uint8_t id_822 { 128 };
                                  bool id_823 { bool(leb128_fst_121 >= id_822) };
                                  letpair_res_802 = id_823;
                                }
                                let_res_801 = letpair_res_802;
                              }
                              while_flag_797 = let_res_801;
                              if (while_flag_797) {
                                (void)::dessser::Void();
                              }
                            } while (while_flag_797);
                            (void)::dessser::Void();
                            uint8_t id_824 { 0 };
                            uint32_t id_825 { leb_ref_117[id_824] };
                            uint8_t id_826 { 0 };
                            Pointer id_827 { p_ref_119[id_826] };
                            ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_828 { id_825, id_827 };
                            let_res_796 = id_828;
                          }
                          let_res_794 = let_res_796;
                        }
                        let_res_791 = let_res_794;
                      }
                      ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 let_res_829;
                      {
                        ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 dlist1_126 { let_res_791 };
                        ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 letpair_res_830;
                        {
                          auto dlist1_fst_127 { std::get<0>(dlist1_126) };
                          auto dlist1_snd_128 { std::get<1>(dlist1_126) };
                          Lst<dessser::gen::rc_entry::t_ext> endoflist_831;
                          ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 id_832 { endoflist_831, dlist1_snd_128 };
                          Vec<1, ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9> id_833 {  id_832  };
                          ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 let_res_834;
                          {
                            Vec<1, ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9> inits_src_ref_129 { id_833 };
                            int32_t id_835 { 0L };
                            Vec<1, int32_t> id_836 {  id_835  };
                            {
                              Vec<1, int32_t> repeat_n_130 { id_836 };
                              bool while_flag_837 { true };
                              do {
                                int32_t id_838 { int32_t(dlist1_fst_127) };
                                uint8_t id_839 { 0 };
                                int32_t id_840 { repeat_n_130[id_839] };
                                bool id_841 { bool(id_838 > id_840) };
                                while_flag_837 = id_841;
                                if (while_flag_837) {
                                  uint8_t id_842 { 0 };
                                  ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 id_843 { inits_src_ref_129[id_842] };
                                  {
                                    ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 dlist2_131 { id_843 };
                                    {
                                      auto dlist2_fst_132 { std::get<0>(dlist2_131) };
                                      auto dlist2_snd_133 { std::get<1>(dlist2_131) };
                                      uint8_t id_844 { 0 };
                                      auto fun845 { dessser::gen::rc_entry::of_row_binary };
                                      ::dessser::gen::sync_value::t47e3362e539b61ad5bc0fe6744e49d62 id_846 { fun845(dlist2_snd_133) };
                                      ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 letpair_res_847;
                                      {
                                        auto dlist3_fst_135 { std::get<0>(id_846) };
                                        auto dlist3_snd_136 { std::get<1>(id_846) };
                                        Lst<dessser::gen::rc_entry::t_ext> id_848 { dlist3_fst_135, dlist2_fst_132 };
                                        ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 id_849 { id_848, dlist3_snd_136 };
                                        letpair_res_847 = id_849;
                                      }
                                      Void id_850 { ((void)(inits_src_ref_129[id_844] = letpair_res_847), ::dessser::Void()) };
                                      (void)id_850;
                                    }
                                    (void)::dessser::Void();
                                  }
                                  (void)::dessser::Void();
                                  uint8_t id_851 { 0 };
                                  uint8_t id_852 { 0 };
                                  int32_t id_853 { repeat_n_130[id_852] };
                                  int32_t id_854 { 1L };
                                  int32_t id_855 { int32_t(id_853 + id_854) };
                                  Void id_856 { ((void)(repeat_n_130[id_851] = id_855), ::dessser::Void()) };
                                  (void)id_856;
                                  (void)id_856;
                                }
                              } while (while_flag_837);
                              (void)::dessser::Void();
                            }
                            (void)::dessser::Void();
                            uint8_t id_857 { 0 };
                            ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 id_858 { inits_src_ref_129[id_857] };
                            let_res_834 = id_858;
                          }
                          letpair_res_830 = let_res_834;
                        }
                        let_res_829 = letpair_res_830;
                      }
                      ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_859;
                      {
                        auto dlist4_fst_138 { std::get<0>(let_res_829) };
                        auto dlist4_snd_139 { std::get<1>(let_res_829) };
                        Arr<dessser::gen::rc_entry::t_ext> id_860 { dlist4_fst_138.toArrRev() };
                        ::dessser::gen::sync_value::t id_861 { std::in_place_index<6>, id_860 };
                        ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_862 { id_861, dlist4_snd_139 };
                        letpair_res_859 = id_862;
                      }
                      choose_res_788 = letpair_res_859;
                    } else {
                      uint16_t id_863 { 7 };
                      bool id_864 { bool(id_863 == dsum1_fst_73) };
                      ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_865;
                      if (id_864) {
                        auto fun866 { dessser::gen::source_info::of_row_binary };
                        ::dessser::gen::sync_value::tf1b07204c9c2214dfaf5f174f6300e9a id_867 { fun866(dsum1_snd_74) };
                        ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_868;
                        {
                          auto dsum2_fst_115 { std::get<0>(id_867) };
                          auto dsum2_snd_116 { std::get<1>(id_867) };
                          ::dessser::gen::sync_value::t id_869 { std::in_place_index<7>, dsum2_fst_115 };
                          ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_870 { id_869, dsum2_snd_116 };
                          letpair_res_868 = id_870;
                        }
                        choose_res_865 = letpair_res_868;
                      } else {
                        uint16_t id_871 { 8 };
                        bool id_872 { bool(id_871 == dsum1_fst_73) };
                        ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_873;
                        if (id_872) {
                          auto fun874 { dessser::gen::runtime_stats::of_row_binary };
                          ::dessser::gen::sync_value::t0404418c5456e6c318afcd8cf14b75c1 id_875 { fun874(dsum1_snd_74) };
                          ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_876;
                          {
                            auto dsum2_fst_112 { std::get<0>(id_875) };
                            auto dsum2_snd_113 { std::get<1>(id_875) };
                            ::dessser::gen::sync_value::t id_877 { std::in_place_index<8>, dsum2_fst_112 };
                            ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_878 { id_877, dsum2_snd_113 };
                            letpair_res_876 = id_878;
                          }
                          choose_res_873 = letpair_res_876;
                        } else {
                          uint16_t id_879 { 9 };
                          bool id_880 { bool(id_879 == dsum1_fst_73) };
                          ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_881;
                          if (id_880) {
                            auto fun882 { dessser::gen::replay::of_row_binary };
                            ::dessser::gen::sync_value::t4f69e417cce4a8fd9a6492bd06fc9968 id_883 { fun882(dsum1_snd_74) };
                            ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_884;
                            {
                              auto dsum2_fst_109 { std::get<0>(id_883) };
                              auto dsum2_snd_110 { std::get<1>(id_883) };
                              ::dessser::gen::sync_value::t id_885 { std::in_place_index<9>, dsum2_fst_109 };
                              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_886 { id_885, dsum2_snd_110 };
                              letpair_res_884 = id_886;
                            }
                            choose_res_881 = letpair_res_884;
                          } else {
                            uint16_t id_887 { 10 };
                            bool id_888 { bool(id_887 == dsum1_fst_73) };
                            ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_889;
                            if (id_888) {
                              auto fun890 { dessser::gen::replayer::of_row_binary };
                              ::dessser::gen::sync_value::t0d3332e65eb58017bd9ce92925526fe1 id_891 { fun890(dsum1_snd_74) };
                              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_892;
                              {
                                auto dsum2_fst_106 { std::get<0>(id_891) };
                                auto dsum2_snd_107 { std::get<1>(id_891) };
                                ::dessser::gen::sync_value::t id_893 { std::in_place_index<10>, dsum2_fst_106 };
                                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_894 { id_893, dsum2_snd_107 };
                                letpair_res_892 = id_894;
                              }
                              choose_res_889 = letpair_res_892;
                            } else {
                              uint16_t id_895 { 11 };
                              bool id_896 { bool(id_895 == dsum1_fst_73) };
                              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_897;
                              if (id_896) {
                                auto fun898 { dessser::gen::replay_request::of_row_binary };
                                ::dessser::gen::sync_value::tb04e7483a47551f3c586f859338754a3 id_899 { fun898(dsum1_snd_74) };
                                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_900;
                                {
                                  auto dsum2_fst_103 { std::get<0>(id_899) };
                                  auto dsum2_snd_104 { std::get<1>(id_899) };
                                  ::dessser::gen::sync_value::t id_901 { std::in_place_index<11>, dsum2_fst_103 };
                                  ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_902 { id_901, dsum2_snd_104 };
                                  letpair_res_900 = id_902;
                                }
                                choose_res_897 = letpair_res_900;
                              } else {
                                uint16_t id_903 { 12 };
                                bool id_904 { bool(id_903 == dsum1_fst_73) };
                                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_905;
                                if (id_904) {
                                  auto fun906 { dessser::gen::alert::of_row_binary };
                                  ::dessser::gen::sync_value::t444e608a3269594da3e48ff9117a0d03 id_907 { fun906(dsum1_snd_74) };
                                  ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_908;
                                  {
                                    auto dsum2_fst_100 { std::get<0>(id_907) };
                                    auto dsum2_snd_101 { std::get<1>(id_907) };
                                    ::dessser::gen::sync_value::t id_909 { std::in_place_index<12>, dsum2_fst_100 };
                                    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_910 { id_909, dsum2_snd_101 };
                                    letpair_res_908 = id_910;
                                  }
                                  choose_res_905 = letpair_res_908;
                                } else {
                                  uint16_t id_911 { 13 };
                                  bool id_912 { bool(id_911 == dsum1_fst_73) };
                                  ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_913;
                                  if (id_912) {
                                    auto fun914 { dessser::gen::pivot::of_row_binary };
                                    ::dessser::gen::sync_value::t2a03b8ab7cecf56205c765b69d16f216 id_915 { fun914(dsum1_snd_74) };
                                    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_916;
                                    {
                                      auto dsum2_fst_97 { std::get<0>(id_915) };
                                      auto dsum2_snd_98 { std::get<1>(id_915) };
                                      ::dessser::gen::sync_value::t id_917 { std::in_place_index<13>, dsum2_fst_97 };
                                      ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_918 { id_917, dsum2_snd_98 };
                                      letpair_res_916 = id_918;
                                    }
                                    choose_res_913 = letpair_res_916;
                                  } else {
                                    uint16_t id_919 { 14 };
                                    bool id_920 { bool(id_919 == dsum1_fst_73) };
                                    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_921;
                                    if (id_920) {
                                      auto fun922 { dessser::gen::output_specs::of_row_binary };
                                      ::dessser::gen::sync_value::tf66ee8ddea68e7658659620791429c2e id_923 { fun922(dsum1_snd_74) };
                                      ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_924;
                                      {
                                        auto dsum2_fst_94 { std::get<0>(id_923) };
                                        auto dsum2_snd_95 { std::get<1>(id_923) };
                                        ::dessser::gen::sync_value::t id_925 { std::in_place_index<14>, dsum2_fst_94 };
                                        ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_926 { id_925, dsum2_snd_95 };
                                        letpair_res_924 = id_926;
                                      }
                                      choose_res_921 = letpair_res_924;
                                    } else {
                                      uint16_t id_927 { 15 };
                                      bool id_928 { bool(id_927 == dsum1_fst_73) };
                                      ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_929;
                                      if (id_928) {
                                        auto fun930 { dessser::gen::dashboard_widget::of_row_binary };
                                        ::dessser::gen::sync_value::t7b3e7c64daee99819044254f252b16cd id_931 { fun930(dsum1_snd_74) };
                                        ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_932;
                                        {
                                          auto dsum2_fst_91 { std::get<0>(id_931) };
                                          auto dsum2_snd_92 { std::get<1>(id_931) };
                                          ::dessser::gen::sync_value::t id_933 { std::in_place_index<15>, dsum2_fst_91 };
                                          ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_934 { id_933, dsum2_snd_92 };
                                          letpair_res_932 = id_934;
                                        }
                                        choose_res_929 = letpair_res_932;
                                      } else {
                                        uint16_t id_935 { 16 };
                                        bool id_936 { bool(id_935 == dsum1_fst_73) };
                                        ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_937;
                                        if (id_936) {
                                          auto fun938 { dessser::gen::alerting_contact::of_row_binary };
                                          ::dessser::gen::sync_value::t63085be0ace05d30e702e98f7d406fb6 id_939 { fun938(dsum1_snd_74) };
                                          ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_940;
                                          {
                                            auto dsum2_fst_88 { std::get<0>(id_939) };
                                            auto dsum2_snd_89 { std::get<1>(id_939) };
                                            ::dessser::gen::sync_value::t id_941 { std::in_place_index<16>, dsum2_fst_88 };
                                            ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_942 { id_941, dsum2_snd_89 };
                                            letpair_res_940 = id_942;
                                          }
                                          choose_res_937 = letpair_res_940;
                                        } else {
                                          uint16_t id_943 { 17 };
                                          bool id_944 { bool(id_943 == dsum1_fst_73) };
                                          ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_945;
                                          if (id_944) {
                                            auto fun946 { dessser::gen::alerting_notification::of_row_binary };
                                            ::dessser::gen::sync_value::t2587780bdb272f24e6438b12cbc61e92 id_947 { fun946(dsum1_snd_74) };
                                            ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_948;
                                            {
                                              auto dsum2_fst_85 { std::get<0>(id_947) };
                                              auto dsum2_snd_86 { std::get<1>(id_947) };
                                              ::dessser::gen::sync_value::t id_949 { std::in_place_index<17>, dsum2_fst_85 };
                                              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_950 { id_949, dsum2_snd_86 };
                                              letpair_res_948 = id_950;
                                            }
                                            choose_res_945 = letpair_res_948;
                                          } else {
                                            uint16_t id_951 { 18 };
                                            bool id_952 { bool(id_951 == dsum1_fst_73) };
                                            ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_953;
                                            if (id_952) {
                                              auto fun954 { dessser::gen::alerting_delivery_status::of_row_binary };
                                              ::dessser::gen::sync_value::te49867912245e444e88027721575ec35 id_955 { fun954(dsum1_snd_74) };
                                              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_956;
                                              {
                                                auto dsum2_fst_82 { std::get<0>(id_955) };
                                                auto dsum2_snd_83 { std::get<1>(id_955) };
                                                ::dessser::gen::sync_value::t id_957 { std::in_place_index<18>, dsum2_fst_82 };
                                                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_958 { id_957, dsum2_snd_83 };
                                                letpair_res_956 = id_958;
                                              }
                                              choose_res_953 = letpair_res_956;
                                            } else {
                                              uint16_t id_959 { 19 };
                                              bool id_960 { bool(id_959 == dsum1_fst_73) };
                                              ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 choose_res_961;
                                              if (id_960) {
                                                auto fun962 { dessser::gen::alerting_log::of_row_binary };
                                                ::dessser::gen::sync_value::t555ce468db008991e3ea7cea3f54910f id_963 { fun962(dsum1_snd_74) };
                                                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_964;
                                                {
                                                  auto dsum2_fst_79 { std::get<0>(id_963) };
                                                  auto dsum2_snd_80 { std::get<1>(id_963) };
                                                  ::dessser::gen::sync_value::t id_965 { std::in_place_index<19>, dsum2_fst_79 };
                                                  ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_966 { id_965, dsum2_snd_80 };
                                                  letpair_res_964 = id_966;
                                                }
                                                choose_res_961 = letpair_res_964;
                                              } else {
                                                uint16_t id_967 { 20 };
                                                bool id_968 { bool(dsum1_fst_73 == id_967) };
                                                Void id_969 { ((void)(assert(id_968)), ::dessser::Void()) };
                                                (void)id_969;
                                                auto fun970 { dessser::gen::alerting_inhibition::of_row_binary };
                                                ::dessser::gen::sync_value::t511ff94fe7190561084aee555c49cbe8 id_971 { fun970(dsum1_snd_74) };
                                                ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_972;
                                                {
                                                  auto dsum2_fst_76 { std::get<0>(id_971) };
                                                  auto dsum2_snd_77 { std::get<1>(id_971) };
                                                  ::dessser::gen::sync_value::t id_973 { std::in_place_index<20>, dsum2_fst_76 };
                                                  ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_974 { id_973, dsum2_snd_77 };
                                                  letpair_res_972 = id_974;
                                                }
                                                choose_res_961 = letpair_res_972;
                                              }
                                              choose_res_953 = choose_res_961;
                                            }
                                            choose_res_945 = choose_res_953;
                                          }
                                          choose_res_937 = choose_res_945;
                                        }
                                        choose_res_929 = choose_res_937;
                                      }
                                      choose_res_921 = choose_res_929;
                                    }
                                    choose_res_913 = choose_res_921;
                                  }
                                  choose_res_905 = choose_res_913;
                                }
                                choose_res_897 = choose_res_905;
                              }
                              choose_res_889 = choose_res_897;
                            }
                            choose_res_881 = choose_res_889;
                          }
                          choose_res_873 = choose_res_881;
                        }
                        choose_res_865 = choose_res_873;
                      }
                      choose_res_788 = choose_res_865;
                    }
                    choose_res_780 = choose_res_788;
                  }
                  choose_res_704 = choose_res_780;
                }
                choose_res_696 = choose_res_704;
              }
              choose_res_688 = choose_res_696;
            }
            choose_res_680 = choose_res_688;
          }
          choose_res_617 = choose_res_680;
        }
        letpair_res_614 = choose_res_617;
      }
      let_res_613 = letpair_res_614;
    }
    return let_res_613;
  }
   };
  return fun609;
}
std::function<::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_212" "make_snd_213" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_212") (identifier "make_snd_213"))))
 */
static std::function<::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79(Pointer &)> fun975 { [&](Pointer p_0) {
    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_976 { of_row_binary(p_0) };
    ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 letpair_res_977;
    {
      auto make_fst_212 { std::get<0>(id_976) };
      auto make_snd_213 { std::get<1>(id_976) };
      ::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79 id_978 { make_fst_212, make_snd_213 };
      letpair_res_977 = id_978;
    }
    return letpair_res_977;
  }
   };
  return fun975;
}
std::function<::dessser::gen::sync_value::t0fc9c7c3447925ba31ecb766cf775e79(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | Pivot $pivot | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::sync_value::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_value::t &,Pointer &)> fun979 { [&](::dessser::gen::sync_value::t p_0, Pointer p_1) {
    Pointer id_980 { to_row_binary(p_0, p_1) };
    return id_980;
  }
   };
  return fun979;
}
std::function<Pointer(::dessser::gen::sync_value::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
