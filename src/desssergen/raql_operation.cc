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
struct t4774fe515f9a8e5673bc2feaee67a68f {
  bool clickhouse_syntax;
  std::string escape_seq;
  Lst<dessser::gen::field_type::t_ext> fields;
  bool may_quote;
  std::string null;
  char separator;
  bool vectors_of_chars_as_string;
  t4774fe515f9a8e5673bc2feaee67a68f(bool clickhouse_syntax_, std::string escape_seq_, Lst<dessser::gen::field_type::t_ext> fields_, bool may_quote_, std::string null_, char separator_, bool vectors_of_chars_as_string_) : clickhouse_syntax(clickhouse_syntax_), escape_seq(escape_seq_), fields(fields_), may_quote(may_quote_), null(null_), separator(separator_), vectors_of_chars_as_string(vectors_of_chars_as_string_) {}
  t4774fe515f9a8e5673bc2feaee67a68f() = default;
};
struct external_format : public std::variant<
  ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f, // CSV
  Lst<dessser::gen::field_type::t_ext> // RowBinary
> { using variant::variant; };

struct t1961e84afc2b1abe7ce9bf9253dd47b8 {
  dessser::gen::raql_expr::t_ext fname;
  std::optional<dessser::gen::raql_expr::t_ext> preprocessor;
  dessser::gen::raql_expr::t_ext unlink;
  t1961e84afc2b1abe7ce9bf9253dd47b8(dessser::gen::raql_expr::t_ext fname_, std::optional<dessser::gen::raql_expr::t_ext> preprocessor_, dessser::gen::raql_expr::t_ext unlink_) : fname(fname_), preprocessor(preprocessor_), unlink(unlink_) {}
  t1961e84afc2b1abe7ce9bf9253dd47b8() = default;
};
typedef std::tuple<
  std::string,
  dessser::gen::raql_expr::t_ext
> tcd17c85cefeae7a860c0732c05eaeaed;

struct tb07656d6bb51183c62956887bcdc8cf2 {
  dessser::gen::raql_expr::t_ext after_max_events;
  dessser::gen::raql_expr::t_ext after_max_secs;
  tb07656d6bb51183c62956887bcdc8cf2(dessser::gen::raql_expr::t_ext after_max_events_, dessser::gen::raql_expr::t_ext after_max_secs_) : after_max_events(after_max_events_), after_max_secs(after_max_secs_) {}
  tb07656d6bb51183c62956887bcdc8cf2() = default;
};
struct ta7fb64c30db2a6f0744298f9ba111e14 : public std::variant<
  Void, // Beginning
  dessser::gen::raql_expr::t_ext, // OffsetFromEnd
  Void, // SaveInState
  ::dessser::gen::raql_operation::tb07656d6bb51183c62956887bcdc8cf2 // UseKafkaGroupCoordinator
> { using variant::variant; };

struct tf15d79cf8e11e1ea99ca519694240894 {
  Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> options;
  std::optional<dessser::gen::raql_expr::t_ext> partitions;
  ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 restart_from;
  dessser::gen::raql_expr::t_ext topic;
  tf15d79cf8e11e1ea99ca519694240894(Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> options_, std::optional<dessser::gen::raql_expr::t_ext> partitions_, ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 restart_from_, dessser::gen::raql_expr::t_ext topic_) : options(options_), partitions(partitions_), restart_from(restart_from_), topic(topic_) {}
  tf15d79cf8e11e1ea99ca519694240894() = default;
};
struct external_source : public std::variant<
  ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8, // File
  ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 // Kafka
> { using variant::variant; };

typedef std::tuple<
  ::dessser::gen::raql_operation::external_format*,
  Pointer
> td224083eaf19a954cf9d9cafa8673ea6;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  char,
  Pointer
> t9c427530664aa522ce95ad420b884056;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  std::string,
  Pointer
> tef94b55d8809251f13165d9a05bd9d0e;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

typedef std::tuple<
  bool,
  Pointer
> t4138de986e20d18b01e4c493dc9d5451;

typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  Lst<dessser::gen::field_type::t_ext>,
  Pointer
> tfba505af7788ece275315330d94bba2e;

typedef std::tuple<
  dessser::gen::field_type::t_ext,
  Pointer
> t2f09fa79b0bdf1902e3b53bc7e485604;

typedef std::tuple<
  ::dessser::gen::raql_operation::external_source*,
  Pointer
> t271b8f1ad1dc1b4cc142866cf5601794;

typedef std::tuple<
  dessser::gen::raql_expr::t_ext,
  Pointer
> t1113e6691818baaf60a775527f6cc1ac;

typedef std::tuple<
  std::optional<dessser::gen::raql_expr::t_ext>,
  Pointer
> tf1063a6af8c1fb72f0e0ee089d43d040;

typedef std::tuple<
  Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed>,
  Pointer
> tc9c5fe4e3c65effcf5ec497fd0133180;

typedef std::tuple<
  ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14,
  Pointer
> t5a237d86cabc7ad13430dbcf6495ec54;

struct t59b20b8b0e4973a8b2e924c6f3f006db : public std::variant<
  Void, // AllSites
  std::string, // TheseSites
  Void // ThisSite
> { using variant::variant; };

struct t3ebe768f5b483383c74caad368fa4d1b : public std::tuple<
  ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db,
  std::optional<std::string>,
  dessser::gen::function_name::t_ext
> { using tuple::tuple; };
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct data_source : public std::variant<
  ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b, // NamedOperation
  t* // SubQuery
> { using variant::variant; };

extern std::function<Pointer(::dessser::gen::raql_operation::data_source*,Pointer)> data_source_to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tf0c8d4f3070907529cc1a83f8baf6fab : public std::tuple<
  uint32_t,
  std::optional<dessser::gen::raql_expr::t_ext>,
  Lst<dessser::gen::raql_expr::t_ext>
> { using tuple::tuple; };
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tbedd072c623fede5642d53b92db3bc60 {
  std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others;
  bool commit_before;
  dessser::gen::raql_expr::t_ext commit_cond;
  std::optional<dessser::gen::event_time::t_ext> Aggregate_event_time;
  std::optional<dessser::gen::raql_expr::t_ext> every;
  Lst<dessser::gen::field_name::t_ext> Aggregate_factors;
  Lst<dessser::gen::raql_select_field::t_ext> Aggregate_fields;
  dessser::gen::raql_flush_method::t_ext flush_how;
  Lst<::dessser::gen::raql_operation::data_source*> from;
  Lst<dessser::gen::raql_expr::t_ext> key;
  Lst<dessser::gen::raql_expr::t_ext> notifications;
  std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> sort;
  dessser::gen::raql_expr::t_ext where;
  tbedd072c623fede5642d53b92db3bc60(std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others_, bool commit_before_, dessser::gen::raql_expr::t_ext commit_cond_, std::optional<dessser::gen::event_time::t_ext> Aggregate_event_time_, std::optional<dessser::gen::raql_expr::t_ext> every_, Lst<dessser::gen::field_name::t_ext> Aggregate_factors_, Lst<dessser::gen::raql_select_field::t_ext> Aggregate_fields_, dessser::gen::raql_flush_method::t_ext flush_how_, Lst<::dessser::gen::raql_operation::data_source*> from_, Lst<dessser::gen::raql_expr::t_ext> key_, Lst<dessser::gen::raql_expr::t_ext> notifications_, std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> sort_, dessser::gen::raql_expr::t_ext where_) : and_all_others(and_all_others_), commit_before(commit_before_), commit_cond(commit_cond_), Aggregate_event_time(Aggregate_event_time_), every(every_), Aggregate_factors(Aggregate_factors_), Aggregate_fields(Aggregate_fields_), flush_how(flush_how_), from(from_), key(key_), notifications(notifications_), sort(sort_), where(where_) {}
  tbedd072c623fede5642d53b92db3bc60() = default;
};
struct t61f013c74b0e45f17e9562bd5460b239 {
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::field_name::t_ext> ReadExternal_factors;
  ::dessser::gen::raql_operation::external_format* format;
  ::dessser::gen::raql_operation::external_source* source;
  t61f013c74b0e45f17e9562bd5460b239(std::optional<dessser::gen::event_time::t_ext> event_time_, Lst<dessser::gen::field_name::t_ext> ReadExternal_factors_, ::dessser::gen::raql_operation::external_format* format_, ::dessser::gen::raql_operation::external_source* source_) : event_time(event_time_), ReadExternal_factors(ReadExternal_factors_), format(format_), source(source_) {}
  t61f013c74b0e45f17e9562bd5460b239() = default;
};
struct t5a75bfb14bb95ab8cf8a8b9296aea27d {
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string net_addr;
  uint16_t port;
  dessser::gen::raql_net_protocol::t_ext proto;
  t5a75bfb14bb95ab8cf8a8b9296aea27d(Lst<dessser::gen::field_name::t_ext> factors_, std::string net_addr_, uint16_t port_, dessser::gen::raql_net_protocol::t_ext proto_) : factors(factors_), net_addr(net_addr_), port(port_), proto(proto_) {}
  t5a75bfb14bb95ab8cf8a8b9296aea27d() = default;
};
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t : public std::variant<
  ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60, // Aggregate
  ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239, // ReadExternal
  ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d // ListenFor
> { using variant::variant; };

extern std::function<Pointer(::dessser::gen::raql_operation::t*,Pointer)> to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(::dessser::gen::raql_operation::data_source*)> data_source_sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(::dessser::gen::raql_operation::t*)> sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  ::dessser::gen::raql_operation::data_source*,
  Pointer
> tcd2420ce0244df52965bf04a8e398ab3;

extern std::function<::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3(Pointer)> data_source_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db,
  Pointer
> ta86591fd7bb24cbb53009de06037fc09;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  std::optional<std::string>,
  Pointer
> t3fbff88eef4e4c8bc42b06e5ad07ea51;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  dessser::gen::function_name::t_ext,
  Pointer
> tc7d3fcfd06c0f02b3732e1754a18402b;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  ::dessser::gen::raql_operation::t*,
  Pointer
> te2fc367261094758eeb235699c19c018;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018(Pointer)> of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  Lst<dessser::gen::raql_select_field::t_ext>,
  Pointer
> ta9047710b0a6cdbb6cf02e2ae071242e;

typedef std::tuple<
  dessser::gen::raql_select_field::t_ext,
  Pointer
> t385fc99bd06c53216a5de778dea0dc6e;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  std::optional<Lst<dessser::gen::field_name::t_ext>>,
  Pointer
> t885b8962b524dff3368f7a529f1d466b;

typedef std::tuple<
  Lst<dessser::gen::field_name::t_ext>,
  Pointer
> t0dfa866705b76efff53e4aa97228a967;

typedef std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> t273a2b7978f5b466a128a51c1cc4a27b;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab>,
  Pointer
> t87f3bb6a03f4e408df2a73622c0ea788;

typedef std::tuple<
  Lst<dessser::gen::raql_expr::t_ext>,
  Pointer
> t0067a338c0fc91b6a811c8df70d4c87a;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  std::optional<dessser::gen::event_time::t_ext>,
  Pointer
> te3858ac581a2bb69ede2f45fc6f9aff4;

typedef std::tuple<
  dessser::gen::event_time::t_ext,
  Pointer
> te8ff255b34432f8503a86cf675cbafe6;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  dessser::gen::raql_flush_method::t_ext,
  Pointer
> t01507690afb11d3b148862b712bad5a5;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  Lst<::dessser::gen::raql_operation::data_source*>,
  Pointer
> t189f4c78595b5c6595a039b832db352d;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  dessser::gen::raql_net_protocol::t_ext,
  Pointer
> t09401f6cfd6a52d2f08b29ed5a55a113;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" "Ptr")
      (let "ssum_dst_848" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_868"
            (let "srec_dst_867"
              (let "srec_dst_861"
                (let "srec_dst_858"
                  (let "srec_dst_857"
                    (let "srec_dst_854" (write-u8 (identifier "ssum_dst_848") (u8-of-char (get-field "separator" (get-alt "CSV" (param 0)))))
                      (write-bytes
                        (let "leb128_sz_855" (make-vec (string-length (get-field "null" (get-alt "CSV" (param 0)))))
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
                        (bytes-of-string (get-field "null" (get-alt "CSV" (param 0)))))) 
                    (write-u8 (identifier "srec_dst_857") (u8-of-bool (get-field "may_quote" (get-alt "CSV" (param 0))))))
                  (write-bytes
                    (let "leb128_sz_859" (make-vec (string-length (get-field "escape_seq" (get-alt "CSV" (param 0)))))
                      (let "leb128_ptr_860" (make-vec (identifier "srec_dst_858"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_860")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_860"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_859"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_859"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_859"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_859") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_859")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_859")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_860"))))) 
                    (bytes-of-string (get-field "escape_seq" (get-alt "CSV" (param 0))))))
                (let "dst_ref_864"
                  (make-vec
                    (let "leb128_sz_862" (make-vec (cardinality (get-field "fields" (get-alt "CSV" (param 0)))))
                      (let "leb128_ptr_863" (make-vec (identifier "srec_dst_861"))
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
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_863"))))))
                  (let "n_ref_865" (make-vec (i32 0))
                    (seq
                      (for-each "x_866" (get-field "fields" (get-alt "CSV" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_864") (apply (ext-identifier field_type to-row-binary) (identifier "x_866") (unsafe-nth (u8 0) (identifier "dst_ref_864"))))
                          (set-vec (u8 0) (identifier "n_ref_865") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_865")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_864")))))) 
              (write-u8 (identifier "srec_dst_867") (u8-of-bool (get-field "vectors_of_chars_as_string" (get-alt "CSV" (param 0))))))
            (write-u8 (identifier "srec_dst_868") (u8-of-bool (get-field "clickhouse_syntax" (get-alt "CSV" (param 0))))))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "dst_ref_851"
              (make-vec
                (let "leb128_sz_849" (make-vec (cardinality (get-alt "RowBinary" (param 0))))
                  (let "leb128_ptr_850" (make-vec (identifier "ssum_dst_848"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_850")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_850"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_849"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_849"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_849"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_849") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_849")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_849")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_850"))))))
              (let "n_ref_852" (make-vec (i32 0))
                (seq
                  (for-each "x_853" (get-alt "RowBinary" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_851") (apply (ext-identifier field_type to-row-binary) (identifier "x_853") (unsafe-nth (u8 0) (identifier "dst_ref_851"))))
                      (set-vec (u8 0) (identifier "n_ref_852") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_852")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_851")))))))))
 */
static std::function<Pointer(::dessser::gen::raql_operation::external_format*,Pointer)> external_format_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_operation::external_format*,Pointer)> fun0 { [&fun0](::dessser::gen::raql_operation::external_format* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_848 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_8 { std::get<0 /* CSV */>((*p_0)) };
        char id_9 { id_8.separator };
        uint8_t id_10 { uint8_t(id_9) };
        Pointer id_11 { ssum_dst_848.writeU8(id_10) };
        Pointer let_res_12;
        {
          Pointer srec_dst_854 { id_11 };
          ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_13 { std::get<0 /* CSV */>((*p_0)) };
          std::string id_14 { id_13.null };
          uint32_t id_15 { (uint32_t)id_14.size() };
          Vec<1, uint32_t> id_16 {  id_15  };
          Pointer let_res_17;
          {
            Vec<1, uint32_t> leb128_sz_855 { id_16 };
            Vec<1, Pointer> id_18 {  srec_dst_854  };
            Pointer let_res_19;
            {
              Vec<1, Pointer> leb128_ptr_856 { id_18 };
              bool while_flag_20 { true };
              do {
                uint8_t id_21 { 0 };
                uint8_t id_22 { 0 };
                Pointer id_23 { leb128_ptr_856[id_22] };
                uint32_t id_24 { 128U };
                uint8_t id_25 { 0 };
                uint32_t id_26 { leb128_sz_855[id_25] };
                bool id_27 { bool(id_24 > id_26) };
                uint8_t choose_res_28;
                if (id_27) {
                  uint8_t id_29 { 0 };
                  uint32_t id_30 { leb128_sz_855[id_29] };
                  uint8_t id_31 { uint8_t(id_30) };
                  choose_res_28 = id_31;
                } else {
                  uint8_t id_32 { 0 };
                  uint32_t id_33 { leb128_sz_855[id_32] };
                  uint8_t id_34 { uint8_t(id_33) };
                  uint8_t id_35 { 128 };
                  uint8_t id_36 { uint8_t(id_34 | id_35) };
                  choose_res_28 = id_36;
                }
                Pointer id_37 { id_23.writeU8(choose_res_28) };
                Void id_38 { ((void)(leb128_ptr_856[id_21] = id_37), VOID) };
                (void)id_38;
                uint8_t id_39 { 0 };
                uint8_t id_40 { 0 };
                uint32_t id_41 { leb128_sz_855[id_40] };
                uint8_t id_42 { 7 };
                uint32_t id_43 { uint32_t(id_41 >> id_42) };
                Void id_44 { ((void)(leb128_sz_855[id_39] = id_43), VOID) };
                (void)id_44;
                uint8_t id_45 { 0 };
                uint32_t id_46 { leb128_sz_855[id_45] };
                uint32_t id_47 { 0U };
                bool id_48 { bool(id_46 > id_47) };
                while_flag_20 = id_48;
                if (while_flag_20) {
                  (void)VOID;
                }
              } while (while_flag_20);
              (void)VOID;
              uint8_t id_49 { 0 };
              Pointer id_50 { leb128_ptr_856[id_49] };
              let_res_19 = id_50;
            }
            let_res_17 = let_res_19;
          }
          ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_51 { std::get<0 /* CSV */>((*p_0)) };
          std::string id_52 { id_51.null };
          Bytes id_53 { id_52 };
          Pointer id_54 { let_res_17.writeBytes(id_53) };
          let_res_12 = id_54;
        }
        Pointer let_res_55;
        {
          Pointer srec_dst_857 { let_res_12 };
          ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_56 { std::get<0 /* CSV */>((*p_0)) };
          bool id_57 { id_56.may_quote };
          uint8_t id_58 { uint8_t(id_57) };
          Pointer id_59 { srec_dst_857.writeU8(id_58) };
          let_res_55 = id_59;
        }
        Pointer let_res_60;
        {
          Pointer srec_dst_858 { let_res_55 };
          ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_61 { std::get<0 /* CSV */>((*p_0)) };
          std::string id_62 { id_61.escape_seq };
          uint32_t id_63 { (uint32_t)id_62.size() };
          Vec<1, uint32_t> id_64 {  id_63  };
          Pointer let_res_65;
          {
            Vec<1, uint32_t> leb128_sz_859 { id_64 };
            Vec<1, Pointer> id_66 {  srec_dst_858  };
            Pointer let_res_67;
            {
              Vec<1, Pointer> leb128_ptr_860 { id_66 };
              bool while_flag_68 { true };
              do {
                uint8_t id_69 { 0 };
                uint8_t id_70 { 0 };
                Pointer id_71 { leb128_ptr_860[id_70] };
                uint32_t id_72 { 128U };
                uint8_t id_73 { 0 };
                uint32_t id_74 { leb128_sz_859[id_73] };
                bool id_75 { bool(id_72 > id_74) };
                uint8_t choose_res_76;
                if (id_75) {
                  uint8_t id_77 { 0 };
                  uint32_t id_78 { leb128_sz_859[id_77] };
                  uint8_t id_79 { uint8_t(id_78) };
                  choose_res_76 = id_79;
                } else {
                  uint8_t id_80 { 0 };
                  uint32_t id_81 { leb128_sz_859[id_80] };
                  uint8_t id_82 { uint8_t(id_81) };
                  uint8_t id_83 { 128 };
                  uint8_t id_84 { uint8_t(id_82 | id_83) };
                  choose_res_76 = id_84;
                }
                Pointer id_85 { id_71.writeU8(choose_res_76) };
                Void id_86 { ((void)(leb128_ptr_860[id_69] = id_85), VOID) };
                (void)id_86;
                uint8_t id_87 { 0 };
                uint8_t id_88 { 0 };
                uint32_t id_89 { leb128_sz_859[id_88] };
                uint8_t id_90 { 7 };
                uint32_t id_91 { uint32_t(id_89 >> id_90) };
                Void id_92 { ((void)(leb128_sz_859[id_87] = id_91), VOID) };
                (void)id_92;
                uint8_t id_93 { 0 };
                uint32_t id_94 { leb128_sz_859[id_93] };
                uint32_t id_95 { 0U };
                bool id_96 { bool(id_94 > id_95) };
                while_flag_68 = id_96;
                if (while_flag_68) {
                  (void)VOID;
                }
              } while (while_flag_68);
              (void)VOID;
              uint8_t id_97 { 0 };
              Pointer id_98 { leb128_ptr_860[id_97] };
              let_res_67 = id_98;
            }
            let_res_65 = let_res_67;
          }
          ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_99 { std::get<0 /* CSV */>((*p_0)) };
          std::string id_100 { id_99.escape_seq };
          Bytes id_101 { id_100 };
          Pointer id_102 { let_res_65.writeBytes(id_101) };
          let_res_60 = id_102;
        }
        Pointer let_res_103;
        {
          Pointer srec_dst_861 { let_res_60 };
          ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_104 { std::get<0 /* CSV */>((*p_0)) };
          Lst<dessser::gen::field_type::t_ext> id_105 { id_104.fields };
          uint32_t id_106 { id_105.size() };
          Vec<1, uint32_t> id_107 {  id_106  };
          Pointer let_res_108;
          {
            Vec<1, uint32_t> leb128_sz_862 { id_107 };
            Vec<1, Pointer> id_109 {  srec_dst_861  };
            Pointer let_res_110;
            {
              Vec<1, Pointer> leb128_ptr_863 { id_109 };
              bool while_flag_111 { true };
              do {
                uint8_t id_112 { 0 };
                uint8_t id_113 { 0 };
                Pointer id_114 { leb128_ptr_863[id_113] };
                uint32_t id_115 { 128U };
                uint8_t id_116 { 0 };
                uint32_t id_117 { leb128_sz_862[id_116] };
                bool id_118 { bool(id_115 > id_117) };
                uint8_t choose_res_119;
                if (id_118) {
                  uint8_t id_120 { 0 };
                  uint32_t id_121 { leb128_sz_862[id_120] };
                  uint8_t id_122 { uint8_t(id_121) };
                  choose_res_119 = id_122;
                } else {
                  uint8_t id_123 { 0 };
                  uint32_t id_124 { leb128_sz_862[id_123] };
                  uint8_t id_125 { uint8_t(id_124) };
                  uint8_t id_126 { 128 };
                  uint8_t id_127 { uint8_t(id_125 | id_126) };
                  choose_res_119 = id_127;
                }
                Pointer id_128 { id_114.writeU8(choose_res_119) };
                Void id_129 { ((void)(leb128_ptr_863[id_112] = id_128), VOID) };
                (void)id_129;
                uint8_t id_130 { 0 };
                uint8_t id_131 { 0 };
                uint32_t id_132 { leb128_sz_862[id_131] };
                uint8_t id_133 { 7 };
                uint32_t id_134 { uint32_t(id_132 >> id_133) };
                Void id_135 { ((void)(leb128_sz_862[id_130] = id_134), VOID) };
                (void)id_135;
                uint8_t id_136 { 0 };
                uint32_t id_137 { leb128_sz_862[id_136] };
                uint32_t id_138 { 0U };
                bool id_139 { bool(id_137 > id_138) };
                while_flag_111 = id_139;
                if (while_flag_111) {
                  (void)VOID;
                }
              } while (while_flag_111);
              (void)VOID;
              uint8_t id_140 { 0 };
              Pointer id_141 { leb128_ptr_863[id_140] };
              let_res_110 = id_141;
            }
            let_res_108 = let_res_110;
          }
          Vec<1, Pointer> id_142 {  let_res_108  };
          Pointer let_res_143;
          {
            Vec<1, Pointer> dst_ref_864 { id_142 };
            int32_t id_144 { 0L };
            Vec<1, int32_t> id_145 {  id_144  };
            Pointer let_res_146;
            {
              Vec<1, int32_t> n_ref_865 { id_145 };
              ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_147 { std::get<0 /* CSV */>((*p_0)) };
              Lst<dessser::gen::field_type::t_ext> id_148 { id_147.fields };
              for (dessser::gen::field_type::t_ext x_866 : id_148) {
                uint8_t id_149 { 0 };
                auto fun150 { dessser::gen::field_type::to_row_binary };
                uint8_t id_151 { 0 };
                Pointer id_152 { dst_ref_864[id_151] };
                Pointer id_153 { fun150(x_866, id_152) };
                Void id_154 { ((void)(dst_ref_864[id_149] = id_153), VOID) };
                (void)id_154;
                uint8_t id_155 { 0 };
                int32_t id_156 { 1L };
                uint8_t id_157 { 0 };
                int32_t id_158 { n_ref_865[id_157] };
                int32_t id_159 { int32_t(id_156 + id_158) };
                Void id_160 { ((void)(n_ref_865[id_155] = id_159), VOID) };
                (void)id_160;
                (void)id_160;
              }
              (void)VOID;
              uint8_t id_161 { 0 };
              Pointer id_162 { dst_ref_864[id_161] };
              let_res_146 = id_162;
            }
            let_res_143 = let_res_146;
          }
          let_res_103 = let_res_143;
        }
        Pointer let_res_163;
        {
          Pointer srec_dst_867 { let_res_103 };
          ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_164 { std::get<0 /* CSV */>((*p_0)) };
          bool id_165 { id_164.vectors_of_chars_as_string };
          uint8_t id_166 { uint8_t(id_165) };
          Pointer id_167 { srec_dst_867.writeU8(id_166) };
          let_res_163 = id_167;
        }
        Pointer let_res_168;
        {
          Pointer srec_dst_868 { let_res_163 };
          ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_169 { std::get<0 /* CSV */>((*p_0)) };
          bool id_170 { id_169.clickhouse_syntax };
          uint8_t id_171 { uint8_t(id_170) };
          Pointer id_172 { srec_dst_868.writeU8(id_171) };
          let_res_168 = id_172;
        }
        choose_res_7 = let_res_168;
      } else {
        uint16_t id_173 { uint16_t((*p_0).index()) };
        uint16_t id_174 { 1 };
        bool id_175 { bool(id_173 == id_174) };
        Void id_176 { ((void)(assert(id_175)), VOID) };
        (void)id_176;
        Lst<dessser::gen::field_type::t_ext> id_177 { std::get<1 /* RowBinary */>((*p_0)) };
        uint32_t id_178 { id_177.size() };
        Vec<1, uint32_t> id_179 {  id_178  };
        Pointer let_res_180;
        {
          Vec<1, uint32_t> leb128_sz_849 { id_179 };
          Vec<1, Pointer> id_181 {  ssum_dst_848  };
          Pointer let_res_182;
          {
            Vec<1, Pointer> leb128_ptr_850 { id_181 };
            bool while_flag_183 { true };
            do {
              uint8_t id_184 { 0 };
              uint8_t id_185 { 0 };
              Pointer id_186 { leb128_ptr_850[id_185] };
              uint32_t id_187 { 128U };
              uint8_t id_188 { 0 };
              uint32_t id_189 { leb128_sz_849[id_188] };
              bool id_190 { bool(id_187 > id_189) };
              uint8_t choose_res_191;
              if (id_190) {
                uint8_t id_192 { 0 };
                uint32_t id_193 { leb128_sz_849[id_192] };
                uint8_t id_194 { uint8_t(id_193) };
                choose_res_191 = id_194;
              } else {
                uint8_t id_195 { 0 };
                uint32_t id_196 { leb128_sz_849[id_195] };
                uint8_t id_197 { uint8_t(id_196) };
                uint8_t id_198 { 128 };
                uint8_t id_199 { uint8_t(id_197 | id_198) };
                choose_res_191 = id_199;
              }
              Pointer id_200 { id_186.writeU8(choose_res_191) };
              Void id_201 { ((void)(leb128_ptr_850[id_184] = id_200), VOID) };
              (void)id_201;
              uint8_t id_202 { 0 };
              uint8_t id_203 { 0 };
              uint32_t id_204 { leb128_sz_849[id_203] };
              uint8_t id_205 { 7 };
              uint32_t id_206 { uint32_t(id_204 >> id_205) };
              Void id_207 { ((void)(leb128_sz_849[id_202] = id_206), VOID) };
              (void)id_207;
              uint8_t id_208 { 0 };
              uint32_t id_209 { leb128_sz_849[id_208] };
              uint32_t id_210 { 0U };
              bool id_211 { bool(id_209 > id_210) };
              while_flag_183 = id_211;
              if (while_flag_183) {
                (void)VOID;
              }
            } while (while_flag_183);
            (void)VOID;
            uint8_t id_212 { 0 };
            Pointer id_213 { leb128_ptr_850[id_212] };
            let_res_182 = id_213;
          }
          let_res_180 = let_res_182;
        }
        Vec<1, Pointer> id_214 {  let_res_180  };
        Pointer let_res_215;
        {
          Vec<1, Pointer> dst_ref_851 { id_214 };
          int32_t id_216 { 0L };
          Vec<1, int32_t> id_217 {  id_216  };
          Pointer let_res_218;
          {
            Vec<1, int32_t> n_ref_852 { id_217 };
            Lst<dessser::gen::field_type::t_ext> id_219 { std::get<1 /* RowBinary */>((*p_0)) };
            for (dessser::gen::field_type::t_ext x_853 : id_219) {
              uint8_t id_220 { 0 };
              auto fun221 { dessser::gen::field_type::to_row_binary };
              uint8_t id_222 { 0 };
              Pointer id_223 { dst_ref_851[id_222] };
              Pointer id_224 { fun221(x_853, id_223) };
              Void id_225 { ((void)(dst_ref_851[id_220] = id_224), VOID) };
              (void)id_225;
              uint8_t id_226 { 0 };
              int32_t id_227 { 1L };
              uint8_t id_228 { 0 };
              int32_t id_229 { n_ref_852[id_228] };
              int32_t id_230 { int32_t(id_227 + id_229) };
              Void id_231 { ((void)(n_ref_852[id_226] = id_230), VOID) };
              (void)id_231;
              (void)id_231;
            }
            (void)VOID;
            uint8_t id_232 { 0 };
            Pointer id_233 { dst_ref_851[id_232] };
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
std::function<Pointer(::dessser::gen::raql_operation::external_format*,Pointer)> external_format_to_row_binary(external_format_to_row_binary_init());

/* 
    (fun ("[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" "Ptr")
      (let "ssum_dst_829" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_846"
            (let "srec_dst_845" (apply (ext-identifier raql_expr to-row-binary) (get-field "fname" (get-alt "File" (param 0))) (identifier "ssum_dst_829"))
              (if (is-null (get-field "preprocessor" (get-alt "File" (param 0)))) 
                (write-u8 (identifier "srec_dst_845") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "preprocessor" (get-alt "File" (param 0)))) (write-u8 (identifier "srec_dst_845") (u8 0)))))
            (apply (ext-identifier raql_expr to-row-binary) (get-field "unlink" (get-alt "File" (param 0))) (identifier "srec_dst_846")))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "srec_dst_841"
              (let "srec_dst_840"
                (let "srec_dst_839"
                  (let "dst_ref_832"
                    (make-vec
                      (let "leb128_sz_830" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (param 0)))))
                        (let "leb128_ptr_831" (make-vec (identifier "ssum_dst_829"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_831")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_831"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_830"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_830"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_830"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_830") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_830")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_830")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_831"))))))
                    (let "n_ref_833" (make-vec (i32 0))
                      (seq
                        (for-each "x_834" (get-field "options" (get-alt "Kafka" (param 0)))
                          (seq
                            (set-vec (u8 0) (identifier "dst_ref_832")
                              (let "stup_dst_838"
                                (let "stup_dst_835" (unsafe-nth (u8 0) (identifier "dst_ref_832"))
                                  (write-bytes
                                    (let "leb128_sz_836" (make-vec (string-length (get-item 0 (identifier "x_834"))))
                                      (let "leb128_ptr_837" (make-vec (identifier "stup_dst_835"))
                                        (seq
                                          (while
                                            (seq
                                              (set-vec (u8 0) (identifier "leb128_ptr_837")
                                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_837"))
                                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_836"))) 
                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_836"))) 
                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_836"))) (u8 128)))))
                                              (set-vec (u8 0) (identifier "leb128_sz_836") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_836")) (u8 7))) 
                                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_836")) (u32 0))) 
                                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_837"))))) 
                                    (bytes-of-string (get-item 0 (identifier "x_834"))))) 
                                (apply (ext-identifier raql_expr to-row-binary) (get-item 1 (identifier "x_834")) (identifier "stup_dst_838"))))
                            (set-vec (u8 0) (identifier "n_ref_833") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_833")))))) 
                        (unsafe-nth (u8 0) (identifier "dst_ref_832"))))) 
                  (apply (ext-identifier raql_expr to-row-binary) (get-field "topic" (get-alt "Kafka" (param 0))) (identifier "srec_dst_839")))
                (if (is-null (get-field "partitions" (get-alt "Kafka" (param 0)))) 
                  (write-u8 (identifier "srec_dst_840") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "partitions" (get-alt "Kafka" (param 0)))) (write-u8 (identifier "srec_dst_840") (u8 0)))))
              (let "ssum_dst_843" (write-u16 little-endian (identifier "srec_dst_841") (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))))
                (if (eq (u16 0) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
                  (identifier "ssum_dst_843")
                  (if (eq (u16 1) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))))
                    (apply (ext-identifier raql_expr to-row-binary) (get-alt "OffsetFromEnd" (get-field "restart_from" (get-alt "Kafka" (param 0)))) (identifier "ssum_dst_843"))
                    (if (eq (u16 2) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
                      (identifier "ssum_dst_843")
                      (seq (assert (eq (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))) (u16 3)))
                        (let "srec_dst_844"
                          (apply (ext-identifier raql_expr to-row-binary) (get-field "after_max_secs" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0))))) (identifier "ssum_dst_843"))
                          (apply (ext-identifier raql_expr to-row-binary) (get-field "after_max_events" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0))))) (identifier "srec_dst_844")))))))))))))
 */
static std::function<Pointer(::dessser::gen::raql_operation::external_source*,Pointer)> external_source_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_operation::external_source*,Pointer)> fun234 { [&fun234](::dessser::gen::raql_operation::external_source* p_0, Pointer p_1) {
    uint16_t id_235 { uint16_t((*p_0).index()) };
    Pointer id_236 { p_1.writeU16Le(id_235) };
    Pointer let_res_237;
    {
      Pointer ssum_dst_829 { id_236 };
      uint16_t id_238 { 0 };
      uint16_t id_239 { uint16_t((*p_0).index()) };
      bool id_240 { bool(id_238 == id_239) };
      Pointer choose_res_241;
      if (id_240) {
        auto fun242 { dessser::gen::raql_expr::to_row_binary };
        ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8 id_243 { std::get<0 /* File */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_244 { id_243.fname };
        Pointer id_245 { fun242(id_244, ssum_dst_829) };
        Pointer let_res_246;
        {
          Pointer srec_dst_845 { id_245 };
          ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8 id_247 { std::get<0 /* File */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_248 { id_247.preprocessor };
          bool id_249 { !(id_248.has_value ()) };
          Pointer choose_res_250;
          if (id_249) {
            uint8_t id_251 { 1 };
            Pointer id_252 { srec_dst_845.writeU8(id_251) };
            choose_res_250 = id_252;
          } else {
            auto fun253 { dessser::gen::raql_expr::to_row_binary };
            ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8 id_254 { std::get<0 /* File */>((*p_0)) };
            std::optional<dessser::gen::raql_expr::t_ext> id_255 { id_254.preprocessor };
            dessser::gen::raql_expr::t_ext id_256 { id_255.value() };
            uint8_t id_257 { 0 };
            Pointer id_258 { srec_dst_845.writeU8(id_257) };
            Pointer id_259 { fun253(id_256, id_258) };
            choose_res_250 = id_259;
          }
          let_res_246 = choose_res_250;
        }
        Pointer let_res_260;
        {
          Pointer srec_dst_846 { let_res_246 };
          auto fun261 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8 id_262 { std::get<0 /* File */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_263 { id_262.unlink };
          Pointer id_264 { fun261(id_263, srec_dst_846) };
          let_res_260 = id_264;
        }
        choose_res_241 = let_res_260;
      } else {
        uint16_t id_265 { uint16_t((*p_0).index()) };
        uint16_t id_266 { 1 };
        bool id_267 { bool(id_265 == id_266) };
        Void id_268 { ((void)(assert(id_267)), VOID) };
        (void)id_268;
        ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_269 { std::get<1 /* Kafka */>((*p_0)) };
        Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> id_270 { id_269.options };
        uint32_t id_271 { id_270.size() };
        Vec<1, uint32_t> id_272 {  id_271  };
        Pointer let_res_273;
        {
          Vec<1, uint32_t> leb128_sz_830 { id_272 };
          Vec<1, Pointer> id_274 {  ssum_dst_829  };
          Pointer let_res_275;
          {
            Vec<1, Pointer> leb128_ptr_831 { id_274 };
            bool while_flag_276 { true };
            do {
              uint8_t id_277 { 0 };
              uint8_t id_278 { 0 };
              Pointer id_279 { leb128_ptr_831[id_278] };
              uint32_t id_280 { 128U };
              uint8_t id_281 { 0 };
              uint32_t id_282 { leb128_sz_830[id_281] };
              bool id_283 { bool(id_280 > id_282) };
              uint8_t choose_res_284;
              if (id_283) {
                uint8_t id_285 { 0 };
                uint32_t id_286 { leb128_sz_830[id_285] };
                uint8_t id_287 { uint8_t(id_286) };
                choose_res_284 = id_287;
              } else {
                uint8_t id_288 { 0 };
                uint32_t id_289 { leb128_sz_830[id_288] };
                uint8_t id_290 { uint8_t(id_289) };
                uint8_t id_291 { 128 };
                uint8_t id_292 { uint8_t(id_290 | id_291) };
                choose_res_284 = id_292;
              }
              Pointer id_293 { id_279.writeU8(choose_res_284) };
              Void id_294 { ((void)(leb128_ptr_831[id_277] = id_293), VOID) };
              (void)id_294;
              uint8_t id_295 { 0 };
              uint8_t id_296 { 0 };
              uint32_t id_297 { leb128_sz_830[id_296] };
              uint8_t id_298 { 7 };
              uint32_t id_299 { uint32_t(id_297 >> id_298) };
              Void id_300 { ((void)(leb128_sz_830[id_295] = id_299), VOID) };
              (void)id_300;
              uint8_t id_301 { 0 };
              uint32_t id_302 { leb128_sz_830[id_301] };
              uint32_t id_303 { 0U };
              bool id_304 { bool(id_302 > id_303) };
              while_flag_276 = id_304;
              if (while_flag_276) {
                (void)VOID;
              }
            } while (while_flag_276);
            (void)VOID;
            uint8_t id_305 { 0 };
            Pointer id_306 { leb128_ptr_831[id_305] };
            let_res_275 = id_306;
          }
          let_res_273 = let_res_275;
        }
        Vec<1, Pointer> id_307 {  let_res_273  };
        Pointer let_res_308;
        {
          Vec<1, Pointer> dst_ref_832 { id_307 };
          int32_t id_309 { 0L };
          Vec<1, int32_t> id_310 {  id_309  };
          Pointer let_res_311;
          {
            Vec<1, int32_t> n_ref_833 { id_310 };
            ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_312 { std::get<1 /* Kafka */>((*p_0)) };
            Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> id_313 { id_312.options };
            for (::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed x_834 : id_313) {
              uint8_t id_314 { 0 };
              uint8_t id_315 { 0 };
              Pointer id_316 { dst_ref_832[id_315] };
              Pointer let_res_317;
              {
                Pointer stup_dst_835 { id_316 };
                std::string id_318 { std::get<0>(x_834) };
                uint32_t id_319 { (uint32_t)id_318.size() };
                Vec<1, uint32_t> id_320 {  id_319  };
                Pointer let_res_321;
                {
                  Vec<1, uint32_t> leb128_sz_836 { id_320 };
                  Vec<1, Pointer> id_322 {  stup_dst_835  };
                  Pointer let_res_323;
                  {
                    Vec<1, Pointer> leb128_ptr_837 { id_322 };
                    bool while_flag_324 { true };
                    do {
                      uint8_t id_325 { 0 };
                      uint8_t id_326 { 0 };
                      Pointer id_327 { leb128_ptr_837[id_326] };
                      uint32_t id_328 { 128U };
                      uint8_t id_329 { 0 };
                      uint32_t id_330 { leb128_sz_836[id_329] };
                      bool id_331 { bool(id_328 > id_330) };
                      uint8_t choose_res_332;
                      if (id_331) {
                        uint8_t id_333 { 0 };
                        uint32_t id_334 { leb128_sz_836[id_333] };
                        uint8_t id_335 { uint8_t(id_334) };
                        choose_res_332 = id_335;
                      } else {
                        uint8_t id_336 { 0 };
                        uint32_t id_337 { leb128_sz_836[id_336] };
                        uint8_t id_338 { uint8_t(id_337) };
                        uint8_t id_339 { 128 };
                        uint8_t id_340 { uint8_t(id_338 | id_339) };
                        choose_res_332 = id_340;
                      }
                      Pointer id_341 { id_327.writeU8(choose_res_332) };
                      Void id_342 { ((void)(leb128_ptr_837[id_325] = id_341), VOID) };
                      (void)id_342;
                      uint8_t id_343 { 0 };
                      uint8_t id_344 { 0 };
                      uint32_t id_345 { leb128_sz_836[id_344] };
                      uint8_t id_346 { 7 };
                      uint32_t id_347 { uint32_t(id_345 >> id_346) };
                      Void id_348 { ((void)(leb128_sz_836[id_343] = id_347), VOID) };
                      (void)id_348;
                      uint8_t id_349 { 0 };
                      uint32_t id_350 { leb128_sz_836[id_349] };
                      uint32_t id_351 { 0U };
                      bool id_352 { bool(id_350 > id_351) };
                      while_flag_324 = id_352;
                      if (while_flag_324) {
                        (void)VOID;
                      }
                    } while (while_flag_324);
                    (void)VOID;
                    uint8_t id_353 { 0 };
                    Pointer id_354 { leb128_ptr_837[id_353] };
                    let_res_323 = id_354;
                  }
                  let_res_321 = let_res_323;
                }
                std::string id_355 { std::get<0>(x_834) };
                Bytes id_356 { id_355 };
                Pointer id_357 { let_res_321.writeBytes(id_356) };
                let_res_317 = id_357;
              }
              Pointer let_res_358;
              {
                Pointer stup_dst_838 { let_res_317 };
                auto fun359 { dessser::gen::raql_expr::to_row_binary };
                dessser::gen::raql_expr::t_ext id_360 { std::get<1>(x_834) };
                Pointer id_361 { fun359(id_360, stup_dst_838) };
                let_res_358 = id_361;
              }
              Void id_362 { ((void)(dst_ref_832[id_314] = let_res_358), VOID) };
              (void)id_362;
              uint8_t id_363 { 0 };
              int32_t id_364 { 1L };
              uint8_t id_365 { 0 };
              int32_t id_366 { n_ref_833[id_365] };
              int32_t id_367 { int32_t(id_364 + id_366) };
              Void id_368 { ((void)(n_ref_833[id_363] = id_367), VOID) };
              (void)id_368;
              (void)id_368;
            }
            (void)VOID;
            uint8_t id_369 { 0 };
            Pointer id_370 { dst_ref_832[id_369] };
            let_res_311 = id_370;
          }
          let_res_308 = let_res_311;
        }
        Pointer let_res_371;
        {
          Pointer srec_dst_839 { let_res_308 };
          auto fun372 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_373 { std::get<1 /* Kafka */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_374 { id_373.topic };
          Pointer id_375 { fun372(id_374, srec_dst_839) };
          let_res_371 = id_375;
        }
        Pointer let_res_376;
        {
          Pointer srec_dst_840 { let_res_371 };
          ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_377 { std::get<1 /* Kafka */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_378 { id_377.partitions };
          bool id_379 { !(id_378.has_value ()) };
          Pointer choose_res_380;
          if (id_379) {
            uint8_t id_381 { 1 };
            Pointer id_382 { srec_dst_840.writeU8(id_381) };
            choose_res_380 = id_382;
          } else {
            auto fun383 { dessser::gen::raql_expr::to_row_binary };
            ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_384 { std::get<1 /* Kafka */>((*p_0)) };
            std::optional<dessser::gen::raql_expr::t_ext> id_385 { id_384.partitions };
            dessser::gen::raql_expr::t_ext id_386 { id_385.value() };
            uint8_t id_387 { 0 };
            Pointer id_388 { srec_dst_840.writeU8(id_387) };
            Pointer id_389 { fun383(id_386, id_388) };
            choose_res_380 = id_389;
          }
          let_res_376 = choose_res_380;
        }
        Pointer let_res_390;
        {
          Pointer srec_dst_841 { let_res_376 };
          ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_391 { std::get<1 /* Kafka */>((*p_0)) };
          ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_392 { id_391.restart_from };
          uint16_t id_393 { uint16_t(id_392.index()) };
          Pointer id_394 { srec_dst_841.writeU16Le(id_393) };
          Pointer let_res_395;
          {
            Pointer ssum_dst_843 { id_394 };
            uint16_t id_396 { 0 };
            ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_397 { std::get<1 /* Kafka */>((*p_0)) };
            ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_398 { id_397.restart_from };
            uint16_t id_399 { uint16_t(id_398.index()) };
            bool id_400 { bool(id_396 == id_399) };
            Pointer choose_res_401;
            if (id_400) {
              choose_res_401 = ssum_dst_843;
            } else {
              uint16_t id_402 { 1 };
              ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_403 { std::get<1 /* Kafka */>((*p_0)) };
              ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_404 { id_403.restart_from };
              uint16_t id_405 { uint16_t(id_404.index()) };
              bool id_406 { bool(id_402 == id_405) };
              Pointer choose_res_407;
              if (id_406) {
                auto fun408 { dessser::gen::raql_expr::to_row_binary };
                ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_409 { std::get<1 /* Kafka */>((*p_0)) };
                ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_410 { id_409.restart_from };
                dessser::gen::raql_expr::t_ext id_411 { std::get<1 /* OffsetFromEnd */>(id_410) };
                Pointer id_412 { fun408(id_411, ssum_dst_843) };
                choose_res_407 = id_412;
              } else {
                uint16_t id_413 { 2 };
                ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_414 { std::get<1 /* Kafka */>((*p_0)) };
                ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_415 { id_414.restart_from };
                uint16_t id_416 { uint16_t(id_415.index()) };
                bool id_417 { bool(id_413 == id_416) };
                Pointer choose_res_418;
                if (id_417) {
                  choose_res_418 = ssum_dst_843;
                } else {
                  ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_419 { std::get<1 /* Kafka */>((*p_0)) };
                  ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_420 { id_419.restart_from };
                  uint16_t id_421 { uint16_t(id_420.index()) };
                  uint16_t id_422 { 3 };
                  bool id_423 { bool(id_421 == id_422) };
                  Void id_424 { ((void)(assert(id_423)), VOID) };
                  (void)id_424;
                  auto fun425 { dessser::gen::raql_expr::to_row_binary };
                  ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_426 { std::get<1 /* Kafka */>((*p_0)) };
                  ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_427 { id_426.restart_from };
                  ::dessser::gen::raql_operation::tb07656d6bb51183c62956887bcdc8cf2 id_428 { std::get<3 /* UseKafkaGroupCoordinator */>(id_427) };
                  dessser::gen::raql_expr::t_ext id_429 { id_428.after_max_secs };
                  Pointer id_430 { fun425(id_429, ssum_dst_843) };
                  Pointer let_res_431;
                  {
                    Pointer srec_dst_844 { id_430 };
                    auto fun432 { dessser::gen::raql_expr::to_row_binary };
                    ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_433 { std::get<1 /* Kafka */>((*p_0)) };
                    ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_434 { id_433.restart_from };
                    ::dessser::gen::raql_operation::tb07656d6bb51183c62956887bcdc8cf2 id_435 { std::get<3 /* UseKafkaGroupCoordinator */>(id_434) };
                    dessser::gen::raql_expr::t_ext id_436 { id_435.after_max_events };
                    Pointer id_437 { fun432(id_436, srec_dst_844) };
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
std::function<Pointer(::dessser::gen::raql_operation::external_source*,Pointer)> external_source_to_row_binary(external_source_to_row_binary_init());

/* 
    (fun ("[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]")
      (if (eq (u16 0) (label-of (param 0)))
        (add
          (add
            (let "sz_747"
              (let "sz_743"
                (add
                  (add (size 3)
                    (add
                      (let "n_ref_740" (make-vec (string-length (get-field "null" (get-alt "CSV" (param 0)))))
                        (let "lebsz_ref_741" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_740")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_741")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_741") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_741")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_741")))))) 
                      (size-of-u32 (string-length (get-field "null" (get-alt "CSV" (param 0))))))) 
                  (size 1))
                (add (identifier "sz_743")
                  (add
                    (let "n_ref_745" (make-vec (string-length (get-field "escape_seq" (get-alt "CSV" (param 0)))))
                      (let "lebsz_ref_746" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_745")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_746")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_746") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_746")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_746")))))) 
                    (size-of-u32 (string-length (get-field "escape_seq" (get-alt "CSV" (param 0))))))))
              (let "sz_ref_750"
                (make-vec
                  (add (identifier "sz_747")
                    (let "n_ref_748" (make-vec (cardinality (get-field "fields" (get-alt "CSV" (param 0)))))
                      (let "lebsz_ref_749" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_748")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_749")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_749") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_749")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_749"))))))))
                (seq
                  (let "repeat_n_751" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "fields" (get-alt "CSV" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_751")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_750")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_750"))
                            (apply (ext-identifier field_type sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_751")) (get-field "fields" (get-alt "CSV" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_751") (add (unsafe-nth (u8 0) (identifier "repeat_n_751")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_750"))))) (size 1)) 
          (size 1))
        (seq (assert (eq (label-of (param 0)) (u16 1)))
          (let "sz_ref_735"
            (make-vec
              (add (size 2)
                (let "n_ref_733" (make-vec (cardinality (get-alt "RowBinary" (param 0))))
                  (let "lebsz_ref_734" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_733")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_734")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_734") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_734")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_734"))))))))
            (seq
              (let "repeat_n_736" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-alt "RowBinary" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_736")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_735")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_735")) (apply (ext-identifier field_type sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_736")) (get-alt "RowBinary" (param 0))))))
                    (set-vec (u8 0) (identifier "repeat_n_736") (add (unsafe-nth (u8 0) (identifier "repeat_n_736")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_735")))))))
 */
static std::function<Size(::dessser::gen::raql_operation::external_format*)> external_format_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_operation::external_format*)> fun438 { [&fun438](::dessser::gen::raql_operation::external_format* p_0) {
    uint16_t id_439 { 0 };
    uint16_t id_440 { uint16_t((*p_0).index()) };
    bool id_441 { bool(id_439 == id_440) };
    Size choose_res_442;
    if (id_441) {
      Size id_443 { 3UL };
      ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_444 { std::get<0 /* CSV */>((*p_0)) };
      std::string id_445 { id_444.null };
      uint32_t id_446 { (uint32_t)id_445.size() };
      Vec<1, uint32_t> id_447 {  id_446  };
      Size let_res_448;
      {
        Vec<1, uint32_t> n_ref_740 { id_447 };
        uint32_t id_449 { 1U };
        Vec<1, uint32_t> id_450 {  id_449  };
        Size let_res_451;
        {
          Vec<1, uint32_t> lebsz_ref_741 { id_450 };
          bool while_flag_452 { true };
          do {
            uint8_t id_453 { 0 };
            uint32_t id_454 { n_ref_740[id_453] };
            uint8_t id_455 { 0 };
            uint32_t id_456 { lebsz_ref_741[id_455] };
            uint8_t id_457 { 7 };
            uint32_t id_458 { uint32_t(id_456 << id_457) };
            bool id_459 { bool(id_454 >= id_458) };
            while_flag_452 = id_459;
            if (while_flag_452) {
              uint8_t id_460 { 0 };
              uint8_t id_461 { 0 };
              uint32_t id_462 { lebsz_ref_741[id_461] };
              uint32_t id_463 { 1U };
              uint32_t id_464 { uint32_t(id_462 + id_463) };
              Void id_465 { ((void)(lebsz_ref_741[id_460] = id_464), VOID) };
              (void)id_465;
            }
          } while (while_flag_452);
          (void)VOID;
          uint8_t id_466 { 0 };
          uint32_t id_467 { lebsz_ref_741[id_466] };
          Size id_468 { Size(id_467) };
          let_res_451 = id_468;
        }
        let_res_448 = let_res_451;
      }
      ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_469 { std::get<0 /* CSV */>((*p_0)) };
      std::string id_470 { id_469.null };
      uint32_t id_471 { (uint32_t)id_470.size() };
      Size id_472 { Size(id_471) };
      Size id_473 { Size(let_res_448 + id_472) };
      Size id_474 { Size(id_443 + id_473) };
      Size id_475 { 1UL };
      Size id_476 { Size(id_474 + id_475) };
      Size let_res_477;
      {
        Size sz_743 { id_476 };
        ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_478 { std::get<0 /* CSV */>((*p_0)) };
        std::string id_479 { id_478.escape_seq };
        uint32_t id_480 { (uint32_t)id_479.size() };
        Vec<1, uint32_t> id_481 {  id_480  };
        Size let_res_482;
        {
          Vec<1, uint32_t> n_ref_745 { id_481 };
          uint32_t id_483 { 1U };
          Vec<1, uint32_t> id_484 {  id_483  };
          Size let_res_485;
          {
            Vec<1, uint32_t> lebsz_ref_746 { id_484 };
            bool while_flag_486 { true };
            do {
              uint8_t id_487 { 0 };
              uint32_t id_488 { n_ref_745[id_487] };
              uint8_t id_489 { 0 };
              uint32_t id_490 { lebsz_ref_746[id_489] };
              uint8_t id_491 { 7 };
              uint32_t id_492 { uint32_t(id_490 << id_491) };
              bool id_493 { bool(id_488 >= id_492) };
              while_flag_486 = id_493;
              if (while_flag_486) {
                uint8_t id_494 { 0 };
                uint8_t id_495 { 0 };
                uint32_t id_496 { lebsz_ref_746[id_495] };
                uint32_t id_497 { 1U };
                uint32_t id_498 { uint32_t(id_496 + id_497) };
                Void id_499 { ((void)(lebsz_ref_746[id_494] = id_498), VOID) };
                (void)id_499;
              }
            } while (while_flag_486);
            (void)VOID;
            uint8_t id_500 { 0 };
            uint32_t id_501 { lebsz_ref_746[id_500] };
            Size id_502 { Size(id_501) };
            let_res_485 = id_502;
          }
          let_res_482 = let_res_485;
        }
        ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_503 { std::get<0 /* CSV */>((*p_0)) };
        std::string id_504 { id_503.escape_seq };
        uint32_t id_505 { (uint32_t)id_504.size() };
        Size id_506 { Size(id_505) };
        Size id_507 { Size(let_res_482 + id_506) };
        Size id_508 { Size(sz_743 + id_507) };
        let_res_477 = id_508;
      }
      Size let_res_509;
      {
        Size sz_747 { let_res_477 };
        ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_510 { std::get<0 /* CSV */>((*p_0)) };
        Lst<dessser::gen::field_type::t_ext> id_511 { id_510.fields };
        uint32_t id_512 { id_511.size() };
        Vec<1, uint32_t> id_513 {  id_512  };
        Size let_res_514;
        {
          Vec<1, uint32_t> n_ref_748 { id_513 };
          uint32_t id_515 { 1U };
          Vec<1, uint32_t> id_516 {  id_515  };
          Size let_res_517;
          {
            Vec<1, uint32_t> lebsz_ref_749 { id_516 };
            bool while_flag_518 { true };
            do {
              uint8_t id_519 { 0 };
              uint32_t id_520 { n_ref_748[id_519] };
              uint8_t id_521 { 0 };
              uint32_t id_522 { lebsz_ref_749[id_521] };
              uint8_t id_523 { 7 };
              uint32_t id_524 { uint32_t(id_522 << id_523) };
              bool id_525 { bool(id_520 >= id_524) };
              while_flag_518 = id_525;
              if (while_flag_518) {
                uint8_t id_526 { 0 };
                uint8_t id_527 { 0 };
                uint32_t id_528 { lebsz_ref_749[id_527] };
                uint32_t id_529 { 1U };
                uint32_t id_530 { uint32_t(id_528 + id_529) };
                Void id_531 { ((void)(lebsz_ref_749[id_526] = id_530), VOID) };
                (void)id_531;
              }
            } while (while_flag_518);
            (void)VOID;
            uint8_t id_532 { 0 };
            uint32_t id_533 { lebsz_ref_749[id_532] };
            Size id_534 { Size(id_533) };
            let_res_517 = id_534;
          }
          let_res_514 = let_res_517;
        }
        Size id_535 { Size(sz_747 + let_res_514) };
        Vec<1, Size> id_536 {  id_535  };
        Size let_res_537;
        {
          Vec<1, Size> sz_ref_750 { id_536 };
          int32_t id_538 { 0L };
          Vec<1, int32_t> id_539 {  id_538  };
          {
            Vec<1, int32_t> repeat_n_751 { id_539 };
            bool while_flag_540 { true };
            do {
              ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_541 { std::get<0 /* CSV */>((*p_0)) };
              Lst<dessser::gen::field_type::t_ext> id_542 { id_541.fields };
              uint32_t id_543 { id_542.size() };
              int32_t id_544 { int32_t(id_543) };
              uint8_t id_545 { 0 };
              int32_t id_546 { repeat_n_751[id_545] };
              bool id_547 { bool(id_544 > id_546) };
              while_flag_540 = id_547;
              if (while_flag_540) {
                uint8_t id_548 { 0 };
                uint8_t id_549 { 0 };
                Size id_550 { sz_ref_750[id_549] };
                auto fun551 { dessser::gen::field_type::sersize_of_row_binary };
                uint8_t id_552 { 0 };
                int32_t id_553 { repeat_n_751[id_552] };
                ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_554 { std::get<0 /* CSV */>((*p_0)) };
                Lst<dessser::gen::field_type::t_ext> id_555 { id_554.fields };
                dessser::gen::field_type::t_ext id_556 { id_555[id_553] };
                Size id_557 { fun551(id_556) };
                Size id_558 { Size(id_550 + id_557) };
                Void id_559 { ((void)(sz_ref_750[id_548] = id_558), VOID) };
                (void)id_559;
                uint8_t id_560 { 0 };
                uint8_t id_561 { 0 };
                int32_t id_562 { repeat_n_751[id_561] };
                int32_t id_563 { 1L };
                int32_t id_564 { int32_t(id_562 + id_563) };
                Void id_565 { ((void)(repeat_n_751[id_560] = id_564), VOID) };
                (void)id_565;
                (void)id_565;
              }
            } while (while_flag_540);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_566 { 0 };
          Size id_567 { sz_ref_750[id_566] };
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
      Void id_575 { ((void)(assert(id_574)), VOID) };
      (void)id_575;
      Size id_576 { 2UL };
      Lst<dessser::gen::field_type::t_ext> id_577 { std::get<1 /* RowBinary */>((*p_0)) };
      uint32_t id_578 { id_577.size() };
      Vec<1, uint32_t> id_579 {  id_578  };
      Size let_res_580;
      {
        Vec<1, uint32_t> n_ref_733 { id_579 };
        uint32_t id_581 { 1U };
        Vec<1, uint32_t> id_582 {  id_581  };
        Size let_res_583;
        {
          Vec<1, uint32_t> lebsz_ref_734 { id_582 };
          bool while_flag_584 { true };
          do {
            uint8_t id_585 { 0 };
            uint32_t id_586 { n_ref_733[id_585] };
            uint8_t id_587 { 0 };
            uint32_t id_588 { lebsz_ref_734[id_587] };
            uint8_t id_589 { 7 };
            uint32_t id_590 { uint32_t(id_588 << id_589) };
            bool id_591 { bool(id_586 >= id_590) };
            while_flag_584 = id_591;
            if (while_flag_584) {
              uint8_t id_592 { 0 };
              uint8_t id_593 { 0 };
              uint32_t id_594 { lebsz_ref_734[id_593] };
              uint32_t id_595 { 1U };
              uint32_t id_596 { uint32_t(id_594 + id_595) };
              Void id_597 { ((void)(lebsz_ref_734[id_592] = id_596), VOID) };
              (void)id_597;
            }
          } while (while_flag_584);
          (void)VOID;
          uint8_t id_598 { 0 };
          uint32_t id_599 { lebsz_ref_734[id_598] };
          Size id_600 { Size(id_599) };
          let_res_583 = id_600;
        }
        let_res_580 = let_res_583;
      }
      Size id_601 { Size(id_576 + let_res_580) };
      Vec<1, Size> id_602 {  id_601  };
      Size let_res_603;
      {
        Vec<1, Size> sz_ref_735 { id_602 };
        int32_t id_604 { 0L };
        Vec<1, int32_t> id_605 {  id_604  };
        {
          Vec<1, int32_t> repeat_n_736 { id_605 };
          bool while_flag_606 { true };
          do {
            Lst<dessser::gen::field_type::t_ext> id_607 { std::get<1 /* RowBinary */>((*p_0)) };
            uint32_t id_608 { id_607.size() };
            int32_t id_609 { int32_t(id_608) };
            uint8_t id_610 { 0 };
            int32_t id_611 { repeat_n_736[id_610] };
            bool id_612 { bool(id_609 > id_611) };
            while_flag_606 = id_612;
            if (while_flag_606) {
              uint8_t id_613 { 0 };
              uint8_t id_614 { 0 };
              Size id_615 { sz_ref_735[id_614] };
              auto fun616 { dessser::gen::field_type::sersize_of_row_binary };
              uint8_t id_617 { 0 };
              int32_t id_618 { repeat_n_736[id_617] };
              Lst<dessser::gen::field_type::t_ext> id_619 { std::get<1 /* RowBinary */>((*p_0)) };
              dessser::gen::field_type::t_ext id_620 { id_619[id_618] };
              Size id_621 { fun616(id_620) };
              Size id_622 { Size(id_615 + id_621) };
              Void id_623 { ((void)(sz_ref_735[id_613] = id_622), VOID) };
              (void)id_623;
              uint8_t id_624 { 0 };
              uint8_t id_625 { 0 };
              int32_t id_626 { repeat_n_736[id_625] };
              int32_t id_627 { 1L };
              int32_t id_628 { int32_t(id_626 + id_627) };
              Void id_629 { ((void)(repeat_n_736[id_624] = id_628), VOID) };
              (void)id_629;
              (void)id_629;
            }
          } while (while_flag_606);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_630 { 0 };
        Size id_631 { sz_ref_735[id_630] };
        let_res_603 = id_631;
      }
      choose_res_442 = let_res_603;
    }
    return choose_res_442;
  }
   };
  return fun438;
}
std::function<Size(::dessser::gen::raql_operation::external_format*)> external_format_sersize_of_row_binary(external_format_sersize_of_row_binary_init());

/* 
    (fun ("[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_731"
          (let "sz_730" (add (size 2) (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "fname" (get-alt "File" (param 0)))))
            (if (is-null (get-field "preprocessor" (get-alt "File" (param 0)))) 
              (add (identifier "sz_730") (size 1)) (add (add (identifier "sz_730") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "preprocessor" (get-alt "File" (param 0)))))) (size 1))))
          (add (identifier "sz_731") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "unlink" (get-alt "File" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1)))
          (let "sz_725"
            (let "sz_724"
              (let "sz_723"
                (let "sz_ref_716"
                  (make-vec
                    (add (size 2)
                      (let "n_ref_714" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (param 0)))))
                        (let "lebsz_ref_715" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_714")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_715")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_715") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_715")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_715"))))))))
                  (seq
                    (let "repeat_n_717" (make-vec (i32 0))
                      (while (gt (to-i32 (cardinality (get-field "options" (get-alt "Kafka" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_717")))
                        (seq
                          (set-vec (u8 0) (identifier "sz_ref_716")
                            (let "sz_722"
                              (let "sz_718" (unsafe-nth (u8 0) (identifier "sz_ref_716"))
                                (add (identifier "sz_718")
                                  (let "wlen_719" (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_717")) (get-field "options" (get-alt "Kafka" (param 0))))))
                                    (add
                                      (let "n_ref_720" (make-vec (identifier "wlen_719"))
                                        (let "lebsz_ref_721" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_720")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_721")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_721") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_721")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_721")))))) 
                                      (size-of-u32 (identifier "wlen_719"))))))
                              (add (identifier "sz_722")
                                (apply (ext-identifier raql_expr sersize-of-row-binary) (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_717")) (get-field "options" (get-alt "Kafka" (param 0)))))))))
                          (set-vec (u8 0) (identifier "repeat_n_717") (add (unsafe-nth (u8 0) (identifier "repeat_n_717")) (i32 1)))))) 
                    (unsafe-nth (u8 0) (identifier "sz_ref_716")))) (add (identifier "sz_723") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "topic" (get-alt "Kafka" (param 0))))))
              (if (is-null (get-field "partitions" (get-alt "Kafka" (param 0)))) 
                (add (identifier "sz_724") (size 1)) (add (add (identifier "sz_724") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "partitions" (get-alt "Kafka" (param 0)))))) (size 1))))
            (if (eq (u16 0) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
              (add (identifier "sz_725") (size 2))
              (if (eq (u16 1) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))))
                (add (add (identifier "sz_725") (size 2)) (apply (ext-identifier raql_expr sersize-of-row-binary) (get-alt "OffsetFromEnd" (get-field "restart_from" (get-alt "Kafka" (param 0))))))
                (if (eq (u16 2) (label-of (get-field "restart_from" (get-alt "Kafka" (param 0))))) 
                  (add (identifier "sz_725") (size 2))
                  (seq (assert (eq (label-of (get-field "restart_from" (get-alt "Kafka" (param 0)))) (u16 3)))
                    (let "sz_728"
                      (add (add (identifier "sz_725") (size 2))
                        (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "after_max_secs" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0)))))))
                      (add (identifier "sz_728") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "after_max_events" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (param 0))))))))))))))))
 */
static std::function<Size(::dessser::gen::raql_operation::external_source*)> external_source_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_operation::external_source*)> fun632 { [&fun632](::dessser::gen::raql_operation::external_source* p_0) {
    uint16_t id_633 { 0 };
    uint16_t id_634 { uint16_t((*p_0).index()) };
    bool id_635 { bool(id_633 == id_634) };
    Size choose_res_636;
    if (id_635) {
      Size id_637 { 2UL };
      auto fun638 { dessser::gen::raql_expr::sersize_of_row_binary };
      ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8 id_639 { std::get<0 /* File */>((*p_0)) };
      dessser::gen::raql_expr::t_ext id_640 { id_639.fname };
      Size id_641 { fun638(id_640) };
      Size id_642 { Size(id_637 + id_641) };
      Size let_res_643;
      {
        Size sz_730 { id_642 };
        ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8 id_644 { std::get<0 /* File */>((*p_0)) };
        std::optional<dessser::gen::raql_expr::t_ext> id_645 { id_644.preprocessor };
        bool id_646 { !(id_645.has_value ()) };
        Size choose_res_647;
        if (id_646) {
          Size id_648 { 1UL };
          Size id_649 { Size(sz_730 + id_648) };
          choose_res_647 = id_649;
        } else {
          auto fun650 { dessser::gen::raql_expr::sersize_of_row_binary };
          ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8 id_651 { std::get<0 /* File */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_652 { id_651.preprocessor };
          dessser::gen::raql_expr::t_ext id_653 { id_652.value() };
          Size id_654 { fun650(id_653) };
          Size id_655 { Size(sz_730 + id_654) };
          Size id_656 { 1UL };
          Size id_657 { Size(id_655 + id_656) };
          choose_res_647 = id_657;
        }
        let_res_643 = choose_res_647;
      }
      Size let_res_658;
      {
        Size sz_731 { let_res_643 };
        auto fun659 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8 id_660 { std::get<0 /* File */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_661 { id_660.unlink };
        Size id_662 { fun659(id_661) };
        Size id_663 { Size(sz_731 + id_662) };
        let_res_658 = id_663;
      }
      choose_res_636 = let_res_658;
    } else {
      uint16_t id_664 { uint16_t((*p_0).index()) };
      uint16_t id_665 { 1 };
      bool id_666 { bool(id_664 == id_665) };
      Void id_667 { ((void)(assert(id_666)), VOID) };
      (void)id_667;
      Size id_668 { 2UL };
      ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_669 { std::get<1 /* Kafka */>((*p_0)) };
      Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> id_670 { id_669.options };
      uint32_t id_671 { id_670.size() };
      Vec<1, uint32_t> id_672 {  id_671  };
      Size let_res_673;
      {
        Vec<1, uint32_t> n_ref_714 { id_672 };
        uint32_t id_674 { 1U };
        Vec<1, uint32_t> id_675 {  id_674  };
        Size let_res_676;
        {
          Vec<1, uint32_t> lebsz_ref_715 { id_675 };
          bool while_flag_677 { true };
          do {
            uint8_t id_678 { 0 };
            uint32_t id_679 { n_ref_714[id_678] };
            uint8_t id_680 { 0 };
            uint32_t id_681 { lebsz_ref_715[id_680] };
            uint8_t id_682 { 7 };
            uint32_t id_683 { uint32_t(id_681 << id_682) };
            bool id_684 { bool(id_679 >= id_683) };
            while_flag_677 = id_684;
            if (while_flag_677) {
              uint8_t id_685 { 0 };
              uint8_t id_686 { 0 };
              uint32_t id_687 { lebsz_ref_715[id_686] };
              uint32_t id_688 { 1U };
              uint32_t id_689 { uint32_t(id_687 + id_688) };
              Void id_690 { ((void)(lebsz_ref_715[id_685] = id_689), VOID) };
              (void)id_690;
            }
          } while (while_flag_677);
          (void)VOID;
          uint8_t id_691 { 0 };
          uint32_t id_692 { lebsz_ref_715[id_691] };
          Size id_693 { Size(id_692) };
          let_res_676 = id_693;
        }
        let_res_673 = let_res_676;
      }
      Size id_694 { Size(id_668 + let_res_673) };
      Vec<1, Size> id_695 {  id_694  };
      Size let_res_696;
      {
        Vec<1, Size> sz_ref_716 { id_695 };
        int32_t id_697 { 0L };
        Vec<1, int32_t> id_698 {  id_697  };
        {
          Vec<1, int32_t> repeat_n_717 { id_698 };
          bool while_flag_699 { true };
          do {
            ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_700 { std::get<1 /* Kafka */>((*p_0)) };
            Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> id_701 { id_700.options };
            uint32_t id_702 { id_701.size() };
            int32_t id_703 { int32_t(id_702) };
            uint8_t id_704 { 0 };
            int32_t id_705 { repeat_n_717[id_704] };
            bool id_706 { bool(id_703 > id_705) };
            while_flag_699 = id_706;
            if (while_flag_699) {
              uint8_t id_707 { 0 };
              uint8_t id_708 { 0 };
              Size id_709 { sz_ref_716[id_708] };
              Size let_res_710;
              {
                Size sz_718 { id_709 };
                uint8_t id_711 { 0 };
                int32_t id_712 { repeat_n_717[id_711] };
                ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_713 { std::get<1 /* Kafka */>((*p_0)) };
                Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> id_714 { id_713.options };
                ::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed id_715 { id_714[id_712] };
                std::string id_716 { std::get<0>(id_715) };
                uint32_t id_717 { (uint32_t)id_716.size() };
                Size let_res_718;
                {
                  uint32_t wlen_719 { id_717 };
                  Vec<1, uint32_t> id_719 {  wlen_719  };
                  Size let_res_720;
                  {
                    Vec<1, uint32_t> n_ref_720 { id_719 };
                    uint32_t id_721 { 1U };
                    Vec<1, uint32_t> id_722 {  id_721  };
                    Size let_res_723;
                    {
                      Vec<1, uint32_t> lebsz_ref_721 { id_722 };
                      bool while_flag_724 { true };
                      do {
                        uint8_t id_725 { 0 };
                        uint32_t id_726 { n_ref_720[id_725] };
                        uint8_t id_727 { 0 };
                        uint32_t id_728 { lebsz_ref_721[id_727] };
                        uint8_t id_729 { 7 };
                        uint32_t id_730 { uint32_t(id_728 << id_729) };
                        bool id_731 { bool(id_726 >= id_730) };
                        while_flag_724 = id_731;
                        if (while_flag_724) {
                          uint8_t id_732 { 0 };
                          uint8_t id_733 { 0 };
                          uint32_t id_734 { lebsz_ref_721[id_733] };
                          uint32_t id_735 { 1U };
                          uint32_t id_736 { uint32_t(id_734 + id_735) };
                          Void id_737 { ((void)(lebsz_ref_721[id_732] = id_736), VOID) };
                          (void)id_737;
                        }
                      } while (while_flag_724);
                      (void)VOID;
                      uint8_t id_738 { 0 };
                      uint32_t id_739 { lebsz_ref_721[id_738] };
                      Size id_740 { Size(id_739) };
                      let_res_723 = id_740;
                    }
                    let_res_720 = let_res_723;
                  }
                  Size id_741 { Size(wlen_719) };
                  Size id_742 { Size(let_res_720 + id_741) };
                  let_res_718 = id_742;
                }
                Size id_743 { Size(sz_718 + let_res_718) };
                let_res_710 = id_743;
              }
              Size let_res_744;
              {
                Size sz_722 { let_res_710 };
                auto fun745 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_746 { 0 };
                int32_t id_747 { repeat_n_717[id_746] };
                ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_748 { std::get<1 /* Kafka */>((*p_0)) };
                Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> id_749 { id_748.options };
                ::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed id_750 { id_749[id_747] };
                dessser::gen::raql_expr::t_ext id_751 { std::get<1>(id_750) };
                Size id_752 { fun745(id_751) };
                Size id_753 { Size(sz_722 + id_752) };
                let_res_744 = id_753;
              }
              Void id_754 { ((void)(sz_ref_716[id_707] = let_res_744), VOID) };
              (void)id_754;
              uint8_t id_755 { 0 };
              uint8_t id_756 { 0 };
              int32_t id_757 { repeat_n_717[id_756] };
              int32_t id_758 { 1L };
              int32_t id_759 { int32_t(id_757 + id_758) };
              Void id_760 { ((void)(repeat_n_717[id_755] = id_759), VOID) };
              (void)id_760;
              (void)id_760;
            }
          } while (while_flag_699);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_761 { 0 };
        Size id_762 { sz_ref_716[id_761] };
        let_res_696 = id_762;
      }
      Size let_res_763;
      {
        Size sz_723 { let_res_696 };
        auto fun764 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_765 { std::get<1 /* Kafka */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_766 { id_765.topic };
        Size id_767 { fun764(id_766) };
        Size id_768 { Size(sz_723 + id_767) };
        let_res_763 = id_768;
      }
      Size let_res_769;
      {
        Size sz_724 { let_res_763 };
        ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_770 { std::get<1 /* Kafka */>((*p_0)) };
        std::optional<dessser::gen::raql_expr::t_ext> id_771 { id_770.partitions };
        bool id_772 { !(id_771.has_value ()) };
        Size choose_res_773;
        if (id_772) {
          Size id_774 { 1UL };
          Size id_775 { Size(sz_724 + id_774) };
          choose_res_773 = id_775;
        } else {
          auto fun776 { dessser::gen::raql_expr::sersize_of_row_binary };
          ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_777 { std::get<1 /* Kafka */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_778 { id_777.partitions };
          dessser::gen::raql_expr::t_ext id_779 { id_778.value() };
          Size id_780 { fun776(id_779) };
          Size id_781 { Size(sz_724 + id_780) };
          Size id_782 { 1UL };
          Size id_783 { Size(id_781 + id_782) };
          choose_res_773 = id_783;
        }
        let_res_769 = choose_res_773;
      }
      Size let_res_784;
      {
        Size sz_725 { let_res_769 };
        uint16_t id_785 { 0 };
        ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_786 { std::get<1 /* Kafka */>((*p_0)) };
        ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_787 { id_786.restart_from };
        uint16_t id_788 { uint16_t(id_787.index()) };
        bool id_789 { bool(id_785 == id_788) };
        Size choose_res_790;
        if (id_789) {
          Size id_791 { 2UL };
          Size id_792 { Size(sz_725 + id_791) };
          choose_res_790 = id_792;
        } else {
          uint16_t id_793 { 1 };
          ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_794 { std::get<1 /* Kafka */>((*p_0)) };
          ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_795 { id_794.restart_from };
          uint16_t id_796 { uint16_t(id_795.index()) };
          bool id_797 { bool(id_793 == id_796) };
          Size choose_res_798;
          if (id_797) {
            Size id_799 { 2UL };
            Size id_800 { Size(sz_725 + id_799) };
            auto fun801 { dessser::gen::raql_expr::sersize_of_row_binary };
            ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_802 { std::get<1 /* Kafka */>((*p_0)) };
            ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_803 { id_802.restart_from };
            dessser::gen::raql_expr::t_ext id_804 { std::get<1 /* OffsetFromEnd */>(id_803) };
            Size id_805 { fun801(id_804) };
            Size id_806 { Size(id_800 + id_805) };
            choose_res_798 = id_806;
          } else {
            uint16_t id_807 { 2 };
            ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_808 { std::get<1 /* Kafka */>((*p_0)) };
            ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_809 { id_808.restart_from };
            uint16_t id_810 { uint16_t(id_809.index()) };
            bool id_811 { bool(id_807 == id_810) };
            Size choose_res_812;
            if (id_811) {
              Size id_813 { 2UL };
              Size id_814 { Size(sz_725 + id_813) };
              choose_res_812 = id_814;
            } else {
              ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_815 { std::get<1 /* Kafka */>((*p_0)) };
              ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_816 { id_815.restart_from };
              uint16_t id_817 { uint16_t(id_816.index()) };
              uint16_t id_818 { 3 };
              bool id_819 { bool(id_817 == id_818) };
              Void id_820 { ((void)(assert(id_819)), VOID) };
              (void)id_820;
              Size id_821 { 2UL };
              Size id_822 { Size(sz_725 + id_821) };
              auto fun823 { dessser::gen::raql_expr::sersize_of_row_binary };
              ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_824 { std::get<1 /* Kafka */>((*p_0)) };
              ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_825 { id_824.restart_from };
              ::dessser::gen::raql_operation::tb07656d6bb51183c62956887bcdc8cf2 id_826 { std::get<3 /* UseKafkaGroupCoordinator */>(id_825) };
              dessser::gen::raql_expr::t_ext id_827 { id_826.after_max_secs };
              Size id_828 { fun823(id_827) };
              Size id_829 { Size(id_822 + id_828) };
              Size let_res_830;
              {
                Size sz_728 { id_829 };
                auto fun831 { dessser::gen::raql_expr::sersize_of_row_binary };
                ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_832 { std::get<1 /* Kafka */>((*p_0)) };
                ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_833 { id_832.restart_from };
                ::dessser::gen::raql_operation::tb07656d6bb51183c62956887bcdc8cf2 id_834 { std::get<3 /* UseKafkaGroupCoordinator */>(id_833) };
                dessser::gen::raql_expr::t_ext id_835 { id_834.after_max_events };
                Size id_836 { fun831(id_835) };
                Size id_837 { Size(sz_728 + id_836) };
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
std::function<Size(::dessser::gen::raql_operation::external_source*)> external_source_sersize_of_row_binary(external_source_sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_360" "make_snd_361"
        (let "dsum1_247" (let-pair "du16_fst_242" "du16_snd_243" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_242") (identifier "du16_snd_243")))
          (let-pair "dsum1_fst_248" "dsum1_snd_249" (identifier "dsum1_247")
            (if (eq (u16 0) (identifier "dsum1_fst_248"))
              (let "drec_279" (let-pair "dchar_fst_277" "dchar_snd_278" (read-u8 (identifier "dsum1_snd_249")) (make-tup (char-of-u8 (identifier "dchar_fst_277")) (identifier "dchar_snd_278")))
                (let-pair "drec_fst_280" "drec_snd_281" (identifier "drec_279")
                  (let "drec_294"
                    (let "dstring1_288"
                      (let "leb_ref_282" (make-vec (u32 0))
                        (let "shft_ref_283" (make-vec (u8 0))
                          (let "p_ref_284" (make-vec (identifier "drec_snd_281"))
                            (seq
                              (while
                                (let "leb128_285" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_284")))
                                  (let-pair "leb128_fst_286" "leb128_snd_287" 
                                    (identifier "leb128_285")
                                    (seq (set-vec (u8 0) (identifier "p_ref_284") (identifier "leb128_snd_287"))
                                      (set-vec (u8 0) (identifier "leb_ref_282")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_286") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_283"))) (unsafe-nth (u8 0) (identifier "leb_ref_282"))))
                                      (set-vec (u8 0) (identifier "shft_ref_283") (add (unsafe-nth (u8 0) (identifier "shft_ref_283")) (u8 7))) 
                                      (ge (identifier "leb128_fst_286") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_282"))) (unsafe-nth (u8 0) (identifier "p_ref_284")))))))
                      (let-pair "dstring1_fst_289" "dstring1_snd_290" 
                        (identifier "dstring1_288")
                        (let-pair "dstring2_fst_292" "dstring2_snd_293" 
                          (read-bytes (identifier "dstring1_snd_290") (identifier "dstring1_fst_289")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_292")) (identifier "dstring2_snd_293")))))
                    (let-pair "drec_fst_295" "drec_snd_296" (identifier "drec_294")
                      (let "drec_300" (let-pair "dbool_fst_298" "dbool_snd_299" (read-u8 (identifier "drec_snd_296")) (make-tup (not (eq (identifier "dbool_fst_298") (u8 0))) (identifier "dbool_snd_299")))
                        (let-pair "drec_fst_301" "drec_snd_302" (identifier "drec_300")
                          (let "drec_315"
                            (let "dstring1_309"
                              (let "leb_ref_303" (make-vec (u32 0))
                                (let "shft_ref_304" (make-vec (u8 0))
                                  (let "p_ref_305" (make-vec (identifier "drec_snd_302"))
                                    (seq
                                      (while
                                        (let "leb128_306" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_305")))
                                          (let-pair "leb128_fst_307" "leb128_snd_308" 
                                            (identifier "leb128_306")
                                            (seq (set-vec (u8 0) (identifier "p_ref_305") (identifier "leb128_snd_308"))
                                              (set-vec (u8 0) (identifier "leb_ref_303")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_307") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_304"))) (unsafe-nth (u8 0) (identifier "leb_ref_303"))))
                                              (set-vec (u8 0) (identifier "shft_ref_304") (add (unsafe-nth (u8 0) (identifier "shft_ref_304")) (u8 7))) 
                                              (ge (identifier "leb128_fst_307") (u8 128))))) 
                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_303"))) (unsafe-nth (u8 0) (identifier "p_ref_305")))))))
                              (let-pair "dstring1_fst_310" "dstring1_snd_311" 
                                (identifier "dstring1_309")
                                (let-pair "dstring2_fst_313" "dstring2_snd_314" 
                                  (read-bytes (identifier "dstring1_snd_311") (identifier "dstring1_fst_310")) 
                                  (make-tup (string-of-bytes (identifier "dstring2_fst_313")) (identifier "dstring2_snd_314")))))
                            (let-pair "drec_fst_316" "drec_snd_317" (identifier "drec_315")
                              (let "drec_341"
                                (let-pair "dlist4_fst_339" "dlist4_snd_340"
                                  (let "dlist1_327"
                                    (let "leb_ref_318" (make-vec (u32 0))
                                      (let "shft_ref_319" (make-vec (u8 0))
                                        (let "p_ref_320" (make-vec (identifier "drec_snd_317"))
                                          (seq
                                            (while
                                              (let "leb128_321" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_320")))
                                                (let-pair "leb128_fst_322" "leb128_snd_323" 
                                                  (identifier "leb128_321")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_320") (identifier "leb128_snd_323"))
                                                    (set-vec (u8 0) (identifier "leb_ref_318")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_322") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_319"))) (unsafe-nth (u8 0) (identifier "leb_ref_318"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_319") (add (unsafe-nth (u8 0) (identifier "shft_ref_319")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_322") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_318")) (unsafe-nth (u8 0) (identifier "p_ref_320")))))))
                                    (let-pair "dlist1_fst_328" "dlist1_snd_329" 
                                      (identifier "dlist1_327")
                                      (let "inits_src_ref_330" (make-vec (make-tup (end-of-list "$field_type") (identifier "dlist1_snd_329")))
                                        (seq
                                          (let "repeat_n_331" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_328")) (unsafe-nth (u8 0) (identifier "repeat_n_331")))
                                              (seq
                                                (let "dlist2_332" (unsafe-nth (u8 0) (identifier "inits_src_ref_330"))
                                                  (let-pair "dlist2_fst_333" "dlist2_snd_334" 
                                                    (identifier "dlist2_332")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_330")
                                                      (let-pair "dlist3_fst_336" "dlist3_snd_337" 
                                                        (apply (ext-identifier field_type of-row-binary) (identifier "dlist2_snd_334"))
                                                        (make-tup (cons (identifier "dlist3_fst_336") (identifier "dlist2_fst_333")) (identifier "dlist3_snd_337"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_331") (add (unsafe-nth (u8 0) (identifier "repeat_n_331")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_330")))))) 
                                  (make-tup (identity (identifier "dlist4_fst_339")) (identifier "dlist4_snd_340")))
                                (let-pair "drec_fst_342" "drec_snd_343" 
                                  (identifier "drec_341")
                                  (let "drec_347" (let-pair "dbool_fst_345" "dbool_snd_346" (read-u8 (identifier "drec_snd_343")) (make-tup (not (eq (identifier "dbool_fst_345") (u8 0))) (identifier "dbool_snd_346")))
                                    (let-pair "drec_fst_348" "drec_snd_349" 
                                      (identifier "drec_347")
                                      (let-pair "dbool_fst_351" "dbool_snd_352" 
                                        (read-u8 (identifier "drec_snd_349"))
                                        (make-tup
                                          (construct "[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" 0
                                            (make-rec (string "clickhouse_syntax") 
                                              (not (eq (identifier "dbool_fst_351") (u8 0))) 
                                              (string "vectors_of_chars_as_string") 
                                              (identifier "drec_fst_348") 
                                              (string "fields") (identifier "drec_fst_342") 
                                              (string "escape_seq") (identifier "drec_fst_316") 
                                              (string "may_quote") (identifier "drec_fst_301") 
                                              (string "null") (identifier "drec_fst_295") 
                                              (string "separator") (identifier "drec_fst_280"))) 
                                          (identifier "dbool_snd_352")))))))))))))))
              (seq (assert (eq (identifier "dsum1_fst_248") (u16 1)))
                (let-pair "dlist4_fst_271" "dlist4_snd_272"
                  (let "dlist1_259"
                    (let "leb_ref_250" (make-vec (u32 0))
                      (let "shft_ref_251" (make-vec (u8 0))
                        (let "p_ref_252" (make-vec (identifier "dsum1_snd_249"))
                          (seq
                            (while
                              (let "leb128_253" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_252")))
                                (let-pair "leb128_fst_254" "leb128_snd_255" 
                                  (identifier "leb128_253")
                                  (seq (set-vec (u8 0) (identifier "p_ref_252") (identifier "leb128_snd_255"))
                                    (set-vec (u8 0) (identifier "leb_ref_250")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_254") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_251"))) (unsafe-nth (u8 0) (identifier "leb_ref_250"))))
                                    (set-vec (u8 0) (identifier "shft_ref_251") (add (unsafe-nth (u8 0) (identifier "shft_ref_251")) (u8 7))) 
                                    (ge (identifier "leb128_fst_254") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_250")) (unsafe-nth (u8 0) (identifier "p_ref_252")))))))
                    (let-pair "dlist1_fst_260" "dlist1_snd_261" (identifier "dlist1_259")
                      (let "inits_src_ref_262" (make-vec (make-tup (end-of-list "$field_type") (identifier "dlist1_snd_261")))
                        (seq
                          (let "repeat_n_263" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_260")) (unsafe-nth (u8 0) (identifier "repeat_n_263")))
                              (seq
                                (let "dlist2_264" (unsafe-nth (u8 0) (identifier "inits_src_ref_262"))
                                  (let-pair "dlist2_fst_265" "dlist2_snd_266" 
                                    (identifier "dlist2_264")
                                    (set-vec (u8 0) (identifier "inits_src_ref_262")
                                      (let-pair "dlist3_fst_268" "dlist3_snd_269" 
                                        (apply (ext-identifier field_type of-row-binary) (identifier "dlist2_snd_266")) 
                                        (make-tup (cons (identifier "dlist3_fst_268") (identifier "dlist2_fst_265")) (identifier "dlist3_snd_269"))))))
                                (set-vec (u8 0) (identifier "repeat_n_263") (add (unsafe-nth (u8 0) (identifier "repeat_n_263")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_262"))))))
                  (make-tup
                    (construct "[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" 1
                      (identity (identifier "dlist4_fst_271"))) (identifier "dlist4_snd_272"))))))) 
        (make-tup (identifier "make_fst_360") (identifier "make_snd_361"))))
 */
static std::function<::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6(Pointer)> external_format_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6(Pointer)> fun838 { [&fun838](Pointer p_0) {
    ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_839 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 letpair_res_840;
    {
      auto du16_fst_242 { std::get<0>(id_839) };
      auto du16_snd_243 { std::get<1>(id_839) };
      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_841 { du16_fst_242, du16_snd_243 };
      letpair_res_840 = id_841;
    }
    ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 let_res_842;
    {
      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 dsum1_247 { letpair_res_840 };
      ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_843;
      {
        auto dsum1_fst_248 { std::get<0>(dsum1_247) };
        auto dsum1_snd_249 { std::get<1>(dsum1_247) };
        uint16_t id_844 { 0 };
        bool id_845 { bool(id_844 == dsum1_fst_248) };
        ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 choose_res_846;
        if (id_845) {
          ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_847 { dsum1_snd_249.readU8() };
          ::dessser::gen::raql_operation::t9c427530664aa522ce95ad420b884056 letpair_res_848;
          {
            auto dchar_fst_277 { std::get<0>(id_847) };
            auto dchar_snd_278 { std::get<1>(id_847) };
            char id_849 { char(dchar_fst_277) };
            ::dessser::gen::raql_operation::t9c427530664aa522ce95ad420b884056 id_850 { id_849, dchar_snd_278 };
            letpair_res_848 = id_850;
          }
          ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 let_res_851;
          {
            ::dessser::gen::raql_operation::t9c427530664aa522ce95ad420b884056 drec_279 { letpair_res_848 };
            ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_852;
            {
              auto drec_fst_280 { std::get<0>(drec_279) };
              auto drec_snd_281 { std::get<1>(drec_279) };
              uint32_t id_853 { 0U };
              Vec<1, uint32_t> id_854 {  id_853  };
              ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_855;
              {
                Vec<1, uint32_t> leb_ref_282 { id_854 };
                uint8_t id_856 { 0 };
                Vec<1, uint8_t> id_857 {  id_856  };
                ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_858;
                {
                  Vec<1, uint8_t> shft_ref_283 { id_857 };
                  Vec<1, Pointer> id_859 {  drec_snd_281  };
                  ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_860;
                  {
                    Vec<1, Pointer> p_ref_284 { id_859 };
                    bool while_flag_861 { true };
                    do {
                      uint8_t id_862 { 0 };
                      Pointer id_863 { p_ref_284[id_862] };
                      ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_864 { id_863.readU8() };
                      bool let_res_865;
                      {
                        ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_285 { id_864 };
                        bool letpair_res_866;
                        {
                          auto leb128_fst_286 { std::get<0>(leb128_285) };
                          auto leb128_snd_287 { std::get<1>(leb128_285) };
                          uint8_t id_867 { 0 };
                          Void id_868 { ((void)(p_ref_284[id_867] = leb128_snd_287), VOID) };
                          (void)id_868;
                          uint8_t id_869 { 0 };
                          uint8_t id_870 { 127 };
                          uint8_t id_871 { uint8_t(leb128_fst_286 & id_870) };
                          uint32_t id_872 { uint32_t(id_871) };
                          uint8_t id_873 { 0 };
                          uint8_t id_874 { shft_ref_283[id_873] };
                          uint32_t id_875 { uint32_t(id_872 << id_874) };
                          uint8_t id_876 { 0 };
                          uint32_t id_877 { leb_ref_282[id_876] };
                          uint32_t id_878 { uint32_t(id_875 | id_877) };
                          Void id_879 { ((void)(leb_ref_282[id_869] = id_878), VOID) };
                          (void)id_879;
                          uint8_t id_880 { 0 };
                          uint8_t id_881 { 0 };
                          uint8_t id_882 { shft_ref_283[id_881] };
                          uint8_t id_883 { 7 };
                          uint8_t id_884 { uint8_t(id_882 + id_883) };
                          Void id_885 { ((void)(shft_ref_283[id_880] = id_884), VOID) };
                          (void)id_885;
                          uint8_t id_886 { 128 };
                          bool id_887 { bool(leb128_fst_286 >= id_886) };
                          letpair_res_866 = id_887;
                        }
                        let_res_865 = letpair_res_866;
                      }
                      while_flag_861 = let_res_865;
                      if (while_flag_861) {
                        (void)VOID;
                      }
                    } while (while_flag_861);
                    (void)VOID;
                    uint8_t id_888 { 0 };
                    uint32_t id_889 { leb_ref_282[id_888] };
                    Size id_890 { Size(id_889) };
                    uint8_t id_891 { 0 };
                    Pointer id_892 { p_ref_284[id_891] };
                    ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c id_893 { id_890, id_892 };
                    let_res_860 = id_893;
                  }
                  let_res_858 = let_res_860;
                }
                let_res_855 = let_res_858;
              }
              ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e let_res_894;
              {
                ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c dstring1_288 { let_res_855 };
                ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e letpair_res_895;
                {
                  auto dstring1_fst_289 { std::get<0>(dstring1_288) };
                  auto dstring1_snd_290 { std::get<1>(dstring1_288) };
                  ::dessser::gen::raql_operation::t188345aa49abd0cb47ff73fedc219f08 id_896 { dstring1_snd_290.readBytes(dstring1_fst_289) };
                  ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e letpair_res_897;
                  {
                    auto dstring2_fst_292 { std::get<0>(id_896) };
                    auto dstring2_snd_293 { std::get<1>(id_896) };
                    std::string id_898 { dstring2_fst_292.toString() };
                    ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e id_899 { id_898, dstring2_snd_293 };
                    letpair_res_897 = id_899;
                  }
                  letpair_res_895 = letpair_res_897;
                }
                let_res_894 = letpair_res_895;
              }
              ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 let_res_900;
              {
                ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e drec_294 { let_res_894 };
                ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_901;
                {
                  auto drec_fst_295 { std::get<0>(drec_294) };
                  auto drec_snd_296 { std::get<1>(drec_294) };
                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_902 { drec_snd_296.readU8() };
                  ::dessser::gen::raql_operation::t4138de986e20d18b01e4c493dc9d5451 letpair_res_903;
                  {
                    auto dbool_fst_298 { std::get<0>(id_902) };
                    auto dbool_snd_299 { std::get<1>(id_902) };
                    uint8_t id_904 { 0 };
                    bool id_905 { bool(dbool_fst_298 == id_904) };
                    bool id_906 { ! id_905 };
                    ::dessser::gen::raql_operation::t4138de986e20d18b01e4c493dc9d5451 id_907 { id_906, dbool_snd_299 };
                    letpair_res_903 = id_907;
                  }
                  ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 let_res_908;
                  {
                    ::dessser::gen::raql_operation::t4138de986e20d18b01e4c493dc9d5451 drec_300 { letpair_res_903 };
                    ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_909;
                    {
                      auto drec_fst_301 { std::get<0>(drec_300) };
                      auto drec_snd_302 { std::get<1>(drec_300) };
                      uint32_t id_910 { 0U };
                      Vec<1, uint32_t> id_911 {  id_910  };
                      ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_912;
                      {
                        Vec<1, uint32_t> leb_ref_303 { id_911 };
                        uint8_t id_913 { 0 };
                        Vec<1, uint8_t> id_914 {  id_913  };
                        ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_915;
                        {
                          Vec<1, uint8_t> shft_ref_304 { id_914 };
                          Vec<1, Pointer> id_916 {  drec_snd_302  };
                          ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_917;
                          {
                            Vec<1, Pointer> p_ref_305 { id_916 };
                            bool while_flag_918 { true };
                            do {
                              uint8_t id_919 { 0 };
                              Pointer id_920 { p_ref_305[id_919] };
                              ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_921 { id_920.readU8() };
                              bool let_res_922;
                              {
                                ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_306 { id_921 };
                                bool letpair_res_923;
                                {
                                  auto leb128_fst_307 { std::get<0>(leb128_306) };
                                  auto leb128_snd_308 { std::get<1>(leb128_306) };
                                  uint8_t id_924 { 0 };
                                  Void id_925 { ((void)(p_ref_305[id_924] = leb128_snd_308), VOID) };
                                  (void)id_925;
                                  uint8_t id_926 { 0 };
                                  uint8_t id_927 { 127 };
                                  uint8_t id_928 { uint8_t(leb128_fst_307 & id_927) };
                                  uint32_t id_929 { uint32_t(id_928) };
                                  uint8_t id_930 { 0 };
                                  uint8_t id_931 { shft_ref_304[id_930] };
                                  uint32_t id_932 { uint32_t(id_929 << id_931) };
                                  uint8_t id_933 { 0 };
                                  uint32_t id_934 { leb_ref_303[id_933] };
                                  uint32_t id_935 { uint32_t(id_932 | id_934) };
                                  Void id_936 { ((void)(leb_ref_303[id_926] = id_935), VOID) };
                                  (void)id_936;
                                  uint8_t id_937 { 0 };
                                  uint8_t id_938 { 0 };
                                  uint8_t id_939 { shft_ref_304[id_938] };
                                  uint8_t id_940 { 7 };
                                  uint8_t id_941 { uint8_t(id_939 + id_940) };
                                  Void id_942 { ((void)(shft_ref_304[id_937] = id_941), VOID) };
                                  (void)id_942;
                                  uint8_t id_943 { 128 };
                                  bool id_944 { bool(leb128_fst_307 >= id_943) };
                                  letpair_res_923 = id_944;
                                }
                                let_res_922 = letpair_res_923;
                              }
                              while_flag_918 = let_res_922;
                              if (while_flag_918) {
                                (void)VOID;
                              }
                            } while (while_flag_918);
                            (void)VOID;
                            uint8_t id_945 { 0 };
                            uint32_t id_946 { leb_ref_303[id_945] };
                            Size id_947 { Size(id_946) };
                            uint8_t id_948 { 0 };
                            Pointer id_949 { p_ref_305[id_948] };
                            ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c id_950 { id_947, id_949 };
                            let_res_917 = id_950;
                          }
                          let_res_915 = let_res_917;
                        }
                        let_res_912 = let_res_915;
                      }
                      ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e let_res_951;
                      {
                        ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c dstring1_309 { let_res_912 };
                        ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e letpair_res_952;
                        {
                          auto dstring1_fst_310 { std::get<0>(dstring1_309) };
                          auto dstring1_snd_311 { std::get<1>(dstring1_309) };
                          ::dessser::gen::raql_operation::t188345aa49abd0cb47ff73fedc219f08 id_953 { dstring1_snd_311.readBytes(dstring1_fst_310) };
                          ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e letpair_res_954;
                          {
                            auto dstring2_fst_313 { std::get<0>(id_953) };
                            auto dstring2_snd_314 { std::get<1>(id_953) };
                            std::string id_955 { dstring2_fst_313.toString() };
                            ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e id_956 { id_955, dstring2_snd_314 };
                            letpair_res_954 = id_956;
                          }
                          letpair_res_952 = letpair_res_954;
                        }
                        let_res_951 = letpair_res_952;
                      }
                      ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 let_res_957;
                      {
                        ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e drec_315 { let_res_951 };
                        ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_958;
                        {
                          auto drec_fst_316 { std::get<0>(drec_315) };
                          auto drec_snd_317 { std::get<1>(drec_315) };
                          uint32_t id_959 { 0U };
                          Vec<1, uint32_t> id_960 {  id_959  };
                          ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_961;
                          {
                            Vec<1, uint32_t> leb_ref_318 { id_960 };
                            uint8_t id_962 { 0 };
                            Vec<1, uint8_t> id_963 {  id_962  };
                            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_964;
                            {
                              Vec<1, uint8_t> shft_ref_319 { id_963 };
                              Vec<1, Pointer> id_965 {  drec_snd_317  };
                              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_966;
                              {
                                Vec<1, Pointer> p_ref_320 { id_965 };
                                bool while_flag_967 { true };
                                do {
                                  uint8_t id_968 { 0 };
                                  Pointer id_969 { p_ref_320[id_968] };
                                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_970 { id_969.readU8() };
                                  bool let_res_971;
                                  {
                                    ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_321 { id_970 };
                                    bool letpair_res_972;
                                    {
                                      auto leb128_fst_322 { std::get<0>(leb128_321) };
                                      auto leb128_snd_323 { std::get<1>(leb128_321) };
                                      uint8_t id_973 { 0 };
                                      Void id_974 { ((void)(p_ref_320[id_973] = leb128_snd_323), VOID) };
                                      (void)id_974;
                                      uint8_t id_975 { 0 };
                                      uint8_t id_976 { 127 };
                                      uint8_t id_977 { uint8_t(leb128_fst_322 & id_976) };
                                      uint32_t id_978 { uint32_t(id_977) };
                                      uint8_t id_979 { 0 };
                                      uint8_t id_980 { shft_ref_319[id_979] };
                                      uint32_t id_981 { uint32_t(id_978 << id_980) };
                                      uint8_t id_982 { 0 };
                                      uint32_t id_983 { leb_ref_318[id_982] };
                                      uint32_t id_984 { uint32_t(id_981 | id_983) };
                                      Void id_985 { ((void)(leb_ref_318[id_975] = id_984), VOID) };
                                      (void)id_985;
                                      uint8_t id_986 { 0 };
                                      uint8_t id_987 { 0 };
                                      uint8_t id_988 { shft_ref_319[id_987] };
                                      uint8_t id_989 { 7 };
                                      uint8_t id_990 { uint8_t(id_988 + id_989) };
                                      Void id_991 { ((void)(shft_ref_319[id_986] = id_990), VOID) };
                                      (void)id_991;
                                      uint8_t id_992 { 128 };
                                      bool id_993 { bool(leb128_fst_322 >= id_992) };
                                      letpair_res_972 = id_993;
                                    }
                                    let_res_971 = letpair_res_972;
                                  }
                                  while_flag_967 = let_res_971;
                                  if (while_flag_967) {
                                    (void)VOID;
                                  }
                                } while (while_flag_967);
                                (void)VOID;
                                uint8_t id_994 { 0 };
                                uint32_t id_995 { leb_ref_318[id_994] };
                                uint8_t id_996 { 0 };
                                Pointer id_997 { p_ref_320[id_996] };
                                ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_998 { id_995, id_997 };
                                let_res_966 = id_998;
                              }
                              let_res_964 = let_res_966;
                            }
                            let_res_961 = let_res_964;
                          }
                          ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e let_res_999;
                          {
                            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_327 { let_res_961 };
                            ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e letpair_res_1000;
                            {
                              auto dlist1_fst_328 { std::get<0>(dlist1_327) };
                              auto dlist1_snd_329 { std::get<1>(dlist1_327) };
                              Lst<dessser::gen::field_type::t_ext> endoflist_1001;
                              ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e id_1002 { endoflist_1001, dlist1_snd_329 };
                              Vec<1, ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e> id_1003 {  id_1002  };
                              ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e let_res_1004;
                              {
                                Vec<1, ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e> inits_src_ref_330 { id_1003 };
                                int32_t id_1005 { 0L };
                                Vec<1, int32_t> id_1006 {  id_1005  };
                                {
                                  Vec<1, int32_t> repeat_n_331 { id_1006 };
                                  bool while_flag_1007 { true };
                                  do {
                                    int32_t id_1008 { int32_t(dlist1_fst_328) };
                                    uint8_t id_1009 { 0 };
                                    int32_t id_1010 { repeat_n_331[id_1009] };
                                    bool id_1011 { bool(id_1008 > id_1010) };
                                    while_flag_1007 = id_1011;
                                    if (while_flag_1007) {
                                      uint8_t id_1012 { 0 };
                                      ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e id_1013 { inits_src_ref_330[id_1012] };
                                      {
                                        ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e dlist2_332 { id_1013 };
                                        {
                                          auto dlist2_fst_333 { std::get<0>(dlist2_332) };
                                          auto dlist2_snd_334 { std::get<1>(dlist2_332) };
                                          uint8_t id_1014 { 0 };
                                          auto fun1015 { dessser::gen::field_type::of_row_binary };
                                          ::dessser::gen::raql_operation::t2f09fa79b0bdf1902e3b53bc7e485604 id_1016 { fun1015(dlist2_snd_334) };
                                          ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e letpair_res_1017;
                                          {
                                            auto dlist3_fst_336 { std::get<0>(id_1016) };
                                            auto dlist3_snd_337 { std::get<1>(id_1016) };
                                            Lst<dessser::gen::field_type::t_ext> id_1018 { dlist3_fst_336, dlist2_fst_333 };
                                            ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e id_1019 { id_1018, dlist3_snd_337 };
                                            letpair_res_1017 = id_1019;
                                          }
                                          Void id_1020 { ((void)(inits_src_ref_330[id_1014] = letpair_res_1017), VOID) };
                                          (void)id_1020;
                                        }
                                        (void)VOID;
                                      }
                                      (void)VOID;
                                      uint8_t id_1021 { 0 };
                                      uint8_t id_1022 { 0 };
                                      int32_t id_1023 { repeat_n_331[id_1022] };
                                      int32_t id_1024 { 1L };
                                      int32_t id_1025 { int32_t(id_1023 + id_1024) };
                                      Void id_1026 { ((void)(repeat_n_331[id_1021] = id_1025), VOID) };
                                      (void)id_1026;
                                      (void)id_1026;
                                    }
                                  } while (while_flag_1007);
                                  (void)VOID;
                                }
                                (void)VOID;
                                uint8_t id_1027 { 0 };
                                ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e id_1028 { inits_src_ref_330[id_1027] };
                                let_res_1004 = id_1028;
                              }
                              letpair_res_1000 = let_res_1004;
                            }
                            let_res_999 = letpair_res_1000;
                          }
                          ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e letpair_res_1029;
                          {
                            auto dlist4_fst_339 { std::get<0>(let_res_999) };
                            auto dlist4_snd_340 { std::get<1>(let_res_999) };
                            ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e id_1030 { dlist4_fst_339, dlist4_snd_340 };
                            letpair_res_1029 = id_1030;
                          }
                          ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 let_res_1031;
                          {
                            ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e drec_341 { letpair_res_1029 };
                            ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_1032;
                            {
                              auto drec_fst_342 { std::get<0>(drec_341) };
                              auto drec_snd_343 { std::get<1>(drec_341) };
                              ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_1033 { drec_snd_343.readU8() };
                              ::dessser::gen::raql_operation::t4138de986e20d18b01e4c493dc9d5451 letpair_res_1034;
                              {
                                auto dbool_fst_345 { std::get<0>(id_1033) };
                                auto dbool_snd_346 { std::get<1>(id_1033) };
                                uint8_t id_1035 { 0 };
                                bool id_1036 { bool(dbool_fst_345 == id_1035) };
                                bool id_1037 { ! id_1036 };
                                ::dessser::gen::raql_operation::t4138de986e20d18b01e4c493dc9d5451 id_1038 { id_1037, dbool_snd_346 };
                                letpair_res_1034 = id_1038;
                              }
                              ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 let_res_1039;
                              {
                                ::dessser::gen::raql_operation::t4138de986e20d18b01e4c493dc9d5451 drec_347 { letpair_res_1034 };
                                ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_1040;
                                {
                                  auto drec_fst_348 { std::get<0>(drec_347) };
                                  auto drec_snd_349 { std::get<1>(drec_347) };
                                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_1041 { drec_snd_349.readU8() };
                                  ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_1042;
                                  {
                                    auto dbool_fst_351 { std::get<0>(id_1041) };
                                    auto dbool_snd_352 { std::get<1>(id_1041) };
                                    uint8_t id_1043 { 0 };
                                    bool id_1044 { bool(dbool_fst_351 == id_1043) };
                                    bool id_1045 { ! id_1044 };
                                    ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f id_1046 { .clickhouse_syntax = id_1045, .escape_seq = drec_fst_316, .fields = drec_fst_342, .may_quote = drec_fst_301, .null = drec_fst_295, .separator = drec_fst_280, .vectors_of_chars_as_string = drec_fst_348 };
                                    ::dessser::gen::raql_operation::external_format* id_1047 { new ::dessser::gen::raql_operation::external_format(std::in_place_index<0>, id_1046) };
                                    ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 id_1048 { id_1047, dbool_snd_352 };
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
          bool id_1050 { bool(dsum1_fst_248 == id_1049) };
          Void id_1051 { ((void)(assert(id_1050)), VOID) };
          (void)id_1051;
          uint32_t id_1052 { 0U };
          Vec<1, uint32_t> id_1053 {  id_1052  };
          ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_1054;
          {
            Vec<1, uint32_t> leb_ref_250 { id_1053 };
            uint8_t id_1055 { 0 };
            Vec<1, uint8_t> id_1056 {  id_1055  };
            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_1057;
            {
              Vec<1, uint8_t> shft_ref_251 { id_1056 };
              Vec<1, Pointer> id_1058 {  dsum1_snd_249  };
              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_1059;
              {
                Vec<1, Pointer> p_ref_252 { id_1058 };
                bool while_flag_1060 { true };
                do {
                  uint8_t id_1061 { 0 };
                  Pointer id_1062 { p_ref_252[id_1061] };
                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_1063 { id_1062.readU8() };
                  bool let_res_1064;
                  {
                    ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_253 { id_1063 };
                    bool letpair_res_1065;
                    {
                      auto leb128_fst_254 { std::get<0>(leb128_253) };
                      auto leb128_snd_255 { std::get<1>(leb128_253) };
                      uint8_t id_1066 { 0 };
                      Void id_1067 { ((void)(p_ref_252[id_1066] = leb128_snd_255), VOID) };
                      (void)id_1067;
                      uint8_t id_1068 { 0 };
                      uint8_t id_1069 { 127 };
                      uint8_t id_1070 { uint8_t(leb128_fst_254 & id_1069) };
                      uint32_t id_1071 { uint32_t(id_1070) };
                      uint8_t id_1072 { 0 };
                      uint8_t id_1073 { shft_ref_251[id_1072] };
                      uint32_t id_1074 { uint32_t(id_1071 << id_1073) };
                      uint8_t id_1075 { 0 };
                      uint32_t id_1076 { leb_ref_250[id_1075] };
                      uint32_t id_1077 { uint32_t(id_1074 | id_1076) };
                      Void id_1078 { ((void)(leb_ref_250[id_1068] = id_1077), VOID) };
                      (void)id_1078;
                      uint8_t id_1079 { 0 };
                      uint8_t id_1080 { 0 };
                      uint8_t id_1081 { shft_ref_251[id_1080] };
                      uint8_t id_1082 { 7 };
                      uint8_t id_1083 { uint8_t(id_1081 + id_1082) };
                      Void id_1084 { ((void)(shft_ref_251[id_1079] = id_1083), VOID) };
                      (void)id_1084;
                      uint8_t id_1085 { 128 };
                      bool id_1086 { bool(leb128_fst_254 >= id_1085) };
                      letpair_res_1065 = id_1086;
                    }
                    let_res_1064 = letpair_res_1065;
                  }
                  while_flag_1060 = let_res_1064;
                  if (while_flag_1060) {
                    (void)VOID;
                  }
                } while (while_flag_1060);
                (void)VOID;
                uint8_t id_1087 { 0 };
                uint32_t id_1088 { leb_ref_250[id_1087] };
                uint8_t id_1089 { 0 };
                Pointer id_1090 { p_ref_252[id_1089] };
                ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_1091 { id_1088, id_1090 };
                let_res_1059 = id_1091;
              }
              let_res_1057 = let_res_1059;
            }
            let_res_1054 = let_res_1057;
          }
          ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e let_res_1092;
          {
            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_259 { let_res_1054 };
            ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e letpair_res_1093;
            {
              auto dlist1_fst_260 { std::get<0>(dlist1_259) };
              auto dlist1_snd_261 { std::get<1>(dlist1_259) };
              Lst<dessser::gen::field_type::t_ext> endoflist_1094;
              ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e id_1095 { endoflist_1094, dlist1_snd_261 };
              Vec<1, ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e> id_1096 {  id_1095  };
              ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e let_res_1097;
              {
                Vec<1, ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e> inits_src_ref_262 { id_1096 };
                int32_t id_1098 { 0L };
                Vec<1, int32_t> id_1099 {  id_1098  };
                {
                  Vec<1, int32_t> repeat_n_263 { id_1099 };
                  bool while_flag_1100 { true };
                  do {
                    int32_t id_1101 { int32_t(dlist1_fst_260) };
                    uint8_t id_1102 { 0 };
                    int32_t id_1103 { repeat_n_263[id_1102] };
                    bool id_1104 { bool(id_1101 > id_1103) };
                    while_flag_1100 = id_1104;
                    if (while_flag_1100) {
                      uint8_t id_1105 { 0 };
                      ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e id_1106 { inits_src_ref_262[id_1105] };
                      {
                        ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e dlist2_264 { id_1106 };
                        {
                          auto dlist2_fst_265 { std::get<0>(dlist2_264) };
                          auto dlist2_snd_266 { std::get<1>(dlist2_264) };
                          uint8_t id_1107 { 0 };
                          auto fun1108 { dessser::gen::field_type::of_row_binary };
                          ::dessser::gen::raql_operation::t2f09fa79b0bdf1902e3b53bc7e485604 id_1109 { fun1108(dlist2_snd_266) };
                          ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e letpair_res_1110;
                          {
                            auto dlist3_fst_268 { std::get<0>(id_1109) };
                            auto dlist3_snd_269 { std::get<1>(id_1109) };
                            Lst<dessser::gen::field_type::t_ext> id_1111 { dlist3_fst_268, dlist2_fst_265 };
                            ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e id_1112 { id_1111, dlist3_snd_269 };
                            letpair_res_1110 = id_1112;
                          }
                          Void id_1113 { ((void)(inits_src_ref_262[id_1107] = letpair_res_1110), VOID) };
                          (void)id_1113;
                        }
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_1114 { 0 };
                      uint8_t id_1115 { 0 };
                      int32_t id_1116 { repeat_n_263[id_1115] };
                      int32_t id_1117 { 1L };
                      int32_t id_1118 { int32_t(id_1116 + id_1117) };
                      Void id_1119 { ((void)(repeat_n_263[id_1114] = id_1118), VOID) };
                      (void)id_1119;
                      (void)id_1119;
                    }
                  } while (while_flag_1100);
                  (void)VOID;
                }
                (void)VOID;
                uint8_t id_1120 { 0 };
                ::dessser::gen::raql_operation::tfba505af7788ece275315330d94bba2e id_1121 { inits_src_ref_262[id_1120] };
                let_res_1097 = id_1121;
              }
              letpair_res_1093 = let_res_1097;
            }
            let_res_1092 = letpair_res_1093;
          }
          ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_1122;
          {
            auto dlist4_fst_271 { std::get<0>(let_res_1092) };
            auto dlist4_snd_272 { std::get<1>(let_res_1092) };
            ::dessser::gen::raql_operation::external_format* id_1123 { new ::dessser::gen::raql_operation::external_format(std::in_place_index<1>, dlist4_fst_271) };
            ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 id_1124 { id_1123, dlist4_snd_272 };
            letpair_res_1122 = id_1124;
          }
          choose_res_846 = letpair_res_1122;
        }
        letpair_res_843 = choose_res_846;
      }
      let_res_842 = letpair_res_843;
    }
    ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 letpair_res_1125;
    {
      auto make_fst_360 { std::get<0>(let_res_842) };
      auto make_snd_361 { std::get<1>(let_res_842) };
      ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 id_1126 { make_fst_360, make_snd_361 };
      letpair_res_1125 = id_1126;
    }
    return letpair_res_1125;
  }
   };
  return fun838;
}
std::function<::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6(Pointer)> external_format_of_row_binary(external_format_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_239" "make_snd_240"
        (let "dsum1_134" (let-pair "du16_fst_129" "du16_snd_130" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_129") (identifier "du16_snd_130")))
          (let-pair "dsum1_fst_135" "dsum1_snd_136" (identifier "dsum1_134")
            (if (eq (u16 0) (identifier "dsum1_fst_135"))
              (let "drec_223" (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_136"))
                (let-pair "drec_fst_224" "drec_snd_225" (identifier "drec_223")
                  (let "drec_229"
                    (if (eq (peek-u8 (identifier "drec_snd_225") (size 0)) (u8 1)) 
                      (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_225") (size 1)))
                      (let-pair "make1_1_fst_227" "make1_1_snd_228" (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_225") (size 1)))
                        (make-tup (not-null (identifier "make1_1_fst_227")) (identifier "make1_1_snd_228"))))
                    (let-pair "drec_fst_230" "drec_snd_231" (identifier "drec_229")
                      (let-pair "drec_fst_233" "drec_snd_234" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_231"))
                        (make-tup
                          (construct "[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" 0
                            (make-rec (string "unlink") (identifier "drec_fst_233") (string "preprocessor") (identifier "drec_fst_230") (string "fname") (identifier "drec_fst_224"))) 
                          (identifier "drec_snd_234")))))))
              (seq (assert (eq (identifier "dsum1_fst_135") (u16 1)))
                (let "drec_178"
                  (let-pair "dlist4_fst_176" "dlist4_snd_177"
                    (let "dlist1_146"
                      (let "leb_ref_137" (make-vec (u32 0))
                        (let "shft_ref_138" (make-vec (u8 0))
                          (let "p_ref_139" (make-vec (identifier "dsum1_snd_136"))
                            (seq
                              (while
                                (let "leb128_140" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_139")))
                                  (let-pair "leb128_fst_141" "leb128_snd_142" 
                                    (identifier "leb128_140")
                                    (seq (set-vec (u8 0) (identifier "p_ref_139") (identifier "leb128_snd_142"))
                                      (set-vec (u8 0) (identifier "leb_ref_137")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_141") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_138"))) (unsafe-nth (u8 0) (identifier "leb_ref_137"))))
                                      (set-vec (u8 0) (identifier "shft_ref_138") (add (unsafe-nth (u8 0) (identifier "shft_ref_138")) (u8 7))) 
                                      (ge (identifier "leb128_fst_141") (u8 128))))) 
                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_137")) (unsafe-nth (u8 0) (identifier "p_ref_139")))))))
                      (let-pair "dlist1_fst_147" "dlist1_snd_148" (identifier "dlist1_146")
                        (let "inits_src_ref_149" (make-vec (make-tup (end-of-list "(STRING; $raql_expr)") (identifier "dlist1_snd_148")))
                          (seq
                            (let "repeat_n_150" (make-vec (i32 0))
                              (while (gt (to-i32 (identifier "dlist1_fst_147")) (unsafe-nth (u8 0) (identifier "repeat_n_150")))
                                (seq
                                  (let "dlist2_151" (unsafe-nth (u8 0) (identifier "inits_src_ref_149"))
                                    (let-pair "dlist2_fst_152" "dlist2_snd_153" 
                                      (identifier "dlist2_151")
                                      (set-vec (u8 0) (identifier "inits_src_ref_149")
                                        (let "dtup_166"
                                          (let "dstring1_160"
                                            (let "leb_ref_154" (make-vec (u32 0))
                                              (let "shft_ref_155" (make-vec (u8 0))
                                                (let "p_ref_156" (make-vec (identifier "dlist2_snd_153"))
                                                  (seq
                                                    (while
                                                      (let "leb128_157" 
                                                        (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_156")))
                                                        (let-pair "leb128_fst_158" "leb128_snd_159" 
                                                          (identifier "leb128_157")
                                                          (seq (set-vec (u8 0) (identifier "p_ref_156") (identifier "leb128_snd_159"))
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb_ref_154")
                                                              (bit-or 
                                                                (left-shift (to-u32 (bit-and (identifier "leb128_fst_158") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_155")))
                                                                (unsafe-nth (u8 0) (identifier "leb_ref_154")))) 
                                                            (set-vec (u8 0) (identifier "shft_ref_155") (add (unsafe-nth (u8 0) (identifier "shft_ref_155")) (u8 7))) 
                                                            (ge (identifier "leb128_fst_158") (u8 128))))) 
                                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_154"))) (unsafe-nth (u8 0) (identifier "p_ref_156")))))))
                                            (let-pair "dstring1_fst_161" "dstring1_snd_162" 
                                              (identifier "dstring1_160")
                                              (let-pair "dstring2_fst_164" "dstring2_snd_165" 
                                                (read-bytes (identifier "dstring1_snd_162") (identifier "dstring1_fst_161")) 
                                                (make-tup (string-of-bytes (identifier "dstring2_fst_164")) (identifier "dstring2_snd_165")))))
                                          (let-pair "dtup_fst_167" "dtup_snd_168" 
                                            (identifier "dtup_166")
                                            (let-pair "dtup_fst_170" "dtup_snd_171" 
                                              (apply (ext-identifier raql_expr of-row-binary) (identifier "dtup_snd_168"))
                                              (make-tup (cons (make-tup (identifier "dtup_fst_167") (identifier "dtup_fst_170")) (identifier "dlist2_fst_152")) (identifier "dtup_snd_171"))))))))
                                  (set-vec (u8 0) (identifier "repeat_n_150") (add (unsafe-nth (u8 0) (identifier "repeat_n_150")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "inits_src_ref_149")))))) 
                    (make-tup (identity (identifier "dlist4_fst_176")) (identifier "dlist4_snd_177")))
                  (let-pair "drec_fst_179" "drec_snd_180" (identifier "drec_178")
                    (let "drec_181" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_180"))
                      (let-pair "drec_fst_182" "drec_snd_183" (identifier "drec_181")
                        (let "drec_187"
                          (if (eq (peek-u8 (identifier "drec_snd_183") (size 0)) (u8 1)) 
                            (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_183") (size 1)))
                            (let-pair "make1_1_fst_185" "make1_1_snd_186" 
                              (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_183") (size 1))) 
                              (make-tup (not-null (identifier "make1_1_fst_185")) (identifier "make1_1_snd_186"))))
                          (let-pair "drec_fst_188" "drec_snd_189" (identifier "drec_187")
                            (let-pair "drec_fst_218" "drec_snd_219"
                              (let "dsum1_196" (let-pair "du16_fst_191" "du16_snd_192" (read-u16 little-endian (identifier "drec_snd_189")) (make-tup (identifier "du16_fst_191") (identifier "du16_snd_192")))
                                (let-pair "dsum1_fst_197" "dsum1_snd_198" 
                                  (identifier "dsum1_196")
                                  (if (eq (u16 0) (identifier "dsum1_fst_197"))
                                    (make-tup (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 0 (nop))
                                      (identifier "dsum1_snd_198"))
                                    (if (eq (u16 1) (identifier "dsum1_fst_197"))
                                      (let-pair "dsum2_fst_212" "dsum2_snd_213" 
                                        (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_198"))
                                        (make-tup
                                          (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 1
                                            (identifier "dsum2_fst_212")) 
                                          (identifier "dsum2_snd_213")))
                                      (if (eq (u16 2) (identifier "dsum1_fst_197"))
                                        (make-tup (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 2 (nop))
                                          (identifier "dsum1_snd_198"))
                                        (seq (assert (eq (identifier "dsum1_fst_197") (u16 3)))
                                          (let "drec_199" (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_198"))
                                            (let-pair "drec_fst_200" "drec_snd_201" 
                                              (identifier "drec_199")
                                              (let-pair "drec_fst_203" "drec_snd_204" 
                                                (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_201"))
                                                (make-tup
                                                  (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 3
                                                    (make-rec (string "after_max_events") (identifier "drec_fst_203") (string "after_max_secs") (identifier "drec_fst_200"))) 
                                                  (identifier "drec_snd_204")))))))))))
                              (make-tup
                                (construct "[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" 1
                                  (make-rec (string "restart_from") (identifier "drec_fst_218") 
                                    (string "partitions") (identifier "drec_fst_188") 
                                    (string "topic") (identifier "drec_fst_182") 
                                    (string "options") (identifier "drec_fst_179"))) 
                                (identifier "drec_snd_219"))))))))))))) 
        (make-tup (identifier "make_fst_239") (identifier "make_snd_240"))))
 */
static std::function<::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794(Pointer)> external_source_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794(Pointer)> fun1127 { [&fun1127](Pointer p_0) {
    ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_1128 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1129;
    {
      auto du16_fst_129 { std::get<0>(id_1128) };
      auto du16_snd_130 { std::get<1>(id_1128) };
      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_1130 { du16_fst_129, du16_snd_130 };
      letpair_res_1129 = id_1130;
    }
    ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 let_res_1131;
    {
      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 dsum1_134 { letpair_res_1129 };
      ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 letpair_res_1132;
      {
        auto dsum1_fst_135 { std::get<0>(dsum1_134) };
        auto dsum1_snd_136 { std::get<1>(dsum1_134) };
        uint16_t id_1133 { 0 };
        bool id_1134 { bool(id_1133 == dsum1_fst_135) };
        ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 choose_res_1135;
        if (id_1134) {
          auto fun1136 { dessser::gen::raql_expr::of_row_binary };
          ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_1137 { fun1136(dsum1_snd_136) };
          ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 let_res_1138;
          {
            ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac drec_223 { id_1137 };
            ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 letpair_res_1139;
            {
              auto drec_fst_224 { std::get<0>(drec_223) };
              auto drec_snd_225 { std::get<1>(drec_223) };
              Size id_1140 { 0UL };
              uint8_t id_1141 { drec_snd_225.peekU8(id_1140) };
              uint8_t id_1142 { 1 };
              bool id_1143 { bool(id_1141 == id_1142) };
              ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 choose_res_1144;
              if (id_1143) {
                std::optional<dessser::gen::raql_expr::t_ext> id_1145 { std::nullopt };
                Size id_1146 { 1UL };
                Pointer id_1147 { drec_snd_225.skip(id_1146) };
                ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 id_1148 { id_1145, id_1147 };
                choose_res_1144 = id_1148;
              } else {
                auto fun1149 { dessser::gen::raql_expr::of_row_binary };
                Size id_1150 { 1UL };
                Pointer id_1151 { drec_snd_225.skip(id_1150) };
                ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_1152 { fun1149(id_1151) };
                ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 letpair_res_1153;
                {
                  auto make1_1_fst_227 { std::get<0>(id_1152) };
                  auto make1_1_snd_228 { std::get<1>(id_1152) };
                  std::optional<dessser::gen::raql_expr::t_ext> id_1154 { make1_1_fst_227 };
                  ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 id_1155 { id_1154, make1_1_snd_228 };
                  letpair_res_1153 = id_1155;
                }
                choose_res_1144 = letpair_res_1153;
              }
              ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 let_res_1156;
              {
                ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 drec_229 { choose_res_1144 };
                ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 letpair_res_1157;
                {
                  auto drec_fst_230 { std::get<0>(drec_229) };
                  auto drec_snd_231 { std::get<1>(drec_229) };
                  auto fun1158 { dessser::gen::raql_expr::of_row_binary };
                  ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_1159 { fun1158(drec_snd_231) };
                  ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 letpair_res_1160;
                  {
                    auto drec_fst_233 { std::get<0>(id_1159) };
                    auto drec_snd_234 { std::get<1>(id_1159) };
                    ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8 id_1161 { .fname = drec_fst_224, .preprocessor = drec_fst_230, .unlink = drec_fst_233 };
                    ::dessser::gen::raql_operation::external_source* id_1162 { new ::dessser::gen::raql_operation::external_source(std::in_place_index<0>, id_1161) };
                    ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 id_1163 { id_1162, drec_snd_234 };
                    letpair_res_1160 = id_1163;
                  }
                  letpair_res_1157 = letpair_res_1160;
                }
                let_res_1156 = letpair_res_1157;
              }
              letpair_res_1139 = let_res_1156;
            }
            let_res_1138 = letpair_res_1139;
          }
          choose_res_1135 = let_res_1138;
        } else {
          uint16_t id_1164 { 1 };
          bool id_1165 { bool(dsum1_fst_135 == id_1164) };
          Void id_1166 { ((void)(assert(id_1165)), VOID) };
          (void)id_1166;
          uint32_t id_1167 { 0U };
          Vec<1, uint32_t> id_1168 {  id_1167  };
          ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_1169;
          {
            Vec<1, uint32_t> leb_ref_137 { id_1168 };
            uint8_t id_1170 { 0 };
            Vec<1, uint8_t> id_1171 {  id_1170  };
            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_1172;
            {
              Vec<1, uint8_t> shft_ref_138 { id_1171 };
              Vec<1, Pointer> id_1173 {  dsum1_snd_136  };
              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_1174;
              {
                Vec<1, Pointer> p_ref_139 { id_1173 };
                bool while_flag_1175 { true };
                do {
                  uint8_t id_1176 { 0 };
                  Pointer id_1177 { p_ref_139[id_1176] };
                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_1178 { id_1177.readU8() };
                  bool let_res_1179;
                  {
                    ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_140 { id_1178 };
                    bool letpair_res_1180;
                    {
                      auto leb128_fst_141 { std::get<0>(leb128_140) };
                      auto leb128_snd_142 { std::get<1>(leb128_140) };
                      uint8_t id_1181 { 0 };
                      Void id_1182 { ((void)(p_ref_139[id_1181] = leb128_snd_142), VOID) };
                      (void)id_1182;
                      uint8_t id_1183 { 0 };
                      uint8_t id_1184 { 127 };
                      uint8_t id_1185 { uint8_t(leb128_fst_141 & id_1184) };
                      uint32_t id_1186 { uint32_t(id_1185) };
                      uint8_t id_1187 { 0 };
                      uint8_t id_1188 { shft_ref_138[id_1187] };
                      uint32_t id_1189 { uint32_t(id_1186 << id_1188) };
                      uint8_t id_1190 { 0 };
                      uint32_t id_1191 { leb_ref_137[id_1190] };
                      uint32_t id_1192 { uint32_t(id_1189 | id_1191) };
                      Void id_1193 { ((void)(leb_ref_137[id_1183] = id_1192), VOID) };
                      (void)id_1193;
                      uint8_t id_1194 { 0 };
                      uint8_t id_1195 { 0 };
                      uint8_t id_1196 { shft_ref_138[id_1195] };
                      uint8_t id_1197 { 7 };
                      uint8_t id_1198 { uint8_t(id_1196 + id_1197) };
                      Void id_1199 { ((void)(shft_ref_138[id_1194] = id_1198), VOID) };
                      (void)id_1199;
                      uint8_t id_1200 { 128 };
                      bool id_1201 { bool(leb128_fst_141 >= id_1200) };
                      letpair_res_1180 = id_1201;
                    }
                    let_res_1179 = letpair_res_1180;
                  }
                  while_flag_1175 = let_res_1179;
                  if (while_flag_1175) {
                    (void)VOID;
                  }
                } while (while_flag_1175);
                (void)VOID;
                uint8_t id_1202 { 0 };
                uint32_t id_1203 { leb_ref_137[id_1202] };
                uint8_t id_1204 { 0 };
                Pointer id_1205 { p_ref_139[id_1204] };
                ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_1206 { id_1203, id_1205 };
                let_res_1174 = id_1206;
              }
              let_res_1172 = let_res_1174;
            }
            let_res_1169 = let_res_1172;
          }
          ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 let_res_1207;
          {
            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_146 { let_res_1169 };
            ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 letpair_res_1208;
            {
              auto dlist1_fst_147 { std::get<0>(dlist1_146) };
              auto dlist1_snd_148 { std::get<1>(dlist1_146) };
              Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> endoflist_1209;
              ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 id_1210 { endoflist_1209, dlist1_snd_148 };
              Vec<1, ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180> id_1211 {  id_1210  };
              ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 let_res_1212;
              {
                Vec<1, ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180> inits_src_ref_149 { id_1211 };
                int32_t id_1213 { 0L };
                Vec<1, int32_t> id_1214 {  id_1213  };
                {
                  Vec<1, int32_t> repeat_n_150 { id_1214 };
                  bool while_flag_1215 { true };
                  do {
                    int32_t id_1216 { int32_t(dlist1_fst_147) };
                    uint8_t id_1217 { 0 };
                    int32_t id_1218 { repeat_n_150[id_1217] };
                    bool id_1219 { bool(id_1216 > id_1218) };
                    while_flag_1215 = id_1219;
                    if (while_flag_1215) {
                      uint8_t id_1220 { 0 };
                      ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 id_1221 { inits_src_ref_149[id_1220] };
                      {
                        ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 dlist2_151 { id_1221 };
                        {
                          auto dlist2_fst_152 { std::get<0>(dlist2_151) };
                          auto dlist2_snd_153 { std::get<1>(dlist2_151) };
                          uint8_t id_1222 { 0 };
                          uint32_t id_1223 { 0U };
                          Vec<1, uint32_t> id_1224 {  id_1223  };
                          ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_1225;
                          {
                            Vec<1, uint32_t> leb_ref_154 { id_1224 };
                            uint8_t id_1226 { 0 };
                            Vec<1, uint8_t> id_1227 {  id_1226  };
                            ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_1228;
                            {
                              Vec<1, uint8_t> shft_ref_155 { id_1227 };
                              Vec<1, Pointer> id_1229 {  dlist2_snd_153  };
                              ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_1230;
                              {
                                Vec<1, Pointer> p_ref_156 { id_1229 };
                                bool while_flag_1231 { true };
                                do {
                                  uint8_t id_1232 { 0 };
                                  Pointer id_1233 { p_ref_156[id_1232] };
                                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_1234 { id_1233.readU8() };
                                  bool let_res_1235;
                                  {
                                    ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_157 { id_1234 };
                                    bool letpair_res_1236;
                                    {
                                      auto leb128_fst_158 { std::get<0>(leb128_157) };
                                      auto leb128_snd_159 { std::get<1>(leb128_157) };
                                      uint8_t id_1237 { 0 };
                                      Void id_1238 { ((void)(p_ref_156[id_1237] = leb128_snd_159), VOID) };
                                      (void)id_1238;
                                      uint8_t id_1239 { 0 };
                                      uint8_t id_1240 { 127 };
                                      uint8_t id_1241 { uint8_t(leb128_fst_158 & id_1240) };
                                      uint32_t id_1242 { uint32_t(id_1241) };
                                      uint8_t id_1243 { 0 };
                                      uint8_t id_1244 { shft_ref_155[id_1243] };
                                      uint32_t id_1245 { uint32_t(id_1242 << id_1244) };
                                      uint8_t id_1246 { 0 };
                                      uint32_t id_1247 { leb_ref_154[id_1246] };
                                      uint32_t id_1248 { uint32_t(id_1245 | id_1247) };
                                      Void id_1249 { ((void)(leb_ref_154[id_1239] = id_1248), VOID) };
                                      (void)id_1249;
                                      uint8_t id_1250 { 0 };
                                      uint8_t id_1251 { 0 };
                                      uint8_t id_1252 { shft_ref_155[id_1251] };
                                      uint8_t id_1253 { 7 };
                                      uint8_t id_1254 { uint8_t(id_1252 + id_1253) };
                                      Void id_1255 { ((void)(shft_ref_155[id_1250] = id_1254), VOID) };
                                      (void)id_1255;
                                      uint8_t id_1256 { 128 };
                                      bool id_1257 { bool(leb128_fst_158 >= id_1256) };
                                      letpair_res_1236 = id_1257;
                                    }
                                    let_res_1235 = letpair_res_1236;
                                  }
                                  while_flag_1231 = let_res_1235;
                                  if (while_flag_1231) {
                                    (void)VOID;
                                  }
                                } while (while_flag_1231);
                                (void)VOID;
                                uint8_t id_1258 { 0 };
                                uint32_t id_1259 { leb_ref_154[id_1258] };
                                Size id_1260 { Size(id_1259) };
                                uint8_t id_1261 { 0 };
                                Pointer id_1262 { p_ref_156[id_1261] };
                                ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c id_1263 { id_1260, id_1262 };
                                let_res_1230 = id_1263;
                              }
                              let_res_1228 = let_res_1230;
                            }
                            let_res_1225 = let_res_1228;
                          }
                          ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e let_res_1264;
                          {
                            ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c dstring1_160 { let_res_1225 };
                            ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1265;
                            {
                              auto dstring1_fst_161 { std::get<0>(dstring1_160) };
                              auto dstring1_snd_162 { std::get<1>(dstring1_160) };
                              ::dessser::gen::raql_operation::t188345aa49abd0cb47ff73fedc219f08 id_1266 { dstring1_snd_162.readBytes(dstring1_fst_161) };
                              ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1267;
                              {
                                auto dstring2_fst_164 { std::get<0>(id_1266) };
                                auto dstring2_snd_165 { std::get<1>(id_1266) };
                                std::string id_1268 { dstring2_fst_164.toString() };
                                ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e id_1269 { id_1268, dstring2_snd_165 };
                                letpair_res_1267 = id_1269;
                              }
                              letpair_res_1265 = letpair_res_1267;
                            }
                            let_res_1264 = letpair_res_1265;
                          }
                          ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 let_res_1270;
                          {
                            ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e dtup_166 { let_res_1264 };
                            ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 letpair_res_1271;
                            {
                              auto dtup_fst_167 { std::get<0>(dtup_166) };
                              auto dtup_snd_168 { std::get<1>(dtup_166) };
                              auto fun1272 { dessser::gen::raql_expr::of_row_binary };
                              ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_1273 { fun1272(dtup_snd_168) };
                              ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 letpair_res_1274;
                              {
                                auto dtup_fst_170 { std::get<0>(id_1273) };
                                auto dtup_snd_171 { std::get<1>(id_1273) };
                                ::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed id_1275 { dtup_fst_167, dtup_fst_170 };
                                Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> id_1276 { id_1275, dlist2_fst_152 };
                                ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 id_1277 { id_1276, dtup_snd_171 };
                                letpair_res_1274 = id_1277;
                              }
                              letpair_res_1271 = letpair_res_1274;
                            }
                            let_res_1270 = letpair_res_1271;
                          }
                          Void id_1278 { ((void)(inits_src_ref_149[id_1222] = let_res_1270), VOID) };
                          (void)id_1278;
                        }
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_1279 { 0 };
                      uint8_t id_1280 { 0 };
                      int32_t id_1281 { repeat_n_150[id_1280] };
                      int32_t id_1282 { 1L };
                      int32_t id_1283 { int32_t(id_1281 + id_1282) };
                      Void id_1284 { ((void)(repeat_n_150[id_1279] = id_1283), VOID) };
                      (void)id_1284;
                      (void)id_1284;
                    }
                  } while (while_flag_1215);
                  (void)VOID;
                }
                (void)VOID;
                uint8_t id_1285 { 0 };
                ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 id_1286 { inits_src_ref_149[id_1285] };
                let_res_1212 = id_1286;
              }
              letpair_res_1208 = let_res_1212;
            }
            let_res_1207 = letpair_res_1208;
          }
          ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 letpair_res_1287;
          {
            auto dlist4_fst_176 { std::get<0>(let_res_1207) };
            auto dlist4_snd_177 { std::get<1>(let_res_1207) };
            ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 id_1288 { dlist4_fst_176, dlist4_snd_177 };
            letpair_res_1287 = id_1288;
          }
          ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 let_res_1289;
          {
            ::dessser::gen::raql_operation::tc9c5fe4e3c65effcf5ec497fd0133180 drec_178 { letpair_res_1287 };
            ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 letpair_res_1290;
            {
              auto drec_fst_179 { std::get<0>(drec_178) };
              auto drec_snd_180 { std::get<1>(drec_178) };
              auto fun1291 { dessser::gen::raql_expr::of_row_binary };
              ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_1292 { fun1291(drec_snd_180) };
              ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 let_res_1293;
              {
                ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac drec_181 { id_1292 };
                ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 letpair_res_1294;
                {
                  auto drec_fst_182 { std::get<0>(drec_181) };
                  auto drec_snd_183 { std::get<1>(drec_181) };
                  Size id_1295 { 0UL };
                  uint8_t id_1296 { drec_snd_183.peekU8(id_1295) };
                  uint8_t id_1297 { 1 };
                  bool id_1298 { bool(id_1296 == id_1297) };
                  ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 choose_res_1299;
                  if (id_1298) {
                    std::optional<dessser::gen::raql_expr::t_ext> id_1300 { std::nullopt };
                    Size id_1301 { 1UL };
                    Pointer id_1302 { drec_snd_183.skip(id_1301) };
                    ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 id_1303 { id_1300, id_1302 };
                    choose_res_1299 = id_1303;
                  } else {
                    auto fun1304 { dessser::gen::raql_expr::of_row_binary };
                    Size id_1305 { 1UL };
                    Pointer id_1306 { drec_snd_183.skip(id_1305) };
                    ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_1307 { fun1304(id_1306) };
                    ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 letpair_res_1308;
                    {
                      auto make1_1_fst_185 { std::get<0>(id_1307) };
                      auto make1_1_snd_186 { std::get<1>(id_1307) };
                      std::optional<dessser::gen::raql_expr::t_ext> id_1309 { make1_1_fst_185 };
                      ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 id_1310 { id_1309, make1_1_snd_186 };
                      letpair_res_1308 = id_1310;
                    }
                    choose_res_1299 = letpair_res_1308;
                  }
                  ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 let_res_1311;
                  {
                    ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 drec_187 { choose_res_1299 };
                    ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 letpair_res_1312;
                    {
                      auto drec_fst_188 { std::get<0>(drec_187) };
                      auto drec_snd_189 { std::get<1>(drec_187) };
                      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_1313 { drec_snd_189.readU16Le() };
                      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1314;
                      {
                        auto du16_fst_191 { std::get<0>(id_1313) };
                        auto du16_snd_192 { std::get<1>(id_1313) };
                        ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_1315 { du16_fst_191, du16_snd_192 };
                        letpair_res_1314 = id_1315;
                      }
                      ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 let_res_1316;
                      {
                        ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 dsum1_196 { letpair_res_1314 };
                        ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 letpair_res_1317;
                        {
                          auto dsum1_fst_197 { std::get<0>(dsum1_196) };
                          auto dsum1_snd_198 { std::get<1>(dsum1_196) };
                          uint16_t id_1318 { 0 };
                          bool id_1319 { bool(id_1318 == dsum1_fst_197) };
                          ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 choose_res_1320;
                          if (id_1319) {
                            (void)VOID;
                            ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_1321 { std::in_place_index<0>, VOID };
                            ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 id_1322 { id_1321, dsum1_snd_198 };
                            choose_res_1320 = id_1322;
                          } else {
                            uint16_t id_1323 { 1 };
                            bool id_1324 { bool(id_1323 == dsum1_fst_197) };
                            ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 choose_res_1325;
                            if (id_1324) {
                              auto fun1326 { dessser::gen::raql_expr::of_row_binary };
                              ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_1327 { fun1326(dsum1_snd_198) };
                              ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 letpair_res_1328;
                              {
                                auto dsum2_fst_212 { std::get<0>(id_1327) };
                                auto dsum2_snd_213 { std::get<1>(id_1327) };
                                ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_1329 { std::in_place_index<1>, dsum2_fst_212 };
                                ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 id_1330 { id_1329, dsum2_snd_213 };
                                letpair_res_1328 = id_1330;
                              }
                              choose_res_1325 = letpair_res_1328;
                            } else {
                              uint16_t id_1331 { 2 };
                              bool id_1332 { bool(id_1331 == dsum1_fst_197) };
                              ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 choose_res_1333;
                              if (id_1332) {
                                (void)VOID;
                                ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_1334 { std::in_place_index<2>, VOID };
                                ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 id_1335 { id_1334, dsum1_snd_198 };
                                choose_res_1333 = id_1335;
                              } else {
                                uint16_t id_1336 { 3 };
                                bool id_1337 { bool(dsum1_fst_197 == id_1336) };
                                Void id_1338 { ((void)(assert(id_1337)), VOID) };
                                (void)id_1338;
                                auto fun1339 { dessser::gen::raql_expr::of_row_binary };
                                ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_1340 { fun1339(dsum1_snd_198) };
                                ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 let_res_1341;
                                {
                                  ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac drec_199 { id_1340 };
                                  ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 letpair_res_1342;
                                  {
                                    auto drec_fst_200 { std::get<0>(drec_199) };
                                    auto drec_snd_201 { std::get<1>(drec_199) };
                                    auto fun1343 { dessser::gen::raql_expr::of_row_binary };
                                    ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_1344 { fun1343(drec_snd_201) };
                                    ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 letpair_res_1345;
                                    {
                                      auto drec_fst_203 { std::get<0>(id_1344) };
                                      auto drec_snd_204 { std::get<1>(id_1344) };
                                      ::dessser::gen::raql_operation::tb07656d6bb51183c62956887bcdc8cf2 id_1346 { .after_max_events = drec_fst_203, .after_max_secs = drec_fst_200 };
                                      ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 id_1347 { std::in_place_index<3>, id_1346 };
                                      ::dessser::gen::raql_operation::t5a237d86cabc7ad13430dbcf6495ec54 id_1348 { id_1347, drec_snd_204 };
                                      letpair_res_1345 = id_1348;
                                    }
                                    letpair_res_1342 = letpair_res_1345;
                                  }
                                  let_res_1341 = letpair_res_1342;
                                }
                                choose_res_1333 = let_res_1341;
                              }
                              choose_res_1325 = choose_res_1333;
                            }
                            choose_res_1320 = choose_res_1325;
                          }
                          letpair_res_1317 = choose_res_1320;
                        }
                        let_res_1316 = letpair_res_1317;
                      }
                      ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 letpair_res_1349;
                      {
                        auto drec_fst_218 { std::get<0>(let_res_1316) };
                        auto drec_snd_219 { std::get<1>(let_res_1316) };
                        ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 id_1350 { .options = drec_fst_179, .partitions = drec_fst_188, .restart_from = drec_fst_218, .topic = drec_fst_182 };
                        ::dessser::gen::raql_operation::external_source* id_1351 { new ::dessser::gen::raql_operation::external_source(std::in_place_index<1>, id_1350) };
                        ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 id_1352 { id_1351, drec_snd_219 };
                        letpair_res_1349 = id_1352;
                      }
                      letpair_res_1312 = letpair_res_1349;
                    }
                    let_res_1311 = letpair_res_1312;
                  }
                  letpair_res_1294 = let_res_1311;
                }
                let_res_1293 = letpair_res_1294;
              }
              letpair_res_1290 = let_res_1293;
            }
            let_res_1289 = letpair_res_1290;
          }
          choose_res_1135 = let_res_1289;
        }
        letpair_res_1132 = choose_res_1135;
      }
      let_res_1131 = letpair_res_1132;
    }
    ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 letpair_res_1353;
    {
      auto make_fst_239 { std::get<0>(let_res_1131) };
      auto make_snd_240 { std::get<1>(let_res_1131) };
      ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 id_1354 { make_fst_239, make_snd_240 };
      letpair_res_1353 = id_1354;
    }
    return letpair_res_1353;
  }
   };
  return fun1127;
}
std::function<::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794(Pointer)> external_source_of_row_binary(external_source_of_row_binary_init());

/* 
    (fun ("[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" "Ptr")
      (let "ssum_dst_819" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "stup_dst_827"
            (let "stup_dst_824"
              (let "ssum_dst_821" (write-u16 little-endian (identifier "ssum_dst_819") (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))))
                (if (eq (u16 0) (label-of (get-item 0 (get-alt "NamedOperation" (param 0))))) 
                  (identifier "ssum_dst_821")
                  (if (eq (u16 1) (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))))
                    (write-bytes
                      (let "leb128_sz_822" (make-vec (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0))))))
                        (let "leb128_ptr_823" (make-vec (identifier "ssum_dst_821"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_823")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_823"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_822"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_822"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_822"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_822") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_822")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_822")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_823"))))) 
                      (bytes-of-string (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0))))))
                    (seq (assert (eq (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))) (u16 2))) (identifier "ssum_dst_821")))))
              (if (is-null (get-item 1 (get-alt "NamedOperation" (param 0)))) 
                (write-u8 (identifier "stup_dst_824") (u8 1))
                (write-bytes
                  (let "leb128_sz_825" (make-vec (string-length (force (get-item 1 (get-alt "NamedOperation" (param 0))))))
                    (let "leb128_ptr_826" (make-vec (write-u8 (identifier "stup_dst_824") (u8 0)))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_826")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_826"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_825"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_825"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_825"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_825") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_825")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_825")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_826"))))) 
                  (bytes-of-string (force (get-item 1 (get-alt "NamedOperation" (param 0)))))))) 
            (apply (ext-identifier function_name to-row-binary) (get-item 2 (get-alt "NamedOperation" (param 0))) (identifier "stup_dst_827")))
          (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "to-row-binary") (get-alt "SubQuery" (param 0)) (identifier "ssum_dst_819"))))))
 */
static std::function<Pointer(::dessser::gen::raql_operation::data_source*,Pointer)> data_source_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_operation::data_source*,Pointer)> fun1355 { [&fun1355](::dessser::gen::raql_operation::data_source* p_0, Pointer p_1) {
    uint16_t id_1356 { uint16_t((*p_0).index()) };
    Pointer id_1357 { p_1.writeU16Le(id_1356) };
    Pointer let_res_1358;
    {
      Pointer ssum_dst_819 { id_1357 };
      uint16_t id_1359 { 0 };
      uint16_t id_1360 { uint16_t((*p_0).index()) };
      bool id_1361 { bool(id_1359 == id_1360) };
      Pointer choose_res_1362;
      if (id_1361) {
        ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1363 { std::get<0 /* NamedOperation */>((*p_0)) };
        ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_1364 { std::get<0>(id_1363) };
        uint16_t id_1365 { uint16_t(id_1364.index()) };
        Pointer id_1366 { ssum_dst_819.writeU16Le(id_1365) };
        Pointer let_res_1367;
        {
          Pointer ssum_dst_821 { id_1366 };
          uint16_t id_1368 { 0 };
          ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1369 { std::get<0 /* NamedOperation */>((*p_0)) };
          ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_1370 { std::get<0>(id_1369) };
          uint16_t id_1371 { uint16_t(id_1370.index()) };
          bool id_1372 { bool(id_1368 == id_1371) };
          Pointer choose_res_1373;
          if (id_1372) {
            choose_res_1373 = ssum_dst_821;
          } else {
            uint16_t id_1374 { 1 };
            ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1375 { std::get<0 /* NamedOperation */>((*p_0)) };
            ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_1376 { std::get<0>(id_1375) };
            uint16_t id_1377 { uint16_t(id_1376.index()) };
            bool id_1378 { bool(id_1374 == id_1377) };
            Pointer choose_res_1379;
            if (id_1378) {
              ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1380 { std::get<0 /* NamedOperation */>((*p_0)) };
              ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_1381 { std::get<0>(id_1380) };
              std::string id_1382 { std::get<1 /* TheseSites */>(id_1381) };
              uint32_t id_1383 { (uint32_t)id_1382.size() };
              Vec<1, uint32_t> id_1384 {  id_1383  };
              Pointer let_res_1385;
              {
                Vec<1, uint32_t> leb128_sz_822 { id_1384 };
                Vec<1, Pointer> id_1386 {  ssum_dst_821  };
                Pointer let_res_1387;
                {
                  Vec<1, Pointer> leb128_ptr_823 { id_1386 };
                  bool while_flag_1388 { true };
                  do {
                    uint8_t id_1389 { 0 };
                    uint8_t id_1390 { 0 };
                    Pointer id_1391 { leb128_ptr_823[id_1390] };
                    uint32_t id_1392 { 128U };
                    uint8_t id_1393 { 0 };
                    uint32_t id_1394 { leb128_sz_822[id_1393] };
                    bool id_1395 { bool(id_1392 > id_1394) };
                    uint8_t choose_res_1396;
                    if (id_1395) {
                      uint8_t id_1397 { 0 };
                      uint32_t id_1398 { leb128_sz_822[id_1397] };
                      uint8_t id_1399 { uint8_t(id_1398) };
                      choose_res_1396 = id_1399;
                    } else {
                      uint8_t id_1400 { 0 };
                      uint32_t id_1401 { leb128_sz_822[id_1400] };
                      uint8_t id_1402 { uint8_t(id_1401) };
                      uint8_t id_1403 { 128 };
                      uint8_t id_1404 { uint8_t(id_1402 | id_1403) };
                      choose_res_1396 = id_1404;
                    }
                    Pointer id_1405 { id_1391.writeU8(choose_res_1396) };
                    Void id_1406 { ((void)(leb128_ptr_823[id_1389] = id_1405), VOID) };
                    (void)id_1406;
                    uint8_t id_1407 { 0 };
                    uint8_t id_1408 { 0 };
                    uint32_t id_1409 { leb128_sz_822[id_1408] };
                    uint8_t id_1410 { 7 };
                    uint32_t id_1411 { uint32_t(id_1409 >> id_1410) };
                    Void id_1412 { ((void)(leb128_sz_822[id_1407] = id_1411), VOID) };
                    (void)id_1412;
                    uint8_t id_1413 { 0 };
                    uint32_t id_1414 { leb128_sz_822[id_1413] };
                    uint32_t id_1415 { 0U };
                    bool id_1416 { bool(id_1414 > id_1415) };
                    while_flag_1388 = id_1416;
                    if (while_flag_1388) {
                      (void)VOID;
                    }
                  } while (while_flag_1388);
                  (void)VOID;
                  uint8_t id_1417 { 0 };
                  Pointer id_1418 { leb128_ptr_823[id_1417] };
                  let_res_1387 = id_1418;
                }
                let_res_1385 = let_res_1387;
              }
              ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1419 { std::get<0 /* NamedOperation */>((*p_0)) };
              ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_1420 { std::get<0>(id_1419) };
              std::string id_1421 { std::get<1 /* TheseSites */>(id_1420) };
              Bytes id_1422 { id_1421 };
              Pointer id_1423 { let_res_1385.writeBytes(id_1422) };
              choose_res_1379 = id_1423;
            } else {
              ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1424 { std::get<0 /* NamedOperation */>((*p_0)) };
              ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_1425 { std::get<0>(id_1424) };
              uint16_t id_1426 { uint16_t(id_1425.index()) };
              uint16_t id_1427 { 2 };
              bool id_1428 { bool(id_1426 == id_1427) };
              Void id_1429 { ((void)(assert(id_1428)), VOID) };
              (void)id_1429;
              choose_res_1379 = ssum_dst_821;
            }
            choose_res_1373 = choose_res_1379;
          }
          let_res_1367 = choose_res_1373;
        }
        Pointer let_res_1430;
        {
          Pointer stup_dst_824 { let_res_1367 };
          ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1431 { std::get<0 /* NamedOperation */>((*p_0)) };
          std::optional<std::string> id_1432 { std::get<1>(id_1431) };
          bool id_1433 { !(id_1432.has_value ()) };
          Pointer choose_res_1434;
          if (id_1433) {
            uint8_t id_1435 { 1 };
            Pointer id_1436 { stup_dst_824.writeU8(id_1435) };
            choose_res_1434 = id_1436;
          } else {
            ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1437 { std::get<0 /* NamedOperation */>((*p_0)) };
            std::optional<std::string> id_1438 { std::get<1>(id_1437) };
            std::string id_1439 { id_1438.value() };
            uint32_t id_1440 { (uint32_t)id_1439.size() };
            Vec<1, uint32_t> id_1441 {  id_1440  };
            Pointer let_res_1442;
            {
              Vec<1, uint32_t> leb128_sz_825 { id_1441 };
              uint8_t id_1443 { 0 };
              Pointer id_1444 { stup_dst_824.writeU8(id_1443) };
              Vec<1, Pointer> id_1445 {  id_1444  };
              Pointer let_res_1446;
              {
                Vec<1, Pointer> leb128_ptr_826 { id_1445 };
                bool while_flag_1447 { true };
                do {
                  uint8_t id_1448 { 0 };
                  uint8_t id_1449 { 0 };
                  Pointer id_1450 { leb128_ptr_826[id_1449] };
                  uint32_t id_1451 { 128U };
                  uint8_t id_1452 { 0 };
                  uint32_t id_1453 { leb128_sz_825[id_1452] };
                  bool id_1454 { bool(id_1451 > id_1453) };
                  uint8_t choose_res_1455;
                  if (id_1454) {
                    uint8_t id_1456 { 0 };
                    uint32_t id_1457 { leb128_sz_825[id_1456] };
                    uint8_t id_1458 { uint8_t(id_1457) };
                    choose_res_1455 = id_1458;
                  } else {
                    uint8_t id_1459 { 0 };
                    uint32_t id_1460 { leb128_sz_825[id_1459] };
                    uint8_t id_1461 { uint8_t(id_1460) };
                    uint8_t id_1462 { 128 };
                    uint8_t id_1463 { uint8_t(id_1461 | id_1462) };
                    choose_res_1455 = id_1463;
                  }
                  Pointer id_1464 { id_1450.writeU8(choose_res_1455) };
                  Void id_1465 { ((void)(leb128_ptr_826[id_1448] = id_1464), VOID) };
                  (void)id_1465;
                  uint8_t id_1466 { 0 };
                  uint8_t id_1467 { 0 };
                  uint32_t id_1468 { leb128_sz_825[id_1467] };
                  uint8_t id_1469 { 7 };
                  uint32_t id_1470 { uint32_t(id_1468 >> id_1469) };
                  Void id_1471 { ((void)(leb128_sz_825[id_1466] = id_1470), VOID) };
                  (void)id_1471;
                  uint8_t id_1472 { 0 };
                  uint32_t id_1473 { leb128_sz_825[id_1472] };
                  uint32_t id_1474 { 0U };
                  bool id_1475 { bool(id_1473 > id_1474) };
                  while_flag_1447 = id_1475;
                  if (while_flag_1447) {
                    (void)VOID;
                  }
                } while (while_flag_1447);
                (void)VOID;
                uint8_t id_1476 { 0 };
                Pointer id_1477 { leb128_ptr_826[id_1476] };
                let_res_1446 = id_1477;
              }
              let_res_1442 = let_res_1446;
            }
            ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1478 { std::get<0 /* NamedOperation */>((*p_0)) };
            std::optional<std::string> id_1479 { std::get<1>(id_1478) };
            std::string id_1480 { id_1479.value() };
            Bytes id_1481 { id_1480 };
            Pointer id_1482 { let_res_1442.writeBytes(id_1481) };
            choose_res_1434 = id_1482;
          }
          let_res_1430 = choose_res_1434;
        }
        Pointer let_res_1483;
        {
          Pointer stup_dst_827 { let_res_1430 };
          auto fun1484 { dessser::gen::function_name::to_row_binary };
          ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_1485 { std::get<0 /* NamedOperation */>((*p_0)) };
          dessser::gen::function_name::t_ext id_1486 { std::get<2>(id_1485) };
          Pointer id_1487 { fun1484(id_1486, stup_dst_827) };
          let_res_1483 = id_1487;
        }
        choose_res_1362 = let_res_1483;
      } else {
        uint16_t id_1488 { uint16_t((*p_0).index()) };
        uint16_t id_1489 { 1 };
        bool id_1490 { bool(id_1488 == id_1489) };
        Void id_1491 { ((void)(assert(id_1490)), VOID) };
        (void)id_1491;
        t* id_1492 { std::get<1 /* SubQuery */>((*p_0)) };
        Pointer id_1493 { to_row_binary(id_1492, ssum_dst_819) };
        choose_res_1362 = id_1493;
      }
      let_res_1358 = choose_res_1362;
    }
    return let_res_1358;
  }
   };
  return fun1355;
}
std::function<Pointer(::dessser::gen::raql_operation::data_source*,Pointer)> data_source_to_row_binary(data_source_to_row_binary_init());

/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" "Ptr")
      (let "ssum_dst_870" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_933"
            (let "srec_dst_932"
              (let "srec_dst_926"
                (let "srec_dst_925"
                  (let "srec_dst_924"
                    (let "srec_dst_923"
                      (let "srec_dst_917"
                        (let "srec_dst_911"
                          (let "srec_dst_910"
                            (let "srec_dst_909"
                              (let "srec_dst_900"
                                (let "srec_dst_894"
                                  (let "dst_ref_891"
                                    (make-vec
                                      (let "leb128_sz_889" (make-vec (cardinality (get-field "fields" (get-alt "Aggregate" (param 0)))))
                                        (let "leb128_ptr_890" (make-vec (identifier "ssum_dst_870"))
                                          (seq
                                            (while
                                              (seq
                                                (set-vec (u8 0) (identifier "leb128_ptr_890")
                                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_890"))
                                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_889"))) 
                                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_889"))) 
                                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_889"))) (u8 128)))))
                                                (set-vec (u8 0) (identifier "leb128_sz_889") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_889")) (u8 7))) 
                                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_889")) (u32 0))) 
                                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_890"))))))
                                    (let "n_ref_892" (make-vec (i32 0))
                                      (seq
                                        (for-each "x_893" (get-field "fields" (get-alt "Aggregate" (param 0)))
                                          (seq (set-vec (u8 0) (identifier "dst_ref_891") (apply (ext-identifier raql_select_field to-row-binary) (identifier "x_893") (unsafe-nth (u8 0) (identifier "dst_ref_891"))))
                                            (set-vec (u8 0) (identifier "n_ref_892") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_892")))))) 
                                        (unsafe-nth (u8 0) (identifier "dst_ref_891")))))
                                  (if (is-null (get-field "and_all_others" (get-alt "Aggregate" (param 0)))) 
                                    (write-u8 (identifier "srec_dst_894") (u8 1))
                                    (let "dst_ref_897"
                                      (make-vec
                                        (let "leb128_sz_895" (make-vec (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))
                                          (let "leb128_ptr_896" (make-vec (write-u8 (identifier "srec_dst_894") (u8 0)))
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
                                          (for-each "x_899" (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_897") (apply (ext-identifier field_name to-row-binary) (identifier "x_899") (unsafe-nth (u8 0) (identifier "dst_ref_897"))))
                                              (set-vec (u8 0) (identifier "n_ref_898") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_898")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_897")))))))
                                (if (is-null (get-field "sort" (get-alt "Aggregate" (param 0)))) 
                                  (write-u8 (identifier "srec_dst_900") (u8 1))
                                  (let "stup_dst_903"
                                    (let "stup_dst_902"
                                      (let "stup_dst_901" (write-u8 (identifier "srec_dst_900") (u8 0))
                                        (write-u32 little-endian (identifier "stup_dst_901") (get-item 0 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                      (if (is-null (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) 
                                        (write-u8 (identifier "stup_dst_902") (u8 1))
                                        (apply (ext-identifier raql_expr to-row-binary) (force (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) (write-u8 (identifier "stup_dst_902") (u8 0)))))
                                    (let "dst_ref_906"
                                      (make-vec
                                        (let "leb128_sz_904" (make-vec (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                          (let "leb128_ptr_905" (make-vec (identifier "stup_dst_903"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_905")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_905"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_904"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_904"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_904"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_904") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_904")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_904")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_905"))))))
                                      (let "n_ref_907" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_908" (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_906") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_908") (unsafe-nth (u8 0) (identifier "dst_ref_906"))))
                                              (set-vec (u8 0) (identifier "n_ref_907") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_907")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_906")))))))) 
                              (apply (ext-identifier raql_expr to-row-binary) (get-field "where" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_909")))
                            (if (is-null (get-field "event_time" (get-alt "Aggregate" (param 0)))) 
                              (write-u8 (identifier "srec_dst_910") (u8 1))
                              (apply (ext-identifier event_time to-row-binary) (force (get-field "event_time" (get-alt "Aggregate" (param 0)))) (write-u8 (identifier "srec_dst_910") (u8 0)))))
                          (let "dst_ref_914"
                            (make-vec
                              (let "leb128_sz_912" (make-vec (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0)))))
                                (let "leb128_ptr_913" (make-vec (identifier "srec_dst_911"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_913")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_913"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_912"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_912"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_912"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_912") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_912")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_912")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_913"))))))
                            (let "n_ref_915" (make-vec (i32 0))
                              (seq
                                (for-each "x_916" (get-field "notifications" (get-alt "Aggregate" (param 0)))
                                  (seq (set-vec (u8 0) (identifier "dst_ref_914") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_916") (unsafe-nth (u8 0) (identifier "dst_ref_914"))))
                                    (set-vec (u8 0) (identifier "n_ref_915") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_915")))))) 
                                (unsafe-nth (u8 0) (identifier "dst_ref_914"))))))
                        (let "dst_ref_920"
                          (make-vec
                            (let "leb128_sz_918" (make-vec (cardinality (get-field "key" (get-alt "Aggregate" (param 0)))))
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
                              (for-each "x_922" (get-field "key" (get-alt "Aggregate" (param 0)))
                                (seq (set-vec (u8 0) (identifier "dst_ref_920") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_922") (unsafe-nth (u8 0) (identifier "dst_ref_920"))))
                                  (set-vec (u8 0) (identifier "n_ref_921") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_921")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_920")))))) 
                      (apply (ext-identifier raql_expr to-row-binary) (get-field "commit_cond" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_923")))
                    (write-u8 (identifier "srec_dst_924") (u8-of-bool (get-field "commit_before" (get-alt "Aggregate" (param 0))))))
                  (apply (ext-identifier raql_flush_method to-row-binary) (get-field "flush_how" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_925")))
                (let "dst_ref_929"
                  (make-vec
                    (let "leb128_sz_927" (make-vec (cardinality (get-field "from" (get-alt "Aggregate" (param 0)))))
                      (let "leb128_ptr_928" (make-vec (identifier "srec_dst_926"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_928")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_928"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_927"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_927"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_927"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_927") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_927")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_927")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_928"))))))
                  (let "n_ref_930" (make-vec (i32 0))
                    (seq
                      (for-each "x_931" (get-field "from" (get-alt "Aggregate" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_929") (apply (identifier "data_source-to-row-binary") (identifier "x_931") (unsafe-nth (u8 0) (identifier "dst_ref_929"))))
                          (set-vec (u8 0) (identifier "n_ref_930") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_930")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_929"))))))
              (if (is-null (get-field "every" (get-alt "Aggregate" (param 0)))) 
                (write-u8 (identifier "srec_dst_932") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "every" (get-alt "Aggregate" (param 0)))) (write-u8 (identifier "srec_dst_932") (u8 0)))))
            (let "dst_ref_936"
              (make-vec
                (let "leb128_sz_934" (make-vec (cardinality (get-field "factors" (get-alt "Aggregate" (param 0)))))
                  (let "leb128_ptr_935" (make-vec (identifier "srec_dst_933"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_935")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_935"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_934"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_934"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_934"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_934") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_934")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_934")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_935"))))))
              (let "n_ref_937" (make-vec (i32 0))
                (seq
                  (for-each "x_938" (get-field "factors" (get-alt "Aggregate" (param 0)))
                    (seq (set-vec (u8 0) (identifier "dst_ref_936") (apply (ext-identifier field_name to-row-binary) (identifier "x_938") (unsafe-nth (u8 0) (identifier "dst_ref_936"))))
                      (set-vec (u8 0) (identifier "n_ref_937") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_937")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_936"))))))
          (if (eq (u16 1) (label-of (param 0)))
            (let "srec_dst_883"
              (let "srec_dst_882"
                (let "srec_dst_881" (apply (identifier "external_source-to-row-binary") (get-field "source" (get-alt "ReadExternal" (param 0))) (identifier "ssum_dst_870"))
                  (apply (identifier "external_format-to-row-binary") (get-field "format" (get-alt "ReadExternal" (param 0))) (identifier "srec_dst_881")))
                (if (is-null (get-field "event_time" (get-alt "ReadExternal" (param 0)))) 
                  (write-u8 (identifier "srec_dst_882") (u8 1)) (apply (ext-identifier event_time to-row-binary) (force (get-field "event_time" (get-alt "ReadExternal" (param 0)))) (write-u8 (identifier "srec_dst_882") (u8 0)))))
              (let "dst_ref_886"
                (make-vec
                  (let "leb128_sz_884" (make-vec (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0)))))
                    (let "leb128_ptr_885" (make-vec (identifier "srec_dst_883"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_885")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_885"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_884"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_884"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_884"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_884") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_884")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_884")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_885"))))))
                (let "n_ref_887" (make-vec (i32 0))
                  (seq
                    (for-each "x_888" (get-field "factors" (get-alt "ReadExternal" (param 0)))
                      (seq (set-vec (u8 0) (identifier "dst_ref_886") (apply (ext-identifier field_name to-row-binary) (identifier "x_888") (unsafe-nth (u8 0) (identifier "dst_ref_886"))))
                        (set-vec (u8 0) (identifier "n_ref_887") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_887")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_886"))))))
            (seq (assert (eq (label-of (param 0)) (u16 2)))
              (let "srec_dst_875"
                (let "srec_dst_874"
                  (let "srec_dst_873"
                    (write-bytes
                      (let "leb128_sz_871" (make-vec (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0)))))
                        (let "leb128_ptr_872" (make-vec (identifier "ssum_dst_870"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_872")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_872"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_871"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_871"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_871"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_871") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_871")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_871")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_872"))))) 
                      (bytes-of-string (get-field "net_addr" (get-alt "ListenFor" (param 0))))) 
                    (write-u16 little-endian (identifier "srec_dst_873") (get-field "port" (get-alt "ListenFor" (param 0)))))
                  (apply (ext-identifier raql_net_protocol to-row-binary) (get-field "proto" (get-alt "ListenFor" (param 0))) (identifier "srec_dst_874")))
                (let "dst_ref_878"
                  (make-vec
                    (let "leb128_sz_876" (make-vec (cardinality (get-field "factors" (get-alt "ListenFor" (param 0)))))
                      (let "leb128_ptr_877" (make-vec (identifier "srec_dst_875"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_877")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_877"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_876"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_876"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_876"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_876") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_876")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_876")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_877"))))))
                  (let "n_ref_879" (make-vec (i32 0))
                    (seq
                      (for-each "x_880" (get-field "factors" (get-alt "ListenFor" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_878") (apply (ext-identifier field_name to-row-binary) (identifier "x_880") (unsafe-nth (u8 0) (identifier "dst_ref_878"))))
                          (set-vec (u8 0) (identifier "n_ref_879") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_879")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_878")))))))))))
 */
static std::function<Pointer(::dessser::gen::raql_operation::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_operation::t*,Pointer)> fun1494 { [&fun1494](::dessser::gen::raql_operation::t* p_0, Pointer p_1) {
    uint16_t id_1495 { uint16_t((*p_0).index()) };
    Pointer id_1496 { p_1.writeU16Le(id_1495) };
    Pointer let_res_1497;
    {
      Pointer ssum_dst_870 { id_1496 };
      uint16_t id_1498 { 0 };
      uint16_t id_1499 { uint16_t((*p_0).index()) };
      bool id_1500 { bool(id_1498 == id_1499) };
      Pointer choose_res_1501;
      if (id_1500) {
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1502 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::raql_select_field::t_ext> id_1503 { id_1502.Aggregate_fields };
        uint32_t id_1504 { id_1503.size() };
        Vec<1, uint32_t> id_1505 {  id_1504  };
        Pointer let_res_1506;
        {
          Vec<1, uint32_t> leb128_sz_889 { id_1505 };
          Vec<1, Pointer> id_1507 {  ssum_dst_870  };
          Pointer let_res_1508;
          {
            Vec<1, Pointer> leb128_ptr_890 { id_1507 };
            bool while_flag_1509 { true };
            do {
              uint8_t id_1510 { 0 };
              uint8_t id_1511 { 0 };
              Pointer id_1512 { leb128_ptr_890[id_1511] };
              uint32_t id_1513 { 128U };
              uint8_t id_1514 { 0 };
              uint32_t id_1515 { leb128_sz_889[id_1514] };
              bool id_1516 { bool(id_1513 > id_1515) };
              uint8_t choose_res_1517;
              if (id_1516) {
                uint8_t id_1518 { 0 };
                uint32_t id_1519 { leb128_sz_889[id_1518] };
                uint8_t id_1520 { uint8_t(id_1519) };
                choose_res_1517 = id_1520;
              } else {
                uint8_t id_1521 { 0 };
                uint32_t id_1522 { leb128_sz_889[id_1521] };
                uint8_t id_1523 { uint8_t(id_1522) };
                uint8_t id_1524 { 128 };
                uint8_t id_1525 { uint8_t(id_1523 | id_1524) };
                choose_res_1517 = id_1525;
              }
              Pointer id_1526 { id_1512.writeU8(choose_res_1517) };
              Void id_1527 { ((void)(leb128_ptr_890[id_1510] = id_1526), VOID) };
              (void)id_1527;
              uint8_t id_1528 { 0 };
              uint8_t id_1529 { 0 };
              uint32_t id_1530 { leb128_sz_889[id_1529] };
              uint8_t id_1531 { 7 };
              uint32_t id_1532 { uint32_t(id_1530 >> id_1531) };
              Void id_1533 { ((void)(leb128_sz_889[id_1528] = id_1532), VOID) };
              (void)id_1533;
              uint8_t id_1534 { 0 };
              uint32_t id_1535 { leb128_sz_889[id_1534] };
              uint32_t id_1536 { 0U };
              bool id_1537 { bool(id_1535 > id_1536) };
              while_flag_1509 = id_1537;
              if (while_flag_1509) {
                (void)VOID;
              }
            } while (while_flag_1509);
            (void)VOID;
            uint8_t id_1538 { 0 };
            Pointer id_1539 { leb128_ptr_890[id_1538] };
            let_res_1508 = id_1539;
          }
          let_res_1506 = let_res_1508;
        }
        Vec<1, Pointer> id_1540 {  let_res_1506  };
        Pointer let_res_1541;
        {
          Vec<1, Pointer> dst_ref_891 { id_1540 };
          int32_t id_1542 { 0L };
          Vec<1, int32_t> id_1543 {  id_1542  };
          Pointer let_res_1544;
          {
            Vec<1, int32_t> n_ref_892 { id_1543 };
            ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1545 { std::get<0 /* Aggregate */>((*p_0)) };
            Lst<dessser::gen::raql_select_field::t_ext> id_1546 { id_1545.Aggregate_fields };
            for (dessser::gen::raql_select_field::t_ext x_893 : id_1546) {
              uint8_t id_1547 { 0 };
              auto fun1548 { dessser::gen::raql_select_field::to_row_binary };
              uint8_t id_1549 { 0 };
              Pointer id_1550 { dst_ref_891[id_1549] };
              Pointer id_1551 { fun1548(x_893, id_1550) };
              Void id_1552 { ((void)(dst_ref_891[id_1547] = id_1551), VOID) };
              (void)id_1552;
              uint8_t id_1553 { 0 };
              int32_t id_1554 { 1L };
              uint8_t id_1555 { 0 };
              int32_t id_1556 { n_ref_892[id_1555] };
              int32_t id_1557 { int32_t(id_1554 + id_1556) };
              Void id_1558 { ((void)(n_ref_892[id_1553] = id_1557), VOID) };
              (void)id_1558;
              (void)id_1558;
            }
            (void)VOID;
            uint8_t id_1559 { 0 };
            Pointer id_1560 { dst_ref_891[id_1559] };
            let_res_1544 = id_1560;
          }
          let_res_1541 = let_res_1544;
        }
        Pointer let_res_1561;
        {
          Pointer srec_dst_894 { let_res_1541 };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1562 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<Lst<dessser::gen::field_name::t_ext>> id_1563 { id_1562.and_all_others };
          bool id_1564 { !(id_1563.has_value ()) };
          Pointer choose_res_1565;
          if (id_1564) {
            uint8_t id_1566 { 1 };
            Pointer id_1567 { srec_dst_894.writeU8(id_1566) };
            choose_res_1565 = id_1567;
          } else {
            ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1568 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<Lst<dessser::gen::field_name::t_ext>> id_1569 { id_1568.and_all_others };
            Lst<dessser::gen::field_name::t_ext> id_1570 { id_1569.value() };
            uint32_t id_1571 { id_1570.size() };
            Vec<1, uint32_t> id_1572 {  id_1571  };
            Pointer let_res_1573;
            {
              Vec<1, uint32_t> leb128_sz_895 { id_1572 };
              uint8_t id_1574 { 0 };
              Pointer id_1575 { srec_dst_894.writeU8(id_1574) };
              Vec<1, Pointer> id_1576 {  id_1575  };
              Pointer let_res_1577;
              {
                Vec<1, Pointer> leb128_ptr_896 { id_1576 };
                bool while_flag_1578 { true };
                do {
                  uint8_t id_1579 { 0 };
                  uint8_t id_1580 { 0 };
                  Pointer id_1581 { leb128_ptr_896[id_1580] };
                  uint32_t id_1582 { 128U };
                  uint8_t id_1583 { 0 };
                  uint32_t id_1584 { leb128_sz_895[id_1583] };
                  bool id_1585 { bool(id_1582 > id_1584) };
                  uint8_t choose_res_1586;
                  if (id_1585) {
                    uint8_t id_1587 { 0 };
                    uint32_t id_1588 { leb128_sz_895[id_1587] };
                    uint8_t id_1589 { uint8_t(id_1588) };
                    choose_res_1586 = id_1589;
                  } else {
                    uint8_t id_1590 { 0 };
                    uint32_t id_1591 { leb128_sz_895[id_1590] };
                    uint8_t id_1592 { uint8_t(id_1591) };
                    uint8_t id_1593 { 128 };
                    uint8_t id_1594 { uint8_t(id_1592 | id_1593) };
                    choose_res_1586 = id_1594;
                  }
                  Pointer id_1595 { id_1581.writeU8(choose_res_1586) };
                  Void id_1596 { ((void)(leb128_ptr_896[id_1579] = id_1595), VOID) };
                  (void)id_1596;
                  uint8_t id_1597 { 0 };
                  uint8_t id_1598 { 0 };
                  uint32_t id_1599 { leb128_sz_895[id_1598] };
                  uint8_t id_1600 { 7 };
                  uint32_t id_1601 { uint32_t(id_1599 >> id_1600) };
                  Void id_1602 { ((void)(leb128_sz_895[id_1597] = id_1601), VOID) };
                  (void)id_1602;
                  uint8_t id_1603 { 0 };
                  uint32_t id_1604 { leb128_sz_895[id_1603] };
                  uint32_t id_1605 { 0U };
                  bool id_1606 { bool(id_1604 > id_1605) };
                  while_flag_1578 = id_1606;
                  if (while_flag_1578) {
                    (void)VOID;
                  }
                } while (while_flag_1578);
                (void)VOID;
                uint8_t id_1607 { 0 };
                Pointer id_1608 { leb128_ptr_896[id_1607] };
                let_res_1577 = id_1608;
              }
              let_res_1573 = let_res_1577;
            }
            Vec<1, Pointer> id_1609 {  let_res_1573  };
            Pointer let_res_1610;
            {
              Vec<1, Pointer> dst_ref_897 { id_1609 };
              int32_t id_1611 { 0L };
              Vec<1, int32_t> id_1612 {  id_1611  };
              Pointer let_res_1613;
              {
                Vec<1, int32_t> n_ref_898 { id_1612 };
                ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1614 { std::get<0 /* Aggregate */>((*p_0)) };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_1615 { id_1614.and_all_others };
                Lst<dessser::gen::field_name::t_ext> id_1616 { id_1615.value() };
                for (dessser::gen::field_name::t_ext x_899 : id_1616) {
                  uint8_t id_1617 { 0 };
                  auto fun1618 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_1619 { 0 };
                  Pointer id_1620 { dst_ref_897[id_1619] };
                  Pointer id_1621 { fun1618(x_899, id_1620) };
                  Void id_1622 { ((void)(dst_ref_897[id_1617] = id_1621), VOID) };
                  (void)id_1622;
                  uint8_t id_1623 { 0 };
                  int32_t id_1624 { 1L };
                  uint8_t id_1625 { 0 };
                  int32_t id_1626 { n_ref_898[id_1625] };
                  int32_t id_1627 { int32_t(id_1624 + id_1626) };
                  Void id_1628 { ((void)(n_ref_898[id_1623] = id_1627), VOID) };
                  (void)id_1628;
                  (void)id_1628;
                }
                (void)VOID;
                uint8_t id_1629 { 0 };
                Pointer id_1630 { dst_ref_897[id_1629] };
                let_res_1613 = id_1630;
              }
              let_res_1610 = let_res_1613;
            }
            choose_res_1565 = let_res_1610;
          }
          let_res_1561 = choose_res_1565;
        }
        Pointer let_res_1631;
        {
          Pointer srec_dst_900 { let_res_1561 };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1632 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_1633 { id_1632.sort };
          bool id_1634 { !(id_1633.has_value ()) };
          Pointer choose_res_1635;
          if (id_1634) {
            uint8_t id_1636 { 1 };
            Pointer id_1637 { srec_dst_900.writeU8(id_1636) };
            choose_res_1635 = id_1637;
          } else {
            uint8_t id_1638 { 0 };
            Pointer id_1639 { srec_dst_900.writeU8(id_1638) };
            Pointer let_res_1640;
            {
              Pointer stup_dst_901 { id_1639 };
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1641 { std::get<0 /* Aggregate */>((*p_0)) };
              std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_1642 { id_1641.sort };
              ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_1643 { id_1642.value() };
              uint32_t id_1644 { std::get<0>(id_1643) };
              Pointer id_1645 { stup_dst_901.writeU32Le(id_1644) };
              let_res_1640 = id_1645;
            }
            Pointer let_res_1646;
            {
              Pointer stup_dst_902 { let_res_1640 };
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1647 { std::get<0 /* Aggregate */>((*p_0)) };
              std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_1648 { id_1647.sort };
              ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_1649 { id_1648.value() };
              std::optional<dessser::gen::raql_expr::t_ext> id_1650 { std::get<1>(id_1649) };
              bool id_1651 { !(id_1650.has_value ()) };
              Pointer choose_res_1652;
              if (id_1651) {
                uint8_t id_1653 { 1 };
                Pointer id_1654 { stup_dst_902.writeU8(id_1653) };
                choose_res_1652 = id_1654;
              } else {
                auto fun1655 { dessser::gen::raql_expr::to_row_binary };
                ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1656 { std::get<0 /* Aggregate */>((*p_0)) };
                std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_1657 { id_1656.sort };
                ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_1658 { id_1657.value() };
                std::optional<dessser::gen::raql_expr::t_ext> id_1659 { std::get<1>(id_1658) };
                dessser::gen::raql_expr::t_ext id_1660 { id_1659.value() };
                uint8_t id_1661 { 0 };
                Pointer id_1662 { stup_dst_902.writeU8(id_1661) };
                Pointer id_1663 { fun1655(id_1660, id_1662) };
                choose_res_1652 = id_1663;
              }
              let_res_1646 = choose_res_1652;
            }
            Pointer let_res_1664;
            {
              Pointer stup_dst_903 { let_res_1646 };
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1665 { std::get<0 /* Aggregate */>((*p_0)) };
              std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_1666 { id_1665.sort };
              ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_1667 { id_1666.value() };
              Lst<dessser::gen::raql_expr::t_ext> id_1668 { std::get<2>(id_1667) };
              uint32_t id_1669 { id_1668.size() };
              Vec<1, uint32_t> id_1670 {  id_1669  };
              Pointer let_res_1671;
              {
                Vec<1, uint32_t> leb128_sz_904 { id_1670 };
                Vec<1, Pointer> id_1672 {  stup_dst_903  };
                Pointer let_res_1673;
                {
                  Vec<1, Pointer> leb128_ptr_905 { id_1672 };
                  bool while_flag_1674 { true };
                  do {
                    uint8_t id_1675 { 0 };
                    uint8_t id_1676 { 0 };
                    Pointer id_1677 { leb128_ptr_905[id_1676] };
                    uint32_t id_1678 { 128U };
                    uint8_t id_1679 { 0 };
                    uint32_t id_1680 { leb128_sz_904[id_1679] };
                    bool id_1681 { bool(id_1678 > id_1680) };
                    uint8_t choose_res_1682;
                    if (id_1681) {
                      uint8_t id_1683 { 0 };
                      uint32_t id_1684 { leb128_sz_904[id_1683] };
                      uint8_t id_1685 { uint8_t(id_1684) };
                      choose_res_1682 = id_1685;
                    } else {
                      uint8_t id_1686 { 0 };
                      uint32_t id_1687 { leb128_sz_904[id_1686] };
                      uint8_t id_1688 { uint8_t(id_1687) };
                      uint8_t id_1689 { 128 };
                      uint8_t id_1690 { uint8_t(id_1688 | id_1689) };
                      choose_res_1682 = id_1690;
                    }
                    Pointer id_1691 { id_1677.writeU8(choose_res_1682) };
                    Void id_1692 { ((void)(leb128_ptr_905[id_1675] = id_1691), VOID) };
                    (void)id_1692;
                    uint8_t id_1693 { 0 };
                    uint8_t id_1694 { 0 };
                    uint32_t id_1695 { leb128_sz_904[id_1694] };
                    uint8_t id_1696 { 7 };
                    uint32_t id_1697 { uint32_t(id_1695 >> id_1696) };
                    Void id_1698 { ((void)(leb128_sz_904[id_1693] = id_1697), VOID) };
                    (void)id_1698;
                    uint8_t id_1699 { 0 };
                    uint32_t id_1700 { leb128_sz_904[id_1699] };
                    uint32_t id_1701 { 0U };
                    bool id_1702 { bool(id_1700 > id_1701) };
                    while_flag_1674 = id_1702;
                    if (while_flag_1674) {
                      (void)VOID;
                    }
                  } while (while_flag_1674);
                  (void)VOID;
                  uint8_t id_1703 { 0 };
                  Pointer id_1704 { leb128_ptr_905[id_1703] };
                  let_res_1673 = id_1704;
                }
                let_res_1671 = let_res_1673;
              }
              Vec<1, Pointer> id_1705 {  let_res_1671  };
              Pointer let_res_1706;
              {
                Vec<1, Pointer> dst_ref_906 { id_1705 };
                int32_t id_1707 { 0L };
                Vec<1, int32_t> id_1708 {  id_1707  };
                Pointer let_res_1709;
                {
                  Vec<1, int32_t> n_ref_907 { id_1708 };
                  ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1710 { std::get<0 /* Aggregate */>((*p_0)) };
                  std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_1711 { id_1710.sort };
                  ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_1712 { id_1711.value() };
                  Lst<dessser::gen::raql_expr::t_ext> id_1713 { std::get<2>(id_1712) };
                  for (dessser::gen::raql_expr::t_ext x_908 : id_1713) {
                    uint8_t id_1714 { 0 };
                    auto fun1715 { dessser::gen::raql_expr::to_row_binary };
                    uint8_t id_1716 { 0 };
                    Pointer id_1717 { dst_ref_906[id_1716] };
                    Pointer id_1718 { fun1715(x_908, id_1717) };
                    Void id_1719 { ((void)(dst_ref_906[id_1714] = id_1718), VOID) };
                    (void)id_1719;
                    uint8_t id_1720 { 0 };
                    int32_t id_1721 { 1L };
                    uint8_t id_1722 { 0 };
                    int32_t id_1723 { n_ref_907[id_1722] };
                    int32_t id_1724 { int32_t(id_1721 + id_1723) };
                    Void id_1725 { ((void)(n_ref_907[id_1720] = id_1724), VOID) };
                    (void)id_1725;
                    (void)id_1725;
                  }
                  (void)VOID;
                  uint8_t id_1726 { 0 };
                  Pointer id_1727 { dst_ref_906[id_1726] };
                  let_res_1709 = id_1727;
                }
                let_res_1706 = let_res_1709;
              }
              let_res_1664 = let_res_1706;
            }
            choose_res_1635 = let_res_1664;
          }
          let_res_1631 = choose_res_1635;
        }
        Pointer let_res_1728;
        {
          Pointer srec_dst_909 { let_res_1631 };
          auto fun1729 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1730 { std::get<0 /* Aggregate */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_1731 { id_1730.where };
          Pointer id_1732 { fun1729(id_1731, srec_dst_909) };
          let_res_1728 = id_1732;
        }
        Pointer let_res_1733;
        {
          Pointer srec_dst_910 { let_res_1728 };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1734 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::event_time::t_ext> id_1735 { id_1734.Aggregate_event_time };
          bool id_1736 { !(id_1735.has_value ()) };
          Pointer choose_res_1737;
          if (id_1736) {
            uint8_t id_1738 { 1 };
            Pointer id_1739 { srec_dst_910.writeU8(id_1738) };
            choose_res_1737 = id_1739;
          } else {
            auto fun1740 { dessser::gen::event_time::to_row_binary };
            ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1741 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<dessser::gen::event_time::t_ext> id_1742 { id_1741.Aggregate_event_time };
            dessser::gen::event_time::t_ext id_1743 { id_1742.value() };
            uint8_t id_1744 { 0 };
            Pointer id_1745 { srec_dst_910.writeU8(id_1744) };
            Pointer id_1746 { fun1740(id_1743, id_1745) };
            choose_res_1737 = id_1746;
          }
          let_res_1733 = choose_res_1737;
        }
        Pointer let_res_1747;
        {
          Pointer srec_dst_911 { let_res_1733 };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1748 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<dessser::gen::raql_expr::t_ext> id_1749 { id_1748.notifications };
          uint32_t id_1750 { id_1749.size() };
          Vec<1, uint32_t> id_1751 {  id_1750  };
          Pointer let_res_1752;
          {
            Vec<1, uint32_t> leb128_sz_912 { id_1751 };
            Vec<1, Pointer> id_1753 {  srec_dst_911  };
            Pointer let_res_1754;
            {
              Vec<1, Pointer> leb128_ptr_913 { id_1753 };
              bool while_flag_1755 { true };
              do {
                uint8_t id_1756 { 0 };
                uint8_t id_1757 { 0 };
                Pointer id_1758 { leb128_ptr_913[id_1757] };
                uint32_t id_1759 { 128U };
                uint8_t id_1760 { 0 };
                uint32_t id_1761 { leb128_sz_912[id_1760] };
                bool id_1762 { bool(id_1759 > id_1761) };
                uint8_t choose_res_1763;
                if (id_1762) {
                  uint8_t id_1764 { 0 };
                  uint32_t id_1765 { leb128_sz_912[id_1764] };
                  uint8_t id_1766 { uint8_t(id_1765) };
                  choose_res_1763 = id_1766;
                } else {
                  uint8_t id_1767 { 0 };
                  uint32_t id_1768 { leb128_sz_912[id_1767] };
                  uint8_t id_1769 { uint8_t(id_1768) };
                  uint8_t id_1770 { 128 };
                  uint8_t id_1771 { uint8_t(id_1769 | id_1770) };
                  choose_res_1763 = id_1771;
                }
                Pointer id_1772 { id_1758.writeU8(choose_res_1763) };
                Void id_1773 { ((void)(leb128_ptr_913[id_1756] = id_1772), VOID) };
                (void)id_1773;
                uint8_t id_1774 { 0 };
                uint8_t id_1775 { 0 };
                uint32_t id_1776 { leb128_sz_912[id_1775] };
                uint8_t id_1777 { 7 };
                uint32_t id_1778 { uint32_t(id_1776 >> id_1777) };
                Void id_1779 { ((void)(leb128_sz_912[id_1774] = id_1778), VOID) };
                (void)id_1779;
                uint8_t id_1780 { 0 };
                uint32_t id_1781 { leb128_sz_912[id_1780] };
                uint32_t id_1782 { 0U };
                bool id_1783 { bool(id_1781 > id_1782) };
                while_flag_1755 = id_1783;
                if (while_flag_1755) {
                  (void)VOID;
                }
              } while (while_flag_1755);
              (void)VOID;
              uint8_t id_1784 { 0 };
              Pointer id_1785 { leb128_ptr_913[id_1784] };
              let_res_1754 = id_1785;
            }
            let_res_1752 = let_res_1754;
          }
          Vec<1, Pointer> id_1786 {  let_res_1752  };
          Pointer let_res_1787;
          {
            Vec<1, Pointer> dst_ref_914 { id_1786 };
            int32_t id_1788 { 0L };
            Vec<1, int32_t> id_1789 {  id_1788  };
            Pointer let_res_1790;
            {
              Vec<1, int32_t> n_ref_915 { id_1789 };
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1791 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_1792 { id_1791.notifications };
              for (dessser::gen::raql_expr::t_ext x_916 : id_1792) {
                uint8_t id_1793 { 0 };
                auto fun1794 { dessser::gen::raql_expr::to_row_binary };
                uint8_t id_1795 { 0 };
                Pointer id_1796 { dst_ref_914[id_1795] };
                Pointer id_1797 { fun1794(x_916, id_1796) };
                Void id_1798 { ((void)(dst_ref_914[id_1793] = id_1797), VOID) };
                (void)id_1798;
                uint8_t id_1799 { 0 };
                int32_t id_1800 { 1L };
                uint8_t id_1801 { 0 };
                int32_t id_1802 { n_ref_915[id_1801] };
                int32_t id_1803 { int32_t(id_1800 + id_1802) };
                Void id_1804 { ((void)(n_ref_915[id_1799] = id_1803), VOID) };
                (void)id_1804;
                (void)id_1804;
              }
              (void)VOID;
              uint8_t id_1805 { 0 };
              Pointer id_1806 { dst_ref_914[id_1805] };
              let_res_1790 = id_1806;
            }
            let_res_1787 = let_res_1790;
          }
          let_res_1747 = let_res_1787;
        }
        Pointer let_res_1807;
        {
          Pointer srec_dst_917 { let_res_1747 };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1808 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<dessser::gen::raql_expr::t_ext> id_1809 { id_1808.key };
          uint32_t id_1810 { id_1809.size() };
          Vec<1, uint32_t> id_1811 {  id_1810  };
          Pointer let_res_1812;
          {
            Vec<1, uint32_t> leb128_sz_918 { id_1811 };
            Vec<1, Pointer> id_1813 {  srec_dst_917  };
            Pointer let_res_1814;
            {
              Vec<1, Pointer> leb128_ptr_919 { id_1813 };
              bool while_flag_1815 { true };
              do {
                uint8_t id_1816 { 0 };
                uint8_t id_1817 { 0 };
                Pointer id_1818 { leb128_ptr_919[id_1817] };
                uint32_t id_1819 { 128U };
                uint8_t id_1820 { 0 };
                uint32_t id_1821 { leb128_sz_918[id_1820] };
                bool id_1822 { bool(id_1819 > id_1821) };
                uint8_t choose_res_1823;
                if (id_1822) {
                  uint8_t id_1824 { 0 };
                  uint32_t id_1825 { leb128_sz_918[id_1824] };
                  uint8_t id_1826 { uint8_t(id_1825) };
                  choose_res_1823 = id_1826;
                } else {
                  uint8_t id_1827 { 0 };
                  uint32_t id_1828 { leb128_sz_918[id_1827] };
                  uint8_t id_1829 { uint8_t(id_1828) };
                  uint8_t id_1830 { 128 };
                  uint8_t id_1831 { uint8_t(id_1829 | id_1830) };
                  choose_res_1823 = id_1831;
                }
                Pointer id_1832 { id_1818.writeU8(choose_res_1823) };
                Void id_1833 { ((void)(leb128_ptr_919[id_1816] = id_1832), VOID) };
                (void)id_1833;
                uint8_t id_1834 { 0 };
                uint8_t id_1835 { 0 };
                uint32_t id_1836 { leb128_sz_918[id_1835] };
                uint8_t id_1837 { 7 };
                uint32_t id_1838 { uint32_t(id_1836 >> id_1837) };
                Void id_1839 { ((void)(leb128_sz_918[id_1834] = id_1838), VOID) };
                (void)id_1839;
                uint8_t id_1840 { 0 };
                uint32_t id_1841 { leb128_sz_918[id_1840] };
                uint32_t id_1842 { 0U };
                bool id_1843 { bool(id_1841 > id_1842) };
                while_flag_1815 = id_1843;
                if (while_flag_1815) {
                  (void)VOID;
                }
              } while (while_flag_1815);
              (void)VOID;
              uint8_t id_1844 { 0 };
              Pointer id_1845 { leb128_ptr_919[id_1844] };
              let_res_1814 = id_1845;
            }
            let_res_1812 = let_res_1814;
          }
          Vec<1, Pointer> id_1846 {  let_res_1812  };
          Pointer let_res_1847;
          {
            Vec<1, Pointer> dst_ref_920 { id_1846 };
            int32_t id_1848 { 0L };
            Vec<1, int32_t> id_1849 {  id_1848  };
            Pointer let_res_1850;
            {
              Vec<1, int32_t> n_ref_921 { id_1849 };
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1851 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_1852 { id_1851.key };
              for (dessser::gen::raql_expr::t_ext x_922 : id_1852) {
                uint8_t id_1853 { 0 };
                auto fun1854 { dessser::gen::raql_expr::to_row_binary };
                uint8_t id_1855 { 0 };
                Pointer id_1856 { dst_ref_920[id_1855] };
                Pointer id_1857 { fun1854(x_922, id_1856) };
                Void id_1858 { ((void)(dst_ref_920[id_1853] = id_1857), VOID) };
                (void)id_1858;
                uint8_t id_1859 { 0 };
                int32_t id_1860 { 1L };
                uint8_t id_1861 { 0 };
                int32_t id_1862 { n_ref_921[id_1861] };
                int32_t id_1863 { int32_t(id_1860 + id_1862) };
                Void id_1864 { ((void)(n_ref_921[id_1859] = id_1863), VOID) };
                (void)id_1864;
                (void)id_1864;
              }
              (void)VOID;
              uint8_t id_1865 { 0 };
              Pointer id_1866 { dst_ref_920[id_1865] };
              let_res_1850 = id_1866;
            }
            let_res_1847 = let_res_1850;
          }
          let_res_1807 = let_res_1847;
        }
        Pointer let_res_1867;
        {
          Pointer srec_dst_923 { let_res_1807 };
          auto fun1868 { dessser::gen::raql_expr::to_row_binary };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1869 { std::get<0 /* Aggregate */>((*p_0)) };
          dessser::gen::raql_expr::t_ext id_1870 { id_1869.commit_cond };
          Pointer id_1871 { fun1868(id_1870, srec_dst_923) };
          let_res_1867 = id_1871;
        }
        Pointer let_res_1872;
        {
          Pointer srec_dst_924 { let_res_1867 };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1873 { std::get<0 /* Aggregate */>((*p_0)) };
          bool id_1874 { id_1873.commit_before };
          uint8_t id_1875 { uint8_t(id_1874) };
          Pointer id_1876 { srec_dst_924.writeU8(id_1875) };
          let_res_1872 = id_1876;
        }
        Pointer let_res_1877;
        {
          Pointer srec_dst_925 { let_res_1872 };
          auto fun1878 { dessser::gen::raql_flush_method::to_row_binary };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1879 { std::get<0 /* Aggregate */>((*p_0)) };
          dessser::gen::raql_flush_method::t_ext id_1880 { id_1879.flush_how };
          Pointer id_1881 { fun1878(id_1880, srec_dst_925) };
          let_res_1877 = id_1881;
        }
        Pointer let_res_1882;
        {
          Pointer srec_dst_926 { let_res_1877 };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1883 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<::dessser::gen::raql_operation::data_source*> id_1884 { id_1883.from };
          uint32_t id_1885 { id_1884.size() };
          Vec<1, uint32_t> id_1886 {  id_1885  };
          Pointer let_res_1887;
          {
            Vec<1, uint32_t> leb128_sz_927 { id_1886 };
            Vec<1, Pointer> id_1888 {  srec_dst_926  };
            Pointer let_res_1889;
            {
              Vec<1, Pointer> leb128_ptr_928 { id_1888 };
              bool while_flag_1890 { true };
              do {
                uint8_t id_1891 { 0 };
                uint8_t id_1892 { 0 };
                Pointer id_1893 { leb128_ptr_928[id_1892] };
                uint32_t id_1894 { 128U };
                uint8_t id_1895 { 0 };
                uint32_t id_1896 { leb128_sz_927[id_1895] };
                bool id_1897 { bool(id_1894 > id_1896) };
                uint8_t choose_res_1898;
                if (id_1897) {
                  uint8_t id_1899 { 0 };
                  uint32_t id_1900 { leb128_sz_927[id_1899] };
                  uint8_t id_1901 { uint8_t(id_1900) };
                  choose_res_1898 = id_1901;
                } else {
                  uint8_t id_1902 { 0 };
                  uint32_t id_1903 { leb128_sz_927[id_1902] };
                  uint8_t id_1904 { uint8_t(id_1903) };
                  uint8_t id_1905 { 128 };
                  uint8_t id_1906 { uint8_t(id_1904 | id_1905) };
                  choose_res_1898 = id_1906;
                }
                Pointer id_1907 { id_1893.writeU8(choose_res_1898) };
                Void id_1908 { ((void)(leb128_ptr_928[id_1891] = id_1907), VOID) };
                (void)id_1908;
                uint8_t id_1909 { 0 };
                uint8_t id_1910 { 0 };
                uint32_t id_1911 { leb128_sz_927[id_1910] };
                uint8_t id_1912 { 7 };
                uint32_t id_1913 { uint32_t(id_1911 >> id_1912) };
                Void id_1914 { ((void)(leb128_sz_927[id_1909] = id_1913), VOID) };
                (void)id_1914;
                uint8_t id_1915 { 0 };
                uint32_t id_1916 { leb128_sz_927[id_1915] };
                uint32_t id_1917 { 0U };
                bool id_1918 { bool(id_1916 > id_1917) };
                while_flag_1890 = id_1918;
                if (while_flag_1890) {
                  (void)VOID;
                }
              } while (while_flag_1890);
              (void)VOID;
              uint8_t id_1919 { 0 };
              Pointer id_1920 { leb128_ptr_928[id_1919] };
              let_res_1889 = id_1920;
            }
            let_res_1887 = let_res_1889;
          }
          Vec<1, Pointer> id_1921 {  let_res_1887  };
          Pointer let_res_1922;
          {
            Vec<1, Pointer> dst_ref_929 { id_1921 };
            int32_t id_1923 { 0L };
            Vec<1, int32_t> id_1924 {  id_1923  };
            Pointer let_res_1925;
            {
              Vec<1, int32_t> n_ref_930 { id_1924 };
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1926 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<::dessser::gen::raql_operation::data_source*> id_1927 { id_1926.from };
              for (::dessser::gen::raql_operation::data_source* x_931 : id_1927) {
                uint8_t id_1928 { 0 };
                uint8_t id_1929 { 0 };
                Pointer id_1930 { dst_ref_929[id_1929] };
                Pointer id_1931 { data_source_to_row_binary(x_931, id_1930) };
                Void id_1932 { ((void)(dst_ref_929[id_1928] = id_1931), VOID) };
                (void)id_1932;
                uint8_t id_1933 { 0 };
                int32_t id_1934 { 1L };
                uint8_t id_1935 { 0 };
                int32_t id_1936 { n_ref_930[id_1935] };
                int32_t id_1937 { int32_t(id_1934 + id_1936) };
                Void id_1938 { ((void)(n_ref_930[id_1933] = id_1937), VOID) };
                (void)id_1938;
                (void)id_1938;
              }
              (void)VOID;
              uint8_t id_1939 { 0 };
              Pointer id_1940 { dst_ref_929[id_1939] };
              let_res_1925 = id_1940;
            }
            let_res_1922 = let_res_1925;
          }
          let_res_1882 = let_res_1922;
        }
        Pointer let_res_1941;
        {
          Pointer srec_dst_932 { let_res_1882 };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1942 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_1943 { id_1942.every };
          bool id_1944 { !(id_1943.has_value ()) };
          Pointer choose_res_1945;
          if (id_1944) {
            uint8_t id_1946 { 1 };
            Pointer id_1947 { srec_dst_932.writeU8(id_1946) };
            choose_res_1945 = id_1947;
          } else {
            auto fun1948 { dessser::gen::raql_expr::to_row_binary };
            ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1949 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<dessser::gen::raql_expr::t_ext> id_1950 { id_1949.every };
            dessser::gen::raql_expr::t_ext id_1951 { id_1950.value() };
            uint8_t id_1952 { 0 };
            Pointer id_1953 { srec_dst_932.writeU8(id_1952) };
            Pointer id_1954 { fun1948(id_1951, id_1953) };
            choose_res_1945 = id_1954;
          }
          let_res_1941 = choose_res_1945;
        }
        Pointer let_res_1955;
        {
          Pointer srec_dst_933 { let_res_1941 };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1956 { std::get<0 /* Aggregate */>((*p_0)) };
          Lst<dessser::gen::field_name::t_ext> id_1957 { id_1956.Aggregate_factors };
          uint32_t id_1958 { id_1957.size() };
          Vec<1, uint32_t> id_1959 {  id_1958  };
          Pointer let_res_1960;
          {
            Vec<1, uint32_t> leb128_sz_934 { id_1959 };
            Vec<1, Pointer> id_1961 {  srec_dst_933  };
            Pointer let_res_1962;
            {
              Vec<1, Pointer> leb128_ptr_935 { id_1961 };
              bool while_flag_1963 { true };
              do {
                uint8_t id_1964 { 0 };
                uint8_t id_1965 { 0 };
                Pointer id_1966 { leb128_ptr_935[id_1965] };
                uint32_t id_1967 { 128U };
                uint8_t id_1968 { 0 };
                uint32_t id_1969 { leb128_sz_934[id_1968] };
                bool id_1970 { bool(id_1967 > id_1969) };
                uint8_t choose_res_1971;
                if (id_1970) {
                  uint8_t id_1972 { 0 };
                  uint32_t id_1973 { leb128_sz_934[id_1972] };
                  uint8_t id_1974 { uint8_t(id_1973) };
                  choose_res_1971 = id_1974;
                } else {
                  uint8_t id_1975 { 0 };
                  uint32_t id_1976 { leb128_sz_934[id_1975] };
                  uint8_t id_1977 { uint8_t(id_1976) };
                  uint8_t id_1978 { 128 };
                  uint8_t id_1979 { uint8_t(id_1977 | id_1978) };
                  choose_res_1971 = id_1979;
                }
                Pointer id_1980 { id_1966.writeU8(choose_res_1971) };
                Void id_1981 { ((void)(leb128_ptr_935[id_1964] = id_1980), VOID) };
                (void)id_1981;
                uint8_t id_1982 { 0 };
                uint8_t id_1983 { 0 };
                uint32_t id_1984 { leb128_sz_934[id_1983] };
                uint8_t id_1985 { 7 };
                uint32_t id_1986 { uint32_t(id_1984 >> id_1985) };
                Void id_1987 { ((void)(leb128_sz_934[id_1982] = id_1986), VOID) };
                (void)id_1987;
                uint8_t id_1988 { 0 };
                uint32_t id_1989 { leb128_sz_934[id_1988] };
                uint32_t id_1990 { 0U };
                bool id_1991 { bool(id_1989 > id_1990) };
                while_flag_1963 = id_1991;
                if (while_flag_1963) {
                  (void)VOID;
                }
              } while (while_flag_1963);
              (void)VOID;
              uint8_t id_1992 { 0 };
              Pointer id_1993 { leb128_ptr_935[id_1992] };
              let_res_1962 = id_1993;
            }
            let_res_1960 = let_res_1962;
          }
          Vec<1, Pointer> id_1994 {  let_res_1960  };
          Pointer let_res_1995;
          {
            Vec<1, Pointer> dst_ref_936 { id_1994 };
            int32_t id_1996 { 0L };
            Vec<1, int32_t> id_1997 {  id_1996  };
            Pointer let_res_1998;
            {
              Vec<1, int32_t> n_ref_937 { id_1997 };
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_1999 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::field_name::t_ext> id_2000 { id_1999.Aggregate_factors };
              for (dessser::gen::field_name::t_ext x_938 : id_2000) {
                uint8_t id_2001 { 0 };
                auto fun2002 { dessser::gen::field_name::to_row_binary };
                uint8_t id_2003 { 0 };
                Pointer id_2004 { dst_ref_936[id_2003] };
                Pointer id_2005 { fun2002(x_938, id_2004) };
                Void id_2006 { ((void)(dst_ref_936[id_2001] = id_2005), VOID) };
                (void)id_2006;
                uint8_t id_2007 { 0 };
                int32_t id_2008 { 1L };
                uint8_t id_2009 { 0 };
                int32_t id_2010 { n_ref_937[id_2009] };
                int32_t id_2011 { int32_t(id_2008 + id_2010) };
                Void id_2012 { ((void)(n_ref_937[id_2007] = id_2011), VOID) };
                (void)id_2012;
                (void)id_2012;
              }
              (void)VOID;
              uint8_t id_2013 { 0 };
              Pointer id_2014 { dst_ref_936[id_2013] };
              let_res_1998 = id_2014;
            }
            let_res_1995 = let_res_1998;
          }
          let_res_1955 = let_res_1995;
        }
        choose_res_1501 = let_res_1955;
      } else {
        uint16_t id_2015 { 1 };
        uint16_t id_2016 { uint16_t((*p_0).index()) };
        bool id_2017 { bool(id_2015 == id_2016) };
        Pointer choose_res_2018;
        if (id_2017) {
          ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2019 { std::get<1 /* ReadExternal */>((*p_0)) };
          ::dessser::gen::raql_operation::external_source* id_2020 { id_2019.source };
          Pointer id_2021 { external_source_to_row_binary(id_2020, ssum_dst_870) };
          Pointer let_res_2022;
          {
            Pointer srec_dst_881 { id_2021 };
            ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2023 { std::get<1 /* ReadExternal */>((*p_0)) };
            ::dessser::gen::raql_operation::external_format* id_2024 { id_2023.format };
            Pointer id_2025 { external_format_to_row_binary(id_2024, srec_dst_881) };
            let_res_2022 = id_2025;
          }
          Pointer let_res_2026;
          {
            Pointer srec_dst_882 { let_res_2022 };
            ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2027 { std::get<1 /* ReadExternal */>((*p_0)) };
            std::optional<dessser::gen::event_time::t_ext> id_2028 { id_2027.event_time };
            bool id_2029 { !(id_2028.has_value ()) };
            Pointer choose_res_2030;
            if (id_2029) {
              uint8_t id_2031 { 1 };
              Pointer id_2032 { srec_dst_882.writeU8(id_2031) };
              choose_res_2030 = id_2032;
            } else {
              auto fun2033 { dessser::gen::event_time::to_row_binary };
              ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2034 { std::get<1 /* ReadExternal */>((*p_0)) };
              std::optional<dessser::gen::event_time::t_ext> id_2035 { id_2034.event_time };
              dessser::gen::event_time::t_ext id_2036 { id_2035.value() };
              uint8_t id_2037 { 0 };
              Pointer id_2038 { srec_dst_882.writeU8(id_2037) };
              Pointer id_2039 { fun2033(id_2036, id_2038) };
              choose_res_2030 = id_2039;
            }
            let_res_2026 = choose_res_2030;
          }
          Pointer let_res_2040;
          {
            Pointer srec_dst_883 { let_res_2026 };
            ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2041 { std::get<1 /* ReadExternal */>((*p_0)) };
            Lst<dessser::gen::field_name::t_ext> id_2042 { id_2041.ReadExternal_factors };
            uint32_t id_2043 { id_2042.size() };
            Vec<1, uint32_t> id_2044 {  id_2043  };
            Pointer let_res_2045;
            {
              Vec<1, uint32_t> leb128_sz_884 { id_2044 };
              Vec<1, Pointer> id_2046 {  srec_dst_883  };
              Pointer let_res_2047;
              {
                Vec<1, Pointer> leb128_ptr_885 { id_2046 };
                bool while_flag_2048 { true };
                do {
                  uint8_t id_2049 { 0 };
                  uint8_t id_2050 { 0 };
                  Pointer id_2051 { leb128_ptr_885[id_2050] };
                  uint32_t id_2052 { 128U };
                  uint8_t id_2053 { 0 };
                  uint32_t id_2054 { leb128_sz_884[id_2053] };
                  bool id_2055 { bool(id_2052 > id_2054) };
                  uint8_t choose_res_2056;
                  if (id_2055) {
                    uint8_t id_2057 { 0 };
                    uint32_t id_2058 { leb128_sz_884[id_2057] };
                    uint8_t id_2059 { uint8_t(id_2058) };
                    choose_res_2056 = id_2059;
                  } else {
                    uint8_t id_2060 { 0 };
                    uint32_t id_2061 { leb128_sz_884[id_2060] };
                    uint8_t id_2062 { uint8_t(id_2061) };
                    uint8_t id_2063 { 128 };
                    uint8_t id_2064 { uint8_t(id_2062 | id_2063) };
                    choose_res_2056 = id_2064;
                  }
                  Pointer id_2065 { id_2051.writeU8(choose_res_2056) };
                  Void id_2066 { ((void)(leb128_ptr_885[id_2049] = id_2065), VOID) };
                  (void)id_2066;
                  uint8_t id_2067 { 0 };
                  uint8_t id_2068 { 0 };
                  uint32_t id_2069 { leb128_sz_884[id_2068] };
                  uint8_t id_2070 { 7 };
                  uint32_t id_2071 { uint32_t(id_2069 >> id_2070) };
                  Void id_2072 { ((void)(leb128_sz_884[id_2067] = id_2071), VOID) };
                  (void)id_2072;
                  uint8_t id_2073 { 0 };
                  uint32_t id_2074 { leb128_sz_884[id_2073] };
                  uint32_t id_2075 { 0U };
                  bool id_2076 { bool(id_2074 > id_2075) };
                  while_flag_2048 = id_2076;
                  if (while_flag_2048) {
                    (void)VOID;
                  }
                } while (while_flag_2048);
                (void)VOID;
                uint8_t id_2077 { 0 };
                Pointer id_2078 { leb128_ptr_885[id_2077] };
                let_res_2047 = id_2078;
              }
              let_res_2045 = let_res_2047;
            }
            Vec<1, Pointer> id_2079 {  let_res_2045  };
            Pointer let_res_2080;
            {
              Vec<1, Pointer> dst_ref_886 { id_2079 };
              int32_t id_2081 { 0L };
              Vec<1, int32_t> id_2082 {  id_2081  };
              Pointer let_res_2083;
              {
                Vec<1, int32_t> n_ref_887 { id_2082 };
                ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2084 { std::get<1 /* ReadExternal */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2085 { id_2084.ReadExternal_factors };
                for (dessser::gen::field_name::t_ext x_888 : id_2085) {
                  uint8_t id_2086 { 0 };
                  auto fun2087 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_2088 { 0 };
                  Pointer id_2089 { dst_ref_886[id_2088] };
                  Pointer id_2090 { fun2087(x_888, id_2089) };
                  Void id_2091 { ((void)(dst_ref_886[id_2086] = id_2090), VOID) };
                  (void)id_2091;
                  uint8_t id_2092 { 0 };
                  int32_t id_2093 { 1L };
                  uint8_t id_2094 { 0 };
                  int32_t id_2095 { n_ref_887[id_2094] };
                  int32_t id_2096 { int32_t(id_2093 + id_2095) };
                  Void id_2097 { ((void)(n_ref_887[id_2092] = id_2096), VOID) };
                  (void)id_2097;
                  (void)id_2097;
                }
                (void)VOID;
                uint8_t id_2098 { 0 };
                Pointer id_2099 { dst_ref_886[id_2098] };
                let_res_2083 = id_2099;
              }
              let_res_2080 = let_res_2083;
            }
            let_res_2040 = let_res_2080;
          }
          choose_res_2018 = let_res_2040;
        } else {
          uint16_t id_2100 { uint16_t((*p_0).index()) };
          uint16_t id_2101 { 2 };
          bool id_2102 { bool(id_2100 == id_2101) };
          Void id_2103 { ((void)(assert(id_2102)), VOID) };
          (void)id_2103;
          ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2104 { std::get<2 /* ListenFor */>((*p_0)) };
          std::string id_2105 { id_2104.net_addr };
          uint32_t id_2106 { (uint32_t)id_2105.size() };
          Vec<1, uint32_t> id_2107 {  id_2106  };
          Pointer let_res_2108;
          {
            Vec<1, uint32_t> leb128_sz_871 { id_2107 };
            Vec<1, Pointer> id_2109 {  ssum_dst_870  };
            Pointer let_res_2110;
            {
              Vec<1, Pointer> leb128_ptr_872 { id_2109 };
              bool while_flag_2111 { true };
              do {
                uint8_t id_2112 { 0 };
                uint8_t id_2113 { 0 };
                Pointer id_2114 { leb128_ptr_872[id_2113] };
                uint32_t id_2115 { 128U };
                uint8_t id_2116 { 0 };
                uint32_t id_2117 { leb128_sz_871[id_2116] };
                bool id_2118 { bool(id_2115 > id_2117) };
                uint8_t choose_res_2119;
                if (id_2118) {
                  uint8_t id_2120 { 0 };
                  uint32_t id_2121 { leb128_sz_871[id_2120] };
                  uint8_t id_2122 { uint8_t(id_2121) };
                  choose_res_2119 = id_2122;
                } else {
                  uint8_t id_2123 { 0 };
                  uint32_t id_2124 { leb128_sz_871[id_2123] };
                  uint8_t id_2125 { uint8_t(id_2124) };
                  uint8_t id_2126 { 128 };
                  uint8_t id_2127 { uint8_t(id_2125 | id_2126) };
                  choose_res_2119 = id_2127;
                }
                Pointer id_2128 { id_2114.writeU8(choose_res_2119) };
                Void id_2129 { ((void)(leb128_ptr_872[id_2112] = id_2128), VOID) };
                (void)id_2129;
                uint8_t id_2130 { 0 };
                uint8_t id_2131 { 0 };
                uint32_t id_2132 { leb128_sz_871[id_2131] };
                uint8_t id_2133 { 7 };
                uint32_t id_2134 { uint32_t(id_2132 >> id_2133) };
                Void id_2135 { ((void)(leb128_sz_871[id_2130] = id_2134), VOID) };
                (void)id_2135;
                uint8_t id_2136 { 0 };
                uint32_t id_2137 { leb128_sz_871[id_2136] };
                uint32_t id_2138 { 0U };
                bool id_2139 { bool(id_2137 > id_2138) };
                while_flag_2111 = id_2139;
                if (while_flag_2111) {
                  (void)VOID;
                }
              } while (while_flag_2111);
              (void)VOID;
              uint8_t id_2140 { 0 };
              Pointer id_2141 { leb128_ptr_872[id_2140] };
              let_res_2110 = id_2141;
            }
            let_res_2108 = let_res_2110;
          }
          ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2142 { std::get<2 /* ListenFor */>((*p_0)) };
          std::string id_2143 { id_2142.net_addr };
          Bytes id_2144 { id_2143 };
          Pointer id_2145 { let_res_2108.writeBytes(id_2144) };
          Pointer let_res_2146;
          {
            Pointer srec_dst_873 { id_2145 };
            ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2147 { std::get<2 /* ListenFor */>((*p_0)) };
            uint16_t id_2148 { id_2147.port };
            Pointer id_2149 { srec_dst_873.writeU16Le(id_2148) };
            let_res_2146 = id_2149;
          }
          Pointer let_res_2150;
          {
            Pointer srec_dst_874 { let_res_2146 };
            auto fun2151 { dessser::gen::raql_net_protocol::to_row_binary };
            ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2152 { std::get<2 /* ListenFor */>((*p_0)) };
            dessser::gen::raql_net_protocol::t_ext id_2153 { id_2152.proto };
            Pointer id_2154 { fun2151(id_2153, srec_dst_874) };
            let_res_2150 = id_2154;
          }
          Pointer let_res_2155;
          {
            Pointer srec_dst_875 { let_res_2150 };
            ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2156 { std::get<2 /* ListenFor */>((*p_0)) };
            Lst<dessser::gen::field_name::t_ext> id_2157 { id_2156.factors };
            uint32_t id_2158 { id_2157.size() };
            Vec<1, uint32_t> id_2159 {  id_2158  };
            Pointer let_res_2160;
            {
              Vec<1, uint32_t> leb128_sz_876 { id_2159 };
              Vec<1, Pointer> id_2161 {  srec_dst_875  };
              Pointer let_res_2162;
              {
                Vec<1, Pointer> leb128_ptr_877 { id_2161 };
                bool while_flag_2163 { true };
                do {
                  uint8_t id_2164 { 0 };
                  uint8_t id_2165 { 0 };
                  Pointer id_2166 { leb128_ptr_877[id_2165] };
                  uint32_t id_2167 { 128U };
                  uint8_t id_2168 { 0 };
                  uint32_t id_2169 { leb128_sz_876[id_2168] };
                  bool id_2170 { bool(id_2167 > id_2169) };
                  uint8_t choose_res_2171;
                  if (id_2170) {
                    uint8_t id_2172 { 0 };
                    uint32_t id_2173 { leb128_sz_876[id_2172] };
                    uint8_t id_2174 { uint8_t(id_2173) };
                    choose_res_2171 = id_2174;
                  } else {
                    uint8_t id_2175 { 0 };
                    uint32_t id_2176 { leb128_sz_876[id_2175] };
                    uint8_t id_2177 { uint8_t(id_2176) };
                    uint8_t id_2178 { 128 };
                    uint8_t id_2179 { uint8_t(id_2177 | id_2178) };
                    choose_res_2171 = id_2179;
                  }
                  Pointer id_2180 { id_2166.writeU8(choose_res_2171) };
                  Void id_2181 { ((void)(leb128_ptr_877[id_2164] = id_2180), VOID) };
                  (void)id_2181;
                  uint8_t id_2182 { 0 };
                  uint8_t id_2183 { 0 };
                  uint32_t id_2184 { leb128_sz_876[id_2183] };
                  uint8_t id_2185 { 7 };
                  uint32_t id_2186 { uint32_t(id_2184 >> id_2185) };
                  Void id_2187 { ((void)(leb128_sz_876[id_2182] = id_2186), VOID) };
                  (void)id_2187;
                  uint8_t id_2188 { 0 };
                  uint32_t id_2189 { leb128_sz_876[id_2188] };
                  uint32_t id_2190 { 0U };
                  bool id_2191 { bool(id_2189 > id_2190) };
                  while_flag_2163 = id_2191;
                  if (while_flag_2163) {
                    (void)VOID;
                  }
                } while (while_flag_2163);
                (void)VOID;
                uint8_t id_2192 { 0 };
                Pointer id_2193 { leb128_ptr_877[id_2192] };
                let_res_2162 = id_2193;
              }
              let_res_2160 = let_res_2162;
            }
            Vec<1, Pointer> id_2194 {  let_res_2160  };
            Pointer let_res_2195;
            {
              Vec<1, Pointer> dst_ref_878 { id_2194 };
              int32_t id_2196 { 0L };
              Vec<1, int32_t> id_2197 {  id_2196  };
              Pointer let_res_2198;
              {
                Vec<1, int32_t> n_ref_879 { id_2197 };
                ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2199 { std::get<2 /* ListenFor */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2200 { id_2199.factors };
                for (dessser::gen::field_name::t_ext x_880 : id_2200) {
                  uint8_t id_2201 { 0 };
                  auto fun2202 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_2203 { 0 };
                  Pointer id_2204 { dst_ref_878[id_2203] };
                  Pointer id_2205 { fun2202(x_880, id_2204) };
                  Void id_2206 { ((void)(dst_ref_878[id_2201] = id_2205), VOID) };
                  (void)id_2206;
                  uint8_t id_2207 { 0 };
                  int32_t id_2208 { 1L };
                  uint8_t id_2209 { 0 };
                  int32_t id_2210 { n_ref_879[id_2209] };
                  int32_t id_2211 { int32_t(id_2208 + id_2210) };
                  Void id_2212 { ((void)(n_ref_879[id_2207] = id_2211), VOID) };
                  (void)id_2212;
                  (void)id_2212;
                }
                (void)VOID;
                uint8_t id_2213 { 0 };
                Pointer id_2214 { dst_ref_878[id_2213] };
                let_res_2198 = id_2214;
              }
              let_res_2195 = let_res_2198;
            }
            let_res_2155 = let_res_2195;
          }
          choose_res_2018 = let_res_2155;
        }
        choose_res_1501 = choose_res_2018;
      }
      let_res_1497 = choose_res_1501;
    }
    return let_res_1497;
  }
   };
  return fun1494;
}
std::function<Pointer(::dessser::gen::raql_operation::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_711"
          (let "sz_707"
            (if (eq (u16 0) (label-of (get-item 0 (get-alt "NamedOperation" (param 0))))) 
              (size 4)
              (if (eq (u16 1) (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))))
                (add (size 4)
                  (add
                    (let "n_ref_705" (make-vec (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0))))))
                      (let "lebsz_ref_706" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_705")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_706")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_706") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_706")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_706")))))) 
                    (size-of-u32 (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (param 0)))))))) 
                (seq (assert (eq (label-of (get-item 0 (get-alt "NamedOperation" (param 0)))) (u16 2))) (size 4))))
            (if (is-null (get-item 1 (get-alt "NamedOperation" (param 0)))) 
              (add (identifier "sz_707") (size 1))
              (add
                (add (identifier "sz_707")
                  (add
                    (let "n_ref_709" (make-vec (string-length (force (get-item 1 (get-alt "NamedOperation" (param 0))))))
                      (let "lebsz_ref_710" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_709")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_710")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_710") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_710")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_710")))))) 
                    (size-of-u32 (string-length (force (get-item 1 (get-alt "NamedOperation" (param 0)))))))) 
                (size 1)))) (add (identifier "sz_711") (apply (ext-identifier function_name sersize-of-row-binary) (get-item 2 (get-alt "NamedOperation" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "sersize-of-row-binary") (get-alt "SubQuery" (param 0)))))))
 */
static std::function<Size(::dessser::gen::raql_operation::data_source*)> data_source_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_operation::data_source*)> fun2215 { [&fun2215](::dessser::gen::raql_operation::data_source* p_0) {
    uint16_t id_2216 { 0 };
    uint16_t id_2217 { uint16_t((*p_0).index()) };
    bool id_2218 { bool(id_2216 == id_2217) };
    Size choose_res_2219;
    if (id_2218) {
      uint16_t id_2220 { 0 };
      ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_2221 { std::get<0 /* NamedOperation */>((*p_0)) };
      ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_2222 { std::get<0>(id_2221) };
      uint16_t id_2223 { uint16_t(id_2222.index()) };
      bool id_2224 { bool(id_2220 == id_2223) };
      Size choose_res_2225;
      if (id_2224) {
        Size id_2226 { 4UL };
        choose_res_2225 = id_2226;
      } else {
        uint16_t id_2227 { 1 };
        ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_2228 { std::get<0 /* NamedOperation */>((*p_0)) };
        ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_2229 { std::get<0>(id_2228) };
        uint16_t id_2230 { uint16_t(id_2229.index()) };
        bool id_2231 { bool(id_2227 == id_2230) };
        Size choose_res_2232;
        if (id_2231) {
          Size id_2233 { 4UL };
          ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_2234 { std::get<0 /* NamedOperation */>((*p_0)) };
          ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_2235 { std::get<0>(id_2234) };
          std::string id_2236 { std::get<1 /* TheseSites */>(id_2235) };
          uint32_t id_2237 { (uint32_t)id_2236.size() };
          Vec<1, uint32_t> id_2238 {  id_2237  };
          Size let_res_2239;
          {
            Vec<1, uint32_t> n_ref_705 { id_2238 };
            uint32_t id_2240 { 1U };
            Vec<1, uint32_t> id_2241 {  id_2240  };
            Size let_res_2242;
            {
              Vec<1, uint32_t> lebsz_ref_706 { id_2241 };
              bool while_flag_2243 { true };
              do {
                uint8_t id_2244 { 0 };
                uint32_t id_2245 { n_ref_705[id_2244] };
                uint8_t id_2246 { 0 };
                uint32_t id_2247 { lebsz_ref_706[id_2246] };
                uint8_t id_2248 { 7 };
                uint32_t id_2249 { uint32_t(id_2247 << id_2248) };
                bool id_2250 { bool(id_2245 >= id_2249) };
                while_flag_2243 = id_2250;
                if (while_flag_2243) {
                  uint8_t id_2251 { 0 };
                  uint8_t id_2252 { 0 };
                  uint32_t id_2253 { lebsz_ref_706[id_2252] };
                  uint32_t id_2254 { 1U };
                  uint32_t id_2255 { uint32_t(id_2253 + id_2254) };
                  Void id_2256 { ((void)(lebsz_ref_706[id_2251] = id_2255), VOID) };
                  (void)id_2256;
                }
              } while (while_flag_2243);
              (void)VOID;
              uint8_t id_2257 { 0 };
              uint32_t id_2258 { lebsz_ref_706[id_2257] };
              Size id_2259 { Size(id_2258) };
              let_res_2242 = id_2259;
            }
            let_res_2239 = let_res_2242;
          }
          ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_2260 { std::get<0 /* NamedOperation */>((*p_0)) };
          ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_2261 { std::get<0>(id_2260) };
          std::string id_2262 { std::get<1 /* TheseSites */>(id_2261) };
          uint32_t id_2263 { (uint32_t)id_2262.size() };
          Size id_2264 { Size(id_2263) };
          Size id_2265 { Size(let_res_2239 + id_2264) };
          Size id_2266 { Size(id_2233 + id_2265) };
          choose_res_2232 = id_2266;
        } else {
          ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_2267 { std::get<0 /* NamedOperation */>((*p_0)) };
          ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_2268 { std::get<0>(id_2267) };
          uint16_t id_2269 { uint16_t(id_2268.index()) };
          uint16_t id_2270 { 2 };
          bool id_2271 { bool(id_2269 == id_2270) };
          Void id_2272 { ((void)(assert(id_2271)), VOID) };
          (void)id_2272;
          Size id_2273 { 4UL };
          choose_res_2232 = id_2273;
        }
        choose_res_2225 = choose_res_2232;
      }
      Size let_res_2274;
      {
        Size sz_707 { choose_res_2225 };
        ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_2275 { std::get<0 /* NamedOperation */>((*p_0)) };
        std::optional<std::string> id_2276 { std::get<1>(id_2275) };
        bool id_2277 { !(id_2276.has_value ()) };
        Size choose_res_2278;
        if (id_2277) {
          Size id_2279 { 1UL };
          Size id_2280 { Size(sz_707 + id_2279) };
          choose_res_2278 = id_2280;
        } else {
          ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_2281 { std::get<0 /* NamedOperation */>((*p_0)) };
          std::optional<std::string> id_2282 { std::get<1>(id_2281) };
          std::string id_2283 { id_2282.value() };
          uint32_t id_2284 { (uint32_t)id_2283.size() };
          Vec<1, uint32_t> id_2285 {  id_2284  };
          Size let_res_2286;
          {
            Vec<1, uint32_t> n_ref_709 { id_2285 };
            uint32_t id_2287 { 1U };
            Vec<1, uint32_t> id_2288 {  id_2287  };
            Size let_res_2289;
            {
              Vec<1, uint32_t> lebsz_ref_710 { id_2288 };
              bool while_flag_2290 { true };
              do {
                uint8_t id_2291 { 0 };
                uint32_t id_2292 { n_ref_709[id_2291] };
                uint8_t id_2293 { 0 };
                uint32_t id_2294 { lebsz_ref_710[id_2293] };
                uint8_t id_2295 { 7 };
                uint32_t id_2296 { uint32_t(id_2294 << id_2295) };
                bool id_2297 { bool(id_2292 >= id_2296) };
                while_flag_2290 = id_2297;
                if (while_flag_2290) {
                  uint8_t id_2298 { 0 };
                  uint8_t id_2299 { 0 };
                  uint32_t id_2300 { lebsz_ref_710[id_2299] };
                  uint32_t id_2301 { 1U };
                  uint32_t id_2302 { uint32_t(id_2300 + id_2301) };
                  Void id_2303 { ((void)(lebsz_ref_710[id_2298] = id_2302), VOID) };
                  (void)id_2303;
                }
              } while (while_flag_2290);
              (void)VOID;
              uint8_t id_2304 { 0 };
              uint32_t id_2305 { lebsz_ref_710[id_2304] };
              Size id_2306 { Size(id_2305) };
              let_res_2289 = id_2306;
            }
            let_res_2286 = let_res_2289;
          }
          ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_2307 { std::get<0 /* NamedOperation */>((*p_0)) };
          std::optional<std::string> id_2308 { std::get<1>(id_2307) };
          std::string id_2309 { id_2308.value() };
          uint32_t id_2310 { (uint32_t)id_2309.size() };
          Size id_2311 { Size(id_2310) };
          Size id_2312 { Size(let_res_2286 + id_2311) };
          Size id_2313 { Size(sz_707 + id_2312) };
          Size id_2314 { 1UL };
          Size id_2315 { Size(id_2313 + id_2314) };
          choose_res_2278 = id_2315;
        }
        let_res_2274 = choose_res_2278;
      }
      Size let_res_2316;
      {
        Size sz_711 { let_res_2274 };
        auto fun2317 { dessser::gen::function_name::sersize_of_row_binary };
        ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_2318 { std::get<0 /* NamedOperation */>((*p_0)) };
        dessser::gen::function_name::t_ext id_2319 { std::get<2>(id_2318) };
        Size id_2320 { fun2317(id_2319) };
        Size id_2321 { Size(sz_711 + id_2320) };
        let_res_2316 = id_2321;
      }
      choose_res_2219 = let_res_2316;
    } else {
      uint16_t id_2322 { uint16_t((*p_0).index()) };
      uint16_t id_2323 { 1 };
      bool id_2324 { bool(id_2322 == id_2323) };
      Void id_2325 { ((void)(assert(id_2324)), VOID) };
      (void)id_2325;
      Size id_2326 { 2UL };
      t* id_2327 { std::get<1 /* SubQuery */>((*p_0)) };
      Size id_2328 { sersize_of_row_binary(id_2327) };
      Size id_2329 { Size(id_2326 + id_2328) };
      choose_res_2219 = id_2329;
    }
    return choose_res_2219;
  }
   };
  return fun2215;
}
std::function<Size(::dessser::gen::raql_operation::data_source*)> data_source_sersize_of_row_binary(data_source_sersize_of_row_binary_init());

/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_813"
          (let "sz_812"
            (let "sz_807"
              (let "sz_806"
                (add
                  (let "sz_804"
                    (let "sz_799"
                      (let "sz_794"
                        (let "sz_793"
                          (let "sz_792"
                            (let "sz_784"
                              (let "sz_779"
                                (let "sz_ref_777"
                                  (make-vec
                                    (add (size 2)
                                      (let "n_ref_775" (make-vec (cardinality (get-field "fields" (get-alt "Aggregate" (param 0)))))
                                        (let "lebsz_ref_776" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_775")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_776")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_776") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_776")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_776"))))))))
                                  (seq
                                    (let "repeat_n_778" (make-vec (i32 0))
                                      (while (gt (to-i32 (cardinality (get-field "fields" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_778")))
                                        (seq
                                          (set-vec (u8 0) (identifier "sz_ref_777")
                                            (add (unsafe-nth (u8 0) (identifier "sz_ref_777"))
                                              (apply (ext-identifier raql_select_field sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_778")) (get-field "fields" (get-alt "Aggregate" (param 0)))))))
                                          (set-vec (u8 0) (identifier "repeat_n_778") (add (unsafe-nth (u8 0) (identifier "repeat_n_778")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "sz_ref_777"))))
                                (if (is-null (get-field "and_all_others" (get-alt "Aggregate" (param 0)))) 
                                  (add (identifier "sz_779") (size 1))
                                  (add
                                    (let "sz_ref_782"
                                      (make-vec
                                        (add (identifier "sz_779")
                                          (let "n_ref_780" (make-vec (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))
                                            (let "lebsz_ref_781" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_780")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_781")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_781") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_781")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_781"))))))))
                                      (seq
                                        (let "repeat_n_783" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_783")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_782")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_782"))
                                                  (apply (ext-identifier field_name sersize-of-row-binary)
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_783")) (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))))
                                              (set-vec (u8 0) (identifier "repeat_n_783") (add (unsafe-nth (u8 0) (identifier "repeat_n_783")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_782")))) 
                                    (size 1))))
                              (if (is-null (get-field "sort" (get-alt "Aggregate" (param 0)))) 
                                (add (identifier "sz_784") (size 1))
                                (add
                                  (let "sz_787"
                                    (if (is-null (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) 
                                      (add (add (identifier "sz_784") (size 4)) (size 1))
                                      (add (add (add (identifier "sz_784") (size 4)) (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0))))))))
                                        (size 1)))
                                    (let "sz_ref_790"
                                      (make-vec
                                        (add (identifier "sz_787")
                                          (let "n_ref_788" (make-vec (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                            (let "lebsz_ref_789" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_788")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_789")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_789") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_789")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_789"))))))))
                                      (seq
                                        (let "repeat_n_791" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0))))))) (unsafe-nth (u8 0) (identifier "repeat_n_791")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_790")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_790"))
                                                  (apply (ext-identifier raql_expr sersize-of-row-binary)
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_791")) (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))))
                                              (set-vec (u8 0) (identifier "repeat_n_791") (add (unsafe-nth (u8 0) (identifier "repeat_n_791")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_790"))))) 
                                  (size 1)))) (add (identifier "sz_792") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "where" (get-alt "Aggregate" (param 0))))))
                          (if (is-null (get-field "event_time" (get-alt "Aggregate" (param 0)))) 
                            (add (identifier "sz_793") (size 1))
                            (add (add (identifier "sz_793") (apply (ext-identifier event_time sersize-of-row-binary) (force (get-field "event_time" (get-alt "Aggregate" (param 0)))))) (size 1))))
                        (let "sz_ref_797"
                          (make-vec
                            (add (identifier "sz_794")
                              (let "n_ref_795" (make-vec (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0)))))
                                (let "lebsz_ref_796" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_795")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_796")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_796") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_796")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_796"))))))))
                          (seq
                            (let "repeat_n_798" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_798")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_797")
                                    (add (unsafe-nth (u8 0) (identifier "sz_ref_797"))
                                      (apply (ext-identifier raql_expr sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_798")) (get-field "notifications" (get-alt "Aggregate" (param 0)))))))
                                  (set-vec (u8 0) (identifier "repeat_n_798") (add (unsafe-nth (u8 0) (identifier "repeat_n_798")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_797")))))
                      (let "sz_ref_802"
                        (make-vec
                          (add (identifier "sz_799")
                            (let "n_ref_800" (make-vec (cardinality (get-field "key" (get-alt "Aggregate" (param 0)))))
                              (let "lebsz_ref_801" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_800")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_801")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_801") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_801")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_801"))))))))
                        (seq
                          (let "repeat_n_803" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-field "key" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_803")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_802")
                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_802"))
                                    (apply (ext-identifier raql_expr sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_803")) (get-field "key" (get-alt "Aggregate" (param 0)))))))
                                (set-vec (u8 0) (identifier "repeat_n_803") (add (unsafe-nth (u8 0) (identifier "repeat_n_803")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_802"))))) 
                    (add (identifier "sz_804") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "commit_cond" (get-alt "Aggregate" (param 0)))))) 
                  (size 1)) (add (identifier "sz_806") (apply (ext-identifier raql_flush_method sersize-of-row-binary) (get-field "flush_how" (get-alt "Aggregate" (param 0))))))
              (let "sz_ref_810"
                (make-vec
                  (add (identifier "sz_807")
                    (let "n_ref_808" (make-vec (cardinality (get-field "from" (get-alt "Aggregate" (param 0)))))
                      (let "lebsz_ref_809" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_808")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_809")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_809") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_809")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_809"))))))))
                (seq
                  (let "repeat_n_811" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "from" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_811")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_810")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_810"))
                            (apply (identifier "data_source-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_811")) (get-field "from" (get-alt "Aggregate" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_811") (add (unsafe-nth (u8 0) (identifier "repeat_n_811")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_810")))))
            (if (is-null (get-field "every" (get-alt "Aggregate" (param 0)))) 
              (add (identifier "sz_812") (size 1)) (add (add (identifier "sz_812") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "every" (get-alt "Aggregate" (param 0)))))) (size 1))))
          (let "sz_ref_816"
            (make-vec
              (add (identifier "sz_813")
                (let "n_ref_814" (make-vec (cardinality (get-field "factors" (get-alt "Aggregate" (param 0)))))
                  (let "lebsz_ref_815" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_814")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_815")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_815") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_815")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_815"))))))))
            (seq
              (let "repeat_n_817" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_817")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_816")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_816"))
                        (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_817")) (get-field "factors" (get-alt "Aggregate" (param 0)))))))
                    (set-vec (u8 0) (identifier "repeat_n_817") (add (unsafe-nth (u8 0) (identifier "repeat_n_817")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_816")))))
        (if (eq (u16 1) (label-of (param 0)))
          (let "sz_769"
            (let "sz_768"
              (let "sz_767" (add (size 2) (apply (identifier "external_source-sersize-of-row-binary") (get-field "source" (get-alt "ReadExternal" (param 0)))))
                (add (identifier "sz_767") (apply (identifier "external_format-sersize-of-row-binary") (get-field "format" (get-alt "ReadExternal" (param 0))))))
              (if (is-null (get-field "event_time" (get-alt "ReadExternal" (param 0)))) 
                (add (identifier "sz_768") (size 1)) (add (add (identifier "sz_768") (apply (ext-identifier event_time sersize-of-row-binary) (force (get-field "event_time" (get-alt "ReadExternal" (param 0)))))) (size 1))))
            (let "sz_ref_772"
              (make-vec
                (add (identifier "sz_769")
                  (let "n_ref_770" (make-vec (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0)))))
                    (let "lebsz_ref_771" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_770")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_771")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_771") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_771")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_771"))))))))
              (seq
                (let "repeat_n_773" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_773")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_772")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_772"))
                          (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_773")) (get-field "factors" (get-alt "ReadExternal" (param 0)))))))
                      (set-vec (u8 0) (identifier "repeat_n_773") (add (unsafe-nth (u8 0) (identifier "repeat_n_773")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_772")))))
          (seq (assert (eq (label-of (param 0)) (u16 2)))
            (let "sz_761"
              (let "sz_760"
                (add
                  (add (size 2)
                    (add
                      (let "n_ref_757" (make-vec (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0)))))
                        (let "lebsz_ref_758" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_757")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_758")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_758") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_758")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_758")))))) 
                      (size-of-u32 (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0))))))) 
                  (size 2)) (add (identifier "sz_760") (apply (ext-identifier raql_net_protocol sersize-of-row-binary) (get-field "proto" (get-alt "ListenFor" (param 0))))))
              (let "sz_ref_764"
                (make-vec
                  (add (identifier "sz_761")
                    (let "n_ref_762" (make-vec (cardinality (get-field "factors" (get-alt "ListenFor" (param 0)))))
                      (let "lebsz_ref_763" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_762")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_763")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_763") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_763")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_763"))))))))
                (seq
                  (let "repeat_n_765" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "ListenFor" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_765")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_764")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_764"))
                            (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_765")) (get-field "factors" (get-alt "ListenFor" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_765") (add (unsafe-nth (u8 0) (identifier "repeat_n_765")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_764")))))))))
 */
static std::function<Size(::dessser::gen::raql_operation::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_operation::t*)> fun2330 { [&fun2330](::dessser::gen::raql_operation::t* p_0) {
    uint16_t id_2331 { 0 };
    uint16_t id_2332 { uint16_t((*p_0).index()) };
    bool id_2333 { bool(id_2331 == id_2332) };
    Size choose_res_2334;
    if (id_2333) {
      Size id_2335 { 2UL };
      ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2336 { std::get<0 /* Aggregate */>((*p_0)) };
      Lst<dessser::gen::raql_select_field::t_ext> id_2337 { id_2336.Aggregate_fields };
      uint32_t id_2338 { id_2337.size() };
      Vec<1, uint32_t> id_2339 {  id_2338  };
      Size let_res_2340;
      {
        Vec<1, uint32_t> n_ref_775 { id_2339 };
        uint32_t id_2341 { 1U };
        Vec<1, uint32_t> id_2342 {  id_2341  };
        Size let_res_2343;
        {
          Vec<1, uint32_t> lebsz_ref_776 { id_2342 };
          bool while_flag_2344 { true };
          do {
            uint8_t id_2345 { 0 };
            uint32_t id_2346 { n_ref_775[id_2345] };
            uint8_t id_2347 { 0 };
            uint32_t id_2348 { lebsz_ref_776[id_2347] };
            uint8_t id_2349 { 7 };
            uint32_t id_2350 { uint32_t(id_2348 << id_2349) };
            bool id_2351 { bool(id_2346 >= id_2350) };
            while_flag_2344 = id_2351;
            if (while_flag_2344) {
              uint8_t id_2352 { 0 };
              uint8_t id_2353 { 0 };
              uint32_t id_2354 { lebsz_ref_776[id_2353] };
              uint32_t id_2355 { 1U };
              uint32_t id_2356 { uint32_t(id_2354 + id_2355) };
              Void id_2357 { ((void)(lebsz_ref_776[id_2352] = id_2356), VOID) };
              (void)id_2357;
            }
          } while (while_flag_2344);
          (void)VOID;
          uint8_t id_2358 { 0 };
          uint32_t id_2359 { lebsz_ref_776[id_2358] };
          Size id_2360 { Size(id_2359) };
          let_res_2343 = id_2360;
        }
        let_res_2340 = let_res_2343;
      }
      Size id_2361 { Size(id_2335 + let_res_2340) };
      Vec<1, Size> id_2362 {  id_2361  };
      Size let_res_2363;
      {
        Vec<1, Size> sz_ref_777 { id_2362 };
        int32_t id_2364 { 0L };
        Vec<1, int32_t> id_2365 {  id_2364  };
        {
          Vec<1, int32_t> repeat_n_778 { id_2365 };
          bool while_flag_2366 { true };
          do {
            ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2367 { std::get<0 /* Aggregate */>((*p_0)) };
            Lst<dessser::gen::raql_select_field::t_ext> id_2368 { id_2367.Aggregate_fields };
            uint32_t id_2369 { id_2368.size() };
            int32_t id_2370 { int32_t(id_2369) };
            uint8_t id_2371 { 0 };
            int32_t id_2372 { repeat_n_778[id_2371] };
            bool id_2373 { bool(id_2370 > id_2372) };
            while_flag_2366 = id_2373;
            if (while_flag_2366) {
              uint8_t id_2374 { 0 };
              uint8_t id_2375 { 0 };
              Size id_2376 { sz_ref_777[id_2375] };
              auto fun2377 { dessser::gen::raql_select_field::sersize_of_row_binary };
              uint8_t id_2378 { 0 };
              int32_t id_2379 { repeat_n_778[id_2378] };
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2380 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_select_field::t_ext> id_2381 { id_2380.Aggregate_fields };
              dessser::gen::raql_select_field::t_ext id_2382 { id_2381[id_2379] };
              Size id_2383 { fun2377(id_2382) };
              Size id_2384 { Size(id_2376 + id_2383) };
              Void id_2385 { ((void)(sz_ref_777[id_2374] = id_2384), VOID) };
              (void)id_2385;
              uint8_t id_2386 { 0 };
              uint8_t id_2387 { 0 };
              int32_t id_2388 { repeat_n_778[id_2387] };
              int32_t id_2389 { 1L };
              int32_t id_2390 { int32_t(id_2388 + id_2389) };
              Void id_2391 { ((void)(repeat_n_778[id_2386] = id_2390), VOID) };
              (void)id_2391;
              (void)id_2391;
            }
          } while (while_flag_2366);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_2392 { 0 };
        Size id_2393 { sz_ref_777[id_2392] };
        let_res_2363 = id_2393;
      }
      Size let_res_2394;
      {
        Size sz_779 { let_res_2363 };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2395 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<Lst<dessser::gen::field_name::t_ext>> id_2396 { id_2395.and_all_others };
        bool id_2397 { !(id_2396.has_value ()) };
        Size choose_res_2398;
        if (id_2397) {
          Size id_2399 { 1UL };
          Size id_2400 { Size(sz_779 + id_2399) };
          choose_res_2398 = id_2400;
        } else {
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2401 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<Lst<dessser::gen::field_name::t_ext>> id_2402 { id_2401.and_all_others };
          Lst<dessser::gen::field_name::t_ext> id_2403 { id_2402.value() };
          uint32_t id_2404 { id_2403.size() };
          Vec<1, uint32_t> id_2405 {  id_2404  };
          Size let_res_2406;
          {
            Vec<1, uint32_t> n_ref_780 { id_2405 };
            uint32_t id_2407 { 1U };
            Vec<1, uint32_t> id_2408 {  id_2407  };
            Size let_res_2409;
            {
              Vec<1, uint32_t> lebsz_ref_781 { id_2408 };
              bool while_flag_2410 { true };
              do {
                uint8_t id_2411 { 0 };
                uint32_t id_2412 { n_ref_780[id_2411] };
                uint8_t id_2413 { 0 };
                uint32_t id_2414 { lebsz_ref_781[id_2413] };
                uint8_t id_2415 { 7 };
                uint32_t id_2416 { uint32_t(id_2414 << id_2415) };
                bool id_2417 { bool(id_2412 >= id_2416) };
                while_flag_2410 = id_2417;
                if (while_flag_2410) {
                  uint8_t id_2418 { 0 };
                  uint8_t id_2419 { 0 };
                  uint32_t id_2420 { lebsz_ref_781[id_2419] };
                  uint32_t id_2421 { 1U };
                  uint32_t id_2422 { uint32_t(id_2420 + id_2421) };
                  Void id_2423 { ((void)(lebsz_ref_781[id_2418] = id_2422), VOID) };
                  (void)id_2423;
                }
              } while (while_flag_2410);
              (void)VOID;
              uint8_t id_2424 { 0 };
              uint32_t id_2425 { lebsz_ref_781[id_2424] };
              Size id_2426 { Size(id_2425) };
              let_res_2409 = id_2426;
            }
            let_res_2406 = let_res_2409;
          }
          Size id_2427 { Size(sz_779 + let_res_2406) };
          Vec<1, Size> id_2428 {  id_2427  };
          Size let_res_2429;
          {
            Vec<1, Size> sz_ref_782 { id_2428 };
            int32_t id_2430 { 0L };
            Vec<1, int32_t> id_2431 {  id_2430  };
            {
              Vec<1, int32_t> repeat_n_783 { id_2431 };
              bool while_flag_2432 { true };
              do {
                ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2433 { std::get<0 /* Aggregate */>((*p_0)) };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_2434 { id_2433.and_all_others };
                Lst<dessser::gen::field_name::t_ext> id_2435 { id_2434.value() };
                uint32_t id_2436 { id_2435.size() };
                int32_t id_2437 { int32_t(id_2436) };
                uint8_t id_2438 { 0 };
                int32_t id_2439 { repeat_n_783[id_2438] };
                bool id_2440 { bool(id_2437 > id_2439) };
                while_flag_2432 = id_2440;
                if (while_flag_2432) {
                  uint8_t id_2441 { 0 };
                  uint8_t id_2442 { 0 };
                  Size id_2443 { sz_ref_782[id_2442] };
                  auto fun2444 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_2445 { 0 };
                  int32_t id_2446 { repeat_n_783[id_2445] };
                  ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2447 { std::get<0 /* Aggregate */>((*p_0)) };
                  std::optional<Lst<dessser::gen::field_name::t_ext>> id_2448 { id_2447.and_all_others };
                  Lst<dessser::gen::field_name::t_ext> id_2449 { id_2448.value() };
                  dessser::gen::field_name::t_ext id_2450 { id_2449[id_2446] };
                  Size id_2451 { fun2444(id_2450) };
                  Size id_2452 { Size(id_2443 + id_2451) };
                  Void id_2453 { ((void)(sz_ref_782[id_2441] = id_2452), VOID) };
                  (void)id_2453;
                  uint8_t id_2454 { 0 };
                  uint8_t id_2455 { 0 };
                  int32_t id_2456 { repeat_n_783[id_2455] };
                  int32_t id_2457 { 1L };
                  int32_t id_2458 { int32_t(id_2456 + id_2457) };
                  Void id_2459 { ((void)(repeat_n_783[id_2454] = id_2458), VOID) };
                  (void)id_2459;
                  (void)id_2459;
                }
              } while (while_flag_2432);
              (void)VOID;
            }
            (void)VOID;
            uint8_t id_2460 { 0 };
            Size id_2461 { sz_ref_782[id_2460] };
            let_res_2429 = id_2461;
          }
          Size id_2462 { 1UL };
          Size id_2463 { Size(let_res_2429 + id_2462) };
          choose_res_2398 = id_2463;
        }
        let_res_2394 = choose_res_2398;
      }
      Size let_res_2464;
      {
        Size sz_784 { let_res_2394 };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2465 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_2466 { id_2465.sort };
        bool id_2467 { !(id_2466.has_value ()) };
        Size choose_res_2468;
        if (id_2467) {
          Size id_2469 { 1UL };
          Size id_2470 { Size(sz_784 + id_2469) };
          choose_res_2468 = id_2470;
        } else {
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2471 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_2472 { id_2471.sort };
          ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_2473 { id_2472.value() };
          std::optional<dessser::gen::raql_expr::t_ext> id_2474 { std::get<1>(id_2473) };
          bool id_2475 { !(id_2474.has_value ()) };
          Size choose_res_2476;
          if (id_2475) {
            Size id_2477 { 4UL };
            Size id_2478 { Size(sz_784 + id_2477) };
            Size id_2479 { 1UL };
            Size id_2480 { Size(id_2478 + id_2479) };
            choose_res_2476 = id_2480;
          } else {
            Size id_2481 { 4UL };
            Size id_2482 { Size(sz_784 + id_2481) };
            auto fun2483 { dessser::gen::raql_expr::sersize_of_row_binary };
            ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2484 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_2485 { id_2484.sort };
            ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_2486 { id_2485.value() };
            std::optional<dessser::gen::raql_expr::t_ext> id_2487 { std::get<1>(id_2486) };
            dessser::gen::raql_expr::t_ext id_2488 { id_2487.value() };
            Size id_2489 { fun2483(id_2488) };
            Size id_2490 { Size(id_2482 + id_2489) };
            Size id_2491 { 1UL };
            Size id_2492 { Size(id_2490 + id_2491) };
            choose_res_2476 = id_2492;
          }
          Size let_res_2493;
          {
            Size sz_787 { choose_res_2476 };
            ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2494 { std::get<0 /* Aggregate */>((*p_0)) };
            std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_2495 { id_2494.sort };
            ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_2496 { id_2495.value() };
            Lst<dessser::gen::raql_expr::t_ext> id_2497 { std::get<2>(id_2496) };
            uint32_t id_2498 { id_2497.size() };
            Vec<1, uint32_t> id_2499 {  id_2498  };
            Size let_res_2500;
            {
              Vec<1, uint32_t> n_ref_788 { id_2499 };
              uint32_t id_2501 { 1U };
              Vec<1, uint32_t> id_2502 {  id_2501  };
              Size let_res_2503;
              {
                Vec<1, uint32_t> lebsz_ref_789 { id_2502 };
                bool while_flag_2504 { true };
                do {
                  uint8_t id_2505 { 0 };
                  uint32_t id_2506 { n_ref_788[id_2505] };
                  uint8_t id_2507 { 0 };
                  uint32_t id_2508 { lebsz_ref_789[id_2507] };
                  uint8_t id_2509 { 7 };
                  uint32_t id_2510 { uint32_t(id_2508 << id_2509) };
                  bool id_2511 { bool(id_2506 >= id_2510) };
                  while_flag_2504 = id_2511;
                  if (while_flag_2504) {
                    uint8_t id_2512 { 0 };
                    uint8_t id_2513 { 0 };
                    uint32_t id_2514 { lebsz_ref_789[id_2513] };
                    uint32_t id_2515 { 1U };
                    uint32_t id_2516 { uint32_t(id_2514 + id_2515) };
                    Void id_2517 { ((void)(lebsz_ref_789[id_2512] = id_2516), VOID) };
                    (void)id_2517;
                  }
                } while (while_flag_2504);
                (void)VOID;
                uint8_t id_2518 { 0 };
                uint32_t id_2519 { lebsz_ref_789[id_2518] };
                Size id_2520 { Size(id_2519) };
                let_res_2503 = id_2520;
              }
              let_res_2500 = let_res_2503;
            }
            Size id_2521 { Size(sz_787 + let_res_2500) };
            Vec<1, Size> id_2522 {  id_2521  };
            Size let_res_2523;
            {
              Vec<1, Size> sz_ref_790 { id_2522 };
              int32_t id_2524 { 0L };
              Vec<1, int32_t> id_2525 {  id_2524  };
              {
                Vec<1, int32_t> repeat_n_791 { id_2525 };
                bool while_flag_2526 { true };
                do {
                  ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2527 { std::get<0 /* Aggregate */>((*p_0)) };
                  std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_2528 { id_2527.sort };
                  ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_2529 { id_2528.value() };
                  Lst<dessser::gen::raql_expr::t_ext> id_2530 { std::get<2>(id_2529) };
                  uint32_t id_2531 { id_2530.size() };
                  int32_t id_2532 { int32_t(id_2531) };
                  uint8_t id_2533 { 0 };
                  int32_t id_2534 { repeat_n_791[id_2533] };
                  bool id_2535 { bool(id_2532 > id_2534) };
                  while_flag_2526 = id_2535;
                  if (while_flag_2526) {
                    uint8_t id_2536 { 0 };
                    uint8_t id_2537 { 0 };
                    Size id_2538 { sz_ref_790[id_2537] };
                    auto fun2539 { dessser::gen::raql_expr::sersize_of_row_binary };
                    uint8_t id_2540 { 0 };
                    int32_t id_2541 { repeat_n_791[id_2540] };
                    ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2542 { std::get<0 /* Aggregate */>((*p_0)) };
                    std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_2543 { id_2542.sort };
                    ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_2544 { id_2543.value() };
                    Lst<dessser::gen::raql_expr::t_ext> id_2545 { std::get<2>(id_2544) };
                    dessser::gen::raql_expr::t_ext id_2546 { id_2545[id_2541] };
                    Size id_2547 { fun2539(id_2546) };
                    Size id_2548 { Size(id_2538 + id_2547) };
                    Void id_2549 { ((void)(sz_ref_790[id_2536] = id_2548), VOID) };
                    (void)id_2549;
                    uint8_t id_2550 { 0 };
                    uint8_t id_2551 { 0 };
                    int32_t id_2552 { repeat_n_791[id_2551] };
                    int32_t id_2553 { 1L };
                    int32_t id_2554 { int32_t(id_2552 + id_2553) };
                    Void id_2555 { ((void)(repeat_n_791[id_2550] = id_2554), VOID) };
                    (void)id_2555;
                    (void)id_2555;
                  }
                } while (while_flag_2526);
                (void)VOID;
              }
              (void)VOID;
              uint8_t id_2556 { 0 };
              Size id_2557 { sz_ref_790[id_2556] };
              let_res_2523 = id_2557;
            }
            let_res_2493 = let_res_2523;
          }
          Size id_2558 { 1UL };
          Size id_2559 { Size(let_res_2493 + id_2558) };
          choose_res_2468 = id_2559;
        }
        let_res_2464 = choose_res_2468;
      }
      Size let_res_2560;
      {
        Size sz_792 { let_res_2464 };
        auto fun2561 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2562 { std::get<0 /* Aggregate */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_2563 { id_2562.where };
        Size id_2564 { fun2561(id_2563) };
        Size id_2565 { Size(sz_792 + id_2564) };
        let_res_2560 = id_2565;
      }
      Size let_res_2566;
      {
        Size sz_793 { let_res_2560 };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2567 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<dessser::gen::event_time::t_ext> id_2568 { id_2567.Aggregate_event_time };
        bool id_2569 { !(id_2568.has_value ()) };
        Size choose_res_2570;
        if (id_2569) {
          Size id_2571 { 1UL };
          Size id_2572 { Size(sz_793 + id_2571) };
          choose_res_2570 = id_2572;
        } else {
          auto fun2573 { dessser::gen::event_time::sersize_of_row_binary };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2574 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::event_time::t_ext> id_2575 { id_2574.Aggregate_event_time };
          dessser::gen::event_time::t_ext id_2576 { id_2575.value() };
          Size id_2577 { fun2573(id_2576) };
          Size id_2578 { Size(sz_793 + id_2577) };
          Size id_2579 { 1UL };
          Size id_2580 { Size(id_2578 + id_2579) };
          choose_res_2570 = id_2580;
        }
        let_res_2566 = choose_res_2570;
      }
      Size let_res_2581;
      {
        Size sz_794 { let_res_2566 };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2582 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::raql_expr::t_ext> id_2583 { id_2582.notifications };
        uint32_t id_2584 { id_2583.size() };
        Vec<1, uint32_t> id_2585 {  id_2584  };
        Size let_res_2586;
        {
          Vec<1, uint32_t> n_ref_795 { id_2585 };
          uint32_t id_2587 { 1U };
          Vec<1, uint32_t> id_2588 {  id_2587  };
          Size let_res_2589;
          {
            Vec<1, uint32_t> lebsz_ref_796 { id_2588 };
            bool while_flag_2590 { true };
            do {
              uint8_t id_2591 { 0 };
              uint32_t id_2592 { n_ref_795[id_2591] };
              uint8_t id_2593 { 0 };
              uint32_t id_2594 { lebsz_ref_796[id_2593] };
              uint8_t id_2595 { 7 };
              uint32_t id_2596 { uint32_t(id_2594 << id_2595) };
              bool id_2597 { bool(id_2592 >= id_2596) };
              while_flag_2590 = id_2597;
              if (while_flag_2590) {
                uint8_t id_2598 { 0 };
                uint8_t id_2599 { 0 };
                uint32_t id_2600 { lebsz_ref_796[id_2599] };
                uint32_t id_2601 { 1U };
                uint32_t id_2602 { uint32_t(id_2600 + id_2601) };
                Void id_2603 { ((void)(lebsz_ref_796[id_2598] = id_2602), VOID) };
                (void)id_2603;
              }
            } while (while_flag_2590);
            (void)VOID;
            uint8_t id_2604 { 0 };
            uint32_t id_2605 { lebsz_ref_796[id_2604] };
            Size id_2606 { Size(id_2605) };
            let_res_2589 = id_2606;
          }
          let_res_2586 = let_res_2589;
        }
        Size id_2607 { Size(sz_794 + let_res_2586) };
        Vec<1, Size> id_2608 {  id_2607  };
        Size let_res_2609;
        {
          Vec<1, Size> sz_ref_797 { id_2608 };
          int32_t id_2610 { 0L };
          Vec<1, int32_t> id_2611 {  id_2610  };
          {
            Vec<1, int32_t> repeat_n_798 { id_2611 };
            bool while_flag_2612 { true };
            do {
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2613 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_2614 { id_2613.notifications };
              uint32_t id_2615 { id_2614.size() };
              int32_t id_2616 { int32_t(id_2615) };
              uint8_t id_2617 { 0 };
              int32_t id_2618 { repeat_n_798[id_2617] };
              bool id_2619 { bool(id_2616 > id_2618) };
              while_flag_2612 = id_2619;
              if (while_flag_2612) {
                uint8_t id_2620 { 0 };
                uint8_t id_2621 { 0 };
                Size id_2622 { sz_ref_797[id_2621] };
                auto fun2623 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_2624 { 0 };
                int32_t id_2625 { repeat_n_798[id_2624] };
                ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2626 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<dessser::gen::raql_expr::t_ext> id_2627 { id_2626.notifications };
                dessser::gen::raql_expr::t_ext id_2628 { id_2627[id_2625] };
                Size id_2629 { fun2623(id_2628) };
                Size id_2630 { Size(id_2622 + id_2629) };
                Void id_2631 { ((void)(sz_ref_797[id_2620] = id_2630), VOID) };
                (void)id_2631;
                uint8_t id_2632 { 0 };
                uint8_t id_2633 { 0 };
                int32_t id_2634 { repeat_n_798[id_2633] };
                int32_t id_2635 { 1L };
                int32_t id_2636 { int32_t(id_2634 + id_2635) };
                Void id_2637 { ((void)(repeat_n_798[id_2632] = id_2636), VOID) };
                (void)id_2637;
                (void)id_2637;
              }
            } while (while_flag_2612);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_2638 { 0 };
          Size id_2639 { sz_ref_797[id_2638] };
          let_res_2609 = id_2639;
        }
        let_res_2581 = let_res_2609;
      }
      Size let_res_2640;
      {
        Size sz_799 { let_res_2581 };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2641 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::raql_expr::t_ext> id_2642 { id_2641.key };
        uint32_t id_2643 { id_2642.size() };
        Vec<1, uint32_t> id_2644 {  id_2643  };
        Size let_res_2645;
        {
          Vec<1, uint32_t> n_ref_800 { id_2644 };
          uint32_t id_2646 { 1U };
          Vec<1, uint32_t> id_2647 {  id_2646  };
          Size let_res_2648;
          {
            Vec<1, uint32_t> lebsz_ref_801 { id_2647 };
            bool while_flag_2649 { true };
            do {
              uint8_t id_2650 { 0 };
              uint32_t id_2651 { n_ref_800[id_2650] };
              uint8_t id_2652 { 0 };
              uint32_t id_2653 { lebsz_ref_801[id_2652] };
              uint8_t id_2654 { 7 };
              uint32_t id_2655 { uint32_t(id_2653 << id_2654) };
              bool id_2656 { bool(id_2651 >= id_2655) };
              while_flag_2649 = id_2656;
              if (while_flag_2649) {
                uint8_t id_2657 { 0 };
                uint8_t id_2658 { 0 };
                uint32_t id_2659 { lebsz_ref_801[id_2658] };
                uint32_t id_2660 { 1U };
                uint32_t id_2661 { uint32_t(id_2659 + id_2660) };
                Void id_2662 { ((void)(lebsz_ref_801[id_2657] = id_2661), VOID) };
                (void)id_2662;
              }
            } while (while_flag_2649);
            (void)VOID;
            uint8_t id_2663 { 0 };
            uint32_t id_2664 { lebsz_ref_801[id_2663] };
            Size id_2665 { Size(id_2664) };
            let_res_2648 = id_2665;
          }
          let_res_2645 = let_res_2648;
        }
        Size id_2666 { Size(sz_799 + let_res_2645) };
        Vec<1, Size> id_2667 {  id_2666  };
        Size let_res_2668;
        {
          Vec<1, Size> sz_ref_802 { id_2667 };
          int32_t id_2669 { 0L };
          Vec<1, int32_t> id_2670 {  id_2669  };
          {
            Vec<1, int32_t> repeat_n_803 { id_2670 };
            bool while_flag_2671 { true };
            do {
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2672 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::raql_expr::t_ext> id_2673 { id_2672.key };
              uint32_t id_2674 { id_2673.size() };
              int32_t id_2675 { int32_t(id_2674) };
              uint8_t id_2676 { 0 };
              int32_t id_2677 { repeat_n_803[id_2676] };
              bool id_2678 { bool(id_2675 > id_2677) };
              while_flag_2671 = id_2678;
              if (while_flag_2671) {
                uint8_t id_2679 { 0 };
                uint8_t id_2680 { 0 };
                Size id_2681 { sz_ref_802[id_2680] };
                auto fun2682 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_2683 { 0 };
                int32_t id_2684 { repeat_n_803[id_2683] };
                ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2685 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<dessser::gen::raql_expr::t_ext> id_2686 { id_2685.key };
                dessser::gen::raql_expr::t_ext id_2687 { id_2686[id_2684] };
                Size id_2688 { fun2682(id_2687) };
                Size id_2689 { Size(id_2681 + id_2688) };
                Void id_2690 { ((void)(sz_ref_802[id_2679] = id_2689), VOID) };
                (void)id_2690;
                uint8_t id_2691 { 0 };
                uint8_t id_2692 { 0 };
                int32_t id_2693 { repeat_n_803[id_2692] };
                int32_t id_2694 { 1L };
                int32_t id_2695 { int32_t(id_2693 + id_2694) };
                Void id_2696 { ((void)(repeat_n_803[id_2691] = id_2695), VOID) };
                (void)id_2696;
                (void)id_2696;
              }
            } while (while_flag_2671);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_2697 { 0 };
          Size id_2698 { sz_ref_802[id_2697] };
          let_res_2668 = id_2698;
        }
        let_res_2640 = let_res_2668;
      }
      Size let_res_2699;
      {
        Size sz_804 { let_res_2640 };
        auto fun2700 { dessser::gen::raql_expr::sersize_of_row_binary };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2701 { std::get<0 /* Aggregate */>((*p_0)) };
        dessser::gen::raql_expr::t_ext id_2702 { id_2701.commit_cond };
        Size id_2703 { fun2700(id_2702) };
        Size id_2704 { Size(sz_804 + id_2703) };
        let_res_2699 = id_2704;
      }
      Size id_2705 { 1UL };
      Size id_2706 { Size(let_res_2699 + id_2705) };
      Size let_res_2707;
      {
        Size sz_806 { id_2706 };
        auto fun2708 { dessser::gen::raql_flush_method::sersize_of_row_binary };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2709 { std::get<0 /* Aggregate */>((*p_0)) };
        dessser::gen::raql_flush_method::t_ext id_2710 { id_2709.flush_how };
        Size id_2711 { fun2708(id_2710) };
        Size id_2712 { Size(sz_806 + id_2711) };
        let_res_2707 = id_2712;
      }
      Size let_res_2713;
      {
        Size sz_807 { let_res_2707 };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2714 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<::dessser::gen::raql_operation::data_source*> id_2715 { id_2714.from };
        uint32_t id_2716 { id_2715.size() };
        Vec<1, uint32_t> id_2717 {  id_2716  };
        Size let_res_2718;
        {
          Vec<1, uint32_t> n_ref_808 { id_2717 };
          uint32_t id_2719 { 1U };
          Vec<1, uint32_t> id_2720 {  id_2719  };
          Size let_res_2721;
          {
            Vec<1, uint32_t> lebsz_ref_809 { id_2720 };
            bool while_flag_2722 { true };
            do {
              uint8_t id_2723 { 0 };
              uint32_t id_2724 { n_ref_808[id_2723] };
              uint8_t id_2725 { 0 };
              uint32_t id_2726 { lebsz_ref_809[id_2725] };
              uint8_t id_2727 { 7 };
              uint32_t id_2728 { uint32_t(id_2726 << id_2727) };
              bool id_2729 { bool(id_2724 >= id_2728) };
              while_flag_2722 = id_2729;
              if (while_flag_2722) {
                uint8_t id_2730 { 0 };
                uint8_t id_2731 { 0 };
                uint32_t id_2732 { lebsz_ref_809[id_2731] };
                uint32_t id_2733 { 1U };
                uint32_t id_2734 { uint32_t(id_2732 + id_2733) };
                Void id_2735 { ((void)(lebsz_ref_809[id_2730] = id_2734), VOID) };
                (void)id_2735;
              }
            } while (while_flag_2722);
            (void)VOID;
            uint8_t id_2736 { 0 };
            uint32_t id_2737 { lebsz_ref_809[id_2736] };
            Size id_2738 { Size(id_2737) };
            let_res_2721 = id_2738;
          }
          let_res_2718 = let_res_2721;
        }
        Size id_2739 { Size(sz_807 + let_res_2718) };
        Vec<1, Size> id_2740 {  id_2739  };
        Size let_res_2741;
        {
          Vec<1, Size> sz_ref_810 { id_2740 };
          int32_t id_2742 { 0L };
          Vec<1, int32_t> id_2743 {  id_2742  };
          {
            Vec<1, int32_t> repeat_n_811 { id_2743 };
            bool while_flag_2744 { true };
            do {
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2745 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<::dessser::gen::raql_operation::data_source*> id_2746 { id_2745.from };
              uint32_t id_2747 { id_2746.size() };
              int32_t id_2748 { int32_t(id_2747) };
              uint8_t id_2749 { 0 };
              int32_t id_2750 { repeat_n_811[id_2749] };
              bool id_2751 { bool(id_2748 > id_2750) };
              while_flag_2744 = id_2751;
              if (while_flag_2744) {
                uint8_t id_2752 { 0 };
                uint8_t id_2753 { 0 };
                Size id_2754 { sz_ref_810[id_2753] };
                uint8_t id_2755 { 0 };
                int32_t id_2756 { repeat_n_811[id_2755] };
                ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2757 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<::dessser::gen::raql_operation::data_source*> id_2758 { id_2757.from };
                ::dessser::gen::raql_operation::data_source* id_2759 { id_2758[id_2756] };
                Size id_2760 { data_source_sersize_of_row_binary(id_2759) };
                Size id_2761 { Size(id_2754 + id_2760) };
                Void id_2762 { ((void)(sz_ref_810[id_2752] = id_2761), VOID) };
                (void)id_2762;
                uint8_t id_2763 { 0 };
                uint8_t id_2764 { 0 };
                int32_t id_2765 { repeat_n_811[id_2764] };
                int32_t id_2766 { 1L };
                int32_t id_2767 { int32_t(id_2765 + id_2766) };
                Void id_2768 { ((void)(repeat_n_811[id_2763] = id_2767), VOID) };
                (void)id_2768;
                (void)id_2768;
              }
            } while (while_flag_2744);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_2769 { 0 };
          Size id_2770 { sz_ref_810[id_2769] };
          let_res_2741 = id_2770;
        }
        let_res_2713 = let_res_2741;
      }
      Size let_res_2771;
      {
        Size sz_812 { let_res_2713 };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2772 { std::get<0 /* Aggregate */>((*p_0)) };
        std::optional<dessser::gen::raql_expr::t_ext> id_2773 { id_2772.every };
        bool id_2774 { !(id_2773.has_value ()) };
        Size choose_res_2775;
        if (id_2774) {
          Size id_2776 { 1UL };
          Size id_2777 { Size(sz_812 + id_2776) };
          choose_res_2775 = id_2777;
        } else {
          auto fun2778 { dessser::gen::raql_expr::sersize_of_row_binary };
          ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2779 { std::get<0 /* Aggregate */>((*p_0)) };
          std::optional<dessser::gen::raql_expr::t_ext> id_2780 { id_2779.every };
          dessser::gen::raql_expr::t_ext id_2781 { id_2780.value() };
          Size id_2782 { fun2778(id_2781) };
          Size id_2783 { Size(sz_812 + id_2782) };
          Size id_2784 { 1UL };
          Size id_2785 { Size(id_2783 + id_2784) };
          choose_res_2775 = id_2785;
        }
        let_res_2771 = choose_res_2775;
      }
      Size let_res_2786;
      {
        Size sz_813 { let_res_2771 };
        ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2787 { std::get<0 /* Aggregate */>((*p_0)) };
        Lst<dessser::gen::field_name::t_ext> id_2788 { id_2787.Aggregate_factors };
        uint32_t id_2789 { id_2788.size() };
        Vec<1, uint32_t> id_2790 {  id_2789  };
        Size let_res_2791;
        {
          Vec<1, uint32_t> n_ref_814 { id_2790 };
          uint32_t id_2792 { 1U };
          Vec<1, uint32_t> id_2793 {  id_2792  };
          Size let_res_2794;
          {
            Vec<1, uint32_t> lebsz_ref_815 { id_2793 };
            bool while_flag_2795 { true };
            do {
              uint8_t id_2796 { 0 };
              uint32_t id_2797 { n_ref_814[id_2796] };
              uint8_t id_2798 { 0 };
              uint32_t id_2799 { lebsz_ref_815[id_2798] };
              uint8_t id_2800 { 7 };
              uint32_t id_2801 { uint32_t(id_2799 << id_2800) };
              bool id_2802 { bool(id_2797 >= id_2801) };
              while_flag_2795 = id_2802;
              if (while_flag_2795) {
                uint8_t id_2803 { 0 };
                uint8_t id_2804 { 0 };
                uint32_t id_2805 { lebsz_ref_815[id_2804] };
                uint32_t id_2806 { 1U };
                uint32_t id_2807 { uint32_t(id_2805 + id_2806) };
                Void id_2808 { ((void)(lebsz_ref_815[id_2803] = id_2807), VOID) };
                (void)id_2808;
              }
            } while (while_flag_2795);
            (void)VOID;
            uint8_t id_2809 { 0 };
            uint32_t id_2810 { lebsz_ref_815[id_2809] };
            Size id_2811 { Size(id_2810) };
            let_res_2794 = id_2811;
          }
          let_res_2791 = let_res_2794;
        }
        Size id_2812 { Size(sz_813 + let_res_2791) };
        Vec<1, Size> id_2813 {  id_2812  };
        Size let_res_2814;
        {
          Vec<1, Size> sz_ref_816 { id_2813 };
          int32_t id_2815 { 0L };
          Vec<1, int32_t> id_2816 {  id_2815  };
          {
            Vec<1, int32_t> repeat_n_817 { id_2816 };
            bool while_flag_2817 { true };
            do {
              ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2818 { std::get<0 /* Aggregate */>((*p_0)) };
              Lst<dessser::gen::field_name::t_ext> id_2819 { id_2818.Aggregate_factors };
              uint32_t id_2820 { id_2819.size() };
              int32_t id_2821 { int32_t(id_2820) };
              uint8_t id_2822 { 0 };
              int32_t id_2823 { repeat_n_817[id_2822] };
              bool id_2824 { bool(id_2821 > id_2823) };
              while_flag_2817 = id_2824;
              if (while_flag_2817) {
                uint8_t id_2825 { 0 };
                uint8_t id_2826 { 0 };
                Size id_2827 { sz_ref_816[id_2826] };
                auto fun2828 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_2829 { 0 };
                int32_t id_2830 { repeat_n_817[id_2829] };
                ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_2831 { std::get<0 /* Aggregate */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2832 { id_2831.Aggregate_factors };
                dessser::gen::field_name::t_ext id_2833 { id_2832[id_2830] };
                Size id_2834 { fun2828(id_2833) };
                Size id_2835 { Size(id_2827 + id_2834) };
                Void id_2836 { ((void)(sz_ref_816[id_2825] = id_2835), VOID) };
                (void)id_2836;
                uint8_t id_2837 { 0 };
                uint8_t id_2838 { 0 };
                int32_t id_2839 { repeat_n_817[id_2838] };
                int32_t id_2840 { 1L };
                int32_t id_2841 { int32_t(id_2839 + id_2840) };
                Void id_2842 { ((void)(repeat_n_817[id_2837] = id_2841), VOID) };
                (void)id_2842;
                (void)id_2842;
              }
            } while (while_flag_2817);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_2843 { 0 };
          Size id_2844 { sz_ref_816[id_2843] };
          let_res_2814 = id_2844;
        }
        let_res_2786 = let_res_2814;
      }
      choose_res_2334 = let_res_2786;
    } else {
      uint16_t id_2845 { 1 };
      uint16_t id_2846 { uint16_t((*p_0).index()) };
      bool id_2847 { bool(id_2845 == id_2846) };
      Size choose_res_2848;
      if (id_2847) {
        Size id_2849 { 2UL };
        ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2850 { std::get<1 /* ReadExternal */>((*p_0)) };
        ::dessser::gen::raql_operation::external_source* id_2851 { id_2850.source };
        Size id_2852 { external_source_sersize_of_row_binary(id_2851) };
        Size id_2853 { Size(id_2849 + id_2852) };
        Size let_res_2854;
        {
          Size sz_767 { id_2853 };
          ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2855 { std::get<1 /* ReadExternal */>((*p_0)) };
          ::dessser::gen::raql_operation::external_format* id_2856 { id_2855.format };
          Size id_2857 { external_format_sersize_of_row_binary(id_2856) };
          Size id_2858 { Size(sz_767 + id_2857) };
          let_res_2854 = id_2858;
        }
        Size let_res_2859;
        {
          Size sz_768 { let_res_2854 };
          ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2860 { std::get<1 /* ReadExternal */>((*p_0)) };
          std::optional<dessser::gen::event_time::t_ext> id_2861 { id_2860.event_time };
          bool id_2862 { !(id_2861.has_value ()) };
          Size choose_res_2863;
          if (id_2862) {
            Size id_2864 { 1UL };
            Size id_2865 { Size(sz_768 + id_2864) };
            choose_res_2863 = id_2865;
          } else {
            auto fun2866 { dessser::gen::event_time::sersize_of_row_binary };
            ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2867 { std::get<1 /* ReadExternal */>((*p_0)) };
            std::optional<dessser::gen::event_time::t_ext> id_2868 { id_2867.event_time };
            dessser::gen::event_time::t_ext id_2869 { id_2868.value() };
            Size id_2870 { fun2866(id_2869) };
            Size id_2871 { Size(sz_768 + id_2870) };
            Size id_2872 { 1UL };
            Size id_2873 { Size(id_2871 + id_2872) };
            choose_res_2863 = id_2873;
          }
          let_res_2859 = choose_res_2863;
        }
        Size let_res_2874;
        {
          Size sz_769 { let_res_2859 };
          ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2875 { std::get<1 /* ReadExternal */>((*p_0)) };
          Lst<dessser::gen::field_name::t_ext> id_2876 { id_2875.ReadExternal_factors };
          uint32_t id_2877 { id_2876.size() };
          Vec<1, uint32_t> id_2878 {  id_2877  };
          Size let_res_2879;
          {
            Vec<1, uint32_t> n_ref_770 { id_2878 };
            uint32_t id_2880 { 1U };
            Vec<1, uint32_t> id_2881 {  id_2880  };
            Size let_res_2882;
            {
              Vec<1, uint32_t> lebsz_ref_771 { id_2881 };
              bool while_flag_2883 { true };
              do {
                uint8_t id_2884 { 0 };
                uint32_t id_2885 { n_ref_770[id_2884] };
                uint8_t id_2886 { 0 };
                uint32_t id_2887 { lebsz_ref_771[id_2886] };
                uint8_t id_2888 { 7 };
                uint32_t id_2889 { uint32_t(id_2887 << id_2888) };
                bool id_2890 { bool(id_2885 >= id_2889) };
                while_flag_2883 = id_2890;
                if (while_flag_2883) {
                  uint8_t id_2891 { 0 };
                  uint8_t id_2892 { 0 };
                  uint32_t id_2893 { lebsz_ref_771[id_2892] };
                  uint32_t id_2894 { 1U };
                  uint32_t id_2895 { uint32_t(id_2893 + id_2894) };
                  Void id_2896 { ((void)(lebsz_ref_771[id_2891] = id_2895), VOID) };
                  (void)id_2896;
                }
              } while (while_flag_2883);
              (void)VOID;
              uint8_t id_2897 { 0 };
              uint32_t id_2898 { lebsz_ref_771[id_2897] };
              Size id_2899 { Size(id_2898) };
              let_res_2882 = id_2899;
            }
            let_res_2879 = let_res_2882;
          }
          Size id_2900 { Size(sz_769 + let_res_2879) };
          Vec<1, Size> id_2901 {  id_2900  };
          Size let_res_2902;
          {
            Vec<1, Size> sz_ref_772 { id_2901 };
            int32_t id_2903 { 0L };
            Vec<1, int32_t> id_2904 {  id_2903  };
            {
              Vec<1, int32_t> repeat_n_773 { id_2904 };
              bool while_flag_2905 { true };
              do {
                ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2906 { std::get<1 /* ReadExternal */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_2907 { id_2906.ReadExternal_factors };
                uint32_t id_2908 { id_2907.size() };
                int32_t id_2909 { int32_t(id_2908) };
                uint8_t id_2910 { 0 };
                int32_t id_2911 { repeat_n_773[id_2910] };
                bool id_2912 { bool(id_2909 > id_2911) };
                while_flag_2905 = id_2912;
                if (while_flag_2905) {
                  uint8_t id_2913 { 0 };
                  uint8_t id_2914 { 0 };
                  Size id_2915 { sz_ref_772[id_2914] };
                  auto fun2916 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_2917 { 0 };
                  int32_t id_2918 { repeat_n_773[id_2917] };
                  ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_2919 { std::get<1 /* ReadExternal */>((*p_0)) };
                  Lst<dessser::gen::field_name::t_ext> id_2920 { id_2919.ReadExternal_factors };
                  dessser::gen::field_name::t_ext id_2921 { id_2920[id_2918] };
                  Size id_2922 { fun2916(id_2921) };
                  Size id_2923 { Size(id_2915 + id_2922) };
                  Void id_2924 { ((void)(sz_ref_772[id_2913] = id_2923), VOID) };
                  (void)id_2924;
                  uint8_t id_2925 { 0 };
                  uint8_t id_2926 { 0 };
                  int32_t id_2927 { repeat_n_773[id_2926] };
                  int32_t id_2928 { 1L };
                  int32_t id_2929 { int32_t(id_2927 + id_2928) };
                  Void id_2930 { ((void)(repeat_n_773[id_2925] = id_2929), VOID) };
                  (void)id_2930;
                  (void)id_2930;
                }
              } while (while_flag_2905);
              (void)VOID;
            }
            (void)VOID;
            uint8_t id_2931 { 0 };
            Size id_2932 { sz_ref_772[id_2931] };
            let_res_2902 = id_2932;
          }
          let_res_2874 = let_res_2902;
        }
        choose_res_2848 = let_res_2874;
      } else {
        uint16_t id_2933 { uint16_t((*p_0).index()) };
        uint16_t id_2934 { 2 };
        bool id_2935 { bool(id_2933 == id_2934) };
        Void id_2936 { ((void)(assert(id_2935)), VOID) };
        (void)id_2936;
        Size id_2937 { 2UL };
        ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2938 { std::get<2 /* ListenFor */>((*p_0)) };
        std::string id_2939 { id_2938.net_addr };
        uint32_t id_2940 { (uint32_t)id_2939.size() };
        Vec<1, uint32_t> id_2941 {  id_2940  };
        Size let_res_2942;
        {
          Vec<1, uint32_t> n_ref_757 { id_2941 };
          uint32_t id_2943 { 1U };
          Vec<1, uint32_t> id_2944 {  id_2943  };
          Size let_res_2945;
          {
            Vec<1, uint32_t> lebsz_ref_758 { id_2944 };
            bool while_flag_2946 { true };
            do {
              uint8_t id_2947 { 0 };
              uint32_t id_2948 { n_ref_757[id_2947] };
              uint8_t id_2949 { 0 };
              uint32_t id_2950 { lebsz_ref_758[id_2949] };
              uint8_t id_2951 { 7 };
              uint32_t id_2952 { uint32_t(id_2950 << id_2951) };
              bool id_2953 { bool(id_2948 >= id_2952) };
              while_flag_2946 = id_2953;
              if (while_flag_2946) {
                uint8_t id_2954 { 0 };
                uint8_t id_2955 { 0 };
                uint32_t id_2956 { lebsz_ref_758[id_2955] };
                uint32_t id_2957 { 1U };
                uint32_t id_2958 { uint32_t(id_2956 + id_2957) };
                Void id_2959 { ((void)(lebsz_ref_758[id_2954] = id_2958), VOID) };
                (void)id_2959;
              }
            } while (while_flag_2946);
            (void)VOID;
            uint8_t id_2960 { 0 };
            uint32_t id_2961 { lebsz_ref_758[id_2960] };
            Size id_2962 { Size(id_2961) };
            let_res_2945 = id_2962;
          }
          let_res_2942 = let_res_2945;
        }
        ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2963 { std::get<2 /* ListenFor */>((*p_0)) };
        std::string id_2964 { id_2963.net_addr };
        uint32_t id_2965 { (uint32_t)id_2964.size() };
        Size id_2966 { Size(id_2965) };
        Size id_2967 { Size(let_res_2942 + id_2966) };
        Size id_2968 { Size(id_2937 + id_2967) };
        Size id_2969 { 2UL };
        Size id_2970 { Size(id_2968 + id_2969) };
        Size let_res_2971;
        {
          Size sz_760 { id_2970 };
          auto fun2972 { dessser::gen::raql_net_protocol::sersize_of_row_binary };
          ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2973 { std::get<2 /* ListenFor */>((*p_0)) };
          dessser::gen::raql_net_protocol::t_ext id_2974 { id_2973.proto };
          Size id_2975 { fun2972(id_2974) };
          Size id_2976 { Size(sz_760 + id_2975) };
          let_res_2971 = id_2976;
        }
        Size let_res_2977;
        {
          Size sz_761 { let_res_2971 };
          ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_2978 { std::get<2 /* ListenFor */>((*p_0)) };
          Lst<dessser::gen::field_name::t_ext> id_2979 { id_2978.factors };
          uint32_t id_2980 { id_2979.size() };
          Vec<1, uint32_t> id_2981 {  id_2980  };
          Size let_res_2982;
          {
            Vec<1, uint32_t> n_ref_762 { id_2981 };
            uint32_t id_2983 { 1U };
            Vec<1, uint32_t> id_2984 {  id_2983  };
            Size let_res_2985;
            {
              Vec<1, uint32_t> lebsz_ref_763 { id_2984 };
              bool while_flag_2986 { true };
              do {
                uint8_t id_2987 { 0 };
                uint32_t id_2988 { n_ref_762[id_2987] };
                uint8_t id_2989 { 0 };
                uint32_t id_2990 { lebsz_ref_763[id_2989] };
                uint8_t id_2991 { 7 };
                uint32_t id_2992 { uint32_t(id_2990 << id_2991) };
                bool id_2993 { bool(id_2988 >= id_2992) };
                while_flag_2986 = id_2993;
                if (while_flag_2986) {
                  uint8_t id_2994 { 0 };
                  uint8_t id_2995 { 0 };
                  uint32_t id_2996 { lebsz_ref_763[id_2995] };
                  uint32_t id_2997 { 1U };
                  uint32_t id_2998 { uint32_t(id_2996 + id_2997) };
                  Void id_2999 { ((void)(lebsz_ref_763[id_2994] = id_2998), VOID) };
                  (void)id_2999;
                }
              } while (while_flag_2986);
              (void)VOID;
              uint8_t id_3000 { 0 };
              uint32_t id_3001 { lebsz_ref_763[id_3000] };
              Size id_3002 { Size(id_3001) };
              let_res_2985 = id_3002;
            }
            let_res_2982 = let_res_2985;
          }
          Size id_3003 { Size(sz_761 + let_res_2982) };
          Vec<1, Size> id_3004 {  id_3003  };
          Size let_res_3005;
          {
            Vec<1, Size> sz_ref_764 { id_3004 };
            int32_t id_3006 { 0L };
            Vec<1, int32_t> id_3007 {  id_3006  };
            {
              Vec<1, int32_t> repeat_n_765 { id_3007 };
              bool while_flag_3008 { true };
              do {
                ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_3009 { std::get<2 /* ListenFor */>((*p_0)) };
                Lst<dessser::gen::field_name::t_ext> id_3010 { id_3009.factors };
                uint32_t id_3011 { id_3010.size() };
                int32_t id_3012 { int32_t(id_3011) };
                uint8_t id_3013 { 0 };
                int32_t id_3014 { repeat_n_765[id_3013] };
                bool id_3015 { bool(id_3012 > id_3014) };
                while_flag_3008 = id_3015;
                if (while_flag_3008) {
                  uint8_t id_3016 { 0 };
                  uint8_t id_3017 { 0 };
                  Size id_3018 { sz_ref_764[id_3017] };
                  auto fun3019 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_3020 { 0 };
                  int32_t id_3021 { repeat_n_765[id_3020] };
                  ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_3022 { std::get<2 /* ListenFor */>((*p_0)) };
                  Lst<dessser::gen::field_name::t_ext> id_3023 { id_3022.factors };
                  dessser::gen::field_name::t_ext id_3024 { id_3023[id_3021] };
                  Size id_3025 { fun3019(id_3024) };
                  Size id_3026 { Size(id_3018 + id_3025) };
                  Void id_3027 { ((void)(sz_ref_764[id_3016] = id_3026), VOID) };
                  (void)id_3027;
                  uint8_t id_3028 { 0 };
                  uint8_t id_3029 { 0 };
                  int32_t id_3030 { repeat_n_765[id_3029] };
                  int32_t id_3031 { 1L };
                  int32_t id_3032 { int32_t(id_3030 + id_3031) };
                  Void id_3033 { ((void)(repeat_n_765[id_3028] = id_3032), VOID) };
                  (void)id_3033;
                  (void)id_3033;
                }
              } while (while_flag_3008);
              (void)VOID;
            }
            (void)VOID;
            uint8_t id_3034 { 0 };
            Size id_3035 { sz_ref_764[id_3034] };
            let_res_3005 = id_3035;
          }
          let_res_2977 = let_res_3005;
        }
        choose_res_2848 = let_res_2977;
      }
      choose_res_2334 = choose_res_2848;
    }
    return choose_res_2334;
  }
   };
  return fun2330;
}
std::function<Size(::dessser::gen::raql_operation::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_126" "make_snd_127"
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
                  (make-tup (construct "[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" 1 (identifier "dsum2_fst_66")) (identifier "dsum2_snd_67")))))))
        (make-tup (identifier "make_fst_126") (identifier "make_snd_127"))))
 */
static std::function<::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3(Pointer)> data_source_of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3(Pointer)> fun3036 { [&fun3036](Pointer p_0) {
    ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_3037 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 letpair_res_3038;
    {
      auto du16_fst_57 { std::get<0>(id_3037) };
      auto du16_snd_58 { std::get<1>(id_3037) };
      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_3039 { du16_fst_57, du16_snd_58 };
      letpair_res_3038 = id_3039;
    }
    ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 let_res_3040;
    {
      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_3038 };
      ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 letpair_res_3041;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_3042 { 0 };
        bool id_3043 { bool(id_3042 == dsum1_fst_63) };
        ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 choose_res_3044;
        if (id_3043) {
          ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_3045 { dsum1_snd_64.readU16Le() };
          ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 letpair_res_3046;
          {
            auto du16_fst_69 { std::get<0>(id_3045) };
            auto du16_snd_70 { std::get<1>(id_3045) };
            ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_3047 { du16_fst_69, du16_snd_70 };
            letpair_res_3046 = id_3047;
          }
          ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 let_res_3048;
          {
            ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 dsum1_74 { letpair_res_3046 };
            ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 letpair_res_3049;
            {
              auto dsum1_fst_75 { std::get<0>(dsum1_74) };
              auto dsum1_snd_76 { std::get<1>(dsum1_74) };
              uint16_t id_3050 { 0 };
              bool id_3051 { bool(id_3050 == dsum1_fst_75) };
              ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 choose_res_3052;
              if (id_3051) {
                (void)VOID;
                ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_3053 { std::in_place_index<0>, VOID };
                ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 id_3054 { id_3053, dsum1_snd_76 };
                choose_res_3052 = id_3054;
              } else {
                uint16_t id_3055 { 1 };
                bool id_3056 { bool(id_3055 == dsum1_fst_75) };
                ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 choose_res_3057;
                if (id_3056) {
                  uint32_t id_3058 { 0U };
                  Vec<1, uint32_t> id_3059 {  id_3058  };
                  ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_3060;
                  {
                    Vec<1, uint32_t> leb_ref_80 { id_3059 };
                    uint8_t id_3061 { 0 };
                    Vec<1, uint8_t> id_3062 {  id_3061  };
                    ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_3063;
                    {
                      Vec<1, uint8_t> shft_ref_81 { id_3062 };
                      Vec<1, Pointer> id_3064 {  dsum1_snd_76  };
                      ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_3065;
                      {
                        Vec<1, Pointer> p_ref_82 { id_3064 };
                        bool while_flag_3066 { true };
                        do {
                          uint8_t id_3067 { 0 };
                          Pointer id_3068 { p_ref_82[id_3067] };
                          ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3069 { id_3068.readU8() };
                          bool let_res_3070;
                          {
                            ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_83 { id_3069 };
                            bool letpair_res_3071;
                            {
                              auto leb128_fst_84 { std::get<0>(leb128_83) };
                              auto leb128_snd_85 { std::get<1>(leb128_83) };
                              uint8_t id_3072 { 0 };
                              Void id_3073 { ((void)(p_ref_82[id_3072] = leb128_snd_85), VOID) };
                              (void)id_3073;
                              uint8_t id_3074 { 0 };
                              uint8_t id_3075 { 127 };
                              uint8_t id_3076 { uint8_t(leb128_fst_84 & id_3075) };
                              uint32_t id_3077 { uint32_t(id_3076) };
                              uint8_t id_3078 { 0 };
                              uint8_t id_3079 { shft_ref_81[id_3078] };
                              uint32_t id_3080 { uint32_t(id_3077 << id_3079) };
                              uint8_t id_3081 { 0 };
                              uint32_t id_3082 { leb_ref_80[id_3081] };
                              uint32_t id_3083 { uint32_t(id_3080 | id_3082) };
                              Void id_3084 { ((void)(leb_ref_80[id_3074] = id_3083), VOID) };
                              (void)id_3084;
                              uint8_t id_3085 { 0 };
                              uint8_t id_3086 { 0 };
                              uint8_t id_3087 { shft_ref_81[id_3086] };
                              uint8_t id_3088 { 7 };
                              uint8_t id_3089 { uint8_t(id_3087 + id_3088) };
                              Void id_3090 { ((void)(shft_ref_81[id_3085] = id_3089), VOID) };
                              (void)id_3090;
                              uint8_t id_3091 { 128 };
                              bool id_3092 { bool(leb128_fst_84 >= id_3091) };
                              letpair_res_3071 = id_3092;
                            }
                            let_res_3070 = letpair_res_3071;
                          }
                          while_flag_3066 = let_res_3070;
                          if (while_flag_3066) {
                            (void)VOID;
                          }
                        } while (while_flag_3066);
                        (void)VOID;
                        uint8_t id_3093 { 0 };
                        uint32_t id_3094 { leb_ref_80[id_3093] };
                        Size id_3095 { Size(id_3094) };
                        uint8_t id_3096 { 0 };
                        Pointer id_3097 { p_ref_82[id_3096] };
                        ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c id_3098 { id_3095, id_3097 };
                        let_res_3065 = id_3098;
                      }
                      let_res_3063 = let_res_3065;
                    }
                    let_res_3060 = let_res_3063;
                  }
                  ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 let_res_3099;
                  {
                    ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c dstring1_86 { let_res_3060 };
                    ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 letpair_res_3100;
                    {
                      auto dstring1_fst_87 { std::get<0>(dstring1_86) };
                      auto dstring1_snd_88 { std::get<1>(dstring1_86) };
                      ::dessser::gen::raql_operation::t188345aa49abd0cb47ff73fedc219f08 id_3101 { dstring1_snd_88.readBytes(dstring1_fst_87) };
                      ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 letpair_res_3102;
                      {
                        auto dstring2_fst_90 { std::get<0>(id_3101) };
                        auto dstring2_snd_91 { std::get<1>(id_3101) };
                        std::string id_3103 { dstring2_fst_90.toString() };
                        ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_3104 { std::in_place_index<1>, id_3103 };
                        ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 id_3105 { id_3104, dstring2_snd_91 };
                        letpair_res_3102 = id_3105;
                      }
                      letpair_res_3100 = letpair_res_3102;
                    }
                    let_res_3099 = letpair_res_3100;
                  }
                  choose_res_3057 = let_res_3099;
                } else {
                  uint16_t id_3106 { 2 };
                  bool id_3107 { bool(dsum1_fst_75 == id_3106) };
                  Void id_3108 { ((void)(assert(id_3107)), VOID) };
                  (void)id_3108;
                  (void)VOID;
                  ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db id_3109 { std::in_place_index<2>, VOID };
                  ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 id_3110 { id_3109, dsum1_snd_76 };
                  choose_res_3057 = id_3110;
                }
                choose_res_3052 = choose_res_3057;
              }
              letpair_res_3049 = choose_res_3052;
            }
            let_res_3048 = letpair_res_3049;
          }
          ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 let_res_3111;
          {
            ::dessser::gen::raql_operation::ta86591fd7bb24cbb53009de06037fc09 dtup_98 { let_res_3048 };
            ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 letpair_res_3112;
            {
              auto dtup_fst_99 { std::get<0>(dtup_98) };
              auto dtup_snd_100 { std::get<1>(dtup_98) };
              Size id_3113 { 0UL };
              uint8_t id_3114 { dtup_snd_100.peekU8(id_3113) };
              uint8_t id_3115 { 1 };
              bool id_3116 { bool(id_3114 == id_3115) };
              ::dessser::gen::raql_operation::t3fbff88eef4e4c8bc42b06e5ad07ea51 choose_res_3117;
              if (id_3116) {
                std::optional<std::string> id_3118 { std::nullopt };
                Size id_3119 { 1UL };
                Pointer id_3120 { dtup_snd_100.skip(id_3119) };
                ::dessser::gen::raql_operation::t3fbff88eef4e4c8bc42b06e5ad07ea51 id_3121 { id_3118, id_3120 };
                choose_res_3117 = id_3121;
              } else {
                uint32_t id_3122 { 0U };
                Vec<1, uint32_t> id_3123 {  id_3122  };
                ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_3124;
                {
                  Vec<1, uint32_t> leb_ref_101 { id_3123 };
                  uint8_t id_3125 { 0 };
                  Vec<1, uint8_t> id_3126 {  id_3125  };
                  ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_3127;
                  {
                    Vec<1, uint8_t> shft_ref_102 { id_3126 };
                    Size id_3128 { 1UL };
                    Pointer id_3129 { dtup_snd_100.skip(id_3128) };
                    Vec<1, Pointer> id_3130 {  id_3129  };
                    ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_3131;
                    {
                      Vec<1, Pointer> p_ref_103 { id_3130 };
                      bool while_flag_3132 { true };
                      do {
                        uint8_t id_3133 { 0 };
                        Pointer id_3134 { p_ref_103[id_3133] };
                        ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3135 { id_3134.readU8() };
                        bool let_res_3136;
                        {
                          ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_104 { id_3135 };
                          bool letpair_res_3137;
                          {
                            auto leb128_fst_105 { std::get<0>(leb128_104) };
                            auto leb128_snd_106 { std::get<1>(leb128_104) };
                            uint8_t id_3138 { 0 };
                            Void id_3139 { ((void)(p_ref_103[id_3138] = leb128_snd_106), VOID) };
                            (void)id_3139;
                            uint8_t id_3140 { 0 };
                            uint8_t id_3141 { 127 };
                            uint8_t id_3142 { uint8_t(leb128_fst_105 & id_3141) };
                            uint32_t id_3143 { uint32_t(id_3142) };
                            uint8_t id_3144 { 0 };
                            uint8_t id_3145 { shft_ref_102[id_3144] };
                            uint32_t id_3146 { uint32_t(id_3143 << id_3145) };
                            uint8_t id_3147 { 0 };
                            uint32_t id_3148 { leb_ref_101[id_3147] };
                            uint32_t id_3149 { uint32_t(id_3146 | id_3148) };
                            Void id_3150 { ((void)(leb_ref_101[id_3140] = id_3149), VOID) };
                            (void)id_3150;
                            uint8_t id_3151 { 0 };
                            uint8_t id_3152 { 0 };
                            uint8_t id_3153 { shft_ref_102[id_3152] };
                            uint8_t id_3154 { 7 };
                            uint8_t id_3155 { uint8_t(id_3153 + id_3154) };
                            Void id_3156 { ((void)(shft_ref_102[id_3151] = id_3155), VOID) };
                            (void)id_3156;
                            uint8_t id_3157 { 128 };
                            bool id_3158 { bool(leb128_fst_105 >= id_3157) };
                            letpair_res_3137 = id_3158;
                          }
                          let_res_3136 = letpair_res_3137;
                        }
                        while_flag_3132 = let_res_3136;
                        if (while_flag_3132) {
                          (void)VOID;
                        }
                      } while (while_flag_3132);
                      (void)VOID;
                      uint8_t id_3159 { 0 };
                      uint32_t id_3160 { leb_ref_101[id_3159] };
                      Size id_3161 { Size(id_3160) };
                      uint8_t id_3162 { 0 };
                      Pointer id_3163 { p_ref_103[id_3162] };
                      ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c id_3164 { id_3161, id_3163 };
                      let_res_3131 = id_3164;
                    }
                    let_res_3127 = let_res_3131;
                  }
                  let_res_3124 = let_res_3127;
                }
                ::dessser::gen::raql_operation::t3fbff88eef4e4c8bc42b06e5ad07ea51 let_res_3165;
                {
                  ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c dstring1_107 { let_res_3124 };
                  ::dessser::gen::raql_operation::t3fbff88eef4e4c8bc42b06e5ad07ea51 letpair_res_3166;
                  {
                    auto dstring1_fst_108 { std::get<0>(dstring1_107) };
                    auto dstring1_snd_109 { std::get<1>(dstring1_107) };
                    ::dessser::gen::raql_operation::t188345aa49abd0cb47ff73fedc219f08 id_3167 { dstring1_snd_109.readBytes(dstring1_fst_108) };
                    ::dessser::gen::raql_operation::t3fbff88eef4e4c8bc42b06e5ad07ea51 letpair_res_3168;
                    {
                      auto dstring2_fst_111 { std::get<0>(id_3167) };
                      auto dstring2_snd_112 { std::get<1>(id_3167) };
                      std::string id_3169 { dstring2_fst_111.toString() };
                      std::optional<std::string> id_3170 { id_3169 };
                      ::dessser::gen::raql_operation::t3fbff88eef4e4c8bc42b06e5ad07ea51 id_3171 { id_3170, dstring2_snd_112 };
                      letpair_res_3168 = id_3171;
                    }
                    letpair_res_3166 = letpair_res_3168;
                  }
                  let_res_3165 = letpair_res_3166;
                }
                choose_res_3117 = let_res_3165;
              }
              ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 let_res_3172;
              {
                ::dessser::gen::raql_operation::t3fbff88eef4e4c8bc42b06e5ad07ea51 dtup_116 { choose_res_3117 };
                ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 letpair_res_3173;
                {
                  auto dtup_fst_117 { std::get<0>(dtup_116) };
                  auto dtup_snd_118 { std::get<1>(dtup_116) };
                  auto fun3174 { dessser::gen::function_name::of_row_binary };
                  ::dessser::gen::raql_operation::tc7d3fcfd06c0f02b3732e1754a18402b id_3175 { fun3174(dtup_snd_118) };
                  ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 letpair_res_3176;
                  {
                    auto dtup_fst_120 { std::get<0>(id_3175) };
                    auto dtup_snd_121 { std::get<1>(id_3175) };
                    ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b id_3177 { dtup_fst_99, dtup_fst_117, dtup_fst_120 };
                    ::dessser::gen::raql_operation::data_source* id_3178 { new ::dessser::gen::raql_operation::data_source(std::in_place_index<0>, id_3177) };
                    ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 id_3179 { id_3178, dtup_snd_121 };
                    letpair_res_3176 = id_3179;
                  }
                  letpair_res_3173 = letpair_res_3176;
                }
                let_res_3172 = letpair_res_3173;
              }
              letpair_res_3112 = let_res_3172;
            }
            let_res_3111 = letpair_res_3112;
          }
          choose_res_3044 = let_res_3111;
        } else {
          uint16_t id_3180 { 1 };
          bool id_3181 { bool(dsum1_fst_63 == id_3180) };
          Void id_3182 { ((void)(assert(id_3181)), VOID) };
          (void)id_3182;
          ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 id_3183 { of_row_binary(dsum1_snd_64) };
          ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 letpair_res_3184;
          {
            auto dsum2_fst_66 { std::get<0>(id_3183) };
            auto dsum2_snd_67 { std::get<1>(id_3183) };
            ::dessser::gen::raql_operation::data_source* id_3185 { new ::dessser::gen::raql_operation::data_source(std::in_place_index<1>, dsum2_fst_66) };
            ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 id_3186 { id_3185, dsum2_snd_67 };
            letpair_res_3184 = id_3186;
          }
          choose_res_3044 = letpair_res_3184;
        }
        letpair_res_3041 = choose_res_3044;
      }
      let_res_3040 = letpair_res_3041;
    }
    ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 letpair_res_3187;
    {
      auto make_fst_126 { std::get<0>(let_res_3040) };
      auto make_snd_127 { std::get<1>(let_res_3040) };
      ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 id_3188 { make_fst_126, make_snd_127 };
      letpair_res_3187 = id_3188;
    }
    return letpair_res_3187;
  }
   };
  return fun3036;
}
std::function<::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3(Pointer)> data_source_of_row_binary(data_source_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_699" "make_snd_700"
        (let "dsum1_368" (let-pair "du16_fst_363" "du16_snd_364" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_363") (identifier "du16_snd_364")))
          (let-pair "dsum1_fst_369" "dsum1_snd_370" (identifier "dsum1_368")
            (if (eq (u16 0) (identifier "dsum1_fst_369"))
              (let "drec_488"
                (let-pair "dlist4_fst_486" "dlist4_snd_487"
                  (let "dlist1_474"
                    (let "leb_ref_465" (make-vec (u32 0))
                      (let "shft_ref_466" (make-vec (u8 0))
                        (let "p_ref_467" (make-vec (identifier "dsum1_snd_370"))
                          (seq
                            (while
                              (let "leb128_468" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_467")))
                                (let-pair "leb128_fst_469" "leb128_snd_470" 
                                  (identifier "leb128_468")
                                  (seq (set-vec (u8 0) (identifier "p_ref_467") (identifier "leb128_snd_470"))
                                    (set-vec (u8 0) (identifier "leb_ref_465")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_469") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_466"))) (unsafe-nth (u8 0) (identifier "leb_ref_465"))))
                                    (set-vec (u8 0) (identifier "shft_ref_466") (add (unsafe-nth (u8 0) (identifier "shft_ref_466")) (u8 7))) 
                                    (ge (identifier "leb128_fst_469") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_465")) (unsafe-nth (u8 0) (identifier "p_ref_467")))))))
                    (let-pair "dlist1_fst_475" "dlist1_snd_476" (identifier "dlist1_474")
                      (let "inits_src_ref_477" (make-vec (make-tup (end-of-list "$raql_select_field") (identifier "dlist1_snd_476")))
                        (seq
                          (let "repeat_n_478" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_475")) (unsafe-nth (u8 0) (identifier "repeat_n_478")))
                              (seq
                                (let "dlist2_479" (unsafe-nth (u8 0) (identifier "inits_src_ref_477"))
                                  (let-pair "dlist2_fst_480" "dlist2_snd_481" 
                                    (identifier "dlist2_479")
                                    (set-vec (u8 0) (identifier "inits_src_ref_477")
                                      (let-pair "dlist3_fst_483" "dlist3_snd_484" 
                                        (apply (ext-identifier raql_select_field of-row-binary) (identifier "dlist2_snd_481"))
                                        (make-tup (cons (identifier "dlist3_fst_483") (identifier "dlist2_fst_480")) (identifier "dlist3_snd_484"))))))
                                (set-vec (u8 0) (identifier "repeat_n_478") (add (unsafe-nth (u8 0) (identifier "repeat_n_478")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_477")))))) 
                  (make-tup (identity (identifier "dlist4_fst_486")) (identifier "dlist4_snd_487")))
                (let-pair "drec_fst_489" "drec_snd_490" (identifier "drec_488")
                  (let "drec_517"
                    (if (eq (peek-u8 (identifier "drec_snd_490") (size 0)) (u8 1)) 
                      (make-tup (null "$field_name[[]]") (ptr-add (identifier "drec_snd_490") (size 1)))
                      (let-pair "dlist4_fst_512" "dlist4_snd_513"
                        (let "dlist1_500"
                          (let "leb_ref_491" (make-vec (u32 0))
                            (let "shft_ref_492" (make-vec (u8 0))
                              (let "p_ref_493" (make-vec (ptr-add (identifier "drec_snd_490") (size 1)))
                                (seq
                                  (while
                                    (let "leb128_494" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_493")))
                                      (let-pair "leb128_fst_495" "leb128_snd_496" 
                                        (identifier "leb128_494")
                                        (seq (set-vec (u8 0) (identifier "p_ref_493") (identifier "leb128_snd_496"))
                                          (set-vec (u8 0) (identifier "leb_ref_491")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_495") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_492"))) (unsafe-nth (u8 0) (identifier "leb_ref_491"))))
                                          (set-vec (u8 0) (identifier "shft_ref_492") (add (unsafe-nth (u8 0) (identifier "shft_ref_492")) (u8 7))) 
                                          (ge (identifier "leb128_fst_495") (u8 128))))) 
                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_491")) (unsafe-nth (u8 0) (identifier "p_ref_493")))))))
                          (let-pair "dlist1_fst_501" "dlist1_snd_502" 
                            (identifier "dlist1_500")
                            (let "inits_src_ref_503" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_502")))
                              (seq
                                (let "repeat_n_504" (make-vec (i32 0))
                                  (while (gt (to-i32 (identifier "dlist1_fst_501")) (unsafe-nth (u8 0) (identifier "repeat_n_504")))
                                    (seq
                                      (let "dlist2_505" (unsafe-nth (u8 0) (identifier "inits_src_ref_503"))
                                        (let-pair "dlist2_fst_506" "dlist2_snd_507" 
                                          (identifier "dlist2_505")
                                          (set-vec (u8 0) (identifier "inits_src_ref_503")
                                            (let-pair "dlist3_fst_509" "dlist3_snd_510" 
                                              (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_507"))
                                              (make-tup (cons (identifier "dlist3_fst_509") (identifier "dlist2_fst_506")) (identifier "dlist3_snd_510"))))))
                                      (set-vec (u8 0) (identifier "repeat_n_504") (add (unsafe-nth (u8 0) (identifier "repeat_n_504")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "inits_src_ref_503")))))) 
                        (make-tup (not-null (identity (identifier "dlist4_fst_512"))) (identifier "dlist4_snd_513"))))
                    (let-pair "drec_fst_518" "drec_snd_519" (identifier "drec_517")
                      (let "drec_561"
                        (if (eq (peek-u8 (identifier "drec_snd_519") (size 0)) (u8 1)) 
                          (make-tup (null "(U32; $raql_expr?; $raql_expr[[]])") (ptr-add (identifier "drec_snd_519") (size 1)))
                          (let "dtup_523" (let-pair "du32_fst_521" "du32_snd_522" (read-u32 little-endian (ptr-add (identifier "drec_snd_519") (size 1))) (make-tup (identifier "du32_fst_521") (identifier "du32_snd_522")))
                            (let-pair "dtup_fst_524" "dtup_snd_525" (identifier "dtup_523")
                              (let "dtup_529"
                                (if (eq (peek-u8 (identifier "dtup_snd_525") (size 0)) (u8 1)) 
                                  (make-tup (null "$raql_expr") (ptr-add (identifier "dtup_snd_525") (size 1)))
                                  (let-pair "make1_1_fst_527" "make1_1_snd_528" 
                                    (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "dtup_snd_525") (size 1))) 
                                    (make-tup (not-null (identifier "make1_1_fst_527")) (identifier "make1_1_snd_528"))))
                                (let-pair "dtup_fst_530" "dtup_snd_531" 
                                  (identifier "dtup_529")
                                  (let-pair "dlist4_fst_553" "dlist4_snd_554"
                                    (let "dlist1_541"
                                      (let "leb_ref_532" (make-vec (u32 0))
                                        (let "shft_ref_533" (make-vec (u8 0))
                                          (let "p_ref_534" (make-vec (identifier "dtup_snd_531"))
                                            (seq
                                              (while
                                                (let "leb128_535" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_534")))
                                                  (let-pair "leb128_fst_536" "leb128_snd_537" 
                                                    (identifier "leb128_535")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_534") (identifier "leb128_snd_537"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_532")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_536") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_533")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_532")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_533") (add (unsafe-nth (u8 0) (identifier "shft_ref_533")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_536") (u8 128))))) 
                                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_532")) (unsafe-nth (u8 0) (identifier "p_ref_534")))))))
                                      (let-pair "dlist1_fst_542" "dlist1_snd_543" 
                                        (identifier "dlist1_541")
                                        (let "inits_src_ref_544" (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_543")))
                                          (seq
                                            (let "repeat_n_545" (make-vec (i32 0))
                                              (while (gt (to-i32 (identifier "dlist1_fst_542")) (unsafe-nth (u8 0) (identifier "repeat_n_545")))
                                                (seq
                                                  (let "dlist2_546" (unsafe-nth (u8 0) (identifier "inits_src_ref_544"))
                                                    (let-pair "dlist2_fst_547" "dlist2_snd_548" 
                                                      (identifier "dlist2_546")
                                                      (set-vec (u8 0) 
                                                        (identifier "inits_src_ref_544")
                                                        (let-pair "dlist3_fst_550" "dlist3_snd_551" 
                                                          (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_548"))
                                                          (make-tup (cons (identifier "dlist3_fst_550") (identifier "dlist2_fst_547")) (identifier "dlist3_snd_551"))))))
                                                  (set-vec (u8 0) (identifier "repeat_n_545") (add (unsafe-nth (u8 0) (identifier "repeat_n_545")) (i32 1)))))) 
                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_544"))))))
                                    (make-tup (not-null (make-tup (identifier "dtup_fst_524") (identifier "dtup_fst_530") (identity (identifier "dlist4_fst_553")))) (identifier "dlist4_snd_554"))))))))
                        (let-pair "drec_fst_562" "drec_snd_563" (identifier "drec_561")
                          (let "drec_564" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_563"))
                            (let-pair "drec_fst_565" "drec_snd_566" (identifier "drec_564")
                              (let "drec_570"
                                (if (eq (peek-u8 (identifier "drec_snd_566") (size 0)) (u8 1)) 
                                  (make-tup (null "$event_time") (ptr-add (identifier "drec_snd_566") (size 1)))
                                  (let-pair "make1_1_fst_568" "make1_1_snd_569" 
                                    (apply (ext-identifier event_time of-row-binary) (ptr-add (identifier "drec_snd_566") (size 1))) 
                                    (make-tup (not-null (identifier "make1_1_fst_568")) (identifier "make1_1_snd_569"))))
                                (let-pair "drec_fst_571" "drec_snd_572" 
                                  (identifier "drec_570")
                                  (let "drec_596"
                                    (let-pair "dlist4_fst_594" "dlist4_snd_595"
                                      (let "dlist1_582"
                                        (let "leb_ref_573" (make-vec (u32 0))
                                          (let "shft_ref_574" (make-vec (u8 0))
                                            (let "p_ref_575" (make-vec (identifier "drec_snd_572"))
                                              (seq
                                                (while
                                                  (let "leb128_576" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_575")))
                                                    (let-pair "leb128_fst_577" "leb128_snd_578" 
                                                      (identifier "leb128_576")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_575") (identifier "leb128_snd_578"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_573")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_577") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_574")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_573")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_574") (add (unsafe-nth (u8 0) (identifier "shft_ref_574")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_577") (u8 128))))) 
                                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_573")) (unsafe-nth (u8 0) (identifier "p_ref_575")))))))
                                        (let-pair "dlist1_fst_583" "dlist1_snd_584" 
                                          (identifier "dlist1_582")
                                          (let "inits_src_ref_585" (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_584")))
                                            (seq
                                              (let "repeat_n_586" (make-vec (i32 0))
                                                (while (gt (to-i32 (identifier "dlist1_fst_583")) (unsafe-nth (u8 0) (identifier "repeat_n_586")))
                                                  (seq
                                                    (let "dlist2_587" 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_585"))
                                                      (let-pair "dlist2_fst_588" "dlist2_snd_589" 
                                                        (identifier "dlist2_587")
                                                        (set-vec (u8 0) 
                                                          (identifier "inits_src_ref_585")
                                                          (let-pair "dlist3_fst_591" "dlist3_snd_592" 
                                                            (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_589"))
                                                            (make-tup (cons (identifier "dlist3_fst_591") (identifier "dlist2_fst_588")) (identifier "dlist3_snd_592"))))))
                                                    (set-vec (u8 0) (identifier "repeat_n_586") (add (unsafe-nth (u8 0) (identifier "repeat_n_586")) (i32 1)))))) 
                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_585")))))) 
                                      (make-tup (identity (identifier "dlist4_fst_594")) (identifier "dlist4_snd_595")))
                                    (let-pair "drec_fst_597" "drec_snd_598" 
                                      (identifier "drec_596")
                                      (let "drec_622"
                                        (let-pair "dlist4_fst_620" "dlist4_snd_621"
                                          (let "dlist1_608"
                                            (let "leb_ref_599" (make-vec (u32 0))
                                              (let "shft_ref_600" (make-vec (u8 0))
                                                (let "p_ref_601" (make-vec (identifier "drec_snd_598"))
                                                  (seq
                                                    (while
                                                      (let "leb128_602" 
                                                        (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_601")))
                                                        (let-pair "leb128_fst_603" "leb128_snd_604" 
                                                          (identifier "leb128_602")
                                                          (seq (set-vec (u8 0) (identifier "p_ref_601") (identifier "leb128_snd_604"))
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb_ref_599")
                                                              (bit-or 
                                                                (left-shift (to-u32 (bit-and (identifier "leb128_fst_603") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_600")))
                                                                (unsafe-nth (u8 0) (identifier "leb_ref_599")))) 
                                                            (set-vec (u8 0) (identifier "shft_ref_600") (add (unsafe-nth (u8 0) (identifier "shft_ref_600")) (u8 7))) 
                                                            (ge (identifier "leb128_fst_603") (u8 128))))) 
                                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_599")) (unsafe-nth (u8 0) (identifier "p_ref_601")))))))
                                            (let-pair "dlist1_fst_609" "dlist1_snd_610" 
                                              (identifier "dlist1_608")
                                              (let "inits_src_ref_611" 
                                                (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_610")))
                                                (seq
                                                  (let "repeat_n_612" 
                                                    (make-vec (i32 0))
                                                    (while (gt (to-i32 (identifier "dlist1_fst_609")) (unsafe-nth (u8 0) (identifier "repeat_n_612")))
                                                      (seq
                                                        (let "dlist2_613" 
                                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_611"))
                                                          (let-pair "dlist2_fst_614" "dlist2_snd_615" 
                                                            (identifier "dlist2_613")
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "inits_src_ref_611")
                                                              (let-pair "dlist3_fst_617" "dlist3_snd_618" 
                                                                (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_615"))
                                                                (make-tup (cons (identifier "dlist3_fst_617") (identifier "dlist2_fst_614")) (identifier "dlist3_snd_618"))))))
                                                        (set-vec (u8 0) (identifier "repeat_n_612") (add (unsafe-nth (u8 0) (identifier "repeat_n_612")) (i32 1)))))) 
                                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_611")))))) 
                                          (make-tup (identity (identifier "dlist4_fst_620")) (identifier "dlist4_snd_621")))
                                        (let-pair "drec_fst_623" "drec_snd_624" 
                                          (identifier "drec_622")
                                          (let "drec_625" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_624"))
                                            (let-pair "drec_fst_626" "drec_snd_627" 
                                              (identifier "drec_625")
                                              (let "drec_631" (let-pair "dbool_fst_629" "dbool_snd_630" (read-u8 (identifier "drec_snd_627")) (make-tup (not (eq (identifier "dbool_fst_629") (u8 0))) (identifier "dbool_snd_630")))
                                                (let-pair "drec_fst_632" "drec_snd_633" 
                                                  (identifier "drec_631")
                                                  (let "drec_634" (apply (ext-identifier raql_flush_method of-row-binary) (identifier "drec_snd_633"))
                                                    (let-pair "drec_fst_635" "drec_snd_636" 
                                                      (identifier "drec_634")
                                                      (let "drec_660"
                                                        (let-pair "dlist4_fst_658" "dlist4_snd_659"
                                                          (let "dlist1_646"
                                                            (let "leb_ref_637" 
                                                              (make-vec (u32 0))
                                                              (let "shft_ref_638" 
                                                                (make-vec (u8 0))
                                                                (let "p_ref_639" 
                                                                  (make-vec (identifier "drec_snd_636"))
                                                                  (seq
                                                                    (while
                                                                    (let "leb128_640" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_639")))
                                                                    (let-pair "leb128_fst_641" "leb128_snd_642" 
                                                                    (identifier "leb128_640")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_639") (identifier "leb128_snd_642"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_637")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_641") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_638")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_637")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_638") (add (unsafe-nth (u8 0) (identifier "shft_ref_638")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_641") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_637")) (unsafe-nth (u8 0) (identifier "p_ref_639")))))))
                                                            (let-pair "dlist1_fst_647" "dlist1_snd_648" 
                                                              (identifier "dlist1_646")
                                                              (let "inits_src_ref_649"
                                                                (make-vec
                                                                  (make-tup 
                                                                    (end-of-list "(data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])")
                                                                    (identifier "dlist1_snd_648")))
                                                                (seq
                                                                  (let "repeat_n_650" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_647")) (unsafe-nth (u8 0) (identifier "repeat_n_650")))
                                                                    (seq
                                                                    (let "dlist2_651" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_649"))
                                                                    (let-pair "dlist2_fst_652" "dlist2_snd_653" 
                                                                    (identifier "dlist2_651")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_649")
                                                                    (let-pair "dlist3_fst_655" "dlist3_snd_656" 
                                                                    (apply (identifier "data_source-of-row-binary") (identifier "dlist2_snd_653"))
                                                                    (make-tup (cons (identifier "dlist3_fst_655") (identifier "dlist2_fst_652")) (identifier "dlist3_snd_656"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_650") (add (unsafe-nth (u8 0) (identifier "repeat_n_650")) (i32 1))))))
                                                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_649")))))) 
                                                          (make-tup (identity (identifier "dlist4_fst_658")) (identifier "dlist4_snd_659")))
                                                        (let-pair "drec_fst_661" "drec_snd_662" 
                                                          (identifier "drec_660")
                                                          (let "drec_666"
                                                            (if (eq (peek-u8 (identifier "drec_snd_662") (size 0)) (u8 1)) 
                                                              (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_662") (size 1)))
                                                              (let-pair "make1_1_fst_664" "make1_1_snd_665" 
                                                                (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_662") (size 1)))
                                                                (make-tup (not-null (identifier "make1_1_fst_664")) (identifier "make1_1_snd_665"))))
                                                            (let-pair "drec_fst_667" "drec_snd_668" 
                                                              (identifier "drec_666")
                                                              (let-pair "dlist4_fst_690" "dlist4_snd_691"
                                                                (let "dlist1_678"
                                                                  (let "leb_ref_669" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_670" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_671" 
                                                                    (make-vec (identifier "drec_snd_668"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_672" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_671")))
                                                                    (let-pair "leb128_fst_673" "leb128_snd_674" 
                                                                    (identifier "leb128_672")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_671") (identifier "leb128_snd_674"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_669")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_673") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_670")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_669")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_670") (add (unsafe-nth (u8 0) (identifier "shft_ref_670")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_673") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_669")) (unsafe-nth (u8 0) (identifier "p_ref_671")))))))
                                                                  (let-pair "dlist1_fst_679" "dlist1_snd_680" 
                                                                    (identifier "dlist1_678")
                                                                    (let "inits_src_ref_681" 
                                                                    (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_680")))
                                                                    (seq
                                                                    (let "repeat_n_682" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_679")) (unsafe-nth (u8 0) (identifier "repeat_n_682")))
                                                                    (seq
                                                                    (let "dlist2_683" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_681"))
                                                                    (let-pair "dlist2_fst_684" "dlist2_snd_685" 
                                                                    (identifier "dlist2_683")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_681")
                                                                    (let-pair "dlist3_fst_687" "dlist3_snd_688" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_685"))
                                                                    (make-tup (cons (identifier "dlist3_fst_687") (identifier "dlist2_fst_684")) (identifier "dlist3_snd_688"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_682") (add (unsafe-nth (u8 0) (identifier "repeat_n_682")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_681"))))))
                                                                (make-tup
                                                                  (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" 0
                                                                    (make-rec 
                                                                    (string "factors") 
                                                                    (identity (identifier "dlist4_fst_690")) 
                                                                    (string "every") 
                                                                    (identifier "drec_fst_667") 
                                                                    (string "from") 
                                                                    (identifier "drec_fst_661") 
                                                                    (string "flush_how") 
                                                                    (identifier "drec_fst_635") 
                                                                    (string "commit_before") 
                                                                    (identifier "drec_fst_632") 
                                                                    (string "commit_cond") 
                                                                    (identifier "drec_fst_626") 
                                                                    (string "key") 
                                                                    (identifier "drec_fst_623") 
                                                                    (string "notifications") 
                                                                    (identifier "drec_fst_597") 
                                                                    (string "event_time") 
                                                                    (identifier "drec_fst_571") 
                                                                    (string "where") 
                                                                    (identifier "drec_fst_565") 
                                                                    (string "sort") 
                                                                    (identifier "drec_fst_562") 
                                                                    (string "and_all_others") 
                                                                    (identifier "drec_fst_518") 
                                                                    (string "fields") 
                                                                    (identifier "drec_fst_489"))) 
                                                                  (identifier "dlist4_snd_691")))))))))))))))))))))))))))
              (if (eq (u16 1) (identifier "dsum1_fst_369"))
                (let "drec_424" (apply (identifier "external_source-of-row-binary") (identifier "dsum1_snd_370"))
                  (let-pair "drec_fst_425" "drec_snd_426" (identifier "drec_424")
                    (let "drec_427" (apply (identifier "external_format-of-row-binary") (identifier "drec_snd_426"))
                      (let-pair "drec_fst_428" "drec_snd_429" (identifier "drec_427")
                        (let "drec_433"
                          (if (eq (peek-u8 (identifier "drec_snd_429") (size 0)) (u8 1)) 
                            (make-tup (null "$event_time") (ptr-add (identifier "drec_snd_429") (size 1)))
                            (let-pair "make1_1_fst_431" "make1_1_snd_432" 
                              (apply (ext-identifier event_time of-row-binary) (ptr-add (identifier "drec_snd_429") (size 1))) 
                              (make-tup (not-null (identifier "make1_1_fst_431")) (identifier "make1_1_snd_432"))))
                          (let-pair "drec_fst_434" "drec_snd_435" (identifier "drec_433")
                            (let-pair "dlist4_fst_457" "dlist4_snd_458"
                              (let "dlist1_445"
                                (let "leb_ref_436" (make-vec (u32 0))
                                  (let "shft_ref_437" (make-vec (u8 0))
                                    (let "p_ref_438" (make-vec (identifier "drec_snd_435"))
                                      (seq
                                        (while
                                          (let "leb128_439" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_438")))
                                            (let-pair "leb128_fst_440" "leb128_snd_441" 
                                              (identifier "leb128_439")
                                              (seq (set-vec (u8 0) (identifier "p_ref_438") (identifier "leb128_snd_441"))
                                                (set-vec (u8 0) (identifier "leb_ref_436")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_440") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_437"))) (unsafe-nth (u8 0) (identifier "leb_ref_436"))))
                                                (set-vec (u8 0) (identifier "shft_ref_437") (add (unsafe-nth (u8 0) (identifier "shft_ref_437")) (u8 7))) 
                                                (ge (identifier "leb128_fst_440") (u8 128))))) 
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_436")) (unsafe-nth (u8 0) (identifier "p_ref_438")))))))
                                (let-pair "dlist1_fst_446" "dlist1_snd_447" 
                                  (identifier "dlist1_445")
                                  (let "inits_src_ref_448" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_447")))
                                    (seq
                                      (let "repeat_n_449" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_446")) (unsafe-nth (u8 0) (identifier "repeat_n_449")))
                                          (seq
                                            (let "dlist2_450" (unsafe-nth (u8 0) (identifier "inits_src_ref_448"))
                                              (let-pair "dlist2_fst_451" "dlist2_snd_452" 
                                                (identifier "dlist2_450")
                                                (set-vec (u8 0) (identifier "inits_src_ref_448")
                                                  (let-pair "dlist3_fst_454" "dlist3_snd_455" 
                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_452"))
                                                    (make-tup (cons (identifier "dlist3_fst_454") (identifier "dlist2_fst_451")) (identifier "dlist3_snd_455"))))))
                                            (set-vec (u8 0) (identifier "repeat_n_449") (add (unsafe-nth (u8 0) (identifier "repeat_n_449")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_448"))))))
                              (make-tup
                                (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" 1
                                  (make-rec (string "factors") (identity (identifier "dlist4_fst_457")) 
                                    (string "event_time") (identifier "drec_fst_434") 
                                    (string "format") (identifier "drec_fst_428") 
                                    (string "source") (identifier "drec_fst_425"))) 
                                (identifier "dlist4_snd_458")))))))))
                (seq (assert (eq (identifier "dsum1_fst_369") (u16 2)))
                  (let "drec_383"
                    (let "dstring1_377"
                      (let "leb_ref_371" (make-vec (u32 0))
                        (let "shft_ref_372" (make-vec (u8 0))
                          (let "p_ref_373" (make-vec (identifier "dsum1_snd_370"))
                            (seq
                              (while
                                (let "leb128_374" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_373")))
                                  (let-pair "leb128_fst_375" "leb128_snd_376" 
                                    (identifier "leb128_374")
                                    (seq (set-vec (u8 0) (identifier "p_ref_373") (identifier "leb128_snd_376"))
                                      (set-vec (u8 0) (identifier "leb_ref_371")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_375") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_372"))) (unsafe-nth (u8 0) (identifier "leb_ref_371"))))
                                      (set-vec (u8 0) (identifier "shft_ref_372") (add (unsafe-nth (u8 0) (identifier "shft_ref_372")) (u8 7))) 
                                      (ge (identifier "leb128_fst_375") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_371"))) (unsafe-nth (u8 0) (identifier "p_ref_373")))))))
                      (let-pair "dstring1_fst_378" "dstring1_snd_379" 
                        (identifier "dstring1_377")
                        (let-pair "dstring2_fst_381" "dstring2_snd_382" 
                          (read-bytes (identifier "dstring1_snd_379") (identifier "dstring1_fst_378")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_381")) (identifier "dstring2_snd_382")))))
                    (let-pair "drec_fst_384" "drec_snd_385" (identifier "drec_383")
                      (let "drec_389" (let-pair "du16_fst_387" "du16_snd_388" (read-u16 little-endian (identifier "drec_snd_385")) (make-tup (identifier "du16_fst_387") (identifier "du16_snd_388")))
                        (let-pair "drec_fst_390" "drec_snd_391" (identifier "drec_389")
                          (let "drec_392" (apply (ext-identifier raql_net_protocol of-row-binary) (identifier "drec_snd_391"))
                            (let-pair "drec_fst_393" "drec_snd_394" (identifier "drec_392")
                              (let-pair "dlist4_fst_416" "dlist4_snd_417"
                                (let "dlist1_404"
                                  (let "leb_ref_395" (make-vec (u32 0))
                                    (let "shft_ref_396" (make-vec (u8 0))
                                      (let "p_ref_397" (make-vec (identifier "drec_snd_394"))
                                        (seq
                                          (while
                                            (let "leb128_398" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_397")))
                                              (let-pair "leb128_fst_399" "leb128_snd_400" 
                                                (identifier "leb128_398")
                                                (seq (set-vec (u8 0) (identifier "p_ref_397") (identifier "leb128_snd_400"))
                                                  (set-vec (u8 0) (identifier "leb_ref_395")
                                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_399") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_396"))) (unsafe-nth (u8 0) (identifier "leb_ref_395"))))
                                                  (set-vec (u8 0) (identifier "shft_ref_396") (add (unsafe-nth (u8 0) (identifier "shft_ref_396")) (u8 7))) 
                                                  (ge (identifier "leb128_fst_399") (u8 128))))) 
                                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_395")) (unsafe-nth (u8 0) (identifier "p_ref_397")))))))
                                  (let-pair "dlist1_fst_405" "dlist1_snd_406" 
                                    (identifier "dlist1_404")
                                    (let "inits_src_ref_407" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_406")))
                                      (seq
                                        (let "repeat_n_408" (make-vec (i32 0))
                                          (while (gt (to-i32 (identifier "dlist1_fst_405")) (unsafe-nth (u8 0) (identifier "repeat_n_408")))
                                            (seq
                                              (let "dlist2_409" (unsafe-nth (u8 0) (identifier "inits_src_ref_407"))
                                                (let-pair "dlist2_fst_410" "dlist2_snd_411" 
                                                  (identifier "dlist2_409")
                                                  (set-vec (u8 0) (identifier "inits_src_ref_407")
                                                    (let-pair "dlist3_fst_413" "dlist3_snd_414" 
                                                      (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_411"))
                                                      (make-tup (cons (identifier "dlist3_fst_413") (identifier "dlist2_fst_410")) (identifier "dlist3_snd_414"))))))
                                              (set-vec (u8 0) (identifier "repeat_n_408") (add (unsafe-nth (u8 0) (identifier "repeat_n_408")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_407"))))))
                                (make-tup
                                  (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: (data_source AS [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS])[[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: (external_source AS [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]); format: (external_format AS [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]); event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" 2
                                    (make-rec (string "factors") (identity (identifier "dlist4_fst_416")) 
                                      (string "proto") (identifier "drec_fst_393") 
                                      (string "port") (identifier "drec_fst_390") 
                                      (string "net_addr") (identifier "drec_fst_384"))) 
                                  (identifier "dlist4_snd_417")))))))))))))) 
        (make-tup (identifier "make_fst_699") (identifier "make_snd_700"))))
 */
static std::function<::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018(Pointer)> fun3189 { [&fun3189](Pointer p_0) {
    ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_3190 { p_0.readU16Le() };
    ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 letpair_res_3191;
    {
      auto du16_fst_363 { std::get<0>(id_3190) };
      auto du16_snd_364 { std::get<1>(id_3190) };
      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_3192 { du16_fst_363, du16_snd_364 };
      letpair_res_3191 = id_3192;
    }
    ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3193;
    {
      ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 dsum1_368 { letpair_res_3191 };
      ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3194;
      {
        auto dsum1_fst_369 { std::get<0>(dsum1_368) };
        auto dsum1_snd_370 { std::get<1>(dsum1_368) };
        uint16_t id_3195 { 0 };
        bool id_3196 { bool(id_3195 == dsum1_fst_369) };
        ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 choose_res_3197;
        if (id_3196) {
          uint32_t id_3198 { 0U };
          Vec<1, uint32_t> id_3199 {  id_3198  };
          ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3200;
          {
            Vec<1, uint32_t> leb_ref_465 { id_3199 };
            uint8_t id_3201 { 0 };
            Vec<1, uint8_t> id_3202 {  id_3201  };
            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3203;
            {
              Vec<1, uint8_t> shft_ref_466 { id_3202 };
              Vec<1, Pointer> id_3204 {  dsum1_snd_370  };
              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3205;
              {
                Vec<1, Pointer> p_ref_467 { id_3204 };
                bool while_flag_3206 { true };
                do {
                  uint8_t id_3207 { 0 };
                  Pointer id_3208 { p_ref_467[id_3207] };
                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3209 { id_3208.readU8() };
                  bool let_res_3210;
                  {
                    ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_468 { id_3209 };
                    bool letpair_res_3211;
                    {
                      auto leb128_fst_469 { std::get<0>(leb128_468) };
                      auto leb128_snd_470 { std::get<1>(leb128_468) };
                      uint8_t id_3212 { 0 };
                      Void id_3213 { ((void)(p_ref_467[id_3212] = leb128_snd_470), VOID) };
                      (void)id_3213;
                      uint8_t id_3214 { 0 };
                      uint8_t id_3215 { 127 };
                      uint8_t id_3216 { uint8_t(leb128_fst_469 & id_3215) };
                      uint32_t id_3217 { uint32_t(id_3216) };
                      uint8_t id_3218 { 0 };
                      uint8_t id_3219 { shft_ref_466[id_3218] };
                      uint32_t id_3220 { uint32_t(id_3217 << id_3219) };
                      uint8_t id_3221 { 0 };
                      uint32_t id_3222 { leb_ref_465[id_3221] };
                      uint32_t id_3223 { uint32_t(id_3220 | id_3222) };
                      Void id_3224 { ((void)(leb_ref_465[id_3214] = id_3223), VOID) };
                      (void)id_3224;
                      uint8_t id_3225 { 0 };
                      uint8_t id_3226 { 0 };
                      uint8_t id_3227 { shft_ref_466[id_3226] };
                      uint8_t id_3228 { 7 };
                      uint8_t id_3229 { uint8_t(id_3227 + id_3228) };
                      Void id_3230 { ((void)(shft_ref_466[id_3225] = id_3229), VOID) };
                      (void)id_3230;
                      uint8_t id_3231 { 128 };
                      bool id_3232 { bool(leb128_fst_469 >= id_3231) };
                      letpair_res_3211 = id_3232;
                    }
                    let_res_3210 = letpair_res_3211;
                  }
                  while_flag_3206 = let_res_3210;
                  if (while_flag_3206) {
                    (void)VOID;
                  }
                } while (while_flag_3206);
                (void)VOID;
                uint8_t id_3233 { 0 };
                uint32_t id_3234 { leb_ref_465[id_3233] };
                uint8_t id_3235 { 0 };
                Pointer id_3236 { p_ref_467[id_3235] };
                ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3237 { id_3234, id_3236 };
                let_res_3205 = id_3237;
              }
              let_res_3203 = let_res_3205;
            }
            let_res_3200 = let_res_3203;
          }
          ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e let_res_3238;
          {
            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_474 { let_res_3200 };
            ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e letpair_res_3239;
            {
              auto dlist1_fst_475 { std::get<0>(dlist1_474) };
              auto dlist1_snd_476 { std::get<1>(dlist1_474) };
              Lst<dessser::gen::raql_select_field::t_ext> endoflist_3240;
              ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e id_3241 { endoflist_3240, dlist1_snd_476 };
              Vec<1, ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e> id_3242 {  id_3241  };
              ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e let_res_3243;
              {
                Vec<1, ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e> inits_src_ref_477 { id_3242 };
                int32_t id_3244 { 0L };
                Vec<1, int32_t> id_3245 {  id_3244  };
                {
                  Vec<1, int32_t> repeat_n_478 { id_3245 };
                  bool while_flag_3246 { true };
                  do {
                    int32_t id_3247 { int32_t(dlist1_fst_475) };
                    uint8_t id_3248 { 0 };
                    int32_t id_3249 { repeat_n_478[id_3248] };
                    bool id_3250 { bool(id_3247 > id_3249) };
                    while_flag_3246 = id_3250;
                    if (while_flag_3246) {
                      uint8_t id_3251 { 0 };
                      ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e id_3252 { inits_src_ref_477[id_3251] };
                      {
                        ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e dlist2_479 { id_3252 };
                        {
                          auto dlist2_fst_480 { std::get<0>(dlist2_479) };
                          auto dlist2_snd_481 { std::get<1>(dlist2_479) };
                          uint8_t id_3253 { 0 };
                          auto fun3254 { dessser::gen::raql_select_field::of_row_binary };
                          ::dessser::gen::raql_operation::t385fc99bd06c53216a5de778dea0dc6e id_3255 { fun3254(dlist2_snd_481) };
                          ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e letpair_res_3256;
                          {
                            auto dlist3_fst_483 { std::get<0>(id_3255) };
                            auto dlist3_snd_484 { std::get<1>(id_3255) };
                            Lst<dessser::gen::raql_select_field::t_ext> id_3257 { dlist3_fst_483, dlist2_fst_480 };
                            ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e id_3258 { id_3257, dlist3_snd_484 };
                            letpair_res_3256 = id_3258;
                          }
                          Void id_3259 { ((void)(inits_src_ref_477[id_3253] = letpair_res_3256), VOID) };
                          (void)id_3259;
                        }
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_3260 { 0 };
                      uint8_t id_3261 { 0 };
                      int32_t id_3262 { repeat_n_478[id_3261] };
                      int32_t id_3263 { 1L };
                      int32_t id_3264 { int32_t(id_3262 + id_3263) };
                      Void id_3265 { ((void)(repeat_n_478[id_3260] = id_3264), VOID) };
                      (void)id_3265;
                      (void)id_3265;
                    }
                  } while (while_flag_3246);
                  (void)VOID;
                }
                (void)VOID;
                uint8_t id_3266 { 0 };
                ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e id_3267 { inits_src_ref_477[id_3266] };
                let_res_3243 = id_3267;
              }
              letpair_res_3239 = let_res_3243;
            }
            let_res_3238 = letpair_res_3239;
          }
          ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e letpair_res_3268;
          {
            auto dlist4_fst_486 { std::get<0>(let_res_3238) };
            auto dlist4_snd_487 { std::get<1>(let_res_3238) };
            ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e id_3269 { dlist4_fst_486, dlist4_snd_487 };
            letpair_res_3268 = id_3269;
          }
          ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3270;
          {
            ::dessser::gen::raql_operation::ta9047710b0a6cdbb6cf02e2ae071242e drec_488 { letpair_res_3268 };
            ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3271;
            {
              auto drec_fst_489 { std::get<0>(drec_488) };
              auto drec_snd_490 { std::get<1>(drec_488) };
              Size id_3272 { 0UL };
              uint8_t id_3273 { drec_snd_490.peekU8(id_3272) };
              uint8_t id_3274 { 1 };
              bool id_3275 { bool(id_3273 == id_3274) };
              ::dessser::gen::raql_operation::t885b8962b524dff3368f7a529f1d466b choose_res_3276;
              if (id_3275) {
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_3277 { std::nullopt };
                Size id_3278 { 1UL };
                Pointer id_3279 { drec_snd_490.skip(id_3278) };
                ::dessser::gen::raql_operation::t885b8962b524dff3368f7a529f1d466b id_3280 { id_3277, id_3279 };
                choose_res_3276 = id_3280;
              } else {
                uint32_t id_3281 { 0U };
                Vec<1, uint32_t> id_3282 {  id_3281  };
                ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3283;
                {
                  Vec<1, uint32_t> leb_ref_491 { id_3282 };
                  uint8_t id_3284 { 0 };
                  Vec<1, uint8_t> id_3285 {  id_3284  };
                  ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3286;
                  {
                    Vec<1, uint8_t> shft_ref_492 { id_3285 };
                    Size id_3287 { 1UL };
                    Pointer id_3288 { drec_snd_490.skip(id_3287) };
                    Vec<1, Pointer> id_3289 {  id_3288  };
                    ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3290;
                    {
                      Vec<1, Pointer> p_ref_493 { id_3289 };
                      bool while_flag_3291 { true };
                      do {
                        uint8_t id_3292 { 0 };
                        Pointer id_3293 { p_ref_493[id_3292] };
                        ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3294 { id_3293.readU8() };
                        bool let_res_3295;
                        {
                          ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_494 { id_3294 };
                          bool letpair_res_3296;
                          {
                            auto leb128_fst_495 { std::get<0>(leb128_494) };
                            auto leb128_snd_496 { std::get<1>(leb128_494) };
                            uint8_t id_3297 { 0 };
                            Void id_3298 { ((void)(p_ref_493[id_3297] = leb128_snd_496), VOID) };
                            (void)id_3298;
                            uint8_t id_3299 { 0 };
                            uint8_t id_3300 { 127 };
                            uint8_t id_3301 { uint8_t(leb128_fst_495 & id_3300) };
                            uint32_t id_3302 { uint32_t(id_3301) };
                            uint8_t id_3303 { 0 };
                            uint8_t id_3304 { shft_ref_492[id_3303] };
                            uint32_t id_3305 { uint32_t(id_3302 << id_3304) };
                            uint8_t id_3306 { 0 };
                            uint32_t id_3307 { leb_ref_491[id_3306] };
                            uint32_t id_3308 { uint32_t(id_3305 | id_3307) };
                            Void id_3309 { ((void)(leb_ref_491[id_3299] = id_3308), VOID) };
                            (void)id_3309;
                            uint8_t id_3310 { 0 };
                            uint8_t id_3311 { 0 };
                            uint8_t id_3312 { shft_ref_492[id_3311] };
                            uint8_t id_3313 { 7 };
                            uint8_t id_3314 { uint8_t(id_3312 + id_3313) };
                            Void id_3315 { ((void)(shft_ref_492[id_3310] = id_3314), VOID) };
                            (void)id_3315;
                            uint8_t id_3316 { 128 };
                            bool id_3317 { bool(leb128_fst_495 >= id_3316) };
                            letpair_res_3296 = id_3317;
                          }
                          let_res_3295 = letpair_res_3296;
                        }
                        while_flag_3291 = let_res_3295;
                        if (while_flag_3291) {
                          (void)VOID;
                        }
                      } while (while_flag_3291);
                      (void)VOID;
                      uint8_t id_3318 { 0 };
                      uint32_t id_3319 { leb_ref_491[id_3318] };
                      uint8_t id_3320 { 0 };
                      Pointer id_3321 { p_ref_493[id_3320] };
                      ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3322 { id_3319, id_3321 };
                      let_res_3290 = id_3322;
                    }
                    let_res_3286 = let_res_3290;
                  }
                  let_res_3283 = let_res_3286;
                }
                ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 let_res_3323;
                {
                  ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_500 { let_res_3283 };
                  ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 letpair_res_3324;
                  {
                    auto dlist1_fst_501 { std::get<0>(dlist1_500) };
                    auto dlist1_snd_502 { std::get<1>(dlist1_500) };
                    Lst<dessser::gen::field_name::t_ext> endoflist_3325;
                    ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3326 { endoflist_3325, dlist1_snd_502 };
                    Vec<1, ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967> id_3327 {  id_3326  };
                    ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 let_res_3328;
                    {
                      Vec<1, ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967> inits_src_ref_503 { id_3327 };
                      int32_t id_3329 { 0L };
                      Vec<1, int32_t> id_3330 {  id_3329  };
                      {
                        Vec<1, int32_t> repeat_n_504 { id_3330 };
                        bool while_flag_3331 { true };
                        do {
                          int32_t id_3332 { int32_t(dlist1_fst_501) };
                          uint8_t id_3333 { 0 };
                          int32_t id_3334 { repeat_n_504[id_3333] };
                          bool id_3335 { bool(id_3332 > id_3334) };
                          while_flag_3331 = id_3335;
                          if (while_flag_3331) {
                            uint8_t id_3336 { 0 };
                            ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3337 { inits_src_ref_503[id_3336] };
                            {
                              ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 dlist2_505 { id_3337 };
                              {
                                auto dlist2_fst_506 { std::get<0>(dlist2_505) };
                                auto dlist2_snd_507 { std::get<1>(dlist2_505) };
                                uint8_t id_3338 { 0 };
                                auto fun3339 { dessser::gen::field_name::of_row_binary };
                                ::dessser::gen::raql_operation::t273a2b7978f5b466a128a51c1cc4a27b id_3340 { fun3339(dlist2_snd_507) };
                                ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 letpair_res_3341;
                                {
                                  auto dlist3_fst_509 { std::get<0>(id_3340) };
                                  auto dlist3_snd_510 { std::get<1>(id_3340) };
                                  Lst<dessser::gen::field_name::t_ext> id_3342 { dlist3_fst_509, dlist2_fst_506 };
                                  ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3343 { id_3342, dlist3_snd_510 };
                                  letpair_res_3341 = id_3343;
                                }
                                Void id_3344 { ((void)(inits_src_ref_503[id_3338] = letpair_res_3341), VOID) };
                                (void)id_3344;
                              }
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_3345 { 0 };
                            uint8_t id_3346 { 0 };
                            int32_t id_3347 { repeat_n_504[id_3346] };
                            int32_t id_3348 { 1L };
                            int32_t id_3349 { int32_t(id_3347 + id_3348) };
                            Void id_3350 { ((void)(repeat_n_504[id_3345] = id_3349), VOID) };
                            (void)id_3350;
                            (void)id_3350;
                          }
                        } while (while_flag_3331);
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_3351 { 0 };
                      ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3352 { inits_src_ref_503[id_3351] };
                      let_res_3328 = id_3352;
                    }
                    letpair_res_3324 = let_res_3328;
                  }
                  let_res_3323 = letpair_res_3324;
                }
                ::dessser::gen::raql_operation::t885b8962b524dff3368f7a529f1d466b letpair_res_3353;
                {
                  auto dlist4_fst_512 { std::get<0>(let_res_3323) };
                  auto dlist4_snd_513 { std::get<1>(let_res_3323) };
                  std::optional<Lst<dessser::gen::field_name::t_ext>> id_3354 { dlist4_fst_512 };
                  ::dessser::gen::raql_operation::t885b8962b524dff3368f7a529f1d466b id_3355 { id_3354, dlist4_snd_513 };
                  letpair_res_3353 = id_3355;
                }
                choose_res_3276 = letpair_res_3353;
              }
              ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3356;
              {
                ::dessser::gen::raql_operation::t885b8962b524dff3368f7a529f1d466b drec_517 { choose_res_3276 };
                ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3357;
                {
                  auto drec_fst_518 { std::get<0>(drec_517) };
                  auto drec_snd_519 { std::get<1>(drec_517) };
                  Size id_3358 { 0UL };
                  uint8_t id_3359 { drec_snd_519.peekU8(id_3358) };
                  uint8_t id_3360 { 1 };
                  bool id_3361 { bool(id_3359 == id_3360) };
                  ::dessser::gen::raql_operation::t87f3bb6a03f4e408df2a73622c0ea788 choose_res_3362;
                  if (id_3361) {
                    std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_3363 { std::nullopt };
                    Size id_3364 { 1UL };
                    Pointer id_3365 { drec_snd_519.skip(id_3364) };
                    ::dessser::gen::raql_operation::t87f3bb6a03f4e408df2a73622c0ea788 id_3366 { id_3363, id_3365 };
                    choose_res_3362 = id_3366;
                  } else {
                    Size id_3367 { 1UL };
                    Pointer id_3368 { drec_snd_519.skip(id_3367) };
                    ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3369 { id_3368.readU32Le() };
                    ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 letpair_res_3370;
                    {
                      auto du32_fst_521 { std::get<0>(id_3369) };
                      auto du32_snd_522 { std::get<1>(id_3369) };
                      ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3371 { du32_fst_521, du32_snd_522 };
                      letpair_res_3370 = id_3371;
                    }
                    ::dessser::gen::raql_operation::t87f3bb6a03f4e408df2a73622c0ea788 let_res_3372;
                    {
                      ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dtup_523 { letpair_res_3370 };
                      ::dessser::gen::raql_operation::t87f3bb6a03f4e408df2a73622c0ea788 letpair_res_3373;
                      {
                        auto dtup_fst_524 { std::get<0>(dtup_523) };
                        auto dtup_snd_525 { std::get<1>(dtup_523) };
                        Size id_3374 { 0UL };
                        uint8_t id_3375 { dtup_snd_525.peekU8(id_3374) };
                        uint8_t id_3376 { 1 };
                        bool id_3377 { bool(id_3375 == id_3376) };
                        ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 choose_res_3378;
                        if (id_3377) {
                          std::optional<dessser::gen::raql_expr::t_ext> id_3379 { std::nullopt };
                          Size id_3380 { 1UL };
                          Pointer id_3381 { dtup_snd_525.skip(id_3380) };
                          ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 id_3382 { id_3379, id_3381 };
                          choose_res_3378 = id_3382;
                        } else {
                          auto fun3383 { dessser::gen::raql_expr::of_row_binary };
                          Size id_3384 { 1UL };
                          Pointer id_3385 { dtup_snd_525.skip(id_3384) };
                          ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_3386 { fun3383(id_3385) };
                          ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 letpair_res_3387;
                          {
                            auto make1_1_fst_527 { std::get<0>(id_3386) };
                            auto make1_1_snd_528 { std::get<1>(id_3386) };
                            std::optional<dessser::gen::raql_expr::t_ext> id_3388 { make1_1_fst_527 };
                            ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 id_3389 { id_3388, make1_1_snd_528 };
                            letpair_res_3387 = id_3389;
                          }
                          choose_res_3378 = letpair_res_3387;
                        }
                        ::dessser::gen::raql_operation::t87f3bb6a03f4e408df2a73622c0ea788 let_res_3390;
                        {
                          ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 dtup_529 { choose_res_3378 };
                          ::dessser::gen::raql_operation::t87f3bb6a03f4e408df2a73622c0ea788 letpair_res_3391;
                          {
                            auto dtup_fst_530 { std::get<0>(dtup_529) };
                            auto dtup_snd_531 { std::get<1>(dtup_529) };
                            uint32_t id_3392 { 0U };
                            Vec<1, uint32_t> id_3393 {  id_3392  };
                            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3394;
                            {
                              Vec<1, uint32_t> leb_ref_532 { id_3393 };
                              uint8_t id_3395 { 0 };
                              Vec<1, uint8_t> id_3396 {  id_3395  };
                              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3397;
                              {
                                Vec<1, uint8_t> shft_ref_533 { id_3396 };
                                Vec<1, Pointer> id_3398 {  dtup_snd_531  };
                                ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3399;
                                {
                                  Vec<1, Pointer> p_ref_534 { id_3398 };
                                  bool while_flag_3400 { true };
                                  do {
                                    uint8_t id_3401 { 0 };
                                    Pointer id_3402 { p_ref_534[id_3401] };
                                    ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3403 { id_3402.readU8() };
                                    bool let_res_3404;
                                    {
                                      ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_535 { id_3403 };
                                      bool letpair_res_3405;
                                      {
                                        auto leb128_fst_536 { std::get<0>(leb128_535) };
                                        auto leb128_snd_537 { std::get<1>(leb128_535) };
                                        uint8_t id_3406 { 0 };
                                        Void id_3407 { ((void)(p_ref_534[id_3406] = leb128_snd_537), VOID) };
                                        (void)id_3407;
                                        uint8_t id_3408 { 0 };
                                        uint8_t id_3409 { 127 };
                                        uint8_t id_3410 { uint8_t(leb128_fst_536 & id_3409) };
                                        uint32_t id_3411 { uint32_t(id_3410) };
                                        uint8_t id_3412 { 0 };
                                        uint8_t id_3413 { shft_ref_533[id_3412] };
                                        uint32_t id_3414 { uint32_t(id_3411 << id_3413) };
                                        uint8_t id_3415 { 0 };
                                        uint32_t id_3416 { leb_ref_532[id_3415] };
                                        uint32_t id_3417 { uint32_t(id_3414 | id_3416) };
                                        Void id_3418 { ((void)(leb_ref_532[id_3408] = id_3417), VOID) };
                                        (void)id_3418;
                                        uint8_t id_3419 { 0 };
                                        uint8_t id_3420 { 0 };
                                        uint8_t id_3421 { shft_ref_533[id_3420] };
                                        uint8_t id_3422 { 7 };
                                        uint8_t id_3423 { uint8_t(id_3421 + id_3422) };
                                        Void id_3424 { ((void)(shft_ref_533[id_3419] = id_3423), VOID) };
                                        (void)id_3424;
                                        uint8_t id_3425 { 128 };
                                        bool id_3426 { bool(leb128_fst_536 >= id_3425) };
                                        letpair_res_3405 = id_3426;
                                      }
                                      let_res_3404 = letpair_res_3405;
                                    }
                                    while_flag_3400 = let_res_3404;
                                    if (while_flag_3400) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_3400);
                                  (void)VOID;
                                  uint8_t id_3427 { 0 };
                                  uint32_t id_3428 { leb_ref_532[id_3427] };
                                  uint8_t id_3429 { 0 };
                                  Pointer id_3430 { p_ref_534[id_3429] };
                                  ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3431 { id_3428, id_3430 };
                                  let_res_3399 = id_3431;
                                }
                                let_res_3397 = let_res_3399;
                              }
                              let_res_3394 = let_res_3397;
                            }
                            ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a let_res_3432;
                            {
                              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_541 { let_res_3394 };
                              ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3433;
                              {
                                auto dlist1_fst_542 { std::get<0>(dlist1_541) };
                                auto dlist1_snd_543 { std::get<1>(dlist1_541) };
                                Lst<dessser::gen::raql_expr::t_ext> endoflist_3434;
                                ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3435 { endoflist_3434, dlist1_snd_543 };
                                Vec<1, ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a> id_3436 {  id_3435  };
                                ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a let_res_3437;
                                {
                                  Vec<1, ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a> inits_src_ref_544 { id_3436 };
                                  int32_t id_3438 { 0L };
                                  Vec<1, int32_t> id_3439 {  id_3438  };
                                  {
                                    Vec<1, int32_t> repeat_n_545 { id_3439 };
                                    bool while_flag_3440 { true };
                                    do {
                                      int32_t id_3441 { int32_t(dlist1_fst_542) };
                                      uint8_t id_3442 { 0 };
                                      int32_t id_3443 { repeat_n_545[id_3442] };
                                      bool id_3444 { bool(id_3441 > id_3443) };
                                      while_flag_3440 = id_3444;
                                      if (while_flag_3440) {
                                        uint8_t id_3445 { 0 };
                                        ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3446 { inits_src_ref_544[id_3445] };
                                        {
                                          ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a dlist2_546 { id_3446 };
                                          {
                                            auto dlist2_fst_547 { std::get<0>(dlist2_546) };
                                            auto dlist2_snd_548 { std::get<1>(dlist2_546) };
                                            uint8_t id_3447 { 0 };
                                            auto fun3448 { dessser::gen::raql_expr::of_row_binary };
                                            ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_3449 { fun3448(dlist2_snd_548) };
                                            ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3450;
                                            {
                                              auto dlist3_fst_550 { std::get<0>(id_3449) };
                                              auto dlist3_snd_551 { std::get<1>(id_3449) };
                                              Lst<dessser::gen::raql_expr::t_ext> id_3451 { dlist3_fst_550, dlist2_fst_547 };
                                              ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3452 { id_3451, dlist3_snd_551 };
                                              letpair_res_3450 = id_3452;
                                            }
                                            Void id_3453 { ((void)(inits_src_ref_544[id_3447] = letpair_res_3450), VOID) };
                                            (void)id_3453;
                                          }
                                          (void)VOID;
                                        }
                                        (void)VOID;
                                        uint8_t id_3454 { 0 };
                                        uint8_t id_3455 { 0 };
                                        int32_t id_3456 { repeat_n_545[id_3455] };
                                        int32_t id_3457 { 1L };
                                        int32_t id_3458 { int32_t(id_3456 + id_3457) };
                                        Void id_3459 { ((void)(repeat_n_545[id_3454] = id_3458), VOID) };
                                        (void)id_3459;
                                        (void)id_3459;
                                      }
                                    } while (while_flag_3440);
                                    (void)VOID;
                                  }
                                  (void)VOID;
                                  uint8_t id_3460 { 0 };
                                  ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3461 { inits_src_ref_544[id_3460] };
                                  let_res_3437 = id_3461;
                                }
                                letpair_res_3433 = let_res_3437;
                              }
                              let_res_3432 = letpair_res_3433;
                            }
                            ::dessser::gen::raql_operation::t87f3bb6a03f4e408df2a73622c0ea788 letpair_res_3462;
                            {
                              auto dlist4_fst_553 { std::get<0>(let_res_3432) };
                              auto dlist4_snd_554 { std::get<1>(let_res_3432) };
                              ::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab id_3463 { dtup_fst_524, dtup_fst_530, dlist4_fst_553 };
                              std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> id_3464 { id_3463 };
                              ::dessser::gen::raql_operation::t87f3bb6a03f4e408df2a73622c0ea788 id_3465 { id_3464, dlist4_snd_554 };
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
                  ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3466;
                  {
                    ::dessser::gen::raql_operation::t87f3bb6a03f4e408df2a73622c0ea788 drec_561 { choose_res_3362 };
                    ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3467;
                    {
                      auto drec_fst_562 { std::get<0>(drec_561) };
                      auto drec_snd_563 { std::get<1>(drec_561) };
                      auto fun3468 { dessser::gen::raql_expr::of_row_binary };
                      ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_3469 { fun3468(drec_snd_563) };
                      ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3470;
                      {
                        ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac drec_564 { id_3469 };
                        ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3471;
                        {
                          auto drec_fst_565 { std::get<0>(drec_564) };
                          auto drec_snd_566 { std::get<1>(drec_564) };
                          Size id_3472 { 0UL };
                          uint8_t id_3473 { drec_snd_566.peekU8(id_3472) };
                          uint8_t id_3474 { 1 };
                          bool id_3475 { bool(id_3473 == id_3474) };
                          ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 choose_res_3476;
                          if (id_3475) {
                            std::optional<dessser::gen::event_time::t_ext> id_3477 { std::nullopt };
                            Size id_3478 { 1UL };
                            Pointer id_3479 { drec_snd_566.skip(id_3478) };
                            ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 id_3480 { id_3477, id_3479 };
                            choose_res_3476 = id_3480;
                          } else {
                            auto fun3481 { dessser::gen::event_time::of_row_binary };
                            Size id_3482 { 1UL };
                            Pointer id_3483 { drec_snd_566.skip(id_3482) };
                            ::dessser::gen::raql_operation::te8ff255b34432f8503a86cf675cbafe6 id_3484 { fun3481(id_3483) };
                            ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 letpair_res_3485;
                            {
                              auto make1_1_fst_568 { std::get<0>(id_3484) };
                              auto make1_1_snd_569 { std::get<1>(id_3484) };
                              std::optional<dessser::gen::event_time::t_ext> id_3486 { make1_1_fst_568 };
                              ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 id_3487 { id_3486, make1_1_snd_569 };
                              letpair_res_3485 = id_3487;
                            }
                            choose_res_3476 = letpair_res_3485;
                          }
                          ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3488;
                          {
                            ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 drec_570 { choose_res_3476 };
                            ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3489;
                            {
                              auto drec_fst_571 { std::get<0>(drec_570) };
                              auto drec_snd_572 { std::get<1>(drec_570) };
                              uint32_t id_3490 { 0U };
                              Vec<1, uint32_t> id_3491 {  id_3490  };
                              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3492;
                              {
                                Vec<1, uint32_t> leb_ref_573 { id_3491 };
                                uint8_t id_3493 { 0 };
                                Vec<1, uint8_t> id_3494 {  id_3493  };
                                ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3495;
                                {
                                  Vec<1, uint8_t> shft_ref_574 { id_3494 };
                                  Vec<1, Pointer> id_3496 {  drec_snd_572  };
                                  ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3497;
                                  {
                                    Vec<1, Pointer> p_ref_575 { id_3496 };
                                    bool while_flag_3498 { true };
                                    do {
                                      uint8_t id_3499 { 0 };
                                      Pointer id_3500 { p_ref_575[id_3499] };
                                      ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3501 { id_3500.readU8() };
                                      bool let_res_3502;
                                      {
                                        ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_576 { id_3501 };
                                        bool letpair_res_3503;
                                        {
                                          auto leb128_fst_577 { std::get<0>(leb128_576) };
                                          auto leb128_snd_578 { std::get<1>(leb128_576) };
                                          uint8_t id_3504 { 0 };
                                          Void id_3505 { ((void)(p_ref_575[id_3504] = leb128_snd_578), VOID) };
                                          (void)id_3505;
                                          uint8_t id_3506 { 0 };
                                          uint8_t id_3507 { 127 };
                                          uint8_t id_3508 { uint8_t(leb128_fst_577 & id_3507) };
                                          uint32_t id_3509 { uint32_t(id_3508) };
                                          uint8_t id_3510 { 0 };
                                          uint8_t id_3511 { shft_ref_574[id_3510] };
                                          uint32_t id_3512 { uint32_t(id_3509 << id_3511) };
                                          uint8_t id_3513 { 0 };
                                          uint32_t id_3514 { leb_ref_573[id_3513] };
                                          uint32_t id_3515 { uint32_t(id_3512 | id_3514) };
                                          Void id_3516 { ((void)(leb_ref_573[id_3506] = id_3515), VOID) };
                                          (void)id_3516;
                                          uint8_t id_3517 { 0 };
                                          uint8_t id_3518 { 0 };
                                          uint8_t id_3519 { shft_ref_574[id_3518] };
                                          uint8_t id_3520 { 7 };
                                          uint8_t id_3521 { uint8_t(id_3519 + id_3520) };
                                          Void id_3522 { ((void)(shft_ref_574[id_3517] = id_3521), VOID) };
                                          (void)id_3522;
                                          uint8_t id_3523 { 128 };
                                          bool id_3524 { bool(leb128_fst_577 >= id_3523) };
                                          letpair_res_3503 = id_3524;
                                        }
                                        let_res_3502 = letpair_res_3503;
                                      }
                                      while_flag_3498 = let_res_3502;
                                      if (while_flag_3498) {
                                        (void)VOID;
                                      }
                                    } while (while_flag_3498);
                                    (void)VOID;
                                    uint8_t id_3525 { 0 };
                                    uint32_t id_3526 { leb_ref_573[id_3525] };
                                    uint8_t id_3527 { 0 };
                                    Pointer id_3528 { p_ref_575[id_3527] };
                                    ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3529 { id_3526, id_3528 };
                                    let_res_3497 = id_3529;
                                  }
                                  let_res_3495 = let_res_3497;
                                }
                                let_res_3492 = let_res_3495;
                              }
                              ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a let_res_3530;
                              {
                                ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_582 { let_res_3492 };
                                ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3531;
                                {
                                  auto dlist1_fst_583 { std::get<0>(dlist1_582) };
                                  auto dlist1_snd_584 { std::get<1>(dlist1_582) };
                                  Lst<dessser::gen::raql_expr::t_ext> endoflist_3532;
                                  ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3533 { endoflist_3532, dlist1_snd_584 };
                                  Vec<1, ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a> id_3534 {  id_3533  };
                                  ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a let_res_3535;
                                  {
                                    Vec<1, ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a> inits_src_ref_585 { id_3534 };
                                    int32_t id_3536 { 0L };
                                    Vec<1, int32_t> id_3537 {  id_3536  };
                                    {
                                      Vec<1, int32_t> repeat_n_586 { id_3537 };
                                      bool while_flag_3538 { true };
                                      do {
                                        int32_t id_3539 { int32_t(dlist1_fst_583) };
                                        uint8_t id_3540 { 0 };
                                        int32_t id_3541 { repeat_n_586[id_3540] };
                                        bool id_3542 { bool(id_3539 > id_3541) };
                                        while_flag_3538 = id_3542;
                                        if (while_flag_3538) {
                                          uint8_t id_3543 { 0 };
                                          ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3544 { inits_src_ref_585[id_3543] };
                                          {
                                            ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a dlist2_587 { id_3544 };
                                            {
                                              auto dlist2_fst_588 { std::get<0>(dlist2_587) };
                                              auto dlist2_snd_589 { std::get<1>(dlist2_587) };
                                              uint8_t id_3545 { 0 };
                                              auto fun3546 { dessser::gen::raql_expr::of_row_binary };
                                              ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_3547 { fun3546(dlist2_snd_589) };
                                              ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3548;
                                              {
                                                auto dlist3_fst_591 { std::get<0>(id_3547) };
                                                auto dlist3_snd_592 { std::get<1>(id_3547) };
                                                Lst<dessser::gen::raql_expr::t_ext> id_3549 { dlist3_fst_591, dlist2_fst_588 };
                                                ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3550 { id_3549, dlist3_snd_592 };
                                                letpair_res_3548 = id_3550;
                                              }
                                              Void id_3551 { ((void)(inits_src_ref_585[id_3545] = letpair_res_3548), VOID) };
                                              (void)id_3551;
                                            }
                                            (void)VOID;
                                          }
                                          (void)VOID;
                                          uint8_t id_3552 { 0 };
                                          uint8_t id_3553 { 0 };
                                          int32_t id_3554 { repeat_n_586[id_3553] };
                                          int32_t id_3555 { 1L };
                                          int32_t id_3556 { int32_t(id_3554 + id_3555) };
                                          Void id_3557 { ((void)(repeat_n_586[id_3552] = id_3556), VOID) };
                                          (void)id_3557;
                                          (void)id_3557;
                                        }
                                      } while (while_flag_3538);
                                      (void)VOID;
                                    }
                                    (void)VOID;
                                    uint8_t id_3558 { 0 };
                                    ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3559 { inits_src_ref_585[id_3558] };
                                    let_res_3535 = id_3559;
                                  }
                                  letpair_res_3531 = let_res_3535;
                                }
                                let_res_3530 = letpair_res_3531;
                              }
                              ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3560;
                              {
                                auto dlist4_fst_594 { std::get<0>(let_res_3530) };
                                auto dlist4_snd_595 { std::get<1>(let_res_3530) };
                                ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3561 { dlist4_fst_594, dlist4_snd_595 };
                                letpair_res_3560 = id_3561;
                              }
                              ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3562;
                              {
                                ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a drec_596 { letpair_res_3560 };
                                ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3563;
                                {
                                  auto drec_fst_597 { std::get<0>(drec_596) };
                                  auto drec_snd_598 { std::get<1>(drec_596) };
                                  uint32_t id_3564 { 0U };
                                  Vec<1, uint32_t> id_3565 {  id_3564  };
                                  ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3566;
                                  {
                                    Vec<1, uint32_t> leb_ref_599 { id_3565 };
                                    uint8_t id_3567 { 0 };
                                    Vec<1, uint8_t> id_3568 {  id_3567  };
                                    ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3569;
                                    {
                                      Vec<1, uint8_t> shft_ref_600 { id_3568 };
                                      Vec<1, Pointer> id_3570 {  drec_snd_598  };
                                      ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3571;
                                      {
                                        Vec<1, Pointer> p_ref_601 { id_3570 };
                                        bool while_flag_3572 { true };
                                        do {
                                          uint8_t id_3573 { 0 };
                                          Pointer id_3574 { p_ref_601[id_3573] };
                                          ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3575 { id_3574.readU8() };
                                          bool let_res_3576;
                                          {
                                            ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_602 { id_3575 };
                                            bool letpair_res_3577;
                                            {
                                              auto leb128_fst_603 { std::get<0>(leb128_602) };
                                              auto leb128_snd_604 { std::get<1>(leb128_602) };
                                              uint8_t id_3578 { 0 };
                                              Void id_3579 { ((void)(p_ref_601[id_3578] = leb128_snd_604), VOID) };
                                              (void)id_3579;
                                              uint8_t id_3580 { 0 };
                                              uint8_t id_3581 { 127 };
                                              uint8_t id_3582 { uint8_t(leb128_fst_603 & id_3581) };
                                              uint32_t id_3583 { uint32_t(id_3582) };
                                              uint8_t id_3584 { 0 };
                                              uint8_t id_3585 { shft_ref_600[id_3584] };
                                              uint32_t id_3586 { uint32_t(id_3583 << id_3585) };
                                              uint8_t id_3587 { 0 };
                                              uint32_t id_3588 { leb_ref_599[id_3587] };
                                              uint32_t id_3589 { uint32_t(id_3586 | id_3588) };
                                              Void id_3590 { ((void)(leb_ref_599[id_3580] = id_3589), VOID) };
                                              (void)id_3590;
                                              uint8_t id_3591 { 0 };
                                              uint8_t id_3592 { 0 };
                                              uint8_t id_3593 { shft_ref_600[id_3592] };
                                              uint8_t id_3594 { 7 };
                                              uint8_t id_3595 { uint8_t(id_3593 + id_3594) };
                                              Void id_3596 { ((void)(shft_ref_600[id_3591] = id_3595), VOID) };
                                              (void)id_3596;
                                              uint8_t id_3597 { 128 };
                                              bool id_3598 { bool(leb128_fst_603 >= id_3597) };
                                              letpair_res_3577 = id_3598;
                                            }
                                            let_res_3576 = letpair_res_3577;
                                          }
                                          while_flag_3572 = let_res_3576;
                                          if (while_flag_3572) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_3572);
                                        (void)VOID;
                                        uint8_t id_3599 { 0 };
                                        uint32_t id_3600 { leb_ref_599[id_3599] };
                                        uint8_t id_3601 { 0 };
                                        Pointer id_3602 { p_ref_601[id_3601] };
                                        ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3603 { id_3600, id_3602 };
                                        let_res_3571 = id_3603;
                                      }
                                      let_res_3569 = let_res_3571;
                                    }
                                    let_res_3566 = let_res_3569;
                                  }
                                  ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a let_res_3604;
                                  {
                                    ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_608 { let_res_3566 };
                                    ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3605;
                                    {
                                      auto dlist1_fst_609 { std::get<0>(dlist1_608) };
                                      auto dlist1_snd_610 { std::get<1>(dlist1_608) };
                                      Lst<dessser::gen::raql_expr::t_ext> endoflist_3606;
                                      ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3607 { endoflist_3606, dlist1_snd_610 };
                                      Vec<1, ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a> id_3608 {  id_3607  };
                                      ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a let_res_3609;
                                      {
                                        Vec<1, ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a> inits_src_ref_611 { id_3608 };
                                        int32_t id_3610 { 0L };
                                        Vec<1, int32_t> id_3611 {  id_3610  };
                                        {
                                          Vec<1, int32_t> repeat_n_612 { id_3611 };
                                          bool while_flag_3612 { true };
                                          do {
                                            int32_t id_3613 { int32_t(dlist1_fst_609) };
                                            uint8_t id_3614 { 0 };
                                            int32_t id_3615 { repeat_n_612[id_3614] };
                                            bool id_3616 { bool(id_3613 > id_3615) };
                                            while_flag_3612 = id_3616;
                                            if (while_flag_3612) {
                                              uint8_t id_3617 { 0 };
                                              ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3618 { inits_src_ref_611[id_3617] };
                                              {
                                                ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a dlist2_613 { id_3618 };
                                                {
                                                  auto dlist2_fst_614 { std::get<0>(dlist2_613) };
                                                  auto dlist2_snd_615 { std::get<1>(dlist2_613) };
                                                  uint8_t id_3619 { 0 };
                                                  auto fun3620 { dessser::gen::raql_expr::of_row_binary };
                                                  ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_3621 { fun3620(dlist2_snd_615) };
                                                  ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3622;
                                                  {
                                                    auto dlist3_fst_617 { std::get<0>(id_3621) };
                                                    auto dlist3_snd_618 { std::get<1>(id_3621) };
                                                    Lst<dessser::gen::raql_expr::t_ext> id_3623 { dlist3_fst_617, dlist2_fst_614 };
                                                    ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3624 { id_3623, dlist3_snd_618 };
                                                    letpair_res_3622 = id_3624;
                                                  }
                                                  Void id_3625 { ((void)(inits_src_ref_611[id_3619] = letpair_res_3622), VOID) };
                                                  (void)id_3625;
                                                }
                                                (void)VOID;
                                              }
                                              (void)VOID;
                                              uint8_t id_3626 { 0 };
                                              uint8_t id_3627 { 0 };
                                              int32_t id_3628 { repeat_n_612[id_3627] };
                                              int32_t id_3629 { 1L };
                                              int32_t id_3630 { int32_t(id_3628 + id_3629) };
                                              Void id_3631 { ((void)(repeat_n_612[id_3626] = id_3630), VOID) };
                                              (void)id_3631;
                                              (void)id_3631;
                                            }
                                          } while (while_flag_3612);
                                          (void)VOID;
                                        }
                                        (void)VOID;
                                        uint8_t id_3632 { 0 };
                                        ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3633 { inits_src_ref_611[id_3632] };
                                        let_res_3609 = id_3633;
                                      }
                                      letpair_res_3605 = let_res_3609;
                                    }
                                    let_res_3604 = letpair_res_3605;
                                  }
                                  ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3634;
                                  {
                                    auto dlist4_fst_620 { std::get<0>(let_res_3604) };
                                    auto dlist4_snd_621 { std::get<1>(let_res_3604) };
                                    ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a id_3635 { dlist4_fst_620, dlist4_snd_621 };
                                    letpair_res_3634 = id_3635;
                                  }
                                  ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3636;
                                  {
                                    ::dessser::gen::raql_operation::t0067a338c0fc91b6a811c8df70d4c87a drec_622 { letpair_res_3634 };
                                    ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3637;
                                    {
                                      auto drec_fst_623 { std::get<0>(drec_622) };
                                      auto drec_snd_624 { std::get<1>(drec_622) };
                                      auto fun3638 { dessser::gen::raql_expr::of_row_binary };
                                      ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_3639 { fun3638(drec_snd_624) };
                                      ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3640;
                                      {
                                        ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac drec_625 { id_3639 };
                                        ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3641;
                                        {
                                          auto drec_fst_626 { std::get<0>(drec_625) };
                                          auto drec_snd_627 { std::get<1>(drec_625) };
                                          ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3642 { drec_snd_627.readU8() };
                                          ::dessser::gen::raql_operation::t4138de986e20d18b01e4c493dc9d5451 letpair_res_3643;
                                          {
                                            auto dbool_fst_629 { std::get<0>(id_3642) };
                                            auto dbool_snd_630 { std::get<1>(id_3642) };
                                            uint8_t id_3644 { 0 };
                                            bool id_3645 { bool(dbool_fst_629 == id_3644) };
                                            bool id_3646 { ! id_3645 };
                                            ::dessser::gen::raql_operation::t4138de986e20d18b01e4c493dc9d5451 id_3647 { id_3646, dbool_snd_630 };
                                            letpair_res_3643 = id_3647;
                                          }
                                          ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3648;
                                          {
                                            ::dessser::gen::raql_operation::t4138de986e20d18b01e4c493dc9d5451 drec_631 { letpair_res_3643 };
                                            ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3649;
                                            {
                                              auto drec_fst_632 { std::get<0>(drec_631) };
                                              auto drec_snd_633 { std::get<1>(drec_631) };
                                              auto fun3650 { dessser::gen::raql_flush_method::of_row_binary };
                                              ::dessser::gen::raql_operation::t01507690afb11d3b148862b712bad5a5 id_3651 { fun3650(drec_snd_633) };
                                              ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3652;
                                              {
                                                ::dessser::gen::raql_operation::t01507690afb11d3b148862b712bad5a5 drec_634 { id_3651 };
                                                ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3653;
                                                {
                                                  auto drec_fst_635 { std::get<0>(drec_634) };
                                                  auto drec_snd_636 { std::get<1>(drec_634) };
                                                  uint32_t id_3654 { 0U };
                                                  Vec<1, uint32_t> id_3655 {  id_3654  };
                                                  ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3656;
                                                  {
                                                    Vec<1, uint32_t> leb_ref_637 { id_3655 };
                                                    uint8_t id_3657 { 0 };
                                                    Vec<1, uint8_t> id_3658 {  id_3657  };
                                                    ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3659;
                                                    {
                                                      Vec<1, uint8_t> shft_ref_638 { id_3658 };
                                                      Vec<1, Pointer> id_3660 {  drec_snd_636  };
                                                      ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3661;
                                                      {
                                                        Vec<1, Pointer> p_ref_639 { id_3660 };
                                                        bool while_flag_3662 { true };
                                                        do {
                                                          uint8_t id_3663 { 0 };
                                                          Pointer id_3664 { p_ref_639[id_3663] };
                                                          ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3665 { id_3664.readU8() };
                                                          bool let_res_3666;
                                                          {
                                                            ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_640 { id_3665 };
                                                            bool letpair_res_3667;
                                                            {
                                                              auto leb128_fst_641 { std::get<0>(leb128_640) };
                                                              auto leb128_snd_642 { std::get<1>(leb128_640) };
                                                              uint8_t id_3668 { 0 };
                                                              Void id_3669 { ((void)(p_ref_639[id_3668] = leb128_snd_642), VOID) };
                                                              (void)id_3669;
                                                              uint8_t id_3670 { 0 };
                                                              uint8_t id_3671 { 127 };
                                                              uint8_t id_3672 { uint8_t(leb128_fst_641 & id_3671) };
                                                              uint32_t id_3673 { uint32_t(id_3672) };
                                                              uint8_t id_3674 { 0 };
                                                              uint8_t id_3675 { shft_ref_638[id_3674] };
                                                              uint32_t id_3676 { uint32_t(id_3673 << id_3675) };
                                                              uint8_t id_3677 { 0 };
                                                              uint32_t id_3678 { leb_ref_637[id_3677] };
                                                              uint32_t id_3679 { uint32_t(id_3676 | id_3678) };
                                                              Void id_3680 { ((void)(leb_ref_637[id_3670] = id_3679), VOID) };
                                                              (void)id_3680;
                                                              uint8_t id_3681 { 0 };
                                                              uint8_t id_3682 { 0 };
                                                              uint8_t id_3683 { shft_ref_638[id_3682] };
                                                              uint8_t id_3684 { 7 };
                                                              uint8_t id_3685 { uint8_t(id_3683 + id_3684) };
                                                              Void id_3686 { ((void)(shft_ref_638[id_3681] = id_3685), VOID) };
                                                              (void)id_3686;
                                                              uint8_t id_3687 { 128 };
                                                              bool id_3688 { bool(leb128_fst_641 >= id_3687) };
                                                              letpair_res_3667 = id_3688;
                                                            }
                                                            let_res_3666 = letpair_res_3667;
                                                          }
                                                          while_flag_3662 = let_res_3666;
                                                          if (while_flag_3662) {
                                                            (void)VOID;
                                                          }
                                                        } while (while_flag_3662);
                                                        (void)VOID;
                                                        uint8_t id_3689 { 0 };
                                                        uint32_t id_3690 { leb_ref_637[id_3689] };
                                                        uint8_t id_3691 { 0 };
                                                        Pointer id_3692 { p_ref_639[id_3691] };
                                                        ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3693 { id_3690, id_3692 };
                                                        let_res_3661 = id_3693;
                                                      }
                                                      let_res_3659 = let_res_3661;
                                                    }
                                                    let_res_3656 = let_res_3659;
                                                  }
                                                  ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d let_res_3694;
                                                  {
                                                    ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_646 { let_res_3656 };
                                                    ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d letpair_res_3695;
                                                    {
                                                      auto dlist1_fst_647 { std::get<0>(dlist1_646) };
                                                      auto dlist1_snd_648 { std::get<1>(dlist1_646) };
                                                      Lst<::dessser::gen::raql_operation::data_source*> endoflist_3696;
                                                      ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d id_3697 { endoflist_3696, dlist1_snd_648 };
                                                      Vec<1, ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d> id_3698 {  id_3697  };
                                                      ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d let_res_3699;
                                                      {
                                                        Vec<1, ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d> inits_src_ref_649 { id_3698 };
                                                        int32_t id_3700 { 0L };
                                                        Vec<1, int32_t> id_3701 {  id_3700  };
                                                        {
                                                          Vec<1, int32_t> repeat_n_650 { id_3701 };
                                                          bool while_flag_3702 { true };
                                                          do {
                                                            int32_t id_3703 { int32_t(dlist1_fst_647) };
                                                            uint8_t id_3704 { 0 };
                                                            int32_t id_3705 { repeat_n_650[id_3704] };
                                                            bool id_3706 { bool(id_3703 > id_3705) };
                                                            while_flag_3702 = id_3706;
                                                            if (while_flag_3702) {
                                                              uint8_t id_3707 { 0 };
                                                              ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d id_3708 { inits_src_ref_649[id_3707] };
                                                              {
                                                                ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d dlist2_651 { id_3708 };
                                                                {
                                                                  auto dlist2_fst_652 { std::get<0>(dlist2_651) };
                                                                  auto dlist2_snd_653 { std::get<1>(dlist2_651) };
                                                                  uint8_t id_3709 { 0 };
                                                                  ::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3 id_3710 { data_source_of_row_binary(dlist2_snd_653) };
                                                                  ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d letpair_res_3711;
                                                                  {
                                                                    auto dlist3_fst_655 { std::get<0>(id_3710) };
                                                                    auto dlist3_snd_656 { std::get<1>(id_3710) };
                                                                    Lst<::dessser::gen::raql_operation::data_source*> id_3712 { dlist3_fst_655, dlist2_fst_652 };
                                                                    ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d id_3713 { id_3712, dlist3_snd_656 };
                                                                    letpair_res_3711 = id_3713;
                                                                  }
                                                                  Void id_3714 { ((void)(inits_src_ref_649[id_3709] = letpair_res_3711), VOID) };
                                                                  (void)id_3714;
                                                                }
                                                                (void)VOID;
                                                              }
                                                              (void)VOID;
                                                              uint8_t id_3715 { 0 };
                                                              uint8_t id_3716 { 0 };
                                                              int32_t id_3717 { repeat_n_650[id_3716] };
                                                              int32_t id_3718 { 1L };
                                                              int32_t id_3719 { int32_t(id_3717 + id_3718) };
                                                              Void id_3720 { ((void)(repeat_n_650[id_3715] = id_3719), VOID) };
                                                              (void)id_3720;
                                                              (void)id_3720;
                                                            }
                                                          } while (while_flag_3702);
                                                          (void)VOID;
                                                        }
                                                        (void)VOID;
                                                        uint8_t id_3721 { 0 };
                                                        ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d id_3722 { inits_src_ref_649[id_3721] };
                                                        let_res_3699 = id_3722;
                                                      }
                                                      letpair_res_3695 = let_res_3699;
                                                    }
                                                    let_res_3694 = letpair_res_3695;
                                                  }
                                                  ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d letpair_res_3723;
                                                  {
                                                    auto dlist4_fst_658 { std::get<0>(let_res_3694) };
                                                    auto dlist4_snd_659 { std::get<1>(let_res_3694) };
                                                    ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d id_3724 { dlist4_fst_658, dlist4_snd_659 };
                                                    letpair_res_3723 = id_3724;
                                                  }
                                                  ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3725;
                                                  {
                                                    ::dessser::gen::raql_operation::t189f4c78595b5c6595a039b832db352d drec_660 { letpair_res_3723 };
                                                    ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3726;
                                                    {
                                                      auto drec_fst_661 { std::get<0>(drec_660) };
                                                      auto drec_snd_662 { std::get<1>(drec_660) };
                                                      Size id_3727 { 0UL };
                                                      uint8_t id_3728 { drec_snd_662.peekU8(id_3727) };
                                                      uint8_t id_3729 { 1 };
                                                      bool id_3730 { bool(id_3728 == id_3729) };
                                                      ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 choose_res_3731;
                                                      if (id_3730) {
                                                        std::optional<dessser::gen::raql_expr::t_ext> id_3732 { std::nullopt };
                                                        Size id_3733 { 1UL };
                                                        Pointer id_3734 { drec_snd_662.skip(id_3733) };
                                                        ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 id_3735 { id_3732, id_3734 };
                                                        choose_res_3731 = id_3735;
                                                      } else {
                                                        auto fun3736 { dessser::gen::raql_expr::of_row_binary };
                                                        Size id_3737 { 1UL };
                                                        Pointer id_3738 { drec_snd_662.skip(id_3737) };
                                                        ::dessser::gen::raql_operation::t1113e6691818baaf60a775527f6cc1ac id_3739 { fun3736(id_3738) };
                                                        ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 letpair_res_3740;
                                                        {
                                                          auto make1_1_fst_664 { std::get<0>(id_3739) };
                                                          auto make1_1_snd_665 { std::get<1>(id_3739) };
                                                          std::optional<dessser::gen::raql_expr::t_ext> id_3741 { make1_1_fst_664 };
                                                          ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 id_3742 { id_3741, make1_1_snd_665 };
                                                          letpair_res_3740 = id_3742;
                                                        }
                                                        choose_res_3731 = letpair_res_3740;
                                                      }
                                                      ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3743;
                                                      {
                                                        ::dessser::gen::raql_operation::tf1063a6af8c1fb72f0e0ee089d43d040 drec_666 { choose_res_3731 };
                                                        ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3744;
                                                        {
                                                          auto drec_fst_667 { std::get<0>(drec_666) };
                                                          auto drec_snd_668 { std::get<1>(drec_666) };
                                                          uint32_t id_3745 { 0U };
                                                          Vec<1, uint32_t> id_3746 {  id_3745  };
                                                          ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3747;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_669 { id_3746 };
                                                            uint8_t id_3748 { 0 };
                                                            Vec<1, uint8_t> id_3749 {  id_3748  };
                                                            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3750;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_670 { id_3749 };
                                                              Vec<1, Pointer> id_3751 {  drec_snd_668  };
                                                              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3752;
                                                              {
                                                                Vec<1, Pointer> p_ref_671 { id_3751 };
                                                                bool while_flag_3753 { true };
                                                                do {
                                                                  uint8_t id_3754 { 0 };
                                                                  Pointer id_3755 { p_ref_671[id_3754] };
                                                                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3756 { id_3755.readU8() };
                                                                  bool let_res_3757;
                                                                  {
                                                                    ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_672 { id_3756 };
                                                                    bool letpair_res_3758;
                                                                    {
                                                                      auto leb128_fst_673 { std::get<0>(leb128_672) };
                                                                      auto leb128_snd_674 { std::get<1>(leb128_672) };
                                                                      uint8_t id_3759 { 0 };
                                                                      Void id_3760 { ((void)(p_ref_671[id_3759] = leb128_snd_674), VOID) };
                                                                      (void)id_3760;
                                                                      uint8_t id_3761 { 0 };
                                                                      uint8_t id_3762 { 127 };
                                                                      uint8_t id_3763 { uint8_t(leb128_fst_673 & id_3762) };
                                                                      uint32_t id_3764 { uint32_t(id_3763) };
                                                                      uint8_t id_3765 { 0 };
                                                                      uint8_t id_3766 { shft_ref_670[id_3765] };
                                                                      uint32_t id_3767 { uint32_t(id_3764 << id_3766) };
                                                                      uint8_t id_3768 { 0 };
                                                                      uint32_t id_3769 { leb_ref_669[id_3768] };
                                                                      uint32_t id_3770 { uint32_t(id_3767 | id_3769) };
                                                                      Void id_3771 { ((void)(leb_ref_669[id_3761] = id_3770), VOID) };
                                                                      (void)id_3771;
                                                                      uint8_t id_3772 { 0 };
                                                                      uint8_t id_3773 { 0 };
                                                                      uint8_t id_3774 { shft_ref_670[id_3773] };
                                                                      uint8_t id_3775 { 7 };
                                                                      uint8_t id_3776 { uint8_t(id_3774 + id_3775) };
                                                                      Void id_3777 { ((void)(shft_ref_670[id_3772] = id_3776), VOID) };
                                                                      (void)id_3777;
                                                                      uint8_t id_3778 { 128 };
                                                                      bool id_3779 { bool(leb128_fst_673 >= id_3778) };
                                                                      letpair_res_3758 = id_3779;
                                                                    }
                                                                    let_res_3757 = letpair_res_3758;
                                                                  }
                                                                  while_flag_3753 = let_res_3757;
                                                                  if (while_flag_3753) {
                                                                    (void)VOID;
                                                                  }
                                                                } while (while_flag_3753);
                                                                (void)VOID;
                                                                uint8_t id_3780 { 0 };
                                                                uint32_t id_3781 { leb_ref_669[id_3780] };
                                                                uint8_t id_3782 { 0 };
                                                                Pointer id_3783 { p_ref_671[id_3782] };
                                                                ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3784 { id_3781, id_3783 };
                                                                let_res_3752 = id_3784;
                                                              }
                                                              let_res_3750 = let_res_3752;
                                                            }
                                                            let_res_3747 = let_res_3750;
                                                          }
                                                          ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 let_res_3785;
                                                          {
                                                            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_678 { let_res_3747 };
                                                            ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 letpair_res_3786;
                                                            {
                                                              auto dlist1_fst_679 { std::get<0>(dlist1_678) };
                                                              auto dlist1_snd_680 { std::get<1>(dlist1_678) };
                                                              Lst<dessser::gen::field_name::t_ext> endoflist_3787;
                                                              ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3788 { endoflist_3787, dlist1_snd_680 };
                                                              Vec<1, ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967> id_3789 {  id_3788  };
                                                              ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 let_res_3790;
                                                              {
                                                                Vec<1, ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967> inits_src_ref_681 { id_3789 };
                                                                int32_t id_3791 { 0L };
                                                                Vec<1, int32_t> id_3792 {  id_3791  };
                                                                {
                                                                  Vec<1, int32_t> repeat_n_682 { id_3792 };
                                                                  bool while_flag_3793 { true };
                                                                  do {
                                                                    int32_t id_3794 { int32_t(dlist1_fst_679) };
                                                                    uint8_t id_3795 { 0 };
                                                                    int32_t id_3796 { repeat_n_682[id_3795] };
                                                                    bool id_3797 { bool(id_3794 > id_3796) };
                                                                    while_flag_3793 = id_3797;
                                                                    if (while_flag_3793) {
                                                                      uint8_t id_3798 { 0 };
                                                                      ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3799 { inits_src_ref_681[id_3798] };
                                                                      {
                                                                        ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 dlist2_683 { id_3799 };
                                                                        {
                                                                          auto dlist2_fst_684 { std::get<0>(dlist2_683) };
                                                                          auto dlist2_snd_685 { std::get<1>(dlist2_683) };
                                                                          uint8_t id_3800 { 0 };
                                                                          auto fun3801 { dessser::gen::field_name::of_row_binary };
                                                                          ::dessser::gen::raql_operation::t273a2b7978f5b466a128a51c1cc4a27b id_3802 { fun3801(dlist2_snd_685) };
                                                                          ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 letpair_res_3803;
                                                                          {
                                                                            auto dlist3_fst_687 { std::get<0>(id_3802) };
                                                                            auto dlist3_snd_688 { std::get<1>(id_3802) };
                                                                            Lst<dessser::gen::field_name::t_ext> id_3804 { dlist3_fst_687, dlist2_fst_684 };
                                                                            ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3805 { id_3804, dlist3_snd_688 };
                                                                            letpair_res_3803 = id_3805;
                                                                          }
                                                                          Void id_3806 { ((void)(inits_src_ref_681[id_3800] = letpair_res_3803), VOID) };
                                                                          (void)id_3806;
                                                                        }
                                                                        (void)VOID;
                                                                      }
                                                                      (void)VOID;
                                                                      uint8_t id_3807 { 0 };
                                                                      uint8_t id_3808 { 0 };
                                                                      int32_t id_3809 { repeat_n_682[id_3808] };
                                                                      int32_t id_3810 { 1L };
                                                                      int32_t id_3811 { int32_t(id_3809 + id_3810) };
                                                                      Void id_3812 { ((void)(repeat_n_682[id_3807] = id_3811), VOID) };
                                                                      (void)id_3812;
                                                                      (void)id_3812;
                                                                    }
                                                                  } while (while_flag_3793);
                                                                  (void)VOID;
                                                                }
                                                                (void)VOID;
                                                                uint8_t id_3813 { 0 };
                                                                ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3814 { inits_src_ref_681[id_3813] };
                                                                let_res_3790 = id_3814;
                                                              }
                                                              letpair_res_3786 = let_res_3790;
                                                            }
                                                            let_res_3785 = letpair_res_3786;
                                                          }
                                                          ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3815;
                                                          {
                                                            auto dlist4_fst_690 { std::get<0>(let_res_3785) };
                                                            auto dlist4_snd_691 { std::get<1>(let_res_3785) };
                                                            ::dessser::gen::raql_operation::tbedd072c623fede5642d53b92db3bc60 id_3816 { .and_all_others = drec_fst_518, .commit_before = drec_fst_632, .commit_cond = drec_fst_626, .Aggregate_event_time = drec_fst_571, .every = drec_fst_667, .Aggregate_factors = dlist4_fst_690, .Aggregate_fields = drec_fst_489, .flush_how = drec_fst_635, .from = drec_fst_661, .key = drec_fst_623, .notifications = drec_fst_597, .sort = drec_fst_562, .where = drec_fst_565 };
                                                            ::dessser::gen::raql_operation::t* id_3817 { new ::dessser::gen::raql_operation::t(std::in_place_index<0>, id_3816) };
                                                            ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 id_3818 { id_3817, dlist4_snd_691 };
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
          bool id_3820 { bool(id_3819 == dsum1_fst_369) };
          ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 choose_res_3821;
          if (id_3820) {
            ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 id_3822 { external_source_of_row_binary(dsum1_snd_370) };
            ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3823;
            {
              ::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794 drec_424 { id_3822 };
              ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3824;
              {
                auto drec_fst_425 { std::get<0>(drec_424) };
                auto drec_snd_426 { std::get<1>(drec_424) };
                ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 id_3825 { external_format_of_row_binary(drec_snd_426) };
                ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3826;
                {
                  ::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6 drec_427 { id_3825 };
                  ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3827;
                  {
                    auto drec_fst_428 { std::get<0>(drec_427) };
                    auto drec_snd_429 { std::get<1>(drec_427) };
                    Size id_3828 { 0UL };
                    uint8_t id_3829 { drec_snd_429.peekU8(id_3828) };
                    uint8_t id_3830 { 1 };
                    bool id_3831 { bool(id_3829 == id_3830) };
                    ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 choose_res_3832;
                    if (id_3831) {
                      std::optional<dessser::gen::event_time::t_ext> id_3833 { std::nullopt };
                      Size id_3834 { 1UL };
                      Pointer id_3835 { drec_snd_429.skip(id_3834) };
                      ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 id_3836 { id_3833, id_3835 };
                      choose_res_3832 = id_3836;
                    } else {
                      auto fun3837 { dessser::gen::event_time::of_row_binary };
                      Size id_3838 { 1UL };
                      Pointer id_3839 { drec_snd_429.skip(id_3838) };
                      ::dessser::gen::raql_operation::te8ff255b34432f8503a86cf675cbafe6 id_3840 { fun3837(id_3839) };
                      ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 letpair_res_3841;
                      {
                        auto make1_1_fst_431 { std::get<0>(id_3840) };
                        auto make1_1_snd_432 { std::get<1>(id_3840) };
                        std::optional<dessser::gen::event_time::t_ext> id_3842 { make1_1_fst_431 };
                        ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 id_3843 { id_3842, make1_1_snd_432 };
                        letpair_res_3841 = id_3843;
                      }
                      choose_res_3832 = letpair_res_3841;
                    }
                    ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3844;
                    {
                      ::dessser::gen::raql_operation::te3858ac581a2bb69ede2f45fc6f9aff4 drec_433 { choose_res_3832 };
                      ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3845;
                      {
                        auto drec_fst_434 { std::get<0>(drec_433) };
                        auto drec_snd_435 { std::get<1>(drec_433) };
                        uint32_t id_3846 { 0U };
                        Vec<1, uint32_t> id_3847 {  id_3846  };
                        ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3848;
                        {
                          Vec<1, uint32_t> leb_ref_436 { id_3847 };
                          uint8_t id_3849 { 0 };
                          Vec<1, uint8_t> id_3850 {  id_3849  };
                          ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3851;
                          {
                            Vec<1, uint8_t> shft_ref_437 { id_3850 };
                            Vec<1, Pointer> id_3852 {  drec_snd_435  };
                            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3853;
                            {
                              Vec<1, Pointer> p_ref_438 { id_3852 };
                              bool while_flag_3854 { true };
                              do {
                                uint8_t id_3855 { 0 };
                                Pointer id_3856 { p_ref_438[id_3855] };
                                ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3857 { id_3856.readU8() };
                                bool let_res_3858;
                                {
                                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_439 { id_3857 };
                                  bool letpair_res_3859;
                                  {
                                    auto leb128_fst_440 { std::get<0>(leb128_439) };
                                    auto leb128_snd_441 { std::get<1>(leb128_439) };
                                    uint8_t id_3860 { 0 };
                                    Void id_3861 { ((void)(p_ref_438[id_3860] = leb128_snd_441), VOID) };
                                    (void)id_3861;
                                    uint8_t id_3862 { 0 };
                                    uint8_t id_3863 { 127 };
                                    uint8_t id_3864 { uint8_t(leb128_fst_440 & id_3863) };
                                    uint32_t id_3865 { uint32_t(id_3864) };
                                    uint8_t id_3866 { 0 };
                                    uint8_t id_3867 { shft_ref_437[id_3866] };
                                    uint32_t id_3868 { uint32_t(id_3865 << id_3867) };
                                    uint8_t id_3869 { 0 };
                                    uint32_t id_3870 { leb_ref_436[id_3869] };
                                    uint32_t id_3871 { uint32_t(id_3868 | id_3870) };
                                    Void id_3872 { ((void)(leb_ref_436[id_3862] = id_3871), VOID) };
                                    (void)id_3872;
                                    uint8_t id_3873 { 0 };
                                    uint8_t id_3874 { 0 };
                                    uint8_t id_3875 { shft_ref_437[id_3874] };
                                    uint8_t id_3876 { 7 };
                                    uint8_t id_3877 { uint8_t(id_3875 + id_3876) };
                                    Void id_3878 { ((void)(shft_ref_437[id_3873] = id_3877), VOID) };
                                    (void)id_3878;
                                    uint8_t id_3879 { 128 };
                                    bool id_3880 { bool(leb128_fst_440 >= id_3879) };
                                    letpair_res_3859 = id_3880;
                                  }
                                  let_res_3858 = letpair_res_3859;
                                }
                                while_flag_3854 = let_res_3858;
                                if (while_flag_3854) {
                                  (void)VOID;
                                }
                              } while (while_flag_3854);
                              (void)VOID;
                              uint8_t id_3881 { 0 };
                              uint32_t id_3882 { leb_ref_436[id_3881] };
                              uint8_t id_3883 { 0 };
                              Pointer id_3884 { p_ref_438[id_3883] };
                              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_3885 { id_3882, id_3884 };
                              let_res_3853 = id_3885;
                            }
                            let_res_3851 = let_res_3853;
                          }
                          let_res_3848 = let_res_3851;
                        }
                        ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 let_res_3886;
                        {
                          ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_445 { let_res_3848 };
                          ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 letpair_res_3887;
                          {
                            auto dlist1_fst_446 { std::get<0>(dlist1_445) };
                            auto dlist1_snd_447 { std::get<1>(dlist1_445) };
                            Lst<dessser::gen::field_name::t_ext> endoflist_3888;
                            ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3889 { endoflist_3888, dlist1_snd_447 };
                            Vec<1, ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967> id_3890 {  id_3889  };
                            ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 let_res_3891;
                            {
                              Vec<1, ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967> inits_src_ref_448 { id_3890 };
                              int32_t id_3892 { 0L };
                              Vec<1, int32_t> id_3893 {  id_3892  };
                              {
                                Vec<1, int32_t> repeat_n_449 { id_3893 };
                                bool while_flag_3894 { true };
                                do {
                                  int32_t id_3895 { int32_t(dlist1_fst_446) };
                                  uint8_t id_3896 { 0 };
                                  int32_t id_3897 { repeat_n_449[id_3896] };
                                  bool id_3898 { bool(id_3895 > id_3897) };
                                  while_flag_3894 = id_3898;
                                  if (while_flag_3894) {
                                    uint8_t id_3899 { 0 };
                                    ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3900 { inits_src_ref_448[id_3899] };
                                    {
                                      ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 dlist2_450 { id_3900 };
                                      {
                                        auto dlist2_fst_451 { std::get<0>(dlist2_450) };
                                        auto dlist2_snd_452 { std::get<1>(dlist2_450) };
                                        uint8_t id_3901 { 0 };
                                        auto fun3902 { dessser::gen::field_name::of_row_binary };
                                        ::dessser::gen::raql_operation::t273a2b7978f5b466a128a51c1cc4a27b id_3903 { fun3902(dlist2_snd_452) };
                                        ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 letpair_res_3904;
                                        {
                                          auto dlist3_fst_454 { std::get<0>(id_3903) };
                                          auto dlist3_snd_455 { std::get<1>(id_3903) };
                                          Lst<dessser::gen::field_name::t_ext> id_3905 { dlist3_fst_454, dlist2_fst_451 };
                                          ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3906 { id_3905, dlist3_snd_455 };
                                          letpair_res_3904 = id_3906;
                                        }
                                        Void id_3907 { ((void)(inits_src_ref_448[id_3901] = letpair_res_3904), VOID) };
                                        (void)id_3907;
                                      }
                                      (void)VOID;
                                    }
                                    (void)VOID;
                                    uint8_t id_3908 { 0 };
                                    uint8_t id_3909 { 0 };
                                    int32_t id_3910 { repeat_n_449[id_3909] };
                                    int32_t id_3911 { 1L };
                                    int32_t id_3912 { int32_t(id_3910 + id_3911) };
                                    Void id_3913 { ((void)(repeat_n_449[id_3908] = id_3912), VOID) };
                                    (void)id_3913;
                                    (void)id_3913;
                                  }
                                } while (while_flag_3894);
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_3914 { 0 };
                              ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_3915 { inits_src_ref_448[id_3914] };
                              let_res_3891 = id_3915;
                            }
                            letpair_res_3887 = let_res_3891;
                          }
                          let_res_3886 = letpair_res_3887;
                        }
                        ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3916;
                        {
                          auto dlist4_fst_457 { std::get<0>(let_res_3886) };
                          auto dlist4_snd_458 { std::get<1>(let_res_3886) };
                          ::dessser::gen::raql_operation::t61f013c74b0e45f17e9562bd5460b239 id_3917 { .event_time = drec_fst_434, .ReadExternal_factors = dlist4_fst_457, .format = drec_fst_428, .source = drec_fst_425 };
                          ::dessser::gen::raql_operation::t* id_3918 { new ::dessser::gen::raql_operation::t(std::in_place_index<1>, id_3917) };
                          ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 id_3919 { id_3918, dlist4_snd_458 };
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
            bool id_3921 { bool(dsum1_fst_369 == id_3920) };
            Void id_3922 { ((void)(assert(id_3921)), VOID) };
            (void)id_3922;
            uint32_t id_3923 { 0U };
            Vec<1, uint32_t> id_3924 {  id_3923  };
            ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_3925;
            {
              Vec<1, uint32_t> leb_ref_371 { id_3924 };
              uint8_t id_3926 { 0 };
              Vec<1, uint8_t> id_3927 {  id_3926  };
              ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_3928;
              {
                Vec<1, uint8_t> shft_ref_372 { id_3927 };
                Vec<1, Pointer> id_3929 {  dsum1_snd_370  };
                ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c let_res_3930;
                {
                  Vec<1, Pointer> p_ref_373 { id_3929 };
                  bool while_flag_3931 { true };
                  do {
                    uint8_t id_3932 { 0 };
                    Pointer id_3933 { p_ref_373[id_3932] };
                    ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3934 { id_3933.readU8() };
                    bool let_res_3935;
                    {
                      ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_374 { id_3934 };
                      bool letpair_res_3936;
                      {
                        auto leb128_fst_375 { std::get<0>(leb128_374) };
                        auto leb128_snd_376 { std::get<1>(leb128_374) };
                        uint8_t id_3937 { 0 };
                        Void id_3938 { ((void)(p_ref_373[id_3937] = leb128_snd_376), VOID) };
                        (void)id_3938;
                        uint8_t id_3939 { 0 };
                        uint8_t id_3940 { 127 };
                        uint8_t id_3941 { uint8_t(leb128_fst_375 & id_3940) };
                        uint32_t id_3942 { uint32_t(id_3941) };
                        uint8_t id_3943 { 0 };
                        uint8_t id_3944 { shft_ref_372[id_3943] };
                        uint32_t id_3945 { uint32_t(id_3942 << id_3944) };
                        uint8_t id_3946 { 0 };
                        uint32_t id_3947 { leb_ref_371[id_3946] };
                        uint32_t id_3948 { uint32_t(id_3945 | id_3947) };
                        Void id_3949 { ((void)(leb_ref_371[id_3939] = id_3948), VOID) };
                        (void)id_3949;
                        uint8_t id_3950 { 0 };
                        uint8_t id_3951 { 0 };
                        uint8_t id_3952 { shft_ref_372[id_3951] };
                        uint8_t id_3953 { 7 };
                        uint8_t id_3954 { uint8_t(id_3952 + id_3953) };
                        Void id_3955 { ((void)(shft_ref_372[id_3950] = id_3954), VOID) };
                        (void)id_3955;
                        uint8_t id_3956 { 128 };
                        bool id_3957 { bool(leb128_fst_375 >= id_3956) };
                        letpair_res_3936 = id_3957;
                      }
                      let_res_3935 = letpair_res_3936;
                    }
                    while_flag_3931 = let_res_3935;
                    if (while_flag_3931) {
                      (void)VOID;
                    }
                  } while (while_flag_3931);
                  (void)VOID;
                  uint8_t id_3958 { 0 };
                  uint32_t id_3959 { leb_ref_371[id_3958] };
                  Size id_3960 { Size(id_3959) };
                  uint8_t id_3961 { 0 };
                  Pointer id_3962 { p_ref_373[id_3961] };
                  ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c id_3963 { id_3960, id_3962 };
                  let_res_3930 = id_3963;
                }
                let_res_3928 = let_res_3930;
              }
              let_res_3925 = let_res_3928;
            }
            ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e let_res_3964;
            {
              ::dessser::gen::raql_operation::t8beb80162423aee37bd383e9b6834c9c dstring1_377 { let_res_3925 };
              ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e letpair_res_3965;
              {
                auto dstring1_fst_378 { std::get<0>(dstring1_377) };
                auto dstring1_snd_379 { std::get<1>(dstring1_377) };
                ::dessser::gen::raql_operation::t188345aa49abd0cb47ff73fedc219f08 id_3966 { dstring1_snd_379.readBytes(dstring1_fst_378) };
                ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e letpair_res_3967;
                {
                  auto dstring2_fst_381 { std::get<0>(id_3966) };
                  auto dstring2_snd_382 { std::get<1>(id_3966) };
                  std::string id_3968 { dstring2_fst_381.toString() };
                  ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e id_3969 { id_3968, dstring2_snd_382 };
                  letpair_res_3967 = id_3969;
                }
                letpair_res_3965 = letpair_res_3967;
              }
              let_res_3964 = letpair_res_3965;
            }
            ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3970;
            {
              ::dessser::gen::raql_operation::tef94b55d8809251f13165d9a05bd9d0e drec_383 { let_res_3964 };
              ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3971;
              {
                auto drec_fst_384 { std::get<0>(drec_383) };
                auto drec_snd_385 { std::get<1>(drec_383) };
                ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_3972 { drec_snd_385.readU16Le() };
                ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 letpair_res_3973;
                {
                  auto du16_fst_387 { std::get<0>(id_3972) };
                  auto du16_snd_388 { std::get<1>(id_3972) };
                  ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 id_3974 { du16_fst_387, du16_snd_388 };
                  letpair_res_3973 = id_3974;
                }
                ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3975;
                {
                  ::dessser::gen::raql_operation::t22a32080ad88ab548b80077a17b7dd46 drec_389 { letpair_res_3973 };
                  ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3976;
                  {
                    auto drec_fst_390 { std::get<0>(drec_389) };
                    auto drec_snd_391 { std::get<1>(drec_389) };
                    auto fun3977 { dessser::gen::raql_net_protocol::of_row_binary };
                    ::dessser::gen::raql_operation::t09401f6cfd6a52d2f08b29ed5a55a113 id_3978 { fun3977(drec_snd_391) };
                    ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 let_res_3979;
                    {
                      ::dessser::gen::raql_operation::t09401f6cfd6a52d2f08b29ed5a55a113 drec_392 { id_3978 };
                      ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_3980;
                      {
                        auto drec_fst_393 { std::get<0>(drec_392) };
                        auto drec_snd_394 { std::get<1>(drec_392) };
                        uint32_t id_3981 { 0U };
                        Vec<1, uint32_t> id_3982 {  id_3981  };
                        ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3983;
                        {
                          Vec<1, uint32_t> leb_ref_395 { id_3982 };
                          uint8_t id_3984 { 0 };
                          Vec<1, uint8_t> id_3985 {  id_3984  };
                          ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3986;
                          {
                            Vec<1, uint8_t> shft_ref_396 { id_3985 };
                            Vec<1, Pointer> id_3987 {  drec_snd_394  };
                            ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 let_res_3988;
                            {
                              Vec<1, Pointer> p_ref_397 { id_3987 };
                              bool while_flag_3989 { true };
                              do {
                                uint8_t id_3990 { 0 };
                                Pointer id_3991 { p_ref_397[id_3990] };
                                ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 id_3992 { id_3991.readU8() };
                                bool let_res_3993;
                                {
                                  ::dessser::gen::raql_operation::tb3f98ea670610d40658a618de3ec7b90 leb128_398 { id_3992 };
                                  bool letpair_res_3994;
                                  {
                                    auto leb128_fst_399 { std::get<0>(leb128_398) };
                                    auto leb128_snd_400 { std::get<1>(leb128_398) };
                                    uint8_t id_3995 { 0 };
                                    Void id_3996 { ((void)(p_ref_397[id_3995] = leb128_snd_400), VOID) };
                                    (void)id_3996;
                                    uint8_t id_3997 { 0 };
                                    uint8_t id_3998 { 127 };
                                    uint8_t id_3999 { uint8_t(leb128_fst_399 & id_3998) };
                                    uint32_t id_4000 { uint32_t(id_3999) };
                                    uint8_t id_4001 { 0 };
                                    uint8_t id_4002 { shft_ref_396[id_4001] };
                                    uint32_t id_4003 { uint32_t(id_4000 << id_4002) };
                                    uint8_t id_4004 { 0 };
                                    uint32_t id_4005 { leb_ref_395[id_4004] };
                                    uint32_t id_4006 { uint32_t(id_4003 | id_4005) };
                                    Void id_4007 { ((void)(leb_ref_395[id_3997] = id_4006), VOID) };
                                    (void)id_4007;
                                    uint8_t id_4008 { 0 };
                                    uint8_t id_4009 { 0 };
                                    uint8_t id_4010 { shft_ref_396[id_4009] };
                                    uint8_t id_4011 { 7 };
                                    uint8_t id_4012 { uint8_t(id_4010 + id_4011) };
                                    Void id_4013 { ((void)(shft_ref_396[id_4008] = id_4012), VOID) };
                                    (void)id_4013;
                                    uint8_t id_4014 { 128 };
                                    bool id_4015 { bool(leb128_fst_399 >= id_4014) };
                                    letpair_res_3994 = id_4015;
                                  }
                                  let_res_3993 = letpair_res_3994;
                                }
                                while_flag_3989 = let_res_3993;
                                if (while_flag_3989) {
                                  (void)VOID;
                                }
                              } while (while_flag_3989);
                              (void)VOID;
                              uint8_t id_4016 { 0 };
                              uint32_t id_4017 { leb_ref_395[id_4016] };
                              uint8_t id_4018 { 0 };
                              Pointer id_4019 { p_ref_397[id_4018] };
                              ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 id_4020 { id_4017, id_4019 };
                              let_res_3988 = id_4020;
                            }
                            let_res_3986 = let_res_3988;
                          }
                          let_res_3983 = let_res_3986;
                        }
                        ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 let_res_4021;
                        {
                          ::dessser::gen::raql_operation::t405eb186408556fed8f2c41523c07d13 dlist1_404 { let_res_3983 };
                          ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 letpair_res_4022;
                          {
                            auto dlist1_fst_405 { std::get<0>(dlist1_404) };
                            auto dlist1_snd_406 { std::get<1>(dlist1_404) };
                            Lst<dessser::gen::field_name::t_ext> endoflist_4023;
                            ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_4024 { endoflist_4023, dlist1_snd_406 };
                            Vec<1, ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967> id_4025 {  id_4024  };
                            ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 let_res_4026;
                            {
                              Vec<1, ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967> inits_src_ref_407 { id_4025 };
                              int32_t id_4027 { 0L };
                              Vec<1, int32_t> id_4028 {  id_4027  };
                              {
                                Vec<1, int32_t> repeat_n_408 { id_4028 };
                                bool while_flag_4029 { true };
                                do {
                                  int32_t id_4030 { int32_t(dlist1_fst_405) };
                                  uint8_t id_4031 { 0 };
                                  int32_t id_4032 { repeat_n_408[id_4031] };
                                  bool id_4033 { bool(id_4030 > id_4032) };
                                  while_flag_4029 = id_4033;
                                  if (while_flag_4029) {
                                    uint8_t id_4034 { 0 };
                                    ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_4035 { inits_src_ref_407[id_4034] };
                                    {
                                      ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 dlist2_409 { id_4035 };
                                      {
                                        auto dlist2_fst_410 { std::get<0>(dlist2_409) };
                                        auto dlist2_snd_411 { std::get<1>(dlist2_409) };
                                        uint8_t id_4036 { 0 };
                                        auto fun4037 { dessser::gen::field_name::of_row_binary };
                                        ::dessser::gen::raql_operation::t273a2b7978f5b466a128a51c1cc4a27b id_4038 { fun4037(dlist2_snd_411) };
                                        ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 letpair_res_4039;
                                        {
                                          auto dlist3_fst_413 { std::get<0>(id_4038) };
                                          auto dlist3_snd_414 { std::get<1>(id_4038) };
                                          Lst<dessser::gen::field_name::t_ext> id_4040 { dlist3_fst_413, dlist2_fst_410 };
                                          ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_4041 { id_4040, dlist3_snd_414 };
                                          letpair_res_4039 = id_4041;
                                        }
                                        Void id_4042 { ((void)(inits_src_ref_407[id_4036] = letpair_res_4039), VOID) };
                                        (void)id_4042;
                                      }
                                      (void)VOID;
                                    }
                                    (void)VOID;
                                    uint8_t id_4043 { 0 };
                                    uint8_t id_4044 { 0 };
                                    int32_t id_4045 { repeat_n_408[id_4044] };
                                    int32_t id_4046 { 1L };
                                    int32_t id_4047 { int32_t(id_4045 + id_4046) };
                                    Void id_4048 { ((void)(repeat_n_408[id_4043] = id_4047), VOID) };
                                    (void)id_4048;
                                    (void)id_4048;
                                  }
                                } while (while_flag_4029);
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_4049 { 0 };
                              ::dessser::gen::raql_operation::t0dfa866705b76efff53e4aa97228a967 id_4050 { inits_src_ref_407[id_4049] };
                              let_res_4026 = id_4050;
                            }
                            letpair_res_4022 = let_res_4026;
                          }
                          let_res_4021 = letpair_res_4022;
                        }
                        ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_4051;
                        {
                          auto dlist4_fst_416 { std::get<0>(let_res_4021) };
                          auto dlist4_snd_417 { std::get<1>(let_res_4021) };
                          ::dessser::gen::raql_operation::t5a75bfb14bb95ab8cf8a8b9296aea27d id_4052 { .factors = dlist4_fst_416, .net_addr = drec_fst_384, .port = drec_fst_390, .proto = drec_fst_393 };
                          ::dessser::gen::raql_operation::t* id_4053 { new ::dessser::gen::raql_operation::t(std::in_place_index<2>, id_4052) };
                          ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 id_4054 { id_4053, dlist4_snd_417 };
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
    ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 letpair_res_4055;
    {
      auto make_fst_699 { std::get<0>(let_res_3193) };
      auto make_snd_700 { std::get<1>(let_res_3193) };
      ::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018 id_4056 { make_fst_699, make_snd_700 };
      letpair_res_4055 = id_4056;
    }
    return letpair_res_4055;
  }
   };
  return fun3189;
}
std::function<::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
