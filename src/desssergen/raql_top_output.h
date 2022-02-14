#ifndef DESSSER_GEN_raql_top_output
#define DESSSER_GEN_raql_top_output
#include <functional>
#include <memory>
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
enum t {
  Membership,
  Rank,
  List,
};

constexpr size_t t_size { 3 };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v) {
    case Membership: os << "Membership"; break;
    case Rank: os << "Rank"; break;
    case List: os << "List"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct tb4cf14c6c35a0613c4e1d589a1a0feb5 : public std::tuple<
  ::dessser::gen::raql_top_output::t,
  Pointer
> {
  using tuple::tuple;
  tb4cf14c6c35a0613c4e1d589a1a0feb5(std::tuple<::dessser::gen::raql_top_output::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_top_output::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb4cf14c6c35a0613c4e1d589a1a0feb5 const &a, tb4cf14c6c35a0613c4e1d589a1a0feb5 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb4cf14c6c35a0613c4e1d589a1a0feb5 const &a, tb4cf14c6c35a0613c4e1d589a1a0feb5 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb4cf14c6c35a0613c4e1d589a1a0feb5 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tb4cf14c6c35a0613c4e1d589a1a0feb5> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_top_output::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_top_output::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_top_output::tb4cf14c6c35a0613c4e1d589a1a0feb5(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::raql_top_output::tb4cf14c6c35a0613c4e1d589a1a0feb5(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::raql_top_output::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
