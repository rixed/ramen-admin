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
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  dessser::gen::field_name::t_ext,
  t*
> t5b91ba1a37fd19816559f3dabb32e8b5;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t74f1fe598dc51577e2126144a227cc38 {
  t* case_cond;
  t* case_cons;
  t74f1fe598dc51577e2126144a227cc38(t* case_cond_, t* case_cons_) : case_cond(case_cond_), case_cons(case_cons_) {}
  t74f1fe598dc51577e2126144a227cc38() = default;
  bool operator==(t74f1fe598dc51577e2126144a227cc38 const &other) const {
    return case_cond == other.case_cond && case_cons == other.case_cons;
  }
};
inline std::ostream &operator<<(std::ostream &os, t74f1fe598dc51577e2126144a227cc38 const &r) {
  os << '{';
  os << "case_cond:" << *r.case_cond << ',';
  os << "case_cons:" << *r.case_cons;
  os << '}';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  Lst<::dessser::gen::raql_expr::t74f1fe598dc51577e2126144a227cc38>,
  std::optional<t*>
> te3216971987147b926d84139da428868;

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
    case 3: os << "Now " << std::get<3>(v); break;
    case 4: os << "Random " << std::get<4>(v); break;
    case 5: os << "EventStart " << std::get<5>(v); break;
    case 6: os << "EventStop " << std::get<6>(v); break;
    case 7: os << "Path " << std::get<7>(v); break;
    case 8: os << "Pi " << std::get<8>(v); break;
  }
  return os;
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

typedef std::tuple<
  dessser::gen::raql_type::t_ext,
  ::dessser::gen::raql_expr::tc847b6b1db0945d7ec695a4564143cf9
> tb0402ef6eb0c00c8a2b51d497e491ff8;

struct t133df32a784c216f0d970b5805a6b8b8 : public std::variant<
  Void, // Age
  dessser::gen::raql_type::t_ext, // Cast
  Void, // Force
  ::dessser::gen::raql_expr::tb0402ef6eb0c00c8a2b51d497e491ff8, // Peek
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

enum Constr_t133df32a784c216f0d970b5805a6b8b8 {
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

inline std::ostream &operator<<(std::ostream &os, t133df32a784c216f0d970b5805a6b8b8 const &v) {
  switch (v.index()) {
    case 0: os << "Age " << std::get<0>(v); break;
    case 1: os << "Cast " << std::get<1>(v); break;
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  ::dessser::gen::raql_expr::t133df32a784c216f0d970b5805a6b8b8,
  t*
> te187493dde7c4904748658f3fab36344;

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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  ::dessser::gen::raql_expr::t0714e951accff7f9c7ebbbf55cde5e2d,
  Lst<t*>
> t1e1d1f41f4901a81e40d15f719d91e36;

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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct ta9eb4fce65081acc55eb3ed855903623 : public std::tuple<
  ::dessser::gen::raql_expr::t58dafdea9146e1796e71a181a3397bec,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, ta9eb4fce65081acc55eb3ed855903623 const &t) {
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t794ab464927988d666f9919732c3239c : public std::tuple<
  ::dessser::gen::raql_expr::t29b2bb83c49c2dd7652b8b5187b1f015,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t794ab464927988d666f9919732c3239c const &t) {
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
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t9dca13408164b9b878af2f494a648c1a : public std::variant<
  ::dessser::gen::raql_expr::tf7ae7db1c515d769014dcb9b31531498, // SL0
  ::dessser::gen::raql_expr::te187493dde7c4904748658f3fab36344, // SL1
  ::dessser::gen::raql_expr::t1e1d1f41f4901a81e40d15f719d91e36, // SL1s
  ::dessser::gen::raql_expr::ta9eb4fce65081acc55eb3ed855903623, // SL2
  ::dessser::gen::raql_expr::t794ab464927988d666f9919732c3239c // SL3
> { using variant::variant; };

enum Constr_t9dca13408164b9b878af2f494a648c1a {
  SL0,
  SL1,
  SL1s,
  SL2,
  SL3,
};

inline std::ostream &operator<<(std::ostream &os, t9dca13408164b9b878af2f494a648c1a const &v) {
  switch (v.index()) {
    case 0: os << "SL0 " << std::get<0>(v); break;
    case 1: os << "SL1 " << std::get<1>(v); break;
    case 2: os << "SL1s " << std::get<2>(v); break;
    case 3: os << "SL2 " << std::get<3>(v); break;
    case 4: os << "SL3 " << std::get<4>(v); break;
  }
  return os;
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

struct t7a94101e0d1c22c7ddfebd959d73730a : public std::tuple<
  double,
  double,
  uint32_t
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t7a94101e0d1c22c7ddfebd959d73730a const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t82ed0b4d8276434c22a0ca15ade92062 : public std::variant<
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
  ::dessser::gen::raql_expr::t7a94101e0d1c22c7ddfebd959d73730a, // AggrHistogram
  Void, // Group
  Void, // Count
  Void // Distinct
> { using variant::variant; };

enum Constr_t82ed0b4d8276434c22a0ca15ade92062 {
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

inline std::ostream &operator<<(std::ostream &os, t82ed0b4d8276434c22a0ca15ade92062 const &v) {
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  ::dessser::gen::raql_expr::t82ed0b4d8276434c22a0ca15ade92062,
  t*
> t797b5289cecf30b53b722bff0d1083a8;

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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct tab0dcdfe0a2d58ff7fba6f4496f1629d : public std::tuple<
  ::dessser::gen::raql_expr::ta7ffb229534f504804e1c24f742166d6,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, tab0dcdfe0a2d58ff7fba6f4496f1629d const &t) {
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t680c3184893bd6b56c0f5481ac3d4cb6 : public std::tuple<
  ::dessser::gen::raql_expr::t213fd001439b7e9763630d054b30bb45,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t680c3184893bd6b56c0f5481ac3d4cb6 const &t) {
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t801b86950988d4a9ab0f917a16c686fa : public std::tuple<
  ::dessser::gen::raql_expr::t2e68ed7bcde629b79efcf8cb23da3dd3,
  t*,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t801b86950988d4a9ab0f917a16c686fa const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t) << ", "
     << *std::get<2>(t) << ", "
     << *std::get<3>(t) << ", "
     << *std::get<4>(t)
     << '>';
  return os;
}

struct tf2ae8d5f5e1b34f3177f49c9abffb1b8 {
  bool inv;
  bool up_to;
  tf2ae8d5f5e1b34f3177f49c9abffb1b8(bool inv_, bool up_to_) : inv(inv_), up_to(up_to_) {}
  tf2ae8d5f5e1b34f3177f49c9abffb1b8() = default;
  bool operator==(tf2ae8d5f5e1b34f3177f49c9abffb1b8 const &other) const {
    return inv == other.inv && up_to == other.up_to;
  }
};
inline std::ostream &operator<<(std::ostream &os, tf2ae8d5f5e1b34f3177f49c9abffb1b8 const &r) {
  os << '{';
  os << "inv:" << r.inv << ',';
  os << "up_to:" << r.up_to;
  os << '}';
  return os;
}

struct ta224f9c3db1110a4377a7bc09d90f61d : public std::variant<
  Void, // MultiLinReg
  ::dessser::gen::raql_expr::tf2ae8d5f5e1b34f3177f49c9abffb1b8 // Largest
> { using variant::variant; };

enum Constr_ta224f9c3db1110a4377a7bc09d90f61d {
  MultiLinReg,
  Largest,
};

inline std::ostream &operator<<(std::ostream &os, ta224f9c3db1110a4377a7bc09d90f61d const &v) {
  switch (v.index()) {
    case 0: os << "MultiLinReg " << std::get<0>(v); break;
    case 1: os << "Largest " << std::get<1>(v); break;
  }
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct tb4eb57575e7c623634bbff5329b1a217 : public std::tuple<
  ::dessser::gen::raql_expr::ta224f9c3db1110a4377a7bc09d90f61d,
  t*,
  t*,
  t*,
  Lst<t*>
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, tb4eb57575e7c623634bbff5329b1a217 const &t) {
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t6b77256fcb81f65e6f93d323c46fc1f9 : public std::tuple<
  ::dessser::gen::raql_expr::ta020e7823506dcf58037dc373380c189,
  t*,
  t*,
  t*,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t6b77256fcb81f65e6f93d323c46fc1f9 const &t) {
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
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct tb31124d338e87bfd847b1eb902308416 {
  t* by;
  t* duration;
  std::optional<t*> max_size;
  dessser::gen::raql_top_output::t_ext output;
  t* sigmas;
  t* size;
  t* Top_time;
  t* Top_what;
  tb31124d338e87bfd847b1eb902308416(t* by_, t* duration_, std::optional<t*> max_size_, dessser::gen::raql_top_output::t_ext output_, t* sigmas_, t* size_, t* Top_time_, t* Top_what_) : by(by_), duration(duration_), max_size(max_size_), output(output_), sigmas(sigmas_), size(size_), Top_time(Top_time_), Top_what(Top_what_) {}
  tb31124d338e87bfd847b1eb902308416() = default;
  bool operator==(tb31124d338e87bfd847b1eb902308416 const &other) const {
    return by == other.by && duration == other.duration && max_size == other.max_size && output == other.output && sigmas == other.sigmas && size == other.size && Top_time == other.Top_time && Top_what == other.Top_what;
  }
};
inline std::ostream &operator<<(std::ostream &os, tb31124d338e87bfd847b1eb902308416 const &r) {
  os << '{';
  os << "by:" << *r.by << ',';
  os << "duration:" << *r.duration << ',';
  os << "max_size:" << *r.max_size << ',';
  os << "output:" << r.output << ',';
  os << "sigmas:" << *r.sigmas << ',';
  os << "size:" << *r.size << ',';
  os << "Top_time:" << *r.Top_time << ',';
  os << "Top_what:" << *r.Top_what;
  os << '}';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct tfca66c554695a68c8dec4088f30f0894 {
  t* max_age;
  std::optional<t*> sample_size;
  t* time;
  bool tumbling;
  t* what;
  tfca66c554695a68c8dec4088f30f0894(t* max_age_, std::optional<t*> sample_size_, t* time_, bool tumbling_, t* what_) : max_age(max_age_), sample_size(sample_size_), time(time_), tumbling(tumbling_), what(what_) {}
  tfca66c554695a68c8dec4088f30f0894() = default;
  bool operator==(tfca66c554695a68c8dec4088f30f0894 const &other) const {
    return max_age == other.max_age && sample_size == other.sample_size && time == other.time && tumbling == other.tumbling && what == other.what;
  }
};
inline std::ostream &operator<<(std::ostream &os, tfca66c554695a68c8dec4088f30f0894 const &r) {
  os << '{';
  os << "max_age:" << *r.max_age << ',';
  os << "sample_size:" << *r.sample_size << ',';
  os << "time:" << *r.time << ',';
  os << "tumbling:" << r.tumbling << ',';
  os << "what:" << *r.what;
  os << '}';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t4245a93299b7c11e1cfcaddef6d823f9 : public std::variant<
  ::dessser::gen::raql_expr::t797b5289cecf30b53b722bff0d1083a8, // SF1
  ::dessser::gen::raql_expr::tab0dcdfe0a2d58ff7fba6f4496f1629d, // SF2
  ::dessser::gen::raql_expr::t680c3184893bd6b56c0f5481ac3d4cb6, // SF3
  ::dessser::gen::raql_expr::t801b86950988d4a9ab0f917a16c686fa, // SF4
  ::dessser::gen::raql_expr::tb4eb57575e7c623634bbff5329b1a217, // SF4s
  ::dessser::gen::raql_expr::t6b77256fcb81f65e6f93d323c46fc1f9, // SF6
  ::dessser::gen::raql_expr::tb31124d338e87bfd847b1eb902308416, // Top
  ::dessser::gen::raql_expr::tfca66c554695a68c8dec4088f30f0894 // Past
> { using variant::variant; };

enum Constr_t4245a93299b7c11e1cfcaddef6d823f9 {
  SF1,
  SF2,
  SF3,
  SF4,
  SF4s,
  SF6,
  Top,
  Past,
};

inline std::ostream &operator<<(std::ostream &os, t4245a93299b7c11e1cfcaddef6d823f9 const &v) {
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t6b39e3f74b6636396258bc56974b2612 : public std::tuple<
  ::dessser::gen::raql_expr::t9aeb08fceb6eb1d5796a64c8fddd436c,
  bool,
  ::dessser::gen::raql_expr::t4245a93299b7c11e1cfcaddef6d823f9
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t6b39e3f74b6636396258bc56974b2612 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  t*,
  t*
> t7411897bdb6c9b6e00a01b4eb6506ccf;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t9fb75ec5c85706195b12b035eb776a06 : public std::variant<
  ::dessser::gen::raql_expr::t7411897bdb6c9b6e00a01b4eb6506ccf // Split
> { using variant::variant; };

enum Constr_t9fb75ec5c85706195b12b035eb776a06 {
  Split,
};

inline std::ostream &operator<<(std::ostream &os, t9fb75ec5c85706195b12b035eb776a06 const &v) {
  switch (v.index()) {
    case 0: os << "Split " << std::get<0>(v); break;
  }
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct tcd2efd1f3cea61fc14fa325fd3ec62af : public std::variant<
  Lst<t*>, // Tuple
  Lst<::dessser::gen::raql_expr::t5b91ba1a37fd19816559f3dabb32e8b5>, // Record
  Lst<t*>, // Vector
  ::dessser::gen::raql_expr::te3216971987147b926d84139da428868, // Case
  ::dessser::gen::raql_expr::t9dca13408164b9b878af2f494a648c1a, // Stateless
  ::dessser::gen::raql_expr::t6b39e3f74b6636396258bc56974b2612, // Stateful
  ::dessser::gen::raql_expr::t9fb75ec5c85706195b12b035eb776a06 // Generator
> { using variant::variant; };

enum Constr_tcd2efd1f3cea61fc14fa325fd3ec62af {
  Tuple,
  Record,
  Vector,
  Case,
  Stateless,
  Stateful,
  Generator,
};

inline std::ostream &operator<<(std::ostream &os, tcd2efd1f3cea61fc14fa325fd3ec62af const &v) {
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t {
  ::dessser::gen::raql_expr::tcd2efd1f3cea61fc14fa325fd3ec62af text;
  dessser::gen::raql_type::t_ext typ;
  uint32_t uniq_num;
  std::optional<dessser::gen::units::t_ext> units;
  t(::dessser::gen::raql_expr::tcd2efd1f3cea61fc14fa325fd3ec62af text_, dessser::gen::raql_type::t_ext typ_, uint32_t uniq_num_, std::optional<dessser::gen::units::t_ext> units_) : text(text_), typ(typ_), uniq_num(uniq_num_), units(units_) {}
  t() = default;
  bool operator==(t const &other) const {
    return text == other.text && typ == other.typ && uniq_num == other.uniq_num && units == other.units;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "text:" << r.text << ',';
  os << "typ:" << r.typ << ',';
  os << "uniq_num:" << r.uniq_num << ',';
  os << "units:" << r.units;
  os << '}';
  return os;
}

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  ::dessser::gen::raql_expr::t*,
  Pointer
> t5fc112a96748292611657700222a91a6;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_expr::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_expr::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_expr::t5fc112a96748292611657700222a91a6(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
