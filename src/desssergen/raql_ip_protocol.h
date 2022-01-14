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
struct t : public std::variant<
  Void, // UDP
  Void // TCP
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // UDP
    case 1: return std::get<1>(a) == std::get<1>(b); // TCP
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
enum Constr_t {
  UDP,
  TCP,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "UDP" << std::get<0>(v); break;
    case 1: os << "TCP" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t6c8e59c4c22b0ccb6b646b9799fa9367 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,
  Pointer
> {
  using tuple::tuple;
  t6c8e59c4c22b0ccb6b646b9799fa9367(std::tuple<std::shared_ptr<::dessser::gen::raql_ip_protocol::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_ip_protocol::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6c8e59c4c22b0ccb6b646b9799fa9367 const &a, t6c8e59c4c22b0ccb6b646b9799fa9367 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6c8e59c4c22b0ccb6b646b9799fa9367 const &a, t6c8e59c4c22b0ccb6b646b9799fa9367 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t6c8e59c4c22b0ccb6b646b9799fa9367 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t6c8e59c4c22b0ccb6b646b9799fa9367> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367(Pointer)> of_row_binary;
extern std::function<::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
