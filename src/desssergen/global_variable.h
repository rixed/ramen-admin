#ifndef DESSSER_GEN_global_variable
#define DESSSER_GEN_global_variable
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_type.h"
#include "desssergen/field_name.h"

namespace dessser::gen::global_variable {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t652f68aa23f2c18d61b70156eeb125ea : public std::variant<
  Void, // Program
  Void, // Site
  Void // Global
> { using variant::variant; };

enum Constr_t652f68aa23f2c18d61b70156eeb125ea {
  Program,
  Site,
  Global,
};

inline std::ostream &operator<<(std::ostream &os, t652f68aa23f2c18d61b70156eeb125ea const &v) {
  switch (v.index()) {
    case 0: os << "Program " << std::get<0>(v); break;
    case 1: os << "Site " << std::get<1>(v); break;
    case 2: os << "Global " << std::get<2>(v); break;
  }
  return os;
}

inline bool operator==(t652f68aa23f2c18d61b70156eeb125ea const &a, t652f68aa23f2c18d61b70156eeb125ea const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Program
    case 1: return std::get<1>(a) == std::get<1>(b); // Site
    case 2: return std::get<2>(a) == std::get<2>(b); // Global
  };
  return false;
}
inline bool operator!=(t652f68aa23f2c18d61b70156eeb125ea const &a, t652f68aa23f2c18d61b70156eeb125ea const &b) {
  return !operator==(a, b);
}
struct t {
  dessser::gen::field_name::t_ext name;
  ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea scope;
  dessser::gen::raql_type::t_ext typ;
  t(dessser::gen::field_name::t_ext name_, ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea scope_, dessser::gen::raql_type::t_ext typ_) : name(name_), scope(scope_), typ(typ_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << ::dessser::gen::field_name::Deref(r.name) << ',';
  os << "scope:" << r.scope << ',';
  os << "typ:" << ::dessser::gen::raql_type::Deref(r.typ);
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && a.scope == b.scope && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct te0fdf9308787ca06b18f7afa420eb4db : public std::tuple<
  ::dessser::gen::global_variable::t*,
  Pointer
> {
  using tuple::tuple;
  te0fdf9308787ca06b18f7afa420eb4db(std::tuple<::dessser::gen::global_variable::t*, Pointer> p)
    : std::tuple<::dessser::gen::global_variable::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te0fdf9308787ca06b18f7afa420eb4db const &a, te0fdf9308787ca06b18f7afa420eb4db const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te0fdf9308787ca06b18f7afa420eb4db const &a, te0fdf9308787ca06b18f7afa420eb4db const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te0fdf9308787ca06b18f7afa420eb4db const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::global_variable::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::global_variable::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::global_variable::te0fdf9308787ca06b18f7afa420eb4db(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
