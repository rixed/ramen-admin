#ifndef DESSSER_GEN_raql_ip_protocol
#define DESSSER_GEN_raql_ip_protocol
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_ip_protocol {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
enum t {
  UDP,
  TCP,
};

constexpr size_t t_size { 2 };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v) {
    case UDP: os << "UDP"; break;
    case TCP: os << "TCP"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t79eade9ade2a11d25def1cd0e6a98e48 : public std::tuple<
  ::dessser::gen::raql_ip_protocol::t,
  Pointer
> {
  using tuple::tuple;
  t79eade9ade2a11d25def1cd0e6a98e48(std::tuple<::dessser::gen::raql_ip_protocol::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_ip_protocol::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t79eade9ade2a11d25def1cd0e6a98e48 const &a, t79eade9ade2a11d25def1cd0e6a98e48 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t79eade9ade2a11d25def1cd0e6a98e48 const &a, t79eade9ade2a11d25def1cd0e6a98e48 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t79eade9ade2a11d25def1cd0e6a98e48 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t79eade9ade2a11d25def1cd0e6a98e48> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_ip_protocol::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_ip_protocol::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_ip_protocol::t79eade9ade2a11d25def1cd0e6a98e48(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::raql_ip_protocol::t79eade9ade2a11d25def1cd0e6a98e48(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::raql_ip_protocol::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
