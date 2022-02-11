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

namespace dessser::gen::alerting_delivery_status {
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
  Void, // StartToBeSent
  Void, // StartToBeSentThenStopped
  Void, // StartSent
  Void, // StartAcked
  Void, // StopToBeSent
  Void // StopSent
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 6 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // StartToBeSent
    case 1: return std::get<1>(a) == std::get<1>(b); // StartToBeSentThenStopped
    case 2: return std::get<2>(a) == std::get<2>(b); // StartSent
    case 3: return std::get<3>(a) == std::get<3>(b); // StartAcked
    case 4: return std::get<4>(a) == std::get<4>(b); // StopToBeSent
    case 5: return std::get<5>(a) == std::get<5>(b); // StopSent
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t3a70e06bd973b675ad23916a4f0f5e29 : public std::tuple<
  ::dessser::gen::alerting_delivery_status::t,
  Pointer
> {
  using tuple::tuple;
  t3a70e06bd973b675ad23916a4f0f5e29(std::tuple<::dessser::gen::alerting_delivery_status::t, Pointer> p)
    : std::tuple<::dessser::gen::alerting_delivery_status::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3a70e06bd973b675ad23916a4f0f5e29 const &a, t3a70e06bd973b675ad23916a4f0f5e29 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3a70e06bd973b675ad23916a4f0f5e29 const &a, t3a70e06bd973b675ad23916a4f0f5e29 const &b) {
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
    (fun ("[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" "Ptr")
      (let "ssum_dst_89" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_89")
          (if (eq (u16 1) (label-of (param 0))) (identifier "ssum_dst_89")
            (if (eq (u16 2) (label-of (param 0))) (identifier "ssum_dst_89")
              (if (eq (u16 3) (label-of (param 0))) (identifier "ssum_dst_89") (if (eq (u16 4) (label-of (param 0))) (identifier "ssum_dst_89") (seq (assert (eq (label-of (param 0)) (u16 5))) (identifier "ssum_dst_89")))))))))
 */
static std::function<Pointer(::dessser::gen::alerting_delivery_status::t const &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::alerting_delivery_status::t const &,Pointer &)> fun0 { [&](::dessser::gen::alerting_delivery_status::t p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0.index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_89 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0.index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_89;
      } else {
        uint16_t id_8 { 1 };
        uint16_t id_9 { uint16_t(p_0.index()) };
        bool id_10 { bool(id_8 == id_9) };
        Pointer choose_res_11;
        if (id_10) {
          choose_res_11 = ssum_dst_89;
        } else {
          uint16_t id_12 { 2 };
          uint16_t id_13 { uint16_t(p_0.index()) };
          bool id_14 { bool(id_12 == id_13) };
          Pointer choose_res_15;
          if (id_14) {
            choose_res_15 = ssum_dst_89;
          } else {
            uint16_t id_16 { 3 };
            uint16_t id_17 { uint16_t(p_0.index()) };
            bool id_18 { bool(id_16 == id_17) };
            Pointer choose_res_19;
            if (id_18) {
              choose_res_19 = ssum_dst_89;
            } else {
              uint16_t id_20 { 4 };
              uint16_t id_21 { uint16_t(p_0.index()) };
              bool id_22 { bool(id_20 == id_21) };
              Pointer choose_res_23;
              if (id_22) {
                choose_res_23 = ssum_dst_89;
              } else {
                uint16_t id_24 { uint16_t(p_0.index()) };
                uint16_t id_25 { 5 };
                bool id_26 { bool(id_24 == id_25) };
                Void id_27 { ((void)(assert(id_26)), ::dessser::Void()) };
                (void)id_27;
                choose_res_23 = ssum_dst_89;
              }
              choose_res_19 = choose_res_23;
            }
            choose_res_15 = choose_res_19;
          }
          choose_res_11 = choose_res_15;
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
std::function<Pointer(::dessser::gen::alerting_delivery_status::t const &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0))) (size 2)
          (if (eq (u16 2) (label-of (param 0))) (size 2) (if (eq (u16 3) (label-of (param 0))) (size 2) (if (eq (u16 4) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 5))) (size 2))))))))
 */
static std::function<Size(::dessser::gen::alerting_delivery_status::t const &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::alerting_delivery_status::t const &)> fun28 { [&](::dessser::gen::alerting_delivery_status::t p_0) {
    uint16_t id_29 { 0 };
    uint16_t id_30 { uint16_t(p_0.index()) };
    bool id_31 { bool(id_29 == id_30) };
    Size choose_res_32;
    if (id_31) {
      Size id_33 { 2UL };
      choose_res_32 = id_33;
    } else {
      uint16_t id_34 { 1 };
      uint16_t id_35 { uint16_t(p_0.index()) };
      bool id_36 { bool(id_34 == id_35) };
      Size choose_res_37;
      if (id_36) {
        Size id_38 { 2UL };
        choose_res_37 = id_38;
      } else {
        uint16_t id_39 { 2 };
        uint16_t id_40 { uint16_t(p_0.index()) };
        bool id_41 { bool(id_39 == id_40) };
        Size choose_res_42;
        if (id_41) {
          Size id_43 { 2UL };
          choose_res_42 = id_43;
        } else {
          uint16_t id_44 { 3 };
          uint16_t id_45 { uint16_t(p_0.index()) };
          bool id_46 { bool(id_44 == id_45) };
          Size choose_res_47;
          if (id_46) {
            Size id_48 { 2UL };
            choose_res_47 = id_48;
          } else {
            uint16_t id_49 { 4 };
            uint16_t id_50 { uint16_t(p_0.index()) };
            bool id_51 { bool(id_49 == id_50) };
            Size choose_res_52;
            if (id_51) {
              Size id_53 { 2UL };
              choose_res_52 = id_53;
            } else {
              uint16_t id_54 { uint16_t(p_0.index()) };
              uint16_t id_55 { 5 };
              bool id_56 { bool(id_54 == id_55) };
              Void id_57 { ((void)(assert(id_56)), ::dessser::Void()) };
              (void)id_57;
              Size id_58 { 2UL };
              choose_res_52 = id_58;
            }
            choose_res_47 = choose_res_52;
          }
          choose_res_42 = choose_res_47;
        }
        choose_res_37 = choose_res_42;
      }
      choose_res_32 = choose_res_37;
    }
    return choose_res_32;
  }
   };
  return fun28;
}
std::function<Size(::dessser::gen::alerting_delivery_status::t const &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 0 (nop)) (identifier "dsum1_snd_65"))
            (if (eq (u16 1) (identifier "dsum1_fst_64"))
              (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 1 (nop)) (identifier "dsum1_snd_65"))
              (if (eq (u16 2) (identifier "dsum1_fst_64"))
                (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 2 (nop)) (identifier "dsum1_snd_65"))
                (if (eq (u16 3) (identifier "dsum1_fst_64"))
                  (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 3 (nop)) (identifier "dsum1_snd_65"))
                  (if (eq (u16 4) (identifier "dsum1_fst_64"))
                    (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 4 (nop)) (identifier "dsum1_snd_65"))
                    (seq (assert (eq (identifier "dsum1_fst_64") (u16 5)))
                      (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 5 (nop)) (identifier "dsum1_snd_65")))))))))))
 */
static std::function<::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29(Pointer &)> fun59 { [&](Pointer p_0) {
    ::dessser::gen::alerting_delivery_status::ta97bb48ed75bbda6173555873826c8c6 id_60 { p_0.readU16Le() };
    ::dessser::gen::alerting_delivery_status::ta97bb48ed75bbda6173555873826c8c6 letpair_res_61;
    {
      auto du16_fst_58 { std::get<0>(id_60) };
      auto du16_snd_59 { std::get<1>(id_60) };
      ::dessser::gen::alerting_delivery_status::ta97bb48ed75bbda6173555873826c8c6 id_62 { du16_fst_58, du16_snd_59 };
      letpair_res_61 = id_62;
    }
    ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 let_res_63;
    {
      ::dessser::gen::alerting_delivery_status::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_61 };
      ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 letpair_res_64;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_65 { 0 };
        bool id_66 { bool(id_65 == dsum1_fst_64) };
        ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 choose_res_67;
        if (id_66) {
          (void)::dessser::Void();
          ::dessser::gen::alerting_delivery_status::t id_68 { std::in_place_index<0>, ::dessser::Void() };
          ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 id_69 { id_68, dsum1_snd_65 };
          choose_res_67 = id_69;
        } else {
          uint16_t id_70 { 1 };
          bool id_71 { bool(id_70 == dsum1_fst_64) };
          ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 choose_res_72;
          if (id_71) {
            (void)::dessser::Void();
            ::dessser::gen::alerting_delivery_status::t id_73 { std::in_place_index<1>, ::dessser::Void() };
            ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 id_74 { id_73, dsum1_snd_65 };
            choose_res_72 = id_74;
          } else {
            uint16_t id_75 { 2 };
            bool id_76 { bool(id_75 == dsum1_fst_64) };
            ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 choose_res_77;
            if (id_76) {
              (void)::dessser::Void();
              ::dessser::gen::alerting_delivery_status::t id_78 { std::in_place_index<2>, ::dessser::Void() };
              ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 id_79 { id_78, dsum1_snd_65 };
              choose_res_77 = id_79;
            } else {
              uint16_t id_80 { 3 };
              bool id_81 { bool(id_80 == dsum1_fst_64) };
              ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 choose_res_82;
              if (id_81) {
                (void)::dessser::Void();
                ::dessser::gen::alerting_delivery_status::t id_83 { std::in_place_index<3>, ::dessser::Void() };
                ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 id_84 { id_83, dsum1_snd_65 };
                choose_res_82 = id_84;
              } else {
                uint16_t id_85 { 4 };
                bool id_86 { bool(id_85 == dsum1_fst_64) };
                ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 choose_res_87;
                if (id_86) {
                  (void)::dessser::Void();
                  ::dessser::gen::alerting_delivery_status::t id_88 { std::in_place_index<4>, ::dessser::Void() };
                  ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 id_89 { id_88, dsum1_snd_65 };
                  choose_res_87 = id_89;
                } else {
                  uint16_t id_90 { 5 };
                  bool id_91 { bool(dsum1_fst_64 == id_90) };
                  Void id_92 { ((void)(assert(id_91)), ::dessser::Void()) };
                  (void)id_92;
                  (void)::dessser::Void();
                  ::dessser::gen::alerting_delivery_status::t id_93 { std::in_place_index<5>, ::dessser::Void() };
                  ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 id_94 { id_93, dsum1_snd_65 };
                  choose_res_87 = id_94;
                }
                choose_res_82 = choose_res_87;
              }
              choose_res_77 = choose_res_82;
            }
            choose_res_72 = choose_res_77;
          }
          choose_res_67 = choose_res_72;
        }
        letpair_res_64 = choose_res_67;
      }
      let_res_63 = letpair_res_64;
    }
    return let_res_63;
  }
   };
  return fun59;
}
std::function<::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_85" "make_snd_86" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_85") (identifier "make_snd_86"))))
 */
static std::function<::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29(Pointer &)> fun95 { [&](Pointer p_0) {
    ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 id_96 { of_row_binary(p_0) };
    ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 letpair_res_97;
    {
      auto make_fst_85 { std::get<0>(id_96) };
      auto make_snd_86 { std::get<1>(id_96) };
      ::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29 id_98 { make_fst_85, make_snd_86 };
      letpair_res_97 = id_98;
    }
    return letpair_res_97;
  }
   };
  return fun95;
}
std::function<::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::alerting_delivery_status::t const &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::alerting_delivery_status::t const &,Pointer &)> fun99 { [&](::dessser::gen::alerting_delivery_status::t p_0, Pointer p_1) {
    Pointer id_100 { to_row_binary(p_0, p_1) };
    return id_100;
  }
   };
  return fun99;
}
std::function<Pointer(::dessser::gen::alerting_delivery_status::t const &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
