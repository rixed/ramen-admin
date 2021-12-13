#ifndef DESSSER_GEN_raql_flush_method
#define DESSSER_GEN_raql_flush_method
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_flush_method {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  Void, // reset
  Void // never
> { using variant::variant; };

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // reset
    case 1: return std::get<1>(a) == std::get<1>(b); // never
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
enum Constr_t {
  reset,
  never,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "reset" << std::get<0>(v); break;
    case 1: os << "never" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t8a28a190b669d936f20fb6e41e8357f1 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_flush_method::t> ,
  Pointer
> {
  using tuple::tuple;
  t8a28a190b669d936f20fb6e41e8357f1(std::tuple<std::shared_ptr<::dessser::gen::raql_flush_method::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_flush_method::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8a28a190b669d936f20fb6e41e8357f1 const &a, t8a28a190b669d936f20fb6e41e8357f1 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8a28a190b669d936f20fb6e41e8357f1 const &a, t8a28a190b669d936f20fb6e41e8357f1 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t8a28a190b669d936f20fb6e41e8357f1 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t8a28a190b669d936f20fb6e41e8357f1> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_flush_method::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_flush_method::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_flush_method::t8a28a190b669d936f20fb6e41e8357f1(Pointer)> of_row_binary;
extern std::function<::dessser::gen::raql_flush_method::t8a28a190b669d936f20fb6e41e8357f1(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_flush_method::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
