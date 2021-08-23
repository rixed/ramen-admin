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
struct t85cb3b3308973b3caab409eac4f91fe4 : public std::variant<
  double,
  dessser::gen::event_time_field::t_ext,
  dessser::gen::event_time_field::t_ext
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t85cb3b3308973b3caab409eac4f91fe4 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::event_time_field::t_ext,
  ::dessser::gen::event_time::t85cb3b3308973b3caab409eac4f91fe4
> t;

typedef std::tuple<
  ::dessser::gen::event_time::t*,
  Pointer
> tdaa6372439c84e43d057c41d9a934bcd;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::event_time::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::event_time::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::event_time::tdaa6372439c84e43d057c41d9a934bcd(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
