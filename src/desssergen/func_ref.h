#ifndef DESSSER_GEN_func_ref
#define DESSSER_GEN_func_ref
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/function_name.h"
#include "desssergen/program_name.h"
#include "desssergen/site_name.h"

namespace dessser::gen::func_ref {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::site_name::t_ext site;
  dessser::gen::program_name::t_ext program;
  dessser::gen::function_name::t_ext func;
  bool operator==(t const &other) const {
    return site == other.site && program == other.program && func == other.func;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "site:" << r.site << ',';
  os << "program:" << r.program << ',';
  os << "func:" << r.func;
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
