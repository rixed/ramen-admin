#ifndef DESSSER_GEN_raql_expr
#define DESSSER_GEN_raql_expr
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
struct t893212699a9dab9c7aae59235cac13d9 : public std::tuple<
  dessser::gen::field_name::t_ext,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t893212699a9dab9c7aae59235cac13d9 const &a, t893212699a9dab9c7aae59235cac13d9 const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t893212699a9dab9c7aae59235cac13d9 const &a, t893212699a9dab9c7aae59235cac13d9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t893212699a9dab9c7aae59235cac13d9 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t893212699a9dab9c7aae59235cac13d9> const t) { os << *t; return os; }

struct ta4f782a597a104ffca4e8eb34b1832aa {
  std::shared_ptr<::dessser::gen::raql_expr::t>  case_cond;
  std::shared_ptr<::dessser::gen::raql_expr::t>  case_cons;
  ta4f782a597a104ffca4e8eb34b1832aa(std::shared_ptr<::dessser::gen::raql_expr::t>  case_cond_, std::shared_ptr<::dessser::gen::raql_expr::t>  case_cons_) : case_cond(case_cond_), case_cons(case_cons_) {}
  ta4f782a597a104ffca4e8eb34b1832aa() = default;
};
inline bool operator==(ta4f782a597a104ffca4e8eb34b1832aa const &a, ta4f782a597a104ffca4e8eb34b1832aa const &b) {
  return (*a.case_cond) == (*b.case_cond) && (*a.case_cons) == (*b.case_cons);
}

inline bool operator!=(ta4f782a597a104ffca4e8eb34b1832aa const &a, ta4f782a597a104ffca4e8eb34b1832aa const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta4f782a597a104ffca4e8eb34b1832aa const &r) {
  os << '{';
  os << "case_cond:" << r.case_cond << ',';
  os << "case_cons:" << r.case_cons;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta4f782a597a104ffca4e8eb34b1832aa> const r) { os << *r; return os; }

struct t7a300b42842ab70bb0c47c946967b5e9 : public std::tuple<
  Lst<::dessser::gen::raql_expr::ta4f782a597a104ffca4e8eb34b1832aa>,
  std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> >
> {
  using tuple::tuple;
};
inline bool operator==(t7a300b42842ab70bb0c47c946967b5e9 const &a, t7a300b42842ab70bb0c47c946967b5e9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && ((std::get<1>(a) && std::get<1>(b) && (*std::get<1>(a).value()) == (*std::get<1>(b).value())) || (!std::get<1>(a) && !std::get<1>(b)));
}
inline bool operator!=(t7a300b42842ab70bb0c47c946967b5e9 const &a, t7a300b42842ab70bb0c47c946967b5e9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t7a300b42842ab70bb0c47c946967b5e9 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  if (std::get<1>(t)) os << std::get<1>(t).value();
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7a300b42842ab70bb0c47c946967b5e9> const t) { os << *t; return os; }

struct tc12b6657c8a8e014a9c0805fe6c1ffaa : public std::variant<
  dessser::gen::raql_value::t_ext, // Const
  dessser::gen::raql_variable::t_ext, // Variable
  dessser::gen::raql_binding_key::t_ext, // Binding
  Void, // Now
  Void, // Random
  Void, // EventStart
  Void, // EventStop
  Lst<dessser::gen::raql_path_comp::t_ext>, // Path
  Void // Pi
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 9 };
};

inline bool operator==(tc12b6657c8a8e014a9c0805fe6c1ffaa const &a, tc12b6657c8a8e014a9c0805fe6c1ffaa const &b) {
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
inline bool operator!=(tc12b6657c8a8e014a9c0805fe6c1ffaa const &a, tc12b6657c8a8e014a9c0805fe6c1ffaa const &b) {
  return !operator==(a, b);
}
enum Constr_tc12b6657c8a8e014a9c0805fe6c1ffaa {
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

inline std::ostream &operator<<(std::ostream &os, tc12b6657c8a8e014a9c0805fe6c1ffaa const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc12b6657c8a8e014a9c0805fe6c1ffaa> const v) { os << *v; return os; }

enum t33468f773066246b23483d21d37a8051 {
  LittleEndian,
  BigEndian,
};

constexpr size_t t33468f773066246b23483d21d37a8051_size { 2 };
inline std::ostream &operator<<(std::ostream &os, t33468f773066246b23483d21d37a8051 const &v) {
  switch (v) {
    case LittleEndian: os << "LittleEndian"; break;
    case BigEndian: os << "BigEndian"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t33468f773066246b23483d21d37a8051> const v) { os << *v; return os; }

struct tb74caafb8030d46b153cbcb9ef47ad2d : public std::tuple<
  dessser::gen::raql_type::t_ext,
  ::dessser::gen::raql_expr::t33468f773066246b23483d21d37a8051
> {
  using tuple::tuple;
};
inline bool operator==(tb74caafb8030d46b153cbcb9ef47ad2d const &a, tb74caafb8030d46b153cbcb9ef47ad2d const &b) {
  return ::dessser::gen::raql_type::Deref(std::get<0>(a)) == ::dessser::gen::raql_type::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb74caafb8030d46b153cbcb9ef47ad2d const &a, tb74caafb8030d46b153cbcb9ef47ad2d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb74caafb8030d46b153cbcb9ef47ad2d const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tb74caafb8030d46b153cbcb9ef47ad2d> const t) { os << *t; return os; }

struct ta1361e7c36afcb5ba90129e776bcbf84 : public std::variant<
  Void, // Age
  dessser::gen::raql_type::t_ext, // Cast
  Void, // Force
  ::dessser::gen::raql_expr::tb74caafb8030d46b153cbcb9ef47ad2d, // Peek
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
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 41 };
};

inline bool operator==(ta1361e7c36afcb5ba90129e776bcbf84 const &a, ta1361e7c36afcb5ba90129e776bcbf84 const &b) {
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
inline bool operator!=(ta1361e7c36afcb5ba90129e776bcbf84 const &a, ta1361e7c36afcb5ba90129e776bcbf84 const &b) {
  return !operator==(a, b);
}
enum Constr_ta1361e7c36afcb5ba90129e776bcbf84 {
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

inline std::ostream &operator<<(std::ostream &os, ta1361e7c36afcb5ba90129e776bcbf84 const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta1361e7c36afcb5ba90129e776bcbf84> const v) { os << *v; return os; }

struct tdcaebeaea4b518f114e9d5c6a3122d25 : public std::tuple<
  ::dessser::gen::raql_expr::ta1361e7c36afcb5ba90129e776bcbf84,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(tdcaebeaea4b518f114e9d5c6a3122d25 const &a, tdcaebeaea4b518f114e9d5c6a3122d25 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(tdcaebeaea4b518f114e9d5c6a3122d25 const &a, tdcaebeaea4b518f114e9d5c6a3122d25 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tdcaebeaea4b518f114e9d5c6a3122d25 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tdcaebeaea4b518f114e9d5c6a3122d25> const t) { os << *t; return os; }

enum t5cdb95783a680d6980d26fd9ad947036 {
  Max,
  Min,
  Print,
  Coalesce,
};

constexpr size_t t5cdb95783a680d6980d26fd9ad947036_size { 4 };
inline std::ostream &operator<<(std::ostream &os, t5cdb95783a680d6980d26fd9ad947036 const &v) {
  switch (v) {
    case Max: os << "Max"; break;
    case Min: os << "Min"; break;
    case Print: os << "Print"; break;
    case Coalesce: os << "Coalesce"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t5cdb95783a680d6980d26fd9ad947036> const v) { os << *v; return os; }

struct t15592658c87dfdd5b6aa9aea551004da : public std::tuple<
  ::dessser::gen::raql_expr::t5cdb95783a680d6980d26fd9ad947036,
  Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >
> {
  using tuple::tuple;
};
inline bool operator==(t15592658c87dfdd5b6aa9aea551004da const &a, t15592658c87dfdd5b6aa9aea551004da const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t15592658c87dfdd5b6aa9aea551004da const &a, t15592658c87dfdd5b6aa9aea551004da const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t15592658c87dfdd5b6aa9aea551004da const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t15592658c87dfdd5b6aa9aea551004da> const t) { os << *t; return os; }

enum t2ade1f1615a1b24c8e2ee86351d1ee39 {
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

constexpr size_t t2ade1f1615a1b24c8e2ee86351d1ee39_size { 26 };
inline std::ostream &operator<<(std::ostream &os, t2ade1f1615a1b24c8e2ee86351d1ee39 const &v) {
  switch (v) {
    case Add: os << "Add"; break;
    case Sub: os << "Sub"; break;
    case Mul: os << "Mul"; break;
    case Div: os << "Div"; break;
    case IDiv: os << "IDiv"; break;
    case Mod: os << "Mod"; break;
    case Pow: os << "Pow"; break;
    case Trunc: os << "Trunc"; break;
    case Reldiff: os << "Reldiff"; break;
    case And: os << "And"; break;
    case Or: os << "Or"; break;
    case Ge: os << "Ge"; break;
    case Gt: os << "Gt"; break;
    case Eq: os << "Eq"; break;
    case Concat: os << "Concat"; break;
    case StartsWith: os << "StartsWith"; break;
    case EndsWith: os << "EndsWith"; break;
    case BitAnd: os << "BitAnd"; break;
    case BitOr: os << "BitOr"; break;
    case BitXor: os << "BitXor"; break;
    case BitShift: os << "BitShift"; break;
    case Get: os << "Get"; break;
    case In: os << "In"; break;
    case Strftime: os << "Strftime"; break;
    case Index: os << "Index"; break;
    case Percentile: os << "Percentile"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2ade1f1615a1b24c8e2ee86351d1ee39> const v) { os << *v; return os; }

struct te7a4d6eae2f27f87719b7e00a7ae2e76 : public std::tuple<
  ::dessser::gen::raql_expr::t2ade1f1615a1b24c8e2ee86351d1ee39,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(te7a4d6eae2f27f87719b7e00a7ae2e76 const &a, te7a4d6eae2f27f87719b7e00a7ae2e76 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b));
}
inline bool operator!=(te7a4d6eae2f27f87719b7e00a7ae2e76 const &a, te7a4d6eae2f27f87719b7e00a7ae2e76 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te7a4d6eae2f27f87719b7e00a7ae2e76 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te7a4d6eae2f27f87719b7e00a7ae2e76> const t) { os << *t; return os; }

enum tafe36d3b8e34b0bdb04064c3f4cda035 {
  SubString,
  MapSet,
};

constexpr size_t tafe36d3b8e34b0bdb04064c3f4cda035_size { 2 };
inline std::ostream &operator<<(std::ostream &os, tafe36d3b8e34b0bdb04064c3f4cda035 const &v) {
  switch (v) {
    case SubString: os << "SubString"; break;
    case MapSet: os << "MapSet"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tafe36d3b8e34b0bdb04064c3f4cda035> const v) { os << *v; return os; }

struct t53da299de89588caa86990df40ee157b : public std::tuple<
  ::dessser::gen::raql_expr::tafe36d3b8e34b0bdb04064c3f4cda035,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t53da299de89588caa86990df40ee157b const &a, t53da299de89588caa86990df40ee157b const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b));
}
inline bool operator!=(t53da299de89588caa86990df40ee157b const &a, t53da299de89588caa86990df40ee157b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t53da299de89588caa86990df40ee157b const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t53da299de89588caa86990df40ee157b> const t) { os << *t; return os; }

struct t3267fa899a41f9e0c8db35320b53e6b1 : public std::variant<
  ::dessser::gen::raql_expr::tc12b6657c8a8e014a9c0805fe6c1ffaa, // SL0
  ::dessser::gen::raql_expr::tdcaebeaea4b518f114e9d5c6a3122d25, // SL1
  ::dessser::gen::raql_expr::t15592658c87dfdd5b6aa9aea551004da, // SL1s
  ::dessser::gen::raql_expr::te7a4d6eae2f27f87719b7e00a7ae2e76, // SL2
  ::dessser::gen::raql_expr::t53da299de89588caa86990df40ee157b // SL3
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 5 };
};

inline bool operator==(t3267fa899a41f9e0c8db35320b53e6b1 const &a, t3267fa899a41f9e0c8db35320b53e6b1 const &b) {
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
inline bool operator!=(t3267fa899a41f9e0c8db35320b53e6b1 const &a, t3267fa899a41f9e0c8db35320b53e6b1 const &b) {
  return !operator==(a, b);
}
enum Constr_t3267fa899a41f9e0c8db35320b53e6b1 {
  SL0,
  SL1,
  SL1s,
  SL2,
  SL3,
};

inline std::ostream &operator<<(std::ostream &os, t3267fa899a41f9e0c8db35320b53e6b1 const &v) {
  switch (v.index()) {
    case 0: os << "SL0 " << std::get<0>(v); break;
    case 1: os << "SL1 " << std::get<1>(v); break;
    case 2: os << "SL1s " << std::get<2>(v); break;
    case 3: os << "SL2 " << std::get<3>(v); break;
    case 4: os << "SL3 " << std::get<4>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t3267fa899a41f9e0c8db35320b53e6b1> const v) { os << *v; return os; }

enum t30db7861170b37de146c6231a87c6042 {
  LocalState,
  GlobalState,
};

constexpr size_t t30db7861170b37de146c6231a87c6042_size { 2 };
inline std::ostream &operator<<(std::ostream &os, t30db7861170b37de146c6231a87c6042 const &v) {
  switch (v) {
    case LocalState: os << "LocalState"; break;
    case GlobalState: os << "GlobalState"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t30db7861170b37de146c6231a87c6042> const v) { os << *v; return os; }

struct t66cf3f891349e2747678760eec02eb62 : public std::tuple<
  double,
  double,
  uint32_t
> {
  using tuple::tuple;
};
inline bool operator==(t66cf3f891349e2747678760eec02eb62 const &a, t66cf3f891349e2747678760eec02eb62 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t66cf3f891349e2747678760eec02eb62 const &a, t66cf3f891349e2747678760eec02eb62 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t66cf3f891349e2747678760eec02eb62 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t66cf3f891349e2747678760eec02eb62> const t) { os << *t; return os; }

struct t72c6a286926f82d38f40c2c2d00ebcc6 : public std::variant<
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
  ::dessser::gen::raql_expr::t66cf3f891349e2747678760eec02eb62, // AggrHistogram
  Void, // Group
  Void, // Count
  Void // Distinct
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 15 };
};

inline bool operator==(t72c6a286926f82d38f40c2c2d00ebcc6 const &a, t72c6a286926f82d38f40c2c2d00ebcc6 const &b) {
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
inline bool operator!=(t72c6a286926f82d38f40c2c2d00ebcc6 const &a, t72c6a286926f82d38f40c2c2d00ebcc6 const &b) {
  return !operator==(a, b);
}
enum Constr_t72c6a286926f82d38f40c2c2d00ebcc6 {
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

inline std::ostream &operator<<(std::ostream &os, t72c6a286926f82d38f40c2c2d00ebcc6 const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t72c6a286926f82d38f40c2c2d00ebcc6> const v) { os << *v; return os; }

struct t33838a2e63bc4895abd013987ee48342 : public std::tuple<
  ::dessser::gen::raql_expr::t72c6a286926f82d38f40c2c2d00ebcc6,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t33838a2e63bc4895abd013987ee48342 const &a, t33838a2e63bc4895abd013987ee48342 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t33838a2e63bc4895abd013987ee48342 const &a, t33838a2e63bc4895abd013987ee48342 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t33838a2e63bc4895abd013987ee48342 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t33838a2e63bc4895abd013987ee48342> const t) { os << *t; return os; }

enum t638469967f4a441e0e32d7820019314d {
  Lag,
  ExpSmooth,
  Sample,
  OneOutOf,
};

constexpr size_t t638469967f4a441e0e32d7820019314d_size { 4 };
inline std::ostream &operator<<(std::ostream &os, t638469967f4a441e0e32d7820019314d const &v) {
  switch (v) {
    case Lag: os << "Lag"; break;
    case ExpSmooth: os << "ExpSmooth"; break;
    case Sample: os << "Sample"; break;
    case OneOutOf: os << "OneOutOf"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t638469967f4a441e0e32d7820019314d> const v) { os << *v; return os; }

struct tce9a4f76e50a6cfbfc9de64ac8fc6e78 : public std::tuple<
  ::dessser::gen::raql_expr::t638469967f4a441e0e32d7820019314d,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(tce9a4f76e50a6cfbfc9de64ac8fc6e78 const &a, tce9a4f76e50a6cfbfc9de64ac8fc6e78 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b));
}
inline bool operator!=(tce9a4f76e50a6cfbfc9de64ac8fc6e78 const &a, tce9a4f76e50a6cfbfc9de64ac8fc6e78 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tce9a4f76e50a6cfbfc9de64ac8fc6e78 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tce9a4f76e50a6cfbfc9de64ac8fc6e78> const t) { os << *t; return os; }

struct tde6226ab24e2bde569d940f438b90782 : public std::variant<
  Void, // MovingAvg
  Void, // Hysteresis
  bool // OnceEvery
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

inline bool operator==(tde6226ab24e2bde569d940f438b90782 const &a, tde6226ab24e2bde569d940f438b90782 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // MovingAvg
    case 1: return std::get<1>(a) == std::get<1>(b); // Hysteresis
    case 2: return std::get<2>(a) == std::get<2>(b); // OnceEvery
  };
  return false;
}
inline bool operator!=(tde6226ab24e2bde569d940f438b90782 const &a, tde6226ab24e2bde569d940f438b90782 const &b) {
  return !operator==(a, b);
}
enum Constr_tde6226ab24e2bde569d940f438b90782 {
  MovingAvg,
  Hysteresis,
  OnceEvery,
};

inline std::ostream &operator<<(std::ostream &os, tde6226ab24e2bde569d940f438b90782 const &v) {
  switch (v.index()) {
    case 0: os << "MovingAvg" << std::get<0>(v); break;
    case 1: os << "Hysteresis" << std::get<1>(v); break;
    case 2: os << "OnceEvery " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tde6226ab24e2bde569d940f438b90782> const v) { os << *v; return os; }

struct t27e357241014cac9c70637dbe763fa46 : public std::tuple<
  ::dessser::gen::raql_expr::tde6226ab24e2bde569d940f438b90782,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t27e357241014cac9c70637dbe763fa46 const &a, t27e357241014cac9c70637dbe763fa46 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b));
}
inline bool operator!=(t27e357241014cac9c70637dbe763fa46 const &a, t27e357241014cac9c70637dbe763fa46 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t27e357241014cac9c70637dbe763fa46 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t27e357241014cac9c70637dbe763fa46> const t) { os << *t; return os; }

struct t482aebd3608ffaf2914a7e856b14192b : public std::variant<
  Void, // DampedHolt
  bool // Remember
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t482aebd3608ffaf2914a7e856b14192b const &a, t482aebd3608ffaf2914a7e856b14192b const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // DampedHolt
    case 1: return std::get<1>(a) == std::get<1>(b); // Remember
  };
  return false;
}
inline bool operator!=(t482aebd3608ffaf2914a7e856b14192b const &a, t482aebd3608ffaf2914a7e856b14192b const &b) {
  return !operator==(a, b);
}
enum Constr_t482aebd3608ffaf2914a7e856b14192b {
  DampedHolt,
  Remember,
};

inline std::ostream &operator<<(std::ostream &os, t482aebd3608ffaf2914a7e856b14192b const &v) {
  switch (v.index()) {
    case 0: os << "DampedHolt" << std::get<0>(v); break;
    case 1: os << "Remember " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t482aebd3608ffaf2914a7e856b14192b> const v) { os << *v; return os; }

struct t2783f1bd5678d740a05f0e7d758a084e : public std::tuple<
  ::dessser::gen::raql_expr::t482aebd3608ffaf2914a7e856b14192b,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t2783f1bd5678d740a05f0e7d758a084e const &a, t2783f1bd5678d740a05f0e7d758a084e const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b)) && (*std::get<4>(a)) == (*std::get<4>(b));
}
inline bool operator!=(t2783f1bd5678d740a05f0e7d758a084e const &a, t2783f1bd5678d740a05f0e7d758a084e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t2783f1bd5678d740a05f0e7d758a084e const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t) << ", ";
  os << std::get<4>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2783f1bd5678d740a05f0e7d758a084e> const t) { os << *t; return os; }

struct t98f65fefde90f21cac9f06d483a57475 {
  bool inv;
  bool up_to;
  t98f65fefde90f21cac9f06d483a57475(bool inv_, bool up_to_) : inv(inv_), up_to(up_to_) {}
  t98f65fefde90f21cac9f06d483a57475() = default;
};
inline bool operator==(t98f65fefde90f21cac9f06d483a57475 const &a, t98f65fefde90f21cac9f06d483a57475 const &b) {
  return a.inv == b.inv && a.up_to == b.up_to;
}

inline bool operator!=(t98f65fefde90f21cac9f06d483a57475 const &a, t98f65fefde90f21cac9f06d483a57475 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t98f65fefde90f21cac9f06d483a57475 const &r) {
  os << '{';
  os << "inv:" << r.inv << ',';
  os << "up_to:" << r.up_to;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t98f65fefde90f21cac9f06d483a57475> const r) { os << *r; return os; }

struct tdd3c5c0a7097ddd3d17c28956240cbea : public std::variant<
  Void, // MultiLinReg
  ::dessser::gen::raql_expr::t98f65fefde90f21cac9f06d483a57475 // Largest
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(tdd3c5c0a7097ddd3d17c28956240cbea const &a, tdd3c5c0a7097ddd3d17c28956240cbea const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // MultiLinReg
    case 1: return std::get<1>(a) == std::get<1>(b); // Largest
  };
  return false;
}
inline bool operator!=(tdd3c5c0a7097ddd3d17c28956240cbea const &a, tdd3c5c0a7097ddd3d17c28956240cbea const &b) {
  return !operator==(a, b);
}
enum Constr_tdd3c5c0a7097ddd3d17c28956240cbea {
  MultiLinReg,
  Largest,
};

inline std::ostream &operator<<(std::ostream &os, tdd3c5c0a7097ddd3d17c28956240cbea const &v) {
  switch (v.index()) {
    case 0: os << "MultiLinReg" << std::get<0>(v); break;
    case 1: os << "Largest " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tdd3c5c0a7097ddd3d17c28956240cbea> const v) { os << *v; return os; }

struct t62a574a444d31b9a476bfa017f081a2b : public std::tuple<
  ::dessser::gen::raql_expr::tdd3c5c0a7097ddd3d17c28956240cbea,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >
> {
  using tuple::tuple;
};
inline bool operator==(t62a574a444d31b9a476bfa017f081a2b const &a, t62a574a444d31b9a476bfa017f081a2b const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b)) && std::get<4>(a) == std::get<4>(b);
}
inline bool operator!=(t62a574a444d31b9a476bfa017f081a2b const &a, t62a574a444d31b9a476bfa017f081a2b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t62a574a444d31b9a476bfa017f081a2b const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t) << ", ";
  os << std::get<4>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t62a574a444d31b9a476bfa017f081a2b> const t) { os << *t; return os; }

enum t7ca40b2395ae0931861f2a365208f839 {
  DampedHoltWinter,
};

constexpr size_t t7ca40b2395ae0931861f2a365208f839_size { 1 };
inline std::ostream &operator<<(std::ostream &os, t7ca40b2395ae0931861f2a365208f839 const &v) {
  switch (v) {
    case DampedHoltWinter: os << "DampedHoltWinter"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7ca40b2395ae0931861f2a365208f839> const v) { os << *v; return os; }

struct t7a9d88064d123458a7299610e9c50c56 : public std::tuple<
  ::dessser::gen::raql_expr::t7ca40b2395ae0931861f2a365208f839,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t7a9d88064d123458a7299610e9c50c56 const &a, t7a9d88064d123458a7299610e9c50c56 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b)) && (*std::get<2>(a)) == (*std::get<2>(b)) && (*std::get<3>(a)) == (*std::get<3>(b)) && (*std::get<4>(a)) == (*std::get<4>(b)) && (*std::get<5>(a)) == (*std::get<5>(b)) && (*std::get<6>(a)) == (*std::get<6>(b));
}
inline bool operator!=(t7a9d88064d123458a7299610e9c50c56 const &a, t7a9d88064d123458a7299610e9c50c56 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t7a9d88064d123458a7299610e9c50c56 const &t) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7a9d88064d123458a7299610e9c50c56> const t) { os << *t; return os; }

struct t9ff32f6938631a338c8ace99a86c40f3 {
  dessser::gen::raql_top_output::t_ext output;
  std::shared_ptr<::dessser::gen::raql_expr::t>  size;
  std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> > max_size;
  std::shared_ptr<::dessser::gen::raql_expr::t>  Top_what;
  std::shared_ptr<::dessser::gen::raql_expr::t>  by;
  std::shared_ptr<::dessser::gen::raql_expr::t>  Top_time;
  std::shared_ptr<::dessser::gen::raql_expr::t>  duration;
  std::shared_ptr<::dessser::gen::raql_expr::t>  sigmas;
  t9ff32f6938631a338c8ace99a86c40f3(dessser::gen::raql_top_output::t_ext output_, std::shared_ptr<::dessser::gen::raql_expr::t>  size_, std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> > max_size_, std::shared_ptr<::dessser::gen::raql_expr::t>  Top_what_, std::shared_ptr<::dessser::gen::raql_expr::t>  by_, std::shared_ptr<::dessser::gen::raql_expr::t>  Top_time_, std::shared_ptr<::dessser::gen::raql_expr::t>  duration_, std::shared_ptr<::dessser::gen::raql_expr::t>  sigmas_) : output(output_), size(size_), max_size(max_size_), Top_what(Top_what_), by(by_), Top_time(Top_time_), duration(duration_), sigmas(sigmas_) {}
  t9ff32f6938631a338c8ace99a86c40f3() = default;
};
inline bool operator==(t9ff32f6938631a338c8ace99a86c40f3 const &a, t9ff32f6938631a338c8ace99a86c40f3 const &b) {
  return ::dessser::gen::raql_top_output::Deref(a.output) == ::dessser::gen::raql_top_output::Deref(b.output) && (*a.size) == (*b.size) && ((a.max_size && b.max_size && (*a.max_size.value()) == (*b.max_size.value())) || (!a.max_size && !b.max_size)) && (*a.Top_what) == (*b.Top_what) && (*a.by) == (*b.by) && (*a.Top_time) == (*b.Top_time) && (*a.duration) == (*b.duration) && (*a.sigmas) == (*b.sigmas);
}

inline bool operator!=(t9ff32f6938631a338c8ace99a86c40f3 const &a, t9ff32f6938631a338c8ace99a86c40f3 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t9ff32f6938631a338c8ace99a86c40f3 const &r) {
  os << '{';
  os << "output:" << r.output << ',';
  os << "size:" << r.size << ',';
  if (r.max_size) os << "max_size:" << r.max_size.value() << ',';
  os << "Top_what:" << r.Top_what << ',';
  os << "by:" << r.by << ',';
  os << "Top_time:" << r.Top_time << ',';
  os << "duration:" << r.duration << ',';
  os << "sigmas:" << r.sigmas;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t9ff32f6938631a338c8ace99a86c40f3> const r) { os << *r; return os; }

struct t1444e78faaacd44c5e033d97448c4e87 {
  std::shared_ptr<::dessser::gen::raql_expr::t>  what;
  std::shared_ptr<::dessser::gen::raql_expr::t>  time;
  std::shared_ptr<::dessser::gen::raql_expr::t>  max_age;
  bool tumbling;
  std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> > sample_size;
  t1444e78faaacd44c5e033d97448c4e87(std::shared_ptr<::dessser::gen::raql_expr::t>  what_, std::shared_ptr<::dessser::gen::raql_expr::t>  time_, std::shared_ptr<::dessser::gen::raql_expr::t>  max_age_, bool tumbling_, std::optional<std::shared_ptr<::dessser::gen::raql_expr::t> > sample_size_) : what(what_), time(time_), max_age(max_age_), tumbling(tumbling_), sample_size(sample_size_) {}
  t1444e78faaacd44c5e033d97448c4e87() = default;
};
inline bool operator==(t1444e78faaacd44c5e033d97448c4e87 const &a, t1444e78faaacd44c5e033d97448c4e87 const &b) {
  return (*a.what) == (*b.what) && (*a.time) == (*b.time) && (*a.max_age) == (*b.max_age) && a.tumbling == b.tumbling && ((a.sample_size && b.sample_size && (*a.sample_size.value()) == (*b.sample_size.value())) || (!a.sample_size && !b.sample_size));
}

inline bool operator!=(t1444e78faaacd44c5e033d97448c4e87 const &a, t1444e78faaacd44c5e033d97448c4e87 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t1444e78faaacd44c5e033d97448c4e87 const &r) {
  os << '{';
  os << "what:" << r.what << ',';
  os << "time:" << r.time << ',';
  os << "max_age:" << r.max_age << ',';
  os << "tumbling:" << r.tumbling << ',';
  if (r.sample_size) os << "sample_size:" << r.sample_size.value();
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t1444e78faaacd44c5e033d97448c4e87> const r) { os << *r; return os; }

struct t988dbba8f7f718b94a28d77808883135 : public std::variant<
  ::dessser::gen::raql_expr::t33838a2e63bc4895abd013987ee48342, // SF1
  ::dessser::gen::raql_expr::tce9a4f76e50a6cfbfc9de64ac8fc6e78, // SF2
  ::dessser::gen::raql_expr::t27e357241014cac9c70637dbe763fa46, // SF3
  ::dessser::gen::raql_expr::t2783f1bd5678d740a05f0e7d758a084e, // SF4
  ::dessser::gen::raql_expr::t62a574a444d31b9a476bfa017f081a2b, // SF4s
  ::dessser::gen::raql_expr::t7a9d88064d123458a7299610e9c50c56, // SF6
  ::dessser::gen::raql_expr::t9ff32f6938631a338c8ace99a86c40f3, // Top
  ::dessser::gen::raql_expr::t1444e78faaacd44c5e033d97448c4e87 // Past
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 8 };
};

inline bool operator==(t988dbba8f7f718b94a28d77808883135 const &a, t988dbba8f7f718b94a28d77808883135 const &b) {
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
inline bool operator!=(t988dbba8f7f718b94a28d77808883135 const &a, t988dbba8f7f718b94a28d77808883135 const &b) {
  return !operator==(a, b);
}
enum Constr_t988dbba8f7f718b94a28d77808883135 {
  SF1,
  SF2,
  SF3,
  SF4,
  SF4s,
  SF6,
  Top,
  Past,
};

inline std::ostream &operator<<(std::ostream &os, t988dbba8f7f718b94a28d77808883135 const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t988dbba8f7f718b94a28d77808883135> const v) { os << *v; return os; }

struct te911ed7290f60379de95c4e48ca07aa8 {
  std::optional<::dessser::gen::raql_expr::t30db7861170b37de146c6231a87c6042> lifespan;
  bool skip_nulls;
  ::dessser::gen::raql_expr::t988dbba8f7f718b94a28d77808883135 operation;
  te911ed7290f60379de95c4e48ca07aa8(std::optional<::dessser::gen::raql_expr::t30db7861170b37de146c6231a87c6042> lifespan_, bool skip_nulls_, ::dessser::gen::raql_expr::t988dbba8f7f718b94a28d77808883135 operation_) : lifespan(lifespan_), skip_nulls(skip_nulls_), operation(operation_) {}
  te911ed7290f60379de95c4e48ca07aa8() = default;
};
inline bool operator==(te911ed7290f60379de95c4e48ca07aa8 const &a, te911ed7290f60379de95c4e48ca07aa8 const &b) {
  return ((a.lifespan && b.lifespan && a.lifespan.value() == b.lifespan.value()) || (!a.lifespan && !b.lifespan)) && a.skip_nulls == b.skip_nulls && a.operation == b.operation;
}

inline bool operator!=(te911ed7290f60379de95c4e48ca07aa8 const &a, te911ed7290f60379de95c4e48ca07aa8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te911ed7290f60379de95c4e48ca07aa8 const &r) {
  os << '{';
  if (r.lifespan) os << "lifespan:" << r.lifespan.value() << ',';
  os << "skip_nulls:" << r.skip_nulls << ',';
  os << "operation:" << r.operation;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te911ed7290f60379de95c4e48ca07aa8> const r) { os << *r; return os; }

struct t09ebe067ef7b13158d058ba3ce6f150c : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  std::shared_ptr<::dessser::gen::raql_expr::t> 
> {
  using tuple::tuple;
};
inline bool operator==(t09ebe067ef7b13158d058ba3ce6f150c const &a, t09ebe067ef7b13158d058ba3ce6f150c const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t09ebe067ef7b13158d058ba3ce6f150c const &a, t09ebe067ef7b13158d058ba3ce6f150c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t09ebe067ef7b13158d058ba3ce6f150c const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t09ebe067ef7b13158d058ba3ce6f150c> const t) { os << *t; return os; }

struct t8411610d7f6cfe33697a36943471c946 : public std::variant<
  ::dessser::gen::raql_expr::t09ebe067ef7b13158d058ba3ce6f150c // Split
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 1 };
};

inline bool operator==(t8411610d7f6cfe33697a36943471c946 const &a, t8411610d7f6cfe33697a36943471c946 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Split
  };
  return false;
}
inline bool operator!=(t8411610d7f6cfe33697a36943471c946 const &a, t8411610d7f6cfe33697a36943471c946 const &b) {
  return !operator==(a, b);
}
enum Constr_t8411610d7f6cfe33697a36943471c946 {
  Split,
};

inline std::ostream &operator<<(std::ostream &os, t8411610d7f6cfe33697a36943471c946 const &v) {
  switch (v.index()) {
    case 0: os << "Split " << std::get<0>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t8411610d7f6cfe33697a36943471c946> const v) { os << *v; return os; }

struct t6c5f9fd1d543de7239bd047f61f528e7 : public std::variant<
  Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >, // Tuple
  Lst<::dessser::gen::raql_expr::t893212699a9dab9c7aae59235cac13d9>, // Record
  Lst<std::shared_ptr<::dessser::gen::raql_expr::t> >, // Vector
  ::dessser::gen::raql_expr::t7a300b42842ab70bb0c47c946967b5e9, // Case
  ::dessser::gen::raql_expr::t3267fa899a41f9e0c8db35320b53e6b1, // Stateless
  ::dessser::gen::raql_expr::te911ed7290f60379de95c4e48ca07aa8, // Stateful
  ::dessser::gen::raql_expr::t8411610d7f6cfe33697a36943471c946 // Generator
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 7 };
};

inline bool operator==(t6c5f9fd1d543de7239bd047f61f528e7 const &a, t6c5f9fd1d543de7239bd047f61f528e7 const &b) {
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
inline bool operator!=(t6c5f9fd1d543de7239bd047f61f528e7 const &a, t6c5f9fd1d543de7239bd047f61f528e7 const &b) {
  return !operator==(a, b);
}
enum Constr_t6c5f9fd1d543de7239bd047f61f528e7 {
  Tuple,
  Record,
  Vector,
  Case,
  Stateless,
  Stateful,
  Generator,
};

inline std::ostream &operator<<(std::ostream &os, t6c5f9fd1d543de7239bd047f61f528e7 const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t6c5f9fd1d543de7239bd047f61f528e7> const v) { os << *v; return os; }

struct t {
  ::dessser::gen::raql_expr::t6c5f9fd1d543de7239bd047f61f528e7 text;
  uint32_t uniq_num;
  dessser::gen::raql_type::t_ext typ;
  std::optional<dessser::gen::units::t_ext> units;
  t(::dessser::gen::raql_expr::t6c5f9fd1d543de7239bd047f61f528e7 text_, uint32_t uniq_num_, dessser::gen::raql_type::t_ext typ_, std::optional<dessser::gen::units::t_ext> units_) : text(text_), uniq_num(uniq_num_), typ(typ_), units(units_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.text == b.text && a.uniq_num == b.uniq_num && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ) && ((a.units && b.units && ::dessser::gen::units::Deref(a.units.value()) == ::dessser::gen::units::Deref(b.units.value())) || (!a.units && !b.units));
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "text:" << r.text << ',';
  os << "uniq_num:" << r.uniq_num << ',';
  os << "typ:" << r.typ << ',';
  if (r.units) os << "units:" << r.units.value();
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

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
struct tf4faeadcb1d4bc08688cd9dc4070e517 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_expr::t> ,
  Pointer
> {
  using tuple::tuple;
  tf4faeadcb1d4bc08688cd9dc4070e517(std::tuple<std::shared_ptr<::dessser::gen::raql_expr::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_expr::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf4faeadcb1d4bc08688cd9dc4070e517 const &a, tf4faeadcb1d4bc08688cd9dc4070e517 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf4faeadcb1d4bc08688cd9dc4070e517 const &a, tf4faeadcb1d4bc08688cd9dc4070e517 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf4faeadcb1d4bc08688cd9dc4070e517 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf4faeadcb1d4bc08688cd9dc4070e517> const t) { os << *t; return os; }

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
/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_expr::t>  &,Pointer &)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_expr::t>  &)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_expr::tf4faeadcb1d4bc08688cd9dc4070e517(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::raql_expr::tf4faeadcb1d4bc08688cd9dc4070e517(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_expr::t>  &,Pointer &)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
