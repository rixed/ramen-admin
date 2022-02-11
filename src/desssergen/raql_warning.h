#ifndef DESSSER_GEN_raql_warning
#define DESSSER_GEN_raql_warning
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_warning {
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

struct tde111694a17169793df63837585293d4 : public std::tuple<
  ::dessser::gen::raql_warning::t,
  Pointer
> {
  using tuple::tuple;
  tde111694a17169793df63837585293d4(std::tuple<::dessser::gen::raql_warning::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_warning::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tde111694a17169793df63837585293d4 const &a, tde111694a17169793df63837585293d4 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tde111694a17169793df63837585293d4 const &a, tde111694a17169793df63837585293d4 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tde111694a17169793df63837585293d4 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tde111694a17169793df63837585293d4> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_warning::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_warning::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_warning::tde111694a17169793df63837585293d4(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::raql_warning::tde111694a17169793df63837585293d4(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::raql_warning::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
