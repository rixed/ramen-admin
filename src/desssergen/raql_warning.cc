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

namespace dessser::gen::raql_warning {
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
  std::optional<uint32_t> line;
  std::optional<uint32_t> column;
  std::string message;
  t(std::optional<uint32_t> line_, std::optional<uint32_t> column_, std::string message_) : line(line_), column(column_), message(message_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ((a.line && b.line && a.line.value() == b.line.value()) || (!a.line && !b.line)) && ((a.column && b.column && a.column.value() == b.column.value()) || (!a.column && !b.column)) && a.message == b.message;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t295f2df97e866209f4856553b103991a : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_warning::t> ,
  Pointer
> {
  using tuple::tuple;
  t295f2df97e866209f4856553b103991a(std::tuple<std::shared_ptr<::dessser::gen::raql_warning::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_warning::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t295f2df97e866209f4856553b103991a const &a, t295f2df97e866209f4856553b103991a const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t295f2df97e866209f4856553b103991a const &a, t295f2df97e866209f4856553b103991a const &b) {
  return !operator==(a, b);
}
struct t112740284841ba75ec1e9fc60758e609 : public std::tuple<
  std::optional<uint32_t>,
  Pointer
> {
  using tuple::tuple;
  t112740284841ba75ec1e9fc60758e609(std::tuple<std::optional<uint32_t>, Pointer> p)
    : std::tuple<std::optional<uint32_t>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t112740284841ba75ec1e9fc60758e609 const &a, t112740284841ba75ec1e9fc60758e609 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t112740284841ba75ec1e9fc60758e609 const &a, t112740284841ba75ec1e9fc60758e609 const &b) {
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
    (fun ("{line: U32?; column: U32?; message: STRING}" "Ptr")
      (let "srec_dst_100"
        (let "srec_dst_99" (if (is-null (get-field "line" (param 0))) (write-u8 (param 1) (u8 1)) (write-u32 little-endian (write-u8 (param 1) (u8 0)) (force (get-field "line" (param 0)))))
          (if (is-null (get-field "column" (param 0))) (write-u8 (identifier "srec_dst_99") (u8 1)) (write-u32 little-endian (write-u8 (identifier "srec_dst_99") (u8 0)) (force (get-field "column" (param 0))))))
        (write-bytes
          (let "leb128_sz_101" (make-vec (string-length (get-field "message" (param 0))))
            (let "leb128_ptr_102" (make-vec (identifier "srec_dst_100"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_102")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_102"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_101"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_101"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_101"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_101") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_101")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_101")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_102"))))) 
          (bytes-of-string (get-field "message" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_warning::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_warning::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::raql_warning::t>  p_0, Pointer p_1) {
    std::optional<uint32_t> id_1 { (*p_0).line };
    bool id_2 { !(id_1.has_value ()) };
    Pointer choose_res_3;
    if (id_2) {
      uint8_t id_4 { 1 };
      Pointer id_5 { p_1.writeU8(id_4) };
      choose_res_3 = id_5;
    } else {
      uint8_t id_6 { 0 };
      Pointer id_7 { p_1.writeU8(id_6) };
      std::optional<uint32_t> id_8 { (*p_0).line };
      uint32_t id_9 { id_8.value() };
      Pointer id_10 { id_7.writeU32Le(id_9) };
      choose_res_3 = id_10;
    }
    Pointer let_res_11;
    {
      Pointer srec_dst_99 { choose_res_3 };
      std::optional<uint32_t> id_12 { (*p_0).column };
      bool id_13 { !(id_12.has_value ()) };
      Pointer choose_res_14;
      if (id_13) {
        uint8_t id_15 { 1 };
        Pointer id_16 { srec_dst_99.writeU8(id_15) };
        choose_res_14 = id_16;
      } else {
        uint8_t id_17 { 0 };
        Pointer id_18 { srec_dst_99.writeU8(id_17) };
        std::optional<uint32_t> id_19 { (*p_0).column };
        uint32_t id_20 { id_19.value() };
        Pointer id_21 { id_18.writeU32Le(id_20) };
        choose_res_14 = id_21;
      }
      let_res_11 = choose_res_14;
    }
    Pointer let_res_22;
    {
      Pointer srec_dst_100 { let_res_11 };
      std::string id_23 { (*p_0).message };
      uint32_t id_24 { (uint32_t)id_23.size() };
      Vec<1, uint32_t> id_25 {  id_24  };
      Pointer let_res_26;
      {
        Vec<1, uint32_t> leb128_sz_101 { id_25 };
        Vec<1, Pointer> id_27 {  srec_dst_100  };
        Pointer let_res_28;
        {
          Vec<1, Pointer> leb128_ptr_102 { id_27 };
          bool while_flag_29 { true };
          do {
            uint8_t id_30 { 0 };
            uint8_t id_31 { 0 };
            Pointer id_32 { leb128_ptr_102[id_31] };
            uint32_t id_33 { 128U };
            uint8_t id_34 { 0 };
            uint32_t id_35 { leb128_sz_101[id_34] };
            bool id_36 { bool(id_33 > id_35) };
            uint8_t choose_res_37;
            if (id_36) {
              uint8_t id_38 { 0 };
              uint32_t id_39 { leb128_sz_101[id_38] };
              uint8_t id_40 { uint8_t(id_39) };
              choose_res_37 = id_40;
            } else {
              uint8_t id_41 { 0 };
              uint32_t id_42 { leb128_sz_101[id_41] };
              uint8_t id_43 { uint8_t(id_42) };
              uint8_t id_44 { 128 };
              uint8_t id_45 { uint8_t(id_43 | id_44) };
              choose_res_37 = id_45;
            }
            Pointer id_46 { id_32.writeU8(choose_res_37) };
            Void id_47 { ((void)(leb128_ptr_102[id_30] = id_46), ::dessser::Void()) };
            (void)id_47;
            uint8_t id_48 { 0 };
            uint8_t id_49 { 0 };
            uint32_t id_50 { leb128_sz_101[id_49] };
            uint8_t id_51 { 7 };
            uint32_t id_52 { uint32_t(id_50 >> id_51) };
            Void id_53 { ((void)(leb128_sz_101[id_48] = id_52), ::dessser::Void()) };
            (void)id_53;
            uint8_t id_54 { 0 };
            uint32_t id_55 { leb128_sz_101[id_54] };
            uint32_t id_56 { 0U };
            bool id_57 { bool(id_55 > id_56) };
            while_flag_29 = id_57;
            if (while_flag_29) {
              (void)::dessser::Void();
            }
          } while (while_flag_29);
          (void)::dessser::Void();
          uint8_t id_58 { 0 };
          Pointer id_59 { leb128_ptr_102[id_58] };
          let_res_28 = id_59;
        }
        let_res_26 = let_res_28;
      }
      std::string id_60 { (*p_0).message };
      Bytes id_61 { id_60 };
      Pointer id_62 { let_res_26.writeBytes(id_61) };
      let_res_22 = id_62;
    }
    return let_res_22;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_warning::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{line: U32?; column: U32?; message: STRING}")
      (add (if (is-null (get-field "column" (param 0))) (add (if (is-null (get-field "line" (param 0))) (size 1) (size 5)) (size 1)) (add (add (if (is-null (get-field "line" (param 0))) (size 1) (size 5)) (size 4)) (size 1)))
        (add
          (let "n_ref_97" (make-vec (string-length (get-field "message" (param 0))))
            (let "lebsz_ref_98" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_97")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_98")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_98") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_98")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_98")))))) 
          (size-of-u32 (string-length (get-field "message" (param 0)))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_warning::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_warning::t> )> fun63 { [&](std::shared_ptr<::dessser::gen::raql_warning::t>  p_0) {
    std::optional<uint32_t> id_64 { (*p_0).column };
    bool id_65 { !(id_64.has_value ()) };
    Size choose_res_66;
    if (id_65) {
      std::optional<uint32_t> id_67 { (*p_0).line };
      bool id_68 { !(id_67.has_value ()) };
      Size choose_res_69;
      if (id_68) {
        Size id_70 { 1UL };
        choose_res_69 = id_70;
      } else {
        Size id_71 { 5UL };
        choose_res_69 = id_71;
      }
      Size id_72 { 1UL };
      Size id_73 { Size(choose_res_69 + id_72) };
      choose_res_66 = id_73;
    } else {
      std::optional<uint32_t> id_74 { (*p_0).line };
      bool id_75 { !(id_74.has_value ()) };
      Size choose_res_76;
      if (id_75) {
        Size id_77 { 1UL };
        choose_res_76 = id_77;
      } else {
        Size id_78 { 5UL };
        choose_res_76 = id_78;
      }
      Size id_79 { 4UL };
      Size id_80 { Size(choose_res_76 + id_79) };
      Size id_81 { 1UL };
      Size id_82 { Size(id_80 + id_81) };
      choose_res_66 = id_82;
    }
    std::string id_83 { (*p_0).message };
    uint32_t id_84 { (uint32_t)id_83.size() };
    Vec<1, uint32_t> id_85 {  id_84  };
    Size let_res_86;
    {
      Vec<1, uint32_t> n_ref_97 { id_85 };
      uint32_t id_87 { 1U };
      Vec<1, uint32_t> id_88 {  id_87  };
      Size let_res_89;
      {
        Vec<1, uint32_t> lebsz_ref_98 { id_88 };
        bool while_flag_90 { true };
        do {
          uint8_t id_91 { 0 };
          uint32_t id_92 { n_ref_97[id_91] };
          uint8_t id_93 { 0 };
          uint32_t id_94 { lebsz_ref_98[id_93] };
          uint8_t id_95 { 7 };
          uint32_t id_96 { uint32_t(id_94 << id_95) };
          bool id_97 { bool(id_92 >= id_96) };
          while_flag_90 = id_97;
          if (while_flag_90) {
            uint8_t id_98 { 0 };
            uint8_t id_99 { 0 };
            uint32_t id_100 { lebsz_ref_98[id_99] };
            uint32_t id_101 { 1U };
            uint32_t id_102 { uint32_t(id_100 + id_101) };
            Void id_103 { ((void)(lebsz_ref_98[id_98] = id_102), ::dessser::Void()) };
            (void)id_103;
          }
        } while (while_flag_90);
        (void)::dessser::Void();
        uint8_t id_104 { 0 };
        uint32_t id_105 { lebsz_ref_98[id_104] };
        Size id_106 { Size(id_105) };
        let_res_89 = id_106;
      }
      let_res_86 = let_res_89;
    }
    std::string id_107 { (*p_0).message };
    uint32_t id_108 { (uint32_t)id_107.size() };
    Size id_109 { Size(id_108) };
    Size id_110 { Size(let_res_86 + id_109) };
    Size id_111 { Size(choose_res_66 + id_110) };
    return id_111;
  }
   };
  return fun63;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_warning::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_63"
        (if (eq (peek-u8 (param 0) (size 0)) (u8 1)) (make-tup (null "U32") (ptr-add (param 0) (size 1)))
          (let-pair "du32_fst_58" "du32_snd_59" (read-u32 little-endian (ptr-add (param 0) (size 1))) (make-tup (not-null (identifier "du32_fst_58")) (identifier "du32_snd_59"))))
        (let-pair "drec_fst_64" "drec_snd_65" (identifier "drec_63")
          (let "drec_72"
            (if (eq (peek-u8 (identifier "drec_snd_65") (size 0)) (u8 1)) 
              (make-tup (null "U32") (ptr-add (identifier "drec_snd_65") (size 1)))
              (let-pair "du32_fst_67" "du32_snd_68" (read-u32 little-endian (ptr-add (identifier "drec_snd_65") (size 1))) (make-tup (not-null (identifier "du32_fst_67")) (identifier "du32_snd_68"))))
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
                    (make-tup (make-rec (string "message") (string-of-bytes (identifier "dstring2_fst_85")) (string "column") (identifier "drec_fst_73") (string "line") (identifier "drec_fst_64")) (identifier "dstring2_snd_86"))))))))))
 */
static std::function<::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a(Pointer)> fun112 { [&](Pointer p_0) {
    Size id_113 { 0UL };
    uint8_t id_114 { p_0.peekU8(id_113) };
    uint8_t id_115 { 1 };
    bool id_116 { bool(id_114 == id_115) };
    ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 choose_res_117;
    if (id_116) {
      std::optional<uint32_t> id_118 { std::nullopt };
      Size id_119 { 1UL };
      Pointer id_120 { p_0.skip(id_119) };
      ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 id_121 { id_118, id_120 };
      choose_res_117 = id_121;
    } else {
      Size id_122 { 1UL };
      Pointer id_123 { p_0.skip(id_122) };
      ::dessser::gen::raql_warning::t491c44439106a32f896827242e8e76a1 id_124 { id_123.readU32Le() };
      ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 letpair_res_125;
      {
        auto du32_fst_58 { std::get<0>(id_124) };
        auto du32_snd_59 { std::get<1>(id_124) };
        std::optional<uint32_t> id_126 { du32_fst_58 };
        ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 id_127 { id_126, du32_snd_59 };
        letpair_res_125 = id_127;
      }
      choose_res_117 = letpair_res_125;
    }
    ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a let_res_128;
    {
      ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 drec_63 { choose_res_117 };
      ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a letpair_res_129;
      {
        auto drec_fst_64 { std::get<0>(drec_63) };
        auto drec_snd_65 { std::get<1>(drec_63) };
        Size id_130 { 0UL };
        uint8_t id_131 { drec_snd_65.peekU8(id_130) };
        uint8_t id_132 { 1 };
        bool id_133 { bool(id_131 == id_132) };
        ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 choose_res_134;
        if (id_133) {
          std::optional<uint32_t> id_135 { std::nullopt };
          Size id_136 { 1UL };
          Pointer id_137 { drec_snd_65.skip(id_136) };
          ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 id_138 { id_135, id_137 };
          choose_res_134 = id_138;
        } else {
          Size id_139 { 1UL };
          Pointer id_140 { drec_snd_65.skip(id_139) };
          ::dessser::gen::raql_warning::t491c44439106a32f896827242e8e76a1 id_141 { id_140.readU32Le() };
          ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 letpair_res_142;
          {
            auto du32_fst_67 { std::get<0>(id_141) };
            auto du32_snd_68 { std::get<1>(id_141) };
            std::optional<uint32_t> id_143 { du32_fst_67 };
            ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 id_144 { id_143, du32_snd_68 };
            letpair_res_142 = id_144;
          }
          choose_res_134 = letpair_res_142;
        }
        ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a let_res_145;
        {
          ::dessser::gen::raql_warning::t112740284841ba75ec1e9fc60758e609 drec_72 { choose_res_134 };
          ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a letpair_res_146;
          {
            auto drec_fst_73 { std::get<0>(drec_72) };
            auto drec_snd_74 { std::get<1>(drec_72) };
            uint32_t id_147 { 0U };
            Vec<1, uint32_t> id_148 {  id_147  };
            ::dessser::gen::raql_warning::t12fb9c475959b52bf7b17b155a955ffa let_res_149;
            {
              Vec<1, uint32_t> leb_ref_75 { id_148 };
              uint8_t id_150 { 0 };
              Vec<1, uint8_t> id_151 {  id_150  };
              ::dessser::gen::raql_warning::t12fb9c475959b52bf7b17b155a955ffa let_res_152;
              {
                Vec<1, uint8_t> shft_ref_76 { id_151 };
                Vec<1, Pointer> id_153 {  drec_snd_74  };
                ::dessser::gen::raql_warning::t12fb9c475959b52bf7b17b155a955ffa let_res_154;
                {
                  Vec<1, Pointer> p_ref_77 { id_153 };
                  bool while_flag_155 { true };
                  do {
                    uint8_t id_156 { 0 };
                    Pointer id_157 { p_ref_77[id_156] };
                    ::dessser::gen::raql_warning::t1a5d74abf838df33f185a72a8912f5c9 id_158 { id_157.readU8() };
                    bool let_res_159;
                    {
                      ::dessser::gen::raql_warning::t1a5d74abf838df33f185a72a8912f5c9 leb128_78 { id_158 };
                      bool letpair_res_160;
                      {
                        auto leb128_fst_79 { std::get<0>(leb128_78) };
                        auto leb128_snd_80 { std::get<1>(leb128_78) };
                        uint8_t id_161 { 0 };
                        Void id_162 { ((void)(p_ref_77[id_161] = leb128_snd_80), ::dessser::Void()) };
                        (void)id_162;
                        uint8_t id_163 { 0 };
                        uint8_t id_164 { 127 };
                        uint8_t id_165 { uint8_t(leb128_fst_79 & id_164) };
                        uint32_t id_166 { uint32_t(id_165) };
                        uint8_t id_167 { 0 };
                        uint8_t id_168 { shft_ref_76[id_167] };
                        uint32_t id_169 { uint32_t(id_166 << id_168) };
                        uint8_t id_170 { 0 };
                        uint32_t id_171 { leb_ref_75[id_170] };
                        uint32_t id_172 { uint32_t(id_169 | id_171) };
                        Void id_173 { ((void)(leb_ref_75[id_163] = id_172), ::dessser::Void()) };
                        (void)id_173;
                        uint8_t id_174 { 0 };
                        uint8_t id_175 { 0 };
                        uint8_t id_176 { shft_ref_76[id_175] };
                        uint8_t id_177 { 7 };
                        uint8_t id_178 { uint8_t(id_176 + id_177) };
                        Void id_179 { ((void)(shft_ref_76[id_174] = id_178), ::dessser::Void()) };
                        (void)id_179;
                        uint8_t id_180 { 128 };
                        bool id_181 { bool(leb128_fst_79 >= id_180) };
                        letpair_res_160 = id_181;
                      }
                      let_res_159 = letpair_res_160;
                    }
                    while_flag_155 = let_res_159;
                    if (while_flag_155) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_155);
                  (void)::dessser::Void();
                  uint8_t id_182 { 0 };
                  uint32_t id_183 { leb_ref_75[id_182] };
                  Size id_184 { Size(id_183) };
                  uint8_t id_185 { 0 };
                  Pointer id_186 { p_ref_77[id_185] };
                  ::dessser::gen::raql_warning::t12fb9c475959b52bf7b17b155a955ffa id_187 { id_184, id_186 };
                  let_res_154 = id_187;
                }
                let_res_152 = let_res_154;
              }
              let_res_149 = let_res_152;
            }
            ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a let_res_188;
            {
              ::dessser::gen::raql_warning::t12fb9c475959b52bf7b17b155a955ffa dstring1_81 { let_res_149 };
              ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a letpair_res_189;
              {
                auto dstring1_fst_82 { std::get<0>(dstring1_81) };
                auto dstring1_snd_83 { std::get<1>(dstring1_81) };
                ::dessser::gen::raql_warning::t9ef6882174ae71a34a3c5ef6b29242fb id_190 { dstring1_snd_83.readBytes(dstring1_fst_82) };
                ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a letpair_res_191;
                {
                  auto dstring2_fst_85 { std::get<0>(id_190) };
                  auto dstring2_snd_86 { std::get<1>(id_190) };
                  std::string id_192 { dstring2_fst_85.toString() };
                  std::shared_ptr<::dessser::gen::raql_warning::t>  id_193 { std::make_shared<::dessser::gen::raql_warning::t>(drec_fst_64, drec_fst_73, id_192) };
                  ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a id_194 { id_193, dstring2_snd_86 };
                  letpair_res_191 = id_194;
                }
                letpair_res_189 = letpair_res_191;
              }
              let_res_188 = letpair_res_189;
            }
            letpair_res_146 = let_res_188;
          }
          let_res_145 = letpair_res_146;
        }
        letpair_res_129 = let_res_145;
      }
      let_res_128 = letpair_res_129;
    }
    return let_res_128;
  }
   };
  return fun112;
}
std::function<::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_91" "make_snd_92" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_91") (identifier "make_snd_92"))))
 */
static std::function<::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a(Pointer)> fun195 { [&](Pointer p_0) {
    ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a id_196 { of_row_binary(p_0) };
    ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a letpair_res_197;
    {
      auto make_fst_91 { std::get<0>(id_196) };
      auto make_snd_92 { std::get<1>(id_196) };
      ::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a id_198 { make_fst_91, make_snd_92 };
      letpair_res_197 = id_198;
    }
    return letpair_res_197;
  }
   };
  return fun195;
}
std::function<::dessser::gen::raql_warning::t295f2df97e866209f4856553b103991a(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{line: U32?; column: U32?; message: STRING}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_warning::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_warning::t> ,Pointer)> fun199 { [&](std::shared_ptr<::dessser::gen::raql_warning::t>  p_0, Pointer p_1) {
    Pointer id_200 { to_row_binary(p_0, p_1) };
    return id_200;
  }
   };
  return fun199;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_warning::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
