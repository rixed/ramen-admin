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
struct t48a2d544f23c6703dc0a88c42484f480 : public std::variant<
  Void, // OutputField
  Void // Parameter
> { using variant::variant; };

enum Constr_t48a2d544f23c6703dc0a88c42484f480 {
  OutputField,
  Parameter,
};

inline std::ostream &operator<<(std::ostream &os, t48a2d544f23c6703dc0a88c42484f480 const &v) {
  switch (v.index()) {
    case 0: os << "OutputField " << std::get<0>(v); break;
    case 1: os << "Parameter " << std::get<1>(v); break;
  }
  return os;
}

struct t : public std::tuple<
  dessser::gen::field_name::t_ext,
  ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480,
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
  ::dessser::gen::event_time_field::t*,
  Pointer
> tb006f453c9f72d09177fd3f76e27ff99;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::event_time_field::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::event_time_field::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::event_time_field::tb006f453c9f72d09177fd3f76e27ff99(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
