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
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_type::t_ext typ;
  std::optional<dessser::gen::units::t_ext> units;
  std::string doc;
  std::optional<std::string> aggr;
  bool operator==(t const &other) const {
    return name == other.name && typ == other.typ && units == other.units && doc == other.doc && aggr == other.aggr;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "typ:" << r.typ << ',';
  os << "units:" << r.units << ',';
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
