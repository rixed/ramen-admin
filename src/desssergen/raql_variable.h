#ifndef DESSSER_GEN_raql_variable
#define DESSSER_GEN_raql_variable
#include <arpa/inet.h>
#include <functional>
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

typedef std::tuple<
  ::dessser::gen::raql_variable::t*,
  Pointer
> tbc8330b08ecf0c6a983540ff732694a2;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_variable::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_variable::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_variable::tbc8330b08ecf0c6a983540ff732694a2(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
