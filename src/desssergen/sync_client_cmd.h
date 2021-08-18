#ifndef DESSSER_GEN_sync_client_cmd
#define DESSSER_GEN_sync_client_cmd
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_selector.h"
#include "desssergen/sync_user_id.h"

namespace dessser::gen::sync_client_cmd {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  dessser::gen::sync_user_id::t_ext,
  double
> td17298225a9b57dc7469fe7682403a40;

typedef std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext
> t08ff092200f210c10792e73a746a4bfd;

struct t2887a6d9058ae0e0e681d62129c69c50 : public std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext,
  double,
  bool
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t2887a6d9058ae0e0e681d62129c69c50 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct t3fa061ec66599e2b8b3b5d44d886f101 : public std::tuple<
  dessser::gen::sync_key::t_ext,
  double,
  bool
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t3fa061ec66599e2b8b3b5d44d886f101 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t : public std::variant<
  td17298225a9b57dc7469fe7682403a40,
  dessser::gen::sync_selector::t_ext,
  t08ff092200f210c10792e73a746a4bfd,
  t2887a6d9058ae0e0e681d62129c69c50,
  t08ff092200f210c10792e73a746a4bfd,
  dessser::gen::sync_key::t_ext,
  t3fa061ec66599e2b8b3b5d44d886f101,
  t3fa061ec66599e2b8b3b5d44d886f101,
  dessser::gen::sync_key::t_ext,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
    case 8: os << std::get<8>(v); break;
    case 9: os << std::get<9>(v); break;
  }
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
