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
inline std::ostream &operator<<(std::ostream &os, t4774fe515f9a8e5673bc2feaee67a68f const &r) {
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
inline bool operator==(t4774fe515f9a8e5673bc2feaee67a68f const &a, t4774fe515f9a8e5673bc2feaee67a68f const &b) {
  return a.clickhouse_syntax == b.clickhouse_syntax && a.escape_seq == b.escape_seq && a.fields == b.fields && a.may_quote == b.may_quote && a.null == b.null && a.separator == b.separator && a.vectors_of_chars_as_string == b.vectors_of_chars_as_string;
}

inline bool operator!=(t4774fe515f9a8e5673bc2feaee67a68f const &a, t4774fe515f9a8e5673bc2feaee67a68f const &b) {
  return !operator==(a, b);
}
struct external_format : public std::variant<
  ::dessser::gen::raql_operation::t4774fe515f9a8e5673bc2feaee67a68f, // CSV
  Lst<dessser::gen::field_type::t_ext> // RowBinary
> { using variant::variant; };

enum Constr_external_format {
  CSV,
  RowBinary,
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
inline std::ostream &operator<<(std::ostream &os, external_format const &v) {
  switch (v.index()) {
    case 0: os << "CSV " << std::get<0>(v); break;
    case 1: os << "RowBinary " << std::get<1>(v); break;
  }
  return os;
}

struct t1961e84afc2b1abe7ce9bf9253dd47b8 {
  dessser::gen::raql_expr::t_ext fname;
  std::optional<dessser::gen::raql_expr::t_ext> preprocessor;
  dessser::gen::raql_expr::t_ext unlink;
  t1961e84afc2b1abe7ce9bf9253dd47b8(dessser::gen::raql_expr::t_ext fname_, std::optional<dessser::gen::raql_expr::t_ext> preprocessor_, dessser::gen::raql_expr::t_ext unlink_) : fname(fname_), preprocessor(preprocessor_), unlink(unlink_) {}
  t1961e84afc2b1abe7ce9bf9253dd47b8() = default;
};
inline std::ostream &operator<<(std::ostream &os, t1961e84afc2b1abe7ce9bf9253dd47b8 const &r) {
  os << '{';
  os << "fname:" << ::dessser::gen::raql_expr::Deref(r.fname) << ',';
  if (r.preprocessor) os << "preprocessor:" << ::dessser::gen::raql_expr::Deref(r.preprocessor.value()) << ',';
  os << "unlink:" << ::dessser::gen::raql_expr::Deref(r.unlink);
  os << '}';
  return os;
}
inline bool operator==(t1961e84afc2b1abe7ce9bf9253dd47b8 const &a, t1961e84afc2b1abe7ce9bf9253dd47b8 const &b) {
  return ::dessser::gen::raql_expr::Deref(a.fname) == ::dessser::gen::raql_expr::Deref(b.fname) && ((a.preprocessor && b.preprocessor && ::dessser::gen::raql_expr::Deref(a.preprocessor.value()) == ::dessser::gen::raql_expr::Deref(b.preprocessor.value())) || (!a.preprocessor && !b.preprocessor)) && ::dessser::gen::raql_expr::Deref(a.unlink) == ::dessser::gen::raql_expr::Deref(b.unlink);
}

inline bool operator!=(t1961e84afc2b1abe7ce9bf9253dd47b8 const &a, t1961e84afc2b1abe7ce9bf9253dd47b8 const &b) {
  return !operator==(a, b);
}
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
inline std::ostream &operator<<(std::ostream &os, tb07656d6bb51183c62956887bcdc8cf2 const &r) {
  os << '{';
  os << "after_max_events:" << ::dessser::gen::raql_expr::Deref(r.after_max_events) << ',';
  os << "after_max_secs:" << ::dessser::gen::raql_expr::Deref(r.after_max_secs);
  os << '}';
  return os;
}
inline bool operator==(tb07656d6bb51183c62956887bcdc8cf2 const &a, tb07656d6bb51183c62956887bcdc8cf2 const &b) {
  return ::dessser::gen::raql_expr::Deref(a.after_max_events) == ::dessser::gen::raql_expr::Deref(b.after_max_events) && ::dessser::gen::raql_expr::Deref(a.after_max_secs) == ::dessser::gen::raql_expr::Deref(b.after_max_secs);
}

inline bool operator!=(tb07656d6bb51183c62956887bcdc8cf2 const &a, tb07656d6bb51183c62956887bcdc8cf2 const &b) {
  return !operator==(a, b);
}
struct ta7fb64c30db2a6f0744298f9ba111e14 : public std::variant<
  Void, // Beginning
  dessser::gen::raql_expr::t_ext, // OffsetFromEnd
  Void, // SaveInState
  ::dessser::gen::raql_operation::tb07656d6bb51183c62956887bcdc8cf2 // UseKafkaGroupCoordinator
> { using variant::variant; };

enum Constr_ta7fb64c30db2a6f0744298f9ba111e14 {
  Beginning,
  OffsetFromEnd,
  SaveInState,
  UseKafkaGroupCoordinator,
};

inline bool operator==(ta7fb64c30db2a6f0744298f9ba111e14 const &a, ta7fb64c30db2a6f0744298f9ba111e14 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Beginning
    case 1: return ::dessser::gen::raql_expr::Deref(std::get<1>(a)) == ::dessser::gen::raql_expr::Deref(std::get<1>(b)); // OffsetFromEnd
    case 2: return std::get<2>(a) == std::get<2>(b); // SaveInState
    case 3: return std::get<3>(a) == std::get<3>(b); // UseKafkaGroupCoordinator
  };
  return false;
}
inline bool operator!=(ta7fb64c30db2a6f0744298f9ba111e14 const &a, ta7fb64c30db2a6f0744298f9ba111e14 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta7fb64c30db2a6f0744298f9ba111e14 const &v) {
  switch (v.index()) {
    case 0: os << "Beginning " << std::get<0>(v); break;
    case 1: os << "OffsetFromEnd " << ::dessser::gen::raql_expr::Deref(std::get<1>(v)); break;
    case 2: os << "SaveInState " << std::get<2>(v); break;
    case 3: os << "UseKafkaGroupCoordinator " << std::get<3>(v); break;
  }
  return os;
}

struct tf15d79cf8e11e1ea99ca519694240894 {
  Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> options;
  std::optional<dessser::gen::raql_expr::t_ext> partitions;
  ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 restart_from;
  dessser::gen::raql_expr::t_ext topic;
  tf15d79cf8e11e1ea99ca519694240894(Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> options_, std::optional<dessser::gen::raql_expr::t_ext> partitions_, ::dessser::gen::raql_operation::ta7fb64c30db2a6f0744298f9ba111e14 restart_from_, dessser::gen::raql_expr::t_ext topic_) : options(options_), partitions(partitions_), restart_from(restart_from_), topic(topic_) {}
  tf15d79cf8e11e1ea99ca519694240894() = default;
};
inline std::ostream &operator<<(std::ostream &os, tf15d79cf8e11e1ea99ca519694240894 const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  if (r.partitions) os << "partitions:" << ::dessser::gen::raql_expr::Deref(r.partitions.value()) << ',';
  os << "restart_from:" << r.restart_from << ',';
  os << "topic:" << ::dessser::gen::raql_expr::Deref(r.topic);
  os << '}';
  return os;
}
inline bool operator==(tf15d79cf8e11e1ea99ca519694240894 const &a, tf15d79cf8e11e1ea99ca519694240894 const &b) {
  return a.options == b.options && ((a.partitions && b.partitions && ::dessser::gen::raql_expr::Deref(a.partitions.value()) == ::dessser::gen::raql_expr::Deref(b.partitions.value())) || (!a.partitions && !b.partitions)) && a.restart_from == b.restart_from && ::dessser::gen::raql_expr::Deref(a.topic) == ::dessser::gen::raql_expr::Deref(b.topic);
}

inline bool operator!=(tf15d79cf8e11e1ea99ca519694240894 const &a, tf15d79cf8e11e1ea99ca519694240894 const &b) {
  return !operator==(a, b);
}
struct external_source : public std::variant<
  ::dessser::gen::raql_operation::t1961e84afc2b1abe7ce9bf9253dd47b8, // File
  ::dessser::gen::raql_operation::tf15d79cf8e11e1ea99ca519694240894 // Kafka
> { using variant::variant; };

enum Constr_external_source {
  File,
  Kafka,
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

inline bool operator==(t59b20b8b0e4973a8b2e924c6f3f006db const &a, t59b20b8b0e4973a8b2e924c6f3f006db const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // AllSites
    case 1: return std::get<1>(a) == std::get<1>(b); // TheseSites
    case 2: return std::get<2>(a) == std::get<2>(b); // ThisSite
  };
  return false;
}
inline bool operator!=(t59b20b8b0e4973a8b2e924c6f3f006db const &a, t59b20b8b0e4973a8b2e924c6f3f006db const &b) {
  return !operator==(a, b);
}
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
inline bool operator==(t3ebe768f5b483383c74caad368fa4d1b const &a, t3ebe768f5b483383c74caad368fa4d1b const &b) {
  return std::get<0>(a) == std::get<0>(b) && ((std::get<1>(a) && std::get<1>(b) && std::get<1>(a).value() == std::get<1>(b).value()) || (!std::get<1>(a) && !std::get<1>(b))) && ::dessser::gen::function_name::Deref(std::get<2>(a)) == ::dessser::gen::function_name::Deref(std::get<2>(b));
}
inline bool operator!=(t3ebe768f5b483383c74caad368fa4d1b const &a, t3ebe768f5b483383c74caad368fa4d1b const &b) {
  return !operator==(a, b);
}
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

enum Constr_data_source {
  NamedOperation,
  SubQuery,
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
inline std::ostream &operator<<(std::ostream &os, data_source const &v) {
  switch (v.index()) {
    case 0: os << "NamedOperation " << std::get<0>(v); break;
    case 1: os << "SubQuery " << (*std::get<1>(v)); break;
  }
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tf0c8d4f3070907529cc1a83f8baf6fab : public std::tuple<
  uint32_t,
  std::optional<dessser::gen::raql_expr::t_ext>,
  Lst<dessser::gen::raql_expr::t_ext>
> { using tuple::tuple; };
inline bool operator==(tf0c8d4f3070907529cc1a83f8baf6fab const &a, tf0c8d4f3070907529cc1a83f8baf6fab const &b) {
  return std::get<0>(a) == std::get<0>(b) && ((std::get<1>(a) && std::get<1>(b) && ::dessser::gen::raql_expr::Deref(std::get<1>(a).value()) == ::dessser::gen::raql_expr::Deref(std::get<1>(b).value())) || (!std::get<1>(a) && !std::get<1>(b))) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(tf0c8d4f3070907529cc1a83f8baf6fab const &a, tf0c8d4f3070907529cc1a83f8baf6fab const &b) {
  return !operator==(a, b);
}
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
inline bool operator==(struct t const &, struct t const &);
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
inline std::ostream &operator<<(std::ostream &os, tbedd072c623fede5642d53b92db3bc60 const &r) {
  os << '{';
  if (r.and_all_others) os << "and_all_others:" << r.and_all_others.value() << ',';
  os << "commit_before:" << r.commit_before << ',';
  os << "commit_cond:" << ::dessser::gen::raql_expr::Deref(r.commit_cond) << ',';
  if (r.Aggregate_event_time) os << "Aggregate_event_time:" << ::dessser::gen::event_time::Deref(r.Aggregate_event_time.value()) << ',';
  if (r.every) os << "every:" << ::dessser::gen::raql_expr::Deref(r.every.value()) << ',';
  os << "Aggregate_factors:" << r.Aggregate_factors << ',';
  os << "Aggregate_fields:" << r.Aggregate_fields << ',';
  os << "flush_how:" << ::dessser::gen::raql_flush_method::Deref(r.flush_how) << ',';
  os << "from:" << r.from << ',';
  os << "key:" << r.key << ',';
  os << "notifications:" << r.notifications << ',';
  if (r.sort) os << "sort:" << r.sort.value() << ',';
  os << "where:" << ::dessser::gen::raql_expr::Deref(r.where);
  os << '}';
  return os;
}
inline bool operator==(tbedd072c623fede5642d53b92db3bc60 const &a, tbedd072c623fede5642d53b92db3bc60 const &b) {
  return ((a.and_all_others && b.and_all_others && a.and_all_others.value() == b.and_all_others.value()) || (!a.and_all_others && !b.and_all_others)) && a.commit_before == b.commit_before && ::dessser::gen::raql_expr::Deref(a.commit_cond) == ::dessser::gen::raql_expr::Deref(b.commit_cond) && ((a.Aggregate_event_time && b.Aggregate_event_time && ::dessser::gen::event_time::Deref(a.Aggregate_event_time.value()) == ::dessser::gen::event_time::Deref(b.Aggregate_event_time.value())) || (!a.Aggregate_event_time && !b.Aggregate_event_time)) && ((a.every && b.every && ::dessser::gen::raql_expr::Deref(a.every.value()) == ::dessser::gen::raql_expr::Deref(b.every.value())) || (!a.every && !b.every)) && a.Aggregate_factors == b.Aggregate_factors && a.Aggregate_fields == b.Aggregate_fields && ::dessser::gen::raql_flush_method::Deref(a.flush_how) == ::dessser::gen::raql_flush_method::Deref(b.flush_how) && a.from == b.from && a.key == b.key && a.notifications == b.notifications && ((a.sort && b.sort && a.sort.value() == b.sort.value()) || (!a.sort && !b.sort)) && ::dessser::gen::raql_expr::Deref(a.where) == ::dessser::gen::raql_expr::Deref(b.where);
}

inline bool operator!=(tbedd072c623fede5642d53b92db3bc60 const &a, tbedd072c623fede5642d53b92db3bc60 const &b) {
  return !operator==(a, b);
}
struct t61f013c74b0e45f17e9562bd5460b239 {
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::field_name::t_ext> ReadExternal_factors;
  ::dessser::gen::raql_operation::external_format* format;
  ::dessser::gen::raql_operation::external_source* source;
  t61f013c74b0e45f17e9562bd5460b239(std::optional<dessser::gen::event_time::t_ext> event_time_, Lst<dessser::gen::field_name::t_ext> ReadExternal_factors_, ::dessser::gen::raql_operation::external_format* format_, ::dessser::gen::raql_operation::external_source* source_) : event_time(event_time_), ReadExternal_factors(ReadExternal_factors_), format(format_), source(source_) {}
  t61f013c74b0e45f17e9562bd5460b239() = default;
};
inline std::ostream &operator<<(std::ostream &os, t61f013c74b0e45f17e9562bd5460b239 const &r) {
  os << '{';
  if (r.event_time) os << "event_time:" << ::dessser::gen::event_time::Deref(r.event_time.value()) << ',';
  os << "ReadExternal_factors:" << r.ReadExternal_factors << ',';
  os << "format:" << r.format << ',';
  os << "source:" << r.source;
  os << '}';
  return os;
}
inline bool operator==(t61f013c74b0e45f17e9562bd5460b239 const &a, t61f013c74b0e45f17e9562bd5460b239 const &b) {
  return ((a.event_time && b.event_time && ::dessser::gen::event_time::Deref(a.event_time.value()) == ::dessser::gen::event_time::Deref(b.event_time.value())) || (!a.event_time && !b.event_time)) && a.ReadExternal_factors == b.ReadExternal_factors && a.format == b.format && a.source == b.source;
}

inline bool operator!=(t61f013c74b0e45f17e9562bd5460b239 const &a, t61f013c74b0e45f17e9562bd5460b239 const &b) {
  return !operator==(a, b);
}
struct t5a75bfb14bb95ab8cf8a8b9296aea27d {
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string net_addr;
  uint16_t port;
  dessser::gen::raql_net_protocol::t_ext proto;
  t5a75bfb14bb95ab8cf8a8b9296aea27d(Lst<dessser::gen::field_name::t_ext> factors_, std::string net_addr_, uint16_t port_, dessser::gen::raql_net_protocol::t_ext proto_) : factors(factors_), net_addr(net_addr_), port(port_), proto(proto_) {}
  t5a75bfb14bb95ab8cf8a8b9296aea27d() = default;
};
inline std::ostream &operator<<(std::ostream &os, t5a75bfb14bb95ab8cf8a8b9296aea27d const &r) {
  os << '{';
  os << "factors:" << r.factors << ',';
  os << "net_addr:" << r.net_addr << ',';
  os << "port:" << r.port << ',';
  os << "proto:" << ::dessser::gen::raql_net_protocol::Deref(r.proto);
  os << '}';
  return os;
}
inline bool operator==(t5a75bfb14bb95ab8cf8a8b9296aea27d const &a, t5a75bfb14bb95ab8cf8a8b9296aea27d const &b) {
  return a.factors == b.factors && a.net_addr == b.net_addr && a.port == b.port && ::dessser::gen::raql_net_protocol::Deref(a.proto) == ::dessser::gen::raql_net_protocol::Deref(b.proto);
}

inline bool operator!=(t5a75bfb14bb95ab8cf8a8b9296aea27d const &a, t5a75bfb14bb95ab8cf8a8b9296aea27d const &b) {
  return !operator==(a, b);
}
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

enum Constr_t {
  Aggregate,
  ReadExternal,
  ListenFor,
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
inline bool operator==(struct t const &, struct t const &);
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
inline t Deref(t_ext x) { return *x; }

}
#endif
