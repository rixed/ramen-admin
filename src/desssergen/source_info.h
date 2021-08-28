#ifndef DESSSER_GEN_source_info
#define DESSSER_GEN_source_info
#include <arpa/inet.h>
#include <functional>
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
  bool operator==(compiled_func const &other) const {
    return doc == other.doc && factors == other.factors && in_signature == other.in_signature && is_lazy == other.is_lazy && name == other.name && operation == other.operation && out_record == other.out_record && retention == other.retention && signature == other.signature;
  }
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
  os << "retention:" << r.retention << ',';
  os << "signature:" << r.signature;
  os << '}';
  return os;
}

struct compiled_program {
  dessser::gen::raql_expr::t_ext condition;
  Lst<dessser::gen::program_parameter::t_ext> default_params;
  Lst<::dessser::gen::source_info::compiled_func*> funcs;
  Lst<dessser::gen::global_variable::t_ext> globals;
  bool operator==(compiled_program const &other) const {
    return condition == other.condition && default_params == other.default_params && funcs == other.funcs && globals == other.globals;
  }
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

struct tcf61baf1ca251368717dff4345cd4bfb {
  std::optional<dessser::gen::src_path::t_ext> depends_on;
  std::string err_msg;
  bool operator==(tcf61baf1ca251368717dff4345cd4bfb const &other) const {
    return depends_on == other.depends_on && err_msg == other.err_msg;
  }
};
inline std::ostream &operator<<(std::ostream &os, tcf61baf1ca251368717dff4345cd4bfb const &r) {
  os << '{';
  os << "depends_on:" << r.depends_on << ',';
  os << "err_msg:" << r.err_msg;
  os << '}';
  return os;
}

struct t6ac3210567b19e88b41ebcefc5642eee : public std::variant<
  ::dessser::gen::source_info::compiled_program*, // Compiled
  ::dessser::gen::source_info::tcf61baf1ca251368717dff4345cd4bfb // Failed
> { using variant::variant; };

enum Constr_t6ac3210567b19e88b41ebcefc5642eee {
  Compiled,
  Failed,
};

inline std::ostream &operator<<(std::ostream &os, t6ac3210567b19e88b41ebcefc5642eee const &v) {
  switch (v.index()) {
    case 0: os << "Compiled " << std::get<0>(v); break;
    case 1: os << "Failed " << std::get<1>(v); break;
  }
  return os;
}

struct t {
  ::dessser::gen::source_info::t6ac3210567b19e88b41ebcefc5642eee detail;
  Lst<std::string> md5s;
  std::string src_ext;
  bool operator==(t const &other) const {
    return detail == other.detail && md5s == other.md5s && src_ext == other.src_ext;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "detail:" << r.detail << ',';
  os << "md5s:" << r.md5s << ',';
  os << "src_ext:" << r.src_ext;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::source_info::compiled_func*,
  Pointer
> t9e45dc1ac0fec909dcc286f5d2162cb9;

typedef std::tuple<
  ::dessser::gen::source_info::compiled_program*,
  Pointer
> t5cd1bbfb4f9f8bb51dadea9dbddee4df;

typedef std::tuple<
  ::dessser::gen::source_info::t*,
  Pointer
> ta38848586446dac711443ba2fdd1244d;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::source_info::compiled_func*,Pointer)> compiled_func_to_row_binary;
extern std::function<Pointer(::dessser::gen::source_info::compiled_program*,Pointer)> compiled_program_to_row_binary;
extern std::function<Pointer(::dessser::gen::source_info::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::source_info::compiled_func*)> compiled_func_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::source_info::compiled_program*)> compiled_program_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::source_info::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::source_info::t9e45dc1ac0fec909dcc286f5d2162cb9(Pointer)> compiled_func_of_row_binary;
extern std::function<::dessser::gen::source_info::t5cd1bbfb4f9f8bb51dadea9dbddee4df(Pointer)> compiled_program_of_row_binary;
extern std::function<::dessser::gen::source_info::ta38848586446dac711443ba2fdd1244d(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
