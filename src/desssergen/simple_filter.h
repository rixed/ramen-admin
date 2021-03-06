#ifndef DESSSER_GEN_simple_filter
#define DESSSER_GEN_simple_filter
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"

namespace dessser::gen::simple_filter {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_name::t_ext lhs;
  std::string rhs;
  std::string op;
  t(dessser::gen::field_name::t_ext lhs_, std::string rhs_, std::string op_) : lhs(lhs_), rhs(rhs_), op(op_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.lhs) == ::dessser::gen::field_name::Deref(b.lhs) && a.rhs == b.rhs && a.op == b.op;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "lhs:" << r.lhs << ',';
  os << "rhs:" << r.rhs << ',';
  os << "op:" << r.op;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t996e97f91d2b9cc027d79136a291a516 : public std::tuple<
  ::dessser::gen::simple_filter::t,
  Pointer
> {
  using tuple::tuple;
  t996e97f91d2b9cc027d79136a291a516(std::tuple<::dessser::gen::simple_filter::t, Pointer> p)
    : std::tuple<::dessser::gen::simple_filter::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t996e97f91d2b9cc027d79136a291a516 const &a, t996e97f91d2b9cc027d79136a291a516 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t996e97f91d2b9cc027d79136a291a516 const &a, t996e97f91d2b9cc027d79136a291a516 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t996e97f91d2b9cc027d79136a291a516 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t996e97f91d2b9cc027d79136a291a516> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::simple_filter::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::simple_filter::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::simple_filter::t996e97f91d2b9cc027d79136a291a516(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::simple_filter::t996e97f91d2b9cc027d79136a291a516(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::simple_filter::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
