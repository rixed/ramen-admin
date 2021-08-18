#ifndef DESSSER_GEN_event_time_field
#define DESSSER_GEN_event_time_field
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"

namespace dessser::gen::event_time_field {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t2dbd741445d7e42b47d58662914c784b : public std::variant<
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t2dbd741445d7e42b47d58662914c784b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t : public std::tuple<
  dessser::gen::field_name::t_ext,
  t2dbd741445d7e42b47d58662914c784b,
  double
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
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
