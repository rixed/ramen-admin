#ifndef DESSSER_GEN_raql_value
#define DESSSER_GEN_raql_value
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_value {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tb689860ac91fca7822797a026958e891 : public std::variant<
  uint32_t, // v4
  uint128_t // v6
> { using variant::variant; };

enum Constr_tb689860ac91fca7822797a026958e891 {
  Ip_v4,
  Ip_v6,
};

inline bool operator==(tb689860ac91fca7822797a026958e891 const &a, tb689860ac91fca7822797a026958e891 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // v4
    case 1: return std::get<1>(a) == std::get<1>(b); // v6
  };
  return false;
}
inline bool operator!=(tb689860ac91fca7822797a026958e891 const &a, tb689860ac91fca7822797a026958e891 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tb689860ac91fca7822797a026958e891 const &v) {
  switch (v.index()) {
    case 0: os << "v4 " << std::get<0>(v); break;
    case 1: os << "v6 " << std::get<1>(v); break;
  }
  return os;
}

struct t81f779acbcb9180b1df9b88e2d8ce982 {
  uint32_t Cidr4_ip;
  uint8_t Cidr4_mask;
  t81f779acbcb9180b1df9b88e2d8ce982(uint32_t Cidr4_ip_, uint8_t Cidr4_mask_) : Cidr4_ip(Cidr4_ip_), Cidr4_mask(Cidr4_mask_) {}
  t81f779acbcb9180b1df9b88e2d8ce982() = default;
};
inline std::ostream &operator<<(std::ostream &os, t81f779acbcb9180b1df9b88e2d8ce982 const &r) {
  os << '{';
  os << "Cidr4_ip:" << r.Cidr4_ip << ',';
  os << "Cidr4_mask:" << r.Cidr4_mask;
  os << '}';
  return os;
}
inline bool operator==(t81f779acbcb9180b1df9b88e2d8ce982 const &a, t81f779acbcb9180b1df9b88e2d8ce982 const &b) {
  return a.Cidr4_ip == b.Cidr4_ip && a.Cidr4_mask == b.Cidr4_mask;
}

inline bool operator!=(t81f779acbcb9180b1df9b88e2d8ce982 const &a, t81f779acbcb9180b1df9b88e2d8ce982 const &b) {
  return !operator==(a, b);
}
struct t8d4af754051624596ec1687a64e3bf86 {
  uint128_t ip;
  uint8_t mask;
  t8d4af754051624596ec1687a64e3bf86(uint128_t ip_, uint8_t mask_) : ip(ip_), mask(mask_) {}
  t8d4af754051624596ec1687a64e3bf86() = default;
};
inline std::ostream &operator<<(std::ostream &os, t8d4af754051624596ec1687a64e3bf86 const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "mask:" << r.mask;
  os << '}';
  return os;
}
inline bool operator==(t8d4af754051624596ec1687a64e3bf86 const &a, t8d4af754051624596ec1687a64e3bf86 const &b) {
  return a.ip == b.ip && a.mask == b.mask;
}

inline bool operator!=(t8d4af754051624596ec1687a64e3bf86 const &a, t8d4af754051624596ec1687a64e3bf86 const &b) {
  return !operator==(a, b);
}
struct t086a8e00718450baf3e88e60b5e42a27 : public std::variant<
  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982, // v4
  ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 // v6
> { using variant::variant; };

enum Constr_t086a8e00718450baf3e88e60b5e42a27 {
  v4,
  v6,
};

inline bool operator==(t086a8e00718450baf3e88e60b5e42a27 const &a, t086a8e00718450baf3e88e60b5e42a27 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // v4
    case 1: return std::get<1>(a) == std::get<1>(b); // v6
  };
  return false;
}
inline bool operator!=(t086a8e00718450baf3e88e60b5e42a27 const &a, t086a8e00718450baf3e88e60b5e42a27 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t086a8e00718450baf3e88e60b5e42a27 const &v) {
  switch (v.index()) {
    case 0: os << "v4 " << std::get<0>(v); break;
    case 1: os << "v6 " << std::get<1>(v); break;
  }
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
typedef std::tuple<
  std::string,
  t*
> t100b7e5cf4b9a621db7a39d7f1d01e5c;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
typedef std::tuple<
  t*,
  t*
> t7411897bdb6c9b6e00a01b4eb6506ccf;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t : public std::variant<
  Void, // VNull
  Void, // VUnit
  double, // VFloat
  std::string, // VString
  bool, // VBool
  char, // VChar
  uint8_t, // VU8
  uint16_t, // VU16
  uint32_t, // VU24
  uint32_t, // VU32
  uint64_t, // VU40
  uint64_t, // VU48
  uint64_t, // VU56
  uint64_t, // VU64
  uint128_t, // VU128
  int8_t, // VI8
  int16_t, // VI16
  int32_t, // VI24
  int32_t, // VI32
  int64_t, // VI40
  int64_t, // VI48
  int64_t, // VI56
  int64_t, // VI64
  int128_t, // VI128
  uint64_t, // VEth
  uint32_t, // VIpv4
  uint128_t, // VIpv6
  ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891, // VIp
  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982, // VCidrv4
  ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86, // VCidrv6
  ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27, // VCidr
  Arr<t*>, // VTup
  Arr<t*>, // VVec
  Arr<t*>, // VLst
  Arr<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c>, // VRec
  Arr<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> // VMap
> { using variant::variant; };

enum Constr_t {
  VNull,
  VUnit,
  VFloat,
  VString,
  VBool,
  VChar,
  VU8,
  VU16,
  VU24,
  VU32,
  VU40,
  VU48,
  VU56,
  VU64,
  VU128,
  VI8,
  VI16,
  VI24,
  VI32,
  VI40,
  VI48,
  VI56,
  VI64,
  VI128,
  VEth,
  VIpv4,
  VIpv6,
  VIp,
  VCidrv4,
  VCidrv6,
  VCidr,
  VTup,
  VVec,
  VLst,
  VRec,
  VMap,
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // VNull
    case 1: return std::get<1>(a) == std::get<1>(b); // VUnit
    case 2: return std::get<2>(a) == std::get<2>(b); // VFloat
    case 3: return std::get<3>(a) == std::get<3>(b); // VString
    case 4: return std::get<4>(a) == std::get<4>(b); // VBool
    case 5: return std::get<5>(a) == std::get<5>(b); // VChar
    case 6: return std::get<6>(a) == std::get<6>(b); // VU8
    case 7: return std::get<7>(a) == std::get<7>(b); // VU16
    case 8: return std::get<8>(a) == std::get<8>(b); // VU24
    case 9: return std::get<9>(a) == std::get<9>(b); // VU32
    case 10: return std::get<10>(a) == std::get<10>(b); // VU40
    case 11: return std::get<11>(a) == std::get<11>(b); // VU48
    case 12: return std::get<12>(a) == std::get<12>(b); // VU56
    case 13: return std::get<13>(a) == std::get<13>(b); // VU64
    case 14: return std::get<14>(a) == std::get<14>(b); // VU128
    case 15: return std::get<15>(a) == std::get<15>(b); // VI8
    case 16: return std::get<16>(a) == std::get<16>(b); // VI16
    case 17: return std::get<17>(a) == std::get<17>(b); // VI24
    case 18: return std::get<18>(a) == std::get<18>(b); // VI32
    case 19: return std::get<19>(a) == std::get<19>(b); // VI40
    case 20: return std::get<20>(a) == std::get<20>(b); // VI48
    case 21: return std::get<21>(a) == std::get<21>(b); // VI56
    case 22: return std::get<22>(a) == std::get<22>(b); // VI64
    case 23: return std::get<23>(a) == std::get<23>(b); // VI128
    case 24: return std::get<24>(a) == std::get<24>(b); // VEth
    case 25: return std::get<25>(a) == std::get<25>(b); // VIpv4
    case 26: return std::get<26>(a) == std::get<26>(b); // VIpv6
    case 27: return std::get<27>(a) == std::get<27>(b); // VIp
    case 28: return std::get<28>(a) == std::get<28>(b); // VCidrv4
    case 29: return std::get<29>(a) == std::get<29>(b); // VCidrv6
    case 30: return std::get<30>(a) == std::get<30>(b); // VCidr
    case 31: return std::get<31>(a) == std::get<31>(b); // VTup
    case 32: return std::get<32>(a) == std::get<32>(b); // VVec
    case 33: return std::get<33>(a) == std::get<33>(b); // VLst
    case 34: return std::get<34>(a) == std::get<34>(b); // VRec
    case 35: return std::get<35>(a) == std::get<35>(b); // VMap
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "VNull " << std::get<0>(v); break;
    case 1: os << "VUnit " << std::get<1>(v); break;
    case 2: os << "VFloat " << std::get<2>(v); break;
    case 3: os << "VString " << std::get<3>(v); break;
    case 4: os << "VBool " << std::get<4>(v); break;
    case 5: os << "VChar " << std::get<5>(v); break;
    case 6: os << "VU8 " << std::get<6>(v); break;
    case 7: os << "VU16 " << std::get<7>(v); break;
    case 8: os << "VU24 " << std::get<8>(v); break;
    case 9: os << "VU32 " << std::get<9>(v); break;
    case 10: os << "VU40 " << std::get<10>(v); break;
    case 11: os << "VU48 " << std::get<11>(v); break;
    case 12: os << "VU56 " << std::get<12>(v); break;
    case 13: os << "VU64 " << std::get<13>(v); break;
    case 14: os << "VU128 " << std::get<14>(v); break;
    case 15: os << "VI8 " << std::get<15>(v); break;
    case 16: os << "VI16 " << std::get<16>(v); break;
    case 17: os << "VI24 " << std::get<17>(v); break;
    case 18: os << "VI32 " << std::get<18>(v); break;
    case 19: os << "VI40 " << std::get<19>(v); break;
    case 20: os << "VI48 " << std::get<20>(v); break;
    case 21: os << "VI56 " << std::get<21>(v); break;
    case 22: os << "VI64 " << std::get<22>(v); break;
    case 23: os << "VI128 " << std::get<23>(v); break;
    case 24: os << "VEth " << std::get<24>(v); break;
    case 25: os << "VIpv4 " << std::get<25>(v); break;
    case 26: os << "VIpv6 " << std::get<26>(v); break;
    case 27: os << "VIp " << std::get<27>(v); break;
    case 28: os << "VCidrv4 " << std::get<28>(v); break;
    case 29: os << "VCidrv6 " << std::get<29>(v); break;
    case 30: os << "VCidr " << std::get<30>(v); break;
    case 31: os << "VTup " << std::get<31>(v); break;
    case 32: os << "VVec " << std::get<32>(v); break;
    case 33: os << "VLst " << std::get<33>(v); break;
    case 34: os << "VRec " << std::get<34>(v); break;
    case 35: os << "VMap " << std::get<35>(v); break;
  }
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
typedef std::tuple<
  ::dessser::gen::raql_value::t*,
  Pointer
> t85eb9b4ae6397e976e7bd6d60235f8d0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_value::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_value::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
