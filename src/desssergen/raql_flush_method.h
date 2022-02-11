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
struct t : public std::variant<
  Void, // reset
  Void // never
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // reset
    case 1: return std::get<1>(a) == std::get<1>(b); // never
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
enum Constr_t {
  reset,
  never,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "reset" << std::get<0>(v); break;
    case 1: os << "never" << std::get<1>(v); break;
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
