#ifndef DESSSER_GEN_raql_select_field
#define DESSSER_GEN_raql_select_field
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_expr.h"

namespace dessser::gen::raql_select_field {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::raql_expr::t_ext expr;
  dessser::gen::field_name::t_ext alias;
  std::string doc;
  std::optional<std::string> aggr;
  bool operator==(t const &other) const {
    return expr == other.expr && alias == other.alias && doc == other.doc && aggr == other.aggr;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "expr:" << r.expr << ',';
  os << "alias:" << r.alias << ',';
  os << "doc:" << r.doc << ',';
  os << "aggr:" << r.aggr;
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
