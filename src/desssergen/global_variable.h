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
struct t92d550ed37bacecb946618f8c58e8de4 : public std::variant<
  Void, // Program
  Void, // Site
  Void // Global
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

inline bool operator==(t92d550ed37bacecb946618f8c58e8de4 const &a, t92d550ed37bacecb946618f8c58e8de4 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Program
    case 1: return std::get<1>(a) == std::get<1>(b); // Site
    case 2: return std::get<2>(a) == std::get<2>(b); // Global
  };
  return false;
}
inline bool operator!=(t92d550ed37bacecb946618f8c58e8de4 const &a, t92d550ed37bacecb946618f8c58e8de4 const &b) {
  return !operator==(a, b);
}
enum Constr_t92d550ed37bacecb946618f8c58e8de4 {
  Program,
  Site,
  Global,
};

inline std::ostream &operator<<(std::ostream &os, t92d550ed37bacecb946618f8c58e8de4 const &v) {
  switch (v.index()) {
    case 0: os << "Program" << std::get<0>(v); break;
    case 1: os << "Site" << std::get<1>(v); break;
    case 2: os << "Global" << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t92d550ed37bacecb946618f8c58e8de4> const v) { os << *v; return os; }

struct t {
  dessser::gen::field_name::t_ext name;
  ::dessser::gen::global_variable::t92d550ed37bacecb946618f8c58e8de4 scope;
  dessser::gen::raql_type::t_ext typ;
  t(dessser::gen::field_name::t_ext name_, ::dessser::gen::global_variable::t92d550ed37bacecb946618f8c58e8de4 scope_, dessser::gen::raql_type::t_ext typ_) : name(name_), scope(scope_), typ(typ_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && a.scope == b.scope && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "scope:" << r.scope << ',';
  os << "typ:" << r.typ;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct taf65a2957250625a7a5650ae2ff774d3 : public std::tuple<
  std::shared_ptr<::dessser::gen::global_variable::t> ,
  Pointer
> {
  using tuple::tuple;
  taf65a2957250625a7a5650ae2ff774d3(std::tuple<std::shared_ptr<::dessser::gen::global_variable::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::global_variable::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(taf65a2957250625a7a5650ae2ff774d3 const &a, taf65a2957250625a7a5650ae2ff774d3 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(taf65a2957250625a7a5650ae2ff774d3 const &a, taf65a2957250625a7a5650ae2ff774d3 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, taf65a2957250625a7a5650ae2ff774d3 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<taf65a2957250625a7a5650ae2ff774d3> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::global_variable::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::global_variable::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::global_variable::taf65a2957250625a7a5650ae2ff774d3(Pointer)> of_row_binary;
extern std::function<::dessser::gen::global_variable::taf65a2957250625a7a5650ae2ff774d3(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::global_variable::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
