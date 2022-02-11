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
#include "desssergen/field_name.h"
#include "desssergen/raql_net_protocol.h"
#include "desssergen/raql_ip_protocol.h"
#include "desssergen/field_name.h"
#include "desssergen/event_time.h"
#include "desssergen/field_type.h"
#include "desssergen/field_type.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_expr.h"
#include "desssergen/function_name.h"
#include "desssergen/raql_flush_method.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/event_time.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_select_field.h"

namespace dessser::gen::raql_operation {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t78cec4f9827249604fe947034c575f2a {
  char separator;
  std::string null;
  bool may_quote;
  std::string escape_seq;
  Lst<dessser::gen::field_type::t_ext> fields;
  bool vectors_of_chars_as_string;
  bool clickhouse_syntax;
  t78cec4f9827249604fe947034c575f2a(char separator_, std::string null_, bool may_quote_, std::string escape_seq_, Lst<dessser::gen::field_type::t_ext> fields_, bool vectors_of_chars_as_string_, bool clickhouse_syntax_) : separator(separator_), null(null_), may_quote(may_quote_), escape_seq(escape_seq_), fields(fields_), vectors_of_chars_as_string(vectors_of_chars_as_string_), clickhouse_syntax(clickhouse_syntax_) {}
  t78cec4f9827249604fe947034c575f2a() = default;
};
inline bool operator==(t78cec4f9827249604fe947034c575f2a const &a, t78cec4f9827249604fe947034c575f2a const &b) {
  return a.separator == b.separator && a.null == b.null && a.may_quote == b.may_quote && a.escape_seq == b.escape_seq && a.fields == b.fields && a.vectors_of_chars_as_string == b.vectors_of_chars_as_string && a.clickhouse_syntax == b.clickhouse_syntax;
}

inline bool operator!=(t78cec4f9827249604fe947034c575f2a const &a, t78cec4f9827249604fe947034c575f2a const &b) {
  return !operator==(a, b);
}
struct external_format : public std::variant<
  ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a, // CSV
  Lst<dessser::gen::field_type::t_ext> // RowBinary
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(external_format const &a, external_format const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // CSV
    case 1: return std::get<1>(a) == std::get<1>(b); // RowBinary
  };
  return false;
}
inline bool operator!=(external_format const &a, external_format const &b) {
  return !operator==(a, b);
}
struct t614b5d4c127c7065272d8dcc1f9877d3 {
  dessser::gen::raql_expr::t_ext fname;
  std::optional<dessser::gen::raql_expr::t_ext> preprocessor;
  dessser::gen::raql_expr::t_ext unlink;
  t614b5d4c127c7065272d8dcc1f9877d3(dessser::gen::raql_expr::t_ext fname_, std::optional<dessser::gen::raql_expr::t_ext> preprocessor_, dessser::gen::raql_expr::t_ext unlink_) : fname(fname_), preprocessor(preprocessor_), unlink(unlink_) {}
  t614b5d4c127c7065272d8dcc1f9877d3() = default;
};
inline bool operator==(t614b5d4c127c7065272d8dcc1f9877d3 const &a, t614b5d4c127c7065272d8dcc1f9877d3 const &b) {
  return ::dessser::gen::raql_expr::Deref(a.fname) == ::dessser::gen::raql_expr::Deref(b.fname) && ((a.preprocessor && b.preprocessor && ::dessser::gen::raql_expr::Deref(a.preprocessor.value()) == ::dessser::gen::raql_expr::Deref(b.preprocessor.value())) || (!a.preprocessor && !b.preprocessor)) && ::dessser::gen::raql_expr::Deref(a.unlink) == ::dessser::gen::raql_expr::Deref(b.unlink);
}

inline bool operator!=(t614b5d4c127c7065272d8dcc1f9877d3 const &a, t614b5d4c127c7065272d8dcc1f9877d3 const &b) {
  return !operator==(a, b);
}
struct t42c3ffb6cb514e3c128f0c7344ce492a : public std::tuple<
  std::string,
  dessser::gen::raql_expr::t_ext
> {
  using tuple::tuple;
};
inline bool operator==(t42c3ffb6cb514e3c128f0c7344ce492a const &a, t42c3ffb6cb514e3c128f0c7344ce492a const &b) {
  return std::get<0>(a) == std::get<0>(b) && ::dessser::gen::raql_expr::Deref(std::get<1>(a)) == ::dessser::gen::raql_expr::Deref(std::get<1>(b));
}
inline bool operator!=(t42c3ffb6cb514e3c128f0c7344ce492a const &a, t42c3ffb6cb514e3c128f0c7344ce492a const &b) {
  return !operator==(a, b);
}
struct t66e84af8ac3d220e6953b809395192f8 {
  dessser::gen::raql_expr::t_ext after_max_secs;
  dessser::gen::raql_expr::t_ext after_max_events;
  t66e84af8ac3d220e6953b809395192f8(dessser::gen::raql_expr::t_ext after_max_secs_, dessser::gen::raql_expr::t_ext after_max_events_) : after_max_secs(after_max_secs_), after_max_events(after_max_events_) {}
  t66e84af8ac3d220e6953b809395192f8() = default;
};
inline bool operator==(t66e84af8ac3d220e6953b809395192f8 const &a, t66e84af8ac3d220e6953b809395192f8 const &b) {
  return ::dessser::gen::raql_expr::Deref(a.after_max_secs) == ::dessser::gen::raql_expr::Deref(b.after_max_secs) && ::dessser::gen::raql_expr::Deref(a.after_max_events) == ::dessser::gen::raql_expr::Deref(b.after_max_events);
}

inline bool operator!=(t66e84af8ac3d220e6953b809395192f8 const &a, t66e84af8ac3d220e6953b809395192f8 const &b) {
  return !operator==(a, b);
}
struct tbbc319188017fc622f05dfada38341dc : public std::variant<
  Void, // Beginning
  dessser::gen::raql_expr::t_ext, // OffsetFromEnd
  Void, // SaveInState
  ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 // UseKafkaGroupCoordinator
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 4 };
};

inline bool operator==(tbbc319188017fc622f05dfada38341dc const &a, tbbc319188017fc622f05dfada38341dc const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Beginning
    case 1: return ::dessser::gen::raql_expr::Deref(std::get<1>(a)) == ::dessser::gen::raql_expr::Deref(std::get<1>(b)); // OffsetFromEnd
    case 2: return std::get<2>(a) == std::get<2>(b); // SaveInState
    case 3: return std::get<3>(a) == std::get<3>(b); // UseKafkaGroupCoordinator
  };
  return false;
}
inline bool operator!=(tbbc319188017fc622f05dfada38341dc const &a, tbbc319188017fc622f05dfada38341dc const &b) {
  return !operator==(a, b);
}
struct ta64ee09b20632228f3a50181be1b6548 {
  Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> options;
  dessser::gen::raql_expr::t_ext topic;
  std::optional<dessser::gen::raql_expr::t_ext> partitions;
  ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc restart_from;
  ta64ee09b20632228f3a50181be1b6548(Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> options_, dessser::gen::raql_expr::t_ext topic_, std::optional<dessser::gen::raql_expr::t_ext> partitions_, ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc restart_from_) : options(options_), topic(topic_), partitions(partitions_), restart_from(restart_from_) {}
  ta64ee09b20632228f3a50181be1b6548() = default;
};
inline bool operator==(ta64ee09b20632228f3a50181be1b6548 const &a, ta64ee09b20632228f3a50181be1b6548 const &b) {
  return a.options == b.options && ::dessser::gen::raql_expr::Deref(a.topic) == ::dessser::gen::raql_expr::Deref(b.topic) && ((a.partitions && b.partitions && ::dessser::gen::raql_expr::Deref(a.partitions.value()) == ::dessser::gen::raql_expr::Deref(b.partitions.value())) || (!a.partitions && !b.partitions)) && a.restart_from == b.restart_from;
}

inline bool operator!=(ta64ee09b20632228f3a50181be1b6548 const &a, ta64ee09b20632228f3a50181be1b6548 const &b) {
  return !operator==(a, b);
}
struct external_source : public std::variant<
  ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3, // File
  ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 // Kafka
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(external_source const &a, external_source const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // File
    case 1: return std::get<1>(a) == std::get<1>(b); // Kafka
  };
  return false;
}
inline bool operator!=(external_source const &a, external_source const &b) {
  return !operator==(a, b);
}
struct t451e3326ef72e0df775e9ee8e2a61bf4 : public std::tuple<
  ::dessser::gen::raql_operation::external_format,
  Pointer
> {
  using tuple::tuple;
  t451e3326ef72e0df775e9ee8e2a61bf4(std::tuple<::dessser::gen::raql_operation::external_format, Pointer> p)
    : std::tuple<::dessser::gen::raql_operation::external_format, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t451e3326ef72e0df775e9ee8e2a61bf4 const &a, t451e3326ef72e0df775e9ee8e2a61bf4 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t451e3326ef72e0df775e9ee8e2a61bf4 const &a, t451e3326ef72e0df775e9ee8e2a61bf4 const &b) {
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
struct tfa74ce2af9d2c970f57cbdfa42fae458 : public std::tuple<
  char,
  Pointer
> {
  using tuple::tuple;
  tfa74ce2af9d2c970f57cbdfa42fae458(std::tuple<char, Pointer> p)
    : std::tuple<char, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tfa74ce2af9d2c970f57cbdfa42fae458 const &a, tfa74ce2af9d2c970f57cbdfa42fae458 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tfa74ce2af9d2c970f57cbdfa42fae458 const &a, tfa74ce2af9d2c970f57cbdfa42fae458 const &b) {
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
struct t13a07ee37ab40962540da8534858dc07 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t13a07ee37ab40962540da8534858dc07(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
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
struct tf9a0a3fefc87c9e10a93d3a172850c26 : public std::tuple<
  bool,
  Pointer
> {
  using tuple::tuple;
  tf9a0a3fefc87c9e10a93d3a172850c26(std::tuple<bool, Pointer> p)
    : std::tuple<bool, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf9a0a3fefc87c9e10a93d3a172850c26 const &a, tf9a0a3fefc87c9e10a93d3a172850c26 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf9a0a3fefc87c9e10a93d3a172850c26 const &a, tf9a0a3fefc87c9e10a93d3a172850c26 const &b) {
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
struct t85ae7cee8f9175cc6090b55d00747cf9 : public std::tuple<
  Lst<dessser::gen::field_type::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t85ae7cee8f9175cc6090b55d00747cf9(std::tuple<Lst<dessser::gen::field_type::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::field_type::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t85ae7cee8f9175cc6090b55d00747cf9 const &a, t85ae7cee8f9175cc6090b55d00747cf9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t85ae7cee8f9175cc6090b55d00747cf9 const &a, t85ae7cee8f9175cc6090b55d00747cf9 const &b) {
  return !operator==(a, b);
}
struct t20a180051b815e05487bcfd57d0d9adb : public std::tuple<
  dessser::gen::field_type::t_ext,
  Pointer
> {
  using tuple::tuple;
  t20a180051b815e05487bcfd57d0d9adb(std::tuple<dessser::gen::field_type::t_ext, Pointer> p)
    : std::tuple<dessser::gen::field_type::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t20a180051b815e05487bcfd57d0d9adb const &a, t20a180051b815e05487bcfd57d0d9adb const &b) {
  return ::dessser::gen::field_type::Deref(std::get<0>(a)) == ::dessser::gen::field_type::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t20a180051b815e05487bcfd57d0d9adb const &a, t20a180051b815e05487bcfd57d0d9adb const &b) {
  return !operator==(a, b);
}
struct t6005154d7547b64400cf202525298d69 : public std::tuple<
  ::dessser::gen::raql_operation::external_source,
  Pointer
> {
  using tuple::tuple;
  t6005154d7547b64400cf202525298d69(std::tuple<::dessser::gen::raql_operation::external_source, Pointer> p)
    : std::tuple<::dessser::gen::raql_operation::external_source, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6005154d7547b64400cf202525298d69 const &a, t6005154d7547b64400cf202525298d69 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6005154d7547b64400cf202525298d69 const &a, t6005154d7547b64400cf202525298d69 const &b) {
  return !operator==(a, b);
}
struct tc473a3a3b5068e57b15e934d0afcc038 : public std::tuple<
  dessser::gen::raql_expr::t_ext,
  Pointer
> {
  using tuple::tuple;
  tc473a3a3b5068e57b15e934d0afcc038(std::tuple<dessser::gen::raql_expr::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_expr::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc473a3a3b5068e57b15e934d0afcc038 const &a, tc473a3a3b5068e57b15e934d0afcc038 const &b) {
  return ::dessser::gen::raql_expr::Deref(std::get<0>(a)) == ::dessser::gen::raql_expr::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc473a3a3b5068e57b15e934d0afcc038 const &a, tc473a3a3b5068e57b15e934d0afcc038 const &b) {
  return !operator==(a, b);
}
struct tffcb9977d856d30366202f1b8eb57823 : public std::tuple<
  std::optional<dessser::gen::raql_expr::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tffcb9977d856d30366202f1b8eb57823(std::tuple<std::optional<dessser::gen::raql_expr::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::raql_expr::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tffcb9977d856d30366202f1b8eb57823 const &a, tffcb9977d856d30366202f1b8eb57823 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && ::dessser::gen::raql_expr::Deref(std::get<0>(a).value()) == ::dessser::gen::raql_expr::Deref(std::get<0>(b).value())) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tffcb9977d856d30366202f1b8eb57823 const &a, tffcb9977d856d30366202f1b8eb57823 const &b) {
  return !operator==(a, b);
}
struct tf13fbb09f51834e815a6b7b178fd9c4c : public std::tuple<
  Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a>,
  Pointer
> {
  using tuple::tuple;
  tf13fbb09f51834e815a6b7b178fd9c4c(std::tuple<Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf13fbb09f51834e815a6b7b178fd9c4c const &a, tf13fbb09f51834e815a6b7b178fd9c4c const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf13fbb09f51834e815a6b7b178fd9c4c const &a, tf13fbb09f51834e815a6b7b178fd9c4c const &b) {
  return !operator==(a, b);
}
struct t63851e9ebc3cda254eb20d83ee5492de : public std::tuple<
  ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc,
  Pointer
> {
  using tuple::tuple;
  t63851e9ebc3cda254eb20d83ee5492de(std::tuple<::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc, Pointer> p)
    : std::tuple<::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t63851e9ebc3cda254eb20d83ee5492de const &a, t63851e9ebc3cda254eb20d83ee5492de const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t63851e9ebc3cda254eb20d83ee5492de const &a, t63851e9ebc3cda254eb20d83ee5492de const &b) {
  return !operator==(a, b);
}
struct t8c6ca1751131c806bba8633db9760cf7 : public std::variant<
  Void, // AllSites
  std::string, // TheseSites
  Void // ThisSite
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

inline bool operator==(t8c6ca1751131c806bba8633db9760cf7 const &a, t8c6ca1751131c806bba8633db9760cf7 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // AllSites
    case 1: return std::get<1>(a) == std::get<1>(b); // TheseSites
    case 2: return std::get<2>(a) == std::get<2>(b); // ThisSite
  };
  return false;
}
inline bool operator!=(t8c6ca1751131c806bba8633db9760cf7 const &a, t8c6ca1751131c806bba8633db9760cf7 const &b) {
  return !operator==(a, b);
}
struct t0ca94dea84b5aab39c17a3e69f7dc2d6 : public std::tuple<
  ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7,
  std::optional<std::string>,
  dessser::gen::function_name::t_ext
> {
  using tuple::tuple;
};
inline bool operator==(t0ca94dea84b5aab39c17a3e69f7dc2d6 const &a, t0ca94dea84b5aab39c17a3e69f7dc2d6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && ((std::get<1>(a) && std::get<1>(b) && std::get<1>(a).value() == std::get<1>(b).value()) || (!std::get<1>(a) && !std::get<1>(b))) && ::dessser::gen::function_name::Deref(std::get<2>(a)) == ::dessser::gen::function_name::Deref(std::get<2>(b));
}
inline bool operator!=(t0ca94dea84b5aab39c17a3e69f7dc2d6 const &a, t0ca94dea84b5aab39c17a3e69f7dc2d6 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct data_source : public std::variant<
  ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6, // NamedOperation
  std::shared_ptr<::dessser::gen::raql_operation::t>  // SubQuery
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(data_source const &a, data_source const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // NamedOperation
    case 1: return (*std::get<1>(a)) == (*std::get<1>(b)); // SubQuery
  };
  return false;
}
inline bool operator!=(data_source const &a, data_source const &b) {
  return !operator==(a, b);
}
struct t75cceda8358977a4781ef44dda7fab07 : public std::tuple<
  uint32_t,
  std::optional<dessser::gen::raql_expr::t_ext>,
  Lst<dessser::gen::raql_expr::t_ext>
> {
  using tuple::tuple;
};
inline bool operator==(t75cceda8358977a4781ef44dda7fab07 const &a, t75cceda8358977a4781ef44dda7fab07 const &b) {
  return std::get<0>(a) == std::get<0>(b) && ((std::get<1>(a) && std::get<1>(b) && ::dessser::gen::raql_expr::Deref(std::get<1>(a).value()) == ::dessser::gen::raql_expr::Deref(std::get<1>(b).value())) || (!std::get<1>(a) && !std::get<1>(b))) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t75cceda8358977a4781ef44dda7fab07 const &a, t75cceda8358977a4781ef44dda7fab07 const &b) {
  return !operator==(a, b);
}
struct t58a57ec09888f557d57bf4376ca44b24 {
  Lst<dessser::gen::raql_select_field::t_ext> Aggregate_fields;
  std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others;
  std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> sort;
  dessser::gen::raql_expr::t_ext where;
  std::optional<dessser::gen::event_time::t_ext> Aggregate_event_time;
  Lst<dessser::gen::raql_expr::t_ext> notifications;
  Lst<dessser::gen::raql_expr::t_ext> key;
  dessser::gen::raql_expr::t_ext commit_cond;
  bool commit_before;
  dessser::gen::raql_flush_method::t_ext flush_how;
  Lst<::dessser::gen::raql_operation::data_source> from;
  std::optional<dessser::gen::raql_expr::t_ext> every;
  Lst<dessser::gen::field_name::t_ext> Aggregate_factors;
  t58a57ec09888f557d57bf4376ca44b24(Lst<dessser::gen::raql_select_field::t_ext> Aggregate_fields_, std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others_, std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> sort_, dessser::gen::raql_expr::t_ext where_, std::optional<dessser::gen::event_time::t_ext> Aggregate_event_time_, Lst<dessser::gen::raql_expr::t_ext> notifications_, Lst<dessser::gen::raql_expr::t_ext> key_, dessser::gen::raql_expr::t_ext commit_cond_, bool commit_before_, dessser::gen::raql_flush_method::t_ext flush_how_, Lst<::dessser::gen::raql_operation::data_source> from_, std::optional<dessser::gen::raql_expr::t_ext> every_, Lst<dessser::gen::field_name::t_ext> Aggregate_factors_) : Aggregate_fields(Aggregate_fields_), and_all_others(and_all_others_), sort(sort_), where(where_), Aggregate_event_time(Aggregate_event_time_), notifications(notifications_), key(key_), commit_cond(commit_cond_), commit_before(commit_before_), flush_how(flush_how_), from(from_), every(every_), Aggregate_factors(Aggregate_factors_) {}
  t58a57ec09888f557d57bf4376ca44b24() = default;
};
inline bool operator==(t58a57ec09888f557d57bf4376ca44b24 const &a, t58a57ec09888f557d57bf4376ca44b24 const &b) {
  return a.Aggregate_fields == b.Aggregate_fields && ((a.and_all_others && b.and_all_others && a.and_all_others.value() == b.and_all_others.value()) || (!a.and_all_others && !b.and_all_others)) && ((a.sort && b.sort && a.sort.value() == b.sort.value()) || (!a.sort && !b.sort)) && ::dessser::gen::raql_expr::Deref(a.where) == ::dessser::gen::raql_expr::Deref(b.where) && ((a.Aggregate_event_time && b.Aggregate_event_time && ::dessser::gen::event_time::Deref(a.Aggregate_event_time.value()) == ::dessser::gen::event_time::Deref(b.Aggregate_event_time.value())) || (!a.Aggregate_event_time && !b.Aggregate_event_time)) && a.notifications == b.notifications && a.key == b.key && ::dessser::gen::raql_expr::Deref(a.commit_cond) == ::dessser::gen::raql_expr::Deref(b.commit_cond) && a.commit_before == b.commit_before && ::dessser::gen::raql_flush_method::Deref(a.flush_how) == ::dessser::gen::raql_flush_method::Deref(b.flush_how) && a.from == b.from && ((a.every && b.every && ::dessser::gen::raql_expr::Deref(a.every.value()) == ::dessser::gen::raql_expr::Deref(b.every.value())) || (!a.every && !b.every)) && a.Aggregate_factors == b.Aggregate_factors;
}

inline bool operator!=(t58a57ec09888f557d57bf4376ca44b24 const &a, t58a57ec09888f557d57bf4376ca44b24 const &b) {
  return !operator==(a, b);
}
struct t146ce039ffc00c7cf249e9dc380db920 {
  ::dessser::gen::raql_operation::external_source source;
  ::dessser::gen::raql_operation::external_format format;
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::field_name::t_ext> ReadExternal_factors;
  t146ce039ffc00c7cf249e9dc380db920(::dessser::gen::raql_operation::external_source source_, ::dessser::gen::raql_operation::external_format format_, std::optional<dessser::gen::event_time::t_ext> event_time_, Lst<dessser::gen::field_name::t_ext> ReadExternal_factors_) : source(source_), format(format_), event_time(event_time_), ReadExternal_factors(ReadExternal_factors_) {}
  t146ce039ffc00c7cf249e9dc380db920() = default;
};
inline bool operator==(t146ce039ffc00c7cf249e9dc380db920 const &a, t146ce039ffc00c7cf249e9dc380db920 const &b) {
  return a.source == b.source && a.format == b.format && ((a.event_time && b.event_time && ::dessser::gen::event_time::Deref(a.event_time.value()) == ::dessser::gen::event_time::Deref(b.event_time.value())) || (!a.event_time && !b.event_time)) && a.ReadExternal_factors == b.ReadExternal_factors;
}

inline bool operator!=(t146ce039ffc00c7cf249e9dc380db920 const &a, t146ce039ffc00c7cf249e9dc380db920 const &b) {
  return !operator==(a, b);
}
struct tb24aca08586dad8e1ea84f2fd44f4bd3 {
  std::string net_addr;
  uint16_t port;
  dessser::gen::raql_ip_protocol::t_ext ip_proto;
  dessser::gen::raql_net_protocol::t_ext proto;
  Lst<dessser::gen::field_name::t_ext> factors;
  tb24aca08586dad8e1ea84f2fd44f4bd3(std::string net_addr_, uint16_t port_, dessser::gen::raql_ip_protocol::t_ext ip_proto_, dessser::gen::raql_net_protocol::t_ext proto_, Lst<dessser::gen::field_name::t_ext> factors_) : net_addr(net_addr_), port(port_), ip_proto(ip_proto_), proto(proto_), factors(factors_) {}
  tb24aca08586dad8e1ea84f2fd44f4bd3() = default;
};
inline bool operator==(tb24aca08586dad8e1ea84f2fd44f4bd3 const &a, tb24aca08586dad8e1ea84f2fd44f4bd3 const &b) {
  return a.net_addr == b.net_addr && a.port == b.port && ::dessser::gen::raql_ip_protocol::Deref(a.ip_proto) == ::dessser::gen::raql_ip_protocol::Deref(b.ip_proto) && ::dessser::gen::raql_net_protocol::Deref(a.proto) == ::dessser::gen::raql_net_protocol::Deref(b.proto) && a.factors == b.factors;
}

inline bool operator!=(tb24aca08586dad8e1ea84f2fd44f4bd3 const &a, tb24aca08586dad8e1ea84f2fd44f4bd3 const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24, // Aggregate
  ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920, // ReadExternal
  ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 // ListenFor
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Aggregate
    case 1: return std::get<1>(a) == std::get<1>(b); // ReadExternal
    case 2: return std::get<2>(a) == std::get<2>(b); // ListenFor
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t>  &,Pointer &)> wrap_to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(::dessser::gen::raql_operation::data_source &,Pointer &)> data_source_to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t>  &,Pointer &)> to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(::dessser::gen::raql_operation::data_source &)> data_source_sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::t>  &)> sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t063f95ee917f7168b9cc40076caa81fd : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_operation::t> ,
  Pointer
> {
  using tuple::tuple;
  t063f95ee917f7168b9cc40076caa81fd(std::tuple<std::shared_ptr<::dessser::gen::raql_operation::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_operation::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t063f95ee917f7168b9cc40076caa81fd const &a, t063f95ee917f7168b9cc40076caa81fd const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t063f95ee917f7168b9cc40076caa81fd const &a, t063f95ee917f7168b9cc40076caa81fd const &b) {
  return !operator==(a, b);
}
extern std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer &)> wrap_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t040f327c301430239c5fa4296312592c : public std::tuple<
  ::dessser::gen::raql_operation::data_source,
  Pointer
> {
  using tuple::tuple;
  t040f327c301430239c5fa4296312592c(std::tuple<::dessser::gen::raql_operation::data_source, Pointer> p)
    : std::tuple<::dessser::gen::raql_operation::data_source, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t040f327c301430239c5fa4296312592c const &a, t040f327c301430239c5fa4296312592c const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t040f327c301430239c5fa4296312592c const &a, t040f327c301430239c5fa4296312592c const &b) {
  return !operator==(a, b);
}
extern std::function<::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c(Pointer &)> data_source_of_row_binary;
struct t844d6b87e600be23c995de9c1a6436d6 : public std::tuple<
  ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7,
  Pointer
> {
  using tuple::tuple;
  t844d6b87e600be23c995de9c1a6436d6(std::tuple<::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7, Pointer> p)
    : std::tuple<::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t844d6b87e600be23c995de9c1a6436d6 const &a, t844d6b87e600be23c995de9c1a6436d6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t844d6b87e600be23c995de9c1a6436d6 const &a, t844d6b87e600be23c995de9c1a6436d6 const &b) {
  return !operator==(a, b);
}
struct ta18b971ad5bf537b68fb1bbf5fd2b926 : public std::tuple<
  std::optional<std::string>,
  Pointer
> {
  using tuple::tuple;
  ta18b971ad5bf537b68fb1bbf5fd2b926(std::tuple<std::optional<std::string>, Pointer> p)
    : std::tuple<std::optional<std::string>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta18b971ad5bf537b68fb1bbf5fd2b926 const &a, ta18b971ad5bf537b68fb1bbf5fd2b926 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta18b971ad5bf537b68fb1bbf5fd2b926 const &a, ta18b971ad5bf537b68fb1bbf5fd2b926 const &b) {
  return !operator==(a, b);
}
struct t7ced0f6935c1265b26e1abfcc364f52e : public std::tuple<
  dessser::gen::function_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t7ced0f6935c1265b26e1abfcc364f52e(std::tuple<dessser::gen::function_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::function_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7ced0f6935c1265b26e1abfcc364f52e const &a, t7ced0f6935c1265b26e1abfcc364f52e const &b) {
  return ::dessser::gen::function_name::Deref(std::get<0>(a)) == ::dessser::gen::function_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7ced0f6935c1265b26e1abfcc364f52e const &a, t7ced0f6935c1265b26e1abfcc364f52e const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer &)> of_row_binary;
struct t2b03e6197598f957b7ddc8235cc3f32d : public std::tuple<
  Lst<dessser::gen::raql_select_field::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t2b03e6197598f957b7ddc8235cc3f32d(std::tuple<Lst<dessser::gen::raql_select_field::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::raql_select_field::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2b03e6197598f957b7ddc8235cc3f32d const &a, t2b03e6197598f957b7ddc8235cc3f32d const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2b03e6197598f957b7ddc8235cc3f32d const &a, t2b03e6197598f957b7ddc8235cc3f32d const &b) {
  return !operator==(a, b);
}
struct t8ce288a7922f2eebd9fbfe87e5972d1b : public std::tuple<
  dessser::gen::raql_select_field::t_ext,
  Pointer
> {
  using tuple::tuple;
  t8ce288a7922f2eebd9fbfe87e5972d1b(std::tuple<dessser::gen::raql_select_field::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_select_field::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8ce288a7922f2eebd9fbfe87e5972d1b const &a, t8ce288a7922f2eebd9fbfe87e5972d1b const &b) {
  return ::dessser::gen::raql_select_field::Deref(std::get<0>(a)) == ::dessser::gen::raql_select_field::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8ce288a7922f2eebd9fbfe87e5972d1b const &a, t8ce288a7922f2eebd9fbfe87e5972d1b const &b) {
  return !operator==(a, b);
}
struct t2fa56af3afd4098bea1b66e93db81284 : public std::tuple<
  std::optional<Lst<dessser::gen::field_name::t_ext>>,
  Pointer
> {
  using tuple::tuple;
  t2fa56af3afd4098bea1b66e93db81284(std::tuple<std::optional<Lst<dessser::gen::field_name::t_ext>>, Pointer> p)
    : std::tuple<std::optional<Lst<dessser::gen::field_name::t_ext>>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2fa56af3afd4098bea1b66e93db81284 const &a, t2fa56af3afd4098bea1b66e93db81284 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2fa56af3afd4098bea1b66e93db81284 const &a, t2fa56af3afd4098bea1b66e93db81284 const &b) {
  return !operator==(a, b);
}
struct tae4ac4fd187cdebd0a4f6d30f229fbc5 : public std::tuple<
  Lst<dessser::gen::field_name::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tae4ac4fd187cdebd0a4f6d30f229fbc5(std::tuple<Lst<dessser::gen::field_name::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::field_name::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tae4ac4fd187cdebd0a4f6d30f229fbc5 const &a, tae4ac4fd187cdebd0a4f6d30f229fbc5 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tae4ac4fd187cdebd0a4f6d30f229fbc5 const &a, tae4ac4fd187cdebd0a4f6d30f229fbc5 const &b) {
  return !operator==(a, b);
}
struct t18cecf882d7ac80cef37dfe6b22279d4 : public std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t18cecf882d7ac80cef37dfe6b22279d4(std::tuple<dessser::gen::field_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::field_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t18cecf882d7ac80cef37dfe6b22279d4 const &a, t18cecf882d7ac80cef37dfe6b22279d4 const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t18cecf882d7ac80cef37dfe6b22279d4 const &a, t18cecf882d7ac80cef37dfe6b22279d4 const &b) {
  return !operator==(a, b);
}
struct te8be0cdfe14de9667ee131ff8f8ccbc5 : public std::tuple<
  std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07>,
  Pointer
> {
  using tuple::tuple;
  te8be0cdfe14de9667ee131ff8f8ccbc5(std::tuple<std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07>, Pointer> p)
    : std::tuple<std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te8be0cdfe14de9667ee131ff8f8ccbc5 const &a, te8be0cdfe14de9667ee131ff8f8ccbc5 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te8be0cdfe14de9667ee131ff8f8ccbc5 const &a, te8be0cdfe14de9667ee131ff8f8ccbc5 const &b) {
  return !operator==(a, b);
}
struct tc75358d1d8abf9ae364b723c583ed583 : public std::tuple<
  Lst<dessser::gen::raql_expr::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tc75358d1d8abf9ae364b723c583ed583(std::tuple<Lst<dessser::gen::raql_expr::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::raql_expr::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc75358d1d8abf9ae364b723c583ed583 const &a, tc75358d1d8abf9ae364b723c583ed583 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc75358d1d8abf9ae364b723c583ed583 const &a, tc75358d1d8abf9ae364b723c583ed583 const &b) {
  return !operator==(a, b);
}
struct t9d7811e9b2b7649b14c53a6539d110a6 : public std::tuple<
  std::optional<dessser::gen::event_time::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t9d7811e9b2b7649b14c53a6539d110a6(std::tuple<std::optional<dessser::gen::event_time::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::event_time::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9d7811e9b2b7649b14c53a6539d110a6 const &a, t9d7811e9b2b7649b14c53a6539d110a6 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && ::dessser::gen::event_time::Deref(std::get<0>(a).value()) == ::dessser::gen::event_time::Deref(std::get<0>(b).value())) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9d7811e9b2b7649b14c53a6539d110a6 const &a, t9d7811e9b2b7649b14c53a6539d110a6 const &b) {
  return !operator==(a, b);
}
struct t6402d827f30fdf794bf052c6e2db3344 : public std::tuple<
  dessser::gen::event_time::t_ext,
  Pointer
> {
  using tuple::tuple;
  t6402d827f30fdf794bf052c6e2db3344(std::tuple<dessser::gen::event_time::t_ext, Pointer> p)
    : std::tuple<dessser::gen::event_time::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6402d827f30fdf794bf052c6e2db3344 const &a, t6402d827f30fdf794bf052c6e2db3344 const &b) {
  return ::dessser::gen::event_time::Deref(std::get<0>(a)) == ::dessser::gen::event_time::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6402d827f30fdf794bf052c6e2db3344 const &a, t6402d827f30fdf794bf052c6e2db3344 const &b) {
  return !operator==(a, b);
}
struct t810ce2c2364cf512ac90f670b999da7d : public std::tuple<
  dessser::gen::raql_flush_method::t_ext,
  Pointer
> {
  using tuple::tuple;
  t810ce2c2364cf512ac90f670b999da7d(std::tuple<dessser::gen::raql_flush_method::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_flush_method::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t810ce2c2364cf512ac90f670b999da7d const &a, t810ce2c2364cf512ac90f670b999da7d const &b) {
  return ::dessser::gen::raql_flush_method::Deref(std::get<0>(a)) == ::dessser::gen::raql_flush_method::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t810ce2c2364cf512ac90f670b999da7d const &a, t810ce2c2364cf512ac90f670b999da7d const &b) {
  return !operator==(a, b);
}
struct tbcf6a3aa37d854ac0cc9f4cc183dcc59 : public std::tuple<
  Lst<::dessser::gen::raql_operation::data_source>,
  Pointer
> {
  using tuple::tuple;
  tbcf6a3aa37d854ac0cc9f4cc183dcc59(std::tuple<Lst<::dessser::gen::raql_operation::data_source>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::raql_operation::data_source>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tbcf6a3aa37d854ac0cc9f4cc183dcc59 const &a, tbcf6a3aa37d854ac0cc9f4cc183dcc59 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tbcf6a3aa37d854ac0cc9f4cc183dcc59 const &a, tbcf6a3aa37d854ac0cc9f4cc183dcc59 const &b) {
  return !operator==(a, b);
}
struct tb79a82b758e19581c860a01593485d0a : public std::tuple<
  dessser::gen::raql_ip_protocol::t_ext,
  Pointer
> {
  using tuple::tuple;
  tb79a82b758e19581c860a01593485d0a(std::tuple<dessser::gen::raql_ip_protocol::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_ip_protocol::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb79a82b758e19581c860a01593485d0a const &a, tb79a82b758e19581c860a01593485d0a const &b) {
  return ::dessser::gen::raql_ip_protocol::Deref(std::get<0>(a)) == ::dessser::gen::raql_ip_protocol::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb79a82b758e19581c860a01593485d0a const &a, tb79a82b758e19581c860a01593485d0a const &b) {
  return !operator==(a, b);
}
struct ta85addb3b405dfc5781945a2f01e354a : public std::tuple<
  dessser::gen::raql_net_protocol::t_ext,
  Pointer
> {
  using tuple::tuple;
  ta85addb3b405dfc5781945a2f01e354a(std::tuple<dessser::gen::raql_net_protocol::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_net_protocol::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta85addb3b405dfc5781945a2f01e354a const &a, ta85addb3b405dfc5781945a2f01e354a const &b) {
  return ::dessser::gen::raql_net_protocol::Deref(std::get<0>(a)) == ::dessser::gen::raql_net_protocol::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta85addb3b405dfc5781945a2f01e354a const &a, ta85addb3b405dfc5781945a2f01e354a const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" "Ptr")
      (let "ssum_dst_844" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_864"
            (let "srec_dst_863"
              (let "srec_dst_857"
                (let "srec_dst_854"
                  (let "srec_dst_853"
                    (let "srec_dst_850" (write-u8 (identifier "ssum_dst_844") (u8-of-char (get-field "separator" (get-alt "CSV" (param 0)))))
                      (write-bytes
                        (let "leb128_sz_851" (make-vec (string-length (get-field "null" (get-alt "CSV" (param 0)))))
                          (let "leb128_ptr_852" (make-vec (identifier "srec_dst_850"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_852")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_852"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_851"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_851"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_851"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_851") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_851")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_851")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_852"))))) 
                        (bytes-of-string (get-field "null" (get-alt "CSV" (param 0)))))) 
                    (write-u8 (identifier "srec_dst_853") (u8-of-bool (get-field "may_quote" (get-alt "CSV" (param 0))))))
                  (write-bytes
                    (let "leb128_sz_855" (make-vec (string-length (get-field "escape_seq" (get-alt "CSV" (param 0)))))
                      (let "leb128_ptr_856" (make-vec (identifier "srec_dst_854"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_856")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_856"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_855"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_855"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_855"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_855") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_855")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_855")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_856"))))) 
                    (bytes-of-string (get-field "escape_seq" (get-alt "CSV" (param 0))))))
                (let "dst_ref_860"
                  (make-vec
                    (let "leb128_sz_858" (make-vec (cardinality (get-field "fields" (get-alt "CSV" (param 0)))))
                      (let "leb128_ptr_859" (make-vec (identifier "srec_dst_857"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_859")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_859"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_858"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_858"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_858"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_858") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_858")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_858")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_859"))))))
                  (let "n_ref_861" (make-vec (i32 0))
                    (seq
                      (for-each "x_862" (get-field "fields" (get-alt "CSV" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_860") (apply (ext-identifier field_type to-row-binary) (identifier "x_862") (unsafe-nth (u8 0) (identifier "dst_ref_860"))))
                          (set-vec (u8 0) (identifier "n_ref_861") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_861")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_860")))))) 
              (write-u8 (identifier "srec_dst_863") (u8-of-bool (get-field "vectors_of_chars_as_string" (get-alt "CSV" (param 0))))))
            (write-u8 (identifier "srec_dst_864") (u8-of-bool (get-field "clickhouse_syntax" (get-alt "CSV" (param 0))))))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "dst_ref_847"
              (make-vec
                (let "leb128_sz_845" (make-vec (cardinality (get-alt "RowBinary" (param 0))))
                  (let "leb128_ptr_846" (make-vec (identifier "ssum_dst_844"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_846")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_846"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_845"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_845"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_845"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_845") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_845")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_845")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_846"))))))
              (let "n_ref_848" (make-vec (i32 0))
                (seq
                  (for-each "x_849" (get-alt "RowBinary" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_847") (apply (ext-identifier field_type to-row-binary) (identifier "x_849") (unsafe-nth (u8 0) (identifier "dst_ref_847"))))
                      (set-vec (u8 0) (identifier "n_ref_848") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_848")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_847")))))))))
 */
static std::function<Pointer(::dessser::gen::raql_operation::external_format const &,Pointer &)> external_format_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_operation::external_format const &,Pointer &)> fun0 { [&](::dessser::gen::raql_operation::external_format p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0.index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_844 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0.index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_8 { std::get<0 /* CSV */>(p_0) };
        char id_9 { id_8.separator };
        uint8_t id_10 { uint8_t(id_9) };
        Pointer id_11 { ssum_dst_844.writeU8(id_10) };
        Pointer let_res_12;
        {
          Pointer srec_dst_850 { id_11 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_13 { std::get<0 /* CSV */>(p_0) };
          std::string id_14 { id_13.null };
          uint32_t id_15 { (uint32_t)id_14.size() };
          Vec<1, uint32_t> id_16 {  id_15  };
          Pointer let_res_17;
          {
            Vec<1, uint32_t> leb128_sz_851 { id_16 };
            Vec<1, Pointer> id_18 {  srec_dst_850  };
            Pointer let_res_19;
            {
              Vec<1, Pointer> leb128_ptr_852 { id_18 };
              bool while_flag_20 { true };
              do {
                uint8_t id_21 { 0 };
                uint8_t id_22 { 0 };
                Pointer id_23 { leb128_ptr_852[id_22] };
                uint32_t id_24 { 128U };
                uint8_t id_25 { 0 };
                uint32_t id_26 { leb128_sz_851[id_25] };
                bool id_27 { bool(id_24 > id_26) };
                uint8_t choose_res_28;
                if (id_27) {
                  uint8_t id_29 { 0 };
                  uint32_t id_30 { leb128_sz_851[id_29] };
                  uint8_t id_31 { uint8_t(id_30) };
                  choose_res_28 = id_31;
                } else {
                  uint8_t id_32 { 0 };
                  uint32_t id_33 { leb128_sz_851[id_32] };
                  uint8_t id_34 { uint8_t(id_33) };
                  uint8_t id_35 { 128 };
                  uint8_t id_36 { uint8_t(id_34 | id_35) };
                  choose_res_28 = id_36;
                }
                Pointer id_37 { id_23.writeU8(choose_res_28) };
                Void id_38 { ((void)(leb128_ptr_852[id_21] = id_37), ::dessser::Void()) };
                (void)id_38;
                uint8_t id_39 { 0 };
                uint8_t id_40 { 0 };
                uint32_t id_41 { leb128_sz_851[id_40] };
                uint8_t id_42 { 7 };
                uint32_t id_43 { uint32_t(id_41 >> id_42) };
                Void id_44 { ((void)(leb128_sz_851[id_39] = id_43), ::dessser::Void()) };
                (void)id_44;
                uint8_t id_45 { 0 };
                uint32_t id_46 { leb128_sz_851[id_45] };
                uint32_t id_47 { 0U };
                bool id_48 { bool(id_46 > id_47) };
                while_flag_20 = id_48;
                if (while_flag_20) {
                  (void)::dessser::Void();
                }
              } while (while_flag_20);
              (void)::dessser::Void();
              uint8_t id_49 { 0 };
              Pointer id_50 { leb128_ptr_852[id_49] };
              let_res_19 = id_50;
            }
            let_res_17 = let_res_19;
          }
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_51 { std::get<0 /* CSV */>(p_0) };
          std::string id_52 { id_51.null };
          Bytes id_53 { id_52 };
          Pointer id_54 { let_res_17.writeBytes(id_53) };
          let_res_12 = id_54;
        }
        Pointer let_res_55;
        {
          Pointer srec_dst_853 { let_res_12 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_56 { std::get<0 /* CSV */>(p_0) };
          bool id_57 { id_56.may_quote };
          uint8_t id_58 { uint8_t(id_57) };
          Pointer id_59 { srec_dst_853.writeU8(id_58) };
          let_res_55 = id_59;
        }
        Pointer let_res_60;
        {
          Pointer srec_dst_854 { let_res_55 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_61 { std::get<0 /* CSV */>(p_0) };
          std::string id_62 { id_61.escape_seq };
          uint32_t id_63 { (uint32_t)id_62.size() };
          Vec<1, uint32_t> id_64 {  id_63  };
          Pointer let_res_65;
          {
            Vec<1, uint32_t> leb128_sz_855 { id_64 };
            Vec<1, Pointer> id_66 {  srec_dst_854  };
            Pointer let_res_67;
            {
              Vec<1, Pointer> leb128_ptr_856 { id_66 };
              bool while_flag_68 { true };
              do {
                uint8_t id_69 { 0 };
                uint8_t id_70 { 0 };
                Pointer id_71 { leb128_ptr_856[id_70] };
                uint32_t id_72 { 128U };
                uint8_t id_73 { 0 };
                uint32_t id_74 { leb128_sz_855[id_73] };
                bool id_75 { bool(id_72 > id_74) };
                uint8_t choose_res_76;
                if (id_75) {
                  uint8_t id_77 { 0 };
                  uint32_t id_78 { leb128_sz_855[id_77] };
                  uint8_t id_79 { uint8_t(id_78) };
                  choose_res_76 = id_79;
                } else {
                  uint8_t id_80 { 0 };
                  uint32_t id_81 { leb128_sz_855[id_80] };
                  uint8_t id_82 { uint8_t(id_81) };
                  uint8_t id_83 { 128 };
                  uint8_t id_84 { uint8_t(id_82 | id_83) };
                  choose_res_76 = id_84;
                }
                Pointer id_85 { id_71.writeU8(choose_res_76) };
                Void id_86 { ((void)(leb128_ptr_856[id_69] = id_85), ::dessser::Void()) };
                (void)id_86;
                uint8_t id_87 { 0 };
                uint8_t id_88 { 0 };
                uint32_t id_89 { leb128_sz_855[id_88] };
                uint8_t id_90 { 7 };
                uint32_t id_91 { uint32_t(id_89 >> id_90) };
                Void id_92 { ((void)(leb128_sz_855[id_87] = id_91), ::dessser::Void()) };
                (void)id_92;
                uint8_t id_93 { 0 };
                uint32_t id_94 { leb128_sz_855[id_93] };
                uint32_t id_95 { 0U };
                bool id_96 { bool(id_94 > id_95) };
                while_flag_68 = id_96;
                if (while_flag_68) {
                  (void)::dessser::Void();
                }
              } while (while_flag_68);
              (void)::dessser::Void();
              uint8_t id_97 { 0 };
              Pointer id_98 { leb128_ptr_856[id_97] };
              let_res_67 = id_98;
            }
            let_res_65 = let_res_67;
          }
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_99 { std::get<0 /* CSV */>(p_0) };
          std::string id_100 { id_99.escape_seq };
          Bytes id_101 { id_100 };
          Pointer id_102 { let_res_65.writeBytes(id_101) };
          let_res_60 = id_102;
        }
        Pointer let_res_103;
        {
          Pointer srec_dst_857 { let_res_60 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_104 { std::get<0 /* CSV */>(p_0) };
          Lst<dessser::gen::field_type::t_ext> id_105 { id_104.fields };
          uint32_t id_106 { id_105.size() };
          Vec<1, uint32_t> id_107 {  id_106  };
          Pointer let_res_108;
          {
            Vec<1, uint32_t> leb128_sz_858 { id_107 };
            Vec<1, Pointer> id_109 {  srec_dst_857  };
            Pointer let_res_110;
            {
              Vec<1, Pointer> leb128_ptr_859 { id_109 };
              bool while_flag_111 { true };
              do {
                uint8_t id_112 { 0 };
                uint8_t id_113 { 0 };
                Pointer id_114 { leb128_ptr_859[id_113] };
                uint32_t id_115 { 128U };
                uint8_t id_116 { 0 };
                uint32_t id_117 { leb128_sz_858[id_116] };
                bool id_118 { bool(id_115 > id_117) };
                uint8_t choose_res_119;
                if (id_118) {
                  uint8_t id_120 { 0 };
                  uint32_t id_121 { leb128_sz_858[id_120] };
                  uint8_t id_122 { uint8_t(id_121) };
                  choose_res_119 = id_122;
                } else {
                  uint8_t id_123 { 0 };
                  uint32_t id_124 { leb128_sz_858[id_123] };
                  uint8_t id_125 { uint8_t(id_124) };
                  uint8_t id_126 { 128 };
                  uint8_t id_127 { uint8_t(id_125 | id_126) };
                  choose_res_119 = id_127;
                }
                Pointer id_128 { id_114.writeU8(choose_res_119) };
                Void id_129 { ((void)(leb128_ptr_859[id_112] = id_128), ::dessser::Void()) };
                (void)id_129;
                uint8_t id_130 { 0 };
                uint8_t id_131 { 0 };
                uint32_t id_132 { leb128_sz_858[id_131] };
                uint8_t id_133 { 7 };
                uint32_t id_134 { uint32_t(id_132 >> id_133) };
                Void id_135 { ((void)(leb128_sz_858[id_130] = id_134), ::dessser::Void()) };
                (void)id_135;
                uint8_t id_136 { 0 };
                uint32_t id_137 { leb128_sz_858[id_136] };
                uint32_t id_138 { 0U };
                bool id_139 { bool(id_137 > id_138) };
                while_flag_111 = id_139;
                if (while_flag_111) {
                  (void)::dessser::Void();
                }
              } while (while_flag_111);
              (void)::dessser::Void();
              uint8_t id_140 { 0 };
              Pointer id_141 { leb128_ptr_859[id_140] };
              let_res_110 = id_141;
            }
            let_res_108 = let_res_110;
          }
          Vec<1, Pointer> id_142 {  let_res_108  };
          Pointer let_res_143;
          {
            Vec<1, Pointer> dst_ref_860 { id_142 };
            int32_t id_144 { 0L };
            Vec<1, int32_t> id_145 {  id_144  };
            Pointer let_res_146;
            {
              Vec<1, int32_t> n_ref_861 { id_145 };
              ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_147 { std::get<0 /* CSV */>(p_0) };
              Lst<dessser::gen::field_type::t_ext> id_148 { id_147.fields };
              for (dessser::gen::field_type::t_ext &x_862 : id_148) {
                uint8_t id_149 { 0 };
                auto fun150 { dessser::gen::field_type::to_row_binary };
                uint8_t id_151 { 0 };
                Pointer id_152 { dst_ref_860[id_151] };
                Pointer id_153 { fun150(x_862, id_152) };
                Void id_154 { ((void)(dst_ref_860[id_149] = id_153), ::dessser::Void()) };
                (void)id_154;
                uint8_t id_155 { 0 };
                int32_t id_156 { 1L };
                uint8_t id_157 { 0 };
                int32_t id_158 { n_ref_861[id_157] };
                int32_t id_159 { int32_t(id_156 + id_158) };
                Void id_160 { ((void)(n_ref_861[id_155] = id_159), ::dessser::Void()) };
                (void)id_160;
                (void)id_160;
              }
              (void)::dessser::Void();
              uint8_t id_161 { 0 };
              Pointer id_162 { dst_ref_860[id_161] };
              let_res_146 = id_162;
            }
            let_res_143 = let_res_146;
          }
          let_res_103 = let_res_143;
        }
        Pointer let_res_163;
        {
          Pointer srec_dst_863 { let_res_103 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_164 { std::get<0 /* CSV */>(p_0) };
          bool id_165 { id_164.vectors_of_chars_as_string };
          uint8_t id_166 { uint8_t(id_165) };
          Pointer id_167 { srec_dst_863.writeU8(id_166) };
          let_res_163 = id_167;
        }
        Pointer let_res_168;
        {
          Pointer srec_dst_864 { let_res_163 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_169 { std::get<0 /* CSV */>(p_0) };
          bool id_170 { id_169.clickhouse_syntax };
          uint8_t id_171 { uint8_t(id_170) };
          Pointer id_172 { srec_dst_864.writeU8(id_171) };
          let_res_168 = id_172;
        }
        choose_res_7 = let_res_168;
      } else {
        uint16_t id_173 { uint16_t(p_0.index()) };
        uint16_t id_174 { 1 };
        bool id_175 { bool(id_173 == id_174) };
        Void id_176 { ((void)(assert(id_175)), ::dessser::Void()) };
        (void)id_176;
        Lst<dessser::gen::field_type::t_ext> id_177 { std::get<1 /* RowBinary */>(p_0) };
        uint32_t id_178 { id_177.size() };
        Vec<1, uint32_t> id_179 {  id_178  };
        Pointer let_res_180;
        {
          Vec<1, uint32_t> leb128_sz_845 { id_179 };
          Vec<1, Pointer> id_181 {  ssum_dst_844  };
          Pointer let_res_182;
          {
            Vec<1, Pointer> leb128_ptr_846 { id_181 };
            bool while_flag_183 { true };
            do {
              uint8_t id_184 { 0 };
              uint8_t id_185 { 0 };
              Pointer id_186 { leb128_ptr_846[id_185] };
              uint32_t id_187 { 128U };
              uint8_t id_188 { 0 };
              uint32_t id_189 { leb128_sz_845[id_188] };
              bool id_190 { bool(id_187 > id_189) };
              uint8_t choose_res_191;
              if (id_190) {
                uint8_t id_192 { 0 };
                uint32_t id_193 { leb128_sz_845[id_192] };
                uint8_t id_194 { uint8_t(id_193) };
                choose_res_191 = id_194;
              } else {
                uint8_t id_195 { 0 };
                uint32_t id_196 { leb128_sz_845[id_195] };
                uint8_t id_197 { uint8_t(id_196) };
                uint8_t id_198 { 128 };
                uint8_t id_199 { uint8_t(id_197 | id_198) };
                choose_res_191 = id_199;
              }
              Pointer id_200 { id_186.writeU8(choose_res_191) };
              Void id_201 { ((void)(leb128_ptr_846[id_184] = id_200), ::dessser::Void()) };
              (void)id_201;
              uint8_t id_202 { 0 };
              uint8_t id_203 { 0 };
              uint32_t id_204 { leb128_sz_845[id_203] };
              uint8_t id_205 { 7 };
              uint32_t id_206 { uint32_t(id_204 >> id_205) };
              Void id_207 { ((void)(leb128_sz_845[id_202] = id_206), ::dessser::Void()) };
              (void)id_207;
              uint8_t id_208 { 0 };
              uint32_t id_209 { leb128_sz_845[id_208] };
              uint32_t id_210 { 0U };
              bool id_211 { bool(id_209 > id_210) };
              while_flag_183 = id_211;
              if (while_flag_183) {
                (void)::dessser::Void();
              }
            } while (while_flag_183);
            (void)::dessser::Void();
            uint8_t id_212 { 0 };
            Pointer id_213 { leb128_ptr_846[id_212] };
            let_res_182 = id_213;
          }
          let_res_180 = let_res_182;
        }
        Vec<1, Pointer> id_214 {  let_res_180  };
        Pointer let_res_215;
        {
          Vec<1, Pointer> dst_ref_847 { id_214 };
          int32_t id_216 { 0L };
          Vec<1, int32_t> id_217 {  id_216  };
          Pointer let_res_218;
          {
            Vec<1, int32_t> n_ref_848 { id_217 };
            Lst<dessser::gen::field_type::t_ext> id_219 { std::get<1 /* RowBinary */>(p_0) };
            for (dessser::gen::field_type::t_ext &x_849 : id_219) {
              uint8_t id_220 { 0 };
              auto fun221 { dessser::gen::field_type::to_row_binary };
              uint8_t id_222 { 0 };
              Pointer id_223 { dst_ref_847[id_222] };
              Pointer id_224 { fun221(x_849, id_223) };
              Void id_225 { ((void)(dst_ref_847[id_220] = id_224), ::dessser::Void()) };
              (void)id_225;
              uint8_t id_226 { 0 };
              int32_t id_227 { 1L };
              uint8_t id_228 { 0 };
              int32_t id_229 { n_ref_848[id_228] };
              int32_t id_230 { int32_t(id_227 + id_229) };
              Void id_231 { ((void)(n_ref_848[id_226] = id_230), ::dessser::Void()) };
              (void)id_231;
              (void)id_231;
            }
            (void)::dessser::Void();
            uint8_t id_232 { 0 };
            Pointer id_233 { dst_ref_847[id_232] };
            let_res_218 = id_233;
          }
          let_res_215 = let_res_218;
        }
        choose_res_7 = let_res_215;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::raql_operation::external_format const &,Pointer &)> external_format_to_row_binary(external_format_to_row_binary_init());

/* 
    (fun ("[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" "Ptr")
      (let "ssum_dst_825" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_842"
            (let "srec_dst_841" (apply (ext-identifier raql_expr to-row-binary) (get-field "fname" (get-alt "File" (param 0))) (identifier "ssum_dst_825"))
              (if (is-null (get-field "preprocessor" (get-alt "File" (param 0)))) 
                (write-u8 (identifier "srec_dst_841") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "preprocessor" (get-alt "File" (param 0)))) (write-u8 (identifier "srec_dst_841") (u8 0)))))
            (apply (ext-identifier raql_expr to-row-binary) (get-field "unlink" (get-alt "File" (param 0))) (identifier "srec_dst_842")))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "srec_dst_837"
              (let "srec_dst_836"
                (let "srec_dst_835"
                  (let "dst_ref_828"
                    (make-vec
                      (let "leb128_sz_826" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (param 0)))))
                        (let "leb128_ptr_827" (make-vec (identifier "ssum_dst_825"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_827")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_827"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_826"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_826"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_826"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_826") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_826")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_826")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_827"))))))
                    (let "n_ref_829" (make-vec (i32 0))
                      (seq
                        (for-each "x_830" (get-field "options" (get-alt "Kafka" (param 0)))
                          (seq
                            (set-vec (u8 0) (identifier "dst_ref_828")
                              (let "stup_dst_834"
                                (let "stup_dst_831" (unsafe-nth (u8 0) (identifier "dst_ref_828"))
                                  (write-bytes
                                    (let "leb128_sz_832" (make-vec (string-length (get-item 0 (identifier "x_830"))))
                                      (let "leb128_ptr_833" (make-vec (identifier "stup_dst_831"))
                                        (seq
                                          (while
                                            (seq
                                              (set-vec (u8 0) (identifier "leb128_ptr_833")
                                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_833"))
                                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_832"))) 
                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_832"))) 
                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_832"))) (u8 128)))))
                                              (set-vec (u8 0) (identifier "leb128_sz_832") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_832")) (u8 7))) 
                                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_832")) (u32 0))) 
                                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_833"))))) 
                                    (bytes-of-string (get-item 0 (identifier "x_830"))))) 
                                (apply (ext-identifier raql_expr to-row-binary) (get-item 1 (identifier "x_830")) (identifier "stup_dst_834"))))
                            (set-vec (u8 0) (identifier "n_ref_829") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_829")))))) 
                        (unsafe-nth (u8 0) (identifier "dst_ref_828"))))) 
                  (apply (ext-identifier raql_expr to-row-binary) (get-field "topic" (get-alt "Kafka" (param 0))) (identifier "srec_dst_835")))
                (if (is-null (get-field "partitions" (get-alt "Kafka" (param 0)))) 
                  (write-u8 (identifier "srec_dst_836") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "partitions" (get-alt "Kafka" (param 0)))) (write-u8 (identifier "srec_dst_836") (u8 0)))))
              (let "ssum_dst_839" (write-u16 little-endian (identifier "srec_dst_837") (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))))
                (if (eq (u16 0) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
                  (identifier "ssum_dst_839")
                  (if (eq (u16 1) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))))
                    (apply (ext-identifier raql_expr to-row-binary) (get-alt "OffsetFromEnd" (get-field "restart_from" (get-alt "Kafka" (param 0)))) (identifier "ssum_dst_839"))
                    (if (eq (u16 2) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
                      (identifier "ssum_dst_839")
                      (seq (assert (eq (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))) (u16 3)))
                        (let "srec_dst_840"
                          (apply (ext-identifier raql_expr to-row-binary) (get-field "after_max_secs" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0))))) (identifier "ssum_dst_839"))
                          (apply (ext-identifier raql_expr to-row-binary) (get-field "after_max_events" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0))))) (identifier "srec_dst_840")))))))))))))
 */
static std::function<Pointer(::dessser::gen::raql_operation::external_source &,Pointer &)> external_source_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_operation::external_source &,Pointer &)> fun234 { [&](::dessser::gen::raql_operation::external_source p_0, Pointer p_1) {
    uint16_t id_235 { uint16_t(p_0.index()) };
    Pointer id_236 { p_1.writeU16Le(id_235) };
    Pointer let_res_237;
    {
      Pointer ssum_dst_825 { id_236 };
      uint16_t id_238 { 0 };
      uint16_t id_239 { uint16_t(p_0.index()) };
      bool id_240 { bool(id_238 == id_239) };
      Pointer choose_res_241;
      if (id_240) {
        auto fun242 { dessser::gen::raql_expr::to_row_binary };
        ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_243 { std::get<0 /* File */>(p_0) };
        dessser::gen::raql_expr::t_ext id_244 { id_243.fname };
        Pointer id_245 { fun242(id_244, ssum_dst_825) };
        Pointer let_res_246;
        {
          Pointer srec_dst_841 { id_245 };
          ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_247 { std::get<0 /* File */>(p_0) };
          std::optional<dessser::gen::raql_expr::t_ext> id_248 { id_247.preprocessor };
          bool id_249 { !(id_248.has_value ()) };
          Pointer choose_res_250;
          if (id_249) {
            uint8_t id_251 { 1 };
            Pointer id_252 { srec_dst_841.writeU8(id_251) };
            choose_res_250 = id_252;
          } else {
            auto fun253 { dessser::gen::raql_expr::to_row_binary };
            ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_254 { std::get<0 /* File */>(p_0) };
            std::optional<dessser::gen::raql_expr::t_ext> id_255 { id_254.preprocessor };
            dessser::gen::raql_expr::t_ext id_256 { id_255.value() };
            uint8_t id_257 { 0 };
            Pointer id_258 { srec_dst_841.writeU8(id_257) };
            Pointer id_259 { fun253(id_256, id_258) };
            choose_res_250 = id_259;
          }
          let_res_246 = choose_res_250;
        }
        Pointer let_res_260;
        {
          Pointer srec_dst_842 { let_res_246 };
          auto fun261 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_262 { std::get<0 /* File */>(p_0) };
          dessser::gen::raql_expr::t_ext id_263 { id_262.unlink };
          Pointer id_264 { fun261(id_263, srec_dst_842) };
          let_res_260 = id_264;
        }
        choose_res_241 = let_res_260;
      } else {
        uint16_t id_265 { uint16_t(p_0.index()) };
        uint16_t id_266 { 1 };
        bool id_267 { bool(id_265 == id_266) };
        Void id_268 { ((void)(assert(id_267)), ::dessser::Void()) };
        (void)id_268;
        ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_269 { std::get<1 /* Kafka */>(p_0) };
        Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> id_270 { id_269.options };
        uint32_t id_271 { id_270.size() };
        Vec<1, uint32_t> id_272 {  id_271  };
        Pointer let_res_273;
        {
          Vec<1, uint32_t> leb128_sz_826 { id_272 };
          Vec<1, Pointer> id_274 {  ssum_dst_825  };
          Pointer let_res_275;
          {
            Vec<1, Pointer> leb128_ptr_827 { id_274 };
            bool while_flag_276 { true };
            do {
              uint8_t id_277 { 0 };
              uint8_t id_278 { 0 };
              Pointer id_279 { leb128_ptr_827[id_278] };
              uint32_t id_280 { 128U };
              uint8_t id_281 { 0 };
              uint32_t id_282 { leb128_sz_826[id_281] };
              bool id_283 { bool(id_280 > id_282) };
              uint8_t choose_res_284;
              if (id_283) {
                uint8_t id_285 { 0 };
                uint32_t id_286 { leb128_sz_826[id_285] };
                uint8_t id_287 { uint8_t(id_286) };
                choose_res_284 = id_287;
              } else {
                uint8_t id_288 { 0 };
                uint32_t id_289 { leb128_sz_826[id_288] };
                uint8_t id_290 { uint8_t(id_289) };
                uint8_t id_291 { 128 };
                uint8_t id_292 { uint8_t(id_290 | id_291) };
                choose_res_284 = id_292;
              }
              Pointer id_293 { id_279.writeU8(choose_res_284) };
              Void id_294 { ((void)(leb128_ptr_827[id_277] = id_293), ::dessser::Void()) };
              (void)id_294;
              uint8_t id_295 { 0 };
              uint8_t id_296 { 0 };
              uint32_t id_297 { leb128_sz_826[id_296] };
              uint8_t id_298 { 7 };
              uint32_t id_299 { uint32_t(id_297 >> id_298) };
              Void id_300 { ((void)(leb128_sz_826[id_295] = id_299), ::dessser::Void()) };
              (void)id_300;
              uint8_t id_301 { 0 };
              uint32_t id_302 { leb128_sz_826[id_301] };
              uint32_t id_303 { 0U };
              bool id_304 { bool(id_302 > id_303) };
              while_flag_276 = id_304;
              if (while_flag_276) {
                (void)::dessser::Void();
              }
            } while (while_flag_276);
            (void)::dessser::Void();
            uint8_t id_305 { 0 };
            Pointer id_306 { leb128_ptr_827[id_305] };
            let_res_275 = id_306;
          }
          let_res_273 = let_res_275;
        }
        Vec<1, Pointer> id_307 {  let_res_273  };
        Pointer let_res_308;
        {
          Vec<1, Pointer> dst_ref_828 { id_307 };
          int32_t id_309 { 0L };
          Vec<1, int32_t> id_310 {  id_309  };
          Pointer let_res_311;
          {
            Vec<1, int32_t> n_ref_829 { id_310 };
            ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_312 { std::get<1 /* Kafka */>(p_0) };
            Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> id_313 { id_312.options };
            for (::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a &x_830 : id_313) {
              uint8_t id_314 { 0 };
              uint8_t id_315 { 0 };
              Pointer id_316 { dst_ref_828[id_315] };
              Pointer let_res_317;
              {
                Pointer stup_dst_831 { id_316 };
                std::string id_318 { std::get<0>(x_830) };
                uint32_t id_319 { (uint32_t)id_318.size() };
                Vec<1, uint32_t> id_320 {  id_319  };
                Pointer let_res_321;
                {
                  Vec<1, uint32_t> leb128_sz_832 { id_320 };
                  Vec<1, Pointer> id_322 {  stup_dst_831  };
                  Pointer let_res_323;
                  {
                    Vec<1, Pointer> leb128_ptr_833 { id_322 };
                    bool while_flag_324 { true };
                    do {
                      uint8_t id_325 { 0 };
                      uint8_t id_326 { 0 };
                      Pointer id_327 { leb128_ptr_833[id_326] };
                      uint32_t id_328 { 128U };
                      uint8_t id_329 { 0 };
                      uint32_t id_330 { leb128_sz_832[id_329] };
                      bool id_331 { bool(id_328 > id_330) };
                      uint8_t choose_res_332;
                      if (id_331) {
                        uint8_t id_333 { 0 };
                        uint32_t id_334 { leb128_sz_832[id_333] };
                        uint8_t id_335 { uint8_t(id_334) };
                        choose_res_332 = id_335;
                      } else {
                        uint8_t id_336 { 0 };
                        uint32_t id_337 { leb128_sz_832[id_336] };
                        uint8_t id_338 { uint8_t(id_337) };
                        uint8_t id_339 { 128 };
                        uint8_t id_340 { uint8_t(id_338 | id_339) };
                        choose_res_332 = id_340;
                      }
                      Pointer id_341 { id_327.writeU8(choose_res_332) };
                      Void id_342 { ((void)(leb128_ptr_833[id_325] = id_341), ::dessser::Void()) };
                      (void)id_342;
                      uint8_t id_343 { 0 };
                      uint8_t id_344 { 0 };
                      uint32_t id_345 { leb128_sz_832[id_344] };
                      uint8_t id_346 { 7 };
                      uint32_t id_347 { uint32_t(id_345 >> id_346) };
                      Void id_348 { ((void)(leb128_sz_832[id_343] = id_347), ::dessser::Void()) };
                      (void)id_348;
                      uint8_t id_349 { 0 };
                      uint32_t id_350 { leb128_sz_832[id_349] };
                      uint32_t id_351 { 0U };
                      bool id_352 { bool(id_350 > id_351) };
                      while_flag_324 = id_352;
                      if (while_flag_324) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_324);
                    (void)::dessser::Void();
                    uint8_t id_353 { 0 };
                    Pointer id_354 { leb128_ptr_833[id_353] };
                    let_res_323 = id_354;
                  }
                  let_res_321 = let_res_323;
                }
                std::string id_355 { std::get<0>(x_830) };
                Bytes id_356 { id_355 };
                Pointer id_357 { let_res_321.writeBytes(id_356) };
                let_res_317 = id_357;
              }
              Pointer let_res_358;
              {
                Pointer stup_dst_834 { let_res_317 };
                auto fun359 { dessser::gen::raql_expr::to_row_binary };
                dessser::gen::raql_expr::t_ext id_360 { std::get<1>(x_830) };
                Pointer id_361 { fun359(id_360, stup_dst_834) };
                let_res_358 = id_361;
              }
              Void id_362 { ((void)(dst_ref_828[id_314] = let_res_358), ::dessser::Void()) };
              (void)id_362;
              uint8_t id_363 { 0 };
              int32_t id_364 { 1L };
              uint8_t id_365 { 0 };
              int32_t id_366 { n_ref_829[id_365] };
              int32_t id_367 { int32_t(id_364 + id_366) };
              Void id_368 { ((void)(n_ref_829[id_363] = id_367), ::dessser::Void()) };
              (void)id_368;
              (void)id_368;
            }
            (void)::dessser::Void();
            uint8_t id_369 { 0 };
            Pointer id_370 { dst_ref_828[id_369] };
            let_res_311 = id_370;
          }
          let_res_308 = let_res_311;
        }
        Pointer let_res_371;
        {
          Pointer srec_dst_835 { let_res_308 };
          auto fun372 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_373 { std::get<1 /* Kafka */>(p_0) };
          dessser::gen::raql_expr::t_ext id_374 { id_373.topic };
          Pointer id_375 { fun372(id_374, srec_dst_835) };
          let_res_371 = id_375;
        }
        Pointer let_res_376;
        {
          Pointer srec_dst_836 { let_res_371 };
          ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_377 { std::get<1 /* Kafka */>(p_0) };
          std::optional<dessser::gen::raql_expr::t_ext> id_378 { id_377.partitions };
          bool id_379 { !(id_378.has_value ()) };
          Pointer choose_res_380;
          if (id_379) {
            uint8_t id_381 { 1 };
            Pointer id_382 { srec_dst_836.writeU8(id_381) };
            choose_res_380 = id_382;
          } else {
            auto fun383 { dessser::gen::raql_expr::to_row_binary };
            ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_384 { std::get<1 /* Kafka */>(p_0) };
            std::optional<dessser::gen::raql_expr::t_ext> id_385 { id_384.partitions };
            dessser::gen::raql_expr::t_ext id_386 { id_385.value() };
            uint8_t id_387 { 0 };
            Pointer id_388 { srec_dst_836.writeU8(id_387) };
            Pointer id_389 { fun383(id_386, id_388) };
            choose_res_380 = id_389;
          }
          let_res_376 = choose_res_380;
        }
        Pointer let_res_390;
        {
          Pointer srec_dst_837 { let_res_376 };
          ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_391 { std::get<1 /* Kafka */>(p_0) };
          ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_392 { id_391.restart_from };
          uint16_t id_393 { uint16_t(id_392.index()) };
          Pointer id_394 { srec_dst_837.writeU16Le(id_393) };
          Pointer let_res_395;
          {
            Pointer ssum_dst_839 { id_394 };
            uint16_t id_396 { 0 };
            ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_397 { std::get<1 /* Kafka */>(p_0) };
            ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_398 { id_397.restart_from };
            uint16_t id_399 { uint16_t(id_398.index()) };
            bool id_400 { bool(id_396 == id_399) };
            Pointer choose_res_401;
            if (id_400) {
              choose_res_401 = ssum_dst_839;
            } else {
              uint16_t id_402 { 1 };
              ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_403 { std::get<1 /* Kafka */>(p_0) };
              ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_404 { id_403.restart_from };
              uint16_t id_405 { uint16_t(id_404.index()) };
              bool id_406 { bool(id_402 == id_405) };
              Pointer choose_res_407;
              if (id_406) {
                auto fun408 { dessser::gen::raql_expr::to_row_binary };
                ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_409 { std::get<1 /* Kafka */>(p_0) };
                ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_410 { id_409.restart_from };
                dessser::gen::raql_expr::t_ext id_411 { std::get<1 /* OffsetFromEnd */>(id_410) };
                Pointer id_412 { fun408(id_411, ssum_dst_839) };
                choose_res_407 = id_412;
              } else {
                uint16_t id_413 { 2 };
                ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_414 { std::get<1 /* Kafka */>(p_0) };
                ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_415 { id_414.restart_from };
                uint16_t id_416 { uint16_t(id_415.index()) };
                bool id_417 { bool(id_413 == id_416) };
                Pointer choose_res_418;
                if (id_417) {
                  choose_res_418 = ssum_dst_839;
                } else {
                  ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_419 { std::get<1 /* Kafka */>(p_0) };
                  ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_420 { id_419.restart_from };
                  uint16_t id_421 { uint16_t(id_420.index()) };
                  uint16_t id_422 { 3 };
                  bool id_423 { bool(id_421 == id_422) };
                  Void id_424 { ((void)(assert(id_423)), ::dessser::Void()) };
                  (void)id_424;
                  auto fun425 { dessser::gen::raql_expr::to_row_binary };
                  ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_426 { std::get<1 /* Kafka */>(p_0) };
                  ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_427 { id_426.restart_from };
                  ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_428 { std::get<3 /* UseKafkaGroupCoordinator */>(id_427) };
                  dessser::gen::raql_expr::t_ext id_429 { id_428.after_max_secs };
                  Pointer id_430 { fun425(id_429, ssum_dst_839) };
                  Pointer let_res_431;
                  {
                    Pointer srec_dst_840 { id_430 };
                    auto fun432 { dessser::gen::raql_expr::to_row_binary };
                    ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_433 { std::get<1 /* Kafka */>(p_0) };
                    ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_434 { id_433.restart_from };
                    ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_435 { std::get<3 /* UseKafkaGroupCoordinator */>(id_434) };
                    dessser::gen::raql_expr::t_ext id_436 { id_435.after_max_events };
                    Pointer id_437 { fun432(id_436, srec_dst_840) };
                    let_res_431 = id_437;
                  }
                  choose_res_418 = let_res_431;
                }
                choose_res_407 = choose_res_418;
              }
              choose_res_401 = choose_res_407;
            }
            let_res_395 = choose_res_401;
          }
          let_res_390 = let_res_395;
        }
        choose_res_241 = let_res_390;
      }
      let_res_237 = choose_res_241;
    }
    return let_res_237;
  }
   };
  return fun234;
}
std::function<Pointer(::dessser::gen::raql_operation::external_source &,Pointer &)> external_source_to_row_binary(external_source_to_row_binary_init());

/* 
    (fun ("[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]")
      (if (eq (u16 0) (label-of (param 0)))
        (add
          (add
            (let "sz_742"
              (let "sz_738"
                (add
                  (add (size 3)
                    (add
                      (let "n_ref_735" (make-vec (string-length (get-field "null" (get-alt "CSV" (param 0)))))
                        (let "lebsz_ref_736" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_735")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_736")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_736") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_736")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_736")))))) 
                      (size-of-u32 (string-length (get-field "null" (get-alt "CSV" (param 0))))))) 
                  (size 1))
                (add (identifier "sz_738")
                  (add
                    (let "n_ref_740" (make-vec (string-length (get-field "escape_seq" (get-alt "CSV" (param 0)))))
                      (let "lebsz_ref_741" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_740")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_741")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_741") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_741")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_741")))))) 
                    (size-of-u32 (string-length (get-field "escape_seq" (get-alt "CSV" (param 0))))))))
              (let "sz_ref_745"
                (make-vec
                  (add (identifier "sz_742")
                    (let "n_ref_743" (make-vec (cardinality (get-field "fields" (get-alt "CSV" (param 0)))))
                      (let "lebsz_ref_744" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_743")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_744")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_744") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_744")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_744"))))))))
                (seq
                  (let "repeat_n_746" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "fields" (get-alt "CSV" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_746")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_745")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_745"))
                            (apply (ext-identifier field_type sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_746")) (get-field "fields" (get-alt "CSV" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_746") (add (unsafe-nth (u8 0) (identifier "repeat_n_746")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_745"))))) (size 1)) 
          (size 1))
        (seq (assert (eq (label-of (param 0)) (u16 1)))
          (let "sz_ref_730"
            (make-vec
              (add (size 2)
                (let "n_ref_728" (make-vec (cardinality (get-alt "RowBinary" (param 0))))
                  (let "lebsz_ref_729" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_728")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_729")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_729") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_729")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_729"))))))))
            (seq
              (let "repeat_n_731" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-alt "RowBinary" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_731")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_730")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_730")) (apply (ext-identifier field_type sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_731")) (get-alt "RowBinary" (param 0))))))
                    (set-vec (u8 0) (identifier "repeat_n_731") (add (unsafe-nth (u8 0) (identifier "repeat_n_731")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_730")))))))
 */
static std::function<Size(::dessser::gen::raql_operation::external_format const &)> external_format_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_operation::external_format const &)> fun438 { [&](::dessser::gen::raql_operation::external_format p_0) {
    uint16_t id_439 { 0 };
    uint16_t id_440 { uint16_t(p_0.index()) };
    bool id_441 { bool(id_439 == id_440) };
    Size choose_res_442;
    if (id_441) {
      Size id_443 { 3UL };
      ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_444 { std::get<0 /* CSV */>(p_0) };
      std::string id_445 { id_444.null };
      uint32_t id_446 { (uint32_t)id_445.size() };
      Vec<1, uint32_t> id_447 {  id_446  };
      Size let_res_448;
      {
        Vec<1, uint32_t> n_ref_735 { id_447 };
        uint32_t id_449 { 1U };
        Vec<1, uint32_t> id_450 {  id_449  };
        Size let_res_451;
        {
          Vec<1, uint32_t> lebsz_ref_736 { id_450 };
          bool while_flag_452 { true };
          do {
            uint8_t id_453 { 0 };
            uint32_t id_454 { n_ref_735[id_453] };
            uint8_t id_455 { 0 };
            uint32_t id_456 { lebsz_ref_736[id_455] };
            uint8_t id_457 { 7 };
            uint32_t id_458 { uint32_t(id_456 << id_457) };
            bool id_459 { bool(id_454 >= id_458) };
            while_flag_452 = id_459;
            if (while_flag_452) {
              uint8_t id_460 { 0 };
              uint8_t id_461 { 0 };
              uint32_t id_462 { lebsz_ref_736[id_461] };
              uint32_t id_463 { 1U };
              uint32_t id_464 { uint32_t(id_462 + id_463) };
              Void id_465 { ((void)(lebsz_ref_736[id_460] = id_464), ::dessser::Void()) };
              (void)id_465;
            }
          } while (while_flag_452);
          (void)::dessser::Void();
          uint8_t id_466 { 0 };
          uint32_t id_467 { lebsz_ref_736[id_466] };
          Size id_468 { Size(id_467) };
          let_res_451 = id_468;
        }
        let_res_448 = let_res_451;
      }
      ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_469 { std::get<0 /* CSV */>(p_0) };
      std::string id_470 { id_469.null };
      uint32_t id_471 { (uint32_t)id_470.size() };
      Size id_472 { Size(id_471) };
      Size id_473 { Size(let_res_448 + id_472) };
      Size id_474 { Size(id_443 + id_473) };
      Size id_475 { 1UL };
      Size id_476 { Size(id_474 + id_475) };
      Size let_res_477;
      {
        Size sz_738 { id_476 };
        ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_478 { std::get<0 /* CSV */>(p_0) };
        std::string id_479 { id_478.escape_seq };
        uint32_t id_480 { (uint32_t)id_479.size() };
        Vec<1, uint32_t> id_481 {  id_480  };
        Size let_res_482;
        {
          Vec<1, uint32_t> n_ref_740 { id_481 };
          uint32_t id_483 { 1U };
          Vec<1, uint32_t> id_484 {  id_483  };
          Size let_res_485;
          {
            Vec<1, uint32_t> lebsz_ref_741 { id_484 };
            bool while_flag_486 { true };
            do {
              uint8_t id_487 { 0 };
              uint32_t id_488 { n_ref_740[id_487] };
              uint8_t id_489 { 0 };
              uint32_t id_490 { lebsz_ref_741[id_489] };
              uint8_t id_491 { 7 };
              uint32_t id_492 { uint32_t(id_490 << id_491) };
              bool id_493 { bool(id_488 >= id_492) };
              while_flag_486 = id_493;
              if (while_flag_486) {
                uint8_t id_494 { 0 };
                uint8_t id_495 { 0 };
                uint32_t id_496 { lebsz_ref_741[id_495] };
                uint32_t id_497 { 1U };
                uint32_t id_498 { uint32_t(id_496 + id_497) };
                Void id_499 { ((void)(lebsz_ref_741[id_494] = id_498), ::dessser::Void()) };
                (void)id_499;
              }
            } while (while_flag_486);
            (void)::dessser::Void();
            uint8_t id_500 { 0 };
            uint32_t id_501 { lebsz_ref_741[id_500] };
            Size id_502 { Size(id_501) };
            let_res_485 = id_502;
          }
          let_res_482 = let_res_485;
        }
        ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_503 { std::get<0 /* CSV */>(p_0) };
        std::string id_504 { id_503.escape_seq };
        uint32_t id_505 { (uint32_t)id_504.size() };
        Size id_506 { Size(id_505) };
        Size id_507 { Size(let_res_482 + id_506) };
        Size id_508 { Size(sz_738 + id_507) };
        let_res_477 = id_508;
      }
      Size let_res_509;
      {
        Size sz_742 { let_res_477 };
        ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_510 { std::get<0 /* CSV */>(p_0) };
        Lst<dessser::gen::field_type::t_ext> id_511 { id_510.fields };
        uint32_t id_512 { id_511.size() };
        Vec<1, uint32_t> id_513 {  id_512  };
        Size let_res_514;
        {
          Vec<1, uint32_t> n_ref_743 { id_513 };
          uint32_t id_515 { 1U };
          Vec<1, uint32_t> id_516 {  id_515  };
          Size let_res_517;
          {
            Vec<1, uint32_t> lebsz_ref_744 { id_516 };
            bool while_flag_518 { true };
            do {
              uint8_t id_519 { 0 };
              uint32_t id_520 { n_ref_743[id_519] };
              uint8_t id_521 { 0 };
              uint32_t id_522 { lebsz_ref_744[id_521] };
              uint8_t id_523 { 7 };
              uint32_t id_524 { uint32_t(id_522 << id_523) };
              bool id_525 { bool(id_520 >= id_524) };
              while_flag_518 = id_525;
              if (while_flag_518) {
                uint8_t id_526 { 0 };
                uint8_t id_527 { 0 };
                uint32_t id_528 { lebsz_ref_744[id_527] };
                uint32_t id_529 { 1U };
                uint32_t id_530 { uint32_t(id_528 + id_529) };
                Void id_531 { ((void)(lebsz_ref_744[id_526] = id_530), ::dessser::Void()) };
                (void)id_531;
              }
            } while (while_flag_518);
            (void)::dessser::Void();
            uint8_t id_532 { 0 };
            uint32_t id_533 { lebsz_ref_744[id_532] };
            Size id_534 { Size(id_533) };
            let_res_517 = id_534;
          }
          let_res_514 = let_res_517;
        }
        Size id_535 { Size(sz_742 + let_res_514) };
        Vec<1, Size> id_536 {  id_535  };
        Size let_res_537;
        {
          Vec<1, Size> sz_ref_745 { id_536 };
          int32_t id_538 { 0L };
          Vec<1, int32_t> id_539 {  id_538  };
          {
            Vec<1, int32_t> repeat_n_746 { id_539 };
            bool while_flag_540 { true };
            do {
              ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_541 { std::get<0 /* CSV */>(p_0) };
              Lst<dessser::gen::field_type::t_ext> id_542 { id_541.fields };
              uint32_t id_543 { id_542.size() };
              int32_t id_544 { int32_t(id_543) };
              uint8_t id_545 { 0 };
              int32_t id_546 { repeat_n_746[id_545] };
              bool id_547 { bool(id_544 > id_546) };
              while_flag_540 = id_547;
              if (while_flag_540) {
                uint8_t id_548 { 0 };
                uint8_t id_549 { 0 };
                Size id_550 { sz_ref_745[id_549] };
                auto fun551 { dessser::gen::field_type::sersize_of_row_binary };
                uint8_t id_552 { 0 };
                int32_t id_553 { repeat_n_746[id_552] };
                ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_554 { std::get<0 /* CSV */>(p_0) };
                Lst<dessser::gen::field_type::t_ext> id_555 { id_554.fields };
                dessser::gen::field_type::t_ext id_556 { id_555[id_553] };
                Size id_557 { fun551(id_556) };
                Size id_558 { Size(id_550 + id_557) };
                Void id_559 { ((void)(sz_ref_745[id_548] = id_558), ::dessser::Void()) };
                (void)id_559;
                uint8_t id_560 { 0 };
                uint8_t id_561 { 0 };
                int32_t id_562 { repeat_n_746[id_561] };
                int32_t id_563 { 1L };
                int32_t id_564 { int32_t(id_562 + id_563) };
                Void id_565 { ((void)(repeat_n_746[id_560] = id_564), ::dessser::Void()) };
                (void)id_565;
                (void)id_565;
              }
            } while (while_flag_540);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_566 { 0 };
          Size id_567 { sz_ref_745[id_566] };
          let_res_537 = id_567;
        }
        let_res_509 = let_res_537;
      }
      Size id_568 { 1UL };
      Size id_569 { Size(let_res_509 + id_568) };
      Size id_570 { 1UL };
      Size id_571 { Size(id_569 + id_570) };
      choose_res_442 = id_571;
    } else {
      uint16_t id_572 { uint16_t(p_0.index()) };
      uint16_t id_573 { 1 };
      bool id_574 { bool(id_572 == id_573) };
      Void id_575 { ((void)(assert(id_574)), ::dessser::Void()) };
      (void)id_575;
      Size id_576 { 2UL };
      Lst<dessser::gen::field_type::t_ext> id_577 { std::get<1 /* RowBinary */>(p_0) };
      uint32_t id_578 { id_577.size() };
      Vec<1, uint32_t> id_579 {  id_578  };
      Size let_res_580;
      {
        Vec<1, uint32_t> n_ref_728 { id_579 };
        uint32_t id_581 { 1U };
        Vec<1, uint32_t> id_582 {  id_581  };
        Size let_res_583;
        {
          Vec<1, uint32_t> lebsz_ref_729 { id_582 };
          bool while_flag_584 { true };
          do {
            uint8_t id_585 { 0 };
            uint32_t id_586 { n_ref_728[id_585] };
            uint8_t id_587 { 0 };
            uint32_t id_588 { lebsz_ref_729[id_587] };
            uint8_t id_589 { 7 };
            uint32_t id_590 { uint32_t(id_588 << id_589) };
            bool id_591 { bool(id_586 >= id_590) };
            while_flag_584 = id_591;
            if (while_flag_584) {
              uint8_t id_592 { 0 };
              uint8_t id_593 { 0 };
              uint32_t id_594 { lebsz_ref_729[id_593] };
              uint32_t id_595 { 1U };
              uint32_t id_596 { uint32_t(id_594 + id_595) };
              Void id_597 { ((void)(lebsz_ref_729[id_592] = id_596), ::dessser::Void()) };
              (void)id_597;
            }
          } while (while_flag_584);
          (void)::dessser::Void();
          uint8_t id_598 { 0 };
          uint32_t id_599 { lebsz_ref_729[id_598] };
          Size id_600 { Size(id_599) };
          let_res_583 = id_600;
        }
        let_res_580 = let_res_583;
      }
      Size id_601 { Size(id_576 + let_res_580) };
      Vec<1, Size> id_602 {  id_601  };
      Size let_res_603;
      {
        Vec<1, Size> sz_ref_730 { id_602 };
        int32_t id_604 { 0L };
        Vec<1, int32_t> id_605 {  id_604  };
        {
          Vec<1, int32_t> repeat_n_731 { id_605 };
          bool while_flag_606 { true };
          do {
            Lst<dessser::gen::field_type::t_ext> id_607 { std::get<1 /* RowBinary */>(p_0) };
            uint32_t id_608 { id_607.size() };
            int32_t id_609 { int32_t(id_608) };
            uint8_t id_610 { 0 };
            int32_t id_611 { repeat_n_731[id_610] };
            bool id_612 { bool(id_609 > id_611) };
            while_flag_606 = id_612;
            if (while_flag_606) {
              uint8_t id_613 { 0 };
              uint8_t id_614 { 0 };
              Size id_615 { sz_ref_730[id_614] };
              auto fun616 { dessser::gen::field_type::sersize_of_row_binary };
              uint8_t id_617 { 0 };
              int32_t id_618 { repeat_n_731[id_617] };
              Lst<dessser::gen::field_type::t_ext> id_619 { std::get<1 /* RowBinary */>(p_0) };
              dessser::gen::field_type::t_ext id_620 { id_619[id_618] };
              Size id_621 { fun616(id_620) };
              Size id_622 { Size(id_615 + id_621) };
              Void id_623 { ((void)(sz_ref_730[id_613] = id_622), ::dessser::Void()) };
              (void)id_623;
              uint8_t id_624 { 0 };
              uint8_t id_625 { 0 };
              int32_t id_626 { repeat_n_731[id_625] };
              int32_t id_627 { 1L };
              int32_t id_628 { int32_t(id_626 + id_627) };
              Void id_629 { ((void)(repeat_n_731[id_624] = id_628), ::dessser::Void()) };
              (void)id_629;
              (void)id_629;
            }
          } while (while_flag_606);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_630 { 0 };
        Size id_631 { sz_ref_730[id_630] };
        let_res_603 = id_631;
      }
      choose_res_442 = let_res_603;
    }
    return choose_res_442;
  }
   };
  return fun438;
}
std::function<Size(::dessser::gen::raql_operation::external_format const &)> external_format_sersize_of_row_binary(external_format_sersize_of_row_binary_init());

/* 
    (fun ("[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_726"
          (let "sz_725" (add (size 2) (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "fname" (get-alt "File" (param 0)))))
            (if (is-null (get-field "preprocessor" (get-alt "File" (param 0)))) 
              (add (identifier "sz_725") (size 1)) (add (add (identifier "sz_725") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "preprocessor" (get-alt "File" (param 0)))))) (size 1))))
          (add (identifier "sz_726") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "unlink" (get-alt "File" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1)))
          (let "sz_720"
            (let "sz_719"
              (let "sz_718"
                (let "sz_ref_711"
                  (make-vec
                    (add (size 2)
                      (let "n_ref_709" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (param 0)))))
                        (let "lebsz_ref_710" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_709")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_710")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_710") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_710")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_710"))))))))
                  (seq
                    (let "repeat_n_712" (make-vec (i32 0))
                      (while (gt (to-i32 (cardinality (get-field "options" (get-alt "Kafka" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_712")))
                        (seq
                          (set-vec (u8 0) (identifier "sz_ref_711")
                            (let "sz_717"
                              (let "sz_713" (unsafe-nth (u8 0) (identifier "sz_ref_711"))
                                (add (identifier "sz_713")
                                  (let "wlen_714" (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_712")) (get-field "options" (get-alt "Kafka" (param 0))))))
                                    (add
                                      (let "n_ref_715" (make-vec (identifier "wlen_714"))
                                        (let "lebsz_ref_716" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_715")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_716")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_716") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_716")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_716")))))) 
                                      (size-of-u32 (identifier "wlen_714"))))))
                              (add (identifier "sz_717")
                                (apply (ext-identifier raql_expr sersize-of-row-binary) (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_712")) (get-field "options" (get-alt "Kafka" (param 0)))))))))
                          (set-vec (u8 0) (identifier "repeat_n_712") (add (unsafe-nth (u8 0) (identifier "repeat_n_712")) (i32 1)))))) 
                    (unsafe-nth (u8 0) (identifier "sz_ref_711")))) (add (identifier "sz_718") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "topic" (get-alt "Kafka" (param 0))))))
              (if (is-null (get-field "partitions" (get-alt "Kafka" (param 0)))) 
                (add (identifier "sz_719") (size 1)) (add (add (identifier "sz_719") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "partitions" (get-alt "Kafka" (param 0)))))) (size 1))))
            (if (eq (u16 0) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
              (add (identifier "sz_720") (size 2))
              (if (eq (u16 1) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))))
                (add (add (identifier "sz_720") (size 2)) (apply (ext-identifier raql_expr sersize-of-row-binary) (get-alt "OffsetFromEnd" (get-field "restart_from" (get-alt "Kafka" (param 0))))))
                (if (eq (u16 2) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
                  (add (identifier "sz_720") (size 2))
                  (seq (assert (eq (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))) (u16 3)))
                    (let "sz_723"
                      (add (add (identifier "sz_720") (size 2))
                        (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "after_max_secs" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0)))))))
                      (add (identifier "sz_723") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "after_max_events" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0))))))))))))))))
 */
static std::function<Size(::dessser::gen::raql_operation::external_source &)> external_source_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_operation::external_source &)> fun632 { [&](::dessser::gen::raql_operation::external_source p_0) {
    uint16_t id_633 { 0 };
    uint16_t id_634 { uint16_t(p_0.index()) };
    bool id_635 { bool(id_633 == id_634) };
    Size choose_res_636;
    if (id_635) {
      Size id_637 { 2UL };
      auto fun638 { dessser::gen::raql_expr::sersize_of_row_binary };
      ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_639 { std::get<0 /* File */>(p_0) };
      dessser::gen::raql_expr::t_ext id_640 { id_639.fname };
      Size id_641 { fun638(id_640) };
      Size id_642 { Size(id_637 + id_641) };
      Size let_res_643;
      {
        Size sz_725 { id_642 };
        ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_644 { std::get<0 /* File */>(p_0) };
        std::optional<dessser::gen::raql_expr::t_ext> id_645 { id_644.preprocessor };
        bool id_646 { !(id_645.has_value ()) };
        Size choose_res_647;
        if (id_646) {
          Size id_648 { 1UL };
          Size id_649 { Size(sz_725 + id_648) };
          choose_res_647 = id_649;
        } else {
          auto fun650 { dessser::gen::raql_expr::sersize_of_row_binary };
          ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_651 { std::get<0 /* File */>(p_0) };
          std::optional<dessser::gen::raql_expr::t_ext> id_652 { id_651.preprocessor };
          dessser::gen::raql_expr::t_ext id_653 { id_652.value() };
          Size id_654 { fun650(id_653) };
          Size id_655 { Size(sz_725 + id_654) };
          Size id_656 { 1UL };
          Size id_657 { Size(id_655 + id_656) };
          choose_res_647 = id_657;
        }
        let_res_643 = choose_res_647;
      }
      Size let_res_658;
      {
        Size sz_726 { let_res_643 };
        auto fun659 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_660 { std::get<0 /* File */>(p_0) };
        dessser::gen::raql_expr::t_ext id_661 { id_660.unlink };
        Size id_662 { fun659(id_661) };
        Size id_663 { Size(sz_726 + id_662) };
        let_res_658 = id_663;
      }
      choose_res_636 = let_res_658;
    } else {
      uint16_t id_664 { uint16_t(p_0.index()) };
      uint16_t id_665 { 1 };
      bool id_666 { bool(id_664 == id_665) };
      Void id_667 { ((void)(assert(id_666)), ::dessser::Void()) };
      (void)id_667;
      Size id_668 { 2UL };
      ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_669 { std::get<1 /* Kafka */>(p_0) };
      Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> id_670 { id_669.options };
      uint32_t id_671 { id_670.size() };
      Vec<1, uint32_t> id_672 {  id_671  };
      Size let_res_673;
      {
        Vec<1, uint32_t> n_ref_709 { id_672 };
        uint32_t id_674 { 1U };
        Vec<1, uint32_t> id_675 {  id_674  };
        Size let_res_676;
        {
          Vec<1, uint32_t> lebsz_ref_710 { id_675 };
          bool while_flag_677 { true };
          do {
            uint8_t id_678 { 0 };
            uint32_t id_679 { n_ref_709[id_678] };
            uint8_t id_680 { 0 };
            uint32_t id_681 { lebsz_ref_710[id_680] };
            uint8_t id_682 { 7 };
            uint32_t id_683 { uint32_t(id_681 << id_682) };
            bool id_684 { bool(id_679 >= id_683) };
            while_flag_677 = id_684;
            if (while_flag_677) {
              uint8_t id_685 { 0 };
              uint8_t id_686 { 0 };
              uint32_t id_687 { lebsz_ref_710[id_686] };
              uint32_t id_688 { 1U };
              uint32_t id_689 { uint32_t(id_687 + id_688) };
              Void id_690 { ((void)(lebsz_ref_710[id_685] = id_689), ::dessser::Void()) };
              (void)id_690;
            }
          } while (while_flag_677);
          (void)::dessser::Void();
          uint8_t id_691 { 0 };
          uint32_t id_692 { lebsz_ref_710[id_691] };
          Size id_693 { Size(id_692) };
          let_res_676 = id_693;
        }
        let_res_673 = let_res_676;
      }
      Size id_694 { Size(id_668 + let_res_673) };
      Vec<1, Size> id_695 {  id_694  };
      Size let_res_696;
      {
        Vec<1, Size> sz_ref_711 { id_695 };
        int32_t id_697 { 0L };
        Vec<1, int32_t> id_698 {  id_697  };
        {
          Vec<1, int32_t> repeat_n_712 { id_698 };
          bool while_flag_699 { true };
          do {
            ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_700 { std::get<1 /* Kafka */>(p_0) };
            Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> id_701 { id_700.options };
            uint32_t id_702 { id_701.size() };
            int32_t id_703 { int32_t(id_702) };
            uint8_t id_704 { 0 };
            int32_t id_705 { repeat_n_712[id_704] };
            bool id_706 { bool(id_703 > id_705) };
            while_flag_699 = id_706;
            if (while_flag_699) {
              uint8_t id_707 { 0 };
              uint8_t id_708 { 0 };
              Size id_709 { sz_ref_711[id_708] };
              Size let_res_710;
              {
                Size sz_713 { id_709 };
                uint8_t id_711 { 0 };
                int32_t id_712 { repeat_n_712[id_711] };
                ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_713 { std::get<1 /* Kafka */>(p_0) };
                Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> id_714 { id_713.options };
                ::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a id_715 { id_714[id_712] };
                std::string id_716 { std::get<0>(id_715) };
                uint32_t id_717 { (uint32_t)id_716.size() };
                Size let_res_718;
                {
                  uint32_t wlen_714 { id_717 };
                  Vec<1, uint32_t> id_719 {  wlen_714  };
                  Size let_res_720;
                  {
                    Vec<1, uint32_t> n_ref_715 { id_719 };
                    uint32_t id_721 { 1U };
                    Vec<1, uint32_t> id_722 {  id_721  };
                    Size let_res_723;
                    {
                      Vec<1, uint32_t> lebsz_ref_716 { id_722 };
                      bool while_flag_724 { true };
                      do {
                        uint8_t id_725 { 0 };
                        uint32_t id_726 { n_ref_715[id_725] };
                        uint8_t id_727 { 0 };
                        uint32_t id_728 { lebsz_ref_716[id_727] };
                        uint8_t id_729 { 7 };
                        uint32_t id_730 { uint32_t(id_728 << id_729) };
                        bool id_731 { bool(id_726 >= id_730) };
                        while_flag_724 = id_731;
                        if (while_flag_724) {
                          uint8_t id_732 { 0 };
                          uint8_t id_733 { 0 };
                          uint32_t id_734 { lebsz_ref_716[id_733] };
                          uint32_t id_735 { 1U };
                          uint32_t id_736 { uint32_t(id_734 + id_735) };
                          Void id_737 { ((void)(lebsz_ref_716[id_732] = id_736), ::dessser::Void()) };
                          (void)id_737;
                        }
                      } while (while_flag_724);
                      (void)::dessser::Void();
                      uint8_t id_738 { 0 };
                      uint32_t id_739 { lebsz_ref_716[id_738] };
                      Size id_740 { Size(id_739) };
                      let_res_723 = id_740;
                    }
                    let_res_720 = let_res_723;
                  }
                  Size id_741 { Size(wlen_714) };
                  Size id_742 { Size(let_res_720 + id_741) };
                  let_res_718 = id_742;
                }
                Size id_743 { Size(sz_713 + let_res_718) };
                let_res_710 = id_743;
              }
              Size let_res_744;
              {
                Size sz_717 { let_res_710 };
                auto fun745 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_746 { 0 };
                int32_t id_747 { repeat_n_712[id_746] };
                ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_748 { std::get<1 /* Kafka */>(p_0) };
                Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> id_749 { id_748.options };
                ::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a id_750 { id_749[id_747] };
                dessser::gen::raql_expr::t_ext id_751 { std::get<1>(id_750) };
                Size id_752 { fun745(id_751) };
                Size id_753 { Size(sz_717 + id_752) };
                let_res_744 = id_753;
              }
              Void id_754 { ((void)(sz_ref_711[id_707] = let_res_744), ::dessser::Void()) };
              (void)id_754;
              uint8_t id_755 { 0 };
              uint8_t id_756 { 0 };
              int32_t id_757 { repeat_n_712[id_756] };
              int32_t id_758 { 1L };
              int32_t id_759 { int32_t(id_757 + id_758) };
              Void id_760 { ((void)(repeat_n_712[id_755] = id_759), ::dessser::Void()) };
              (void)id_760;
              (void)id_760;
            }
          } while (while_flag_699);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_761 { 0 };
        Size id_762 { sz_ref_711[id_761] };
        let_res_696 = id_762;
      }
      Size let_res_763;
      {
        Size sz_718 { let_res_696 };
        auto fun764 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_765 { std::get<1 /* Kafka */>(p_0) };
        dessser::gen::raql_expr::t_ext id_766 { id_765.topic };
        Size id_767 { fun764(id_766) };
        Size id_768 { Size(sz_718 + id_767) };
        let_res_763 = id_768;
      }
      Size let_res_769;
      {
        Size sz_719 { let_res_763 };
        ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_770 { std::get<1 /* Kafka */>(p_0) };
        std::optional<dessser::gen::raql_expr::t_ext> id_771 { id_770.partitions };
        bool id_772 { !(id_771.has_value ()) };
        Size choose_res_773;
        if (id_772) {
          Size id_774 { 1UL };
          Size id_775 { Size(sz_719 + id_774) };
          choose_res_773 = id_775;
        } else {
          auto fun776 { dessser::gen::raql_expr::sersize_of_row_binary };
          ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_777 { std::get<1 /* Kafka */>(p_0) };
          std::optional<dessser::gen::raql_expr::t_ext> id_778 { id_777.partitions };
          dessser::gen::raql_expr::t_ext id_779 { id_778.value() };
          Size id_780 { fun776(id_779) };
          Size id_781 { Size(sz_719 + id_780) };
          Size id_782 { 1UL };
          Size id_783 { Size(id_781 + id_782) };
          choose_res_773 = id_783;
        }
        let_res_769 = choose_res_773;
      }
      Size let_res_784;
      {
        Size sz_720 { let_res_769 };
        uint16_t id_785 { 0 };
        ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_786 { std::get<1 /* Kafka */>(p_0) };
        ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_787 { id_786.restart_from };
        uint16_t id_788 { uint16_t(id_787.index()) };
        bool id_789 { bool(id_785 == id_788) };
        Size choose_res_790;
        if (id_789) {
          Size id_791 { 2UL };
          Size id_792 { Size(sz_720 + id_791) };
          choose_res_790 = id_792;
        } else {
          uint16_t id_793 { 1 };
          ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_794 { std::get<1 /* Kafka */>(p_0) };
          ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_795 { id_794.restart_from };
          uint16_t id_796 { uint16_t(id_795.index()) };
          bool id_797 { bool(id_793 == id_796) };
          Size choose_res_798;
          if (id_797) {
            Size id_799 { 2UL };
            Size id_800 { Size(sz_720 + id_799) };
            auto fun801 { dessser::gen::raql_expr::sersize_of_row_binary };
            ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_802 { std::get<1 /* Kafka */>(p_0) };
            ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_803 { id_802.restart_from };
            dessser::gen::raql_expr::t_ext id_804 { std::get<1 /* OffsetFromEnd */>(id_803) };
            Size id_805 { fun801(id_804) };
            Size id_806 { Size(id_800 + id_805) };
            choose_res_798 = id_806;
          } else {
            uint16_t id_807 { 2 };
            ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_808 { std::get<1 /* Kafka */>(p_0) };
            ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_809 { id_808.restart_from };
            uint16_t id_810 { uint16_t(id_809.index()) };
            bool id_811 { bool(id_807 == id_810) };
            Size choose_res_812;
            if (id_811) {
              Size id_813 { 2UL };
              Size id_814 { Size(sz_720 + id_813) };
              choose_res_812 = id_814;
            } else {
              ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_815 { std::get<1 /* Kafka */>(p_0) };
              ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_816 { id_815.restart_from };
              uint16_t id_817 { uint16_t(id_816.index()) };
              uint16_t id_818 { 3 };
              bool id_819 { bool(id_817 == id_818) };
              Void id_820 { ((void)(assert(id_819)), ::dessser::Void()) };
              (void)id_820;
              Size id_821 { 2UL };
              Size id_822 { Size(sz_720 + id_821) };
              auto fun823 { dessser::gen::raql_expr::sersize_of_row_binary };
              ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_824 { std::get<1 /* Kafka */>(p_0) };
              ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_825 { id_824.restart_from };
              ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_826 { std::get<3 /* UseKafkaGroupCoordinator */>(id_825) };
              dessser::gen::raql_expr::t_ext id_827 { id_826.after_max_secs };
              Size id_828 { fun823(id_827) };
              Size id_829 { Size(id_822 + id_828) };
              Size let_res_830;
              {
                Size sz_723 { id_829 };
                auto fun831 { dessser::gen::raql_expr::sersize_of_row_binary };
                ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_832 { std::get<1 /* Kafka */>(p_0) };
                ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_833 { id_832.restart_from };
                ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_834 { std::get<3 /* UseKafkaGroupCoordinator */>(id_833) };
                dessser::gen::raql_expr::t_ext id_835 { id_834.after_max_events };
                Size id_836 { fun831(id_835) };
                Size id_837 { Size(sz_723 + id_836) };
                let_res_830 = id_837;
              }
              choose_res_812 = let_res_830;
            }
            choose_res_798 = choose_res_812;
          }
          choose_res_790 = choose_res_798;
        }
        let_res_784 = choose_res_790;
      }
      choose_res_636 = let_res_784;
    }
    return choose_res_636;
  }
   };
  return fun632;
}
std::function<Size(::dessser::gen::raql_operation::external_source &)> external_source_sersize_of_row_binary(external_source_sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_242" (let-pair "du16_fst_237" "du16_snd_238" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_237") (identifier "du16_snd_238")))
        (let-pair "dsum1_fst_243" "dsum1_snd_244" (identifier "dsum1_242")
          (if (eq (u16 0) (identifier "dsum1_fst_243"))
            (let "drec_274" (let-pair "dchar_fst_272" "dchar_snd_273" (read-u8 (identifier "dsum1_snd_244")) (make-tup (char-of-u8 (identifier "dchar_fst_272")) (identifier "dchar_snd_273")))
              (let-pair "drec_fst_275" "drec_snd_276" (identifier "drec_274")
                (let "drec_289"
                  (let "dstring1_283"
                    (let "leb_ref_277" (make-vec (u32 0))
                      (let "shft_ref_278" (make-vec (u8 0))
                        (let "p_ref_279" (make-vec (identifier "drec_snd_276"))
                          (seq
                            (while
                              (let "leb128_280" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_279")))
                                (let-pair "leb128_fst_281" "leb128_snd_282" 
                                  (identifier "leb128_280")
                                  (seq (set-vec (u8 0) (identifier "p_ref_279") (identifier "leb128_snd_282"))
                                    (set-vec (u8 0) (identifier "leb_ref_277")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_281") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_278"))) (unsafe-nth (u8 0) (identifier "leb_ref_277"))))
                                    (set-vec (u8 0) (identifier "shft_ref_278") (add (unsafe-nth (u8 0) (identifier "shft_ref_278")) (u8 7))) 
                                    (ge (identifier "leb128_fst_281") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_277"))) (unsafe-nth (u8 0) (identifier "p_ref_279")))))))
                    (let-pair "dstring1_fst_284" "dstring1_snd_285" (identifier "dstring1_283")
                      (let-pair "dstring2_fst_287" "dstring2_snd_288" 
                        (read-bytes (identifier "dstring1_snd_285") (identifier "dstring1_fst_284")) 
                        (make-tup (string-of-bytes (identifier "dstring2_fst_287")) (identifier "dstring2_snd_288")))))
                  (let-pair "drec_fst_290" "drec_snd_291" (identifier "drec_289")
                    (let "drec_295" (let-pair "dbool_fst_293" "dbool_snd_294" (read-u8 (identifier "drec_snd_291")) (make-tup (not (eq (identifier "dbool_fst_293") (u8 0))) (identifier "dbool_snd_294")))
                      (let-pair "drec_fst_296" "drec_snd_297" (identifier "drec_295")
                        (let "drec_310"
                          (let "dstring1_304"
                            (let "leb_ref_298" (make-vec (u32 0))
                              (let "shft_ref_299" (make-vec (u8 0))
                                (let "p_ref_300" (make-vec (identifier "drec_snd_297"))
                                  (seq
                                    (while
                                      (let "leb128_301" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_300")))
                                        (let-pair "leb128_fst_302" "leb128_snd_303" 
                                          (identifier "leb128_301")
                                          (seq (set-vec (u8 0) (identifier "p_ref_300") (identifier "leb128_snd_303"))
                                            (set-vec (u8 0) (identifier "leb_ref_298")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_302") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_299"))) (unsafe-nth (u8 0) (identifier "leb_ref_298"))))
                                            (set-vec (u8 0) (identifier "shft_ref_299") (add (unsafe-nth (u8 0) (identifier "shft_ref_299")) (u8 7))) 
                                            (ge (identifier "leb128_fst_302") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_298"))) (unsafe-nth (u8 0) (identifier "p_ref_300")))))))
                            (let-pair "dstring1_fst_305" "dstring1_snd_306" 
                              (identifier "dstring1_304")
                              (let-pair "dstring2_fst_308" "dstring2_snd_309" 
                                (read-bytes (identifier "dstring1_snd_306") (identifier "dstring1_fst_305")) 
                                (make-tup (string-of-bytes (identifier "dstring2_fst_308")) (identifier "dstring2_snd_309")))))
                          (let-pair "drec_fst_311" "drec_snd_312" (identifier "drec_310")
                            (let "drec_336"
                              (let-pair "dlist4_fst_334" "dlist4_snd_335"
                                (let "dlist1_322"
                                  (let "leb_ref_313" (make-vec (u32 0))
                                    (let "shft_ref_314" (make-vec (u8 0))
                                      (let "p_ref_315" (make-vec (identifier "drec_snd_312"))
                                        (seq
                                          (while
                                            (let "leb128_316" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_315")))
                                              (let-pair "leb128_fst_317" "leb128_snd_318" 
                                                (identifier "leb128_316")
                                                (seq (set-vec (u8 0) (identifier "p_ref_315") (identifier "leb128_snd_318"))
                                                  (set-vec (u8 0) (identifier "leb_ref_313")
                                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_317") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_314"))) (unsafe-nth (u8 0) (identifier "leb_ref_313"))))
                                                  (set-vec (u8 0) (identifier "shft_ref_314") (add (unsafe-nth (u8 0) (identifier "shft_ref_314")) (u8 7))) 
                                                  (ge (identifier "leb128_fst_317") (u8 128))))) 
                                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_313")) (unsafe-nth (u8 0) (identifier "p_ref_315")))))))
                                  (let-pair "dlist1_fst_323" "dlist1_snd_324" 
                                    (identifier "dlist1_322")
                                    (let "inits_src_ref_325" (make-vec (make-tup (end-of-list "$field_type") (identifier "dlist1_snd_324")))
                                      (seq
                                        (let "repeat_n_326" (make-vec (i32 0))
                                          (while (gt (to-i32 (identifier "dlist1_fst_323")) (unsafe-nth (u8 0) (identifier "repeat_n_326")))
                                            (seq
                                              (let "dlist2_327" (unsafe-nth (u8 0) (identifier "inits_src_ref_325"))
                                                (let-pair "dlist2_fst_328" "dlist2_snd_329" 
                                                  (identifier "dlist2_327")
                                                  (set-vec (u8 0) (identifier "inits_src_ref_325")
                                                    (let-pair "dlist3_fst_331" "dlist3_snd_332" 
                                                      (apply (ext-identifier field_type of-row-binary) (identifier "dlist2_snd_329"))
                                                      (make-tup (cons (identifier "dlist3_fst_331") (identifier "dlist2_fst_328")) (identifier "dlist3_snd_332"))))))
                                              (set-vec (u8 0) (identifier "repeat_n_326") (add (unsafe-nth (u8 0) (identifier "repeat_n_326")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_325")))))) 
                                (make-tup (identity (identifier "dlist4_fst_334")) (identifier "dlist4_snd_335")))
                              (let-pair "drec_fst_337" "drec_snd_338" 
                                (identifier "drec_336")
                                (let "drec_342" (let-pair "dbool_fst_340" "dbool_snd_341" (read-u8 (identifier "drec_snd_338")) (make-tup (not (eq (identifier "dbool_fst_340") (u8 0))) (identifier "dbool_snd_341")))
                                  (let-pair "drec_fst_343" "drec_snd_344" 
                                    (identifier "drec_342")
                                    (let-pair "dbool_fst_346" "dbool_snd_347" 
                                      (read-u8 (identifier "drec_snd_344"))
                                      (make-tup
                                        (construct "[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" 0
                                          (make-rec (string "clickhouse_syntax") 
                                            (not (eq (identifier "dbool_fst_346") (u8 0))) 
                                            (string "vectors_of_chars_as_string") 
                                            (identifier "drec_fst_343") 
                                            (string "fields") (identifier "drec_fst_337") 
                                            (string "escape_seq") (identifier "drec_fst_311") 
                                            (string "may_quote") (identifier "drec_fst_296") 
                                            (string "null") (identifier "drec_fst_290") 
                                            (string "separator") (identifier "drec_fst_275"))) 
                                        (identifier "dbool_snd_347")))))))))))))))
            (seq (assert (eq (identifier "dsum1_fst_243") (u16 1)))
              (let-pair "dlist4_fst_266" "dlist4_snd_267"
                (let "dlist1_254"
                  (let "leb_ref_245" (make-vec (u32 0))
                    (let "shft_ref_246" (make-vec (u8 0))
                      (let "p_ref_247" (make-vec (identifier "dsum1_snd_244"))
                        (seq
                          (while
                            (let "leb128_248" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_247")))
                              (let-pair "leb128_fst_249" "leb128_snd_250" 
                                (identifier "leb128_248")
                                (seq (set-vec (u8 0) (identifier "p_ref_247") (identifier "leb128_snd_250"))
                                  (set-vec (u8 0) (identifier "leb_ref_245")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_249") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_246"))) (unsafe-nth (u8 0) (identifier "leb_ref_245"))))
                                  (set-vec (u8 0) (identifier "shft_ref_246") (add (unsafe-nth (u8 0) (identifier "shft_ref_246")) (u8 7))) 
                                  (ge (identifier "leb128_fst_249") (u8 128))))) 
                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_245")) (unsafe-nth (u8 0) (identifier "p_ref_247")))))))
                  (let-pair "dlist1_fst_255" "dlist1_snd_256" (identifier "dlist1_254")
                    (let "inits_src_ref_257" (make-vec (make-tup (end-of-list "$field_type") (identifier "dlist1_snd_256")))
                      (seq
                        (let "repeat_n_258" (make-vec (i32 0))
                          (while (gt (to-i32 (identifier "dlist1_fst_255")) (unsafe-nth (u8 0) (identifier "repeat_n_258")))
                            (seq
                              (let "dlist2_259" (unsafe-nth (u8 0) (identifier "inits_src_ref_257"))
                                (let-pair "dlist2_fst_260" "dlist2_snd_261" 
                                  (identifier "dlist2_259")
                                  (set-vec (u8 0) (identifier "inits_src_ref_257")
                                    (let-pair "dlist3_fst_263" "dlist3_snd_264" 
                                      (apply (ext-identifier field_type of-row-binary) (identifier "dlist2_snd_261")) 
                                      (make-tup (cons (identifier "dlist3_fst_263") (identifier "dlist2_fst_260")) (identifier "dlist3_snd_264"))))))
                              (set-vec (u8 0) (identifier "repeat_n_258") (add (unsafe-nth (u8 0) (identifier "repeat_n_258")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "inits_src_ref_257"))))))
                (make-tup
                  (construct "[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" 1
                    (identity (identifier "dlist4_fst_266"))) (identifier "dlist4_snd_267"))))))))
 */
static std::function<::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4(Pointer &)> external_format_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4(Pointer &)> fun838 { [&](Pointer p_0) {
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_839 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_840;
    {
      auto du16_fst_237 { std::get<0>(id_839) };
      auto du16_snd_238 { std::get<1>(id_839) };
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_841 { du16_fst_237, du16_snd_238 };
      letpair_res_840 = id_841;
    }
    ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 let_res_842;
    {
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_242 { letpair_res_840 };
      ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 letpair_res_843;
      {
        auto dsum1_fst_243 { std::get<0>(dsum1_242) };
        auto dsum1_snd_244 { std::get<1>(dsum1_242) };
        uint16_t id_844 { 0 };
        bool id_845 { bool(id_844 == dsum1_fst_243) };
        ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 choose_res_846;
        if (id_845) {
          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_847 { dsum1_snd_244.readU8() };
          ::dessser::gen::raql_operation::tfa74ce2af9d2c970f57cbdfa42fae458 letpair_res_848;
          {
            auto dchar_fst_272 { std::get<0>(id_847) };
            auto dchar_snd_273 { std::get<1>(id_847) };
            char id_849 { char(dchar_fst_272) };
            ::dessser::gen::raql_operation::tfa74ce2af9d2c970f57cbdfa42fae458 id_850 { id_849, dchar_snd_273 };
            letpair_res_848 = id_850;
          }
          ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 let_res_851;
          {
            ::dessser::gen::raql_operation::tfa74ce2af9d2c970f57cbdfa42fae458 drec_274 { letpair_res_848 };
            ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 letpair_res_852;
            {
              auto drec_fst_275 { std::get<0>(drec_274) };
              auto drec_snd_276 { std::get<1>(drec_274) };
              uint32_t id_853 { 0U };
              Vec<1, uint32_t> id_854 {  id_853  };
              ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_855;
              {
                Vec<1, uint32_t> leb_ref_277 { id_854 };
                uint8_t id_856 { 0 };
                Vec<1, uint8_t> id_857 {  id_856  };
                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_858;
                {
                  Vec<1, uint8_t> shft_ref_278 { id_857 };
                  Vec<1, Pointer> id_859 {  drec_snd_276  };
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_860;
                  {
                    Vec<1, Pointer> p_ref_279 { id_859 };
                    bool while_flag_861 { true };
                    do {
                      uint8_t id_862 { 0 };
                      Pointer id_863 { p_ref_279[id_862] };
                      ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_864 { id_863.readU8() };
                      bool let_res_865;
                      {
                        ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_280 { id_864 };
                        bool letpair_res_866;
                        {
                          auto leb128_fst_281 { std::get<0>(leb128_280) };
                          auto leb128_snd_282 { std::get<1>(leb128_280) };
                          uint8_t id_867 { 0 };
                          Void id_868 { ((void)(p_ref_279[id_867] = leb128_snd_282), ::dessser::Void()) };
                          (void)id_868;
                          uint8_t id_869 { 0 };
                          uint8_t id_870 { 127 };
                          uint8_t id_871 { uint8_t(leb128_fst_281 & id_870) };
                          uint32_t id_872 { uint32_t(id_871) };
                          uint8_t id_873 { 0 };
                          uint8_t id_874 { shft_ref_278[id_873] };
                          uint32_t id_875 { uint32_t(id_872 << id_874) };
                          uint8_t id_876 { 0 };
                          uint32_t id_877 { leb_ref_277[id_876] };
                          uint32_t id_878 { uint32_t(id_875 | id_877) };
                          Void id_879 { ((void)(leb_ref_277[id_869] = id_878), ::dessser::Void()) };
                          (void)id_879;
                          uint8_t id_880 { 0 };
                          uint8_t id_881 { 0 };
                          uint8_t id_882 { shft_ref_278[id_881] };
                          uint8_t id_883 { 7 };
                          uint8_t id_884 { uint8_t(id_882 + id_883) };
                          Void id_885 { ((void)(shft_ref_278[id_880] = id_884), ::dessser::Void()) };
                          (void)id_885;
                          uint8_t id_886 { 128 };
                          bool id_887 { bool(leb128_fst_281 >= id_886) };
                          letpair_res_866 = id_887;
                        }
                        let_res_865 = letpair_res_866;
                      }
                      while_flag_861 = let_res_865;
                      if (while_flag_861) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_861);
                    (void)::dessser::Void();
                    uint8_t id_888 { 0 };
                    uint32_t id_889 { leb_ref_277[id_888] };
                    Size id_890 { Size(id_889) };
                    uint8_t id_891 { 0 };
                    Pointer id_892 { p_ref_279[id_891] };
                    ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_893 { id_890, id_892 };
                    let_res_860 = id_893;
                  }
                  let_res_858 = let_res_860;
                }
                let_res_855 = let_res_858;
              }
              ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 let_res_894;
              {
                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_283 { let_res_855 };
                ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_895;
                {
                  auto dstring1_fst_284 { std::get<0>(dstring1_283) };
                  auto dstring1_snd_285 { std::get<1>(dstring1_283) };
                  ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_896 { dstring1_snd_285.readBytes(dstring1_fst_284) };
                  ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_897;
                  {
                    auto dstring2_fst_287 { std::get<0>(id_896) };
                    auto dstring2_snd_288 { std::get<1>(id_896) };
                    std::string id_898 { dstring2_fst_287.toString() };
                    ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 id_899 { id_898, dstring2_snd_288 };
                    letpair_res_897 = id_899;
                  }
                  letpair_res_895 = letpair_res_897;
                }
                let_res_894 = letpair_res_895;
              }
              ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 let_res_900;
              {
                ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 drec_289 { let_res_894 };
                ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 letpair_res_901;
                {
                  auto drec_fst_290 { std::get<0>(drec_289) };
                  auto drec_snd_291 { std::get<1>(drec_289) };
                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_902 { drec_snd_291.readU8() };
                  ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_903;
                  {
                    auto dbool_fst_293 { std::get<0>(id_902) };
                    auto dbool_snd_294 { std::get<1>(id_902) };
                    uint8_t id_904 { 0 };
                    bool id_905 { bool(dbool_fst_293 == id_904) };
                    bool id_906 { ! id_905 };
                    ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 id_907 { id_906, dbool_snd_294 };
                    letpair_res_903 = id_907;
                  }
                  ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 let_res_908;
                  {
                    ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 drec_295 { letpair_res_903 };
                    ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 letpair_res_909;
                    {
                      auto drec_fst_296 { std::get<0>(drec_295) };
                      auto drec_snd_297 { std::get<1>(drec_295) };
                      uint32_t id_910 { 0U };
                      Vec<1, uint32_t> id_911 {  id_910  };
                      ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_912;
                      {
                        Vec<1, uint32_t> leb_ref_298 { id_911 };
                        uint8_t id_913 { 0 };
                        Vec<1, uint8_t> id_914 {  id_913  };
                        ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_915;
                        {
                          Vec<1, uint8_t> shft_ref_299 { id_914 };
                          Vec<1, Pointer> id_916 {  drec_snd_297  };
                          ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_917;
                          {
                            Vec<1, Pointer> p_ref_300 { id_916 };
                            bool while_flag_918 { true };
                            do {
                              uint8_t id_919 { 0 };
                              Pointer id_920 { p_ref_300[id_919] };
                              ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_921 { id_920.readU8() };
                              bool let_res_922;
                              {
                                ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_301 { id_921 };
                                bool letpair_res_923;
                                {
                                  auto leb128_fst_302 { std::get<0>(leb128_301) };
                                  auto leb128_snd_303 { std::get<1>(leb128_301) };
                                  uint8_t id_924 { 0 };
                                  Void id_925 { ((void)(p_ref_300[id_924] = leb128_snd_303), ::dessser::Void()) };
                                  (void)id_925;
                                  uint8_t id_926 { 0 };
                                  uint8_t id_927 { 127 };
                                  uint8_t id_928 { uint8_t(leb128_fst_302 & id_927) };
                                  uint32_t id_929 { uint32_t(id_928) };
                                  uint8_t id_930 { 0 };
                                  uint8_t id_931 { shft_ref_299[id_930] };
                                  uint32_t id_932 { uint32_t(id_929 << id_931) };
                                  uint8_t id_933 { 0 };
                                  uint32_t id_934 { leb_ref_298[id_933] };
                                  uint32_t id_935 { uint32_t(id_932 | id_934) };
                                  Void id_936 { ((void)(leb_ref_298[id_926] = id_935), ::dessser::Void()) };
                                  (void)id_936;
                                  uint8_t id_937 { 0 };
                                  uint8_t id_938 { 0 };
                                  uint8_t id_939 { shft_ref_299[id_938] };
                                  uint8_t id_940 { 7 };
                                  uint8_t id_941 { uint8_t(id_939 + id_940) };
                                  Void id_942 { ((void)(shft_ref_299[id_937] = id_941), ::dessser::Void()) };
                                  (void)id_942;
                                  uint8_t id_943 { 128 };
                                  bool id_944 { bool(leb128_fst_302 >= id_943) };
                                  letpair_res_923 = id_944;
                                }
                                let_res_922 = letpair_res_923;
                              }
                              while_flag_918 = let_res_922;
                              if (while_flag_918) {
                                (void)::dessser::Void();
                              }
                            } while (while_flag_918);
                            (void)::dessser::Void();
                            uint8_t id_945 { 0 };
                            uint32_t id_946 { leb_ref_298[id_945] };
                            Size id_947 { Size(id_946) };
                            uint8_t id_948 { 0 };
                            Pointer id_949 { p_ref_300[id_948] };
                            ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_950 { id_947, id_949 };
                            let_res_917 = id_950;
                          }
                          let_res_915 = let_res_917;
                        }
                        let_res_912 = let_res_915;
                      }
                      ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 let_res_951;
                      {
                        ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_304 { let_res_912 };
                        ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_952;
                        {
                          auto dstring1_fst_305 { std::get<0>(dstring1_304) };
                          auto dstring1_snd_306 { std::get<1>(dstring1_304) };
                          ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_953 { dstring1_snd_306.readBytes(dstring1_fst_305) };
                          ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_954;
                          {
                            auto dstring2_fst_308 { std::get<0>(id_953) };
                            auto dstring2_snd_309 { std::get<1>(id_953) };
                            std::string id_955 { dstring2_fst_308.toString() };
                            ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 id_956 { id_955, dstring2_snd_309 };
                            letpair_res_954 = id_956;
                          }
                          letpair_res_952 = letpair_res_954;
                        }
                        let_res_951 = letpair_res_952;
                      }
                      ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 let_res_957;
                      {
                        ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 drec_310 { let_res_951 };
                        ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 letpair_res_958;
                        {
                          auto drec_fst_311 { std::get<0>(drec_310) };
                          auto drec_snd_312 { std::get<1>(drec_310) };
                          uint32_t id_959 { 0U };
                          Vec<1, uint32_t> id_960 {  id_959  };
                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_961;
                          {
                            Vec<1, uint32_t> leb_ref_313 { id_960 };
                            uint8_t id_962 { 0 };
                            Vec<1, uint8_t> id_963 {  id_962  };
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_964;
                            {
                              Vec<1, uint8_t> shft_ref_314 { id_963 };
                              Vec<1, Pointer> id_965 {  drec_snd_312  };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_966;
                              {
                                Vec<1, Pointer> p_ref_315 { id_965 };
                                bool while_flag_967 { true };
                                do {
                                  uint8_t id_968 { 0 };
                                  Pointer id_969 { p_ref_315[id_968] };
                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_970 { id_969.readU8() };
                                  bool let_res_971;
                                  {
                                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_316 { id_970 };
                                    bool letpair_res_972;
                                    {
                                      auto leb128_fst_317 { std::get<0>(leb128_316) };
                                      auto leb128_snd_318 { std::get<1>(leb128_316) };
                                      uint8_t id_973 { 0 };
                                      Void id_974 { ((void)(p_ref_315[id_973] = leb128_snd_318), ::dessser::Void()) };
                                      (void)id_974;
                                      uint8_t id_975 { 0 };
                                      uint8_t id_976 { 127 };
                                      uint8_t id_977 { uint8_t(leb128_fst_317 & id_976) };
                                      uint32_t id_978 { uint32_t(id_977) };
                                      uint8_t id_979 { 0 };
                                      uint8_t id_980 { shft_ref_314[id_979] };
                                      uint32_t id_981 { uint32_t(id_978 << id_980) };
                                      uint8_t id_982 { 0 };
                                      uint32_t id_983 { leb_ref_313[id_982] };
                                      uint32_t id_984 { uint32_t(id_981 | id_983) };
                                      Void id_985 { ((void)(leb_ref_313[id_975] = id_984), ::dessser::Void()) };
                                      (void)id_985;
                                      uint8_t id_986 { 0 };
                                      uint8_t id_987 { 0 };
                                      uint8_t id_988 { shft_ref_314[id_987] };
                                      uint8_t id_989 { 7 };
                                      uint8_t id_990 { uint8_t(id_988 + id_989) };
                                      Void id_991 { ((void)(shft_ref_314[id_986] = id_990), ::dessser::Void()) };
                                      (void)id_991;
                                      uint8_t id_992 { 128 };
                                      bool id_993 { bool(leb128_fst_317 >= id_992) };
                                      letpair_res_972 = id_993;
                                    }
                                    let_res_971 = letpair_res_972;
                                  }
                                  while_flag_967 = let_res_971;
                                  if (while_flag_967) {
                                    (void)::dessser::Void();
                                  }
                                } while (while_flag_967);
                                (void)::dessser::Void();
                                uint8_t id_994 { 0 };
                                uint32_t id_995 { leb_ref_313[id_994] };
                                uint8_t id_996 { 0 };
                                Pointer id_997 { p_ref_315[id_996] };
                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_998 { id_995, id_997 };
                                let_res_966 = id_998;
                              }
                              let_res_964 = let_res_966;
                            }
                            let_res_961 = let_res_964;
                          }
                          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 let_res_999;
                          {
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_322 { let_res_961 };
                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1000;
                            {
                              auto dlist1_fst_323 { std::get<0>(dlist1_322) };
                              auto dlist1_snd_324 { std::get<1>(dlist1_322) };
                              Lst<dessser::gen::field_type::t_ext> endoflist_1001;
                              ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1002 { endoflist_1001, dlist1_snd_324 };
                              Vec<1, ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9> id_1003 {  id_1002  };
                              ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 let_res_1004;
                              {
                                Vec<1, ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9> inits_src_ref_325 { id_1003 };
                                int32_t id_1005 { 0L };
                                Vec<1, int32_t> id_1006 {  id_1005  };
                                {
                                  Vec<1, int32_t> repeat_n_326 { id_1006 };
                                  bool while_flag_1007 { true };
                                  do {
                                    int32_t id_1008 { int32_t(dlist1_fst_323) };
                                    uint8_t id_1009 { 0 };
                                    int32_t id_1010 { repeat_n_326[id_1009] };
                                    bool id_1011 { bool(id_1008 > id_1010) };
                                    while_flag_1007 = id_1011;
                                    if (while_flag_1007) {
                                      uint8_t id_1012 { 0 };
                                      ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1013 { inits_src_ref_325[id_1012] };
                                      {
                                        ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 dlist2_327 { id_1013 };
                                        {
                                          auto dlist2_fst_328 { std::get<0>(dlist2_327) };
                                          auto dlist2_snd_329 { std::get<1>(dlist2_327) };
                                          uint8_t id_1014 { 0 };
                                          auto fun1015 { dessser::gen::field_type::of_row_binary };
                                          ::dessser::gen::raql_operation::t20a180051b815e05487bcfd57d0d9adb id_1016 { fun1015(dlist2_snd_329) };
                                          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1017;
                                          {
                                            auto dlist3_fst_331 { std::get<0>(id_1016) };
                                            auto dlist3_snd_332 { std::get<1>(id_1016) };
                                            Lst<dessser::gen::field_type::t_ext> id_1018 { dlist3_fst_331, dlist2_fst_328 };
                                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1019 { id_1018, dlist3_snd_332 };
                                            letpair_res_1017 = id_1019;
                                          }
                                          Void id_1020 { ((void)(inits_src_ref_325[id_1014] = letpair_res_1017), ::dessser::Void()) };
                                          (void)id_1020;
                                        }
                                        (void)::dessser::Void();
                                      }
                                      (void)::dessser::Void();
                                      uint8_t id_1021 { 0 };
                                      uint8_t id_1022 { 0 };
                                      int32_t id_1023 { repeat_n_326[id_1022] };
                                      int32_t id_1024 { 1L };
                                      int32_t id_1025 { int32_t(id_1023 + id_1024) };
                                      Void id_1026 { ((void)(repeat_n_326[id_1021] = id_1025), ::dessser::Void()) };
                                      (void)id_1026;
                                      (void)id_1026;
                                    }
                                  } while (while_flag_1007);
                                  (void)::dessser::Void();
                                }
                                (void)::dessser::Void();
                                uint8_t id_1027 { 0 };
                                ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1028 { inits_src_ref_325[id_1027] };
                                let_res_1004 = id_1028;
                              }
                              letpair_res_1000 = let_res_1004;
                            }
                            let_res_999 = letpair_res_1000;
                          }
                          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1029;
                          {
                            auto dlist4_fst_334 { std::get<0>(let_res_999) };
                            auto dlist4_snd_335 { std::get<1>(let_res_999) };
                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1030 { dlist4_fst_334, dlist4_snd_335 };
                            letpair_res_1029 = id_1030;
                          }
                          ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 let_res_1031;
                          {
                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 drec_336 { letpair_res_1029 };
                            ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 letpair_res_1032;
                            {
                              auto drec_fst_337 { std::get<0>(drec_336) };
                              auto drec_snd_338 { std::get<1>(drec_336) };
                              ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1033 { drec_snd_338.readU8() };
                              ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1034;
                              {
                                auto dbool_fst_340 { std::get<0>(id_1033) };
                                auto dbool_snd_341 { std::get<1>(id_1033) };
                                uint8_t id_1035 { 0 };
                                bool id_1036 { bool(dbool_fst_340 == id_1035) };
                                bool id_1037 { ! id_1036 };
                                ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 id_1038 { id_1037, dbool_snd_341 };
                                letpair_res_1034 = id_1038;
                              }
                              ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 let_res_1039;
                              {
                                ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 drec_342 { letpair_res_1034 };
                                ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 letpair_res_1040;
                                {
                                  auto drec_fst_343 { std::get<0>(drec_342) };
                                  auto drec_snd_344 { std::get<1>(drec_342) };
                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1041 { drec_snd_344.readU8() };
                                  ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 letpair_res_1042;
                                  {
                                    auto dbool_fst_346 { std::get<0>(id_1041) };
                                    auto dbool_snd_347 { std::get<1>(id_1041) };
                                    uint8_t id_1043 { 0 };
                                    bool id_1044 { bool(dbool_fst_346 == id_1043) };
                                    bool id_1045 { ! id_1044 };
                                    ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_1046 { drec_fst_275, drec_fst_290, drec_fst_296, drec_fst_311, drec_fst_337, drec_fst_343, id_1045 };
                                    ::dessser::gen::raql_operation::external_format id_1047 { std::in_place_index<0>, id_1046 };
                                    ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 id_1048 { id_1047, dbool_snd_347 };
                                    letpair_res_1042 = id_1048;
                                  }
                                  letpair_res_1040 = letpair_res_1042;
                                }
                                let_res_1039 = letpair_res_1040;
                              }
                              letpair_res_1032 = let_res_1039;
                            }
                            let_res_1031 = letpair_res_1032;
                          }
                          letpair_res_958 = let_res_1031;
                        }
                        let_res_957 = letpair_res_958;
                      }
                      letpair_res_909 = let_res_957;
                    }
                    let_res_908 = letpair_res_909;
                  }
                  letpair_res_901 = let_res_908;
                }
                let_res_900 = letpair_res_901;
              }
              letpair_res_852 = let_res_900;
            }
            let_res_851 = letpair_res_852;
          }
          choose_res_846 = let_res_851;
        } else {
          uint16_t id_1049 { 1 };
          bool id_1050 { bool(dsum1_fst_243 == id_1049) };
          Void id_1051 { ((void)(assert(id_1050)), ::dessser::Void()) };
          (void)id_1051;
          uint32_t id_1052 { 0U };
          Vec<1, uint32_t> id_1053 {  id_1052  };
          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1054;
          {
            Vec<1, uint32_t> leb_ref_245 { id_1053 };
            uint8_t id_1055 { 0 };
            Vec<1, uint8_t> id_1056 {  id_1055  };
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1057;
            {
              Vec<1, uint8_t> shft_ref_246 { id_1056 };
              Vec<1, Pointer> id_1058 {  dsum1_snd_244  };
              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1059;
              {
                Vec<1, Pointer> p_ref_247 { id_1058 };
                bool while_flag_1060 { true };
                do {
                  uint8_t id_1061 { 0 };
                  Pointer id_1062 { p_ref_247[id_1061] };
                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1063 { id_1062.readU8() };
                  bool let_res_1064;
                  {
                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_248 { id_1063 };
                    bool letpair_res_1065;
                    {
                      auto leb128_fst_249 { std::get<0>(leb128_248) };
                      auto leb128_snd_250 { std::get<1>(leb128_248) };
                      uint8_t id_1066 { 0 };
                      Void id_1067 { ((void)(p_ref_247[id_1066] = leb128_snd_250), ::dessser::Void()) };
                      (void)id_1067;
                      uint8_t id_1068 { 0 };
                      uint8_t id_1069 { 127 };
                      uint8_t id_1070 { uint8_t(leb128_fst_249 & id_1069) };
                      uint32_t id_1071 { uint32_t(id_1070) };
                      uint8_t id_1072 { 0 };
                      uint8_t id_1073 { shft_ref_246[id_1072] };
                      uint32_t id_1074 { uint32_t(id_1071 << id_1073) };
                      uint8_t id_1075 { 0 };
                      uint32_t id_1076 { leb_ref_245[id_1075] };
                      uint32_t id_1077 { uint32_t(id_1074 | id_1076) };
                      Void id_1078 { ((void)(leb_ref_245[id_1068] = id_1077), ::dessser::Void()) };
                      (void)id_1078;
                      uint8_t id_1079 { 0 };
                      uint8_t id_1080 { 0 };
                      uint8_t id_1081 { shft_ref_246[id_1080] };
                      uint8_t id_1082 { 7 };
                      uint8_t id_1083 { uint8_t(id_1081 + id_1082) };
                      Void id_1084 { ((void)(shft_ref_246[id_1079] = id_1083), ::dessser::Void()) };
                      (void)id_1084;
                      uint8_t id_1085 { 128 };
                      bool id_1086 { bool(leb128_fst_249 >= id_1085) };
                      letpair_res_1065 = id_1086;
                    }
                    let_res_1064 = letpair_res_1065;
                  }
                  while_flag_1060 = let_res_1064;
                  if (while_flag_1060) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_1060);
                (void)::dessser::Void();
                uint8_t id_1087 { 0 };
                uint32_t id_1088 { leb_ref_245[id_1087] };
                uint8_t id_1089 { 0 };
                Pointer id_1090 { p_ref_247[id_1089] };
                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_1091 { id_1088, id_1090 };
                let_res_1059 = id_1091;
              }
              let_res_1057 = let_res_1059;
            }
            let_res_1054 = let_res_1057;
          }
          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 let_res_1092;
          {
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_254 { let_res_1054 };
            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1093;
            {
              auto dlist1_fst_255 { std::get<0>(dlist1_254) };
              auto dlist1_snd_256 { std::get<1>(dlist1_254) };
              Lst<dessser::gen::field_type::t_ext> endoflist_1094;
              ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1095 { endoflist_1094, dlist1_snd_256 };
              Vec<1, ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9> id_1096 {  id_1095  };
              ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 let_res_1097;
              {
                Vec<1, ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9> inits_src_ref_257 { id_1096 };
                int32_t id_1098 { 0L };
                Vec<1, int32_t> id_1099 {  id_1098  };
                {
                  Vec<1, int32_t> repeat_n_258 { id_1099 };
                  bool while_flag_1100 { true };
                  do {
                    int32_t id_1101 { int32_t(dlist1_fst_255) };
                    uint8_t id_1102 { 0 };
                    int32_t id_1103 { repeat_n_258[id_1102] };
                    bool id_1104 { bool(id_1101 > id_1103) };
                    while_flag_1100 = id_1104;
                    if (while_flag_1100) {
                      uint8_t id_1105 { 0 };
                      ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1106 { inits_src_ref_257[id_1105] };
                      {
                        ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 dlist2_259 { id_1106 };
                        {
                          auto dlist2_fst_260 { std::get<0>(dlist2_259) };
                          auto dlist2_snd_261 { std::get<1>(dlist2_259) };
                          uint8_t id_1107 { 0 };
                          auto fun1108 { dessser::gen::field_type::of_row_binary };
                          ::dessser::gen::raql_operation::t20a180051b815e05487bcfd57d0d9adb id_1109 { fun1108(dlist2_snd_261) };
                          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1110;
                          {
                            auto dlist3_fst_263 { std::get<0>(id_1109) };
                            auto dlist3_snd_264 { std::get<1>(id_1109) };
                            Lst<dessser::gen::field_type::t_ext> id_1111 { dlist3_fst_263, dlist2_fst_260 };
                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1112 { id_1111, dlist3_snd_264 };
                            letpair_res_1110 = id_1112;
                          }
                          Void id_1113 { ((void)(inits_src_ref_257[id_1107] = letpair_res_1110), ::dessser::Void()) };
                          (void)id_1113;
                        }
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_1114 { 0 };
                      uint8_t id_1115 { 0 };
                      int32_t id_1116 { repeat_n_258[id_1115] };
                      int32_t id_1117 { 1L };
                      int32_t id_1118 { int32_t(id_1116 + id_1117) };
                      Void id_1119 { ((void)(repeat_n_258[id_1114] = id_1118), ::dessser::Void()) };
                      (void)id_1119;
                      (void)id_1119;
                    }
                  } while (while_flag_1100);
                  (void)::dessser::Void();
                }
                (void)::dessser::Void();
                uint8_t id_1120 { 0 };
                ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1121 { inits_src_ref_257[id_1120] };
                let_res_1097 = id_1121;
              }
              letpair_res_1093 = let_res_1097;
            }
            let_res_1092 = letpair_res_1093;
          }
          ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 letpair_res_1122;
          {
            auto dlist4_fst_266 { std::get<0>(let_res_1092) };
            auto dlist4_snd_267 { std::get<1>(let_res_1092) };
            ::dessser::gen::raql_operation::external_format id_1123 { std::in_place_index<1>, dlist4_fst_266 };
            ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 id_1124 { id_1123, dlist4_snd_267 };
            letpair_res_1122 = id_1124;
          }
          choose_res_846 = letpair_res_1122;
        }
        letpair_res_843 = choose_res_846;
      }
      let_res_842 = letpair_res_843;
    }
    return let_res_842;
  }
   };
  return fun838;
}
std::function<::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4(Pointer &)> external_format_of_row_binary(external_format_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_132" (let-pair "du16_fst_127" "du16_snd_128" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_127") (identifier "du16_snd_128")))
        (let-pair "dsum1_fst_133" "dsum1_snd_134" (identifier "dsum1_132")
          (if (eq (u16 0) (identifier "dsum1_fst_133"))
            (let "drec_221" (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_134"))
              (let-pair "drec_fst_222" "drec_snd_223" (identifier "drec_221")
                (let "drec_227"
                  (if (eq (peek-u8 (identifier "drec_snd_223") (size 0)) (u8 1)) 
                    (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_223") (size 1)))
                    (let-pair "make1_1_fst_225" "make1_1_snd_226" (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_223") (size 1)))
                      (make-tup (not-null (identifier "make1_1_fst_225")) (identifier "make1_1_snd_226"))))
                  (let-pair "drec_fst_228" "drec_snd_229" (identifier "drec_227")
                    (let-pair "drec_fst_231" "drec_snd_232" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_229"))
                      (make-tup
                        (construct "[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" 0
                          (make-rec (string "unlink") (identifier "drec_fst_231") (string "preprocessor") (identifier "drec_fst_228") (string "fname") (identifier "drec_fst_222"))) 
                        (identifier "drec_snd_232")))))))
            (seq (assert (eq (identifier "dsum1_fst_133") (u16 1)))
              (let "drec_176"
                (let-pair "dlist4_fst_174" "dlist4_snd_175"
                  (let "dlist1_144"
                    (let "leb_ref_135" (make-vec (u32 0))
                      (let "shft_ref_136" (make-vec (u8 0))
                        (let "p_ref_137" (make-vec (identifier "dsum1_snd_134"))
                          (seq
                            (while
                              (let "leb128_138" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_137")))
                                (let-pair "leb128_fst_139" "leb128_snd_140" 
                                  (identifier "leb128_138")
                                  (seq (set-vec (u8 0) (identifier "p_ref_137") (identifier "leb128_snd_140"))
                                    (set-vec (u8 0) (identifier "leb_ref_135")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_139") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_136"))) (unsafe-nth (u8 0) (identifier "leb_ref_135"))))
                                    (set-vec (u8 0) (identifier "shft_ref_136") (add (unsafe-nth (u8 0) (identifier "shft_ref_136")) (u8 7))) 
                                    (ge (identifier "leb128_fst_139") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_135")) (unsafe-nth (u8 0) (identifier "p_ref_137")))))))
                    (let-pair "dlist1_fst_145" "dlist1_snd_146" (identifier "dlist1_144")
                      (let "inits_src_ref_147" (make-vec (make-tup (end-of-list "(STRING; $raql_expr)") (identifier "dlist1_snd_146")))
                        (seq
                          (let "repeat_n_148" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_145")) (unsafe-nth (u8 0) (identifier "repeat_n_148")))
                              (seq
                                (let "dlist2_149" (unsafe-nth (u8 0) (identifier "inits_src_ref_147"))
                                  (let-pair "dlist2_fst_150" "dlist2_snd_151" 
                                    (identifier "dlist2_149")
                                    (set-vec (u8 0) (identifier "inits_src_ref_147")
                                      (let "dtup_164"
                                        (let "dstring1_158"
                                          (let "leb_ref_152" (make-vec (u32 0))
                                            (let "shft_ref_153" (make-vec (u8 0))
                                              (let "p_ref_154" (make-vec (identifier "dlist2_snd_151"))
                                                (seq
                                                  (while
                                                    (let "leb128_155" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_154")))
                                                      (let-pair "leb128_fst_156" "leb128_snd_157" 
                                                        (identifier "leb128_155")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_154") (identifier "leb128_snd_157"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_152")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_156") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_153")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_152")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_153") (add (unsafe-nth (u8 0) (identifier "shft_ref_153")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_156") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_152"))) (unsafe-nth (u8 0) (identifier "p_ref_154")))))))
                                          (let-pair "dstring1_fst_159" "dstring1_snd_160" 
                                            (identifier "dstring1_158")
                                            (let-pair "dstring2_fst_162" "dstring2_snd_163" 
                                              (read-bytes (identifier "dstring1_snd_160") (identifier "dstring1_fst_159")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_162")) (identifier "dstring2_snd_163")))))
                                        (let-pair "dtup_fst_165" "dtup_snd_166" 
                                          (identifier "dtup_164")
                                          (let-pair "dtup_fst_168" "dtup_snd_169" 
                                            (apply (ext-identifier raql_expr of-row-binary) (identifier "dtup_snd_166"))
                                            (make-tup (cons (make-tup (identifier "dtup_fst_165") (identifier "dtup_fst_168")) (identifier "dlist2_fst_150")) (identifier "dtup_snd_169"))))))))
                                (set-vec (u8 0) (identifier "repeat_n_148") (add (unsafe-nth (u8 0) (identifier "repeat_n_148")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_147")))))) 
                  (make-tup (identity (identifier "dlist4_fst_174")) (identifier "dlist4_snd_175")))
                (let-pair "drec_fst_177" "drec_snd_178" (identifier "drec_176")
                  (let "drec_179" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_178"))
                    (let-pair "drec_fst_180" "drec_snd_181" (identifier "drec_179")
                      (let "drec_185"
                        (if (eq (peek-u8 (identifier "drec_snd_181") (size 0)) (u8 1)) 
                          (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_181") (size 1)))
                          (let-pair "make1_1_fst_183" "make1_1_snd_184" 
                            (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_181") (size 1))) 
                            (make-tup (not-null (identifier "make1_1_fst_183")) (identifier "make1_1_snd_184"))))
                        (let-pair "drec_fst_186" "drec_snd_187" (identifier "drec_185")
                          (let-pair "drec_fst_216" "drec_snd_217"
                            (let "dsum1_194" (let-pair "du16_fst_189" "du16_snd_190" (read-u16 little-endian (identifier "drec_snd_187")) (make-tup (identifier "du16_fst_189") (identifier "du16_snd_190")))
                              (let-pair "dsum1_fst_195" "dsum1_snd_196" 
                                (identifier "dsum1_194")
                                (if (eq (u16 0) (identifier "dsum1_fst_195"))
                                  (make-tup (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 0 (nop))
                                    (identifier "dsum1_snd_196"))
                                  (if (eq (u16 1) (identifier "dsum1_fst_195"))
                                    (let-pair "dsum2_fst_210" "dsum2_snd_211" 
                                      (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_196"))
                                      (make-tup
                                        (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 1
                                          (identifier "dsum2_fst_210")) 
                                        (identifier "dsum2_snd_211")))
                                    (if (eq (u16 2) (identifier "dsum1_fst_195"))
                                      (make-tup (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 2 (nop))
                                        (identifier "dsum1_snd_196"))
                                      (seq (assert (eq (identifier "dsum1_fst_195") (u16 3)))
                                        (let "drec_197" (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_196"))
                                          (let-pair "drec_fst_198" "drec_snd_199" 
                                            (identifier "drec_197")
                                            (let-pair "drec_fst_201" "drec_snd_202" 
                                              (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_199"))
                                              (make-tup
                                                (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 3
                                                  (make-rec (string "after_max_events") (identifier "drec_fst_201") (string "after_max_secs") (identifier "drec_fst_198"))) 
                                                (identifier "drec_snd_202")))))))))))
                            (make-tup
                              (construct "[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" 1
                                (make-rec (string "restart_from") (identifier "drec_fst_216") 
                                  (string "partitions") (identifier "drec_fst_186") 
                                  (string "topic") (identifier "drec_fst_180") 
                                  (string "options") (identifier "drec_fst_177"))) 
                              (identifier "drec_snd_217"))))))))))))))
 */
static std::function<::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69(Pointer &)> external_source_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69(Pointer &)> fun1125 { [&](Pointer p_0) {
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_1126 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1127;
    {
      auto du16_fst_127 { std::get<0>(id_1126) };
      auto du16_snd_128 { std::get<1>(id_1126) };
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_1128 { du16_fst_127, du16_snd_128 };
      letpair_res_1127 = id_1128;
    }
    ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 let_res_1129;
    {
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_132 { letpair_res_1127 };
      ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 letpair_res_1130;
      {
        auto dsum1_fst_133 { std::get<0>(dsum1_132) };
        auto dsum1_snd_134 { std::get<1>(dsum1_132) };
        uint16_t id_1131 { 0 };
        bool id_1132 { bool(id_1131 == dsum1_fst_133) };
        ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 choose_res_1133;
        if (id_1132) {
          auto fun1134 { dessser::gen::raql_expr::of_row_binary };
          ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1135 { fun1134(dsum1_snd_134) };
          ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 let_res_1136;
          {
            ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_221 { id_1135 };
            ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 letpair_res_1137;
            {
              auto drec_fst_222 { std::get<0>(drec_221) };
              auto drec_snd_223 { std::get<1>(drec_221) };
              Size id_1138 { 0UL };
              uint8_t id_1139 { drec_snd_223.peekU8(id_1138) };
              uint8_t id_1140 { 1 };
              bool id_1141 { bool(id_1139 == id_1140) };
              ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 choose_res_1142;
              if (id_1141) {
                std::optional<dessser::gen::raql_expr::t_ext> id_1143 { std::nullopt };
                Size id_1144 { 1UL };
                Pointer id_1145 { drec_snd_223.skip(id_1144) };
                ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_1146 { id_1143, id_1145 };
                choose_res_1142 = id_1146;
              } else {
                auto fun1147 { dessser::gen::raql_expr::of_row_binary };
                Size id_1148 { 1UL };
                Pointer id_1149 { drec_snd_223.skip(id_1148) };
                ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1150 { fun1147(id_1149) };
                ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 letpair_res_1151;
                {
                  auto make1_1_fst_225 { std::get<0>(id_1150) };
                  auto make1_1_snd_226 { std::get<1>(id_1150) };
                  std::optional<dessser::gen::raql_expr::t_ext> id_1152 { make1_1_fst_225 };
                  ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_1153 { id_1152, make1_1_snd_226 };
                  letpair_res_1151 = id_1153;
                }
                choose_res_1142 = letpair_res_1151;
              }
              ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 let_res_1154;
              {
                ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 drec_227 { choose_res_1142 };
                ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 letpair_res_1155;
                {
                  auto drec_fst_228 { std::get<0>(drec_227) };
                  auto drec_snd_229 { std::get<1>(drec_227) };
                  auto fun1156 { dessser::gen::raql_expr::of_row_binary };
                  ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1157 { fun1156(drec_snd_229) };
                  ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 letpair_res_1158;
                  {
                    auto drec_fst_231 { std::get<0>(id_1157) };
                    auto drec_snd_232 { std::get<1>(id_1157) };
                    ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_1159 { drec_fst_222, drec_fst_228, drec_fst_231 };
                    ::dessser::gen::raql_operation::external_source id_1160 { std::in_place_index<0>, id_1159 };
                    ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 id_1161 { id_1160, drec_snd_232 };
                    letpair_res_1158 = id_1161;
                  }
                  letpair_res_1155 = letpair_res_1158;
                }
                let_res_1154 = letpair_res_1155;
              }
              letpair_res_1137 = let_res_1154;
            }
            let_res_1136 = letpair_res_1137;
          }
          choose_res_1133 = let_res_1136;
        } else {
          uint16_t id_1162 { 1 };
          bool id_1163 { bool(dsum1_fst_133 == id_1162) };
          Void id_1164 { ((void)(assert(id_1163)), ::dessser::Void()) };
          (void)id_1164;
          uint32_t id_1165 { 0U };
          Vec<1, uint32_t> id_1166 {  id_1165  };
          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1167;
          {
            Vec<1, uint32_t> leb_ref_135 { id_1166 };
            uint8_t id_1168 { 0 };
            Vec<1, uint8_t> id_1169 {  id_1168  };
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1170;
            {
              Vec<1, uint8_t> shft_ref_136 { id_1169 };
              Vec<1, Pointer> id_1171 {  dsum1_snd_134  };
              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1172;
              {
                Vec<1, Pointer> p_ref_137 { id_1171 };
                bool while_flag_1173 { true };
                do {
                  uint8_t id_1174 { 0 };
                  Pointer id_1175 { p_ref_137[id_1174] };
                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1176 { id_1175.readU8() };
                  bool let_res_1177;
                  {
                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_138 { id_1176 };
                    bool letpair_res_1178;
                    {
                      auto leb128_fst_139 { std::get<0>(leb128_138) };
                      auto leb128_snd_140 { std::get<1>(leb128_138) };
                      uint8_t id_1179 { 0 };
                      Void id_1180 { ((void)(p_ref_137[id_1179] = leb128_snd_140), ::dessser::Void()) };
                      (void)id_1180;
                      uint8_t id_1181 { 0 };
                      uint8_t id_1182 { 127 };
                      uint8_t id_1183 { uint8_t(leb128_fst_139 & id_1182) };
                      uint32_t id_1184 { uint32_t(id_1183) };
                      uint8_t id_1185 { 0 };
                      uint8_t id_1186 { shft_ref_136[id_1185] };
                      uint32_t id_1187 { uint32_t(id_1184 << id_1186) };
                      uint8_t id_1188 { 0 };
                      uint32_t id_1189 { leb_ref_135[id_1188] };
                      uint32_t id_1190 { uint32_t(id_1187 | id_1189) };
                      Void id_1191 { ((void)(leb_ref_135[id_1181] = id_1190), ::dessser::Void()) };
                      (void)id_1191;
                      uint8_t id_1192 { 0 };
                      uint8_t id_1193 { 0 };
                      uint8_t id_1194 { shft_ref_136[id_1193] };
                      uint8_t id_1195 { 7 };
                      uint8_t id_1196 { uint8_t(id_1194 + id_1195) };
                      Void id_1197 { ((void)(shft_ref_136[id_1192] = id_1196), ::dessser::Void()) };
                      (void)id_1197;
                      uint8_t id_1198 { 128 };
                      bool id_1199 { bool(leb128_fst_139 >= id_1198) };
                      letpair_res_1178 = id_1199;
                    }
                    let_res_1177 = letpair_res_1178;
                  }
                  while_flag_1173 = let_res_1177;
                  if (while_flag_1173) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_1173);
                (void)::dessser::Void();
                uint8_t id_1200 { 0 };
                uint32_t id_1201 { leb_ref_135[id_1200] };
                uint8_t id_1202 { 0 };
                Pointer id_1203 { p_ref_137[id_1202] };
                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_1204 { id_1201, id_1203 };
                let_res_1172 = id_1204;
              }
              let_res_1170 = let_res_1172;
            }
            let_res_1167 = let_res_1170;
          }
          ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c let_res_1205;
          {
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_144 { let_res_1167 };
            ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c letpair_res_1206;
            {
              auto dlist1_fst_145 { std::get<0>(dlist1_144) };
              auto dlist1_snd_146 { std::get<1>(dlist1_144) };
              Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> endoflist_1207;
              ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c id_1208 { endoflist_1207, dlist1_snd_146 };
              Vec<1, ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c> id_1209 {  id_1208  };
              ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c let_res_1210;
              {
                Vec<1, ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c> inits_src_ref_147 { id_1209 };
                int32_t id_1211 { 0L };
                Vec<1, int32_t> id_1212 {  id_1211  };
                {
                  Vec<1, int32_t> repeat_n_148 { id_1212 };
                  bool while_flag_1213 { true };
                  do {
                    int32_t id_1214 { int32_t(dlist1_fst_145) };
                    uint8_t id_1215 { 0 };
                    int32_t id_1216 { repeat_n_148[id_1215] };
                    bool id_1217 { bool(id_1214 > id_1216) };
                    while_flag_1213 = id_1217;
                    if (while_flag_1213) {
                      uint8_t id_1218 { 0 };
                      ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c id_1219 { inits_src_ref_147[id_1218] };
                      {
                        ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c dlist2_149 { id_1219 };
                        {
                          auto dlist2_fst_150 { std::get<0>(dlist2_149) };
                          auto dlist2_snd_151 { std::get<1>(dlist2_149) };
                          uint8_t id_1220 { 0 };
                          uint32_t id_1221 { 0U };
                          Vec<1, uint32_t> id_1222 {  id_1221  };
                          ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_1223;
                          {
                            Vec<1, uint32_t> leb_ref_152 { id_1222 };
                            uint8_t id_1224 { 0 };
                            Vec<1, uint8_t> id_1225 {  id_1224  };
                            ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_1226;
                            {
                              Vec<1, uint8_t> shft_ref_153 { id_1225 };
                              Vec<1, Pointer> id_1227 {  dlist2_snd_151  };
                              ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_1228;
                              {
                                Vec<1, Pointer> p_ref_154 { id_1227 };
                                bool while_flag_1229 { true };
                                do {
                                  uint8_t id_1230 { 0 };
                                  Pointer id_1231 { p_ref_154[id_1230] };
                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1232 { id_1231.readU8() };
                                  bool let_res_1233;
                                  {
                                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_155 { id_1232 };
                                    bool letpair_res_1234;
                                    {
                                      auto leb128_fst_156 { std::get<0>(leb128_155) };
                                      auto leb128_snd_157 { std::get<1>(leb128_155) };
                                      uint8_t id_1235 { 0 };
                                      Void id_1236 { ((void)(p_ref_154[id_1235] = leb128_snd_157), ::dessser::Void()) };
                                      (void)id_1236;
                                      uint8_t id_1237 { 0 };
                                      uint8_t id_1238 { 127 };
                                      uint8_t id_1239 { uint8_t(leb128_fst_156 & id_1238) };
                                      uint32_t id_1240 { uint32_t(id_1239) };
                                      uint8_t id_1241 { 0 };
                                      uint8_t id_1242 { shft_ref_153[id_1241] };
                                      uint32_t id_1243 { uint32_t(id_1240 << id_1242) };
                                      uint8_t id_1244 { 0 };
                                      uint32_t id_1245 { leb_ref_152[id_1244] };
                                      uint32_t id_1246 { uint32_t(id_1243 | id_1245) };
                                      Void id_1247 { ((void)(leb_ref_152[id_1237] = id_1246), ::dessser::Void()) };
                                      (void)id_1247;
                                      uint8_t id_1248 { 0 };
                                      uint8_t id_1249 { 0 };
                                      uint8_t id_1250 { shft_ref_153[id_1249] };
                                      uint8_t id_1251 { 7 };
                                      uint8_t id_1252 { uint8_t(id_1250 + id_1251) };
                                      Void id_1253 { ((void)(shft_ref_153[id_1248] = id_1252), ::dessser::Void()) };
                                      (void)id_1253;
                                      uint8_t id_1254 { 128 };
                                      bool id_1255 { bool(leb128_fst_156 >= id_1254) };
                                      letpair_res_1234 = id_1255;
                                    }
                                    let_res_1233 = letpair_res_1234;
                                  }
                                  while_flag_1229 = let_res_1233;
                                  if (while_flag_1229) {
                                    (void)::dessser::Void();
                                  }
                                } while (while_flag_1229);
                                (void)::dessser::Void();
                                uint8_t id_1256 { 0 };
                                uint32_t id_1257 { leb_ref_152[id_1256] };
                                Size id_1258 { Size(id_1257) };
                                uint8_t id_1259 { 0 };
                                Pointer id_1260 { p_ref_154[id_1259] };
                                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_1261 { id_1258, id_1260 };
                                let_res_1228 = id_1261;
                              }
                              let_res_1226 = let_res_1228;
                            }
                            let_res_1223 = let_res_1226;
                          }
                          ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 let_res_1262;
                          {
                            ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_158 { let_res_1223 };
                            ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_1263;
                            {
                              auto dstring1_fst_159 { std::get<0>(dstring1_158) };
                              auto dstring1_snd_160 { std::get<1>(dstring1_158) };
                              ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_1264 { dstring1_snd_160.readBytes(dstring1_fst_159) };
                              ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_1265;
                              {
                                auto dstring2_fst_162 { std::get<0>(id_1264) };
                                auto dstring2_snd_163 { std::get<1>(id_1264) };
                                std::string id_1266 { dstring2_fst_162.toString() };
                                ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 id_1267 { id_1266, dstring2_snd_163 };
                                letpair_res_1265 = id_1267;
                              }
                              letpair_res_1263 = letpair_res_1265;
                            }
                            let_res_1262 = letpair_res_1263;
                          }
                          ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c let_res_1268;
                          {
                            ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 dtup_164 { let_res_1262 };
                            ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c letpair_res_1269;
                            {
                              auto dtup_fst_165 { std::get<0>(dtup_164) };
                              auto dtup_snd_166 { std::get<1>(dtup_164) };
                              auto fun1270 { dessser::gen::raql_expr::of_row_binary };
                              ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1271 { fun1270(dtup_snd_166) };
                              ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c letpair_res_1272;
                              {
                                auto dtup_fst_168 { std::get<0>(id_1271) };
                                auto dtup_snd_169 { std::get<1>(id_1271) };
                                ::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a id_1273 { dtup_fst_165, dtup_fst_168 };
                                Lst<::dessser::gen::raql_operation::t42c3ffb6cb514e3c128f0c7344ce492a> id_1274 { id_1273, dlist2_fst_150 };
                                ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c id_1275 { id_1274, dtup_snd_169 };
                                letpair_res_1272 = id_1275;
                              }
                              letpair_res_1269 = letpair_res_1272;
                            }
                            let_res_1268 = letpair_res_1269;
                          }
                          Void id_1276 { ((void)(inits_src_ref_147[id_1220] = let_res_1268), ::dessser::Void()) };
                          (void)id_1276;
                        }
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_1277 { 0 };
                      uint8_t id_1278 { 0 };
                      int32_t id_1279 { repeat_n_148[id_1278] };
                      int32_t id_1280 { 1L };
                      int32_t id_1281 { int32_t(id_1279 + id_1280) };
                      Void id_1282 { ((void)(repeat_n_148[id_1277] = id_1281), ::dessser::Void()) };
                      (void)id_1282;
                      (void)id_1282;
                    }
                  } while (while_flag_1213);
                  (void)::dessser::Void();
                }
                (void)::dessser::Void();
                uint8_t id_1283 { 0 };
                ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c id_1284 { inits_src_ref_147[id_1283] };
                let_res_1210 = id_1284;
              }
              letpair_res_1206 = let_res_1210;
            }
            let_res_1205 = letpair_res_1206;
          }
          ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c letpair_res_1285;
          {
            auto dlist4_fst_174 { std::get<0>(let_res_1205) };
            auto dlist4_snd_175 { std::get<1>(let_res_1205) };
            ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c id_1286 { dlist4_fst_174, dlist4_snd_175 };
            letpair_res_1285 = id_1286;
          }
          ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 let_res_1287;
          {
            ::dessser::gen::raql_operation::tf13fbb09f51834e815a6b7b178fd9c4c drec_176 { letpair_res_1285 };
            ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 letpair_res_1288;
            {
              auto drec_fst_177 { std::get<0>(drec_176) };
              auto drec_snd_178 { std::get<1>(drec_176) };
              auto fun1289 { dessser::gen::raql_expr::of_row_binary };
              ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1290 { fun1289(drec_snd_178) };
              ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 let_res_1291;
              {
                ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_179 { id_1290 };
                ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 letpair_res_1292;
                {
                  auto drec_fst_180 { std::get<0>(drec_179) };
                  auto drec_snd_181 { std::get<1>(drec_179) };
                  Size id_1293 { 0UL };
                  uint8_t id_1294 { drec_snd_181.peekU8(id_1293) };
                  uint8_t id_1295 { 1 };
                  bool id_1296 { bool(id_1294 == id_1295) };
                  ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 choose_res_1297;
                  if (id_1296) {
                    std::optional<dessser::gen::raql_expr::t_ext> id_1298 { std::nullopt };
                    Size id_1299 { 1UL };
                    Pointer id_1300 { drec_snd_181.skip(id_1299) };
                    ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_1301 { id_1298, id_1300 };
                    choose_res_1297 = id_1301;
                  } else {
                    auto fun1302 { dessser::gen::raql_expr::of_row_binary };
                    Size id_1303 { 1UL };
                    Pointer id_1304 { drec_snd_181.skip(id_1303) };
                    ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1305 { fun1302(id_1304) };
                    ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 letpair_res_1306;
                    {
                      auto make1_1_fst_183 { std::get<0>(id_1305) };
                      auto make1_1_snd_184 { std::get<1>(id_1305) };
                      std::optional<dessser::gen::raql_expr::t_ext> id_1307 { make1_1_fst_183 };
                      ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_1308 { id_1307, make1_1_snd_184 };
                      letpair_res_1306 = id_1308;
                    }
                    choose_res_1297 = letpair_res_1306;
                  }
                  ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 let_res_1309;
                  {
                    ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 drec_185 { choose_res_1297 };
                    ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 letpair_res_1310;
                    {
                      auto drec_fst_186 { std::get<0>(drec_185) };
                      auto drec_snd_187 { std::get<1>(drec_185) };
                      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_1311 { drec_snd_187.readU16Le() };
                      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1312;
                      {
                        auto du16_fst_189 { std::get<0>(id_1311) };
                        auto du16_snd_190 { std::get<1>(id_1311) };
                        ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_1313 { du16_fst_189, du16_snd_190 };
                        letpair_res_1312 = id_1313;
                      }
                      ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de let_res_1314;
                      {
                        ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_194 { letpair_res_1312 };
                        ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de letpair_res_1315;
                        {
                          auto dsum1_fst_195 { std::get<0>(dsum1_194) };
                          auto dsum1_snd_196 { std::get<1>(dsum1_194) };
                          uint16_t id_1316 { 0 };
                          bool id_1317 { bool(id_1316 == dsum1_fst_195) };
                          ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de choose_res_1318;
                          if (id_1317) {
                            (void)::dessser::Void();
                            ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_1319 { std::in_place_index<0>, ::dessser::Void() };
                            ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de id_1320 { id_1319, dsum1_snd_196 };
                            choose_res_1318 = id_1320;
                          } else {
                            uint16_t id_1321 { 1 };
                            bool id_1322 { bool(id_1321 == dsum1_fst_195) };
                            ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de choose_res_1323;
                            if (id_1322) {
                              auto fun1324 { dessser::gen::raql_expr::of_row_binary };
                              ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1325 { fun1324(dsum1_snd_196) };
                              ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de letpair_res_1326;
                              {
                                auto dsum2_fst_210 { std::get<0>(id_1325) };
                                auto dsum2_snd_211 { std::get<1>(id_1325) };
                                ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_1327 { std::in_place_index<1>, dsum2_fst_210 };
                                ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de id_1328 { id_1327, dsum2_snd_211 };
                                letpair_res_1326 = id_1328;
                              }
                              choose_res_1323 = letpair_res_1326;
                            } else {
                              uint16_t id_1329 { 2 };
                              bool id_1330 { bool(id_1329 == dsum1_fst_195) };
                              ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de choose_res_1331;
                              if (id_1330) {
                                (void)::dessser::Void();
                                ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_1332 { std::in_place_index<2>, ::dessser::Void() };
                                ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de id_1333 { id_1332, dsum1_snd_196 };
                                choose_res_1331 = id_1333;
                              } else {
                                uint16_t id_1334 { 3 };
                                bool id_1335 { bool(dsum1_fst_195 == id_1334) };
                                Void id_1336 { ((void)(assert(id_1335)), ::dessser::Void()) };
                                (void)id_1336;
                                auto fun1337 { dessser::gen::raql_expr::of_row_binary };
                                ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1338 { fun1337(dsum1_snd_196) };
                                ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de let_res_1339;
                                {
                                  ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_197 { id_1338 };
                                  ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de letpair_res_1340;
                                  {
                                    auto drec_fst_198 { std::get<0>(drec_197) };
                                    auto drec_snd_199 { std::get<1>(drec_197) };
                                    auto fun1341 { dessser::gen::raql_expr::of_row_binary };
                                    ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1342 { fun1341(drec_snd_199) };
                                    ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de letpair_res_1343;
                                    {
                                      auto drec_fst_201 { std::get<0>(id_1342) };
                                      auto drec_snd_202 { std::get<1>(id_1342) };
                                      ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_1344 { drec_fst_198, drec_fst_201 };
                                      ::dessser::gen::raql_operation::tbbc319188017fc622f05dfada38341dc id_1345 { std::in_place_index<3>, id_1344 };
                                      ::dessser::gen::raql_operation::t63851e9ebc3cda254eb20d83ee5492de id_1346 { id_1345, drec_snd_202 };
                                      letpair_res_1343 = id_1346;
                                    }
                                    letpair_res_1340 = letpair_res_1343;
                                  }
                                  let_res_1339 = letpair_res_1340;
                                }
                                choose_res_1331 = let_res_1339;
                              }
                              choose_res_1323 = choose_res_1331;
                            }
                            choose_res_1318 = choose_res_1323;
                          }
                          letpair_res_1315 = choose_res_1318;
                        }
                        let_res_1314 = letpair_res_1315;
                      }
                      ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 letpair_res_1347;
                      {
                        auto drec_fst_216 { std::get<0>(let_res_1314) };
                        auto drec_snd_217 { std::get<1>(let_res_1314) };
                        ::dessser::gen::raql_operation::ta64ee09b20632228f3a50181be1b6548 id_1348 { drec_fst_177, drec_fst_180, drec_fst_186, drec_fst_216 };
                        ::dessser::gen::raql_operation::external_source id_1349 { std::in_place_index<1>, id_1348 };
                        ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 id_1350 { id_1349, drec_snd_217 };
                        letpair_res_1347 = id_1350;
                      }
                      letpair_res_1310 = letpair_res_1347;
                    }
                    let_res_1309 = letpair_res_1310;
                  }
                  letpair_res_1292 = let_res_1309;
                }
                let_res_1291 = letpair_res_1292;
              }
              letpair_res_1288 = let_res_1291;
            }
            let_res_1287 = letpair_res_1288;
          }
          choose_res_1133 = let_res_1287;
        }
        letpair_res_1130 = choose_res_1133;
      }
      let_res_1129 = letpair_res_1130;
    }
    return let_res_1129;
  }
   };
  return fun1125;
}
std::function<::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69(Pointer &)> external_source_of_row_binary(external_source_of_row_binary_init());

/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; ip_proto: $raql_ip_protocol; proto: $raql_net_protocol; factors: $field_name[[]]}]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t>  &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t>  &,Pointer &)> fun1351 { [&](std::shared_ptr<::dessser::gen::raql_operation::t>  p_0, Pointer p_1) {
    Pointer id_1352 { to_row_binary(p_0, p_1) };
    return id_1352;
  }
   };
  return fun1351;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t>  &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());

/* 
    (fun ("[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" "Ptr")
      (let "ssum_dst_815" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "stup_dst_823"
            (let "stup_dst_820"
              (let "ssum_dst_817" (write-u16 little-endian (identifier "ssum_dst_815") (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))))
                (if (eq (u16 0) (label-of (get-item 0 (get-alt "NamedOperation" (param 0))))) 
                  (identifier "ssum_dst_817")
                  (if (eq (u16 1) (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))))
                    (write-bytes
                      (let "leb128_sz_818" (make-vec (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0))))))
                        (let "leb128_ptr_819" (make-vec (identifier "ssum_dst_817"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_819")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_819"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_818"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_818"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_818"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_818") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_818")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_818")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_819"))))) 
                      (bytes-of-string (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0))))))
                    (seq (assert (eq (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))) (u16 2))) (identifier "ssum_dst_817")))))
              (if (is-null (get-item 1 (get-alt "NamedOperation" (param 0)))) 
                (write-u8 (identifier "stup_dst_820") (u8 1))
                (write-bytes
                  (let "leb128_sz_821" (make-vec (string-length (force (get-item 1 (get-alt "NamedOperation" (param 0))))))
                    (let "leb128_ptr_822" (make-vec (write-u8 (identifier "stup_dst_820") (u8 0)))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_822")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_822"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_821"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_821"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_821"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_821") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_821")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_821")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_822"))))) 
                  (bytes-of-string (force (get-item 1 (get-alt "NamedOperation" (param 0)))))))) 
            (apply (ext-identifier function_name to-row-binary) (get-item 2 (get-alt "NamedOperation" (param 0))) (identifier "stup_dst_823")))
          (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "to-row-binary") (get-alt "SubQuery" (param 0)) (identifier "ssum_dst_815"))))))
 */
static std::function<Pointer(::dessser::gen::raql_operation::data_source &,Pointer &)> data_source_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_operation::data_source &,Pointer &)> fun1353 { [&](::dessser::gen::raql_operation::data_source p_0, Pointer p_1) {
    uint16_t id_1354 { uint16_t(p_0.index()) };
    Pointer id_1355 { p_1.writeU16Le(id_1354) };
    Pointer let_res_1356;
    {
      Pointer ssum_dst_815 { id_1355 };
      uint16_t id_1357 { 0 };
      uint16_t id_1358 { uint16_t(p_0.index()) };
      bool id_1359 { bool(id_1357 == id_1358) };
      Pointer choose_res_1360;
      if (id_1359) {
        ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1361 { std::get<0 /* NamedOperation */>(p_0) };
        ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_1362 { std::get<0>(id_1361) };
        uint16_t id_1363 { uint16_t(id_1362.index()) };
        Pointer id_1364 { ssum_dst_815.writeU16Le(id_1363) };
        Pointer let_res_1365;
        {
          Pointer ssum_dst_817 { id_1364 };
          uint16_t id_1366 { 0 };
          ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1367 { std::get<0 /* NamedOperation */>(p_0) };
          ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_1368 { std::get<0>(id_1367) };
          uint16_t id_1369 { uint16_t(id_1368.index()) };
          bool id_1370 { bool(id_1366 == id_1369) };
          Pointer choose_res_1371;
          if (id_1370) {
            choose_res_1371 = ssum_dst_817;
          } else {
            uint16_t id_1372 { 1 };
            ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1373 { std::get<0 /* NamedOperation */>(p_0) };
            ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_1374 { std::get<0>(id_1373) };
            uint16_t id_1375 { uint16_t(id_1374.index()) };
            bool id_1376 { bool(id_1372 == id_1375) };
            Pointer choose_res_1377;
            if (id_1376) {
              ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1378 { std::get<0 /* NamedOperation */>(p_0) };
              ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_1379 { std::get<0>(id_1378) };
              std::string id_1380 { std::get<1 /* TheseSites */>(id_1379) };
              uint32_t id_1381 { (uint32_t)id_1380.size() };
              Vec<1, uint32_t> id_1382 {  id_1381  };
              Pointer let_res_1383;
              {
                Vec<1, uint32_t> leb128_sz_818 { id_1382 };
                Vec<1, Pointer> id_1384 {  ssum_dst_817  };
                Pointer let_res_1385;
                {
                  Vec<1, Pointer> leb128_ptr_819 { id_1384 };
                  bool while_flag_1386 { true };
                  do {
                    uint8_t id_1387 { 0 };
                    uint8_t id_1388 { 0 };
                    Pointer id_1389 { leb128_ptr_819[id_1388] };
                    uint32_t id_1390 { 128U };
                    uint8_t id_1391 { 0 };
                    uint32_t id_1392 { leb128_sz_818[id_1391] };
                    bool id_1393 { bool(id_1390 > id_1392) };
                    uint8_t choose_res_1394;
                    if (id_1393) {
                      uint8_t id_1395 { 0 };
                      uint32_t id_1396 { leb128_sz_818[id_1395] };
                      uint8_t id_1397 { uint8_t(id_1396) };
                      choose_res_1394 = id_1397;
                    } else {
                      uint8_t id_1398 { 0 };
                      uint32_t id_1399 { leb128_sz_818[id_1398] };
                      uint8_t id_1400 { uint8_t(id_1399) };
                      uint8_t id_1401 { 128 };
                      uint8_t id_1402 { uint8_t(id_1400 | id_1401) };
                      choose_res_1394 = id_1402;
                    }
                    Pointer id_1403 { id_1389.writeU8(choose_res_1394) };
                    Void id_1404 { ((void)(leb128_ptr_819[id_1387] = id_1403), ::dessser::Void()) };
                    (void)id_1404;
                    uint8_t id_1405 { 0 };
                    uint8_t id_1406 { 0 };
                    uint32_t id_1407 { leb128_sz_818[id_1406] };
                    uint8_t id_1408 { 7 };
                    uint32_t id_1409 { uint32_t(id_1407 >> id_1408) };
                    Void id_1410 { ((void)(leb128_sz_818[id_1405] = id_1409), ::dessser::Void()) };
                    (void)id_1410;
                    uint8_t id_1411 { 0 };
                    uint32_t id_1412 { leb128_sz_818[id_1411] };
                    uint32_t id_1413 { 0U };
                    bool id_1414 { bool(id_1412 > id_1413) };
                    while_flag_1386 = id_1414;
                    if (while_flag_1386) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_1386);
                  (void)::dessser::Void();
                  uint8_t id_1415 { 0 };
                  Pointer id_1416 { leb128_ptr_819[id_1415] };
                  let_res_1385 = id_1416;
                }
                let_res_1383 = let_res_1385;
              }
              ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1417 { std::get<0 /* NamedOperation */>(p_0) };
              ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_1418 { std::get<0>(id_1417) };
              std::string id_1419 { std::get<1 /* TheseSites */>(id_1418) };
              Bytes id_1420 { id_1419 };
              Pointer id_1421 { let_res_1383.writeBytes(id_1420) };
              choose_res_1377 = id_1421;
            } else {
              ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1422 { std::get<0 /* NamedOperation */>(p_0) };
              ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_1423 { std::get<0>(id_1422) };
              uint16_t id_1424 { uint16_t(id_1423.index()) };
              uint16_t id_1425 { 2 };
              bool id_1426 { bool(id_1424 == id_1425) };
              Void id_1427 { ((void)(assert(id_1426)), ::dessser::Void()) };
              (void)id_1427;
              choose_res_1377 = ssum_dst_817;
            }
            choose_res_1371 = choose_res_1377;
          }
          let_res_1365 = choose_res_1371;
        }
        Pointer let_res_1428;
        {
          Pointer stup_dst_820 { let_res_1365 };
          ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1429 { std::get<0 /* NamedOperation */>(p_0) };
          std::optional<std::string> id_1430 { std::get<1>(id_1429) };
          bool id_1431 { !(id_1430.has_value ()) };
          Pointer choose_res_1432;
          if (id_1431) {
            uint8_t id_1433 { 1 };
            Pointer id_1434 { stup_dst_820.writeU8(id_1433) };
            choose_res_1432 = id_1434;
          } else {
            ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1435 { std::get<0 /* NamedOperation */>(p_0) };
            std::optional<std::string> id_1436 { std::get<1>(id_1435) };
            std::string id_1437 { id_1436.value() };
            uint32_t id_1438 { (uint32_t)id_1437.size() };
            Vec<1, uint32_t> id_1439 {  id_1438  };
            Pointer let_res_1440;
            {
              Vec<1, uint32_t> leb128_sz_821 { id_1439 };
              uint8_t id_1441 { 0 };
              Pointer id_1442 { stup_dst_820.writeU8(id_1441) };
              Vec<1, Pointer> id_1443 {  id_1442  };
              Pointer let_res_1444;
              {
                Vec<1, Pointer> leb128_ptr_822 { id_1443 };
                bool while_flag_1445 { true };
                do {
                  uint8_t id_1446 { 0 };
                  uint8_t id_1447 { 0 };
                  Pointer id_1448 { leb128_ptr_822[id_1447] };
                  uint32_t id_1449 { 128U };
                  uint8_t id_1450 { 0 };
                  uint32_t id_1451 { leb128_sz_821[id_1450] };
                  bool id_1452 { bool(id_1449 > id_1451) };
                  uint8_t choose_res_1453;
                  if (id_1452) {
                    uint8_t id_1454 { 0 };
                    uint32_t id_1455 { leb128_sz_821[id_1454] };
                    uint8_t id_1456 { uint8_t(id_1455) };
                    choose_res_1453 = id_1456;
                  } else {
                    uint8_t id_1457 { 0 };
                    uint32_t id_1458 { leb128_sz_821[id_1457] };
                    uint8_t id_1459 { uint8_t(id_1458) };
                    uint8_t id_1460 { 128 };
                    uint8_t id_1461 { uint8_t(id_1459 | id_1460) };
                    choose_res_1453 = id_1461;
                  }
                  Pointer id_1462 { id_1448.writeU8(choose_res_1453) };
                  Void id_1463 { ((void)(leb128_ptr_822[id_1446] = id_1462), ::dessser::Void()) };
                  (void)id_1463;
                  uint8_t id_1464 { 0 };
                  uint8_t id_1465 { 0 };
                  uint32_t id_1466 { leb128_sz_821[id_1465] };
                  uint8_t id_1467 { 7 };
                  uint32_t id_1468 { uint32_t(id_1466 >> id_1467) };
                  Void id_1469 { ((void)(leb128_sz_821[id_1464] = id_1468), ::dessser::Void()) };
                  (void)id_1469;
                  uint8_t id_1470 { 0 };
                  uint32_t id_1471 { leb128_sz_821[id_1470] };
                  uint32_t id_1472 { 0U };
                  bool id_1473 { bool(id_1471 > id_1472) };
                  while_flag_1445 = id_1473;
                  if (while_flag_1445) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_1445);
                (void)::dessser::Void();
                uint8_t id_1474 { 0 };
                Pointer id_1475 { leb128_ptr_822[id_1474] };
                let_res_1444 = id_1475;
              }
              let_res_1440 = let_res_1444;
            }
            ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1476 { std::get<0 /* NamedOperation */>(p_0) };
            std::optional<std::string> id_1477 { std::get<1>(id_1476) };
            std::string id_1478 { id_1477.value() };
            Bytes id_1479 { id_1478 };
            Pointer id_1480 { let_res_1440.writeBytes(id_1479) };
            choose_res_1432 = id_1480;
          }
          let_res_1428 = choose_res_1432;
        }
        Pointer let_res_1481;
        {
          Pointer stup_dst_823 { let_res_1428 };
          auto fun1482 { dessser::gen::function_name::to_row_binary };
          ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_1483 { std::get<0 /* NamedOperation */>(p_0) };
          dessser::gen::function_name::t_ext id_1484 { std::get<2>(id_1483) };
          Pointer id_1485 { fun1482(id_1484, stup_dst_823) };
          let_res_1481 = id_1485;
        }
        choose_res_1360 = let_res_1481;
      } else {
        uint16_t id_1486 { uint16_t(p_0.index()) };
        uint16_t id_1487 { 1 };
        bool id_1488 { bool(id_1486 == id_1487) };
        Void id_1489 { ((void)(assert(id_1488)), ::dessser::Void()) };
        (void)id_1489;
        std::shared_ptr<::dessser::gen::raql_operation::t>  id_1490 { std::get<1 /* SubQuery */>(p_0) };
        Pointer id_1491 { to_row_binary(id_1490, ssum_dst_815) };
        choose_res_1360 = id_1491;
      }
      let_res_1356 = choose_res_1360;
    }
    return let_res_1356;
  }
   };
  return fun1353;
}
std::function<Pointer(::dessser::gen::raql_operation::data_source &,Pointer &)> data_source_to_row_binary(data_source_to_row_binary_init());

/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; ip_proto: $raql_ip_protocol; proto: $raql_net_protocol; factors: $field_name[[]]}]" "Ptr")
      (let "ssum_dst_866" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_930"
            (let "srec_dst_929"
              (let "srec_dst_923"
                (let "srec_dst_922"
                  (let "srec_dst_921"
                    (let "srec_dst_920"
                      (let "srec_dst_914"
                        (let "srec_dst_908"
                          (let "srec_dst_907"
                            (let "srec_dst_906"
                              (let "srec_dst_897"
                                (let "srec_dst_891"
                                  (let "dst_ref_888"
                                    (make-vec
                                      (let "leb128_sz_886" (make-vec (cardinality (get-field "fields" (get-alt "Aggregate" (param 0)))))
                                        (let "leb128_ptr_887" (make-vec (identifier "ssum_dst_866"))
                                          (seq
                                            (while
                                              (seq
                                                (set-vec (u8 0) (identifier "leb128_ptr_887")
                                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_887"))
                                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_886"))) 
                                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_886"))) 
                                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_886"))) (u8 128)))))
                                                (set-vec (u8 0) (identifier "leb128_sz_886") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_886")) (u8 7))) 
                                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_886")) (u32 0))) 
                                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_887"))))))
                                    (let "n_ref_889" (make-vec (i32 0))
                                      (seq
                                        (for-each "x_890" (get-field "fields" (get-alt "Aggregate" (param 0)))
                                          (seq (set-vec (u8 0) (identifier "dst_ref_888") (apply (ext-identifier raql_select_field to-row-binary) (identifier "x_890") (unsafe-nth (u8 0) (identifier "dst_ref_888"))))
                                            (set-vec (u8 0) (identifier "n_ref_889") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_889")))))) 
                                        (unsafe-nth (u8 0) (identifier "dst_ref_888")))))
                                  (if (is-null (get-field "and_all_others" (get-alt "Aggregate" (param 0)))) 
                                    (write-u8 (identifier "srec_dst_891") (u8 1))
                                    (let "dst_ref_894"
                                      (make-vec
                                        (let "leb128_sz_892" (make-vec (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))
                                          (let "leb128_ptr_893" (make-vec (write-u8 (identifier "srec_dst_891") (u8 0)))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_893")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_893"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_892"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_892"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_892"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_892") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_892")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_892")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_893"))))))
                                      (let "n_ref_895" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_896" (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_894") (apply (ext-identifier field_name to-row-binary) (identifier "x_896") (unsafe-nth (u8 0) (identifier "dst_ref_894"))))
                                              (set-vec (u8 0) (identifier "n_ref_895") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_895")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_894")))))))
                                (if (is-null (get-field "sort" (get-alt "Aggregate" (param 0)))) 
                                  (write-u8 (identifier "srec_dst_897") (u8 1))
                                  (let "stup_dst_900"
                                    (let "stup_dst_899"
                                      (let "stup_dst_898" (write-u8 (identifier "srec_dst_897") (u8 0))
                                        (write-u32 little-endian (identifier "stup_dst_898") (get-item 0 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                      (if (is-null (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) 
                                        (write-u8 (identifier "stup_dst_899") (u8 1))
                                        (apply (ext-identifier raql_expr to-row-binary) (force (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) (write-u8 (identifier "stup_dst_899") (u8 0)))))
                                    (let "dst_ref_903"
                                      (make-vec
                                        (let "leb128_sz_901" (make-vec (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                          (let "leb128_ptr_902" (make-vec (identifier "stup_dst_900"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_902")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_902"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_901"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_901"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_901"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_901") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_901")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_901")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_902"))))))
                                      (let "n_ref_904" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_905" (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_903") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_905") (unsafe-nth (u8 0) (identifier "dst_ref_903"))))
                                              (set-vec (u8 0) (identifier "n_ref_904") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_904")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_903")))))))) 
                              (apply (ext-identifier raql_expr to-row-binary) (get-field "where" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_906")))
                            (if (is-null (get-field "event_time" (get-alt "Aggregate" (param 0)))) 
                              (write-u8 (identifier "srec_dst_907") (u8 1))
                              (apply (ext-identifier event_time to-row-binary) (force (get-field "event_time" (get-alt "Aggregate" (param 0)))) (write-u8 (identifier "srec_dst_907") (u8 0)))))
                          (let "dst_ref_911"
                            (make-vec
                              (let "leb128_sz_909" (make-vec (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0)))))
                                (let "leb128_ptr_910" (make-vec (identifier "srec_dst_908"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_910")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_910"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_909"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_909"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_909"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_909") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_909")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_909")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_910"))))))
                            (let "n_ref_912" (make-vec (i32 0))
                              (seq
                                (for-each "x_913" (get-field "notifications" (get-alt "Aggregate" (param 0)))
                                  (seq (set-vec (u8 0) (identifier "dst_ref_911") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_913") (unsafe-nth (u8 0) (identifier "dst_ref_911"))))
                                    (set-vec (u8 0) (identifier "n_ref_912") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_912")))))) 
                                (unsafe-nth (u8 0) (identifier "dst_ref_911"))))))
                        (let "dst_ref_917"
                          (make-vec
                            (let "leb128_sz_915" (make-vec (cardinality (get-field "key" (get-alt "Aggregate" (param 0)))))
                              (let "leb128_ptr_916" (make-vec (identifier "srec_dst_914"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_916")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_916"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_915"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_915"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_915"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_915") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_915")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_915")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_916"))))))
                          (let "n_ref_918" (make-vec (i32 0))
                            (seq
                              (for-each "x_919" (get-field "key" (get-alt "Aggregate" (param 0)))
                                (seq (set-vec (u8 0) (identifier "dst_ref_917") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_919") (unsafe-nth (u8 0) (identifier "dst_ref_917"))))
                                  (set-vec (u8 0) (identifier "n_ref_918") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_918")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_917")))))) 
                      (apply (ext-identifier raql_expr to-row-binary) (get-field "commit_cond" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_920")))
                    (write-u8 (identifier "srec_dst_921") (u8-of-bool (get-field "commit_before" (get-alt "Aggregate" (param 0))))))
                  (apply (ext-identifier raql_flush_method to-row-binary) (get-field "flush_how" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_922")))
                (let "dst_ref_926"
                  (make-vec
                    (let "leb128_sz_924" (make-vec (cardinality (get-field "from" (get-alt "Aggregate" (param 0)))))
                      (let "leb128_ptr_925" (make-vec (identifier "srec_dst_923"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_925")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_925"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_924"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_924"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_924"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_924") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_924")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_924")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_925"))))))
                  (let "n_ref_927" (make-vec (i32 0))
                    (seq
                      (for-each "x_928" (get-field "from" (get-alt "Aggregate" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_926") (apply (identifier "data_source-to-row-binary") (identifier "x_928") (unsafe-nth (u8 0) (identifier "dst_ref_926"))))
                          (set-vec (u8 0) (identifier "n_ref_927") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_927")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_926"))))))
              (if (is-null (get-field "every" (get-alt "Aggregate" (param 0)))) 
                (write-u8 (identifier "srec_dst_929") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "every" (get-alt "Aggregate" (param 0)))) (write-u8 (identifier "srec_dst_929") (u8 0)))))
            (let "dst_ref_933"
              (make-vec
                (let "leb128_sz_931" (make-vec (cardinality (get-field "factors" (get-alt "Aggregate" (param 0)))))
                  (let "leb128_ptr_932" (make-vec (identifier "srec_dst_930"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_932")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_932"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_931"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_931"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_931"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_931") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_931")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_931")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_932"))))))
              (let "n_ref_934" (make-vec (i32 0))
                (seq
                  (for-each "x_935" (get-field "factors" (get-alt "Aggregate" (param 0)))
                    (seq (set-vec (u8 0) (identifier "dst_ref_933") (apply (ext-identifier field_name to-row-binary) (identifier "x_935") (unsafe-nth (u8 0) (identifier "dst_ref_933"))))
                      (set-vec (u8 0) (identifier "n_ref_934") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_934")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_933"))))))
          (if (eq (u16 1) (label-of (param 0)))
            (let "srec_dst_880"
              (let "srec_dst_879"
                (let "srec_dst_878" (apply (identifier "external_source-to-row-binary") (get-field "source" (get-alt "ReadExternal" (param 0))) (identifier "ssum_dst_866"))
                  (apply (identifier "external_format-to-row-binary") (get-field "format" (get-alt "ReadExternal" (param 0))) (identifier "srec_dst_878")))
                (if (is-null (get-field "event_time" (get-alt "ReadExternal" (param 0)))) 
                  (write-u8 (identifier "srec_dst_879") (u8 1)) (apply (ext-identifier event_time to-row-binary) (force (get-field "event_time" (get-alt "ReadExternal" (param 0)))) (write-u8 (identifier "srec_dst_879") (u8 0)))))
              (let "dst_ref_883"
                (make-vec
                  (let "leb128_sz_881" (make-vec (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0)))))
                    (let "leb128_ptr_882" (make-vec (identifier "srec_dst_880"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_882")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_882"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_881"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_881"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_881"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_881") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_881")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_881")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_882"))))))
                (let "n_ref_884" (make-vec (i32 0))
                  (seq
                    (for-each "x_885" (get-field "factors" (get-alt "ReadExternal" (param 0)))
                      (seq (set-vec (u8 0) (identifier "dst_ref_883") (apply (ext-identifier field_name to-row-binary) (identifier "x_885") (unsafe-nth (u8 0) (identifier "dst_ref_883"))))
                        (set-vec (u8 0) (identifier "n_ref_884") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_884")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_883"))))))
            (seq (assert (eq (label-of (param 0)) (u16 2)))
              (let "srec_dst_872"
                (let "srec_dst_871"
                  (let "srec_dst_870"
                    (let "srec_dst_869"
                      (write-bytes
                        (let "leb128_sz_867" (make-vec (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0)))))
                          (let "leb128_ptr_868" (make-vec (identifier "ssum_dst_866"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_868")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_868"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_867"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_867"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_867"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_867") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_867")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_867")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_868"))))) 
                        (bytes-of-string (get-field "net_addr" (get-alt "ListenFor" (param 0))))) 
                      (write-u16 little-endian (identifier "srec_dst_869") (get-field "port" (get-alt "ListenFor" (param 0)))))
                    (apply (ext-identifier raql_ip_protocol to-row-binary) (get-field "ip_proto" (get-alt "ListenFor" (param 0))) (identifier "srec_dst_870")))
                  (apply (ext-identifier raql_net_protocol to-row-binary) (get-field "proto" (get-alt "ListenFor" (param 0))) (identifier "srec_dst_871")))
                (let "dst_ref_875"
                  (make-vec
                    (let "leb128_sz_873" (make-vec (cardinality (get-field "factors" (get-alt "ListenFor" (param 0)))))
                      (let "leb128_ptr_874" (make-vec (identifier "srec_dst_872"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_874")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_874"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_873"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_873"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_873"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_873") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_873")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_873")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_874"))))))
                  (let "n_ref_876" (make-vec (i32 0))
                    (seq
                      (for-each "x_877" (get-field "factors" (get-alt "ListenFor" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_875") (apply (ext-identifier field_name to-row-binary) (identifier "x_877") (unsafe-nth (u8 0) (identifier "dst_ref_875"))))
                          (set-vec (u8 0) (identifier "n_ref_876") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_876")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_875")))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t>  &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t>  &,Pointer &)> fun1492 { [&](std::shared_ptr<::dessser::gen::raql_operation::t>  p_0, Pointer p_1) {
    uint16_t id_1493 { uint16_t((*p_0).index()) };
    Pointer id_1494 { p_1.writeU16Le(id_1493) };
    Pointer let_res_1495;
    {
      Pointer ssum_dst_866 { id_1494 };
      uint16_t id_1496 { 0 };
      uint16_t id_1497 { uint16_t((*p_0).index()) };
      bool id_1498 { bool(id_1496 == id_1497) };
      Pointer choose_res_1499;
      if (id_1498) {
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1500 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::raql_select_field::t_ext> id_1501 { id_1500.Aggregate_fields };
        uint32_t id_1502 { id_1501.size() };
        Vec<1, uint32_t> id_1503 {  id_1502  };
        Pointer let_res_1504;
        {
          Vec<1, uint32_t> leb128_sz_886 { id_1503 };
          Vec<1, Pointer> id_1505 {  ssum_dst_866  };
          Pointer let_res_1506;
          {
            Vec<1, Pointer> leb128_ptr_887 { id_1505 };
            bool while_flag_1507 { true };
            do {
              uint8_t id_1508 { 0 };
              uint8_t id_1509 { 0 };
              Pointer id_1510 { leb128_ptr_887[id_1509] };
              uint32_t id_1511 { 128U };
              uint8_t id_1512 { 0 };
              uint32_t id_1513 { leb128_sz_886[id_1512] };
              bool id_1514 { bool(id_1511 > id_1513) };
              uint8_t choose_res_1515;
              if (id_1514) {
                uint8_t id_1516 { 0 };
                uint32_t id_1517 { leb128_sz_886[id_1516] };
                uint8_t id_1518 { uint8_t(id_1517) };
                choose_res_1515 = id_1518;
              } else {
                uint8_t id_1519 { 0 };
                uint32_t id_1520 { leb128_sz_886[id_1519] };
                uint8_t id_1521 { uint8_t(id_1520) };
                uint8_t id_1522 { 128 };
                uint8_t id_1523 { uint8_t(id_1521 | id_1522) };
                choose_res_1515 = id_1523;
              }
              Pointer id_1524 { id_1510.writeU8(choose_res_1515) };
              Void id_1525 { ((void)(leb128_ptr_887[id_1508] = id_1524), ::dessser::Void()) };
              (void)id_1525;
              uint8_t id_1526 { 0 };
              uint8_t id_1527 { 0 };
              uint32_t id_1528 { leb128_sz_886[id_1527] };
              uint8_t id_1529 { 7 };
              uint32_t id_1530 { uint32_t(id_1528 >> id_1529) };
              Void id_1531 { ((void)(leb128_sz_886[id_1526] = id_1530), ::dessser::Void()) };
              (void)id_1531;
              uint8_t id_1532 { 0 };
              uint32_t id_1533 { leb128_sz_886[id_1532] };
              uint32_t id_1534 { 0U };
              bool id_1535 { bool(id_1533 > id_1534) };
              while_flag_1507 = id_1535;
              if (while_flag_1507) {
                (void)::dessser::Void();
              }
            } while (while_flag_1507);
            (void)::dessser::Void();
            uint8_t id_1536 { 0 };
            Pointer id_1537 { leb128_ptr_887[id_1536] };
            let_res_1506 = id_1537;
          }
          let_res_1504 = let_res_1506;
        }
        Vec<1, Pointer> id_1538 {  let_res_1504  };
        Pointer let_res_1539;
        {
          Vec<1, Pointer> dst_ref_888 { id_1538 };
          int32_t id_1540 { 0L };
          Vec<1, int32_t> id_1541 {  id_1540  };
          Pointer let_res_1542;
          {
            Vec<1, int32_t> n_ref_889 { id_1541 };
            ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1543 { std::get<0 /* Aggregate */>((*p_0)) };
            Lst<dessser::gen::raql_select_field::t_ext> id_1544 { id_1543.Aggregate_fields };
            for (dessser::gen::raql_select_field::t_ext &x_890 : id_1544) {
              uint8_t id_1545 { 0 };
              auto fun1546 { dessser::gen::raql_select_field::to_row_binary };
              uint8_t id_1547 { 0 };
              Pointer id_1548 { dst_ref_888[id_1547] };
              Pointer id_1549 { fun1546(x_890, id_1548) };
              Void id_1550 { ((void)(dst_ref_888[id_1545] = id_1549), ::dessser::Void()) };
              (void)id_1550;
              uint8_t id_1551 { 0 };
              int32_t id_1552 { 1L };
              uint8_t id_1553 { 0 };
              int32_t id_1554 { n_ref_889[id_1553] };
              int32_t id_1555 { int32_t(id_1552 + id_1554) };
              Void id_1556 { ((void)(n_ref_889[id_1551] = id_1555), ::dessser::Void()) };
              (void)id_1556;
              (void)id_1556;
            }
            (void)::dessser::Void();
            uint8_t id_1557 { 0 };
            Pointer id_1558 { dst_ref_888[id_1557] };
            let_res_1542 = id_1558;
          }
          let_res_1539 = let_res_1542;
        }
        Pointer let_res_1559;
        {
          Pointer srec_dst_891 { let_res_1539 };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1560 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<Lst<dessser::gen::field_name::t_ext>> id_1561 { id_1560.and_all_others };
          bool id_1562 { !(id_1561.has_value ()) };
          Pointer choose_res_1563;
          if (id_1562) {
            uint8_t id_1564 { 1 };
            Pointer id_1565 { srec_dst_891.writeU8(id_1564) };
            choose_res_1563 = id_1565;
          } else {
            ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1566 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<Lst<dessser::gen::field_name::t_ext>> id_1567 { id_1566.and_all_others };
            Lst<dessser::gen::field_name::t_ext> id_1568 { id_1567.value() };
            uint32_t id_1569 { id_1568.size() };
            Vec<1, uint32_t> id_1570 {  id_1569  };
            Pointer let_res_1571;
            {
              Vec<1, uint32_t> leb128_sz_892 { id_1570 };
              uint8_t id_1572 { 0 };
              Pointer id_1573 { srec_dst_891.writeU8(id_1572) };
              Vec<1, Pointer> id_1574 {  id_1573  };
              Pointer let_res_1575;
              {
                Vec<1, Pointer> leb128_ptr_893 { id_1574 };
                bool while_flag_1576 { true };
                do {
                  uint8_t id_1577 { 0 };
                  uint8_t id_1578 { 0 };
                  Pointer id_1579 { leb128_ptr_893[id_1578] };
                  uint32_t id_1580 { 128U };
                  uint8_t id_1581 { 0 };
                  uint32_t id_1582 { leb128_sz_892[id_1581] };
                  bool id_1583 { bool(id_1580 > id_1582) };
                  uint8_t choose_res_1584;
                  if (id_1583) {
                    uint8_t id_1585 { 0 };
                    uint32_t id_1586 { leb128_sz_892[id_1585] };
                    uint8_t id_1587 { uint8_t(id_1586) };
                    choose_res_1584 = id_1587;
                  } else {
                    uint8_t id_1588 { 0 };
                    uint32_t id_1589 { leb128_sz_892[id_1588] };
                    uint8_t id_1590 { uint8_t(id_1589) };
                    uint8_t id_1591 { 128 };
                    uint8_t id_1592 { uint8_t(id_1590 | id_1591) };
                    choose_res_1584 = id_1592;
                  }
                  Pointer id_1593 { id_1579.writeU8(choose_res_1584) };
                  Void id_1594 { ((void)(leb128_ptr_893[id_1577] = id_1593), ::dessser::Void()) };
                  (void)id_1594;
                  uint8_t id_1595 { 0 };
                  uint8_t id_1596 { 0 };
                  uint32_t id_1597 { leb128_sz_892[id_1596] };
                  uint8_t id_1598 { 7 };
                  uint32_t id_1599 { uint32_t(id_1597 >> id_1598) };
                  Void id_1600 { ((void)(leb128_sz_892[id_1595] = id_1599), ::dessser::Void()) };
                  (void)id_1600;
                  uint8_t id_1601 { 0 };
                  uint32_t id_1602 { leb128_sz_892[id_1601] };
                  uint32_t id_1603 { 0U };
                  bool id_1604 { bool(id_1602 > id_1603) };
                  while_flag_1576 = id_1604;
                  if (while_flag_1576) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_1576);
                (void)::dessser::Void();
                uint8_t id_1605 { 0 };
                Pointer id_1606 { leb128_ptr_893[id_1605] };
                let_res_1575 = id_1606;
              }
              let_res_1571 = let_res_1575;
            }
            Vec<1, Pointer> id_1607 {  let_res_1571  };
            Pointer let_res_1608;
            {
              Vec<1, Pointer> dst_ref_894 { id_1607 };
              int32_t id_1609 { 0L };
              Vec<1, int32_t> id_1610 {  id_1609  };
              Pointer let_res_1611;
              {
                Vec<1, int32_t> n_ref_895 { id_1610 };
                ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1612 { std::get<0 /* Aggregate */>((*p_0)) };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_1613 { id_1612.and_all_others };
                Lst<dessser::gen::field_name::t_ext> id_1614 { id_1613.value() };
                for (dessser::gen::field_name::t_ext &x_896 : id_1614) {
                  uint8_t id_1615 { 0 };
                  auto fun1616 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_1617 { 0 };
                  Pointer id_1618 { dst_ref_894[id_1617] };
                  Pointer id_1619 { fun1616(x_896, id_1618) };
                  Void id_1620 { ((void)(dst_ref_894[id_1615] = id_1619), ::dessser::Void()) };
                  (void)id_1620;
                  uint8_t id_1621 { 0 };
                  int32_t id_1622 { 1L };
                  uint8_t id_1623 { 0 };
                  int32_t id_1624 { n_ref_895[id_1623] };
                  int32_t id_1625 { int32_t(id_1622 + id_1624) };
                  Void id_1626 { ((void)(n_ref_895[id_1621] = id_1625), ::dessser::Void()) };
                  (void)id_1626;
                  (void)id_1626;
                }
                (void)::dessser::Void();
                uint8_t id_1627 { 0 };
                Pointer id_1628 { dst_ref_894[id_1627] };
                let_res_1611 = id_1628;
              }
              let_res_1608 = let_res_1611;
            }
            choose_res_1563 = let_res_1608;
          }
          let_res_1559 = choose_res_1563;
        }
        Pointer let_res_1629;
        {
          Pointer srec_dst_897 { let_res_1559 };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1630 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1631 { id_1630.sort };
          bool id_1632 { !(id_1631.has_value ()) };
          Pointer choose_res_1633;
          if (id_1632) {
            uint8_t id_1634 { 1 };
            Pointer id_1635 { srec_dst_897.writeU8(id_1634) };
            choose_res_1633 = id_1635;
          } else {
            uint8_t id_1636 { 0 };
            Pointer id_1637 { srec_dst_897.writeU8(id_1636) };
            Pointer let_res_1638;
            {
              Pointer stup_dst_898 { id_1637 };
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1639 { std::get<0 /* Aggregate */>((*p_0)) };
              std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1640 { id_1639.sort };
              ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1641 { id_1640.value() };
              uint32_t id_1642 { std::get<0>(id_1641) };
              Pointer id_1643 { stup_dst_898.writeU32Le(id_1642) };
              let_res_1638 = id_1643;
            }
            Pointer let_res_1644;
            {
              Pointer stup_dst_899 { let_res_1638 };
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1645 { std::get<0 /* Aggregate */>((*p_0)) };
              std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1646 { id_1645.sort };
              ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1647 { id_1646.value() };
              std::optional<dessser::gen::raql_expr::t_ext> id_1648 { std::get<1>(id_1647) };
              bool id_1649 { !(id_1648.has_value ()) };
              Pointer choose_res_1650;
              if (id_1649) {
                uint8_t id_1651 { 1 };
                Pointer id_1652 { stup_dst_899.writeU8(id_1651) };
                choose_res_1650 = id_1652;
              } else {
                auto fun1653 { dessser::gen::raql_expr::to_row_binary };
                ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1654 { std::get<0 /* Aggregate */>((*p_0)) };
                std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1655 { id_1654.sort };
                ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1656 { id_1655.value() };
                std::optional<dessser::gen::raql_expr::t_ext> id_1657 { std::get<1>(id_1656) };
                dessser::gen::raql_expr::t_ext id_1658 { id_1657.value() };
                uint8_t id_1659 { 0 };
                Pointer id_1660 { stup_dst_899.writeU8(id_1659) };
                Pointer id_1661 { fun1653(id_1658, id_1660) };
                choose_res_1650 = id_1661;
              }
              let_res_1644 = choose_res_1650;
            }
            Pointer let_res_1662;
            {
              Pointer stup_dst_900 { let_res_1644 };
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1663 { std::get<0 /* Aggregate */>((*p_0)) };
              std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1664 { id_1663.sort };
              ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1665 { id_1664.value() };
              Lst<dessser::gen::raql_expr::t_ext> id_1666 { std::get<2>(id_1665) };
              uint32_t id_1667 { id_1666.size() };
              Vec<1, uint32_t> id_1668 {  id_1667  };
              Pointer let_res_1669;
              {
                Vec<1, uint32_t> leb128_sz_901 { id_1668 };
                Vec<1, Pointer> id_1670 {  stup_dst_900  };
                Pointer let_res_1671;
                {
                  Vec<1, Pointer> leb128_ptr_902 { id_1670 };
                  bool while_flag_1672 { true };
                  do {
                    uint8_t id_1673 { 0 };
                    uint8_t id_1674 { 0 };
                    Pointer id_1675 { leb128_ptr_902[id_1674] };
                    uint32_t id_1676 { 128U };
                    uint8_t id_1677 { 0 };
                    uint32_t id_1678 { leb128_sz_901[id_1677] };
                    bool id_1679 { bool(id_1676 > id_1678) };
                    uint8_t choose_res_1680;
                    if (id_1679) {
                      uint8_t id_1681 { 0 };
                      uint32_t id_1682 { leb128_sz_901[id_1681] };
                      uint8_t id_1683 { uint8_t(id_1682) };
                      choose_res_1680 = id_1683;
                    } else {
                      uint8_t id_1684 { 0 };
                      uint32_t id_1685 { leb128_sz_901[id_1684] };
                      uint8_t id_1686 { uint8_t(id_1685) };
                      uint8_t id_1687 { 128 };
                      uint8_t id_1688 { uint8_t(id_1686 | id_1687) };
                      choose_res_1680 = id_1688;
                    }
                    Pointer id_1689 { id_1675.writeU8(choose_res_1680) };
                    Void id_1690 { ((void)(leb128_ptr_902[id_1673] = id_1689), ::dessser::Void()) };
                    (void)id_1690;
                    uint8_t id_1691 { 0 };
                    uint8_t id_1692 { 0 };
                    uint32_t id_1693 { leb128_sz_901[id_1692] };
                    uint8_t id_1694 { 7 };
                    uint32_t id_1695 { uint32_t(id_1693 >> id_1694) };
                    Void id_1696 { ((void)(leb128_sz_901[id_1691] = id_1695), ::dessser::Void()) };
                    (void)id_1696;
                    uint8_t id_1697 { 0 };
                    uint32_t id_1698 { leb128_sz_901[id_1697] };
                    uint32_t id_1699 { 0U };
                    bool id_1700 { bool(id_1698 > id_1699) };
                    while_flag_1672 = id_1700;
                    if (while_flag_1672) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_1672);
                  (void)::dessser::Void();
                  uint8_t id_1701 { 0 };
                  Pointer id_1702 { leb128_ptr_902[id_1701] };
                  let_res_1671 = id_1702;
                }
                let_res_1669 = let_res_1671;
              }
              Vec<1, Pointer> id_1703 {  let_res_1669  };
              Pointer let_res_1704;
              {
                Vec<1, Pointer> dst_ref_903 { id_1703 };
                int32_t id_1705 { 0L };
                Vec<1, int32_t> id_1706 {  id_1705  };
                Pointer let_res_1707;
                {
                  Vec<1, int32_t> n_ref_904 { id_1706 };
                  ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1708 { std::get<0 /* Aggregate */>((*p_0)) };
                  std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1709 { id_1708.sort };
                  ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1710 { id_1709.value() };
                  Lst<dessser::gen::raql_expr::t_ext> id_1711 { std::get<2>(id_1710) };
                  for (dessser::gen::raql_expr::t_ext &x_905 : id_1711) {
                    uint8_t id_1712 { 0 };
                    auto fun1713 { dessser::gen::raql_expr::to_row_binary };
                    uint8_t id_1714 { 0 };
                    Pointer id_1715 { dst_ref_903[id_1714] };
                    Pointer id_1716 { fun1713(x_905, id_1715) };
                    Void id_1717 { ((void)(dst_ref_903[id_1712] = id_1716), ::dessser::Void()) };
                    (void)id_1717;
                    uint8_t id_1718 { 0 };
                    int32_t id_1719 { 1L };
                    uint8_t id_1720 { 0 };
                    int32_t id_1721 { n_ref_904[id_1720] };
                    int32_t id_1722 { int32_t(id_1719 + id_1721) };
                    Void id_1723 { ((void)(n_ref_904[id_1718] = id_1722), ::dessser::Void()) };
                    (void)id_1723;
                    (void)id_1723;
                  }
                  (void)::dessser::Void();
                  uint8_t id_1724 { 0 };
                  Pointer id_1725 { dst_ref_903[id_1724] };
                  let_res_1707 = id_1725;
                }
                let_res_1704 = let_res_1707;
              }
              let_res_1662 = let_res_1704;
            }
            choose_res_1633 = let_res_1662;
          }
          let_res_1629 = choose_res_1633;
        }
        Pointer let_res_1726;
        {
          Pointer srec_dst_906 { let_res_1629 };
          auto fun1727 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1728 { std::get<0 /* Aggregate */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_1729 { id_1728.where };
          Pointer id_1730 { fun1727(id_1729, srec_dst_906) };
          let_res_1726 = id_1730;
        }
        Pointer let_res_1731;
        {
          Pointer srec_dst_907 { let_res_1726 };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1732 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::event_time::t_ext> id_1733 { id_1732.Aggregate_event_time };
          bool id_1734 { !(id_1733.has_value ()) };
          Pointer choose_res_1735;
          if (id_1734) {
            uint8_t id_1736 { 1 };
            Pointer id_1737 { srec_dst_907.writeU8(id_1736) };
            choose_res_1735 = id_1737;
          } else {
            auto fun1738 { dessser::gen::event_time::to_row_binary };
            ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1739 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<dessser::gen::event_time::t_ext> id_1740 { id_1739.Aggregate_event_time };
            dessser::gen::event_time::t_ext id_1741 { id_1740.value() };
            uint8_t id_1742 { 0 };
            Pointer id_1743 { srec_dst_907.writeU8(id_1742) };
            Pointer id_1744 { fun1738(id_1741, id_1743) };
            choose_res_1735 = id_1744;
          }
          let_res_1731 = choose_res_1735;
        }
        Pointer let_res_1745;
        {
          Pointer srec_dst_908 { let_res_1731 };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1746 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<dessser::gen::raql_expr::t_ext> id_1747 { id_1746.notifications };
          uint32_t id_1748 { id_1747.size() };
          Vec<1, uint32_t> id_1749 {  id_1748  };
          Pointer let_res_1750;
          {
            Vec<1, uint32_t> leb128_sz_909 { id_1749 };
            Vec<1, Pointer> id_1751 {  srec_dst_908  };
            Pointer let_res_1752;
            {
              Vec<1, Pointer> leb128_ptr_910 { id_1751 };
              bool while_flag_1753 { true };
              do {
                uint8_t id_1754 { 0 };
                uint8_t id_1755 { 0 };
                Pointer id_1756 { leb128_ptr_910[id_1755] };
                uint32_t id_1757 { 128U };
                uint8_t id_1758 { 0 };
                uint32_t id_1759 { leb128_sz_909[id_1758] };
                bool id_1760 { bool(id_1757 > id_1759) };
                uint8_t choose_res_1761;
                if (id_1760) {
                  uint8_t id_1762 { 0 };
                  uint32_t id_1763 { leb128_sz_909[id_1762] };
                  uint8_t id_1764 { uint8_t(id_1763) };
                  choose_res_1761 = id_1764;
                } else {
                  uint8_t id_1765 { 0 };
                  uint32_t id_1766 { leb128_sz_909[id_1765] };
                  uint8_t id_1767 { uint8_t(id_1766) };
                  uint8_t id_1768 { 128 };
                  uint8_t id_1769 { uint8_t(id_1767 | id_1768) };
                  choose_res_1761 = id_1769;
                }
                Pointer id_1770 { id_1756.writeU8(choose_res_1761) };
                Void id_1771 { ((void)(leb128_ptr_910[id_1754] = id_1770), ::dessser::Void()) };
                (void)id_1771;
                uint8_t id_1772 { 0 };
                uint8_t id_1773 { 0 };
                uint32_t id_1774 { leb128_sz_909[id_1773] };
                uint8_t id_1775 { 7 };
                uint32_t id_1776 { uint32_t(id_1774 >> id_1775) };
                Void id_1777 { ((void)(leb128_sz_909[id_1772] = id_1776), ::dessser::Void()) };
                (void)id_1777;
                uint8_t id_1778 { 0 };
                uint32_t id_1779 { leb128_sz_909[id_1778] };
                uint32_t id_1780 { 0U };
                bool id_1781 { bool(id_1779 > id_1780) };
                while_flag_1753 = id_1781;
                if (while_flag_1753) {
                  (void)::dessser::Void();
                }
              } while (while_flag_1753);
              (void)::dessser::Void();
              uint8_t id_1782 { 0 };
              Pointer id_1783 { leb128_ptr_910[id_1782] };
              let_res_1752 = id_1783;
            }
            let_res_1750 = let_res_1752;
          }
          Vec<1, Pointer> id_1784 {  let_res_1750  };
          Pointer let_res_1785;
          {
            Vec<1, Pointer> dst_ref_911 { id_1784 };
            int32_t id_1786 { 0L };
            Vec<1, int32_t> id_1787 {  id_1786  };
            Pointer let_res_1788;
            {
              Vec<1, int32_t> n_ref_912 { id_1787 };
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1789 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_1790 { id_1789.notifications };
              for (dessser::gen::raql_expr::t_ext &x_913 : id_1790) {
                uint8_t id_1791 { 0 };
                auto fun1792 { dessser::gen::raql_expr::to_row_binary };
                uint8_t id_1793 { 0 };
                Pointer id_1794 { dst_ref_911[id_1793] };
                Pointer id_1795 { fun1792(x_913, id_1794) };
                Void id_1796 { ((void)(dst_ref_911[id_1791] = id_1795), ::dessser::Void()) };
                (void)id_1796;
                uint8_t id_1797 { 0 };
                int32_t id_1798 { 1L };
                uint8_t id_1799 { 0 };
                int32_t id_1800 { n_ref_912[id_1799] };
                int32_t id_1801 { int32_t(id_1798 + id_1800) };
                Void id_1802 { ((void)(n_ref_912[id_1797] = id_1801), ::dessser::Void()) };
                (void)id_1802;
                (void)id_1802;
              }
              (void)::dessser::Void();
              uint8_t id_1803 { 0 };
              Pointer id_1804 { dst_ref_911[id_1803] };
              let_res_1788 = id_1804;
            }
            let_res_1785 = let_res_1788;
          }
          let_res_1745 = let_res_1785;
        }
        Pointer let_res_1805;
        {
          Pointer srec_dst_914 { let_res_1745 };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1806 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<dessser::gen::raql_expr::t_ext> id_1807 { id_1806.key };
          uint32_t id_1808 { id_1807.size() };
          Vec<1, uint32_t> id_1809 {  id_1808  };
          Pointer let_res_1810;
          {
            Vec<1, uint32_t> leb128_sz_915 { id_1809 };
            Vec<1, Pointer> id_1811 {  srec_dst_914  };
            Pointer let_res_1812;
            {
              Vec<1, Pointer> leb128_ptr_916 { id_1811 };
              bool while_flag_1813 { true };
              do {
                uint8_t id_1814 { 0 };
                uint8_t id_1815 { 0 };
                Pointer id_1816 { leb128_ptr_916[id_1815] };
                uint32_t id_1817 { 128U };
                uint8_t id_1818 { 0 };
                uint32_t id_1819 { leb128_sz_915[id_1818] };
                bool id_1820 { bool(id_1817 > id_1819) };
                uint8_t choose_res_1821;
                if (id_1820) {
                  uint8_t id_1822 { 0 };
                  uint32_t id_1823 { leb128_sz_915[id_1822] };
                  uint8_t id_1824 { uint8_t(id_1823) };
                  choose_res_1821 = id_1824;
                } else {
                  uint8_t id_1825 { 0 };
                  uint32_t id_1826 { leb128_sz_915[id_1825] };
                  uint8_t id_1827 { uint8_t(id_1826) };
                  uint8_t id_1828 { 128 };
                  uint8_t id_1829 { uint8_t(id_1827 | id_1828) };
                  choose_res_1821 = id_1829;
                }
                Pointer id_1830 { id_1816.writeU8(choose_res_1821) };
                Void id_1831 { ((void)(leb128_ptr_916[id_1814] = id_1830), ::dessser::Void()) };
                (void)id_1831;
                uint8_t id_1832 { 0 };
                uint8_t id_1833 { 0 };
                uint32_t id_1834 { leb128_sz_915[id_1833] };
                uint8_t id_1835 { 7 };
                uint32_t id_1836 { uint32_t(id_1834 >> id_1835) };
                Void id_1837 { ((void)(leb128_sz_915[id_1832] = id_1836), ::dessser::Void()) };
                (void)id_1837;
                uint8_t id_1838 { 0 };
                uint32_t id_1839 { leb128_sz_915[id_1838] };
                uint32_t id_1840 { 0U };
                bool id_1841 { bool(id_1839 > id_1840) };
                while_flag_1813 = id_1841;
                if (while_flag_1813) {
                  (void)::dessser::Void();
                }
              } while (while_flag_1813);
              (void)::dessser::Void();
              uint8_t id_1842 { 0 };
              Pointer id_1843 { leb128_ptr_916[id_1842] };
              let_res_1812 = id_1843;
            }
            let_res_1810 = let_res_1812;
          }
          Vec<1, Pointer> id_1844 {  let_res_1810  };
          Pointer let_res_1845;
          {
            Vec<1, Pointer> dst_ref_917 { id_1844 };
            int32_t id_1846 { 0L };
            Vec<1, int32_t> id_1847 {  id_1846  };
            Pointer let_res_1848;
            {
              Vec<1, int32_t> n_ref_918 { id_1847 };
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1849 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_1850 { id_1849.key };
              for (dessser::gen::raql_expr::t_ext &x_919 : id_1850) {
                uint8_t id_1851 { 0 };
                auto fun1852 { dessser::gen::raql_expr::to_row_binary };
                uint8_t id_1853 { 0 };
                Pointer id_1854 { dst_ref_917[id_1853] };
                Pointer id_1855 { fun1852(x_919, id_1854) };
                Void id_1856 { ((void)(dst_ref_917[id_1851] = id_1855), ::dessser::Void()) };
                (void)id_1856;
                uint8_t id_1857 { 0 };
                int32_t id_1858 { 1L };
                uint8_t id_1859 { 0 };
                int32_t id_1860 { n_ref_918[id_1859] };
                int32_t id_1861 { int32_t(id_1858 + id_1860) };
                Void id_1862 { ((void)(n_ref_918[id_1857] = id_1861), ::dessser::Void()) };
                (void)id_1862;
                (void)id_1862;
              }
              (void)::dessser::Void();
              uint8_t id_1863 { 0 };
              Pointer id_1864 { dst_ref_917[id_1863] };
              let_res_1848 = id_1864;
            }
            let_res_1845 = let_res_1848;
          }
          let_res_1805 = let_res_1845;
        }
        Pointer let_res_1865;
        {
          Pointer srec_dst_920 { let_res_1805 };
          auto fun1866 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1867 { std::get<0 /* Aggregate */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_1868 { id_1867.commit_cond };
          Pointer id_1869 { fun1866(id_1868, srec_dst_920) };
          let_res_1865 = id_1869;
        }
        Pointer let_res_1870;
        {
          Pointer srec_dst_921 { let_res_1865 };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1871 { std::get<0 /* Aggregate */>((*p_0)) };
          bool id_1872 { id_1871.commit_before };
          uint8_t id_1873 { uint8_t(id_1872) };
          Pointer id_1874 { srec_dst_921.writeU8(id_1873) };
          let_res_1870 = id_1874;
        }
        Pointer let_res_1875;
        {
          Pointer srec_dst_922 { let_res_1870 };
          auto fun1876 { dessser::gen::raql_flush_method::to_row_binary };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1877 { std::get<0 /* Aggregate */>((*p_0)) };
          dessser::gen::raql_flush_method::t_ext id_1878 { id_1877.flush_how };
          Pointer id_1879 { fun1876(id_1878, srec_dst_922) };
          let_res_1875 = id_1879;
        }
        Pointer let_res_1880;
        {
          Pointer srec_dst_923 { let_res_1875 };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1881 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<::dessser::gen::raql_operation::data_source> id_1882 { id_1881.from };
          uint32_t id_1883 { id_1882.size() };
          Vec<1, uint32_t> id_1884 {  id_1883  };
          Pointer let_res_1885;
          {
            Vec<1, uint32_t> leb128_sz_924 { id_1884 };
            Vec<1, Pointer> id_1886 {  srec_dst_923  };
            Pointer let_res_1887;
            {
              Vec<1, Pointer> leb128_ptr_925 { id_1886 };
              bool while_flag_1888 { true };
              do {
                uint8_t id_1889 { 0 };
                uint8_t id_1890 { 0 };
                Pointer id_1891 { leb128_ptr_925[id_1890] };
                uint32_t id_1892 { 128U };
                uint8_t id_1893 { 0 };
                uint32_t id_1894 { leb128_sz_924[id_1893] };
                bool id_1895 { bool(id_1892 > id_1894) };
                uint8_t choose_res_1896;
                if (id_1895) {
                  uint8_t id_1897 { 0 };
                  uint32_t id_1898 { leb128_sz_924[id_1897] };
                  uint8_t id_1899 { uint8_t(id_1898) };
                  choose_res_1896 = id_1899;
                } else {
                  uint8_t id_1900 { 0 };
                  uint32_t id_1901 { leb128_sz_924[id_1900] };
                  uint8_t id_1902 { uint8_t(id_1901) };
                  uint8_t id_1903 { 128 };
                  uint8_t id_1904 { uint8_t(id_1902 | id_1903) };
                  choose_res_1896 = id_1904;
                }
                Pointer id_1905 { id_1891.writeU8(choose_res_1896) };
                Void id_1906 { ((void)(leb128_ptr_925[id_1889] = id_1905), ::dessser::Void()) };
                (void)id_1906;
                uint8_t id_1907 { 0 };
                uint8_t id_1908 { 0 };
                uint32_t id_1909 { leb128_sz_924[id_1908] };
                uint8_t id_1910 { 7 };
                uint32_t id_1911 { uint32_t(id_1909 >> id_1910) };
                Void id_1912 { ((void)(leb128_sz_924[id_1907] = id_1911), ::dessser::Void()) };
                (void)id_1912;
                uint8_t id_1913 { 0 };
                uint32_t id_1914 { leb128_sz_924[id_1913] };
                uint32_t id_1915 { 0U };
                bool id_1916 { bool(id_1914 > id_1915) };
                while_flag_1888 = id_1916;
                if (while_flag_1888) {
                  (void)::dessser::Void();
                }
              } while (while_flag_1888);
              (void)::dessser::Void();
              uint8_t id_1917 { 0 };
              Pointer id_1918 { leb128_ptr_925[id_1917] };
              let_res_1887 = id_1918;
            }
            let_res_1885 = let_res_1887;
          }
          Vec<1, Pointer> id_1919 {  let_res_1885  };
          Pointer let_res_1920;
          {
            Vec<1, Pointer> dst_ref_926 { id_1919 };
            int32_t id_1921 { 0L };
            Vec<1, int32_t> id_1922 {  id_1921  };
            Pointer let_res_1923;
            {
              Vec<1, int32_t> n_ref_927 { id_1922 };
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1924 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<::dessser::gen::raql_operation::data_source> id_1925 { id_1924.from };
              for (::dessser::gen::raql_operation::data_source &x_928 : id_1925) {
                uint8_t id_1926 { 0 };
                uint8_t id_1927 { 0 };
                Pointer id_1928 { dst_ref_926[id_1927] };
                Pointer id_1929 { data_source_to_row_binary(x_928, id_1928) };
                Void id_1930 { ((void)(dst_ref_926[id_1926] = id_1929), ::dessser::Void()) };
                (void)id_1930;
                uint8_t id_1931 { 0 };
                int32_t id_1932 { 1L };
                uint8_t id_1933 { 0 };
                int32_t id_1934 { n_ref_927[id_1933] };
                int32_t id_1935 { int32_t(id_1932 + id_1934) };
                Void id_1936 { ((void)(n_ref_927[id_1931] = id_1935), ::dessser::Void()) };
                (void)id_1936;
                (void)id_1936;
              }
              (void)::dessser::Void();
              uint8_t id_1937 { 0 };
              Pointer id_1938 { dst_ref_926[id_1937] };
              let_res_1923 = id_1938;
            }
            let_res_1920 = let_res_1923;
          }
          let_res_1880 = let_res_1920;
        }
        Pointer let_res_1939;
        {
          Pointer srec_dst_929 { let_res_1880 };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1940 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_1941 { id_1940.every };
          bool id_1942 { !(id_1941.has_value ()) };
          Pointer choose_res_1943;
          if (id_1942) {
            uint8_t id_1944 { 1 };
            Pointer id_1945 { srec_dst_929.writeU8(id_1944) };
            choose_res_1943 = id_1945;
          } else {
            auto fun1946 { dessser::gen::raql_expr::to_row_binary };
            ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1947 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<dessser::gen::raql_expr::t_ext> id_1948 { id_1947.every };
            dessser::gen::raql_expr::t_ext id_1949 { id_1948.value() };
            uint8_t id_1950 { 0 };
            Pointer id_1951 { srec_dst_929.writeU8(id_1950) };
            Pointer id_1952 { fun1946(id_1949, id_1951) };
            choose_res_1943 = id_1952;
          }
          let_res_1939 = choose_res_1943;
        }
        Pointer let_res_1953;
        {
          Pointer srec_dst_930 { let_res_1939 };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1954 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<dessser::gen::field_name::t_ext> id_1955 { id_1954.Aggregate_factors };
          uint32_t id_1956 { id_1955.size() };
          Vec<1, uint32_t> id_1957 {  id_1956  };
          Pointer let_res_1958;
          {
            Vec<1, uint32_t> leb128_sz_931 { id_1957 };
            Vec<1, Pointer> id_1959 {  srec_dst_930  };
            Pointer let_res_1960;
            {
              Vec<1, Pointer> leb128_ptr_932 { id_1959 };
              bool while_flag_1961 { true };
              do {
                uint8_t id_1962 { 0 };
                uint8_t id_1963 { 0 };
                Pointer id_1964 { leb128_ptr_932[id_1963] };
                uint32_t id_1965 { 128U };
                uint8_t id_1966 { 0 };
                uint32_t id_1967 { leb128_sz_931[id_1966] };
                bool id_1968 { bool(id_1965 > id_1967) };
                uint8_t choose_res_1969;
                if (id_1968) {
                  uint8_t id_1970 { 0 };
                  uint32_t id_1971 { leb128_sz_931[id_1970] };
                  uint8_t id_1972 { uint8_t(id_1971) };
                  choose_res_1969 = id_1972;
                } else {
                  uint8_t id_1973 { 0 };
                  uint32_t id_1974 { leb128_sz_931[id_1973] };
                  uint8_t id_1975 { uint8_t(id_1974) };
                  uint8_t id_1976 { 128 };
                  uint8_t id_1977 { uint8_t(id_1975 | id_1976) };
                  choose_res_1969 = id_1977;
                }
                Pointer id_1978 { id_1964.writeU8(choose_res_1969) };
                Void id_1979 { ((void)(leb128_ptr_932[id_1962] = id_1978), ::dessser::Void()) };
                (void)id_1979;
                uint8_t id_1980 { 0 };
                uint8_t id_1981 { 0 };
                uint32_t id_1982 { leb128_sz_931[id_1981] };
                uint8_t id_1983 { 7 };
                uint32_t id_1984 { uint32_t(id_1982 >> id_1983) };
                Void id_1985 { ((void)(leb128_sz_931[id_1980] = id_1984), ::dessser::Void()) };
                (void)id_1985;
                uint8_t id_1986 { 0 };
                uint32_t id_1987 { leb128_sz_931[id_1986] };
                uint32_t id_1988 { 0U };
                bool id_1989 { bool(id_1987 > id_1988) };
                while_flag_1961 = id_1989;
                if (while_flag_1961) {
                  (void)::dessser::Void();
                }
              } while (while_flag_1961);
              (void)::dessser::Void();
              uint8_t id_1990 { 0 };
              Pointer id_1991 { leb128_ptr_932[id_1990] };
              let_res_1960 = id_1991;
            }
            let_res_1958 = let_res_1960;
          }
          Vec<1, Pointer> id_1992 {  let_res_1958  };
          Pointer let_res_1993;
          {
            Vec<1, Pointer> dst_ref_933 { id_1992 };
            int32_t id_1994 { 0L };
            Vec<1, int32_t> id_1995 {  id_1994  };
            Pointer let_res_1996;
            {
              Vec<1, int32_t> n_ref_934 { id_1995 };
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_1997 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::field_name::t_ext> id_1998 { id_1997.Aggregate_factors };
              for (dessser::gen::field_name::t_ext &x_935 : id_1998) {
                uint8_t id_1999 { 0 };
                auto fun2000 { dessser::gen::field_name::to_row_binary };
                uint8_t id_2001 { 0 };
                Pointer id_2002 { dst_ref_933[id_2001] };
                Pointer id_2003 { fun2000(x_935, id_2002) };
                Void id_2004 { ((void)(dst_ref_933[id_1999] = id_2003), ::dessser::Void()) };
                (void)id_2004;
                uint8_t id_2005 { 0 };
                int32_t id_2006 { 1L };
                uint8_t id_2007 { 0 };
                int32_t id_2008 { n_ref_934[id_2007] };
                int32_t id_2009 { int32_t(id_2006 + id_2008) };
                Void id_2010 { ((void)(n_ref_934[id_2005] = id_2009), ::dessser::Void()) };
                (void)id_2010;
                (void)id_2010;
              }
              (void)::dessser::Void();
              uint8_t id_2011 { 0 };
              Pointer id_2012 { dst_ref_933[id_2011] };
              let_res_1996 = id_2012;
            }
            let_res_1993 = let_res_1996;
          }
          let_res_1953 = let_res_1993;
        }
        choose_res_1499 = let_res_1953;
      } else {
        uint16_t id_2013 { 1 };
        uint16_t id_2014 { uint16_t((*p_0).index()) };
        bool id_2015 { bool(id_2013 == id_2014) };
        Pointer choose_res_2016;
        if (id_2015) {
          ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2017 { std::get<1 /* ReadExternal */>((*p_0)) };
          ::dessser::gen::raql_operation::external_source id_2018 { id_2017.source };
          Pointer id_2019 { external_source_to_row_binary(id_2018, ssum_dst_866) };
          Pointer let_res_2020;
          {
            Pointer srec_dst_878 { id_2019 };
            ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2021 { std::get<1 /* ReadExternal */>((*p_0)) };
            ::dessser::gen::raql_operation::external_format id_2022 { id_2021.format };
            Pointer id_2023 { external_format_to_row_binary(id_2022, srec_dst_878) };
            let_res_2020 = id_2023;
          }
          Pointer let_res_2024;
          {
            Pointer srec_dst_879 { let_res_2020 };
            ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2025 { std::get<1 /* ReadExternal */>((*p_0)) };
            std::optional<dessser::gen::event_time::t_ext> id_2026 { id_2025.event_time };
            bool id_2027 { !(id_2026.has_value ()) };
            Pointer choose_res_2028;
            if (id_2027) {
              uint8_t id_2029 { 1 };
              Pointer id_2030 { srec_dst_879.writeU8(id_2029) };
              choose_res_2028 = id_2030;
            } else {
              auto fun2031 { dessser::gen::event_time::to_row_binary };
              ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2032 { std::get<1 /* ReadExternal */>((*p_0)) };
              std::optional<dessser::gen::event_time::t_ext> id_2033 { id_2032.event_time };
              dessser::gen::event_time::t_ext id_2034 { id_2033.value() };
              uint8_t id_2035 { 0 };
              Pointer id_2036 { srec_dst_879.writeU8(id_2035) };
              Pointer id_2037 { fun2031(id_2034, id_2036) };
              choose_res_2028 = id_2037;
            }
            let_res_2024 = choose_res_2028;
          }
          Pointer let_res_2038;
          {
            Pointer srec_dst_880 { let_res_2024 };
            ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2039 { std::get<1 /* ReadExternal */>((*p_0)) };
            Lst<dessser::gen::field_name::t_ext> id_2040 { id_2039.ReadExternal_factors };
            uint32_t id_2041 { id_2040.size() };
            Vec<1, uint32_t> id_2042 {  id_2041  };
            Pointer let_res_2043;
            {
              Vec<1, uint32_t> leb128_sz_881 { id_2042 };
              Vec<1, Pointer> id_2044 {  srec_dst_880  };
              Pointer let_res_2045;
              {
                Vec<1, Pointer> leb128_ptr_882 { id_2044 };
                bool while_flag_2046 { true };
                do {
                  uint8_t id_2047 { 0 };
                  uint8_t id_2048 { 0 };
                  Pointer id_2049 { leb128_ptr_882[id_2048] };
                  uint32_t id_2050 { 128U };
                  uint8_t id_2051 { 0 };
                  uint32_t id_2052 { leb128_sz_881[id_2051] };
                  bool id_2053 { bool(id_2050 > id_2052) };
                  uint8_t choose_res_2054;
                  if (id_2053) {
                    uint8_t id_2055 { 0 };
                    uint32_t id_2056 { leb128_sz_881[id_2055] };
                    uint8_t id_2057 { uint8_t(id_2056) };
                    choose_res_2054 = id_2057;
                  } else {
                    uint8_t id_2058 { 0 };
                    uint32_t id_2059 { leb128_sz_881[id_2058] };
                    uint8_t id_2060 { uint8_t(id_2059) };
                    uint8_t id_2061 { 128 };
                    uint8_t id_2062 { uint8_t(id_2060 | id_2061) };
                    choose_res_2054 = id_2062;
                  }
                  Pointer id_2063 { id_2049.writeU8(choose_res_2054) };
                  Void id_2064 { ((void)(leb128_ptr_882[id_2047] = id_2063), ::dessser::Void()) };
                  (void)id_2064;
                  uint8_t id_2065 { 0 };
                  uint8_t id_2066 { 0 };
                  uint32_t id_2067 { leb128_sz_881[id_2066] };
                  uint8_t id_2068 { 7 };
                  uint32_t id_2069 { uint32_t(id_2067 >> id_2068) };
                  Void id_2070 { ((void)(leb128_sz_881[id_2065] = id_2069), ::dessser::Void()) };
                  (void)id_2070;
                  uint8_t id_2071 { 0 };
                  uint32_t id_2072 { leb128_sz_881[id_2071] };
                  uint32_t id_2073 { 0U };
                  bool id_2074 { bool(id_2072 > id_2073) };
                  while_flag_2046 = id_2074;
                  if (while_flag_2046) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_2046);
                (void)::dessser::Void();
                uint8_t id_2075 { 0 };
                Pointer id_2076 { leb128_ptr_882[id_2075] };
                let_res_2045 = id_2076;
              }
              let_res_2043 = let_res_2045;
            }
            Vec<1, Pointer> id_2077 {  let_res_2043  };
            Pointer let_res_2078;
            {
              Vec<1, Pointer> dst_ref_883 { id_2077 };
              int32_t id_2079 { 0L };
              Vec<1, int32_t> id_2080 {  id_2079  };
              Pointer let_res_2081;
              {
                Vec<1, int32_t> n_ref_884 { id_2080 };
                ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2082 { std::get<1 /* ReadExternal */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2083 { id_2082.ReadExternal_factors };
                for (dessser::gen::field_name::t_ext &x_885 : id_2083) {
                  uint8_t id_2084 { 0 };
                  auto fun2085 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_2086 { 0 };
                  Pointer id_2087 { dst_ref_883[id_2086] };
                  Pointer id_2088 { fun2085(x_885, id_2087) };
                  Void id_2089 { ((void)(dst_ref_883[id_2084] = id_2088), ::dessser::Void()) };
                  (void)id_2089;
                  uint8_t id_2090 { 0 };
                  int32_t id_2091 { 1L };
                  uint8_t id_2092 { 0 };
                  int32_t id_2093 { n_ref_884[id_2092] };
                  int32_t id_2094 { int32_t(id_2091 + id_2093) };
                  Void id_2095 { ((void)(n_ref_884[id_2090] = id_2094), ::dessser::Void()) };
                  (void)id_2095;
                  (void)id_2095;
                }
                (void)::dessser::Void();
                uint8_t id_2096 { 0 };
                Pointer id_2097 { dst_ref_883[id_2096] };
                let_res_2081 = id_2097;
              }
              let_res_2078 = let_res_2081;
            }
            let_res_2038 = let_res_2078;
          }
          choose_res_2016 = let_res_2038;
        } else {
          uint16_t id_2098 { uint16_t((*p_0).index()) };
          uint16_t id_2099 { 2 };
          bool id_2100 { bool(id_2098 == id_2099) };
          Void id_2101 { ((void)(assert(id_2100)), ::dessser::Void()) };
          (void)id_2101;
          ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2102 { std::get<2 /* ListenFor */>((*p_0)) };
          std::string id_2103 { id_2102.net_addr };
          uint32_t id_2104 { (uint32_t)id_2103.size() };
          Vec<1, uint32_t> id_2105 {  id_2104  };
          Pointer let_res_2106;
          {
            Vec<1, uint32_t> leb128_sz_867 { id_2105 };
            Vec<1, Pointer> id_2107 {  ssum_dst_866  };
            Pointer let_res_2108;
            {
              Vec<1, Pointer> leb128_ptr_868 { id_2107 };
              bool while_flag_2109 { true };
              do {
                uint8_t id_2110 { 0 };
                uint8_t id_2111 { 0 };
                Pointer id_2112 { leb128_ptr_868[id_2111] };
                uint32_t id_2113 { 128U };
                uint8_t id_2114 { 0 };
                uint32_t id_2115 { leb128_sz_867[id_2114] };
                bool id_2116 { bool(id_2113 > id_2115) };
                uint8_t choose_res_2117;
                if (id_2116) {
                  uint8_t id_2118 { 0 };
                  uint32_t id_2119 { leb128_sz_867[id_2118] };
                  uint8_t id_2120 { uint8_t(id_2119) };
                  choose_res_2117 = id_2120;
                } else {
                  uint8_t id_2121 { 0 };
                  uint32_t id_2122 { leb128_sz_867[id_2121] };
                  uint8_t id_2123 { uint8_t(id_2122) };
                  uint8_t id_2124 { 128 };
                  uint8_t id_2125 { uint8_t(id_2123 | id_2124) };
                  choose_res_2117 = id_2125;
                }
                Pointer id_2126 { id_2112.writeU8(choose_res_2117) };
                Void id_2127 { ((void)(leb128_ptr_868[id_2110] = id_2126), ::dessser::Void()) };
                (void)id_2127;
                uint8_t id_2128 { 0 };
                uint8_t id_2129 { 0 };
                uint32_t id_2130 { leb128_sz_867[id_2129] };
                uint8_t id_2131 { 7 };
                uint32_t id_2132 { uint32_t(id_2130 >> id_2131) };
                Void id_2133 { ((void)(leb128_sz_867[id_2128] = id_2132), ::dessser::Void()) };
                (void)id_2133;
                uint8_t id_2134 { 0 };
                uint32_t id_2135 { leb128_sz_867[id_2134] };
                uint32_t id_2136 { 0U };
                bool id_2137 { bool(id_2135 > id_2136) };
                while_flag_2109 = id_2137;
                if (while_flag_2109) {
                  (void)::dessser::Void();
                }
              } while (while_flag_2109);
              (void)::dessser::Void();
              uint8_t id_2138 { 0 };
              Pointer id_2139 { leb128_ptr_868[id_2138] };
              let_res_2108 = id_2139;
            }
            let_res_2106 = let_res_2108;
          }
          ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2140 { std::get<2 /* ListenFor */>((*p_0)) };
          std::string id_2141 { id_2140.net_addr };
          Bytes id_2142 { id_2141 };
          Pointer id_2143 { let_res_2106.writeBytes(id_2142) };
          Pointer let_res_2144;
          {
            Pointer srec_dst_869 { id_2143 };
            ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2145 { std::get<2 /* ListenFor */>((*p_0)) };
            uint16_t id_2146 { id_2145.port };
            Pointer id_2147 { srec_dst_869.writeU16Le(id_2146) };
            let_res_2144 = id_2147;
          }
          Pointer let_res_2148;
          {
            Pointer srec_dst_870 { let_res_2144 };
            auto fun2149 { dessser::gen::raql_ip_protocol::to_row_binary };
            ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2150 { std::get<2 /* ListenFor */>((*p_0)) };
            dessser::gen::raql_ip_protocol::t_ext id_2151 { id_2150.ip_proto };
            Pointer id_2152 { fun2149(id_2151, srec_dst_870) };
            let_res_2148 = id_2152;
          }
          Pointer let_res_2153;
          {
            Pointer srec_dst_871 { let_res_2148 };
            auto fun2154 { dessser::gen::raql_net_protocol::to_row_binary };
            ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2155 { std::get<2 /* ListenFor */>((*p_0)) };
            dessser::gen::raql_net_protocol::t_ext id_2156 { id_2155.proto };
            Pointer id_2157 { fun2154(id_2156, srec_dst_871) };
            let_res_2153 = id_2157;
          }
          Pointer let_res_2158;
          {
            Pointer srec_dst_872 { let_res_2153 };
            ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2159 { std::get<2 /* ListenFor */>((*p_0)) };
            Lst<dessser::gen::field_name::t_ext> id_2160 { id_2159.factors };
            uint32_t id_2161 { id_2160.size() };
            Vec<1, uint32_t> id_2162 {  id_2161  };
            Pointer let_res_2163;
            {
              Vec<1, uint32_t> leb128_sz_873 { id_2162 };
              Vec<1, Pointer> id_2164 {  srec_dst_872  };
              Pointer let_res_2165;
              {
                Vec<1, Pointer> leb128_ptr_874 { id_2164 };
                bool while_flag_2166 { true };
                do {
                  uint8_t id_2167 { 0 };
                  uint8_t id_2168 { 0 };
                  Pointer id_2169 { leb128_ptr_874[id_2168] };
                  uint32_t id_2170 { 128U };
                  uint8_t id_2171 { 0 };
                  uint32_t id_2172 { leb128_sz_873[id_2171] };
                  bool id_2173 { bool(id_2170 > id_2172) };
                  uint8_t choose_res_2174;
                  if (id_2173) {
                    uint8_t id_2175 { 0 };
                    uint32_t id_2176 { leb128_sz_873[id_2175] };
                    uint8_t id_2177 { uint8_t(id_2176) };
                    choose_res_2174 = id_2177;
                  } else {
                    uint8_t id_2178 { 0 };
                    uint32_t id_2179 { leb128_sz_873[id_2178] };
                    uint8_t id_2180 { uint8_t(id_2179) };
                    uint8_t id_2181 { 128 };
                    uint8_t id_2182 { uint8_t(id_2180 | id_2181) };
                    choose_res_2174 = id_2182;
                  }
                  Pointer id_2183 { id_2169.writeU8(choose_res_2174) };
                  Void id_2184 { ((void)(leb128_ptr_874[id_2167] = id_2183), ::dessser::Void()) };
                  (void)id_2184;
                  uint8_t id_2185 { 0 };
                  uint8_t id_2186 { 0 };
                  uint32_t id_2187 { leb128_sz_873[id_2186] };
                  uint8_t id_2188 { 7 };
                  uint32_t id_2189 { uint32_t(id_2187 >> id_2188) };
                  Void id_2190 { ((void)(leb128_sz_873[id_2185] = id_2189), ::dessser::Void()) };
                  (void)id_2190;
                  uint8_t id_2191 { 0 };
                  uint32_t id_2192 { leb128_sz_873[id_2191] };
                  uint32_t id_2193 { 0U };
                  bool id_2194 { bool(id_2192 > id_2193) };
                  while_flag_2166 = id_2194;
                  if (while_flag_2166) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_2166);
                (void)::dessser::Void();
                uint8_t id_2195 { 0 };
                Pointer id_2196 { leb128_ptr_874[id_2195] };
                let_res_2165 = id_2196;
              }
              let_res_2163 = let_res_2165;
            }
            Vec<1, Pointer> id_2197 {  let_res_2163  };
            Pointer let_res_2198;
            {
              Vec<1, Pointer> dst_ref_875 { id_2197 };
              int32_t id_2199 { 0L };
              Vec<1, int32_t> id_2200 {  id_2199  };
              Pointer let_res_2201;
              {
                Vec<1, int32_t> n_ref_876 { id_2200 };
                ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2202 { std::get<2 /* ListenFor */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2203 { id_2202.factors };
                for (dessser::gen::field_name::t_ext &x_877 : id_2203) {
                  uint8_t id_2204 { 0 };
                  auto fun2205 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_2206 { 0 };
                  Pointer id_2207 { dst_ref_875[id_2206] };
                  Pointer id_2208 { fun2205(x_877, id_2207) };
                  Void id_2209 { ((void)(dst_ref_875[id_2204] = id_2208), ::dessser::Void()) };
                  (void)id_2209;
                  uint8_t id_2210 { 0 };
                  int32_t id_2211 { 1L };
                  uint8_t id_2212 { 0 };
                  int32_t id_2213 { n_ref_876[id_2212] };
                  int32_t id_2214 { int32_t(id_2211 + id_2213) };
                  Void id_2215 { ((void)(n_ref_876[id_2210] = id_2214), ::dessser::Void()) };
                  (void)id_2215;
                  (void)id_2215;
                }
                (void)::dessser::Void();
                uint8_t id_2216 { 0 };
                Pointer id_2217 { dst_ref_875[id_2216] };
                let_res_2201 = id_2217;
              }
              let_res_2198 = let_res_2201;
            }
            let_res_2158 = let_res_2198;
          }
          choose_res_2016 = let_res_2158;
        }
        choose_res_1499 = choose_res_2016;
      }
      let_res_1495 = choose_res_1499;
    }
    return let_res_1495;
  }
   };
  return fun1492;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t>  &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_706"
          (let "sz_702"
            (if (eq (u16 0) (label-of (get-item 0 (get-alt "NamedOperation" (param 0))))) 
              (size 4)
              (if (eq (u16 1) (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))))
                (add (size 4)
                  (add
                    (let "n_ref_700" (make-vec (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0))))))
                      (let "lebsz_ref_701" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_700")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_701")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_701") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_701")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_701")))))) 
                    (size-of-u32 (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0)))))))) 
                (seq (assert (eq (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))) (u16 2))) (size 4))))
            (if (is-null (get-item 1 (get-alt "NamedOperation" (param 0)))) 
              (add (identifier "sz_702") (size 1))
              (add
                (add (identifier "sz_702")
                  (add
                    (let "n_ref_704" (make-vec (string-length (force (get-item 1 (get-alt "NamedOperation" (param 0))))))
                      (let "lebsz_ref_705" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_704")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_705")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_705") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_705")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_705")))))) 
                    (size-of-u32 (string-length (force (get-item 1 (get-alt "NamedOperation" (param 0)))))))) 
                (size 1)))) (add (identifier "sz_706") (apply (ext-identifier function_name sersize-of-row-binary) (get-item 2 (get-alt "NamedOperation" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "sersize-of-row-binary") (get-alt "SubQuery" (param 0)))))))
 */
static std::function<Size(::dessser::gen::raql_operation::data_source &)> data_source_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_operation::data_source &)> fun2218 { [&](::dessser::gen::raql_operation::data_source p_0) {
    uint16_t id_2219 { 0 };
    uint16_t id_2220 { uint16_t(p_0.index()) };
    bool id_2221 { bool(id_2219 == id_2220) };
    Size choose_res_2222;
    if (id_2221) {
      uint16_t id_2223 { 0 };
      ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_2224 { std::get<0 /* NamedOperation */>(p_0) };
      ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_2225 { std::get<0>(id_2224) };
      uint16_t id_2226 { uint16_t(id_2225.index()) };
      bool id_2227 { bool(id_2223 == id_2226) };
      Size choose_res_2228;
      if (id_2227) {
        Size id_2229 { 4UL };
        choose_res_2228 = id_2229;
      } else {
        uint16_t id_2230 { 1 };
        ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_2231 { std::get<0 /* NamedOperation */>(p_0) };
        ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_2232 { std::get<0>(id_2231) };
        uint16_t id_2233 { uint16_t(id_2232.index()) };
        bool id_2234 { bool(id_2230 == id_2233) };
        Size choose_res_2235;
        if (id_2234) {
          Size id_2236 { 4UL };
          ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_2237 { std::get<0 /* NamedOperation */>(p_0) };
          ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_2238 { std::get<0>(id_2237) };
          std::string id_2239 { std::get<1 /* TheseSites */>(id_2238) };
          uint32_t id_2240 { (uint32_t)id_2239.size() };
          Vec<1, uint32_t> id_2241 {  id_2240  };
          Size let_res_2242;
          {
            Vec<1, uint32_t> n_ref_700 { id_2241 };
            uint32_t id_2243 { 1U };
            Vec<1, uint32_t> id_2244 {  id_2243  };
            Size let_res_2245;
            {
              Vec<1, uint32_t> lebsz_ref_701 { id_2244 };
              bool while_flag_2246 { true };
              do {
                uint8_t id_2247 { 0 };
                uint32_t id_2248 { n_ref_700[id_2247] };
                uint8_t id_2249 { 0 };
                uint32_t id_2250 { lebsz_ref_701[id_2249] };
                uint8_t id_2251 { 7 };
                uint32_t id_2252 { uint32_t(id_2250 << id_2251) };
                bool id_2253 { bool(id_2248 >= id_2252) };
                while_flag_2246 = id_2253;
                if (while_flag_2246) {
                  uint8_t id_2254 { 0 };
                  uint8_t id_2255 { 0 };
                  uint32_t id_2256 { lebsz_ref_701[id_2255] };
                  uint32_t id_2257 { 1U };
                  uint32_t id_2258 { uint32_t(id_2256 + id_2257) };
                  Void id_2259 { ((void)(lebsz_ref_701[id_2254] = id_2258), ::dessser::Void()) };
                  (void)id_2259;
                }
              } while (while_flag_2246);
              (void)::dessser::Void();
              uint8_t id_2260 { 0 };
              uint32_t id_2261 { lebsz_ref_701[id_2260] };
              Size id_2262 { Size(id_2261) };
              let_res_2245 = id_2262;
            }
            let_res_2242 = let_res_2245;
          }
          ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_2263 { std::get<0 /* NamedOperation */>(p_0) };
          ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_2264 { std::get<0>(id_2263) };
          std::string id_2265 { std::get<1 /* TheseSites */>(id_2264) };
          uint32_t id_2266 { (uint32_t)id_2265.size() };
          Size id_2267 { Size(id_2266) };
          Size id_2268 { Size(let_res_2242 + id_2267) };
          Size id_2269 { Size(id_2236 + id_2268) };
          choose_res_2235 = id_2269;
        } else {
          ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_2270 { std::get<0 /* NamedOperation */>(p_0) };
          ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_2271 { std::get<0>(id_2270) };
          uint16_t id_2272 { uint16_t(id_2271.index()) };
          uint16_t id_2273 { 2 };
          bool id_2274 { bool(id_2272 == id_2273) };
          Void id_2275 { ((void)(assert(id_2274)), ::dessser::Void()) };
          (void)id_2275;
          Size id_2276 { 4UL };
          choose_res_2235 = id_2276;
        }
        choose_res_2228 = choose_res_2235;
      }
      Size let_res_2277;
      {
        Size sz_702 { choose_res_2228 };
        ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_2278 { std::get<0 /* NamedOperation */>(p_0) };
        std::optional<std::string> id_2279 { std::get<1>(id_2278) };
        bool id_2280 { !(id_2279.has_value ()) };
        Size choose_res_2281;
        if (id_2280) {
          Size id_2282 { 1UL };
          Size id_2283 { Size(sz_702 + id_2282) };
          choose_res_2281 = id_2283;
        } else {
          ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_2284 { std::get<0 /* NamedOperation */>(p_0) };
          std::optional<std::string> id_2285 { std::get<1>(id_2284) };
          std::string id_2286 { id_2285.value() };
          uint32_t id_2287 { (uint32_t)id_2286.size() };
          Vec<1, uint32_t> id_2288 {  id_2287  };
          Size let_res_2289;
          {
            Vec<1, uint32_t> n_ref_704 { id_2288 };
            uint32_t id_2290 { 1U };
            Vec<1, uint32_t> id_2291 {  id_2290  };
            Size let_res_2292;
            {
              Vec<1, uint32_t> lebsz_ref_705 { id_2291 };
              bool while_flag_2293 { true };
              do {
                uint8_t id_2294 { 0 };
                uint32_t id_2295 { n_ref_704[id_2294] };
                uint8_t id_2296 { 0 };
                uint32_t id_2297 { lebsz_ref_705[id_2296] };
                uint8_t id_2298 { 7 };
                uint32_t id_2299 { uint32_t(id_2297 << id_2298) };
                bool id_2300 { bool(id_2295 >= id_2299) };
                while_flag_2293 = id_2300;
                if (while_flag_2293) {
                  uint8_t id_2301 { 0 };
                  uint8_t id_2302 { 0 };
                  uint32_t id_2303 { lebsz_ref_705[id_2302] };
                  uint32_t id_2304 { 1U };
                  uint32_t id_2305 { uint32_t(id_2303 + id_2304) };
                  Void id_2306 { ((void)(lebsz_ref_705[id_2301] = id_2305), ::dessser::Void()) };
                  (void)id_2306;
                }
              } while (while_flag_2293);
              (void)::dessser::Void();
              uint8_t id_2307 { 0 };
              uint32_t id_2308 { lebsz_ref_705[id_2307] };
              Size id_2309 { Size(id_2308) };
              let_res_2292 = id_2309;
            }
            let_res_2289 = let_res_2292;
          }
          ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_2310 { std::get<0 /* NamedOperation */>(p_0) };
          std::optional<std::string> id_2311 { std::get<1>(id_2310) };
          std::string id_2312 { id_2311.value() };
          uint32_t id_2313 { (uint32_t)id_2312.size() };
          Size id_2314 { Size(id_2313) };
          Size id_2315 { Size(let_res_2289 + id_2314) };
          Size id_2316 { Size(sz_702 + id_2315) };
          Size id_2317 { 1UL };
          Size id_2318 { Size(id_2316 + id_2317) };
          choose_res_2281 = id_2318;
        }
        let_res_2277 = choose_res_2281;
      }
      Size let_res_2319;
      {
        Size sz_706 { let_res_2277 };
        auto fun2320 { dessser::gen::function_name::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_2321 { std::get<0 /* NamedOperation */>(p_0) };
        dessser::gen::function_name::t_ext id_2322 { std::get<2>(id_2321) };
        Size id_2323 { fun2320(id_2322) };
        Size id_2324 { Size(sz_706 + id_2323) };
        let_res_2319 = id_2324;
      }
      choose_res_2222 = let_res_2319;
    } else {
      uint16_t id_2325 { uint16_t(p_0.index()) };
      uint16_t id_2326 { 1 };
      bool id_2327 { bool(id_2325 == id_2326) };
      Void id_2328 { ((void)(assert(id_2327)), ::dessser::Void()) };
      (void)id_2328;
      Size id_2329 { 2UL };
      std::shared_ptr<::dessser::gen::raql_operation::t>  id_2330 { std::get<1 /* SubQuery */>(p_0) };
      Size id_2331 { sersize_of_row_binary(id_2330) };
      Size id_2332 { Size(id_2329 + id_2331) };
      choose_res_2222 = id_2332;
    }
    return choose_res_2222;
  }
   };
  return fun2218;
}
std::function<Size(::dessser::gen::raql_operation::data_source &)> data_source_sersize_of_row_binary(data_source_sersize_of_row_binary_init());

/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; ip_proto: $raql_ip_protocol; proto: $raql_net_protocol; factors: $field_name[[]]}]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_809"
          (let "sz_808"
            (let "sz_803"
              (let "sz_802"
                (add
                  (let "sz_800"
                    (let "sz_795"
                      (let "sz_790"
                        (let "sz_789"
                          (let "sz_788"
                            (let "sz_780"
                              (let "sz_775"
                                (let "sz_ref_773"
                                  (make-vec
                                    (add (size 2)
                                      (let "n_ref_771" (make-vec (cardinality (get-field "fields" (get-alt "Aggregate" (param 0)))))
                                        (let "lebsz_ref_772" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_771")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_772")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_772") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_772")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_772"))))))))
                                  (seq
                                    (let "repeat_n_774" (make-vec (i32 0))
                                      (while (gt (to-i32 (cardinality (get-field "fields" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_774")))
                                        (seq
                                          (set-vec (u8 0) (identifier "sz_ref_773")
                                            (add (unsafe-nth (u8 0) (identifier "sz_ref_773"))
                                              (apply (ext-identifier raql_select_field sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_774")) (get-field "fields" (get-alt "Aggregate" (param 0)))))))
                                          (set-vec (u8 0) (identifier "repeat_n_774") (add (unsafe-nth (u8 0) (identifier "repeat_n_774")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "sz_ref_773"))))
                                (if (is-null (get-field "and_all_others" (get-alt "Aggregate" (param 0)))) 
                                  (add (identifier "sz_775") (size 1))
                                  (add
                                    (let "sz_ref_778"
                                      (make-vec
                                        (add (identifier "sz_775")
                                          (let "n_ref_776" (make-vec (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))
                                            (let "lebsz_ref_777" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_776")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_777")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_777") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_777")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_777"))))))))
                                      (seq
                                        (let "repeat_n_779" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_779")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_778")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_778"))
                                                  (apply (ext-identifier field_name sersize-of-row-binary)
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_779")) (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))))
                                              (set-vec (u8 0) (identifier "repeat_n_779") (add (unsafe-nth (u8 0) (identifier "repeat_n_779")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_778")))) 
                                    (size 1))))
                              (if (is-null (get-field "sort" (get-alt "Aggregate" (param 0)))) 
                                (add (identifier "sz_780") (size 1))
                                (add
                                  (let "sz_783"
                                    (if (is-null (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) 
                                      (add (add (identifier "sz_780") (size 4)) (size 1))
                                      (add (add (add (identifier "sz_780") (size 4)) (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0))))))))
                                        (size 1)))
                                    (let "sz_ref_786"
                                      (make-vec
                                        (add (identifier "sz_783")
                                          (let "n_ref_784" (make-vec (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                            (let "lebsz_ref_785" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_784")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_785")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_785") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_785")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_785"))))))))
                                      (seq
                                        (let "repeat_n_787" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0))))))) (unsafe-nth (u8 0) (identifier "repeat_n_787")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_786")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_786"))
                                                  (apply (ext-identifier raql_expr sersize-of-row-binary)
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_787")) (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))))
                                              (set-vec (u8 0) (identifier "repeat_n_787") (add (unsafe-nth (u8 0) (identifier "repeat_n_787")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_786"))))) 
                                  (size 1)))) (add (identifier "sz_788") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "where" (get-alt "Aggregate" (param 0))))))
                          (if (is-null (get-field "event_time" (get-alt "Aggregate" (param 0)))) 
                            (add (identifier "sz_789") (size 1))
                            (add (add (identifier "sz_789") (apply (ext-identifier event_time sersize-of-row-binary) (force (get-field "event_time" (get-alt "Aggregate" (param 0)))))) (size 1))))
                        (let "sz_ref_793"
                          (make-vec
                            (add (identifier "sz_790")
                              (let "n_ref_791" (make-vec (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0)))))
                                (let "lebsz_ref_792" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_791")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_792")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_792") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_792")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_792"))))))))
                          (seq
                            (let "repeat_n_794" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_794")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_793")
                                    (add (unsafe-nth (u8 0) (identifier "sz_ref_793"))
                                      (apply (ext-identifier raql_expr sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_794")) (get-field "notifications" (get-alt "Aggregate" (param 0)))))))
                                  (set-vec (u8 0) (identifier "repeat_n_794") (add (unsafe-nth (u8 0) (identifier "repeat_n_794")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_793")))))
                      (let "sz_ref_798"
                        (make-vec
                          (add (identifier "sz_795")
                            (let "n_ref_796" (make-vec (cardinality (get-field "key" (get-alt "Aggregate" (param 0)))))
                              (let "lebsz_ref_797" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_796")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_797")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_797") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_797")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_797"))))))))
                        (seq
                          (let "repeat_n_799" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-field "key" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_799")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_798")
                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_798"))
                                    (apply (ext-identifier raql_expr sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_799")) (get-field "key" (get-alt "Aggregate" (param 0)))))))
                                (set-vec (u8 0) (identifier "repeat_n_799") (add (unsafe-nth (u8 0) (identifier "repeat_n_799")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_798"))))) 
                    (add (identifier "sz_800") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "commit_cond" (get-alt "Aggregate" (param 0)))))) 
                  (size 1)) (add (identifier "sz_802") (apply (ext-identifier raql_flush_method sersize-of-row-binary) (get-field "flush_how" (get-alt "Aggregate" (param 0))))))
              (let "sz_ref_806"
                (make-vec
                  (add (identifier "sz_803")
                    (let "n_ref_804" (make-vec (cardinality (get-field "from" (get-alt "Aggregate" (param 0)))))
                      (let "lebsz_ref_805" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_804")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_805")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_805") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_805")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_805"))))))))
                (seq
                  (let "repeat_n_807" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "from" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_807")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_806")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_806"))
                            (apply (identifier "data_source-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_807")) (get-field "from" (get-alt "Aggregate" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_807") (add (unsafe-nth (u8 0) (identifier "repeat_n_807")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_806")))))
            (if (is-null (get-field "every" (get-alt "Aggregate" (param 0)))) 
              (add (identifier "sz_808") (size 1)) (add (add (identifier "sz_808") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "every" (get-alt "Aggregate" (param 0)))))) (size 1))))
          (let "sz_ref_812"
            (make-vec
              (add (identifier "sz_809")
                (let "n_ref_810" (make-vec (cardinality (get-field "factors" (get-alt "Aggregate" (param 0)))))
                  (let "lebsz_ref_811" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_810")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_811")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_811") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_811")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_811"))))))))
            (seq
              (let "repeat_n_813" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_813")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_812")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_812"))
                        (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_813")) (get-field "factors" (get-alt "Aggregate" (param 0)))))))
                    (set-vec (u8 0) (identifier "repeat_n_813") (add (unsafe-nth (u8 0) (identifier "repeat_n_813")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_812")))))
        (if (eq (u16 1) (label-of (param 0)))
          (let "sz_765"
            (let "sz_764"
              (let "sz_763" (add (size 2) (apply (identifier "external_source-sersize-of-row-binary") (get-field "source" (get-alt "ReadExternal" (param 0)))))
                (add (identifier "sz_763") (apply (identifier "external_format-sersize-of-row-binary") (get-field "format" (get-alt "ReadExternal" (param 0))))))
              (if (is-null (get-field "event_time" (get-alt "ReadExternal" (param 0)))) 
                (add (identifier "sz_764") (size 1)) (add (add (identifier "sz_764") (apply (ext-identifier event_time sersize-of-row-binary) (force (get-field "event_time" (get-alt "ReadExternal" (param 0)))))) (size 1))))
            (let "sz_ref_768"
              (make-vec
                (add (identifier "sz_765")
                  (let "n_ref_766" (make-vec (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0)))))
                    (let "lebsz_ref_767" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_766")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_767")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_767") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_767")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_767"))))))))
              (seq
                (let "repeat_n_769" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_769")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_768")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_768"))
                          (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_769")) (get-field "factors" (get-alt "ReadExternal" (param 0)))))))
                      (set-vec (u8 0) (identifier "repeat_n_769") (add (unsafe-nth (u8 0) (identifier "repeat_n_769")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_768")))))
          (seq (assert (eq (label-of (param 0)) (u16 2)))
            (let "sz_757"
              (let "sz_756"
                (let "sz_755"
                  (add
                    (add (size 2)
                      (add
                        (let "n_ref_752" (make-vec (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0)))))
                          (let "lebsz_ref_753" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_752")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_753")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_753") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_753")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_753")))))) 
                        (size-of-u32 (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0))))))) 
                    (size 2)) (add (identifier "sz_755") (apply (ext-identifier raql_ip_protocol sersize-of-row-binary) (get-field "ip_proto" (get-alt "ListenFor" (param 0))))))
                (add (identifier "sz_756") (apply (ext-identifier raql_net_protocol sersize-of-row-binary) (get-field "proto" (get-alt "ListenFor" (param 0))))))
              (let "sz_ref_760"
                (make-vec
                  (add (identifier "sz_757")
                    (let "n_ref_758" (make-vec (cardinality (get-field "factors" (get-alt "ListenFor" (param 0)))))
                      (let "lebsz_ref_759" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_758")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_759")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_759") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_759")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_759"))))))))
                (seq
                  (let "repeat_n_761" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "ListenFor" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_761")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_760")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_760"))
                            (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_761")) (get-field "factors" (get-alt "ListenFor" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_761") (add (unsafe-nth (u8 0) (identifier "repeat_n_761")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_760")))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::t>  &)> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::t>  &)> fun2333 { [&](std::shared_ptr<::dessser::gen::raql_operation::t>  p_0) {
    uint16_t id_2334 { 0 };
    uint16_t id_2335 { uint16_t((*p_0).index()) };
    bool id_2336 { bool(id_2334 == id_2335) };
    Size choose_res_2337;
    if (id_2336) {
      Size id_2338 { 2UL };
      ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2339 { std::get<0 /* Aggregate */>((*p_0)) };
      Lst<dessser::gen::raql_select_field::t_ext> id_2340 { id_2339.Aggregate_fields };
      uint32_t id_2341 { id_2340.size() };
      Vec<1, uint32_t> id_2342 {  id_2341  };
      Size let_res_2343;
      {
        Vec<1, uint32_t> n_ref_771 { id_2342 };
        uint32_t id_2344 { 1U };
        Vec<1, uint32_t> id_2345 {  id_2344  };
        Size let_res_2346;
        {
          Vec<1, uint32_t> lebsz_ref_772 { id_2345 };
          bool while_flag_2347 { true };
          do {
            uint8_t id_2348 { 0 };
            uint32_t id_2349 { n_ref_771[id_2348] };
            uint8_t id_2350 { 0 };
            uint32_t id_2351 { lebsz_ref_772[id_2350] };
            uint8_t id_2352 { 7 };
            uint32_t id_2353 { uint32_t(id_2351 << id_2352) };
            bool id_2354 { bool(id_2349 >= id_2353) };
            while_flag_2347 = id_2354;
            if (while_flag_2347) {
              uint8_t id_2355 { 0 };
              uint8_t id_2356 { 0 };
              uint32_t id_2357 { lebsz_ref_772[id_2356] };
              uint32_t id_2358 { 1U };
              uint32_t id_2359 { uint32_t(id_2357 + id_2358) };
              Void id_2360 { ((void)(lebsz_ref_772[id_2355] = id_2359), ::dessser::Void()) };
              (void)id_2360;
            }
          } while (while_flag_2347);
          (void)::dessser::Void();
          uint8_t id_2361 { 0 };
          uint32_t id_2362 { lebsz_ref_772[id_2361] };
          Size id_2363 { Size(id_2362) };
          let_res_2346 = id_2363;
        }
        let_res_2343 = let_res_2346;
      }
      Size id_2364 { Size(id_2338 + let_res_2343) };
      Vec<1, Size> id_2365 {  id_2364  };
      Size let_res_2366;
      {
        Vec<1, Size> sz_ref_773 { id_2365 };
        int32_t id_2367 { 0L };
        Vec<1, int32_t> id_2368 {  id_2367  };
        {
          Vec<1, int32_t> repeat_n_774 { id_2368 };
          bool while_flag_2369 { true };
          do {
            ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2370 { std::get<0 /* Aggregate */>((*p_0)) };
            Lst<dessser::gen::raql_select_field::t_ext> id_2371 { id_2370.Aggregate_fields };
            uint32_t id_2372 { id_2371.size() };
            int32_t id_2373 { int32_t(id_2372) };
            uint8_t id_2374 { 0 };
            int32_t id_2375 { repeat_n_774[id_2374] };
            bool id_2376 { bool(id_2373 > id_2375) };
            while_flag_2369 = id_2376;
            if (while_flag_2369) {
              uint8_t id_2377 { 0 };
              uint8_t id_2378 { 0 };
              Size id_2379 { sz_ref_773[id_2378] };
              auto fun2380 { dessser::gen::raql_select_field::sersize_of_row_binary };
              uint8_t id_2381 { 0 };
              int32_t id_2382 { repeat_n_774[id_2381] };
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2383 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_select_field::t_ext> id_2384 { id_2383.Aggregate_fields };
              dessser::gen::raql_select_field::t_ext id_2385 { id_2384[id_2382] };
              Size id_2386 { fun2380(id_2385) };
              Size id_2387 { Size(id_2379 + id_2386) };
              Void id_2388 { ((void)(sz_ref_773[id_2377] = id_2387), ::dessser::Void()) };
              (void)id_2388;
              uint8_t id_2389 { 0 };
              uint8_t id_2390 { 0 };
              int32_t id_2391 { repeat_n_774[id_2390] };
              int32_t id_2392 { 1L };
              int32_t id_2393 { int32_t(id_2391 + id_2392) };
              Void id_2394 { ((void)(repeat_n_774[id_2389] = id_2393), ::dessser::Void()) };
              (void)id_2394;
              (void)id_2394;
            }
          } while (while_flag_2369);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_2395 { 0 };
        Size id_2396 { sz_ref_773[id_2395] };
        let_res_2366 = id_2396;
      }
      Size let_res_2397;
      {
        Size sz_775 { let_res_2366 };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2398 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<Lst<dessser::gen::field_name::t_ext>> id_2399 { id_2398.and_all_others };
        bool id_2400 { !(id_2399.has_value ()) };
        Size choose_res_2401;
        if (id_2400) {
          Size id_2402 { 1UL };
          Size id_2403 { Size(sz_775 + id_2402) };
          choose_res_2401 = id_2403;
        } else {
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2404 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<Lst<dessser::gen::field_name::t_ext>> id_2405 { id_2404.and_all_others };
          Lst<dessser::gen::field_name::t_ext> id_2406 { id_2405.value() };
          uint32_t id_2407 { id_2406.size() };
          Vec<1, uint32_t> id_2408 {  id_2407  };
          Size let_res_2409;
          {
            Vec<1, uint32_t> n_ref_776 { id_2408 };
            uint32_t id_2410 { 1U };
            Vec<1, uint32_t> id_2411 {  id_2410  };
            Size let_res_2412;
            {
              Vec<1, uint32_t> lebsz_ref_777 { id_2411 };
              bool while_flag_2413 { true };
              do {
                uint8_t id_2414 { 0 };
                uint32_t id_2415 { n_ref_776[id_2414] };
                uint8_t id_2416 { 0 };
                uint32_t id_2417 { lebsz_ref_777[id_2416] };
                uint8_t id_2418 { 7 };
                uint32_t id_2419 { uint32_t(id_2417 << id_2418) };
                bool id_2420 { bool(id_2415 >= id_2419) };
                while_flag_2413 = id_2420;
                if (while_flag_2413) {
                  uint8_t id_2421 { 0 };
                  uint8_t id_2422 { 0 };
                  uint32_t id_2423 { lebsz_ref_777[id_2422] };
                  uint32_t id_2424 { 1U };
                  uint32_t id_2425 { uint32_t(id_2423 + id_2424) };
                  Void id_2426 { ((void)(lebsz_ref_777[id_2421] = id_2425), ::dessser::Void()) };
                  (void)id_2426;
                }
              } while (while_flag_2413);
              (void)::dessser::Void();
              uint8_t id_2427 { 0 };
              uint32_t id_2428 { lebsz_ref_777[id_2427] };
              Size id_2429 { Size(id_2428) };
              let_res_2412 = id_2429;
            }
            let_res_2409 = let_res_2412;
          }
          Size id_2430 { Size(sz_775 + let_res_2409) };
          Vec<1, Size> id_2431 {  id_2430  };
          Size let_res_2432;
          {
            Vec<1, Size> sz_ref_778 { id_2431 };
            int32_t id_2433 { 0L };
            Vec<1, int32_t> id_2434 {  id_2433  };
            {
              Vec<1, int32_t> repeat_n_779 { id_2434 };
              bool while_flag_2435 { true };
              do {
                ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2436 { std::get<0 /* Aggregate */>((*p_0)) };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_2437 { id_2436.and_all_others };
                Lst<dessser::gen::field_name::t_ext> id_2438 { id_2437.value() };
                uint32_t id_2439 { id_2438.size() };
                int32_t id_2440 { int32_t(id_2439) };
                uint8_t id_2441 { 0 };
                int32_t id_2442 { repeat_n_779[id_2441] };
                bool id_2443 { bool(id_2440 > id_2442) };
                while_flag_2435 = id_2443;
                if (while_flag_2435) {
                  uint8_t id_2444 { 0 };
                  uint8_t id_2445 { 0 };
                  Size id_2446 { sz_ref_778[id_2445] };
                  auto fun2447 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_2448 { 0 };
                  int32_t id_2449 { repeat_n_779[id_2448] };
                  ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2450 { std::get<0 /* Aggregate */>((*p_0)) };
                  std::optional<Lst<dessser::gen::field_name::t_ext>> id_2451 { id_2450.and_all_others };
                  Lst<dessser::gen::field_name::t_ext> id_2452 { id_2451.value() };
                  dessser::gen::field_name::t_ext id_2453 { id_2452[id_2449] };
                  Size id_2454 { fun2447(id_2453) };
                  Size id_2455 { Size(id_2446 + id_2454) };
                  Void id_2456 { ((void)(sz_ref_778[id_2444] = id_2455), ::dessser::Void()) };
                  (void)id_2456;
                  uint8_t id_2457 { 0 };
                  uint8_t id_2458 { 0 };
                  int32_t id_2459 { repeat_n_779[id_2458] };
                  int32_t id_2460 { 1L };
                  int32_t id_2461 { int32_t(id_2459 + id_2460) };
                  Void id_2462 { ((void)(repeat_n_779[id_2457] = id_2461), ::dessser::Void()) };
                  (void)id_2462;
                  (void)id_2462;
                }
              } while (while_flag_2435);
              (void)::dessser::Void();
            }
            (void)::dessser::Void();
            uint8_t id_2463 { 0 };
            Size id_2464 { sz_ref_778[id_2463] };
            let_res_2432 = id_2464;
          }
          Size id_2465 { 1UL };
          Size id_2466 { Size(let_res_2432 + id_2465) };
          choose_res_2401 = id_2466;
        }
        let_res_2397 = choose_res_2401;
      }
      Size let_res_2467;
      {
        Size sz_780 { let_res_2397 };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2468 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2469 { id_2468.sort };
        bool id_2470 { !(id_2469.has_value ()) };
        Size choose_res_2471;
        if (id_2470) {
          Size id_2472 { 1UL };
          Size id_2473 { Size(sz_780 + id_2472) };
          choose_res_2471 = id_2473;
        } else {
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2474 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2475 { id_2474.sort };
          ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2476 { id_2475.value() };
          std::optional<dessser::gen::raql_expr::t_ext> id_2477 { std::get<1>(id_2476) };
          bool id_2478 { !(id_2477.has_value ()) };
          Size choose_res_2479;
          if (id_2478) {
            Size id_2480 { 4UL };
            Size id_2481 { Size(sz_780 + id_2480) };
            Size id_2482 { 1UL };
            Size id_2483 { Size(id_2481 + id_2482) };
            choose_res_2479 = id_2483;
          } else {
            Size id_2484 { 4UL };
            Size id_2485 { Size(sz_780 + id_2484) };
            auto fun2486 { dessser::gen::raql_expr::sersize_of_row_binary };
            ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2487 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2488 { id_2487.sort };
            ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2489 { id_2488.value() };
            std::optional<dessser::gen::raql_expr::t_ext> id_2490 { std::get<1>(id_2489) };
            dessser::gen::raql_expr::t_ext id_2491 { id_2490.value() };
            Size id_2492 { fun2486(id_2491) };
            Size id_2493 { Size(id_2485 + id_2492) };
            Size id_2494 { 1UL };
            Size id_2495 { Size(id_2493 + id_2494) };
            choose_res_2479 = id_2495;
          }
          Size let_res_2496;
          {
            Size sz_783 { choose_res_2479 };
            ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2497 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2498 { id_2497.sort };
            ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2499 { id_2498.value() };
            Lst<dessser::gen::raql_expr::t_ext> id_2500 { std::get<2>(id_2499) };
            uint32_t id_2501 { id_2500.size() };
            Vec<1, uint32_t> id_2502 {  id_2501  };
            Size let_res_2503;
            {
              Vec<1, uint32_t> n_ref_784 { id_2502 };
              uint32_t id_2504 { 1U };
              Vec<1, uint32_t> id_2505 {  id_2504  };
              Size let_res_2506;
              {
                Vec<1, uint32_t> lebsz_ref_785 { id_2505 };
                bool while_flag_2507 { true };
                do {
                  uint8_t id_2508 { 0 };
                  uint32_t id_2509 { n_ref_784[id_2508] };
                  uint8_t id_2510 { 0 };
                  uint32_t id_2511 { lebsz_ref_785[id_2510] };
                  uint8_t id_2512 { 7 };
                  uint32_t id_2513 { uint32_t(id_2511 << id_2512) };
                  bool id_2514 { bool(id_2509 >= id_2513) };
                  while_flag_2507 = id_2514;
                  if (while_flag_2507) {
                    uint8_t id_2515 { 0 };
                    uint8_t id_2516 { 0 };
                    uint32_t id_2517 { lebsz_ref_785[id_2516] };
                    uint32_t id_2518 { 1U };
                    uint32_t id_2519 { uint32_t(id_2517 + id_2518) };
                    Void id_2520 { ((void)(lebsz_ref_785[id_2515] = id_2519), ::dessser::Void()) };
                    (void)id_2520;
                  }
                } while (while_flag_2507);
                (void)::dessser::Void();
                uint8_t id_2521 { 0 };
                uint32_t id_2522 { lebsz_ref_785[id_2521] };
                Size id_2523 { Size(id_2522) };
                let_res_2506 = id_2523;
              }
              let_res_2503 = let_res_2506;
            }
            Size id_2524 { Size(sz_783 + let_res_2503) };
            Vec<1, Size> id_2525 {  id_2524  };
            Size let_res_2526;
            {
              Vec<1, Size> sz_ref_786 { id_2525 };
              int32_t id_2527 { 0L };
              Vec<1, int32_t> id_2528 {  id_2527  };
              {
                Vec<1, int32_t> repeat_n_787 { id_2528 };
                bool while_flag_2529 { true };
                do {
                  ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2530 { std::get<0 /* Aggregate */>((*p_0)) };
                  std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2531 { id_2530.sort };
                  ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2532 { id_2531.value() };
                  Lst<dessser::gen::raql_expr::t_ext> id_2533 { std::get<2>(id_2532) };
                  uint32_t id_2534 { id_2533.size() };
                  int32_t id_2535 { int32_t(id_2534) };
                  uint8_t id_2536 { 0 };
                  int32_t id_2537 { repeat_n_787[id_2536] };
                  bool id_2538 { bool(id_2535 > id_2537) };
                  while_flag_2529 = id_2538;
                  if (while_flag_2529) {
                    uint8_t id_2539 { 0 };
                    uint8_t id_2540 { 0 };
                    Size id_2541 { sz_ref_786[id_2540] };
                    auto fun2542 { dessser::gen::raql_expr::sersize_of_row_binary };
                    uint8_t id_2543 { 0 };
                    int32_t id_2544 { repeat_n_787[id_2543] };
                    ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2545 { std::get<0 /* Aggregate */>((*p_0)) };
                    std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2546 { id_2545.sort };
                    ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2547 { id_2546.value() };
                    Lst<dessser::gen::raql_expr::t_ext> id_2548 { std::get<2>(id_2547) };
                    dessser::gen::raql_expr::t_ext id_2549 { id_2548[id_2544] };
                    Size id_2550 { fun2542(id_2549) };
                    Size id_2551 { Size(id_2541 + id_2550) };
                    Void id_2552 { ((void)(sz_ref_786[id_2539] = id_2551), ::dessser::Void()) };
                    (void)id_2552;
                    uint8_t id_2553 { 0 };
                    uint8_t id_2554 { 0 };
                    int32_t id_2555 { repeat_n_787[id_2554] };
                    int32_t id_2556 { 1L };
                    int32_t id_2557 { int32_t(id_2555 + id_2556) };
                    Void id_2558 { ((void)(repeat_n_787[id_2553] = id_2557), ::dessser::Void()) };
                    (void)id_2558;
                    (void)id_2558;
                  }
                } while (while_flag_2529);
                (void)::dessser::Void();
              }
              (void)::dessser::Void();
              uint8_t id_2559 { 0 };
              Size id_2560 { sz_ref_786[id_2559] };
              let_res_2526 = id_2560;
            }
            let_res_2496 = let_res_2526;
          }
          Size id_2561 { 1UL };
          Size id_2562 { Size(let_res_2496 + id_2561) };
          choose_res_2471 = id_2562;
        }
        let_res_2467 = choose_res_2471;
      }
      Size let_res_2563;
      {
        Size sz_788 { let_res_2467 };
        auto fun2564 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2565 { std::get<0 /* Aggregate */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_2566 { id_2565.where };
        Size id_2567 { fun2564(id_2566) };
        Size id_2568 { Size(sz_788 + id_2567) };
        let_res_2563 = id_2568;
      }
      Size let_res_2569;
      {
        Size sz_789 { let_res_2563 };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2570 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<dessser::gen::event_time::t_ext> id_2571 { id_2570.Aggregate_event_time };
        bool id_2572 { !(id_2571.has_value ()) };
        Size choose_res_2573;
        if (id_2572) {
          Size id_2574 { 1UL };
          Size id_2575 { Size(sz_789 + id_2574) };
          choose_res_2573 = id_2575;
        } else {
          auto fun2576 { dessser::gen::event_time::sersize_of_row_binary };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2577 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::event_time::t_ext> id_2578 { id_2577.Aggregate_event_time };
          dessser::gen::event_time::t_ext id_2579 { id_2578.value() };
          Size id_2580 { fun2576(id_2579) };
          Size id_2581 { Size(sz_789 + id_2580) };
          Size id_2582 { 1UL };
          Size id_2583 { Size(id_2581 + id_2582) };
          choose_res_2573 = id_2583;
        }
        let_res_2569 = choose_res_2573;
      }
      Size let_res_2584;
      {
        Size sz_790 { let_res_2569 };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2585 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::raql_expr::t_ext> id_2586 { id_2585.notifications };
        uint32_t id_2587 { id_2586.size() };
        Vec<1, uint32_t> id_2588 {  id_2587  };
        Size let_res_2589;
        {
          Vec<1, uint32_t> n_ref_791 { id_2588 };
          uint32_t id_2590 { 1U };
          Vec<1, uint32_t> id_2591 {  id_2590  };
          Size let_res_2592;
          {
            Vec<1, uint32_t> lebsz_ref_792 { id_2591 };
            bool while_flag_2593 { true };
            do {
              uint8_t id_2594 { 0 };
              uint32_t id_2595 { n_ref_791[id_2594] };
              uint8_t id_2596 { 0 };
              uint32_t id_2597 { lebsz_ref_792[id_2596] };
              uint8_t id_2598 { 7 };
              uint32_t id_2599 { uint32_t(id_2597 << id_2598) };
              bool id_2600 { bool(id_2595 >= id_2599) };
              while_flag_2593 = id_2600;
              if (while_flag_2593) {
                uint8_t id_2601 { 0 };
                uint8_t id_2602 { 0 };
                uint32_t id_2603 { lebsz_ref_792[id_2602] };
                uint32_t id_2604 { 1U };
                uint32_t id_2605 { uint32_t(id_2603 + id_2604) };
                Void id_2606 { ((void)(lebsz_ref_792[id_2601] = id_2605), ::dessser::Void()) };
                (void)id_2606;
              }
            } while (while_flag_2593);
            (void)::dessser::Void();
            uint8_t id_2607 { 0 };
            uint32_t id_2608 { lebsz_ref_792[id_2607] };
            Size id_2609 { Size(id_2608) };
            let_res_2592 = id_2609;
          }
          let_res_2589 = let_res_2592;
        }
        Size id_2610 { Size(sz_790 + let_res_2589) };
        Vec<1, Size> id_2611 {  id_2610  };
        Size let_res_2612;
        {
          Vec<1, Size> sz_ref_793 { id_2611 };
          int32_t id_2613 { 0L };
          Vec<1, int32_t> id_2614 {  id_2613  };
          {
            Vec<1, int32_t> repeat_n_794 { id_2614 };
            bool while_flag_2615 { true };
            do {
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2616 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_2617 { id_2616.notifications };
              uint32_t id_2618 { id_2617.size() };
              int32_t id_2619 { int32_t(id_2618) };
              uint8_t id_2620 { 0 };
              int32_t id_2621 { repeat_n_794[id_2620] };
              bool id_2622 { bool(id_2619 > id_2621) };
              while_flag_2615 = id_2622;
              if (while_flag_2615) {
                uint8_t id_2623 { 0 };
                uint8_t id_2624 { 0 };
                Size id_2625 { sz_ref_793[id_2624] };
                auto fun2626 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_2627 { 0 };
                int32_t id_2628 { repeat_n_794[id_2627] };
                ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2629 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<dessser::gen::raql_expr::t_ext> id_2630 { id_2629.notifications };
                dessser::gen::raql_expr::t_ext id_2631 { id_2630[id_2628] };
                Size id_2632 { fun2626(id_2631) };
                Size id_2633 { Size(id_2625 + id_2632) };
                Void id_2634 { ((void)(sz_ref_793[id_2623] = id_2633), ::dessser::Void()) };
                (void)id_2634;
                uint8_t id_2635 { 0 };
                uint8_t id_2636 { 0 };
                int32_t id_2637 { repeat_n_794[id_2636] };
                int32_t id_2638 { 1L };
                int32_t id_2639 { int32_t(id_2637 + id_2638) };
                Void id_2640 { ((void)(repeat_n_794[id_2635] = id_2639), ::dessser::Void()) };
                (void)id_2640;
                (void)id_2640;
              }
            } while (while_flag_2615);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_2641 { 0 };
          Size id_2642 { sz_ref_793[id_2641] };
          let_res_2612 = id_2642;
        }
        let_res_2584 = let_res_2612;
      }
      Size let_res_2643;
      {
        Size sz_795 { let_res_2584 };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2644 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::raql_expr::t_ext> id_2645 { id_2644.key };
        uint32_t id_2646 { id_2645.size() };
        Vec<1, uint32_t> id_2647 {  id_2646  };
        Size let_res_2648;
        {
          Vec<1, uint32_t> n_ref_796 { id_2647 };
          uint32_t id_2649 { 1U };
          Vec<1, uint32_t> id_2650 {  id_2649  };
          Size let_res_2651;
          {
            Vec<1, uint32_t> lebsz_ref_797 { id_2650 };
            bool while_flag_2652 { true };
            do {
              uint8_t id_2653 { 0 };
              uint32_t id_2654 { n_ref_796[id_2653] };
              uint8_t id_2655 { 0 };
              uint32_t id_2656 { lebsz_ref_797[id_2655] };
              uint8_t id_2657 { 7 };
              uint32_t id_2658 { uint32_t(id_2656 << id_2657) };
              bool id_2659 { bool(id_2654 >= id_2658) };
              while_flag_2652 = id_2659;
              if (while_flag_2652) {
                uint8_t id_2660 { 0 };
                uint8_t id_2661 { 0 };
                uint32_t id_2662 { lebsz_ref_797[id_2661] };
                uint32_t id_2663 { 1U };
                uint32_t id_2664 { uint32_t(id_2662 + id_2663) };
                Void id_2665 { ((void)(lebsz_ref_797[id_2660] = id_2664), ::dessser::Void()) };
                (void)id_2665;
              }
            } while (while_flag_2652);
            (void)::dessser::Void();
            uint8_t id_2666 { 0 };
            uint32_t id_2667 { lebsz_ref_797[id_2666] };
            Size id_2668 { Size(id_2667) };
            let_res_2651 = id_2668;
          }
          let_res_2648 = let_res_2651;
        }
        Size id_2669 { Size(sz_795 + let_res_2648) };
        Vec<1, Size> id_2670 {  id_2669  };
        Size let_res_2671;
        {
          Vec<1, Size> sz_ref_798 { id_2670 };
          int32_t id_2672 { 0L };
          Vec<1, int32_t> id_2673 {  id_2672  };
          {
            Vec<1, int32_t> repeat_n_799 { id_2673 };
            bool while_flag_2674 { true };
            do {
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2675 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_2676 { id_2675.key };
              uint32_t id_2677 { id_2676.size() };
              int32_t id_2678 { int32_t(id_2677) };
              uint8_t id_2679 { 0 };
              int32_t id_2680 { repeat_n_799[id_2679] };
              bool id_2681 { bool(id_2678 > id_2680) };
              while_flag_2674 = id_2681;
              if (while_flag_2674) {
                uint8_t id_2682 { 0 };
                uint8_t id_2683 { 0 };
                Size id_2684 { sz_ref_798[id_2683] };
                auto fun2685 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_2686 { 0 };
                int32_t id_2687 { repeat_n_799[id_2686] };
                ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2688 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<dessser::gen::raql_expr::t_ext> id_2689 { id_2688.key };
                dessser::gen::raql_expr::t_ext id_2690 { id_2689[id_2687] };
                Size id_2691 { fun2685(id_2690) };
                Size id_2692 { Size(id_2684 + id_2691) };
                Void id_2693 { ((void)(sz_ref_798[id_2682] = id_2692), ::dessser::Void()) };
                (void)id_2693;
                uint8_t id_2694 { 0 };
                uint8_t id_2695 { 0 };
                int32_t id_2696 { repeat_n_799[id_2695] };
                int32_t id_2697 { 1L };
                int32_t id_2698 { int32_t(id_2696 + id_2697) };
                Void id_2699 { ((void)(repeat_n_799[id_2694] = id_2698), ::dessser::Void()) };
                (void)id_2699;
                (void)id_2699;
              }
            } while (while_flag_2674);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_2700 { 0 };
          Size id_2701 { sz_ref_798[id_2700] };
          let_res_2671 = id_2701;
        }
        let_res_2643 = let_res_2671;
      }
      Size let_res_2702;
      {
        Size sz_800 { let_res_2643 };
        auto fun2703 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2704 { std::get<0 /* Aggregate */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_2705 { id_2704.commit_cond };
        Size id_2706 { fun2703(id_2705) };
        Size id_2707 { Size(sz_800 + id_2706) };
        let_res_2702 = id_2707;
      }
      Size id_2708 { 1UL };
      Size id_2709 { Size(let_res_2702 + id_2708) };
      Size let_res_2710;
      {
        Size sz_802 { id_2709 };
        auto fun2711 { dessser::gen::raql_flush_method::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2712 { std::get<0 /* Aggregate */>((*p_0)) };
        dessser::gen::raql_flush_method::t_ext id_2713 { id_2712.flush_how };
        Size id_2714 { fun2711(id_2713) };
        Size id_2715 { Size(sz_802 + id_2714) };
        let_res_2710 = id_2715;
      }
      Size let_res_2716;
      {
        Size sz_803 { let_res_2710 };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2717 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<::dessser::gen::raql_operation::data_source> id_2718 { id_2717.from };
        uint32_t id_2719 { id_2718.size() };
        Vec<1, uint32_t> id_2720 {  id_2719  };
        Size let_res_2721;
        {
          Vec<1, uint32_t> n_ref_804 { id_2720 };
          uint32_t id_2722 { 1U };
          Vec<1, uint32_t> id_2723 {  id_2722  };
          Size let_res_2724;
          {
            Vec<1, uint32_t> lebsz_ref_805 { id_2723 };
            bool while_flag_2725 { true };
            do {
              uint8_t id_2726 { 0 };
              uint32_t id_2727 { n_ref_804[id_2726] };
              uint8_t id_2728 { 0 };
              uint32_t id_2729 { lebsz_ref_805[id_2728] };
              uint8_t id_2730 { 7 };
              uint32_t id_2731 { uint32_t(id_2729 << id_2730) };
              bool id_2732 { bool(id_2727 >= id_2731) };
              while_flag_2725 = id_2732;
              if (while_flag_2725) {
                uint8_t id_2733 { 0 };
                uint8_t id_2734 { 0 };
                uint32_t id_2735 { lebsz_ref_805[id_2734] };
                uint32_t id_2736 { 1U };
                uint32_t id_2737 { uint32_t(id_2735 + id_2736) };
                Void id_2738 { ((void)(lebsz_ref_805[id_2733] = id_2737), ::dessser::Void()) };
                (void)id_2738;
              }
            } while (while_flag_2725);
            (void)::dessser::Void();
            uint8_t id_2739 { 0 };
            uint32_t id_2740 { lebsz_ref_805[id_2739] };
            Size id_2741 { Size(id_2740) };
            let_res_2724 = id_2741;
          }
          let_res_2721 = let_res_2724;
        }
        Size id_2742 { Size(sz_803 + let_res_2721) };
        Vec<1, Size> id_2743 {  id_2742  };
        Size let_res_2744;
        {
          Vec<1, Size> sz_ref_806 { id_2743 };
          int32_t id_2745 { 0L };
          Vec<1, int32_t> id_2746 {  id_2745  };
          {
            Vec<1, int32_t> repeat_n_807 { id_2746 };
            bool while_flag_2747 { true };
            do {
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2748 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<::dessser::gen::raql_operation::data_source> id_2749 { id_2748.from };
              uint32_t id_2750 { id_2749.size() };
              int32_t id_2751 { int32_t(id_2750) };
              uint8_t id_2752 { 0 };
              int32_t id_2753 { repeat_n_807[id_2752] };
              bool id_2754 { bool(id_2751 > id_2753) };
              while_flag_2747 = id_2754;
              if (while_flag_2747) {
                uint8_t id_2755 { 0 };
                uint8_t id_2756 { 0 };
                Size id_2757 { sz_ref_806[id_2756] };
                uint8_t id_2758 { 0 };
                int32_t id_2759 { repeat_n_807[id_2758] };
                ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2760 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<::dessser::gen::raql_operation::data_source> id_2761 { id_2760.from };
                ::dessser::gen::raql_operation::data_source id_2762 { id_2761[id_2759] };
                Size id_2763 { data_source_sersize_of_row_binary(id_2762) };
                Size id_2764 { Size(id_2757 + id_2763) };
                Void id_2765 { ((void)(sz_ref_806[id_2755] = id_2764), ::dessser::Void()) };
                (void)id_2765;
                uint8_t id_2766 { 0 };
                uint8_t id_2767 { 0 };
                int32_t id_2768 { repeat_n_807[id_2767] };
                int32_t id_2769 { 1L };
                int32_t id_2770 { int32_t(id_2768 + id_2769) };
                Void id_2771 { ((void)(repeat_n_807[id_2766] = id_2770), ::dessser::Void()) };
                (void)id_2771;
                (void)id_2771;
              }
            } while (while_flag_2747);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_2772 { 0 };
          Size id_2773 { sz_ref_806[id_2772] };
          let_res_2744 = id_2773;
        }
        let_res_2716 = let_res_2744;
      }
      Size let_res_2774;
      {
        Size sz_808 { let_res_2716 };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2775 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<dessser::gen::raql_expr::t_ext> id_2776 { id_2775.every };
        bool id_2777 { !(id_2776.has_value ()) };
        Size choose_res_2778;
        if (id_2777) {
          Size id_2779 { 1UL };
          Size id_2780 { Size(sz_808 + id_2779) };
          choose_res_2778 = id_2780;
        } else {
          auto fun2781 { dessser::gen::raql_expr::sersize_of_row_binary };
          ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2782 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_2783 { id_2782.every };
          dessser::gen::raql_expr::t_ext id_2784 { id_2783.value() };
          Size id_2785 { fun2781(id_2784) };
          Size id_2786 { Size(sz_808 + id_2785) };
          Size id_2787 { 1UL };
          Size id_2788 { Size(id_2786 + id_2787) };
          choose_res_2778 = id_2788;
        }
        let_res_2774 = choose_res_2778;
      }
      Size let_res_2789;
      {
        Size sz_809 { let_res_2774 };
        ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2790 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::field_name::t_ext> id_2791 { id_2790.Aggregate_factors };
        uint32_t id_2792 { id_2791.size() };
        Vec<1, uint32_t> id_2793 {  id_2792  };
        Size let_res_2794;
        {
          Vec<1, uint32_t> n_ref_810 { id_2793 };
          uint32_t id_2795 { 1U };
          Vec<1, uint32_t> id_2796 {  id_2795  };
          Size let_res_2797;
          {
            Vec<1, uint32_t> lebsz_ref_811 { id_2796 };
            bool while_flag_2798 { true };
            do {
              uint8_t id_2799 { 0 };
              uint32_t id_2800 { n_ref_810[id_2799] };
              uint8_t id_2801 { 0 };
              uint32_t id_2802 { lebsz_ref_811[id_2801] };
              uint8_t id_2803 { 7 };
              uint32_t id_2804 { uint32_t(id_2802 << id_2803) };
              bool id_2805 { bool(id_2800 >= id_2804) };
              while_flag_2798 = id_2805;
              if (while_flag_2798) {
                uint8_t id_2806 { 0 };
                uint8_t id_2807 { 0 };
                uint32_t id_2808 { lebsz_ref_811[id_2807] };
                uint32_t id_2809 { 1U };
                uint32_t id_2810 { uint32_t(id_2808 + id_2809) };
                Void id_2811 { ((void)(lebsz_ref_811[id_2806] = id_2810), ::dessser::Void()) };
                (void)id_2811;
              }
            } while (while_flag_2798);
            (void)::dessser::Void();
            uint8_t id_2812 { 0 };
            uint32_t id_2813 { lebsz_ref_811[id_2812] };
            Size id_2814 { Size(id_2813) };
            let_res_2797 = id_2814;
          }
          let_res_2794 = let_res_2797;
        }
        Size id_2815 { Size(sz_809 + let_res_2794) };
        Vec<1, Size> id_2816 {  id_2815  };
        Size let_res_2817;
        {
          Vec<1, Size> sz_ref_812 { id_2816 };
          int32_t id_2818 { 0L };
          Vec<1, int32_t> id_2819 {  id_2818  };
          {
            Vec<1, int32_t> repeat_n_813 { id_2819 };
            bool while_flag_2820 { true };
            do {
              ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2821 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::field_name::t_ext> id_2822 { id_2821.Aggregate_factors };
              uint32_t id_2823 { id_2822.size() };
              int32_t id_2824 { int32_t(id_2823) };
              uint8_t id_2825 { 0 };
              int32_t id_2826 { repeat_n_813[id_2825] };
              bool id_2827 { bool(id_2824 > id_2826) };
              while_flag_2820 = id_2827;
              if (while_flag_2820) {
                uint8_t id_2828 { 0 };
                uint8_t id_2829 { 0 };
                Size id_2830 { sz_ref_812[id_2829] };
                auto fun2831 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_2832 { 0 };
                int32_t id_2833 { repeat_n_813[id_2832] };
                ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_2834 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2835 { id_2834.Aggregate_factors };
                dessser::gen::field_name::t_ext id_2836 { id_2835[id_2833] };
                Size id_2837 { fun2831(id_2836) };
                Size id_2838 { Size(id_2830 + id_2837) };
                Void id_2839 { ((void)(sz_ref_812[id_2828] = id_2838), ::dessser::Void()) };
                (void)id_2839;
                uint8_t id_2840 { 0 };
                uint8_t id_2841 { 0 };
                int32_t id_2842 { repeat_n_813[id_2841] };
                int32_t id_2843 { 1L };
                int32_t id_2844 { int32_t(id_2842 + id_2843) };
                Void id_2845 { ((void)(repeat_n_813[id_2840] = id_2844), ::dessser::Void()) };
                (void)id_2845;
                (void)id_2845;
              }
            } while (while_flag_2820);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_2846 { 0 };
          Size id_2847 { sz_ref_812[id_2846] };
          let_res_2817 = id_2847;
        }
        let_res_2789 = let_res_2817;
      }
      choose_res_2337 = let_res_2789;
    } else {
      uint16_t id_2848 { 1 };
      uint16_t id_2849 { uint16_t((*p_0).index()) };
      bool id_2850 { bool(id_2848 == id_2849) };
      Size choose_res_2851;
      if (id_2850) {
        Size id_2852 { 2UL };
        ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2853 { std::get<1 /* ReadExternal */>((*p_0)) };
        ::dessser::gen::raql_operation::external_source id_2854 { id_2853.source };
        Size id_2855 { external_source_sersize_of_row_binary(id_2854) };
        Size id_2856 { Size(id_2852 + id_2855) };
        Size let_res_2857;
        {
          Size sz_763 { id_2856 };
          ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2858 { std::get<1 /* ReadExternal */>((*p_0)) };
          ::dessser::gen::raql_operation::external_format id_2859 { id_2858.format };
          Size id_2860 { external_format_sersize_of_row_binary(id_2859) };
          Size id_2861 { Size(sz_763 + id_2860) };
          let_res_2857 = id_2861;
        }
        Size let_res_2862;
        {
          Size sz_764 { let_res_2857 };
          ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2863 { std::get<1 /* ReadExternal */>((*p_0)) };
          std::optional<dessser::gen::event_time::t_ext> id_2864 { id_2863.event_time };
          bool id_2865 { !(id_2864.has_value ()) };
          Size choose_res_2866;
          if (id_2865) {
            Size id_2867 { 1UL };
            Size id_2868 { Size(sz_764 + id_2867) };
            choose_res_2866 = id_2868;
          } else {
            auto fun2869 { dessser::gen::event_time::sersize_of_row_binary };
            ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2870 { std::get<1 /* ReadExternal */>((*p_0)) };
            std::optional<dessser::gen::event_time::t_ext> id_2871 { id_2870.event_time };
            dessser::gen::event_time::t_ext id_2872 { id_2871.value() };
            Size id_2873 { fun2869(id_2872) };
            Size id_2874 { Size(sz_764 + id_2873) };
            Size id_2875 { 1UL };
            Size id_2876 { Size(id_2874 + id_2875) };
            choose_res_2866 = id_2876;
          }
          let_res_2862 = choose_res_2866;
        }
        Size let_res_2877;
        {
          Size sz_765 { let_res_2862 };
          ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2878 { std::get<1 /* ReadExternal */>((*p_0)) };
          Lst<dessser::gen::field_name::t_ext> id_2879 { id_2878.ReadExternal_factors };
          uint32_t id_2880 { id_2879.size() };
          Vec<1, uint32_t> id_2881 {  id_2880  };
          Size let_res_2882;
          {
            Vec<1, uint32_t> n_ref_766 { id_2881 };
            uint32_t id_2883 { 1U };
            Vec<1, uint32_t> id_2884 {  id_2883  };
            Size let_res_2885;
            {
              Vec<1, uint32_t> lebsz_ref_767 { id_2884 };
              bool while_flag_2886 { true };
              do {
                uint8_t id_2887 { 0 };
                uint32_t id_2888 { n_ref_766[id_2887] };
                uint8_t id_2889 { 0 };
                uint32_t id_2890 { lebsz_ref_767[id_2889] };
                uint8_t id_2891 { 7 };
                uint32_t id_2892 { uint32_t(id_2890 << id_2891) };
                bool id_2893 { bool(id_2888 >= id_2892) };
                while_flag_2886 = id_2893;
                if (while_flag_2886) {
                  uint8_t id_2894 { 0 };
                  uint8_t id_2895 { 0 };
                  uint32_t id_2896 { lebsz_ref_767[id_2895] };
                  uint32_t id_2897 { 1U };
                  uint32_t id_2898 { uint32_t(id_2896 + id_2897) };
                  Void id_2899 { ((void)(lebsz_ref_767[id_2894] = id_2898), ::dessser::Void()) };
                  (void)id_2899;
                }
              } while (while_flag_2886);
              (void)::dessser::Void();
              uint8_t id_2900 { 0 };
              uint32_t id_2901 { lebsz_ref_767[id_2900] };
              Size id_2902 { Size(id_2901) };
              let_res_2885 = id_2902;
            }
            let_res_2882 = let_res_2885;
          }
          Size id_2903 { Size(sz_765 + let_res_2882) };
          Vec<1, Size> id_2904 {  id_2903  };
          Size let_res_2905;
          {
            Vec<1, Size> sz_ref_768 { id_2904 };
            int32_t id_2906 { 0L };
            Vec<1, int32_t> id_2907 {  id_2906  };
            {
              Vec<1, int32_t> repeat_n_769 { id_2907 };
              bool while_flag_2908 { true };
              do {
                ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2909 { std::get<1 /* ReadExternal */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2910 { id_2909.ReadExternal_factors };
                uint32_t id_2911 { id_2910.size() };
                int32_t id_2912 { int32_t(id_2911) };
                uint8_t id_2913 { 0 };
                int32_t id_2914 { repeat_n_769[id_2913] };
                bool id_2915 { bool(id_2912 > id_2914) };
                while_flag_2908 = id_2915;
                if (while_flag_2908) {
                  uint8_t id_2916 { 0 };
                  uint8_t id_2917 { 0 };
                  Size id_2918 { sz_ref_768[id_2917] };
                  auto fun2919 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_2920 { 0 };
                  int32_t id_2921 { repeat_n_769[id_2920] };
                  ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_2922 { std::get<1 /* ReadExternal */>((*p_0)) };
                  Lst<dessser::gen::field_name::t_ext> id_2923 { id_2922.ReadExternal_factors };
                  dessser::gen::field_name::t_ext id_2924 { id_2923[id_2921] };
                  Size id_2925 { fun2919(id_2924) };
                  Size id_2926 { Size(id_2918 + id_2925) };
                  Void id_2927 { ((void)(sz_ref_768[id_2916] = id_2926), ::dessser::Void()) };
                  (void)id_2927;
                  uint8_t id_2928 { 0 };
                  uint8_t id_2929 { 0 };
                  int32_t id_2930 { repeat_n_769[id_2929] };
                  int32_t id_2931 { 1L };
                  int32_t id_2932 { int32_t(id_2930 + id_2931) };
                  Void id_2933 { ((void)(repeat_n_769[id_2928] = id_2932), ::dessser::Void()) };
                  (void)id_2933;
                  (void)id_2933;
                }
              } while (while_flag_2908);
              (void)::dessser::Void();
            }
            (void)::dessser::Void();
            uint8_t id_2934 { 0 };
            Size id_2935 { sz_ref_768[id_2934] };
            let_res_2905 = id_2935;
          }
          let_res_2877 = let_res_2905;
        }
        choose_res_2851 = let_res_2877;
      } else {
        uint16_t id_2936 { uint16_t((*p_0).index()) };
        uint16_t id_2937 { 2 };
        bool id_2938 { bool(id_2936 == id_2937) };
        Void id_2939 { ((void)(assert(id_2938)), ::dessser::Void()) };
        (void)id_2939;
        Size id_2940 { 2UL };
        ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2941 { std::get<2 /* ListenFor */>((*p_0)) };
        std::string id_2942 { id_2941.net_addr };
        uint32_t id_2943 { (uint32_t)id_2942.size() };
        Vec<1, uint32_t> id_2944 {  id_2943  };
        Size let_res_2945;
        {
          Vec<1, uint32_t> n_ref_752 { id_2944 };
          uint32_t id_2946 { 1U };
          Vec<1, uint32_t> id_2947 {  id_2946  };
          Size let_res_2948;
          {
            Vec<1, uint32_t> lebsz_ref_753 { id_2947 };
            bool while_flag_2949 { true };
            do {
              uint8_t id_2950 { 0 };
              uint32_t id_2951 { n_ref_752[id_2950] };
              uint8_t id_2952 { 0 };
              uint32_t id_2953 { lebsz_ref_753[id_2952] };
              uint8_t id_2954 { 7 };
              uint32_t id_2955 { uint32_t(id_2953 << id_2954) };
              bool id_2956 { bool(id_2951 >= id_2955) };
              while_flag_2949 = id_2956;
              if (while_flag_2949) {
                uint8_t id_2957 { 0 };
                uint8_t id_2958 { 0 };
                uint32_t id_2959 { lebsz_ref_753[id_2958] };
                uint32_t id_2960 { 1U };
                uint32_t id_2961 { uint32_t(id_2959 + id_2960) };
                Void id_2962 { ((void)(lebsz_ref_753[id_2957] = id_2961), ::dessser::Void()) };
                (void)id_2962;
              }
            } while (while_flag_2949);
            (void)::dessser::Void();
            uint8_t id_2963 { 0 };
            uint32_t id_2964 { lebsz_ref_753[id_2963] };
            Size id_2965 { Size(id_2964) };
            let_res_2948 = id_2965;
          }
          let_res_2945 = let_res_2948;
        }
        ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2966 { std::get<2 /* ListenFor */>((*p_0)) };
        std::string id_2967 { id_2966.net_addr };
        uint32_t id_2968 { (uint32_t)id_2967.size() };
        Size id_2969 { Size(id_2968) };
        Size id_2970 { Size(let_res_2945 + id_2969) };
        Size id_2971 { Size(id_2940 + id_2970) };
        Size id_2972 { 2UL };
        Size id_2973 { Size(id_2971 + id_2972) };
        Size let_res_2974;
        {
          Size sz_755 { id_2973 };
          auto fun2975 { dessser::gen::raql_ip_protocol::sersize_of_row_binary };
          ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2976 { std::get<2 /* ListenFor */>((*p_0)) };
          dessser::gen::raql_ip_protocol::t_ext id_2977 { id_2976.ip_proto };
          Size id_2978 { fun2975(id_2977) };
          Size id_2979 { Size(sz_755 + id_2978) };
          let_res_2974 = id_2979;
        }
        Size let_res_2980;
        {
          Size sz_756 { let_res_2974 };
          auto fun2981 { dessser::gen::raql_net_protocol::sersize_of_row_binary };
          ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2982 { std::get<2 /* ListenFor */>((*p_0)) };
          dessser::gen::raql_net_protocol::t_ext id_2983 { id_2982.proto };
          Size id_2984 { fun2981(id_2983) };
          Size id_2985 { Size(sz_756 + id_2984) };
          let_res_2980 = id_2985;
        }
        Size let_res_2986;
        {
          Size sz_757 { let_res_2980 };
          ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_2987 { std::get<2 /* ListenFor */>((*p_0)) };
          Lst<dessser::gen::field_name::t_ext> id_2988 { id_2987.factors };
          uint32_t id_2989 { id_2988.size() };
          Vec<1, uint32_t> id_2990 {  id_2989  };
          Size let_res_2991;
          {
            Vec<1, uint32_t> n_ref_758 { id_2990 };
            uint32_t id_2992 { 1U };
            Vec<1, uint32_t> id_2993 {  id_2992  };
            Size let_res_2994;
            {
              Vec<1, uint32_t> lebsz_ref_759 { id_2993 };
              bool while_flag_2995 { true };
              do {
                uint8_t id_2996 { 0 };
                uint32_t id_2997 { n_ref_758[id_2996] };
                uint8_t id_2998 { 0 };
                uint32_t id_2999 { lebsz_ref_759[id_2998] };
                uint8_t id_3000 { 7 };
                uint32_t id_3001 { uint32_t(id_2999 << id_3000) };
                bool id_3002 { bool(id_2997 >= id_3001) };
                while_flag_2995 = id_3002;
                if (while_flag_2995) {
                  uint8_t id_3003 { 0 };
                  uint8_t id_3004 { 0 };
                  uint32_t id_3005 { lebsz_ref_759[id_3004] };
                  uint32_t id_3006 { 1U };
                  uint32_t id_3007 { uint32_t(id_3005 + id_3006) };
                  Void id_3008 { ((void)(lebsz_ref_759[id_3003] = id_3007), ::dessser::Void()) };
                  (void)id_3008;
                }
              } while (while_flag_2995);
              (void)::dessser::Void();
              uint8_t id_3009 { 0 };
              uint32_t id_3010 { lebsz_ref_759[id_3009] };
              Size id_3011 { Size(id_3010) };
              let_res_2994 = id_3011;
            }
            let_res_2991 = let_res_2994;
          }
          Size id_3012 { Size(sz_757 + let_res_2991) };
          Vec<1, Size> id_3013 {  id_3012  };
          Size let_res_3014;
          {
            Vec<1, Size> sz_ref_760 { id_3013 };
            int32_t id_3015 { 0L };
            Vec<1, int32_t> id_3016 {  id_3015  };
            {
              Vec<1, int32_t> repeat_n_761 { id_3016 };
              bool while_flag_3017 { true };
              do {
                ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_3018 { std::get<2 /* ListenFor */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_3019 { id_3018.factors };
                uint32_t id_3020 { id_3019.size() };
                int32_t id_3021 { int32_t(id_3020) };
                uint8_t id_3022 { 0 };
                int32_t id_3023 { repeat_n_761[id_3022] };
                bool id_3024 { bool(id_3021 > id_3023) };
                while_flag_3017 = id_3024;
                if (while_flag_3017) {
                  uint8_t id_3025 { 0 };
                  uint8_t id_3026 { 0 };
                  Size id_3027 { sz_ref_760[id_3026] };
                  auto fun3028 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_3029 { 0 };
                  int32_t id_3030 { repeat_n_761[id_3029] };
                  ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_3031 { std::get<2 /* ListenFor */>((*p_0)) };
                  Lst<dessser::gen::field_name::t_ext> id_3032 { id_3031.factors };
                  dessser::gen::field_name::t_ext id_3033 { id_3032[id_3030] };
                  Size id_3034 { fun3028(id_3033) };
                  Size id_3035 { Size(id_3027 + id_3034) };
                  Void id_3036 { ((void)(sz_ref_760[id_3025] = id_3035), ::dessser::Void()) };
                  (void)id_3036;
                  uint8_t id_3037 { 0 };
                  uint8_t id_3038 { 0 };
                  int32_t id_3039 { repeat_n_761[id_3038] };
                  int32_t id_3040 { 1L };
                  int32_t id_3041 { int32_t(id_3039 + id_3040) };
                  Void id_3042 { ((void)(repeat_n_761[id_3037] = id_3041), ::dessser::Void()) };
                  (void)id_3042;
                  (void)id_3042;
                }
              } while (while_flag_3017);
              (void)::dessser::Void();
            }
            (void)::dessser::Void();
            uint8_t id_3043 { 0 };
            Size id_3044 { sz_ref_760[id_3043] };
            let_res_3014 = id_3044;
          }
          let_res_2986 = let_res_3014;
        }
        choose_res_2851 = let_res_2986;
      }
      choose_res_2337 = choose_res_2851;
    }
    return choose_res_2337;
  }
   };
  return fun2333;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::t>  &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_694" "make_snd_695" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_694") (identifier "make_snd_695"))))
 */
static std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer &)> fun3045 { [&](Pointer p_0) {
    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3046 { of_row_binary(p_0) };
    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3047;
    {
      auto make_fst_694 { std::get<0>(id_3046) };
      auto make_snd_695 { std::get<1>(id_3046) };
      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3048 { make_fst_694, make_snd_695 };
      letpair_res_3047 = id_3048;
    }
    return letpair_res_3047;
  }
   };
  return fun3045;
}
std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (let "dtup_99"
              (let "dsum1_75" (let-pair "du16_fst_70" "du16_snd_71" (read-u16 little-endian (identifier "dsum1_snd_65")) (make-tup (identifier "du16_fst_70") (identifier "du16_snd_71")))
                (let-pair "dsum1_fst_76" "dsum1_snd_77" (identifier "dsum1_75")
                  (if (eq (u16 0) (identifier "dsum1_fst_76")) (make-tup (construct "[AllSites Void | TheseSites STRING | ThisSite Void]" 0 (nop)) (identifier "dsum1_snd_77"))
                    (if (eq (u16 1) (identifier "dsum1_fst_76"))
                      (let "dstring1_87"
                        (let "leb_ref_81" (make-vec (u32 0))
                          (let "shft_ref_82" (make-vec (u8 0))
                            (let "p_ref_83" (make-vec (identifier "dsum1_snd_77"))
                              (seq
                                (while
                                  (let "leb128_84" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_83")))
                                    (let-pair "leb128_fst_85" "leb128_snd_86" 
                                      (identifier "leb128_84")
                                      (seq (set-vec (u8 0) (identifier "p_ref_83") (identifier "leb128_snd_86"))
                                        (set-vec (u8 0) (identifier "leb_ref_81")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_85") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_82"))) (unsafe-nth (u8 0) (identifier "leb_ref_81"))))
                                        (set-vec (u8 0) (identifier "shft_ref_82") (add (unsafe-nth (u8 0) (identifier "shft_ref_82")) (u8 7))) 
                                        (ge (identifier "leb128_fst_85") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_81"))) (unsafe-nth (u8 0) (identifier "p_ref_83")))))))
                        (let-pair "dstring1_fst_88" "dstring1_snd_89" 
                          (identifier "dstring1_87")
                          (let-pair "dstring2_fst_91" "dstring2_snd_92" 
                            (read-bytes (identifier "dstring1_snd_89") (identifier "dstring1_fst_88"))
                            (make-tup (construct "[AllSites Void | TheseSites STRING | ThisSite Void]" 1 (string-of-bytes (identifier "dstring2_fst_91"))) (identifier "dstring2_snd_92")))))
                      (seq (assert (eq (identifier "dsum1_fst_76") (u16 2))) (make-tup (construct "[AllSites Void | TheseSites STRING | ThisSite Void]" 2 (nop)) (identifier "dsum1_snd_77")))))))
              (let-pair "dtup_fst_100" "dtup_snd_101" (identifier "dtup_99")
                (let "dtup_117"
                  (if (eq (peek-u8 (identifier "dtup_snd_101") (size 0)) (u8 1)) 
                    (make-tup (null "STRING") (ptr-add (identifier "dtup_snd_101") (size 1)))
                    (let "dstring1_108"
                      (let "leb_ref_102" (make-vec (u32 0))
                        (let "shft_ref_103" (make-vec (u8 0))
                          (let "p_ref_104" (make-vec (ptr-add (identifier "dtup_snd_101") (size 1)))
                            (seq
                              (while
                                (let "leb128_105" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_104")))
                                  (let-pair "leb128_fst_106" "leb128_snd_107" 
                                    (identifier "leb128_105")
                                    (seq (set-vec (u8 0) (identifier "p_ref_104") (identifier "leb128_snd_107"))
                                      (set-vec (u8 0) (identifier "leb_ref_102")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_106") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_103"))) (unsafe-nth (u8 0) (identifier "leb_ref_102"))))
                                      (set-vec (u8 0) (identifier "shft_ref_103") (add (unsafe-nth (u8 0) (identifier "shft_ref_103")) (u8 7))) 
                                      (ge (identifier "leb128_fst_106") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_102"))) (unsafe-nth (u8 0) (identifier "p_ref_104")))))))
                      (let-pair "dstring1_fst_109" "dstring1_snd_110" 
                        (identifier "dstring1_108")
                        (let-pair "dstring2_fst_112" "dstring2_snd_113" 
                          (read-bytes (identifier "dstring1_snd_110") (identifier "dstring1_fst_109")) 
                          (make-tup (not-null (string-of-bytes (identifier "dstring2_fst_112"))) (identifier "dstring2_snd_113"))))))
                  (let-pair "dtup_fst_118" "dtup_snd_119" (identifier "dtup_117")
                    (let-pair "dtup_fst_121" "dtup_snd_122" (apply (ext-identifier function_name of-row-binary) (identifier "dtup_snd_119"))
                      (make-tup
                        (construct "[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" 0
                          (make-tup (identifier "dtup_fst_100") (identifier "dtup_fst_118") (identifier "dtup_fst_121"))) 
                        (identifier "dtup_snd_122")))))))
            (seq (assert (eq (identifier "dsum1_fst_64") (u16 1)))
              (let-pair "dsum2_fst_67" "dsum2_snd_68" (apply (identifier "of-row-binary") (identifier "dsum1_snd_65"))
                (make-tup (construct "[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" 1 (identifier "dsum2_fst_67")) (identifier "dsum2_snd_68"))))))))
 */
static std::function<::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c(Pointer &)> data_source_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c(Pointer &)> fun3049 { [&](Pointer p_0) {
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3050 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_3051;
    {
      auto du16_fst_58 { std::get<0>(id_3050) };
      auto du16_snd_59 { std::get<1>(id_3050) };
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3052 { du16_fst_58, du16_snd_59 };
      letpair_res_3051 = id_3052;
    }
    ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c let_res_3053;
    {
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_3051 };
      ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c letpair_res_3054;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_3055 { 0 };
        bool id_3056 { bool(id_3055 == dsum1_fst_64) };
        ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c choose_res_3057;
        if (id_3056) {
          ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3058 { dsum1_snd_65.readU16Le() };
          ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_3059;
          {
            auto du16_fst_70 { std::get<0>(id_3058) };
            auto du16_snd_71 { std::get<1>(id_3058) };
            ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3060 { du16_fst_70, du16_snd_71 };
            letpair_res_3059 = id_3060;
          }
          ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 let_res_3061;
          {
            ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_75 { letpair_res_3059 };
            ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 letpair_res_3062;
            {
              auto dsum1_fst_76 { std::get<0>(dsum1_75) };
              auto dsum1_snd_77 { std::get<1>(dsum1_75) };
              uint16_t id_3063 { 0 };
              bool id_3064 { bool(id_3063 == dsum1_fst_76) };
              ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 choose_res_3065;
              if (id_3064) {
                (void)::dessser::Void();
                ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_3066 { std::in_place_index<0>, ::dessser::Void() };
                ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 id_3067 { id_3066, dsum1_snd_77 };
                choose_res_3065 = id_3067;
              } else {
                uint16_t id_3068 { 1 };
                bool id_3069 { bool(id_3068 == dsum1_fst_76) };
                ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 choose_res_3070;
                if (id_3069) {
                  uint32_t id_3071 { 0U };
                  Vec<1, uint32_t> id_3072 {  id_3071  };
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3073;
                  {
                    Vec<1, uint32_t> leb_ref_81 { id_3072 };
                    uint8_t id_3074 { 0 };
                    Vec<1, uint8_t> id_3075 {  id_3074  };
                    ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3076;
                    {
                      Vec<1, uint8_t> shft_ref_82 { id_3075 };
                      Vec<1, Pointer> id_3077 {  dsum1_snd_77  };
                      ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3078;
                      {
                        Vec<1, Pointer> p_ref_83 { id_3077 };
                        bool while_flag_3079 { true };
                        do {
                          uint8_t id_3080 { 0 };
                          Pointer id_3081 { p_ref_83[id_3080] };
                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3082 { id_3081.readU8() };
                          bool let_res_3083;
                          {
                            ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_84 { id_3082 };
                            bool letpair_res_3084;
                            {
                              auto leb128_fst_85 { std::get<0>(leb128_84) };
                              auto leb128_snd_86 { std::get<1>(leb128_84) };
                              uint8_t id_3085 { 0 };
                              Void id_3086 { ((void)(p_ref_83[id_3085] = leb128_snd_86), ::dessser::Void()) };
                              (void)id_3086;
                              uint8_t id_3087 { 0 };
                              uint8_t id_3088 { 127 };
                              uint8_t id_3089 { uint8_t(leb128_fst_85 & id_3088) };
                              uint32_t id_3090 { uint32_t(id_3089) };
                              uint8_t id_3091 { 0 };
                              uint8_t id_3092 { shft_ref_82[id_3091] };
                              uint32_t id_3093 { uint32_t(id_3090 << id_3092) };
                              uint8_t id_3094 { 0 };
                              uint32_t id_3095 { leb_ref_81[id_3094] };
                              uint32_t id_3096 { uint32_t(id_3093 | id_3095) };
                              Void id_3097 { ((void)(leb_ref_81[id_3087] = id_3096), ::dessser::Void()) };
                              (void)id_3097;
                              uint8_t id_3098 { 0 };
                              uint8_t id_3099 { 0 };
                              uint8_t id_3100 { shft_ref_82[id_3099] };
                              uint8_t id_3101 { 7 };
                              uint8_t id_3102 { uint8_t(id_3100 + id_3101) };
                              Void id_3103 { ((void)(shft_ref_82[id_3098] = id_3102), ::dessser::Void()) };
                              (void)id_3103;
                              uint8_t id_3104 { 128 };
                              bool id_3105 { bool(leb128_fst_85 >= id_3104) };
                              letpair_res_3084 = id_3105;
                            }
                            let_res_3083 = letpair_res_3084;
                          }
                          while_flag_3079 = let_res_3083;
                          if (while_flag_3079) {
                            (void)::dessser::Void();
                          }
                        } while (while_flag_3079);
                        (void)::dessser::Void();
                        uint8_t id_3106 { 0 };
                        uint32_t id_3107 { leb_ref_81[id_3106] };
                        Size id_3108 { Size(id_3107) };
                        uint8_t id_3109 { 0 };
                        Pointer id_3110 { p_ref_83[id_3109] };
                        ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_3111 { id_3108, id_3110 };
                        let_res_3078 = id_3111;
                      }
                      let_res_3076 = let_res_3078;
                    }
                    let_res_3073 = let_res_3076;
                  }
                  ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 let_res_3112;
                  {
                    ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_87 { let_res_3073 };
                    ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 letpair_res_3113;
                    {
                      auto dstring1_fst_88 { std::get<0>(dstring1_87) };
                      auto dstring1_snd_89 { std::get<1>(dstring1_87) };
                      ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_3114 { dstring1_snd_89.readBytes(dstring1_fst_88) };
                      ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 letpair_res_3115;
                      {
                        auto dstring2_fst_91 { std::get<0>(id_3114) };
                        auto dstring2_snd_92 { std::get<1>(id_3114) };
                        std::string id_3116 { dstring2_fst_91.toString() };
                        ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_3117 { std::in_place_index<1>, id_3116 };
                        ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 id_3118 { id_3117, dstring2_snd_92 };
                        letpair_res_3115 = id_3118;
                      }
                      letpair_res_3113 = letpair_res_3115;
                    }
                    let_res_3112 = letpair_res_3113;
                  }
                  choose_res_3070 = let_res_3112;
                } else {
                  uint16_t id_3119 { 2 };
                  bool id_3120 { bool(dsum1_fst_76 == id_3119) };
                  Void id_3121 { ((void)(assert(id_3120)), ::dessser::Void()) };
                  (void)id_3121;
                  (void)::dessser::Void();
                  ::dessser::gen::raql_operation::t8c6ca1751131c806bba8633db9760cf7 id_3122 { std::in_place_index<2>, ::dessser::Void() };
                  ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 id_3123 { id_3122, dsum1_snd_77 };
                  choose_res_3070 = id_3123;
                }
                choose_res_3065 = choose_res_3070;
              }
              letpair_res_3062 = choose_res_3065;
            }
            let_res_3061 = letpair_res_3062;
          }
          ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c let_res_3124;
          {
            ::dessser::gen::raql_operation::t844d6b87e600be23c995de9c1a6436d6 dtup_99 { let_res_3061 };
            ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c letpair_res_3125;
            {
              auto dtup_fst_100 { std::get<0>(dtup_99) };
              auto dtup_snd_101 { std::get<1>(dtup_99) };
              Size id_3126 { 0UL };
              uint8_t id_3127 { dtup_snd_101.peekU8(id_3126) };
              uint8_t id_3128 { 1 };
              bool id_3129 { bool(id_3127 == id_3128) };
              ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 choose_res_3130;
              if (id_3129) {
                std::optional<std::string> id_3131 { std::nullopt };
                Size id_3132 { 1UL };
                Pointer id_3133 { dtup_snd_101.skip(id_3132) };
                ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 id_3134 { id_3131, id_3133 };
                choose_res_3130 = id_3134;
              } else {
                uint32_t id_3135 { 0U };
                Vec<1, uint32_t> id_3136 {  id_3135  };
                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3137;
                {
                  Vec<1, uint32_t> leb_ref_102 { id_3136 };
                  uint8_t id_3138 { 0 };
                  Vec<1, uint8_t> id_3139 {  id_3138  };
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3140;
                  {
                    Vec<1, uint8_t> shft_ref_103 { id_3139 };
                    Size id_3141 { 1UL };
                    Pointer id_3142 { dtup_snd_101.skip(id_3141) };
                    Vec<1, Pointer> id_3143 {  id_3142  };
                    ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3144;
                    {
                      Vec<1, Pointer> p_ref_104 { id_3143 };
                      bool while_flag_3145 { true };
                      do {
                        uint8_t id_3146 { 0 };
                        Pointer id_3147 { p_ref_104[id_3146] };
                        ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3148 { id_3147.readU8() };
                        bool let_res_3149;
                        {
                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_105 { id_3148 };
                          bool letpair_res_3150;
                          {
                            auto leb128_fst_106 { std::get<0>(leb128_105) };
                            auto leb128_snd_107 { std::get<1>(leb128_105) };
                            uint8_t id_3151 { 0 };
                            Void id_3152 { ((void)(p_ref_104[id_3151] = leb128_snd_107), ::dessser::Void()) };
                            (void)id_3152;
                            uint8_t id_3153 { 0 };
                            uint8_t id_3154 { 127 };
                            uint8_t id_3155 { uint8_t(leb128_fst_106 & id_3154) };
                            uint32_t id_3156 { uint32_t(id_3155) };
                            uint8_t id_3157 { 0 };
                            uint8_t id_3158 { shft_ref_103[id_3157] };
                            uint32_t id_3159 { uint32_t(id_3156 << id_3158) };
                            uint8_t id_3160 { 0 };
                            uint32_t id_3161 { leb_ref_102[id_3160] };
                            uint32_t id_3162 { uint32_t(id_3159 | id_3161) };
                            Void id_3163 { ((void)(leb_ref_102[id_3153] = id_3162), ::dessser::Void()) };
                            (void)id_3163;
                            uint8_t id_3164 { 0 };
                            uint8_t id_3165 { 0 };
                            uint8_t id_3166 { shft_ref_103[id_3165] };
                            uint8_t id_3167 { 7 };
                            uint8_t id_3168 { uint8_t(id_3166 + id_3167) };
                            Void id_3169 { ((void)(shft_ref_103[id_3164] = id_3168), ::dessser::Void()) };
                            (void)id_3169;
                            uint8_t id_3170 { 128 };
                            bool id_3171 { bool(leb128_fst_106 >= id_3170) };
                            letpair_res_3150 = id_3171;
                          }
                          let_res_3149 = letpair_res_3150;
                        }
                        while_flag_3145 = let_res_3149;
                        if (while_flag_3145) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_3145);
                      (void)::dessser::Void();
                      uint8_t id_3172 { 0 };
                      uint32_t id_3173 { leb_ref_102[id_3172] };
                      Size id_3174 { Size(id_3173) };
                      uint8_t id_3175 { 0 };
                      Pointer id_3176 { p_ref_104[id_3175] };
                      ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_3177 { id_3174, id_3176 };
                      let_res_3144 = id_3177;
                    }
                    let_res_3140 = let_res_3144;
                  }
                  let_res_3137 = let_res_3140;
                }
                ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 let_res_3178;
                {
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_108 { let_res_3137 };
                  ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_3179;
                  {
                    auto dstring1_fst_109 { std::get<0>(dstring1_108) };
                    auto dstring1_snd_110 { std::get<1>(dstring1_108) };
                    ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_3180 { dstring1_snd_110.readBytes(dstring1_fst_109) };
                    ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_3181;
                    {
                      auto dstring2_fst_112 { std::get<0>(id_3180) };
                      auto dstring2_snd_113 { std::get<1>(id_3180) };
                      std::string id_3182 { dstring2_fst_112.toString() };
                      std::optional<std::string> id_3183 { id_3182 };
                      ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 id_3184 { id_3183, dstring2_snd_113 };
                      letpair_res_3181 = id_3184;
                    }
                    letpair_res_3179 = letpair_res_3181;
                  }
                  let_res_3178 = letpair_res_3179;
                }
                choose_res_3130 = let_res_3178;
              }
              ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c let_res_3185;
              {
                ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 dtup_117 { choose_res_3130 };
                ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c letpair_res_3186;
                {
                  auto dtup_fst_118 { std::get<0>(dtup_117) };
                  auto dtup_snd_119 { std::get<1>(dtup_117) };
                  auto fun3187 { dessser::gen::function_name::of_row_binary };
                  ::dessser::gen::raql_operation::t7ced0f6935c1265b26e1abfcc364f52e id_3188 { fun3187(dtup_snd_119) };
                  ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c letpair_res_3189;
                  {
                    auto dtup_fst_121 { std::get<0>(id_3188) };
                    auto dtup_snd_122 { std::get<1>(id_3188) };
                    ::dessser::gen::raql_operation::t0ca94dea84b5aab39c17a3e69f7dc2d6 id_3190 { dtup_fst_100, dtup_fst_118, dtup_fst_121 };
                    ::dessser::gen::raql_operation::data_source id_3191 { std::in_place_index<0>, id_3190 };
                    ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c id_3192 { id_3191, dtup_snd_122 };
                    letpair_res_3189 = id_3192;
                  }
                  letpair_res_3186 = letpair_res_3189;
                }
                let_res_3185 = letpair_res_3186;
              }
              letpair_res_3125 = let_res_3185;
            }
            let_res_3124 = letpair_res_3125;
          }
          choose_res_3057 = let_res_3124;
        } else {
          uint16_t id_3193 { 1 };
          bool id_3194 { bool(dsum1_fst_64 == id_3193) };
          Void id_3195 { ((void)(assert(id_3194)), ::dessser::Void()) };
          (void)id_3195;
          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3196 { of_row_binary(dsum1_snd_65) };
          ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c letpair_res_3197;
          {
            auto dsum2_fst_67 { std::get<0>(id_3196) };
            auto dsum2_snd_68 { std::get<1>(id_3196) };
            ::dessser::gen::raql_operation::data_source id_3198 { std::in_place_index<1>, dsum2_fst_67 };
            ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c id_3199 { id_3198, dsum2_snd_68 };
            letpair_res_3197 = id_3199;
          }
          choose_res_3057 = letpair_res_3197;
        }
        letpair_res_3054 = choose_res_3057;
      }
      let_res_3053 = letpair_res_3054;
    }
    return let_res_3053;
  }
   };
  return fun3049;
}
std::function<::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c(Pointer &)> data_source_of_row_binary(data_source_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_360" (let-pair "du16_fst_355" "du16_snd_356" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_355") (identifier "du16_snd_356")))
        (let-pair "dsum1_fst_361" "dsum1_snd_362" (identifier "dsum1_360")
          (if (eq (u16 0) (identifier "dsum1_fst_361"))
            (let "drec_483"
              (let-pair "dlist4_fst_481" "dlist4_snd_482"
                (let "dlist1_469"
                  (let "leb_ref_460" (make-vec (u32 0))
                    (let "shft_ref_461" (make-vec (u8 0))
                      (let "p_ref_462" (make-vec (identifier "dsum1_snd_362"))
                        (seq
                          (while
                            (let "leb128_463" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_462")))
                              (let-pair "leb128_fst_464" "leb128_snd_465" 
                                (identifier "leb128_463")
                                (seq (set-vec (u8 0) (identifier "p_ref_462") (identifier "leb128_snd_465"))
                                  (set-vec (u8 0) (identifier "leb_ref_460")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_464") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_461"))) (unsafe-nth (u8 0) (identifier "leb_ref_460"))))
                                  (set-vec (u8 0) (identifier "shft_ref_461") (add (unsafe-nth (u8 0) (identifier "shft_ref_461")) (u8 7))) 
                                  (ge (identifier "leb128_fst_464") (u8 128))))) 
                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_460")) (unsafe-nth (u8 0) (identifier "p_ref_462")))))))
                  (let-pair "dlist1_fst_470" "dlist1_snd_471" (identifier "dlist1_469")
                    (let "inits_src_ref_472" (make-vec (make-tup (end-of-list "$raql_select_field") (identifier "dlist1_snd_471")))
                      (seq
                        (let "repeat_n_473" (make-vec (i32 0))
                          (while (gt (to-i32 (identifier "dlist1_fst_470")) (unsafe-nth (u8 0) (identifier "repeat_n_473")))
                            (seq
                              (let "dlist2_474" (unsafe-nth (u8 0) (identifier "inits_src_ref_472"))
                                (let-pair "dlist2_fst_475" "dlist2_snd_476" 
                                  (identifier "dlist2_474")
                                  (set-vec (u8 0) (identifier "inits_src_ref_472")
                                    (let-pair "dlist3_fst_478" "dlist3_snd_479" 
                                      (apply (ext-identifier raql_select_field of-row-binary) (identifier "dlist2_snd_476"))
                                      (make-tup (cons (identifier "dlist3_fst_478") (identifier "dlist2_fst_475")) (identifier "dlist3_snd_479"))))))
                              (set-vec (u8 0) (identifier "repeat_n_473") (add (unsafe-nth (u8 0) (identifier "repeat_n_473")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "inits_src_ref_472")))))) 
                (make-tup (identity (identifier "dlist4_fst_481")) (identifier "dlist4_snd_482")))
              (let-pair "drec_fst_484" "drec_snd_485" (identifier "drec_483")
                (let "drec_512"
                  (if (eq (peek-u8 (identifier "drec_snd_485") (size 0)) (u8 1)) 
                    (make-tup (null "$field_name[[]]") (ptr-add (identifier "drec_snd_485") (size 1)))
                    (let-pair "dlist4_fst_507" "dlist4_snd_508"
                      (let "dlist1_495"
                        (let "leb_ref_486" (make-vec (u32 0))
                          (let "shft_ref_487" (make-vec (u8 0))
                            (let "p_ref_488" (make-vec (ptr-add (identifier "drec_snd_485") (size 1)))
                              (seq
                                (while
                                  (let "leb128_489" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_488")))
                                    (let-pair "leb128_fst_490" "leb128_snd_491" 
                                      (identifier "leb128_489")
                                      (seq (set-vec (u8 0) (identifier "p_ref_488") (identifier "leb128_snd_491"))
                                        (set-vec (u8 0) (identifier "leb_ref_486")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_490") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_487"))) (unsafe-nth (u8 0) (identifier "leb_ref_486"))))
                                        (set-vec (u8 0) (identifier "shft_ref_487") (add (unsafe-nth (u8 0) (identifier "shft_ref_487")) (u8 7))) 
                                        (ge (identifier "leb128_fst_490") (u8 128))))) 
                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_486")) (unsafe-nth (u8 0) (identifier "p_ref_488")))))))
                        (let-pair "dlist1_fst_496" "dlist1_snd_497" (identifier "dlist1_495")
                          (let "inits_src_ref_498" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_497")))
                            (seq
                              (let "repeat_n_499" (make-vec (i32 0))
                                (while (gt (to-i32 (identifier "dlist1_fst_496")) (unsafe-nth (u8 0) (identifier "repeat_n_499")))
                                  (seq
                                    (let "dlist2_500" (unsafe-nth (u8 0) (identifier "inits_src_ref_498"))
                                      (let-pair "dlist2_fst_501" "dlist2_snd_502" 
                                        (identifier "dlist2_500")
                                        (set-vec (u8 0) (identifier "inits_src_ref_498")
                                          (let-pair "dlist3_fst_504" "dlist3_snd_505" 
                                            (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_502"))
                                            (make-tup (cons (identifier "dlist3_fst_504") (identifier "dlist2_fst_501")) (identifier "dlist3_snd_505"))))))
                                    (set-vec (u8 0) (identifier "repeat_n_499") (add (unsafe-nth (u8 0) (identifier "repeat_n_499")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "inits_src_ref_498")))))) 
                      (make-tup (not-null (identity (identifier "dlist4_fst_507"))) (identifier "dlist4_snd_508"))))
                  (let-pair "drec_fst_513" "drec_snd_514" (identifier "drec_512")
                    (let "drec_556"
                      (if (eq (peek-u8 (identifier "drec_snd_514") (size 0)) (u8 1)) 
                        (make-tup (null "(U32; $raql_expr?; $raql_expr[[]])") (ptr-add (identifier "drec_snd_514") (size 1)))
                        (let "dtup_518" (let-pair "du32_fst_516" "du32_snd_517" (read-u32 little-endian (ptr-add (identifier "drec_snd_514") (size 1))) (make-tup (identifier "du32_fst_516") (identifier "du32_snd_517")))
                          (let-pair "dtup_fst_519" "dtup_snd_520" (identifier "dtup_518")
                            (let "dtup_524"
                              (if (eq (peek-u8 (identifier "dtup_snd_520") (size 0)) (u8 1)) 
                                (make-tup (null "$raql_expr") (ptr-add (identifier "dtup_snd_520") (size 1)))
                                (let-pair "make1_1_fst_522" "make1_1_snd_523" 
                                  (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "dtup_snd_520") (size 1))) 
                                  (make-tup (not-null (identifier "make1_1_fst_522")) (identifier "make1_1_snd_523"))))
                              (let-pair "dtup_fst_525" "dtup_snd_526" 
                                (identifier "dtup_524")
                                (let-pair "dlist4_fst_548" "dlist4_snd_549"
                                  (let "dlist1_536"
                                    (let "leb_ref_527" (make-vec (u32 0))
                                      (let "shft_ref_528" (make-vec (u8 0))
                                        (let "p_ref_529" (make-vec (identifier "dtup_snd_526"))
                                          (seq
                                            (while
                                              (let "leb128_530" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_529")))
                                                (let-pair "leb128_fst_531" "leb128_snd_532" 
                                                  (identifier "leb128_530")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_529") (identifier "leb128_snd_532"))
                                                    (set-vec (u8 0) (identifier "leb_ref_527")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_531") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_528"))) (unsafe-nth (u8 0) (identifier "leb_ref_527"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_528") (add (unsafe-nth (u8 0) (identifier "shft_ref_528")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_531") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_527")) (unsafe-nth (u8 0) (identifier "p_ref_529")))))))
                                    (let-pair "dlist1_fst_537" "dlist1_snd_538" 
                                      (identifier "dlist1_536")
                                      (let "inits_src_ref_539" (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_538")))
                                        (seq
                                          (let "repeat_n_540" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_537")) (unsafe-nth (u8 0) (identifier "repeat_n_540")))
                                              (seq
                                                (let "dlist2_541" (unsafe-nth (u8 0) (identifier "inits_src_ref_539"))
                                                  (let-pair "dlist2_fst_542" "dlist2_snd_543" 
                                                    (identifier "dlist2_541")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_539")
                                                      (let-pair "dlist3_fst_545" "dlist3_snd_546" 
                                                        (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_543"))
                                                        (make-tup (cons (identifier "dlist3_fst_545") (identifier "dlist2_fst_542")) (identifier "dlist3_snd_546"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_540") (add (unsafe-nth (u8 0) (identifier "repeat_n_540")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_539"))))))
                                  (make-tup (not-null (make-tup (identifier "dtup_fst_519") (identifier "dtup_fst_525") (identity (identifier "dlist4_fst_548")))) (identifier "dlist4_snd_549"))))))))
                      (let-pair "drec_fst_557" "drec_snd_558" (identifier "drec_556")
                        (let "drec_559" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_558"))
                          (let-pair "drec_fst_560" "drec_snd_561" (identifier "drec_559")
                            (let "drec_565"
                              (if (eq (peek-u8 (identifier "drec_snd_561") (size 0)) (u8 1)) 
                                (make-tup (null "$event_time") (ptr-add (identifier "drec_snd_561") (size 1)))
                                (let-pair "make1_1_fst_563" "make1_1_snd_564" 
                                  (apply (ext-identifier event_time of-row-binary) (ptr-add (identifier "drec_snd_561") (size 1))) 
                                  (make-tup (not-null (identifier "make1_1_fst_563")) (identifier "make1_1_snd_564"))))
                              (let-pair "drec_fst_566" "drec_snd_567" 
                                (identifier "drec_565")
                                (let "drec_591"
                                  (let-pair "dlist4_fst_589" "dlist4_snd_590"
                                    (let "dlist1_577"
                                      (let "leb_ref_568" (make-vec (u32 0))
                                        (let "shft_ref_569" (make-vec (u8 0))
                                          (let "p_ref_570" (make-vec (identifier "drec_snd_567"))
                                            (seq
                                              (while
                                                (let "leb128_571" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_570")))
                                                  (let-pair "leb128_fst_572" "leb128_snd_573" 
                                                    (identifier "leb128_571")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_570") (identifier "leb128_snd_573"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_568")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_572") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_569")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_568")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_569") (add (unsafe-nth (u8 0) (identifier "shft_ref_569")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_572") (u8 128))))) 
                                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_568")) (unsafe-nth (u8 0) (identifier "p_ref_570")))))))
                                      (let-pair "dlist1_fst_578" "dlist1_snd_579" 
                                        (identifier "dlist1_577")
                                        (let "inits_src_ref_580" (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_579")))
                                          (seq
                                            (let "repeat_n_581" (make-vec (i32 0))
                                              (while (gt (to-i32 (identifier "dlist1_fst_578")) (unsafe-nth (u8 0) (identifier "repeat_n_581")))
                                                (seq
                                                  (let "dlist2_582" (unsafe-nth (u8 0) (identifier "inits_src_ref_580"))
                                                    (let-pair "dlist2_fst_583" "dlist2_snd_584" 
                                                      (identifier "dlist2_582")
                                                      (set-vec (u8 0) 
                                                        (identifier "inits_src_ref_580")
                                                        (let-pair "dlist3_fst_586" "dlist3_snd_587" 
                                                          (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_584"))
                                                          (make-tup (cons (identifier "dlist3_fst_586") (identifier "dlist2_fst_583")) (identifier "dlist3_snd_587"))))))
                                                  (set-vec (u8 0) (identifier "repeat_n_581") (add (unsafe-nth (u8 0) (identifier "repeat_n_581")) (i32 1)))))) 
                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_580")))))) 
                                    (make-tup (identity (identifier "dlist4_fst_589")) (identifier "dlist4_snd_590")))
                                  (let-pair "drec_fst_592" "drec_snd_593" 
                                    (identifier "drec_591")
                                    (let "drec_617"
                                      (let-pair "dlist4_fst_615" "dlist4_snd_616"
                                        (let "dlist1_603"
                                          (let "leb_ref_594" (make-vec (u32 0))
                                            (let "shft_ref_595" (make-vec (u8 0))
                                              (let "p_ref_596" (make-vec (identifier "drec_snd_593"))
                                                (seq
                                                  (while
                                                    (let "leb128_597" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_596")))
                                                      (let-pair "leb128_fst_598" "leb128_snd_599" 
                                                        (identifier "leb128_597")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_596") (identifier "leb128_snd_599"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_594")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_598") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_595")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_594")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_595") (add (unsafe-nth (u8 0) (identifier "shft_ref_595")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_598") (u8 128))))) 
                                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_594")) (unsafe-nth (u8 0) (identifier "p_ref_596")))))))
                                          (let-pair "dlist1_fst_604" "dlist1_snd_605" 
                                            (identifier "dlist1_603")
                                            (let "inits_src_ref_606" 
                                              (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_605")))
                                              (seq
                                                (let "repeat_n_607" (make-vec (i32 0))
                                                  (while (gt (to-i32 (identifier "dlist1_fst_604")) (unsafe-nth (u8 0) (identifier "repeat_n_607")))
                                                    (seq
                                                      (let "dlist2_608" 
                                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_606"))
                                                        (let-pair "dlist2_fst_609" "dlist2_snd_610" 
                                                          (identifier "dlist2_608")
                                                          (set-vec (u8 0) 
                                                            (identifier "inits_src_ref_606")
                                                            (let-pair "dlist3_fst_612" "dlist3_snd_613" 
                                                              (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_610"))
                                                              (make-tup (cons (identifier "dlist3_fst_612") (identifier "dlist2_fst_609")) (identifier "dlist3_snd_613"))))))
                                                      (set-vec (u8 0) (identifier "repeat_n_607") (add (unsafe-nth (u8 0) (identifier "repeat_n_607")) (i32 1)))))) 
                                                (unsafe-nth (u8 0) (identifier "inits_src_ref_606")))))) 
                                        (make-tup (identity (identifier "dlist4_fst_615")) (identifier "dlist4_snd_616")))
                                      (let-pair "drec_fst_618" "drec_snd_619" 
                                        (identifier "drec_617")
                                        (let "drec_620" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_619"))
                                          (let-pair "drec_fst_621" "drec_snd_622" 
                                            (identifier "drec_620")
                                            (let "drec_626" (let-pair "dbool_fst_624" "dbool_snd_625" (read-u8 (identifier "drec_snd_622")) (make-tup (not (eq (identifier "dbool_fst_624") (u8 0))) (identifier "dbool_snd_625")))
                                              (let-pair "drec_fst_627" "drec_snd_628" 
                                                (identifier "drec_626")
                                                (let "drec_629" (apply (ext-identifier raql_flush_method of-row-binary) (identifier "drec_snd_628"))
                                                  (let-pair "drec_fst_630" "drec_snd_631" 
                                                    (identifier "drec_629")
                                                    (let "drec_655"
                                                      (let-pair "dlist4_fst_653" "dlist4_snd_654"
                                                        (let "dlist1_641"
                                                          (let "leb_ref_632" 
                                                            (make-vec (u32 0))
                                                            (let "shft_ref_633" 
                                                              (make-vec (u8 0))
                                                              (let "p_ref_634" 
                                                                (make-vec (identifier "drec_snd_631"))
                                                                (seq
                                                                  (while
                                                                    (let "leb128_635" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_634")))
                                                                    (let-pair "leb128_fst_636" "leb128_snd_637" 
                                                                    (identifier "leb128_635")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_634") (identifier "leb128_snd_637"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_632")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_636") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_633")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_632")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_633") (add (unsafe-nth (u8 0) (identifier "shft_ref_633")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_636") (u8 128))))) 
                                                                    (nop)) 
                                                                  (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_632")) (unsafe-nth (u8 0) (identifier "p_ref_634")))))))
                                                          (let-pair "dlist1_fst_642" "dlist1_snd_643" 
                                                            (identifier "dlist1_641")
                                                            (let "inits_src_ref_644"
                                                              (make-vec
                                                                (make-tup 
                                                                  (end-of-list "(data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])")
                                                                  (identifier "dlist1_snd_643")))
                                                              (seq
                                                                (let "repeat_n_645" 
                                                                  (make-vec (i32 0))
                                                                  (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_642")) (unsafe-nth (u8 0) (identifier "repeat_n_645")))
                                                                    (seq
                                                                    (let "dlist2_646" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_644"))
                                                                    (let-pair "dlist2_fst_647" "dlist2_snd_648" 
                                                                    (identifier "dlist2_646")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_644")
                                                                    (let-pair "dlist3_fst_650" "dlist3_snd_651" 
                                                                    (apply (identifier "data_source-of-row-binary") (identifier "dlist2_snd_648"))
                                                                    (make-tup (cons (identifier "dlist3_fst_650") (identifier "dlist2_fst_647")) (identifier "dlist3_snd_651"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_645") (add (unsafe-nth (u8 0) (identifier "repeat_n_645")) (i32 1))))))
                                                                (unsafe-nth (u8 0) (identifier "inits_src_ref_644")))))) 
                                                        (make-tup (identity (identifier "dlist4_fst_653")) (identifier "dlist4_snd_654")))
                                                      (let-pair "drec_fst_656" "drec_snd_657" 
                                                        (identifier "drec_655")
                                                        (let "drec_661"
                                                          (if (eq (peek-u8 (identifier "drec_snd_657") (size 0)) (u8 1)) 
                                                            (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_657") (size 1)))
                                                            (let-pair "make1_1_fst_659" "make1_1_snd_660" 
                                                              (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_657") (size 1)))
                                                              (make-tup (not-null (identifier "make1_1_fst_659")) (identifier "make1_1_snd_660"))))
                                                          (let-pair "drec_fst_662" "drec_snd_663" 
                                                            (identifier "drec_661")
                                                            (let-pair "dlist4_fst_685" "dlist4_snd_686"
                                                              (let "dlist1_673"
                                                                (let "leb_ref_664" 
                                                                  (make-vec (u32 0))
                                                                  (let "shft_ref_665" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_666" 
                                                                    (make-vec (identifier "drec_snd_663"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_667" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_666")))
                                                                    (let-pair "leb128_fst_668" "leb128_snd_669" 
                                                                    (identifier "leb128_667")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_666") (identifier "leb128_snd_669"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_664")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_668") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_665")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_664")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_665") (add (unsafe-nth (u8 0) (identifier "shft_ref_665")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_668") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_664")) (unsafe-nth (u8 0) (identifier "p_ref_666")))))))
                                                                (let-pair "dlist1_fst_674" "dlist1_snd_675" 
                                                                  (identifier "dlist1_673")
                                                                  (let "inits_src_ref_676" 
                                                                    (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_675")))
                                                                    (seq
                                                                    (let "repeat_n_677" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_674")) (unsafe-nth (u8 0) (identifier "repeat_n_677")))
                                                                    (seq
                                                                    (let "dlist2_678" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_676"))
                                                                    (let-pair "dlist2_fst_679" "dlist2_snd_680" 
                                                                    (identifier "dlist2_678")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_676")
                                                                    (let-pair "dlist3_fst_682" "dlist3_snd_683" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_680"))
                                                                    (make-tup (cons (identifier "dlist3_fst_682") (identifier "dlist2_fst_679")) (identifier "dlist3_snd_683"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_677") (add (unsafe-nth (u8 0) (identifier "repeat_n_677")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_676"))))))
                                                              (make-tup
                                                                (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; ip_proto: $raql_ip_protocol; proto: $raql_net_protocol; factors: $field_name[[]]}]" 0
                                                                  (make-rec 
                                                                    (string "factors") 
                                                                    (identity (identifier "dlist4_fst_685")) 
                                                                    (string "every") 
                                                                    (identifier "drec_fst_662") 
                                                                    (string "from") 
                                                                    (identifier "drec_fst_656") 
                                                                    (string "flush_how") 
                                                                    (identifier "drec_fst_630") 
                                                                    (string "commit_before") 
                                                                    (identifier "drec_fst_627") 
                                                                    (string "commit_cond") 
                                                                    (identifier "drec_fst_621") 
                                                                    (string "key") 
                                                                    (identifier "drec_fst_618") 
                                                                    (string "notifications") 
                                                                    (identifier "drec_fst_592") 
                                                                    (string "event_time") 
                                                                    (identifier "drec_fst_566") 
                                                                    (string "where") 
                                                                    (identifier "drec_fst_560") 
                                                                    (string "sort") 
                                                                    (identifier "drec_fst_557") 
                                                                    (string "and_all_others") 
                                                                    (identifier "drec_fst_513") 
                                                                    (string "fields") 
                                                                    (identifier "drec_fst_484"))) 
                                                                (identifier "dlist4_snd_686")))))))))))))))))))))))))))
            (if (eq (u16 1) (identifier "dsum1_fst_361"))
              (let "drec_419" (apply (identifier "external_source-of-row-binary") (identifier "dsum1_snd_362"))
                (let-pair "drec_fst_420" "drec_snd_421" (identifier "drec_419")
                  (let "drec_422" (apply (identifier "external_format-of-row-binary") (identifier "drec_snd_421"))
                    (let-pair "drec_fst_423" "drec_snd_424" (identifier "drec_422")
                      (let "drec_428"
                        (if (eq (peek-u8 (identifier "drec_snd_424") (size 0)) (u8 1)) 
                          (make-tup (null "$event_time") (ptr-add (identifier "drec_snd_424") (size 1)))
                          (let-pair "make1_1_fst_426" "make1_1_snd_427" 
                            (apply (ext-identifier event_time of-row-binary) (ptr-add (identifier "drec_snd_424") (size 1))) 
                            (make-tup (not-null (identifier "make1_1_fst_426")) (identifier "make1_1_snd_427"))))
                        (let-pair "drec_fst_429" "drec_snd_430" (identifier "drec_428")
                          (let-pair "dlist4_fst_452" "dlist4_snd_453"
                            (let "dlist1_440"
                              (let "leb_ref_431" (make-vec (u32 0))
                                (let "shft_ref_432" (make-vec (u8 0))
                                  (let "p_ref_433" (make-vec (identifier "drec_snd_430"))
                                    (seq
                                      (while
                                        (let "leb128_434" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_433")))
                                          (let-pair "leb128_fst_435" "leb128_snd_436" 
                                            (identifier "leb128_434")
                                            (seq (set-vec (u8 0) (identifier "p_ref_433") (identifier "leb128_snd_436"))
                                              (set-vec (u8 0) (identifier "leb_ref_431")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_435") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_432"))) (unsafe-nth (u8 0) (identifier "leb_ref_431"))))
                                              (set-vec (u8 0) (identifier "shft_ref_432") (add (unsafe-nth (u8 0) (identifier "shft_ref_432")) (u8 7))) 
                                              (ge (identifier "leb128_fst_435") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_431")) (unsafe-nth (u8 0) (identifier "p_ref_433")))))))
                              (let-pair "dlist1_fst_441" "dlist1_snd_442" 
                                (identifier "dlist1_440")
                                (let "inits_src_ref_443" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_442")))
                                  (seq
                                    (let "repeat_n_444" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_441")) (unsafe-nth (u8 0) (identifier "repeat_n_444")))
                                        (seq
                                          (let "dlist2_445" (unsafe-nth (u8 0) (identifier "inits_src_ref_443"))
                                            (let-pair "dlist2_fst_446" "dlist2_snd_447" 
                                              (identifier "dlist2_445")
                                              (set-vec (u8 0) (identifier "inits_src_ref_443")
                                                (let-pair "dlist3_fst_449" "dlist3_snd_450" 
                                                  (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_447"))
                                                  (make-tup (cons (identifier "dlist3_fst_449") (identifier "dlist2_fst_446")) (identifier "dlist3_snd_450"))))))
                                          (set-vec (u8 0) (identifier "repeat_n_444") (add (unsafe-nth (u8 0) (identifier "repeat_n_444")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_443"))))))
                            (make-tup
                              (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; ip_proto: $raql_ip_protocol; proto: $raql_net_protocol; factors: $field_name[[]]}]" 1
                                (make-rec (string "factors") (identity (identifier "dlist4_fst_452")) 
                                  (string "event_time") (identifier "drec_fst_429") 
                                  (string "format") (identifier "drec_fst_423") 
                                  (string "source") (identifier "drec_fst_420"))) 
                              (identifier "dlist4_snd_453")))))))))
              (seq (assert (eq (identifier "dsum1_fst_361") (u16 2)))
                (let "drec_375"
                  (let "dstring1_369"
                    (let "leb_ref_363" (make-vec (u32 0))
                      (let "shft_ref_364" (make-vec (u8 0))
                        (let "p_ref_365" (make-vec (identifier "dsum1_snd_362"))
                          (seq
                            (while
                              (let "leb128_366" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_365")))
                                (let-pair "leb128_fst_367" "leb128_snd_368" 
                                  (identifier "leb128_366")
                                  (seq (set-vec (u8 0) (identifier "p_ref_365") (identifier "leb128_snd_368"))
                                    (set-vec (u8 0) (identifier "leb_ref_363")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_367") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_364"))) (unsafe-nth (u8 0) (identifier "leb_ref_363"))))
                                    (set-vec (u8 0) (identifier "shft_ref_364") (add (unsafe-nth (u8 0) (identifier "shft_ref_364")) (u8 7))) 
                                    (ge (identifier "leb128_fst_367") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_363"))) (unsafe-nth (u8 0) (identifier "p_ref_365")))))))
                    (let-pair "dstring1_fst_370" "dstring1_snd_371" (identifier "dstring1_369")
                      (let-pair "dstring2_fst_373" "dstring2_snd_374" 
                        (read-bytes (identifier "dstring1_snd_371") (identifier "dstring1_fst_370")) 
                        (make-tup (string-of-bytes (identifier "dstring2_fst_373")) (identifier "dstring2_snd_374")))))
                  (let-pair "drec_fst_376" "drec_snd_377" (identifier "drec_375")
                    (let "drec_381" (let-pair "du16_fst_379" "du16_snd_380" (read-u16 little-endian (identifier "drec_snd_377")) (make-tup (identifier "du16_fst_379") (identifier "du16_snd_380")))
                      (let-pair "drec_fst_382" "drec_snd_383" (identifier "drec_381")
                        (let "drec_384" (apply (ext-identifier raql_ip_protocol of-row-binary) (identifier "drec_snd_383"))
                          (let-pair "drec_fst_385" "drec_snd_386" (identifier "drec_384")
                            (let "drec_387" (apply (ext-identifier raql_net_protocol of-row-binary) (identifier "drec_snd_386"))
                              (let-pair "drec_fst_388" "drec_snd_389" 
                                (identifier "drec_387")
                                (let-pair "dlist4_fst_411" "dlist4_snd_412"
                                  (let "dlist1_399"
                                    (let "leb_ref_390" (make-vec (u32 0))
                                      (let "shft_ref_391" (make-vec (u8 0))
                                        (let "p_ref_392" (make-vec (identifier "drec_snd_389"))
                                          (seq
                                            (while
                                              (let "leb128_393" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_392")))
                                                (let-pair "leb128_fst_394" "leb128_snd_395" 
                                                  (identifier "leb128_393")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_392") (identifier "leb128_snd_395"))
                                                    (set-vec (u8 0) (identifier "leb_ref_390")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_394") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_391"))) (unsafe-nth (u8 0) (identifier "leb_ref_390"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_391") (add (unsafe-nth (u8 0) (identifier "shft_ref_391")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_394") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_390")) (unsafe-nth (u8 0) (identifier "p_ref_392")))))))
                                    (let-pair "dlist1_fst_400" "dlist1_snd_401" 
                                      (identifier "dlist1_399")
                                      (let "inits_src_ref_402" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_401")))
                                        (seq
                                          (let "repeat_n_403" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_400")) (unsafe-nth (u8 0) (identifier "repeat_n_403")))
                                              (seq
                                                (let "dlist2_404" (unsafe-nth (u8 0) (identifier "inits_src_ref_402"))
                                                  (let-pair "dlist2_fst_405" "dlist2_snd_406" 
                                                    (identifier "dlist2_404")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_402")
                                                      (let-pair "dlist3_fst_408" "dlist3_snd_409" 
                                                        (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_406"))
                                                        (make-tup (cons (identifier "dlist3_fst_408") (identifier "dlist2_fst_405")) (identifier "dlist3_snd_409"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_403") (add (unsafe-nth (u8 0) (identifier "repeat_n_403")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_402"))))))
                                  (make-tup
                                    (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; ip_proto: $raql_ip_protocol; proto: $raql_net_protocol; factors: $field_name[[]]}]" 2
                                      (make-rec (string "factors") (identity (identifier "dlist4_fst_411")) 
                                        (string "proto") (identifier "drec_fst_388") 
                                        (string "ip_proto") (identifier "drec_fst_385") 
                                        (string "port") (identifier "drec_fst_382") 
                                        (string "net_addr") (identifier "drec_fst_376"))) 
                                    (identifier "dlist4_snd_412")))))))))))))))))
 */
static std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer &)> fun3200 { [&](Pointer p_0) {
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3201 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_3202;
    {
      auto du16_fst_355 { std::get<0>(id_3201) };
      auto du16_snd_356 { std::get<1>(id_3201) };
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3203 { du16_fst_355, du16_snd_356 };
      letpair_res_3202 = id_3203;
    }
    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3204;
    {
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_360 { letpair_res_3202 };
      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3205;
      {
        auto dsum1_fst_361 { std::get<0>(dsum1_360) };
        auto dsum1_snd_362 { std::get<1>(dsum1_360) };
        uint16_t id_3206 { 0 };
        bool id_3207 { bool(id_3206 == dsum1_fst_361) };
        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd choose_res_3208;
        if (id_3207) {
          uint32_t id_3209 { 0U };
          Vec<1, uint32_t> id_3210 {  id_3209  };
          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3211;
          {
            Vec<1, uint32_t> leb_ref_460 { id_3210 };
            uint8_t id_3212 { 0 };
            Vec<1, uint8_t> id_3213 {  id_3212  };
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3214;
            {
              Vec<1, uint8_t> shft_ref_461 { id_3213 };
              Vec<1, Pointer> id_3215 {  dsum1_snd_362  };
              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3216;
              {
                Vec<1, Pointer> p_ref_462 { id_3215 };
                bool while_flag_3217 { true };
                do {
                  uint8_t id_3218 { 0 };
                  Pointer id_3219 { p_ref_462[id_3218] };
                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3220 { id_3219.readU8() };
                  bool let_res_3221;
                  {
                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_463 { id_3220 };
                    bool letpair_res_3222;
                    {
                      auto leb128_fst_464 { std::get<0>(leb128_463) };
                      auto leb128_snd_465 { std::get<1>(leb128_463) };
                      uint8_t id_3223 { 0 };
                      Void id_3224 { ((void)(p_ref_462[id_3223] = leb128_snd_465), ::dessser::Void()) };
                      (void)id_3224;
                      uint8_t id_3225 { 0 };
                      uint8_t id_3226 { 127 };
                      uint8_t id_3227 { uint8_t(leb128_fst_464 & id_3226) };
                      uint32_t id_3228 { uint32_t(id_3227) };
                      uint8_t id_3229 { 0 };
                      uint8_t id_3230 { shft_ref_461[id_3229] };
                      uint32_t id_3231 { uint32_t(id_3228 << id_3230) };
                      uint8_t id_3232 { 0 };
                      uint32_t id_3233 { leb_ref_460[id_3232] };
                      uint32_t id_3234 { uint32_t(id_3231 | id_3233) };
                      Void id_3235 { ((void)(leb_ref_460[id_3225] = id_3234), ::dessser::Void()) };
                      (void)id_3235;
                      uint8_t id_3236 { 0 };
                      uint8_t id_3237 { 0 };
                      uint8_t id_3238 { shft_ref_461[id_3237] };
                      uint8_t id_3239 { 7 };
                      uint8_t id_3240 { uint8_t(id_3238 + id_3239) };
                      Void id_3241 { ((void)(shft_ref_461[id_3236] = id_3240), ::dessser::Void()) };
                      (void)id_3241;
                      uint8_t id_3242 { 128 };
                      bool id_3243 { bool(leb128_fst_464 >= id_3242) };
                      letpair_res_3222 = id_3243;
                    }
                    let_res_3221 = letpair_res_3222;
                  }
                  while_flag_3217 = let_res_3221;
                  if (while_flag_3217) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_3217);
                (void)::dessser::Void();
                uint8_t id_3244 { 0 };
                uint32_t id_3245 { leb_ref_460[id_3244] };
                uint8_t id_3246 { 0 };
                Pointer id_3247 { p_ref_462[id_3246] };
                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3248 { id_3245, id_3247 };
                let_res_3216 = id_3248;
              }
              let_res_3214 = let_res_3216;
            }
            let_res_3211 = let_res_3214;
          }
          ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d let_res_3249;
          {
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_469 { let_res_3211 };
            ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d letpair_res_3250;
            {
              auto dlist1_fst_470 { std::get<0>(dlist1_469) };
              auto dlist1_snd_471 { std::get<1>(dlist1_469) };
              Lst<dessser::gen::raql_select_field::t_ext> endoflist_3251;
              ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3252 { endoflist_3251, dlist1_snd_471 };
              Vec<1, ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d> id_3253 {  id_3252  };
              ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d let_res_3254;
              {
                Vec<1, ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d> inits_src_ref_472 { id_3253 };
                int32_t id_3255 { 0L };
                Vec<1, int32_t> id_3256 {  id_3255  };
                {
                  Vec<1, int32_t> repeat_n_473 { id_3256 };
                  bool while_flag_3257 { true };
                  do {
                    int32_t id_3258 { int32_t(dlist1_fst_470) };
                    uint8_t id_3259 { 0 };
                    int32_t id_3260 { repeat_n_473[id_3259] };
                    bool id_3261 { bool(id_3258 > id_3260) };
                    while_flag_3257 = id_3261;
                    if (while_flag_3257) {
                      uint8_t id_3262 { 0 };
                      ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3263 { inits_src_ref_472[id_3262] };
                      {
                        ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d dlist2_474 { id_3263 };
                        {
                          auto dlist2_fst_475 { std::get<0>(dlist2_474) };
                          auto dlist2_snd_476 { std::get<1>(dlist2_474) };
                          uint8_t id_3264 { 0 };
                          auto fun3265 { dessser::gen::raql_select_field::of_row_binary };
                          ::dessser::gen::raql_operation::t8ce288a7922f2eebd9fbfe87e5972d1b id_3266 { fun3265(dlist2_snd_476) };
                          ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d letpair_res_3267;
                          {
                            auto dlist3_fst_478 { std::get<0>(id_3266) };
                            auto dlist3_snd_479 { std::get<1>(id_3266) };
                            Lst<dessser::gen::raql_select_field::t_ext> id_3268 { dlist3_fst_478, dlist2_fst_475 };
                            ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3269 { id_3268, dlist3_snd_479 };
                            letpair_res_3267 = id_3269;
                          }
                          Void id_3270 { ((void)(inits_src_ref_472[id_3264] = letpair_res_3267), ::dessser::Void()) };
                          (void)id_3270;
                        }
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_3271 { 0 };
                      uint8_t id_3272 { 0 };
                      int32_t id_3273 { repeat_n_473[id_3272] };
                      int32_t id_3274 { 1L };
                      int32_t id_3275 { int32_t(id_3273 + id_3274) };
                      Void id_3276 { ((void)(repeat_n_473[id_3271] = id_3275), ::dessser::Void()) };
                      (void)id_3276;
                      (void)id_3276;
                    }
                  } while (while_flag_3257);
                  (void)::dessser::Void();
                }
                (void)::dessser::Void();
                uint8_t id_3277 { 0 };
                ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3278 { inits_src_ref_472[id_3277] };
                let_res_3254 = id_3278;
              }
              letpair_res_3250 = let_res_3254;
            }
            let_res_3249 = letpair_res_3250;
          }
          ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d letpair_res_3279;
          {
            auto dlist4_fst_481 { std::get<0>(let_res_3249) };
            auto dlist4_snd_482 { std::get<1>(let_res_3249) };
            ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3280 { dlist4_fst_481, dlist4_snd_482 };
            letpair_res_3279 = id_3280;
          }
          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3281;
          {
            ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d drec_483 { letpair_res_3279 };
            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3282;
            {
              auto drec_fst_484 { std::get<0>(drec_483) };
              auto drec_snd_485 { std::get<1>(drec_483) };
              Size id_3283 { 0UL };
              uint8_t id_3284 { drec_snd_485.peekU8(id_3283) };
              uint8_t id_3285 { 1 };
              bool id_3286 { bool(id_3284 == id_3285) };
              ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 choose_res_3287;
              if (id_3286) {
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_3288 { std::nullopt };
                Size id_3289 { 1UL };
                Pointer id_3290 { drec_snd_485.skip(id_3289) };
                ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 id_3291 { id_3288, id_3290 };
                choose_res_3287 = id_3291;
              } else {
                uint32_t id_3292 { 0U };
                Vec<1, uint32_t> id_3293 {  id_3292  };
                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3294;
                {
                  Vec<1, uint32_t> leb_ref_486 { id_3293 };
                  uint8_t id_3295 { 0 };
                  Vec<1, uint8_t> id_3296 {  id_3295  };
                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3297;
                  {
                    Vec<1, uint8_t> shft_ref_487 { id_3296 };
                    Size id_3298 { 1UL };
                    Pointer id_3299 { drec_snd_485.skip(id_3298) };
                    Vec<1, Pointer> id_3300 {  id_3299  };
                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3301;
                    {
                      Vec<1, Pointer> p_ref_488 { id_3300 };
                      bool while_flag_3302 { true };
                      do {
                        uint8_t id_3303 { 0 };
                        Pointer id_3304 { p_ref_488[id_3303] };
                        ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3305 { id_3304.readU8() };
                        bool let_res_3306;
                        {
                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_489 { id_3305 };
                          bool letpair_res_3307;
                          {
                            auto leb128_fst_490 { std::get<0>(leb128_489) };
                            auto leb128_snd_491 { std::get<1>(leb128_489) };
                            uint8_t id_3308 { 0 };
                            Void id_3309 { ((void)(p_ref_488[id_3308] = leb128_snd_491), ::dessser::Void()) };
                            (void)id_3309;
                            uint8_t id_3310 { 0 };
                            uint8_t id_3311 { 127 };
                            uint8_t id_3312 { uint8_t(leb128_fst_490 & id_3311) };
                            uint32_t id_3313 { uint32_t(id_3312) };
                            uint8_t id_3314 { 0 };
                            uint8_t id_3315 { shft_ref_487[id_3314] };
                            uint32_t id_3316 { uint32_t(id_3313 << id_3315) };
                            uint8_t id_3317 { 0 };
                            uint32_t id_3318 { leb_ref_486[id_3317] };
                            uint32_t id_3319 { uint32_t(id_3316 | id_3318) };
                            Void id_3320 { ((void)(leb_ref_486[id_3310] = id_3319), ::dessser::Void()) };
                            (void)id_3320;
                            uint8_t id_3321 { 0 };
                            uint8_t id_3322 { 0 };
                            uint8_t id_3323 { shft_ref_487[id_3322] };
                            uint8_t id_3324 { 7 };
                            uint8_t id_3325 { uint8_t(id_3323 + id_3324) };
                            Void id_3326 { ((void)(shft_ref_487[id_3321] = id_3325), ::dessser::Void()) };
                            (void)id_3326;
                            uint8_t id_3327 { 128 };
                            bool id_3328 { bool(leb128_fst_490 >= id_3327) };
                            letpair_res_3307 = id_3328;
                          }
                          let_res_3306 = letpair_res_3307;
                        }
                        while_flag_3302 = let_res_3306;
                        if (while_flag_3302) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_3302);
                      (void)::dessser::Void();
                      uint8_t id_3329 { 0 };
                      uint32_t id_3330 { leb_ref_486[id_3329] };
                      uint8_t id_3331 { 0 };
                      Pointer id_3332 { p_ref_488[id_3331] };
                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3333 { id_3330, id_3332 };
                      let_res_3301 = id_3333;
                    }
                    let_res_3297 = let_res_3301;
                  }
                  let_res_3294 = let_res_3297;
                }
                ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3334;
                {
                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_495 { let_res_3294 };
                  ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3335;
                  {
                    auto dlist1_fst_496 { std::get<0>(dlist1_495) };
                    auto dlist1_snd_497 { std::get<1>(dlist1_495) };
                    Lst<dessser::gen::field_name::t_ext> endoflist_3336;
                    ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3337 { endoflist_3336, dlist1_snd_497 };
                    Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_3338 {  id_3337  };
                    ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3339;
                    {
                      Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_498 { id_3338 };
                      int32_t id_3340 { 0L };
                      Vec<1, int32_t> id_3341 {  id_3340  };
                      {
                        Vec<1, int32_t> repeat_n_499 { id_3341 };
                        bool while_flag_3342 { true };
                        do {
                          int32_t id_3343 { int32_t(dlist1_fst_496) };
                          uint8_t id_3344 { 0 };
                          int32_t id_3345 { repeat_n_499[id_3344] };
                          bool id_3346 { bool(id_3343 > id_3345) };
                          while_flag_3342 = id_3346;
                          if (while_flag_3342) {
                            uint8_t id_3347 { 0 };
                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3348 { inits_src_ref_498[id_3347] };
                            {
                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_500 { id_3348 };
                              {
                                auto dlist2_fst_501 { std::get<0>(dlist2_500) };
                                auto dlist2_snd_502 { std::get<1>(dlist2_500) };
                                uint8_t id_3349 { 0 };
                                auto fun3350 { dessser::gen::field_name::of_row_binary };
                                ::dessser::gen::raql_operation::t18cecf882d7ac80cef37dfe6b22279d4 id_3351 { fun3350(dlist2_snd_502) };
                                ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3352;
                                {
                                  auto dlist3_fst_504 { std::get<0>(id_3351) };
                                  auto dlist3_snd_505 { std::get<1>(id_3351) };
                                  Lst<dessser::gen::field_name::t_ext> id_3353 { dlist3_fst_504, dlist2_fst_501 };
                                  ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3354 { id_3353, dlist3_snd_505 };
                                  letpair_res_3352 = id_3354;
                                }
                                Void id_3355 { ((void)(inits_src_ref_498[id_3349] = letpair_res_3352), ::dessser::Void()) };
                                (void)id_3355;
                              }
                              (void)::dessser::Void();
                            }
                            (void)::dessser::Void();
                            uint8_t id_3356 { 0 };
                            uint8_t id_3357 { 0 };
                            int32_t id_3358 { repeat_n_499[id_3357] };
                            int32_t id_3359 { 1L };
                            int32_t id_3360 { int32_t(id_3358 + id_3359) };
                            Void id_3361 { ((void)(repeat_n_499[id_3356] = id_3360), ::dessser::Void()) };
                            (void)id_3361;
                            (void)id_3361;
                          }
                        } while (while_flag_3342);
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_3362 { 0 };
                      ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3363 { inits_src_ref_498[id_3362] };
                      let_res_3339 = id_3363;
                    }
                    letpair_res_3335 = let_res_3339;
                  }
                  let_res_3334 = letpair_res_3335;
                }
                ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 letpair_res_3364;
                {
                  auto dlist4_fst_507 { std::get<0>(let_res_3334) };
                  auto dlist4_snd_508 { std::get<1>(let_res_3334) };
                  std::optional<Lst<dessser::gen::field_name::t_ext>> id_3365 { dlist4_fst_507 };
                  ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 id_3366 { id_3365, dlist4_snd_508 };
                  letpair_res_3364 = id_3366;
                }
                choose_res_3287 = letpair_res_3364;
              }
              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3367;
              {
                ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 drec_512 { choose_res_3287 };
                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3368;
                {
                  auto drec_fst_513 { std::get<0>(drec_512) };
                  auto drec_snd_514 { std::get<1>(drec_512) };
                  Size id_3369 { 0UL };
                  uint8_t id_3370 { drec_snd_514.peekU8(id_3369) };
                  uint8_t id_3371 { 1 };
                  bool id_3372 { bool(id_3370 == id_3371) };
                  ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 choose_res_3373;
                  if (id_3372) {
                    std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_3374 { std::nullopt };
                    Size id_3375 { 1UL };
                    Pointer id_3376 { drec_snd_514.skip(id_3375) };
                    ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 id_3377 { id_3374, id_3376 };
                    choose_res_3373 = id_3377;
                  } else {
                    Size id_3378 { 1UL };
                    Pointer id_3379 { drec_snd_514.skip(id_3378) };
                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3380 { id_3379.readU32Le() };
                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 letpair_res_3381;
                    {
                      auto du32_fst_516 { std::get<0>(id_3380) };
                      auto du32_snd_517 { std::get<1>(id_3380) };
                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3382 { du32_fst_516, du32_snd_517 };
                      letpair_res_3381 = id_3382;
                    }
                    ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 let_res_3383;
                    {
                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dtup_518 { letpair_res_3381 };
                      ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 letpair_res_3384;
                      {
                        auto dtup_fst_519 { std::get<0>(dtup_518) };
                        auto dtup_snd_520 { std::get<1>(dtup_518) };
                        Size id_3385 { 0UL };
                        uint8_t id_3386 { dtup_snd_520.peekU8(id_3385) };
                        uint8_t id_3387 { 1 };
                        bool id_3388 { bool(id_3386 == id_3387) };
                        ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 choose_res_3389;
                        if (id_3388) {
                          std::optional<dessser::gen::raql_expr::t_ext> id_3390 { std::nullopt };
                          Size id_3391 { 1UL };
                          Pointer id_3392 { dtup_snd_520.skip(id_3391) };
                          ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_3393 { id_3390, id_3392 };
                          choose_res_3389 = id_3393;
                        } else {
                          auto fun3394 { dessser::gen::raql_expr::of_row_binary };
                          Size id_3395 { 1UL };
                          Pointer id_3396 { dtup_snd_520.skip(id_3395) };
                          ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3397 { fun3394(id_3396) };
                          ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 letpair_res_3398;
                          {
                            auto make1_1_fst_522 { std::get<0>(id_3397) };
                            auto make1_1_snd_523 { std::get<1>(id_3397) };
                            std::optional<dessser::gen::raql_expr::t_ext> id_3399 { make1_1_fst_522 };
                            ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_3400 { id_3399, make1_1_snd_523 };
                            letpair_res_3398 = id_3400;
                          }
                          choose_res_3389 = letpair_res_3398;
                        }
                        ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 let_res_3401;
                        {
                          ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 dtup_524 { choose_res_3389 };
                          ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 letpair_res_3402;
                          {
                            auto dtup_fst_525 { std::get<0>(dtup_524) };
                            auto dtup_snd_526 { std::get<1>(dtup_524) };
                            uint32_t id_3403 { 0U };
                            Vec<1, uint32_t> id_3404 {  id_3403  };
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3405;
                            {
                              Vec<1, uint32_t> leb_ref_527 { id_3404 };
                              uint8_t id_3406 { 0 };
                              Vec<1, uint8_t> id_3407 {  id_3406  };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3408;
                              {
                                Vec<1, uint8_t> shft_ref_528 { id_3407 };
                                Vec<1, Pointer> id_3409 {  dtup_snd_526  };
                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3410;
                                {
                                  Vec<1, Pointer> p_ref_529 { id_3409 };
                                  bool while_flag_3411 { true };
                                  do {
                                    uint8_t id_3412 { 0 };
                                    Pointer id_3413 { p_ref_529[id_3412] };
                                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3414 { id_3413.readU8() };
                                    bool let_res_3415;
                                    {
                                      ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_530 { id_3414 };
                                      bool letpair_res_3416;
                                      {
                                        auto leb128_fst_531 { std::get<0>(leb128_530) };
                                        auto leb128_snd_532 { std::get<1>(leb128_530) };
                                        uint8_t id_3417 { 0 };
                                        Void id_3418 { ((void)(p_ref_529[id_3417] = leb128_snd_532), ::dessser::Void()) };
                                        (void)id_3418;
                                        uint8_t id_3419 { 0 };
                                        uint8_t id_3420 { 127 };
                                        uint8_t id_3421 { uint8_t(leb128_fst_531 & id_3420) };
                                        uint32_t id_3422 { uint32_t(id_3421) };
                                        uint8_t id_3423 { 0 };
                                        uint8_t id_3424 { shft_ref_528[id_3423] };
                                        uint32_t id_3425 { uint32_t(id_3422 << id_3424) };
                                        uint8_t id_3426 { 0 };
                                        uint32_t id_3427 { leb_ref_527[id_3426] };
                                        uint32_t id_3428 { uint32_t(id_3425 | id_3427) };
                                        Void id_3429 { ((void)(leb_ref_527[id_3419] = id_3428), ::dessser::Void()) };
                                        (void)id_3429;
                                        uint8_t id_3430 { 0 };
                                        uint8_t id_3431 { 0 };
                                        uint8_t id_3432 { shft_ref_528[id_3431] };
                                        uint8_t id_3433 { 7 };
                                        uint8_t id_3434 { uint8_t(id_3432 + id_3433) };
                                        Void id_3435 { ((void)(shft_ref_528[id_3430] = id_3434), ::dessser::Void()) };
                                        (void)id_3435;
                                        uint8_t id_3436 { 128 };
                                        bool id_3437 { bool(leb128_fst_531 >= id_3436) };
                                        letpair_res_3416 = id_3437;
                                      }
                                      let_res_3415 = letpair_res_3416;
                                    }
                                    while_flag_3411 = let_res_3415;
                                    if (while_flag_3411) {
                                      (void)::dessser::Void();
                                    }
                                  } while (while_flag_3411);
                                  (void)::dessser::Void();
                                  uint8_t id_3438 { 0 };
                                  uint32_t id_3439 { leb_ref_527[id_3438] };
                                  uint8_t id_3440 { 0 };
                                  Pointer id_3441 { p_ref_529[id_3440] };
                                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3442 { id_3439, id_3441 };
                                  let_res_3410 = id_3442;
                                }
                                let_res_3408 = let_res_3410;
                              }
                              let_res_3405 = let_res_3408;
                            }
                            ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3443;
                            {
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_536 { let_res_3405 };
                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3444;
                              {
                                auto dlist1_fst_537 { std::get<0>(dlist1_536) };
                                auto dlist1_snd_538 { std::get<1>(dlist1_536) };
                                Lst<dessser::gen::raql_expr::t_ext> endoflist_3445;
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3446 { endoflist_3445, dlist1_snd_538 };
                                Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> id_3447 {  id_3446  };
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3448;
                                {
                                  Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> inits_src_ref_539 { id_3447 };
                                  int32_t id_3449 { 0L };
                                  Vec<1, int32_t> id_3450 {  id_3449  };
                                  {
                                    Vec<1, int32_t> repeat_n_540 { id_3450 };
                                    bool while_flag_3451 { true };
                                    do {
                                      int32_t id_3452 { int32_t(dlist1_fst_537) };
                                      uint8_t id_3453 { 0 };
                                      int32_t id_3454 { repeat_n_540[id_3453] };
                                      bool id_3455 { bool(id_3452 > id_3454) };
                                      while_flag_3451 = id_3455;
                                      if (while_flag_3451) {
                                        uint8_t id_3456 { 0 };
                                        ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3457 { inits_src_ref_539[id_3456] };
                                        {
                                          ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 dlist2_541 { id_3457 };
                                          {
                                            auto dlist2_fst_542 { std::get<0>(dlist2_541) };
                                            auto dlist2_snd_543 { std::get<1>(dlist2_541) };
                                            uint8_t id_3458 { 0 };
                                            auto fun3459 { dessser::gen::raql_expr::of_row_binary };
                                            ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3460 { fun3459(dlist2_snd_543) };
                                            ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3461;
                                            {
                                              auto dlist3_fst_545 { std::get<0>(id_3460) };
                                              auto dlist3_snd_546 { std::get<1>(id_3460) };
                                              Lst<dessser::gen::raql_expr::t_ext> id_3462 { dlist3_fst_545, dlist2_fst_542 };
                                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3463 { id_3462, dlist3_snd_546 };
                                              letpair_res_3461 = id_3463;
                                            }
                                            Void id_3464 { ((void)(inits_src_ref_539[id_3458] = letpair_res_3461), ::dessser::Void()) };
                                            (void)id_3464;
                                          }
                                          (void)::dessser::Void();
                                        }
                                        (void)::dessser::Void();
                                        uint8_t id_3465 { 0 };
                                        uint8_t id_3466 { 0 };
                                        int32_t id_3467 { repeat_n_540[id_3466] };
                                        int32_t id_3468 { 1L };
                                        int32_t id_3469 { int32_t(id_3467 + id_3468) };
                                        Void id_3470 { ((void)(repeat_n_540[id_3465] = id_3469), ::dessser::Void()) };
                                        (void)id_3470;
                                        (void)id_3470;
                                      }
                                    } while (while_flag_3451);
                                    (void)::dessser::Void();
                                  }
                                  (void)::dessser::Void();
                                  uint8_t id_3471 { 0 };
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3472 { inits_src_ref_539[id_3471] };
                                  let_res_3448 = id_3472;
                                }
                                letpair_res_3444 = let_res_3448;
                              }
                              let_res_3443 = letpair_res_3444;
                            }
                            ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 letpair_res_3473;
                            {
                              auto dlist4_fst_548 { std::get<0>(let_res_3443) };
                              auto dlist4_snd_549 { std::get<1>(let_res_3443) };
                              ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_3474 { dtup_fst_519, dtup_fst_525, dlist4_fst_548 };
                              std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_3475 { id_3474 };
                              ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 id_3476 { id_3475, dlist4_snd_549 };
                              letpair_res_3473 = id_3476;
                            }
                            letpair_res_3402 = letpair_res_3473;
                          }
                          let_res_3401 = letpair_res_3402;
                        }
                        letpair_res_3384 = let_res_3401;
                      }
                      let_res_3383 = letpair_res_3384;
                    }
                    choose_res_3373 = let_res_3383;
                  }
                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3477;
                  {
                    ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 drec_556 { choose_res_3373 };
                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3478;
                    {
                      auto drec_fst_557 { std::get<0>(drec_556) };
                      auto drec_snd_558 { std::get<1>(drec_556) };
                      auto fun3479 { dessser::gen::raql_expr::of_row_binary };
                      ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3480 { fun3479(drec_snd_558) };
                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3481;
                      {
                        ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_559 { id_3480 };
                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3482;
                        {
                          auto drec_fst_560 { std::get<0>(drec_559) };
                          auto drec_snd_561 { std::get<1>(drec_559) };
                          Size id_3483 { 0UL };
                          uint8_t id_3484 { drec_snd_561.peekU8(id_3483) };
                          uint8_t id_3485 { 1 };
                          bool id_3486 { bool(id_3484 == id_3485) };
                          ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 choose_res_3487;
                          if (id_3486) {
                            std::optional<dessser::gen::event_time::t_ext> id_3488 { std::nullopt };
                            Size id_3489 { 1UL };
                            Pointer id_3490 { drec_snd_561.skip(id_3489) };
                            ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 id_3491 { id_3488, id_3490 };
                            choose_res_3487 = id_3491;
                          } else {
                            auto fun3492 { dessser::gen::event_time::of_row_binary };
                            Size id_3493 { 1UL };
                            Pointer id_3494 { drec_snd_561.skip(id_3493) };
                            ::dessser::gen::raql_operation::t6402d827f30fdf794bf052c6e2db3344 id_3495 { fun3492(id_3494) };
                            ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 letpair_res_3496;
                            {
                              auto make1_1_fst_563 { std::get<0>(id_3495) };
                              auto make1_1_snd_564 { std::get<1>(id_3495) };
                              std::optional<dessser::gen::event_time::t_ext> id_3497 { make1_1_fst_563 };
                              ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 id_3498 { id_3497, make1_1_snd_564 };
                              letpair_res_3496 = id_3498;
                            }
                            choose_res_3487 = letpair_res_3496;
                          }
                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3499;
                          {
                            ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 drec_565 { choose_res_3487 };
                            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3500;
                            {
                              auto drec_fst_566 { std::get<0>(drec_565) };
                              auto drec_snd_567 { std::get<1>(drec_565) };
                              uint32_t id_3501 { 0U };
                              Vec<1, uint32_t> id_3502 {  id_3501  };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3503;
                              {
                                Vec<1, uint32_t> leb_ref_568 { id_3502 };
                                uint8_t id_3504 { 0 };
                                Vec<1, uint8_t> id_3505 {  id_3504  };
                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3506;
                                {
                                  Vec<1, uint8_t> shft_ref_569 { id_3505 };
                                  Vec<1, Pointer> id_3507 {  drec_snd_567  };
                                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3508;
                                  {
                                    Vec<1, Pointer> p_ref_570 { id_3507 };
                                    bool while_flag_3509 { true };
                                    do {
                                      uint8_t id_3510 { 0 };
                                      Pointer id_3511 { p_ref_570[id_3510] };
                                      ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3512 { id_3511.readU8() };
                                      bool let_res_3513;
                                      {
                                        ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_571 { id_3512 };
                                        bool letpair_res_3514;
                                        {
                                          auto leb128_fst_572 { std::get<0>(leb128_571) };
                                          auto leb128_snd_573 { std::get<1>(leb128_571) };
                                          uint8_t id_3515 { 0 };
                                          Void id_3516 { ((void)(p_ref_570[id_3515] = leb128_snd_573), ::dessser::Void()) };
                                          (void)id_3516;
                                          uint8_t id_3517 { 0 };
                                          uint8_t id_3518 { 127 };
                                          uint8_t id_3519 { uint8_t(leb128_fst_572 & id_3518) };
                                          uint32_t id_3520 { uint32_t(id_3519) };
                                          uint8_t id_3521 { 0 };
                                          uint8_t id_3522 { shft_ref_569[id_3521] };
                                          uint32_t id_3523 { uint32_t(id_3520 << id_3522) };
                                          uint8_t id_3524 { 0 };
                                          uint32_t id_3525 { leb_ref_568[id_3524] };
                                          uint32_t id_3526 { uint32_t(id_3523 | id_3525) };
                                          Void id_3527 { ((void)(leb_ref_568[id_3517] = id_3526), ::dessser::Void()) };
                                          (void)id_3527;
                                          uint8_t id_3528 { 0 };
                                          uint8_t id_3529 { 0 };
                                          uint8_t id_3530 { shft_ref_569[id_3529] };
                                          uint8_t id_3531 { 7 };
                                          uint8_t id_3532 { uint8_t(id_3530 + id_3531) };
                                          Void id_3533 { ((void)(shft_ref_569[id_3528] = id_3532), ::dessser::Void()) };
                                          (void)id_3533;
                                          uint8_t id_3534 { 128 };
                                          bool id_3535 { bool(leb128_fst_572 >= id_3534) };
                                          letpair_res_3514 = id_3535;
                                        }
                                        let_res_3513 = letpair_res_3514;
                                      }
                                      while_flag_3509 = let_res_3513;
                                      if (while_flag_3509) {
                                        (void)::dessser::Void();
                                      }
                                    } while (while_flag_3509);
                                    (void)::dessser::Void();
                                    uint8_t id_3536 { 0 };
                                    uint32_t id_3537 { leb_ref_568[id_3536] };
                                    uint8_t id_3538 { 0 };
                                    Pointer id_3539 { p_ref_570[id_3538] };
                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3540 { id_3537, id_3539 };
                                    let_res_3508 = id_3540;
                                  }
                                  let_res_3506 = let_res_3508;
                                }
                                let_res_3503 = let_res_3506;
                              }
                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3541;
                              {
                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_577 { let_res_3503 };
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3542;
                                {
                                  auto dlist1_fst_578 { std::get<0>(dlist1_577) };
                                  auto dlist1_snd_579 { std::get<1>(dlist1_577) };
                                  Lst<dessser::gen::raql_expr::t_ext> endoflist_3543;
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3544 { endoflist_3543, dlist1_snd_579 };
                                  Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> id_3545 {  id_3544  };
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3546;
                                  {
                                    Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> inits_src_ref_580 { id_3545 };
                                    int32_t id_3547 { 0L };
                                    Vec<1, int32_t> id_3548 {  id_3547  };
                                    {
                                      Vec<1, int32_t> repeat_n_581 { id_3548 };
                                      bool while_flag_3549 { true };
                                      do {
                                        int32_t id_3550 { int32_t(dlist1_fst_578) };
                                        uint8_t id_3551 { 0 };
                                        int32_t id_3552 { repeat_n_581[id_3551] };
                                        bool id_3553 { bool(id_3550 > id_3552) };
                                        while_flag_3549 = id_3553;
                                        if (while_flag_3549) {
                                          uint8_t id_3554 { 0 };
                                          ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3555 { inits_src_ref_580[id_3554] };
                                          {
                                            ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 dlist2_582 { id_3555 };
                                            {
                                              auto dlist2_fst_583 { std::get<0>(dlist2_582) };
                                              auto dlist2_snd_584 { std::get<1>(dlist2_582) };
                                              uint8_t id_3556 { 0 };
                                              auto fun3557 { dessser::gen::raql_expr::of_row_binary };
                                              ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3558 { fun3557(dlist2_snd_584) };
                                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3559;
                                              {
                                                auto dlist3_fst_586 { std::get<0>(id_3558) };
                                                auto dlist3_snd_587 { std::get<1>(id_3558) };
                                                Lst<dessser::gen::raql_expr::t_ext> id_3560 { dlist3_fst_586, dlist2_fst_583 };
                                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3561 { id_3560, dlist3_snd_587 };
                                                letpair_res_3559 = id_3561;
                                              }
                                              Void id_3562 { ((void)(inits_src_ref_580[id_3556] = letpair_res_3559), ::dessser::Void()) };
                                              (void)id_3562;
                                            }
                                            (void)::dessser::Void();
                                          }
                                          (void)::dessser::Void();
                                          uint8_t id_3563 { 0 };
                                          uint8_t id_3564 { 0 };
                                          int32_t id_3565 { repeat_n_581[id_3564] };
                                          int32_t id_3566 { 1L };
                                          int32_t id_3567 { int32_t(id_3565 + id_3566) };
                                          Void id_3568 { ((void)(repeat_n_581[id_3563] = id_3567), ::dessser::Void()) };
                                          (void)id_3568;
                                          (void)id_3568;
                                        }
                                      } while (while_flag_3549);
                                      (void)::dessser::Void();
                                    }
                                    (void)::dessser::Void();
                                    uint8_t id_3569 { 0 };
                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3570 { inits_src_ref_580[id_3569] };
                                    let_res_3546 = id_3570;
                                  }
                                  letpair_res_3542 = let_res_3546;
                                }
                                let_res_3541 = letpair_res_3542;
                              }
                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3571;
                              {
                                auto dlist4_fst_589 { std::get<0>(let_res_3541) };
                                auto dlist4_snd_590 { std::get<1>(let_res_3541) };
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3572 { dlist4_fst_589, dlist4_snd_590 };
                                letpair_res_3571 = id_3572;
                              }
                              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3573;
                              {
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 drec_591 { letpair_res_3571 };
                                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3574;
                                {
                                  auto drec_fst_592 { std::get<0>(drec_591) };
                                  auto drec_snd_593 { std::get<1>(drec_591) };
                                  uint32_t id_3575 { 0U };
                                  Vec<1, uint32_t> id_3576 {  id_3575  };
                                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3577;
                                  {
                                    Vec<1, uint32_t> leb_ref_594 { id_3576 };
                                    uint8_t id_3578 { 0 };
                                    Vec<1, uint8_t> id_3579 {  id_3578  };
                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3580;
                                    {
                                      Vec<1, uint8_t> shft_ref_595 { id_3579 };
                                      Vec<1, Pointer> id_3581 {  drec_snd_593  };
                                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3582;
                                      {
                                        Vec<1, Pointer> p_ref_596 { id_3581 };
                                        bool while_flag_3583 { true };
                                        do {
                                          uint8_t id_3584 { 0 };
                                          Pointer id_3585 { p_ref_596[id_3584] };
                                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3586 { id_3585.readU8() };
                                          bool let_res_3587;
                                          {
                                            ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_597 { id_3586 };
                                            bool letpair_res_3588;
                                            {
                                              auto leb128_fst_598 { std::get<0>(leb128_597) };
                                              auto leb128_snd_599 { std::get<1>(leb128_597) };
                                              uint8_t id_3589 { 0 };
                                              Void id_3590 { ((void)(p_ref_596[id_3589] = leb128_snd_599), ::dessser::Void()) };
                                              (void)id_3590;
                                              uint8_t id_3591 { 0 };
                                              uint8_t id_3592 { 127 };
                                              uint8_t id_3593 { uint8_t(leb128_fst_598 & id_3592) };
                                              uint32_t id_3594 { uint32_t(id_3593) };
                                              uint8_t id_3595 { 0 };
                                              uint8_t id_3596 { shft_ref_595[id_3595] };
                                              uint32_t id_3597 { uint32_t(id_3594 << id_3596) };
                                              uint8_t id_3598 { 0 };
                                              uint32_t id_3599 { leb_ref_594[id_3598] };
                                              uint32_t id_3600 { uint32_t(id_3597 | id_3599) };
                                              Void id_3601 { ((void)(leb_ref_594[id_3591] = id_3600), ::dessser::Void()) };
                                              (void)id_3601;
                                              uint8_t id_3602 { 0 };
                                              uint8_t id_3603 { 0 };
                                              uint8_t id_3604 { shft_ref_595[id_3603] };
                                              uint8_t id_3605 { 7 };
                                              uint8_t id_3606 { uint8_t(id_3604 + id_3605) };
                                              Void id_3607 { ((void)(shft_ref_595[id_3602] = id_3606), ::dessser::Void()) };
                                              (void)id_3607;
                                              uint8_t id_3608 { 128 };
                                              bool id_3609 { bool(leb128_fst_598 >= id_3608) };
                                              letpair_res_3588 = id_3609;
                                            }
                                            let_res_3587 = letpair_res_3588;
                                          }
                                          while_flag_3583 = let_res_3587;
                                          if (while_flag_3583) {
                                            (void)::dessser::Void();
                                          }
                                        } while (while_flag_3583);
                                        (void)::dessser::Void();
                                        uint8_t id_3610 { 0 };
                                        uint32_t id_3611 { leb_ref_594[id_3610] };
                                        uint8_t id_3612 { 0 };
                                        Pointer id_3613 { p_ref_596[id_3612] };
                                        ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3614 { id_3611, id_3613 };
                                        let_res_3582 = id_3614;
                                      }
                                      let_res_3580 = let_res_3582;
                                    }
                                    let_res_3577 = let_res_3580;
                                  }
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3615;
                                  {
                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_603 { let_res_3577 };
                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3616;
                                    {
                                      auto dlist1_fst_604 { std::get<0>(dlist1_603) };
                                      auto dlist1_snd_605 { std::get<1>(dlist1_603) };
                                      Lst<dessser::gen::raql_expr::t_ext> endoflist_3617;
                                      ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3618 { endoflist_3617, dlist1_snd_605 };
                                      Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> id_3619 {  id_3618  };
                                      ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3620;
                                      {
                                        Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> inits_src_ref_606 { id_3619 };
                                        int32_t id_3621 { 0L };
                                        Vec<1, int32_t> id_3622 {  id_3621  };
                                        {
                                          Vec<1, int32_t> repeat_n_607 { id_3622 };
                                          bool while_flag_3623 { true };
                                          do {
                                            int32_t id_3624 { int32_t(dlist1_fst_604) };
                                            uint8_t id_3625 { 0 };
                                            int32_t id_3626 { repeat_n_607[id_3625] };
                                            bool id_3627 { bool(id_3624 > id_3626) };
                                            while_flag_3623 = id_3627;
                                            if (while_flag_3623) {
                                              uint8_t id_3628 { 0 };
                                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3629 { inits_src_ref_606[id_3628] };
                                              {
                                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 dlist2_608 { id_3629 };
                                                {
                                                  auto dlist2_fst_609 { std::get<0>(dlist2_608) };
                                                  auto dlist2_snd_610 { std::get<1>(dlist2_608) };
                                                  uint8_t id_3630 { 0 };
                                                  auto fun3631 { dessser::gen::raql_expr::of_row_binary };
                                                  ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3632 { fun3631(dlist2_snd_610) };
                                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3633;
                                                  {
                                                    auto dlist3_fst_612 { std::get<0>(id_3632) };
                                                    auto dlist3_snd_613 { std::get<1>(id_3632) };
                                                    Lst<dessser::gen::raql_expr::t_ext> id_3634 { dlist3_fst_612, dlist2_fst_609 };
                                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3635 { id_3634, dlist3_snd_613 };
                                                    letpair_res_3633 = id_3635;
                                                  }
                                                  Void id_3636 { ((void)(inits_src_ref_606[id_3630] = letpair_res_3633), ::dessser::Void()) };
                                                  (void)id_3636;
                                                }
                                                (void)::dessser::Void();
                                              }
                                              (void)::dessser::Void();
                                              uint8_t id_3637 { 0 };
                                              uint8_t id_3638 { 0 };
                                              int32_t id_3639 { repeat_n_607[id_3638] };
                                              int32_t id_3640 { 1L };
                                              int32_t id_3641 { int32_t(id_3639 + id_3640) };
                                              Void id_3642 { ((void)(repeat_n_607[id_3637] = id_3641), ::dessser::Void()) };
                                              (void)id_3642;
                                              (void)id_3642;
                                            }
                                          } while (while_flag_3623);
                                          (void)::dessser::Void();
                                        }
                                        (void)::dessser::Void();
                                        uint8_t id_3643 { 0 };
                                        ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3644 { inits_src_ref_606[id_3643] };
                                        let_res_3620 = id_3644;
                                      }
                                      letpair_res_3616 = let_res_3620;
                                    }
                                    let_res_3615 = letpair_res_3616;
                                  }
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3645;
                                  {
                                    auto dlist4_fst_615 { std::get<0>(let_res_3615) };
                                    auto dlist4_snd_616 { std::get<1>(let_res_3615) };
                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3646 { dlist4_fst_615, dlist4_snd_616 };
                                    letpair_res_3645 = id_3646;
                                  }
                                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3647;
                                  {
                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 drec_617 { letpair_res_3645 };
                                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3648;
                                    {
                                      auto drec_fst_618 { std::get<0>(drec_617) };
                                      auto drec_snd_619 { std::get<1>(drec_617) };
                                      auto fun3649 { dessser::gen::raql_expr::of_row_binary };
                                      ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3650 { fun3649(drec_snd_619) };
                                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3651;
                                      {
                                        ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_620 { id_3650 };
                                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3652;
                                        {
                                          auto drec_fst_621 { std::get<0>(drec_620) };
                                          auto drec_snd_622 { std::get<1>(drec_620) };
                                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3653 { drec_snd_622.readU8() };
                                          ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_3654;
                                          {
                                            auto dbool_fst_624 { std::get<0>(id_3653) };
                                            auto dbool_snd_625 { std::get<1>(id_3653) };
                                            uint8_t id_3655 { 0 };
                                            bool id_3656 { bool(dbool_fst_624 == id_3655) };
                                            bool id_3657 { ! id_3656 };
                                            ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 id_3658 { id_3657, dbool_snd_625 };
                                            letpair_res_3654 = id_3658;
                                          }
                                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3659;
                                          {
                                            ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 drec_626 { letpair_res_3654 };
                                            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3660;
                                            {
                                              auto drec_fst_627 { std::get<0>(drec_626) };
                                              auto drec_snd_628 { std::get<1>(drec_626) };
                                              auto fun3661 { dessser::gen::raql_flush_method::of_row_binary };
                                              ::dessser::gen::raql_operation::t810ce2c2364cf512ac90f670b999da7d id_3662 { fun3661(drec_snd_628) };
                                              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3663;
                                              {
                                                ::dessser::gen::raql_operation::t810ce2c2364cf512ac90f670b999da7d drec_629 { id_3662 };
                                                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3664;
                                                {
                                                  auto drec_fst_630 { std::get<0>(drec_629) };
                                                  auto drec_snd_631 { std::get<1>(drec_629) };
                                                  uint32_t id_3665 { 0U };
                                                  Vec<1, uint32_t> id_3666 {  id_3665  };
                                                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3667;
                                                  {
                                                    Vec<1, uint32_t> leb_ref_632 { id_3666 };
                                                    uint8_t id_3668 { 0 };
                                                    Vec<1, uint8_t> id_3669 {  id_3668  };
                                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3670;
                                                    {
                                                      Vec<1, uint8_t> shft_ref_633 { id_3669 };
                                                      Vec<1, Pointer> id_3671 {  drec_snd_631  };
                                                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3672;
                                                      {
                                                        Vec<1, Pointer> p_ref_634 { id_3671 };
                                                        bool while_flag_3673 { true };
                                                        do {
                                                          uint8_t id_3674 { 0 };
                                                          Pointer id_3675 { p_ref_634[id_3674] };
                                                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3676 { id_3675.readU8() };
                                                          bool let_res_3677;
                                                          {
                                                            ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_635 { id_3676 };
                                                            bool letpair_res_3678;
                                                            {
                                                              auto leb128_fst_636 { std::get<0>(leb128_635) };
                                                              auto leb128_snd_637 { std::get<1>(leb128_635) };
                                                              uint8_t id_3679 { 0 };
                                                              Void id_3680 { ((void)(p_ref_634[id_3679] = leb128_snd_637), ::dessser::Void()) };
                                                              (void)id_3680;
                                                              uint8_t id_3681 { 0 };
                                                              uint8_t id_3682 { 127 };
                                                              uint8_t id_3683 { uint8_t(leb128_fst_636 & id_3682) };
                                                              uint32_t id_3684 { uint32_t(id_3683) };
                                                              uint8_t id_3685 { 0 };
                                                              uint8_t id_3686 { shft_ref_633[id_3685] };
                                                              uint32_t id_3687 { uint32_t(id_3684 << id_3686) };
                                                              uint8_t id_3688 { 0 };
                                                              uint32_t id_3689 { leb_ref_632[id_3688] };
                                                              uint32_t id_3690 { uint32_t(id_3687 | id_3689) };
                                                              Void id_3691 { ((void)(leb_ref_632[id_3681] = id_3690), ::dessser::Void()) };
                                                              (void)id_3691;
                                                              uint8_t id_3692 { 0 };
                                                              uint8_t id_3693 { 0 };
                                                              uint8_t id_3694 { shft_ref_633[id_3693] };
                                                              uint8_t id_3695 { 7 };
                                                              uint8_t id_3696 { uint8_t(id_3694 + id_3695) };
                                                              Void id_3697 { ((void)(shft_ref_633[id_3692] = id_3696), ::dessser::Void()) };
                                                              (void)id_3697;
                                                              uint8_t id_3698 { 128 };
                                                              bool id_3699 { bool(leb128_fst_636 >= id_3698) };
                                                              letpair_res_3678 = id_3699;
                                                            }
                                                            let_res_3677 = letpair_res_3678;
                                                          }
                                                          while_flag_3673 = let_res_3677;
                                                          if (while_flag_3673) {
                                                            (void)::dessser::Void();
                                                          }
                                                        } while (while_flag_3673);
                                                        (void)::dessser::Void();
                                                        uint8_t id_3700 { 0 };
                                                        uint32_t id_3701 { leb_ref_632[id_3700] };
                                                        uint8_t id_3702 { 0 };
                                                        Pointer id_3703 { p_ref_634[id_3702] };
                                                        ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3704 { id_3701, id_3703 };
                                                        let_res_3672 = id_3704;
                                                      }
                                                      let_res_3670 = let_res_3672;
                                                    }
                                                    let_res_3667 = let_res_3670;
                                                  }
                                                  ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 let_res_3705;
                                                  {
                                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_641 { let_res_3667 };
                                                    ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 letpair_res_3706;
                                                    {
                                                      auto dlist1_fst_642 { std::get<0>(dlist1_641) };
                                                      auto dlist1_snd_643 { std::get<1>(dlist1_641) };
                                                      Lst<::dessser::gen::raql_operation::data_source> endoflist_3707;
                                                      ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 id_3708 { endoflist_3707, dlist1_snd_643 };
                                                      Vec<1, ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59> id_3709 {  id_3708  };
                                                      ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 let_res_3710;
                                                      {
                                                        Vec<1, ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59> inits_src_ref_644 { id_3709 };
                                                        int32_t id_3711 { 0L };
                                                        Vec<1, int32_t> id_3712 {  id_3711  };
                                                        {
                                                          Vec<1, int32_t> repeat_n_645 { id_3712 };
                                                          bool while_flag_3713 { true };
                                                          do {
                                                            int32_t id_3714 { int32_t(dlist1_fst_642) };
                                                            uint8_t id_3715 { 0 };
                                                            int32_t id_3716 { repeat_n_645[id_3715] };
                                                            bool id_3717 { bool(id_3714 > id_3716) };
                                                            while_flag_3713 = id_3717;
                                                            if (while_flag_3713) {
                                                              uint8_t id_3718 { 0 };
                                                              ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 id_3719 { inits_src_ref_644[id_3718] };
                                                              {
                                                                ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 dlist2_646 { id_3719 };
                                                                {
                                                                  auto dlist2_fst_647 { std::get<0>(dlist2_646) };
                                                                  auto dlist2_snd_648 { std::get<1>(dlist2_646) };
                                                                  uint8_t id_3720 { 0 };
                                                                  ::dessser::gen::raql_operation::t040f327c301430239c5fa4296312592c id_3721 { data_source_of_row_binary(dlist2_snd_648) };
                                                                  ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 letpair_res_3722;
                                                                  {
                                                                    auto dlist3_fst_650 { std::get<0>(id_3721) };
                                                                    auto dlist3_snd_651 { std::get<1>(id_3721) };
                                                                    Lst<::dessser::gen::raql_operation::data_source> id_3723 { dlist3_fst_650, dlist2_fst_647 };
                                                                    ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 id_3724 { id_3723, dlist3_snd_651 };
                                                                    letpair_res_3722 = id_3724;
                                                                  }
                                                                  Void id_3725 { ((void)(inits_src_ref_644[id_3720] = letpair_res_3722), ::dessser::Void()) };
                                                                  (void)id_3725;
                                                                }
                                                                (void)::dessser::Void();
                                                              }
                                                              (void)::dessser::Void();
                                                              uint8_t id_3726 { 0 };
                                                              uint8_t id_3727 { 0 };
                                                              int32_t id_3728 { repeat_n_645[id_3727] };
                                                              int32_t id_3729 { 1L };
                                                              int32_t id_3730 { int32_t(id_3728 + id_3729) };
                                                              Void id_3731 { ((void)(repeat_n_645[id_3726] = id_3730), ::dessser::Void()) };
                                                              (void)id_3731;
                                                              (void)id_3731;
                                                            }
                                                          } while (while_flag_3713);
                                                          (void)::dessser::Void();
                                                        }
                                                        (void)::dessser::Void();
                                                        uint8_t id_3732 { 0 };
                                                        ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 id_3733 { inits_src_ref_644[id_3732] };
                                                        let_res_3710 = id_3733;
                                                      }
                                                      letpair_res_3706 = let_res_3710;
                                                    }
                                                    let_res_3705 = letpair_res_3706;
                                                  }
                                                  ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 letpair_res_3734;
                                                  {
                                                    auto dlist4_fst_653 { std::get<0>(let_res_3705) };
                                                    auto dlist4_snd_654 { std::get<1>(let_res_3705) };
                                                    ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 id_3735 { dlist4_fst_653, dlist4_snd_654 };
                                                    letpair_res_3734 = id_3735;
                                                  }
                                                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3736;
                                                  {
                                                    ::dessser::gen::raql_operation::tbcf6a3aa37d854ac0cc9f4cc183dcc59 drec_655 { letpair_res_3734 };
                                                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3737;
                                                    {
                                                      auto drec_fst_656 { std::get<0>(drec_655) };
                                                      auto drec_snd_657 { std::get<1>(drec_655) };
                                                      Size id_3738 { 0UL };
                                                      uint8_t id_3739 { drec_snd_657.peekU8(id_3738) };
                                                      uint8_t id_3740 { 1 };
                                                      bool id_3741 { bool(id_3739 == id_3740) };
                                                      ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 choose_res_3742;
                                                      if (id_3741) {
                                                        std::optional<dessser::gen::raql_expr::t_ext> id_3743 { std::nullopt };
                                                        Size id_3744 { 1UL };
                                                        Pointer id_3745 { drec_snd_657.skip(id_3744) };
                                                        ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_3746 { id_3743, id_3745 };
                                                        choose_res_3742 = id_3746;
                                                      } else {
                                                        auto fun3747 { dessser::gen::raql_expr::of_row_binary };
                                                        Size id_3748 { 1UL };
                                                        Pointer id_3749 { drec_snd_657.skip(id_3748) };
                                                        ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3750 { fun3747(id_3749) };
                                                        ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 letpair_res_3751;
                                                        {
                                                          auto make1_1_fst_659 { std::get<0>(id_3750) };
                                                          auto make1_1_snd_660 { std::get<1>(id_3750) };
                                                          std::optional<dessser::gen::raql_expr::t_ext> id_3752 { make1_1_fst_659 };
                                                          ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_3753 { id_3752, make1_1_snd_660 };
                                                          letpair_res_3751 = id_3753;
                                                        }
                                                        choose_res_3742 = letpair_res_3751;
                                                      }
                                                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3754;
                                                      {
                                                        ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 drec_661 { choose_res_3742 };
                                                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3755;
                                                        {
                                                          auto drec_fst_662 { std::get<0>(drec_661) };
                                                          auto drec_snd_663 { std::get<1>(drec_661) };
                                                          uint32_t id_3756 { 0U };
                                                          Vec<1, uint32_t> id_3757 {  id_3756  };
                                                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3758;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_664 { id_3757 };
                                                            uint8_t id_3759 { 0 };
                                                            Vec<1, uint8_t> id_3760 {  id_3759  };
                                                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3761;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_665 { id_3760 };
                                                              Vec<1, Pointer> id_3762 {  drec_snd_663  };
                                                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3763;
                                                              {
                                                                Vec<1, Pointer> p_ref_666 { id_3762 };
                                                                bool while_flag_3764 { true };
                                                                do {
                                                                  uint8_t id_3765 { 0 };
                                                                  Pointer id_3766 { p_ref_666[id_3765] };
                                                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3767 { id_3766.readU8() };
                                                                  bool let_res_3768;
                                                                  {
                                                                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_667 { id_3767 };
                                                                    bool letpair_res_3769;
                                                                    {
                                                                      auto leb128_fst_668 { std::get<0>(leb128_667) };
                                                                      auto leb128_snd_669 { std::get<1>(leb128_667) };
                                                                      uint8_t id_3770 { 0 };
                                                                      Void id_3771 { ((void)(p_ref_666[id_3770] = leb128_snd_669), ::dessser::Void()) };
                                                                      (void)id_3771;
                                                                      uint8_t id_3772 { 0 };
                                                                      uint8_t id_3773 { 127 };
                                                                      uint8_t id_3774 { uint8_t(leb128_fst_668 & id_3773) };
                                                                      uint32_t id_3775 { uint32_t(id_3774) };
                                                                      uint8_t id_3776 { 0 };
                                                                      uint8_t id_3777 { shft_ref_665[id_3776] };
                                                                      uint32_t id_3778 { uint32_t(id_3775 << id_3777) };
                                                                      uint8_t id_3779 { 0 };
                                                                      uint32_t id_3780 { leb_ref_664[id_3779] };
                                                                      uint32_t id_3781 { uint32_t(id_3778 | id_3780) };
                                                                      Void id_3782 { ((void)(leb_ref_664[id_3772] = id_3781), ::dessser::Void()) };
                                                                      (void)id_3782;
                                                                      uint8_t id_3783 { 0 };
                                                                      uint8_t id_3784 { 0 };
                                                                      uint8_t id_3785 { shft_ref_665[id_3784] };
                                                                      uint8_t id_3786 { 7 };
                                                                      uint8_t id_3787 { uint8_t(id_3785 + id_3786) };
                                                                      Void id_3788 { ((void)(shft_ref_665[id_3783] = id_3787), ::dessser::Void()) };
                                                                      (void)id_3788;
                                                                      uint8_t id_3789 { 128 };
                                                                      bool id_3790 { bool(leb128_fst_668 >= id_3789) };
                                                                      letpair_res_3769 = id_3790;
                                                                    }
                                                                    let_res_3768 = letpair_res_3769;
                                                                  }
                                                                  while_flag_3764 = let_res_3768;
                                                                  if (while_flag_3764) {
                                                                    (void)::dessser::Void();
                                                                  }
                                                                } while (while_flag_3764);
                                                                (void)::dessser::Void();
                                                                uint8_t id_3791 { 0 };
                                                                uint32_t id_3792 { leb_ref_664[id_3791] };
                                                                uint8_t id_3793 { 0 };
                                                                Pointer id_3794 { p_ref_666[id_3793] };
                                                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3795 { id_3792, id_3794 };
                                                                let_res_3763 = id_3795;
                                                              }
                                                              let_res_3761 = let_res_3763;
                                                            }
                                                            let_res_3758 = let_res_3761;
                                                          }
                                                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3796;
                                                          {
                                                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_673 { let_res_3758 };
                                                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3797;
                                                            {
                                                              auto dlist1_fst_674 { std::get<0>(dlist1_673) };
                                                              auto dlist1_snd_675 { std::get<1>(dlist1_673) };
                                                              Lst<dessser::gen::field_name::t_ext> endoflist_3798;
                                                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3799 { endoflist_3798, dlist1_snd_675 };
                                                              Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_3800 {  id_3799  };
                                                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3801;
                                                              {
                                                                Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_676 { id_3800 };
                                                                int32_t id_3802 { 0L };
                                                                Vec<1, int32_t> id_3803 {  id_3802  };
                                                                {
                                                                  Vec<1, int32_t> repeat_n_677 { id_3803 };
                                                                  bool while_flag_3804 { true };
                                                                  do {
                                                                    int32_t id_3805 { int32_t(dlist1_fst_674) };
                                                                    uint8_t id_3806 { 0 };
                                                                    int32_t id_3807 { repeat_n_677[id_3806] };
                                                                    bool id_3808 { bool(id_3805 > id_3807) };
                                                                    while_flag_3804 = id_3808;
                                                                    if (while_flag_3804) {
                                                                      uint8_t id_3809 { 0 };
                                                                      ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3810 { inits_src_ref_676[id_3809] };
                                                                      {
                                                                        ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_678 { id_3810 };
                                                                        {
                                                                          auto dlist2_fst_679 { std::get<0>(dlist2_678) };
                                                                          auto dlist2_snd_680 { std::get<1>(dlist2_678) };
                                                                          uint8_t id_3811 { 0 };
                                                                          auto fun3812 { dessser::gen::field_name::of_row_binary };
                                                                          ::dessser::gen::raql_operation::t18cecf882d7ac80cef37dfe6b22279d4 id_3813 { fun3812(dlist2_snd_680) };
                                                                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3814;
                                                                          {
                                                                            auto dlist3_fst_682 { std::get<0>(id_3813) };
                                                                            auto dlist3_snd_683 { std::get<1>(id_3813) };
                                                                            Lst<dessser::gen::field_name::t_ext> id_3815 { dlist3_fst_682, dlist2_fst_679 };
                                                                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3816 { id_3815, dlist3_snd_683 };
                                                                            letpair_res_3814 = id_3816;
                                                                          }
                                                                          Void id_3817 { ((void)(inits_src_ref_676[id_3811] = letpair_res_3814), ::dessser::Void()) };
                                                                          (void)id_3817;
                                                                        }
                                                                        (void)::dessser::Void();
                                                                      }
                                                                      (void)::dessser::Void();
                                                                      uint8_t id_3818 { 0 };
                                                                      uint8_t id_3819 { 0 };
                                                                      int32_t id_3820 { repeat_n_677[id_3819] };
                                                                      int32_t id_3821 { 1L };
                                                                      int32_t id_3822 { int32_t(id_3820 + id_3821) };
                                                                      Void id_3823 { ((void)(repeat_n_677[id_3818] = id_3822), ::dessser::Void()) };
                                                                      (void)id_3823;
                                                                      (void)id_3823;
                                                                    }
                                                                  } while (while_flag_3804);
                                                                  (void)::dessser::Void();
                                                                }
                                                                (void)::dessser::Void();
                                                                uint8_t id_3824 { 0 };
                                                                ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3825 { inits_src_ref_676[id_3824] };
                                                                let_res_3801 = id_3825;
                                                              }
                                                              letpair_res_3797 = let_res_3801;
                                                            }
                                                            let_res_3796 = letpair_res_3797;
                                                          }
                                                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3826;
                                                          {
                                                            auto dlist4_fst_685 { std::get<0>(let_res_3796) };
                                                            auto dlist4_snd_686 { std::get<1>(let_res_3796) };
                                                            ::dessser::gen::raql_operation::t58a57ec09888f557d57bf4376ca44b24 id_3827 { drec_fst_484, drec_fst_513, drec_fst_557, drec_fst_560, drec_fst_566, drec_fst_592, drec_fst_618, drec_fst_621, drec_fst_627, drec_fst_630, drec_fst_656, drec_fst_662, dlist4_fst_685 };
                                                            std::shared_ptr<::dessser::gen::raql_operation::t>  id_3828 { std::make_shared<::dessser::gen::raql_operation::t>(std::in_place_index<0>, id_3827) };
                                                            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3829 { id_3828, dlist4_snd_686 };
                                                            letpair_res_3826 = id_3829;
                                                          }
                                                          letpair_res_3755 = letpair_res_3826;
                                                        }
                                                        let_res_3754 = letpair_res_3755;
                                                      }
                                                      letpair_res_3737 = let_res_3754;
                                                    }
                                                    let_res_3736 = letpair_res_3737;
                                                  }
                                                  letpair_res_3664 = let_res_3736;
                                                }
                                                let_res_3663 = letpair_res_3664;
                                              }
                                              letpair_res_3660 = let_res_3663;
                                            }
                                            let_res_3659 = letpair_res_3660;
                                          }
                                          letpair_res_3652 = let_res_3659;
                                        }
                                        let_res_3651 = letpair_res_3652;
                                      }
                                      letpair_res_3648 = let_res_3651;
                                    }
                                    let_res_3647 = letpair_res_3648;
                                  }
                                  letpair_res_3574 = let_res_3647;
                                }
                                let_res_3573 = letpair_res_3574;
                              }
                              letpair_res_3500 = let_res_3573;
                            }
                            let_res_3499 = letpair_res_3500;
                          }
                          letpair_res_3482 = let_res_3499;
                        }
                        let_res_3481 = letpair_res_3482;
                      }
                      letpair_res_3478 = let_res_3481;
                    }
                    let_res_3477 = letpair_res_3478;
                  }
                  letpair_res_3368 = let_res_3477;
                }
                let_res_3367 = letpair_res_3368;
              }
              letpair_res_3282 = let_res_3367;
            }
            let_res_3281 = letpair_res_3282;
          }
          choose_res_3208 = let_res_3281;
        } else {
          uint16_t id_3830 { 1 };
          bool id_3831 { bool(id_3830 == dsum1_fst_361) };
          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd choose_res_3832;
          if (id_3831) {
            ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 id_3833 { external_source_of_row_binary(dsum1_snd_362) };
            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3834;
            {
              ::dessser::gen::raql_operation::t6005154d7547b64400cf202525298d69 drec_419 { id_3833 };
              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3835;
              {
                auto drec_fst_420 { std::get<0>(drec_419) };
                auto drec_snd_421 { std::get<1>(drec_419) };
                ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 id_3836 { external_format_of_row_binary(drec_snd_421) };
                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3837;
                {
                  ::dessser::gen::raql_operation::t451e3326ef72e0df775e9ee8e2a61bf4 drec_422 { id_3836 };
                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3838;
                  {
                    auto drec_fst_423 { std::get<0>(drec_422) };
                    auto drec_snd_424 { std::get<1>(drec_422) };
                    Size id_3839 { 0UL };
                    uint8_t id_3840 { drec_snd_424.peekU8(id_3839) };
                    uint8_t id_3841 { 1 };
                    bool id_3842 { bool(id_3840 == id_3841) };
                    ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 choose_res_3843;
                    if (id_3842) {
                      std::optional<dessser::gen::event_time::t_ext> id_3844 { std::nullopt };
                      Size id_3845 { 1UL };
                      Pointer id_3846 { drec_snd_424.skip(id_3845) };
                      ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 id_3847 { id_3844, id_3846 };
                      choose_res_3843 = id_3847;
                    } else {
                      auto fun3848 { dessser::gen::event_time::of_row_binary };
                      Size id_3849 { 1UL };
                      Pointer id_3850 { drec_snd_424.skip(id_3849) };
                      ::dessser::gen::raql_operation::t6402d827f30fdf794bf052c6e2db3344 id_3851 { fun3848(id_3850) };
                      ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 letpair_res_3852;
                      {
                        auto make1_1_fst_426 { std::get<0>(id_3851) };
                        auto make1_1_snd_427 { std::get<1>(id_3851) };
                        std::optional<dessser::gen::event_time::t_ext> id_3853 { make1_1_fst_426 };
                        ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 id_3854 { id_3853, make1_1_snd_427 };
                        letpair_res_3852 = id_3854;
                      }
                      choose_res_3843 = letpair_res_3852;
                    }
                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3855;
                    {
                      ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 drec_428 { choose_res_3843 };
                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3856;
                      {
                        auto drec_fst_429 { std::get<0>(drec_428) };
                        auto drec_snd_430 { std::get<1>(drec_428) };
                        uint32_t id_3857 { 0U };
                        Vec<1, uint32_t> id_3858 {  id_3857  };
                        ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3859;
                        {
                          Vec<1, uint32_t> leb_ref_431 { id_3858 };
                          uint8_t id_3860 { 0 };
                          Vec<1, uint8_t> id_3861 {  id_3860  };
                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3862;
                          {
                            Vec<1, uint8_t> shft_ref_432 { id_3861 };
                            Vec<1, Pointer> id_3863 {  drec_snd_430  };
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3864;
                            {
                              Vec<1, Pointer> p_ref_433 { id_3863 };
                              bool while_flag_3865 { true };
                              do {
                                uint8_t id_3866 { 0 };
                                Pointer id_3867 { p_ref_433[id_3866] };
                                ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3868 { id_3867.readU8() };
                                bool let_res_3869;
                                {
                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_434 { id_3868 };
                                  bool letpair_res_3870;
                                  {
                                    auto leb128_fst_435 { std::get<0>(leb128_434) };
                                    auto leb128_snd_436 { std::get<1>(leb128_434) };
                                    uint8_t id_3871 { 0 };
                                    Void id_3872 { ((void)(p_ref_433[id_3871] = leb128_snd_436), ::dessser::Void()) };
                                    (void)id_3872;
                                    uint8_t id_3873 { 0 };
                                    uint8_t id_3874 { 127 };
                                    uint8_t id_3875 { uint8_t(leb128_fst_435 & id_3874) };
                                    uint32_t id_3876 { uint32_t(id_3875) };
                                    uint8_t id_3877 { 0 };
                                    uint8_t id_3878 { shft_ref_432[id_3877] };
                                    uint32_t id_3879 { uint32_t(id_3876 << id_3878) };
                                    uint8_t id_3880 { 0 };
                                    uint32_t id_3881 { leb_ref_431[id_3880] };
                                    uint32_t id_3882 { uint32_t(id_3879 | id_3881) };
                                    Void id_3883 { ((void)(leb_ref_431[id_3873] = id_3882), ::dessser::Void()) };
                                    (void)id_3883;
                                    uint8_t id_3884 { 0 };
                                    uint8_t id_3885 { 0 };
                                    uint8_t id_3886 { shft_ref_432[id_3885] };
                                    uint8_t id_3887 { 7 };
                                    uint8_t id_3888 { uint8_t(id_3886 + id_3887) };
                                    Void id_3889 { ((void)(shft_ref_432[id_3884] = id_3888), ::dessser::Void()) };
                                    (void)id_3889;
                                    uint8_t id_3890 { 128 };
                                    bool id_3891 { bool(leb128_fst_435 >= id_3890) };
                                    letpair_res_3870 = id_3891;
                                  }
                                  let_res_3869 = letpair_res_3870;
                                }
                                while_flag_3865 = let_res_3869;
                                if (while_flag_3865) {
                                  (void)::dessser::Void();
                                }
                              } while (while_flag_3865);
                              (void)::dessser::Void();
                              uint8_t id_3892 { 0 };
                              uint32_t id_3893 { leb_ref_431[id_3892] };
                              uint8_t id_3894 { 0 };
                              Pointer id_3895 { p_ref_433[id_3894] };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3896 { id_3893, id_3895 };
                              let_res_3864 = id_3896;
                            }
                            let_res_3862 = let_res_3864;
                          }
                          let_res_3859 = let_res_3862;
                        }
                        ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3897;
                        {
                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_440 { let_res_3859 };
                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3898;
                          {
                            auto dlist1_fst_441 { std::get<0>(dlist1_440) };
                            auto dlist1_snd_442 { std::get<1>(dlist1_440) };
                            Lst<dessser::gen::field_name::t_ext> endoflist_3899;
                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3900 { endoflist_3899, dlist1_snd_442 };
                            Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_3901 {  id_3900  };
                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3902;
                            {
                              Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_443 { id_3901 };
                              int32_t id_3903 { 0L };
                              Vec<1, int32_t> id_3904 {  id_3903  };
                              {
                                Vec<1, int32_t> repeat_n_444 { id_3904 };
                                bool while_flag_3905 { true };
                                do {
                                  int32_t id_3906 { int32_t(dlist1_fst_441) };
                                  uint8_t id_3907 { 0 };
                                  int32_t id_3908 { repeat_n_444[id_3907] };
                                  bool id_3909 { bool(id_3906 > id_3908) };
                                  while_flag_3905 = id_3909;
                                  if (while_flag_3905) {
                                    uint8_t id_3910 { 0 };
                                    ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3911 { inits_src_ref_443[id_3910] };
                                    {
                                      ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_445 { id_3911 };
                                      {
                                        auto dlist2_fst_446 { std::get<0>(dlist2_445) };
                                        auto dlist2_snd_447 { std::get<1>(dlist2_445) };
                                        uint8_t id_3912 { 0 };
                                        auto fun3913 { dessser::gen::field_name::of_row_binary };
                                        ::dessser::gen::raql_operation::t18cecf882d7ac80cef37dfe6b22279d4 id_3914 { fun3913(dlist2_snd_447) };
                                        ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3915;
                                        {
                                          auto dlist3_fst_449 { std::get<0>(id_3914) };
                                          auto dlist3_snd_450 { std::get<1>(id_3914) };
                                          Lst<dessser::gen::field_name::t_ext> id_3916 { dlist3_fst_449, dlist2_fst_446 };
                                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3917 { id_3916, dlist3_snd_450 };
                                          letpair_res_3915 = id_3917;
                                        }
                                        Void id_3918 { ((void)(inits_src_ref_443[id_3912] = letpair_res_3915), ::dessser::Void()) };
                                        (void)id_3918;
                                      }
                                      (void)::dessser::Void();
                                    }
                                    (void)::dessser::Void();
                                    uint8_t id_3919 { 0 };
                                    uint8_t id_3920 { 0 };
                                    int32_t id_3921 { repeat_n_444[id_3920] };
                                    int32_t id_3922 { 1L };
                                    int32_t id_3923 { int32_t(id_3921 + id_3922) };
                                    Void id_3924 { ((void)(repeat_n_444[id_3919] = id_3923), ::dessser::Void()) };
                                    (void)id_3924;
                                    (void)id_3924;
                                  }
                                } while (while_flag_3905);
                                (void)::dessser::Void();
                              }
                              (void)::dessser::Void();
                              uint8_t id_3925 { 0 };
                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3926 { inits_src_ref_443[id_3925] };
                              let_res_3902 = id_3926;
                            }
                            letpair_res_3898 = let_res_3902;
                          }
                          let_res_3897 = letpair_res_3898;
                        }
                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3927;
                        {
                          auto dlist4_fst_452 { std::get<0>(let_res_3897) };
                          auto dlist4_snd_453 { std::get<1>(let_res_3897) };
                          ::dessser::gen::raql_operation::t146ce039ffc00c7cf249e9dc380db920 id_3928 { drec_fst_420, drec_fst_423, drec_fst_429, dlist4_fst_452 };
                          std::shared_ptr<::dessser::gen::raql_operation::t>  id_3929 { std::make_shared<::dessser::gen::raql_operation::t>(std::in_place_index<1>, id_3928) };
                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3930 { id_3929, dlist4_snd_453 };
                          letpair_res_3927 = id_3930;
                        }
                        letpair_res_3856 = letpair_res_3927;
                      }
                      let_res_3855 = letpair_res_3856;
                    }
                    letpair_res_3838 = let_res_3855;
                  }
                  let_res_3837 = letpair_res_3838;
                }
                letpair_res_3835 = let_res_3837;
              }
              let_res_3834 = letpair_res_3835;
            }
            choose_res_3832 = let_res_3834;
          } else {
            uint16_t id_3931 { 2 };
            bool id_3932 { bool(dsum1_fst_361 == id_3931) };
            Void id_3933 { ((void)(assert(id_3932)), ::dessser::Void()) };
            (void)id_3933;
            uint32_t id_3934 { 0U };
            Vec<1, uint32_t> id_3935 {  id_3934  };
            ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3936;
            {
              Vec<1, uint32_t> leb_ref_363 { id_3935 };
              uint8_t id_3937 { 0 };
              Vec<1, uint8_t> id_3938 {  id_3937  };
              ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3939;
              {
                Vec<1, uint8_t> shft_ref_364 { id_3938 };
                Vec<1, Pointer> id_3940 {  dsum1_snd_362  };
                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3941;
                {
                  Vec<1, Pointer> p_ref_365 { id_3940 };
                  bool while_flag_3942 { true };
                  do {
                    uint8_t id_3943 { 0 };
                    Pointer id_3944 { p_ref_365[id_3943] };
                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3945 { id_3944.readU8() };
                    bool let_res_3946;
                    {
                      ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_366 { id_3945 };
                      bool letpair_res_3947;
                      {
                        auto leb128_fst_367 { std::get<0>(leb128_366) };
                        auto leb128_snd_368 { std::get<1>(leb128_366) };
                        uint8_t id_3948 { 0 };
                        Void id_3949 { ((void)(p_ref_365[id_3948] = leb128_snd_368), ::dessser::Void()) };
                        (void)id_3949;
                        uint8_t id_3950 { 0 };
                        uint8_t id_3951 { 127 };
                        uint8_t id_3952 { uint8_t(leb128_fst_367 & id_3951) };
                        uint32_t id_3953 { uint32_t(id_3952) };
                        uint8_t id_3954 { 0 };
                        uint8_t id_3955 { shft_ref_364[id_3954] };
                        uint32_t id_3956 { uint32_t(id_3953 << id_3955) };
                        uint8_t id_3957 { 0 };
                        uint32_t id_3958 { leb_ref_363[id_3957] };
                        uint32_t id_3959 { uint32_t(id_3956 | id_3958) };
                        Void id_3960 { ((void)(leb_ref_363[id_3950] = id_3959), ::dessser::Void()) };
                        (void)id_3960;
                        uint8_t id_3961 { 0 };
                        uint8_t id_3962 { 0 };
                        uint8_t id_3963 { shft_ref_364[id_3962] };
                        uint8_t id_3964 { 7 };
                        uint8_t id_3965 { uint8_t(id_3963 + id_3964) };
                        Void id_3966 { ((void)(shft_ref_364[id_3961] = id_3965), ::dessser::Void()) };
                        (void)id_3966;
                        uint8_t id_3967 { 128 };
                        bool id_3968 { bool(leb128_fst_367 >= id_3967) };
                        letpair_res_3947 = id_3968;
                      }
                      let_res_3946 = letpair_res_3947;
                    }
                    while_flag_3942 = let_res_3946;
                    if (while_flag_3942) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_3942);
                  (void)::dessser::Void();
                  uint8_t id_3969 { 0 };
                  uint32_t id_3970 { leb_ref_363[id_3969] };
                  Size id_3971 { Size(id_3970) };
                  uint8_t id_3972 { 0 };
                  Pointer id_3973 { p_ref_365[id_3972] };
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_3974 { id_3971, id_3973 };
                  let_res_3941 = id_3974;
                }
                let_res_3939 = let_res_3941;
              }
              let_res_3936 = let_res_3939;
            }
            ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 let_res_3975;
            {
              ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_369 { let_res_3936 };
              ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_3976;
              {
                auto dstring1_fst_370 { std::get<0>(dstring1_369) };
                auto dstring1_snd_371 { std::get<1>(dstring1_369) };
                ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_3977 { dstring1_snd_371.readBytes(dstring1_fst_370) };
                ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_3978;
                {
                  auto dstring2_fst_373 { std::get<0>(id_3977) };
                  auto dstring2_snd_374 { std::get<1>(id_3977) };
                  std::string id_3979 { dstring2_fst_373.toString() };
                  ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 id_3980 { id_3979, dstring2_snd_374 };
                  letpair_res_3978 = id_3980;
                }
                letpair_res_3976 = letpair_res_3978;
              }
              let_res_3975 = letpair_res_3976;
            }
            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3981;
            {
              ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 drec_375 { let_res_3975 };
              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3982;
              {
                auto drec_fst_376 { std::get<0>(drec_375) };
                auto drec_snd_377 { std::get<1>(drec_375) };
                ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3983 { drec_snd_377.readU16Le() };
                ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_3984;
                {
                  auto du16_fst_379 { std::get<0>(id_3983) };
                  auto du16_snd_380 { std::get<1>(id_3983) };
                  ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3985 { du16_fst_379, du16_snd_380 };
                  letpair_res_3984 = id_3985;
                }
                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3986;
                {
                  ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 drec_381 { letpair_res_3984 };
                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3987;
                  {
                    auto drec_fst_382 { std::get<0>(drec_381) };
                    auto drec_snd_383 { std::get<1>(drec_381) };
                    auto fun3988 { dessser::gen::raql_ip_protocol::of_row_binary };
                    ::dessser::gen::raql_operation::tb79a82b758e19581c860a01593485d0a id_3989 { fun3988(drec_snd_383) };
                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3990;
                    {
                      ::dessser::gen::raql_operation::tb79a82b758e19581c860a01593485d0a drec_384 { id_3989 };
                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3991;
                      {
                        auto drec_fst_385 { std::get<0>(drec_384) };
                        auto drec_snd_386 { std::get<1>(drec_384) };
                        auto fun3992 { dessser::gen::raql_net_protocol::of_row_binary };
                        ::dessser::gen::raql_operation::ta85addb3b405dfc5781945a2f01e354a id_3993 { fun3992(drec_snd_386) };
                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3994;
                        {
                          ::dessser::gen::raql_operation::ta85addb3b405dfc5781945a2f01e354a drec_387 { id_3993 };
                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3995;
                          {
                            auto drec_fst_388 { std::get<0>(drec_387) };
                            auto drec_snd_389 { std::get<1>(drec_387) };
                            uint32_t id_3996 { 0U };
                            Vec<1, uint32_t> id_3997 {  id_3996  };
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3998;
                            {
                              Vec<1, uint32_t> leb_ref_390 { id_3997 };
                              uint8_t id_3999 { 0 };
                              Vec<1, uint8_t> id_4000 {  id_3999  };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_4001;
                              {
                                Vec<1, uint8_t> shft_ref_391 { id_4000 };
                                Vec<1, Pointer> id_4002 {  drec_snd_389  };
                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_4003;
                                {
                                  Vec<1, Pointer> p_ref_392 { id_4002 };
                                  bool while_flag_4004 { true };
                                  do {
                                    uint8_t id_4005 { 0 };
                                    Pointer id_4006 { p_ref_392[id_4005] };
                                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_4007 { id_4006.readU8() };
                                    bool let_res_4008;
                                    {
                                      ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_393 { id_4007 };
                                      bool letpair_res_4009;
                                      {
                                        auto leb128_fst_394 { std::get<0>(leb128_393) };
                                        auto leb128_snd_395 { std::get<1>(leb128_393) };
                                        uint8_t id_4010 { 0 };
                                        Void id_4011 { ((void)(p_ref_392[id_4010] = leb128_snd_395), ::dessser::Void()) };
                                        (void)id_4011;
                                        uint8_t id_4012 { 0 };
                                        uint8_t id_4013 { 127 };
                                        uint8_t id_4014 { uint8_t(leb128_fst_394 & id_4013) };
                                        uint32_t id_4015 { uint32_t(id_4014) };
                                        uint8_t id_4016 { 0 };
                                        uint8_t id_4017 { shft_ref_391[id_4016] };
                                        uint32_t id_4018 { uint32_t(id_4015 << id_4017) };
                                        uint8_t id_4019 { 0 };
                                        uint32_t id_4020 { leb_ref_390[id_4019] };
                                        uint32_t id_4021 { uint32_t(id_4018 | id_4020) };
                                        Void id_4022 { ((void)(leb_ref_390[id_4012] = id_4021), ::dessser::Void()) };
                                        (void)id_4022;
                                        uint8_t id_4023 { 0 };
                                        uint8_t id_4024 { 0 };
                                        uint8_t id_4025 { shft_ref_391[id_4024] };
                                        uint8_t id_4026 { 7 };
                                        uint8_t id_4027 { uint8_t(id_4025 + id_4026) };
                                        Void id_4028 { ((void)(shft_ref_391[id_4023] = id_4027), ::dessser::Void()) };
                                        (void)id_4028;
                                        uint8_t id_4029 { 128 };
                                        bool id_4030 { bool(leb128_fst_394 >= id_4029) };
                                        letpair_res_4009 = id_4030;
                                      }
                                      let_res_4008 = letpair_res_4009;
                                    }
                                    while_flag_4004 = let_res_4008;
                                    if (while_flag_4004) {
                                      (void)::dessser::Void();
                                    }
                                  } while (while_flag_4004);
                                  (void)::dessser::Void();
                                  uint8_t id_4031 { 0 };
                                  uint32_t id_4032 { leb_ref_390[id_4031] };
                                  uint8_t id_4033 { 0 };
                                  Pointer id_4034 { p_ref_392[id_4033] };
                                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_4035 { id_4032, id_4034 };
                                  let_res_4003 = id_4035;
                                }
                                let_res_4001 = let_res_4003;
                              }
                              let_res_3998 = let_res_4001;
                            }
                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_4036;
                            {
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_399 { let_res_3998 };
                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_4037;
                              {
                                auto dlist1_fst_400 { std::get<0>(dlist1_399) };
                                auto dlist1_snd_401 { std::get<1>(dlist1_399) };
                                Lst<dessser::gen::field_name::t_ext> endoflist_4038;
                                ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_4039 { endoflist_4038, dlist1_snd_401 };
                                Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_4040 {  id_4039  };
                                ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_4041;
                                {
                                  Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_402 { id_4040 };
                                  int32_t id_4042 { 0L };
                                  Vec<1, int32_t> id_4043 {  id_4042  };
                                  {
                                    Vec<1, int32_t> repeat_n_403 { id_4043 };
                                    bool while_flag_4044 { true };
                                    do {
                                      int32_t id_4045 { int32_t(dlist1_fst_400) };
                                      uint8_t id_4046 { 0 };
                                      int32_t id_4047 { repeat_n_403[id_4046] };
                                      bool id_4048 { bool(id_4045 > id_4047) };
                                      while_flag_4044 = id_4048;
                                      if (while_flag_4044) {
                                        uint8_t id_4049 { 0 };
                                        ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_4050 { inits_src_ref_402[id_4049] };
                                        {
                                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_404 { id_4050 };
                                          {
                                            auto dlist2_fst_405 { std::get<0>(dlist2_404) };
                                            auto dlist2_snd_406 { std::get<1>(dlist2_404) };
                                            uint8_t id_4051 { 0 };
                                            auto fun4052 { dessser::gen::field_name::of_row_binary };
                                            ::dessser::gen::raql_operation::t18cecf882d7ac80cef37dfe6b22279d4 id_4053 { fun4052(dlist2_snd_406) };
                                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_4054;
                                            {
                                              auto dlist3_fst_408 { std::get<0>(id_4053) };
                                              auto dlist3_snd_409 { std::get<1>(id_4053) };
                                              Lst<dessser::gen::field_name::t_ext> id_4055 { dlist3_fst_408, dlist2_fst_405 };
                                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_4056 { id_4055, dlist3_snd_409 };
                                              letpair_res_4054 = id_4056;
                                            }
                                            Void id_4057 { ((void)(inits_src_ref_402[id_4051] = letpair_res_4054), ::dessser::Void()) };
                                            (void)id_4057;
                                          }
                                          (void)::dessser::Void();
                                        }
                                        (void)::dessser::Void();
                                        uint8_t id_4058 { 0 };
                                        uint8_t id_4059 { 0 };
                                        int32_t id_4060 { repeat_n_403[id_4059] };
                                        int32_t id_4061 { 1L };
                                        int32_t id_4062 { int32_t(id_4060 + id_4061) };
                                        Void id_4063 { ((void)(repeat_n_403[id_4058] = id_4062), ::dessser::Void()) };
                                        (void)id_4063;
                                        (void)id_4063;
                                      }
                                    } while (while_flag_4044);
                                    (void)::dessser::Void();
                                  }
                                  (void)::dessser::Void();
                                  uint8_t id_4064 { 0 };
                                  ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_4065 { inits_src_ref_402[id_4064] };
                                  let_res_4041 = id_4065;
                                }
                                letpair_res_4037 = let_res_4041;
                              }
                              let_res_4036 = letpair_res_4037;
                            }
                            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_4066;
                            {
                              auto dlist4_fst_411 { std::get<0>(let_res_4036) };
                              auto dlist4_snd_412 { std::get<1>(let_res_4036) };
                              ::dessser::gen::raql_operation::tb24aca08586dad8e1ea84f2fd44f4bd3 id_4067 { drec_fst_376, drec_fst_382, drec_fst_385, drec_fst_388, dlist4_fst_411 };
                              std::shared_ptr<::dessser::gen::raql_operation::t>  id_4068 { std::make_shared<::dessser::gen::raql_operation::t>(std::in_place_index<2>, id_4067) };
                              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_4069 { id_4068, dlist4_snd_412 };
                              letpair_res_4066 = id_4069;
                            }
                            letpair_res_3995 = letpair_res_4066;
                          }
                          let_res_3994 = letpair_res_3995;
                        }
                        letpair_res_3991 = let_res_3994;
                      }
                      let_res_3990 = letpair_res_3991;
                    }
                    letpair_res_3987 = let_res_3990;
                  }
                  let_res_3986 = letpair_res_3987;
                }
                letpair_res_3982 = let_res_3986;
              }
              let_res_3981 = letpair_res_3982;
            }
            choose_res_3832 = let_res_3981;
          }
          choose_res_3208 = choose_res_3832;
        }
        letpair_res_3205 = choose_res_3208;
      }
      let_res_3204 = letpair_res_3205;
    }
    return let_res_3204;
  }
   };
  return fun3200;
}
std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer &)> of_row_binary(of_row_binary_init());


}
