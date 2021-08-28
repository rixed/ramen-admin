#ifndef DESSSER_GEN_raql_binding_key
#define DESSSER_GEN_raql_binding_key
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_variable.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_variable.h"

namespace dessser::gen::raql_binding_key {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  dessser::gen::raql_variable::t_ext,
  dessser::gen::field_name::t_ext
> t269f127ed3b1b265bbc0b9043d333314;

struct t : public std::variant<
  uint32_t, // State
  ::dessser::gen::raql_binding_key::t269f127ed3b1b265bbc0b9043d333314, // RecordField
  dessser::gen::raql_variable::t_ext, // RecordValue
  std::string // Direct
> { using variant::variant; };

enum Constr_t {
  State,
  RecordField,
  RecordValue,
  Direct,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "State " << std::get<0>(v); break;
    case 1: os << "RecordField " << std::get<1>(v); break;
    case 2: os << "RecordValue " << std::get<2>(v); break;
    case 3: os << "Direct " << std::get<3>(v); break;
  }
  return os;
}

typedef std::tuple<
  ::dessser::gen::raql_binding_key::t*,
  Pointer
> t2fb89294d169d1b8c1dc7c9181c50762;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_binding_key::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_binding_key::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_binding_key::t2fb89294d169d1b8c1dc7c9181c50762(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
