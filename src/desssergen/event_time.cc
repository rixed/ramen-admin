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
#include "desssergen/event_time_field.h"
#include "desssergen/event_time_field.h"
#include "desssergen/event_time_field.h"

namespace dessser::gen::event_time {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t52e26a57572ca91d707cdc0b7b472229 : public std::variant<
  double, // DurationConst
  dessser::gen::event_time_field::t_ext, // DurationField
  dessser::gen::event_time_field::t_ext // StopField
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

inline bool operator==(t52e26a57572ca91d707cdc0b7b472229 const &a, t52e26a57572ca91d707cdc0b7b472229 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // DurationConst
    case 1: return ::dessser::gen::event_time_field::Deref(std::get<1>(a)) == ::dessser::gen::event_time_field::Deref(std::get<1>(b)); // DurationField
    case 2: return ::dessser::gen::event_time_field::Deref(std::get<2>(a)) == ::dessser::gen::event_time_field::Deref(std::get<2>(b)); // StopField
  };
  return false;
}
inline bool operator!=(t52e26a57572ca91d707cdc0b7b472229 const &a, t52e26a57572ca91d707cdc0b7b472229 const &b) {
  return !operator==(a, b);
}
struct t : public std::tuple<
  dessser::gen::event_time_field::t_ext,
  ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229
> {
  using tuple::tuple;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::event_time_field::Deref(std::get<0>(a)) == ::dessser::gen::event_time_field::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tcc7976c4e7ba96ee361470d862fd2d95 : public std::tuple<
  ::dessser::gen::event_time::t,
  Pointer
> {
  using tuple::tuple;
  tcc7976c4e7ba96ee361470d862fd2d95(std::tuple<::dessser::gen::event_time::t, Pointer> p)
    : std::tuple<::dessser::gen::event_time::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcc7976c4e7ba96ee361470d862fd2d95 const &a, tcc7976c4e7ba96ee361470d862fd2d95 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcc7976c4e7ba96ee361470d862fd2d95 const &a, tcc7976c4e7ba96ee361470d862fd2d95 const &b) {
  return !operator==(a, b);
}
struct tbbd2b8c4f75407d8eeb609a7e2e8ba68 : public std::tuple<
  dessser::gen::event_time_field::t_ext,
  Pointer
> {
  using tuple::tuple;
  tbbd2b8c4f75407d8eeb609a7e2e8ba68(std::tuple<dessser::gen::event_time_field::t_ext, Pointer> p)
    : std::tuple<dessser::gen::event_time_field::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tbbd2b8c4f75407d8eeb609a7e2e8ba68 const &a, tbbd2b8c4f75407d8eeb609a7e2e8ba68 const &b) {
  return ::dessser::gen::event_time_field::Deref(std::get<0>(a)) == ::dessser::gen::event_time_field::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tbbd2b8c4f75407d8eeb609a7e2e8ba68 const &a, tbbd2b8c4f75407d8eeb609a7e2e8ba68 const &b) {
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
struct t2be49010dea1b8f6d58217bcef4a8083 : public std::tuple<
  ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229,
  Pointer
> {
  using tuple::tuple;
  t2be49010dea1b8f6d58217bcef4a8083(std::tuple<::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229, Pointer> p)
    : std::tuple<::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2be49010dea1b8f6d58217bcef4a8083 const &a, t2be49010dea1b8f6d58217bcef4a8083 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2be49010dea1b8f6d58217bcef4a8083 const &a, t2be49010dea1b8f6d58217bcef4a8083 const &b) {
  return !operator==(a, b);
}
struct td2cd337bb3c8bc04d5603393d084985b : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  td2cd337bb3c8bc04d5603393d084985b(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("($event_time_field; [DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field])" "Ptr")
      (let "stup_dst_90" (apply (ext-identifier event_time_field to-row-binary) (get-item 0 (param 0)) (param 1))
        (let "ssum_dst_92" (write-u16 little-endian (identifier "stup_dst_90") (label-of (get-item 1 (param 0))))
          (if (eq (u16 0) (label-of (get-item 1 (param 0)))) (write-u64 little-endian (identifier "ssum_dst_92") (u64-of-float (get-alt "DurationConst" (get-item 1 (param 0)))))
            (if (eq (u16 1) (label-of (get-item 1 (param 0)))) (apply (ext-identifier event_time_field to-row-binary) (get-alt "DurationField" (get-item 1 (param 0))) (identifier "ssum_dst_92"))
              (seq (assert (eq (label-of (get-item 1 (param 0))) (u16 2))) (apply (ext-identifier event_time_field to-row-binary) (get-alt "StopField" (get-item 1 (param 0))) (identifier "ssum_dst_92"))))))))
 */
static std::function<Pointer(::dessser::gen::event_time::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::event_time::t &,Pointer &)> fun0 { [&](::dessser::gen::event_time::t p_0, Pointer p_1) {
    auto fun1 { dessser::gen::event_time_field::to_row_binary };
    dessser::gen::event_time_field::t_ext id_2 { std::get<0>(p_0) };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer stup_dst_90 { id_3 };
      ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_5 { std::get<1>(p_0) };
      uint16_t id_6 { uint16_t(id_5.index()) };
      Pointer id_7 { stup_dst_90.writeU16Le(id_6) };
      Pointer let_res_8;
      {
        Pointer ssum_dst_92 { id_7 };
        uint16_t id_9 { 0 };
        ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_10 { std::get<1>(p_0) };
        uint16_t id_11 { uint16_t(id_10.index()) };
        bool id_12 { bool(id_9 == id_11) };
        Pointer choose_res_13;
        if (id_12) {
          ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_14 { std::get<1>(p_0) };
          double id_15 { std::get<0 /* DurationConst */>(id_14) };
          uint64_t id_16 { qword_of_float(id_15) };
          Pointer id_17 { ssum_dst_92.writeU64Le(id_16) };
          choose_res_13 = id_17;
        } else {
          uint16_t id_18 { 1 };
          ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_19 { std::get<1>(p_0) };
          uint16_t id_20 { uint16_t(id_19.index()) };
          bool id_21 { bool(id_18 == id_20) };
          Pointer choose_res_22;
          if (id_21) {
            auto fun23 { dessser::gen::event_time_field::to_row_binary };
            ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_24 { std::get<1>(p_0) };
            dessser::gen::event_time_field::t_ext id_25 { std::get<1 /* DurationField */>(id_24) };
            Pointer id_26 { fun23(id_25, ssum_dst_92) };
            choose_res_22 = id_26;
          } else {
            ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_27 { std::get<1>(p_0) };
            uint16_t id_28 { uint16_t(id_27.index()) };
            uint16_t id_29 { 2 };
            bool id_30 { bool(id_28 == id_29) };
            Void id_31 { ((void)(assert(id_30)), ::dessser::Void()) };
            (void)id_31;
            auto fun32 { dessser::gen::event_time_field::to_row_binary };
            ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_33 { std::get<1>(p_0) };
            dessser::gen::event_time_field::t_ext id_34 { std::get<2 /* StopField */>(id_33) };
            Pointer id_35 { fun32(id_34, ssum_dst_92) };
            choose_res_22 = id_35;
          }
          choose_res_13 = choose_res_22;
        }
        let_res_8 = choose_res_13;
      }
      let_res_4 = let_res_8;
    }
    return let_res_4;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::event_time::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("($event_time_field; [DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field])")
      (let "sz_88" (apply (ext-identifier event_time_field sersize-of-row-binary) (get-item 0 (param 0)))
        (if (eq (u16 0) (label-of (get-item 1 (param 0)))) (add (add (identifier "sz_88") (size 2)) (size 8))
          (if (eq (u16 1) (label-of (get-item 1 (param 0)))) (add (add (identifier "sz_88") (size 2)) (apply (ext-identifier event_time_field sersize-of-row-binary) (get-alt "DurationField" (get-item 1 (param 0)))))
            (seq (assert (eq (label-of (get-item 1 (param 0))) (u16 2))) (add (add (identifier "sz_88") (size 2)) (apply (ext-identifier event_time_field sersize-of-row-binary) (get-alt "StopField" (get-item 1 (param 0))))))))))
 */
static std::function<Size(::dessser::gen::event_time::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::event_time::t &)> fun36 { [&](::dessser::gen::event_time::t p_0) {
    auto fun37 { dessser::gen::event_time_field::sersize_of_row_binary };
    dessser::gen::event_time_field::t_ext id_38 { std::get<0>(p_0) };
    Size id_39 { fun37(id_38) };
    Size let_res_40;
    {
      Size sz_88 { id_39 };
      uint16_t id_41 { 0 };
      ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_42 { std::get<1>(p_0) };
      uint16_t id_43 { uint16_t(id_42.index()) };
      bool id_44 { bool(id_41 == id_43) };
      Size choose_res_45;
      if (id_44) {
        Size id_46 { 2UL };
        Size id_47 { Size(sz_88 + id_46) };
        Size id_48 { 8UL };
        Size id_49 { Size(id_47 + id_48) };
        choose_res_45 = id_49;
      } else {
        uint16_t id_50 { 1 };
        ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_51 { std::get<1>(p_0) };
        uint16_t id_52 { uint16_t(id_51.index()) };
        bool id_53 { bool(id_50 == id_52) };
        Size choose_res_54;
        if (id_53) {
          Size id_55 { 2UL };
          Size id_56 { Size(sz_88 + id_55) };
          auto fun57 { dessser::gen::event_time_field::sersize_of_row_binary };
          ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_58 { std::get<1>(p_0) };
          dessser::gen::event_time_field::t_ext id_59 { std::get<1 /* DurationField */>(id_58) };
          Size id_60 { fun57(id_59) };
          Size id_61 { Size(id_56 + id_60) };
          choose_res_54 = id_61;
        } else {
          ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_62 { std::get<1>(p_0) };
          uint16_t id_63 { uint16_t(id_62.index()) };
          uint16_t id_64 { 2 };
          bool id_65 { bool(id_63 == id_64) };
          Void id_66 { ((void)(assert(id_65)), ::dessser::Void()) };
          (void)id_66;
          Size id_67 { 2UL };
          Size id_68 { Size(sz_88 + id_67) };
          auto fun69 { dessser::gen::event_time_field::sersize_of_row_binary };
          ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_70 { std::get<1>(p_0) };
          dessser::gen::event_time_field::t_ext id_71 { std::get<2 /* StopField */>(id_70) };
          Size id_72 { fun69(id_71) };
          Size id_73 { Size(id_68 + id_72) };
          choose_res_54 = id_73;
        }
        choose_res_45 = choose_res_54;
      }
      let_res_40 = choose_res_45;
    }
    return let_res_40;
  }
   };
  return fun36;
}
std::function<Size(::dessser::gen::event_time::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_57" (apply (ext-identifier event_time_field of-row-binary) (param 0))
        (let-pair "dtup_fst_58" "dtup_snd_59" (identifier "dtup_57")
          (let-pair "dtup_fst_82" "dtup_snd_83"
            (let "dsum1_66" (let-pair "du16_fst_61" "du16_snd_62" (read-u16 little-endian (identifier "dtup_snd_59")) (make-tup (identifier "du16_fst_61") (identifier "du16_snd_62")))
              (let-pair "dsum1_fst_67" "dsum1_snd_68" (identifier "dsum1_66")
                (if (eq (u16 0) (identifier "dsum1_fst_67"))
                  (let-pair "dfloat_fst_76" "dfloat_snd_77" (read-u64 little-endian (identifier "dsum1_snd_68"))
                    (make-tup (construct "[DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field]" 0 (float-of-u64 (identifier "dfloat_fst_76"))) (identifier "dfloat_snd_77")))
                  (if (eq (u16 1) (identifier "dsum1_fst_67"))
                    (let-pair "dsum2_fst_73" "dsum2_snd_74" (apply (ext-identifier event_time_field of-row-binary) (identifier "dsum1_snd_68"))
                      (make-tup (construct "[DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field]" 1 (identifier "dsum2_fst_73")) (identifier "dsum2_snd_74")))
                    (seq (assert (eq (identifier "dsum1_fst_67") (u16 2)))
                      (let-pair "dsum2_fst_70" "dsum2_snd_71" (apply (ext-identifier event_time_field of-row-binary) (identifier "dsum1_snd_68"))
                        (make-tup (construct "[DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field]" 2 (identifier "dsum2_fst_70")) (identifier "dsum2_snd_71"))))))))
            (make-tup (make-tup (identifier "dtup_fst_58") (identifier "dtup_fst_82")) (identifier "dtup_snd_83"))))))
 */
static std::function<::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95(Pointer &)> fun74 { [&](Pointer p_0) {
    auto fun75 { dessser::gen::event_time_field::of_row_binary };
    ::dessser::gen::event_time::tbbd2b8c4f75407d8eeb609a7e2e8ba68 id_76 { fun75(p_0) };
    ::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95 let_res_77;
    {
      ::dessser::gen::event_time::tbbd2b8c4f75407d8eeb609a7e2e8ba68 dtup_57 { id_76 };
      ::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95 letpair_res_78;
      {
        auto dtup_fst_58 { std::get<0>(dtup_57) };
        auto dtup_snd_59 { std::get<1>(dtup_57) };
        ::dessser::gen::event_time::ta97bb48ed75bbda6173555873826c8c6 id_79 { dtup_snd_59.readU16Le() };
        ::dessser::gen::event_time::ta97bb48ed75bbda6173555873826c8c6 letpair_res_80;
        {
          auto du16_fst_61 { std::get<0>(id_79) };
          auto du16_snd_62 { std::get<1>(id_79) };
          ::dessser::gen::event_time::ta97bb48ed75bbda6173555873826c8c6 id_81 { du16_fst_61, du16_snd_62 };
          letpair_res_80 = id_81;
        }
        ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 let_res_82;
        {
          ::dessser::gen::event_time::ta97bb48ed75bbda6173555873826c8c6 dsum1_66 { letpair_res_80 };
          ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 letpair_res_83;
          {
            auto dsum1_fst_67 { std::get<0>(dsum1_66) };
            auto dsum1_snd_68 { std::get<1>(dsum1_66) };
            uint16_t id_84 { 0 };
            bool id_85 { bool(id_84 == dsum1_fst_67) };
            ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 choose_res_86;
            if (id_85) {
              ::dessser::gen::event_time::td2cd337bb3c8bc04d5603393d084985b id_87 { dsum1_snd_68.readU64Le() };
              ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 letpair_res_88;
              {
                auto dfloat_fst_76 { std::get<0>(id_87) };
                auto dfloat_snd_77 { std::get<1>(id_87) };
                double id_89 { float_of_qword(dfloat_fst_76) };
                ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_90 { std::in_place_index<0>, id_89 };
                ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 id_91 { id_90, dfloat_snd_77 };
                letpair_res_88 = id_91;
              }
              choose_res_86 = letpair_res_88;
            } else {
              uint16_t id_92 { 1 };
              bool id_93 { bool(id_92 == dsum1_fst_67) };
              ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 choose_res_94;
              if (id_93) {
                auto fun95 { dessser::gen::event_time_field::of_row_binary };
                ::dessser::gen::event_time::tbbd2b8c4f75407d8eeb609a7e2e8ba68 id_96 { fun95(dsum1_snd_68) };
                ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 letpair_res_97;
                {
                  auto dsum2_fst_73 { std::get<0>(id_96) };
                  auto dsum2_snd_74 { std::get<1>(id_96) };
                  ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_98 { std::in_place_index<1>, dsum2_fst_73 };
                  ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 id_99 { id_98, dsum2_snd_74 };
                  letpair_res_97 = id_99;
                }
                choose_res_94 = letpair_res_97;
              } else {
                uint16_t id_100 { 2 };
                bool id_101 { bool(dsum1_fst_67 == id_100) };
                Void id_102 { ((void)(assert(id_101)), ::dessser::Void()) };
                (void)id_102;
                auto fun103 { dessser::gen::event_time_field::of_row_binary };
                ::dessser::gen::event_time::tbbd2b8c4f75407d8eeb609a7e2e8ba68 id_104 { fun103(dsum1_snd_68) };
                ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 letpair_res_105;
                {
                  auto dsum2_fst_70 { std::get<0>(id_104) };
                  auto dsum2_snd_71 { std::get<1>(id_104) };
                  ::dessser::gen::event_time::t52e26a57572ca91d707cdc0b7b472229 id_106 { std::in_place_index<2>, dsum2_fst_70 };
                  ::dessser::gen::event_time::t2be49010dea1b8f6d58217bcef4a8083 id_107 { id_106, dsum2_snd_71 };
                  letpair_res_105 = id_107;
                }
                choose_res_94 = letpair_res_105;
              }
              choose_res_86 = choose_res_94;
            }
            letpair_res_83 = choose_res_86;
          }
          let_res_82 = letpair_res_83;
        }
        ::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95 letpair_res_108;
        {
          auto dtup_fst_82 { std::get<0>(let_res_82) };
          auto dtup_snd_83 { std::get<1>(let_res_82) };
          ::dessser::gen::event_time::t id_109 { dtup_fst_58, dtup_fst_82 };
          ::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95 id_110 { id_109, dtup_snd_83 };
          letpair_res_108 = id_110;
        }
        letpair_res_78 = letpair_res_108;
      }
      let_res_77 = letpair_res_78;
    }
    return let_res_77;
  }
   };
  return fun74;
}
std::function<::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_85" "make_snd_86" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_85") (identifier "make_snd_86"))))
 */
static std::function<::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95(Pointer &)> fun111 { [&](Pointer p_0) {
    ::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95 id_112 { of_row_binary(p_0) };
    ::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95 letpair_res_113;
    {
      auto make_fst_85 { std::get<0>(id_112) };
      auto make_snd_86 { std::get<1>(id_112) };
      ::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95 id_114 { make_fst_85, make_snd_86 };
      letpair_res_113 = id_114;
    }
    return letpair_res_113;
  }
   };
  return fun111;
}
std::function<::dessser::gen::event_time::tcc7976c4e7ba96ee361470d862fd2d95(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("($event_time_field; [DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field])" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::event_time::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::event_time::t &,Pointer &)> fun115 { [&](::dessser::gen::event_time::t p_0, Pointer p_1) {
    Pointer id_116 { to_row_binary(p_0, p_1) };
    return id_116;
  }
   };
  return fun115;
}
std::function<Pointer(::dessser::gen::event_time::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
