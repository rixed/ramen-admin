#ifndef DESSSER_GEN_fq_function_name
#define DESSSER_GEN_fq_function_name
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

namespace dessser::gen::fq_function_name {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::function_name::t_ext function;
  dessser::gen::program_name::t_ext program;
  dessser::gen::site_name::t_ext site;
  t(dessser::gen::function_name::t_ext function_, dessser::gen::program_name::t_ext program_, dessser::gen::site_name::t_ext site_) : function(function_), program(program_), site(site_) {}
  t() = default;
  bool operator==(t const &other) const {
    return function == other.function && program == other.program && site == other.site;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "function:" << r.function << ',';
  os << "program:" << r.program << ',';
  os << "site:" << r.site;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::fq_function_name::t*,
  Pointer
> t024adea80a7aaa8777363d4a16b0f33f;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::fq_function_name::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::fq_function_name::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::fq_function_name::t024adea80a7aaa8777363d4a16b0f33f(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
