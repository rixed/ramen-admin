#ifndef DESSSER_GEN_source_info
#define DESSSER_GEN_source_info
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/src_path.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_operation.h"
#include "desssergen/retention.h"
#include "desssergen/function_name.h"
#include "desssergen/global_variable.h"
#include "desssergen/raql_expr.h"
#include "desssergen/program_parameter.h"

namespace dessser::gen::source_info {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct compiled_func {
  std::string doc;
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string in_signature;
  bool is_lazy;
  dessser::gen::function_name::t_ext name;
  dessser::gen::raql_operation::t_ext operation;
  dessser::gen::raql_type::t_ext out_record;
  std::optional<dessser::gen::retention::t_ext> retention;
  std::string signature;
  compiled_func(std::string doc_, Lst<dessser::gen::field_name::t_ext> factors_, std::string in_signature_, bool is_lazy_, dessser::gen::function_name::t_ext name_, dessser::gen::raql_operation::t_ext operation_, dessser::gen::raql_type::t_ext out_record_, std::optional<dessser::gen::retention::t_ext> retention_, std::string signature_) : doc(doc_), factors(factors_), in_signature(in_signature_), is_lazy(is_lazy_), name(name_), operation(operation_), out_record(out_record_), retention(retention_), signature(signature_) {}
  compiled_func() = default;
};
inline std::ostream &operator<<(std::ostream &os, compiled_func const &r) {
  os << '{';
  os << "doc:" << r.doc << ',';
  os << "factors:" << r.factors << ',';
  os << "in_signature:" << r.in_signature << ',';
  os << "is_lazy:" << r.is_lazy << ',';
  os << "name:" << r.name << ',';
  os << "operation:" << r.operation << ',';
  os << "out_record:" << r.out_record << ',';
  if (r.retention) os << "retention:" << r.retention.value() << ',';
  os << "signature:" << r.signature;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<compiled_func> const r) { os << *r; return os; }

inline bool operator==(compiled_func const &a, compiled_func const &b) {
  return a.doc == b.doc && a.factors == b.factors && a.in_signature == b.in_signature && a.is_lazy == b.is_lazy && ::dessser::gen::function_name::Deref(a.name) == ::dessser::gen::function_name::Deref(b.name) && ::dessser::gen::raql_operation::Deref(a.operation) == ::dessser::gen::raql_operation::Deref(b.operation) && ::dessser::gen::raql_type::Deref(a.out_record) == ::dessser::gen::raql_type::Deref(b.out_record) && ((a.retention && b.retention && ::dessser::gen::retention::Deref(a.retention.value()) == ::dessser::gen::retention::Deref(b.retention.value())) || (!a.retention && !b.retention)) && a.signature == b.signature;
}

inline bool operator!=(compiled_func const &a, compiled_func const &b) {
  return !operator==(a, b);
}
struct compiled_program {
  dessser::gen::raql_expr::t_ext condition;
  Lst<dessser::gen::program_parameter::t_ext> default_params;
  Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > funcs;
  Lst<dessser::gen::global_variable::t_ext> globals;
  compiled_program(dessser::gen::raql_expr::t_ext condition_, Lst<dessser::gen::program_parameter::t_ext> default_params_, Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > funcs_, Lst<dessser::gen::global_variable::t_ext> globals_) : condition(condition_), default_params(default_params_), funcs(funcs_), globals(globals_) {}
  compiled_program() = default;
};
inline std::ostream &operator<<(std::ostream &os, compiled_program const &r) {
  os << '{';
  os << "condition:" << r.condition << ',';
  os << "default_params:" << r.default_params << ',';
  os << "funcs:" << r.funcs << ',';
  os << "globals:" << r.globals;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<compiled_program> const r) { os << *r; return os; }

inline bool operator==(compiled_program const &a, compiled_program const &b) {
  return ::dessser::gen::raql_expr::Deref(a.condition) == ::dessser::gen::raql_expr::Deref(b.condition) && a.default_params == b.default_params && a.funcs == b.funcs && a.globals == b.globals;
}

inline bool operator!=(compiled_program const &a, compiled_program const &b) {
  return !operator==(a, b);
}
struct t88a6703da8448662bc6d4e57390c3cfd {
  std::optional<dessser::gen::src_path::t_ext> depends_on;
  std::string err_msg;
  t88a6703da8448662bc6d4e57390c3cfd(std::optional<dessser::gen::src_path::t_ext> depends_on_, std::string err_msg_) : depends_on(depends_on_), err_msg(err_msg_) {}
  t88a6703da8448662bc6d4e57390c3cfd() = default;
};
inline std::ostream &operator<<(std::ostream &os, t88a6703da8448662bc6d4e57390c3cfd const &r) {
  os << '{';
  if (r.depends_on) os << "depends_on:" << r.depends_on.value() << ',';
  os << "err_msg:" << r.err_msg;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t88a6703da8448662bc6d4e57390c3cfd> const r) { os << *r; return os; }

inline bool operator==(t88a6703da8448662bc6d4e57390c3cfd const &a, t88a6703da8448662bc6d4e57390c3cfd const &b) {
  return ((a.depends_on && b.depends_on && ::dessser::gen::src_path::Deref(a.depends_on.value()) == ::dessser::gen::src_path::Deref(b.depends_on.value())) || (!a.depends_on && !b.depends_on)) && a.err_msg == b.err_msg;
}

inline bool operator!=(t88a6703da8448662bc6d4e57390c3cfd const &a, t88a6703da8448662bc6d4e57390c3cfd const &b) {
  return !operator==(a, b);
}
struct t6053a864da647a621fc35e881a801a97 : public std::variant<
  std::shared_ptr<::dessser::gen::source_info::compiled_program> , // Compiled
  ::dessser::gen::source_info::t88a6703da8448662bc6d4e57390c3cfd // Failed
> { using variant::variant; };

enum Constr_t6053a864da647a621fc35e881a801a97 {
  Compiled,
  Failed,
};

inline std::ostream &operator<<(std::ostream &os, t6053a864da647a621fc35e881a801a97 const &v) {
  switch (v.index()) {
    case 0: os << "Compiled " << std::get<0>(v); break;
    case 1: os << "Failed " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t6053a864da647a621fc35e881a801a97> const v) { os << *v; return os; }

inline bool operator==(t6053a864da647a621fc35e881a801a97 const &a, t6053a864da647a621fc35e881a801a97 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return (*std::get<0>(a)) == (*std::get<0>(b)); // Compiled
    case 1: return std::get<1>(a) == std::get<1>(b); // Failed
  };
  return false;
}
inline bool operator!=(t6053a864da647a621fc35e881a801a97 const &a, t6053a864da647a621fc35e881a801a97 const &b) {
  return !operator==(a, b);
}
struct t {
  ::dessser::gen::source_info::t6053a864da647a621fc35e881a801a97 detail;
  Lst<std::string> md5s;
  std::string src_ext;
  t(::dessser::gen::source_info::t6053a864da647a621fc35e881a801a97 detail_, Lst<std::string> md5s_, std::string src_ext_) : detail(detail_), md5s(md5s_), src_ext(src_ext_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "detail:" << r.detail << ',';
  os << "md5s:" << r.md5s << ',';
  os << "src_ext:" << r.src_ext;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

inline bool operator==(t const &a, t const &b) {
  return a.detail == b.detail && a.md5s == b.md5s && a.src_ext == b.src_ext;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tf10028d8c172b81c81f09681b7ea7fa0 : public std::tuple<
  std::shared_ptr<::dessser::gen::source_info::compiled_func> ,
  Pointer
> {
  using tuple::tuple;
  tf10028d8c172b81c81f09681b7ea7fa0(std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_func> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_func> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf10028d8c172b81c81f09681b7ea7fa0 const &a, tf10028d8c172b81c81f09681b7ea7fa0 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf10028d8c172b81c81f09681b7ea7fa0 const &a, tf10028d8c172b81c81f09681b7ea7fa0 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf10028d8c172b81c81f09681b7ea7fa0 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

struct tab14cca2da8a1bf7815d3cb326bdebb2 : public std::tuple<
  std::shared_ptr<::dessser::gen::source_info::compiled_program> ,
  Pointer
> {
  using tuple::tuple;
  tab14cca2da8a1bf7815d3cb326bdebb2(std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_program> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_program> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tab14cca2da8a1bf7815d3cb326bdebb2 const &a, tab14cca2da8a1bf7815d3cb326bdebb2 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tab14cca2da8a1bf7815d3cb326bdebb2 const &a, tab14cca2da8a1bf7815d3cb326bdebb2 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tab14cca2da8a1bf7815d3cb326bdebb2 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

struct t30765aebeaacaa9c15b78975b43a156d : public std::tuple<
  std::shared_ptr<::dessser::gen::source_info::t> ,
  Pointer
> {
  using tuple::tuple;
  t30765aebeaacaa9c15b78975b43a156d(std::tuple<std::shared_ptr<::dessser::gen::source_info::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::source_info::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t30765aebeaacaa9c15b78975b43a156d const &a, t30765aebeaacaa9c15b78975b43a156d const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t30765aebeaacaa9c15b78975b43a156d const &a, t30765aebeaacaa9c15b78975b43a156d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t30765aebeaacaa9c15b78975b43a156d const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_func> ,Pointer)> compiled_func_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> compiled_program_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> compiled_func_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> compiled_program_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::source_info::tf10028d8c172b81c81f09681b7ea7fa0(Pointer)> compiled_func_of_row_binary;
extern std::function<::dessser::gen::source_info::tab14cca2da8a1bf7815d3cb326bdebb2(Pointer)> compiled_program_of_row_binary;
extern std::function<::dessser::gen::source_info::t30765aebeaacaa9c15b78975b43a156d(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
