#ifndef DESSSER_GEN_raql_expr
#define DESSSER_GEN_raql_expr
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/units.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_top_output.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_path_comp.h"
#include "desssergen/raql_binding_key.h"
#include "desssergen/raql_variable.h"
#include "desssergen/raql_value.h"
#include "desssergen/field_name.h"

namespace dessser::gen::raql_expr {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t;
struct t;
struct t;
typedef std::tuple<
  dessser::gen::field_name::t_ext,
  t*
> t5b91ba1a37fd19816559f3dabb32e8b5;

struct t;
struct t;
struct t;
struct t;
struct t;
struct taa24bd22284a38a2aa5417ddcf68dc02 {
  t* case_cond;
  t* case_cons;
  bool operator==(taa24bd22284a38a2aa5417ddcf68dc02 const &other) const {
    return case_cond == other.case_cond && case_cons == other.case_cons;
  }
};
inline std::ostream &operator<<(std::ostream &os, taa24bd22284a38a2aa5417ddcf68dc02 const &r) {
  os << '{';
  os << "case_cond:" << r.case_cond << ',';
  os << "case_cons:" << r.case_cons;
  os << '}';
  return os;
}

struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  Lst<::dessser::gen::raql_expr::taa24bd22284a38a2aa5417ddcf68dc02>,
  std::optional<t*>
> t72e501d49719761ba8ff88c3982af245;

struct t302ca6fb40d94197a91ec3595c5b0d3b : public std::variant<
  dessser::gen::raql_value::t_ext,
  dessser::gen::raql_variable::t_ext,
  dessser::gen::raql_binding_key::t_ext,
  Void,
  Void,
  Void,
  Void,
  Lst<dessser::gen::raql_path_comp::t_ext>,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t302ca6fb40d94197a91ec3595c5b0d3b const &v) {
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

struct t48b79f232880b7b4f6fa63fb49447c29 : public std::variant<
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t48b79f232880b7b4f6fa63fb49447c29 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::raql_type::t_ext,
  ::dessser::gen::raql_expr::t48b79f232880b7b4f6fa63fb49447c29
> tc0b7eee4e32fb5400edd291164ac1e81;

struct t13d510ae314aa88e35c3706532ac9488 : public std::variant<
  Void,
  dessser::gen::raql_type::t_ext,
  Void,
  ::dessser::gen::raql_expr::tc0b7eee4e32fb5400edd291164ac1e81,
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
inline std::ostream &operator<<(std::ostream &os, t13d510ae314aa88e35c3706532ac9488 const &v) {
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
struct t;
typedef std::tuple<
  ::dessser::gen::raql_expr::t13d510ae314aa88e35c3706532ac9488,
  t*
> t89cf11a8d9e6bf81ab17d6aed4247182;

struct t94d3f63f7a6f4439feec5972b0434d93 : public std::variant<
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t94d3f63f7a6f4439feec5972b0434d93 const &v) {
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
typedef std::tuple<
  ::dessser::gen::raql_expr::t94d3f63f7a6f4439feec5972b0434d93,
  Lst<t*>
> t3b727565b3ae9f61fd29a5836b55e8e7;

struct t132110d5e7d86d2e99c17ebeb895e5fe : public std::variant<
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
inline std::ostream &operator<<(std::ostream &os, t132110d5e7d86d2e99c17ebeb895e5fe const &v) {
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
struct t;
struct t;
struct tf6d60f65b15932c045d2a92fc1c17c59 : public std::tuple<
  ::dessser::gen::raql_expr::t132110d5e7d86d2e99c17ebeb895e5fe,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, tf6d60f65b15932c045d2a92fc1c17c59 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t40bdb8406d714c5cd0be4e7af25144fb : public std::tuple<
  ::dessser::gen::raql_expr::t48b79f232880b7b4f6fa63fb49447c29,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t40bdb8406d714c5cd0be4e7af25144fb const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
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
struct tbd346f57da21609965082cdc361f8fbf : public std::variant<
  ::dessser::gen::raql_expr::t302ca6fb40d94197a91ec3595c5b0d3b,
  ::dessser::gen::raql_expr::t89cf11a8d9e6bf81ab17d6aed4247182,
  ::dessser::gen::raql_expr::t3b727565b3ae9f61fd29a5836b55e8e7,
  ::dessser::gen::raql_expr::tf6d60f65b15932c045d2a92fc1c17c59,
  ::dessser::gen::raql_expr::t40bdb8406d714c5cd0be4e7af25144fb
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tbd346f57da21609965082cdc361f8fbf const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
  }
  return os;
}

struct t7a94101e0d1c22c7ddfebd959d73730a : public std::tuple<
  double,
  double,
  uint32_t
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t7a94101e0d1c22c7ddfebd959d73730a const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t0bfb6ea47ab5b6963434216ffdbf1c4b : public std::variant<
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
  ::dessser::gen::raql_expr::t7a94101e0d1c22c7ddfebd959d73730a,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t0bfb6ea47ab5b6963434216ffdbf1c4b const &v) {
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
struct t;
typedef std::tuple<
  ::dessser::gen::raql_expr::t0bfb6ea47ab5b6963434216ffdbf1c4b,
  t*
> t4e68126c7ef14bc7c3816b834301e131;

struct t;
struct t;
struct t;
struct t;
struct t29ad70980c1ed0de607f154b2cf37079 : public std::tuple<
  ::dessser::gen::raql_expr::t94d3f63f7a6f4439feec5972b0434d93,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t29ad70980c1ed0de607f154b2cf37079 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct tdcc895625422a22e36d3aaa6c06c106d : public std::variant<
  Void,
  Void,
  bool
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tdcc895625422a22e36d3aaa6c06c106d const &v) {
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
struct t;
struct t;
struct t;
struct t6fd96f32806a7be149cf6aeb65c52003 : public std::tuple<
  ::dessser::gen::raql_expr::tdcc895625422a22e36d3aaa6c06c106d,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t6fd96f32806a7be149cf6aeb65c52003 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct t921af81efb70732ad0db1d0c7dcad5c6 : public std::variant<
  Void,
  bool
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t921af81efb70732ad0db1d0c7dcad5c6 const &v) {
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
struct t;
struct t;
struct t;
struct t5eea0d7071354d8574d1d288be2da03c : public std::tuple<
  ::dessser::gen::raql_expr::t921af81efb70732ad0db1d0c7dcad5c6,
  t*,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t5eea0d7071354d8574d1d288be2da03c const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t) << ", "
     << std::get<4>(t)
     << '>';
  return os;
}

struct tf4054221050c951844715a915de49acf {
  bool inv;
  bool up_to;
  bool operator==(tf4054221050c951844715a915de49acf const &other) const {
    return inv == other.inv && up_to == other.up_to;
  }
};
inline std::ostream &operator<<(std::ostream &os, tf4054221050c951844715a915de49acf const &r) {
  os << '{';
  os << "inv:" << r.inv << ',';
  os << "up_to:" << r.up_to;
  os << '}';
  return os;
}

struct tfb1d24d1e7b7f70fdb5d555af94ff2cc : public std::variant<
  Void,
  ::dessser::gen::raql_expr::tf4054221050c951844715a915de49acf
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tfb1d24d1e7b7f70fdb5d555af94ff2cc const &v) {
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
struct t;
struct t;
struct t;
struct tfc88680f34dff428e51a593a8371a47c : public std::tuple<
  ::dessser::gen::raql_expr::tfb1d24d1e7b7f70fdb5d555af94ff2cc,
  t*,
  t*,
  t*,
  Lst<t*>
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, tfc88680f34dff428e51a593a8371a47c const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t) << ", "
     << std::get<4>(t)
     << '>';
  return os;
}

struct t113d89516a2c18ae050fd882eee5a84a : public std::variant<
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t113d89516a2c18ae050fd882eee5a84a const &v) {
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
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct te0a08dc040b97d85619e928e4be8c242 : public std::tuple<
  ::dessser::gen::raql_expr::t113d89516a2c18ae050fd882eee5a84a,
  t*,
  t*,
  t*,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, te0a08dc040b97d85619e928e4be8c242 const &t) {
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
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t29f7627e1294ce8b01bedbbca5e648c9 {
  t* by;
  t* duration;
  std::optional<t*> max_size;
  dessser::gen::raql_top_output::t_ext output;
  t* sigmas;
  t* size;
  t* time;
  t* what;
  bool operator==(t29f7627e1294ce8b01bedbbca5e648c9 const &other) const {
    return by == other.by && duration == other.duration && max_size == other.max_size && output == other.output && sigmas == other.sigmas && size == other.size && time == other.time && what == other.what;
  }
};
inline std::ostream &operator<<(std::ostream &os, t29f7627e1294ce8b01bedbbca5e648c9 const &r) {
  os << '{';
  os << "by:" << r.by << ',';
  os << "duration:" << r.duration << ',';
  os << "max_size:" << r.max_size << ',';
  os << "output:" << r.output << ',';
  os << "sigmas:" << r.sigmas << ',';
  os << "size:" << r.size << ',';
  os << "time:" << r.time << ',';
  os << "what:" << r.what;
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
struct t14d4670eeb12d711128d8053596f780b {
  t* max_age;
  std::optional<t*> sample_size;
  t* time;
  bool tumbling;
  t* what;
  bool operator==(t14d4670eeb12d711128d8053596f780b const &other) const {
    return max_age == other.max_age && sample_size == other.sample_size && time == other.time && tumbling == other.tumbling && what == other.what;
  }
};
inline std::ostream &operator<<(std::ostream &os, t14d4670eeb12d711128d8053596f780b const &r) {
  os << '{';
  os << "max_age:" << r.max_age << ',';
  os << "sample_size:" << r.sample_size << ',';
  os << "time:" << r.time << ',';
  os << "tumbling:" << r.tumbling << ',';
  os << "what:" << r.what;
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
struct td8f2c9359fa7d29a6d812dc03d98c395 : public std::variant<
  ::dessser::gen::raql_expr::t4e68126c7ef14bc7c3816b834301e131,
  ::dessser::gen::raql_expr::t29ad70980c1ed0de607f154b2cf37079,
  ::dessser::gen::raql_expr::t6fd96f32806a7be149cf6aeb65c52003,
  ::dessser::gen::raql_expr::t5eea0d7071354d8574d1d288be2da03c,
  ::dessser::gen::raql_expr::tfc88680f34dff428e51a593a8371a47c,
  ::dessser::gen::raql_expr::te0a08dc040b97d85619e928e4be8c242,
  ::dessser::gen::raql_expr::t29f7627e1294ce8b01bedbbca5e648c9,
  ::dessser::gen::raql_expr::t14d4670eeb12d711128d8053596f780b
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, td8f2c9359fa7d29a6d812dc03d98c395 const &v) {
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
struct t7af95785d470bcc8d4f6cb645267c5ab : public std::tuple<
  ::dessser::gen::raql_expr::t48b79f232880b7b4f6fa63fb49447c29,
  bool,
  ::dessser::gen::raql_expr::td8f2c9359fa7d29a6d812dc03d98c395
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t7af95785d470bcc8d4f6cb645267c5ab const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

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
struct t6c44ef6a580b31684bea6cc68702bc6b : public std::variant<
  ::dessser::gen::raql_expr::t7411897bdb6c9b6e00a01b4eb6506ccf
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t6c44ef6a580b31684bea6cc68702bc6b const &v) {
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
struct t7721f259aab20be1dffc9fa06a1108cf : public std::variant<
  Lst<t*>,
  Lst<::dessser::gen::raql_expr::t5b91ba1a37fd19816559f3dabb32e8b5>,
  Lst<t*>,
  ::dessser::gen::raql_expr::t72e501d49719761ba8ff88c3982af245,
  ::dessser::gen::raql_expr::tbd346f57da21609965082cdc361f8fbf,
  ::dessser::gen::raql_expr::t7af95785d470bcc8d4f6cb645267c5ab,
  ::dessser::gen::raql_expr::t6c44ef6a580b31684bea6cc68702bc6b
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t7721f259aab20be1dffc9fa06a1108cf const &v) {
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
struct t {
  ::dessser::gen::raql_expr::t7721f259aab20be1dffc9fa06a1108cf text;
  dessser::gen::raql_type::t_ext typ;
  uint32_t uniq_num;
  std::optional<dessser::gen::units::t_ext> units;
  bool operator==(t const &other) const {
    return text == other.text && typ == other.typ && uniq_num == other.uniq_num && units == other.units;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "text:" << r.text << ',';
  os << "typ:" << r.typ << ',';
  os << "uniq_num:" << r.uniq_num << ',';
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
  ::dessser::gen::raql_expr::t*,
  Pointer
> t5fc112a96748292611657700222a91a6;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::raql_expr::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::raql_expr::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::raql_expr::t5fc112a96748292611657700222a91a6(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
