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
  dessser::gen::site_name::t_ext site;
  dessser::gen::program_name::t_ext program;
  dessser::gen::function_name::t_ext function;
  t(dessser::gen::site_name::t_ext site_, dessser::gen::program_name::t_ext program_, dessser::gen::function_name::t_ext function_) : site(site_), program(program_), function(function_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site) && ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && ::dessser::gen::function_name::Deref(a.function) == ::dessser::gen::function_name::Deref(b.function);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "site:" << r.site << ',';
  os << "program:" << r.program << ',';
  os << "function:" << r.function;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tf1fae54ea048ad49ea9dc7e6824f4917 : public std::tuple<
  std::shared_ptr<::dessser::gen::fq_function_name::t> ,
  Pointer
> {
  using tuple::tuple;
  tf1fae54ea048ad49ea9dc7e6824f4917(std::tuple<std::shared_ptr<::dessser::gen::fq_function_name::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::fq_function_name::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf1fae54ea048ad49ea9dc7e6824f4917 const &a, tf1fae54ea048ad49ea9dc7e6824f4917 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf1fae54ea048ad49ea9dc7e6824f4917 const &a, tf1fae54ea048ad49ea9dc7e6824f4917 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf1fae54ea048ad49ea9dc7e6824f4917 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf1fae54ea048ad49ea9dc7e6824f4917> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::fq_function_name::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::fq_function_name::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::fq_function_name::tf1fae54ea048ad49ea9dc7e6824f4917(Pointer)> of_row_binary;
extern std::function<::dessser::gen::fq_function_name::tf1fae54ea048ad49ea9dc7e6824f4917(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::fq_function_name::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
