#ifndef DESSSER_GEN_raql_expr
#define DESSSER_GEN_raql_expr
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/units.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_top_output.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_path_comp.h"
#include "desssergen/raql_binding_key.h"
#include "desssergen/raql_variable.h"
#include "desssergen/raql_value.h"
#include "desssergen/field_name.h"

namespace dessser::gen::raql_expr {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tddfc646ae3827db7d4914729994bdbb1 : public std::tuple<
  dessser::gen::field_name::t_ext,
  t*
> {
  using tuple::tuple;
  tddfc646ae3827db7d4914729994bdbb1(std::tuple<dessser::gen::field_name::t_ext, t*> p)
    : std::tuple<dessser::gen::field_name::t_ext, t*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tddfc646ae3827db7d4914729994bdbb1 const &a, tddfc646ae3827db7d4914729994bdbb1 const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(tddfc646ae3827db7d4914729994bdbb1 const &a, tddfc646ae3827db7d4914729994bdbb1 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tddfc646ae3827db7d4914729994bdbb1 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t)
     << '>';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t39d6b38be34658e00b272e1147f8bf0c {
  t* case_cond;
  t* case_cons;
  t39d6b38be34658e00b272e1147f8bf0c(t* case_cond_, t* case_cons_) : case_cond(case_cond_), case_cons(case_cons_) {}
  t39d6b38be34658e00b272e1147f8bf0c() = default;
};
inline std::ostream &operator<<(std::ostream &os, t39d6b38be34658e00b272e1147f8bf0c const &r) {
  os << '{';
  os << "case_cond:" << (*r.case_cond) << ',';
  os << "case_cons:" << (*r.case_cons);
  os << '}';
  return os;
}
inline bool operator==(t39d6b38be34658e00b272e1147f8bf0c const &a, t39d6b38be34658e00b272e1147f8bf0c const &b) {
  return (*a.case_cond) == (*b.case_cond) && (*a.case_cons) == (*b.case_cons);
}

inline bool operator!=(t39d6b38be34658e00b272e1147f8bf0c const &a, t39d6b38be34658e00b272e1147f8bf0c const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct td73e40f734c89c38f2d6352e81bfc1af : public std::tuple<
  Lst<::dessser::gen::raql_expr::t39d6b38be34658e00b272e1147f8bf0c>,
  std::optional<t*>
> {
  using tuple::tuple;
  td73e40f734c89c38f2d6352e81bfc1af(std::tuple<Lst<::dessser::gen::raql_expr::t39d6b38be34658e00b272e1147f8bf0c>, std::optional<t*>> p)
    : std::tuple<Lst<::dessser::gen::raql_expr::t39d6b38be34658e00b272e1147f8bf0c>, std::optional<t*>>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td73e40f734c89c38f2d6352e81bfc1af const &a, td73e40f734c89c38f2d6352e81bfc1af const &b) {
  return std::get<0>(a) == std::get<0>(b) && ((std::get<1>(a) && std::get<1>(b) && (*std::get<1>(a).value()) == (*std::get<1>(b).value())) || (!std::get<1>(a) && !std::get<1>(b)));
}
inline bool operator!=(td73e40f734c89c38f2d6352e81bfc1af const &a, td73e40f734c89c38f2d6352e81bfc1af const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td73e40f734c89c38f2d6352e81bfc1af const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t)
     << '>';
  return os;
}

struct tf7ae7db1c515d769014dcb9b31531498 : public std::variant<
  dessser::gen::raql_value::t_ext, // Const
  dessser::gen::raql_variable::t_ext, // Variable
  dessser::gen::raql_binding_key::t_ext, // Binding
  Void, // Now
  Void, // Random
  Void, // EventStart
  Void, // EventStop
  Lst<dessser::gen::raql_path_comp::t_ext>, // Path
  Void // Pi
> { using variant::variant; };

enum Constr_tf7ae7db1c515d769014dcb9b31531498 {
  Const,
  Variable,
  Binding,
  Now,
  Random,
  EventStart,
  EventStop,
  Path,
  Pi,
};

inline std::ostream &operator<<(std::ostream &os, tf7ae7db1c515d769014dcb9b31531498 const &v) {
  switch (v.index()) {
    case 0: os << "Const " << ::dessser::gen::raql_value::Deref(std::get<0>(v)); break;
    case 1: os << "Variable " << ::dessser::gen::raql_variable::Deref(std::get<1>(v)); break;
    case 2: os << "Binding " << ::dessser::gen::raql_binding_key::Deref(std::get<2>(v)); break;
    case 3: os << "Now " << std::get<3>(v); break;
    case 4: os << "Random " << std::get<4>(v); break;
    case 5: os << "EventStart " << std::get<5>(v); break;
    case 6: os << "EventStop " << std::get<6>(v); break;
    case 7: os << "Path " << std::get<7>(v); break;
    case 8: os << "Pi " << std::get<8>(v); break;
  }
  return os;
}

inline bool operator==(tf7ae7db1c515d769014dcb9b31531498 const &a, tf7ae7db1c515d769014dcb9b31531498 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::raql_value::Deref(std::get<0>(a)) == ::dessser::gen::raql_value::Deref(std::get<0>(b)); // Const
    case 1: return ::dessser::gen::raql_variable::Deref(std::get<1>(a)) == ::dessser::gen::raql_variable::Deref(std::get<1>(b)); // Variable
    case 2: return ::dessser::gen::raql_binding_key::Deref(std::get<2>(a)) == ::dessser::gen::raql_binding_key::Deref(std::get<2>(b)); // Binding
    case 3: return std::get<3>(a) == std::get<3>(b); // Now
    case 4: return std::get<4>(a) == std::get<4>(b); // Random
    case 5: return std::get<5>(a) == std::get<5>(b); // EventStart
    case 6: return std::get<6>(a) == std::get<6>(b); // EventStop
    case 7: return std::get<7>(a) == std::get<7>(b); // Path
    case 8: return std::get<8>(a) == std::get<8>(b); // Pi
  };
  return false;
}
inline bool operator!=(tf7ae7db1c515d769014dcb9b31531498 const &a, tf7ae7db1c515d769014dcb9b31531498 const &b) {
  return !operator==(a, b);
}
struct tc847b6b1db0945d7ec695a4564143cf9 : public std::variant<
  Void, // LittleEndian
  Void // BigEndian
> { using variant::variant; };

enum Constr_tc847b6b1db0945d7ec695a4564143cf9 {
  LittleEndian,
  BigEndian,
};

inline std::ostream &operator<<(std::ostream &os, tc847b6b1db0945d7ec695a4564143cf9 const &v) {
  switch (v.index()) {
    case 0: os << "LittleEndian " << std::get<0>(v); break;
    case 1: os << "BigEndian " << std::get<1>(v); break;
  }
  return os;
}

inline bool operator==(tc847b6b1db0945d7ec695a4564143cf9 const &a, tc847b6b1db0945d7ec695a4564143cf9 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // LittleEndian
    case 1: return std::get<1>(a) == std::get<1>(b); // BigEndian
  };
  return false;
}
inline bool operator!=(tc847b6b1db0945d7ec695a4564143cf9 const &a, tc847b6b1db0945d7ec695a4564143cf9 const &b) {
  return !operator==(a, b);
}
struct te0e199631746ade8fdd411b7e499dc4a : public std::tuple<
  dessser::gen::raql_type::t_ext,
  ::dessser::gen::raql_expr::tc847b6b1db0945d7ec695a4564143cf9
> {
  using tuple::tuple;
  te0e199631746ade8fdd411b7e499dc4a(std::tuple<dessser::gen::raql_type::t_ext, ::dessser::gen::raql_expr::tc847b6b1db0945d7ec695a4564143cf9> p)
    : std::tuple<dessser::gen::raql_type::t_ext, ::dessser::gen::raql_expr::tc847b6b1db0945d7ec695a4564143cf9>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te0e199631746ade8fdd411b7e499dc4a const &a, te0e199631746ade8fdd411b7e499dc4a const &b) {
  return ::dessser::gen::raql_type::Deref(std::get<0>(a)) == ::dessser::gen::raql_type::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te0e199631746ade8fdd411b7e499dc4a const &a, te0e199631746ade8fdd411b7e499dc4a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te0e199631746ade8fdd411b7e499dc4a const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t55f3c32df481113125a05cab83e4d003 : public std::variant<
  Void, // Age
  dessser::gen::raql_type::t_ext, // Cast
  Void, // Force
  ::dessser::gen::raql_expr::te0e199631746ade8fdd411b7e499dc4a, // Peek
  Void, // Length
  Void, // Lower
  Void, // Upper
  Void, // UuidOfU128
  Void, // Not
  Void, // Abs
  Void, // Minus
  Void, // Defined
  Void, // Exp
  Void, // Log
  Void, // Log10
  Void, // Sqrt
  Void, // Sq
  Void, // Ceil
  Void, // Floor
  Void, // Round
  Void, // Cos
  Void, // Sin
  Void, // Tan
  Void, // ACos
  Void, // ASin
  Void, // ATan
  Void, // CosH
  Void, // SinH
  Void, // TanH
  Void, // Hash
  Void, // BeginOfRange
  Void, // EndOfRange
  Void, // Sparkline
  Void, // Strptime
  Void, // Variant
  Void, // Chr
  std::string, // Like
  Void, // Fit
  Void, // CountryCode
  Void, // IpFamily
  Void // Basename
> { using variant::variant; };

enum Constr_t55f3c32df481113125a05cab83e4d003 {
  Age,
  Cast,
  Force,
  Peek,
  Length,
  Lower,
  Upper,
  UuidOfU128,
  Not,
  Abs,
  Minus,
  Defined,
  Exp,
  Log,
  Log10,
  Sqrt,
  Sq,
  Ceil,
  Floor,
  Round,
  Cos,
  Sin,
  Tan,
  ACos,
  ASin,
  ATan,
  CosH,
  SinH,
  TanH,
  Hash,
  BeginOfRange,
  EndOfRange,
  Sparkline,
  Strptime,
  Variant,
  Chr,
  Like,
  Fit,
  CountryCode,
  IpFamily,
  Basename,
};

inline std::ostream &operator<<(std::ostream &os, t55f3c32df481113125a05cab83e4d003 const &v) {
  switch (v.index()) {
    case 0: os << "Age " << std::get<0>(v); break;
    case 1: os << "Cast " << ::dessser::gen::raql_type::Deref(std::get<1>(v)); break;
    case 2: os << "Force " << std::get<2>(v); break;
    case 3: os << "Peek " << std::get<3>(v); break;
    case 4: os << "Length " << std::get<4>(v); break;
    case 5: os << "Lower " << std::get<5>(v); break;
    case 6: os << "Upper " << std::get<6>(v); break;
    case 7: os << "UuidOfU128 " << std::get<7>(v); break;
    case 8: os << "Not " << std::get<8>(v); break;
    case 9: os << "Abs " << std::get<9>(v); break;
    case 10: os << "Minus " << std::get<10>(v); break;
    case 11: os << "Defined " << std::get<11>(v); break;
    case 12: os << "Exp " << std::get<12>(v); break;
    case 13: os << "Log " << std::get<13>(v); break;
    case 14: os << "Log10 " << std::get<14>(v); break;
    case 15: os << "Sqrt " << std::get<15>(v); break;
    case 16: os << "Sq " << std::get<16>(v); break;
    case 17: os << "Ceil " << std::get<17>(v); break;
    case 18: os << "Floor " << std::get<18>(v); break;
    case 19: os << "Round " << std::get<19>(v); break;
    case 20: os << "Cos " << std::get<20>(v); break;
    case 21: os << "Sin " << std::get<21>(v); break;
    case 22: os << "Tan " << std::get<22>(v); break;
    case 23: os << "ACos " << std::get<23>(v); break;
    case 24: os << "ASin " << std::get<24>(v); break;
    case 25: os << "ATan " << std::get<25>(v); break;
    case 26: os << "CosH " << std::get<26>(v); break;
    case 27: os << "SinH " << std::get<27>(v); break;
    case 28: os << "TanH " << std::get<28>(v); break;
    case 29: os << "Hash " << std::get<29>(v); break;
    case 30: os << "BeginOfRange " << std::get<30>(v); break;
    case 31: os << "EndOfRange " << std::get<31>(v); break;
    case 32: os << "Sparkline " << std::get<32>(v); break;
    case 33: os << "Strptime " << std::get<33>(v); break;
    case 34: os << "Variant " << std::get<34>(v); break;
    case 35: os << "Chr " << std::get<35>(v); break;
    case 36: os << "Like " << std::get<36>(v); break;
    case 37: os << "Fit " << std::get<37>(v); break;
    case 38: os << "CountryCode " << std::get<38>(v); break;
    case 39: os << "IpFamily " << std::get<39>(v); break;
    case 40: os << "Basename " << std::get<40>(v); break;
  }
  return os;
}

inline bool operator==(t55f3c32df481113125a05cab83e4d003 const &a, t55f3c32df481113125a05cab83e4d003 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Age
    case 1: return ::dessser::gen::raql_type::Deref(std::get<1>(a)) == ::dessser::gen::raql_type::Deref(std::get<1>(b)); // Cast
    case 2: return std::get<2>(a) == std::get<2>(b); // Force
    case 3: return std::get<3>(a) == std::get<3>(b); // Peek
    case 4: return std::get<4>(a) == std::get<4>(b); // Length
    case 5: return std::get<5>(a) == std::get<5>(b); // Lower
    case 6: return std::get<6>(a) == std::get<6>(b); // Upper
    case 7: return std::get<7>(a) == std::get<7>(b); // UuidOfU128
    case 8: return std::get<8>(a) == std::get<8>(b); // Not
    case 9: return std::get<9>(a) == std::get<9>(b); // Abs
    case 10: return std::get<10>(a) == std::get<10>(b); // Minus
    case 11: return std::get<11>(a) == std::get<11>(b); // Defined
    case 12: return std::get<12>(a) == std::get<12>(b); // Exp
    case 13: return std::get<13>(a) == std::get<13>(b); // Log
    case 14: return std::get<14>(a) == std::get<14>(b); // Log10
    case 15: return std::get<15>(a) == std::get<15>(b); // Sqrt
    case 16: return std::get<16>(a) == std::get<16>(b); // Sq
    case 17: return std::get<17>(a) == std::get<17>(b); // Ceil
    case 18: return std::get<18>(a) == std::get<18>(b); // Floor
    case 19: return std::get<19>(a) == std::get<19>(b); // Round
    case 20: return std::get<20>(a) == std::get<20>(b); // Cos
    case 21: return std::get<21>(a) == std::get<21>(b); // Sin
    case 22: return std::get<22>(a) == std::get<22>(b); // Tan
    case 23: return std::get<23>(a) == std::get<23>(b); // ACos
    case 24: return std::get<24>(a) == std::get<24>(b); // ASin
    case 25: return std::get<25>(a) == std::get<25>(b); // ATan
    case 26: return std::get<26>(a) == std::get<26>(b); // CosH
    case 27: return std::get<27>(a) == std::get<27>(b); // SinH
    case 28: return std::get<28>(a) == std::get<28>(b); // TanH
    case 29: return std::get<29>(a) == std::get<29>(b); // Hash
    case 30: return std::get<30>(a) == std::get<30>(b); // BeginOfRange
    case 31: return std::get<31>(a) == std::get<31>(b); // EndOfRange
    case 32: return std::get<32>(a) == std::get<32>(b); // Sparkline
    case 33: return std::get<33>(a) == std::get<33>(b); // Strptime
    case 34: return std::get<34>(a) == std::get<34>(b); // Variant
    case 35: return std::get<35>(a) == std::get<35>(b); // Chr
    case 36: return std::get<36>(a) == std::get<36>(b); // Like
    case 37: return std::get<37>(a) == std::get<37>(b); // Fit
    case 38: return std::get<38>(a) == std::get<38>(b); // CountryCode
    case 39: return std::get<39>(a) == std::get<39>(b); // IpFamily
    case 40: return std::get<40>(a) == std::get<40>(b); // Basename
  };
  return false;
}
inline bool operator!=(t55f3c32df481113125a05cab83e4d003 const &a, t55f3c32df481113125a05cab83e4d003 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t317de84c4263132c81b0c1329184a44e : public std::tuple<
  ::dessser::gen::raql_expr::t55f3c32df481113125a05cab83e4d003,
  t*
> {
  using tuple::tuple;
  t317de84c4263132c81b0c1329184a44e(std::tuple<::dessser::gen::raql_expr::t55f3c32df481113125a05cab83e4d003, t*> p)
    : std::tuple<::dessser::gen::raql_expr::t55f3c32df481113125a05cab83e4d003, t*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t317de84c4263132c81b0c1329184a44e const &a, t317de84c4263132c81b0c1329184a44e const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t317de84c4263132c81b0c1329184a44e const &a, t317de84c4263132c81b0c1329184a44e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t317de84c4263132c81b0c1329184a44e const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t)
     << '>';
  return os;
}

struct t0714e951accff7f9c7ebbbf55cde5e2d : public std::variant<
  Void, // Max
  Void, // Min
  Void, // Print
  Void // Coalesce
> { using variant::variant; };

enum Constr_t0714e951accff7f9c7ebbbf55cde5e2d {
  Max,
  Min,
  Print,
  Coalesce,
};

inline std::ostream &operator<<(std::ostream &os, t0714e951accff7f9c7ebbbf55cde5e2d const &v) {
  switch (v.index()) {
    case 0: os << "Max " << std::get<0>(v); break;
    case 1: os << "Min " << std::get<1>(v); break;
    case 2: os << "Print " << std::get<2>(v); break;
    case 3: os << "Coalesce " << std::get<3>(v); break;
  }
  return os;
}

inline bool operator==(t0714e951accff7f9c7ebbbf55cde5e2d const &a, t0714e951accff7f9c7ebbbf55cde5e2d const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Max
    case 1: return std::get<1>(a) == std::get<1>(b); // Min
    case 2: return std::get<2>(a) == std::get<2>(b); // Print
    case 3: return std::get<3>(a) == std::get<3>(b); // Coalesce
  };
  return false;
}
inline bool operator!=(t0714e951accff7f9c7ebbbf55cde5e2d const &a, t0714e951accff7f9c7ebbbf55cde5e2d const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tc1369d4853f822ab78c808b3836300ae : public std::tuple<
  ::dessser::gen::raql_expr::t0714e951accff7f9c7ebbbf55cde5e2d,
  Lst<t*>
> {
  using tuple::tuple;
  tc1369d4853f822ab78c808b3836300ae(std::tuple<::dessser::gen::raql_expr::t0714e951accff7f9c7ebbbf55cde5e2d, Lst<t*>> p)
    : std::tuple<::dessser::gen::raql_expr::t0714e951accff7f9c7ebbbf55cde5e2d, Lst<t*>>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc1369d4853f822ab78c808b3836300ae const &a, tc1369d4853f822ab78c808b3836300ae const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc1369d4853f822ab78c808b3836300ae const &a, tc1369d4853f822ab78c808b3836300ae const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc1369d4853f822ab78c808b3836300ae const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t58dafdea9146e1796e71a181a3397bec : public std::variant<
  Void, // Add
  Void, // Sub
  Void, // Mul
  Void, // Div
  Void, // IDiv
  Void, // Mod
  Void, // Pow
  Void, // Trunc
  Void, // Reldiff
  Void, // And
  Void, // Or
  Void, // Ge
  Void, // Gt
  Void, // Eq
  Void, // Concat
  Void, // StartsWith
  Void, // EndsWith
  Void, // BitAnd
  Void, // BitOr
  Void, // BitXor
  Void, // BitShift
  Void, // Get
  Void, // In
  Void, // Strftime
  Void, // Index
  Void // Percentile
> { using variant::variant; };

enum Constr_t58dafdea9146e1796e71a181a3397bec {
  Add,
  Sub,
  Mul,
  Div,
  IDiv,
  Mod,
  Pow,
  Trunc,
  Reldiff,
  And,
  Or,
  Ge,
  Gt,
  Eq,
  Concat,
  StartsWith,
  EndsWith,
  BitAnd,
  BitOr,
  BitXor,
  BitShift,
  Get,
  In,
  Strftime,
  Index,
  Percentile,
};

inline std::ostream &operator<<(std::ostream &os, t58dafdea9146e1796e71a181a3397bec const &v) {
  switch (v.index()) {
    case 0: os << "Add " << std::get<0>(v); break;
    case 1: os << "Sub " << std::get<1>(v); break;
    case 2: os << "Mul " << std::get<2>(v); break;
    case 3: os << "Div " << std::get<3>(v); break;
    case 4: os << "IDiv " << std::get<4>(v); break;
    case 5: os << "Mod " << std::get<5>(v); break;
    case 6: os << "Pow " << std::get<6>(v); break;
    case 7: os << "Trunc " << std::get<7>(v); break;
    case 8: os << "Reldiff " << std::get<8>(v); break;
    case 9: os << "And " << std::get<9>(v); break;
    case 10: os << "Or " << std::get<10>(v); break;
    case 11: os << "Ge " << std::get<11>(v); break;
    case 12: os << "Gt " << std::get<12>(v); break;
    case 13: os << "Eq " << std::get<13>(v); break;
    case 14: os << "Concat " << std::get<14>(v); break;
    case 15: os << "StartsWith " << std::get<15>(v); break;
    case 16: os << "EndsWith " << std::get<16>(v); break;
    case 17: os << "BitAnd " << std::get<17>(v); break;
    case 18: os << "BitOr " << std::get<18>(v); break;
    case 19: os << "BitXor " << std::get<19>(v); break;
    case 20: os << "BitShift " << std::get<20>(v); break;
    case 21: os << "Get " << std::get<21>(v); break;
    case 22: os << "In " << std::get<22>(v); break;
    case 23: os << "Strftime " << std::get<23>(v); break;
    case 24: os << "Index " << std::get<24>(v); break;
    case 25: os << "Percentile " << std::get<25>(v); break;
  }
  return os;
}

inline bool operator==(t58dafdea9146e1796e71a181a3397bec const &a, t58dafdea9146e1796e71a181a3397bec const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Add
    case 1: return std::get<1>(a) == std::get<1>(b); // Sub
    case 2: return std::get<2>(a) == std::get<2>(b); // Mul
    case 3: return std::get<3>(a) == std::get<3>(b); // Div
    case 4: return std::get<4>(a) == std::get<4>(b); // IDiv
    case 5: return std::get<5>(a) == std::get<5>(b); // Mod
    case 6: return std::get<6>(a) == std::get<6>(b); // Pow
    case 7: return std::get<7>(a) == std::get<7>(b); // Trunc
    case 8: return std::get<8>(a) == std::get<8>(b); // Reldiff
    case 9: return std::get<9>(a) == std::get<9>(b); // And
    case 10: return std::get<10>(a) == std::get<10>(b); // Or
    case 11: return std::get<11>(a) == std::get<11>(b); // Ge
    case 12: return std::get<12>(a) == std::get<12>(b); // Gt
    case 13: return std::get<13>(a) == std::get<13>(b); // Eq
    case 14: return std::get<14>(a) == std::get<14>(b); // Concat
    case 15: return std::get<15>(a) == std::get<15>(b); // StartsWith
    case 16: return std::get<16>(a) == std::get<16>(b); // EndsWith
    case 17: return std::get<17>(a) == std::get<17>(b); // BitAnd
    case 18: return std::get<18>(a) == std::get<18>(b); // BitOr
    case 19: return std::get<19>(a) == std::get<19>(b); // BitXor
    case 20: return std::get<20>(a) == std::get<20>(b); // BitShift
    case 21: return std::get<21>(a) == std::get<21>(b); // Get
    case 22: return std::get<22>(a) == std::get<22>(b); // In
    case 23: return std::get<23>(a) == std::get<23>(b); // Strftime
    case 24: return std::get<24>(a) == std::get<24>(b); // Index
    case 25: return std::get<25>(a) == std::get<25>(b); // Percentile
  };
  return false;
}
inline bool operator!=(t58dafdea9146e1796e71a181a3397bec const &a, t58dafdea9146e1796e71a181a3397bec const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t1449747958ef85e652b082157a6cdb3f : public std::tuple<
  ::dessser::gen::raql_expr::t58dafdea9146e1796e71a181a3397bec,
  t*,
  t*
> {
  using tuple::tuple;
};
inline bool operator==(t1449747958ef85e652b082157a6cdb3f const &a, t1449747958ef85e652b082157a6cdb3f const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b));
}
inline bool operator!=(t1449747958ef85e652b082157a6cdb3f const &a, t1449747958ef85e652b082157a6cdb3f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t1449747958ef85e652b082157a6cdb3f const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t) << ", "
     << *std::get<2>(t)
     << '>';
  return os;
}

struct t29b2bb83c49c2dd7652b8b5187b1f015 : public std::variant<
  Void, // SubString
  Void // MapSet
> { using variant::variant; };

enum Constr_t29b2bb83c49c2dd7652b8b5187b1f015 {
  SubString,
  MapSet,
};

inline std::ostream &operator<<(std::ostream &os, t29b2bb83c49c2dd7652b8b5187b1f015 const &v) {
  switch (v.index()) {
    case 0: os << "SubString " << std::get<0>(v); break;
    case 1: os << "MapSet " << std::get<1>(v); break;
  }
  return os;
}

inline bool operator==(t29b2bb83c49c2dd7652b8b5187b1f015 const &a, t29b2bb83c49c2dd7652b8b5187b1f015 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // SubString
    case 1: return std::get<1>(a) == std::get<1>(b); // MapSet
  };
  return false;
}
inline bool operator!=(t29b2bb83c49c2dd7652b8b5187b1f015 const &a, t29b2bb83c49c2dd7652b8b5187b1f015 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t11f260516b98fafae85b63c599a34c8b : public std::tuple<
  ::dessser::gen::raql_expr::t29b2bb83c49c2dd7652b8b5187b1f015,
  t*,
  t*,
  t*
> {
  using tuple::tuple;
};
inline bool operator==(t11f260516b98fafae85b63c599a34c8b const &a, t11f260516b98fafae85b63c599a34c8b const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b));
}
inline bool operator!=(t11f260516b98fafae85b63c599a34c8b const &a, t11f260516b98fafae85b63c599a34c8b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t11f260516b98fafae85b63c599a34c8b const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t) << ", "
     << *std::get<2>(t) << ", "
     << *std::get<3>(t)
     << '>';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t74bec7fc82b0955e5415aed5697bdf75 : public std::variant<
  ::dessser::gen::raql_expr::tf7ae7db1c515d769014dcb9b31531498, // SL0
  ::dessser::gen::raql_expr::t317de84c4263132c81b0c1329184a44e, // SL1
  ::dessser::gen::raql_expr::tc1369d4853f822ab78c808b3836300ae, // SL1s
  ::dessser::gen::raql_expr::t1449747958ef85e652b082157a6cdb3f, // SL2
  ::dessser::gen::raql_expr::t11f260516b98fafae85b63c599a34c8b // SL3
> { using variant::variant; };

enum Constr_t74bec7fc82b0955e5415aed5697bdf75 {
  SL0,
  SL1,
  SL1s,
  SL2,
  SL3,
};

inline std::ostream &operator<<(std::ostream &os, t74bec7fc82b0955e5415aed5697bdf75 const &v) {
  switch (v.index()) {
    case 0: os << "SL0 " << std::get<0>(v); break;
    case 1: os << "SL1 " << std::get<1>(v); break;
    case 2: os << "SL1s " << std::get<2>(v); break;
    case 3: os << "SL2 " << std::get<3>(v); break;
    case 4: os << "SL3 " << std::get<4>(v); break;
  }
  return os;
}

inline bool operator==(t74bec7fc82b0955e5415aed5697bdf75 const &a, t74bec7fc82b0955e5415aed5697bdf75 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // SL0
    case 1: return std::get<1>(a) == std::get<1>(b); // SL1
    case 2: return std::get<2>(a) == std::get<2>(b); // SL1s
    case 3: return std::get<3>(a) == std::get<3>(b); // SL2
    case 4: return std::get<4>(a) == std::get<4>(b); // SL3
  };
  return false;
}
inline bool operator!=(t74bec7fc82b0955e5415aed5697bdf75 const &a, t74bec7fc82b0955e5415aed5697bdf75 const &b) {
  return !operator==(a, b);
}
struct t9aeb08fceb6eb1d5796a64c8fddd436c : public std::variant<
  Void, // LocalState
  Void // GlobalState
> { using variant::variant; };

enum Constr_t9aeb08fceb6eb1d5796a64c8fddd436c {
  LocalState,
  GlobalState,
};

inline std::ostream &operator<<(std::ostream &os, t9aeb08fceb6eb1d5796a64c8fddd436c const &v) {
  switch (v.index()) {
    case 0: os << "LocalState " << std::get<0>(v); break;
    case 1: os << "GlobalState " << std::get<1>(v); break;
  }
  return os;
}

inline bool operator==(t9aeb08fceb6eb1d5796a64c8fddd436c const &a, t9aeb08fceb6eb1d5796a64c8fddd436c const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // LocalState
    case 1: return std::get<1>(a) == std::get<1>(b); // GlobalState
  };
  return false;
}
inline bool operator!=(t9aeb08fceb6eb1d5796a64c8fddd436c const &a, t9aeb08fceb6eb1d5796a64c8fddd436c const &b) {
  return !operator==(a, b);
}
struct tc1c4317cb65c5b1b0f16657e46216582 : public std::tuple<
  double,
  double,
  uint32_t
> {
  using tuple::tuple;
};
inline bool operator==(tc1c4317cb65c5b1b0f16657e46216582 const &a, tc1c4317cb65c5b1b0f16657e46216582 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(tc1c4317cb65c5b1b0f16657e46216582 const &a, tc1c4317cb65c5b1b0f16657e46216582 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc1c4317cb65c5b1b0f16657e46216582 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t82fe136ba20c37a9f3853622f9acef6d : public std::variant<
  Void, // AggrMin
  Void, // AggrMax
  Void, // AggrSum
  Void, // AggrAvg
  Void, // AggrAnd
  Void, // AggrOr
  Void, // AggrBitAnd
  Void, // AggrBitOr
  Void, // AggrBitXor
  Void, // AggrFirst
  Void, // AggrLast
  ::dessser::gen::raql_expr::tc1c4317cb65c5b1b0f16657e46216582, // AggrHistogram
  Void, // Group
  Void, // Count
  Void // Distinct
> { using variant::variant; };

enum Constr_t82fe136ba20c37a9f3853622f9acef6d {
  AggrMin,
  AggrMax,
  AggrSum,
  AggrAvg,
  AggrAnd,
  AggrOr,
  AggrBitAnd,
  AggrBitOr,
  AggrBitXor,
  AggrFirst,
  AggrLast,
  AggrHistogram,
  Group,
  Count,
  Distinct,
};

inline std::ostream &operator<<(std::ostream &os, t82fe136ba20c37a9f3853622f9acef6d const &v) {
  switch (v.index()) {
    case 0: os << "AggrMin " << std::get<0>(v); break;
    case 1: os << "AggrMax " << std::get<1>(v); break;
    case 2: os << "AggrSum " << std::get<2>(v); break;
    case 3: os << "AggrAvg " << std::get<3>(v); break;
    case 4: os << "AggrAnd " << std::get<4>(v); break;
    case 5: os << "AggrOr " << std::get<5>(v); break;
    case 6: os << "AggrBitAnd " << std::get<6>(v); break;
    case 7: os << "AggrBitOr " << std::get<7>(v); break;
    case 8: os << "AggrBitXor " << std::get<8>(v); break;
    case 9: os << "AggrFirst " << std::get<9>(v); break;
    case 10: os << "AggrLast " << std::get<10>(v); break;
    case 11: os << "AggrHistogram " << std::get<11>(v); break;
    case 12: os << "Group " << std::get<12>(v); break;
    case 13: os << "Count " << std::get<13>(v); break;
    case 14: os << "Distinct " << std::get<14>(v); break;
  }
  return os;
}

inline bool operator==(t82fe136ba20c37a9f3853622f9acef6d const &a, t82fe136ba20c37a9f3853622f9acef6d const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // AggrMin
    case 1: return std::get<1>(a) == std::get<1>(b); // AggrMax
    case 2: return std::get<2>(a) == std::get<2>(b); // AggrSum
    case 3: return std::get<3>(a) == std::get<3>(b); // AggrAvg
    case 4: return std::get<4>(a) == std::get<4>(b); // AggrAnd
    case 5: return std::get<5>(a) == std::get<5>(b); // AggrOr
    case 6: return std::get<6>(a) == std::get<6>(b); // AggrBitAnd
    case 7: return std::get<7>(a) == std::get<7>(b); // AggrBitOr
    case 8: return std::get<8>(a) == std::get<8>(b); // AggrBitXor
    case 9: return std::get<9>(a) == std::get<9>(b); // AggrFirst
    case 10: return std::get<10>(a) == std::get<10>(b); // AggrLast
    case 11: return std::get<11>(a) == std::get<11>(b); // AggrHistogram
    case 12: return std::get<12>(a) == std::get<12>(b); // Group
    case 13: return std::get<13>(a) == std::get<13>(b); // Count
    case 14: return std::get<14>(a) == std::get<14>(b); // Distinct
  };
  return false;
}
inline bool operator!=(t82fe136ba20c37a9f3853622f9acef6d const &a, t82fe136ba20c37a9f3853622f9acef6d const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tb2d8dbe6ccfb536023cbb663cf40a704 : public std::tuple<
  ::dessser::gen::raql_expr::t82fe136ba20c37a9f3853622f9acef6d,
  t*
> {
  using tuple::tuple;
  tb2d8dbe6ccfb536023cbb663cf40a704(std::tuple<::dessser::gen::raql_expr::t82fe136ba20c37a9f3853622f9acef6d, t*> p)
    : std::tuple<::dessser::gen::raql_expr::t82fe136ba20c37a9f3853622f9acef6d, t*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb2d8dbe6ccfb536023cbb663cf40a704 const &a, tb2d8dbe6ccfb536023cbb663cf40a704 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(tb2d8dbe6ccfb536023cbb663cf40a704 const &a, tb2d8dbe6ccfb536023cbb663cf40a704 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb2d8dbe6ccfb536023cbb663cf40a704 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t)
     << '>';
  return os;
}

struct ta7ffb229534f504804e1c24f742166d6 : public std::variant<
  Void, // Lag
  Void, // ExpSmooth
  Void, // Sample
  Void // OneOutOf
> { using variant::variant; };

enum Constr_ta7ffb229534f504804e1c24f742166d6 {
  Lag,
  ExpSmooth,
  Sample,
  OneOutOf,
};

inline std::ostream &operator<<(std::ostream &os, ta7ffb229534f504804e1c24f742166d6 const &v) {
  switch (v.index()) {
    case 0: os << "Lag " << std::get<0>(v); break;
    case 1: os << "ExpSmooth " << std::get<1>(v); break;
    case 2: os << "Sample " << std::get<2>(v); break;
    case 3: os << "OneOutOf " << std::get<3>(v); break;
  }
  return os;
}

inline bool operator==(ta7ffb229534f504804e1c24f742166d6 const &a, ta7ffb229534f504804e1c24f742166d6 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Lag
    case 1: return std::get<1>(a) == std::get<1>(b); // ExpSmooth
    case 2: return std::get<2>(a) == std::get<2>(b); // Sample
    case 3: return std::get<3>(a) == std::get<3>(b); // OneOutOf
  };
  return false;
}
inline bool operator!=(ta7ffb229534f504804e1c24f742166d6 const &a, ta7ffb229534f504804e1c24f742166d6 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t6ca11fcc3293480822dee749868fd0f3 : public std::tuple<
  ::dessser::gen::raql_expr::ta7ffb229534f504804e1c24f742166d6,
  t*,
  t*
> {
  using tuple::tuple;
};
inline bool operator==(t6ca11fcc3293480822dee749868fd0f3 const &a, t6ca11fcc3293480822dee749868fd0f3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b));
}
inline bool operator!=(t6ca11fcc3293480822dee749868fd0f3 const &a, t6ca11fcc3293480822dee749868fd0f3 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t6ca11fcc3293480822dee749868fd0f3 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t) << ", "
     << *std::get<2>(t)
     << '>';
  return os;
}

struct t213fd001439b7e9763630d054b30bb45 : public std::variant<
  Void, // MovingAvg
  Void, // Hysteresis
  bool // OnceEvery
> { using variant::variant; };

enum Constr_t213fd001439b7e9763630d054b30bb45 {
  MovingAvg,
  Hysteresis,
  OnceEvery,
};

inline std::ostream &operator<<(std::ostream &os, t213fd001439b7e9763630d054b30bb45 const &v) {
  switch (v.index()) {
    case 0: os << "MovingAvg " << std::get<0>(v); break;
    case 1: os << "Hysteresis " << std::get<1>(v); break;
    case 2: os << "OnceEvery " << std::get<2>(v); break;
  }
  return os;
}

inline bool operator==(t213fd001439b7e9763630d054b30bb45 const &a, t213fd001439b7e9763630d054b30bb45 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // MovingAvg
    case 1: return std::get<1>(a) == std::get<1>(b); // Hysteresis
    case 2: return std::get<2>(a) == std::get<2>(b); // OnceEvery
  };
  return false;
}
inline bool operator!=(t213fd001439b7e9763630d054b30bb45 const &a, t213fd001439b7e9763630d054b30bb45 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tb5f0bb83ac029015b6b4ee8cd11bbc9e : public std::tuple<
  ::dessser::gen::raql_expr::t213fd001439b7e9763630d054b30bb45,
  t*,
  t*,
  t*
> {
  using tuple::tuple;
};
inline bool operator==(tb5f0bb83ac029015b6b4ee8cd11bbc9e const &a, tb5f0bb83ac029015b6b4ee8cd11bbc9e const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b));
}
inline bool operator!=(tb5f0bb83ac029015b6b4ee8cd11bbc9e const &a, tb5f0bb83ac029015b6b4ee8cd11bbc9e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb5f0bb83ac029015b6b4ee8cd11bbc9e const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t) << ", "
     << *std::get<2>(t) << ", "
     << *std::get<3>(t)
     << '>';
  return os;
}

struct t2e68ed7bcde629b79efcf8cb23da3dd3 : public std::variant<
  Void, // DampedHolt
  bool // Remember
> { using variant::variant; };

enum Constr_t2e68ed7bcde629b79efcf8cb23da3dd3 {
  DampedHolt,
  Remember,
};

inline std::ostream &operator<<(std::ostream &os, t2e68ed7bcde629b79efcf8cb23da3dd3 const &v) {
  switch (v.index()) {
    case 0: os << "DampedHolt " << std::get<0>(v); break;
    case 1: os << "Remember " << std::get<1>(v); break;
  }
  return os;
}

inline bool operator==(t2e68ed7bcde629b79efcf8cb23da3dd3 const &a, t2e68ed7bcde629b79efcf8cb23da3dd3 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // DampedHolt
    case 1: return std::get<1>(a) == std::get<1>(b); // Remember
  };
  return false;
}
inline bool operator!=(t2e68ed7bcde629b79efcf8cb23da3dd3 const &a, t2e68ed7bcde629b79efcf8cb23da3dd3 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tbbe1592e503b04515498e1841d4ef53f : public std::tuple<
  ::dessser::gen::raql_expr::t2e68ed7bcde629b79efcf8cb23da3dd3,
  t*,
  t*,
  t*,
  t*
> {
  using tuple::tuple;
};
inline bool operator==(tbbe1592e503b04515498e1841d4ef53f const &a, tbbe1592e503b04515498e1841d4ef53f const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b)) && (*std::get<4>(a)) == (*std::get<4>(b));
}
inline bool operator!=(tbbe1592e503b04515498e1841d4ef53f const &a, tbbe1592e503b04515498e1841d4ef53f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tbbe1592e503b04515498e1841d4ef53f const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t) << ", "
     << *std::get<2>(t) << ", "
     << *std::get<3>(t) << ", "
     << *std::get<4>(t)
     << '>';
  return os;
}

struct t544d24ae3e0dea30c1a68be6bcde1392 {
  bool inv;
  bool up_to;
  t544d24ae3e0dea30c1a68be6bcde1392(bool inv_, bool up_to_) : inv(inv_), up_to(up_to_) {}
  t544d24ae3e0dea30c1a68be6bcde1392() = default;
};
inline std::ostream &operator<<(std::ostream &os, t544d24ae3e0dea30c1a68be6bcde1392 const &r) {
  os << '{';
  os << "inv:" << r.inv << ',';
  os << "up_to:" << r.up_to;
  os << '}';
  return os;
}
inline bool operator==(t544d24ae3e0dea30c1a68be6bcde1392 const &a, t544d24ae3e0dea30c1a68be6bcde1392 const &b) {
  return a.inv == b.inv && a.up_to == b.up_to;
}

inline bool operator!=(t544d24ae3e0dea30c1a68be6bcde1392 const &a, t544d24ae3e0dea30c1a68be6bcde1392 const &b) {
  return !operator==(a, b);
}
struct t7f41e7341759d79e67af6acb8e5b5a38 : public std::variant<
  Void, // MultiLinReg
  ::dessser::gen::raql_expr::t544d24ae3e0dea30c1a68be6bcde1392 // Largest
> { using variant::variant; };

enum Constr_t7f41e7341759d79e67af6acb8e5b5a38 {
  MultiLinReg,
  Largest,
};

inline std::ostream &operator<<(std::ostream &os, t7f41e7341759d79e67af6acb8e5b5a38 const &v) {
  switch (v.index()) {
    case 0: os << "MultiLinReg " << std::get<0>(v); break;
    case 1: os << "Largest " << std::get<1>(v); break;
  }
  return os;
}

inline bool operator==(t7f41e7341759d79e67af6acb8e5b5a38 const &a, t7f41e7341759d79e67af6acb8e5b5a38 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // MultiLinReg
    case 1: return std::get<1>(a) == std::get<1>(b); // Largest
  };
  return false;
}
inline bool operator!=(t7f41e7341759d79e67af6acb8e5b5a38 const &a, t7f41e7341759d79e67af6acb8e5b5a38 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t70c931bd7b4850d7fd1d2f0b15785f7c : public std::tuple<
  ::dessser::gen::raql_expr::t7f41e7341759d79e67af6acb8e5b5a38,
  t*,
  t*,
  t*,
  Lst<t*>
> {
  using tuple::tuple;
};
inline bool operator==(t70c931bd7b4850d7fd1d2f0b15785f7c const &a, t70c931bd7b4850d7fd1d2f0b15785f7c const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b)) && std::get<4>(a) == std::get<4>(b);
}
inline bool operator!=(t70c931bd7b4850d7fd1d2f0b15785f7c const &a, t70c931bd7b4850d7fd1d2f0b15785f7c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t70c931bd7b4850d7fd1d2f0b15785f7c const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t) << ", "
     << *std::get<2>(t) << ", "
     << *std::get<3>(t) << ", "
     << std::get<4>(t)
     << '>';
  return os;
}

struct ta020e7823506dcf58037dc373380c189 : public std::variant<
  Void // DampedHoltWinter
> { using variant::variant; };

enum Constr_ta020e7823506dcf58037dc373380c189 {
  DampedHoltWinter,
};

inline std::ostream &operator<<(std::ostream &os, ta020e7823506dcf58037dc373380c189 const &v) {
  switch (v.index()) {
    case 0: os << "DampedHoltWinter " << std::get<0>(v); break;
  }
  return os;
}

inline bool operator==(ta020e7823506dcf58037dc373380c189 const &a, ta020e7823506dcf58037dc373380c189 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // DampedHoltWinter
  };
  return false;
}
inline bool operator!=(ta020e7823506dcf58037dc373380c189 const &a, ta020e7823506dcf58037dc373380c189 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct te6925d16e5bcfe16da1b529df8649844 : public std::tuple<
  ::dessser::gen::raql_expr::ta020e7823506dcf58037dc373380c189,
  t*,
  t*,
  t*,
  t*,
  t*,
  t*
> {
  using tuple::tuple;
};
inline bool operator==(te6925d16e5bcfe16da1b529df8649844 const &a, te6925d16e5bcfe16da1b529df8649844 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b)) && (*std::get<4>(a)) == (*std::get<4>(b)) && (*std::get<5>(a)) == (*std::get<5>(b)) && (*std::get<6>(a)) == (*std::get<6>(b));
}
inline bool operator!=(te6925d16e5bcfe16da1b529df8649844 const &a, te6925d16e5bcfe16da1b529df8649844 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te6925d16e5bcfe16da1b529df8649844 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t) << ", "
     << *std::get<2>(t) << ", "
     << *std::get<3>(t) << ", "
     << *std::get<4>(t) << ", "
     << *std::get<5>(t) << ", "
     << *std::get<6>(t)
     << '>';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t779c3e3eae2a4b246fb5314d03e1dcac {
  t* by;
  t* duration;
  std::optional<t*> max_size;
  dessser::gen::raql_top_output::t_ext output;
  t* sigmas;
  t* size;
  t* Top_time;
  t* Top_what;
  t779c3e3eae2a4b246fb5314d03e1dcac(t* by_, t* duration_, std::optional<t*> max_size_, dessser::gen::raql_top_output::t_ext output_, t* sigmas_, t* size_, t* Top_time_, t* Top_what_) : by(by_), duration(duration_), max_size(max_size_), output(output_), sigmas(sigmas_), size(size_), Top_time(Top_time_), Top_what(Top_what_) {}
  t779c3e3eae2a4b246fb5314d03e1dcac() = default;
};
inline std::ostream &operator<<(std::ostream &os, t779c3e3eae2a4b246fb5314d03e1dcac const &r) {
  os << '{';
  os << "by:" << (*r.by) << ',';
  os << "duration:" << (*r.duration) << ',';
  if (r.max_size) os << "max_size:" << (*r.max_size.value()) << ',';
  os << "output:" << ::dessser::gen::raql_top_output::Deref(r.output) << ',';
  os << "sigmas:" << (*r.sigmas) << ',';
  os << "size:" << (*r.size) << ',';
  os << "Top_time:" << (*r.Top_time) << ',';
  os << "Top_what:" << (*r.Top_what);
  os << '}';
  return os;
}
inline bool operator==(t779c3e3eae2a4b246fb5314d03e1dcac const &a, t779c3e3eae2a4b246fb5314d03e1dcac const &b) {
  return (*a.by) == (*b.by) && (*a.duration) == (*b.duration) && ((a.max_size && b.max_size && (*a.max_size.value()) == (*b.max_size.value())) || (!a.max_size && !b.max_size)) && ::dessser::gen::raql_top_output::Deref(a.output) == ::dessser::gen::raql_top_output::Deref(b.output) && (*a.sigmas) == (*b.sigmas) && (*a.size) == (*b.size) && (*a.Top_time) == (*b.Top_time) && (*a.Top_what) == (*b.Top_what);
}

inline bool operator!=(t779c3e3eae2a4b246fb5314d03e1dcac const &a, t779c3e3eae2a4b246fb5314d03e1dcac const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tc56215e23eb52ef2b8bf1bb867c7e0a2 {
  t* max_age;
  std::optional<t*> sample_size;
  t* time;
  bool tumbling;
  t* what;
  tc56215e23eb52ef2b8bf1bb867c7e0a2(t* max_age_, std::optional<t*> sample_size_, t* time_, bool tumbling_, t* what_) : max_age(max_age_), sample_size(sample_size_), time(time_), tumbling(tumbling_), what(what_) {}
  tc56215e23eb52ef2b8bf1bb867c7e0a2() = default;
};
inline std::ostream &operator<<(std::ostream &os, tc56215e23eb52ef2b8bf1bb867c7e0a2 const &r) {
  os << '{';
  os << "max_age:" << (*r.max_age) << ',';
  if (r.sample_size) os << "sample_size:" << (*r.sample_size.value()) << ',';
  os << "time:" << (*r.time) << ',';
  os << "tumbling:" << r.tumbling << ',';
  os << "what:" << (*r.what);
  os << '}';
  return os;
}
inline bool operator==(tc56215e23eb52ef2b8bf1bb867c7e0a2 const &a, tc56215e23eb52ef2b8bf1bb867c7e0a2 const &b) {
  return (*a.max_age) == (*b.max_age) && ((a.sample_size && b.sample_size && (*a.sample_size.value()) == (*b.sample_size.value())) || (!a.sample_size && !b.sample_size)) && (*a.time) == (*b.time) && a.tumbling == b.tumbling && (*a.what) == (*b.what);
}

inline bool operator!=(tc56215e23eb52ef2b8bf1bb867c7e0a2 const &a, tc56215e23eb52ef2b8bf1bb867c7e0a2 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tbf52983c99e6494329934c4a28dcf071 : public std::variant<
  ::dessser::gen::raql_expr::tb2d8dbe6ccfb536023cbb663cf40a704, // SF1
  ::dessser::gen::raql_expr::t6ca11fcc3293480822dee749868fd0f3, // SF2
  ::dessser::gen::raql_expr::tb5f0bb83ac029015b6b4ee8cd11bbc9e, // SF3
  ::dessser::gen::raql_expr::tbbe1592e503b04515498e1841d4ef53f, // SF4
  ::dessser::gen::raql_expr::t70c931bd7b4850d7fd1d2f0b15785f7c, // SF4s
  ::dessser::gen::raql_expr::te6925d16e5bcfe16da1b529df8649844, // SF6
  ::dessser::gen::raql_expr::t779c3e3eae2a4b246fb5314d03e1dcac, // Top
  ::dessser::gen::raql_expr::tc56215e23eb52ef2b8bf1bb867c7e0a2 // Past
> { using variant::variant; };

enum Constr_tbf52983c99e6494329934c4a28dcf071 {
  SF1,
  SF2,
  SF3,
  SF4,
  SF4s,
  SF6,
  Top,
  Past,
};

inline std::ostream &operator<<(std::ostream &os, tbf52983c99e6494329934c4a28dcf071 const &v) {
  switch (v.index()) {
    case 0: os << "SF1 " << std::get<0>(v); break;
    case 1: os << "SF2 " << std::get<1>(v); break;
    case 2: os << "SF3 " << std::get<2>(v); break;
    case 3: os << "SF4 " << std::get<3>(v); break;
    case 4: os << "SF4s " << std::get<4>(v); break;
    case 5: os << "SF6 " << std::get<5>(v); break;
    case 6: os << "Top " << std::get<6>(v); break;
    case 7: os << "Past " << std::get<7>(v); break;
  }
  return os;
}

inline bool operator==(tbf52983c99e6494329934c4a28dcf071 const &a, tbf52983c99e6494329934c4a28dcf071 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // SF1
    case 1: return std::get<1>(a) == std::get<1>(b); // SF2
    case 2: return std::get<2>(a) == std::get<2>(b); // SF3
    case 3: return std::get<3>(a) == std::get<3>(b); // SF4
    case 4: return std::get<4>(a) == std::get<4>(b); // SF4s
    case 5: return std::get<5>(a) == std::get<5>(b); // SF6
    case 6: return std::get<6>(a) == std::get<6>(b); // Top
    case 7: return std::get<7>(a) == std::get<7>(b); // Past
  };
  return false;
}
inline bool operator!=(tbf52983c99e6494329934c4a28dcf071 const &a, tbf52983c99e6494329934c4a28dcf071 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t300ed380327f6325b25c9ea8678c67f9 : public std::tuple<
  ::dessser::gen::raql_expr::t9aeb08fceb6eb1d5796a64c8fddd436c,
  bool,
  ::dessser::gen::raql_expr::tbf52983c99e6494329934c4a28dcf071
> {
  using tuple::tuple;
};
inline bool operator==(t300ed380327f6325b25c9ea8678c67f9 const &a, t300ed380327f6325b25c9ea8678c67f9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t300ed380327f6325b25c9ea8678c67f9 const &a, t300ed380327f6325b25c9ea8678c67f9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t300ed380327f6325b25c9ea8678c67f9 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t904326184a165aa7b5c8e6ffafa090a8 : public std::tuple<
  t*,
  t*
> {
  using tuple::tuple;
  t904326184a165aa7b5c8e6ffafa090a8(std::tuple<t*, t*> p)
    : std::tuple<t*, t*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t904326184a165aa7b5c8e6ffafa090a8 const &a, t904326184a165aa7b5c8e6ffafa090a8 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t904326184a165aa7b5c8e6ffafa090a8 const &a, t904326184a165aa7b5c8e6ffafa090a8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t904326184a165aa7b5c8e6ffafa090a8 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << *std::get<1>(t)
     << '>';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tbcd1dc8722e46cce4ab285b33e4a2b47 : public std::variant<
  ::dessser::gen::raql_expr::t904326184a165aa7b5c8e6ffafa090a8 // Split
> { using variant::variant; };

enum Constr_tbcd1dc8722e46cce4ab285b33e4a2b47 {
  Split,
};

inline std::ostream &operator<<(std::ostream &os, tbcd1dc8722e46cce4ab285b33e4a2b47 const &v) {
  switch (v.index()) {
    case 0: os << "Split " << std::get<0>(v); break;
  }
  return os;
}

inline bool operator==(tbcd1dc8722e46cce4ab285b33e4a2b47 const &a, tbcd1dc8722e46cce4ab285b33e4a2b47 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Split
  };
  return false;
}
inline bool operator!=(tbcd1dc8722e46cce4ab285b33e4a2b47 const &a, tbcd1dc8722e46cce4ab285b33e4a2b47 const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t25167b1d73a9200430f74833c3ed0c2c : public std::variant<
  Lst<t*>, // Tuple
  Lst<::dessser::gen::raql_expr::tddfc646ae3827db7d4914729994bdbb1>, // Record
  Lst<t*>, // Vector
  ::dessser::gen::raql_expr::td73e40f734c89c38f2d6352e81bfc1af, // Case
  ::dessser::gen::raql_expr::t74bec7fc82b0955e5415aed5697bdf75, // Stateless
  ::dessser::gen::raql_expr::t300ed380327f6325b25c9ea8678c67f9, // Stateful
  ::dessser::gen::raql_expr::tbcd1dc8722e46cce4ab285b33e4a2b47 // Generator
> { using variant::variant; };

enum Constr_t25167b1d73a9200430f74833c3ed0c2c {
  Tuple,
  Record,
  Vector,
  Case,
  Stateless,
  Stateful,
  Generator,
};

inline std::ostream &operator<<(std::ostream &os, t25167b1d73a9200430f74833c3ed0c2c const &v) {
  switch (v.index()) {
    case 0: os << "Tuple " << std::get<0>(v); break;
    case 1: os << "Record " << std::get<1>(v); break;
    case 2: os << "Vector " << std::get<2>(v); break;
    case 3: os << "Case " << std::get<3>(v); break;
    case 4: os << "Stateless " << std::get<4>(v); break;
    case 5: os << "Stateful " << std::get<5>(v); break;
    case 6: os << "Generator " << std::get<6>(v); break;
  }
  return os;
}

inline bool operator==(t25167b1d73a9200430f74833c3ed0c2c const &a, t25167b1d73a9200430f74833c3ed0c2c const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Tuple
    case 1: return std::get<1>(a) == std::get<1>(b); // Record
    case 2: return std::get<2>(a) == std::get<2>(b); // Vector
    case 3: return std::get<3>(a) == std::get<3>(b); // Case
    case 4: return std::get<4>(a) == std::get<4>(b); // Stateless
    case 5: return std::get<5>(a) == std::get<5>(b); // Stateful
    case 6: return std::get<6>(a) == std::get<6>(b); // Generator
  };
  return false;
}
inline bool operator!=(t25167b1d73a9200430f74833c3ed0c2c const &a, t25167b1d73a9200430f74833c3ed0c2c const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t {
  ::dessser::gen::raql_expr::t25167b1d73a9200430f74833c3ed0c2c text;
  dessser::gen::raql_type::t_ext typ;
  uint32_t uniq_num;
  std::optional<dessser::gen::units::t_ext> units;
  t(::dessser::gen::raql_expr::t25167b1d73a9200430f74833c3ed0c2c text_, dessser::gen::raql_type::t_ext typ_, uint32_t uniq_num_, std::optional<dessser::gen::units::t_ext> units_) : text(text_), typ(typ_), uniq_num(uniq_num_), units(units_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "text:" << r.text << ',';
  os << "typ:" << ::dessser::gen::raql_type::Deref(r.typ) << ',';
  os << "uniq_num:" << r.uniq_num << ',';
  if (r.units) os << "units:" << ::dessser::gen::units::Deref(r.units.value());
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.text == b.text && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ) && a.uniq_num == b.uniq_num && ((a.units && b.units && ::dessser::gen::units::Deref(a.units.value()) == ::dessser::gen::units::Deref(b.units.value())) || (!a.units && !b.units));
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tb7593e4df5df7703a4ff8aa31f13df0d : public std::tuple<
  ::dessser::gen::raql_expr::t*,
  Pointer
> {
  using tuple::tuple;
  tb7593e4df5df7703a4ff8aa31f13df0d(std::tuple<::dessser::gen::raql_expr::t*, Pointer> p)
    : std::tuple<::dessser::gen::raql_expr::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb7593e4df5df7703a4ff8aa31f13df0d const &a, tb7593e4df5df7703a4ff8aa31f13df0d const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb7593e4df5df7703a4ff8aa31f13df0d const &a, tb7593e4df5df7703a4ff8aa31f13df0d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb7593e4df5df7703a4ff8aa31f13df0d const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_expr::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_expr::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_expr::tb7593e4df5df7703a4ff8aa31f13df0d(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
