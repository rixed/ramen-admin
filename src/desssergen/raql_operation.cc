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
#include "desssergen/field_name.h"
#include "desssergen/raql_net_protocol.h"
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
  bool clickhouse_syntax;
  std::string escape_seq;
  Lst<dessser::gen::field_type::t_ext> fields;
  bool may_quote;
  std::string null;
  char separator;
  bool vectors_of_chars_as_string;
  t78cec4f9827249604fe947034c575f2a(bool clickhouse_syntax_, std::string escape_seq_, Lst<dessser::gen::field_type::t_ext> fields_, bool may_quote_, std::string null_, char separator_, bool vectors_of_chars_as_string_) : clickhouse_syntax(clickhouse_syntax_), escape_seq(escape_seq_), fields(fields_), may_quote(may_quote_), null(null_), separator(separator_), vectors_of_chars_as_string(vectors_of_chars_as_string_) {}
  t78cec4f9827249604fe947034c575f2a() = default;
};
inline bool operator==(t78cec4f9827249604fe947034c575f2a const &a, t78cec4f9827249604fe947034c575f2a const &b) {
  return a.clickhouse_syntax == b.clickhouse_syntax && a.escape_seq == b.escape_seq && a.fields == b.fields && a.may_quote == b.may_quote && a.null == b.null && a.separator == b.separator && a.vectors_of_chars_as_string == b.vectors_of_chars_as_string;
}

inline bool operator!=(t78cec4f9827249604fe947034c575f2a const &a, t78cec4f9827249604fe947034c575f2a const &b) {
  return !operator==(a, b);
}
struct external_format : public std::variant<
  ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a, // CSV
  Lst<dessser::gen::field_type::t_ext> // RowBinary
> { using variant::variant; };

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
struct td1e70aeaf070b9b0d0119e932e590179 : public std::tuple<
  std::string,
  dessser::gen::raql_expr::t_ext
> {
  using tuple::tuple;
  td1e70aeaf070b9b0d0119e932e590179(std::tuple<std::string, dessser::gen::raql_expr::t_ext> p)
    : std::tuple<std::string, dessser::gen::raql_expr::t_ext>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td1e70aeaf070b9b0d0119e932e590179 const &a, td1e70aeaf070b9b0d0119e932e590179 const &b) {
  return std::get<0>(a) == std::get<0>(b) && ::dessser::gen::raql_expr::Deref(std::get<1>(a)) == ::dessser::gen::raql_expr::Deref(std::get<1>(b));
}
inline bool operator!=(td1e70aeaf070b9b0d0119e932e590179 const &a, td1e70aeaf070b9b0d0119e932e590179 const &b) {
  return !operator==(a, b);
}
struct t66e84af8ac3d220e6953b809395192f8 {
  dessser::gen::raql_expr::t_ext after_max_events;
  dessser::gen::raql_expr::t_ext after_max_secs;
  t66e84af8ac3d220e6953b809395192f8(dessser::gen::raql_expr::t_ext after_max_events_, dessser::gen::raql_expr::t_ext after_max_secs_) : after_max_events(after_max_events_), after_max_secs(after_max_secs_) {}
  t66e84af8ac3d220e6953b809395192f8() = default;
};
inline bool operator==(t66e84af8ac3d220e6953b809395192f8 const &a, t66e84af8ac3d220e6953b809395192f8 const &b) {
  return ::dessser::gen::raql_expr::Deref(a.after_max_events) == ::dessser::gen::raql_expr::Deref(b.after_max_events) && ::dessser::gen::raql_expr::Deref(a.after_max_secs) == ::dessser::gen::raql_expr::Deref(b.after_max_secs);
}

inline bool operator!=(t66e84af8ac3d220e6953b809395192f8 const &a, t66e84af8ac3d220e6953b809395192f8 const &b) {
  return !operator==(a, b);
}
struct td6b783eb78996074f9384054f64b14ae : public std::variant<
  Void, // Beginning
  dessser::gen::raql_expr::t_ext, // OffsetFromEnd
  Void, // SaveInState
  ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 // UseKafkaGroupCoordinator
> { using variant::variant; };

inline bool operator==(td6b783eb78996074f9384054f64b14ae const &a, td6b783eb78996074f9384054f64b14ae const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Beginning
    case 1: return ::dessser::gen::raql_expr::Deref(std::get<1>(a)) == ::dessser::gen::raql_expr::Deref(std::get<1>(b)); // OffsetFromEnd
    case 2: return std::get<2>(a) == std::get<2>(b); // SaveInState
    case 3: return std::get<3>(a) == std::get<3>(b); // UseKafkaGroupCoordinator
  };
  return false;
}
inline bool operator!=(td6b783eb78996074f9384054f64b14ae const &a, td6b783eb78996074f9384054f64b14ae const &b) {
  return !operator==(a, b);
}
struct t39c49449a1a829aeb161993f390f9dbf {
  Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> options;
  std::optional<dessser::gen::raql_expr::t_ext> partitions;
  ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae restart_from;
  dessser::gen::raql_expr::t_ext topic;
  t39c49449a1a829aeb161993f390f9dbf(Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> options_, std::optional<dessser::gen::raql_expr::t_ext> partitions_, ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae restart_from_, dessser::gen::raql_expr::t_ext topic_) : options(options_), partitions(partitions_), restart_from(restart_from_), topic(topic_) {}
  t39c49449a1a829aeb161993f390f9dbf() = default;
};
inline bool operator==(t39c49449a1a829aeb161993f390f9dbf const &a, t39c49449a1a829aeb161993f390f9dbf const &b) {
  return a.options == b.options && ((a.partitions && b.partitions && ::dessser::gen::raql_expr::Deref(a.partitions.value()) == ::dessser::gen::raql_expr::Deref(b.partitions.value())) || (!a.partitions && !b.partitions)) && a.restart_from == b.restart_from && ::dessser::gen::raql_expr::Deref(a.topic) == ::dessser::gen::raql_expr::Deref(b.topic);
}

inline bool operator!=(t39c49449a1a829aeb161993f390f9dbf const &a, t39c49449a1a829aeb161993f390f9dbf const &b) {
  return !operator==(a, b);
}
struct external_source : public std::variant<
  ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3, // File
  ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf // Kafka
> { using variant::variant; };

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
struct t818559b68b475733e8c99b87db21c5d3 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_operation::external_format> ,
  Pointer
> {
  using tuple::tuple;
  t818559b68b475733e8c99b87db21c5d3(std::tuple<std::shared_ptr<::dessser::gen::raql_operation::external_format> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_operation::external_format> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t818559b68b475733e8c99b87db21c5d3 const &a, t818559b68b475733e8c99b87db21c5d3 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t818559b68b475733e8c99b87db21c5d3 const &a, t818559b68b475733e8c99b87db21c5d3 const &b) {
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
struct t8b60740739dfc5a7cf5f2b99a1358fa6 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_operation::external_source> ,
  Pointer
> {
  using tuple::tuple;
  t8b60740739dfc5a7cf5f2b99a1358fa6(std::tuple<std::shared_ptr<::dessser::gen::raql_operation::external_source> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_operation::external_source> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8b60740739dfc5a7cf5f2b99a1358fa6 const &a, t8b60740739dfc5a7cf5f2b99a1358fa6 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8b60740739dfc5a7cf5f2b99a1358fa6 const &a, t8b60740739dfc5a7cf5f2b99a1358fa6 const &b) {
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
struct t90d9936f362c598c2320b06a45a435fd : public std::tuple<
  Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179>,
  Pointer
> {
  using tuple::tuple;
  t90d9936f362c598c2320b06a45a435fd(std::tuple<Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t90d9936f362c598c2320b06a45a435fd const &a, t90d9936f362c598c2320b06a45a435fd const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t90d9936f362c598c2320b06a45a435fd const &a, t90d9936f362c598c2320b06a45a435fd const &b) {
  return !operator==(a, b);
}
struct t879fdacf820dcaecad2995c1cfff3ff6 : public std::tuple<
  ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae,
  Pointer
> {
  using tuple::tuple;
  t879fdacf820dcaecad2995c1cfff3ff6(std::tuple<::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae, Pointer> p)
    : std::tuple<::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t879fdacf820dcaecad2995c1cfff3ff6 const &a, t879fdacf820dcaecad2995c1cfff3ff6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t879fdacf820dcaecad2995c1cfff3ff6 const &a, t879fdacf820dcaecad2995c1cfff3ff6 const &b) {
  return !operator==(a, b);
}
struct t054d75b46129860c650f4e7e4e60a6f9 : public std::variant<
  Void, // AllSites
  std::string, // TheseSites
  Void // ThisSite
> { using variant::variant; };

inline bool operator==(t054d75b46129860c650f4e7e4e60a6f9 const &a, t054d75b46129860c650f4e7e4e60a6f9 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // AllSites
    case 1: return std::get<1>(a) == std::get<1>(b); // TheseSites
    case 2: return std::get<2>(a) == std::get<2>(b); // ThisSite
  };
  return false;
}
inline bool operator!=(t054d75b46129860c650f4e7e4e60a6f9 const &a, t054d75b46129860c650f4e7e4e60a6f9 const &b) {
  return !operator==(a, b);
}
struct ted682f302d97794f7d8af77b7693b421 : public std::tuple<
  ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9,
  std::optional<std::string>,
  dessser::gen::function_name::t_ext
> {
  using tuple::tuple;
};
inline bool operator==(ted682f302d97794f7d8af77b7693b421 const &a, ted682f302d97794f7d8af77b7693b421 const &b) {
  return std::get<0>(a) == std::get<0>(b) && ((std::get<1>(a) && std::get<1>(b) && std::get<1>(a).value() == std::get<1>(b).value()) || (!std::get<1>(a) && !std::get<1>(b))) && ::dessser::gen::function_name::Deref(std::get<2>(a)) == ::dessser::gen::function_name::Deref(std::get<2>(b));
}
inline bool operator!=(ted682f302d97794f7d8af77b7693b421 const &a, ted682f302d97794f7d8af77b7693b421 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct data_source : public std::variant<
  ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421, // NamedOperation
  std::shared_ptr<::dessser::gen::raql_operation::t>  // SubQuery
> { using variant::variant; };

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
struct t2924eb63c15624d94238446da8ddd5a5 {
  std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others;
  bool commit_before;
  dessser::gen::raql_expr::t_ext commit_cond;
  std::optional<dessser::gen::event_time::t_ext> Aggregate_event_time;
  std::optional<dessser::gen::raql_expr::t_ext> every;
  Lst<dessser::gen::field_name::t_ext> Aggregate_factors;
  Lst<dessser::gen::raql_select_field::t_ext> Aggregate_fields;
  dessser::gen::raql_flush_method::t_ext flush_how;
  Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> > from;
  Lst<dessser::gen::raql_expr::t_ext> key;
  Lst<dessser::gen::raql_expr::t_ext> notifications;
  std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> sort;
  dessser::gen::raql_expr::t_ext where;
  t2924eb63c15624d94238446da8ddd5a5(std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others_, bool commit_before_, dessser::gen::raql_expr::t_ext commit_cond_, std::optional<dessser::gen::event_time::t_ext> Aggregate_event_time_, std::optional<dessser::gen::raql_expr::t_ext> every_, Lst<dessser::gen::field_name::t_ext> Aggregate_factors_, Lst<dessser::gen::raql_select_field::t_ext> Aggregate_fields_, dessser::gen::raql_flush_method::t_ext flush_how_, Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> > from_, Lst<dessser::gen::raql_expr::t_ext> key_, Lst<dessser::gen::raql_expr::t_ext> notifications_, std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> sort_, dessser::gen::raql_expr::t_ext where_) : and_all_others(and_all_others_), commit_before(commit_before_), commit_cond(commit_cond_), Aggregate_event_time(Aggregate_event_time_), every(every_), Aggregate_factors(Aggregate_factors_), Aggregate_fields(Aggregate_fields_), flush_how(flush_how_), from(from_), key(key_), notifications(notifications_), sort(sort_), where(where_) {}
  t2924eb63c15624d94238446da8ddd5a5() = default;
};
inline bool operator==(t2924eb63c15624d94238446da8ddd5a5 const &a, t2924eb63c15624d94238446da8ddd5a5 const &b) {
  return ((a.and_all_others && b.and_all_others && a.and_all_others.value() == b.and_all_others.value()) || (!a.and_all_others && !b.and_all_others)) && a.commit_before == b.commit_before && ::dessser::gen::raql_expr::Deref(a.commit_cond) == ::dessser::gen::raql_expr::Deref(b.commit_cond) && ((a.Aggregate_event_time && b.Aggregate_event_time && ::dessser::gen::event_time::Deref(a.Aggregate_event_time.value()) == ::dessser::gen::event_time::Deref(b.Aggregate_event_time.value())) || (!a.Aggregate_event_time && !b.Aggregate_event_time)) && ((a.every && b.every && ::dessser::gen::raql_expr::Deref(a.every.value()) == ::dessser::gen::raql_expr::Deref(b.every.value())) || (!a.every && !b.every)) && a.Aggregate_factors == b.Aggregate_factors && a.Aggregate_fields == b.Aggregate_fields && ::dessser::gen::raql_flush_method::Deref(a.flush_how) == ::dessser::gen::raql_flush_method::Deref(b.flush_how) && a.from == b.from && a.key == b.key && a.notifications == b.notifications && ((a.sort && b.sort && a.sort.value() == b.sort.value()) || (!a.sort && !b.sort)) && ::dessser::gen::raql_expr::Deref(a.where) == ::dessser::gen::raql_expr::Deref(b.where);
}

inline bool operator!=(t2924eb63c15624d94238446da8ddd5a5 const &a, t2924eb63c15624d94238446da8ddd5a5 const &b) {
  return !operator==(a, b);
}
struct teabb4aa6beb374b8a3faf63ed92e59d1 {
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::field_name::t_ext> ReadExternal_factors;
  std::shared_ptr<::dessser::gen::raql_operation::external_format>  format;
  std::shared_ptr<::dessser::gen::raql_operation::external_source>  source;
  teabb4aa6beb374b8a3faf63ed92e59d1(std::optional<dessser::gen::event_time::t_ext> event_time_, Lst<dessser::gen::field_name::t_ext> ReadExternal_factors_, std::shared_ptr<::dessser::gen::raql_operation::external_format>  format_, std::shared_ptr<::dessser::gen::raql_operation::external_source>  source_) : event_time(event_time_), ReadExternal_factors(ReadExternal_factors_), format(format_), source(source_) {}
  teabb4aa6beb374b8a3faf63ed92e59d1() = default;
};
inline bool operator==(teabb4aa6beb374b8a3faf63ed92e59d1 const &a, teabb4aa6beb374b8a3faf63ed92e59d1 const &b) {
  return ((a.event_time && b.event_time && ::dessser::gen::event_time::Deref(a.event_time.value()) == ::dessser::gen::event_time::Deref(b.event_time.value())) || (!a.event_time && !b.event_time)) && a.ReadExternal_factors == b.ReadExternal_factors && (*a.format) == (*b.format) && (*a.source) == (*b.source);
}

inline bool operator!=(teabb4aa6beb374b8a3faf63ed92e59d1 const &a, teabb4aa6beb374b8a3faf63ed92e59d1 const &b) {
  return !operator==(a, b);
}
struct tfb55a595623604efa44696c62f9afcc5 {
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string net_addr;
  uint16_t port;
  dessser::gen::raql_net_protocol::t_ext proto;
  tfb55a595623604efa44696c62f9afcc5(Lst<dessser::gen::field_name::t_ext> factors_, std::string net_addr_, uint16_t port_, dessser::gen::raql_net_protocol::t_ext proto_) : factors(factors_), net_addr(net_addr_), port(port_), proto(proto_) {}
  tfb55a595623604efa44696c62f9afcc5() = default;
};
inline bool operator==(tfb55a595623604efa44696c62f9afcc5 const &a, tfb55a595623604efa44696c62f9afcc5 const &b) {
  return a.factors == b.factors && a.net_addr == b.net_addr && a.port == b.port && ::dessser::gen::raql_net_protocol::Deref(a.proto) == ::dessser::gen::raql_net_protocol::Deref(b.proto);
}

inline bool operator!=(tfb55a595623604efa44696c62f9afcc5 const &a, tfb55a595623604efa44696c62f9afcc5 const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5, // Aggregate
  ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1, // ReadExternal
  ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 // ListenFor
> { using variant::variant; };

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
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> wrap_to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::data_source> ,Pointer)> data_source_to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::data_source> )> data_source_sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::t> )> sersize_of_row_binary;
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
extern std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> wrap_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t686eed8ab9a7b5a11ecf622b72433681 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_operation::data_source> ,
  Pointer
> {
  using tuple::tuple;
  t686eed8ab9a7b5a11ecf622b72433681(std::tuple<std::shared_ptr<::dessser::gen::raql_operation::data_source> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_operation::data_source> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t686eed8ab9a7b5a11ecf622b72433681 const &a, t686eed8ab9a7b5a11ecf622b72433681 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t686eed8ab9a7b5a11ecf622b72433681 const &a, t686eed8ab9a7b5a11ecf622b72433681 const &b) {
  return !operator==(a, b);
}
extern std::function<::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681(Pointer)> data_source_of_row_binary;
struct tedbc0e6cf6279cdd2eff41d7793af3bd : public std::tuple<
  ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9,
  Pointer
> {
  using tuple::tuple;
  tedbc0e6cf6279cdd2eff41d7793af3bd(std::tuple<::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9, Pointer> p)
    : std::tuple<::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tedbc0e6cf6279cdd2eff41d7793af3bd const &a, tedbc0e6cf6279cdd2eff41d7793af3bd const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tedbc0e6cf6279cdd2eff41d7793af3bd const &a, tedbc0e6cf6279cdd2eff41d7793af3bd const &b) {
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
extern std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> of_row_binary;
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
struct t397ac070d450160cc53ed25cc12147c9 : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> >,
  Pointer
> {
  using tuple::tuple;
  t397ac070d450160cc53ed25cc12147c9(std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t397ac070d450160cc53ed25cc12147c9 const &a, t397ac070d450160cc53ed25cc12147c9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t397ac070d450160cc53ed25cc12147c9 const &a, t397ac070d450160cc53ed25cc12147c9 const &b) {
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
      (let "ssum_dst_839" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_859"
            (let "srec_dst_858"
              (let "srec_dst_852"
                (let "srec_dst_849"
                  (let "srec_dst_848"
                    (let "srec_dst_845" (write-u8 (identifier "ssum_dst_839") (u8-of-char (get-field "separator" (get-alt "CSV" (param 0)))))
                      (write-bytes
                        (let "leb128_sz_846" (make-vec (string-length (get-field "null" (get-alt "CSV" (param 0)))))
                          (let "leb128_ptr_847" (make-vec (identifier "srec_dst_845"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_847")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_847"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_846"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_846"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_846"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_846") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_846")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_846")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_847"))))) 
                        (bytes-of-string (get-field "null" (get-alt "CSV" (param 0)))))) 
                    (write-u8 (identifier "srec_dst_848") (u8-of-bool (get-field "may_quote" (get-alt "CSV" (param 0))))))
                  (write-bytes
                    (let "leb128_sz_850" (make-vec (string-length (get-field "escape_seq" (get-alt "CSV" (param 0)))))
                      (let "leb128_ptr_851" (make-vec (identifier "srec_dst_849"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_851")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_851"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_850"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_850"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_850"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_850") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_850")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_850")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_851"))))) 
                    (bytes-of-string (get-field "escape_seq" (get-alt "CSV" (param 0))))))
                (let "dst_ref_855"
                  (make-vec
                    (let "leb128_sz_853" (make-vec (cardinality (get-field "fields" (get-alt "CSV" (param 0)))))
                      (let "leb128_ptr_854" (make-vec (identifier "srec_dst_852"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_854")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_854"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_853"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_853"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_853"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_853") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_853")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_853")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_854"))))))
                  (let "n_ref_856" (make-vec (i32 0))
                    (seq
                      (for-each "x_857" (get-field "fields" (get-alt "CSV" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_855") (apply (ext-identifier field_type to-row-binary) (identifier "x_857") (unsafe-nth (u8 0) (identifier "dst_ref_855"))))
                          (set-vec (u8 0) (identifier "n_ref_856") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_856")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_855")))))) 
              (write-u8 (identifier "srec_dst_858") (u8-of-bool (get-field "vectors_of_chars_as_string" (get-alt "CSV" (param 0))))))
            (write-u8 (identifier "srec_dst_859") (u8-of-bool (get-field "clickhouse_syntax" (get-alt "CSV" (param 0))))))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "dst_ref_842"
              (make-vec
                (let "leb128_sz_840" (make-vec (cardinality (get-alt "RowBinary" (param 0))))
                  (let "leb128_ptr_841" (make-vec (identifier "ssum_dst_839"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_841")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_841"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_840"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_840"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_840"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_840") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_840")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_840")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_841"))))))
              (let "n_ref_843" (make-vec (i32 0))
                (seq
                  (for-each "x_844" (get-alt "RowBinary" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_842") (apply (ext-identifier field_type to-row-binary) (identifier "x_844") (unsafe-nth (u8 0) (identifier "dst_ref_842"))))
                      (set-vec (u8 0) (identifier "n_ref_843") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_843")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_842")))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::external_format> ,Pointer)> external_format_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::external_format> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::raql_operation::external_format>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_839 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_8 { std::get<0 /* CSV */>((*p_0)) };
        char id_9 { id_8.separator };
        uint8_t id_10 { uint8_t(id_9) };
        Pointer id_11 { ssum_dst_839.writeU8(id_10) };
        Pointer let_res_12;
        {
          Pointer srec_dst_845 { id_11 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_13 { std::get<0 /* CSV */>((*p_0)) };
          std::string id_14 { id_13.null };
          uint32_t id_15 { (uint32_t)id_14.size() };
          Vec<1, uint32_t> id_16 {  id_15  };
          Pointer let_res_17;
          {
            Vec<1, uint32_t> leb128_sz_846 { id_16 };
            Vec<1, Pointer> id_18 {  srec_dst_845  };
            Pointer let_res_19;
            {
              Vec<1, Pointer> leb128_ptr_847 { id_18 };
              bool while_flag_20 { true };
              do {
                uint8_t id_21 { 0 };
                uint8_t id_22 { 0 };
                Pointer id_23 { leb128_ptr_847[id_22] };
                uint32_t id_24 { 128U };
                uint8_t id_25 { 0 };
                uint32_t id_26 { leb128_sz_846[id_25] };
                bool id_27 { bool(id_24 > id_26) };
                uint8_t choose_res_28;
                if (id_27) {
                  uint8_t id_29 { 0 };
                  uint32_t id_30 { leb128_sz_846[id_29] };
                  uint8_t id_31 { uint8_t(id_30) };
                  choose_res_28 = id_31;
                } else {
                  uint8_t id_32 { 0 };
                  uint32_t id_33 { leb128_sz_846[id_32] };
                  uint8_t id_34 { uint8_t(id_33) };
                  uint8_t id_35 { 128 };
                  uint8_t id_36 { uint8_t(id_34 | id_35) };
                  choose_res_28 = id_36;
                }
                Pointer id_37 { id_23.writeU8(choose_res_28) };
                Void id_38 { ((void)(leb128_ptr_847[id_21] = id_37), ::dessser::VOID) };
                (void)id_38;
                uint8_t id_39 { 0 };
                uint8_t id_40 { 0 };
                uint32_t id_41 { leb128_sz_846[id_40] };
                uint8_t id_42 { 7 };
                uint32_t id_43 { uint32_t(id_41 >> id_42) };
                Void id_44 { ((void)(leb128_sz_846[id_39] = id_43), ::dessser::VOID) };
                (void)id_44;
                uint8_t id_45 { 0 };
                uint32_t id_46 { leb128_sz_846[id_45] };
                uint32_t id_47 { 0U };
                bool id_48 { bool(id_46 > id_47) };
                while_flag_20 = id_48;
                if (while_flag_20) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_20);
              (void)::dessser::VOID;
              uint8_t id_49 { 0 };
              Pointer id_50 { leb128_ptr_847[id_49] };
              let_res_19 = id_50;
            }
            let_res_17 = let_res_19;
          }
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_51 { std::get<0 /* CSV */>((*p_0)) };
          std::string id_52 { id_51.null };
          Bytes id_53 { id_52 };
          Pointer id_54 { let_res_17.writeBytes(id_53) };
          let_res_12 = id_54;
        }
        Pointer let_res_55;
        {
          Pointer srec_dst_848 { let_res_12 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_56 { std::get<0 /* CSV */>((*p_0)) };
          bool id_57 { id_56.may_quote };
          uint8_t id_58 { uint8_t(id_57) };
          Pointer id_59 { srec_dst_848.writeU8(id_58) };
          let_res_55 = id_59;
        }
        Pointer let_res_60;
        {
          Pointer srec_dst_849 { let_res_55 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_61 { std::get<0 /* CSV */>((*p_0)) };
          std::string id_62 { id_61.escape_seq };
          uint32_t id_63 { (uint32_t)id_62.size() };
          Vec<1, uint32_t> id_64 {  id_63  };
          Pointer let_res_65;
          {
            Vec<1, uint32_t> leb128_sz_850 { id_64 };
            Vec<1, Pointer> id_66 {  srec_dst_849  };
            Pointer let_res_67;
            {
              Vec<1, Pointer> leb128_ptr_851 { id_66 };
              bool while_flag_68 { true };
              do {
                uint8_t id_69 { 0 };
                uint8_t id_70 { 0 };
                Pointer id_71 { leb128_ptr_851[id_70] };
                uint32_t id_72 { 128U };
                uint8_t id_73 { 0 };
                uint32_t id_74 { leb128_sz_850[id_73] };
                bool id_75 { bool(id_72 > id_74) };
                uint8_t choose_res_76;
                if (id_75) {
                  uint8_t id_77 { 0 };
                  uint32_t id_78 { leb128_sz_850[id_77] };
                  uint8_t id_79 { uint8_t(id_78) };
                  choose_res_76 = id_79;
                } else {
                  uint8_t id_80 { 0 };
                  uint32_t id_81 { leb128_sz_850[id_80] };
                  uint8_t id_82 { uint8_t(id_81) };
                  uint8_t id_83 { 128 };
                  uint8_t id_84 { uint8_t(id_82 | id_83) };
                  choose_res_76 = id_84;
                }
                Pointer id_85 { id_71.writeU8(choose_res_76) };
                Void id_86 { ((void)(leb128_ptr_851[id_69] = id_85), ::dessser::VOID) };
                (void)id_86;
                uint8_t id_87 { 0 };
                uint8_t id_88 { 0 };
                uint32_t id_89 { leb128_sz_850[id_88] };
                uint8_t id_90 { 7 };
                uint32_t id_91 { uint32_t(id_89 >> id_90) };
                Void id_92 { ((void)(leb128_sz_850[id_87] = id_91), ::dessser::VOID) };
                (void)id_92;
                uint8_t id_93 { 0 };
                uint32_t id_94 { leb128_sz_850[id_93] };
                uint32_t id_95 { 0U };
                bool id_96 { bool(id_94 > id_95) };
                while_flag_68 = id_96;
                if (while_flag_68) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_68);
              (void)::dessser::VOID;
              uint8_t id_97 { 0 };
              Pointer id_98 { leb128_ptr_851[id_97] };
              let_res_67 = id_98;
            }
            let_res_65 = let_res_67;
          }
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_99 { std::get<0 /* CSV */>((*p_0)) };
          std::string id_100 { id_99.escape_seq };
          Bytes id_101 { id_100 };
          Pointer id_102 { let_res_65.writeBytes(id_101) };
          let_res_60 = id_102;
        }
        Pointer let_res_103;
        {
          Pointer srec_dst_852 { let_res_60 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_104 { std::get<0 /* CSV */>((*p_0)) };
          Lst<dessser::gen::field_type::t_ext> id_105 { id_104.fields };
          uint32_t id_106 { id_105.size() };
          Vec<1, uint32_t> id_107 {  id_106  };
          Pointer let_res_108;
          {
            Vec<1, uint32_t> leb128_sz_853 { id_107 };
            Vec<1, Pointer> id_109 {  srec_dst_852  };
            Pointer let_res_110;
            {
              Vec<1, Pointer> leb128_ptr_854 { id_109 };
              bool while_flag_111 { true };
              do {
                uint8_t id_112 { 0 };
                uint8_t id_113 { 0 };
                Pointer id_114 { leb128_ptr_854[id_113] };
                uint32_t id_115 { 128U };
                uint8_t id_116 { 0 };
                uint32_t id_117 { leb128_sz_853[id_116] };
                bool id_118 { bool(id_115 > id_117) };
                uint8_t choose_res_119;
                if (id_118) {
                  uint8_t id_120 { 0 };
                  uint32_t id_121 { leb128_sz_853[id_120] };
                  uint8_t id_122 { uint8_t(id_121) };
                  choose_res_119 = id_122;
                } else {
                  uint8_t id_123 { 0 };
                  uint32_t id_124 { leb128_sz_853[id_123] };
                  uint8_t id_125 { uint8_t(id_124) };
                  uint8_t id_126 { 128 };
                  uint8_t id_127 { uint8_t(id_125 | id_126) };
                  choose_res_119 = id_127;
                }
                Pointer id_128 { id_114.writeU8(choose_res_119) };
                Void id_129 { ((void)(leb128_ptr_854[id_112] = id_128), ::dessser::VOID) };
                (void)id_129;
                uint8_t id_130 { 0 };
                uint8_t id_131 { 0 };
                uint32_t id_132 { leb128_sz_853[id_131] };
                uint8_t id_133 { 7 };
                uint32_t id_134 { uint32_t(id_132 >> id_133) };
                Void id_135 { ((void)(leb128_sz_853[id_130] = id_134), ::dessser::VOID) };
                (void)id_135;
                uint8_t id_136 { 0 };
                uint32_t id_137 { leb128_sz_853[id_136] };
                uint32_t id_138 { 0U };
                bool id_139 { bool(id_137 > id_138) };
                while_flag_111 = id_139;
                if (while_flag_111) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_111);
              (void)::dessser::VOID;
              uint8_t id_140 { 0 };
              Pointer id_141 { leb128_ptr_854[id_140] };
              let_res_110 = id_141;
            }
            let_res_108 = let_res_110;
          }
          Vec<1, Pointer> id_142 {  let_res_108  };
          Pointer let_res_143;
          {
            Vec<1, Pointer> dst_ref_855 { id_142 };
            int32_t id_144 { 0L };
            Vec<1, int32_t> id_145 {  id_144  };
            Pointer let_res_146;
            {
              Vec<1, int32_t> n_ref_856 { id_145 };
              ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_147 { std::get<0 /* CSV */>((*p_0)) };
              Lst<dessser::gen::field_type::t_ext> id_148 { id_147.fields };
              for (dessser::gen::field_type::t_ext x_857 : id_148) {
                uint8_t id_149 { 0 };
                auto fun150 { dessser::gen::field_type::to_row_binary };
                uint8_t id_151 { 0 };
                Pointer id_152 { dst_ref_855[id_151] };
                Pointer id_153 { fun150(x_857, id_152) };
                Void id_154 { ((void)(dst_ref_855[id_149] = id_153), ::dessser::VOID) };
                (void)id_154;
                uint8_t id_155 { 0 };
                int32_t id_156 { 1L };
                uint8_t id_157 { 0 };
                int32_t id_158 { n_ref_856[id_157] };
                int32_t id_159 { int32_t(id_156 + id_158) };
                Void id_160 { ((void)(n_ref_856[id_155] = id_159), ::dessser::VOID) };
                (void)id_160;
                (void)id_160;
              }
              (void)::dessser::VOID;
              uint8_t id_161 { 0 };
              Pointer id_162 { dst_ref_855[id_161] };
              let_res_146 = id_162;
            }
            let_res_143 = let_res_146;
          }
          let_res_103 = let_res_143;
        }
        Pointer let_res_163;
        {
          Pointer srec_dst_858 { let_res_103 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_164 { std::get<0 /* CSV */>((*p_0)) };
          bool id_165 { id_164.vectors_of_chars_as_string };
          uint8_t id_166 { uint8_t(id_165) };
          Pointer id_167 { srec_dst_858.writeU8(id_166) };
          let_res_163 = id_167;
        }
        Pointer let_res_168;
        {
          Pointer srec_dst_859 { let_res_163 };
          ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_169 { std::get<0 /* CSV */>((*p_0)) };
          bool id_170 { id_169.clickhouse_syntax };
          uint8_t id_171 { uint8_t(id_170) };
          Pointer id_172 { srec_dst_859.writeU8(id_171) };
          let_res_168 = id_172;
        }
        choose_res_7 = let_res_168;
      } else {
        uint16_t id_173 { uint16_t((*p_0).index()) };
        uint16_t id_174 { 1 };
        bool id_175 { bool(id_173 == id_174) };
        Void id_176 { ((void)(assert(id_175)), ::dessser::VOID) };
        (void)id_176;
        Lst<dessser::gen::field_type::t_ext> id_177 { std::get<1 /* RowBinary */>((*p_0)) };
        uint32_t id_178 { id_177.size() };
        Vec<1, uint32_t> id_179 {  id_178  };
        Pointer let_res_180;
        {
          Vec<1, uint32_t> leb128_sz_840 { id_179 };
          Vec<1, Pointer> id_181 {  ssum_dst_839  };
          Pointer let_res_182;
          {
            Vec<1, Pointer> leb128_ptr_841 { id_181 };
            bool while_flag_183 { true };
            do {
              uint8_t id_184 { 0 };
              uint8_t id_185 { 0 };
              Pointer id_186 { leb128_ptr_841[id_185] };
              uint32_t id_187 { 128U };
              uint8_t id_188 { 0 };
              uint32_t id_189 { leb128_sz_840[id_188] };
              bool id_190 { bool(id_187 > id_189) };
              uint8_t choose_res_191;
              if (id_190) {
                uint8_t id_192 { 0 };
                uint32_t id_193 { leb128_sz_840[id_192] };
                uint8_t id_194 { uint8_t(id_193) };
                choose_res_191 = id_194;
              } else {
                uint8_t id_195 { 0 };
                uint32_t id_196 { leb128_sz_840[id_195] };
                uint8_t id_197 { uint8_t(id_196) };
                uint8_t id_198 { 128 };
                uint8_t id_199 { uint8_t(id_197 | id_198) };
                choose_res_191 = id_199;
              }
              Pointer id_200 { id_186.writeU8(choose_res_191) };
              Void id_201 { ((void)(leb128_ptr_841[id_184] = id_200), ::dessser::VOID) };
              (void)id_201;
              uint8_t id_202 { 0 };
              uint8_t id_203 { 0 };
              uint32_t id_204 { leb128_sz_840[id_203] };
              uint8_t id_205 { 7 };
              uint32_t id_206 { uint32_t(id_204 >> id_205) };
              Void id_207 { ((void)(leb128_sz_840[id_202] = id_206), ::dessser::VOID) };
              (void)id_207;
              uint8_t id_208 { 0 };
              uint32_t id_209 { leb128_sz_840[id_208] };
              uint32_t id_210 { 0U };
              bool id_211 { bool(id_209 > id_210) };
              while_flag_183 = id_211;
              if (while_flag_183) {
                (void)::dessser::VOID;
              }
            } while (while_flag_183);
            (void)::dessser::VOID;
            uint8_t id_212 { 0 };
            Pointer id_213 { leb128_ptr_841[id_212] };
            let_res_182 = id_213;
          }
          let_res_180 = let_res_182;
        }
        Vec<1, Pointer> id_214 {  let_res_180  };
        Pointer let_res_215;
        {
          Vec<1, Pointer> dst_ref_842 { id_214 };
          int32_t id_216 { 0L };
          Vec<1, int32_t> id_217 {  id_216  };
          Pointer let_res_218;
          {
            Vec<1, int32_t> n_ref_843 { id_217 };
            Lst<dessser::gen::field_type::t_ext> id_219 { std::get<1 /* RowBinary */>((*p_0)) };
            for (dessser::gen::field_type::t_ext x_844 : id_219) {
              uint8_t id_220 { 0 };
              auto fun221 { dessser::gen::field_type::to_row_binary };
              uint8_t id_222 { 0 };
              Pointer id_223 { dst_ref_842[id_222] };
              Pointer id_224 { fun221(x_844, id_223) };
              Void id_225 { ((void)(dst_ref_842[id_220] = id_224), ::dessser::VOID) };
              (void)id_225;
              uint8_t id_226 { 0 };
              int32_t id_227 { 1L };
              uint8_t id_228 { 0 };
              int32_t id_229 { n_ref_843[id_228] };
              int32_t id_230 { int32_t(id_227 + id_229) };
              Void id_231 { ((void)(n_ref_843[id_226] = id_230), ::dessser::VOID) };
              (void)id_231;
              (void)id_231;
            }
            (void)::dessser::VOID;
            uint8_t id_232 { 0 };
            Pointer id_233 { dst_ref_842[id_232] };
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
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::external_format> ,Pointer)> external_format_to_row_binary(external_format_to_row_binary_init());

/* 
    (fun ("[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" "Ptr")
      (let "ssum_dst_820" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_837"
            (let "srec_dst_836" (apply (ext-identifier raql_expr to-row-binary) (get-field "fname" (get-alt "File" (param 0))) (identifier "ssum_dst_820"))
              (if (is-null (get-field "preprocessor" (get-alt "File" (param 0)))) 
                (write-u8 (identifier "srec_dst_836") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "preprocessor" (get-alt "File" (param 0)))) (write-u8 (identifier "srec_dst_836") (u8 0)))))
            (apply (ext-identifier raql_expr to-row-binary) (get-field "unlink" (get-alt "File" (param 0))) (identifier "srec_dst_837")))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "srec_dst_832"
              (let "srec_dst_831"
                (let "srec_dst_830"
                  (let "dst_ref_823"
                    (make-vec
                      (let "leb128_sz_821" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (param 0)))))
                        (let "leb128_ptr_822" (make-vec (identifier "ssum_dst_820"))
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
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_822"))))))
                    (let "n_ref_824" (make-vec (i32 0))
                      (seq
                        (for-each "x_825" (get-field "options" (get-alt "Kafka" (param 0)))
                          (seq
                            (set-vec (u8 0) (identifier "dst_ref_823")
                              (let "stup_dst_829"
                                (let "stup_dst_826" (unsafe-nth (u8 0) (identifier "dst_ref_823"))
                                  (write-bytes
                                    (let "leb128_sz_827" (make-vec (string-length (get-item 0 (identifier "x_825"))))
                                      (let "leb128_ptr_828" (make-vec (identifier "stup_dst_826"))
                                        (seq
                                          (while
                                            (seq
                                              (set-vec (u8 0) (identifier "leb128_ptr_828")
                                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_828"))
                                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_827"))) 
                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_827"))) 
                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_827"))) (u8 128)))))
                                              (set-vec (u8 0) (identifier "leb128_sz_827") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_827")) (u8 7))) 
                                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_827")) (u32 0))) 
                                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_828"))))) 
                                    (bytes-of-string (get-item 0 (identifier "x_825"))))) 
                                (apply (ext-identifier raql_expr to-row-binary) (get-item 1 (identifier "x_825")) (identifier "stup_dst_829"))))
                            (set-vec (u8 0) (identifier "n_ref_824") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_824")))))) 
                        (unsafe-nth (u8 0) (identifier "dst_ref_823"))))) 
                  (apply (ext-identifier raql_expr to-row-binary) (get-field "topic" (get-alt "Kafka" (param 0))) (identifier "srec_dst_830")))
                (if (is-null (get-field "partitions" (get-alt "Kafka" (param 0)))) 
                  (write-u8 (identifier "srec_dst_831") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "partitions" (get-alt "Kafka" (param 0)))) (write-u8 (identifier "srec_dst_831") (u8 0)))))
              (let "ssum_dst_834" (write-u16 little-endian (identifier "srec_dst_832") (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))))
                (if (eq (u16 0) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
                  (identifier "ssum_dst_834")
                  (if (eq (u16 1) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))))
                    (apply (ext-identifier raql_expr to-row-binary) (get-alt "OffsetFromEnd" (get-field "restart_from" (get-alt "Kafka" (param 0)))) (identifier "ssum_dst_834"))
                    (if (eq (u16 2) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
                      (identifier "ssum_dst_834")
                      (seq (assert (eq (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))) (u16 3)))
                        (let "srec_dst_835"
                          (apply (ext-identifier raql_expr to-row-binary) (get-field "after_max_secs" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0))))) (identifier "ssum_dst_834"))
                          (apply (ext-identifier raql_expr to-row-binary) (get-field "after_max_events" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0))))) (identifier "srec_dst_835")))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::external_source> ,Pointer)> external_source_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::external_source> ,Pointer)> fun234 { [&fun234](std::shared_ptr<::dessser::gen::raql_operation::external_source>  p_0, Pointer p_1) {
    uint16_t id_235 { uint16_t((*p_0).index()) };
    Pointer id_236 { p_1.writeU16Le(id_235) };
    Pointer let_res_237;
    {
      Pointer ssum_dst_820 { id_236 };
      uint16_t id_238 { 0 };
      uint16_t id_239 { uint16_t((*p_0).index()) };
      bool id_240 { bool(id_238 == id_239) };
      Pointer choose_res_241;
      if (id_240) {
        auto fun242 { dessser::gen::raql_expr::to_row_binary };
        ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_243 { std::get<0 /* File */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_244 { id_243.fname };
        Pointer id_245 { fun242(id_244, ssum_dst_820) };
        Pointer let_res_246;
        {
          Pointer srec_dst_836 { id_245 };
          ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_247 { std::get<0 /* File */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_248 { id_247.preprocessor };
          bool id_249 { !(id_248.has_value ()) };
          Pointer choose_res_250;
          if (id_249) {
            uint8_t id_251 { 1 };
            Pointer id_252 { srec_dst_836.writeU8(id_251) };
            choose_res_250 = id_252;
          } else {
            auto fun253 { dessser::gen::raql_expr::to_row_binary };
            ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_254 { std::get<0 /* File */>((*p_0)) };
            std::optional<dessser::gen::raql_expr::t_ext> id_255 { id_254.preprocessor };
            dessser::gen::raql_expr::t_ext id_256 { id_255.value() };
            uint8_t id_257 { 0 };
            Pointer id_258 { srec_dst_836.writeU8(id_257) };
            Pointer id_259 { fun253(id_256, id_258) };
            choose_res_250 = id_259;
          }
          let_res_246 = choose_res_250;
        }
        Pointer let_res_260;
        {
          Pointer srec_dst_837 { let_res_246 };
          auto fun261 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_262 { std::get<0 /* File */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_263 { id_262.unlink };
          Pointer id_264 { fun261(id_263, srec_dst_837) };
          let_res_260 = id_264;
        }
        choose_res_241 = let_res_260;
      } else {
        uint16_t id_265 { uint16_t((*p_0).index()) };
        uint16_t id_266 { 1 };
        bool id_267 { bool(id_265 == id_266) };
        Void id_268 { ((void)(assert(id_267)), ::dessser::VOID) };
        (void)id_268;
        ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_269 { std::get<1 /* Kafka */>((*p_0)) };
        Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> id_270 { id_269.options };
        uint32_t id_271 { id_270.size() };
        Vec<1, uint32_t> id_272 {  id_271  };
        Pointer let_res_273;
        {
          Vec<1, uint32_t> leb128_sz_821 { id_272 };
          Vec<1, Pointer> id_274 {  ssum_dst_820  };
          Pointer let_res_275;
          {
            Vec<1, Pointer> leb128_ptr_822 { id_274 };
            bool while_flag_276 { true };
            do {
              uint8_t id_277 { 0 };
              uint8_t id_278 { 0 };
              Pointer id_279 { leb128_ptr_822[id_278] };
              uint32_t id_280 { 128U };
              uint8_t id_281 { 0 };
              uint32_t id_282 { leb128_sz_821[id_281] };
              bool id_283 { bool(id_280 > id_282) };
              uint8_t choose_res_284;
              if (id_283) {
                uint8_t id_285 { 0 };
                uint32_t id_286 { leb128_sz_821[id_285] };
                uint8_t id_287 { uint8_t(id_286) };
                choose_res_284 = id_287;
              } else {
                uint8_t id_288 { 0 };
                uint32_t id_289 { leb128_sz_821[id_288] };
                uint8_t id_290 { uint8_t(id_289) };
                uint8_t id_291 { 128 };
                uint8_t id_292 { uint8_t(id_290 | id_291) };
                choose_res_284 = id_292;
              }
              Pointer id_293 { id_279.writeU8(choose_res_284) };
              Void id_294 { ((void)(leb128_ptr_822[id_277] = id_293), ::dessser::VOID) };
              (void)id_294;
              uint8_t id_295 { 0 };
              uint8_t id_296 { 0 };
              uint32_t id_297 { leb128_sz_821[id_296] };
              uint8_t id_298 { 7 };
              uint32_t id_299 { uint32_t(id_297 >> id_298) };
              Void id_300 { ((void)(leb128_sz_821[id_295] = id_299), ::dessser::VOID) };
              (void)id_300;
              uint8_t id_301 { 0 };
              uint32_t id_302 { leb128_sz_821[id_301] };
              uint32_t id_303 { 0U };
              bool id_304 { bool(id_302 > id_303) };
              while_flag_276 = id_304;
              if (while_flag_276) {
                (void)::dessser::VOID;
              }
            } while (while_flag_276);
            (void)::dessser::VOID;
            uint8_t id_305 { 0 };
            Pointer id_306 { leb128_ptr_822[id_305] };
            let_res_275 = id_306;
          }
          let_res_273 = let_res_275;
        }
        Vec<1, Pointer> id_307 {  let_res_273  };
        Pointer let_res_308;
        {
          Vec<1, Pointer> dst_ref_823 { id_307 };
          int32_t id_309 { 0L };
          Vec<1, int32_t> id_310 {  id_309  };
          Pointer let_res_311;
          {
            Vec<1, int32_t> n_ref_824 { id_310 };
            ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_312 { std::get<1 /* Kafka */>((*p_0)) };
            Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> id_313 { id_312.options };
            for (::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179 x_825 : id_313) {
              uint8_t id_314 { 0 };
              uint8_t id_315 { 0 };
              Pointer id_316 { dst_ref_823[id_315] };
              Pointer let_res_317;
              {
                Pointer stup_dst_826 { id_316 };
                std::string id_318 { std::get<0>(x_825) };
                uint32_t id_319 { (uint32_t)id_318.size() };
                Vec<1, uint32_t> id_320 {  id_319  };
                Pointer let_res_321;
                {
                  Vec<1, uint32_t> leb128_sz_827 { id_320 };
                  Vec<1, Pointer> id_322 {  stup_dst_826  };
                  Pointer let_res_323;
                  {
                    Vec<1, Pointer> leb128_ptr_828 { id_322 };
                    bool while_flag_324 { true };
                    do {
                      uint8_t id_325 { 0 };
                      uint8_t id_326 { 0 };
                      Pointer id_327 { leb128_ptr_828[id_326] };
                      uint32_t id_328 { 128U };
                      uint8_t id_329 { 0 };
                      uint32_t id_330 { leb128_sz_827[id_329] };
                      bool id_331 { bool(id_328 > id_330) };
                      uint8_t choose_res_332;
                      if (id_331) {
                        uint8_t id_333 { 0 };
                        uint32_t id_334 { leb128_sz_827[id_333] };
                        uint8_t id_335 { uint8_t(id_334) };
                        choose_res_332 = id_335;
                      } else {
                        uint8_t id_336 { 0 };
                        uint32_t id_337 { leb128_sz_827[id_336] };
                        uint8_t id_338 { uint8_t(id_337) };
                        uint8_t id_339 { 128 };
                        uint8_t id_340 { uint8_t(id_338 | id_339) };
                        choose_res_332 = id_340;
                      }
                      Pointer id_341 { id_327.writeU8(choose_res_332) };
                      Void id_342 { ((void)(leb128_ptr_828[id_325] = id_341), ::dessser::VOID) };
                      (void)id_342;
                      uint8_t id_343 { 0 };
                      uint8_t id_344 { 0 };
                      uint32_t id_345 { leb128_sz_827[id_344] };
                      uint8_t id_346 { 7 };
                      uint32_t id_347 { uint32_t(id_345 >> id_346) };
                      Void id_348 { ((void)(leb128_sz_827[id_343] = id_347), ::dessser::VOID) };
                      (void)id_348;
                      uint8_t id_349 { 0 };
                      uint32_t id_350 { leb128_sz_827[id_349] };
                      uint32_t id_351 { 0U };
                      bool id_352 { bool(id_350 > id_351) };
                      while_flag_324 = id_352;
                      if (while_flag_324) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_324);
                    (void)::dessser::VOID;
                    uint8_t id_353 { 0 };
                    Pointer id_354 { leb128_ptr_828[id_353] };
                    let_res_323 = id_354;
                  }
                  let_res_321 = let_res_323;
                }
                std::string id_355 { std::get<0>(x_825) };
                Bytes id_356 { id_355 };
                Pointer id_357 { let_res_321.writeBytes(id_356) };
                let_res_317 = id_357;
              }
              Pointer let_res_358;
              {
                Pointer stup_dst_829 { let_res_317 };
                auto fun359 { dessser::gen::raql_expr::to_row_binary };
                dessser::gen::raql_expr::t_ext id_360 { std::get<1>(x_825) };
                Pointer id_361 { fun359(id_360, stup_dst_829) };
                let_res_358 = id_361;
              }
              Void id_362 { ((void)(dst_ref_823[id_314] = let_res_358), ::dessser::VOID) };
              (void)id_362;
              uint8_t id_363 { 0 };
              int32_t id_364 { 1L };
              uint8_t id_365 { 0 };
              int32_t id_366 { n_ref_824[id_365] };
              int32_t id_367 { int32_t(id_364 + id_366) };
              Void id_368 { ((void)(n_ref_824[id_363] = id_367), ::dessser::VOID) };
              (void)id_368;
              (void)id_368;
            }
            (void)::dessser::VOID;
            uint8_t id_369 { 0 };
            Pointer id_370 { dst_ref_823[id_369] };
            let_res_311 = id_370;
          }
          let_res_308 = let_res_311;
        }
        Pointer let_res_371;
        {
          Pointer srec_dst_830 { let_res_308 };
          auto fun372 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_373 { std::get<1 /* Kafka */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_374 { id_373.topic };
          Pointer id_375 { fun372(id_374, srec_dst_830) };
          let_res_371 = id_375;
        }
        Pointer let_res_376;
        {
          Pointer srec_dst_831 { let_res_371 };
          ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_377 { std::get<1 /* Kafka */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_378 { id_377.partitions };
          bool id_379 { !(id_378.has_value ()) };
          Pointer choose_res_380;
          if (id_379) {
            uint8_t id_381 { 1 };
            Pointer id_382 { srec_dst_831.writeU8(id_381) };
            choose_res_380 = id_382;
          } else {
            auto fun383 { dessser::gen::raql_expr::to_row_binary };
            ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_384 { std::get<1 /* Kafka */>((*p_0)) };
            std::optional<dessser::gen::raql_expr::t_ext> id_385 { id_384.partitions };
            dessser::gen::raql_expr::t_ext id_386 { id_385.value() };
            uint8_t id_387 { 0 };
            Pointer id_388 { srec_dst_831.writeU8(id_387) };
            Pointer id_389 { fun383(id_386, id_388) };
            choose_res_380 = id_389;
          }
          let_res_376 = choose_res_380;
        }
        Pointer let_res_390;
        {
          Pointer srec_dst_832 { let_res_376 };
          ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_391 { std::get<1 /* Kafka */>((*p_0)) };
          ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_392 { id_391.restart_from };
          uint16_t id_393 { uint16_t(id_392.index()) };
          Pointer id_394 { srec_dst_832.writeU16Le(id_393) };
          Pointer let_res_395;
          {
            Pointer ssum_dst_834 { id_394 };
            uint16_t id_396 { 0 };
            ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_397 { std::get<1 /* Kafka */>((*p_0)) };
            ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_398 { id_397.restart_from };
            uint16_t id_399 { uint16_t(id_398.index()) };
            bool id_400 { bool(id_396 == id_399) };
            Pointer choose_res_401;
            if (id_400) {
              choose_res_401 = ssum_dst_834;
            } else {
              uint16_t id_402 { 1 };
              ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_403 { std::get<1 /* Kafka */>((*p_0)) };
              ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_404 { id_403.restart_from };
              uint16_t id_405 { uint16_t(id_404.index()) };
              bool id_406 { bool(id_402 == id_405) };
              Pointer choose_res_407;
              if (id_406) {
                auto fun408 { dessser::gen::raql_expr::to_row_binary };
                ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_409 { std::get<1 /* Kafka */>((*p_0)) };
                ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_410 { id_409.restart_from };
                dessser::gen::raql_expr::t_ext id_411 { std::get<1 /* OffsetFromEnd */>(id_410) };
                Pointer id_412 { fun408(id_411, ssum_dst_834) };
                choose_res_407 = id_412;
              } else {
                uint16_t id_413 { 2 };
                ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_414 { std::get<1 /* Kafka */>((*p_0)) };
                ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_415 { id_414.restart_from };
                uint16_t id_416 { uint16_t(id_415.index()) };
                bool id_417 { bool(id_413 == id_416) };
                Pointer choose_res_418;
                if (id_417) {
                  choose_res_418 = ssum_dst_834;
                } else {
                  ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_419 { std::get<1 /* Kafka */>((*p_0)) };
                  ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_420 { id_419.restart_from };
                  uint16_t id_421 { uint16_t(id_420.index()) };
                  uint16_t id_422 { 3 };
                  bool id_423 { bool(id_421 == id_422) };
                  Void id_424 { ((void)(assert(id_423)), ::dessser::VOID) };
                  (void)id_424;
                  auto fun425 { dessser::gen::raql_expr::to_row_binary };
                  ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_426 { std::get<1 /* Kafka */>((*p_0)) };
                  ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_427 { id_426.restart_from };
                  ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_428 { std::get<3 /* UseKafkaGroupCoordinator */>(id_427) };
                  dessser::gen::raql_expr::t_ext id_429 { id_428.after_max_secs };
                  Pointer id_430 { fun425(id_429, ssum_dst_834) };
                  Pointer let_res_431;
                  {
                    Pointer srec_dst_835 { id_430 };
                    auto fun432 { dessser::gen::raql_expr::to_row_binary };
                    ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_433 { std::get<1 /* Kafka */>((*p_0)) };
                    ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_434 { id_433.restart_from };
                    ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_435 { std::get<3 /* UseKafkaGroupCoordinator */>(id_434) };
                    dessser::gen::raql_expr::t_ext id_436 { id_435.after_max_events };
                    Pointer id_437 { fun432(id_436, srec_dst_835) };
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
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::external_source> ,Pointer)> external_source_to_row_binary(external_source_to_row_binary_init());

/* 
    (fun ("[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]")
      (if (eq (u16 0) (label-of (param 0)))
        (add
          (add
            (let "sz_738"
              (let "sz_734"
                (add
                  (add (size 3)
                    (add
                      (let "n_ref_731" (make-vec (string-length (get-field "null" (get-alt "CSV" (param 0)))))
                        (let "lebsz_ref_732" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_731")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_732")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_732") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_732")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_732")))))) 
                      (size-of-u32 (string-length (get-field "null" (get-alt "CSV" (param 0))))))) 
                  (size 1))
                (add (identifier "sz_734")
                  (add
                    (let "n_ref_736" (make-vec (string-length (get-field "escape_seq" (get-alt "CSV" (param 0)))))
                      (let "lebsz_ref_737" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_736")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_737")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_737") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_737")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_737")))))) 
                    (size-of-u32 (string-length (get-field "escape_seq" (get-alt "CSV" (param 0))))))))
              (let "sz_ref_741"
                (make-vec
                  (add (identifier "sz_738")
                    (let "n_ref_739" (make-vec (cardinality (get-field "fields" (get-alt "CSV" (param 0)))))
                      (let "lebsz_ref_740" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_739")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_740")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_740") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_740")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_740"))))))))
                (seq
                  (let "repeat_n_742" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "fields" (get-alt "CSV" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_742")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_741")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_741"))
                            (apply (ext-identifier field_type sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_742")) (get-field "fields" (get-alt "CSV" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_742") (add (unsafe-nth (u8 0) (identifier "repeat_n_742")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_741"))))) (size 1)) 
          (size 1))
        (seq (assert (eq (label-of (param 0)) (u16 1)))
          (let "sz_ref_726"
            (make-vec
              (add (size 2)
                (let "n_ref_724" (make-vec (cardinality (get-alt "RowBinary" (param 0))))
                  (let "lebsz_ref_725" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_724")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_725")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_725") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_725")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_725"))))))))
            (seq
              (let "repeat_n_727" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-alt "RowBinary" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_727")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_726")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_726")) (apply (ext-identifier field_type sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_727")) (get-alt "RowBinary" (param 0))))))
                    (set-vec (u8 0) (identifier "repeat_n_727") (add (unsafe-nth (u8 0) (identifier "repeat_n_727")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_726")))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::external_format> )> external_format_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::external_format> )> fun438 { [&fun438](std::shared_ptr<::dessser::gen::raql_operation::external_format>  p_0) {
    uint16_t id_439 { 0 };
    uint16_t id_440 { uint16_t((*p_0).index()) };
    bool id_441 { bool(id_439 == id_440) };
    Size choose_res_442;
    if (id_441) {
      Size id_443 { 3UL };
      ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_444 { std::get<0 /* CSV */>((*p_0)) };
      std::string id_445 { id_444.null };
      uint32_t id_446 { (uint32_t)id_445.size() };
      Vec<1, uint32_t> id_447 {  id_446  };
      Size let_res_448;
      {
        Vec<1, uint32_t> n_ref_731 { id_447 };
        uint32_t id_449 { 1U };
        Vec<1, uint32_t> id_450 {  id_449  };
        Size let_res_451;
        {
          Vec<1, uint32_t> lebsz_ref_732 { id_450 };
          bool while_flag_452 { true };
          do {
            uint8_t id_453 { 0 };
            uint32_t id_454 { n_ref_731[id_453] };
            uint8_t id_455 { 0 };
            uint32_t id_456 { lebsz_ref_732[id_455] };
            uint8_t id_457 { 7 };
            uint32_t id_458 { uint32_t(id_456 << id_457) };
            bool id_459 { bool(id_454 >= id_458) };
            while_flag_452 = id_459;
            if (while_flag_452) {
              uint8_t id_460 { 0 };
              uint8_t id_461 { 0 };
              uint32_t id_462 { lebsz_ref_732[id_461] };
              uint32_t id_463 { 1U };
              uint32_t id_464 { uint32_t(id_462 + id_463) };
              Void id_465 { ((void)(lebsz_ref_732[id_460] = id_464), ::dessser::VOID) };
              (void)id_465;
            }
          } while (while_flag_452);
          (void)::dessser::VOID;
          uint8_t id_466 { 0 };
          uint32_t id_467 { lebsz_ref_732[id_466] };
          Size id_468 { Size(id_467) };
          let_res_451 = id_468;
        }
        let_res_448 = let_res_451;
      }
      ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_469 { std::get<0 /* CSV */>((*p_0)) };
      std::string id_470 { id_469.null };
      uint32_t id_471 { (uint32_t)id_470.size() };
      Size id_472 { Size(id_471) };
      Size id_473 { Size(let_res_448 + id_472) };
      Size id_474 { Size(id_443 + id_473) };
      Size id_475 { 1UL };
      Size id_476 { Size(id_474 + id_475) };
      Size let_res_477;
      {
        Size sz_734 { id_476 };
        ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_478 { std::get<0 /* CSV */>((*p_0)) };
        std::string id_479 { id_478.escape_seq };
        uint32_t id_480 { (uint32_t)id_479.size() };
        Vec<1, uint32_t> id_481 {  id_480  };
        Size let_res_482;
        {
          Vec<1, uint32_t> n_ref_736 { id_481 };
          uint32_t id_483 { 1U };
          Vec<1, uint32_t> id_484 {  id_483  };
          Size let_res_485;
          {
            Vec<1, uint32_t> lebsz_ref_737 { id_484 };
            bool while_flag_486 { true };
            do {
              uint8_t id_487 { 0 };
              uint32_t id_488 { n_ref_736[id_487] };
              uint8_t id_489 { 0 };
              uint32_t id_490 { lebsz_ref_737[id_489] };
              uint8_t id_491 { 7 };
              uint32_t id_492 { uint32_t(id_490 << id_491) };
              bool id_493 { bool(id_488 >= id_492) };
              while_flag_486 = id_493;
              if (while_flag_486) {
                uint8_t id_494 { 0 };
                uint8_t id_495 { 0 };
                uint32_t id_496 { lebsz_ref_737[id_495] };
                uint32_t id_497 { 1U };
                uint32_t id_498 { uint32_t(id_496 + id_497) };
                Void id_499 { ((void)(lebsz_ref_737[id_494] = id_498), ::dessser::VOID) };
                (void)id_499;
              }
            } while (while_flag_486);
            (void)::dessser::VOID;
            uint8_t id_500 { 0 };
            uint32_t id_501 { lebsz_ref_737[id_500] };
            Size id_502 { Size(id_501) };
            let_res_485 = id_502;
          }
          let_res_482 = let_res_485;
        }
        ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_503 { std::get<0 /* CSV */>((*p_0)) };
        std::string id_504 { id_503.escape_seq };
        uint32_t id_505 { (uint32_t)id_504.size() };
        Size id_506 { Size(id_505) };
        Size id_507 { Size(let_res_482 + id_506) };
        Size id_508 { Size(sz_734 + id_507) };
        let_res_477 = id_508;
      }
      Size let_res_509;
      {
        Size sz_738 { let_res_477 };
        ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_510 { std::get<0 /* CSV */>((*p_0)) };
        Lst<dessser::gen::field_type::t_ext> id_511 { id_510.fields };
        uint32_t id_512 { id_511.size() };
        Vec<1, uint32_t> id_513 {  id_512  };
        Size let_res_514;
        {
          Vec<1, uint32_t> n_ref_739 { id_513 };
          uint32_t id_515 { 1U };
          Vec<1, uint32_t> id_516 {  id_515  };
          Size let_res_517;
          {
            Vec<1, uint32_t> lebsz_ref_740 { id_516 };
            bool while_flag_518 { true };
            do {
              uint8_t id_519 { 0 };
              uint32_t id_520 { n_ref_739[id_519] };
              uint8_t id_521 { 0 };
              uint32_t id_522 { lebsz_ref_740[id_521] };
              uint8_t id_523 { 7 };
              uint32_t id_524 { uint32_t(id_522 << id_523) };
              bool id_525 { bool(id_520 >= id_524) };
              while_flag_518 = id_525;
              if (while_flag_518) {
                uint8_t id_526 { 0 };
                uint8_t id_527 { 0 };
                uint32_t id_528 { lebsz_ref_740[id_527] };
                uint32_t id_529 { 1U };
                uint32_t id_530 { uint32_t(id_528 + id_529) };
                Void id_531 { ((void)(lebsz_ref_740[id_526] = id_530), ::dessser::VOID) };
                (void)id_531;
              }
            } while (while_flag_518);
            (void)::dessser::VOID;
            uint8_t id_532 { 0 };
            uint32_t id_533 { lebsz_ref_740[id_532] };
            Size id_534 { Size(id_533) };
            let_res_517 = id_534;
          }
          let_res_514 = let_res_517;
        }
        Size id_535 { Size(sz_738 + let_res_514) };
        Vec<1, Size> id_536 {  id_535  };
        Size let_res_537;
        {
          Vec<1, Size> sz_ref_741 { id_536 };
          int32_t id_538 { 0L };
          Vec<1, int32_t> id_539 {  id_538  };
          {
            Vec<1, int32_t> repeat_n_742 { id_539 };
            bool while_flag_540 { true };
            do {
              ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_541 { std::get<0 /* CSV */>((*p_0)) };
              Lst<dessser::gen::field_type::t_ext> id_542 { id_541.fields };
              uint32_t id_543 { id_542.size() };
              int32_t id_544 { int32_t(id_543) };
              uint8_t id_545 { 0 };
              int32_t id_546 { repeat_n_742[id_545] };
              bool id_547 { bool(id_544 > id_546) };
              while_flag_540 = id_547;
              if (while_flag_540) {
                uint8_t id_548 { 0 };
                uint8_t id_549 { 0 };
                Size id_550 { sz_ref_741[id_549] };
                auto fun551 { dessser::gen::field_type::sersize_of_row_binary };
                uint8_t id_552 { 0 };
                int32_t id_553 { repeat_n_742[id_552] };
                ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_554 { std::get<0 /* CSV */>((*p_0)) };
                Lst<dessser::gen::field_type::t_ext> id_555 { id_554.fields };
                dessser::gen::field_type::t_ext id_556 { id_555[id_553] };
                Size id_557 { fun551(id_556) };
                Size id_558 { Size(id_550 + id_557) };
                Void id_559 { ((void)(sz_ref_741[id_548] = id_558), ::dessser::VOID) };
                (void)id_559;
                uint8_t id_560 { 0 };
                uint8_t id_561 { 0 };
                int32_t id_562 { repeat_n_742[id_561] };
                int32_t id_563 { 1L };
                int32_t id_564 { int32_t(id_562 + id_563) };
                Void id_565 { ((void)(repeat_n_742[id_560] = id_564), ::dessser::VOID) };
                (void)id_565;
                (void)id_565;
              }
            } while (while_flag_540);
            (void)::dessser::VOID;
          }
          (void)::dessser::VOID;
          uint8_t id_566 { 0 };
          Size id_567 { sz_ref_741[id_566] };
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
      uint16_t id_572 { uint16_t((*p_0).index()) };
      uint16_t id_573 { 1 };
      bool id_574 { bool(id_572 == id_573) };
      Void id_575 { ((void)(assert(id_574)), ::dessser::VOID) };
      (void)id_575;
      Size id_576 { 2UL };
      Lst<dessser::gen::field_type::t_ext> id_577 { std::get<1 /* RowBinary */>((*p_0)) };
      uint32_t id_578 { id_577.size() };
      Vec<1, uint32_t> id_579 {  id_578  };
      Size let_res_580;
      {
        Vec<1, uint32_t> n_ref_724 { id_579 };
        uint32_t id_581 { 1U };
        Vec<1, uint32_t> id_582 {  id_581  };
        Size let_res_583;
        {
          Vec<1, uint32_t> lebsz_ref_725 { id_582 };
          bool while_flag_584 { true };
          do {
            uint8_t id_585 { 0 };
            uint32_t id_586 { n_ref_724[id_585] };
            uint8_t id_587 { 0 };
            uint32_t id_588 { lebsz_ref_725[id_587] };
            uint8_t id_589 { 7 };
            uint32_t id_590 { uint32_t(id_588 << id_589) };
            bool id_591 { bool(id_586 >= id_590) };
            while_flag_584 = id_591;
            if (while_flag_584) {
              uint8_t id_592 { 0 };
              uint8_t id_593 { 0 };
              uint32_t id_594 { lebsz_ref_725[id_593] };
              uint32_t id_595 { 1U };
              uint32_t id_596 { uint32_t(id_594 + id_595) };
              Void id_597 { ((void)(lebsz_ref_725[id_592] = id_596), ::dessser::VOID) };
              (void)id_597;
            }
          } while (while_flag_584);
          (void)::dessser::VOID;
          uint8_t id_598 { 0 };
          uint32_t id_599 { lebsz_ref_725[id_598] };
          Size id_600 { Size(id_599) };
          let_res_583 = id_600;
        }
        let_res_580 = let_res_583;
      }
      Size id_601 { Size(id_576 + let_res_580) };
      Vec<1, Size> id_602 {  id_601  };
      Size let_res_603;
      {
        Vec<1, Size> sz_ref_726 { id_602 };
        int32_t id_604 { 0L };
        Vec<1, int32_t> id_605 {  id_604  };
        {
          Vec<1, int32_t> repeat_n_727 { id_605 };
          bool while_flag_606 { true };
          do {
            Lst<dessser::gen::field_type::t_ext> id_607 { std::get<1 /* RowBinary */>((*p_0)) };
            uint32_t id_608 { id_607.size() };
            int32_t id_609 { int32_t(id_608) };
            uint8_t id_610 { 0 };
            int32_t id_611 { repeat_n_727[id_610] };
            bool id_612 { bool(id_609 > id_611) };
            while_flag_606 = id_612;
            if (while_flag_606) {
              uint8_t id_613 { 0 };
              uint8_t id_614 { 0 };
              Size id_615 { sz_ref_726[id_614] };
              auto fun616 { dessser::gen::field_type::sersize_of_row_binary };
              uint8_t id_617 { 0 };
              int32_t id_618 { repeat_n_727[id_617] };
              Lst<dessser::gen::field_type::t_ext> id_619 { std::get<1 /* RowBinary */>((*p_0)) };
              dessser::gen::field_type::t_ext id_620 { id_619[id_618] };
              Size id_621 { fun616(id_620) };
              Size id_622 { Size(id_615 + id_621) };
              Void id_623 { ((void)(sz_ref_726[id_613] = id_622), ::dessser::VOID) };
              (void)id_623;
              uint8_t id_624 { 0 };
              uint8_t id_625 { 0 };
              int32_t id_626 { repeat_n_727[id_625] };
              int32_t id_627 { 1L };
              int32_t id_628 { int32_t(id_626 + id_627) };
              Void id_629 { ((void)(repeat_n_727[id_624] = id_628), ::dessser::VOID) };
              (void)id_629;
              (void)id_629;
            }
          } while (while_flag_606);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_630 { 0 };
        Size id_631 { sz_ref_726[id_630] };
        let_res_603 = id_631;
      }
      choose_res_442 = let_res_603;
    }
    return choose_res_442;
  }
   };
  return fun438;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::external_format> )> external_format_sersize_of_row_binary(external_format_sersize_of_row_binary_init());

/* 
    (fun ("[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_722"
          (let "sz_721" (add (size 2) (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "fname" (get-alt "File" (param 0)))))
            (if (is-null (get-field "preprocessor" (get-alt "File" (param 0)))) 
              (add (identifier "sz_721") (size 1)) (add (add (identifier "sz_721") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "preprocessor" (get-alt "File" (param 0)))))) (size 1))))
          (add (identifier "sz_722") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "unlink" (get-alt "File" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1)))
          (let "sz_716"
            (let "sz_715"
              (let "sz_714"
                (let "sz_ref_707"
                  (make-vec
                    (add (size 2)
                      (let "n_ref_705" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (param 0)))))
                        (let "lebsz_ref_706" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_705")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_706")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_706") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_706")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_706"))))))))
                  (seq
                    (let "repeat_n_708" (make-vec (i32 0))
                      (while (gt (to-i32 (cardinality (get-field "options" (get-alt "Kafka" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_708")))
                        (seq
                          (set-vec (u8 0) (identifier "sz_ref_707")
                            (let "sz_713"
                              (let "sz_709" (unsafe-nth (u8 0) (identifier "sz_ref_707"))
                                (add (identifier "sz_709")
                                  (let "wlen_710" (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_708")) (get-field "options" (get-alt "Kafka" (param 0))))))
                                    (add
                                      (let "n_ref_711" (make-vec (identifier "wlen_710"))
                                        (let "lebsz_ref_712" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_711")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_712")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_712") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_712")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_712")))))) 
                                      (size-of-u32 (identifier "wlen_710"))))))
                              (add (identifier "sz_713")
                                (apply (ext-identifier raql_expr sersize-of-row-binary) (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_708")) (get-field "options" (get-alt "Kafka" (param 0)))))))))
                          (set-vec (u8 0) (identifier "repeat_n_708") (add (unsafe-nth (u8 0) (identifier "repeat_n_708")) (i32 1)))))) 
                    (unsafe-nth (u8 0) (identifier "sz_ref_707")))) (add (identifier "sz_714") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "topic" (get-alt "Kafka" (param 0))))))
              (if (is-null (get-field "partitions" (get-alt "Kafka" (param 0)))) 
                (add (identifier "sz_715") (size 1)) (add (add (identifier "sz_715") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "partitions" (get-alt "Kafka" (param 0)))))) (size 1))))
            (if (eq (u16 0) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
              (add (identifier "sz_716") (size 2))
              (if (eq (u16 1) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))))
                (add (add (identifier "sz_716") (size 2)) (apply (ext-identifier raql_expr sersize-of-row-binary) (get-alt "OffsetFromEnd" (get-field "restart_from" (get-alt "Kafka" (param 0))))))
                (if (eq (u16 2) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
                  (add (identifier "sz_716") (size 2))
                  (seq (assert (eq (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))) (u16 3)))
                    (let "sz_719"
                      (add (add (identifier "sz_716") (size 2))
                        (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "after_max_secs" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0)))))))
                      (add (identifier "sz_719") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "after_max_events" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::external_source> )> external_source_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::external_source> )> fun632 { [&fun632](std::shared_ptr<::dessser::gen::raql_operation::external_source>  p_0) {
    uint16_t id_633 { 0 };
    uint16_t id_634 { uint16_t((*p_0).index()) };
    bool id_635 { bool(id_633 == id_634) };
    Size choose_res_636;
    if (id_635) {
      Size id_637 { 2UL };
      auto fun638 { dessser::gen::raql_expr::sersize_of_row_binary };
      ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_639 { std::get<0 /* File */>((*p_0)) };
      dessser::gen::raql_expr::t_ext id_640 { id_639.fname };
      Size id_641 { fun638(id_640) };
      Size id_642 { Size(id_637 + id_641) };
      Size let_res_643;
      {
        Size sz_721 { id_642 };
        ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_644 { std::get<0 /* File */>((*p_0)) };
        std::optional<dessser::gen::raql_expr::t_ext> id_645 { id_644.preprocessor };
        bool id_646 { !(id_645.has_value ()) };
        Size choose_res_647;
        if (id_646) {
          Size id_648 { 1UL };
          Size id_649 { Size(sz_721 + id_648) };
          choose_res_647 = id_649;
        } else {
          auto fun650 { dessser::gen::raql_expr::sersize_of_row_binary };
          ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_651 { std::get<0 /* File */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_652 { id_651.preprocessor };
          dessser::gen::raql_expr::t_ext id_653 { id_652.value() };
          Size id_654 { fun650(id_653) };
          Size id_655 { Size(sz_721 + id_654) };
          Size id_656 { 1UL };
          Size id_657 { Size(id_655 + id_656) };
          choose_res_647 = id_657;
        }
        let_res_643 = choose_res_647;
      }
      Size let_res_658;
      {
        Size sz_722 { let_res_643 };
        auto fun659 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_660 { std::get<0 /* File */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_661 { id_660.unlink };
        Size id_662 { fun659(id_661) };
        Size id_663 { Size(sz_722 + id_662) };
        let_res_658 = id_663;
      }
      choose_res_636 = let_res_658;
    } else {
      uint16_t id_664 { uint16_t((*p_0).index()) };
      uint16_t id_665 { 1 };
      bool id_666 { bool(id_664 == id_665) };
      Void id_667 { ((void)(assert(id_666)), ::dessser::VOID) };
      (void)id_667;
      Size id_668 { 2UL };
      ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_669 { std::get<1 /* Kafka */>((*p_0)) };
      Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> id_670 { id_669.options };
      uint32_t id_671 { id_670.size() };
      Vec<1, uint32_t> id_672 {  id_671  };
      Size let_res_673;
      {
        Vec<1, uint32_t> n_ref_705 { id_672 };
        uint32_t id_674 { 1U };
        Vec<1, uint32_t> id_675 {  id_674  };
        Size let_res_676;
        {
          Vec<1, uint32_t> lebsz_ref_706 { id_675 };
          bool while_flag_677 { true };
          do {
            uint8_t id_678 { 0 };
            uint32_t id_679 { n_ref_705[id_678] };
            uint8_t id_680 { 0 };
            uint32_t id_681 { lebsz_ref_706[id_680] };
            uint8_t id_682 { 7 };
            uint32_t id_683 { uint32_t(id_681 << id_682) };
            bool id_684 { bool(id_679 >= id_683) };
            while_flag_677 = id_684;
            if (while_flag_677) {
              uint8_t id_685 { 0 };
              uint8_t id_686 { 0 };
              uint32_t id_687 { lebsz_ref_706[id_686] };
              uint32_t id_688 { 1U };
              uint32_t id_689 { uint32_t(id_687 + id_688) };
              Void id_690 { ((void)(lebsz_ref_706[id_685] = id_689), ::dessser::VOID) };
              (void)id_690;
            }
          } while (while_flag_677);
          (void)::dessser::VOID;
          uint8_t id_691 { 0 };
          uint32_t id_692 { lebsz_ref_706[id_691] };
          Size id_693 { Size(id_692) };
          let_res_676 = id_693;
        }
        let_res_673 = let_res_676;
      }
      Size id_694 { Size(id_668 + let_res_673) };
      Vec<1, Size> id_695 {  id_694  };
      Size let_res_696;
      {
        Vec<1, Size> sz_ref_707 { id_695 };
        int32_t id_697 { 0L };
        Vec<1, int32_t> id_698 {  id_697  };
        {
          Vec<1, int32_t> repeat_n_708 { id_698 };
          bool while_flag_699 { true };
          do {
            ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_700 { std::get<1 /* Kafka */>((*p_0)) };
            Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> id_701 { id_700.options };
            uint32_t id_702 { id_701.size() };
            int32_t id_703 { int32_t(id_702) };
            uint8_t id_704 { 0 };
            int32_t id_705 { repeat_n_708[id_704] };
            bool id_706 { bool(id_703 > id_705) };
            while_flag_699 = id_706;
            if (while_flag_699) {
              uint8_t id_707 { 0 };
              uint8_t id_708 { 0 };
              Size id_709 { sz_ref_707[id_708] };
              Size let_res_710;
              {
                Size sz_709 { id_709 };
                uint8_t id_711 { 0 };
                int32_t id_712 { repeat_n_708[id_711] };
                ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_713 { std::get<1 /* Kafka */>((*p_0)) };
                Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> id_714 { id_713.options };
                ::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179 id_715 { id_714[id_712] };
                std::string id_716 { std::get<0>(id_715) };
                uint32_t id_717 { (uint32_t)id_716.size() };
                Size let_res_718;
                {
                  uint32_t wlen_710 { id_717 };
                  Vec<1, uint32_t> id_719 {  wlen_710  };
                  Size let_res_720;
                  {
                    Vec<1, uint32_t> n_ref_711 { id_719 };
                    uint32_t id_721 { 1U };
                    Vec<1, uint32_t> id_722 {  id_721  };
                    Size let_res_723;
                    {
                      Vec<1, uint32_t> lebsz_ref_712 { id_722 };
                      bool while_flag_724 { true };
                      do {
                        uint8_t id_725 { 0 };
                        uint32_t id_726 { n_ref_711[id_725] };
                        uint8_t id_727 { 0 };
                        uint32_t id_728 { lebsz_ref_712[id_727] };
                        uint8_t id_729 { 7 };
                        uint32_t id_730 { uint32_t(id_728 << id_729) };
                        bool id_731 { bool(id_726 >= id_730) };
                        while_flag_724 = id_731;
                        if (while_flag_724) {
                          uint8_t id_732 { 0 };
                          uint8_t id_733 { 0 };
                          uint32_t id_734 { lebsz_ref_712[id_733] };
                          uint32_t id_735 { 1U };
                          uint32_t id_736 { uint32_t(id_734 + id_735) };
                          Void id_737 { ((void)(lebsz_ref_712[id_732] = id_736), ::dessser::VOID) };
                          (void)id_737;
                        }
                      } while (while_flag_724);
                      (void)::dessser::VOID;
                      uint8_t id_738 { 0 };
                      uint32_t id_739 { lebsz_ref_712[id_738] };
                      Size id_740 { Size(id_739) };
                      let_res_723 = id_740;
                    }
                    let_res_720 = let_res_723;
                  }
                  Size id_741 { Size(wlen_710) };
                  Size id_742 { Size(let_res_720 + id_741) };
                  let_res_718 = id_742;
                }
                Size id_743 { Size(sz_709 + let_res_718) };
                let_res_710 = id_743;
              }
              Size let_res_744;
              {
                Size sz_713 { let_res_710 };
                auto fun745 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_746 { 0 };
                int32_t id_747 { repeat_n_708[id_746] };
                ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_748 { std::get<1 /* Kafka */>((*p_0)) };
                Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> id_749 { id_748.options };
                ::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179 id_750 { id_749[id_747] };
                dessser::gen::raql_expr::t_ext id_751 { std::get<1>(id_750) };
                Size id_752 { fun745(id_751) };
                Size id_753 { Size(sz_713 + id_752) };
                let_res_744 = id_753;
              }
              Void id_754 { ((void)(sz_ref_707[id_707] = let_res_744), ::dessser::VOID) };
              (void)id_754;
              uint8_t id_755 { 0 };
              uint8_t id_756 { 0 };
              int32_t id_757 { repeat_n_708[id_756] };
              int32_t id_758 { 1L };
              int32_t id_759 { int32_t(id_757 + id_758) };
              Void id_760 { ((void)(repeat_n_708[id_755] = id_759), ::dessser::VOID) };
              (void)id_760;
              (void)id_760;
            }
          } while (while_flag_699);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_761 { 0 };
        Size id_762 { sz_ref_707[id_761] };
        let_res_696 = id_762;
      }
      Size let_res_763;
      {
        Size sz_714 { let_res_696 };
        auto fun764 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_765 { std::get<1 /* Kafka */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_766 { id_765.topic };
        Size id_767 { fun764(id_766) };
        Size id_768 { Size(sz_714 + id_767) };
        let_res_763 = id_768;
      }
      Size let_res_769;
      {
        Size sz_715 { let_res_763 };
        ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_770 { std::get<1 /* Kafka */>((*p_0)) };
        std::optional<dessser::gen::raql_expr::t_ext> id_771 { id_770.partitions };
        bool id_772 { !(id_771.has_value ()) };
        Size choose_res_773;
        if (id_772) {
          Size id_774 { 1UL };
          Size id_775 { Size(sz_715 + id_774) };
          choose_res_773 = id_775;
        } else {
          auto fun776 { dessser::gen::raql_expr::sersize_of_row_binary };
          ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_777 { std::get<1 /* Kafka */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_778 { id_777.partitions };
          dessser::gen::raql_expr::t_ext id_779 { id_778.value() };
          Size id_780 { fun776(id_779) };
          Size id_781 { Size(sz_715 + id_780) };
          Size id_782 { 1UL };
          Size id_783 { Size(id_781 + id_782) };
          choose_res_773 = id_783;
        }
        let_res_769 = choose_res_773;
      }
      Size let_res_784;
      {
        Size sz_716 { let_res_769 };
        uint16_t id_785 { 0 };
        ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_786 { std::get<1 /* Kafka */>((*p_0)) };
        ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_787 { id_786.restart_from };
        uint16_t id_788 { uint16_t(id_787.index()) };
        bool id_789 { bool(id_785 == id_788) };
        Size choose_res_790;
        if (id_789) {
          Size id_791 { 2UL };
          Size id_792 { Size(sz_716 + id_791) };
          choose_res_790 = id_792;
        } else {
          uint16_t id_793 { 1 };
          ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_794 { std::get<1 /* Kafka */>((*p_0)) };
          ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_795 { id_794.restart_from };
          uint16_t id_796 { uint16_t(id_795.index()) };
          bool id_797 { bool(id_793 == id_796) };
          Size choose_res_798;
          if (id_797) {
            Size id_799 { 2UL };
            Size id_800 { Size(sz_716 + id_799) };
            auto fun801 { dessser::gen::raql_expr::sersize_of_row_binary };
            ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_802 { std::get<1 /* Kafka */>((*p_0)) };
            ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_803 { id_802.restart_from };
            dessser::gen::raql_expr::t_ext id_804 { std::get<1 /* OffsetFromEnd */>(id_803) };
            Size id_805 { fun801(id_804) };
            Size id_806 { Size(id_800 + id_805) };
            choose_res_798 = id_806;
          } else {
            uint16_t id_807 { 2 };
            ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_808 { std::get<1 /* Kafka */>((*p_0)) };
            ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_809 { id_808.restart_from };
            uint16_t id_810 { uint16_t(id_809.index()) };
            bool id_811 { bool(id_807 == id_810) };
            Size choose_res_812;
            if (id_811) {
              Size id_813 { 2UL };
              Size id_814 { Size(sz_716 + id_813) };
              choose_res_812 = id_814;
            } else {
              ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_815 { std::get<1 /* Kafka */>((*p_0)) };
              ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_816 { id_815.restart_from };
              uint16_t id_817 { uint16_t(id_816.index()) };
              uint16_t id_818 { 3 };
              bool id_819 { bool(id_817 == id_818) };
              Void id_820 { ((void)(assert(id_819)), ::dessser::VOID) };
              (void)id_820;
              Size id_821 { 2UL };
              Size id_822 { Size(sz_716 + id_821) };
              auto fun823 { dessser::gen::raql_expr::sersize_of_row_binary };
              ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_824 { std::get<1 /* Kafka */>((*p_0)) };
              ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_825 { id_824.restart_from };
              ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_826 { std::get<3 /* UseKafkaGroupCoordinator */>(id_825) };
              dessser::gen::raql_expr::t_ext id_827 { id_826.after_max_secs };
              Size id_828 { fun823(id_827) };
              Size id_829 { Size(id_822 + id_828) };
              Size let_res_830;
              {
                Size sz_719 { id_829 };
                auto fun831 { dessser::gen::raql_expr::sersize_of_row_binary };
                ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_832 { std::get<1 /* Kafka */>((*p_0)) };
                ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_833 { id_832.restart_from };
                ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_834 { std::get<3 /* UseKafkaGroupCoordinator */>(id_833) };
                dessser::gen::raql_expr::t_ext id_835 { id_834.after_max_events };
                Size id_836 { fun831(id_835) };
                Size id_837 { Size(sz_719 + id_836) };
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
std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::external_source> )> external_source_sersize_of_row_binary(external_source_sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_241" (let-pair "du16_fst_236" "du16_snd_237" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_236") (identifier "du16_snd_237")))
        (let-pair "dsum1_fst_242" "dsum1_snd_243" (identifier "dsum1_241")
          (if (eq (u16 0) (identifier "dsum1_fst_242"))
            (let "drec_273" (let-pair "dchar_fst_271" "dchar_snd_272" (read-u8 (identifier "dsum1_snd_243")) (make-tup (char-of-u8 (identifier "dchar_fst_271")) (identifier "dchar_snd_272")))
              (let-pair "drec_fst_274" "drec_snd_275" (identifier "drec_273")
                (let "drec_288"
                  (let "dstring1_282"
                    (let "leb_ref_276" (make-vec (u32 0))
                      (let "shft_ref_277" (make-vec (u8 0))
                        (let "p_ref_278" (make-vec (identifier "drec_snd_275"))
                          (seq
                            (while
                              (let "leb128_279" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_278")))
                                (let-pair "leb128_fst_280" "leb128_snd_281" 
                                  (identifier "leb128_279")
                                  (seq (set-vec (u8 0) (identifier "p_ref_278") (identifier "leb128_snd_281"))
                                    (set-vec (u8 0) (identifier "leb_ref_276")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_280") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_277"))) (unsafe-nth (u8 0) (identifier "leb_ref_276"))))
                                    (set-vec (u8 0) (identifier "shft_ref_277") (add (unsafe-nth (u8 0) (identifier "shft_ref_277")) (u8 7))) 
                                    (ge (identifier "leb128_fst_280") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_276"))) (unsafe-nth (u8 0) (identifier "p_ref_278")))))))
                    (let-pair "dstring1_fst_283" "dstring1_snd_284" (identifier "dstring1_282")
                      (let-pair "dstring2_fst_286" "dstring2_snd_287" 
                        (read-bytes (identifier "dstring1_snd_284") (identifier "dstring1_fst_283")) 
                        (make-tup (string-of-bytes (identifier "dstring2_fst_286")) (identifier "dstring2_snd_287")))))
                  (let-pair "drec_fst_289" "drec_snd_290" (identifier "drec_288")
                    (let "drec_294" (let-pair "dbool_fst_292" "dbool_snd_293" (read-u8 (identifier "drec_snd_290")) (make-tup (not (eq (identifier "dbool_fst_292") (u8 0))) (identifier "dbool_snd_293")))
                      (let-pair "drec_fst_295" "drec_snd_296" (identifier "drec_294")
                        (let "drec_309"
                          (let "dstring1_303"
                            (let "leb_ref_297" (make-vec (u32 0))
                              (let "shft_ref_298" (make-vec (u8 0))
                                (let "p_ref_299" (make-vec (identifier "drec_snd_296"))
                                  (seq
                                    (while
                                      (let "leb128_300" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_299")))
                                        (let-pair "leb128_fst_301" "leb128_snd_302" 
                                          (identifier "leb128_300")
                                          (seq (set-vec (u8 0) (identifier "p_ref_299") (identifier "leb128_snd_302"))
                                            (set-vec (u8 0) (identifier "leb_ref_297")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_301") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_298"))) (unsafe-nth (u8 0) (identifier "leb_ref_297"))))
                                            (set-vec (u8 0) (identifier "shft_ref_298") (add (unsafe-nth (u8 0) (identifier "shft_ref_298")) (u8 7))) 
                                            (ge (identifier "leb128_fst_301") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_297"))) (unsafe-nth (u8 0) (identifier "p_ref_299")))))))
                            (let-pair "dstring1_fst_304" "dstring1_snd_305" 
                              (identifier "dstring1_303")
                              (let-pair "dstring2_fst_307" "dstring2_snd_308" 
                                (read-bytes (identifier "dstring1_snd_305") (identifier "dstring1_fst_304")) 
                                (make-tup (string-of-bytes (identifier "dstring2_fst_307")) (identifier "dstring2_snd_308")))))
                          (let-pair "drec_fst_310" "drec_snd_311" (identifier "drec_309")
                            (let "drec_335"
                              (let-pair "dlist4_fst_333" "dlist4_snd_334"
                                (let "dlist1_321"
                                  (let "leb_ref_312" (make-vec (u32 0))
                                    (let "shft_ref_313" (make-vec (u8 0))
                                      (let "p_ref_314" (make-vec (identifier "drec_snd_311"))
                                        (seq
                                          (while
                                            (let "leb128_315" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_314")))
                                              (let-pair "leb128_fst_316" "leb128_snd_317" 
                                                (identifier "leb128_315")
                                                (seq (set-vec (u8 0) (identifier "p_ref_314") (identifier "leb128_snd_317"))
                                                  (set-vec (u8 0) (identifier "leb_ref_312")
                                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_316") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_313"))) (unsafe-nth (u8 0) (identifier "leb_ref_312"))))
                                                  (set-vec (u8 0) (identifier "shft_ref_313") (add (unsafe-nth (u8 0) (identifier "shft_ref_313")) (u8 7))) 
                                                  (ge (identifier "leb128_fst_316") (u8 128))))) 
                                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_312")) (unsafe-nth (u8 0) (identifier "p_ref_314")))))))
                                  (let-pair "dlist1_fst_322" "dlist1_snd_323" 
                                    (identifier "dlist1_321")
                                    (let "inits_src_ref_324" (make-vec (make-tup (end-of-list "$field_type") (identifier "dlist1_snd_323")))
                                      (seq
                                        (let "repeat_n_325" (make-vec (i32 0))
                                          (while (gt (to-i32 (identifier "dlist1_fst_322")) (unsafe-nth (u8 0) (identifier "repeat_n_325")))
                                            (seq
                                              (let "dlist2_326" (unsafe-nth (u8 0) (identifier "inits_src_ref_324"))
                                                (let-pair "dlist2_fst_327" "dlist2_snd_328" 
                                                  (identifier "dlist2_326")
                                                  (set-vec (u8 0) (identifier "inits_src_ref_324")
                                                    (let-pair "dlist3_fst_330" "dlist3_snd_331" 
                                                      (apply (ext-identifier field_type of-row-binary) (identifier "dlist2_snd_328"))
                                                      (make-tup (cons (identifier "dlist3_fst_330") (identifier "dlist2_fst_327")) (identifier "dlist3_snd_331"))))))
                                              (set-vec (u8 0) (identifier "repeat_n_325") (add (unsafe-nth (u8 0) (identifier "repeat_n_325")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_324")))))) 
                                (make-tup (identity (identifier "dlist4_fst_333")) (identifier "dlist4_snd_334")))
                              (let-pair "drec_fst_336" "drec_snd_337" 
                                (identifier "drec_335")
                                (let "drec_341" (let-pair "dbool_fst_339" "dbool_snd_340" (read-u8 (identifier "drec_snd_337")) (make-tup (not (eq (identifier "dbool_fst_339") (u8 0))) (identifier "dbool_snd_340")))
                                  (let-pair "drec_fst_342" "drec_snd_343" 
                                    (identifier "drec_341")
                                    (let-pair "dbool_fst_345" "dbool_snd_346" 
                                      (read-u8 (identifier "drec_snd_343"))
                                      (make-tup
                                        (construct "[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" 0
                                          (make-rec (string "clickhouse_syntax") 
                                            (not (eq (identifier "dbool_fst_345") (u8 0))) 
                                            (string "vectors_of_chars_as_string") 
                                            (identifier "drec_fst_342") 
                                            (string "fields") (identifier "drec_fst_336") 
                                            (string "escape_seq") (identifier "drec_fst_310") 
                                            (string "may_quote") (identifier "drec_fst_295") 
                                            (string "null") (identifier "drec_fst_289") 
                                            (string "separator") (identifier "drec_fst_274"))) 
                                        (identifier "dbool_snd_346")))))))))))))))
            (seq (assert (eq (identifier "dsum1_fst_242") (u16 1)))
              (let-pair "dlist4_fst_265" "dlist4_snd_266"
                (let "dlist1_253"
                  (let "leb_ref_244" (make-vec (u32 0))
                    (let "shft_ref_245" (make-vec (u8 0))
                      (let "p_ref_246" (make-vec (identifier "dsum1_snd_243"))
                        (seq
                          (while
                            (let "leb128_247" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_246")))
                              (let-pair "leb128_fst_248" "leb128_snd_249" 
                                (identifier "leb128_247")
                                (seq (set-vec (u8 0) (identifier "p_ref_246") (identifier "leb128_snd_249"))
                                  (set-vec (u8 0) (identifier "leb_ref_244")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_248") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_245"))) (unsafe-nth (u8 0) (identifier "leb_ref_244"))))
                                  (set-vec (u8 0) (identifier "shft_ref_245") (add (unsafe-nth (u8 0) (identifier "shft_ref_245")) (u8 7))) 
                                  (ge (identifier "leb128_fst_248") (u8 128))))) 
                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_244")) (unsafe-nth (u8 0) (identifier "p_ref_246")))))))
                  (let-pair "dlist1_fst_254" "dlist1_snd_255" (identifier "dlist1_253")
                    (let "inits_src_ref_256" (make-vec (make-tup (end-of-list "$field_type") (identifier "dlist1_snd_255")))
                      (seq
                        (let "repeat_n_257" (make-vec (i32 0))
                          (while (gt (to-i32 (identifier "dlist1_fst_254")) (unsafe-nth (u8 0) (identifier "repeat_n_257")))
                            (seq
                              (let "dlist2_258" (unsafe-nth (u8 0) (identifier "inits_src_ref_256"))
                                (let-pair "dlist2_fst_259" "dlist2_snd_260" 
                                  (identifier "dlist2_258")
                                  (set-vec (u8 0) (identifier "inits_src_ref_256")
                                    (let-pair "dlist3_fst_262" "dlist3_snd_263" 
                                      (apply (ext-identifier field_type of-row-binary) (identifier "dlist2_snd_260")) 
                                      (make-tup (cons (identifier "dlist3_fst_262") (identifier "dlist2_fst_259")) (identifier "dlist3_snd_263"))))))
                              (set-vec (u8 0) (identifier "repeat_n_257") (add (unsafe-nth (u8 0) (identifier "repeat_n_257")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "inits_src_ref_256"))))))
                (make-tup
                  (construct "[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" 1
                    (identity (identifier "dlist4_fst_265"))) (identifier "dlist4_snd_266"))))))))
 */
static std::function<::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3(Pointer)> external_format_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3(Pointer)> fun838 { [&fun838](Pointer p_0) {
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_839 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_840;
    {
      auto du16_fst_236 { std::get<0>(id_839) };
      auto du16_snd_237 { std::get<1>(id_839) };
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_841 { du16_fst_236, du16_snd_237 };
      letpair_res_840 = id_841;
    }
    ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 let_res_842;
    {
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_241 { letpair_res_840 };
      ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 letpair_res_843;
      {
        auto dsum1_fst_242 { std::get<0>(dsum1_241) };
        auto dsum1_snd_243 { std::get<1>(dsum1_241) };
        uint16_t id_844 { 0 };
        bool id_845 { bool(id_844 == dsum1_fst_242) };
        ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 choose_res_846;
        if (id_845) {
          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_847 { dsum1_snd_243.readU8() };
          ::dessser::gen::raql_operation::tfa74ce2af9d2c970f57cbdfa42fae458 letpair_res_848;
          {
            auto dchar_fst_271 { std::get<0>(id_847) };
            auto dchar_snd_272 { std::get<1>(id_847) };
            char id_849 { char(dchar_fst_271) };
            ::dessser::gen::raql_operation::tfa74ce2af9d2c970f57cbdfa42fae458 id_850 { id_849, dchar_snd_272 };
            letpair_res_848 = id_850;
          }
          ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 let_res_851;
          {
            ::dessser::gen::raql_operation::tfa74ce2af9d2c970f57cbdfa42fae458 drec_273 { letpair_res_848 };
            ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 letpair_res_852;
            {
              auto drec_fst_274 { std::get<0>(drec_273) };
              auto drec_snd_275 { std::get<1>(drec_273) };
              uint32_t id_853 { 0U };
              Vec<1, uint32_t> id_854 {  id_853  };
              ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_855;
              {
                Vec<1, uint32_t> leb_ref_276 { id_854 };
                uint8_t id_856 { 0 };
                Vec<1, uint8_t> id_857 {  id_856  };
                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_858;
                {
                  Vec<1, uint8_t> shft_ref_277 { id_857 };
                  Vec<1, Pointer> id_859 {  drec_snd_275  };
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_860;
                  {
                    Vec<1, Pointer> p_ref_278 { id_859 };
                    bool while_flag_861 { true };
                    do {
                      uint8_t id_862 { 0 };
                      Pointer id_863 { p_ref_278[id_862] };
                      ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_864 { id_863.readU8() };
                      bool let_res_865;
                      {
                        ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_279 { id_864 };
                        bool letpair_res_866;
                        {
                          auto leb128_fst_280 { std::get<0>(leb128_279) };
                          auto leb128_snd_281 { std::get<1>(leb128_279) };
                          uint8_t id_867 { 0 };
                          Void id_868 { ((void)(p_ref_278[id_867] = leb128_snd_281), ::dessser::VOID) };
                          (void)id_868;
                          uint8_t id_869 { 0 };
                          uint8_t id_870 { 127 };
                          uint8_t id_871 { uint8_t(leb128_fst_280 & id_870) };
                          uint32_t id_872 { uint32_t(id_871) };
                          uint8_t id_873 { 0 };
                          uint8_t id_874 { shft_ref_277[id_873] };
                          uint32_t id_875 { uint32_t(id_872 << id_874) };
                          uint8_t id_876 { 0 };
                          uint32_t id_877 { leb_ref_276[id_876] };
                          uint32_t id_878 { uint32_t(id_875 | id_877) };
                          Void id_879 { ((void)(leb_ref_276[id_869] = id_878), ::dessser::VOID) };
                          (void)id_879;
                          uint8_t id_880 { 0 };
                          uint8_t id_881 { 0 };
                          uint8_t id_882 { shft_ref_277[id_881] };
                          uint8_t id_883 { 7 };
                          uint8_t id_884 { uint8_t(id_882 + id_883) };
                          Void id_885 { ((void)(shft_ref_277[id_880] = id_884), ::dessser::VOID) };
                          (void)id_885;
                          uint8_t id_886 { 128 };
                          bool id_887 { bool(leb128_fst_280 >= id_886) };
                          letpair_res_866 = id_887;
                        }
                        let_res_865 = letpair_res_866;
                      }
                      while_flag_861 = let_res_865;
                      if (while_flag_861) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_861);
                    (void)::dessser::VOID;
                    uint8_t id_888 { 0 };
                    uint32_t id_889 { leb_ref_276[id_888] };
                    Size id_890 { Size(id_889) };
                    uint8_t id_891 { 0 };
                    Pointer id_892 { p_ref_278[id_891] };
                    ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_893 { id_890, id_892 };
                    let_res_860 = id_893;
                  }
                  let_res_858 = let_res_860;
                }
                let_res_855 = let_res_858;
              }
              ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 let_res_894;
              {
                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_282 { let_res_855 };
                ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_895;
                {
                  auto dstring1_fst_283 { std::get<0>(dstring1_282) };
                  auto dstring1_snd_284 { std::get<1>(dstring1_282) };
                  ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_896 { dstring1_snd_284.readBytes(dstring1_fst_283) };
                  ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_897;
                  {
                    auto dstring2_fst_286 { std::get<0>(id_896) };
                    auto dstring2_snd_287 { std::get<1>(id_896) };
                    std::string id_898 { dstring2_fst_286.toString() };
                    ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 id_899 { id_898, dstring2_snd_287 };
                    letpair_res_897 = id_899;
                  }
                  letpair_res_895 = letpair_res_897;
                }
                let_res_894 = letpair_res_895;
              }
              ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 let_res_900;
              {
                ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 drec_288 { let_res_894 };
                ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 letpair_res_901;
                {
                  auto drec_fst_289 { std::get<0>(drec_288) };
                  auto drec_snd_290 { std::get<1>(drec_288) };
                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_902 { drec_snd_290.readU8() };
                  ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_903;
                  {
                    auto dbool_fst_292 { std::get<0>(id_902) };
                    auto dbool_snd_293 { std::get<1>(id_902) };
                    uint8_t id_904 { 0 };
                    bool id_905 { bool(dbool_fst_292 == id_904) };
                    bool id_906 { ! id_905 };
                    ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 id_907 { id_906, dbool_snd_293 };
                    letpair_res_903 = id_907;
                  }
                  ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 let_res_908;
                  {
                    ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 drec_294 { letpair_res_903 };
                    ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 letpair_res_909;
                    {
                      auto drec_fst_295 { std::get<0>(drec_294) };
                      auto drec_snd_296 { std::get<1>(drec_294) };
                      uint32_t id_910 { 0U };
                      Vec<1, uint32_t> id_911 {  id_910  };
                      ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_912;
                      {
                        Vec<1, uint32_t> leb_ref_297 { id_911 };
                        uint8_t id_913 { 0 };
                        Vec<1, uint8_t> id_914 {  id_913  };
                        ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_915;
                        {
                          Vec<1, uint8_t> shft_ref_298 { id_914 };
                          Vec<1, Pointer> id_916 {  drec_snd_296  };
                          ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_917;
                          {
                            Vec<1, Pointer> p_ref_299 { id_916 };
                            bool while_flag_918 { true };
                            do {
                              uint8_t id_919 { 0 };
                              Pointer id_920 { p_ref_299[id_919] };
                              ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_921 { id_920.readU8() };
                              bool let_res_922;
                              {
                                ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_300 { id_921 };
                                bool letpair_res_923;
                                {
                                  auto leb128_fst_301 { std::get<0>(leb128_300) };
                                  auto leb128_snd_302 { std::get<1>(leb128_300) };
                                  uint8_t id_924 { 0 };
                                  Void id_925 { ((void)(p_ref_299[id_924] = leb128_snd_302), ::dessser::VOID) };
                                  (void)id_925;
                                  uint8_t id_926 { 0 };
                                  uint8_t id_927 { 127 };
                                  uint8_t id_928 { uint8_t(leb128_fst_301 & id_927) };
                                  uint32_t id_929 { uint32_t(id_928) };
                                  uint8_t id_930 { 0 };
                                  uint8_t id_931 { shft_ref_298[id_930] };
                                  uint32_t id_932 { uint32_t(id_929 << id_931) };
                                  uint8_t id_933 { 0 };
                                  uint32_t id_934 { leb_ref_297[id_933] };
                                  uint32_t id_935 { uint32_t(id_932 | id_934) };
                                  Void id_936 { ((void)(leb_ref_297[id_926] = id_935), ::dessser::VOID) };
                                  (void)id_936;
                                  uint8_t id_937 { 0 };
                                  uint8_t id_938 { 0 };
                                  uint8_t id_939 { shft_ref_298[id_938] };
                                  uint8_t id_940 { 7 };
                                  uint8_t id_941 { uint8_t(id_939 + id_940) };
                                  Void id_942 { ((void)(shft_ref_298[id_937] = id_941), ::dessser::VOID) };
                                  (void)id_942;
                                  uint8_t id_943 { 128 };
                                  bool id_944 { bool(leb128_fst_301 >= id_943) };
                                  letpair_res_923 = id_944;
                                }
                                let_res_922 = letpair_res_923;
                              }
                              while_flag_918 = let_res_922;
                              if (while_flag_918) {
                                (void)::dessser::VOID;
                              }
                            } while (while_flag_918);
                            (void)::dessser::VOID;
                            uint8_t id_945 { 0 };
                            uint32_t id_946 { leb_ref_297[id_945] };
                            Size id_947 { Size(id_946) };
                            uint8_t id_948 { 0 };
                            Pointer id_949 { p_ref_299[id_948] };
                            ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_950 { id_947, id_949 };
                            let_res_917 = id_950;
                          }
                          let_res_915 = let_res_917;
                        }
                        let_res_912 = let_res_915;
                      }
                      ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 let_res_951;
                      {
                        ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_303 { let_res_912 };
                        ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_952;
                        {
                          auto dstring1_fst_304 { std::get<0>(dstring1_303) };
                          auto dstring1_snd_305 { std::get<1>(dstring1_303) };
                          ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_953 { dstring1_snd_305.readBytes(dstring1_fst_304) };
                          ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_954;
                          {
                            auto dstring2_fst_307 { std::get<0>(id_953) };
                            auto dstring2_snd_308 { std::get<1>(id_953) };
                            std::string id_955 { dstring2_fst_307.toString() };
                            ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 id_956 { id_955, dstring2_snd_308 };
                            letpair_res_954 = id_956;
                          }
                          letpair_res_952 = letpair_res_954;
                        }
                        let_res_951 = letpair_res_952;
                      }
                      ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 let_res_957;
                      {
                        ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 drec_309 { let_res_951 };
                        ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 letpair_res_958;
                        {
                          auto drec_fst_310 { std::get<0>(drec_309) };
                          auto drec_snd_311 { std::get<1>(drec_309) };
                          uint32_t id_959 { 0U };
                          Vec<1, uint32_t> id_960 {  id_959  };
                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_961;
                          {
                            Vec<1, uint32_t> leb_ref_312 { id_960 };
                            uint8_t id_962 { 0 };
                            Vec<1, uint8_t> id_963 {  id_962  };
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_964;
                            {
                              Vec<1, uint8_t> shft_ref_313 { id_963 };
                              Vec<1, Pointer> id_965 {  drec_snd_311  };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_966;
                              {
                                Vec<1, Pointer> p_ref_314 { id_965 };
                                bool while_flag_967 { true };
                                do {
                                  uint8_t id_968 { 0 };
                                  Pointer id_969 { p_ref_314[id_968] };
                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_970 { id_969.readU8() };
                                  bool let_res_971;
                                  {
                                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_315 { id_970 };
                                    bool letpair_res_972;
                                    {
                                      auto leb128_fst_316 { std::get<0>(leb128_315) };
                                      auto leb128_snd_317 { std::get<1>(leb128_315) };
                                      uint8_t id_973 { 0 };
                                      Void id_974 { ((void)(p_ref_314[id_973] = leb128_snd_317), ::dessser::VOID) };
                                      (void)id_974;
                                      uint8_t id_975 { 0 };
                                      uint8_t id_976 { 127 };
                                      uint8_t id_977 { uint8_t(leb128_fst_316 & id_976) };
                                      uint32_t id_978 { uint32_t(id_977) };
                                      uint8_t id_979 { 0 };
                                      uint8_t id_980 { shft_ref_313[id_979] };
                                      uint32_t id_981 { uint32_t(id_978 << id_980) };
                                      uint8_t id_982 { 0 };
                                      uint32_t id_983 { leb_ref_312[id_982] };
                                      uint32_t id_984 { uint32_t(id_981 | id_983) };
                                      Void id_985 { ((void)(leb_ref_312[id_975] = id_984), ::dessser::VOID) };
                                      (void)id_985;
                                      uint8_t id_986 { 0 };
                                      uint8_t id_987 { 0 };
                                      uint8_t id_988 { shft_ref_313[id_987] };
                                      uint8_t id_989 { 7 };
                                      uint8_t id_990 { uint8_t(id_988 + id_989) };
                                      Void id_991 { ((void)(shft_ref_313[id_986] = id_990), ::dessser::VOID) };
                                      (void)id_991;
                                      uint8_t id_992 { 128 };
                                      bool id_993 { bool(leb128_fst_316 >= id_992) };
                                      letpair_res_972 = id_993;
                                    }
                                    let_res_971 = letpair_res_972;
                                  }
                                  while_flag_967 = let_res_971;
                                  if (while_flag_967) {
                                    (void)::dessser::VOID;
                                  }
                                } while (while_flag_967);
                                (void)::dessser::VOID;
                                uint8_t id_994 { 0 };
                                uint32_t id_995 { leb_ref_312[id_994] };
                                uint8_t id_996 { 0 };
                                Pointer id_997 { p_ref_314[id_996] };
                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_998 { id_995, id_997 };
                                let_res_966 = id_998;
                              }
                              let_res_964 = let_res_966;
                            }
                            let_res_961 = let_res_964;
                          }
                          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 let_res_999;
                          {
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_321 { let_res_961 };
                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1000;
                            {
                              auto dlist1_fst_322 { std::get<0>(dlist1_321) };
                              auto dlist1_snd_323 { std::get<1>(dlist1_321) };
                              Lst<dessser::gen::field_type::t_ext> endoflist_1001;
                              ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1002 { endoflist_1001, dlist1_snd_323 };
                              Vec<1, ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9> id_1003 {  id_1002  };
                              ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 let_res_1004;
                              {
                                Vec<1, ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9> inits_src_ref_324 { id_1003 };
                                int32_t id_1005 { 0L };
                                Vec<1, int32_t> id_1006 {  id_1005  };
                                {
                                  Vec<1, int32_t> repeat_n_325 { id_1006 };
                                  bool while_flag_1007 { true };
                                  do {
                                    int32_t id_1008 { int32_t(dlist1_fst_322) };
                                    uint8_t id_1009 { 0 };
                                    int32_t id_1010 { repeat_n_325[id_1009] };
                                    bool id_1011 { bool(id_1008 > id_1010) };
                                    while_flag_1007 = id_1011;
                                    if (while_flag_1007) {
                                      uint8_t id_1012 { 0 };
                                      ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1013 { inits_src_ref_324[id_1012] };
                                      {
                                        ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 dlist2_326 { id_1013 };
                                        {
                                          auto dlist2_fst_327 { std::get<0>(dlist2_326) };
                                          auto dlist2_snd_328 { std::get<1>(dlist2_326) };
                                          uint8_t id_1014 { 0 };
                                          auto fun1015 { dessser::gen::field_type::of_row_binary };
                                          ::dessser::gen::raql_operation::t20a180051b815e05487bcfd57d0d9adb id_1016 { fun1015(dlist2_snd_328) };
                                          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1017;
                                          {
                                            auto dlist3_fst_330 { std::get<0>(id_1016) };
                                            auto dlist3_snd_331 { std::get<1>(id_1016) };
                                            Lst<dessser::gen::field_type::t_ext> id_1018 { dlist3_fst_330, dlist2_fst_327 };
                                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1019 { id_1018, dlist3_snd_331 };
                                            letpair_res_1017 = id_1019;
                                          }
                                          Void id_1020 { ((void)(inits_src_ref_324[id_1014] = letpair_res_1017), ::dessser::VOID) };
                                          (void)id_1020;
                                        }
                                        (void)::dessser::VOID;
                                      }
                                      (void)::dessser::VOID;
                                      uint8_t id_1021 { 0 };
                                      uint8_t id_1022 { 0 };
                                      int32_t id_1023 { repeat_n_325[id_1022] };
                                      int32_t id_1024 { 1L };
                                      int32_t id_1025 { int32_t(id_1023 + id_1024) };
                                      Void id_1026 { ((void)(repeat_n_325[id_1021] = id_1025), ::dessser::VOID) };
                                      (void)id_1026;
                                      (void)id_1026;
                                    }
                                  } while (while_flag_1007);
                                  (void)::dessser::VOID;
                                }
                                (void)::dessser::VOID;
                                uint8_t id_1027 { 0 };
                                ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1028 { inits_src_ref_324[id_1027] };
                                let_res_1004 = id_1028;
                              }
                              letpair_res_1000 = let_res_1004;
                            }
                            let_res_999 = letpair_res_1000;
                          }
                          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1029;
                          {
                            auto dlist4_fst_333 { std::get<0>(let_res_999) };
                            auto dlist4_snd_334 { std::get<1>(let_res_999) };
                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1030 { dlist4_fst_333, dlist4_snd_334 };
                            letpair_res_1029 = id_1030;
                          }
                          ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 let_res_1031;
                          {
                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 drec_335 { letpair_res_1029 };
                            ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 letpair_res_1032;
                            {
                              auto drec_fst_336 { std::get<0>(drec_335) };
                              auto drec_snd_337 { std::get<1>(drec_335) };
                              ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1033 { drec_snd_337.readU8() };
                              ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_1034;
                              {
                                auto dbool_fst_339 { std::get<0>(id_1033) };
                                auto dbool_snd_340 { std::get<1>(id_1033) };
                                uint8_t id_1035 { 0 };
                                bool id_1036 { bool(dbool_fst_339 == id_1035) };
                                bool id_1037 { ! id_1036 };
                                ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 id_1038 { id_1037, dbool_snd_340 };
                                letpair_res_1034 = id_1038;
                              }
                              ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 let_res_1039;
                              {
                                ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 drec_341 { letpair_res_1034 };
                                ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 letpair_res_1040;
                                {
                                  auto drec_fst_342 { std::get<0>(drec_341) };
                                  auto drec_snd_343 { std::get<1>(drec_341) };
                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1041 { drec_snd_343.readU8() };
                                  ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 letpair_res_1042;
                                  {
                                    auto dbool_fst_345 { std::get<0>(id_1041) };
                                    auto dbool_snd_346 { std::get<1>(id_1041) };
                                    uint8_t id_1043 { 0 };
                                    bool id_1044 { bool(dbool_fst_345 == id_1043) };
                                    bool id_1045 { ! id_1044 };
                                    ::dessser::gen::raql_operation::t78cec4f9827249604fe947034c575f2a id_1046 { id_1045, drec_fst_310, drec_fst_336, drec_fst_295, drec_fst_289, drec_fst_274, drec_fst_342 };
                                    std::shared_ptr<::dessser::gen::raql_operation::external_format>  id_1047 { std::make_shared<::dessser::gen::raql_operation::external_format>(std::in_place_index<0>, id_1046) };
                                    ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 id_1048 { id_1047, dbool_snd_346 };
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
          bool id_1050 { bool(dsum1_fst_242 == id_1049) };
          Void id_1051 { ((void)(assert(id_1050)), ::dessser::VOID) };
          (void)id_1051;
          uint32_t id_1052 { 0U };
          Vec<1, uint32_t> id_1053 {  id_1052  };
          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1054;
          {
            Vec<1, uint32_t> leb_ref_244 { id_1053 };
            uint8_t id_1055 { 0 };
            Vec<1, uint8_t> id_1056 {  id_1055  };
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1057;
            {
              Vec<1, uint8_t> shft_ref_245 { id_1056 };
              Vec<1, Pointer> id_1058 {  dsum1_snd_243  };
              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1059;
              {
                Vec<1, Pointer> p_ref_246 { id_1058 };
                bool while_flag_1060 { true };
                do {
                  uint8_t id_1061 { 0 };
                  Pointer id_1062 { p_ref_246[id_1061] };
                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1063 { id_1062.readU8() };
                  bool let_res_1064;
                  {
                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_247 { id_1063 };
                    bool letpair_res_1065;
                    {
                      auto leb128_fst_248 { std::get<0>(leb128_247) };
                      auto leb128_snd_249 { std::get<1>(leb128_247) };
                      uint8_t id_1066 { 0 };
                      Void id_1067 { ((void)(p_ref_246[id_1066] = leb128_snd_249), ::dessser::VOID) };
                      (void)id_1067;
                      uint8_t id_1068 { 0 };
                      uint8_t id_1069 { 127 };
                      uint8_t id_1070 { uint8_t(leb128_fst_248 & id_1069) };
                      uint32_t id_1071 { uint32_t(id_1070) };
                      uint8_t id_1072 { 0 };
                      uint8_t id_1073 { shft_ref_245[id_1072] };
                      uint32_t id_1074 { uint32_t(id_1071 << id_1073) };
                      uint8_t id_1075 { 0 };
                      uint32_t id_1076 { leb_ref_244[id_1075] };
                      uint32_t id_1077 { uint32_t(id_1074 | id_1076) };
                      Void id_1078 { ((void)(leb_ref_244[id_1068] = id_1077), ::dessser::VOID) };
                      (void)id_1078;
                      uint8_t id_1079 { 0 };
                      uint8_t id_1080 { 0 };
                      uint8_t id_1081 { shft_ref_245[id_1080] };
                      uint8_t id_1082 { 7 };
                      uint8_t id_1083 { uint8_t(id_1081 + id_1082) };
                      Void id_1084 { ((void)(shft_ref_245[id_1079] = id_1083), ::dessser::VOID) };
                      (void)id_1084;
                      uint8_t id_1085 { 128 };
                      bool id_1086 { bool(leb128_fst_248 >= id_1085) };
                      letpair_res_1065 = id_1086;
                    }
                    let_res_1064 = letpair_res_1065;
                  }
                  while_flag_1060 = let_res_1064;
                  if (while_flag_1060) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_1060);
                (void)::dessser::VOID;
                uint8_t id_1087 { 0 };
                uint32_t id_1088 { leb_ref_244[id_1087] };
                uint8_t id_1089 { 0 };
                Pointer id_1090 { p_ref_246[id_1089] };
                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_1091 { id_1088, id_1090 };
                let_res_1059 = id_1091;
              }
              let_res_1057 = let_res_1059;
            }
            let_res_1054 = let_res_1057;
          }
          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 let_res_1092;
          {
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_253 { let_res_1054 };
            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1093;
            {
              auto dlist1_fst_254 { std::get<0>(dlist1_253) };
              auto dlist1_snd_255 { std::get<1>(dlist1_253) };
              Lst<dessser::gen::field_type::t_ext> endoflist_1094;
              ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1095 { endoflist_1094, dlist1_snd_255 };
              Vec<1, ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9> id_1096 {  id_1095  };
              ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 let_res_1097;
              {
                Vec<1, ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9> inits_src_ref_256 { id_1096 };
                int32_t id_1098 { 0L };
                Vec<1, int32_t> id_1099 {  id_1098  };
                {
                  Vec<1, int32_t> repeat_n_257 { id_1099 };
                  bool while_flag_1100 { true };
                  do {
                    int32_t id_1101 { int32_t(dlist1_fst_254) };
                    uint8_t id_1102 { 0 };
                    int32_t id_1103 { repeat_n_257[id_1102] };
                    bool id_1104 { bool(id_1101 > id_1103) };
                    while_flag_1100 = id_1104;
                    if (while_flag_1100) {
                      uint8_t id_1105 { 0 };
                      ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1106 { inits_src_ref_256[id_1105] };
                      {
                        ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 dlist2_258 { id_1106 };
                        {
                          auto dlist2_fst_259 { std::get<0>(dlist2_258) };
                          auto dlist2_snd_260 { std::get<1>(dlist2_258) };
                          uint8_t id_1107 { 0 };
                          auto fun1108 { dessser::gen::field_type::of_row_binary };
                          ::dessser::gen::raql_operation::t20a180051b815e05487bcfd57d0d9adb id_1109 { fun1108(dlist2_snd_260) };
                          ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 letpair_res_1110;
                          {
                            auto dlist3_fst_262 { std::get<0>(id_1109) };
                            auto dlist3_snd_263 { std::get<1>(id_1109) };
                            Lst<dessser::gen::field_type::t_ext> id_1111 { dlist3_fst_262, dlist2_fst_259 };
                            ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1112 { id_1111, dlist3_snd_263 };
                            letpair_res_1110 = id_1112;
                          }
                          Void id_1113 { ((void)(inits_src_ref_256[id_1107] = letpair_res_1110), ::dessser::VOID) };
                          (void)id_1113;
                        }
                        (void)::dessser::VOID;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_1114 { 0 };
                      uint8_t id_1115 { 0 };
                      int32_t id_1116 { repeat_n_257[id_1115] };
                      int32_t id_1117 { 1L };
                      int32_t id_1118 { int32_t(id_1116 + id_1117) };
                      Void id_1119 { ((void)(repeat_n_257[id_1114] = id_1118), ::dessser::VOID) };
                      (void)id_1119;
                      (void)id_1119;
                    }
                  } while (while_flag_1100);
                  (void)::dessser::VOID;
                }
                (void)::dessser::VOID;
                uint8_t id_1120 { 0 };
                ::dessser::gen::raql_operation::t85ae7cee8f9175cc6090b55d00747cf9 id_1121 { inits_src_ref_256[id_1120] };
                let_res_1097 = id_1121;
              }
              letpair_res_1093 = let_res_1097;
            }
            let_res_1092 = letpair_res_1093;
          }
          ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 letpair_res_1122;
          {
            auto dlist4_fst_265 { std::get<0>(let_res_1092) };
            auto dlist4_snd_266 { std::get<1>(let_res_1092) };
            std::shared_ptr<::dessser::gen::raql_operation::external_format>  id_1123 { std::make_shared<::dessser::gen::raql_operation::external_format>(std::in_place_index<1>, dlist4_fst_265) };
            ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 id_1124 { id_1123, dlist4_snd_266 };
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
std::function<::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3(Pointer)> external_format_of_row_binary(external_format_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_131" (let-pair "du16_fst_126" "du16_snd_127" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_126") (identifier "du16_snd_127")))
        (let-pair "dsum1_fst_132" "dsum1_snd_133" (identifier "dsum1_131")
          (if (eq (u16 0) (identifier "dsum1_fst_132"))
            (let "drec_220" (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_133"))
              (let-pair "drec_fst_221" "drec_snd_222" (identifier "drec_220")
                (let "drec_226"
                  (if (eq (peek-u8 (identifier "drec_snd_222") (size 0)) (u8 1)) 
                    (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_222") (size 1)))
                    (let-pair "make1_1_fst_224" "make1_1_snd_225" (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_222") (size 1)))
                      (make-tup (not-null (identifier "make1_1_fst_224")) (identifier "make1_1_snd_225"))))
                  (let-pair "drec_fst_227" "drec_snd_228" (identifier "drec_226")
                    (let-pair "drec_fst_230" "drec_snd_231" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_228"))
                      (make-tup
                        (construct "[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" 0
                          (make-rec (string "unlink") (identifier "drec_fst_230") (string "preprocessor") (identifier "drec_fst_227") (string "fname") (identifier "drec_fst_221"))) 
                        (identifier "drec_snd_231")))))))
            (seq (assert (eq (identifier "dsum1_fst_132") (u16 1)))
              (let "drec_175"
                (let-pair "dlist4_fst_173" "dlist4_snd_174"
                  (let "dlist1_143"
                    (let "leb_ref_134" (make-vec (u32 0))
                      (let "shft_ref_135" (make-vec (u8 0))
                        (let "p_ref_136" (make-vec (identifier "dsum1_snd_133"))
                          (seq
                            (while
                              (let "leb128_137" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_136")))
                                (let-pair "leb128_fst_138" "leb128_snd_139" 
                                  (identifier "leb128_137")
                                  (seq (set-vec (u8 0) (identifier "p_ref_136") (identifier "leb128_snd_139"))
                                    (set-vec (u8 0) (identifier "leb_ref_134")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_138") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_135"))) (unsafe-nth (u8 0) (identifier "leb_ref_134"))))
                                    (set-vec (u8 0) (identifier "shft_ref_135") (add (unsafe-nth (u8 0) (identifier "shft_ref_135")) (u8 7))) 
                                    (ge (identifier "leb128_fst_138") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_134")) (unsafe-nth (u8 0) (identifier "p_ref_136")))))))
                    (let-pair "dlist1_fst_144" "dlist1_snd_145" (identifier "dlist1_143")
                      (let "inits_src_ref_146" (make-vec (make-tup (end-of-list "(STRING; $raql_expr)") (identifier "dlist1_snd_145")))
                        (seq
                          (let "repeat_n_147" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_144")) (unsafe-nth (u8 0) (identifier "repeat_n_147")))
                              (seq
                                (let "dlist2_148" (unsafe-nth (u8 0) (identifier "inits_src_ref_146"))
                                  (let-pair "dlist2_fst_149" "dlist2_snd_150" 
                                    (identifier "dlist2_148")
                                    (set-vec (u8 0) (identifier "inits_src_ref_146")
                                      (let "dtup_163"
                                        (let "dstring1_157"
                                          (let "leb_ref_151" (make-vec (u32 0))
                                            (let "shft_ref_152" (make-vec (u8 0))
                                              (let "p_ref_153" (make-vec (identifier "dlist2_snd_150"))
                                                (seq
                                                  (while
                                                    (let "leb128_154" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_153")))
                                                      (let-pair "leb128_fst_155" "leb128_snd_156" 
                                                        (identifier "leb128_154")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_153") (identifier "leb128_snd_156"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_151")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_155") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_152")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_151")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_152") (add (unsafe-nth (u8 0) (identifier "shft_ref_152")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_155") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_151"))) (unsafe-nth (u8 0) (identifier "p_ref_153")))))))
                                          (let-pair "dstring1_fst_158" "dstring1_snd_159" 
                                            (identifier "dstring1_157")
                                            (let-pair "dstring2_fst_161" "dstring2_snd_162" 
                                              (read-bytes (identifier "dstring1_snd_159") (identifier "dstring1_fst_158")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_161")) (identifier "dstring2_snd_162")))))
                                        (let-pair "dtup_fst_164" "dtup_snd_165" 
                                          (identifier "dtup_163")
                                          (let-pair "dtup_fst_167" "dtup_snd_168" 
                                            (apply (ext-identifier raql_expr of-row-binary) (identifier "dtup_snd_165"))
                                            (make-tup (cons (make-tup (identifier "dtup_fst_164") (identifier "dtup_fst_167")) (identifier "dlist2_fst_149")) (identifier "dtup_snd_168"))))))))
                                (set-vec (u8 0) (identifier "repeat_n_147") (add (unsafe-nth (u8 0) (identifier "repeat_n_147")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_146")))))) 
                  (make-tup (identity (identifier "dlist4_fst_173")) (identifier "dlist4_snd_174")))
                (let-pair "drec_fst_176" "drec_snd_177" (identifier "drec_175")
                  (let "drec_178" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_177"))
                    (let-pair "drec_fst_179" "drec_snd_180" (identifier "drec_178")
                      (let "drec_184"
                        (if (eq (peek-u8 (identifier "drec_snd_180") (size 0)) (u8 1)) 
                          (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_180") (size 1)))
                          (let-pair "make1_1_fst_182" "make1_1_snd_183" 
                            (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_180") (size 1))) 
                            (make-tup (not-null (identifier "make1_1_fst_182")) (identifier "make1_1_snd_183"))))
                        (let-pair "drec_fst_185" "drec_snd_186" (identifier "drec_184")
                          (let-pair "drec_fst_215" "drec_snd_216"
                            (let "dsum1_193" (let-pair "du16_fst_188" "du16_snd_189" (read-u16 little-endian (identifier "drec_snd_186")) (make-tup (identifier "du16_fst_188") (identifier "du16_snd_189")))
                              (let-pair "dsum1_fst_194" "dsum1_snd_195" 
                                (identifier "dsum1_193")
                                (if (eq (u16 0) (identifier "dsum1_fst_194"))
                                  (make-tup (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 0 (nop))
                                    (identifier "dsum1_snd_195"))
                                  (if (eq (u16 1) (identifier "dsum1_fst_194"))
                                    (let-pair "dsum2_fst_209" "dsum2_snd_210" 
                                      (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_195"))
                                      (make-tup
                                        (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 1
                                          (identifier "dsum2_fst_209")) 
                                        (identifier "dsum2_snd_210")))
                                    (if (eq (u16 2) (identifier "dsum1_fst_194"))
                                      (make-tup (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 2 (nop))
                                        (identifier "dsum1_snd_195"))
                                      (seq (assert (eq (identifier "dsum1_fst_194") (u16 3)))
                                        (let "drec_196" (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_195"))
                                          (let-pair "drec_fst_197" "drec_snd_198" 
                                            (identifier "drec_196")
                                            (let-pair "drec_fst_200" "drec_snd_201" 
                                              (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_198"))
                                              (make-tup
                                                (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 3
                                                  (make-rec (string "after_max_events") (identifier "drec_fst_200") (string "after_max_secs") (identifier "drec_fst_197"))) 
                                                (identifier "drec_snd_201")))))))))))
                            (make-tup
                              (construct "[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" 1
                                (make-rec (string "restart_from") (identifier "drec_fst_215") 
                                  (string "partitions") (identifier "drec_fst_185") 
                                  (string "topic") (identifier "drec_fst_179") 
                                  (string "options") (identifier "drec_fst_176"))) 
                              (identifier "drec_snd_216"))))))))))))))
 */
static std::function<::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6(Pointer)> external_source_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6(Pointer)> fun1125 { [&fun1125](Pointer p_0) {
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_1126 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1127;
    {
      auto du16_fst_126 { std::get<0>(id_1126) };
      auto du16_snd_127 { std::get<1>(id_1126) };
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_1128 { du16_fst_126, du16_snd_127 };
      letpair_res_1127 = id_1128;
    }
    ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 let_res_1129;
    {
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_131 { letpair_res_1127 };
      ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 letpair_res_1130;
      {
        auto dsum1_fst_132 { std::get<0>(dsum1_131) };
        auto dsum1_snd_133 { std::get<1>(dsum1_131) };
        uint16_t id_1131 { 0 };
        bool id_1132 { bool(id_1131 == dsum1_fst_132) };
        ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 choose_res_1133;
        if (id_1132) {
          auto fun1134 { dessser::gen::raql_expr::of_row_binary };
          ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1135 { fun1134(dsum1_snd_133) };
          ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 let_res_1136;
          {
            ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_220 { id_1135 };
            ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 letpair_res_1137;
            {
              auto drec_fst_221 { std::get<0>(drec_220) };
              auto drec_snd_222 { std::get<1>(drec_220) };
              Size id_1138 { 0UL };
              uint8_t id_1139 { drec_snd_222.peekU8(id_1138) };
              uint8_t id_1140 { 1 };
              bool id_1141 { bool(id_1139 == id_1140) };
              ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 choose_res_1142;
              if (id_1141) {
                std::optional<dessser::gen::raql_expr::t_ext> id_1143 { std::nullopt };
                Size id_1144 { 1UL };
                Pointer id_1145 { drec_snd_222.skip(id_1144) };
                ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_1146 { id_1143, id_1145 };
                choose_res_1142 = id_1146;
              } else {
                auto fun1147 { dessser::gen::raql_expr::of_row_binary };
                Size id_1148 { 1UL };
                Pointer id_1149 { drec_snd_222.skip(id_1148) };
                ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1150 { fun1147(id_1149) };
                ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 letpair_res_1151;
                {
                  auto make1_1_fst_224 { std::get<0>(id_1150) };
                  auto make1_1_snd_225 { std::get<1>(id_1150) };
                  std::optional<dessser::gen::raql_expr::t_ext> id_1152 { make1_1_fst_224 };
                  ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_1153 { id_1152, make1_1_snd_225 };
                  letpair_res_1151 = id_1153;
                }
                choose_res_1142 = letpair_res_1151;
              }
              ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 let_res_1154;
              {
                ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 drec_226 { choose_res_1142 };
                ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 letpair_res_1155;
                {
                  auto drec_fst_227 { std::get<0>(drec_226) };
                  auto drec_snd_228 { std::get<1>(drec_226) };
                  auto fun1156 { dessser::gen::raql_expr::of_row_binary };
                  ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1157 { fun1156(drec_snd_228) };
                  ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 letpair_res_1158;
                  {
                    auto drec_fst_230 { std::get<0>(id_1157) };
                    auto drec_snd_231 { std::get<1>(id_1157) };
                    ::dessser::gen::raql_operation::t614b5d4c127c7065272d8dcc1f9877d3 id_1159 { drec_fst_221, drec_fst_227, drec_fst_230 };
                    std::shared_ptr<::dessser::gen::raql_operation::external_source>  id_1160 { std::make_shared<::dessser::gen::raql_operation::external_source>(std::in_place_index<0>, id_1159) };
                    ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 id_1161 { id_1160, drec_snd_231 };
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
          bool id_1163 { bool(dsum1_fst_132 == id_1162) };
          Void id_1164 { ((void)(assert(id_1163)), ::dessser::VOID) };
          (void)id_1164;
          uint32_t id_1165 { 0U };
          Vec<1, uint32_t> id_1166 {  id_1165  };
          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1167;
          {
            Vec<1, uint32_t> leb_ref_134 { id_1166 };
            uint8_t id_1168 { 0 };
            Vec<1, uint8_t> id_1169 {  id_1168  };
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1170;
            {
              Vec<1, uint8_t> shft_ref_135 { id_1169 };
              Vec<1, Pointer> id_1171 {  dsum1_snd_133  };
              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_1172;
              {
                Vec<1, Pointer> p_ref_136 { id_1171 };
                bool while_flag_1173 { true };
                do {
                  uint8_t id_1174 { 0 };
                  Pointer id_1175 { p_ref_136[id_1174] };
                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1176 { id_1175.readU8() };
                  bool let_res_1177;
                  {
                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_137 { id_1176 };
                    bool letpair_res_1178;
                    {
                      auto leb128_fst_138 { std::get<0>(leb128_137) };
                      auto leb128_snd_139 { std::get<1>(leb128_137) };
                      uint8_t id_1179 { 0 };
                      Void id_1180 { ((void)(p_ref_136[id_1179] = leb128_snd_139), ::dessser::VOID) };
                      (void)id_1180;
                      uint8_t id_1181 { 0 };
                      uint8_t id_1182 { 127 };
                      uint8_t id_1183 { uint8_t(leb128_fst_138 & id_1182) };
                      uint32_t id_1184 { uint32_t(id_1183) };
                      uint8_t id_1185 { 0 };
                      uint8_t id_1186 { shft_ref_135[id_1185] };
                      uint32_t id_1187 { uint32_t(id_1184 << id_1186) };
                      uint8_t id_1188 { 0 };
                      uint32_t id_1189 { leb_ref_134[id_1188] };
                      uint32_t id_1190 { uint32_t(id_1187 | id_1189) };
                      Void id_1191 { ((void)(leb_ref_134[id_1181] = id_1190), ::dessser::VOID) };
                      (void)id_1191;
                      uint8_t id_1192 { 0 };
                      uint8_t id_1193 { 0 };
                      uint8_t id_1194 { shft_ref_135[id_1193] };
                      uint8_t id_1195 { 7 };
                      uint8_t id_1196 { uint8_t(id_1194 + id_1195) };
                      Void id_1197 { ((void)(shft_ref_135[id_1192] = id_1196), ::dessser::VOID) };
                      (void)id_1197;
                      uint8_t id_1198 { 128 };
                      bool id_1199 { bool(leb128_fst_138 >= id_1198) };
                      letpair_res_1178 = id_1199;
                    }
                    let_res_1177 = letpair_res_1178;
                  }
                  while_flag_1173 = let_res_1177;
                  if (while_flag_1173) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_1173);
                (void)::dessser::VOID;
                uint8_t id_1200 { 0 };
                uint32_t id_1201 { leb_ref_134[id_1200] };
                uint8_t id_1202 { 0 };
                Pointer id_1203 { p_ref_136[id_1202] };
                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_1204 { id_1201, id_1203 };
                let_res_1172 = id_1204;
              }
              let_res_1170 = let_res_1172;
            }
            let_res_1167 = let_res_1170;
          }
          ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd let_res_1205;
          {
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_143 { let_res_1167 };
            ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd letpair_res_1206;
            {
              auto dlist1_fst_144 { std::get<0>(dlist1_143) };
              auto dlist1_snd_145 { std::get<1>(dlist1_143) };
              Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> endoflist_1207;
              ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd id_1208 { endoflist_1207, dlist1_snd_145 };
              Vec<1, ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd> id_1209 {  id_1208  };
              ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd let_res_1210;
              {
                Vec<1, ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd> inits_src_ref_146 { id_1209 };
                int32_t id_1211 { 0L };
                Vec<1, int32_t> id_1212 {  id_1211  };
                {
                  Vec<1, int32_t> repeat_n_147 { id_1212 };
                  bool while_flag_1213 { true };
                  do {
                    int32_t id_1214 { int32_t(dlist1_fst_144) };
                    uint8_t id_1215 { 0 };
                    int32_t id_1216 { repeat_n_147[id_1215] };
                    bool id_1217 { bool(id_1214 > id_1216) };
                    while_flag_1213 = id_1217;
                    if (while_flag_1213) {
                      uint8_t id_1218 { 0 };
                      ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd id_1219 { inits_src_ref_146[id_1218] };
                      {
                        ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd dlist2_148 { id_1219 };
                        {
                          auto dlist2_fst_149 { std::get<0>(dlist2_148) };
                          auto dlist2_snd_150 { std::get<1>(dlist2_148) };
                          uint8_t id_1220 { 0 };
                          uint32_t id_1221 { 0U };
                          Vec<1, uint32_t> id_1222 {  id_1221  };
                          ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_1223;
                          {
                            Vec<1, uint32_t> leb_ref_151 { id_1222 };
                            uint8_t id_1224 { 0 };
                            Vec<1, uint8_t> id_1225 {  id_1224  };
                            ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_1226;
                            {
                              Vec<1, uint8_t> shft_ref_152 { id_1225 };
                              Vec<1, Pointer> id_1227 {  dlist2_snd_150  };
                              ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_1228;
                              {
                                Vec<1, Pointer> p_ref_153 { id_1227 };
                                bool while_flag_1229 { true };
                                do {
                                  uint8_t id_1230 { 0 };
                                  Pointer id_1231 { p_ref_153[id_1230] };
                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_1232 { id_1231.readU8() };
                                  bool let_res_1233;
                                  {
                                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_154 { id_1232 };
                                    bool letpair_res_1234;
                                    {
                                      auto leb128_fst_155 { std::get<0>(leb128_154) };
                                      auto leb128_snd_156 { std::get<1>(leb128_154) };
                                      uint8_t id_1235 { 0 };
                                      Void id_1236 { ((void)(p_ref_153[id_1235] = leb128_snd_156), ::dessser::VOID) };
                                      (void)id_1236;
                                      uint8_t id_1237 { 0 };
                                      uint8_t id_1238 { 127 };
                                      uint8_t id_1239 { uint8_t(leb128_fst_155 & id_1238) };
                                      uint32_t id_1240 { uint32_t(id_1239) };
                                      uint8_t id_1241 { 0 };
                                      uint8_t id_1242 { shft_ref_152[id_1241] };
                                      uint32_t id_1243 { uint32_t(id_1240 << id_1242) };
                                      uint8_t id_1244 { 0 };
                                      uint32_t id_1245 { leb_ref_151[id_1244] };
                                      uint32_t id_1246 { uint32_t(id_1243 | id_1245) };
                                      Void id_1247 { ((void)(leb_ref_151[id_1237] = id_1246), ::dessser::VOID) };
                                      (void)id_1247;
                                      uint8_t id_1248 { 0 };
                                      uint8_t id_1249 { 0 };
                                      uint8_t id_1250 { shft_ref_152[id_1249] };
                                      uint8_t id_1251 { 7 };
                                      uint8_t id_1252 { uint8_t(id_1250 + id_1251) };
                                      Void id_1253 { ((void)(shft_ref_152[id_1248] = id_1252), ::dessser::VOID) };
                                      (void)id_1253;
                                      uint8_t id_1254 { 128 };
                                      bool id_1255 { bool(leb128_fst_155 >= id_1254) };
                                      letpair_res_1234 = id_1255;
                                    }
                                    let_res_1233 = letpair_res_1234;
                                  }
                                  while_flag_1229 = let_res_1233;
                                  if (while_flag_1229) {
                                    (void)::dessser::VOID;
                                  }
                                } while (while_flag_1229);
                                (void)::dessser::VOID;
                                uint8_t id_1256 { 0 };
                                uint32_t id_1257 { leb_ref_151[id_1256] };
                                Size id_1258 { Size(id_1257) };
                                uint8_t id_1259 { 0 };
                                Pointer id_1260 { p_ref_153[id_1259] };
                                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_1261 { id_1258, id_1260 };
                                let_res_1228 = id_1261;
                              }
                              let_res_1226 = let_res_1228;
                            }
                            let_res_1223 = let_res_1226;
                          }
                          ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 let_res_1262;
                          {
                            ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_157 { let_res_1223 };
                            ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_1263;
                            {
                              auto dstring1_fst_158 { std::get<0>(dstring1_157) };
                              auto dstring1_snd_159 { std::get<1>(dstring1_157) };
                              ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_1264 { dstring1_snd_159.readBytes(dstring1_fst_158) };
                              ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_1265;
                              {
                                auto dstring2_fst_161 { std::get<0>(id_1264) };
                                auto dstring2_snd_162 { std::get<1>(id_1264) };
                                std::string id_1266 { dstring2_fst_161.toString() };
                                ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 id_1267 { id_1266, dstring2_snd_162 };
                                letpair_res_1265 = id_1267;
                              }
                              letpair_res_1263 = letpair_res_1265;
                            }
                            let_res_1262 = letpair_res_1263;
                          }
                          ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd let_res_1268;
                          {
                            ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 dtup_163 { let_res_1262 };
                            ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd letpair_res_1269;
                            {
                              auto dtup_fst_164 { std::get<0>(dtup_163) };
                              auto dtup_snd_165 { std::get<1>(dtup_163) };
                              auto fun1270 { dessser::gen::raql_expr::of_row_binary };
                              ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1271 { fun1270(dtup_snd_165) };
                              ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd letpair_res_1272;
                              {
                                auto dtup_fst_167 { std::get<0>(id_1271) };
                                auto dtup_snd_168 { std::get<1>(id_1271) };
                                ::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179 id_1273 { dtup_fst_164, dtup_fst_167 };
                                Lst<::dessser::gen::raql_operation::td1e70aeaf070b9b0d0119e932e590179> id_1274 { id_1273, dlist2_fst_149 };
                                ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd id_1275 { id_1274, dtup_snd_168 };
                                letpair_res_1272 = id_1275;
                              }
                              letpair_res_1269 = letpair_res_1272;
                            }
                            let_res_1268 = letpair_res_1269;
                          }
                          Void id_1276 { ((void)(inits_src_ref_146[id_1220] = let_res_1268), ::dessser::VOID) };
                          (void)id_1276;
                        }
                        (void)::dessser::VOID;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_1277 { 0 };
                      uint8_t id_1278 { 0 };
                      int32_t id_1279 { repeat_n_147[id_1278] };
                      int32_t id_1280 { 1L };
                      int32_t id_1281 { int32_t(id_1279 + id_1280) };
                      Void id_1282 { ((void)(repeat_n_147[id_1277] = id_1281), ::dessser::VOID) };
                      (void)id_1282;
                      (void)id_1282;
                    }
                  } while (while_flag_1213);
                  (void)::dessser::VOID;
                }
                (void)::dessser::VOID;
                uint8_t id_1283 { 0 };
                ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd id_1284 { inits_src_ref_146[id_1283] };
                let_res_1210 = id_1284;
              }
              letpair_res_1206 = let_res_1210;
            }
            let_res_1205 = letpair_res_1206;
          }
          ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd letpair_res_1285;
          {
            auto dlist4_fst_173 { std::get<0>(let_res_1205) };
            auto dlist4_snd_174 { std::get<1>(let_res_1205) };
            ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd id_1286 { dlist4_fst_173, dlist4_snd_174 };
            letpair_res_1285 = id_1286;
          }
          ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 let_res_1287;
          {
            ::dessser::gen::raql_operation::t90d9936f362c598c2320b06a45a435fd drec_175 { letpair_res_1285 };
            ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 letpair_res_1288;
            {
              auto drec_fst_176 { std::get<0>(drec_175) };
              auto drec_snd_177 { std::get<1>(drec_175) };
              auto fun1289 { dessser::gen::raql_expr::of_row_binary };
              ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1290 { fun1289(drec_snd_177) };
              ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 let_res_1291;
              {
                ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_178 { id_1290 };
                ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 letpair_res_1292;
                {
                  auto drec_fst_179 { std::get<0>(drec_178) };
                  auto drec_snd_180 { std::get<1>(drec_178) };
                  Size id_1293 { 0UL };
                  uint8_t id_1294 { drec_snd_180.peekU8(id_1293) };
                  uint8_t id_1295 { 1 };
                  bool id_1296 { bool(id_1294 == id_1295) };
                  ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 choose_res_1297;
                  if (id_1296) {
                    std::optional<dessser::gen::raql_expr::t_ext> id_1298 { std::nullopt };
                    Size id_1299 { 1UL };
                    Pointer id_1300 { drec_snd_180.skip(id_1299) };
                    ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_1301 { id_1298, id_1300 };
                    choose_res_1297 = id_1301;
                  } else {
                    auto fun1302 { dessser::gen::raql_expr::of_row_binary };
                    Size id_1303 { 1UL };
                    Pointer id_1304 { drec_snd_180.skip(id_1303) };
                    ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1305 { fun1302(id_1304) };
                    ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 letpair_res_1306;
                    {
                      auto make1_1_fst_182 { std::get<0>(id_1305) };
                      auto make1_1_snd_183 { std::get<1>(id_1305) };
                      std::optional<dessser::gen::raql_expr::t_ext> id_1307 { make1_1_fst_182 };
                      ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_1308 { id_1307, make1_1_snd_183 };
                      letpair_res_1306 = id_1308;
                    }
                    choose_res_1297 = letpair_res_1306;
                  }
                  ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 let_res_1309;
                  {
                    ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 drec_184 { choose_res_1297 };
                    ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 letpair_res_1310;
                    {
                      auto drec_fst_185 { std::get<0>(drec_184) };
                      auto drec_snd_186 { std::get<1>(drec_184) };
                      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_1311 { drec_snd_186.readU16Le() };
                      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1312;
                      {
                        auto du16_fst_188 { std::get<0>(id_1311) };
                        auto du16_snd_189 { std::get<1>(id_1311) };
                        ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_1313 { du16_fst_188, du16_snd_189 };
                        letpair_res_1312 = id_1313;
                      }
                      ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 let_res_1314;
                      {
                        ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_193 { letpair_res_1312 };
                        ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 letpair_res_1315;
                        {
                          auto dsum1_fst_194 { std::get<0>(dsum1_193) };
                          auto dsum1_snd_195 { std::get<1>(dsum1_193) };
                          uint16_t id_1316 { 0 };
                          bool id_1317 { bool(id_1316 == dsum1_fst_194) };
                          ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 choose_res_1318;
                          if (id_1317) {
                            (void)::dessser::VOID;
                            ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_1319 { std::in_place_index<0>, ::dessser::VOID };
                            ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 id_1320 { id_1319, dsum1_snd_195 };
                            choose_res_1318 = id_1320;
                          } else {
                            uint16_t id_1321 { 1 };
                            bool id_1322 { bool(id_1321 == dsum1_fst_194) };
                            ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 choose_res_1323;
                            if (id_1322) {
                              auto fun1324 { dessser::gen::raql_expr::of_row_binary };
                              ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1325 { fun1324(dsum1_snd_195) };
                              ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 letpair_res_1326;
                              {
                                auto dsum2_fst_209 { std::get<0>(id_1325) };
                                auto dsum2_snd_210 { std::get<1>(id_1325) };
                                ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_1327 { std::in_place_index<1>, dsum2_fst_209 };
                                ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 id_1328 { id_1327, dsum2_snd_210 };
                                letpair_res_1326 = id_1328;
                              }
                              choose_res_1323 = letpair_res_1326;
                            } else {
                              uint16_t id_1329 { 2 };
                              bool id_1330 { bool(id_1329 == dsum1_fst_194) };
                              ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 choose_res_1331;
                              if (id_1330) {
                                (void)::dessser::VOID;
                                ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_1332 { std::in_place_index<2>, ::dessser::VOID };
                                ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 id_1333 { id_1332, dsum1_snd_195 };
                                choose_res_1331 = id_1333;
                              } else {
                                uint16_t id_1334 { 3 };
                                bool id_1335 { bool(dsum1_fst_194 == id_1334) };
                                Void id_1336 { ((void)(assert(id_1335)), ::dessser::VOID) };
                                (void)id_1336;
                                auto fun1337 { dessser::gen::raql_expr::of_row_binary };
                                ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1338 { fun1337(dsum1_snd_195) };
                                ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 let_res_1339;
                                {
                                  ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_196 { id_1338 };
                                  ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 letpair_res_1340;
                                  {
                                    auto drec_fst_197 { std::get<0>(drec_196) };
                                    auto drec_snd_198 { std::get<1>(drec_196) };
                                    auto fun1341 { dessser::gen::raql_expr::of_row_binary };
                                    ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_1342 { fun1341(drec_snd_198) };
                                    ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 letpair_res_1343;
                                    {
                                      auto drec_fst_200 { std::get<0>(id_1342) };
                                      auto drec_snd_201 { std::get<1>(id_1342) };
                                      ::dessser::gen::raql_operation::t66e84af8ac3d220e6953b809395192f8 id_1344 { drec_fst_200, drec_fst_197 };
                                      ::dessser::gen::raql_operation::td6b783eb78996074f9384054f64b14ae id_1345 { std::in_place_index<3>, id_1344 };
                                      ::dessser::gen::raql_operation::t879fdacf820dcaecad2995c1cfff3ff6 id_1346 { id_1345, drec_snd_201 };
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
                      ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 letpair_res_1347;
                      {
                        auto drec_fst_215 { std::get<0>(let_res_1314) };
                        auto drec_snd_216 { std::get<1>(let_res_1314) };
                        ::dessser::gen::raql_operation::t39c49449a1a829aeb161993f390f9dbf id_1348 { drec_fst_176, drec_fst_185, drec_fst_215, drec_fst_179 };
                        std::shared_ptr<::dessser::gen::raql_operation::external_source>  id_1349 { std::make_shared<::dessser::gen::raql_operation::external_source>(std::in_place_index<1>, id_1348) };
                        ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 id_1350 { id_1349, drec_snd_216 };
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
std::function<::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6(Pointer)> external_source_of_row_binary(external_source_of_row_binary_init());

/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> fun1351 { [&fun1351](std::shared_ptr<::dessser::gen::raql_operation::t>  p_0, Pointer p_1) {
    Pointer id_1352 { to_row_binary(p_0, p_1) };
    return id_1352;
  }
   };
  return fun1351;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());

/* 
    (fun ("[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" "Ptr")
      (let "ssum_dst_810" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "stup_dst_818"
            (let "stup_dst_815"
              (let "ssum_dst_812" (write-u16 little-endian (identifier "ssum_dst_810") (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))))
                (if (eq (u16 0) (label-of (get-item 0 (get-alt "NamedOperation" (param 0))))) 
                  (identifier "ssum_dst_812")
                  (if (eq (u16 1) (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))))
                    (write-bytes
                      (let "leb128_sz_813" (make-vec (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0))))))
                        (let "leb128_ptr_814" (make-vec (identifier "ssum_dst_812"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_814")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_814"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_813"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_813"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_813"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_813") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_813")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_813")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_814"))))) 
                      (bytes-of-string (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0))))))
                    (seq (assert (eq (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))) (u16 2))) (identifier "ssum_dst_812")))))
              (if (is-null (get-item 1 (get-alt "NamedOperation" (param 0)))) 
                (write-u8 (identifier "stup_dst_815") (u8 1))
                (write-bytes
                  (let "leb128_sz_816" (make-vec (string-length (force (get-item 1 (get-alt "NamedOperation" (param 0))))))
                    (let "leb128_ptr_817" (make-vec (write-u8 (identifier "stup_dst_815") (u8 0)))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_817")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_817"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_816"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_816"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_816"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_816") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_816")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_816")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_817"))))) 
                  (bytes-of-string (force (get-item 1 (get-alt "NamedOperation" (param 0)))))))) 
            (apply (ext-identifier function_name to-row-binary) (get-item 2 (get-alt "NamedOperation" (param 0))) (identifier "stup_dst_818")))
          (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "to-row-binary") (get-alt "SubQuery" (param 0)) (identifier "ssum_dst_810"))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::data_source> ,Pointer)> data_source_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::data_source> ,Pointer)> fun1353 { [&fun1353](std::shared_ptr<::dessser::gen::raql_operation::data_source>  p_0, Pointer p_1) {
    uint16_t id_1354 { uint16_t((*p_0).index()) };
    Pointer id_1355 { p_1.writeU16Le(id_1354) };
    Pointer let_res_1356;
    {
      Pointer ssum_dst_810 { id_1355 };
      uint16_t id_1357 { 0 };
      uint16_t id_1358 { uint16_t((*p_0).index()) };
      bool id_1359 { bool(id_1357 == id_1358) };
      Pointer choose_res_1360;
      if (id_1359) {
        ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1361 { std::get<0 /* NamedOperation */>((*p_0)) };
        ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_1362 { std::get<0>(id_1361) };
        uint16_t id_1363 { uint16_t(id_1362.index()) };
        Pointer id_1364 { ssum_dst_810.writeU16Le(id_1363) };
        Pointer let_res_1365;
        {
          Pointer ssum_dst_812 { id_1364 };
          uint16_t id_1366 { 0 };
          ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1367 { std::get<0 /* NamedOperation */>((*p_0)) };
          ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_1368 { std::get<0>(id_1367) };
          uint16_t id_1369 { uint16_t(id_1368.index()) };
          bool id_1370 { bool(id_1366 == id_1369) };
          Pointer choose_res_1371;
          if (id_1370) {
            choose_res_1371 = ssum_dst_812;
          } else {
            uint16_t id_1372 { 1 };
            ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1373 { std::get<0 /* NamedOperation */>((*p_0)) };
            ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_1374 { std::get<0>(id_1373) };
            uint16_t id_1375 { uint16_t(id_1374.index()) };
            bool id_1376 { bool(id_1372 == id_1375) };
            Pointer choose_res_1377;
            if (id_1376) {
              ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1378 { std::get<0 /* NamedOperation */>((*p_0)) };
              ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_1379 { std::get<0>(id_1378) };
              std::string id_1380 { std::get<1 /* TheseSites */>(id_1379) };
              uint32_t id_1381 { (uint32_t)id_1380.size() };
              Vec<1, uint32_t> id_1382 {  id_1381  };
              Pointer let_res_1383;
              {
                Vec<1, uint32_t> leb128_sz_813 { id_1382 };
                Vec<1, Pointer> id_1384 {  ssum_dst_812  };
                Pointer let_res_1385;
                {
                  Vec<1, Pointer> leb128_ptr_814 { id_1384 };
                  bool while_flag_1386 { true };
                  do {
                    uint8_t id_1387 { 0 };
                    uint8_t id_1388 { 0 };
                    Pointer id_1389 { leb128_ptr_814[id_1388] };
                    uint32_t id_1390 { 128U };
                    uint8_t id_1391 { 0 };
                    uint32_t id_1392 { leb128_sz_813[id_1391] };
                    bool id_1393 { bool(id_1390 > id_1392) };
                    uint8_t choose_res_1394;
                    if (id_1393) {
                      uint8_t id_1395 { 0 };
                      uint32_t id_1396 { leb128_sz_813[id_1395] };
                      uint8_t id_1397 { uint8_t(id_1396) };
                      choose_res_1394 = id_1397;
                    } else {
                      uint8_t id_1398 { 0 };
                      uint32_t id_1399 { leb128_sz_813[id_1398] };
                      uint8_t id_1400 { uint8_t(id_1399) };
                      uint8_t id_1401 { 128 };
                      uint8_t id_1402 { uint8_t(id_1400 | id_1401) };
                      choose_res_1394 = id_1402;
                    }
                    Pointer id_1403 { id_1389.writeU8(choose_res_1394) };
                    Void id_1404 { ((void)(leb128_ptr_814[id_1387] = id_1403), ::dessser::VOID) };
                    (void)id_1404;
                    uint8_t id_1405 { 0 };
                    uint8_t id_1406 { 0 };
                    uint32_t id_1407 { leb128_sz_813[id_1406] };
                    uint8_t id_1408 { 7 };
                    uint32_t id_1409 { uint32_t(id_1407 >> id_1408) };
                    Void id_1410 { ((void)(leb128_sz_813[id_1405] = id_1409), ::dessser::VOID) };
                    (void)id_1410;
                    uint8_t id_1411 { 0 };
                    uint32_t id_1412 { leb128_sz_813[id_1411] };
                    uint32_t id_1413 { 0U };
                    bool id_1414 { bool(id_1412 > id_1413) };
                    while_flag_1386 = id_1414;
                    if (while_flag_1386) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_1386);
                  (void)::dessser::VOID;
                  uint8_t id_1415 { 0 };
                  Pointer id_1416 { leb128_ptr_814[id_1415] };
                  let_res_1385 = id_1416;
                }
                let_res_1383 = let_res_1385;
              }
              ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1417 { std::get<0 /* NamedOperation */>((*p_0)) };
              ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_1418 { std::get<0>(id_1417) };
              std::string id_1419 { std::get<1 /* TheseSites */>(id_1418) };
              Bytes id_1420 { id_1419 };
              Pointer id_1421 { let_res_1383.writeBytes(id_1420) };
              choose_res_1377 = id_1421;
            } else {
              ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1422 { std::get<0 /* NamedOperation */>((*p_0)) };
              ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_1423 { std::get<0>(id_1422) };
              uint16_t id_1424 { uint16_t(id_1423.index()) };
              uint16_t id_1425 { 2 };
              bool id_1426 { bool(id_1424 == id_1425) };
              Void id_1427 { ((void)(assert(id_1426)), ::dessser::VOID) };
              (void)id_1427;
              choose_res_1377 = ssum_dst_812;
            }
            choose_res_1371 = choose_res_1377;
          }
          let_res_1365 = choose_res_1371;
        }
        Pointer let_res_1428;
        {
          Pointer stup_dst_815 { let_res_1365 };
          ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1429 { std::get<0 /* NamedOperation */>((*p_0)) };
          std::optional<std::string> id_1430 { std::get<1>(id_1429) };
          bool id_1431 { !(id_1430.has_value ()) };
          Pointer choose_res_1432;
          if (id_1431) {
            uint8_t id_1433 { 1 };
            Pointer id_1434 { stup_dst_815.writeU8(id_1433) };
            choose_res_1432 = id_1434;
          } else {
            ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1435 { std::get<0 /* NamedOperation */>((*p_0)) };
            std::optional<std::string> id_1436 { std::get<1>(id_1435) };
            std::string id_1437 { id_1436.value() };
            uint32_t id_1438 { (uint32_t)id_1437.size() };
            Vec<1, uint32_t> id_1439 {  id_1438  };
            Pointer let_res_1440;
            {
              Vec<1, uint32_t> leb128_sz_816 { id_1439 };
              uint8_t id_1441 { 0 };
              Pointer id_1442 { stup_dst_815.writeU8(id_1441) };
              Vec<1, Pointer> id_1443 {  id_1442  };
              Pointer let_res_1444;
              {
                Vec<1, Pointer> leb128_ptr_817 { id_1443 };
                bool while_flag_1445 { true };
                do {
                  uint8_t id_1446 { 0 };
                  uint8_t id_1447 { 0 };
                  Pointer id_1448 { leb128_ptr_817[id_1447] };
                  uint32_t id_1449 { 128U };
                  uint8_t id_1450 { 0 };
                  uint32_t id_1451 { leb128_sz_816[id_1450] };
                  bool id_1452 { bool(id_1449 > id_1451) };
                  uint8_t choose_res_1453;
                  if (id_1452) {
                    uint8_t id_1454 { 0 };
                    uint32_t id_1455 { leb128_sz_816[id_1454] };
                    uint8_t id_1456 { uint8_t(id_1455) };
                    choose_res_1453 = id_1456;
                  } else {
                    uint8_t id_1457 { 0 };
                    uint32_t id_1458 { leb128_sz_816[id_1457] };
                    uint8_t id_1459 { uint8_t(id_1458) };
                    uint8_t id_1460 { 128 };
                    uint8_t id_1461 { uint8_t(id_1459 | id_1460) };
                    choose_res_1453 = id_1461;
                  }
                  Pointer id_1462 { id_1448.writeU8(choose_res_1453) };
                  Void id_1463 { ((void)(leb128_ptr_817[id_1446] = id_1462), ::dessser::VOID) };
                  (void)id_1463;
                  uint8_t id_1464 { 0 };
                  uint8_t id_1465 { 0 };
                  uint32_t id_1466 { leb128_sz_816[id_1465] };
                  uint8_t id_1467 { 7 };
                  uint32_t id_1468 { uint32_t(id_1466 >> id_1467) };
                  Void id_1469 { ((void)(leb128_sz_816[id_1464] = id_1468), ::dessser::VOID) };
                  (void)id_1469;
                  uint8_t id_1470 { 0 };
                  uint32_t id_1471 { leb128_sz_816[id_1470] };
                  uint32_t id_1472 { 0U };
                  bool id_1473 { bool(id_1471 > id_1472) };
                  while_flag_1445 = id_1473;
                  if (while_flag_1445) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_1445);
                (void)::dessser::VOID;
                uint8_t id_1474 { 0 };
                Pointer id_1475 { leb128_ptr_817[id_1474] };
                let_res_1444 = id_1475;
              }
              let_res_1440 = let_res_1444;
            }
            ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1476 { std::get<0 /* NamedOperation */>((*p_0)) };
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
          Pointer stup_dst_818 { let_res_1428 };
          auto fun1482 { dessser::gen::function_name::to_row_binary };
          ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_1483 { std::get<0 /* NamedOperation */>((*p_0)) };
          dessser::gen::function_name::t_ext id_1484 { std::get<2>(id_1483) };
          Pointer id_1485 { fun1482(id_1484, stup_dst_818) };
          let_res_1481 = id_1485;
        }
        choose_res_1360 = let_res_1481;
      } else {
        uint16_t id_1486 { uint16_t((*p_0).index()) };
        uint16_t id_1487 { 1 };
        bool id_1488 { bool(id_1486 == id_1487) };
        Void id_1489 { ((void)(assert(id_1488)), ::dessser::VOID) };
        (void)id_1489;
        std::shared_ptr<::dessser::gen::raql_operation::t>  id_1490 { std::get<1 /* SubQuery */>((*p_0)) };
        Pointer id_1491 { to_row_binary(id_1490, ssum_dst_810) };
        choose_res_1360 = id_1491;
      }
      let_res_1356 = choose_res_1360;
    }
    return let_res_1356;
  }
   };
  return fun1353;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::data_source> ,Pointer)> data_source_to_row_binary(data_source_to_row_binary_init());

/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" "Ptr")
      (let "ssum_dst_861" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_924"
            (let "srec_dst_923"
              (let "srec_dst_917"
                (let "srec_dst_916"
                  (let "srec_dst_915"
                    (let "srec_dst_914"
                      (let "srec_dst_908"
                        (let "srec_dst_902"
                          (let "srec_dst_901"
                            (let "srec_dst_900"
                              (let "srec_dst_891"
                                (let "srec_dst_885"
                                  (let "dst_ref_882"
                                    (make-vec
                                      (let "leb128_sz_880" (make-vec (cardinality (get-field "fields" (get-alt "Aggregate" (param 0)))))
                                        (let "leb128_ptr_881" (make-vec (identifier "ssum_dst_861"))
                                          (seq
                                            (while
                                              (seq
                                                (set-vec (u8 0) (identifier "leb128_ptr_881")
                                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_881"))
                                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_880"))) 
                                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_880"))) 
                                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_880"))) (u8 128)))))
                                                (set-vec (u8 0) (identifier "leb128_sz_880") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_880")) (u8 7))) 
                                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_880")) (u32 0))) 
                                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_881"))))))
                                    (let "n_ref_883" (make-vec (i32 0))
                                      (seq
                                        (for-each "x_884" (get-field "fields" (get-alt "Aggregate" (param 0)))
                                          (seq (set-vec (u8 0) (identifier "dst_ref_882") (apply (ext-identifier raql_select_field to-row-binary) (identifier "x_884") (unsafe-nth (u8 0) (identifier "dst_ref_882"))))
                                            (set-vec (u8 0) (identifier "n_ref_883") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_883")))))) 
                                        (unsafe-nth (u8 0) (identifier "dst_ref_882")))))
                                  (if (is-null (get-field "and_all_others" (get-alt "Aggregate" (param 0)))) 
                                    (write-u8 (identifier "srec_dst_885") (u8 1))
                                    (let "dst_ref_888"
                                      (make-vec
                                        (let "leb128_sz_886" (make-vec (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))
                                          (let "leb128_ptr_887" (make-vec (write-u8 (identifier "srec_dst_885") (u8 0)))
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
                                          (for-each "x_890" (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_888") (apply (ext-identifier field_name to-row-binary) (identifier "x_890") (unsafe-nth (u8 0) (identifier "dst_ref_888"))))
                                              (set-vec (u8 0) (identifier "n_ref_889") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_889")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_888")))))))
                                (if (is-null (get-field "sort" (get-alt "Aggregate" (param 0)))) 
                                  (write-u8 (identifier "srec_dst_891") (u8 1))
                                  (let "stup_dst_894"
                                    (let "stup_dst_893"
                                      (let "stup_dst_892" (write-u8 (identifier "srec_dst_891") (u8 0))
                                        (write-u32 little-endian (identifier "stup_dst_892") (get-item 0 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                      (if (is-null (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) 
                                        (write-u8 (identifier "stup_dst_893") (u8 1))
                                        (apply (ext-identifier raql_expr to-row-binary) (force (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) (write-u8 (identifier "stup_dst_893") (u8 0)))))
                                    (let "dst_ref_897"
                                      (make-vec
                                        (let "leb128_sz_895" (make-vec (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                          (let "leb128_ptr_896" (make-vec (identifier "stup_dst_894"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_896")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_896"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_895"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_895"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_895"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_895") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_895")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_895")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_896"))))))
                                      (let "n_ref_898" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_899" (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_897") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_899") (unsafe-nth (u8 0) (identifier "dst_ref_897"))))
                                              (set-vec (u8 0) (identifier "n_ref_898") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_898")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_897")))))))) 
                              (apply (ext-identifier raql_expr to-row-binary) (get-field "where" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_900")))
                            (if (is-null (get-field "event_time" (get-alt "Aggregate" (param 0)))) 
                              (write-u8 (identifier "srec_dst_901") (u8 1))
                              (apply (ext-identifier event_time to-row-binary) (force (get-field "event_time" (get-alt "Aggregate" (param 0)))) (write-u8 (identifier "srec_dst_901") (u8 0)))))
                          (let "dst_ref_905"
                            (make-vec
                              (let "leb128_sz_903" (make-vec (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0)))))
                                (let "leb128_ptr_904" (make-vec (identifier "srec_dst_902"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_904")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_904"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_903"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_903"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_903"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_903") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_903")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_903")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_904"))))))
                            (let "n_ref_906" (make-vec (i32 0))
                              (seq
                                (for-each "x_907" (get-field "notifications" (get-alt "Aggregate" (param 0)))
                                  (seq (set-vec (u8 0) (identifier "dst_ref_905") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_907") (unsafe-nth (u8 0) (identifier "dst_ref_905"))))
                                    (set-vec (u8 0) (identifier "n_ref_906") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_906")))))) 
                                (unsafe-nth (u8 0) (identifier "dst_ref_905"))))))
                        (let "dst_ref_911"
                          (make-vec
                            (let "leb128_sz_909" (make-vec (cardinality (get-field "key" (get-alt "Aggregate" (param 0)))))
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
                              (for-each "x_913" (get-field "key" (get-alt "Aggregate" (param 0)))
                                (seq (set-vec (u8 0) (identifier "dst_ref_911") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_913") (unsafe-nth (u8 0) (identifier "dst_ref_911"))))
                                  (set-vec (u8 0) (identifier "n_ref_912") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_912")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_911")))))) 
                      (apply (ext-identifier raql_expr to-row-binary) (get-field "commit_cond" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_914")))
                    (write-u8 (identifier "srec_dst_915") (u8-of-bool (get-field "commit_before" (get-alt "Aggregate" (param 0))))))
                  (apply (ext-identifier raql_flush_method to-row-binary) (get-field "flush_how" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_916")))
                (let "dst_ref_920"
                  (make-vec
                    (let "leb128_sz_918" (make-vec (cardinality (get-field "from" (get-alt "Aggregate" (param 0)))))
                      (let "leb128_ptr_919" (make-vec (identifier "srec_dst_917"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_919")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_919"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_918"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_918"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_918"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_918") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_918")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_918")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_919"))))))
                  (let "n_ref_921" (make-vec (i32 0))
                    (seq
                      (for-each "x_922" (get-field "from" (get-alt "Aggregate" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_920") (apply (identifier "data_source-to-row-binary") (identifier "x_922") (unsafe-nth (u8 0) (identifier "dst_ref_920"))))
                          (set-vec (u8 0) (identifier "n_ref_921") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_921")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_920"))))))
              (if (is-null (get-field "every" (get-alt "Aggregate" (param 0)))) 
                (write-u8 (identifier "srec_dst_923") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "every" (get-alt "Aggregate" (param 0)))) (write-u8 (identifier "srec_dst_923") (u8 0)))))
            (let "dst_ref_927"
              (make-vec
                (let "leb128_sz_925" (make-vec (cardinality (get-field "factors" (get-alt "Aggregate" (param 0)))))
                  (let "leb128_ptr_926" (make-vec (identifier "srec_dst_924"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_926")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_926"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_925"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_925"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_925"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_925") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_925")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_925")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_926"))))))
              (let "n_ref_928" (make-vec (i32 0))
                (seq
                  (for-each "x_929" (get-field "factors" (get-alt "Aggregate" (param 0)))
                    (seq (set-vec (u8 0) (identifier "dst_ref_927") (apply (ext-identifier field_name to-row-binary) (identifier "x_929") (unsafe-nth (u8 0) (identifier "dst_ref_927"))))
                      (set-vec (u8 0) (identifier "n_ref_928") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_928")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_927"))))))
          (if (eq (u16 1) (label-of (param 0)))
            (let "srec_dst_874"
              (let "srec_dst_873"
                (let "srec_dst_872" (apply (identifier "external_source-to-row-binary") (get-field "source" (get-alt "ReadExternal" (param 0))) (identifier "ssum_dst_861"))
                  (apply (identifier "external_format-to-row-binary") (get-field "format" (get-alt "ReadExternal" (param 0))) (identifier "srec_dst_872")))
                (if (is-null (get-field "event_time" (get-alt "ReadExternal" (param 0)))) 
                  (write-u8 (identifier "srec_dst_873") (u8 1)) (apply (ext-identifier event_time to-row-binary) (force (get-field "event_time" (get-alt "ReadExternal" (param 0)))) (write-u8 (identifier "srec_dst_873") (u8 0)))))
              (let "dst_ref_877"
                (make-vec
                  (let "leb128_sz_875" (make-vec (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0)))))
                    (let "leb128_ptr_876" (make-vec (identifier "srec_dst_874"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_876")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_876"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_875"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_875"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_875"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_875") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_875")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_875")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_876"))))))
                (let "n_ref_878" (make-vec (i32 0))
                  (seq
                    (for-each "x_879" (get-field "factors" (get-alt "ReadExternal" (param 0)))
                      (seq (set-vec (u8 0) (identifier "dst_ref_877") (apply (ext-identifier field_name to-row-binary) (identifier "x_879") (unsafe-nth (u8 0) (identifier "dst_ref_877"))))
                        (set-vec (u8 0) (identifier "n_ref_878") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_878")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_877"))))))
            (seq (assert (eq (label-of (param 0)) (u16 2)))
              (let "srec_dst_866"
                (let "srec_dst_865"
                  (let "srec_dst_864"
                    (write-bytes
                      (let "leb128_sz_862" (make-vec (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0)))))
                        (let "leb128_ptr_863" (make-vec (identifier "ssum_dst_861"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_863")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_863"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_862"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_862"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_862"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_862") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_862")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_862")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_863"))))) 
                      (bytes-of-string (get-field "net_addr" (get-alt "ListenFor" (param 0))))) 
                    (write-u16 little-endian (identifier "srec_dst_864") (get-field "port" (get-alt "ListenFor" (param 0)))))
                  (apply (ext-identifier raql_net_protocol to-row-binary) (get-field "proto" (get-alt "ListenFor" (param 0))) (identifier "srec_dst_865")))
                (let "dst_ref_869"
                  (make-vec
                    (let "leb128_sz_867" (make-vec (cardinality (get-field "factors" (get-alt "ListenFor" (param 0)))))
                      (let "leb128_ptr_868" (make-vec (identifier "srec_dst_866"))
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
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_868"))))))
                  (let "n_ref_870" (make-vec (i32 0))
                    (seq
                      (for-each "x_871" (get-field "factors" (get-alt "ListenFor" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_869") (apply (ext-identifier field_name to-row-binary) (identifier "x_871") (unsafe-nth (u8 0) (identifier "dst_ref_869"))))
                          (set-vec (u8 0) (identifier "n_ref_870") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_870")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_869")))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> fun1492 { [&fun1492](std::shared_ptr<::dessser::gen::raql_operation::t>  p_0, Pointer p_1) {
    uint16_t id_1493 { uint16_t((*p_0).index()) };
    Pointer id_1494 { p_1.writeU16Le(id_1493) };
    Pointer let_res_1495;
    {
      Pointer ssum_dst_861 { id_1494 };
      uint16_t id_1496 { 0 };
      uint16_t id_1497 { uint16_t((*p_0).index()) };
      bool id_1498 { bool(id_1496 == id_1497) };
      Pointer choose_res_1499;
      if (id_1498) {
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1500 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::raql_select_field::t_ext> id_1501 { id_1500.Aggregate_fields };
        uint32_t id_1502 { id_1501.size() };
        Vec<1, uint32_t> id_1503 {  id_1502  };
        Pointer let_res_1504;
        {
          Vec<1, uint32_t> leb128_sz_880 { id_1503 };
          Vec<1, Pointer> id_1505 {  ssum_dst_861  };
          Pointer let_res_1506;
          {
            Vec<1, Pointer> leb128_ptr_881 { id_1505 };
            bool while_flag_1507 { true };
            do {
              uint8_t id_1508 { 0 };
              uint8_t id_1509 { 0 };
              Pointer id_1510 { leb128_ptr_881[id_1509] };
              uint32_t id_1511 { 128U };
              uint8_t id_1512 { 0 };
              uint32_t id_1513 { leb128_sz_880[id_1512] };
              bool id_1514 { bool(id_1511 > id_1513) };
              uint8_t choose_res_1515;
              if (id_1514) {
                uint8_t id_1516 { 0 };
                uint32_t id_1517 { leb128_sz_880[id_1516] };
                uint8_t id_1518 { uint8_t(id_1517) };
                choose_res_1515 = id_1518;
              } else {
                uint8_t id_1519 { 0 };
                uint32_t id_1520 { leb128_sz_880[id_1519] };
                uint8_t id_1521 { uint8_t(id_1520) };
                uint8_t id_1522 { 128 };
                uint8_t id_1523 { uint8_t(id_1521 | id_1522) };
                choose_res_1515 = id_1523;
              }
              Pointer id_1524 { id_1510.writeU8(choose_res_1515) };
              Void id_1525 { ((void)(leb128_ptr_881[id_1508] = id_1524), ::dessser::VOID) };
              (void)id_1525;
              uint8_t id_1526 { 0 };
              uint8_t id_1527 { 0 };
              uint32_t id_1528 { leb128_sz_880[id_1527] };
              uint8_t id_1529 { 7 };
              uint32_t id_1530 { uint32_t(id_1528 >> id_1529) };
              Void id_1531 { ((void)(leb128_sz_880[id_1526] = id_1530), ::dessser::VOID) };
              (void)id_1531;
              uint8_t id_1532 { 0 };
              uint32_t id_1533 { leb128_sz_880[id_1532] };
              uint32_t id_1534 { 0U };
              bool id_1535 { bool(id_1533 > id_1534) };
              while_flag_1507 = id_1535;
              if (while_flag_1507) {
                (void)::dessser::VOID;
              }
            } while (while_flag_1507);
            (void)::dessser::VOID;
            uint8_t id_1536 { 0 };
            Pointer id_1537 { leb128_ptr_881[id_1536] };
            let_res_1506 = id_1537;
          }
          let_res_1504 = let_res_1506;
        }
        Vec<1, Pointer> id_1538 {  let_res_1504  };
        Pointer let_res_1539;
        {
          Vec<1, Pointer> dst_ref_882 { id_1538 };
          int32_t id_1540 { 0L };
          Vec<1, int32_t> id_1541 {  id_1540  };
          Pointer let_res_1542;
          {
            Vec<1, int32_t> n_ref_883 { id_1541 };
            ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1543 { std::get<0 /* Aggregate */>((*p_0)) };
            Lst<dessser::gen::raql_select_field::t_ext> id_1544 { id_1543.Aggregate_fields };
            for (dessser::gen::raql_select_field::t_ext x_884 : id_1544) {
              uint8_t id_1545 { 0 };
              auto fun1546 { dessser::gen::raql_select_field::to_row_binary };
              uint8_t id_1547 { 0 };
              Pointer id_1548 { dst_ref_882[id_1547] };
              Pointer id_1549 { fun1546(x_884, id_1548) };
              Void id_1550 { ((void)(dst_ref_882[id_1545] = id_1549), ::dessser::VOID) };
              (void)id_1550;
              uint8_t id_1551 { 0 };
              int32_t id_1552 { 1L };
              uint8_t id_1553 { 0 };
              int32_t id_1554 { n_ref_883[id_1553] };
              int32_t id_1555 { int32_t(id_1552 + id_1554) };
              Void id_1556 { ((void)(n_ref_883[id_1551] = id_1555), ::dessser::VOID) };
              (void)id_1556;
              (void)id_1556;
            }
            (void)::dessser::VOID;
            uint8_t id_1557 { 0 };
            Pointer id_1558 { dst_ref_882[id_1557] };
            let_res_1542 = id_1558;
          }
          let_res_1539 = let_res_1542;
        }
        Pointer let_res_1559;
        {
          Pointer srec_dst_885 { let_res_1539 };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1560 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<Lst<dessser::gen::field_name::t_ext>> id_1561 { id_1560.and_all_others };
          bool id_1562 { !(id_1561.has_value ()) };
          Pointer choose_res_1563;
          if (id_1562) {
            uint8_t id_1564 { 1 };
            Pointer id_1565 { srec_dst_885.writeU8(id_1564) };
            choose_res_1563 = id_1565;
          } else {
            ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1566 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<Lst<dessser::gen::field_name::t_ext>> id_1567 { id_1566.and_all_others };
            Lst<dessser::gen::field_name::t_ext> id_1568 { id_1567.value() };
            uint32_t id_1569 { id_1568.size() };
            Vec<1, uint32_t> id_1570 {  id_1569  };
            Pointer let_res_1571;
            {
              Vec<1, uint32_t> leb128_sz_886 { id_1570 };
              uint8_t id_1572 { 0 };
              Pointer id_1573 { srec_dst_885.writeU8(id_1572) };
              Vec<1, Pointer> id_1574 {  id_1573  };
              Pointer let_res_1575;
              {
                Vec<1, Pointer> leb128_ptr_887 { id_1574 };
                bool while_flag_1576 { true };
                do {
                  uint8_t id_1577 { 0 };
                  uint8_t id_1578 { 0 };
                  Pointer id_1579 { leb128_ptr_887[id_1578] };
                  uint32_t id_1580 { 128U };
                  uint8_t id_1581 { 0 };
                  uint32_t id_1582 { leb128_sz_886[id_1581] };
                  bool id_1583 { bool(id_1580 > id_1582) };
                  uint8_t choose_res_1584;
                  if (id_1583) {
                    uint8_t id_1585 { 0 };
                    uint32_t id_1586 { leb128_sz_886[id_1585] };
                    uint8_t id_1587 { uint8_t(id_1586) };
                    choose_res_1584 = id_1587;
                  } else {
                    uint8_t id_1588 { 0 };
                    uint32_t id_1589 { leb128_sz_886[id_1588] };
                    uint8_t id_1590 { uint8_t(id_1589) };
                    uint8_t id_1591 { 128 };
                    uint8_t id_1592 { uint8_t(id_1590 | id_1591) };
                    choose_res_1584 = id_1592;
                  }
                  Pointer id_1593 { id_1579.writeU8(choose_res_1584) };
                  Void id_1594 { ((void)(leb128_ptr_887[id_1577] = id_1593), ::dessser::VOID) };
                  (void)id_1594;
                  uint8_t id_1595 { 0 };
                  uint8_t id_1596 { 0 };
                  uint32_t id_1597 { leb128_sz_886[id_1596] };
                  uint8_t id_1598 { 7 };
                  uint32_t id_1599 { uint32_t(id_1597 >> id_1598) };
                  Void id_1600 { ((void)(leb128_sz_886[id_1595] = id_1599), ::dessser::VOID) };
                  (void)id_1600;
                  uint8_t id_1601 { 0 };
                  uint32_t id_1602 { leb128_sz_886[id_1601] };
                  uint32_t id_1603 { 0U };
                  bool id_1604 { bool(id_1602 > id_1603) };
                  while_flag_1576 = id_1604;
                  if (while_flag_1576) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_1576);
                (void)::dessser::VOID;
                uint8_t id_1605 { 0 };
                Pointer id_1606 { leb128_ptr_887[id_1605] };
                let_res_1575 = id_1606;
              }
              let_res_1571 = let_res_1575;
            }
            Vec<1, Pointer> id_1607 {  let_res_1571  };
            Pointer let_res_1608;
            {
              Vec<1, Pointer> dst_ref_888 { id_1607 };
              int32_t id_1609 { 0L };
              Vec<1, int32_t> id_1610 {  id_1609  };
              Pointer let_res_1611;
              {
                Vec<1, int32_t> n_ref_889 { id_1610 };
                ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1612 { std::get<0 /* Aggregate */>((*p_0)) };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_1613 { id_1612.and_all_others };
                Lst<dessser::gen::field_name::t_ext> id_1614 { id_1613.value() };
                for (dessser::gen::field_name::t_ext x_890 : id_1614) {
                  uint8_t id_1615 { 0 };
                  auto fun1616 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_1617 { 0 };
                  Pointer id_1618 { dst_ref_888[id_1617] };
                  Pointer id_1619 { fun1616(x_890, id_1618) };
                  Void id_1620 { ((void)(dst_ref_888[id_1615] = id_1619), ::dessser::VOID) };
                  (void)id_1620;
                  uint8_t id_1621 { 0 };
                  int32_t id_1622 { 1L };
                  uint8_t id_1623 { 0 };
                  int32_t id_1624 { n_ref_889[id_1623] };
                  int32_t id_1625 { int32_t(id_1622 + id_1624) };
                  Void id_1626 { ((void)(n_ref_889[id_1621] = id_1625), ::dessser::VOID) };
                  (void)id_1626;
                  (void)id_1626;
                }
                (void)::dessser::VOID;
                uint8_t id_1627 { 0 };
                Pointer id_1628 { dst_ref_888[id_1627] };
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
          Pointer srec_dst_891 { let_res_1559 };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1630 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1631 { id_1630.sort };
          bool id_1632 { !(id_1631.has_value ()) };
          Pointer choose_res_1633;
          if (id_1632) {
            uint8_t id_1634 { 1 };
            Pointer id_1635 { srec_dst_891.writeU8(id_1634) };
            choose_res_1633 = id_1635;
          } else {
            uint8_t id_1636 { 0 };
            Pointer id_1637 { srec_dst_891.writeU8(id_1636) };
            Pointer let_res_1638;
            {
              Pointer stup_dst_892 { id_1637 };
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1639 { std::get<0 /* Aggregate */>((*p_0)) };
              std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1640 { id_1639.sort };
              ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1641 { id_1640.value() };
              uint32_t id_1642 { std::get<0>(id_1641) };
              Pointer id_1643 { stup_dst_892.writeU32Le(id_1642) };
              let_res_1638 = id_1643;
            }
            Pointer let_res_1644;
            {
              Pointer stup_dst_893 { let_res_1638 };
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1645 { std::get<0 /* Aggregate */>((*p_0)) };
              std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1646 { id_1645.sort };
              ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1647 { id_1646.value() };
              std::optional<dessser::gen::raql_expr::t_ext> id_1648 { std::get<1>(id_1647) };
              bool id_1649 { !(id_1648.has_value ()) };
              Pointer choose_res_1650;
              if (id_1649) {
                uint8_t id_1651 { 1 };
                Pointer id_1652 { stup_dst_893.writeU8(id_1651) };
                choose_res_1650 = id_1652;
              } else {
                auto fun1653 { dessser::gen::raql_expr::to_row_binary };
                ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1654 { std::get<0 /* Aggregate */>((*p_0)) };
                std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1655 { id_1654.sort };
                ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1656 { id_1655.value() };
                std::optional<dessser::gen::raql_expr::t_ext> id_1657 { std::get<1>(id_1656) };
                dessser::gen::raql_expr::t_ext id_1658 { id_1657.value() };
                uint8_t id_1659 { 0 };
                Pointer id_1660 { stup_dst_893.writeU8(id_1659) };
                Pointer id_1661 { fun1653(id_1658, id_1660) };
                choose_res_1650 = id_1661;
              }
              let_res_1644 = choose_res_1650;
            }
            Pointer let_res_1662;
            {
              Pointer stup_dst_894 { let_res_1644 };
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1663 { std::get<0 /* Aggregate */>((*p_0)) };
              std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1664 { id_1663.sort };
              ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1665 { id_1664.value() };
              Lst<dessser::gen::raql_expr::t_ext> id_1666 { std::get<2>(id_1665) };
              uint32_t id_1667 { id_1666.size() };
              Vec<1, uint32_t> id_1668 {  id_1667  };
              Pointer let_res_1669;
              {
                Vec<1, uint32_t> leb128_sz_895 { id_1668 };
                Vec<1, Pointer> id_1670 {  stup_dst_894  };
                Pointer let_res_1671;
                {
                  Vec<1, Pointer> leb128_ptr_896 { id_1670 };
                  bool while_flag_1672 { true };
                  do {
                    uint8_t id_1673 { 0 };
                    uint8_t id_1674 { 0 };
                    Pointer id_1675 { leb128_ptr_896[id_1674] };
                    uint32_t id_1676 { 128U };
                    uint8_t id_1677 { 0 };
                    uint32_t id_1678 { leb128_sz_895[id_1677] };
                    bool id_1679 { bool(id_1676 > id_1678) };
                    uint8_t choose_res_1680;
                    if (id_1679) {
                      uint8_t id_1681 { 0 };
                      uint32_t id_1682 { leb128_sz_895[id_1681] };
                      uint8_t id_1683 { uint8_t(id_1682) };
                      choose_res_1680 = id_1683;
                    } else {
                      uint8_t id_1684 { 0 };
                      uint32_t id_1685 { leb128_sz_895[id_1684] };
                      uint8_t id_1686 { uint8_t(id_1685) };
                      uint8_t id_1687 { 128 };
                      uint8_t id_1688 { uint8_t(id_1686 | id_1687) };
                      choose_res_1680 = id_1688;
                    }
                    Pointer id_1689 { id_1675.writeU8(choose_res_1680) };
                    Void id_1690 { ((void)(leb128_ptr_896[id_1673] = id_1689), ::dessser::VOID) };
                    (void)id_1690;
                    uint8_t id_1691 { 0 };
                    uint8_t id_1692 { 0 };
                    uint32_t id_1693 { leb128_sz_895[id_1692] };
                    uint8_t id_1694 { 7 };
                    uint32_t id_1695 { uint32_t(id_1693 >> id_1694) };
                    Void id_1696 { ((void)(leb128_sz_895[id_1691] = id_1695), ::dessser::VOID) };
                    (void)id_1696;
                    uint8_t id_1697 { 0 };
                    uint32_t id_1698 { leb128_sz_895[id_1697] };
                    uint32_t id_1699 { 0U };
                    bool id_1700 { bool(id_1698 > id_1699) };
                    while_flag_1672 = id_1700;
                    if (while_flag_1672) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_1672);
                  (void)::dessser::VOID;
                  uint8_t id_1701 { 0 };
                  Pointer id_1702 { leb128_ptr_896[id_1701] };
                  let_res_1671 = id_1702;
                }
                let_res_1669 = let_res_1671;
              }
              Vec<1, Pointer> id_1703 {  let_res_1669  };
              Pointer let_res_1704;
              {
                Vec<1, Pointer> dst_ref_897 { id_1703 };
                int32_t id_1705 { 0L };
                Vec<1, int32_t> id_1706 {  id_1705  };
                Pointer let_res_1707;
                {
                  Vec<1, int32_t> n_ref_898 { id_1706 };
                  ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1708 { std::get<0 /* Aggregate */>((*p_0)) };
                  std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_1709 { id_1708.sort };
                  ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_1710 { id_1709.value() };
                  Lst<dessser::gen::raql_expr::t_ext> id_1711 { std::get<2>(id_1710) };
                  for (dessser::gen::raql_expr::t_ext x_899 : id_1711) {
                    uint8_t id_1712 { 0 };
                    auto fun1713 { dessser::gen::raql_expr::to_row_binary };
                    uint8_t id_1714 { 0 };
                    Pointer id_1715 { dst_ref_897[id_1714] };
                    Pointer id_1716 { fun1713(x_899, id_1715) };
                    Void id_1717 { ((void)(dst_ref_897[id_1712] = id_1716), ::dessser::VOID) };
                    (void)id_1717;
                    uint8_t id_1718 { 0 };
                    int32_t id_1719 { 1L };
                    uint8_t id_1720 { 0 };
                    int32_t id_1721 { n_ref_898[id_1720] };
                    int32_t id_1722 { int32_t(id_1719 + id_1721) };
                    Void id_1723 { ((void)(n_ref_898[id_1718] = id_1722), ::dessser::VOID) };
                    (void)id_1723;
                    (void)id_1723;
                  }
                  (void)::dessser::VOID;
                  uint8_t id_1724 { 0 };
                  Pointer id_1725 { dst_ref_897[id_1724] };
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
          Pointer srec_dst_900 { let_res_1629 };
          auto fun1727 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1728 { std::get<0 /* Aggregate */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_1729 { id_1728.where };
          Pointer id_1730 { fun1727(id_1729, srec_dst_900) };
          let_res_1726 = id_1730;
        }
        Pointer let_res_1731;
        {
          Pointer srec_dst_901 { let_res_1726 };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1732 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::event_time::t_ext> id_1733 { id_1732.Aggregate_event_time };
          bool id_1734 { !(id_1733.has_value ()) };
          Pointer choose_res_1735;
          if (id_1734) {
            uint8_t id_1736 { 1 };
            Pointer id_1737 { srec_dst_901.writeU8(id_1736) };
            choose_res_1735 = id_1737;
          } else {
            auto fun1738 { dessser::gen::event_time::to_row_binary };
            ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1739 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<dessser::gen::event_time::t_ext> id_1740 { id_1739.Aggregate_event_time };
            dessser::gen::event_time::t_ext id_1741 { id_1740.value() };
            uint8_t id_1742 { 0 };
            Pointer id_1743 { srec_dst_901.writeU8(id_1742) };
            Pointer id_1744 { fun1738(id_1741, id_1743) };
            choose_res_1735 = id_1744;
          }
          let_res_1731 = choose_res_1735;
        }
        Pointer let_res_1745;
        {
          Pointer srec_dst_902 { let_res_1731 };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1746 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<dessser::gen::raql_expr::t_ext> id_1747 { id_1746.notifications };
          uint32_t id_1748 { id_1747.size() };
          Vec<1, uint32_t> id_1749 {  id_1748  };
          Pointer let_res_1750;
          {
            Vec<1, uint32_t> leb128_sz_903 { id_1749 };
            Vec<1, Pointer> id_1751 {  srec_dst_902  };
            Pointer let_res_1752;
            {
              Vec<1, Pointer> leb128_ptr_904 { id_1751 };
              bool while_flag_1753 { true };
              do {
                uint8_t id_1754 { 0 };
                uint8_t id_1755 { 0 };
                Pointer id_1756 { leb128_ptr_904[id_1755] };
                uint32_t id_1757 { 128U };
                uint8_t id_1758 { 0 };
                uint32_t id_1759 { leb128_sz_903[id_1758] };
                bool id_1760 { bool(id_1757 > id_1759) };
                uint8_t choose_res_1761;
                if (id_1760) {
                  uint8_t id_1762 { 0 };
                  uint32_t id_1763 { leb128_sz_903[id_1762] };
                  uint8_t id_1764 { uint8_t(id_1763) };
                  choose_res_1761 = id_1764;
                } else {
                  uint8_t id_1765 { 0 };
                  uint32_t id_1766 { leb128_sz_903[id_1765] };
                  uint8_t id_1767 { uint8_t(id_1766) };
                  uint8_t id_1768 { 128 };
                  uint8_t id_1769 { uint8_t(id_1767 | id_1768) };
                  choose_res_1761 = id_1769;
                }
                Pointer id_1770 { id_1756.writeU8(choose_res_1761) };
                Void id_1771 { ((void)(leb128_ptr_904[id_1754] = id_1770), ::dessser::VOID) };
                (void)id_1771;
                uint8_t id_1772 { 0 };
                uint8_t id_1773 { 0 };
                uint32_t id_1774 { leb128_sz_903[id_1773] };
                uint8_t id_1775 { 7 };
                uint32_t id_1776 { uint32_t(id_1774 >> id_1775) };
                Void id_1777 { ((void)(leb128_sz_903[id_1772] = id_1776), ::dessser::VOID) };
                (void)id_1777;
                uint8_t id_1778 { 0 };
                uint32_t id_1779 { leb128_sz_903[id_1778] };
                uint32_t id_1780 { 0U };
                bool id_1781 { bool(id_1779 > id_1780) };
                while_flag_1753 = id_1781;
                if (while_flag_1753) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_1753);
              (void)::dessser::VOID;
              uint8_t id_1782 { 0 };
              Pointer id_1783 { leb128_ptr_904[id_1782] };
              let_res_1752 = id_1783;
            }
            let_res_1750 = let_res_1752;
          }
          Vec<1, Pointer> id_1784 {  let_res_1750  };
          Pointer let_res_1785;
          {
            Vec<1, Pointer> dst_ref_905 { id_1784 };
            int32_t id_1786 { 0L };
            Vec<1, int32_t> id_1787 {  id_1786  };
            Pointer let_res_1788;
            {
              Vec<1, int32_t> n_ref_906 { id_1787 };
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1789 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_1790 { id_1789.notifications };
              for (dessser::gen::raql_expr::t_ext x_907 : id_1790) {
                uint8_t id_1791 { 0 };
                auto fun1792 { dessser::gen::raql_expr::to_row_binary };
                uint8_t id_1793 { 0 };
                Pointer id_1794 { dst_ref_905[id_1793] };
                Pointer id_1795 { fun1792(x_907, id_1794) };
                Void id_1796 { ((void)(dst_ref_905[id_1791] = id_1795), ::dessser::VOID) };
                (void)id_1796;
                uint8_t id_1797 { 0 };
                int32_t id_1798 { 1L };
                uint8_t id_1799 { 0 };
                int32_t id_1800 { n_ref_906[id_1799] };
                int32_t id_1801 { int32_t(id_1798 + id_1800) };
                Void id_1802 { ((void)(n_ref_906[id_1797] = id_1801), ::dessser::VOID) };
                (void)id_1802;
                (void)id_1802;
              }
              (void)::dessser::VOID;
              uint8_t id_1803 { 0 };
              Pointer id_1804 { dst_ref_905[id_1803] };
              let_res_1788 = id_1804;
            }
            let_res_1785 = let_res_1788;
          }
          let_res_1745 = let_res_1785;
        }
        Pointer let_res_1805;
        {
          Pointer srec_dst_908 { let_res_1745 };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1806 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<dessser::gen::raql_expr::t_ext> id_1807 { id_1806.key };
          uint32_t id_1808 { id_1807.size() };
          Vec<1, uint32_t> id_1809 {  id_1808  };
          Pointer let_res_1810;
          {
            Vec<1, uint32_t> leb128_sz_909 { id_1809 };
            Vec<1, Pointer> id_1811 {  srec_dst_908  };
            Pointer let_res_1812;
            {
              Vec<1, Pointer> leb128_ptr_910 { id_1811 };
              bool while_flag_1813 { true };
              do {
                uint8_t id_1814 { 0 };
                uint8_t id_1815 { 0 };
                Pointer id_1816 { leb128_ptr_910[id_1815] };
                uint32_t id_1817 { 128U };
                uint8_t id_1818 { 0 };
                uint32_t id_1819 { leb128_sz_909[id_1818] };
                bool id_1820 { bool(id_1817 > id_1819) };
                uint8_t choose_res_1821;
                if (id_1820) {
                  uint8_t id_1822 { 0 };
                  uint32_t id_1823 { leb128_sz_909[id_1822] };
                  uint8_t id_1824 { uint8_t(id_1823) };
                  choose_res_1821 = id_1824;
                } else {
                  uint8_t id_1825 { 0 };
                  uint32_t id_1826 { leb128_sz_909[id_1825] };
                  uint8_t id_1827 { uint8_t(id_1826) };
                  uint8_t id_1828 { 128 };
                  uint8_t id_1829 { uint8_t(id_1827 | id_1828) };
                  choose_res_1821 = id_1829;
                }
                Pointer id_1830 { id_1816.writeU8(choose_res_1821) };
                Void id_1831 { ((void)(leb128_ptr_910[id_1814] = id_1830), ::dessser::VOID) };
                (void)id_1831;
                uint8_t id_1832 { 0 };
                uint8_t id_1833 { 0 };
                uint32_t id_1834 { leb128_sz_909[id_1833] };
                uint8_t id_1835 { 7 };
                uint32_t id_1836 { uint32_t(id_1834 >> id_1835) };
                Void id_1837 { ((void)(leb128_sz_909[id_1832] = id_1836), ::dessser::VOID) };
                (void)id_1837;
                uint8_t id_1838 { 0 };
                uint32_t id_1839 { leb128_sz_909[id_1838] };
                uint32_t id_1840 { 0U };
                bool id_1841 { bool(id_1839 > id_1840) };
                while_flag_1813 = id_1841;
                if (while_flag_1813) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_1813);
              (void)::dessser::VOID;
              uint8_t id_1842 { 0 };
              Pointer id_1843 { leb128_ptr_910[id_1842] };
              let_res_1812 = id_1843;
            }
            let_res_1810 = let_res_1812;
          }
          Vec<1, Pointer> id_1844 {  let_res_1810  };
          Pointer let_res_1845;
          {
            Vec<1, Pointer> dst_ref_911 { id_1844 };
            int32_t id_1846 { 0L };
            Vec<1, int32_t> id_1847 {  id_1846  };
            Pointer let_res_1848;
            {
              Vec<1, int32_t> n_ref_912 { id_1847 };
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1849 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_1850 { id_1849.key };
              for (dessser::gen::raql_expr::t_ext x_913 : id_1850) {
                uint8_t id_1851 { 0 };
                auto fun1852 { dessser::gen::raql_expr::to_row_binary };
                uint8_t id_1853 { 0 };
                Pointer id_1854 { dst_ref_911[id_1853] };
                Pointer id_1855 { fun1852(x_913, id_1854) };
                Void id_1856 { ((void)(dst_ref_911[id_1851] = id_1855), ::dessser::VOID) };
                (void)id_1856;
                uint8_t id_1857 { 0 };
                int32_t id_1858 { 1L };
                uint8_t id_1859 { 0 };
                int32_t id_1860 { n_ref_912[id_1859] };
                int32_t id_1861 { int32_t(id_1858 + id_1860) };
                Void id_1862 { ((void)(n_ref_912[id_1857] = id_1861), ::dessser::VOID) };
                (void)id_1862;
                (void)id_1862;
              }
              (void)::dessser::VOID;
              uint8_t id_1863 { 0 };
              Pointer id_1864 { dst_ref_911[id_1863] };
              let_res_1848 = id_1864;
            }
            let_res_1845 = let_res_1848;
          }
          let_res_1805 = let_res_1845;
        }
        Pointer let_res_1865;
        {
          Pointer srec_dst_914 { let_res_1805 };
          auto fun1866 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1867 { std::get<0 /* Aggregate */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_1868 { id_1867.commit_cond };
          Pointer id_1869 { fun1866(id_1868, srec_dst_914) };
          let_res_1865 = id_1869;
        }
        Pointer let_res_1870;
        {
          Pointer srec_dst_915 { let_res_1865 };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1871 { std::get<0 /* Aggregate */>((*p_0)) };
          bool id_1872 { id_1871.commit_before };
          uint8_t id_1873 { uint8_t(id_1872) };
          Pointer id_1874 { srec_dst_915.writeU8(id_1873) };
          let_res_1870 = id_1874;
        }
        Pointer let_res_1875;
        {
          Pointer srec_dst_916 { let_res_1870 };
          auto fun1876 { dessser::gen::raql_flush_method::to_row_binary };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1877 { std::get<0 /* Aggregate */>((*p_0)) };
          dessser::gen::raql_flush_method::t_ext id_1878 { id_1877.flush_how };
          Pointer id_1879 { fun1876(id_1878, srec_dst_916) };
          let_res_1875 = id_1879;
        }
        Pointer let_res_1880;
        {
          Pointer srec_dst_917 { let_res_1875 };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1881 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> > id_1882 { id_1881.from };
          uint32_t id_1883 { id_1882.size() };
          Vec<1, uint32_t> id_1884 {  id_1883  };
          Pointer let_res_1885;
          {
            Vec<1, uint32_t> leb128_sz_918 { id_1884 };
            Vec<1, Pointer> id_1886 {  srec_dst_917  };
            Pointer let_res_1887;
            {
              Vec<1, Pointer> leb128_ptr_919 { id_1886 };
              bool while_flag_1888 { true };
              do {
                uint8_t id_1889 { 0 };
                uint8_t id_1890 { 0 };
                Pointer id_1891 { leb128_ptr_919[id_1890] };
                uint32_t id_1892 { 128U };
                uint8_t id_1893 { 0 };
                uint32_t id_1894 { leb128_sz_918[id_1893] };
                bool id_1895 { bool(id_1892 > id_1894) };
                uint8_t choose_res_1896;
                if (id_1895) {
                  uint8_t id_1897 { 0 };
                  uint32_t id_1898 { leb128_sz_918[id_1897] };
                  uint8_t id_1899 { uint8_t(id_1898) };
                  choose_res_1896 = id_1899;
                } else {
                  uint8_t id_1900 { 0 };
                  uint32_t id_1901 { leb128_sz_918[id_1900] };
                  uint8_t id_1902 { uint8_t(id_1901) };
                  uint8_t id_1903 { 128 };
                  uint8_t id_1904 { uint8_t(id_1902 | id_1903) };
                  choose_res_1896 = id_1904;
                }
                Pointer id_1905 { id_1891.writeU8(choose_res_1896) };
                Void id_1906 { ((void)(leb128_ptr_919[id_1889] = id_1905), ::dessser::VOID) };
                (void)id_1906;
                uint8_t id_1907 { 0 };
                uint8_t id_1908 { 0 };
                uint32_t id_1909 { leb128_sz_918[id_1908] };
                uint8_t id_1910 { 7 };
                uint32_t id_1911 { uint32_t(id_1909 >> id_1910) };
                Void id_1912 { ((void)(leb128_sz_918[id_1907] = id_1911), ::dessser::VOID) };
                (void)id_1912;
                uint8_t id_1913 { 0 };
                uint32_t id_1914 { leb128_sz_918[id_1913] };
                uint32_t id_1915 { 0U };
                bool id_1916 { bool(id_1914 > id_1915) };
                while_flag_1888 = id_1916;
                if (while_flag_1888) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_1888);
              (void)::dessser::VOID;
              uint8_t id_1917 { 0 };
              Pointer id_1918 { leb128_ptr_919[id_1917] };
              let_res_1887 = id_1918;
            }
            let_res_1885 = let_res_1887;
          }
          Vec<1, Pointer> id_1919 {  let_res_1885  };
          Pointer let_res_1920;
          {
            Vec<1, Pointer> dst_ref_920 { id_1919 };
            int32_t id_1921 { 0L };
            Vec<1, int32_t> id_1922 {  id_1921  };
            Pointer let_res_1923;
            {
              Vec<1, int32_t> n_ref_921 { id_1922 };
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1924 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> > id_1925 { id_1924.from };
              for (std::shared_ptr<::dessser::gen::raql_operation::data_source>  x_922 : id_1925) {
                uint8_t id_1926 { 0 };
                uint8_t id_1927 { 0 };
                Pointer id_1928 { dst_ref_920[id_1927] };
                Pointer id_1929 { data_source_to_row_binary(x_922, id_1928) };
                Void id_1930 { ((void)(dst_ref_920[id_1926] = id_1929), ::dessser::VOID) };
                (void)id_1930;
                uint8_t id_1931 { 0 };
                int32_t id_1932 { 1L };
                uint8_t id_1933 { 0 };
                int32_t id_1934 { n_ref_921[id_1933] };
                int32_t id_1935 { int32_t(id_1932 + id_1934) };
                Void id_1936 { ((void)(n_ref_921[id_1931] = id_1935), ::dessser::VOID) };
                (void)id_1936;
                (void)id_1936;
              }
              (void)::dessser::VOID;
              uint8_t id_1937 { 0 };
              Pointer id_1938 { dst_ref_920[id_1937] };
              let_res_1923 = id_1938;
            }
            let_res_1920 = let_res_1923;
          }
          let_res_1880 = let_res_1920;
        }
        Pointer let_res_1939;
        {
          Pointer srec_dst_923 { let_res_1880 };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1940 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_1941 { id_1940.every };
          bool id_1942 { !(id_1941.has_value ()) };
          Pointer choose_res_1943;
          if (id_1942) {
            uint8_t id_1944 { 1 };
            Pointer id_1945 { srec_dst_923.writeU8(id_1944) };
            choose_res_1943 = id_1945;
          } else {
            auto fun1946 { dessser::gen::raql_expr::to_row_binary };
            ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1947 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<dessser::gen::raql_expr::t_ext> id_1948 { id_1947.every };
            dessser::gen::raql_expr::t_ext id_1949 { id_1948.value() };
            uint8_t id_1950 { 0 };
            Pointer id_1951 { srec_dst_923.writeU8(id_1950) };
            Pointer id_1952 { fun1946(id_1949, id_1951) };
            choose_res_1943 = id_1952;
          }
          let_res_1939 = choose_res_1943;
        }
        Pointer let_res_1953;
        {
          Pointer srec_dst_924 { let_res_1939 };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1954 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<dessser::gen::field_name::t_ext> id_1955 { id_1954.Aggregate_factors };
          uint32_t id_1956 { id_1955.size() };
          Vec<1, uint32_t> id_1957 {  id_1956  };
          Pointer let_res_1958;
          {
            Vec<1, uint32_t> leb128_sz_925 { id_1957 };
            Vec<1, Pointer> id_1959 {  srec_dst_924  };
            Pointer let_res_1960;
            {
              Vec<1, Pointer> leb128_ptr_926 { id_1959 };
              bool while_flag_1961 { true };
              do {
                uint8_t id_1962 { 0 };
                uint8_t id_1963 { 0 };
                Pointer id_1964 { leb128_ptr_926[id_1963] };
                uint32_t id_1965 { 128U };
                uint8_t id_1966 { 0 };
                uint32_t id_1967 { leb128_sz_925[id_1966] };
                bool id_1968 { bool(id_1965 > id_1967) };
                uint8_t choose_res_1969;
                if (id_1968) {
                  uint8_t id_1970 { 0 };
                  uint32_t id_1971 { leb128_sz_925[id_1970] };
                  uint8_t id_1972 { uint8_t(id_1971) };
                  choose_res_1969 = id_1972;
                } else {
                  uint8_t id_1973 { 0 };
                  uint32_t id_1974 { leb128_sz_925[id_1973] };
                  uint8_t id_1975 { uint8_t(id_1974) };
                  uint8_t id_1976 { 128 };
                  uint8_t id_1977 { uint8_t(id_1975 | id_1976) };
                  choose_res_1969 = id_1977;
                }
                Pointer id_1978 { id_1964.writeU8(choose_res_1969) };
                Void id_1979 { ((void)(leb128_ptr_926[id_1962] = id_1978), ::dessser::VOID) };
                (void)id_1979;
                uint8_t id_1980 { 0 };
                uint8_t id_1981 { 0 };
                uint32_t id_1982 { leb128_sz_925[id_1981] };
                uint8_t id_1983 { 7 };
                uint32_t id_1984 { uint32_t(id_1982 >> id_1983) };
                Void id_1985 { ((void)(leb128_sz_925[id_1980] = id_1984), ::dessser::VOID) };
                (void)id_1985;
                uint8_t id_1986 { 0 };
                uint32_t id_1987 { leb128_sz_925[id_1986] };
                uint32_t id_1988 { 0U };
                bool id_1989 { bool(id_1987 > id_1988) };
                while_flag_1961 = id_1989;
                if (while_flag_1961) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_1961);
              (void)::dessser::VOID;
              uint8_t id_1990 { 0 };
              Pointer id_1991 { leb128_ptr_926[id_1990] };
              let_res_1960 = id_1991;
            }
            let_res_1958 = let_res_1960;
          }
          Vec<1, Pointer> id_1992 {  let_res_1958  };
          Pointer let_res_1993;
          {
            Vec<1, Pointer> dst_ref_927 { id_1992 };
            int32_t id_1994 { 0L };
            Vec<1, int32_t> id_1995 {  id_1994  };
            Pointer let_res_1996;
            {
              Vec<1, int32_t> n_ref_928 { id_1995 };
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_1997 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::field_name::t_ext> id_1998 { id_1997.Aggregate_factors };
              for (dessser::gen::field_name::t_ext x_929 : id_1998) {
                uint8_t id_1999 { 0 };
                auto fun2000 { dessser::gen::field_name::to_row_binary };
                uint8_t id_2001 { 0 };
                Pointer id_2002 { dst_ref_927[id_2001] };
                Pointer id_2003 { fun2000(x_929, id_2002) };
                Void id_2004 { ((void)(dst_ref_927[id_1999] = id_2003), ::dessser::VOID) };
                (void)id_2004;
                uint8_t id_2005 { 0 };
                int32_t id_2006 { 1L };
                uint8_t id_2007 { 0 };
                int32_t id_2008 { n_ref_928[id_2007] };
                int32_t id_2009 { int32_t(id_2006 + id_2008) };
                Void id_2010 { ((void)(n_ref_928[id_2005] = id_2009), ::dessser::VOID) };
                (void)id_2010;
                (void)id_2010;
              }
              (void)::dessser::VOID;
              uint8_t id_2011 { 0 };
              Pointer id_2012 { dst_ref_927[id_2011] };
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
          ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2017 { std::get<1 /* ReadExternal */>((*p_0)) };
          std::shared_ptr<::dessser::gen::raql_operation::external_source>  id_2018 { id_2017.source };
          Pointer id_2019 { external_source_to_row_binary(id_2018, ssum_dst_861) };
          Pointer let_res_2020;
          {
            Pointer srec_dst_872 { id_2019 };
            ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2021 { std::get<1 /* ReadExternal */>((*p_0)) };
            std::shared_ptr<::dessser::gen::raql_operation::external_format>  id_2022 { id_2021.format };
            Pointer id_2023 { external_format_to_row_binary(id_2022, srec_dst_872) };
            let_res_2020 = id_2023;
          }
          Pointer let_res_2024;
          {
            Pointer srec_dst_873 { let_res_2020 };
            ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2025 { std::get<1 /* ReadExternal */>((*p_0)) };
            std::optional<dessser::gen::event_time::t_ext> id_2026 { id_2025.event_time };
            bool id_2027 { !(id_2026.has_value ()) };
            Pointer choose_res_2028;
            if (id_2027) {
              uint8_t id_2029 { 1 };
              Pointer id_2030 { srec_dst_873.writeU8(id_2029) };
              choose_res_2028 = id_2030;
            } else {
              auto fun2031 { dessser::gen::event_time::to_row_binary };
              ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2032 { std::get<1 /* ReadExternal */>((*p_0)) };
              std::optional<dessser::gen::event_time::t_ext> id_2033 { id_2032.event_time };
              dessser::gen::event_time::t_ext id_2034 { id_2033.value() };
              uint8_t id_2035 { 0 };
              Pointer id_2036 { srec_dst_873.writeU8(id_2035) };
              Pointer id_2037 { fun2031(id_2034, id_2036) };
              choose_res_2028 = id_2037;
            }
            let_res_2024 = choose_res_2028;
          }
          Pointer let_res_2038;
          {
            Pointer srec_dst_874 { let_res_2024 };
            ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2039 { std::get<1 /* ReadExternal */>((*p_0)) };
            Lst<dessser::gen::field_name::t_ext> id_2040 { id_2039.ReadExternal_factors };
            uint32_t id_2041 { id_2040.size() };
            Vec<1, uint32_t> id_2042 {  id_2041  };
            Pointer let_res_2043;
            {
              Vec<1, uint32_t> leb128_sz_875 { id_2042 };
              Vec<1, Pointer> id_2044 {  srec_dst_874  };
              Pointer let_res_2045;
              {
                Vec<1, Pointer> leb128_ptr_876 { id_2044 };
                bool while_flag_2046 { true };
                do {
                  uint8_t id_2047 { 0 };
                  uint8_t id_2048 { 0 };
                  Pointer id_2049 { leb128_ptr_876[id_2048] };
                  uint32_t id_2050 { 128U };
                  uint8_t id_2051 { 0 };
                  uint32_t id_2052 { leb128_sz_875[id_2051] };
                  bool id_2053 { bool(id_2050 > id_2052) };
                  uint8_t choose_res_2054;
                  if (id_2053) {
                    uint8_t id_2055 { 0 };
                    uint32_t id_2056 { leb128_sz_875[id_2055] };
                    uint8_t id_2057 { uint8_t(id_2056) };
                    choose_res_2054 = id_2057;
                  } else {
                    uint8_t id_2058 { 0 };
                    uint32_t id_2059 { leb128_sz_875[id_2058] };
                    uint8_t id_2060 { uint8_t(id_2059) };
                    uint8_t id_2061 { 128 };
                    uint8_t id_2062 { uint8_t(id_2060 | id_2061) };
                    choose_res_2054 = id_2062;
                  }
                  Pointer id_2063 { id_2049.writeU8(choose_res_2054) };
                  Void id_2064 { ((void)(leb128_ptr_876[id_2047] = id_2063), ::dessser::VOID) };
                  (void)id_2064;
                  uint8_t id_2065 { 0 };
                  uint8_t id_2066 { 0 };
                  uint32_t id_2067 { leb128_sz_875[id_2066] };
                  uint8_t id_2068 { 7 };
                  uint32_t id_2069 { uint32_t(id_2067 >> id_2068) };
                  Void id_2070 { ((void)(leb128_sz_875[id_2065] = id_2069), ::dessser::VOID) };
                  (void)id_2070;
                  uint8_t id_2071 { 0 };
                  uint32_t id_2072 { leb128_sz_875[id_2071] };
                  uint32_t id_2073 { 0U };
                  bool id_2074 { bool(id_2072 > id_2073) };
                  while_flag_2046 = id_2074;
                  if (while_flag_2046) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_2046);
                (void)::dessser::VOID;
                uint8_t id_2075 { 0 };
                Pointer id_2076 { leb128_ptr_876[id_2075] };
                let_res_2045 = id_2076;
              }
              let_res_2043 = let_res_2045;
            }
            Vec<1, Pointer> id_2077 {  let_res_2043  };
            Pointer let_res_2078;
            {
              Vec<1, Pointer> dst_ref_877 { id_2077 };
              int32_t id_2079 { 0L };
              Vec<1, int32_t> id_2080 {  id_2079  };
              Pointer let_res_2081;
              {
                Vec<1, int32_t> n_ref_878 { id_2080 };
                ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2082 { std::get<1 /* ReadExternal */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2083 { id_2082.ReadExternal_factors };
                for (dessser::gen::field_name::t_ext x_879 : id_2083) {
                  uint8_t id_2084 { 0 };
                  auto fun2085 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_2086 { 0 };
                  Pointer id_2087 { dst_ref_877[id_2086] };
                  Pointer id_2088 { fun2085(x_879, id_2087) };
                  Void id_2089 { ((void)(dst_ref_877[id_2084] = id_2088), ::dessser::VOID) };
                  (void)id_2089;
                  uint8_t id_2090 { 0 };
                  int32_t id_2091 { 1L };
                  uint8_t id_2092 { 0 };
                  int32_t id_2093 { n_ref_878[id_2092] };
                  int32_t id_2094 { int32_t(id_2091 + id_2093) };
                  Void id_2095 { ((void)(n_ref_878[id_2090] = id_2094), ::dessser::VOID) };
                  (void)id_2095;
                  (void)id_2095;
                }
                (void)::dessser::VOID;
                uint8_t id_2096 { 0 };
                Pointer id_2097 { dst_ref_877[id_2096] };
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
          Void id_2101 { ((void)(assert(id_2100)), ::dessser::VOID) };
          (void)id_2101;
          ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2102 { std::get<2 /* ListenFor */>((*p_0)) };
          std::string id_2103 { id_2102.net_addr };
          uint32_t id_2104 { (uint32_t)id_2103.size() };
          Vec<1, uint32_t> id_2105 {  id_2104  };
          Pointer let_res_2106;
          {
            Vec<1, uint32_t> leb128_sz_862 { id_2105 };
            Vec<1, Pointer> id_2107 {  ssum_dst_861  };
            Pointer let_res_2108;
            {
              Vec<1, Pointer> leb128_ptr_863 { id_2107 };
              bool while_flag_2109 { true };
              do {
                uint8_t id_2110 { 0 };
                uint8_t id_2111 { 0 };
                Pointer id_2112 { leb128_ptr_863[id_2111] };
                uint32_t id_2113 { 128U };
                uint8_t id_2114 { 0 };
                uint32_t id_2115 { leb128_sz_862[id_2114] };
                bool id_2116 { bool(id_2113 > id_2115) };
                uint8_t choose_res_2117;
                if (id_2116) {
                  uint8_t id_2118 { 0 };
                  uint32_t id_2119 { leb128_sz_862[id_2118] };
                  uint8_t id_2120 { uint8_t(id_2119) };
                  choose_res_2117 = id_2120;
                } else {
                  uint8_t id_2121 { 0 };
                  uint32_t id_2122 { leb128_sz_862[id_2121] };
                  uint8_t id_2123 { uint8_t(id_2122) };
                  uint8_t id_2124 { 128 };
                  uint8_t id_2125 { uint8_t(id_2123 | id_2124) };
                  choose_res_2117 = id_2125;
                }
                Pointer id_2126 { id_2112.writeU8(choose_res_2117) };
                Void id_2127 { ((void)(leb128_ptr_863[id_2110] = id_2126), ::dessser::VOID) };
                (void)id_2127;
                uint8_t id_2128 { 0 };
                uint8_t id_2129 { 0 };
                uint32_t id_2130 { leb128_sz_862[id_2129] };
                uint8_t id_2131 { 7 };
                uint32_t id_2132 { uint32_t(id_2130 >> id_2131) };
                Void id_2133 { ((void)(leb128_sz_862[id_2128] = id_2132), ::dessser::VOID) };
                (void)id_2133;
                uint8_t id_2134 { 0 };
                uint32_t id_2135 { leb128_sz_862[id_2134] };
                uint32_t id_2136 { 0U };
                bool id_2137 { bool(id_2135 > id_2136) };
                while_flag_2109 = id_2137;
                if (while_flag_2109) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_2109);
              (void)::dessser::VOID;
              uint8_t id_2138 { 0 };
              Pointer id_2139 { leb128_ptr_863[id_2138] };
              let_res_2108 = id_2139;
            }
            let_res_2106 = let_res_2108;
          }
          ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2140 { std::get<2 /* ListenFor */>((*p_0)) };
          std::string id_2141 { id_2140.net_addr };
          Bytes id_2142 { id_2141 };
          Pointer id_2143 { let_res_2106.writeBytes(id_2142) };
          Pointer let_res_2144;
          {
            Pointer srec_dst_864 { id_2143 };
            ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2145 { std::get<2 /* ListenFor */>((*p_0)) };
            uint16_t id_2146 { id_2145.port };
            Pointer id_2147 { srec_dst_864.writeU16Le(id_2146) };
            let_res_2144 = id_2147;
          }
          Pointer let_res_2148;
          {
            Pointer srec_dst_865 { let_res_2144 };
            auto fun2149 { dessser::gen::raql_net_protocol::to_row_binary };
            ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2150 { std::get<2 /* ListenFor */>((*p_0)) };
            dessser::gen::raql_net_protocol::t_ext id_2151 { id_2150.proto };
            Pointer id_2152 { fun2149(id_2151, srec_dst_865) };
            let_res_2148 = id_2152;
          }
          Pointer let_res_2153;
          {
            Pointer srec_dst_866 { let_res_2148 };
            ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2154 { std::get<2 /* ListenFor */>((*p_0)) };
            Lst<dessser::gen::field_name::t_ext> id_2155 { id_2154.factors };
            uint32_t id_2156 { id_2155.size() };
            Vec<1, uint32_t> id_2157 {  id_2156  };
            Pointer let_res_2158;
            {
              Vec<1, uint32_t> leb128_sz_867 { id_2157 };
              Vec<1, Pointer> id_2159 {  srec_dst_866  };
              Pointer let_res_2160;
              {
                Vec<1, Pointer> leb128_ptr_868 { id_2159 };
                bool while_flag_2161 { true };
                do {
                  uint8_t id_2162 { 0 };
                  uint8_t id_2163 { 0 };
                  Pointer id_2164 { leb128_ptr_868[id_2163] };
                  uint32_t id_2165 { 128U };
                  uint8_t id_2166 { 0 };
                  uint32_t id_2167 { leb128_sz_867[id_2166] };
                  bool id_2168 { bool(id_2165 > id_2167) };
                  uint8_t choose_res_2169;
                  if (id_2168) {
                    uint8_t id_2170 { 0 };
                    uint32_t id_2171 { leb128_sz_867[id_2170] };
                    uint8_t id_2172 { uint8_t(id_2171) };
                    choose_res_2169 = id_2172;
                  } else {
                    uint8_t id_2173 { 0 };
                    uint32_t id_2174 { leb128_sz_867[id_2173] };
                    uint8_t id_2175 { uint8_t(id_2174) };
                    uint8_t id_2176 { 128 };
                    uint8_t id_2177 { uint8_t(id_2175 | id_2176) };
                    choose_res_2169 = id_2177;
                  }
                  Pointer id_2178 { id_2164.writeU8(choose_res_2169) };
                  Void id_2179 { ((void)(leb128_ptr_868[id_2162] = id_2178), ::dessser::VOID) };
                  (void)id_2179;
                  uint8_t id_2180 { 0 };
                  uint8_t id_2181 { 0 };
                  uint32_t id_2182 { leb128_sz_867[id_2181] };
                  uint8_t id_2183 { 7 };
                  uint32_t id_2184 { uint32_t(id_2182 >> id_2183) };
                  Void id_2185 { ((void)(leb128_sz_867[id_2180] = id_2184), ::dessser::VOID) };
                  (void)id_2185;
                  uint8_t id_2186 { 0 };
                  uint32_t id_2187 { leb128_sz_867[id_2186] };
                  uint32_t id_2188 { 0U };
                  bool id_2189 { bool(id_2187 > id_2188) };
                  while_flag_2161 = id_2189;
                  if (while_flag_2161) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_2161);
                (void)::dessser::VOID;
                uint8_t id_2190 { 0 };
                Pointer id_2191 { leb128_ptr_868[id_2190] };
                let_res_2160 = id_2191;
              }
              let_res_2158 = let_res_2160;
            }
            Vec<1, Pointer> id_2192 {  let_res_2158  };
            Pointer let_res_2193;
            {
              Vec<1, Pointer> dst_ref_869 { id_2192 };
              int32_t id_2194 { 0L };
              Vec<1, int32_t> id_2195 {  id_2194  };
              Pointer let_res_2196;
              {
                Vec<1, int32_t> n_ref_870 { id_2195 };
                ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2197 { std::get<2 /* ListenFor */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2198 { id_2197.factors };
                for (dessser::gen::field_name::t_ext x_871 : id_2198) {
                  uint8_t id_2199 { 0 };
                  auto fun2200 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_2201 { 0 };
                  Pointer id_2202 { dst_ref_869[id_2201] };
                  Pointer id_2203 { fun2200(x_871, id_2202) };
                  Void id_2204 { ((void)(dst_ref_869[id_2199] = id_2203), ::dessser::VOID) };
                  (void)id_2204;
                  uint8_t id_2205 { 0 };
                  int32_t id_2206 { 1L };
                  uint8_t id_2207 { 0 };
                  int32_t id_2208 { n_ref_870[id_2207] };
                  int32_t id_2209 { int32_t(id_2206 + id_2208) };
                  Void id_2210 { ((void)(n_ref_870[id_2205] = id_2209), ::dessser::VOID) };
                  (void)id_2210;
                  (void)id_2210;
                }
                (void)::dessser::VOID;
                uint8_t id_2211 { 0 };
                Pointer id_2212 { dst_ref_869[id_2211] };
                let_res_2196 = id_2212;
              }
              let_res_2193 = let_res_2196;
            }
            let_res_2153 = let_res_2193;
          }
          choose_res_2016 = let_res_2153;
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
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_702"
          (let "sz_698"
            (if (eq (u16 0) (label-of (get-item 0 (get-alt "NamedOperation" (param 0))))) 
              (size 4)
              (if (eq (u16 1) (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))))
                (add (size 4)
                  (add
                    (let "n_ref_696" (make-vec (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0))))))
                      (let "lebsz_ref_697" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_696")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_697")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_697") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_697")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_697")))))) 
                    (size-of-u32 (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0)))))))) 
                (seq (assert (eq (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))) (u16 2))) (size 4))))
            (if (is-null (get-item 1 (get-alt "NamedOperation" (param 0)))) 
              (add (identifier "sz_698") (size 1))
              (add
                (add (identifier "sz_698")
                  (add
                    (let "n_ref_700" (make-vec (string-length (force (get-item 1 (get-alt "NamedOperation" (param 0))))))
                      (let "lebsz_ref_701" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_700")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_701")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_701") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_701")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_701")))))) 
                    (size-of-u32 (string-length (force (get-item 1 (get-alt "NamedOperation" (param 0)))))))) 
                (size 1)))) (add (identifier "sz_702") (apply (ext-identifier function_name sersize-of-row-binary) (get-item 2 (get-alt "NamedOperation" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "sersize-of-row-binary") (get-alt "SubQuery" (param 0)))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::data_source> )> data_source_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::data_source> )> fun2213 { [&fun2213](std::shared_ptr<::dessser::gen::raql_operation::data_source>  p_0) {
    uint16_t id_2214 { 0 };
    uint16_t id_2215 { uint16_t((*p_0).index()) };
    bool id_2216 { bool(id_2214 == id_2215) };
    Size choose_res_2217;
    if (id_2216) {
      uint16_t id_2218 { 0 };
      ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_2219 { std::get<0 /* NamedOperation */>((*p_0)) };
      ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_2220 { std::get<0>(id_2219) };
      uint16_t id_2221 { uint16_t(id_2220.index()) };
      bool id_2222 { bool(id_2218 == id_2221) };
      Size choose_res_2223;
      if (id_2222) {
        Size id_2224 { 4UL };
        choose_res_2223 = id_2224;
      } else {
        uint16_t id_2225 { 1 };
        ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_2226 { std::get<0 /* NamedOperation */>((*p_0)) };
        ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_2227 { std::get<0>(id_2226) };
        uint16_t id_2228 { uint16_t(id_2227.index()) };
        bool id_2229 { bool(id_2225 == id_2228) };
        Size choose_res_2230;
        if (id_2229) {
          Size id_2231 { 4UL };
          ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_2232 { std::get<0 /* NamedOperation */>((*p_0)) };
          ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_2233 { std::get<0>(id_2232) };
          std::string id_2234 { std::get<1 /* TheseSites */>(id_2233) };
          uint32_t id_2235 { (uint32_t)id_2234.size() };
          Vec<1, uint32_t> id_2236 {  id_2235  };
          Size let_res_2237;
          {
            Vec<1, uint32_t> n_ref_696 { id_2236 };
            uint32_t id_2238 { 1U };
            Vec<1, uint32_t> id_2239 {  id_2238  };
            Size let_res_2240;
            {
              Vec<1, uint32_t> lebsz_ref_697 { id_2239 };
              bool while_flag_2241 { true };
              do {
                uint8_t id_2242 { 0 };
                uint32_t id_2243 { n_ref_696[id_2242] };
                uint8_t id_2244 { 0 };
                uint32_t id_2245 { lebsz_ref_697[id_2244] };
                uint8_t id_2246 { 7 };
                uint32_t id_2247 { uint32_t(id_2245 << id_2246) };
                bool id_2248 { bool(id_2243 >= id_2247) };
                while_flag_2241 = id_2248;
                if (while_flag_2241) {
                  uint8_t id_2249 { 0 };
                  uint8_t id_2250 { 0 };
                  uint32_t id_2251 { lebsz_ref_697[id_2250] };
                  uint32_t id_2252 { 1U };
                  uint32_t id_2253 { uint32_t(id_2251 + id_2252) };
                  Void id_2254 { ((void)(lebsz_ref_697[id_2249] = id_2253), ::dessser::VOID) };
                  (void)id_2254;
                }
              } while (while_flag_2241);
              (void)::dessser::VOID;
              uint8_t id_2255 { 0 };
              uint32_t id_2256 { lebsz_ref_697[id_2255] };
              Size id_2257 { Size(id_2256) };
              let_res_2240 = id_2257;
            }
            let_res_2237 = let_res_2240;
          }
          ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_2258 { std::get<0 /* NamedOperation */>((*p_0)) };
          ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_2259 { std::get<0>(id_2258) };
          std::string id_2260 { std::get<1 /* TheseSites */>(id_2259) };
          uint32_t id_2261 { (uint32_t)id_2260.size() };
          Size id_2262 { Size(id_2261) };
          Size id_2263 { Size(let_res_2237 + id_2262) };
          Size id_2264 { Size(id_2231 + id_2263) };
          choose_res_2230 = id_2264;
        } else {
          ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_2265 { std::get<0 /* NamedOperation */>((*p_0)) };
          ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_2266 { std::get<0>(id_2265) };
          uint16_t id_2267 { uint16_t(id_2266.index()) };
          uint16_t id_2268 { 2 };
          bool id_2269 { bool(id_2267 == id_2268) };
          Void id_2270 { ((void)(assert(id_2269)), ::dessser::VOID) };
          (void)id_2270;
          Size id_2271 { 4UL };
          choose_res_2230 = id_2271;
        }
        choose_res_2223 = choose_res_2230;
      }
      Size let_res_2272;
      {
        Size sz_698 { choose_res_2223 };
        ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_2273 { std::get<0 /* NamedOperation */>((*p_0)) };
        std::optional<std::string> id_2274 { std::get<1>(id_2273) };
        bool id_2275 { !(id_2274.has_value ()) };
        Size choose_res_2276;
        if (id_2275) {
          Size id_2277 { 1UL };
          Size id_2278 { Size(sz_698 + id_2277) };
          choose_res_2276 = id_2278;
        } else {
          ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_2279 { std::get<0 /* NamedOperation */>((*p_0)) };
          std::optional<std::string> id_2280 { std::get<1>(id_2279) };
          std::string id_2281 { id_2280.value() };
          uint32_t id_2282 { (uint32_t)id_2281.size() };
          Vec<1, uint32_t> id_2283 {  id_2282  };
          Size let_res_2284;
          {
            Vec<1, uint32_t> n_ref_700 { id_2283 };
            uint32_t id_2285 { 1U };
            Vec<1, uint32_t> id_2286 {  id_2285  };
            Size let_res_2287;
            {
              Vec<1, uint32_t> lebsz_ref_701 { id_2286 };
              bool while_flag_2288 { true };
              do {
                uint8_t id_2289 { 0 };
                uint32_t id_2290 { n_ref_700[id_2289] };
                uint8_t id_2291 { 0 };
                uint32_t id_2292 { lebsz_ref_701[id_2291] };
                uint8_t id_2293 { 7 };
                uint32_t id_2294 { uint32_t(id_2292 << id_2293) };
                bool id_2295 { bool(id_2290 >= id_2294) };
                while_flag_2288 = id_2295;
                if (while_flag_2288) {
                  uint8_t id_2296 { 0 };
                  uint8_t id_2297 { 0 };
                  uint32_t id_2298 { lebsz_ref_701[id_2297] };
                  uint32_t id_2299 { 1U };
                  uint32_t id_2300 { uint32_t(id_2298 + id_2299) };
                  Void id_2301 { ((void)(lebsz_ref_701[id_2296] = id_2300), ::dessser::VOID) };
                  (void)id_2301;
                }
              } while (while_flag_2288);
              (void)::dessser::VOID;
              uint8_t id_2302 { 0 };
              uint32_t id_2303 { lebsz_ref_701[id_2302] };
              Size id_2304 { Size(id_2303) };
              let_res_2287 = id_2304;
            }
            let_res_2284 = let_res_2287;
          }
          ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_2305 { std::get<0 /* NamedOperation */>((*p_0)) };
          std::optional<std::string> id_2306 { std::get<1>(id_2305) };
          std::string id_2307 { id_2306.value() };
          uint32_t id_2308 { (uint32_t)id_2307.size() };
          Size id_2309 { Size(id_2308) };
          Size id_2310 { Size(let_res_2284 + id_2309) };
          Size id_2311 { Size(sz_698 + id_2310) };
          Size id_2312 { 1UL };
          Size id_2313 { Size(id_2311 + id_2312) };
          choose_res_2276 = id_2313;
        }
        let_res_2272 = choose_res_2276;
      }
      Size let_res_2314;
      {
        Size sz_702 { let_res_2272 };
        auto fun2315 { dessser::gen::function_name::sersize_of_row_binary };
        ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_2316 { std::get<0 /* NamedOperation */>((*p_0)) };
        dessser::gen::function_name::t_ext id_2317 { std::get<2>(id_2316) };
        Size id_2318 { fun2315(id_2317) };
        Size id_2319 { Size(sz_702 + id_2318) };
        let_res_2314 = id_2319;
      }
      choose_res_2217 = let_res_2314;
    } else {
      uint16_t id_2320 { uint16_t((*p_0).index()) };
      uint16_t id_2321 { 1 };
      bool id_2322 { bool(id_2320 == id_2321) };
      Void id_2323 { ((void)(assert(id_2322)), ::dessser::VOID) };
      (void)id_2323;
      Size id_2324 { 2UL };
      std::shared_ptr<::dessser::gen::raql_operation::t>  id_2325 { std::get<1 /* SubQuery */>((*p_0)) };
      Size id_2326 { sersize_of_row_binary(id_2325) };
      Size id_2327 { Size(id_2324 + id_2326) };
      choose_res_2217 = id_2327;
    }
    return choose_res_2217;
  }
   };
  return fun2213;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::data_source> )> data_source_sersize_of_row_binary(data_source_sersize_of_row_binary_init());

/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_804"
          (let "sz_803"
            (let "sz_798"
              (let "sz_797"
                (add
                  (let "sz_795"
                    (let "sz_790"
                      (let "sz_785"
                        (let "sz_784"
                          (let "sz_783"
                            (let "sz_775"
                              (let "sz_770"
                                (let "sz_ref_768"
                                  (make-vec
                                    (add (size 2)
                                      (let "n_ref_766" (make-vec (cardinality (get-field "fields" (get-alt "Aggregate" (param 0)))))
                                        (let "lebsz_ref_767" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_766")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_767")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_767") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_767")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_767"))))))))
                                  (seq
                                    (let "repeat_n_769" (make-vec (i32 0))
                                      (while (gt (to-i32 (cardinality (get-field "fields" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_769")))
                                        (seq
                                          (set-vec (u8 0) (identifier "sz_ref_768")
                                            (add (unsafe-nth (u8 0) (identifier "sz_ref_768"))
                                              (apply (ext-identifier raql_select_field sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_769")) (get-field "fields" (get-alt "Aggregate" (param 0)))))))
                                          (set-vec (u8 0) (identifier "repeat_n_769") (add (unsafe-nth (u8 0) (identifier "repeat_n_769")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "sz_ref_768"))))
                                (if (is-null (get-field "and_all_others" (get-alt "Aggregate" (param 0)))) 
                                  (add (identifier "sz_770") (size 1))
                                  (add
                                    (let "sz_ref_773"
                                      (make-vec
                                        (add (identifier "sz_770")
                                          (let "n_ref_771" (make-vec (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))
                                            (let "lebsz_ref_772" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_771")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_772")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_772") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_772")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_772"))))))))
                                      (seq
                                        (let "repeat_n_774" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_774")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_773")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_773"))
                                                  (apply (ext-identifier field_name sersize-of-row-binary)
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_774")) (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))))
                                              (set-vec (u8 0) (identifier "repeat_n_774") (add (unsafe-nth (u8 0) (identifier "repeat_n_774")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_773")))) 
                                    (size 1))))
                              (if (is-null (get-field "sort" (get-alt "Aggregate" (param 0)))) 
                                (add (identifier "sz_775") (size 1))
                                (add
                                  (let "sz_778"
                                    (if (is-null (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) 
                                      (add (add (identifier "sz_775") (size 4)) (size 1))
                                      (add (add (add (identifier "sz_775") (size 4)) (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0))))))))
                                        (size 1)))
                                    (let "sz_ref_781"
                                      (make-vec
                                        (add (identifier "sz_778")
                                          (let "n_ref_779" (make-vec (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                            (let "lebsz_ref_780" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_779")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_780")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_780") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_780")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_780"))))))))
                                      (seq
                                        (let "repeat_n_782" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0))))))) (unsafe-nth (u8 0) (identifier "repeat_n_782")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_781")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_781"))
                                                  (apply (ext-identifier raql_expr sersize-of-row-binary)
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_782")) (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))))
                                              (set-vec (u8 0) (identifier "repeat_n_782") (add (unsafe-nth (u8 0) (identifier "repeat_n_782")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_781"))))) 
                                  (size 1)))) (add (identifier "sz_783") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "where" (get-alt "Aggregate" (param 0))))))
                          (if (is-null (get-field "event_time" (get-alt "Aggregate" (param 0)))) 
                            (add (identifier "sz_784") (size 1))
                            (add (add (identifier "sz_784") (apply (ext-identifier event_time sersize-of-row-binary) (force (get-field "event_time" (get-alt "Aggregate" (param 0)))))) (size 1))))
                        (let "sz_ref_788"
                          (make-vec
                            (add (identifier "sz_785")
                              (let "n_ref_786" (make-vec (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0)))))
                                (let "lebsz_ref_787" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_786")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_787")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_787") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_787")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_787"))))))))
                          (seq
                            (let "repeat_n_789" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_789")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_788")
                                    (add (unsafe-nth (u8 0) (identifier "sz_ref_788"))
                                      (apply (ext-identifier raql_expr sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_789")) (get-field "notifications" (get-alt "Aggregate" (param 0)))))))
                                  (set-vec (u8 0) (identifier "repeat_n_789") (add (unsafe-nth (u8 0) (identifier "repeat_n_789")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_788")))))
                      (let "sz_ref_793"
                        (make-vec
                          (add (identifier "sz_790")
                            (let "n_ref_791" (make-vec (cardinality (get-field "key" (get-alt "Aggregate" (param 0)))))
                              (let "lebsz_ref_792" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_791")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_792")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_792") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_792")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_792"))))))))
                        (seq
                          (let "repeat_n_794" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-field "key" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_794")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_793")
                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_793"))
                                    (apply (ext-identifier raql_expr sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_794")) (get-field "key" (get-alt "Aggregate" (param 0)))))))
                                (set-vec (u8 0) (identifier "repeat_n_794") (add (unsafe-nth (u8 0) (identifier "repeat_n_794")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_793"))))) 
                    (add (identifier "sz_795") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "commit_cond" (get-alt "Aggregate" (param 0)))))) 
                  (size 1)) (add (identifier "sz_797") (apply (ext-identifier raql_flush_method sersize-of-row-binary) (get-field "flush_how" (get-alt "Aggregate" (param 0))))))
              (let "sz_ref_801"
                (make-vec
                  (add (identifier "sz_798")
                    (let "n_ref_799" (make-vec (cardinality (get-field "from" (get-alt "Aggregate" (param 0)))))
                      (let "lebsz_ref_800" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_799")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_800")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_800") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_800")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_800"))))))))
                (seq
                  (let "repeat_n_802" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "from" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_802")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_801")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_801"))
                            (apply (identifier "data_source-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_802")) (get-field "from" (get-alt "Aggregate" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_802") (add (unsafe-nth (u8 0) (identifier "repeat_n_802")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_801")))))
            (if (is-null (get-field "every" (get-alt "Aggregate" (param 0)))) 
              (add (identifier "sz_803") (size 1)) (add (add (identifier "sz_803") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "every" (get-alt "Aggregate" (param 0)))))) (size 1))))
          (let "sz_ref_807"
            (make-vec
              (add (identifier "sz_804")
                (let "n_ref_805" (make-vec (cardinality (get-field "factors" (get-alt "Aggregate" (param 0)))))
                  (let "lebsz_ref_806" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_805")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_806")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_806") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_806")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_806"))))))))
            (seq
              (let "repeat_n_808" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_808")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_807")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_807"))
                        (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_808")) (get-field "factors" (get-alt "Aggregate" (param 0)))))))
                    (set-vec (u8 0) (identifier "repeat_n_808") (add (unsafe-nth (u8 0) (identifier "repeat_n_808")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_807")))))
        (if (eq (u16 1) (label-of (param 0)))
          (let "sz_760"
            (let "sz_759"
              (let "sz_758" (add (size 2) (apply (identifier "external_source-sersize-of-row-binary") (get-field "source" (get-alt "ReadExternal" (param 0)))))
                (add (identifier "sz_758") (apply (identifier "external_format-sersize-of-row-binary") (get-field "format" (get-alt "ReadExternal" (param 0))))))
              (if (is-null (get-field "event_time" (get-alt "ReadExternal" (param 0)))) 
                (add (identifier "sz_759") (size 1)) (add (add (identifier "sz_759") (apply (ext-identifier event_time sersize-of-row-binary) (force (get-field "event_time" (get-alt "ReadExternal" (param 0)))))) (size 1))))
            (let "sz_ref_763"
              (make-vec
                (add (identifier "sz_760")
                  (let "n_ref_761" (make-vec (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0)))))
                    (let "lebsz_ref_762" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_761")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_762")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_762") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_762")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_762"))))))))
              (seq
                (let "repeat_n_764" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_764")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_763")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_763"))
                          (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_764")) (get-field "factors" (get-alt "ReadExternal" (param 0)))))))
                      (set-vec (u8 0) (identifier "repeat_n_764") (add (unsafe-nth (u8 0) (identifier "repeat_n_764")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_763")))))
          (seq (assert (eq (label-of (param 0)) (u16 2)))
            (let "sz_752"
              (let "sz_751"
                (add
                  (add (size 2)
                    (add
                      (let "n_ref_748" (make-vec (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0)))))
                        (let "lebsz_ref_749" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_748")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_749")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_749") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_749")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_749")))))) 
                      (size-of-u32 (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0))))))) 
                  (size 2)) (add (identifier "sz_751") (apply (ext-identifier raql_net_protocol sersize-of-row-binary) (get-field "proto" (get-alt "ListenFor" (param 0))))))
              (let "sz_ref_755"
                (make-vec
                  (add (identifier "sz_752")
                    (let "n_ref_753" (make-vec (cardinality (get-field "factors" (get-alt "ListenFor" (param 0)))))
                      (let "lebsz_ref_754" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_753")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_754")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_754") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_754")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_754"))))))))
                (seq
                  (let "repeat_n_756" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "ListenFor" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_756")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_755")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_755"))
                            (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_756")) (get-field "factors" (get-alt "ListenFor" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_756") (add (unsafe-nth (u8 0) (identifier "repeat_n_756")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_755")))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::t> )> fun2328 { [&fun2328](std::shared_ptr<::dessser::gen::raql_operation::t>  p_0) {
    uint16_t id_2329 { 0 };
    uint16_t id_2330 { uint16_t((*p_0).index()) };
    bool id_2331 { bool(id_2329 == id_2330) };
    Size choose_res_2332;
    if (id_2331) {
      Size id_2333 { 2UL };
      ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2334 { std::get<0 /* Aggregate */>((*p_0)) };
      Lst<dessser::gen::raql_select_field::t_ext> id_2335 { id_2334.Aggregate_fields };
      uint32_t id_2336 { id_2335.size() };
      Vec<1, uint32_t> id_2337 {  id_2336  };
      Size let_res_2338;
      {
        Vec<1, uint32_t> n_ref_766 { id_2337 };
        uint32_t id_2339 { 1U };
        Vec<1, uint32_t> id_2340 {  id_2339  };
        Size let_res_2341;
        {
          Vec<1, uint32_t> lebsz_ref_767 { id_2340 };
          bool while_flag_2342 { true };
          do {
            uint8_t id_2343 { 0 };
            uint32_t id_2344 { n_ref_766[id_2343] };
            uint8_t id_2345 { 0 };
            uint32_t id_2346 { lebsz_ref_767[id_2345] };
            uint8_t id_2347 { 7 };
            uint32_t id_2348 { uint32_t(id_2346 << id_2347) };
            bool id_2349 { bool(id_2344 >= id_2348) };
            while_flag_2342 = id_2349;
            if (while_flag_2342) {
              uint8_t id_2350 { 0 };
              uint8_t id_2351 { 0 };
              uint32_t id_2352 { lebsz_ref_767[id_2351] };
              uint32_t id_2353 { 1U };
              uint32_t id_2354 { uint32_t(id_2352 + id_2353) };
              Void id_2355 { ((void)(lebsz_ref_767[id_2350] = id_2354), ::dessser::VOID) };
              (void)id_2355;
            }
          } while (while_flag_2342);
          (void)::dessser::VOID;
          uint8_t id_2356 { 0 };
          uint32_t id_2357 { lebsz_ref_767[id_2356] };
          Size id_2358 { Size(id_2357) };
          let_res_2341 = id_2358;
        }
        let_res_2338 = let_res_2341;
      }
      Size id_2359 { Size(id_2333 + let_res_2338) };
      Vec<1, Size> id_2360 {  id_2359  };
      Size let_res_2361;
      {
        Vec<1, Size> sz_ref_768 { id_2360 };
        int32_t id_2362 { 0L };
        Vec<1, int32_t> id_2363 {  id_2362  };
        {
          Vec<1, int32_t> repeat_n_769 { id_2363 };
          bool while_flag_2364 { true };
          do {
            ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2365 { std::get<0 /* Aggregate */>((*p_0)) };
            Lst<dessser::gen::raql_select_field::t_ext> id_2366 { id_2365.Aggregate_fields };
            uint32_t id_2367 { id_2366.size() };
            int32_t id_2368 { int32_t(id_2367) };
            uint8_t id_2369 { 0 };
            int32_t id_2370 { repeat_n_769[id_2369] };
            bool id_2371 { bool(id_2368 > id_2370) };
            while_flag_2364 = id_2371;
            if (while_flag_2364) {
              uint8_t id_2372 { 0 };
              uint8_t id_2373 { 0 };
              Size id_2374 { sz_ref_768[id_2373] };
              auto fun2375 { dessser::gen::raql_select_field::sersize_of_row_binary };
              uint8_t id_2376 { 0 };
              int32_t id_2377 { repeat_n_769[id_2376] };
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2378 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_select_field::t_ext> id_2379 { id_2378.Aggregate_fields };
              dessser::gen::raql_select_field::t_ext id_2380 { id_2379[id_2377] };
              Size id_2381 { fun2375(id_2380) };
              Size id_2382 { Size(id_2374 + id_2381) };
              Void id_2383 { ((void)(sz_ref_768[id_2372] = id_2382), ::dessser::VOID) };
              (void)id_2383;
              uint8_t id_2384 { 0 };
              uint8_t id_2385 { 0 };
              int32_t id_2386 { repeat_n_769[id_2385] };
              int32_t id_2387 { 1L };
              int32_t id_2388 { int32_t(id_2386 + id_2387) };
              Void id_2389 { ((void)(repeat_n_769[id_2384] = id_2388), ::dessser::VOID) };
              (void)id_2389;
              (void)id_2389;
            }
          } while (while_flag_2364);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_2390 { 0 };
        Size id_2391 { sz_ref_768[id_2390] };
        let_res_2361 = id_2391;
      }
      Size let_res_2392;
      {
        Size sz_770 { let_res_2361 };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2393 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<Lst<dessser::gen::field_name::t_ext>> id_2394 { id_2393.and_all_others };
        bool id_2395 { !(id_2394.has_value ()) };
        Size choose_res_2396;
        if (id_2395) {
          Size id_2397 { 1UL };
          Size id_2398 { Size(sz_770 + id_2397) };
          choose_res_2396 = id_2398;
        } else {
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2399 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<Lst<dessser::gen::field_name::t_ext>> id_2400 { id_2399.and_all_others };
          Lst<dessser::gen::field_name::t_ext> id_2401 { id_2400.value() };
          uint32_t id_2402 { id_2401.size() };
          Vec<1, uint32_t> id_2403 {  id_2402  };
          Size let_res_2404;
          {
            Vec<1, uint32_t> n_ref_771 { id_2403 };
            uint32_t id_2405 { 1U };
            Vec<1, uint32_t> id_2406 {  id_2405  };
            Size let_res_2407;
            {
              Vec<1, uint32_t> lebsz_ref_772 { id_2406 };
              bool while_flag_2408 { true };
              do {
                uint8_t id_2409 { 0 };
                uint32_t id_2410 { n_ref_771[id_2409] };
                uint8_t id_2411 { 0 };
                uint32_t id_2412 { lebsz_ref_772[id_2411] };
                uint8_t id_2413 { 7 };
                uint32_t id_2414 { uint32_t(id_2412 << id_2413) };
                bool id_2415 { bool(id_2410 >= id_2414) };
                while_flag_2408 = id_2415;
                if (while_flag_2408) {
                  uint8_t id_2416 { 0 };
                  uint8_t id_2417 { 0 };
                  uint32_t id_2418 { lebsz_ref_772[id_2417] };
                  uint32_t id_2419 { 1U };
                  uint32_t id_2420 { uint32_t(id_2418 + id_2419) };
                  Void id_2421 { ((void)(lebsz_ref_772[id_2416] = id_2420), ::dessser::VOID) };
                  (void)id_2421;
                }
              } while (while_flag_2408);
              (void)::dessser::VOID;
              uint8_t id_2422 { 0 };
              uint32_t id_2423 { lebsz_ref_772[id_2422] };
              Size id_2424 { Size(id_2423) };
              let_res_2407 = id_2424;
            }
            let_res_2404 = let_res_2407;
          }
          Size id_2425 { Size(sz_770 + let_res_2404) };
          Vec<1, Size> id_2426 {  id_2425  };
          Size let_res_2427;
          {
            Vec<1, Size> sz_ref_773 { id_2426 };
            int32_t id_2428 { 0L };
            Vec<1, int32_t> id_2429 {  id_2428  };
            {
              Vec<1, int32_t> repeat_n_774 { id_2429 };
              bool while_flag_2430 { true };
              do {
                ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2431 { std::get<0 /* Aggregate */>((*p_0)) };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_2432 { id_2431.and_all_others };
                Lst<dessser::gen::field_name::t_ext> id_2433 { id_2432.value() };
                uint32_t id_2434 { id_2433.size() };
                int32_t id_2435 { int32_t(id_2434) };
                uint8_t id_2436 { 0 };
                int32_t id_2437 { repeat_n_774[id_2436] };
                bool id_2438 { bool(id_2435 > id_2437) };
                while_flag_2430 = id_2438;
                if (while_flag_2430) {
                  uint8_t id_2439 { 0 };
                  uint8_t id_2440 { 0 };
                  Size id_2441 { sz_ref_773[id_2440] };
                  auto fun2442 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_2443 { 0 };
                  int32_t id_2444 { repeat_n_774[id_2443] };
                  ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2445 { std::get<0 /* Aggregate */>((*p_0)) };
                  std::optional<Lst<dessser::gen::field_name::t_ext>> id_2446 { id_2445.and_all_others };
                  Lst<dessser::gen::field_name::t_ext> id_2447 { id_2446.value() };
                  dessser::gen::field_name::t_ext id_2448 { id_2447[id_2444] };
                  Size id_2449 { fun2442(id_2448) };
                  Size id_2450 { Size(id_2441 + id_2449) };
                  Void id_2451 { ((void)(sz_ref_773[id_2439] = id_2450), ::dessser::VOID) };
                  (void)id_2451;
                  uint8_t id_2452 { 0 };
                  uint8_t id_2453 { 0 };
                  int32_t id_2454 { repeat_n_774[id_2453] };
                  int32_t id_2455 { 1L };
                  int32_t id_2456 { int32_t(id_2454 + id_2455) };
                  Void id_2457 { ((void)(repeat_n_774[id_2452] = id_2456), ::dessser::VOID) };
                  (void)id_2457;
                  (void)id_2457;
                }
              } while (while_flag_2430);
              (void)::dessser::VOID;
            }
            (void)::dessser::VOID;
            uint8_t id_2458 { 0 };
            Size id_2459 { sz_ref_773[id_2458] };
            let_res_2427 = id_2459;
          }
          Size id_2460 { 1UL };
          Size id_2461 { Size(let_res_2427 + id_2460) };
          choose_res_2396 = id_2461;
        }
        let_res_2392 = choose_res_2396;
      }
      Size let_res_2462;
      {
        Size sz_775 { let_res_2392 };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2463 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2464 { id_2463.sort };
        bool id_2465 { !(id_2464.has_value ()) };
        Size choose_res_2466;
        if (id_2465) {
          Size id_2467 { 1UL };
          Size id_2468 { Size(sz_775 + id_2467) };
          choose_res_2466 = id_2468;
        } else {
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2469 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2470 { id_2469.sort };
          ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2471 { id_2470.value() };
          std::optional<dessser::gen::raql_expr::t_ext> id_2472 { std::get<1>(id_2471) };
          bool id_2473 { !(id_2472.has_value ()) };
          Size choose_res_2474;
          if (id_2473) {
            Size id_2475 { 4UL };
            Size id_2476 { Size(sz_775 + id_2475) };
            Size id_2477 { 1UL };
            Size id_2478 { Size(id_2476 + id_2477) };
            choose_res_2474 = id_2478;
          } else {
            Size id_2479 { 4UL };
            Size id_2480 { Size(sz_775 + id_2479) };
            auto fun2481 { dessser::gen::raql_expr::sersize_of_row_binary };
            ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2482 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2483 { id_2482.sort };
            ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2484 { id_2483.value() };
            std::optional<dessser::gen::raql_expr::t_ext> id_2485 { std::get<1>(id_2484) };
            dessser::gen::raql_expr::t_ext id_2486 { id_2485.value() };
            Size id_2487 { fun2481(id_2486) };
            Size id_2488 { Size(id_2480 + id_2487) };
            Size id_2489 { 1UL };
            Size id_2490 { Size(id_2488 + id_2489) };
            choose_res_2474 = id_2490;
          }
          Size let_res_2491;
          {
            Size sz_778 { choose_res_2474 };
            ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2492 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2493 { id_2492.sort };
            ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2494 { id_2493.value() };
            Lst<dessser::gen::raql_expr::t_ext> id_2495 { std::get<2>(id_2494) };
            uint32_t id_2496 { id_2495.size() };
            Vec<1, uint32_t> id_2497 {  id_2496  };
            Size let_res_2498;
            {
              Vec<1, uint32_t> n_ref_779 { id_2497 };
              uint32_t id_2499 { 1U };
              Vec<1, uint32_t> id_2500 {  id_2499  };
              Size let_res_2501;
              {
                Vec<1, uint32_t> lebsz_ref_780 { id_2500 };
                bool while_flag_2502 { true };
                do {
                  uint8_t id_2503 { 0 };
                  uint32_t id_2504 { n_ref_779[id_2503] };
                  uint8_t id_2505 { 0 };
                  uint32_t id_2506 { lebsz_ref_780[id_2505] };
                  uint8_t id_2507 { 7 };
                  uint32_t id_2508 { uint32_t(id_2506 << id_2507) };
                  bool id_2509 { bool(id_2504 >= id_2508) };
                  while_flag_2502 = id_2509;
                  if (while_flag_2502) {
                    uint8_t id_2510 { 0 };
                    uint8_t id_2511 { 0 };
                    uint32_t id_2512 { lebsz_ref_780[id_2511] };
                    uint32_t id_2513 { 1U };
                    uint32_t id_2514 { uint32_t(id_2512 + id_2513) };
                    Void id_2515 { ((void)(lebsz_ref_780[id_2510] = id_2514), ::dessser::VOID) };
                    (void)id_2515;
                  }
                } while (while_flag_2502);
                (void)::dessser::VOID;
                uint8_t id_2516 { 0 };
                uint32_t id_2517 { lebsz_ref_780[id_2516] };
                Size id_2518 { Size(id_2517) };
                let_res_2501 = id_2518;
              }
              let_res_2498 = let_res_2501;
            }
            Size id_2519 { Size(sz_778 + let_res_2498) };
            Vec<1, Size> id_2520 {  id_2519  };
            Size let_res_2521;
            {
              Vec<1, Size> sz_ref_781 { id_2520 };
              int32_t id_2522 { 0L };
              Vec<1, int32_t> id_2523 {  id_2522  };
              {
                Vec<1, int32_t> repeat_n_782 { id_2523 };
                bool while_flag_2524 { true };
                do {
                  ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2525 { std::get<0 /* Aggregate */>((*p_0)) };
                  std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2526 { id_2525.sort };
                  ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2527 { id_2526.value() };
                  Lst<dessser::gen::raql_expr::t_ext> id_2528 { std::get<2>(id_2527) };
                  uint32_t id_2529 { id_2528.size() };
                  int32_t id_2530 { int32_t(id_2529) };
                  uint8_t id_2531 { 0 };
                  int32_t id_2532 { repeat_n_782[id_2531] };
                  bool id_2533 { bool(id_2530 > id_2532) };
                  while_flag_2524 = id_2533;
                  if (while_flag_2524) {
                    uint8_t id_2534 { 0 };
                    uint8_t id_2535 { 0 };
                    Size id_2536 { sz_ref_781[id_2535] };
                    auto fun2537 { dessser::gen::raql_expr::sersize_of_row_binary };
                    uint8_t id_2538 { 0 };
                    int32_t id_2539 { repeat_n_782[id_2538] };
                    ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2540 { std::get<0 /* Aggregate */>((*p_0)) };
                    std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_2541 { id_2540.sort };
                    ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_2542 { id_2541.value() };
                    Lst<dessser::gen::raql_expr::t_ext> id_2543 { std::get<2>(id_2542) };
                    dessser::gen::raql_expr::t_ext id_2544 { id_2543[id_2539] };
                    Size id_2545 { fun2537(id_2544) };
                    Size id_2546 { Size(id_2536 + id_2545) };
                    Void id_2547 { ((void)(sz_ref_781[id_2534] = id_2546), ::dessser::VOID) };
                    (void)id_2547;
                    uint8_t id_2548 { 0 };
                    uint8_t id_2549 { 0 };
                    int32_t id_2550 { repeat_n_782[id_2549] };
                    int32_t id_2551 { 1L };
                    int32_t id_2552 { int32_t(id_2550 + id_2551) };
                    Void id_2553 { ((void)(repeat_n_782[id_2548] = id_2552), ::dessser::VOID) };
                    (void)id_2553;
                    (void)id_2553;
                  }
                } while (while_flag_2524);
                (void)::dessser::VOID;
              }
              (void)::dessser::VOID;
              uint8_t id_2554 { 0 };
              Size id_2555 { sz_ref_781[id_2554] };
              let_res_2521 = id_2555;
            }
            let_res_2491 = let_res_2521;
          }
          Size id_2556 { 1UL };
          Size id_2557 { Size(let_res_2491 + id_2556) };
          choose_res_2466 = id_2557;
        }
        let_res_2462 = choose_res_2466;
      }
      Size let_res_2558;
      {
        Size sz_783 { let_res_2462 };
        auto fun2559 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2560 { std::get<0 /* Aggregate */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_2561 { id_2560.where };
        Size id_2562 { fun2559(id_2561) };
        Size id_2563 { Size(sz_783 + id_2562) };
        let_res_2558 = id_2563;
      }
      Size let_res_2564;
      {
        Size sz_784 { let_res_2558 };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2565 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<dessser::gen::event_time::t_ext> id_2566 { id_2565.Aggregate_event_time };
        bool id_2567 { !(id_2566.has_value ()) };
        Size choose_res_2568;
        if (id_2567) {
          Size id_2569 { 1UL };
          Size id_2570 { Size(sz_784 + id_2569) };
          choose_res_2568 = id_2570;
        } else {
          auto fun2571 { dessser::gen::event_time::sersize_of_row_binary };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2572 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::event_time::t_ext> id_2573 { id_2572.Aggregate_event_time };
          dessser::gen::event_time::t_ext id_2574 { id_2573.value() };
          Size id_2575 { fun2571(id_2574) };
          Size id_2576 { Size(sz_784 + id_2575) };
          Size id_2577 { 1UL };
          Size id_2578 { Size(id_2576 + id_2577) };
          choose_res_2568 = id_2578;
        }
        let_res_2564 = choose_res_2568;
      }
      Size let_res_2579;
      {
        Size sz_785 { let_res_2564 };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2580 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::raql_expr::t_ext> id_2581 { id_2580.notifications };
        uint32_t id_2582 { id_2581.size() };
        Vec<1, uint32_t> id_2583 {  id_2582  };
        Size let_res_2584;
        {
          Vec<1, uint32_t> n_ref_786 { id_2583 };
          uint32_t id_2585 { 1U };
          Vec<1, uint32_t> id_2586 {  id_2585  };
          Size let_res_2587;
          {
            Vec<1, uint32_t> lebsz_ref_787 { id_2586 };
            bool while_flag_2588 { true };
            do {
              uint8_t id_2589 { 0 };
              uint32_t id_2590 { n_ref_786[id_2589] };
              uint8_t id_2591 { 0 };
              uint32_t id_2592 { lebsz_ref_787[id_2591] };
              uint8_t id_2593 { 7 };
              uint32_t id_2594 { uint32_t(id_2592 << id_2593) };
              bool id_2595 { bool(id_2590 >= id_2594) };
              while_flag_2588 = id_2595;
              if (while_flag_2588) {
                uint8_t id_2596 { 0 };
                uint8_t id_2597 { 0 };
                uint32_t id_2598 { lebsz_ref_787[id_2597] };
                uint32_t id_2599 { 1U };
                uint32_t id_2600 { uint32_t(id_2598 + id_2599) };
                Void id_2601 { ((void)(lebsz_ref_787[id_2596] = id_2600), ::dessser::VOID) };
                (void)id_2601;
              }
            } while (while_flag_2588);
            (void)::dessser::VOID;
            uint8_t id_2602 { 0 };
            uint32_t id_2603 { lebsz_ref_787[id_2602] };
            Size id_2604 { Size(id_2603) };
            let_res_2587 = id_2604;
          }
          let_res_2584 = let_res_2587;
        }
        Size id_2605 { Size(sz_785 + let_res_2584) };
        Vec<1, Size> id_2606 {  id_2605  };
        Size let_res_2607;
        {
          Vec<1, Size> sz_ref_788 { id_2606 };
          int32_t id_2608 { 0L };
          Vec<1, int32_t> id_2609 {  id_2608  };
          {
            Vec<1, int32_t> repeat_n_789 { id_2609 };
            bool while_flag_2610 { true };
            do {
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2611 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_2612 { id_2611.notifications };
              uint32_t id_2613 { id_2612.size() };
              int32_t id_2614 { int32_t(id_2613) };
              uint8_t id_2615 { 0 };
              int32_t id_2616 { repeat_n_789[id_2615] };
              bool id_2617 { bool(id_2614 > id_2616) };
              while_flag_2610 = id_2617;
              if (while_flag_2610) {
                uint8_t id_2618 { 0 };
                uint8_t id_2619 { 0 };
                Size id_2620 { sz_ref_788[id_2619] };
                auto fun2621 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_2622 { 0 };
                int32_t id_2623 { repeat_n_789[id_2622] };
                ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2624 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<dessser::gen::raql_expr::t_ext> id_2625 { id_2624.notifications };
                dessser::gen::raql_expr::t_ext id_2626 { id_2625[id_2623] };
                Size id_2627 { fun2621(id_2626) };
                Size id_2628 { Size(id_2620 + id_2627) };
                Void id_2629 { ((void)(sz_ref_788[id_2618] = id_2628), ::dessser::VOID) };
                (void)id_2629;
                uint8_t id_2630 { 0 };
                uint8_t id_2631 { 0 };
                int32_t id_2632 { repeat_n_789[id_2631] };
                int32_t id_2633 { 1L };
                int32_t id_2634 { int32_t(id_2632 + id_2633) };
                Void id_2635 { ((void)(repeat_n_789[id_2630] = id_2634), ::dessser::VOID) };
                (void)id_2635;
                (void)id_2635;
              }
            } while (while_flag_2610);
            (void)::dessser::VOID;
          }
          (void)::dessser::VOID;
          uint8_t id_2636 { 0 };
          Size id_2637 { sz_ref_788[id_2636] };
          let_res_2607 = id_2637;
        }
        let_res_2579 = let_res_2607;
      }
      Size let_res_2638;
      {
        Size sz_790 { let_res_2579 };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2639 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::raql_expr::t_ext> id_2640 { id_2639.key };
        uint32_t id_2641 { id_2640.size() };
        Vec<1, uint32_t> id_2642 {  id_2641  };
        Size let_res_2643;
        {
          Vec<1, uint32_t> n_ref_791 { id_2642 };
          uint32_t id_2644 { 1U };
          Vec<1, uint32_t> id_2645 {  id_2644  };
          Size let_res_2646;
          {
            Vec<1, uint32_t> lebsz_ref_792 { id_2645 };
            bool while_flag_2647 { true };
            do {
              uint8_t id_2648 { 0 };
              uint32_t id_2649 { n_ref_791[id_2648] };
              uint8_t id_2650 { 0 };
              uint32_t id_2651 { lebsz_ref_792[id_2650] };
              uint8_t id_2652 { 7 };
              uint32_t id_2653 { uint32_t(id_2651 << id_2652) };
              bool id_2654 { bool(id_2649 >= id_2653) };
              while_flag_2647 = id_2654;
              if (while_flag_2647) {
                uint8_t id_2655 { 0 };
                uint8_t id_2656 { 0 };
                uint32_t id_2657 { lebsz_ref_792[id_2656] };
                uint32_t id_2658 { 1U };
                uint32_t id_2659 { uint32_t(id_2657 + id_2658) };
                Void id_2660 { ((void)(lebsz_ref_792[id_2655] = id_2659), ::dessser::VOID) };
                (void)id_2660;
              }
            } while (while_flag_2647);
            (void)::dessser::VOID;
            uint8_t id_2661 { 0 };
            uint32_t id_2662 { lebsz_ref_792[id_2661] };
            Size id_2663 { Size(id_2662) };
            let_res_2646 = id_2663;
          }
          let_res_2643 = let_res_2646;
        }
        Size id_2664 { Size(sz_790 + let_res_2643) };
        Vec<1, Size> id_2665 {  id_2664  };
        Size let_res_2666;
        {
          Vec<1, Size> sz_ref_793 { id_2665 };
          int32_t id_2667 { 0L };
          Vec<1, int32_t> id_2668 {  id_2667  };
          {
            Vec<1, int32_t> repeat_n_794 { id_2668 };
            bool while_flag_2669 { true };
            do {
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2670 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_2671 { id_2670.key };
              uint32_t id_2672 { id_2671.size() };
              int32_t id_2673 { int32_t(id_2672) };
              uint8_t id_2674 { 0 };
              int32_t id_2675 { repeat_n_794[id_2674] };
              bool id_2676 { bool(id_2673 > id_2675) };
              while_flag_2669 = id_2676;
              if (while_flag_2669) {
                uint8_t id_2677 { 0 };
                uint8_t id_2678 { 0 };
                Size id_2679 { sz_ref_793[id_2678] };
                auto fun2680 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_2681 { 0 };
                int32_t id_2682 { repeat_n_794[id_2681] };
                ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2683 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<dessser::gen::raql_expr::t_ext> id_2684 { id_2683.key };
                dessser::gen::raql_expr::t_ext id_2685 { id_2684[id_2682] };
                Size id_2686 { fun2680(id_2685) };
                Size id_2687 { Size(id_2679 + id_2686) };
                Void id_2688 { ((void)(sz_ref_793[id_2677] = id_2687), ::dessser::VOID) };
                (void)id_2688;
                uint8_t id_2689 { 0 };
                uint8_t id_2690 { 0 };
                int32_t id_2691 { repeat_n_794[id_2690] };
                int32_t id_2692 { 1L };
                int32_t id_2693 { int32_t(id_2691 + id_2692) };
                Void id_2694 { ((void)(repeat_n_794[id_2689] = id_2693), ::dessser::VOID) };
                (void)id_2694;
                (void)id_2694;
              }
            } while (while_flag_2669);
            (void)::dessser::VOID;
          }
          (void)::dessser::VOID;
          uint8_t id_2695 { 0 };
          Size id_2696 { sz_ref_793[id_2695] };
          let_res_2666 = id_2696;
        }
        let_res_2638 = let_res_2666;
      }
      Size let_res_2697;
      {
        Size sz_795 { let_res_2638 };
        auto fun2698 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2699 { std::get<0 /* Aggregate */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_2700 { id_2699.commit_cond };
        Size id_2701 { fun2698(id_2700) };
        Size id_2702 { Size(sz_795 + id_2701) };
        let_res_2697 = id_2702;
      }
      Size id_2703 { 1UL };
      Size id_2704 { Size(let_res_2697 + id_2703) };
      Size let_res_2705;
      {
        Size sz_797 { id_2704 };
        auto fun2706 { dessser::gen::raql_flush_method::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2707 { std::get<0 /* Aggregate */>((*p_0)) };
        dessser::gen::raql_flush_method::t_ext id_2708 { id_2707.flush_how };
        Size id_2709 { fun2706(id_2708) };
        Size id_2710 { Size(sz_797 + id_2709) };
        let_res_2705 = id_2710;
      }
      Size let_res_2711;
      {
        Size sz_798 { let_res_2705 };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2712 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> > id_2713 { id_2712.from };
        uint32_t id_2714 { id_2713.size() };
        Vec<1, uint32_t> id_2715 {  id_2714  };
        Size let_res_2716;
        {
          Vec<1, uint32_t> n_ref_799 { id_2715 };
          uint32_t id_2717 { 1U };
          Vec<1, uint32_t> id_2718 {  id_2717  };
          Size let_res_2719;
          {
            Vec<1, uint32_t> lebsz_ref_800 { id_2718 };
            bool while_flag_2720 { true };
            do {
              uint8_t id_2721 { 0 };
              uint32_t id_2722 { n_ref_799[id_2721] };
              uint8_t id_2723 { 0 };
              uint32_t id_2724 { lebsz_ref_800[id_2723] };
              uint8_t id_2725 { 7 };
              uint32_t id_2726 { uint32_t(id_2724 << id_2725) };
              bool id_2727 { bool(id_2722 >= id_2726) };
              while_flag_2720 = id_2727;
              if (while_flag_2720) {
                uint8_t id_2728 { 0 };
                uint8_t id_2729 { 0 };
                uint32_t id_2730 { lebsz_ref_800[id_2729] };
                uint32_t id_2731 { 1U };
                uint32_t id_2732 { uint32_t(id_2730 + id_2731) };
                Void id_2733 { ((void)(lebsz_ref_800[id_2728] = id_2732), ::dessser::VOID) };
                (void)id_2733;
              }
            } while (while_flag_2720);
            (void)::dessser::VOID;
            uint8_t id_2734 { 0 };
            uint32_t id_2735 { lebsz_ref_800[id_2734] };
            Size id_2736 { Size(id_2735) };
            let_res_2719 = id_2736;
          }
          let_res_2716 = let_res_2719;
        }
        Size id_2737 { Size(sz_798 + let_res_2716) };
        Vec<1, Size> id_2738 {  id_2737  };
        Size let_res_2739;
        {
          Vec<1, Size> sz_ref_801 { id_2738 };
          int32_t id_2740 { 0L };
          Vec<1, int32_t> id_2741 {  id_2740  };
          {
            Vec<1, int32_t> repeat_n_802 { id_2741 };
            bool while_flag_2742 { true };
            do {
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2743 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> > id_2744 { id_2743.from };
              uint32_t id_2745 { id_2744.size() };
              int32_t id_2746 { int32_t(id_2745) };
              uint8_t id_2747 { 0 };
              int32_t id_2748 { repeat_n_802[id_2747] };
              bool id_2749 { bool(id_2746 > id_2748) };
              while_flag_2742 = id_2749;
              if (while_flag_2742) {
                uint8_t id_2750 { 0 };
                uint8_t id_2751 { 0 };
                Size id_2752 { sz_ref_801[id_2751] };
                uint8_t id_2753 { 0 };
                int32_t id_2754 { repeat_n_802[id_2753] };
                ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2755 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> > id_2756 { id_2755.from };
                std::shared_ptr<::dessser::gen::raql_operation::data_source>  id_2757 { id_2756[id_2754] };
                Size id_2758 { data_source_sersize_of_row_binary(id_2757) };
                Size id_2759 { Size(id_2752 + id_2758) };
                Void id_2760 { ((void)(sz_ref_801[id_2750] = id_2759), ::dessser::VOID) };
                (void)id_2760;
                uint8_t id_2761 { 0 };
                uint8_t id_2762 { 0 };
                int32_t id_2763 { repeat_n_802[id_2762] };
                int32_t id_2764 { 1L };
                int32_t id_2765 { int32_t(id_2763 + id_2764) };
                Void id_2766 { ((void)(repeat_n_802[id_2761] = id_2765), ::dessser::VOID) };
                (void)id_2766;
                (void)id_2766;
              }
            } while (while_flag_2742);
            (void)::dessser::VOID;
          }
          (void)::dessser::VOID;
          uint8_t id_2767 { 0 };
          Size id_2768 { sz_ref_801[id_2767] };
          let_res_2739 = id_2768;
        }
        let_res_2711 = let_res_2739;
      }
      Size let_res_2769;
      {
        Size sz_803 { let_res_2711 };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2770 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<dessser::gen::raql_expr::t_ext> id_2771 { id_2770.every };
        bool id_2772 { !(id_2771.has_value ()) };
        Size choose_res_2773;
        if (id_2772) {
          Size id_2774 { 1UL };
          Size id_2775 { Size(sz_803 + id_2774) };
          choose_res_2773 = id_2775;
        } else {
          auto fun2776 { dessser::gen::raql_expr::sersize_of_row_binary };
          ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2777 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_2778 { id_2777.every };
          dessser::gen::raql_expr::t_ext id_2779 { id_2778.value() };
          Size id_2780 { fun2776(id_2779) };
          Size id_2781 { Size(sz_803 + id_2780) };
          Size id_2782 { 1UL };
          Size id_2783 { Size(id_2781 + id_2782) };
          choose_res_2773 = id_2783;
        }
        let_res_2769 = choose_res_2773;
      }
      Size let_res_2784;
      {
        Size sz_804 { let_res_2769 };
        ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2785 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::field_name::t_ext> id_2786 { id_2785.Aggregate_factors };
        uint32_t id_2787 { id_2786.size() };
        Vec<1, uint32_t> id_2788 {  id_2787  };
        Size let_res_2789;
        {
          Vec<1, uint32_t> n_ref_805 { id_2788 };
          uint32_t id_2790 { 1U };
          Vec<1, uint32_t> id_2791 {  id_2790  };
          Size let_res_2792;
          {
            Vec<1, uint32_t> lebsz_ref_806 { id_2791 };
            bool while_flag_2793 { true };
            do {
              uint8_t id_2794 { 0 };
              uint32_t id_2795 { n_ref_805[id_2794] };
              uint8_t id_2796 { 0 };
              uint32_t id_2797 { lebsz_ref_806[id_2796] };
              uint8_t id_2798 { 7 };
              uint32_t id_2799 { uint32_t(id_2797 << id_2798) };
              bool id_2800 { bool(id_2795 >= id_2799) };
              while_flag_2793 = id_2800;
              if (while_flag_2793) {
                uint8_t id_2801 { 0 };
                uint8_t id_2802 { 0 };
                uint32_t id_2803 { lebsz_ref_806[id_2802] };
                uint32_t id_2804 { 1U };
                uint32_t id_2805 { uint32_t(id_2803 + id_2804) };
                Void id_2806 { ((void)(lebsz_ref_806[id_2801] = id_2805), ::dessser::VOID) };
                (void)id_2806;
              }
            } while (while_flag_2793);
            (void)::dessser::VOID;
            uint8_t id_2807 { 0 };
            uint32_t id_2808 { lebsz_ref_806[id_2807] };
            Size id_2809 { Size(id_2808) };
            let_res_2792 = id_2809;
          }
          let_res_2789 = let_res_2792;
        }
        Size id_2810 { Size(sz_804 + let_res_2789) };
        Vec<1, Size> id_2811 {  id_2810  };
        Size let_res_2812;
        {
          Vec<1, Size> sz_ref_807 { id_2811 };
          int32_t id_2813 { 0L };
          Vec<1, int32_t> id_2814 {  id_2813  };
          {
            Vec<1, int32_t> repeat_n_808 { id_2814 };
            bool while_flag_2815 { true };
            do {
              ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2816 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::field_name::t_ext> id_2817 { id_2816.Aggregate_factors };
              uint32_t id_2818 { id_2817.size() };
              int32_t id_2819 { int32_t(id_2818) };
              uint8_t id_2820 { 0 };
              int32_t id_2821 { repeat_n_808[id_2820] };
              bool id_2822 { bool(id_2819 > id_2821) };
              while_flag_2815 = id_2822;
              if (while_flag_2815) {
                uint8_t id_2823 { 0 };
                uint8_t id_2824 { 0 };
                Size id_2825 { sz_ref_807[id_2824] };
                auto fun2826 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_2827 { 0 };
                int32_t id_2828 { repeat_n_808[id_2827] };
                ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_2829 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2830 { id_2829.Aggregate_factors };
                dessser::gen::field_name::t_ext id_2831 { id_2830[id_2828] };
                Size id_2832 { fun2826(id_2831) };
                Size id_2833 { Size(id_2825 + id_2832) };
                Void id_2834 { ((void)(sz_ref_807[id_2823] = id_2833), ::dessser::VOID) };
                (void)id_2834;
                uint8_t id_2835 { 0 };
                uint8_t id_2836 { 0 };
                int32_t id_2837 { repeat_n_808[id_2836] };
                int32_t id_2838 { 1L };
                int32_t id_2839 { int32_t(id_2837 + id_2838) };
                Void id_2840 { ((void)(repeat_n_808[id_2835] = id_2839), ::dessser::VOID) };
                (void)id_2840;
                (void)id_2840;
              }
            } while (while_flag_2815);
            (void)::dessser::VOID;
          }
          (void)::dessser::VOID;
          uint8_t id_2841 { 0 };
          Size id_2842 { sz_ref_807[id_2841] };
          let_res_2812 = id_2842;
        }
        let_res_2784 = let_res_2812;
      }
      choose_res_2332 = let_res_2784;
    } else {
      uint16_t id_2843 { 1 };
      uint16_t id_2844 { uint16_t((*p_0).index()) };
      bool id_2845 { bool(id_2843 == id_2844) };
      Size choose_res_2846;
      if (id_2845) {
        Size id_2847 { 2UL };
        ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2848 { std::get<1 /* ReadExternal */>((*p_0)) };
        std::shared_ptr<::dessser::gen::raql_operation::external_source>  id_2849 { id_2848.source };
        Size id_2850 { external_source_sersize_of_row_binary(id_2849) };
        Size id_2851 { Size(id_2847 + id_2850) };
        Size let_res_2852;
        {
          Size sz_758 { id_2851 };
          ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2853 { std::get<1 /* ReadExternal */>((*p_0)) };
          std::shared_ptr<::dessser::gen::raql_operation::external_format>  id_2854 { id_2853.format };
          Size id_2855 { external_format_sersize_of_row_binary(id_2854) };
          Size id_2856 { Size(sz_758 + id_2855) };
          let_res_2852 = id_2856;
        }
        Size let_res_2857;
        {
          Size sz_759 { let_res_2852 };
          ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2858 { std::get<1 /* ReadExternal */>((*p_0)) };
          std::optional<dessser::gen::event_time::t_ext> id_2859 { id_2858.event_time };
          bool id_2860 { !(id_2859.has_value ()) };
          Size choose_res_2861;
          if (id_2860) {
            Size id_2862 { 1UL };
            Size id_2863 { Size(sz_759 + id_2862) };
            choose_res_2861 = id_2863;
          } else {
            auto fun2864 { dessser::gen::event_time::sersize_of_row_binary };
            ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2865 { std::get<1 /* ReadExternal */>((*p_0)) };
            std::optional<dessser::gen::event_time::t_ext> id_2866 { id_2865.event_time };
            dessser::gen::event_time::t_ext id_2867 { id_2866.value() };
            Size id_2868 { fun2864(id_2867) };
            Size id_2869 { Size(sz_759 + id_2868) };
            Size id_2870 { 1UL };
            Size id_2871 { Size(id_2869 + id_2870) };
            choose_res_2861 = id_2871;
          }
          let_res_2857 = choose_res_2861;
        }
        Size let_res_2872;
        {
          Size sz_760 { let_res_2857 };
          ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2873 { std::get<1 /* ReadExternal */>((*p_0)) };
          Lst<dessser::gen::field_name::t_ext> id_2874 { id_2873.ReadExternal_factors };
          uint32_t id_2875 { id_2874.size() };
          Vec<1, uint32_t> id_2876 {  id_2875  };
          Size let_res_2877;
          {
            Vec<1, uint32_t> n_ref_761 { id_2876 };
            uint32_t id_2878 { 1U };
            Vec<1, uint32_t> id_2879 {  id_2878  };
            Size let_res_2880;
            {
              Vec<1, uint32_t> lebsz_ref_762 { id_2879 };
              bool while_flag_2881 { true };
              do {
                uint8_t id_2882 { 0 };
                uint32_t id_2883 { n_ref_761[id_2882] };
                uint8_t id_2884 { 0 };
                uint32_t id_2885 { lebsz_ref_762[id_2884] };
                uint8_t id_2886 { 7 };
                uint32_t id_2887 { uint32_t(id_2885 << id_2886) };
                bool id_2888 { bool(id_2883 >= id_2887) };
                while_flag_2881 = id_2888;
                if (while_flag_2881) {
                  uint8_t id_2889 { 0 };
                  uint8_t id_2890 { 0 };
                  uint32_t id_2891 { lebsz_ref_762[id_2890] };
                  uint32_t id_2892 { 1U };
                  uint32_t id_2893 { uint32_t(id_2891 + id_2892) };
                  Void id_2894 { ((void)(lebsz_ref_762[id_2889] = id_2893), ::dessser::VOID) };
                  (void)id_2894;
                }
              } while (while_flag_2881);
              (void)::dessser::VOID;
              uint8_t id_2895 { 0 };
              uint32_t id_2896 { lebsz_ref_762[id_2895] };
              Size id_2897 { Size(id_2896) };
              let_res_2880 = id_2897;
            }
            let_res_2877 = let_res_2880;
          }
          Size id_2898 { Size(sz_760 + let_res_2877) };
          Vec<1, Size> id_2899 {  id_2898  };
          Size let_res_2900;
          {
            Vec<1, Size> sz_ref_763 { id_2899 };
            int32_t id_2901 { 0L };
            Vec<1, int32_t> id_2902 {  id_2901  };
            {
              Vec<1, int32_t> repeat_n_764 { id_2902 };
              bool while_flag_2903 { true };
              do {
                ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2904 { std::get<1 /* ReadExternal */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2905 { id_2904.ReadExternal_factors };
                uint32_t id_2906 { id_2905.size() };
                int32_t id_2907 { int32_t(id_2906) };
                uint8_t id_2908 { 0 };
                int32_t id_2909 { repeat_n_764[id_2908] };
                bool id_2910 { bool(id_2907 > id_2909) };
                while_flag_2903 = id_2910;
                if (while_flag_2903) {
                  uint8_t id_2911 { 0 };
                  uint8_t id_2912 { 0 };
                  Size id_2913 { sz_ref_763[id_2912] };
                  auto fun2914 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_2915 { 0 };
                  int32_t id_2916 { repeat_n_764[id_2915] };
                  ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_2917 { std::get<1 /* ReadExternal */>((*p_0)) };
                  Lst<dessser::gen::field_name::t_ext> id_2918 { id_2917.ReadExternal_factors };
                  dessser::gen::field_name::t_ext id_2919 { id_2918[id_2916] };
                  Size id_2920 { fun2914(id_2919) };
                  Size id_2921 { Size(id_2913 + id_2920) };
                  Void id_2922 { ((void)(sz_ref_763[id_2911] = id_2921), ::dessser::VOID) };
                  (void)id_2922;
                  uint8_t id_2923 { 0 };
                  uint8_t id_2924 { 0 };
                  int32_t id_2925 { repeat_n_764[id_2924] };
                  int32_t id_2926 { 1L };
                  int32_t id_2927 { int32_t(id_2925 + id_2926) };
                  Void id_2928 { ((void)(repeat_n_764[id_2923] = id_2927), ::dessser::VOID) };
                  (void)id_2928;
                  (void)id_2928;
                }
              } while (while_flag_2903);
              (void)::dessser::VOID;
            }
            (void)::dessser::VOID;
            uint8_t id_2929 { 0 };
            Size id_2930 { sz_ref_763[id_2929] };
            let_res_2900 = id_2930;
          }
          let_res_2872 = let_res_2900;
        }
        choose_res_2846 = let_res_2872;
      } else {
        uint16_t id_2931 { uint16_t((*p_0).index()) };
        uint16_t id_2932 { 2 };
        bool id_2933 { bool(id_2931 == id_2932) };
        Void id_2934 { ((void)(assert(id_2933)), ::dessser::VOID) };
        (void)id_2934;
        Size id_2935 { 2UL };
        ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2936 { std::get<2 /* ListenFor */>((*p_0)) };
        std::string id_2937 { id_2936.net_addr };
        uint32_t id_2938 { (uint32_t)id_2937.size() };
        Vec<1, uint32_t> id_2939 {  id_2938  };
        Size let_res_2940;
        {
          Vec<1, uint32_t> n_ref_748 { id_2939 };
          uint32_t id_2941 { 1U };
          Vec<1, uint32_t> id_2942 {  id_2941  };
          Size let_res_2943;
          {
            Vec<1, uint32_t> lebsz_ref_749 { id_2942 };
            bool while_flag_2944 { true };
            do {
              uint8_t id_2945 { 0 };
              uint32_t id_2946 { n_ref_748[id_2945] };
              uint8_t id_2947 { 0 };
              uint32_t id_2948 { lebsz_ref_749[id_2947] };
              uint8_t id_2949 { 7 };
              uint32_t id_2950 { uint32_t(id_2948 << id_2949) };
              bool id_2951 { bool(id_2946 >= id_2950) };
              while_flag_2944 = id_2951;
              if (while_flag_2944) {
                uint8_t id_2952 { 0 };
                uint8_t id_2953 { 0 };
                uint32_t id_2954 { lebsz_ref_749[id_2953] };
                uint32_t id_2955 { 1U };
                uint32_t id_2956 { uint32_t(id_2954 + id_2955) };
                Void id_2957 { ((void)(lebsz_ref_749[id_2952] = id_2956), ::dessser::VOID) };
                (void)id_2957;
              }
            } while (while_flag_2944);
            (void)::dessser::VOID;
            uint8_t id_2958 { 0 };
            uint32_t id_2959 { lebsz_ref_749[id_2958] };
            Size id_2960 { Size(id_2959) };
            let_res_2943 = id_2960;
          }
          let_res_2940 = let_res_2943;
        }
        ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2961 { std::get<2 /* ListenFor */>((*p_0)) };
        std::string id_2962 { id_2961.net_addr };
        uint32_t id_2963 { (uint32_t)id_2962.size() };
        Size id_2964 { Size(id_2963) };
        Size id_2965 { Size(let_res_2940 + id_2964) };
        Size id_2966 { Size(id_2935 + id_2965) };
        Size id_2967 { 2UL };
        Size id_2968 { Size(id_2966 + id_2967) };
        Size let_res_2969;
        {
          Size sz_751 { id_2968 };
          auto fun2970 { dessser::gen::raql_net_protocol::sersize_of_row_binary };
          ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2971 { std::get<2 /* ListenFor */>((*p_0)) };
          dessser::gen::raql_net_protocol::t_ext id_2972 { id_2971.proto };
          Size id_2973 { fun2970(id_2972) };
          Size id_2974 { Size(sz_751 + id_2973) };
          let_res_2969 = id_2974;
        }
        Size let_res_2975;
        {
          Size sz_752 { let_res_2969 };
          ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_2976 { std::get<2 /* ListenFor */>((*p_0)) };
          Lst<dessser::gen::field_name::t_ext> id_2977 { id_2976.factors };
          uint32_t id_2978 { id_2977.size() };
          Vec<1, uint32_t> id_2979 {  id_2978  };
          Size let_res_2980;
          {
            Vec<1, uint32_t> n_ref_753 { id_2979 };
            uint32_t id_2981 { 1U };
            Vec<1, uint32_t> id_2982 {  id_2981  };
            Size let_res_2983;
            {
              Vec<1, uint32_t> lebsz_ref_754 { id_2982 };
              bool while_flag_2984 { true };
              do {
                uint8_t id_2985 { 0 };
                uint32_t id_2986 { n_ref_753[id_2985] };
                uint8_t id_2987 { 0 };
                uint32_t id_2988 { lebsz_ref_754[id_2987] };
                uint8_t id_2989 { 7 };
                uint32_t id_2990 { uint32_t(id_2988 << id_2989) };
                bool id_2991 { bool(id_2986 >= id_2990) };
                while_flag_2984 = id_2991;
                if (while_flag_2984) {
                  uint8_t id_2992 { 0 };
                  uint8_t id_2993 { 0 };
                  uint32_t id_2994 { lebsz_ref_754[id_2993] };
                  uint32_t id_2995 { 1U };
                  uint32_t id_2996 { uint32_t(id_2994 + id_2995) };
                  Void id_2997 { ((void)(lebsz_ref_754[id_2992] = id_2996), ::dessser::VOID) };
                  (void)id_2997;
                }
              } while (while_flag_2984);
              (void)::dessser::VOID;
              uint8_t id_2998 { 0 };
              uint32_t id_2999 { lebsz_ref_754[id_2998] };
              Size id_3000 { Size(id_2999) };
              let_res_2983 = id_3000;
            }
            let_res_2980 = let_res_2983;
          }
          Size id_3001 { Size(sz_752 + let_res_2980) };
          Vec<1, Size> id_3002 {  id_3001  };
          Size let_res_3003;
          {
            Vec<1, Size> sz_ref_755 { id_3002 };
            int32_t id_3004 { 0L };
            Vec<1, int32_t> id_3005 {  id_3004  };
            {
              Vec<1, int32_t> repeat_n_756 { id_3005 };
              bool while_flag_3006 { true };
              do {
                ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_3007 { std::get<2 /* ListenFor */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_3008 { id_3007.factors };
                uint32_t id_3009 { id_3008.size() };
                int32_t id_3010 { int32_t(id_3009) };
                uint8_t id_3011 { 0 };
                int32_t id_3012 { repeat_n_756[id_3011] };
                bool id_3013 { bool(id_3010 > id_3012) };
                while_flag_3006 = id_3013;
                if (while_flag_3006) {
                  uint8_t id_3014 { 0 };
                  uint8_t id_3015 { 0 };
                  Size id_3016 { sz_ref_755[id_3015] };
                  auto fun3017 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_3018 { 0 };
                  int32_t id_3019 { repeat_n_756[id_3018] };
                  ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_3020 { std::get<2 /* ListenFor */>((*p_0)) };
                  Lst<dessser::gen::field_name::t_ext> id_3021 { id_3020.factors };
                  dessser::gen::field_name::t_ext id_3022 { id_3021[id_3019] };
                  Size id_3023 { fun3017(id_3022) };
                  Size id_3024 { Size(id_3016 + id_3023) };
                  Void id_3025 { ((void)(sz_ref_755[id_3014] = id_3024), ::dessser::VOID) };
                  (void)id_3025;
                  uint8_t id_3026 { 0 };
                  uint8_t id_3027 { 0 };
                  int32_t id_3028 { repeat_n_756[id_3027] };
                  int32_t id_3029 { 1L };
                  int32_t id_3030 { int32_t(id_3028 + id_3029) };
                  Void id_3031 { ((void)(repeat_n_756[id_3026] = id_3030), ::dessser::VOID) };
                  (void)id_3031;
                  (void)id_3031;
                }
              } while (while_flag_3006);
              (void)::dessser::VOID;
            }
            (void)::dessser::VOID;
            uint8_t id_3032 { 0 };
            Size id_3033 { sz_ref_755[id_3032] };
            let_res_3003 = id_3033;
          }
          let_res_2975 = let_res_3003;
        }
        choose_res_2846 = let_res_2975;
      }
      choose_res_2332 = choose_res_2846;
    }
    return choose_res_2332;
  }
   };
  return fun2328;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_690" "make_snd_691" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_690") (identifier "make_snd_691"))))
 */
static std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> fun3034 { [&fun3034](Pointer p_0) {
    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3035 { of_row_binary(p_0) };
    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3036;
    {
      auto make_fst_690 { std::get<0>(id_3035) };
      auto make_snd_691 { std::get<1>(id_3035) };
      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3037 { make_fst_690, make_snd_691 };
      letpair_res_3036 = id_3037;
    }
    return letpair_res_3036;
  }
   };
  return fun3034;
}
std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
          (if (eq (u16 0) (identifier "dsum1_fst_63"))
            (let "dtup_98"
              (let "dsum1_74" (let-pair "du16_fst_69" "du16_snd_70" (read-u16 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du16_fst_69") (identifier "du16_snd_70")))
                (let-pair "dsum1_fst_75" "dsum1_snd_76" (identifier "dsum1_74")
                  (if (eq (u16 0) (identifier "dsum1_fst_75")) (make-tup (construct "[AllSites Void | TheseSites STRING | ThisSite Void]" 0 (nop)) (identifier "dsum1_snd_76"))
                    (if (eq (u16 1) (identifier "dsum1_fst_75"))
                      (let "dstring1_86"
                        (let "leb_ref_80" (make-vec (u32 0))
                          (let "shft_ref_81" (make-vec (u8 0))
                            (let "p_ref_82" (make-vec (identifier "dsum1_snd_76"))
                              (seq
                                (while
                                  (let "leb128_83" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_82")))
                                    (let-pair "leb128_fst_84" "leb128_snd_85" 
                                      (identifier "leb128_83")
                                      (seq (set-vec (u8 0) (identifier "p_ref_82") (identifier "leb128_snd_85"))
                                        (set-vec (u8 0) (identifier "leb_ref_80")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_84") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_81"))) (unsafe-nth (u8 0) (identifier "leb_ref_80"))))
                                        (set-vec (u8 0) (identifier "shft_ref_81") (add (unsafe-nth (u8 0) (identifier "shft_ref_81")) (u8 7))) 
                                        (ge (identifier "leb128_fst_84") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_80"))) (unsafe-nth (u8 0) (identifier "p_ref_82")))))))
                        (let-pair "dstring1_fst_87" "dstring1_snd_88" 
                          (identifier "dstring1_86")
                          (let-pair "dstring2_fst_90" "dstring2_snd_91" 
                            (read-bytes (identifier "dstring1_snd_88") (identifier "dstring1_fst_87"))
                            (make-tup (construct "[AllSites Void | TheseSites STRING | ThisSite Void]" 1 (string-of-bytes (identifier "dstring2_fst_90"))) (identifier "dstring2_snd_91")))))
                      (seq (assert (eq (identifier "dsum1_fst_75") (u16 2))) (make-tup (construct "[AllSites Void | TheseSites STRING | ThisSite Void]" 2 (nop)) (identifier "dsum1_snd_76")))))))
              (let-pair "dtup_fst_99" "dtup_snd_100" (identifier "dtup_98")
                (let "dtup_116"
                  (if (eq (peek-u8 (identifier "dtup_snd_100") (size 0)) (u8 1)) 
                    (make-tup (null "STRING") (ptr-add (identifier "dtup_snd_100") (size 1)))
                    (let "dstring1_107"
                      (let "leb_ref_101" (make-vec (u32 0))
                        (let "shft_ref_102" (make-vec (u8 0))
                          (let "p_ref_103" (make-vec (ptr-add (identifier "dtup_snd_100") (size 1)))
                            (seq
                              (while
                                (let "leb128_104" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_103")))
                                  (let-pair "leb128_fst_105" "leb128_snd_106" 
                                    (identifier "leb128_104")
                                    (seq (set-vec (u8 0) (identifier "p_ref_103") (identifier "leb128_snd_106"))
                                      (set-vec (u8 0) (identifier "leb_ref_101")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_105") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_102"))) (unsafe-nth (u8 0) (identifier "leb_ref_101"))))
                                      (set-vec (u8 0) (identifier "shft_ref_102") (add (unsafe-nth (u8 0) (identifier "shft_ref_102")) (u8 7))) 
                                      (ge (identifier "leb128_fst_105") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_101"))) (unsafe-nth (u8 0) (identifier "p_ref_103")))))))
                      (let-pair "dstring1_fst_108" "dstring1_snd_109" 
                        (identifier "dstring1_107")
                        (let-pair "dstring2_fst_111" "dstring2_snd_112" 
                          (read-bytes (identifier "dstring1_snd_109") (identifier "dstring1_fst_108")) 
                          (make-tup (not-null (string-of-bytes (identifier "dstring2_fst_111"))) (identifier "dstring2_snd_112"))))))
                  (let-pair "dtup_fst_117" "dtup_snd_118" (identifier "dtup_116")
                    (let-pair "dtup_fst_120" "dtup_snd_121" (apply (ext-identifier function_name of-row-binary) (identifier "dtup_snd_118"))
                      (make-tup
                        (construct "[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" 0
                          (make-tup (identifier "dtup_fst_99") (identifier "dtup_fst_117") (identifier "dtup_fst_120"))) 
                        (identifier "dtup_snd_121")))))))
            (seq (assert (eq (identifier "dsum1_fst_63") (u16 1)))
              (let-pair "dsum2_fst_66" "dsum2_snd_67" (apply (identifier "of-row-binary") (identifier "dsum1_snd_64"))
                (make-tup (construct "[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" 1 (identifier "dsum2_fst_66")) (identifier "dsum2_snd_67"))))))))
 */
static std::function<::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681(Pointer)> data_source_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681(Pointer)> fun3038 { [&fun3038](Pointer p_0) {
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3039 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_3040;
    {
      auto du16_fst_57 { std::get<0>(id_3039) };
      auto du16_snd_58 { std::get<1>(id_3039) };
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3041 { du16_fst_57, du16_snd_58 };
      letpair_res_3040 = id_3041;
    }
    ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 let_res_3042;
    {
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_62 { letpair_res_3040 };
      ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 letpair_res_3043;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_3044 { 0 };
        bool id_3045 { bool(id_3044 == dsum1_fst_63) };
        ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 choose_res_3046;
        if (id_3045) {
          ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3047 { dsum1_snd_64.readU16Le() };
          ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_3048;
          {
            auto du16_fst_69 { std::get<0>(id_3047) };
            auto du16_snd_70 { std::get<1>(id_3047) };
            ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3049 { du16_fst_69, du16_snd_70 };
            letpair_res_3048 = id_3049;
          }
          ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd let_res_3050;
          {
            ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_74 { letpair_res_3048 };
            ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd letpair_res_3051;
            {
              auto dsum1_fst_75 { std::get<0>(dsum1_74) };
              auto dsum1_snd_76 { std::get<1>(dsum1_74) };
              uint16_t id_3052 { 0 };
              bool id_3053 { bool(id_3052 == dsum1_fst_75) };
              ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd choose_res_3054;
              if (id_3053) {
                (void)::dessser::VOID;
                ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_3055 { std::in_place_index<0>, ::dessser::VOID };
                ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd id_3056 { id_3055, dsum1_snd_76 };
                choose_res_3054 = id_3056;
              } else {
                uint16_t id_3057 { 1 };
                bool id_3058 { bool(id_3057 == dsum1_fst_75) };
                ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd choose_res_3059;
                if (id_3058) {
                  uint32_t id_3060 { 0U };
                  Vec<1, uint32_t> id_3061 {  id_3060  };
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3062;
                  {
                    Vec<1, uint32_t> leb_ref_80 { id_3061 };
                    uint8_t id_3063 { 0 };
                    Vec<1, uint8_t> id_3064 {  id_3063  };
                    ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3065;
                    {
                      Vec<1, uint8_t> shft_ref_81 { id_3064 };
                      Vec<1, Pointer> id_3066 {  dsum1_snd_76  };
                      ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3067;
                      {
                        Vec<1, Pointer> p_ref_82 { id_3066 };
                        bool while_flag_3068 { true };
                        do {
                          uint8_t id_3069 { 0 };
                          Pointer id_3070 { p_ref_82[id_3069] };
                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3071 { id_3070.readU8() };
                          bool let_res_3072;
                          {
                            ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_83 { id_3071 };
                            bool letpair_res_3073;
                            {
                              auto leb128_fst_84 { std::get<0>(leb128_83) };
                              auto leb128_snd_85 { std::get<1>(leb128_83) };
                              uint8_t id_3074 { 0 };
                              Void id_3075 { ((void)(p_ref_82[id_3074] = leb128_snd_85), ::dessser::VOID) };
                              (void)id_3075;
                              uint8_t id_3076 { 0 };
                              uint8_t id_3077 { 127 };
                              uint8_t id_3078 { uint8_t(leb128_fst_84 & id_3077) };
                              uint32_t id_3079 { uint32_t(id_3078) };
                              uint8_t id_3080 { 0 };
                              uint8_t id_3081 { shft_ref_81[id_3080] };
                              uint32_t id_3082 { uint32_t(id_3079 << id_3081) };
                              uint8_t id_3083 { 0 };
                              uint32_t id_3084 { leb_ref_80[id_3083] };
                              uint32_t id_3085 { uint32_t(id_3082 | id_3084) };
                              Void id_3086 { ((void)(leb_ref_80[id_3076] = id_3085), ::dessser::VOID) };
                              (void)id_3086;
                              uint8_t id_3087 { 0 };
                              uint8_t id_3088 { 0 };
                              uint8_t id_3089 { shft_ref_81[id_3088] };
                              uint8_t id_3090 { 7 };
                              uint8_t id_3091 { uint8_t(id_3089 + id_3090) };
                              Void id_3092 { ((void)(shft_ref_81[id_3087] = id_3091), ::dessser::VOID) };
                              (void)id_3092;
                              uint8_t id_3093 { 128 };
                              bool id_3094 { bool(leb128_fst_84 >= id_3093) };
                              letpair_res_3073 = id_3094;
                            }
                            let_res_3072 = letpair_res_3073;
                          }
                          while_flag_3068 = let_res_3072;
                          if (while_flag_3068) {
                            (void)::dessser::VOID;
                          }
                        } while (while_flag_3068);
                        (void)::dessser::VOID;
                        uint8_t id_3095 { 0 };
                        uint32_t id_3096 { leb_ref_80[id_3095] };
                        Size id_3097 { Size(id_3096) };
                        uint8_t id_3098 { 0 };
                        Pointer id_3099 { p_ref_82[id_3098] };
                        ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_3100 { id_3097, id_3099 };
                        let_res_3067 = id_3100;
                      }
                      let_res_3065 = let_res_3067;
                    }
                    let_res_3062 = let_res_3065;
                  }
                  ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd let_res_3101;
                  {
                    ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_86 { let_res_3062 };
                    ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd letpair_res_3102;
                    {
                      auto dstring1_fst_87 { std::get<0>(dstring1_86) };
                      auto dstring1_snd_88 { std::get<1>(dstring1_86) };
                      ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_3103 { dstring1_snd_88.readBytes(dstring1_fst_87) };
                      ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd letpair_res_3104;
                      {
                        auto dstring2_fst_90 { std::get<0>(id_3103) };
                        auto dstring2_snd_91 { std::get<1>(id_3103) };
                        std::string id_3105 { dstring2_fst_90.toString() };
                        ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_3106 { std::in_place_index<1>, id_3105 };
                        ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd id_3107 { id_3106, dstring2_snd_91 };
                        letpair_res_3104 = id_3107;
                      }
                      letpair_res_3102 = letpair_res_3104;
                    }
                    let_res_3101 = letpair_res_3102;
                  }
                  choose_res_3059 = let_res_3101;
                } else {
                  uint16_t id_3108 { 2 };
                  bool id_3109 { bool(dsum1_fst_75 == id_3108) };
                  Void id_3110 { ((void)(assert(id_3109)), ::dessser::VOID) };
                  (void)id_3110;
                  (void)::dessser::VOID;
                  ::dessser::gen::raql_operation::t054d75b46129860c650f4e7e4e60a6f9 id_3111 { std::in_place_index<2>, ::dessser::VOID };
                  ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd id_3112 { id_3111, dsum1_snd_76 };
                  choose_res_3059 = id_3112;
                }
                choose_res_3054 = choose_res_3059;
              }
              letpair_res_3051 = choose_res_3054;
            }
            let_res_3050 = letpair_res_3051;
          }
          ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 let_res_3113;
          {
            ::dessser::gen::raql_operation::tedbc0e6cf6279cdd2eff41d7793af3bd dtup_98 { let_res_3050 };
            ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 letpair_res_3114;
            {
              auto dtup_fst_99 { std::get<0>(dtup_98) };
              auto dtup_snd_100 { std::get<1>(dtup_98) };
              Size id_3115 { 0UL };
              uint8_t id_3116 { dtup_snd_100.peekU8(id_3115) };
              uint8_t id_3117 { 1 };
              bool id_3118 { bool(id_3116 == id_3117) };
              ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 choose_res_3119;
              if (id_3118) {
                std::optional<std::string> id_3120 { std::nullopt };
                Size id_3121 { 1UL };
                Pointer id_3122 { dtup_snd_100.skip(id_3121) };
                ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 id_3123 { id_3120, id_3122 };
                choose_res_3119 = id_3123;
              } else {
                uint32_t id_3124 { 0U };
                Vec<1, uint32_t> id_3125 {  id_3124  };
                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3126;
                {
                  Vec<1, uint32_t> leb_ref_101 { id_3125 };
                  uint8_t id_3127 { 0 };
                  Vec<1, uint8_t> id_3128 {  id_3127  };
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3129;
                  {
                    Vec<1, uint8_t> shft_ref_102 { id_3128 };
                    Size id_3130 { 1UL };
                    Pointer id_3131 { dtup_snd_100.skip(id_3130) };
                    Vec<1, Pointer> id_3132 {  id_3131  };
                    ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3133;
                    {
                      Vec<1, Pointer> p_ref_103 { id_3132 };
                      bool while_flag_3134 { true };
                      do {
                        uint8_t id_3135 { 0 };
                        Pointer id_3136 { p_ref_103[id_3135] };
                        ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3137 { id_3136.readU8() };
                        bool let_res_3138;
                        {
                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_104 { id_3137 };
                          bool letpair_res_3139;
                          {
                            auto leb128_fst_105 { std::get<0>(leb128_104) };
                            auto leb128_snd_106 { std::get<1>(leb128_104) };
                            uint8_t id_3140 { 0 };
                            Void id_3141 { ((void)(p_ref_103[id_3140] = leb128_snd_106), ::dessser::VOID) };
                            (void)id_3141;
                            uint8_t id_3142 { 0 };
                            uint8_t id_3143 { 127 };
                            uint8_t id_3144 { uint8_t(leb128_fst_105 & id_3143) };
                            uint32_t id_3145 { uint32_t(id_3144) };
                            uint8_t id_3146 { 0 };
                            uint8_t id_3147 { shft_ref_102[id_3146] };
                            uint32_t id_3148 { uint32_t(id_3145 << id_3147) };
                            uint8_t id_3149 { 0 };
                            uint32_t id_3150 { leb_ref_101[id_3149] };
                            uint32_t id_3151 { uint32_t(id_3148 | id_3150) };
                            Void id_3152 { ((void)(leb_ref_101[id_3142] = id_3151), ::dessser::VOID) };
                            (void)id_3152;
                            uint8_t id_3153 { 0 };
                            uint8_t id_3154 { 0 };
                            uint8_t id_3155 { shft_ref_102[id_3154] };
                            uint8_t id_3156 { 7 };
                            uint8_t id_3157 { uint8_t(id_3155 + id_3156) };
                            Void id_3158 { ((void)(shft_ref_102[id_3153] = id_3157), ::dessser::VOID) };
                            (void)id_3158;
                            uint8_t id_3159 { 128 };
                            bool id_3160 { bool(leb128_fst_105 >= id_3159) };
                            letpair_res_3139 = id_3160;
                          }
                          let_res_3138 = letpair_res_3139;
                        }
                        while_flag_3134 = let_res_3138;
                        if (while_flag_3134) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_3134);
                      (void)::dessser::VOID;
                      uint8_t id_3161 { 0 };
                      uint32_t id_3162 { leb_ref_101[id_3161] };
                      Size id_3163 { Size(id_3162) };
                      uint8_t id_3164 { 0 };
                      Pointer id_3165 { p_ref_103[id_3164] };
                      ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_3166 { id_3163, id_3165 };
                      let_res_3133 = id_3166;
                    }
                    let_res_3129 = let_res_3133;
                  }
                  let_res_3126 = let_res_3129;
                }
                ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 let_res_3167;
                {
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_107 { let_res_3126 };
                  ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_3168;
                  {
                    auto dstring1_fst_108 { std::get<0>(dstring1_107) };
                    auto dstring1_snd_109 { std::get<1>(dstring1_107) };
                    ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_3169 { dstring1_snd_109.readBytes(dstring1_fst_108) };
                    ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_3170;
                    {
                      auto dstring2_fst_111 { std::get<0>(id_3169) };
                      auto dstring2_snd_112 { std::get<1>(id_3169) };
                      std::string id_3171 { dstring2_fst_111.toString() };
                      std::optional<std::string> id_3172 { id_3171 };
                      ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 id_3173 { id_3172, dstring2_snd_112 };
                      letpair_res_3170 = id_3173;
                    }
                    letpair_res_3168 = letpair_res_3170;
                  }
                  let_res_3167 = letpair_res_3168;
                }
                choose_res_3119 = let_res_3167;
              }
              ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 let_res_3174;
              {
                ::dessser::gen::raql_operation::ta18b971ad5bf537b68fb1bbf5fd2b926 dtup_116 { choose_res_3119 };
                ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 letpair_res_3175;
                {
                  auto dtup_fst_117 { std::get<0>(dtup_116) };
                  auto dtup_snd_118 { std::get<1>(dtup_116) };
                  auto fun3176 { dessser::gen::function_name::of_row_binary };
                  ::dessser::gen::raql_operation::t7ced0f6935c1265b26e1abfcc364f52e id_3177 { fun3176(dtup_snd_118) };
                  ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 letpair_res_3178;
                  {
                    auto dtup_fst_120 { std::get<0>(id_3177) };
                    auto dtup_snd_121 { std::get<1>(id_3177) };
                    ::dessser::gen::raql_operation::ted682f302d97794f7d8af77b7693b421 id_3179 { dtup_fst_99, dtup_fst_117, dtup_fst_120 };
                    std::shared_ptr<::dessser::gen::raql_operation::data_source>  id_3180 { std::make_shared<::dessser::gen::raql_operation::data_source>(std::in_place_index<0>, id_3179) };
                    ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 id_3181 { id_3180, dtup_snd_121 };
                    letpair_res_3178 = id_3181;
                  }
                  letpair_res_3175 = letpair_res_3178;
                }
                let_res_3174 = letpair_res_3175;
              }
              letpair_res_3114 = let_res_3174;
            }
            let_res_3113 = letpair_res_3114;
          }
          choose_res_3046 = let_res_3113;
        } else {
          uint16_t id_3182 { 1 };
          bool id_3183 { bool(dsum1_fst_63 == id_3182) };
          Void id_3184 { ((void)(assert(id_3183)), ::dessser::VOID) };
          (void)id_3184;
          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3185 { of_row_binary(dsum1_snd_64) };
          ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 letpair_res_3186;
          {
            auto dsum2_fst_66 { std::get<0>(id_3185) };
            auto dsum2_snd_67 { std::get<1>(id_3185) };
            std::shared_ptr<::dessser::gen::raql_operation::data_source>  id_3187 { std::make_shared<::dessser::gen::raql_operation::data_source>(std::in_place_index<1>, dsum2_fst_66) };
            ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 id_3188 { id_3187, dsum2_snd_67 };
            letpair_res_3186 = id_3188;
          }
          choose_res_3046 = letpair_res_3186;
        }
        letpair_res_3043 = choose_res_3046;
      }
      let_res_3042 = letpair_res_3043;
    }
    return let_res_3042;
  }
   };
  return fun3038;
}
std::function<::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681(Pointer)> data_source_of_row_binary(data_source_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_359" (let-pair "du16_fst_354" "du16_snd_355" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_354") (identifier "du16_snd_355")))
        (let-pair "dsum1_fst_360" "dsum1_snd_361" (identifier "dsum1_359")
          (if (eq (u16 0) (identifier "dsum1_fst_360"))
            (let "drec_479"
              (let-pair "dlist4_fst_477" "dlist4_snd_478"
                (let "dlist1_465"
                  (let "leb_ref_456" (make-vec (u32 0))
                    (let "shft_ref_457" (make-vec (u8 0))
                      (let "p_ref_458" (make-vec (identifier "dsum1_snd_361"))
                        (seq
                          (while
                            (let "leb128_459" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_458")))
                              (let-pair "leb128_fst_460" "leb128_snd_461" 
                                (identifier "leb128_459")
                                (seq (set-vec (u8 0) (identifier "p_ref_458") (identifier "leb128_snd_461"))
                                  (set-vec (u8 0) (identifier "leb_ref_456")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_460") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_457"))) (unsafe-nth (u8 0) (identifier "leb_ref_456"))))
                                  (set-vec (u8 0) (identifier "shft_ref_457") (add (unsafe-nth (u8 0) (identifier "shft_ref_457")) (u8 7))) 
                                  (ge (identifier "leb128_fst_460") (u8 128))))) 
                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_456")) (unsafe-nth (u8 0) (identifier "p_ref_458")))))))
                  (let-pair "dlist1_fst_466" "dlist1_snd_467" (identifier "dlist1_465")
                    (let "inits_src_ref_468" (make-vec (make-tup (end-of-list "$raql_select_field") (identifier "dlist1_snd_467")))
                      (seq
                        (let "repeat_n_469" (make-vec (i32 0))
                          (while (gt (to-i32 (identifier "dlist1_fst_466")) (unsafe-nth (u8 0) (identifier "repeat_n_469")))
                            (seq
                              (let "dlist2_470" (unsafe-nth (u8 0) (identifier "inits_src_ref_468"))
                                (let-pair "dlist2_fst_471" "dlist2_snd_472" 
                                  (identifier "dlist2_470")
                                  (set-vec (u8 0) (identifier "inits_src_ref_468")
                                    (let-pair "dlist3_fst_474" "dlist3_snd_475" 
                                      (apply (ext-identifier raql_select_field of-row-binary) (identifier "dlist2_snd_472"))
                                      (make-tup (cons (identifier "dlist3_fst_474") (identifier "dlist2_fst_471")) (identifier "dlist3_snd_475"))))))
                              (set-vec (u8 0) (identifier "repeat_n_469") (add (unsafe-nth (u8 0) (identifier "repeat_n_469")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "inits_src_ref_468")))))) 
                (make-tup (identity (identifier "dlist4_fst_477")) (identifier "dlist4_snd_478")))
              (let-pair "drec_fst_480" "drec_snd_481" (identifier "drec_479")
                (let "drec_508"
                  (if (eq (peek-u8 (identifier "drec_snd_481") (size 0)) (u8 1)) 
                    (make-tup (null "$field_name[[]]") (ptr-add (identifier "drec_snd_481") (size 1)))
                    (let-pair "dlist4_fst_503" "dlist4_snd_504"
                      (let "dlist1_491"
                        (let "leb_ref_482" (make-vec (u32 0))
                          (let "shft_ref_483" (make-vec (u8 0))
                            (let "p_ref_484" (make-vec (ptr-add (identifier "drec_snd_481") (size 1)))
                              (seq
                                (while
                                  (let "leb128_485" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_484")))
                                    (let-pair "leb128_fst_486" "leb128_snd_487" 
                                      (identifier "leb128_485")
                                      (seq (set-vec (u8 0) (identifier "p_ref_484") (identifier "leb128_snd_487"))
                                        (set-vec (u8 0) (identifier "leb_ref_482")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_486") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_483"))) (unsafe-nth (u8 0) (identifier "leb_ref_482"))))
                                        (set-vec (u8 0) (identifier "shft_ref_483") (add (unsafe-nth (u8 0) (identifier "shft_ref_483")) (u8 7))) 
                                        (ge (identifier "leb128_fst_486") (u8 128))))) 
                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_482")) (unsafe-nth (u8 0) (identifier "p_ref_484")))))))
                        (let-pair "dlist1_fst_492" "dlist1_snd_493" (identifier "dlist1_491")
                          (let "inits_src_ref_494" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_493")))
                            (seq
                              (let "repeat_n_495" (make-vec (i32 0))
                                (while (gt (to-i32 (identifier "dlist1_fst_492")) (unsafe-nth (u8 0) (identifier "repeat_n_495")))
                                  (seq
                                    (let "dlist2_496" (unsafe-nth (u8 0) (identifier "inits_src_ref_494"))
                                      (let-pair "dlist2_fst_497" "dlist2_snd_498" 
                                        (identifier "dlist2_496")
                                        (set-vec (u8 0) (identifier "inits_src_ref_494")
                                          (let-pair "dlist3_fst_500" "dlist3_snd_501" 
                                            (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_498"))
                                            (make-tup (cons (identifier "dlist3_fst_500") (identifier "dlist2_fst_497")) (identifier "dlist3_snd_501"))))))
                                    (set-vec (u8 0) (identifier "repeat_n_495") (add (unsafe-nth (u8 0) (identifier "repeat_n_495")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "inits_src_ref_494")))))) 
                      (make-tup (not-null (identity (identifier "dlist4_fst_503"))) (identifier "dlist4_snd_504"))))
                  (let-pair "drec_fst_509" "drec_snd_510" (identifier "drec_508")
                    (let "drec_552"
                      (if (eq (peek-u8 (identifier "drec_snd_510") (size 0)) (u8 1)) 
                        (make-tup (null "(U32; $raql_expr?; $raql_expr[[]])") (ptr-add (identifier "drec_snd_510") (size 1)))
                        (let "dtup_514" (let-pair "du32_fst_512" "du32_snd_513" (read-u32 little-endian (ptr-add (identifier "drec_snd_510") (size 1))) (make-tup (identifier "du32_fst_512") (identifier "du32_snd_513")))
                          (let-pair "dtup_fst_515" "dtup_snd_516" (identifier "dtup_514")
                            (let "dtup_520"
                              (if (eq (peek-u8 (identifier "dtup_snd_516") (size 0)) (u8 1)) 
                                (make-tup (null "$raql_expr") (ptr-add (identifier "dtup_snd_516") (size 1)))
                                (let-pair "make1_1_fst_518" "make1_1_snd_519" 
                                  (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "dtup_snd_516") (size 1))) 
                                  (make-tup (not-null (identifier "make1_1_fst_518")) (identifier "make1_1_snd_519"))))
                              (let-pair "dtup_fst_521" "dtup_snd_522" 
                                (identifier "dtup_520")
                                (let-pair "dlist4_fst_544" "dlist4_snd_545"
                                  (let "dlist1_532"
                                    (let "leb_ref_523" (make-vec (u32 0))
                                      (let "shft_ref_524" (make-vec (u8 0))
                                        (let "p_ref_525" (make-vec (identifier "dtup_snd_522"))
                                          (seq
                                            (while
                                              (let "leb128_526" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_525")))
                                                (let-pair "leb128_fst_527" "leb128_snd_528" 
                                                  (identifier "leb128_526")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_525") (identifier "leb128_snd_528"))
                                                    (set-vec (u8 0) (identifier "leb_ref_523")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_527") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_524"))) (unsafe-nth (u8 0) (identifier "leb_ref_523"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_524") (add (unsafe-nth (u8 0) (identifier "shft_ref_524")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_527") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_523")) (unsafe-nth (u8 0) (identifier "p_ref_525")))))))
                                    (let-pair "dlist1_fst_533" "dlist1_snd_534" 
                                      (identifier "dlist1_532")
                                      (let "inits_src_ref_535" (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_534")))
                                        (seq
                                          (let "repeat_n_536" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_533")) (unsafe-nth (u8 0) (identifier "repeat_n_536")))
                                              (seq
                                                (let "dlist2_537" (unsafe-nth (u8 0) (identifier "inits_src_ref_535"))
                                                  (let-pair "dlist2_fst_538" "dlist2_snd_539" 
                                                    (identifier "dlist2_537")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_535")
                                                      (let-pair "dlist3_fst_541" "dlist3_snd_542" 
                                                        (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_539"))
                                                        (make-tup (cons (identifier "dlist3_fst_541") (identifier "dlist2_fst_538")) (identifier "dlist3_snd_542"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_536") (add (unsafe-nth (u8 0) (identifier "repeat_n_536")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_535"))))))
                                  (make-tup (not-null (make-tup (identifier "dtup_fst_515") (identifier "dtup_fst_521") (identity (identifier "dlist4_fst_544")))) (identifier "dlist4_snd_545"))))))))
                      (let-pair "drec_fst_553" "drec_snd_554" (identifier "drec_552")
                        (let "drec_555" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_554"))
                          (let-pair "drec_fst_556" "drec_snd_557" (identifier "drec_555")
                            (let "drec_561"
                              (if (eq (peek-u8 (identifier "drec_snd_557") (size 0)) (u8 1)) 
                                (make-tup (null "$event_time") (ptr-add (identifier "drec_snd_557") (size 1)))
                                (let-pair "make1_1_fst_559" "make1_1_snd_560" 
                                  (apply (ext-identifier event_time of-row-binary) (ptr-add (identifier "drec_snd_557") (size 1))) 
                                  (make-tup (not-null (identifier "make1_1_fst_559")) (identifier "make1_1_snd_560"))))
                              (let-pair "drec_fst_562" "drec_snd_563" 
                                (identifier "drec_561")
                                (let "drec_587"
                                  (let-pair "dlist4_fst_585" "dlist4_snd_586"
                                    (let "dlist1_573"
                                      (let "leb_ref_564" (make-vec (u32 0))
                                        (let "shft_ref_565" (make-vec (u8 0))
                                          (let "p_ref_566" (make-vec (identifier "drec_snd_563"))
                                            (seq
                                              (while
                                                (let "leb128_567" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_566")))
                                                  (let-pair "leb128_fst_568" "leb128_snd_569" 
                                                    (identifier "leb128_567")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_566") (identifier "leb128_snd_569"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_564")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_568") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_565")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_564")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_565") (add (unsafe-nth (u8 0) (identifier "shft_ref_565")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_568") (u8 128))))) 
                                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_564")) (unsafe-nth (u8 0) (identifier "p_ref_566")))))))
                                      (let-pair "dlist1_fst_574" "dlist1_snd_575" 
                                        (identifier "dlist1_573")
                                        (let "inits_src_ref_576" (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_575")))
                                          (seq
                                            (let "repeat_n_577" (make-vec (i32 0))
                                              (while (gt (to-i32 (identifier "dlist1_fst_574")) (unsafe-nth (u8 0) (identifier "repeat_n_577")))
                                                (seq
                                                  (let "dlist2_578" (unsafe-nth (u8 0) (identifier "inits_src_ref_576"))
                                                    (let-pair "dlist2_fst_579" "dlist2_snd_580" 
                                                      (identifier "dlist2_578")
                                                      (set-vec (u8 0) 
                                                        (identifier "inits_src_ref_576")
                                                        (let-pair "dlist3_fst_582" "dlist3_snd_583" 
                                                          (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_580"))
                                                          (make-tup (cons (identifier "dlist3_fst_582") (identifier "dlist2_fst_579")) (identifier "dlist3_snd_583"))))))
                                                  (set-vec (u8 0) (identifier "repeat_n_577") (add (unsafe-nth (u8 0) (identifier "repeat_n_577")) (i32 1)))))) 
                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_576")))))) 
                                    (make-tup (identity (identifier "dlist4_fst_585")) (identifier "dlist4_snd_586")))
                                  (let-pair "drec_fst_588" "drec_snd_589" 
                                    (identifier "drec_587")
                                    (let "drec_613"
                                      (let-pair "dlist4_fst_611" "dlist4_snd_612"
                                        (let "dlist1_599"
                                          (let "leb_ref_590" (make-vec (u32 0))
                                            (let "shft_ref_591" (make-vec (u8 0))
                                              (let "p_ref_592" (make-vec (identifier "drec_snd_589"))
                                                (seq
                                                  (while
                                                    (let "leb128_593" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_592")))
                                                      (let-pair "leb128_fst_594" "leb128_snd_595" 
                                                        (identifier "leb128_593")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_592") (identifier "leb128_snd_595"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_590")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_594") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_591")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_590")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_591") (add (unsafe-nth (u8 0) (identifier "shft_ref_591")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_594") (u8 128))))) 
                                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_590")) (unsafe-nth (u8 0) (identifier "p_ref_592")))))))
                                          (let-pair "dlist1_fst_600" "dlist1_snd_601" 
                                            (identifier "dlist1_599")
                                            (let "inits_src_ref_602" 
                                              (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_601")))
                                              (seq
                                                (let "repeat_n_603" (make-vec (i32 0))
                                                  (while (gt (to-i32 (identifier "dlist1_fst_600")) (unsafe-nth (u8 0) (identifier "repeat_n_603")))
                                                    (seq
                                                      (let "dlist2_604" 
                                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_602"))
                                                        (let-pair "dlist2_fst_605" "dlist2_snd_606" 
                                                          (identifier "dlist2_604")
                                                          (set-vec (u8 0) 
                                                            (identifier "inits_src_ref_602")
                                                            (let-pair "dlist3_fst_608" "dlist3_snd_609" 
                                                              (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_606"))
                                                              (make-tup (cons (identifier "dlist3_fst_608") (identifier "dlist2_fst_605")) (identifier "dlist3_snd_609"))))))
                                                      (set-vec (u8 0) (identifier "repeat_n_603") (add (unsafe-nth (u8 0) (identifier "repeat_n_603")) (i32 1)))))) 
                                                (unsafe-nth (u8 0) (identifier "inits_src_ref_602")))))) 
                                        (make-tup (identity (identifier "dlist4_fst_611")) (identifier "dlist4_snd_612")))
                                      (let-pair "drec_fst_614" "drec_snd_615" 
                                        (identifier "drec_613")
                                        (let "drec_616" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_615"))
                                          (let-pair "drec_fst_617" "drec_snd_618" 
                                            (identifier "drec_616")
                                            (let "drec_622" (let-pair "dbool_fst_620" "dbool_snd_621" (read-u8 (identifier "drec_snd_618")) (make-tup (not (eq (identifier "dbool_fst_620") (u8 0))) (identifier "dbool_snd_621")))
                                              (let-pair "drec_fst_623" "drec_snd_624" 
                                                (identifier "drec_622")
                                                (let "drec_625" (apply (ext-identifier raql_flush_method of-row-binary) (identifier "drec_snd_624"))
                                                  (let-pair "drec_fst_626" "drec_snd_627" 
                                                    (identifier "drec_625")
                                                    (let "drec_651"
                                                      (let-pair "dlist4_fst_649" "dlist4_snd_650"
                                                        (let "dlist1_637"
                                                          (let "leb_ref_628" 
                                                            (make-vec (u32 0))
                                                            (let "shft_ref_629" 
                                                              (make-vec (u8 0))
                                                              (let "p_ref_630" 
                                                                (make-vec (identifier "drec_snd_627"))
                                                                (seq
                                                                  (while
                                                                    (let "leb128_631" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_630")))
                                                                    (let-pair "leb128_fst_632" "leb128_snd_633" 
                                                                    (identifier "leb128_631")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_630") (identifier "leb128_snd_633"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_628")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_632") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_629")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_628")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_629") (add (unsafe-nth (u8 0) (identifier "shft_ref_629")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_632") (u8 128))))) 
                                                                    (nop)) 
                                                                  (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_628")) (unsafe-nth (u8 0) (identifier "p_ref_630")))))))
                                                          (let-pair "dlist1_fst_638" "dlist1_snd_639" 
                                                            (identifier "dlist1_637")
                                                            (let "inits_src_ref_640"
                                                              (make-vec
                                                                (make-tup 
                                                                  (end-of-list "(data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])")
                                                                  (identifier "dlist1_snd_639")))
                                                              (seq
                                                                (let "repeat_n_641" 
                                                                  (make-vec (i32 0))
                                                                  (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_638")) (unsafe-nth (u8 0) (identifier "repeat_n_641")))
                                                                    (seq
                                                                    (let "dlist2_642" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_640"))
                                                                    (let-pair "dlist2_fst_643" "dlist2_snd_644" 
                                                                    (identifier "dlist2_642")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_640")
                                                                    (let-pair "dlist3_fst_646" "dlist3_snd_647" 
                                                                    (apply (identifier "data_source-of-row-binary") (identifier "dlist2_snd_644"))
                                                                    (make-tup (cons (identifier "dlist3_fst_646") (identifier "dlist2_fst_643")) (identifier "dlist3_snd_647"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_641") (add (unsafe-nth (u8 0) (identifier "repeat_n_641")) (i32 1))))))
                                                                (unsafe-nth (u8 0) (identifier "inits_src_ref_640")))))) 
                                                        (make-tup (identity (identifier "dlist4_fst_649")) (identifier "dlist4_snd_650")))
                                                      (let-pair "drec_fst_652" "drec_snd_653" 
                                                        (identifier "drec_651")
                                                        (let "drec_657"
                                                          (if (eq (peek-u8 (identifier "drec_snd_653") (size 0)) (u8 1)) 
                                                            (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_653") (size 1)))
                                                            (let-pair "make1_1_fst_655" "make1_1_snd_656" 
                                                              (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_653") (size 1)))
                                                              (make-tup (not-null (identifier "make1_1_fst_655")) (identifier "make1_1_snd_656"))))
                                                          (let-pair "drec_fst_658" "drec_snd_659" 
                                                            (identifier "drec_657")
                                                            (let-pair "dlist4_fst_681" "dlist4_snd_682"
                                                              (let "dlist1_669"
                                                                (let "leb_ref_660" 
                                                                  (make-vec (u32 0))
                                                                  (let "shft_ref_661" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_662" 
                                                                    (make-vec (identifier "drec_snd_659"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_663" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_662")))
                                                                    (let-pair "leb128_fst_664" "leb128_snd_665" 
                                                                    (identifier "leb128_663")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_662") (identifier "leb128_snd_665"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_660")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_664") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_661")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_660")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_661") (add (unsafe-nth (u8 0) (identifier "shft_ref_661")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_664") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_660")) (unsafe-nth (u8 0) (identifier "p_ref_662")))))))
                                                                (let-pair "dlist1_fst_670" "dlist1_snd_671" 
                                                                  (identifier "dlist1_669")
                                                                  (let "inits_src_ref_672" 
                                                                    (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_671")))
                                                                    (seq
                                                                    (let "repeat_n_673" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_670")) (unsafe-nth (u8 0) (identifier "repeat_n_673")))
                                                                    (seq
                                                                    (let "dlist2_674" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_672"))
                                                                    (let-pair "dlist2_fst_675" "dlist2_snd_676" 
                                                                    (identifier "dlist2_674")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_672")
                                                                    (let-pair "dlist3_fst_678" "dlist3_snd_679" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_676"))
                                                                    (make-tup (cons (identifier "dlist3_fst_678") (identifier "dlist2_fst_675")) (identifier "dlist3_snd_679"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_673") (add (unsafe-nth (u8 0) (identifier "repeat_n_673")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_672"))))))
                                                              (make-tup
                                                                (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" 0
                                                                  (make-rec 
                                                                    (string "factors") 
                                                                    (identity (identifier "dlist4_fst_681")) 
                                                                    (string "every") 
                                                                    (identifier "drec_fst_658") 
                                                                    (string "from") 
                                                                    (identifier "drec_fst_652") 
                                                                    (string "flush_how") 
                                                                    (identifier "drec_fst_626") 
                                                                    (string "commit_before") 
                                                                    (identifier "drec_fst_623") 
                                                                    (string "commit_cond") 
                                                                    (identifier "drec_fst_617") 
                                                                    (string "key") 
                                                                    (identifier "drec_fst_614") 
                                                                    (string "notifications") 
                                                                    (identifier "drec_fst_588") 
                                                                    (string "event_time") 
                                                                    (identifier "drec_fst_562") 
                                                                    (string "where") 
                                                                    (identifier "drec_fst_556") 
                                                                    (string "sort") 
                                                                    (identifier "drec_fst_553") 
                                                                    (string "and_all_others") 
                                                                    (identifier "drec_fst_509") 
                                                                    (string "fields") 
                                                                    (identifier "drec_fst_480"))) 
                                                                (identifier "dlist4_snd_682")))))))))))))))))))))))))))
            (if (eq (u16 1) (identifier "dsum1_fst_360"))
              (let "drec_415" (apply (identifier "external_source-of-row-binary") (identifier "dsum1_snd_361"))
                (let-pair "drec_fst_416" "drec_snd_417" (identifier "drec_415")
                  (let "drec_418" (apply (identifier "external_format-of-row-binary") (identifier "drec_snd_417"))
                    (let-pair "drec_fst_419" "drec_snd_420" (identifier "drec_418")
                      (let "drec_424"
                        (if (eq (peek-u8 (identifier "drec_snd_420") (size 0)) (u8 1)) 
                          (make-tup (null "$event_time") (ptr-add (identifier "drec_snd_420") (size 1)))
                          (let-pair "make1_1_fst_422" "make1_1_snd_423" 
                            (apply (ext-identifier event_time of-row-binary) (ptr-add (identifier "drec_snd_420") (size 1))) 
                            (make-tup (not-null (identifier "make1_1_fst_422")) (identifier "make1_1_snd_423"))))
                        (let-pair "drec_fst_425" "drec_snd_426" (identifier "drec_424")
                          (let-pair "dlist4_fst_448" "dlist4_snd_449"
                            (let "dlist1_436"
                              (let "leb_ref_427" (make-vec (u32 0))
                                (let "shft_ref_428" (make-vec (u8 0))
                                  (let "p_ref_429" (make-vec (identifier "drec_snd_426"))
                                    (seq
                                      (while
                                        (let "leb128_430" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_429")))
                                          (let-pair "leb128_fst_431" "leb128_snd_432" 
                                            (identifier "leb128_430")
                                            (seq (set-vec (u8 0) (identifier "p_ref_429") (identifier "leb128_snd_432"))
                                              (set-vec (u8 0) (identifier "leb_ref_427")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_431") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_428"))) (unsafe-nth (u8 0) (identifier "leb_ref_427"))))
                                              (set-vec (u8 0) (identifier "shft_ref_428") (add (unsafe-nth (u8 0) (identifier "shft_ref_428")) (u8 7))) 
                                              (ge (identifier "leb128_fst_431") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_427")) (unsafe-nth (u8 0) (identifier "p_ref_429")))))))
                              (let-pair "dlist1_fst_437" "dlist1_snd_438" 
                                (identifier "dlist1_436")
                                (let "inits_src_ref_439" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_438")))
                                  (seq
                                    (let "repeat_n_440" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_437")) (unsafe-nth (u8 0) (identifier "repeat_n_440")))
                                        (seq
                                          (let "dlist2_441" (unsafe-nth (u8 0) (identifier "inits_src_ref_439"))
                                            (let-pair "dlist2_fst_442" "dlist2_snd_443" 
                                              (identifier "dlist2_441")
                                              (set-vec (u8 0) (identifier "inits_src_ref_439")
                                                (let-pair "dlist3_fst_445" "dlist3_snd_446" 
                                                  (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_443"))
                                                  (make-tup (cons (identifier "dlist3_fst_445") (identifier "dlist2_fst_442")) (identifier "dlist3_snd_446"))))))
                                          (set-vec (u8 0) (identifier "repeat_n_440") (add (unsafe-nth (u8 0) (identifier "repeat_n_440")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_439"))))))
                            (make-tup
                              (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" 1
                                (make-rec (string "factors") (identity (identifier "dlist4_fst_448")) 
                                  (string "event_time") (identifier "drec_fst_425") 
                                  (string "format") (identifier "drec_fst_419") 
                                  (string "source") (identifier "drec_fst_416"))) 
                              (identifier "dlist4_snd_449")))))))))
              (seq (assert (eq (identifier "dsum1_fst_360") (u16 2)))
                (let "drec_374"
                  (let "dstring1_368"
                    (let "leb_ref_362" (make-vec (u32 0))
                      (let "shft_ref_363" (make-vec (u8 0))
                        (let "p_ref_364" (make-vec (identifier "dsum1_snd_361"))
                          (seq
                            (while
                              (let "leb128_365" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_364")))
                                (let-pair "leb128_fst_366" "leb128_snd_367" 
                                  (identifier "leb128_365")
                                  (seq (set-vec (u8 0) (identifier "p_ref_364") (identifier "leb128_snd_367"))
                                    (set-vec (u8 0) (identifier "leb_ref_362")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_366") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_363"))) (unsafe-nth (u8 0) (identifier "leb_ref_362"))))
                                    (set-vec (u8 0) (identifier "shft_ref_363") (add (unsafe-nth (u8 0) (identifier "shft_ref_363")) (u8 7))) 
                                    (ge (identifier "leb128_fst_366") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_362"))) (unsafe-nth (u8 0) (identifier "p_ref_364")))))))
                    (let-pair "dstring1_fst_369" "dstring1_snd_370" (identifier "dstring1_368")
                      (let-pair "dstring2_fst_372" "dstring2_snd_373" 
                        (read-bytes (identifier "dstring1_snd_370") (identifier "dstring1_fst_369")) 
                        (make-tup (string-of-bytes (identifier "dstring2_fst_372")) (identifier "dstring2_snd_373")))))
                  (let-pair "drec_fst_375" "drec_snd_376" (identifier "drec_374")
                    (let "drec_380" (let-pair "du16_fst_378" "du16_snd_379" (read-u16 little-endian (identifier "drec_snd_376")) (make-tup (identifier "du16_fst_378") (identifier "du16_snd_379")))
                      (let-pair "drec_fst_381" "drec_snd_382" (identifier "drec_380")
                        (let "drec_383" (apply (ext-identifier raql_net_protocol of-row-binary) (identifier "drec_snd_382"))
                          (let-pair "drec_fst_384" "drec_snd_385" (identifier "drec_383")
                            (let-pair "dlist4_fst_407" "dlist4_snd_408"
                              (let "dlist1_395"
                                (let "leb_ref_386" (make-vec (u32 0))
                                  (let "shft_ref_387" (make-vec (u8 0))
                                    (let "p_ref_388" (make-vec (identifier "drec_snd_385"))
                                      (seq
                                        (while
                                          (let "leb128_389" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_388")))
                                            (let-pair "leb128_fst_390" "leb128_snd_391" 
                                              (identifier "leb128_389")
                                              (seq (set-vec (u8 0) (identifier "p_ref_388") (identifier "leb128_snd_391"))
                                                (set-vec (u8 0) (identifier "leb_ref_386")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_390") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_387"))) (unsafe-nth (u8 0) (identifier "leb_ref_386"))))
                                                (set-vec (u8 0) (identifier "shft_ref_387") (add (unsafe-nth (u8 0) (identifier "shft_ref_387")) (u8 7))) 
                                                (ge (identifier "leb128_fst_390") (u8 128))))) 
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_386")) (unsafe-nth (u8 0) (identifier "p_ref_388")))))))
                                (let-pair "dlist1_fst_396" "dlist1_snd_397" 
                                  (identifier "dlist1_395")
                                  (let "inits_src_ref_398" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_397")))
                                    (seq
                                      (let "repeat_n_399" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_396")) (unsafe-nth (u8 0) (identifier "repeat_n_399")))
                                          (seq
                                            (let "dlist2_400" (unsafe-nth (u8 0) (identifier "inits_src_ref_398"))
                                              (let-pair "dlist2_fst_401" "dlist2_snd_402" 
                                                (identifier "dlist2_400")
                                                (set-vec (u8 0) (identifier "inits_src_ref_398")
                                                  (let-pair "dlist3_fst_404" "dlist3_snd_405" 
                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_402"))
                                                    (make-tup (cons (identifier "dlist3_fst_404") (identifier "dlist2_fst_401")) (identifier "dlist3_snd_405"))))))
                                            (set-vec (u8 0) (identifier "repeat_n_399") (add (unsafe-nth (u8 0) (identifier "repeat_n_399")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_398"))))))
                              (make-tup
                                (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" 2
                                  (make-rec (string "factors") (identity (identifier "dlist4_fst_407")) 
                                    (string "proto") (identifier "drec_fst_384") 
                                    (string "port") (identifier "drec_fst_381") 
                                    (string "net_addr") (identifier "drec_fst_375"))) 
                                (identifier "dlist4_snd_408")))))))))))))))
 */
static std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> fun3189 { [&fun3189](Pointer p_0) {
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3190 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_3191;
    {
      auto du16_fst_354 { std::get<0>(id_3190) };
      auto du16_snd_355 { std::get<1>(id_3190) };
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3192 { du16_fst_354, du16_snd_355 };
      letpair_res_3191 = id_3192;
    }
    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3193;
    {
      ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 dsum1_359 { letpair_res_3191 };
      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3194;
      {
        auto dsum1_fst_360 { std::get<0>(dsum1_359) };
        auto dsum1_snd_361 { std::get<1>(dsum1_359) };
        uint16_t id_3195 { 0 };
        bool id_3196 { bool(id_3195 == dsum1_fst_360) };
        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd choose_res_3197;
        if (id_3196) {
          uint32_t id_3198 { 0U };
          Vec<1, uint32_t> id_3199 {  id_3198  };
          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3200;
          {
            Vec<1, uint32_t> leb_ref_456 { id_3199 };
            uint8_t id_3201 { 0 };
            Vec<1, uint8_t> id_3202 {  id_3201  };
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3203;
            {
              Vec<1, uint8_t> shft_ref_457 { id_3202 };
              Vec<1, Pointer> id_3204 {  dsum1_snd_361  };
              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3205;
              {
                Vec<1, Pointer> p_ref_458 { id_3204 };
                bool while_flag_3206 { true };
                do {
                  uint8_t id_3207 { 0 };
                  Pointer id_3208 { p_ref_458[id_3207] };
                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3209 { id_3208.readU8() };
                  bool let_res_3210;
                  {
                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_459 { id_3209 };
                    bool letpair_res_3211;
                    {
                      auto leb128_fst_460 { std::get<0>(leb128_459) };
                      auto leb128_snd_461 { std::get<1>(leb128_459) };
                      uint8_t id_3212 { 0 };
                      Void id_3213 { ((void)(p_ref_458[id_3212] = leb128_snd_461), ::dessser::VOID) };
                      (void)id_3213;
                      uint8_t id_3214 { 0 };
                      uint8_t id_3215 { 127 };
                      uint8_t id_3216 { uint8_t(leb128_fst_460 & id_3215) };
                      uint32_t id_3217 { uint32_t(id_3216) };
                      uint8_t id_3218 { 0 };
                      uint8_t id_3219 { shft_ref_457[id_3218] };
                      uint32_t id_3220 { uint32_t(id_3217 << id_3219) };
                      uint8_t id_3221 { 0 };
                      uint32_t id_3222 { leb_ref_456[id_3221] };
                      uint32_t id_3223 { uint32_t(id_3220 | id_3222) };
                      Void id_3224 { ((void)(leb_ref_456[id_3214] = id_3223), ::dessser::VOID) };
                      (void)id_3224;
                      uint8_t id_3225 { 0 };
                      uint8_t id_3226 { 0 };
                      uint8_t id_3227 { shft_ref_457[id_3226] };
                      uint8_t id_3228 { 7 };
                      uint8_t id_3229 { uint8_t(id_3227 + id_3228) };
                      Void id_3230 { ((void)(shft_ref_457[id_3225] = id_3229), ::dessser::VOID) };
                      (void)id_3230;
                      uint8_t id_3231 { 128 };
                      bool id_3232 { bool(leb128_fst_460 >= id_3231) };
                      letpair_res_3211 = id_3232;
                    }
                    let_res_3210 = letpair_res_3211;
                  }
                  while_flag_3206 = let_res_3210;
                  if (while_flag_3206) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_3206);
                (void)::dessser::VOID;
                uint8_t id_3233 { 0 };
                uint32_t id_3234 { leb_ref_456[id_3233] };
                uint8_t id_3235 { 0 };
                Pointer id_3236 { p_ref_458[id_3235] };
                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3237 { id_3234, id_3236 };
                let_res_3205 = id_3237;
              }
              let_res_3203 = let_res_3205;
            }
            let_res_3200 = let_res_3203;
          }
          ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d let_res_3238;
          {
            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_465 { let_res_3200 };
            ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d letpair_res_3239;
            {
              auto dlist1_fst_466 { std::get<0>(dlist1_465) };
              auto dlist1_snd_467 { std::get<1>(dlist1_465) };
              Lst<dessser::gen::raql_select_field::t_ext> endoflist_3240;
              ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3241 { endoflist_3240, dlist1_snd_467 };
              Vec<1, ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d> id_3242 {  id_3241  };
              ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d let_res_3243;
              {
                Vec<1, ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d> inits_src_ref_468 { id_3242 };
                int32_t id_3244 { 0L };
                Vec<1, int32_t> id_3245 {  id_3244  };
                {
                  Vec<1, int32_t> repeat_n_469 { id_3245 };
                  bool while_flag_3246 { true };
                  do {
                    int32_t id_3247 { int32_t(dlist1_fst_466) };
                    uint8_t id_3248 { 0 };
                    int32_t id_3249 { repeat_n_469[id_3248] };
                    bool id_3250 { bool(id_3247 > id_3249) };
                    while_flag_3246 = id_3250;
                    if (while_flag_3246) {
                      uint8_t id_3251 { 0 };
                      ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3252 { inits_src_ref_468[id_3251] };
                      {
                        ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d dlist2_470 { id_3252 };
                        {
                          auto dlist2_fst_471 { std::get<0>(dlist2_470) };
                          auto dlist2_snd_472 { std::get<1>(dlist2_470) };
                          uint8_t id_3253 { 0 };
                          auto fun3254 { dessser::gen::raql_select_field::of_row_binary };
                          ::dessser::gen::raql_operation::t8ce288a7922f2eebd9fbfe87e5972d1b id_3255 { fun3254(dlist2_snd_472) };
                          ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d letpair_res_3256;
                          {
                            auto dlist3_fst_474 { std::get<0>(id_3255) };
                            auto dlist3_snd_475 { std::get<1>(id_3255) };
                            Lst<dessser::gen::raql_select_field::t_ext> id_3257 { dlist3_fst_474, dlist2_fst_471 };
                            ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3258 { id_3257, dlist3_snd_475 };
                            letpair_res_3256 = id_3258;
                          }
                          Void id_3259 { ((void)(inits_src_ref_468[id_3253] = letpair_res_3256), ::dessser::VOID) };
                          (void)id_3259;
                        }
                        (void)::dessser::VOID;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_3260 { 0 };
                      uint8_t id_3261 { 0 };
                      int32_t id_3262 { repeat_n_469[id_3261] };
                      int32_t id_3263 { 1L };
                      int32_t id_3264 { int32_t(id_3262 + id_3263) };
                      Void id_3265 { ((void)(repeat_n_469[id_3260] = id_3264), ::dessser::VOID) };
                      (void)id_3265;
                      (void)id_3265;
                    }
                  } while (while_flag_3246);
                  (void)::dessser::VOID;
                }
                (void)::dessser::VOID;
                uint8_t id_3266 { 0 };
                ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3267 { inits_src_ref_468[id_3266] };
                let_res_3243 = id_3267;
              }
              letpair_res_3239 = let_res_3243;
            }
            let_res_3238 = letpair_res_3239;
          }
          ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d letpair_res_3268;
          {
            auto dlist4_fst_477 { std::get<0>(let_res_3238) };
            auto dlist4_snd_478 { std::get<1>(let_res_3238) };
            ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d id_3269 { dlist4_fst_477, dlist4_snd_478 };
            letpair_res_3268 = id_3269;
          }
          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3270;
          {
            ::dessser::gen::raql_operation::t2b03e6197598f957b7ddc8235cc3f32d drec_479 { letpair_res_3268 };
            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3271;
            {
              auto drec_fst_480 { std::get<0>(drec_479) };
              auto drec_snd_481 { std::get<1>(drec_479) };
              Size id_3272 { 0UL };
              uint8_t id_3273 { drec_snd_481.peekU8(id_3272) };
              uint8_t id_3274 { 1 };
              bool id_3275 { bool(id_3273 == id_3274) };
              ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 choose_res_3276;
              if (id_3275) {
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_3277 { std::nullopt };
                Size id_3278 { 1UL };
                Pointer id_3279 { drec_snd_481.skip(id_3278) };
                ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 id_3280 { id_3277, id_3279 };
                choose_res_3276 = id_3280;
              } else {
                uint32_t id_3281 { 0U };
                Vec<1, uint32_t> id_3282 {  id_3281  };
                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3283;
                {
                  Vec<1, uint32_t> leb_ref_482 { id_3282 };
                  uint8_t id_3284 { 0 };
                  Vec<1, uint8_t> id_3285 {  id_3284  };
                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3286;
                  {
                    Vec<1, uint8_t> shft_ref_483 { id_3285 };
                    Size id_3287 { 1UL };
                    Pointer id_3288 { drec_snd_481.skip(id_3287) };
                    Vec<1, Pointer> id_3289 {  id_3288  };
                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3290;
                    {
                      Vec<1, Pointer> p_ref_484 { id_3289 };
                      bool while_flag_3291 { true };
                      do {
                        uint8_t id_3292 { 0 };
                        Pointer id_3293 { p_ref_484[id_3292] };
                        ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3294 { id_3293.readU8() };
                        bool let_res_3295;
                        {
                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_485 { id_3294 };
                          bool letpair_res_3296;
                          {
                            auto leb128_fst_486 { std::get<0>(leb128_485) };
                            auto leb128_snd_487 { std::get<1>(leb128_485) };
                            uint8_t id_3297 { 0 };
                            Void id_3298 { ((void)(p_ref_484[id_3297] = leb128_snd_487), ::dessser::VOID) };
                            (void)id_3298;
                            uint8_t id_3299 { 0 };
                            uint8_t id_3300 { 127 };
                            uint8_t id_3301 { uint8_t(leb128_fst_486 & id_3300) };
                            uint32_t id_3302 { uint32_t(id_3301) };
                            uint8_t id_3303 { 0 };
                            uint8_t id_3304 { shft_ref_483[id_3303] };
                            uint32_t id_3305 { uint32_t(id_3302 << id_3304) };
                            uint8_t id_3306 { 0 };
                            uint32_t id_3307 { leb_ref_482[id_3306] };
                            uint32_t id_3308 { uint32_t(id_3305 | id_3307) };
                            Void id_3309 { ((void)(leb_ref_482[id_3299] = id_3308), ::dessser::VOID) };
                            (void)id_3309;
                            uint8_t id_3310 { 0 };
                            uint8_t id_3311 { 0 };
                            uint8_t id_3312 { shft_ref_483[id_3311] };
                            uint8_t id_3313 { 7 };
                            uint8_t id_3314 { uint8_t(id_3312 + id_3313) };
                            Void id_3315 { ((void)(shft_ref_483[id_3310] = id_3314), ::dessser::VOID) };
                            (void)id_3315;
                            uint8_t id_3316 { 128 };
                            bool id_3317 { bool(leb128_fst_486 >= id_3316) };
                            letpair_res_3296 = id_3317;
                          }
                          let_res_3295 = letpair_res_3296;
                        }
                        while_flag_3291 = let_res_3295;
                        if (while_flag_3291) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_3291);
                      (void)::dessser::VOID;
                      uint8_t id_3318 { 0 };
                      uint32_t id_3319 { leb_ref_482[id_3318] };
                      uint8_t id_3320 { 0 };
                      Pointer id_3321 { p_ref_484[id_3320] };
                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3322 { id_3319, id_3321 };
                      let_res_3290 = id_3322;
                    }
                    let_res_3286 = let_res_3290;
                  }
                  let_res_3283 = let_res_3286;
                }
                ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3323;
                {
                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_491 { let_res_3283 };
                  ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3324;
                  {
                    auto dlist1_fst_492 { std::get<0>(dlist1_491) };
                    auto dlist1_snd_493 { std::get<1>(dlist1_491) };
                    Lst<dessser::gen::field_name::t_ext> endoflist_3325;
                    ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3326 { endoflist_3325, dlist1_snd_493 };
                    Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_3327 {  id_3326  };
                    ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3328;
                    {
                      Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_494 { id_3327 };
                      int32_t id_3329 { 0L };
                      Vec<1, int32_t> id_3330 {  id_3329  };
                      {
                        Vec<1, int32_t> repeat_n_495 { id_3330 };
                        bool while_flag_3331 { true };
                        do {
                          int32_t id_3332 { int32_t(dlist1_fst_492) };
                          uint8_t id_3333 { 0 };
                          int32_t id_3334 { repeat_n_495[id_3333] };
                          bool id_3335 { bool(id_3332 > id_3334) };
                          while_flag_3331 = id_3335;
                          if (while_flag_3331) {
                            uint8_t id_3336 { 0 };
                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3337 { inits_src_ref_494[id_3336] };
                            {
                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_496 { id_3337 };
                              {
                                auto dlist2_fst_497 { std::get<0>(dlist2_496) };
                                auto dlist2_snd_498 { std::get<1>(dlist2_496) };
                                uint8_t id_3338 { 0 };
                                auto fun3339 { dessser::gen::field_name::of_row_binary };
                                ::dessser::gen::raql_operation::t18cecf882d7ac80cef37dfe6b22279d4 id_3340 { fun3339(dlist2_snd_498) };
                                ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3341;
                                {
                                  auto dlist3_fst_500 { std::get<0>(id_3340) };
                                  auto dlist3_snd_501 { std::get<1>(id_3340) };
                                  Lst<dessser::gen::field_name::t_ext> id_3342 { dlist3_fst_500, dlist2_fst_497 };
                                  ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3343 { id_3342, dlist3_snd_501 };
                                  letpair_res_3341 = id_3343;
                                }
                                Void id_3344 { ((void)(inits_src_ref_494[id_3338] = letpair_res_3341), ::dessser::VOID) };
                                (void)id_3344;
                              }
                              (void)::dessser::VOID;
                            }
                            (void)::dessser::VOID;
                            uint8_t id_3345 { 0 };
                            uint8_t id_3346 { 0 };
                            int32_t id_3347 { repeat_n_495[id_3346] };
                            int32_t id_3348 { 1L };
                            int32_t id_3349 { int32_t(id_3347 + id_3348) };
                            Void id_3350 { ((void)(repeat_n_495[id_3345] = id_3349), ::dessser::VOID) };
                            (void)id_3350;
                            (void)id_3350;
                          }
                        } while (while_flag_3331);
                        (void)::dessser::VOID;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_3351 { 0 };
                      ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3352 { inits_src_ref_494[id_3351] };
                      let_res_3328 = id_3352;
                    }
                    letpair_res_3324 = let_res_3328;
                  }
                  let_res_3323 = letpair_res_3324;
                }
                ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 letpair_res_3353;
                {
                  auto dlist4_fst_503 { std::get<0>(let_res_3323) };
                  auto dlist4_snd_504 { std::get<1>(let_res_3323) };
                  std::optional<Lst<dessser::gen::field_name::t_ext>> id_3354 { dlist4_fst_503 };
                  ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 id_3355 { id_3354, dlist4_snd_504 };
                  letpair_res_3353 = id_3355;
                }
                choose_res_3276 = letpair_res_3353;
              }
              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3356;
              {
                ::dessser::gen::raql_operation::t2fa56af3afd4098bea1b66e93db81284 drec_508 { choose_res_3276 };
                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3357;
                {
                  auto drec_fst_509 { std::get<0>(drec_508) };
                  auto drec_snd_510 { std::get<1>(drec_508) };
                  Size id_3358 { 0UL };
                  uint8_t id_3359 { drec_snd_510.peekU8(id_3358) };
                  uint8_t id_3360 { 1 };
                  bool id_3361 { bool(id_3359 == id_3360) };
                  ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 choose_res_3362;
                  if (id_3361) {
                    std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_3363 { std::nullopt };
                    Size id_3364 { 1UL };
                    Pointer id_3365 { drec_snd_510.skip(id_3364) };
                    ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 id_3366 { id_3363, id_3365 };
                    choose_res_3362 = id_3366;
                  } else {
                    Size id_3367 { 1UL };
                    Pointer id_3368 { drec_snd_510.skip(id_3367) };
                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3369 { id_3368.readU32Le() };
                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 letpair_res_3370;
                    {
                      auto du32_fst_512 { std::get<0>(id_3369) };
                      auto du32_snd_513 { std::get<1>(id_3369) };
                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3371 { du32_fst_512, du32_snd_513 };
                      letpair_res_3370 = id_3371;
                    }
                    ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 let_res_3372;
                    {
                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dtup_514 { letpair_res_3370 };
                      ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 letpair_res_3373;
                      {
                        auto dtup_fst_515 { std::get<0>(dtup_514) };
                        auto dtup_snd_516 { std::get<1>(dtup_514) };
                        Size id_3374 { 0UL };
                        uint8_t id_3375 { dtup_snd_516.peekU8(id_3374) };
                        uint8_t id_3376 { 1 };
                        bool id_3377 { bool(id_3375 == id_3376) };
                        ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 choose_res_3378;
                        if (id_3377) {
                          std::optional<dessser::gen::raql_expr::t_ext> id_3379 { std::nullopt };
                          Size id_3380 { 1UL };
                          Pointer id_3381 { dtup_snd_516.skip(id_3380) };
                          ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_3382 { id_3379, id_3381 };
                          choose_res_3378 = id_3382;
                        } else {
                          auto fun3383 { dessser::gen::raql_expr::of_row_binary };
                          Size id_3384 { 1UL };
                          Pointer id_3385 { dtup_snd_516.skip(id_3384) };
                          ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3386 { fun3383(id_3385) };
                          ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 letpair_res_3387;
                          {
                            auto make1_1_fst_518 { std::get<0>(id_3386) };
                            auto make1_1_snd_519 { std::get<1>(id_3386) };
                            std::optional<dessser::gen::raql_expr::t_ext> id_3388 { make1_1_fst_518 };
                            ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_3389 { id_3388, make1_1_snd_519 };
                            letpair_res_3387 = id_3389;
                          }
                          choose_res_3378 = letpair_res_3387;
                        }
                        ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 let_res_3390;
                        {
                          ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 dtup_520 { choose_res_3378 };
                          ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 letpair_res_3391;
                          {
                            auto dtup_fst_521 { std::get<0>(dtup_520) };
                            auto dtup_snd_522 { std::get<1>(dtup_520) };
                            uint32_t id_3392 { 0U };
                            Vec<1, uint32_t> id_3393 {  id_3392  };
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3394;
                            {
                              Vec<1, uint32_t> leb_ref_523 { id_3393 };
                              uint8_t id_3395 { 0 };
                              Vec<1, uint8_t> id_3396 {  id_3395  };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3397;
                              {
                                Vec<1, uint8_t> shft_ref_524 { id_3396 };
                                Vec<1, Pointer> id_3398 {  dtup_snd_522  };
                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3399;
                                {
                                  Vec<1, Pointer> p_ref_525 { id_3398 };
                                  bool while_flag_3400 { true };
                                  do {
                                    uint8_t id_3401 { 0 };
                                    Pointer id_3402 { p_ref_525[id_3401] };
                                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3403 { id_3402.readU8() };
                                    bool let_res_3404;
                                    {
                                      ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_526 { id_3403 };
                                      bool letpair_res_3405;
                                      {
                                        auto leb128_fst_527 { std::get<0>(leb128_526) };
                                        auto leb128_snd_528 { std::get<1>(leb128_526) };
                                        uint8_t id_3406 { 0 };
                                        Void id_3407 { ((void)(p_ref_525[id_3406] = leb128_snd_528), ::dessser::VOID) };
                                        (void)id_3407;
                                        uint8_t id_3408 { 0 };
                                        uint8_t id_3409 { 127 };
                                        uint8_t id_3410 { uint8_t(leb128_fst_527 & id_3409) };
                                        uint32_t id_3411 { uint32_t(id_3410) };
                                        uint8_t id_3412 { 0 };
                                        uint8_t id_3413 { shft_ref_524[id_3412] };
                                        uint32_t id_3414 { uint32_t(id_3411 << id_3413) };
                                        uint8_t id_3415 { 0 };
                                        uint32_t id_3416 { leb_ref_523[id_3415] };
                                        uint32_t id_3417 { uint32_t(id_3414 | id_3416) };
                                        Void id_3418 { ((void)(leb_ref_523[id_3408] = id_3417), ::dessser::VOID) };
                                        (void)id_3418;
                                        uint8_t id_3419 { 0 };
                                        uint8_t id_3420 { 0 };
                                        uint8_t id_3421 { shft_ref_524[id_3420] };
                                        uint8_t id_3422 { 7 };
                                        uint8_t id_3423 { uint8_t(id_3421 + id_3422) };
                                        Void id_3424 { ((void)(shft_ref_524[id_3419] = id_3423), ::dessser::VOID) };
                                        (void)id_3424;
                                        uint8_t id_3425 { 128 };
                                        bool id_3426 { bool(leb128_fst_527 >= id_3425) };
                                        letpair_res_3405 = id_3426;
                                      }
                                      let_res_3404 = letpair_res_3405;
                                    }
                                    while_flag_3400 = let_res_3404;
                                    if (while_flag_3400) {
                                      (void)::dessser::VOID;
                                    }
                                  } while (while_flag_3400);
                                  (void)::dessser::VOID;
                                  uint8_t id_3427 { 0 };
                                  uint32_t id_3428 { leb_ref_523[id_3427] };
                                  uint8_t id_3429 { 0 };
                                  Pointer id_3430 { p_ref_525[id_3429] };
                                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3431 { id_3428, id_3430 };
                                  let_res_3399 = id_3431;
                                }
                                let_res_3397 = let_res_3399;
                              }
                              let_res_3394 = let_res_3397;
                            }
                            ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3432;
                            {
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_532 { let_res_3394 };
                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3433;
                              {
                                auto dlist1_fst_533 { std::get<0>(dlist1_532) };
                                auto dlist1_snd_534 { std::get<1>(dlist1_532) };
                                Lst<dessser::gen::raql_expr::t_ext> endoflist_3434;
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3435 { endoflist_3434, dlist1_snd_534 };
                                Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> id_3436 {  id_3435  };
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3437;
                                {
                                  Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> inits_src_ref_535 { id_3436 };
                                  int32_t id_3438 { 0L };
                                  Vec<1, int32_t> id_3439 {  id_3438  };
                                  {
                                    Vec<1, int32_t> repeat_n_536 { id_3439 };
                                    bool while_flag_3440 { true };
                                    do {
                                      int32_t id_3441 { int32_t(dlist1_fst_533) };
                                      uint8_t id_3442 { 0 };
                                      int32_t id_3443 { repeat_n_536[id_3442] };
                                      bool id_3444 { bool(id_3441 > id_3443) };
                                      while_flag_3440 = id_3444;
                                      if (while_flag_3440) {
                                        uint8_t id_3445 { 0 };
                                        ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3446 { inits_src_ref_535[id_3445] };
                                        {
                                          ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 dlist2_537 { id_3446 };
                                          {
                                            auto dlist2_fst_538 { std::get<0>(dlist2_537) };
                                            auto dlist2_snd_539 { std::get<1>(dlist2_537) };
                                            uint8_t id_3447 { 0 };
                                            auto fun3448 { dessser::gen::raql_expr::of_row_binary };
                                            ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3449 { fun3448(dlist2_snd_539) };
                                            ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3450;
                                            {
                                              auto dlist3_fst_541 { std::get<0>(id_3449) };
                                              auto dlist3_snd_542 { std::get<1>(id_3449) };
                                              Lst<dessser::gen::raql_expr::t_ext> id_3451 { dlist3_fst_541, dlist2_fst_538 };
                                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3452 { id_3451, dlist3_snd_542 };
                                              letpair_res_3450 = id_3452;
                                            }
                                            Void id_3453 { ((void)(inits_src_ref_535[id_3447] = letpair_res_3450), ::dessser::VOID) };
                                            (void)id_3453;
                                          }
                                          (void)::dessser::VOID;
                                        }
                                        (void)::dessser::VOID;
                                        uint8_t id_3454 { 0 };
                                        uint8_t id_3455 { 0 };
                                        int32_t id_3456 { repeat_n_536[id_3455] };
                                        int32_t id_3457 { 1L };
                                        int32_t id_3458 { int32_t(id_3456 + id_3457) };
                                        Void id_3459 { ((void)(repeat_n_536[id_3454] = id_3458), ::dessser::VOID) };
                                        (void)id_3459;
                                        (void)id_3459;
                                      }
                                    } while (while_flag_3440);
                                    (void)::dessser::VOID;
                                  }
                                  (void)::dessser::VOID;
                                  uint8_t id_3460 { 0 };
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3461 { inits_src_ref_535[id_3460] };
                                  let_res_3437 = id_3461;
                                }
                                letpair_res_3433 = let_res_3437;
                              }
                              let_res_3432 = letpair_res_3433;
                            }
                            ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 letpair_res_3462;
                            {
                              auto dlist4_fst_544 { std::get<0>(let_res_3432) };
                              auto dlist4_snd_545 { std::get<1>(let_res_3432) };
                              ::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07 id_3463 { dtup_fst_515, dtup_fst_521, dlist4_fst_544 };
                              std::optional<::dessser::gen::raql_operation::t75cceda8358977a4781ef44dda7fab07> id_3464 { id_3463 };
                              ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 id_3465 { id_3464, dlist4_snd_545 };
                              letpair_res_3462 = id_3465;
                            }
                            letpair_res_3391 = letpair_res_3462;
                          }
                          let_res_3390 = letpair_res_3391;
                        }
                        letpair_res_3373 = let_res_3390;
                      }
                      let_res_3372 = letpair_res_3373;
                    }
                    choose_res_3362 = let_res_3372;
                  }
                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3466;
                  {
                    ::dessser::gen::raql_operation::te8be0cdfe14de9667ee131ff8f8ccbc5 drec_552 { choose_res_3362 };
                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3467;
                    {
                      auto drec_fst_553 { std::get<0>(drec_552) };
                      auto drec_snd_554 { std::get<1>(drec_552) };
                      auto fun3468 { dessser::gen::raql_expr::of_row_binary };
                      ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3469 { fun3468(drec_snd_554) };
                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3470;
                      {
                        ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_555 { id_3469 };
                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3471;
                        {
                          auto drec_fst_556 { std::get<0>(drec_555) };
                          auto drec_snd_557 { std::get<1>(drec_555) };
                          Size id_3472 { 0UL };
                          uint8_t id_3473 { drec_snd_557.peekU8(id_3472) };
                          uint8_t id_3474 { 1 };
                          bool id_3475 { bool(id_3473 == id_3474) };
                          ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 choose_res_3476;
                          if (id_3475) {
                            std::optional<dessser::gen::event_time::t_ext> id_3477 { std::nullopt };
                            Size id_3478 { 1UL };
                            Pointer id_3479 { drec_snd_557.skip(id_3478) };
                            ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 id_3480 { id_3477, id_3479 };
                            choose_res_3476 = id_3480;
                          } else {
                            auto fun3481 { dessser::gen::event_time::of_row_binary };
                            Size id_3482 { 1UL };
                            Pointer id_3483 { drec_snd_557.skip(id_3482) };
                            ::dessser::gen::raql_operation::t6402d827f30fdf794bf052c6e2db3344 id_3484 { fun3481(id_3483) };
                            ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 letpair_res_3485;
                            {
                              auto make1_1_fst_559 { std::get<0>(id_3484) };
                              auto make1_1_snd_560 { std::get<1>(id_3484) };
                              std::optional<dessser::gen::event_time::t_ext> id_3486 { make1_1_fst_559 };
                              ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 id_3487 { id_3486, make1_1_snd_560 };
                              letpair_res_3485 = id_3487;
                            }
                            choose_res_3476 = letpair_res_3485;
                          }
                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3488;
                          {
                            ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 drec_561 { choose_res_3476 };
                            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3489;
                            {
                              auto drec_fst_562 { std::get<0>(drec_561) };
                              auto drec_snd_563 { std::get<1>(drec_561) };
                              uint32_t id_3490 { 0U };
                              Vec<1, uint32_t> id_3491 {  id_3490  };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3492;
                              {
                                Vec<1, uint32_t> leb_ref_564 { id_3491 };
                                uint8_t id_3493 { 0 };
                                Vec<1, uint8_t> id_3494 {  id_3493  };
                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3495;
                                {
                                  Vec<1, uint8_t> shft_ref_565 { id_3494 };
                                  Vec<1, Pointer> id_3496 {  drec_snd_563  };
                                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3497;
                                  {
                                    Vec<1, Pointer> p_ref_566 { id_3496 };
                                    bool while_flag_3498 { true };
                                    do {
                                      uint8_t id_3499 { 0 };
                                      Pointer id_3500 { p_ref_566[id_3499] };
                                      ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3501 { id_3500.readU8() };
                                      bool let_res_3502;
                                      {
                                        ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_567 { id_3501 };
                                        bool letpair_res_3503;
                                        {
                                          auto leb128_fst_568 { std::get<0>(leb128_567) };
                                          auto leb128_snd_569 { std::get<1>(leb128_567) };
                                          uint8_t id_3504 { 0 };
                                          Void id_3505 { ((void)(p_ref_566[id_3504] = leb128_snd_569), ::dessser::VOID) };
                                          (void)id_3505;
                                          uint8_t id_3506 { 0 };
                                          uint8_t id_3507 { 127 };
                                          uint8_t id_3508 { uint8_t(leb128_fst_568 & id_3507) };
                                          uint32_t id_3509 { uint32_t(id_3508) };
                                          uint8_t id_3510 { 0 };
                                          uint8_t id_3511 { shft_ref_565[id_3510] };
                                          uint32_t id_3512 { uint32_t(id_3509 << id_3511) };
                                          uint8_t id_3513 { 0 };
                                          uint32_t id_3514 { leb_ref_564[id_3513] };
                                          uint32_t id_3515 { uint32_t(id_3512 | id_3514) };
                                          Void id_3516 { ((void)(leb_ref_564[id_3506] = id_3515), ::dessser::VOID) };
                                          (void)id_3516;
                                          uint8_t id_3517 { 0 };
                                          uint8_t id_3518 { 0 };
                                          uint8_t id_3519 { shft_ref_565[id_3518] };
                                          uint8_t id_3520 { 7 };
                                          uint8_t id_3521 { uint8_t(id_3519 + id_3520) };
                                          Void id_3522 { ((void)(shft_ref_565[id_3517] = id_3521), ::dessser::VOID) };
                                          (void)id_3522;
                                          uint8_t id_3523 { 128 };
                                          bool id_3524 { bool(leb128_fst_568 >= id_3523) };
                                          letpair_res_3503 = id_3524;
                                        }
                                        let_res_3502 = letpair_res_3503;
                                      }
                                      while_flag_3498 = let_res_3502;
                                      if (while_flag_3498) {
                                        (void)::dessser::VOID;
                                      }
                                    } while (while_flag_3498);
                                    (void)::dessser::VOID;
                                    uint8_t id_3525 { 0 };
                                    uint32_t id_3526 { leb_ref_564[id_3525] };
                                    uint8_t id_3527 { 0 };
                                    Pointer id_3528 { p_ref_566[id_3527] };
                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3529 { id_3526, id_3528 };
                                    let_res_3497 = id_3529;
                                  }
                                  let_res_3495 = let_res_3497;
                                }
                                let_res_3492 = let_res_3495;
                              }
                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3530;
                              {
                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_573 { let_res_3492 };
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3531;
                                {
                                  auto dlist1_fst_574 { std::get<0>(dlist1_573) };
                                  auto dlist1_snd_575 { std::get<1>(dlist1_573) };
                                  Lst<dessser::gen::raql_expr::t_ext> endoflist_3532;
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3533 { endoflist_3532, dlist1_snd_575 };
                                  Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> id_3534 {  id_3533  };
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3535;
                                  {
                                    Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> inits_src_ref_576 { id_3534 };
                                    int32_t id_3536 { 0L };
                                    Vec<1, int32_t> id_3537 {  id_3536  };
                                    {
                                      Vec<1, int32_t> repeat_n_577 { id_3537 };
                                      bool while_flag_3538 { true };
                                      do {
                                        int32_t id_3539 { int32_t(dlist1_fst_574) };
                                        uint8_t id_3540 { 0 };
                                        int32_t id_3541 { repeat_n_577[id_3540] };
                                        bool id_3542 { bool(id_3539 > id_3541) };
                                        while_flag_3538 = id_3542;
                                        if (while_flag_3538) {
                                          uint8_t id_3543 { 0 };
                                          ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3544 { inits_src_ref_576[id_3543] };
                                          {
                                            ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 dlist2_578 { id_3544 };
                                            {
                                              auto dlist2_fst_579 { std::get<0>(dlist2_578) };
                                              auto dlist2_snd_580 { std::get<1>(dlist2_578) };
                                              uint8_t id_3545 { 0 };
                                              auto fun3546 { dessser::gen::raql_expr::of_row_binary };
                                              ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3547 { fun3546(dlist2_snd_580) };
                                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3548;
                                              {
                                                auto dlist3_fst_582 { std::get<0>(id_3547) };
                                                auto dlist3_snd_583 { std::get<1>(id_3547) };
                                                Lst<dessser::gen::raql_expr::t_ext> id_3549 { dlist3_fst_582, dlist2_fst_579 };
                                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3550 { id_3549, dlist3_snd_583 };
                                                letpair_res_3548 = id_3550;
                                              }
                                              Void id_3551 { ((void)(inits_src_ref_576[id_3545] = letpair_res_3548), ::dessser::VOID) };
                                              (void)id_3551;
                                            }
                                            (void)::dessser::VOID;
                                          }
                                          (void)::dessser::VOID;
                                          uint8_t id_3552 { 0 };
                                          uint8_t id_3553 { 0 };
                                          int32_t id_3554 { repeat_n_577[id_3553] };
                                          int32_t id_3555 { 1L };
                                          int32_t id_3556 { int32_t(id_3554 + id_3555) };
                                          Void id_3557 { ((void)(repeat_n_577[id_3552] = id_3556), ::dessser::VOID) };
                                          (void)id_3557;
                                          (void)id_3557;
                                        }
                                      } while (while_flag_3538);
                                      (void)::dessser::VOID;
                                    }
                                    (void)::dessser::VOID;
                                    uint8_t id_3558 { 0 };
                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3559 { inits_src_ref_576[id_3558] };
                                    let_res_3535 = id_3559;
                                  }
                                  letpair_res_3531 = let_res_3535;
                                }
                                let_res_3530 = letpair_res_3531;
                              }
                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3560;
                              {
                                auto dlist4_fst_585 { std::get<0>(let_res_3530) };
                                auto dlist4_snd_586 { std::get<1>(let_res_3530) };
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3561 { dlist4_fst_585, dlist4_snd_586 };
                                letpair_res_3560 = id_3561;
                              }
                              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3562;
                              {
                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 drec_587 { letpair_res_3560 };
                                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3563;
                                {
                                  auto drec_fst_588 { std::get<0>(drec_587) };
                                  auto drec_snd_589 { std::get<1>(drec_587) };
                                  uint32_t id_3564 { 0U };
                                  Vec<1, uint32_t> id_3565 {  id_3564  };
                                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3566;
                                  {
                                    Vec<1, uint32_t> leb_ref_590 { id_3565 };
                                    uint8_t id_3567 { 0 };
                                    Vec<1, uint8_t> id_3568 {  id_3567  };
                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3569;
                                    {
                                      Vec<1, uint8_t> shft_ref_591 { id_3568 };
                                      Vec<1, Pointer> id_3570 {  drec_snd_589  };
                                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3571;
                                      {
                                        Vec<1, Pointer> p_ref_592 { id_3570 };
                                        bool while_flag_3572 { true };
                                        do {
                                          uint8_t id_3573 { 0 };
                                          Pointer id_3574 { p_ref_592[id_3573] };
                                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3575 { id_3574.readU8() };
                                          bool let_res_3576;
                                          {
                                            ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_593 { id_3575 };
                                            bool letpair_res_3577;
                                            {
                                              auto leb128_fst_594 { std::get<0>(leb128_593) };
                                              auto leb128_snd_595 { std::get<1>(leb128_593) };
                                              uint8_t id_3578 { 0 };
                                              Void id_3579 { ((void)(p_ref_592[id_3578] = leb128_snd_595), ::dessser::VOID) };
                                              (void)id_3579;
                                              uint8_t id_3580 { 0 };
                                              uint8_t id_3581 { 127 };
                                              uint8_t id_3582 { uint8_t(leb128_fst_594 & id_3581) };
                                              uint32_t id_3583 { uint32_t(id_3582) };
                                              uint8_t id_3584 { 0 };
                                              uint8_t id_3585 { shft_ref_591[id_3584] };
                                              uint32_t id_3586 { uint32_t(id_3583 << id_3585) };
                                              uint8_t id_3587 { 0 };
                                              uint32_t id_3588 { leb_ref_590[id_3587] };
                                              uint32_t id_3589 { uint32_t(id_3586 | id_3588) };
                                              Void id_3590 { ((void)(leb_ref_590[id_3580] = id_3589), ::dessser::VOID) };
                                              (void)id_3590;
                                              uint8_t id_3591 { 0 };
                                              uint8_t id_3592 { 0 };
                                              uint8_t id_3593 { shft_ref_591[id_3592] };
                                              uint8_t id_3594 { 7 };
                                              uint8_t id_3595 { uint8_t(id_3593 + id_3594) };
                                              Void id_3596 { ((void)(shft_ref_591[id_3591] = id_3595), ::dessser::VOID) };
                                              (void)id_3596;
                                              uint8_t id_3597 { 128 };
                                              bool id_3598 { bool(leb128_fst_594 >= id_3597) };
                                              letpair_res_3577 = id_3598;
                                            }
                                            let_res_3576 = letpair_res_3577;
                                          }
                                          while_flag_3572 = let_res_3576;
                                          if (while_flag_3572) {
                                            (void)::dessser::VOID;
                                          }
                                        } while (while_flag_3572);
                                        (void)::dessser::VOID;
                                        uint8_t id_3599 { 0 };
                                        uint32_t id_3600 { leb_ref_590[id_3599] };
                                        uint8_t id_3601 { 0 };
                                        Pointer id_3602 { p_ref_592[id_3601] };
                                        ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3603 { id_3600, id_3602 };
                                        let_res_3571 = id_3603;
                                      }
                                      let_res_3569 = let_res_3571;
                                    }
                                    let_res_3566 = let_res_3569;
                                  }
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3604;
                                  {
                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_599 { let_res_3566 };
                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3605;
                                    {
                                      auto dlist1_fst_600 { std::get<0>(dlist1_599) };
                                      auto dlist1_snd_601 { std::get<1>(dlist1_599) };
                                      Lst<dessser::gen::raql_expr::t_ext> endoflist_3606;
                                      ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3607 { endoflist_3606, dlist1_snd_601 };
                                      Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> id_3608 {  id_3607  };
                                      ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 let_res_3609;
                                      {
                                        Vec<1, ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583> inits_src_ref_602 { id_3608 };
                                        int32_t id_3610 { 0L };
                                        Vec<1, int32_t> id_3611 {  id_3610  };
                                        {
                                          Vec<1, int32_t> repeat_n_603 { id_3611 };
                                          bool while_flag_3612 { true };
                                          do {
                                            int32_t id_3613 { int32_t(dlist1_fst_600) };
                                            uint8_t id_3614 { 0 };
                                            int32_t id_3615 { repeat_n_603[id_3614] };
                                            bool id_3616 { bool(id_3613 > id_3615) };
                                            while_flag_3612 = id_3616;
                                            if (while_flag_3612) {
                                              uint8_t id_3617 { 0 };
                                              ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3618 { inits_src_ref_602[id_3617] };
                                              {
                                                ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 dlist2_604 { id_3618 };
                                                {
                                                  auto dlist2_fst_605 { std::get<0>(dlist2_604) };
                                                  auto dlist2_snd_606 { std::get<1>(dlist2_604) };
                                                  uint8_t id_3619 { 0 };
                                                  auto fun3620 { dessser::gen::raql_expr::of_row_binary };
                                                  ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3621 { fun3620(dlist2_snd_606) };
                                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3622;
                                                  {
                                                    auto dlist3_fst_608 { std::get<0>(id_3621) };
                                                    auto dlist3_snd_609 { std::get<1>(id_3621) };
                                                    Lst<dessser::gen::raql_expr::t_ext> id_3623 { dlist3_fst_608, dlist2_fst_605 };
                                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3624 { id_3623, dlist3_snd_609 };
                                                    letpair_res_3622 = id_3624;
                                                  }
                                                  Void id_3625 { ((void)(inits_src_ref_602[id_3619] = letpair_res_3622), ::dessser::VOID) };
                                                  (void)id_3625;
                                                }
                                                (void)::dessser::VOID;
                                              }
                                              (void)::dessser::VOID;
                                              uint8_t id_3626 { 0 };
                                              uint8_t id_3627 { 0 };
                                              int32_t id_3628 { repeat_n_603[id_3627] };
                                              int32_t id_3629 { 1L };
                                              int32_t id_3630 { int32_t(id_3628 + id_3629) };
                                              Void id_3631 { ((void)(repeat_n_603[id_3626] = id_3630), ::dessser::VOID) };
                                              (void)id_3631;
                                              (void)id_3631;
                                            }
                                          } while (while_flag_3612);
                                          (void)::dessser::VOID;
                                        }
                                        (void)::dessser::VOID;
                                        uint8_t id_3632 { 0 };
                                        ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3633 { inits_src_ref_602[id_3632] };
                                        let_res_3609 = id_3633;
                                      }
                                      letpair_res_3605 = let_res_3609;
                                    }
                                    let_res_3604 = letpair_res_3605;
                                  }
                                  ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 letpair_res_3634;
                                  {
                                    auto dlist4_fst_611 { std::get<0>(let_res_3604) };
                                    auto dlist4_snd_612 { std::get<1>(let_res_3604) };
                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 id_3635 { dlist4_fst_611, dlist4_snd_612 };
                                    letpair_res_3634 = id_3635;
                                  }
                                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3636;
                                  {
                                    ::dessser::gen::raql_operation::tc75358d1d8abf9ae364b723c583ed583 drec_613 { letpair_res_3634 };
                                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3637;
                                    {
                                      auto drec_fst_614 { std::get<0>(drec_613) };
                                      auto drec_snd_615 { std::get<1>(drec_613) };
                                      auto fun3638 { dessser::gen::raql_expr::of_row_binary };
                                      ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3639 { fun3638(drec_snd_615) };
                                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3640;
                                      {
                                        ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 drec_616 { id_3639 };
                                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3641;
                                        {
                                          auto drec_fst_617 { std::get<0>(drec_616) };
                                          auto drec_snd_618 { std::get<1>(drec_616) };
                                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3642 { drec_snd_618.readU8() };
                                          ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_3643;
                                          {
                                            auto dbool_fst_620 { std::get<0>(id_3642) };
                                            auto dbool_snd_621 { std::get<1>(id_3642) };
                                            uint8_t id_3644 { 0 };
                                            bool id_3645 { bool(dbool_fst_620 == id_3644) };
                                            bool id_3646 { ! id_3645 };
                                            ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 id_3647 { id_3646, dbool_snd_621 };
                                            letpair_res_3643 = id_3647;
                                          }
                                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3648;
                                          {
                                            ::dessser::gen::raql_operation::tf9a0a3fefc87c9e10a93d3a172850c26 drec_622 { letpair_res_3643 };
                                            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3649;
                                            {
                                              auto drec_fst_623 { std::get<0>(drec_622) };
                                              auto drec_snd_624 { std::get<1>(drec_622) };
                                              auto fun3650 { dessser::gen::raql_flush_method::of_row_binary };
                                              ::dessser::gen::raql_operation::t810ce2c2364cf512ac90f670b999da7d id_3651 { fun3650(drec_snd_624) };
                                              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3652;
                                              {
                                                ::dessser::gen::raql_operation::t810ce2c2364cf512ac90f670b999da7d drec_625 { id_3651 };
                                                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3653;
                                                {
                                                  auto drec_fst_626 { std::get<0>(drec_625) };
                                                  auto drec_snd_627 { std::get<1>(drec_625) };
                                                  uint32_t id_3654 { 0U };
                                                  Vec<1, uint32_t> id_3655 {  id_3654  };
                                                  ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3656;
                                                  {
                                                    Vec<1, uint32_t> leb_ref_628 { id_3655 };
                                                    uint8_t id_3657 { 0 };
                                                    Vec<1, uint8_t> id_3658 {  id_3657  };
                                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3659;
                                                    {
                                                      Vec<1, uint8_t> shft_ref_629 { id_3658 };
                                                      Vec<1, Pointer> id_3660 {  drec_snd_627  };
                                                      ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3661;
                                                      {
                                                        Vec<1, Pointer> p_ref_630 { id_3660 };
                                                        bool while_flag_3662 { true };
                                                        do {
                                                          uint8_t id_3663 { 0 };
                                                          Pointer id_3664 { p_ref_630[id_3663] };
                                                          ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3665 { id_3664.readU8() };
                                                          bool let_res_3666;
                                                          {
                                                            ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_631 { id_3665 };
                                                            bool letpair_res_3667;
                                                            {
                                                              auto leb128_fst_632 { std::get<0>(leb128_631) };
                                                              auto leb128_snd_633 { std::get<1>(leb128_631) };
                                                              uint8_t id_3668 { 0 };
                                                              Void id_3669 { ((void)(p_ref_630[id_3668] = leb128_snd_633), ::dessser::VOID) };
                                                              (void)id_3669;
                                                              uint8_t id_3670 { 0 };
                                                              uint8_t id_3671 { 127 };
                                                              uint8_t id_3672 { uint8_t(leb128_fst_632 & id_3671) };
                                                              uint32_t id_3673 { uint32_t(id_3672) };
                                                              uint8_t id_3674 { 0 };
                                                              uint8_t id_3675 { shft_ref_629[id_3674] };
                                                              uint32_t id_3676 { uint32_t(id_3673 << id_3675) };
                                                              uint8_t id_3677 { 0 };
                                                              uint32_t id_3678 { leb_ref_628[id_3677] };
                                                              uint32_t id_3679 { uint32_t(id_3676 | id_3678) };
                                                              Void id_3680 { ((void)(leb_ref_628[id_3670] = id_3679), ::dessser::VOID) };
                                                              (void)id_3680;
                                                              uint8_t id_3681 { 0 };
                                                              uint8_t id_3682 { 0 };
                                                              uint8_t id_3683 { shft_ref_629[id_3682] };
                                                              uint8_t id_3684 { 7 };
                                                              uint8_t id_3685 { uint8_t(id_3683 + id_3684) };
                                                              Void id_3686 { ((void)(shft_ref_629[id_3681] = id_3685), ::dessser::VOID) };
                                                              (void)id_3686;
                                                              uint8_t id_3687 { 128 };
                                                              bool id_3688 { bool(leb128_fst_632 >= id_3687) };
                                                              letpair_res_3667 = id_3688;
                                                            }
                                                            let_res_3666 = letpair_res_3667;
                                                          }
                                                          while_flag_3662 = let_res_3666;
                                                          if (while_flag_3662) {
                                                            (void)::dessser::VOID;
                                                          }
                                                        } while (while_flag_3662);
                                                        (void)::dessser::VOID;
                                                        uint8_t id_3689 { 0 };
                                                        uint32_t id_3690 { leb_ref_628[id_3689] };
                                                        uint8_t id_3691 { 0 };
                                                        Pointer id_3692 { p_ref_630[id_3691] };
                                                        ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3693 { id_3690, id_3692 };
                                                        let_res_3661 = id_3693;
                                                      }
                                                      let_res_3659 = let_res_3661;
                                                    }
                                                    let_res_3656 = let_res_3659;
                                                  }
                                                  ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 let_res_3694;
                                                  {
                                                    ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_637 { let_res_3656 };
                                                    ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 letpair_res_3695;
                                                    {
                                                      auto dlist1_fst_638 { std::get<0>(dlist1_637) };
                                                      auto dlist1_snd_639 { std::get<1>(dlist1_637) };
                                                      Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> > endoflist_3696;
                                                      ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 id_3697 { endoflist_3696, dlist1_snd_639 };
                                                      Vec<1, ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9> id_3698 {  id_3697  };
                                                      ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 let_res_3699;
                                                      {
                                                        Vec<1, ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9> inits_src_ref_640 { id_3698 };
                                                        int32_t id_3700 { 0L };
                                                        Vec<1, int32_t> id_3701 {  id_3700  };
                                                        {
                                                          Vec<1, int32_t> repeat_n_641 { id_3701 };
                                                          bool while_flag_3702 { true };
                                                          do {
                                                            int32_t id_3703 { int32_t(dlist1_fst_638) };
                                                            uint8_t id_3704 { 0 };
                                                            int32_t id_3705 { repeat_n_641[id_3704] };
                                                            bool id_3706 { bool(id_3703 > id_3705) };
                                                            while_flag_3702 = id_3706;
                                                            if (while_flag_3702) {
                                                              uint8_t id_3707 { 0 };
                                                              ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 id_3708 { inits_src_ref_640[id_3707] };
                                                              {
                                                                ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 dlist2_642 { id_3708 };
                                                                {
                                                                  auto dlist2_fst_643 { std::get<0>(dlist2_642) };
                                                                  auto dlist2_snd_644 { std::get<1>(dlist2_642) };
                                                                  uint8_t id_3709 { 0 };
                                                                  ::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681 id_3710 { data_source_of_row_binary(dlist2_snd_644) };
                                                                  ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 letpair_res_3711;
                                                                  {
                                                                    auto dlist3_fst_646 { std::get<0>(id_3710) };
                                                                    auto dlist3_snd_647 { std::get<1>(id_3710) };
                                                                    Lst<std::shared_ptr<::dessser::gen::raql_operation::data_source> > id_3712 { dlist3_fst_646, dlist2_fst_643 };
                                                                    ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 id_3713 { id_3712, dlist3_snd_647 };
                                                                    letpair_res_3711 = id_3713;
                                                                  }
                                                                  Void id_3714 { ((void)(inits_src_ref_640[id_3709] = letpair_res_3711), ::dessser::VOID) };
                                                                  (void)id_3714;
                                                                }
                                                                (void)::dessser::VOID;
                                                              }
                                                              (void)::dessser::VOID;
                                                              uint8_t id_3715 { 0 };
                                                              uint8_t id_3716 { 0 };
                                                              int32_t id_3717 { repeat_n_641[id_3716] };
                                                              int32_t id_3718 { 1L };
                                                              int32_t id_3719 { int32_t(id_3717 + id_3718) };
                                                              Void id_3720 { ((void)(repeat_n_641[id_3715] = id_3719), ::dessser::VOID) };
                                                              (void)id_3720;
                                                              (void)id_3720;
                                                            }
                                                          } while (while_flag_3702);
                                                          (void)::dessser::VOID;
                                                        }
                                                        (void)::dessser::VOID;
                                                        uint8_t id_3721 { 0 };
                                                        ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 id_3722 { inits_src_ref_640[id_3721] };
                                                        let_res_3699 = id_3722;
                                                      }
                                                      letpair_res_3695 = let_res_3699;
                                                    }
                                                    let_res_3694 = letpair_res_3695;
                                                  }
                                                  ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 letpair_res_3723;
                                                  {
                                                    auto dlist4_fst_649 { std::get<0>(let_res_3694) };
                                                    auto dlist4_snd_650 { std::get<1>(let_res_3694) };
                                                    ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 id_3724 { dlist4_fst_649, dlist4_snd_650 };
                                                    letpair_res_3723 = id_3724;
                                                  }
                                                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3725;
                                                  {
                                                    ::dessser::gen::raql_operation::t397ac070d450160cc53ed25cc12147c9 drec_651 { letpair_res_3723 };
                                                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3726;
                                                    {
                                                      auto drec_fst_652 { std::get<0>(drec_651) };
                                                      auto drec_snd_653 { std::get<1>(drec_651) };
                                                      Size id_3727 { 0UL };
                                                      uint8_t id_3728 { drec_snd_653.peekU8(id_3727) };
                                                      uint8_t id_3729 { 1 };
                                                      bool id_3730 { bool(id_3728 == id_3729) };
                                                      ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 choose_res_3731;
                                                      if (id_3730) {
                                                        std::optional<dessser::gen::raql_expr::t_ext> id_3732 { std::nullopt };
                                                        Size id_3733 { 1UL };
                                                        Pointer id_3734 { drec_snd_653.skip(id_3733) };
                                                        ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_3735 { id_3732, id_3734 };
                                                        choose_res_3731 = id_3735;
                                                      } else {
                                                        auto fun3736 { dessser::gen::raql_expr::of_row_binary };
                                                        Size id_3737 { 1UL };
                                                        Pointer id_3738 { drec_snd_653.skip(id_3737) };
                                                        ::dessser::gen::raql_operation::tc473a3a3b5068e57b15e934d0afcc038 id_3739 { fun3736(id_3738) };
                                                        ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 letpair_res_3740;
                                                        {
                                                          auto make1_1_fst_655 { std::get<0>(id_3739) };
                                                          auto make1_1_snd_656 { std::get<1>(id_3739) };
                                                          std::optional<dessser::gen::raql_expr::t_ext> id_3741 { make1_1_fst_655 };
                                                          ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 id_3742 { id_3741, make1_1_snd_656 };
                                                          letpair_res_3740 = id_3742;
                                                        }
                                                        choose_res_3731 = letpair_res_3740;
                                                      }
                                                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3743;
                                                      {
                                                        ::dessser::gen::raql_operation::tffcb9977d856d30366202f1b8eb57823 drec_657 { choose_res_3731 };
                                                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3744;
                                                        {
                                                          auto drec_fst_658 { std::get<0>(drec_657) };
                                                          auto drec_snd_659 { std::get<1>(drec_657) };
                                                          uint32_t id_3745 { 0U };
                                                          Vec<1, uint32_t> id_3746 {  id_3745  };
                                                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3747;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_660 { id_3746 };
                                                            uint8_t id_3748 { 0 };
                                                            Vec<1, uint8_t> id_3749 {  id_3748  };
                                                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3750;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_661 { id_3749 };
                                                              Vec<1, Pointer> id_3751 {  drec_snd_659  };
                                                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3752;
                                                              {
                                                                Vec<1, Pointer> p_ref_662 { id_3751 };
                                                                bool while_flag_3753 { true };
                                                                do {
                                                                  uint8_t id_3754 { 0 };
                                                                  Pointer id_3755 { p_ref_662[id_3754] };
                                                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3756 { id_3755.readU8() };
                                                                  bool let_res_3757;
                                                                  {
                                                                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_663 { id_3756 };
                                                                    bool letpair_res_3758;
                                                                    {
                                                                      auto leb128_fst_664 { std::get<0>(leb128_663) };
                                                                      auto leb128_snd_665 { std::get<1>(leb128_663) };
                                                                      uint8_t id_3759 { 0 };
                                                                      Void id_3760 { ((void)(p_ref_662[id_3759] = leb128_snd_665), ::dessser::VOID) };
                                                                      (void)id_3760;
                                                                      uint8_t id_3761 { 0 };
                                                                      uint8_t id_3762 { 127 };
                                                                      uint8_t id_3763 { uint8_t(leb128_fst_664 & id_3762) };
                                                                      uint32_t id_3764 { uint32_t(id_3763) };
                                                                      uint8_t id_3765 { 0 };
                                                                      uint8_t id_3766 { shft_ref_661[id_3765] };
                                                                      uint32_t id_3767 { uint32_t(id_3764 << id_3766) };
                                                                      uint8_t id_3768 { 0 };
                                                                      uint32_t id_3769 { leb_ref_660[id_3768] };
                                                                      uint32_t id_3770 { uint32_t(id_3767 | id_3769) };
                                                                      Void id_3771 { ((void)(leb_ref_660[id_3761] = id_3770), ::dessser::VOID) };
                                                                      (void)id_3771;
                                                                      uint8_t id_3772 { 0 };
                                                                      uint8_t id_3773 { 0 };
                                                                      uint8_t id_3774 { shft_ref_661[id_3773] };
                                                                      uint8_t id_3775 { 7 };
                                                                      uint8_t id_3776 { uint8_t(id_3774 + id_3775) };
                                                                      Void id_3777 { ((void)(shft_ref_661[id_3772] = id_3776), ::dessser::VOID) };
                                                                      (void)id_3777;
                                                                      uint8_t id_3778 { 128 };
                                                                      bool id_3779 { bool(leb128_fst_664 >= id_3778) };
                                                                      letpair_res_3758 = id_3779;
                                                                    }
                                                                    let_res_3757 = letpair_res_3758;
                                                                  }
                                                                  while_flag_3753 = let_res_3757;
                                                                  if (while_flag_3753) {
                                                                    (void)::dessser::VOID;
                                                                  }
                                                                } while (while_flag_3753);
                                                                (void)::dessser::VOID;
                                                                uint8_t id_3780 { 0 };
                                                                uint32_t id_3781 { leb_ref_660[id_3780] };
                                                                uint8_t id_3782 { 0 };
                                                                Pointer id_3783 { p_ref_662[id_3782] };
                                                                ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3784 { id_3781, id_3783 };
                                                                let_res_3752 = id_3784;
                                                              }
                                                              let_res_3750 = let_res_3752;
                                                            }
                                                            let_res_3747 = let_res_3750;
                                                          }
                                                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3785;
                                                          {
                                                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_669 { let_res_3747 };
                                                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3786;
                                                            {
                                                              auto dlist1_fst_670 { std::get<0>(dlist1_669) };
                                                              auto dlist1_snd_671 { std::get<1>(dlist1_669) };
                                                              Lst<dessser::gen::field_name::t_ext> endoflist_3787;
                                                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3788 { endoflist_3787, dlist1_snd_671 };
                                                              Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_3789 {  id_3788  };
                                                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3790;
                                                              {
                                                                Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_672 { id_3789 };
                                                                int32_t id_3791 { 0L };
                                                                Vec<1, int32_t> id_3792 {  id_3791  };
                                                                {
                                                                  Vec<1, int32_t> repeat_n_673 { id_3792 };
                                                                  bool while_flag_3793 { true };
                                                                  do {
                                                                    int32_t id_3794 { int32_t(dlist1_fst_670) };
                                                                    uint8_t id_3795 { 0 };
                                                                    int32_t id_3796 { repeat_n_673[id_3795] };
                                                                    bool id_3797 { bool(id_3794 > id_3796) };
                                                                    while_flag_3793 = id_3797;
                                                                    if (while_flag_3793) {
                                                                      uint8_t id_3798 { 0 };
                                                                      ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3799 { inits_src_ref_672[id_3798] };
                                                                      {
                                                                        ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_674 { id_3799 };
                                                                        {
                                                                          auto dlist2_fst_675 { std::get<0>(dlist2_674) };
                                                                          auto dlist2_snd_676 { std::get<1>(dlist2_674) };
                                                                          uint8_t id_3800 { 0 };
                                                                          auto fun3801 { dessser::gen::field_name::of_row_binary };
                                                                          ::dessser::gen::raql_operation::t18cecf882d7ac80cef37dfe6b22279d4 id_3802 { fun3801(dlist2_snd_676) };
                                                                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3803;
                                                                          {
                                                                            auto dlist3_fst_678 { std::get<0>(id_3802) };
                                                                            auto dlist3_snd_679 { std::get<1>(id_3802) };
                                                                            Lst<dessser::gen::field_name::t_ext> id_3804 { dlist3_fst_678, dlist2_fst_675 };
                                                                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3805 { id_3804, dlist3_snd_679 };
                                                                            letpair_res_3803 = id_3805;
                                                                          }
                                                                          Void id_3806 { ((void)(inits_src_ref_672[id_3800] = letpair_res_3803), ::dessser::VOID) };
                                                                          (void)id_3806;
                                                                        }
                                                                        (void)::dessser::VOID;
                                                                      }
                                                                      (void)::dessser::VOID;
                                                                      uint8_t id_3807 { 0 };
                                                                      uint8_t id_3808 { 0 };
                                                                      int32_t id_3809 { repeat_n_673[id_3808] };
                                                                      int32_t id_3810 { 1L };
                                                                      int32_t id_3811 { int32_t(id_3809 + id_3810) };
                                                                      Void id_3812 { ((void)(repeat_n_673[id_3807] = id_3811), ::dessser::VOID) };
                                                                      (void)id_3812;
                                                                      (void)id_3812;
                                                                    }
                                                                  } while (while_flag_3793);
                                                                  (void)::dessser::VOID;
                                                                }
                                                                (void)::dessser::VOID;
                                                                uint8_t id_3813 { 0 };
                                                                ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3814 { inits_src_ref_672[id_3813] };
                                                                let_res_3790 = id_3814;
                                                              }
                                                              letpair_res_3786 = let_res_3790;
                                                            }
                                                            let_res_3785 = letpair_res_3786;
                                                          }
                                                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3815;
                                                          {
                                                            auto dlist4_fst_681 { std::get<0>(let_res_3785) };
                                                            auto dlist4_snd_682 { std::get<1>(let_res_3785) };
                                                            ::dessser::gen::raql_operation::t2924eb63c15624d94238446da8ddd5a5 id_3816 { drec_fst_509, drec_fst_623, drec_fst_617, drec_fst_562, drec_fst_658, dlist4_fst_681, drec_fst_480, drec_fst_626, drec_fst_652, drec_fst_614, drec_fst_588, drec_fst_553, drec_fst_556 };
                                                            std::shared_ptr<::dessser::gen::raql_operation::t>  id_3817 { std::make_shared<::dessser::gen::raql_operation::t>(std::in_place_index<0>, id_3816) };
                                                            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3818 { id_3817, dlist4_snd_682 };
                                                            letpair_res_3815 = id_3818;
                                                          }
                                                          letpair_res_3744 = letpair_res_3815;
                                                        }
                                                        let_res_3743 = letpair_res_3744;
                                                      }
                                                      letpair_res_3726 = let_res_3743;
                                                    }
                                                    let_res_3725 = letpair_res_3726;
                                                  }
                                                  letpair_res_3653 = let_res_3725;
                                                }
                                                let_res_3652 = letpair_res_3653;
                                              }
                                              letpair_res_3649 = let_res_3652;
                                            }
                                            let_res_3648 = letpair_res_3649;
                                          }
                                          letpair_res_3641 = let_res_3648;
                                        }
                                        let_res_3640 = letpair_res_3641;
                                      }
                                      letpair_res_3637 = let_res_3640;
                                    }
                                    let_res_3636 = letpair_res_3637;
                                  }
                                  letpair_res_3563 = let_res_3636;
                                }
                                let_res_3562 = letpair_res_3563;
                              }
                              letpair_res_3489 = let_res_3562;
                            }
                            let_res_3488 = letpair_res_3489;
                          }
                          letpair_res_3471 = let_res_3488;
                        }
                        let_res_3470 = letpair_res_3471;
                      }
                      letpair_res_3467 = let_res_3470;
                    }
                    let_res_3466 = letpair_res_3467;
                  }
                  letpair_res_3357 = let_res_3466;
                }
                let_res_3356 = letpair_res_3357;
              }
              letpair_res_3271 = let_res_3356;
            }
            let_res_3270 = letpair_res_3271;
          }
          choose_res_3197 = let_res_3270;
        } else {
          uint16_t id_3819 { 1 };
          bool id_3820 { bool(id_3819 == dsum1_fst_360) };
          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd choose_res_3821;
          if (id_3820) {
            ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 id_3822 { external_source_of_row_binary(dsum1_snd_361) };
            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3823;
            {
              ::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6 drec_415 { id_3822 };
              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3824;
              {
                auto drec_fst_416 { std::get<0>(drec_415) };
                auto drec_snd_417 { std::get<1>(drec_415) };
                ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 id_3825 { external_format_of_row_binary(drec_snd_417) };
                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3826;
                {
                  ::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3 drec_418 { id_3825 };
                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3827;
                  {
                    auto drec_fst_419 { std::get<0>(drec_418) };
                    auto drec_snd_420 { std::get<1>(drec_418) };
                    Size id_3828 { 0UL };
                    uint8_t id_3829 { drec_snd_420.peekU8(id_3828) };
                    uint8_t id_3830 { 1 };
                    bool id_3831 { bool(id_3829 == id_3830) };
                    ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 choose_res_3832;
                    if (id_3831) {
                      std::optional<dessser::gen::event_time::t_ext> id_3833 { std::nullopt };
                      Size id_3834 { 1UL };
                      Pointer id_3835 { drec_snd_420.skip(id_3834) };
                      ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 id_3836 { id_3833, id_3835 };
                      choose_res_3832 = id_3836;
                    } else {
                      auto fun3837 { dessser::gen::event_time::of_row_binary };
                      Size id_3838 { 1UL };
                      Pointer id_3839 { drec_snd_420.skip(id_3838) };
                      ::dessser::gen::raql_operation::t6402d827f30fdf794bf052c6e2db3344 id_3840 { fun3837(id_3839) };
                      ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 letpair_res_3841;
                      {
                        auto make1_1_fst_422 { std::get<0>(id_3840) };
                        auto make1_1_snd_423 { std::get<1>(id_3840) };
                        std::optional<dessser::gen::event_time::t_ext> id_3842 { make1_1_fst_422 };
                        ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 id_3843 { id_3842, make1_1_snd_423 };
                        letpair_res_3841 = id_3843;
                      }
                      choose_res_3832 = letpair_res_3841;
                    }
                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3844;
                    {
                      ::dessser::gen::raql_operation::t9d7811e9b2b7649b14c53a6539d110a6 drec_424 { choose_res_3832 };
                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3845;
                      {
                        auto drec_fst_425 { std::get<0>(drec_424) };
                        auto drec_snd_426 { std::get<1>(drec_424) };
                        uint32_t id_3846 { 0U };
                        Vec<1, uint32_t> id_3847 {  id_3846  };
                        ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3848;
                        {
                          Vec<1, uint32_t> leb_ref_427 { id_3847 };
                          uint8_t id_3849 { 0 };
                          Vec<1, uint8_t> id_3850 {  id_3849  };
                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3851;
                          {
                            Vec<1, uint8_t> shft_ref_428 { id_3850 };
                            Vec<1, Pointer> id_3852 {  drec_snd_426  };
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3853;
                            {
                              Vec<1, Pointer> p_ref_429 { id_3852 };
                              bool while_flag_3854 { true };
                              do {
                                uint8_t id_3855 { 0 };
                                Pointer id_3856 { p_ref_429[id_3855] };
                                ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3857 { id_3856.readU8() };
                                bool let_res_3858;
                                {
                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_430 { id_3857 };
                                  bool letpair_res_3859;
                                  {
                                    auto leb128_fst_431 { std::get<0>(leb128_430) };
                                    auto leb128_snd_432 { std::get<1>(leb128_430) };
                                    uint8_t id_3860 { 0 };
                                    Void id_3861 { ((void)(p_ref_429[id_3860] = leb128_snd_432), ::dessser::VOID) };
                                    (void)id_3861;
                                    uint8_t id_3862 { 0 };
                                    uint8_t id_3863 { 127 };
                                    uint8_t id_3864 { uint8_t(leb128_fst_431 & id_3863) };
                                    uint32_t id_3865 { uint32_t(id_3864) };
                                    uint8_t id_3866 { 0 };
                                    uint8_t id_3867 { shft_ref_428[id_3866] };
                                    uint32_t id_3868 { uint32_t(id_3865 << id_3867) };
                                    uint8_t id_3869 { 0 };
                                    uint32_t id_3870 { leb_ref_427[id_3869] };
                                    uint32_t id_3871 { uint32_t(id_3868 | id_3870) };
                                    Void id_3872 { ((void)(leb_ref_427[id_3862] = id_3871), ::dessser::VOID) };
                                    (void)id_3872;
                                    uint8_t id_3873 { 0 };
                                    uint8_t id_3874 { 0 };
                                    uint8_t id_3875 { shft_ref_428[id_3874] };
                                    uint8_t id_3876 { 7 };
                                    uint8_t id_3877 { uint8_t(id_3875 + id_3876) };
                                    Void id_3878 { ((void)(shft_ref_428[id_3873] = id_3877), ::dessser::VOID) };
                                    (void)id_3878;
                                    uint8_t id_3879 { 128 };
                                    bool id_3880 { bool(leb128_fst_431 >= id_3879) };
                                    letpair_res_3859 = id_3880;
                                  }
                                  let_res_3858 = letpair_res_3859;
                                }
                                while_flag_3854 = let_res_3858;
                                if (while_flag_3854) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_3854);
                              (void)::dessser::VOID;
                              uint8_t id_3881 { 0 };
                              uint32_t id_3882 { leb_ref_427[id_3881] };
                              uint8_t id_3883 { 0 };
                              Pointer id_3884 { p_ref_429[id_3883] };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_3885 { id_3882, id_3884 };
                              let_res_3853 = id_3885;
                            }
                            let_res_3851 = let_res_3853;
                          }
                          let_res_3848 = let_res_3851;
                        }
                        ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3886;
                        {
                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_436 { let_res_3848 };
                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3887;
                          {
                            auto dlist1_fst_437 { std::get<0>(dlist1_436) };
                            auto dlist1_snd_438 { std::get<1>(dlist1_436) };
                            Lst<dessser::gen::field_name::t_ext> endoflist_3888;
                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3889 { endoflist_3888, dlist1_snd_438 };
                            Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_3890 {  id_3889  };
                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_3891;
                            {
                              Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_439 { id_3890 };
                              int32_t id_3892 { 0L };
                              Vec<1, int32_t> id_3893 {  id_3892  };
                              {
                                Vec<1, int32_t> repeat_n_440 { id_3893 };
                                bool while_flag_3894 { true };
                                do {
                                  int32_t id_3895 { int32_t(dlist1_fst_437) };
                                  uint8_t id_3896 { 0 };
                                  int32_t id_3897 { repeat_n_440[id_3896] };
                                  bool id_3898 { bool(id_3895 > id_3897) };
                                  while_flag_3894 = id_3898;
                                  if (while_flag_3894) {
                                    uint8_t id_3899 { 0 };
                                    ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3900 { inits_src_ref_439[id_3899] };
                                    {
                                      ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_441 { id_3900 };
                                      {
                                        auto dlist2_fst_442 { std::get<0>(dlist2_441) };
                                        auto dlist2_snd_443 { std::get<1>(dlist2_441) };
                                        uint8_t id_3901 { 0 };
                                        auto fun3902 { dessser::gen::field_name::of_row_binary };
                                        ::dessser::gen::raql_operation::t18cecf882d7ac80cef37dfe6b22279d4 id_3903 { fun3902(dlist2_snd_443) };
                                        ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_3904;
                                        {
                                          auto dlist3_fst_445 { std::get<0>(id_3903) };
                                          auto dlist3_snd_446 { std::get<1>(id_3903) };
                                          Lst<dessser::gen::field_name::t_ext> id_3905 { dlist3_fst_445, dlist2_fst_442 };
                                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3906 { id_3905, dlist3_snd_446 };
                                          letpair_res_3904 = id_3906;
                                        }
                                        Void id_3907 { ((void)(inits_src_ref_439[id_3901] = letpair_res_3904), ::dessser::VOID) };
                                        (void)id_3907;
                                      }
                                      (void)::dessser::VOID;
                                    }
                                    (void)::dessser::VOID;
                                    uint8_t id_3908 { 0 };
                                    uint8_t id_3909 { 0 };
                                    int32_t id_3910 { repeat_n_440[id_3909] };
                                    int32_t id_3911 { 1L };
                                    int32_t id_3912 { int32_t(id_3910 + id_3911) };
                                    Void id_3913 { ((void)(repeat_n_440[id_3908] = id_3912), ::dessser::VOID) };
                                    (void)id_3913;
                                    (void)id_3913;
                                  }
                                } while (while_flag_3894);
                                (void)::dessser::VOID;
                              }
                              (void)::dessser::VOID;
                              uint8_t id_3914 { 0 };
                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_3915 { inits_src_ref_439[id_3914] };
                              let_res_3891 = id_3915;
                            }
                            letpair_res_3887 = let_res_3891;
                          }
                          let_res_3886 = letpair_res_3887;
                        }
                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3916;
                        {
                          auto dlist4_fst_448 { std::get<0>(let_res_3886) };
                          auto dlist4_snd_449 { std::get<1>(let_res_3886) };
                          ::dessser::gen::raql_operation::teabb4aa6beb374b8a3faf63ed92e59d1 id_3917 { drec_fst_425, dlist4_fst_448, drec_fst_419, drec_fst_416 };
                          std::shared_ptr<::dessser::gen::raql_operation::t>  id_3918 { std::make_shared<::dessser::gen::raql_operation::t>(std::in_place_index<1>, id_3917) };
                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_3919 { id_3918, dlist4_snd_449 };
                          letpair_res_3916 = id_3919;
                        }
                        letpair_res_3845 = letpair_res_3916;
                      }
                      let_res_3844 = letpair_res_3845;
                    }
                    letpair_res_3827 = let_res_3844;
                  }
                  let_res_3826 = letpair_res_3827;
                }
                letpair_res_3824 = let_res_3826;
              }
              let_res_3823 = letpair_res_3824;
            }
            choose_res_3821 = let_res_3823;
          } else {
            uint16_t id_3920 { 2 };
            bool id_3921 { bool(dsum1_fst_360 == id_3920) };
            Void id_3922 { ((void)(assert(id_3921)), ::dessser::VOID) };
            (void)id_3922;
            uint32_t id_3923 { 0U };
            Vec<1, uint32_t> id_3924 {  id_3923  };
            ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3925;
            {
              Vec<1, uint32_t> leb_ref_362 { id_3924 };
              uint8_t id_3926 { 0 };
              Vec<1, uint8_t> id_3927 {  id_3926  };
              ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3928;
              {
                Vec<1, uint8_t> shft_ref_363 { id_3927 };
                Vec<1, Pointer> id_3929 {  dsum1_snd_361  };
                ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa let_res_3930;
                {
                  Vec<1, Pointer> p_ref_364 { id_3929 };
                  bool while_flag_3931 { true };
                  do {
                    uint8_t id_3932 { 0 };
                    Pointer id_3933 { p_ref_364[id_3932] };
                    ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3934 { id_3933.readU8() };
                    bool let_res_3935;
                    {
                      ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_365 { id_3934 };
                      bool letpair_res_3936;
                      {
                        auto leb128_fst_366 { std::get<0>(leb128_365) };
                        auto leb128_snd_367 { std::get<1>(leb128_365) };
                        uint8_t id_3937 { 0 };
                        Void id_3938 { ((void)(p_ref_364[id_3937] = leb128_snd_367), ::dessser::VOID) };
                        (void)id_3938;
                        uint8_t id_3939 { 0 };
                        uint8_t id_3940 { 127 };
                        uint8_t id_3941 { uint8_t(leb128_fst_366 & id_3940) };
                        uint32_t id_3942 { uint32_t(id_3941) };
                        uint8_t id_3943 { 0 };
                        uint8_t id_3944 { shft_ref_363[id_3943] };
                        uint32_t id_3945 { uint32_t(id_3942 << id_3944) };
                        uint8_t id_3946 { 0 };
                        uint32_t id_3947 { leb_ref_362[id_3946] };
                        uint32_t id_3948 { uint32_t(id_3945 | id_3947) };
                        Void id_3949 { ((void)(leb_ref_362[id_3939] = id_3948), ::dessser::VOID) };
                        (void)id_3949;
                        uint8_t id_3950 { 0 };
                        uint8_t id_3951 { 0 };
                        uint8_t id_3952 { shft_ref_363[id_3951] };
                        uint8_t id_3953 { 7 };
                        uint8_t id_3954 { uint8_t(id_3952 + id_3953) };
                        Void id_3955 { ((void)(shft_ref_363[id_3950] = id_3954), ::dessser::VOID) };
                        (void)id_3955;
                        uint8_t id_3956 { 128 };
                        bool id_3957 { bool(leb128_fst_366 >= id_3956) };
                        letpair_res_3936 = id_3957;
                      }
                      let_res_3935 = letpair_res_3936;
                    }
                    while_flag_3931 = let_res_3935;
                    if (while_flag_3931) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_3931);
                  (void)::dessser::VOID;
                  uint8_t id_3958 { 0 };
                  uint32_t id_3959 { leb_ref_362[id_3958] };
                  Size id_3960 { Size(id_3959) };
                  uint8_t id_3961 { 0 };
                  Pointer id_3962 { p_ref_364[id_3961] };
                  ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa id_3963 { id_3960, id_3962 };
                  let_res_3930 = id_3963;
                }
                let_res_3928 = let_res_3930;
              }
              let_res_3925 = let_res_3928;
            }
            ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 let_res_3964;
            {
              ::dessser::gen::raql_operation::t12fb9c475959b52bf7b17b155a955ffa dstring1_368 { let_res_3925 };
              ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_3965;
              {
                auto dstring1_fst_369 { std::get<0>(dstring1_368) };
                auto dstring1_snd_370 { std::get<1>(dstring1_368) };
                ::dessser::gen::raql_operation::t9ef6882174ae71a34a3c5ef6b29242fb id_3966 { dstring1_snd_370.readBytes(dstring1_fst_369) };
                ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 letpair_res_3967;
                {
                  auto dstring2_fst_372 { std::get<0>(id_3966) };
                  auto dstring2_snd_373 { std::get<1>(id_3966) };
                  std::string id_3968 { dstring2_fst_372.toString() };
                  ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 id_3969 { id_3968, dstring2_snd_373 };
                  letpair_res_3967 = id_3969;
                }
                letpair_res_3965 = letpair_res_3967;
              }
              let_res_3964 = letpair_res_3965;
            }
            ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3970;
            {
              ::dessser::gen::raql_operation::t13a07ee37ab40962540da8534858dc07 drec_374 { let_res_3964 };
              ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3971;
              {
                auto drec_fst_375 { std::get<0>(drec_374) };
                auto drec_snd_376 { std::get<1>(drec_374) };
                ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3972 { drec_snd_376.readU16Le() };
                ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 letpair_res_3973;
                {
                  auto du16_fst_378 { std::get<0>(id_3972) };
                  auto du16_snd_379 { std::get<1>(id_3972) };
                  ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 id_3974 { du16_fst_378, du16_snd_379 };
                  letpair_res_3973 = id_3974;
                }
                ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3975;
                {
                  ::dessser::gen::raql_operation::ta97bb48ed75bbda6173555873826c8c6 drec_380 { letpair_res_3973 };
                  ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3976;
                  {
                    auto drec_fst_381 { std::get<0>(drec_380) };
                    auto drec_snd_382 { std::get<1>(drec_380) };
                    auto fun3977 { dessser::gen::raql_net_protocol::of_row_binary };
                    ::dessser::gen::raql_operation::ta85addb3b405dfc5781945a2f01e354a id_3978 { fun3977(drec_snd_382) };
                    ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd let_res_3979;
                    {
                      ::dessser::gen::raql_operation::ta85addb3b405dfc5781945a2f01e354a drec_383 { id_3978 };
                      ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_3980;
                      {
                        auto drec_fst_384 { std::get<0>(drec_383) };
                        auto drec_snd_385 { std::get<1>(drec_383) };
                        uint32_t id_3981 { 0U };
                        Vec<1, uint32_t> id_3982 {  id_3981  };
                        ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3983;
                        {
                          Vec<1, uint32_t> leb_ref_386 { id_3982 };
                          uint8_t id_3984 { 0 };
                          Vec<1, uint8_t> id_3985 {  id_3984  };
                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3986;
                          {
                            Vec<1, uint8_t> shft_ref_387 { id_3985 };
                            Vec<1, Pointer> id_3987 {  drec_snd_385  };
                            ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 let_res_3988;
                            {
                              Vec<1, Pointer> p_ref_388 { id_3987 };
                              bool while_flag_3989 { true };
                              do {
                                uint8_t id_3990 { 0 };
                                Pointer id_3991 { p_ref_388[id_3990] };
                                ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 id_3992 { id_3991.readU8() };
                                bool let_res_3993;
                                {
                                  ::dessser::gen::raql_operation::t1a5d74abf838df33f185a72a8912f5c9 leb128_389 { id_3992 };
                                  bool letpair_res_3994;
                                  {
                                    auto leb128_fst_390 { std::get<0>(leb128_389) };
                                    auto leb128_snd_391 { std::get<1>(leb128_389) };
                                    uint8_t id_3995 { 0 };
                                    Void id_3996 { ((void)(p_ref_388[id_3995] = leb128_snd_391), ::dessser::VOID) };
                                    (void)id_3996;
                                    uint8_t id_3997 { 0 };
                                    uint8_t id_3998 { 127 };
                                    uint8_t id_3999 { uint8_t(leb128_fst_390 & id_3998) };
                                    uint32_t id_4000 { uint32_t(id_3999) };
                                    uint8_t id_4001 { 0 };
                                    uint8_t id_4002 { shft_ref_387[id_4001] };
                                    uint32_t id_4003 { uint32_t(id_4000 << id_4002) };
                                    uint8_t id_4004 { 0 };
                                    uint32_t id_4005 { leb_ref_386[id_4004] };
                                    uint32_t id_4006 { uint32_t(id_4003 | id_4005) };
                                    Void id_4007 { ((void)(leb_ref_386[id_3997] = id_4006), ::dessser::VOID) };
                                    (void)id_4007;
                                    uint8_t id_4008 { 0 };
                                    uint8_t id_4009 { 0 };
                                    uint8_t id_4010 { shft_ref_387[id_4009] };
                                    uint8_t id_4011 { 7 };
                                    uint8_t id_4012 { uint8_t(id_4010 + id_4011) };
                                    Void id_4013 { ((void)(shft_ref_387[id_4008] = id_4012), ::dessser::VOID) };
                                    (void)id_4013;
                                    uint8_t id_4014 { 128 };
                                    bool id_4015 { bool(leb128_fst_390 >= id_4014) };
                                    letpair_res_3994 = id_4015;
                                  }
                                  let_res_3993 = letpair_res_3994;
                                }
                                while_flag_3989 = let_res_3993;
                                if (while_flag_3989) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_3989);
                              (void)::dessser::VOID;
                              uint8_t id_4016 { 0 };
                              uint32_t id_4017 { leb_ref_386[id_4016] };
                              uint8_t id_4018 { 0 };
                              Pointer id_4019 { p_ref_388[id_4018] };
                              ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 id_4020 { id_4017, id_4019 };
                              let_res_3988 = id_4020;
                            }
                            let_res_3986 = let_res_3988;
                          }
                          let_res_3983 = let_res_3986;
                        }
                        ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_4021;
                        {
                          ::dessser::gen::raql_operation::t491c44439106a32f896827242e8e76a1 dlist1_395 { let_res_3983 };
                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_4022;
                          {
                            auto dlist1_fst_396 { std::get<0>(dlist1_395) };
                            auto dlist1_snd_397 { std::get<1>(dlist1_395) };
                            Lst<dessser::gen::field_name::t_ext> endoflist_4023;
                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_4024 { endoflist_4023, dlist1_snd_397 };
                            Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> id_4025 {  id_4024  };
                            ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 let_res_4026;
                            {
                              Vec<1, ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5> inits_src_ref_398 { id_4025 };
                              int32_t id_4027 { 0L };
                              Vec<1, int32_t> id_4028 {  id_4027  };
                              {
                                Vec<1, int32_t> repeat_n_399 { id_4028 };
                                bool while_flag_4029 { true };
                                do {
                                  int32_t id_4030 { int32_t(dlist1_fst_396) };
                                  uint8_t id_4031 { 0 };
                                  int32_t id_4032 { repeat_n_399[id_4031] };
                                  bool id_4033 { bool(id_4030 > id_4032) };
                                  while_flag_4029 = id_4033;
                                  if (while_flag_4029) {
                                    uint8_t id_4034 { 0 };
                                    ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_4035 { inits_src_ref_398[id_4034] };
                                    {
                                      ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 dlist2_400 { id_4035 };
                                      {
                                        auto dlist2_fst_401 { std::get<0>(dlist2_400) };
                                        auto dlist2_snd_402 { std::get<1>(dlist2_400) };
                                        uint8_t id_4036 { 0 };
                                        auto fun4037 { dessser::gen::field_name::of_row_binary };
                                        ::dessser::gen::raql_operation::t18cecf882d7ac80cef37dfe6b22279d4 id_4038 { fun4037(dlist2_snd_402) };
                                        ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 letpair_res_4039;
                                        {
                                          auto dlist3_fst_404 { std::get<0>(id_4038) };
                                          auto dlist3_snd_405 { std::get<1>(id_4038) };
                                          Lst<dessser::gen::field_name::t_ext> id_4040 { dlist3_fst_404, dlist2_fst_401 };
                                          ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_4041 { id_4040, dlist3_snd_405 };
                                          letpair_res_4039 = id_4041;
                                        }
                                        Void id_4042 { ((void)(inits_src_ref_398[id_4036] = letpair_res_4039), ::dessser::VOID) };
                                        (void)id_4042;
                                      }
                                      (void)::dessser::VOID;
                                    }
                                    (void)::dessser::VOID;
                                    uint8_t id_4043 { 0 };
                                    uint8_t id_4044 { 0 };
                                    int32_t id_4045 { repeat_n_399[id_4044] };
                                    int32_t id_4046 { 1L };
                                    int32_t id_4047 { int32_t(id_4045 + id_4046) };
                                    Void id_4048 { ((void)(repeat_n_399[id_4043] = id_4047), ::dessser::VOID) };
                                    (void)id_4048;
                                    (void)id_4048;
                                  }
                                } while (while_flag_4029);
                                (void)::dessser::VOID;
                              }
                              (void)::dessser::VOID;
                              uint8_t id_4049 { 0 };
                              ::dessser::gen::raql_operation::tae4ac4fd187cdebd0a4f6d30f229fbc5 id_4050 { inits_src_ref_398[id_4049] };
                              let_res_4026 = id_4050;
                            }
                            letpair_res_4022 = let_res_4026;
                          }
                          let_res_4021 = letpair_res_4022;
                        }
                        ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd letpair_res_4051;
                        {
                          auto dlist4_fst_407 { std::get<0>(let_res_4021) };
                          auto dlist4_snd_408 { std::get<1>(let_res_4021) };
                          ::dessser::gen::raql_operation::tfb55a595623604efa44696c62f9afcc5 id_4052 { dlist4_fst_407, drec_fst_375, drec_fst_381, drec_fst_384 };
                          std::shared_ptr<::dessser::gen::raql_operation::t>  id_4053 { std::make_shared<::dessser::gen::raql_operation::t>(std::in_place_index<2>, id_4052) };
                          ::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd id_4054 { id_4053, dlist4_snd_408 };
                          letpair_res_4051 = id_4054;
                        }
                        letpair_res_3980 = letpair_res_4051;
                      }
                      let_res_3979 = letpair_res_3980;
                    }
                    letpair_res_3976 = let_res_3979;
                  }
                  let_res_3975 = letpair_res_3976;
                }
                letpair_res_3971 = let_res_3975;
              }
              let_res_3970 = letpair_res_3971;
            }
            choose_res_3821 = let_res_3970;
          }
          choose_res_3197 = choose_res_3821;
        }
        letpair_res_3194 = choose_res_3197;
      }
      let_res_3193 = letpair_res_3194;
    }
    return let_res_3193;
  }
   };
  return fun3189;
}
std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> of_row_binary(of_row_binary_init());


}
