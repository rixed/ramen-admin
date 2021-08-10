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

namespace dessser::gen::program_parameter {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_type::t ptyp;
  dessser::gen::raql_value::t value;
  bool operator==(t const &other) const {
    return ptyp == other.ptyp && value == other.value;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "ptyp:" << r.ptyp << ',';
  os << "value:" << r.value;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  dessser::gen::field_type::t,
  Pointer
> v_03ddfabda296f7bff76f03d4225eaf1a;

typedef std::tuple<
  dessser::gen::raql_value::t,
  Pointer
> ba3b596d6a5cbc29dc62e6e6a46440d5;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{ptyp: $field_type; value: $raql_value}" "Ptr")
      (let "srec_dst_67" (apply (ext-identifier field_type to-row-binary) (get-field "ptyp" (param 0)) (param 1)) (apply (ext-identifier raql_value to-row-binary) (get-field "value" (param 0)) (identifier "srec_dst_67"))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    std::function<Pointer(dessser::gen::field_type::t,Pointer)> id_1 { dessser::gen::field_type::to_row_binary };
    dessser::gen::field_type::t id_2 { p_0.ptyp };
    Pointer id_3 { id_1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_67 { id_3 };
      std::function<Pointer(dessser::gen::raql_value::t,Pointer)> id_5 { dessser::gen::raql_value::to_row_binary };
      dessser::gen::raql_value::t id_6 { p_0.value };
      Pointer id_7 { id_5(id_6, srec_dst_67) };
      let_res_4 = id_7;
    }
    return let_res_4;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{ptyp: $field_type; value: $raql_value}")
      (let "sz_66" (apply (ext-identifier field_type sersize-of-row-binary) (get-field "ptyp" (param 0))) (add (identifier "sz_66") (apply (ext-identifier raql_value sersize-of-row-binary) (get-field "value" (param 0))))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun8 { [&fun8](t p_0) {
    std::function<Size(dessser::gen::field_type::t)> id_9 { dessser::gen::field_type::sersize_of_row_binary };
    dessser::gen::field_type::t id_10 { p_0.ptyp };
    Size id_11 { id_9(id_10) };
    Size let_res_12;
    {
      Size sz_66 { id_11 };
      std::function<Size(dessser::gen::raql_value::t)> id_13 { dessser::gen::raql_value::sersize_of_row_binary };
      dessser::gen::raql_value::t id_14 { p_0.value };
      Size id_15 { id_13(id_14) };
      Size id_16 { Size(sz_66 + id_15) };
      let_res_12 = id_16;
    }
    return let_res_12;
  }
   };
  return fun8;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier field_type of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let-pair "drec_fst_60" "drec_snd_61" (apply (ext-identifier raql_value of-row-binary) (identifier "drec_snd_58"))
            (make-tup (make-rec (string "ptyp") (identifier "drec_fst_57") (string "value") (identifier "drec_fst_60")) (identifier "drec_snd_61"))))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun17 { [&fun17](Pointer p_0) {
    std::function<v_03ddfabda296f7bff76f03d4225eaf1a(Pointer)> id_18 { dessser::gen::field_type::of_row_binary };
    v_03ddfabda296f7bff76f03d4225eaf1a id_19 { id_18(p_0) };
    f63f919559f0d70225bd0da5dd9bcafc let_res_20;
    {
      v_03ddfabda296f7bff76f03d4225eaf1a drec_56 { id_19 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_21;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        std::function<ba3b596d6a5cbc29dc62e6e6a46440d5(Pointer)> id_22 { dessser::gen::raql_value::of_row_binary };
        ba3b596d6a5cbc29dc62e6e6a46440d5 id_23 { id_22(drec_snd_58) };
        f63f919559f0d70225bd0da5dd9bcafc letpair_res_24;
        {
          auto drec_fst_60 { std::get<0>(id_23) };
          auto drec_snd_61 { std::get<1>(id_23) };
          t id_25 {  .ptyp = drec_fst_57, .value = drec_fst_60  };
          f63f919559f0d70225bd0da5dd9bcafc id_26 {  id_25, drec_snd_61  };
          letpair_res_24 = id_26;
        }
        letpair_res_21 = letpair_res_24;
      }
      let_res_20 = letpair_res_21;
    }
    return let_res_20;
  }
   };
  return fun17;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
