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

namespace dessser::gen::raql_path_comp {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  uint32_t,
  dessser::gen::field_name::t
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  uint16_t,
  Pointer
> v_362f9d9108a6902af48b6c83d5377ea1;

typedef std::tuple<
  uint32_t,
  Pointer
> ac0fbd05039f742d2f1d9ac182e392ab;

typedef std::tuple<
  dessser::gen::field_name::t,
  Pointer
> c50aa083fa818c6eeca389b0025dda98;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Idx U32 | Name $field_name]" "Ptr")
      (let "ssum_dst_79" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (write-u32 little-endian (identifier "ssum_dst_79") (get-alt "Idx" (param 0)))
          (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (ext-identifier field_name to-row-binary) (get-alt "Name" (param 0)) (identifier "ssum_dst_79"))))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0.index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_79 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0.index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        uint32_t id_8 { std::get<0>(p_0) };
        Pointer id_9 { ssum_dst_79.writeU32Le(id_8) };
        choose_res_7 = id_9;
      } else {
        uint16_t id_10 { uint16_t(p_0.index()) };
        uint16_t id_11 { 1 };
        bool id_12 { bool(id_10 == id_11) };
        Void id_13 { ((void)(assert(id_12)), VOID) };
        std::function<Pointer(dessser::gen::field_name::t,Pointer)> id_14 { dessser::gen::field_name::to_row_binary };
        dessser::gen::field_name::t id_15 { std::get<1>(p_0) };
        Pointer id_16 { id_14(id_15, ssum_dst_79) };
        choose_res_7 = id_16;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Idx U32 | Name $field_name]")
      (if (eq (u16 0) (label-of (param 0))) (size 6) (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (ext-identifier field_name sersize-of-row-binary) (get-alt "Name" (param 0)))))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun17 { [&fun17](t p_0) {
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
      Void id_26 { ((void)(assert(id_25)), VOID) };
      Size id_27 { 2UL };
      std::function<Size(dessser::gen::field_name::t)> id_28 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t id_29 { std::get<1>(p_0) };
      Size id_30 { id_28(id_29) };
      Size id_31 { Size(id_27 + id_30) };
      choose_res_21 = id_31;
    }
    return choose_res_21;
  }
   };
  return fun17;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_75" "make_snd_76"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let-pair "du32_fst_69" "du32_snd_70" (read-u32 little-endian (identifier "dsum1_snd_64")) (make-tup (construct "[Idx U32 | Name $field_name]" 0 (identifier "du32_fst_69")) (identifier "du32_snd_70")))
              (seq (assert (eq (identifier "dsum1_fst_63") (u16 1)))
                (let-pair "dsum2_fst_66" "dsum2_snd_67" (apply (ext-identifier field_name of-row-binary) (identifier "dsum1_snd_64"))
                  (make-tup (construct "[Idx U32 | Name $field_name]" 1 (identifier "dsum2_fst_66")) (identifier "dsum2_snd_67"))))))) 
        (make-tup (identifier "make_fst_75") (identifier "make_snd_76"))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun32 { [&fun32](Pointer p_0) {
    v_362f9d9108a6902af48b6c83d5377ea1 id_33 { p_0.readU16Le() };
    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_34;
    {
      auto du16_fst_57 { std::get<0>(id_33) };
      auto du16_snd_58 { std::get<1>(id_33) };
      v_362f9d9108a6902af48b6c83d5377ea1 id_35 {  du16_fst_57, du16_snd_58  };
      letpair_res_34 = id_35;
    }
    f63f919559f0d70225bd0da5dd9bcafc let_res_36;
    {
      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_62 { letpair_res_34 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_37;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_38 { 0 };
        bool id_39 { bool(id_38 == dsum1_fst_63) };
        f63f919559f0d70225bd0da5dd9bcafc choose_res_40;
        if (id_39) {
          ac0fbd05039f742d2f1d9ac182e392ab id_41 { dsum1_snd_64.readU32Le() };
          f63f919559f0d70225bd0da5dd9bcafc letpair_res_42;
          {
            auto du32_fst_69 { std::get<0>(id_41) };
            auto du32_snd_70 { std::get<1>(id_41) };
            t id_43 { std::in_place_index<0>, du32_fst_69 };
            f63f919559f0d70225bd0da5dd9bcafc id_44 {  id_43, du32_snd_70  };
            letpair_res_42 = id_44;
          }
          choose_res_40 = letpair_res_42;
        } else {
          uint16_t id_45 { 1 };
          bool id_46 { bool(dsum1_fst_63 == id_45) };
          Void id_47 { ((void)(assert(id_46)), VOID) };
          std::function<c50aa083fa818c6eeca389b0025dda98(Pointer)> id_48 { dessser::gen::field_name::of_row_binary };
          c50aa083fa818c6eeca389b0025dda98 id_49 { id_48(dsum1_snd_64) };
          f63f919559f0d70225bd0da5dd9bcafc letpair_res_50;
          {
            auto dsum2_fst_66 { std::get<0>(id_49) };
            auto dsum2_snd_67 { std::get<1>(id_49) };
            t id_51 { std::in_place_index<1>, dsum2_fst_66 };
            f63f919559f0d70225bd0da5dd9bcafc id_52 {  id_51, dsum2_snd_67  };
            letpair_res_50 = id_52;
          }
          choose_res_40 = letpair_res_50;
        }
        letpair_res_37 = choose_res_40;
      }
      let_res_36 = letpair_res_37;
    }
    f63f919559f0d70225bd0da5dd9bcafc letpair_res_53;
    {
      auto make_fst_75 { std::get<0>(let_res_36) };
      auto make_snd_76 { std::get<1>(let_res_36) };
      f63f919559f0d70225bd0da5dd9bcafc id_54 {  make_fst_75, make_snd_76  };
      letpair_res_53 = id_54;
    }
    return letpair_res_53;
  }
   };
  return fun32;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
