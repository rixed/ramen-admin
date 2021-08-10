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

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  *raql_expr duration;
  double period;
  bool operator==(t const &other) const {
    return duration == other.duration && period == other.period;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "duration:" << r.duration << ',';
  os << "period:" << r.period;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  *raql_expr,
  Pointer
> v_3501be1aaefb5944279c6a13f6d0d43f;

typedef std::tuple<
  uint64_t,
  Pointer
> b62e103e7915a76f45f02f7c6f667c79;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{duration: $raql_expr; period: FLOAT}" "Ptr")
      (let "srec_dst_70" (apply (ext-identifier raql_expr to-row-binary) (get-field "duration" (param 0)) (param 1)) (write-u64 little-endian (identifier "srec_dst_70") (u64-of-float (get-field "period" (param 0))))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    std::function<Pointer(*raql_expr,Pointer)> id_1 { dessser_gen::raql_expr.to_row_binary };
    *raql_expr id_2 { p_0.duration };
    Pointer id_3 { id_1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_70 { id_3 };
      double id_5 { p_0.period };
      uint64_t id_6 { qword_of_float(id_5) };
      Pointer id_7 { srec_dst_70.writeU64Le(id_6) };
      let_res_4 = id_7;
    }
    return let_res_4;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{duration: $raql_expr; period: FLOAT}") (add (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "duration" (param 0))) (size 8)))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun8 { [&fun8](t p_0) {
    std::function<Size(*raql_expr)> id_9 { dessser_gen::raql_expr.sersize_of_row_binary };
    *raql_expr id_10 { p_0.duration };
    Size id_11 { id_9(id_10) };
    Size id_12 { 8UL };
    Size id_13 { Size(id_11 + id_12) };
    return id_13;
  }
   };
  return fun8;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier raql_expr of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let-pair "dfloat_fst_60" "dfloat_snd_61" (read-u64 little-endian (identifier "drec_snd_58"))
            (make-tup (make-rec (string "duration") (identifier "drec_fst_57") (string "period") (float-of-u64 (identifier "dfloat_fst_60"))) (identifier "dfloat_snd_61"))))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun14 { [&fun14](Pointer p_0) {
    std::function<v_3501be1aaefb5944279c6a13f6d0d43f(Pointer)> id_15 { dessser_gen::raql_expr.of_row_binary };
    v_3501be1aaefb5944279c6a13f6d0d43f id_16 { id_15(p_0) };
    f63f919559f0d70225bd0da5dd9bcafc let_res_17;
    {
      v_3501be1aaefb5944279c6a13f6d0d43f drec_56 { id_16 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_18;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        b62e103e7915a76f45f02f7c6f667c79 id_19 { drec_snd_58.readU64Le() };
        f63f919559f0d70225bd0da5dd9bcafc letpair_res_20;
        {
          auto dfloat_fst_60 { std::get<0>(id_19) };
          auto dfloat_snd_61 { std::get<1>(id_19) };
          double id_21 { float_of_qword(dfloat_fst_60) };
          t id_22 {  .duration = drec_fst_57, .period = id_21  };
          f63f919559f0d70225bd0da5dd9bcafc id_23 {  id_22, dfloat_snd_61  };
          letpair_res_20 = id_23;
        }
        letpair_res_18 = letpair_res_20;
      }
      let_res_17 = letpair_res_18;
    }
    return let_res_17;
  }
   };
  return fun14;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
