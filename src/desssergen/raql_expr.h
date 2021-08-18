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
struct t177d8060c8d9defa2496b6f538d50dc6 {
  t* case_cond;
  t* case_cons;
  bool operator==(t177d8060c8d9defa2496b6f538d50dc6 const &other) const {
    return case_cond == other.case_cond && case_cons == other.case_cons;
  }
};
inline std::ostream &operator<<(std::ostream &os, t177d8060c8d9defa2496b6f538d50dc6 const &r) {
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
  Lst<t177d8060c8d9defa2496b6f538d50dc6>,
  std::optional<t*>
> tbc47cf0d3f02094b967fcd5b040d1985;

struct t0c40b492f61ef87a5fcf3b21d8f4e80e : public std::variant<
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
inline std::ostream &operator<<(std::ostream &os, t0c40b492f61ef87a5fcf3b21d8f4e80e const &v) {
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

struct t2dbd741445d7e42b47d58662914c784b : public std::variant<
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t2dbd741445d7e42b47d58662914c784b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::raql_type::t_ext,
  t2dbd741445d7e42b47d58662914c784b
> t7fc9de748f26a92499dfbf302288210d;

struct te0944ec416054dd0f74e66aa7bb24d96 : public std::variant<
  Void,
  dessser::gen::raql_type::t_ext,
  Void,
  t7fc9de748f26a92499dfbf302288210d,
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
inline std::ostream &operator<<(std::ostream &os, te0944ec416054dd0f74e66aa7bb24d96 const &v) {
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
  te0944ec416054dd0f74e66aa7bb24d96,
  t*
> t12d1490e670eca7c57a76871a5f9bd86;

struct t7ae9bb09a1a0070adced41151deef93f : public std::variant<
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t7ae9bb09a1a0070adced41151deef93f const &v) {
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
  t7ae9bb09a1a0070adced41151deef93f,
  Lst<t*>
> t598129eb09e2c59d3acabd02013c58bf;

struct ta402aa25be8876cf8c4a9d229cd14994 : public std::variant<
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
inline std::ostream &operator<<(std::ostream &os, ta402aa25be8876cf8c4a9d229cd14994 const &v) {
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
struct t5bbbb8a47e6794d457428e727b3cb603 : public std::tuple<
  ta402aa25be8876cf8c4a9d229cd14994,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t5bbbb8a47e6794d457428e727b3cb603 const &t) {
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
struct tadb560c88aeba8f056a56c15e9b73f5b : public std::tuple<
  t2dbd741445d7e42b47d58662914c784b,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, tadb560c88aeba8f056a56c15e9b73f5b const &t) {
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
struct te83c8c2ba507757c32c3745663dc4a2e : public std::variant<
  t0c40b492f61ef87a5fcf3b21d8f4e80e,
  t12d1490e670eca7c57a76871a5f9bd86,
  t598129eb09e2c59d3acabd02013c58bf,
  t5bbbb8a47e6794d457428e727b3cb603,
  tadb560c88aeba8f056a56c15e9b73f5b
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, te83c8c2ba507757c32c3745663dc4a2e const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
  }
  return os;
}

struct t08a4206efa0e73cfb0135731e5423c08 : public std::tuple<
  double,
  double,
  uint32_t
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t08a4206efa0e73cfb0135731e5423c08 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t070762157f579c7a8e789f54a7d3fc53 : public std::variant<
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
  t08a4206efa0e73cfb0135731e5423c08,
  Void,
  Void,
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t070762157f579c7a8e789f54a7d3fc53 const &v) {
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
  t070762157f579c7a8e789f54a7d3fc53,
  t*
> t96a48a8eba707570d4f5e7ba2ca2e141;

struct t;
struct t;
struct t;
struct t;
struct t532d170d8f625c2e1251fd22ac6bf5f1 : public std::tuple<
  t7ae9bb09a1a0070adced41151deef93f,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t532d170d8f625c2e1251fd22ac6bf5f1 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct t7c498ce06acf948707e50e0f1cdc51b3 : public std::variant<
  Void,
  Void,
  bool
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t7c498ce06acf948707e50e0f1cdc51b3 const &v) {
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
struct td1a7262ccc9c3dc19b2cfedfbe3325d0 : public std::tuple<
  t7c498ce06acf948707e50e0f1cdc51b3,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, td1a7262ccc9c3dc19b2cfedfbe3325d0 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct tb5da3d7613982d2f6e505d341026f6d9 : public std::variant<
  Void,
  bool
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tb5da3d7613982d2f6e505d341026f6d9 const &v) {
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
struct t9e65f050ea9829e0601e5f07b5deb731 : public std::tuple<
  tb5da3d7613982d2f6e505d341026f6d9,
  t*,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t9e65f050ea9829e0601e5f07b5deb731 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t) << ", "
     << std::get<4>(t)
     << '>';
  return os;
}

struct tfe489f988a8fa16084d8a9296ec32556 {
  bool inv;
  bool up_to;
  bool operator==(tfe489f988a8fa16084d8a9296ec32556 const &other) const {
    return inv == other.inv && up_to == other.up_to;
  }
};
inline std::ostream &operator<<(std::ostream &os, tfe489f988a8fa16084d8a9296ec32556 const &r) {
  os << '{';
  os << "inv:" << r.inv << ',';
  os << "up_to:" << r.up_to;
  os << '}';
  return os;
}

struct t03b98ddbeb67c50e5afdf161b45b5928 : public std::variant<
  Void,
  tfe489f988a8fa16084d8a9296ec32556
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, t03b98ddbeb67c50e5afdf161b45b5928 const &v) {
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
struct tbd8917b427f49aecfe973d80d4802685 : public std::tuple<
  t03b98ddbeb67c50e5afdf161b45b5928,
  t*,
  t*,
  t*,
  Lst<t*>
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, tbd8917b427f49aecfe973d80d4802685 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t) << ", "
     << std::get<4>(t)
     << '>';
  return os;
}

struct tafdc15d083fb8c2b34d5c9537c7c3b35 : public std::variant<
  Void
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tafdc15d083fb8c2b34d5c9537c7c3b35 const &v) {
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
struct td69c573d3d751d786bf69def959e2558 : public std::tuple<
  tafdc15d083fb8c2b34d5c9537c7c3b35,
  t*,
  t*,
  t*,
  t*,
  t*,
  t*
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, td69c573d3d751d786bf69def959e2558 const &t) {
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
struct t9bfded57d764855b59cb221ca084b590 {
  dessser::gen::raql_top_output::t_ext output;
  t* size;
  std::optional<t*> max_size;
  t* what;
  t* by;
  t* time;
  t* duration;
  t* sigmas;
  bool operator==(t9bfded57d764855b59cb221ca084b590 const &other) const {
    return output == other.output && size == other.size && max_size == other.max_size && what == other.what && by == other.by && time == other.time && duration == other.duration && sigmas == other.sigmas;
  }
};
inline std::ostream &operator<<(std::ostream &os, t9bfded57d764855b59cb221ca084b590 const &r) {
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
struct t;
struct t;
struct t;
struct t;
struct t660e047757fc7ba51fd7f001e0bf9d9c {
  t* what;
  t* time;
  t* max_age;
  bool tumbling;
  std::optional<t*> sample_size;
  bool operator==(t660e047757fc7ba51fd7f001e0bf9d9c const &other) const {
    return what == other.what && time == other.time && max_age == other.max_age && tumbling == other.tumbling && sample_size == other.sample_size;
  }
};
inline std::ostream &operator<<(std::ostream &os, t660e047757fc7ba51fd7f001e0bf9d9c const &r) {
  os << '{';
  os << "what:" << r.what << ',';
  os << "time:" << r.time << ',';
  os << "max_age:" << r.max_age << ',';
  os << "tumbling:" << r.tumbling << ',';
  os << "sample_size:" << r.sample_size;
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
struct te525f7ce13a3bdc572f5b895e8d77e09 : public std::variant<
  t96a48a8eba707570d4f5e7ba2ca2e141,
  t532d170d8f625c2e1251fd22ac6bf5f1,
  td1a7262ccc9c3dc19b2cfedfbe3325d0,
  t9e65f050ea9829e0601e5f07b5deb731,
  tbd8917b427f49aecfe973d80d4802685,
  td69c573d3d751d786bf69def959e2558,
  t9bfded57d764855b59cb221ca084b590,
  t660e047757fc7ba51fd7f001e0bf9d9c
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, te525f7ce13a3bdc572f5b895e8d77e09 const &v) {
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
struct t0856dc35a1fb9cac8e18275020f9255a : public std::tuple<
  t2dbd741445d7e42b47d58662914c784b,
  bool,
  te525f7ce13a3bdc572f5b895e8d77e09
> { using tuple::tuple; };
inline std::ostream &operator<<(std::ostream &os, t0856dc35a1fb9cac8e18275020f9255a const &t) {
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
struct ta8c163c764f1b99e1eafc9bc4bc9b365 : public std::variant<
  t7411897bdb6c9b6e00a01b4eb6506ccf
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, ta8c163c764f1b99e1eafc9bc4bc9b365 const &v) {
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
struct tf3dae4884b4e557e8054ca7c164cab32 : public std::variant<
  Lst<t*>,
  Lst<t5b91ba1a37fd19816559f3dabb32e8b5>,
  Lst<t*>,
  tbc47cf0d3f02094b967fcd5b040d1985,
  te83c8c2ba507757c32c3745663dc4a2e,
  t0856dc35a1fb9cac8e18275020f9255a,
  ta8c163c764f1b99e1eafc9bc4bc9b365
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tf3dae4884b4e557e8054ca7c164cab32 const &v) {
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
  tf3dae4884b4e557e8054ca7c164cab32 text;
  uint32_t uniq_num;
  dessser::gen::raql_type::t_ext typ;
  std::optional<dessser::gen::units::t_ext> units;
  bool operator==(t const &other) const {
    return text == other.text && uniq_num == other.uniq_num && typ == other.typ && units == other.units;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
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
struct t;
struct t;
struct t;
struct t;
struct t;
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
