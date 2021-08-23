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
struct t426ec5a4dbcd1c52e1e8ea09a6e19f05 {
  bool clickhouse_syntax;
  std::string escape_seq;
  Lst<dessser::gen::field_type::t_ext> fields;
  bool may_quote;
  std::string null;
  char separator;
  bool vectors_of_chars_as_string;
  bool operator==(t426ec5a4dbcd1c52e1e8ea09a6e19f05 const &other) const {
    return clickhouse_syntax == other.clickhouse_syntax && escape_seq == other.escape_seq && fields == other.fields && may_quote == other.may_quote && null == other.null && separator == other.separator && vectors_of_chars_as_string == other.vectors_of_chars_as_string;
  }
};
inline std::ostream &operator<<(std::ostream &os, t426ec5a4dbcd1c52e1e8ea09a6e19f05 const &r) {
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
  ::dessser::gen::raql_operation::t426ec5a4dbcd1c52e1e8ea09a6e19f05,
  Lst<dessser::gen::field_type::t_ext>
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, external_format const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct ta828a76692b94aa6a15973ace224bedc {
  dessser::gen::raql_expr::t_ext fname;
  std::optional<dessser::gen::raql_expr::t_ext> preprocessor;
  dessser::gen::raql_expr::t_ext unlink;
  bool operator==(ta828a76692b94aa6a15973ace224bedc const &other) const {
    return fname == other.fname && preprocessor == other.preprocessor && unlink == other.unlink;
  }
};
inline std::ostream &operator<<(std::ostream &os, ta828a76692b94aa6a15973ace224bedc const &r) {
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

struct td384feca89a39ea894720b77f112b9a1 {
  dessser::gen::raql_expr::t_ext after_max_events;
  dessser::gen::raql_expr::t_ext after_max_secs;
  bool operator==(td384feca89a39ea894720b77f112b9a1 const &other) const {
    return after_max_events == other.after_max_events && after_max_secs == other.after_max_secs;
  }
};
inline std::ostream &operator<<(std::ostream &os, td384feca89a39ea894720b77f112b9a1 const &r) {
  os << '{';
  os << "after_max_events:" << r.after_max_events << ',';
  os << "after_max_secs:" << r.after_max_secs;
  os << '}';
  return os;
}

struct t7a8fc89a12bc01e52d320b2a51383e19 : public std::variant<
  Void,
  dessser::gen::raql_expr::t_ext,
  Void,
  ::dessser::gen::raql_operation::td384feca89a39ea894720b77f112b9a1
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t7a8fc89a12bc01e52d320b2a51383e19 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

struct t178d9283de83572f00c66ee7dba54b24 {
  Lst<::dessser::gen::raql_operation::tcd17c85cefeae7a860c0732c05eaeaed> options;
  std::optional<dessser::gen::raql_expr::t_ext> partitions;
  ::dessser::gen::raql_operation::t7a8fc89a12bc01e52d320b2a51383e19 restart_from;
  dessser::gen::raql_expr::t_ext topic;
  bool operator==(t178d9283de83572f00c66ee7dba54b24 const &other) const {
    return options == other.options && partitions == other.partitions && restart_from == other.restart_from && topic == other.topic;
  }
};
inline std::ostream &operator<<(std::ostream &os, t178d9283de83572f00c66ee7dba54b24 const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "partitions:" << r.partitions << ',';
  os << "restart_from:" << r.restart_from << ',';
  os << "topic:" << r.topic;
  os << '}';
  return os;
}

struct external_source : public std::variant<
  ::dessser::gen::raql_operation::ta828a76692b94aa6a15973ace224bedc,
  ::dessser::gen::raql_operation::t178d9283de83572f00c66ee7dba54b24
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, external_source const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
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

struct te10a95f610a64bfb7ccea542c54f0a25 : public std::variant<
  Void,
  std::string,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, te10a95f610a64bfb7ccea542c54f0a25 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct td4b444f3ed9452640dbc7f7aab54c9b5 : public std::tuple<
  ::dessser::gen::raql_operation::te10a95f610a64bfb7ccea542c54f0a25,
  std::optional<std::string>,
  dessser::gen::function_name::t_ext
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, td4b444f3ed9452640dbc7f7aab54c9b5 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t;
struct t;
struct data_source : public std::variant<
  ::dessser::gen::raql_operation::td4b444f3ed9452640dbc7f7aab54c9b5,
  t*
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, data_source const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t;
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
struct t88a98b9fc1e57e97e91c2ec6b9980a71 {
  std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others;
  bool commit_before;
  dessser::gen::raql_expr::t_ext commit_cond;
  std::optional<dessser::gen::event_time::t_ext> event_time;
  std::optional<dessser::gen::raql_expr::t_ext> every;
  Lst<dessser::gen::field_name::t_ext> factors;
  Lst<dessser::gen::raql_select_field::t_ext> fields;
  dessser::gen::raql_flush_method::t_ext flush_how;
  Lst<::dessser::gen::raql_operation::data_source*> from;
  Lst<dessser::gen::raql_expr::t_ext> key;
  Lst<dessser::gen::raql_expr::t_ext> notifications;
  std::optional<::dessser::gen::raql_operation::tf0c8d4f3070907529cc1a83f8baf6fab> sort;
  dessser::gen::raql_expr::t_ext where;
  bool operator==(t88a98b9fc1e57e97e91c2ec6b9980a71 const &other) const {
    return and_all_others == other.and_all_others && commit_before == other.commit_before && commit_cond == other.commit_cond && event_time == other.event_time && every == other.every && factors == other.factors && fields == other.fields && flush_how == other.flush_how && from == other.from && key == other.key && notifications == other.notifications && sort == other.sort && where == other.where;
  }
};
inline std::ostream &operator<<(std::ostream &os, t88a98b9fc1e57e97e91c2ec6b9980a71 const &r) {
  os << '{';
  os << "and_all_others:" << r.and_all_others << ',';
  os << "commit_before:" << r.commit_before << ',';
  os << "commit_cond:" << r.commit_cond << ',';
  os << "event_time:" << r.event_time << ',';
  os << "every:" << r.every << ',';
  os << "factors:" << r.factors << ',';
  os << "fields:" << r.fields << ',';
  os << "flush_how:" << r.flush_how << ',';
  os << "from:" << r.from << ',';
  os << "key:" << r.key << ',';
  os << "notifications:" << r.notifications << ',';
  os << "sort:" << r.sort << ',';
  os << "where:" << r.where;
  os << '}';
  return os;
}

struct t77f719ca910b4bd51d6b275eaca24bc2 {
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::field_name::t_ext> factors;
  ::dessser::gen::raql_operation::external_format* format;
  ::dessser::gen::raql_operation::external_source* source;
  bool operator==(t77f719ca910b4bd51d6b275eaca24bc2 const &other) const {
    return event_time == other.event_time && factors == other.factors && format == other.format && source == other.source;
  }
};
inline std::ostream &operator<<(std::ostream &os, t77f719ca910b4bd51d6b275eaca24bc2 const &r) {
  os << '{';
  os << "event_time:" << r.event_time << ',';
  os << "factors:" << r.factors << ',';
  os << "format:" << r.format << ',';
  os << "source:" << r.source;
  os << '}';
  return os;
}

struct t2afb8ad736953f66a8b1dc4bc6b2a746 {
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string net_addr;
  uint16_t port;
  dessser::gen::raql_net_protocol::t_ext proto;
  bool operator==(t2afb8ad736953f66a8b1dc4bc6b2a746 const &other) const {
    return factors == other.factors && net_addr == other.net_addr && port == other.port && proto == other.proto;
  }
};
inline std::ostream &operator<<(std::ostream &os, t2afb8ad736953f66a8b1dc4bc6b2a746 const &r) {
  os << '{';
  os << "factors:" << r.factors << ',';
  os << "net_addr:" << r.net_addr << ',';
  os << "port:" << r.port << ',';
  os << "proto:" << r.proto;
  os << '}';
  return os;
}

struct t;
struct t : public std::variant<
  ::dessser::gen::raql_operation::t88a98b9fc1e57e97e91c2ec6b9980a71,
  ::dessser::gen::raql_operation::t77f719ca910b4bd51d6b275eaca24bc2,
  ::dessser::gen::raql_operation::t2afb8ad736953f66a8b1dc4bc6b2a746
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  ::dessser::gen::raql_operation::data_source*,
  Pointer
> tcd2420ce0244df52965bf04a8e398ab3;

struct t;
struct t;
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
