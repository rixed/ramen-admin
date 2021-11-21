#ifndef DESSSER_GEN_global_variable
#define DESSSER_GEN_global_variable
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
    case 0: os << "Program" << std::get<0>(v); break;
    case 1: os << "Site" << std::get<1>(v); break;
    case 2: os << "Global" << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t652f68aa23f2c18d61b70156eeb125ea> const v) { os << *v; return os; }

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
  os << "name:" << r.name << ',';
  os << "scope:" << r.scope << ',';
  os << "typ:" << r.typ;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && a.scope == b.scope && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t12a4afd72f36ee14a00cd9875e781364 : public std::tuple<
  std::shared_ptr<::dessser::gen::global_variable::t> ,
  Pointer
> {
  using tuple::tuple;
  t12a4afd72f36ee14a00cd9875e781364(std::tuple<std::shared_ptr<::dessser::gen::global_variable::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::global_variable::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12a4afd72f36ee14a00cd9875e781364 const &a, t12a4afd72f36ee14a00cd9875e781364 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12a4afd72f36ee14a00cd9875e781364 const &a, t12a4afd72f36ee14a00cd9875e781364 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t12a4afd72f36ee14a00cd9875e781364 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t12a4afd72f36ee14a00cd9875e781364> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::global_variable::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::global_variable::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::global_variable::t12a4afd72f36ee14a00cd9875e781364(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
