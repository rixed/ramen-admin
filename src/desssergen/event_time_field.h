#ifndef DESSSER_GEN_event_time_field
#define DESSSER_GEN_event_time_field
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"

namespace dessser::gen::event_time_field {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tc66891f26215ed3a95ca778dcaba5d3c : public std::variant<
  Void, // OutputField
  Void // Parameter
> { using variant::variant; };

inline bool operator==(tc66891f26215ed3a95ca778dcaba5d3c const &a, tc66891f26215ed3a95ca778dcaba5d3c const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // OutputField
    case 1: return std::get<1>(a) == std::get<1>(b); // Parameter
  };
  return false;
}
inline bool operator!=(tc66891f26215ed3a95ca778dcaba5d3c const &a, tc66891f26215ed3a95ca778dcaba5d3c const &b) {
  return !operator==(a, b);
}
enum Constr_tc66891f26215ed3a95ca778dcaba5d3c {
  OutputField,
  Parameter,
};

inline std::ostream &operator<<(std::ostream &os, tc66891f26215ed3a95ca778dcaba5d3c const &v) {
  switch (v.index()) {
    case 0: os << "OutputField" << std::get<0>(v); break;
    case 1: os << "Parameter" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc66891f26215ed3a95ca778dcaba5d3c> const v) { os << *v; return os; }

struct t : public std::tuple<
  dessser::gen::field_name::t_ext,
  ::dessser::gen::event_time_field::tc66891f26215ed3a95ca778dcaba5d3c,
  double
> {
  using tuple::tuple;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const t) { os << *t; return os; }

struct t3e9f667e2981ef35bfede890d7e0f667 : public std::tuple<
  std::shared_ptr<::dessser::gen::event_time_field::t> ,
  Pointer
> {
  using tuple::tuple;
  t3e9f667e2981ef35bfede890d7e0f667(std::tuple<std::shared_ptr<::dessser::gen::event_time_field::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::event_time_field::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3e9f667e2981ef35bfede890d7e0f667 const &a, t3e9f667e2981ef35bfede890d7e0f667 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3e9f667e2981ef35bfede890d7e0f667 const &a, t3e9f667e2981ef35bfede890d7e0f667 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t3e9f667e2981ef35bfede890d7e0f667 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t3e9f667e2981ef35bfede890d7e0f667> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::event_time_field::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::event_time_field::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::event_time_field::t3e9f667e2981ef35bfede890d7e0f667(Pointer)> of_row_binary;
extern std::function<::dessser::gen::event_time_field::t3e9f667e2981ef35bfede890d7e0f667(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::event_time_field::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
