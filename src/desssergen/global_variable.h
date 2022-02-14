#ifndef DESSSER_GEN_global_variable
#define DESSSER_GEN_global_variable
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
enum t54b6b844175be8bcdfc38eae0dd1a139 {
  Program,
  Site,
  Global,
};

constexpr size_t t54b6b844175be8bcdfc38eae0dd1a139_size { 3 };
inline std::ostream &operator<<(std::ostream &os, t54b6b844175be8bcdfc38eae0dd1a139 const &v) {
  switch (v) {
    case Program: os << "Program"; break;
    case Site: os << "Site"; break;
    case Global: os << "Global"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t54b6b844175be8bcdfc38eae0dd1a139> const v) { os << *v; return os; }

struct t {
  ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 scope;
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_type::t_ext typ;
  t(::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 scope_, dessser::gen::field_name::t_ext name_, dessser::gen::raql_type::t_ext typ_) : scope(scope_), name(name_), typ(typ_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.scope == b.scope && ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "scope:" << r.scope << ',';
  os << "name:" << r.name << ',';
  os << "typ:" << r.typ;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tc84f2fcbb1d2467c59aba5c8fcedbcc6 : public std::tuple<
  ::dessser::gen::global_variable::t,
  Pointer
> {
  using tuple::tuple;
  tc84f2fcbb1d2467c59aba5c8fcedbcc6(std::tuple<::dessser::gen::global_variable::t, Pointer> p)
    : std::tuple<::dessser::gen::global_variable::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc84f2fcbb1d2467c59aba5c8fcedbcc6 const &a, tc84f2fcbb1d2467c59aba5c8fcedbcc6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc84f2fcbb1d2467c59aba5c8fcedbcc6 const &a, tc84f2fcbb1d2467c59aba5c8fcedbcc6 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc84f2fcbb1d2467c59aba5c8fcedbcc6 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc84f2fcbb1d2467c59aba5c8fcedbcc6> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::global_variable::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::global_variable::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::global_variable::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
