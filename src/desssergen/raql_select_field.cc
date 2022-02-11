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
#include "desssergen/raql_expr.h"

namespace dessser::gen::raql_select_field {
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
  dessser::gen::raql_expr::t_ext expr;
  dessser::gen::field_name::t_ext alias;
  std::string doc;
  std::optional<std::string> aggr;
  t(dessser::gen::raql_expr::t_ext expr_, dessser::gen::field_name::t_ext alias_, std::string doc_, std::optional<std::string> aggr_) : expr(expr_), alias(alias_), doc(doc_), aggr(aggr_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::raql_expr::Deref(a.expr) == ::dessser::gen::raql_expr::Deref(b.expr) && ::dessser::gen::field_name::Deref(a.alias) == ::dessser::gen::field_name::Deref(b.alias) && a.doc == b.doc && ((a.aggr && b.aggr && a.aggr.value() == b.aggr.value()) || (!a.aggr && !b.aggr));
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t3569225fb8bfc5f25806a8899fbad91d : public std::tuple<
  ::dessser::gen::raql_select_field::t,
  Pointer
> {
  using tuple::tuple;
  t3569225fb8bfc5f25806a8899fbad91d(std::tuple<::dessser::gen::raql_select_field::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_select_field::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3569225fb8bfc5f25806a8899fbad91d const &a, t3569225fb8bfc5f25806a8899fbad91d const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3569225fb8bfc5f25806a8899fbad91d const &a, t3569225fb8bfc5f25806a8899fbad91d const &b) {
  return !operator==(a, b);
}
struct tc473a3a3b5068e57b15e934d0afcc038 : public std::tuple<
  dessser::gen::raql_expr::t_ext,
  Pointer
> {
  using tuple::tuple;
  tc473a3a3b5068e57b15e934d0afcc038(std::tuple<dessser::gen::raql_expr::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_expr::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc473a3a3b5068e57b15e934d0afcc038 const &a, tc473a3a3b5068e57b15e934d0afcc038 const &b) {
  return ::dessser::gen::raql_expr::Deref(std::get<0>(a)) == ::dessser::gen::raql_expr::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc473a3a3b5068e57b15e934d0afcc038 const &a, tc473a3a3b5068e57b15e934d0afcc038 const &b) {
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
struct ta18b971ad5bf537b68fb1bbf5fd2b926 : public std::tuple<
  std::optional<std::string>,
  Pointer
> {
  using tuple::tuple;
  ta18b971ad5bf537b68fb1bbf5fd2b926(std::tuple<std::optional<std::string>, Pointer> p)
    : std::tuple<std::optional<std::string>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta18b971ad5bf537b68fb1bbf5fd2b926 const &a, ta18b971ad5bf537b68fb1bbf5fd2b926 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta18b971ad5bf537b68fb1bbf5fd2b926 const &a, ta18b971ad5bf537b68fb1bbf5fd2b926 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{expr: $raql_expr; alias: $field_name; doc: STRING; aggr: STRING?}" "Ptr")
      (let "srec_dst_113"
        (let "srec_dst_110"
          (let "srec_dst_109" (apply (ext-identifier raql_expr to-row-binary) (get-field "expr" (param 0)) (param 1)) (apply (ext-identifier field_name to-row-binary) (get-field "alias" (param 0)) (identifier "srec_dst_109")))
          (write-bytes
            (let "leb128_sz_111" (make-vec (string-length (get-field "doc" (param 0))))
              (let "leb128_ptr_112" (make-vec (identifier "srec_dst_110"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_112")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_112"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_111"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_111"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_111"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_111") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_111")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_111")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_112"))))) 
            (bytes-of-string (get-field "doc" (param 0)))))
        (if (is-null (get-field "aggr" (param 0))) (write-u8 (identifier "srec_dst_113") (u8 1))
          (write-bytes
            (let "leb128_sz_114" (make-vec (string-length (force (get-field "aggr" (param 0)))))
              (let "leb128_ptr_115" (make-vec (write-u8 (identifier "srec_dst_113") (u8 0)))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_115")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_115"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_114"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_114"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_114"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_114") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_114")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_114")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_115"))))) 
            (bytes-of-string (force (get-field "aggr" (param 0))))))))
 */
static std::function<Pointer(::dessser::gen::raql_select_field::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_select_field::t &,Pointer &)> fun0 { [&](::dessser::gen::raql_select_field::t p_0, Pointer p_1) {
    auto fun1 { dessser::gen::raql_expr::to_row_binary };
    dessser::gen::raql_expr::t_ext id_2 { p_0.expr };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_109 { id_3 };
      auto fun5 { dessser::gen::field_name::to_row_binary };
      dessser::gen::field_name::t_ext id_6 { p_0.alias };
      Pointer id_7 { fun5(id_6, srec_dst_109) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_110 { let_res_4 };
      std::string id_9 { p_0.doc };
      uint32_t id_10 { (uint32_t)id_9.size() };
      Vec<1, uint32_t> id_11 {  id_10  };
      Pointer let_res_12;
      {
        Vec<1, uint32_t> leb128_sz_111 { id_11 };
        Vec<1, Pointer> id_13 {  srec_dst_110  };
        Pointer let_res_14;
        {
          Vec<1, Pointer> leb128_ptr_112 { id_13 };
          bool while_flag_15 { true };
          do {
            uint8_t id_16 { 0 };
            uint8_t id_17 { 0 };
            Pointer id_18 { leb128_ptr_112[id_17] };
            uint32_t id_19 { 128U };
            uint8_t id_20 { 0 };
            uint32_t id_21 { leb128_sz_111[id_20] };
            bool id_22 { bool(id_19 > id_21) };
            uint8_t choose_res_23;
            if (id_22) {
              uint8_t id_24 { 0 };
              uint32_t id_25 { leb128_sz_111[id_24] };
              uint8_t id_26 { uint8_t(id_25) };
              choose_res_23 = id_26;
            } else {
              uint8_t id_27 { 0 };
              uint32_t id_28 { leb128_sz_111[id_27] };
              uint8_t id_29 { uint8_t(id_28) };
              uint8_t id_30 { 128 };
              uint8_t id_31 { uint8_t(id_29 | id_30) };
              choose_res_23 = id_31;
            }
            Pointer id_32 { id_18.writeU8(choose_res_23) };
            Void id_33 { ((void)(leb128_ptr_112[id_16] = id_32), ::dessser::Void()) };
            (void)id_33;
            uint8_t id_34 { 0 };
            uint8_t id_35 { 0 };
            uint32_t id_36 { leb128_sz_111[id_35] };
            uint8_t id_37 { 7 };
            uint32_t id_38 { uint32_t(id_36 >> id_37) };
            Void id_39 { ((void)(leb128_sz_111[id_34] = id_38), ::dessser::Void()) };
            (void)id_39;
            uint8_t id_40 { 0 };
            uint32_t id_41 { leb128_sz_111[id_40] };
            uint32_t id_42 { 0U };
            bool id_43 { bool(id_41 > id_42) };
            while_flag_15 = id_43;
            if (while_flag_15) {
              (void)::dessser::Void();
            }
          } while (while_flag_15);
          (void)::dessser::Void();
          uint8_t id_44 { 0 };
          Pointer id_45 { leb128_ptr_112[id_44] };
          let_res_14 = id_45;
        }
        let_res_12 = let_res_14;
      }
      std::string id_46 { p_0.doc };
      Bytes id_47 { id_46 };
      Pointer id_48 { let_res_12.writeBytes(id_47) };
      let_res_8 = id_48;
    }
    Pointer let_res_49;
    {
      Pointer srec_dst_113 { let_res_8 };
      std::optional<std::string> id_50 { p_0.aggr };
      bool id_51 { !(id_50.has_value ()) };
      Pointer choose_res_52;
      if (id_51) {
        uint8_t id_53 { 1 };
        Pointer id_54 { srec_dst_113.writeU8(id_53) };
        choose_res_52 = id_54;
      } else {
        std::optional<std::string> id_55 { p_0.aggr };
        std::string id_56 { id_55.value() };
        uint32_t id_57 { (uint32_t)id_56.size() };
        Vec<1, uint32_t> id_58 {  id_57  };
        Pointer let_res_59;
        {
          Vec<1, uint32_t> leb128_sz_114 { id_58 };
          uint8_t id_60 { 0 };
          Pointer id_61 { srec_dst_113.writeU8(id_60) };
          Vec<1, Pointer> id_62 {  id_61  };
          Pointer let_res_63;
          {
            Vec<1, Pointer> leb128_ptr_115 { id_62 };
            bool while_flag_64 { true };
            do {
              uint8_t id_65 { 0 };
              uint8_t id_66 { 0 };
              Pointer id_67 { leb128_ptr_115[id_66] };
              uint32_t id_68 { 128U };
              uint8_t id_69 { 0 };
              uint32_t id_70 { leb128_sz_114[id_69] };
              bool id_71 { bool(id_68 > id_70) };
              uint8_t choose_res_72;
              if (id_71) {
                uint8_t id_73 { 0 };
                uint32_t id_74 { leb128_sz_114[id_73] };
                uint8_t id_75 { uint8_t(id_74) };
                choose_res_72 = id_75;
              } else {
                uint8_t id_76 { 0 };
                uint32_t id_77 { leb128_sz_114[id_76] };
                uint8_t id_78 { uint8_t(id_77) };
                uint8_t id_79 { 128 };
                uint8_t id_80 { uint8_t(id_78 | id_79) };
                choose_res_72 = id_80;
              }
              Pointer id_81 { id_67.writeU8(choose_res_72) };
              Void id_82 { ((void)(leb128_ptr_115[id_65] = id_81), ::dessser::Void()) };
              (void)id_82;
              uint8_t id_83 { 0 };
              uint8_t id_84 { 0 };
              uint32_t id_85 { leb128_sz_114[id_84] };
              uint8_t id_86 { 7 };
              uint32_t id_87 { uint32_t(id_85 >> id_86) };
              Void id_88 { ((void)(leb128_sz_114[id_83] = id_87), ::dessser::Void()) };
              (void)id_88;
              uint8_t id_89 { 0 };
              uint32_t id_90 { leb128_sz_114[id_89] };
              uint32_t id_91 { 0U };
              bool id_92 { bool(id_90 > id_91) };
              while_flag_64 = id_92;
              if (while_flag_64) {
                (void)::dessser::Void();
              }
            } while (while_flag_64);
            (void)::dessser::Void();
            uint8_t id_93 { 0 };
            Pointer id_94 { leb128_ptr_115[id_93] };
            let_res_63 = id_94;
          }
          let_res_59 = let_res_63;
        }
        std::optional<std::string> id_95 { p_0.aggr };
        std::string id_96 { id_95.value() };
        Bytes id_97 { id_96 };
        Pointer id_98 { let_res_59.writeBytes(id_97) };
        choose_res_52 = id_98;
      }
      let_res_49 = choose_res_52;
    }
    return let_res_49;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::raql_select_field::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{expr: $raql_expr; alias: $field_name; doc: STRING; aggr: STRING?}")
      (let "sz_105"
        (let "sz_101"
          (let "sz_100" (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "expr" (param 0))) (add (identifier "sz_100") (apply (ext-identifier field_name sersize-of-row-binary) (get-field "alias" (param 0)))))
          (add (identifier "sz_101")
            (add
              (let "n_ref_103" (make-vec (string-length (get-field "doc" (param 0))))
                (let "lebsz_ref_104" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_103")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_104")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_104") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_104")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_104")))))) 
              (size-of-u32 (string-length (get-field "doc" (param 0)))))))
        (if (is-null (get-field "aggr" (param 0))) (add (identifier "sz_105") (size 1))
          (add
            (add (identifier "sz_105")
              (add
                (let "n_ref_107" (make-vec (string-length (force (get-field "aggr" (param 0)))))
                  (let "lebsz_ref_108" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_107")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_108")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_108") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_108")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_108")))))) 
                (size-of-u32 (string-length (force (get-field "aggr" (param 0))))))) 
            (size 1)))))
 */
static std::function<Size(::dessser::gen::raql_select_field::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_select_field::t &)> fun99 { [&](::dessser::gen::raql_select_field::t p_0) {
    auto fun100 { dessser::gen::raql_expr::sersize_of_row_binary };
    dessser::gen::raql_expr::t_ext id_101 { p_0.expr };
    Size id_102 { fun100(id_101) };
    Size let_res_103;
    {
      Size sz_100 { id_102 };
      auto fun104 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_105 { p_0.alias };
      Size id_106 { fun104(id_105) };
      Size id_107 { Size(sz_100 + id_106) };
      let_res_103 = id_107;
    }
    Size let_res_108;
    {
      Size sz_101 { let_res_103 };
      std::string id_109 { p_0.doc };
      uint32_t id_110 { (uint32_t)id_109.size() };
      Vec<1, uint32_t> id_111 {  id_110  };
      Size let_res_112;
      {
        Vec<1, uint32_t> n_ref_103 { id_111 };
        uint32_t id_113 { 1U };
        Vec<1, uint32_t> id_114 {  id_113  };
        Size let_res_115;
        {
          Vec<1, uint32_t> lebsz_ref_104 { id_114 };
          bool while_flag_116 { true };
          do {
            uint8_t id_117 { 0 };
            uint32_t id_118 { n_ref_103[id_117] };
            uint8_t id_119 { 0 };
            uint32_t id_120 { lebsz_ref_104[id_119] };
            uint8_t id_121 { 7 };
            uint32_t id_122 { uint32_t(id_120 << id_121) };
            bool id_123 { bool(id_118 >= id_122) };
            while_flag_116 = id_123;
            if (while_flag_116) {
              uint8_t id_124 { 0 };
              uint8_t id_125 { 0 };
              uint32_t id_126 { lebsz_ref_104[id_125] };
              uint32_t id_127 { 1U };
              uint32_t id_128 { uint32_t(id_126 + id_127) };
              Void id_129 { ((void)(lebsz_ref_104[id_124] = id_128), ::dessser::Void()) };
              (void)id_129;
            }
          } while (while_flag_116);
          (void)::dessser::Void();
          uint8_t id_130 { 0 };
          uint32_t id_131 { lebsz_ref_104[id_130] };
          Size id_132 { Size(id_131) };
          let_res_115 = id_132;
        }
        let_res_112 = let_res_115;
      }
      std::string id_133 { p_0.doc };
      uint32_t id_134 { (uint32_t)id_133.size() };
      Size id_135 { Size(id_134) };
      Size id_136 { Size(let_res_112 + id_135) };
      Size id_137 { Size(sz_101 + id_136) };
      let_res_108 = id_137;
    }
    Size let_res_138;
    {
      Size sz_105 { let_res_108 };
      std::optional<std::string> id_139 { p_0.aggr };
      bool id_140 { !(id_139.has_value ()) };
      Size choose_res_141;
      if (id_140) {
        Size id_142 { 1UL };
        Size id_143 { Size(sz_105 + id_142) };
        choose_res_141 = id_143;
      } else {
        std::optional<std::string> id_144 { p_0.aggr };
        std::string id_145 { id_144.value() };
        uint32_t id_146 { (uint32_t)id_145.size() };
        Vec<1, uint32_t> id_147 {  id_146  };
        Size let_res_148;
        {
          Vec<1, uint32_t> n_ref_107 { id_147 };
          uint32_t id_149 { 1U };
          Vec<1, uint32_t> id_150 {  id_149  };
          Size let_res_151;
          {
            Vec<1, uint32_t> lebsz_ref_108 { id_150 };
            bool while_flag_152 { true };
            do {
              uint8_t id_153 { 0 };
              uint32_t id_154 { n_ref_107[id_153] };
              uint8_t id_155 { 0 };
              uint32_t id_156 { lebsz_ref_108[id_155] };
              uint8_t id_157 { 7 };
              uint32_t id_158 { uint32_t(id_156 << id_157) };
              bool id_159 { bool(id_154 >= id_158) };
              while_flag_152 = id_159;
              if (while_flag_152) {
                uint8_t id_160 { 0 };
                uint8_t id_161 { 0 };
                uint32_t id_162 { lebsz_ref_108[id_161] };
                uint32_t id_163 { 1U };
                uint32_t id_164 { uint32_t(id_162 + id_163) };
                Void id_165 { ((void)(lebsz_ref_108[id_160] = id_164), ::dessser::Void()) };
                (void)id_165;
              }
            } while (while_flag_152);
            (void)::dessser::Void();
            uint8_t id_166 { 0 };
            uint32_t id_167 { lebsz_ref_108[id_166] };
            Size id_168 { Size(id_167) };
            let_res_151 = id_168;
          }
          let_res_148 = let_res_151;
        }
        std::optional<std::string> id_169 { p_0.aggr };
        std::string id_170 { id_169.value() };
        uint32_t id_171 { (uint32_t)id_170.size() };
        Size id_172 { Size(id_171) };
        Size id_173 { Size(let_res_148 + id_172) };
        Size id_174 { Size(sz_105 + id_173) };
        Size id_175 { 1UL };
        Size id_176 { Size(id_174 + id_175) };
        choose_res_141 = id_176;
      }
      let_res_138 = choose_res_141;
    }
    return let_res_138;
  }
   };
  return fun99;
}
std::function<Size(::dessser::gen::raql_select_field::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_57" (apply (ext-identifier raql_expr of-row-binary) (param 0))
        (let-pair "drec_fst_58" "drec_snd_59" (identifier "drec_57")
          (let "drec_60" (apply (ext-identifier field_name of-row-binary) (identifier "drec_snd_59"))
            (let-pair "drec_fst_61" "drec_snd_62" (identifier "drec_60")
              (let "drec_75"
                (let "dstring1_69"
                  (let "leb_ref_63" (make-vec (u32 0))
                    (let "shft_ref_64" (make-vec (u8 0))
                      (let "p_ref_65" (make-vec (identifier "drec_snd_62"))
                        (seq
                          (while
                            (let "leb128_66" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_65")))
                              (let-pair "leb128_fst_67" "leb128_snd_68" 
                                (identifier "leb128_66")
                                (seq (set-vec (u8 0) (identifier "p_ref_65") (identifier "leb128_snd_68"))
                                  (set-vec (u8 0) (identifier "leb_ref_63")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_67") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_64"))) (unsafe-nth (u8 0) (identifier "leb_ref_63"))))
                                  (set-vec (u8 0) (identifier "shft_ref_64") (add (unsafe-nth (u8 0) (identifier "shft_ref_64")) (u8 7))) 
                                  (ge (identifier "leb128_fst_67") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_63"))) (unsafe-nth (u8 0) (identifier "p_ref_65")))))))
                  (let-pair "dstring1_fst_70" "dstring1_snd_71" (identifier "dstring1_69")
                    (let-pair "dstring2_fst_73" "dstring2_snd_74" (read-bytes (identifier "dstring1_snd_71") (identifier "dstring1_fst_70"))
                      (make-tup (string-of-bytes (identifier "dstring2_fst_73")) (identifier "dstring2_snd_74")))))
                (let-pair "drec_fst_76" "drec_snd_77" (identifier "drec_75")
                  (let-pair "drec_fst_94" "drec_snd_95"
                    (if (eq (peek-u8 (identifier "drec_snd_77") (size 0)) (u8 1)) 
                      (make-tup (null "STRING") (ptr-add (identifier "drec_snd_77") (size 1)))
                      (let "dstring1_84"
                        (let "leb_ref_78" (make-vec (u32 0))
                          (let "shft_ref_79" (make-vec (u8 0))
                            (let "p_ref_80" (make-vec (ptr-add (identifier "drec_snd_77") (size 1)))
                              (seq
                                (while
                                  (let "leb128_81" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_80")))
                                    (let-pair "leb128_fst_82" "leb128_snd_83" 
                                      (identifier "leb128_81")
                                      (seq (set-vec (u8 0) (identifier "p_ref_80") (identifier "leb128_snd_83"))
                                        (set-vec (u8 0) (identifier "leb_ref_78")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_82") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_79"))) (unsafe-nth (u8 0) (identifier "leb_ref_78"))))
                                        (set-vec (u8 0) (identifier "shft_ref_79") (add (unsafe-nth (u8 0) (identifier "shft_ref_79")) (u8 7))) 
                                        (ge (identifier "leb128_fst_82") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_78"))) (unsafe-nth (u8 0) (identifier "p_ref_80")))))))
                        (let-pair "dstring1_fst_85" "dstring1_snd_86" 
                          (identifier "dstring1_84")
                          (let-pair "dstring2_fst_88" "dstring2_snd_89" 
                            (read-bytes (identifier "dstring1_snd_86") (identifier "dstring1_fst_85")) 
                            (make-tup (not-null (string-of-bytes (identifier "dstring2_fst_88"))) (identifier "dstring2_snd_89"))))))
                    (make-tup (make-rec (string "aggr") (identifier "drec_fst_94") (string "doc") (identifier "drec_fst_76") (string "alias") (identifier "drec_fst_61") (string "expr") (identifier "drec_fst_58"))
                      (identifier "drec_snd_95"))))))))))
 */
static std::function<::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d(Pointer &)> fun177 { [&](Pointer p_0) {
    auto fun178 { dessser::gen::raql_expr::of_row_binary };
    ::dessser::gen::raql_select_field::tc473a3a3b5068e57b15e934d0afcc038 id_179 { fun178(p_0) };
    ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d let_res_180;
    {
      ::dessser::gen::raql_select_field::tc473a3a3b5068e57b15e934d0afcc038 drec_57 { id_179 };
      ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d letpair_res_181;
      {
        auto drec_fst_58 { std::get<0>(drec_57) };
        auto drec_snd_59 { std::get<1>(drec_57) };
        auto fun182 { dessser::gen::field_name::of_row_binary };
        ::dessser::gen::raql_select_field::t18cecf882d7ac80cef37dfe6b22279d4 id_183 { fun182(drec_snd_59) };
        ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d let_res_184;
        {
          ::dessser::gen::raql_select_field::t18cecf882d7ac80cef37dfe6b22279d4 drec_60 { id_183 };
          ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d letpair_res_185;
          {
            auto drec_fst_61 { std::get<0>(drec_60) };
            auto drec_snd_62 { std::get<1>(drec_60) };
            uint32_t id_186 { 0U };
            Vec<1, uint32_t> id_187 {  id_186  };
            ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa let_res_188;
            {
              Vec<1, uint32_t> leb_ref_63 { id_187 };
              uint8_t id_189 { 0 };
              Vec<1, uint8_t> id_190 {  id_189  };
              ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa let_res_191;
              {
                Vec<1, uint8_t> shft_ref_64 { id_190 };
                Vec<1, Pointer> id_192 {  drec_snd_62  };
                ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa let_res_193;
                {
                  Vec<1, Pointer> p_ref_65 { id_192 };
                  bool while_flag_194 { true };
                  do {
                    uint8_t id_195 { 0 };
                    Pointer id_196 { p_ref_65[id_195] };
                    ::dessser::gen::raql_select_field::t1a5d74abf838df33f185a72a8912f5c9 id_197 { id_196.readU8() };
                    bool let_res_198;
                    {
                      ::dessser::gen::raql_select_field::t1a5d74abf838df33f185a72a8912f5c9 leb128_66 { id_197 };
                      bool letpair_res_199;
                      {
                        auto leb128_fst_67 { std::get<0>(leb128_66) };
                        auto leb128_snd_68 { std::get<1>(leb128_66) };
                        uint8_t id_200 { 0 };
                        Void id_201 { ((void)(p_ref_65[id_200] = leb128_snd_68), ::dessser::Void()) };
                        (void)id_201;
                        uint8_t id_202 { 0 };
                        uint8_t id_203 { 127 };
                        uint8_t id_204 { uint8_t(leb128_fst_67 & id_203) };
                        uint32_t id_205 { uint32_t(id_204) };
                        uint8_t id_206 { 0 };
                        uint8_t id_207 { shft_ref_64[id_206] };
                        uint32_t id_208 { uint32_t(id_205 << id_207) };
                        uint8_t id_209 { 0 };
                        uint32_t id_210 { leb_ref_63[id_209] };
                        uint32_t id_211 { uint32_t(id_208 | id_210) };
                        Void id_212 { ((void)(leb_ref_63[id_202] = id_211), ::dessser::Void()) };
                        (void)id_212;
                        uint8_t id_213 { 0 };
                        uint8_t id_214 { 0 };
                        uint8_t id_215 { shft_ref_64[id_214] };
                        uint8_t id_216 { 7 };
                        uint8_t id_217 { uint8_t(id_215 + id_216) };
                        Void id_218 { ((void)(shft_ref_64[id_213] = id_217), ::dessser::Void()) };
                        (void)id_218;
                        uint8_t id_219 { 128 };
                        bool id_220 { bool(leb128_fst_67 >= id_219) };
                        letpair_res_199 = id_220;
                      }
                      let_res_198 = letpair_res_199;
                    }
                    while_flag_194 = let_res_198;
                    if (while_flag_194) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_194);
                  (void)::dessser::Void();
                  uint8_t id_221 { 0 };
                  uint32_t id_222 { leb_ref_63[id_221] };
                  Size id_223 { Size(id_222) };
                  uint8_t id_224 { 0 };
                  Pointer id_225 { p_ref_65[id_224] };
                  ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa id_226 { id_223, id_225 };
                  let_res_193 = id_226;
                }
                let_res_191 = let_res_193;
              }
              let_res_188 = let_res_191;
            }
            ::dessser::gen::raql_select_field::t13a07ee37ab40962540da8534858dc07 let_res_227;
            {
              ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa dstring1_69 { let_res_188 };
              ::dessser::gen::raql_select_field::t13a07ee37ab40962540da8534858dc07 letpair_res_228;
              {
                auto dstring1_fst_70 { std::get<0>(dstring1_69) };
                auto dstring1_snd_71 { std::get<1>(dstring1_69) };
                ::dessser::gen::raql_select_field::t9ef6882174ae71a34a3c5ef6b29242fb id_229 { dstring1_snd_71.readBytes(dstring1_fst_70) };
                ::dessser::gen::raql_select_field::t13a07ee37ab40962540da8534858dc07 letpair_res_230;
                {
                  auto dstring2_fst_73 { std::get<0>(id_229) };
                  auto dstring2_snd_74 { std::get<1>(id_229) };
                  std::string id_231 { dstring2_fst_73.toString() };
                  ::dessser::gen::raql_select_field::t13a07ee37ab40962540da8534858dc07 id_232 { id_231, dstring2_snd_74 };
                  letpair_res_230 = id_232;
                }
                letpair_res_228 = letpair_res_230;
              }
              let_res_227 = letpair_res_228;
            }
            ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d let_res_233;
            {
              ::dessser::gen::raql_select_field::t13a07ee37ab40962540da8534858dc07 drec_75 { let_res_227 };
              ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d letpair_res_234;
              {
                auto drec_fst_76 { std::get<0>(drec_75) };
                auto drec_snd_77 { std::get<1>(drec_75) };
                Size id_235 { 0UL };
                uint8_t id_236 { drec_snd_77.peekU8(id_235) };
                uint8_t id_237 { 1 };
                bool id_238 { bool(id_236 == id_237) };
                ::dessser::gen::raql_select_field::ta18b971ad5bf537b68fb1bbf5fd2b926 choose_res_239;
                if (id_238) {
                  std::optional<std::string> id_240 { std::nullopt };
                  Size id_241 { 1UL };
                  Pointer id_242 { drec_snd_77.skip(id_241) };
                  ::dessser::gen::raql_select_field::ta18b971ad5bf537b68fb1bbf5fd2b926 id_243 { id_240, id_242 };
                  choose_res_239 = id_243;
                } else {
                  uint32_t id_244 { 0U };
                  Vec<1, uint32_t> id_245 {  id_244  };
                  ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa let_res_246;
                  {
                    Vec<1, uint32_t> leb_ref_78 { id_245 };
                    uint8_t id_247 { 0 };
                    Vec<1, uint8_t> id_248 {  id_247  };
                    ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa let_res_249;
                    {
                      Vec<1, uint8_t> shft_ref_79 { id_248 };
                      Size id_250 { 1UL };
                      Pointer id_251 { drec_snd_77.skip(id_250) };
                      Vec<1, Pointer> id_252 {  id_251  };
                      ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa let_res_253;
                      {
                        Vec<1, Pointer> p_ref_80 { id_252 };
                        bool while_flag_254 { true };
                        do {
                          uint8_t id_255 { 0 };
                          Pointer id_256 { p_ref_80[id_255] };
                          ::dessser::gen::raql_select_field::t1a5d74abf838df33f185a72a8912f5c9 id_257 { id_256.readU8() };
                          bool let_res_258;
                          {
                            ::dessser::gen::raql_select_field::t1a5d74abf838df33f185a72a8912f5c9 leb128_81 { id_257 };
                            bool letpair_res_259;
                            {
                              auto leb128_fst_82 { std::get<0>(leb128_81) };
                              auto leb128_snd_83 { std::get<1>(leb128_81) };
                              uint8_t id_260 { 0 };
                              Void id_261 { ((void)(p_ref_80[id_260] = leb128_snd_83), ::dessser::Void()) };
                              (void)id_261;
                              uint8_t id_262 { 0 };
                              uint8_t id_263 { 127 };
                              uint8_t id_264 { uint8_t(leb128_fst_82 & id_263) };
                              uint32_t id_265 { uint32_t(id_264) };
                              uint8_t id_266 { 0 };
                              uint8_t id_267 { shft_ref_79[id_266] };
                              uint32_t id_268 { uint32_t(id_265 << id_267) };
                              uint8_t id_269 { 0 };
                              uint32_t id_270 { leb_ref_78[id_269] };
                              uint32_t id_271 { uint32_t(id_268 | id_270) };
                              Void id_272 { ((void)(leb_ref_78[id_262] = id_271), ::dessser::Void()) };
                              (void)id_272;
                              uint8_t id_273 { 0 };
                              uint8_t id_274 { 0 };
                              uint8_t id_275 { shft_ref_79[id_274] };
                              uint8_t id_276 { 7 };
                              uint8_t id_277 { uint8_t(id_275 + id_276) };
                              Void id_278 { ((void)(shft_ref_79[id_273] = id_277), ::dessser::Void()) };
                              (void)id_278;
                              uint8_t id_279 { 128 };
                              bool id_280 { bool(leb128_fst_82 >= id_279) };
                              letpair_res_259 = id_280;
                            }
                            let_res_258 = letpair_res_259;
                          }
                          while_flag_254 = let_res_258;
                          if (while_flag_254) {
                            (void)::dessser::Void();
                          }
                        } while (while_flag_254);
                        (void)::dessser::Void();
                        uint8_t id_281 { 0 };
                        uint32_t id_282 { leb_ref_78[id_281] };
                        Size id_283 { Size(id_282) };
                        uint8_t id_284 { 0 };
                        Pointer id_285 { p_ref_80[id_284] };
                        ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa id_286 { id_283, id_285 };
                        let_res_253 = id_286;
                      }
                      let_res_249 = let_res_253;
                    }
                    let_res_246 = let_res_249;
                  }
                  ::dessser::gen::raql_select_field::ta18b971ad5bf537b68fb1bbf5fd2b926 let_res_287;
                  {
                    ::dessser::gen::raql_select_field::t12fb9c475959b52bf7b17b155a955ffa dstring1_84 { let_res_246 };
                    ::dessser::gen::raql_select_field::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_288;
                    {
                      auto dstring1_fst_85 { std::get<0>(dstring1_84) };
                      auto dstring1_snd_86 { std::get<1>(dstring1_84) };
                      ::dessser::gen::raql_select_field::t9ef6882174ae71a34a3c5ef6b29242fb id_289 { dstring1_snd_86.readBytes(dstring1_fst_85) };
                      ::dessser::gen::raql_select_field::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_290;
                      {
                        auto dstring2_fst_88 { std::get<0>(id_289) };
                        auto dstring2_snd_89 { std::get<1>(id_289) };
                        std::string id_291 { dstring2_fst_88.toString() };
                        std::optional<std::string> id_292 { id_291 };
                        ::dessser::gen::raql_select_field::ta18b971ad5bf537b68fb1bbf5fd2b926 id_293 { id_292, dstring2_snd_89 };
                        letpair_res_290 = id_293;
                      }
                      letpair_res_288 = letpair_res_290;
                    }
                    let_res_287 = letpair_res_288;
                  }
                  choose_res_239 = let_res_287;
                }
                ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d letpair_res_294;
                {
                  auto drec_fst_94 { std::get<0>(choose_res_239) };
                  auto drec_snd_95 { std::get<1>(choose_res_239) };
                  ::dessser::gen::raql_select_field::t id_295 { drec_fst_58, drec_fst_61, drec_fst_76, drec_fst_94 };
                  ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d id_296 { id_295, drec_snd_95 };
                  letpair_res_294 = id_296;
                }
                letpair_res_234 = letpair_res_294;
              }
              let_res_233 = letpair_res_234;
            }
            letpair_res_185 = let_res_233;
          }
          let_res_184 = letpair_res_185;
        }
        letpair_res_181 = let_res_184;
      }
      let_res_180 = letpair_res_181;
    }
    return let_res_180;
  }
   };
  return fun177;
}
std::function<::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_97" "make_snd_98" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_97") (identifier "make_snd_98"))))
 */
static std::function<::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d(Pointer &)> fun297 { [&](Pointer p_0) {
    ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d id_298 { of_row_binary(p_0) };
    ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d letpair_res_299;
    {
      auto make_fst_97 { std::get<0>(id_298) };
      auto make_snd_98 { std::get<1>(id_298) };
      ::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d id_300 { make_fst_97, make_snd_98 };
      letpair_res_299 = id_300;
    }
    return letpair_res_299;
  }
   };
  return fun297;
}
std::function<::dessser::gen::raql_select_field::t3569225fb8bfc5f25806a8899fbad91d(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{expr: $raql_expr; alias: $field_name; doc: STRING; aggr: STRING?}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::raql_select_field::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_select_field::t &,Pointer &)> fun301 { [&](::dessser::gen::raql_select_field::t p_0, Pointer p_1) {
    Pointer id_302 { to_row_binary(p_0, p_1) };
    return id_302;
  }
   };
  return fun301;
}
std::function<Pointer(::dessser::gen::raql_select_field::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
