#ifndef DESSSER_GEN_func_ref
#define DESSSER_GEN_func_ref
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
struct tff4bf20007a06d9088a88bafe23e44d5 : public std::tuple<
  std::shared_ptr<::dessser::gen::func_ref::t> ,
  Pointer
> {
  using tuple::tuple;
  tff4bf20007a06d9088a88bafe23e44d5(std::tuple<std::shared_ptr<::dessser::gen::func_ref::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::func_ref::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tff4bf20007a06d9088a88bafe23e44d5 const &a, tff4bf20007a06d9088a88bafe23e44d5 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tff4bf20007a06d9088a88bafe23e44d5 const &a, tff4bf20007a06d9088a88bafe23e44d5 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tff4bf20007a06d9088a88bafe23e44d5 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::func_ref::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::func_ref::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::func_ref::tff4bf20007a06d9088a88bafe23e44d5(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
