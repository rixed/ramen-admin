#ifndef DESSSER_GEN_raql_path_comp
#define DESSSER_GEN_raql_path_comp
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"

namespace dessser::gen::raql_path_comp {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  uint32_t, // Idx
  dessser::gen::field_name::t_ext // Name
> { using variant::variant; };

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Idx
    case 1: return ::dessser::gen::field_name::Deref(std::get<1>(a)) == ::dessser::gen::field_name::Deref(std::get<1>(b)); // Name
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
enum Constr_t {
  Idx,
  Name,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "Idx " << std::get<0>(v); break;
    case 1: os << "Name " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t16c6226b84acb3730f799350894ac2a3 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_path_comp::t> ,
  Pointer
> {
  using tuple::tuple;
  t16c6226b84acb3730f799350894ac2a3(std::tuple<std::shared_ptr<::dessser::gen::raql_path_comp::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_path_comp::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t16c6226b84acb3730f799350894ac2a3 const &a, t16c6226b84acb3730f799350894ac2a3 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t16c6226b84acb3730f799350894ac2a3 const &a, t16c6226b84acb3730f799350894ac2a3 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t16c6226b84acb3730f799350894ac2a3 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t16c6226b84acb3730f799350894ac2a3> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_path_comp::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_path_comp::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_path_comp::t16c6226b84acb3730f799350894ac2a3(Pointer)> of_row_binary;
extern std::function<::dessser::gen::raql_path_comp::t16c6226b84acb3730f799350894ac2a3(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_path_comp::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
