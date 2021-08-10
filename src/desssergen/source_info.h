#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::source_info {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct v_3688294421a0ac74c89eed28ac0b000d {
  dessser::gen::function_name::t name;
  std::optional<dessser::gen::retention::t> retention;
  bool is_lazy;
  std::string doc;
  dessser::gen::raql_operation::t operation;
  dessser::gen::raql_type::t out_record;
  Lst<dessser::gen::field_name::t> factors;
  std::string signature;
  std::string in_signature;
  bool operator==(v_3688294421a0ac74c89eed28ac0b000d const &other) const {
    return name == other.name && retention == other.retention && is_lazy == other.is_lazy && doc == other.doc && operation == other.operation && out_record == other.out_record && factors == other.factors && signature == other.signature && in_signature == other.in_signature;
  }
};
std::ostream &operator<<(std::ostream &os, v_3688294421a0ac74c89eed28ac0b000d const &r) {
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

struct a9adb622935fb3e63633e15c6e6f64d4 {
  Lst<dessser::gen::program_parameter::t> default_params;
  dessser::gen::raql_expr::t condition;
  Lst<dessser::gen::global_variable::t> globals;
  Lst<v_3688294421a0ac74c89eed28ac0b000d> funcs;
  bool operator==(a9adb622935fb3e63633e15c6e6f64d4 const &other) const {
    return default_params == other.default_params && condition == other.condition && globals == other.globals && funcs == other.funcs;
  }
};
std::ostream &operator<<(std::ostream &os, a9adb622935fb3e63633e15c6e6f64d4 const &r) {
  os << '{';
  os << "default_params:" << r.default_params << ',';
  os << "condition:" << r.condition << ',';
  os << "globals:" << r.globals << ',';
  os << "funcs:" << r.funcs;
  os << '}';
  return os;
}

struct v_31d6b3b8d8b6f074fb3bcffbc5b1aa90 {
  std::string err_msg;
  std::optional<dessser::gen::src_path::t> depends_on;
  bool operator==(v_31d6b3b8d8b6f074fb3bcffbc5b1aa90 const &other) const {
    return err_msg == other.err_msg && depends_on == other.depends_on;
  }
};
std::ostream &operator<<(std::ostream &os, v_31d6b3b8d8b6f074fb3bcffbc5b1aa90 const &r) {
  os << '{';
  os << "err_msg:" << r.err_msg << ',';
  os << "depends_on:" << r.depends_on;
  os << '}';
  return os;
}

struct v_1d526b39e597fcea4e0328d0a7f6426a : public std::variant<
  a9adb622935fb3e63633e15c6e6f64d4,
  v_31d6b3b8d8b6f074fb3bcffbc5b1aa90
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_1d526b39e597fcea4e0328d0a7f6426a const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t {
  std::string src_ext;
  Lst<std::string> md5s;
  v_1d526b39e597fcea4e0328d0a7f6426a detail;
  bool operator==(t const &other) const {
    return src_ext == other.src_ext && md5s == other.md5s && detail == other.detail;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "src_ext:" << r.src_ext << ',';
  os << "md5s:" << r.md5s << ',';
  os << "detail:" << r.detail;
  os << '}';
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
