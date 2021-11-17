#ifndef DESSSER_GEN_simple_filter
#define DESSSER_GEN_simple_filter
#include <arpa/inet.h>
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
struct td37ebe6eab835faa3db142ce469a93d5 : public std::tuple<
  std::shared_ptr<::dessser::gen::simple_filter::t> ,
  Pointer
> {
  using tuple::tuple;
  td37ebe6eab835faa3db142ce469a93d5(std::tuple<std::shared_ptr<::dessser::gen::simple_filter::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::simple_filter::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td37ebe6eab835faa3db142ce469a93d5 const &a, td37ebe6eab835faa3db142ce469a93d5 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td37ebe6eab835faa3db142ce469a93d5 const &a, td37ebe6eab835faa3db142ce469a93d5 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td37ebe6eab835faa3db142ce469a93d5 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::simple_filter::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::simple_filter::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::simple_filter::td37ebe6eab835faa3db142ce469a93d5(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
