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
  compiled_func(std::string doc_, Lst<dessser::gen::field_name::t_ext> factors_, std::string in_signature_, bool is_lazy_, dessser::gen::function_name::t_ext name_, dessser::gen::raql_operation::t_ext operation_, dessser::gen::raql_type::t_ext out_record_, std::optional<dessser::gen::retention::t_ext> retention_, std::string signature_) : doc(doc_), factors(factors_), in_signature(in_signature_), is_lazy(is_lazy_), name(name_), operation(operation_), out_record(out_record_), retention(retention_), signature(signature_) {}
  compiled_func() = default;
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
  compiled_program(dessser::gen::raql_expr::t_ext condition_, Lst<dessser::gen::program_parameter::t_ext> default_params_, Lst<::dessser::gen::source_info::compiled_func*> funcs_, Lst<dessser::gen::global_variable::t_ext> globals_) : condition(condition_), default_params(default_params_), funcs(funcs_), globals(globals_) {}
  compiled_program() = default;
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

struct t8100aa66a1cd239db571dfaa7d44577b {
  std::optional<dessser::gen::src_path::t_ext> depends_on;
  std::string err_msg;
  t8100aa66a1cd239db571dfaa7d44577b(std::optional<dessser::gen::src_path::t_ext> depends_on_, std::string err_msg_) : depends_on(depends_on_), err_msg(err_msg_) {}
  t8100aa66a1cd239db571dfaa7d44577b() = default;
  bool operator==(t8100aa66a1cd239db571dfaa7d44577b const &other) const {
    return depends_on == other.depends_on && err_msg == other.err_msg;
  }
};
inline std::ostream &operator<<(std::ostream &os, t8100aa66a1cd239db571dfaa7d44577b const &r) {
  os << '{';
  os << "depends_on:" << r.depends_on << ',';
  os << "err_msg:" << r.err_msg;
  os << '}';
  return os;
}

struct t5f384f7916a2ad2c8006a89d10acc591 : public std::variant<
  ::dessser::gen::source_info::compiled_program*, // Compiled
  ::dessser::gen::source_info::t8100aa66a1cd239db571dfaa7d44577b // Failed
> { using variant::variant; };

enum Constr_t5f384f7916a2ad2c8006a89d10acc591 {
  Compiled,
  Failed,
};

inline std::ostream &operator<<(std::ostream &os, t5f384f7916a2ad2c8006a89d10acc591 const &v) {
  switch (v.index()) {
    case 0: os << "Compiled " << std::get<0>(v); break;
    case 1: os << "Failed " << std::get<1>(v); break;
  }
  return os;
}

struct t {
  ::dessser::gen::source_info::t5f384f7916a2ad2c8006a89d10acc591 detail;
  Lst<std::string> md5s;
  std::string src_ext;
  t(::dessser::gen::source_info::t5f384f7916a2ad2c8006a89d10acc591 detail_, Lst<std::string> md5s_, std::string src_ext_) : detail(detail_), md5s(md5s_), src_ext(src_ext_) {}
  t() = default;
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
