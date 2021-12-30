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
#include "desssergen/field_name.h"

namespace dessser::gen::simple_filter {
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
  dessser::gen::field_name::t_ext lhs;
  std::string rhs;
  std::string op;
  t(dessser::gen::field_name::t_ext lhs_, std::string rhs_, std::string op_) : lhs(lhs_), rhs(rhs_), op(op_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.lhs) == ::dessser::gen::field_name::Deref(b.lhs) && a.rhs == b.rhs && a.op == b.op;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tb507a8f2c568f9319d8e16dafa079fc1 : public std::tuple<
  std::shared_ptr<::dessser::gen::simple_filter::t> ,
  Pointer
> {
  using tuple::tuple;
  tb507a8f2c568f9319d8e16dafa079fc1(std::tuple<std::shared_ptr<::dessser::gen::simple_filter::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::simple_filter::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb507a8f2c568f9319d8e16dafa079fc1 const &a, tb507a8f2c568f9319d8e16dafa079fc1 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb507a8f2c568f9319d8e16dafa079fc1 const &a, tb507a8f2c568f9319d8e16dafa079fc1 const &b) {
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
struct t12fb9c475959b52bf7b17b155a955ffa : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t12fb9c475959b52bf7b17b155a955ffa(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return !operator==(a, b);
}
struct t1a5d74abf838df33f185a72a8912f5c9 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1a5d74abf838df33f185a72a8912f5c9(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return !operator==(a, b);
}
struct t13a07ee37ab40962540da8534858dc07 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t13a07ee37ab40962540da8534858dc07(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
  return !operator==(a, b);
}
struct t9ef6882174ae71a34a3c5ef6b29242fb : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t9ef6882174ae71a34a3c5ef6b29242fb(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{lhs: $field_name; rhs: STRING; op: STRING}" "Ptr")
      (let "srec_dst_105"
        (let "srec_dst_102" (apply (ext-identifier field_name to-row-binary) (get-field "lhs" (param 0)) (param 1))
          (write-bytes
            (let "leb128_sz_103" (make-vec (string-length (get-field "rhs" (param 0))))
              (let "leb128_ptr_104" (make-vec (identifier "srec_dst_102"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_104")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_104"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_103"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_103"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_103"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_103") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_103")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_103")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_104"))))) 
            (bytes-of-string (get-field "rhs" (param 0)))))
        (write-bytes
          (let "leb128_sz_106" (make-vec (string-length (get-field "op" (param 0))))
            (let "leb128_ptr_107" (make-vec (identifier "srec_dst_105"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_107")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_107"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_106"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_106"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_106"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_106") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_106")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_106")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_107"))))) 
          (bytes-of-string (get-field "op" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::simple_filter::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::simple_filter::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::simple_filter::t>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t_ext id_2 { (*p_0).lhs };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_102 { id_3 };
      std::string id_5 { (*p_0).rhs };
      uint32_t id_6 { (uint32_t)id_5.size() };
      Vec<1, uint32_t> id_7 {  id_6  };
      Pointer let_res_8;
      {
        Vec<1, uint32_t> leb128_sz_103 { id_7 };
        Vec<1, Pointer> id_9 {  srec_dst_102  };
        Pointer let_res_10;
        {
          Vec<1, Pointer> leb128_ptr_104 { id_9 };
          bool while_flag_11 { true };
          do {
            uint8_t id_12 { 0 };
            uint8_t id_13 { 0 };
            Pointer id_14 { leb128_ptr_104[id_13] };
            uint32_t id_15 { 128U };
            uint8_t id_16 { 0 };
            uint32_t id_17 { leb128_sz_103[id_16] };
            bool id_18 { bool(id_15 > id_17) };
            uint8_t choose_res_19;
            if (id_18) {
              uint8_t id_20 { 0 };
              uint32_t id_21 { leb128_sz_103[id_20] };
              uint8_t id_22 { uint8_t(id_21) };
              choose_res_19 = id_22;
            } else {
              uint8_t id_23 { 0 };
              uint32_t id_24 { leb128_sz_103[id_23] };
              uint8_t id_25 { uint8_t(id_24) };
              uint8_t id_26 { 128 };
              uint8_t id_27 { uint8_t(id_25 | id_26) };
              choose_res_19 = id_27;
            }
            Pointer id_28 { id_14.writeU8(choose_res_19) };
            Void id_29 { ((void)(leb128_ptr_104[id_12] = id_28), ::dessser::VOID) };
            (void)id_29;
            uint8_t id_30 { 0 };
            uint8_t id_31 { 0 };
            uint32_t id_32 { leb128_sz_103[id_31] };
            uint8_t id_33 { 7 };
            uint32_t id_34 { uint32_t(id_32 >> id_33) };
            Void id_35 { ((void)(leb128_sz_103[id_30] = id_34), ::dessser::VOID) };
            (void)id_35;
            uint8_t id_36 { 0 };
            uint32_t id_37 { leb128_sz_103[id_36] };
            uint32_t id_38 { 0U };
            bool id_39 { bool(id_37 > id_38) };
            while_flag_11 = id_39;
            if (while_flag_11) {
              (void)::dessser::VOID;
            }
          } while (while_flag_11);
          (void)::dessser::VOID;
          uint8_t id_40 { 0 };
          Pointer id_41 { leb128_ptr_104[id_40] };
          let_res_10 = id_41;
        }
        let_res_8 = let_res_10;
      }
      std::string id_42 { (*p_0).rhs };
      Bytes id_43 { id_42 };
      Pointer id_44 { let_res_8.writeBytes(id_43) };
      let_res_4 = id_44;
    }
    Pointer let_res_45;
    {
      Pointer srec_dst_105 { let_res_4 };
      std::string id_46 { (*p_0).op };
      uint32_t id_47 { (uint32_t)id_46.size() };
      Vec<1, uint32_t> id_48 {  id_47  };
      Pointer let_res_49;
      {
        Vec<1, uint32_t> leb128_sz_106 { id_48 };
        Vec<1, Pointer> id_50 {  srec_dst_105  };
        Pointer let_res_51;
        {
          Vec<1, Pointer> leb128_ptr_107 { id_50 };
          bool while_flag_52 { true };
          do {
            uint8_t id_53 { 0 };
            uint8_t id_54 { 0 };
            Pointer id_55 { leb128_ptr_107[id_54] };
            uint32_t id_56 { 128U };
            uint8_t id_57 { 0 };
            uint32_t id_58 { leb128_sz_106[id_57] };
            bool id_59 { bool(id_56 > id_58) };
            uint8_t choose_res_60;
            if (id_59) {
              uint8_t id_61 { 0 };
              uint32_t id_62 { leb128_sz_106[id_61] };
              uint8_t id_63 { uint8_t(id_62) };
              choose_res_60 = id_63;
            } else {
              uint8_t id_64 { 0 };
              uint32_t id_65 { leb128_sz_106[id_64] };
              uint8_t id_66 { uint8_t(id_65) };
              uint8_t id_67 { 128 };
              uint8_t id_68 { uint8_t(id_66 | id_67) };
              choose_res_60 = id_68;
            }
            Pointer id_69 { id_55.writeU8(choose_res_60) };
            Void id_70 { ((void)(leb128_ptr_107[id_53] = id_69), ::dessser::VOID) };
            (void)id_70;
            uint8_t id_71 { 0 };
            uint8_t id_72 { 0 };
            uint32_t id_73 { leb128_sz_106[id_72] };
            uint8_t id_74 { 7 };
            uint32_t id_75 { uint32_t(id_73 >> id_74) };
            Void id_76 { ((void)(leb128_sz_106[id_71] = id_75), ::dessser::VOID) };
            (void)id_76;
            uint8_t id_77 { 0 };
            uint32_t id_78 { leb128_sz_106[id_77] };
            uint32_t id_79 { 0U };
            bool id_80 { bool(id_78 > id_79) };
            while_flag_52 = id_80;
            if (while_flag_52) {
              (void)::dessser::VOID;
            }
          } while (while_flag_52);
          (void)::dessser::VOID;
          uint8_t id_81 { 0 };
          Pointer id_82 { leb128_ptr_107[id_81] };
          let_res_51 = id_82;
        }
        let_res_49 = let_res_51;
      }
      std::string id_83 { (*p_0).op };
      Bytes id_84 { id_83 };
      Pointer id_85 { let_res_49.writeBytes(id_84) };
      let_res_45 = id_85;
    }
    return let_res_45;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::simple_filter::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{lhs: $field_name; rhs: STRING; op: STRING}")
      (let "sz_98"
        (let "sz_94" (apply (ext-identifier field_name sersize-of-row-binary) (get-field "lhs" (param 0)))
          (add (identifier "sz_94")
            (add
              (let "n_ref_96" (make-vec (string-length (get-field "rhs" (param 0))))
                (let "lebsz_ref_97" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_96")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_97")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_97") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_97")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_97")))))) 
              (size-of-u32 (string-length (get-field "rhs" (param 0)))))))
        (add (identifier "sz_98")
          (add
            (let "n_ref_100" (make-vec (string-length (get-field "op" (param 0))))
              (let "lebsz_ref_101" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_100")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_101")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_101") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_101")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_101")))))) 
            (size-of-u32 (string-length (get-field "op" (param 0))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::simple_filter::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::simple_filter::t> )> fun86 { [&](std::shared_ptr<::dessser::gen::simple_filter::t>  p_0) {
    auto fun87 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t_ext id_88 { (*p_0).lhs };
    Size id_89 { fun87(id_88) };
    Size let_res_90;
    {
      Size sz_94 { id_89 };
      std::string id_91 { (*p_0).rhs };
      uint32_t id_92 { (uint32_t)id_91.size() };
      Vec<1, uint32_t> id_93 {  id_92  };
      Size let_res_94;
      {
        Vec<1, uint32_t> n_ref_96 { id_93 };
        uint32_t id_95 { 1U };
        Vec<1, uint32_t> id_96 {  id_95  };
        Size let_res_97;
        {
          Vec<1, uint32_t> lebsz_ref_97 { id_96 };
          bool while_flag_98 { true };
          do {
            uint8_t id_99 { 0 };
            uint32_t id_100 { n_ref_96[id_99] };
            uint8_t id_101 { 0 };
            uint32_t id_102 { lebsz_ref_97[id_101] };
            uint8_t id_103 { 7 };
            uint32_t id_104 { uint32_t(id_102 << id_103) };
            bool id_105 { bool(id_100 >= id_104) };
            while_flag_98 = id_105;
            if (while_flag_98) {
              uint8_t id_106 { 0 };
              uint8_t id_107 { 0 };
              uint32_t id_108 { lebsz_ref_97[id_107] };
              uint32_t id_109 { 1U };
              uint32_t id_110 { uint32_t(id_108 + id_109) };
              Void id_111 { ((void)(lebsz_ref_97[id_106] = id_110), ::dessser::VOID) };
              (void)id_111;
            }
          } while (while_flag_98);
          (void)::dessser::VOID;
          uint8_t id_112 { 0 };
          uint32_t id_113 { lebsz_ref_97[id_112] };
          Size id_114 { Size(id_113) };
          let_res_97 = id_114;
        }
        let_res_94 = let_res_97;
      }
      std::string id_115 { (*p_0).rhs };
      uint32_t id_116 { (uint32_t)id_115.size() };
      Size id_117 { Size(id_116) };
      Size id_118 { Size(let_res_94 + id_117) };
      Size id_119 { Size(sz_94 + id_118) };
      let_res_90 = id_119;
    }
    Size let_res_120;
    {
      Size sz_98 { let_res_90 };
      std::string id_121 { (*p_0).op };
      uint32_t id_122 { (uint32_t)id_121.size() };
      Vec<1, uint32_t> id_123 {  id_122  };
      Size let_res_124;
      {
        Vec<1, uint32_t> n_ref_100 { id_123 };
        uint32_t id_125 { 1U };
        Vec<1, uint32_t> id_126 {  id_125  };
        Size let_res_127;
        {
          Vec<1, uint32_t> lebsz_ref_101 { id_126 };
          bool while_flag_128 { true };
          do {
            uint8_t id_129 { 0 };
            uint32_t id_130 { n_ref_100[id_129] };
            uint8_t id_131 { 0 };
            uint32_t id_132 { lebsz_ref_101[id_131] };
            uint8_t id_133 { 7 };
            uint32_t id_134 { uint32_t(id_132 << id_133) };
            bool id_135 { bool(id_130 >= id_134) };
            while_flag_128 = id_135;
            if (while_flag_128) {
              uint8_t id_136 { 0 };
              uint8_t id_137 { 0 };
              uint32_t id_138 { lebsz_ref_101[id_137] };
              uint32_t id_139 { 1U };
              uint32_t id_140 { uint32_t(id_138 + id_139) };
              Void id_141 { ((void)(lebsz_ref_101[id_136] = id_140), ::dessser::VOID) };
              (void)id_141;
            }
          } while (while_flag_128);
          (void)::dessser::VOID;
          uint8_t id_142 { 0 };
          uint32_t id_143 { lebsz_ref_101[id_142] };
          Size id_144 { Size(id_143) };
          let_res_127 = id_144;
        }
        let_res_124 = let_res_127;
      }
      std::string id_145 { (*p_0).op };
      uint32_t id_146 { (uint32_t)id_145.size() };
      Size id_147 { Size(id_146) };
      Size id_148 { Size(let_res_124 + id_147) };
      Size id_149 { Size(sz_98 + id_148) };
      let_res_120 = id_149;
    }
    return let_res_120;
  }
   };
  return fun86;
}
std::function<Size(std::shared_ptr<::dessser::gen::simple_filter::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_57" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "drec_fst_58" "drec_snd_59" (identifier "drec_57")
          (let "drec_72"
            (let "dstring1_66"
              (let "leb_ref_60" (make-vec (u32 0))
                (let "shft_ref_61" (make-vec (u8 0))
                  (let "p_ref_62" (make-vec (identifier "drec_snd_59"))
                    (seq
                      (while
                        (let "leb128_63" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_62")))
                          (let-pair "leb128_fst_64" "leb128_snd_65" (identifier "leb128_63")
                            (seq (set-vec (u8 0) (identifier "p_ref_62") (identifier "leb128_snd_65"))
                              (set-vec (u8 0) (identifier "leb_ref_60")
                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_64") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_61"))) (unsafe-nth (u8 0) (identifier "leb_ref_60"))))
                              (set-vec (u8 0) (identifier "shft_ref_61") (add (unsafe-nth (u8 0) (identifier "shft_ref_61")) (u8 7))) 
                              (ge (identifier "leb128_fst_64") (u8 128))))) 
                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_60"))) (unsafe-nth (u8 0) (identifier "p_ref_62")))))))
              (let-pair "dstring1_fst_67" "dstring1_snd_68" (identifier "dstring1_66")
                (let-pair "dstring2_fst_70" "dstring2_snd_71" (read-bytes (identifier "dstring1_snd_68") (identifier "dstring1_fst_67")) (make-tup (string-of-bytes (identifier "dstring2_fst_70")) (identifier "dstring2_snd_71")))))
            (let-pair "drec_fst_73" "drec_snd_74" (identifier "drec_72")
              (let "dstring1_81"
                (let "leb_ref_75" (make-vec (u32 0))
                  (let "shft_ref_76" (make-vec (u8 0))
                    (let "p_ref_77" (make-vec (identifier "drec_snd_74"))
                      (seq
                        (while
                          (let "leb128_78" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_77")))
                            (let-pair "leb128_fst_79" "leb128_snd_80" 
                              (identifier "leb128_78")
                              (seq (set-vec (u8 0) (identifier "p_ref_77") (identifier "leb128_snd_80"))
                                (set-vec (u8 0) (identifier "leb_ref_75")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_79") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_76"))) (unsafe-nth (u8 0) (identifier "leb_ref_75"))))
                                (set-vec (u8 0) (identifier "shft_ref_76") (add (unsafe-nth (u8 0) (identifier "shft_ref_76")) (u8 7))) 
                                (ge (identifier "leb128_fst_79") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_75"))) (unsafe-nth (u8 0) (identifier "p_ref_77")))))))
                (let-pair "dstring1_fst_82" "dstring1_snd_83" (identifier "dstring1_81")
                  (let-pair "dstring2_fst_85" "dstring2_snd_86" (read-bytes (identifier "dstring1_snd_83") (identifier "dstring1_fst_82"))
                    (make-tup (make-rec (string "op") (string-of-bytes (identifier "dstring2_fst_85")) (string "rhs") (identifier "drec_fst_73") (string "lhs") (identifier "drec_fst_58")) (identifier "dstring2_snd_86"))))))))))
 */
static std::function<::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1(Pointer)> fun150 { [&](Pointer p_0) {
    auto fun151 { dessser::gen::field_name::of_row_binary };
    ::dessser::gen::simple_filter::t18cecf882d7ac80cef37dfe6b22279d4 id_152 { fun151(p_0) };
    ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 let_res_153;
    {
      ::dessser::gen::simple_filter::t18cecf882d7ac80cef37dfe6b22279d4 drec_57 { id_152 };
      ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 letpair_res_154;
      {
        auto drec_fst_58 { std::get<0>(drec_57) };
        auto drec_snd_59 { std::get<1>(drec_57) };
        uint32_t id_155 { 0U };
        Vec<1, uint32_t> id_156 {  id_155  };
        ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa let_res_157;
        {
          Vec<1, uint32_t> leb_ref_60 { id_156 };
          uint8_t id_158 { 0 };
          Vec<1, uint8_t> id_159 {  id_158  };
          ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa let_res_160;
          {
            Vec<1, uint8_t> shft_ref_61 { id_159 };
            Vec<1, Pointer> id_161 {  drec_snd_59  };
            ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa let_res_162;
            {
              Vec<1, Pointer> p_ref_62 { id_161 };
              bool while_flag_163 { true };
              do {
                uint8_t id_164 { 0 };
                Pointer id_165 { p_ref_62[id_164] };
                ::dessser::gen::simple_filter::t1a5d74abf838df33f185a72a8912f5c9 id_166 { id_165.readU8() };
                bool let_res_167;
                {
                  ::dessser::gen::simple_filter::t1a5d74abf838df33f185a72a8912f5c9 leb128_63 { id_166 };
                  bool letpair_res_168;
                  {
                    auto leb128_fst_64 { std::get<0>(leb128_63) };
                    auto leb128_snd_65 { std::get<1>(leb128_63) };
                    uint8_t id_169 { 0 };
                    Void id_170 { ((void)(p_ref_62[id_169] = leb128_snd_65), ::dessser::VOID) };
                    (void)id_170;
                    uint8_t id_171 { 0 };
                    uint8_t id_172 { 127 };
                    uint8_t id_173 { uint8_t(leb128_fst_64 & id_172) };
                    uint32_t id_174 { uint32_t(id_173) };
                    uint8_t id_175 { 0 };
                    uint8_t id_176 { shft_ref_61[id_175] };
                    uint32_t id_177 { uint32_t(id_174 << id_176) };
                    uint8_t id_178 { 0 };
                    uint32_t id_179 { leb_ref_60[id_178] };
                    uint32_t id_180 { uint32_t(id_177 | id_179) };
                    Void id_181 { ((void)(leb_ref_60[id_171] = id_180), ::dessser::VOID) };
                    (void)id_181;
                    uint8_t id_182 { 0 };
                    uint8_t id_183 { 0 };
                    uint8_t id_184 { shft_ref_61[id_183] };
                    uint8_t id_185 { 7 };
                    uint8_t id_186 { uint8_t(id_184 + id_185) };
                    Void id_187 { ((void)(shft_ref_61[id_182] = id_186), ::dessser::VOID) };
                    (void)id_187;
                    uint8_t id_188 { 128 };
                    bool id_189 { bool(leb128_fst_64 >= id_188) };
                    letpair_res_168 = id_189;
                  }
                  let_res_167 = letpair_res_168;
                }
                while_flag_163 = let_res_167;
                if (while_flag_163) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_163);
              (void)::dessser::VOID;
              uint8_t id_190 { 0 };
              uint32_t id_191 { leb_ref_60[id_190] };
              Size id_192 { Size(id_191) };
              uint8_t id_193 { 0 };
              Pointer id_194 { p_ref_62[id_193] };
              ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa id_195 { id_192, id_194 };
              let_res_162 = id_195;
            }
            let_res_160 = let_res_162;
          }
          let_res_157 = let_res_160;
        }
        ::dessser::gen::simple_filter::t13a07ee37ab40962540da8534858dc07 let_res_196;
        {
          ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa dstring1_66 { let_res_157 };
          ::dessser::gen::simple_filter::t13a07ee37ab40962540da8534858dc07 letpair_res_197;
          {
            auto dstring1_fst_67 { std::get<0>(dstring1_66) };
            auto dstring1_snd_68 { std::get<1>(dstring1_66) };
            ::dessser::gen::simple_filter::t9ef6882174ae71a34a3c5ef6b29242fb id_198 { dstring1_snd_68.readBytes(dstring1_fst_67) };
            ::dessser::gen::simple_filter::t13a07ee37ab40962540da8534858dc07 letpair_res_199;
            {
              auto dstring2_fst_70 { std::get<0>(id_198) };
              auto dstring2_snd_71 { std::get<1>(id_198) };
              std::string id_200 { dstring2_fst_70.toString() };
              ::dessser::gen::simple_filter::t13a07ee37ab40962540da8534858dc07 id_201 { id_200, dstring2_snd_71 };
              letpair_res_199 = id_201;
            }
            letpair_res_197 = letpair_res_199;
          }
          let_res_196 = letpair_res_197;
        }
        ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 let_res_202;
        {
          ::dessser::gen::simple_filter::t13a07ee37ab40962540da8534858dc07 drec_72 { let_res_196 };
          ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 letpair_res_203;
          {
            auto drec_fst_73 { std::get<0>(drec_72) };
            auto drec_snd_74 { std::get<1>(drec_72) };
            uint32_t id_204 { 0U };
            Vec<1, uint32_t> id_205 {  id_204  };
            ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa let_res_206;
            {
              Vec<1, uint32_t> leb_ref_75 { id_205 };
              uint8_t id_207 { 0 };
              Vec<1, uint8_t> id_208 {  id_207  };
              ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa let_res_209;
              {
                Vec<1, uint8_t> shft_ref_76 { id_208 };
                Vec<1, Pointer> id_210 {  drec_snd_74  };
                ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa let_res_211;
                {
                  Vec<1, Pointer> p_ref_77 { id_210 };
                  bool while_flag_212 { true };
                  do {
                    uint8_t id_213 { 0 };
                    Pointer id_214 { p_ref_77[id_213] };
                    ::dessser::gen::simple_filter::t1a5d74abf838df33f185a72a8912f5c9 id_215 { id_214.readU8() };
                    bool let_res_216;
                    {
                      ::dessser::gen::simple_filter::t1a5d74abf838df33f185a72a8912f5c9 leb128_78 { id_215 };
                      bool letpair_res_217;
                      {
                        auto leb128_fst_79 { std::get<0>(leb128_78) };
                        auto leb128_snd_80 { std::get<1>(leb128_78) };
                        uint8_t id_218 { 0 };
                        Void id_219 { ((void)(p_ref_77[id_218] = leb128_snd_80), ::dessser::VOID) };
                        (void)id_219;
                        uint8_t id_220 { 0 };
                        uint8_t id_221 { 127 };
                        uint8_t id_222 { uint8_t(leb128_fst_79 & id_221) };
                        uint32_t id_223 { uint32_t(id_222) };
                        uint8_t id_224 { 0 };
                        uint8_t id_225 { shft_ref_76[id_224] };
                        uint32_t id_226 { uint32_t(id_223 << id_225) };
                        uint8_t id_227 { 0 };
                        uint32_t id_228 { leb_ref_75[id_227] };
                        uint32_t id_229 { uint32_t(id_226 | id_228) };
                        Void id_230 { ((void)(leb_ref_75[id_220] = id_229), ::dessser::VOID) };
                        (void)id_230;
                        uint8_t id_231 { 0 };
                        uint8_t id_232 { 0 };
                        uint8_t id_233 { shft_ref_76[id_232] };
                        uint8_t id_234 { 7 };
                        uint8_t id_235 { uint8_t(id_233 + id_234) };
                        Void id_236 { ((void)(shft_ref_76[id_231] = id_235), ::dessser::VOID) };
                        (void)id_236;
                        uint8_t id_237 { 128 };
                        bool id_238 { bool(leb128_fst_79 >= id_237) };
                        letpair_res_217 = id_238;
                      }
                      let_res_216 = letpair_res_217;
                    }
                    while_flag_212 = let_res_216;
                    if (while_flag_212) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_212);
                  (void)::dessser::VOID;
                  uint8_t id_239 { 0 };
                  uint32_t id_240 { leb_ref_75[id_239] };
                  Size id_241 { Size(id_240) };
                  uint8_t id_242 { 0 };
                  Pointer id_243 { p_ref_77[id_242] };
                  ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa id_244 { id_241, id_243 };
                  let_res_211 = id_244;
                }
                let_res_209 = let_res_211;
              }
              let_res_206 = let_res_209;
            }
            ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 let_res_245;
            {
              ::dessser::gen::simple_filter::t12fb9c475959b52bf7b17b155a955ffa dstring1_81 { let_res_206 };
              ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 letpair_res_246;
              {
                auto dstring1_fst_82 { std::get<0>(dstring1_81) };
                auto dstring1_snd_83 { std::get<1>(dstring1_81) };
                ::dessser::gen::simple_filter::t9ef6882174ae71a34a3c5ef6b29242fb id_247 { dstring1_snd_83.readBytes(dstring1_fst_82) };
                ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 letpair_res_248;
                {
                  auto dstring2_fst_85 { std::get<0>(id_247) };
                  auto dstring2_snd_86 { std::get<1>(id_247) };
                  std::string id_249 { dstring2_fst_85.toString() };
                  std::shared_ptr<::dessser::gen::simple_filter::t>  id_250 { std::make_shared<::dessser::gen::simple_filter::t>(drec_fst_58, drec_fst_73, id_249) };
                  ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 id_251 { id_250, dstring2_snd_86 };
                  letpair_res_248 = id_251;
                }
                letpair_res_246 = letpair_res_248;
              }
              let_res_245 = letpair_res_246;
            }
            letpair_res_203 = let_res_245;
          }
          let_res_202 = letpair_res_203;
        }
        letpair_res_154 = let_res_202;
      }
      let_res_153 = letpair_res_154;
    }
    return let_res_153;
  }
   };
  return fun150;
}
std::function<::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_91" "make_snd_92" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_91") (identifier "make_snd_92"))))
 */
static std::function<::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1(Pointer)> fun252 { [&](Pointer p_0) {
    ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 id_253 { of_row_binary(p_0) };
    ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 letpair_res_254;
    {
      auto make_fst_91 { std::get<0>(id_253) };
      auto make_snd_92 { std::get<1>(id_253) };
      ::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1 id_255 { make_fst_91, make_snd_92 };
      letpair_res_254 = id_255;
    }
    return letpair_res_254;
  }
   };
  return fun252;
}
std::function<::dessser::gen::simple_filter::tb507a8f2c568f9319d8e16dafa079fc1(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{lhs: $field_name; rhs: STRING; op: STRING}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::simple_filter::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::simple_filter::t> ,Pointer)> fun256 { [&](std::shared_ptr<::dessser::gen::simple_filter::t>  p_0, Pointer p_1) {
    Pointer id_257 { to_row_binary(p_0, p_1) };
    return id_257;
  }
   };
  return fun256;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::simple_filter::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
