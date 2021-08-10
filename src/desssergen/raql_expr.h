#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

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
