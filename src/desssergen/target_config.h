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
struct t895c8468bdc5b9f7e7bbe8a73ee2087a {
  bool enabled;
  bool debug;
  double report_period;
  dessser::gen::file_path::t_ext cwd;
  Arr<dessser::gen::program_run_parameter::t_ext> params;
  std::string on_site;
  bool automatic;
  bool operator==(t895c8468bdc5b9f7e7bbe8a73ee2087a const &other) const {
    return enabled == other.enabled && debug == other.debug && report_period == other.report_period && cwd == other.cwd && params == other.params && on_site == other.on_site && automatic == other.automatic;
  }
};
inline std::ostream &operator<<(std::ostream &os, t895c8468bdc5b9f7e7bbe8a73ee2087a const &r) {
  os << '{';
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

typedef std::tuple<
  dessser::gen::program_name::t_ext,
  t895c8468bdc5b9f7e7bbe8a73ee2087a
> tcd0434c9b855cccef1496d4439f6fcb1;

typedef Arr<tcd0434c9b855cccef1496d4439f6fcb1> t;
typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t&,Pointer)> to_row_binary;
extern std::function<Size(t&)> sersize_of_row_binary;
extern std::function<t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary;
typedef t t_ext;

}
#endif
