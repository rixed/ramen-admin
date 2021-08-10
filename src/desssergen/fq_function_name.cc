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
  *site_name site;
  *program_name program;
  *function_name function;
  bool operator==(t const &other) const {
    return site == other.site && program == other.program && function == other.function;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "site:" << r.site << ',';
  os << "program:" << r.program << ',';
  os << "function:" << r.function;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  *site_name,
  Pointer
> ddf7cb48181332ead2f60a5f4bb1a8de;

typedef std::tuple<
  *program_name,
  Pointer
> f6e2f55e3ebc4a068d1f568f5860423e;

typedef std::tuple<
  *function_name,
  Pointer
> v_382b80697fdeb5158d298be4e9fcf65e;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{site: $site_name; program: $program_name; function: $function_name}" "Ptr")
      (let "srec_dst_72"
        (let "srec_dst_71" (apply (ext-identifier site_name to-row-binary) (get-field "site" (param 0)) (param 1)) (apply (ext-identifier program_name to-row-binary) (get-field "program" (param 0)) (identifier "srec_dst_71")))
        (apply (ext-identifier function_name to-row-binary) (get-field "function" (param 0)) (identifier "srec_dst_72"))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    std::function<Pointer(*site_name,Pointer)> id_1 { dessser_gen::site_name.to_row_binary };
    *site_name id_2 { p_0.site };
    Pointer id_3 { id_1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_71 { id_3 };
      std::function<Pointer(*program_name,Pointer)> id_5 { dessser_gen::program_name.to_row_binary };
      *program_name id_6 { p_0.program };
      Pointer id_7 { id_5(id_6, srec_dst_71) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_72 { let_res_4 };
      std::function<Pointer(*function_name,Pointer)> id_9 { dessser_gen::function_name.to_row_binary };
      *function_name id_10 { p_0.function };
      Pointer id_11 { id_9(id_10, srec_dst_72) };
      let_res_8 = id_11;
    }
    return let_res_8;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{site: $site_name; program: $program_name; function: $function_name}")
      (let "sz_70"
        (let "sz_69" (apply (ext-identifier site_name sersize-of-row-binary) (get-field "site" (param 0))) (add (identifier "sz_69") (apply (ext-identifier program_name sersize-of-row-binary) (get-field "program" (param 0)))))
        (add (identifier "sz_70") (apply (ext-identifier function_name sersize-of-row-binary) (get-field "function" (param 0))))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun12 { [&fun12](t p_0) {
    std::function<Size(*site_name)> id_13 { dessser_gen::site_name.sersize_of_row_binary };
    *site_name id_14 { p_0.site };
    Size id_15 { id_13(id_14) };
    Size let_res_16;
    {
      Size sz_69 { id_15 };
      std::function<Size(*program_name)> id_17 { dessser_gen::program_name.sersize_of_row_binary };
      *program_name id_18 { p_0.program };
      Size id_19 { id_17(id_18) };
      Size id_20 { Size(sz_69 + id_19) };
      let_res_16 = id_20;
    }
    Size let_res_21;
    {
      Size sz_70 { let_res_16 };
      std::function<Size(*function_name)> id_22 { dessser_gen::function_name.sersize_of_row_binary };
      *function_name id_23 { p_0.function };
      Size id_24 { id_22(id_23) };
      Size id_25 { Size(sz_70 + id_24) };
      let_res_21 = id_25;
    }
    return let_res_21;
  }
   };
  return fun12;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier site_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_59" (apply (ext-identifier program_name of-row-binary) (identifier "drec_snd_58"))
            (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
              (let-pair "drec_fst_63" "drec_snd_64" (apply (ext-identifier function_name of-row-binary) (identifier "drec_snd_61"))
                (make-tup (make-rec (string "site") (identifier "drec_fst_57") (string "program") (identifier "drec_fst_60") (string "function") (identifier "drec_fst_63")) (identifier "drec_snd_64"))))))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun26 { [&fun26](Pointer p_0) {
    std::function<ddf7cb48181332ead2f60a5f4bb1a8de(Pointer)> id_27 { dessser_gen::site_name.of_row_binary };
    ddf7cb48181332ead2f60a5f4bb1a8de id_28 { id_27(p_0) };
    f63f919559f0d70225bd0da5dd9bcafc let_res_29;
    {
      ddf7cb48181332ead2f60a5f4bb1a8de drec_56 { id_28 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_30;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        std::function<f6e2f55e3ebc4a068d1f568f5860423e(Pointer)> id_31 { dessser_gen::program_name.of_row_binary };
        f6e2f55e3ebc4a068d1f568f5860423e id_32 { id_31(drec_snd_58) };
        f63f919559f0d70225bd0da5dd9bcafc let_res_33;
        {
          f6e2f55e3ebc4a068d1f568f5860423e drec_59 { id_32 };
          f63f919559f0d70225bd0da5dd9bcafc letpair_res_34;
          {
            auto drec_fst_60 { std::get<0>(drec_59) };
            auto drec_snd_61 { std::get<1>(drec_59) };
            std::function<v_382b80697fdeb5158d298be4e9fcf65e(Pointer)> id_35 { dessser_gen::function_name.of_row_binary };
            v_382b80697fdeb5158d298be4e9fcf65e id_36 { id_35(drec_snd_61) };
            f63f919559f0d70225bd0da5dd9bcafc letpair_res_37;
            {
              auto drec_fst_63 { std::get<0>(id_36) };
              auto drec_snd_64 { std::get<1>(id_36) };
              t id_38 {  .site = drec_fst_57, .program = drec_fst_60, .function = drec_fst_63  };
              f63f919559f0d70225bd0da5dd9bcafc id_39 {  id_38, drec_snd_64  };
              letpair_res_37 = id_39;
            }
            letpair_res_34 = letpair_res_37;
          }
          let_res_33 = letpair_res_34;
        }
        letpair_res_30 = let_res_33;
      }
      let_res_29 = letpair_res_30;
    }
    return let_res_29;
  }
   };
  return fun26;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
