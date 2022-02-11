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
struct t : public std::variant<
  Void, // Unknown
  Void, // In
  Void, // GroupState
  Void, // GlobalState
  Void, // OutPrevious
  Void, // Out
  Void, // SortFirst
  Void, // SortSmallest
  Void, // SortGreatest
  Void, // Param
  Void, // Env
  Void, // Record
  Void // GlobalVar
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 13 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Unknown
    case 1: return std::get<1>(a) == std::get<1>(b); // In
    case 2: return std::get<2>(a) == std::get<2>(b); // GroupState
    case 3: return std::get<3>(a) == std::get<3>(b); // GlobalState
    case 4: return std::get<4>(a) == std::get<4>(b); // OutPrevious
    case 5: return std::get<5>(a) == std::get<5>(b); // Out
    case 6: return std::get<6>(a) == std::get<6>(b); // SortFirst
    case 7: return std::get<7>(a) == std::get<7>(b); // SortSmallest
    case 8: return std::get<8>(a) == std::get<8>(b); // SortGreatest
    case 9: return std::get<9>(a) == std::get<9>(b); // Param
    case 10: return std::get<10>(a) == std::get<10>(b); // Env
    case 11: return std::get<11>(a) == std::get<11>(b); // Record
    case 12: return std::get<12>(a) == std::get<12>(b); // GlobalVar
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
enum Constr_t {
  Unknown,
  In,
  GroupState,
  GlobalState,
  OutPrevious,
  Out,
  SortFirst,
  SortSmallest,
  SortGreatest,
  Param,
  Env,
  Record,
  GlobalVar,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Unknown" << std::get<0>(v); break;
    case 1: os << "In" << std::get<1>(v); break;
    case 2: os << "GroupState" << std::get<2>(v); break;
    case 3: os << "GlobalState" << std::get<3>(v); break;
    case 4: os << "OutPrevious" << std::get<4>(v); break;
    case 5: os << "Out" << std::get<5>(v); break;
    case 6: os << "SortFirst" << std::get<6>(v); break;
    case 7: os << "SortSmallest" << std::get<7>(v); break;
    case 8: os << "SortGreatest" << std::get<8>(v); break;
    case 9: os << "Param" << std::get<9>(v); break;
    case 10: os << "Env" << std::get<10>(v); break;
    case 11: os << "Record" << std::get<11>(v); break;
    case 12: os << "GlobalVar" << std::get<12>(v); break;
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
