#ifndef DESSSER_GEN_sync_socket
#define DESSSER_GEN_sync_socket
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::sync_socket {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t690438e8d106ddec68c668ab00e5188a : public std::variant<
  uint32_t, // v4
  uint128_t // v6
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t690438e8d106ddec68c668ab00e5188a const &a, t690438e8d106ddec68c668ab00e5188a const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // v4
    case 1: return std::get<1>(a) == std::get<1>(b); // v6
  };
  return false;
}
inline bool operator!=(t690438e8d106ddec68c668ab00e5188a const &a, t690438e8d106ddec68c668ab00e5188a const &b) {
  return !operator==(a, b);
}
enum Constr_t690438e8d106ddec68c668ab00e5188a {
  v4,
  v6,
};

inline std::ostream &operator<<(std::ostream &os, t690438e8d106ddec68c668ab00e5188a const &v) {
  switch (v.index()) {
    case 0: os << "v4 " << std::get<0>(v); break;
    case 1: os << "v6 " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t690438e8d106ddec68c668ab00e5188a> const v) { os << *v; return os; }

struct t {
  ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a ip;
  uint16_t port;
  t(::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a ip_, uint16_t port_) : ip(ip_), port(port_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.ip == b.ip && a.port == b.port;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "port:" << r.port;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tc5e6846e85f79c9786f90afd8b73dfb1 : public std::tuple<
  ::dessser::gen::sync_socket::t,
  Pointer
> {
  using tuple::tuple;
  tc5e6846e85f79c9786f90afd8b73dfb1(std::tuple<::dessser::gen::sync_socket::t, Pointer> p)
    : std::tuple<::dessser::gen::sync_socket::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc5e6846e85f79c9786f90afd8b73dfb1 const &a, tc5e6846e85f79c9786f90afd8b73dfb1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc5e6846e85f79c9786f90afd8b73dfb1 const &a, tc5e6846e85f79c9786f90afd8b73dfb1 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc5e6846e85f79c9786f90afd8b73dfb1 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc5e6846e85f79c9786f90afd8b73dfb1> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_socket::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_socket::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::sync_socket::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
