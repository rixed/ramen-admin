#ifndef DESSSER_GEN_worker
#define DESSSER_GEN_worker
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/func_ref.h"
#include "desssergen/func_ref.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_value.h"
#include "desssergen/field_name.h"
#include "desssergen/file_path.h"

namespace dessser::gen::worker {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t4827d21c37f0b56d86b99cff40066ee3 : public std::tuple<
  dessser::gen::field_name::t_ext,
  dessser::gen::raql_value::t_ext
> {
  using tuple::tuple;
  t4827d21c37f0b56d86b99cff40066ee3(std::tuple<dessser::gen::field_name::t_ext, dessser::gen::raql_value::t_ext> p)
    : std::tuple<dessser::gen::field_name::t_ext, dessser::gen::raql_value::t_ext>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4827d21c37f0b56d86b99cff40066ee3 const &a, t4827d21c37f0b56d86b99cff40066ee3 const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && ::dessser::gen::raql_value::Deref(std::get<1>(a)) == ::dessser::gen::raql_value::Deref(std::get<1>(b));
}
inline bool operator!=(t4827d21c37f0b56d86b99cff40066ee3 const &a, t4827d21c37f0b56d86b99cff40066ee3 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4827d21c37f0b56d86b99cff40066ee3 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t4827d21c37f0b56d86b99cff40066ee3> const t) { os << *t; return os; }

struct tb1d409993b02f1b7f7cedc87680eed70 {
  std::string tunneld_host;
  uint16_t tunneld_port;
  uint32_t parent_num;
  tb1d409993b02f1b7f7cedc87680eed70(std::string tunneld_host_, uint16_t tunneld_port_, uint32_t parent_num_) : tunneld_host(tunneld_host_), tunneld_port(tunneld_port_), parent_num(parent_num_) {}
  tb1d409993b02f1b7f7cedc87680eed70() = default;
};
inline bool operator==(tb1d409993b02f1b7f7cedc87680eed70 const &a, tb1d409993b02f1b7f7cedc87680eed70 const &b) {
  return a.tunneld_host == b.tunneld_host && a.tunneld_port == b.tunneld_port && a.parent_num == b.parent_num;
}

inline bool operator!=(tb1d409993b02f1b7f7cedc87680eed70 const &a, tb1d409993b02f1b7f7cedc87680eed70 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb1d409993b02f1b7f7cedc87680eed70 const &r) {
  os << '{';
  os << "tunneld_host:" << r.tunneld_host << ',';
  os << "tunneld_port:" << r.tunneld_port << ',';
  os << "parent_num:" << r.parent_num;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tb1d409993b02f1b7f7cedc87680eed70> const r) { os << *r; return os; }

struct t99c4dcc041241b8d5db72250f8968306 : public std::variant<
  Void, // Whole
  Arr<::dessser::gen::worker::tb1d409993b02f1b7f7cedc87680eed70> // TopHalf
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t99c4dcc041241b8d5db72250f8968306 const &a, t99c4dcc041241b8d5db72250f8968306 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Whole
    case 1: return std::get<1>(a) == std::get<1>(b); // TopHalf
  };
  return false;
}
inline bool operator!=(t99c4dcc041241b8d5db72250f8968306 const &a, t99c4dcc041241b8d5db72250f8968306 const &b) {
  return !operator==(a, b);
}
enum Constr_t99c4dcc041241b8d5db72250f8968306 {
  Whole,
  TopHalf,
};

inline std::ostream &operator<<(std::ostream &os, t99c4dcc041241b8d5db72250f8968306 const &v) {
  switch (v.index()) {
    case 0: os << "Whole" << std::get<0>(v); break;
    case 1: os << "TopHalf " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t99c4dcc041241b8d5db72250f8968306> const v) { os << *v; return os; }

struct t {
  bool enabled;
  bool debug;
  double report_period;
  dessser::gen::file_path::t_ext cwd;
  std::string worker_signature;
  std::string info_signature;
  bool is_used;
  Arr<::dessser::gen::worker::t4827d21c37f0b56d86b99cff40066ee3> params;
  Arr<dessser::gen::field_name::t_ext> envvars;
  ::dessser::gen::worker::t99c4dcc041241b8d5db72250f8968306 role;
  std::optional<Arr<dessser::gen::func_ref::t_ext>> parents;
  Arr<dessser::gen::func_ref::t_ext> children;
  t(bool enabled_, bool debug_, double report_period_, dessser::gen::file_path::t_ext cwd_, std::string worker_signature_, std::string info_signature_, bool is_used_, Arr<::dessser::gen::worker::t4827d21c37f0b56d86b99cff40066ee3> params_, Arr<dessser::gen::field_name::t_ext> envvars_, ::dessser::gen::worker::t99c4dcc041241b8d5db72250f8968306 role_, std::optional<Arr<dessser::gen::func_ref::t_ext>> parents_, Arr<dessser::gen::func_ref::t_ext> children_) : enabled(enabled_), debug(debug_), report_period(report_period_), cwd(cwd_), worker_signature(worker_signature_), info_signature(info_signature_), is_used(is_used_), params(params_), envvars(envvars_), role(role_), parents(parents_), children(children_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.enabled == b.enabled && a.debug == b.debug && a.report_period == b.report_period && ::dessser::gen::file_path::Deref(a.cwd) == ::dessser::gen::file_path::Deref(b.cwd) && a.worker_signature == b.worker_signature && a.info_signature == b.info_signature && a.is_used == b.is_used && a.params == b.params && a.envvars == b.envvars && a.role == b.role && ((a.parents && b.parents && a.parents.value() == b.parents.value()) || (!a.parents && !b.parents)) && a.children == b.children;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "enabled:" << r.enabled << ',';
  os << "debug:" << r.debug << ',';
  os << "report_period:" << r.report_period << ',';
  os << "cwd:" << r.cwd << ',';
  os << "worker_signature:" << r.worker_signature << ',';
  os << "info_signature:" << r.info_signature << ',';
  os << "is_used:" << r.is_used << ',';
  os << "params:" << r.params << ',';
  os << "envvars:" << r.envvars << ',';
  os << "role:" << r.role << ',';
  if (r.parents) os << "parents:" << r.parents.value() << ',';
  os << "children:" << r.children;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tfd8469c1f315c828082a129ae15367ca : public std::tuple<
  std::shared_ptr<::dessser::gen::worker::t> ,
  Pointer
> {
  using tuple::tuple;
  tfd8469c1f315c828082a129ae15367ca(std::tuple<std::shared_ptr<::dessser::gen::worker::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::worker::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tfd8469c1f315c828082a129ae15367ca const &a, tfd8469c1f315c828082a129ae15367ca const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tfd8469c1f315c828082a129ae15367ca const &a, tfd8469c1f315c828082a129ae15367ca const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tfd8469c1f315c828082a129ae15367ca const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tfd8469c1f315c828082a129ae15367ca> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::worker::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::worker::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::worker::tfd8469c1f315c828082a129ae15367ca(Pointer)> of_row_binary;
extern std::function<::dessser::gen::worker::tfd8469c1f315c828082a129ae15367ca(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::worker::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
