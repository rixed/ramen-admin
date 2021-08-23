#ifndef DESSSER_GEN_raql_flush_method
#define DESSSER_GEN_raql_flush_method
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_flush_method {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  ::dessser::gen::raql_flush_method::t*,
  Pointer
> tcbc153db83c60379b0035bb8ccfee2da;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_flush_method::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_flush_method::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_flush_method::tcbc153db83c60379b0035bb8ccfee2da(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
