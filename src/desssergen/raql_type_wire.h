#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  uint32_t,
  t*
> v_21d42a88cbfa8d217bab3e5ff3c8293a;

typedef std::tuple<
  std::string,
  t*
> v_7fc8d7a0a67813ab72751cde815990fd;

typedef std::tuple<
  t*,
  t*
> v_88361d7e3c5fc5844d2ff9213ba400b1;

struct af7296d43d3d217e0560bba37ac4a9f7 : public std::variant<
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
  v_21d42a88cbfa8d217bab3e5ff3c8293a,
  t*,
  Arr<v_7fc8d7a0a67813ab72751cde815990fd>,
  Arr<v_7fc8d7a0a67813ab72751cde815990fd>,
  v_88361d7e3c5fc5844d2ff9213ba400b1
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, af7296d43d3d217e0560bba37ac4a9f7 const &v) {
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

struct t {
  af7296d43d3d217e0560bba37ac4a9f7 type;
  bool nullable;
  bool operator==(t const &other) const {
    return type == other.type && nullable == other.nullable;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "type:" << r.type << ',';
  os << "nullable:" << r.nullable;
  os << '}';
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
