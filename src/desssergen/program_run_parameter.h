#ifndef DESSSER_GEN_program_run_parameter
#define DESSSER_GEN_program_run_parameter
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/raql_value.h"
#include "desssergen/field_name.h"

namespace dessser::gen::program_run_parameter {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_value::t_ext value;
  t(dessser::gen::field_name::t_ext name_, dessser::gen::raql_value::t_ext value_) : name(name_), value(value_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << ::dessser::gen::field_name::Deref(r.name) << ',';
  os << "value:" << ::dessser::gen::raql_value::Deref(r.value);
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_value::Deref(a.value) == ::dessser::gen::raql_value::Deref(b.value);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t173f3f612a5483c7df1f08e5e0f5709b : public std::tuple<
  std::shared_ptr<::dessser::gen::program_run_parameter::t> ,
  Pointer
> {
  using tuple::tuple;
  t173f3f612a5483c7df1f08e5e0f5709b(std::tuple<std::shared_ptr<::dessser::gen::program_run_parameter::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::program_run_parameter::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t173f3f612a5483c7df1f08e5e0f5709b const &a, t173f3f612a5483c7df1f08e5e0f5709b const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t173f3f612a5483c7df1f08e5e0f5709b const &a, t173f3f612a5483c7df1f08e5e0f5709b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t173f3f612a5483c7df1f08e5e0f5709b const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::program_run_parameter::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::program_run_parameter::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::program_run_parameter::t173f3f612a5483c7df1f08e5e0f5709b(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t>  r) { os << *r; return os; }

}
#endif
