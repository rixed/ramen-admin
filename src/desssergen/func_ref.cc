#include <algorithm>
#include <charconv>  // for from_chars
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
  dessser::gen::site_name::t_ext site;
  dessser::gen::program_name::t_ext program;
  dessser::gen::function_name::t_ext func;
  t(dessser::gen::site_name::t_ext site_, dessser::gen::program_name::t_ext program_, dessser::gen::function_name::t_ext func_) : site(site_), program(program_), func(func_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site) && ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && ::dessser::gen::function_name::Deref(a.func) == ::dessser::gen::function_name::Deref(b.func);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct taa1ea876bd3405a61d941fe18b62be03 : public std::tuple<
  std::shared_ptr<::dessser::gen::func_ref::t> ,
  Pointer
> {
  using tuple::tuple;
  taa1ea876bd3405a61d941fe18b62be03(std::tuple<std::shared_ptr<::dessser::gen::func_ref::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::func_ref::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(taa1ea876bd3405a61d941fe18b62be03 const &a, taa1ea876bd3405a61d941fe18b62be03 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(taa1ea876bd3405a61d941fe18b62be03 const &a, taa1ea876bd3405a61d941fe18b62be03 const &b) {
  return !operator==(a, b);
}
struct t5fda3fa18a9129079240e343cc4c7827 : public std::tuple<
  dessser::gen::site_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t5fda3fa18a9129079240e343cc4c7827(std::tuple<dessser::gen::site_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::site_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5fda3fa18a9129079240e343cc4c7827 const &a, t5fda3fa18a9129079240e343cc4c7827 const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5fda3fa18a9129079240e343cc4c7827 const &a, t5fda3fa18a9129079240e343cc4c7827 const &b) {
  return !operator==(a, b);
}
struct td8645decacfa82d2239ee8ec2f67634c : public std::tuple<
  dessser::gen::program_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  td8645decacfa82d2239ee8ec2f67634c(std::tuple<dessser::gen::program_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::program_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td8645decacfa82d2239ee8ec2f67634c const &a, td8645decacfa82d2239ee8ec2f67634c const &b) {
  return ::dessser::gen::program_name::Deref(std::get<0>(a)) == ::dessser::gen::program_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td8645decacfa82d2239ee8ec2f67634c const &a, td8645decacfa82d2239ee8ec2f67634c const &b) {
  return !operator==(a, b);
}
struct t7ced0f6935c1265b26e1abfcc364f52e : public std::tuple<
  dessser::gen::function_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t7ced0f6935c1265b26e1abfcc364f52e(std::tuple<dessser::gen::function_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::function_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7ced0f6935c1265b26e1abfcc364f52e const &a, t7ced0f6935c1265b26e1abfcc364f52e const &b) {
  return ::dessser::gen::function_name::Deref(std::get<0>(a)) == ::dessser::gen::function_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7ced0f6935c1265b26e1abfcc364f52e const &a, t7ced0f6935c1265b26e1abfcc364f52e const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{site: $site_name; program: $program_name; func: $function_name}" "Ptr")
      (let "srec_dst_73"
        (let "srec_dst_72" (apply (ext-identifier site_name to-row-binary) (get-field "site" (param 0)) (param 1)) (apply (ext-identifier program_name to-row-binary) (get-field "program" (param 0)) (identifier "srec_dst_72")))
        (apply (ext-identifier function_name to-row-binary) (get-field "func" (param 0)) (identifier "srec_dst_73"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::func_ref::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::func_ref::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::func_ref::t>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::site_name::to_row_binary };
    dessser::gen::site_name::t_ext id_2 { (*p_0).site };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_72 { id_3 };
      auto fun5 { dessser::gen::program_name::to_row_binary };
      dessser::gen::program_name::t_ext id_6 { (*p_0).program };
      Pointer id_7 { fun5(id_6, srec_dst_72) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_73 { let_res_4 };
      auto fun9 { dessser::gen::function_name::to_row_binary };
      dessser::gen::function_name::t_ext id_10 { (*p_0).func };
      Pointer id_11 { fun9(id_10, srec_dst_73) };
      let_res_8 = id_11;
    }
    return let_res_8;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::func_ref::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{site: $site_name; program: $program_name; func: $function_name}")
      (let "sz_71"
        (let "sz_70" (apply (ext-identifier site_name sersize-of-row-binary) (get-field "site" (param 0))) (add (identifier "sz_70") (apply (ext-identifier program_name sersize-of-row-binary) (get-field "program" (param 0)))))
        (add (identifier "sz_71") (apply (ext-identifier function_name sersize-of-row-binary) (get-field "func" (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::func_ref::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::func_ref::t> )> fun12 { [&](std::shared_ptr<::dessser::gen::func_ref::t>  p_0) {
    auto fun13 { dessser::gen::site_name::sersize_of_row_binary };
    dessser::gen::site_name::t_ext id_14 { (*p_0).site };
    Size id_15 { fun13(id_14) };
    Size let_res_16;
    {
      Size sz_70 { id_15 };
      auto fun17 { dessser::gen::program_name::sersize_of_row_binary };
      dessser::gen::program_name::t_ext id_18 { (*p_0).program };
      Size id_19 { fun17(id_18) };
      Size id_20 { Size(sz_70 + id_19) };
      let_res_16 = id_20;
    }
    Size let_res_21;
    {
      Size sz_71 { let_res_16 };
      auto fun22 { dessser::gen::function_name::sersize_of_row_binary };
      dessser::gen::function_name::t_ext id_23 { (*p_0).func };
      Size id_24 { fun22(id_23) };
      Size id_25 { Size(sz_71 + id_24) };
      let_res_21 = id_25;
    }
    return let_res_21;
  }
   };
  return fun12;
}
std::function<Size(std::shared_ptr<::dessser::gen::func_ref::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_57" (apply (ext-identifier site_name of-row-binary) (param 0))
        (let-pair "drec_fst_58" "drec_snd_59" (identifier "drec_57")
          (let "drec_60" (apply (ext-identifier program_name of-row-binary) (identifier "drec_snd_59"))
            (let-pair "drec_fst_61" "drec_snd_62" (identifier "drec_60")
              (let-pair "drec_fst_64" "drec_snd_65" (apply (ext-identifier function_name of-row-binary) (identifier "drec_snd_62"))
                (make-tup (make-rec (string "func") (identifier "drec_fst_64") (string "program") (identifier "drec_fst_61") (string "site") (identifier "drec_fst_58")) (identifier "drec_snd_65"))))))))
 */
static std::function<::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03(Pointer)> fun26 { [&](Pointer p_0) {
    auto fun27 { dessser::gen::site_name::of_row_binary };
    ::dessser::gen::func_ref::t5fda3fa18a9129079240e343cc4c7827 id_28 { fun27(p_0) };
    ::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03 let_res_29;
    {
      ::dessser::gen::func_ref::t5fda3fa18a9129079240e343cc4c7827 drec_57 { id_28 };
      ::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03 letpair_res_30;
      {
        auto drec_fst_58 { std::get<0>(drec_57) };
        auto drec_snd_59 { std::get<1>(drec_57) };
        auto fun31 { dessser::gen::program_name::of_row_binary };
        ::dessser::gen::func_ref::td8645decacfa82d2239ee8ec2f67634c id_32 { fun31(drec_snd_59) };
        ::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03 let_res_33;
        {
          ::dessser::gen::func_ref::td8645decacfa82d2239ee8ec2f67634c drec_60 { id_32 };
          ::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03 letpair_res_34;
          {
            auto drec_fst_61 { std::get<0>(drec_60) };
            auto drec_snd_62 { std::get<1>(drec_60) };
            auto fun35 { dessser::gen::function_name::of_row_binary };
            ::dessser::gen::func_ref::t7ced0f6935c1265b26e1abfcc364f52e id_36 { fun35(drec_snd_62) };
            ::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03 letpair_res_37;
            {
              auto drec_fst_64 { std::get<0>(id_36) };
              auto drec_snd_65 { std::get<1>(id_36) };
              std::shared_ptr<::dessser::gen::func_ref::t>  id_38 { std::make_shared<::dessser::gen::func_ref::t>(drec_fst_58, drec_fst_61, drec_fst_64) };
              ::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03 id_39 { id_38, drec_snd_65 };
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
std::function<::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_67" "make_snd_68" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_67") (identifier "make_snd_68"))))
 */
static std::function<::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03(Pointer)> fun40 { [&](Pointer p_0) {
    ::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03 id_41 { of_row_binary(p_0) };
    ::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03 letpair_res_42;
    {
      auto make_fst_67 { std::get<0>(id_41) };
      auto make_snd_68 { std::get<1>(id_41) };
      ::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03 id_43 { make_fst_67, make_snd_68 };
      letpair_res_42 = id_43;
    }
    return letpair_res_42;
  }
   };
  return fun40;
}
std::function<::dessser::gen::func_ref::taa1ea876bd3405a61d941fe18b62be03(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{site: $site_name; program: $program_name; func: $function_name}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::func_ref::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::func_ref::t> ,Pointer)> fun44 { [&](std::shared_ptr<::dessser::gen::func_ref::t>  p_0, Pointer p_1) {
    Pointer id_45 { to_row_binary(p_0, p_1) };
    return id_45;
  }
   };
  return fun44;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::func_ref::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
