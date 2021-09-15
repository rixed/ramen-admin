#ifndef DESSSER_GEN_rc_entry
#define DESSSER_GEN_rc_entry
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

namespace dessser::gen::rc_entry {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  bool automatic;
  dessser::gen::file_path::t_ext cwd;
  bool debug;
  bool enabled;
  std::string on_site;
  Arr<dessser::gen::program_run_parameter::t_ext> params;
  dessser::gen::program_name::t_ext program;
  double report_period;
  t(bool automatic_, dessser::gen::file_path::t_ext cwd_, bool debug_, bool enabled_, std::string on_site_, Arr<dessser::gen::program_run_parameter::t_ext> params_, dessser::gen::program_name::t_ext program_, double report_period_) : automatic(automatic_), cwd(cwd_), debug(debug_), enabled(enabled_), on_site(on_site_), params(params_), program(program_), report_period(report_period_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "automatic:" << r.automatic << ',';
  os << "cwd:" << ::dessser::gen::file_path::Deref(r.cwd) << ',';
  os << "debug:" << r.debug << ',';
  os << "enabled:" << r.enabled << ',';
  os << "on_site:" << r.on_site << ',';
  os << "params:" << r.params << ',';
  os << "program:" << ::dessser::gen::program_name::Deref(r.program) << ',';
  os << "report_period:" << r.report_period;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.automatic == b.automatic && ::dessser::gen::file_path::Deref(a.cwd) == ::dessser::gen::file_path::Deref(b.cwd) && a.debug == b.debug && a.enabled == b.enabled && a.on_site == b.on_site && a.params == b.params && ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && a.report_period == b.report_period;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t2c17f1ade0bb053f8b40955fc8bc8af6 : public std::tuple<
  ::dessser::gen::rc_entry::t*,
  Pointer
> {
  using tuple::tuple;
  t2c17f1ade0bb053f8b40955fc8bc8af6(std::tuple<::dessser::gen::rc_entry::t*, Pointer> p)
    : std::tuple<::dessser::gen::rc_entry::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2c17f1ade0bb053f8b40955fc8bc8af6 const &a, t2c17f1ade0bb053f8b40955fc8bc8af6 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2c17f1ade0bb053f8b40955fc8bc8af6 const &a, t2c17f1ade0bb053f8b40955fc8bc8af6 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t2c17f1ade0bb053f8b40955fc8bc8af6 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::rc_entry::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::rc_entry::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::rc_entry::t2c17f1ade0bb053f8b40955fc8bc8af6(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
