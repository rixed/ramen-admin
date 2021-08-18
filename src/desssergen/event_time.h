#ifndef DESSSER_GEN_event_time
#define DESSSER_GEN_event_time
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/event_time_field.h"
#include "desssergen/event_time_field.h"
#include "desssergen/event_time_field.h"

namespace dessser::gen::event_time {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t1a52f882c9037437cef3177237d6aa2c : public std::variant<
  double,
  dessser::gen::event_time_field::t_ext,
  dessser::gen::event_time_field::t_ext
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t1a52f882c9037437cef3177237d6aa2c const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::event_time_field::t_ext,
  t1a52f882c9037437cef3177237d6aa2c
> t;

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
