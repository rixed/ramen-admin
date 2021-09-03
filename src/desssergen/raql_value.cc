#include <algorithm>
#include <arpa/inet.h>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <random>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>
#include "dessser/runtime.h"


namespace dessser::gen::raql_value {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct tb689860ac91fca7822797a026958e891 : public std::variant<
  uint32_t, // v4
  uint128_t // v6
> { using variant::variant; };

struct t81f779acbcb9180b1df9b88e2d8ce982 {
  uint32_t Cidr4_ip;
  uint8_t Cidr4_mask;
  t81f779acbcb9180b1df9b88e2d8ce982(uint32_t Cidr4_ip_, uint8_t Cidr4_mask_) : Cidr4_ip(Cidr4_ip_), Cidr4_mask(Cidr4_mask_) {}
  t81f779acbcb9180b1df9b88e2d8ce982() = default;
};
struct t8d4af754051624596ec1687a64e3bf86 {
  uint128_t ip;
  uint8_t mask;
  t8d4af754051624596ec1687a64e3bf86(uint128_t ip_, uint8_t mask_) : ip(ip_), mask(mask_) {}
  t8d4af754051624596ec1687a64e3bf86() = default;
};
struct t086a8e00718450baf3e88e60b5e42a27 : public std::variant<
  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982, // v4
  ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 // v6
> { using variant::variant; };

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  uint128_t,
  Pointer
> t5d72eb1f6edf58d2d6a63eca47034564;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891,
  Pointer
> t3112ad7e709a70a40b86a8e67d6eb121;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27,
  Pointer
> t07c6ba94ebc3c46bea9b5d748e096901;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  Lst<t*>,
  Pointer
> tff7ae6104a72ec7dfd0a80e3a42a8548;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  Lst<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c>,
  Pointer
> t3e9183f42423fa301e184f85283e3582;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
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
  Lst<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf>,
  Pointer
> tf4ebf93395ce1142f131bdef5e190b87;

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" "Ptr")
      (let "label1_569" (label-of (param 0))
        (let "ssum_dst_570" (write-u16 little-endian (param 1) (identifier "label1_569"))
          (if (eq (u16 0) (identifier "label1_569")) (identifier "ssum_dst_570")
            (if (eq (u16 1) (identifier "label1_569")) (identifier "ssum_dst_570")
              (if (eq (u16 2) (identifier "label1_569")) (write-u64 little-endian (identifier "ssum_dst_570") (u64-of-float (get-alt "VFloat" (param 0))))
                (if (eq (u16 3) (identifier "label1_569"))
                  (write-bytes
                    (let "leb128_sz_610" (make-vec (string-length (get-alt "VString" (param 0))))
                      (let "leb128_ptr_611" (make-vec (identifier "ssum_dst_570"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_611")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_611"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_610"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_610"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_610"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_610") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_610")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_610")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_611"))))) 
                    (bytes-of-string (get-alt "VString" (param 0))))
                  (if (eq (u16 4) (identifier "label1_569")) (write-u8 (identifier "ssum_dst_570") (u8-of-bool (get-alt "VBool" (param 0))))
                    (if (eq (u16 5) (identifier "label1_569")) (write-u8 (identifier "ssum_dst_570") (u8-of-char (get-alt "VChar" (param 0))))
                      (if (eq (u16 6) (identifier "label1_569")) (write-u8 (identifier "ssum_dst_570") (get-alt "VU8" (param 0)))
                        (if (eq (u16 7) (identifier "label1_569")) (write-u16 little-endian (identifier "ssum_dst_570") (get-alt "VU16" (param 0)))
                          (if (eq (u16 8) (identifier "label1_569")) 
                            (write-u32 little-endian (identifier "ssum_dst_570") (to-u32 (get-alt "VU24" (param 0))))
                            (if (eq (u16 9) (identifier "label1_569")) 
                              (write-u32 little-endian (identifier "ssum_dst_570") (get-alt "VU32" (param 0)))
                              (if (eq (u16 10) (identifier "label1_569")) 
                                (write-u64 little-endian (identifier "ssum_dst_570") (to-u64 (get-alt "VU40" (param 0))))
                                (if (eq (u16 11) (identifier "label1_569")) 
                                  (write-u64 little-endian (identifier "ssum_dst_570") (to-u64 (get-alt "VU48" (param 0))))
                                  (if (eq (u16 12) (identifier "label1_569")) 
                                    (write-u64 little-endian (identifier "ssum_dst_570") (to-u64 (get-alt "VU56" (param 0))))
                                    (if (eq (u16 13) (identifier "label1_569")) 
                                      (write-u64 little-endian (identifier "ssum_dst_570") (get-alt "VU64" (param 0)))
                                      (if (eq (u16 14) (identifier "label1_569")) 
                                        (write-u128 little-endian (identifier "ssum_dst_570") (get-alt "VU128" (param 0)))
                                        (if (eq (u16 15) (identifier "label1_569")) 
                                          (write-u8 (identifier "ssum_dst_570") (to-u8 (get-alt "VI8" (param 0))))
                                          (if (eq (u16 16) (identifier "label1_569")) 
                                            (write-u16 little-endian (identifier "ssum_dst_570") (to-u16 (get-alt "VI16" (param 0))))
                                            (if (eq (u16 17) (identifier "label1_569")) 
                                              (write-u32 little-endian (identifier "ssum_dst_570") (to-u32 (to-i32 (get-alt "VI24" (param 0)))))
                                              (if (eq (u16 18) (identifier "label1_569")) 
                                                (write-u32 little-endian (identifier "ssum_dst_570") (to-u32 (get-alt "VI32" (param 0))))
                                                (if (eq (u16 19) (identifier "label1_569")) 
                                                  (write-u64 little-endian (identifier "ssum_dst_570") (to-u64 (to-i64 (get-alt "VI40" (param 0)))))
                                                  (if (eq (u16 20) (identifier "label1_569")) 
                                                    (write-u64 little-endian (identifier "ssum_dst_570") (to-u64 (to-i64 (get-alt "VI48" (param 0)))))
                                                    (if (eq (u16 21) (identifier "label1_569")) 
                                                      (write-u64 little-endian (identifier "ssum_dst_570") (to-u64 (to-i64 (get-alt "VI56" (param 0)))))
                                                      (if (eq (u16 22) (identifier "label1_569")) 
                                                        (write-u64 little-endian (identifier "ssum_dst_570") (to-u64 (get-alt "VI64" (param 0))))
                                                        (if (eq (u16 23) (identifier "label1_569")) 
                                                          (write-u128 little-endian (identifier "ssum_dst_570") (to-u128 (get-alt "VI128" (param 0))))
                                                          (if (eq (u16 24) (identifier "label1_569")) 
                                                            (write-u64 little-endian (identifier "ssum_dst_570") (to-u64 (get-alt "VEth" (param 0))))
                                                            (if (eq (u16 25) (identifier "label1_569")) 
                                                              (write-u32 little-endian (identifier "ssum_dst_570") (get-alt "VIpv4" (param 0)))
                                                              (if (eq (u16 26) (identifier "label1_569")) 
                                                                (write-u128 little-endian (identifier "ssum_dst_570") (get-alt "VIpv6" (param 0)))
                                                                (if (eq (u16 27) (identifier "label1_569"))
                                                                  (let "ssum_dst_609" 
                                                                    (write-u16 little-endian (identifier "ssum_dst_570") (label-of (get-alt "VIp" (param 0))))
                                                                    (if 
                                                                    (eq (u16 0) (label-of (get-alt "VIp" (param 0)))) 
                                                                    (write-u32 little-endian (identifier "ssum_dst_609") (get-alt "v4" (get-alt "VIp" (param 0))))
                                                                    (seq (assert (eq (label-of (get-alt "VIp" (param 0))) (u16 1))) (write-u128 little-endian (identifier "ssum_dst_609") (get-alt "v6" (get-alt "VIp" (param 0)))))))
                                                                  (if 
                                                                    (eq (u16 28) (identifier "label1_569"))
                                                                    (let "srec_dst_607" 
                                                                    (write-u32 little-endian (identifier "ssum_dst_570") (get-field "ip" (get-alt "VCidrv4" (param 0))))
                                                                    (write-u8 (identifier "srec_dst_607") (get-field "mask" (get-alt "VCidrv4" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label1_569"))
                                                                    (let "srec_dst_606" 
                                                                    (write-u128 little-endian (identifier "ssum_dst_570") (get-field "ip" (get-alt "VCidrv6" (param 0))))
                                                                    (write-u8 (identifier "srec_dst_606") (get-field "mask" (get-alt "VCidrv6" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label1_569"))
                                                                    (let "ssum_dst_603" 
                                                                    (write-u16 little-endian (identifier "ssum_dst_570") (label-of (get-alt "VCidr" (param 0))))
                                                                    (if 
                                                                    (eq (u16 0) (label-of (get-alt "VCidr" (param 0))))
                                                                    (let "srec_dst_605" 
                                                                    (write-u32 little-endian (identifier "ssum_dst_603") (get-field "ip" (get-alt "v4" (get-alt "VCidr" (param 0)))))
                                                                    (write-u8 (identifier "srec_dst_605") (get-field "mask" (get-alt "v4" (get-alt "VCidr" (param 0))))))
                                                                    (seq 
                                                                    (assert (eq (label-of (get-alt "VCidr" (param 0))) (u16 1)))
                                                                    (let "srec_dst_604" 
                                                                    (write-u128 little-endian (identifier "ssum_dst_603") (get-field "ip" (get-alt "v6" (get-alt "VCidr" (param 0)))))
                                                                    (write-u8 (identifier "srec_dst_604") (get-field "mask" (get-alt "v6" (get-alt "VCidr" (param 0)))))))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label1_569"))
                                                                    (let "dst_ref_599"
                                                                    (make-vec
                                                                    (let "leb128_sz_597" 
                                                                    (make-vec (cardinality (get-alt "VTup" (param 0))))
                                                                    (let "leb128_ptr_598" 
                                                                    (make-vec (identifier "ssum_dst_570"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_598")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_598"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_597"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_597"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_597"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_597") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_597")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_597")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_598"))))))
                                                                    (let "n_ref_600" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_601" 
                                                                    (get-alt "VTup" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_599") (apply (myself "Ptr") (identifier "x_601") (unsafe-nth (u8 0) (identifier "dst_ref_599"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_600") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_600")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_599")))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label1_569"))
                                                                    (let "dst_ref_594"
                                                                    (make-vec
                                                                    (let "leb128_sz_592" 
                                                                    (make-vec (cardinality (get-alt "VVec" (param 0))))
                                                                    (let "leb128_ptr_593" 
                                                                    (make-vec (identifier "ssum_dst_570"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_593")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_593"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_592"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_592"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_592"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_592") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_592")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_592")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_593"))))))
                                                                    (let "n_ref_595" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_596" 
                                                                    (get-alt "VVec" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_594") (apply (myself "Ptr") (identifier "x_596") (unsafe-nth (u8 0) (identifier "dst_ref_594"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_595") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_595")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_594")))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label1_569"))
                                                                    (let "dst_ref_589"
                                                                    (make-vec
                                                                    (let "leb128_sz_587" 
                                                                    (make-vec (cardinality (get-alt "VLst" (param 0))))
                                                                    (let "leb128_ptr_588" 
                                                                    (make-vec (identifier "ssum_dst_570"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_588")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_588"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_587"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_587"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_587"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_587") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_587")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_587")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_588"))))))
                                                                    (let "n_ref_590" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_591" 
                                                                    (get-alt "VLst" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_589") (apply (myself "Ptr") (identifier "x_591") (unsafe-nth (u8 0) (identifier "dst_ref_589"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_590") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_590")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_589")))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label1_569"))
                                                                    (let "dst_ref_580"
                                                                    (make-vec
                                                                    (let "leb128_sz_578" 
                                                                    (make-vec (cardinality (get-alt "VRec" (param 0))))
                                                                    (let "leb128_ptr_579" 
                                                                    (make-vec (identifier "ssum_dst_570"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_579")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_579"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_578"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_578"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_578"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_578") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_578")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_578")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_579"))))))
                                                                    (let "n_ref_581" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_582" 
                                                                    (get-alt "VRec" (param 0))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "dst_ref_580")
                                                                    (apply 
                                                                    (myself "Ptr") 
                                                                    (get-item 1 (identifier "x_582"))
                                                                    (let "stup_dst_583" 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_580"))
                                                                    (write-bytes
                                                                    (let "leb128_sz_584" 
                                                                    (make-vec (string-length (get-item 0 (identifier "x_582"))))
                                                                    (let "leb128_ptr_585" 
                                                                    (make-vec (identifier "stup_dst_583"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_585")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_585"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_584"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_584"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_584"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_584") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_584")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_584")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_585"))))) 
                                                                    (bytes-of-string (get-item 0 (identifier "x_582"))))))) 
                                                                    (set-vec (u8 0) (identifier "n_ref_581") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_581")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_580")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label1_569") (u16 35)))
                                                                    (let "dst_ref_573"
                                                                    (make-vec
                                                                    (let "leb128_sz_571" 
                                                                    (make-vec (cardinality (get-alt "VMap" (param 0))))
                                                                    (let "leb128_ptr_572" 
                                                                    (make-vec (identifier "ssum_dst_570"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_572")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_572"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_571"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_571"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_571"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_571") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_571")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_571")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_572"))))))
                                                                    (let "n_ref_574" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_575" 
                                                                    (get-alt "VMap" (param 0))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "dst_ref_573")
                                                                    (apply (myself "Ptr") (get-item 1 (identifier "x_575")) (apply (myself "Ptr") (get-item 0 (identifier "x_575")) (unsafe-nth (u8 0) (identifier "dst_ref_573")))))
                                                                    (set-vec (u8 0) (identifier "n_ref_574") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_574")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_573"))))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::raql_value::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_value::t*,Pointer)> fun0 { [&fun0](::dessser::gen::raql_value::t* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer let_res_2;
    {
      uint16_t label1_569 { id_1 };
      Pointer id_3 { p_1.writeU16Le(label1_569) };
      Pointer let_res_4;
      {
        Pointer ssum_dst_570 { id_3 };
        uint16_t id_5 { 0 };
        bool id_6 { bool(id_5 == label1_569) };
        Pointer choose_res_7;
        if (id_6) {
          choose_res_7 = ssum_dst_570;
        } else {
          uint16_t id_8 { 1 };
          bool id_9 { bool(id_8 == label1_569) };
          Pointer choose_res_10;
          if (id_9) {
            choose_res_10 = ssum_dst_570;
          } else {
            uint16_t id_11 { 2 };
            bool id_12 { bool(id_11 == label1_569) };
            Pointer choose_res_13;
            if (id_12) {
              double id_14 { std::get<2 /* VFloat */>((*p_0)) };
              uint64_t id_15 { qword_of_float(id_14) };
              Pointer id_16 { ssum_dst_570.writeU64Le(id_15) };
              choose_res_13 = id_16;
            } else {
              uint16_t id_17 { 3 };
              bool id_18 { bool(id_17 == label1_569) };
              Pointer choose_res_19;
              if (id_18) {
                std::string id_20 { std::get<3 /* VString */>((*p_0)) };
                uint32_t id_21 { (uint32_t)id_20.size() };
                Vec<1, uint32_t> id_22 {  id_21  };
                Pointer let_res_23;
                {
                  Vec<1, uint32_t> leb128_sz_610 { id_22 };
                  Vec<1, Pointer> id_24 {  ssum_dst_570  };
                  Pointer let_res_25;
                  {
                    Vec<1, Pointer> leb128_ptr_611 { id_24 };
                    bool while_flag_26 { true };
                    do {
                      uint8_t id_27 { 0 };
                      uint8_t id_28 { 0 };
                      Pointer id_29 { leb128_ptr_611[id_28] };
                      uint32_t id_30 { 128U };
                      uint8_t id_31 { 0 };
                      uint32_t id_32 { leb128_sz_610[id_31] };
                      bool id_33 { bool(id_30 > id_32) };
                      uint8_t choose_res_34;
                      if (id_33) {
                        uint8_t id_35 { 0 };
                        uint32_t id_36 { leb128_sz_610[id_35] };
                        uint8_t id_37 { uint8_t(id_36) };
                        choose_res_34 = id_37;
                      } else {
                        uint8_t id_38 { 0 };
                        uint32_t id_39 { leb128_sz_610[id_38] };
                        uint8_t id_40 { uint8_t(id_39) };
                        uint8_t id_41 { 128 };
                        uint8_t id_42 { uint8_t(id_40 | id_41) };
                        choose_res_34 = id_42;
                      }
                      Pointer id_43 { id_29.writeU8(choose_res_34) };
                      Void id_44 { ((void)(leb128_ptr_611[id_27] = id_43), VOID) };
                      (void)id_44;
                      uint8_t id_45 { 0 };
                      uint8_t id_46 { 0 };
                      uint32_t id_47 { leb128_sz_610[id_46] };
                      uint8_t id_48 { 7 };
                      uint32_t id_49 { uint32_t(id_47 >> id_48) };
                      Void id_50 { ((void)(leb128_sz_610[id_45] = id_49), VOID) };
                      (void)id_50;
                      uint8_t id_51 { 0 };
                      uint32_t id_52 { leb128_sz_610[id_51] };
                      uint32_t id_53 { 0U };
                      bool id_54 { bool(id_52 > id_53) };
                      while_flag_26 = id_54;
                      if (while_flag_26) {
                        (void)VOID;
                      }
                    } while (while_flag_26);
                    (void)VOID;
                    uint8_t id_55 { 0 };
                    Pointer id_56 { leb128_ptr_611[id_55] };
                    let_res_25 = id_56;
                  }
                  let_res_23 = let_res_25;
                }
                std::string id_57 { std::get<3 /* VString */>((*p_0)) };
                Bytes id_58 { id_57 };
                Pointer id_59 { let_res_23.writeBytes(id_58) };
                choose_res_19 = id_59;
              } else {
                uint16_t id_60 { 4 };
                bool id_61 { bool(id_60 == label1_569) };
                Pointer choose_res_62;
                if (id_61) {
                  bool id_63 { std::get<4 /* VBool */>((*p_0)) };
                  uint8_t id_64 { uint8_t(id_63) };
                  Pointer id_65 { ssum_dst_570.writeU8(id_64) };
                  choose_res_62 = id_65;
                } else {
                  uint16_t id_66 { 5 };
                  bool id_67 { bool(id_66 == label1_569) };
                  Pointer choose_res_68;
                  if (id_67) {
                    char id_69 { std::get<5 /* VChar */>((*p_0)) };
                    uint8_t id_70 { uint8_t(id_69) };
                    Pointer id_71 { ssum_dst_570.writeU8(id_70) };
                    choose_res_68 = id_71;
                  } else {
                    uint16_t id_72 { 6 };
                    bool id_73 { bool(id_72 == label1_569) };
                    Pointer choose_res_74;
                    if (id_73) {
                      uint8_t id_75 { std::get<6 /* VU8 */>((*p_0)) };
                      Pointer id_76 { ssum_dst_570.writeU8(id_75) };
                      choose_res_74 = id_76;
                    } else {
                      uint16_t id_77 { 7 };
                      bool id_78 { bool(id_77 == label1_569) };
                      Pointer choose_res_79;
                      if (id_78) {
                        uint16_t id_80 { std::get<7 /* VU16 */>((*p_0)) };
                        Pointer id_81 { ssum_dst_570.writeU16Le(id_80) };
                        choose_res_79 = id_81;
                      } else {
                        uint16_t id_82 { 8 };
                        bool id_83 { bool(id_82 == label1_569) };
                        Pointer choose_res_84;
                        if (id_83) {
                          uint32_t id_85 { std::get<8 /* VU24 */>((*p_0)) };
                          uint32_t id_86 { uint32_t(id_85) };
                          Pointer id_87 { ssum_dst_570.writeU32Le(id_86) };
                          choose_res_84 = id_87;
                        } else {
                          uint16_t id_88 { 9 };
                          bool id_89 { bool(id_88 == label1_569) };
                          Pointer choose_res_90;
                          if (id_89) {
                            uint32_t id_91 { std::get<9 /* VU32 */>((*p_0)) };
                            Pointer id_92 { ssum_dst_570.writeU32Le(id_91) };
                            choose_res_90 = id_92;
                          } else {
                            uint16_t id_93 { 10 };
                            bool id_94 { bool(id_93 == label1_569) };
                            Pointer choose_res_95;
                            if (id_94) {
                              uint64_t id_96 { std::get<10 /* VU40 */>((*p_0)) };
                              uint64_t id_97 { uint64_t(id_96) };
                              Pointer id_98 { ssum_dst_570.writeU64Le(id_97) };
                              choose_res_95 = id_98;
                            } else {
                              uint16_t id_99 { 11 };
                              bool id_100 { bool(id_99 == label1_569) };
                              Pointer choose_res_101;
                              if (id_100) {
                                uint64_t id_102 { std::get<11 /* VU48 */>((*p_0)) };
                                uint64_t id_103 { uint64_t(id_102) };
                                Pointer id_104 { ssum_dst_570.writeU64Le(id_103) };
                                choose_res_101 = id_104;
                              } else {
                                uint16_t id_105 { 12 };
                                bool id_106 { bool(id_105 == label1_569) };
                                Pointer choose_res_107;
                                if (id_106) {
                                  uint64_t id_108 { std::get<12 /* VU56 */>((*p_0)) };
                                  uint64_t id_109 { uint64_t(id_108) };
                                  Pointer id_110 { ssum_dst_570.writeU64Le(id_109) };
                                  choose_res_107 = id_110;
                                } else {
                                  uint16_t id_111 { 13 };
                                  bool id_112 { bool(id_111 == label1_569) };
                                  Pointer choose_res_113;
                                  if (id_112) {
                                    uint64_t id_114 { std::get<13 /* VU64 */>((*p_0)) };
                                    Pointer id_115 { ssum_dst_570.writeU64Le(id_114) };
                                    choose_res_113 = id_115;
                                  } else {
                                    uint16_t id_116 { 14 };
                                    bool id_117 { bool(id_116 == label1_569) };
                                    Pointer choose_res_118;
                                    if (id_117) {
                                      uint128_t id_119 { std::get<14 /* VU128 */>((*p_0)) };
                                      Pointer id_120 { ssum_dst_570.writeU128Le(id_119) };
                                      choose_res_118 = id_120;
                                    } else {
                                      uint16_t id_121 { 15 };
                                      bool id_122 { bool(id_121 == label1_569) };
                                      Pointer choose_res_123;
                                      if (id_122) {
                                        int8_t id_124 { std::get<15 /* VI8 */>((*p_0)) };
                                        uint8_t id_125 { uint8_t(id_124) };
                                        Pointer id_126 { ssum_dst_570.writeU8(id_125) };
                                        choose_res_123 = id_126;
                                      } else {
                                        uint16_t id_127 { 16 };
                                        bool id_128 { bool(id_127 == label1_569) };
                                        Pointer choose_res_129;
                                        if (id_128) {
                                          int16_t id_130 { std::get<16 /* VI16 */>((*p_0)) };
                                          uint16_t id_131 { uint16_t(id_130) };
                                          Pointer id_132 { ssum_dst_570.writeU16Le(id_131) };
                                          choose_res_129 = id_132;
                                        } else {
                                          uint16_t id_133 { 17 };
                                          bool id_134 { bool(id_133 == label1_569) };
                                          Pointer choose_res_135;
                                          if (id_134) {
                                            int32_t id_136 { std::get<17 /* VI24 */>((*p_0)) };
                                            int32_t id_137 { int32_t(id_136) };
                                            uint32_t id_138 { uint32_t(id_137) };
                                            Pointer id_139 { ssum_dst_570.writeU32Le(id_138) };
                                            choose_res_135 = id_139;
                                          } else {
                                            uint16_t id_140 { 18 };
                                            bool id_141 { bool(id_140 == label1_569) };
                                            Pointer choose_res_142;
                                            if (id_141) {
                                              int32_t id_143 { std::get<18 /* VI32 */>((*p_0)) };
                                              uint32_t id_144 { uint32_t(id_143) };
                                              Pointer id_145 { ssum_dst_570.writeU32Le(id_144) };
                                              choose_res_142 = id_145;
                                            } else {
                                              uint16_t id_146 { 19 };
                                              bool id_147 { bool(id_146 == label1_569) };
                                              Pointer choose_res_148;
                                              if (id_147) {
                                                int64_t id_149 { std::get<19 /* VI40 */>((*p_0)) };
                                                int64_t id_150 { int64_t(id_149) };
                                                uint64_t id_151 { uint64_t(id_150) };
                                                Pointer id_152 { ssum_dst_570.writeU64Le(id_151) };
                                                choose_res_148 = id_152;
                                              } else {
                                                uint16_t id_153 { 20 };
                                                bool id_154 { bool(id_153 == label1_569) };
                                                Pointer choose_res_155;
                                                if (id_154) {
                                                  int64_t id_156 { std::get<20 /* VI48 */>((*p_0)) };
                                                  int64_t id_157 { int64_t(id_156) };
                                                  uint64_t id_158 { uint64_t(id_157) };
                                                  Pointer id_159 { ssum_dst_570.writeU64Le(id_158) };
                                                  choose_res_155 = id_159;
                                                } else {
                                                  uint16_t id_160 { 21 };
                                                  bool id_161 { bool(id_160 == label1_569) };
                                                  Pointer choose_res_162;
                                                  if (id_161) {
                                                    int64_t id_163 { std::get<21 /* VI56 */>((*p_0)) };
                                                    int64_t id_164 { int64_t(id_163) };
                                                    uint64_t id_165 { uint64_t(id_164) };
                                                    Pointer id_166 { ssum_dst_570.writeU64Le(id_165) };
                                                    choose_res_162 = id_166;
                                                  } else {
                                                    uint16_t id_167 { 22 };
                                                    bool id_168 { bool(id_167 == label1_569) };
                                                    Pointer choose_res_169;
                                                    if (id_168) {
                                                      int64_t id_170 { std::get<22 /* VI64 */>((*p_0)) };
                                                      uint64_t id_171 { uint64_t(id_170) };
                                                      Pointer id_172 { ssum_dst_570.writeU64Le(id_171) };
                                                      choose_res_169 = id_172;
                                                    } else {
                                                      uint16_t id_173 { 23 };
                                                      bool id_174 { bool(id_173 == label1_569) };
                                                      Pointer choose_res_175;
                                                      if (id_174) {
                                                        int128_t id_176 { std::get<23 /* VI128 */>((*p_0)) };
                                                        uint128_t id_177 { uint128_t(id_176) };
                                                        Pointer id_178 { ssum_dst_570.writeU128Le(id_177) };
                                                        choose_res_175 = id_178;
                                                      } else {
                                                        uint16_t id_179 { 24 };
                                                        bool id_180 { bool(id_179 == label1_569) };
                                                        Pointer choose_res_181;
                                                        if (id_180) {
                                                          uint64_t id_182 { std::get<24 /* VEth */>((*p_0)) };
                                                          uint64_t id_183 { uint64_t(id_182) };
                                                          Pointer id_184 { ssum_dst_570.writeU64Le(id_183) };
                                                          choose_res_181 = id_184;
                                                        } else {
                                                          uint16_t id_185 { 25 };
                                                          bool id_186 { bool(id_185 == label1_569) };
                                                          Pointer choose_res_187;
                                                          if (id_186) {
                                                            uint32_t id_188 { std::get<25 /* VIpv4 */>((*p_0)) };
                                                            Pointer id_189 { ssum_dst_570.writeU32Le(id_188) };
                                                            choose_res_187 = id_189;
                                                          } else {
                                                            uint16_t id_190 { 26 };
                                                            bool id_191 { bool(id_190 == label1_569) };
                                                            Pointer choose_res_192;
                                                            if (id_191) {
                                                              uint128_t id_193 { std::get<26 /* VIpv6 */>((*p_0)) };
                                                              Pointer id_194 { ssum_dst_570.writeU128Le(id_193) };
                                                              choose_res_192 = id_194;
                                                            } else {
                                                              uint16_t id_195 { 27 };
                                                              bool id_196 { bool(id_195 == label1_569) };
                                                              Pointer choose_res_197;
                                                              if (id_196) {
                                                                ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_198 { std::get<27 /* VIp */>((*p_0)) };
                                                                uint16_t id_199 { uint16_t(id_198.index()) };
                                                                Pointer id_200 { ssum_dst_570.writeU16Le(id_199) };
                                                                Pointer let_res_201;
                                                                {
                                                                  Pointer ssum_dst_609 { id_200 };
                                                                  uint16_t id_202 { 0 };
                                                                  ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_203 { std::get<27 /* VIp */>((*p_0)) };
                                                                  uint16_t id_204 { uint16_t(id_203.index()) };
                                                                  bool id_205 { bool(id_202 == id_204) };
                                                                  Pointer choose_res_206;
                                                                  if (id_205) {
                                                                    ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_207 { std::get<27 /* VIp */>((*p_0)) };
                                                                    uint32_t id_208 { std::get<0 /* v4 */>(id_207) };
                                                                    Pointer id_209 { ssum_dst_609.writeU32Le(id_208) };
                                                                    choose_res_206 = id_209;
                                                                  } else {
                                                                    ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_210 { std::get<27 /* VIp */>((*p_0)) };
                                                                    uint16_t id_211 { uint16_t(id_210.index()) };
                                                                    uint16_t id_212 { 1 };
                                                                    bool id_213 { bool(id_211 == id_212) };
                                                                    Void id_214 { ((void)(assert(id_213)), VOID) };
                                                                    (void)id_214;
                                                                    ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_215 { std::get<27 /* VIp */>((*p_0)) };
                                                                    uint128_t id_216 { std::get<1 /* v6 */>(id_215) };
                                                                    Pointer id_217 { ssum_dst_609.writeU128Le(id_216) };
                                                                    choose_res_206 = id_217;
                                                                  }
                                                                  let_res_201 = choose_res_206;
                                                                }
                                                                choose_res_197 = let_res_201;
                                                              } else {
                                                                uint16_t id_218 { 28 };
                                                                bool id_219 { bool(id_218 == label1_569) };
                                                                Pointer choose_res_220;
                                                                if (id_219) {
                                                                  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_221 { std::get<28 /* VCidrv4 */>((*p_0)) };
                                                                  uint32_t id_222 { id_221.Cidr4_ip };
                                                                  Pointer id_223 { ssum_dst_570.writeU32Le(id_222) };
                                                                  Pointer let_res_224;
                                                                  {
                                                                    Pointer srec_dst_607 { id_223 };
                                                                    ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_225 { std::get<28 /* VCidrv4 */>((*p_0)) };
                                                                    uint8_t id_226 { id_225.Cidr4_mask };
                                                                    Pointer id_227 { srec_dst_607.writeU8(id_226) };
                                                                    let_res_224 = id_227;
                                                                  }
                                                                  choose_res_220 = let_res_224;
                                                                } else {
                                                                  uint16_t id_228 { 29 };
                                                                  bool id_229 { bool(id_228 == label1_569) };
                                                                  Pointer choose_res_230;
                                                                  if (id_229) {
                                                                    ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_231 { std::get<29 /* VCidrv6 */>((*p_0)) };
                                                                    uint128_t id_232 { id_231.ip };
                                                                    Pointer id_233 { ssum_dst_570.writeU128Le(id_232) };
                                                                    Pointer let_res_234;
                                                                    {
                                                                      Pointer srec_dst_606 { id_233 };
                                                                      ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_235 { std::get<29 /* VCidrv6 */>((*p_0)) };
                                                                      uint8_t id_236 { id_235.mask };
                                                                      Pointer id_237 { srec_dst_606.writeU8(id_236) };
                                                                      let_res_234 = id_237;
                                                                    }
                                                                    choose_res_230 = let_res_234;
                                                                  } else {
                                                                    uint16_t id_238 { 30 };
                                                                    bool id_239 { bool(id_238 == label1_569) };
                                                                    Pointer choose_res_240;
                                                                    if (id_239) {
                                                                      ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_241 { std::get<30 /* VCidr */>((*p_0)) };
                                                                      uint16_t id_242 { uint16_t(id_241.index()) };
                                                                      Pointer id_243 { ssum_dst_570.writeU16Le(id_242) };
                                                                      Pointer let_res_244;
                                                                      {
                                                                        Pointer ssum_dst_603 { id_243 };
                                                                        uint16_t id_245 { 0 };
                                                                        ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_246 { std::get<30 /* VCidr */>((*p_0)) };
                                                                        uint16_t id_247 { uint16_t(id_246.index()) };
                                                                        bool id_248 { bool(id_245 == id_247) };
                                                                        Pointer choose_res_249;
                                                                        if (id_248) {
                                                                          ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_250 { std::get<30 /* VCidr */>((*p_0)) };
                                                                          ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_251 { std::get<0 /* v4 */>(id_250) };
                                                                          uint32_t id_252 { id_251.Cidr4_ip };
                                                                          Pointer id_253 { ssum_dst_603.writeU32Le(id_252) };
                                                                          Pointer let_res_254;
                                                                          {
                                                                            Pointer srec_dst_605 { id_253 };
                                                                            ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_255 { std::get<30 /* VCidr */>((*p_0)) };
                                                                            ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_256 { std::get<0 /* v4 */>(id_255) };
                                                                            uint8_t id_257 { id_256.Cidr4_mask };
                                                                            Pointer id_258 { srec_dst_605.writeU8(id_257) };
                                                                            let_res_254 = id_258;
                                                                          }
                                                                          choose_res_249 = let_res_254;
                                                                        } else {
                                                                          ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_259 { std::get<30 /* VCidr */>((*p_0)) };
                                                                          uint16_t id_260 { uint16_t(id_259.index()) };
                                                                          uint16_t id_261 { 1 };
                                                                          bool id_262 { bool(id_260 == id_261) };
                                                                          Void id_263 { ((void)(assert(id_262)), VOID) };
                                                                          (void)id_263;
                                                                          ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_264 { std::get<30 /* VCidr */>((*p_0)) };
                                                                          ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_265 { std::get<1 /* v6 */>(id_264) };
                                                                          uint128_t id_266 { id_265.ip };
                                                                          Pointer id_267 { ssum_dst_603.writeU128Le(id_266) };
                                                                          Pointer let_res_268;
                                                                          {
                                                                            Pointer srec_dst_604 { id_267 };
                                                                            ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_269 { std::get<30 /* VCidr */>((*p_0)) };
                                                                            ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_270 { std::get<1 /* v6 */>(id_269) };
                                                                            uint8_t id_271 { id_270.mask };
                                                                            Pointer id_272 { srec_dst_604.writeU8(id_271) };
                                                                            let_res_268 = id_272;
                                                                          }
                                                                          choose_res_249 = let_res_268;
                                                                        }
                                                                        let_res_244 = choose_res_249;
                                                                      }
                                                                      choose_res_240 = let_res_244;
                                                                    } else {
                                                                      uint16_t id_273 { 31 };
                                                                      bool id_274 { bool(id_273 == label1_569) };
                                                                      Pointer choose_res_275;
                                                                      if (id_274) {
                                                                        Arr<t*> id_276 { std::get<31 /* VTup */>((*p_0)) };
                                                                        uint32_t id_277 { id_276.size() };
                                                                        Vec<1, uint32_t> id_278 {  id_277  };
                                                                        Pointer let_res_279;
                                                                        {
                                                                          Vec<1, uint32_t> leb128_sz_597 { id_278 };
                                                                          Vec<1, Pointer> id_280 {  ssum_dst_570  };
                                                                          Pointer let_res_281;
                                                                          {
                                                                            Vec<1, Pointer> leb128_ptr_598 { id_280 };
                                                                            bool while_flag_282 { true };
                                                                            do {
                                                                              uint8_t id_283 { 0 };
                                                                              uint8_t id_284 { 0 };
                                                                              Pointer id_285 { leb128_ptr_598[id_284] };
                                                                              uint32_t id_286 { 128U };
                                                                              uint8_t id_287 { 0 };
                                                                              uint32_t id_288 { leb128_sz_597[id_287] };
                                                                              bool id_289 { bool(id_286 > id_288) };
                                                                              uint8_t choose_res_290;
                                                                              if (id_289) {
                                                                                uint8_t id_291 { 0 };
                                                                                uint32_t id_292 { leb128_sz_597[id_291] };
                                                                                uint8_t id_293 { uint8_t(id_292) };
                                                                                choose_res_290 = id_293;
                                                                              } else {
                                                                                uint8_t id_294 { 0 };
                                                                                uint32_t id_295 { leb128_sz_597[id_294] };
                                                                                uint8_t id_296 { uint8_t(id_295) };
                                                                                uint8_t id_297 { 128 };
                                                                                uint8_t id_298 { uint8_t(id_296 | id_297) };
                                                                                choose_res_290 = id_298;
                                                                              }
                                                                              Pointer id_299 { id_285.writeU8(choose_res_290) };
                                                                              Void id_300 { ((void)(leb128_ptr_598[id_283] = id_299), VOID) };
                                                                              (void)id_300;
                                                                              uint8_t id_301 { 0 };
                                                                              uint8_t id_302 { 0 };
                                                                              uint32_t id_303 { leb128_sz_597[id_302] };
                                                                              uint8_t id_304 { 7 };
                                                                              uint32_t id_305 { uint32_t(id_303 >> id_304) };
                                                                              Void id_306 { ((void)(leb128_sz_597[id_301] = id_305), VOID) };
                                                                              (void)id_306;
                                                                              uint8_t id_307 { 0 };
                                                                              uint32_t id_308 { leb128_sz_597[id_307] };
                                                                              uint32_t id_309 { 0U };
                                                                              bool id_310 { bool(id_308 > id_309) };
                                                                              while_flag_282 = id_310;
                                                                              if (while_flag_282) {
                                                                                (void)VOID;
                                                                              }
                                                                            } while (while_flag_282);
                                                                            (void)VOID;
                                                                            uint8_t id_311 { 0 };
                                                                            Pointer id_312 { leb128_ptr_598[id_311] };
                                                                            let_res_281 = id_312;
                                                                          }
                                                                          let_res_279 = let_res_281;
                                                                        }
                                                                        Vec<1, Pointer> id_313 {  let_res_279  };
                                                                        Pointer let_res_314;
                                                                        {
                                                                          Vec<1, Pointer> dst_ref_599 { id_313 };
                                                                          int32_t id_315 { 0L };
                                                                          Vec<1, int32_t> id_316 {  id_315  };
                                                                          Pointer let_res_317;
                                                                          {
                                                                            Vec<1, int32_t> n_ref_600 { id_316 };
                                                                            Arr<t*> id_318 { std::get<31 /* VTup */>((*p_0)) };
                                                                            for (t* x_601 : id_318) {
                                                                              uint8_t id_319 { 0 };
                                                                              uint8_t id_320 { 0 };
                                                                              Pointer id_321 { dst_ref_599[id_320] };
                                                                              Pointer id_322 { fun0(x_601, id_321) };
                                                                              Void id_323 { ((void)(dst_ref_599[id_319] = id_322), VOID) };
                                                                              (void)id_323;
                                                                              uint8_t id_324 { 0 };
                                                                              int32_t id_325 { 1L };
                                                                              uint8_t id_326 { 0 };
                                                                              int32_t id_327 { n_ref_600[id_326] };
                                                                              int32_t id_328 { int32_t(id_325 + id_327) };
                                                                              Void id_329 { ((void)(n_ref_600[id_324] = id_328), VOID) };
                                                                              (void)id_329;
                                                                              (void)id_329;
                                                                            }
                                                                            (void)VOID;
                                                                            uint8_t id_330 { 0 };
                                                                            Pointer id_331 { dst_ref_599[id_330] };
                                                                            let_res_317 = id_331;
                                                                          }
                                                                          let_res_314 = let_res_317;
                                                                        }
                                                                        choose_res_275 = let_res_314;
                                                                      } else {
                                                                        uint16_t id_332 { 32 };
                                                                        bool id_333 { bool(id_332 == label1_569) };
                                                                        Pointer choose_res_334;
                                                                        if (id_333) {
                                                                          Arr<t*> id_335 { std::get<32 /* VVec */>((*p_0)) };
                                                                          uint32_t id_336 { id_335.size() };
                                                                          Vec<1, uint32_t> id_337 {  id_336  };
                                                                          Pointer let_res_338;
                                                                          {
                                                                            Vec<1, uint32_t> leb128_sz_592 { id_337 };
                                                                            Vec<1, Pointer> id_339 {  ssum_dst_570  };
                                                                            Pointer let_res_340;
                                                                            {
                                                                              Vec<1, Pointer> leb128_ptr_593 { id_339 };
                                                                              bool while_flag_341 { true };
                                                                              do {
                                                                                uint8_t id_342 { 0 };
                                                                                uint8_t id_343 { 0 };
                                                                                Pointer id_344 { leb128_ptr_593[id_343] };
                                                                                uint32_t id_345 { 128U };
                                                                                uint8_t id_346 { 0 };
                                                                                uint32_t id_347 { leb128_sz_592[id_346] };
                                                                                bool id_348 { bool(id_345 > id_347) };
                                                                                uint8_t choose_res_349;
                                                                                if (id_348) {
                                                                                  uint8_t id_350 { 0 };
                                                                                  uint32_t id_351 { leb128_sz_592[id_350] };
                                                                                  uint8_t id_352 { uint8_t(id_351) };
                                                                                  choose_res_349 = id_352;
                                                                                } else {
                                                                                  uint8_t id_353 { 0 };
                                                                                  uint32_t id_354 { leb128_sz_592[id_353] };
                                                                                  uint8_t id_355 { uint8_t(id_354) };
                                                                                  uint8_t id_356 { 128 };
                                                                                  uint8_t id_357 { uint8_t(id_355 | id_356) };
                                                                                  choose_res_349 = id_357;
                                                                                }
                                                                                Pointer id_358 { id_344.writeU8(choose_res_349) };
                                                                                Void id_359 { ((void)(leb128_ptr_593[id_342] = id_358), VOID) };
                                                                                (void)id_359;
                                                                                uint8_t id_360 { 0 };
                                                                                uint8_t id_361 { 0 };
                                                                                uint32_t id_362 { leb128_sz_592[id_361] };
                                                                                uint8_t id_363 { 7 };
                                                                                uint32_t id_364 { uint32_t(id_362 >> id_363) };
                                                                                Void id_365 { ((void)(leb128_sz_592[id_360] = id_364), VOID) };
                                                                                (void)id_365;
                                                                                uint8_t id_366 { 0 };
                                                                                uint32_t id_367 { leb128_sz_592[id_366] };
                                                                                uint32_t id_368 { 0U };
                                                                                bool id_369 { bool(id_367 > id_368) };
                                                                                while_flag_341 = id_369;
                                                                                if (while_flag_341) {
                                                                                  (void)VOID;
                                                                                }
                                                                              } while (while_flag_341);
                                                                              (void)VOID;
                                                                              uint8_t id_370 { 0 };
                                                                              Pointer id_371 { leb128_ptr_593[id_370] };
                                                                              let_res_340 = id_371;
                                                                            }
                                                                            let_res_338 = let_res_340;
                                                                          }
                                                                          Vec<1, Pointer> id_372 {  let_res_338  };
                                                                          Pointer let_res_373;
                                                                          {
                                                                            Vec<1, Pointer> dst_ref_594 { id_372 };
                                                                            int32_t id_374 { 0L };
                                                                            Vec<1, int32_t> id_375 {  id_374  };
                                                                            Pointer let_res_376;
                                                                            {
                                                                              Vec<1, int32_t> n_ref_595 { id_375 };
                                                                              Arr<t*> id_377 { std::get<32 /* VVec */>((*p_0)) };
                                                                              for (t* x_596 : id_377) {
                                                                                uint8_t id_378 { 0 };
                                                                                uint8_t id_379 { 0 };
                                                                                Pointer id_380 { dst_ref_594[id_379] };
                                                                                Pointer id_381 { fun0(x_596, id_380) };
                                                                                Void id_382 { ((void)(dst_ref_594[id_378] = id_381), VOID) };
                                                                                (void)id_382;
                                                                                uint8_t id_383 { 0 };
                                                                                int32_t id_384 { 1L };
                                                                                uint8_t id_385 { 0 };
                                                                                int32_t id_386 { n_ref_595[id_385] };
                                                                                int32_t id_387 { int32_t(id_384 + id_386) };
                                                                                Void id_388 { ((void)(n_ref_595[id_383] = id_387), VOID) };
                                                                                (void)id_388;
                                                                                (void)id_388;
                                                                              }
                                                                              (void)VOID;
                                                                              uint8_t id_389 { 0 };
                                                                              Pointer id_390 { dst_ref_594[id_389] };
                                                                              let_res_376 = id_390;
                                                                            }
                                                                            let_res_373 = let_res_376;
                                                                          }
                                                                          choose_res_334 = let_res_373;
                                                                        } else {
                                                                          uint16_t id_391 { 33 };
                                                                          bool id_392 { bool(id_391 == label1_569) };
                                                                          Pointer choose_res_393;
                                                                          if (id_392) {
                                                                            Arr<t*> id_394 { std::get<33 /* VLst */>((*p_0)) };
                                                                            uint32_t id_395 { id_394.size() };
                                                                            Vec<1, uint32_t> id_396 {  id_395  };
                                                                            Pointer let_res_397;
                                                                            {
                                                                              Vec<1, uint32_t> leb128_sz_587 { id_396 };
                                                                              Vec<1, Pointer> id_398 {  ssum_dst_570  };
                                                                              Pointer let_res_399;
                                                                              {
                                                                                Vec<1, Pointer> leb128_ptr_588 { id_398 };
                                                                                bool while_flag_400 { true };
                                                                                do {
                                                                                  uint8_t id_401 { 0 };
                                                                                  uint8_t id_402 { 0 };
                                                                                  Pointer id_403 { leb128_ptr_588[id_402] };
                                                                                  uint32_t id_404 { 128U };
                                                                                  uint8_t id_405 { 0 };
                                                                                  uint32_t id_406 { leb128_sz_587[id_405] };
                                                                                  bool id_407 { bool(id_404 > id_406) };
                                                                                  uint8_t choose_res_408;
                                                                                  if (id_407) {
                                                                                    uint8_t id_409 { 0 };
                                                                                    uint32_t id_410 { leb128_sz_587[id_409] };
                                                                                    uint8_t id_411 { uint8_t(id_410) };
                                                                                    choose_res_408 = id_411;
                                                                                  } else {
                                                                                    uint8_t id_412 { 0 };
                                                                                    uint32_t id_413 { leb128_sz_587[id_412] };
                                                                                    uint8_t id_414 { uint8_t(id_413) };
                                                                                    uint8_t id_415 { 128 };
                                                                                    uint8_t id_416 { uint8_t(id_414 | id_415) };
                                                                                    choose_res_408 = id_416;
                                                                                  }
                                                                                  Pointer id_417 { id_403.writeU8(choose_res_408) };
                                                                                  Void id_418 { ((void)(leb128_ptr_588[id_401] = id_417), VOID) };
                                                                                  (void)id_418;
                                                                                  uint8_t id_419 { 0 };
                                                                                  uint8_t id_420 { 0 };
                                                                                  uint32_t id_421 { leb128_sz_587[id_420] };
                                                                                  uint8_t id_422 { 7 };
                                                                                  uint32_t id_423 { uint32_t(id_421 >> id_422) };
                                                                                  Void id_424 { ((void)(leb128_sz_587[id_419] = id_423), VOID) };
                                                                                  (void)id_424;
                                                                                  uint8_t id_425 { 0 };
                                                                                  uint32_t id_426 { leb128_sz_587[id_425] };
                                                                                  uint32_t id_427 { 0U };
                                                                                  bool id_428 { bool(id_426 > id_427) };
                                                                                  while_flag_400 = id_428;
                                                                                  if (while_flag_400) {
                                                                                    (void)VOID;
                                                                                  }
                                                                                } while (while_flag_400);
                                                                                (void)VOID;
                                                                                uint8_t id_429 { 0 };
                                                                                Pointer id_430 { leb128_ptr_588[id_429] };
                                                                                let_res_399 = id_430;
                                                                              }
                                                                              let_res_397 = let_res_399;
                                                                            }
                                                                            Vec<1, Pointer> id_431 {  let_res_397  };
                                                                            Pointer let_res_432;
                                                                            {
                                                                              Vec<1, Pointer> dst_ref_589 { id_431 };
                                                                              int32_t id_433 { 0L };
                                                                              Vec<1, int32_t> id_434 {  id_433  };
                                                                              Pointer let_res_435;
                                                                              {
                                                                                Vec<1, int32_t> n_ref_590 { id_434 };
                                                                                Arr<t*> id_436 { std::get<33 /* VLst */>((*p_0)) };
                                                                                for (t* x_591 : id_436) {
                                                                                  uint8_t id_437 { 0 };
                                                                                  uint8_t id_438 { 0 };
                                                                                  Pointer id_439 { dst_ref_589[id_438] };
                                                                                  Pointer id_440 { fun0(x_591, id_439) };
                                                                                  Void id_441 { ((void)(dst_ref_589[id_437] = id_440), VOID) };
                                                                                  (void)id_441;
                                                                                  uint8_t id_442 { 0 };
                                                                                  int32_t id_443 { 1L };
                                                                                  uint8_t id_444 { 0 };
                                                                                  int32_t id_445 { n_ref_590[id_444] };
                                                                                  int32_t id_446 { int32_t(id_443 + id_445) };
                                                                                  Void id_447 { ((void)(n_ref_590[id_442] = id_446), VOID) };
                                                                                  (void)id_447;
                                                                                  (void)id_447;
                                                                                }
                                                                                (void)VOID;
                                                                                uint8_t id_448 { 0 };
                                                                                Pointer id_449 { dst_ref_589[id_448] };
                                                                                let_res_435 = id_449;
                                                                              }
                                                                              let_res_432 = let_res_435;
                                                                            }
                                                                            choose_res_393 = let_res_432;
                                                                          } else {
                                                                            uint16_t id_450 { 34 };
                                                                            bool id_451 { bool(id_450 == label1_569) };
                                                                            Pointer choose_res_452;
                                                                            if (id_451) {
                                                                              Arr<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_453 { std::get<34 /* VRec */>((*p_0)) };
                                                                              uint32_t id_454 { id_453.size() };
                                                                              Vec<1, uint32_t> id_455 {  id_454  };
                                                                              Pointer let_res_456;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_578 { id_455 };
                                                                                Vec<1, Pointer> id_457 {  ssum_dst_570  };
                                                                                Pointer let_res_458;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_579 { id_457 };
                                                                                  bool while_flag_459 { true };
                                                                                  do {
                                                                                    uint8_t id_460 { 0 };
                                                                                    uint8_t id_461 { 0 };
                                                                                    Pointer id_462 { leb128_ptr_579[id_461] };
                                                                                    uint32_t id_463 { 128U };
                                                                                    uint8_t id_464 { 0 };
                                                                                    uint32_t id_465 { leb128_sz_578[id_464] };
                                                                                    bool id_466 { bool(id_463 > id_465) };
                                                                                    uint8_t choose_res_467;
                                                                                    if (id_466) {
                                                                                      uint8_t id_468 { 0 };
                                                                                      uint32_t id_469 { leb128_sz_578[id_468] };
                                                                                      uint8_t id_470 { uint8_t(id_469) };
                                                                                      choose_res_467 = id_470;
                                                                                    } else {
                                                                                      uint8_t id_471 { 0 };
                                                                                      uint32_t id_472 { leb128_sz_578[id_471] };
                                                                                      uint8_t id_473 { uint8_t(id_472) };
                                                                                      uint8_t id_474 { 128 };
                                                                                      uint8_t id_475 { uint8_t(id_473 | id_474) };
                                                                                      choose_res_467 = id_475;
                                                                                    }
                                                                                    Pointer id_476 { id_462.writeU8(choose_res_467) };
                                                                                    Void id_477 { ((void)(leb128_ptr_579[id_460] = id_476), VOID) };
                                                                                    (void)id_477;
                                                                                    uint8_t id_478 { 0 };
                                                                                    uint8_t id_479 { 0 };
                                                                                    uint32_t id_480 { leb128_sz_578[id_479] };
                                                                                    uint8_t id_481 { 7 };
                                                                                    uint32_t id_482 { uint32_t(id_480 >> id_481) };
                                                                                    Void id_483 { ((void)(leb128_sz_578[id_478] = id_482), VOID) };
                                                                                    (void)id_483;
                                                                                    uint8_t id_484 { 0 };
                                                                                    uint32_t id_485 { leb128_sz_578[id_484] };
                                                                                    uint32_t id_486 { 0U };
                                                                                    bool id_487 { bool(id_485 > id_486) };
                                                                                    while_flag_459 = id_487;
                                                                                    if (while_flag_459) {
                                                                                      (void)VOID;
                                                                                    }
                                                                                  } while (while_flag_459);
                                                                                  (void)VOID;
                                                                                  uint8_t id_488 { 0 };
                                                                                  Pointer id_489 { leb128_ptr_579[id_488] };
                                                                                  let_res_458 = id_489;
                                                                                }
                                                                                let_res_456 = let_res_458;
                                                                              }
                                                                              Vec<1, Pointer> id_490 {  let_res_456  };
                                                                              Pointer let_res_491;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_580 { id_490 };
                                                                                int32_t id_492 { 0L };
                                                                                Vec<1, int32_t> id_493 {  id_492  };
                                                                                Pointer let_res_494;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_581 { id_493 };
                                                                                  Arr<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_495 { std::get<34 /* VRec */>((*p_0)) };
                                                                                  for (::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c x_582 : id_495) {
                                                                                    uint8_t id_496 { 0 };
                                                                                    t* id_497 { std::get<1>(x_582) };
                                                                                    uint8_t id_498 { 0 };
                                                                                    Pointer id_499 { dst_ref_580[id_498] };
                                                                                    Pointer let_res_500;
                                                                                    {
                                                                                      Pointer stup_dst_583 { id_499 };
                                                                                      std::string id_501 { std::get<0>(x_582) };
                                                                                      uint32_t id_502 { (uint32_t)id_501.size() };
                                                                                      Vec<1, uint32_t> id_503 {  id_502  };
                                                                                      Pointer let_res_504;
                                                                                      {
                                                                                        Vec<1, uint32_t> leb128_sz_584 { id_503 };
                                                                                        Vec<1, Pointer> id_505 {  stup_dst_583  };
                                                                                        Pointer let_res_506;
                                                                                        {
                                                                                          Vec<1, Pointer> leb128_ptr_585 { id_505 };
                                                                                          bool while_flag_507 { true };
                                                                                          do {
                                                                                            uint8_t id_508 { 0 };
                                                                                            uint8_t id_509 { 0 };
                                                                                            Pointer id_510 { leb128_ptr_585[id_509] };
                                                                                            uint32_t id_511 { 128U };
                                                                                            uint8_t id_512 { 0 };
                                                                                            uint32_t id_513 { leb128_sz_584[id_512] };
                                                                                            bool id_514 { bool(id_511 > id_513) };
                                                                                            uint8_t choose_res_515;
                                                                                            if (id_514) {
                                                                                              uint8_t id_516 { 0 };
                                                                                              uint32_t id_517 { leb128_sz_584[id_516] };
                                                                                              uint8_t id_518 { uint8_t(id_517) };
                                                                                              choose_res_515 = id_518;
                                                                                            } else {
                                                                                              uint8_t id_519 { 0 };
                                                                                              uint32_t id_520 { leb128_sz_584[id_519] };
                                                                                              uint8_t id_521 { uint8_t(id_520) };
                                                                                              uint8_t id_522 { 128 };
                                                                                              uint8_t id_523 { uint8_t(id_521 | id_522) };
                                                                                              choose_res_515 = id_523;
                                                                                            }
                                                                                            Pointer id_524 { id_510.writeU8(choose_res_515) };
                                                                                            Void id_525 { ((void)(leb128_ptr_585[id_508] = id_524), VOID) };
                                                                                            (void)id_525;
                                                                                            uint8_t id_526 { 0 };
                                                                                            uint8_t id_527 { 0 };
                                                                                            uint32_t id_528 { leb128_sz_584[id_527] };
                                                                                            uint8_t id_529 { 7 };
                                                                                            uint32_t id_530 { uint32_t(id_528 >> id_529) };
                                                                                            Void id_531 { ((void)(leb128_sz_584[id_526] = id_530), VOID) };
                                                                                            (void)id_531;
                                                                                            uint8_t id_532 { 0 };
                                                                                            uint32_t id_533 { leb128_sz_584[id_532] };
                                                                                            uint32_t id_534 { 0U };
                                                                                            bool id_535 { bool(id_533 > id_534) };
                                                                                            while_flag_507 = id_535;
                                                                                            if (while_flag_507) {
                                                                                              (void)VOID;
                                                                                            }
                                                                                          } while (while_flag_507);
                                                                                          (void)VOID;
                                                                                          uint8_t id_536 { 0 };
                                                                                          Pointer id_537 { leb128_ptr_585[id_536] };
                                                                                          let_res_506 = id_537;
                                                                                        }
                                                                                        let_res_504 = let_res_506;
                                                                                      }
                                                                                      std::string id_538 { std::get<0>(x_582) };
                                                                                      Bytes id_539 { id_538 };
                                                                                      Pointer id_540 { let_res_504.writeBytes(id_539) };
                                                                                      let_res_500 = id_540;
                                                                                    }
                                                                                    Pointer id_541 { fun0(id_497, let_res_500) };
                                                                                    Void id_542 { ((void)(dst_ref_580[id_496] = id_541), VOID) };
                                                                                    (void)id_542;
                                                                                    uint8_t id_543 { 0 };
                                                                                    int32_t id_544 { 1L };
                                                                                    uint8_t id_545 { 0 };
                                                                                    int32_t id_546 { n_ref_581[id_545] };
                                                                                    int32_t id_547 { int32_t(id_544 + id_546) };
                                                                                    Void id_548 { ((void)(n_ref_581[id_543] = id_547), VOID) };
                                                                                    (void)id_548;
                                                                                    (void)id_548;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_549 { 0 };
                                                                                  Pointer id_550 { dst_ref_580[id_549] };
                                                                                  let_res_494 = id_550;
                                                                                }
                                                                                let_res_491 = let_res_494;
                                                                              }
                                                                              choose_res_452 = let_res_491;
                                                                            } else {
                                                                              uint16_t id_551 { 35 };
                                                                              bool id_552 { bool(label1_569 == id_551) };
                                                                              Void id_553 { ((void)(assert(id_552)), VOID) };
                                                                              (void)id_553;
                                                                              Arr<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> id_554 { std::get<35 /* VMap */>((*p_0)) };
                                                                              uint32_t id_555 { id_554.size() };
                                                                              Vec<1, uint32_t> id_556 {  id_555  };
                                                                              Pointer let_res_557;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_571 { id_556 };
                                                                                Vec<1, Pointer> id_558 {  ssum_dst_570  };
                                                                                Pointer let_res_559;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_572 { id_558 };
                                                                                  bool while_flag_560 { true };
                                                                                  do {
                                                                                    uint8_t id_561 { 0 };
                                                                                    uint8_t id_562 { 0 };
                                                                                    Pointer id_563 { leb128_ptr_572[id_562] };
                                                                                    uint32_t id_564 { 128U };
                                                                                    uint8_t id_565 { 0 };
                                                                                    uint32_t id_566 { leb128_sz_571[id_565] };
                                                                                    bool id_567 { bool(id_564 > id_566) };
                                                                                    uint8_t choose_res_568;
                                                                                    if (id_567) {
                                                                                      uint8_t id_569 { 0 };
                                                                                      uint32_t id_570 { leb128_sz_571[id_569] };
                                                                                      uint8_t id_571 { uint8_t(id_570) };
                                                                                      choose_res_568 = id_571;
                                                                                    } else {
                                                                                      uint8_t id_572 { 0 };
                                                                                      uint32_t id_573 { leb128_sz_571[id_572] };
                                                                                      uint8_t id_574 { uint8_t(id_573) };
                                                                                      uint8_t id_575 { 128 };
                                                                                      uint8_t id_576 { uint8_t(id_574 | id_575) };
                                                                                      choose_res_568 = id_576;
                                                                                    }
                                                                                    Pointer id_577 { id_563.writeU8(choose_res_568) };
                                                                                    Void id_578 { ((void)(leb128_ptr_572[id_561] = id_577), VOID) };
                                                                                    (void)id_578;
                                                                                    uint8_t id_579 { 0 };
                                                                                    uint8_t id_580 { 0 };
                                                                                    uint32_t id_581 { leb128_sz_571[id_580] };
                                                                                    uint8_t id_582 { 7 };
                                                                                    uint32_t id_583 { uint32_t(id_581 >> id_582) };
                                                                                    Void id_584 { ((void)(leb128_sz_571[id_579] = id_583), VOID) };
                                                                                    (void)id_584;
                                                                                    uint8_t id_585 { 0 };
                                                                                    uint32_t id_586 { leb128_sz_571[id_585] };
                                                                                    uint32_t id_587 { 0U };
                                                                                    bool id_588 { bool(id_586 > id_587) };
                                                                                    while_flag_560 = id_588;
                                                                                    if (while_flag_560) {
                                                                                      (void)VOID;
                                                                                    }
                                                                                  } while (while_flag_560);
                                                                                  (void)VOID;
                                                                                  uint8_t id_589 { 0 };
                                                                                  Pointer id_590 { leb128_ptr_572[id_589] };
                                                                                  let_res_559 = id_590;
                                                                                }
                                                                                let_res_557 = let_res_559;
                                                                              }
                                                                              Vec<1, Pointer> id_591 {  let_res_557  };
                                                                              Pointer let_res_592;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_573 { id_591 };
                                                                                int32_t id_593 { 0L };
                                                                                Vec<1, int32_t> id_594 {  id_593  };
                                                                                Pointer let_res_595;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_574 { id_594 };
                                                                                  Arr<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> id_596 { std::get<35 /* VMap */>((*p_0)) };
                                                                                  for (::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf x_575 : id_596) {
                                                                                    uint8_t id_597 { 0 };
                                                                                    t* id_598 { std::get<1>(x_575) };
                                                                                    t* id_599 { std::get<0>(x_575) };
                                                                                    uint8_t id_600 { 0 };
                                                                                    Pointer id_601 { dst_ref_573[id_600] };
                                                                                    Pointer id_602 { fun0(id_599, id_601) };
                                                                                    Pointer id_603 { fun0(id_598, id_602) };
                                                                                    Void id_604 { ((void)(dst_ref_573[id_597] = id_603), VOID) };
                                                                                    (void)id_604;
                                                                                    uint8_t id_605 { 0 };
                                                                                    int32_t id_606 { 1L };
                                                                                    uint8_t id_607 { 0 };
                                                                                    int32_t id_608 { n_ref_574[id_607] };
                                                                                    int32_t id_609 { int32_t(id_606 + id_608) };
                                                                                    Void id_610 { ((void)(n_ref_574[id_605] = id_609), VOID) };
                                                                                    (void)id_610;
                                                                                    (void)id_610;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_611 { 0 };
                                                                                  Pointer id_612 { dst_ref_573[id_611] };
                                                                                  let_res_595 = id_612;
                                                                                }
                                                                                let_res_592 = let_res_595;
                                                                              }
                                                                              choose_res_452 = let_res_592;
                                                                            }
                                                                            choose_res_393 = choose_res_452;
                                                                          }
                                                                          choose_res_334 = choose_res_393;
                                                                        }
                                                                        choose_res_275 = choose_res_334;
                                                                      }
                                                                      choose_res_240 = choose_res_275;
                                                                    }
                                                                    choose_res_230 = choose_res_240;
                                                                  }
                                                                  choose_res_220 = choose_res_230;
                                                                }
                                                                choose_res_197 = choose_res_220;
                                                              }
                                                              choose_res_192 = choose_res_197;
                                                            }
                                                            choose_res_187 = choose_res_192;
                                                          }
                                                          choose_res_181 = choose_res_187;
                                                        }
                                                        choose_res_175 = choose_res_181;
                                                      }
                                                      choose_res_169 = choose_res_175;
                                                    }
                                                    choose_res_162 = choose_res_169;
                                                  }
                                                  choose_res_155 = choose_res_162;
                                                }
                                                choose_res_148 = choose_res_155;
                                              }
                                              choose_res_142 = choose_res_148;
                                            }
                                            choose_res_135 = choose_res_142;
                                          }
                                          choose_res_129 = choose_res_135;
                                        }
                                        choose_res_123 = choose_res_129;
                                      }
                                      choose_res_118 = choose_res_123;
                                    }
                                    choose_res_113 = choose_res_118;
                                  }
                                  choose_res_107 = choose_res_113;
                                }
                                choose_res_101 = choose_res_107;
                              }
                              choose_res_95 = choose_res_101;
                            }
                            choose_res_90 = choose_res_95;
                          }
                          choose_res_84 = choose_res_90;
                        }
                        choose_res_79 = choose_res_84;
                      }
                      choose_res_74 = choose_res_79;
                    }
                    choose_res_68 = choose_res_74;
                  }
                  choose_res_62 = choose_res_68;
                }
                choose_res_19 = choose_res_62;
              }
              choose_res_13 = choose_res_19;
            }
            choose_res_10 = choose_res_13;
          }
          choose_res_7 = choose_res_10;
        }
        let_res_4 = choose_res_7;
      }
      let_res_2 = let_res_4;
    }
    return let_res_2;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::raql_value::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]")
      (let "label2_528" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_528")) (size 2)
          (if (eq (u16 1) (identifier "label2_528")) (size 2)
            (if (eq (u16 2) (identifier "label2_528")) (size 10)
              (if (eq (u16 3) (identifier "label2_528"))
                (add (size 2)
                  (add
                    (let "n_ref_567" (make-vec (string-length (get-alt "VString" (param 0))))
                      (let "lebsz_ref_568" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_567")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_568")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_568") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_568")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_568")))))) 
                    (size-of-u32 (string-length (get-alt "VString" (param 0))))))
                (if (eq (u16 4) (identifier "label2_528")) (size 3)
                  (if (eq (u16 5) (identifier "label2_528")) (size 3)
                    (if (eq (u16 6) (identifier "label2_528")) (size 3)
                      (if (eq (u16 7) (identifier "label2_528")) (size 4)
                        (if (eq (u16 8) (identifier "label2_528")) (size 6)
                          (if (eq (u16 9) (identifier "label2_528")) 
                            (size 6)
                            (if (eq (u16 10) (identifier "label2_528")) 
                              (size 10)
                              (if (eq (u16 11) (identifier "label2_528")) 
                                (size 10)
                                (if (eq (u16 12) (identifier "label2_528")) 
                                  (size 10)
                                  (if (eq (u16 13) (identifier "label2_528")) 
                                    (size 10)
                                    (if (eq (u16 14) (identifier "label2_528")) 
                                      (size 18)
                                      (if (eq (u16 15) (identifier "label2_528")) 
                                        (size 3)
                                        (if (eq (u16 16) (identifier "label2_528")) 
                                          (size 4)
                                          (if (eq (u16 17) (identifier "label2_528")) 
                                            (size 6)
                                            (if (eq (u16 18) (identifier "label2_528")) 
                                              (size 6)
                                              (if (eq (u16 19) (identifier "label2_528")) 
                                                (size 10)
                                                (if (eq (u16 20) (identifier "label2_528")) 
                                                  (size 10)
                                                  (if (eq (u16 21) (identifier "label2_528")) 
                                                    (size 10)
                                                    (if (eq (u16 22) (identifier "label2_528")) 
                                                      (size 10)
                                                      (if (eq (u16 23) (identifier "label2_528")) 
                                                        (size 18)
                                                        (if (eq (u16 24) (identifier "label2_528")) 
                                                          (size 10)
                                                          (if (eq (u16 25) (identifier "label2_528")) 
                                                            (size 6)
                                                            (if (eq (u16 26) (identifier "label2_528")) 
                                                              (size 18)
                                                              (if (eq (u16 27) (identifier "label2_528"))
                                                                (if (eq (u16 0) (label-of (get-alt "VIp" (param 0)))) (size 8) (seq (assert (eq (label-of (get-alt "VIp" (param 0))) (u16 1))) (size 20)))
                                                                (if (eq (u16 28) (identifier "label2_528")) 
                                                                  (size 7)
                                                                  (if 
                                                                    (eq (u16 29) (identifier "label2_528")) 
                                                                    (size 19)
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label2_528"))
                                                                    (if (eq (u16 0) (label-of (get-alt "VCidr" (param 0)))) (size 9) (seq (assert (eq (label-of (get-alt "VCidr" (param 0))) (u16 1))) (size 21)))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label2_528"))
                                                                    (let "sz_ref_554"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_552" 
                                                                    (make-vec (cardinality (get-alt "VTup" (param 0))))
                                                                    (let "lebsz_ref_553" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_552")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_553")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_553") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_553")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_553"))))))))
                                                                    (seq
                                                                    (let "repeat_n_555" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VTup" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_555")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_554")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_554")) 
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_555")) (get-alt "VTup" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_555") (add (unsafe-nth (u8 0) (identifier "repeat_n_555")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_554"))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label2_528"))
                                                                    (let "sz_ref_550"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_548" 
                                                                    (make-vec (cardinality (get-alt "VVec" (param 0))))
                                                                    (let "lebsz_ref_549" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_548")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_549")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_549") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_549")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_549"))))))))
                                                                    (seq
                                                                    (let "repeat_n_551" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VVec" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_551")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_550")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_550")) 
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_551")) (get-alt "VVec" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_551") (add (unsafe-nth (u8 0) (identifier "repeat_n_551")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_550"))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label2_528"))
                                                                    (let "sz_ref_546"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_544" 
                                                                    (make-vec (cardinality (get-alt "VLst" (param 0))))
                                                                    (let "lebsz_ref_545" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_544")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_545")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_545") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_545")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_545"))))))))
                                                                    (seq
                                                                    (let "repeat_n_547" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VLst" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_547")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_546")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_546")) 
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_547")) (get-alt "VLst" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_547") (add (unsafe-nth (u8 0) (identifier "repeat_n_547")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_546"))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label2_528"))
                                                                    (let "sz_ref_537"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_535" 
                                                                    (make-vec (cardinality (get-alt "VRec" (param 0))))
                                                                    (let "lebsz_ref_536" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_535")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_536")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_536") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_536")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_536"))))))))
                                                                    (seq
                                                                    (let "repeat_n_538" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VRec" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_538")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_537")
                                                                    (let "sz_543"
                                                                    (let "sz_539" 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_537"))
                                                                    (add 
                                                                    (identifier "sz_539")
                                                                    (let "wlen_540" 
                                                                    (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_538")) (get-alt "VRec" (param 0)))))
                                                                    (add
                                                                    (let "n_ref_541" 
                                                                    (make-vec (identifier "wlen_540"))
                                                                    (let "lebsz_ref_542" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_541")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_542")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_542") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_542")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_542")))))) 
                                                                    (size-of-u32 (identifier "wlen_540"))))))
                                                                    (add (identifier "sz_543") (apply (myself "Size") (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_538")) (get-alt "VRec" (param 0))))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_538") (add (unsafe-nth (u8 0) (identifier "repeat_n_538")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_537"))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label2_528") (u16 35)))
                                                                    (let "sz_ref_531"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_529" 
                                                                    (make-vec (cardinality (get-alt "VMap" (param 0))))
                                                                    (let "lebsz_ref_530" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_529")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_530")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_530") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_530")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_530"))))))))
                                                                    (seq
                                                                    (let "repeat_n_532" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VMap" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_532")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_531")
                                                                    (add
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_531"))
                                                                    (apply (myself "Size") (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_532")) (get-alt "VMap" (param 0))))))
                                                                    (apply (myself "Size") (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_532")) (get-alt "VMap" (param 0)))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_532") (add (unsafe-nth (u8 0) (identifier "repeat_n_532")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_531"))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Size(::dessser::gen::raql_value::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_value::t*)> fun613 { [&fun613](::dessser::gen::raql_value::t* p_0) {
    uint16_t id_614 { uint16_t((*p_0).index()) };
    Size let_res_615;
    {
      uint16_t label2_528 { id_614 };
      uint16_t id_616 { 0 };
      bool id_617 { bool(id_616 == label2_528) };
      Size choose_res_618;
      if (id_617) {
        Size id_619 { 2UL };
        choose_res_618 = id_619;
      } else {
        uint16_t id_620 { 1 };
        bool id_621 { bool(id_620 == label2_528) };
        Size choose_res_622;
        if (id_621) {
          Size id_623 { 2UL };
          choose_res_622 = id_623;
        } else {
          uint16_t id_624 { 2 };
          bool id_625 { bool(id_624 == label2_528) };
          Size choose_res_626;
          if (id_625) {
            Size id_627 { 10UL };
            choose_res_626 = id_627;
          } else {
            uint16_t id_628 { 3 };
            bool id_629 { bool(id_628 == label2_528) };
            Size choose_res_630;
            if (id_629) {
              Size id_631 { 2UL };
              std::string id_632 { std::get<3 /* VString */>((*p_0)) };
              uint32_t id_633 { (uint32_t)id_632.size() };
              Vec<1, uint32_t> id_634 {  id_633  };
              Size let_res_635;
              {
                Vec<1, uint32_t> n_ref_567 { id_634 };
                uint32_t id_636 { 1U };
                Vec<1, uint32_t> id_637 {  id_636  };
                Size let_res_638;
                {
                  Vec<1, uint32_t> lebsz_ref_568 { id_637 };
                  bool while_flag_639 { true };
                  do {
                    uint8_t id_640 { 0 };
                    uint32_t id_641 { n_ref_567[id_640] };
                    uint8_t id_642 { 0 };
                    uint32_t id_643 { lebsz_ref_568[id_642] };
                    uint8_t id_644 { 7 };
                    uint32_t id_645 { uint32_t(id_643 << id_644) };
                    bool id_646 { bool(id_641 >= id_645) };
                    while_flag_639 = id_646;
                    if (while_flag_639) {
                      uint8_t id_647 { 0 };
                      uint8_t id_648 { 0 };
                      uint32_t id_649 { lebsz_ref_568[id_648] };
                      uint32_t id_650 { 1U };
                      uint32_t id_651 { uint32_t(id_649 + id_650) };
                      Void id_652 { ((void)(lebsz_ref_568[id_647] = id_651), VOID) };
                      (void)id_652;
                    }
                  } while (while_flag_639);
                  (void)VOID;
                  uint8_t id_653 { 0 };
                  uint32_t id_654 { lebsz_ref_568[id_653] };
                  Size id_655 { Size(id_654) };
                  let_res_638 = id_655;
                }
                let_res_635 = let_res_638;
              }
              std::string id_656 { std::get<3 /* VString */>((*p_0)) };
              uint32_t id_657 { (uint32_t)id_656.size() };
              Size id_658 { Size(id_657) };
              Size id_659 { Size(let_res_635 + id_658) };
              Size id_660 { Size(id_631 + id_659) };
              choose_res_630 = id_660;
            } else {
              uint16_t id_661 { 4 };
              bool id_662 { bool(id_661 == label2_528) };
              Size choose_res_663;
              if (id_662) {
                Size id_664 { 3UL };
                choose_res_663 = id_664;
              } else {
                uint16_t id_665 { 5 };
                bool id_666 { bool(id_665 == label2_528) };
                Size choose_res_667;
                if (id_666) {
                  Size id_668 { 3UL };
                  choose_res_667 = id_668;
                } else {
                  uint16_t id_669 { 6 };
                  bool id_670 { bool(id_669 == label2_528) };
                  Size choose_res_671;
                  if (id_670) {
                    Size id_672 { 3UL };
                    choose_res_671 = id_672;
                  } else {
                    uint16_t id_673 { 7 };
                    bool id_674 { bool(id_673 == label2_528) };
                    Size choose_res_675;
                    if (id_674) {
                      Size id_676 { 4UL };
                      choose_res_675 = id_676;
                    } else {
                      uint16_t id_677 { 8 };
                      bool id_678 { bool(id_677 == label2_528) };
                      Size choose_res_679;
                      if (id_678) {
                        Size id_680 { 6UL };
                        choose_res_679 = id_680;
                      } else {
                        uint16_t id_681 { 9 };
                        bool id_682 { bool(id_681 == label2_528) };
                        Size choose_res_683;
                        if (id_682) {
                          Size id_684 { 6UL };
                          choose_res_683 = id_684;
                        } else {
                          uint16_t id_685 { 10 };
                          bool id_686 { bool(id_685 == label2_528) };
                          Size choose_res_687;
                          if (id_686) {
                            Size id_688 { 10UL };
                            choose_res_687 = id_688;
                          } else {
                            uint16_t id_689 { 11 };
                            bool id_690 { bool(id_689 == label2_528) };
                            Size choose_res_691;
                            if (id_690) {
                              Size id_692 { 10UL };
                              choose_res_691 = id_692;
                            } else {
                              uint16_t id_693 { 12 };
                              bool id_694 { bool(id_693 == label2_528) };
                              Size choose_res_695;
                              if (id_694) {
                                Size id_696 { 10UL };
                                choose_res_695 = id_696;
                              } else {
                                uint16_t id_697 { 13 };
                                bool id_698 { bool(id_697 == label2_528) };
                                Size choose_res_699;
                                if (id_698) {
                                  Size id_700 { 10UL };
                                  choose_res_699 = id_700;
                                } else {
                                  uint16_t id_701 { 14 };
                                  bool id_702 { bool(id_701 == label2_528) };
                                  Size choose_res_703;
                                  if (id_702) {
                                    Size id_704 { 18UL };
                                    choose_res_703 = id_704;
                                  } else {
                                    uint16_t id_705 { 15 };
                                    bool id_706 { bool(id_705 == label2_528) };
                                    Size choose_res_707;
                                    if (id_706) {
                                      Size id_708 { 3UL };
                                      choose_res_707 = id_708;
                                    } else {
                                      uint16_t id_709 { 16 };
                                      bool id_710 { bool(id_709 == label2_528) };
                                      Size choose_res_711;
                                      if (id_710) {
                                        Size id_712 { 4UL };
                                        choose_res_711 = id_712;
                                      } else {
                                        uint16_t id_713 { 17 };
                                        bool id_714 { bool(id_713 == label2_528) };
                                        Size choose_res_715;
                                        if (id_714) {
                                          Size id_716 { 6UL };
                                          choose_res_715 = id_716;
                                        } else {
                                          uint16_t id_717 { 18 };
                                          bool id_718 { bool(id_717 == label2_528) };
                                          Size choose_res_719;
                                          if (id_718) {
                                            Size id_720 { 6UL };
                                            choose_res_719 = id_720;
                                          } else {
                                            uint16_t id_721 { 19 };
                                            bool id_722 { bool(id_721 == label2_528) };
                                            Size choose_res_723;
                                            if (id_722) {
                                              Size id_724 { 10UL };
                                              choose_res_723 = id_724;
                                            } else {
                                              uint16_t id_725 { 20 };
                                              bool id_726 { bool(id_725 == label2_528) };
                                              Size choose_res_727;
                                              if (id_726) {
                                                Size id_728 { 10UL };
                                                choose_res_727 = id_728;
                                              } else {
                                                uint16_t id_729 { 21 };
                                                bool id_730 { bool(id_729 == label2_528) };
                                                Size choose_res_731;
                                                if (id_730) {
                                                  Size id_732 { 10UL };
                                                  choose_res_731 = id_732;
                                                } else {
                                                  uint16_t id_733 { 22 };
                                                  bool id_734 { bool(id_733 == label2_528) };
                                                  Size choose_res_735;
                                                  if (id_734) {
                                                    Size id_736 { 10UL };
                                                    choose_res_735 = id_736;
                                                  } else {
                                                    uint16_t id_737 { 23 };
                                                    bool id_738 { bool(id_737 == label2_528) };
                                                    Size choose_res_739;
                                                    if (id_738) {
                                                      Size id_740 { 18UL };
                                                      choose_res_739 = id_740;
                                                    } else {
                                                      uint16_t id_741 { 24 };
                                                      bool id_742 { bool(id_741 == label2_528) };
                                                      Size choose_res_743;
                                                      if (id_742) {
                                                        Size id_744 { 10UL };
                                                        choose_res_743 = id_744;
                                                      } else {
                                                        uint16_t id_745 { 25 };
                                                        bool id_746 { bool(id_745 == label2_528) };
                                                        Size choose_res_747;
                                                        if (id_746) {
                                                          Size id_748 { 6UL };
                                                          choose_res_747 = id_748;
                                                        } else {
                                                          uint16_t id_749 { 26 };
                                                          bool id_750 { bool(id_749 == label2_528) };
                                                          Size choose_res_751;
                                                          if (id_750) {
                                                            Size id_752 { 18UL };
                                                            choose_res_751 = id_752;
                                                          } else {
                                                            uint16_t id_753 { 27 };
                                                            bool id_754 { bool(id_753 == label2_528) };
                                                            Size choose_res_755;
                                                            if (id_754) {
                                                              uint16_t id_756 { 0 };
                                                              ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_757 { std::get<27 /* VIp */>((*p_0)) };
                                                              uint16_t id_758 { uint16_t(id_757.index()) };
                                                              bool id_759 { bool(id_756 == id_758) };
                                                              Size choose_res_760;
                                                              if (id_759) {
                                                                Size id_761 { 8UL };
                                                                choose_res_760 = id_761;
                                                              } else {
                                                                ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_762 { std::get<27 /* VIp */>((*p_0)) };
                                                                uint16_t id_763 { uint16_t(id_762.index()) };
                                                                uint16_t id_764 { 1 };
                                                                bool id_765 { bool(id_763 == id_764) };
                                                                Void id_766 { ((void)(assert(id_765)), VOID) };
                                                                (void)id_766;
                                                                Size id_767 { 20UL };
                                                                choose_res_760 = id_767;
                                                              }
                                                              choose_res_755 = choose_res_760;
                                                            } else {
                                                              uint16_t id_768 { 28 };
                                                              bool id_769 { bool(id_768 == label2_528) };
                                                              Size choose_res_770;
                                                              if (id_769) {
                                                                Size id_771 { 7UL };
                                                                choose_res_770 = id_771;
                                                              } else {
                                                                uint16_t id_772 { 29 };
                                                                bool id_773 { bool(id_772 == label2_528) };
                                                                Size choose_res_774;
                                                                if (id_773) {
                                                                  Size id_775 { 19UL };
                                                                  choose_res_774 = id_775;
                                                                } else {
                                                                  uint16_t id_776 { 30 };
                                                                  bool id_777 { bool(id_776 == label2_528) };
                                                                  Size choose_res_778;
                                                                  if (id_777) {
                                                                    uint16_t id_779 { 0 };
                                                                    ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_780 { std::get<30 /* VCidr */>((*p_0)) };
                                                                    uint16_t id_781 { uint16_t(id_780.index()) };
                                                                    bool id_782 { bool(id_779 == id_781) };
                                                                    Size choose_res_783;
                                                                    if (id_782) {
                                                                      Size id_784 { 9UL };
                                                                      choose_res_783 = id_784;
                                                                    } else {
                                                                      ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_785 { std::get<30 /* VCidr */>((*p_0)) };
                                                                      uint16_t id_786 { uint16_t(id_785.index()) };
                                                                      uint16_t id_787 { 1 };
                                                                      bool id_788 { bool(id_786 == id_787) };
                                                                      Void id_789 { ((void)(assert(id_788)), VOID) };
                                                                      (void)id_789;
                                                                      Size id_790 { 21UL };
                                                                      choose_res_783 = id_790;
                                                                    }
                                                                    choose_res_778 = choose_res_783;
                                                                  } else {
                                                                    uint16_t id_791 { 31 };
                                                                    bool id_792 { bool(id_791 == label2_528) };
                                                                    Size choose_res_793;
                                                                    if (id_792) {
                                                                      Size id_794 { 2UL };
                                                                      Arr<t*> id_795 { std::get<31 /* VTup */>((*p_0)) };
                                                                      uint32_t id_796 { id_795.size() };
                                                                      Vec<1, uint32_t> id_797 {  id_796  };
                                                                      Size let_res_798;
                                                                      {
                                                                        Vec<1, uint32_t> n_ref_552 { id_797 };
                                                                        uint32_t id_799 { 1U };
                                                                        Vec<1, uint32_t> id_800 {  id_799  };
                                                                        Size let_res_801;
                                                                        {
                                                                          Vec<1, uint32_t> lebsz_ref_553 { id_800 };
                                                                          bool while_flag_802 { true };
                                                                          do {
                                                                            uint8_t id_803 { 0 };
                                                                            uint32_t id_804 { n_ref_552[id_803] };
                                                                            uint8_t id_805 { 0 };
                                                                            uint32_t id_806 { lebsz_ref_553[id_805] };
                                                                            uint8_t id_807 { 7 };
                                                                            uint32_t id_808 { uint32_t(id_806 << id_807) };
                                                                            bool id_809 { bool(id_804 >= id_808) };
                                                                            while_flag_802 = id_809;
                                                                            if (while_flag_802) {
                                                                              uint8_t id_810 { 0 };
                                                                              uint8_t id_811 { 0 };
                                                                              uint32_t id_812 { lebsz_ref_553[id_811] };
                                                                              uint32_t id_813 { 1U };
                                                                              uint32_t id_814 { uint32_t(id_812 + id_813) };
                                                                              Void id_815 { ((void)(lebsz_ref_553[id_810] = id_814), VOID) };
                                                                              (void)id_815;
                                                                            }
                                                                          } while (while_flag_802);
                                                                          (void)VOID;
                                                                          uint8_t id_816 { 0 };
                                                                          uint32_t id_817 { lebsz_ref_553[id_816] };
                                                                          Size id_818 { Size(id_817) };
                                                                          let_res_801 = id_818;
                                                                        }
                                                                        let_res_798 = let_res_801;
                                                                      }
                                                                      Size id_819 { Size(id_794 + let_res_798) };
                                                                      Vec<1, Size> id_820 {  id_819  };
                                                                      Size let_res_821;
                                                                      {
                                                                        Vec<1, Size> sz_ref_554 { id_820 };
                                                                        int32_t id_822 { 0L };
                                                                        Vec<1, int32_t> id_823 {  id_822  };
                                                                        {
                                                                          Vec<1, int32_t> repeat_n_555 { id_823 };
                                                                          bool while_flag_824 { true };
                                                                          do {
                                                                            Arr<t*> id_825 { std::get<31 /* VTup */>((*p_0)) };
                                                                            uint32_t id_826 { id_825.size() };
                                                                            int32_t id_827 { int32_t(id_826) };
                                                                            uint8_t id_828 { 0 };
                                                                            int32_t id_829 { repeat_n_555[id_828] };
                                                                            bool id_830 { bool(id_827 > id_829) };
                                                                            while_flag_824 = id_830;
                                                                            if (while_flag_824) {
                                                                              uint8_t id_831 { 0 };
                                                                              uint8_t id_832 { 0 };
                                                                              Size id_833 { sz_ref_554[id_832] };
                                                                              uint8_t id_834 { 0 };
                                                                              int32_t id_835 { repeat_n_555[id_834] };
                                                                              Arr<t*> id_836 { std::get<31 /* VTup */>((*p_0)) };
                                                                              t* id_837 { id_836[id_835] };
                                                                              Size id_838 { fun613(id_837) };
                                                                              Size id_839 { Size(id_833 + id_838) };
                                                                              Void id_840 { ((void)(sz_ref_554[id_831] = id_839), VOID) };
                                                                              (void)id_840;
                                                                              uint8_t id_841 { 0 };
                                                                              uint8_t id_842 { 0 };
                                                                              int32_t id_843 { repeat_n_555[id_842] };
                                                                              int32_t id_844 { 1L };
                                                                              int32_t id_845 { int32_t(id_843 + id_844) };
                                                                              Void id_846 { ((void)(repeat_n_555[id_841] = id_845), VOID) };
                                                                              (void)id_846;
                                                                              (void)id_846;
                                                                            }
                                                                          } while (while_flag_824);
                                                                          (void)VOID;
                                                                        }
                                                                        (void)VOID;
                                                                        uint8_t id_847 { 0 };
                                                                        Size id_848 { sz_ref_554[id_847] };
                                                                        let_res_821 = id_848;
                                                                      }
                                                                      choose_res_793 = let_res_821;
                                                                    } else {
                                                                      uint16_t id_849 { 32 };
                                                                      bool id_850 { bool(id_849 == label2_528) };
                                                                      Size choose_res_851;
                                                                      if (id_850) {
                                                                        Size id_852 { 2UL };
                                                                        Arr<t*> id_853 { std::get<32 /* VVec */>((*p_0)) };
                                                                        uint32_t id_854 { id_853.size() };
                                                                        Vec<1, uint32_t> id_855 {  id_854  };
                                                                        Size let_res_856;
                                                                        {
                                                                          Vec<1, uint32_t> n_ref_548 { id_855 };
                                                                          uint32_t id_857 { 1U };
                                                                          Vec<1, uint32_t> id_858 {  id_857  };
                                                                          Size let_res_859;
                                                                          {
                                                                            Vec<1, uint32_t> lebsz_ref_549 { id_858 };
                                                                            bool while_flag_860 { true };
                                                                            do {
                                                                              uint8_t id_861 { 0 };
                                                                              uint32_t id_862 { n_ref_548[id_861] };
                                                                              uint8_t id_863 { 0 };
                                                                              uint32_t id_864 { lebsz_ref_549[id_863] };
                                                                              uint8_t id_865 { 7 };
                                                                              uint32_t id_866 { uint32_t(id_864 << id_865) };
                                                                              bool id_867 { bool(id_862 >= id_866) };
                                                                              while_flag_860 = id_867;
                                                                              if (while_flag_860) {
                                                                                uint8_t id_868 { 0 };
                                                                                uint8_t id_869 { 0 };
                                                                                uint32_t id_870 { lebsz_ref_549[id_869] };
                                                                                uint32_t id_871 { 1U };
                                                                                uint32_t id_872 { uint32_t(id_870 + id_871) };
                                                                                Void id_873 { ((void)(lebsz_ref_549[id_868] = id_872), VOID) };
                                                                                (void)id_873;
                                                                              }
                                                                            } while (while_flag_860);
                                                                            (void)VOID;
                                                                            uint8_t id_874 { 0 };
                                                                            uint32_t id_875 { lebsz_ref_549[id_874] };
                                                                            Size id_876 { Size(id_875) };
                                                                            let_res_859 = id_876;
                                                                          }
                                                                          let_res_856 = let_res_859;
                                                                        }
                                                                        Size id_877 { Size(id_852 + let_res_856) };
                                                                        Vec<1, Size> id_878 {  id_877  };
                                                                        Size let_res_879;
                                                                        {
                                                                          Vec<1, Size> sz_ref_550 { id_878 };
                                                                          int32_t id_880 { 0L };
                                                                          Vec<1, int32_t> id_881 {  id_880  };
                                                                          {
                                                                            Vec<1, int32_t> repeat_n_551 { id_881 };
                                                                            bool while_flag_882 { true };
                                                                            do {
                                                                              Arr<t*> id_883 { std::get<32 /* VVec */>((*p_0)) };
                                                                              uint32_t id_884 { id_883.size() };
                                                                              int32_t id_885 { int32_t(id_884) };
                                                                              uint8_t id_886 { 0 };
                                                                              int32_t id_887 { repeat_n_551[id_886] };
                                                                              bool id_888 { bool(id_885 > id_887) };
                                                                              while_flag_882 = id_888;
                                                                              if (while_flag_882) {
                                                                                uint8_t id_889 { 0 };
                                                                                uint8_t id_890 { 0 };
                                                                                Size id_891 { sz_ref_550[id_890] };
                                                                                uint8_t id_892 { 0 };
                                                                                int32_t id_893 { repeat_n_551[id_892] };
                                                                                Arr<t*> id_894 { std::get<32 /* VVec */>((*p_0)) };
                                                                                t* id_895 { id_894[id_893] };
                                                                                Size id_896 { fun613(id_895) };
                                                                                Size id_897 { Size(id_891 + id_896) };
                                                                                Void id_898 { ((void)(sz_ref_550[id_889] = id_897), VOID) };
                                                                                (void)id_898;
                                                                                uint8_t id_899 { 0 };
                                                                                uint8_t id_900 { 0 };
                                                                                int32_t id_901 { repeat_n_551[id_900] };
                                                                                int32_t id_902 { 1L };
                                                                                int32_t id_903 { int32_t(id_901 + id_902) };
                                                                                Void id_904 { ((void)(repeat_n_551[id_899] = id_903), VOID) };
                                                                                (void)id_904;
                                                                                (void)id_904;
                                                                              }
                                                                            } while (while_flag_882);
                                                                            (void)VOID;
                                                                          }
                                                                          (void)VOID;
                                                                          uint8_t id_905 { 0 };
                                                                          Size id_906 { sz_ref_550[id_905] };
                                                                          let_res_879 = id_906;
                                                                        }
                                                                        choose_res_851 = let_res_879;
                                                                      } else {
                                                                        uint16_t id_907 { 33 };
                                                                        bool id_908 { bool(id_907 == label2_528) };
                                                                        Size choose_res_909;
                                                                        if (id_908) {
                                                                          Size id_910 { 2UL };
                                                                          Arr<t*> id_911 { std::get<33 /* VLst */>((*p_0)) };
                                                                          uint32_t id_912 { id_911.size() };
                                                                          Vec<1, uint32_t> id_913 {  id_912  };
                                                                          Size let_res_914;
                                                                          {
                                                                            Vec<1, uint32_t> n_ref_544 { id_913 };
                                                                            uint32_t id_915 { 1U };
                                                                            Vec<1, uint32_t> id_916 {  id_915  };
                                                                            Size let_res_917;
                                                                            {
                                                                              Vec<1, uint32_t> lebsz_ref_545 { id_916 };
                                                                              bool while_flag_918 { true };
                                                                              do {
                                                                                uint8_t id_919 { 0 };
                                                                                uint32_t id_920 { n_ref_544[id_919] };
                                                                                uint8_t id_921 { 0 };
                                                                                uint32_t id_922 { lebsz_ref_545[id_921] };
                                                                                uint8_t id_923 { 7 };
                                                                                uint32_t id_924 { uint32_t(id_922 << id_923) };
                                                                                bool id_925 { bool(id_920 >= id_924) };
                                                                                while_flag_918 = id_925;
                                                                                if (while_flag_918) {
                                                                                  uint8_t id_926 { 0 };
                                                                                  uint8_t id_927 { 0 };
                                                                                  uint32_t id_928 { lebsz_ref_545[id_927] };
                                                                                  uint32_t id_929 { 1U };
                                                                                  uint32_t id_930 { uint32_t(id_928 + id_929) };
                                                                                  Void id_931 { ((void)(lebsz_ref_545[id_926] = id_930), VOID) };
                                                                                  (void)id_931;
                                                                                }
                                                                              } while (while_flag_918);
                                                                              (void)VOID;
                                                                              uint8_t id_932 { 0 };
                                                                              uint32_t id_933 { lebsz_ref_545[id_932] };
                                                                              Size id_934 { Size(id_933) };
                                                                              let_res_917 = id_934;
                                                                            }
                                                                            let_res_914 = let_res_917;
                                                                          }
                                                                          Size id_935 { Size(id_910 + let_res_914) };
                                                                          Vec<1, Size> id_936 {  id_935  };
                                                                          Size let_res_937;
                                                                          {
                                                                            Vec<1, Size> sz_ref_546 { id_936 };
                                                                            int32_t id_938 { 0L };
                                                                            Vec<1, int32_t> id_939 {  id_938  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_547 { id_939 };
                                                                              bool while_flag_940 { true };
                                                                              do {
                                                                                Arr<t*> id_941 { std::get<33 /* VLst */>((*p_0)) };
                                                                                uint32_t id_942 { id_941.size() };
                                                                                int32_t id_943 { int32_t(id_942) };
                                                                                uint8_t id_944 { 0 };
                                                                                int32_t id_945 { repeat_n_547[id_944] };
                                                                                bool id_946 { bool(id_943 > id_945) };
                                                                                while_flag_940 = id_946;
                                                                                if (while_flag_940) {
                                                                                  uint8_t id_947 { 0 };
                                                                                  uint8_t id_948 { 0 };
                                                                                  Size id_949 { sz_ref_546[id_948] };
                                                                                  uint8_t id_950 { 0 };
                                                                                  int32_t id_951 { repeat_n_547[id_950] };
                                                                                  Arr<t*> id_952 { std::get<33 /* VLst */>((*p_0)) };
                                                                                  t* id_953 { id_952[id_951] };
                                                                                  Size id_954 { fun613(id_953) };
                                                                                  Size id_955 { Size(id_949 + id_954) };
                                                                                  Void id_956 { ((void)(sz_ref_546[id_947] = id_955), VOID) };
                                                                                  (void)id_956;
                                                                                  uint8_t id_957 { 0 };
                                                                                  uint8_t id_958 { 0 };
                                                                                  int32_t id_959 { repeat_n_547[id_958] };
                                                                                  int32_t id_960 { 1L };
                                                                                  int32_t id_961 { int32_t(id_959 + id_960) };
                                                                                  Void id_962 { ((void)(repeat_n_547[id_957] = id_961), VOID) };
                                                                                  (void)id_962;
                                                                                  (void)id_962;
                                                                                }
                                                                              } while (while_flag_940);
                                                                              (void)VOID;
                                                                            }
                                                                            (void)VOID;
                                                                            uint8_t id_963 { 0 };
                                                                            Size id_964 { sz_ref_546[id_963] };
                                                                            let_res_937 = id_964;
                                                                          }
                                                                          choose_res_909 = let_res_937;
                                                                        } else {
                                                                          uint16_t id_965 { 34 };
                                                                          bool id_966 { bool(id_965 == label2_528) };
                                                                          Size choose_res_967;
                                                                          if (id_966) {
                                                                            Size id_968 { 2UL };
                                                                            Arr<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_969 { std::get<34 /* VRec */>((*p_0)) };
                                                                            uint32_t id_970 { id_969.size() };
                                                                            Vec<1, uint32_t> id_971 {  id_970  };
                                                                            Size let_res_972;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_535 { id_971 };
                                                                              uint32_t id_973 { 1U };
                                                                              Vec<1, uint32_t> id_974 {  id_973  };
                                                                              Size let_res_975;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_536 { id_974 };
                                                                                bool while_flag_976 { true };
                                                                                do {
                                                                                  uint8_t id_977 { 0 };
                                                                                  uint32_t id_978 { n_ref_535[id_977] };
                                                                                  uint8_t id_979 { 0 };
                                                                                  uint32_t id_980 { lebsz_ref_536[id_979] };
                                                                                  uint8_t id_981 { 7 };
                                                                                  uint32_t id_982 { uint32_t(id_980 << id_981) };
                                                                                  bool id_983 { bool(id_978 >= id_982) };
                                                                                  while_flag_976 = id_983;
                                                                                  if (while_flag_976) {
                                                                                    uint8_t id_984 { 0 };
                                                                                    uint8_t id_985 { 0 };
                                                                                    uint32_t id_986 { lebsz_ref_536[id_985] };
                                                                                    uint32_t id_987 { 1U };
                                                                                    uint32_t id_988 { uint32_t(id_986 + id_987) };
                                                                                    Void id_989 { ((void)(lebsz_ref_536[id_984] = id_988), VOID) };
                                                                                    (void)id_989;
                                                                                  }
                                                                                } while (while_flag_976);
                                                                                (void)VOID;
                                                                                uint8_t id_990 { 0 };
                                                                                uint32_t id_991 { lebsz_ref_536[id_990] };
                                                                                Size id_992 { Size(id_991) };
                                                                                let_res_975 = id_992;
                                                                              }
                                                                              let_res_972 = let_res_975;
                                                                            }
                                                                            Size id_993 { Size(id_968 + let_res_972) };
                                                                            Vec<1, Size> id_994 {  id_993  };
                                                                            Size let_res_995;
                                                                            {
                                                                              Vec<1, Size> sz_ref_537 { id_994 };
                                                                              int32_t id_996 { 0L };
                                                                              Vec<1, int32_t> id_997 {  id_996  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_538 { id_997 };
                                                                                bool while_flag_998 { true };
                                                                                do {
                                                                                  Arr<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_999 { std::get<34 /* VRec */>((*p_0)) };
                                                                                  uint32_t id_1000 { id_999.size() };
                                                                                  int32_t id_1001 { int32_t(id_1000) };
                                                                                  uint8_t id_1002 { 0 };
                                                                                  int32_t id_1003 { repeat_n_538[id_1002] };
                                                                                  bool id_1004 { bool(id_1001 > id_1003) };
                                                                                  while_flag_998 = id_1004;
                                                                                  if (while_flag_998) {
                                                                                    uint8_t id_1005 { 0 };
                                                                                    uint8_t id_1006 { 0 };
                                                                                    Size id_1007 { sz_ref_537[id_1006] };
                                                                                    Size let_res_1008;
                                                                                    {
                                                                                      Size sz_539 { id_1007 };
                                                                                      uint8_t id_1009 { 0 };
                                                                                      int32_t id_1010 { repeat_n_538[id_1009] };
                                                                                      Arr<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_1011 { std::get<34 /* VRec */>((*p_0)) };
                                                                                      ::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c id_1012 { id_1011[id_1010] };
                                                                                      std::string id_1013 { std::get<0>(id_1012) };
                                                                                      uint32_t id_1014 { (uint32_t)id_1013.size() };
                                                                                      Size let_res_1015;
                                                                                      {
                                                                                        uint32_t wlen_540 { id_1014 };
                                                                                        Vec<1, uint32_t> id_1016 {  wlen_540  };
                                                                                        Size let_res_1017;
                                                                                        {
                                                                                          Vec<1, uint32_t> n_ref_541 { id_1016 };
                                                                                          uint32_t id_1018 { 1U };
                                                                                          Vec<1, uint32_t> id_1019 {  id_1018  };
                                                                                          Size let_res_1020;
                                                                                          {
                                                                                            Vec<1, uint32_t> lebsz_ref_542 { id_1019 };
                                                                                            bool while_flag_1021 { true };
                                                                                            do {
                                                                                              uint8_t id_1022 { 0 };
                                                                                              uint32_t id_1023 { n_ref_541[id_1022] };
                                                                                              uint8_t id_1024 { 0 };
                                                                                              uint32_t id_1025 { lebsz_ref_542[id_1024] };
                                                                                              uint8_t id_1026 { 7 };
                                                                                              uint32_t id_1027 { uint32_t(id_1025 << id_1026) };
                                                                                              bool id_1028 { bool(id_1023 >= id_1027) };
                                                                                              while_flag_1021 = id_1028;
                                                                                              if (while_flag_1021) {
                                                                                                uint8_t id_1029 { 0 };
                                                                                                uint8_t id_1030 { 0 };
                                                                                                uint32_t id_1031 { lebsz_ref_542[id_1030] };
                                                                                                uint32_t id_1032 { 1U };
                                                                                                uint32_t id_1033 { uint32_t(id_1031 + id_1032) };
                                                                                                Void id_1034 { ((void)(lebsz_ref_542[id_1029] = id_1033), VOID) };
                                                                                                (void)id_1034;
                                                                                              }
                                                                                            } while (while_flag_1021);
                                                                                            (void)VOID;
                                                                                            uint8_t id_1035 { 0 };
                                                                                            uint32_t id_1036 { lebsz_ref_542[id_1035] };
                                                                                            Size id_1037 { Size(id_1036) };
                                                                                            let_res_1020 = id_1037;
                                                                                          }
                                                                                          let_res_1017 = let_res_1020;
                                                                                        }
                                                                                        Size id_1038 { Size(wlen_540) };
                                                                                        Size id_1039 { Size(let_res_1017 + id_1038) };
                                                                                        let_res_1015 = id_1039;
                                                                                      }
                                                                                      Size id_1040 { Size(sz_539 + let_res_1015) };
                                                                                      let_res_1008 = id_1040;
                                                                                    }
                                                                                    Size let_res_1041;
                                                                                    {
                                                                                      Size sz_543 { let_res_1008 };
                                                                                      uint8_t id_1042 { 0 };
                                                                                      int32_t id_1043 { repeat_n_538[id_1042] };
                                                                                      Arr<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_1044 { std::get<34 /* VRec */>((*p_0)) };
                                                                                      ::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c id_1045 { id_1044[id_1043] };
                                                                                      t* id_1046 { std::get<1>(id_1045) };
                                                                                      Size id_1047 { fun613(id_1046) };
                                                                                      Size id_1048 { Size(sz_543 + id_1047) };
                                                                                      let_res_1041 = id_1048;
                                                                                    }
                                                                                    Void id_1049 { ((void)(sz_ref_537[id_1005] = let_res_1041), VOID) };
                                                                                    (void)id_1049;
                                                                                    uint8_t id_1050 { 0 };
                                                                                    uint8_t id_1051 { 0 };
                                                                                    int32_t id_1052 { repeat_n_538[id_1051] };
                                                                                    int32_t id_1053 { 1L };
                                                                                    int32_t id_1054 { int32_t(id_1052 + id_1053) };
                                                                                    Void id_1055 { ((void)(repeat_n_538[id_1050] = id_1054), VOID) };
                                                                                    (void)id_1055;
                                                                                    (void)id_1055;
                                                                                  }
                                                                                } while (while_flag_998);
                                                                                (void)VOID;
                                                                              }
                                                                              (void)VOID;
                                                                              uint8_t id_1056 { 0 };
                                                                              Size id_1057 { sz_ref_537[id_1056] };
                                                                              let_res_995 = id_1057;
                                                                            }
                                                                            choose_res_967 = let_res_995;
                                                                          } else {
                                                                            uint16_t id_1058 { 35 };
                                                                            bool id_1059 { bool(label2_528 == id_1058) };
                                                                            Void id_1060 { ((void)(assert(id_1059)), VOID) };
                                                                            (void)id_1060;
                                                                            Size id_1061 { 2UL };
                                                                            Arr<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> id_1062 { std::get<35 /* VMap */>((*p_0)) };
                                                                            uint32_t id_1063 { id_1062.size() };
                                                                            Vec<1, uint32_t> id_1064 {  id_1063  };
                                                                            Size let_res_1065;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_529 { id_1064 };
                                                                              uint32_t id_1066 { 1U };
                                                                              Vec<1, uint32_t> id_1067 {  id_1066  };
                                                                              Size let_res_1068;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_530 { id_1067 };
                                                                                bool while_flag_1069 { true };
                                                                                do {
                                                                                  uint8_t id_1070 { 0 };
                                                                                  uint32_t id_1071 { n_ref_529[id_1070] };
                                                                                  uint8_t id_1072 { 0 };
                                                                                  uint32_t id_1073 { lebsz_ref_530[id_1072] };
                                                                                  uint8_t id_1074 { 7 };
                                                                                  uint32_t id_1075 { uint32_t(id_1073 << id_1074) };
                                                                                  bool id_1076 { bool(id_1071 >= id_1075) };
                                                                                  while_flag_1069 = id_1076;
                                                                                  if (while_flag_1069) {
                                                                                    uint8_t id_1077 { 0 };
                                                                                    uint8_t id_1078 { 0 };
                                                                                    uint32_t id_1079 { lebsz_ref_530[id_1078] };
                                                                                    uint32_t id_1080 { 1U };
                                                                                    uint32_t id_1081 { uint32_t(id_1079 + id_1080) };
                                                                                    Void id_1082 { ((void)(lebsz_ref_530[id_1077] = id_1081), VOID) };
                                                                                    (void)id_1082;
                                                                                  }
                                                                                } while (while_flag_1069);
                                                                                (void)VOID;
                                                                                uint8_t id_1083 { 0 };
                                                                                uint32_t id_1084 { lebsz_ref_530[id_1083] };
                                                                                Size id_1085 { Size(id_1084) };
                                                                                let_res_1068 = id_1085;
                                                                              }
                                                                              let_res_1065 = let_res_1068;
                                                                            }
                                                                            Size id_1086 { Size(id_1061 + let_res_1065) };
                                                                            Vec<1, Size> id_1087 {  id_1086  };
                                                                            Size let_res_1088;
                                                                            {
                                                                              Vec<1, Size> sz_ref_531 { id_1087 };
                                                                              int32_t id_1089 { 0L };
                                                                              Vec<1, int32_t> id_1090 {  id_1089  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_532 { id_1090 };
                                                                                bool while_flag_1091 { true };
                                                                                do {
                                                                                  Arr<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> id_1092 { std::get<35 /* VMap */>((*p_0)) };
                                                                                  uint32_t id_1093 { id_1092.size() };
                                                                                  int32_t id_1094 { int32_t(id_1093) };
                                                                                  uint8_t id_1095 { 0 };
                                                                                  int32_t id_1096 { repeat_n_532[id_1095] };
                                                                                  bool id_1097 { bool(id_1094 > id_1096) };
                                                                                  while_flag_1091 = id_1097;
                                                                                  if (while_flag_1091) {
                                                                                    uint8_t id_1098 { 0 };
                                                                                    uint8_t id_1099 { 0 };
                                                                                    Size id_1100 { sz_ref_531[id_1099] };
                                                                                    uint8_t id_1101 { 0 };
                                                                                    int32_t id_1102 { repeat_n_532[id_1101] };
                                                                                    Arr<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> id_1103 { std::get<35 /* VMap */>((*p_0)) };
                                                                                    ::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf id_1104 { id_1103[id_1102] };
                                                                                    t* id_1105 { std::get<0>(id_1104) };
                                                                                    Size id_1106 { fun613(id_1105) };
                                                                                    Size id_1107 { Size(id_1100 + id_1106) };
                                                                                    uint8_t id_1108 { 0 };
                                                                                    int32_t id_1109 { repeat_n_532[id_1108] };
                                                                                    Arr<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> id_1110 { std::get<35 /* VMap */>((*p_0)) };
                                                                                    ::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf id_1111 { id_1110[id_1109] };
                                                                                    t* id_1112 { std::get<1>(id_1111) };
                                                                                    Size id_1113 { fun613(id_1112) };
                                                                                    Size id_1114 { Size(id_1107 + id_1113) };
                                                                                    Void id_1115 { ((void)(sz_ref_531[id_1098] = id_1114), VOID) };
                                                                                    (void)id_1115;
                                                                                    uint8_t id_1116 { 0 };
                                                                                    uint8_t id_1117 { 0 };
                                                                                    int32_t id_1118 { repeat_n_532[id_1117] };
                                                                                    int32_t id_1119 { 1L };
                                                                                    int32_t id_1120 { int32_t(id_1118 + id_1119) };
                                                                                    Void id_1121 { ((void)(repeat_n_532[id_1116] = id_1120), VOID) };
                                                                                    (void)id_1121;
                                                                                    (void)id_1121;
                                                                                  }
                                                                                } while (while_flag_1091);
                                                                                (void)VOID;
                                                                              }
                                                                              (void)VOID;
                                                                              uint8_t id_1122 { 0 };
                                                                              Size id_1123 { sz_ref_531[id_1122] };
                                                                              let_res_1088 = id_1123;
                                                                            }
                                                                            choose_res_967 = let_res_1088;
                                                                          }
                                                                          choose_res_909 = choose_res_967;
                                                                        }
                                                                        choose_res_851 = choose_res_909;
                                                                      }
                                                                      choose_res_793 = choose_res_851;
                                                                    }
                                                                    choose_res_778 = choose_res_793;
                                                                  }
                                                                  choose_res_774 = choose_res_778;
                                                                }
                                                                choose_res_770 = choose_res_774;
                                                              }
                                                              choose_res_755 = choose_res_770;
                                                            }
                                                            choose_res_751 = choose_res_755;
                                                          }
                                                          choose_res_747 = choose_res_751;
                                                        }
                                                        choose_res_743 = choose_res_747;
                                                      }
                                                      choose_res_739 = choose_res_743;
                                                    }
                                                    choose_res_735 = choose_res_739;
                                                  }
                                                  choose_res_731 = choose_res_735;
                                                }
                                                choose_res_727 = choose_res_731;
                                              }
                                              choose_res_723 = choose_res_727;
                                            }
                                            choose_res_719 = choose_res_723;
                                          }
                                          choose_res_715 = choose_res_719;
                                        }
                                        choose_res_711 = choose_res_715;
                                      }
                                      choose_res_707 = choose_res_711;
                                    }
                                    choose_res_703 = choose_res_707;
                                  }
                                  choose_res_699 = choose_res_703;
                                }
                                choose_res_695 = choose_res_699;
                              }
                              choose_res_691 = choose_res_695;
                            }
                            choose_res_687 = choose_res_691;
                          }
                          choose_res_683 = choose_res_687;
                        }
                        choose_res_679 = choose_res_683;
                      }
                      choose_res_675 = choose_res_679;
                    }
                    choose_res_671 = choose_res_675;
                  }
                  choose_res_667 = choose_res_671;
                }
                choose_res_663 = choose_res_667;
              }
              choose_res_630 = choose_res_663;
            }
            choose_res_626 = choose_res_630;
          }
          choose_res_622 = choose_res_626;
        }
        choose_res_618 = choose_res_622;
      }
      let_res_615 = choose_res_618;
    }
    return let_res_615;
  }
   };
  return fun613;
}
std::function<Size(::dessser::gen::raql_value::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_526" "make_snd_527"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (make-tup
                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 0
                  (nop)) (identifier "dsum1_snd_64"))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (make-tup
                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 1
                    (nop)) (identifier "dsum1_snd_64"))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (let-pair "dfloat_fst_514" "dfloat_snd_515" (read-u64 little-endian (identifier "dsum1_snd_64"))
                    (make-tup
                      (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 2
                        (float-of-u64 (identifier "dfloat_fst_514"))) 
                      (identifier "dfloat_snd_515")))
                  (if (eq (u16 3) (identifier "dsum1_fst_63"))
                    (let "dstring1_504"
                      (let "leb_ref_498" (make-vec (u32 0))
                        (let "shft_ref_499" (make-vec (u8 0))
                          (let "p_ref_500" (make-vec (identifier "dsum1_snd_64"))
                            (seq
                              (while
                                (let "leb128_501" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_500")))
                                  (let-pair "leb128_fst_502" "leb128_snd_503" 
                                    (identifier "leb128_501")
                                    (seq (set-vec (u8 0) (identifier "p_ref_500") (identifier "leb128_snd_503"))
                                      (set-vec (u8 0) (identifier "leb_ref_498")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_502") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_499"))) (unsafe-nth (u8 0) (identifier "leb_ref_498"))))
                                      (set-vec (u8 0) (identifier "shft_ref_499") (add (unsafe-nth (u8 0) (identifier "shft_ref_499")) (u8 7))) 
                                      (ge (identifier "leb128_fst_502") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_498"))) (unsafe-nth (u8 0) (identifier "p_ref_500")))))))
                      (let-pair "dstring1_fst_505" "dstring1_snd_506" 
                        (identifier "dstring1_504")
                        (let-pair "dstring2_fst_508" "dstring2_snd_509" 
                          (read-bytes (identifier "dstring1_snd_506") (identifier "dstring1_fst_505"))
                          (make-tup
                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 3
                              (string-of-bytes (identifier "dstring2_fst_508"))) 
                            (identifier "dstring2_snd_509")))))
                    (if (eq (u16 4) (identifier "dsum1_fst_63"))
                      (let-pair "dbool_fst_493" "dbool_snd_494" (read-u8 (identifier "dsum1_snd_64"))
                        (make-tup
                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 4
                            (not (eq (identifier "dbool_fst_493") (u8 0)))) 
                          (identifier "dbool_snd_494")))
                      (if (eq (u16 5) (identifier "dsum1_fst_63"))
                        (let-pair "dchar_fst_487" "dchar_snd_488" (read-u8 (identifier "dsum1_snd_64"))
                          (make-tup
                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 5
                              (char-of-u8 (identifier "dchar_fst_487"))) 
                            (identifier "dchar_snd_488")))
                        (if (eq (u16 6) (identifier "dsum1_fst_63"))
                          (let-pair "du8_fst_481" "du8_snd_482" (read-u8 (identifier "dsum1_snd_64"))
                            (make-tup
                              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 6
                                (identifier "du8_fst_481")) (identifier "du8_snd_482")))
                          (if (eq (u16 7) (identifier "dsum1_fst_63"))
                            (let-pair "du16_fst_475" "du16_snd_476" (read-u16 little-endian (identifier "dsum1_snd_64"))
                              (make-tup
                                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 7
                                  (identifier "du16_fst_475")) (identifier "du16_snd_476")))
                            (if (eq (u16 8) (identifier "dsum1_fst_63"))
                              (let-pair "du24_fst_469" "du24_snd_470" 
                                (read-u32 little-endian (identifier "dsum1_snd_64"))
                                (make-tup
                                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 8
                                    (to-u24 (identifier "du24_fst_469"))) 
                                  (identifier "du24_snd_470")))
                              (if (eq (u16 9) (identifier "dsum1_fst_63"))
                                (let-pair "du32_fst_463" "du32_snd_464" 
                                  (read-u32 little-endian (identifier "dsum1_snd_64"))
                                  (make-tup
                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 9
                                      (identifier "du32_fst_463")) (identifier "du32_snd_464")))
                                (if (eq (u16 10) (identifier "dsum1_fst_63"))
                                  (let-pair "du40_fst_457" "du40_snd_458" 
                                    (read-u64 little-endian (identifier "dsum1_snd_64"))
                                    (make-tup
                                      (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 10
                                        (to-u40 (identifier "du40_fst_457"))) 
                                      (identifier "du40_snd_458")))
                                  (if (eq (u16 11) (identifier "dsum1_fst_63"))
                                    (let-pair "du48_fst_451" "du48_snd_452" 
                                      (read-u64 little-endian (identifier "dsum1_snd_64"))
                                      (make-tup
                                        (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 11
                                          (to-u48 (identifier "du48_fst_451"))) 
                                        (identifier "du48_snd_452")))
                                    (if (eq (u16 12) (identifier "dsum1_fst_63"))
                                      (let-pair "du56_fst_445" "du56_snd_446" 
                                        (read-u64 little-endian (identifier "dsum1_snd_64"))
                                        (make-tup
                                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 12
                                            (to-u56 (identifier "du56_fst_445"))) 
                                          (identifier "du56_snd_446")))
                                      (if (eq (u16 13) (identifier "dsum1_fst_63"))
                                        (let-pair "du64_fst_439" "du64_snd_440" 
                                          (read-u64 little-endian (identifier "dsum1_snd_64"))
                                          (make-tup
                                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 13
                                              (identifier "du64_fst_439")) 
                                            (identifier "du64_snd_440")))
                                        (if (eq (u16 14) (identifier "dsum1_fst_63"))
                                          (let-pair "di128_fst_433" "di128_snd_434" 
                                            (read-u128 little-endian (identifier "dsum1_snd_64"))
                                            (make-tup
                                              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 14
                                                (identifier "di128_fst_433")) 
                                              (identifier "di128_snd_434")))
                                          (if (eq (u16 15) (identifier "dsum1_fst_63"))
                                            (let-pair "di8_fst_427" "di8_snd_428" 
                                              (read-u8 (identifier "dsum1_snd_64"))
                                              (make-tup
                                                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 15
                                                  (to-i8 (identifier "di8_fst_427"))) 
                                                (identifier "di8_snd_428")))
                                            (if (eq (u16 16) (identifier "dsum1_fst_63"))
                                              (let-pair "di16_fst_421" "di16_snd_422" 
                                                (read-u16 little-endian (identifier "dsum1_snd_64"))
                                                (make-tup
                                                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 16
                                                    (to-i16 (identifier "di16_fst_421"))) 
                                                  (identifier "di16_snd_422")))
                                              (if (eq (u16 17) (identifier "dsum1_fst_63"))
                                                (let-pair "di24_fst_415" "di24_snd_416" 
                                                  (read-u32 little-endian (identifier "dsum1_snd_64"))
                                                  (make-tup
                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 17
                                                      (to-i24 (identifier "di24_fst_415"))) 
                                                    (identifier "di24_snd_416")))
                                                (if (eq (u16 18) (identifier "dsum1_fst_63"))
                                                  (let-pair "di32_fst_409" "di32_snd_410" 
                                                    (read-u32 little-endian (identifier "dsum1_snd_64"))
                                                    (make-tup
                                                      (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 18
                                                        (to-i32 (identifier "di32_fst_409"))) 
                                                      (identifier "di32_snd_410")))
                                                  (if (eq (u16 19) (identifier "dsum1_fst_63"))
                                                    (let-pair "di40_fst_403" "di40_snd_404" 
                                                      (read-u64 little-endian (identifier "dsum1_snd_64"))
                                                      (make-tup
                                                        (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 19
                                                          (to-i40 (identifier "di40_fst_403"))) 
                                                        (identifier "di40_snd_404")))
                                                    (if (eq (u16 20) (identifier "dsum1_fst_63"))
                                                      (let-pair "di48_fst_397" "di48_snd_398" 
                                                        (read-u64 little-endian (identifier "dsum1_snd_64"))
                                                        (make-tup
                                                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 20
                                                            (to-i48 (identifier "di48_fst_397"))) 
                                                          (identifier "di48_snd_398")))
                                                      (if (eq (u16 21) (identifier "dsum1_fst_63"))
                                                        (let-pair "di56_fst_391" "di56_snd_392" 
                                                          (read-u64 little-endian (identifier "dsum1_snd_64"))
                                                          (make-tup
                                                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 21
                                                              (to-i56 (identifier "di56_fst_391"))) 
                                                            (identifier "di56_snd_392")))
                                                        (if (eq (u16 22) (identifier "dsum1_fst_63"))
                                                          (let-pair "di64_fst_385" "di64_snd_386" 
                                                            (read-u64 little-endian (identifier "dsum1_snd_64"))
                                                            (make-tup
                                                              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 22
                                                                (to-i64 (identifier "di64_fst_385"))) 
                                                              (identifier "di64_snd_386")))
                                                          (if (eq (u16 23) (identifier "dsum1_fst_63"))
                                                            (let-pair "di128_fst_379" "di128_snd_380" 
                                                              (read-u128 little-endian (identifier "dsum1_snd_64"))
                                                              (make-tup
                                                                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 23
                                                                  (to-i128 (identifier "di128_fst_379"))) 
                                                                (identifier "di128_snd_380")))
                                                            (if (eq (u16 24) (identifier "dsum1_fst_63"))
                                                              (let-pair "du48_fst_370" "du48_snd_371" 
                                                                (read-u64 little-endian (identifier "dsum1_snd_64"))
                                                                (make-tup
                                                                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 24
                                                                    (make-usr "Eth" (to-u48 (identifier "du48_fst_370")))) 
                                                                  (identifier "du48_snd_371")))
                                                              (if (eq (u16 25) (identifier "dsum1_fst_63"))
                                                                (let-pair "du32_fst_361" "du32_snd_362" 
                                                                  (read-u32 little-endian (identifier "dsum1_snd_64"))
                                                                  (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 25
                                                                    (make-usr "Ip4" (identifier "du32_fst_361"))) 
                                                                    (identifier "du32_snd_362")))
                                                                (if (eq (u16 26) (identifier "dsum1_fst_63"))
                                                                  (let-pair "di128_fst_352" "di128_snd_353" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_64"))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 26
                                                                    (make-usr "Ip6" (identifier "di128_fst_352"))) 
                                                                    (identifier "di128_snd_353")))
                                                                  (if 
                                                                    (eq (u16 27) (identifier "dsum1_fst_63"))
                                                                    (let-pair "des_usr_type_fst_346" "des_usr_type_snd_347"
                                                                    (let "dsum1_324"
                                                                    (let-pair "du16_fst_319" "du16_snd_320" (read-u16 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du16_fst_319") (identifier "du16_snd_320")))
                                                                    (let-pair "dsum1_fst_325" "dsum1_snd_326" 
                                                                    (identifier "dsum1_324")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_325"))
                                                                    (let-pair "du32_fst_337" "du32_snd_338" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_326"))
                                                                    (make-tup (construct "[v4 Ip4 | v6 Ip6]" 0 (make-usr "Ip4" (identifier "du32_fst_337"))) (identifier "du32_snd_338")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_325") (u16 1)))
                                                                    (let-pair "di128_fst_328" "di128_snd_329" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_326"))
                                                                    (make-tup (construct "[v4 Ip4 | v6 Ip6]" 1 (make-usr "Ip6" (identifier "di128_fst_328"))) (identifier "di128_snd_329")))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 27
                                                                    (make-usr "Ip" (identifier "des_usr_type_fst_346"))) 
                                                                    (identifier "des_usr_type_snd_347")))
                                                                    (if 
                                                                    (eq (u16 28) (identifier "dsum1_fst_63"))
                                                                    (let "drec_303"
                                                                    (let-pair "du32_fst_298" "du32_snd_299" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_64")) 
                                                                    (make-tup (make-usr "Ip4" (identifier "du32_fst_298")) (identifier "du32_snd_299")))
                                                                    (let-pair "drec_fst_304" "drec_snd_305" 
                                                                    (identifier "drec_303")
                                                                    (let-pair "du8_fst_307" "du8_snd_308" 
                                                                    (read-u8 (identifier "drec_snd_305"))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 28
                                                                    (make-usr "Cidr4" (make-rec (string "mask") (identifier "du8_fst_307") (string "ip") (identifier "drec_fst_304")))) 
                                                                    (identifier "du8_snd_308")))))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "dsum1_fst_63"))
                                                                    (let "drec_282"
                                                                    (let-pair "di128_fst_277" "di128_snd_278" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_64")) 
                                                                    (make-tup (make-usr "Ip6" (identifier "di128_fst_277")) (identifier "di128_snd_278")))
                                                                    (let-pair "drec_fst_283" "drec_snd_284" 
                                                                    (identifier "drec_282")
                                                                    (let-pair "du8_fst_286" "du8_snd_287" 
                                                                    (read-u8 (identifier "drec_snd_284"))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 29
                                                                    (make-usr "Cidr6" (make-rec (string "mask") (identifier "du8_fst_286") (string "ip") (identifier "drec_fst_283")))) 
                                                                    (identifier "du8_snd_287")))))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "dsum1_fst_63"))
                                                                    (let-pair "des_usr_type_fst_271" "des_usr_type_snd_272"
                                                                    (let "dsum1_225"
                                                                    (let-pair "du16_fst_220" "du16_snd_221" (read-u16 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du16_fst_220") (identifier "du16_snd_221")))
                                                                    (let-pair "dsum1_fst_226" "dsum1_snd_227" 
                                                                    (identifier "dsum1_225")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_226"))
                                                                    (let "drec_255"
                                                                    (let-pair "du32_fst_250" "du32_snd_251" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_227")) 
                                                                    (make-tup (make-usr "Ip4" (identifier "du32_fst_250")) (identifier "du32_snd_251")))
                                                                    (let-pair "drec_fst_256" "drec_snd_257" 
                                                                    (identifier "drec_255")
                                                                    (let-pair "du8_fst_259" "du8_snd_260" 
                                                                    (read-u8 (identifier "drec_snd_257"))
                                                                    (make-tup
                                                                    (construct "[v4 Cidr4 | v6 Cidr6]" 0 (make-usr "Cidr4" (make-rec (string "mask") (identifier "du8_fst_259") (string "ip") (identifier "drec_fst_256"))))
                                                                    (identifier "du8_snd_260")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_226") (u16 1)))
                                                                    (let "drec_234"
                                                                    (let-pair "di128_fst_229" "di128_snd_230" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_227")) 
                                                                    (make-tup (make-usr "Ip6" (identifier "di128_fst_229")) (identifier "di128_snd_230")))
                                                                    (let-pair "drec_fst_235" "drec_snd_236" 
                                                                    (identifier "drec_234")
                                                                    (let-pair "du8_fst_238" "du8_snd_239" 
                                                                    (read-u8 (identifier "drec_snd_236"))
                                                                    (make-tup
                                                                    (construct "[v4 Cidr4 | v6 Cidr6]" 1 (make-usr "Cidr6" (make-rec (string "mask") (identifier "du8_fst_238") (string "ip") (identifier "drec_fst_235"))))
                                                                    (identifier "du8_snd_239")))))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 30
                                                                    (make-usr "Cidr" (identifier "des_usr_type_fst_271"))) 
                                                                    (identifier "des_usr_type_snd_272")))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "dsum1_fst_63"))
                                                                    (let-pair "dlist4_fst_214" "dlist4_snd_215"
                                                                    (let "dlist1_202"
                                                                    (let "leb_ref_193" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_194" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_195" 
                                                                    (make-vec (identifier "dsum1_snd_64"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_196" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_195")))
                                                                    (let-pair "leb128_fst_197" "leb128_snd_198" 
                                                                    (identifier "leb128_196")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_195") (identifier "leb128_snd_198"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_193")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_197") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_194")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_193")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_194") (add (unsafe-nth (u8 0) (identifier "shft_ref_194")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_197") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_193")) (unsafe-nth (u8 0) (identifier "p_ref_195")))))))
                                                                    (let-pair "dlist1_fst_203" "dlist1_snd_204" 
                                                                    (identifier "dlist1_202")
                                                                    (let "inits_src_ref_205" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_204")))
                                                                    (seq
                                                                    (let "repeat_n_206" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_203")) (unsafe-nth (u8 0) (identifier "repeat_n_206")))
                                                                    (seq
                                                                    (let "dlist2_207" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_205"))
                                                                    (let-pair "dlist2_fst_208" "dlist2_snd_209" 
                                                                    (identifier "dlist2_207")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_205")
                                                                    (let-pair "dlist3_fst_211" "dlist3_snd_212" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_209"))
                                                                    (make-tup (cons (identifier "dlist3_fst_211") (identifier "dlist2_fst_208")) (identifier "dlist3_snd_212"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_206") (add (unsafe-nth (u8 0) (identifier "repeat_n_206")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_205"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 31
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_214"))) 
                                                                    (identifier "dlist4_snd_215")))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "dsum1_fst_63"))
                                                                    (let-pair "dlist4_fst_188" "dlist4_snd_189"
                                                                    (let "dlist1_176"
                                                                    (let "leb_ref_167" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_168" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_169" 
                                                                    (make-vec (identifier "dsum1_snd_64"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_170" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_169")))
                                                                    (let-pair "leb128_fst_171" "leb128_snd_172" 
                                                                    (identifier "leb128_170")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_169") (identifier "leb128_snd_172"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_167")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_171") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_168")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_167")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_168") (add (unsafe-nth (u8 0) (identifier "shft_ref_168")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_171") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_167")) (unsafe-nth (u8 0) (identifier "p_ref_169")))))))
                                                                    (let-pair "dlist1_fst_177" "dlist1_snd_178" 
                                                                    (identifier "dlist1_176")
                                                                    (let "inits_src_ref_179" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_178")))
                                                                    (seq
                                                                    (let "repeat_n_180" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_177")) (unsafe-nth (u8 0) (identifier "repeat_n_180")))
                                                                    (seq
                                                                    (let "dlist2_181" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_179"))
                                                                    (let-pair "dlist2_fst_182" "dlist2_snd_183" 
                                                                    (identifier "dlist2_181")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_179")
                                                                    (let-pair "dlist3_fst_185" "dlist3_snd_186" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_183"))
                                                                    (make-tup (cons (identifier "dlist3_fst_185") (identifier "dlist2_fst_182")) (identifier "dlist3_snd_186"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_180") (add (unsafe-nth (u8 0) (identifier "repeat_n_180")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_179"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 32
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_188"))) 
                                                                    (identifier "dlist4_snd_189")))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "dsum1_fst_63"))
                                                                    (let-pair "dlist4_fst_162" "dlist4_snd_163"
                                                                    (let "dlist1_150"
                                                                    (let "leb_ref_141" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_142" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_143" 
                                                                    (make-vec (identifier "dsum1_snd_64"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_144" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_143")))
                                                                    (let-pair "leb128_fst_145" "leb128_snd_146" 
                                                                    (identifier "leb128_144")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_143") (identifier "leb128_snd_146"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_141")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_145") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_142")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_141")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_142") (add (unsafe-nth (u8 0) (identifier "shft_ref_142")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_145") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_141")) (unsafe-nth (u8 0) (identifier "p_ref_143")))))))
                                                                    (let-pair "dlist1_fst_151" "dlist1_snd_152" 
                                                                    (identifier "dlist1_150")
                                                                    (let "inits_src_ref_153" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_152")))
                                                                    (seq
                                                                    (let "repeat_n_154" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_151")) (unsafe-nth (u8 0) (identifier "repeat_n_154")))
                                                                    (seq
                                                                    (let "dlist2_155" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_153"))
                                                                    (let-pair "dlist2_fst_156" "dlist2_snd_157" 
                                                                    (identifier "dlist2_155")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_153")
                                                                    (let-pair "dlist3_fst_159" "dlist3_snd_160" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_157"))
                                                                    (make-tup (cons (identifier "dlist3_fst_159") (identifier "dlist2_fst_156")) (identifier "dlist3_snd_160"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_154") (add (unsafe-nth (u8 0) (identifier "repeat_n_154")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_153"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 33
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_162"))) 
                                                                    (identifier "dlist4_snd_163")))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "dsum1_fst_63"))
                                                                    (let-pair "dlist4_fst_136" "dlist4_snd_137"
                                                                    (let "dlist1_106"
                                                                    (let "leb_ref_97" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_98" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_99" 
                                                                    (make-vec (identifier "dsum1_snd_64"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_100" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_99")))
                                                                    (let-pair "leb128_fst_101" "leb128_snd_102" 
                                                                    (identifier "leb128_100")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_99") (identifier "leb128_snd_102"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_97")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_101") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_98")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_97")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_98") (add (unsafe-nth (u8 0) (identifier "shft_ref_98")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_101") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_97")) (unsafe-nth (u8 0) (identifier "p_ref_99")))))))
                                                                    (let-pair "dlist1_fst_107" "dlist1_snd_108" 
                                                                    (identifier "dlist1_106")
                                                                    (let "inits_src_ref_109" 
                                                                    (make-vec (make-tup (end-of-list "(STRING; THIS)") (identifier "dlist1_snd_108")))
                                                                    (seq
                                                                    (let "repeat_n_110" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_107")) (unsafe-nth (u8 0) (identifier "repeat_n_110")))
                                                                    (seq
                                                                    (let "dlist2_111" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_109"))
                                                                    (let-pair "dlist2_fst_112" "dlist2_snd_113" 
                                                                    (identifier "dlist2_111")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_109")
                                                                    (let "dstring1_120"
                                                                    (let "leb_ref_114" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_115" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_116" 
                                                                    (make-vec (identifier "dlist2_snd_113"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_117" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_116")))
                                                                    (let-pair "leb128_fst_118" "leb128_snd_119" 
                                                                    (identifier "leb128_117")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_116") (identifier "leb128_snd_119"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_114")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_118") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_115")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_114")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_115") (add (unsafe-nth (u8 0) (identifier "shft_ref_115")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_118") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_114"))) (unsafe-nth (u8 0) (identifier "p_ref_116")))))))
                                                                    (let-pair "dstring1_fst_121" "dstring1_snd_122" 
                                                                    (identifier "dstring1_120")
                                                                    (let-pair "dstring2_fst_124" "dstring2_snd_125" 
                                                                    (read-bytes (identifier "dstring1_snd_122") (identifier "dstring1_fst_121"))
                                                                    (let-pair "dtup_fst_130" "dtup_snd_131" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dstring2_snd_125"))
                                                                    (make-tup 
                                                                    (cons (make-tup (string-of-bytes (identifier "dstring2_fst_124")) (identifier "dtup_fst_130")) (identifier "dlist2_fst_112")) 
                                                                    (identifier "dtup_snd_131"))))))))) 
                                                                    (set-vec (u8 0) (identifier "repeat_n_110") (add (unsafe-nth (u8 0) (identifier "repeat_n_110")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_109"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 34
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_136"))) 
                                                                    (identifier "dlist4_snd_137")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_63") (u16 35)))
                                                                    (let-pair "dlist4_fst_92" "dlist4_snd_93"
                                                                    (let "dlist1_74"
                                                                    (let "leb_ref_65" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_66" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_67" 
                                                                    (make-vec (identifier "dsum1_snd_64"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_68" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_67")))
                                                                    (let-pair "leb128_fst_69" "leb128_snd_70" 
                                                                    (identifier "leb128_68")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_67") (identifier "leb128_snd_70"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_65")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_69") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_66")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_65")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_66") (add (unsafe-nth (u8 0) (identifier "shft_ref_66")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_69") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_65")) (unsafe-nth (u8 0) (identifier "p_ref_67")))))))
                                                                    (let-pair "dlist1_fst_75" "dlist1_snd_76" 
                                                                    (identifier "dlist1_74")
                                                                    (let "inits_src_ref_77" 
                                                                    (make-vec (make-tup (end-of-list "(THIS; THIS)") (identifier "dlist1_snd_76")))
                                                                    (seq
                                                                    (let "repeat_n_78" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_75")) (unsafe-nth (u8 0) (identifier "repeat_n_78")))
                                                                    (seq
                                                                    (let "dlist2_79" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_77"))
                                                                    (let-pair "dlist2_fst_80" "dlist2_snd_81" 
                                                                    (identifier "dlist2_79")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_77")
                                                                    (let-pair "dtup_fst_83" "dtup_snd_84" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_81"))
                                                                    (let-pair "dtup_fst_86" "dtup_snd_87" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_84"))
                                                                    (make-tup (cons (make-tup (identifier "dtup_fst_83") (identifier "dtup_fst_86")) (identifier "dlist2_fst_80")) (identifier "dtup_snd_87")))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_78") (add (unsafe-nth (u8 0) (identifier "repeat_n_78")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_77"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VLst THIS[] | VRec (STRING; THIS)[] | VMap (THIS; THIS)[]]" 35
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_92"))) 
                                                                    (identifier "dlist4_snd_93"))))))))))))))))))))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_526") (identifier "make_snd_527"))))
 */
static std::function<::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0(Pointer)> fun1124 { [&fun1124](Pointer p_0) {
    ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 id_1125 { p_0.readU16Le() };
    ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1126;
    {
      auto du16_fst_57 { std::get<0>(id_1125) };
      auto du16_snd_58 { std::get<1>(id_1125) };
      ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 id_1127 { du16_fst_57, du16_snd_58 };
      letpair_res_1126 = id_1127;
    }
    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 let_res_1128;
    {
      ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_1126 };
      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1129;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_1130 { 0 };
        bool id_1131 { bool(id_1130 == dsum1_fst_63) };
        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1132;
        if (id_1131) {
          (void)VOID;
          ::dessser::gen::raql_value::t* id_1133 { new ::dessser::gen::raql_value::t(std::in_place_index<0>, VOID) };
          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1134 { id_1133, dsum1_snd_64 };
          choose_res_1132 = id_1134;
        } else {
          uint16_t id_1135 { 1 };
          bool id_1136 { bool(id_1135 == dsum1_fst_63) };
          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1137;
          if (id_1136) {
            (void)VOID;
            ::dessser::gen::raql_value::t* id_1138 { new ::dessser::gen::raql_value::t(std::in_place_index<1>, VOID) };
            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1139 { id_1138, dsum1_snd_64 };
            choose_res_1137 = id_1139;
          } else {
            uint16_t id_1140 { 2 };
            bool id_1141 { bool(id_1140 == dsum1_fst_63) };
            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1142;
            if (id_1141) {
              ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1143 { dsum1_snd_64.readU64Le() };
              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1144;
              {
                auto dfloat_fst_514 { std::get<0>(id_1143) };
                auto dfloat_snd_515 { std::get<1>(id_1143) };
                double id_1145 { float_of_qword(dfloat_fst_514) };
                ::dessser::gen::raql_value::t* id_1146 { new ::dessser::gen::raql_value::t(std::in_place_index<2>, id_1145) };
                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1147 { id_1146, dfloat_snd_515 };
                letpair_res_1144 = id_1147;
              }
              choose_res_1142 = letpair_res_1144;
            } else {
              uint16_t id_1148 { 3 };
              bool id_1149 { bool(id_1148 == dsum1_fst_63) };
              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1150;
              if (id_1149) {
                uint32_t id_1151 { 0U };
                Vec<1, uint32_t> id_1152 {  id_1151  };
                ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c let_res_1153;
                {
                  Vec<1, uint32_t> leb_ref_498 { id_1152 };
                  uint8_t id_1154 { 0 };
                  Vec<1, uint8_t> id_1155 {  id_1154  };
                  ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c let_res_1156;
                  {
                    Vec<1, uint8_t> shft_ref_499 { id_1155 };
                    Vec<1, Pointer> id_1157 {  dsum1_snd_64  };
                    ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c let_res_1158;
                    {
                      Vec<1, Pointer> p_ref_500 { id_1157 };
                      bool while_flag_1159 { true };
                      do {
                        uint8_t id_1160 { 0 };
                        Pointer id_1161 { p_ref_500[id_1160] };
                        ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1162 { id_1161.readU8() };
                        bool let_res_1163;
                        {
                          ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 leb128_501 { id_1162 };
                          bool letpair_res_1164;
                          {
                            auto leb128_fst_502 { std::get<0>(leb128_501) };
                            auto leb128_snd_503 { std::get<1>(leb128_501) };
                            uint8_t id_1165 { 0 };
                            Void id_1166 { ((void)(p_ref_500[id_1165] = leb128_snd_503), VOID) };
                            (void)id_1166;
                            uint8_t id_1167 { 0 };
                            uint8_t id_1168 { 127 };
                            uint8_t id_1169 { uint8_t(leb128_fst_502 & id_1168) };
                            uint32_t id_1170 { uint32_t(id_1169) };
                            uint8_t id_1171 { 0 };
                            uint8_t id_1172 { shft_ref_499[id_1171] };
                            uint32_t id_1173 { uint32_t(id_1170 << id_1172) };
                            uint8_t id_1174 { 0 };
                            uint32_t id_1175 { leb_ref_498[id_1174] };
                            uint32_t id_1176 { uint32_t(id_1173 | id_1175) };
                            Void id_1177 { ((void)(leb_ref_498[id_1167] = id_1176), VOID) };
                            (void)id_1177;
                            uint8_t id_1178 { 0 };
                            uint8_t id_1179 { 0 };
                            uint8_t id_1180 { shft_ref_499[id_1179] };
                            uint8_t id_1181 { 7 };
                            uint8_t id_1182 { uint8_t(id_1180 + id_1181) };
                            Void id_1183 { ((void)(shft_ref_499[id_1178] = id_1182), VOID) };
                            (void)id_1183;
                            uint8_t id_1184 { 128 };
                            bool id_1185 { bool(leb128_fst_502 >= id_1184) };
                            letpair_res_1164 = id_1185;
                          }
                          let_res_1163 = letpair_res_1164;
                        }
                        while_flag_1159 = let_res_1163;
                        if (while_flag_1159) {
                          (void)VOID;
                        }
                      } while (while_flag_1159);
                      (void)VOID;
                      uint8_t id_1186 { 0 };
                      uint32_t id_1187 { leb_ref_498[id_1186] };
                      Size id_1188 { Size(id_1187) };
                      uint8_t id_1189 { 0 };
                      Pointer id_1190 { p_ref_500[id_1189] };
                      ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c id_1191 { id_1188, id_1190 };
                      let_res_1158 = id_1191;
                    }
                    let_res_1156 = let_res_1158;
                  }
                  let_res_1153 = let_res_1156;
                }
                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 let_res_1192;
                {
                  ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c dstring1_504 { let_res_1153 };
                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1193;
                  {
                    auto dstring1_fst_505 { std::get<0>(dstring1_504) };
                    auto dstring1_snd_506 { std::get<1>(dstring1_504) };
                    ::dessser::gen::raql_value::t188345aa49abd0cb47ff73fedc219f08 id_1194 { dstring1_snd_506.readBytes(dstring1_fst_505) };
                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1195;
                    {
                      auto dstring2_fst_508 { std::get<0>(id_1194) };
                      auto dstring2_snd_509 { std::get<1>(id_1194) };
                      std::string id_1196 { dstring2_fst_508.toString() };
                      ::dessser::gen::raql_value::t* id_1197 { new ::dessser::gen::raql_value::t(std::in_place_index<3>, id_1196) };
                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1198 { id_1197, dstring2_snd_509 };
                      letpair_res_1195 = id_1198;
                    }
                    letpair_res_1193 = letpair_res_1195;
                  }
                  let_res_1192 = letpair_res_1193;
                }
                choose_res_1150 = let_res_1192;
              } else {
                uint16_t id_1199 { 4 };
                bool id_1200 { bool(id_1199 == dsum1_fst_63) };
                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1201;
                if (id_1200) {
                  ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1202 { dsum1_snd_64.readU8() };
                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1203;
                  {
                    auto dbool_fst_493 { std::get<0>(id_1202) };
                    auto dbool_snd_494 { std::get<1>(id_1202) };
                    uint8_t id_1204 { 0 };
                    bool id_1205 { bool(dbool_fst_493 == id_1204) };
                    bool id_1206 { ! id_1205 };
                    ::dessser::gen::raql_value::t* id_1207 { new ::dessser::gen::raql_value::t(std::in_place_index<4>, id_1206) };
                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1208 { id_1207, dbool_snd_494 };
                    letpair_res_1203 = id_1208;
                  }
                  choose_res_1201 = letpair_res_1203;
                } else {
                  uint16_t id_1209 { 5 };
                  bool id_1210 { bool(id_1209 == dsum1_fst_63) };
                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1211;
                  if (id_1210) {
                    ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1212 { dsum1_snd_64.readU8() };
                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1213;
                    {
                      auto dchar_fst_487 { std::get<0>(id_1212) };
                      auto dchar_snd_488 { std::get<1>(id_1212) };
                      char id_1214 { char(dchar_fst_487) };
                      ::dessser::gen::raql_value::t* id_1215 { new ::dessser::gen::raql_value::t(std::in_place_index<5>, id_1214) };
                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1216 { id_1215, dchar_snd_488 };
                      letpair_res_1213 = id_1216;
                    }
                    choose_res_1211 = letpair_res_1213;
                  } else {
                    uint16_t id_1217 { 6 };
                    bool id_1218 { bool(id_1217 == dsum1_fst_63) };
                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1219;
                    if (id_1218) {
                      ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1220 { dsum1_snd_64.readU8() };
                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1221;
                      {
                        auto du8_fst_481 { std::get<0>(id_1220) };
                        auto du8_snd_482 { std::get<1>(id_1220) };
                        ::dessser::gen::raql_value::t* id_1222 { new ::dessser::gen::raql_value::t(std::in_place_index<6>, du8_fst_481) };
                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1223 { id_1222, du8_snd_482 };
                        letpair_res_1221 = id_1223;
                      }
                      choose_res_1219 = letpair_res_1221;
                    } else {
                      uint16_t id_1224 { 7 };
                      bool id_1225 { bool(id_1224 == dsum1_fst_63) };
                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1226;
                      if (id_1225) {
                        ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 id_1227 { dsum1_snd_64.readU16Le() };
                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1228;
                        {
                          auto du16_fst_475 { std::get<0>(id_1227) };
                          auto du16_snd_476 { std::get<1>(id_1227) };
                          ::dessser::gen::raql_value::t* id_1229 { new ::dessser::gen::raql_value::t(std::in_place_index<7>, du16_fst_475) };
                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1230 { id_1229, du16_snd_476 };
                          letpair_res_1228 = id_1230;
                        }
                        choose_res_1226 = letpair_res_1228;
                      } else {
                        uint16_t id_1231 { 8 };
                        bool id_1232 { bool(id_1231 == dsum1_fst_63) };
                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1233;
                        if (id_1232) {
                          ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1234 { dsum1_snd_64.readU32Le() };
                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1235;
                          {
                            auto du24_fst_469 { std::get<0>(id_1234) };
                            auto du24_snd_470 { std::get<1>(id_1234) };
                            uint32_t id_1236 { uint32_t(du24_fst_469) };
                            ::dessser::gen::raql_value::t* id_1237 { new ::dessser::gen::raql_value::t(std::in_place_index<8>, id_1236) };
                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1238 { id_1237, du24_snd_470 };
                            letpair_res_1235 = id_1238;
                          }
                          choose_res_1233 = letpair_res_1235;
                        } else {
                          uint16_t id_1239 { 9 };
                          bool id_1240 { bool(id_1239 == dsum1_fst_63) };
                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1241;
                          if (id_1240) {
                            ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1242 { dsum1_snd_64.readU32Le() };
                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1243;
                            {
                              auto du32_fst_463 { std::get<0>(id_1242) };
                              auto du32_snd_464 { std::get<1>(id_1242) };
                              ::dessser::gen::raql_value::t* id_1244 { new ::dessser::gen::raql_value::t(std::in_place_index<9>, du32_fst_463) };
                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1245 { id_1244, du32_snd_464 };
                              letpair_res_1243 = id_1245;
                            }
                            choose_res_1241 = letpair_res_1243;
                          } else {
                            uint16_t id_1246 { 10 };
                            bool id_1247 { bool(id_1246 == dsum1_fst_63) };
                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1248;
                            if (id_1247) {
                              ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1249 { dsum1_snd_64.readU64Le() };
                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1250;
                              {
                                auto du40_fst_457 { std::get<0>(id_1249) };
                                auto du40_snd_458 { std::get<1>(id_1249) };
                                uint64_t id_1251 { uint64_t(du40_fst_457) };
                                ::dessser::gen::raql_value::t* id_1252 { new ::dessser::gen::raql_value::t(std::in_place_index<10>, id_1251) };
                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1253 { id_1252, du40_snd_458 };
                                letpair_res_1250 = id_1253;
                              }
                              choose_res_1248 = letpair_res_1250;
                            } else {
                              uint16_t id_1254 { 11 };
                              bool id_1255 { bool(id_1254 == dsum1_fst_63) };
                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1256;
                              if (id_1255) {
                                ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1257 { dsum1_snd_64.readU64Le() };
                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1258;
                                {
                                  auto du48_fst_451 { std::get<0>(id_1257) };
                                  auto du48_snd_452 { std::get<1>(id_1257) };
                                  uint64_t id_1259 { uint64_t(du48_fst_451) };
                                  ::dessser::gen::raql_value::t* id_1260 { new ::dessser::gen::raql_value::t(std::in_place_index<11>, id_1259) };
                                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1261 { id_1260, du48_snd_452 };
                                  letpair_res_1258 = id_1261;
                                }
                                choose_res_1256 = letpair_res_1258;
                              } else {
                                uint16_t id_1262 { 12 };
                                bool id_1263 { bool(id_1262 == dsum1_fst_63) };
                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1264;
                                if (id_1263) {
                                  ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1265 { dsum1_snd_64.readU64Le() };
                                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1266;
                                  {
                                    auto du56_fst_445 { std::get<0>(id_1265) };
                                    auto du56_snd_446 { std::get<1>(id_1265) };
                                    uint64_t id_1267 { uint64_t(du56_fst_445) };
                                    ::dessser::gen::raql_value::t* id_1268 { new ::dessser::gen::raql_value::t(std::in_place_index<12>, id_1267) };
                                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1269 { id_1268, du56_snd_446 };
                                    letpair_res_1266 = id_1269;
                                  }
                                  choose_res_1264 = letpair_res_1266;
                                } else {
                                  uint16_t id_1270 { 13 };
                                  bool id_1271 { bool(id_1270 == dsum1_fst_63) };
                                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1272;
                                  if (id_1271) {
                                    ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1273 { dsum1_snd_64.readU64Le() };
                                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1274;
                                    {
                                      auto du64_fst_439 { std::get<0>(id_1273) };
                                      auto du64_snd_440 { std::get<1>(id_1273) };
                                      ::dessser::gen::raql_value::t* id_1275 { new ::dessser::gen::raql_value::t(std::in_place_index<13>, du64_fst_439) };
                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1276 { id_1275, du64_snd_440 };
                                      letpair_res_1274 = id_1276;
                                    }
                                    choose_res_1272 = letpair_res_1274;
                                  } else {
                                    uint16_t id_1277 { 14 };
                                    bool id_1278 { bool(id_1277 == dsum1_fst_63) };
                                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1279;
                                    if (id_1278) {
                                      ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 id_1280 { dsum1_snd_64.readU128Le() };
                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1281;
                                      {
                                        auto di128_fst_433 { std::get<0>(id_1280) };
                                        auto di128_snd_434 { std::get<1>(id_1280) };
                                        ::dessser::gen::raql_value::t* id_1282 { new ::dessser::gen::raql_value::t(std::in_place_index<14>, di128_fst_433) };
                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1283 { id_1282, di128_snd_434 };
                                        letpair_res_1281 = id_1283;
                                      }
                                      choose_res_1279 = letpair_res_1281;
                                    } else {
                                      uint16_t id_1284 { 15 };
                                      bool id_1285 { bool(id_1284 == dsum1_fst_63) };
                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1286;
                                      if (id_1285) {
                                        ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1287 { dsum1_snd_64.readU8() };
                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1288;
                                        {
                                          auto di8_fst_427 { std::get<0>(id_1287) };
                                          auto di8_snd_428 { std::get<1>(id_1287) };
                                          int8_t id_1289 { int8_t(di8_fst_427) };
                                          ::dessser::gen::raql_value::t* id_1290 { new ::dessser::gen::raql_value::t(std::in_place_index<15>, id_1289) };
                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1291 { id_1290, di8_snd_428 };
                                          letpair_res_1288 = id_1291;
                                        }
                                        choose_res_1286 = letpair_res_1288;
                                      } else {
                                        uint16_t id_1292 { 16 };
                                        bool id_1293 { bool(id_1292 == dsum1_fst_63) };
                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1294;
                                        if (id_1293) {
                                          ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 id_1295 { dsum1_snd_64.readU16Le() };
                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1296;
                                          {
                                            auto di16_fst_421 { std::get<0>(id_1295) };
                                            auto di16_snd_422 { std::get<1>(id_1295) };
                                            int16_t id_1297 { int16_t(di16_fst_421) };
                                            ::dessser::gen::raql_value::t* id_1298 { new ::dessser::gen::raql_value::t(std::in_place_index<16>, id_1297) };
                                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1299 { id_1298, di16_snd_422 };
                                            letpair_res_1296 = id_1299;
                                          }
                                          choose_res_1294 = letpair_res_1296;
                                        } else {
                                          uint16_t id_1300 { 17 };
                                          bool id_1301 { bool(id_1300 == dsum1_fst_63) };
                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1302;
                                          if (id_1301) {
                                            ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1303 { dsum1_snd_64.readU32Le() };
                                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1304;
                                            {
                                              auto di24_fst_415 { std::get<0>(id_1303) };
                                              auto di24_snd_416 { std::get<1>(id_1303) };
                                              int32_t id_1305 { int32_t(di24_fst_415) };
                                              ::dessser::gen::raql_value::t* id_1306 { new ::dessser::gen::raql_value::t(std::in_place_index<17>, id_1305) };
                                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1307 { id_1306, di24_snd_416 };
                                              letpair_res_1304 = id_1307;
                                            }
                                            choose_res_1302 = letpair_res_1304;
                                          } else {
                                            uint16_t id_1308 { 18 };
                                            bool id_1309 { bool(id_1308 == dsum1_fst_63) };
                                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1310;
                                            if (id_1309) {
                                              ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1311 { dsum1_snd_64.readU32Le() };
                                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1312;
                                              {
                                                auto di32_fst_409 { std::get<0>(id_1311) };
                                                auto di32_snd_410 { std::get<1>(id_1311) };
                                                int32_t id_1313 { int32_t(di32_fst_409) };
                                                ::dessser::gen::raql_value::t* id_1314 { new ::dessser::gen::raql_value::t(std::in_place_index<18>, id_1313) };
                                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1315 { id_1314, di32_snd_410 };
                                                letpair_res_1312 = id_1315;
                                              }
                                              choose_res_1310 = letpair_res_1312;
                                            } else {
                                              uint16_t id_1316 { 19 };
                                              bool id_1317 { bool(id_1316 == dsum1_fst_63) };
                                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1318;
                                              if (id_1317) {
                                                ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1319 { dsum1_snd_64.readU64Le() };
                                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1320;
                                                {
                                                  auto di40_fst_403 { std::get<0>(id_1319) };
                                                  auto di40_snd_404 { std::get<1>(id_1319) };
                                                  int64_t id_1321 { int64_t(di40_fst_403) };
                                                  ::dessser::gen::raql_value::t* id_1322 { new ::dessser::gen::raql_value::t(std::in_place_index<19>, id_1321) };
                                                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1323 { id_1322, di40_snd_404 };
                                                  letpair_res_1320 = id_1323;
                                                }
                                                choose_res_1318 = letpair_res_1320;
                                              } else {
                                                uint16_t id_1324 { 20 };
                                                bool id_1325 { bool(id_1324 == dsum1_fst_63) };
                                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1326;
                                                if (id_1325) {
                                                  ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1327 { dsum1_snd_64.readU64Le() };
                                                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1328;
                                                  {
                                                    auto di48_fst_397 { std::get<0>(id_1327) };
                                                    auto di48_snd_398 { std::get<1>(id_1327) };
                                                    int64_t id_1329 { int64_t(di48_fst_397) };
                                                    ::dessser::gen::raql_value::t* id_1330 { new ::dessser::gen::raql_value::t(std::in_place_index<20>, id_1329) };
                                                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1331 { id_1330, di48_snd_398 };
                                                    letpair_res_1328 = id_1331;
                                                  }
                                                  choose_res_1326 = letpair_res_1328;
                                                } else {
                                                  uint16_t id_1332 { 21 };
                                                  bool id_1333 { bool(id_1332 == dsum1_fst_63) };
                                                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1334;
                                                  if (id_1333) {
                                                    ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1335 { dsum1_snd_64.readU64Le() };
                                                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1336;
                                                    {
                                                      auto di56_fst_391 { std::get<0>(id_1335) };
                                                      auto di56_snd_392 { std::get<1>(id_1335) };
                                                      int64_t id_1337 { int64_t(di56_fst_391) };
                                                      ::dessser::gen::raql_value::t* id_1338 { new ::dessser::gen::raql_value::t(std::in_place_index<21>, id_1337) };
                                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1339 { id_1338, di56_snd_392 };
                                                      letpair_res_1336 = id_1339;
                                                    }
                                                    choose_res_1334 = letpair_res_1336;
                                                  } else {
                                                    uint16_t id_1340 { 22 };
                                                    bool id_1341 { bool(id_1340 == dsum1_fst_63) };
                                                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1342;
                                                    if (id_1341) {
                                                      ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1343 { dsum1_snd_64.readU64Le() };
                                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1344;
                                                      {
                                                        auto di64_fst_385 { std::get<0>(id_1343) };
                                                        auto di64_snd_386 { std::get<1>(id_1343) };
                                                        int64_t id_1345 { int64_t(di64_fst_385) };
                                                        ::dessser::gen::raql_value::t* id_1346 { new ::dessser::gen::raql_value::t(std::in_place_index<22>, id_1345) };
                                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1347 { id_1346, di64_snd_386 };
                                                        letpair_res_1344 = id_1347;
                                                      }
                                                      choose_res_1342 = letpair_res_1344;
                                                    } else {
                                                      uint16_t id_1348 { 23 };
                                                      bool id_1349 { bool(id_1348 == dsum1_fst_63) };
                                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1350;
                                                      if (id_1349) {
                                                        ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 id_1351 { dsum1_snd_64.readU128Le() };
                                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1352;
                                                        {
                                                          auto di128_fst_379 { std::get<0>(id_1351) };
                                                          auto di128_snd_380 { std::get<1>(id_1351) };
                                                          int128_t id_1353 { int128_t(di128_fst_379) };
                                                          ::dessser::gen::raql_value::t* id_1354 { new ::dessser::gen::raql_value::t(std::in_place_index<23>, id_1353) };
                                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1355 { id_1354, di128_snd_380 };
                                                          letpair_res_1352 = id_1355;
                                                        }
                                                        choose_res_1350 = letpair_res_1352;
                                                      } else {
                                                        uint16_t id_1356 { 24 };
                                                        bool id_1357 { bool(id_1356 == dsum1_fst_63) };
                                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1358;
                                                        if (id_1357) {
                                                          ::dessser::gen::raql_value::t7a47220550fc5126a7b79f1e0c10c645 id_1359 { dsum1_snd_64.readU64Le() };
                                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1360;
                                                          {
                                                            auto du48_fst_370 { std::get<0>(id_1359) };
                                                            auto du48_snd_371 { std::get<1>(id_1359) };
                                                            std::function<uint64_t(uint64_t)> fun1361 { [&fun1361](uint64_t p_0) {
                                                              return p_0;
                                                            }
                                                             };
                                                            uint64_t id_1362 { uint64_t(du48_fst_370) };
                                                            uint64_t id_1363 { fun1361(id_1362) };
                                                            ::dessser::gen::raql_value::t* id_1364 { new ::dessser::gen::raql_value::t(std::in_place_index<24>, id_1363) };
                                                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1365 { id_1364, du48_snd_371 };
                                                            letpair_res_1360 = id_1365;
                                                          }
                                                          choose_res_1358 = letpair_res_1360;
                                                        } else {
                                                          uint16_t id_1366 { 25 };
                                                          bool id_1367 { bool(id_1366 == dsum1_fst_63) };
                                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1368;
                                                          if (id_1367) {
                                                            ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1369 { dsum1_snd_64.readU32Le() };
                                                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1370;
                                                            {
                                                              auto du32_fst_361 { std::get<0>(id_1369) };
                                                              auto du32_snd_362 { std::get<1>(id_1369) };
                                                              std::function<uint32_t(uint32_t)> fun1371 { [&fun1371](uint32_t p_0) {
                                                                return p_0;
                                                              }
                                                               };
                                                              uint32_t id_1372 { fun1371(du32_fst_361) };
                                                              ::dessser::gen::raql_value::t* id_1373 { new ::dessser::gen::raql_value::t(std::in_place_index<25>, id_1372) };
                                                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1374 { id_1373, du32_snd_362 };
                                                              letpair_res_1370 = id_1374;
                                                            }
                                                            choose_res_1368 = letpair_res_1370;
                                                          } else {
                                                            uint16_t id_1375 { 26 };
                                                            bool id_1376 { bool(id_1375 == dsum1_fst_63) };
                                                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1377;
                                                            if (id_1376) {
                                                              ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 id_1378 { dsum1_snd_64.readU128Le() };
                                                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1379;
                                                              {
                                                                auto di128_fst_352 { std::get<0>(id_1378) };
                                                                auto di128_snd_353 { std::get<1>(id_1378) };
                                                                std::function<uint128_t(uint128_t)> fun1380 { [&fun1380](uint128_t p_0) {
                                                                  return p_0;
                                                                }
                                                                 };
                                                                uint128_t id_1381 { fun1380(di128_fst_352) };
                                                                ::dessser::gen::raql_value::t* id_1382 { new ::dessser::gen::raql_value::t(std::in_place_index<26>, id_1381) };
                                                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1383 { id_1382, di128_snd_353 };
                                                                letpair_res_1379 = id_1383;
                                                              }
                                                              choose_res_1377 = letpair_res_1379;
                                                            } else {
                                                              uint16_t id_1384 { 27 };
                                                              bool id_1385 { bool(id_1384 == dsum1_fst_63) };
                                                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1386;
                                                              if (id_1385) {
                                                                ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 id_1387 { dsum1_snd_64.readU16Le() };
                                                                ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1388;
                                                                {
                                                                  auto du16_fst_319 { std::get<0>(id_1387) };
                                                                  auto du16_snd_320 { std::get<1>(id_1387) };
                                                                  ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 id_1389 { du16_fst_319, du16_snd_320 };
                                                                  letpair_res_1388 = id_1389;
                                                                }
                                                                ::dessser::gen::raql_value::t3112ad7e709a70a40b86a8e67d6eb121 let_res_1390;
                                                                {
                                                                  ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 dsum1_324 { letpair_res_1388 };
                                                                  ::dessser::gen::raql_value::t3112ad7e709a70a40b86a8e67d6eb121 letpair_res_1391;
                                                                  {
                                                                    auto dsum1_fst_325 { std::get<0>(dsum1_324) };
                                                                    auto dsum1_snd_326 { std::get<1>(dsum1_324) };
                                                                    uint16_t id_1392 { 0 };
                                                                    bool id_1393 { bool(id_1392 == dsum1_fst_325) };
                                                                    ::dessser::gen::raql_value::t3112ad7e709a70a40b86a8e67d6eb121 choose_res_1394;
                                                                    if (id_1393) {
                                                                      ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1395 { dsum1_snd_326.readU32Le() };
                                                                      ::dessser::gen::raql_value::t3112ad7e709a70a40b86a8e67d6eb121 letpair_res_1396;
                                                                      {
                                                                        auto du32_fst_337 { std::get<0>(id_1395) };
                                                                        auto du32_snd_338 { std::get<1>(id_1395) };
                                                                        std::function<uint32_t(uint32_t)> fun1397 { [&fun1397](uint32_t p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        uint32_t id_1398 { fun1397(du32_fst_337) };
                                                                        ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_1399 { std::in_place_index<0>, id_1398 };
                                                                        ::dessser::gen::raql_value::t3112ad7e709a70a40b86a8e67d6eb121 id_1400 { id_1399, du32_snd_338 };
                                                                        letpair_res_1396 = id_1400;
                                                                      }
                                                                      choose_res_1394 = letpair_res_1396;
                                                                    } else {
                                                                      uint16_t id_1401 { 1 };
                                                                      bool id_1402 { bool(dsum1_fst_325 == id_1401) };
                                                                      Void id_1403 { ((void)(assert(id_1402)), VOID) };
                                                                      (void)id_1403;
                                                                      ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 id_1404 { dsum1_snd_326.readU128Le() };
                                                                      ::dessser::gen::raql_value::t3112ad7e709a70a40b86a8e67d6eb121 letpair_res_1405;
                                                                      {
                                                                        auto di128_fst_328 { std::get<0>(id_1404) };
                                                                        auto di128_snd_329 { std::get<1>(id_1404) };
                                                                        std::function<uint128_t(uint128_t)> fun1406 { [&fun1406](uint128_t p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        uint128_t id_1407 { fun1406(di128_fst_328) };
                                                                        ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_1408 { std::in_place_index<1>, id_1407 };
                                                                        ::dessser::gen::raql_value::t3112ad7e709a70a40b86a8e67d6eb121 id_1409 { id_1408, di128_snd_329 };
                                                                        letpair_res_1405 = id_1409;
                                                                      }
                                                                      choose_res_1394 = letpair_res_1405;
                                                                    }
                                                                    letpair_res_1391 = choose_res_1394;
                                                                  }
                                                                  let_res_1390 = letpair_res_1391;
                                                                }
                                                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1410;
                                                                {
                                                                  auto des_usr_type_fst_346 { std::get<0>(let_res_1390) };
                                                                  auto des_usr_type_snd_347 { std::get<1>(let_res_1390) };
                                                                  std::function<::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891(::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891)> fun1411 { [&fun1411](::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 p_0) {
                                                                    return p_0;
                                                                  }
                                                                   };
                                                                  ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_1412 { fun1411(des_usr_type_fst_346) };
                                                                  ::dessser::gen::raql_value::t* id_1413 { new ::dessser::gen::raql_value::t(std::in_place_index<27>, id_1412) };
                                                                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1414 { id_1413, des_usr_type_snd_347 };
                                                                  letpair_res_1410 = id_1414;
                                                                }
                                                                choose_res_1386 = letpair_res_1410;
                                                              } else {
                                                                uint16_t id_1415 { 28 };
                                                                bool id_1416 { bool(id_1415 == dsum1_fst_63) };
                                                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1417;
                                                                if (id_1416) {
                                                                  ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1418 { dsum1_snd_64.readU32Le() };
                                                                  ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 letpair_res_1419;
                                                                  {
                                                                    auto du32_fst_298 { std::get<0>(id_1418) };
                                                                    auto du32_snd_299 { std::get<1>(id_1418) };
                                                                    std::function<uint32_t(uint32_t)> fun1420 { [&fun1420](uint32_t p_0) {
                                                                      return p_0;
                                                                    }
                                                                     };
                                                                    uint32_t id_1421 { fun1420(du32_fst_298) };
                                                                    ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1422 { id_1421, du32_snd_299 };
                                                                    letpair_res_1419 = id_1422;
                                                                  }
                                                                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 let_res_1423;
                                                                  {
                                                                    ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 drec_303 { letpair_res_1419 };
                                                                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1424;
                                                                    {
                                                                      auto drec_fst_304 { std::get<0>(drec_303) };
                                                                      auto drec_snd_305 { std::get<1>(drec_303) };
                                                                      ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1425 { drec_snd_305.readU8() };
                                                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1426;
                                                                      {
                                                                        auto du8_fst_307 { std::get<0>(id_1425) };
                                                                        auto du8_snd_308 { std::get<1>(id_1425) };
                                                                        std::function<::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982(::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982)> fun1427 { [&fun1427](::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_1428 { .Cidr4_ip = drec_fst_304, .Cidr4_mask = du8_fst_307 };
                                                                        ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_1429 { fun1427(id_1428) };
                                                                        ::dessser::gen::raql_value::t* id_1430 { new ::dessser::gen::raql_value::t(std::in_place_index<28>, id_1429) };
                                                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1431 { id_1430, du8_snd_308 };
                                                                        letpair_res_1426 = id_1431;
                                                                      }
                                                                      letpair_res_1424 = letpair_res_1426;
                                                                    }
                                                                    let_res_1423 = letpair_res_1424;
                                                                  }
                                                                  choose_res_1417 = let_res_1423;
                                                                } else {
                                                                  uint16_t id_1432 { 29 };
                                                                  bool id_1433 { bool(id_1432 == dsum1_fst_63) };
                                                                  ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1434;
                                                                  if (id_1433) {
                                                                    ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 id_1435 { dsum1_snd_64.readU128Le() };
                                                                    ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 letpair_res_1436;
                                                                    {
                                                                      auto di128_fst_277 { std::get<0>(id_1435) };
                                                                      auto di128_snd_278 { std::get<1>(id_1435) };
                                                                      std::function<uint128_t(uint128_t)> fun1437 { [&fun1437](uint128_t p_0) {
                                                                        return p_0;
                                                                      }
                                                                       };
                                                                      uint128_t id_1438 { fun1437(di128_fst_277) };
                                                                      ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 id_1439 { id_1438, di128_snd_278 };
                                                                      letpair_res_1436 = id_1439;
                                                                    }
                                                                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 let_res_1440;
                                                                    {
                                                                      ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 drec_282 { letpair_res_1436 };
                                                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1441;
                                                                      {
                                                                        auto drec_fst_283 { std::get<0>(drec_282) };
                                                                        auto drec_snd_284 { std::get<1>(drec_282) };
                                                                        ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1442 { drec_snd_284.readU8() };
                                                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1443;
                                                                        {
                                                                          auto du8_fst_286 { std::get<0>(id_1442) };
                                                                          auto du8_snd_287 { std::get<1>(id_1442) };
                                                                          std::function<::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86(::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86)> fun1444 { [&fun1444](::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 p_0) {
                                                                            return p_0;
                                                                          }
                                                                           };
                                                                          ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_1445 { .ip = drec_fst_283, .mask = du8_fst_286 };
                                                                          ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_1446 { fun1444(id_1445) };
                                                                          ::dessser::gen::raql_value::t* id_1447 { new ::dessser::gen::raql_value::t(std::in_place_index<29>, id_1446) };
                                                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1448 { id_1447, du8_snd_287 };
                                                                          letpair_res_1443 = id_1448;
                                                                        }
                                                                        letpair_res_1441 = letpair_res_1443;
                                                                      }
                                                                      let_res_1440 = letpair_res_1441;
                                                                    }
                                                                    choose_res_1434 = let_res_1440;
                                                                  } else {
                                                                    uint16_t id_1449 { 30 };
                                                                    bool id_1450 { bool(id_1449 == dsum1_fst_63) };
                                                                    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1451;
                                                                    if (id_1450) {
                                                                      ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 id_1452 { dsum1_snd_64.readU16Le() };
                                                                      ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1453;
                                                                      {
                                                                        auto du16_fst_220 { std::get<0>(id_1452) };
                                                                        auto du16_snd_221 { std::get<1>(id_1452) };
                                                                        ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 id_1454 { du16_fst_220, du16_snd_221 };
                                                                        letpair_res_1453 = id_1454;
                                                                      }
                                                                      ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 let_res_1455;
                                                                      {
                                                                        ::dessser::gen::raql_value::t22a32080ad88ab548b80077a17b7dd46 dsum1_225 { letpair_res_1453 };
                                                                        ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 letpair_res_1456;
                                                                        {
                                                                          auto dsum1_fst_226 { std::get<0>(dsum1_225) };
                                                                          auto dsum1_snd_227 { std::get<1>(dsum1_225) };
                                                                          uint16_t id_1457 { 0 };
                                                                          bool id_1458 { bool(id_1457 == dsum1_fst_226) };
                                                                          ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 choose_res_1459;
                                                                          if (id_1458) {
                                                                            ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1460 { dsum1_snd_227.readU32Le() };
                                                                            ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 letpair_res_1461;
                                                                            {
                                                                              auto du32_fst_250 { std::get<0>(id_1460) };
                                                                              auto du32_snd_251 { std::get<1>(id_1460) };
                                                                              std::function<uint32_t(uint32_t)> fun1462 { [&fun1462](uint32_t p_0) {
                                                                                return p_0;
                                                                              }
                                                                               };
                                                                              uint32_t id_1463 { fun1462(du32_fst_250) };
                                                                              ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1464 { id_1463, du32_snd_251 };
                                                                              letpair_res_1461 = id_1464;
                                                                            }
                                                                            ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 let_res_1465;
                                                                            {
                                                                              ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 drec_255 { letpair_res_1461 };
                                                                              ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 letpair_res_1466;
                                                                              {
                                                                                auto drec_fst_256 { std::get<0>(drec_255) };
                                                                                auto drec_snd_257 { std::get<1>(drec_255) };
                                                                                ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1467 { drec_snd_257.readU8() };
                                                                                ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 letpair_res_1468;
                                                                                {
                                                                                  auto du8_fst_259 { std::get<0>(id_1467) };
                                                                                  auto du8_snd_260 { std::get<1>(id_1467) };
                                                                                  std::function<::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982(::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982)> fun1469 { [&fun1469](::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 p_0) {
                                                                                    return p_0;
                                                                                  }
                                                                                   };
                                                                                  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_1470 { .Cidr4_ip = drec_fst_256, .Cidr4_mask = du8_fst_259 };
                                                                                  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_1471 { fun1469(id_1470) };
                                                                                  ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1472 { std::in_place_index<0>, id_1471 };
                                                                                  ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 id_1473 { id_1472, du8_snd_260 };
                                                                                  letpair_res_1468 = id_1473;
                                                                                }
                                                                                letpair_res_1466 = letpair_res_1468;
                                                                              }
                                                                              let_res_1465 = letpair_res_1466;
                                                                            }
                                                                            choose_res_1459 = let_res_1465;
                                                                          } else {
                                                                            uint16_t id_1474 { 1 };
                                                                            bool id_1475 { bool(dsum1_fst_226 == id_1474) };
                                                                            Void id_1476 { ((void)(assert(id_1475)), VOID) };
                                                                            (void)id_1476;
                                                                            ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 id_1477 { dsum1_snd_227.readU128Le() };
                                                                            ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 letpair_res_1478;
                                                                            {
                                                                              auto di128_fst_229 { std::get<0>(id_1477) };
                                                                              auto di128_snd_230 { std::get<1>(id_1477) };
                                                                              std::function<uint128_t(uint128_t)> fun1479 { [&fun1479](uint128_t p_0) {
                                                                                return p_0;
                                                                              }
                                                                               };
                                                                              uint128_t id_1480 { fun1479(di128_fst_229) };
                                                                              ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 id_1481 { id_1480, di128_snd_230 };
                                                                              letpair_res_1478 = id_1481;
                                                                            }
                                                                            ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 let_res_1482;
                                                                            {
                                                                              ::dessser::gen::raql_value::t5d72eb1f6edf58d2d6a63eca47034564 drec_234 { letpair_res_1478 };
                                                                              ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 letpair_res_1483;
                                                                              {
                                                                                auto drec_fst_235 { std::get<0>(drec_234) };
                                                                                auto drec_snd_236 { std::get<1>(drec_234) };
                                                                                ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1484 { drec_snd_236.readU8() };
                                                                                ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 letpair_res_1485;
                                                                                {
                                                                                  auto du8_fst_238 { std::get<0>(id_1484) };
                                                                                  auto du8_snd_239 { std::get<1>(id_1484) };
                                                                                  std::function<::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86(::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86)> fun1486 { [&fun1486](::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 p_0) {
                                                                                    return p_0;
                                                                                  }
                                                                                   };
                                                                                  ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_1487 { .ip = drec_fst_235, .mask = du8_fst_238 };
                                                                                  ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_1488 { fun1486(id_1487) };
                                                                                  ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1489 { std::in_place_index<1>, id_1488 };
                                                                                  ::dessser::gen::raql_value::t07c6ba94ebc3c46bea9b5d748e096901 id_1490 { id_1489, du8_snd_239 };
                                                                                  letpair_res_1485 = id_1490;
                                                                                }
                                                                                letpair_res_1483 = letpair_res_1485;
                                                                              }
                                                                              let_res_1482 = letpair_res_1483;
                                                                            }
                                                                            choose_res_1459 = let_res_1482;
                                                                          }
                                                                          letpair_res_1456 = choose_res_1459;
                                                                        }
                                                                        let_res_1455 = letpair_res_1456;
                                                                      }
                                                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1491;
                                                                      {
                                                                        auto des_usr_type_fst_271 { std::get<0>(let_res_1455) };
                                                                        auto des_usr_type_snd_272 { std::get<1>(let_res_1455) };
                                                                        std::function<::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27(::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27)> fun1492 { [&fun1492](::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1493 { fun1492(des_usr_type_fst_271) };
                                                                        ::dessser::gen::raql_value::t* id_1494 { new ::dessser::gen::raql_value::t(std::in_place_index<30>, id_1493) };
                                                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1495 { id_1494, des_usr_type_snd_272 };
                                                                        letpair_res_1491 = id_1495;
                                                                      }
                                                                      choose_res_1451 = letpair_res_1491;
                                                                    } else {
                                                                      uint16_t id_1496 { 31 };
                                                                      bool id_1497 { bool(id_1496 == dsum1_fst_63) };
                                                                      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1498;
                                                                      if (id_1497) {
                                                                        uint32_t id_1499 { 0U };
                                                                        Vec<1, uint32_t> id_1500 {  id_1499  };
                                                                        ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1501;
                                                                        {
                                                                          Vec<1, uint32_t> leb_ref_193 { id_1500 };
                                                                          uint8_t id_1502 { 0 };
                                                                          Vec<1, uint8_t> id_1503 {  id_1502  };
                                                                          ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1504;
                                                                          {
                                                                            Vec<1, uint8_t> shft_ref_194 { id_1503 };
                                                                            Vec<1, Pointer> id_1505 {  dsum1_snd_64  };
                                                                            ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1506;
                                                                            {
                                                                              Vec<1, Pointer> p_ref_195 { id_1505 };
                                                                              bool while_flag_1507 { true };
                                                                              do {
                                                                                uint8_t id_1508 { 0 };
                                                                                Pointer id_1509 { p_ref_195[id_1508] };
                                                                                ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1510 { id_1509.readU8() };
                                                                                bool let_res_1511;
                                                                                {
                                                                                  ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 leb128_196 { id_1510 };
                                                                                  bool letpair_res_1512;
                                                                                  {
                                                                                    auto leb128_fst_197 { std::get<0>(leb128_196) };
                                                                                    auto leb128_snd_198 { std::get<1>(leb128_196) };
                                                                                    uint8_t id_1513 { 0 };
                                                                                    Void id_1514 { ((void)(p_ref_195[id_1513] = leb128_snd_198), VOID) };
                                                                                    (void)id_1514;
                                                                                    uint8_t id_1515 { 0 };
                                                                                    uint8_t id_1516 { 127 };
                                                                                    uint8_t id_1517 { uint8_t(leb128_fst_197 & id_1516) };
                                                                                    uint32_t id_1518 { uint32_t(id_1517) };
                                                                                    uint8_t id_1519 { 0 };
                                                                                    uint8_t id_1520 { shft_ref_194[id_1519] };
                                                                                    uint32_t id_1521 { uint32_t(id_1518 << id_1520) };
                                                                                    uint8_t id_1522 { 0 };
                                                                                    uint32_t id_1523 { leb_ref_193[id_1522] };
                                                                                    uint32_t id_1524 { uint32_t(id_1521 | id_1523) };
                                                                                    Void id_1525 { ((void)(leb_ref_193[id_1515] = id_1524), VOID) };
                                                                                    (void)id_1525;
                                                                                    uint8_t id_1526 { 0 };
                                                                                    uint8_t id_1527 { 0 };
                                                                                    uint8_t id_1528 { shft_ref_194[id_1527] };
                                                                                    uint8_t id_1529 { 7 };
                                                                                    uint8_t id_1530 { uint8_t(id_1528 + id_1529) };
                                                                                    Void id_1531 { ((void)(shft_ref_194[id_1526] = id_1530), VOID) };
                                                                                    (void)id_1531;
                                                                                    uint8_t id_1532 { 128 };
                                                                                    bool id_1533 { bool(leb128_fst_197 >= id_1532) };
                                                                                    letpair_res_1512 = id_1533;
                                                                                  }
                                                                                  let_res_1511 = letpair_res_1512;
                                                                                }
                                                                                while_flag_1507 = let_res_1511;
                                                                                if (while_flag_1507) {
                                                                                  (void)VOID;
                                                                                }
                                                                              } while (while_flag_1507);
                                                                              (void)VOID;
                                                                              uint8_t id_1534 { 0 };
                                                                              uint32_t id_1535 { leb_ref_193[id_1534] };
                                                                              uint8_t id_1536 { 0 };
                                                                              Pointer id_1537 { p_ref_195[id_1536] };
                                                                              ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1538 { id_1535, id_1537 };
                                                                              let_res_1506 = id_1538;
                                                                            }
                                                                            let_res_1504 = let_res_1506;
                                                                          }
                                                                          let_res_1501 = let_res_1504;
                                                                        }
                                                                        ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 let_res_1539;
                                                                        {
                                                                          ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 dlist1_202 { let_res_1501 };
                                                                          ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 letpair_res_1540;
                                                                          {
                                                                            auto dlist1_fst_203 { std::get<0>(dlist1_202) };
                                                                            auto dlist1_snd_204 { std::get<1>(dlist1_202) };
                                                                            Lst<t*> endoflist_1541;
                                                                            ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1542 { endoflist_1541, dlist1_snd_204 };
                                                                            Vec<1, ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548> id_1543 {  id_1542  };
                                                                            ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 let_res_1544;
                                                                            {
                                                                              Vec<1, ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548> inits_src_ref_205 { id_1543 };
                                                                              int32_t id_1545 { 0L };
                                                                              Vec<1, int32_t> id_1546 {  id_1545  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_206 { id_1546 };
                                                                                bool while_flag_1547 { true };
                                                                                do {
                                                                                  int32_t id_1548 { int32_t(dlist1_fst_203) };
                                                                                  uint8_t id_1549 { 0 };
                                                                                  int32_t id_1550 { repeat_n_206[id_1549] };
                                                                                  bool id_1551 { bool(id_1548 > id_1550) };
                                                                                  while_flag_1547 = id_1551;
                                                                                  if (while_flag_1547) {
                                                                                    uint8_t id_1552 { 0 };
                                                                                    ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1553 { inits_src_ref_205[id_1552] };
                                                                                    {
                                                                                      ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 dlist2_207 { id_1553 };
                                                                                      {
                                                                                        auto dlist2_fst_208 { std::get<0>(dlist2_207) };
                                                                                        auto dlist2_snd_209 { std::get<1>(dlist2_207) };
                                                                                        uint8_t id_1554 { 0 };
                                                                                        ::dessser::gen::raql_value::t45217dce3db5a9a49037839afd0048e8 id_1555 { fun1124(dlist2_snd_209) };
                                                                                        ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 letpair_res_1556;
                                                                                        {
                                                                                          auto dlist3_fst_211 { std::get<0>(id_1555) };
                                                                                          auto dlist3_snd_212 { std::get<1>(id_1555) };
                                                                                          Lst<t*> id_1557 { dlist3_fst_211, dlist2_fst_208 };
                                                                                          ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1558 { id_1557, dlist3_snd_212 };
                                                                                          letpair_res_1556 = id_1558;
                                                                                        }
                                                                                        Void id_1559 { ((void)(inits_src_ref_205[id_1554] = letpair_res_1556), VOID) };
                                                                                        (void)id_1559;
                                                                                      }
                                                                                      (void)VOID;
                                                                                    }
                                                                                    (void)VOID;
                                                                                    uint8_t id_1560 { 0 };
                                                                                    uint8_t id_1561 { 0 };
                                                                                    int32_t id_1562 { repeat_n_206[id_1561] };
                                                                                    int32_t id_1563 { 1L };
                                                                                    int32_t id_1564 { int32_t(id_1562 + id_1563) };
                                                                                    Void id_1565 { ((void)(repeat_n_206[id_1560] = id_1564), VOID) };
                                                                                    (void)id_1565;
                                                                                    (void)id_1565;
                                                                                  }
                                                                                } while (while_flag_1547);
                                                                                (void)VOID;
                                                                              }
                                                                              (void)VOID;
                                                                              uint8_t id_1566 { 0 };
                                                                              ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1567 { inits_src_ref_205[id_1566] };
                                                                              let_res_1544 = id_1567;
                                                                            }
                                                                            letpair_res_1540 = let_res_1544;
                                                                          }
                                                                          let_res_1539 = letpair_res_1540;
                                                                        }
                                                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1568;
                                                                        {
                                                                          auto dlist4_fst_214 { std::get<0>(let_res_1539) };
                                                                          auto dlist4_snd_215 { std::get<1>(let_res_1539) };
                                                                          Arr<t*> id_1569 { dlist4_fst_214.toListRev() };
                                                                          ::dessser::gen::raql_value::t* id_1570 { new ::dessser::gen::raql_value::t(std::in_place_index<31>, id_1569) };
                                                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1571 { id_1570, dlist4_snd_215 };
                                                                          letpair_res_1568 = id_1571;
                                                                        }
                                                                        choose_res_1498 = letpair_res_1568;
                                                                      } else {
                                                                        uint16_t id_1572 { 32 };
                                                                        bool id_1573 { bool(id_1572 == dsum1_fst_63) };
                                                                        ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1574;
                                                                        if (id_1573) {
                                                                          uint32_t id_1575 { 0U };
                                                                          Vec<1, uint32_t> id_1576 {  id_1575  };
                                                                          ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1577;
                                                                          {
                                                                            Vec<1, uint32_t> leb_ref_167 { id_1576 };
                                                                            uint8_t id_1578 { 0 };
                                                                            Vec<1, uint8_t> id_1579 {  id_1578  };
                                                                            ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1580;
                                                                            {
                                                                              Vec<1, uint8_t> shft_ref_168 { id_1579 };
                                                                              Vec<1, Pointer> id_1581 {  dsum1_snd_64  };
                                                                              ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1582;
                                                                              {
                                                                                Vec<1, Pointer> p_ref_169 { id_1581 };
                                                                                bool while_flag_1583 { true };
                                                                                do {
                                                                                  uint8_t id_1584 { 0 };
                                                                                  Pointer id_1585 { p_ref_169[id_1584] };
                                                                                  ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1586 { id_1585.readU8() };
                                                                                  bool let_res_1587;
                                                                                  {
                                                                                    ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 leb128_170 { id_1586 };
                                                                                    bool letpair_res_1588;
                                                                                    {
                                                                                      auto leb128_fst_171 { std::get<0>(leb128_170) };
                                                                                      auto leb128_snd_172 { std::get<1>(leb128_170) };
                                                                                      uint8_t id_1589 { 0 };
                                                                                      Void id_1590 { ((void)(p_ref_169[id_1589] = leb128_snd_172), VOID) };
                                                                                      (void)id_1590;
                                                                                      uint8_t id_1591 { 0 };
                                                                                      uint8_t id_1592 { 127 };
                                                                                      uint8_t id_1593 { uint8_t(leb128_fst_171 & id_1592) };
                                                                                      uint32_t id_1594 { uint32_t(id_1593) };
                                                                                      uint8_t id_1595 { 0 };
                                                                                      uint8_t id_1596 { shft_ref_168[id_1595] };
                                                                                      uint32_t id_1597 { uint32_t(id_1594 << id_1596) };
                                                                                      uint8_t id_1598 { 0 };
                                                                                      uint32_t id_1599 { leb_ref_167[id_1598] };
                                                                                      uint32_t id_1600 { uint32_t(id_1597 | id_1599) };
                                                                                      Void id_1601 { ((void)(leb_ref_167[id_1591] = id_1600), VOID) };
                                                                                      (void)id_1601;
                                                                                      uint8_t id_1602 { 0 };
                                                                                      uint8_t id_1603 { 0 };
                                                                                      uint8_t id_1604 { shft_ref_168[id_1603] };
                                                                                      uint8_t id_1605 { 7 };
                                                                                      uint8_t id_1606 { uint8_t(id_1604 + id_1605) };
                                                                                      Void id_1607 { ((void)(shft_ref_168[id_1602] = id_1606), VOID) };
                                                                                      (void)id_1607;
                                                                                      uint8_t id_1608 { 128 };
                                                                                      bool id_1609 { bool(leb128_fst_171 >= id_1608) };
                                                                                      letpair_res_1588 = id_1609;
                                                                                    }
                                                                                    let_res_1587 = letpair_res_1588;
                                                                                  }
                                                                                  while_flag_1583 = let_res_1587;
                                                                                  if (while_flag_1583) {
                                                                                    (void)VOID;
                                                                                  }
                                                                                } while (while_flag_1583);
                                                                                (void)VOID;
                                                                                uint8_t id_1610 { 0 };
                                                                                uint32_t id_1611 { leb_ref_167[id_1610] };
                                                                                uint8_t id_1612 { 0 };
                                                                                Pointer id_1613 { p_ref_169[id_1612] };
                                                                                ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1614 { id_1611, id_1613 };
                                                                                let_res_1582 = id_1614;
                                                                              }
                                                                              let_res_1580 = let_res_1582;
                                                                            }
                                                                            let_res_1577 = let_res_1580;
                                                                          }
                                                                          ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 let_res_1615;
                                                                          {
                                                                            ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 dlist1_176 { let_res_1577 };
                                                                            ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 letpair_res_1616;
                                                                            {
                                                                              auto dlist1_fst_177 { std::get<0>(dlist1_176) };
                                                                              auto dlist1_snd_178 { std::get<1>(dlist1_176) };
                                                                              Lst<t*> endoflist_1617;
                                                                              ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1618 { endoflist_1617, dlist1_snd_178 };
                                                                              Vec<1, ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548> id_1619 {  id_1618  };
                                                                              ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 let_res_1620;
                                                                              {
                                                                                Vec<1, ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548> inits_src_ref_179 { id_1619 };
                                                                                int32_t id_1621 { 0L };
                                                                                Vec<1, int32_t> id_1622 {  id_1621  };
                                                                                {
                                                                                  Vec<1, int32_t> repeat_n_180 { id_1622 };
                                                                                  bool while_flag_1623 { true };
                                                                                  do {
                                                                                    int32_t id_1624 { int32_t(dlist1_fst_177) };
                                                                                    uint8_t id_1625 { 0 };
                                                                                    int32_t id_1626 { repeat_n_180[id_1625] };
                                                                                    bool id_1627 { bool(id_1624 > id_1626) };
                                                                                    while_flag_1623 = id_1627;
                                                                                    if (while_flag_1623) {
                                                                                      uint8_t id_1628 { 0 };
                                                                                      ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1629 { inits_src_ref_179[id_1628] };
                                                                                      {
                                                                                        ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 dlist2_181 { id_1629 };
                                                                                        {
                                                                                          auto dlist2_fst_182 { std::get<0>(dlist2_181) };
                                                                                          auto dlist2_snd_183 { std::get<1>(dlist2_181) };
                                                                                          uint8_t id_1630 { 0 };
                                                                                          ::dessser::gen::raql_value::t45217dce3db5a9a49037839afd0048e8 id_1631 { fun1124(dlist2_snd_183) };
                                                                                          ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 letpair_res_1632;
                                                                                          {
                                                                                            auto dlist3_fst_185 { std::get<0>(id_1631) };
                                                                                            auto dlist3_snd_186 { std::get<1>(id_1631) };
                                                                                            Lst<t*> id_1633 { dlist3_fst_185, dlist2_fst_182 };
                                                                                            ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1634 { id_1633, dlist3_snd_186 };
                                                                                            letpair_res_1632 = id_1634;
                                                                                          }
                                                                                          Void id_1635 { ((void)(inits_src_ref_179[id_1630] = letpair_res_1632), VOID) };
                                                                                          (void)id_1635;
                                                                                        }
                                                                                        (void)VOID;
                                                                                      }
                                                                                      (void)VOID;
                                                                                      uint8_t id_1636 { 0 };
                                                                                      uint8_t id_1637 { 0 };
                                                                                      int32_t id_1638 { repeat_n_180[id_1637] };
                                                                                      int32_t id_1639 { 1L };
                                                                                      int32_t id_1640 { int32_t(id_1638 + id_1639) };
                                                                                      Void id_1641 { ((void)(repeat_n_180[id_1636] = id_1640), VOID) };
                                                                                      (void)id_1641;
                                                                                      (void)id_1641;
                                                                                    }
                                                                                  } while (while_flag_1623);
                                                                                  (void)VOID;
                                                                                }
                                                                                (void)VOID;
                                                                                uint8_t id_1642 { 0 };
                                                                                ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1643 { inits_src_ref_179[id_1642] };
                                                                                let_res_1620 = id_1643;
                                                                              }
                                                                              letpair_res_1616 = let_res_1620;
                                                                            }
                                                                            let_res_1615 = letpair_res_1616;
                                                                          }
                                                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1644;
                                                                          {
                                                                            auto dlist4_fst_188 { std::get<0>(let_res_1615) };
                                                                            auto dlist4_snd_189 { std::get<1>(let_res_1615) };
                                                                            Arr<t*> id_1645 { dlist4_fst_188.toListRev() };
                                                                            ::dessser::gen::raql_value::t* id_1646 { new ::dessser::gen::raql_value::t(std::in_place_index<32>, id_1645) };
                                                                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1647 { id_1646, dlist4_snd_189 };
                                                                            letpair_res_1644 = id_1647;
                                                                          }
                                                                          choose_res_1574 = letpair_res_1644;
                                                                        } else {
                                                                          uint16_t id_1648 { 33 };
                                                                          bool id_1649 { bool(id_1648 == dsum1_fst_63) };
                                                                          ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1650;
                                                                          if (id_1649) {
                                                                            uint32_t id_1651 { 0U };
                                                                            Vec<1, uint32_t> id_1652 {  id_1651  };
                                                                            ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1653;
                                                                            {
                                                                              Vec<1, uint32_t> leb_ref_141 { id_1652 };
                                                                              uint8_t id_1654 { 0 };
                                                                              Vec<1, uint8_t> id_1655 {  id_1654  };
                                                                              ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1656;
                                                                              {
                                                                                Vec<1, uint8_t> shft_ref_142 { id_1655 };
                                                                                Vec<1, Pointer> id_1657 {  dsum1_snd_64  };
                                                                                ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1658;
                                                                                {
                                                                                  Vec<1, Pointer> p_ref_143 { id_1657 };
                                                                                  bool while_flag_1659 { true };
                                                                                  do {
                                                                                    uint8_t id_1660 { 0 };
                                                                                    Pointer id_1661 { p_ref_143[id_1660] };
                                                                                    ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1662 { id_1661.readU8() };
                                                                                    bool let_res_1663;
                                                                                    {
                                                                                      ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 leb128_144 { id_1662 };
                                                                                      bool letpair_res_1664;
                                                                                      {
                                                                                        auto leb128_fst_145 { std::get<0>(leb128_144) };
                                                                                        auto leb128_snd_146 { std::get<1>(leb128_144) };
                                                                                        uint8_t id_1665 { 0 };
                                                                                        Void id_1666 { ((void)(p_ref_143[id_1665] = leb128_snd_146), VOID) };
                                                                                        (void)id_1666;
                                                                                        uint8_t id_1667 { 0 };
                                                                                        uint8_t id_1668 { 127 };
                                                                                        uint8_t id_1669 { uint8_t(leb128_fst_145 & id_1668) };
                                                                                        uint32_t id_1670 { uint32_t(id_1669) };
                                                                                        uint8_t id_1671 { 0 };
                                                                                        uint8_t id_1672 { shft_ref_142[id_1671] };
                                                                                        uint32_t id_1673 { uint32_t(id_1670 << id_1672) };
                                                                                        uint8_t id_1674 { 0 };
                                                                                        uint32_t id_1675 { leb_ref_141[id_1674] };
                                                                                        uint32_t id_1676 { uint32_t(id_1673 | id_1675) };
                                                                                        Void id_1677 { ((void)(leb_ref_141[id_1667] = id_1676), VOID) };
                                                                                        (void)id_1677;
                                                                                        uint8_t id_1678 { 0 };
                                                                                        uint8_t id_1679 { 0 };
                                                                                        uint8_t id_1680 { shft_ref_142[id_1679] };
                                                                                        uint8_t id_1681 { 7 };
                                                                                        uint8_t id_1682 { uint8_t(id_1680 + id_1681) };
                                                                                        Void id_1683 { ((void)(shft_ref_142[id_1678] = id_1682), VOID) };
                                                                                        (void)id_1683;
                                                                                        uint8_t id_1684 { 128 };
                                                                                        bool id_1685 { bool(leb128_fst_145 >= id_1684) };
                                                                                        letpair_res_1664 = id_1685;
                                                                                      }
                                                                                      let_res_1663 = letpair_res_1664;
                                                                                    }
                                                                                    while_flag_1659 = let_res_1663;
                                                                                    if (while_flag_1659) {
                                                                                      (void)VOID;
                                                                                    }
                                                                                  } while (while_flag_1659);
                                                                                  (void)VOID;
                                                                                  uint8_t id_1686 { 0 };
                                                                                  uint32_t id_1687 { leb_ref_141[id_1686] };
                                                                                  uint8_t id_1688 { 0 };
                                                                                  Pointer id_1689 { p_ref_143[id_1688] };
                                                                                  ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1690 { id_1687, id_1689 };
                                                                                  let_res_1658 = id_1690;
                                                                                }
                                                                                let_res_1656 = let_res_1658;
                                                                              }
                                                                              let_res_1653 = let_res_1656;
                                                                            }
                                                                            ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 let_res_1691;
                                                                            {
                                                                              ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 dlist1_150 { let_res_1653 };
                                                                              ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 letpair_res_1692;
                                                                              {
                                                                                auto dlist1_fst_151 { std::get<0>(dlist1_150) };
                                                                                auto dlist1_snd_152 { std::get<1>(dlist1_150) };
                                                                                Lst<t*> endoflist_1693;
                                                                                ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1694 { endoflist_1693, dlist1_snd_152 };
                                                                                Vec<1, ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548> id_1695 {  id_1694  };
                                                                                ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 let_res_1696;
                                                                                {
                                                                                  Vec<1, ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548> inits_src_ref_153 { id_1695 };
                                                                                  int32_t id_1697 { 0L };
                                                                                  Vec<1, int32_t> id_1698 {  id_1697  };
                                                                                  {
                                                                                    Vec<1, int32_t> repeat_n_154 { id_1698 };
                                                                                    bool while_flag_1699 { true };
                                                                                    do {
                                                                                      int32_t id_1700 { int32_t(dlist1_fst_151) };
                                                                                      uint8_t id_1701 { 0 };
                                                                                      int32_t id_1702 { repeat_n_154[id_1701] };
                                                                                      bool id_1703 { bool(id_1700 > id_1702) };
                                                                                      while_flag_1699 = id_1703;
                                                                                      if (while_flag_1699) {
                                                                                        uint8_t id_1704 { 0 };
                                                                                        ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1705 { inits_src_ref_153[id_1704] };
                                                                                        {
                                                                                          ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 dlist2_155 { id_1705 };
                                                                                          {
                                                                                            auto dlist2_fst_156 { std::get<0>(dlist2_155) };
                                                                                            auto dlist2_snd_157 { std::get<1>(dlist2_155) };
                                                                                            uint8_t id_1706 { 0 };
                                                                                            ::dessser::gen::raql_value::t45217dce3db5a9a49037839afd0048e8 id_1707 { fun1124(dlist2_snd_157) };
                                                                                            ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 letpair_res_1708;
                                                                                            {
                                                                                              auto dlist3_fst_159 { std::get<0>(id_1707) };
                                                                                              auto dlist3_snd_160 { std::get<1>(id_1707) };
                                                                                              Lst<t*> id_1709 { dlist3_fst_159, dlist2_fst_156 };
                                                                                              ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1710 { id_1709, dlist3_snd_160 };
                                                                                              letpair_res_1708 = id_1710;
                                                                                            }
                                                                                            Void id_1711 { ((void)(inits_src_ref_153[id_1706] = letpair_res_1708), VOID) };
                                                                                            (void)id_1711;
                                                                                          }
                                                                                          (void)VOID;
                                                                                        }
                                                                                        (void)VOID;
                                                                                        uint8_t id_1712 { 0 };
                                                                                        uint8_t id_1713 { 0 };
                                                                                        int32_t id_1714 { repeat_n_154[id_1713] };
                                                                                        int32_t id_1715 { 1L };
                                                                                        int32_t id_1716 { int32_t(id_1714 + id_1715) };
                                                                                        Void id_1717 { ((void)(repeat_n_154[id_1712] = id_1716), VOID) };
                                                                                        (void)id_1717;
                                                                                        (void)id_1717;
                                                                                      }
                                                                                    } while (while_flag_1699);
                                                                                    (void)VOID;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_1718 { 0 };
                                                                                  ::dessser::gen::raql_value::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1719 { inits_src_ref_153[id_1718] };
                                                                                  let_res_1696 = id_1719;
                                                                                }
                                                                                letpair_res_1692 = let_res_1696;
                                                                              }
                                                                              let_res_1691 = letpair_res_1692;
                                                                            }
                                                                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1720;
                                                                            {
                                                                              auto dlist4_fst_162 { std::get<0>(let_res_1691) };
                                                                              auto dlist4_snd_163 { std::get<1>(let_res_1691) };
                                                                              Arr<t*> id_1721 { dlist4_fst_162.toListRev() };
                                                                              ::dessser::gen::raql_value::t* id_1722 { new ::dessser::gen::raql_value::t(std::in_place_index<33>, id_1721) };
                                                                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1723 { id_1722, dlist4_snd_163 };
                                                                              letpair_res_1720 = id_1723;
                                                                            }
                                                                            choose_res_1650 = letpair_res_1720;
                                                                          } else {
                                                                            uint16_t id_1724 { 34 };
                                                                            bool id_1725 { bool(id_1724 == dsum1_fst_63) };
                                                                            ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 choose_res_1726;
                                                                            if (id_1725) {
                                                                              uint32_t id_1727 { 0U };
                                                                              Vec<1, uint32_t> id_1728 {  id_1727  };
                                                                              ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1729;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_97 { id_1728 };
                                                                                uint8_t id_1730 { 0 };
                                                                                Vec<1, uint8_t> id_1731 {  id_1730  };
                                                                                ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1732;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_98 { id_1731 };
                                                                                  Vec<1, Pointer> id_1733 {  dsum1_snd_64  };
                                                                                  ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1734;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_99 { id_1733 };
                                                                                    bool while_flag_1735 { true };
                                                                                    do {
                                                                                      uint8_t id_1736 { 0 };
                                                                                      Pointer id_1737 { p_ref_99[id_1736] };
                                                                                      ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1738 { id_1737.readU8() };
                                                                                      bool let_res_1739;
                                                                                      {
                                                                                        ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 leb128_100 { id_1738 };
                                                                                        bool letpair_res_1740;
                                                                                        {
                                                                                          auto leb128_fst_101 { std::get<0>(leb128_100) };
                                                                                          auto leb128_snd_102 { std::get<1>(leb128_100) };
                                                                                          uint8_t id_1741 { 0 };
                                                                                          Void id_1742 { ((void)(p_ref_99[id_1741] = leb128_snd_102), VOID) };
                                                                                          (void)id_1742;
                                                                                          uint8_t id_1743 { 0 };
                                                                                          uint8_t id_1744 { 127 };
                                                                                          uint8_t id_1745 { uint8_t(leb128_fst_101 & id_1744) };
                                                                                          uint32_t id_1746 { uint32_t(id_1745) };
                                                                                          uint8_t id_1747 { 0 };
                                                                                          uint8_t id_1748 { shft_ref_98[id_1747] };
                                                                                          uint32_t id_1749 { uint32_t(id_1746 << id_1748) };
                                                                                          uint8_t id_1750 { 0 };
                                                                                          uint32_t id_1751 { leb_ref_97[id_1750] };
                                                                                          uint32_t id_1752 { uint32_t(id_1749 | id_1751) };
                                                                                          Void id_1753 { ((void)(leb_ref_97[id_1743] = id_1752), VOID) };
                                                                                          (void)id_1753;
                                                                                          uint8_t id_1754 { 0 };
                                                                                          uint8_t id_1755 { 0 };
                                                                                          uint8_t id_1756 { shft_ref_98[id_1755] };
                                                                                          uint8_t id_1757 { 7 };
                                                                                          uint8_t id_1758 { uint8_t(id_1756 + id_1757) };
                                                                                          Void id_1759 { ((void)(shft_ref_98[id_1754] = id_1758), VOID) };
                                                                                          (void)id_1759;
                                                                                          uint8_t id_1760 { 128 };
                                                                                          bool id_1761 { bool(leb128_fst_101 >= id_1760) };
                                                                                          letpair_res_1740 = id_1761;
                                                                                        }
                                                                                        let_res_1739 = letpair_res_1740;
                                                                                      }
                                                                                      while_flag_1735 = let_res_1739;
                                                                                      if (while_flag_1735) {
                                                                                        (void)VOID;
                                                                                      }
                                                                                    } while (while_flag_1735);
                                                                                    (void)VOID;
                                                                                    uint8_t id_1762 { 0 };
                                                                                    uint32_t id_1763 { leb_ref_97[id_1762] };
                                                                                    uint8_t id_1764 { 0 };
                                                                                    Pointer id_1765 { p_ref_99[id_1764] };
                                                                                    ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1766 { id_1763, id_1765 };
                                                                                    let_res_1734 = id_1766;
                                                                                  }
                                                                                  let_res_1732 = let_res_1734;
                                                                                }
                                                                                let_res_1729 = let_res_1732;
                                                                              }
                                                                              ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 let_res_1767;
                                                                              {
                                                                                ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 dlist1_106 { let_res_1729 };
                                                                                ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 letpair_res_1768;
                                                                                {
                                                                                  auto dlist1_fst_107 { std::get<0>(dlist1_106) };
                                                                                  auto dlist1_snd_108 { std::get<1>(dlist1_106) };
                                                                                  Lst<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c> endoflist_1769;
                                                                                  ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 id_1770 { endoflist_1769, dlist1_snd_108 };
                                                                                  Vec<1, ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582> id_1771 {  id_1770  };
                                                                                  ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 let_res_1772;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582> inits_src_ref_109 { id_1771 };
                                                                                    int32_t id_1773 { 0L };
                                                                                    Vec<1, int32_t> id_1774 {  id_1773  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_110 { id_1774 };
                                                                                      bool while_flag_1775 { true };
                                                                                      do {
                                                                                        int32_t id_1776 { int32_t(dlist1_fst_107) };
                                                                                        uint8_t id_1777 { 0 };
                                                                                        int32_t id_1778 { repeat_n_110[id_1777] };
                                                                                        bool id_1779 { bool(id_1776 > id_1778) };
                                                                                        while_flag_1775 = id_1779;
                                                                                        if (while_flag_1775) {
                                                                                          uint8_t id_1780 { 0 };
                                                                                          ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 id_1781 { inits_src_ref_109[id_1780] };
                                                                                          {
                                                                                            ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 dlist2_111 { id_1781 };
                                                                                            {
                                                                                              auto dlist2_fst_112 { std::get<0>(dlist2_111) };
                                                                                              auto dlist2_snd_113 { std::get<1>(dlist2_111) };
                                                                                              uint8_t id_1782 { 0 };
                                                                                              uint32_t id_1783 { 0U };
                                                                                              Vec<1, uint32_t> id_1784 {  id_1783  };
                                                                                              ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c let_res_1785;
                                                                                              {
                                                                                                Vec<1, uint32_t> leb_ref_114 { id_1784 };
                                                                                                uint8_t id_1786 { 0 };
                                                                                                Vec<1, uint8_t> id_1787 {  id_1786  };
                                                                                                ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c let_res_1788;
                                                                                                {
                                                                                                  Vec<1, uint8_t> shft_ref_115 { id_1787 };
                                                                                                  Vec<1, Pointer> id_1789 {  dlist2_snd_113  };
                                                                                                  ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c let_res_1790;
                                                                                                  {
                                                                                                    Vec<1, Pointer> p_ref_116 { id_1789 };
                                                                                                    bool while_flag_1791 { true };
                                                                                                    do {
                                                                                                      uint8_t id_1792 { 0 };
                                                                                                      Pointer id_1793 { p_ref_116[id_1792] };
                                                                                                      ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1794 { id_1793.readU8() };
                                                                                                      bool let_res_1795;
                                                                                                      {
                                                                                                        ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 leb128_117 { id_1794 };
                                                                                                        bool letpair_res_1796;
                                                                                                        {
                                                                                                          auto leb128_fst_118 { std::get<0>(leb128_117) };
                                                                                                          auto leb128_snd_119 { std::get<1>(leb128_117) };
                                                                                                          uint8_t id_1797 { 0 };
                                                                                                          Void id_1798 { ((void)(p_ref_116[id_1797] = leb128_snd_119), VOID) };
                                                                                                          (void)id_1798;
                                                                                                          uint8_t id_1799 { 0 };
                                                                                                          uint8_t id_1800 { 127 };
                                                                                                          uint8_t id_1801 { uint8_t(leb128_fst_118 & id_1800) };
                                                                                                          uint32_t id_1802 { uint32_t(id_1801) };
                                                                                                          uint8_t id_1803 { 0 };
                                                                                                          uint8_t id_1804 { shft_ref_115[id_1803] };
                                                                                                          uint32_t id_1805 { uint32_t(id_1802 << id_1804) };
                                                                                                          uint8_t id_1806 { 0 };
                                                                                                          uint32_t id_1807 { leb_ref_114[id_1806] };
                                                                                                          uint32_t id_1808 { uint32_t(id_1805 | id_1807) };
                                                                                                          Void id_1809 { ((void)(leb_ref_114[id_1799] = id_1808), VOID) };
                                                                                                          (void)id_1809;
                                                                                                          uint8_t id_1810 { 0 };
                                                                                                          uint8_t id_1811 { 0 };
                                                                                                          uint8_t id_1812 { shft_ref_115[id_1811] };
                                                                                                          uint8_t id_1813 { 7 };
                                                                                                          uint8_t id_1814 { uint8_t(id_1812 + id_1813) };
                                                                                                          Void id_1815 { ((void)(shft_ref_115[id_1810] = id_1814), VOID) };
                                                                                                          (void)id_1815;
                                                                                                          uint8_t id_1816 { 128 };
                                                                                                          bool id_1817 { bool(leb128_fst_118 >= id_1816) };
                                                                                                          letpair_res_1796 = id_1817;
                                                                                                        }
                                                                                                        let_res_1795 = letpair_res_1796;
                                                                                                      }
                                                                                                      while_flag_1791 = let_res_1795;
                                                                                                      if (while_flag_1791) {
                                                                                                        (void)VOID;
                                                                                                      }
                                                                                                    } while (while_flag_1791);
                                                                                                    (void)VOID;
                                                                                                    uint8_t id_1818 { 0 };
                                                                                                    uint32_t id_1819 { leb_ref_114[id_1818] };
                                                                                                    Size id_1820 { Size(id_1819) };
                                                                                                    uint8_t id_1821 { 0 };
                                                                                                    Pointer id_1822 { p_ref_116[id_1821] };
                                                                                                    ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c id_1823 { id_1820, id_1822 };
                                                                                                    let_res_1790 = id_1823;
                                                                                                  }
                                                                                                  let_res_1788 = let_res_1790;
                                                                                                }
                                                                                                let_res_1785 = let_res_1788;
                                                                                              }
                                                                                              ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 let_res_1824;
                                                                                              {
                                                                                                ::dessser::gen::raql_value::t8beb80162423aee37bd383e9b6834c9c dstring1_120 { let_res_1785 };
                                                                                                ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 letpair_res_1825;
                                                                                                {
                                                                                                  auto dstring1_fst_121 { std::get<0>(dstring1_120) };
                                                                                                  auto dstring1_snd_122 { std::get<1>(dstring1_120) };
                                                                                                  ::dessser::gen::raql_value::t188345aa49abd0cb47ff73fedc219f08 id_1826 { dstring1_snd_122.readBytes(dstring1_fst_121) };
                                                                                                  ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 letpair_res_1827;
                                                                                                  {
                                                                                                    auto dstring2_fst_124 { std::get<0>(id_1826) };
                                                                                                    auto dstring2_snd_125 { std::get<1>(id_1826) };
                                                                                                    ::dessser::gen::raql_value::t45217dce3db5a9a49037839afd0048e8 id_1828 { fun1124(dstring2_snd_125) };
                                                                                                    ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 letpair_res_1829;
                                                                                                    {
                                                                                                      auto dtup_fst_130 { std::get<0>(id_1828) };
                                                                                                      auto dtup_snd_131 { std::get<1>(id_1828) };
                                                                                                      std::string id_1830 { dstring2_fst_124.toString() };
                                                                                                      ::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c id_1831 { id_1830, dtup_fst_130 };
                                                                                                      Lst<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_1832 { id_1831, dlist2_fst_112 };
                                                                                                      ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 id_1833 { id_1832, dtup_snd_131 };
                                                                                                      letpair_res_1829 = id_1833;
                                                                                                    }
                                                                                                    letpair_res_1827 = letpair_res_1829;
                                                                                                  }
                                                                                                  letpair_res_1825 = letpair_res_1827;
                                                                                                }
                                                                                                let_res_1824 = letpair_res_1825;
                                                                                              }
                                                                                              Void id_1834 { ((void)(inits_src_ref_109[id_1782] = let_res_1824), VOID) };
                                                                                              (void)id_1834;
                                                                                            }
                                                                                            (void)VOID;
                                                                                          }
                                                                                          (void)VOID;
                                                                                          uint8_t id_1835 { 0 };
                                                                                          uint8_t id_1836 { 0 };
                                                                                          int32_t id_1837 { repeat_n_110[id_1836] };
                                                                                          int32_t id_1838 { 1L };
                                                                                          int32_t id_1839 { int32_t(id_1837 + id_1838) };
                                                                                          Void id_1840 { ((void)(repeat_n_110[id_1835] = id_1839), VOID) };
                                                                                          (void)id_1840;
                                                                                          (void)id_1840;
                                                                                        }
                                                                                      } while (while_flag_1775);
                                                                                      (void)VOID;
                                                                                    }
                                                                                    (void)VOID;
                                                                                    uint8_t id_1841 { 0 };
                                                                                    ::dessser::gen::raql_value::t3e9183f42423fa301e184f85283e3582 id_1842 { inits_src_ref_109[id_1841] };
                                                                                    let_res_1772 = id_1842;
                                                                                  }
                                                                                  letpair_res_1768 = let_res_1772;
                                                                                }
                                                                                let_res_1767 = letpair_res_1768;
                                                                              }
                                                                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1843;
                                                                              {
                                                                                auto dlist4_fst_136 { std::get<0>(let_res_1767) };
                                                                                auto dlist4_snd_137 { std::get<1>(let_res_1767) };
                                                                                Arr<::dessser::gen::raql_value::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_1844 { dlist4_fst_136.toListRev() };
                                                                                ::dessser::gen::raql_value::t* id_1845 { new ::dessser::gen::raql_value::t(std::in_place_index<34>, id_1844) };
                                                                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1846 { id_1845, dlist4_snd_137 };
                                                                                letpair_res_1843 = id_1846;
                                                                              }
                                                                              choose_res_1726 = letpair_res_1843;
                                                                            } else {
                                                                              uint16_t id_1847 { 35 };
                                                                              bool id_1848 { bool(dsum1_fst_63 == id_1847) };
                                                                              Void id_1849 { ((void)(assert(id_1848)), VOID) };
                                                                              (void)id_1849;
                                                                              uint32_t id_1850 { 0U };
                                                                              Vec<1, uint32_t> id_1851 {  id_1850  };
                                                                              ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1852;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_65 { id_1851 };
                                                                                uint8_t id_1853 { 0 };
                                                                                Vec<1, uint8_t> id_1854 {  id_1853  };
                                                                                ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1855;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_66 { id_1854 };
                                                                                  Vec<1, Pointer> id_1856 {  dsum1_snd_64  };
                                                                                  ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 let_res_1857;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_67 { id_1856 };
                                                                                    bool while_flag_1858 { true };
                                                                                    do {
                                                                                      uint8_t id_1859 { 0 };
                                                                                      Pointer id_1860 { p_ref_67[id_1859] };
                                                                                      ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 id_1861 { id_1860.readU8() };
                                                                                      bool let_res_1862;
                                                                                      {
                                                                                        ::dessser::gen::raql_value::tb3f98ea670610d40658a618de3ec7b90 leb128_68 { id_1861 };
                                                                                        bool letpair_res_1863;
                                                                                        {
                                                                                          auto leb128_fst_69 { std::get<0>(leb128_68) };
                                                                                          auto leb128_snd_70 { std::get<1>(leb128_68) };
                                                                                          uint8_t id_1864 { 0 };
                                                                                          Void id_1865 { ((void)(p_ref_67[id_1864] = leb128_snd_70), VOID) };
                                                                                          (void)id_1865;
                                                                                          uint8_t id_1866 { 0 };
                                                                                          uint8_t id_1867 { 127 };
                                                                                          uint8_t id_1868 { uint8_t(leb128_fst_69 & id_1867) };
                                                                                          uint32_t id_1869 { uint32_t(id_1868) };
                                                                                          uint8_t id_1870 { 0 };
                                                                                          uint8_t id_1871 { shft_ref_66[id_1870] };
                                                                                          uint32_t id_1872 { uint32_t(id_1869 << id_1871) };
                                                                                          uint8_t id_1873 { 0 };
                                                                                          uint32_t id_1874 { leb_ref_65[id_1873] };
                                                                                          uint32_t id_1875 { uint32_t(id_1872 | id_1874) };
                                                                                          Void id_1876 { ((void)(leb_ref_65[id_1866] = id_1875), VOID) };
                                                                                          (void)id_1876;
                                                                                          uint8_t id_1877 { 0 };
                                                                                          uint8_t id_1878 { 0 };
                                                                                          uint8_t id_1879 { shft_ref_66[id_1878] };
                                                                                          uint8_t id_1880 { 7 };
                                                                                          uint8_t id_1881 { uint8_t(id_1879 + id_1880) };
                                                                                          Void id_1882 { ((void)(shft_ref_66[id_1877] = id_1881), VOID) };
                                                                                          (void)id_1882;
                                                                                          uint8_t id_1883 { 128 };
                                                                                          bool id_1884 { bool(leb128_fst_69 >= id_1883) };
                                                                                          letpair_res_1863 = id_1884;
                                                                                        }
                                                                                        let_res_1862 = letpair_res_1863;
                                                                                      }
                                                                                      while_flag_1858 = let_res_1862;
                                                                                      if (while_flag_1858) {
                                                                                        (void)VOID;
                                                                                      }
                                                                                    } while (while_flag_1858);
                                                                                    (void)VOID;
                                                                                    uint8_t id_1885 { 0 };
                                                                                    uint32_t id_1886 { leb_ref_65[id_1885] };
                                                                                    uint8_t id_1887 { 0 };
                                                                                    Pointer id_1888 { p_ref_67[id_1887] };
                                                                                    ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 id_1889 { id_1886, id_1888 };
                                                                                    let_res_1857 = id_1889;
                                                                                  }
                                                                                  let_res_1855 = let_res_1857;
                                                                                }
                                                                                let_res_1852 = let_res_1855;
                                                                              }
                                                                              ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 let_res_1890;
                                                                              {
                                                                                ::dessser::gen::raql_value::t405eb186408556fed8f2c41523c07d13 dlist1_74 { let_res_1852 };
                                                                                ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 letpair_res_1891;
                                                                                {
                                                                                  auto dlist1_fst_75 { std::get<0>(dlist1_74) };
                                                                                  auto dlist1_snd_76 { std::get<1>(dlist1_74) };
                                                                                  Lst<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> endoflist_1892;
                                                                                  ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 id_1893 { endoflist_1892, dlist1_snd_76 };
                                                                                  Vec<1, ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87> id_1894 {  id_1893  };
                                                                                  ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 let_res_1895;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87> inits_src_ref_77 { id_1894 };
                                                                                    int32_t id_1896 { 0L };
                                                                                    Vec<1, int32_t> id_1897 {  id_1896  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_78 { id_1897 };
                                                                                      bool while_flag_1898 { true };
                                                                                      do {
                                                                                        int32_t id_1899 { int32_t(dlist1_fst_75) };
                                                                                        uint8_t id_1900 { 0 };
                                                                                        int32_t id_1901 { repeat_n_78[id_1900] };
                                                                                        bool id_1902 { bool(id_1899 > id_1901) };
                                                                                        while_flag_1898 = id_1902;
                                                                                        if (while_flag_1898) {
                                                                                          uint8_t id_1903 { 0 };
                                                                                          ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 id_1904 { inits_src_ref_77[id_1903] };
                                                                                          {
                                                                                            ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 dlist2_79 { id_1904 };
                                                                                            {
                                                                                              auto dlist2_fst_80 { std::get<0>(dlist2_79) };
                                                                                              auto dlist2_snd_81 { std::get<1>(dlist2_79) };
                                                                                              uint8_t id_1905 { 0 };
                                                                                              ::dessser::gen::raql_value::t45217dce3db5a9a49037839afd0048e8 id_1906 { fun1124(dlist2_snd_81) };
                                                                                              ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 letpair_res_1907;
                                                                                              {
                                                                                                auto dtup_fst_83 { std::get<0>(id_1906) };
                                                                                                auto dtup_snd_84 { std::get<1>(id_1906) };
                                                                                                ::dessser::gen::raql_value::t45217dce3db5a9a49037839afd0048e8 id_1908 { fun1124(dtup_snd_84) };
                                                                                                ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 letpair_res_1909;
                                                                                                {
                                                                                                  auto dtup_fst_86 { std::get<0>(id_1908) };
                                                                                                  auto dtup_snd_87 { std::get<1>(id_1908) };
                                                                                                  ::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf id_1910 { dtup_fst_83, dtup_fst_86 };
                                                                                                  Lst<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> id_1911 { id_1910, dlist2_fst_80 };
                                                                                                  ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 id_1912 { id_1911, dtup_snd_87 };
                                                                                                  letpair_res_1909 = id_1912;
                                                                                                }
                                                                                                letpair_res_1907 = letpair_res_1909;
                                                                                              }
                                                                                              Void id_1913 { ((void)(inits_src_ref_77[id_1905] = letpair_res_1907), VOID) };
                                                                                              (void)id_1913;
                                                                                            }
                                                                                            (void)VOID;
                                                                                          }
                                                                                          (void)VOID;
                                                                                          uint8_t id_1914 { 0 };
                                                                                          uint8_t id_1915 { 0 };
                                                                                          int32_t id_1916 { repeat_n_78[id_1915] };
                                                                                          int32_t id_1917 { 1L };
                                                                                          int32_t id_1918 { int32_t(id_1916 + id_1917) };
                                                                                          Void id_1919 { ((void)(repeat_n_78[id_1914] = id_1918), VOID) };
                                                                                          (void)id_1919;
                                                                                          (void)id_1919;
                                                                                        }
                                                                                      } while (while_flag_1898);
                                                                                      (void)VOID;
                                                                                    }
                                                                                    (void)VOID;
                                                                                    uint8_t id_1920 { 0 };
                                                                                    ::dessser::gen::raql_value::tf4ebf93395ce1142f131bdef5e190b87 id_1921 { inits_src_ref_77[id_1920] };
                                                                                    let_res_1895 = id_1921;
                                                                                  }
                                                                                  letpair_res_1891 = let_res_1895;
                                                                                }
                                                                                let_res_1890 = letpair_res_1891;
                                                                              }
                                                                              ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1922;
                                                                              {
                                                                                auto dlist4_fst_92 { std::get<0>(let_res_1890) };
                                                                                auto dlist4_snd_93 { std::get<1>(let_res_1890) };
                                                                                Arr<::dessser::gen::raql_value::t7411897bdb6c9b6e00a01b4eb6506ccf> id_1923 { dlist4_fst_92.toListRev() };
                                                                                ::dessser::gen::raql_value::t* id_1924 { new ::dessser::gen::raql_value::t(std::in_place_index<35>, id_1923) };
                                                                                ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1925 { id_1924, dlist4_snd_93 };
                                                                                letpair_res_1922 = id_1925;
                                                                              }
                                                                              choose_res_1726 = letpair_res_1922;
                                                                            }
                                                                            choose_res_1650 = choose_res_1726;
                                                                          }
                                                                          choose_res_1574 = choose_res_1650;
                                                                        }
                                                                        choose_res_1498 = choose_res_1574;
                                                                      }
                                                                      choose_res_1451 = choose_res_1498;
                                                                    }
                                                                    choose_res_1434 = choose_res_1451;
                                                                  }
                                                                  choose_res_1417 = choose_res_1434;
                                                                }
                                                                choose_res_1386 = choose_res_1417;
                                                              }
                                                              choose_res_1377 = choose_res_1386;
                                                            }
                                                            choose_res_1368 = choose_res_1377;
                                                          }
                                                          choose_res_1358 = choose_res_1368;
                                                        }
                                                        choose_res_1350 = choose_res_1358;
                                                      }
                                                      choose_res_1342 = choose_res_1350;
                                                    }
                                                    choose_res_1334 = choose_res_1342;
                                                  }
                                                  choose_res_1326 = choose_res_1334;
                                                }
                                                choose_res_1318 = choose_res_1326;
                                              }
                                              choose_res_1310 = choose_res_1318;
                                            }
                                            choose_res_1302 = choose_res_1310;
                                          }
                                          choose_res_1294 = choose_res_1302;
                                        }
                                        choose_res_1286 = choose_res_1294;
                                      }
                                      choose_res_1279 = choose_res_1286;
                                    }
                                    choose_res_1272 = choose_res_1279;
                                  }
                                  choose_res_1264 = choose_res_1272;
                                }
                                choose_res_1256 = choose_res_1264;
                              }
                              choose_res_1248 = choose_res_1256;
                            }
                            choose_res_1241 = choose_res_1248;
                          }
                          choose_res_1233 = choose_res_1241;
                        }
                        choose_res_1226 = choose_res_1233;
                      }
                      choose_res_1219 = choose_res_1226;
                    }
                    choose_res_1211 = choose_res_1219;
                  }
                  choose_res_1201 = choose_res_1211;
                }
                choose_res_1150 = choose_res_1201;
              }
              choose_res_1142 = choose_res_1150;
            }
            choose_res_1137 = choose_res_1142;
          }
          choose_res_1132 = choose_res_1137;
        }
        letpair_res_1129 = choose_res_1132;
      }
      let_res_1128 = letpair_res_1129;
    }
    ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 letpair_res_1926;
    {
      auto make_fst_526 { std::get<0>(let_res_1128) };
      auto make_snd_527 { std::get<1>(let_res_1128) };
      ::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0 id_1927 { make_fst_526, make_snd_527 };
      letpair_res_1926 = id_1927;
    }
    return letpair_res_1926;
  }
   };
  return fun1124;
}
std::function<::dessser::gen::raql_value::t85eb9b4ae6397e976e7bd6d60235f8d0(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
