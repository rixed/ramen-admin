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
struct t1dcff2c3eac99ab32bfc006552be8787 : public std::variant<
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t1dcff2c3eac99ab32bfc006552be8787 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct t {
  t1dcff2c3eac99ab32bfc006552be8787 scope;
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_type::t_ext typ;
  bool operator==(t const &other) const {
    return scope == other.scope && name == other.name && typ == other.typ;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "scope:" << r.scope << ',';
  os << "name:" << r.name << ',';
  os << "typ:" << r.typ;
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
