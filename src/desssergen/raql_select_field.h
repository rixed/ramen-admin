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
  std::optional<std::string> aggr;
  dessser::gen::field_name::t_ext alias;
  std::string doc;
  dessser::gen::raql_expr::t_ext expr;
  bool operator==(t const &other) const {
    return aggr == other.aggr && alias == other.alias && doc == other.doc && expr == other.expr;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "aggr:" << r.aggr << ',';
  os << "alias:" << r.alias << ',';
  os << "doc:" << r.doc << ',';
  os << "expr:" << r.expr;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::raql_select_field::t*,
  Pointer
> t36d901fa3ebe9f1e6f4e29b46ea83b2b;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_select_field::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_select_field::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_select_field::t36d901fa3ebe9f1e6f4e29b46ea83b2b(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
