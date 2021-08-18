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
struct t2dfffd4312923e34e0c3ba0f8d708626 : public std::variant<
  uint32_t,
  uint128_t
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t2dfffd4312923e34e0c3ba0f8d708626 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t0e8fd8e4985161b0a31c95457a9d7013 {
  uint32_t ip;
  uint8_t mask;
  bool operator==(t0e8fd8e4985161b0a31c95457a9d7013 const &other) const {
    return ip == other.ip && mask == other.mask;
  }
};
inline std::ostream &operator<<(std::ostream &os, t0e8fd8e4985161b0a31c95457a9d7013 const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "mask:" << r.mask;
  os << '}';
  return os;
}

struct t51bc874aa6932e2400d81510c260c7c1 {
  uint128_t ip;
  uint8_t mask;
  bool operator==(t51bc874aa6932e2400d81510c260c7c1 const &other) const {
    return ip == other.ip && mask == other.mask;
  }
};
inline std::ostream &operator<<(std::ostream &os, t51bc874aa6932e2400d81510c260c7c1 const &r) {
  os << '{';
  os << "ip:" << r.ip << ',';
  os << "mask:" << r.mask;
  os << '}';
  return os;
}

struct t0ad6dd9e2a8cc9b8c03e7324c11a5d6e : public std::variant<
  t0e8fd8e4985161b0a31c95457a9d7013,
  t51bc874aa6932e2400d81510c260c7c1
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t0ad6dd9e2a8cc9b8c03e7324c11a5d6e const &v) {
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
struct t;
typedef std::tuple<
  std::string,
  t*
> t100b7e5cf4b9a621db7a39d7f1d01e5c;

struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  t*,
  t*
> t7411897bdb6c9b6e00a01b4eb6506ccf;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
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
  t2dfffd4312923e34e0c3ba0f8d708626,
  t0e8fd8e4985161b0a31c95457a9d7013,
  t51bc874aa6932e2400d81510c260c7c1,
  t0ad6dd9e2a8cc9b8c03e7324c11a5d6e,
  Arr<t*>,
  Arr<t*>,
  Arr<t*>,
  Arr<t100b7e5cf4b9a621db7a39d7f1d01e5c>,
  Arr<t7411897bdb6c9b6e00a01b4eb6506ccf>
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
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

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t*,Pointer)> to_row_binary;
extern std::function<Size(t*)> sersize_of_row_binary;
extern std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
