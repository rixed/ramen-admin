#ifndef DESSSER_GEN_func_ref
#define DESSSER_GEN_func_ref
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

namespace dessser::gen::func_ref {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::function_name::t_ext func;
  dessser::gen::program_name::t_ext program;
  dessser::gen::site_name::t_ext site;
  t(dessser::gen::function_name::t_ext func_, dessser::gen::program_name::t_ext program_, dessser::gen::site_name::t_ext site_) : func(func_), program(program_), site(site_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "func:" << ::dessser::gen::function_name::Deref(r.func) << ',';
  os << "program:" << ::dessser::gen::program_name::Deref(r.program) << ',';
  os << "site:" << ::dessser::gen::site_name::Deref(r.site);
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::function_name::Deref(a.func) == ::dessser::gen::function_name::Deref(b.func) && ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tc1232252b3372e81155cf238dacf3283 : public std::tuple<
  ::dessser::gen::func_ref::t*,
  Pointer
> {
  using tuple::tuple;
  tc1232252b3372e81155cf238dacf3283(std::tuple<::dessser::gen::func_ref::t*, Pointer> p)
    : std::tuple<::dessser::gen::func_ref::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc1232252b3372e81155cf238dacf3283 const &a, tc1232252b3372e81155cf238dacf3283 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc1232252b3372e81155cf238dacf3283 const &a, tc1232252b3372e81155cf238dacf3283 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc1232252b3372e81155cf238dacf3283 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::func_ref::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::func_ref::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::func_ref::tc1232252b3372e81155cf238dacf3283(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
