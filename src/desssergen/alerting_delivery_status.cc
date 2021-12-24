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
struct tec94fb10bb9e3d4256b8917917ea243f : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_delivery_status::t> ,
  Pointer
> {
  using tuple::tuple;
  tec94fb10bb9e3d4256b8917917ea243f(std::tuple<std::shared_ptr<::dessser::gen::alerting_delivery_status::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_delivery_status::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tec94fb10bb9e3d4256b8917917ea243f const &a, tec94fb10bb9e3d4256b8917917ea243f const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tec94fb10bb9e3d4256b8917917ea243f const &a, tec94fb10bb9e3d4256b8917917ea243f const &b) {
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
      (let "ssum_dst_88" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_88")
          (if (eq (u16 1) (label-of (param 0))) (identifier "ssum_dst_88")
            (if (eq (u16 2) (label-of (param 0))) (identifier "ssum_dst_88")
              (if (eq (u16 3) (label-of (param 0))) (identifier "ssum_dst_88") (if (eq (u16 4) (label-of (param 0))) (identifier "ssum_dst_88") (seq (assert (eq (label-of (param 0)) (u16 5))) (identifier "ssum_dst_88")))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::alerting_delivery_status::t>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_88 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_88;
      } else {
        uint16_t id_8 { 1 };
        uint16_t id_9 { uint16_t((*p_0).index()) };
        bool id_10 { bool(id_8 == id_9) };
        Pointer choose_res_11;
        if (id_10) {
          choose_res_11 = ssum_dst_88;
        } else {
          uint16_t id_12 { 2 };
          uint16_t id_13 { uint16_t((*p_0).index()) };
          bool id_14 { bool(id_12 == id_13) };
          Pointer choose_res_15;
          if (id_14) {
            choose_res_15 = ssum_dst_88;
          } else {
            uint16_t id_16 { 3 };
            uint16_t id_17 { uint16_t((*p_0).index()) };
            bool id_18 { bool(id_16 == id_17) };
            Pointer choose_res_19;
            if (id_18) {
              choose_res_19 = ssum_dst_88;
            } else {
              uint16_t id_20 { 4 };
              uint16_t id_21 { uint16_t((*p_0).index()) };
              bool id_22 { bool(id_20 == id_21) };
              Pointer choose_res_23;
              if (id_22) {
                choose_res_23 = ssum_dst_88;
              } else {
                uint16_t id_24 { uint16_t((*p_0).index()) };
                uint16_t id_25 { 5 };
                bool id_26 { bool(id_24 == id_25) };
                Void id_27 { ((void)(assert(id_26)), ::dessser::VOID) };
                (void)id_27;
                choose_res_23 = ssum_dst_88;
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
std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0))) (size 2)
          (if (eq (u16 2) (label-of (param 0))) (size 2) (if (eq (u16 3) (label-of (param 0))) (size 2) (if (eq (u16 4) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 5))) (size 2))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> )> fun28 { [&](std::shared_ptr<::dessser::gen::alerting_delivery_status::t>  p_0) {
    uint16_t id_29 { 0 };
    uint16_t id_30 { uint16_t((*p_0).index()) };
    bool id_31 { bool(id_29 == id_30) };
    Size choose_res_32;
    if (id_31) {
      Size id_33 { 2UL };
      choose_res_32 = id_33;
    } else {
      uint16_t id_34 { 1 };
      uint16_t id_35 { uint16_t((*p_0).index()) };
      bool id_36 { bool(id_34 == id_35) };
      Size choose_res_37;
      if (id_36) {
        Size id_38 { 2UL };
        choose_res_37 = id_38;
      } else {
        uint16_t id_39 { 2 };
        uint16_t id_40 { uint16_t((*p_0).index()) };
        bool id_41 { bool(id_39 == id_40) };
        Size choose_res_42;
        if (id_41) {
          Size id_43 { 2UL };
          choose_res_42 = id_43;
        } else {
          uint16_t id_44 { 3 };
          uint16_t id_45 { uint16_t((*p_0).index()) };
          bool id_46 { bool(id_44 == id_45) };
          Size choose_res_47;
          if (id_46) {
            Size id_48 { 2UL };
            choose_res_47 = id_48;
          } else {
            uint16_t id_49 { 4 };
            uint16_t id_50 { uint16_t((*p_0).index()) };
            bool id_51 { bool(id_49 == id_50) };
            Size choose_res_52;
            if (id_51) {
              Size id_53 { 2UL };
              choose_res_52 = id_53;
            } else {
              uint16_t id_54 { uint16_t((*p_0).index()) };
              uint16_t id_55 { 5 };
              bool id_56 { bool(id_54 == id_55) };
              Void id_57 { ((void)(assert(id_56)), ::dessser::VOID) };
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
std::function<Size(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
          (if (eq (u16 0) (identifier "dsum1_fst_63"))
            (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 0 (nop)) (identifier "dsum1_snd_64"))
            (if (eq (u16 1) (identifier "dsum1_fst_63"))
              (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 1 (nop)) (identifier "dsum1_snd_64"))
              (if (eq (u16 2) (identifier "dsum1_fst_63"))
                (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 2 (nop)) (identifier "dsum1_snd_64"))
                (if (eq (u16 3) (identifier "dsum1_fst_63"))
                  (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 3 (nop)) (identifier "dsum1_snd_64"))
                  (if (eq (u16 4) (identifier "dsum1_fst_63"))
                    (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 4 (nop)) (identifier "dsum1_snd_64"))
                    (seq (assert (eq (identifier "dsum1_fst_63") (u16 5)))
                      (make-tup (construct "[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" 5 (nop)) (identifier "dsum1_snd_64")))))))))))
 */
static std::function<::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f(Pointer)> fun59 { [&](Pointer p_0) {
    ::dessser::gen::alerting_delivery_status::ta97bb48ed75bbda6173555873826c8c6 id_60 { p_0.readU16Le() };
    ::dessser::gen::alerting_delivery_status::ta97bb48ed75bbda6173555873826c8c6 letpair_res_61;
    {
      auto du16_fst_57 { std::get<0>(id_60) };
      auto du16_snd_58 { std::get<1>(id_60) };
      ::dessser::gen::alerting_delivery_status::ta97bb48ed75bbda6173555873826c8c6 id_62 { du16_fst_57, du16_snd_58 };
      letpair_res_61 = id_62;
    }
    ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f let_res_63;
    {
      ::dessser::gen::alerting_delivery_status::ta97bb48ed75bbda6173555873826c8c6 dsum1_62 { letpair_res_61 };
      ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f letpair_res_64;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_65 { 0 };
        bool id_66 { bool(id_65 == dsum1_fst_63) };
        ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f choose_res_67;
        if (id_66) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::alerting_delivery_status::t>  id_68 { std::make_shared<::dessser::gen::alerting_delivery_status::t>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f id_69 { id_68, dsum1_snd_64 };
          choose_res_67 = id_69;
        } else {
          uint16_t id_70 { 1 };
          bool id_71 { bool(id_70 == dsum1_fst_63) };
          ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f choose_res_72;
          if (id_71) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::alerting_delivery_status::t>  id_73 { std::make_shared<::dessser::gen::alerting_delivery_status::t>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f id_74 { id_73, dsum1_snd_64 };
            choose_res_72 = id_74;
          } else {
            uint16_t id_75 { 2 };
            bool id_76 { bool(id_75 == dsum1_fst_63) };
            ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f choose_res_77;
            if (id_76) {
              (void)::dessser::VOID;
              std::shared_ptr<::dessser::gen::alerting_delivery_status::t>  id_78 { std::make_shared<::dessser::gen::alerting_delivery_status::t>(std::in_place_index<2>, ::dessser::VOID) };
              ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f id_79 { id_78, dsum1_snd_64 };
              choose_res_77 = id_79;
            } else {
              uint16_t id_80 { 3 };
              bool id_81 { bool(id_80 == dsum1_fst_63) };
              ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f choose_res_82;
              if (id_81) {
                (void)::dessser::VOID;
                std::shared_ptr<::dessser::gen::alerting_delivery_status::t>  id_83 { std::make_shared<::dessser::gen::alerting_delivery_status::t>(std::in_place_index<3>, ::dessser::VOID) };
                ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f id_84 { id_83, dsum1_snd_64 };
                choose_res_82 = id_84;
              } else {
                uint16_t id_85 { 4 };
                bool id_86 { bool(id_85 == dsum1_fst_63) };
                ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f choose_res_87;
                if (id_86) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::alerting_delivery_status::t>  id_88 { std::make_shared<::dessser::gen::alerting_delivery_status::t>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f id_89 { id_88, dsum1_snd_64 };
                  choose_res_87 = id_89;
                } else {
                  uint16_t id_90 { 5 };
                  bool id_91 { bool(dsum1_fst_63 == id_90) };
                  Void id_92 { ((void)(assert(id_91)), ::dessser::VOID) };
                  (void)id_92;
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::alerting_delivery_status::t>  id_93 { std::make_shared<::dessser::gen::alerting_delivery_status::t>(std::in_place_index<5>, ::dessser::VOID) };
                  ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f id_94 { id_93, dsum1_snd_64 };
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
std::function<::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_84" "make_snd_85" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_84") (identifier "make_snd_85"))))
 */
static std::function<::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f(Pointer)> fun95 { [&](Pointer p_0) {
    ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f id_96 { of_row_binary(p_0) };
    ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f letpair_res_97;
    {
      auto make_fst_84 { std::get<0>(id_96) };
      auto make_snd_85 { std::get<1>(id_96) };
      ::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f id_98 { make_fst_84, make_snd_85 };
      letpair_res_97 = id_98;
    }
    return letpair_res_97;
  }
   };
  return fun95;
}
std::function<::dessser::gen::alerting_delivery_status::tec94fb10bb9e3d4256b8917917ea243f(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[StartToBeSent Void | StartToBeSentThenStopped Void | StartSent Void | StartAcked Void | StopToBeSent Void | StopSent Void]" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> ,Pointer)> fun99 { [&](std::shared_ptr<::dessser::gen::alerting_delivery_status::t>  p_0, Pointer p_1) {
    Pointer id_100 { to_row_binary(p_0, p_1) };
    return id_100;
  }
   };
  return fun99;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
