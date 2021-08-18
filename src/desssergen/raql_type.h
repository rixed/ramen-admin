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
struct t;
struct t;
typedef std::tuple<
  uint32_t,
  t*
> t9327d6336842c469509b67056a719df9;

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
struct t;
struct t82f0fed4e9a4095dda4e6566499e3c0d : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Arr<t*>,
  t9327d6336842c469509b67056a719df9,
  t*,
  Arr<t100b7e5cf4b9a621db7a39d7f1d01e5c>,
  Arr<t100b7e5cf4b9a621db7a39d7f1d01e5c>,
  t7411897bdb6c9b6e00a01b4eb6506ccf
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t82f0fed4e9a4095dda4e6566499e3c0d const &v) {
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
struct t {
  t82f0fed4e9a4095dda4e6566499e3c0d type;
  bool nullable;
  bool operator==(t const &other) const {
    return type == other.type && nullable == other.nullable;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "type:" << r.type << ',';
  os << "nullable:" << r.nullable;
  os << '}';
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
