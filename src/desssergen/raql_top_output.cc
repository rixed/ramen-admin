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

namespace dessser::gen::raql_top_output {
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
  Void, // Membership
  Void, // Rank
  Void // List
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Membership
    case 1: return std::get<1>(a) == std::get<1>(b); // Rank
    case 2: return std::get<2>(a) == std::get<2>(b); // List
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t39fed1293271e7460d2b7f31b53fc49c : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_top_output::t> ,
  Pointer
> {
  using tuple::tuple;
  t39fed1293271e7460d2b7f31b53fc49c(std::tuple<std::shared_ptr<::dessser::gen::raql_top_output::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_top_output::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t39fed1293271e7460d2b7f31b53fc49c const &a, t39fed1293271e7460d2b7f31b53fc49c const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t39fed1293271e7460d2b7f31b53fc49c const &a, t39fed1293271e7460d2b7f31b53fc49c const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Membership Void | Rank Void | List Void]" "Ptr")
      (let "ssum_dst_80" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_80") (if (eq (u16 1) (label-of (param 0))) (identifier "ssum_dst_80") (seq (assert (eq (label-of (param 0)) (u16 2))) (identifier "ssum_dst_80"))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_top_output::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_top_output::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::raql_top_output::t>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_80 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_80;
      } else {
        uint16_t id_8 { 1 };
        uint16_t id_9 { uint16_t((*p_0).index()) };
        bool id_10 { bool(id_8 == id_9) };
        Pointer choose_res_11;
        if (id_10) {
          choose_res_11 = ssum_dst_80;
        } else {
          uint16_t id_12 { uint16_t((*p_0).index()) };
          uint16_t id_13 { 2 };
          bool id_14 { bool(id_12 == id_13) };
          Void id_15 { ((void)(assert(id_14)), ::dessser::VOID) };
          (void)id_15;
          choose_res_11 = ssum_dst_80;
        }
        choose_res_7 = choose_res_11;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_top_output::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Membership Void | Rank Void | List Void]") (if (eq (u16 0) (label-of (param 0))) (size 2) (if (eq (u16 1) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 2))) (size 2)))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_top_output::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_top_output::t> )> fun16 { [&](std::shared_ptr<::dessser::gen::raql_top_output::t>  p_0) {
    uint16_t id_17 { 0 };
    uint16_t id_18 { uint16_t((*p_0).index()) };
    bool id_19 { bool(id_17 == id_18) };
    Size choose_res_20;
    if (id_19) {
      Size id_21 { 2UL };
      choose_res_20 = id_21;
    } else {
      uint16_t id_22 { 1 };
      uint16_t id_23 { uint16_t((*p_0).index()) };
      bool id_24 { bool(id_22 == id_23) };
      Size choose_res_25;
      if (id_24) {
        Size id_26 { 2UL };
        choose_res_25 = id_26;
      } else {
        uint16_t id_27 { uint16_t((*p_0).index()) };
        uint16_t id_28 { 2 };
        bool id_29 { bool(id_27 == id_28) };
        Void id_30 { ((void)(assert(id_29)), ::dessser::VOID) };
        (void)id_30;
        Size id_31 { 2UL };
        choose_res_25 = id_31;
      }
      choose_res_20 = choose_res_25;
    }
    return choose_res_20;
  }
   };
  return fun16;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_top_output::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64")) (make-tup (construct "[Membership Void | Rank Void | List Void]" 0 (nop)) (identifier "dsum1_snd_65"))
            (if (eq (u16 1) (identifier "dsum1_fst_64")) (make-tup (construct "[Membership Void | Rank Void | List Void]" 1 (nop)) (identifier "dsum1_snd_65"))
              (seq (assert (eq (identifier "dsum1_fst_64") (u16 2))) (make-tup (construct "[Membership Void | Rank Void | List Void]" 2 (nop)) (identifier "dsum1_snd_65"))))))))
 */
static std::function<::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c(Pointer)> fun32 { [&](Pointer p_0) {
    ::dessser::gen::raql_top_output::ta97bb48ed75bbda6173555873826c8c6 id_33 { p_0.readU16Le() };
    ::dessser::gen::raql_top_output::ta97bb48ed75bbda6173555873826c8c6 letpair_res_34;
    {
      auto du16_fst_58 { std::get<0>(id_33) };
      auto du16_snd_59 { std::get<1>(id_33) };
      ::dessser::gen::raql_top_output::ta97bb48ed75bbda6173555873826c8c6 id_35 { du16_fst_58, du16_snd_59 };
      letpair_res_34 = id_35;
    }
    ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c let_res_36;
    {
      ::dessser::gen::raql_top_output::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_34 };
      ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c letpair_res_37;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_38 { 0 };
        bool id_39 { bool(id_38 == dsum1_fst_64) };
        ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c choose_res_40;
        if (id_39) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::raql_top_output::t>  id_41 { std::make_shared<::dessser::gen::raql_top_output::t>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c id_42 { id_41, dsum1_snd_65 };
          choose_res_40 = id_42;
        } else {
          uint16_t id_43 { 1 };
          bool id_44 { bool(id_43 == dsum1_fst_64) };
          ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c choose_res_45;
          if (id_44) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::raql_top_output::t>  id_46 { std::make_shared<::dessser::gen::raql_top_output::t>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c id_47 { id_46, dsum1_snd_65 };
            choose_res_45 = id_47;
          } else {
            uint16_t id_48 { 2 };
            bool id_49 { bool(dsum1_fst_64 == id_48) };
            Void id_50 { ((void)(assert(id_49)), ::dessser::VOID) };
            (void)id_50;
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::raql_top_output::t>  id_51 { std::make_shared<::dessser::gen::raql_top_output::t>(std::in_place_index<2>, ::dessser::VOID) };
            ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c id_52 { id_51, dsum1_snd_65 };
            choose_res_45 = id_52;
          }
          choose_res_40 = choose_res_45;
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
std::function<::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_76" "make_snd_77" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_76") (identifier "make_snd_77"))))
 */
static std::function<::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c(Pointer)> fun53 { [&](Pointer p_0) {
    ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c id_54 { of_row_binary(p_0) };
    ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c letpair_res_55;
    {
      auto make_fst_76 { std::get<0>(id_54) };
      auto make_snd_77 { std::get<1>(id_54) };
      ::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c id_56 { make_fst_76, make_snd_77 };
      letpair_res_55 = id_56;
    }
    return letpair_res_55;
  }
   };
  return fun53;
}
std::function<::dessser::gen::raql_top_output::t39fed1293271e7460d2b7f31b53fc49c(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[Membership Void | Rank Void | List Void]" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_top_output::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_top_output::t> ,Pointer)> fun57 { [&](std::shared_ptr<::dessser::gen::raql_top_output::t>  p_0, Pointer p_1) {
    Pointer id_58 { to_row_binary(p_0, p_1) };
    return id_58;
  }
   };
  return fun57;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_top_output::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
