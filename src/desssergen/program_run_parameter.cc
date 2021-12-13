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
#include "desssergen/field_name.h"

namespace dessser::gen::program_run_parameter {
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
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_value::t_ext value;
  t(dessser::gen::field_name::t_ext name_, dessser::gen::raql_value::t_ext value_) : name(name_), value(value_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_value::Deref(a.value) == ::dessser::gen::raql_value::Deref(b.value);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t62c3c742c99d7c40e6f6e70698ba71a5 : public std::tuple<
  std::shared_ptr<::dessser::gen::program_run_parameter::t> ,
  Pointer
> {
  using tuple::tuple;
  t62c3c742c99d7c40e6f6e70698ba71a5(std::tuple<std::shared_ptr<::dessser::gen::program_run_parameter::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::program_run_parameter::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t62c3c742c99d7c40e6f6e70698ba71a5 const &a, t62c3c742c99d7c40e6f6e70698ba71a5 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t62c3c742c99d7c40e6f6e70698ba71a5 const &a, t62c3c742c99d7c40e6f6e70698ba71a5 const &b) {
  return !operator==(a, b);
}
struct t18cecf882d7ac80cef37dfe6b22279d4 : public std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t18cecf882d7ac80cef37dfe6b22279d4(std::tuple<dessser::gen::field_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::field_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t18cecf882d7ac80cef37dfe6b22279d4 const &a, t18cecf882d7ac80cef37dfe6b22279d4 const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t18cecf882d7ac80cef37dfe6b22279d4 const &a, t18cecf882d7ac80cef37dfe6b22279d4 const &b) {
  return !operator==(a, b);
}
struct tf3063cfb73e0f06d3ea99ebd15a86d50 : public std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> {
  using tuple::tuple;
  tf3063cfb73e0f06d3ea99ebd15a86d50(std::tuple<dessser::gen::raql_value::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_value::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf3063cfb73e0f06d3ea99ebd15a86d50 const &a, tf3063cfb73e0f06d3ea99ebd15a86d50 const &b) {
  return ::dessser::gen::raql_value::Deref(std::get<0>(a)) == ::dessser::gen::raql_value::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf3063cfb73e0f06d3ea99ebd15a86d50 const &a, tf3063cfb73e0f06d3ea99ebd15a86d50 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{name: $field_name; value: $raql_value}" "Ptr")
      (let "srec_dst_67" (apply (ext-identifier field_name to-row-binary) (get-field "name" (param 0)) (param 1)) (apply (ext-identifier raql_value to-row-binary) (get-field "value" (param 0)) (identifier "srec_dst_67"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::program_run_parameter::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::program_run_parameter::t> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::program_run_parameter::t>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t_ext id_2 { (*p_0).name };
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
std::function<Pointer(std::shared_ptr<::dessser::gen::program_run_parameter::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{name: $field_name; value: $raql_value}")
      (let "sz_66" (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (param 0))) (add (identifier "sz_66") (apply (ext-identifier raql_value sersize-of-row-binary) (get-field "value" (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::program_run_parameter::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::program_run_parameter::t> )> fun8 { [&fun8](std::shared_ptr<::dessser::gen::program_run_parameter::t>  p_0) {
    auto fun9 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t_ext id_10 { (*p_0).name };
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
std::function<Size(std::shared_ptr<::dessser::gen::program_run_parameter::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let-pair "drec_fst_60" "drec_snd_61" (apply (ext-identifier raql_value of-row-binary) (identifier "drec_snd_58"))
            (make-tup (make-rec (string "value") (identifier "drec_fst_60") (string "name") (identifier "drec_fst_57")) (identifier "drec_snd_61"))))))
 */
static std::function<::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5(Pointer)> fun17 { [&fun17](Pointer p_0) {
    auto fun18 { dessser::gen::field_name::of_row_binary };
    ::dessser::gen::program_run_parameter::t18cecf882d7ac80cef37dfe6b22279d4 id_19 { fun18(p_0) };
    ::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5 let_res_20;
    {
      ::dessser::gen::program_run_parameter::t18cecf882d7ac80cef37dfe6b22279d4 drec_56 { id_19 };
      ::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5 letpair_res_21;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        auto fun22 { dessser::gen::raql_value::of_row_binary };
        ::dessser::gen::program_run_parameter::tf3063cfb73e0f06d3ea99ebd15a86d50 id_23 { fun22(drec_snd_58) };
        ::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5 letpair_res_24;
        {
          auto drec_fst_60 { std::get<0>(id_23) };
          auto drec_snd_61 { std::get<1>(id_23) };
          std::shared_ptr<::dessser::gen::program_run_parameter::t>  id_25 { std::make_shared<::dessser::gen::program_run_parameter::t>(drec_fst_57, drec_fst_60) };
          ::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5 id_26 { id_25, drec_snd_61 };
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
std::function<::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_63" "make_snd_64" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_63") (identifier "make_snd_64"))))
 */
static std::function<::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5(Pointer)> fun27 { [&fun27](Pointer p_0) {
    ::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5 id_28 { of_row_binary(p_0) };
    ::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5 letpair_res_29;
    {
      auto make_fst_63 { std::get<0>(id_28) };
      auto make_snd_64 { std::get<1>(id_28) };
      ::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5 id_30 { make_fst_63, make_snd_64 };
      letpair_res_29 = id_30;
    }
    return letpair_res_29;
  }
   };
  return fun27;
}
std::function<::dessser::gen::program_run_parameter::t62c3c742c99d7c40e6f6e70698ba71a5(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{name: $field_name; value: $raql_value}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::program_run_parameter::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::program_run_parameter::t> ,Pointer)> fun31 { [&fun31](std::shared_ptr<::dessser::gen::program_run_parameter::t>  p_0, Pointer p_1) {
    Pointer id_32 { to_row_binary(p_0, p_1) };
    return id_32;
  }
   };
  return fun31;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::program_run_parameter::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
