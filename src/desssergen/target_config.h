#ifndef DESSSER_GEN_target_config
#define DESSSER_GEN_target_config
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/program_run_parameter.h"
#include "desssergen/file_path.h"
#include "desssergen/program_name.h"

namespace dessser::gen::target_config {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tde271fc1a19e4cbe02c4f12911834143 {
  bool automatic;
  dessser::gen::file_path::t_ext cwd;
  bool debug;
  bool enabled;
  std::string on_site;
  Arr<dessser::gen::program_run_parameter::t_ext> params;
  double report_period;
  tde271fc1a19e4cbe02c4f12911834143(bool automatic_, dessser::gen::file_path::t_ext cwd_, bool debug_, bool enabled_, std::string on_site_, Arr<dessser::gen::program_run_parameter::t_ext> params_, double report_period_) : automatic(automatic_), cwd(cwd_), debug(debug_), enabled(enabled_), on_site(on_site_), params(params_), report_period(report_period_) {}
  tde271fc1a19e4cbe02c4f12911834143() = default;
};
inline std::ostream &operator<<(std::ostream &os, tde271fc1a19e4cbe02c4f12911834143 const &r) {
  os << '{';
  os << "automatic:" << r.automatic << ',';
  os << "cwd:" << ::dessser::gen::file_path::Deref(r.cwd) << ',';
  os << "debug:" << r.debug << ',';
  os << "enabled:" << r.enabled << ',';
  os << "on_site:" << r.on_site << ',';
  os << "params:" << r.params << ',';
  os << "report_period:" << r.report_period;
  os << '}';
  return os;
}
inline bool operator==(tde271fc1a19e4cbe02c4f12911834143 const &a, tde271fc1a19e4cbe02c4f12911834143 const &b) {
  return a.automatic == b.automatic && ::dessser::gen::file_path::Deref(a.cwd) == ::dessser::gen::file_path::Deref(b.cwd) && a.debug == b.debug && a.enabled == b.enabled && a.on_site == b.on_site && a.params == b.params && a.report_period == b.report_period;
}

inline bool operator!=(tde271fc1a19e4cbe02c4f12911834143 const &a, tde271fc1a19e4cbe02c4f12911834143 const &b) {
  return !operator==(a, b);
}
struct td07c419fcbb1d7c2123fd1ae7e7e5dd0 : public std::tuple<
  dessser::gen::program_name::t_ext,
  ::dessser::gen::target_config::tde271fc1a19e4cbe02c4f12911834143
> {
  using tuple::tuple;
  td07c419fcbb1d7c2123fd1ae7e7e5dd0(std::tuple<dessser::gen::program_name::t_ext, ::dessser::gen::target_config::tde271fc1a19e4cbe02c4f12911834143> p)
    : std::tuple<dessser::gen::program_name::t_ext, ::dessser::gen::target_config::tde271fc1a19e4cbe02c4f12911834143>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td07c419fcbb1d7c2123fd1ae7e7e5dd0 const &a, td07c419fcbb1d7c2123fd1ae7e7e5dd0 const &b) {
  return ::dessser::gen::program_name::Deref(std::get<0>(a)) == ::dessser::gen::program_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td07c419fcbb1d7c2123fd1ae7e7e5dd0 const &a, td07c419fcbb1d7c2123fd1ae7e7e5dd0 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td07c419fcbb1d7c2123fd1ae7e7e5dd0 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

typedef Arr<::dessser::gen::target_config::td07c419fcbb1d7c2123fd1ae7e7e5dd0> t;
struct tf6138ae5919ddcb1cb9a935a9dc7190a : public std::tuple<
  t,
  Pointer
> {
  using tuple::tuple;
  tf6138ae5919ddcb1cb9a935a9dc7190a(std::tuple<t, Pointer> p)
    : std::tuple<t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf6138ae5919ddcb1cb9a935a9dc7190a const &a, tf6138ae5919ddcb1cb9a935a9dc7190a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf6138ae5919ddcb1cb9a935a9dc7190a const &a, tf6138ae5919ddcb1cb9a935a9dc7190a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf6138ae5919ddcb1cb9a935a9dc7190a const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<::dessser::gen::target_config::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
