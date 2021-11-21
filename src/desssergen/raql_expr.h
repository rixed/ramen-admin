#ifndef DESSSER_GEN_raql_expr
#define DESSSER_GEN_raql_expr
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t0027cfad262565398262cbf1e1df58d6 : public std::tuple<
  dessser::gen::field_name::t_ext,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
  t0027cfad262565398262cbf1e1df58d6(std::tuple<dessser::gen::field_name::t_ext, std::shared_ptr<::dessser::gen::raql_expr::t> > p)
    : std::tuple<dessser::gen::field_name::t_ext, std::shared_ptr<::dessser::gen::raql_expr::t> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0027cfad262565398262cbf1e1df58d6 const &a, t0027cfad262565398262cbf1e1df58d6 const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t0027cfad262565398262cbf1e1df58d6 const &a, t0027cfad262565398262cbf1e1df58d6 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t0027cfad262565398262cbf1e1df58d6 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0027cfad262565398262cbf1e1df58d6> const t) { os << *t; return os; }

struct t0afff8bac4fc9d0c4493b6dc4c3d250e {
  std::shared_ptr<::dessser::gen::raql_expr::t>  case_cond;
  std::shared_ptr<::dessser::gen::raql_expr::t>  case_cons;
  t0afff8bac4fc9d0c4493b6dc4c3d250e(std::shared_ptr<::dessser::gen::raql_expr::t>  case_cond_, std::shared_ptr<::dessser::gen::raql_expr::t>  case_cons_) : case_cond(case_cond_), case_cons(case_cons_) {}
  t0afff8bac4fc9d0c4493b6dc4c3d250e() = default;
};
inline std::ostream &operator<<(std::ostream &os, t0afff8bac4fc9d0c4493b6dc4c3d250e const &r) {
  os << '{';
  os << "case_cond:" << r.case_cond << ',';
  os << "case_cons:" << r.case_cons;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0afff8bac4fc9d0c4493b6dc4c3d250e> const r) { os << *r; return os; }

inline bool operator==(t0afff8bac4fc9d0c4493b6dc4c3d250e const &a, t0afff8bac4fc9d0c4493b6dc4c3d250e const &b) {
  return (*a.case_cond) == (*b.case_cond) && (*a.case_cons) == (*b.case_cons);
}

inline bool operator!=(t0afff8bac4fc9d0c4493b6dc4c3d250e const &a, t0afff8bac4fc9d0c4493b6dc4c3d250e const &b) {
  return !operator==(a, b);
}
struct t861242503efd004045f7f32d6f59fabc : public std::tuple<
  Lst<::dessser::gen::raql_expr::t0afff8bac4fc9d0c4493b6dc4c3d250e>,
  std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> >
> {
  using tuple::tuple;
  t861242503efd004045f7f32d6f59fabc(std::tuple<Lst<::dessser::gen::raql_expr::t0afff8bac4fc9d0c4493b6dc4c3d250e>, std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> >> p)
    : std::tuple<Lst<::dessser::gen::raql_expr::t0afff8bac4fc9d0c4493b6dc4c3d250e>, std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> >>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t861242503efd004045f7f32d6f59fabc const &a, t861242503efd004045f7f32d6f59fabc const &b) {
  return std::get<0>(a) == std::get<0>(b) && ((std::get<1>(a) && std::get<1>(b) && (*std::get<1>(a).value()) == (*std::get<1>(b).value())) || (!std::get<1>(a) && !std::get<1>(b)));
}
inline bool operator!=(t861242503efd004045f7f32d6f59fabc const &a, t861242503efd004045f7f32d6f59fabc const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t861242503efd004045f7f32d6f59fabc const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  if (std::get<1>(t)) os << std::get<1>(t).value();
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t861242503efd004045f7f32d6f59fabc> const t) { os << *t; return os; }

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
    case 0: os << "Const " << std::get<0>(v); break;
    case 1: os << "Variable " << std::get<1>(v); break;
    case 2: os << "Binding " << std::get<2>(v); break;
    case 3: os << "Now" << std::get<3>(v); break;
    case 4: os << "Random" << std::get<4>(v); break;
    case 5: os << "EventStart" << std::get<5>(v); break;
    case 6: os << "EventStop" << std::get<6>(v); break;
    case 7: os << "Path " << std::get<7>(v); break;
    case 8: os << "Pi" << std::get<8>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf7ae7db1c515d769014dcb9b31531498> const v) { os << *v; return os; }

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
    case 0: os << "LittleEndian" << std::get<0>(v); break;
    case 1: os << "BigEndian" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc847b6b1db0945d7ec695a4564143cf9> const v) { os << *v; return os; }

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
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te0e199631746ade8fdd411b7e499dc4a> const t) { os << *t; return os; }

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
    case 0: os << "Age" << std::get<0>(v); break;
    case 1: os << "Cast " << std::get<1>(v); break;
    case 2: os << "Force" << std::get<2>(v); break;
    case 3: os << "Peek " << std::get<3>(v); break;
    case 4: os << "Length" << std::get<4>(v); break;
    case 5: os << "Lower" << std::get<5>(v); break;
    case 6: os << "Upper" << std::get<6>(v); break;
    case 7: os << "UuidOfU128" << std::get<7>(v); break;
    case 8: os << "Not" << std::get<8>(v); break;
    case 9: os << "Abs" << std::get<9>(v); break;
    case 10: os << "Minus" << std::get<10>(v); break;
    case 11: os << "Defined" << std::get<11>(v); break;
    case 12: os << "Exp" << std::get<12>(v); break;
    case 13: os << "Log" << std::get<13>(v); break;
    case 14: os << "Log10" << std::get<14>(v); break;
    case 15: os << "Sqrt" << std::get<15>(v); break;
    case 16: os << "Sq" << std::get<16>(v); break;
    case 17: os << "Ceil" << std::get<17>(v); break;
    case 18: os << "Floor" << std::get<18>(v); break;
    case 19: os << "Round" << std::get<19>(v); break;
    case 20: os << "Cos" << std::get<20>(v); break;
    case 21: os << "Sin" << std::get<21>(v); break;
    case 22: os << "Tan" << std::get<22>(v); break;
    case 23: os << "ACos" << std::get<23>(v); break;
    case 24: os << "ASin" << std::get<24>(v); break;
    case 25: os << "ATan" << std::get<25>(v); break;
    case 26: os << "CosH" << std::get<26>(v); break;
    case 27: os << "SinH" << std::get<27>(v); break;
    case 28: os << "TanH" << std::get<28>(v); break;
    case 29: os << "Hash" << std::get<29>(v); break;
    case 30: os << "BeginOfRange" << std::get<30>(v); break;
    case 31: os << "EndOfRange" << std::get<31>(v); break;
    case 32: os << "Sparkline" << std::get<32>(v); break;
    case 33: os << "Strptime" << std::get<33>(v); break;
    case 34: os << "Variant" << std::get<34>(v); break;
    case 35: os << "Chr" << std::get<35>(v); break;
    case 36: os << "Like " << std::get<36>(v); break;
    case 37: os << "Fit" << std::get<37>(v); break;
    case 38: os << "CountryCode" << std::get<38>(v); break;
    case 39: os << "IpFamily" << std::get<39>(v); break;
    case 40: os << "Basename" << std::get<40>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t55f3c32df481113125a05cab83e4d003> const v) { os << *v; return os; }

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
struct t2bf9e3d0ef6db07b7c7d81f16499592f : public std::tuple<
  ::dessser::gen::raql_expr::t55f3c32df481113125a05cab83e4d003,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
  t2bf9e3d0ef6db07b7c7d81f16499592f(std::tuple<::dessser::gen::raql_expr::t55f3c32df481113125a05cab83e4d003, std::shared_ptr<::dessser::gen::raql_expr::t> > p)
    : std::tuple<::dessser::gen::raql_expr::t55f3c32df481113125a05cab83e4d003, std::shared_ptr<::dessser::gen::raql_expr::t> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2bf9e3d0ef6db07b7c7d81f16499592f const &a, t2bf9e3d0ef6db07b7c7d81f16499592f const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t2bf9e3d0ef6db07b7c7d81f16499592f const &a, t2bf9e3d0ef6db07b7c7d81f16499592f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t2bf9e3d0ef6db07b7c7d81f16499592f const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2bf9e3d0ef6db07b7c7d81f16499592f> const t) { os << *t; return os; }

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
    case 0: os << "Max" << std::get<0>(v); break;
    case 1: os << "Min" << std::get<1>(v); break;
    case 2: os << "Print" << std::get<2>(v); break;
    case 3: os << "Coalesce" << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0714e951accff7f9c7ebbbf55cde5e2d> const v) { os << *v; return os; }

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
struct teb665593199b3e0ba16be90af51adc52 : public std::tuple<
  ::dessser::gen::raql_expr::t0714e951accff7f9c7ebbbf55cde5e2d,
  Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >
> {
  using tuple::tuple;
  teb665593199b3e0ba16be90af51adc52(std::tuple<::dessser::gen::raql_expr::t0714e951accff7f9c7ebbbf55cde5e2d, Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >> p)
    : std::tuple<::dessser::gen::raql_expr::t0714e951accff7f9c7ebbbf55cde5e2d, Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(teb665593199b3e0ba16be90af51adc52 const &a, teb665593199b3e0ba16be90af51adc52 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(teb665593199b3e0ba16be90af51adc52 const &a, teb665593199b3e0ba16be90af51adc52 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, teb665593199b3e0ba16be90af51adc52 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<teb665593199b3e0ba16be90af51adc52> const t) { os << *t; return os; }

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
    case 0: os << "Add" << std::get<0>(v); break;
    case 1: os << "Sub" << std::get<1>(v); break;
    case 2: os << "Mul" << std::get<2>(v); break;
    case 3: os << "Div" << std::get<3>(v); break;
    case 4: os << "IDiv" << std::get<4>(v); break;
    case 5: os << "Mod" << std::get<5>(v); break;
    case 6: os << "Pow" << std::get<6>(v); break;
    case 7: os << "Trunc" << std::get<7>(v); break;
    case 8: os << "Reldiff" << std::get<8>(v); break;
    case 9: os << "And" << std::get<9>(v); break;
    case 10: os << "Or" << std::get<10>(v); break;
    case 11: os << "Ge" << std::get<11>(v); break;
    case 12: os << "Gt" << std::get<12>(v); break;
    case 13: os << "Eq" << std::get<13>(v); break;
    case 14: os << "Concat" << std::get<14>(v); break;
    case 15: os << "StartsWith" << std::get<15>(v); break;
    case 16: os << "EndsWith" << std::get<16>(v); break;
    case 17: os << "BitAnd" << std::get<17>(v); break;
    case 18: os << "BitOr" << std::get<18>(v); break;
    case 19: os << "BitXor" << std::get<19>(v); break;
    case 20: os << "BitShift" << std::get<20>(v); break;
    case 21: os << "Get" << std::get<21>(v); break;
    case 22: os << "In" << std::get<22>(v); break;
    case 23: os << "Strftime" << std::get<23>(v); break;
    case 24: os << "Index" << std::get<24>(v); break;
    case 25: os << "Percentile" << std::get<25>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t58dafdea9146e1796e71a181a3397bec> const v) { os << *v; return os; }

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
struct t083f3b17868fcab98a52958393ac8430 : public std::tuple<
  ::dessser::gen::raql_expr::t58dafdea9146e1796e71a181a3397bec,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t083f3b17868fcab98a52958393ac8430 const &a, t083f3b17868fcab98a52958393ac8430 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b));
}
inline bool operator!=(t083f3b17868fcab98a52958393ac8430 const &a, t083f3b17868fcab98a52958393ac8430 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t083f3b17868fcab98a52958393ac8430 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t083f3b17868fcab98a52958393ac8430> const t) { os << *t; return os; }

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
    case 0: os << "SubString" << std::get<0>(v); break;
    case 1: os << "MapSet" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t29b2bb83c49c2dd7652b8b5187b1f015> const v) { os << *v; return os; }

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
struct t72b37463f2f8137542a48c9591ad44f8 : public std::tuple<
  ::dessser::gen::raql_expr::t29b2bb83c49c2dd7652b8b5187b1f015,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t72b37463f2f8137542a48c9591ad44f8 const &a, t72b37463f2f8137542a48c9591ad44f8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b));
}
inline bool operator!=(t72b37463f2f8137542a48c9591ad44f8 const &a, t72b37463f2f8137542a48c9591ad44f8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t72b37463f2f8137542a48c9591ad44f8 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t72b37463f2f8137542a48c9591ad44f8> const t) { os << *t; return os; }

struct t15424bc73ac631083e04c0c8220ca508 : public std::variant<
  ::dessser::gen::raql_expr::tf7ae7db1c515d769014dcb9b31531498, // SL0
  ::dessser::gen::raql_expr::t2bf9e3d0ef6db07b7c7d81f16499592f, // SL1
  ::dessser::gen::raql_expr::teb665593199b3e0ba16be90af51adc52, // SL1s
  ::dessser::gen::raql_expr::t083f3b17868fcab98a52958393ac8430, // SL2
  ::dessser::gen::raql_expr::t72b37463f2f8137542a48c9591ad44f8 // SL3
> { using variant::variant; };

enum Constr_t15424bc73ac631083e04c0c8220ca508 {
  SL0,
  SL1,
  SL1s,
  SL2,
  SL3,
};

inline std::ostream &operator<<(std::ostream &os, t15424bc73ac631083e04c0c8220ca508 const &v) {
  switch (v.index()) {
    case 0: os << "SL0 " << std::get<0>(v); break;
    case 1: os << "SL1 " << std::get<1>(v); break;
    case 2: os << "SL1s " << std::get<2>(v); break;
    case 3: os << "SL2 " << std::get<3>(v); break;
    case 4: os << "SL3 " << std::get<4>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t15424bc73ac631083e04c0c8220ca508> const v) { os << *v; return os; }

inline bool operator==(t15424bc73ac631083e04c0c8220ca508 const &a, t15424bc73ac631083e04c0c8220ca508 const &b) {
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
inline bool operator!=(t15424bc73ac631083e04c0c8220ca508 const &a, t15424bc73ac631083e04c0c8220ca508 const &b) {
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
    case 0: os << "LocalState" << std::get<0>(v); break;
    case 1: os << "GlobalState" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t9aeb08fceb6eb1d5796a64c8fddd436c> const v) { os << *v; return os; }

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
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc1c4317cb65c5b1b0f16657e46216582> const t) { os << *t; return os; }

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
    case 0: os << "AggrMin" << std::get<0>(v); break;
    case 1: os << "AggrMax" << std::get<1>(v); break;
    case 2: os << "AggrSum" << std::get<2>(v); break;
    case 3: os << "AggrAvg" << std::get<3>(v); break;
    case 4: os << "AggrAnd" << std::get<4>(v); break;
    case 5: os << "AggrOr" << std::get<5>(v); break;
    case 6: os << "AggrBitAnd" << std::get<6>(v); break;
    case 7: os << "AggrBitOr" << std::get<7>(v); break;
    case 8: os << "AggrBitXor" << std::get<8>(v); break;
    case 9: os << "AggrFirst" << std::get<9>(v); break;
    case 10: os << "AggrLast" << std::get<10>(v); break;
    case 11: os << "AggrHistogram " << std::get<11>(v); break;
    case 12: os << "Group" << std::get<12>(v); break;
    case 13: os << "Count" << std::get<13>(v); break;
    case 14: os << "Distinct" << std::get<14>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t82fe136ba20c37a9f3853622f9acef6d> const v) { os << *v; return os; }

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
struct t842e56645003d39e82d251dd0572c177 : public std::tuple<
  ::dessser::gen::raql_expr::t82fe136ba20c37a9f3853622f9acef6d,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
  t842e56645003d39e82d251dd0572c177(std::tuple<::dessser::gen::raql_expr::t82fe136ba20c37a9f3853622f9acef6d, std::shared_ptr<::dessser::gen::raql_expr::t> > p)
    : std::tuple<::dessser::gen::raql_expr::t82fe136ba20c37a9f3853622f9acef6d, std::shared_ptr<::dessser::gen::raql_expr::t> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t842e56645003d39e82d251dd0572c177 const &a, t842e56645003d39e82d251dd0572c177 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t842e56645003d39e82d251dd0572c177 const &a, t842e56645003d39e82d251dd0572c177 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t842e56645003d39e82d251dd0572c177 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t842e56645003d39e82d251dd0572c177> const t) { os << *t; return os; }

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
    case 0: os << "Lag" << std::get<0>(v); break;
    case 1: os << "ExpSmooth" << std::get<1>(v); break;
    case 2: os << "Sample" << std::get<2>(v); break;
    case 3: os << "OneOutOf" << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta7ffb229534f504804e1c24f742166d6> const v) { os << *v; return os; }

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
struct t156bcf1ad9ce6d9e40331026dc1aa6fc : public std::tuple<
  ::dessser::gen::raql_expr::ta7ffb229534f504804e1c24f742166d6,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t156bcf1ad9ce6d9e40331026dc1aa6fc const &a, t156bcf1ad9ce6d9e40331026dc1aa6fc const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b));
}
inline bool operator!=(t156bcf1ad9ce6d9e40331026dc1aa6fc const &a, t156bcf1ad9ce6d9e40331026dc1aa6fc const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t156bcf1ad9ce6d9e40331026dc1aa6fc const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t156bcf1ad9ce6d9e40331026dc1aa6fc> const t) { os << *t; return os; }

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
    case 0: os << "MovingAvg" << std::get<0>(v); break;
    case 1: os << "Hysteresis" << std::get<1>(v); break;
    case 2: os << "OnceEvery " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t213fd001439b7e9763630d054b30bb45> const v) { os << *v; return os; }

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
struct tcd5db8556e1cf4a7d6719ccf4b3ab4e2 : public std::tuple<
  ::dessser::gen::raql_expr::t213fd001439b7e9763630d054b30bb45,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(tcd5db8556e1cf4a7d6719ccf4b3ab4e2 const &a, tcd5db8556e1cf4a7d6719ccf4b3ab4e2 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b));
}
inline bool operator!=(tcd5db8556e1cf4a7d6719ccf4b3ab4e2 const &a, tcd5db8556e1cf4a7d6719ccf4b3ab4e2 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tcd5db8556e1cf4a7d6719ccf4b3ab4e2 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tcd5db8556e1cf4a7d6719ccf4b3ab4e2> const t) { os << *t; return os; }

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
    case 0: os << "DampedHolt" << std::get<0>(v); break;
    case 1: os << "Remember " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2e68ed7bcde629b79efcf8cb23da3dd3> const v) { os << *v; return os; }

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
struct t4cd5d28fed19def290bbf3f3159f7540 : public std::tuple<
  ::dessser::gen::raql_expr::t2e68ed7bcde629b79efcf8cb23da3dd3,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t4cd5d28fed19def290bbf3f3159f7540 const &a, t4cd5d28fed19def290bbf3f3159f7540 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b)) && (*std::get<4>(a)) == (*std::get<4>(b));
}
inline bool operator!=(t4cd5d28fed19def290bbf3f3159f7540 const &a, t4cd5d28fed19def290bbf3f3159f7540 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4cd5d28fed19def290bbf3f3159f7540 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t) << ", ";
  os << std::get<4>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t4cd5d28fed19def290bbf3f3159f7540> const t) { os << *t; return os; }

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
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t544d24ae3e0dea30c1a68be6bcde1392> const r) { os << *r; return os; }

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
    case 0: os << "MultiLinReg" << std::get<0>(v); break;
    case 1: os << "Largest " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7f41e7341759d79e67af6acb8e5b5a38> const v) { os << *v; return os; }

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
struct t3a3a2756e672e330b90782219a734e6e : public std::tuple<
  ::dessser::gen::raql_expr::t7f41e7341759d79e67af6acb8e5b5a38,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >
> {
  using tuple::tuple;
};
inline bool operator==(t3a3a2756e672e330b90782219a734e6e const &a, t3a3a2756e672e330b90782219a734e6e const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b)) && std::get<4>(a) == std::get<4>(b);
}
inline bool operator!=(t3a3a2756e672e330b90782219a734e6e const &a, t3a3a2756e672e330b90782219a734e6e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t3a3a2756e672e330b90782219a734e6e const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t) << ", ";
  os << std::get<4>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t3a3a2756e672e330b90782219a734e6e> const t) { os << *t; return os; }

struct ta020e7823506dcf58037dc373380c189 : public std::variant<
  Void // DampedHoltWinter
> { using variant::variant; };

enum Constr_ta020e7823506dcf58037dc373380c189 {
  DampedHoltWinter,
};

inline std::ostream &operator<<(std::ostream &os, ta020e7823506dcf58037dc373380c189 const &v) {
  switch (v.index()) {
    case 0: os << "DampedHoltWinter" << std::get<0>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta020e7823506dcf58037dc373380c189> const v) { os << *v; return os; }

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
struct t7d9b329001c3dfdd96ec9a76049c274e : public std::tuple<
  ::dessser::gen::raql_expr::ta020e7823506dcf58037dc373380c189,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t7d9b329001c3dfdd96ec9a76049c274e const &a, t7d9b329001c3dfdd96ec9a76049c274e const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b)) && (*std::get<4>(a)) == (*std::get<4>(b)) && (*std::get<5>(a)) == (*std::get<5>(b)) && (*std::get<6>(a)) == (*std::get<6>(b));
}
inline bool operator!=(t7d9b329001c3dfdd96ec9a76049c274e const &a, t7d9b329001c3dfdd96ec9a76049c274e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t7d9b329001c3dfdd96ec9a76049c274e const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t) << ", ";
  os << std::get<4>(t) << ", ";
  os << std::get<5>(t) << ", ";
  os << std::get<6>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7d9b329001c3dfdd96ec9a76049c274e> const t) { os << *t; return os; }

struct t2587b0204a2cc2b5c14a1e38eb6405fe {
  std::shared_ptr<::dessser::gen::raql_expr::t>  by;
  std::shared_ptr<::dessser::gen::raql_expr::t>  duration;
  std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> > max_size;
  dessser::gen::raql_top_output::t_ext output;
  std::shared_ptr<::dessser::gen::raql_expr::t>  sigmas;
  std::shared_ptr<::dessser::gen::raql_expr::t>  size;
  std::shared_ptr<::dessser::gen::raql_expr::t>  Top_time;
  std::shared_ptr<::dessser::gen::raql_expr::t>  Top_what;
  t2587b0204a2cc2b5c14a1e38eb6405fe(std::shared_ptr<::dessser::gen::raql_expr::t>  by_, std::shared_ptr<::dessser::gen::raql_expr::t>  duration_, std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> > max_size_, dessser::gen::raql_top_output::t_ext output_, std::shared_ptr<::dessser::gen::raql_expr::t>  sigmas_, std::shared_ptr<::dessser::gen::raql_expr::t>  size_, std::shared_ptr<::dessser::gen::raql_expr::t>  Top_time_, std::shared_ptr<::dessser::gen::raql_expr::t>  Top_what_) : by(by_), duration(duration_), max_size(max_size_), output(output_), sigmas(sigmas_), size(size_), Top_time(Top_time_), Top_what(Top_what_) {}
  t2587b0204a2cc2b5c14a1e38eb6405fe() = default;
};
inline std::ostream &operator<<(std::ostream &os, t2587b0204a2cc2b5c14a1e38eb6405fe const &r) {
  os << '{';
  os << "by:" << r.by << ',';
  os << "duration:" << r.duration << ',';
  if (r.max_size) os << "max_size:" << r.max_size.value() << ',';
  os << "output:" << r.output << ',';
  os << "sigmas:" << r.sigmas << ',';
  os << "size:" << r.size << ',';
  os << "Top_time:" << r.Top_time << ',';
  os << "Top_what:" << r.Top_what;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2587b0204a2cc2b5c14a1e38eb6405fe> const r) { os << *r; return os; }

inline bool operator==(t2587b0204a2cc2b5c14a1e38eb6405fe const &a, t2587b0204a2cc2b5c14a1e38eb6405fe const &b) {
  return (*a.by) == (*b.by) && (*a.duration) == (*b.duration) && ((a.max_size && b.max_size && (*a.max_size.value()) == (*b.max_size.value())) || (!a.max_size && !b.max_size)) && ::dessser::gen::raql_top_output::Deref(a.output) == ::dessser::gen::raql_top_output::Deref(b.output) && (*a.sigmas) == (*b.sigmas) && (*a.size) == (*b.size) && (*a.Top_time) == (*b.Top_time) && (*a.Top_what) == (*b.Top_what);
}

inline bool operator!=(t2587b0204a2cc2b5c14a1e38eb6405fe const &a, t2587b0204a2cc2b5c14a1e38eb6405fe const &b) {
  return !operator==(a, b);
}
struct te2ba3421e594507f8f26caad78dc0767 {
  std::shared_ptr<::dessser::gen::raql_expr::t>  max_age;
  std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> > sample_size;
  std::shared_ptr<::dessser::gen::raql_expr::t>  time;
  bool tumbling;
  std::shared_ptr<::dessser::gen::raql_expr::t>  what;
  te2ba3421e594507f8f26caad78dc0767(std::shared_ptr<::dessser::gen::raql_expr::t>  max_age_, std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> > sample_size_, std::shared_ptr<::dessser::gen::raql_expr::t>  time_, bool tumbling_, std::shared_ptr<::dessser::gen::raql_expr::t>  what_) : max_age(max_age_), sample_size(sample_size_), time(time_), tumbling(tumbling_), what(what_) {}
  te2ba3421e594507f8f26caad78dc0767() = default;
};
inline std::ostream &operator<<(std::ostream &os, te2ba3421e594507f8f26caad78dc0767 const &r) {
  os << '{';
  os << "max_age:" << r.max_age << ',';
  if (r.sample_size) os << "sample_size:" << r.sample_size.value() << ',';
  os << "time:" << r.time << ',';
  os << "tumbling:" << r.tumbling << ',';
  os << "what:" << r.what;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te2ba3421e594507f8f26caad78dc0767> const r) { os << *r; return os; }

inline bool operator==(te2ba3421e594507f8f26caad78dc0767 const &a, te2ba3421e594507f8f26caad78dc0767 const &b) {
  return (*a.max_age) == (*b.max_age) && ((a.sample_size && b.sample_size && (*a.sample_size.value()) == (*b.sample_size.value())) || (!a.sample_size && !b.sample_size)) && (*a.time) == (*b.time) && a.tumbling == b.tumbling && (*a.what) == (*b.what);
}

inline bool operator!=(te2ba3421e594507f8f26caad78dc0767 const &a, te2ba3421e594507f8f26caad78dc0767 const &b) {
  return !operator==(a, b);
}
struct tc8c905f1080710c74f3fb2c33cb1c44d : public std::variant<
  ::dessser::gen::raql_expr::t842e56645003d39e82d251dd0572c177, // SF1
  ::dessser::gen::raql_expr::t156bcf1ad9ce6d9e40331026dc1aa6fc, // SF2
  ::dessser::gen::raql_expr::tcd5db8556e1cf4a7d6719ccf4b3ab4e2, // SF3
  ::dessser::gen::raql_expr::t4cd5d28fed19def290bbf3f3159f7540, // SF4
  ::dessser::gen::raql_expr::t3a3a2756e672e330b90782219a734e6e, // SF4s
  ::dessser::gen::raql_expr::t7d9b329001c3dfdd96ec9a76049c274e, // SF6
  ::dessser::gen::raql_expr::t2587b0204a2cc2b5c14a1e38eb6405fe, // Top
  ::dessser::gen::raql_expr::te2ba3421e594507f8f26caad78dc0767 // Past
> { using variant::variant; };

enum Constr_tc8c905f1080710c74f3fb2c33cb1c44d {
  SF1,
  SF2,
  SF3,
  SF4,
  SF4s,
  SF6,
  Top,
  Past,
};

inline std::ostream &operator<<(std::ostream &os, tc8c905f1080710c74f3fb2c33cb1c44d const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc8c905f1080710c74f3fb2c33cb1c44d> const v) { os << *v; return os; }

inline bool operator==(tc8c905f1080710c74f3fb2c33cb1c44d const &a, tc8c905f1080710c74f3fb2c33cb1c44d const &b) {
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
inline bool operator!=(tc8c905f1080710c74f3fb2c33cb1c44d const &a, tc8c905f1080710c74f3fb2c33cb1c44d const &b) {
  return !operator==(a, b);
}
struct t0fdcb01004f6d661cc35c8da5539bf53 : public std::tuple<
  ::dessser::gen::raql_expr::t9aeb08fceb6eb1d5796a64c8fddd436c,
  bool,
  ::dessser::gen::raql_expr::tc8c905f1080710c74f3fb2c33cb1c44d
> {
  using tuple::tuple;
};
inline bool operator==(t0fdcb01004f6d661cc35c8da5539bf53 const &a, t0fdcb01004f6d661cc35c8da5539bf53 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t0fdcb01004f6d661cc35c8da5539bf53 const &a, t0fdcb01004f6d661cc35c8da5539bf53 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t0fdcb01004f6d661cc35c8da5539bf53 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0fdcb01004f6d661cc35c8da5539bf53> const t) { os << *t; return os; }

struct td9f8b1c9ff549bea94f93f8fe358ba75 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
  td9f8b1c9ff549bea94f93f8fe358ba75(std::tuple<std::shared_ptr<::dessser::gen::raql_expr::t> , std::shared_ptr<::dessser::gen::raql_expr::t> > p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_expr::t> , std::shared_ptr<::dessser::gen::raql_expr::t> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td9f8b1c9ff549bea94f93f8fe358ba75 const &a, td9f8b1c9ff549bea94f93f8fe358ba75 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(td9f8b1c9ff549bea94f93f8fe358ba75 const &a, td9f8b1c9ff549bea94f93f8fe358ba75 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td9f8b1c9ff549bea94f93f8fe358ba75 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td9f8b1c9ff549bea94f93f8fe358ba75> const t) { os << *t; return os; }

struct t71f3a42b2004c5157ecbe7f6b64cd2c0 : public std::variant<
  ::dessser::gen::raql_expr::td9f8b1c9ff549bea94f93f8fe358ba75 // Split
> { using variant::variant; };

enum Constr_t71f3a42b2004c5157ecbe7f6b64cd2c0 {
  Split,
};

inline std::ostream &operator<<(std::ostream &os, t71f3a42b2004c5157ecbe7f6b64cd2c0 const &v) {
  switch (v.index()) {
    case 0: os << "Split " << std::get<0>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t71f3a42b2004c5157ecbe7f6b64cd2c0> const v) { os << *v; return os; }

inline bool operator==(t71f3a42b2004c5157ecbe7f6b64cd2c0 const &a, t71f3a42b2004c5157ecbe7f6b64cd2c0 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Split
  };
  return false;
}
inline bool operator!=(t71f3a42b2004c5157ecbe7f6b64cd2c0 const &a, t71f3a42b2004c5157ecbe7f6b64cd2c0 const &b) {
  return !operator==(a, b);
}
struct tbfda389c08824349b8fad4a6dffe3b23 : public std::variant<
  Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >, // Tuple
  Lst<::dessser::gen::raql_expr::t0027cfad262565398262cbf1e1df58d6>, // Record
  Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >, // Vector
  ::dessser::gen::raql_expr::t861242503efd004045f7f32d6f59fabc, // Case
  ::dessser::gen::raql_expr::t15424bc73ac631083e04c0c8220ca508, // Stateless
  ::dessser::gen::raql_expr::t0fdcb01004f6d661cc35c8da5539bf53, // Stateful
  ::dessser::gen::raql_expr::t71f3a42b2004c5157ecbe7f6b64cd2c0 // Generator
> { using variant::variant; };

enum Constr_tbfda389c08824349b8fad4a6dffe3b23 {
  Tuple,
  Record,
  Vector,
  Case,
  Stateless,
  Stateful,
  Generator,
};

inline std::ostream &operator<<(std::ostream &os, tbfda389c08824349b8fad4a6dffe3b23 const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tbfda389c08824349b8fad4a6dffe3b23> const v) { os << *v; return os; }

inline bool operator==(tbfda389c08824349b8fad4a6dffe3b23 const &a, tbfda389c08824349b8fad4a6dffe3b23 const &b) {
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
inline bool operator!=(tbfda389c08824349b8fad4a6dffe3b23 const &a, tbfda389c08824349b8fad4a6dffe3b23 const &b) {
  return !operator==(a, b);
}
struct t {
  ::dessser::gen::raql_expr::tbfda389c08824349b8fad4a6dffe3b23 text;
  dessser::gen::raql_type::t_ext typ;
  uint32_t uniq_num;
  std::optional<dessser::gen::units::t_ext> units;
  t(::dessser::gen::raql_expr::tbfda389c08824349b8fad4a6dffe3b23 text_, dessser::gen::raql_type::t_ext typ_, uint32_t uniq_num_, std::optional<dessser::gen::units::t_ext> units_) : text(text_), typ(typ_), uniq_num(uniq_num_), units(units_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "text:" << r.text << ',';
  os << "typ:" << r.typ << ',';
  os << "uniq_num:" << r.uniq_num << ',';
  if (r.units) os << "units:" << r.units.value();
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

inline bool operator==(t const &a, t const &b) {
  return a.text == b.text && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ) && a.uniq_num == b.uniq_num && ((a.units && b.units && ::dessser::gen::units::Deref(a.units.value()) == ::dessser::gen::units::Deref(b.units.value())) || (!a.units && !b.units));
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t941fc5823ff49780db4e6bb9a331e7d9 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  Pointer
> {
  using tuple::tuple;
  t941fc5823ff49780db4e6bb9a331e7d9(std::tuple<std::shared_ptr<::dessser::gen::raql_expr::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_expr::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t941fc5823ff49780db4e6bb9a331e7d9 const &a, t941fc5823ff49780db4e6bb9a331e7d9 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t941fc5823ff49780db4e6bb9a331e7d9 const &a, t941fc5823ff49780db4e6bb9a331e7d9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t941fc5823ff49780db4e6bb9a331e7d9 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t941fc5823ff49780db4e6bb9a331e7d9> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_expr::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_expr::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_expr::t941fc5823ff49780db4e6bb9a331e7d9(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
