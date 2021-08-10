#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  *field_name,
  *raql_value
> v_7a08095eeded42b6cde638d4d53dd964;

struct f4f9cb35168f81f8ec0d29afee065aaa {
  std::string tunneld_host;
  uint16_t tunneld_port;
  uint32_t parent_num;
  bool operator==(f4f9cb35168f81f8ec0d29afee065aaa const &other) const {
    return tunneld_host == other.tunneld_host && tunneld_port == other.tunneld_port && parent_num == other.parent_num;
  }
};
std::ostream &operator<<(std::ostream &os, f4f9cb35168f81f8ec0d29afee065aaa const &r) {
  os << '{';
  os << "tunneld_host:" << r.tunneld_host << ',';
  os << "tunneld_port:" << r.tunneld_port << ',';
  os << "parent_num:" << r.parent_num;
  os << '}';
  return os;
}

struct e1503df6dd01643870ca1bf95113afdf : public std::variant<
  Void,
  Arr<f4f9cb35168f81f8ec0d29afee065aaa>
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, e1503df6dd01643870ca1bf95113afdf const &v) {
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
  *file_path cwd;
  std::string worker_signature;
  std::string info_signature;
  bool is_used;
  Arr<v_7a08095eeded42b6cde638d4d53dd964> params;
  Arr<*field_name> envvars;
  e1503df6dd01643870ca1bf95113afdf role;
  std::optional<Arr<*func_ref>> parents;
  Arr<*func_ref> children;
  bool operator==(t const &other) const {
    return enabled == other.enabled && debug == other.debug && report_period == other.report_period && cwd == other.cwd && worker_signature == other.worker_signature && info_signature == other.info_signature && is_used == other.is_used && params == other.params && envvars == other.envvars && role == other.role && parents == other.parents && children == other.children;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
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
