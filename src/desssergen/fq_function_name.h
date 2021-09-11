#ifndef DESSSER_GEN_fq_function_name
#define DESSSER_GEN_fq_function_name
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/function_name.h"
#include "desssergen/program_name.h"
#include "desssergen/site_name.h"

namespace dessser::gen::fq_function_name {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::function_name::t_ext function;
  dessser::gen::program_name::t_ext program;
  dessser::gen::site_name::t_ext site;
  t(dessser::gen::function_name::t_ext function_, dessser::gen::program_name::t_ext program_, dessser::gen::site_name::t_ext site_) : function(function_), program(program_), site(site_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "function:" << ::dessser::gen::function_name::Deref(r.function) << ',';
  os << "program:" << ::dessser::gen::program_name::Deref(r.program) << ',';
  os << "site:" << ::dessser::gen::site_name::Deref(r.site);
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::function_name::Deref(a.function) == ::dessser::gen::function_name::Deref(b.function) && ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tf533ff813b5d329c8f12bc34e9fcc752 : public std::tuple<
  ::dessser::gen::fq_function_name::t*,
  Pointer
> {
  using tuple::tuple;
  tf533ff813b5d329c8f12bc34e9fcc752(std::tuple<::dessser::gen::fq_function_name::t*, Pointer> p)
    : std::tuple<::dessser::gen::fq_function_name::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf533ff813b5d329c8f12bc34e9fcc752 const &a, tf533ff813b5d329c8f12bc34e9fcc752 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf533ff813b5d329c8f12bc34e9fcc752 const &a, tf533ff813b5d329c8f12bc34e9fcc752 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf533ff813b5d329c8f12bc34e9fcc752 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::fq_function_name::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::fq_function_name::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
