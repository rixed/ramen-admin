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

namespace dessser::gen::alerting_inhibition {
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
  std::string what;
  double start_date;
  double stop_date;
  std::string who;
  std::string why;
  t(std::string what_, double start_date_, double stop_date_, std::string who_, std::string why_) : what(what_), start_date(start_date_), stop_date(stop_date_), who(who_), why(why_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.what == b.what && a.start_date == b.start_date && a.stop_date == b.stop_date && a.who == b.who && a.why == b.why;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct td0766d14326fd014941742c3a29e7ad3 : public std::tuple<
  ::dessser::gen::alerting_inhibition::t,
  Pointer
> {
  using tuple::tuple;
  td0766d14326fd014941742c3a29e7ad3(std::tuple<::dessser::gen::alerting_inhibition::t, Pointer> p)
    : std::tuple<::dessser::gen::alerting_inhibition::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td0766d14326fd014941742c3a29e7ad3 const &a, td0766d14326fd014941742c3a29e7ad3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td0766d14326fd014941742c3a29e7ad3 const &a, td0766d14326fd014941742c3a29e7ad3 const &b) {
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
    (fun ("{what: STRING; start_date: FLOAT; stop_date: FLOAT; who: STRING; why: STRING}" "Ptr")
      (let "srec_dst_138"
        (let "srec_dst_135"
          (let "srec_dst_134"
            (let "srec_dst_133"
              (write-bytes
                (let "leb128_sz_131" (make-vec (string-length (get-field "what" (param 0))))
                  (let "leb128_ptr_132" (make-vec (param 1))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_132")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_132"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_131"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_131"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_131"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_131") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_131")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_131")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_132"))))) 
                (bytes-of-string (get-field "what" (param 0)))) (write-u64 little-endian (identifier "srec_dst_133") (u64-of-float (get-field "start_date" (param 0)))))
            (write-u64 little-endian (identifier "srec_dst_134") (u64-of-float (get-field "stop_date" (param 0)))))
          (write-bytes
            (let "leb128_sz_136" (make-vec (string-length (get-field "who" (param 0))))
              (let "leb128_ptr_137" (make-vec (identifier "srec_dst_135"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_137")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_137"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_136"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_136"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_136"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_136") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_136")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_136")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_137"))))) 
            (bytes-of-string (get-field "who" (param 0)))))
        (write-bytes
          (let "leb128_sz_139" (make-vec (string-length (get-field "why" (param 0))))
            (let "leb128_ptr_140" (make-vec (identifier "srec_dst_138"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_140")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_140"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_139"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_139"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_139"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_139") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_139")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_139")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_140"))))) 
          (bytes-of-string (get-field "why" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::alerting_inhibition::t const &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::alerting_inhibition::t const &,Pointer &)> fun0 { [&](::dessser::gen::alerting_inhibition::t p_0, Pointer p_1) {
    std::string id_1 { p_0.what };
    uint32_t id_2 { (uint32_t)id_1.size() };
    Vec<1, uint32_t> id_3 {  id_2  };
    Pointer let_res_4;
    {
      Vec<1, uint32_t> leb128_sz_131 { id_3 };
      Vec<1, Pointer> id_5 {  p_1  };
      Pointer let_res_6;
      {
        Vec<1, Pointer> leb128_ptr_132 { id_5 };
        bool while_flag_7 { true };
        do {
          uint8_t id_8 { 0 };
          uint8_t id_9 { 0 };
          Pointer id_10 { leb128_ptr_132[id_9] };
          uint32_t id_11 { 128U };
          uint8_t id_12 { 0 };
          uint32_t id_13 { leb128_sz_131[id_12] };
          bool id_14 { bool(id_11 > id_13) };
          uint8_t choose_res_15;
          if (id_14) {
            uint8_t id_16 { 0 };
            uint32_t id_17 { leb128_sz_131[id_16] };
            uint8_t id_18 { uint8_t(id_17) };
            choose_res_15 = id_18;
          } else {
            uint8_t id_19 { 0 };
            uint32_t id_20 { leb128_sz_131[id_19] };
            uint8_t id_21 { uint8_t(id_20) };
            uint8_t id_22 { 128 };
            uint8_t id_23 { uint8_t(id_21 | id_22) };
            choose_res_15 = id_23;
          }
          Pointer id_24 { id_10.writeU8(choose_res_15) };
          Void id_25 { ((void)(leb128_ptr_132[id_8] = id_24), ::dessser::Void()) };
          (void)id_25;
          uint8_t id_26 { 0 };
          uint8_t id_27 { 0 };
          uint32_t id_28 { leb128_sz_131[id_27] };
          uint8_t id_29 { 7 };
          uint32_t id_30 { uint32_t(id_28 >> id_29) };
          Void id_31 { ((void)(leb128_sz_131[id_26] = id_30), ::dessser::Void()) };
          (void)id_31;
          uint8_t id_32 { 0 };
          uint32_t id_33 { leb128_sz_131[id_32] };
          uint32_t id_34 { 0U };
          bool id_35 { bool(id_33 > id_34) };
          while_flag_7 = id_35;
          if (while_flag_7) {
            (void)::dessser::Void();
          }
        } while (while_flag_7);
        (void)::dessser::Void();
        uint8_t id_36 { 0 };
        Pointer id_37 { leb128_ptr_132[id_36] };
        let_res_6 = id_37;
      }
      let_res_4 = let_res_6;
    }
    std::string id_38 { p_0.what };
    Bytes id_39 { id_38 };
    Pointer id_40 { let_res_4.writeBytes(id_39) };
    Pointer let_res_41;
    {
      Pointer srec_dst_133 { id_40 };
      double id_42 { p_0.start_date };
      uint64_t id_43 { qword_of_float(id_42) };
      Pointer id_44 { srec_dst_133.writeU64Le(id_43) };
      let_res_41 = id_44;
    }
    Pointer let_res_45;
    {
      Pointer srec_dst_134 { let_res_41 };
      double id_46 { p_0.stop_date };
      uint64_t id_47 { qword_of_float(id_46) };
      Pointer id_48 { srec_dst_134.writeU64Le(id_47) };
      let_res_45 = id_48;
    }
    Pointer let_res_49;
    {
      Pointer srec_dst_135 { let_res_45 };
      std::string id_50 { p_0.who };
      uint32_t id_51 { (uint32_t)id_50.size() };
      Vec<1, uint32_t> id_52 {  id_51  };
      Pointer let_res_53;
      {
        Vec<1, uint32_t> leb128_sz_136 { id_52 };
        Vec<1, Pointer> id_54 {  srec_dst_135  };
        Pointer let_res_55;
        {
          Vec<1, Pointer> leb128_ptr_137 { id_54 };
          bool while_flag_56 { true };
          do {
            uint8_t id_57 { 0 };
            uint8_t id_58 { 0 };
            Pointer id_59 { leb128_ptr_137[id_58] };
            uint32_t id_60 { 128U };
            uint8_t id_61 { 0 };
            uint32_t id_62 { leb128_sz_136[id_61] };
            bool id_63 { bool(id_60 > id_62) };
            uint8_t choose_res_64;
            if (id_63) {
              uint8_t id_65 { 0 };
              uint32_t id_66 { leb128_sz_136[id_65] };
              uint8_t id_67 { uint8_t(id_66) };
              choose_res_64 = id_67;
            } else {
              uint8_t id_68 { 0 };
              uint32_t id_69 { leb128_sz_136[id_68] };
              uint8_t id_70 { uint8_t(id_69) };
              uint8_t id_71 { 128 };
              uint8_t id_72 { uint8_t(id_70 | id_71) };
              choose_res_64 = id_72;
            }
            Pointer id_73 { id_59.writeU8(choose_res_64) };
            Void id_74 { ((void)(leb128_ptr_137[id_57] = id_73), ::dessser::Void()) };
            (void)id_74;
            uint8_t id_75 { 0 };
            uint8_t id_76 { 0 };
            uint32_t id_77 { leb128_sz_136[id_76] };
            uint8_t id_78 { 7 };
            uint32_t id_79 { uint32_t(id_77 >> id_78) };
            Void id_80 { ((void)(leb128_sz_136[id_75] = id_79), ::dessser::Void()) };
            (void)id_80;
            uint8_t id_81 { 0 };
            uint32_t id_82 { leb128_sz_136[id_81] };
            uint32_t id_83 { 0U };
            bool id_84 { bool(id_82 > id_83) };
            while_flag_56 = id_84;
            if (while_flag_56) {
              (void)::dessser::Void();
            }
          } while (while_flag_56);
          (void)::dessser::Void();
          uint8_t id_85 { 0 };
          Pointer id_86 { leb128_ptr_137[id_85] };
          let_res_55 = id_86;
        }
        let_res_53 = let_res_55;
      }
      std::string id_87 { p_0.who };
      Bytes id_88 { id_87 };
      Pointer id_89 { let_res_53.writeBytes(id_88) };
      let_res_49 = id_89;
    }
    Pointer let_res_90;
    {
      Pointer srec_dst_138 { let_res_49 };
      std::string id_91 { p_0.why };
      uint32_t id_92 { (uint32_t)id_91.size() };
      Vec<1, uint32_t> id_93 {  id_92  };
      Pointer let_res_94;
      {
        Vec<1, uint32_t> leb128_sz_139 { id_93 };
        Vec<1, Pointer> id_95 {  srec_dst_138  };
        Pointer let_res_96;
        {
          Vec<1, Pointer> leb128_ptr_140 { id_95 };
          bool while_flag_97 { true };
          do {
            uint8_t id_98 { 0 };
            uint8_t id_99 { 0 };
            Pointer id_100 { leb128_ptr_140[id_99] };
            uint32_t id_101 { 128U };
            uint8_t id_102 { 0 };
            uint32_t id_103 { leb128_sz_139[id_102] };
            bool id_104 { bool(id_101 > id_103) };
            uint8_t choose_res_105;
            if (id_104) {
              uint8_t id_106 { 0 };
              uint32_t id_107 { leb128_sz_139[id_106] };
              uint8_t id_108 { uint8_t(id_107) };
              choose_res_105 = id_108;
            } else {
              uint8_t id_109 { 0 };
              uint32_t id_110 { leb128_sz_139[id_109] };
              uint8_t id_111 { uint8_t(id_110) };
              uint8_t id_112 { 128 };
              uint8_t id_113 { uint8_t(id_111 | id_112) };
              choose_res_105 = id_113;
            }
            Pointer id_114 { id_100.writeU8(choose_res_105) };
            Void id_115 { ((void)(leb128_ptr_140[id_98] = id_114), ::dessser::Void()) };
            (void)id_115;
            uint8_t id_116 { 0 };
            uint8_t id_117 { 0 };
            uint32_t id_118 { leb128_sz_139[id_117] };
            uint8_t id_119 { 7 };
            uint32_t id_120 { uint32_t(id_118 >> id_119) };
            Void id_121 { ((void)(leb128_sz_139[id_116] = id_120), ::dessser::Void()) };
            (void)id_121;
            uint8_t id_122 { 0 };
            uint32_t id_123 { leb128_sz_139[id_122] };
            uint32_t id_124 { 0U };
            bool id_125 { bool(id_123 > id_124) };
            while_flag_97 = id_125;
            if (while_flag_97) {
              (void)::dessser::Void();
            }
          } while (while_flag_97);
          (void)::dessser::Void();
          uint8_t id_126 { 0 };
          Pointer id_127 { leb128_ptr_140[id_126] };
          let_res_96 = id_127;
        }
        let_res_94 = let_res_96;
      }
      std::string id_128 { p_0.why };
      Bytes id_129 { id_128 };
      Pointer id_130 { let_res_94.writeBytes(id_129) };
      let_res_90 = id_130;
    }
    return let_res_90;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::alerting_inhibition::t const &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{what: STRING; start_date: FLOAT; stop_date: FLOAT; who: STRING; why: STRING}")
      (let "sz_127"
        (let "sz_123"
          (add
            (add
              (add
                (let "n_ref_119" (make-vec (string-length (get-field "what" (param 0))))
                  (let "lebsz_ref_120" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_119")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_120")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_120") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_120")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_120")))))) 
                (size-of-u32 (string-length (get-field "what" (param 0))))) 
              (size 8)) (size 8))
          (add (identifier "sz_123")
            (add
              (let "n_ref_125" (make-vec (string-length (get-field "who" (param 0))))
                (let "lebsz_ref_126" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_125")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_126")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_126") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_126")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_126")))))) 
              (size-of-u32 (string-length (get-field "who" (param 0)))))))
        (add (identifier "sz_127")
          (add
            (let "n_ref_129" (make-vec (string-length (get-field "why" (param 0))))
              (let "lebsz_ref_130" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_129")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_130")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_130") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_130")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_130")))))) 
            (size-of-u32 (string-length (get-field "why" (param 0))))))))
 */
static std::function<Size(::dessser::gen::alerting_inhibition::t const &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::alerting_inhibition::t const &)> fun131 { [&](::dessser::gen::alerting_inhibition::t p_0) {
    std::string id_132 { p_0.what };
    uint32_t id_133 { (uint32_t)id_132.size() };
    Vec<1, uint32_t> id_134 {  id_133  };
    Size let_res_135;
    {
      Vec<1, uint32_t> n_ref_119 { id_134 };
      uint32_t id_136 { 1U };
      Vec<1, uint32_t> id_137 {  id_136  };
      Size let_res_138;
      {
        Vec<1, uint32_t> lebsz_ref_120 { id_137 };
        bool while_flag_139 { true };
        do {
          uint8_t id_140 { 0 };
          uint32_t id_141 { n_ref_119[id_140] };
          uint8_t id_142 { 0 };
          uint32_t id_143 { lebsz_ref_120[id_142] };
          uint8_t id_144 { 7 };
          uint32_t id_145 { uint32_t(id_143 << id_144) };
          bool id_146 { bool(id_141 >= id_145) };
          while_flag_139 = id_146;
          if (while_flag_139) {
            uint8_t id_147 { 0 };
            uint8_t id_148 { 0 };
            uint32_t id_149 { lebsz_ref_120[id_148] };
            uint32_t id_150 { 1U };
            uint32_t id_151 { uint32_t(id_149 + id_150) };
            Void id_152 { ((void)(lebsz_ref_120[id_147] = id_151), ::dessser::Void()) };
            (void)id_152;
          }
        } while (while_flag_139);
        (void)::dessser::Void();
        uint8_t id_153 { 0 };
        uint32_t id_154 { lebsz_ref_120[id_153] };
        Size id_155 { Size(id_154) };
        let_res_138 = id_155;
      }
      let_res_135 = let_res_138;
    }
    std::string id_156 { p_0.what };
    uint32_t id_157 { (uint32_t)id_156.size() };
    Size id_158 { Size(id_157) };
    Size id_159 { Size(let_res_135 + id_158) };
    Size id_160 { 8UL };
    Size id_161 { Size(id_159 + id_160) };
    Size id_162 { 8UL };
    Size id_163 { Size(id_161 + id_162) };
    Size let_res_164;
    {
      Size sz_123 { id_163 };
      std::string id_165 { p_0.who };
      uint32_t id_166 { (uint32_t)id_165.size() };
      Vec<1, uint32_t> id_167 {  id_166  };
      Size let_res_168;
      {
        Vec<1, uint32_t> n_ref_125 { id_167 };
        uint32_t id_169 { 1U };
        Vec<1, uint32_t> id_170 {  id_169  };
        Size let_res_171;
        {
          Vec<1, uint32_t> lebsz_ref_126 { id_170 };
          bool while_flag_172 { true };
          do {
            uint8_t id_173 { 0 };
            uint32_t id_174 { n_ref_125[id_173] };
            uint8_t id_175 { 0 };
            uint32_t id_176 { lebsz_ref_126[id_175] };
            uint8_t id_177 { 7 };
            uint32_t id_178 { uint32_t(id_176 << id_177) };
            bool id_179 { bool(id_174 >= id_178) };
            while_flag_172 = id_179;
            if (while_flag_172) {
              uint8_t id_180 { 0 };
              uint8_t id_181 { 0 };
              uint32_t id_182 { lebsz_ref_126[id_181] };
              uint32_t id_183 { 1U };
              uint32_t id_184 { uint32_t(id_182 + id_183) };
              Void id_185 { ((void)(lebsz_ref_126[id_180] = id_184), ::dessser::Void()) };
              (void)id_185;
            }
          } while (while_flag_172);
          (void)::dessser::Void();
          uint8_t id_186 { 0 };
          uint32_t id_187 { lebsz_ref_126[id_186] };
          Size id_188 { Size(id_187) };
          let_res_171 = id_188;
        }
        let_res_168 = let_res_171;
      }
      std::string id_189 { p_0.who };
      uint32_t id_190 { (uint32_t)id_189.size() };
      Size id_191 { Size(id_190) };
      Size id_192 { Size(let_res_168 + id_191) };
      Size id_193 { Size(sz_123 + id_192) };
      let_res_164 = id_193;
    }
    Size let_res_194;
    {
      Size sz_127 { let_res_164 };
      std::string id_195 { p_0.why };
      uint32_t id_196 { (uint32_t)id_195.size() };
      Vec<1, uint32_t> id_197 {  id_196  };
      Size let_res_198;
      {
        Vec<1, uint32_t> n_ref_129 { id_197 };
        uint32_t id_199 { 1U };
        Vec<1, uint32_t> id_200 {  id_199  };
        Size let_res_201;
        {
          Vec<1, uint32_t> lebsz_ref_130 { id_200 };
          bool while_flag_202 { true };
          do {
            uint8_t id_203 { 0 };
            uint32_t id_204 { n_ref_129[id_203] };
            uint8_t id_205 { 0 };
            uint32_t id_206 { lebsz_ref_130[id_205] };
            uint8_t id_207 { 7 };
            uint32_t id_208 { uint32_t(id_206 << id_207) };
            bool id_209 { bool(id_204 >= id_208) };
            while_flag_202 = id_209;
            if (while_flag_202) {
              uint8_t id_210 { 0 };
              uint8_t id_211 { 0 };
              uint32_t id_212 { lebsz_ref_130[id_211] };
              uint32_t id_213 { 1U };
              uint32_t id_214 { uint32_t(id_212 + id_213) };
              Void id_215 { ((void)(lebsz_ref_130[id_210] = id_214), ::dessser::Void()) };
              (void)id_215;
            }
          } while (while_flag_202);
          (void)::dessser::Void();
          uint8_t id_216 { 0 };
          uint32_t id_217 { lebsz_ref_130[id_216] };
          Size id_218 { Size(id_217) };
          let_res_201 = id_218;
        }
        let_res_198 = let_res_201;
      }
      std::string id_219 { p_0.why };
      uint32_t id_220 { (uint32_t)id_219.size() };
      Size id_221 { Size(id_220) };
      Size id_222 { Size(let_res_198 + id_221) };
      Size id_223 { Size(sz_127 + id_222) };
      let_res_194 = id_223;
    }
    return let_res_194;
  }
   };
  return fun131;
}
std::function<Size(::dessser::gen::alerting_inhibition::t const &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_69"
        (let "dstring1_63"
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
                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_57"))) (unsafe-nth (u8 0) (identifier "p_ref_59")))))))
          (let-pair "dstring1_fst_64" "dstring1_snd_65" (identifier "dstring1_63")
            (let-pair "dstring2_fst_67" "dstring2_snd_68" (read-bytes (identifier "dstring1_snd_65") (identifier "dstring1_fst_64")) (make-tup (string-of-bytes (identifier "dstring2_fst_67")) (identifier "dstring2_snd_68")))))
        (let-pair "drec_fst_70" "drec_snd_71" (identifier "drec_69")
          (let "drec_75" (let-pair "dfloat_fst_73" "dfloat_snd_74" (read-u64 little-endian (identifier "drec_snd_71")) (make-tup (float-of-u64 (identifier "dfloat_fst_73")) (identifier "dfloat_snd_74")))
            (let-pair "drec_fst_76" "drec_snd_77" (identifier "drec_75")
              (let "drec_81" (let-pair "dfloat_fst_79" "dfloat_snd_80" (read-u64 little-endian (identifier "drec_snd_77")) (make-tup (float-of-u64 (identifier "dfloat_fst_79")) (identifier "dfloat_snd_80")))
                (let-pair "drec_fst_82" "drec_snd_83" (identifier "drec_81")
                  (let "drec_96"
                    (let "dstring1_90"
                      (let "leb_ref_84" (make-vec (u32 0))
                        (let "shft_ref_85" (make-vec (u8 0))
                          (let "p_ref_86" (make-vec (identifier "drec_snd_83"))
                            (seq
                              (while
                                (let "leb128_87" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_86")))
                                  (let-pair "leb128_fst_88" "leb128_snd_89" 
                                    (identifier "leb128_87")
                                    (seq (set-vec (u8 0) (identifier "p_ref_86") (identifier "leb128_snd_89"))
                                      (set-vec (u8 0) (identifier "leb_ref_84")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_88") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_85"))) (unsafe-nth (u8 0) (identifier "leb_ref_84"))))
                                      (set-vec (u8 0) (identifier "shft_ref_85") (add (unsafe-nth (u8 0) (identifier "shft_ref_85")) (u8 7))) 
                                      (ge (identifier "leb128_fst_88") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_84"))) (unsafe-nth (u8 0) (identifier "p_ref_86")))))))
                      (let-pair "dstring1_fst_91" "dstring1_snd_92" (identifier "dstring1_90")
                        (let-pair "dstring2_fst_94" "dstring2_snd_95" 
                          (read-bytes (identifier "dstring1_snd_92") (identifier "dstring1_fst_91")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_94")) (identifier "dstring2_snd_95")))))
                    (let-pair "drec_fst_97" "drec_snd_98" (identifier "drec_96")
                      (let "dstring1_105"
                        (let "leb_ref_99" (make-vec (u32 0))
                          (let "shft_ref_100" (make-vec (u8 0))
                            (let "p_ref_101" (make-vec (identifier "drec_snd_98"))
                              (seq
                                (while
                                  (let "leb128_102" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_101")))
                                    (let-pair "leb128_fst_103" "leb128_snd_104" 
                                      (identifier "leb128_102")
                                      (seq (set-vec (u8 0) (identifier "p_ref_101") (identifier "leb128_snd_104"))
                                        (set-vec (u8 0) (identifier "leb_ref_99")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_103") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_100"))) (unsafe-nth (u8 0) (identifier "leb_ref_99"))))
                                        (set-vec (u8 0) (identifier "shft_ref_100") (add (unsafe-nth (u8 0) (identifier "shft_ref_100")) (u8 7))) 
                                        (ge (identifier "leb128_fst_103") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_99"))) (unsafe-nth (u8 0) (identifier "p_ref_101")))))))
                        (let-pair "dstring1_fst_106" "dstring1_snd_107" 
                          (identifier "dstring1_105")
                          (let-pair "dstring2_fst_109" "dstring2_snd_110" 
                            (read-bytes (identifier "dstring1_snd_107") (identifier "dstring1_fst_106"))
                            (make-tup
                              (make-rec (string "why") (string-of-bytes (identifier "dstring2_fst_109")) 
                                (string "who") (identifier "drec_fst_97") 
                                (string "stop_date") (identifier "drec_fst_82") 
                                (string "start_date") (identifier "drec_fst_76") 
                                (string "what") (identifier "drec_fst_70")) 
                              (identifier "dstring2_snd_110"))))))))))))))
 */
static std::function<::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3(Pointer &)> fun224 { [&](Pointer p_0) {
    uint32_t id_225 { 0U };
    Vec<1, uint32_t> id_226 {  id_225  };
    ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa let_res_227;
    {
      Vec<1, uint32_t> leb_ref_57 { id_226 };
      uint8_t id_228 { 0 };
      Vec<1, uint8_t> id_229 {  id_228  };
      ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa let_res_230;
      {
        Vec<1, uint8_t> shft_ref_58 { id_229 };
        Vec<1, Pointer> id_231 {  p_0  };
        ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa let_res_232;
        {
          Vec<1, Pointer> p_ref_59 { id_231 };
          bool while_flag_233 { true };
          do {
            uint8_t id_234 { 0 };
            Pointer id_235 { p_ref_59[id_234] };
            ::dessser::gen::alerting_inhibition::t1a5d74abf838df33f185a72a8912f5c9 id_236 { id_235.readU8() };
            bool let_res_237;
            {
              ::dessser::gen::alerting_inhibition::t1a5d74abf838df33f185a72a8912f5c9 leb128_60 { id_236 };
              bool letpair_res_238;
              {
                auto leb128_fst_61 { std::get<0>(leb128_60) };
                auto leb128_snd_62 { std::get<1>(leb128_60) };
                uint8_t id_239 { 0 };
                Void id_240 { ((void)(p_ref_59[id_239] = leb128_snd_62), ::dessser::Void()) };
                (void)id_240;
                uint8_t id_241 { 0 };
                uint8_t id_242 { 127 };
                uint8_t id_243 { uint8_t(leb128_fst_61 & id_242) };
                uint32_t id_244 { uint32_t(id_243) };
                uint8_t id_245 { 0 };
                uint8_t id_246 { shft_ref_58[id_245] };
                uint32_t id_247 { uint32_t(id_244 << id_246) };
                uint8_t id_248 { 0 };
                uint32_t id_249 { leb_ref_57[id_248] };
                uint32_t id_250 { uint32_t(id_247 | id_249) };
                Void id_251 { ((void)(leb_ref_57[id_241] = id_250), ::dessser::Void()) };
                (void)id_251;
                uint8_t id_252 { 0 };
                uint8_t id_253 { 0 };
                uint8_t id_254 { shft_ref_58[id_253] };
                uint8_t id_255 { 7 };
                uint8_t id_256 { uint8_t(id_254 + id_255) };
                Void id_257 { ((void)(shft_ref_58[id_252] = id_256), ::dessser::Void()) };
                (void)id_257;
                uint8_t id_258 { 128 };
                bool id_259 { bool(leb128_fst_61 >= id_258) };
                letpair_res_238 = id_259;
              }
              let_res_237 = letpair_res_238;
            }
            while_flag_233 = let_res_237;
            if (while_flag_233) {
              (void)::dessser::Void();
            }
          } while (while_flag_233);
          (void)::dessser::Void();
          uint8_t id_260 { 0 };
          uint32_t id_261 { leb_ref_57[id_260] };
          Size id_262 { Size(id_261) };
          uint8_t id_263 { 0 };
          Pointer id_264 { p_ref_59[id_263] };
          ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa id_265 { id_262, id_264 };
          let_res_232 = id_265;
        }
        let_res_230 = let_res_232;
      }
      let_res_227 = let_res_230;
    }
    ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 let_res_266;
    {
      ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa dstring1_63 { let_res_227 };
      ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 letpair_res_267;
      {
        auto dstring1_fst_64 { std::get<0>(dstring1_63) };
        auto dstring1_snd_65 { std::get<1>(dstring1_63) };
        ::dessser::gen::alerting_inhibition::t9ef6882174ae71a34a3c5ef6b29242fb id_268 { dstring1_snd_65.readBytes(dstring1_fst_64) };
        ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 letpair_res_269;
        {
          auto dstring2_fst_67 { std::get<0>(id_268) };
          auto dstring2_snd_68 { std::get<1>(id_268) };
          std::string id_270 { dstring2_fst_67.toString() };
          ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 id_271 { id_270, dstring2_snd_68 };
          letpair_res_269 = id_271;
        }
        letpair_res_267 = letpair_res_269;
      }
      let_res_266 = letpair_res_267;
    }
    ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 let_res_272;
    {
      ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 drec_69 { let_res_266 };
      ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 letpair_res_273;
      {
        auto drec_fst_70 { std::get<0>(drec_69) };
        auto drec_snd_71 { std::get<1>(drec_69) };
        ::dessser::gen::alerting_inhibition::td2cd337bb3c8bc04d5603393d084985b id_274 { drec_snd_71.readU64Le() };
        ::dessser::gen::alerting_inhibition::t9a758baeff17224a77e1a522010b4168 letpair_res_275;
        {
          auto dfloat_fst_73 { std::get<0>(id_274) };
          auto dfloat_snd_74 { std::get<1>(id_274) };
          double id_276 { float_of_qword(dfloat_fst_73) };
          ::dessser::gen::alerting_inhibition::t9a758baeff17224a77e1a522010b4168 id_277 { id_276, dfloat_snd_74 };
          letpair_res_275 = id_277;
        }
        ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 let_res_278;
        {
          ::dessser::gen::alerting_inhibition::t9a758baeff17224a77e1a522010b4168 drec_75 { letpair_res_275 };
          ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 letpair_res_279;
          {
            auto drec_fst_76 { std::get<0>(drec_75) };
            auto drec_snd_77 { std::get<1>(drec_75) };
            ::dessser::gen::alerting_inhibition::td2cd337bb3c8bc04d5603393d084985b id_280 { drec_snd_77.readU64Le() };
            ::dessser::gen::alerting_inhibition::t9a758baeff17224a77e1a522010b4168 letpair_res_281;
            {
              auto dfloat_fst_79 { std::get<0>(id_280) };
              auto dfloat_snd_80 { std::get<1>(id_280) };
              double id_282 { float_of_qword(dfloat_fst_79) };
              ::dessser::gen::alerting_inhibition::t9a758baeff17224a77e1a522010b4168 id_283 { id_282, dfloat_snd_80 };
              letpair_res_281 = id_283;
            }
            ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 let_res_284;
            {
              ::dessser::gen::alerting_inhibition::t9a758baeff17224a77e1a522010b4168 drec_81 { letpair_res_281 };
              ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 letpair_res_285;
              {
                auto drec_fst_82 { std::get<0>(drec_81) };
                auto drec_snd_83 { std::get<1>(drec_81) };
                uint32_t id_286 { 0U };
                Vec<1, uint32_t> id_287 {  id_286  };
                ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa let_res_288;
                {
                  Vec<1, uint32_t> leb_ref_84 { id_287 };
                  uint8_t id_289 { 0 };
                  Vec<1, uint8_t> id_290 {  id_289  };
                  ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa let_res_291;
                  {
                    Vec<1, uint8_t> shft_ref_85 { id_290 };
                    Vec<1, Pointer> id_292 {  drec_snd_83  };
                    ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa let_res_293;
                    {
                      Vec<1, Pointer> p_ref_86 { id_292 };
                      bool while_flag_294 { true };
                      do {
                        uint8_t id_295 { 0 };
                        Pointer id_296 { p_ref_86[id_295] };
                        ::dessser::gen::alerting_inhibition::t1a5d74abf838df33f185a72a8912f5c9 id_297 { id_296.readU8() };
                        bool let_res_298;
                        {
                          ::dessser::gen::alerting_inhibition::t1a5d74abf838df33f185a72a8912f5c9 leb128_87 { id_297 };
                          bool letpair_res_299;
                          {
                            auto leb128_fst_88 { std::get<0>(leb128_87) };
                            auto leb128_snd_89 { std::get<1>(leb128_87) };
                            uint8_t id_300 { 0 };
                            Void id_301 { ((void)(p_ref_86[id_300] = leb128_snd_89), ::dessser::Void()) };
                            (void)id_301;
                            uint8_t id_302 { 0 };
                            uint8_t id_303 { 127 };
                            uint8_t id_304 { uint8_t(leb128_fst_88 & id_303) };
                            uint32_t id_305 { uint32_t(id_304) };
                            uint8_t id_306 { 0 };
                            uint8_t id_307 { shft_ref_85[id_306] };
                            uint32_t id_308 { uint32_t(id_305 << id_307) };
                            uint8_t id_309 { 0 };
                            uint32_t id_310 { leb_ref_84[id_309] };
                            uint32_t id_311 { uint32_t(id_308 | id_310) };
                            Void id_312 { ((void)(leb_ref_84[id_302] = id_311), ::dessser::Void()) };
                            (void)id_312;
                            uint8_t id_313 { 0 };
                            uint8_t id_314 { 0 };
                            uint8_t id_315 { shft_ref_85[id_314] };
                            uint8_t id_316 { 7 };
                            uint8_t id_317 { uint8_t(id_315 + id_316) };
                            Void id_318 { ((void)(shft_ref_85[id_313] = id_317), ::dessser::Void()) };
                            (void)id_318;
                            uint8_t id_319 { 128 };
                            bool id_320 { bool(leb128_fst_88 >= id_319) };
                            letpair_res_299 = id_320;
                          }
                          let_res_298 = letpair_res_299;
                        }
                        while_flag_294 = let_res_298;
                        if (while_flag_294) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_294);
                      (void)::dessser::Void();
                      uint8_t id_321 { 0 };
                      uint32_t id_322 { leb_ref_84[id_321] };
                      Size id_323 { Size(id_322) };
                      uint8_t id_324 { 0 };
                      Pointer id_325 { p_ref_86[id_324] };
                      ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa id_326 { id_323, id_325 };
                      let_res_293 = id_326;
                    }
                    let_res_291 = let_res_293;
                  }
                  let_res_288 = let_res_291;
                }
                ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 let_res_327;
                {
                  ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa dstring1_90 { let_res_288 };
                  ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 letpair_res_328;
                  {
                    auto dstring1_fst_91 { std::get<0>(dstring1_90) };
                    auto dstring1_snd_92 { std::get<1>(dstring1_90) };
                    ::dessser::gen::alerting_inhibition::t9ef6882174ae71a34a3c5ef6b29242fb id_329 { dstring1_snd_92.readBytes(dstring1_fst_91) };
                    ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 letpair_res_330;
                    {
                      auto dstring2_fst_94 { std::get<0>(id_329) };
                      auto dstring2_snd_95 { std::get<1>(id_329) };
                      std::string id_331 { dstring2_fst_94.toString() };
                      ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 id_332 { id_331, dstring2_snd_95 };
                      letpair_res_330 = id_332;
                    }
                    letpair_res_328 = letpair_res_330;
                  }
                  let_res_327 = letpair_res_328;
                }
                ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 let_res_333;
                {
                  ::dessser::gen::alerting_inhibition::t13a07ee37ab40962540da8534858dc07 drec_96 { let_res_327 };
                  ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 letpair_res_334;
                  {
                    auto drec_fst_97 { std::get<0>(drec_96) };
                    auto drec_snd_98 { std::get<1>(drec_96) };
                    uint32_t id_335 { 0U };
                    Vec<1, uint32_t> id_336 {  id_335  };
                    ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa let_res_337;
                    {
                      Vec<1, uint32_t> leb_ref_99 { id_336 };
                      uint8_t id_338 { 0 };
                      Vec<1, uint8_t> id_339 {  id_338  };
                      ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa let_res_340;
                      {
                        Vec<1, uint8_t> shft_ref_100 { id_339 };
                        Vec<1, Pointer> id_341 {  drec_snd_98  };
                        ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa let_res_342;
                        {
                          Vec<1, Pointer> p_ref_101 { id_341 };
                          bool while_flag_343 { true };
                          do {
                            uint8_t id_344 { 0 };
                            Pointer id_345 { p_ref_101[id_344] };
                            ::dessser::gen::alerting_inhibition::t1a5d74abf838df33f185a72a8912f5c9 id_346 { id_345.readU8() };
                            bool let_res_347;
                            {
                              ::dessser::gen::alerting_inhibition::t1a5d74abf838df33f185a72a8912f5c9 leb128_102 { id_346 };
                              bool letpair_res_348;
                              {
                                auto leb128_fst_103 { std::get<0>(leb128_102) };
                                auto leb128_snd_104 { std::get<1>(leb128_102) };
                                uint8_t id_349 { 0 };
                                Void id_350 { ((void)(p_ref_101[id_349] = leb128_snd_104), ::dessser::Void()) };
                                (void)id_350;
                                uint8_t id_351 { 0 };
                                uint8_t id_352 { 127 };
                                uint8_t id_353 { uint8_t(leb128_fst_103 & id_352) };
                                uint32_t id_354 { uint32_t(id_353) };
                                uint8_t id_355 { 0 };
                                uint8_t id_356 { shft_ref_100[id_355] };
                                uint32_t id_357 { uint32_t(id_354 << id_356) };
                                uint8_t id_358 { 0 };
                                uint32_t id_359 { leb_ref_99[id_358] };
                                uint32_t id_360 { uint32_t(id_357 | id_359) };
                                Void id_361 { ((void)(leb_ref_99[id_351] = id_360), ::dessser::Void()) };
                                (void)id_361;
                                uint8_t id_362 { 0 };
                                uint8_t id_363 { 0 };
                                uint8_t id_364 { shft_ref_100[id_363] };
                                uint8_t id_365 { 7 };
                                uint8_t id_366 { uint8_t(id_364 + id_365) };
                                Void id_367 { ((void)(shft_ref_100[id_362] = id_366), ::dessser::Void()) };
                                (void)id_367;
                                uint8_t id_368 { 128 };
                                bool id_369 { bool(leb128_fst_103 >= id_368) };
                                letpair_res_348 = id_369;
                              }
                              let_res_347 = letpair_res_348;
                            }
                            while_flag_343 = let_res_347;
                            if (while_flag_343) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_343);
                          (void)::dessser::Void();
                          uint8_t id_370 { 0 };
                          uint32_t id_371 { leb_ref_99[id_370] };
                          Size id_372 { Size(id_371) };
                          uint8_t id_373 { 0 };
                          Pointer id_374 { p_ref_101[id_373] };
                          ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa id_375 { id_372, id_374 };
                          let_res_342 = id_375;
                        }
                        let_res_340 = let_res_342;
                      }
                      let_res_337 = let_res_340;
                    }
                    ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 let_res_376;
                    {
                      ::dessser::gen::alerting_inhibition::t12fb9c475959b52bf7b17b155a955ffa dstring1_105 { let_res_337 };
                      ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 letpair_res_377;
                      {
                        auto dstring1_fst_106 { std::get<0>(dstring1_105) };
                        auto dstring1_snd_107 { std::get<1>(dstring1_105) };
                        ::dessser::gen::alerting_inhibition::t9ef6882174ae71a34a3c5ef6b29242fb id_378 { dstring1_snd_107.readBytes(dstring1_fst_106) };
                        ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 letpair_res_379;
                        {
                          auto dstring2_fst_109 { std::get<0>(id_378) };
                          auto dstring2_snd_110 { std::get<1>(id_378) };
                          std::string id_380 { dstring2_fst_109.toString() };
                          ::dessser::gen::alerting_inhibition::t id_381 { drec_fst_70, drec_fst_76, drec_fst_82, drec_fst_97, id_380 };
                          ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 id_382 { id_381, dstring2_snd_110 };
                          letpair_res_379 = id_382;
                        }
                        letpair_res_377 = letpair_res_379;
                      }
                      let_res_376 = letpair_res_377;
                    }
                    letpair_res_334 = let_res_376;
                  }
                  let_res_333 = letpair_res_334;
                }
                letpair_res_285 = let_res_333;
              }
              let_res_284 = letpair_res_285;
            }
            letpair_res_279 = let_res_284;
          }
          let_res_278 = letpair_res_279;
        }
        letpair_res_273 = let_res_278;
      }
      let_res_272 = letpair_res_273;
    }
    return let_res_272;
  }
   };
  return fun224;
}
std::function<::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_115" "make_snd_116" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_115") (identifier "make_snd_116"))))
 */
static std::function<::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3(Pointer &)> fun383 { [&](Pointer p_0) {
    ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 id_384 { of_row_binary(p_0) };
    ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 letpair_res_385;
    {
      auto make_fst_115 { std::get<0>(id_384) };
      auto make_snd_116 { std::get<1>(id_384) };
      ::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3 id_386 { make_fst_115, make_snd_116 };
      letpair_res_385 = id_386;
    }
    return letpair_res_385;
  }
   };
  return fun383;
}
std::function<::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{what: STRING; start_date: FLOAT; stop_date: FLOAT; who: STRING; why: STRING}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::alerting_inhibition::t const &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::alerting_inhibition::t const &,Pointer &)> fun387 { [&](::dessser::gen::alerting_inhibition::t p_0, Pointer p_1) {
    Pointer id_388 { to_row_binary(p_0, p_1) };
    return id_388;
  }
   };
  return fun387;
}
std::function<Pointer(::dessser::gen::alerting_inhibition::t const &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
