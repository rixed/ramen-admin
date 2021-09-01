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

inline std::ostream &operator<<(std::ostream &os, tb689860ac91fca7822797a026958e891 const &v) {
  switch (v.index()) {
    case 0: os << "v4 " << std::get<0>(v); break;
    case 1: os << "v6 " << std::get<1>(v); break;
  }
  return os;
}

struct t7ccce890087e1d1590c7df50bbb5dedc {
  uint32_t Cidr4_ip;
  uint8_t Cidr4_mask;
  t7ccce890087e1d1590c7df50bbb5dedc(uint32_t Cidr4_ip_, uint8_t Cidr4_mask_) : Cidr4_ip(Cidr4_ip_), Cidr4_mask(Cidr4_mask_) {}
  t7ccce890087e1d1590c7df50bbb5dedc() = default;
  bool operator==(t7ccce890087e1d1590c7df50bbb5dedc const &other) const {
    return Cidr4_ip == other.Cidr4_ip && Cidr4_mask == other.Cidr4_mask;
  }
};
inline std::ostream &operator<<(std::ostream &os, t7ccce890087e1d1590c7df50bbb5dedc const &r) {
  os << '{';
  os << "Cidr4_ip:" << r.Cidr4_ip << ',';
  os << "Cidr4_mask:" << r.Cidr4_mask;
  os << '}';
  return os;
}

struct t7d6e94f701896afa22229dc87f5225a1 {
  uint128_t ip;
  uint8_t mask;
  t7d6e94f701896afa22229dc87f5225a1(uint128_t ip_, uint8_t mask_) : ip(ip_), mask(mask_) {}
  t7d6e94f701896afa22229dc87f5225a1() = default;
  bool operator==(t7d6e94f701896afa22229dc87f5225a1 const &other) const {
    return ip == other.ip && mask == other.mask;
  }
};
inline std::ostream &operator<<(std::ostream &os, t7d6e94f701896afa22229dc87f5225a1 const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "mask:" << r.mask;
  os << '}';
  return os;
}

struct tbb8f59fe54579f629154765675a23df7 : public std::variant<
  ::dessser::gen::raql_value::t7ccce890087e1d1590c7df50bbb5dedc, // v4
  ::dessser::gen::raql_value::t7d6e94f701896afa22229dc87f5225a1 // v6
> { using variant::variant; };

enum Constr_tbb8f59fe54579f629154765675a23df7 {
  v4,
  v6,
};

inline std::ostream &operator<<(std::ostream &os, tbb8f59fe54579f629154765675a23df7 const &v) {
  switch (v.index()) {
    case 0: os << "v4 " << std::get<0>(v); break;
    case 1: os << "v6 " << std::get<1>(v); break;
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
  ::dessser::gen::raql_value::t7ccce890087e1d1590c7df50bbb5dedc, // VCidrv4
  ::dessser::gen::raql_value::t7d6e94f701896afa22229dc87f5225a1, // VCidrv6
  ::dessser::gen::raql_value::tbb8f59fe54579f629154765675a23df7, // VCidr
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
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
struct t;
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

}
#endif
