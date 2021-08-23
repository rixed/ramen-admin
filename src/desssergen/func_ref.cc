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
#include "desssergen/function_name.h"
#include "desssergen/program_name.h"
#include "desssergen/site_name.h"


namespace dessser::gen::func_ref {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::function_name::t_ext func;
  dessser::gen::program_name::t_ext program;
  dessser::gen::site_name::t_ext site;
  bool operator==(t const &other) const {
    return func == other.func && program == other.program && site == other.site;
  }
};
typedef std::tuple<
  ::dessser::gen::func_ref::t*,
  Pointer
> tffa98ef3b236ed523827b79a069afe00;

typedef std::tuple<
  dessser::gen::site_name::t_ext,
  Pointer
> tb31a43e42345099d489759a9c141b1b9;

typedef std::tuple<
  dessser::gen::program_name::t_ext,
  Pointer
> tb2e42d4897c18582b07eacd83dd7412d;

typedef std::tuple<
  dessser::gen::function_name::t_ext,
  Pointer
> tc7d3fcfd06c0f02b3732e1754a18402b;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{site: $site_name; program: $program_name; func: $function_name}" "Ptr")
      (let "srec_dst_72"
        (let "srec_dst_71" (apply (ext-identifier site_name to-row-binary) (get-field "site" (param 0)) (param 1)) (apply (ext-identifier program_name to-row-binary) (get-field "program" (param 0)) (identifier "srec_dst_71")))
        (apply (ext-identifier function_name to-row-binary) (get-field "func" (param 0)) (identifier "srec_dst_72"))))
 */
static std::function<Pointer(::dessser::gen::func_ref::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::func_ref::t*,Pointer)> fun0 { [&fun0](::dessser::gen::func_ref::t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::site_name::to_row_binary };
    dessser::gen::site_name::t_ext id_2 { p_0->site };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_71 { id_3 };
      auto fun5 { dessser::gen::program_name::to_row_binary };
      dessser::gen::program_name::t_ext id_6 { p_0->program };
      Pointer id_7 { fun5(id_6, srec_dst_71) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_72 { let_res_4 };
      auto fun9 { dessser::gen::function_name::to_row_binary };
      dessser::gen::function_name::t_ext id_10 { p_0->func };
      Pointer id_11 { fun9(id_10, srec_dst_72) };
      let_res_8 = id_11;
    }
    return let_res_8;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::func_ref::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{site: $site_name; program: $program_name; func: $function_name}")
      (let "sz_70"
        (let "sz_69" (apply (ext-identifier site_name sersize-of-row-binary) (get-field "site" (param 0))) (add (identifier "sz_69") (apply (ext-identifier program_name sersize-of-row-binary) (get-field "program" (param 0)))))
        (add (identifier "sz_70") (apply (ext-identifier function_name sersize-of-row-binary) (get-field "func" (param 0))))))
 */
static std::function<Size(::dessser::gen::func_ref::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::func_ref::t*)> fun12 { [&fun12](::dessser::gen::func_ref::t* p_0) {
    auto fun13 { dessser::gen::site_name::sersize_of_row_binary };
    dessser::gen::site_name::t_ext id_14 { p_0->site };
    Size id_15 { fun13(id_14) };
    Size let_res_16;
    {
      Size sz_69 { id_15 };
      auto fun17 { dessser::gen::program_name::sersize_of_row_binary };
      dessser::gen::program_name::t_ext id_18 { p_0->program };
      Size id_19 { fun17(id_18) };
      Size id_20 { Size(sz_69 + id_19) };
      let_res_16 = id_20;
    }
    Size let_res_21;
    {
      Size sz_70 { let_res_16 };
      auto fun22 { dessser::gen::function_name::sersize_of_row_binary };
      dessser::gen::function_name::t_ext id_23 { p_0->func };
      Size id_24 { fun22(id_23) };
      Size id_25 { Size(sz_70 + id_24) };
      let_res_21 = id_25;
    }
    return let_res_21;
  }
   };
  return fun12;
}
std::function<Size(::dessser::gen::func_ref::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier site_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_59" (apply (ext-identifier program_name of-row-binary) (identifier "drec_snd_58"))
            (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
              (let-pair "drec_fst_63" "drec_snd_64" (apply (ext-identifier function_name of-row-binary) (identifier "drec_snd_61"))
                (make-tup (make-rec (string "func") (identifier "drec_fst_63") (string "program") (identifier "drec_fst_60") (string "site") (identifier "drec_fst_57")) (identifier "drec_snd_64"))))))))
 */
static std::function<::dessser::gen::func_ref::tffa98ef3b236ed523827b79a069afe00(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::func_ref::tffa98ef3b236ed523827b79a069afe00(Pointer)> fun26 { [&fun26](Pointer p_0) {
    auto fun27 { dessser::gen::site_name::of_row_binary };
    ::dessser::gen::func_ref::tb31a43e42345099d489759a9c141b1b9 id_28 { fun27(p_0) };
    ::dessser::gen::func_ref::tffa98ef3b236ed523827b79a069afe00 let_res_29;
    {
      ::dessser::gen::func_ref::tb31a43e42345099d489759a9c141b1b9 drec_56 { id_28 };
      ::dessser::gen::func_ref::tffa98ef3b236ed523827b79a069afe00 letpair_res_30;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        auto fun31 { dessser::gen::program_name::of_row_binary };
        ::dessser::gen::func_ref::tb2e42d4897c18582b07eacd83dd7412d id_32 { fun31(drec_snd_58) };
        ::dessser::gen::func_ref::tffa98ef3b236ed523827b79a069afe00 let_res_33;
        {
          ::dessser::gen::func_ref::tb2e42d4897c18582b07eacd83dd7412d drec_59 { id_32 };
          ::dessser::gen::func_ref::tffa98ef3b236ed523827b79a069afe00 letpair_res_34;
          {
            auto drec_fst_60 { std::get<0>(drec_59) };
            auto drec_snd_61 { std::get<1>(drec_59) };
            auto fun35 { dessser::gen::function_name::of_row_binary };
            ::dessser::gen::func_ref::tc7d3fcfd06c0f02b3732e1754a18402b id_36 { fun35(drec_snd_61) };
            ::dessser::gen::func_ref::tffa98ef3b236ed523827b79a069afe00 letpair_res_37;
            {
              auto drec_fst_63 { std::get<0>(id_36) };
              auto drec_snd_64 { std::get<1>(id_36) };
              ::dessser::gen::func_ref::t* id_38 { new ::dessser::gen::func_ref::t({ .func = drec_fst_63, .program = drec_fst_60, .site = drec_fst_57 }) };
              ::dessser::gen::func_ref::tffa98ef3b236ed523827b79a069afe00 id_39 { id_38, drec_snd_64 };
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
std::function<::dessser::gen::func_ref::tffa98ef3b236ed523827b79a069afe00(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
