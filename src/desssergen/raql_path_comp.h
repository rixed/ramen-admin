#ifndef DESSSER_GEN_raql_path_comp
#define DESSSER_GEN_raql_path_comp
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"

namespace dessser::gen::raql_path_comp {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  uint32_t,
  dessser::gen::field_name::t_ext
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  ::dessser::gen::raql_path_comp::t*,
  Pointer
> td126b489ead23b1cdc9c388bd4ee24bc;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_path_comp::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_path_comp::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_path_comp::td126b489ead23b1cdc9c388bd4ee24bc(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
