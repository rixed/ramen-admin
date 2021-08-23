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

struct t8fc31e51f4d30b966d0aba41171f4da5 {
  uint32_t parent_num;
  std::string tunneld_host;
  uint16_t tunneld_port;
  bool operator==(t8fc31e51f4d30b966d0aba41171f4da5 const &other) const {
    return parent_num == other.parent_num && tunneld_host == other.tunneld_host && tunneld_port == other.tunneld_port;
  }
};
inline std::ostream &operator<<(std::ostream &os, t8fc31e51f4d30b966d0aba41171f4da5 const &r) {
  os << '{';
  os << "parent_num:" << r.parent_num << ',';
  os << "tunneld_host:" << r.tunneld_host << ',';
  os << "tunneld_port:" << r.tunneld_port;
  os << '}';
  return os;
}

struct t313b9867db010cca466a30c76e768a91 : public std::variant<
  Void,
  Arr<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5>
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t313b9867db010cca466a30c76e768a91 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
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
  ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 role;
  std::string worker_signature;
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
