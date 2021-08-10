#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct v_7dc4293225aede806bbbfec766da77a3 : public std::variant<
  double,
  *event_time_field,
  *event_time_field
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_7dc4293225aede806bbbfec766da77a3 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

typedef std::tuple<
  *event_time_field,
  v_7dc4293225aede806bbbfec766da77a3
> t;

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
