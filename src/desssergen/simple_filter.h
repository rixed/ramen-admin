#ifndef DESSSER_GEN_simple_filter
#define DESSSER_GEN_simple_filter
#include <arpa/inet.h>
#include <functional>
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
  std::string op;
  std::string rhs;
  t(dessser::gen::field_name::t_ext lhs_, std::string op_, std::string rhs_) : lhs(lhs_), op(op_), rhs(rhs_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "lhs:" << ::dessser::gen::field_name::Deref(r.lhs) << ',';
  os << "op:" << r.op << ',';
  os << "rhs:" << r.rhs;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.lhs) == ::dessser::gen::field_name::Deref(b.lhs) && a.op == b.op && a.rhs == b.rhs;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  ::dessser::gen::simple_filter::t*,
  Pointer
> t5ec462bd9f9d5a838e7e865b5af804fe;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::simple_filter::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::simple_filter::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
