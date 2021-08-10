#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct b48f9480e4991d15124ad477c5cb330e : public std::tuple<
  uint32_t,
  std::optional<*raql_expr>,
  Lst<*raql_expr>
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, b48f9480e4991d15124ad477c5cb330e const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct v_3cd54ea1158497be65dc13cca6d4b046 : public std::variant<
  Void,
  std::string,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_3cd54ea1158497be65dc13cca6d4b046 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct v_9054563dd112d3f48469dddea6b8194e : public std::tuple<
  v_3cd54ea1158497be65dc13cca6d4b046,
  std::optional<std::string>,
  *function_name
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_9054563dd112d3f48469dddea6b8194e const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct ee20956156b3a0bf3ed4185051a85c84 : public std::variant<
  v_9054563dd112d3f48469dddea6b8194e,
  t*
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, ee20956156b3a0bf3ed4185051a85c84 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct v_41bb77c6ca1cb4242e451c68e9cdbd6c {
  Lst<*raql_select_field> fields;
  std::optional<Lst<*field_name>> and_all_others;
  std::optional<b48f9480e4991d15124ad477c5cb330e> sort;
  *raql_expr where;
  std::optional<*event_time> event_time;
  Lst<*raql_expr> notifications;
  Lst<*raql_expr> key;
  *raql_expr commit_cond;
  bool commit_before;
  *raql_flush_method flush_how;
  Lst<ee20956156b3a0bf3ed4185051a85c84> from;
  std::optional<*raql_expr> every;
  Lst<*field_name> factors;
  bool operator==(v_41bb77c6ca1cb4242e451c68e9cdbd6c const &other) const {
    return fields == other.fields && and_all_others == other.and_all_others && sort == other.sort && where == other.where && event_time == other.event_time && notifications == other.notifications && key == other.key && commit_cond == other.commit_cond && commit_before == other.commit_before && flush_how == other.flush_how && from == other.from && every == other.every && factors == other.factors;
  }
};
std::ostream &operator<<(std::ostream &os, v_41bb77c6ca1cb4242e451c68e9cdbd6c const &r) {
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

struct v_65abbca6f6205aebd6740de88f9e9235 {
  *raql_expr fname;
  std::optional<*raql_expr> preprocessor;
  *raql_expr unlink;
  bool operator==(v_65abbca6f6205aebd6740de88f9e9235 const &other) const {
    return fname == other.fname && preprocessor == other.preprocessor && unlink == other.unlink;
  }
};
std::ostream &operator<<(std::ostream &os, v_65abbca6f6205aebd6740de88f9e9235 const &r) {
  os << '{';
  os << "fname:" << r.fname << ',';
  os << "preprocessor:" << r.preprocessor << ',';
  os << "unlink:" << r.unlink;
  os << '}';
  return os;
}

typedef std::tuple<
  std::string,
  *raql_expr
> df398bbef680305e3e9f5137633156fb;

struct e1d3e929c0a104569907bf46832d32c2 {
  *raql_expr after_max_secs;
  *raql_expr after_max_events;
  bool operator==(e1d3e929c0a104569907bf46832d32c2 const &other) const {
    return after_max_secs == other.after_max_secs && after_max_events == other.after_max_events;
  }
};
std::ostream &operator<<(std::ostream &os, e1d3e929c0a104569907bf46832d32c2 const &r) {
  os << '{';
  os << "after_max_secs:" << r.after_max_secs << ',';
  os << "after_max_events:" << r.after_max_events;
  os << '}';
  return os;
}

struct v_39cf200fa778e5fa84401746e9b5ba70 : public std::variant<
  Void,
  *raql_expr,
  Void,
  e1d3e929c0a104569907bf46832d32c2
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_39cf200fa778e5fa84401746e9b5ba70 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

struct v_81cd54ad1d16b1060af71b31d87d9f09 {
  Lst<df398bbef680305e3e9f5137633156fb> options;
  *raql_expr topic;
  std::optional<*raql_expr> partitions;
  v_39cf200fa778e5fa84401746e9b5ba70 restart_from;
  bool operator==(v_81cd54ad1d16b1060af71b31d87d9f09 const &other) const {
    return options == other.options && topic == other.topic && partitions == other.partitions && restart_from == other.restart_from;
  }
};
std::ostream &operator<<(std::ostream &os, v_81cd54ad1d16b1060af71b31d87d9f09 const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "topic:" << r.topic << ',';
  os << "partitions:" << r.partitions << ',';
  os << "restart_from:" << r.restart_from;
  os << '}';
  return os;
}

struct v_8c0c938be0fcefc45cc5b9cf52c46f04 : public std::variant<
  v_65abbca6f6205aebd6740de88f9e9235,
  v_81cd54ad1d16b1060af71b31d87d9f09
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_8c0c938be0fcefc45cc5b9cf52c46f04 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct v_951168fd627e4197ab60b5fba89b770b {
  char separator;
  std::string null;
  bool may_quote;
  std::string escape_seq;
  Lst<*field_type> fields;
  bool vectors_of_chars_as_string;
  bool clickhouse_syntax;
  bool operator==(v_951168fd627e4197ab60b5fba89b770b const &other) const {
    return separator == other.separator && null == other.null && may_quote == other.may_quote && escape_seq == other.escape_seq && fields == other.fields && vectors_of_chars_as_string == other.vectors_of_chars_as_string && clickhouse_syntax == other.clickhouse_syntax;
  }
};
std::ostream &operator<<(std::ostream &os, v_951168fd627e4197ab60b5fba89b770b const &r) {
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

struct v_21e8c6eca31cc038e9faa45d5b86bfa4 : public std::variant<
  v_951168fd627e4197ab60b5fba89b770b,
  Lst<*field_type>
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_21e8c6eca31cc038e9faa45d5b86bfa4 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct c1efb28eecd443c961e69845a587fe0d {
  v_8c0c938be0fcefc45cc5b9cf52c46f04 source;
  v_21e8c6eca31cc038e9faa45d5b86bfa4 format;
  std::optional<*event_time> event_time;
  Lst<*field_name> factors;
  bool operator==(c1efb28eecd443c961e69845a587fe0d const &other) const {
    return source == other.source && format == other.format && event_time == other.event_time && factors == other.factors;
  }
};
std::ostream &operator<<(std::ostream &os, c1efb28eecd443c961e69845a587fe0d const &r) {
  os << '{';
  os << "source:" << r.source << ',';
  os << "format:" << r.format << ',';
  os << "event_time:" << r.event_time << ',';
  os << "factors:" << r.factors;
  os << '}';
  return os;
}

struct v_00380e3ab86a3786288b2307b930623c {
  std::string net_addr;
  uint16_t port;
  *raql_net_protocol proto;
  Lst<*field_name> factors;
  bool operator==(v_00380e3ab86a3786288b2307b930623c const &other) const {
    return net_addr == other.net_addr && port == other.port && proto == other.proto && factors == other.factors;
  }
};
std::ostream &operator<<(std::ostream &os, v_00380e3ab86a3786288b2307b930623c const &r) {
  os << '{';
  os << "net_addr:" << r.net_addr << ',';
  os << "port:" << r.port << ',';
  os << "proto:" << r.proto << ',';
  os << "factors:" << r.factors;
  os << '}';
  return os;
}

struct t : public std::variant<
  v_41bb77c6ca1cb4242e451c68e9cdbd6c,
  c1efb28eecd443c961e69845a587fe0d,
  v_00380e3ab86a3786288b2307b930623c
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
