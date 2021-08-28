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
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  uint32_t,
  t*
> t9327d6336842c469509b67056a719df9;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
typedef std::tuple<
  std::string,
  t*
> t100b7e5cf4b9a621db7a39d7f1d01e5c;

struct t;
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
  t*,
  t*
> t7411897bdb6c9b6e00a01b4eb6506ccf;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t7edd9b800f08d2150fbb22ba595bb370 : public std::variant<
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
  ::dessser::gen::raql_type::t9327d6336842c469509b67056a719df9, // Vec
  t*, // Arr
  Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c>, // Rec
  Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c>, // Sum
  ::dessser::gen::raql_type::t7411897bdb6c9b6e00a01b4eb6506ccf // Map
> { using variant::variant; };

enum Constr_t7edd9b800f08d2150fbb22ba595bb370 {
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

inline std::ostream &operator<<(std::ostream &os, t7edd9b800f08d2150fbb22ba595bb370 const &v) {
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
    case 32: os << "Arr " << *std::get<32>(v); break;
    case 33: os << "Rec " << std::get<33>(v); break;
    case 34: os << "Sum " << std::get<34>(v); break;
    case 35: os << "Map " << std::get<35>(v); break;
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
struct t {
  bool nullable;
  ::dessser::gen::raql_type::t7edd9b800f08d2150fbb22ba595bb370 type;
  bool operator==(t const &other) const {
    return nullable == other.nullable && type == other.type;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "nullable:" << r.nullable << ',';
  os << "type:" << r.type;
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
typedef std::tuple<
  ::dessser::gen::raql_type::t*,
  Pointer
> tfafddb6af18e2fa33b782eb359ee7c77;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_type::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_type::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_type::tfafddb6af18e2fa33b782eb359ee7c77(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
