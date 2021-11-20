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
struct tbb6b5f61a720ca930638180f8a3d0d1a : public std::tuple<
  dessser::gen::field_name::t_ext,
  dessser::gen::raql_value::t_ext
> {
  using tuple::tuple;
  tbb6b5f61a720ca930638180f8a3d0d1a(std::tuple<dessser::gen::field_name::t_ext, dessser::gen::raql_value::t_ext> p)
    : std::tuple<dessser::gen::field_name::t_ext, dessser::gen::raql_value::t_ext>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tbb6b5f61a720ca930638180f8a3d0d1a const &a, tbb6b5f61a720ca930638180f8a3d0d1a const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && ::dessser::gen::raql_value::Deref(std::get<1>(a)) == ::dessser::gen::raql_value::Deref(std::get<1>(b));
}
inline bool operator!=(tbb6b5f61a720ca930638180f8a3d0d1a const &a, tbb6b5f61a720ca930638180f8a3d0d1a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tbb6b5f61a720ca930638180f8a3d0d1a const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

struct tdc75c022089b23d508b703f7fd52f8cc {
  uint32_t parent_num;
  std::string tunneld_host;
  uint16_t tunneld_port;
  tdc75c022089b23d508b703f7fd52f8cc(uint32_t parent_num_, std::string tunneld_host_, uint16_t tunneld_port_) : parent_num(parent_num_), tunneld_host(tunneld_host_), tunneld_port(tunneld_port_) {}
  tdc75c022089b23d508b703f7fd52f8cc() = default;
};
inline std::ostream &operator<<(std::ostream &os, tdc75c022089b23d508b703f7fd52f8cc const &r) {
  os << '{';
  os << "parent_num:" << r.parent_num << ',';
  os << "tunneld_host:" << r.tunneld_host << ',';
  os << "tunneld_port:" << r.tunneld_port;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tdc75c022089b23d508b703f7fd52f8cc> const r) { os << *r; return os; }

inline bool operator==(tdc75c022089b23d508b703f7fd52f8cc const &a, tdc75c022089b23d508b703f7fd52f8cc const &b) {
  return a.parent_num == b.parent_num && a.tunneld_host == b.tunneld_host && a.tunneld_port == b.tunneld_port;
}

inline bool operator!=(tdc75c022089b23d508b703f7fd52f8cc const &a, tdc75c022089b23d508b703f7fd52f8cc const &b) {
  return !operator==(a, b);
}
struct tcea6add784d8acf1d66fabc567856768 : public std::variant<
  Void, // Whole
  Arr<::dessser::gen::worker::tdc75c022089b23d508b703f7fd52f8cc> // TopHalf
> { using variant::variant; };

enum Constr_tcea6add784d8acf1d66fabc567856768 {
  Whole,
  TopHalf,
};

inline std::ostream &operator<<(std::ostream &os, tcea6add784d8acf1d66fabc567856768 const &v) {
  switch (v.index()) {
    case 0: os << "Whole" << std::get<0>(v); break;
    case 1: os << "TopHalf " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tcea6add784d8acf1d66fabc567856768> const v) { os << *v; return os; }

inline bool operator==(tcea6add784d8acf1d66fabc567856768 const &a, tcea6add784d8acf1d66fabc567856768 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Whole
    case 1: return std::get<1>(a) == std::get<1>(b); // TopHalf
  };
  return false;
}
inline bool operator!=(tcea6add784d8acf1d66fabc567856768 const &a, tcea6add784d8acf1d66fabc567856768 const &b) {
  return !operator==(a, b);
}
struct t {
  Arr<dessser::gen::func_ref::t_ext> children;
  dessser::gen::file_path::t_ext cwd;
  bool debug;
  bool enabled;
  Arr<dessser::gen::field_name::t_ext> envvars;
  std::string info_signature;
  bool is_used;
  Arr<::dessser::gen::worker::tbb6b5f61a720ca930638180f8a3d0d1a> params;
  std::optional<Arr<dessser::gen::func_ref::t_ext>> parents;
  double report_period;
  ::dessser::gen::worker::tcea6add784d8acf1d66fabc567856768 role;
  std::string worker_signature;
  t(Arr<dessser::gen::func_ref::t_ext> children_, dessser::gen::file_path::t_ext cwd_, bool debug_, bool enabled_, Arr<dessser::gen::field_name::t_ext> envvars_, std::string info_signature_, bool is_used_, Arr<::dessser::gen::worker::tbb6b5f61a720ca930638180f8a3d0d1a> params_, std::optional<Arr<dessser::gen::func_ref::t_ext>> parents_, double report_period_, ::dessser::gen::worker::tcea6add784d8acf1d66fabc567856768 role_, std::string worker_signature_) : children(children_), cwd(cwd_), debug(debug_), enabled(enabled_), envvars(envvars_), info_signature(info_signature_), is_used(is_used_), params(params_), parents(parents_), report_period(report_period_), role(role_), worker_signature(worker_signature_) {}
  t() = default;
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
  if (r.parents) os << "parents:" << r.parents.value() << ',';
  os << "report_period:" << r.report_period << ',';
  os << "role:" << r.role << ',';
  os << "worker_signature:" << r.worker_signature;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

inline bool operator==(t const &a, t const &b) {
  return a.children == b.children && ::dessser::gen::file_path::Deref(a.cwd) == ::dessser::gen::file_path::Deref(b.cwd) && a.debug == b.debug && a.enabled == b.enabled && a.envvars == b.envvars && a.info_signature == b.info_signature && a.is_used == b.is_used && a.params == b.params && ((a.parents && b.parents && a.parents.value() == b.parents.value()) || (!a.parents && !b.parents)) && a.report_period == b.report_period && a.role == b.role && a.worker_signature == b.worker_signature;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct ta3e796acad3d617428352d1a366552f7 : public std::tuple<
  std::shared_ptr<::dessser::gen::worker::t> ,
  Pointer
> {
  using tuple::tuple;
  ta3e796acad3d617428352d1a366552f7(std::tuple<std::shared_ptr<::dessser::gen::worker::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::worker::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta3e796acad3d617428352d1a366552f7 const &a, ta3e796acad3d617428352d1a366552f7 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta3e796acad3d617428352d1a366552f7 const &a, ta3e796acad3d617428352d1a366552f7 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta3e796acad3d617428352d1a366552f7 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::worker::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::worker::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::worker::ta3e796acad3d617428352d1a366552f7(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
