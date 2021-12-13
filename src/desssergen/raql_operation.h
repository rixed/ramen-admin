#ifndef DESSSER_GEN_raql_operation
#define DESSSER_GEN_raql_operation
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
inline std::ostream &operator<<(std::ostream &os, t78cec4f9827249604fe947034c575f2a const &r) {
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
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t78cec4f9827249604fe947034c575f2a> const r) { os << *r; return os; }

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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<external_format> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t614b5d4c127c7065272d8dcc1f9877d3 const &r) {
  os << '{';
  os << "fname:" << r.fname << ',';
  if (r.preprocessor) os << "preprocessor:" << r.preprocessor.value() << ',';
  os << "unlink:" << r.unlink;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t614b5d4c127c7065272d8dcc1f9877d3> const r) { os << *r; return os; }

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
inline std::ostream &operator<<(std::ostream &os, td1e70aeaf070b9b0d0119e932e590179 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td1e70aeaf070b9b0d0119e932e590179> const t) { os << *t; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t66e84af8ac3d220e6953b809395192f8 const &r) {
  os << '{';
  os << "after_max_events:" << r.after_max_events << ',';
  os << "after_max_secs:" << r.after_max_secs;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t66e84af8ac3d220e6953b809395192f8> const r) { os << *r; return os; }

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
enum Constr_td6b783eb78996074f9384054f64b14ae {
  Beginning,
  OffsetFromEnd,
  SaveInState,
  UseKafkaGroupCoordinator,
};

inline std::ostream &operator<<(std::ostream &os, td6b783eb78996074f9384054f64b14ae const &v) {
  switch (v.index()) {
    case 0: os << "Beginning" << std::get<0>(v); break;
    case 1: os << "OffsetFromEnd " << std::get<1>(v); break;
    case 2: os << "SaveInState" << std::get<2>(v); break;
    case 3: os << "UseKafkaGroupCoordinator " << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td6b783eb78996074f9384054f64b14ae> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t39c49449a1a829aeb161993f390f9dbf const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  if (r.partitions) os << "partitions:" << r.partitions.value() << ',';
  os << "restart_from:" << r.restart_from << ',';
  os << "topic:" << r.topic;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t39c49449a1a829aeb161993f390f9dbf> const r) { os << *r; return os; }

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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<external_source> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t818559b68b475733e8c99b87db21c5d3 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t818559b68b475733e8c99b87db21c5d3> const t) { os << *t; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t8b60740739dfc5a7cf5f2b99a1358fa6 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t8b60740739dfc5a7cf5f2b99a1358fa6> const t) { os << *t; return os; }

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
enum Constr_t054d75b46129860c650f4e7e4e60a6f9 {
  AllSites,
  TheseSites,
  ThisSite,
};

inline std::ostream &operator<<(std::ostream &os, t054d75b46129860c650f4e7e4e60a6f9 const &v) {
  switch (v.index()) {
    case 0: os << "AllSites" << std::get<0>(v); break;
    case 1: os << "TheseSites " << std::get<1>(v); break;
    case 2: os << "ThisSite" << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t054d75b46129860c650f4e7e4e60a6f9> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, ted682f302d97794f7d8af77b7693b421 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  if (std::get<1>(t)) os << std::get<1>(t).value() << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ted682f302d97794f7d8af77b7693b421> const t) { os << *t; return os; }

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
enum Constr_data_source {
  NamedOperation,
  SubQuery,
};

inline std::ostream &operator<<(std::ostream &os, data_source const &v) {
  switch (v.index()) {
    case 0: os << "NamedOperation " << std::get<0>(v); break;
    case 1: os << "SubQuery " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<data_source> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t75cceda8358977a4781ef44dda7fab07 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  if (std::get<1>(t)) os << std::get<1>(t).value() << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t75cceda8358977a4781ef44dda7fab07> const t) { os << *t; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t2924eb63c15624d94238446da8ddd5a5 const &r) {
  os << '{';
  if (r.and_all_others) os << "and_all_others:" << r.and_all_others.value() << ',';
  os << "commit_before:" << r.commit_before << ',';
  os << "commit_cond:" << r.commit_cond << ',';
  if (r.Aggregate_event_time) os << "Aggregate_event_time:" << r.Aggregate_event_time.value() << ',';
  if (r.every) os << "every:" << r.every.value() << ',';
  os << "Aggregate_factors:" << r.Aggregate_factors << ',';
  os << "Aggregate_fields:" << r.Aggregate_fields << ',';
  os << "flush_how:" << r.flush_how << ',';
  os << "from:" << r.from << ',';
  os << "key:" << r.key << ',';
  os << "notifications:" << r.notifications << ',';
  if (r.sort) os << "sort:" << r.sort.value() << ',';
  os << "where:" << r.where;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2924eb63c15624d94238446da8ddd5a5> const r) { os << *r; return os; }

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
inline std::ostream &operator<<(std::ostream &os, teabb4aa6beb374b8a3faf63ed92e59d1 const &r) {
  os << '{';
  if (r.event_time) os << "event_time:" << r.event_time.value() << ',';
  os << "ReadExternal_factors:" << r.ReadExternal_factors << ',';
  os << "format:" << r.format << ',';
  os << "source:" << r.source;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<teabb4aa6beb374b8a3faf63ed92e59d1> const r) { os << *r; return os; }

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
inline std::ostream &operator<<(std::ostream &os, tfb55a595623604efa44696c62f9afcc5 const &r) {
  os << '{';
  os << "factors:" << r.factors << ',';
  os << "net_addr:" << r.net_addr << ',';
  os << "port:" << r.port << ',';
  os << "proto:" << r.proto;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tfb55a595623604efa44696c62f9afcc5> const r) { os << *r; return os; }

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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
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
inline std::ostream &operator<<(std::ostream &os, t063f95ee917f7168b9cc40076caa81fd const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t063f95ee917f7168b9cc40076caa81fd> const t) { os << *t; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t686eed8ab9a7b5a11ecf622b72433681 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t686eed8ab9a7b5a11ecf622b72433681> const t) { os << *t; return os; }

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::external_format> ,Pointer)> external_format_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::external_source> ,Pointer)> external_source_to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::external_format> )> external_format_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::external_source> )> external_source_sersize_of_row_binary;
extern std::function<::dessser::gen::raql_operation::t818559b68b475733e8c99b87db21c5d3(Pointer)> external_format_of_row_binary;
extern std::function<::dessser::gen::raql_operation::t8b60740739dfc5a7cf5f2b99a1358fa6(Pointer)> external_source_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> wrap_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::data_source> ,Pointer)> data_source_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_operation::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::data_source> )> data_source_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_operation::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> wrap_of_row_binary;
extern std::function<::dessser::gen::raql_operation::t686eed8ab9a7b5a11ecf622b72433681(Pointer)> data_source_of_row_binary;
extern std::function<::dessser::gen::raql_operation::t063f95ee917f7168b9cc40076caa81fd(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
