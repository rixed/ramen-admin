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
struct t978119ec4804fe1beafe149279a598a7 : public std::tuple<
  uint32_t,
  std::optional<dessser::gen::raql_expr::t_ext>,
  Lst<dessser::gen::raql_expr::t_ext>
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t978119ec4804fe1beafe149279a598a7 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t124e1eaf5345ab040f6cf2c6d4415b6f : public std::variant<
  Void,
  std::string,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t124e1eaf5345ab040f6cf2c6d4415b6f const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct ta1c9f116b978b2c90d3950772e905981 : public std::tuple<
  t124e1eaf5345ab040f6cf2c6d4415b6f,
  std::optional<std::string>,
  dessser::gen::function_name::t_ext
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, ta1c9f116b978b2c90d3950772e905981 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t;
struct t;
struct t7da54469969b50af78862e8c5959f1ce : public std::variant<
  ta1c9f116b978b2c90d3950772e905981,
  t*
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t7da54469969b50af78862e8c5959f1ce const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t;
struct t3966dd3c208c246b362b34303a623597 {
  Lst<dessser::gen::raql_select_field::t_ext> fields;
  std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others;
  std::optional<t978119ec4804fe1beafe149279a598a7> sort;
  dessser::gen::raql_expr::t_ext where;
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::raql_expr::t_ext> notifications;
  Lst<dessser::gen::raql_expr::t_ext> key;
  dessser::gen::raql_expr::t_ext commit_cond;
  bool commit_before;
  dessser::gen::raql_flush_method::t_ext flush_how;
  Lst<t7da54469969b50af78862e8c5959f1ce> from;
  std::optional<dessser::gen::raql_expr::t_ext> every;
  Lst<dessser::gen::field_name::t_ext> factors;
  bool operator==(t3966dd3c208c246b362b34303a623597 const &other) const {
    return fields == other.fields && and_all_others == other.and_all_others && sort == other.sort && where == other.where && event_time == other.event_time && notifications == other.notifications && key == other.key && commit_cond == other.commit_cond && commit_before == other.commit_before && flush_how == other.flush_how && from == other.from && every == other.every && factors == other.factors;
  }
};
inline std::ostream &operator<<(std::ostream &os, t3966dd3c208c246b362b34303a623597 const &r) {
  os << '{';
  os << "fields:" << r.fields << ',';
  os << "and_all_others:" << r.and_all_others << ',';
  os << "sort:" << r.sort << ',';
  os << "where:" << r.where << ',';
  os << "event_time:" << r.event_time << ',';
  os << "notifications:" << r.notifications << ',';
  os << "key:" << r.key << ',';
  os << "commit_cond:" << r.commit_cond << ',';
  os << "commit_before:" << r.commit_before << ',';
  os << "flush_how:" << r.flush_how << ',';
  os << "from:" << r.from << ',';
  os << "every:" << r.every << ',';
  os << "factors:" << r.factors;
  os << '}';
  return os;
}

struct t8c7277ad4eb8c988a5ff7487f8638df9 {
  dessser::gen::raql_expr::t_ext fname;
  std::optional<dessser::gen::raql_expr::t_ext> preprocessor;
  dessser::gen::raql_expr::t_ext unlink;
  bool operator==(t8c7277ad4eb8c988a5ff7487f8638df9 const &other) const {
    return fname == other.fname && preprocessor == other.preprocessor && unlink == other.unlink;
  }
};
inline std::ostream &operator<<(std::ostream &os, t8c7277ad4eb8c988a5ff7487f8638df9 const &r) {
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

struct t17e8572d018d99204a8a9d98eef130cb {
  dessser::gen::raql_expr::t_ext after_max_secs;
  dessser::gen::raql_expr::t_ext after_max_events;
  bool operator==(t17e8572d018d99204a8a9d98eef130cb const &other) const {
    return after_max_secs == other.after_max_secs && after_max_events == other.after_max_events;
  }
};
inline std::ostream &operator<<(std::ostream &os, t17e8572d018d99204a8a9d98eef130cb const &r) {
  os << '{';
  os << "after_max_secs:" << r.after_max_secs << ',';
  os << "after_max_events:" << r.after_max_events;
  os << '}';
  return os;
}

struct tfc0bba058a46a5467de1e4d7e2050289 : public std::variant<
  Void,
  dessser::gen::raql_expr::t_ext,
  Void,
  t17e8572d018d99204a8a9d98eef130cb
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tfc0bba058a46a5467de1e4d7e2050289 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

struct t8365673450ffea740621e6cd0100181b {
  Lst<tcd17c85cefeae7a860c0732c05eaeaed> options;
  dessser::gen::raql_expr::t_ext topic;
  std::optional<dessser::gen::raql_expr::t_ext> partitions;
  tfc0bba058a46a5467de1e4d7e2050289 restart_from;
  bool operator==(t8365673450ffea740621e6cd0100181b const &other) const {
    return options == other.options && topic == other.topic && partitions == other.partitions && restart_from == other.restart_from;
  }
};
inline std::ostream &operator<<(std::ostream &os, t8365673450ffea740621e6cd0100181b const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "topic:" << r.topic << ',';
  os << "partitions:" << r.partitions << ',';
  os << "restart_from:" << r.restart_from;
  os << '}';
  return os;
}

struct t32a5353d5fcce6ecaf36a03f218fdaf5 : public std::variant<
  t8c7277ad4eb8c988a5ff7487f8638df9,
  t8365673450ffea740621e6cd0100181b
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t32a5353d5fcce6ecaf36a03f218fdaf5 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t8d81361e7d6b79b719aef47c8ef3fc4a {
  char separator;
  std::string null;
  bool may_quote;
  std::string escape_seq;
  Lst<dessser::gen::field_type::t_ext> fields;
  bool vectors_of_chars_as_string;
  bool clickhouse_syntax;
  bool operator==(t8d81361e7d6b79b719aef47c8ef3fc4a const &other) const {
    return separator == other.separator && null == other.null && may_quote == other.may_quote && escape_seq == other.escape_seq && fields == other.fields && vectors_of_chars_as_string == other.vectors_of_chars_as_string && clickhouse_syntax == other.clickhouse_syntax;
  }
};
inline std::ostream &operator<<(std::ostream &os, t8d81361e7d6b79b719aef47c8ef3fc4a const &r) {
  os << '{';
  os << "separator:" << r.separator << ',';
  os << "null:" << r.null << ',';
  os << "may_quote:" << r.may_quote << ',';
  os << "escape_seq:" << r.escape_seq << ',';
  os << "fields:" << r.fields << ',';
  os << "vectors_of_chars_as_string:" << r.vectors_of_chars_as_string << ',';
  os << "clickhouse_syntax:" << r.clickhouse_syntax;
  os << '}';
  return os;
}

struct tb31b81740e8b77155ad94b854b5f0a7b : public std::variant<
  t8d81361e7d6b79b719aef47c8ef3fc4a,
  Lst<dessser::gen::field_type::t_ext>
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tb31b81740e8b77155ad94b854b5f0a7b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct tb873d876c7db336faf85688620b63cf4 {
  t32a5353d5fcce6ecaf36a03f218fdaf5 source;
  tb31b81740e8b77155ad94b854b5f0a7b format;
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::field_name::t_ext> factors;
  bool operator==(tb873d876c7db336faf85688620b63cf4 const &other) const {
    return source == other.source && format == other.format && event_time == other.event_time && factors == other.factors;
  }
};
inline std::ostream &operator<<(std::ostream &os, tb873d876c7db336faf85688620b63cf4 const &r) {
  os << '{';
  os << "source:" << r.source << ',';
  os << "format:" << r.format << ',';
  os << "event_time:" << r.event_time << ',';
  os << "factors:" << r.factors;
  os << '}';
  return os;
}

struct t7ee51a8dd93a5fe5d6d36c4c2ccb770c {
  std::string net_addr;
  uint16_t port;
  dessser::gen::raql_net_protocol::t_ext proto;
  Lst<dessser::gen::field_name::t_ext> factors;
  bool operator==(t7ee51a8dd93a5fe5d6d36c4c2ccb770c const &other) const {
    return net_addr == other.net_addr && port == other.port && proto == other.proto && factors == other.factors;
  }
};
inline std::ostream &operator<<(std::ostream &os, t7ee51a8dd93a5fe5d6d36c4c2ccb770c const &r) {
  os << '{';
  os << "net_addr:" << r.net_addr << ',';
  os << "port:" << r.port << ',';
  os << "proto:" << r.proto << ',';
  os << "factors:" << r.factors;
  os << '}';
  return os;
}

struct t;
struct t : public std::variant<
  t3966dd3c208c246b362b34303a623597,
  tb873d876c7db336faf85688620b63cf4,
  t7ee51a8dd93a5fe5d6d36c4c2ccb770c
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
typedef std::tuple<
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t*,Pointer)> to_row_binary;
extern std::function<Size(t*)> sersize_of_row_binary;
extern std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
