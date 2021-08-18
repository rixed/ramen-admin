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
struct t185e415437847a4ccee8fa28534b6c9a {
  dessser::gen::function_name::t_ext name;
  std::optional<dessser::gen::retention::t_ext> retention;
  bool is_lazy;
  std::string doc;
  dessser::gen::raql_operation::t_ext operation;
  dessser::gen::raql_type::t_ext out_record;
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string signature;
  std::string in_signature;
  bool operator==(t185e415437847a4ccee8fa28534b6c9a const &other) const {
    return name == other.name && retention == other.retention && is_lazy == other.is_lazy && doc == other.doc && operation == other.operation && out_record == other.out_record && factors == other.factors && signature == other.signature && in_signature == other.in_signature;
  }
};
inline std::ostream &operator<<(std::ostream &os, t185e415437847a4ccee8fa28534b6c9a const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "retention:" << r.retention << ',';
  os << "is_lazy:" << r.is_lazy << ',';
  os << "doc:" << r.doc << ',';
  os << "operation:" << r.operation << ',';
  os << "out_record:" << r.out_record << ',';
  os << "factors:" << r.factors << ',';
  os << "signature:" << r.signature << ',';
  os << "in_signature:" << r.in_signature;
  os << '}';
  return os;
}

struct tb501b6391922b49ec9aa6664744fde2c {
  Lst<dessser::gen::program_parameter::t_ext> default_params;
  dessser::gen::raql_expr::t_ext condition;
  Lst<dessser::gen::global_variable::t_ext> globals;
  Lst<t185e415437847a4ccee8fa28534b6c9a> funcs;
  bool operator==(tb501b6391922b49ec9aa6664744fde2c const &other) const {
    return default_params == other.default_params && condition == other.condition && globals == other.globals && funcs == other.funcs;
  }
};
inline std::ostream &operator<<(std::ostream &os, tb501b6391922b49ec9aa6664744fde2c const &r) {
  os << '{';
  os << "default_params:" << r.default_params << ',';
  os << "condition:" << r.condition << ',';
  os << "globals:" << r.globals << ',';
  os << "funcs:" << r.funcs;
  os << '}';
  return os;
}

struct t8d05ccd34a6cf5f753650c0c5505a8a0 {
  std::string err_msg;
  std::optional<dessser::gen::src_path::t_ext> depends_on;
  bool operator==(t8d05ccd34a6cf5f753650c0c5505a8a0 const &other) const {
    return err_msg == other.err_msg && depends_on == other.depends_on;
  }
};
inline std::ostream &operator<<(std::ostream &os, t8d05ccd34a6cf5f753650c0c5505a8a0 const &r) {
  os << '{';
  os << "err_msg:" << r.err_msg << ',';
  os << "depends_on:" << r.depends_on;
  os << '}';
  return os;
}

struct tfd2aaf02e0ffa8d9573c7521d96be93a : public std::variant<
  tb501b6391922b49ec9aa6664744fde2c,
  t8d05ccd34a6cf5f753650c0c5505a8a0
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tfd2aaf02e0ffa8d9573c7521d96be93a const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t {
  std::string src_ext;
  Lst<std::string> md5s;
  tfd2aaf02e0ffa8d9573c7521d96be93a detail;
  bool operator==(t const &other) const {
    return src_ext == other.src_ext && md5s == other.md5s && detail == other.detail;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "src_ext:" << r.src_ext << ',';
  os << "md5s:" << r.md5s << ',';
  os << "detail:" << r.detail;
  os << '}';
  return os;
}

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
