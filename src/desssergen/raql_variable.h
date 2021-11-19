#ifndef DESSSER_GEN_raql_variable
#define DESSSER_GEN_raql_variable
#include <arpa/inet.h>
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
> { using variant::variant; };

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
    case 0: os << "Unknown " << std::get<0>(v); break;
    case 1: os << "In " << std::get<1>(v); break;
    case 2: os << "GroupState " << std::get<2>(v); break;
    case 3: os << "GlobalState " << std::get<3>(v); break;
    case 4: os << "OutPrevious " << std::get<4>(v); break;
    case 5: os << "Out " << std::get<5>(v); break;
    case 6: os << "SortFirst " << std::get<6>(v); break;
    case 7: os << "SortSmallest " << std::get<7>(v); break;
    case 8: os << "SortGreatest " << std::get<8>(v); break;
    case 9: os << "Param " << std::get<9>(v); break;
    case 10: os << "Env " << std::get<10>(v); break;
    case 11: os << "Record " << std::get<11>(v); break;
    case 12: os << "GlobalVar " << std::get<12>(v); break;
  }
  return os;
}

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
struct te9fedb588053185e9707b2b63ba5bb70 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_variable::t> ,
  Pointer
> {
  using tuple::tuple;
  te9fedb588053185e9707b2b63ba5bb70(std::tuple<std::shared_ptr<::dessser::gen::raql_variable::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_variable::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te9fedb588053185e9707b2b63ba5bb70 const &a, te9fedb588053185e9707b2b63ba5bb70 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te9fedb588053185e9707b2b63ba5bb70 const &a, te9fedb588053185e9707b2b63ba5bb70 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te9fedb588053185e9707b2b63ba5bb70 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_variable::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_variable::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_variable::te9fedb588053185e9707b2b63ba5bb70(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t>  r) { os << *r; return os; }

}
#endif
