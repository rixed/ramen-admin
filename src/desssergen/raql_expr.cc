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

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

namespace dessser::gen::raql_expr {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t;
struct t;
typedef std::tuple<
  dessser::gen::field_name::t,
  t*
> v_4ec9e9432e07cae1458c03426a194a1a;

struct t;
struct t;
struct t;
struct a1a2ab208d8a8e56a609f18e422bdf88 {
  t* case_cond;
  t* case_cons;
  bool operator==(a1a2ab208d8a8e56a609f18e422bdf88 const &other) const {
    return case_cond == other.case_cond && case_cons == other.case_cons;
  }
};
std::ostream &operator<<(std::ostream &os, a1a2ab208d8a8e56a609f18e422bdf88 const &r) {
  os << '{';
  os << "case_cond:" << r.case_cond << ',';
  os << "case_cons:" << r.case_cons;
  os << '}';
  return os;
}

struct t;
typedef std::tuple<
  Lst<a1a2ab208d8a8e56a609f18e422bdf88>,
  std::optional<t*>
> v_7df1ef9c4e82bfdd017031822619493c;

struct b02d571406bf80b296e55bb93213ea59 : public std::variant<
  dessser::gen::raql_value::t,
  dessser::gen::raql_variable::t,
  dessser::gen::raql_binding_key::t,
  Void,
  Void,
  Void,
  Void,
  Lst<dessser::gen::raql_path_comp::t>,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, b02d571406bf80b296e55bb93213ea59 const &v) {
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
  }
  return os;
}

struct b31ee7e2e15bec4cfa9176ec3d86152e : public std::variant<
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, b31ee7e2e15bec4cfa9176ec3d86152e const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::raql_type::t,
  b31ee7e2e15bec4cfa9176ec3d86152e
> v_562760c1b2585f63d315bb555b64832c;

struct v_1d6ee587a956ed7717b51cc22dd3b087 : public std::variant<
  Void,
  dessser::gen::raql_type::t,
  Void,
  v_562760c1b2585f63d315bb555b64832c,
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
  Void,
  Void,
  std::string,
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_1d6ee587a956ed7717b51cc22dd3b087 const &v) {
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
    case 36: os << std::get<36>(v); break;
    case 37: os << std::get<37>(v); break;
    case 38: os << std::get<38>(v); break;
    case 39: os << std::get<39>(v); break;
    case 40: os << std::get<40>(v); break;
  }
  return os;
}

struct t;
typedef std::tuple<
  v_1d6ee587a956ed7717b51cc22dd3b087,
  t*
> v_86716e60fd92843b928cbb08bc52f333;

struct v_38879d3066416481efb8a2cff1fd95bb : public std::variant<
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_38879d3066416481efb8a2cff1fd95bb const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

struct t;
typedef std::tuple<
  v_38879d3066416481efb8a2cff1fd95bb,
  Lst<t*>
> v_3b28b4928a9e27104e63a502937d8fd6;

struct v_20bb2b786e4d41528e682385744fec03 : public std::variant<
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
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_20bb2b786e4d41528e682385744fec03 const &v) {
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
  }
  return os;
}

struct t;
struct t;
struct v_8987bf3ba5adfaa68384b9fde66ab651 : public std::tuple<
  v_20bb2b786e4d41528e682385744fec03,
  t*,
  t*
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_8987bf3ba5adfaa68384b9fde66ab651 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct v_4b68f284ffe696cb6936ca2f6880b08a : public std::variant<
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_4b68f284ffe696cb6936ca2f6880b08a const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t;
struct t;
struct t;
struct v_3d59f26fb89fa3ef8dc792c2f4609b32 : public std::tuple<
  v_4b68f284ffe696cb6936ca2f6880b08a,
  t*,
  t*,
  t*
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_3d59f26fb89fa3ef8dc792c2f4609b32 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct a481e1e269544fa0efe70fc68e01b3bb : public std::variant<
  b02d571406bf80b296e55bb93213ea59,
  v_86716e60fd92843b928cbb08bc52f333,
  v_3b28b4928a9e27104e63a502937d8fd6,
  v_8987bf3ba5adfaa68384b9fde66ab651,
  v_3d59f26fb89fa3ef8dc792c2f4609b32
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, a481e1e269544fa0efe70fc68e01b3bb const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
  }
  return os;
}

struct d9442fc1deb39566ea1af2c5bee72a1c : public std::variant<
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, d9442fc1deb39566ea1af2c5bee72a1c const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct ff127e01aa6516985aeb6ae62f964e8f : public std::tuple<
  double,
  double,
  uint32_t
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, ff127e01aa6516985aeb6ae62f964e8f const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct v_04da9e7d4c0ea0d028b50b2b2bf068b2 : public std::variant<
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
  ff127e01aa6516985aeb6ae62f964e8f,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_04da9e7d4c0ea0d028b50b2b2bf068b2 const &v) {
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
  }
  return os;
}

struct t;
typedef std::tuple<
  v_04da9e7d4c0ea0d028b50b2b2bf068b2,
  t*
> b899c3a5f918df0742a7782ddf15cd18;

struct v_1bafb672d5db6e6c81afc008103c3a63 : public std::variant<
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_1bafb672d5db6e6c81afc008103c3a63 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

struct t;
struct t;
struct bd090e444c05c1e6fea8a3c1c0be1d01 : public std::tuple<
  v_1bafb672d5db6e6c81afc008103c3a63,
  t*,
  t*
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, bd090e444c05c1e6fea8a3c1c0be1d01 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct bf5e3bf9cedd12797481a910416c04b9 : public std::variant<
  Void,
  Void,
  bool
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, bf5e3bf9cedd12797481a910416c04b9 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct t;
struct t;
struct t;
struct bf3bba49b7fb7fb20a2d18c9ba46e6e9 : public std::tuple<
  bf5e3bf9cedd12797481a910416c04b9,
  t*,
  t*,
  t*
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, bf3bba49b7fb7fb20a2d18c9ba46e6e9 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct v_87b032206ceea8867a37c2e0aaee953e : public std::variant<
  Void,
  bool
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_87b032206ceea8867a37c2e0aaee953e const &v) {
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
struct v_853c6bada9e3fde79da0a65d1b1d1c9a : public std::tuple<
  v_87b032206ceea8867a37c2e0aaee953e,
  t*,
  t*,
  t*,
  t*
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_853c6bada9e3fde79da0a65d1b1d1c9a const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t) << ", "
     << std::get<4>(t)
     << '>';
  return os;
}

struct v_0cb2265b788de1dea43d444c41f930d3 {
  bool inv;
  bool up_to;
  bool operator==(v_0cb2265b788de1dea43d444c41f930d3 const &other) const {
    return inv == other.inv && up_to == other.up_to;
  }
};
std::ostream &operator<<(std::ostream &os, v_0cb2265b788de1dea43d444c41f930d3 const &r) {
  os << '{';
  os << "inv:" << r.inv << ',';
  os << "up_to:" << r.up_to;
  os << '}';
  return os;
}

struct v_40203346c83d9d499f90ff16996e8968 : public std::variant<
  Void,
  v_0cb2265b788de1dea43d444c41f930d3
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_40203346c83d9d499f90ff16996e8968 const &v) {
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
struct d48e39cf1002fefa9b2dd8287b9e36b3 : public std::tuple<
  v_40203346c83d9d499f90ff16996e8968,
  t*,
  t*,
  t*,
  Lst<t*>
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, d48e39cf1002fefa9b2dd8287b9e36b3 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t) << ", "
     << std::get<4>(t)
     << '>';
  return os;
}

struct d137ffedb0c351c86760c7f124759f50 : public std::variant<
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, d137ffedb0c351c86760c7f124759f50 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct v_28696cf4b42cc9ab09b392e5143f2f25 : public std::tuple<
  d137ffedb0c351c86760c7f124759f50,
  t*,
  t*,
  t*,
  t*,
  t*,
  t*
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_28696cf4b42cc9ab09b392e5143f2f25 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t) << ", "
     << std::get<4>(t) << ", "
     << std::get<5>(t) << ", "
     << std::get<6>(t)
     << '>';
  return os;
}

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct v_2da729c5f96e51679cb6e2c06e6ceb25 {
  dessser::gen::raql_top_output::t output;
  t* size;
  std::optional<t*> max_size;
  t* what;
  t* by;
  t* time;
  t* duration;
  t* sigmas;
  bool operator==(v_2da729c5f96e51679cb6e2c06e6ceb25 const &other) const {
    return output == other.output && size == other.size && max_size == other.max_size && what == other.what && by == other.by && time == other.time && duration == other.duration && sigmas == other.sigmas;
  }
};
std::ostream &operator<<(std::ostream &os, v_2da729c5f96e51679cb6e2c06e6ceb25 const &r) {
  os << '{';
  os << "output:" << r.output << ',';
  os << "size:" << r.size << ',';
  os << "max_size:" << r.max_size << ',';
  os << "what:" << r.what << ',';
  os << "by:" << r.by << ',';
  os << "time:" << r.time << ',';
  os << "duration:" << r.duration << ',';
  os << "sigmas:" << r.sigmas;
  os << '}';
  return os;
}

struct t;
struct t;
struct t;
struct t;
struct v_148d37e471eb6790a77b16fc96041a20 {
  t* what;
  t* time;
  t* max_age;
  bool tumbling;
  std::optional<t*> sample_size;
  bool operator==(v_148d37e471eb6790a77b16fc96041a20 const &other) const {
    return what == other.what && time == other.time && max_age == other.max_age && tumbling == other.tumbling && sample_size == other.sample_size;
  }
};
std::ostream &operator<<(std::ostream &os, v_148d37e471eb6790a77b16fc96041a20 const &r) {
  os << '{';
  os << "what:" << r.what << ',';
  os << "time:" << r.time << ',';
  os << "max_age:" << r.max_age << ',';
  os << "tumbling:" << r.tumbling << ',';
  os << "sample_size:" << r.sample_size;
  os << '}';
  return os;
}

struct v_2a737e40b715df686303c32fcaefae73 : public std::variant<
  b899c3a5f918df0742a7782ddf15cd18,
  bd090e444c05c1e6fea8a3c1c0be1d01,
  bf3bba49b7fb7fb20a2d18c9ba46e6e9,
  v_853c6bada9e3fde79da0a65d1b1d1c9a,
  d48e39cf1002fefa9b2dd8287b9e36b3,
  v_28696cf4b42cc9ab09b392e5143f2f25,
  v_2da729c5f96e51679cb6e2c06e6ceb25,
  v_148d37e471eb6790a77b16fc96041a20
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_2a737e40b715df686303c32fcaefae73 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
  }
  return os;
}

struct v_58c653b3fc47800248b5c8f49e80fabb : public std::tuple<
  d9442fc1deb39566ea1af2c5bee72a1c,
  bool,
  v_2a737e40b715df686303c32fcaefae73
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_58c653b3fc47800248b5c8f49e80fabb const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t;
struct t;
typedef std::tuple<
  t*,
  t*
> v_88361d7e3c5fc5844d2ff9213ba400b1;

struct v_1c5224020b28e5bf4853392434fd6e31 : public std::variant<
  v_88361d7e3c5fc5844d2ff9213ba400b1
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_1c5224020b28e5bf4853392434fd6e31 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

struct dc31f5cc689133a6f12d16478388e785 : public std::variant<
  Lst<t*>,
  Lst<v_4ec9e9432e07cae1458c03426a194a1a>,
  Lst<t*>,
  v_7df1ef9c4e82bfdd017031822619493c,
  a481e1e269544fa0efe70fc68e01b3bb,
  v_58c653b3fc47800248b5c8f49e80fabb,
  v_1c5224020b28e5bf4853392434fd6e31
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, dc31f5cc689133a6f12d16478388e785 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
  }
  return os;
}

struct t {
  dc31f5cc689133a6f12d16478388e785 text;
  uint32_t uniq_num;
  dessser::gen::raql_type::t typ;
  std::optional<dessser::gen::units::t> units;
  bool operator==(t const &other) const {
    return text == other.text && uniq_num == other.uniq_num && typ == other.typ && units == other.units;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "text:" << r.text << ',';
  os << "uniq_num:" << r.uniq_num << ',';
  os << "typ:" << r.typ << ',';
  os << "units:" << r.units;
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
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  uint16_t,
  Pointer
> v_362f9d9108a6902af48b6c83d5377ea1;

typedef std::tuple<
  dc31f5cc689133a6f12d16478388e785,
  Pointer
> f05619a6958568f0d4db38b191811dc1;

typedef std::tuple<
  uint32_t,
  Pointer
> ac0fbd05039f742d2f1d9ac182e392ab;

typedef std::tuple<
  uint8_t,
  Pointer
> v_1d5843897434feb24d158f3793db9189;

struct t;
typedef std::tuple<
  Lst<t*>,
  Pointer
> e8d9438e2f3a196555a010d8d14a3c3a;

struct t;
struct t;
typedef std::tuple<
  Lst<v_4ec9e9432e07cae1458c03426a194a1a>,
  Pointer
> ddcd449f1e33242c42af2676798021aa;

typedef std::tuple<
  dessser::gen::field_name::t,
  Pointer
> c50aa083fa818c6eeca389b0025dda98;

struct t;
struct t;
typedef std::tuple<
  Lst<a1a2ab208d8a8e56a609f18e422bdf88>,
  Pointer
> v_0f57f764bcc167c70e5ac8f496b908b3;

struct t;
typedef std::tuple<
  std::optional<t*>,
  Pointer
> ff77a37bf330c28b69daf62f3f59e310;

struct t;
struct t;
typedef std::tuple<
  a481e1e269544fa0efe70fc68e01b3bb,
  Pointer
> b1ffdd8a8f59914e8b21c924b278b478;

typedef std::tuple<
  b02d571406bf80b296e55bb93213ea59,
  Pointer
> v_38bf909989bc149a6bff52aacf0b29a7;

typedef std::tuple<
  dessser::gen::raql_value::t,
  Pointer
> ba3b596d6a5cbc29dc62e6e6a46440d5;

typedef std::tuple<
  dessser::gen::raql_variable::t,
  Pointer
> v_0f2a71b58e80153fa85a979b6a0daf94;

typedef std::tuple<
  dessser::gen::raql_binding_key::t,
  Pointer
> eeea9b724957fbc1223450da0773b8d1;

typedef std::tuple<
  Lst<dessser::gen::raql_path_comp::t>,
  Pointer
> v_8576a0d6d1057dc98fce5cca4d47a633;

typedef std::tuple<
  dessser::gen::raql_path_comp::t,
  Pointer
> v_846cc5205657e1110a638b474c92c1c7;

typedef std::tuple<
  v_1d6ee587a956ed7717b51cc22dd3b087,
  Pointer
> v_13312187dea5608a1b10367f2c8e4e74;

typedef std::tuple<
  dessser::gen::raql_type::t,
  Pointer
> v_1afe9f73328d6d7bdf808b1d2eb2af22;

typedef std::tuple<
  b31ee7e2e15bec4cfa9176ec3d86152e,
  Pointer
> v_98c807c6ad3234380e91fff9a3df5c99;

typedef std::tuple<
  Size,
  Pointer
> v_41b0681ed7f1f185fd3e6c4dcdc13110;

typedef std::tuple<
  Bytes,
  Pointer
> f921d1e0a170c3c04148c21704db9c45;

typedef std::tuple<
  v_38879d3066416481efb8a2cff1fd95bb,
  Pointer
> v_9b45f13f89886b24a901e49d3b1f88b9;

struct t;
struct t;
typedef std::tuple<
  v_20bb2b786e4d41528e682385744fec03,
  Pointer
> v_407ccfea1dff98b1bc3e1754c13cff98;

typedef std::tuple<
  v_4b68f284ffe696cb6936ca2f6880b08a,
  Pointer
> v_10a2bfff0e71a34103d9ba64b2a811ea;

typedef std::tuple<
  d9442fc1deb39566ea1af2c5bee72a1c,
  Pointer
> v_3e1a490698d382316a95f8c9ebeef293;

typedef std::tuple<
  bool,
  Pointer
> f2a48a42f9c827f487e53ee52a4e9e2f;

typedef std::tuple<
  v_2a737e40b715df686303c32fcaefae73,
  Pointer
> v_9f6c76bf140d94510c6437dee417ba9f;

typedef std::tuple<
  v_04da9e7d4c0ea0d028b50b2b2bf068b2,
  Pointer
> c0d7f0e7f711b7617e3f34692ada98f5;

typedef std::tuple<
  uint64_t,
  Pointer
> b62e103e7915a76f45f02f7c6f667c79;

typedef std::tuple<
  double,
  Pointer
> v_41a5a8cf414de9bfdc6375241fcc910a;

typedef std::tuple<
  v_1bafb672d5db6e6c81afc008103c3a63,
  Pointer
> v_5d97723b1b63aa3df1222ecb758e8bc2;

typedef std::tuple<
  bf5e3bf9cedd12797481a910416c04b9,
  Pointer
> v_4ef2e9135749a8c10bb981c20e0409c7;

typedef std::tuple<
  v_87b032206ceea8867a37c2e0aaee953e,
  Pointer
> be50f132b1070740f04581361279b652;

typedef std::tuple<
  v_40203346c83d9d499f90ff16996e8968,
  Pointer
> e95534d23d0ba3bdeaf86aa35c50c907;

struct t;
struct t;
typedef std::tuple<
  dessser::gen::raql_top_output::t,
  Pointer
> v_782396e4e62e54e181f157869588e15c;

struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  std::optional<dessser::gen::units::t>,
  Pointer
> bf974315651fdd731eda317cf9d211f4;

typedef std::tuple<
  dessser::gen::units::t,
  Pointer
> v_765fc2dfa0d4b4acfe348a1dcf7356d2;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{text: [Tuple THIS[[]] | Record ($field_name; THIS)[[]] | Vector THIS[[]] | Case ({case_cond: THIS; case_cons: THIS}[[]]; THIS?) | Stateless [SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)] | Stateful ([LocalState Void | GlobalState Void]; BOOL; [SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]) | Generator [Split (THIS; THIS)]]; uniq_num: U32; typ: $raql_type; units: $units?}" "Ptr")
      (let "srec_dst_1288"
        (let "srec_dst_1287"
          (let "srec_dst_1286"
            (let "label1_1165" (label-of (get-field "text" (param 0)))
              (let "ssum_dst_1166" (write-u16 little-endian (param 1) (identifier "label1_1165"))
                (if (eq (u16 0) (identifier "label1_1165"))
                  (let "dst_ref_1283"
                    (make-vec
                      (let "leb128_sz_1281" (make-vec (cardinality (get-alt "Tuple" (get-field "text" (param 0)))))
                        (let "leb128_ptr_1282" (make-vec (identifier "ssum_dst_1166"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_1282")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_1282"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_1281"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1281"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1281"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_1281") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_1281")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_1281")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_1282"))))))
                    (let "n_ref_1284" (make-vec (i32 0))
                      (seq
                        (for-each "x_1285" (get-alt "Tuple" (get-field "text" (param 0)))
                          (seq (set-vec (u8 0) (identifier "dst_ref_1283") (apply (myself "Ptr") (identifier "x_1285") (unsafe-nth (u8 0) (identifier "dst_ref_1283"))))
                            (set-vec (u8 0) (identifier "n_ref_1284") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_1284")))))) 
                        (unsafe-nth (u8 0) (identifier "dst_ref_1283")))))
                  (if (eq (u16 1) (identifier "label1_1165"))
                    (let "dst_ref_1276"
                      (make-vec
                        (let "leb128_sz_1274" (make-vec (cardinality (get-alt "Record" (get-field "text" (param 0)))))
                          (let "leb128_ptr_1275" (make-vec (identifier "ssum_dst_1166"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_1275")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_1275"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_1274"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1274"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1274"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_1274") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_1274")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_1274")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_1275"))))))
                      (let "n_ref_1277" (make-vec (i32 0))
                        (seq
                          (for-each "x_1278" (get-alt "Record" (get-field "text" (param 0)))
                            (seq
                              (set-vec (u8 0) (identifier "dst_ref_1276")
                                (apply (myself "Ptr") (get-item 1 (identifier "x_1278"))
                                  (let "stup_dst_1279" (unsafe-nth (u8 0) (identifier "dst_ref_1276")) (apply (ext-identifier field_name to-row-binary) (get-item 0 (identifier "x_1278")) (identifier "stup_dst_1279")))))
                              (set-vec (u8 0) (identifier "n_ref_1277") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_1277")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_1276")))))
                    (if (eq (u16 2) (identifier "label1_1165"))
                      (let "dst_ref_1271"
                        (make-vec
                          (let "leb128_sz_1269" (make-vec (cardinality (get-alt "Vector" (get-field "text" (param 0)))))
                            (let "leb128_ptr_1270" (make-vec (identifier "ssum_dst_1166"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_1270")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_1270"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_1269"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1269"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1269"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_1269") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_1269")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_1269")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_1270"))))))
                        (let "n_ref_1272" (make-vec (i32 0))
                          (seq
                            (for-each "x_1273" (get-alt "Vector" (get-field "text" (param 0)))
                              (seq (set-vec (u8 0) (identifier "dst_ref_1271") (apply (myself "Ptr") (identifier "x_1273") (unsafe-nth (u8 0) (identifier "dst_ref_1271"))))
                                (set-vec (u8 0) (identifier "n_ref_1272") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_1272")))))) 
                            (unsafe-nth (u8 0) (identifier "dst_ref_1271")))))
                      (if (eq (u16 3) (identifier "label1_1165"))
                        (let "stup_dst_1268"
                          (let "dst_ref_1263"
                            (make-vec
                              (let "leb128_sz_1261" (make-vec (cardinality (get-item 0 (get-alt "Case" (get-field "text" (param 0))))))
                                (let "leb128_ptr_1262" (make-vec (identifier "ssum_dst_1166"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_1262")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_1262"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_1261"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1261"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1261"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_1261") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_1261")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_1261")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_1262"))))))
                            (let "n_ref_1264" (make-vec (i32 0))
                              (seq
                                (for-each "x_1265" (get-item 0 (get-alt "Case" (get-field "text" (param 0))))
                                  (seq
                                    (set-vec (u8 0) (identifier "dst_ref_1263")
                                      (apply (myself "Ptr") (get-field "case_cons" (identifier "x_1265")) (apply (myself "Ptr") (get-field "case_cond" (identifier "x_1265")) (unsafe-nth (u8 0) (identifier "dst_ref_1263")))))
                                    (set-vec (u8 0) (identifier "n_ref_1264") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_1264")))))) 
                                (unsafe-nth (u8 0) (identifier "dst_ref_1263")))))
                          (if (is-null (get-item 1 (get-alt "Case" (get-field "text" (param 0))))) 
                            (write-u8 (identifier "stup_dst_1268") (u8 1)) 
                            (apply (myself "Ptr") (force (get-item 1 (get-alt "Case" (get-field "text" (param 0))))) (write-u8 (identifier "stup_dst_1268") (u8 0)))))
                        (if (eq (u16 4) (identifier "label1_1165"))
                          (let "label1_1227" (label-of (get-alt "Stateless" (get-field "text" (param 0))))
                            (let "ssum_dst_1228" (write-u16 little-endian (identifier "ssum_dst_1166") (identifier "label1_1227"))
                              (if (eq (u16 0) (identifier "label1_1227"))
                                (let "label1_1254" (label-of (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0)))))
                                  (let "ssum_dst_1255" (write-u16 little-endian (identifier "ssum_dst_1228") (identifier "label1_1254"))
                                    (if (eq (u16 0) (identifier "label1_1254"))
                                      (apply (ext-identifier raql_value to-row-binary) (get-alt "Const" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0))))) (identifier "ssum_dst_1255"))
                                      (if (eq (u16 1) (identifier "label1_1254"))
                                        (apply (ext-identifier raql_variable to-row-binary) (get-alt "Variable" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0))))) (identifier "ssum_dst_1255"))
                                        (if (eq (u16 2) (identifier "label1_1254"))
                                          (apply (ext-identifier raql_binding_key to-row-binary) (get-alt "Binding" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0))))) (identifier "ssum_dst_1255"))
                                          (if (eq (u16 3) (identifier "label1_1254")) 
                                            (identifier "ssum_dst_1255")
                                            (if (eq (u16 4) (identifier "label1_1254")) 
                                              (identifier "ssum_dst_1255")
                                              (if (eq (u16 5) (identifier "label1_1254")) 
                                                (identifier "ssum_dst_1255")
                                                (if (eq (u16 6) (identifier "label1_1254")) 
                                                  (identifier "ssum_dst_1255")
                                                  (if (eq (u16 7) (identifier "label1_1254"))
                                                    (let "dst_ref_1258"
                                                      (make-vec
                                                        (let "leb128_sz_1256" 
                                                          (make-vec (cardinality (get-alt "Path" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                                          (let "leb128_ptr_1257" 
                                                            (make-vec (identifier "ssum_dst_1255"))
                                                            (seq
                                                              (while
                                                                (seq
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_1257")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_1257"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_1256"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1256"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1256"))) (u8 128)))))
                                                                  (set-vec (u8 0) (identifier "leb128_sz_1256") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_1256")) (u8 7)))
                                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_1256")) (u32 0))) 
                                                                (nop)) 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_1257"))))))
                                                      (let "n_ref_1259" 
                                                        (make-vec (i32 0))
                                                        (seq
                                                          (for-each "x_1260" 
                                                            (get-alt "Path" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0)))))
                                                            (seq
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "dst_ref_1258") 
                                                                (apply (ext-identifier raql_path_comp to-row-binary) (identifier "x_1260") (unsafe-nth (u8 0) (identifier "dst_ref_1258"))))
                                                              (set-vec (u8 0) (identifier "n_ref_1259") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_1259")))))) 
                                                          (unsafe-nth (u8 0) (identifier "dst_ref_1258"))))) 
                                                    (seq (assert (eq (identifier "label1_1254") (u16 8))) (identifier "ssum_dst_1255"))))))))))))
                                (if (eq (u16 1) (identifier "label1_1227"))
                                  (apply (myself "Ptr") (get-item 1 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0)))))
                                    (let "label1_1246" (label-of (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))
                                      (let "ssum_dst_1247" (write-u16 little-endian (identifier "ssum_dst_1228") (identifier "label1_1246"))
                                        (if (eq (u16 0) (identifier "label1_1246")) 
                                          (identifier "ssum_dst_1247")
                                          (if (eq (u16 1) (identifier "label1_1246"))
                                            (apply (ext-identifier raql_type to-row-binary) (get-alt "Cast" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0)))))) (identifier "ssum_dst_1247"))
                                            (if (eq (u16 2) (identifier "label1_1246")) 
                                              (identifier "ssum_dst_1247")
                                              (if (eq (u16 3) (identifier "label1_1246"))
                                                (let "stup_dst_1250"
                                                  (apply (ext-identifier raql_type to-row-binary) 
                                                    (get-item 0 (get-alt "Peek" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))) 
                                                    (identifier "ssum_dst_1247"))
                                                  (let "ssum_dst_1252"
                                                    (write-u16 little-endian (identifier "stup_dst_1250") (label-of (get-item 1 (get-alt "Peek" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0)))))))))
                                                    (if (eq (u16 0) (label-of (get-item 1 (get-alt "Peek" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))))) 
                                                      (identifier "ssum_dst_1252")
                                                      (seq (assert (eq (label-of (get-item 1 (get-alt "Peek" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0)))))))) (u16 1)))
                                                        (identifier "ssum_dst_1252")))))
                                                (if (eq (u16 4) (identifier "label1_1246")) 
                                                  (identifier "ssum_dst_1247")
                                                  (if (eq (u16 5) (identifier "label1_1246")) 
                                                    (identifier "ssum_dst_1247")
                                                    (if (eq (u16 6) (identifier "label1_1246")) 
                                                      (identifier "ssum_dst_1247")
                                                      (if (eq (u16 7) (identifier "label1_1246")) 
                                                        (identifier "ssum_dst_1247")
                                                        (if (eq (u16 8) (identifier "label1_1246")) 
                                                          (identifier "ssum_dst_1247")
                                                          (if (eq (u16 9) (identifier "label1_1246")) 
                                                            (identifier "ssum_dst_1247")
                                                            (if (eq (u16 10) (identifier "label1_1246")) 
                                                              (identifier "ssum_dst_1247")
                                                              (if (eq (u16 11) (identifier "label1_1246")) 
                                                                (identifier "ssum_dst_1247")
                                                                (if (eq (u16 12) (identifier "label1_1246")) 
                                                                  (identifier "ssum_dst_1247")
                                                                  (if 
                                                                    (eq (u16 13) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 14) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 15) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 16) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 17) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 18) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 19) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 20) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 21) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 22) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 23) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 24) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 25) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 26) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 27) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 28) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 35) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 36) (identifier "label1_1246"))
                                                                    (write-bytes
                                                                    (let "leb128_sz_1248" 
                                                                    (make-vec (string-length (get-alt "Like" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))))
                                                                    (let "leb128_ptr_1249" 
                                                                    (make-vec (identifier "ssum_dst_1247"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_1249")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_1249"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_1248"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1248"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1248"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_1248") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_1248")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_1248")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_1249")))))
                                                                    (bytes-of-string (get-alt "Like" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))))
                                                                    (if 
                                                                    (eq (u16 37) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if 
                                                                    (eq (u16 38) (identifier "label1_1246")) 
                                                                    (identifier "ssum_dst_1247")
                                                                    (if (eq (u16 39) (identifier "label1_1246")) (identifier "ssum_dst_1247") (seq (assert (eq (identifier "label1_1246") (u16 40))) (identifier "ssum_dst_1247")))))))))))))))))))))))))))))))))))))))))))))
                                  (if (eq (u16 2) (identifier "label1_1227"))
                                    (let "stup_dst_1240"
                                      (let "label1_1238" (label-of (get-item 0 (get-alt "SL1s" (get-alt "Stateless" (get-field "text" (param 0))))))
                                        (let "ssum_dst_1239" (write-u16 little-endian (identifier "ssum_dst_1228") (identifier "label1_1238"))
                                          (if (eq (u16 0) (identifier "label1_1238")) 
                                            (identifier "ssum_dst_1239")
                                            (if (eq (u16 1) (identifier "label1_1238")) 
                                              (identifier "ssum_dst_1239")
                                              (if (eq (u16 2) (identifier "label1_1238")) (identifier "ssum_dst_1239") (seq (assert (eq (identifier "label1_1238") (u16 3))) (identifier "ssum_dst_1239")))))))
                                      (let "dst_ref_1243"
                                        (make-vec
                                          (let "leb128_sz_1241" (make-vec (cardinality (get-item 1 (get-alt "SL1s" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                            (let "leb128_ptr_1242" (make-vec (identifier "stup_dst_1240"))
                                              (seq
                                                (while
                                                  (seq
                                                    (set-vec (u8 0) (identifier "leb128_ptr_1242")
                                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_1242"))
                                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_1241"))) 
                                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1241"))) 
                                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1241"))) (u8 128)))))
                                                    (set-vec (u8 0) (identifier "leb128_sz_1241") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_1241")) (u8 7)))
                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_1241")) (u32 0))) 
                                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_1242"))))))
                                        (let "n_ref_1244" (make-vec (i32 0))
                                          (seq
                                            (for-each "x_1245" (get-item 1 (get-alt "SL1s" (get-alt "Stateless" (get-field "text" (param 0)))))
                                              (seq (set-vec (u8 0) (identifier "dst_ref_1243") (apply (myself "Ptr") (identifier "x_1245") (unsafe-nth (u8 0) (identifier "dst_ref_1243"))))
                                                (set-vec (u8 0) (identifier "n_ref_1244") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_1244")))))) 
                                            (unsafe-nth (u8 0) (identifier "dst_ref_1243"))))))
                                    (if (eq (u16 3) (identifier "label1_1227"))
                                      (apply (myself "Ptr") (get-item 2 (get-alt "SL2" (get-alt "Stateless" (get-field "text" (param 0)))))
                                        (apply (myself "Ptr") (get-item 1 (get-alt "SL2" (get-alt "Stateless" (get-field "text" (param 0)))))
                                          (let "label1_1234" (label-of (get-item 0 (get-alt "SL2" (get-alt "Stateless" (get-field "text" (param 0))))))
                                            (let "ssum_dst_1235" (write-u16 little-endian (identifier "ssum_dst_1228") (identifier "label1_1234"))
                                              (if (eq (u16 0) (identifier "label1_1234")) 
                                                (identifier "ssum_dst_1235")
                                                (if (eq (u16 1) (identifier "label1_1234")) 
                                                  (identifier "ssum_dst_1235")
                                                  (if (eq (u16 2) (identifier "label1_1234")) 
                                                    (identifier "ssum_dst_1235")
                                                    (if (eq (u16 3) (identifier "label1_1234")) 
                                                      (identifier "ssum_dst_1235")
                                                      (if (eq (u16 4) (identifier "label1_1234")) 
                                                        (identifier "ssum_dst_1235")
                                                        (if (eq (u16 5) (identifier "label1_1234")) 
                                                          (identifier "ssum_dst_1235")
                                                          (if (eq (u16 6) (identifier "label1_1234")) 
                                                            (identifier "ssum_dst_1235")
                                                            (if (eq (u16 7) (identifier "label1_1234")) 
                                                              (identifier "ssum_dst_1235")
                                                              (if (eq (u16 8) (identifier "label1_1234")) 
                                                                (identifier "ssum_dst_1235")
                                                                (if (eq (u16 9) (identifier "label1_1234")) 
                                                                  (identifier "ssum_dst_1235")
                                                                  (if 
                                                                    (eq (u16 10) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 11) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 12) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 13) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 14) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 15) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 16) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 17) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 18) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 19) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 20) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 21) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 22) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if 
                                                                    (eq (u16 23) (identifier "label1_1234")) 
                                                                    (identifier "ssum_dst_1235")
                                                                    (if (eq (u16 24) (identifier "label1_1234")) (identifier "ssum_dst_1235") (seq (assert (eq (identifier "label1_1234") (u16 25))) (identifier "ssum_dst_1235")))))))))))))))))))))))))))))))
                                      (seq (assert (eq (identifier "label1_1227") (u16 4)))
                                        (apply (myself "Ptr") (get-item 3 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0)))))
                                          (apply (myself "Ptr") (get-item 2 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0)))))
                                            (apply (myself "Ptr") (get-item 1 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0)))))
                                              (let "ssum_dst_1230" (write-u16 little-endian (identifier "ssum_dst_1228") (label-of (get-item 0 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                                (if (eq (u16 0) (label-of (get-item 0 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0))))))) 
                                                  (identifier "ssum_dst_1230") 
                                                  (seq (assert (eq (label-of (get-item 0 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0)))))) (u16 1))) (identifier "ssum_dst_1230"))))))))))))))
                          (if (eq (u16 5) (identifier "label1_1165"))
                            (let "stup_dst_1173"
                              (let "stup_dst_1172"
                                (let "ssum_dst_1171" (write-u16 little-endian (identifier "ssum_dst_1166") (label-of (get-item 0 (get-alt "Stateful" (get-field "text" (param 0))))))
                                  (if (eq (u16 0) (label-of (get-item 0 (get-alt "Stateful" (get-field "text" (param 0)))))) 
                                    (identifier "ssum_dst_1171") (seq (assert (eq (label-of (get-item 0 (get-alt "Stateful" (get-field "text" (param 0))))) (u16 1))) (identifier "ssum_dst_1171"))))
                                (write-u8 (identifier "stup_dst_1172") (u8-of-bool (get-item 1 (get-alt "Stateful" (get-field "text" (param 0)))))))
                              (let "label1_1174" (label-of (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))
                                (let "ssum_dst_1175" (write-u16 little-endian (identifier "stup_dst_1173") (identifier "label1_1174"))
                                  (if (eq (u16 0) (identifier "label1_1174"))
                                    (apply (myself "Ptr") (get-item 1 (get-alt "SF1" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                      (let "label1_1222" (label-of (get-item 0 (get-alt "SF1" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))
                                        (let "ssum_dst_1223" (write-u16 little-endian (identifier "ssum_dst_1175") (identifier "label1_1222"))
                                          (if (eq (u16 0) (identifier "label1_1222")) 
                                            (identifier "ssum_dst_1223")
                                            (if (eq (u16 1) (identifier "label1_1222")) 
                                              (identifier "ssum_dst_1223")
                                              (if (eq (u16 2) (identifier "label1_1222")) 
                                                (identifier "ssum_dst_1223")
                                                (if (eq (u16 3) (identifier "label1_1222")) 
                                                  (identifier "ssum_dst_1223")
                                                  (if (eq (u16 4) (identifier "label1_1222")) 
                                                    (identifier "ssum_dst_1223")
                                                    (if (eq (u16 5) (identifier "label1_1222")) 
                                                      (identifier "ssum_dst_1223")
                                                      (if (eq (u16 6) (identifier "label1_1222")) 
                                                        (identifier "ssum_dst_1223")
                                                        (if (eq (u16 7) (identifier "label1_1222")) 
                                                          (identifier "ssum_dst_1223")
                                                          (if (eq (u16 8) (identifier "label1_1222")) 
                                                            (identifier "ssum_dst_1223")
                                                            (if (eq (u16 9) (identifier "label1_1222")) 
                                                              (identifier "ssum_dst_1223")
                                                              (if (eq (u16 10) (identifier "label1_1222")) 
                                                                (identifier "ssum_dst_1223")
                                                                (if (eq (u16 11) (identifier "label1_1222"))
                                                                  (let "stup_dst_1225"
                                                                    (let "stup_dst_1224"
                                                                    (write-u64 little-endian 
                                                                    (identifier "ssum_dst_1223")
                                                                    (u64-of-float (get-item 0 (get-alt "AggrHistogram" (get-item 0 (get-alt "SF1" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))))
                                                                    (write-u64 little-endian 
                                                                    (identifier "stup_dst_1224")
                                                                    (u64-of-float (get-item 1 (get-alt "AggrHistogram" (get-item 0 (get-alt "SF1" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))))))
                                                                    (write-u32 little-endian 
                                                                    (identifier "stup_dst_1225") 
                                                                    (get-item 2 (get-alt "AggrHistogram" (get-item 0 (get-alt "SF1" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))))
                                                                  (if 
                                                                    (eq (u16 12) (identifier "label1_1222")) 
                                                                    (identifier "ssum_dst_1223")
                                                                    (if (eq (u16 13) (identifier "label1_1222")) (identifier "ssum_dst_1223") (seq (assert (eq (identifier "label1_1222") (u16 14))) (identifier "ssum_dst_1223")))))))))))))))))))
                                    (if (eq (u16 1) (identifier "label1_1174"))
                                      (apply (myself "Ptr") (get-item 2 (get-alt "SF2" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                        (apply (myself "Ptr") (get-item 1 (get-alt "SF2" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                          (let "label1_1218" (label-of (get-item 0 (get-alt "SF2" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))
                                            (let "ssum_dst_1219" (write-u16 little-endian (identifier "ssum_dst_1175") (identifier "label1_1218"))
                                              (if (eq (u16 0) (identifier "label1_1218")) 
                                                (identifier "ssum_dst_1219")
                                                (if (eq (u16 1) (identifier "label1_1218")) 
                                                  (identifier "ssum_dst_1219")
                                                  (if (eq (u16 2) (identifier "label1_1218")) (identifier "ssum_dst_1219") (seq (assert (eq (identifier "label1_1218") (u16 3))) (identifier "ssum_dst_1219")))))))))
                                      (if (eq (u16 2) (identifier "label1_1174"))
                                        (apply (myself "Ptr") (get-item 3 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                          (apply (myself "Ptr") (get-item 2 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                            (apply (myself "Ptr") (get-item 1 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                              (let "label1_1213" (label-of (get-item 0 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))
                                                (let "ssum_dst_1214" 
                                                  (write-u16 little-endian (identifier "ssum_dst_1175") (identifier "label1_1213"))
                                                  (if (eq (u16 0) (identifier "label1_1213")) 
                                                    (identifier "ssum_dst_1214")
                                                    (if (eq (u16 1) (identifier "label1_1213")) 
                                                      (identifier "ssum_dst_1214")
                                                      (seq (assert (eq (identifier "label1_1213") (u16 2)))
                                                        (write-u8 (identifier "ssum_dst_1214") (u8-of-bool (get-alt "OnceEvery" (get-item 0 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))))))))))))
                                        (if (eq (u16 3) (identifier "label1_1174"))
                                          (apply (myself "Ptr") (get-item 4 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                            (apply (myself "Ptr") (get-item 3 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                              (apply (myself "Ptr") (get-item 2 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                (apply (myself "Ptr") 
                                                  (get-item 1 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                  (let "ssum_dst_1208" 
                                                    (write-u16 little-endian (identifier "ssum_dst_1175") (label-of (get-item 0 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                    (if (eq (u16 0) (label-of (get-item 0 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))) 
                                                      (identifier "ssum_dst_1208")
                                                      (seq (assert (eq (label-of (get-item 0 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) (u16 1)))
                                                        (write-u8 (identifier "ssum_dst_1208") (u8-of-bool (get-alt "Remember" (get-item 0 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))))))))))
                                          (if (eq (u16 4) (identifier "label1_1174"))
                                            (let "stup_dst_1201"
                                              (apply (myself "Ptr") (get-item 3 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                (apply (myself "Ptr") 
                                                  (get-item 2 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                  (apply (myself "Ptr") 
                                                    (get-item 1 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                    (let "ssum_dst_1196"
                                                      (write-u16 little-endian (identifier "ssum_dst_1175") (label-of (get-item 0 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                      (if (eq (u16 0) (label-of (get-item 0 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))) 
                                                        (identifier "ssum_dst_1196")
                                                        (seq (assert (eq (label-of (get-item 0 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) (u16 1)))
                                                          (let "srec_dst_1197"
                                                            (write-u8 
                                                              (identifier "ssum_dst_1196")
                                                              (u8-of-bool (get-field "inv" (get-alt "Largest" (get-item 0 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))))
                                                            (write-u8 
                                                              (identifier "srec_dst_1197")
                                                              (u8-of-bool (get-field "up_to" (get-alt "Largest" (get-item 0 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))))))))))))
                                              (let "dst_ref_1204"
                                                (make-vec
                                                  (let "leb128_sz_1202" 
                                                    (make-vec (cardinality (get-item 4 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                    (let "leb128_ptr_1203" 
                                                      (make-vec (identifier "stup_dst_1201"))
                                                      (seq
                                                        (while
                                                          (seq
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb128_ptr_1203")
                                                              (write-u8 
                                                                (unsafe-nth (u8 0) (identifier "leb128_ptr_1203"))
                                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_1202"))) 
                                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1202"))) 
                                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_1202"))) (u8 128)))))
                                                            (set-vec (u8 0) (identifier "leb128_sz_1202") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_1202")) (u8 7)))
                                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_1202")) (u32 0))) 
                                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_1203"))))))
                                                (let "n_ref_1205" (make-vec (i32 0))
                                                  (seq
                                                    (for-each "x_1206" 
                                                      (get-item 4 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                      (seq (set-vec (u8 0) (identifier "dst_ref_1204") (apply (myself "Ptr") (identifier "x_1206") (unsafe-nth (u8 0) (identifier "dst_ref_1204"))))
                                                        (set-vec (u8 0) (identifier "n_ref_1205") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_1205")))))) 
                                                    (unsafe-nth (u8 0) (identifier "dst_ref_1204"))))))
                                            (if (eq (u16 5) (identifier "label1_1174"))
                                              (apply (myself "Ptr") (get-item 6 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                (apply (myself "Ptr") 
                                                  (get-item 5 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                  (apply (myself "Ptr") 
                                                    (get-item 4 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                    (apply (myself "Ptr") 
                                                      (get-item 3 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                      (apply (myself "Ptr") 
                                                        (get-item 2 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                        (apply (myself "Ptr") 
                                                          (get-item 1 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                          (let "ssum_dst_1188"
                                                            (write-u16 little-endian (identifier "ssum_dst_1175") (label-of (get-item 0 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                            (seq (assert (eq (label-of (get-item 0 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) (u16 0))) (identifier "ssum_dst_1188")))))))))
                                              (if (eq (u16 6) (identifier "label1_1174"))
                                                (apply (myself "Ptr") 
                                                  (get-field "sigmas" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                  (apply (myself "Ptr") 
                                                    (get-field "duration" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                    (apply (myself "Ptr") 
                                                      (get-field "time" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                      (apply (myself "Ptr") 
                                                        (get-field "by" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                        (apply (myself "Ptr") 
                                                          (get-field "what" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                          (let "srec_dst_1181"
                                                            (apply (myself "Ptr") 
                                                              (get-field "size" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                              (apply 
                                                                (ext-identifier raql_top_output to-row-binary) 
                                                                (get-field "output" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))) 
                                                                (identifier "ssum_dst_1175")))
                                                            (if (is-null (get-field "max_size" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) 
                                                              (write-u8 (identifier "srec_dst_1181") (u8 1))
                                                              (apply 
                                                                (myself "Ptr") 
                                                                (force (get-field "max_size" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) 
                                                                (write-u8 (identifier "srec_dst_1181") (u8 0))))))))))
                                                (seq (assert (eq (identifier "label1_1174") (u16 7)))
                                                  (let "srec_dst_1179"
                                                    (write-u8
                                                      (apply (myself "Ptr") 
                                                        (get-field "max_age" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                        (apply (myself "Ptr") 
                                                          (get-field "time" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))
                                                          (apply (myself "Ptr") (get-field "what" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))) (identifier "ssum_dst_1175"))))
                                                      (u8-of-bool (get-field "tumbling" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                    (if (is-null (get-field "sample_size" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) 
                                                      (write-u8 (identifier "srec_dst_1179") (u8 1))
                                                      (apply (myself "Ptr") 
                                                        (force (get-field "sample_size" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) 
                                                        (write-u8 (identifier "srec_dst_1179") (u8 0))))))))))))))))
                            (seq (assert (eq (identifier "label1_1165") (u16 6)))
                              (let "ssum_dst_1168" (write-u16 little-endian (identifier "ssum_dst_1166") (label-of (get-alt "Generator" (get-field "text" (param 0)))))
                                (seq (assert (eq (label-of (get-alt "Generator" (get-field "text" (param 0)))) (u16 0)))
                                  (apply (myself "Ptr") (get-item 1 (get-alt "Split" (get-alt "Generator" (get-field "text" (param 0)))))
                                    (apply (myself "Ptr") (get-item 0 (get-alt "Split" (get-alt "Generator" (get-field "text" (param 0))))) (identifier "ssum_dst_1168"))))))))))))))
            (write-u32 little-endian (identifier "srec_dst_1286") (get-field "uniq_num" (param 0)))) 
          (apply (ext-identifier raql_type to-row-binary) (get-field "typ" (param 0)) (identifier "srec_dst_1287")))
        (if (is-null (get-field "units" (param 0))) (write-u8 (identifier "srec_dst_1288") (u8 1)) (apply (ext-identifier units to-row-binary) (force (get-field "units" (param 0))) (write-u8 (identifier "srec_dst_1288") (u8 0))))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    dc31f5cc689133a6f12d16478388e785 id_1 { p_0.text };
    uint16_t id_2 { uint16_t(id_1.index()) };
    Pointer let_res_3;
    {
      uint16_t label1_1165 { id_2 };
      Pointer id_4 { p_1.writeU16Le(label1_1165) };
      Pointer let_res_5;
      {
        Pointer ssum_dst_1166 { id_4 };
        uint16_t id_6 { 0 };
        bool id_7 { bool(id_6 == label1_1165) };
        Pointer choose_res_8;
        if (id_7) {
          dc31f5cc689133a6f12d16478388e785 id_9 { p_0.text };
          Lst<t*> id_10 { std::get<0>(id_9) };
          uint32_t id_11 { id_10.size() };
          Vec<1, uint32_t> id_12 {  id_11  };
          Pointer let_res_13;
          {
            Vec<1, uint32_t> leb128_sz_1281 { id_12 };
            Vec<1, Pointer> id_14 {  ssum_dst_1166  };
            Pointer let_res_15;
            {
              Vec<1, Pointer> leb128_ptr_1282 { id_14 };
              bool while_flag_16 { true };
              do {
                uint8_t id_17 { 0 };
                uint8_t id_18 { 0 };
                Pointer id_19 { leb128_ptr_1282[id_18] };
                uint32_t id_20 { 128U };
                uint8_t id_21 { 0 };
                uint32_t id_22 { leb128_sz_1281[id_21] };
                bool id_23 { bool(id_20 > id_22) };
                uint8_t choose_res_24;
                if (id_23) {
                  uint8_t id_25 { 0 };
                  uint32_t id_26 { leb128_sz_1281[id_25] };
                  uint8_t id_27 { uint8_t(id_26) };
                  choose_res_24 = id_27;
                } else {
                  uint8_t id_28 { 0 };
                  uint32_t id_29 { leb128_sz_1281[id_28] };
                  uint8_t id_30 { uint8_t(id_29) };
                  uint8_t id_31 { 128 };
                  uint8_t id_32 { uint8_t(id_30 | id_31) };
                  choose_res_24 = id_32;
                }
                Pointer id_33 { id_19.writeU8(choose_res_24) };
                Void id_34 { ((void)(leb128_ptr_1282[id_17] = id_33), VOID) };
                uint8_t id_35 { 0 };
                uint8_t id_36 { 0 };
                uint32_t id_37 { leb128_sz_1281[id_36] };
                uint8_t id_38 { 7 };
                uint32_t id_39 { uint32_t(id_37 >> id_38) };
                Void id_40 { ((void)(leb128_sz_1281[id_35] = id_39), VOID) };
                uint8_t id_41 { 0 };
                uint32_t id_42 { leb128_sz_1281[id_41] };
                uint32_t id_43 { 0U };
                bool id_44 { bool(id_42 > id_43) };
                while_flag_16 = id_44;
                if (while_flag_16) {
                }
              } while (while_flag_16);
              uint8_t id_45 { 0 };
              Pointer id_46 { leb128_ptr_1282[id_45] };
              let_res_15 = id_46;
            }
            let_res_13 = let_res_15;
          }
          Vec<1, Pointer> id_47 {  let_res_13  };
          Pointer let_res_48;
          {
            Vec<1, Pointer> dst_ref_1283 { id_47 };
            int32_t id_49 { 0L };
            Vec<1, int32_t> id_50 {  id_49  };
            Pointer let_res_51;
            {
              Vec<1, int32_t> n_ref_1284 { id_50 };
              dc31f5cc689133a6f12d16478388e785 id_52 { p_0.text };
              Lst<t*> id_53 { std::get<0>(id_52) };
              for (t* x_1285 : id_53) {
                uint8_t id_54 { 0 };
                uint8_t id_55 { 0 };
                Pointer id_56 { dst_ref_1283[id_55] };
                Pointer id_57 { fun0(x_1285, id_56) };
                Void id_58 { ((void)(dst_ref_1283[id_54] = id_57), VOID) };
                uint8_t id_59 { 0 };
                int32_t id_60 { 1L };
                uint8_t id_61 { 0 };
                int32_t id_62 { n_ref_1284[id_61] };
                int32_t id_63 { int32_t(id_60 + id_62) };
                Void id_64 { ((void)(n_ref_1284[id_59] = id_63), VOID) };
              }
              uint8_t id_65 { 0 };
              Pointer id_66 { dst_ref_1283[id_65] };
              let_res_51 = id_66;
            }
            let_res_48 = let_res_51;
          }
          choose_res_8 = let_res_48;
        } else {
          uint16_t id_67 { 1 };
          bool id_68 { bool(id_67 == label1_1165) };
          Pointer choose_res_69;
          if (id_68) {
            dc31f5cc689133a6f12d16478388e785 id_70 { p_0.text };
            Lst<v_4ec9e9432e07cae1458c03426a194a1a> id_71 { std::get<1>(id_70) };
            uint32_t id_72 { id_71.size() };
            Vec<1, uint32_t> id_73 {  id_72  };
            Pointer let_res_74;
            {
              Vec<1, uint32_t> leb128_sz_1274 { id_73 };
              Vec<1, Pointer> id_75 {  ssum_dst_1166  };
              Pointer let_res_76;
              {
                Vec<1, Pointer> leb128_ptr_1275 { id_75 };
                bool while_flag_77 { true };
                do {
                  uint8_t id_78 { 0 };
                  uint8_t id_79 { 0 };
                  Pointer id_80 { leb128_ptr_1275[id_79] };
                  uint32_t id_81 { 128U };
                  uint8_t id_82 { 0 };
                  uint32_t id_83 { leb128_sz_1274[id_82] };
                  bool id_84 { bool(id_81 > id_83) };
                  uint8_t choose_res_85;
                  if (id_84) {
                    uint8_t id_86 { 0 };
                    uint32_t id_87 { leb128_sz_1274[id_86] };
                    uint8_t id_88 { uint8_t(id_87) };
                    choose_res_85 = id_88;
                  } else {
                    uint8_t id_89 { 0 };
                    uint32_t id_90 { leb128_sz_1274[id_89] };
                    uint8_t id_91 { uint8_t(id_90) };
                    uint8_t id_92 { 128 };
                    uint8_t id_93 { uint8_t(id_91 | id_92) };
                    choose_res_85 = id_93;
                  }
                  Pointer id_94 { id_80.writeU8(choose_res_85) };
                  Void id_95 { ((void)(leb128_ptr_1275[id_78] = id_94), VOID) };
                  uint8_t id_96 { 0 };
                  uint8_t id_97 { 0 };
                  uint32_t id_98 { leb128_sz_1274[id_97] };
                  uint8_t id_99 { 7 };
                  uint32_t id_100 { uint32_t(id_98 >> id_99) };
                  Void id_101 { ((void)(leb128_sz_1274[id_96] = id_100), VOID) };
                  uint8_t id_102 { 0 };
                  uint32_t id_103 { leb128_sz_1274[id_102] };
                  uint32_t id_104 { 0U };
                  bool id_105 { bool(id_103 > id_104) };
                  while_flag_77 = id_105;
                  if (while_flag_77) {
                  }
                } while (while_flag_77);
                uint8_t id_106 { 0 };
                Pointer id_107 { leb128_ptr_1275[id_106] };
                let_res_76 = id_107;
              }
              let_res_74 = let_res_76;
            }
            Vec<1, Pointer> id_108 {  let_res_74  };
            Pointer let_res_109;
            {
              Vec<1, Pointer> dst_ref_1276 { id_108 };
              int32_t id_110 { 0L };
              Vec<1, int32_t> id_111 {  id_110  };
              Pointer let_res_112;
              {
                Vec<1, int32_t> n_ref_1277 { id_111 };
                dc31f5cc689133a6f12d16478388e785 id_113 { p_0.text };
                Lst<v_4ec9e9432e07cae1458c03426a194a1a> id_114 { std::get<1>(id_113) };
                for (v_4ec9e9432e07cae1458c03426a194a1a x_1278 : id_114) {
                  uint8_t id_115 { 0 };
                  t* id_116 { std::get<1>(x_1278) };
                  uint8_t id_117 { 0 };
                  Pointer id_118 { dst_ref_1276[id_117] };
                  Pointer let_res_119;
                  {
                    Pointer stup_dst_1279 { id_118 };
                    std::function<Pointer(dessser::gen::field_name::t,Pointer)> id_120 { dessser::gen::field_name::to_row_binary };
                    dessser::gen::field_name::t id_121 { std::get<0>(x_1278) };
                    Pointer id_122 { id_120(id_121, stup_dst_1279) };
                    let_res_119 = id_122;
                  }
                  Pointer id_123 { fun0(id_116, let_res_119) };
                  Void id_124 { ((void)(dst_ref_1276[id_115] = id_123), VOID) };
                  uint8_t id_125 { 0 };
                  int32_t id_126 { 1L };
                  uint8_t id_127 { 0 };
                  int32_t id_128 { n_ref_1277[id_127] };
                  int32_t id_129 { int32_t(id_126 + id_128) };
                  Void id_130 { ((void)(n_ref_1277[id_125] = id_129), VOID) };
                }
                uint8_t id_131 { 0 };
                Pointer id_132 { dst_ref_1276[id_131] };
                let_res_112 = id_132;
              }
              let_res_109 = let_res_112;
            }
            choose_res_69 = let_res_109;
          } else {
            uint16_t id_133 { 2 };
            bool id_134 { bool(id_133 == label1_1165) };
            Pointer choose_res_135;
            if (id_134) {
              dc31f5cc689133a6f12d16478388e785 id_136 { p_0.text };
              Lst<t*> id_137 { std::get<2>(id_136) };
              uint32_t id_138 { id_137.size() };
              Vec<1, uint32_t> id_139 {  id_138  };
              Pointer let_res_140;
              {
                Vec<1, uint32_t> leb128_sz_1269 { id_139 };
                Vec<1, Pointer> id_141 {  ssum_dst_1166  };
                Pointer let_res_142;
                {
                  Vec<1, Pointer> leb128_ptr_1270 { id_141 };
                  bool while_flag_143 { true };
                  do {
                    uint8_t id_144 { 0 };
                    uint8_t id_145 { 0 };
                    Pointer id_146 { leb128_ptr_1270[id_145] };
                    uint32_t id_147 { 128U };
                    uint8_t id_148 { 0 };
                    uint32_t id_149 { leb128_sz_1269[id_148] };
                    bool id_150 { bool(id_147 > id_149) };
                    uint8_t choose_res_151;
                    if (id_150) {
                      uint8_t id_152 { 0 };
                      uint32_t id_153 { leb128_sz_1269[id_152] };
                      uint8_t id_154 { uint8_t(id_153) };
                      choose_res_151 = id_154;
                    } else {
                      uint8_t id_155 { 0 };
                      uint32_t id_156 { leb128_sz_1269[id_155] };
                      uint8_t id_157 { uint8_t(id_156) };
                      uint8_t id_158 { 128 };
                      uint8_t id_159 { uint8_t(id_157 | id_158) };
                      choose_res_151 = id_159;
                    }
                    Pointer id_160 { id_146.writeU8(choose_res_151) };
                    Void id_161 { ((void)(leb128_ptr_1270[id_144] = id_160), VOID) };
                    uint8_t id_162 { 0 };
                    uint8_t id_163 { 0 };
                    uint32_t id_164 { leb128_sz_1269[id_163] };
                    uint8_t id_165 { 7 };
                    uint32_t id_166 { uint32_t(id_164 >> id_165) };
                    Void id_167 { ((void)(leb128_sz_1269[id_162] = id_166), VOID) };
                    uint8_t id_168 { 0 };
                    uint32_t id_169 { leb128_sz_1269[id_168] };
                    uint32_t id_170 { 0U };
                    bool id_171 { bool(id_169 > id_170) };
                    while_flag_143 = id_171;
                    if (while_flag_143) {
                    }
                  } while (while_flag_143);
                  uint8_t id_172 { 0 };
                  Pointer id_173 { leb128_ptr_1270[id_172] };
                  let_res_142 = id_173;
                }
                let_res_140 = let_res_142;
              }
              Vec<1, Pointer> id_174 {  let_res_140  };
              Pointer let_res_175;
              {
                Vec<1, Pointer> dst_ref_1271 { id_174 };
                int32_t id_176 { 0L };
                Vec<1, int32_t> id_177 {  id_176  };
                Pointer let_res_178;
                {
                  Vec<1, int32_t> n_ref_1272 { id_177 };
                  dc31f5cc689133a6f12d16478388e785 id_179 { p_0.text };
                  Lst<t*> id_180 { std::get<2>(id_179) };
                  for (t* x_1273 : id_180) {
                    uint8_t id_181 { 0 };
                    uint8_t id_182 { 0 };
                    Pointer id_183 { dst_ref_1271[id_182] };
                    Pointer id_184 { fun0(x_1273, id_183) };
                    Void id_185 { ((void)(dst_ref_1271[id_181] = id_184), VOID) };
                    uint8_t id_186 { 0 };
                    int32_t id_187 { 1L };
                    uint8_t id_188 { 0 };
                    int32_t id_189 { n_ref_1272[id_188] };
                    int32_t id_190 { int32_t(id_187 + id_189) };
                    Void id_191 { ((void)(n_ref_1272[id_186] = id_190), VOID) };
                  }
                  uint8_t id_192 { 0 };
                  Pointer id_193 { dst_ref_1271[id_192] };
                  let_res_178 = id_193;
                }
                let_res_175 = let_res_178;
              }
              choose_res_135 = let_res_175;
            } else {
              uint16_t id_194 { 3 };
              bool id_195 { bool(id_194 == label1_1165) };
              Pointer choose_res_196;
              if (id_195) {
                dc31f5cc689133a6f12d16478388e785 id_197 { p_0.text };
                v_7df1ef9c4e82bfdd017031822619493c id_198 { std::get<3>(id_197) };
                Lst<a1a2ab208d8a8e56a609f18e422bdf88> id_199 { std::get<0>(id_198) };
                uint32_t id_200 { id_199.size() };
                Vec<1, uint32_t> id_201 {  id_200  };
                Pointer let_res_202;
                {
                  Vec<1, uint32_t> leb128_sz_1261 { id_201 };
                  Vec<1, Pointer> id_203 {  ssum_dst_1166  };
                  Pointer let_res_204;
                  {
                    Vec<1, Pointer> leb128_ptr_1262 { id_203 };
                    bool while_flag_205 { true };
                    do {
                      uint8_t id_206 { 0 };
                      uint8_t id_207 { 0 };
                      Pointer id_208 { leb128_ptr_1262[id_207] };
                      uint32_t id_209 { 128U };
                      uint8_t id_210 { 0 };
                      uint32_t id_211 { leb128_sz_1261[id_210] };
                      bool id_212 { bool(id_209 > id_211) };
                      uint8_t choose_res_213;
                      if (id_212) {
                        uint8_t id_214 { 0 };
                        uint32_t id_215 { leb128_sz_1261[id_214] };
                        uint8_t id_216 { uint8_t(id_215) };
                        choose_res_213 = id_216;
                      } else {
                        uint8_t id_217 { 0 };
                        uint32_t id_218 { leb128_sz_1261[id_217] };
                        uint8_t id_219 { uint8_t(id_218) };
                        uint8_t id_220 { 128 };
                        uint8_t id_221 { uint8_t(id_219 | id_220) };
                        choose_res_213 = id_221;
                      }
                      Pointer id_222 { id_208.writeU8(choose_res_213) };
                      Void id_223 { ((void)(leb128_ptr_1262[id_206] = id_222), VOID) };
                      uint8_t id_224 { 0 };
                      uint8_t id_225 { 0 };
                      uint32_t id_226 { leb128_sz_1261[id_225] };
                      uint8_t id_227 { 7 };
                      uint32_t id_228 { uint32_t(id_226 >> id_227) };
                      Void id_229 { ((void)(leb128_sz_1261[id_224] = id_228), VOID) };
                      uint8_t id_230 { 0 };
                      uint32_t id_231 { leb128_sz_1261[id_230] };
                      uint32_t id_232 { 0U };
                      bool id_233 { bool(id_231 > id_232) };
                      while_flag_205 = id_233;
                      if (while_flag_205) {
                      }
                    } while (while_flag_205);
                    uint8_t id_234 { 0 };
                    Pointer id_235 { leb128_ptr_1262[id_234] };
                    let_res_204 = id_235;
                  }
                  let_res_202 = let_res_204;
                }
                Vec<1, Pointer> id_236 {  let_res_202  };
                Pointer let_res_237;
                {
                  Vec<1, Pointer> dst_ref_1263 { id_236 };
                  int32_t id_238 { 0L };
                  Vec<1, int32_t> id_239 {  id_238  };
                  Pointer let_res_240;
                  {
                    Vec<1, int32_t> n_ref_1264 { id_239 };
                    dc31f5cc689133a6f12d16478388e785 id_241 { p_0.text };
                    v_7df1ef9c4e82bfdd017031822619493c id_242 { std::get<3>(id_241) };
                    Lst<a1a2ab208d8a8e56a609f18e422bdf88> id_243 { std::get<0>(id_242) };
                    for (a1a2ab208d8a8e56a609f18e422bdf88 x_1265 : id_243) {
                      uint8_t id_244 { 0 };
                      t* id_245 { x_1265.case_cons };
                      t* id_246 { x_1265.case_cond };
                      uint8_t id_247 { 0 };
                      Pointer id_248 { dst_ref_1263[id_247] };
                      Pointer id_249 { fun0(id_246, id_248) };
                      Pointer id_250 { fun0(id_245, id_249) };
                      Void id_251 { ((void)(dst_ref_1263[id_244] = id_250), VOID) };
                      uint8_t id_252 { 0 };
                      int32_t id_253 { 1L };
                      uint8_t id_254 { 0 };
                      int32_t id_255 { n_ref_1264[id_254] };
                      int32_t id_256 { int32_t(id_253 + id_255) };
                      Void id_257 { ((void)(n_ref_1264[id_252] = id_256), VOID) };
                    }
                    uint8_t id_258 { 0 };
                    Pointer id_259 { dst_ref_1263[id_258] };
                    let_res_240 = id_259;
                  }
                  let_res_237 = let_res_240;
                }
                Pointer let_res_260;
                {
                  Pointer stup_dst_1268 { let_res_237 };
                  dc31f5cc689133a6f12d16478388e785 id_261 { p_0.text };
                  v_7df1ef9c4e82bfdd017031822619493c id_262 { std::get<3>(id_261) };
                  std::optional<t*> id_263 { std::get<1>(id_262) };
                  bool id_264 { !(id_263.has_value ()) };
                  Pointer choose_res_265;
                  if (id_264) {
                    uint8_t id_266 { 1 };
                    Pointer id_267 { stup_dst_1268.writeU8(id_266) };
                    choose_res_265 = id_267;
                  } else {
                    dc31f5cc689133a6f12d16478388e785 id_268 { p_0.text };
                    v_7df1ef9c4e82bfdd017031822619493c id_269 { std::get<3>(id_268) };
                    std::optional<t*> id_270 { std::get<1>(id_269) };
                    t* id_271 { id_270.value() };
                    uint8_t id_272 { 0 };
                    Pointer id_273 { stup_dst_1268.writeU8(id_272) };
                    Pointer id_274 { fun0(id_271, id_273) };
                    choose_res_265 = id_274;
                  }
                  let_res_260 = choose_res_265;
                }
                choose_res_196 = let_res_260;
              } else {
                uint16_t id_275 { 4 };
                bool id_276 { bool(id_275 == label1_1165) };
                Pointer choose_res_277;
                if (id_276) {
                  dc31f5cc689133a6f12d16478388e785 id_278 { p_0.text };
                  a481e1e269544fa0efe70fc68e01b3bb id_279 { std::get<4>(id_278) };
                  uint16_t id_280 { uint16_t(id_279.index()) };
                  Pointer let_res_281;
                  {
                    uint16_t label1_1227 { id_280 };
                    Pointer id_282 { ssum_dst_1166.writeU16Le(label1_1227) };
                    Pointer let_res_283;
                    {
                      Pointer ssum_dst_1228 { id_282 };
                      uint16_t id_284 { 0 };
                      bool id_285 { bool(id_284 == label1_1227) };
                      Pointer choose_res_286;
                      if (id_285) {
                        dc31f5cc689133a6f12d16478388e785 id_287 { p_0.text };
                        a481e1e269544fa0efe70fc68e01b3bb id_288 { std::get<4>(id_287) };
                        b02d571406bf80b296e55bb93213ea59 id_289 { std::get<0>(id_288) };
                        uint16_t id_290 { uint16_t(id_289.index()) };
                        Pointer let_res_291;
                        {
                          uint16_t label1_1254 { id_290 };
                          Pointer id_292 { ssum_dst_1228.writeU16Le(label1_1254) };
                          Pointer let_res_293;
                          {
                            Pointer ssum_dst_1255 { id_292 };
                            uint16_t id_294 { 0 };
                            bool id_295 { bool(id_294 == label1_1254) };
                            Pointer choose_res_296;
                            if (id_295) {
                              std::function<Pointer(dessser::gen::raql_value::t,Pointer)> id_297 { dessser::gen::raql_value::to_row_binary };
                              dc31f5cc689133a6f12d16478388e785 id_298 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_299 { std::get<4>(id_298) };
                              b02d571406bf80b296e55bb93213ea59 id_300 { std::get<0>(id_299) };
                              dessser::gen::raql_value::t id_301 { std::get<0>(id_300) };
                              Pointer id_302 { id_297(id_301, ssum_dst_1255) };
                              choose_res_296 = id_302;
                            } else {
                              uint16_t id_303 { 1 };
                              bool id_304 { bool(id_303 == label1_1254) };
                              Pointer choose_res_305;
                              if (id_304) {
                                std::function<Pointer(dessser::gen::raql_variable::t,Pointer)> id_306 { dessser::gen::raql_variable::to_row_binary };
                                dc31f5cc689133a6f12d16478388e785 id_307 { p_0.text };
                                a481e1e269544fa0efe70fc68e01b3bb id_308 { std::get<4>(id_307) };
                                b02d571406bf80b296e55bb93213ea59 id_309 { std::get<0>(id_308) };
                                dessser::gen::raql_variable::t id_310 { std::get<1>(id_309) };
                                Pointer id_311 { id_306(id_310, ssum_dst_1255) };
                                choose_res_305 = id_311;
                              } else {
                                uint16_t id_312 { 2 };
                                bool id_313 { bool(id_312 == label1_1254) };
                                Pointer choose_res_314;
                                if (id_313) {
                                  std::function<Pointer(dessser::gen::raql_binding_key::t,Pointer)> id_315 { dessser::gen::raql_binding_key::to_row_binary };
                                  dc31f5cc689133a6f12d16478388e785 id_316 { p_0.text };
                                  a481e1e269544fa0efe70fc68e01b3bb id_317 { std::get<4>(id_316) };
                                  b02d571406bf80b296e55bb93213ea59 id_318 { std::get<0>(id_317) };
                                  dessser::gen::raql_binding_key::t id_319 { std::get<2>(id_318) };
                                  Pointer id_320 { id_315(id_319, ssum_dst_1255) };
                                  choose_res_314 = id_320;
                                } else {
                                  uint16_t id_321 { 3 };
                                  bool id_322 { bool(id_321 == label1_1254) };
                                  Pointer choose_res_323;
                                  if (id_322) {
                                    choose_res_323 = ssum_dst_1255;
                                  } else {
                                    uint16_t id_324 { 4 };
                                    bool id_325 { bool(id_324 == label1_1254) };
                                    Pointer choose_res_326;
                                    if (id_325) {
                                      choose_res_326 = ssum_dst_1255;
                                    } else {
                                      uint16_t id_327 { 5 };
                                      bool id_328 { bool(id_327 == label1_1254) };
                                      Pointer choose_res_329;
                                      if (id_328) {
                                        choose_res_329 = ssum_dst_1255;
                                      } else {
                                        uint16_t id_330 { 6 };
                                        bool id_331 { bool(id_330 == label1_1254) };
                                        Pointer choose_res_332;
                                        if (id_331) {
                                          choose_res_332 = ssum_dst_1255;
                                        } else {
                                          uint16_t id_333 { 7 };
                                          bool id_334 { bool(id_333 == label1_1254) };
                                          Pointer choose_res_335;
                                          if (id_334) {
                                            dc31f5cc689133a6f12d16478388e785 id_336 { p_0.text };
                                            a481e1e269544fa0efe70fc68e01b3bb id_337 { std::get<4>(id_336) };
                                            b02d571406bf80b296e55bb93213ea59 id_338 { std::get<0>(id_337) };
                                            Lst<dessser::gen::raql_path_comp::t> id_339 { std::get<7>(id_338) };
                                            uint32_t id_340 { id_339.size() };
                                            Vec<1, uint32_t> id_341 {  id_340  };
                                            Pointer let_res_342;
                                            {
                                              Vec<1, uint32_t> leb128_sz_1256 { id_341 };
                                              Vec<1, Pointer> id_343 {  ssum_dst_1255  };
                                              Pointer let_res_344;
                                              {
                                                Vec<1, Pointer> leb128_ptr_1257 { id_343 };
                                                bool while_flag_345 { true };
                                                do {
                                                  uint8_t id_346 { 0 };
                                                  uint8_t id_347 { 0 };
                                                  Pointer id_348 { leb128_ptr_1257[id_347] };
                                                  uint32_t id_349 { 128U };
                                                  uint8_t id_350 { 0 };
                                                  uint32_t id_351 { leb128_sz_1256[id_350] };
                                                  bool id_352 { bool(id_349 > id_351) };
                                                  uint8_t choose_res_353;
                                                  if (id_352) {
                                                    uint8_t id_354 { 0 };
                                                    uint32_t id_355 { leb128_sz_1256[id_354] };
                                                    uint8_t id_356 { uint8_t(id_355) };
                                                    choose_res_353 = id_356;
                                                  } else {
                                                    uint8_t id_357 { 0 };
                                                    uint32_t id_358 { leb128_sz_1256[id_357] };
                                                    uint8_t id_359 { uint8_t(id_358) };
                                                    uint8_t id_360 { 128 };
                                                    uint8_t id_361 { uint8_t(id_359 | id_360) };
                                                    choose_res_353 = id_361;
                                                  }
                                                  Pointer id_362 { id_348.writeU8(choose_res_353) };
                                                  Void id_363 { ((void)(leb128_ptr_1257[id_346] = id_362), VOID) };
                                                  uint8_t id_364 { 0 };
                                                  uint8_t id_365 { 0 };
                                                  uint32_t id_366 { leb128_sz_1256[id_365] };
                                                  uint8_t id_367 { 7 };
                                                  uint32_t id_368 { uint32_t(id_366 >> id_367) };
                                                  Void id_369 { ((void)(leb128_sz_1256[id_364] = id_368), VOID) };
                                                  uint8_t id_370 { 0 };
                                                  uint32_t id_371 { leb128_sz_1256[id_370] };
                                                  uint32_t id_372 { 0U };
                                                  bool id_373 { bool(id_371 > id_372) };
                                                  while_flag_345 = id_373;
                                                  if (while_flag_345) {
                                                  }
                                                } while (while_flag_345);
                                                uint8_t id_374 { 0 };
                                                Pointer id_375 { leb128_ptr_1257[id_374] };
                                                let_res_344 = id_375;
                                              }
                                              let_res_342 = let_res_344;
                                            }
                                            Vec<1, Pointer> id_376 {  let_res_342  };
                                            Pointer let_res_377;
                                            {
                                              Vec<1, Pointer> dst_ref_1258 { id_376 };
                                              int32_t id_378 { 0L };
                                              Vec<1, int32_t> id_379 {  id_378  };
                                              Pointer let_res_380;
                                              {
                                                Vec<1, int32_t> n_ref_1259 { id_379 };
                                                dc31f5cc689133a6f12d16478388e785 id_381 { p_0.text };
                                                a481e1e269544fa0efe70fc68e01b3bb id_382 { std::get<4>(id_381) };
                                                b02d571406bf80b296e55bb93213ea59 id_383 { std::get<0>(id_382) };
                                                Lst<dessser::gen::raql_path_comp::t> id_384 { std::get<7>(id_383) };
                                                for (dessser::gen::raql_path_comp::t x_1260 : id_384) {
                                                  uint8_t id_385 { 0 };
                                                  std::function<Pointer(dessser::gen::raql_path_comp::t,Pointer)> id_386 { dessser::gen::raql_path_comp::to_row_binary };
                                                  uint8_t id_387 { 0 };
                                                  Pointer id_388 { dst_ref_1258[id_387] };
                                                  Pointer id_389 { id_386(x_1260, id_388) };
                                                  Void id_390 { ((void)(dst_ref_1258[id_385] = id_389), VOID) };
                                                  uint8_t id_391 { 0 };
                                                  int32_t id_392 { 1L };
                                                  uint8_t id_393 { 0 };
                                                  int32_t id_394 { n_ref_1259[id_393] };
                                                  int32_t id_395 { int32_t(id_392 + id_394) };
                                                  Void id_396 { ((void)(n_ref_1259[id_391] = id_395), VOID) };
                                                }
                                                uint8_t id_397 { 0 };
                                                Pointer id_398 { dst_ref_1258[id_397] };
                                                let_res_380 = id_398;
                                              }
                                              let_res_377 = let_res_380;
                                            }
                                            choose_res_335 = let_res_377;
                                          } else {
                                            uint16_t id_399 { 8 };
                                            bool id_400 { bool(label1_1254 == id_399) };
                                            Void id_401 { ((void)(assert(id_400)), VOID) };
                                            choose_res_335 = ssum_dst_1255;
                                          }
                                          choose_res_332 = choose_res_335;
                                        }
                                        choose_res_329 = choose_res_332;
                                      }
                                      choose_res_326 = choose_res_329;
                                    }
                                    choose_res_323 = choose_res_326;
                                  }
                                  choose_res_314 = choose_res_323;
                                }
                                choose_res_305 = choose_res_314;
                              }
                              choose_res_296 = choose_res_305;
                            }
                            let_res_293 = choose_res_296;
                          }
                          let_res_291 = let_res_293;
                        }
                        choose_res_286 = let_res_291;
                      } else {
                        uint16_t id_402 { 1 };
                        bool id_403 { bool(id_402 == label1_1227) };
                        Pointer choose_res_404;
                        if (id_403) {
                          dc31f5cc689133a6f12d16478388e785 id_405 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_406 { std::get<4>(id_405) };
                          v_86716e60fd92843b928cbb08bc52f333 id_407 { std::get<1>(id_406) };
                          t* id_408 { std::get<1>(id_407) };
                          dc31f5cc689133a6f12d16478388e785 id_409 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_410 { std::get<4>(id_409) };
                          v_86716e60fd92843b928cbb08bc52f333 id_411 { std::get<1>(id_410) };
                          v_1d6ee587a956ed7717b51cc22dd3b087 id_412 { std::get<0>(id_411) };
                          uint16_t id_413 { uint16_t(id_412.index()) };
                          Pointer let_res_414;
                          {
                            uint16_t label1_1246 { id_413 };
                            Pointer id_415 { ssum_dst_1228.writeU16Le(label1_1246) };
                            Pointer let_res_416;
                            {
                              Pointer ssum_dst_1247 { id_415 };
                              uint16_t id_417 { 0 };
                              bool id_418 { bool(id_417 == label1_1246) };
                              Pointer choose_res_419;
                              if (id_418) {
                                choose_res_419 = ssum_dst_1247;
                              } else {
                                uint16_t id_420 { 1 };
                                bool id_421 { bool(id_420 == label1_1246) };
                                Pointer choose_res_422;
                                if (id_421) {
                                  std::function<Pointer(dessser::gen::raql_type::t,Pointer)> id_423 { dessser::gen::raql_type::to_row_binary };
                                  dc31f5cc689133a6f12d16478388e785 id_424 { p_0.text };
                                  a481e1e269544fa0efe70fc68e01b3bb id_425 { std::get<4>(id_424) };
                                  v_86716e60fd92843b928cbb08bc52f333 id_426 { std::get<1>(id_425) };
                                  v_1d6ee587a956ed7717b51cc22dd3b087 id_427 { std::get<0>(id_426) };
                                  dessser::gen::raql_type::t id_428 { std::get<1>(id_427) };
                                  Pointer id_429 { id_423(id_428, ssum_dst_1247) };
                                  choose_res_422 = id_429;
                                } else {
                                  uint16_t id_430 { 2 };
                                  bool id_431 { bool(id_430 == label1_1246) };
                                  Pointer choose_res_432;
                                  if (id_431) {
                                    choose_res_432 = ssum_dst_1247;
                                  } else {
                                    uint16_t id_433 { 3 };
                                    bool id_434 { bool(id_433 == label1_1246) };
                                    Pointer choose_res_435;
                                    if (id_434) {
                                      std::function<Pointer(dessser::gen::raql_type::t,Pointer)> id_436 { dessser::gen::raql_type::to_row_binary };
                                      dc31f5cc689133a6f12d16478388e785 id_437 { p_0.text };
                                      a481e1e269544fa0efe70fc68e01b3bb id_438 { std::get<4>(id_437) };
                                      v_86716e60fd92843b928cbb08bc52f333 id_439 { std::get<1>(id_438) };
                                      v_1d6ee587a956ed7717b51cc22dd3b087 id_440 { std::get<0>(id_439) };
                                      v_562760c1b2585f63d315bb555b64832c id_441 { std::get<3>(id_440) };
                                      dessser::gen::raql_type::t id_442 { std::get<0>(id_441) };
                                      Pointer id_443 { id_436(id_442, ssum_dst_1247) };
                                      Pointer let_res_444;
                                      {
                                        Pointer stup_dst_1250 { id_443 };
                                        dc31f5cc689133a6f12d16478388e785 id_445 { p_0.text };
                                        a481e1e269544fa0efe70fc68e01b3bb id_446 { std::get<4>(id_445) };
                                        v_86716e60fd92843b928cbb08bc52f333 id_447 { std::get<1>(id_446) };
                                        v_1d6ee587a956ed7717b51cc22dd3b087 id_448 { std::get<0>(id_447) };
                                        v_562760c1b2585f63d315bb555b64832c id_449 { std::get<3>(id_448) };
                                        b31ee7e2e15bec4cfa9176ec3d86152e id_450 { std::get<1>(id_449) };
                                        uint16_t id_451 { uint16_t(id_450.index()) };
                                        Pointer id_452 { stup_dst_1250.writeU16Le(id_451) };
                                        Pointer let_res_453;
                                        {
                                          Pointer ssum_dst_1252 { id_452 };
                                          uint16_t id_454 { 0 };
                                          dc31f5cc689133a6f12d16478388e785 id_455 { p_0.text };
                                          a481e1e269544fa0efe70fc68e01b3bb id_456 { std::get<4>(id_455) };
                                          v_86716e60fd92843b928cbb08bc52f333 id_457 { std::get<1>(id_456) };
                                          v_1d6ee587a956ed7717b51cc22dd3b087 id_458 { std::get<0>(id_457) };
                                          v_562760c1b2585f63d315bb555b64832c id_459 { std::get<3>(id_458) };
                                          b31ee7e2e15bec4cfa9176ec3d86152e id_460 { std::get<1>(id_459) };
                                          uint16_t id_461 { uint16_t(id_460.index()) };
                                          bool id_462 { bool(id_454 == id_461) };
                                          Pointer choose_res_463;
                                          if (id_462) {
                                            choose_res_463 = ssum_dst_1252;
                                          } else {
                                            dc31f5cc689133a6f12d16478388e785 id_464 { p_0.text };
                                            a481e1e269544fa0efe70fc68e01b3bb id_465 { std::get<4>(id_464) };
                                            v_86716e60fd92843b928cbb08bc52f333 id_466 { std::get<1>(id_465) };
                                            v_1d6ee587a956ed7717b51cc22dd3b087 id_467 { std::get<0>(id_466) };
                                            v_562760c1b2585f63d315bb555b64832c id_468 { std::get<3>(id_467) };
                                            b31ee7e2e15bec4cfa9176ec3d86152e id_469 { std::get<1>(id_468) };
                                            uint16_t id_470 { uint16_t(id_469.index()) };
                                            uint16_t id_471 { 1 };
                                            bool id_472 { bool(id_470 == id_471) };
                                            Void id_473 { ((void)(assert(id_472)), VOID) };
                                            choose_res_463 = ssum_dst_1252;
                                          }
                                          let_res_453 = choose_res_463;
                                        }
                                        let_res_444 = let_res_453;
                                      }
                                      choose_res_435 = let_res_444;
                                    } else {
                                      uint16_t id_474 { 4 };
                                      bool id_475 { bool(id_474 == label1_1246) };
                                      Pointer choose_res_476;
                                      if (id_475) {
                                        choose_res_476 = ssum_dst_1247;
                                      } else {
                                        uint16_t id_477 { 5 };
                                        bool id_478 { bool(id_477 == label1_1246) };
                                        Pointer choose_res_479;
                                        if (id_478) {
                                          choose_res_479 = ssum_dst_1247;
                                        } else {
                                          uint16_t id_480 { 6 };
                                          bool id_481 { bool(id_480 == label1_1246) };
                                          Pointer choose_res_482;
                                          if (id_481) {
                                            choose_res_482 = ssum_dst_1247;
                                          } else {
                                            uint16_t id_483 { 7 };
                                            bool id_484 { bool(id_483 == label1_1246) };
                                            Pointer choose_res_485;
                                            if (id_484) {
                                              choose_res_485 = ssum_dst_1247;
                                            } else {
                                              uint16_t id_486 { 8 };
                                              bool id_487 { bool(id_486 == label1_1246) };
                                              Pointer choose_res_488;
                                              if (id_487) {
                                                choose_res_488 = ssum_dst_1247;
                                              } else {
                                                uint16_t id_489 { 9 };
                                                bool id_490 { bool(id_489 == label1_1246) };
                                                Pointer choose_res_491;
                                                if (id_490) {
                                                  choose_res_491 = ssum_dst_1247;
                                                } else {
                                                  uint16_t id_492 { 10 };
                                                  bool id_493 { bool(id_492 == label1_1246) };
                                                  Pointer choose_res_494;
                                                  if (id_493) {
                                                    choose_res_494 = ssum_dst_1247;
                                                  } else {
                                                    uint16_t id_495 { 11 };
                                                    bool id_496 { bool(id_495 == label1_1246) };
                                                    Pointer choose_res_497;
                                                    if (id_496) {
                                                      choose_res_497 = ssum_dst_1247;
                                                    } else {
                                                      uint16_t id_498 { 12 };
                                                      bool id_499 { bool(id_498 == label1_1246) };
                                                      Pointer choose_res_500;
                                                      if (id_499) {
                                                        choose_res_500 = ssum_dst_1247;
                                                      } else {
                                                        uint16_t id_501 { 13 };
                                                        bool id_502 { bool(id_501 == label1_1246) };
                                                        Pointer choose_res_503;
                                                        if (id_502) {
                                                          choose_res_503 = ssum_dst_1247;
                                                        } else {
                                                          uint16_t id_504 { 14 };
                                                          bool id_505 { bool(id_504 == label1_1246) };
                                                          Pointer choose_res_506;
                                                          if (id_505) {
                                                            choose_res_506 = ssum_dst_1247;
                                                          } else {
                                                            uint16_t id_507 { 15 };
                                                            bool id_508 { bool(id_507 == label1_1246) };
                                                            Pointer choose_res_509;
                                                            if (id_508) {
                                                              choose_res_509 = ssum_dst_1247;
                                                            } else {
                                                              uint16_t id_510 { 16 };
                                                              bool id_511 { bool(id_510 == label1_1246) };
                                                              Pointer choose_res_512;
                                                              if (id_511) {
                                                                choose_res_512 = ssum_dst_1247;
                                                              } else {
                                                                uint16_t id_513 { 17 };
                                                                bool id_514 { bool(id_513 == label1_1246) };
                                                                Pointer choose_res_515;
                                                                if (id_514) {
                                                                  choose_res_515 = ssum_dst_1247;
                                                                } else {
                                                                  uint16_t id_516 { 18 };
                                                                  bool id_517 { bool(id_516 == label1_1246) };
                                                                  Pointer choose_res_518;
                                                                  if (id_517) {
                                                                    choose_res_518 = ssum_dst_1247;
                                                                  } else {
                                                                    uint16_t id_519 { 19 };
                                                                    bool id_520 { bool(id_519 == label1_1246) };
                                                                    Pointer choose_res_521;
                                                                    if (id_520) {
                                                                      choose_res_521 = ssum_dst_1247;
                                                                    } else {
                                                                      uint16_t id_522 { 20 };
                                                                      bool id_523 { bool(id_522 == label1_1246) };
                                                                      Pointer choose_res_524;
                                                                      if (id_523) {
                                                                        choose_res_524 = ssum_dst_1247;
                                                                      } else {
                                                                        uint16_t id_525 { 21 };
                                                                        bool id_526 { bool(id_525 == label1_1246) };
                                                                        Pointer choose_res_527;
                                                                        if (id_526) {
                                                                          choose_res_527 = ssum_dst_1247;
                                                                        } else {
                                                                          uint16_t id_528 { 22 };
                                                                          bool id_529 { bool(id_528 == label1_1246) };
                                                                          Pointer choose_res_530;
                                                                          if (id_529) {
                                                                            choose_res_530 = ssum_dst_1247;
                                                                          } else {
                                                                            uint16_t id_531 { 23 };
                                                                            bool id_532 { bool(id_531 == label1_1246) };
                                                                            Pointer choose_res_533;
                                                                            if (id_532) {
                                                                              choose_res_533 = ssum_dst_1247;
                                                                            } else {
                                                                              uint16_t id_534 { 24 };
                                                                              bool id_535 { bool(id_534 == label1_1246) };
                                                                              Pointer choose_res_536;
                                                                              if (id_535) {
                                                                                choose_res_536 = ssum_dst_1247;
                                                                              } else {
                                                                                uint16_t id_537 { 25 };
                                                                                bool id_538 { bool(id_537 == label1_1246) };
                                                                                Pointer choose_res_539;
                                                                                if (id_538) {
                                                                                  choose_res_539 = ssum_dst_1247;
                                                                                } else {
                                                                                  uint16_t id_540 { 26 };
                                                                                  bool id_541 { bool(id_540 == label1_1246) };
                                                                                  Pointer choose_res_542;
                                                                                  if (id_541) {
                                                                                    choose_res_542 = ssum_dst_1247;
                                                                                  } else {
                                                                                    uint16_t id_543 { 27 };
                                                                                    bool id_544 { bool(id_543 == label1_1246) };
                                                                                    Pointer choose_res_545;
                                                                                    if (id_544) {
                                                                                      choose_res_545 = ssum_dst_1247;
                                                                                    } else {
                                                                                      uint16_t id_546 { 28 };
                                                                                      bool id_547 { bool(id_546 == label1_1246) };
                                                                                      Pointer choose_res_548;
                                                                                      if (id_547) {
                                                                                        choose_res_548 = ssum_dst_1247;
                                                                                      } else {
                                                                                        uint16_t id_549 { 29 };
                                                                                        bool id_550 { bool(id_549 == label1_1246) };
                                                                                        Pointer choose_res_551;
                                                                                        if (id_550) {
                                                                                          choose_res_551 = ssum_dst_1247;
                                                                                        } else {
                                                                                          uint16_t id_552 { 30 };
                                                                                          bool id_553 { bool(id_552 == label1_1246) };
                                                                                          Pointer choose_res_554;
                                                                                          if (id_553) {
                                                                                            choose_res_554 = ssum_dst_1247;
                                                                                          } else {
                                                                                            uint16_t id_555 { 31 };
                                                                                            bool id_556 { bool(id_555 == label1_1246) };
                                                                                            Pointer choose_res_557;
                                                                                            if (id_556) {
                                                                                              choose_res_557 = ssum_dst_1247;
                                                                                            } else {
                                                                                              uint16_t id_558 { 32 };
                                                                                              bool id_559 { bool(id_558 == label1_1246) };
                                                                                              Pointer choose_res_560;
                                                                                              if (id_559) {
                                                                                                choose_res_560 = ssum_dst_1247;
                                                                                              } else {
                                                                                                uint16_t id_561 { 33 };
                                                                                                bool id_562 { bool(id_561 == label1_1246) };
                                                                                                Pointer choose_res_563;
                                                                                                if (id_562) {
                                                                                                  choose_res_563 = ssum_dst_1247;
                                                                                                } else {
                                                                                                  uint16_t id_564 { 34 };
                                                                                                  bool id_565 { bool(id_564 == label1_1246) };
                                                                                                  Pointer choose_res_566;
                                                                                                  if (id_565) {
                                                                                                    choose_res_566 = ssum_dst_1247;
                                                                                                  } else {
                                                                                                    uint16_t id_567 { 35 };
                                                                                                    bool id_568 { bool(id_567 == label1_1246) };
                                                                                                    Pointer choose_res_569;
                                                                                                    if (id_568) {
                                                                                                      choose_res_569 = ssum_dst_1247;
                                                                                                    } else {
                                                                                                      uint16_t id_570 { 36 };
                                                                                                      bool id_571 { bool(id_570 == label1_1246) };
                                                                                                      Pointer choose_res_572;
                                                                                                      if (id_571) {
                                                                                                        dc31f5cc689133a6f12d16478388e785 id_573 { p_0.text };
                                                                                                        a481e1e269544fa0efe70fc68e01b3bb id_574 { std::get<4>(id_573) };
                                                                                                        v_86716e60fd92843b928cbb08bc52f333 id_575 { std::get<1>(id_574) };
                                                                                                        v_1d6ee587a956ed7717b51cc22dd3b087 id_576 { std::get<0>(id_575) };
                                                                                                        std::string id_577 { std::get<36>(id_576) };
                                                                                                        uint32_t id_578 { (uint32_t)id_577.size() };
                                                                                                        Vec<1, uint32_t> id_579 {  id_578  };
                                                                                                        Pointer let_res_580;
                                                                                                        {
                                                                                                          Vec<1, uint32_t> leb128_sz_1248 { id_579 };
                                                                                                          Vec<1, Pointer> id_581 {  ssum_dst_1247  };
                                                                                                          Pointer let_res_582;
                                                                                                          {
                                                                                                            Vec<1, Pointer> leb128_ptr_1249 { id_581 };
                                                                                                            bool while_flag_583 { true };
                                                                                                            do {
                                                                                                              uint8_t id_584 { 0 };
                                                                                                              uint8_t id_585 { 0 };
                                                                                                              Pointer id_586 { leb128_ptr_1249[id_585] };
                                                                                                              uint32_t id_587 { 128U };
                                                                                                              uint8_t id_588 { 0 };
                                                                                                              uint32_t id_589 { leb128_sz_1248[id_588] };
                                                                                                              bool id_590 { bool(id_587 > id_589) };
                                                                                                              uint8_t choose_res_591;
                                                                                                              if (id_590) {
                                                                                                                uint8_t id_592 { 0 };
                                                                                                                uint32_t id_593 { leb128_sz_1248[id_592] };
                                                                                                                uint8_t id_594 { uint8_t(id_593) };
                                                                                                                choose_res_591 = id_594;
                                                                                                              } else {
                                                                                                                uint8_t id_595 { 0 };
                                                                                                                uint32_t id_596 { leb128_sz_1248[id_595] };
                                                                                                                uint8_t id_597 { uint8_t(id_596) };
                                                                                                                uint8_t id_598 { 128 };
                                                                                                                uint8_t id_599 { uint8_t(id_597 | id_598) };
                                                                                                                choose_res_591 = id_599;
                                                                                                              }
                                                                                                              Pointer id_600 { id_586.writeU8(choose_res_591) };
                                                                                                              Void id_601 { ((void)(leb128_ptr_1249[id_584] = id_600), VOID) };
                                                                                                              uint8_t id_602 { 0 };
                                                                                                              uint8_t id_603 { 0 };
                                                                                                              uint32_t id_604 { leb128_sz_1248[id_603] };
                                                                                                              uint8_t id_605 { 7 };
                                                                                                              uint32_t id_606 { uint32_t(id_604 >> id_605) };
                                                                                                              Void id_607 { ((void)(leb128_sz_1248[id_602] = id_606), VOID) };
                                                                                                              uint8_t id_608 { 0 };
                                                                                                              uint32_t id_609 { leb128_sz_1248[id_608] };
                                                                                                              uint32_t id_610 { 0U };
                                                                                                              bool id_611 { bool(id_609 > id_610) };
                                                                                                              while_flag_583 = id_611;
                                                                                                              if (while_flag_583) {
                                                                                                              }
                                                                                                            } while (while_flag_583);
                                                                                                            uint8_t id_612 { 0 };
                                                                                                            Pointer id_613 { leb128_ptr_1249[id_612] };
                                                                                                            let_res_582 = id_613;
                                                                                                          }
                                                                                                          let_res_580 = let_res_582;
                                                                                                        }
                                                                                                        dc31f5cc689133a6f12d16478388e785 id_614 { p_0.text };
                                                                                                        a481e1e269544fa0efe70fc68e01b3bb id_615 { std::get<4>(id_614) };
                                                                                                        v_86716e60fd92843b928cbb08bc52f333 id_616 { std::get<1>(id_615) };
                                                                                                        v_1d6ee587a956ed7717b51cc22dd3b087 id_617 { std::get<0>(id_616) };
                                                                                                        std::string id_618 { std::get<36>(id_617) };
                                                                                                        Bytes id_619 { id_618 };
                                                                                                        Pointer id_620 { let_res_580.writeBytes(id_619) };
                                                                                                        choose_res_572 = id_620;
                                                                                                      } else {
                                                                                                        uint16_t id_621 { 37 };
                                                                                                        bool id_622 { bool(id_621 == label1_1246) };
                                                                                                        Pointer choose_res_623;
                                                                                                        if (id_622) {
                                                                                                          choose_res_623 = ssum_dst_1247;
                                                                                                        } else {
                                                                                                          uint16_t id_624 { 38 };
                                                                                                          bool id_625 { bool(id_624 == label1_1246) };
                                                                                                          Pointer choose_res_626;
                                                                                                          if (id_625) {
                                                                                                            choose_res_626 = ssum_dst_1247;
                                                                                                          } else {
                                                                                                            uint16_t id_627 { 39 };
                                                                                                            bool id_628 { bool(id_627 == label1_1246) };
                                                                                                            Pointer choose_res_629;
                                                                                                            if (id_628) {
                                                                                                              choose_res_629 = ssum_dst_1247;
                                                                                                            } else {
                                                                                                              uint16_t id_630 { 40 };
                                                                                                              bool id_631 { bool(label1_1246 == id_630) };
                                                                                                              Void id_632 { ((void)(assert(id_631)), VOID) };
                                                                                                              choose_res_629 = ssum_dst_1247;
                                                                                                            }
                                                                                                            choose_res_626 = choose_res_629;
                                                                                                          }
                                                                                                          choose_res_623 = choose_res_626;
                                                                                                        }
                                                                                                        choose_res_572 = choose_res_623;
                                                                                                      }
                                                                                                      choose_res_569 = choose_res_572;
                                                                                                    }
                                                                                                    choose_res_566 = choose_res_569;
                                                                                                  }
                                                                                                  choose_res_563 = choose_res_566;
                                                                                                }
                                                                                                choose_res_560 = choose_res_563;
                                                                                              }
                                                                                              choose_res_557 = choose_res_560;
                                                                                            }
                                                                                            choose_res_554 = choose_res_557;
                                                                                          }
                                                                                          choose_res_551 = choose_res_554;
                                                                                        }
                                                                                        choose_res_548 = choose_res_551;
                                                                                      }
                                                                                      choose_res_545 = choose_res_548;
                                                                                    }
                                                                                    choose_res_542 = choose_res_545;
                                                                                  }
                                                                                  choose_res_539 = choose_res_542;
                                                                                }
                                                                                choose_res_536 = choose_res_539;
                                                                              }
                                                                              choose_res_533 = choose_res_536;
                                                                            }
                                                                            choose_res_530 = choose_res_533;
                                                                          }
                                                                          choose_res_527 = choose_res_530;
                                                                        }
                                                                        choose_res_524 = choose_res_527;
                                                                      }
                                                                      choose_res_521 = choose_res_524;
                                                                    }
                                                                    choose_res_518 = choose_res_521;
                                                                  }
                                                                  choose_res_515 = choose_res_518;
                                                                }
                                                                choose_res_512 = choose_res_515;
                                                              }
                                                              choose_res_509 = choose_res_512;
                                                            }
                                                            choose_res_506 = choose_res_509;
                                                          }
                                                          choose_res_503 = choose_res_506;
                                                        }
                                                        choose_res_500 = choose_res_503;
                                                      }
                                                      choose_res_497 = choose_res_500;
                                                    }
                                                    choose_res_494 = choose_res_497;
                                                  }
                                                  choose_res_491 = choose_res_494;
                                                }
                                                choose_res_488 = choose_res_491;
                                              }
                                              choose_res_485 = choose_res_488;
                                            }
                                            choose_res_482 = choose_res_485;
                                          }
                                          choose_res_479 = choose_res_482;
                                        }
                                        choose_res_476 = choose_res_479;
                                      }
                                      choose_res_435 = choose_res_476;
                                    }
                                    choose_res_432 = choose_res_435;
                                  }
                                  choose_res_422 = choose_res_432;
                                }
                                choose_res_419 = choose_res_422;
                              }
                              let_res_416 = choose_res_419;
                            }
                            let_res_414 = let_res_416;
                          }
                          Pointer id_633 { fun0(id_408, let_res_414) };
                          choose_res_404 = id_633;
                        } else {
                          uint16_t id_634 { 2 };
                          bool id_635 { bool(id_634 == label1_1227) };
                          Pointer choose_res_636;
                          if (id_635) {
                            dc31f5cc689133a6f12d16478388e785 id_637 { p_0.text };
                            a481e1e269544fa0efe70fc68e01b3bb id_638 { std::get<4>(id_637) };
                            v_3b28b4928a9e27104e63a502937d8fd6 id_639 { std::get<2>(id_638) };
                            v_38879d3066416481efb8a2cff1fd95bb id_640 { std::get<0>(id_639) };
                            uint16_t id_641 { uint16_t(id_640.index()) };
                            Pointer let_res_642;
                            {
                              uint16_t label1_1238 { id_641 };
                              Pointer id_643 { ssum_dst_1228.writeU16Le(label1_1238) };
                              Pointer let_res_644;
                              {
                                Pointer ssum_dst_1239 { id_643 };
                                uint16_t id_645 { 0 };
                                bool id_646 { bool(id_645 == label1_1238) };
                                Pointer choose_res_647;
                                if (id_646) {
                                  choose_res_647 = ssum_dst_1239;
                                } else {
                                  uint16_t id_648 { 1 };
                                  bool id_649 { bool(id_648 == label1_1238) };
                                  Pointer choose_res_650;
                                  if (id_649) {
                                    choose_res_650 = ssum_dst_1239;
                                  } else {
                                    uint16_t id_651 { 2 };
                                    bool id_652 { bool(id_651 == label1_1238) };
                                    Pointer choose_res_653;
                                    if (id_652) {
                                      choose_res_653 = ssum_dst_1239;
                                    } else {
                                      uint16_t id_654 { 3 };
                                      bool id_655 { bool(label1_1238 == id_654) };
                                      Void id_656 { ((void)(assert(id_655)), VOID) };
                                      choose_res_653 = ssum_dst_1239;
                                    }
                                    choose_res_650 = choose_res_653;
                                  }
                                  choose_res_647 = choose_res_650;
                                }
                                let_res_644 = choose_res_647;
                              }
                              let_res_642 = let_res_644;
                            }
                            Pointer let_res_657;
                            {
                              Pointer stup_dst_1240 { let_res_642 };
                              dc31f5cc689133a6f12d16478388e785 id_658 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_659 { std::get<4>(id_658) };
                              v_3b28b4928a9e27104e63a502937d8fd6 id_660 { std::get<2>(id_659) };
                              Lst<t*> id_661 { std::get<1>(id_660) };
                              uint32_t id_662 { id_661.size() };
                              Vec<1, uint32_t> id_663 {  id_662  };
                              Pointer let_res_664;
                              {
                                Vec<1, uint32_t> leb128_sz_1241 { id_663 };
                                Vec<1, Pointer> id_665 {  stup_dst_1240  };
                                Pointer let_res_666;
                                {
                                  Vec<1, Pointer> leb128_ptr_1242 { id_665 };
                                  bool while_flag_667 { true };
                                  do {
                                    uint8_t id_668 { 0 };
                                    uint8_t id_669 { 0 };
                                    Pointer id_670 { leb128_ptr_1242[id_669] };
                                    uint32_t id_671 { 128U };
                                    uint8_t id_672 { 0 };
                                    uint32_t id_673 { leb128_sz_1241[id_672] };
                                    bool id_674 { bool(id_671 > id_673) };
                                    uint8_t choose_res_675;
                                    if (id_674) {
                                      uint8_t id_676 { 0 };
                                      uint32_t id_677 { leb128_sz_1241[id_676] };
                                      uint8_t id_678 { uint8_t(id_677) };
                                      choose_res_675 = id_678;
                                    } else {
                                      uint8_t id_679 { 0 };
                                      uint32_t id_680 { leb128_sz_1241[id_679] };
                                      uint8_t id_681 { uint8_t(id_680) };
                                      uint8_t id_682 { 128 };
                                      uint8_t id_683 { uint8_t(id_681 | id_682) };
                                      choose_res_675 = id_683;
                                    }
                                    Pointer id_684 { id_670.writeU8(choose_res_675) };
                                    Void id_685 { ((void)(leb128_ptr_1242[id_668] = id_684), VOID) };
                                    uint8_t id_686 { 0 };
                                    uint8_t id_687 { 0 };
                                    uint32_t id_688 { leb128_sz_1241[id_687] };
                                    uint8_t id_689 { 7 };
                                    uint32_t id_690 { uint32_t(id_688 >> id_689) };
                                    Void id_691 { ((void)(leb128_sz_1241[id_686] = id_690), VOID) };
                                    uint8_t id_692 { 0 };
                                    uint32_t id_693 { leb128_sz_1241[id_692] };
                                    uint32_t id_694 { 0U };
                                    bool id_695 { bool(id_693 > id_694) };
                                    while_flag_667 = id_695;
                                    if (while_flag_667) {
                                    }
                                  } while (while_flag_667);
                                  uint8_t id_696 { 0 };
                                  Pointer id_697 { leb128_ptr_1242[id_696] };
                                  let_res_666 = id_697;
                                }
                                let_res_664 = let_res_666;
                              }
                              Vec<1, Pointer> id_698 {  let_res_664  };
                              Pointer let_res_699;
                              {
                                Vec<1, Pointer> dst_ref_1243 { id_698 };
                                int32_t id_700 { 0L };
                                Vec<1, int32_t> id_701 {  id_700  };
                                Pointer let_res_702;
                                {
                                  Vec<1, int32_t> n_ref_1244 { id_701 };
                                  dc31f5cc689133a6f12d16478388e785 id_703 { p_0.text };
                                  a481e1e269544fa0efe70fc68e01b3bb id_704 { std::get<4>(id_703) };
                                  v_3b28b4928a9e27104e63a502937d8fd6 id_705 { std::get<2>(id_704) };
                                  Lst<t*> id_706 { std::get<1>(id_705) };
                                  for (t* x_1245 : id_706) {
                                    uint8_t id_707 { 0 };
                                    uint8_t id_708 { 0 };
                                    Pointer id_709 { dst_ref_1243[id_708] };
                                    Pointer id_710 { fun0(x_1245, id_709) };
                                    Void id_711 { ((void)(dst_ref_1243[id_707] = id_710), VOID) };
                                    uint8_t id_712 { 0 };
                                    int32_t id_713 { 1L };
                                    uint8_t id_714 { 0 };
                                    int32_t id_715 { n_ref_1244[id_714] };
                                    int32_t id_716 { int32_t(id_713 + id_715) };
                                    Void id_717 { ((void)(n_ref_1244[id_712] = id_716), VOID) };
                                  }
                                  uint8_t id_718 { 0 };
                                  Pointer id_719 { dst_ref_1243[id_718] };
                                  let_res_702 = id_719;
                                }
                                let_res_699 = let_res_702;
                              }
                              let_res_657 = let_res_699;
                            }
                            choose_res_636 = let_res_657;
                          } else {
                            uint16_t id_720 { 3 };
                            bool id_721 { bool(id_720 == label1_1227) };
                            Pointer choose_res_722;
                            if (id_721) {
                              dc31f5cc689133a6f12d16478388e785 id_723 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_724 { std::get<4>(id_723) };
                              v_8987bf3ba5adfaa68384b9fde66ab651 id_725 { std::get<3>(id_724) };
                              t* id_726 { std::get<2>(id_725) };
                              dc31f5cc689133a6f12d16478388e785 id_727 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_728 { std::get<4>(id_727) };
                              v_8987bf3ba5adfaa68384b9fde66ab651 id_729 { std::get<3>(id_728) };
                              t* id_730 { std::get<1>(id_729) };
                              dc31f5cc689133a6f12d16478388e785 id_731 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_732 { std::get<4>(id_731) };
                              v_8987bf3ba5adfaa68384b9fde66ab651 id_733 { std::get<3>(id_732) };
                              v_20bb2b786e4d41528e682385744fec03 id_734 { std::get<0>(id_733) };
                              uint16_t id_735 { uint16_t(id_734.index()) };
                              Pointer let_res_736;
                              {
                                uint16_t label1_1234 { id_735 };
                                Pointer id_737 { ssum_dst_1228.writeU16Le(label1_1234) };
                                Pointer let_res_738;
                                {
                                  Pointer ssum_dst_1235 { id_737 };
                                  uint16_t id_739 { 0 };
                                  bool id_740 { bool(id_739 == label1_1234) };
                                  Pointer choose_res_741;
                                  if (id_740) {
                                    choose_res_741 = ssum_dst_1235;
                                  } else {
                                    uint16_t id_742 { 1 };
                                    bool id_743 { bool(id_742 == label1_1234) };
                                    Pointer choose_res_744;
                                    if (id_743) {
                                      choose_res_744 = ssum_dst_1235;
                                    } else {
                                      uint16_t id_745 { 2 };
                                      bool id_746 { bool(id_745 == label1_1234) };
                                      Pointer choose_res_747;
                                      if (id_746) {
                                        choose_res_747 = ssum_dst_1235;
                                      } else {
                                        uint16_t id_748 { 3 };
                                        bool id_749 { bool(id_748 == label1_1234) };
                                        Pointer choose_res_750;
                                        if (id_749) {
                                          choose_res_750 = ssum_dst_1235;
                                        } else {
                                          uint16_t id_751 { 4 };
                                          bool id_752 { bool(id_751 == label1_1234) };
                                          Pointer choose_res_753;
                                          if (id_752) {
                                            choose_res_753 = ssum_dst_1235;
                                          } else {
                                            uint16_t id_754 { 5 };
                                            bool id_755 { bool(id_754 == label1_1234) };
                                            Pointer choose_res_756;
                                            if (id_755) {
                                              choose_res_756 = ssum_dst_1235;
                                            } else {
                                              uint16_t id_757 { 6 };
                                              bool id_758 { bool(id_757 == label1_1234) };
                                              Pointer choose_res_759;
                                              if (id_758) {
                                                choose_res_759 = ssum_dst_1235;
                                              } else {
                                                uint16_t id_760 { 7 };
                                                bool id_761 { bool(id_760 == label1_1234) };
                                                Pointer choose_res_762;
                                                if (id_761) {
                                                  choose_res_762 = ssum_dst_1235;
                                                } else {
                                                  uint16_t id_763 { 8 };
                                                  bool id_764 { bool(id_763 == label1_1234) };
                                                  Pointer choose_res_765;
                                                  if (id_764) {
                                                    choose_res_765 = ssum_dst_1235;
                                                  } else {
                                                    uint16_t id_766 { 9 };
                                                    bool id_767 { bool(id_766 == label1_1234) };
                                                    Pointer choose_res_768;
                                                    if (id_767) {
                                                      choose_res_768 = ssum_dst_1235;
                                                    } else {
                                                      uint16_t id_769 { 10 };
                                                      bool id_770 { bool(id_769 == label1_1234) };
                                                      Pointer choose_res_771;
                                                      if (id_770) {
                                                        choose_res_771 = ssum_dst_1235;
                                                      } else {
                                                        uint16_t id_772 { 11 };
                                                        bool id_773 { bool(id_772 == label1_1234) };
                                                        Pointer choose_res_774;
                                                        if (id_773) {
                                                          choose_res_774 = ssum_dst_1235;
                                                        } else {
                                                          uint16_t id_775 { 12 };
                                                          bool id_776 { bool(id_775 == label1_1234) };
                                                          Pointer choose_res_777;
                                                          if (id_776) {
                                                            choose_res_777 = ssum_dst_1235;
                                                          } else {
                                                            uint16_t id_778 { 13 };
                                                            bool id_779 { bool(id_778 == label1_1234) };
                                                            Pointer choose_res_780;
                                                            if (id_779) {
                                                              choose_res_780 = ssum_dst_1235;
                                                            } else {
                                                              uint16_t id_781 { 14 };
                                                              bool id_782 { bool(id_781 == label1_1234) };
                                                              Pointer choose_res_783;
                                                              if (id_782) {
                                                                choose_res_783 = ssum_dst_1235;
                                                              } else {
                                                                uint16_t id_784 { 15 };
                                                                bool id_785 { bool(id_784 == label1_1234) };
                                                                Pointer choose_res_786;
                                                                if (id_785) {
                                                                  choose_res_786 = ssum_dst_1235;
                                                                } else {
                                                                  uint16_t id_787 { 16 };
                                                                  bool id_788 { bool(id_787 == label1_1234) };
                                                                  Pointer choose_res_789;
                                                                  if (id_788) {
                                                                    choose_res_789 = ssum_dst_1235;
                                                                  } else {
                                                                    uint16_t id_790 { 17 };
                                                                    bool id_791 { bool(id_790 == label1_1234) };
                                                                    Pointer choose_res_792;
                                                                    if (id_791) {
                                                                      choose_res_792 = ssum_dst_1235;
                                                                    } else {
                                                                      uint16_t id_793 { 18 };
                                                                      bool id_794 { bool(id_793 == label1_1234) };
                                                                      Pointer choose_res_795;
                                                                      if (id_794) {
                                                                        choose_res_795 = ssum_dst_1235;
                                                                      } else {
                                                                        uint16_t id_796 { 19 };
                                                                        bool id_797 { bool(id_796 == label1_1234) };
                                                                        Pointer choose_res_798;
                                                                        if (id_797) {
                                                                          choose_res_798 = ssum_dst_1235;
                                                                        } else {
                                                                          uint16_t id_799 { 20 };
                                                                          bool id_800 { bool(id_799 == label1_1234) };
                                                                          Pointer choose_res_801;
                                                                          if (id_800) {
                                                                            choose_res_801 = ssum_dst_1235;
                                                                          } else {
                                                                            uint16_t id_802 { 21 };
                                                                            bool id_803 { bool(id_802 == label1_1234) };
                                                                            Pointer choose_res_804;
                                                                            if (id_803) {
                                                                              choose_res_804 = ssum_dst_1235;
                                                                            } else {
                                                                              uint16_t id_805 { 22 };
                                                                              bool id_806 { bool(id_805 == label1_1234) };
                                                                              Pointer choose_res_807;
                                                                              if (id_806) {
                                                                                choose_res_807 = ssum_dst_1235;
                                                                              } else {
                                                                                uint16_t id_808 { 23 };
                                                                                bool id_809 { bool(id_808 == label1_1234) };
                                                                                Pointer choose_res_810;
                                                                                if (id_809) {
                                                                                  choose_res_810 = ssum_dst_1235;
                                                                                } else {
                                                                                  uint16_t id_811 { 24 };
                                                                                  bool id_812 { bool(id_811 == label1_1234) };
                                                                                  Pointer choose_res_813;
                                                                                  if (id_812) {
                                                                                    choose_res_813 = ssum_dst_1235;
                                                                                  } else {
                                                                                    uint16_t id_814 { 25 };
                                                                                    bool id_815 { bool(label1_1234 == id_814) };
                                                                                    Void id_816 { ((void)(assert(id_815)), VOID) };
                                                                                    choose_res_813 = ssum_dst_1235;
                                                                                  }
                                                                                  choose_res_810 = choose_res_813;
                                                                                }
                                                                                choose_res_807 = choose_res_810;
                                                                              }
                                                                              choose_res_804 = choose_res_807;
                                                                            }
                                                                            choose_res_801 = choose_res_804;
                                                                          }
                                                                          choose_res_798 = choose_res_801;
                                                                        }
                                                                        choose_res_795 = choose_res_798;
                                                                      }
                                                                      choose_res_792 = choose_res_795;
                                                                    }
                                                                    choose_res_789 = choose_res_792;
                                                                  }
                                                                  choose_res_786 = choose_res_789;
                                                                }
                                                                choose_res_783 = choose_res_786;
                                                              }
                                                              choose_res_780 = choose_res_783;
                                                            }
                                                            choose_res_777 = choose_res_780;
                                                          }
                                                          choose_res_774 = choose_res_777;
                                                        }
                                                        choose_res_771 = choose_res_774;
                                                      }
                                                      choose_res_768 = choose_res_771;
                                                    }
                                                    choose_res_765 = choose_res_768;
                                                  }
                                                  choose_res_762 = choose_res_765;
                                                }
                                                choose_res_759 = choose_res_762;
                                              }
                                              choose_res_756 = choose_res_759;
                                            }
                                            choose_res_753 = choose_res_756;
                                          }
                                          choose_res_750 = choose_res_753;
                                        }
                                        choose_res_747 = choose_res_750;
                                      }
                                      choose_res_744 = choose_res_747;
                                    }
                                    choose_res_741 = choose_res_744;
                                  }
                                  let_res_738 = choose_res_741;
                                }
                                let_res_736 = let_res_738;
                              }
                              Pointer id_817 { fun0(id_730, let_res_736) };
                              Pointer id_818 { fun0(id_726, id_817) };
                              choose_res_722 = id_818;
                            } else {
                              uint16_t id_819 { 4 };
                              bool id_820 { bool(label1_1227 == id_819) };
                              Void id_821 { ((void)(assert(id_820)), VOID) };
                              dc31f5cc689133a6f12d16478388e785 id_822 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_823 { std::get<4>(id_822) };
                              v_3d59f26fb89fa3ef8dc792c2f4609b32 id_824 { std::get<4>(id_823) };
                              t* id_825 { std::get<3>(id_824) };
                              dc31f5cc689133a6f12d16478388e785 id_826 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_827 { std::get<4>(id_826) };
                              v_3d59f26fb89fa3ef8dc792c2f4609b32 id_828 { std::get<4>(id_827) };
                              t* id_829 { std::get<2>(id_828) };
                              dc31f5cc689133a6f12d16478388e785 id_830 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_831 { std::get<4>(id_830) };
                              v_3d59f26fb89fa3ef8dc792c2f4609b32 id_832 { std::get<4>(id_831) };
                              t* id_833 { std::get<1>(id_832) };
                              dc31f5cc689133a6f12d16478388e785 id_834 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_835 { std::get<4>(id_834) };
                              v_3d59f26fb89fa3ef8dc792c2f4609b32 id_836 { std::get<4>(id_835) };
                              v_4b68f284ffe696cb6936ca2f6880b08a id_837 { std::get<0>(id_836) };
                              uint16_t id_838 { uint16_t(id_837.index()) };
                              Pointer id_839 { ssum_dst_1228.writeU16Le(id_838) };
                              Pointer let_res_840;
                              {
                                Pointer ssum_dst_1230 { id_839 };
                                uint16_t id_841 { 0 };
                                dc31f5cc689133a6f12d16478388e785 id_842 { p_0.text };
                                a481e1e269544fa0efe70fc68e01b3bb id_843 { std::get<4>(id_842) };
                                v_3d59f26fb89fa3ef8dc792c2f4609b32 id_844 { std::get<4>(id_843) };
                                v_4b68f284ffe696cb6936ca2f6880b08a id_845 { std::get<0>(id_844) };
                                uint16_t id_846 { uint16_t(id_845.index()) };
                                bool id_847 { bool(id_841 == id_846) };
                                Pointer choose_res_848;
                                if (id_847) {
                                  choose_res_848 = ssum_dst_1230;
                                } else {
                                  dc31f5cc689133a6f12d16478388e785 id_849 { p_0.text };
                                  a481e1e269544fa0efe70fc68e01b3bb id_850 { std::get<4>(id_849) };
                                  v_3d59f26fb89fa3ef8dc792c2f4609b32 id_851 { std::get<4>(id_850) };
                                  v_4b68f284ffe696cb6936ca2f6880b08a id_852 { std::get<0>(id_851) };
                                  uint16_t id_853 { uint16_t(id_852.index()) };
                                  uint16_t id_854 { 1 };
                                  bool id_855 { bool(id_853 == id_854) };
                                  Void id_856 { ((void)(assert(id_855)), VOID) };
                                  choose_res_848 = ssum_dst_1230;
                                }
                                let_res_840 = choose_res_848;
                              }
                              Pointer id_857 { fun0(id_833, let_res_840) };
                              Pointer id_858 { fun0(id_829, id_857) };
                              Pointer id_859 { fun0(id_825, id_858) };
                              choose_res_722 = id_859;
                            }
                            choose_res_636 = choose_res_722;
                          }
                          choose_res_404 = choose_res_636;
                        }
                        choose_res_286 = choose_res_404;
                      }
                      let_res_283 = choose_res_286;
                    }
                    let_res_281 = let_res_283;
                  }
                  choose_res_277 = let_res_281;
                } else {
                  uint16_t id_860 { 5 };
                  bool id_861 { bool(id_860 == label1_1165) };
                  Pointer choose_res_862;
                  if (id_861) {
                    dc31f5cc689133a6f12d16478388e785 id_863 { p_0.text };
                    v_58c653b3fc47800248b5c8f49e80fabb id_864 { std::get<5>(id_863) };
                    d9442fc1deb39566ea1af2c5bee72a1c id_865 { std::get<0>(id_864) };
                    uint16_t id_866 { uint16_t(id_865.index()) };
                    Pointer id_867 { ssum_dst_1166.writeU16Le(id_866) };
                    Pointer let_res_868;
                    {
                      Pointer ssum_dst_1171 { id_867 };
                      uint16_t id_869 { 0 };
                      dc31f5cc689133a6f12d16478388e785 id_870 { p_0.text };
                      v_58c653b3fc47800248b5c8f49e80fabb id_871 { std::get<5>(id_870) };
                      d9442fc1deb39566ea1af2c5bee72a1c id_872 { std::get<0>(id_871) };
                      uint16_t id_873 { uint16_t(id_872.index()) };
                      bool id_874 { bool(id_869 == id_873) };
                      Pointer choose_res_875;
                      if (id_874) {
                        choose_res_875 = ssum_dst_1171;
                      } else {
                        dc31f5cc689133a6f12d16478388e785 id_876 { p_0.text };
                        v_58c653b3fc47800248b5c8f49e80fabb id_877 { std::get<5>(id_876) };
                        d9442fc1deb39566ea1af2c5bee72a1c id_878 { std::get<0>(id_877) };
                        uint16_t id_879 { uint16_t(id_878.index()) };
                        uint16_t id_880 { 1 };
                        bool id_881 { bool(id_879 == id_880) };
                        Void id_882 { ((void)(assert(id_881)), VOID) };
                        choose_res_875 = ssum_dst_1171;
                      }
                      let_res_868 = choose_res_875;
                    }
                    Pointer let_res_883;
                    {
                      Pointer stup_dst_1172 { let_res_868 };
                      dc31f5cc689133a6f12d16478388e785 id_884 { p_0.text };
                      v_58c653b3fc47800248b5c8f49e80fabb id_885 { std::get<5>(id_884) };
                      bool id_886 { std::get<1>(id_885) };
                      uint8_t id_887 { uint8_t(id_886) };
                      Pointer id_888 { stup_dst_1172.writeU8(id_887) };
                      let_res_883 = id_888;
                    }
                    Pointer let_res_889;
                    {
                      Pointer stup_dst_1173 { let_res_883 };
                      dc31f5cc689133a6f12d16478388e785 id_890 { p_0.text };
                      v_58c653b3fc47800248b5c8f49e80fabb id_891 { std::get<5>(id_890) };
                      v_2a737e40b715df686303c32fcaefae73 id_892 { std::get<2>(id_891) };
                      uint16_t id_893 { uint16_t(id_892.index()) };
                      Pointer let_res_894;
                      {
                        uint16_t label1_1174 { id_893 };
                        Pointer id_895 { stup_dst_1173.writeU16Le(label1_1174) };
                        Pointer let_res_896;
                        {
                          Pointer ssum_dst_1175 { id_895 };
                          uint16_t id_897 { 0 };
                          bool id_898 { bool(id_897 == label1_1174) };
                          Pointer choose_res_899;
                          if (id_898) {
                            dc31f5cc689133a6f12d16478388e785 id_900 { p_0.text };
                            v_58c653b3fc47800248b5c8f49e80fabb id_901 { std::get<5>(id_900) };
                            v_2a737e40b715df686303c32fcaefae73 id_902 { std::get<2>(id_901) };
                            b899c3a5f918df0742a7782ddf15cd18 id_903 { std::get<0>(id_902) };
                            t* id_904 { std::get<1>(id_903) };
                            dc31f5cc689133a6f12d16478388e785 id_905 { p_0.text };
                            v_58c653b3fc47800248b5c8f49e80fabb id_906 { std::get<5>(id_905) };
                            v_2a737e40b715df686303c32fcaefae73 id_907 { std::get<2>(id_906) };
                            b899c3a5f918df0742a7782ddf15cd18 id_908 { std::get<0>(id_907) };
                            v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_909 { std::get<0>(id_908) };
                            uint16_t id_910 { uint16_t(id_909.index()) };
                            Pointer let_res_911;
                            {
                              uint16_t label1_1222 { id_910 };
                              Pointer id_912 { ssum_dst_1175.writeU16Le(label1_1222) };
                              Pointer let_res_913;
                              {
                                Pointer ssum_dst_1223 { id_912 };
                                uint16_t id_914 { 0 };
                                bool id_915 { bool(id_914 == label1_1222) };
                                Pointer choose_res_916;
                                if (id_915) {
                                  choose_res_916 = ssum_dst_1223;
                                } else {
                                  uint16_t id_917 { 1 };
                                  bool id_918 { bool(id_917 == label1_1222) };
                                  Pointer choose_res_919;
                                  if (id_918) {
                                    choose_res_919 = ssum_dst_1223;
                                  } else {
                                    uint16_t id_920 { 2 };
                                    bool id_921 { bool(id_920 == label1_1222) };
                                    Pointer choose_res_922;
                                    if (id_921) {
                                      choose_res_922 = ssum_dst_1223;
                                    } else {
                                      uint16_t id_923 { 3 };
                                      bool id_924 { bool(id_923 == label1_1222) };
                                      Pointer choose_res_925;
                                      if (id_924) {
                                        choose_res_925 = ssum_dst_1223;
                                      } else {
                                        uint16_t id_926 { 4 };
                                        bool id_927 { bool(id_926 == label1_1222) };
                                        Pointer choose_res_928;
                                        if (id_927) {
                                          choose_res_928 = ssum_dst_1223;
                                        } else {
                                          uint16_t id_929 { 5 };
                                          bool id_930 { bool(id_929 == label1_1222) };
                                          Pointer choose_res_931;
                                          if (id_930) {
                                            choose_res_931 = ssum_dst_1223;
                                          } else {
                                            uint16_t id_932 { 6 };
                                            bool id_933 { bool(id_932 == label1_1222) };
                                            Pointer choose_res_934;
                                            if (id_933) {
                                              choose_res_934 = ssum_dst_1223;
                                            } else {
                                              uint16_t id_935 { 7 };
                                              bool id_936 { bool(id_935 == label1_1222) };
                                              Pointer choose_res_937;
                                              if (id_936) {
                                                choose_res_937 = ssum_dst_1223;
                                              } else {
                                                uint16_t id_938 { 8 };
                                                bool id_939 { bool(id_938 == label1_1222) };
                                                Pointer choose_res_940;
                                                if (id_939) {
                                                  choose_res_940 = ssum_dst_1223;
                                                } else {
                                                  uint16_t id_941 { 9 };
                                                  bool id_942 { bool(id_941 == label1_1222) };
                                                  Pointer choose_res_943;
                                                  if (id_942) {
                                                    choose_res_943 = ssum_dst_1223;
                                                  } else {
                                                    uint16_t id_944 { 10 };
                                                    bool id_945 { bool(id_944 == label1_1222) };
                                                    Pointer choose_res_946;
                                                    if (id_945) {
                                                      choose_res_946 = ssum_dst_1223;
                                                    } else {
                                                      uint16_t id_947 { 11 };
                                                      bool id_948 { bool(id_947 == label1_1222) };
                                                      Pointer choose_res_949;
                                                      if (id_948) {
                                                        dc31f5cc689133a6f12d16478388e785 id_950 { p_0.text };
                                                        v_58c653b3fc47800248b5c8f49e80fabb id_951 { std::get<5>(id_950) };
                                                        v_2a737e40b715df686303c32fcaefae73 id_952 { std::get<2>(id_951) };
                                                        b899c3a5f918df0742a7782ddf15cd18 id_953 { std::get<0>(id_952) };
                                                        v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_954 { std::get<0>(id_953) };
                                                        ff127e01aa6516985aeb6ae62f964e8f id_955 { std::get<11>(id_954) };
                                                        double id_956 { std::get<0>(id_955) };
                                                        uint64_t id_957 { qword_of_float(id_956) };
                                                        Pointer id_958 { ssum_dst_1223.writeU64Le(id_957) };
                                                        Pointer let_res_959;
                                                        {
                                                          Pointer stup_dst_1224 { id_958 };
                                                          dc31f5cc689133a6f12d16478388e785 id_960 { p_0.text };
                                                          v_58c653b3fc47800248b5c8f49e80fabb id_961 { std::get<5>(id_960) };
                                                          v_2a737e40b715df686303c32fcaefae73 id_962 { std::get<2>(id_961) };
                                                          b899c3a5f918df0742a7782ddf15cd18 id_963 { std::get<0>(id_962) };
                                                          v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_964 { std::get<0>(id_963) };
                                                          ff127e01aa6516985aeb6ae62f964e8f id_965 { std::get<11>(id_964) };
                                                          double id_966 { std::get<1>(id_965) };
                                                          uint64_t id_967 { qword_of_float(id_966) };
                                                          Pointer id_968 { stup_dst_1224.writeU64Le(id_967) };
                                                          let_res_959 = id_968;
                                                        }
                                                        Pointer let_res_969;
                                                        {
                                                          Pointer stup_dst_1225 { let_res_959 };
                                                          dc31f5cc689133a6f12d16478388e785 id_970 { p_0.text };
                                                          v_58c653b3fc47800248b5c8f49e80fabb id_971 { std::get<5>(id_970) };
                                                          v_2a737e40b715df686303c32fcaefae73 id_972 { std::get<2>(id_971) };
                                                          b899c3a5f918df0742a7782ddf15cd18 id_973 { std::get<0>(id_972) };
                                                          v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_974 { std::get<0>(id_973) };
                                                          ff127e01aa6516985aeb6ae62f964e8f id_975 { std::get<11>(id_974) };
                                                          uint32_t id_976 { std::get<2>(id_975) };
                                                          Pointer id_977 { stup_dst_1225.writeU32Le(id_976) };
                                                          let_res_969 = id_977;
                                                        }
                                                        choose_res_949 = let_res_969;
                                                      } else {
                                                        uint16_t id_978 { 12 };
                                                        bool id_979 { bool(id_978 == label1_1222) };
                                                        Pointer choose_res_980;
                                                        if (id_979) {
                                                          choose_res_980 = ssum_dst_1223;
                                                        } else {
                                                          uint16_t id_981 { 13 };
                                                          bool id_982 { bool(id_981 == label1_1222) };
                                                          Pointer choose_res_983;
                                                          if (id_982) {
                                                            choose_res_983 = ssum_dst_1223;
                                                          } else {
                                                            uint16_t id_984 { 14 };
                                                            bool id_985 { bool(label1_1222 == id_984) };
                                                            Void id_986 { ((void)(assert(id_985)), VOID) };
                                                            choose_res_983 = ssum_dst_1223;
                                                          }
                                                          choose_res_980 = choose_res_983;
                                                        }
                                                        choose_res_949 = choose_res_980;
                                                      }
                                                      choose_res_946 = choose_res_949;
                                                    }
                                                    choose_res_943 = choose_res_946;
                                                  }
                                                  choose_res_940 = choose_res_943;
                                                }
                                                choose_res_937 = choose_res_940;
                                              }
                                              choose_res_934 = choose_res_937;
                                            }
                                            choose_res_931 = choose_res_934;
                                          }
                                          choose_res_928 = choose_res_931;
                                        }
                                        choose_res_925 = choose_res_928;
                                      }
                                      choose_res_922 = choose_res_925;
                                    }
                                    choose_res_919 = choose_res_922;
                                  }
                                  choose_res_916 = choose_res_919;
                                }
                                let_res_913 = choose_res_916;
                              }
                              let_res_911 = let_res_913;
                            }
                            Pointer id_987 { fun0(id_904, let_res_911) };
                            choose_res_899 = id_987;
                          } else {
                            uint16_t id_988 { 1 };
                            bool id_989 { bool(id_988 == label1_1174) };
                            Pointer choose_res_990;
                            if (id_989) {
                              dc31f5cc689133a6f12d16478388e785 id_991 { p_0.text };
                              v_58c653b3fc47800248b5c8f49e80fabb id_992 { std::get<5>(id_991) };
                              v_2a737e40b715df686303c32fcaefae73 id_993 { std::get<2>(id_992) };
                              bd090e444c05c1e6fea8a3c1c0be1d01 id_994 { std::get<1>(id_993) };
                              t* id_995 { std::get<2>(id_994) };
                              dc31f5cc689133a6f12d16478388e785 id_996 { p_0.text };
                              v_58c653b3fc47800248b5c8f49e80fabb id_997 { std::get<5>(id_996) };
                              v_2a737e40b715df686303c32fcaefae73 id_998 { std::get<2>(id_997) };
                              bd090e444c05c1e6fea8a3c1c0be1d01 id_999 { std::get<1>(id_998) };
                              t* id_1000 { std::get<1>(id_999) };
                              dc31f5cc689133a6f12d16478388e785 id_1001 { p_0.text };
                              v_58c653b3fc47800248b5c8f49e80fabb id_1002 { std::get<5>(id_1001) };
                              v_2a737e40b715df686303c32fcaefae73 id_1003 { std::get<2>(id_1002) };
                              bd090e444c05c1e6fea8a3c1c0be1d01 id_1004 { std::get<1>(id_1003) };
                              v_1bafb672d5db6e6c81afc008103c3a63 id_1005 { std::get<0>(id_1004) };
                              uint16_t id_1006 { uint16_t(id_1005.index()) };
                              Pointer let_res_1007;
                              {
                                uint16_t label1_1218 { id_1006 };
                                Pointer id_1008 { ssum_dst_1175.writeU16Le(label1_1218) };
                                Pointer let_res_1009;
                                {
                                  Pointer ssum_dst_1219 { id_1008 };
                                  uint16_t id_1010 { 0 };
                                  bool id_1011 { bool(id_1010 == label1_1218) };
                                  Pointer choose_res_1012;
                                  if (id_1011) {
                                    choose_res_1012 = ssum_dst_1219;
                                  } else {
                                    uint16_t id_1013 { 1 };
                                    bool id_1014 { bool(id_1013 == label1_1218) };
                                    Pointer choose_res_1015;
                                    if (id_1014) {
                                      choose_res_1015 = ssum_dst_1219;
                                    } else {
                                      uint16_t id_1016 { 2 };
                                      bool id_1017 { bool(id_1016 == label1_1218) };
                                      Pointer choose_res_1018;
                                      if (id_1017) {
                                        choose_res_1018 = ssum_dst_1219;
                                      } else {
                                        uint16_t id_1019 { 3 };
                                        bool id_1020 { bool(label1_1218 == id_1019) };
                                        Void id_1021 { ((void)(assert(id_1020)), VOID) };
                                        choose_res_1018 = ssum_dst_1219;
                                      }
                                      choose_res_1015 = choose_res_1018;
                                    }
                                    choose_res_1012 = choose_res_1015;
                                  }
                                  let_res_1009 = choose_res_1012;
                                }
                                let_res_1007 = let_res_1009;
                              }
                              Pointer id_1022 { fun0(id_1000, let_res_1007) };
                              Pointer id_1023 { fun0(id_995, id_1022) };
                              choose_res_990 = id_1023;
                            } else {
                              uint16_t id_1024 { 2 };
                              bool id_1025 { bool(id_1024 == label1_1174) };
                              Pointer choose_res_1026;
                              if (id_1025) {
                                dc31f5cc689133a6f12d16478388e785 id_1027 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_1028 { std::get<5>(id_1027) };
                                v_2a737e40b715df686303c32fcaefae73 id_1029 { std::get<2>(id_1028) };
                                bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_1030 { std::get<2>(id_1029) };
                                t* id_1031 { std::get<3>(id_1030) };
                                dc31f5cc689133a6f12d16478388e785 id_1032 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_1033 { std::get<5>(id_1032) };
                                v_2a737e40b715df686303c32fcaefae73 id_1034 { std::get<2>(id_1033) };
                                bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_1035 { std::get<2>(id_1034) };
                                t* id_1036 { std::get<2>(id_1035) };
                                dc31f5cc689133a6f12d16478388e785 id_1037 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_1038 { std::get<5>(id_1037) };
                                v_2a737e40b715df686303c32fcaefae73 id_1039 { std::get<2>(id_1038) };
                                bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_1040 { std::get<2>(id_1039) };
                                t* id_1041 { std::get<1>(id_1040) };
                                dc31f5cc689133a6f12d16478388e785 id_1042 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_1043 { std::get<5>(id_1042) };
                                v_2a737e40b715df686303c32fcaefae73 id_1044 { std::get<2>(id_1043) };
                                bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_1045 { std::get<2>(id_1044) };
                                bf5e3bf9cedd12797481a910416c04b9 id_1046 { std::get<0>(id_1045) };
                                uint16_t id_1047 { uint16_t(id_1046.index()) };
                                Pointer let_res_1048;
                                {
                                  uint16_t label1_1213 { id_1047 };
                                  Pointer id_1049 { ssum_dst_1175.writeU16Le(label1_1213) };
                                  Pointer let_res_1050;
                                  {
                                    Pointer ssum_dst_1214 { id_1049 };
                                    uint16_t id_1051 { 0 };
                                    bool id_1052 { bool(id_1051 == label1_1213) };
                                    Pointer choose_res_1053;
                                    if (id_1052) {
                                      choose_res_1053 = ssum_dst_1214;
                                    } else {
                                      uint16_t id_1054 { 1 };
                                      bool id_1055 { bool(id_1054 == label1_1213) };
                                      Pointer choose_res_1056;
                                      if (id_1055) {
                                        choose_res_1056 = ssum_dst_1214;
                                      } else {
                                        uint16_t id_1057 { 2 };
                                        bool id_1058 { bool(label1_1213 == id_1057) };
                                        Void id_1059 { ((void)(assert(id_1058)), VOID) };
                                        dc31f5cc689133a6f12d16478388e785 id_1060 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1061 { std::get<5>(id_1060) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1062 { std::get<2>(id_1061) };
                                        bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_1063 { std::get<2>(id_1062) };
                                        bf5e3bf9cedd12797481a910416c04b9 id_1064 { std::get<0>(id_1063) };
                                        bool id_1065 { std::get<2>(id_1064) };
                                        uint8_t id_1066 { uint8_t(id_1065) };
                                        Pointer id_1067 { ssum_dst_1214.writeU8(id_1066) };
                                        choose_res_1056 = id_1067;
                                      }
                                      choose_res_1053 = choose_res_1056;
                                    }
                                    let_res_1050 = choose_res_1053;
                                  }
                                  let_res_1048 = let_res_1050;
                                }
                                Pointer id_1068 { fun0(id_1041, let_res_1048) };
                                Pointer id_1069 { fun0(id_1036, id_1068) };
                                Pointer id_1070 { fun0(id_1031, id_1069) };
                                choose_res_1026 = id_1070;
                              } else {
                                uint16_t id_1071 { 3 };
                                bool id_1072 { bool(id_1071 == label1_1174) };
                                Pointer choose_res_1073;
                                if (id_1072) {
                                  dc31f5cc689133a6f12d16478388e785 id_1074 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_1075 { std::get<5>(id_1074) };
                                  v_2a737e40b715df686303c32fcaefae73 id_1076 { std::get<2>(id_1075) };
                                  v_853c6bada9e3fde79da0a65d1b1d1c9a id_1077 { std::get<3>(id_1076) };
                                  t* id_1078 { std::get<4>(id_1077) };
                                  dc31f5cc689133a6f12d16478388e785 id_1079 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_1080 { std::get<5>(id_1079) };
                                  v_2a737e40b715df686303c32fcaefae73 id_1081 { std::get<2>(id_1080) };
                                  v_853c6bada9e3fde79da0a65d1b1d1c9a id_1082 { std::get<3>(id_1081) };
                                  t* id_1083 { std::get<3>(id_1082) };
                                  dc31f5cc689133a6f12d16478388e785 id_1084 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_1085 { std::get<5>(id_1084) };
                                  v_2a737e40b715df686303c32fcaefae73 id_1086 { std::get<2>(id_1085) };
                                  v_853c6bada9e3fde79da0a65d1b1d1c9a id_1087 { std::get<3>(id_1086) };
                                  t* id_1088 { std::get<2>(id_1087) };
                                  dc31f5cc689133a6f12d16478388e785 id_1089 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_1090 { std::get<5>(id_1089) };
                                  v_2a737e40b715df686303c32fcaefae73 id_1091 { std::get<2>(id_1090) };
                                  v_853c6bada9e3fde79da0a65d1b1d1c9a id_1092 { std::get<3>(id_1091) };
                                  t* id_1093 { std::get<1>(id_1092) };
                                  dc31f5cc689133a6f12d16478388e785 id_1094 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_1095 { std::get<5>(id_1094) };
                                  v_2a737e40b715df686303c32fcaefae73 id_1096 { std::get<2>(id_1095) };
                                  v_853c6bada9e3fde79da0a65d1b1d1c9a id_1097 { std::get<3>(id_1096) };
                                  v_87b032206ceea8867a37c2e0aaee953e id_1098 { std::get<0>(id_1097) };
                                  uint16_t id_1099 { uint16_t(id_1098.index()) };
                                  Pointer id_1100 { ssum_dst_1175.writeU16Le(id_1099) };
                                  Pointer let_res_1101;
                                  {
                                    Pointer ssum_dst_1208 { id_1100 };
                                    uint16_t id_1102 { 0 };
                                    dc31f5cc689133a6f12d16478388e785 id_1103 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_1104 { std::get<5>(id_1103) };
                                    v_2a737e40b715df686303c32fcaefae73 id_1105 { std::get<2>(id_1104) };
                                    v_853c6bada9e3fde79da0a65d1b1d1c9a id_1106 { std::get<3>(id_1105) };
                                    v_87b032206ceea8867a37c2e0aaee953e id_1107 { std::get<0>(id_1106) };
                                    uint16_t id_1108 { uint16_t(id_1107.index()) };
                                    bool id_1109 { bool(id_1102 == id_1108) };
                                    Pointer choose_res_1110;
                                    if (id_1109) {
                                      choose_res_1110 = ssum_dst_1208;
                                    } else {
                                      dc31f5cc689133a6f12d16478388e785 id_1111 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1112 { std::get<5>(id_1111) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1113 { std::get<2>(id_1112) };
                                      v_853c6bada9e3fde79da0a65d1b1d1c9a id_1114 { std::get<3>(id_1113) };
                                      v_87b032206ceea8867a37c2e0aaee953e id_1115 { std::get<0>(id_1114) };
                                      uint16_t id_1116 { uint16_t(id_1115.index()) };
                                      uint16_t id_1117 { 1 };
                                      bool id_1118 { bool(id_1116 == id_1117) };
                                      Void id_1119 { ((void)(assert(id_1118)), VOID) };
                                      dc31f5cc689133a6f12d16478388e785 id_1120 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1121 { std::get<5>(id_1120) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1122 { std::get<2>(id_1121) };
                                      v_853c6bada9e3fde79da0a65d1b1d1c9a id_1123 { std::get<3>(id_1122) };
                                      v_87b032206ceea8867a37c2e0aaee953e id_1124 { std::get<0>(id_1123) };
                                      bool id_1125 { std::get<1>(id_1124) };
                                      uint8_t id_1126 { uint8_t(id_1125) };
                                      Pointer id_1127 { ssum_dst_1208.writeU8(id_1126) };
                                      choose_res_1110 = id_1127;
                                    }
                                    let_res_1101 = choose_res_1110;
                                  }
                                  Pointer id_1128 { fun0(id_1093, let_res_1101) };
                                  Pointer id_1129 { fun0(id_1088, id_1128) };
                                  Pointer id_1130 { fun0(id_1083, id_1129) };
                                  Pointer id_1131 { fun0(id_1078, id_1130) };
                                  choose_res_1073 = id_1131;
                                } else {
                                  uint16_t id_1132 { 4 };
                                  bool id_1133 { bool(id_1132 == label1_1174) };
                                  Pointer choose_res_1134;
                                  if (id_1133) {
                                    dc31f5cc689133a6f12d16478388e785 id_1135 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_1136 { std::get<5>(id_1135) };
                                    v_2a737e40b715df686303c32fcaefae73 id_1137 { std::get<2>(id_1136) };
                                    d48e39cf1002fefa9b2dd8287b9e36b3 id_1138 { std::get<4>(id_1137) };
                                    t* id_1139 { std::get<3>(id_1138) };
                                    dc31f5cc689133a6f12d16478388e785 id_1140 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_1141 { std::get<5>(id_1140) };
                                    v_2a737e40b715df686303c32fcaefae73 id_1142 { std::get<2>(id_1141) };
                                    d48e39cf1002fefa9b2dd8287b9e36b3 id_1143 { std::get<4>(id_1142) };
                                    t* id_1144 { std::get<2>(id_1143) };
                                    dc31f5cc689133a6f12d16478388e785 id_1145 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_1146 { std::get<5>(id_1145) };
                                    v_2a737e40b715df686303c32fcaefae73 id_1147 { std::get<2>(id_1146) };
                                    d48e39cf1002fefa9b2dd8287b9e36b3 id_1148 { std::get<4>(id_1147) };
                                    t* id_1149 { std::get<1>(id_1148) };
                                    dc31f5cc689133a6f12d16478388e785 id_1150 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_1151 { std::get<5>(id_1150) };
                                    v_2a737e40b715df686303c32fcaefae73 id_1152 { std::get<2>(id_1151) };
                                    d48e39cf1002fefa9b2dd8287b9e36b3 id_1153 { std::get<4>(id_1152) };
                                    v_40203346c83d9d499f90ff16996e8968 id_1154 { std::get<0>(id_1153) };
                                    uint16_t id_1155 { uint16_t(id_1154.index()) };
                                    Pointer id_1156 { ssum_dst_1175.writeU16Le(id_1155) };
                                    Pointer let_res_1157;
                                    {
                                      Pointer ssum_dst_1196 { id_1156 };
                                      uint16_t id_1158 { 0 };
                                      dc31f5cc689133a6f12d16478388e785 id_1159 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1160 { std::get<5>(id_1159) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1161 { std::get<2>(id_1160) };
                                      d48e39cf1002fefa9b2dd8287b9e36b3 id_1162 { std::get<4>(id_1161) };
                                      v_40203346c83d9d499f90ff16996e8968 id_1163 { std::get<0>(id_1162) };
                                      uint16_t id_1164 { uint16_t(id_1163.index()) };
                                      bool id_1165 { bool(id_1158 == id_1164) };
                                      Pointer choose_res_1166;
                                      if (id_1165) {
                                        choose_res_1166 = ssum_dst_1196;
                                      } else {
                                        dc31f5cc689133a6f12d16478388e785 id_1167 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1168 { std::get<5>(id_1167) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1169 { std::get<2>(id_1168) };
                                        d48e39cf1002fefa9b2dd8287b9e36b3 id_1170 { std::get<4>(id_1169) };
                                        v_40203346c83d9d499f90ff16996e8968 id_1171 { std::get<0>(id_1170) };
                                        uint16_t id_1172 { uint16_t(id_1171.index()) };
                                        uint16_t id_1173 { 1 };
                                        bool id_1174 { bool(id_1172 == id_1173) };
                                        Void id_1175 { ((void)(assert(id_1174)), VOID) };
                                        dc31f5cc689133a6f12d16478388e785 id_1176 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1177 { std::get<5>(id_1176) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1178 { std::get<2>(id_1177) };
                                        d48e39cf1002fefa9b2dd8287b9e36b3 id_1179 { std::get<4>(id_1178) };
                                        v_40203346c83d9d499f90ff16996e8968 id_1180 { std::get<0>(id_1179) };
                                        v_0cb2265b788de1dea43d444c41f930d3 id_1181 { std::get<1>(id_1180) };
                                        bool id_1182 { id_1181.inv };
                                        uint8_t id_1183 { uint8_t(id_1182) };
                                        Pointer id_1184 { ssum_dst_1196.writeU8(id_1183) };
                                        Pointer let_res_1185;
                                        {
                                          Pointer srec_dst_1197 { id_1184 };
                                          dc31f5cc689133a6f12d16478388e785 id_1186 { p_0.text };
                                          v_58c653b3fc47800248b5c8f49e80fabb id_1187 { std::get<5>(id_1186) };
                                          v_2a737e40b715df686303c32fcaefae73 id_1188 { std::get<2>(id_1187) };
                                          d48e39cf1002fefa9b2dd8287b9e36b3 id_1189 { std::get<4>(id_1188) };
                                          v_40203346c83d9d499f90ff16996e8968 id_1190 { std::get<0>(id_1189) };
                                          v_0cb2265b788de1dea43d444c41f930d3 id_1191 { std::get<1>(id_1190) };
                                          bool id_1192 { id_1191.up_to };
                                          uint8_t id_1193 { uint8_t(id_1192) };
                                          Pointer id_1194 { srec_dst_1197.writeU8(id_1193) };
                                          let_res_1185 = id_1194;
                                        }
                                        choose_res_1166 = let_res_1185;
                                      }
                                      let_res_1157 = choose_res_1166;
                                    }
                                    Pointer id_1195 { fun0(id_1149, let_res_1157) };
                                    Pointer id_1196 { fun0(id_1144, id_1195) };
                                    Pointer id_1197 { fun0(id_1139, id_1196) };
                                    Pointer let_res_1198;
                                    {
                                      Pointer stup_dst_1201 { id_1197 };
                                      dc31f5cc689133a6f12d16478388e785 id_1199 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1200 { std::get<5>(id_1199) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1201 { std::get<2>(id_1200) };
                                      d48e39cf1002fefa9b2dd8287b9e36b3 id_1202 { std::get<4>(id_1201) };
                                      Lst<t*> id_1203 { std::get<4>(id_1202) };
                                      uint32_t id_1204 { id_1203.size() };
                                      Vec<1, uint32_t> id_1205 {  id_1204  };
                                      Pointer let_res_1206;
                                      {
                                        Vec<1, uint32_t> leb128_sz_1202 { id_1205 };
                                        Vec<1, Pointer> id_1207 {  stup_dst_1201  };
                                        Pointer let_res_1208;
                                        {
                                          Vec<1, Pointer> leb128_ptr_1203 { id_1207 };
                                          bool while_flag_1209 { true };
                                          do {
                                            uint8_t id_1210 { 0 };
                                            uint8_t id_1211 { 0 };
                                            Pointer id_1212 { leb128_ptr_1203[id_1211] };
                                            uint32_t id_1213 { 128U };
                                            uint8_t id_1214 { 0 };
                                            uint32_t id_1215 { leb128_sz_1202[id_1214] };
                                            bool id_1216 { bool(id_1213 > id_1215) };
                                            uint8_t choose_res_1217;
                                            if (id_1216) {
                                              uint8_t id_1218 { 0 };
                                              uint32_t id_1219 { leb128_sz_1202[id_1218] };
                                              uint8_t id_1220 { uint8_t(id_1219) };
                                              choose_res_1217 = id_1220;
                                            } else {
                                              uint8_t id_1221 { 0 };
                                              uint32_t id_1222 { leb128_sz_1202[id_1221] };
                                              uint8_t id_1223 { uint8_t(id_1222) };
                                              uint8_t id_1224 { 128 };
                                              uint8_t id_1225 { uint8_t(id_1223 | id_1224) };
                                              choose_res_1217 = id_1225;
                                            }
                                            Pointer id_1226 { id_1212.writeU8(choose_res_1217) };
                                            Void id_1227 { ((void)(leb128_ptr_1203[id_1210] = id_1226), VOID) };
                                            uint8_t id_1228 { 0 };
                                            uint8_t id_1229 { 0 };
                                            uint32_t id_1230 { leb128_sz_1202[id_1229] };
                                            uint8_t id_1231 { 7 };
                                            uint32_t id_1232 { uint32_t(id_1230 >> id_1231) };
                                            Void id_1233 { ((void)(leb128_sz_1202[id_1228] = id_1232), VOID) };
                                            uint8_t id_1234 { 0 };
                                            uint32_t id_1235 { leb128_sz_1202[id_1234] };
                                            uint32_t id_1236 { 0U };
                                            bool id_1237 { bool(id_1235 > id_1236) };
                                            while_flag_1209 = id_1237;
                                            if (while_flag_1209) {
                                            }
                                          } while (while_flag_1209);
                                          uint8_t id_1238 { 0 };
                                          Pointer id_1239 { leb128_ptr_1203[id_1238] };
                                          let_res_1208 = id_1239;
                                        }
                                        let_res_1206 = let_res_1208;
                                      }
                                      Vec<1, Pointer> id_1240 {  let_res_1206  };
                                      Pointer let_res_1241;
                                      {
                                        Vec<1, Pointer> dst_ref_1204 { id_1240 };
                                        int32_t id_1242 { 0L };
                                        Vec<1, int32_t> id_1243 {  id_1242  };
                                        Pointer let_res_1244;
                                        {
                                          Vec<1, int32_t> n_ref_1205 { id_1243 };
                                          dc31f5cc689133a6f12d16478388e785 id_1245 { p_0.text };
                                          v_58c653b3fc47800248b5c8f49e80fabb id_1246 { std::get<5>(id_1245) };
                                          v_2a737e40b715df686303c32fcaefae73 id_1247 { std::get<2>(id_1246) };
                                          d48e39cf1002fefa9b2dd8287b9e36b3 id_1248 { std::get<4>(id_1247) };
                                          Lst<t*> id_1249 { std::get<4>(id_1248) };
                                          for (t* x_1206 : id_1249) {
                                            uint8_t id_1250 { 0 };
                                            uint8_t id_1251 { 0 };
                                            Pointer id_1252 { dst_ref_1204[id_1251] };
                                            Pointer id_1253 { fun0(x_1206, id_1252) };
                                            Void id_1254 { ((void)(dst_ref_1204[id_1250] = id_1253), VOID) };
                                            uint8_t id_1255 { 0 };
                                            int32_t id_1256 { 1L };
                                            uint8_t id_1257 { 0 };
                                            int32_t id_1258 { n_ref_1205[id_1257] };
                                            int32_t id_1259 { int32_t(id_1256 + id_1258) };
                                            Void id_1260 { ((void)(n_ref_1205[id_1255] = id_1259), VOID) };
                                          }
                                          uint8_t id_1261 { 0 };
                                          Pointer id_1262 { dst_ref_1204[id_1261] };
                                          let_res_1244 = id_1262;
                                        }
                                        let_res_1241 = let_res_1244;
                                      }
                                      let_res_1198 = let_res_1241;
                                    }
                                    choose_res_1134 = let_res_1198;
                                  } else {
                                    uint16_t id_1263 { 5 };
                                    bool id_1264 { bool(id_1263 == label1_1174) };
                                    Pointer choose_res_1265;
                                    if (id_1264) {
                                      dc31f5cc689133a6f12d16478388e785 id_1266 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1267 { std::get<5>(id_1266) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1268 { std::get<2>(id_1267) };
                                      v_28696cf4b42cc9ab09b392e5143f2f25 id_1269 { std::get<5>(id_1268) };
                                      t* id_1270 { std::get<6>(id_1269) };
                                      dc31f5cc689133a6f12d16478388e785 id_1271 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1272 { std::get<5>(id_1271) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1273 { std::get<2>(id_1272) };
                                      v_28696cf4b42cc9ab09b392e5143f2f25 id_1274 { std::get<5>(id_1273) };
                                      t* id_1275 { std::get<5>(id_1274) };
                                      dc31f5cc689133a6f12d16478388e785 id_1276 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1277 { std::get<5>(id_1276) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1278 { std::get<2>(id_1277) };
                                      v_28696cf4b42cc9ab09b392e5143f2f25 id_1279 { std::get<5>(id_1278) };
                                      t* id_1280 { std::get<4>(id_1279) };
                                      dc31f5cc689133a6f12d16478388e785 id_1281 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1282 { std::get<5>(id_1281) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1283 { std::get<2>(id_1282) };
                                      v_28696cf4b42cc9ab09b392e5143f2f25 id_1284 { std::get<5>(id_1283) };
                                      t* id_1285 { std::get<3>(id_1284) };
                                      dc31f5cc689133a6f12d16478388e785 id_1286 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1287 { std::get<5>(id_1286) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1288 { std::get<2>(id_1287) };
                                      v_28696cf4b42cc9ab09b392e5143f2f25 id_1289 { std::get<5>(id_1288) };
                                      t* id_1290 { std::get<2>(id_1289) };
                                      dc31f5cc689133a6f12d16478388e785 id_1291 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1292 { std::get<5>(id_1291) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1293 { std::get<2>(id_1292) };
                                      v_28696cf4b42cc9ab09b392e5143f2f25 id_1294 { std::get<5>(id_1293) };
                                      t* id_1295 { std::get<1>(id_1294) };
                                      dc31f5cc689133a6f12d16478388e785 id_1296 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_1297 { std::get<5>(id_1296) };
                                      v_2a737e40b715df686303c32fcaefae73 id_1298 { std::get<2>(id_1297) };
                                      v_28696cf4b42cc9ab09b392e5143f2f25 id_1299 { std::get<5>(id_1298) };
                                      d137ffedb0c351c86760c7f124759f50 id_1300 { std::get<0>(id_1299) };
                                      uint16_t id_1301 { uint16_t(id_1300.index()) };
                                      Pointer id_1302 { ssum_dst_1175.writeU16Le(id_1301) };
                                      Pointer let_res_1303;
                                      {
                                        Pointer ssum_dst_1188 { id_1302 };
                                        dc31f5cc689133a6f12d16478388e785 id_1304 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1305 { std::get<5>(id_1304) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1306 { std::get<2>(id_1305) };
                                        v_28696cf4b42cc9ab09b392e5143f2f25 id_1307 { std::get<5>(id_1306) };
                                        d137ffedb0c351c86760c7f124759f50 id_1308 { std::get<0>(id_1307) };
                                        uint16_t id_1309 { uint16_t(id_1308.index()) };
                                        uint16_t id_1310 { 0 };
                                        bool id_1311 { bool(id_1309 == id_1310) };
                                        Void id_1312 { ((void)(assert(id_1311)), VOID) };
                                        let_res_1303 = ssum_dst_1188;
                                      }
                                      Pointer id_1313 { fun0(id_1295, let_res_1303) };
                                      Pointer id_1314 { fun0(id_1290, id_1313) };
                                      Pointer id_1315 { fun0(id_1285, id_1314) };
                                      Pointer id_1316 { fun0(id_1280, id_1315) };
                                      Pointer id_1317 { fun0(id_1275, id_1316) };
                                      Pointer id_1318 { fun0(id_1270, id_1317) };
                                      choose_res_1265 = id_1318;
                                    } else {
                                      uint16_t id_1319 { 6 };
                                      bool id_1320 { bool(id_1319 == label1_1174) };
                                      Pointer choose_res_1321;
                                      if (id_1320) {
                                        dc31f5cc689133a6f12d16478388e785 id_1322 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1323 { std::get<5>(id_1322) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1324 { std::get<2>(id_1323) };
                                        v_2da729c5f96e51679cb6e2c06e6ceb25 id_1325 { std::get<6>(id_1324) };
                                        t* id_1326 { id_1325.sigmas };
                                        dc31f5cc689133a6f12d16478388e785 id_1327 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1328 { std::get<5>(id_1327) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1329 { std::get<2>(id_1328) };
                                        v_2da729c5f96e51679cb6e2c06e6ceb25 id_1330 { std::get<6>(id_1329) };
                                        t* id_1331 { id_1330.duration };
                                        dc31f5cc689133a6f12d16478388e785 id_1332 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1333 { std::get<5>(id_1332) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1334 { std::get<2>(id_1333) };
                                        v_2da729c5f96e51679cb6e2c06e6ceb25 id_1335 { std::get<6>(id_1334) };
                                        t* id_1336 { id_1335.time };
                                        dc31f5cc689133a6f12d16478388e785 id_1337 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1338 { std::get<5>(id_1337) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1339 { std::get<2>(id_1338) };
                                        v_2da729c5f96e51679cb6e2c06e6ceb25 id_1340 { std::get<6>(id_1339) };
                                        t* id_1341 { id_1340.by };
                                        dc31f5cc689133a6f12d16478388e785 id_1342 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1343 { std::get<5>(id_1342) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1344 { std::get<2>(id_1343) };
                                        v_2da729c5f96e51679cb6e2c06e6ceb25 id_1345 { std::get<6>(id_1344) };
                                        t* id_1346 { id_1345.what };
                                        dc31f5cc689133a6f12d16478388e785 id_1347 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1348 { std::get<5>(id_1347) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1349 { std::get<2>(id_1348) };
                                        v_2da729c5f96e51679cb6e2c06e6ceb25 id_1350 { std::get<6>(id_1349) };
                                        t* id_1351 { id_1350.size };
                                        std::function<Pointer(dessser::gen::raql_top_output::t,Pointer)> id_1352 { dessser::gen::raql_top_output::to_row_binary };
                                        dc31f5cc689133a6f12d16478388e785 id_1353 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1354 { std::get<5>(id_1353) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1355 { std::get<2>(id_1354) };
                                        v_2da729c5f96e51679cb6e2c06e6ceb25 id_1356 { std::get<6>(id_1355) };
                                        dessser::gen::raql_top_output::t id_1357 { id_1356.output };
                                        Pointer id_1358 { id_1352(id_1357, ssum_dst_1175) };
                                        Pointer id_1359 { fun0(id_1351, id_1358) };
                                        Pointer let_res_1360;
                                        {
                                          Pointer srec_dst_1181 { id_1359 };
                                          dc31f5cc689133a6f12d16478388e785 id_1361 { p_0.text };
                                          v_58c653b3fc47800248b5c8f49e80fabb id_1362 { std::get<5>(id_1361) };
                                          v_2a737e40b715df686303c32fcaefae73 id_1363 { std::get<2>(id_1362) };
                                          v_2da729c5f96e51679cb6e2c06e6ceb25 id_1364 { std::get<6>(id_1363) };
                                          std::optional<t*> id_1365 { id_1364.max_size };
                                          bool id_1366 { !(id_1365.has_value ()) };
                                          Pointer choose_res_1367;
                                          if (id_1366) {
                                            uint8_t id_1368 { 1 };
                                            Pointer id_1369 { srec_dst_1181.writeU8(id_1368) };
                                            choose_res_1367 = id_1369;
                                          } else {
                                            dc31f5cc689133a6f12d16478388e785 id_1370 { p_0.text };
                                            v_58c653b3fc47800248b5c8f49e80fabb id_1371 { std::get<5>(id_1370) };
                                            v_2a737e40b715df686303c32fcaefae73 id_1372 { std::get<2>(id_1371) };
                                            v_2da729c5f96e51679cb6e2c06e6ceb25 id_1373 { std::get<6>(id_1372) };
                                            std::optional<t*> id_1374 { id_1373.max_size };
                                            t* id_1375 { id_1374.value() };
                                            uint8_t id_1376 { 0 };
                                            Pointer id_1377 { srec_dst_1181.writeU8(id_1376) };
                                            Pointer id_1378 { fun0(id_1375, id_1377) };
                                            choose_res_1367 = id_1378;
                                          }
                                          let_res_1360 = choose_res_1367;
                                        }
                                        Pointer id_1379 { fun0(id_1346, let_res_1360) };
                                        Pointer id_1380 { fun0(id_1341, id_1379) };
                                        Pointer id_1381 { fun0(id_1336, id_1380) };
                                        Pointer id_1382 { fun0(id_1331, id_1381) };
                                        Pointer id_1383 { fun0(id_1326, id_1382) };
                                        choose_res_1321 = id_1383;
                                      } else {
                                        uint16_t id_1384 { 7 };
                                        bool id_1385 { bool(label1_1174 == id_1384) };
                                        Void id_1386 { ((void)(assert(id_1385)), VOID) };
                                        dc31f5cc689133a6f12d16478388e785 id_1387 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1388 { std::get<5>(id_1387) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1389 { std::get<2>(id_1388) };
                                        v_148d37e471eb6790a77b16fc96041a20 id_1390 { std::get<7>(id_1389) };
                                        t* id_1391 { id_1390.max_age };
                                        dc31f5cc689133a6f12d16478388e785 id_1392 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1393 { std::get<5>(id_1392) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1394 { std::get<2>(id_1393) };
                                        v_148d37e471eb6790a77b16fc96041a20 id_1395 { std::get<7>(id_1394) };
                                        t* id_1396 { id_1395.time };
                                        dc31f5cc689133a6f12d16478388e785 id_1397 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1398 { std::get<5>(id_1397) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1399 { std::get<2>(id_1398) };
                                        v_148d37e471eb6790a77b16fc96041a20 id_1400 { std::get<7>(id_1399) };
                                        t* id_1401 { id_1400.what };
                                        Pointer id_1402 { fun0(id_1401, ssum_dst_1175) };
                                        Pointer id_1403 { fun0(id_1396, id_1402) };
                                        Pointer id_1404 { fun0(id_1391, id_1403) };
                                        dc31f5cc689133a6f12d16478388e785 id_1405 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_1406 { std::get<5>(id_1405) };
                                        v_2a737e40b715df686303c32fcaefae73 id_1407 { std::get<2>(id_1406) };
                                        v_148d37e471eb6790a77b16fc96041a20 id_1408 { std::get<7>(id_1407) };
                                        bool id_1409 { id_1408.tumbling };
                                        uint8_t id_1410 { uint8_t(id_1409) };
                                        Pointer id_1411 { id_1404.writeU8(id_1410) };
                                        Pointer let_res_1412;
                                        {
                                          Pointer srec_dst_1179 { id_1411 };
                                          dc31f5cc689133a6f12d16478388e785 id_1413 { p_0.text };
                                          v_58c653b3fc47800248b5c8f49e80fabb id_1414 { std::get<5>(id_1413) };
                                          v_2a737e40b715df686303c32fcaefae73 id_1415 { std::get<2>(id_1414) };
                                          v_148d37e471eb6790a77b16fc96041a20 id_1416 { std::get<7>(id_1415) };
                                          std::optional<t*> id_1417 { id_1416.sample_size };
                                          bool id_1418 { !(id_1417.has_value ()) };
                                          Pointer choose_res_1419;
                                          if (id_1418) {
                                            uint8_t id_1420 { 1 };
                                            Pointer id_1421 { srec_dst_1179.writeU8(id_1420) };
                                            choose_res_1419 = id_1421;
                                          } else {
                                            dc31f5cc689133a6f12d16478388e785 id_1422 { p_0.text };
                                            v_58c653b3fc47800248b5c8f49e80fabb id_1423 { std::get<5>(id_1422) };
                                            v_2a737e40b715df686303c32fcaefae73 id_1424 { std::get<2>(id_1423) };
                                            v_148d37e471eb6790a77b16fc96041a20 id_1425 { std::get<7>(id_1424) };
                                            std::optional<t*> id_1426 { id_1425.sample_size };
                                            t* id_1427 { id_1426.value() };
                                            uint8_t id_1428 { 0 };
                                            Pointer id_1429 { srec_dst_1179.writeU8(id_1428) };
                                            Pointer id_1430 { fun0(id_1427, id_1429) };
                                            choose_res_1419 = id_1430;
                                          }
                                          let_res_1412 = choose_res_1419;
                                        }
                                        choose_res_1321 = let_res_1412;
                                      }
                                      choose_res_1265 = choose_res_1321;
                                    }
                                    choose_res_1134 = choose_res_1265;
                                  }
                                  choose_res_1073 = choose_res_1134;
                                }
                                choose_res_1026 = choose_res_1073;
                              }
                              choose_res_990 = choose_res_1026;
                            }
                            choose_res_899 = choose_res_990;
                          }
                          let_res_896 = choose_res_899;
                        }
                        let_res_894 = let_res_896;
                      }
                      let_res_889 = let_res_894;
                    }
                    choose_res_862 = let_res_889;
                  } else {
                    uint16_t id_1431 { 6 };
                    bool id_1432 { bool(label1_1165 == id_1431) };
                    Void id_1433 { ((void)(assert(id_1432)), VOID) };
                    dc31f5cc689133a6f12d16478388e785 id_1434 { p_0.text };
                    v_1c5224020b28e5bf4853392434fd6e31 id_1435 { std::get<6>(id_1434) };
                    uint16_t id_1436 { uint16_t(id_1435.index()) };
                    Pointer id_1437 { ssum_dst_1166.writeU16Le(id_1436) };
                    Pointer let_res_1438;
                    {
                      Pointer ssum_dst_1168 { id_1437 };
                      dc31f5cc689133a6f12d16478388e785 id_1439 { p_0.text };
                      v_1c5224020b28e5bf4853392434fd6e31 id_1440 { std::get<6>(id_1439) };
                      uint16_t id_1441 { uint16_t(id_1440.index()) };
                      uint16_t id_1442 { 0 };
                      bool id_1443 { bool(id_1441 == id_1442) };
                      Void id_1444 { ((void)(assert(id_1443)), VOID) };
                      dc31f5cc689133a6f12d16478388e785 id_1445 { p_0.text };
                      v_1c5224020b28e5bf4853392434fd6e31 id_1446 { std::get<6>(id_1445) };
                      v_88361d7e3c5fc5844d2ff9213ba400b1 id_1447 { std::get<0>(id_1446) };
                      t* id_1448 { std::get<1>(id_1447) };
                      dc31f5cc689133a6f12d16478388e785 id_1449 { p_0.text };
                      v_1c5224020b28e5bf4853392434fd6e31 id_1450 { std::get<6>(id_1449) };
                      v_88361d7e3c5fc5844d2ff9213ba400b1 id_1451 { std::get<0>(id_1450) };
                      t* id_1452 { std::get<0>(id_1451) };
                      Pointer id_1453 { fun0(id_1452, ssum_dst_1168) };
                      Pointer id_1454 { fun0(id_1448, id_1453) };
                      let_res_1438 = id_1454;
                    }
                    choose_res_862 = let_res_1438;
                  }
                  choose_res_277 = choose_res_862;
                }
                choose_res_196 = choose_res_277;
              }
              choose_res_135 = choose_res_196;
            }
            choose_res_69 = choose_res_135;
          }
          choose_res_8 = choose_res_69;
        }
        let_res_5 = choose_res_8;
      }
      let_res_3 = let_res_5;
    }
    Pointer let_res_1455;
    {
      Pointer srec_dst_1286 { let_res_3 };
      uint32_t id_1456 { p_0.uniq_num };
      Pointer id_1457 { srec_dst_1286.writeU32Le(id_1456) };
      let_res_1455 = id_1457;
    }
    Pointer let_res_1458;
    {
      Pointer srec_dst_1287 { let_res_1455 };
      std::function<Pointer(dessser::gen::raql_type::t,Pointer)> id_1459 { dessser::gen::raql_type::to_row_binary };
      dessser::gen::raql_type::t id_1460 { p_0.typ };
      Pointer id_1461 { id_1459(id_1460, srec_dst_1287) };
      let_res_1458 = id_1461;
    }
    Pointer let_res_1462;
    {
      Pointer srec_dst_1288 { let_res_1458 };
      std::optional<dessser::gen::units::t> id_1463 { p_0.units };
      bool id_1464 { !(id_1463.has_value ()) };
      Pointer choose_res_1465;
      if (id_1464) {
        uint8_t id_1466 { 1 };
        Pointer id_1467 { srec_dst_1288.writeU8(id_1466) };
        choose_res_1465 = id_1467;
      } else {
        std::function<Pointer(dessser::gen::units::t,Pointer)> id_1468 { dessser::gen::units::to_row_binary };
        std::optional<dessser::gen::units::t> id_1469 { p_0.units };
        dessser::gen::units::t id_1470 { id_1469.value() };
        uint8_t id_1471 { 0 };
        Pointer id_1472 { srec_dst_1288.writeU8(id_1471) };
        Pointer id_1473 { id_1468(id_1470, id_1472) };
        choose_res_1465 = id_1473;
      }
      let_res_1462 = choose_res_1465;
    }
    return let_res_1462;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{text: [Tuple THIS[[]] | Record ($field_name; THIS)[[]] | Vector THIS[[]] | Case ({case_cond: THIS; case_cons: THIS}[[]]; THIS?) | Stateless [SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)] | Stateful ([LocalState Void | GlobalState Void]; BOOL; [SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]) | Generator [Split (THIS; THIS)]]; uniq_num: U32; typ: $raql_type; units: $units?}")
      (let "sz_1164"
        (let "sz_1163"
          (add
            (let "sz_1045" (size 0)
              (let "label2_1046" (label-of (get-field "text" (param 0)))
                (if (eq (u16 0) (identifier "label2_1046"))
                  (let "sz_ref_1160"
                    (make-vec
                      (add (add (identifier "sz_1045") (size 2))
                        (let "n_ref_1158" (make-vec (cardinality (get-alt "Tuple" (get-field "text" (param 0)))))
                          (let "lebsz_ref_1159" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_1158")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_1159")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_1159") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_1159")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_1159"))))))))
                    (seq
                      (let "repeat_n_1161" (make-vec (i32 0))
                        (while (gt (to-i32 (cardinality (get-alt "Tuple" (get-field "text" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_1161")))
                          (seq
                            (set-vec (u8 0) (identifier "sz_ref_1160")
                              (add (unsafe-nth (u8 0) (identifier "sz_ref_1160")) (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_1161")) (get-alt "Tuple" (get-field "text" (param 0)))))))
                            (set-vec (u8 0) (identifier "repeat_n_1161") (add (unsafe-nth (u8 0) (identifier "repeat_n_1161")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "sz_ref_1160"))))
                  (if (eq (u16 1) (identifier "label2_1046"))
                    (let "sz_ref_1154"
                      (make-vec
                        (add (add (identifier "sz_1045") (size 2))
                          (let "n_ref_1152" (make-vec (cardinality (get-alt "Record" (get-field "text" (param 0)))))
                            (let "lebsz_ref_1153" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_1152")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_1153")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_1153") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_1153")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_1153"))))))))
                      (seq
                        (let "repeat_n_1155" (make-vec (i32 0))
                          (while (gt (to-i32 (cardinality (get-alt "Record" (get-field "text" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_1155")))
                            (seq
                              (set-vec (u8 0) (identifier "sz_ref_1154")
                                (let "sz_1157"
                                  (let "sz_1156" (unsafe-nth (u8 0) (identifier "sz_ref_1154"))
                                    (add (identifier "sz_1156")
                                      (apply (ext-identifier field_name sersize-of-row-binary) (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_1155")) (get-alt "Record" (get-field "text" (param 0))))))))
                                  (add (identifier "sz_1157") (apply (myself "Size") (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_1155")) (get-alt "Record" (get-field "text" (param 0)))))))))
                              (set-vec (u8 0) (identifier "repeat_n_1155") (add (unsafe-nth (u8 0) (identifier "repeat_n_1155")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "sz_ref_1154"))))
                    (if (eq (u16 2) (identifier "label2_1046"))
                      (let "sz_ref_1150"
                        (make-vec
                          (add (add (identifier "sz_1045") (size 2))
                            (let "n_ref_1148" (make-vec (cardinality (get-alt "Vector" (get-field "text" (param 0)))))
                              (let "lebsz_ref_1149" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_1148")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_1149")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_1149") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_1149")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_1149"))))))))
                        (seq
                          (let "repeat_n_1151" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-alt "Vector" (get-field "text" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_1151")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_1150")
                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_1150")) (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_1151")) (get-alt "Vector" (get-field "text" (param 0)))))))
                                (set-vec (u8 0) (identifier "repeat_n_1151") (add (unsafe-nth (u8 0) (identifier "repeat_n_1151")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_1150"))))
                      (if (eq (u16 3) (identifier "label2_1046"))
                        (let "sz_1147"
                          (let "sz_ref_1143"
                            (make-vec
                              (add (add (identifier "sz_1045") (size 2))
                                (let "n_ref_1141" (make-vec (cardinality (get-item 0 (get-alt "Case" (get-field "text" (param 0))))))
                                  (let "lebsz_ref_1142" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_1141")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_1142")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_1142") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_1142")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_1142"))))))))
                            (seq
                              (let "repeat_n_1144" (make-vec (i32 0))
                                (while (gt (to-i32 (cardinality (get-item 0 (get-alt "Case" (get-field "text" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_1144")))
                                  (seq
                                    (set-vec (u8 0) (identifier "sz_ref_1143")
                                      (add
                                        (add (unsafe-nth (u8 0) (identifier "sz_ref_1143"))
                                          (apply (myself "Size") (get-field "case_cond" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_1144")) (get-item 0 (get-alt "Case" (get-field "text" (param 0))))))))
                                        (apply (myself "Size") (get-field "case_cons" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_1144")) (get-item 0 (get-alt "Case" (get-field "text" (param 0)))))))))
                                    (set-vec (u8 0) (identifier "repeat_n_1144") (add (unsafe-nth (u8 0) (identifier "repeat_n_1144")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "sz_ref_1143"))))
                          (if (is-null (get-item 1 (get-alt "Case" (get-field "text" (param 0))))) 
                            (add (identifier "sz_1147") (size 1)) (add (add (identifier "sz_1147") (apply (myself "Size") (force (get-item 1 (get-alt "Case" (get-field "text" (param 0))))))) (size 1))))
                        (if (eq (u16 4) (identifier "label2_1046"))
                          (if (eq (u16 0) (label-of (get-alt "Stateless" (get-field "text" (param 0)))))
                            (let "label2_1135" (label-of (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0)))))
                              (if (eq (u16 0) (identifier "label2_1135"))
                                (add (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                  (apply (ext-identifier raql_value sersize-of-row-binary) (get-alt "Const" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                (if (eq (u16 1) (identifier "label2_1135"))
                                  (add (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                    (apply (ext-identifier raql_variable sersize-of-row-binary) (get-alt "Variable" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                  (if (eq (u16 2) (identifier "label2_1135"))
                                    (add (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                      (apply (ext-identifier raql_binding_key sersize-of-row-binary) (get-alt "Binding" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                    (if (eq (u16 3) (identifier "label2_1135")) 
                                      (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                      (if (eq (u16 4) (identifier "label2_1135")) 
                                        (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                        (if (eq (u16 5) (identifier "label2_1135")) 
                                          (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                          (if (eq (u16 6) (identifier "label2_1135")) 
                                            (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                            (if (eq (u16 7) (identifier "label2_1135"))
                                              (let "sz_ref_1138"
                                                (make-vec
                                                  (add (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                                    (let "n_ref_1136" 
                                                      (make-vec (cardinality (get-alt "Path" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                                      (let "lebsz_ref_1137" 
                                                        (make-vec (u32 1))
                                                        (seq
                                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_1136")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_1137")) (u8 7)))
                                                            (set-vec (u8 0) (identifier "lebsz_ref_1137") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_1137")) (u32 1))))
                                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_1137"))))))))
                                                (seq
                                                  (let "repeat_n_1139" 
                                                    (make-vec (i32 0))
                                                    (while (gt (to-i32 (cardinality (get-alt "Path" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0))))))) (unsafe-nth (u8 0) (identifier "repeat_n_1139")))
                                                      (seq
                                                        (set-vec (u8 0) 
                                                          (identifier "sz_ref_1138")
                                                          (add (unsafe-nth (u8 0) (identifier "sz_ref_1138"))
                                                            (apply (ext-identifier raql_path_comp sersize-of-row-binary)
                                                              (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_1139")) (get-alt "Path" (get-alt "SL0" (get-alt "Stateless" (get-field "text" (param 0)))))))))
                                                        (set-vec (u8 0) (identifier "repeat_n_1139") (add (unsafe-nth (u8 0) (identifier "repeat_n_1139")) (i32 1)))))) 
                                                  (unsafe-nth (u8 0) (identifier "sz_ref_1138")))) 
                                              (seq (assert (eq (identifier "label2_1135") (u16 8))) (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))))))))))))
                            (if (eq (u16 1) (label-of (get-alt "Stateless" (get-field "text" (param 0)))))
                              (add
                                (let "sz_1126" (add (add (identifier "sz_1045") (size 2)) (size 2))
                                  (let "label2_1127" (label-of (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))
                                    (if (eq (u16 0) (identifier "label2_1127")) 
                                      (add (identifier "sz_1126") (size 2))
                                      (if (eq (u16 1) (identifier "label2_1127"))
                                        (add (add (identifier "sz_1126") (size 2))
                                          (apply (ext-identifier raql_type sersize-of-row-binary) (get-alt "Cast" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))))
                                        (if (eq (u16 2) (identifier "label2_1127")) 
                                          (add (identifier "sz_1126") (size 2))
                                          (if (eq (u16 3) (identifier "label2_1127"))
                                            (let "sz_1132"
                                              (add (add (identifier "sz_1126") (size 2))
                                                (apply (ext-identifier raql_type sersize-of-row-binary) (get-item 0 (get-alt "Peek" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0)))))))))
                                              (if (eq (u16 0) (label-of (get-item 1 (get-alt "Peek" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))))) 
                                                (add (identifier "sz_1132") (size 2))
                                                (seq (assert (eq (label-of (get-item 1 (get-alt "Peek" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0)))))))) (u16 1)))
                                                  (add (identifier "sz_1132") (size 2)))))
                                            (if (eq (u16 4) (identifier "label2_1127")) 
                                              (add (identifier "sz_1126") (size 2))
                                              (if (eq (u16 5) (identifier "label2_1127")) 
                                                (add (identifier "sz_1126") (size 2))
                                                (if (eq (u16 6) (identifier "label2_1127")) 
                                                  (add (identifier "sz_1126") (size 2))
                                                  (if (eq (u16 7) (identifier "label2_1127")) 
                                                    (add (identifier "sz_1126") (size 2))
                                                    (if (eq (u16 8) (identifier "label2_1127")) 
                                                      (add (identifier "sz_1126") (size 2))
                                                      (if (eq (u16 9) (identifier "label2_1127")) 
                                                        (add (identifier "sz_1126") (size 2))
                                                        (if (eq (u16 10) (identifier "label2_1127")) 
                                                          (add (identifier "sz_1126") (size 2))
                                                          (if (eq (u16 11) (identifier "label2_1127")) 
                                                            (add (identifier "sz_1126") (size 2))
                                                            (if (eq (u16 12) (identifier "label2_1127")) 
                                                              (add (identifier "sz_1126") (size 2))
                                                              (if (eq (u16 13) (identifier "label2_1127")) 
                                                                (add (identifier "sz_1126") (size 2))
                                                                (if (eq (u16 14) (identifier "label2_1127")) 
                                                                  (add (identifier "sz_1126") (size 2))
                                                                  (if 
                                                                    (eq (u16 15) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 16) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 17) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 18) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 19) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 20) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 21) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 22) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 23) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 24) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 25) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 26) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 27) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 28) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 35) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 36) (identifier "label2_1127"))
                                                                    (add 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (add
                                                                    (let "n_ref_1129" 
                                                                    (make-vec (string-length (get-alt "Like" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))))
                                                                    (let "lebsz_ref_1130" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_1129")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_1130")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_1130") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_1130")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_1130"))))))
                                                                    (size-of-u32 (string-length (get-alt "Like" (get-item 0 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0))))))))))
                                                                    (if 
                                                                    (eq (u16 37) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 38) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2))
                                                                    (if 
                                                                    (eq (u16 39) (identifier "label2_1127")) 
                                                                    (add (identifier "sz_1126") (size 2)) 
                                                                    (seq (assert (eq (identifier "label2_1127") (u16 40))) (add (identifier "sz_1126") (size 2)))))))))))))))))))))))))))))))))))))))))))))
                                (apply (myself "Size") (get-item 1 (get-alt "SL1" (get-alt "Stateless" (get-field "text" (param 0)))))))
                              (if (eq (u16 2) (label-of (get-alt "Stateless" (get-field "text" (param 0)))))
                                (let "sz_1121"
                                  (let "label2_1120" (label-of (get-item 0 (get-alt "SL1s" (get-alt "Stateless" (get-field "text" (param 0))))))
                                    (if (eq (u16 0) (identifier "label2_1120")) 
                                      (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                      (if (eq (u16 1) (identifier "label2_1120")) 
                                        (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                        (if (eq (u16 2) (identifier "label2_1120")) 
                                          (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                          (seq (assert (eq (identifier "label2_1120") (u16 3))) (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2)))))))
                                  (let "sz_ref_1124"
                                    (make-vec
                                      (add (identifier "sz_1121")
                                        (let "n_ref_1122" (make-vec (cardinality (get-item 1 (get-alt "SL1s" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                          (let "lebsz_ref_1123" (make-vec (u32 1))
                                            (seq
                                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_1122")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_1123")) (u8 7)))
                                                (set-vec (u8 0) (identifier "lebsz_ref_1123") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_1123")) (u32 1)))) 
                                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_1123"))))))))
                                    (seq
                                      (let "repeat_n_1125" (make-vec (i32 0))
                                        (while (gt (to-i32 (cardinality (get-item 1 (get-alt "SL1s" (get-alt "Stateless" (get-field "text" (param 0))))))) (unsafe-nth (u8 0) (identifier "repeat_n_1125")))
                                          (seq
                                            (set-vec (u8 0) (identifier "sz_ref_1124")
                                              (add (unsafe-nth (u8 0) (identifier "sz_ref_1124"))
                                                (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_1125")) (get-item 1 (get-alt "SL1s" (get-alt "Stateless" (get-field "text" (param 0)))))))))
                                            (set-vec (u8 0) (identifier "repeat_n_1125") (add (unsafe-nth (u8 0) (identifier "repeat_n_1125")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "sz_ref_1124")))))
                                (if (eq (u16 3) (label-of (get-alt "Stateless" (get-field "text" (param 0)))))
                                  (add
                                    (add
                                      (let "sz_1115" (add (add (identifier "sz_1045") (size 2)) (size 2))
                                        (let "label2_1116" (label-of (get-item 0 (get-alt "SL2" (get-alt "Stateless" (get-field "text" (param 0))))))
                                          (if (eq (u16 0) (identifier "label2_1116")) 
                                            (add (identifier "sz_1115") (size 2))
                                            (if (eq (u16 1) (identifier "label2_1116")) 
                                              (add (identifier "sz_1115") (size 2))
                                              (if (eq (u16 2) (identifier "label2_1116")) 
                                                (add (identifier "sz_1115") (size 2))
                                                (if (eq (u16 3) (identifier "label2_1116")) 
                                                  (add (identifier "sz_1115") (size 2))
                                                  (if (eq (u16 4) (identifier "label2_1116")) 
                                                    (add (identifier "sz_1115") (size 2))
                                                    (if (eq (u16 5) (identifier "label2_1116")) 
                                                      (add (identifier "sz_1115") (size 2))
                                                      (if (eq (u16 6) (identifier "label2_1116")) 
                                                        (add (identifier "sz_1115") (size 2))
                                                        (if (eq (u16 7) (identifier "label2_1116")) 
                                                          (add (identifier "sz_1115") (size 2))
                                                          (if (eq (u16 8) (identifier "label2_1116")) 
                                                            (add (identifier "sz_1115") (size 2))
                                                            (if (eq (u16 9) (identifier "label2_1116")) 
                                                              (add (identifier "sz_1115") (size 2))
                                                              (if (eq (u16 10) (identifier "label2_1116")) 
                                                                (add (identifier "sz_1115") (size 2))
                                                                (if (eq (u16 11) (identifier "label2_1116")) 
                                                                  (add (identifier "sz_1115") (size 2))
                                                                  (if 
                                                                    (eq (u16 12) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 13) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 14) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 15) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 16) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 17) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 18) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 19) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 20) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 21) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 22) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 23) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2))
                                                                    (if 
                                                                    (eq (u16 24) (identifier "label2_1116")) 
                                                                    (add (identifier "sz_1115") (size 2)) 
                                                                    (seq (assert (eq (identifier "label2_1116") (u16 25))) (add (identifier "sz_1115") (size 2))))))))))))))))))))))))))))))
                                      (apply (myself "Size") (get-item 1 (get-alt "SL2" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                    (apply (myself "Size") (get-item 2 (get-alt "SL2" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                  (seq (assert (eq (label-of (get-alt "Stateless" (get-field "text" (param 0)))) (u16 4)))
                                    (add
                                      (add
                                        (add
                                          (if (eq (u16 0) (label-of (get-item 0 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0))))))) 
                                            (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2))
                                            (seq (assert (eq (label-of (get-item 0 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0)))))) (u16 1)))
                                              (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (size 2)))) 
                                          (apply (myself "Size") (get-item 1 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                        (apply (myself "Size") (get-item 2 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0)))))))
                                      (apply (myself "Size") (get-item 3 (get-alt "SL3" (get-alt "Stateless" (get-field "text" (param 0))))))))))))
                          (if (eq (u16 5) (identifier "label2_1046"))
                            (let "sz_1053"
                              (add
                                (if (eq (u16 0) (label-of (get-item 0 (get-alt "Stateful" (get-field "text" (param 0)))))) 
                                  (add (add (identifier "sz_1045") (size 2)) (size 2))
                                  (seq (assert (eq (label-of (get-item 0 (get-alt "Stateful" (get-field "text" (param 0))))) (u16 1))) (add (add (identifier "sz_1045") (size 2)) (size 2)))) 
                                (size 1))
                              (let "label2_1054" (label-of (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))
                                (if (eq (u16 0) (identifier "label2_1054"))
                                  (add
                                    (let "sz_1103" (add (identifier "sz_1053") (size 2))
                                      (let "label2_1104" (label-of (get-item 0 (get-alt "SF1" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))
                                        (if (eq (u16 0) (identifier "label2_1104")) 
                                          (add (identifier "sz_1103") (size 2))
                                          (if (eq (u16 1) (identifier "label2_1104")) 
                                            (add (identifier "sz_1103") (size 2))
                                            (if (eq (u16 2) (identifier "label2_1104")) 
                                              (add (identifier "sz_1103") (size 2))
                                              (if (eq (u16 3) (identifier "label2_1104")) 
                                                (add (identifier "sz_1103") (size 2))
                                                (if (eq (u16 4) (identifier "label2_1104")) 
                                                  (add (identifier "sz_1103") (size 2))
                                                  (if (eq (u16 5) (identifier "label2_1104")) 
                                                    (add (identifier "sz_1103") (size 2))
                                                    (if (eq (u16 6) (identifier "label2_1104")) 
                                                      (add (identifier "sz_1103") (size 2))
                                                      (if (eq (u16 7) (identifier "label2_1104")) 
                                                        (add (identifier "sz_1103") (size 2))
                                                        (if (eq (u16 8) (identifier "label2_1104")) 
                                                          (add (identifier "sz_1103") (size 2))
                                                          (if (eq (u16 9) (identifier "label2_1104")) 
                                                            (add (identifier "sz_1103") (size 2))
                                                            (if (eq (u16 10) (identifier "label2_1104")) 
                                                              (add (identifier "sz_1103") (size 2))
                                                              (if (eq (u16 11) (identifier "label2_1104")) 
                                                                (add (add (add (add (identifier "sz_1103") (size 2)) (size 8)) (size 8)) (size 4))
                                                                (if (eq (u16 12) (identifier "label2_1104")) 
                                                                  (add (identifier "sz_1103") (size 2))
                                                                  (if 
                                                                    (eq (u16 13) (identifier "label2_1104")) 
                                                                    (add (identifier "sz_1103") (size 2)) 
                                                                    (seq (assert (eq (identifier "label2_1104") (u16 14))) (add (identifier "sz_1103") (size 2)))))))))))))))))))
                                    (apply (myself "Size") (get-item 1 (get-alt "SF1" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                  (if (eq (u16 1) (identifier "label2_1054"))
                                    (add
                                      (add
                                        (let "label2_1100" (label-of (get-item 0 (get-alt "SF2" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))
                                          (if (eq (u16 0) (identifier "label2_1100")) 
                                            (add (add (identifier "sz_1053") (size 2)) (size 2))
                                            (if (eq (u16 1) (identifier "label2_1100")) 
                                              (add (add (identifier "sz_1053") (size 2)) (size 2))
                                              (if (eq (u16 2) (identifier "label2_1100")) 
                                                (add (add (identifier "sz_1053") (size 2)) (size 2)) 
                                                (seq (assert (eq (identifier "label2_1100") (u16 3))) (add (add (identifier "sz_1053") (size 2)) (size 2)))))))
                                        (apply (myself "Size") (get-item 1 (get-alt "SF2" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                      (apply (myself "Size") (get-item 2 (get-alt "SF2" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                    (if (eq (u16 2) (identifier "label2_1054"))
                                      (add
                                        (add
                                          (add
                                            (if (eq (u16 0) (label-of (get-item 0 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))) 
                                              (add (add (identifier "sz_1053") (size 2)) (size 2))
                                              (if (eq (u16 1) (label-of (get-item 0 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))) 
                                                (add (add (identifier "sz_1053") (size 2)) (size 2))
                                                (seq (assert (eq (label-of (get-item 0 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) (u16 2)))
                                                  (add (add (add (identifier "sz_1053") (size 2)) (size 2)) (size 1)))))
                                            (apply (myself "Size") (get-item 1 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                          (apply (myself "Size") (get-item 2 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                        (apply (myself "Size") (get-item 3 (get-alt "SF3" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                      (if (eq (u16 3) (identifier "label2_1054"))
                                        (add
                                          (add
                                            (add
                                              (add
                                                (if (eq (u16 0) (label-of (get-item 0 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))) 
                                                  (add (add (identifier "sz_1053") (size 2)) (size 2))
                                                  (seq (assert (eq (label-of (get-item 0 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) (u16 1)))
                                                    (add (add (add (identifier "sz_1053") (size 2)) (size 2)) (size 1))))
                                                (apply (myself "Size") (get-item 1 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                              (apply (myself "Size") (get-item 2 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                            (apply (myself "Size") (get-item 3 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                          (apply (myself "Size") (get-item 4 (get-alt "SF4" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                        (if (eq (u16 4) (identifier "label2_1054"))
                                          (let "sz_1083"
                                            (add
                                              (add
                                                (add
                                                  (if (eq (u16 0) (label-of (get-item 0 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))) 
                                                    (add (add (identifier "sz_1053") (size 2)) (size 2))
                                                    (seq (assert (eq (label-of (get-item 0 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) (u16 1)))
                                                      (add (add (add (add (identifier "sz_1053") (size 2)) (size 2)) (size 1)) (size 1))))
                                                  (apply (myself "Size") (get-item 1 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                (apply (myself "Size") (get-item 2 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                              (apply (myself "Size") (get-item 3 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                            (let "sz_ref_1086"
                                              (make-vec
                                                (add (identifier "sz_1083")
                                                  (let "n_ref_1084" (make-vec (cardinality (get-item 4 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                    (let "lebsz_ref_1085" 
                                                      (make-vec (u32 1))
                                                      (seq
                                                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_1084")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_1085")) (u8 7)))
                                                          (set-vec (u8 0) (identifier "lebsz_ref_1085") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_1085")) (u32 1))))
                                                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_1085"))))))))
                                              (seq
                                                (let "repeat_n_1087" 
                                                  (make-vec (i32 0))
                                                  (while (gt (to-i32 (cardinality (get-item 4 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))) (unsafe-nth (u8 0) (identifier "repeat_n_1087")))
                                                    (seq
                                                      (set-vec (u8 0) 
                                                        (identifier "sz_ref_1086")
                                                        (add (unsafe-nth (u8 0) (identifier "sz_ref_1086"))
                                                          (apply (myself "Size")
                                                            (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_1087")) (get-item 4 (get-alt "SF4s" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))))
                                                      (set-vec (u8 0) (identifier "repeat_n_1087") (add (unsafe-nth (u8 0) (identifier "repeat_n_1087")) (i32 1)))))) 
                                                (unsafe-nth (u8 0) (identifier "sz_ref_1086")))))
                                          (if (eq (u16 5) (identifier "label2_1054"))
                                            (add
                                              (add
                                                (add
                                                  (add
                                                    (add
                                                      (add
                                                        (seq (assert (eq (label-of (get-item 0 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) (u16 0)))
                                                          (add (add (identifier "sz_1053") (size 2)) (size 2))) 
                                                        (apply (myself "Size") (get-item 1 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                      (apply (myself "Size") (get-item 2 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                    (apply (myself "Size") (get-item 3 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                  (apply (myself "Size") (get-item 4 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                (apply (myself "Size") (get-item 5 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                              (apply (myself "Size") (get-item 6 (get-alt "SF6" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                            (if (eq (u16 6) (identifier "label2_1054"))
                                              (add
                                                (add
                                                  (add
                                                    (add
                                                      (add
                                                        (let "sz_1062"
                                                          (add
                                                            (add (add (identifier "sz_1053") (size 2))
                                                              (apply (ext-identifier raql_top_output sersize-of-row-binary) (get-field "output" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                            (apply (myself "Size") (get-field "size" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                          (if (is-null (get-field "max_size" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) 
                                                            (add (identifier "sz_1062") (size 1))
                                                            (add (add (identifier "sz_1062") (apply (myself "Size") (force (get-field "max_size" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))))
                                                              (size 1)))) 
                                                        (apply (myself "Size") (get-field "what" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                      (apply (myself "Size") (get-field "by" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                    (apply (myself "Size") (get-field "time" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                  (apply (myself "Size") (get-field "duration" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                (apply (myself "Size") (get-field "sigmas" (get-alt "Top" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                              (seq (assert (eq (identifier "label2_1054") (u16 7)))
                                                (let "sz_1059"
                                                  (add
                                                    (add
                                                      (add (add (add (identifier "sz_1053") (size 2)) (apply (myself "Size") (get-field "what" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                        (apply (myself "Size") (get-field "time" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))))
                                                      (apply (myself "Size") (get-field "max_age" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))) 
                                                    (size 1))
                                                  (if (is-null (get-field "sample_size" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0))))))) 
                                                    (add (identifier "sz_1059") (size 1))
                                                    (add (add (identifier "sz_1059") (apply (myself "Size") (force (get-field "sample_size" (get-alt "Past" (get-item 2 (get-alt "Stateful" (get-field "text" (param 0)))))))))
                                                      (size 1))))))))))))))
                            (seq (assert (eq (identifier "label2_1046") (u16 6)))
                              (seq (assert (eq (label-of (get-alt "Generator" (get-field "text" (param 0)))) (u16 0)))
                                (add (add (add (add (identifier "sz_1045") (size 2)) (size 2)) (apply (myself "Size") (get-item 0 (get-alt "Split" (get-alt "Generator" (get-field "text" (param 0)))))))
                                  (apply (myself "Size") (get-item 1 (get-alt "Split" (get-alt "Generator" (get-field "text" (param 0))))))))))))))))) 
            (size 4)) (add (identifier "sz_1163") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "typ" (param 0)))))
        (if (is-null (get-field "units" (param 0))) (add (identifier "sz_1164") (size 1)) (add (add (identifier "sz_1164") (apply (ext-identifier units sersize-of-row-binary) (force (get-field "units" (param 0))))) (size 1)))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun1474 { [&fun1474](t p_0) {
    Size id_1475 { 0UL };
    Size let_res_1476;
    {
      Size sz_1045 { id_1475 };
      dc31f5cc689133a6f12d16478388e785 id_1477 { p_0.text };
      uint16_t id_1478 { uint16_t(id_1477.index()) };
      Size let_res_1479;
      {
        uint16_t label2_1046 { id_1478 };
        uint16_t id_1480 { 0 };
        bool id_1481 { bool(id_1480 == label2_1046) };
        Size choose_res_1482;
        if (id_1481) {
          Size id_1483 { 2UL };
          Size id_1484 { Size(sz_1045 + id_1483) };
          dc31f5cc689133a6f12d16478388e785 id_1485 { p_0.text };
          Lst<t*> id_1486 { std::get<0>(id_1485) };
          uint32_t id_1487 { id_1486.size() };
          Vec<1, uint32_t> id_1488 {  id_1487  };
          Size let_res_1489;
          {
            Vec<1, uint32_t> n_ref_1158 { id_1488 };
            uint32_t id_1490 { 1U };
            Vec<1, uint32_t> id_1491 {  id_1490  };
            Size let_res_1492;
            {
              Vec<1, uint32_t> lebsz_ref_1159 { id_1491 };
              bool while_flag_1493 { true };
              do {
                uint8_t id_1494 { 0 };
                uint32_t id_1495 { n_ref_1158[id_1494] };
                uint8_t id_1496 { 0 };
                uint32_t id_1497 { lebsz_ref_1159[id_1496] };
                uint8_t id_1498 { 7 };
                uint32_t id_1499 { uint32_t(id_1497 << id_1498) };
                bool id_1500 { bool(id_1495 >= id_1499) };
                while_flag_1493 = id_1500;
                if (while_flag_1493) {
                  uint8_t id_1501 { 0 };
                  uint8_t id_1502 { 0 };
                  uint32_t id_1503 { lebsz_ref_1159[id_1502] };
                  uint32_t id_1504 { 1U };
                  uint32_t id_1505 { uint32_t(id_1503 + id_1504) };
                  Void id_1506 { ((void)(lebsz_ref_1159[id_1501] = id_1505), VOID) };
                }
              } while (while_flag_1493);
              uint8_t id_1507 { 0 };
              uint32_t id_1508 { lebsz_ref_1159[id_1507] };
              Size id_1509 { Size(id_1508) };
              let_res_1492 = id_1509;
            }
            let_res_1489 = let_res_1492;
          }
          Size id_1510 { Size(id_1484 + let_res_1489) };
          Vec<1, Size> id_1511 {  id_1510  };
          Size let_res_1512;
          {
            Vec<1, Size> sz_ref_1160 { id_1511 };
            int32_t id_1513 { 0L };
            Vec<1, int32_t> id_1514 {  id_1513  };
            {
              Vec<1, int32_t> repeat_n_1161 { id_1514 };
              bool while_flag_1515 { true };
              do {
                dc31f5cc689133a6f12d16478388e785 id_1516 { p_0.text };
                Lst<t*> id_1517 { std::get<0>(id_1516) };
                uint32_t id_1518 { id_1517.size() };
                int32_t id_1519 { int32_t(id_1518) };
                uint8_t id_1520 { 0 };
                int32_t id_1521 { repeat_n_1161[id_1520] };
                bool id_1522 { bool(id_1519 > id_1521) };
                while_flag_1515 = id_1522;
                if (while_flag_1515) {
                  uint8_t id_1523 { 0 };
                  uint8_t id_1524 { 0 };
                  Size id_1525 { sz_ref_1160[id_1524] };
                  uint8_t id_1526 { 0 };
                  int32_t id_1527 { repeat_n_1161[id_1526] };
                  dc31f5cc689133a6f12d16478388e785 id_1528 { p_0.text };
                  Lst<t*> id_1529 { std::get<0>(id_1528) };
                  t* id_1530 { id_1529[id_1527] };
                  Size id_1531 { fun1474(id_1530) };
                  Size id_1532 { Size(id_1525 + id_1531) };
                  Void id_1533 { ((void)(sz_ref_1160[id_1523] = id_1532), VOID) };
                  uint8_t id_1534 { 0 };
                  uint8_t id_1535 { 0 };
                  int32_t id_1536 { repeat_n_1161[id_1535] };
                  int32_t id_1537 { 1L };
                  int32_t id_1538 { int32_t(id_1536 + id_1537) };
                  Void id_1539 { ((void)(repeat_n_1161[id_1534] = id_1538), VOID) };
                }
              } while (while_flag_1515);
            }
            uint8_t id_1540 { 0 };
            Size id_1541 { sz_ref_1160[id_1540] };
            let_res_1512 = id_1541;
          }
          choose_res_1482 = let_res_1512;
        } else {
          uint16_t id_1542 { 1 };
          bool id_1543 { bool(id_1542 == label2_1046) };
          Size choose_res_1544;
          if (id_1543) {
            Size id_1545 { 2UL };
            Size id_1546 { Size(sz_1045 + id_1545) };
            dc31f5cc689133a6f12d16478388e785 id_1547 { p_0.text };
            Lst<v_4ec9e9432e07cae1458c03426a194a1a> id_1548 { std::get<1>(id_1547) };
            uint32_t id_1549 { id_1548.size() };
            Vec<1, uint32_t> id_1550 {  id_1549  };
            Size let_res_1551;
            {
              Vec<1, uint32_t> n_ref_1152 { id_1550 };
              uint32_t id_1552 { 1U };
              Vec<1, uint32_t> id_1553 {  id_1552  };
              Size let_res_1554;
              {
                Vec<1, uint32_t> lebsz_ref_1153 { id_1553 };
                bool while_flag_1555 { true };
                do {
                  uint8_t id_1556 { 0 };
                  uint32_t id_1557 { n_ref_1152[id_1556] };
                  uint8_t id_1558 { 0 };
                  uint32_t id_1559 { lebsz_ref_1153[id_1558] };
                  uint8_t id_1560 { 7 };
                  uint32_t id_1561 { uint32_t(id_1559 << id_1560) };
                  bool id_1562 { bool(id_1557 >= id_1561) };
                  while_flag_1555 = id_1562;
                  if (while_flag_1555) {
                    uint8_t id_1563 { 0 };
                    uint8_t id_1564 { 0 };
                    uint32_t id_1565 { lebsz_ref_1153[id_1564] };
                    uint32_t id_1566 { 1U };
                    uint32_t id_1567 { uint32_t(id_1565 + id_1566) };
                    Void id_1568 { ((void)(lebsz_ref_1153[id_1563] = id_1567), VOID) };
                  }
                } while (while_flag_1555);
                uint8_t id_1569 { 0 };
                uint32_t id_1570 { lebsz_ref_1153[id_1569] };
                Size id_1571 { Size(id_1570) };
                let_res_1554 = id_1571;
              }
              let_res_1551 = let_res_1554;
            }
            Size id_1572 { Size(id_1546 + let_res_1551) };
            Vec<1, Size> id_1573 {  id_1572  };
            Size let_res_1574;
            {
              Vec<1, Size> sz_ref_1154 { id_1573 };
              int32_t id_1575 { 0L };
              Vec<1, int32_t> id_1576 {  id_1575  };
              {
                Vec<1, int32_t> repeat_n_1155 { id_1576 };
                bool while_flag_1577 { true };
                do {
                  dc31f5cc689133a6f12d16478388e785 id_1578 { p_0.text };
                  Lst<v_4ec9e9432e07cae1458c03426a194a1a> id_1579 { std::get<1>(id_1578) };
                  uint32_t id_1580 { id_1579.size() };
                  int32_t id_1581 { int32_t(id_1580) };
                  uint8_t id_1582 { 0 };
                  int32_t id_1583 { repeat_n_1155[id_1582] };
                  bool id_1584 { bool(id_1581 > id_1583) };
                  while_flag_1577 = id_1584;
                  if (while_flag_1577) {
                    uint8_t id_1585 { 0 };
                    uint8_t id_1586 { 0 };
                    Size id_1587 { sz_ref_1154[id_1586] };
                    Size let_res_1588;
                    {
                      Size sz_1156 { id_1587 };
                      std::function<Size(dessser::gen::field_name::t)> id_1589 { dessser::gen::field_name::sersize_of_row_binary };
                      uint8_t id_1590 { 0 };
                      int32_t id_1591 { repeat_n_1155[id_1590] };
                      dc31f5cc689133a6f12d16478388e785 id_1592 { p_0.text };
                      Lst<v_4ec9e9432e07cae1458c03426a194a1a> id_1593 { std::get<1>(id_1592) };
                      v_4ec9e9432e07cae1458c03426a194a1a id_1594 { id_1593[id_1591] };
                      dessser::gen::field_name::t id_1595 { std::get<0>(id_1594) };
                      Size id_1596 { id_1589(id_1595) };
                      Size id_1597 { Size(sz_1156 + id_1596) };
                      let_res_1588 = id_1597;
                    }
                    Size let_res_1598;
                    {
                      Size sz_1157 { let_res_1588 };
                      uint8_t id_1599 { 0 };
                      int32_t id_1600 { repeat_n_1155[id_1599] };
                      dc31f5cc689133a6f12d16478388e785 id_1601 { p_0.text };
                      Lst<v_4ec9e9432e07cae1458c03426a194a1a> id_1602 { std::get<1>(id_1601) };
                      v_4ec9e9432e07cae1458c03426a194a1a id_1603 { id_1602[id_1600] };
                      t* id_1604 { std::get<1>(id_1603) };
                      Size id_1605 { fun1474(id_1604) };
                      Size id_1606 { Size(sz_1157 + id_1605) };
                      let_res_1598 = id_1606;
                    }
                    Void id_1607 { ((void)(sz_ref_1154[id_1585] = let_res_1598), VOID) };
                    uint8_t id_1608 { 0 };
                    uint8_t id_1609 { 0 };
                    int32_t id_1610 { repeat_n_1155[id_1609] };
                    int32_t id_1611 { 1L };
                    int32_t id_1612 { int32_t(id_1610 + id_1611) };
                    Void id_1613 { ((void)(repeat_n_1155[id_1608] = id_1612), VOID) };
                  }
                } while (while_flag_1577);
              }
              uint8_t id_1614 { 0 };
              Size id_1615 { sz_ref_1154[id_1614] };
              let_res_1574 = id_1615;
            }
            choose_res_1544 = let_res_1574;
          } else {
            uint16_t id_1616 { 2 };
            bool id_1617 { bool(id_1616 == label2_1046) };
            Size choose_res_1618;
            if (id_1617) {
              Size id_1619 { 2UL };
              Size id_1620 { Size(sz_1045 + id_1619) };
              dc31f5cc689133a6f12d16478388e785 id_1621 { p_0.text };
              Lst<t*> id_1622 { std::get<2>(id_1621) };
              uint32_t id_1623 { id_1622.size() };
              Vec<1, uint32_t> id_1624 {  id_1623  };
              Size let_res_1625;
              {
                Vec<1, uint32_t> n_ref_1148 { id_1624 };
                uint32_t id_1626 { 1U };
                Vec<1, uint32_t> id_1627 {  id_1626  };
                Size let_res_1628;
                {
                  Vec<1, uint32_t> lebsz_ref_1149 { id_1627 };
                  bool while_flag_1629 { true };
                  do {
                    uint8_t id_1630 { 0 };
                    uint32_t id_1631 { n_ref_1148[id_1630] };
                    uint8_t id_1632 { 0 };
                    uint32_t id_1633 { lebsz_ref_1149[id_1632] };
                    uint8_t id_1634 { 7 };
                    uint32_t id_1635 { uint32_t(id_1633 << id_1634) };
                    bool id_1636 { bool(id_1631 >= id_1635) };
                    while_flag_1629 = id_1636;
                    if (while_flag_1629) {
                      uint8_t id_1637 { 0 };
                      uint8_t id_1638 { 0 };
                      uint32_t id_1639 { lebsz_ref_1149[id_1638] };
                      uint32_t id_1640 { 1U };
                      uint32_t id_1641 { uint32_t(id_1639 + id_1640) };
                      Void id_1642 { ((void)(lebsz_ref_1149[id_1637] = id_1641), VOID) };
                    }
                  } while (while_flag_1629);
                  uint8_t id_1643 { 0 };
                  uint32_t id_1644 { lebsz_ref_1149[id_1643] };
                  Size id_1645 { Size(id_1644) };
                  let_res_1628 = id_1645;
                }
                let_res_1625 = let_res_1628;
              }
              Size id_1646 { Size(id_1620 + let_res_1625) };
              Vec<1, Size> id_1647 {  id_1646  };
              Size let_res_1648;
              {
                Vec<1, Size> sz_ref_1150 { id_1647 };
                int32_t id_1649 { 0L };
                Vec<1, int32_t> id_1650 {  id_1649  };
                {
                  Vec<1, int32_t> repeat_n_1151 { id_1650 };
                  bool while_flag_1651 { true };
                  do {
                    dc31f5cc689133a6f12d16478388e785 id_1652 { p_0.text };
                    Lst<t*> id_1653 { std::get<2>(id_1652) };
                    uint32_t id_1654 { id_1653.size() };
                    int32_t id_1655 { int32_t(id_1654) };
                    uint8_t id_1656 { 0 };
                    int32_t id_1657 { repeat_n_1151[id_1656] };
                    bool id_1658 { bool(id_1655 > id_1657) };
                    while_flag_1651 = id_1658;
                    if (while_flag_1651) {
                      uint8_t id_1659 { 0 };
                      uint8_t id_1660 { 0 };
                      Size id_1661 { sz_ref_1150[id_1660] };
                      uint8_t id_1662 { 0 };
                      int32_t id_1663 { repeat_n_1151[id_1662] };
                      dc31f5cc689133a6f12d16478388e785 id_1664 { p_0.text };
                      Lst<t*> id_1665 { std::get<2>(id_1664) };
                      t* id_1666 { id_1665[id_1663] };
                      Size id_1667 { fun1474(id_1666) };
                      Size id_1668 { Size(id_1661 + id_1667) };
                      Void id_1669 { ((void)(sz_ref_1150[id_1659] = id_1668), VOID) };
                      uint8_t id_1670 { 0 };
                      uint8_t id_1671 { 0 };
                      int32_t id_1672 { repeat_n_1151[id_1671] };
                      int32_t id_1673 { 1L };
                      int32_t id_1674 { int32_t(id_1672 + id_1673) };
                      Void id_1675 { ((void)(repeat_n_1151[id_1670] = id_1674), VOID) };
                    }
                  } while (while_flag_1651);
                }
                uint8_t id_1676 { 0 };
                Size id_1677 { sz_ref_1150[id_1676] };
                let_res_1648 = id_1677;
              }
              choose_res_1618 = let_res_1648;
            } else {
              uint16_t id_1678 { 3 };
              bool id_1679 { bool(id_1678 == label2_1046) };
              Size choose_res_1680;
              if (id_1679) {
                Size id_1681 { 2UL };
                Size id_1682 { Size(sz_1045 + id_1681) };
                dc31f5cc689133a6f12d16478388e785 id_1683 { p_0.text };
                v_7df1ef9c4e82bfdd017031822619493c id_1684 { std::get<3>(id_1683) };
                Lst<a1a2ab208d8a8e56a609f18e422bdf88> id_1685 { std::get<0>(id_1684) };
                uint32_t id_1686 { id_1685.size() };
                Vec<1, uint32_t> id_1687 {  id_1686  };
                Size let_res_1688;
                {
                  Vec<1, uint32_t> n_ref_1141 { id_1687 };
                  uint32_t id_1689 { 1U };
                  Vec<1, uint32_t> id_1690 {  id_1689  };
                  Size let_res_1691;
                  {
                    Vec<1, uint32_t> lebsz_ref_1142 { id_1690 };
                    bool while_flag_1692 { true };
                    do {
                      uint8_t id_1693 { 0 };
                      uint32_t id_1694 { n_ref_1141[id_1693] };
                      uint8_t id_1695 { 0 };
                      uint32_t id_1696 { lebsz_ref_1142[id_1695] };
                      uint8_t id_1697 { 7 };
                      uint32_t id_1698 { uint32_t(id_1696 << id_1697) };
                      bool id_1699 { bool(id_1694 >= id_1698) };
                      while_flag_1692 = id_1699;
                      if (while_flag_1692) {
                        uint8_t id_1700 { 0 };
                        uint8_t id_1701 { 0 };
                        uint32_t id_1702 { lebsz_ref_1142[id_1701] };
                        uint32_t id_1703 { 1U };
                        uint32_t id_1704 { uint32_t(id_1702 + id_1703) };
                        Void id_1705 { ((void)(lebsz_ref_1142[id_1700] = id_1704), VOID) };
                      }
                    } while (while_flag_1692);
                    uint8_t id_1706 { 0 };
                    uint32_t id_1707 { lebsz_ref_1142[id_1706] };
                    Size id_1708 { Size(id_1707) };
                    let_res_1691 = id_1708;
                  }
                  let_res_1688 = let_res_1691;
                }
                Size id_1709 { Size(id_1682 + let_res_1688) };
                Vec<1, Size> id_1710 {  id_1709  };
                Size let_res_1711;
                {
                  Vec<1, Size> sz_ref_1143 { id_1710 };
                  int32_t id_1712 { 0L };
                  Vec<1, int32_t> id_1713 {  id_1712  };
                  {
                    Vec<1, int32_t> repeat_n_1144 { id_1713 };
                    bool while_flag_1714 { true };
                    do {
                      dc31f5cc689133a6f12d16478388e785 id_1715 { p_0.text };
                      v_7df1ef9c4e82bfdd017031822619493c id_1716 { std::get<3>(id_1715) };
                      Lst<a1a2ab208d8a8e56a609f18e422bdf88> id_1717 { std::get<0>(id_1716) };
                      uint32_t id_1718 { id_1717.size() };
                      int32_t id_1719 { int32_t(id_1718) };
                      uint8_t id_1720 { 0 };
                      int32_t id_1721 { repeat_n_1144[id_1720] };
                      bool id_1722 { bool(id_1719 > id_1721) };
                      while_flag_1714 = id_1722;
                      if (while_flag_1714) {
                        uint8_t id_1723 { 0 };
                        uint8_t id_1724 { 0 };
                        Size id_1725 { sz_ref_1143[id_1724] };
                        uint8_t id_1726 { 0 };
                        int32_t id_1727 { repeat_n_1144[id_1726] };
                        dc31f5cc689133a6f12d16478388e785 id_1728 { p_0.text };
                        v_7df1ef9c4e82bfdd017031822619493c id_1729 { std::get<3>(id_1728) };
                        Lst<a1a2ab208d8a8e56a609f18e422bdf88> id_1730 { std::get<0>(id_1729) };
                        a1a2ab208d8a8e56a609f18e422bdf88 id_1731 { id_1730[id_1727] };
                        t* id_1732 { id_1731.case_cond };
                        Size id_1733 { fun1474(id_1732) };
                        Size id_1734 { Size(id_1725 + id_1733) };
                        uint8_t id_1735 { 0 };
                        int32_t id_1736 { repeat_n_1144[id_1735] };
                        dc31f5cc689133a6f12d16478388e785 id_1737 { p_0.text };
                        v_7df1ef9c4e82bfdd017031822619493c id_1738 { std::get<3>(id_1737) };
                        Lst<a1a2ab208d8a8e56a609f18e422bdf88> id_1739 { std::get<0>(id_1738) };
                        a1a2ab208d8a8e56a609f18e422bdf88 id_1740 { id_1739[id_1736] };
                        t* id_1741 { id_1740.case_cons };
                        Size id_1742 { fun1474(id_1741) };
                        Size id_1743 { Size(id_1734 + id_1742) };
                        Void id_1744 { ((void)(sz_ref_1143[id_1723] = id_1743), VOID) };
                        uint8_t id_1745 { 0 };
                        uint8_t id_1746 { 0 };
                        int32_t id_1747 { repeat_n_1144[id_1746] };
                        int32_t id_1748 { 1L };
                        int32_t id_1749 { int32_t(id_1747 + id_1748) };
                        Void id_1750 { ((void)(repeat_n_1144[id_1745] = id_1749), VOID) };
                      }
                    } while (while_flag_1714);
                  }
                  uint8_t id_1751 { 0 };
                  Size id_1752 { sz_ref_1143[id_1751] };
                  let_res_1711 = id_1752;
                }
                Size let_res_1753;
                {
                  Size sz_1147 { let_res_1711 };
                  dc31f5cc689133a6f12d16478388e785 id_1754 { p_0.text };
                  v_7df1ef9c4e82bfdd017031822619493c id_1755 { std::get<3>(id_1754) };
                  std::optional<t*> id_1756 { std::get<1>(id_1755) };
                  bool id_1757 { !(id_1756.has_value ()) };
                  Size choose_res_1758;
                  if (id_1757) {
                    Size id_1759 { 1UL };
                    Size id_1760 { Size(sz_1147 + id_1759) };
                    choose_res_1758 = id_1760;
                  } else {
                    dc31f5cc689133a6f12d16478388e785 id_1761 { p_0.text };
                    v_7df1ef9c4e82bfdd017031822619493c id_1762 { std::get<3>(id_1761) };
                    std::optional<t*> id_1763 { std::get<1>(id_1762) };
                    t* id_1764 { id_1763.value() };
                    Size id_1765 { fun1474(id_1764) };
                    Size id_1766 { Size(sz_1147 + id_1765) };
                    Size id_1767 { 1UL };
                    Size id_1768 { Size(id_1766 + id_1767) };
                    choose_res_1758 = id_1768;
                  }
                  let_res_1753 = choose_res_1758;
                }
                choose_res_1680 = let_res_1753;
              } else {
                uint16_t id_1769 { 4 };
                bool id_1770 { bool(id_1769 == label2_1046) };
                Size choose_res_1771;
                if (id_1770) {
                  uint16_t id_1772 { 0 };
                  dc31f5cc689133a6f12d16478388e785 id_1773 { p_0.text };
                  a481e1e269544fa0efe70fc68e01b3bb id_1774 { std::get<4>(id_1773) };
                  uint16_t id_1775 { uint16_t(id_1774.index()) };
                  bool id_1776 { bool(id_1772 == id_1775) };
                  Size choose_res_1777;
                  if (id_1776) {
                    dc31f5cc689133a6f12d16478388e785 id_1778 { p_0.text };
                    a481e1e269544fa0efe70fc68e01b3bb id_1779 { std::get<4>(id_1778) };
                    b02d571406bf80b296e55bb93213ea59 id_1780 { std::get<0>(id_1779) };
                    uint16_t id_1781 { uint16_t(id_1780.index()) };
                    Size let_res_1782;
                    {
                      uint16_t label2_1135 { id_1781 };
                      uint16_t id_1783 { 0 };
                      bool id_1784 { bool(id_1783 == label2_1135) };
                      Size choose_res_1785;
                      if (id_1784) {
                        Size id_1786 { 2UL };
                        Size id_1787 { Size(sz_1045 + id_1786) };
                        Size id_1788 { 2UL };
                        Size id_1789 { Size(id_1787 + id_1788) };
                        Size id_1790 { 2UL };
                        Size id_1791 { Size(id_1789 + id_1790) };
                        std::function<Size(dessser::gen::raql_value::t)> id_1792 { dessser::gen::raql_value::sersize_of_row_binary };
                        dc31f5cc689133a6f12d16478388e785 id_1793 { p_0.text };
                        a481e1e269544fa0efe70fc68e01b3bb id_1794 { std::get<4>(id_1793) };
                        b02d571406bf80b296e55bb93213ea59 id_1795 { std::get<0>(id_1794) };
                        dessser::gen::raql_value::t id_1796 { std::get<0>(id_1795) };
                        Size id_1797 { id_1792(id_1796) };
                        Size id_1798 { Size(id_1791 + id_1797) };
                        choose_res_1785 = id_1798;
                      } else {
                        uint16_t id_1799 { 1 };
                        bool id_1800 { bool(id_1799 == label2_1135) };
                        Size choose_res_1801;
                        if (id_1800) {
                          Size id_1802 { 2UL };
                          Size id_1803 { Size(sz_1045 + id_1802) };
                          Size id_1804 { 2UL };
                          Size id_1805 { Size(id_1803 + id_1804) };
                          Size id_1806 { 2UL };
                          Size id_1807 { Size(id_1805 + id_1806) };
                          std::function<Size(dessser::gen::raql_variable::t)> id_1808 { dessser::gen::raql_variable::sersize_of_row_binary };
                          dc31f5cc689133a6f12d16478388e785 id_1809 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_1810 { std::get<4>(id_1809) };
                          b02d571406bf80b296e55bb93213ea59 id_1811 { std::get<0>(id_1810) };
                          dessser::gen::raql_variable::t id_1812 { std::get<1>(id_1811) };
                          Size id_1813 { id_1808(id_1812) };
                          Size id_1814 { Size(id_1807 + id_1813) };
                          choose_res_1801 = id_1814;
                        } else {
                          uint16_t id_1815 { 2 };
                          bool id_1816 { bool(id_1815 == label2_1135) };
                          Size choose_res_1817;
                          if (id_1816) {
                            Size id_1818 { 2UL };
                            Size id_1819 { Size(sz_1045 + id_1818) };
                            Size id_1820 { 2UL };
                            Size id_1821 { Size(id_1819 + id_1820) };
                            Size id_1822 { 2UL };
                            Size id_1823 { Size(id_1821 + id_1822) };
                            std::function<Size(dessser::gen::raql_binding_key::t)> id_1824 { dessser::gen::raql_binding_key::sersize_of_row_binary };
                            dc31f5cc689133a6f12d16478388e785 id_1825 { p_0.text };
                            a481e1e269544fa0efe70fc68e01b3bb id_1826 { std::get<4>(id_1825) };
                            b02d571406bf80b296e55bb93213ea59 id_1827 { std::get<0>(id_1826) };
                            dessser::gen::raql_binding_key::t id_1828 { std::get<2>(id_1827) };
                            Size id_1829 { id_1824(id_1828) };
                            Size id_1830 { Size(id_1823 + id_1829) };
                            choose_res_1817 = id_1830;
                          } else {
                            uint16_t id_1831 { 3 };
                            bool id_1832 { bool(id_1831 == label2_1135) };
                            Size choose_res_1833;
                            if (id_1832) {
                              Size id_1834 { 2UL };
                              Size id_1835 { Size(sz_1045 + id_1834) };
                              Size id_1836 { 2UL };
                              Size id_1837 { Size(id_1835 + id_1836) };
                              Size id_1838 { 2UL };
                              Size id_1839 { Size(id_1837 + id_1838) };
                              choose_res_1833 = id_1839;
                            } else {
                              uint16_t id_1840 { 4 };
                              bool id_1841 { bool(id_1840 == label2_1135) };
                              Size choose_res_1842;
                              if (id_1841) {
                                Size id_1843 { 2UL };
                                Size id_1844 { Size(sz_1045 + id_1843) };
                                Size id_1845 { 2UL };
                                Size id_1846 { Size(id_1844 + id_1845) };
                                Size id_1847 { 2UL };
                                Size id_1848 { Size(id_1846 + id_1847) };
                                choose_res_1842 = id_1848;
                              } else {
                                uint16_t id_1849 { 5 };
                                bool id_1850 { bool(id_1849 == label2_1135) };
                                Size choose_res_1851;
                                if (id_1850) {
                                  Size id_1852 { 2UL };
                                  Size id_1853 { Size(sz_1045 + id_1852) };
                                  Size id_1854 { 2UL };
                                  Size id_1855 { Size(id_1853 + id_1854) };
                                  Size id_1856 { 2UL };
                                  Size id_1857 { Size(id_1855 + id_1856) };
                                  choose_res_1851 = id_1857;
                                } else {
                                  uint16_t id_1858 { 6 };
                                  bool id_1859 { bool(id_1858 == label2_1135) };
                                  Size choose_res_1860;
                                  if (id_1859) {
                                    Size id_1861 { 2UL };
                                    Size id_1862 { Size(sz_1045 + id_1861) };
                                    Size id_1863 { 2UL };
                                    Size id_1864 { Size(id_1862 + id_1863) };
                                    Size id_1865 { 2UL };
                                    Size id_1866 { Size(id_1864 + id_1865) };
                                    choose_res_1860 = id_1866;
                                  } else {
                                    uint16_t id_1867 { 7 };
                                    bool id_1868 { bool(id_1867 == label2_1135) };
                                    Size choose_res_1869;
                                    if (id_1868) {
                                      Size id_1870 { 2UL };
                                      Size id_1871 { Size(sz_1045 + id_1870) };
                                      Size id_1872 { 2UL };
                                      Size id_1873 { Size(id_1871 + id_1872) };
                                      Size id_1874 { 2UL };
                                      Size id_1875 { Size(id_1873 + id_1874) };
                                      dc31f5cc689133a6f12d16478388e785 id_1876 { p_0.text };
                                      a481e1e269544fa0efe70fc68e01b3bb id_1877 { std::get<4>(id_1876) };
                                      b02d571406bf80b296e55bb93213ea59 id_1878 { std::get<0>(id_1877) };
                                      Lst<dessser::gen::raql_path_comp::t> id_1879 { std::get<7>(id_1878) };
                                      uint32_t id_1880 { id_1879.size() };
                                      Vec<1, uint32_t> id_1881 {  id_1880  };
                                      Size let_res_1882;
                                      {
                                        Vec<1, uint32_t> n_ref_1136 { id_1881 };
                                        uint32_t id_1883 { 1U };
                                        Vec<1, uint32_t> id_1884 {  id_1883  };
                                        Size let_res_1885;
                                        {
                                          Vec<1, uint32_t> lebsz_ref_1137 { id_1884 };
                                          bool while_flag_1886 { true };
                                          do {
                                            uint8_t id_1887 { 0 };
                                            uint32_t id_1888 { n_ref_1136[id_1887] };
                                            uint8_t id_1889 { 0 };
                                            uint32_t id_1890 { lebsz_ref_1137[id_1889] };
                                            uint8_t id_1891 { 7 };
                                            uint32_t id_1892 { uint32_t(id_1890 << id_1891) };
                                            bool id_1893 { bool(id_1888 >= id_1892) };
                                            while_flag_1886 = id_1893;
                                            if (while_flag_1886) {
                                              uint8_t id_1894 { 0 };
                                              uint8_t id_1895 { 0 };
                                              uint32_t id_1896 { lebsz_ref_1137[id_1895] };
                                              uint32_t id_1897 { 1U };
                                              uint32_t id_1898 { uint32_t(id_1896 + id_1897) };
                                              Void id_1899 { ((void)(lebsz_ref_1137[id_1894] = id_1898), VOID) };
                                            }
                                          } while (while_flag_1886);
                                          uint8_t id_1900 { 0 };
                                          uint32_t id_1901 { lebsz_ref_1137[id_1900] };
                                          Size id_1902 { Size(id_1901) };
                                          let_res_1885 = id_1902;
                                        }
                                        let_res_1882 = let_res_1885;
                                      }
                                      Size id_1903 { Size(id_1875 + let_res_1882) };
                                      Vec<1, Size> id_1904 {  id_1903  };
                                      Size let_res_1905;
                                      {
                                        Vec<1, Size> sz_ref_1138 { id_1904 };
                                        int32_t id_1906 { 0L };
                                        Vec<1, int32_t> id_1907 {  id_1906  };
                                        {
                                          Vec<1, int32_t> repeat_n_1139 { id_1907 };
                                          bool while_flag_1908 { true };
                                          do {
                                            dc31f5cc689133a6f12d16478388e785 id_1909 { p_0.text };
                                            a481e1e269544fa0efe70fc68e01b3bb id_1910 { std::get<4>(id_1909) };
                                            b02d571406bf80b296e55bb93213ea59 id_1911 { std::get<0>(id_1910) };
                                            Lst<dessser::gen::raql_path_comp::t> id_1912 { std::get<7>(id_1911) };
                                            uint32_t id_1913 { id_1912.size() };
                                            int32_t id_1914 { int32_t(id_1913) };
                                            uint8_t id_1915 { 0 };
                                            int32_t id_1916 { repeat_n_1139[id_1915] };
                                            bool id_1917 { bool(id_1914 > id_1916) };
                                            while_flag_1908 = id_1917;
                                            if (while_flag_1908) {
                                              uint8_t id_1918 { 0 };
                                              uint8_t id_1919 { 0 };
                                              Size id_1920 { sz_ref_1138[id_1919] };
                                              std::function<Size(dessser::gen::raql_path_comp::t)> id_1921 { dessser::gen::raql_path_comp::sersize_of_row_binary };
                                              uint8_t id_1922 { 0 };
                                              int32_t id_1923 { repeat_n_1139[id_1922] };
                                              dc31f5cc689133a6f12d16478388e785 id_1924 { p_0.text };
                                              a481e1e269544fa0efe70fc68e01b3bb id_1925 { std::get<4>(id_1924) };
                                              b02d571406bf80b296e55bb93213ea59 id_1926 { std::get<0>(id_1925) };
                                              Lst<dessser::gen::raql_path_comp::t> id_1927 { std::get<7>(id_1926) };
                                              dessser::gen::raql_path_comp::t id_1928 { id_1927[id_1923] };
                                              Size id_1929 { id_1921(id_1928) };
                                              Size id_1930 { Size(id_1920 + id_1929) };
                                              Void id_1931 { ((void)(sz_ref_1138[id_1918] = id_1930), VOID) };
                                              uint8_t id_1932 { 0 };
                                              uint8_t id_1933 { 0 };
                                              int32_t id_1934 { repeat_n_1139[id_1933] };
                                              int32_t id_1935 { 1L };
                                              int32_t id_1936 { int32_t(id_1934 + id_1935) };
                                              Void id_1937 { ((void)(repeat_n_1139[id_1932] = id_1936), VOID) };
                                            }
                                          } while (while_flag_1908);
                                        }
                                        uint8_t id_1938 { 0 };
                                        Size id_1939 { sz_ref_1138[id_1938] };
                                        let_res_1905 = id_1939;
                                      }
                                      choose_res_1869 = let_res_1905;
                                    } else {
                                      uint16_t id_1940 { 8 };
                                      bool id_1941 { bool(label2_1135 == id_1940) };
                                      Void id_1942 { ((void)(assert(id_1941)), VOID) };
                                      Size id_1943 { 2UL };
                                      Size id_1944 { Size(sz_1045 + id_1943) };
                                      Size id_1945 { 2UL };
                                      Size id_1946 { Size(id_1944 + id_1945) };
                                      Size id_1947 { 2UL };
                                      Size id_1948 { Size(id_1946 + id_1947) };
                                      choose_res_1869 = id_1948;
                                    }
                                    choose_res_1860 = choose_res_1869;
                                  }
                                  choose_res_1851 = choose_res_1860;
                                }
                                choose_res_1842 = choose_res_1851;
                              }
                              choose_res_1833 = choose_res_1842;
                            }
                            choose_res_1817 = choose_res_1833;
                          }
                          choose_res_1801 = choose_res_1817;
                        }
                        choose_res_1785 = choose_res_1801;
                      }
                      let_res_1782 = choose_res_1785;
                    }
                    choose_res_1777 = let_res_1782;
                  } else {
                    uint16_t id_1949 { 1 };
                    dc31f5cc689133a6f12d16478388e785 id_1950 { p_0.text };
                    a481e1e269544fa0efe70fc68e01b3bb id_1951 { std::get<4>(id_1950) };
                    uint16_t id_1952 { uint16_t(id_1951.index()) };
                    bool id_1953 { bool(id_1949 == id_1952) };
                    Size choose_res_1954;
                    if (id_1953) {
                      Size id_1955 { 2UL };
                      Size id_1956 { Size(sz_1045 + id_1955) };
                      Size id_1957 { 2UL };
                      Size id_1958 { Size(id_1956 + id_1957) };
                      Size let_res_1959;
                      {
                        Size sz_1126 { id_1958 };
                        dc31f5cc689133a6f12d16478388e785 id_1960 { p_0.text };
                        a481e1e269544fa0efe70fc68e01b3bb id_1961 { std::get<4>(id_1960) };
                        v_86716e60fd92843b928cbb08bc52f333 id_1962 { std::get<1>(id_1961) };
                        v_1d6ee587a956ed7717b51cc22dd3b087 id_1963 { std::get<0>(id_1962) };
                        uint16_t id_1964 { uint16_t(id_1963.index()) };
                        Size let_res_1965;
                        {
                          uint16_t label2_1127 { id_1964 };
                          uint16_t id_1966 { 0 };
                          bool id_1967 { bool(id_1966 == label2_1127) };
                          Size choose_res_1968;
                          if (id_1967) {
                            Size id_1969 { 2UL };
                            Size id_1970 { Size(sz_1126 + id_1969) };
                            choose_res_1968 = id_1970;
                          } else {
                            uint16_t id_1971 { 1 };
                            bool id_1972 { bool(id_1971 == label2_1127) };
                            Size choose_res_1973;
                            if (id_1972) {
                              Size id_1974 { 2UL };
                              Size id_1975 { Size(sz_1126 + id_1974) };
                              std::function<Size(dessser::gen::raql_type::t)> id_1976 { dessser::gen::raql_type::sersize_of_row_binary };
                              dc31f5cc689133a6f12d16478388e785 id_1977 { p_0.text };
                              a481e1e269544fa0efe70fc68e01b3bb id_1978 { std::get<4>(id_1977) };
                              v_86716e60fd92843b928cbb08bc52f333 id_1979 { std::get<1>(id_1978) };
                              v_1d6ee587a956ed7717b51cc22dd3b087 id_1980 { std::get<0>(id_1979) };
                              dessser::gen::raql_type::t id_1981 { std::get<1>(id_1980) };
                              Size id_1982 { id_1976(id_1981) };
                              Size id_1983 { Size(id_1975 + id_1982) };
                              choose_res_1973 = id_1983;
                            } else {
                              uint16_t id_1984 { 2 };
                              bool id_1985 { bool(id_1984 == label2_1127) };
                              Size choose_res_1986;
                              if (id_1985) {
                                Size id_1987 { 2UL };
                                Size id_1988 { Size(sz_1126 + id_1987) };
                                choose_res_1986 = id_1988;
                              } else {
                                uint16_t id_1989 { 3 };
                                bool id_1990 { bool(id_1989 == label2_1127) };
                                Size choose_res_1991;
                                if (id_1990) {
                                  Size id_1992 { 2UL };
                                  Size id_1993 { Size(sz_1126 + id_1992) };
                                  std::function<Size(dessser::gen::raql_type::t)> id_1994 { dessser::gen::raql_type::sersize_of_row_binary };
                                  dc31f5cc689133a6f12d16478388e785 id_1995 { p_0.text };
                                  a481e1e269544fa0efe70fc68e01b3bb id_1996 { std::get<4>(id_1995) };
                                  v_86716e60fd92843b928cbb08bc52f333 id_1997 { std::get<1>(id_1996) };
                                  v_1d6ee587a956ed7717b51cc22dd3b087 id_1998 { std::get<0>(id_1997) };
                                  v_562760c1b2585f63d315bb555b64832c id_1999 { std::get<3>(id_1998) };
                                  dessser::gen::raql_type::t id_2000 { std::get<0>(id_1999) };
                                  Size id_2001 { id_1994(id_2000) };
                                  Size id_2002 { Size(id_1993 + id_2001) };
                                  Size let_res_2003;
                                  {
                                    Size sz_1132 { id_2002 };
                                    uint16_t id_2004 { 0 };
                                    dc31f5cc689133a6f12d16478388e785 id_2005 { p_0.text };
                                    a481e1e269544fa0efe70fc68e01b3bb id_2006 { std::get<4>(id_2005) };
                                    v_86716e60fd92843b928cbb08bc52f333 id_2007 { std::get<1>(id_2006) };
                                    v_1d6ee587a956ed7717b51cc22dd3b087 id_2008 { std::get<0>(id_2007) };
                                    v_562760c1b2585f63d315bb555b64832c id_2009 { std::get<3>(id_2008) };
                                    b31ee7e2e15bec4cfa9176ec3d86152e id_2010 { std::get<1>(id_2009) };
                                    uint16_t id_2011 { uint16_t(id_2010.index()) };
                                    bool id_2012 { bool(id_2004 == id_2011) };
                                    Size choose_res_2013;
                                    if (id_2012) {
                                      Size id_2014 { 2UL };
                                      Size id_2015 { Size(sz_1132 + id_2014) };
                                      choose_res_2013 = id_2015;
                                    } else {
                                      dc31f5cc689133a6f12d16478388e785 id_2016 { p_0.text };
                                      a481e1e269544fa0efe70fc68e01b3bb id_2017 { std::get<4>(id_2016) };
                                      v_86716e60fd92843b928cbb08bc52f333 id_2018 { std::get<1>(id_2017) };
                                      v_1d6ee587a956ed7717b51cc22dd3b087 id_2019 { std::get<0>(id_2018) };
                                      v_562760c1b2585f63d315bb555b64832c id_2020 { std::get<3>(id_2019) };
                                      b31ee7e2e15bec4cfa9176ec3d86152e id_2021 { std::get<1>(id_2020) };
                                      uint16_t id_2022 { uint16_t(id_2021.index()) };
                                      uint16_t id_2023 { 1 };
                                      bool id_2024 { bool(id_2022 == id_2023) };
                                      Void id_2025 { ((void)(assert(id_2024)), VOID) };
                                      Size id_2026 { 2UL };
                                      Size id_2027 { Size(sz_1132 + id_2026) };
                                      choose_res_2013 = id_2027;
                                    }
                                    let_res_2003 = choose_res_2013;
                                  }
                                  choose_res_1991 = let_res_2003;
                                } else {
                                  uint16_t id_2028 { 4 };
                                  bool id_2029 { bool(id_2028 == label2_1127) };
                                  Size choose_res_2030;
                                  if (id_2029) {
                                    Size id_2031 { 2UL };
                                    Size id_2032 { Size(sz_1126 + id_2031) };
                                    choose_res_2030 = id_2032;
                                  } else {
                                    uint16_t id_2033 { 5 };
                                    bool id_2034 { bool(id_2033 == label2_1127) };
                                    Size choose_res_2035;
                                    if (id_2034) {
                                      Size id_2036 { 2UL };
                                      Size id_2037 { Size(sz_1126 + id_2036) };
                                      choose_res_2035 = id_2037;
                                    } else {
                                      uint16_t id_2038 { 6 };
                                      bool id_2039 { bool(id_2038 == label2_1127) };
                                      Size choose_res_2040;
                                      if (id_2039) {
                                        Size id_2041 { 2UL };
                                        Size id_2042 { Size(sz_1126 + id_2041) };
                                        choose_res_2040 = id_2042;
                                      } else {
                                        uint16_t id_2043 { 7 };
                                        bool id_2044 { bool(id_2043 == label2_1127) };
                                        Size choose_res_2045;
                                        if (id_2044) {
                                          Size id_2046 { 2UL };
                                          Size id_2047 { Size(sz_1126 + id_2046) };
                                          choose_res_2045 = id_2047;
                                        } else {
                                          uint16_t id_2048 { 8 };
                                          bool id_2049 { bool(id_2048 == label2_1127) };
                                          Size choose_res_2050;
                                          if (id_2049) {
                                            Size id_2051 { 2UL };
                                            Size id_2052 { Size(sz_1126 + id_2051) };
                                            choose_res_2050 = id_2052;
                                          } else {
                                            uint16_t id_2053 { 9 };
                                            bool id_2054 { bool(id_2053 == label2_1127) };
                                            Size choose_res_2055;
                                            if (id_2054) {
                                              Size id_2056 { 2UL };
                                              Size id_2057 { Size(sz_1126 + id_2056) };
                                              choose_res_2055 = id_2057;
                                            } else {
                                              uint16_t id_2058 { 10 };
                                              bool id_2059 { bool(id_2058 == label2_1127) };
                                              Size choose_res_2060;
                                              if (id_2059) {
                                                Size id_2061 { 2UL };
                                                Size id_2062 { Size(sz_1126 + id_2061) };
                                                choose_res_2060 = id_2062;
                                              } else {
                                                uint16_t id_2063 { 11 };
                                                bool id_2064 { bool(id_2063 == label2_1127) };
                                                Size choose_res_2065;
                                                if (id_2064) {
                                                  Size id_2066 { 2UL };
                                                  Size id_2067 { Size(sz_1126 + id_2066) };
                                                  choose_res_2065 = id_2067;
                                                } else {
                                                  uint16_t id_2068 { 12 };
                                                  bool id_2069 { bool(id_2068 == label2_1127) };
                                                  Size choose_res_2070;
                                                  if (id_2069) {
                                                    Size id_2071 { 2UL };
                                                    Size id_2072 { Size(sz_1126 + id_2071) };
                                                    choose_res_2070 = id_2072;
                                                  } else {
                                                    uint16_t id_2073 { 13 };
                                                    bool id_2074 { bool(id_2073 == label2_1127) };
                                                    Size choose_res_2075;
                                                    if (id_2074) {
                                                      Size id_2076 { 2UL };
                                                      Size id_2077 { Size(sz_1126 + id_2076) };
                                                      choose_res_2075 = id_2077;
                                                    } else {
                                                      uint16_t id_2078 { 14 };
                                                      bool id_2079 { bool(id_2078 == label2_1127) };
                                                      Size choose_res_2080;
                                                      if (id_2079) {
                                                        Size id_2081 { 2UL };
                                                        Size id_2082 { Size(sz_1126 + id_2081) };
                                                        choose_res_2080 = id_2082;
                                                      } else {
                                                        uint16_t id_2083 { 15 };
                                                        bool id_2084 { bool(id_2083 == label2_1127) };
                                                        Size choose_res_2085;
                                                        if (id_2084) {
                                                          Size id_2086 { 2UL };
                                                          Size id_2087 { Size(sz_1126 + id_2086) };
                                                          choose_res_2085 = id_2087;
                                                        } else {
                                                          uint16_t id_2088 { 16 };
                                                          bool id_2089 { bool(id_2088 == label2_1127) };
                                                          Size choose_res_2090;
                                                          if (id_2089) {
                                                            Size id_2091 { 2UL };
                                                            Size id_2092 { Size(sz_1126 + id_2091) };
                                                            choose_res_2090 = id_2092;
                                                          } else {
                                                            uint16_t id_2093 { 17 };
                                                            bool id_2094 { bool(id_2093 == label2_1127) };
                                                            Size choose_res_2095;
                                                            if (id_2094) {
                                                              Size id_2096 { 2UL };
                                                              Size id_2097 { Size(sz_1126 + id_2096) };
                                                              choose_res_2095 = id_2097;
                                                            } else {
                                                              uint16_t id_2098 { 18 };
                                                              bool id_2099 { bool(id_2098 == label2_1127) };
                                                              Size choose_res_2100;
                                                              if (id_2099) {
                                                                Size id_2101 { 2UL };
                                                                Size id_2102 { Size(sz_1126 + id_2101) };
                                                                choose_res_2100 = id_2102;
                                                              } else {
                                                                uint16_t id_2103 { 19 };
                                                                bool id_2104 { bool(id_2103 == label2_1127) };
                                                                Size choose_res_2105;
                                                                if (id_2104) {
                                                                  Size id_2106 { 2UL };
                                                                  Size id_2107 { Size(sz_1126 + id_2106) };
                                                                  choose_res_2105 = id_2107;
                                                                } else {
                                                                  uint16_t id_2108 { 20 };
                                                                  bool id_2109 { bool(id_2108 == label2_1127) };
                                                                  Size choose_res_2110;
                                                                  if (id_2109) {
                                                                    Size id_2111 { 2UL };
                                                                    Size id_2112 { Size(sz_1126 + id_2111) };
                                                                    choose_res_2110 = id_2112;
                                                                  } else {
                                                                    uint16_t id_2113 { 21 };
                                                                    bool id_2114 { bool(id_2113 == label2_1127) };
                                                                    Size choose_res_2115;
                                                                    if (id_2114) {
                                                                      Size id_2116 { 2UL };
                                                                      Size id_2117 { Size(sz_1126 + id_2116) };
                                                                      choose_res_2115 = id_2117;
                                                                    } else {
                                                                      uint16_t id_2118 { 22 };
                                                                      bool id_2119 { bool(id_2118 == label2_1127) };
                                                                      Size choose_res_2120;
                                                                      if (id_2119) {
                                                                        Size id_2121 { 2UL };
                                                                        Size id_2122 { Size(sz_1126 + id_2121) };
                                                                        choose_res_2120 = id_2122;
                                                                      } else {
                                                                        uint16_t id_2123 { 23 };
                                                                        bool id_2124 { bool(id_2123 == label2_1127) };
                                                                        Size choose_res_2125;
                                                                        if (id_2124) {
                                                                          Size id_2126 { 2UL };
                                                                          Size id_2127 { Size(sz_1126 + id_2126) };
                                                                          choose_res_2125 = id_2127;
                                                                        } else {
                                                                          uint16_t id_2128 { 24 };
                                                                          bool id_2129 { bool(id_2128 == label2_1127) };
                                                                          Size choose_res_2130;
                                                                          if (id_2129) {
                                                                            Size id_2131 { 2UL };
                                                                            Size id_2132 { Size(sz_1126 + id_2131) };
                                                                            choose_res_2130 = id_2132;
                                                                          } else {
                                                                            uint16_t id_2133 { 25 };
                                                                            bool id_2134 { bool(id_2133 == label2_1127) };
                                                                            Size choose_res_2135;
                                                                            if (id_2134) {
                                                                              Size id_2136 { 2UL };
                                                                              Size id_2137 { Size(sz_1126 + id_2136) };
                                                                              choose_res_2135 = id_2137;
                                                                            } else {
                                                                              uint16_t id_2138 { 26 };
                                                                              bool id_2139 { bool(id_2138 == label2_1127) };
                                                                              Size choose_res_2140;
                                                                              if (id_2139) {
                                                                                Size id_2141 { 2UL };
                                                                                Size id_2142 { Size(sz_1126 + id_2141) };
                                                                                choose_res_2140 = id_2142;
                                                                              } else {
                                                                                uint16_t id_2143 { 27 };
                                                                                bool id_2144 { bool(id_2143 == label2_1127) };
                                                                                Size choose_res_2145;
                                                                                if (id_2144) {
                                                                                  Size id_2146 { 2UL };
                                                                                  Size id_2147 { Size(sz_1126 + id_2146) };
                                                                                  choose_res_2145 = id_2147;
                                                                                } else {
                                                                                  uint16_t id_2148 { 28 };
                                                                                  bool id_2149 { bool(id_2148 == label2_1127) };
                                                                                  Size choose_res_2150;
                                                                                  if (id_2149) {
                                                                                    Size id_2151 { 2UL };
                                                                                    Size id_2152 { Size(sz_1126 + id_2151) };
                                                                                    choose_res_2150 = id_2152;
                                                                                  } else {
                                                                                    uint16_t id_2153 { 29 };
                                                                                    bool id_2154 { bool(id_2153 == label2_1127) };
                                                                                    Size choose_res_2155;
                                                                                    if (id_2154) {
                                                                                      Size id_2156 { 2UL };
                                                                                      Size id_2157 { Size(sz_1126 + id_2156) };
                                                                                      choose_res_2155 = id_2157;
                                                                                    } else {
                                                                                      uint16_t id_2158 { 30 };
                                                                                      bool id_2159 { bool(id_2158 == label2_1127) };
                                                                                      Size choose_res_2160;
                                                                                      if (id_2159) {
                                                                                        Size id_2161 { 2UL };
                                                                                        Size id_2162 { Size(sz_1126 + id_2161) };
                                                                                        choose_res_2160 = id_2162;
                                                                                      } else {
                                                                                        uint16_t id_2163 { 31 };
                                                                                        bool id_2164 { bool(id_2163 == label2_1127) };
                                                                                        Size choose_res_2165;
                                                                                        if (id_2164) {
                                                                                          Size id_2166 { 2UL };
                                                                                          Size id_2167 { Size(sz_1126 + id_2166) };
                                                                                          choose_res_2165 = id_2167;
                                                                                        } else {
                                                                                          uint16_t id_2168 { 32 };
                                                                                          bool id_2169 { bool(id_2168 == label2_1127) };
                                                                                          Size choose_res_2170;
                                                                                          if (id_2169) {
                                                                                            Size id_2171 { 2UL };
                                                                                            Size id_2172 { Size(sz_1126 + id_2171) };
                                                                                            choose_res_2170 = id_2172;
                                                                                          } else {
                                                                                            uint16_t id_2173 { 33 };
                                                                                            bool id_2174 { bool(id_2173 == label2_1127) };
                                                                                            Size choose_res_2175;
                                                                                            if (id_2174) {
                                                                                              Size id_2176 { 2UL };
                                                                                              Size id_2177 { Size(sz_1126 + id_2176) };
                                                                                              choose_res_2175 = id_2177;
                                                                                            } else {
                                                                                              uint16_t id_2178 { 34 };
                                                                                              bool id_2179 { bool(id_2178 == label2_1127) };
                                                                                              Size choose_res_2180;
                                                                                              if (id_2179) {
                                                                                                Size id_2181 { 2UL };
                                                                                                Size id_2182 { Size(sz_1126 + id_2181) };
                                                                                                choose_res_2180 = id_2182;
                                                                                              } else {
                                                                                                uint16_t id_2183 { 35 };
                                                                                                bool id_2184 { bool(id_2183 == label2_1127) };
                                                                                                Size choose_res_2185;
                                                                                                if (id_2184) {
                                                                                                  Size id_2186 { 2UL };
                                                                                                  Size id_2187 { Size(sz_1126 + id_2186) };
                                                                                                  choose_res_2185 = id_2187;
                                                                                                } else {
                                                                                                  uint16_t id_2188 { 36 };
                                                                                                  bool id_2189 { bool(id_2188 == label2_1127) };
                                                                                                  Size choose_res_2190;
                                                                                                  if (id_2189) {
                                                                                                    Size id_2191 { 2UL };
                                                                                                    Size id_2192 { Size(sz_1126 + id_2191) };
                                                                                                    dc31f5cc689133a6f12d16478388e785 id_2193 { p_0.text };
                                                                                                    a481e1e269544fa0efe70fc68e01b3bb id_2194 { std::get<4>(id_2193) };
                                                                                                    v_86716e60fd92843b928cbb08bc52f333 id_2195 { std::get<1>(id_2194) };
                                                                                                    v_1d6ee587a956ed7717b51cc22dd3b087 id_2196 { std::get<0>(id_2195) };
                                                                                                    std::string id_2197 { std::get<36>(id_2196) };
                                                                                                    uint32_t id_2198 { (uint32_t)id_2197.size() };
                                                                                                    Vec<1, uint32_t> id_2199 {  id_2198  };
                                                                                                    Size let_res_2200;
                                                                                                    {
                                                                                                      Vec<1, uint32_t> n_ref_1129 { id_2199 };
                                                                                                      uint32_t id_2201 { 1U };
                                                                                                      Vec<1, uint32_t> id_2202 {  id_2201  };
                                                                                                      Size let_res_2203;
                                                                                                      {
                                                                                                        Vec<1, uint32_t> lebsz_ref_1130 { id_2202 };
                                                                                                        bool while_flag_2204 { true };
                                                                                                        do {
                                                                                                          uint8_t id_2205 { 0 };
                                                                                                          uint32_t id_2206 { n_ref_1129[id_2205] };
                                                                                                          uint8_t id_2207 { 0 };
                                                                                                          uint32_t id_2208 { lebsz_ref_1130[id_2207] };
                                                                                                          uint8_t id_2209 { 7 };
                                                                                                          uint32_t id_2210 { uint32_t(id_2208 << id_2209) };
                                                                                                          bool id_2211 { bool(id_2206 >= id_2210) };
                                                                                                          while_flag_2204 = id_2211;
                                                                                                          if (while_flag_2204) {
                                                                                                            uint8_t id_2212 { 0 };
                                                                                                            uint8_t id_2213 { 0 };
                                                                                                            uint32_t id_2214 { lebsz_ref_1130[id_2213] };
                                                                                                            uint32_t id_2215 { 1U };
                                                                                                            uint32_t id_2216 { uint32_t(id_2214 + id_2215) };
                                                                                                            Void id_2217 { ((void)(lebsz_ref_1130[id_2212] = id_2216), VOID) };
                                                                                                          }
                                                                                                        } while (while_flag_2204);
                                                                                                        uint8_t id_2218 { 0 };
                                                                                                        uint32_t id_2219 { lebsz_ref_1130[id_2218] };
                                                                                                        Size id_2220 { Size(id_2219) };
                                                                                                        let_res_2203 = id_2220;
                                                                                                      }
                                                                                                      let_res_2200 = let_res_2203;
                                                                                                    }
                                                                                                    dc31f5cc689133a6f12d16478388e785 id_2221 { p_0.text };
                                                                                                    a481e1e269544fa0efe70fc68e01b3bb id_2222 { std::get<4>(id_2221) };
                                                                                                    v_86716e60fd92843b928cbb08bc52f333 id_2223 { std::get<1>(id_2222) };
                                                                                                    v_1d6ee587a956ed7717b51cc22dd3b087 id_2224 { std::get<0>(id_2223) };
                                                                                                    std::string id_2225 { std::get<36>(id_2224) };
                                                                                                    uint32_t id_2226 { (uint32_t)id_2225.size() };
                                                                                                    Size id_2227 { Size(id_2226) };
                                                                                                    Size id_2228 { Size(let_res_2200 + id_2227) };
                                                                                                    Size id_2229 { Size(id_2192 + id_2228) };
                                                                                                    choose_res_2190 = id_2229;
                                                                                                  } else {
                                                                                                    uint16_t id_2230 { 37 };
                                                                                                    bool id_2231 { bool(id_2230 == label2_1127) };
                                                                                                    Size choose_res_2232;
                                                                                                    if (id_2231) {
                                                                                                      Size id_2233 { 2UL };
                                                                                                      Size id_2234 { Size(sz_1126 + id_2233) };
                                                                                                      choose_res_2232 = id_2234;
                                                                                                    } else {
                                                                                                      uint16_t id_2235 { 38 };
                                                                                                      bool id_2236 { bool(id_2235 == label2_1127) };
                                                                                                      Size choose_res_2237;
                                                                                                      if (id_2236) {
                                                                                                        Size id_2238 { 2UL };
                                                                                                        Size id_2239 { Size(sz_1126 + id_2238) };
                                                                                                        choose_res_2237 = id_2239;
                                                                                                      } else {
                                                                                                        uint16_t id_2240 { 39 };
                                                                                                        bool id_2241 { bool(id_2240 == label2_1127) };
                                                                                                        Size choose_res_2242;
                                                                                                        if (id_2241) {
                                                                                                          Size id_2243 { 2UL };
                                                                                                          Size id_2244 { Size(sz_1126 + id_2243) };
                                                                                                          choose_res_2242 = id_2244;
                                                                                                        } else {
                                                                                                          uint16_t id_2245 { 40 };
                                                                                                          bool id_2246 { bool(label2_1127 == id_2245) };
                                                                                                          Void id_2247 { ((void)(assert(id_2246)), VOID) };
                                                                                                          Size id_2248 { 2UL };
                                                                                                          Size id_2249 { Size(sz_1126 + id_2248) };
                                                                                                          choose_res_2242 = id_2249;
                                                                                                        }
                                                                                                        choose_res_2237 = choose_res_2242;
                                                                                                      }
                                                                                                      choose_res_2232 = choose_res_2237;
                                                                                                    }
                                                                                                    choose_res_2190 = choose_res_2232;
                                                                                                  }
                                                                                                  choose_res_2185 = choose_res_2190;
                                                                                                }
                                                                                                choose_res_2180 = choose_res_2185;
                                                                                              }
                                                                                              choose_res_2175 = choose_res_2180;
                                                                                            }
                                                                                            choose_res_2170 = choose_res_2175;
                                                                                          }
                                                                                          choose_res_2165 = choose_res_2170;
                                                                                        }
                                                                                        choose_res_2160 = choose_res_2165;
                                                                                      }
                                                                                      choose_res_2155 = choose_res_2160;
                                                                                    }
                                                                                    choose_res_2150 = choose_res_2155;
                                                                                  }
                                                                                  choose_res_2145 = choose_res_2150;
                                                                                }
                                                                                choose_res_2140 = choose_res_2145;
                                                                              }
                                                                              choose_res_2135 = choose_res_2140;
                                                                            }
                                                                            choose_res_2130 = choose_res_2135;
                                                                          }
                                                                          choose_res_2125 = choose_res_2130;
                                                                        }
                                                                        choose_res_2120 = choose_res_2125;
                                                                      }
                                                                      choose_res_2115 = choose_res_2120;
                                                                    }
                                                                    choose_res_2110 = choose_res_2115;
                                                                  }
                                                                  choose_res_2105 = choose_res_2110;
                                                                }
                                                                choose_res_2100 = choose_res_2105;
                                                              }
                                                              choose_res_2095 = choose_res_2100;
                                                            }
                                                            choose_res_2090 = choose_res_2095;
                                                          }
                                                          choose_res_2085 = choose_res_2090;
                                                        }
                                                        choose_res_2080 = choose_res_2085;
                                                      }
                                                      choose_res_2075 = choose_res_2080;
                                                    }
                                                    choose_res_2070 = choose_res_2075;
                                                  }
                                                  choose_res_2065 = choose_res_2070;
                                                }
                                                choose_res_2060 = choose_res_2065;
                                              }
                                              choose_res_2055 = choose_res_2060;
                                            }
                                            choose_res_2050 = choose_res_2055;
                                          }
                                          choose_res_2045 = choose_res_2050;
                                        }
                                        choose_res_2040 = choose_res_2045;
                                      }
                                      choose_res_2035 = choose_res_2040;
                                    }
                                    choose_res_2030 = choose_res_2035;
                                  }
                                  choose_res_1991 = choose_res_2030;
                                }
                                choose_res_1986 = choose_res_1991;
                              }
                              choose_res_1973 = choose_res_1986;
                            }
                            choose_res_1968 = choose_res_1973;
                          }
                          let_res_1965 = choose_res_1968;
                        }
                        let_res_1959 = let_res_1965;
                      }
                      dc31f5cc689133a6f12d16478388e785 id_2250 { p_0.text };
                      a481e1e269544fa0efe70fc68e01b3bb id_2251 { std::get<4>(id_2250) };
                      v_86716e60fd92843b928cbb08bc52f333 id_2252 { std::get<1>(id_2251) };
                      t* id_2253 { std::get<1>(id_2252) };
                      Size id_2254 { fun1474(id_2253) };
                      Size id_2255 { Size(let_res_1959 + id_2254) };
                      choose_res_1954 = id_2255;
                    } else {
                      uint16_t id_2256 { 2 };
                      dc31f5cc689133a6f12d16478388e785 id_2257 { p_0.text };
                      a481e1e269544fa0efe70fc68e01b3bb id_2258 { std::get<4>(id_2257) };
                      uint16_t id_2259 { uint16_t(id_2258.index()) };
                      bool id_2260 { bool(id_2256 == id_2259) };
                      Size choose_res_2261;
                      if (id_2260) {
                        dc31f5cc689133a6f12d16478388e785 id_2262 { p_0.text };
                        a481e1e269544fa0efe70fc68e01b3bb id_2263 { std::get<4>(id_2262) };
                        v_3b28b4928a9e27104e63a502937d8fd6 id_2264 { std::get<2>(id_2263) };
                        v_38879d3066416481efb8a2cff1fd95bb id_2265 { std::get<0>(id_2264) };
                        uint16_t id_2266 { uint16_t(id_2265.index()) };
                        Size let_res_2267;
                        {
                          uint16_t label2_1120 { id_2266 };
                          uint16_t id_2268 { 0 };
                          bool id_2269 { bool(id_2268 == label2_1120) };
                          Size choose_res_2270;
                          if (id_2269) {
                            Size id_2271 { 2UL };
                            Size id_2272 { Size(sz_1045 + id_2271) };
                            Size id_2273 { 2UL };
                            Size id_2274 { Size(id_2272 + id_2273) };
                            Size id_2275 { 2UL };
                            Size id_2276 { Size(id_2274 + id_2275) };
                            choose_res_2270 = id_2276;
                          } else {
                            uint16_t id_2277 { 1 };
                            bool id_2278 { bool(id_2277 == label2_1120) };
                            Size choose_res_2279;
                            if (id_2278) {
                              Size id_2280 { 2UL };
                              Size id_2281 { Size(sz_1045 + id_2280) };
                              Size id_2282 { 2UL };
                              Size id_2283 { Size(id_2281 + id_2282) };
                              Size id_2284 { 2UL };
                              Size id_2285 { Size(id_2283 + id_2284) };
                              choose_res_2279 = id_2285;
                            } else {
                              uint16_t id_2286 { 2 };
                              bool id_2287 { bool(id_2286 == label2_1120) };
                              Size choose_res_2288;
                              if (id_2287) {
                                Size id_2289 { 2UL };
                                Size id_2290 { Size(sz_1045 + id_2289) };
                                Size id_2291 { 2UL };
                                Size id_2292 { Size(id_2290 + id_2291) };
                                Size id_2293 { 2UL };
                                Size id_2294 { Size(id_2292 + id_2293) };
                                choose_res_2288 = id_2294;
                              } else {
                                uint16_t id_2295 { 3 };
                                bool id_2296 { bool(label2_1120 == id_2295) };
                                Void id_2297 { ((void)(assert(id_2296)), VOID) };
                                Size id_2298 { 2UL };
                                Size id_2299 { Size(sz_1045 + id_2298) };
                                Size id_2300 { 2UL };
                                Size id_2301 { Size(id_2299 + id_2300) };
                                Size id_2302 { 2UL };
                                Size id_2303 { Size(id_2301 + id_2302) };
                                choose_res_2288 = id_2303;
                              }
                              choose_res_2279 = choose_res_2288;
                            }
                            choose_res_2270 = choose_res_2279;
                          }
                          let_res_2267 = choose_res_2270;
                        }
                        Size let_res_2304;
                        {
                          Size sz_1121 { let_res_2267 };
                          dc31f5cc689133a6f12d16478388e785 id_2305 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_2306 { std::get<4>(id_2305) };
                          v_3b28b4928a9e27104e63a502937d8fd6 id_2307 { std::get<2>(id_2306) };
                          Lst<t*> id_2308 { std::get<1>(id_2307) };
                          uint32_t id_2309 { id_2308.size() };
                          Vec<1, uint32_t> id_2310 {  id_2309  };
                          Size let_res_2311;
                          {
                            Vec<1, uint32_t> n_ref_1122 { id_2310 };
                            uint32_t id_2312 { 1U };
                            Vec<1, uint32_t> id_2313 {  id_2312  };
                            Size let_res_2314;
                            {
                              Vec<1, uint32_t> lebsz_ref_1123 { id_2313 };
                              bool while_flag_2315 { true };
                              do {
                                uint8_t id_2316 { 0 };
                                uint32_t id_2317 { n_ref_1122[id_2316] };
                                uint8_t id_2318 { 0 };
                                uint32_t id_2319 { lebsz_ref_1123[id_2318] };
                                uint8_t id_2320 { 7 };
                                uint32_t id_2321 { uint32_t(id_2319 << id_2320) };
                                bool id_2322 { bool(id_2317 >= id_2321) };
                                while_flag_2315 = id_2322;
                                if (while_flag_2315) {
                                  uint8_t id_2323 { 0 };
                                  uint8_t id_2324 { 0 };
                                  uint32_t id_2325 { lebsz_ref_1123[id_2324] };
                                  uint32_t id_2326 { 1U };
                                  uint32_t id_2327 { uint32_t(id_2325 + id_2326) };
                                  Void id_2328 { ((void)(lebsz_ref_1123[id_2323] = id_2327), VOID) };
                                }
                              } while (while_flag_2315);
                              uint8_t id_2329 { 0 };
                              uint32_t id_2330 { lebsz_ref_1123[id_2329] };
                              Size id_2331 { Size(id_2330) };
                              let_res_2314 = id_2331;
                            }
                            let_res_2311 = let_res_2314;
                          }
                          Size id_2332 { Size(sz_1121 + let_res_2311) };
                          Vec<1, Size> id_2333 {  id_2332  };
                          Size let_res_2334;
                          {
                            Vec<1, Size> sz_ref_1124 { id_2333 };
                            int32_t id_2335 { 0L };
                            Vec<1, int32_t> id_2336 {  id_2335  };
                            {
                              Vec<1, int32_t> repeat_n_1125 { id_2336 };
                              bool while_flag_2337 { true };
                              do {
                                dc31f5cc689133a6f12d16478388e785 id_2338 { p_0.text };
                                a481e1e269544fa0efe70fc68e01b3bb id_2339 { std::get<4>(id_2338) };
                                v_3b28b4928a9e27104e63a502937d8fd6 id_2340 { std::get<2>(id_2339) };
                                Lst<t*> id_2341 { std::get<1>(id_2340) };
                                uint32_t id_2342 { id_2341.size() };
                                int32_t id_2343 { int32_t(id_2342) };
                                uint8_t id_2344 { 0 };
                                int32_t id_2345 { repeat_n_1125[id_2344] };
                                bool id_2346 { bool(id_2343 > id_2345) };
                                while_flag_2337 = id_2346;
                                if (while_flag_2337) {
                                  uint8_t id_2347 { 0 };
                                  uint8_t id_2348 { 0 };
                                  Size id_2349 { sz_ref_1124[id_2348] };
                                  uint8_t id_2350 { 0 };
                                  int32_t id_2351 { repeat_n_1125[id_2350] };
                                  dc31f5cc689133a6f12d16478388e785 id_2352 { p_0.text };
                                  a481e1e269544fa0efe70fc68e01b3bb id_2353 { std::get<4>(id_2352) };
                                  v_3b28b4928a9e27104e63a502937d8fd6 id_2354 { std::get<2>(id_2353) };
                                  Lst<t*> id_2355 { std::get<1>(id_2354) };
                                  t* id_2356 { id_2355[id_2351] };
                                  Size id_2357 { fun1474(id_2356) };
                                  Size id_2358 { Size(id_2349 + id_2357) };
                                  Void id_2359 { ((void)(sz_ref_1124[id_2347] = id_2358), VOID) };
                                  uint8_t id_2360 { 0 };
                                  uint8_t id_2361 { 0 };
                                  int32_t id_2362 { repeat_n_1125[id_2361] };
                                  int32_t id_2363 { 1L };
                                  int32_t id_2364 { int32_t(id_2362 + id_2363) };
                                  Void id_2365 { ((void)(repeat_n_1125[id_2360] = id_2364), VOID) };
                                }
                              } while (while_flag_2337);
                            }
                            uint8_t id_2366 { 0 };
                            Size id_2367 { sz_ref_1124[id_2366] };
                            let_res_2334 = id_2367;
                          }
                          let_res_2304 = let_res_2334;
                        }
                        choose_res_2261 = let_res_2304;
                      } else {
                        uint16_t id_2368 { 3 };
                        dc31f5cc689133a6f12d16478388e785 id_2369 { p_0.text };
                        a481e1e269544fa0efe70fc68e01b3bb id_2370 { std::get<4>(id_2369) };
                        uint16_t id_2371 { uint16_t(id_2370.index()) };
                        bool id_2372 { bool(id_2368 == id_2371) };
                        Size choose_res_2373;
                        if (id_2372) {
                          Size id_2374 { 2UL };
                          Size id_2375 { Size(sz_1045 + id_2374) };
                          Size id_2376 { 2UL };
                          Size id_2377 { Size(id_2375 + id_2376) };
                          Size let_res_2378;
                          {
                            Size sz_1115 { id_2377 };
                            dc31f5cc689133a6f12d16478388e785 id_2379 { p_0.text };
                            a481e1e269544fa0efe70fc68e01b3bb id_2380 { std::get<4>(id_2379) };
                            v_8987bf3ba5adfaa68384b9fde66ab651 id_2381 { std::get<3>(id_2380) };
                            v_20bb2b786e4d41528e682385744fec03 id_2382 { std::get<0>(id_2381) };
                            uint16_t id_2383 { uint16_t(id_2382.index()) };
                            Size let_res_2384;
                            {
                              uint16_t label2_1116 { id_2383 };
                              uint16_t id_2385 { 0 };
                              bool id_2386 { bool(id_2385 == label2_1116) };
                              Size choose_res_2387;
                              if (id_2386) {
                                Size id_2388 { 2UL };
                                Size id_2389 { Size(sz_1115 + id_2388) };
                                choose_res_2387 = id_2389;
                              } else {
                                uint16_t id_2390 { 1 };
                                bool id_2391 { bool(id_2390 == label2_1116) };
                                Size choose_res_2392;
                                if (id_2391) {
                                  Size id_2393 { 2UL };
                                  Size id_2394 { Size(sz_1115 + id_2393) };
                                  choose_res_2392 = id_2394;
                                } else {
                                  uint16_t id_2395 { 2 };
                                  bool id_2396 { bool(id_2395 == label2_1116) };
                                  Size choose_res_2397;
                                  if (id_2396) {
                                    Size id_2398 { 2UL };
                                    Size id_2399 { Size(sz_1115 + id_2398) };
                                    choose_res_2397 = id_2399;
                                  } else {
                                    uint16_t id_2400 { 3 };
                                    bool id_2401 { bool(id_2400 == label2_1116) };
                                    Size choose_res_2402;
                                    if (id_2401) {
                                      Size id_2403 { 2UL };
                                      Size id_2404 { Size(sz_1115 + id_2403) };
                                      choose_res_2402 = id_2404;
                                    } else {
                                      uint16_t id_2405 { 4 };
                                      bool id_2406 { bool(id_2405 == label2_1116) };
                                      Size choose_res_2407;
                                      if (id_2406) {
                                        Size id_2408 { 2UL };
                                        Size id_2409 { Size(sz_1115 + id_2408) };
                                        choose_res_2407 = id_2409;
                                      } else {
                                        uint16_t id_2410 { 5 };
                                        bool id_2411 { bool(id_2410 == label2_1116) };
                                        Size choose_res_2412;
                                        if (id_2411) {
                                          Size id_2413 { 2UL };
                                          Size id_2414 { Size(sz_1115 + id_2413) };
                                          choose_res_2412 = id_2414;
                                        } else {
                                          uint16_t id_2415 { 6 };
                                          bool id_2416 { bool(id_2415 == label2_1116) };
                                          Size choose_res_2417;
                                          if (id_2416) {
                                            Size id_2418 { 2UL };
                                            Size id_2419 { Size(sz_1115 + id_2418) };
                                            choose_res_2417 = id_2419;
                                          } else {
                                            uint16_t id_2420 { 7 };
                                            bool id_2421 { bool(id_2420 == label2_1116) };
                                            Size choose_res_2422;
                                            if (id_2421) {
                                              Size id_2423 { 2UL };
                                              Size id_2424 { Size(sz_1115 + id_2423) };
                                              choose_res_2422 = id_2424;
                                            } else {
                                              uint16_t id_2425 { 8 };
                                              bool id_2426 { bool(id_2425 == label2_1116) };
                                              Size choose_res_2427;
                                              if (id_2426) {
                                                Size id_2428 { 2UL };
                                                Size id_2429 { Size(sz_1115 + id_2428) };
                                                choose_res_2427 = id_2429;
                                              } else {
                                                uint16_t id_2430 { 9 };
                                                bool id_2431 { bool(id_2430 == label2_1116) };
                                                Size choose_res_2432;
                                                if (id_2431) {
                                                  Size id_2433 { 2UL };
                                                  Size id_2434 { Size(sz_1115 + id_2433) };
                                                  choose_res_2432 = id_2434;
                                                } else {
                                                  uint16_t id_2435 { 10 };
                                                  bool id_2436 { bool(id_2435 == label2_1116) };
                                                  Size choose_res_2437;
                                                  if (id_2436) {
                                                    Size id_2438 { 2UL };
                                                    Size id_2439 { Size(sz_1115 + id_2438) };
                                                    choose_res_2437 = id_2439;
                                                  } else {
                                                    uint16_t id_2440 { 11 };
                                                    bool id_2441 { bool(id_2440 == label2_1116) };
                                                    Size choose_res_2442;
                                                    if (id_2441) {
                                                      Size id_2443 { 2UL };
                                                      Size id_2444 { Size(sz_1115 + id_2443) };
                                                      choose_res_2442 = id_2444;
                                                    } else {
                                                      uint16_t id_2445 { 12 };
                                                      bool id_2446 { bool(id_2445 == label2_1116) };
                                                      Size choose_res_2447;
                                                      if (id_2446) {
                                                        Size id_2448 { 2UL };
                                                        Size id_2449 { Size(sz_1115 + id_2448) };
                                                        choose_res_2447 = id_2449;
                                                      } else {
                                                        uint16_t id_2450 { 13 };
                                                        bool id_2451 { bool(id_2450 == label2_1116) };
                                                        Size choose_res_2452;
                                                        if (id_2451) {
                                                          Size id_2453 { 2UL };
                                                          Size id_2454 { Size(sz_1115 + id_2453) };
                                                          choose_res_2452 = id_2454;
                                                        } else {
                                                          uint16_t id_2455 { 14 };
                                                          bool id_2456 { bool(id_2455 == label2_1116) };
                                                          Size choose_res_2457;
                                                          if (id_2456) {
                                                            Size id_2458 { 2UL };
                                                            Size id_2459 { Size(sz_1115 + id_2458) };
                                                            choose_res_2457 = id_2459;
                                                          } else {
                                                            uint16_t id_2460 { 15 };
                                                            bool id_2461 { bool(id_2460 == label2_1116) };
                                                            Size choose_res_2462;
                                                            if (id_2461) {
                                                              Size id_2463 { 2UL };
                                                              Size id_2464 { Size(sz_1115 + id_2463) };
                                                              choose_res_2462 = id_2464;
                                                            } else {
                                                              uint16_t id_2465 { 16 };
                                                              bool id_2466 { bool(id_2465 == label2_1116) };
                                                              Size choose_res_2467;
                                                              if (id_2466) {
                                                                Size id_2468 { 2UL };
                                                                Size id_2469 { Size(sz_1115 + id_2468) };
                                                                choose_res_2467 = id_2469;
                                                              } else {
                                                                uint16_t id_2470 { 17 };
                                                                bool id_2471 { bool(id_2470 == label2_1116) };
                                                                Size choose_res_2472;
                                                                if (id_2471) {
                                                                  Size id_2473 { 2UL };
                                                                  Size id_2474 { Size(sz_1115 + id_2473) };
                                                                  choose_res_2472 = id_2474;
                                                                } else {
                                                                  uint16_t id_2475 { 18 };
                                                                  bool id_2476 { bool(id_2475 == label2_1116) };
                                                                  Size choose_res_2477;
                                                                  if (id_2476) {
                                                                    Size id_2478 { 2UL };
                                                                    Size id_2479 { Size(sz_1115 + id_2478) };
                                                                    choose_res_2477 = id_2479;
                                                                  } else {
                                                                    uint16_t id_2480 { 19 };
                                                                    bool id_2481 { bool(id_2480 == label2_1116) };
                                                                    Size choose_res_2482;
                                                                    if (id_2481) {
                                                                      Size id_2483 { 2UL };
                                                                      Size id_2484 { Size(sz_1115 + id_2483) };
                                                                      choose_res_2482 = id_2484;
                                                                    } else {
                                                                      uint16_t id_2485 { 20 };
                                                                      bool id_2486 { bool(id_2485 == label2_1116) };
                                                                      Size choose_res_2487;
                                                                      if (id_2486) {
                                                                        Size id_2488 { 2UL };
                                                                        Size id_2489 { Size(sz_1115 + id_2488) };
                                                                        choose_res_2487 = id_2489;
                                                                      } else {
                                                                        uint16_t id_2490 { 21 };
                                                                        bool id_2491 { bool(id_2490 == label2_1116) };
                                                                        Size choose_res_2492;
                                                                        if (id_2491) {
                                                                          Size id_2493 { 2UL };
                                                                          Size id_2494 { Size(sz_1115 + id_2493) };
                                                                          choose_res_2492 = id_2494;
                                                                        } else {
                                                                          uint16_t id_2495 { 22 };
                                                                          bool id_2496 { bool(id_2495 == label2_1116) };
                                                                          Size choose_res_2497;
                                                                          if (id_2496) {
                                                                            Size id_2498 { 2UL };
                                                                            Size id_2499 { Size(sz_1115 + id_2498) };
                                                                            choose_res_2497 = id_2499;
                                                                          } else {
                                                                            uint16_t id_2500 { 23 };
                                                                            bool id_2501 { bool(id_2500 == label2_1116) };
                                                                            Size choose_res_2502;
                                                                            if (id_2501) {
                                                                              Size id_2503 { 2UL };
                                                                              Size id_2504 { Size(sz_1115 + id_2503) };
                                                                              choose_res_2502 = id_2504;
                                                                            } else {
                                                                              uint16_t id_2505 { 24 };
                                                                              bool id_2506 { bool(id_2505 == label2_1116) };
                                                                              Size choose_res_2507;
                                                                              if (id_2506) {
                                                                                Size id_2508 { 2UL };
                                                                                Size id_2509 { Size(sz_1115 + id_2508) };
                                                                                choose_res_2507 = id_2509;
                                                                              } else {
                                                                                uint16_t id_2510 { 25 };
                                                                                bool id_2511 { bool(label2_1116 == id_2510) };
                                                                                Void id_2512 { ((void)(assert(id_2511)), VOID) };
                                                                                Size id_2513 { 2UL };
                                                                                Size id_2514 { Size(sz_1115 + id_2513) };
                                                                                choose_res_2507 = id_2514;
                                                                              }
                                                                              choose_res_2502 = choose_res_2507;
                                                                            }
                                                                            choose_res_2497 = choose_res_2502;
                                                                          }
                                                                          choose_res_2492 = choose_res_2497;
                                                                        }
                                                                        choose_res_2487 = choose_res_2492;
                                                                      }
                                                                      choose_res_2482 = choose_res_2487;
                                                                    }
                                                                    choose_res_2477 = choose_res_2482;
                                                                  }
                                                                  choose_res_2472 = choose_res_2477;
                                                                }
                                                                choose_res_2467 = choose_res_2472;
                                                              }
                                                              choose_res_2462 = choose_res_2467;
                                                            }
                                                            choose_res_2457 = choose_res_2462;
                                                          }
                                                          choose_res_2452 = choose_res_2457;
                                                        }
                                                        choose_res_2447 = choose_res_2452;
                                                      }
                                                      choose_res_2442 = choose_res_2447;
                                                    }
                                                    choose_res_2437 = choose_res_2442;
                                                  }
                                                  choose_res_2432 = choose_res_2437;
                                                }
                                                choose_res_2427 = choose_res_2432;
                                              }
                                              choose_res_2422 = choose_res_2427;
                                            }
                                            choose_res_2417 = choose_res_2422;
                                          }
                                          choose_res_2412 = choose_res_2417;
                                        }
                                        choose_res_2407 = choose_res_2412;
                                      }
                                      choose_res_2402 = choose_res_2407;
                                    }
                                    choose_res_2397 = choose_res_2402;
                                  }
                                  choose_res_2392 = choose_res_2397;
                                }
                                choose_res_2387 = choose_res_2392;
                              }
                              let_res_2384 = choose_res_2387;
                            }
                            let_res_2378 = let_res_2384;
                          }
                          dc31f5cc689133a6f12d16478388e785 id_2515 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_2516 { std::get<4>(id_2515) };
                          v_8987bf3ba5adfaa68384b9fde66ab651 id_2517 { std::get<3>(id_2516) };
                          t* id_2518 { std::get<1>(id_2517) };
                          Size id_2519 { fun1474(id_2518) };
                          Size id_2520 { Size(let_res_2378 + id_2519) };
                          dc31f5cc689133a6f12d16478388e785 id_2521 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_2522 { std::get<4>(id_2521) };
                          v_8987bf3ba5adfaa68384b9fde66ab651 id_2523 { std::get<3>(id_2522) };
                          t* id_2524 { std::get<2>(id_2523) };
                          Size id_2525 { fun1474(id_2524) };
                          Size id_2526 { Size(id_2520 + id_2525) };
                          choose_res_2373 = id_2526;
                        } else {
                          dc31f5cc689133a6f12d16478388e785 id_2527 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_2528 { std::get<4>(id_2527) };
                          uint16_t id_2529 { uint16_t(id_2528.index()) };
                          uint16_t id_2530 { 4 };
                          bool id_2531 { bool(id_2529 == id_2530) };
                          Void id_2532 { ((void)(assert(id_2531)), VOID) };
                          uint16_t id_2533 { 0 };
                          dc31f5cc689133a6f12d16478388e785 id_2534 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_2535 { std::get<4>(id_2534) };
                          v_3d59f26fb89fa3ef8dc792c2f4609b32 id_2536 { std::get<4>(id_2535) };
                          v_4b68f284ffe696cb6936ca2f6880b08a id_2537 { std::get<0>(id_2536) };
                          uint16_t id_2538 { uint16_t(id_2537.index()) };
                          bool id_2539 { bool(id_2533 == id_2538) };
                          Size choose_res_2540;
                          if (id_2539) {
                            Size id_2541 { 2UL };
                            Size id_2542 { Size(sz_1045 + id_2541) };
                            Size id_2543 { 2UL };
                            Size id_2544 { Size(id_2542 + id_2543) };
                            Size id_2545 { 2UL };
                            Size id_2546 { Size(id_2544 + id_2545) };
                            choose_res_2540 = id_2546;
                          } else {
                            dc31f5cc689133a6f12d16478388e785 id_2547 { p_0.text };
                            a481e1e269544fa0efe70fc68e01b3bb id_2548 { std::get<4>(id_2547) };
                            v_3d59f26fb89fa3ef8dc792c2f4609b32 id_2549 { std::get<4>(id_2548) };
                            v_4b68f284ffe696cb6936ca2f6880b08a id_2550 { std::get<0>(id_2549) };
                            uint16_t id_2551 { uint16_t(id_2550.index()) };
                            uint16_t id_2552 { 1 };
                            bool id_2553 { bool(id_2551 == id_2552) };
                            Void id_2554 { ((void)(assert(id_2553)), VOID) };
                            Size id_2555 { 2UL };
                            Size id_2556 { Size(sz_1045 + id_2555) };
                            Size id_2557 { 2UL };
                            Size id_2558 { Size(id_2556 + id_2557) };
                            Size id_2559 { 2UL };
                            Size id_2560 { Size(id_2558 + id_2559) };
                            choose_res_2540 = id_2560;
                          }
                          dc31f5cc689133a6f12d16478388e785 id_2561 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_2562 { std::get<4>(id_2561) };
                          v_3d59f26fb89fa3ef8dc792c2f4609b32 id_2563 { std::get<4>(id_2562) };
                          t* id_2564 { std::get<1>(id_2563) };
                          Size id_2565 { fun1474(id_2564) };
                          Size id_2566 { Size(choose_res_2540 + id_2565) };
                          dc31f5cc689133a6f12d16478388e785 id_2567 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_2568 { std::get<4>(id_2567) };
                          v_3d59f26fb89fa3ef8dc792c2f4609b32 id_2569 { std::get<4>(id_2568) };
                          t* id_2570 { std::get<2>(id_2569) };
                          Size id_2571 { fun1474(id_2570) };
                          Size id_2572 { Size(id_2566 + id_2571) };
                          dc31f5cc689133a6f12d16478388e785 id_2573 { p_0.text };
                          a481e1e269544fa0efe70fc68e01b3bb id_2574 { std::get<4>(id_2573) };
                          v_3d59f26fb89fa3ef8dc792c2f4609b32 id_2575 { std::get<4>(id_2574) };
                          t* id_2576 { std::get<3>(id_2575) };
                          Size id_2577 { fun1474(id_2576) };
                          Size id_2578 { Size(id_2572 + id_2577) };
                          choose_res_2373 = id_2578;
                        }
                        choose_res_2261 = choose_res_2373;
                      }
                      choose_res_1954 = choose_res_2261;
                    }
                    choose_res_1777 = choose_res_1954;
                  }
                  choose_res_1771 = choose_res_1777;
                } else {
                  uint16_t id_2579 { 5 };
                  bool id_2580 { bool(id_2579 == label2_1046) };
                  Size choose_res_2581;
                  if (id_2580) {
                    uint16_t id_2582 { 0 };
                    dc31f5cc689133a6f12d16478388e785 id_2583 { p_0.text };
                    v_58c653b3fc47800248b5c8f49e80fabb id_2584 { std::get<5>(id_2583) };
                    d9442fc1deb39566ea1af2c5bee72a1c id_2585 { std::get<0>(id_2584) };
                    uint16_t id_2586 { uint16_t(id_2585.index()) };
                    bool id_2587 { bool(id_2582 == id_2586) };
                    Size choose_res_2588;
                    if (id_2587) {
                      Size id_2589 { 2UL };
                      Size id_2590 { Size(sz_1045 + id_2589) };
                      Size id_2591 { 2UL };
                      Size id_2592 { Size(id_2590 + id_2591) };
                      choose_res_2588 = id_2592;
                    } else {
                      dc31f5cc689133a6f12d16478388e785 id_2593 { p_0.text };
                      v_58c653b3fc47800248b5c8f49e80fabb id_2594 { std::get<5>(id_2593) };
                      d9442fc1deb39566ea1af2c5bee72a1c id_2595 { std::get<0>(id_2594) };
                      uint16_t id_2596 { uint16_t(id_2595.index()) };
                      uint16_t id_2597 { 1 };
                      bool id_2598 { bool(id_2596 == id_2597) };
                      Void id_2599 { ((void)(assert(id_2598)), VOID) };
                      Size id_2600 { 2UL };
                      Size id_2601 { Size(sz_1045 + id_2600) };
                      Size id_2602 { 2UL };
                      Size id_2603 { Size(id_2601 + id_2602) };
                      choose_res_2588 = id_2603;
                    }
                    Size id_2604 { 1UL };
                    Size id_2605 { Size(choose_res_2588 + id_2604) };
                    Size let_res_2606;
                    {
                      Size sz_1053 { id_2605 };
                      dc31f5cc689133a6f12d16478388e785 id_2607 { p_0.text };
                      v_58c653b3fc47800248b5c8f49e80fabb id_2608 { std::get<5>(id_2607) };
                      v_2a737e40b715df686303c32fcaefae73 id_2609 { std::get<2>(id_2608) };
                      uint16_t id_2610 { uint16_t(id_2609.index()) };
                      Size let_res_2611;
                      {
                        uint16_t label2_1054 { id_2610 };
                        uint16_t id_2612 { 0 };
                        bool id_2613 { bool(id_2612 == label2_1054) };
                        Size choose_res_2614;
                        if (id_2613) {
                          Size id_2615 { 2UL };
                          Size id_2616 { Size(sz_1053 + id_2615) };
                          Size let_res_2617;
                          {
                            Size sz_1103 { id_2616 };
                            dc31f5cc689133a6f12d16478388e785 id_2618 { p_0.text };
                            v_58c653b3fc47800248b5c8f49e80fabb id_2619 { std::get<5>(id_2618) };
                            v_2a737e40b715df686303c32fcaefae73 id_2620 { std::get<2>(id_2619) };
                            b899c3a5f918df0742a7782ddf15cd18 id_2621 { std::get<0>(id_2620) };
                            v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_2622 { std::get<0>(id_2621) };
                            uint16_t id_2623 { uint16_t(id_2622.index()) };
                            Size let_res_2624;
                            {
                              uint16_t label2_1104 { id_2623 };
                              uint16_t id_2625 { 0 };
                              bool id_2626 { bool(id_2625 == label2_1104) };
                              Size choose_res_2627;
                              if (id_2626) {
                                Size id_2628 { 2UL };
                                Size id_2629 { Size(sz_1103 + id_2628) };
                                choose_res_2627 = id_2629;
                              } else {
                                uint16_t id_2630 { 1 };
                                bool id_2631 { bool(id_2630 == label2_1104) };
                                Size choose_res_2632;
                                if (id_2631) {
                                  Size id_2633 { 2UL };
                                  Size id_2634 { Size(sz_1103 + id_2633) };
                                  choose_res_2632 = id_2634;
                                } else {
                                  uint16_t id_2635 { 2 };
                                  bool id_2636 { bool(id_2635 == label2_1104) };
                                  Size choose_res_2637;
                                  if (id_2636) {
                                    Size id_2638 { 2UL };
                                    Size id_2639 { Size(sz_1103 + id_2638) };
                                    choose_res_2637 = id_2639;
                                  } else {
                                    uint16_t id_2640 { 3 };
                                    bool id_2641 { bool(id_2640 == label2_1104) };
                                    Size choose_res_2642;
                                    if (id_2641) {
                                      Size id_2643 { 2UL };
                                      Size id_2644 { Size(sz_1103 + id_2643) };
                                      choose_res_2642 = id_2644;
                                    } else {
                                      uint16_t id_2645 { 4 };
                                      bool id_2646 { bool(id_2645 == label2_1104) };
                                      Size choose_res_2647;
                                      if (id_2646) {
                                        Size id_2648 { 2UL };
                                        Size id_2649 { Size(sz_1103 + id_2648) };
                                        choose_res_2647 = id_2649;
                                      } else {
                                        uint16_t id_2650 { 5 };
                                        bool id_2651 { bool(id_2650 == label2_1104) };
                                        Size choose_res_2652;
                                        if (id_2651) {
                                          Size id_2653 { 2UL };
                                          Size id_2654 { Size(sz_1103 + id_2653) };
                                          choose_res_2652 = id_2654;
                                        } else {
                                          uint16_t id_2655 { 6 };
                                          bool id_2656 { bool(id_2655 == label2_1104) };
                                          Size choose_res_2657;
                                          if (id_2656) {
                                            Size id_2658 { 2UL };
                                            Size id_2659 { Size(sz_1103 + id_2658) };
                                            choose_res_2657 = id_2659;
                                          } else {
                                            uint16_t id_2660 { 7 };
                                            bool id_2661 { bool(id_2660 == label2_1104) };
                                            Size choose_res_2662;
                                            if (id_2661) {
                                              Size id_2663 { 2UL };
                                              Size id_2664 { Size(sz_1103 + id_2663) };
                                              choose_res_2662 = id_2664;
                                            } else {
                                              uint16_t id_2665 { 8 };
                                              bool id_2666 { bool(id_2665 == label2_1104) };
                                              Size choose_res_2667;
                                              if (id_2666) {
                                                Size id_2668 { 2UL };
                                                Size id_2669 { Size(sz_1103 + id_2668) };
                                                choose_res_2667 = id_2669;
                                              } else {
                                                uint16_t id_2670 { 9 };
                                                bool id_2671 { bool(id_2670 == label2_1104) };
                                                Size choose_res_2672;
                                                if (id_2671) {
                                                  Size id_2673 { 2UL };
                                                  Size id_2674 { Size(sz_1103 + id_2673) };
                                                  choose_res_2672 = id_2674;
                                                } else {
                                                  uint16_t id_2675 { 10 };
                                                  bool id_2676 { bool(id_2675 == label2_1104) };
                                                  Size choose_res_2677;
                                                  if (id_2676) {
                                                    Size id_2678 { 2UL };
                                                    Size id_2679 { Size(sz_1103 + id_2678) };
                                                    choose_res_2677 = id_2679;
                                                  } else {
                                                    uint16_t id_2680 { 11 };
                                                    bool id_2681 { bool(id_2680 == label2_1104) };
                                                    Size choose_res_2682;
                                                    if (id_2681) {
                                                      Size id_2683 { 2UL };
                                                      Size id_2684 { Size(sz_1103 + id_2683) };
                                                      Size id_2685 { 8UL };
                                                      Size id_2686 { Size(id_2684 + id_2685) };
                                                      Size id_2687 { 8UL };
                                                      Size id_2688 { Size(id_2686 + id_2687) };
                                                      Size id_2689 { 4UL };
                                                      Size id_2690 { Size(id_2688 + id_2689) };
                                                      choose_res_2682 = id_2690;
                                                    } else {
                                                      uint16_t id_2691 { 12 };
                                                      bool id_2692 { bool(id_2691 == label2_1104) };
                                                      Size choose_res_2693;
                                                      if (id_2692) {
                                                        Size id_2694 { 2UL };
                                                        Size id_2695 { Size(sz_1103 + id_2694) };
                                                        choose_res_2693 = id_2695;
                                                      } else {
                                                        uint16_t id_2696 { 13 };
                                                        bool id_2697 { bool(id_2696 == label2_1104) };
                                                        Size choose_res_2698;
                                                        if (id_2697) {
                                                          Size id_2699 { 2UL };
                                                          Size id_2700 { Size(sz_1103 + id_2699) };
                                                          choose_res_2698 = id_2700;
                                                        } else {
                                                          uint16_t id_2701 { 14 };
                                                          bool id_2702 { bool(label2_1104 == id_2701) };
                                                          Void id_2703 { ((void)(assert(id_2702)), VOID) };
                                                          Size id_2704 { 2UL };
                                                          Size id_2705 { Size(sz_1103 + id_2704) };
                                                          choose_res_2698 = id_2705;
                                                        }
                                                        choose_res_2693 = choose_res_2698;
                                                      }
                                                      choose_res_2682 = choose_res_2693;
                                                    }
                                                    choose_res_2677 = choose_res_2682;
                                                  }
                                                  choose_res_2672 = choose_res_2677;
                                                }
                                                choose_res_2667 = choose_res_2672;
                                              }
                                              choose_res_2662 = choose_res_2667;
                                            }
                                            choose_res_2657 = choose_res_2662;
                                          }
                                          choose_res_2652 = choose_res_2657;
                                        }
                                        choose_res_2647 = choose_res_2652;
                                      }
                                      choose_res_2642 = choose_res_2647;
                                    }
                                    choose_res_2637 = choose_res_2642;
                                  }
                                  choose_res_2632 = choose_res_2637;
                                }
                                choose_res_2627 = choose_res_2632;
                              }
                              let_res_2624 = choose_res_2627;
                            }
                            let_res_2617 = let_res_2624;
                          }
                          dc31f5cc689133a6f12d16478388e785 id_2706 { p_0.text };
                          v_58c653b3fc47800248b5c8f49e80fabb id_2707 { std::get<5>(id_2706) };
                          v_2a737e40b715df686303c32fcaefae73 id_2708 { std::get<2>(id_2707) };
                          b899c3a5f918df0742a7782ddf15cd18 id_2709 { std::get<0>(id_2708) };
                          t* id_2710 { std::get<1>(id_2709) };
                          Size id_2711 { fun1474(id_2710) };
                          Size id_2712 { Size(let_res_2617 + id_2711) };
                          choose_res_2614 = id_2712;
                        } else {
                          uint16_t id_2713 { 1 };
                          bool id_2714 { bool(id_2713 == label2_1054) };
                          Size choose_res_2715;
                          if (id_2714) {
                            dc31f5cc689133a6f12d16478388e785 id_2716 { p_0.text };
                            v_58c653b3fc47800248b5c8f49e80fabb id_2717 { std::get<5>(id_2716) };
                            v_2a737e40b715df686303c32fcaefae73 id_2718 { std::get<2>(id_2717) };
                            bd090e444c05c1e6fea8a3c1c0be1d01 id_2719 { std::get<1>(id_2718) };
                            v_1bafb672d5db6e6c81afc008103c3a63 id_2720 { std::get<0>(id_2719) };
                            uint16_t id_2721 { uint16_t(id_2720.index()) };
                            Size let_res_2722;
                            {
                              uint16_t label2_1100 { id_2721 };
                              uint16_t id_2723 { 0 };
                              bool id_2724 { bool(id_2723 == label2_1100) };
                              Size choose_res_2725;
                              if (id_2724) {
                                Size id_2726 { 2UL };
                                Size id_2727 { Size(sz_1053 + id_2726) };
                                Size id_2728 { 2UL };
                                Size id_2729 { Size(id_2727 + id_2728) };
                                choose_res_2725 = id_2729;
                              } else {
                                uint16_t id_2730 { 1 };
                                bool id_2731 { bool(id_2730 == label2_1100) };
                                Size choose_res_2732;
                                if (id_2731) {
                                  Size id_2733 { 2UL };
                                  Size id_2734 { Size(sz_1053 + id_2733) };
                                  Size id_2735 { 2UL };
                                  Size id_2736 { Size(id_2734 + id_2735) };
                                  choose_res_2732 = id_2736;
                                } else {
                                  uint16_t id_2737 { 2 };
                                  bool id_2738 { bool(id_2737 == label2_1100) };
                                  Size choose_res_2739;
                                  if (id_2738) {
                                    Size id_2740 { 2UL };
                                    Size id_2741 { Size(sz_1053 + id_2740) };
                                    Size id_2742 { 2UL };
                                    Size id_2743 { Size(id_2741 + id_2742) };
                                    choose_res_2739 = id_2743;
                                  } else {
                                    uint16_t id_2744 { 3 };
                                    bool id_2745 { bool(label2_1100 == id_2744) };
                                    Void id_2746 { ((void)(assert(id_2745)), VOID) };
                                    Size id_2747 { 2UL };
                                    Size id_2748 { Size(sz_1053 + id_2747) };
                                    Size id_2749 { 2UL };
                                    Size id_2750 { Size(id_2748 + id_2749) };
                                    choose_res_2739 = id_2750;
                                  }
                                  choose_res_2732 = choose_res_2739;
                                }
                                choose_res_2725 = choose_res_2732;
                              }
                              let_res_2722 = choose_res_2725;
                            }
                            dc31f5cc689133a6f12d16478388e785 id_2751 { p_0.text };
                            v_58c653b3fc47800248b5c8f49e80fabb id_2752 { std::get<5>(id_2751) };
                            v_2a737e40b715df686303c32fcaefae73 id_2753 { std::get<2>(id_2752) };
                            bd090e444c05c1e6fea8a3c1c0be1d01 id_2754 { std::get<1>(id_2753) };
                            t* id_2755 { std::get<1>(id_2754) };
                            Size id_2756 { fun1474(id_2755) };
                            Size id_2757 { Size(let_res_2722 + id_2756) };
                            dc31f5cc689133a6f12d16478388e785 id_2758 { p_0.text };
                            v_58c653b3fc47800248b5c8f49e80fabb id_2759 { std::get<5>(id_2758) };
                            v_2a737e40b715df686303c32fcaefae73 id_2760 { std::get<2>(id_2759) };
                            bd090e444c05c1e6fea8a3c1c0be1d01 id_2761 { std::get<1>(id_2760) };
                            t* id_2762 { std::get<2>(id_2761) };
                            Size id_2763 { fun1474(id_2762) };
                            Size id_2764 { Size(id_2757 + id_2763) };
                            choose_res_2715 = id_2764;
                          } else {
                            uint16_t id_2765 { 2 };
                            bool id_2766 { bool(id_2765 == label2_1054) };
                            Size choose_res_2767;
                            if (id_2766) {
                              uint16_t id_2768 { 0 };
                              dc31f5cc689133a6f12d16478388e785 id_2769 { p_0.text };
                              v_58c653b3fc47800248b5c8f49e80fabb id_2770 { std::get<5>(id_2769) };
                              v_2a737e40b715df686303c32fcaefae73 id_2771 { std::get<2>(id_2770) };
                              bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_2772 { std::get<2>(id_2771) };
                              bf5e3bf9cedd12797481a910416c04b9 id_2773 { std::get<0>(id_2772) };
                              uint16_t id_2774 { uint16_t(id_2773.index()) };
                              bool id_2775 { bool(id_2768 == id_2774) };
                              Size choose_res_2776;
                              if (id_2775) {
                                Size id_2777 { 2UL };
                                Size id_2778 { Size(sz_1053 + id_2777) };
                                Size id_2779 { 2UL };
                                Size id_2780 { Size(id_2778 + id_2779) };
                                choose_res_2776 = id_2780;
                              } else {
                                uint16_t id_2781 { 1 };
                                dc31f5cc689133a6f12d16478388e785 id_2782 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_2783 { std::get<5>(id_2782) };
                                v_2a737e40b715df686303c32fcaefae73 id_2784 { std::get<2>(id_2783) };
                                bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_2785 { std::get<2>(id_2784) };
                                bf5e3bf9cedd12797481a910416c04b9 id_2786 { std::get<0>(id_2785) };
                                uint16_t id_2787 { uint16_t(id_2786.index()) };
                                bool id_2788 { bool(id_2781 == id_2787) };
                                Size choose_res_2789;
                                if (id_2788) {
                                  Size id_2790 { 2UL };
                                  Size id_2791 { Size(sz_1053 + id_2790) };
                                  Size id_2792 { 2UL };
                                  Size id_2793 { Size(id_2791 + id_2792) };
                                  choose_res_2789 = id_2793;
                                } else {
                                  dc31f5cc689133a6f12d16478388e785 id_2794 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_2795 { std::get<5>(id_2794) };
                                  v_2a737e40b715df686303c32fcaefae73 id_2796 { std::get<2>(id_2795) };
                                  bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_2797 { std::get<2>(id_2796) };
                                  bf5e3bf9cedd12797481a910416c04b9 id_2798 { std::get<0>(id_2797) };
                                  uint16_t id_2799 { uint16_t(id_2798.index()) };
                                  uint16_t id_2800 { 2 };
                                  bool id_2801 { bool(id_2799 == id_2800) };
                                  Void id_2802 { ((void)(assert(id_2801)), VOID) };
                                  Size id_2803 { 2UL };
                                  Size id_2804 { Size(sz_1053 + id_2803) };
                                  Size id_2805 { 2UL };
                                  Size id_2806 { Size(id_2804 + id_2805) };
                                  Size id_2807 { 1UL };
                                  Size id_2808 { Size(id_2806 + id_2807) };
                                  choose_res_2789 = id_2808;
                                }
                                choose_res_2776 = choose_res_2789;
                              }
                              dc31f5cc689133a6f12d16478388e785 id_2809 { p_0.text };
                              v_58c653b3fc47800248b5c8f49e80fabb id_2810 { std::get<5>(id_2809) };
                              v_2a737e40b715df686303c32fcaefae73 id_2811 { std::get<2>(id_2810) };
                              bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_2812 { std::get<2>(id_2811) };
                              t* id_2813 { std::get<1>(id_2812) };
                              Size id_2814 { fun1474(id_2813) };
                              Size id_2815 { Size(choose_res_2776 + id_2814) };
                              dc31f5cc689133a6f12d16478388e785 id_2816 { p_0.text };
                              v_58c653b3fc47800248b5c8f49e80fabb id_2817 { std::get<5>(id_2816) };
                              v_2a737e40b715df686303c32fcaefae73 id_2818 { std::get<2>(id_2817) };
                              bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_2819 { std::get<2>(id_2818) };
                              t* id_2820 { std::get<2>(id_2819) };
                              Size id_2821 { fun1474(id_2820) };
                              Size id_2822 { Size(id_2815 + id_2821) };
                              dc31f5cc689133a6f12d16478388e785 id_2823 { p_0.text };
                              v_58c653b3fc47800248b5c8f49e80fabb id_2824 { std::get<5>(id_2823) };
                              v_2a737e40b715df686303c32fcaefae73 id_2825 { std::get<2>(id_2824) };
                              bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_2826 { std::get<2>(id_2825) };
                              t* id_2827 { std::get<3>(id_2826) };
                              Size id_2828 { fun1474(id_2827) };
                              Size id_2829 { Size(id_2822 + id_2828) };
                              choose_res_2767 = id_2829;
                            } else {
                              uint16_t id_2830 { 3 };
                              bool id_2831 { bool(id_2830 == label2_1054) };
                              Size choose_res_2832;
                              if (id_2831) {
                                uint16_t id_2833 { 0 };
                                dc31f5cc689133a6f12d16478388e785 id_2834 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_2835 { std::get<5>(id_2834) };
                                v_2a737e40b715df686303c32fcaefae73 id_2836 { std::get<2>(id_2835) };
                                v_853c6bada9e3fde79da0a65d1b1d1c9a id_2837 { std::get<3>(id_2836) };
                                v_87b032206ceea8867a37c2e0aaee953e id_2838 { std::get<0>(id_2837) };
                                uint16_t id_2839 { uint16_t(id_2838.index()) };
                                bool id_2840 { bool(id_2833 == id_2839) };
                                Size choose_res_2841;
                                if (id_2840) {
                                  Size id_2842 { 2UL };
                                  Size id_2843 { Size(sz_1053 + id_2842) };
                                  Size id_2844 { 2UL };
                                  Size id_2845 { Size(id_2843 + id_2844) };
                                  choose_res_2841 = id_2845;
                                } else {
                                  dc31f5cc689133a6f12d16478388e785 id_2846 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_2847 { std::get<5>(id_2846) };
                                  v_2a737e40b715df686303c32fcaefae73 id_2848 { std::get<2>(id_2847) };
                                  v_853c6bada9e3fde79da0a65d1b1d1c9a id_2849 { std::get<3>(id_2848) };
                                  v_87b032206ceea8867a37c2e0aaee953e id_2850 { std::get<0>(id_2849) };
                                  uint16_t id_2851 { uint16_t(id_2850.index()) };
                                  uint16_t id_2852 { 1 };
                                  bool id_2853 { bool(id_2851 == id_2852) };
                                  Void id_2854 { ((void)(assert(id_2853)), VOID) };
                                  Size id_2855 { 2UL };
                                  Size id_2856 { Size(sz_1053 + id_2855) };
                                  Size id_2857 { 2UL };
                                  Size id_2858 { Size(id_2856 + id_2857) };
                                  Size id_2859 { 1UL };
                                  Size id_2860 { Size(id_2858 + id_2859) };
                                  choose_res_2841 = id_2860;
                                }
                                dc31f5cc689133a6f12d16478388e785 id_2861 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_2862 { std::get<5>(id_2861) };
                                v_2a737e40b715df686303c32fcaefae73 id_2863 { std::get<2>(id_2862) };
                                v_853c6bada9e3fde79da0a65d1b1d1c9a id_2864 { std::get<3>(id_2863) };
                                t* id_2865 { std::get<1>(id_2864) };
                                Size id_2866 { fun1474(id_2865) };
                                Size id_2867 { Size(choose_res_2841 + id_2866) };
                                dc31f5cc689133a6f12d16478388e785 id_2868 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_2869 { std::get<5>(id_2868) };
                                v_2a737e40b715df686303c32fcaefae73 id_2870 { std::get<2>(id_2869) };
                                v_853c6bada9e3fde79da0a65d1b1d1c9a id_2871 { std::get<3>(id_2870) };
                                t* id_2872 { std::get<2>(id_2871) };
                                Size id_2873 { fun1474(id_2872) };
                                Size id_2874 { Size(id_2867 + id_2873) };
                                dc31f5cc689133a6f12d16478388e785 id_2875 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_2876 { std::get<5>(id_2875) };
                                v_2a737e40b715df686303c32fcaefae73 id_2877 { std::get<2>(id_2876) };
                                v_853c6bada9e3fde79da0a65d1b1d1c9a id_2878 { std::get<3>(id_2877) };
                                t* id_2879 { std::get<3>(id_2878) };
                                Size id_2880 { fun1474(id_2879) };
                                Size id_2881 { Size(id_2874 + id_2880) };
                                dc31f5cc689133a6f12d16478388e785 id_2882 { p_0.text };
                                v_58c653b3fc47800248b5c8f49e80fabb id_2883 { std::get<5>(id_2882) };
                                v_2a737e40b715df686303c32fcaefae73 id_2884 { std::get<2>(id_2883) };
                                v_853c6bada9e3fde79da0a65d1b1d1c9a id_2885 { std::get<3>(id_2884) };
                                t* id_2886 { std::get<4>(id_2885) };
                                Size id_2887 { fun1474(id_2886) };
                                Size id_2888 { Size(id_2881 + id_2887) };
                                choose_res_2832 = id_2888;
                              } else {
                                uint16_t id_2889 { 4 };
                                bool id_2890 { bool(id_2889 == label2_1054) };
                                Size choose_res_2891;
                                if (id_2890) {
                                  uint16_t id_2892 { 0 };
                                  dc31f5cc689133a6f12d16478388e785 id_2893 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_2894 { std::get<5>(id_2893) };
                                  v_2a737e40b715df686303c32fcaefae73 id_2895 { std::get<2>(id_2894) };
                                  d48e39cf1002fefa9b2dd8287b9e36b3 id_2896 { std::get<4>(id_2895) };
                                  v_40203346c83d9d499f90ff16996e8968 id_2897 { std::get<0>(id_2896) };
                                  uint16_t id_2898 { uint16_t(id_2897.index()) };
                                  bool id_2899 { bool(id_2892 == id_2898) };
                                  Size choose_res_2900;
                                  if (id_2899) {
                                    Size id_2901 { 2UL };
                                    Size id_2902 { Size(sz_1053 + id_2901) };
                                    Size id_2903 { 2UL };
                                    Size id_2904 { Size(id_2902 + id_2903) };
                                    choose_res_2900 = id_2904;
                                  } else {
                                    dc31f5cc689133a6f12d16478388e785 id_2905 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_2906 { std::get<5>(id_2905) };
                                    v_2a737e40b715df686303c32fcaefae73 id_2907 { std::get<2>(id_2906) };
                                    d48e39cf1002fefa9b2dd8287b9e36b3 id_2908 { std::get<4>(id_2907) };
                                    v_40203346c83d9d499f90ff16996e8968 id_2909 { std::get<0>(id_2908) };
                                    uint16_t id_2910 { uint16_t(id_2909.index()) };
                                    uint16_t id_2911 { 1 };
                                    bool id_2912 { bool(id_2910 == id_2911) };
                                    Void id_2913 { ((void)(assert(id_2912)), VOID) };
                                    Size id_2914 { 2UL };
                                    Size id_2915 { Size(sz_1053 + id_2914) };
                                    Size id_2916 { 2UL };
                                    Size id_2917 { Size(id_2915 + id_2916) };
                                    Size id_2918 { 1UL };
                                    Size id_2919 { Size(id_2917 + id_2918) };
                                    Size id_2920 { 1UL };
                                    Size id_2921 { Size(id_2919 + id_2920) };
                                    choose_res_2900 = id_2921;
                                  }
                                  dc31f5cc689133a6f12d16478388e785 id_2922 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_2923 { std::get<5>(id_2922) };
                                  v_2a737e40b715df686303c32fcaefae73 id_2924 { std::get<2>(id_2923) };
                                  d48e39cf1002fefa9b2dd8287b9e36b3 id_2925 { std::get<4>(id_2924) };
                                  t* id_2926 { std::get<1>(id_2925) };
                                  Size id_2927 { fun1474(id_2926) };
                                  Size id_2928 { Size(choose_res_2900 + id_2927) };
                                  dc31f5cc689133a6f12d16478388e785 id_2929 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_2930 { std::get<5>(id_2929) };
                                  v_2a737e40b715df686303c32fcaefae73 id_2931 { std::get<2>(id_2930) };
                                  d48e39cf1002fefa9b2dd8287b9e36b3 id_2932 { std::get<4>(id_2931) };
                                  t* id_2933 { std::get<2>(id_2932) };
                                  Size id_2934 { fun1474(id_2933) };
                                  Size id_2935 { Size(id_2928 + id_2934) };
                                  dc31f5cc689133a6f12d16478388e785 id_2936 { p_0.text };
                                  v_58c653b3fc47800248b5c8f49e80fabb id_2937 { std::get<5>(id_2936) };
                                  v_2a737e40b715df686303c32fcaefae73 id_2938 { std::get<2>(id_2937) };
                                  d48e39cf1002fefa9b2dd8287b9e36b3 id_2939 { std::get<4>(id_2938) };
                                  t* id_2940 { std::get<3>(id_2939) };
                                  Size id_2941 { fun1474(id_2940) };
                                  Size id_2942 { Size(id_2935 + id_2941) };
                                  Size let_res_2943;
                                  {
                                    Size sz_1083 { id_2942 };
                                    dc31f5cc689133a6f12d16478388e785 id_2944 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_2945 { std::get<5>(id_2944) };
                                    v_2a737e40b715df686303c32fcaefae73 id_2946 { std::get<2>(id_2945) };
                                    d48e39cf1002fefa9b2dd8287b9e36b3 id_2947 { std::get<4>(id_2946) };
                                    Lst<t*> id_2948 { std::get<4>(id_2947) };
                                    uint32_t id_2949 { id_2948.size() };
                                    Vec<1, uint32_t> id_2950 {  id_2949  };
                                    Size let_res_2951;
                                    {
                                      Vec<1, uint32_t> n_ref_1084 { id_2950 };
                                      uint32_t id_2952 { 1U };
                                      Vec<1, uint32_t> id_2953 {  id_2952  };
                                      Size let_res_2954;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_1085 { id_2953 };
                                        bool while_flag_2955 { true };
                                        do {
                                          uint8_t id_2956 { 0 };
                                          uint32_t id_2957 { n_ref_1084[id_2956] };
                                          uint8_t id_2958 { 0 };
                                          uint32_t id_2959 { lebsz_ref_1085[id_2958] };
                                          uint8_t id_2960 { 7 };
                                          uint32_t id_2961 { uint32_t(id_2959 << id_2960) };
                                          bool id_2962 { bool(id_2957 >= id_2961) };
                                          while_flag_2955 = id_2962;
                                          if (while_flag_2955) {
                                            uint8_t id_2963 { 0 };
                                            uint8_t id_2964 { 0 };
                                            uint32_t id_2965 { lebsz_ref_1085[id_2964] };
                                            uint32_t id_2966 { 1U };
                                            uint32_t id_2967 { uint32_t(id_2965 + id_2966) };
                                            Void id_2968 { ((void)(lebsz_ref_1085[id_2963] = id_2967), VOID) };
                                          }
                                        } while (while_flag_2955);
                                        uint8_t id_2969 { 0 };
                                        uint32_t id_2970 { lebsz_ref_1085[id_2969] };
                                        Size id_2971 { Size(id_2970) };
                                        let_res_2954 = id_2971;
                                      }
                                      let_res_2951 = let_res_2954;
                                    }
                                    Size id_2972 { Size(sz_1083 + let_res_2951) };
                                    Vec<1, Size> id_2973 {  id_2972  };
                                    Size let_res_2974;
                                    {
                                      Vec<1, Size> sz_ref_1086 { id_2973 };
                                      int32_t id_2975 { 0L };
                                      Vec<1, int32_t> id_2976 {  id_2975  };
                                      {
                                        Vec<1, int32_t> repeat_n_1087 { id_2976 };
                                        bool while_flag_2977 { true };
                                        do {
                                          dc31f5cc689133a6f12d16478388e785 id_2978 { p_0.text };
                                          v_58c653b3fc47800248b5c8f49e80fabb id_2979 { std::get<5>(id_2978) };
                                          v_2a737e40b715df686303c32fcaefae73 id_2980 { std::get<2>(id_2979) };
                                          d48e39cf1002fefa9b2dd8287b9e36b3 id_2981 { std::get<4>(id_2980) };
                                          Lst<t*> id_2982 { std::get<4>(id_2981) };
                                          uint32_t id_2983 { id_2982.size() };
                                          int32_t id_2984 { int32_t(id_2983) };
                                          uint8_t id_2985 { 0 };
                                          int32_t id_2986 { repeat_n_1087[id_2985] };
                                          bool id_2987 { bool(id_2984 > id_2986) };
                                          while_flag_2977 = id_2987;
                                          if (while_flag_2977) {
                                            uint8_t id_2988 { 0 };
                                            uint8_t id_2989 { 0 };
                                            Size id_2990 { sz_ref_1086[id_2989] };
                                            uint8_t id_2991 { 0 };
                                            int32_t id_2992 { repeat_n_1087[id_2991] };
                                            dc31f5cc689133a6f12d16478388e785 id_2993 { p_0.text };
                                            v_58c653b3fc47800248b5c8f49e80fabb id_2994 { std::get<5>(id_2993) };
                                            v_2a737e40b715df686303c32fcaefae73 id_2995 { std::get<2>(id_2994) };
                                            d48e39cf1002fefa9b2dd8287b9e36b3 id_2996 { std::get<4>(id_2995) };
                                            Lst<t*> id_2997 { std::get<4>(id_2996) };
                                            t* id_2998 { id_2997[id_2992] };
                                            Size id_2999 { fun1474(id_2998) };
                                            Size id_3000 { Size(id_2990 + id_2999) };
                                            Void id_3001 { ((void)(sz_ref_1086[id_2988] = id_3000), VOID) };
                                            uint8_t id_3002 { 0 };
                                            uint8_t id_3003 { 0 };
                                            int32_t id_3004 { repeat_n_1087[id_3003] };
                                            int32_t id_3005 { 1L };
                                            int32_t id_3006 { int32_t(id_3004 + id_3005) };
                                            Void id_3007 { ((void)(repeat_n_1087[id_3002] = id_3006), VOID) };
                                          }
                                        } while (while_flag_2977);
                                      }
                                      uint8_t id_3008 { 0 };
                                      Size id_3009 { sz_ref_1086[id_3008] };
                                      let_res_2974 = id_3009;
                                    }
                                    let_res_2943 = let_res_2974;
                                  }
                                  choose_res_2891 = let_res_2943;
                                } else {
                                  uint16_t id_3010 { 5 };
                                  bool id_3011 { bool(id_3010 == label2_1054) };
                                  Size choose_res_3012;
                                  if (id_3011) {
                                    dc31f5cc689133a6f12d16478388e785 id_3013 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_3014 { std::get<5>(id_3013) };
                                    v_2a737e40b715df686303c32fcaefae73 id_3015 { std::get<2>(id_3014) };
                                    v_28696cf4b42cc9ab09b392e5143f2f25 id_3016 { std::get<5>(id_3015) };
                                    d137ffedb0c351c86760c7f124759f50 id_3017 { std::get<0>(id_3016) };
                                    uint16_t id_3018 { uint16_t(id_3017.index()) };
                                    uint16_t id_3019 { 0 };
                                    bool id_3020 { bool(id_3018 == id_3019) };
                                    Void id_3021 { ((void)(assert(id_3020)), VOID) };
                                    Size id_3022 { 2UL };
                                    Size id_3023 { Size(sz_1053 + id_3022) };
                                    Size id_3024 { 2UL };
                                    Size id_3025 { Size(id_3023 + id_3024) };
                                    dc31f5cc689133a6f12d16478388e785 id_3026 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_3027 { std::get<5>(id_3026) };
                                    v_2a737e40b715df686303c32fcaefae73 id_3028 { std::get<2>(id_3027) };
                                    v_28696cf4b42cc9ab09b392e5143f2f25 id_3029 { std::get<5>(id_3028) };
                                    t* id_3030 { std::get<1>(id_3029) };
                                    Size id_3031 { fun1474(id_3030) };
                                    Size id_3032 { Size(id_3025 + id_3031) };
                                    dc31f5cc689133a6f12d16478388e785 id_3033 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_3034 { std::get<5>(id_3033) };
                                    v_2a737e40b715df686303c32fcaefae73 id_3035 { std::get<2>(id_3034) };
                                    v_28696cf4b42cc9ab09b392e5143f2f25 id_3036 { std::get<5>(id_3035) };
                                    t* id_3037 { std::get<2>(id_3036) };
                                    Size id_3038 { fun1474(id_3037) };
                                    Size id_3039 { Size(id_3032 + id_3038) };
                                    dc31f5cc689133a6f12d16478388e785 id_3040 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_3041 { std::get<5>(id_3040) };
                                    v_2a737e40b715df686303c32fcaefae73 id_3042 { std::get<2>(id_3041) };
                                    v_28696cf4b42cc9ab09b392e5143f2f25 id_3043 { std::get<5>(id_3042) };
                                    t* id_3044 { std::get<3>(id_3043) };
                                    Size id_3045 { fun1474(id_3044) };
                                    Size id_3046 { Size(id_3039 + id_3045) };
                                    dc31f5cc689133a6f12d16478388e785 id_3047 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_3048 { std::get<5>(id_3047) };
                                    v_2a737e40b715df686303c32fcaefae73 id_3049 { std::get<2>(id_3048) };
                                    v_28696cf4b42cc9ab09b392e5143f2f25 id_3050 { std::get<5>(id_3049) };
                                    t* id_3051 { std::get<4>(id_3050) };
                                    Size id_3052 { fun1474(id_3051) };
                                    Size id_3053 { Size(id_3046 + id_3052) };
                                    dc31f5cc689133a6f12d16478388e785 id_3054 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_3055 { std::get<5>(id_3054) };
                                    v_2a737e40b715df686303c32fcaefae73 id_3056 { std::get<2>(id_3055) };
                                    v_28696cf4b42cc9ab09b392e5143f2f25 id_3057 { std::get<5>(id_3056) };
                                    t* id_3058 { std::get<5>(id_3057) };
                                    Size id_3059 { fun1474(id_3058) };
                                    Size id_3060 { Size(id_3053 + id_3059) };
                                    dc31f5cc689133a6f12d16478388e785 id_3061 { p_0.text };
                                    v_58c653b3fc47800248b5c8f49e80fabb id_3062 { std::get<5>(id_3061) };
                                    v_2a737e40b715df686303c32fcaefae73 id_3063 { std::get<2>(id_3062) };
                                    v_28696cf4b42cc9ab09b392e5143f2f25 id_3064 { std::get<5>(id_3063) };
                                    t* id_3065 { std::get<6>(id_3064) };
                                    Size id_3066 { fun1474(id_3065) };
                                    Size id_3067 { Size(id_3060 + id_3066) };
                                    choose_res_3012 = id_3067;
                                  } else {
                                    uint16_t id_3068 { 6 };
                                    bool id_3069 { bool(id_3068 == label2_1054) };
                                    Size choose_res_3070;
                                    if (id_3069) {
                                      Size id_3071 { 2UL };
                                      Size id_3072 { Size(sz_1053 + id_3071) };
                                      std::function<Size(dessser::gen::raql_top_output::t)> id_3073 { dessser::gen::raql_top_output::sersize_of_row_binary };
                                      dc31f5cc689133a6f12d16478388e785 id_3074 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3075 { std::get<5>(id_3074) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3076 { std::get<2>(id_3075) };
                                      v_2da729c5f96e51679cb6e2c06e6ceb25 id_3077 { std::get<6>(id_3076) };
                                      dessser::gen::raql_top_output::t id_3078 { id_3077.output };
                                      Size id_3079 { id_3073(id_3078) };
                                      Size id_3080 { Size(id_3072 + id_3079) };
                                      dc31f5cc689133a6f12d16478388e785 id_3081 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3082 { std::get<5>(id_3081) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3083 { std::get<2>(id_3082) };
                                      v_2da729c5f96e51679cb6e2c06e6ceb25 id_3084 { std::get<6>(id_3083) };
                                      t* id_3085 { id_3084.size };
                                      Size id_3086 { fun1474(id_3085) };
                                      Size id_3087 { Size(id_3080 + id_3086) };
                                      Size let_res_3088;
                                      {
                                        Size sz_1062 { id_3087 };
                                        dc31f5cc689133a6f12d16478388e785 id_3089 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_3090 { std::get<5>(id_3089) };
                                        v_2a737e40b715df686303c32fcaefae73 id_3091 { std::get<2>(id_3090) };
                                        v_2da729c5f96e51679cb6e2c06e6ceb25 id_3092 { std::get<6>(id_3091) };
                                        std::optional<t*> id_3093 { id_3092.max_size };
                                        bool id_3094 { !(id_3093.has_value ()) };
                                        Size choose_res_3095;
                                        if (id_3094) {
                                          Size id_3096 { 1UL };
                                          Size id_3097 { Size(sz_1062 + id_3096) };
                                          choose_res_3095 = id_3097;
                                        } else {
                                          dc31f5cc689133a6f12d16478388e785 id_3098 { p_0.text };
                                          v_58c653b3fc47800248b5c8f49e80fabb id_3099 { std::get<5>(id_3098) };
                                          v_2a737e40b715df686303c32fcaefae73 id_3100 { std::get<2>(id_3099) };
                                          v_2da729c5f96e51679cb6e2c06e6ceb25 id_3101 { std::get<6>(id_3100) };
                                          std::optional<t*> id_3102 { id_3101.max_size };
                                          t* id_3103 { id_3102.value() };
                                          Size id_3104 { fun1474(id_3103) };
                                          Size id_3105 { Size(sz_1062 + id_3104) };
                                          Size id_3106 { 1UL };
                                          Size id_3107 { Size(id_3105 + id_3106) };
                                          choose_res_3095 = id_3107;
                                        }
                                        let_res_3088 = choose_res_3095;
                                      }
                                      dc31f5cc689133a6f12d16478388e785 id_3108 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3109 { std::get<5>(id_3108) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3110 { std::get<2>(id_3109) };
                                      v_2da729c5f96e51679cb6e2c06e6ceb25 id_3111 { std::get<6>(id_3110) };
                                      t* id_3112 { id_3111.what };
                                      Size id_3113 { fun1474(id_3112) };
                                      Size id_3114 { Size(let_res_3088 + id_3113) };
                                      dc31f5cc689133a6f12d16478388e785 id_3115 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3116 { std::get<5>(id_3115) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3117 { std::get<2>(id_3116) };
                                      v_2da729c5f96e51679cb6e2c06e6ceb25 id_3118 { std::get<6>(id_3117) };
                                      t* id_3119 { id_3118.by };
                                      Size id_3120 { fun1474(id_3119) };
                                      Size id_3121 { Size(id_3114 + id_3120) };
                                      dc31f5cc689133a6f12d16478388e785 id_3122 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3123 { std::get<5>(id_3122) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3124 { std::get<2>(id_3123) };
                                      v_2da729c5f96e51679cb6e2c06e6ceb25 id_3125 { std::get<6>(id_3124) };
                                      t* id_3126 { id_3125.time };
                                      Size id_3127 { fun1474(id_3126) };
                                      Size id_3128 { Size(id_3121 + id_3127) };
                                      dc31f5cc689133a6f12d16478388e785 id_3129 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3130 { std::get<5>(id_3129) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3131 { std::get<2>(id_3130) };
                                      v_2da729c5f96e51679cb6e2c06e6ceb25 id_3132 { std::get<6>(id_3131) };
                                      t* id_3133 { id_3132.duration };
                                      Size id_3134 { fun1474(id_3133) };
                                      Size id_3135 { Size(id_3128 + id_3134) };
                                      dc31f5cc689133a6f12d16478388e785 id_3136 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3137 { std::get<5>(id_3136) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3138 { std::get<2>(id_3137) };
                                      v_2da729c5f96e51679cb6e2c06e6ceb25 id_3139 { std::get<6>(id_3138) };
                                      t* id_3140 { id_3139.sigmas };
                                      Size id_3141 { fun1474(id_3140) };
                                      Size id_3142 { Size(id_3135 + id_3141) };
                                      choose_res_3070 = id_3142;
                                    } else {
                                      uint16_t id_3143 { 7 };
                                      bool id_3144 { bool(label2_1054 == id_3143) };
                                      Void id_3145 { ((void)(assert(id_3144)), VOID) };
                                      Size id_3146 { 2UL };
                                      Size id_3147 { Size(sz_1053 + id_3146) };
                                      dc31f5cc689133a6f12d16478388e785 id_3148 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3149 { std::get<5>(id_3148) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3150 { std::get<2>(id_3149) };
                                      v_148d37e471eb6790a77b16fc96041a20 id_3151 { std::get<7>(id_3150) };
                                      t* id_3152 { id_3151.what };
                                      Size id_3153 { fun1474(id_3152) };
                                      Size id_3154 { Size(id_3147 + id_3153) };
                                      dc31f5cc689133a6f12d16478388e785 id_3155 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3156 { std::get<5>(id_3155) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3157 { std::get<2>(id_3156) };
                                      v_148d37e471eb6790a77b16fc96041a20 id_3158 { std::get<7>(id_3157) };
                                      t* id_3159 { id_3158.time };
                                      Size id_3160 { fun1474(id_3159) };
                                      Size id_3161 { Size(id_3154 + id_3160) };
                                      dc31f5cc689133a6f12d16478388e785 id_3162 { p_0.text };
                                      v_58c653b3fc47800248b5c8f49e80fabb id_3163 { std::get<5>(id_3162) };
                                      v_2a737e40b715df686303c32fcaefae73 id_3164 { std::get<2>(id_3163) };
                                      v_148d37e471eb6790a77b16fc96041a20 id_3165 { std::get<7>(id_3164) };
                                      t* id_3166 { id_3165.max_age };
                                      Size id_3167 { fun1474(id_3166) };
                                      Size id_3168 { Size(id_3161 + id_3167) };
                                      Size id_3169 { 1UL };
                                      Size id_3170 { Size(id_3168 + id_3169) };
                                      Size let_res_3171;
                                      {
                                        Size sz_1059 { id_3170 };
                                        dc31f5cc689133a6f12d16478388e785 id_3172 { p_0.text };
                                        v_58c653b3fc47800248b5c8f49e80fabb id_3173 { std::get<5>(id_3172) };
                                        v_2a737e40b715df686303c32fcaefae73 id_3174 { std::get<2>(id_3173) };
                                        v_148d37e471eb6790a77b16fc96041a20 id_3175 { std::get<7>(id_3174) };
                                        std::optional<t*> id_3176 { id_3175.sample_size };
                                        bool id_3177 { !(id_3176.has_value ()) };
                                        Size choose_res_3178;
                                        if (id_3177) {
                                          Size id_3179 { 1UL };
                                          Size id_3180 { Size(sz_1059 + id_3179) };
                                          choose_res_3178 = id_3180;
                                        } else {
                                          dc31f5cc689133a6f12d16478388e785 id_3181 { p_0.text };
                                          v_58c653b3fc47800248b5c8f49e80fabb id_3182 { std::get<5>(id_3181) };
                                          v_2a737e40b715df686303c32fcaefae73 id_3183 { std::get<2>(id_3182) };
                                          v_148d37e471eb6790a77b16fc96041a20 id_3184 { std::get<7>(id_3183) };
                                          std::optional<t*> id_3185 { id_3184.sample_size };
                                          t* id_3186 { id_3185.value() };
                                          Size id_3187 { fun1474(id_3186) };
                                          Size id_3188 { Size(sz_1059 + id_3187) };
                                          Size id_3189 { 1UL };
                                          Size id_3190 { Size(id_3188 + id_3189) };
                                          choose_res_3178 = id_3190;
                                        }
                                        let_res_3171 = choose_res_3178;
                                      }
                                      choose_res_3070 = let_res_3171;
                                    }
                                    choose_res_3012 = choose_res_3070;
                                  }
                                  choose_res_2891 = choose_res_3012;
                                }
                                choose_res_2832 = choose_res_2891;
                              }
                              choose_res_2767 = choose_res_2832;
                            }
                            choose_res_2715 = choose_res_2767;
                          }
                          choose_res_2614 = choose_res_2715;
                        }
                        let_res_2611 = choose_res_2614;
                      }
                      let_res_2606 = let_res_2611;
                    }
                    choose_res_2581 = let_res_2606;
                  } else {
                    uint16_t id_3191 { 6 };
                    bool id_3192 { bool(label2_1046 == id_3191) };
                    Void id_3193 { ((void)(assert(id_3192)), VOID) };
                    dc31f5cc689133a6f12d16478388e785 id_3194 { p_0.text };
                    v_1c5224020b28e5bf4853392434fd6e31 id_3195 { std::get<6>(id_3194) };
                    uint16_t id_3196 { uint16_t(id_3195.index()) };
                    uint16_t id_3197 { 0 };
                    bool id_3198 { bool(id_3196 == id_3197) };
                    Void id_3199 { ((void)(assert(id_3198)), VOID) };
                    Size id_3200 { 2UL };
                    Size id_3201 { Size(sz_1045 + id_3200) };
                    Size id_3202 { 2UL };
                    Size id_3203 { Size(id_3201 + id_3202) };
                    dc31f5cc689133a6f12d16478388e785 id_3204 { p_0.text };
                    v_1c5224020b28e5bf4853392434fd6e31 id_3205 { std::get<6>(id_3204) };
                    v_88361d7e3c5fc5844d2ff9213ba400b1 id_3206 { std::get<0>(id_3205) };
                    t* id_3207 { std::get<0>(id_3206) };
                    Size id_3208 { fun1474(id_3207) };
                    Size id_3209 { Size(id_3203 + id_3208) };
                    dc31f5cc689133a6f12d16478388e785 id_3210 { p_0.text };
                    v_1c5224020b28e5bf4853392434fd6e31 id_3211 { std::get<6>(id_3210) };
                    v_88361d7e3c5fc5844d2ff9213ba400b1 id_3212 { std::get<0>(id_3211) };
                    t* id_3213 { std::get<1>(id_3212) };
                    Size id_3214 { fun1474(id_3213) };
                    Size id_3215 { Size(id_3209 + id_3214) };
                    choose_res_2581 = id_3215;
                  }
                  choose_res_1771 = choose_res_2581;
                }
                choose_res_1680 = choose_res_1771;
              }
              choose_res_1618 = choose_res_1680;
            }
            choose_res_1544 = choose_res_1618;
          }
          choose_res_1482 = choose_res_1544;
        }
        let_res_1479 = choose_res_1482;
      }
      let_res_1476 = let_res_1479;
    }
    Size id_3216 { 4UL };
    Size id_3217 { Size(let_res_1476 + id_3216) };
    Size let_res_3218;
    {
      Size sz_1163 { id_3217 };
      std::function<Size(dessser::gen::raql_type::t)> id_3219 { dessser::gen::raql_type::sersize_of_row_binary };
      dessser::gen::raql_type::t id_3220 { p_0.typ };
      Size id_3221 { id_3219(id_3220) };
      Size id_3222 { Size(sz_1163 + id_3221) };
      let_res_3218 = id_3222;
    }
    Size let_res_3223;
    {
      Size sz_1164 { let_res_3218 };
      std::optional<dessser::gen::units::t> id_3224 { p_0.units };
      bool id_3225 { !(id_3224.has_value ()) };
      Size choose_res_3226;
      if (id_3225) {
        Size id_3227 { 1UL };
        Size id_3228 { Size(sz_1164 + id_3227) };
        choose_res_3226 = id_3228;
      } else {
        std::function<Size(dessser::gen::units::t)> id_3229 { dessser::gen::units::sersize_of_row_binary };
        std::optional<dessser::gen::units::t> id_3230 { p_0.units };
        dessser::gen::units::t id_3231 { id_3230.value() };
        Size id_3232 { id_3229(id_3231) };
        Size id_3233 { Size(sz_1164 + id_3232) };
        Size id_3234 { 1UL };
        Size id_3235 { Size(id_3233 + id_3234) };
        choose_res_3226 = id_3235;
      }
      let_res_3223 = choose_res_3226;
    }
    return let_res_3223;
  }
   };
  return fun1474;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_1024"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let-pair "dlist4_fst_1019" "dlist4_snd_1020"
                (let "dlist1_1007"
                  (let "leb_ref_998" (make-vec (u32 0))
                    (let "shft_ref_999" (make-vec (u8 0))
                      (let "p_ref_1000" (make-vec (identifier "dsum1_snd_64"))
                        (seq
                          (while
                            (let "leb128_1001" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_1000")))
                              (let-pair "leb128_fst_1002" "leb128_snd_1003" 
                                (identifier "leb128_1001")
                                (seq (set-vec (u8 0) (identifier "p_ref_1000") (identifier "leb128_snd_1003"))
                                  (set-vec (u8 0) (identifier "leb_ref_998")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_1002") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_999"))) (unsafe-nth (u8 0) (identifier "leb_ref_998"))))
                                  (set-vec (u8 0) (identifier "shft_ref_999") (add (unsafe-nth (u8 0) (identifier "shft_ref_999")) (u8 7))) 
                                  (ge (identifier "leb128_fst_1002") (u8 128))))) 
                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_998")) (unsafe-nth (u8 0) (identifier "p_ref_1000")))))))
                  (let-pair "dlist1_fst_1008" "dlist1_snd_1009" (identifier "dlist1_1007")
                    (let "inits_src_ref_1010" (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_1009")))
                      (seq
                        (let "repeat_n_1011" (make-vec (i32 0))
                          (while (gt (to-i32 (identifier "dlist1_fst_1008")) (unsafe-nth (u8 0) (identifier "repeat_n_1011")))
                            (seq
                              (let "dlist2_1012" (unsafe-nth (u8 0) (identifier "inits_src_ref_1010"))
                                (let-pair "dlist2_fst_1013" "dlist2_snd_1014" 
                                  (identifier "dlist2_1012")
                                  (set-vec (u8 0) (identifier "inits_src_ref_1010")
                                    (let-pair "dlist3_fst_1016" "dlist3_snd_1017" 
                                      (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_1014")) 
                                      (make-tup (cons (identifier "dlist3_fst_1016") (identifier "dlist2_fst_1013")) (identifier "dlist3_snd_1017"))))))
                              (set-vec (u8 0) (identifier "repeat_n_1011") (add (unsafe-nth (u8 0) (identifier "repeat_n_1011")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "inits_src_ref_1010"))))))
                (make-tup
                  (construct "[Tuple THIS[[]] | Record ($field_name; THIS)[[]] | Vector THIS[[]] | Case ({case_cond: THIS; case_cons: THIS}[[]]; THIS?) | Stateless [SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)] | Stateful ([LocalState Void | GlobalState Void]; BOOL; [SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]) | Generator [Split (THIS; THIS)]]" 0
                    (identity (identifier "dlist4_fst_1019"))) (identifier "dlist4_snd_1020")))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let-pair "dlist4_fst_993" "dlist4_snd_994"
                  (let "dlist1_975"
                    (let "leb_ref_966" (make-vec (u32 0))
                      (let "shft_ref_967" (make-vec (u8 0))
                        (let "p_ref_968" (make-vec (identifier "dsum1_snd_64"))
                          (seq
                            (while
                              (let "leb128_969" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_968")))
                                (let-pair "leb128_fst_970" "leb128_snd_971" 
                                  (identifier "leb128_969")
                                  (seq (set-vec (u8 0) (identifier "p_ref_968") (identifier "leb128_snd_971"))
                                    (set-vec (u8 0) (identifier "leb_ref_966")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_970") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_967"))) (unsafe-nth (u8 0) (identifier "leb_ref_966"))))
                                    (set-vec (u8 0) (identifier "shft_ref_967") (add (unsafe-nth (u8 0) (identifier "shft_ref_967")) (u8 7))) 
                                    (ge (identifier "leb128_fst_970") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_966")) (unsafe-nth (u8 0) (identifier "p_ref_968")))))))
                    (let-pair "dlist1_fst_976" "dlist1_snd_977" (identifier "dlist1_975")
                      (let "inits_src_ref_978" (make-vec (make-tup (end-of-list "($field_name; THIS)") (identifier "dlist1_snd_977")))
                        (seq
                          (let "repeat_n_979" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_976")) (unsafe-nth (u8 0) (identifier "repeat_n_979")))
                              (seq
                                (let "dlist2_980" (unsafe-nth (u8 0) (identifier "inits_src_ref_978"))
                                  (let-pair "dlist2_fst_981" "dlist2_snd_982" 
                                    (identifier "dlist2_980")
                                    (set-vec (u8 0) (identifier "inits_src_ref_978")
                                      (let-pair "dtup_fst_984" "dtup_snd_985" 
                                        (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_982"))
                                        (let-pair "dtup_fst_987" "dtup_snd_988" 
                                          (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_985"))
                                          (make-tup (cons (make-tup (identifier "dtup_fst_984") (identifier "dtup_fst_987")) (identifier "dlist2_fst_981")) (identifier "dtup_snd_988")))))))
                                (set-vec (u8 0) (identifier "repeat_n_979") (add (unsafe-nth (u8 0) (identifier "repeat_n_979")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_978"))))))
                  (make-tup
                    (construct "[Tuple THIS[[]] | Record ($field_name; THIS)[[]] | Vector THIS[[]] | Case ({case_cond: THIS; case_cons: THIS}[[]]; THIS?) | Stateless [SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)] | Stateful ([LocalState Void | GlobalState Void]; BOOL; [SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]) | Generator [Split (THIS; THIS)]]" 1
                      (identity (identifier "dlist4_fst_993"))) (identifier "dlist4_snd_994")))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (let-pair "dlist4_fst_961" "dlist4_snd_962"
                    (let "dlist1_949"
                      (let "leb_ref_940" (make-vec (u32 0))
                        (let "shft_ref_941" (make-vec (u8 0))
                          (let "p_ref_942" (make-vec (identifier "dsum1_snd_64"))
                            (seq
                              (while
                                (let "leb128_943" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_942")))
                                  (let-pair "leb128_fst_944" "leb128_snd_945" 
                                    (identifier "leb128_943")
                                    (seq (set-vec (u8 0) (identifier "p_ref_942") (identifier "leb128_snd_945"))
                                      (set-vec (u8 0) (identifier "leb_ref_940")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_944") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_941"))) (unsafe-nth (u8 0) (identifier "leb_ref_940"))))
                                      (set-vec (u8 0) (identifier "shft_ref_941") (add (unsafe-nth (u8 0) (identifier "shft_ref_941")) (u8 7))) 
                                      (ge (identifier "leb128_fst_944") (u8 128))))) 
                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_940")) (unsafe-nth (u8 0) (identifier "p_ref_942")))))))
                      (let-pair "dlist1_fst_950" "dlist1_snd_951" (identifier "dlist1_949")
                        (let "inits_src_ref_952" (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_951")))
                          (seq
                            (let "repeat_n_953" (make-vec (i32 0))
                              (while (gt (to-i32 (identifier "dlist1_fst_950")) (unsafe-nth (u8 0) (identifier "repeat_n_953")))
                                (seq
                                  (let "dlist2_954" (unsafe-nth (u8 0) (identifier "inits_src_ref_952"))
                                    (let-pair "dlist2_fst_955" "dlist2_snd_956" 
                                      (identifier "dlist2_954")
                                      (set-vec (u8 0) (identifier "inits_src_ref_952")
                                        (let-pair "dlist3_fst_958" "dlist3_snd_959" 
                                          (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_956")) 
                                          (make-tup (cons (identifier "dlist3_fst_958") (identifier "dlist2_fst_955")) (identifier "dlist3_snd_959"))))))
                                  (set-vec (u8 0) (identifier "repeat_n_953") (add (unsafe-nth (u8 0) (identifier "repeat_n_953")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "inits_src_ref_952"))))))
                    (make-tup
                      (construct "[Tuple THIS[[]] | Record ($field_name; THIS)[[]] | Vector THIS[[]] | Case ({case_cond: THIS; case_cons: THIS}[[]]; THIS?) | Stateless [SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)] | Stateful ([LocalState Void | GlobalState Void]; BOOL; [SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]) | Generator [Split (THIS; THIS)]]" 2
                        (identity (identifier "dlist4_fst_961"))) (identifier "dlist4_snd_962")))
                  (if (eq (u16 3) (identifier "dsum1_fst_63"))
                    (let "dtup_928"
                      (let-pair "dlist4_fst_926" "dlist4_snd_927"
                        (let "dlist1_908"
                          (let "leb_ref_899" (make-vec (u32 0))
                            (let "shft_ref_900" (make-vec (u8 0))
                              (let "p_ref_901" (make-vec (identifier "dsum1_snd_64"))
                                (seq
                                  (while
                                    (let "leb128_902" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_901")))
                                      (let-pair "leb128_fst_903" "leb128_snd_904" 
                                        (identifier "leb128_902")
                                        (seq (set-vec (u8 0) (identifier "p_ref_901") (identifier "leb128_snd_904"))
                                          (set-vec (u8 0) (identifier "leb_ref_899")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_903") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_900"))) (unsafe-nth (u8 0) (identifier "leb_ref_899"))))
                                          (set-vec (u8 0) (identifier "shft_ref_900") (add (unsafe-nth (u8 0) (identifier "shft_ref_900")) (u8 7))) 
                                          (ge (identifier "leb128_fst_903") (u8 128))))) 
                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_899")) (unsafe-nth (u8 0) (identifier "p_ref_901")))))))
                          (let-pair "dlist1_fst_909" "dlist1_snd_910" 
                            (identifier "dlist1_908")
                            (let "inits_src_ref_911" (make-vec (make-tup (end-of-list "{case_cond: THIS; case_cons: THIS}") (identifier "dlist1_snd_910")))
                              (seq
                                (let "repeat_n_912" (make-vec (i32 0))
                                  (while (gt (to-i32 (identifier "dlist1_fst_909")) (unsafe-nth (u8 0) (identifier "repeat_n_912")))
                                    (seq
                                      (let "dlist2_913" (unsafe-nth (u8 0) (identifier "inits_src_ref_911"))
                                        (let-pair "dlist2_fst_914" "dlist2_snd_915" 
                                          (identifier "dlist2_913")
                                          (set-vec (u8 0) (identifier "inits_src_ref_911")
                                            (let-pair "drec_fst_917" "drec_snd_918" 
                                              (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_915"))
                                              (let-pair "drec_fst_920" "drec_snd_921" 
                                                (apply (myself "(THIS; Ptr)") (identifier "drec_snd_918"))
                                                (make-tup (cons (make-rec (string "case_cond") (identifier "drec_fst_917") (string "case_cons") (identifier "drec_fst_920")) (identifier "dlist2_fst_914"))
                                                  (identifier "drec_snd_921"))))))) 
                                      (set-vec (u8 0) (identifier "repeat_n_912") (add (unsafe-nth (u8 0) (identifier "repeat_n_912")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "inits_src_ref_911")))))) 
                        (make-tup (identity (identifier "dlist4_fst_926")) (identifier "dlist4_snd_927")))
                      (let-pair "dtup_fst_929" "dtup_snd_930" (identifier "dtup_928")
                        (let-pair "dtup_fst_935" "dtup_snd_936"
                          (if (eq (peek-u8 (identifier "dtup_snd_930") (size 0)) (u8 1)) 
                            (make-tup (null "THIS") (ptr-add (identifier "dtup_snd_930") (size 1)))
                            (let-pair "make1_1_fst_932" "make1_1_snd_933" 
                              (apply (myself "(THIS; Ptr)") (ptr-add (identifier "dtup_snd_930") (size 1))) 
                              (make-tup (not-null (identifier "make1_1_fst_932")) (identifier "make1_1_snd_933"))))
                          (make-tup
                            (construct "[Tuple THIS[[]] | Record ($field_name; THIS)[[]] | Vector THIS[[]] | Case ({case_cond: THIS; case_cons: THIS}[[]]; THIS?) | Stateless [SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)] | Stateful ([LocalState Void | GlobalState Void]; BOOL; [SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]) | Generator [Split (THIS; THIS)]]" 3
                              (make-tup (identifier "dtup_fst_929") (identifier "dtup_fst_935"))) 
                            (identifier "dtup_snd_936")))))
                    (if (eq (u16 4) (identifier "dsum1_fst_63"))
                      (let-pair "dsum2_fst_897" "dsum2_snd_898"
                        (let "dsum1_475" (let-pair "du16_fst_470" "du16_snd_471" (read-u16 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du16_fst_470") (identifier "du16_snd_471")))
                          (let-pair "dsum1_fst_476" "dsum1_snd_477" (identifier "dsum1_475")
                            (if (eq (u16 0) (identifier "dsum1_fst_476"))
                              (let-pair "dsum2_fst_894" "dsum2_snd_895"
                                (let "dsum1_840" (let-pair "du16_fst_835" "du16_snd_836" (read-u16 little-endian (identifier "dsum1_snd_477")) (make-tup (identifier "du16_fst_835") (identifier "du16_snd_836")))
                                  (let-pair "dsum1_fst_841" "dsum1_snd_842" 
                                    (identifier "dsum1_840")
                                    (if (eq (u16 0) (identifier "dsum1_fst_841"))
                                      (let-pair "dsum2_fst_891" "dsum2_snd_892" 
                                        (apply (ext-identifier raql_value of-row-binary) (identifier "dsum1_snd_842"))
                                        (make-tup
                                          (construct "[Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void]" 0
                                            (identifier "dsum2_fst_891")) 
                                          (identifier "dsum2_snd_892")))
                                      (if (eq (u16 1) (identifier "dsum1_fst_841"))
                                        (let-pair "dsum2_fst_888" "dsum2_snd_889" 
                                          (apply (ext-identifier raql_variable of-row-binary) (identifier "dsum1_snd_842"))
                                          (make-tup
                                            (construct "[Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void]" 1
                                              (identifier "dsum2_fst_888")) 
                                            (identifier "dsum2_snd_889")))
                                        (if (eq (u16 2) (identifier "dsum1_fst_841"))
                                          (let-pair "dsum2_fst_885" "dsum2_snd_886" 
                                            (apply (ext-identifier raql_binding_key of-row-binary) (identifier "dsum1_snd_842"))
                                            (make-tup
                                              (construct "[Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void]" 2
                                                (identifier "dsum2_fst_885")) 
                                              (identifier "dsum2_snd_886")))
                                          (if (eq (u16 3) (identifier "dsum1_fst_841"))
                                            (make-tup
                                              (construct "[Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void]" 3
                                                (nop)) (identifier "dsum1_snd_842"))
                                            (if (eq (u16 4) (identifier "dsum1_fst_841"))
                                              (make-tup
                                                (construct "[Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void]" 4
                                                  (nop)) (identifier "dsum1_snd_842"))
                                              (if (eq (u16 5) (identifier "dsum1_fst_841"))
                                                (make-tup
                                                  (construct "[Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void]" 5
                                                    (nop)) (identifier "dsum1_snd_842"))
                                                (if (eq (u16 6) (identifier "dsum1_fst_841"))
                                                  (make-tup
                                                    (construct "[Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void]" 6
                                                      (nop)) (identifier "dsum1_snd_842"))
                                                  (if (eq (u16 7) (identifier "dsum1_fst_841"))
                                                    (let-pair "dlist4_fst_867" "dlist4_snd_868"
                                                      (let "dlist1_855"
                                                        (let "leb_ref_846" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_847" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_848" 
                                                              (make-vec (identifier "dsum1_snd_842"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_849" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_848")))
                                                                    (let-pair "leb128_fst_850" "leb128_snd_851" 
                                                                    (identifier "leb128_849")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_848") (identifier "leb128_snd_851"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_846")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_850") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_847")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_846")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_847") (add (unsafe-nth (u8 0) (identifier "shft_ref_847")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_850") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_846")) (unsafe-nth (u8 0) (identifier "p_ref_848")))))))
                                                        (let-pair "dlist1_fst_856" "dlist1_snd_857" 
                                                          (identifier "dlist1_855")
                                                          (let "inits_src_ref_858" 
                                                            (make-vec (make-tup (end-of-list "$raql_path_comp") (identifier "dlist1_snd_857")))
                                                            (seq
                                                              (let "repeat_n_859" 
                                                                (make-vec (i32 0))
                                                                (while 
                                                                  (gt (to-i32 (identifier "dlist1_fst_856")) (unsafe-nth (u8 0) (identifier "repeat_n_859")))
                                                                  (seq
                                                                    (let "dlist2_860" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_858"))
                                                                    (let-pair "dlist2_fst_861" "dlist2_snd_862" 
                                                                    (identifier "dlist2_860")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_858")
                                                                    (let-pair "dlist3_fst_864" "dlist3_snd_865" 
                                                                    (apply (ext-identifier raql_path_comp of-row-binary) (identifier "dlist2_snd_862"))
                                                                    (make-tup (cons (identifier "dlist3_fst_864") (identifier "dlist2_fst_861")) (identifier "dlist3_snd_865"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_859") (add (unsafe-nth (u8 0) (identifier "repeat_n_859")) (i32 1))))))
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_858"))))))
                                                      (make-tup
                                                        (construct "[Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void]" 7
                                                          (identity (identifier "dlist4_fst_867"))) 
                                                        (identifier "dlist4_snd_868")))
                                                    (seq (assert (eq (identifier "dsum1_fst_841") (u16 8)))
                                                      (make-tup
                                                        (construct "[Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void]" 8
                                                          (nop)) (identifier "dsum1_snd_842")))))))))))))
                                (make-tup
                                  (construct "[SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)]" 0
                                    (identifier "dsum2_fst_894")) (identifier "dsum2_snd_895")))
                              (if (eq (u16 1) (identifier "dsum1_fst_476"))
                                (let-pair "dtup_fst_826" "dtup_snd_827"
                                  (let "dsum1_666" (let-pair "du16_fst_661" "du16_snd_662" (read-u16 little-endian (identifier "dsum1_snd_477")) (make-tup (identifier "du16_fst_661") (identifier "du16_snd_662")))
                                    (let-pair "dsum1_fst_667" "dsum1_snd_668" 
                                      (identifier "dsum1_666")
                                      (if (eq (u16 0) (identifier "dsum1_fst_667"))
                                        (make-tup
                                          (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 0
                                            (nop)) (identifier "dsum1_snd_668"))
                                        (if (eq (u16 1) (identifier "dsum1_fst_667"))
                                          (let-pair "dsum2_fst_820" "dsum2_snd_821" 
                                            (apply (ext-identifier raql_type of-row-binary) (identifier "dsum1_snd_668"))
                                            (make-tup
                                              (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 1
                                                (identifier "dsum2_fst_820")) 
                                              (identifier "dsum2_snd_821")))
                                          (if (eq (u16 2) (identifier "dsum1_fst_667"))
                                            (make-tup
                                              (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 2
                                                (nop)) (identifier "dsum1_snd_668"))
                                            (if (eq (u16 3) (identifier "dsum1_fst_667"))
                                              (let "dtup_792" (apply (ext-identifier raql_type of-row-binary) (identifier "dsum1_snd_668"))
                                                (let-pair "dtup_fst_793" "dtup_snd_794" 
                                                  (identifier "dtup_792")
                                                  (let-pair "dtup_fst_811" "dtup_snd_812"
                                                    (let "dsum1_801" 
                                                      (let-pair "du16_fst_796" "du16_snd_797" (read-u16 little-endian (identifier "dtup_snd_794")) (make-tup (identifier "du16_fst_796") (identifier "du16_snd_797")))
                                                      (let-pair "dsum1_fst_802" "dsum1_snd_803" 
                                                        (identifier "dsum1_801")
                                                        (if (eq (u16 0) (identifier "dsum1_fst_802")) 
                                                          (make-tup (construct "[LittleEndian Void | BigEndian Void]" 0 (nop)) (identifier "dsum1_snd_803"))
                                                          (seq (assert (eq (identifier "dsum1_fst_802") (u16 1))) (make-tup (construct "[LittleEndian Void | BigEndian Void]" 1 (nop)) (identifier "dsum1_snd_803"))))))
                                                    (make-tup
                                                      (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 3
                                                        (make-tup (identifier "dtup_fst_793") (identifier "dtup_fst_811"))) 
                                                      (identifier "dtup_snd_812")))))
                                              (if (eq (u16 4) (identifier "dsum1_fst_667"))
                                                (make-tup
                                                  (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 4
                                                    (nop)) (identifier "dsum1_snd_668"))
                                                (if (eq (u16 5) (identifier "dsum1_fst_667"))
                                                  (make-tup
                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 5
                                                      (nop)) (identifier "dsum1_snd_668"))
                                                  (if (eq (u16 6) (identifier "dsum1_fst_667"))
                                                    (make-tup
                                                      (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 6
                                                        (nop)) (identifier "dsum1_snd_668"))
                                                    (if (eq (u16 7) (identifier "dsum1_fst_667"))
                                                      (make-tup
                                                        (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 7
                                                          (nop)) (identifier "dsum1_snd_668"))
                                                      (if (eq (u16 8) (identifier "dsum1_fst_667"))
                                                        (make-tup
                                                          (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 8
                                                            (nop)) (identifier "dsum1_snd_668"))
                                                        (if (eq (u16 9) (identifier "dsum1_fst_667"))
                                                          (make-tup
                                                            (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 9
                                                              (nop)) 
                                                            (identifier "dsum1_snd_668"))
                                                          (if (eq (u16 10) (identifier "dsum1_fst_667"))
                                                            (make-tup
                                                              (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 10
                                                                (nop)) 
                                                              (identifier "dsum1_snd_668"))
                                                            (if (eq (u16 11) (identifier "dsum1_fst_667"))
                                                              (make-tup
                                                                (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 11
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_668"))
                                                              (if (eq (u16 12) (identifier "dsum1_fst_667"))
                                                                (make-tup
                                                                  (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 12
                                                                    (nop)) 
                                                                  (identifier "dsum1_snd_668"))
                                                                (if (eq (u16 13) (identifier "dsum1_fst_667"))
                                                                  (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 13
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                  (if 
                                                                    (eq (u16 14) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 14
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 15) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 15
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 16) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 16
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 17) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 17
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 18) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 18
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 19) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 19
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 20) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 20
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 21) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 21
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 22) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 22
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 23) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 23
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 24) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 24
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 25) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 25
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 26) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 26
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 27) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 27
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 28) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 28
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 29
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 30
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 31
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 32
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 33
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 34
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 35) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 35
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 36) (identifier "dsum1_fst_667"))
                                                                    (let "dstring1_687"
                                                                    (let "leb_ref_681" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_682" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_683" 
                                                                    (make-vec (identifier "dsum1_snd_668"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_684" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_683")))
                                                                    (let-pair "leb128_fst_685" "leb128_snd_686" 
                                                                    (identifier "leb128_684")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_683") (identifier "leb128_snd_686"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_681")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_685") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_682")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_681")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_682") (add (unsafe-nth (u8 0) (identifier "shft_ref_682")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_685") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_681"))) (unsafe-nth (u8 0) (identifier "p_ref_683")))))))
                                                                    (let-pair "dstring1_fst_688" "dstring1_snd_689" 
                                                                    (identifier "dstring1_687")
                                                                    (let-pair "dstring2_fst_691" "dstring2_snd_692" 
                                                                    (read-bytes (identifier "dstring1_snd_689") (identifier "dstring1_fst_688"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 36
                                                                    (string-of-bytes (identifier "dstring2_fst_691"))) 
                                                                    (identifier "dstring2_snd_692")))))
                                                                    (if 
                                                                    (eq (u16 37) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 37
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 38) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 38
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (if 
                                                                    (eq (u16 39) (identifier "dsum1_fst_667"))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 39
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_667") (u16 40)))
                                                                    (make-tup
                                                                    (construct "[Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]" 40
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_668")))))))))))))))))))))))))))))))))))))))))))))
                                  (let-pair "dtup_fst_829" "dtup_snd_830" 
                                    (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_827"))
                                    (make-tup
                                      (construct "[SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)]" 1
                                        (make-tup (identifier "dtup_fst_826") (identifier "dtup_fst_829"))) 
                                      (identifier "dtup_snd_830"))))
                                (if (eq (u16 2) (identifier "dsum1_fst_476"))
                                  (let "dtup_628"
                                    (let "dsum1_613" (let-pair "du16_fst_608" "du16_snd_609" (read-u16 little-endian (identifier "dsum1_snd_477")) (make-tup (identifier "du16_fst_608") (identifier "du16_snd_609")))
                                      (let-pair "dsum1_fst_614" "dsum1_snd_615" 
                                        (identifier "dsum1_613")
                                        (if (eq (u16 0) (identifier "dsum1_fst_614")) 
                                          (make-tup (construct "[Max Void | Min Void | Print Void | Coalesce Void]" 0 (nop)) (identifier "dsum1_snd_615"))
                                          (if (eq (u16 1) (identifier "dsum1_fst_614")) 
                                            (make-tup (construct "[Max Void | Min Void | Print Void | Coalesce Void]" 1 (nop)) (identifier "dsum1_snd_615"))
                                            (if (eq (u16 2) (identifier "dsum1_fst_614")) 
                                              (make-tup (construct "[Max Void | Min Void | Print Void | Coalesce Void]" 2 (nop)) (identifier "dsum1_snd_615"))
                                              (seq (assert (eq (identifier "dsum1_fst_614") (u16 3))) (make-tup (construct "[Max Void | Min Void | Print Void | Coalesce Void]" 3 (nop)) (identifier "dsum1_snd_615"))))))))
                                    (let-pair "dtup_fst_629" "dtup_snd_630" 
                                      (identifier "dtup_628")
                                      (let-pair "dlist4_fst_652" "dlist4_snd_653"
                                        (let "dlist1_640"
                                          (let "leb_ref_631" (make-vec (u32 0))
                                            (let "shft_ref_632" (make-vec (u8 0))
                                              (let "p_ref_633" (make-vec (identifier "dtup_snd_630"))
                                                (seq
                                                  (while
                                                    (let "leb128_634" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_633")))
                                                      (let-pair "leb128_fst_635" "leb128_snd_636" 
                                                        (identifier "leb128_634")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_633") (identifier "leb128_snd_636"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_631")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_635") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_632")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_631")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_632") (add (unsafe-nth (u8 0) (identifier "shft_ref_632")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_635") (u8 128))))) 
                                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_631")) (unsafe-nth (u8 0) (identifier "p_ref_633")))))))
                                          (let-pair "dlist1_fst_641" "dlist1_snd_642" 
                                            (identifier "dlist1_640")
                                            (let "inits_src_ref_643" 
                                              (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_642")))
                                              (seq
                                                (let "repeat_n_644" (make-vec (i32 0))
                                                  (while (gt (to-i32 (identifier "dlist1_fst_641")) (unsafe-nth (u8 0) (identifier "repeat_n_644")))
                                                    (seq
                                                      (let "dlist2_645" 
                                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_643"))
                                                        (let-pair "dlist2_fst_646" "dlist2_snd_647" 
                                                          (identifier "dlist2_645")
                                                          (set-vec (u8 0) 
                                                            (identifier "inits_src_ref_643")
                                                            (let-pair "dlist3_fst_649" "dlist3_snd_650" 
                                                              (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_647"))
                                                              (make-tup (cons (identifier "dlist3_fst_649") (identifier "dlist2_fst_646")) (identifier "dlist3_snd_650"))))))
                                                      (set-vec (u8 0) (identifier "repeat_n_644") (add (unsafe-nth (u8 0) (identifier "repeat_n_644")) (i32 1)))))) 
                                                (unsafe-nth (u8 0) (identifier "inits_src_ref_643"))))))
                                        (make-tup
                                          (construct "[SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)]" 2
                                            (make-tup (identifier "dtup_fst_629") (identity (identifier "dlist4_fst_652")))) 
                                          (identifier "dlist4_snd_653")))))
                                  (if (eq (u16 3) (identifier "dsum1_fst_476"))
                                    (let-pair "dtup_fst_596" "dtup_snd_597"
                                      (let "dsum1_514" (let-pair "du16_fst_509" "du16_snd_510" (read-u16 little-endian (identifier "dsum1_snd_477")) (make-tup (identifier "du16_fst_509") (identifier "du16_snd_510")))
                                        (let-pair "dsum1_fst_515" "dsum1_snd_516" 
                                          (identifier "dsum1_514")
                                          (if (eq (u16 0) (identifier "dsum1_fst_515"))
                                            (make-tup
                                              (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 0
                                                (nop)) (identifier "dsum1_snd_516"))
                                            (if (eq (u16 1) (identifier "dsum1_fst_515"))
                                              (make-tup
                                                (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 1
                                                  (nop)) (identifier "dsum1_snd_516"))
                                              (if (eq (u16 2) (identifier "dsum1_fst_515"))
                                                (make-tup
                                                  (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 2
                                                    (nop)) (identifier "dsum1_snd_516"))
                                                (if (eq (u16 3) (identifier "dsum1_fst_515"))
                                                  (make-tup
                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 3
                                                      (nop)) (identifier "dsum1_snd_516"))
                                                  (if (eq (u16 4) (identifier "dsum1_fst_515"))
                                                    (make-tup
                                                      (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 4
                                                        (nop)) (identifier "dsum1_snd_516"))
                                                    (if (eq (u16 5) (identifier "dsum1_fst_515"))
                                                      (make-tup
                                                        (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 5
                                                          (nop)) (identifier "dsum1_snd_516"))
                                                      (if (eq (u16 6) (identifier "dsum1_fst_515"))
                                                        (make-tup
                                                          (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 6
                                                            (nop)) (identifier "dsum1_snd_516"))
                                                        (if (eq (u16 7) (identifier "dsum1_fst_515"))
                                                          (make-tup
                                                            (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 7
                                                              (nop)) 
                                                            (identifier "dsum1_snd_516"))
                                                          (if (eq (u16 8) (identifier "dsum1_fst_515"))
                                                            (make-tup
                                                              (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 8
                                                                (nop)) 
                                                              (identifier "dsum1_snd_516"))
                                                            (if (eq (u16 9) (identifier "dsum1_fst_515"))
                                                              (make-tup
                                                                (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 9
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_516"))
                                                              (if (eq (u16 10) (identifier "dsum1_fst_515"))
                                                                (make-tup
                                                                  (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 10
                                                                    (nop)) 
                                                                  (identifier "dsum1_snd_516"))
                                                                (if (eq (u16 11) (identifier "dsum1_fst_515"))
                                                                  (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 11
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                  (if 
                                                                    (eq (u16 12) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 12
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 13) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 13
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 14) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 14
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 15) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 15
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 16) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 16
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 17) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 17
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 18) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 18
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 19) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 19
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 20) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 20
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 21) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 21
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 22) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 22
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 23) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 23
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (if 
                                                                    (eq (u16 24) (identifier "dsum1_fst_515"))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 24
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_515") (u16 25)))
                                                                    (make-tup
                                                                    (construct "[Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]" 25
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_516"))))))))))))))))))))))))))))))
                                      (let-pair "dtup_fst_599" "dtup_snd_600" 
                                        (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_597"))
                                        (let-pair "dtup_fst_602" "dtup_snd_603" 
                                          (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_600"))
                                          (make-tup
                                            (construct "[SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)]" 3
                                              (make-tup (identifier "dtup_fst_596") (identifier "dtup_fst_599") (identifier "dtup_fst_602"))) 
                                            (identifier "dtup_snd_603")))))
                                    (seq (assert (eq (identifier "dsum1_fst_476") (u16 4)))
                                      (let-pair "dtup_fst_494" "dtup_snd_495"
                                        (let "dsum1_484" (let-pair "du16_fst_479" "du16_snd_480" (read-u16 little-endian (identifier "dsum1_snd_477")) (make-tup (identifier "du16_fst_479") (identifier "du16_snd_480")))
                                          (let-pair "dsum1_fst_485" "dsum1_snd_486" 
                                            (identifier "dsum1_484")
                                            (if (eq (u16 0) (identifier "dsum1_fst_485")) 
                                              (make-tup (construct "[SubString Void | MapSet Void]" 0 (nop)) (identifier "dsum1_snd_486"))
                                              (seq (assert (eq (identifier "dsum1_fst_485") (u16 1))) (make-tup (construct "[SubString Void | MapSet Void]" 1 (nop)) (identifier "dsum1_snd_486"))))))
                                        (let-pair "dtup_fst_497" "dtup_snd_498" 
                                          (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_495"))
                                          (let-pair "dtup_fst_500" "dtup_snd_501" 
                                            (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_498"))
                                            (let-pair "dtup_fst_503" "dtup_snd_504" 
                                              (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_501"))
                                              (make-tup
                                                (construct "[SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)]" 4
                                                  (make-tup (identifier "dtup_fst_494") (identifier "dtup_fst_497") (identifier "dtup_fst_500") (identifier "dtup_fst_503"))) 
                                                (identifier "dtup_snd_504")))))))))))))
                        (make-tup
                          (construct "[Tuple THIS[[]] | Record ($field_name; THIS)[[]] | Vector THIS[[]] | Case ({case_cond: THIS; case_cons: THIS}[[]]; THIS?) | Stateless [SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)] | Stateful ([LocalState Void | GlobalState Void]; BOOL; [SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]) | Generator [Split (THIS; THIS)]]" 4
                            (identifier "dsum2_fst_897")) (identifier "dsum2_snd_898")))
                      (if (eq (u16 5) (identifier "dsum1_fst_63"))
                        (let "dtup_101"
                          (let "dsum1_92" (let-pair "du16_fst_87" "du16_snd_88" (read-u16 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du16_fst_87") (identifier "du16_snd_88")))
                            (let-pair "dsum1_fst_93" "dsum1_snd_94" (identifier "dsum1_92")
                              (if (eq (u16 0) (identifier "dsum1_fst_93")) 
                                (make-tup (construct "[LocalState Void | GlobalState Void]" 0 (nop)) (identifier "dsum1_snd_94"))
                                (seq (assert (eq (identifier "dsum1_fst_93") (u16 1))) (make-tup (construct "[LocalState Void | GlobalState Void]" 1 (nop)) (identifier "dsum1_snd_94"))))))
                          (let-pair "dtup_fst_102" "dtup_snd_103" (identifier "dtup_101")
                            (let "dtup_107" (let-pair "dbool_fst_105" "dbool_snd_106" (read-u8 (identifier "dtup_snd_103")) (make-tup (not (eq (identifier "dbool_fst_105") (u8 0))) (identifier "dbool_snd_106")))
                              (let-pair "dtup_fst_108" "dtup_snd_109" 
                                (identifier "dtup_107")
                                (let-pair "dtup_fst_464" "dtup_snd_465"
                                  (let "dsum1_116" (let-pair "du16_fst_111" "du16_snd_112" (read-u16 little-endian (identifier "dtup_snd_109")) (make-tup (identifier "du16_fst_111") (identifier "du16_snd_112")))
                                    (let-pair "dsum1_fst_117" "dsum1_snd_118" 
                                      (identifier "dsum1_116")
                                      (if (eq (u16 0) (identifier "dsum1_fst_117"))
                                        (let-pair "dtup_fst_455" "dtup_snd_456"
                                          (let "dsum1_388" (let-pair "du16_fst_383" "du16_snd_384" (read-u16 little-endian (identifier "dsum1_snd_118")) (make-tup (identifier "du16_fst_383") (identifier "du16_snd_384")))
                                            (let-pair "dsum1_fst_389" "dsum1_snd_390" 
                                              (identifier "dsum1_388")
                                              (if (eq (u16 0) (identifier "dsum1_fst_389"))
                                                (make-tup
                                                  (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 0
                                                    (nop)) (identifier "dsum1_snd_390"))
                                                (if (eq (u16 1) (identifier "dsum1_fst_389"))
                                                  (make-tup
                                                    (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 1
                                                      (nop)) (identifier "dsum1_snd_390"))
                                                  (if (eq (u16 2) (identifier "dsum1_fst_389"))
                                                    (make-tup
                                                      (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 2
                                                        (nop)) (identifier "dsum1_snd_390"))
                                                    (if (eq (u16 3) (identifier "dsum1_fst_389"))
                                                      (make-tup
                                                        (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 3
                                                          (nop)) (identifier "dsum1_snd_390"))
                                                      (if (eq (u16 4) (identifier "dsum1_fst_389"))
                                                        (make-tup
                                                          (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 4
                                                            (nop)) (identifier "dsum1_snd_390"))
                                                        (if (eq (u16 5) (identifier "dsum1_fst_389"))
                                                          (make-tup
                                                            (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 5
                                                              (nop)) 
                                                            (identifier "dsum1_snd_390"))
                                                          (if (eq (u16 6) (identifier "dsum1_fst_389"))
                                                            (make-tup
                                                              (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 6
                                                                (nop)) 
                                                              (identifier "dsum1_snd_390"))
                                                            (if (eq (u16 7) (identifier "dsum1_fst_389"))
                                                              (make-tup
                                                                (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 7
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_390"))
                                                              (if (eq (u16 8) (identifier "dsum1_fst_389"))
                                                                (make-tup
                                                                  (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 8
                                                                    (nop)) 
                                                                  (identifier "dsum1_snd_390"))
                                                                (if (eq (u16 9) (identifier "dsum1_fst_389"))
                                                                  (make-tup
                                                                    (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 9
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_390"))
                                                                  (if 
                                                                    (eq (u16 10) (identifier "dsum1_fst_389"))
                                                                    (make-tup
                                                                    (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 10
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_390"))
                                                                    (if 
                                                                    (eq (u16 11) (identifier "dsum1_fst_389"))
                                                                    (let "dtup_403"
                                                                    (let-pair "dfloat_fst_401" "dfloat_snd_402" 
                                                                    (read-u64 little-endian (identifier "dsum1_snd_390")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_401")) (identifier "dfloat_snd_402")))
                                                                    (let-pair "dtup_fst_404" "dtup_snd_405" 
                                                                    (identifier "dtup_403")
                                                                    (let "dtup_409"
                                                                    (let-pair "dfloat_fst_407" "dfloat_snd_408" 
                                                                    (read-u64 little-endian (identifier "dtup_snd_405")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_407")) (identifier "dfloat_snd_408")))
                                                                    (let-pair "dtup_fst_410" "dtup_snd_411" 
                                                                    (identifier "dtup_409")
                                                                    (let-pair "du32_fst_413" "du32_snd_414" 
                                                                    (read-u32 little-endian (identifier "dtup_snd_411"))
                                                                    (make-tup
                                                                    (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 11
                                                                    (make-tup (identifier "dtup_fst_404") (identifier "dtup_fst_410") (identifier "du32_fst_413"))) 
                                                                    (identifier "du32_snd_414")))))))
                                                                    (if 
                                                                    (eq (u16 12) (identifier "dsum1_fst_389"))
                                                                    (make-tup
                                                                    (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 12
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_390"))
                                                                    (if 
                                                                    (eq (u16 13) (identifier "dsum1_fst_389"))
                                                                    (make-tup
                                                                    (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 13
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_390"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_389") (u16 14)))
                                                                    (make-tup
                                                                    (construct "[AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]" 14
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_390")))))))))))))))))))
                                          (let-pair "dtup_fst_458" "dtup_snd_459" 
                                            (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_456"))
                                            (make-tup
                                              (construct "[SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]" 0
                                                (make-tup (identifier "dtup_fst_455") (identifier "dtup_fst_458"))) 
                                              (identifier "dtup_snd_459"))))
                                        (if (eq (u16 1) (identifier "dsum1_fst_117"))
                                          (let-pair "dtup_fst_371" "dtup_snd_372"
                                            (let "dsum1_355" (let-pair "du16_fst_350" "du16_snd_351" (read-u16 little-endian (identifier "dsum1_snd_118")) (make-tup (identifier "du16_fst_350") (identifier "du16_snd_351")))
                                              (let-pair "dsum1_fst_356" "dsum1_snd_357" 
                                                (identifier "dsum1_355")
                                                (if (eq (u16 0) (identifier "dsum1_fst_356")) 
                                                  (make-tup (construct "[Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]" 0 (nop)) (identifier "dsum1_snd_357"))
                                                  (if (eq (u16 1) (identifier "dsum1_fst_356")) 
                                                    (make-tup (construct "[Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]" 1 (nop)) (identifier "dsum1_snd_357"))
                                                    (if (eq (u16 2) (identifier "dsum1_fst_356")) 
                                                      (make-tup (construct "[Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]" 2 (nop)) (identifier "dsum1_snd_357"))
                                                      (seq (assert (eq (identifier "dsum1_fst_356") (u16 3)))
                                                        (make-tup (construct "[Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]" 3 (nop)) (identifier "dsum1_snd_357"))))))))
                                            (let-pair "dtup_fst_374" "dtup_snd_375" 
                                              (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_372"))
                                              (let-pair "dtup_fst_377" "dtup_snd_378" 
                                                (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_375"))
                                                (make-tup
                                                  (construct "[SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]" 1
                                                    (make-tup (identifier "dtup_fst_371") (identifier "dtup_fst_374") (identifier "dtup_fst_377"))) 
                                                  (identifier "dtup_snd_378")))))
                                          (if (eq (u16 2) (identifier "dsum1_fst_117"))
                                            (let-pair "dtup_fst_335" "dtup_snd_336"
                                              (let "dsum1_319" (let-pair "du16_fst_314" "du16_snd_315" (read-u16 little-endian (identifier "dsum1_snd_118")) (make-tup (identifier "du16_fst_314") (identifier "du16_snd_315")))
                                                (let-pair "dsum1_fst_320" "dsum1_snd_321" 
                                                  (identifier "dsum1_319")
                                                  (if (eq (u16 0) (identifier "dsum1_fst_320")) 
                                                    (make-tup (construct "[MovingAvg Void | Hysteresis Void | OnceEvery BOOL]" 0 (nop)) (identifier "dsum1_snd_321"))
                                                    (if (eq (u16 1) (identifier "dsum1_fst_320")) 
                                                      (make-tup (construct "[MovingAvg Void | Hysteresis Void | OnceEvery BOOL]" 1 (nop)) (identifier "dsum1_snd_321"))
                                                      (seq (assert (eq (identifier "dsum1_fst_320") (u16 2)))
                                                        (let-pair "dbool_fst_323" "dbool_snd_324" 
                                                          (read-u8 (identifier "dsum1_snd_321"))
                                                          (make-tup (construct "[MovingAvg Void | Hysteresis Void | OnceEvery BOOL]" 2 (not (eq (identifier "dbool_fst_323") (u8 0)))) (identifier "dbool_snd_324"))))))))
                                              (let-pair "dtup_fst_338" "dtup_snd_339" 
                                                (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_336"))
                                                (let-pair "dtup_fst_341" "dtup_snd_342" 
                                                  (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_339"))
                                                  (let-pair "dtup_fst_344" "dtup_snd_345" 
                                                    (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_342"))
                                                    (make-tup
                                                      (construct "[SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]" 2
                                                        (make-tup (identifier "dtup_fst_335") (identifier "dtup_fst_338") (identifier "dtup_fst_341") (identifier "dtup_fst_344"))) 
                                                      (identifier "dtup_snd_345"))))))
                                            (if (eq (u16 3) (identifier "dsum1_fst_117"))
                                              (let-pair "dtup_fst_296" "dtup_snd_297"
                                                (let "dsum1_283" (let-pair "du16_fst_278" "du16_snd_279" (read-u16 little-endian (identifier "dsum1_snd_118")) (make-tup (identifier "du16_fst_278") (identifier "du16_snd_279")))
                                                  (let-pair "dsum1_fst_284" "dsum1_snd_285" 
                                                    (identifier "dsum1_283")
                                                    (if (eq (u16 0) (identifier "dsum1_fst_284")) 
                                                      (make-tup (construct "[DampedHolt Void | Remember BOOL]" 0 (nop)) (identifier "dsum1_snd_285"))
                                                      (seq (assert (eq (identifier "dsum1_fst_284") (u16 1)))
                                                        (let-pair "dbool_fst_287" "dbool_snd_288" 
                                                          (read-u8 (identifier "dsum1_snd_285"))
                                                          (make-tup (construct "[DampedHolt Void | Remember BOOL]" 1 (not (eq (identifier "dbool_fst_287") (u8 0)))) (identifier "dbool_snd_288")))))))
                                                (let-pair "dtup_fst_299" "dtup_snd_300" 
                                                  (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_297"))
                                                  (let-pair "dtup_fst_302" "dtup_snd_303" 
                                                    (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_300"))
                                                    (let-pair "dtup_fst_305" "dtup_snd_306" 
                                                      (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_303"))
                                                      (let-pair "dtup_fst_308" "dtup_snd_309" 
                                                        (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_306"))
                                                        (make-tup
                                                          (construct "[SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]" 3
                                                            (make-tup (identifier "dtup_fst_296") (identifier "dtup_fst_299") (identifier "dtup_fst_302") (identifier "dtup_fst_305") (identifier "dtup_fst_308")))
                                                          (identifier "dtup_snd_309")))))))
                                              (if (eq (u16 4) (identifier "dsum1_fst_117"))
                                                (let "dtup_236"
                                                  (let "dsum1_215" (let-pair "du16_fst_210" "du16_snd_211" (read-u16 little-endian (identifier "dsum1_snd_118")) (make-tup (identifier "du16_fst_210") (identifier "du16_snd_211")))
                                                    (let-pair "dsum1_fst_216" "dsum1_snd_217" 
                                                      (identifier "dsum1_215")
                                                      (if (eq (u16 0) (identifier "dsum1_fst_216")) 
                                                        (make-tup (construct "[MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]" 0 (nop)) (identifier "dsum1_snd_217"))
                                                        (seq (assert (eq (identifier "dsum1_fst_216") (u16 1)))
                                                          (let "drec_221"
                                                            (let-pair "dbool_fst_219" "dbool_snd_220" (read-u8 (identifier "dsum1_snd_217")) (make-tup (not (eq (identifier "dbool_fst_219") (u8 0))) (identifier "dbool_snd_220")))
                                                            (let-pair "drec_fst_222" "drec_snd_223" 
                                                              (identifier "drec_221")
                                                              (let-pair "dbool_fst_225" "dbool_snd_226" 
                                                                (read-u8 (identifier "drec_snd_223"))
                                                                (make-tup
                                                                  (construct "[MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]" 1
                                                                    (make-rec (string "inv") (identifier "drec_fst_222") (string "up_to") (not (eq (identifier "dbool_fst_225") (u8 0))))) 
                                                                  (identifier "dbool_snd_226")))))))))
                                                  (let-pair "dtup_fst_237" "dtup_snd_238" 
                                                    (identifier "dtup_236")
                                                    (let-pair "dtup_fst_240" "dtup_snd_241" 
                                                      (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_238"))
                                                      (let-pair "dtup_fst_243" "dtup_snd_244" 
                                                        (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_241"))
                                                        (let-pair "dtup_fst_246" "dtup_snd_247" 
                                                          (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_244"))
                                                          (let-pair "dlist4_fst_269" "dlist4_snd_270"
                                                            (let "dlist1_257"
                                                              (let "leb_ref_248" 
                                                                (make-vec (u32 0))
                                                                (let "shft_ref_249" 
                                                                  (make-vec (u8 0))
                                                                  (let "p_ref_250" 
                                                                    (make-vec (identifier "dtup_snd_247"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_251" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_250")))
                                                                    (let-pair "leb128_fst_252" "leb128_snd_253" 
                                                                    (identifier "leb128_251")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_250") (identifier "leb128_snd_253"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_248")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_252") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_249")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_248")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_249") (add (unsafe-nth (u8 0) (identifier "shft_ref_249")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_252") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_248")) (unsafe-nth (u8 0) (identifier "p_ref_250")))))))
                                                              (let-pair "dlist1_fst_258" "dlist1_snd_259" 
                                                                (identifier "dlist1_257")
                                                                (let "inits_src_ref_260" 
                                                                  (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_259")))
                                                                  (seq
                                                                    (let "repeat_n_261" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_258")) (unsafe-nth (u8 0) (identifier "repeat_n_261")))
                                                                    (seq
                                                                    (let "dlist2_262" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_260"))
                                                                    (let-pair "dlist2_fst_263" "dlist2_snd_264" 
                                                                    (identifier "dlist2_262")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_260")
                                                                    (let-pair "dlist3_fst_266" "dlist3_snd_267" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_264"))
                                                                    (make-tup (cons (identifier "dlist3_fst_266") (identifier "dlist2_fst_263")) (identifier "dlist3_snd_267"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_261") (add (unsafe-nth (u8 0) (identifier "repeat_n_261")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_260"))))))
                                                            (make-tup
                                                              (construct "[SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]" 4
                                                                (make-tup (identifier "dtup_fst_237") (identifier "dtup_fst_240") (identifier "dtup_fst_243") (identifier "dtup_fst_246") (identity (identifier "dlist4_fst_269"))))
                                                              (identifier "dlist4_snd_270"))))))))
                                                (if (eq (u16 5) (identifier "dsum1_fst_117"))
                                                  (let "dsum1_179" (let-pair "du16_fst_174" "du16_snd_175" (read-u16 little-endian (identifier "dsum1_snd_118")) (make-tup (identifier "du16_fst_174") (identifier "du16_snd_175")))
                                                    (let-pair "dsum1_fst_180" "dsum1_snd_181" 
                                                      (identifier "dsum1_179")
                                                      (seq (assert (eq (identifier "dsum1_fst_180") (u16 0)))
                                                        (let-pair "dtup_fst_189" "dtup_snd_190" 
                                                          (apply (myself "(THIS; Ptr)") (identifier "dsum1_snd_181"))
                                                          (let-pair "dtup_fst_192" "dtup_snd_193" 
                                                            (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_190"))
                                                            (let-pair "dtup_fst_195" "dtup_snd_196" 
                                                              (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_193"))
                                                              (let-pair "dtup_fst_198" "dtup_snd_199" 
                                                                (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_196"))
                                                                (let-pair "dtup_fst_201" "dtup_snd_202" 
                                                                  (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_199"))
                                                                  (let-pair "dtup_fst_204" "dtup_snd_205" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_202"))
                                                                    (make-tup
                                                                    (construct "[SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]" 5
                                                                    (make-tup 
                                                                    (construct "[DampedHoltWinter Void]" 0 (nop)) 
                                                                    (identifier "dtup_fst_189") 
                                                                    (identifier "dtup_fst_192") 
                                                                    (identifier "dtup_fst_195") 
                                                                    (identifier "dtup_fst_198") 
                                                                    (identifier "dtup_fst_201") 
                                                                    (identifier "dtup_fst_204"))) 
                                                                    (identifier "dtup_snd_205")))))))))))
                                                  (if (eq (u16 6) (identifier "dsum1_fst_117"))
                                                    (let "drec_143" (apply (ext-identifier raql_top_output of-row-binary) (identifier "dsum1_snd_118"))
                                                      (let-pair "drec_fst_144" "drec_snd_145" 
                                                        (identifier "drec_143")
                                                        (let-pair "drec_fst_147" "drec_snd_148" 
                                                          (apply (myself "(THIS; Ptr)") (identifier "drec_snd_145"))
                                                          (let-pair "drec_fst_153" "drec_snd_154"
                                                            (if (eq (peek-u8 (identifier "drec_snd_148") (size 0)) (u8 1)) 
                                                              (make-tup (null "THIS") (ptr-add (identifier "drec_snd_148") (size 1)))
                                                              (let-pair "make1_1_fst_150" "make1_1_snd_151" 
                                                                (apply (myself "(THIS; Ptr)") (ptr-add (identifier "drec_snd_148") (size 1))) 
                                                                (make-tup (not-null (identifier "make1_1_fst_150")) (identifier "make1_1_snd_151"))))
                                                            (let-pair "drec_fst_156" "drec_snd_157" 
                                                              (apply (myself "(THIS; Ptr)") (identifier "drec_snd_154"))
                                                              (let-pair "drec_fst_159" "drec_snd_160" 
                                                                (apply (myself "(THIS; Ptr)") (identifier "drec_snd_157"))
                                                                (let-pair "drec_fst_162" "drec_snd_163" 
                                                                  (apply (myself "(THIS; Ptr)") (identifier "drec_snd_160"))
                                                                  (let-pair "drec_fst_165" "drec_snd_166" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "drec_snd_163"))
                                                                    (let-pair "drec_fst_168" "drec_snd_169" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "drec_snd_166"))
                                                                    (make-tup
                                                                    (construct "[SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]" 6
                                                                    (make-rec 
                                                                    (string "output") 
                                                                    (identifier "drec_fst_144") 
                                                                    (string "size") 
                                                                    (identifier "drec_fst_147") 
                                                                    (string "max_size") 
                                                                    (identifier "drec_fst_153") 
                                                                    (string "what") 
                                                                    (identifier "drec_fst_156") 
                                                                    (string "by") 
                                                                    (identifier "drec_fst_159") 
                                                                    (string "time") 
                                                                    (identifier "drec_fst_162") 
                                                                    (string "duration") 
                                                                    (identifier "drec_fst_165") 
                                                                    (string "sigmas") 
                                                                    (identifier "drec_fst_168"))) 
                                                                    (identifier "drec_snd_169")))))))))))
                                                    (seq (assert (eq (identifier "dsum1_fst_117") (u16 7)))
                                                      (let-pair "drec_fst_120" "drec_snd_121" 
                                                        (apply (myself "(THIS; Ptr)") (identifier "dsum1_snd_118"))
                                                        (let-pair "drec_fst_123" "drec_snd_124" 
                                                          (apply (myself "(THIS; Ptr)") (identifier "drec_snd_121"))
                                                          (let-pair "drec_fst_126" "drec_snd_127" 
                                                            (apply (myself "(THIS; Ptr)") (identifier "drec_snd_124"))
                                                            (let "drec_131"
                                                              (let-pair "dbool_fst_129" "dbool_snd_130" (read-u8 (identifier "drec_snd_127")) (make-tup (not (eq (identifier "dbool_fst_129") (u8 0))) (identifier "dbool_snd_130")))
                                                              (let-pair "drec_fst_132" "drec_snd_133" 
                                                                (identifier "drec_131")
                                                                (let-pair "drec_fst_138" "drec_snd_139"
                                                                  (if 
                                                                    (eq (peek-u8 (identifier "drec_snd_133") (size 0)) (u8 1)) 
                                                                    (make-tup (null "THIS") (ptr-add (identifier "drec_snd_133") (size 1)))
                                                                    (let-pair "make1_1_fst_135" "make1_1_snd_136" 
                                                                    (apply (myself "(THIS; Ptr)") (ptr-add (identifier "drec_snd_133") (size 1)))
                                                                    (make-tup (not-null (identifier "make1_1_fst_135")) (identifier "make1_1_snd_136"))))
                                                                  (make-tup
                                                                    (construct "[SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]" 7
                                                                    (make-rec 
                                                                    (string "what") 
                                                                    (identifier "drec_fst_120") 
                                                                    (string "time") 
                                                                    (identifier "drec_fst_123") 
                                                                    (string "max_age") 
                                                                    (identifier "drec_fst_126") 
                                                                    (string "tumbling") 
                                                                    (identifier "drec_fst_132") 
                                                                    (string "sample_size") 
                                                                    (identifier "drec_fst_138"))) 
                                                                    (identifier "drec_snd_139"))))))))))))))))))
                                  (make-tup
                                    (construct "[Tuple THIS[[]] | Record ($field_name; THIS)[[]] | Vector THIS[[]] | Case ({case_cond: THIS; case_cons: THIS}[[]]; THIS?) | Stateless [SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)] | Stateful ([LocalState Void | GlobalState Void]; BOOL; [SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]) | Generator [Split (THIS; THIS)]]" 5
                                      (make-tup (identifier "dtup_fst_102") (identifier "dtup_fst_108") (identifier "dtup_fst_464"))) 
                                    (identifier "dtup_snd_465")))))))
                        (seq (assert (eq (identifier "dsum1_fst_63") (u16 6)))
                          (let "dsum1_71" (let-pair "du16_fst_66" "du16_snd_67" (read-u16 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du16_fst_66") (identifier "du16_snd_67")))
                            (let-pair "dsum1_fst_72" "dsum1_snd_73" (identifier "dsum1_71")
                              (seq (assert (eq (identifier "dsum1_fst_72") (u16 0)))
                                (let-pair "dtup_fst_75" "dtup_snd_76" 
                                  (apply (myself "(THIS; Ptr)") (identifier "dsum1_snd_73"))
                                  (let-pair "dtup_fst_78" "dtup_snd_79" 
                                    (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_76"))
                                    (make-tup
                                      (construct "[Tuple THIS[[]] | Record ($field_name; THIS)[[]] | Vector THIS[[]] | Case ({case_cond: THIS; case_cons: THIS}[[]]; THIS?) | Stateless [SL0 [Const $raql_value | Variable $raql_variable | Binding $raql_binding_key | Now Void | Random Void | EventStart Void | EventStop Void | Path $raql_path_comp[[]] | Pi Void] | SL1 ([Age Void | Cast $raql_type | Force Void | Peek ($raql_type; [LittleEndian Void | BigEndian Void]) | Length Void | Lower Void | Upper Void | UuidOfU128 Void | Not Void | Abs Void | Minus Void | Defined Void | Exp Void | Log Void | Log10 Void | Sqrt Void | Sq Void | Ceil Void | Floor Void | Round Void | Cos Void | Sin Void | Tan Void | ACos Void | ASin Void | ATan Void | CosH Void | SinH Void | TanH Void | Hash Void | BeginOfRange Void | EndOfRange Void | Sparkline Void | Strptime Void | Variant Void | Chr Void | Like STRING | Fit Void | CountryCode Void | IpFamily Void | Basename Void]; THIS) | SL1s ([Max Void | Min Void | Print Void | Coalesce Void]; THIS[[]]) | SL2 ([Add Void | Sub Void | Mul Void | Div Void | IDiv Void | Mod Void | Pow Void | Trunc Void | Reldiff Void | And Void | Or Void | Ge Void | Gt Void | Eq Void | Concat Void | StartsWith Void | EndsWith Void | BitAnd Void | BitOr Void | BitXor Void | BitShift Void | Get Void | In Void | Strftime Void | Index Void | Percentile Void]; THIS; THIS) | SL3 ([SubString Void | MapSet Void]; THIS; THIS; THIS)] | Stateful ([LocalState Void | GlobalState Void]; BOOL; [SF1 ([AggrMin Void | AggrMax Void | AggrSum Void | AggrAvg Void | AggrAnd Void | AggrOr Void | AggrBitAnd Void | AggrBitOr Void | AggrBitXor Void | AggrFirst Void | AggrLast Void | AggrHistogram (FLOAT; FLOAT; U32) | Group Void | Count Void | Distinct Void]; THIS) | SF2 ([Lag Void | ExpSmooth Void | Sample Void | OneOutOf Void]; THIS; THIS) | SF3 ([MovingAvg Void | Hysteresis Void | OnceEvery BOOL]; THIS; THIS; THIS) | SF4 ([DampedHolt Void | Remember BOOL]; THIS; THIS; THIS; THIS) | SF4s ([MultiLinReg Void | Largest {inv: BOOL; up_to: BOOL}]; THIS; THIS; THIS; THIS[[]]) | SF6 ([DampedHoltWinter Void]; THIS; THIS; THIS; THIS; THIS; THIS) | Top {output: $raql_top_output; size: THIS; max_size: THIS?; what: THIS; by: THIS; time: THIS; duration: THIS; sigmas: THIS} | Past {what: THIS; time: THIS; max_age: THIS; tumbling: BOOL; sample_size: THIS?}]) | Generator [Split (THIS; THIS)]]" 6
                                        (construct "[Split (THIS; THIS)]" 0 (make-tup (identifier "dtup_fst_75") (identifier "dtup_fst_78")))) 
                                      (identifier "dtup_snd_79"))))))))))))))))
        (let-pair "drec_fst_1025" "drec_snd_1026" (identifier "drec_1024")
          (let "drec_1030" (let-pair "du32_fst_1028" "du32_snd_1029" (read-u32 little-endian (identifier "drec_snd_1026")) (make-tup (identifier "du32_fst_1028") (identifier "du32_snd_1029")))
            (let-pair "drec_fst_1031" "drec_snd_1032" (identifier "drec_1030")
              (let "drec_1033" (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_1032"))
                (let-pair "drec_fst_1034" "drec_snd_1035" (identifier "drec_1033")
                  (let-pair "drec_fst_1040" "drec_snd_1041"
                    (if (eq (peek-u8 (identifier "drec_snd_1035") (size 0)) (u8 1)) 
                      (make-tup (null "$units") (ptr-add (identifier "drec_snd_1035") (size 1)))
                      (let-pair "make1_1_fst_1037" "make1_1_snd_1038" 
                        (apply (ext-identifier units of-row-binary) (ptr-add (identifier "drec_snd_1035") (size 1))) 
                        (make-tup (not-null (identifier "make1_1_fst_1037")) (identifier "make1_1_snd_1038"))))
                    (make-tup (make-rec (string "text") (identifier "drec_fst_1025") (string "uniq_num") (identifier "drec_fst_1031") (string "typ") (identifier "drec_fst_1034") (string "units") (identifier "drec_fst_1040"))
                      (identifier "drec_snd_1041"))))))))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun3236 { [&fun3236](Pointer p_0) {
    v_362f9d9108a6902af48b6c83d5377ea1 id_3237 { p_0.readU16Le() };
    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_3238;
    {
      auto du16_fst_57 { std::get<0>(id_3237) };
      auto du16_snd_58 { std::get<1>(id_3237) };
      v_362f9d9108a6902af48b6c83d5377ea1 id_3239 {  du16_fst_57, du16_snd_58  };
      letpair_res_3238 = id_3239;
    }
    f05619a6958568f0d4db38b191811dc1 let_res_3240;
    {
      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_62 { letpair_res_3238 };
      f05619a6958568f0d4db38b191811dc1 letpair_res_3241;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_3242 { 0 };
        bool id_3243 { bool(id_3242 == dsum1_fst_63) };
        f05619a6958568f0d4db38b191811dc1 choose_res_3244;
        if (id_3243) {
          uint32_t id_3245 { 0U };
          Vec<1, uint32_t> id_3246 {  id_3245  };
          ac0fbd05039f742d2f1d9ac182e392ab let_res_3247;
          {
            Vec<1, uint32_t> leb_ref_998 { id_3246 };
            uint8_t id_3248 { 0 };
            Vec<1, uint8_t> id_3249 {  id_3248  };
            ac0fbd05039f742d2f1d9ac182e392ab let_res_3250;
            {
              Vec<1, uint8_t> shft_ref_999 { id_3249 };
              Vec<1, Pointer> id_3251 {  dsum1_snd_64  };
              ac0fbd05039f742d2f1d9ac182e392ab let_res_3252;
              {
                Vec<1, Pointer> p_ref_1000 { id_3251 };
                bool while_flag_3253 { true };
                do {
                  uint8_t id_3254 { 0 };
                  Pointer id_3255 { p_ref_1000[id_3254] };
                  v_1d5843897434feb24d158f3793db9189 id_3256 { id_3255.readU8() };
                  bool let_res_3257;
                  {
                    v_1d5843897434feb24d158f3793db9189 leb128_1001 { id_3256 };
                    bool letpair_res_3258;
                    {
                      auto leb128_fst_1002 { std::get<0>(leb128_1001) };
                      auto leb128_snd_1003 { std::get<1>(leb128_1001) };
                      uint8_t id_3259 { 0 };
                      Void id_3260 { ((void)(p_ref_1000[id_3259] = leb128_snd_1003), VOID) };
                      uint8_t id_3261 { 0 };
                      uint8_t id_3262 { 127 };
                      uint8_t id_3263 { uint8_t(leb128_fst_1002 & id_3262) };
                      uint32_t id_3264 { uint32_t(id_3263) };
                      uint8_t id_3265 { 0 };
                      uint8_t id_3266 { shft_ref_999[id_3265] };
                      uint32_t id_3267 { uint32_t(id_3264 << id_3266) };
                      uint8_t id_3268 { 0 };
                      uint32_t id_3269 { leb_ref_998[id_3268] };
                      uint32_t id_3270 { uint32_t(id_3267 | id_3269) };
                      Void id_3271 { ((void)(leb_ref_998[id_3261] = id_3270), VOID) };
                      uint8_t id_3272 { 0 };
                      uint8_t id_3273 { 0 };
                      uint8_t id_3274 { shft_ref_999[id_3273] };
                      uint8_t id_3275 { 7 };
                      uint8_t id_3276 { uint8_t(id_3274 + id_3275) };
                      Void id_3277 { ((void)(shft_ref_999[id_3272] = id_3276), VOID) };
                      uint8_t id_3278 { 128 };
                      bool id_3279 { bool(leb128_fst_1002 >= id_3278) };
                      letpair_res_3258 = id_3279;
                    }
                    let_res_3257 = letpair_res_3258;
                  }
                  while_flag_3253 = let_res_3257;
                  if (while_flag_3253) {
                  }
                } while (while_flag_3253);
                uint8_t id_3280 { 0 };
                uint32_t id_3281 { leb_ref_998[id_3280] };
                uint8_t id_3282 { 0 };
                Pointer id_3283 { p_ref_1000[id_3282] };
                ac0fbd05039f742d2f1d9ac182e392ab id_3284 {  id_3281, id_3283  };
                let_res_3252 = id_3284;
              }
              let_res_3250 = let_res_3252;
            }
            let_res_3247 = let_res_3250;
          }
          e8d9438e2f3a196555a010d8d14a3c3a let_res_3285;
          {
            ac0fbd05039f742d2f1d9ac182e392ab dlist1_1007 { let_res_3247 };
            e8d9438e2f3a196555a010d8d14a3c3a letpair_res_3286;
            {
              auto dlist1_fst_1008 { std::get<0>(dlist1_1007) };
              auto dlist1_snd_1009 { std::get<1>(dlist1_1007) };
              Lst<t*> endoflist_3287;
              e8d9438e2f3a196555a010d8d14a3c3a id_3288 {  endoflist_3287, dlist1_snd_1009  };
              Vec<1, e8d9438e2f3a196555a010d8d14a3c3a> id_3289 {  id_3288  };
              e8d9438e2f3a196555a010d8d14a3c3a let_res_3290;
              {
                Vec<1, e8d9438e2f3a196555a010d8d14a3c3a> inits_src_ref_1010 { id_3289 };
                int32_t id_3291 { 0L };
                Vec<1, int32_t> id_3292 {  id_3291  };
                {
                  Vec<1, int32_t> repeat_n_1011 { id_3292 };
                  bool while_flag_3293 { true };
                  do {
                    int32_t id_3294 { int32_t(dlist1_fst_1008) };
                    uint8_t id_3295 { 0 };
                    int32_t id_3296 { repeat_n_1011[id_3295] };
                    bool id_3297 { bool(id_3294 > id_3296) };
                    while_flag_3293 = id_3297;
                    if (while_flag_3293) {
                      uint8_t id_3298 { 0 };
                      e8d9438e2f3a196555a010d8d14a3c3a id_3299 { inits_src_ref_1010[id_3298] };
                      {
                        e8d9438e2f3a196555a010d8d14a3c3a dlist2_1012 { id_3299 };
                        {
                          auto dlist2_fst_1013 { std::get<0>(dlist2_1012) };
                          auto dlist2_snd_1014 { std::get<1>(dlist2_1012) };
                          uint8_t id_3300 { 0 };
                          f63f919559f0d70225bd0da5dd9bcafc id_3301 { fun3236(dlist2_snd_1014) };
                          e8d9438e2f3a196555a010d8d14a3c3a letpair_res_3302;
                          {
                            auto dlist3_fst_1016 { std::get<0>(id_3301) };
                            auto dlist3_snd_1017 { std::get<1>(id_3301) };
                            Lst<t*> id_3303 { dlist3_fst_1016, dlist2_fst_1013 };
                            e8d9438e2f3a196555a010d8d14a3c3a id_3304 {  id_3303, dlist3_snd_1017  };
                            letpair_res_3302 = id_3304;
                          }
                          Void id_3305 { ((void)(inits_src_ref_1010[id_3300] = letpair_res_3302), VOID) };
                        }
                      }
                      uint8_t id_3306 { 0 };
                      uint8_t id_3307 { 0 };
                      int32_t id_3308 { repeat_n_1011[id_3307] };
                      int32_t id_3309 { 1L };
                      int32_t id_3310 { int32_t(id_3308 + id_3309) };
                      Void id_3311 { ((void)(repeat_n_1011[id_3306] = id_3310), VOID) };
                    }
                  } while (while_flag_3293);
                }
                uint8_t id_3312 { 0 };
                e8d9438e2f3a196555a010d8d14a3c3a id_3313 { inits_src_ref_1010[id_3312] };
                let_res_3290 = id_3313;
              }
              letpair_res_3286 = let_res_3290;
            }
            let_res_3285 = letpair_res_3286;
          }
          f05619a6958568f0d4db38b191811dc1 letpair_res_3314;
          {
            auto dlist4_fst_1019 { std::get<0>(let_res_3285) };
            auto dlist4_snd_1020 { std::get<1>(let_res_3285) };
            dc31f5cc689133a6f12d16478388e785 id_3315 { std::in_place_index<0>, dlist4_fst_1019 };
            f05619a6958568f0d4db38b191811dc1 id_3316 {  id_3315, dlist4_snd_1020  };
            letpair_res_3314 = id_3316;
          }
          choose_res_3244 = letpair_res_3314;
        } else {
          uint16_t id_3317 { 1 };
          bool id_3318 { bool(id_3317 == dsum1_fst_63) };
          f05619a6958568f0d4db38b191811dc1 choose_res_3319;
          if (id_3318) {
            uint32_t id_3320 { 0U };
            Vec<1, uint32_t> id_3321 {  id_3320  };
            ac0fbd05039f742d2f1d9ac182e392ab let_res_3322;
            {
              Vec<1, uint32_t> leb_ref_966 { id_3321 };
              uint8_t id_3323 { 0 };
              Vec<1, uint8_t> id_3324 {  id_3323  };
              ac0fbd05039f742d2f1d9ac182e392ab let_res_3325;
              {
                Vec<1, uint8_t> shft_ref_967 { id_3324 };
                Vec<1, Pointer> id_3326 {  dsum1_snd_64  };
                ac0fbd05039f742d2f1d9ac182e392ab let_res_3327;
                {
                  Vec<1, Pointer> p_ref_968 { id_3326 };
                  bool while_flag_3328 { true };
                  do {
                    uint8_t id_3329 { 0 };
                    Pointer id_3330 { p_ref_968[id_3329] };
                    v_1d5843897434feb24d158f3793db9189 id_3331 { id_3330.readU8() };
                    bool let_res_3332;
                    {
                      v_1d5843897434feb24d158f3793db9189 leb128_969 { id_3331 };
                      bool letpair_res_3333;
                      {
                        auto leb128_fst_970 { std::get<0>(leb128_969) };
                        auto leb128_snd_971 { std::get<1>(leb128_969) };
                        uint8_t id_3334 { 0 };
                        Void id_3335 { ((void)(p_ref_968[id_3334] = leb128_snd_971), VOID) };
                        uint8_t id_3336 { 0 };
                        uint8_t id_3337 { 127 };
                        uint8_t id_3338 { uint8_t(leb128_fst_970 & id_3337) };
                        uint32_t id_3339 { uint32_t(id_3338) };
                        uint8_t id_3340 { 0 };
                        uint8_t id_3341 { shft_ref_967[id_3340] };
                        uint32_t id_3342 { uint32_t(id_3339 << id_3341) };
                        uint8_t id_3343 { 0 };
                        uint32_t id_3344 { leb_ref_966[id_3343] };
                        uint32_t id_3345 { uint32_t(id_3342 | id_3344) };
                        Void id_3346 { ((void)(leb_ref_966[id_3336] = id_3345), VOID) };
                        uint8_t id_3347 { 0 };
                        uint8_t id_3348 { 0 };
                        uint8_t id_3349 { shft_ref_967[id_3348] };
                        uint8_t id_3350 { 7 };
                        uint8_t id_3351 { uint8_t(id_3349 + id_3350) };
                        Void id_3352 { ((void)(shft_ref_967[id_3347] = id_3351), VOID) };
                        uint8_t id_3353 { 128 };
                        bool id_3354 { bool(leb128_fst_970 >= id_3353) };
                        letpair_res_3333 = id_3354;
                      }
                      let_res_3332 = letpair_res_3333;
                    }
                    while_flag_3328 = let_res_3332;
                    if (while_flag_3328) {
                    }
                  } while (while_flag_3328);
                  uint8_t id_3355 { 0 };
                  uint32_t id_3356 { leb_ref_966[id_3355] };
                  uint8_t id_3357 { 0 };
                  Pointer id_3358 { p_ref_968[id_3357] };
                  ac0fbd05039f742d2f1d9ac182e392ab id_3359 {  id_3356, id_3358  };
                  let_res_3327 = id_3359;
                }
                let_res_3325 = let_res_3327;
              }
              let_res_3322 = let_res_3325;
            }
            ddcd449f1e33242c42af2676798021aa let_res_3360;
            {
              ac0fbd05039f742d2f1d9ac182e392ab dlist1_975 { let_res_3322 };
              ddcd449f1e33242c42af2676798021aa letpair_res_3361;
              {
                auto dlist1_fst_976 { std::get<0>(dlist1_975) };
                auto dlist1_snd_977 { std::get<1>(dlist1_975) };
                Lst<v_4ec9e9432e07cae1458c03426a194a1a> endoflist_3362;
                ddcd449f1e33242c42af2676798021aa id_3363 {  endoflist_3362, dlist1_snd_977  };
                Vec<1, ddcd449f1e33242c42af2676798021aa> id_3364 {  id_3363  };
                ddcd449f1e33242c42af2676798021aa let_res_3365;
                {
                  Vec<1, ddcd449f1e33242c42af2676798021aa> inits_src_ref_978 { id_3364 };
                  int32_t id_3366 { 0L };
                  Vec<1, int32_t> id_3367 {  id_3366  };
                  {
                    Vec<1, int32_t> repeat_n_979 { id_3367 };
                    bool while_flag_3368 { true };
                    do {
                      int32_t id_3369 { int32_t(dlist1_fst_976) };
                      uint8_t id_3370 { 0 };
                      int32_t id_3371 { repeat_n_979[id_3370] };
                      bool id_3372 { bool(id_3369 > id_3371) };
                      while_flag_3368 = id_3372;
                      if (while_flag_3368) {
                        uint8_t id_3373 { 0 };
                        ddcd449f1e33242c42af2676798021aa id_3374 { inits_src_ref_978[id_3373] };
                        {
                          ddcd449f1e33242c42af2676798021aa dlist2_980 { id_3374 };
                          {
                            auto dlist2_fst_981 { std::get<0>(dlist2_980) };
                            auto dlist2_snd_982 { std::get<1>(dlist2_980) };
                            uint8_t id_3375 { 0 };
                            std::function<c50aa083fa818c6eeca389b0025dda98(Pointer)> id_3376 { dessser::gen::field_name::of_row_binary };
                            c50aa083fa818c6eeca389b0025dda98 id_3377 { id_3376(dlist2_snd_982) };
                            ddcd449f1e33242c42af2676798021aa letpair_res_3378;
                            {
                              auto dtup_fst_984 { std::get<0>(id_3377) };
                              auto dtup_snd_985 { std::get<1>(id_3377) };
                              f63f919559f0d70225bd0da5dd9bcafc id_3379 { fun3236(dtup_snd_985) };
                              ddcd449f1e33242c42af2676798021aa letpair_res_3380;
                              {
                                auto dtup_fst_987 { std::get<0>(id_3379) };
                                auto dtup_snd_988 { std::get<1>(id_3379) };
                                v_4ec9e9432e07cae1458c03426a194a1a id_3381 {  dtup_fst_984, dtup_fst_987  };
                                Lst<v_4ec9e9432e07cae1458c03426a194a1a> id_3382 { id_3381, dlist2_fst_981 };
                                ddcd449f1e33242c42af2676798021aa id_3383 {  id_3382, dtup_snd_988  };
                                letpair_res_3380 = id_3383;
                              }
                              letpair_res_3378 = letpair_res_3380;
                            }
                            Void id_3384 { ((void)(inits_src_ref_978[id_3375] = letpair_res_3378), VOID) };
                          }
                        }
                        uint8_t id_3385 { 0 };
                        uint8_t id_3386 { 0 };
                        int32_t id_3387 { repeat_n_979[id_3386] };
                        int32_t id_3388 { 1L };
                        int32_t id_3389 { int32_t(id_3387 + id_3388) };
                        Void id_3390 { ((void)(repeat_n_979[id_3385] = id_3389), VOID) };
                      }
                    } while (while_flag_3368);
                  }
                  uint8_t id_3391 { 0 };
                  ddcd449f1e33242c42af2676798021aa id_3392 { inits_src_ref_978[id_3391] };
                  let_res_3365 = id_3392;
                }
                letpair_res_3361 = let_res_3365;
              }
              let_res_3360 = letpair_res_3361;
            }
            f05619a6958568f0d4db38b191811dc1 letpair_res_3393;
            {
              auto dlist4_fst_993 { std::get<0>(let_res_3360) };
              auto dlist4_snd_994 { std::get<1>(let_res_3360) };
              dc31f5cc689133a6f12d16478388e785 id_3394 { std::in_place_index<1>, dlist4_fst_993 };
              f05619a6958568f0d4db38b191811dc1 id_3395 {  id_3394, dlist4_snd_994  };
              letpair_res_3393 = id_3395;
            }
            choose_res_3319 = letpair_res_3393;
          } else {
            uint16_t id_3396 { 2 };
            bool id_3397 { bool(id_3396 == dsum1_fst_63) };
            f05619a6958568f0d4db38b191811dc1 choose_res_3398;
            if (id_3397) {
              uint32_t id_3399 { 0U };
              Vec<1, uint32_t> id_3400 {  id_3399  };
              ac0fbd05039f742d2f1d9ac182e392ab let_res_3401;
              {
                Vec<1, uint32_t> leb_ref_940 { id_3400 };
                uint8_t id_3402 { 0 };
                Vec<1, uint8_t> id_3403 {  id_3402  };
                ac0fbd05039f742d2f1d9ac182e392ab let_res_3404;
                {
                  Vec<1, uint8_t> shft_ref_941 { id_3403 };
                  Vec<1, Pointer> id_3405 {  dsum1_snd_64  };
                  ac0fbd05039f742d2f1d9ac182e392ab let_res_3406;
                  {
                    Vec<1, Pointer> p_ref_942 { id_3405 };
                    bool while_flag_3407 { true };
                    do {
                      uint8_t id_3408 { 0 };
                      Pointer id_3409 { p_ref_942[id_3408] };
                      v_1d5843897434feb24d158f3793db9189 id_3410 { id_3409.readU8() };
                      bool let_res_3411;
                      {
                        v_1d5843897434feb24d158f3793db9189 leb128_943 { id_3410 };
                        bool letpair_res_3412;
                        {
                          auto leb128_fst_944 { std::get<0>(leb128_943) };
                          auto leb128_snd_945 { std::get<1>(leb128_943) };
                          uint8_t id_3413 { 0 };
                          Void id_3414 { ((void)(p_ref_942[id_3413] = leb128_snd_945), VOID) };
                          uint8_t id_3415 { 0 };
                          uint8_t id_3416 { 127 };
                          uint8_t id_3417 { uint8_t(leb128_fst_944 & id_3416) };
                          uint32_t id_3418 { uint32_t(id_3417) };
                          uint8_t id_3419 { 0 };
                          uint8_t id_3420 { shft_ref_941[id_3419] };
                          uint32_t id_3421 { uint32_t(id_3418 << id_3420) };
                          uint8_t id_3422 { 0 };
                          uint32_t id_3423 { leb_ref_940[id_3422] };
                          uint32_t id_3424 { uint32_t(id_3421 | id_3423) };
                          Void id_3425 { ((void)(leb_ref_940[id_3415] = id_3424), VOID) };
                          uint8_t id_3426 { 0 };
                          uint8_t id_3427 { 0 };
                          uint8_t id_3428 { shft_ref_941[id_3427] };
                          uint8_t id_3429 { 7 };
                          uint8_t id_3430 { uint8_t(id_3428 + id_3429) };
                          Void id_3431 { ((void)(shft_ref_941[id_3426] = id_3430), VOID) };
                          uint8_t id_3432 { 128 };
                          bool id_3433 { bool(leb128_fst_944 >= id_3432) };
                          letpair_res_3412 = id_3433;
                        }
                        let_res_3411 = letpair_res_3412;
                      }
                      while_flag_3407 = let_res_3411;
                      if (while_flag_3407) {
                      }
                    } while (while_flag_3407);
                    uint8_t id_3434 { 0 };
                    uint32_t id_3435 { leb_ref_940[id_3434] };
                    uint8_t id_3436 { 0 };
                    Pointer id_3437 { p_ref_942[id_3436] };
                    ac0fbd05039f742d2f1d9ac182e392ab id_3438 {  id_3435, id_3437  };
                    let_res_3406 = id_3438;
                  }
                  let_res_3404 = let_res_3406;
                }
                let_res_3401 = let_res_3404;
              }
              e8d9438e2f3a196555a010d8d14a3c3a let_res_3439;
              {
                ac0fbd05039f742d2f1d9ac182e392ab dlist1_949 { let_res_3401 };
                e8d9438e2f3a196555a010d8d14a3c3a letpair_res_3440;
                {
                  auto dlist1_fst_950 { std::get<0>(dlist1_949) };
                  auto dlist1_snd_951 { std::get<1>(dlist1_949) };
                  Lst<t*> endoflist_3441;
                  e8d9438e2f3a196555a010d8d14a3c3a id_3442 {  endoflist_3441, dlist1_snd_951  };
                  Vec<1, e8d9438e2f3a196555a010d8d14a3c3a> id_3443 {  id_3442  };
                  e8d9438e2f3a196555a010d8d14a3c3a let_res_3444;
                  {
                    Vec<1, e8d9438e2f3a196555a010d8d14a3c3a> inits_src_ref_952 { id_3443 };
                    int32_t id_3445 { 0L };
                    Vec<1, int32_t> id_3446 {  id_3445  };
                    {
                      Vec<1, int32_t> repeat_n_953 { id_3446 };
                      bool while_flag_3447 { true };
                      do {
                        int32_t id_3448 { int32_t(dlist1_fst_950) };
                        uint8_t id_3449 { 0 };
                        int32_t id_3450 { repeat_n_953[id_3449] };
                        bool id_3451 { bool(id_3448 > id_3450) };
                        while_flag_3447 = id_3451;
                        if (while_flag_3447) {
                          uint8_t id_3452 { 0 };
                          e8d9438e2f3a196555a010d8d14a3c3a id_3453 { inits_src_ref_952[id_3452] };
                          {
                            e8d9438e2f3a196555a010d8d14a3c3a dlist2_954 { id_3453 };
                            {
                              auto dlist2_fst_955 { std::get<0>(dlist2_954) };
                              auto dlist2_snd_956 { std::get<1>(dlist2_954) };
                              uint8_t id_3454 { 0 };
                              f63f919559f0d70225bd0da5dd9bcafc id_3455 { fun3236(dlist2_snd_956) };
                              e8d9438e2f3a196555a010d8d14a3c3a letpair_res_3456;
                              {
                                auto dlist3_fst_958 { std::get<0>(id_3455) };
                                auto dlist3_snd_959 { std::get<1>(id_3455) };
                                Lst<t*> id_3457 { dlist3_fst_958, dlist2_fst_955 };
                                e8d9438e2f3a196555a010d8d14a3c3a id_3458 {  id_3457, dlist3_snd_959  };
                                letpair_res_3456 = id_3458;
                              }
                              Void id_3459 { ((void)(inits_src_ref_952[id_3454] = letpair_res_3456), VOID) };
                            }
                          }
                          uint8_t id_3460 { 0 };
                          uint8_t id_3461 { 0 };
                          int32_t id_3462 { repeat_n_953[id_3461] };
                          int32_t id_3463 { 1L };
                          int32_t id_3464 { int32_t(id_3462 + id_3463) };
                          Void id_3465 { ((void)(repeat_n_953[id_3460] = id_3464), VOID) };
                        }
                      } while (while_flag_3447);
                    }
                    uint8_t id_3466 { 0 };
                    e8d9438e2f3a196555a010d8d14a3c3a id_3467 { inits_src_ref_952[id_3466] };
                    let_res_3444 = id_3467;
                  }
                  letpair_res_3440 = let_res_3444;
                }
                let_res_3439 = letpair_res_3440;
              }
              f05619a6958568f0d4db38b191811dc1 letpair_res_3468;
              {
                auto dlist4_fst_961 { std::get<0>(let_res_3439) };
                auto dlist4_snd_962 { std::get<1>(let_res_3439) };
                dc31f5cc689133a6f12d16478388e785 id_3469 { std::in_place_index<2>, dlist4_fst_961 };
                f05619a6958568f0d4db38b191811dc1 id_3470 {  id_3469, dlist4_snd_962  };
                letpair_res_3468 = id_3470;
              }
              choose_res_3398 = letpair_res_3468;
            } else {
              uint16_t id_3471 { 3 };
              bool id_3472 { bool(id_3471 == dsum1_fst_63) };
              f05619a6958568f0d4db38b191811dc1 choose_res_3473;
              if (id_3472) {
                uint32_t id_3474 { 0U };
                Vec<1, uint32_t> id_3475 {  id_3474  };
                ac0fbd05039f742d2f1d9ac182e392ab let_res_3476;
                {
                  Vec<1, uint32_t> leb_ref_899 { id_3475 };
                  uint8_t id_3477 { 0 };
                  Vec<1, uint8_t> id_3478 {  id_3477  };
                  ac0fbd05039f742d2f1d9ac182e392ab let_res_3479;
                  {
                    Vec<1, uint8_t> shft_ref_900 { id_3478 };
                    Vec<1, Pointer> id_3480 {  dsum1_snd_64  };
                    ac0fbd05039f742d2f1d9ac182e392ab let_res_3481;
                    {
                      Vec<1, Pointer> p_ref_901 { id_3480 };
                      bool while_flag_3482 { true };
                      do {
                        uint8_t id_3483 { 0 };
                        Pointer id_3484 { p_ref_901[id_3483] };
                        v_1d5843897434feb24d158f3793db9189 id_3485 { id_3484.readU8() };
                        bool let_res_3486;
                        {
                          v_1d5843897434feb24d158f3793db9189 leb128_902 { id_3485 };
                          bool letpair_res_3487;
                          {
                            auto leb128_fst_903 { std::get<0>(leb128_902) };
                            auto leb128_snd_904 { std::get<1>(leb128_902) };
                            uint8_t id_3488 { 0 };
                            Void id_3489 { ((void)(p_ref_901[id_3488] = leb128_snd_904), VOID) };
                            uint8_t id_3490 { 0 };
                            uint8_t id_3491 { 127 };
                            uint8_t id_3492 { uint8_t(leb128_fst_903 & id_3491) };
                            uint32_t id_3493 { uint32_t(id_3492) };
                            uint8_t id_3494 { 0 };
                            uint8_t id_3495 { shft_ref_900[id_3494] };
                            uint32_t id_3496 { uint32_t(id_3493 << id_3495) };
                            uint8_t id_3497 { 0 };
                            uint32_t id_3498 { leb_ref_899[id_3497] };
                            uint32_t id_3499 { uint32_t(id_3496 | id_3498) };
                            Void id_3500 { ((void)(leb_ref_899[id_3490] = id_3499), VOID) };
                            uint8_t id_3501 { 0 };
                            uint8_t id_3502 { 0 };
                            uint8_t id_3503 { shft_ref_900[id_3502] };
                            uint8_t id_3504 { 7 };
                            uint8_t id_3505 { uint8_t(id_3503 + id_3504) };
                            Void id_3506 { ((void)(shft_ref_900[id_3501] = id_3505), VOID) };
                            uint8_t id_3507 { 128 };
                            bool id_3508 { bool(leb128_fst_903 >= id_3507) };
                            letpair_res_3487 = id_3508;
                          }
                          let_res_3486 = letpair_res_3487;
                        }
                        while_flag_3482 = let_res_3486;
                        if (while_flag_3482) {
                        }
                      } while (while_flag_3482);
                      uint8_t id_3509 { 0 };
                      uint32_t id_3510 { leb_ref_899[id_3509] };
                      uint8_t id_3511 { 0 };
                      Pointer id_3512 { p_ref_901[id_3511] };
                      ac0fbd05039f742d2f1d9ac182e392ab id_3513 {  id_3510, id_3512  };
                      let_res_3481 = id_3513;
                    }
                    let_res_3479 = let_res_3481;
                  }
                  let_res_3476 = let_res_3479;
                }
                v_0f57f764bcc167c70e5ac8f496b908b3 let_res_3514;
                {
                  ac0fbd05039f742d2f1d9ac182e392ab dlist1_908 { let_res_3476 };
                  v_0f57f764bcc167c70e5ac8f496b908b3 letpair_res_3515;
                  {
                    auto dlist1_fst_909 { std::get<0>(dlist1_908) };
                    auto dlist1_snd_910 { std::get<1>(dlist1_908) };
                    Lst<a1a2ab208d8a8e56a609f18e422bdf88> endoflist_3516;
                    v_0f57f764bcc167c70e5ac8f496b908b3 id_3517 {  endoflist_3516, dlist1_snd_910  };
                    Vec<1, v_0f57f764bcc167c70e5ac8f496b908b3> id_3518 {  id_3517  };
                    v_0f57f764bcc167c70e5ac8f496b908b3 let_res_3519;
                    {
                      Vec<1, v_0f57f764bcc167c70e5ac8f496b908b3> inits_src_ref_911 { id_3518 };
                      int32_t id_3520 { 0L };
                      Vec<1, int32_t> id_3521 {  id_3520  };
                      {
                        Vec<1, int32_t> repeat_n_912 { id_3521 };
                        bool while_flag_3522 { true };
                        do {
                          int32_t id_3523 { int32_t(dlist1_fst_909) };
                          uint8_t id_3524 { 0 };
                          int32_t id_3525 { repeat_n_912[id_3524] };
                          bool id_3526 { bool(id_3523 > id_3525) };
                          while_flag_3522 = id_3526;
                          if (while_flag_3522) {
                            uint8_t id_3527 { 0 };
                            v_0f57f764bcc167c70e5ac8f496b908b3 id_3528 { inits_src_ref_911[id_3527] };
                            {
                              v_0f57f764bcc167c70e5ac8f496b908b3 dlist2_913 { id_3528 };
                              {
                                auto dlist2_fst_914 { std::get<0>(dlist2_913) };
                                auto dlist2_snd_915 { std::get<1>(dlist2_913) };
                                uint8_t id_3529 { 0 };
                                f63f919559f0d70225bd0da5dd9bcafc id_3530 { fun3236(dlist2_snd_915) };
                                v_0f57f764bcc167c70e5ac8f496b908b3 letpair_res_3531;
                                {
                                  auto drec_fst_917 { std::get<0>(id_3530) };
                                  auto drec_snd_918 { std::get<1>(id_3530) };
                                  f63f919559f0d70225bd0da5dd9bcafc id_3532 { fun3236(drec_snd_918) };
                                  v_0f57f764bcc167c70e5ac8f496b908b3 letpair_res_3533;
                                  {
                                    auto drec_fst_920 { std::get<0>(id_3532) };
                                    auto drec_snd_921 { std::get<1>(id_3532) };
                                    a1a2ab208d8a8e56a609f18e422bdf88 id_3534 {  .case_cond = drec_fst_917, .case_cons = drec_fst_920  };
                                    Lst<a1a2ab208d8a8e56a609f18e422bdf88> id_3535 { id_3534, dlist2_fst_914 };
                                    v_0f57f764bcc167c70e5ac8f496b908b3 id_3536 {  id_3535, drec_snd_921  };
                                    letpair_res_3533 = id_3536;
                                  }
                                  letpair_res_3531 = letpair_res_3533;
                                }
                                Void id_3537 { ((void)(inits_src_ref_911[id_3529] = letpair_res_3531), VOID) };
                              }
                            }
                            uint8_t id_3538 { 0 };
                            uint8_t id_3539 { 0 };
                            int32_t id_3540 { repeat_n_912[id_3539] };
                            int32_t id_3541 { 1L };
                            int32_t id_3542 { int32_t(id_3540 + id_3541) };
                            Void id_3543 { ((void)(repeat_n_912[id_3538] = id_3542), VOID) };
                          }
                        } while (while_flag_3522);
                      }
                      uint8_t id_3544 { 0 };
                      v_0f57f764bcc167c70e5ac8f496b908b3 id_3545 { inits_src_ref_911[id_3544] };
                      let_res_3519 = id_3545;
                    }
                    letpair_res_3515 = let_res_3519;
                  }
                  let_res_3514 = letpair_res_3515;
                }
                v_0f57f764bcc167c70e5ac8f496b908b3 letpair_res_3546;
                {
                  auto dlist4_fst_926 { std::get<0>(let_res_3514) };
                  auto dlist4_snd_927 { std::get<1>(let_res_3514) };
                  v_0f57f764bcc167c70e5ac8f496b908b3 id_3547 {  dlist4_fst_926, dlist4_snd_927  };
                  letpair_res_3546 = id_3547;
                }
                f05619a6958568f0d4db38b191811dc1 let_res_3548;
                {
                  v_0f57f764bcc167c70e5ac8f496b908b3 dtup_928 { letpair_res_3546 };
                  f05619a6958568f0d4db38b191811dc1 letpair_res_3549;
                  {
                    auto dtup_fst_929 { std::get<0>(dtup_928) };
                    auto dtup_snd_930 { std::get<1>(dtup_928) };
                    Size id_3550 { 0UL };
                    uint8_t id_3551 { dtup_snd_930.peekU8(id_3550) };
                    uint8_t id_3552 { 1 };
                    bool id_3553 { bool(id_3551 == id_3552) };
                    ff77a37bf330c28b69daf62f3f59e310 choose_res_3554;
                    if (id_3553) {
                      std::optional<t*> id_3555 { std::nullopt };
                      Size id_3556 { 1UL };
                      Pointer id_3557 { dtup_snd_930.skip(id_3556) };
                      ff77a37bf330c28b69daf62f3f59e310 id_3558 {  id_3555, id_3557  };
                      choose_res_3554 = id_3558;
                    } else {
                      Size id_3559 { 1UL };
                      Pointer id_3560 { dtup_snd_930.skip(id_3559) };
                      f63f919559f0d70225bd0da5dd9bcafc id_3561 { fun3236(id_3560) };
                      ff77a37bf330c28b69daf62f3f59e310 letpair_res_3562;
                      {
                        auto make1_1_fst_932 { std::get<0>(id_3561) };
                        auto make1_1_snd_933 { std::get<1>(id_3561) };
                        std::optional<t*> id_3563 { make1_1_fst_932 };
                        ff77a37bf330c28b69daf62f3f59e310 id_3564 {  id_3563, make1_1_snd_933  };
                        letpair_res_3562 = id_3564;
                      }
                      choose_res_3554 = letpair_res_3562;
                    }
                    f05619a6958568f0d4db38b191811dc1 letpair_res_3565;
                    {
                      auto dtup_fst_935 { std::get<0>(choose_res_3554) };
                      auto dtup_snd_936 { std::get<1>(choose_res_3554) };
                      v_7df1ef9c4e82bfdd017031822619493c id_3566 {  dtup_fst_929, dtup_fst_935  };
                      dc31f5cc689133a6f12d16478388e785 id_3567 { std::in_place_index<3>, id_3566 };
                      f05619a6958568f0d4db38b191811dc1 id_3568 {  id_3567, dtup_snd_936  };
                      letpair_res_3565 = id_3568;
                    }
                    letpair_res_3549 = letpair_res_3565;
                  }
                  let_res_3548 = letpair_res_3549;
                }
                choose_res_3473 = let_res_3548;
              } else {
                uint16_t id_3569 { 4 };
                bool id_3570 { bool(id_3569 == dsum1_fst_63) };
                f05619a6958568f0d4db38b191811dc1 choose_res_3571;
                if (id_3570) {
                  v_362f9d9108a6902af48b6c83d5377ea1 id_3572 { dsum1_snd_64.readU16Le() };
                  v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_3573;
                  {
                    auto du16_fst_470 { std::get<0>(id_3572) };
                    auto du16_snd_471 { std::get<1>(id_3572) };
                    v_362f9d9108a6902af48b6c83d5377ea1 id_3574 {  du16_fst_470, du16_snd_471  };
                    letpair_res_3573 = id_3574;
                  }
                  b1ffdd8a8f59914e8b21c924b278b478 let_res_3575;
                  {
                    v_362f9d9108a6902af48b6c83d5377ea1 dsum1_475 { letpair_res_3573 };
                    b1ffdd8a8f59914e8b21c924b278b478 letpair_res_3576;
                    {
                      auto dsum1_fst_476 { std::get<0>(dsum1_475) };
                      auto dsum1_snd_477 { std::get<1>(dsum1_475) };
                      uint16_t id_3577 { 0 };
                      bool id_3578 { bool(id_3577 == dsum1_fst_476) };
                      b1ffdd8a8f59914e8b21c924b278b478 choose_res_3579;
                      if (id_3578) {
                        v_362f9d9108a6902af48b6c83d5377ea1 id_3580 { dsum1_snd_477.readU16Le() };
                        v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_3581;
                        {
                          auto du16_fst_835 { std::get<0>(id_3580) };
                          auto du16_snd_836 { std::get<1>(id_3580) };
                          v_362f9d9108a6902af48b6c83d5377ea1 id_3582 {  du16_fst_835, du16_snd_836  };
                          letpair_res_3581 = id_3582;
                        }
                        v_38bf909989bc149a6bff52aacf0b29a7 let_res_3583;
                        {
                          v_362f9d9108a6902af48b6c83d5377ea1 dsum1_840 { letpair_res_3581 };
                          v_38bf909989bc149a6bff52aacf0b29a7 letpair_res_3584;
                          {
                            auto dsum1_fst_841 { std::get<0>(dsum1_840) };
                            auto dsum1_snd_842 { std::get<1>(dsum1_840) };
                            uint16_t id_3585 { 0 };
                            bool id_3586 { bool(id_3585 == dsum1_fst_841) };
                            v_38bf909989bc149a6bff52aacf0b29a7 choose_res_3587;
                            if (id_3586) {
                              std::function<ba3b596d6a5cbc29dc62e6e6a46440d5(Pointer)> id_3588 { dessser::gen::raql_value::of_row_binary };
                              ba3b596d6a5cbc29dc62e6e6a46440d5 id_3589 { id_3588(dsum1_snd_842) };
                              v_38bf909989bc149a6bff52aacf0b29a7 letpair_res_3590;
                              {
                                auto dsum2_fst_891 { std::get<0>(id_3589) };
                                auto dsum2_snd_892 { std::get<1>(id_3589) };
                                b02d571406bf80b296e55bb93213ea59 id_3591 { std::in_place_index<0>, dsum2_fst_891 };
                                v_38bf909989bc149a6bff52aacf0b29a7 id_3592 {  id_3591, dsum2_snd_892  };
                                letpair_res_3590 = id_3592;
                              }
                              choose_res_3587 = letpair_res_3590;
                            } else {
                              uint16_t id_3593 { 1 };
                              bool id_3594 { bool(id_3593 == dsum1_fst_841) };
                              v_38bf909989bc149a6bff52aacf0b29a7 choose_res_3595;
                              if (id_3594) {
                                std::function<v_0f2a71b58e80153fa85a979b6a0daf94(Pointer)> id_3596 { dessser::gen::raql_variable::of_row_binary };
                                v_0f2a71b58e80153fa85a979b6a0daf94 id_3597 { id_3596(dsum1_snd_842) };
                                v_38bf909989bc149a6bff52aacf0b29a7 letpair_res_3598;
                                {
                                  auto dsum2_fst_888 { std::get<0>(id_3597) };
                                  auto dsum2_snd_889 { std::get<1>(id_3597) };
                                  b02d571406bf80b296e55bb93213ea59 id_3599 { std::in_place_index<1>, dsum2_fst_888 };
                                  v_38bf909989bc149a6bff52aacf0b29a7 id_3600 {  id_3599, dsum2_snd_889  };
                                  letpair_res_3598 = id_3600;
                                }
                                choose_res_3595 = letpair_res_3598;
                              } else {
                                uint16_t id_3601 { 2 };
                                bool id_3602 { bool(id_3601 == dsum1_fst_841) };
                                v_38bf909989bc149a6bff52aacf0b29a7 choose_res_3603;
                                if (id_3602) {
                                  std::function<eeea9b724957fbc1223450da0773b8d1(Pointer)> id_3604 { dessser::gen::raql_binding_key::of_row_binary };
                                  eeea9b724957fbc1223450da0773b8d1 id_3605 { id_3604(dsum1_snd_842) };
                                  v_38bf909989bc149a6bff52aacf0b29a7 letpair_res_3606;
                                  {
                                    auto dsum2_fst_885 { std::get<0>(id_3605) };
                                    auto dsum2_snd_886 { std::get<1>(id_3605) };
                                    b02d571406bf80b296e55bb93213ea59 id_3607 { std::in_place_index<2>, dsum2_fst_885 };
                                    v_38bf909989bc149a6bff52aacf0b29a7 id_3608 {  id_3607, dsum2_snd_886  };
                                    letpair_res_3606 = id_3608;
                                  }
                                  choose_res_3603 = letpair_res_3606;
                                } else {
                                  uint16_t id_3609 { 3 };
                                  bool id_3610 { bool(id_3609 == dsum1_fst_841) };
                                  v_38bf909989bc149a6bff52aacf0b29a7 choose_res_3611;
                                  if (id_3610) {
                                    b02d571406bf80b296e55bb93213ea59 id_3612 { std::in_place_index<3>, VOID };
                                    v_38bf909989bc149a6bff52aacf0b29a7 id_3613 {  id_3612, dsum1_snd_842  };
                                    choose_res_3611 = id_3613;
                                  } else {
                                    uint16_t id_3614 { 4 };
                                    bool id_3615 { bool(id_3614 == dsum1_fst_841) };
                                    v_38bf909989bc149a6bff52aacf0b29a7 choose_res_3616;
                                    if (id_3615) {
                                      b02d571406bf80b296e55bb93213ea59 id_3617 { std::in_place_index<4>, VOID };
                                      v_38bf909989bc149a6bff52aacf0b29a7 id_3618 {  id_3617, dsum1_snd_842  };
                                      choose_res_3616 = id_3618;
                                    } else {
                                      uint16_t id_3619 { 5 };
                                      bool id_3620 { bool(id_3619 == dsum1_fst_841) };
                                      v_38bf909989bc149a6bff52aacf0b29a7 choose_res_3621;
                                      if (id_3620) {
                                        b02d571406bf80b296e55bb93213ea59 id_3622 { std::in_place_index<5>, VOID };
                                        v_38bf909989bc149a6bff52aacf0b29a7 id_3623 {  id_3622, dsum1_snd_842  };
                                        choose_res_3621 = id_3623;
                                      } else {
                                        uint16_t id_3624 { 6 };
                                        bool id_3625 { bool(id_3624 == dsum1_fst_841) };
                                        v_38bf909989bc149a6bff52aacf0b29a7 choose_res_3626;
                                        if (id_3625) {
                                          b02d571406bf80b296e55bb93213ea59 id_3627 { std::in_place_index<6>, VOID };
                                          v_38bf909989bc149a6bff52aacf0b29a7 id_3628 {  id_3627, dsum1_snd_842  };
                                          choose_res_3626 = id_3628;
                                        } else {
                                          uint16_t id_3629 { 7 };
                                          bool id_3630 { bool(id_3629 == dsum1_fst_841) };
                                          v_38bf909989bc149a6bff52aacf0b29a7 choose_res_3631;
                                          if (id_3630) {
                                            uint32_t id_3632 { 0U };
                                            Vec<1, uint32_t> id_3633 {  id_3632  };
                                            ac0fbd05039f742d2f1d9ac182e392ab let_res_3634;
                                            {
                                              Vec<1, uint32_t> leb_ref_846 { id_3633 };
                                              uint8_t id_3635 { 0 };
                                              Vec<1, uint8_t> id_3636 {  id_3635  };
                                              ac0fbd05039f742d2f1d9ac182e392ab let_res_3637;
                                              {
                                                Vec<1, uint8_t> shft_ref_847 { id_3636 };
                                                Vec<1, Pointer> id_3638 {  dsum1_snd_842  };
                                                ac0fbd05039f742d2f1d9ac182e392ab let_res_3639;
                                                {
                                                  Vec<1, Pointer> p_ref_848 { id_3638 };
                                                  bool while_flag_3640 { true };
                                                  do {
                                                    uint8_t id_3641 { 0 };
                                                    Pointer id_3642 { p_ref_848[id_3641] };
                                                    v_1d5843897434feb24d158f3793db9189 id_3643 { id_3642.readU8() };
                                                    bool let_res_3644;
                                                    {
                                                      v_1d5843897434feb24d158f3793db9189 leb128_849 { id_3643 };
                                                      bool letpair_res_3645;
                                                      {
                                                        auto leb128_fst_850 { std::get<0>(leb128_849) };
                                                        auto leb128_snd_851 { std::get<1>(leb128_849) };
                                                        uint8_t id_3646 { 0 };
                                                        Void id_3647 { ((void)(p_ref_848[id_3646] = leb128_snd_851), VOID) };
                                                        uint8_t id_3648 { 0 };
                                                        uint8_t id_3649 { 127 };
                                                        uint8_t id_3650 { uint8_t(leb128_fst_850 & id_3649) };
                                                        uint32_t id_3651 { uint32_t(id_3650) };
                                                        uint8_t id_3652 { 0 };
                                                        uint8_t id_3653 { shft_ref_847[id_3652] };
                                                        uint32_t id_3654 { uint32_t(id_3651 << id_3653) };
                                                        uint8_t id_3655 { 0 };
                                                        uint32_t id_3656 { leb_ref_846[id_3655] };
                                                        uint32_t id_3657 { uint32_t(id_3654 | id_3656) };
                                                        Void id_3658 { ((void)(leb_ref_846[id_3648] = id_3657), VOID) };
                                                        uint8_t id_3659 { 0 };
                                                        uint8_t id_3660 { 0 };
                                                        uint8_t id_3661 { shft_ref_847[id_3660] };
                                                        uint8_t id_3662 { 7 };
                                                        uint8_t id_3663 { uint8_t(id_3661 + id_3662) };
                                                        Void id_3664 { ((void)(shft_ref_847[id_3659] = id_3663), VOID) };
                                                        uint8_t id_3665 { 128 };
                                                        bool id_3666 { bool(leb128_fst_850 >= id_3665) };
                                                        letpair_res_3645 = id_3666;
                                                      }
                                                      let_res_3644 = letpair_res_3645;
                                                    }
                                                    while_flag_3640 = let_res_3644;
                                                    if (while_flag_3640) {
                                                    }
                                                  } while (while_flag_3640);
                                                  uint8_t id_3667 { 0 };
                                                  uint32_t id_3668 { leb_ref_846[id_3667] };
                                                  uint8_t id_3669 { 0 };
                                                  Pointer id_3670 { p_ref_848[id_3669] };
                                                  ac0fbd05039f742d2f1d9ac182e392ab id_3671 {  id_3668, id_3670  };
                                                  let_res_3639 = id_3671;
                                                }
                                                let_res_3637 = let_res_3639;
                                              }
                                              let_res_3634 = let_res_3637;
                                            }
                                            v_8576a0d6d1057dc98fce5cca4d47a633 let_res_3672;
                                            {
                                              ac0fbd05039f742d2f1d9ac182e392ab dlist1_855 { let_res_3634 };
                                              v_8576a0d6d1057dc98fce5cca4d47a633 letpair_res_3673;
                                              {
                                                auto dlist1_fst_856 { std::get<0>(dlist1_855) };
                                                auto dlist1_snd_857 { std::get<1>(dlist1_855) };
                                                Lst<dessser::gen::raql_path_comp::t> endoflist_3674;
                                                v_8576a0d6d1057dc98fce5cca4d47a633 id_3675 {  endoflist_3674, dlist1_snd_857  };
                                                Vec<1, v_8576a0d6d1057dc98fce5cca4d47a633> id_3676 {  id_3675  };
                                                v_8576a0d6d1057dc98fce5cca4d47a633 let_res_3677;
                                                {
                                                  Vec<1, v_8576a0d6d1057dc98fce5cca4d47a633> inits_src_ref_858 { id_3676 };
                                                  int32_t id_3678 { 0L };
                                                  Vec<1, int32_t> id_3679 {  id_3678  };
                                                  {
                                                    Vec<1, int32_t> repeat_n_859 { id_3679 };
                                                    bool while_flag_3680 { true };
                                                    do {
                                                      int32_t id_3681 { int32_t(dlist1_fst_856) };
                                                      uint8_t id_3682 { 0 };
                                                      int32_t id_3683 { repeat_n_859[id_3682] };
                                                      bool id_3684 { bool(id_3681 > id_3683) };
                                                      while_flag_3680 = id_3684;
                                                      if (while_flag_3680) {
                                                        uint8_t id_3685 { 0 };
                                                        v_8576a0d6d1057dc98fce5cca4d47a633 id_3686 { inits_src_ref_858[id_3685] };
                                                        {
                                                          v_8576a0d6d1057dc98fce5cca4d47a633 dlist2_860 { id_3686 };
                                                          {
                                                            auto dlist2_fst_861 { std::get<0>(dlist2_860) };
                                                            auto dlist2_snd_862 { std::get<1>(dlist2_860) };
                                                            uint8_t id_3687 { 0 };
                                                            std::function<v_846cc5205657e1110a638b474c92c1c7(Pointer)> id_3688 { dessser::gen::raql_path_comp::of_row_binary };
                                                            v_846cc5205657e1110a638b474c92c1c7 id_3689 { id_3688(dlist2_snd_862) };
                                                            v_8576a0d6d1057dc98fce5cca4d47a633 letpair_res_3690;
                                                            {
                                                              auto dlist3_fst_864 { std::get<0>(id_3689) };
                                                              auto dlist3_snd_865 { std::get<1>(id_3689) };
                                                              Lst<dessser::gen::raql_path_comp::t> id_3691 { dlist3_fst_864, dlist2_fst_861 };
                                                              v_8576a0d6d1057dc98fce5cca4d47a633 id_3692 {  id_3691, dlist3_snd_865  };
                                                              letpair_res_3690 = id_3692;
                                                            }
                                                            Void id_3693 { ((void)(inits_src_ref_858[id_3687] = letpair_res_3690), VOID) };
                                                          }
                                                        }
                                                        uint8_t id_3694 { 0 };
                                                        uint8_t id_3695 { 0 };
                                                        int32_t id_3696 { repeat_n_859[id_3695] };
                                                        int32_t id_3697 { 1L };
                                                        int32_t id_3698 { int32_t(id_3696 + id_3697) };
                                                        Void id_3699 { ((void)(repeat_n_859[id_3694] = id_3698), VOID) };
                                                      }
                                                    } while (while_flag_3680);
                                                  }
                                                  uint8_t id_3700 { 0 };
                                                  v_8576a0d6d1057dc98fce5cca4d47a633 id_3701 { inits_src_ref_858[id_3700] };
                                                  let_res_3677 = id_3701;
                                                }
                                                letpair_res_3673 = let_res_3677;
                                              }
                                              let_res_3672 = letpair_res_3673;
                                            }
                                            v_38bf909989bc149a6bff52aacf0b29a7 letpair_res_3702;
                                            {
                                              auto dlist4_fst_867 { std::get<0>(let_res_3672) };
                                              auto dlist4_snd_868 { std::get<1>(let_res_3672) };
                                              b02d571406bf80b296e55bb93213ea59 id_3703 { std::in_place_index<7>, dlist4_fst_867 };
                                              v_38bf909989bc149a6bff52aacf0b29a7 id_3704 {  id_3703, dlist4_snd_868  };
                                              letpair_res_3702 = id_3704;
                                            }
                                            choose_res_3631 = letpair_res_3702;
                                          } else {
                                            uint16_t id_3705 { 8 };
                                            bool id_3706 { bool(dsum1_fst_841 == id_3705) };
                                            Void id_3707 { ((void)(assert(id_3706)), VOID) };
                                            b02d571406bf80b296e55bb93213ea59 id_3708 { std::in_place_index<8>, VOID };
                                            v_38bf909989bc149a6bff52aacf0b29a7 id_3709 {  id_3708, dsum1_snd_842  };
                                            choose_res_3631 = id_3709;
                                          }
                                          choose_res_3626 = choose_res_3631;
                                        }
                                        choose_res_3621 = choose_res_3626;
                                      }
                                      choose_res_3616 = choose_res_3621;
                                    }
                                    choose_res_3611 = choose_res_3616;
                                  }
                                  choose_res_3603 = choose_res_3611;
                                }
                                choose_res_3595 = choose_res_3603;
                              }
                              choose_res_3587 = choose_res_3595;
                            }
                            letpair_res_3584 = choose_res_3587;
                          }
                          let_res_3583 = letpair_res_3584;
                        }
                        b1ffdd8a8f59914e8b21c924b278b478 letpair_res_3710;
                        {
                          auto dsum2_fst_894 { std::get<0>(let_res_3583) };
                          auto dsum2_snd_895 { std::get<1>(let_res_3583) };
                          a481e1e269544fa0efe70fc68e01b3bb id_3711 { std::in_place_index<0>, dsum2_fst_894 };
                          b1ffdd8a8f59914e8b21c924b278b478 id_3712 {  id_3711, dsum2_snd_895  };
                          letpair_res_3710 = id_3712;
                        }
                        choose_res_3579 = letpair_res_3710;
                      } else {
                        uint16_t id_3713 { 1 };
                        bool id_3714 { bool(id_3713 == dsum1_fst_476) };
                        b1ffdd8a8f59914e8b21c924b278b478 choose_res_3715;
                        if (id_3714) {
                          v_362f9d9108a6902af48b6c83d5377ea1 id_3716 { dsum1_snd_477.readU16Le() };
                          v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_3717;
                          {
                            auto du16_fst_661 { std::get<0>(id_3716) };
                            auto du16_snd_662 { std::get<1>(id_3716) };
                            v_362f9d9108a6902af48b6c83d5377ea1 id_3718 {  du16_fst_661, du16_snd_662  };
                            letpair_res_3717 = id_3718;
                          }
                          v_13312187dea5608a1b10367f2c8e4e74 let_res_3719;
                          {
                            v_362f9d9108a6902af48b6c83d5377ea1 dsum1_666 { letpair_res_3717 };
                            v_13312187dea5608a1b10367f2c8e4e74 letpair_res_3720;
                            {
                              auto dsum1_fst_667 { std::get<0>(dsum1_666) };
                              auto dsum1_snd_668 { std::get<1>(dsum1_666) };
                              uint16_t id_3721 { 0 };
                              bool id_3722 { bool(id_3721 == dsum1_fst_667) };
                              v_13312187dea5608a1b10367f2c8e4e74 choose_res_3723;
                              if (id_3722) {
                                v_1d6ee587a956ed7717b51cc22dd3b087 id_3724 { std::in_place_index<0>, VOID };
                                v_13312187dea5608a1b10367f2c8e4e74 id_3725 {  id_3724, dsum1_snd_668  };
                                choose_res_3723 = id_3725;
                              } else {
                                uint16_t id_3726 { 1 };
                                bool id_3727 { bool(id_3726 == dsum1_fst_667) };
                                v_13312187dea5608a1b10367f2c8e4e74 choose_res_3728;
                                if (id_3727) {
                                  std::function<v_1afe9f73328d6d7bdf808b1d2eb2af22(Pointer)> id_3729 { dessser::gen::raql_type::of_row_binary };
                                  v_1afe9f73328d6d7bdf808b1d2eb2af22 id_3730 { id_3729(dsum1_snd_668) };
                                  v_13312187dea5608a1b10367f2c8e4e74 letpair_res_3731;
                                  {
                                    auto dsum2_fst_820 { std::get<0>(id_3730) };
                                    auto dsum2_snd_821 { std::get<1>(id_3730) };
                                    v_1d6ee587a956ed7717b51cc22dd3b087 id_3732 { std::in_place_index<1>, dsum2_fst_820 };
                                    v_13312187dea5608a1b10367f2c8e4e74 id_3733 {  id_3732, dsum2_snd_821  };
                                    letpair_res_3731 = id_3733;
                                  }
                                  choose_res_3728 = letpair_res_3731;
                                } else {
                                  uint16_t id_3734 { 2 };
                                  bool id_3735 { bool(id_3734 == dsum1_fst_667) };
                                  v_13312187dea5608a1b10367f2c8e4e74 choose_res_3736;
                                  if (id_3735) {
                                    v_1d6ee587a956ed7717b51cc22dd3b087 id_3737 { std::in_place_index<2>, VOID };
                                    v_13312187dea5608a1b10367f2c8e4e74 id_3738 {  id_3737, dsum1_snd_668  };
                                    choose_res_3736 = id_3738;
                                  } else {
                                    uint16_t id_3739 { 3 };
                                    bool id_3740 { bool(id_3739 == dsum1_fst_667) };
                                    v_13312187dea5608a1b10367f2c8e4e74 choose_res_3741;
                                    if (id_3740) {
                                      std::function<v_1afe9f73328d6d7bdf808b1d2eb2af22(Pointer)> id_3742 { dessser::gen::raql_type::of_row_binary };
                                      v_1afe9f73328d6d7bdf808b1d2eb2af22 id_3743 { id_3742(dsum1_snd_668) };
                                      v_13312187dea5608a1b10367f2c8e4e74 let_res_3744;
                                      {
                                        v_1afe9f73328d6d7bdf808b1d2eb2af22 dtup_792 { id_3743 };
                                        v_13312187dea5608a1b10367f2c8e4e74 letpair_res_3745;
                                        {
                                          auto dtup_fst_793 { std::get<0>(dtup_792) };
                                          auto dtup_snd_794 { std::get<1>(dtup_792) };
                                          v_362f9d9108a6902af48b6c83d5377ea1 id_3746 { dtup_snd_794.readU16Le() };
                                          v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_3747;
                                          {
                                            auto du16_fst_796 { std::get<0>(id_3746) };
                                            auto du16_snd_797 { std::get<1>(id_3746) };
                                            v_362f9d9108a6902af48b6c83d5377ea1 id_3748 {  du16_fst_796, du16_snd_797  };
                                            letpair_res_3747 = id_3748;
                                          }
                                          v_98c807c6ad3234380e91fff9a3df5c99 let_res_3749;
                                          {
                                            v_362f9d9108a6902af48b6c83d5377ea1 dsum1_801 { letpair_res_3747 };
                                            v_98c807c6ad3234380e91fff9a3df5c99 letpair_res_3750;
                                            {
                                              auto dsum1_fst_802 { std::get<0>(dsum1_801) };
                                              auto dsum1_snd_803 { std::get<1>(dsum1_801) };
                                              uint16_t id_3751 { 0 };
                                              bool id_3752 { bool(id_3751 == dsum1_fst_802) };
                                              v_98c807c6ad3234380e91fff9a3df5c99 choose_res_3753;
                                              if (id_3752) {
                                                b31ee7e2e15bec4cfa9176ec3d86152e id_3754 { std::in_place_index<0>, VOID };
                                                v_98c807c6ad3234380e91fff9a3df5c99 id_3755 {  id_3754, dsum1_snd_803  };
                                                choose_res_3753 = id_3755;
                                              } else {
                                                uint16_t id_3756 { 1 };
                                                bool id_3757 { bool(dsum1_fst_802 == id_3756) };
                                                Void id_3758 { ((void)(assert(id_3757)), VOID) };
                                                b31ee7e2e15bec4cfa9176ec3d86152e id_3759 { std::in_place_index<1>, VOID };
                                                v_98c807c6ad3234380e91fff9a3df5c99 id_3760 {  id_3759, dsum1_snd_803  };
                                                choose_res_3753 = id_3760;
                                              }
                                              letpair_res_3750 = choose_res_3753;
                                            }
                                            let_res_3749 = letpair_res_3750;
                                          }
                                          v_13312187dea5608a1b10367f2c8e4e74 letpair_res_3761;
                                          {
                                            auto dtup_fst_811 { std::get<0>(let_res_3749) };
                                            auto dtup_snd_812 { std::get<1>(let_res_3749) };
                                            v_562760c1b2585f63d315bb555b64832c id_3762 {  dtup_fst_793, dtup_fst_811  };
                                            v_1d6ee587a956ed7717b51cc22dd3b087 id_3763 { std::in_place_index<3>, id_3762 };
                                            v_13312187dea5608a1b10367f2c8e4e74 id_3764 {  id_3763, dtup_snd_812  };
                                            letpair_res_3761 = id_3764;
                                          }
                                          letpair_res_3745 = letpair_res_3761;
                                        }
                                        let_res_3744 = letpair_res_3745;
                                      }
                                      choose_res_3741 = let_res_3744;
                                    } else {
                                      uint16_t id_3765 { 4 };
                                      bool id_3766 { bool(id_3765 == dsum1_fst_667) };
                                      v_13312187dea5608a1b10367f2c8e4e74 choose_res_3767;
                                      if (id_3766) {
                                        v_1d6ee587a956ed7717b51cc22dd3b087 id_3768 { std::in_place_index<4>, VOID };
                                        v_13312187dea5608a1b10367f2c8e4e74 id_3769 {  id_3768, dsum1_snd_668  };
                                        choose_res_3767 = id_3769;
                                      } else {
                                        uint16_t id_3770 { 5 };
                                        bool id_3771 { bool(id_3770 == dsum1_fst_667) };
                                        v_13312187dea5608a1b10367f2c8e4e74 choose_res_3772;
                                        if (id_3771) {
                                          v_1d6ee587a956ed7717b51cc22dd3b087 id_3773 { std::in_place_index<5>, VOID };
                                          v_13312187dea5608a1b10367f2c8e4e74 id_3774 {  id_3773, dsum1_snd_668  };
                                          choose_res_3772 = id_3774;
                                        } else {
                                          uint16_t id_3775 { 6 };
                                          bool id_3776 { bool(id_3775 == dsum1_fst_667) };
                                          v_13312187dea5608a1b10367f2c8e4e74 choose_res_3777;
                                          if (id_3776) {
                                            v_1d6ee587a956ed7717b51cc22dd3b087 id_3778 { std::in_place_index<6>, VOID };
                                            v_13312187dea5608a1b10367f2c8e4e74 id_3779 {  id_3778, dsum1_snd_668  };
                                            choose_res_3777 = id_3779;
                                          } else {
                                            uint16_t id_3780 { 7 };
                                            bool id_3781 { bool(id_3780 == dsum1_fst_667) };
                                            v_13312187dea5608a1b10367f2c8e4e74 choose_res_3782;
                                            if (id_3781) {
                                              v_1d6ee587a956ed7717b51cc22dd3b087 id_3783 { std::in_place_index<7>, VOID };
                                              v_13312187dea5608a1b10367f2c8e4e74 id_3784 {  id_3783, dsum1_snd_668  };
                                              choose_res_3782 = id_3784;
                                            } else {
                                              uint16_t id_3785 { 8 };
                                              bool id_3786 { bool(id_3785 == dsum1_fst_667) };
                                              v_13312187dea5608a1b10367f2c8e4e74 choose_res_3787;
                                              if (id_3786) {
                                                v_1d6ee587a956ed7717b51cc22dd3b087 id_3788 { std::in_place_index<8>, VOID };
                                                v_13312187dea5608a1b10367f2c8e4e74 id_3789 {  id_3788, dsum1_snd_668  };
                                                choose_res_3787 = id_3789;
                                              } else {
                                                uint16_t id_3790 { 9 };
                                                bool id_3791 { bool(id_3790 == dsum1_fst_667) };
                                                v_13312187dea5608a1b10367f2c8e4e74 choose_res_3792;
                                                if (id_3791) {
                                                  v_1d6ee587a956ed7717b51cc22dd3b087 id_3793 { std::in_place_index<9>, VOID };
                                                  v_13312187dea5608a1b10367f2c8e4e74 id_3794 {  id_3793, dsum1_snd_668  };
                                                  choose_res_3792 = id_3794;
                                                } else {
                                                  uint16_t id_3795 { 10 };
                                                  bool id_3796 { bool(id_3795 == dsum1_fst_667) };
                                                  v_13312187dea5608a1b10367f2c8e4e74 choose_res_3797;
                                                  if (id_3796) {
                                                    v_1d6ee587a956ed7717b51cc22dd3b087 id_3798 { std::in_place_index<10>, VOID };
                                                    v_13312187dea5608a1b10367f2c8e4e74 id_3799 {  id_3798, dsum1_snd_668  };
                                                    choose_res_3797 = id_3799;
                                                  } else {
                                                    uint16_t id_3800 { 11 };
                                                    bool id_3801 { bool(id_3800 == dsum1_fst_667) };
                                                    v_13312187dea5608a1b10367f2c8e4e74 choose_res_3802;
                                                    if (id_3801) {
                                                      v_1d6ee587a956ed7717b51cc22dd3b087 id_3803 { std::in_place_index<11>, VOID };
                                                      v_13312187dea5608a1b10367f2c8e4e74 id_3804 {  id_3803, dsum1_snd_668  };
                                                      choose_res_3802 = id_3804;
                                                    } else {
                                                      uint16_t id_3805 { 12 };
                                                      bool id_3806 { bool(id_3805 == dsum1_fst_667) };
                                                      v_13312187dea5608a1b10367f2c8e4e74 choose_res_3807;
                                                      if (id_3806) {
                                                        v_1d6ee587a956ed7717b51cc22dd3b087 id_3808 { std::in_place_index<12>, VOID };
                                                        v_13312187dea5608a1b10367f2c8e4e74 id_3809 {  id_3808, dsum1_snd_668  };
                                                        choose_res_3807 = id_3809;
                                                      } else {
                                                        uint16_t id_3810 { 13 };
                                                        bool id_3811 { bool(id_3810 == dsum1_fst_667) };
                                                        v_13312187dea5608a1b10367f2c8e4e74 choose_res_3812;
                                                        if (id_3811) {
                                                          v_1d6ee587a956ed7717b51cc22dd3b087 id_3813 { std::in_place_index<13>, VOID };
                                                          v_13312187dea5608a1b10367f2c8e4e74 id_3814 {  id_3813, dsum1_snd_668  };
                                                          choose_res_3812 = id_3814;
                                                        } else {
                                                          uint16_t id_3815 { 14 };
                                                          bool id_3816 { bool(id_3815 == dsum1_fst_667) };
                                                          v_13312187dea5608a1b10367f2c8e4e74 choose_res_3817;
                                                          if (id_3816) {
                                                            v_1d6ee587a956ed7717b51cc22dd3b087 id_3818 { std::in_place_index<14>, VOID };
                                                            v_13312187dea5608a1b10367f2c8e4e74 id_3819 {  id_3818, dsum1_snd_668  };
                                                            choose_res_3817 = id_3819;
                                                          } else {
                                                            uint16_t id_3820 { 15 };
                                                            bool id_3821 { bool(id_3820 == dsum1_fst_667) };
                                                            v_13312187dea5608a1b10367f2c8e4e74 choose_res_3822;
                                                            if (id_3821) {
                                                              v_1d6ee587a956ed7717b51cc22dd3b087 id_3823 { std::in_place_index<15>, VOID };
                                                              v_13312187dea5608a1b10367f2c8e4e74 id_3824 {  id_3823, dsum1_snd_668  };
                                                              choose_res_3822 = id_3824;
                                                            } else {
                                                              uint16_t id_3825 { 16 };
                                                              bool id_3826 { bool(id_3825 == dsum1_fst_667) };
                                                              v_13312187dea5608a1b10367f2c8e4e74 choose_res_3827;
                                                              if (id_3826) {
                                                                v_1d6ee587a956ed7717b51cc22dd3b087 id_3828 { std::in_place_index<16>, VOID };
                                                                v_13312187dea5608a1b10367f2c8e4e74 id_3829 {  id_3828, dsum1_snd_668  };
                                                                choose_res_3827 = id_3829;
                                                              } else {
                                                                uint16_t id_3830 { 17 };
                                                                bool id_3831 { bool(id_3830 == dsum1_fst_667) };
                                                                v_13312187dea5608a1b10367f2c8e4e74 choose_res_3832;
                                                                if (id_3831) {
                                                                  v_1d6ee587a956ed7717b51cc22dd3b087 id_3833 { std::in_place_index<17>, VOID };
                                                                  v_13312187dea5608a1b10367f2c8e4e74 id_3834 {  id_3833, dsum1_snd_668  };
                                                                  choose_res_3832 = id_3834;
                                                                } else {
                                                                  uint16_t id_3835 { 18 };
                                                                  bool id_3836 { bool(id_3835 == dsum1_fst_667) };
                                                                  v_13312187dea5608a1b10367f2c8e4e74 choose_res_3837;
                                                                  if (id_3836) {
                                                                    v_1d6ee587a956ed7717b51cc22dd3b087 id_3838 { std::in_place_index<18>, VOID };
                                                                    v_13312187dea5608a1b10367f2c8e4e74 id_3839 {  id_3838, dsum1_snd_668  };
                                                                    choose_res_3837 = id_3839;
                                                                  } else {
                                                                    uint16_t id_3840 { 19 };
                                                                    bool id_3841 { bool(id_3840 == dsum1_fst_667) };
                                                                    v_13312187dea5608a1b10367f2c8e4e74 choose_res_3842;
                                                                    if (id_3841) {
                                                                      v_1d6ee587a956ed7717b51cc22dd3b087 id_3843 { std::in_place_index<19>, VOID };
                                                                      v_13312187dea5608a1b10367f2c8e4e74 id_3844 {  id_3843, dsum1_snd_668  };
                                                                      choose_res_3842 = id_3844;
                                                                    } else {
                                                                      uint16_t id_3845 { 20 };
                                                                      bool id_3846 { bool(id_3845 == dsum1_fst_667) };
                                                                      v_13312187dea5608a1b10367f2c8e4e74 choose_res_3847;
                                                                      if (id_3846) {
                                                                        v_1d6ee587a956ed7717b51cc22dd3b087 id_3848 { std::in_place_index<20>, VOID };
                                                                        v_13312187dea5608a1b10367f2c8e4e74 id_3849 {  id_3848, dsum1_snd_668  };
                                                                        choose_res_3847 = id_3849;
                                                                      } else {
                                                                        uint16_t id_3850 { 21 };
                                                                        bool id_3851 { bool(id_3850 == dsum1_fst_667) };
                                                                        v_13312187dea5608a1b10367f2c8e4e74 choose_res_3852;
                                                                        if (id_3851) {
                                                                          v_1d6ee587a956ed7717b51cc22dd3b087 id_3853 { std::in_place_index<21>, VOID };
                                                                          v_13312187dea5608a1b10367f2c8e4e74 id_3854 {  id_3853, dsum1_snd_668  };
                                                                          choose_res_3852 = id_3854;
                                                                        } else {
                                                                          uint16_t id_3855 { 22 };
                                                                          bool id_3856 { bool(id_3855 == dsum1_fst_667) };
                                                                          v_13312187dea5608a1b10367f2c8e4e74 choose_res_3857;
                                                                          if (id_3856) {
                                                                            v_1d6ee587a956ed7717b51cc22dd3b087 id_3858 { std::in_place_index<22>, VOID };
                                                                            v_13312187dea5608a1b10367f2c8e4e74 id_3859 {  id_3858, dsum1_snd_668  };
                                                                            choose_res_3857 = id_3859;
                                                                          } else {
                                                                            uint16_t id_3860 { 23 };
                                                                            bool id_3861 { bool(id_3860 == dsum1_fst_667) };
                                                                            v_13312187dea5608a1b10367f2c8e4e74 choose_res_3862;
                                                                            if (id_3861) {
                                                                              v_1d6ee587a956ed7717b51cc22dd3b087 id_3863 { std::in_place_index<23>, VOID };
                                                                              v_13312187dea5608a1b10367f2c8e4e74 id_3864 {  id_3863, dsum1_snd_668  };
                                                                              choose_res_3862 = id_3864;
                                                                            } else {
                                                                              uint16_t id_3865 { 24 };
                                                                              bool id_3866 { bool(id_3865 == dsum1_fst_667) };
                                                                              v_13312187dea5608a1b10367f2c8e4e74 choose_res_3867;
                                                                              if (id_3866) {
                                                                                v_1d6ee587a956ed7717b51cc22dd3b087 id_3868 { std::in_place_index<24>, VOID };
                                                                                v_13312187dea5608a1b10367f2c8e4e74 id_3869 {  id_3868, dsum1_snd_668  };
                                                                                choose_res_3867 = id_3869;
                                                                              } else {
                                                                                uint16_t id_3870 { 25 };
                                                                                bool id_3871 { bool(id_3870 == dsum1_fst_667) };
                                                                                v_13312187dea5608a1b10367f2c8e4e74 choose_res_3872;
                                                                                if (id_3871) {
                                                                                  v_1d6ee587a956ed7717b51cc22dd3b087 id_3873 { std::in_place_index<25>, VOID };
                                                                                  v_13312187dea5608a1b10367f2c8e4e74 id_3874 {  id_3873, dsum1_snd_668  };
                                                                                  choose_res_3872 = id_3874;
                                                                                } else {
                                                                                  uint16_t id_3875 { 26 };
                                                                                  bool id_3876 { bool(id_3875 == dsum1_fst_667) };
                                                                                  v_13312187dea5608a1b10367f2c8e4e74 choose_res_3877;
                                                                                  if (id_3876) {
                                                                                    v_1d6ee587a956ed7717b51cc22dd3b087 id_3878 { std::in_place_index<26>, VOID };
                                                                                    v_13312187dea5608a1b10367f2c8e4e74 id_3879 {  id_3878, dsum1_snd_668  };
                                                                                    choose_res_3877 = id_3879;
                                                                                  } else {
                                                                                    uint16_t id_3880 { 27 };
                                                                                    bool id_3881 { bool(id_3880 == dsum1_fst_667) };
                                                                                    v_13312187dea5608a1b10367f2c8e4e74 choose_res_3882;
                                                                                    if (id_3881) {
                                                                                      v_1d6ee587a956ed7717b51cc22dd3b087 id_3883 { std::in_place_index<27>, VOID };
                                                                                      v_13312187dea5608a1b10367f2c8e4e74 id_3884 {  id_3883, dsum1_snd_668  };
                                                                                      choose_res_3882 = id_3884;
                                                                                    } else {
                                                                                      uint16_t id_3885 { 28 };
                                                                                      bool id_3886 { bool(id_3885 == dsum1_fst_667) };
                                                                                      v_13312187dea5608a1b10367f2c8e4e74 choose_res_3887;
                                                                                      if (id_3886) {
                                                                                        v_1d6ee587a956ed7717b51cc22dd3b087 id_3888 { std::in_place_index<28>, VOID };
                                                                                        v_13312187dea5608a1b10367f2c8e4e74 id_3889 {  id_3888, dsum1_snd_668  };
                                                                                        choose_res_3887 = id_3889;
                                                                                      } else {
                                                                                        uint16_t id_3890 { 29 };
                                                                                        bool id_3891 { bool(id_3890 == dsum1_fst_667) };
                                                                                        v_13312187dea5608a1b10367f2c8e4e74 choose_res_3892;
                                                                                        if (id_3891) {
                                                                                          v_1d6ee587a956ed7717b51cc22dd3b087 id_3893 { std::in_place_index<29>, VOID };
                                                                                          v_13312187dea5608a1b10367f2c8e4e74 id_3894 {  id_3893, dsum1_snd_668  };
                                                                                          choose_res_3892 = id_3894;
                                                                                        } else {
                                                                                          uint16_t id_3895 { 30 };
                                                                                          bool id_3896 { bool(id_3895 == dsum1_fst_667) };
                                                                                          v_13312187dea5608a1b10367f2c8e4e74 choose_res_3897;
                                                                                          if (id_3896) {
                                                                                            v_1d6ee587a956ed7717b51cc22dd3b087 id_3898 { std::in_place_index<30>, VOID };
                                                                                            v_13312187dea5608a1b10367f2c8e4e74 id_3899 {  id_3898, dsum1_snd_668  };
                                                                                            choose_res_3897 = id_3899;
                                                                                          } else {
                                                                                            uint16_t id_3900 { 31 };
                                                                                            bool id_3901 { bool(id_3900 == dsum1_fst_667) };
                                                                                            v_13312187dea5608a1b10367f2c8e4e74 choose_res_3902;
                                                                                            if (id_3901) {
                                                                                              v_1d6ee587a956ed7717b51cc22dd3b087 id_3903 { std::in_place_index<31>, VOID };
                                                                                              v_13312187dea5608a1b10367f2c8e4e74 id_3904 {  id_3903, dsum1_snd_668  };
                                                                                              choose_res_3902 = id_3904;
                                                                                            } else {
                                                                                              uint16_t id_3905 { 32 };
                                                                                              bool id_3906 { bool(id_3905 == dsum1_fst_667) };
                                                                                              v_13312187dea5608a1b10367f2c8e4e74 choose_res_3907;
                                                                                              if (id_3906) {
                                                                                                v_1d6ee587a956ed7717b51cc22dd3b087 id_3908 { std::in_place_index<32>, VOID };
                                                                                                v_13312187dea5608a1b10367f2c8e4e74 id_3909 {  id_3908, dsum1_snd_668  };
                                                                                                choose_res_3907 = id_3909;
                                                                                              } else {
                                                                                                uint16_t id_3910 { 33 };
                                                                                                bool id_3911 { bool(id_3910 == dsum1_fst_667) };
                                                                                                v_13312187dea5608a1b10367f2c8e4e74 choose_res_3912;
                                                                                                if (id_3911) {
                                                                                                  v_1d6ee587a956ed7717b51cc22dd3b087 id_3913 { std::in_place_index<33>, VOID };
                                                                                                  v_13312187dea5608a1b10367f2c8e4e74 id_3914 {  id_3913, dsum1_snd_668  };
                                                                                                  choose_res_3912 = id_3914;
                                                                                                } else {
                                                                                                  uint16_t id_3915 { 34 };
                                                                                                  bool id_3916 { bool(id_3915 == dsum1_fst_667) };
                                                                                                  v_13312187dea5608a1b10367f2c8e4e74 choose_res_3917;
                                                                                                  if (id_3916) {
                                                                                                    v_1d6ee587a956ed7717b51cc22dd3b087 id_3918 { std::in_place_index<34>, VOID };
                                                                                                    v_13312187dea5608a1b10367f2c8e4e74 id_3919 {  id_3918, dsum1_snd_668  };
                                                                                                    choose_res_3917 = id_3919;
                                                                                                  } else {
                                                                                                    uint16_t id_3920 { 35 };
                                                                                                    bool id_3921 { bool(id_3920 == dsum1_fst_667) };
                                                                                                    v_13312187dea5608a1b10367f2c8e4e74 choose_res_3922;
                                                                                                    if (id_3921) {
                                                                                                      v_1d6ee587a956ed7717b51cc22dd3b087 id_3923 { std::in_place_index<35>, VOID };
                                                                                                      v_13312187dea5608a1b10367f2c8e4e74 id_3924 {  id_3923, dsum1_snd_668  };
                                                                                                      choose_res_3922 = id_3924;
                                                                                                    } else {
                                                                                                      uint16_t id_3925 { 36 };
                                                                                                      bool id_3926 { bool(id_3925 == dsum1_fst_667) };
                                                                                                      v_13312187dea5608a1b10367f2c8e4e74 choose_res_3927;
                                                                                                      if (id_3926) {
                                                                                                        uint32_t id_3928 { 0U };
                                                                                                        Vec<1, uint32_t> id_3929 {  id_3928  };
                                                                                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_3930;
                                                                                                        {
                                                                                                          Vec<1, uint32_t> leb_ref_681 { id_3929 };
                                                                                                          uint8_t id_3931 { 0 };
                                                                                                          Vec<1, uint8_t> id_3932 {  id_3931  };
                                                                                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_3933;
                                                                                                          {
                                                                                                            Vec<1, uint8_t> shft_ref_682 { id_3932 };
                                                                                                            Vec<1, Pointer> id_3934 {  dsum1_snd_668  };
                                                                                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_3935;
                                                                                                            {
                                                                                                              Vec<1, Pointer> p_ref_683 { id_3934 };
                                                                                                              bool while_flag_3936 { true };
                                                                                                              do {
                                                                                                                uint8_t id_3937 { 0 };
                                                                                                                Pointer id_3938 { p_ref_683[id_3937] };
                                                                                                                v_1d5843897434feb24d158f3793db9189 id_3939 { id_3938.readU8() };
                                                                                                                bool let_res_3940;
                                                                                                                {
                                                                                                                  v_1d5843897434feb24d158f3793db9189 leb128_684 { id_3939 };
                                                                                                                  bool letpair_res_3941;
                                                                                                                  {
                                                                                                                    auto leb128_fst_685 { std::get<0>(leb128_684) };
                                                                                                                    auto leb128_snd_686 { std::get<1>(leb128_684) };
                                                                                                                    uint8_t id_3942 { 0 };
                                                                                                                    Void id_3943 { ((void)(p_ref_683[id_3942] = leb128_snd_686), VOID) };
                                                                                                                    uint8_t id_3944 { 0 };
                                                                                                                    uint8_t id_3945 { 127 };
                                                                                                                    uint8_t id_3946 { uint8_t(leb128_fst_685 & id_3945) };
                                                                                                                    uint32_t id_3947 { uint32_t(id_3946) };
                                                                                                                    uint8_t id_3948 { 0 };
                                                                                                                    uint8_t id_3949 { shft_ref_682[id_3948] };
                                                                                                                    uint32_t id_3950 { uint32_t(id_3947 << id_3949) };
                                                                                                                    uint8_t id_3951 { 0 };
                                                                                                                    uint32_t id_3952 { leb_ref_681[id_3951] };
                                                                                                                    uint32_t id_3953 { uint32_t(id_3950 | id_3952) };
                                                                                                                    Void id_3954 { ((void)(leb_ref_681[id_3944] = id_3953), VOID) };
                                                                                                                    uint8_t id_3955 { 0 };
                                                                                                                    uint8_t id_3956 { 0 };
                                                                                                                    uint8_t id_3957 { shft_ref_682[id_3956] };
                                                                                                                    uint8_t id_3958 { 7 };
                                                                                                                    uint8_t id_3959 { uint8_t(id_3957 + id_3958) };
                                                                                                                    Void id_3960 { ((void)(shft_ref_682[id_3955] = id_3959), VOID) };
                                                                                                                    uint8_t id_3961 { 128 };
                                                                                                                    bool id_3962 { bool(leb128_fst_685 >= id_3961) };
                                                                                                                    letpair_res_3941 = id_3962;
                                                                                                                  }
                                                                                                                  let_res_3940 = letpair_res_3941;
                                                                                                                }
                                                                                                                while_flag_3936 = let_res_3940;
                                                                                                                if (while_flag_3936) {
                                                                                                                }
                                                                                                              } while (while_flag_3936);
                                                                                                              uint8_t id_3963 { 0 };
                                                                                                              uint32_t id_3964 { leb_ref_681[id_3963] };
                                                                                                              Size id_3965 { Size(id_3964) };
                                                                                                              uint8_t id_3966 { 0 };
                                                                                                              Pointer id_3967 { p_ref_683[id_3966] };
                                                                                                              v_41b0681ed7f1f185fd3e6c4dcdc13110 id_3968 {  id_3965, id_3967  };
                                                                                                              let_res_3935 = id_3968;
                                                                                                            }
                                                                                                            let_res_3933 = let_res_3935;
                                                                                                          }
                                                                                                          let_res_3930 = let_res_3933;
                                                                                                        }
                                                                                                        v_13312187dea5608a1b10367f2c8e4e74 let_res_3969;
                                                                                                        {
                                                                                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_687 { let_res_3930 };
                                                                                                          v_13312187dea5608a1b10367f2c8e4e74 letpair_res_3970;
                                                                                                          {
                                                                                                            auto dstring1_fst_688 { std::get<0>(dstring1_687) };
                                                                                                            auto dstring1_snd_689 { std::get<1>(dstring1_687) };
                                                                                                            f921d1e0a170c3c04148c21704db9c45 id_3971 { dstring1_snd_689.readBytes(dstring1_fst_688) };
                                                                                                            v_13312187dea5608a1b10367f2c8e4e74 letpair_res_3972;
                                                                                                            {
                                                                                                              auto dstring2_fst_691 { std::get<0>(id_3971) };
                                                                                                              auto dstring2_snd_692 { std::get<1>(id_3971) };
                                                                                                              std::string id_3973 { dstring2_fst_691.toString() };
                                                                                                              v_1d6ee587a956ed7717b51cc22dd3b087 id_3974 { std::in_place_index<36>, id_3973 };
                                                                                                              v_13312187dea5608a1b10367f2c8e4e74 id_3975 {  id_3974, dstring2_snd_692  };
                                                                                                              letpair_res_3972 = id_3975;
                                                                                                            }
                                                                                                            letpair_res_3970 = letpair_res_3972;
                                                                                                          }
                                                                                                          let_res_3969 = letpair_res_3970;
                                                                                                        }
                                                                                                        choose_res_3927 = let_res_3969;
                                                                                                      } else {
                                                                                                        uint16_t id_3976 { 37 };
                                                                                                        bool id_3977 { bool(id_3976 == dsum1_fst_667) };
                                                                                                        v_13312187dea5608a1b10367f2c8e4e74 choose_res_3978;
                                                                                                        if (id_3977) {
                                                                                                          v_1d6ee587a956ed7717b51cc22dd3b087 id_3979 { std::in_place_index<37>, VOID };
                                                                                                          v_13312187dea5608a1b10367f2c8e4e74 id_3980 {  id_3979, dsum1_snd_668  };
                                                                                                          choose_res_3978 = id_3980;
                                                                                                        } else {
                                                                                                          uint16_t id_3981 { 38 };
                                                                                                          bool id_3982 { bool(id_3981 == dsum1_fst_667) };
                                                                                                          v_13312187dea5608a1b10367f2c8e4e74 choose_res_3983;
                                                                                                          if (id_3982) {
                                                                                                            v_1d6ee587a956ed7717b51cc22dd3b087 id_3984 { std::in_place_index<38>, VOID };
                                                                                                            v_13312187dea5608a1b10367f2c8e4e74 id_3985 {  id_3984, dsum1_snd_668  };
                                                                                                            choose_res_3983 = id_3985;
                                                                                                          } else {
                                                                                                            uint16_t id_3986 { 39 };
                                                                                                            bool id_3987 { bool(id_3986 == dsum1_fst_667) };
                                                                                                            v_13312187dea5608a1b10367f2c8e4e74 choose_res_3988;
                                                                                                            if (id_3987) {
                                                                                                              v_1d6ee587a956ed7717b51cc22dd3b087 id_3989 { std::in_place_index<39>, VOID };
                                                                                                              v_13312187dea5608a1b10367f2c8e4e74 id_3990 {  id_3989, dsum1_snd_668  };
                                                                                                              choose_res_3988 = id_3990;
                                                                                                            } else {
                                                                                                              uint16_t id_3991 { 40 };
                                                                                                              bool id_3992 { bool(dsum1_fst_667 == id_3991) };
                                                                                                              Void id_3993 { ((void)(assert(id_3992)), VOID) };
                                                                                                              v_1d6ee587a956ed7717b51cc22dd3b087 id_3994 { std::in_place_index<40>, VOID };
                                                                                                              v_13312187dea5608a1b10367f2c8e4e74 id_3995 {  id_3994, dsum1_snd_668  };
                                                                                                              choose_res_3988 = id_3995;
                                                                                                            }
                                                                                                            choose_res_3983 = choose_res_3988;
                                                                                                          }
                                                                                                          choose_res_3978 = choose_res_3983;
                                                                                                        }
                                                                                                        choose_res_3927 = choose_res_3978;
                                                                                                      }
                                                                                                      choose_res_3922 = choose_res_3927;
                                                                                                    }
                                                                                                    choose_res_3917 = choose_res_3922;
                                                                                                  }
                                                                                                  choose_res_3912 = choose_res_3917;
                                                                                                }
                                                                                                choose_res_3907 = choose_res_3912;
                                                                                              }
                                                                                              choose_res_3902 = choose_res_3907;
                                                                                            }
                                                                                            choose_res_3897 = choose_res_3902;
                                                                                          }
                                                                                          choose_res_3892 = choose_res_3897;
                                                                                        }
                                                                                        choose_res_3887 = choose_res_3892;
                                                                                      }
                                                                                      choose_res_3882 = choose_res_3887;
                                                                                    }
                                                                                    choose_res_3877 = choose_res_3882;
                                                                                  }
                                                                                  choose_res_3872 = choose_res_3877;
                                                                                }
                                                                                choose_res_3867 = choose_res_3872;
                                                                              }
                                                                              choose_res_3862 = choose_res_3867;
                                                                            }
                                                                            choose_res_3857 = choose_res_3862;
                                                                          }
                                                                          choose_res_3852 = choose_res_3857;
                                                                        }
                                                                        choose_res_3847 = choose_res_3852;
                                                                      }
                                                                      choose_res_3842 = choose_res_3847;
                                                                    }
                                                                    choose_res_3837 = choose_res_3842;
                                                                  }
                                                                  choose_res_3832 = choose_res_3837;
                                                                }
                                                                choose_res_3827 = choose_res_3832;
                                                              }
                                                              choose_res_3822 = choose_res_3827;
                                                            }
                                                            choose_res_3817 = choose_res_3822;
                                                          }
                                                          choose_res_3812 = choose_res_3817;
                                                        }
                                                        choose_res_3807 = choose_res_3812;
                                                      }
                                                      choose_res_3802 = choose_res_3807;
                                                    }
                                                    choose_res_3797 = choose_res_3802;
                                                  }
                                                  choose_res_3792 = choose_res_3797;
                                                }
                                                choose_res_3787 = choose_res_3792;
                                              }
                                              choose_res_3782 = choose_res_3787;
                                            }
                                            choose_res_3777 = choose_res_3782;
                                          }
                                          choose_res_3772 = choose_res_3777;
                                        }
                                        choose_res_3767 = choose_res_3772;
                                      }
                                      choose_res_3741 = choose_res_3767;
                                    }
                                    choose_res_3736 = choose_res_3741;
                                  }
                                  choose_res_3728 = choose_res_3736;
                                }
                                choose_res_3723 = choose_res_3728;
                              }
                              letpair_res_3720 = choose_res_3723;
                            }
                            let_res_3719 = letpair_res_3720;
                          }
                          b1ffdd8a8f59914e8b21c924b278b478 letpair_res_3996;
                          {
                            auto dtup_fst_826 { std::get<0>(let_res_3719) };
                            auto dtup_snd_827 { std::get<1>(let_res_3719) };
                            f63f919559f0d70225bd0da5dd9bcafc id_3997 { fun3236(dtup_snd_827) };
                            b1ffdd8a8f59914e8b21c924b278b478 letpair_res_3998;
                            {
                              auto dtup_fst_829 { std::get<0>(id_3997) };
                              auto dtup_snd_830 { std::get<1>(id_3997) };
                              v_86716e60fd92843b928cbb08bc52f333 id_3999 {  dtup_fst_826, dtup_fst_829  };
                              a481e1e269544fa0efe70fc68e01b3bb id_4000 { std::in_place_index<1>, id_3999 };
                              b1ffdd8a8f59914e8b21c924b278b478 id_4001 {  id_4000, dtup_snd_830  };
                              letpair_res_3998 = id_4001;
                            }
                            letpair_res_3996 = letpair_res_3998;
                          }
                          choose_res_3715 = letpair_res_3996;
                        } else {
                          uint16_t id_4002 { 2 };
                          bool id_4003 { bool(id_4002 == dsum1_fst_476) };
                          b1ffdd8a8f59914e8b21c924b278b478 choose_res_4004;
                          if (id_4003) {
                            v_362f9d9108a6902af48b6c83d5377ea1 id_4005 { dsum1_snd_477.readU16Le() };
                            v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4006;
                            {
                              auto du16_fst_608 { std::get<0>(id_4005) };
                              auto du16_snd_609 { std::get<1>(id_4005) };
                              v_362f9d9108a6902af48b6c83d5377ea1 id_4007 {  du16_fst_608, du16_snd_609  };
                              letpair_res_4006 = id_4007;
                            }
                            v_9b45f13f89886b24a901e49d3b1f88b9 let_res_4008;
                            {
                              v_362f9d9108a6902af48b6c83d5377ea1 dsum1_613 { letpair_res_4006 };
                              v_9b45f13f89886b24a901e49d3b1f88b9 letpair_res_4009;
                              {
                                auto dsum1_fst_614 { std::get<0>(dsum1_613) };
                                auto dsum1_snd_615 { std::get<1>(dsum1_613) };
                                uint16_t id_4010 { 0 };
                                bool id_4011 { bool(id_4010 == dsum1_fst_614) };
                                v_9b45f13f89886b24a901e49d3b1f88b9 choose_res_4012;
                                if (id_4011) {
                                  v_38879d3066416481efb8a2cff1fd95bb id_4013 { std::in_place_index<0>, VOID };
                                  v_9b45f13f89886b24a901e49d3b1f88b9 id_4014 {  id_4013, dsum1_snd_615  };
                                  choose_res_4012 = id_4014;
                                } else {
                                  uint16_t id_4015 { 1 };
                                  bool id_4016 { bool(id_4015 == dsum1_fst_614) };
                                  v_9b45f13f89886b24a901e49d3b1f88b9 choose_res_4017;
                                  if (id_4016) {
                                    v_38879d3066416481efb8a2cff1fd95bb id_4018 { std::in_place_index<1>, VOID };
                                    v_9b45f13f89886b24a901e49d3b1f88b9 id_4019 {  id_4018, dsum1_snd_615  };
                                    choose_res_4017 = id_4019;
                                  } else {
                                    uint16_t id_4020 { 2 };
                                    bool id_4021 { bool(id_4020 == dsum1_fst_614) };
                                    v_9b45f13f89886b24a901e49d3b1f88b9 choose_res_4022;
                                    if (id_4021) {
                                      v_38879d3066416481efb8a2cff1fd95bb id_4023 { std::in_place_index<2>, VOID };
                                      v_9b45f13f89886b24a901e49d3b1f88b9 id_4024 {  id_4023, dsum1_snd_615  };
                                      choose_res_4022 = id_4024;
                                    } else {
                                      uint16_t id_4025 { 3 };
                                      bool id_4026 { bool(dsum1_fst_614 == id_4025) };
                                      Void id_4027 { ((void)(assert(id_4026)), VOID) };
                                      v_38879d3066416481efb8a2cff1fd95bb id_4028 { std::in_place_index<3>, VOID };
                                      v_9b45f13f89886b24a901e49d3b1f88b9 id_4029 {  id_4028, dsum1_snd_615  };
                                      choose_res_4022 = id_4029;
                                    }
                                    choose_res_4017 = choose_res_4022;
                                  }
                                  choose_res_4012 = choose_res_4017;
                                }
                                letpair_res_4009 = choose_res_4012;
                              }
                              let_res_4008 = letpair_res_4009;
                            }
                            b1ffdd8a8f59914e8b21c924b278b478 let_res_4030;
                            {
                              v_9b45f13f89886b24a901e49d3b1f88b9 dtup_628 { let_res_4008 };
                              b1ffdd8a8f59914e8b21c924b278b478 letpair_res_4031;
                              {
                                auto dtup_fst_629 { std::get<0>(dtup_628) };
                                auto dtup_snd_630 { std::get<1>(dtup_628) };
                                uint32_t id_4032 { 0U };
                                Vec<1, uint32_t> id_4033 {  id_4032  };
                                ac0fbd05039f742d2f1d9ac182e392ab let_res_4034;
                                {
                                  Vec<1, uint32_t> leb_ref_631 { id_4033 };
                                  uint8_t id_4035 { 0 };
                                  Vec<1, uint8_t> id_4036 {  id_4035  };
                                  ac0fbd05039f742d2f1d9ac182e392ab let_res_4037;
                                  {
                                    Vec<1, uint8_t> shft_ref_632 { id_4036 };
                                    Vec<1, Pointer> id_4038 {  dtup_snd_630  };
                                    ac0fbd05039f742d2f1d9ac182e392ab let_res_4039;
                                    {
                                      Vec<1, Pointer> p_ref_633 { id_4038 };
                                      bool while_flag_4040 { true };
                                      do {
                                        uint8_t id_4041 { 0 };
                                        Pointer id_4042 { p_ref_633[id_4041] };
                                        v_1d5843897434feb24d158f3793db9189 id_4043 { id_4042.readU8() };
                                        bool let_res_4044;
                                        {
                                          v_1d5843897434feb24d158f3793db9189 leb128_634 { id_4043 };
                                          bool letpair_res_4045;
                                          {
                                            auto leb128_fst_635 { std::get<0>(leb128_634) };
                                            auto leb128_snd_636 { std::get<1>(leb128_634) };
                                            uint8_t id_4046 { 0 };
                                            Void id_4047 { ((void)(p_ref_633[id_4046] = leb128_snd_636), VOID) };
                                            uint8_t id_4048 { 0 };
                                            uint8_t id_4049 { 127 };
                                            uint8_t id_4050 { uint8_t(leb128_fst_635 & id_4049) };
                                            uint32_t id_4051 { uint32_t(id_4050) };
                                            uint8_t id_4052 { 0 };
                                            uint8_t id_4053 { shft_ref_632[id_4052] };
                                            uint32_t id_4054 { uint32_t(id_4051 << id_4053) };
                                            uint8_t id_4055 { 0 };
                                            uint32_t id_4056 { leb_ref_631[id_4055] };
                                            uint32_t id_4057 { uint32_t(id_4054 | id_4056) };
                                            Void id_4058 { ((void)(leb_ref_631[id_4048] = id_4057), VOID) };
                                            uint8_t id_4059 { 0 };
                                            uint8_t id_4060 { 0 };
                                            uint8_t id_4061 { shft_ref_632[id_4060] };
                                            uint8_t id_4062 { 7 };
                                            uint8_t id_4063 { uint8_t(id_4061 + id_4062) };
                                            Void id_4064 { ((void)(shft_ref_632[id_4059] = id_4063), VOID) };
                                            uint8_t id_4065 { 128 };
                                            bool id_4066 { bool(leb128_fst_635 >= id_4065) };
                                            letpair_res_4045 = id_4066;
                                          }
                                          let_res_4044 = letpair_res_4045;
                                        }
                                        while_flag_4040 = let_res_4044;
                                        if (while_flag_4040) {
                                        }
                                      } while (while_flag_4040);
                                      uint8_t id_4067 { 0 };
                                      uint32_t id_4068 { leb_ref_631[id_4067] };
                                      uint8_t id_4069 { 0 };
                                      Pointer id_4070 { p_ref_633[id_4069] };
                                      ac0fbd05039f742d2f1d9ac182e392ab id_4071 {  id_4068, id_4070  };
                                      let_res_4039 = id_4071;
                                    }
                                    let_res_4037 = let_res_4039;
                                  }
                                  let_res_4034 = let_res_4037;
                                }
                                e8d9438e2f3a196555a010d8d14a3c3a let_res_4072;
                                {
                                  ac0fbd05039f742d2f1d9ac182e392ab dlist1_640 { let_res_4034 };
                                  e8d9438e2f3a196555a010d8d14a3c3a letpair_res_4073;
                                  {
                                    auto dlist1_fst_641 { std::get<0>(dlist1_640) };
                                    auto dlist1_snd_642 { std::get<1>(dlist1_640) };
                                    Lst<t*> endoflist_4074;
                                    e8d9438e2f3a196555a010d8d14a3c3a id_4075 {  endoflist_4074, dlist1_snd_642  };
                                    Vec<1, e8d9438e2f3a196555a010d8d14a3c3a> id_4076 {  id_4075  };
                                    e8d9438e2f3a196555a010d8d14a3c3a let_res_4077;
                                    {
                                      Vec<1, e8d9438e2f3a196555a010d8d14a3c3a> inits_src_ref_643 { id_4076 };
                                      int32_t id_4078 { 0L };
                                      Vec<1, int32_t> id_4079 {  id_4078  };
                                      {
                                        Vec<1, int32_t> repeat_n_644 { id_4079 };
                                        bool while_flag_4080 { true };
                                        do {
                                          int32_t id_4081 { int32_t(dlist1_fst_641) };
                                          uint8_t id_4082 { 0 };
                                          int32_t id_4083 { repeat_n_644[id_4082] };
                                          bool id_4084 { bool(id_4081 > id_4083) };
                                          while_flag_4080 = id_4084;
                                          if (while_flag_4080) {
                                            uint8_t id_4085 { 0 };
                                            e8d9438e2f3a196555a010d8d14a3c3a id_4086 { inits_src_ref_643[id_4085] };
                                            {
                                              e8d9438e2f3a196555a010d8d14a3c3a dlist2_645 { id_4086 };
                                              {
                                                auto dlist2_fst_646 { std::get<0>(dlist2_645) };
                                                auto dlist2_snd_647 { std::get<1>(dlist2_645) };
                                                uint8_t id_4087 { 0 };
                                                f63f919559f0d70225bd0da5dd9bcafc id_4088 { fun3236(dlist2_snd_647) };
                                                e8d9438e2f3a196555a010d8d14a3c3a letpair_res_4089;
                                                {
                                                  auto dlist3_fst_649 { std::get<0>(id_4088) };
                                                  auto dlist3_snd_650 { std::get<1>(id_4088) };
                                                  Lst<t*> id_4090 { dlist3_fst_649, dlist2_fst_646 };
                                                  e8d9438e2f3a196555a010d8d14a3c3a id_4091 {  id_4090, dlist3_snd_650  };
                                                  letpair_res_4089 = id_4091;
                                                }
                                                Void id_4092 { ((void)(inits_src_ref_643[id_4087] = letpair_res_4089), VOID) };
                                              }
                                            }
                                            uint8_t id_4093 { 0 };
                                            uint8_t id_4094 { 0 };
                                            int32_t id_4095 { repeat_n_644[id_4094] };
                                            int32_t id_4096 { 1L };
                                            int32_t id_4097 { int32_t(id_4095 + id_4096) };
                                            Void id_4098 { ((void)(repeat_n_644[id_4093] = id_4097), VOID) };
                                          }
                                        } while (while_flag_4080);
                                      }
                                      uint8_t id_4099 { 0 };
                                      e8d9438e2f3a196555a010d8d14a3c3a id_4100 { inits_src_ref_643[id_4099] };
                                      let_res_4077 = id_4100;
                                    }
                                    letpair_res_4073 = let_res_4077;
                                  }
                                  let_res_4072 = letpair_res_4073;
                                }
                                b1ffdd8a8f59914e8b21c924b278b478 letpair_res_4101;
                                {
                                  auto dlist4_fst_652 { std::get<0>(let_res_4072) };
                                  auto dlist4_snd_653 { std::get<1>(let_res_4072) };
                                  v_3b28b4928a9e27104e63a502937d8fd6 id_4102 {  dtup_fst_629, dlist4_fst_652  };
                                  a481e1e269544fa0efe70fc68e01b3bb id_4103 { std::in_place_index<2>, id_4102 };
                                  b1ffdd8a8f59914e8b21c924b278b478 id_4104 {  id_4103, dlist4_snd_653  };
                                  letpair_res_4101 = id_4104;
                                }
                                letpair_res_4031 = letpair_res_4101;
                              }
                              let_res_4030 = letpair_res_4031;
                            }
                            choose_res_4004 = let_res_4030;
                          } else {
                            uint16_t id_4105 { 3 };
                            bool id_4106 { bool(id_4105 == dsum1_fst_476) };
                            b1ffdd8a8f59914e8b21c924b278b478 choose_res_4107;
                            if (id_4106) {
                              v_362f9d9108a6902af48b6c83d5377ea1 id_4108 { dsum1_snd_477.readU16Le() };
                              v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4109;
                              {
                                auto du16_fst_509 { std::get<0>(id_4108) };
                                auto du16_snd_510 { std::get<1>(id_4108) };
                                v_362f9d9108a6902af48b6c83d5377ea1 id_4110 {  du16_fst_509, du16_snd_510  };
                                letpair_res_4109 = id_4110;
                              }
                              v_407ccfea1dff98b1bc3e1754c13cff98 let_res_4111;
                              {
                                v_362f9d9108a6902af48b6c83d5377ea1 dsum1_514 { letpair_res_4109 };
                                v_407ccfea1dff98b1bc3e1754c13cff98 letpair_res_4112;
                                {
                                  auto dsum1_fst_515 { std::get<0>(dsum1_514) };
                                  auto dsum1_snd_516 { std::get<1>(dsum1_514) };
                                  uint16_t id_4113 { 0 };
                                  bool id_4114 { bool(id_4113 == dsum1_fst_515) };
                                  v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4115;
                                  if (id_4114) {
                                    v_20bb2b786e4d41528e682385744fec03 id_4116 { std::in_place_index<0>, VOID };
                                    v_407ccfea1dff98b1bc3e1754c13cff98 id_4117 {  id_4116, dsum1_snd_516  };
                                    choose_res_4115 = id_4117;
                                  } else {
                                    uint16_t id_4118 { 1 };
                                    bool id_4119 { bool(id_4118 == dsum1_fst_515) };
                                    v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4120;
                                    if (id_4119) {
                                      v_20bb2b786e4d41528e682385744fec03 id_4121 { std::in_place_index<1>, VOID };
                                      v_407ccfea1dff98b1bc3e1754c13cff98 id_4122 {  id_4121, dsum1_snd_516  };
                                      choose_res_4120 = id_4122;
                                    } else {
                                      uint16_t id_4123 { 2 };
                                      bool id_4124 { bool(id_4123 == dsum1_fst_515) };
                                      v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4125;
                                      if (id_4124) {
                                        v_20bb2b786e4d41528e682385744fec03 id_4126 { std::in_place_index<2>, VOID };
                                        v_407ccfea1dff98b1bc3e1754c13cff98 id_4127 {  id_4126, dsum1_snd_516  };
                                        choose_res_4125 = id_4127;
                                      } else {
                                        uint16_t id_4128 { 3 };
                                        bool id_4129 { bool(id_4128 == dsum1_fst_515) };
                                        v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4130;
                                        if (id_4129) {
                                          v_20bb2b786e4d41528e682385744fec03 id_4131 { std::in_place_index<3>, VOID };
                                          v_407ccfea1dff98b1bc3e1754c13cff98 id_4132 {  id_4131, dsum1_snd_516  };
                                          choose_res_4130 = id_4132;
                                        } else {
                                          uint16_t id_4133 { 4 };
                                          bool id_4134 { bool(id_4133 == dsum1_fst_515) };
                                          v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4135;
                                          if (id_4134) {
                                            v_20bb2b786e4d41528e682385744fec03 id_4136 { std::in_place_index<4>, VOID };
                                            v_407ccfea1dff98b1bc3e1754c13cff98 id_4137 {  id_4136, dsum1_snd_516  };
                                            choose_res_4135 = id_4137;
                                          } else {
                                            uint16_t id_4138 { 5 };
                                            bool id_4139 { bool(id_4138 == dsum1_fst_515) };
                                            v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4140;
                                            if (id_4139) {
                                              v_20bb2b786e4d41528e682385744fec03 id_4141 { std::in_place_index<5>, VOID };
                                              v_407ccfea1dff98b1bc3e1754c13cff98 id_4142 {  id_4141, dsum1_snd_516  };
                                              choose_res_4140 = id_4142;
                                            } else {
                                              uint16_t id_4143 { 6 };
                                              bool id_4144 { bool(id_4143 == dsum1_fst_515) };
                                              v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4145;
                                              if (id_4144) {
                                                v_20bb2b786e4d41528e682385744fec03 id_4146 { std::in_place_index<6>, VOID };
                                                v_407ccfea1dff98b1bc3e1754c13cff98 id_4147 {  id_4146, dsum1_snd_516  };
                                                choose_res_4145 = id_4147;
                                              } else {
                                                uint16_t id_4148 { 7 };
                                                bool id_4149 { bool(id_4148 == dsum1_fst_515) };
                                                v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4150;
                                                if (id_4149) {
                                                  v_20bb2b786e4d41528e682385744fec03 id_4151 { std::in_place_index<7>, VOID };
                                                  v_407ccfea1dff98b1bc3e1754c13cff98 id_4152 {  id_4151, dsum1_snd_516  };
                                                  choose_res_4150 = id_4152;
                                                } else {
                                                  uint16_t id_4153 { 8 };
                                                  bool id_4154 { bool(id_4153 == dsum1_fst_515) };
                                                  v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4155;
                                                  if (id_4154) {
                                                    v_20bb2b786e4d41528e682385744fec03 id_4156 { std::in_place_index<8>, VOID };
                                                    v_407ccfea1dff98b1bc3e1754c13cff98 id_4157 {  id_4156, dsum1_snd_516  };
                                                    choose_res_4155 = id_4157;
                                                  } else {
                                                    uint16_t id_4158 { 9 };
                                                    bool id_4159 { bool(id_4158 == dsum1_fst_515) };
                                                    v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4160;
                                                    if (id_4159) {
                                                      v_20bb2b786e4d41528e682385744fec03 id_4161 { std::in_place_index<9>, VOID };
                                                      v_407ccfea1dff98b1bc3e1754c13cff98 id_4162 {  id_4161, dsum1_snd_516  };
                                                      choose_res_4160 = id_4162;
                                                    } else {
                                                      uint16_t id_4163 { 10 };
                                                      bool id_4164 { bool(id_4163 == dsum1_fst_515) };
                                                      v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4165;
                                                      if (id_4164) {
                                                        v_20bb2b786e4d41528e682385744fec03 id_4166 { std::in_place_index<10>, VOID };
                                                        v_407ccfea1dff98b1bc3e1754c13cff98 id_4167 {  id_4166, dsum1_snd_516  };
                                                        choose_res_4165 = id_4167;
                                                      } else {
                                                        uint16_t id_4168 { 11 };
                                                        bool id_4169 { bool(id_4168 == dsum1_fst_515) };
                                                        v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4170;
                                                        if (id_4169) {
                                                          v_20bb2b786e4d41528e682385744fec03 id_4171 { std::in_place_index<11>, VOID };
                                                          v_407ccfea1dff98b1bc3e1754c13cff98 id_4172 {  id_4171, dsum1_snd_516  };
                                                          choose_res_4170 = id_4172;
                                                        } else {
                                                          uint16_t id_4173 { 12 };
                                                          bool id_4174 { bool(id_4173 == dsum1_fst_515) };
                                                          v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4175;
                                                          if (id_4174) {
                                                            v_20bb2b786e4d41528e682385744fec03 id_4176 { std::in_place_index<12>, VOID };
                                                            v_407ccfea1dff98b1bc3e1754c13cff98 id_4177 {  id_4176, dsum1_snd_516  };
                                                            choose_res_4175 = id_4177;
                                                          } else {
                                                            uint16_t id_4178 { 13 };
                                                            bool id_4179 { bool(id_4178 == dsum1_fst_515) };
                                                            v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4180;
                                                            if (id_4179) {
                                                              v_20bb2b786e4d41528e682385744fec03 id_4181 { std::in_place_index<13>, VOID };
                                                              v_407ccfea1dff98b1bc3e1754c13cff98 id_4182 {  id_4181, dsum1_snd_516  };
                                                              choose_res_4180 = id_4182;
                                                            } else {
                                                              uint16_t id_4183 { 14 };
                                                              bool id_4184 { bool(id_4183 == dsum1_fst_515) };
                                                              v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4185;
                                                              if (id_4184) {
                                                                v_20bb2b786e4d41528e682385744fec03 id_4186 { std::in_place_index<14>, VOID };
                                                                v_407ccfea1dff98b1bc3e1754c13cff98 id_4187 {  id_4186, dsum1_snd_516  };
                                                                choose_res_4185 = id_4187;
                                                              } else {
                                                                uint16_t id_4188 { 15 };
                                                                bool id_4189 { bool(id_4188 == dsum1_fst_515) };
                                                                v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4190;
                                                                if (id_4189) {
                                                                  v_20bb2b786e4d41528e682385744fec03 id_4191 { std::in_place_index<15>, VOID };
                                                                  v_407ccfea1dff98b1bc3e1754c13cff98 id_4192 {  id_4191, dsum1_snd_516  };
                                                                  choose_res_4190 = id_4192;
                                                                } else {
                                                                  uint16_t id_4193 { 16 };
                                                                  bool id_4194 { bool(id_4193 == dsum1_fst_515) };
                                                                  v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4195;
                                                                  if (id_4194) {
                                                                    v_20bb2b786e4d41528e682385744fec03 id_4196 { std::in_place_index<16>, VOID };
                                                                    v_407ccfea1dff98b1bc3e1754c13cff98 id_4197 {  id_4196, dsum1_snd_516  };
                                                                    choose_res_4195 = id_4197;
                                                                  } else {
                                                                    uint16_t id_4198 { 17 };
                                                                    bool id_4199 { bool(id_4198 == dsum1_fst_515) };
                                                                    v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4200;
                                                                    if (id_4199) {
                                                                      v_20bb2b786e4d41528e682385744fec03 id_4201 { std::in_place_index<17>, VOID };
                                                                      v_407ccfea1dff98b1bc3e1754c13cff98 id_4202 {  id_4201, dsum1_snd_516  };
                                                                      choose_res_4200 = id_4202;
                                                                    } else {
                                                                      uint16_t id_4203 { 18 };
                                                                      bool id_4204 { bool(id_4203 == dsum1_fst_515) };
                                                                      v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4205;
                                                                      if (id_4204) {
                                                                        v_20bb2b786e4d41528e682385744fec03 id_4206 { std::in_place_index<18>, VOID };
                                                                        v_407ccfea1dff98b1bc3e1754c13cff98 id_4207 {  id_4206, dsum1_snd_516  };
                                                                        choose_res_4205 = id_4207;
                                                                      } else {
                                                                        uint16_t id_4208 { 19 };
                                                                        bool id_4209 { bool(id_4208 == dsum1_fst_515) };
                                                                        v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4210;
                                                                        if (id_4209) {
                                                                          v_20bb2b786e4d41528e682385744fec03 id_4211 { std::in_place_index<19>, VOID };
                                                                          v_407ccfea1dff98b1bc3e1754c13cff98 id_4212 {  id_4211, dsum1_snd_516  };
                                                                          choose_res_4210 = id_4212;
                                                                        } else {
                                                                          uint16_t id_4213 { 20 };
                                                                          bool id_4214 { bool(id_4213 == dsum1_fst_515) };
                                                                          v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4215;
                                                                          if (id_4214) {
                                                                            v_20bb2b786e4d41528e682385744fec03 id_4216 { std::in_place_index<20>, VOID };
                                                                            v_407ccfea1dff98b1bc3e1754c13cff98 id_4217 {  id_4216, dsum1_snd_516  };
                                                                            choose_res_4215 = id_4217;
                                                                          } else {
                                                                            uint16_t id_4218 { 21 };
                                                                            bool id_4219 { bool(id_4218 == dsum1_fst_515) };
                                                                            v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4220;
                                                                            if (id_4219) {
                                                                              v_20bb2b786e4d41528e682385744fec03 id_4221 { std::in_place_index<21>, VOID };
                                                                              v_407ccfea1dff98b1bc3e1754c13cff98 id_4222 {  id_4221, dsum1_snd_516  };
                                                                              choose_res_4220 = id_4222;
                                                                            } else {
                                                                              uint16_t id_4223 { 22 };
                                                                              bool id_4224 { bool(id_4223 == dsum1_fst_515) };
                                                                              v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4225;
                                                                              if (id_4224) {
                                                                                v_20bb2b786e4d41528e682385744fec03 id_4226 { std::in_place_index<22>, VOID };
                                                                                v_407ccfea1dff98b1bc3e1754c13cff98 id_4227 {  id_4226, dsum1_snd_516  };
                                                                                choose_res_4225 = id_4227;
                                                                              } else {
                                                                                uint16_t id_4228 { 23 };
                                                                                bool id_4229 { bool(id_4228 == dsum1_fst_515) };
                                                                                v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4230;
                                                                                if (id_4229) {
                                                                                  v_20bb2b786e4d41528e682385744fec03 id_4231 { std::in_place_index<23>, VOID };
                                                                                  v_407ccfea1dff98b1bc3e1754c13cff98 id_4232 {  id_4231, dsum1_snd_516  };
                                                                                  choose_res_4230 = id_4232;
                                                                                } else {
                                                                                  uint16_t id_4233 { 24 };
                                                                                  bool id_4234 { bool(id_4233 == dsum1_fst_515) };
                                                                                  v_407ccfea1dff98b1bc3e1754c13cff98 choose_res_4235;
                                                                                  if (id_4234) {
                                                                                    v_20bb2b786e4d41528e682385744fec03 id_4236 { std::in_place_index<24>, VOID };
                                                                                    v_407ccfea1dff98b1bc3e1754c13cff98 id_4237 {  id_4236, dsum1_snd_516  };
                                                                                    choose_res_4235 = id_4237;
                                                                                  } else {
                                                                                    uint16_t id_4238 { 25 };
                                                                                    bool id_4239 { bool(dsum1_fst_515 == id_4238) };
                                                                                    Void id_4240 { ((void)(assert(id_4239)), VOID) };
                                                                                    v_20bb2b786e4d41528e682385744fec03 id_4241 { std::in_place_index<25>, VOID };
                                                                                    v_407ccfea1dff98b1bc3e1754c13cff98 id_4242 {  id_4241, dsum1_snd_516  };
                                                                                    choose_res_4235 = id_4242;
                                                                                  }
                                                                                  choose_res_4230 = choose_res_4235;
                                                                                }
                                                                                choose_res_4225 = choose_res_4230;
                                                                              }
                                                                              choose_res_4220 = choose_res_4225;
                                                                            }
                                                                            choose_res_4215 = choose_res_4220;
                                                                          }
                                                                          choose_res_4210 = choose_res_4215;
                                                                        }
                                                                        choose_res_4205 = choose_res_4210;
                                                                      }
                                                                      choose_res_4200 = choose_res_4205;
                                                                    }
                                                                    choose_res_4195 = choose_res_4200;
                                                                  }
                                                                  choose_res_4190 = choose_res_4195;
                                                                }
                                                                choose_res_4185 = choose_res_4190;
                                                              }
                                                              choose_res_4180 = choose_res_4185;
                                                            }
                                                            choose_res_4175 = choose_res_4180;
                                                          }
                                                          choose_res_4170 = choose_res_4175;
                                                        }
                                                        choose_res_4165 = choose_res_4170;
                                                      }
                                                      choose_res_4160 = choose_res_4165;
                                                    }
                                                    choose_res_4155 = choose_res_4160;
                                                  }
                                                  choose_res_4150 = choose_res_4155;
                                                }
                                                choose_res_4145 = choose_res_4150;
                                              }
                                              choose_res_4140 = choose_res_4145;
                                            }
                                            choose_res_4135 = choose_res_4140;
                                          }
                                          choose_res_4130 = choose_res_4135;
                                        }
                                        choose_res_4125 = choose_res_4130;
                                      }
                                      choose_res_4120 = choose_res_4125;
                                    }
                                    choose_res_4115 = choose_res_4120;
                                  }
                                  letpair_res_4112 = choose_res_4115;
                                }
                                let_res_4111 = letpair_res_4112;
                              }
                              b1ffdd8a8f59914e8b21c924b278b478 letpair_res_4243;
                              {
                                auto dtup_fst_596 { std::get<0>(let_res_4111) };
                                auto dtup_snd_597 { std::get<1>(let_res_4111) };
                                f63f919559f0d70225bd0da5dd9bcafc id_4244 { fun3236(dtup_snd_597) };
                                b1ffdd8a8f59914e8b21c924b278b478 letpair_res_4245;
                                {
                                  auto dtup_fst_599 { std::get<0>(id_4244) };
                                  auto dtup_snd_600 { std::get<1>(id_4244) };
                                  f63f919559f0d70225bd0da5dd9bcafc id_4246 { fun3236(dtup_snd_600) };
                                  b1ffdd8a8f59914e8b21c924b278b478 letpair_res_4247;
                                  {
                                    auto dtup_fst_602 { std::get<0>(id_4246) };
                                    auto dtup_snd_603 { std::get<1>(id_4246) };
                                    v_8987bf3ba5adfaa68384b9fde66ab651 id_4248 {  dtup_fst_596, dtup_fst_599, dtup_fst_602  };
                                    a481e1e269544fa0efe70fc68e01b3bb id_4249 { std::in_place_index<3>, id_4248 };
                                    b1ffdd8a8f59914e8b21c924b278b478 id_4250 {  id_4249, dtup_snd_603  };
                                    letpair_res_4247 = id_4250;
                                  }
                                  letpair_res_4245 = letpair_res_4247;
                                }
                                letpair_res_4243 = letpair_res_4245;
                              }
                              choose_res_4107 = letpair_res_4243;
                            } else {
                              uint16_t id_4251 { 4 };
                              bool id_4252 { bool(dsum1_fst_476 == id_4251) };
                              Void id_4253 { ((void)(assert(id_4252)), VOID) };
                              v_362f9d9108a6902af48b6c83d5377ea1 id_4254 { dsum1_snd_477.readU16Le() };
                              v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4255;
                              {
                                auto du16_fst_479 { std::get<0>(id_4254) };
                                auto du16_snd_480 { std::get<1>(id_4254) };
                                v_362f9d9108a6902af48b6c83d5377ea1 id_4256 {  du16_fst_479, du16_snd_480  };
                                letpair_res_4255 = id_4256;
                              }
                              v_10a2bfff0e71a34103d9ba64b2a811ea let_res_4257;
                              {
                                v_362f9d9108a6902af48b6c83d5377ea1 dsum1_484 { letpair_res_4255 };
                                v_10a2bfff0e71a34103d9ba64b2a811ea letpair_res_4258;
                                {
                                  auto dsum1_fst_485 { std::get<0>(dsum1_484) };
                                  auto dsum1_snd_486 { std::get<1>(dsum1_484) };
                                  uint16_t id_4259 { 0 };
                                  bool id_4260 { bool(id_4259 == dsum1_fst_485) };
                                  v_10a2bfff0e71a34103d9ba64b2a811ea choose_res_4261;
                                  if (id_4260) {
                                    v_4b68f284ffe696cb6936ca2f6880b08a id_4262 { std::in_place_index<0>, VOID };
                                    v_10a2bfff0e71a34103d9ba64b2a811ea id_4263 {  id_4262, dsum1_snd_486  };
                                    choose_res_4261 = id_4263;
                                  } else {
                                    uint16_t id_4264 { 1 };
                                    bool id_4265 { bool(dsum1_fst_485 == id_4264) };
                                    Void id_4266 { ((void)(assert(id_4265)), VOID) };
                                    v_4b68f284ffe696cb6936ca2f6880b08a id_4267 { std::in_place_index<1>, VOID };
                                    v_10a2bfff0e71a34103d9ba64b2a811ea id_4268 {  id_4267, dsum1_snd_486  };
                                    choose_res_4261 = id_4268;
                                  }
                                  letpair_res_4258 = choose_res_4261;
                                }
                                let_res_4257 = letpair_res_4258;
                              }
                              b1ffdd8a8f59914e8b21c924b278b478 letpair_res_4269;
                              {
                                auto dtup_fst_494 { std::get<0>(let_res_4257) };
                                auto dtup_snd_495 { std::get<1>(let_res_4257) };
                                f63f919559f0d70225bd0da5dd9bcafc id_4270 { fun3236(dtup_snd_495) };
                                b1ffdd8a8f59914e8b21c924b278b478 letpair_res_4271;
                                {
                                  auto dtup_fst_497 { std::get<0>(id_4270) };
                                  auto dtup_snd_498 { std::get<1>(id_4270) };
                                  f63f919559f0d70225bd0da5dd9bcafc id_4272 { fun3236(dtup_snd_498) };
                                  b1ffdd8a8f59914e8b21c924b278b478 letpair_res_4273;
                                  {
                                    auto dtup_fst_500 { std::get<0>(id_4272) };
                                    auto dtup_snd_501 { std::get<1>(id_4272) };
                                    f63f919559f0d70225bd0da5dd9bcafc id_4274 { fun3236(dtup_snd_501) };
                                    b1ffdd8a8f59914e8b21c924b278b478 letpair_res_4275;
                                    {
                                      auto dtup_fst_503 { std::get<0>(id_4274) };
                                      auto dtup_snd_504 { std::get<1>(id_4274) };
                                      v_3d59f26fb89fa3ef8dc792c2f4609b32 id_4276 {  dtup_fst_494, dtup_fst_497, dtup_fst_500, dtup_fst_503  };
                                      a481e1e269544fa0efe70fc68e01b3bb id_4277 { std::in_place_index<4>, id_4276 };
                                      b1ffdd8a8f59914e8b21c924b278b478 id_4278 {  id_4277, dtup_snd_504  };
                                      letpair_res_4275 = id_4278;
                                    }
                                    letpair_res_4273 = letpair_res_4275;
                                  }
                                  letpair_res_4271 = letpair_res_4273;
                                }
                                letpair_res_4269 = letpair_res_4271;
                              }
                              choose_res_4107 = letpair_res_4269;
                            }
                            choose_res_4004 = choose_res_4107;
                          }
                          choose_res_3715 = choose_res_4004;
                        }
                        choose_res_3579 = choose_res_3715;
                      }
                      letpair_res_3576 = choose_res_3579;
                    }
                    let_res_3575 = letpair_res_3576;
                  }
                  f05619a6958568f0d4db38b191811dc1 letpair_res_4279;
                  {
                    auto dsum2_fst_897 { std::get<0>(let_res_3575) };
                    auto dsum2_snd_898 { std::get<1>(let_res_3575) };
                    dc31f5cc689133a6f12d16478388e785 id_4280 { std::in_place_index<4>, dsum2_fst_897 };
                    f05619a6958568f0d4db38b191811dc1 id_4281 {  id_4280, dsum2_snd_898  };
                    letpair_res_4279 = id_4281;
                  }
                  choose_res_3571 = letpair_res_4279;
                } else {
                  uint16_t id_4282 { 5 };
                  bool id_4283 { bool(id_4282 == dsum1_fst_63) };
                  f05619a6958568f0d4db38b191811dc1 choose_res_4284;
                  if (id_4283) {
                    v_362f9d9108a6902af48b6c83d5377ea1 id_4285 { dsum1_snd_64.readU16Le() };
                    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4286;
                    {
                      auto du16_fst_87 { std::get<0>(id_4285) };
                      auto du16_snd_88 { std::get<1>(id_4285) };
                      v_362f9d9108a6902af48b6c83d5377ea1 id_4287 {  du16_fst_87, du16_snd_88  };
                      letpair_res_4286 = id_4287;
                    }
                    v_3e1a490698d382316a95f8c9ebeef293 let_res_4288;
                    {
                      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_92 { letpair_res_4286 };
                      v_3e1a490698d382316a95f8c9ebeef293 letpair_res_4289;
                      {
                        auto dsum1_fst_93 { std::get<0>(dsum1_92) };
                        auto dsum1_snd_94 { std::get<1>(dsum1_92) };
                        uint16_t id_4290 { 0 };
                        bool id_4291 { bool(id_4290 == dsum1_fst_93) };
                        v_3e1a490698d382316a95f8c9ebeef293 choose_res_4292;
                        if (id_4291) {
                          d9442fc1deb39566ea1af2c5bee72a1c id_4293 { std::in_place_index<0>, VOID };
                          v_3e1a490698d382316a95f8c9ebeef293 id_4294 {  id_4293, dsum1_snd_94  };
                          choose_res_4292 = id_4294;
                        } else {
                          uint16_t id_4295 { 1 };
                          bool id_4296 { bool(dsum1_fst_93 == id_4295) };
                          Void id_4297 { ((void)(assert(id_4296)), VOID) };
                          d9442fc1deb39566ea1af2c5bee72a1c id_4298 { std::in_place_index<1>, VOID };
                          v_3e1a490698d382316a95f8c9ebeef293 id_4299 {  id_4298, dsum1_snd_94  };
                          choose_res_4292 = id_4299;
                        }
                        letpair_res_4289 = choose_res_4292;
                      }
                      let_res_4288 = letpair_res_4289;
                    }
                    f05619a6958568f0d4db38b191811dc1 let_res_4300;
                    {
                      v_3e1a490698d382316a95f8c9ebeef293 dtup_101 { let_res_4288 };
                      f05619a6958568f0d4db38b191811dc1 letpair_res_4301;
                      {
                        auto dtup_fst_102 { std::get<0>(dtup_101) };
                        auto dtup_snd_103 { std::get<1>(dtup_101) };
                        v_1d5843897434feb24d158f3793db9189 id_4302 { dtup_snd_103.readU8() };
                        f2a48a42f9c827f487e53ee52a4e9e2f letpair_res_4303;
                        {
                          auto dbool_fst_105 { std::get<0>(id_4302) };
                          auto dbool_snd_106 { std::get<1>(id_4302) };
                          uint8_t id_4304 { 0 };
                          bool id_4305 { bool(dbool_fst_105 == id_4304) };
                          bool id_4306 { ! id_4305 };
                          f2a48a42f9c827f487e53ee52a4e9e2f id_4307 {  id_4306, dbool_snd_106  };
                          letpair_res_4303 = id_4307;
                        }
                        f05619a6958568f0d4db38b191811dc1 let_res_4308;
                        {
                          f2a48a42f9c827f487e53ee52a4e9e2f dtup_107 { letpair_res_4303 };
                          f05619a6958568f0d4db38b191811dc1 letpair_res_4309;
                          {
                            auto dtup_fst_108 { std::get<0>(dtup_107) };
                            auto dtup_snd_109 { std::get<1>(dtup_107) };
                            v_362f9d9108a6902af48b6c83d5377ea1 id_4310 { dtup_snd_109.readU16Le() };
                            v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4311;
                            {
                              auto du16_fst_111 { std::get<0>(id_4310) };
                              auto du16_snd_112 { std::get<1>(id_4310) };
                              v_362f9d9108a6902af48b6c83d5377ea1 id_4312 {  du16_fst_111, du16_snd_112  };
                              letpair_res_4311 = id_4312;
                            }
                            v_9f6c76bf140d94510c6437dee417ba9f let_res_4313;
                            {
                              v_362f9d9108a6902af48b6c83d5377ea1 dsum1_116 { letpair_res_4311 };
                              v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4314;
                              {
                                auto dsum1_fst_117 { std::get<0>(dsum1_116) };
                                auto dsum1_snd_118 { std::get<1>(dsum1_116) };
                                uint16_t id_4315 { 0 };
                                bool id_4316 { bool(id_4315 == dsum1_fst_117) };
                                v_9f6c76bf140d94510c6437dee417ba9f choose_res_4317;
                                if (id_4316) {
                                  v_362f9d9108a6902af48b6c83d5377ea1 id_4318 { dsum1_snd_118.readU16Le() };
                                  v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4319;
                                  {
                                    auto du16_fst_383 { std::get<0>(id_4318) };
                                    auto du16_snd_384 { std::get<1>(id_4318) };
                                    v_362f9d9108a6902af48b6c83d5377ea1 id_4320 {  du16_fst_383, du16_snd_384  };
                                    letpair_res_4319 = id_4320;
                                  }
                                  c0d7f0e7f711b7617e3f34692ada98f5 let_res_4321;
                                  {
                                    v_362f9d9108a6902af48b6c83d5377ea1 dsum1_388 { letpair_res_4319 };
                                    c0d7f0e7f711b7617e3f34692ada98f5 letpair_res_4322;
                                    {
                                      auto dsum1_fst_389 { std::get<0>(dsum1_388) };
                                      auto dsum1_snd_390 { std::get<1>(dsum1_388) };
                                      uint16_t id_4323 { 0 };
                                      bool id_4324 { bool(id_4323 == dsum1_fst_389) };
                                      c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4325;
                                      if (id_4324) {
                                        v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4326 { std::in_place_index<0>, VOID };
                                        c0d7f0e7f711b7617e3f34692ada98f5 id_4327 {  id_4326, dsum1_snd_390  };
                                        choose_res_4325 = id_4327;
                                      } else {
                                        uint16_t id_4328 { 1 };
                                        bool id_4329 { bool(id_4328 == dsum1_fst_389) };
                                        c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4330;
                                        if (id_4329) {
                                          v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4331 { std::in_place_index<1>, VOID };
                                          c0d7f0e7f711b7617e3f34692ada98f5 id_4332 {  id_4331, dsum1_snd_390  };
                                          choose_res_4330 = id_4332;
                                        } else {
                                          uint16_t id_4333 { 2 };
                                          bool id_4334 { bool(id_4333 == dsum1_fst_389) };
                                          c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4335;
                                          if (id_4334) {
                                            v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4336 { std::in_place_index<2>, VOID };
                                            c0d7f0e7f711b7617e3f34692ada98f5 id_4337 {  id_4336, dsum1_snd_390  };
                                            choose_res_4335 = id_4337;
                                          } else {
                                            uint16_t id_4338 { 3 };
                                            bool id_4339 { bool(id_4338 == dsum1_fst_389) };
                                            c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4340;
                                            if (id_4339) {
                                              v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4341 { std::in_place_index<3>, VOID };
                                              c0d7f0e7f711b7617e3f34692ada98f5 id_4342 {  id_4341, dsum1_snd_390  };
                                              choose_res_4340 = id_4342;
                                            } else {
                                              uint16_t id_4343 { 4 };
                                              bool id_4344 { bool(id_4343 == dsum1_fst_389) };
                                              c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4345;
                                              if (id_4344) {
                                                v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4346 { std::in_place_index<4>, VOID };
                                                c0d7f0e7f711b7617e3f34692ada98f5 id_4347 {  id_4346, dsum1_snd_390  };
                                                choose_res_4345 = id_4347;
                                              } else {
                                                uint16_t id_4348 { 5 };
                                                bool id_4349 { bool(id_4348 == dsum1_fst_389) };
                                                c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4350;
                                                if (id_4349) {
                                                  v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4351 { std::in_place_index<5>, VOID };
                                                  c0d7f0e7f711b7617e3f34692ada98f5 id_4352 {  id_4351, dsum1_snd_390  };
                                                  choose_res_4350 = id_4352;
                                                } else {
                                                  uint16_t id_4353 { 6 };
                                                  bool id_4354 { bool(id_4353 == dsum1_fst_389) };
                                                  c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4355;
                                                  if (id_4354) {
                                                    v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4356 { std::in_place_index<6>, VOID };
                                                    c0d7f0e7f711b7617e3f34692ada98f5 id_4357 {  id_4356, dsum1_snd_390  };
                                                    choose_res_4355 = id_4357;
                                                  } else {
                                                    uint16_t id_4358 { 7 };
                                                    bool id_4359 { bool(id_4358 == dsum1_fst_389) };
                                                    c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4360;
                                                    if (id_4359) {
                                                      v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4361 { std::in_place_index<7>, VOID };
                                                      c0d7f0e7f711b7617e3f34692ada98f5 id_4362 {  id_4361, dsum1_snd_390  };
                                                      choose_res_4360 = id_4362;
                                                    } else {
                                                      uint16_t id_4363 { 8 };
                                                      bool id_4364 { bool(id_4363 == dsum1_fst_389) };
                                                      c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4365;
                                                      if (id_4364) {
                                                        v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4366 { std::in_place_index<8>, VOID };
                                                        c0d7f0e7f711b7617e3f34692ada98f5 id_4367 {  id_4366, dsum1_snd_390  };
                                                        choose_res_4365 = id_4367;
                                                      } else {
                                                        uint16_t id_4368 { 9 };
                                                        bool id_4369 { bool(id_4368 == dsum1_fst_389) };
                                                        c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4370;
                                                        if (id_4369) {
                                                          v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4371 { std::in_place_index<9>, VOID };
                                                          c0d7f0e7f711b7617e3f34692ada98f5 id_4372 {  id_4371, dsum1_snd_390  };
                                                          choose_res_4370 = id_4372;
                                                        } else {
                                                          uint16_t id_4373 { 10 };
                                                          bool id_4374 { bool(id_4373 == dsum1_fst_389) };
                                                          c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4375;
                                                          if (id_4374) {
                                                            v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4376 { std::in_place_index<10>, VOID };
                                                            c0d7f0e7f711b7617e3f34692ada98f5 id_4377 {  id_4376, dsum1_snd_390  };
                                                            choose_res_4375 = id_4377;
                                                          } else {
                                                            uint16_t id_4378 { 11 };
                                                            bool id_4379 { bool(id_4378 == dsum1_fst_389) };
                                                            c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4380;
                                                            if (id_4379) {
                                                              b62e103e7915a76f45f02f7c6f667c79 id_4381 { dsum1_snd_390.readU64Le() };
                                                              v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_4382;
                                                              {
                                                                auto dfloat_fst_401 { std::get<0>(id_4381) };
                                                                auto dfloat_snd_402 { std::get<1>(id_4381) };
                                                                double id_4383 { float_of_qword(dfloat_fst_401) };
                                                                v_41a5a8cf414de9bfdc6375241fcc910a id_4384 {  id_4383, dfloat_snd_402  };
                                                                letpair_res_4382 = id_4384;
                                                              }
                                                              c0d7f0e7f711b7617e3f34692ada98f5 let_res_4385;
                                                              {
                                                                v_41a5a8cf414de9bfdc6375241fcc910a dtup_403 { letpair_res_4382 };
                                                                c0d7f0e7f711b7617e3f34692ada98f5 letpair_res_4386;
                                                                {
                                                                  auto dtup_fst_404 { std::get<0>(dtup_403) };
                                                                  auto dtup_snd_405 { std::get<1>(dtup_403) };
                                                                  b62e103e7915a76f45f02f7c6f667c79 id_4387 { dtup_snd_405.readU64Le() };
                                                                  v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_4388;
                                                                  {
                                                                    auto dfloat_fst_407 { std::get<0>(id_4387) };
                                                                    auto dfloat_snd_408 { std::get<1>(id_4387) };
                                                                    double id_4389 { float_of_qword(dfloat_fst_407) };
                                                                    v_41a5a8cf414de9bfdc6375241fcc910a id_4390 {  id_4389, dfloat_snd_408  };
                                                                    letpair_res_4388 = id_4390;
                                                                  }
                                                                  c0d7f0e7f711b7617e3f34692ada98f5 let_res_4391;
                                                                  {
                                                                    v_41a5a8cf414de9bfdc6375241fcc910a dtup_409 { letpair_res_4388 };
                                                                    c0d7f0e7f711b7617e3f34692ada98f5 letpair_res_4392;
                                                                    {
                                                                      auto dtup_fst_410 { std::get<0>(dtup_409) };
                                                                      auto dtup_snd_411 { std::get<1>(dtup_409) };
                                                                      ac0fbd05039f742d2f1d9ac182e392ab id_4393 { dtup_snd_411.readU32Le() };
                                                                      c0d7f0e7f711b7617e3f34692ada98f5 letpair_res_4394;
                                                                      {
                                                                        auto du32_fst_413 { std::get<0>(id_4393) };
                                                                        auto du32_snd_414 { std::get<1>(id_4393) };
                                                                        ff127e01aa6516985aeb6ae62f964e8f id_4395 {  dtup_fst_404, dtup_fst_410, du32_fst_413  };
                                                                        v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4396 { std::in_place_index<11>, id_4395 };
                                                                        c0d7f0e7f711b7617e3f34692ada98f5 id_4397 {  id_4396, du32_snd_414  };
                                                                        letpair_res_4394 = id_4397;
                                                                      }
                                                                      letpair_res_4392 = letpair_res_4394;
                                                                    }
                                                                    let_res_4391 = letpair_res_4392;
                                                                  }
                                                                  letpair_res_4386 = let_res_4391;
                                                                }
                                                                let_res_4385 = letpair_res_4386;
                                                              }
                                                              choose_res_4380 = let_res_4385;
                                                            } else {
                                                              uint16_t id_4398 { 12 };
                                                              bool id_4399 { bool(id_4398 == dsum1_fst_389) };
                                                              c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4400;
                                                              if (id_4399) {
                                                                v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4401 { std::in_place_index<12>, VOID };
                                                                c0d7f0e7f711b7617e3f34692ada98f5 id_4402 {  id_4401, dsum1_snd_390  };
                                                                choose_res_4400 = id_4402;
                                                              } else {
                                                                uint16_t id_4403 { 13 };
                                                                bool id_4404 { bool(id_4403 == dsum1_fst_389) };
                                                                c0d7f0e7f711b7617e3f34692ada98f5 choose_res_4405;
                                                                if (id_4404) {
                                                                  v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4406 { std::in_place_index<13>, VOID };
                                                                  c0d7f0e7f711b7617e3f34692ada98f5 id_4407 {  id_4406, dsum1_snd_390  };
                                                                  choose_res_4405 = id_4407;
                                                                } else {
                                                                  uint16_t id_4408 { 14 };
                                                                  bool id_4409 { bool(dsum1_fst_389 == id_4408) };
                                                                  Void id_4410 { ((void)(assert(id_4409)), VOID) };
                                                                  v_04da9e7d4c0ea0d028b50b2b2bf068b2 id_4411 { std::in_place_index<14>, VOID };
                                                                  c0d7f0e7f711b7617e3f34692ada98f5 id_4412 {  id_4411, dsum1_snd_390  };
                                                                  choose_res_4405 = id_4412;
                                                                }
                                                                choose_res_4400 = choose_res_4405;
                                                              }
                                                              choose_res_4380 = choose_res_4400;
                                                            }
                                                            choose_res_4375 = choose_res_4380;
                                                          }
                                                          choose_res_4370 = choose_res_4375;
                                                        }
                                                        choose_res_4365 = choose_res_4370;
                                                      }
                                                      choose_res_4360 = choose_res_4365;
                                                    }
                                                    choose_res_4355 = choose_res_4360;
                                                  }
                                                  choose_res_4350 = choose_res_4355;
                                                }
                                                choose_res_4345 = choose_res_4350;
                                              }
                                              choose_res_4340 = choose_res_4345;
                                            }
                                            choose_res_4335 = choose_res_4340;
                                          }
                                          choose_res_4330 = choose_res_4335;
                                        }
                                        choose_res_4325 = choose_res_4330;
                                      }
                                      letpair_res_4322 = choose_res_4325;
                                    }
                                    let_res_4321 = letpair_res_4322;
                                  }
                                  v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4413;
                                  {
                                    auto dtup_fst_455 { std::get<0>(let_res_4321) };
                                    auto dtup_snd_456 { std::get<1>(let_res_4321) };
                                    f63f919559f0d70225bd0da5dd9bcafc id_4414 { fun3236(dtup_snd_456) };
                                    v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4415;
                                    {
                                      auto dtup_fst_458 { std::get<0>(id_4414) };
                                      auto dtup_snd_459 { std::get<1>(id_4414) };
                                      b899c3a5f918df0742a7782ddf15cd18 id_4416 {  dtup_fst_455, dtup_fst_458  };
                                      v_2a737e40b715df686303c32fcaefae73 id_4417 { std::in_place_index<0>, id_4416 };
                                      v_9f6c76bf140d94510c6437dee417ba9f id_4418 {  id_4417, dtup_snd_459  };
                                      letpair_res_4415 = id_4418;
                                    }
                                    letpair_res_4413 = letpair_res_4415;
                                  }
                                  choose_res_4317 = letpair_res_4413;
                                } else {
                                  uint16_t id_4419 { 1 };
                                  bool id_4420 { bool(id_4419 == dsum1_fst_117) };
                                  v_9f6c76bf140d94510c6437dee417ba9f choose_res_4421;
                                  if (id_4420) {
                                    v_362f9d9108a6902af48b6c83d5377ea1 id_4422 { dsum1_snd_118.readU16Le() };
                                    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4423;
                                    {
                                      auto du16_fst_350 { std::get<0>(id_4422) };
                                      auto du16_snd_351 { std::get<1>(id_4422) };
                                      v_362f9d9108a6902af48b6c83d5377ea1 id_4424 {  du16_fst_350, du16_snd_351  };
                                      letpair_res_4423 = id_4424;
                                    }
                                    v_5d97723b1b63aa3df1222ecb758e8bc2 let_res_4425;
                                    {
                                      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_355 { letpair_res_4423 };
                                      v_5d97723b1b63aa3df1222ecb758e8bc2 letpair_res_4426;
                                      {
                                        auto dsum1_fst_356 { std::get<0>(dsum1_355) };
                                        auto dsum1_snd_357 { std::get<1>(dsum1_355) };
                                        uint16_t id_4427 { 0 };
                                        bool id_4428 { bool(id_4427 == dsum1_fst_356) };
                                        v_5d97723b1b63aa3df1222ecb758e8bc2 choose_res_4429;
                                        if (id_4428) {
                                          v_1bafb672d5db6e6c81afc008103c3a63 id_4430 { std::in_place_index<0>, VOID };
                                          v_5d97723b1b63aa3df1222ecb758e8bc2 id_4431 {  id_4430, dsum1_snd_357  };
                                          choose_res_4429 = id_4431;
                                        } else {
                                          uint16_t id_4432 { 1 };
                                          bool id_4433 { bool(id_4432 == dsum1_fst_356) };
                                          v_5d97723b1b63aa3df1222ecb758e8bc2 choose_res_4434;
                                          if (id_4433) {
                                            v_1bafb672d5db6e6c81afc008103c3a63 id_4435 { std::in_place_index<1>, VOID };
                                            v_5d97723b1b63aa3df1222ecb758e8bc2 id_4436 {  id_4435, dsum1_snd_357  };
                                            choose_res_4434 = id_4436;
                                          } else {
                                            uint16_t id_4437 { 2 };
                                            bool id_4438 { bool(id_4437 == dsum1_fst_356) };
                                            v_5d97723b1b63aa3df1222ecb758e8bc2 choose_res_4439;
                                            if (id_4438) {
                                              v_1bafb672d5db6e6c81afc008103c3a63 id_4440 { std::in_place_index<2>, VOID };
                                              v_5d97723b1b63aa3df1222ecb758e8bc2 id_4441 {  id_4440, dsum1_snd_357  };
                                              choose_res_4439 = id_4441;
                                            } else {
                                              uint16_t id_4442 { 3 };
                                              bool id_4443 { bool(dsum1_fst_356 == id_4442) };
                                              Void id_4444 { ((void)(assert(id_4443)), VOID) };
                                              v_1bafb672d5db6e6c81afc008103c3a63 id_4445 { std::in_place_index<3>, VOID };
                                              v_5d97723b1b63aa3df1222ecb758e8bc2 id_4446 {  id_4445, dsum1_snd_357  };
                                              choose_res_4439 = id_4446;
                                            }
                                            choose_res_4434 = choose_res_4439;
                                          }
                                          choose_res_4429 = choose_res_4434;
                                        }
                                        letpair_res_4426 = choose_res_4429;
                                      }
                                      let_res_4425 = letpair_res_4426;
                                    }
                                    v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4447;
                                    {
                                      auto dtup_fst_371 { std::get<0>(let_res_4425) };
                                      auto dtup_snd_372 { std::get<1>(let_res_4425) };
                                      f63f919559f0d70225bd0da5dd9bcafc id_4448 { fun3236(dtup_snd_372) };
                                      v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4449;
                                      {
                                        auto dtup_fst_374 { std::get<0>(id_4448) };
                                        auto dtup_snd_375 { std::get<1>(id_4448) };
                                        f63f919559f0d70225bd0da5dd9bcafc id_4450 { fun3236(dtup_snd_375) };
                                        v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4451;
                                        {
                                          auto dtup_fst_377 { std::get<0>(id_4450) };
                                          auto dtup_snd_378 { std::get<1>(id_4450) };
                                          bd090e444c05c1e6fea8a3c1c0be1d01 id_4452 {  dtup_fst_371, dtup_fst_374, dtup_fst_377  };
                                          v_2a737e40b715df686303c32fcaefae73 id_4453 { std::in_place_index<1>, id_4452 };
                                          v_9f6c76bf140d94510c6437dee417ba9f id_4454 {  id_4453, dtup_snd_378  };
                                          letpair_res_4451 = id_4454;
                                        }
                                        letpair_res_4449 = letpair_res_4451;
                                      }
                                      letpair_res_4447 = letpair_res_4449;
                                    }
                                    choose_res_4421 = letpair_res_4447;
                                  } else {
                                    uint16_t id_4455 { 2 };
                                    bool id_4456 { bool(id_4455 == dsum1_fst_117) };
                                    v_9f6c76bf140d94510c6437dee417ba9f choose_res_4457;
                                    if (id_4456) {
                                      v_362f9d9108a6902af48b6c83d5377ea1 id_4458 { dsum1_snd_118.readU16Le() };
                                      v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4459;
                                      {
                                        auto du16_fst_314 { std::get<0>(id_4458) };
                                        auto du16_snd_315 { std::get<1>(id_4458) };
                                        v_362f9d9108a6902af48b6c83d5377ea1 id_4460 {  du16_fst_314, du16_snd_315  };
                                        letpair_res_4459 = id_4460;
                                      }
                                      v_4ef2e9135749a8c10bb981c20e0409c7 let_res_4461;
                                      {
                                        v_362f9d9108a6902af48b6c83d5377ea1 dsum1_319 { letpair_res_4459 };
                                        v_4ef2e9135749a8c10bb981c20e0409c7 letpair_res_4462;
                                        {
                                          auto dsum1_fst_320 { std::get<0>(dsum1_319) };
                                          auto dsum1_snd_321 { std::get<1>(dsum1_319) };
                                          uint16_t id_4463 { 0 };
                                          bool id_4464 { bool(id_4463 == dsum1_fst_320) };
                                          v_4ef2e9135749a8c10bb981c20e0409c7 choose_res_4465;
                                          if (id_4464) {
                                            bf5e3bf9cedd12797481a910416c04b9 id_4466 { std::in_place_index<0>, VOID };
                                            v_4ef2e9135749a8c10bb981c20e0409c7 id_4467 {  id_4466, dsum1_snd_321  };
                                            choose_res_4465 = id_4467;
                                          } else {
                                            uint16_t id_4468 { 1 };
                                            bool id_4469 { bool(id_4468 == dsum1_fst_320) };
                                            v_4ef2e9135749a8c10bb981c20e0409c7 choose_res_4470;
                                            if (id_4469) {
                                              bf5e3bf9cedd12797481a910416c04b9 id_4471 { std::in_place_index<1>, VOID };
                                              v_4ef2e9135749a8c10bb981c20e0409c7 id_4472 {  id_4471, dsum1_snd_321  };
                                              choose_res_4470 = id_4472;
                                            } else {
                                              uint16_t id_4473 { 2 };
                                              bool id_4474 { bool(dsum1_fst_320 == id_4473) };
                                              Void id_4475 { ((void)(assert(id_4474)), VOID) };
                                              v_1d5843897434feb24d158f3793db9189 id_4476 { dsum1_snd_321.readU8() };
                                              v_4ef2e9135749a8c10bb981c20e0409c7 letpair_res_4477;
                                              {
                                                auto dbool_fst_323 { std::get<0>(id_4476) };
                                                auto dbool_snd_324 { std::get<1>(id_4476) };
                                                uint8_t id_4478 { 0 };
                                                bool id_4479 { bool(dbool_fst_323 == id_4478) };
                                                bool id_4480 { ! id_4479 };
                                                bf5e3bf9cedd12797481a910416c04b9 id_4481 { std::in_place_index<2>, id_4480 };
                                                v_4ef2e9135749a8c10bb981c20e0409c7 id_4482 {  id_4481, dbool_snd_324  };
                                                letpair_res_4477 = id_4482;
                                              }
                                              choose_res_4470 = letpair_res_4477;
                                            }
                                            choose_res_4465 = choose_res_4470;
                                          }
                                          letpair_res_4462 = choose_res_4465;
                                        }
                                        let_res_4461 = letpair_res_4462;
                                      }
                                      v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4483;
                                      {
                                        auto dtup_fst_335 { std::get<0>(let_res_4461) };
                                        auto dtup_snd_336 { std::get<1>(let_res_4461) };
                                        f63f919559f0d70225bd0da5dd9bcafc id_4484 { fun3236(dtup_snd_336) };
                                        v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4485;
                                        {
                                          auto dtup_fst_338 { std::get<0>(id_4484) };
                                          auto dtup_snd_339 { std::get<1>(id_4484) };
                                          f63f919559f0d70225bd0da5dd9bcafc id_4486 { fun3236(dtup_snd_339) };
                                          v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4487;
                                          {
                                            auto dtup_fst_341 { std::get<0>(id_4486) };
                                            auto dtup_snd_342 { std::get<1>(id_4486) };
                                            f63f919559f0d70225bd0da5dd9bcafc id_4488 { fun3236(dtup_snd_342) };
                                            v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4489;
                                            {
                                              auto dtup_fst_344 { std::get<0>(id_4488) };
                                              auto dtup_snd_345 { std::get<1>(id_4488) };
                                              bf3bba49b7fb7fb20a2d18c9ba46e6e9 id_4490 {  dtup_fst_335, dtup_fst_338, dtup_fst_341, dtup_fst_344  };
                                              v_2a737e40b715df686303c32fcaefae73 id_4491 { std::in_place_index<2>, id_4490 };
                                              v_9f6c76bf140d94510c6437dee417ba9f id_4492 {  id_4491, dtup_snd_345  };
                                              letpair_res_4489 = id_4492;
                                            }
                                            letpair_res_4487 = letpair_res_4489;
                                          }
                                          letpair_res_4485 = letpair_res_4487;
                                        }
                                        letpair_res_4483 = letpair_res_4485;
                                      }
                                      choose_res_4457 = letpair_res_4483;
                                    } else {
                                      uint16_t id_4493 { 3 };
                                      bool id_4494 { bool(id_4493 == dsum1_fst_117) };
                                      v_9f6c76bf140d94510c6437dee417ba9f choose_res_4495;
                                      if (id_4494) {
                                        v_362f9d9108a6902af48b6c83d5377ea1 id_4496 { dsum1_snd_118.readU16Le() };
                                        v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4497;
                                        {
                                          auto du16_fst_278 { std::get<0>(id_4496) };
                                          auto du16_snd_279 { std::get<1>(id_4496) };
                                          v_362f9d9108a6902af48b6c83d5377ea1 id_4498 {  du16_fst_278, du16_snd_279  };
                                          letpair_res_4497 = id_4498;
                                        }
                                        be50f132b1070740f04581361279b652 let_res_4499;
                                        {
                                          v_362f9d9108a6902af48b6c83d5377ea1 dsum1_283 { letpair_res_4497 };
                                          be50f132b1070740f04581361279b652 letpair_res_4500;
                                          {
                                            auto dsum1_fst_284 { std::get<0>(dsum1_283) };
                                            auto dsum1_snd_285 { std::get<1>(dsum1_283) };
                                            uint16_t id_4501 { 0 };
                                            bool id_4502 { bool(id_4501 == dsum1_fst_284) };
                                            be50f132b1070740f04581361279b652 choose_res_4503;
                                            if (id_4502) {
                                              v_87b032206ceea8867a37c2e0aaee953e id_4504 { std::in_place_index<0>, VOID };
                                              be50f132b1070740f04581361279b652 id_4505 {  id_4504, dsum1_snd_285  };
                                              choose_res_4503 = id_4505;
                                            } else {
                                              uint16_t id_4506 { 1 };
                                              bool id_4507 { bool(dsum1_fst_284 == id_4506) };
                                              Void id_4508 { ((void)(assert(id_4507)), VOID) };
                                              v_1d5843897434feb24d158f3793db9189 id_4509 { dsum1_snd_285.readU8() };
                                              be50f132b1070740f04581361279b652 letpair_res_4510;
                                              {
                                                auto dbool_fst_287 { std::get<0>(id_4509) };
                                                auto dbool_snd_288 { std::get<1>(id_4509) };
                                                uint8_t id_4511 { 0 };
                                                bool id_4512 { bool(dbool_fst_287 == id_4511) };
                                                bool id_4513 { ! id_4512 };
                                                v_87b032206ceea8867a37c2e0aaee953e id_4514 { std::in_place_index<1>, id_4513 };
                                                be50f132b1070740f04581361279b652 id_4515 {  id_4514, dbool_snd_288  };
                                                letpair_res_4510 = id_4515;
                                              }
                                              choose_res_4503 = letpair_res_4510;
                                            }
                                            letpair_res_4500 = choose_res_4503;
                                          }
                                          let_res_4499 = letpair_res_4500;
                                        }
                                        v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4516;
                                        {
                                          auto dtup_fst_296 { std::get<0>(let_res_4499) };
                                          auto dtup_snd_297 { std::get<1>(let_res_4499) };
                                          f63f919559f0d70225bd0da5dd9bcafc id_4517 { fun3236(dtup_snd_297) };
                                          v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4518;
                                          {
                                            auto dtup_fst_299 { std::get<0>(id_4517) };
                                            auto dtup_snd_300 { std::get<1>(id_4517) };
                                            f63f919559f0d70225bd0da5dd9bcafc id_4519 { fun3236(dtup_snd_300) };
                                            v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4520;
                                            {
                                              auto dtup_fst_302 { std::get<0>(id_4519) };
                                              auto dtup_snd_303 { std::get<1>(id_4519) };
                                              f63f919559f0d70225bd0da5dd9bcafc id_4521 { fun3236(dtup_snd_303) };
                                              v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4522;
                                              {
                                                auto dtup_fst_305 { std::get<0>(id_4521) };
                                                auto dtup_snd_306 { std::get<1>(id_4521) };
                                                f63f919559f0d70225bd0da5dd9bcafc id_4523 { fun3236(dtup_snd_306) };
                                                v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4524;
                                                {
                                                  auto dtup_fst_308 { std::get<0>(id_4523) };
                                                  auto dtup_snd_309 { std::get<1>(id_4523) };
                                                  v_853c6bada9e3fde79da0a65d1b1d1c9a id_4525 {  dtup_fst_296, dtup_fst_299, dtup_fst_302, dtup_fst_305, dtup_fst_308  };
                                                  v_2a737e40b715df686303c32fcaefae73 id_4526 { std::in_place_index<3>, id_4525 };
                                                  v_9f6c76bf140d94510c6437dee417ba9f id_4527 {  id_4526, dtup_snd_309  };
                                                  letpair_res_4524 = id_4527;
                                                }
                                                letpair_res_4522 = letpair_res_4524;
                                              }
                                              letpair_res_4520 = letpair_res_4522;
                                            }
                                            letpair_res_4518 = letpair_res_4520;
                                          }
                                          letpair_res_4516 = letpair_res_4518;
                                        }
                                        choose_res_4495 = letpair_res_4516;
                                      } else {
                                        uint16_t id_4528 { 4 };
                                        bool id_4529 { bool(id_4528 == dsum1_fst_117) };
                                        v_9f6c76bf140d94510c6437dee417ba9f choose_res_4530;
                                        if (id_4529) {
                                          v_362f9d9108a6902af48b6c83d5377ea1 id_4531 { dsum1_snd_118.readU16Le() };
                                          v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4532;
                                          {
                                            auto du16_fst_210 { std::get<0>(id_4531) };
                                            auto du16_snd_211 { std::get<1>(id_4531) };
                                            v_362f9d9108a6902af48b6c83d5377ea1 id_4533 {  du16_fst_210, du16_snd_211  };
                                            letpair_res_4532 = id_4533;
                                          }
                                          e95534d23d0ba3bdeaf86aa35c50c907 let_res_4534;
                                          {
                                            v_362f9d9108a6902af48b6c83d5377ea1 dsum1_215 { letpair_res_4532 };
                                            e95534d23d0ba3bdeaf86aa35c50c907 letpair_res_4535;
                                            {
                                              auto dsum1_fst_216 { std::get<0>(dsum1_215) };
                                              auto dsum1_snd_217 { std::get<1>(dsum1_215) };
                                              uint16_t id_4536 { 0 };
                                              bool id_4537 { bool(id_4536 == dsum1_fst_216) };
                                              e95534d23d0ba3bdeaf86aa35c50c907 choose_res_4538;
                                              if (id_4537) {
                                                v_40203346c83d9d499f90ff16996e8968 id_4539 { std::in_place_index<0>, VOID };
                                                e95534d23d0ba3bdeaf86aa35c50c907 id_4540 {  id_4539, dsum1_snd_217  };
                                                choose_res_4538 = id_4540;
                                              } else {
                                                uint16_t id_4541 { 1 };
                                                bool id_4542 { bool(dsum1_fst_216 == id_4541) };
                                                Void id_4543 { ((void)(assert(id_4542)), VOID) };
                                                v_1d5843897434feb24d158f3793db9189 id_4544 { dsum1_snd_217.readU8() };
                                                f2a48a42f9c827f487e53ee52a4e9e2f letpair_res_4545;
                                                {
                                                  auto dbool_fst_219 { std::get<0>(id_4544) };
                                                  auto dbool_snd_220 { std::get<1>(id_4544) };
                                                  uint8_t id_4546 { 0 };
                                                  bool id_4547 { bool(dbool_fst_219 == id_4546) };
                                                  bool id_4548 { ! id_4547 };
                                                  f2a48a42f9c827f487e53ee52a4e9e2f id_4549 {  id_4548, dbool_snd_220  };
                                                  letpair_res_4545 = id_4549;
                                                }
                                                e95534d23d0ba3bdeaf86aa35c50c907 let_res_4550;
                                                {
                                                  f2a48a42f9c827f487e53ee52a4e9e2f drec_221 { letpair_res_4545 };
                                                  e95534d23d0ba3bdeaf86aa35c50c907 letpair_res_4551;
                                                  {
                                                    auto drec_fst_222 { std::get<0>(drec_221) };
                                                    auto drec_snd_223 { std::get<1>(drec_221) };
                                                    v_1d5843897434feb24d158f3793db9189 id_4552 { drec_snd_223.readU8() };
                                                    e95534d23d0ba3bdeaf86aa35c50c907 letpair_res_4553;
                                                    {
                                                      auto dbool_fst_225 { std::get<0>(id_4552) };
                                                      auto dbool_snd_226 { std::get<1>(id_4552) };
                                                      uint8_t id_4554 { 0 };
                                                      bool id_4555 { bool(dbool_fst_225 == id_4554) };
                                                      bool id_4556 { ! id_4555 };
                                                      v_0cb2265b788de1dea43d444c41f930d3 id_4557 {  .inv = drec_fst_222, .up_to = id_4556  };
                                                      v_40203346c83d9d499f90ff16996e8968 id_4558 { std::in_place_index<1>, id_4557 };
                                                      e95534d23d0ba3bdeaf86aa35c50c907 id_4559 {  id_4558, dbool_snd_226  };
                                                      letpair_res_4553 = id_4559;
                                                    }
                                                    letpair_res_4551 = letpair_res_4553;
                                                  }
                                                  let_res_4550 = letpair_res_4551;
                                                }
                                                choose_res_4538 = let_res_4550;
                                              }
                                              letpair_res_4535 = choose_res_4538;
                                            }
                                            let_res_4534 = letpair_res_4535;
                                          }
                                          v_9f6c76bf140d94510c6437dee417ba9f let_res_4560;
                                          {
                                            e95534d23d0ba3bdeaf86aa35c50c907 dtup_236 { let_res_4534 };
                                            v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4561;
                                            {
                                              auto dtup_fst_237 { std::get<0>(dtup_236) };
                                              auto dtup_snd_238 { std::get<1>(dtup_236) };
                                              f63f919559f0d70225bd0da5dd9bcafc id_4562 { fun3236(dtup_snd_238) };
                                              v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4563;
                                              {
                                                auto dtup_fst_240 { std::get<0>(id_4562) };
                                                auto dtup_snd_241 { std::get<1>(id_4562) };
                                                f63f919559f0d70225bd0da5dd9bcafc id_4564 { fun3236(dtup_snd_241) };
                                                v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4565;
                                                {
                                                  auto dtup_fst_243 { std::get<0>(id_4564) };
                                                  auto dtup_snd_244 { std::get<1>(id_4564) };
                                                  f63f919559f0d70225bd0da5dd9bcafc id_4566 { fun3236(dtup_snd_244) };
                                                  v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4567;
                                                  {
                                                    auto dtup_fst_246 { std::get<0>(id_4566) };
                                                    auto dtup_snd_247 { std::get<1>(id_4566) };
                                                    uint32_t id_4568 { 0U };
                                                    Vec<1, uint32_t> id_4569 {  id_4568  };
                                                    ac0fbd05039f742d2f1d9ac182e392ab let_res_4570;
                                                    {
                                                      Vec<1, uint32_t> leb_ref_248 { id_4569 };
                                                      uint8_t id_4571 { 0 };
                                                      Vec<1, uint8_t> id_4572 {  id_4571  };
                                                      ac0fbd05039f742d2f1d9ac182e392ab let_res_4573;
                                                      {
                                                        Vec<1, uint8_t> shft_ref_249 { id_4572 };
                                                        Vec<1, Pointer> id_4574 {  dtup_snd_247  };
                                                        ac0fbd05039f742d2f1d9ac182e392ab let_res_4575;
                                                        {
                                                          Vec<1, Pointer> p_ref_250 { id_4574 };
                                                          bool while_flag_4576 { true };
                                                          do {
                                                            uint8_t id_4577 { 0 };
                                                            Pointer id_4578 { p_ref_250[id_4577] };
                                                            v_1d5843897434feb24d158f3793db9189 id_4579 { id_4578.readU8() };
                                                            bool let_res_4580;
                                                            {
                                                              v_1d5843897434feb24d158f3793db9189 leb128_251 { id_4579 };
                                                              bool letpair_res_4581;
                                                              {
                                                                auto leb128_fst_252 { std::get<0>(leb128_251) };
                                                                auto leb128_snd_253 { std::get<1>(leb128_251) };
                                                                uint8_t id_4582 { 0 };
                                                                Void id_4583 { ((void)(p_ref_250[id_4582] = leb128_snd_253), VOID) };
                                                                uint8_t id_4584 { 0 };
                                                                uint8_t id_4585 { 127 };
                                                                uint8_t id_4586 { uint8_t(leb128_fst_252 & id_4585) };
                                                                uint32_t id_4587 { uint32_t(id_4586) };
                                                                uint8_t id_4588 { 0 };
                                                                uint8_t id_4589 { shft_ref_249[id_4588] };
                                                                uint32_t id_4590 { uint32_t(id_4587 << id_4589) };
                                                                uint8_t id_4591 { 0 };
                                                                uint32_t id_4592 { leb_ref_248[id_4591] };
                                                                uint32_t id_4593 { uint32_t(id_4590 | id_4592) };
                                                                Void id_4594 { ((void)(leb_ref_248[id_4584] = id_4593), VOID) };
                                                                uint8_t id_4595 { 0 };
                                                                uint8_t id_4596 { 0 };
                                                                uint8_t id_4597 { shft_ref_249[id_4596] };
                                                                uint8_t id_4598 { 7 };
                                                                uint8_t id_4599 { uint8_t(id_4597 + id_4598) };
                                                                Void id_4600 { ((void)(shft_ref_249[id_4595] = id_4599), VOID) };
                                                                uint8_t id_4601 { 128 };
                                                                bool id_4602 { bool(leb128_fst_252 >= id_4601) };
                                                                letpair_res_4581 = id_4602;
                                                              }
                                                              let_res_4580 = letpair_res_4581;
                                                            }
                                                            while_flag_4576 = let_res_4580;
                                                            if (while_flag_4576) {
                                                            }
                                                          } while (while_flag_4576);
                                                          uint8_t id_4603 { 0 };
                                                          uint32_t id_4604 { leb_ref_248[id_4603] };
                                                          uint8_t id_4605 { 0 };
                                                          Pointer id_4606 { p_ref_250[id_4605] };
                                                          ac0fbd05039f742d2f1d9ac182e392ab id_4607 {  id_4604, id_4606  };
                                                          let_res_4575 = id_4607;
                                                        }
                                                        let_res_4573 = let_res_4575;
                                                      }
                                                      let_res_4570 = let_res_4573;
                                                    }
                                                    e8d9438e2f3a196555a010d8d14a3c3a let_res_4608;
                                                    {
                                                      ac0fbd05039f742d2f1d9ac182e392ab dlist1_257 { let_res_4570 };
                                                      e8d9438e2f3a196555a010d8d14a3c3a letpair_res_4609;
                                                      {
                                                        auto dlist1_fst_258 { std::get<0>(dlist1_257) };
                                                        auto dlist1_snd_259 { std::get<1>(dlist1_257) };
                                                        Lst<t*> endoflist_4610;
                                                        e8d9438e2f3a196555a010d8d14a3c3a id_4611 {  endoflist_4610, dlist1_snd_259  };
                                                        Vec<1, e8d9438e2f3a196555a010d8d14a3c3a> id_4612 {  id_4611  };
                                                        e8d9438e2f3a196555a010d8d14a3c3a let_res_4613;
                                                        {
                                                          Vec<1, e8d9438e2f3a196555a010d8d14a3c3a> inits_src_ref_260 { id_4612 };
                                                          int32_t id_4614 { 0L };
                                                          Vec<1, int32_t> id_4615 {  id_4614  };
                                                          {
                                                            Vec<1, int32_t> repeat_n_261 { id_4615 };
                                                            bool while_flag_4616 { true };
                                                            do {
                                                              int32_t id_4617 { int32_t(dlist1_fst_258) };
                                                              uint8_t id_4618 { 0 };
                                                              int32_t id_4619 { repeat_n_261[id_4618] };
                                                              bool id_4620 { bool(id_4617 > id_4619) };
                                                              while_flag_4616 = id_4620;
                                                              if (while_flag_4616) {
                                                                uint8_t id_4621 { 0 };
                                                                e8d9438e2f3a196555a010d8d14a3c3a id_4622 { inits_src_ref_260[id_4621] };
                                                                {
                                                                  e8d9438e2f3a196555a010d8d14a3c3a dlist2_262 { id_4622 };
                                                                  {
                                                                    auto dlist2_fst_263 { std::get<0>(dlist2_262) };
                                                                    auto dlist2_snd_264 { std::get<1>(dlist2_262) };
                                                                    uint8_t id_4623 { 0 };
                                                                    f63f919559f0d70225bd0da5dd9bcafc id_4624 { fun3236(dlist2_snd_264) };
                                                                    e8d9438e2f3a196555a010d8d14a3c3a letpair_res_4625;
                                                                    {
                                                                      auto dlist3_fst_266 { std::get<0>(id_4624) };
                                                                      auto dlist3_snd_267 { std::get<1>(id_4624) };
                                                                      Lst<t*> id_4626 { dlist3_fst_266, dlist2_fst_263 };
                                                                      e8d9438e2f3a196555a010d8d14a3c3a id_4627 {  id_4626, dlist3_snd_267  };
                                                                      letpair_res_4625 = id_4627;
                                                                    }
                                                                    Void id_4628 { ((void)(inits_src_ref_260[id_4623] = letpair_res_4625), VOID) };
                                                                  }
                                                                }
                                                                uint8_t id_4629 { 0 };
                                                                uint8_t id_4630 { 0 };
                                                                int32_t id_4631 { repeat_n_261[id_4630] };
                                                                int32_t id_4632 { 1L };
                                                                int32_t id_4633 { int32_t(id_4631 + id_4632) };
                                                                Void id_4634 { ((void)(repeat_n_261[id_4629] = id_4633), VOID) };
                                                              }
                                                            } while (while_flag_4616);
                                                          }
                                                          uint8_t id_4635 { 0 };
                                                          e8d9438e2f3a196555a010d8d14a3c3a id_4636 { inits_src_ref_260[id_4635] };
                                                          let_res_4613 = id_4636;
                                                        }
                                                        letpair_res_4609 = let_res_4613;
                                                      }
                                                      let_res_4608 = letpair_res_4609;
                                                    }
                                                    v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4637;
                                                    {
                                                      auto dlist4_fst_269 { std::get<0>(let_res_4608) };
                                                      auto dlist4_snd_270 { std::get<1>(let_res_4608) };
                                                      d48e39cf1002fefa9b2dd8287b9e36b3 id_4638 {  dtup_fst_237, dtup_fst_240, dtup_fst_243, dtup_fst_246, dlist4_fst_269  };
                                                      v_2a737e40b715df686303c32fcaefae73 id_4639 { std::in_place_index<4>, id_4638 };
                                                      v_9f6c76bf140d94510c6437dee417ba9f id_4640 {  id_4639, dlist4_snd_270  };
                                                      letpair_res_4637 = id_4640;
                                                    }
                                                    letpair_res_4567 = letpair_res_4637;
                                                  }
                                                  letpair_res_4565 = letpair_res_4567;
                                                }
                                                letpair_res_4563 = letpair_res_4565;
                                              }
                                              letpair_res_4561 = letpair_res_4563;
                                            }
                                            let_res_4560 = letpair_res_4561;
                                          }
                                          choose_res_4530 = let_res_4560;
                                        } else {
                                          uint16_t id_4641 { 5 };
                                          bool id_4642 { bool(id_4641 == dsum1_fst_117) };
                                          v_9f6c76bf140d94510c6437dee417ba9f choose_res_4643;
                                          if (id_4642) {
                                            v_362f9d9108a6902af48b6c83d5377ea1 id_4644 { dsum1_snd_118.readU16Le() };
                                            v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4645;
                                            {
                                              auto du16_fst_174 { std::get<0>(id_4644) };
                                              auto du16_snd_175 { std::get<1>(id_4644) };
                                              v_362f9d9108a6902af48b6c83d5377ea1 id_4646 {  du16_fst_174, du16_snd_175  };
                                              letpair_res_4645 = id_4646;
                                            }
                                            v_9f6c76bf140d94510c6437dee417ba9f let_res_4647;
                                            {
                                              v_362f9d9108a6902af48b6c83d5377ea1 dsum1_179 { letpair_res_4645 };
                                              v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4648;
                                              {
                                                auto dsum1_fst_180 { std::get<0>(dsum1_179) };
                                                auto dsum1_snd_181 { std::get<1>(dsum1_179) };
                                                uint16_t id_4649 { 0 };
                                                bool id_4650 { bool(dsum1_fst_180 == id_4649) };
                                                Void id_4651 { ((void)(assert(id_4650)), VOID) };
                                                f63f919559f0d70225bd0da5dd9bcafc id_4652 { fun3236(dsum1_snd_181) };
                                                v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4653;
                                                {
                                                  auto dtup_fst_189 { std::get<0>(id_4652) };
                                                  auto dtup_snd_190 { std::get<1>(id_4652) };
                                                  f63f919559f0d70225bd0da5dd9bcafc id_4654 { fun3236(dtup_snd_190) };
                                                  v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4655;
                                                  {
                                                    auto dtup_fst_192 { std::get<0>(id_4654) };
                                                    auto dtup_snd_193 { std::get<1>(id_4654) };
                                                    f63f919559f0d70225bd0da5dd9bcafc id_4656 { fun3236(dtup_snd_193) };
                                                    v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4657;
                                                    {
                                                      auto dtup_fst_195 { std::get<0>(id_4656) };
                                                      auto dtup_snd_196 { std::get<1>(id_4656) };
                                                      f63f919559f0d70225bd0da5dd9bcafc id_4658 { fun3236(dtup_snd_196) };
                                                      v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4659;
                                                      {
                                                        auto dtup_fst_198 { std::get<0>(id_4658) };
                                                        auto dtup_snd_199 { std::get<1>(id_4658) };
                                                        f63f919559f0d70225bd0da5dd9bcafc id_4660 { fun3236(dtup_snd_199) };
                                                        v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4661;
                                                        {
                                                          auto dtup_fst_201 { std::get<0>(id_4660) };
                                                          auto dtup_snd_202 { std::get<1>(id_4660) };
                                                          f63f919559f0d70225bd0da5dd9bcafc id_4662 { fun3236(dtup_snd_202) };
                                                          v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4663;
                                                          {
                                                            auto dtup_fst_204 { std::get<0>(id_4662) };
                                                            auto dtup_snd_205 { std::get<1>(id_4662) };
                                                            d137ffedb0c351c86760c7f124759f50 id_4664 { std::in_place_index<0>, VOID };
                                                            v_28696cf4b42cc9ab09b392e5143f2f25 id_4665 {  id_4664, dtup_fst_189, dtup_fst_192, dtup_fst_195, dtup_fst_198, dtup_fst_201, dtup_fst_204  };
                                                            v_2a737e40b715df686303c32fcaefae73 id_4666 { std::in_place_index<5>, id_4665 };
                                                            v_9f6c76bf140d94510c6437dee417ba9f id_4667 {  id_4666, dtup_snd_205  };
                                                            letpair_res_4663 = id_4667;
                                                          }
                                                          letpair_res_4661 = letpair_res_4663;
                                                        }
                                                        letpair_res_4659 = letpair_res_4661;
                                                      }
                                                      letpair_res_4657 = letpair_res_4659;
                                                    }
                                                    letpair_res_4655 = letpair_res_4657;
                                                  }
                                                  letpair_res_4653 = letpair_res_4655;
                                                }
                                                letpair_res_4648 = letpair_res_4653;
                                              }
                                              let_res_4647 = letpair_res_4648;
                                            }
                                            choose_res_4643 = let_res_4647;
                                          } else {
                                            uint16_t id_4668 { 6 };
                                            bool id_4669 { bool(id_4668 == dsum1_fst_117) };
                                            v_9f6c76bf140d94510c6437dee417ba9f choose_res_4670;
                                            if (id_4669) {
                                              std::function<v_782396e4e62e54e181f157869588e15c(Pointer)> id_4671 { dessser::gen::raql_top_output::of_row_binary };
                                              v_782396e4e62e54e181f157869588e15c id_4672 { id_4671(dsum1_snd_118) };
                                              v_9f6c76bf140d94510c6437dee417ba9f let_res_4673;
                                              {
                                                v_782396e4e62e54e181f157869588e15c drec_143 { id_4672 };
                                                v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4674;
                                                {
                                                  auto drec_fst_144 { std::get<0>(drec_143) };
                                                  auto drec_snd_145 { std::get<1>(drec_143) };
                                                  f63f919559f0d70225bd0da5dd9bcafc id_4675 { fun3236(drec_snd_145) };
                                                  v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4676;
                                                  {
                                                    auto drec_fst_147 { std::get<0>(id_4675) };
                                                    auto drec_snd_148 { std::get<1>(id_4675) };
                                                    Size id_4677 { 0UL };
                                                    uint8_t id_4678 { drec_snd_148.peekU8(id_4677) };
                                                    uint8_t id_4679 { 1 };
                                                    bool id_4680 { bool(id_4678 == id_4679) };
                                                    ff77a37bf330c28b69daf62f3f59e310 choose_res_4681;
                                                    if (id_4680) {
                                                      std::optional<t*> id_4682 { std::nullopt };
                                                      Size id_4683 { 1UL };
                                                      Pointer id_4684 { drec_snd_148.skip(id_4683) };
                                                      ff77a37bf330c28b69daf62f3f59e310 id_4685 {  id_4682, id_4684  };
                                                      choose_res_4681 = id_4685;
                                                    } else {
                                                      Size id_4686 { 1UL };
                                                      Pointer id_4687 { drec_snd_148.skip(id_4686) };
                                                      f63f919559f0d70225bd0da5dd9bcafc id_4688 { fun3236(id_4687) };
                                                      ff77a37bf330c28b69daf62f3f59e310 letpair_res_4689;
                                                      {
                                                        auto make1_1_fst_150 { std::get<0>(id_4688) };
                                                        auto make1_1_snd_151 { std::get<1>(id_4688) };
                                                        std::optional<t*> id_4690 { make1_1_fst_150 };
                                                        ff77a37bf330c28b69daf62f3f59e310 id_4691 {  id_4690, make1_1_snd_151  };
                                                        letpair_res_4689 = id_4691;
                                                      }
                                                      choose_res_4681 = letpair_res_4689;
                                                    }
                                                    v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4692;
                                                    {
                                                      auto drec_fst_153 { std::get<0>(choose_res_4681) };
                                                      auto drec_snd_154 { std::get<1>(choose_res_4681) };
                                                      f63f919559f0d70225bd0da5dd9bcafc id_4693 { fun3236(drec_snd_154) };
                                                      v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4694;
                                                      {
                                                        auto drec_fst_156 { std::get<0>(id_4693) };
                                                        auto drec_snd_157 { std::get<1>(id_4693) };
                                                        f63f919559f0d70225bd0da5dd9bcafc id_4695 { fun3236(drec_snd_157) };
                                                        v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4696;
                                                        {
                                                          auto drec_fst_159 { std::get<0>(id_4695) };
                                                          auto drec_snd_160 { std::get<1>(id_4695) };
                                                          f63f919559f0d70225bd0da5dd9bcafc id_4697 { fun3236(drec_snd_160) };
                                                          v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4698;
                                                          {
                                                            auto drec_fst_162 { std::get<0>(id_4697) };
                                                            auto drec_snd_163 { std::get<1>(id_4697) };
                                                            f63f919559f0d70225bd0da5dd9bcafc id_4699 { fun3236(drec_snd_163) };
                                                            v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4700;
                                                            {
                                                              auto drec_fst_165 { std::get<0>(id_4699) };
                                                              auto drec_snd_166 { std::get<1>(id_4699) };
                                                              f63f919559f0d70225bd0da5dd9bcafc id_4701 { fun3236(drec_snd_166) };
                                                              v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4702;
                                                              {
                                                                auto drec_fst_168 { std::get<0>(id_4701) };
                                                                auto drec_snd_169 { std::get<1>(id_4701) };
                                                                v_2da729c5f96e51679cb6e2c06e6ceb25 id_4703 {  .output = drec_fst_144, .size = drec_fst_147, .max_size = drec_fst_153, .what = drec_fst_156, .by = drec_fst_159, .time = drec_fst_162, .duration = drec_fst_165, .sigmas = drec_fst_168  };
                                                                v_2a737e40b715df686303c32fcaefae73 id_4704 { std::in_place_index<6>, id_4703 };
                                                                v_9f6c76bf140d94510c6437dee417ba9f id_4705 {  id_4704, drec_snd_169  };
                                                                letpair_res_4702 = id_4705;
                                                              }
                                                              letpair_res_4700 = letpair_res_4702;
                                                            }
                                                            letpair_res_4698 = letpair_res_4700;
                                                          }
                                                          letpair_res_4696 = letpair_res_4698;
                                                        }
                                                        letpair_res_4694 = letpair_res_4696;
                                                      }
                                                      letpair_res_4692 = letpair_res_4694;
                                                    }
                                                    letpair_res_4676 = letpair_res_4692;
                                                  }
                                                  letpair_res_4674 = letpair_res_4676;
                                                }
                                                let_res_4673 = letpair_res_4674;
                                              }
                                              choose_res_4670 = let_res_4673;
                                            } else {
                                              uint16_t id_4706 { 7 };
                                              bool id_4707 { bool(dsum1_fst_117 == id_4706) };
                                              Void id_4708 { ((void)(assert(id_4707)), VOID) };
                                              f63f919559f0d70225bd0da5dd9bcafc id_4709 { fun3236(dsum1_snd_118) };
                                              v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4710;
                                              {
                                                auto drec_fst_120 { std::get<0>(id_4709) };
                                                auto drec_snd_121 { std::get<1>(id_4709) };
                                                f63f919559f0d70225bd0da5dd9bcafc id_4711 { fun3236(drec_snd_121) };
                                                v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4712;
                                                {
                                                  auto drec_fst_123 { std::get<0>(id_4711) };
                                                  auto drec_snd_124 { std::get<1>(id_4711) };
                                                  f63f919559f0d70225bd0da5dd9bcafc id_4713 { fun3236(drec_snd_124) };
                                                  v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4714;
                                                  {
                                                    auto drec_fst_126 { std::get<0>(id_4713) };
                                                    auto drec_snd_127 { std::get<1>(id_4713) };
                                                    v_1d5843897434feb24d158f3793db9189 id_4715 { drec_snd_127.readU8() };
                                                    f2a48a42f9c827f487e53ee52a4e9e2f letpair_res_4716;
                                                    {
                                                      auto dbool_fst_129 { std::get<0>(id_4715) };
                                                      auto dbool_snd_130 { std::get<1>(id_4715) };
                                                      uint8_t id_4717 { 0 };
                                                      bool id_4718 { bool(dbool_fst_129 == id_4717) };
                                                      bool id_4719 { ! id_4718 };
                                                      f2a48a42f9c827f487e53ee52a4e9e2f id_4720 {  id_4719, dbool_snd_130  };
                                                      letpair_res_4716 = id_4720;
                                                    }
                                                    v_9f6c76bf140d94510c6437dee417ba9f let_res_4721;
                                                    {
                                                      f2a48a42f9c827f487e53ee52a4e9e2f drec_131 { letpair_res_4716 };
                                                      v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4722;
                                                      {
                                                        auto drec_fst_132 { std::get<0>(drec_131) };
                                                        auto drec_snd_133 { std::get<1>(drec_131) };
                                                        Size id_4723 { 0UL };
                                                        uint8_t id_4724 { drec_snd_133.peekU8(id_4723) };
                                                        uint8_t id_4725 { 1 };
                                                        bool id_4726 { bool(id_4724 == id_4725) };
                                                        ff77a37bf330c28b69daf62f3f59e310 choose_res_4727;
                                                        if (id_4726) {
                                                          std::optional<t*> id_4728 { std::nullopt };
                                                          Size id_4729 { 1UL };
                                                          Pointer id_4730 { drec_snd_133.skip(id_4729) };
                                                          ff77a37bf330c28b69daf62f3f59e310 id_4731 {  id_4728, id_4730  };
                                                          choose_res_4727 = id_4731;
                                                        } else {
                                                          Size id_4732 { 1UL };
                                                          Pointer id_4733 { drec_snd_133.skip(id_4732) };
                                                          f63f919559f0d70225bd0da5dd9bcafc id_4734 { fun3236(id_4733) };
                                                          ff77a37bf330c28b69daf62f3f59e310 letpair_res_4735;
                                                          {
                                                            auto make1_1_fst_135 { std::get<0>(id_4734) };
                                                            auto make1_1_snd_136 { std::get<1>(id_4734) };
                                                            std::optional<t*> id_4736 { make1_1_fst_135 };
                                                            ff77a37bf330c28b69daf62f3f59e310 id_4737 {  id_4736, make1_1_snd_136  };
                                                            letpair_res_4735 = id_4737;
                                                          }
                                                          choose_res_4727 = letpair_res_4735;
                                                        }
                                                        v_9f6c76bf140d94510c6437dee417ba9f letpair_res_4738;
                                                        {
                                                          auto drec_fst_138 { std::get<0>(choose_res_4727) };
                                                          auto drec_snd_139 { std::get<1>(choose_res_4727) };
                                                          v_148d37e471eb6790a77b16fc96041a20 id_4739 {  .what = drec_fst_120, .time = drec_fst_123, .max_age = drec_fst_126, .tumbling = drec_fst_132, .sample_size = drec_fst_138  };
                                                          v_2a737e40b715df686303c32fcaefae73 id_4740 { std::in_place_index<7>, id_4739 };
                                                          v_9f6c76bf140d94510c6437dee417ba9f id_4741 {  id_4740, drec_snd_139  };
                                                          letpair_res_4738 = id_4741;
                                                        }
                                                        letpair_res_4722 = letpair_res_4738;
                                                      }
                                                      let_res_4721 = letpair_res_4722;
                                                    }
                                                    letpair_res_4714 = let_res_4721;
                                                  }
                                                  letpair_res_4712 = letpair_res_4714;
                                                }
                                                letpair_res_4710 = letpair_res_4712;
                                              }
                                              choose_res_4670 = letpair_res_4710;
                                            }
                                            choose_res_4643 = choose_res_4670;
                                          }
                                          choose_res_4530 = choose_res_4643;
                                        }
                                        choose_res_4495 = choose_res_4530;
                                      }
                                      choose_res_4457 = choose_res_4495;
                                    }
                                    choose_res_4421 = choose_res_4457;
                                  }
                                  choose_res_4317 = choose_res_4421;
                                }
                                letpair_res_4314 = choose_res_4317;
                              }
                              let_res_4313 = letpair_res_4314;
                            }
                            f05619a6958568f0d4db38b191811dc1 letpair_res_4742;
                            {
                              auto dtup_fst_464 { std::get<0>(let_res_4313) };
                              auto dtup_snd_465 { std::get<1>(let_res_4313) };
                              v_58c653b3fc47800248b5c8f49e80fabb id_4743 {  dtup_fst_102, dtup_fst_108, dtup_fst_464  };
                              dc31f5cc689133a6f12d16478388e785 id_4744 { std::in_place_index<5>, id_4743 };
                              f05619a6958568f0d4db38b191811dc1 id_4745 {  id_4744, dtup_snd_465  };
                              letpair_res_4742 = id_4745;
                            }
                            letpair_res_4309 = letpair_res_4742;
                          }
                          let_res_4308 = letpair_res_4309;
                        }
                        letpair_res_4301 = let_res_4308;
                      }
                      let_res_4300 = letpair_res_4301;
                    }
                    choose_res_4284 = let_res_4300;
                  } else {
                    uint16_t id_4746 { 6 };
                    bool id_4747 { bool(dsum1_fst_63 == id_4746) };
                    Void id_4748 { ((void)(assert(id_4747)), VOID) };
                    v_362f9d9108a6902af48b6c83d5377ea1 id_4749 { dsum1_snd_64.readU16Le() };
                    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_4750;
                    {
                      auto du16_fst_66 { std::get<0>(id_4749) };
                      auto du16_snd_67 { std::get<1>(id_4749) };
                      v_362f9d9108a6902af48b6c83d5377ea1 id_4751 {  du16_fst_66, du16_snd_67  };
                      letpair_res_4750 = id_4751;
                    }
                    f05619a6958568f0d4db38b191811dc1 let_res_4752;
                    {
                      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_71 { letpair_res_4750 };
                      f05619a6958568f0d4db38b191811dc1 letpair_res_4753;
                      {
                        auto dsum1_fst_72 { std::get<0>(dsum1_71) };
                        auto dsum1_snd_73 { std::get<1>(dsum1_71) };
                        uint16_t id_4754 { 0 };
                        bool id_4755 { bool(dsum1_fst_72 == id_4754) };
                        Void id_4756 { ((void)(assert(id_4755)), VOID) };
                        f63f919559f0d70225bd0da5dd9bcafc id_4757 { fun3236(dsum1_snd_73) };
                        f05619a6958568f0d4db38b191811dc1 letpair_res_4758;
                        {
                          auto dtup_fst_75 { std::get<0>(id_4757) };
                          auto dtup_snd_76 { std::get<1>(id_4757) };
                          f63f919559f0d70225bd0da5dd9bcafc id_4759 { fun3236(dtup_snd_76) };
                          f05619a6958568f0d4db38b191811dc1 letpair_res_4760;
                          {
                            auto dtup_fst_78 { std::get<0>(id_4759) };
                            auto dtup_snd_79 { std::get<1>(id_4759) };
                            v_88361d7e3c5fc5844d2ff9213ba400b1 id_4761 {  dtup_fst_75, dtup_fst_78  };
                            v_1c5224020b28e5bf4853392434fd6e31 id_4762 { std::in_place_index<0>, id_4761 };
                            dc31f5cc689133a6f12d16478388e785 id_4763 { std::in_place_index<6>, id_4762 };
                            f05619a6958568f0d4db38b191811dc1 id_4764 {  id_4763, dtup_snd_79  };
                            letpair_res_4760 = id_4764;
                          }
                          letpair_res_4758 = letpair_res_4760;
                        }
                        letpair_res_4753 = letpair_res_4758;
                      }
                      let_res_4752 = letpair_res_4753;
                    }
                    choose_res_4284 = let_res_4752;
                  }
                  choose_res_3571 = choose_res_4284;
                }
                choose_res_3473 = choose_res_3571;
              }
              choose_res_3398 = choose_res_3473;
            }
            choose_res_3319 = choose_res_3398;
          }
          choose_res_3244 = choose_res_3319;
        }
        letpair_res_3241 = choose_res_3244;
      }
      let_res_3240 = letpair_res_3241;
    }
    f63f919559f0d70225bd0da5dd9bcafc let_res_4765;
    {
      f05619a6958568f0d4db38b191811dc1 drec_1024 { let_res_3240 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_4766;
      {
        auto drec_fst_1025 { std::get<0>(drec_1024) };
        auto drec_snd_1026 { std::get<1>(drec_1024) };
        ac0fbd05039f742d2f1d9ac182e392ab id_4767 { drec_snd_1026.readU32Le() };
        ac0fbd05039f742d2f1d9ac182e392ab letpair_res_4768;
        {
          auto du32_fst_1028 { std::get<0>(id_4767) };
          auto du32_snd_1029 { std::get<1>(id_4767) };
          ac0fbd05039f742d2f1d9ac182e392ab id_4769 {  du32_fst_1028, du32_snd_1029  };
          letpair_res_4768 = id_4769;
        }
        f63f919559f0d70225bd0da5dd9bcafc let_res_4770;
        {
          ac0fbd05039f742d2f1d9ac182e392ab drec_1030 { letpair_res_4768 };
          f63f919559f0d70225bd0da5dd9bcafc letpair_res_4771;
          {
            auto drec_fst_1031 { std::get<0>(drec_1030) };
            auto drec_snd_1032 { std::get<1>(drec_1030) };
            std::function<v_1afe9f73328d6d7bdf808b1d2eb2af22(Pointer)> id_4772 { dessser::gen::raql_type::of_row_binary };
            v_1afe9f73328d6d7bdf808b1d2eb2af22 id_4773 { id_4772(drec_snd_1032) };
            f63f919559f0d70225bd0da5dd9bcafc let_res_4774;
            {
              v_1afe9f73328d6d7bdf808b1d2eb2af22 drec_1033 { id_4773 };
              f63f919559f0d70225bd0da5dd9bcafc letpair_res_4775;
              {
                auto drec_fst_1034 { std::get<0>(drec_1033) };
                auto drec_snd_1035 { std::get<1>(drec_1033) };
                Size id_4776 { 0UL };
                uint8_t id_4777 { drec_snd_1035.peekU8(id_4776) };
                uint8_t id_4778 { 1 };
                bool id_4779 { bool(id_4777 == id_4778) };
                bf974315651fdd731eda317cf9d211f4 choose_res_4780;
                if (id_4779) {
                  std::optional<dessser::gen::units::t> id_4781 { std::nullopt };
                  Size id_4782 { 1UL };
                  Pointer id_4783 { drec_snd_1035.skip(id_4782) };
                  bf974315651fdd731eda317cf9d211f4 id_4784 {  id_4781, id_4783  };
                  choose_res_4780 = id_4784;
                } else {
                  std::function<v_765fc2dfa0d4b4acfe348a1dcf7356d2(Pointer)> id_4785 { dessser::gen::units::of_row_binary };
                  Size id_4786 { 1UL };
                  Pointer id_4787 { drec_snd_1035.skip(id_4786) };
                  v_765fc2dfa0d4b4acfe348a1dcf7356d2 id_4788 { id_4785(id_4787) };
                  bf974315651fdd731eda317cf9d211f4 letpair_res_4789;
                  {
                    auto make1_1_fst_1037 { std::get<0>(id_4788) };
                    auto make1_1_snd_1038 { std::get<1>(id_4788) };
                    std::optional<dessser::gen::units::t> id_4790 { make1_1_fst_1037 };
                    bf974315651fdd731eda317cf9d211f4 id_4791 {  id_4790, make1_1_snd_1038  };
                    letpair_res_4789 = id_4791;
                  }
                  choose_res_4780 = letpair_res_4789;
                }
                f63f919559f0d70225bd0da5dd9bcafc letpair_res_4792;
                {
                  auto drec_fst_1040 { std::get<0>(choose_res_4780) };
                  auto drec_snd_1041 { std::get<1>(choose_res_4780) };
                  t id_4793 {  .text = drec_fst_1025, .uniq_num = drec_fst_1031, .typ = drec_fst_1034, .units = drec_fst_1040  };
                  f63f919559f0d70225bd0da5dd9bcafc id_4794 {  id_4793, drec_snd_1041  };
                  letpair_res_4792 = id_4794;
                }
                letpair_res_4775 = letpair_res_4792;
              }
              let_res_4774 = letpair_res_4775;
            }
            letpair_res_4771 = let_res_4774;
          }
          let_res_4770 = letpair_res_4771;
        }
        letpair_res_4766 = let_res_4770;
      }
      let_res_4765 = letpair_res_4766;
    }
    return let_res_4765;
  }
   };
  return fun3236;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
