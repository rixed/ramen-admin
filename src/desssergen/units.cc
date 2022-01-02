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

namespace dessser::gen::units {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t50c85374c162cc57eaa3ade6dd674504 : public std::tuple<
  double,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(t50c85374c162cc57eaa3ade6dd674504 const &a, t50c85374c162cc57eaa3ade6dd674504 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t50c85374c162cc57eaa3ade6dd674504 const &a, t50c85374c162cc57eaa3ade6dd674504 const &b) {
  return !operator==(a, b);
}
struct tb3d0892aa873a8666f6c0a9f27b98c5f : public std::tuple<
  std::string,
  ::dessser::gen::units::t50c85374c162cc57eaa3ade6dd674504
> {
  using tuple::tuple;
};
inline bool operator==(tb3d0892aa873a8666f6c0a9f27b98c5f const &a, tb3d0892aa873a8666f6c0a9f27b98c5f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb3d0892aa873a8666f6c0a9f27b98c5f const &a, tb3d0892aa873a8666f6c0a9f27b98c5f const &b) {
  return !operator==(a, b);
}
typedef Arr<::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f> t;
struct ta30293a82943182cab78182f33b18016 : public std::tuple<
  t,
  Pointer
> {
  using tuple::tuple;
  ta30293a82943182cab78182f33b18016(std::tuple<t, Pointer> p)
    : std::tuple<t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta30293a82943182cab78182f33b18016 const &a, ta30293a82943182cab78182f33b18016 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta30293a82943182cab78182f33b18016 const &a, ta30293a82943182cab78182f33b18016 const &b) {
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
struct t49a7b69c1130e00f4d781dd2303897fc : public std::tuple<
  Lst<::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f>,
  Pointer
> {
  using tuple::tuple;
  t49a7b69c1130e00f4d781dd2303897fc(std::tuple<Lst<::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t49a7b69c1130e00f4d781dd2303897fc const &a, t49a7b69c1130e00f4d781dd2303897fc const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t49a7b69c1130e00f4d781dd2303897fc const &a, t49a7b69c1130e00f4d781dd2303897fc const &b) {
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
struct t9a758baeff17224a77e1a522010b4168 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t9a758baeff17224a77e1a522010b4168(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("(STRING; (FLOAT; BOOL))[]" "Ptr")
      (let "dst_ref_126"
        (make-vec
          (let "leb128_sz_124" (make-vec (cardinality (param 0)))
            (let "leb128_ptr_125" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_125")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_125"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_124"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_124"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_124"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_124") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_124")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_124")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_125"))))))
        (let "n_ref_127" (make-vec (i32 0))
          (seq
            (for-each "x_128" (param 0)
              (seq
                (set-vec (u8 0) (identifier "dst_ref_126")
                  (let "stup_dst_132"
                    (let "stup_dst_129" (unsafe-nth (u8 0) (identifier "dst_ref_126"))
                      (write-bytes
                        (let "leb128_sz_130" (make-vec (string-length (get-item 0 (identifier "x_128"))))
                          (let "leb128_ptr_131" (make-vec (identifier "stup_dst_129"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_131")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_131"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_130"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_130"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_130"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_130") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_130")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_130")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_131"))))) 
                        (bytes-of-string (get-item 0 (identifier "x_128")))))
                    (let "stup_dst_133" (write-u64 little-endian (identifier "stup_dst_132") (u64-of-float (get-item 0 (get-item 1 (identifier "x_128")))))
                      (write-u8 (identifier "stup_dst_133") (u8-of-bool (get-item 1 (get-item 1 (identifier "x_128")))))))) 
                (set-vec (u8 0) (identifier "n_ref_127") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_127")))))) 
            (unsafe-nth (u8 0) (identifier "dst_ref_126"))))))
 */
static std::function<Pointer(t&,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t&,Pointer)> fun0 { [&](t& p_0, Pointer p_1) {
    uint32_t id_1 { p_0.size() };
    Vec<1, uint32_t> id_2 {  id_1  };
    Pointer let_res_3;
    {
      Vec<1, uint32_t> leb128_sz_124 { id_2 };
      Vec<1, Pointer> id_4 {  p_1  };
      Pointer let_res_5;
      {
        Vec<1, Pointer> leb128_ptr_125 { id_4 };
        bool while_flag_6 { true };
        do {
          uint8_t id_7 { 0 };
          uint8_t id_8 { 0 };
          Pointer id_9 { leb128_ptr_125[id_8] };
          uint32_t id_10 { 128U };
          uint8_t id_11 { 0 };
          uint32_t id_12 { leb128_sz_124[id_11] };
          bool id_13 { bool(id_10 > id_12) };
          uint8_t choose_res_14;
          if (id_13) {
            uint8_t id_15 { 0 };
            uint32_t id_16 { leb128_sz_124[id_15] };
            uint8_t id_17 { uint8_t(id_16) };
            choose_res_14 = id_17;
          } else {
            uint8_t id_18 { 0 };
            uint32_t id_19 { leb128_sz_124[id_18] };
            uint8_t id_20 { uint8_t(id_19) };
            uint8_t id_21 { 128 };
            uint8_t id_22 { uint8_t(id_20 | id_21) };
            choose_res_14 = id_22;
          }
          Pointer id_23 { id_9.writeU8(choose_res_14) };
          Void id_24 { ((void)(leb128_ptr_125[id_7] = id_23), ::dessser::Void()) };
          (void)id_24;
          uint8_t id_25 { 0 };
          uint8_t id_26 { 0 };
          uint32_t id_27 { leb128_sz_124[id_26] };
          uint8_t id_28 { 7 };
          uint32_t id_29 { uint32_t(id_27 >> id_28) };
          Void id_30 { ((void)(leb128_sz_124[id_25] = id_29), ::dessser::Void()) };
          (void)id_30;
          uint8_t id_31 { 0 };
          uint32_t id_32 { leb128_sz_124[id_31] };
          uint32_t id_33 { 0U };
          bool id_34 { bool(id_32 > id_33) };
          while_flag_6 = id_34;
          if (while_flag_6) {
            (void)::dessser::Void();
          }
        } while (while_flag_6);
        (void)::dessser::Void();
        uint8_t id_35 { 0 };
        Pointer id_36 { leb128_ptr_125[id_35] };
        let_res_5 = id_36;
      }
      let_res_3 = let_res_5;
    }
    Vec<1, Pointer> id_37 {  let_res_3  };
    Pointer let_res_38;
    {
      Vec<1, Pointer> dst_ref_126 { id_37 };
      int32_t id_39 { 0L };
      Vec<1, int32_t> id_40 {  id_39  };
      Pointer let_res_41;
      {
        Vec<1, int32_t> n_ref_127 { id_40 };
        for (::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f const &x_128 : p_0) {
          uint8_t id_42 { 0 };
          uint8_t id_43 { 0 };
          Pointer id_44 { dst_ref_126[id_43] };
          Pointer let_res_45;
          {
            Pointer stup_dst_129 { id_44 };
            std::string id_46 { std::get<0>(x_128) };
            uint32_t id_47 { (uint32_t)id_46.size() };
            Vec<1, uint32_t> id_48 {  id_47  };
            Pointer let_res_49;
            {
              Vec<1, uint32_t> leb128_sz_130 { id_48 };
              Vec<1, Pointer> id_50 {  stup_dst_129  };
              Pointer let_res_51;
              {
                Vec<1, Pointer> leb128_ptr_131 { id_50 };
                bool while_flag_52 { true };
                do {
                  uint8_t id_53 { 0 };
                  uint8_t id_54 { 0 };
                  Pointer id_55 { leb128_ptr_131[id_54] };
                  uint32_t id_56 { 128U };
                  uint8_t id_57 { 0 };
                  uint32_t id_58 { leb128_sz_130[id_57] };
                  bool id_59 { bool(id_56 > id_58) };
                  uint8_t choose_res_60;
                  if (id_59) {
                    uint8_t id_61 { 0 };
                    uint32_t id_62 { leb128_sz_130[id_61] };
                    uint8_t id_63 { uint8_t(id_62) };
                    choose_res_60 = id_63;
                  } else {
                    uint8_t id_64 { 0 };
                    uint32_t id_65 { leb128_sz_130[id_64] };
                    uint8_t id_66 { uint8_t(id_65) };
                    uint8_t id_67 { 128 };
                    uint8_t id_68 { uint8_t(id_66 | id_67) };
                    choose_res_60 = id_68;
                  }
                  Pointer id_69 { id_55.writeU8(choose_res_60) };
                  Void id_70 { ((void)(leb128_ptr_131[id_53] = id_69), ::dessser::Void()) };
                  (void)id_70;
                  uint8_t id_71 { 0 };
                  uint8_t id_72 { 0 };
                  uint32_t id_73 { leb128_sz_130[id_72] };
                  uint8_t id_74 { 7 };
                  uint32_t id_75 { uint32_t(id_73 >> id_74) };
                  Void id_76 { ((void)(leb128_sz_130[id_71] = id_75), ::dessser::Void()) };
                  (void)id_76;
                  uint8_t id_77 { 0 };
                  uint32_t id_78 { leb128_sz_130[id_77] };
                  uint32_t id_79 { 0U };
                  bool id_80 { bool(id_78 > id_79) };
                  while_flag_52 = id_80;
                  if (while_flag_52) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_52);
                (void)::dessser::Void();
                uint8_t id_81 { 0 };
                Pointer id_82 { leb128_ptr_131[id_81] };
                let_res_51 = id_82;
              }
              let_res_49 = let_res_51;
            }
            std::string id_83 { std::get<0>(x_128) };
            Bytes id_84 { id_83 };
            Pointer id_85 { let_res_49.writeBytes(id_84) };
            let_res_45 = id_85;
          }
          Pointer let_res_86;
          {
            Pointer stup_dst_132 { let_res_45 };
            ::dessser::gen::units::t50c85374c162cc57eaa3ade6dd674504 id_87 { std::get<1>(x_128) };
            double id_88 { std::get<0>(id_87) };
            uint64_t id_89 { qword_of_float(id_88) };
            Pointer id_90 { stup_dst_132.writeU64Le(id_89) };
            Pointer let_res_91;
            {
              Pointer stup_dst_133 { id_90 };
              ::dessser::gen::units::t50c85374c162cc57eaa3ade6dd674504 id_92 { std::get<1>(x_128) };
              bool id_93 { std::get<1>(id_92) };
              uint8_t id_94 { uint8_t(id_93) };
              Pointer id_95 { stup_dst_133.writeU8(id_94) };
              let_res_91 = id_95;
            }
            let_res_86 = let_res_91;
          }
          Void id_96 { ((void)(dst_ref_126[id_42] = let_res_86), ::dessser::Void()) };
          (void)id_96;
          uint8_t id_97 { 0 };
          int32_t id_98 { 1L };
          uint8_t id_99 { 0 };
          int32_t id_100 { n_ref_127[id_99] };
          int32_t id_101 { int32_t(id_98 + id_100) };
          Void id_102 { ((void)(n_ref_127[id_97] = id_101), ::dessser::Void()) };
          (void)id_102;
          (void)id_102;
        }
        (void)::dessser::Void();
        uint8_t id_103 { 0 };
        Pointer id_104 { dst_ref_126[id_103] };
        let_res_41 = id_104;
      }
      let_res_38 = let_res_41;
    }
    return let_res_38;
  }
   };
  return fun0;
}
std::function<Pointer(t&,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("(STRING; (FLOAT; BOOL))[]")
      (let "sz_ref_115"
        (make-vec
          (let "n_ref_113" (make-vec (cardinality (param 0)))
            (let "lebsz_ref_114" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_113")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_114")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_114") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_114")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_114")))))))
        (seq
          (let "repeat_n_116" (make-vec (i32 0))
            (while (gt (to-i32 (cardinality (param 0))) (unsafe-nth (u8 0) (identifier "repeat_n_116")))
              (seq
                (set-vec (u8 0) (identifier "sz_ref_115")
                  (add
                    (add
                      (let "sz_117" (unsafe-nth (u8 0) (identifier "sz_ref_115"))
                        (add (identifier "sz_117")
                          (let "wlen_118" (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_116")) (param 0))))
                            (add
                              (let "n_ref_119" (make-vec (identifier "wlen_118"))
                                (let "lebsz_ref_120" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_119")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_120")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_120") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_120")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_120")))))) 
                              (size-of-u32 (identifier "wlen_118")))))) 
                      (size 8)) (size 1))) (set-vec (u8 0) (identifier "repeat_n_116") (add (unsafe-nth (u8 0) (identifier "repeat_n_116")) (i32 1)))))) 
          (unsafe-nth (u8 0) (identifier "sz_ref_115")))))
 */
static std::function<Size(t&)> sersize_of_row_binary_init()
{
  std::function<Size(t&)> fun105 { [&](t& p_0) {
    uint32_t id_106 { p_0.size() };
    Vec<1, uint32_t> id_107 {  id_106  };
    Size let_res_108;
    {
      Vec<1, uint32_t> n_ref_113 { id_107 };
      uint32_t id_109 { 1U };
      Vec<1, uint32_t> id_110 {  id_109  };
      Size let_res_111;
      {
        Vec<1, uint32_t> lebsz_ref_114 { id_110 };
        bool while_flag_112 { true };
        do {
          uint8_t id_113 { 0 };
          uint32_t id_114 { n_ref_113[id_113] };
          uint8_t id_115 { 0 };
          uint32_t id_116 { lebsz_ref_114[id_115] };
          uint8_t id_117 { 7 };
          uint32_t id_118 { uint32_t(id_116 << id_117) };
          bool id_119 { bool(id_114 >= id_118) };
          while_flag_112 = id_119;
          if (while_flag_112) {
            uint8_t id_120 { 0 };
            uint8_t id_121 { 0 };
            uint32_t id_122 { lebsz_ref_114[id_121] };
            uint32_t id_123 { 1U };
            uint32_t id_124 { uint32_t(id_122 + id_123) };
            Void id_125 { ((void)(lebsz_ref_114[id_120] = id_124), ::dessser::Void()) };
            (void)id_125;
          }
        } while (while_flag_112);
        (void)::dessser::Void();
        uint8_t id_126 { 0 };
        uint32_t id_127 { lebsz_ref_114[id_126] };
        Size id_128 { Size(id_127) };
        let_res_111 = id_128;
      }
      let_res_108 = let_res_111;
    }
    Vec<1, Size> id_129 {  let_res_108  };
    Size let_res_130;
    {
      Vec<1, Size> sz_ref_115 { id_129 };
      int32_t id_131 { 0L };
      Vec<1, int32_t> id_132 {  id_131  };
      {
        Vec<1, int32_t> repeat_n_116 { id_132 };
        bool while_flag_133 { true };
        do {
          uint32_t id_134 { p_0.size() };
          int32_t id_135 { int32_t(id_134) };
          uint8_t id_136 { 0 };
          int32_t id_137 { repeat_n_116[id_136] };
          bool id_138 { bool(id_135 > id_137) };
          while_flag_133 = id_138;
          if (while_flag_133) {
            uint8_t id_139 { 0 };
            uint8_t id_140 { 0 };
            Size id_141 { sz_ref_115[id_140] };
            Size let_res_142;
            {
              Size sz_117 { id_141 };
              uint8_t id_143 { 0 };
              int32_t id_144 { repeat_n_116[id_143] };
              ::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f id_145 { p_0[id_144] };
              std::string id_146 { std::get<0>(id_145) };
              uint32_t id_147 { (uint32_t)id_146.size() };
              Size let_res_148;
              {
                uint32_t wlen_118 { id_147 };
                Vec<1, uint32_t> id_149 {  wlen_118  };
                Size let_res_150;
                {
                  Vec<1, uint32_t> n_ref_119 { id_149 };
                  uint32_t id_151 { 1U };
                  Vec<1, uint32_t> id_152 {  id_151  };
                  Size let_res_153;
                  {
                    Vec<1, uint32_t> lebsz_ref_120 { id_152 };
                    bool while_flag_154 { true };
                    do {
                      uint8_t id_155 { 0 };
                      uint32_t id_156 { n_ref_119[id_155] };
                      uint8_t id_157 { 0 };
                      uint32_t id_158 { lebsz_ref_120[id_157] };
                      uint8_t id_159 { 7 };
                      uint32_t id_160 { uint32_t(id_158 << id_159) };
                      bool id_161 { bool(id_156 >= id_160) };
                      while_flag_154 = id_161;
                      if (while_flag_154) {
                        uint8_t id_162 { 0 };
                        uint8_t id_163 { 0 };
                        uint32_t id_164 { lebsz_ref_120[id_163] };
                        uint32_t id_165 { 1U };
                        uint32_t id_166 { uint32_t(id_164 + id_165) };
                        Void id_167 { ((void)(lebsz_ref_120[id_162] = id_166), ::dessser::Void()) };
                        (void)id_167;
                      }
                    } while (while_flag_154);
                    (void)::dessser::Void();
                    uint8_t id_168 { 0 };
                    uint32_t id_169 { lebsz_ref_120[id_168] };
                    Size id_170 { Size(id_169) };
                    let_res_153 = id_170;
                  }
                  let_res_150 = let_res_153;
                }
                Size id_171 { Size(wlen_118) };
                Size id_172 { Size(let_res_150 + id_171) };
                let_res_148 = id_172;
              }
              Size id_173 { Size(sz_117 + let_res_148) };
              let_res_142 = id_173;
            }
            Size id_174 { 8UL };
            Size id_175 { Size(let_res_142 + id_174) };
            Size id_176 { 1UL };
            Size id_177 { Size(id_175 + id_176) };
            Void id_178 { ((void)(sz_ref_115[id_139] = id_177), ::dessser::Void()) };
            (void)id_178;
            uint8_t id_179 { 0 };
            uint8_t id_180 { 0 };
            int32_t id_181 { repeat_n_116[id_180] };
            int32_t id_182 { 1L };
            int32_t id_183 { int32_t(id_181 + id_182) };
            Void id_184 { ((void)(repeat_n_116[id_179] = id_183), ::dessser::Void()) };
            (void)id_184;
            (void)id_184;
          }
        } while (while_flag_133);
        (void)::dessser::Void();
      }
      (void)::dessser::Void();
      uint8_t id_185 { 0 };
      Size id_186 { sz_ref_115[id_185] };
      let_res_130 = id_186;
    }
    return let_res_130;
  }
   };
  return fun105;
}
std::function<Size(t&)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "dlist4_fst_108" "dlist4_snd_109"
        (let "dlist1_66"
          (let "leb_ref_57" (make-vec (u32 0))
            (let "shft_ref_58" (make-vec (u8 0))
              (let "p_ref_59" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_60" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_59")))
                      (let-pair "leb128_fst_61" "leb128_snd_62" (identifier "leb128_60")
                        (seq (set-vec (u8 0) (identifier "p_ref_59") (identifier "leb128_snd_62"))
                          (set-vec (u8 0) (identifier "leb_ref_57")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_61") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_58"))) (unsafe-nth (u8 0) (identifier "leb_ref_57"))))
                          (set-vec (u8 0) (identifier "shft_ref_58") (add (unsafe-nth (u8 0) (identifier "shft_ref_58")) (u8 7))) 
                          (ge (identifier "leb128_fst_61") (u8 128))))) 
                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_57")) (unsafe-nth (u8 0) (identifier "p_ref_59")))))))
          (let-pair "dlist1_fst_67" "dlist1_snd_68" (identifier "dlist1_66")
            (let "inits_src_ref_69" (make-vec (make-tup (end-of-list "(STRING; (FLOAT; BOOL))") (identifier "dlist1_snd_68")))
              (seq
                (let "repeat_n_70" (make-vec (i32 0))
                  (while (gt (to-i32 (identifier "dlist1_fst_67")) (unsafe-nth (u8 0) (identifier "repeat_n_70")))
                    (seq
                      (let "dlist2_71" (unsafe-nth (u8 0) (identifier "inits_src_ref_69"))
                        (let-pair "dlist2_fst_72" "dlist2_snd_73" (identifier "dlist2_71")
                          (set-vec (u8 0) (identifier "inits_src_ref_69")
                            (let "dtup_86"
                              (let "dstring1_80"
                                (let "leb_ref_74" (make-vec (u32 0))
                                  (let "shft_ref_75" (make-vec (u8 0))
                                    (let "p_ref_76" (make-vec (identifier "dlist2_snd_73"))
                                      (seq
                                        (while
                                          (let "leb128_77" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_76")))
                                            (let-pair "leb128_fst_78" "leb128_snd_79" 
                                              (identifier "leb128_77")
                                              (seq (set-vec (u8 0) (identifier "p_ref_76") (identifier "leb128_snd_79"))
                                                (set-vec (u8 0) (identifier "leb_ref_74")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_78") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_75"))) (unsafe-nth (u8 0) (identifier "leb_ref_74"))))
                                                (set-vec (u8 0) (identifier "shft_ref_75") (add (unsafe-nth (u8 0) (identifier "shft_ref_75")) (u8 7))) 
                                                (ge (identifier "leb128_fst_78") (u8 128))))) 
                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_74"))) (unsafe-nth (u8 0) (identifier "p_ref_76")))))))
                                (let-pair "dstring1_fst_81" "dstring1_snd_82" 
                                  (identifier "dstring1_80")
                                  (let-pair "dstring2_fst_84" "dstring2_snd_85" 
                                    (read-bytes (identifier "dstring1_snd_82") (identifier "dstring1_fst_81")) 
                                    (make-tup (string-of-bytes (identifier "dstring2_fst_84")) (identifier "dstring2_snd_85")))))
                              (let-pair "dtup_fst_87" "dtup_snd_88" (identifier "dtup_86")
                                (let "dtup_92" (let-pair "dfloat_fst_90" "dfloat_snd_91" (read-u64 little-endian (identifier "dtup_snd_88")) (make-tup (float-of-u64 (identifier "dfloat_fst_90")) (identifier "dfloat_snd_91")))
                                  (let-pair "dtup_fst_93" "dtup_snd_94" 
                                    (identifier "dtup_92")
                                    (let-pair "dbool_fst_96" "dbool_snd_97" 
                                      (read-u8 (identifier "dtup_snd_94"))
                                      (make-tup (cons (make-tup (identifier "dtup_fst_87") (make-tup (identifier "dtup_fst_93") (not (eq (identifier "dbool_fst_96") (u8 0))))) (identifier "dlist2_fst_72"))
                                        (identifier "dbool_snd_97")))))))))) 
                      (set-vec (u8 0) (identifier "repeat_n_70") (add (unsafe-nth (u8 0) (identifier "repeat_n_70")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "inits_src_ref_69")))))) 
        (make-tup (arr-of-lst-rev (identifier "dlist4_fst_108")) (identifier "dlist4_snd_109"))))
 */
static std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer)> fun187 { [&](Pointer p_0) {
    uint32_t id_188 { 0U };
    Vec<1, uint32_t> id_189 {  id_188  };
    ::dessser::gen::units::t491c44439106a32f896827242e8e76a1 let_res_190;
    {
      Vec<1, uint32_t> leb_ref_57 { id_189 };
      uint8_t id_191 { 0 };
      Vec<1, uint8_t> id_192 {  id_191  };
      ::dessser::gen::units::t491c44439106a32f896827242e8e76a1 let_res_193;
      {
        Vec<1, uint8_t> shft_ref_58 { id_192 };
        Vec<1, Pointer> id_194 {  p_0  };
        ::dessser::gen::units::t491c44439106a32f896827242e8e76a1 let_res_195;
        {
          Vec<1, Pointer> p_ref_59 { id_194 };
          bool while_flag_196 { true };
          do {
            uint8_t id_197 { 0 };
            Pointer id_198 { p_ref_59[id_197] };
            ::dessser::gen::units::t1a5d74abf838df33f185a72a8912f5c9 id_199 { id_198.readU8() };
            bool let_res_200;
            {
              ::dessser::gen::units::t1a5d74abf838df33f185a72a8912f5c9 leb128_60 { id_199 };
              bool letpair_res_201;
              {
                auto leb128_fst_61 { std::get<0>(leb128_60) };
                auto leb128_snd_62 { std::get<1>(leb128_60) };
                uint8_t id_202 { 0 };
                Void id_203 { ((void)(p_ref_59[id_202] = leb128_snd_62), ::dessser::Void()) };
                (void)id_203;
                uint8_t id_204 { 0 };
                uint8_t id_205 { 127 };
                uint8_t id_206 { uint8_t(leb128_fst_61 & id_205) };
                uint32_t id_207 { uint32_t(id_206) };
                uint8_t id_208 { 0 };
                uint8_t id_209 { shft_ref_58[id_208] };
                uint32_t id_210 { uint32_t(id_207 << id_209) };
                uint8_t id_211 { 0 };
                uint32_t id_212 { leb_ref_57[id_211] };
                uint32_t id_213 { uint32_t(id_210 | id_212) };
                Void id_214 { ((void)(leb_ref_57[id_204] = id_213), ::dessser::Void()) };
                (void)id_214;
                uint8_t id_215 { 0 };
                uint8_t id_216 { 0 };
                uint8_t id_217 { shft_ref_58[id_216] };
                uint8_t id_218 { 7 };
                uint8_t id_219 { uint8_t(id_217 + id_218) };
                Void id_220 { ((void)(shft_ref_58[id_215] = id_219), ::dessser::Void()) };
                (void)id_220;
                uint8_t id_221 { 128 };
                bool id_222 { bool(leb128_fst_61 >= id_221) };
                letpair_res_201 = id_222;
              }
              let_res_200 = letpair_res_201;
            }
            while_flag_196 = let_res_200;
            if (while_flag_196) {
              (void)::dessser::Void();
            }
          } while (while_flag_196);
          (void)::dessser::Void();
          uint8_t id_223 { 0 };
          uint32_t id_224 { leb_ref_57[id_223] };
          uint8_t id_225 { 0 };
          Pointer id_226 { p_ref_59[id_225] };
          ::dessser::gen::units::t491c44439106a32f896827242e8e76a1 id_227 { id_224, id_226 };
          let_res_195 = id_227;
        }
        let_res_193 = let_res_195;
      }
      let_res_190 = let_res_193;
    }
    ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc let_res_228;
    {
      ::dessser::gen::units::t491c44439106a32f896827242e8e76a1 dlist1_66 { let_res_190 };
      ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc letpair_res_229;
      {
        auto dlist1_fst_67 { std::get<0>(dlist1_66) };
        auto dlist1_snd_68 { std::get<1>(dlist1_66) };
        Lst<::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f> endoflist_230;
        ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc id_231 { endoflist_230, dlist1_snd_68 };
        Vec<1, ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc> id_232 {  id_231  };
        ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc let_res_233;
        {
          Vec<1, ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc> inits_src_ref_69 { id_232 };
          int32_t id_234 { 0L };
          Vec<1, int32_t> id_235 {  id_234  };
          {
            Vec<1, int32_t> repeat_n_70 { id_235 };
            bool while_flag_236 { true };
            do {
              int32_t id_237 { int32_t(dlist1_fst_67) };
              uint8_t id_238 { 0 };
              int32_t id_239 { repeat_n_70[id_238] };
              bool id_240 { bool(id_237 > id_239) };
              while_flag_236 = id_240;
              if (while_flag_236) {
                uint8_t id_241 { 0 };
                ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc id_242 { inits_src_ref_69[id_241] };
                {
                  ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc dlist2_71 { id_242 };
                  {
                    auto dlist2_fst_72 { std::get<0>(dlist2_71) };
                    auto dlist2_snd_73 { std::get<1>(dlist2_71) };
                    uint8_t id_243 { 0 };
                    uint32_t id_244 { 0U };
                    Vec<1, uint32_t> id_245 {  id_244  };
                    ::dessser::gen::units::t12fb9c475959b52bf7b17b155a955ffa let_res_246;
                    {
                      Vec<1, uint32_t> leb_ref_74 { id_245 };
                      uint8_t id_247 { 0 };
                      Vec<1, uint8_t> id_248 {  id_247  };
                      ::dessser::gen::units::t12fb9c475959b52bf7b17b155a955ffa let_res_249;
                      {
                        Vec<1, uint8_t> shft_ref_75 { id_248 };
                        Vec<1, Pointer> id_250 {  dlist2_snd_73  };
                        ::dessser::gen::units::t12fb9c475959b52bf7b17b155a955ffa let_res_251;
                        {
                          Vec<1, Pointer> p_ref_76 { id_250 };
                          bool while_flag_252 { true };
                          do {
                            uint8_t id_253 { 0 };
                            Pointer id_254 { p_ref_76[id_253] };
                            ::dessser::gen::units::t1a5d74abf838df33f185a72a8912f5c9 id_255 { id_254.readU8() };
                            bool let_res_256;
                            {
                              ::dessser::gen::units::t1a5d74abf838df33f185a72a8912f5c9 leb128_77 { id_255 };
                              bool letpair_res_257;
                              {
                                auto leb128_fst_78 { std::get<0>(leb128_77) };
                                auto leb128_snd_79 { std::get<1>(leb128_77) };
                                uint8_t id_258 { 0 };
                                Void id_259 { ((void)(p_ref_76[id_258] = leb128_snd_79), ::dessser::Void()) };
                                (void)id_259;
                                uint8_t id_260 { 0 };
                                uint8_t id_261 { 127 };
                                uint8_t id_262 { uint8_t(leb128_fst_78 & id_261) };
                                uint32_t id_263 { uint32_t(id_262) };
                                uint8_t id_264 { 0 };
                                uint8_t id_265 { shft_ref_75[id_264] };
                                uint32_t id_266 { uint32_t(id_263 << id_265) };
                                uint8_t id_267 { 0 };
                                uint32_t id_268 { leb_ref_74[id_267] };
                                uint32_t id_269 { uint32_t(id_266 | id_268) };
                                Void id_270 { ((void)(leb_ref_74[id_260] = id_269), ::dessser::Void()) };
                                (void)id_270;
                                uint8_t id_271 { 0 };
                                uint8_t id_272 { 0 };
                                uint8_t id_273 { shft_ref_75[id_272] };
                                uint8_t id_274 { 7 };
                                uint8_t id_275 { uint8_t(id_273 + id_274) };
                                Void id_276 { ((void)(shft_ref_75[id_271] = id_275), ::dessser::Void()) };
                                (void)id_276;
                                uint8_t id_277 { 128 };
                                bool id_278 { bool(leb128_fst_78 >= id_277) };
                                letpair_res_257 = id_278;
                              }
                              let_res_256 = letpair_res_257;
                            }
                            while_flag_252 = let_res_256;
                            if (while_flag_252) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_252);
                          (void)::dessser::Void();
                          uint8_t id_279 { 0 };
                          uint32_t id_280 { leb_ref_74[id_279] };
                          Size id_281 { Size(id_280) };
                          uint8_t id_282 { 0 };
                          Pointer id_283 { p_ref_76[id_282] };
                          ::dessser::gen::units::t12fb9c475959b52bf7b17b155a955ffa id_284 { id_281, id_283 };
                          let_res_251 = id_284;
                        }
                        let_res_249 = let_res_251;
                      }
                      let_res_246 = let_res_249;
                    }
                    ::dessser::gen::units::t13a07ee37ab40962540da8534858dc07 let_res_285;
                    {
                      ::dessser::gen::units::t12fb9c475959b52bf7b17b155a955ffa dstring1_80 { let_res_246 };
                      ::dessser::gen::units::t13a07ee37ab40962540da8534858dc07 letpair_res_286;
                      {
                        auto dstring1_fst_81 { std::get<0>(dstring1_80) };
                        auto dstring1_snd_82 { std::get<1>(dstring1_80) };
                        ::dessser::gen::units::t9ef6882174ae71a34a3c5ef6b29242fb id_287 { dstring1_snd_82.readBytes(dstring1_fst_81) };
                        ::dessser::gen::units::t13a07ee37ab40962540da8534858dc07 letpair_res_288;
                        {
                          auto dstring2_fst_84 { std::get<0>(id_287) };
                          auto dstring2_snd_85 { std::get<1>(id_287) };
                          std::string id_289 { dstring2_fst_84.toString() };
                          ::dessser::gen::units::t13a07ee37ab40962540da8534858dc07 id_290 { id_289, dstring2_snd_85 };
                          letpair_res_288 = id_290;
                        }
                        letpair_res_286 = letpair_res_288;
                      }
                      let_res_285 = letpair_res_286;
                    }
                    ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc let_res_291;
                    {
                      ::dessser::gen::units::t13a07ee37ab40962540da8534858dc07 dtup_86 { let_res_285 };
                      ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc letpair_res_292;
                      {
                        auto dtup_fst_87 { std::get<0>(dtup_86) };
                        auto dtup_snd_88 { std::get<1>(dtup_86) };
                        ::dessser::gen::units::td2cd337bb3c8bc04d5603393d084985b id_293 { dtup_snd_88.readU64Le() };
                        ::dessser::gen::units::t9a758baeff17224a77e1a522010b4168 letpair_res_294;
                        {
                          auto dfloat_fst_90 { std::get<0>(id_293) };
                          auto dfloat_snd_91 { std::get<1>(id_293) };
                          double id_295 { float_of_qword(dfloat_fst_90) };
                          ::dessser::gen::units::t9a758baeff17224a77e1a522010b4168 id_296 { id_295, dfloat_snd_91 };
                          letpair_res_294 = id_296;
                        }
                        ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc let_res_297;
                        {
                          ::dessser::gen::units::t9a758baeff17224a77e1a522010b4168 dtup_92 { letpair_res_294 };
                          ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc letpair_res_298;
                          {
                            auto dtup_fst_93 { std::get<0>(dtup_92) };
                            auto dtup_snd_94 { std::get<1>(dtup_92) };
                            ::dessser::gen::units::t1a5d74abf838df33f185a72a8912f5c9 id_299 { dtup_snd_94.readU8() };
                            ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc letpair_res_300;
                            {
                              auto dbool_fst_96 { std::get<0>(id_299) };
                              auto dbool_snd_97 { std::get<1>(id_299) };
                              uint8_t id_301 { 0 };
                              bool id_302 { bool(dbool_fst_96 == id_301) };
                              bool id_303 { ! id_302 };
                              ::dessser::gen::units::t50c85374c162cc57eaa3ade6dd674504 id_304 { dtup_fst_93, id_303 };
                              ::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f id_305 { dtup_fst_87, id_304 };
                              Lst<::dessser::gen::units::tb3d0892aa873a8666f6c0a9f27b98c5f> id_306 { id_305, dlist2_fst_72 };
                              ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc id_307 { id_306, dbool_snd_97 };
                              letpair_res_300 = id_307;
                            }
                            letpair_res_298 = letpair_res_300;
                          }
                          let_res_297 = letpair_res_298;
                        }
                        letpair_res_292 = let_res_297;
                      }
                      let_res_291 = letpair_res_292;
                    }
                    Void id_308 { ((void)(inits_src_ref_69[id_243] = let_res_291), ::dessser::Void()) };
                    (void)id_308;
                  }
                  (void)::dessser::Void();
                }
                (void)::dessser::Void();
                uint8_t id_309 { 0 };
                uint8_t id_310 { 0 };
                int32_t id_311 { repeat_n_70[id_310] };
                int32_t id_312 { 1L };
                int32_t id_313 { int32_t(id_311 + id_312) };
                Void id_314 { ((void)(repeat_n_70[id_309] = id_313), ::dessser::Void()) };
                (void)id_314;
                (void)id_314;
              }
            } while (while_flag_236);
            (void)::dessser::Void();
          }
          (void)::dessser::Void();
          uint8_t id_315 { 0 };
          ::dessser::gen::units::t49a7b69c1130e00f4d781dd2303897fc id_316 { inits_src_ref_69[id_315] };
          let_res_233 = id_316;
        }
        letpair_res_229 = let_res_233;
      }
      let_res_228 = letpair_res_229;
    }
    ::dessser::gen::units::ta30293a82943182cab78182f33b18016 letpair_res_317;
    {
      auto dlist4_fst_108 { std::get<0>(let_res_228) };
      auto dlist4_snd_109 { std::get<1>(let_res_228) };
      t id_318 { dlist4_fst_108.toListRev() };
      ::dessser::gen::units::ta30293a82943182cab78182f33b18016 id_319 { id_318, dlist4_snd_109 };
      letpair_res_317 = id_319;
    }
    return letpair_res_317;
  }
   };
  return fun187;
}
std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_111" "make_snd_112" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_111") (identifier "make_snd_112"))))
 */
static std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer)> fun320 { [&](Pointer p_0) {
    ::dessser::gen::units::ta30293a82943182cab78182f33b18016 id_321 { of_row_binary(p_0) };
    ::dessser::gen::units::ta30293a82943182cab78182f33b18016 letpair_res_322;
    {
      auto make_fst_111 { std::get<0>(id_321) };
      auto make_snd_112 { std::get<1>(id_321) };
      ::dessser::gen::units::ta30293a82943182cab78182f33b18016 id_323 { make_fst_111, make_snd_112 };
      letpair_res_322 = id_323;
    }
    return letpair_res_322;
  }
   };
  return fun320;
}
std::function<::dessser::gen::units::ta30293a82943182cab78182f33b18016(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("(STRING; (FLOAT; BOOL))[]" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(t&,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(t&,Pointer)> fun324 { [&](t& p_0, Pointer p_1) {
    Pointer id_325 { to_row_binary(p_0, p_1) };
    return id_325;
  }
   };
  return fun324;
}
std::function<Pointer(t&,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
