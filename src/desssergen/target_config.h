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
struct t8b7b7f2e45a59c7a5e57aa598aae9cc3 {
  bool automatic;
  dessser::gen::file_path::t_ext cwd;
  bool debug;
  bool enabled;
  std::string on_site;
  Arr<dessser::gen::program_run_parameter::t_ext> params;
  double report_period;
  bool operator==(t8b7b7f2e45a59c7a5e57aa598aae9cc3 const &other) const {
    return automatic == other.automatic && cwd == other.cwd && debug == other.debug && enabled == other.enabled && on_site == other.on_site && params == other.params && report_period == other.report_period;
  }
};
inline std::ostream &operator<<(std::ostream &os, t8b7b7f2e45a59c7a5e57aa598aae9cc3 const &r) {
  os << '{';
  os << "automatic:" << r.automatic << ',';
  os << "cwd:" << r.cwd << ',';
  os << "debug:" << r.debug << ',';
  os << "enabled:" << r.enabled << ',';
  os << "on_site:" << r.on_site << ',';
  os << "params:" << r.params << ',';
  os << "report_period:" << r.report_period;
  os << '}';
  return os;
}

typedef std::tuple<
  dessser::gen::program_name::t_ext,
  ::dessser::gen::target_config::t8b7b7f2e45a59c7a5e57aa598aae9cc3
> t40f989d069ce927274ad1cacebd87ee1;

typedef Arr<::dessser::gen::target_config::t40f989d069ce927274ad1cacebd87ee1> t;
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

}
#endif
