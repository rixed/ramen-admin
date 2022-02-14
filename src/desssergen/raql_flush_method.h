#ifndef DESSSER_GEN_raql_flush_method
#define DESSSER_GEN_raql_flush_method
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_flush_method {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
enum t {
  reset,
  never,
};

constexpr size_t t_size { 2 };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v) {
    case reset: os << "reset"; break;
    case never: os << "never"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t22f0ae97d4d35fba924b662f438b82f5 : public std::tuple<
  ::dessser::gen::raql_flush_method::t,
  Pointer
> {
  using tuple::tuple;
  t22f0ae97d4d35fba924b662f438b82f5(std::tuple<::dessser::gen::raql_flush_method::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_flush_method::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t22f0ae97d4d35fba924b662f438b82f5 const &a, t22f0ae97d4d35fba924b662f438b82f5 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t22f0ae97d4d35fba924b662f438b82f5 const &a, t22f0ae97d4d35fba924b662f438b82f5 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t22f0ae97d4d35fba924b662f438b82f5 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t22f0ae97d4d35fba924b662f438b82f5> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_flush_method::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_flush_method::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_flush_method::t22f0ae97d4d35fba924b662f438b82f5(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::raql_flush_method::t22f0ae97d4d35fba924b662f438b82f5(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::raql_flush_method::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
