#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::func_ref {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::site_name::t site;
  dessser::gen::program_name::t program;
  dessser::gen::function_name::t func;
  bool operator==(t const &other) const {
    return site == other.site && program == other.program && func == other.func;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "site:" << r.site << ',';
  os << "program:" << r.program << ',';
  os << "func:" << r.func;
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
