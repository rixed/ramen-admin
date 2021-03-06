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
#include "desssergen/field_name.h"

namespace dessser::gen::raql_path_comp {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  uint32_t, // Idx
  dessser::gen::field_name::t_ext // Name
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Idx
    case 1: return ::dessser::gen::field_name::Deref(std::get<1>(a)) == ::dessser::gen::field_name::Deref(std::get<1>(b)); // Name
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t44f64b18392159636d8c1413aca19b57 : public std::tuple<
  ::dessser::gen::raql_path_comp::t,
  Pointer
> {
  using tuple::tuple;
  t44f64b18392159636d8c1413aca19b57(std::tuple<::dessser::gen::raql_path_comp::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_path_comp::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t44f64b18392159636d8c1413aca19b57 const &a, t44f64b18392159636d8c1413aca19b57 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t44f64b18392159636d8c1413aca19b57 const &a, t44f64b18392159636d8c1413aca19b57 const &b) {
  return !operator==(a, b);
}
struct ta97bb48ed75bbda6173555873826c8c6 : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  ta97bb48ed75bbda6173555873826c8c6(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return !operator==(a, b);
}
struct t491c44439106a32f896827242e8e76a1 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t491c44439106a32f896827242e8e76a1(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Idx U32 | Name $field_name]" "Ptr")
      (let "ssum_dst_80" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (write-u32 little-endian (identifier "ssum_dst_80") (get-alt "Idx" (param 0)))
          (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (ext-identifier field_name to-row-binary) (get-alt "Name" (param 0)) (identifier "ssum_dst_80"))))))
 */
static std::function<Pointer(::dessser::gen::raql_path_comp::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_path_comp::t &,Pointer &)> fun0 { [&](::dessser::gen::raql_path_comp::t p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0.index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_80 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0.index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        uint32_t id_8 { std::get<0 /* Idx */>(p_0) };
        Pointer id_9 { ssum_dst_80.writeU32Le(id_8) };
        choose_res_7 = id_9;
      } else {
        uint16_t id_10 { uint16_t(p_0.index()) };
        uint16_t id_11 { 1 };
        bool id_12 { bool(id_10 == id_11) };
        Void id_13 { ((void)(assert(id_12)), ::dessser::Void()) };
        (void)id_13;
        auto fun14 { dessser::gen::field_name::to_row_binary };
        dessser::gen::field_name::t_ext id_15 { std::get<1 /* Name */>(p_0) };
        Pointer id_16 { fun14(id_15, ssum_dst_80) };
        choose_res_7 = id_16;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::raql_path_comp::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Idx U32 | Name $field_name]")
      (if (eq (u16 0) (label-of (param 0))) (size 6) (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (ext-identifier field_name sersize-of-row-binary) (get-alt "Name" (param 0)))))))
 */
static std::function<Size(::dessser::gen::raql_path_comp::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_path_comp::t &)> fun17 { [&](::dessser::gen::raql_path_comp::t p_0) {
    uint16_t id_18 { 0 };
    uint16_t id_19 { uint16_t(p_0.index()) };
    bool id_20 { bool(id_18 == id_19) };
    Size choose_res_21;
    if (id_20) {
      Size id_22 { 6UL };
      choose_res_21 = id_22;
    } else {
      uint16_t id_23 { uint16_t(p_0.index()) };
      uint16_t id_24 { 1 };
      bool id_25 { bool(id_23 == id_24) };
      Void id_26 { ((void)(assert(id_25)), ::dessser::Void()) };
      (void)id_26;
      Size id_27 { 2UL };
      auto fun28 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_29 { std::get<1 /* Name */>(p_0) };
      Size id_30 { fun28(id_29) };
      Size id_31 { Size(id_27 + id_30) };
      choose_res_21 = id_31;
    }
    return choose_res_21;
  }
   };
  return fun17;
}
std::function<Size(::dessser::gen::raql_path_comp::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (let-pair "du32_fst_70" "du32_snd_71" (read-u32 little-endian (identifier "dsum1_snd_65")) (make-tup (construct "[Idx U32 | Name $field_name]" 0 (identifier "du32_fst_70")) (identifier "du32_snd_71")))
            (seq (assert (eq (identifier "dsum1_fst_64") (u16 1)))
              (let-pair "dsum2_fst_67" "dsum2_snd_68" (apply (ext-identifier field_name of-row-binary) (identifier "dsum1_snd_65"))
                (make-tup (construct "[Idx U32 | Name $field_name]" 1 (identifier "dsum2_fst_67")) (identifier "dsum2_snd_68"))))))))
 */
static std::function<::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57(Pointer &)> fun32 { [&](Pointer p_0) {
    ::dessser::gen::raql_path_comp::ta97bb48ed75bbda6173555873826c8c6 id_33 { p_0.readU16Le() };
    ::dessser::gen::raql_path_comp::ta97bb48ed75bbda6173555873826c8c6 letpair_res_34;
    {
      auto du16_fst_58 { std::get<0>(id_33) };
      auto du16_snd_59 { std::get<1>(id_33) };
      ::dessser::gen::raql_path_comp::ta97bb48ed75bbda6173555873826c8c6 id_35 { du16_fst_58, du16_snd_59 };
      letpair_res_34 = id_35;
    }
    ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 let_res_36;
    {
      ::dessser::gen::raql_path_comp::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_34 };
      ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 letpair_res_37;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_38 { 0 };
        bool id_39 { bool(id_38 == dsum1_fst_64) };
        ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 choose_res_40;
        if (id_39) {
          ::dessser::gen::raql_path_comp::t491c44439106a32f896827242e8e76a1 id_41 { dsum1_snd_65.readU32Le() };
          ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 letpair_res_42;
          {
            auto du32_fst_70 { std::get<0>(id_41) };
            auto du32_snd_71 { std::get<1>(id_41) };
            ::dessser::gen::raql_path_comp::t id_43 { std::in_place_index<0>, du32_fst_70 };
            ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 id_44 { id_43, du32_snd_71 };
            letpair_res_42 = id_44;
          }
          choose_res_40 = letpair_res_42;
        } else {
          uint16_t id_45 { 1 };
          bool id_46 { bool(dsum1_fst_64 == id_45) };
          Void id_47 { ((void)(assert(id_46)), ::dessser::Void()) };
          (void)id_47;
          auto fun48 { dessser::gen::field_name::of_row_binary };
          ::dessser::gen::raql_path_comp::t18cecf882d7ac80cef37dfe6b22279d4 id_49 { fun48(dsum1_snd_65) };
          ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 letpair_res_50;
          {
            auto dsum2_fst_67 { std::get<0>(id_49) };
            auto dsum2_snd_68 { std::get<1>(id_49) };
            ::dessser::gen::raql_path_comp::t id_51 { std::in_place_index<1>, dsum2_fst_67 };
            ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 id_52 { id_51, dsum2_snd_68 };
            letpair_res_50 = id_52;
          }
          choose_res_40 = letpair_res_50;
        }
        letpair_res_37 = choose_res_40;
      }
      let_res_36 = letpair_res_37;
    }
    return let_res_36;
  }
   };
  return fun32;
}
std::function<::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_76" "make_snd_77" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_76") (identifier "make_snd_77"))))
 */
static std::function<::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57(Pointer &)> fun53 { [&](Pointer p_0) {
    ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 id_54 { of_row_binary(p_0) };
    ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 letpair_res_55;
    {
      auto make_fst_76 { std::get<0>(id_54) };
      auto make_snd_77 { std::get<1>(id_54) };
      ::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57 id_56 { make_fst_76, make_snd_77 };
      letpair_res_55 = id_56;
    }
    return letpair_res_55;
  }
   };
  return fun53;
}
std::function<::dessser::gen::raql_path_comp::t44f64b18392159636d8c1413aca19b57(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[Idx U32 | Name $field_name]" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::raql_path_comp::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_path_comp::t &,Pointer &)> fun57 { [&](::dessser::gen::raql_path_comp::t p_0, Pointer p_1) {
    Pointer id_58 { to_row_binary(p_0, p_1) };
    return id_58;
  }
   };
  return fun57;
}
std::function<Pointer(::dessser::gen::raql_path_comp::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
