#ifndef DESSSER_GEN_retention
#define DESSSER_GEN_retention
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_expr.h"

namespace dessser::gen::retention {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::raql_expr::t_ext duration;
  double period;
  t(dessser::gen::raql_expr::t_ext duration_, double period_) : duration(duration_), period(period_) {}
  t() = default;
  bool operator==(t const &other) const {
    return duration == other.duration && period == other.period;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "duration:" << r.duration << ',';
  os << "period:" << r.period;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::retention::t*,
  Pointer
> td879f0124877ae7a41564ce519541045;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::retention::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::retention::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::retention::td879f0124877ae7a41564ce519541045(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
