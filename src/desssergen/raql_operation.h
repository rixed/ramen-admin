#ifndef DESSSER_GEN_raql_operation
#define DESSSER_GEN_raql_operation
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
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

/* ------------ */
/* Declarations */
/* ------------ */
struct t4e73505f12c0301df6abf2cf5d273b35 {
  bool clickhouse_syntax;
  std::string escape_seq;
  Lst<dessser::gen::field_type::t_ext> fields;
  bool may_quote;
  std::string null;
  char separator;
  bool vectors_of_chars_as_string;
  t4e73505f12c0301df6abf2cf5d273b35(bool clickhouse_syntax_, std::string escape_seq_, Lst<dessser::gen::field_type::t_ext> fields_, bool may_quote_, std::string null_, char separator_, bool vectors_of_chars_as_string_) : clickhouse_syntax(clickhouse_syntax_), escape_seq(escape_seq_), fields(fields_), may_quote(may_quote_), null(null_), separator(separator_), vectors_of_chars_as_string(vectors_of_chars_as_string_) {}
  t4e73505f12c0301df6abf2cf5d273b35() = default;
  bool operator==(t4e73505f12c0301df6abf2cf5d273b35 const &other) const {
    return clickhouse_syntax == other.clickhouse_syntax && escape_seq == other.escape_seq && fields == other.fields && may_quote == other.may_quote && null == other.null && separator == other.separator && vectors_of_chars_as_string == other.vectors_of_chars_as_string;
  }
};
inline std::ostream &operator<<(std::ostream &os, t4e73505f12c0301df6abf2cf5d273b35 const &r) {
  os << '{';
  os << "clickhouse_syntax:" << r.clickhouse_syntax << ',';
  os << "escape_seq:" << r.escape_seq << ',';
  os << "fields:" << r.fields << ',';
  os << "may_quote:" << r.may_quote << ',';
  os << "null:" << r.null << ',';
  os << "separator:" << r.separator << ',';
  os << "vectors_of_chars_as_string:" << r.vectors_of_chars_as_string;
  os << '}';
  return os;
}

struct external_format : public std::variant<
  ::dessser::gen::raql_operation::t4e73505f12c0301df6abf2cf5d273b35, // CSV
  Lst<dessser::gen::field_type::t_ext> // RowBinary
> { using variant::variant; };

enum Constr_external_format {
  CSV,
  RowBinary,
};

inline std::ostream &operator<<(std::ostream &os, external_format const &v) {
  switch (v.index()) {
    case 0: os << "CSV " << std::get<0>(v); break;
    case 1: os << "RowBinary " << std::get<1>(v); break;
  }
  return os;
}

struct tba1ba4184156c77bee45e0e58939e9eb {
  dessser::gen::raql_expr::t_ext fname;
  std::optional<dessser::gen::raql_expr::t_ext> preprocessor;
  dessser::gen::raql_expr::t_ext unlink;
  tba1ba4184156c77bee45e0e58939e9eb(dessser::gen::raql_expr::t_ext fname_, std::optional<dessser::gen::raql_expr::t_ext> preprocessor_, dessser::gen::raql_expr::t_ext unlink_) : fname(fname_), preprocessor(preprocessor_), unlink(unlink_) {}
  tba1ba4184156c77bee45e0e58939e9eb() = default;
  bool operator==(tba1ba4184156c77bee45e0e58939e9eb const &other) const {
    return fname == other.fname && preprocessor == other.preprocessor && unlink == other.unlink;
  }
};
inline std::ostream &operator<<(std::ostream &os, tba1ba4184156c77bee45e0e58939e9eb const &r) {
  os << '{';
  os << "fname:" << r.fname << ',';
  os << "preprocessor:" << r.preprocessor << ',';
  os << "unlink:" << r.unlink;
  os << '}';
  return os;
}

typedef std::tuple<
  std::string,
  dessser::gen::raql_expr::t_ext
> tcd17c85cefeae7a860c0732c05eaeaed;

struct t6978cd9fa7626f268968c3c3f4326602 {
  dessser::gen::raql_expr::t_ext after_max_events;
  dessser::gen::raql_expr::t_ext after_max_secs;
  t6978cd9fa7626f268968c3c3f4326602(dessser::gen::raql_expr::t_ext after_max_events_, dessser::gen::raql_expr::t_ext after_max_secs_) : after_max_events(after_max_events_), after_max_secs(after_max_secs_) {}
  t6978cd9fa7626f268968c3c3f4326602() = default;
  bool operator==(t6978cd9fa7626f268968c3c3f4326602 const &other) const {
    return after_max_events == other.after_max_events && after_max_secs == other.after_max_secs;
  }
};
inline std::ostream &operator<<(std::ostream &os, t6978cd9fa7626f268968c3c3f4326602 const &r) {
  os << '{';
  os << "after_max_events:" << r.after_max_events << ',';
  os << "after_max_secs:" << r.after_max_secs;
  os << '}';
  return os;
}

struct t982eaa31ed3f26458d4b45f126bd809a : public std::variant<
  Void, // Beginning
  dessser::gen::raql_expr::t_ext, // OffsetFromEnd
  Void, // SaveInState
  ::dessser::gen::raql_operation::t6978cd9fa7626f268968c3c3f4326602 // UseKafkaGroupCoordinator
> { using variant::variant; };

enum Constr_t982eaa31ed3f26458d4b45f126bd809a {
  Beginning,
  OffsetFromEnd,
  SaveInState,
  UseKafkaGroupCoordinator,
};

inline std::ostream &operator<<(std::ostream &os, t982eaa31ed3f26458d4b45f126bd809a const &v) {
  switch (v.index()) {
    case 0: os << "Beginning " << std::get<0>(v); break;
    case 1: os << "OffsetFromEnd " << std::get<1>(v); break;
    case 2: os << "SaveInState " << std::get<2>(v); break;
    case 3: os << "UseKafkaGroupCoordinator " << std::get<3>(v); break;
  }
  return os;
}

struct t0dd0cbae8c4f4ef8f02af27a977d4ada {
  Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> options;
  std::optional<dessser::gen::raql_expr::t_ext> partitions;
  ::dessser::gen::raql_operation::t982eaa31ed3f26458d4b45f126bd809a restart_from;
  dessser::gen::raql_expr::t_ext topic;
  t0dd0cbae8c4f4ef8f02af27a977d4ada(Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> options_, std::optional<dessser::gen::raql_expr::t_ext> partitions_, ::dessser::gen::raql_operation::t982eaa31ed3f26458d4b45f126bd809a restart_from_, dessser::gen::raql_expr::t_ext topic_) : options(options_), partitions(partitions_), restart_from(restart_from_), topic(topic_) {}
  t0dd0cbae8c4f4ef8f02af27a977d4ada() = default;
  bool operator==(t0dd0cbae8c4f4ef8f02af27a977d4ada const &other) const {
    return options == other.options && partitions == other.partitions && restart_from == other.restart_from && topic == other.topic;
  }
};
inline std::ostream &operator<<(std::ostream &os, t0dd0cbae8c4f4ef8f02af27a977d4ada const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "partitions:" << r.partitions << ',';
  os << "restart_from:" << r.restart_from << ',';
  os << "topic:" << r.topic;
  os << '}';
  return os;
}

struct external_source : public std::variant<
  ::dessser::gen::raql_operation::tba1ba4184156c77bee45e0e58939e9eb, // File
  ::dessser::gen::raql_operation::t0dd0cbae8c4f4ef8f02af27a977d4ada // Kafka
> { using variant::variant; };

enum Constr_external_source {
  File,
  Kafka,
};

inline std::ostream &operator<<(std::ostream &os, external_source const &v) {
  switch (v.index()) {
    case 0: os << "File " << std::get<0>(v); break;
    case 1: os << "Kafka " << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  ::dessser::gen::raql_operation::external_format*,
  Pointer
> td224083eaf19a954cf9d9cafa8673ea6;

typedef std::tuple<
  ::dessser::gen::raql_operation::external_source*,
  Pointer
> t271b8f1ad1dc1b4cc142866cf5601794;

struct t59b20b8b0e4973a8b2e924c6f3f006db : public std::variant<
  Void, // AllSites
  std::string, // TheseSites
  Void // ThisSite
> { using variant::variant; };

enum Constr_t59b20b8b0e4973a8b2e924c6f3f006db {
  AllSites,
  TheseSites,
  ThisSite,
};

inline std::ostream &operator<<(std::ostream &os, t59b20b8b0e4973a8b2e924c6f3f006db const &v) {
  switch (v.index()) {
    case 0: os << "AllSites " << std::get<0>(v); break;
    case 1: os << "TheseSites " << std::get<1>(v); break;
    case 2: os << "ThisSite " << std::get<2>(v); break;
  }
  return os;
}

struct t3ebe768f5b483383c74caad368fa4d1b : public std::tuple<
  ::dessser::gen::raql_operation::t59b20b8b0e4973a8b2e924c6f3f006db,
  std::optional<std::string>,
  dessser::gen::function_name::t_ext
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t3ebe768f5b483383c74caad368fa4d1b const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct data_source : public std::variant<
  ::dessser::gen::raql_operation::t3ebe768f5b483383c74caad368fa4d1b, // NamedOperation
  t* // SubQuery
> { using variant::variant; };

enum Constr_data_source {
  NamedOperation,
  SubQuery,
};

inline std::ostream &operator<<(std::ostream &os, data_source const &v) {
  switch (v.index()) {
    case 0: os << "NamedOperation " << std::get<0>(v); break;
    case 1: os << "SubQuery " << *std::get<1>(v); break;
  }
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct tf0c8d4f3070907529cc1a83f8baf6fab : public std::tuple<
  uint32_t,
  std::optional<dessser::gen::raql_expr::t_ext>,
  Lst<dessser::gen::raql_expr::t_ext>
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, tf0c8d4f3070907529cc1a83f8baf6fab const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct tb351844d2db0c90340adfaa3b56d9d13 {
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
  tb351844d2db0c90340adfaa3b56d9d13(std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others_, bool commit_before_, dessser::gen::raql_expr::t_ext commit_cond_, std::optional<dessser::gen::event_time::t_ext> Aggregate_event_time_, std::optional<dessser::gen::raql_expr::t_ext> every_, Lst<dessser::gen::field_name::t_ext> Aggregate_factors_, Lst<dessser::gen::raql_select_field::t_ext> Aggregate_fields_, dessser::gen::raql_flush_method::t_ext flush_how_, Lst<::dessser::gen::raql_operation::data_source*> from_, Lst<dessser::gen::raql_expr::t_ext> key_, Lst<dessser::gen::raql_expr::t_ext> notifications_, std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> sort_, dessser::gen::raql_expr::t_ext where_) : and_all_others(and_all_others_), commit_before(commit_before_), commit_cond(commit_cond_), Aggregate_event_time(Aggregate_event_time_), every(every_), Aggregate_factors(Aggregate_factors_), Aggregate_fields(Aggregate_fields_), flush_how(flush_how_), from(from_), key(key_), notifications(notifications_), sort(sort_), where(where_) {}
  tb351844d2db0c90340adfaa3b56d9d13() = default;
  bool operator==(tb351844d2db0c90340adfaa3b56d9d13 const &other) const {
    return and_all_others == other.and_all_others && commit_before == other.commit_before && commit_cond == other.commit_cond && Aggregate_event_time == other.Aggregate_event_time && every == other.every && Aggregate_factors == other.Aggregate_factors && Aggregate_fields == other.Aggregate_fields && flush_how == other.flush_how && from == other.from && key == other.key && notifications == other.notifications && sort == other.sort && where == other.where;
  }
};
inline std::ostream &operator<<(std::ostream &os, tb351844d2db0c90340adfaa3b56d9d13 const &r) {
  os << '{';
  os << "and_all_others:" << r.and_all_others << ',';
  os << "commit_before:" << r.commit_before << ',';
  os << "commit_cond:" << r.commit_cond << ',';
  os << "Aggregate_event_time:" << r.Aggregate_event_time << ',';
  os << "every:" << r.every << ',';
  os << "Aggregate_factors:" << r.Aggregate_factors << ',';
  os << "Aggregate_fields:" << r.Aggregate_fields << ',';
  os << "flush_how:" << r.flush_how << ',';
  os << "from:" << r.from << ',';
  os << "key:" << r.key << ',';
  os << "notifications:" << r.notifications << ',';
  os << "sort:" << r.sort << ',';
  os << "where:" << r.where;
  os << '}';
  return os;
}

struct tcb236bf5f79e9a91e09a931d5cece618 {
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::field_name::t_ext> ReadExternal_factors;
  ::dessser::gen::raql_operation::external_format* format;
  ::dessser::gen::raql_operation::external_source* source;
  tcb236bf5f79e9a91e09a931d5cece618(std::optional<dessser::gen::event_time::t_ext> event_time_, Lst<dessser::gen::field_name::t_ext> ReadExternal_factors_, ::dessser::gen::raql_operation::external_format* format_, ::dessser::gen::raql_operation::external_source* source_) : event_time(event_time_), ReadExternal_factors(ReadExternal_factors_), format(format_), source(source_) {}
  tcb236bf5f79e9a91e09a931d5cece618() = default;
  bool operator==(tcb236bf5f79e9a91e09a931d5cece618 const &other) const {
    return event_time == other.event_time && ReadExternal_factors == other.ReadExternal_factors && format == other.format && source == other.source;
  }
};
inline std::ostream &operator<<(std::ostream &os, tcb236bf5f79e9a91e09a931d5cece618 const &r) {
  os << '{';
  os << "event_time:" << r.event_time << ',';
  os << "ReadExternal_factors:" << r.ReadExternal_factors << ',';
  os << "format:" << r.format << ',';
  os << "source:" << r.source;
  os << '}';
  return os;
}

struct te3589c10889f2a54eb4657634d7f2c95 {
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string net_addr;
  uint16_t port;
  dessser::gen::raql_net_protocol::t_ext proto;
  te3589c10889f2a54eb4657634d7f2c95(Lst<dessser::gen::field_name::t_ext> factors_, std::string net_addr_, uint16_t port_, dessser::gen::raql_net_protocol::t_ext proto_) : factors(factors_), net_addr(net_addr_), port(port_), proto(proto_) {}
  te3589c10889f2a54eb4657634d7f2c95() = default;
  bool operator==(te3589c10889f2a54eb4657634d7f2c95 const &other) const {
    return factors == other.factors && net_addr == other.net_addr && port == other.port && proto == other.proto;
  }
};
inline std::ostream &operator<<(std::ostream &os, te3589c10889f2a54eb4657634d7f2c95 const &r) {
  os << '{';
  os << "factors:" << r.factors << ',';
  os << "net_addr:" << r.net_addr << ',';
  os << "port:" << r.port << ',';
  os << "proto:" << r.proto;
  os << '}';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t : public std::variant<
  ::dessser::gen::raql_operation::tb351844d2db0c90340adfaa3b56d9d13, // Aggregate
  ::dessser::gen::raql_operation::tcb236bf5f79e9a91e09a931d5cece618, // ReadExternal
  ::dessser::gen::raql_operation::te3589c10889f2a54eb4657634d7f2c95 // ListenFor
> { using variant::variant; };

enum Constr_t {
  Aggregate,
  ReadExternal,
  ListenFor,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Aggregate " << std::get<0>(v); break;
    case 1: os << "ReadExternal " << std::get<1>(v); break;
    case 2: os << "ListenFor " << std::get<2>(v); break;
  }
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  ::dessser::gen::raql_operation::data_source*,
  Pointer
> tcd2420ce0244df52965bf04a8e398ab3;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  ::dessser::gen::raql_operation::t*,
  Pointer
> te2fc367261094758eeb235699c19c018;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_operation::external_format*,Pointer)> external_format_to_row_binary;
extern std::function<Pointer(::dessser::gen::raql_operation::external_source*,Pointer)> external_source_to_row_binary;
extern std::function<Size(::dessser::gen::raql_operation::external_format*)> external_format_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::raql_operation::external_source*)> external_source_sersize_of_row_binary;
extern std::function<::dessser::gen::raql_operation::td224083eaf19a954cf9d9cafa8673ea6(Pointer)> external_format_of_row_binary;
extern std::function<::dessser::gen::raql_operation::t271b8f1ad1dc1b4cc142866cf5601794(Pointer)> external_source_of_row_binary;
extern std::function<Pointer(::dessser::gen::raql_operation::data_source*,Pointer)> data_source_to_row_binary;
extern std::function<Pointer(::dessser::gen::raql_operation::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_operation::data_source*)> data_source_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::raql_operation::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_operation::tcd2420ce0244df52965bf04a8e398ab3(Pointer)> data_source_of_row_binary;
extern std::function<::dessser::gen::raql_operation::te2fc367261094758eeb235699c19c018(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
