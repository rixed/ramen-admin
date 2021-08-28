#ifndef DESSSER_GEN_raql_top_output
#define DESSSER_GEN_raql_top_output
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_top_output {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  Void, // Membership
  Void, // Rank
  Void // List
> { using variant::variant; };

enum Constr_t {
  Membership,
  Rank,
  List,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Membership " << std::get<0>(v); break;
    case 1: os << "Rank " << std::get<1>(v); break;
    case 2: os << "List " << std::get<2>(v); break;
  }
  return os;
}

typedef std::tuple<
  ::dessser::gen::raql_top_output::t*,
  Pointer
> t4a3969c11645c5ce2fe6965562c350c5;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_top_output::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_top_output::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_top_output::t4a3969c11645c5ce2fe6965562c350c5(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
