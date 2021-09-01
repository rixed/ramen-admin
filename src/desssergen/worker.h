#ifndef DESSSER_GEN_worker
#define DESSSER_GEN_worker
#include <arpa/inet.h>
#include <functional>
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
typedef std::tuple<
  dessser::gen::field_name::t_ext,
  dessser::gen::raql_value::t_ext
> t83d220ac6cd554303ec130a90b325374;

struct tad053cdcabe8c3929c89727a9697b82c {
  uint32_t parent_num;
  std::string tunneld_host;
  uint16_t tunneld_port;
  tad053cdcabe8c3929c89727a9697b82c(uint32_t parent_num_, std::string tunneld_host_, uint16_t tunneld_port_) : parent_num(parent_num_), tunneld_host(tunneld_host_), tunneld_port(tunneld_port_) {}
  tad053cdcabe8c3929c89727a9697b82c() = default;
  bool operator==(tad053cdcabe8c3929c89727a9697b82c const &other) const {
    return parent_num == other.parent_num && tunneld_host == other.tunneld_host && tunneld_port == other.tunneld_port;
  }
};
inline std::ostream &operator<<(std::ostream &os, tad053cdcabe8c3929c89727a9697b82c const &r) {
  os << '{';
  os << "parent_num:" << r.parent_num << ',';
  os << "tunneld_host:" << r.tunneld_host << ',';
  os << "tunneld_port:" << r.tunneld_port;
  os << '}';
  return os;
}

struct t7ce4c6a01bfe32de9bc7d5beeb17dd8f : public std::variant<
  Void, // Whole
  Arr<::dessser::gen::worker::tad053cdcabe8c3929c89727a9697b82c> // TopHalf
> { using variant::variant; };

enum Constr_t7ce4c6a01bfe32de9bc7d5beeb17dd8f {
  Whole,
  TopHalf,
};

inline std::ostream &operator<<(std::ostream &os, t7ce4c6a01bfe32de9bc7d5beeb17dd8f const &v) {
  switch (v.index()) {
    case 0: os << "Whole " << std::get<0>(v); break;
    case 1: os << "TopHalf " << std::get<1>(v); break;
  }
  return os;
}

struct t {
  Arr<dessser::gen::func_ref::t_ext> children;
  dessser::gen::file_path::t_ext cwd;
  bool debug;
  bool enabled;
  Arr<dessser::gen::field_name::t_ext> envvars;
  std::string info_signature;
  bool is_used;
  Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> params;
  std::optional<Arr<dessser::gen::func_ref::t_ext>> parents;
  double report_period;
  ::dessser::gen::worker::t7ce4c6a01bfe32de9bc7d5beeb17dd8f role;
  std::string worker_signature;
  t(Arr<dessser::gen::func_ref::t_ext> children_, dessser::gen::file_path::t_ext cwd_, bool debug_, bool enabled_, Arr<dessser::gen::field_name::t_ext> envvars_, std::string info_signature_, bool is_used_, Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> params_, std::optional<Arr<dessser::gen::func_ref::t_ext>> parents_, double report_period_, ::dessser::gen::worker::t7ce4c6a01bfe32de9bc7d5beeb17dd8f role_, std::string worker_signature_) : children(children_), cwd(cwd_), debug(debug_), enabled(enabled_), envvars(envvars_), info_signature(info_signature_), is_used(is_used_), params(params_), parents(parents_), report_period(report_period_), role(role_), worker_signature(worker_signature_) {}
  t() = default;
  bool operator==(t const &other) const {
    return children == other.children && cwd == other.cwd && debug == other.debug && enabled == other.enabled && envvars == other.envvars && info_signature == other.info_signature && is_used == other.is_used && params == other.params && parents == other.parents && report_period == other.report_period && role == other.role && worker_signature == other.worker_signature;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "children:" << r.children << ',';
  os << "cwd:" << r.cwd << ',';
  os << "debug:" << r.debug << ',';
  os << "enabled:" << r.enabled << ',';
  os << "envvars:" << r.envvars << ',';
  os << "info_signature:" << r.info_signature << ',';
  os << "is_used:" << r.is_used << ',';
  os << "params:" << r.params << ',';
  os << "parents:" << r.parents << ',';
  os << "report_period:" << r.report_period << ',';
  os << "role:" << r.role << ',';
  os << "worker_signature:" << r.worker_signature;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::worker::t*,
  Pointer
> t2153f894ec0d3c3ed0ba5ddc0b3fd576;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::worker::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::worker::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
