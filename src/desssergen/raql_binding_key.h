#ifndef DESSSER_GEN_raql_binding_key
#define DESSSER_GEN_raql_binding_key
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_variable.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_variable.h"

namespace dessser::gen::raql_binding_key {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t40f56917851bc62b1c9e1a72700c3bed : public std::tuple<
  dessser::gen::raql_variable::t_ext,
  dessser::gen::field_name::t_ext
> {
  using tuple::tuple;
  t40f56917851bc62b1c9e1a72700c3bed(std::tuple<dessser::gen::raql_variable::t_ext, dessser::gen::field_name::t_ext> p)
    : std::tuple<dessser::gen::raql_variable::t_ext, dessser::gen::field_name::t_ext>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t40f56917851bc62b1c9e1a72700c3bed const &a, t40f56917851bc62b1c9e1a72700c3bed const &b) {
  return ::dessser::gen::raql_variable::Deref(std::get<0>(a)) == ::dessser::gen::raql_variable::Deref(std::get<0>(b)) && ::dessser::gen::field_name::Deref(std::get<1>(a)) == ::dessser::gen::field_name::Deref(std::get<1>(b));
}
inline bool operator!=(t40f56917851bc62b1c9e1a72700c3bed const &a, t40f56917851bc62b1c9e1a72700c3bed const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t40f56917851bc62b1c9e1a72700c3bed const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t40f56917851bc62b1c9e1a72700c3bed> const t) { os << *t; return os; }

struct t : public std::variant<
  uint32_t, // State
  ::dessser::gen::raql_binding_key::t40f56917851bc62b1c9e1a72700c3bed, // RecordField
  dessser::gen::raql_variable::t_ext, // RecordValue
  std::string // Direct
> { using variant::variant; };

enum Constr_t {
  State,
  RecordField,
  RecordValue,
  Direct,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "State " << std::get<0>(v); break;
    case 1: os << "RecordField " << std::get<1>(v); break;
    case 2: os << "RecordValue " << std::get<2>(v); break;
    case 3: os << "Direct " << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // State
    case 1: return std::get<1>(a) == std::get<1>(b); // RecordField
    case 2: return ::dessser::gen::raql_variable::Deref(std::get<2>(a)) == ::dessser::gen::raql_variable::Deref(std::get<2>(b)); // RecordValue
    case 3: return std::get<3>(a) == std::get<3>(b); // Direct
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tb153335fc05f1eec6819ab87a88b916a : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_binding_key::t> ,
  Pointer
> {
  using tuple::tuple;
  tb153335fc05f1eec6819ab87a88b916a(std::tuple<std::shared_ptr<::dessser::gen::raql_binding_key::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_binding_key::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb153335fc05f1eec6819ab87a88b916a const &a, tb153335fc05f1eec6819ab87a88b916a const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb153335fc05f1eec6819ab87a88b916a const &a, tb153335fc05f1eec6819ab87a88b916a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb153335fc05f1eec6819ab87a88b916a const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tb153335fc05f1eec6819ab87a88b916a> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_binding_key::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_binding_key::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
