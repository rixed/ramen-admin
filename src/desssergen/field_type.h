#ifndef DESSSER_GEN_field_type
#define DESSSER_GEN_field_type
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/units.h"
#include "desssergen/raql_type.h"
#include "desssergen/field_name.h"

namespace dessser::gen::field_type {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  std::optional<std::string> aggr;
  std::string doc;
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_type::t_ext typ;
  std::optional<dessser::gen::units::t_ext> units;
  bool operator==(t const &other) const {
    return aggr == other.aggr && doc == other.doc && name == other.name && typ == other.typ && units == other.units;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "aggr:" << r.aggr << ',';
  os << "doc:" << r.doc << ',';
  os << "name:" << r.name << ',';
  os << "typ:" << r.typ << ',';
  os << "units:" << r.units;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::field_type::t*,
  Pointer
> ta9083c6ab4999123f9c30be0def4cf3a;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::field_type::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::field_type::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::field_type::ta9083c6ab4999123f9c30be0def4cf3a(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
