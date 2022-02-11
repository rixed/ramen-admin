#ifndef DESSSER_GEN_rc_entry
#define DESSSER_GEN_rc_entry
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/program_run_parameter.h"
#include "desssergen/file_path.h"
#include "desssergen/program_name.h"

namespace dessser::gen::rc_entry {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::program_name::t_ext program;
  bool enabled;
  bool debug;
  double report_period;
  dessser::gen::file_path::t_ext cwd;
  Arr<dessser::gen::program_run_parameter::t_ext> params;
  std::string on_site;
  bool automatic;
  t(dessser::gen::program_name::t_ext program_, bool enabled_, bool debug_, double report_period_, dessser::gen::file_path::t_ext cwd_, Arr<dessser::gen::program_run_parameter::t_ext> params_, std::string on_site_, bool automatic_) : program(program_), enabled(enabled_), debug(debug_), report_period(report_period_), cwd(cwd_), params(params_), on_site(on_site_), automatic(automatic_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && a.enabled == b.enabled && a.debug == b.debug && a.report_period == b.report_period && ::dessser::gen::file_path::Deref(a.cwd) == ::dessser::gen::file_path::Deref(b.cwd) && a.params == b.params && a.on_site == b.on_site && a.automatic == b.automatic;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "program:" << r.program << ',';
  os << "enabled:" << r.enabled << ',';
  os << "debug:" << r.debug << ',';
  os << "report_period:" << r.report_period << ',';
  os << "cwd:" << r.cwd << ',';
  os << "params:" << r.params << ',';
  os << "on_site:" << r.on_site << ',';
  os << "automatic:" << r.automatic;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t08bba98e8f6b1246defca69d6f19d107 : public std::tuple<
  ::dessser::gen::rc_entry::t,
  Pointer
> {
  using tuple::tuple;
  t08bba98e8f6b1246defca69d6f19d107(std::tuple<::dessser::gen::rc_entry::t, Pointer> p)
    : std::tuple<::dessser::gen::rc_entry::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t08bba98e8f6b1246defca69d6f19d107 const &a, t08bba98e8f6b1246defca69d6f19d107 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t08bba98e8f6b1246defca69d6f19d107 const &a, t08bba98e8f6b1246defca69d6f19d107 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t08bba98e8f6b1246defca69d6f19d107 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t08bba98e8f6b1246defca69d6f19d107> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::rc_entry::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::rc_entry::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::rc_entry::t08bba98e8f6b1246defca69d6f19d107(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::rc_entry::t08bba98e8f6b1246defca69d6f19d107(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::rc_entry::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
