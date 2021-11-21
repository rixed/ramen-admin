#ifndef DESSSER_GEN_fq_function_name
#define DESSSER_GEN_fq_function_name
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
  os << "function:" << r.function << ',';
  os << "program:" << r.program << ',';
  os << "site:" << r.site;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::function_name::Deref(a.function) == ::dessser::gen::function_name::Deref(b.function) && ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tb5cd2749aa7785c10c094474448db9bb : public std::tuple<
  std::shared_ptr<::dessser::gen::fq_function_name::t> ,
  Pointer
> {
  using tuple::tuple;
  tb5cd2749aa7785c10c094474448db9bb(std::tuple<std::shared_ptr<::dessser::gen::fq_function_name::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::fq_function_name::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb5cd2749aa7785c10c094474448db9bb const &a, tb5cd2749aa7785c10c094474448db9bb const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb5cd2749aa7785c10c094474448db9bb const &a, tb5cd2749aa7785c10c094474448db9bb const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb5cd2749aa7785c10c094474448db9bb const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tb5cd2749aa7785c10c094474448db9bb> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::fq_function_name::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::fq_function_name::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::fq_function_name::tb5cd2749aa7785c10c094474448db9bb(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
