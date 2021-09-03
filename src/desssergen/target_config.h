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
typedef std::tuple<
  dessser::gen::program_name::t_ext,
  ::dessser::gen::target_config::tde271fc1a19e4cbe02c4f12911834143
> t14d295a17d736d8bb79bbe0ed6c85f41;

typedef Arr<::dessser::gen::target_config::t14d295a17d736d8bb79bbe0ed6c85f41> t;
typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<::dessser::gen::target_config::t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
