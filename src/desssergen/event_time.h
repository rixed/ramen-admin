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
struct tb22291137390f6968b7c7852ed4b8408 : public std::variant<
  double, // DurationConst
  dessser::gen::event_time_field::t_ext, // DurationField
  dessser::gen::event_time_field::t_ext // StopField
> { using variant::variant; };

enum Constr_tb22291137390f6968b7c7852ed4b8408 {
  DurationConst,
  DurationField,
  StopField,
};

inline std::ostream &operator<<(std::ostream &os, tb22291137390f6968b7c7852ed4b8408 const &v) {
  switch (v.index()) {
    case 0: os << "DurationConst " << std::get<0>(v); break;
    case 1: os << "DurationField " << std::get<1>(v); break;
    case 2: os << "StopField " << std::get<2>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::event_time_field::t_ext,
  ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408
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
