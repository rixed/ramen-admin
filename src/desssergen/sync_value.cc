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
  Arr<std::shared_ptr<::dessser::gen::sync_value::tuple> >, // Tuples
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
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 20 };
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
struct t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::sync_value::tuple> >,
  Pointer
> {
  using tuple::tuple;
  t1bf5fe51ea8ba8f996ee38d2f7ebf6a3(std::tuple<Lst<std::shared_ptr<::dessser::gen::sync_value::tuple> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::sync_value::tuple> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 const &a, t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 const &a, t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 const &b) {
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
      (let "srec_dst_227" (write-u32 little-endian (param 1) (get-field "skipped" (param 0))) (apply (ext-identifier raql_value to-row-binary) (get-field "values" (param 0)) (identifier "srec_dst_227"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::tuple> ,Pointer)> tuple_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::tuple> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::sync_value::tuple>  p_0, Pointer p_1) {
    uint32_t id_1 { (*p_0).skipped };
    Pointer id_2 { p_1.writeU32Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_227 { id_2 };
      auto fun4 { dessser::gen::raql_value::to_row_binary };
      dessser::gen::raql_value::t_ext id_5 { (*p_0).values };
      Pointer id_6 { fun4(id_5, srec_dst_227) };
      let_res_3 = id_6;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::tuple> ,Pointer)> tuple_to_row_binary(tuple_to_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" "Ptr")
      (let "label1_228" (label-of (param 0))
        (let "ssum_dst_229" (write-u16 little-endian (param 1) (identifier "label1_228"))
          (if (eq (u16 0) (identifier "label1_228"))
            (let "stup_dst_241"
              (let "stup_dst_240" (write-u64 little-endian (identifier "ssum_dst_229") (u64-of-float (get-item 0 (get-alt "Error" (param 0)))))
                (write-u32 little-endian (identifier "stup_dst_240") (get-item 1 (get-alt "Error" (param 0)))))
              (write-bytes
                (let "leb128_sz_242" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                  (let "leb128_ptr_243" (make-vec (identifier "stup_dst_241"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_243")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_243"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_242"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_242"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_242"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_242") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_242")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_242")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_243"))))) 
                (bytes-of-string (get-item 2 (get-alt "Error" (param 0))))))
            (if (eq (u16 1) (identifier "label1_228")) (apply (ext-identifier worker to-row-binary) (get-alt "Worker" (param 0)) (identifier "ssum_dst_229"))
              (if (eq (u16 2) (identifier "label1_228")) (apply (ext-identifier retention to-row-binary) (get-alt "Retention" (param 0)) (identifier "ssum_dst_229"))
                (if (eq (u16 3) (identifier "label1_228")) (apply (ext-identifier time_range to-row-binary) (get-alt "TimeRange" (param 0)) (identifier "ssum_dst_229"))
                  (if (eq (u16 4) (identifier "label1_228"))
                    (let "dst_ref_237"
                      (make-vec
                        (let "leb128_sz_235" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "leb128_ptr_236" (make-vec (identifier "ssum_dst_229"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_236")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_236"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_235"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_235"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_235"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_235") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_235")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_235")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_236"))))))
                      (let "n_ref_238" (make-vec (i32 0))
                        (seq
                          (for-each "x_239" (get-alt "Tuples" (param 0))
                            (seq (set-vec (u8 0) (identifier "dst_ref_237") (apply (identifier "tuple-to-row-binary") (identifier "x_239") (unsafe-nth (u8 0) (identifier "dst_ref_237"))))
                              (set-vec (u8 0) (identifier "n_ref_238") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_238")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_237")))))
                    (if (eq (u16 5) (identifier "label1_228")) (apply (ext-identifier raql_value to-row-binary) (get-alt "RamenValue" (param 0)) (identifier "ssum_dst_229"))
                      (if (eq (u16 6) (identifier "label1_228"))
                        (let "dst_ref_232"
                          (make-vec
                            (let "leb128_sz_230" (make-vec (cardinality (get-alt "TargetConfig" (param 0))))
                              (let "leb128_ptr_231" (make-vec (identifier "ssum_dst_229"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_231")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_231"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_230"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_230"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_230"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_230") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_230")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_230")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_231"))))))
                          (let "n_ref_233" (make-vec (i32 0))
                            (seq
                              (for-each "x_234" (get-alt "TargetConfig" (param 0))
                                (seq (set-vec (u8 0) (identifier "dst_ref_232") (apply (ext-identifier rc_entry to-row-binary) (identifier "x_234") (unsafe-nth (u8 0) (identifier "dst_ref_232"))))
                                  (set-vec (u8 0) (identifier "n_ref_233") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_233")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_232")))))
                        (if (eq (u16 7) (identifier "label1_228")) (apply (ext-identifier source_info to-row-binary) (get-alt "SourceInfo" (param 0)) (identifier "ssum_dst_229"))
                          (if (eq (u16 8) (identifier "label1_228")) 
                            (apply (ext-identifier runtime_stats to-row-binary) (get-alt "RuntimeStats" (param 0)) (identifier "ssum_dst_229"))
                            (if (eq (u16 9) (identifier "label1_228")) 
                              (apply (ext-identifier replay to-row-binary) (get-alt "Replay" (param 0)) (identifier "ssum_dst_229"))
                              (if (eq (u16 10) (identifier "label1_228")) 
                                (apply (ext-identifier replayer to-row-binary) (get-alt "Replayer" (param 0)) (identifier "ssum_dst_229"))
                                (if (eq (u16 11) (identifier "label1_228")) 
                                  (apply (ext-identifier replay_request to-row-binary) (get-alt "ReplayRequest" (param 0)) (identifier "ssum_dst_229"))
                                  (if (eq (u16 12) (identifier "label1_228")) 
                                    (apply (ext-identifier alert to-row-binary) (get-alt "Alert" (param 0)) (identifier "ssum_dst_229"))
                                    (if (eq (u16 13) (identifier "label1_228")) 
                                      (apply (ext-identifier output_specs to-row-binary) (get-alt "OutputSpecs" (param 0)) (identifier "ssum_dst_229"))
                                      (if (eq (u16 14) (identifier "label1_228")) 
                                        (apply (ext-identifier dashboard_widget to-row-binary) (get-alt "DashboardWidget" (param 0)) (identifier "ssum_dst_229"))
                                        (if (eq (u16 15) (identifier "label1_228")) 
                                          (apply (ext-identifier alerting_contact to-row-binary) (get-alt "AlertingContact" (param 0)) (identifier "ssum_dst_229"))
                                          (if (eq (u16 16) (identifier "label1_228")) 
                                            (apply (ext-identifier alerting_notification to-row-binary) (get-alt "Notification" (param 0)) (identifier "ssum_dst_229"))
                                            (if (eq (u16 17) (identifier "label1_228")) 
                                              (apply (ext-identifier alerting_delivery_status to-row-binary) (get-alt "DeliveryStatus" (param 0)) (identifier "ssum_dst_229"))
                                              (if (eq (u16 18) (identifier "label1_228")) 
                                                (apply (ext-identifier alerting_log to-row-binary) (get-alt "IncidentLog" (param 0)) (identifier "ssum_dst_229"))
                                                (seq (assert (eq (identifier "label1_228") (u16 19))) (apply (ext-identifier alerting_inhibition to-row-binary) (get-alt "Inhibition" (param 0)) (identifier "ssum_dst_229")))))))))))))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::t> ,Pointer)> fun7 { [&](std::shared_ptr<::dessser::gen::sync_value::t>  p_0, Pointer p_1) {
    uint16_t id_8 { uint16_t((*p_0).index()) };
    Pointer let_res_9;
    {
      uint16_t label1_228 { id_8 };
      Pointer id_10 { p_1.writeU16Le(label1_228) };
      Pointer let_res_11;
      {
        Pointer ssum_dst_229 { id_10 };
        uint16_t id_12 { 0 };
        bool id_13 { bool(id_12 == label1_228) };
        Pointer choose_res_14;
        if (id_13) {
          ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_15 { std::get<0 /* Error */>((*p_0)) };
          double id_16 { std::get<0>(id_15) };
          uint64_t id_17 { qword_of_float(id_16) };
          Pointer id_18 { ssum_dst_229.writeU64Le(id_17) };
          Pointer let_res_19;
          {
            Pointer stup_dst_240 { id_18 };
            ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_20 { std::get<0 /* Error */>((*p_0)) };
            uint32_t id_21 { std::get<1>(id_20) };
            Pointer id_22 { stup_dst_240.writeU32Le(id_21) };
            let_res_19 = id_22;
          }
          Pointer let_res_23;
          {
            Pointer stup_dst_241 { let_res_19 };
            ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_24 { std::get<0 /* Error */>((*p_0)) };
            std::string id_25 { std::get<2>(id_24) };
            uint32_t id_26 { (uint32_t)id_25.size() };
            Vec<1, uint32_t> id_27 {  id_26  };
            Pointer let_res_28;
            {
              Vec<1, uint32_t> leb128_sz_242 { id_27 };
              Vec<1, Pointer> id_29 {  stup_dst_241  };
              Pointer let_res_30;
              {
                Vec<1, Pointer> leb128_ptr_243 { id_29 };
                bool while_flag_31 { true };
                do {
                  uint8_t id_32 { 0 };
                  uint8_t id_33 { 0 };
                  Pointer id_34 { leb128_ptr_243[id_33] };
                  uint32_t id_35 { 128U };
                  uint8_t id_36 { 0 };
                  uint32_t id_37 { leb128_sz_242[id_36] };
                  bool id_38 { bool(id_35 > id_37) };
                  uint8_t choose_res_39;
                  if (id_38) {
                    uint8_t id_40 { 0 };
                    uint32_t id_41 { leb128_sz_242[id_40] };
                    uint8_t id_42 { uint8_t(id_41) };
                    choose_res_39 = id_42;
                  } else {
                    uint8_t id_43 { 0 };
                    uint32_t id_44 { leb128_sz_242[id_43] };
                    uint8_t id_45 { uint8_t(id_44) };
                    uint8_t id_46 { 128 };
                    uint8_t id_47 { uint8_t(id_45 | id_46) };
                    choose_res_39 = id_47;
                  }
                  Pointer id_48 { id_34.writeU8(choose_res_39) };
                  Void id_49 { ((void)(leb128_ptr_243[id_32] = id_48), ::dessser::VOID) };
                  (void)id_49;
                  uint8_t id_50 { 0 };
                  uint8_t id_51 { 0 };
                  uint32_t id_52 { leb128_sz_242[id_51] };
                  uint8_t id_53 { 7 };
                  uint32_t id_54 { uint32_t(id_52 >> id_53) };
                  Void id_55 { ((void)(leb128_sz_242[id_50] = id_54), ::dessser::VOID) };
                  (void)id_55;
                  uint8_t id_56 { 0 };
                  uint32_t id_57 { leb128_sz_242[id_56] };
                  uint32_t id_58 { 0U };
                  bool id_59 { bool(id_57 > id_58) };
                  while_flag_31 = id_59;
                  if (while_flag_31) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_31);
                (void)::dessser::VOID;
                uint8_t id_60 { 0 };
                Pointer id_61 { leb128_ptr_243[id_60] };
                let_res_30 = id_61;
              }
              let_res_28 = let_res_30;
            }
            ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_62 { std::get<0 /* Error */>((*p_0)) };
            std::string id_63 { std::get<2>(id_62) };
            Bytes id_64 { id_63 };
            Pointer id_65 { let_res_28.writeBytes(id_64) };
            let_res_23 = id_65;
          }
          choose_res_14 = let_res_23;
        } else {
          uint16_t id_66 { 1 };
          bool id_67 { bool(id_66 == label1_228) };
          Pointer choose_res_68;
          if (id_67) {
            auto fun69 { dessser::gen::worker::to_row_binary };
            dessser::gen::worker::t_ext id_70 { std::get<1 /* Worker */>((*p_0)) };
            Pointer id_71 { fun69(id_70, ssum_dst_229) };
            choose_res_68 = id_71;
          } else {
            uint16_t id_72 { 2 };
            bool id_73 { bool(id_72 == label1_228) };
            Pointer choose_res_74;
            if (id_73) {
              auto fun75 { dessser::gen::retention::to_row_binary };
              dessser::gen::retention::t_ext id_76 { std::get<2 /* Retention */>((*p_0)) };
              Pointer id_77 { fun75(id_76, ssum_dst_229) };
              choose_res_74 = id_77;
            } else {
              uint16_t id_78 { 3 };
              bool id_79 { bool(id_78 == label1_228) };
              Pointer choose_res_80;
              if (id_79) {
                auto fun81 { dessser::gen::time_range::to_row_binary };
                dessser::gen::time_range::t_ext id_82 { std::get<3 /* TimeRange */>((*p_0)) };
                Pointer id_83 { fun81(id_82, ssum_dst_229) };
                choose_res_80 = id_83;
              } else {
                uint16_t id_84 { 4 };
                bool id_85 { bool(id_84 == label1_228) };
                Pointer choose_res_86;
                if (id_85) {
                  Arr<std::shared_ptr<::dessser::gen::sync_value::tuple> > id_87 { std::get<4 /* Tuples */>((*p_0)) };
                  uint32_t id_88 { id_87.size() };
                  Vec<1, uint32_t> id_89 {  id_88  };
                  Pointer let_res_90;
                  {
                    Vec<1, uint32_t> leb128_sz_235 { id_89 };
                    Vec<1, Pointer> id_91 {  ssum_dst_229  };
                    Pointer let_res_92;
                    {
                      Vec<1, Pointer> leb128_ptr_236 { id_91 };
                      bool while_flag_93 { true };
                      do {
                        uint8_t id_94 { 0 };
                        uint8_t id_95 { 0 };
                        Pointer id_96 { leb128_ptr_236[id_95] };
                        uint32_t id_97 { 128U };
                        uint8_t id_98 { 0 };
                        uint32_t id_99 { leb128_sz_235[id_98] };
                        bool id_100 { bool(id_97 > id_99) };
                        uint8_t choose_res_101;
                        if (id_100) {
                          uint8_t id_102 { 0 };
                          uint32_t id_103 { leb128_sz_235[id_102] };
                          uint8_t id_104 { uint8_t(id_103) };
                          choose_res_101 = id_104;
                        } else {
                          uint8_t id_105 { 0 };
                          uint32_t id_106 { leb128_sz_235[id_105] };
                          uint8_t id_107 { uint8_t(id_106) };
                          uint8_t id_108 { 128 };
                          uint8_t id_109 { uint8_t(id_107 | id_108) };
                          choose_res_101 = id_109;
                        }
                        Pointer id_110 { id_96.writeU8(choose_res_101) };
                        Void id_111 { ((void)(leb128_ptr_236[id_94] = id_110), ::dessser::VOID) };
                        (void)id_111;
                        uint8_t id_112 { 0 };
                        uint8_t id_113 { 0 };
                        uint32_t id_114 { leb128_sz_235[id_113] };
                        uint8_t id_115 { 7 };
                        uint32_t id_116 { uint32_t(id_114 >> id_115) };
                        Void id_117 { ((void)(leb128_sz_235[id_112] = id_116), ::dessser::VOID) };
                        (void)id_117;
                        uint8_t id_118 { 0 };
                        uint32_t id_119 { leb128_sz_235[id_118] };
                        uint32_t id_120 { 0U };
                        bool id_121 { bool(id_119 > id_120) };
                        while_flag_93 = id_121;
                        if (while_flag_93) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_93);
                      (void)::dessser::VOID;
                      uint8_t id_122 { 0 };
                      Pointer id_123 { leb128_ptr_236[id_122] };
                      let_res_92 = id_123;
                    }
                    let_res_90 = let_res_92;
                  }
                  Vec<1, Pointer> id_124 {  let_res_90  };
                  Pointer let_res_125;
                  {
                    Vec<1, Pointer> dst_ref_237 { id_124 };
                    int32_t id_126 { 0L };
                    Vec<1, int32_t> id_127 {  id_126  };
                    Pointer let_res_128;
                    {
                      Vec<1, int32_t> n_ref_238 { id_127 };
                      Arr<std::shared_ptr<::dessser::gen::sync_value::tuple> > id_129 { std::get<4 /* Tuples */>((*p_0)) };
                      for (std::shared_ptr<::dessser::gen::sync_value::tuple>  &x_239 : id_129) {
                        uint8_t id_130 { 0 };
                        uint8_t id_131 { 0 };
                        Pointer id_132 { dst_ref_237[id_131] };
                        Pointer id_133 { tuple_to_row_binary(x_239, id_132) };
                        Void id_134 { ((void)(dst_ref_237[id_130] = id_133), ::dessser::VOID) };
                        (void)id_134;
                        uint8_t id_135 { 0 };
                        int32_t id_136 { 1L };
                        uint8_t id_137 { 0 };
                        int32_t id_138 { n_ref_238[id_137] };
                        int32_t id_139 { int32_t(id_136 + id_138) };
                        Void id_140 { ((void)(n_ref_238[id_135] = id_139), ::dessser::VOID) };
                        (void)id_140;
                        (void)id_140;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_141 { 0 };
                      Pointer id_142 { dst_ref_237[id_141] };
                      let_res_128 = id_142;
                    }
                    let_res_125 = let_res_128;
                  }
                  choose_res_86 = let_res_125;
                } else {
                  uint16_t id_143 { 5 };
                  bool id_144 { bool(id_143 == label1_228) };
                  Pointer choose_res_145;
                  if (id_144) {
                    auto fun146 { dessser::gen::raql_value::to_row_binary };
                    dessser::gen::raql_value::t_ext id_147 { std::get<5 /* RamenValue */>((*p_0)) };
                    Pointer id_148 { fun146(id_147, ssum_dst_229) };
                    choose_res_145 = id_148;
                  } else {
                    uint16_t id_149 { 6 };
                    bool id_150 { bool(id_149 == label1_228) };
                    Pointer choose_res_151;
                    if (id_150) {
                      Arr<dessser::gen::rc_entry::t_ext> id_152 { std::get<6 /* TargetConfig */>((*p_0)) };
                      uint32_t id_153 { id_152.size() };
                      Vec<1, uint32_t> id_154 {  id_153  };
                      Pointer let_res_155;
                      {
                        Vec<1, uint32_t> leb128_sz_230 { id_154 };
                        Vec<1, Pointer> id_156 {  ssum_dst_229  };
                        Pointer let_res_157;
                        {
                          Vec<1, Pointer> leb128_ptr_231 { id_156 };
                          bool while_flag_158 { true };
                          do {
                            uint8_t id_159 { 0 };
                            uint8_t id_160 { 0 };
                            Pointer id_161 { leb128_ptr_231[id_160] };
                            uint32_t id_162 { 128U };
                            uint8_t id_163 { 0 };
                            uint32_t id_164 { leb128_sz_230[id_163] };
                            bool id_165 { bool(id_162 > id_164) };
                            uint8_t choose_res_166;
                            if (id_165) {
                              uint8_t id_167 { 0 };
                              uint32_t id_168 { leb128_sz_230[id_167] };
                              uint8_t id_169 { uint8_t(id_168) };
                              choose_res_166 = id_169;
                            } else {
                              uint8_t id_170 { 0 };
                              uint32_t id_171 { leb128_sz_230[id_170] };
                              uint8_t id_172 { uint8_t(id_171) };
                              uint8_t id_173 { 128 };
                              uint8_t id_174 { uint8_t(id_172 | id_173) };
                              choose_res_166 = id_174;
                            }
                            Pointer id_175 { id_161.writeU8(choose_res_166) };
                            Void id_176 { ((void)(leb128_ptr_231[id_159] = id_175), ::dessser::VOID) };
                            (void)id_176;
                            uint8_t id_177 { 0 };
                            uint8_t id_178 { 0 };
                            uint32_t id_179 { leb128_sz_230[id_178] };
                            uint8_t id_180 { 7 };
                            uint32_t id_181 { uint32_t(id_179 >> id_180) };
                            Void id_182 { ((void)(leb128_sz_230[id_177] = id_181), ::dessser::VOID) };
                            (void)id_182;
                            uint8_t id_183 { 0 };
                            uint32_t id_184 { leb128_sz_230[id_183] };
                            uint32_t id_185 { 0U };
                            bool id_186 { bool(id_184 > id_185) };
                            while_flag_158 = id_186;
                            if (while_flag_158) {
                              (void)::dessser::VOID;
                            }
                          } while (while_flag_158);
                          (void)::dessser::VOID;
                          uint8_t id_187 { 0 };
                          Pointer id_188 { leb128_ptr_231[id_187] };
                          let_res_157 = id_188;
                        }
                        let_res_155 = let_res_157;
                      }
                      Vec<1, Pointer> id_189 {  let_res_155  };
                      Pointer let_res_190;
                      {
                        Vec<1, Pointer> dst_ref_232 { id_189 };
                        int32_t id_191 { 0L };
                        Vec<1, int32_t> id_192 {  id_191  };
                        Pointer let_res_193;
                        {
                          Vec<1, int32_t> n_ref_233 { id_192 };
                          Arr<dessser::gen::rc_entry::t_ext> id_194 { std::get<6 /* TargetConfig */>((*p_0)) };
                          for (dessser::gen::rc_entry::t_ext &x_234 : id_194) {
                            uint8_t id_195 { 0 };
                            auto fun196 { dessser::gen::rc_entry::to_row_binary };
                            uint8_t id_197 { 0 };
                            Pointer id_198 { dst_ref_232[id_197] };
                            Pointer id_199 { fun196(x_234, id_198) };
                            Void id_200 { ((void)(dst_ref_232[id_195] = id_199), ::dessser::VOID) };
                            (void)id_200;
                            uint8_t id_201 { 0 };
                            int32_t id_202 { 1L };
                            uint8_t id_203 { 0 };
                            int32_t id_204 { n_ref_233[id_203] };
                            int32_t id_205 { int32_t(id_202 + id_204) };
                            Void id_206 { ((void)(n_ref_233[id_201] = id_205), ::dessser::VOID) };
                            (void)id_206;
                            (void)id_206;
                          }
                          (void)::dessser::VOID;
                          uint8_t id_207 { 0 };
                          Pointer id_208 { dst_ref_232[id_207] };
                          let_res_193 = id_208;
                        }
                        let_res_190 = let_res_193;
                      }
                      choose_res_151 = let_res_190;
                    } else {
                      uint16_t id_209 { 7 };
                      bool id_210 { bool(id_209 == label1_228) };
                      Pointer choose_res_211;
                      if (id_210) {
                        auto fun212 { dessser::gen::source_info::to_row_binary };
                        dessser::gen::source_info::t_ext id_213 { std::get<7 /* SourceInfo */>((*p_0)) };
                        Pointer id_214 { fun212(id_213, ssum_dst_229) };
                        choose_res_211 = id_214;
                      } else {
                        uint16_t id_215 { 8 };
                        bool id_216 { bool(id_215 == label1_228) };
                        Pointer choose_res_217;
                        if (id_216) {
                          auto fun218 { dessser::gen::runtime_stats::to_row_binary };
                          dessser::gen::runtime_stats::t_ext id_219 { std::get<8 /* RuntimeStats */>((*p_0)) };
                          Pointer id_220 { fun218(id_219, ssum_dst_229) };
                          choose_res_217 = id_220;
                        } else {
                          uint16_t id_221 { 9 };
                          bool id_222 { bool(id_221 == label1_228) };
                          Pointer choose_res_223;
                          if (id_222) {
                            auto fun224 { dessser::gen::replay::to_row_binary };
                            dessser::gen::replay::t_ext id_225 { std::get<9 /* Replay */>((*p_0)) };
                            Pointer id_226 { fun224(id_225, ssum_dst_229) };
                            choose_res_223 = id_226;
                          } else {
                            uint16_t id_227 { 10 };
                            bool id_228 { bool(id_227 == label1_228) };
                            Pointer choose_res_229;
                            if (id_228) {
                              auto fun230 { dessser::gen::replayer::to_row_binary };
                              dessser::gen::replayer::t_ext id_231 { std::get<10 /* Replayer */>((*p_0)) };
                              Pointer id_232 { fun230(id_231, ssum_dst_229) };
                              choose_res_229 = id_232;
                            } else {
                              uint16_t id_233 { 11 };
                              bool id_234 { bool(id_233 == label1_228) };
                              Pointer choose_res_235;
                              if (id_234) {
                                auto fun236 { dessser::gen::replay_request::to_row_binary };
                                dessser::gen::replay_request::t_ext id_237 { std::get<11 /* ReplayRequest */>((*p_0)) };
                                Pointer id_238 { fun236(id_237, ssum_dst_229) };
                                choose_res_235 = id_238;
                              } else {
                                uint16_t id_239 { 12 };
                                bool id_240 { bool(id_239 == label1_228) };
                                Pointer choose_res_241;
                                if (id_240) {
                                  auto fun242 { dessser::gen::alert::to_row_binary };
                                  dessser::gen::alert::t_ext id_243 { std::get<12 /* Alert */>((*p_0)) };
                                  Pointer id_244 { fun242(id_243, ssum_dst_229) };
                                  choose_res_241 = id_244;
                                } else {
                                  uint16_t id_245 { 13 };
                                  bool id_246 { bool(id_245 == label1_228) };
                                  Pointer choose_res_247;
                                  if (id_246) {
                                    auto fun248 { dessser::gen::output_specs::to_row_binary };
                                    dessser::gen::output_specs::t_ext id_249 { std::get<13 /* OutputSpecs */>((*p_0)) };
                                    Pointer id_250 { fun248(id_249, ssum_dst_229) };
                                    choose_res_247 = id_250;
                                  } else {
                                    uint16_t id_251 { 14 };
                                    bool id_252 { bool(id_251 == label1_228) };
                                    Pointer choose_res_253;
                                    if (id_252) {
                                      auto fun254 { dessser::gen::dashboard_widget::to_row_binary };
                                      dessser::gen::dashboard_widget::t_ext id_255 { std::get<14 /* DashboardWidget */>((*p_0)) };
                                      Pointer id_256 { fun254(id_255, ssum_dst_229) };
                                      choose_res_253 = id_256;
                                    } else {
                                      uint16_t id_257 { 15 };
                                      bool id_258 { bool(id_257 == label1_228) };
                                      Pointer choose_res_259;
                                      if (id_258) {
                                        auto fun260 { dessser::gen::alerting_contact::to_row_binary };
                                        dessser::gen::alerting_contact::t_ext id_261 { std::get<15 /* AlertingContact */>((*p_0)) };
                                        Pointer id_262 { fun260(id_261, ssum_dst_229) };
                                        choose_res_259 = id_262;
                                      } else {
                                        uint16_t id_263 { 16 };
                                        bool id_264 { bool(id_263 == label1_228) };
                                        Pointer choose_res_265;
                                        if (id_264) {
                                          auto fun266 { dessser::gen::alerting_notification::to_row_binary };
                                          dessser::gen::alerting_notification::t_ext id_267 { std::get<16 /* Notification */>((*p_0)) };
                                          Pointer id_268 { fun266(id_267, ssum_dst_229) };
                                          choose_res_265 = id_268;
                                        } else {
                                          uint16_t id_269 { 17 };
                                          bool id_270 { bool(id_269 == label1_228) };
                                          Pointer choose_res_271;
                                          if (id_270) {
                                            auto fun272 { dessser::gen::alerting_delivery_status::to_row_binary };
                                            dessser::gen::alerting_delivery_status::t_ext id_273 { std::get<17 /* DeliveryStatus */>((*p_0)) };
                                            Pointer id_274 { fun272(id_273, ssum_dst_229) };
                                            choose_res_271 = id_274;
                                          } else {
                                            uint16_t id_275 { 18 };
                                            bool id_276 { bool(id_275 == label1_228) };
                                            Pointer choose_res_277;
                                            if (id_276) {
                                              auto fun278 { dessser::gen::alerting_log::to_row_binary };
                                              dessser::gen::alerting_log::t_ext id_279 { std::get<18 /* IncidentLog */>((*p_0)) };
                                              Pointer id_280 { fun278(id_279, ssum_dst_229) };
                                              choose_res_277 = id_280;
                                            } else {
                                              uint16_t id_281 { 19 };
                                              bool id_282 { bool(label1_228 == id_281) };
                                              Void id_283 { ((void)(assert(id_282)), ::dessser::VOID) };
                                              (void)id_283;
                                              auto fun284 { dessser::gen::alerting_inhibition::to_row_binary };
                                              dessser::gen::alerting_inhibition::t_ext id_285 { std::get<19 /* Inhibition */>((*p_0)) };
                                              Pointer id_286 { fun284(id_285, ssum_dst_229) };
                                              choose_res_277 = id_286;
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
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{skipped: U32; values: $raql_value}") (add (size 4) (apply (ext-identifier raql_value sersize-of-row-binary) (get-field "values" (param 0)))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_value::tuple> )> tuple_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_value::tuple> )> fun287 { [&](std::shared_ptr<::dessser::gen::sync_value::tuple>  p_0) {
    Size id_288 { 4UL };
    auto fun289 { dessser::gen::raql_value::sersize_of_row_binary };
    dessser::gen::raql_value::t_ext id_290 { (*p_0).values };
    Size id_291 { fun289(id_290) };
    Size id_292 { Size(id_288 + id_291) };
    return id_292;
  }
   };
  return fun287;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_value::tuple> )> tuple_sersize_of_row_binary(tuple_sersize_of_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]")
      (let "label2_212" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_212"))
          (add (size 14)
            (add
              (let "n_ref_225" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                (let "lebsz_ref_226" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_225")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_226")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_226") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_226")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_226")))))) 
              (size-of-u32 (string-length (get-item 2 (get-alt "Error" (param 0)))))))
          (if (eq (u16 1) (identifier "label2_212")) (add (size 2) (apply (ext-identifier worker sersize-of-row-binary) (get-alt "Worker" (param 0))))
            (if (eq (u16 2) (identifier "label2_212")) (add (size 2) (apply (ext-identifier retention sersize-of-row-binary) (get-alt "Retention" (param 0))))
              (if (eq (u16 3) (identifier "label2_212")) (add (size 2) (apply (ext-identifier time_range sersize-of-row-binary) (get-alt "TimeRange" (param 0))))
                (if (eq (u16 4) (identifier "label2_212"))
                  (let "sz_ref_219"
                    (make-vec
                      (add (size 2)
                        (let "n_ref_217" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "lebsz_ref_218" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_217")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_218")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_218") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_218")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_218"))))))))
                    (seq
                      (let "repeat_n_220" (make-vec (i32 0))
                        (while (gt (to-i32 (cardinality (get-alt "Tuples" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_220")))
                          (seq
                            (set-vec (u8 0) (identifier "sz_ref_219")
                              (add (unsafe-nth (u8 0) (identifier "sz_ref_219")) (apply (identifier "tuple-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_220")) (get-alt "Tuples" (param 0))))))
                            (set-vec (u8 0) (identifier "repeat_n_220") (add (unsafe-nth (u8 0) (identifier "repeat_n_220")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "sz_ref_219"))))
                  (if (eq (u16 5) (identifier "label2_212")) (add (size 2) (apply (ext-identifier raql_value sersize-of-row-binary) (get-alt "RamenValue" (param 0))))
                    (if (eq (u16 6) (identifier "label2_212"))
                      (let "sz_ref_215"
                        (make-vec
                          (add (size 2)
                            (let "n_ref_213" (make-vec (cardinality (get-alt "TargetConfig" (param 0))))
                              (let "lebsz_ref_214" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_213")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_214")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_214") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_214")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_214"))))))))
                        (seq
                          (let "repeat_n_216" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-alt "TargetConfig" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_216")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_215")
                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_215"))
                                    (apply (ext-identifier rc_entry sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_216")) (get-alt "TargetConfig" (param 0))))))
                                (set-vec (u8 0) (identifier "repeat_n_216") (add (unsafe-nth (u8 0) (identifier "repeat_n_216")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_215"))))
                      (if (eq (u16 7) (identifier "label2_212")) (add (size 2) (apply (ext-identifier source_info sersize-of-row-binary) (get-alt "SourceInfo" (param 0))))
                        (if (eq (u16 8) (identifier "label2_212")) (add (size 2) (apply (ext-identifier runtime_stats sersize-of-row-binary) (get-alt "RuntimeStats" (param 0))))
                          (if (eq (u16 9) (identifier "label2_212")) 
                            (add (size 2) (apply (ext-identifier replay sersize-of-row-binary) (get-alt "Replay" (param 0))))
                            (if (eq (u16 10) (identifier "label2_212")) 
                              (add (size 2) (apply (ext-identifier replayer sersize-of-row-binary) (get-alt "Replayer" (param 0))))
                              (if (eq (u16 11) (identifier "label2_212")) 
                                (add (size 2) (apply (ext-identifier replay_request sersize-of-row-binary) (get-alt "ReplayRequest" (param 0))))
                                (if (eq (u16 12) (identifier "label2_212")) 
                                  (add (size 2) (apply (ext-identifier alert sersize-of-row-binary) (get-alt "Alert" (param 0))))
                                  (if (eq (u16 13) (identifier "label2_212")) 
                                    (add (size 2) (apply (ext-identifier output_specs sersize-of-row-binary) (get-alt "OutputSpecs" (param 0))))
                                    (if (eq (u16 14) (identifier "label2_212")) 
                                      (add (size 2) (apply (ext-identifier dashboard_widget sersize-of-row-binary) (get-alt "DashboardWidget" (param 0))))
                                      (if (eq (u16 15) (identifier "label2_212")) 
                                        (add (size 2) (apply (ext-identifier alerting_contact sersize-of-row-binary) (get-alt "AlertingContact" (param 0))))
                                        (if (eq (u16 16) (identifier "label2_212")) 
                                          (add (size 2) (apply (ext-identifier alerting_notification sersize-of-row-binary) (get-alt "Notification" (param 0))))
                                          (if (eq (u16 17) (identifier "label2_212")) 
                                            (add (size 2) (apply (ext-identifier alerting_delivery_status sersize-of-row-binary) (get-alt "DeliveryStatus" (param 0))))
                                            (if (eq (u16 18) (identifier "label2_212")) 
                                              (add (size 2) (apply (ext-identifier alerting_log sersize-of-row-binary) (get-alt "IncidentLog" (param 0))))
                                              (seq (assert (eq (identifier "label2_212") (u16 19))) (add (size 2) (apply (ext-identifier alerting_inhibition sersize-of-row-binary) (get-alt "Inhibition" (param 0))))))))))))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_value::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_value::t> )> fun293 { [&](std::shared_ptr<::dessser::gen::sync_value::t>  p_0) {
    uint16_t id_294 { uint16_t((*p_0).index()) };
    Size let_res_295;
    {
      uint16_t label2_212 { id_294 };
      uint16_t id_296 { 0 };
      bool id_297 { bool(id_296 == label2_212) };
      Size choose_res_298;
      if (id_297) {
        Size id_299 { 14UL };
        ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_300 { std::get<0 /* Error */>((*p_0)) };
        std::string id_301 { std::get<2>(id_300) };
        uint32_t id_302 { (uint32_t)id_301.size() };
        Vec<1, uint32_t> id_303 {  id_302  };
        Size let_res_304;
        {
          Vec<1, uint32_t> n_ref_225 { id_303 };
          uint32_t id_305 { 1U };
          Vec<1, uint32_t> id_306 {  id_305  };
          Size let_res_307;
          {
            Vec<1, uint32_t> lebsz_ref_226 { id_306 };
            bool while_flag_308 { true };
            do {
              uint8_t id_309 { 0 };
              uint32_t id_310 { n_ref_225[id_309] };
              uint8_t id_311 { 0 };
              uint32_t id_312 { lebsz_ref_226[id_311] };
              uint8_t id_313 { 7 };
              uint32_t id_314 { uint32_t(id_312 << id_313) };
              bool id_315 { bool(id_310 >= id_314) };
              while_flag_308 = id_315;
              if (while_flag_308) {
                uint8_t id_316 { 0 };
                uint8_t id_317 { 0 };
                uint32_t id_318 { lebsz_ref_226[id_317] };
                uint32_t id_319 { 1U };
                uint32_t id_320 { uint32_t(id_318 + id_319) };
                Void id_321 { ((void)(lebsz_ref_226[id_316] = id_320), ::dessser::VOID) };
                (void)id_321;
              }
            } while (while_flag_308);
            (void)::dessser::VOID;
            uint8_t id_322 { 0 };
            uint32_t id_323 { lebsz_ref_226[id_322] };
            Size id_324 { Size(id_323) };
            let_res_307 = id_324;
          }
          let_res_304 = let_res_307;
        }
        ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_325 { std::get<0 /* Error */>((*p_0)) };
        std::string id_326 { std::get<2>(id_325) };
        uint32_t id_327 { (uint32_t)id_326.size() };
        Size id_328 { Size(id_327) };
        Size id_329 { Size(let_res_304 + id_328) };
        Size id_330 { Size(id_299 + id_329) };
        choose_res_298 = id_330;
      } else {
        uint16_t id_331 { 1 };
        bool id_332 { bool(id_331 == label2_212) };
        Size choose_res_333;
        if (id_332) {
          Size id_334 { 2UL };
          auto fun335 { dessser::gen::worker::sersize_of_row_binary };
          dessser::gen::worker::t_ext id_336 { std::get<1 /* Worker */>((*p_0)) };
          Size id_337 { fun335(id_336) };
          Size id_338 { Size(id_334 + id_337) };
          choose_res_333 = id_338;
        } else {
          uint16_t id_339 { 2 };
          bool id_340 { bool(id_339 == label2_212) };
          Size choose_res_341;
          if (id_340) {
            Size id_342 { 2UL };
            auto fun343 { dessser::gen::retention::sersize_of_row_binary };
            dessser::gen::retention::t_ext id_344 { std::get<2 /* Retention */>((*p_0)) };
            Size id_345 { fun343(id_344) };
            Size id_346 { Size(id_342 + id_345) };
            choose_res_341 = id_346;
          } else {
            uint16_t id_347 { 3 };
            bool id_348 { bool(id_347 == label2_212) };
            Size choose_res_349;
            if (id_348) {
              Size id_350 { 2UL };
              auto fun351 { dessser::gen::time_range::sersize_of_row_binary };
              dessser::gen::time_range::t_ext id_352 { std::get<3 /* TimeRange */>((*p_0)) };
              Size id_353 { fun351(id_352) };
              Size id_354 { Size(id_350 + id_353) };
              choose_res_349 = id_354;
            } else {
              uint16_t id_355 { 4 };
              bool id_356 { bool(id_355 == label2_212) };
              Size choose_res_357;
              if (id_356) {
                Size id_358 { 2UL };
                Arr<std::shared_ptr<::dessser::gen::sync_value::tuple> > id_359 { std::get<4 /* Tuples */>((*p_0)) };
                uint32_t id_360 { id_359.size() };
                Vec<1, uint32_t> id_361 {  id_360  };
                Size let_res_362;
                {
                  Vec<1, uint32_t> n_ref_217 { id_361 };
                  uint32_t id_363 { 1U };
                  Vec<1, uint32_t> id_364 {  id_363  };
                  Size let_res_365;
                  {
                    Vec<1, uint32_t> lebsz_ref_218 { id_364 };
                    bool while_flag_366 { true };
                    do {
                      uint8_t id_367 { 0 };
                      uint32_t id_368 { n_ref_217[id_367] };
                      uint8_t id_369 { 0 };
                      uint32_t id_370 { lebsz_ref_218[id_369] };
                      uint8_t id_371 { 7 };
                      uint32_t id_372 { uint32_t(id_370 << id_371) };
                      bool id_373 { bool(id_368 >= id_372) };
                      while_flag_366 = id_373;
                      if (while_flag_366) {
                        uint8_t id_374 { 0 };
                        uint8_t id_375 { 0 };
                        uint32_t id_376 { lebsz_ref_218[id_375] };
                        uint32_t id_377 { 1U };
                        uint32_t id_378 { uint32_t(id_376 + id_377) };
                        Void id_379 { ((void)(lebsz_ref_218[id_374] = id_378), ::dessser::VOID) };
                        (void)id_379;
                      }
                    } while (while_flag_366);
                    (void)::dessser::VOID;
                    uint8_t id_380 { 0 };
                    uint32_t id_381 { lebsz_ref_218[id_380] };
                    Size id_382 { Size(id_381) };
                    let_res_365 = id_382;
                  }
                  let_res_362 = let_res_365;
                }
                Size id_383 { Size(id_358 + let_res_362) };
                Vec<1, Size> id_384 {  id_383  };
                Size let_res_385;
                {
                  Vec<1, Size> sz_ref_219 { id_384 };
                  int32_t id_386 { 0L };
                  Vec<1, int32_t> id_387 {  id_386  };
                  {
                    Vec<1, int32_t> repeat_n_220 { id_387 };
                    bool while_flag_388 { true };
                    do {
                      Arr<std::shared_ptr<::dessser::gen::sync_value::tuple> > id_389 { std::get<4 /* Tuples */>((*p_0)) };
                      uint32_t id_390 { id_389.size() };
                      int32_t id_391 { int32_t(id_390) };
                      uint8_t id_392 { 0 };
                      int32_t id_393 { repeat_n_220[id_392] };
                      bool id_394 { bool(id_391 > id_393) };
                      while_flag_388 = id_394;
                      if (while_flag_388) {
                        uint8_t id_395 { 0 };
                        uint8_t id_396 { 0 };
                        Size id_397 { sz_ref_219[id_396] };
                        uint8_t id_398 { 0 };
                        int32_t id_399 { repeat_n_220[id_398] };
                        Arr<std::shared_ptr<::dessser::gen::sync_value::tuple> > id_400 { std::get<4 /* Tuples */>((*p_0)) };
                        std::shared_ptr<::dessser::gen::sync_value::tuple>  id_401 { id_400[id_399] };
                        Size id_402 { tuple_sersize_of_row_binary(id_401) };
                        Size id_403 { Size(id_397 + id_402) };
                        Void id_404 { ((void)(sz_ref_219[id_395] = id_403), ::dessser::VOID) };
                        (void)id_404;
                        uint8_t id_405 { 0 };
                        uint8_t id_406 { 0 };
                        int32_t id_407 { repeat_n_220[id_406] };
                        int32_t id_408 { 1L };
                        int32_t id_409 { int32_t(id_407 + id_408) };
                        Void id_410 { ((void)(repeat_n_220[id_405] = id_409), ::dessser::VOID) };
                        (void)id_410;
                        (void)id_410;
                      }
                    } while (while_flag_388);
                    (void)::dessser::VOID;
                  }
                  (void)::dessser::VOID;
                  uint8_t id_411 { 0 };
                  Size id_412 { sz_ref_219[id_411] };
                  let_res_385 = id_412;
                }
                choose_res_357 = let_res_385;
              } else {
                uint16_t id_413 { 5 };
                bool id_414 { bool(id_413 == label2_212) };
                Size choose_res_415;
                if (id_414) {
                  Size id_416 { 2UL };
                  auto fun417 { dessser::gen::raql_value::sersize_of_row_binary };
                  dessser::gen::raql_value::t_ext id_418 { std::get<5 /* RamenValue */>((*p_0)) };
                  Size id_419 { fun417(id_418) };
                  Size id_420 { Size(id_416 + id_419) };
                  choose_res_415 = id_420;
                } else {
                  uint16_t id_421 { 6 };
                  bool id_422 { bool(id_421 == label2_212) };
                  Size choose_res_423;
                  if (id_422) {
                    Size id_424 { 2UL };
                    Arr<dessser::gen::rc_entry::t_ext> id_425 { std::get<6 /* TargetConfig */>((*p_0)) };
                    uint32_t id_426 { id_425.size() };
                    Vec<1, uint32_t> id_427 {  id_426  };
                    Size let_res_428;
                    {
                      Vec<1, uint32_t> n_ref_213 { id_427 };
                      uint32_t id_429 { 1U };
                      Vec<1, uint32_t> id_430 {  id_429  };
                      Size let_res_431;
                      {
                        Vec<1, uint32_t> lebsz_ref_214 { id_430 };
                        bool while_flag_432 { true };
                        do {
                          uint8_t id_433 { 0 };
                          uint32_t id_434 { n_ref_213[id_433] };
                          uint8_t id_435 { 0 };
                          uint32_t id_436 { lebsz_ref_214[id_435] };
                          uint8_t id_437 { 7 };
                          uint32_t id_438 { uint32_t(id_436 << id_437) };
                          bool id_439 { bool(id_434 >= id_438) };
                          while_flag_432 = id_439;
                          if (while_flag_432) {
                            uint8_t id_440 { 0 };
                            uint8_t id_441 { 0 };
                            uint32_t id_442 { lebsz_ref_214[id_441] };
                            uint32_t id_443 { 1U };
                            uint32_t id_444 { uint32_t(id_442 + id_443) };
                            Void id_445 { ((void)(lebsz_ref_214[id_440] = id_444), ::dessser::VOID) };
                            (void)id_445;
                          }
                        } while (while_flag_432);
                        (void)::dessser::VOID;
                        uint8_t id_446 { 0 };
                        uint32_t id_447 { lebsz_ref_214[id_446] };
                        Size id_448 { Size(id_447) };
                        let_res_431 = id_448;
                      }
                      let_res_428 = let_res_431;
                    }
                    Size id_449 { Size(id_424 + let_res_428) };
                    Vec<1, Size> id_450 {  id_449  };
                    Size let_res_451;
                    {
                      Vec<1, Size> sz_ref_215 { id_450 };
                      int32_t id_452 { 0L };
                      Vec<1, int32_t> id_453 {  id_452  };
                      {
                        Vec<1, int32_t> repeat_n_216 { id_453 };
                        bool while_flag_454 { true };
                        do {
                          Arr<dessser::gen::rc_entry::t_ext> id_455 { std::get<6 /* TargetConfig */>((*p_0)) };
                          uint32_t id_456 { id_455.size() };
                          int32_t id_457 { int32_t(id_456) };
                          uint8_t id_458 { 0 };
                          int32_t id_459 { repeat_n_216[id_458] };
                          bool id_460 { bool(id_457 > id_459) };
                          while_flag_454 = id_460;
                          if (while_flag_454) {
                            uint8_t id_461 { 0 };
                            uint8_t id_462 { 0 };
                            Size id_463 { sz_ref_215[id_462] };
                            auto fun464 { dessser::gen::rc_entry::sersize_of_row_binary };
                            uint8_t id_465 { 0 };
                            int32_t id_466 { repeat_n_216[id_465] };
                            Arr<dessser::gen::rc_entry::t_ext> id_467 { std::get<6 /* TargetConfig */>((*p_0)) };
                            dessser::gen::rc_entry::t_ext id_468 { id_467[id_466] };
                            Size id_469 { fun464(id_468) };
                            Size id_470 { Size(id_463 + id_469) };
                            Void id_471 { ((void)(sz_ref_215[id_461] = id_470), ::dessser::VOID) };
                            (void)id_471;
                            uint8_t id_472 { 0 };
                            uint8_t id_473 { 0 };
                            int32_t id_474 { repeat_n_216[id_473] };
                            int32_t id_475 { 1L };
                            int32_t id_476 { int32_t(id_474 + id_475) };
                            Void id_477 { ((void)(repeat_n_216[id_472] = id_476), ::dessser::VOID) };
                            (void)id_477;
                            (void)id_477;
                          }
                        } while (while_flag_454);
                        (void)::dessser::VOID;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_478 { 0 };
                      Size id_479 { sz_ref_215[id_478] };
                      let_res_451 = id_479;
                    }
                    choose_res_423 = let_res_451;
                  } else {
                    uint16_t id_480 { 7 };
                    bool id_481 { bool(id_480 == label2_212) };
                    Size choose_res_482;
                    if (id_481) {
                      Size id_483 { 2UL };
                      auto fun484 { dessser::gen::source_info::sersize_of_row_binary };
                      dessser::gen::source_info::t_ext id_485 { std::get<7 /* SourceInfo */>((*p_0)) };
                      Size id_486 { fun484(id_485) };
                      Size id_487 { Size(id_483 + id_486) };
                      choose_res_482 = id_487;
                    } else {
                      uint16_t id_488 { 8 };
                      bool id_489 { bool(id_488 == label2_212) };
                      Size choose_res_490;
                      if (id_489) {
                        Size id_491 { 2UL };
                        auto fun492 { dessser::gen::runtime_stats::sersize_of_row_binary };
                        dessser::gen::runtime_stats::t_ext id_493 { std::get<8 /* RuntimeStats */>((*p_0)) };
                        Size id_494 { fun492(id_493) };
                        Size id_495 { Size(id_491 + id_494) };
                        choose_res_490 = id_495;
                      } else {
                        uint16_t id_496 { 9 };
                        bool id_497 { bool(id_496 == label2_212) };
                        Size choose_res_498;
                        if (id_497) {
                          Size id_499 { 2UL };
                          auto fun500 { dessser::gen::replay::sersize_of_row_binary };
                          dessser::gen::replay::t_ext id_501 { std::get<9 /* Replay */>((*p_0)) };
                          Size id_502 { fun500(id_501) };
                          Size id_503 { Size(id_499 + id_502) };
                          choose_res_498 = id_503;
                        } else {
                          uint16_t id_504 { 10 };
                          bool id_505 { bool(id_504 == label2_212) };
                          Size choose_res_506;
                          if (id_505) {
                            Size id_507 { 2UL };
                            auto fun508 { dessser::gen::replayer::sersize_of_row_binary };
                            dessser::gen::replayer::t_ext id_509 { std::get<10 /* Replayer */>((*p_0)) };
                            Size id_510 { fun508(id_509) };
                            Size id_511 { Size(id_507 + id_510) };
                            choose_res_506 = id_511;
                          } else {
                            uint16_t id_512 { 11 };
                            bool id_513 { bool(id_512 == label2_212) };
                            Size choose_res_514;
                            if (id_513) {
                              Size id_515 { 2UL };
                              auto fun516 { dessser::gen::replay_request::sersize_of_row_binary };
                              dessser::gen::replay_request::t_ext id_517 { std::get<11 /* ReplayRequest */>((*p_0)) };
                              Size id_518 { fun516(id_517) };
                              Size id_519 { Size(id_515 + id_518) };
                              choose_res_514 = id_519;
                            } else {
                              uint16_t id_520 { 12 };
                              bool id_521 { bool(id_520 == label2_212) };
                              Size choose_res_522;
                              if (id_521) {
                                Size id_523 { 2UL };
                                auto fun524 { dessser::gen::alert::sersize_of_row_binary };
                                dessser::gen::alert::t_ext id_525 { std::get<12 /* Alert */>((*p_0)) };
                                Size id_526 { fun524(id_525) };
                                Size id_527 { Size(id_523 + id_526) };
                                choose_res_522 = id_527;
                              } else {
                                uint16_t id_528 { 13 };
                                bool id_529 { bool(id_528 == label2_212) };
                                Size choose_res_530;
                                if (id_529) {
                                  Size id_531 { 2UL };
                                  auto fun532 { dessser::gen::output_specs::sersize_of_row_binary };
                                  dessser::gen::output_specs::t_ext id_533 { std::get<13 /* OutputSpecs */>((*p_0)) };
                                  Size id_534 { fun532(id_533) };
                                  Size id_535 { Size(id_531 + id_534) };
                                  choose_res_530 = id_535;
                                } else {
                                  uint16_t id_536 { 14 };
                                  bool id_537 { bool(id_536 == label2_212) };
                                  Size choose_res_538;
                                  if (id_537) {
                                    Size id_539 { 2UL };
                                    auto fun540 { dessser::gen::dashboard_widget::sersize_of_row_binary };
                                    dessser::gen::dashboard_widget::t_ext id_541 { std::get<14 /* DashboardWidget */>((*p_0)) };
                                    Size id_542 { fun540(id_541) };
                                    Size id_543 { Size(id_539 + id_542) };
                                    choose_res_538 = id_543;
                                  } else {
                                    uint16_t id_544 { 15 };
                                    bool id_545 { bool(id_544 == label2_212) };
                                    Size choose_res_546;
                                    if (id_545) {
                                      Size id_547 { 2UL };
                                      auto fun548 { dessser::gen::alerting_contact::sersize_of_row_binary };
                                      dessser::gen::alerting_contact::t_ext id_549 { std::get<15 /* AlertingContact */>((*p_0)) };
                                      Size id_550 { fun548(id_549) };
                                      Size id_551 { Size(id_547 + id_550) };
                                      choose_res_546 = id_551;
                                    } else {
                                      uint16_t id_552 { 16 };
                                      bool id_553 { bool(id_552 == label2_212) };
                                      Size choose_res_554;
                                      if (id_553) {
                                        Size id_555 { 2UL };
                                        auto fun556 { dessser::gen::alerting_notification::sersize_of_row_binary };
                                        dessser::gen::alerting_notification::t_ext id_557 { std::get<16 /* Notification */>((*p_0)) };
                                        Size id_558 { fun556(id_557) };
                                        Size id_559 { Size(id_555 + id_558) };
                                        choose_res_554 = id_559;
                                      } else {
                                        uint16_t id_560 { 17 };
                                        bool id_561 { bool(id_560 == label2_212) };
                                        Size choose_res_562;
                                        if (id_561) {
                                          Size id_563 { 2UL };
                                          auto fun564 { dessser::gen::alerting_delivery_status::sersize_of_row_binary };
                                          dessser::gen::alerting_delivery_status::t_ext id_565 { std::get<17 /* DeliveryStatus */>((*p_0)) };
                                          Size id_566 { fun564(id_565) };
                                          Size id_567 { Size(id_563 + id_566) };
                                          choose_res_562 = id_567;
                                        } else {
                                          uint16_t id_568 { 18 };
                                          bool id_569 { bool(id_568 == label2_212) };
                                          Size choose_res_570;
                                          if (id_569) {
                                            Size id_571 { 2UL };
                                            auto fun572 { dessser::gen::alerting_log::sersize_of_row_binary };
                                            dessser::gen::alerting_log::t_ext id_573 { std::get<18 /* IncidentLog */>((*p_0)) };
                                            Size id_574 { fun572(id_573) };
                                            Size id_575 { Size(id_571 + id_574) };
                                            choose_res_570 = id_575;
                                          } else {
                                            uint16_t id_576 { 19 };
                                            bool id_577 { bool(label2_212 == id_576) };
                                            Void id_578 { ((void)(assert(id_577)), ::dessser::VOID) };
                                            (void)id_578;
                                            Size id_579 { 2UL };
                                            auto fun580 { dessser::gen::alerting_inhibition::sersize_of_row_binary };
                                            dessser::gen::alerting_inhibition::t_ext id_581 { std::get<19 /* Inhibition */>((*p_0)) };
                                            Size id_582 { fun580(id_581) };
                                            Size id_583 { Size(id_579 + id_582) };
                                            choose_res_570 = id_583;
                                          }
                                          choose_res_562 = choose_res_570;
                                        }
                                        choose_res_554 = choose_res_562;
                                      }
                                      choose_res_546 = choose_res_554;
                                    }
                                    choose_res_538 = choose_res_546;
                                  }
                                  choose_res_530 = choose_res_538;
                                }
                                choose_res_522 = choose_res_530;
                              }
                              choose_res_514 = choose_res_522;
                            }
                            choose_res_506 = choose_res_514;
                          }
                          choose_res_498 = choose_res_506;
                        }
                        choose_res_490 = choose_res_498;
                      }
                      choose_res_482 = choose_res_490;
                    }
                    choose_res_423 = choose_res_482;
                  }
                  choose_res_415 = choose_res_423;
                }
                choose_res_357 = choose_res_415;
              }
              choose_res_349 = choose_res_357;
            }
            choose_res_341 = choose_res_349;
          }
          choose_res_333 = choose_res_341;
        }
        choose_res_298 = choose_res_333;
      }
      let_res_295 = choose_res_298;
    }
    return let_res_295;
  }
   };
  return fun293;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_value::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_59" (let-pair "du32_fst_57" "du32_snd_58" (read-u32 little-endian (param 0)) (make-tup (identifier "du32_fst_57") (identifier "du32_snd_58")))
        (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
          (let-pair "drec_fst_63" "drec_snd_64" (apply (ext-identifier raql_value of-row-binary) (identifier "drec_snd_61"))
            (make-tup (make-rec (string "values") (identifier "drec_fst_63") (string "skipped") (identifier "drec_fst_60")) (identifier "drec_snd_64"))))))
 */
static std::function<::dessser::gen::sync_value::t69580374758c5cd49d653ee83c7fa90f(Pointer)> tuple_of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::t69580374758c5cd49d653ee83c7fa90f(Pointer)> fun584 { [&](Pointer p_0) {
    ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_585 { p_0.readU32Le() };
    ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 letpair_res_586;
    {
      auto du32_fst_57 { std::get<0>(id_585) };
      auto du32_snd_58 { std::get<1>(id_585) };
      ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_587 { du32_fst_57, du32_snd_58 };
      letpair_res_586 = id_587;
    }
    ::dessser::gen::sync_value::t69580374758c5cd49d653ee83c7fa90f let_res_588;
    {
      ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 drec_59 { letpair_res_586 };
      ::dessser::gen::sync_value::t69580374758c5cd49d653ee83c7fa90f letpair_res_589;
      {
        auto drec_fst_60 { std::get<0>(drec_59) };
        auto drec_snd_61 { std::get<1>(drec_59) };
        auto fun590 { dessser::gen::raql_value::of_row_binary };
        ::dessser::gen::sync_value::tf3063cfb73e0f06d3ea99ebd15a86d50 id_591 { fun590(drec_snd_61) };
        ::dessser::gen::sync_value::t69580374758c5cd49d653ee83c7fa90f letpair_res_592;
        {
          auto drec_fst_63 { std::get<0>(id_591) };
          auto drec_snd_64 { std::get<1>(id_591) };
          std::shared_ptr<::dessser::gen::sync_value::tuple>  id_593 { std::make_shared<::dessser::gen::sync_value::tuple>(drec_fst_60, drec_fst_63) };
          ::dessser::gen::sync_value::t69580374758c5cd49d653ee83c7fa90f id_594 { id_593, drec_snd_64 };
          letpair_res_592 = id_594;
        }
        letpair_res_589 = letpair_res_592;
      }
      let_res_588 = letpair_res_589;
    }
    return let_res_588;
  }
   };
  return fun584;
}
std::function<::dessser::gen::sync_value::t69580374758c5cd49d653ee83c7fa90f(Pointer)> tuple_of_row_binary(tuple_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_71" (let-pair "du16_fst_66" "du16_snd_67" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_66") (identifier "du16_snd_67")))
        (let-pair "dsum1_fst_72" "dsum1_snd_73" (identifier "dsum1_71")
          (if (eq (u16 0) (identifier "dsum1_fst_72"))
            (let "dtup_180" (let-pair "dfloat_fst_178" "dfloat_snd_179" (read-u64 little-endian (identifier "dsum1_snd_73")) (make-tup (float-of-u64 (identifier "dfloat_fst_178")) (identifier "dfloat_snd_179")))
              (let-pair "dtup_fst_181" "dtup_snd_182" (identifier "dtup_180")
                (let "dtup_186" (let-pair "du32_fst_184" "du32_snd_185" (read-u32 little-endian (identifier "dtup_snd_182")) (make-tup (identifier "du32_fst_184") (identifier "du32_snd_185")))
                  (let-pair "dtup_fst_187" "dtup_snd_188" (identifier "dtup_186")
                    (let "dstring1_195"
                      (let "leb_ref_189" (make-vec (u32 0))
                        (let "shft_ref_190" (make-vec (u8 0))
                          (let "p_ref_191" (make-vec (identifier "dtup_snd_188"))
                            (seq
                              (while
                                (let "leb128_192" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_191")))
                                  (let-pair "leb128_fst_193" "leb128_snd_194" 
                                    (identifier "leb128_192")
                                    (seq (set-vec (u8 0) (identifier "p_ref_191") (identifier "leb128_snd_194"))
                                      (set-vec (u8 0) (identifier "leb_ref_189")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_193") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_190"))) (unsafe-nth (u8 0) (identifier "leb_ref_189"))))
                                      (set-vec (u8 0) (identifier "shft_ref_190") (add (unsafe-nth (u8 0) (identifier "shft_ref_190")) (u8 7))) 
                                      (ge (identifier "leb128_fst_193") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_189"))) (unsafe-nth (u8 0) (identifier "p_ref_191")))))))
                      (let-pair "dstring1_fst_196" "dstring1_snd_197" 
                        (identifier "dstring1_195")
                        (let-pair "dstring2_fst_199" "dstring2_snd_200" 
                          (read-bytes (identifier "dstring1_snd_197") (identifier "dstring1_fst_196"))
                          (make-tup
                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 0
                              (make-tup (identifier "dtup_fst_181") (identifier "dtup_fst_187") (string-of-bytes (identifier "dstring2_fst_199")))) 
                            (identifier "dstring2_snd_200")))))))))
            (if (eq (u16 1) (identifier "dsum1_fst_72"))
              (let-pair "dsum2_fst_175" "dsum2_snd_176" (apply (ext-identifier worker of-row-binary) (identifier "dsum1_snd_73"))
                (make-tup
                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 1
                    (identifier "dsum2_fst_175")) (identifier "dsum2_snd_176")))
              (if (eq (u16 2) (identifier "dsum1_fst_72"))
                (let-pair "dsum2_fst_172" "dsum2_snd_173" (apply (ext-identifier retention of-row-binary) (identifier "dsum1_snd_73"))
                  (make-tup
                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 2
                      (identifier "dsum2_fst_172")) (identifier "dsum2_snd_173")))
                (if (eq (u16 3) (identifier "dsum1_fst_72"))
                  (let-pair "dsum2_fst_169" "dsum2_snd_170" (apply (ext-identifier time_range of-row-binary) (identifier "dsum1_snd_73"))
                    (make-tup
                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 3
                        (identifier "dsum2_fst_169")) (identifier "dsum2_snd_170")))
                  (if (eq (u16 4) (identifier "dsum1_fst_72"))
                    (let-pair "dlist4_fst_163" "dlist4_snd_164"
                      (let "dlist1_151"
                        (let "leb_ref_142" (make-vec (u32 0))
                          (let "shft_ref_143" (make-vec (u8 0))
                            (let "p_ref_144" (make-vec (identifier "dsum1_snd_73"))
                              (seq
                                (while
                                  (let "leb128_145" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_144")))
                                    (let-pair "leb128_fst_146" "leb128_snd_147" 
                                      (identifier "leb128_145")
                                      (seq (set-vec (u8 0) (identifier "p_ref_144") (identifier "leb128_snd_147"))
                                        (set-vec (u8 0) (identifier "leb_ref_142")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_146") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_143"))) (unsafe-nth (u8 0) (identifier "leb_ref_142"))))
                                        (set-vec (u8 0) (identifier "shft_ref_143") (add (unsafe-nth (u8 0) (identifier "shft_ref_143")) (u8 7))) 
                                        (ge (identifier "leb128_fst_146") (u8 128))))) 
                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_142")) (unsafe-nth (u8 0) (identifier "p_ref_144")))))))
                        (let-pair "dlist1_fst_152" "dlist1_snd_153" (identifier "dlist1_151")
                          (let "inits_src_ref_154" (make-vec (make-tup (end-of-list "(tuple AS {skipped: U32; values: $raql_value})") (identifier "dlist1_snd_153")))
                            (seq
                              (let "repeat_n_155" (make-vec (i32 0))
                                (while (gt (to-i32 (identifier "dlist1_fst_152")) (unsafe-nth (u8 0) (identifier "repeat_n_155")))
                                  (seq
                                    (let "dlist2_156" (unsafe-nth (u8 0) (identifier "inits_src_ref_154"))
                                      (let-pair "dlist2_fst_157" "dlist2_snd_158" 
                                        (identifier "dlist2_156")
                                        (set-vec (u8 0) (identifier "inits_src_ref_154")
                                          (let-pair "dlist3_fst_160" "dlist3_snd_161" 
                                            (apply (identifier "tuple-of-row-binary") (identifier "dlist2_snd_158")) 
                                            (make-tup (cons (identifier "dlist3_fst_160") (identifier "dlist2_fst_157")) (identifier "dlist3_snd_161"))))))
                                    (set-vec (u8 0) (identifier "repeat_n_155") (add (unsafe-nth (u8 0) (identifier "repeat_n_155")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "inits_src_ref_154"))))))
                      (make-tup
                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 4
                          (arr-of-lst-rev (identifier "dlist4_fst_163"))) 
                        (identifier "dlist4_snd_164")))
                    (if (eq (u16 5) (identifier "dsum1_fst_72"))
                      (let-pair "dsum2_fst_140" "dsum2_snd_141" (apply (ext-identifier raql_value of-row-binary) (identifier "dsum1_snd_73"))
                        (make-tup
                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 5
                            (identifier "dsum2_fst_140")) (identifier "dsum2_snd_141")))
                      (if (eq (u16 6) (identifier "dsum1_fst_72"))
                        (let-pair "dlist4_fst_134" "dlist4_snd_135"
                          (let "dlist1_122"
                            (let "leb_ref_113" (make-vec (u32 0))
                              (let "shft_ref_114" (make-vec (u8 0))
                                (let "p_ref_115" (make-vec (identifier "dsum1_snd_73"))
                                  (seq
                                    (while
                                      (let "leb128_116" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_115")))
                                        (let-pair "leb128_fst_117" "leb128_snd_118" 
                                          (identifier "leb128_116")
                                          (seq (set-vec (u8 0) (identifier "p_ref_115") (identifier "leb128_snd_118"))
                                            (set-vec (u8 0) (identifier "leb_ref_113")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_117") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_114"))) (unsafe-nth (u8 0) (identifier "leb_ref_113"))))
                                            (set-vec (u8 0) (identifier "shft_ref_114") (add (unsafe-nth (u8 0) (identifier "shft_ref_114")) (u8 7))) 
                                            (ge (identifier "leb128_fst_117") (u8 128))))) 
                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_113")) (unsafe-nth (u8 0) (identifier "p_ref_115")))))))
                            (let-pair "dlist1_fst_123" "dlist1_snd_124" 
                              (identifier "dlist1_122")
                              (let "inits_src_ref_125" (make-vec (make-tup (end-of-list "$rc_entry") (identifier "dlist1_snd_124")))
                                (seq
                                  (let "repeat_n_126" (make-vec (i32 0))
                                    (while (gt (to-i32 (identifier "dlist1_fst_123")) (unsafe-nth (u8 0) (identifier "repeat_n_126")))
                                      (seq
                                        (let "dlist2_127" (unsafe-nth (u8 0) (identifier "inits_src_ref_125"))
                                          (let-pair "dlist2_fst_128" "dlist2_snd_129" 
                                            (identifier "dlist2_127")
                                            (set-vec (u8 0) (identifier "inits_src_ref_125")
                                              (let-pair "dlist3_fst_131" "dlist3_snd_132" 
                                                (apply (ext-identifier rc_entry of-row-binary) (identifier "dlist2_snd_129"))
                                                (make-tup (cons (identifier "dlist3_fst_131") (identifier "dlist2_fst_128")) (identifier "dlist3_snd_132"))))))
                                        (set-vec (u8 0) (identifier "repeat_n_126") (add (unsafe-nth (u8 0) (identifier "repeat_n_126")) (i32 1)))))) 
                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_125"))))))
                          (make-tup
                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 6
                              (arr-of-lst-rev (identifier "dlist4_fst_134"))) 
                            (identifier "dlist4_snd_135")))
                        (if (eq (u16 7) (identifier "dsum1_fst_72"))
                          (let-pair "dsum2_fst_111" "dsum2_snd_112" (apply (ext-identifier source_info of-row-binary) (identifier "dsum1_snd_73"))
                            (make-tup
                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 7
                                (identifier "dsum2_fst_111")) (identifier "dsum2_snd_112")))
                          (if (eq (u16 8) (identifier "dsum1_fst_72"))
                            (let-pair "dsum2_fst_108" "dsum2_snd_109" 
                              (apply (ext-identifier runtime_stats of-row-binary) (identifier "dsum1_snd_73"))
                              (make-tup
                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 8
                                  (identifier "dsum2_fst_108")) (identifier "dsum2_snd_109")))
                            (if (eq (u16 9) (identifier "dsum1_fst_72"))
                              (let-pair "dsum2_fst_105" "dsum2_snd_106" 
                                (apply (ext-identifier replay of-row-binary) (identifier "dsum1_snd_73"))
                                (make-tup
                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 9
                                    (identifier "dsum2_fst_105")) (identifier "dsum2_snd_106")))
                              (if (eq (u16 10) (identifier "dsum1_fst_72"))
                                (let-pair "dsum2_fst_102" "dsum2_snd_103" 
                                  (apply (ext-identifier replayer of-row-binary) (identifier "dsum1_snd_73"))
                                  (make-tup
                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 10
                                      (identifier "dsum2_fst_102")) (identifier "dsum2_snd_103")))
                                (if (eq (u16 11) (identifier "dsum1_fst_72"))
                                  (let-pair "dsum2_fst_99" "dsum2_snd_100" 
                                    (apply (ext-identifier replay_request of-row-binary) (identifier "dsum1_snd_73"))
                                    (make-tup
                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 11
                                        (identifier "dsum2_fst_99")) 
                                      (identifier "dsum2_snd_100")))
                                  (if (eq (u16 12) (identifier "dsum1_fst_72"))
                                    (let-pair "dsum2_fst_96" "dsum2_snd_97" 
                                      (apply (ext-identifier alert of-row-binary) (identifier "dsum1_snd_73"))
                                      (make-tup
                                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 12
                                          (identifier "dsum2_fst_96")) 
                                        (identifier "dsum2_snd_97")))
                                    (if (eq (u16 13) (identifier "dsum1_fst_72"))
                                      (let-pair "dsum2_fst_93" "dsum2_snd_94" 
                                        (apply (ext-identifier output_specs of-row-binary) (identifier "dsum1_snd_73"))
                                        (make-tup
                                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 13
                                            (identifier "dsum2_fst_93")) 
                                          (identifier "dsum2_snd_94")))
                                      (if (eq (u16 14) (identifier "dsum1_fst_72"))
                                        (let-pair "dsum2_fst_90" "dsum2_snd_91" 
                                          (apply (ext-identifier dashboard_widget of-row-binary) (identifier "dsum1_snd_73"))
                                          (make-tup
                                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 14
                                              (identifier "dsum2_fst_90")) 
                                            (identifier "dsum2_snd_91")))
                                        (if (eq (u16 15) (identifier "dsum1_fst_72"))
                                          (let-pair "dsum2_fst_87" "dsum2_snd_88" 
                                            (apply (ext-identifier alerting_contact of-row-binary) (identifier "dsum1_snd_73"))
                                            (make-tup
                                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 15
                                                (identifier "dsum2_fst_87")) 
                                              (identifier "dsum2_snd_88")))
                                          (if (eq (u16 16) (identifier "dsum1_fst_72"))
                                            (let-pair "dsum2_fst_84" "dsum2_snd_85" 
                                              (apply (ext-identifier alerting_notification of-row-binary) (identifier "dsum1_snd_73"))
                                              (make-tup
                                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 16
                                                  (identifier "dsum2_fst_84")) 
                                                (identifier "dsum2_snd_85")))
                                            (if (eq (u16 17) (identifier "dsum1_fst_72"))
                                              (let-pair "dsum2_fst_81" "dsum2_snd_82" 
                                                (apply (ext-identifier alerting_delivery_status of-row-binary) (identifier "dsum1_snd_73"))
                                                (make-tup
                                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 17
                                                    (identifier "dsum2_fst_81")) 
                                                  (identifier "dsum2_snd_82")))
                                              (if (eq (u16 18) (identifier "dsum1_fst_72"))
                                                (let-pair "dsum2_fst_78" "dsum2_snd_79" 
                                                  (apply (ext-identifier alerting_log of-row-binary) (identifier "dsum1_snd_73"))
                                                  (make-tup
                                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 18
                                                      (identifier "dsum2_fst_78")) 
                                                    (identifier "dsum2_snd_79")))
                                                (seq (assert (eq (identifier "dsum1_fst_72") (u16 19)))
                                                  (let-pair "dsum2_fst_75" "dsum2_snd_76" 
                                                    (apply (ext-identifier alerting_inhibition of-row-binary) (identifier "dsum1_snd_73"))
                                                    (make-tup
                                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 19
                                                        (identifier "dsum2_fst_75")) 
                                                      (identifier "dsum2_snd_76"))))))))))))))))))))))))))
 */
static std::function<::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3(Pointer)> fun595 { [&](Pointer p_0) {
    ::dessser::gen::sync_value::ta97bb48ed75bbda6173555873826c8c6 id_596 { p_0.readU16Le() };
    ::dessser::gen::sync_value::ta97bb48ed75bbda6173555873826c8c6 letpair_res_597;
    {
      auto du16_fst_66 { std::get<0>(id_596) };
      auto du16_snd_67 { std::get<1>(id_596) };
      ::dessser::gen::sync_value::ta97bb48ed75bbda6173555873826c8c6 id_598 { du16_fst_66, du16_snd_67 };
      letpair_res_597 = id_598;
    }
    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 let_res_599;
    {
      ::dessser::gen::sync_value::ta97bb48ed75bbda6173555873826c8c6 dsum1_71 { letpair_res_597 };
      ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_600;
      {
        auto dsum1_fst_72 { std::get<0>(dsum1_71) };
        auto dsum1_snd_73 { std::get<1>(dsum1_71) };
        uint16_t id_601 { 0 };
        bool id_602 { bool(id_601 == dsum1_fst_72) };
        ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_603;
        if (id_602) {
          ::dessser::gen::sync_value::td2cd337bb3c8bc04d5603393d084985b id_604 { dsum1_snd_73.readU64Le() };
          ::dessser::gen::sync_value::t9a758baeff17224a77e1a522010b4168 letpair_res_605;
          {
            auto dfloat_fst_178 { std::get<0>(id_604) };
            auto dfloat_snd_179 { std::get<1>(id_604) };
            double id_606 { float_of_qword(dfloat_fst_178) };
            ::dessser::gen::sync_value::t9a758baeff17224a77e1a522010b4168 id_607 { id_606, dfloat_snd_179 };
            letpair_res_605 = id_607;
          }
          ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 let_res_608;
          {
            ::dessser::gen::sync_value::t9a758baeff17224a77e1a522010b4168 dtup_180 { letpair_res_605 };
            ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_609;
            {
              auto dtup_fst_181 { std::get<0>(dtup_180) };
              auto dtup_snd_182 { std::get<1>(dtup_180) };
              ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_610 { dtup_snd_182.readU32Le() };
              ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 letpair_res_611;
              {
                auto du32_fst_184 { std::get<0>(id_610) };
                auto du32_snd_185 { std::get<1>(id_610) };
                ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_612 { du32_fst_184, du32_snd_185 };
                letpair_res_611 = id_612;
              }
              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 let_res_613;
              {
                ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 dtup_186 { letpair_res_611 };
                ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_614;
                {
                  auto dtup_fst_187 { std::get<0>(dtup_186) };
                  auto dtup_snd_188 { std::get<1>(dtup_186) };
                  uint32_t id_615 { 0U };
                  Vec<1, uint32_t> id_616 {  id_615  };
                  ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa let_res_617;
                  {
                    Vec<1, uint32_t> leb_ref_189 { id_616 };
                    uint8_t id_618 { 0 };
                    Vec<1, uint8_t> id_619 {  id_618  };
                    ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa let_res_620;
                    {
                      Vec<1, uint8_t> shft_ref_190 { id_619 };
                      Vec<1, Pointer> id_621 {  dtup_snd_188  };
                      ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa let_res_622;
                      {
                        Vec<1, Pointer> p_ref_191 { id_621 };
                        bool while_flag_623 { true };
                        do {
                          uint8_t id_624 { 0 };
                          Pointer id_625 { p_ref_191[id_624] };
                          ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 id_626 { id_625.readU8() };
                          bool let_res_627;
                          {
                            ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_192 { id_626 };
                            bool letpair_res_628;
                            {
                              auto leb128_fst_193 { std::get<0>(leb128_192) };
                              auto leb128_snd_194 { std::get<1>(leb128_192) };
                              uint8_t id_629 { 0 };
                              Void id_630 { ((void)(p_ref_191[id_629] = leb128_snd_194), ::dessser::VOID) };
                              (void)id_630;
                              uint8_t id_631 { 0 };
                              uint8_t id_632 { 127 };
                              uint8_t id_633 { uint8_t(leb128_fst_193 & id_632) };
                              uint32_t id_634 { uint32_t(id_633) };
                              uint8_t id_635 { 0 };
                              uint8_t id_636 { shft_ref_190[id_635] };
                              uint32_t id_637 { uint32_t(id_634 << id_636) };
                              uint8_t id_638 { 0 };
                              uint32_t id_639 { leb_ref_189[id_638] };
                              uint32_t id_640 { uint32_t(id_637 | id_639) };
                              Void id_641 { ((void)(leb_ref_189[id_631] = id_640), ::dessser::VOID) };
                              (void)id_641;
                              uint8_t id_642 { 0 };
                              uint8_t id_643 { 0 };
                              uint8_t id_644 { shft_ref_190[id_643] };
                              uint8_t id_645 { 7 };
                              uint8_t id_646 { uint8_t(id_644 + id_645) };
                              Void id_647 { ((void)(shft_ref_190[id_642] = id_646), ::dessser::VOID) };
                              (void)id_647;
                              uint8_t id_648 { 128 };
                              bool id_649 { bool(leb128_fst_193 >= id_648) };
                              letpair_res_628 = id_649;
                            }
                            let_res_627 = letpair_res_628;
                          }
                          while_flag_623 = let_res_627;
                          if (while_flag_623) {
                            (void)::dessser::VOID;
                          }
                        } while (while_flag_623);
                        (void)::dessser::VOID;
                        uint8_t id_650 { 0 };
                        uint32_t id_651 { leb_ref_189[id_650] };
                        Size id_652 { Size(id_651) };
                        uint8_t id_653 { 0 };
                        Pointer id_654 { p_ref_191[id_653] };
                        ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa id_655 { id_652, id_654 };
                        let_res_622 = id_655;
                      }
                      let_res_620 = let_res_622;
                    }
                    let_res_617 = let_res_620;
                  }
                  ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 let_res_656;
                  {
                    ::dessser::gen::sync_value::t12fb9c475959b52bf7b17b155a955ffa dstring1_195 { let_res_617 };
                    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_657;
                    {
                      auto dstring1_fst_196 { std::get<0>(dstring1_195) };
                      auto dstring1_snd_197 { std::get<1>(dstring1_195) };
                      ::dessser::gen::sync_value::t9ef6882174ae71a34a3c5ef6b29242fb id_658 { dstring1_snd_197.readBytes(dstring1_fst_196) };
                      ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_659;
                      {
                        auto dstring2_fst_199 { std::get<0>(id_658) };
                        auto dstring2_snd_200 { std::get<1>(id_658) };
                        std::string id_660 { dstring2_fst_199.toString() };
                        ::dessser::gen::sync_value::tbf54298650775373958fa9b35bb96a35 id_661 { dtup_fst_181, dtup_fst_187, id_660 };
                        std::shared_ptr<::dessser::gen::sync_value::t>  id_662 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<0>, id_661) };
                        ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_663 { id_662, dstring2_snd_200 };
                        letpair_res_659 = id_663;
                      }
                      letpair_res_657 = letpair_res_659;
                    }
                    let_res_656 = letpair_res_657;
                  }
                  letpair_res_614 = let_res_656;
                }
                let_res_613 = letpair_res_614;
              }
              letpair_res_609 = let_res_613;
            }
            let_res_608 = letpair_res_609;
          }
          choose_res_603 = let_res_608;
        } else {
          uint16_t id_664 { 1 };
          bool id_665 { bool(id_664 == dsum1_fst_72) };
          ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_666;
          if (id_665) {
            auto fun667 { dessser::gen::worker::of_row_binary };
            ::dessser::gen::sync_value::tf1a9e54f73426165b2d5dbb064eb3fed id_668 { fun667(dsum1_snd_73) };
            ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_669;
            {
              auto dsum2_fst_175 { std::get<0>(id_668) };
              auto dsum2_snd_176 { std::get<1>(id_668) };
              std::shared_ptr<::dessser::gen::sync_value::t>  id_670 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<1>, dsum2_fst_175) };
              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_671 { id_670, dsum2_snd_176 };
              letpair_res_669 = id_671;
            }
            choose_res_666 = letpair_res_669;
          } else {
            uint16_t id_672 { 2 };
            bool id_673 { bool(id_672 == dsum1_fst_72) };
            ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_674;
            if (id_673) {
              auto fun675 { dessser::gen::retention::of_row_binary };
              ::dessser::gen::sync_value::tde821e6d031c399b029ea4a78810ecf6 id_676 { fun675(dsum1_snd_73) };
              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_677;
              {
                auto dsum2_fst_172 { std::get<0>(id_676) };
                auto dsum2_snd_173 { std::get<1>(id_676) };
                std::shared_ptr<::dessser::gen::sync_value::t>  id_678 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<2>, dsum2_fst_172) };
                ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_679 { id_678, dsum2_snd_173 };
                letpair_res_677 = id_679;
              }
              choose_res_674 = letpair_res_677;
            } else {
              uint16_t id_680 { 3 };
              bool id_681 { bool(id_680 == dsum1_fst_72) };
              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_682;
              if (id_681) {
                auto fun683 { dessser::gen::time_range::of_row_binary };
                ::dessser::gen::sync_value::t7ed2098d1a18c9b684db63350a7b96cb id_684 { fun683(dsum1_snd_73) };
                ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_685;
                {
                  auto dsum2_fst_169 { std::get<0>(id_684) };
                  auto dsum2_snd_170 { std::get<1>(id_684) };
                  std::shared_ptr<::dessser::gen::sync_value::t>  id_686 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<3>, dsum2_fst_169) };
                  ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_687 { id_686, dsum2_snd_170 };
                  letpair_res_685 = id_687;
                }
                choose_res_682 = letpair_res_685;
              } else {
                uint16_t id_688 { 4 };
                bool id_689 { bool(id_688 == dsum1_fst_72) };
                ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_690;
                if (id_689) {
                  uint32_t id_691 { 0U };
                  Vec<1, uint32_t> id_692 {  id_691  };
                  ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_693;
                  {
                    Vec<1, uint32_t> leb_ref_142 { id_692 };
                    uint8_t id_694 { 0 };
                    Vec<1, uint8_t> id_695 {  id_694  };
                    ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_696;
                    {
                      Vec<1, uint8_t> shft_ref_143 { id_695 };
                      Vec<1, Pointer> id_697 {  dsum1_snd_73  };
                      ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_698;
                      {
                        Vec<1, Pointer> p_ref_144 { id_697 };
                        bool while_flag_699 { true };
                        do {
                          uint8_t id_700 { 0 };
                          Pointer id_701 { p_ref_144[id_700] };
                          ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 id_702 { id_701.readU8() };
                          bool let_res_703;
                          {
                            ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_145 { id_702 };
                            bool letpair_res_704;
                            {
                              auto leb128_fst_146 { std::get<0>(leb128_145) };
                              auto leb128_snd_147 { std::get<1>(leb128_145) };
                              uint8_t id_705 { 0 };
                              Void id_706 { ((void)(p_ref_144[id_705] = leb128_snd_147), ::dessser::VOID) };
                              (void)id_706;
                              uint8_t id_707 { 0 };
                              uint8_t id_708 { 127 };
                              uint8_t id_709 { uint8_t(leb128_fst_146 & id_708) };
                              uint32_t id_710 { uint32_t(id_709) };
                              uint8_t id_711 { 0 };
                              uint8_t id_712 { shft_ref_143[id_711] };
                              uint32_t id_713 { uint32_t(id_710 << id_712) };
                              uint8_t id_714 { 0 };
                              uint32_t id_715 { leb_ref_142[id_714] };
                              uint32_t id_716 { uint32_t(id_713 | id_715) };
                              Void id_717 { ((void)(leb_ref_142[id_707] = id_716), ::dessser::VOID) };
                              (void)id_717;
                              uint8_t id_718 { 0 };
                              uint8_t id_719 { 0 };
                              uint8_t id_720 { shft_ref_143[id_719] };
                              uint8_t id_721 { 7 };
                              uint8_t id_722 { uint8_t(id_720 + id_721) };
                              Void id_723 { ((void)(shft_ref_143[id_718] = id_722), ::dessser::VOID) };
                              (void)id_723;
                              uint8_t id_724 { 128 };
                              bool id_725 { bool(leb128_fst_146 >= id_724) };
                              letpair_res_704 = id_725;
                            }
                            let_res_703 = letpair_res_704;
                          }
                          while_flag_699 = let_res_703;
                          if (while_flag_699) {
                            (void)::dessser::VOID;
                          }
                        } while (while_flag_699);
                        (void)::dessser::VOID;
                        uint8_t id_726 { 0 };
                        uint32_t id_727 { leb_ref_142[id_726] };
                        uint8_t id_728 { 0 };
                        Pointer id_729 { p_ref_144[id_728] };
                        ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_730 { id_727, id_729 };
                        let_res_698 = id_730;
                      }
                      let_res_696 = let_res_698;
                    }
                    let_res_693 = let_res_696;
                  }
                  ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 let_res_731;
                  {
                    ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 dlist1_151 { let_res_693 };
                    ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 letpair_res_732;
                    {
                      auto dlist1_fst_152 { std::get<0>(dlist1_151) };
                      auto dlist1_snd_153 { std::get<1>(dlist1_151) };
                      Lst<std::shared_ptr<::dessser::gen::sync_value::tuple> > endoflist_733;
                      ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 id_734 { endoflist_733, dlist1_snd_153 };
                      Vec<1, ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3> id_735 {  id_734  };
                      ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 let_res_736;
                      {
                        Vec<1, ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3> inits_src_ref_154 { id_735 };
                        int32_t id_737 { 0L };
                        Vec<1, int32_t> id_738 {  id_737  };
                        {
                          Vec<1, int32_t> repeat_n_155 { id_738 };
                          bool while_flag_739 { true };
                          do {
                            int32_t id_740 { int32_t(dlist1_fst_152) };
                            uint8_t id_741 { 0 };
                            int32_t id_742 { repeat_n_155[id_741] };
                            bool id_743 { bool(id_740 > id_742) };
                            while_flag_739 = id_743;
                            if (while_flag_739) {
                              uint8_t id_744 { 0 };
                              ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 id_745 { inits_src_ref_154[id_744] };
                              {
                                ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 dlist2_156 { id_745 };
                                {
                                  auto dlist2_fst_157 { std::get<0>(dlist2_156) };
                                  auto dlist2_snd_158 { std::get<1>(dlist2_156) };
                                  uint8_t id_746 { 0 };
                                  ::dessser::gen::sync_value::t69580374758c5cd49d653ee83c7fa90f id_747 { tuple_of_row_binary(dlist2_snd_158) };
                                  ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 letpair_res_748;
                                  {
                                    auto dlist3_fst_160 { std::get<0>(id_747) };
                                    auto dlist3_snd_161 { std::get<1>(id_747) };
                                    Lst<std::shared_ptr<::dessser::gen::sync_value::tuple> > id_749 { dlist3_fst_160, dlist2_fst_157 };
                                    ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 id_750 { id_749, dlist3_snd_161 };
                                    letpair_res_748 = id_750;
                                  }
                                  Void id_751 { ((void)(inits_src_ref_154[id_746] = letpair_res_748), ::dessser::VOID) };
                                  (void)id_751;
                                }
                                (void)::dessser::VOID;
                              }
                              (void)::dessser::VOID;
                              uint8_t id_752 { 0 };
                              uint8_t id_753 { 0 };
                              int32_t id_754 { repeat_n_155[id_753] };
                              int32_t id_755 { 1L };
                              int32_t id_756 { int32_t(id_754 + id_755) };
                              Void id_757 { ((void)(repeat_n_155[id_752] = id_756), ::dessser::VOID) };
                              (void)id_757;
                              (void)id_757;
                            }
                          } while (while_flag_739);
                          (void)::dessser::VOID;
                        }
                        (void)::dessser::VOID;
                        uint8_t id_758 { 0 };
                        ::dessser::gen::sync_value::t1bf5fe51ea8ba8f996ee38d2f7ebf6a3 id_759 { inits_src_ref_154[id_758] };
                        let_res_736 = id_759;
                      }
                      letpair_res_732 = let_res_736;
                    }
                    let_res_731 = letpair_res_732;
                  }
                  ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_760;
                  {
                    auto dlist4_fst_163 { std::get<0>(let_res_731) };
                    auto dlist4_snd_164 { std::get<1>(let_res_731) };
                    Arr<std::shared_ptr<::dessser::gen::sync_value::tuple> > id_761 { dlist4_fst_163.toListRev() };
                    std::shared_ptr<::dessser::gen::sync_value::t>  id_762 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<4>, id_761) };
                    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_763 { id_762, dlist4_snd_164 };
                    letpair_res_760 = id_763;
                  }
                  choose_res_690 = letpair_res_760;
                } else {
                  uint16_t id_764 { 5 };
                  bool id_765 { bool(id_764 == dsum1_fst_72) };
                  ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_766;
                  if (id_765) {
                    auto fun767 { dessser::gen::raql_value::of_row_binary };
                    ::dessser::gen::sync_value::tf3063cfb73e0f06d3ea99ebd15a86d50 id_768 { fun767(dsum1_snd_73) };
                    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_769;
                    {
                      auto dsum2_fst_140 { std::get<0>(id_768) };
                      auto dsum2_snd_141 { std::get<1>(id_768) };
                      std::shared_ptr<::dessser::gen::sync_value::t>  id_770 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<5>, dsum2_fst_140) };
                      ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_771 { id_770, dsum2_snd_141 };
                      letpair_res_769 = id_771;
                    }
                    choose_res_766 = letpair_res_769;
                  } else {
                    uint16_t id_772 { 6 };
                    bool id_773 { bool(id_772 == dsum1_fst_72) };
                    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_774;
                    if (id_773) {
                      uint32_t id_775 { 0U };
                      Vec<1, uint32_t> id_776 {  id_775  };
                      ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_777;
                      {
                        Vec<1, uint32_t> leb_ref_113 { id_776 };
                        uint8_t id_778 { 0 };
                        Vec<1, uint8_t> id_779 {  id_778  };
                        ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_780;
                        {
                          Vec<1, uint8_t> shft_ref_114 { id_779 };
                          Vec<1, Pointer> id_781 {  dsum1_snd_73  };
                          ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 let_res_782;
                          {
                            Vec<1, Pointer> p_ref_115 { id_781 };
                            bool while_flag_783 { true };
                            do {
                              uint8_t id_784 { 0 };
                              Pointer id_785 { p_ref_115[id_784] };
                              ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 id_786 { id_785.readU8() };
                              bool let_res_787;
                              {
                                ::dessser::gen::sync_value::t1a5d74abf838df33f185a72a8912f5c9 leb128_116 { id_786 };
                                bool letpair_res_788;
                                {
                                  auto leb128_fst_117 { std::get<0>(leb128_116) };
                                  auto leb128_snd_118 { std::get<1>(leb128_116) };
                                  uint8_t id_789 { 0 };
                                  Void id_790 { ((void)(p_ref_115[id_789] = leb128_snd_118), ::dessser::VOID) };
                                  (void)id_790;
                                  uint8_t id_791 { 0 };
                                  uint8_t id_792 { 127 };
                                  uint8_t id_793 { uint8_t(leb128_fst_117 & id_792) };
                                  uint32_t id_794 { uint32_t(id_793) };
                                  uint8_t id_795 { 0 };
                                  uint8_t id_796 { shft_ref_114[id_795] };
                                  uint32_t id_797 { uint32_t(id_794 << id_796) };
                                  uint8_t id_798 { 0 };
                                  uint32_t id_799 { leb_ref_113[id_798] };
                                  uint32_t id_800 { uint32_t(id_797 | id_799) };
                                  Void id_801 { ((void)(leb_ref_113[id_791] = id_800), ::dessser::VOID) };
                                  (void)id_801;
                                  uint8_t id_802 { 0 };
                                  uint8_t id_803 { 0 };
                                  uint8_t id_804 { shft_ref_114[id_803] };
                                  uint8_t id_805 { 7 };
                                  uint8_t id_806 { uint8_t(id_804 + id_805) };
                                  Void id_807 { ((void)(shft_ref_114[id_802] = id_806), ::dessser::VOID) };
                                  (void)id_807;
                                  uint8_t id_808 { 128 };
                                  bool id_809 { bool(leb128_fst_117 >= id_808) };
                                  letpair_res_788 = id_809;
                                }
                                let_res_787 = letpair_res_788;
                              }
                              while_flag_783 = let_res_787;
                              if (while_flag_783) {
                                (void)::dessser::VOID;
                              }
                            } while (while_flag_783);
                            (void)::dessser::VOID;
                            uint8_t id_810 { 0 };
                            uint32_t id_811 { leb_ref_113[id_810] };
                            uint8_t id_812 { 0 };
                            Pointer id_813 { p_ref_115[id_812] };
                            ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 id_814 { id_811, id_813 };
                            let_res_782 = id_814;
                          }
                          let_res_780 = let_res_782;
                        }
                        let_res_777 = let_res_780;
                      }
                      ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 let_res_815;
                      {
                        ::dessser::gen::sync_value::t491c44439106a32f896827242e8e76a1 dlist1_122 { let_res_777 };
                        ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 letpair_res_816;
                        {
                          auto dlist1_fst_123 { std::get<0>(dlist1_122) };
                          auto dlist1_snd_124 { std::get<1>(dlist1_122) };
                          Lst<dessser::gen::rc_entry::t_ext> endoflist_817;
                          ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 id_818 { endoflist_817, dlist1_snd_124 };
                          Vec<1, ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9> id_819 {  id_818  };
                          ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 let_res_820;
                          {
                            Vec<1, ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9> inits_src_ref_125 { id_819 };
                            int32_t id_821 { 0L };
                            Vec<1, int32_t> id_822 {  id_821  };
                            {
                              Vec<1, int32_t> repeat_n_126 { id_822 };
                              bool while_flag_823 { true };
                              do {
                                int32_t id_824 { int32_t(dlist1_fst_123) };
                                uint8_t id_825 { 0 };
                                int32_t id_826 { repeat_n_126[id_825] };
                                bool id_827 { bool(id_824 > id_826) };
                                while_flag_823 = id_827;
                                if (while_flag_823) {
                                  uint8_t id_828 { 0 };
                                  ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 id_829 { inits_src_ref_125[id_828] };
                                  {
                                    ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 dlist2_127 { id_829 };
                                    {
                                      auto dlist2_fst_128 { std::get<0>(dlist2_127) };
                                      auto dlist2_snd_129 { std::get<1>(dlist2_127) };
                                      uint8_t id_830 { 0 };
                                      auto fun831 { dessser::gen::rc_entry::of_row_binary };
                                      ::dessser::gen::sync_value::t47e3362e539b61ad5bc0fe6744e49d62 id_832 { fun831(dlist2_snd_129) };
                                      ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 letpair_res_833;
                                      {
                                        auto dlist3_fst_131 { std::get<0>(id_832) };
                                        auto dlist3_snd_132 { std::get<1>(id_832) };
                                        Lst<dessser::gen::rc_entry::t_ext> id_834 { dlist3_fst_131, dlist2_fst_128 };
                                        ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 id_835 { id_834, dlist3_snd_132 };
                                        letpair_res_833 = id_835;
                                      }
                                      Void id_836 { ((void)(inits_src_ref_125[id_830] = letpair_res_833), ::dessser::VOID) };
                                      (void)id_836;
                                    }
                                    (void)::dessser::VOID;
                                  }
                                  (void)::dessser::VOID;
                                  uint8_t id_837 { 0 };
                                  uint8_t id_838 { 0 };
                                  int32_t id_839 { repeat_n_126[id_838] };
                                  int32_t id_840 { 1L };
                                  int32_t id_841 { int32_t(id_839 + id_840) };
                                  Void id_842 { ((void)(repeat_n_126[id_837] = id_841), ::dessser::VOID) };
                                  (void)id_842;
                                  (void)id_842;
                                }
                              } while (while_flag_823);
                              (void)::dessser::VOID;
                            }
                            (void)::dessser::VOID;
                            uint8_t id_843 { 0 };
                            ::dessser::gen::sync_value::t09ff74b441bf867176e1b0fd591831e9 id_844 { inits_src_ref_125[id_843] };
                            let_res_820 = id_844;
                          }
                          letpair_res_816 = let_res_820;
                        }
                        let_res_815 = letpair_res_816;
                      }
                      ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_845;
                      {
                        auto dlist4_fst_134 { std::get<0>(let_res_815) };
                        auto dlist4_snd_135 { std::get<1>(let_res_815) };
                        Arr<dessser::gen::rc_entry::t_ext> id_846 { dlist4_fst_134.toListRev() };
                        std::shared_ptr<::dessser::gen::sync_value::t>  id_847 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<6>, id_846) };
                        ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_848 { id_847, dlist4_snd_135 };
                        letpair_res_845 = id_848;
                      }
                      choose_res_774 = letpair_res_845;
                    } else {
                      uint16_t id_849 { 7 };
                      bool id_850 { bool(id_849 == dsum1_fst_72) };
                      ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_851;
                      if (id_850) {
                        auto fun852 { dessser::gen::source_info::of_row_binary };
                        ::dessser::gen::sync_value::tf1b07204c9c2214dfaf5f174f6300e9a id_853 { fun852(dsum1_snd_73) };
                        ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_854;
                        {
                          auto dsum2_fst_111 { std::get<0>(id_853) };
                          auto dsum2_snd_112 { std::get<1>(id_853) };
                          std::shared_ptr<::dessser::gen::sync_value::t>  id_855 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<7>, dsum2_fst_111) };
                          ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_856 { id_855, dsum2_snd_112 };
                          letpair_res_854 = id_856;
                        }
                        choose_res_851 = letpair_res_854;
                      } else {
                        uint16_t id_857 { 8 };
                        bool id_858 { bool(id_857 == dsum1_fst_72) };
                        ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_859;
                        if (id_858) {
                          auto fun860 { dessser::gen::runtime_stats::of_row_binary };
                          ::dessser::gen::sync_value::t0404418c5456e6c318afcd8cf14b75c1 id_861 { fun860(dsum1_snd_73) };
                          ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_862;
                          {
                            auto dsum2_fst_108 { std::get<0>(id_861) };
                            auto dsum2_snd_109 { std::get<1>(id_861) };
                            std::shared_ptr<::dessser::gen::sync_value::t>  id_863 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<8>, dsum2_fst_108) };
                            ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_864 { id_863, dsum2_snd_109 };
                            letpair_res_862 = id_864;
                          }
                          choose_res_859 = letpair_res_862;
                        } else {
                          uint16_t id_865 { 9 };
                          bool id_866 { bool(id_865 == dsum1_fst_72) };
                          ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_867;
                          if (id_866) {
                            auto fun868 { dessser::gen::replay::of_row_binary };
                            ::dessser::gen::sync_value::t4f69e417cce4a8fd9a6492bd06fc9968 id_869 { fun868(dsum1_snd_73) };
                            ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_870;
                            {
                              auto dsum2_fst_105 { std::get<0>(id_869) };
                              auto dsum2_snd_106 { std::get<1>(id_869) };
                              std::shared_ptr<::dessser::gen::sync_value::t>  id_871 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<9>, dsum2_fst_105) };
                              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_872 { id_871, dsum2_snd_106 };
                              letpair_res_870 = id_872;
                            }
                            choose_res_867 = letpair_res_870;
                          } else {
                            uint16_t id_873 { 10 };
                            bool id_874 { bool(id_873 == dsum1_fst_72) };
                            ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_875;
                            if (id_874) {
                              auto fun876 { dessser::gen::replayer::of_row_binary };
                              ::dessser::gen::sync_value::t0d3332e65eb58017bd9ce92925526fe1 id_877 { fun876(dsum1_snd_73) };
                              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_878;
                              {
                                auto dsum2_fst_102 { std::get<0>(id_877) };
                                auto dsum2_snd_103 { std::get<1>(id_877) };
                                std::shared_ptr<::dessser::gen::sync_value::t>  id_879 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<10>, dsum2_fst_102) };
                                ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_880 { id_879, dsum2_snd_103 };
                                letpair_res_878 = id_880;
                              }
                              choose_res_875 = letpair_res_878;
                            } else {
                              uint16_t id_881 { 11 };
                              bool id_882 { bool(id_881 == dsum1_fst_72) };
                              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_883;
                              if (id_882) {
                                auto fun884 { dessser::gen::replay_request::of_row_binary };
                                ::dessser::gen::sync_value::tb04e7483a47551f3c586f859338754a3 id_885 { fun884(dsum1_snd_73) };
                                ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_886;
                                {
                                  auto dsum2_fst_99 { std::get<0>(id_885) };
                                  auto dsum2_snd_100 { std::get<1>(id_885) };
                                  std::shared_ptr<::dessser::gen::sync_value::t>  id_887 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<11>, dsum2_fst_99) };
                                  ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_888 { id_887, dsum2_snd_100 };
                                  letpair_res_886 = id_888;
                                }
                                choose_res_883 = letpair_res_886;
                              } else {
                                uint16_t id_889 { 12 };
                                bool id_890 { bool(id_889 == dsum1_fst_72) };
                                ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_891;
                                if (id_890) {
                                  auto fun892 { dessser::gen::alert::of_row_binary };
                                  ::dessser::gen::sync_value::t444e608a3269594da3e48ff9117a0d03 id_893 { fun892(dsum1_snd_73) };
                                  ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_894;
                                  {
                                    auto dsum2_fst_96 { std::get<0>(id_893) };
                                    auto dsum2_snd_97 { std::get<1>(id_893) };
                                    std::shared_ptr<::dessser::gen::sync_value::t>  id_895 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<12>, dsum2_fst_96) };
                                    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_896 { id_895, dsum2_snd_97 };
                                    letpair_res_894 = id_896;
                                  }
                                  choose_res_891 = letpair_res_894;
                                } else {
                                  uint16_t id_897 { 13 };
                                  bool id_898 { bool(id_897 == dsum1_fst_72) };
                                  ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_899;
                                  if (id_898) {
                                    auto fun900 { dessser::gen::output_specs::of_row_binary };
                                    ::dessser::gen::sync_value::tf66ee8ddea68e7658659620791429c2e id_901 { fun900(dsum1_snd_73) };
                                    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_902;
                                    {
                                      auto dsum2_fst_93 { std::get<0>(id_901) };
                                      auto dsum2_snd_94 { std::get<1>(id_901) };
                                      std::shared_ptr<::dessser::gen::sync_value::t>  id_903 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<13>, dsum2_fst_93) };
                                      ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_904 { id_903, dsum2_snd_94 };
                                      letpair_res_902 = id_904;
                                    }
                                    choose_res_899 = letpair_res_902;
                                  } else {
                                    uint16_t id_905 { 14 };
                                    bool id_906 { bool(id_905 == dsum1_fst_72) };
                                    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_907;
                                    if (id_906) {
                                      auto fun908 { dessser::gen::dashboard_widget::of_row_binary };
                                      ::dessser::gen::sync_value::t7b3e7c64daee99819044254f252b16cd id_909 { fun908(dsum1_snd_73) };
                                      ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_910;
                                      {
                                        auto dsum2_fst_90 { std::get<0>(id_909) };
                                        auto dsum2_snd_91 { std::get<1>(id_909) };
                                        std::shared_ptr<::dessser::gen::sync_value::t>  id_911 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<14>, dsum2_fst_90) };
                                        ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_912 { id_911, dsum2_snd_91 };
                                        letpair_res_910 = id_912;
                                      }
                                      choose_res_907 = letpair_res_910;
                                    } else {
                                      uint16_t id_913 { 15 };
                                      bool id_914 { bool(id_913 == dsum1_fst_72) };
                                      ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_915;
                                      if (id_914) {
                                        auto fun916 { dessser::gen::alerting_contact::of_row_binary };
                                        ::dessser::gen::sync_value::t63085be0ace05d30e702e98f7d406fb6 id_917 { fun916(dsum1_snd_73) };
                                        ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_918;
                                        {
                                          auto dsum2_fst_87 { std::get<0>(id_917) };
                                          auto dsum2_snd_88 { std::get<1>(id_917) };
                                          std::shared_ptr<::dessser::gen::sync_value::t>  id_919 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<15>, dsum2_fst_87) };
                                          ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_920 { id_919, dsum2_snd_88 };
                                          letpair_res_918 = id_920;
                                        }
                                        choose_res_915 = letpair_res_918;
                                      } else {
                                        uint16_t id_921 { 16 };
                                        bool id_922 { bool(id_921 == dsum1_fst_72) };
                                        ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_923;
                                        if (id_922) {
                                          auto fun924 { dessser::gen::alerting_notification::of_row_binary };
                                          ::dessser::gen::sync_value::t2587780bdb272f24e6438b12cbc61e92 id_925 { fun924(dsum1_snd_73) };
                                          ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_926;
                                          {
                                            auto dsum2_fst_84 { std::get<0>(id_925) };
                                            auto dsum2_snd_85 { std::get<1>(id_925) };
                                            std::shared_ptr<::dessser::gen::sync_value::t>  id_927 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<16>, dsum2_fst_84) };
                                            ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_928 { id_927, dsum2_snd_85 };
                                            letpair_res_926 = id_928;
                                          }
                                          choose_res_923 = letpair_res_926;
                                        } else {
                                          uint16_t id_929 { 17 };
                                          bool id_930 { bool(id_929 == dsum1_fst_72) };
                                          ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_931;
                                          if (id_930) {
                                            auto fun932 { dessser::gen::alerting_delivery_status::of_row_binary };
                                            ::dessser::gen::sync_value::te49867912245e444e88027721575ec35 id_933 { fun932(dsum1_snd_73) };
                                            ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_934;
                                            {
                                              auto dsum2_fst_81 { std::get<0>(id_933) };
                                              auto dsum2_snd_82 { std::get<1>(id_933) };
                                              std::shared_ptr<::dessser::gen::sync_value::t>  id_935 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<17>, dsum2_fst_81) };
                                              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_936 { id_935, dsum2_snd_82 };
                                              letpair_res_934 = id_936;
                                            }
                                            choose_res_931 = letpair_res_934;
                                          } else {
                                            uint16_t id_937 { 18 };
                                            bool id_938 { bool(id_937 == dsum1_fst_72) };
                                            ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 choose_res_939;
                                            if (id_938) {
                                              auto fun940 { dessser::gen::alerting_log::of_row_binary };
                                              ::dessser::gen::sync_value::t555ce468db008991e3ea7cea3f54910f id_941 { fun940(dsum1_snd_73) };
                                              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_942;
                                              {
                                                auto dsum2_fst_78 { std::get<0>(id_941) };
                                                auto dsum2_snd_79 { std::get<1>(id_941) };
                                                std::shared_ptr<::dessser::gen::sync_value::t>  id_943 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<18>, dsum2_fst_78) };
                                                ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_944 { id_943, dsum2_snd_79 };
                                                letpair_res_942 = id_944;
                                              }
                                              choose_res_939 = letpair_res_942;
                                            } else {
                                              uint16_t id_945 { 19 };
                                              bool id_946 { bool(dsum1_fst_72 == id_945) };
                                              Void id_947 { ((void)(assert(id_946)), ::dessser::VOID) };
                                              (void)id_947;
                                              auto fun948 { dessser::gen::alerting_inhibition::of_row_binary };
                                              ::dessser::gen::sync_value::t511ff94fe7190561084aee555c49cbe8 id_949 { fun948(dsum1_snd_73) };
                                              ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_950;
                                              {
                                                auto dsum2_fst_75 { std::get<0>(id_949) };
                                                auto dsum2_snd_76 { std::get<1>(id_949) };
                                                std::shared_ptr<::dessser::gen::sync_value::t>  id_951 { std::make_shared<::dessser::gen::sync_value::t>(std::in_place_index<19>, dsum2_fst_75) };
                                                ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_952 { id_951, dsum2_snd_76 };
                                                letpair_res_950 = id_952;
                                              }
                                              choose_res_939 = letpair_res_950;
                                            }
                                            choose_res_931 = choose_res_939;
                                          }
                                          choose_res_923 = choose_res_931;
                                        }
                                        choose_res_915 = choose_res_923;
                                      }
                                      choose_res_907 = choose_res_915;
                                    }
                                    choose_res_899 = choose_res_907;
                                  }
                                  choose_res_891 = choose_res_899;
                                }
                                choose_res_883 = choose_res_891;
                              }
                              choose_res_875 = choose_res_883;
                            }
                            choose_res_867 = choose_res_875;
                          }
                          choose_res_859 = choose_res_867;
                        }
                        choose_res_851 = choose_res_859;
                      }
                      choose_res_774 = choose_res_851;
                    }
                    choose_res_766 = choose_res_774;
                  }
                  choose_res_690 = choose_res_766;
                }
                choose_res_682 = choose_res_690;
              }
              choose_res_674 = choose_res_682;
            }
            choose_res_666 = choose_res_674;
          }
          choose_res_603 = choose_res_666;
        }
        letpair_res_600 = choose_res_603;
      }
      let_res_599 = letpair_res_600;
    }
    return let_res_599;
  }
   };
  return fun595;
}
std::function<::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_208" "make_snd_209" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_208") (identifier "make_snd_209"))))
 */
static std::function<::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3(Pointer)> fun953 { [&](Pointer p_0) {
    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_954 { of_row_binary(p_0) };
    ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 letpair_res_955;
    {
      auto make_fst_208 { std::get<0>(id_954) };
      auto make_snd_209 { std::get<1>(id_954) };
      ::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3 id_956 { make_fst_208, make_snd_209 };
      letpair_res_955 = id_956;
    }
    return letpair_res_955;
  }
   };
  return fun953;
}
std::function<::dessser::gen::sync_value::t15098b8456ebfe3bc6bbe8b1695dacf3(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples (tuple AS {skipped: U32; values: $raql_value})[] | RamenValue $raql_value | TargetConfig $rc_entry[] | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::t> ,Pointer)> fun957 { [&](std::shared_ptr<::dessser::gen::sync_value::t>  p_0, Pointer p_1) {
    Pointer id_958 { to_row_binary(p_0, p_1) };
    return id_958;
  }
   };
  return fun957;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_value::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
