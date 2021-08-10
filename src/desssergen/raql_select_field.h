#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  *raql_expr expr;
  *field_name alias;
  std::string doc;
  std::optional<std::string> aggr;
  bool operator==(t const &other) const {
    return expr == other.expr && alias == other.alias && doc == other.doc && aggr == other.aggr;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "expr:" << r.expr << ',';
  os << "alias:" << r.alias << ',';
  os << "doc:" << r.doc << ',';
  os << "aggr:" << r.aggr;
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
