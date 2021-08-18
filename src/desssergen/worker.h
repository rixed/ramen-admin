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

struct t57bafbdb4cb972c46a36425455535e06 {
  std::string tunneld_host;
  uint16_t tunneld_port;
  uint32_t parent_num;
  bool operator==(t57bafbdb4cb972c46a36425455535e06 const &other) const {
    return tunneld_host == other.tunneld_host && tunneld_port == other.tunneld_port && parent_num == other.parent_num;
  }
};
inline std::ostream &operator<<(std::ostream &os, t57bafbdb4cb972c46a36425455535e06 const &r) {
  os << '{';
  os << "tunneld_host:" << r.tunneld_host << ',';
  os << "tunneld_port:" << r.tunneld_port << ',';
  os << "parent_num:" << r.parent_num;
  os << '}';
  return os;
}

struct t8e7941b7e3893616560afdc4ab6263e6 : public std::variant<
  Void,
  Arr<t57bafbdb4cb972c46a36425455535e06>
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t8e7941b7e3893616560afdc4ab6263e6 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t {
  bool enabled;
  bool debug;
  double report_period;
  dessser::gen::file_path::t_ext cwd;
  std::string worker_signature;
  std::string info_signature;
  bool is_used;
  Arr<t83d220ac6cd554303ec130a90b325374> params;
  Arr<dessser::gen::field_name::t_ext> envvars;
  t8e7941b7e3893616560afdc4ab6263e6 role;
  std::optional<Arr<dessser::gen::func_ref::t_ext>> parents;
  Arr<dessser::gen::func_ref::t_ext> children;
  bool operator==(t const &other) const {
    return enabled == other.enabled && debug == other.debug && report_period == other.report_period && cwd == other.cwd && worker_signature == other.worker_signature && info_signature == other.info_signature && is_used == other.is_used && params == other.params && envvars == other.envvars && role == other.role && parents == other.parents && children == other.children;
  }
};
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
  os << "parents:" << r.parents << ',';
  os << "children:" << r.children;
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
