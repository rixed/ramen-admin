#ifndef DESSSER_GEN_global_variable
#define DESSSER_GEN_global_variable
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_type.h"
#include "desssergen/field_name.h"

namespace dessser::gen::global_variable {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t652f68aa23f2c18d61b70156eeb125ea : public std::variant<
  Void, // Program
  Void, // Site
  Void // Global
> { using variant::variant; };

enum Constr_t652f68aa23f2c18d61b70156eeb125ea {
  Program,
  Site,
  Global,
};

inline std::ostream &operator<<(std::ostream &os, t652f68aa23f2c18d61b70156eeb125ea const &v) {
  switch (v.index()) {
    case 0: os << "Program " << std::get<0>(v); break;
    case 1: os << "Site " << std::get<1>(v); break;
    case 2: os << "Global " << std::get<2>(v); break;
  }
  return os;
}

struct t {
  dessser::gen::field_name::t_ext name;
  ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea scope;
  dessser::gen::raql_type::t_ext typ;
  bool operator==(t const &other) const {
    return name == other.name && scope == other.scope && typ == other.typ;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "scope:" << r.scope << ',';
  os << "typ:" << r.typ;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::global_variable::t*,
  Pointer
> t5cd24a9f87710319310e9dd0c1e1d2fb;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::global_variable::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::global_variable::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
