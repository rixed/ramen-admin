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
  dessser::gen::site_name::t_ext site;
  dessser::gen::program_name::t_ext program;
  dessser::gen::function_name::t_ext func;
  t(dessser::gen::site_name::t_ext site_, dessser::gen::program_name::t_ext program_, dessser::gen::function_name::t_ext func_) : site(site_), program(program_), func(func_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site) && ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && ::dessser::gen::function_name::Deref(a.func) == ::dessser::gen::function_name::Deref(b.func);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "site:" << r.site << ',';
  os << "program:" << r.program << ',';
  os << "func:" << r.func;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct taa1ea876bd3405a61d941fe18b62be03 : public std::tuple<
  std::shared_ptr<::dessser::gen::func_ref::t> ,
  Pointer
> {
  using tuple::tuple;
  taa1ea876bd3405a61d941fe18b62be03(std::tuple<std::shared_ptr<::dessser::gen::func_ref::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::func_ref::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(taa1ea876bd3405a61d941fe18b62be03 const &a, taa1ea876bd3405a61d941fe18b62be03 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(taa1ea876bd3405a61d941fe18b62be03 const &a, taa1ea876bd3405a61d941fe18b62be03 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, taa1ea876bd3405a61d941fe18b62be03 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<taa1ea876bd3405a61d941fe18b62be03> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::func_ref::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::func_ref::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03(Pointer)> of_row_binary;
extern std::function<::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::func_ref::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
