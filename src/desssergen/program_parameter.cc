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
#include "desssergen/raql_value.h"
#include "desssergen/field_type.h"


namespace dessser::gen::program_parameter {
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
  dessser::gen::field_type::t_ext ptyp;
  dessser::gen::raql_value::t_ext value;
  t(dessser::gen::field_type::t_ext ptyp_, dessser::gen::raql_value::t_ext value_) : ptyp(ptyp_), value(value_) {}
  t() = default;
};
typedef std::tuple<
  ::dessser::gen::program_parameter::t*,
  Pointer
> t571f6c411143ec709060fca7e7f9ac08;

typedef std::tuple<
  dessser::gen::field_type::t_ext,
  Pointer
> t2f09fa79b0bdf1902e3b53bc7e485604;

typedef std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> t9cfa78b25ddcb5afc14daf6a802a6f88;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{ptyp: $field_type; value: $raql_value}" "Ptr")
      (let "srec_dst_67" (apply (ext-identifier field_type to-row-binary) (get-field "ptyp" (param 0)) (param 1)) (apply (ext-identifier raql_value to-row-binary) (get-field "value" (param 0)) (identifier "srec_dst_67"))))
 */
static std::function<Pointer(::dessser::gen::program_parameter::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::program_parameter::t*,Pointer)> fun0 { [&fun0](::dessser::gen::program_parameter::t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_type::to_row_binary };
    dessser::gen::field_type::t_ext id_2 { (*p_0).ptyp };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_67 { id_3 };
      auto fun5 { dessser::gen::raql_value::to_row_binary };
      dessser::gen::raql_value::t_ext id_6 { (*p_0).value };
      Pointer id_7 { fun5(id_6, srec_dst_67) };
      let_res_4 = id_7;
    }
    return let_res_4;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::program_parameter::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{ptyp: $field_type; value: $raql_value}")
      (let "sz_66" (apply (ext-identifier field_type sersize-of-row-binary) (get-field "ptyp" (param 0))) (add (identifier "sz_66") (apply (ext-identifier raql_value sersize-of-row-binary) (get-field "value" (param 0))))))
 */
static std::function<Size(::dessser::gen::program_parameter::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::program_parameter::t*)> fun8 { [&fun8](::dessser::gen::program_parameter::t* p_0) {
    auto fun9 { dessser::gen::field_type::sersize_of_row_binary };
    dessser::gen::field_type::t_ext id_10 { (*p_0).ptyp };
    Size id_11 { fun9(id_10) };
    Size let_res_12;
    {
      Size sz_66 { id_11 };
      auto fun13 { dessser::gen::raql_value::sersize_of_row_binary };
      dessser::gen::raql_value::t_ext id_14 { (*p_0).value };
      Size id_15 { fun13(id_14) };
      Size id_16 { Size(sz_66 + id_15) };
      let_res_12 = id_16;
    }
    return let_res_12;
  }
   };
  return fun8;
}
std::function<Size(::dessser::gen::program_parameter::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier field_type of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let-pair "drec_fst_60" "drec_snd_61" (apply (ext-identifier raql_value of-row-binary) (identifier "drec_snd_58"))
            (make-tup (make-rec (string "value") (identifier "drec_fst_60") (string "ptyp") (identifier "drec_fst_57")) (identifier "drec_snd_61"))))))
 */
static std::function<::dessser::gen::program_parameter::t571f6c411143ec709060fca7e7f9ac08(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::program_parameter::t571f6c411143ec709060fca7e7f9ac08(Pointer)> fun17 { [&fun17](Pointer p_0) {
    auto fun18 { dessser::gen::field_type::of_row_binary };
    ::dessser::gen::program_parameter::t2f09fa79b0bdf1902e3b53bc7e485604 id_19 { fun18(p_0) };
    ::dessser::gen::program_parameter::t571f6c411143ec709060fca7e7f9ac08 let_res_20;
    {
      ::dessser::gen::program_parameter::t2f09fa79b0bdf1902e3b53bc7e485604 drec_56 { id_19 };
      ::dessser::gen::program_parameter::t571f6c411143ec709060fca7e7f9ac08 letpair_res_21;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        auto fun22 { dessser::gen::raql_value::of_row_binary };
        ::dessser::gen::program_parameter::t9cfa78b25ddcb5afc14daf6a802a6f88 id_23 { fun22(drec_snd_58) };
        ::dessser::gen::program_parameter::t571f6c411143ec709060fca7e7f9ac08 letpair_res_24;
        {
          auto drec_fst_60 { std::get<0>(id_23) };
          auto drec_snd_61 { std::get<1>(id_23) };
          ::dessser::gen::program_parameter::t* id_25 { new ::dessser::gen::program_parameter::t({ .ptyp = drec_fst_57, .value = drec_fst_60 }) };
          ::dessser::gen::program_parameter::t571f6c411143ec709060fca7e7f9ac08 id_26 { id_25, drec_snd_61 };
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
std::function<::dessser::gen::program_parameter::t571f6c411143ec709060fca7e7f9ac08(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
