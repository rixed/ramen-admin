#ifndef DESSSER_GEN_simple_filter
#define DESSSER_GEN_simple_filter
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"

namespace dessser::gen::simple_filter {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_name::t_ext lhs;
  std::string rhs;
  std::string op;
  bool operator==(t const &other) const {
    return lhs == other.lhs && rhs == other.rhs && op == other.op;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "lhs:" << r.lhs << ',';
  os << "rhs:" << r.rhs << ',';
  os << "op:" << r.op;
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
