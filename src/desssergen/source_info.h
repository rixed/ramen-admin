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
inline bool operator==(compiled_func const &a, compiled_func const &b) {
  return a.doc == b.doc && a.factors == b.factors && a.in_signature == b.in_signature && a.is_lazy == b.is_lazy && ::dessser::gen::function_name::Deref(a.name) == ::dessser::gen::function_name::Deref(b.name) && ::dessser::gen::raql_operation::Deref(a.operation) == ::dessser::gen::raql_operation::Deref(b.operation) && ::dessser::gen::raql_type::Deref(a.out_record) == ::dessser::gen::raql_type::Deref(b.out_record) && ((a.retention && b.retention && ::dessser::gen::retention::Deref(a.retention.value()) == ::dessser::gen::retention::Deref(b.retention.value())) || (!a.retention && !b.retention)) && a.signature == b.signature;
}

inline bool operator!=(compiled_func const &a, compiled_func const &b) {
  return !operator==(a, b);
}
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

struct compiled_program {
  dessser::gen::raql_expr::t_ext condition;
  Lst<dessser::gen::program_parameter::t_ext> default_params;
  Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > funcs;
  Lst<dessser::gen::global_variable::t_ext> globals;
  compiled_program(dessser::gen::raql_expr::t_ext condition_, Lst<dessser::gen::program_parameter::t_ext> default_params_, Lst<std::shared_ptr<::dessser::gen::source_info::compiled_func> > funcs_, Lst<dessser::gen::global_variable::t_ext> globals_) : condition(condition_), default_params(default_params_), funcs(funcs_), globals(globals_) {}
  compiled_program() = default;
};
inline bool operator==(compiled_program const &a, compiled_program const &b) {
  return ::dessser::gen::raql_expr::Deref(a.condition) == ::dessser::gen::raql_expr::Deref(b.condition) && a.default_params == b.default_params && a.funcs == b.funcs && a.globals == b.globals;
}

inline bool operator!=(compiled_program const &a, compiled_program const &b) {
  return !operator==(a, b);
}
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

struct t7904aca1b7c7094ac41533a38083131a {
  std::optional<dessser::gen::src_path::t_ext> depends_on;
  std::string err_msg;
  t7904aca1b7c7094ac41533a38083131a(std::optional<dessser::gen::src_path::t_ext> depends_on_, std::string err_msg_) : depends_on(depends_on_), err_msg(err_msg_) {}
  t7904aca1b7c7094ac41533a38083131a() = default;
};
inline bool operator==(t7904aca1b7c7094ac41533a38083131a const &a, t7904aca1b7c7094ac41533a38083131a const &b) {
  return ((a.depends_on && b.depends_on && ::dessser::gen::src_path::Deref(a.depends_on.value()) == ::dessser::gen::src_path::Deref(b.depends_on.value())) || (!a.depends_on && !b.depends_on)) && a.err_msg == b.err_msg;
}

inline bool operator!=(t7904aca1b7c7094ac41533a38083131a const &a, t7904aca1b7c7094ac41533a38083131a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t7904aca1b7c7094ac41533a38083131a const &r) {
  os << '{';
  if (r.depends_on) os << "depends_on:" << r.depends_on.value() << ',';
  os << "err_msg:" << r.err_msg;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7904aca1b7c7094ac41533a38083131a> const r) { os << *r; return os; }

struct t0b3b13a12d06c11bdb06603757bde4bd : public std::variant<
  std::shared_ptr<::dessser::gen::source_info::compiled_program> , // Compiled
  ::dessser::gen::source_info::t7904aca1b7c7094ac41533a38083131a // Failed
> { using variant::variant; };

inline bool operator==(t0b3b13a12d06c11bdb06603757bde4bd const &a, t0b3b13a12d06c11bdb06603757bde4bd const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return (*std::get<0>(a)) == (*std::get<0>(b)); // Compiled
    case 1: return std::get<1>(a) == std::get<1>(b); // Failed
  };
  return false;
}
inline bool operator!=(t0b3b13a12d06c11bdb06603757bde4bd const &a, t0b3b13a12d06c11bdb06603757bde4bd const &b) {
  return !operator==(a, b);
}
enum Constr_t0b3b13a12d06c11bdb06603757bde4bd {
  Compiled,
  Failed,
};

inline std::ostream &operator<<(std::ostream &os, t0b3b13a12d06c11bdb06603757bde4bd const &v) {
  switch (v.index()) {
    case 0: os << "Compiled " << std::get<0>(v); break;
    case 1: os << "Failed " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0b3b13a12d06c11bdb06603757bde4bd> const v) { os << *v; return os; }

struct t {
  ::dessser::gen::source_info::t0b3b13a12d06c11bdb06603757bde4bd detail;
  Lst<std::string> md5s;
  std::string src_ext;
  t(::dessser::gen::source_info::t0b3b13a12d06c11bdb06603757bde4bd detail_, Lst<std::string> md5s_, std::string src_ext_) : detail(detail_), md5s(md5s_), src_ext(src_ext_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.detail == b.detail && a.md5s == b.md5s && a.src_ext == b.src_ext;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "detail:" << r.detail << ',';
  os << "md5s:" << r.md5s << ',';
  os << "src_ext:" << r.src_ext;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t24b44b6db30fb2060e8aaa3137f095be : public std::tuple<
  std::shared_ptr<::dessser::gen::source_info::compiled_func> ,
  Pointer
> {
  using tuple::tuple;
  t24b44b6db30fb2060e8aaa3137f095be(std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_func> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_func> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t24b44b6db30fb2060e8aaa3137f095be const &a, t24b44b6db30fb2060e8aaa3137f095be const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t24b44b6db30fb2060e8aaa3137f095be const &a, t24b44b6db30fb2060e8aaa3137f095be const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t24b44b6db30fb2060e8aaa3137f095be const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t24b44b6db30fb2060e8aaa3137f095be> const t) { os << *t; return os; }

struct t70259d935c5af76ccd7093d0aa01c0a0 : public std::tuple<
  std::shared_ptr<::dessser::gen::source_info::compiled_program> ,
  Pointer
> {
  using tuple::tuple;
  t70259d935c5af76ccd7093d0aa01c0a0(std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_program> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::source_info::compiled_program> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t70259d935c5af76ccd7093d0aa01c0a0 const &a, t70259d935c5af76ccd7093d0aa01c0a0 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t70259d935c5af76ccd7093d0aa01c0a0 const &a, t70259d935c5af76ccd7093d0aa01c0a0 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t70259d935c5af76ccd7093d0aa01c0a0 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t70259d935c5af76ccd7093d0aa01c0a0> const t) { os << *t; return os; }

struct t52b663ff57b1b0023c18934f992f38e8 : public std::tuple<
  std::shared_ptr<::dessser::gen::source_info::t> ,
  Pointer
> {
  using tuple::tuple;
  t52b663ff57b1b0023c18934f992f38e8(std::tuple<std::shared_ptr<::dessser::gen::source_info::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::source_info::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t52b663ff57b1b0023c18934f992f38e8 const &a, t52b663ff57b1b0023c18934f992f38e8 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t52b663ff57b1b0023c18934f992f38e8 const &a, t52b663ff57b1b0023c18934f992f38e8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t52b663ff57b1b0023c18934f992f38e8 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t52b663ff57b1b0023c18934f992f38e8> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_func> ,Pointer)> compiled_func_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::compiled_program> ,Pointer)> compiled_program_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_func> )> compiled_func_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::source_info::compiled_program> )> compiled_program_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::source_info::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::source_info::t24b44b6db30fb2060e8aaa3137f095be(Pointer)> compiled_func_of_row_binary;
extern std::function<::dessser::gen::source_info::t70259d935c5af76ccd7093d0aa01c0a0(Pointer)> compiled_program_of_row_binary;
extern std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> of_row_binary;
extern std::function<::dessser::gen::source_info::t52b663ff57b1b0023c18934f992f38e8(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::source_info::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
