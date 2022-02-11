#ifndef DESSSER_GEN_source_info
#define DESSSER_GEN_source_info
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/src_path.h"
#include "desssergen/raql_error.h"
#include "desssergen/raql_warning.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_operation.h"
#include "desssergen/raql_expr.h"
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
  dessser::gen::function_name::t_ext name;
  std::optional<dessser::gen::retention::t_ext> retention;
  bool is_lazy;
  std::optional<dessser::gen::raql_expr::t_ext> best_after;
  std::string doc;
  dessser::gen::raql_operation::t_ext operation;
  dessser::gen::raql_type::t_ext out_record;
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string signature;
  std::string in_signature;
  compiled_func(dessser::gen::function_name::t_ext name_, std::optional<dessser::gen::retention::t_ext> retention_, bool is_lazy_, std::optional<dessser::gen::raql_expr::t_ext> best_after_, std::string doc_, dessser::gen::raql_operation::t_ext operation_, dessser::gen::raql_type::t_ext out_record_, Lst<dessser::gen::field_name::t_ext> factors_, std::string signature_, std::string in_signature_) : name(name_), retention(retention_), is_lazy(is_lazy_), best_after(best_after_), doc(doc_), operation(operation_), out_record(out_record_), factors(factors_), signature(signature_), in_signature(in_signature_) {}
  compiled_func() = default;
};
inline bool operator==(compiled_func const &a, compiled_func const &b) {
  return ::dessser::gen::function_name::Deref(a.name) == ::dessser::gen::function_name::Deref(b.name) && ((a.retention && b.retention && ::dessser::gen::retention::Deref(a.retention.value()) == ::dessser::gen::retention::Deref(b.retention.value())) || (!a.retention && !b.retention)) && a.is_lazy == b.is_lazy && ((a.best_after && b.best_after && ::dessser::gen::raql_expr::Deref(a.best_after.value()) == ::dessser::gen::raql_expr::Deref(b.best_after.value())) || (!a.best_after && !b.best_after)) && a.doc == b.doc && ::dessser::gen::raql_operation::Deref(a.operation) == ::dessser::gen::raql_operation::Deref(b.operation) && ::dessser::gen::raql_type::Deref(a.out_record) == ::dessser::gen::raql_type::Deref(b.out_record) && a.factors == b.factors && a.signature == b.signature && a.in_signature == b.in_signature;
}

inline bool operator!=(compiled_func const &a, compiled_func const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, compiled_func const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  if (r.retention) os << "retention:" << r.retention.value() << ',';
  os << "is_lazy:" << r.is_lazy << ',';
  if (r.best_after) os << "best_after:" << r.best_after.value() << ',';
  os << "doc:" << r.doc << ',';
  os << "operation:" << r.operation << ',';
  os << "out_record:" << r.out_record << ',';
  os << "factors:" << r.factors << ',';
  os << "signature:" << r.signature << ',';
  os << "in_signature:" << r.in_signature;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<compiled_func> const r) { os << *r; return os; }

struct compiled_program {
  Lst<dessser::gen::program_parameter::t_ext> default_params;
  dessser::gen::raql_expr::t_ext condition;
  Lst<dessser::gen::global_variable::t_ext> globals;
  Lst<::dessser::gen::source_info::compiled_func> funcs;
  Lst<dessser::gen::raql_warning::t_ext> warnings;
  compiled_program(Lst<dessser::gen::program_parameter::t_ext> default_params_, dessser::gen::raql_expr::t_ext condition_, Lst<dessser::gen::global_variable::t_ext> globals_, Lst<::dessser::gen::source_info::compiled_func> funcs_, Lst<dessser::gen::raql_warning::t_ext> warnings_) : default_params(default_params_), condition(condition_), globals(globals_), funcs(funcs_), warnings(warnings_) {}
  compiled_program() = default;
};
inline bool operator==(compiled_program const &a, compiled_program const &b) {
  return a.default_params == b.default_params && ::dessser::gen::raql_expr::Deref(a.condition) == ::dessser::gen::raql_expr::Deref(b.condition) && a.globals == b.globals && a.funcs == b.funcs && a.warnings == b.warnings;
}

inline bool operator!=(compiled_program const &a, compiled_program const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, compiled_program const &r) {
  os << '{';
  os << "default_params:" << r.default_params << ',';
  os << "condition:" << r.condition << ',';
  os << "globals:" << r.globals << ',';
  os << "funcs:" << r.funcs << ',';
  os << "warnings:" << r.warnings;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<compiled_program> const r) { os << *r; return os; }

struct td7297575b32536089f1cb63910c9de8b {
  Lst<dessser::gen::raql_error::t_ext> errors;
  std::optional<dessser::gen::src_path::t_ext> depends_on;
  td7297575b32536089f1cb63910c9de8b(Lst<dessser::gen::raql_error::t_ext> errors_, std::optional<dessser::gen::src_path::t_ext> depends_on_) : errors(errors_), depends_on(depends_on_) {}
  td7297575b32536089f1cb63910c9de8b() = default;
};
inline bool operator==(td7297575b32536089f1cb63910c9de8b const &a, td7297575b32536089f1cb63910c9de8b const &b) {
  return a.errors == b.errors && ((a.depends_on && b.depends_on && ::dessser::gen::src_path::Deref(a.depends_on.value()) == ::dessser::gen::src_path::Deref(b.depends_on.value())) || (!a.depends_on && !b.depends_on));
}

inline bool operator!=(td7297575b32536089f1cb63910c9de8b const &a, td7297575b32536089f1cb63910c9de8b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td7297575b32536089f1cb63910c9de8b const &r) {
  os << '{';
  os << "errors:" << r.errors << ',';
  if (r.depends_on) os << "depends_on:" << r.depends_on.value();
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td7297575b32536089f1cb63910c9de8b> const r) { os << *r; return os; }

struct t965ad09994cd344dce4a328027a4989a : public std::variant<
  ::dessser::gen::source_info::compiled_program, // Compiled
  ::dessser::gen::source_info::td7297575b32536089f1cb63910c9de8b // Failed
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t965ad09994cd344dce4a328027a4989a const &a, t965ad09994cd344dce4a328027a4989a const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Compiled
    case 1: return std::get<1>(a) == std::get<1>(b); // Failed
  };
  return false;
}
inline bool operator!=(t965ad09994cd344dce4a328027a4989a const &a, t965ad09994cd344dce4a328027a4989a const &b) {
  return !operator==(a, b);
}
enum Constr_t965ad09994cd344dce4a328027a4989a {
  Compiled,
  Failed,
};

inline std::ostream &operator<<(std::ostream &os, t965ad09994cd344dce4a328027a4989a const &v) {
  switch (v.index()) {
    case 0: os << "Compiled " << std::get<0>(v); break;
    case 1: os << "Failed " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t965ad09994cd344dce4a328027a4989a> const v) { os << *v; return os; }

struct t {
  std::string src_ext;
  Lst<std::string> md5s;
  ::dessser::gen::source_info::t965ad09994cd344dce4a328027a4989a detail;
  t(std::string src_ext_, Lst<std::string> md5s_, ::dessser::gen::source_info::t965ad09994cd344dce4a328027a4989a detail_) : src_ext(src_ext_), md5s(md5s_), detail(detail_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.src_ext == b.src_ext && a.md5s == b.md5s && a.detail == b.detail;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "src_ext:" << r.src_ext << ',';
  os << "md5s:" << r.md5s << ',';
  os << "detail:" << r.detail;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t623141d6f602c3ac0c16e49e2c924c59 : public std::tuple<
  ::dessser::gen::source_info::compiled_func,
  Pointer
> {
  using tuple::tuple;
  t623141d6f602c3ac0c16e49e2c924c59(std::tuple<::dessser::gen::source_info::compiled_func, Pointer> p)
    : std::tuple<::dessser::gen::source_info::compiled_func, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t623141d6f602c3ac0c16e49e2c924c59 const &a, t623141d6f602c3ac0c16e49e2c924c59 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t623141d6f602c3ac0c16e49e2c924c59 const &a, t623141d6f602c3ac0c16e49e2c924c59 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t623141d6f602c3ac0c16e49e2c924c59 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t623141d6f602c3ac0c16e49e2c924c59> const t) { os << *t; return os; }

struct t12d6a7c9f7c5d6dd77890845a885e9c9 : public std::tuple<
  ::dessser::gen::source_info::compiled_program,
  Pointer
> {
  using tuple::tuple;
  t12d6a7c9f7c5d6dd77890845a885e9c9(std::tuple<::dessser::gen::source_info::compiled_program, Pointer> p)
    : std::tuple<::dessser::gen::source_info::compiled_program, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12d6a7c9f7c5d6dd77890845a885e9c9 const &a, t12d6a7c9f7c5d6dd77890845a885e9c9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12d6a7c9f7c5d6dd77890845a885e9c9 const &a, t12d6a7c9f7c5d6dd77890845a885e9c9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t12d6a7c9f7c5d6dd77890845a885e9c9 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t12d6a7c9f7c5d6dd77890845a885e9c9> const t) { os << *t; return os; }

struct t2d6b9a42d53c9f874a3fc26e34d09345 : public std::tuple<
  ::dessser::gen::source_info::t,
  Pointer
> {
  using tuple::tuple;
  t2d6b9a42d53c9f874a3fc26e34d09345(std::tuple<::dessser::gen::source_info::t, Pointer> p)
    : std::tuple<::dessser::gen::source_info::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2d6b9a42d53c9f874a3fc26e34d09345 const &a, t2d6b9a42d53c9f874a3fc26e34d09345 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2d6b9a42d53c9f874a3fc26e34d09345 const &a, t2d6b9a42d53c9f874a3fc26e34d09345 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t2d6b9a42d53c9f874a3fc26e34d09345 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2d6b9a42d53c9f874a3fc26e34d09345> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::source_info::compiled_func &,Pointer &)> compiled_func_to_row_binary;
extern std::function<Pointer(::dessser::gen::source_info::compiled_program &,Pointer &)> compiled_program_to_row_binary;
extern std::function<Pointer(::dessser::gen::source_info::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::source_info::compiled_func &)> compiled_func_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::source_info::compiled_program &)> compiled_program_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::source_info::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::source_info::t623141d6f602c3ac0c16e49e2c924c59(Pointer &)> compiled_func_of_row_binary;
extern std::function<::dessser::gen::source_info::t12d6a7c9f7c5d6dd77890845a885e9c9(Pointer &)> compiled_program_of_row_binary;
extern std::function<::dessser::gen::source_info::t2d6b9a42d53c9f874a3fc26e34d09345(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::source_info::t2d6b9a42d53c9f874a3fc26e34d09345(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::source_info::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
