#ifndef DESSSER_GEN_raql_error
#define DESSSER_GEN_raql_error
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_error {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  std::optional<uint32_t> line;
  std::optional<uint32_t> column;
  std::string message;
  t(std::optional<uint32_t> line_, std::optional<uint32_t> column_, std::string message_) : line(line_), column(column_), message(message_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ((a.line && b.line && a.line.value() == b.line.value()) || (!a.line && !b.line)) && ((a.column && b.column && a.column.value() == b.column.value()) || (!a.column && !b.column)) && a.message == b.message;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  if (r.line) os << "line:" << r.line.value() << ',';
  if (r.column) os << "column:" << r.column.value() << ',';
  os << "message:" << r.message;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tc4decde8a76b3f0176e2fbbfd596fe9c : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_error::t> ,
  Pointer
> {
  using tuple::tuple;
  tc4decde8a76b3f0176e2fbbfd596fe9c(std::tuple<std::shared_ptr<::dessser::gen::raql_error::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_error::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc4decde8a76b3f0176e2fbbfd596fe9c const &a, tc4decde8a76b3f0176e2fbbfd596fe9c const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc4decde8a76b3f0176e2fbbfd596fe9c const &a, tc4decde8a76b3f0176e2fbbfd596fe9c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc4decde8a76b3f0176e2fbbfd596fe9c const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc4decde8a76b3f0176e2fbbfd596fe9c> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_error::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_error::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_error::tc4decde8a76b3f0176e2fbbfd596fe9c(Pointer)> of_row_binary;
extern std::function<::dessser::gen::raql_error::tc4decde8a76b3f0176e2fbbfd596fe9c(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_error::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
