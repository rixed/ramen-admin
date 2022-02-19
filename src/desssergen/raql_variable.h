#ifndef DESSSER_GEN_raql_variable
#define DESSSER_GEN_raql_variable
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_variable {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
enum t {
  Unknown,
  In,
  GroupState,
  GlobalState,
  GlobalLastOut,
  LocalLastOut,
  Out,
  SortFirst,
  SortSmallest,
  SortGreatest,
  Param,
  Env,
  Record,
  GlobalVar,
};

constexpr size_t t_size { 14 };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v) {
    case Unknown: os << "Unknown"; break;
    case In: os << "In"; break;
    case GroupState: os << "GroupState"; break;
    case GlobalState: os << "GlobalState"; break;
    case GlobalLastOut: os << "GlobalLastOut"; break;
    case LocalLastOut: os << "LocalLastOut"; break;
    case Out: os << "Out"; break;
    case SortFirst: os << "SortFirst"; break;
    case SortSmallest: os << "SortSmallest"; break;
    case SortGreatest: os << "SortGreatest"; break;
    case Param: os << "Param"; break;
    case Env: os << "Env"; break;
    case Record: os << "Record"; break;
    case GlobalVar: os << "GlobalVar"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t40df163e80e2c56cfae759a1807c4d79 : public std::tuple<
  ::dessser::gen::raql_variable::t,
  Pointer
> {
  using tuple::tuple;
  t40df163e80e2c56cfae759a1807c4d79(std::tuple<::dessser::gen::raql_variable::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_variable::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t40df163e80e2c56cfae759a1807c4d79 const &a, t40df163e80e2c56cfae759a1807c4d79 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t40df163e80e2c56cfae759a1807c4d79 const &a, t40df163e80e2c56cfae759a1807c4d79 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t40df163e80e2c56cfae759a1807c4d79 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t40df163e80e2c56cfae759a1807c4d79> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_variable::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
