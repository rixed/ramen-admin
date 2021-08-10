#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::raql_value {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct cc9ac153fc4d8a1128cc88896605e565 : public std::variant<
  uint32_t,
  uint128_t
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, cc9ac153fc4d8a1128cc88896605e565 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct v_02f625c0a7ec8df42167994cc126588a {
  uint32_t ip;
  uint8_t mask;
  bool operator==(v_02f625c0a7ec8df42167994cc126588a const &other) const {
    return ip == other.ip && mask == other.mask;
  }
};
std::ostream &operator<<(std::ostream &os, v_02f625c0a7ec8df42167994cc126588a const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "mask:" << r.mask;
  os << '}';
  return os;
}

struct e71a8d193957147ef8ce48ce7c420601 {
  uint128_t ip;
  uint8_t mask;
  bool operator==(e71a8d193957147ef8ce48ce7c420601 const &other) const {
    return ip == other.ip && mask == other.mask;
  }
};
std::ostream &operator<<(std::ostream &os, e71a8d193957147ef8ce48ce7c420601 const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "mask:" << r.mask;
  os << '}';
  return os;
}

struct v_15f8f12566613b8539906fe1981330fe : public std::variant<
  v_02f625c0a7ec8df42167994cc126588a,
  e71a8d193957147ef8ce48ce7c420601
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_15f8f12566613b8539906fe1981330fe const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  std::string,
  t*
> v_7fc8d7a0a67813ab72751cde815990fd;

struct t;
struct t;
typedef std::tuple<
  t*,
  t*
> v_88361d7e3c5fc5844d2ff9213ba400b1;

struct t : public std::variant<
  Void,
  Void,
  double,
  std::string,
  bool,
  char,
  uint8_t,
  uint16_t,
  uint32_t,
  uint32_t,
  uint64_t,
  uint64_t,
  uint64_t,
  uint64_t,
  uint128_t,
  int8_t,
  int16_t,
  int32_t,
  int32_t,
  int64_t,
  int64_t,
  int64_t,
  int64_t,
  int128_t,
  uint64_t,
  uint32_t,
  uint128_t,
  cc9ac153fc4d8a1128cc88896605e565,
  v_02f625c0a7ec8df42167994cc126588a,
  e71a8d193957147ef8ce48ce7c420601,
  v_15f8f12566613b8539906fe1981330fe,
  Arr<t*>,
  Arr<t*>,
  Arr<t*>,
  Arr<v_7fc8d7a0a67813ab72751cde815990fd>,
  Arr<v_88361d7e3c5fc5844d2ff9213ba400b1>
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
    case 8: os << std::get<8>(v); break;
    case 9: os << std::get<9>(v); break;
    case 10: os << std::get<10>(v); break;
    case 11: os << std::get<11>(v); break;
    case 12: os << std::get<12>(v); break;
    case 13: os << std::get<13>(v); break;
    case 14: os << std::get<14>(v); break;
    case 15: os << std::get<15>(v); break;
    case 16: os << std::get<16>(v); break;
    case 17: os << std::get<17>(v); break;
    case 18: os << std::get<18>(v); break;
    case 19: os << std::get<19>(v); break;
    case 20: os << std::get<20>(v); break;
    case 21: os << std::get<21>(v); break;
    case 22: os << std::get<22>(v); break;
    case 23: os << std::get<23>(v); break;
    case 24: os << std::get<24>(v); break;
    case 25: os << std::get<25>(v); break;
    case 26: os << std::get<26>(v); break;
    case 27: os << std::get<27>(v); break;
    case 28: os << std::get<28>(v); break;
    case 29: os << std::get<29>(v); break;
    case 30: os << std::get<30>(v); break;
    case 31: os << std::get<31>(v); break;
    case 32: os << std::get<32>(v); break;
    case 33: os << std::get<33>(v); break;
    case 34: os << std::get<34>(v); break;
    case 35: os << std::get<35>(v); break;
  }
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
