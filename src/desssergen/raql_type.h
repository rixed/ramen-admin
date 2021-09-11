#ifndef DESSSER_GEN_raql_type
#define DESSSER_GEN_raql_type
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_type {
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
struct t10100248e19259cc9062c9adb9a823a2 : public std::tuple<
  uint32_t,
  t*
> {
  using tuple::tuple;
  t10100248e19259cc9062c9adb9a823a2(std::tuple<uint32_t, t*> p)
    : std::tuple<uint32_t, t*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t10100248e19259cc9062c9adb9a823a2 const &a, t10100248e19259cc9062c9adb9a823a2 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t10100248e19259cc9062c9adb9a823a2 const &a, t10100248e19259cc9062c9adb9a823a2 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t10100248e19259cc9062c9adb9a823a2 const &t) {
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
struct t283d6c4a825a1e3b55be4835188780e8 : public std::tuple<
  std::string,
  t*
> {
  using tuple::tuple;
  t283d6c4a825a1e3b55be4835188780e8(std::tuple<std::string, t*> p)
    : std::tuple<std::string, t*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t283d6c4a825a1e3b55be4835188780e8 const &a, t283d6c4a825a1e3b55be4835188780e8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t283d6c4a825a1e3b55be4835188780e8 const &a, t283d6c4a825a1e3b55be4835188780e8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t283d6c4a825a1e3b55be4835188780e8 const &t) {
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
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t7dd54d9ebb0c0adfc41ece982c59e1a6 : public std::variant<
  Void, // Void
  Void, // Bool
  Void, // Char
  Void, // Float
  Void, // String
  Void, // U8
  Void, // U16
  Void, // U24
  Void, // U32
  Void, // U40
  Void, // U48
  Void, // U56
  Void, // U64
  Void, // U128
  Void, // I8
  Void, // I16
  Void, // I24
  Void, // I32
  Void, // I40
  Void, // I48
  Void, // I56
  Void, // I64
  Void, // I128
  Void, // Eth
  Void, // Ipv4
  Void, // Ipv6
  Void, // Ip
  Void, // Cidrv4
  Void, // Cidrv6
  Void, // Cidr
  Arr<t*>, // Tup
  ::dessser::gen::raql_type::t10100248e19259cc9062c9adb9a823a2, // Vec
  t*, // Arr
  Arr<::dessser::gen::raql_type::t283d6c4a825a1e3b55be4835188780e8>, // Rec
  Arr<::dessser::gen::raql_type::t283d6c4a825a1e3b55be4835188780e8>, // Sum
  ::dessser::gen::raql_type::t904326184a165aa7b5c8e6ffafa090a8 // Map
> { using variant::variant; };

enum Constr_t7dd54d9ebb0c0adfc41ece982c59e1a6 {
  Void,
  Bool,
  Char,
  Float,
  String,
  U8,
  U16,
  U24,
  U32,
  U40,
  U48,
  U56,
  U64,
  U128,
  I8,
  I16,
  I24,
  I32,
  I40,
  I48,
  I56,
  I64,
  I128,
  Eth,
  Ipv4,
  Ipv6,
  Ip,
  Cidrv4,
  Cidrv6,
  Cidr,
  Tup,
  Vec,
  Arr,
  Rec,
  Sum,
  Map,
};

inline std::ostream &operator<<(std::ostream &os, t7dd54d9ebb0c0adfc41ece982c59e1a6 const &v) {
  switch (v.index()) {
    case 0: os << "Void " << std::get<0>(v); break;
    case 1: os << "Bool " << std::get<1>(v); break;
    case 2: os << "Char " << std::get<2>(v); break;
    case 3: os << "Float " << std::get<3>(v); break;
    case 4: os << "String " << std::get<4>(v); break;
    case 5: os << "U8 " << std::get<5>(v); break;
    case 6: os << "U16 " << std::get<6>(v); break;
    case 7: os << "U24 " << std::get<7>(v); break;
    case 8: os << "U32 " << std::get<8>(v); break;
    case 9: os << "U40 " << std::get<9>(v); break;
    case 10: os << "U48 " << std::get<10>(v); break;
    case 11: os << "U56 " << std::get<11>(v); break;
    case 12: os << "U64 " << std::get<12>(v); break;
    case 13: os << "U128 " << std::get<13>(v); break;
    case 14: os << "I8 " << std::get<14>(v); break;
    case 15: os << "I16 " << std::get<15>(v); break;
    case 16: os << "I24 " << std::get<16>(v); break;
    case 17: os << "I32 " << std::get<17>(v); break;
    case 18: os << "I40 " << std::get<18>(v); break;
    case 19: os << "I48 " << std::get<19>(v); break;
    case 20: os << "I56 " << std::get<20>(v); break;
    case 21: os << "I64 " << std::get<21>(v); break;
    case 22: os << "I128 " << std::get<22>(v); break;
    case 23: os << "Eth " << std::get<23>(v); break;
    case 24: os << "Ipv4 " << std::get<24>(v); break;
    case 25: os << "Ipv6 " << std::get<25>(v); break;
    case 26: os << "Ip " << std::get<26>(v); break;
    case 27: os << "Cidrv4 " << std::get<27>(v); break;
    case 28: os << "Cidrv6 " << std::get<28>(v); break;
    case 29: os << "Cidr " << std::get<29>(v); break;
    case 30: os << "Tup " << std::get<30>(v); break;
    case 31: os << "Vec " << std::get<31>(v); break;
    case 32: os << "Arr " << (*std::get<32>(v)); break;
    case 33: os << "Rec " << std::get<33>(v); break;
    case 34: os << "Sum " << std::get<34>(v); break;
    case 35: os << "Map " << std::get<35>(v); break;
  }
  return os;
}

inline bool operator==(t7dd54d9ebb0c0adfc41ece982c59e1a6 const &a, t7dd54d9ebb0c0adfc41ece982c59e1a6 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Void
    case 1: return std::get<1>(a) == std::get<1>(b); // Bool
    case 2: return std::get<2>(a) == std::get<2>(b); // Char
    case 3: return std::get<3>(a) == std::get<3>(b); // Float
    case 4: return std::get<4>(a) == std::get<4>(b); // String
    case 5: return std::get<5>(a) == std::get<5>(b); // U8
    case 6: return std::get<6>(a) == std::get<6>(b); // U16
    case 7: return std::get<7>(a) == std::get<7>(b); // U24
    case 8: return std::get<8>(a) == std::get<8>(b); // U32
    case 9: return std::get<9>(a) == std::get<9>(b); // U40
    case 10: return std::get<10>(a) == std::get<10>(b); // U48
    case 11: return std::get<11>(a) == std::get<11>(b); // U56
    case 12: return std::get<12>(a) == std::get<12>(b); // U64
    case 13: return std::get<13>(a) == std::get<13>(b); // U128
    case 14: return std::get<14>(a) == std::get<14>(b); // I8
    case 15: return std::get<15>(a) == std::get<15>(b); // I16
    case 16: return std::get<16>(a) == std::get<16>(b); // I24
    case 17: return std::get<17>(a) == std::get<17>(b); // I32
    case 18: return std::get<18>(a) == std::get<18>(b); // I40
    case 19: return std::get<19>(a) == std::get<19>(b); // I48
    case 20: return std::get<20>(a) == std::get<20>(b); // I56
    case 21: return std::get<21>(a) == std::get<21>(b); // I64
    case 22: return std::get<22>(a) == std::get<22>(b); // I128
    case 23: return std::get<23>(a) == std::get<23>(b); // Eth
    case 24: return std::get<24>(a) == std::get<24>(b); // Ipv4
    case 25: return std::get<25>(a) == std::get<25>(b); // Ipv6
    case 26: return std::get<26>(a) == std::get<26>(b); // Ip
    case 27: return std::get<27>(a) == std::get<27>(b); // Cidrv4
    case 28: return std::get<28>(a) == std::get<28>(b); // Cidrv6
    case 29: return std::get<29>(a) == std::get<29>(b); // Cidr
    case 30: return std::get<30>(a) == std::get<30>(b); // Tup
    case 31: return std::get<31>(a) == std::get<31>(b); // Vec
    case 32: return (*std::get<32>(a)) == (*std::get<32>(b)); // Arr
    case 33: return std::get<33>(a) == std::get<33>(b); // Rec
    case 34: return std::get<34>(a) == std::get<34>(b); // Sum
    case 35: return std::get<35>(a) == std::get<35>(b); // Map
  };
  return false;
}
inline bool operator!=(t7dd54d9ebb0c0adfc41ece982c59e1a6 const &a, t7dd54d9ebb0c0adfc41ece982c59e1a6 const &b) {
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
struct t {
  bool nullable;
  ::dessser::gen::raql_type::t7dd54d9ebb0c0adfc41ece982c59e1a6 type;
  t(bool nullable_, ::dessser::gen::raql_type::t7dd54d9ebb0c0adfc41ece982c59e1a6 type_) : nullable(nullable_), type(type_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "nullable:" << r.nullable << ',';
  os << "type:" << r.type;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.nullable == b.nullable && a.type == b.type;
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
struct t8cf8d4a14dfed6b2cbd585598476a47b : public std::tuple<
  ::dessser::gen::raql_type::t*,
  Pointer
> {
  using tuple::tuple;
  t8cf8d4a14dfed6b2cbd585598476a47b(std::tuple<::dessser::gen::raql_type::t*, Pointer> p)
    : std::tuple<::dessser::gen::raql_type::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8cf8d4a14dfed6b2cbd585598476a47b const &a, t8cf8d4a14dfed6b2cbd585598476a47b const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8cf8d4a14dfed6b2cbd585598476a47b const &a, t8cf8d4a14dfed6b2cbd585598476a47b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t8cf8d4a14dfed6b2cbd585598476a47b const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_type::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_type::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_type::t8cf8d4a14dfed6b2cbd585598476a47b(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
