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


namespace dessser::gen::team_name {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::string t;
struct tf6138ae5919ddcb1cb9a935a9dc7190a : public std::tuple<
  t,
  Pointer
> {
  using tuple::tuple;
  tf6138ae5919ddcb1cb9a935a9dc7190a(std::tuple<t, Pointer> p)
    : std::tuple<t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf6138ae5919ddcb1cb9a935a9dc7190a const &a, tf6138ae5919ddcb1cb9a935a9dc7190a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf6138ae5919ddcb1cb9a935a9dc7190a const &a, tf6138ae5919ddcb1cb9a935a9dc7190a const &b) {
  return !operator==(a, b);
}
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
  return !operator==(a, b);
}
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return !operator==(a, b);
}
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("STRING" "Ptr")
      (write-bytes
        (let "leb128_sz_74" (make-vec (string-length (param 0)))
          (let "leb128_ptr_75" (make-vec (param 1))
            (seq
              (while
                (seq
                  (set-vec (u8 0) (identifier "leb128_ptr_75")
                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_75"))
                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_74"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_74"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_74"))) (u8 128)))))
                  (set-vec (u8 0) (identifier "leb128_sz_74") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_74")) (u8 7))) 
                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_74")) (u32 0))) 
                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_75"))))) 
        (bytes-of-string (param 0))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    uint32_t id_1 { (uint32_t)p_0.size() };
    Vec<1, uint32_t> id_2 {  id_1  };
    Pointer let_res_3;
    {
      Vec<1, uint32_t> leb128_sz_74 { id_2 };
      Vec<1, Pointer> id_4 {  p_1  };
      Pointer let_res_5;
      {
        Vec<1, Pointer> leb128_ptr_75 { id_4 };
        bool while_flag_6 { true };
        do {
          uint8_t id_7 { 0 };
          uint8_t id_8 { 0 };
          Pointer id_9 { leb128_ptr_75[id_8] };
          uint32_t id_10 { 128U };
          uint8_t id_11 { 0 };
          uint32_t id_12 { leb128_sz_74[id_11] };
          bool id_13 { bool(id_10 > id_12) };
          uint8_t choose_res_14;
          if (id_13) {
            uint8_t id_15 { 0 };
            uint32_t id_16 { leb128_sz_74[id_15] };
            uint8_t id_17 { uint8_t(id_16) };
            choose_res_14 = id_17;
          } else {
            uint8_t id_18 { 0 };
            uint32_t id_19 { leb128_sz_74[id_18] };
            uint8_t id_20 { uint8_t(id_19) };
            uint8_t id_21 { 128 };
            uint8_t id_22 { uint8_t(id_20 | id_21) };
            choose_res_14 = id_22;
          }
          Pointer id_23 { id_9.writeU8(choose_res_14) };
          Void id_24 { ((void)(leb128_ptr_75[id_7] = id_23), VOID) };
          (void)id_24;
          uint8_t id_25 { 0 };
          uint8_t id_26 { 0 };
          uint32_t id_27 { leb128_sz_74[id_26] };
          uint8_t id_28 { 7 };
          uint32_t id_29 { uint32_t(id_27 >> id_28) };
          Void id_30 { ((void)(leb128_sz_74[id_25] = id_29), VOID) };
          (void)id_30;
          uint8_t id_31 { 0 };
          uint32_t id_32 { leb128_sz_74[id_31] };
          uint32_t id_33 { 0U };
          bool id_34 { bool(id_32 > id_33) };
          while_flag_6 = id_34;
          if (while_flag_6) {
            (void)VOID;
          }
        } while (while_flag_6);
        (void)VOID;
        uint8_t id_35 { 0 };
        Pointer id_36 { leb128_ptr_75[id_35] };
        let_res_5 = id_36;
      }
      let_res_3 = let_res_5;
    }
    Bytes id_37 { p_0 };
    Pointer id_38 { let_res_3.writeBytes(id_37) };
    return id_38;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("STRING")
      (add
        (let "n_ref_72" (make-vec (string-length (param 0)))
          (let "lebsz_ref_73" (make-vec (u32 1))
            (seq
              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_72")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_73")) (u8 7)))
                (set-vec (u8 0) (identifier "lebsz_ref_73") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_73")) (u32 1)))) 
              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_73")))))) 
        (size-of-u32 (string-length (param 0)))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun39 { [&fun39](t p_0) {
    uint32_t id_40 { (uint32_t)p_0.size() };
    Vec<1, uint32_t> id_41 {  id_40  };
    Size let_res_42;
    {
      Vec<1, uint32_t> n_ref_72 { id_41 };
      uint32_t id_43 { 1U };
      Vec<1, uint32_t> id_44 {  id_43  };
      Size let_res_45;
      {
        Vec<1, uint32_t> lebsz_ref_73 { id_44 };
        bool while_flag_46 { true };
        do {
          uint8_t id_47 { 0 };
          uint32_t id_48 { n_ref_72[id_47] };
          uint8_t id_49 { 0 };
          uint32_t id_50 { lebsz_ref_73[id_49] };
          uint8_t id_51 { 7 };
          uint32_t id_52 { uint32_t(id_50 << id_51) };
          bool id_53 { bool(id_48 >= id_52) };
          while_flag_46 = id_53;
          if (while_flag_46) {
            uint8_t id_54 { 0 };
            uint8_t id_55 { 0 };
            uint32_t id_56 { lebsz_ref_73[id_55] };
            uint32_t id_57 { 1U };
            uint32_t id_58 { uint32_t(id_56 + id_57) };
            Void id_59 { ((void)(lebsz_ref_73[id_54] = id_58), VOID) };
            (void)id_59;
          }
        } while (while_flag_46);
        (void)VOID;
        uint8_t id_60 { 0 };
        uint32_t id_61 { lebsz_ref_73[id_60] };
        Size id_62 { Size(id_61) };
        let_res_45 = id_62;
      }
      let_res_42 = let_res_45;
    }
    uint32_t id_63 { (uint32_t)p_0.size() };
    Size id_64 { Size(id_63) };
    Size id_65 { Size(let_res_42 + id_64) };
    return id_65;
  }
   };
  return fun39;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dstring1_62"
        (let "leb_ref_56" (make-vec (u32 0))
          (let "shft_ref_57" (make-vec (u8 0))
            (let "p_ref_58" (make-vec (param 0))
              (seq
                (while
                  (let "leb128_59" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_58")))
                    (let-pair "leb128_fst_60" "leb128_snd_61" (identifier "leb128_59")
                      (seq (set-vec (u8 0) (identifier "p_ref_58") (identifier "leb128_snd_61"))
                        (set-vec (u8 0) (identifier "leb_ref_56")
                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_60") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_57"))) (unsafe-nth (u8 0) (identifier "leb_ref_56"))))
                        (set-vec (u8 0) (identifier "shft_ref_57") (add (unsafe-nth (u8 0) (identifier "shft_ref_57")) (u8 7))) 
                        (ge (identifier "leb128_fst_60") (u8 128))))) 
                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_56"))) (unsafe-nth (u8 0) (identifier "p_ref_58")))))))
        (let-pair "dstring1_fst_63" "dstring1_snd_64" (identifier "dstring1_62")
          (let-pair "dstring2_fst_66" "dstring2_snd_67" (read-bytes (identifier "dstring1_snd_64") (identifier "dstring1_fst_63")) (make-tup (string-of-bytes (identifier "dstring2_fst_66")) (identifier "dstring2_snd_67"))))))
 */
static std::function<::dessser::gen::team_name::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::team_name::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> fun66 { [&fun66](Pointer p_0) {
    uint32_t id_67 { 0U };
    Vec<1, uint32_t> id_68 {  id_67  };
    ::dessser::gen::team_name::t044960e524fd6ec1bfc06410ce526709 let_res_69;
    {
      Vec<1, uint32_t> leb_ref_56 { id_68 };
      uint8_t id_70 { 0 };
      Vec<1, uint8_t> id_71 {  id_70  };
      ::dessser::gen::team_name::t044960e524fd6ec1bfc06410ce526709 let_res_72;
      {
        Vec<1, uint8_t> shft_ref_57 { id_71 };
        Vec<1, Pointer> id_73 {  p_0  };
        ::dessser::gen::team_name::t044960e524fd6ec1bfc06410ce526709 let_res_74;
        {
          Vec<1, Pointer> p_ref_58 { id_73 };
          bool while_flag_75 { true };
          do {
            uint8_t id_76 { 0 };
            Pointer id_77 { p_ref_58[id_76] };
            ::dessser::gen::team_name::t1566bd611d8a2b90669c241f5e8d6ff1 id_78 { id_77.readU8() };
            bool let_res_79;
            {
              ::dessser::gen::team_name::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_59 { id_78 };
              bool letpair_res_80;
              {
                auto leb128_fst_60 { std::get<0>(leb128_59) };
                auto leb128_snd_61 { std::get<1>(leb128_59) };
                uint8_t id_81 { 0 };
                Void id_82 { ((void)(p_ref_58[id_81] = leb128_snd_61), VOID) };
                (void)id_82;
                uint8_t id_83 { 0 };
                uint8_t id_84 { 127 };
                uint8_t id_85 { uint8_t(leb128_fst_60 & id_84) };
                uint32_t id_86 { uint32_t(id_85) };
                uint8_t id_87 { 0 };
                uint8_t id_88 { shft_ref_57[id_87] };
                uint32_t id_89 { uint32_t(id_86 << id_88) };
                uint8_t id_90 { 0 };
                uint32_t id_91 { leb_ref_56[id_90] };
                uint32_t id_92 { uint32_t(id_89 | id_91) };
                Void id_93 { ((void)(leb_ref_56[id_83] = id_92), VOID) };
                (void)id_93;
                uint8_t id_94 { 0 };
                uint8_t id_95 { 0 };
                uint8_t id_96 { shft_ref_57[id_95] };
                uint8_t id_97 { 7 };
                uint8_t id_98 { uint8_t(id_96 + id_97) };
                Void id_99 { ((void)(shft_ref_57[id_94] = id_98), VOID) };
                (void)id_99;
                uint8_t id_100 { 128 };
                bool id_101 { bool(leb128_fst_60 >= id_100) };
                letpair_res_80 = id_101;
              }
              let_res_79 = letpair_res_80;
            }
            while_flag_75 = let_res_79;
            if (while_flag_75) {
              (void)VOID;
            }
          } while (while_flag_75);
          (void)VOID;
          uint8_t id_102 { 0 };
          uint32_t id_103 { leb_ref_56[id_102] };
          Size id_104 { Size(id_103) };
          uint8_t id_105 { 0 };
          Pointer id_106 { p_ref_58[id_105] };
          ::dessser::gen::team_name::t044960e524fd6ec1bfc06410ce526709 id_107 { id_104, id_106 };
          let_res_74 = id_107;
        }
        let_res_72 = let_res_74;
      }
      let_res_69 = let_res_72;
    }
    ::dessser::gen::team_name::tf6138ae5919ddcb1cb9a935a9dc7190a let_res_108;
    {
      ::dessser::gen::team_name::t044960e524fd6ec1bfc06410ce526709 dstring1_62 { let_res_69 };
      ::dessser::gen::team_name::tf6138ae5919ddcb1cb9a935a9dc7190a letpair_res_109;
      {
        auto dstring1_fst_63 { std::get<0>(dstring1_62) };
        auto dstring1_snd_64 { std::get<1>(dstring1_62) };
        ::dessser::gen::team_name::t5887709cc43c8c8e24d28211e8c970a2 id_110 { dstring1_snd_64.readBytes(dstring1_fst_63) };
        ::dessser::gen::team_name::tf6138ae5919ddcb1cb9a935a9dc7190a letpair_res_111;
        {
          auto dstring2_fst_66 { std::get<0>(id_110) };
          auto dstring2_snd_67 { std::get<1>(id_110) };
          t id_112 { dstring2_fst_66.toString() };
          ::dessser::gen::team_name::tf6138ae5919ddcb1cb9a935a9dc7190a id_113 { id_112, dstring2_snd_67 };
          letpair_res_111 = id_113;
        }
        letpair_res_109 = letpair_res_111;
      }
      let_res_108 = letpair_res_109;
    }
    return let_res_108;
  }
   };
  return fun66;
}
std::function<::dessser::gen::team_name::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary(of_row_binary_init());


}
