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

namespace dessser::gen::sync_msg {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t206fd5d881820fd19331922d3e213def {
  Bytes nonce;
  Bytes public_key;
  Bytes message;
  t206fd5d881820fd19331922d3e213def(Bytes nonce_, Bytes public_key_, Bytes message_) : nonce(nonce_), public_key(public_key_), message(message_) {}
  t206fd5d881820fd19331922d3e213def() = default;
};
inline bool operator==(t206fd5d881820fd19331922d3e213def const &a, t206fd5d881820fd19331922d3e213def const &b) {
  return a.nonce == b.nonce && a.public_key == b.public_key && a.message == b.message;
}

inline bool operator!=(t206fd5d881820fd19331922d3e213def const &a, t206fd5d881820fd19331922d3e213def const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def, // SendSessionKey
  Bytes, // Crypted
  Bytes, // ClearText
  std::string // Error
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 4 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // SendSessionKey
    case 1: return std::get<1>(a) == std::get<1>(b); // Crypted
    case 2: return std::get<2>(a) == std::get<2>(b); // ClearText
    case 3: return std::get<3>(a) == std::get<3>(b); // Error
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tc374fe7e38202b30396ee364cbb6d53e : public std::tuple<
  ::dessser::gen::sync_msg::t,
  Pointer
> {
  using tuple::tuple;
  tc374fe7e38202b30396ee364cbb6d53e(std::tuple<::dessser::gen::sync_msg::t, Pointer> p)
    : std::tuple<::dessser::gen::sync_msg::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc374fe7e38202b30396ee364cbb6d53e const &a, tc374fe7e38202b30396ee364cbb6d53e const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc374fe7e38202b30396ee364cbb6d53e const &a, tc374fe7e38202b30396ee364cbb6d53e const &b) {
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
    (fun ("[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted Bytes | ClearText Bytes | Error STRING]" "Ptr")
      (let "ssum_dst_170" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_182"
            (let "srec_dst_179"
              (write-bytes
                (let "leb128_sz_177" (make-vec (u32-of-size (bytes-length (get-field "nonce" (get-alt "SendSessionKey" (param 0))))))
                  (let "leb128_ptr_178" (make-vec (identifier "ssum_dst_170"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_178")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_178"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_177"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_177"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_177"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_177") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_177")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_177")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_178"))))) 
                (get-field "nonce" (get-alt "SendSessionKey" (param 0))))
              (write-bytes
                (let "leb128_sz_180" (make-vec (u32-of-size (bytes-length (get-field "public_key" (get-alt "SendSessionKey" (param 0))))))
                  (let "leb128_ptr_181" (make-vec (identifier "srec_dst_179"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_181")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_181"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_180"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_180"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_180"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_180") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_180")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_180")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_181"))))) 
                (get-field "public_key" (get-alt "SendSessionKey" (param 0)))))
            (write-bytes
              (let "leb128_sz_183" (make-vec (u32-of-size (bytes-length (get-field "message" (get-alt "SendSessionKey" (param 0))))))
                (let "leb128_ptr_184" (make-vec (identifier "srec_dst_182"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_184")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_184"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_183"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_183"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_183"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_183") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_183")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_183")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_184"))))) 
              (get-field "message" (get-alt "SendSessionKey" (param 0)))))
          (if (eq (u16 1) (label-of (param 0)))
            (write-bytes
              (let "leb128_sz_175" (make-vec (u32-of-size (bytes-length (get-alt "Crypted" (param 0)))))
                (let "leb128_ptr_176" (make-vec (identifier "ssum_dst_170"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_176")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_176"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_175"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_175"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_175"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_175") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_175")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_175")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_176"))))) 
              (get-alt "Crypted" (param 0)))
            (if (eq (u16 2) (label-of (param 0)))
              (write-bytes
                (let "leb128_sz_173" (make-vec (u32-of-size (bytes-length (get-alt "ClearText" (param 0)))))
                  (let "leb128_ptr_174" (make-vec (identifier "ssum_dst_170"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_174")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_174"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_173"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_173"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_173"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_173") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_173")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_173")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_174"))))) 
                (get-alt "ClearText" (param 0)))
              (seq (assert (eq (label-of (param 0)) (u16 3)))
                (write-bytes
                  (let "leb128_sz_171" (make-vec (string-length (get-alt "Error" (param 0))))
                    (let "leb128_ptr_172" (make-vec (identifier "ssum_dst_170"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_172")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_172"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_171"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_171"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_171"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_171") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_171")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_171")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_172"))))) 
                  (bytes-of-string (get-alt "Error" (param 0))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_msg::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_msg::t &,Pointer &)> fun0 { [&](::dessser::gen::sync_msg::t p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0.index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_170 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0.index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_8 { std::get<0 /* SendSessionKey */>(p_0) };
        Bytes id_9 { id_8.nonce };
        Size id_10 { id_9.length() };
        uint32_t id_11 { uint32_t(id_10) };
        Vec<1, uint32_t> id_12 {  id_11  };
        Pointer let_res_13;
        {
          Vec<1, uint32_t> leb128_sz_177 { id_12 };
          Vec<1, Pointer> id_14 {  ssum_dst_170  };
          Pointer let_res_15;
          {
            Vec<1, Pointer> leb128_ptr_178 { id_14 };
            bool while_flag_16 { true };
            do {
              uint8_t id_17 { 0 };
              uint8_t id_18 { 0 };
              Pointer id_19 { leb128_ptr_178[id_18] };
              uint32_t id_20 { 128U };
              uint8_t id_21 { 0 };
              uint32_t id_22 { leb128_sz_177[id_21] };
              bool id_23 { bool(id_20 > id_22) };
              uint8_t choose_res_24;
              if (id_23) {
                uint8_t id_25 { 0 };
                uint32_t id_26 { leb128_sz_177[id_25] };
                uint8_t id_27 { uint8_t(id_26) };
                choose_res_24 = id_27;
              } else {
                uint8_t id_28 { 0 };
                uint32_t id_29 { leb128_sz_177[id_28] };
                uint8_t id_30 { uint8_t(id_29) };
                uint8_t id_31 { 128 };
                uint8_t id_32 { uint8_t(id_30 | id_31) };
                choose_res_24 = id_32;
              }
              Pointer id_33 { id_19.writeU8(choose_res_24) };
              Void id_34 { ((void)(leb128_ptr_178[id_17] = id_33), ::dessser::Void()) };
              (void)id_34;
              uint8_t id_35 { 0 };
              uint8_t id_36 { 0 };
              uint32_t id_37 { leb128_sz_177[id_36] };
              uint8_t id_38 { 7 };
              uint32_t id_39 { uint32_t(id_37 >> id_38) };
              Void id_40 { ((void)(leb128_sz_177[id_35] = id_39), ::dessser::Void()) };
              (void)id_40;
              uint8_t id_41 { 0 };
              uint32_t id_42 { leb128_sz_177[id_41] };
              uint32_t id_43 { 0U };
              bool id_44 { bool(id_42 > id_43) };
              while_flag_16 = id_44;
              if (while_flag_16) {
                (void)::dessser::Void();
              }
            } while (while_flag_16);
            (void)::dessser::Void();
            uint8_t id_45 { 0 };
            Pointer id_46 { leb128_ptr_178[id_45] };
            let_res_15 = id_46;
          }
          let_res_13 = let_res_15;
        }
        ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_47 { std::get<0 /* SendSessionKey */>(p_0) };
        Bytes id_48 { id_47.nonce };
        Pointer id_49 { let_res_13.writeBytes(id_48) };
        Pointer let_res_50;
        {
          Pointer srec_dst_179 { id_49 };
          ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_51 { std::get<0 /* SendSessionKey */>(p_0) };
          Bytes id_52 { id_51.public_key };
          Size id_53 { id_52.length() };
          uint32_t id_54 { uint32_t(id_53) };
          Vec<1, uint32_t> id_55 {  id_54  };
          Pointer let_res_56;
          {
            Vec<1, uint32_t> leb128_sz_180 { id_55 };
            Vec<1, Pointer> id_57 {  srec_dst_179  };
            Pointer let_res_58;
            {
              Vec<1, Pointer> leb128_ptr_181 { id_57 };
              bool while_flag_59 { true };
              do {
                uint8_t id_60 { 0 };
                uint8_t id_61 { 0 };
                Pointer id_62 { leb128_ptr_181[id_61] };
                uint32_t id_63 { 128U };
                uint8_t id_64 { 0 };
                uint32_t id_65 { leb128_sz_180[id_64] };
                bool id_66 { bool(id_63 > id_65) };
                uint8_t choose_res_67;
                if (id_66) {
                  uint8_t id_68 { 0 };
                  uint32_t id_69 { leb128_sz_180[id_68] };
                  uint8_t id_70 { uint8_t(id_69) };
                  choose_res_67 = id_70;
                } else {
                  uint8_t id_71 { 0 };
                  uint32_t id_72 { leb128_sz_180[id_71] };
                  uint8_t id_73 { uint8_t(id_72) };
                  uint8_t id_74 { 128 };
                  uint8_t id_75 { uint8_t(id_73 | id_74) };
                  choose_res_67 = id_75;
                }
                Pointer id_76 { id_62.writeU8(choose_res_67) };
                Void id_77 { ((void)(leb128_ptr_181[id_60] = id_76), ::dessser::Void()) };
                (void)id_77;
                uint8_t id_78 { 0 };
                uint8_t id_79 { 0 };
                uint32_t id_80 { leb128_sz_180[id_79] };
                uint8_t id_81 { 7 };
                uint32_t id_82 { uint32_t(id_80 >> id_81) };
                Void id_83 { ((void)(leb128_sz_180[id_78] = id_82), ::dessser::Void()) };
                (void)id_83;
                uint8_t id_84 { 0 };
                uint32_t id_85 { leb128_sz_180[id_84] };
                uint32_t id_86 { 0U };
                bool id_87 { bool(id_85 > id_86) };
                while_flag_59 = id_87;
                if (while_flag_59) {
                  (void)::dessser::Void();
                }
              } while (while_flag_59);
              (void)::dessser::Void();
              uint8_t id_88 { 0 };
              Pointer id_89 { leb128_ptr_181[id_88] };
              let_res_58 = id_89;
            }
            let_res_56 = let_res_58;
          }
          ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_90 { std::get<0 /* SendSessionKey */>(p_0) };
          Bytes id_91 { id_90.public_key };
          Pointer id_92 { let_res_56.writeBytes(id_91) };
          let_res_50 = id_92;
        }
        Pointer let_res_93;
        {
          Pointer srec_dst_182 { let_res_50 };
          ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_94 { std::get<0 /* SendSessionKey */>(p_0) };
          Bytes id_95 { id_94.message };
          Size id_96 { id_95.length() };
          uint32_t id_97 { uint32_t(id_96) };
          Vec<1, uint32_t> id_98 {  id_97  };
          Pointer let_res_99;
          {
            Vec<1, uint32_t> leb128_sz_183 { id_98 };
            Vec<1, Pointer> id_100 {  srec_dst_182  };
            Pointer let_res_101;
            {
              Vec<1, Pointer> leb128_ptr_184 { id_100 };
              bool while_flag_102 { true };
              do {
                uint8_t id_103 { 0 };
                uint8_t id_104 { 0 };
                Pointer id_105 { leb128_ptr_184[id_104] };
                uint32_t id_106 { 128U };
                uint8_t id_107 { 0 };
                uint32_t id_108 { leb128_sz_183[id_107] };
                bool id_109 { bool(id_106 > id_108) };
                uint8_t choose_res_110;
                if (id_109) {
                  uint8_t id_111 { 0 };
                  uint32_t id_112 { leb128_sz_183[id_111] };
                  uint8_t id_113 { uint8_t(id_112) };
                  choose_res_110 = id_113;
                } else {
                  uint8_t id_114 { 0 };
                  uint32_t id_115 { leb128_sz_183[id_114] };
                  uint8_t id_116 { uint8_t(id_115) };
                  uint8_t id_117 { 128 };
                  uint8_t id_118 { uint8_t(id_116 | id_117) };
                  choose_res_110 = id_118;
                }
                Pointer id_119 { id_105.writeU8(choose_res_110) };
                Void id_120 { ((void)(leb128_ptr_184[id_103] = id_119), ::dessser::Void()) };
                (void)id_120;
                uint8_t id_121 { 0 };
                uint8_t id_122 { 0 };
                uint32_t id_123 { leb128_sz_183[id_122] };
                uint8_t id_124 { 7 };
                uint32_t id_125 { uint32_t(id_123 >> id_124) };
                Void id_126 { ((void)(leb128_sz_183[id_121] = id_125), ::dessser::Void()) };
                (void)id_126;
                uint8_t id_127 { 0 };
                uint32_t id_128 { leb128_sz_183[id_127] };
                uint32_t id_129 { 0U };
                bool id_130 { bool(id_128 > id_129) };
                while_flag_102 = id_130;
                if (while_flag_102) {
                  (void)::dessser::Void();
                }
              } while (while_flag_102);
              (void)::dessser::Void();
              uint8_t id_131 { 0 };
              Pointer id_132 { leb128_ptr_184[id_131] };
              let_res_101 = id_132;
            }
            let_res_99 = let_res_101;
          }
          ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_133 { std::get<0 /* SendSessionKey */>(p_0) };
          Bytes id_134 { id_133.message };
          Pointer id_135 { let_res_99.writeBytes(id_134) };
          let_res_93 = id_135;
        }
        choose_res_7 = let_res_93;
      } else {
        uint16_t id_136 { 1 };
        uint16_t id_137 { uint16_t(p_0.index()) };
        bool id_138 { bool(id_136 == id_137) };
        Pointer choose_res_139;
        if (id_138) {
          Bytes id_140 { std::get<1 /* Crypted */>(p_0) };
          Size id_141 { id_140.length() };
          uint32_t id_142 { uint32_t(id_141) };
          Vec<1, uint32_t> id_143 {  id_142  };
          Pointer let_res_144;
          {
            Vec<1, uint32_t> leb128_sz_175 { id_143 };
            Vec<1, Pointer> id_145 {  ssum_dst_170  };
            Pointer let_res_146;
            {
              Vec<1, Pointer> leb128_ptr_176 { id_145 };
              bool while_flag_147 { true };
              do {
                uint8_t id_148 { 0 };
                uint8_t id_149 { 0 };
                Pointer id_150 { leb128_ptr_176[id_149] };
                uint32_t id_151 { 128U };
                uint8_t id_152 { 0 };
                uint32_t id_153 { leb128_sz_175[id_152] };
                bool id_154 { bool(id_151 > id_153) };
                uint8_t choose_res_155;
                if (id_154) {
                  uint8_t id_156 { 0 };
                  uint32_t id_157 { leb128_sz_175[id_156] };
                  uint8_t id_158 { uint8_t(id_157) };
                  choose_res_155 = id_158;
                } else {
                  uint8_t id_159 { 0 };
                  uint32_t id_160 { leb128_sz_175[id_159] };
                  uint8_t id_161 { uint8_t(id_160) };
                  uint8_t id_162 { 128 };
                  uint8_t id_163 { uint8_t(id_161 | id_162) };
                  choose_res_155 = id_163;
                }
                Pointer id_164 { id_150.writeU8(choose_res_155) };
                Void id_165 { ((void)(leb128_ptr_176[id_148] = id_164), ::dessser::Void()) };
                (void)id_165;
                uint8_t id_166 { 0 };
                uint8_t id_167 { 0 };
                uint32_t id_168 { leb128_sz_175[id_167] };
                uint8_t id_169 { 7 };
                uint32_t id_170 { uint32_t(id_168 >> id_169) };
                Void id_171 { ((void)(leb128_sz_175[id_166] = id_170), ::dessser::Void()) };
                (void)id_171;
                uint8_t id_172 { 0 };
                uint32_t id_173 { leb128_sz_175[id_172] };
                uint32_t id_174 { 0U };
                bool id_175 { bool(id_173 > id_174) };
                while_flag_147 = id_175;
                if (while_flag_147) {
                  (void)::dessser::Void();
                }
              } while (while_flag_147);
              (void)::dessser::Void();
              uint8_t id_176 { 0 };
              Pointer id_177 { leb128_ptr_176[id_176] };
              let_res_146 = id_177;
            }
            let_res_144 = let_res_146;
          }
          Bytes id_178 { std::get<1 /* Crypted */>(p_0) };
          Pointer id_179 { let_res_144.writeBytes(id_178) };
          choose_res_139 = id_179;
        } else {
          uint16_t id_180 { 2 };
          uint16_t id_181 { uint16_t(p_0.index()) };
          bool id_182 { bool(id_180 == id_181) };
          Pointer choose_res_183;
          if (id_182) {
            Bytes id_184 { std::get<2 /* ClearText */>(p_0) };
            Size id_185 { id_184.length() };
            uint32_t id_186 { uint32_t(id_185) };
            Vec<1, uint32_t> id_187 {  id_186  };
            Pointer let_res_188;
            {
              Vec<1, uint32_t> leb128_sz_173 { id_187 };
              Vec<1, Pointer> id_189 {  ssum_dst_170  };
              Pointer let_res_190;
              {
                Vec<1, Pointer> leb128_ptr_174 { id_189 };
                bool while_flag_191 { true };
                do {
                  uint8_t id_192 { 0 };
                  uint8_t id_193 { 0 };
                  Pointer id_194 { leb128_ptr_174[id_193] };
                  uint32_t id_195 { 128U };
                  uint8_t id_196 { 0 };
                  uint32_t id_197 { leb128_sz_173[id_196] };
                  bool id_198 { bool(id_195 > id_197) };
                  uint8_t choose_res_199;
                  if (id_198) {
                    uint8_t id_200 { 0 };
                    uint32_t id_201 { leb128_sz_173[id_200] };
                    uint8_t id_202 { uint8_t(id_201) };
                    choose_res_199 = id_202;
                  } else {
                    uint8_t id_203 { 0 };
                    uint32_t id_204 { leb128_sz_173[id_203] };
                    uint8_t id_205 { uint8_t(id_204) };
                    uint8_t id_206 { 128 };
                    uint8_t id_207 { uint8_t(id_205 | id_206) };
                    choose_res_199 = id_207;
                  }
                  Pointer id_208 { id_194.writeU8(choose_res_199) };
                  Void id_209 { ((void)(leb128_ptr_174[id_192] = id_208), ::dessser::Void()) };
                  (void)id_209;
                  uint8_t id_210 { 0 };
                  uint8_t id_211 { 0 };
                  uint32_t id_212 { leb128_sz_173[id_211] };
                  uint8_t id_213 { 7 };
                  uint32_t id_214 { uint32_t(id_212 >> id_213) };
                  Void id_215 { ((void)(leb128_sz_173[id_210] = id_214), ::dessser::Void()) };
                  (void)id_215;
                  uint8_t id_216 { 0 };
                  uint32_t id_217 { leb128_sz_173[id_216] };
                  uint32_t id_218 { 0U };
                  bool id_219 { bool(id_217 > id_218) };
                  while_flag_191 = id_219;
                  if (while_flag_191) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_191);
                (void)::dessser::Void();
                uint8_t id_220 { 0 };
                Pointer id_221 { leb128_ptr_174[id_220] };
                let_res_190 = id_221;
              }
              let_res_188 = let_res_190;
            }
            Bytes id_222 { std::get<2 /* ClearText */>(p_0) };
            Pointer id_223 { let_res_188.writeBytes(id_222) };
            choose_res_183 = id_223;
          } else {
            uint16_t id_224 { uint16_t(p_0.index()) };
            uint16_t id_225 { 3 };
            bool id_226 { bool(id_224 == id_225) };
            Void id_227 { ((void)(assert(id_226)), ::dessser::Void()) };
            (void)id_227;
            std::string id_228 { std::get<3 /* Error */>(p_0) };
            uint32_t id_229 { (uint32_t)id_228.size() };
            Vec<1, uint32_t> id_230 {  id_229  };
            Pointer let_res_231;
            {
              Vec<1, uint32_t> leb128_sz_171 { id_230 };
              Vec<1, Pointer> id_232 {  ssum_dst_170  };
              Pointer let_res_233;
              {
                Vec<1, Pointer> leb128_ptr_172 { id_232 };
                bool while_flag_234 { true };
                do {
                  uint8_t id_235 { 0 };
                  uint8_t id_236 { 0 };
                  Pointer id_237 { leb128_ptr_172[id_236] };
                  uint32_t id_238 { 128U };
                  uint8_t id_239 { 0 };
                  uint32_t id_240 { leb128_sz_171[id_239] };
                  bool id_241 { bool(id_238 > id_240) };
                  uint8_t choose_res_242;
                  if (id_241) {
                    uint8_t id_243 { 0 };
                    uint32_t id_244 { leb128_sz_171[id_243] };
                    uint8_t id_245 { uint8_t(id_244) };
                    choose_res_242 = id_245;
                  } else {
                    uint8_t id_246 { 0 };
                    uint32_t id_247 { leb128_sz_171[id_246] };
                    uint8_t id_248 { uint8_t(id_247) };
                    uint8_t id_249 { 128 };
                    uint8_t id_250 { uint8_t(id_248 | id_249) };
                    choose_res_242 = id_250;
                  }
                  Pointer id_251 { id_237.writeU8(choose_res_242) };
                  Void id_252 { ((void)(leb128_ptr_172[id_235] = id_251), ::dessser::Void()) };
                  (void)id_252;
                  uint8_t id_253 { 0 };
                  uint8_t id_254 { 0 };
                  uint32_t id_255 { leb128_sz_171[id_254] };
                  uint8_t id_256 { 7 };
                  uint32_t id_257 { uint32_t(id_255 >> id_256) };
                  Void id_258 { ((void)(leb128_sz_171[id_253] = id_257), ::dessser::Void()) };
                  (void)id_258;
                  uint8_t id_259 { 0 };
                  uint32_t id_260 { leb128_sz_171[id_259] };
                  uint32_t id_261 { 0U };
                  bool id_262 { bool(id_260 > id_261) };
                  while_flag_234 = id_262;
                  if (while_flag_234) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_234);
                (void)::dessser::Void();
                uint8_t id_263 { 0 };
                Pointer id_264 { leb128_ptr_172[id_263] };
                let_res_233 = id_264;
              }
              let_res_231 = let_res_233;
            }
            std::string id_265 { std::get<3 /* Error */>(p_0) };
            Bytes id_266 { id_265 };
            Pointer id_267 { let_res_231.writeBytes(id_266) };
            choose_res_183 = id_267;
          }
          choose_res_139 = choose_res_183;
        }
        choose_res_7 = choose_res_139;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::sync_msg::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted Bytes | ClearText Bytes | Error STRING]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_165"
          (let "sz_161"
            (add (size 2)
              (add
                (let "n_ref_159" (make-vec (u32-of-size (bytes-length (get-field "nonce" (get-alt "SendSessionKey" (param 0))))))
                  (let "lebsz_ref_160" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_159")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_160")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_160") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_160")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_160")))))) 
                (bytes-length (get-field "nonce" (get-alt "SendSessionKey" (param 0))))))
            (add (identifier "sz_161")
              (add
                (let "n_ref_163" (make-vec (u32-of-size (bytes-length (get-field "public_key" (get-alt "SendSessionKey" (param 0))))))
                  (let "lebsz_ref_164" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_163")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_164")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_164") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_164")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_164")))))) 
                (bytes-length (get-field "public_key" (get-alt "SendSessionKey" (param 0)))))))
          (add (identifier "sz_165")
            (add
              (let "n_ref_167" (make-vec (u32-of-size (bytes-length (get-field "message" (get-alt "SendSessionKey" (param 0))))))
                (let "lebsz_ref_168" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_167")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_168")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_168") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_168")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_168")))))) 
              (bytes-length (get-field "message" (get-alt "SendSessionKey" (param 0)))))))
        (if (eq (u16 1) (label-of (param 0)))
          (add (size 2)
            (add
              (let "n_ref_155" (make-vec (u32-of-size (bytes-length (get-alt "Crypted" (param 0)))))
                (let "lebsz_ref_156" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_155")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_156")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_156") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_156")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_156")))))) 
              (bytes-length (get-alt "Crypted" (param 0)))))
          (if (eq (u16 2) (label-of (param 0)))
            (add (size 2)
              (add
                (let "n_ref_152" (make-vec (u32-of-size (bytes-length (get-alt "ClearText" (param 0)))))
                  (let "lebsz_ref_153" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_152")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_153")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_153") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_153")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_153")))))) 
                (bytes-length (get-alt "ClearText" (param 0)))))
            (seq (assert (eq (label-of (param 0)) (u16 3)))
              (add (size 2)
                (add
                  (let "n_ref_149" (make-vec (string-length (get-alt "Error" (param 0))))
                    (let "lebsz_ref_150" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_149")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_150")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_150") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_150")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_150")))))) 
                  (size-of-u32 (string-length (get-alt "Error" (param 0)))))))))))
 */
static std::function<Size(::dessser::gen::sync_msg::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_msg::t &)> fun268 { [&](::dessser::gen::sync_msg::t p_0) {
    uint16_t id_269 { 0 };
    uint16_t id_270 { uint16_t(p_0.index()) };
    bool id_271 { bool(id_269 == id_270) };
    Size choose_res_272;
    if (id_271) {
      Size id_273 { 2UL };
      ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_274 { std::get<0 /* SendSessionKey */>(p_0) };
      Bytes id_275 { id_274.nonce };
      Size id_276 { id_275.length() };
      uint32_t id_277 { uint32_t(id_276) };
      Vec<1, uint32_t> id_278 {  id_277  };
      Size let_res_279;
      {
        Vec<1, uint32_t> n_ref_159 { id_278 };
        uint32_t id_280 { 1U };
        Vec<1, uint32_t> id_281 {  id_280  };
        Size let_res_282;
        {
          Vec<1, uint32_t> lebsz_ref_160 { id_281 };
          bool while_flag_283 { true };
          do {
            uint8_t id_284 { 0 };
            uint32_t id_285 { n_ref_159[id_284] };
            uint8_t id_286 { 0 };
            uint32_t id_287 { lebsz_ref_160[id_286] };
            uint8_t id_288 { 7 };
            uint32_t id_289 { uint32_t(id_287 << id_288) };
            bool id_290 { bool(id_285 >= id_289) };
            while_flag_283 = id_290;
            if (while_flag_283) {
              uint8_t id_291 { 0 };
              uint8_t id_292 { 0 };
              uint32_t id_293 { lebsz_ref_160[id_292] };
              uint32_t id_294 { 1U };
              uint32_t id_295 { uint32_t(id_293 + id_294) };
              Void id_296 { ((void)(lebsz_ref_160[id_291] = id_295), ::dessser::Void()) };
              (void)id_296;
            }
          } while (while_flag_283);
          (void)::dessser::Void();
          uint8_t id_297 { 0 };
          uint32_t id_298 { lebsz_ref_160[id_297] };
          Size id_299 { Size(id_298) };
          let_res_282 = id_299;
        }
        let_res_279 = let_res_282;
      }
      ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_300 { std::get<0 /* SendSessionKey */>(p_0) };
      Bytes id_301 { id_300.nonce };
      Size id_302 { id_301.length() };
      Size id_303 { Size(let_res_279 + id_302) };
      Size id_304 { Size(id_273 + id_303) };
      Size let_res_305;
      {
        Size sz_161 { id_304 };
        ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_306 { std::get<0 /* SendSessionKey */>(p_0) };
        Bytes id_307 { id_306.public_key };
        Size id_308 { id_307.length() };
        uint32_t id_309 { uint32_t(id_308) };
        Vec<1, uint32_t> id_310 {  id_309  };
        Size let_res_311;
        {
          Vec<1, uint32_t> n_ref_163 { id_310 };
          uint32_t id_312 { 1U };
          Vec<1, uint32_t> id_313 {  id_312  };
          Size let_res_314;
          {
            Vec<1, uint32_t> lebsz_ref_164 { id_313 };
            bool while_flag_315 { true };
            do {
              uint8_t id_316 { 0 };
              uint32_t id_317 { n_ref_163[id_316] };
              uint8_t id_318 { 0 };
              uint32_t id_319 { lebsz_ref_164[id_318] };
              uint8_t id_320 { 7 };
              uint32_t id_321 { uint32_t(id_319 << id_320) };
              bool id_322 { bool(id_317 >= id_321) };
              while_flag_315 = id_322;
              if (while_flag_315) {
                uint8_t id_323 { 0 };
                uint8_t id_324 { 0 };
                uint32_t id_325 { lebsz_ref_164[id_324] };
                uint32_t id_326 { 1U };
                uint32_t id_327 { uint32_t(id_325 + id_326) };
                Void id_328 { ((void)(lebsz_ref_164[id_323] = id_327), ::dessser::Void()) };
                (void)id_328;
              }
            } while (while_flag_315);
            (void)::dessser::Void();
            uint8_t id_329 { 0 };
            uint32_t id_330 { lebsz_ref_164[id_329] };
            Size id_331 { Size(id_330) };
            let_res_314 = id_331;
          }
          let_res_311 = let_res_314;
        }
        ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_332 { std::get<0 /* SendSessionKey */>(p_0) };
        Bytes id_333 { id_332.public_key };
        Size id_334 { id_333.length() };
        Size id_335 { Size(let_res_311 + id_334) };
        Size id_336 { Size(sz_161 + id_335) };
        let_res_305 = id_336;
      }
      Size let_res_337;
      {
        Size sz_165 { let_res_305 };
        ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_338 { std::get<0 /* SendSessionKey */>(p_0) };
        Bytes id_339 { id_338.message };
        Size id_340 { id_339.length() };
        uint32_t id_341 { uint32_t(id_340) };
        Vec<1, uint32_t> id_342 {  id_341  };
        Size let_res_343;
        {
          Vec<1, uint32_t> n_ref_167 { id_342 };
          uint32_t id_344 { 1U };
          Vec<1, uint32_t> id_345 {  id_344  };
          Size let_res_346;
          {
            Vec<1, uint32_t> lebsz_ref_168 { id_345 };
            bool while_flag_347 { true };
            do {
              uint8_t id_348 { 0 };
              uint32_t id_349 { n_ref_167[id_348] };
              uint8_t id_350 { 0 };
              uint32_t id_351 { lebsz_ref_168[id_350] };
              uint8_t id_352 { 7 };
              uint32_t id_353 { uint32_t(id_351 << id_352) };
              bool id_354 { bool(id_349 >= id_353) };
              while_flag_347 = id_354;
              if (while_flag_347) {
                uint8_t id_355 { 0 };
                uint8_t id_356 { 0 };
                uint32_t id_357 { lebsz_ref_168[id_356] };
                uint32_t id_358 { 1U };
                uint32_t id_359 { uint32_t(id_357 + id_358) };
                Void id_360 { ((void)(lebsz_ref_168[id_355] = id_359), ::dessser::Void()) };
                (void)id_360;
              }
            } while (while_flag_347);
            (void)::dessser::Void();
            uint8_t id_361 { 0 };
            uint32_t id_362 { lebsz_ref_168[id_361] };
            Size id_363 { Size(id_362) };
            let_res_346 = id_363;
          }
          let_res_343 = let_res_346;
        }
        ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_364 { std::get<0 /* SendSessionKey */>(p_0) };
        Bytes id_365 { id_364.message };
        Size id_366 { id_365.length() };
        Size id_367 { Size(let_res_343 + id_366) };
        Size id_368 { Size(sz_165 + id_367) };
        let_res_337 = id_368;
      }
      choose_res_272 = let_res_337;
    } else {
      uint16_t id_369 { 1 };
      uint16_t id_370 { uint16_t(p_0.index()) };
      bool id_371 { bool(id_369 == id_370) };
      Size choose_res_372;
      if (id_371) {
        Size id_373 { 2UL };
        Bytes id_374 { std::get<1 /* Crypted */>(p_0) };
        Size id_375 { id_374.length() };
        uint32_t id_376 { uint32_t(id_375) };
        Vec<1, uint32_t> id_377 {  id_376  };
        Size let_res_378;
        {
          Vec<1, uint32_t> n_ref_155 { id_377 };
          uint32_t id_379 { 1U };
          Vec<1, uint32_t> id_380 {  id_379  };
          Size let_res_381;
          {
            Vec<1, uint32_t> lebsz_ref_156 { id_380 };
            bool while_flag_382 { true };
            do {
              uint8_t id_383 { 0 };
              uint32_t id_384 { n_ref_155[id_383] };
              uint8_t id_385 { 0 };
              uint32_t id_386 { lebsz_ref_156[id_385] };
              uint8_t id_387 { 7 };
              uint32_t id_388 { uint32_t(id_386 << id_387) };
              bool id_389 { bool(id_384 >= id_388) };
              while_flag_382 = id_389;
              if (while_flag_382) {
                uint8_t id_390 { 0 };
                uint8_t id_391 { 0 };
                uint32_t id_392 { lebsz_ref_156[id_391] };
                uint32_t id_393 { 1U };
                uint32_t id_394 { uint32_t(id_392 + id_393) };
                Void id_395 { ((void)(lebsz_ref_156[id_390] = id_394), ::dessser::Void()) };
                (void)id_395;
              }
            } while (while_flag_382);
            (void)::dessser::Void();
            uint8_t id_396 { 0 };
            uint32_t id_397 { lebsz_ref_156[id_396] };
            Size id_398 { Size(id_397) };
            let_res_381 = id_398;
          }
          let_res_378 = let_res_381;
        }
        Bytes id_399 { std::get<1 /* Crypted */>(p_0) };
        Size id_400 { id_399.length() };
        Size id_401 { Size(let_res_378 + id_400) };
        Size id_402 { Size(id_373 + id_401) };
        choose_res_372 = id_402;
      } else {
        uint16_t id_403 { 2 };
        uint16_t id_404 { uint16_t(p_0.index()) };
        bool id_405 { bool(id_403 == id_404) };
        Size choose_res_406;
        if (id_405) {
          Size id_407 { 2UL };
          Bytes id_408 { std::get<2 /* ClearText */>(p_0) };
          Size id_409 { id_408.length() };
          uint32_t id_410 { uint32_t(id_409) };
          Vec<1, uint32_t> id_411 {  id_410  };
          Size let_res_412;
          {
            Vec<1, uint32_t> n_ref_152 { id_411 };
            uint32_t id_413 { 1U };
            Vec<1, uint32_t> id_414 {  id_413  };
            Size let_res_415;
            {
              Vec<1, uint32_t> lebsz_ref_153 { id_414 };
              bool while_flag_416 { true };
              do {
                uint8_t id_417 { 0 };
                uint32_t id_418 { n_ref_152[id_417] };
                uint8_t id_419 { 0 };
                uint32_t id_420 { lebsz_ref_153[id_419] };
                uint8_t id_421 { 7 };
                uint32_t id_422 { uint32_t(id_420 << id_421) };
                bool id_423 { bool(id_418 >= id_422) };
                while_flag_416 = id_423;
                if (while_flag_416) {
                  uint8_t id_424 { 0 };
                  uint8_t id_425 { 0 };
                  uint32_t id_426 { lebsz_ref_153[id_425] };
                  uint32_t id_427 { 1U };
                  uint32_t id_428 { uint32_t(id_426 + id_427) };
                  Void id_429 { ((void)(lebsz_ref_153[id_424] = id_428), ::dessser::Void()) };
                  (void)id_429;
                }
              } while (while_flag_416);
              (void)::dessser::Void();
              uint8_t id_430 { 0 };
              uint32_t id_431 { lebsz_ref_153[id_430] };
              Size id_432 { Size(id_431) };
              let_res_415 = id_432;
            }
            let_res_412 = let_res_415;
          }
          Bytes id_433 { std::get<2 /* ClearText */>(p_0) };
          Size id_434 { id_433.length() };
          Size id_435 { Size(let_res_412 + id_434) };
          Size id_436 { Size(id_407 + id_435) };
          choose_res_406 = id_436;
        } else {
          uint16_t id_437 { uint16_t(p_0.index()) };
          uint16_t id_438 { 3 };
          bool id_439 { bool(id_437 == id_438) };
          Void id_440 { ((void)(assert(id_439)), ::dessser::Void()) };
          (void)id_440;
          Size id_441 { 2UL };
          std::string id_442 { std::get<3 /* Error */>(p_0) };
          uint32_t id_443 { (uint32_t)id_442.size() };
          Vec<1, uint32_t> id_444 {  id_443  };
          Size let_res_445;
          {
            Vec<1, uint32_t> n_ref_149 { id_444 };
            uint32_t id_446 { 1U };
            Vec<1, uint32_t> id_447 {  id_446  };
            Size let_res_448;
            {
              Vec<1, uint32_t> lebsz_ref_150 { id_447 };
              bool while_flag_449 { true };
              do {
                uint8_t id_450 { 0 };
                uint32_t id_451 { n_ref_149[id_450] };
                uint8_t id_452 { 0 };
                uint32_t id_453 { lebsz_ref_150[id_452] };
                uint8_t id_454 { 7 };
                uint32_t id_455 { uint32_t(id_453 << id_454) };
                bool id_456 { bool(id_451 >= id_455) };
                while_flag_449 = id_456;
                if (while_flag_449) {
                  uint8_t id_457 { 0 };
                  uint8_t id_458 { 0 };
                  uint32_t id_459 { lebsz_ref_150[id_458] };
                  uint32_t id_460 { 1U };
                  uint32_t id_461 { uint32_t(id_459 + id_460) };
                  Void id_462 { ((void)(lebsz_ref_150[id_457] = id_461), ::dessser::Void()) };
                  (void)id_462;
                }
              } while (while_flag_449);
              (void)::dessser::Void();
              uint8_t id_463 { 0 };
              uint32_t id_464 { lebsz_ref_150[id_463] };
              Size id_465 { Size(id_464) };
              let_res_448 = id_465;
            }
            let_res_445 = let_res_448;
          }
          std::string id_466 { std::get<3 /* Error */>(p_0) };
          uint32_t id_467 { (uint32_t)id_466.size() };
          Size id_468 { Size(id_467) };
          Size id_469 { Size(let_res_445 + id_468) };
          Size id_470 { Size(id_441 + id_469) };
          choose_res_406 = id_470;
        }
        choose_res_372 = choose_res_406;
      }
      choose_res_272 = choose_res_372;
    }
    return choose_res_272;
  }
   };
  return fun268;
}
std::function<Size(::dessser::gen::sync_msg::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (let "drec_114"
              (let "dbytes1_111"
                (let "leb_ref_105" (make-vec (u32 0))
                  (let "shft_ref_106" (make-vec (u8 0))
                    (let "p_ref_107" (make-vec (identifier "dsum1_snd_65"))
                      (seq
                        (while
                          (let "leb128_108" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_107")))
                            (let-pair "leb128_fst_109" "leb128_snd_110" 
                              (identifier "leb128_108")
                              (seq (set-vec (u8 0) (identifier "p_ref_107") (identifier "leb128_snd_110"))
                                (set-vec (u8 0) (identifier "leb_ref_105")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_109") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_106"))) (unsafe-nth (u8 0) (identifier "leb_ref_105"))))
                                (set-vec (u8 0) (identifier "shft_ref_106") (add (unsafe-nth (u8 0) (identifier "shft_ref_106")) (u8 7))) 
                                (ge (identifier "leb128_fst_109") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_105"))) (unsafe-nth (u8 0) (identifier "p_ref_107")))))))
                (let-pair "dbytes1_fst_112" "dbytes1_snd_113" (identifier "dbytes1_111") (read-bytes (identifier "dbytes1_snd_113") (identifier "dbytes1_fst_112"))))
              (let-pair "drec_fst_115" "drec_snd_116" (identifier "drec_114")
                (let "drec_126"
                  (let "dbytes1_123"
                    (let "leb_ref_117" (make-vec (u32 0))
                      (let "shft_ref_118" (make-vec (u8 0))
                        (let "p_ref_119" (make-vec (identifier "drec_snd_116"))
                          (seq
                            (while
                              (let "leb128_120" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_119")))
                                (let-pair "leb128_fst_121" "leb128_snd_122" 
                                  (identifier "leb128_120")
                                  (seq (set-vec (u8 0) (identifier "p_ref_119") (identifier "leb128_snd_122"))
                                    (set-vec (u8 0) (identifier "leb_ref_117")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_121") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_118"))) (unsafe-nth (u8 0) (identifier "leb_ref_117"))))
                                    (set-vec (u8 0) (identifier "shft_ref_118") (add (unsafe-nth (u8 0) (identifier "shft_ref_118")) (u8 7))) 
                                    (ge (identifier "leb128_fst_121") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_117"))) (unsafe-nth (u8 0) (identifier "p_ref_119")))))))
                    (let-pair "dbytes1_fst_124" "dbytes1_snd_125" (identifier "dbytes1_123") (read-bytes (identifier "dbytes1_snd_125") (identifier "dbytes1_fst_124"))))
                  (let-pair "drec_fst_127" "drec_snd_128" (identifier "drec_126")
                    (let-pair "drec_fst_139" "drec_snd_140"
                      (let "dbytes1_135"
                        (let "leb_ref_129" (make-vec (u32 0))
                          (let "shft_ref_130" (make-vec (u8 0))
                            (let "p_ref_131" (make-vec (identifier "drec_snd_128"))
                              (seq
                                (while
                                  (let "leb128_132" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_131")))
                                    (let-pair "leb128_fst_133" "leb128_snd_134" 
                                      (identifier "leb128_132")
                                      (seq (set-vec (u8 0) (identifier "p_ref_131") (identifier "leb128_snd_134"))
                                        (set-vec (u8 0) (identifier "leb_ref_129")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_133") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_130"))) (unsafe-nth (u8 0) (identifier "leb_ref_129"))))
                                        (set-vec (u8 0) (identifier "shft_ref_130") (add (unsafe-nth (u8 0) (identifier "shft_ref_130")) (u8 7))) 
                                        (ge (identifier "leb128_fst_133") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_129"))) (unsafe-nth (u8 0) (identifier "p_ref_131")))))))
                        (let-pair "dbytes1_fst_136" "dbytes1_snd_137" (identifier "dbytes1_135") (read-bytes (identifier "dbytes1_snd_137") (identifier "dbytes1_fst_136"))))
                      (make-tup
                        (construct "[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted Bytes | ClearText Bytes | Error STRING]" 0
                          (make-rec (string "message") (identifier "drec_fst_139") (string "public_key") (identifier "drec_fst_127") (string "nonce") (identifier "drec_fst_115"))) 
                        (identifier "drec_snd_140")))))))
            (if (eq (u16 1) (identifier "dsum1_fst_64"))
              (let-pair "dsum2_fst_103" "dsum2_snd_104"
                (let "dbytes1_99"
                  (let "leb_ref_93" (make-vec (u32 0))
                    (let "shft_ref_94" (make-vec (u8 0))
                      (let "p_ref_95" (make-vec (identifier "dsum1_snd_65"))
                        (seq
                          (while
                            (let "leb128_96" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_95")))
                              (let-pair "leb128_fst_97" "leb128_snd_98" 
                                (identifier "leb128_96")
                                (seq (set-vec (u8 0) (identifier "p_ref_95") (identifier "leb128_snd_98"))
                                  (set-vec (u8 0) (identifier "leb_ref_93")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_97") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_94"))) (unsafe-nth (u8 0) (identifier "leb_ref_93"))))
                                  (set-vec (u8 0) (identifier "shft_ref_94") (add (unsafe-nth (u8 0) (identifier "shft_ref_94")) (u8 7))) 
                                  (ge (identifier "leb128_fst_97") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_93"))) (unsafe-nth (u8 0) (identifier "p_ref_95")))))))
                  (let-pair "dbytes1_fst_100" "dbytes1_snd_101" (identifier "dbytes1_99") (read-bytes (identifier "dbytes1_snd_101") (identifier "dbytes1_fst_100"))))
                (make-tup (construct "[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted Bytes | ClearText Bytes | Error STRING]" 1 (identifier "dsum2_fst_103")) (identifier "dsum2_snd_104")))
              (if (eq (u16 2) (identifier "dsum1_fst_64"))
                (let-pair "dsum2_fst_91" "dsum2_snd_92"
                  (let "dbytes1_87"
                    (let "leb_ref_81" (make-vec (u32 0))
                      (let "shft_ref_82" (make-vec (u8 0))
                        (let "p_ref_83" (make-vec (identifier "dsum1_snd_65"))
                          (seq
                            (while
                              (let "leb128_84" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_83")))
                                (let-pair "leb128_fst_85" "leb128_snd_86" 
                                  (identifier "leb128_84")
                                  (seq (set-vec (u8 0) (identifier "p_ref_83") (identifier "leb128_snd_86"))
                                    (set-vec (u8 0) (identifier "leb_ref_81")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_85") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_82"))) (unsafe-nth (u8 0) (identifier "leb_ref_81"))))
                                    (set-vec (u8 0) (identifier "shft_ref_82") (add (unsafe-nth (u8 0) (identifier "shft_ref_82")) (u8 7))) 
                                    (ge (identifier "leb128_fst_85") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_81"))) (unsafe-nth (u8 0) (identifier "p_ref_83")))))))
                    (let-pair "dbytes1_fst_88" "dbytes1_snd_89" (identifier "dbytes1_87") (read-bytes (identifier "dbytes1_snd_89") (identifier "dbytes1_fst_88"))))
                  (make-tup (construct "[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted Bytes | ClearText Bytes | Error STRING]" 2 (identifier "dsum2_fst_91")) (identifier "dsum2_snd_92")))
                (seq (assert (eq (identifier "dsum1_fst_64") (u16 3)))
                  (let "dstring1_72"
                    (let "leb_ref_66" (make-vec (u32 0))
                      (let "shft_ref_67" (make-vec (u8 0))
                        (let "p_ref_68" (make-vec (identifier "dsum1_snd_65"))
                          (seq
                            (while
                              (let "leb128_69" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_68")))
                                (let-pair "leb128_fst_70" "leb128_snd_71" 
                                  (identifier "leb128_69")
                                  (seq (set-vec (u8 0) (identifier "p_ref_68") (identifier "leb128_snd_71"))
                                    (set-vec (u8 0) (identifier "leb_ref_66")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_70") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_67"))) (unsafe-nth (u8 0) (identifier "leb_ref_66"))))
                                    (set-vec (u8 0) (identifier "shft_ref_67") (add (unsafe-nth (u8 0) (identifier "shft_ref_67")) (u8 7))) 
                                    (ge (identifier "leb128_fst_70") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_66"))) (unsafe-nth (u8 0) (identifier "p_ref_68")))))))
                    (let-pair "dstring1_fst_73" "dstring1_snd_74" (identifier "dstring1_72")
                      (let-pair "dstring2_fst_76" "dstring2_snd_77" (read-bytes (identifier "dstring1_snd_74") (identifier "dstring1_fst_73"))
                        (make-tup (construct "[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted Bytes | ClearText Bytes | Error STRING]" 3 (string-of-bytes (identifier "dstring2_fst_76")))
                          (identifier "dstring2_snd_77"))))))))))))
 */
static std::function<::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e(Pointer &)> fun471 { [&](Pointer p_0) {
    ::dessser::gen::sync_msg::ta97bb48ed75bbda6173555873826c8c6 id_472 { p_0.readU16Le() };
    ::dessser::gen::sync_msg::ta97bb48ed75bbda6173555873826c8c6 letpair_res_473;
    {
      auto du16_fst_58 { std::get<0>(id_472) };
      auto du16_snd_59 { std::get<1>(id_472) };
      ::dessser::gen::sync_msg::ta97bb48ed75bbda6173555873826c8c6 id_474 { du16_fst_58, du16_snd_59 };
      letpair_res_473 = id_474;
    }
    ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e let_res_475;
    {
      ::dessser::gen::sync_msg::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_473 };
      ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e letpair_res_476;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_477 { 0 };
        bool id_478 { bool(id_477 == dsum1_fst_64) };
        ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e choose_res_479;
        if (id_478) {
          uint32_t id_480 { 0U };
          Vec<1, uint32_t> id_481 {  id_480  };
          ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_482;
          {
            Vec<1, uint32_t> leb_ref_105 { id_481 };
            uint8_t id_483 { 0 };
            Vec<1, uint8_t> id_484 {  id_483  };
            ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_485;
            {
              Vec<1, uint8_t> shft_ref_106 { id_484 };
              Vec<1, Pointer> id_486 {  dsum1_snd_65  };
              ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_487;
              {
                Vec<1, Pointer> p_ref_107 { id_486 };
                bool while_flag_488 { true };
                do {
                  uint8_t id_489 { 0 };
                  Pointer id_490 { p_ref_107[id_489] };
                  ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 id_491 { id_490.readU8() };
                  bool let_res_492;
                  {
                    ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_108 { id_491 };
                    bool letpair_res_493;
                    {
                      auto leb128_fst_109 { std::get<0>(leb128_108) };
                      auto leb128_snd_110 { std::get<1>(leb128_108) };
                      uint8_t id_494 { 0 };
                      Void id_495 { ((void)(p_ref_107[id_494] = leb128_snd_110), ::dessser::Void()) };
                      (void)id_495;
                      uint8_t id_496 { 0 };
                      uint8_t id_497 { 127 };
                      uint8_t id_498 { uint8_t(leb128_fst_109 & id_497) };
                      uint32_t id_499 { uint32_t(id_498) };
                      uint8_t id_500 { 0 };
                      uint8_t id_501 { shft_ref_106[id_500] };
                      uint32_t id_502 { uint32_t(id_499 << id_501) };
                      uint8_t id_503 { 0 };
                      uint32_t id_504 { leb_ref_105[id_503] };
                      uint32_t id_505 { uint32_t(id_502 | id_504) };
                      Void id_506 { ((void)(leb_ref_105[id_496] = id_505), ::dessser::Void()) };
                      (void)id_506;
                      uint8_t id_507 { 0 };
                      uint8_t id_508 { 0 };
                      uint8_t id_509 { shft_ref_106[id_508] };
                      uint8_t id_510 { 7 };
                      uint8_t id_511 { uint8_t(id_509 + id_510) };
                      Void id_512 { ((void)(shft_ref_106[id_507] = id_511), ::dessser::Void()) };
                      (void)id_512;
                      uint8_t id_513 { 128 };
                      bool id_514 { bool(leb128_fst_109 >= id_513) };
                      letpair_res_493 = id_514;
                    }
                    let_res_492 = letpair_res_493;
                  }
                  while_flag_488 = let_res_492;
                  if (while_flag_488) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_488);
                (void)::dessser::Void();
                uint8_t id_515 { 0 };
                uint32_t id_516 { leb_ref_105[id_515] };
                Size id_517 { Size(id_516) };
                uint8_t id_518 { 0 };
                Pointer id_519 { p_ref_107[id_518] };
                ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa id_520 { id_517, id_519 };
                let_res_487 = id_520;
              }
              let_res_485 = let_res_487;
            }
            let_res_482 = let_res_485;
          }
          ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb let_res_521;
          {
            ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa dbytes1_111 { let_res_482 };
            ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb letpair_res_522;
            {
              auto dbytes1_fst_112 { std::get<0>(dbytes1_111) };
              auto dbytes1_snd_113 { std::get<1>(dbytes1_111) };
              ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_523 { dbytes1_snd_113.readBytes(dbytes1_fst_112) };
              letpair_res_522 = id_523;
            }
            let_res_521 = letpair_res_522;
          }
          ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e let_res_524;
          {
            ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb drec_114 { let_res_521 };
            ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e letpair_res_525;
            {
              auto drec_fst_115 { std::get<0>(drec_114) };
              auto drec_snd_116 { std::get<1>(drec_114) };
              uint32_t id_526 { 0U };
              Vec<1, uint32_t> id_527 {  id_526  };
              ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_528;
              {
                Vec<1, uint32_t> leb_ref_117 { id_527 };
                uint8_t id_529 { 0 };
                Vec<1, uint8_t> id_530 {  id_529  };
                ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_531;
                {
                  Vec<1, uint8_t> shft_ref_118 { id_530 };
                  Vec<1, Pointer> id_532 {  drec_snd_116  };
                  ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_533;
                  {
                    Vec<1, Pointer> p_ref_119 { id_532 };
                    bool while_flag_534 { true };
                    do {
                      uint8_t id_535 { 0 };
                      Pointer id_536 { p_ref_119[id_535] };
                      ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 id_537 { id_536.readU8() };
                      bool let_res_538;
                      {
                        ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_120 { id_537 };
                        bool letpair_res_539;
                        {
                          auto leb128_fst_121 { std::get<0>(leb128_120) };
                          auto leb128_snd_122 { std::get<1>(leb128_120) };
                          uint8_t id_540 { 0 };
                          Void id_541 { ((void)(p_ref_119[id_540] = leb128_snd_122), ::dessser::Void()) };
                          (void)id_541;
                          uint8_t id_542 { 0 };
                          uint8_t id_543 { 127 };
                          uint8_t id_544 { uint8_t(leb128_fst_121 & id_543) };
                          uint32_t id_545 { uint32_t(id_544) };
                          uint8_t id_546 { 0 };
                          uint8_t id_547 { shft_ref_118[id_546] };
                          uint32_t id_548 { uint32_t(id_545 << id_547) };
                          uint8_t id_549 { 0 };
                          uint32_t id_550 { leb_ref_117[id_549] };
                          uint32_t id_551 { uint32_t(id_548 | id_550) };
                          Void id_552 { ((void)(leb_ref_117[id_542] = id_551), ::dessser::Void()) };
                          (void)id_552;
                          uint8_t id_553 { 0 };
                          uint8_t id_554 { 0 };
                          uint8_t id_555 { shft_ref_118[id_554] };
                          uint8_t id_556 { 7 };
                          uint8_t id_557 { uint8_t(id_555 + id_556) };
                          Void id_558 { ((void)(shft_ref_118[id_553] = id_557), ::dessser::Void()) };
                          (void)id_558;
                          uint8_t id_559 { 128 };
                          bool id_560 { bool(leb128_fst_121 >= id_559) };
                          letpair_res_539 = id_560;
                        }
                        let_res_538 = letpair_res_539;
                      }
                      while_flag_534 = let_res_538;
                      if (while_flag_534) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_534);
                    (void)::dessser::Void();
                    uint8_t id_561 { 0 };
                    uint32_t id_562 { leb_ref_117[id_561] };
                    Size id_563 { Size(id_562) };
                    uint8_t id_564 { 0 };
                    Pointer id_565 { p_ref_119[id_564] };
                    ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa id_566 { id_563, id_565 };
                    let_res_533 = id_566;
                  }
                  let_res_531 = let_res_533;
                }
                let_res_528 = let_res_531;
              }
              ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb let_res_567;
              {
                ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa dbytes1_123 { let_res_528 };
                ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb letpair_res_568;
                {
                  auto dbytes1_fst_124 { std::get<0>(dbytes1_123) };
                  auto dbytes1_snd_125 { std::get<1>(dbytes1_123) };
                  ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_569 { dbytes1_snd_125.readBytes(dbytes1_fst_124) };
                  letpair_res_568 = id_569;
                }
                let_res_567 = letpair_res_568;
              }
              ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e let_res_570;
              {
                ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb drec_126 { let_res_567 };
                ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e letpair_res_571;
                {
                  auto drec_fst_127 { std::get<0>(drec_126) };
                  auto drec_snd_128 { std::get<1>(drec_126) };
                  uint32_t id_572 { 0U };
                  Vec<1, uint32_t> id_573 {  id_572  };
                  ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_574;
                  {
                    Vec<1, uint32_t> leb_ref_129 { id_573 };
                    uint8_t id_575 { 0 };
                    Vec<1, uint8_t> id_576 {  id_575  };
                    ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_577;
                    {
                      Vec<1, uint8_t> shft_ref_130 { id_576 };
                      Vec<1, Pointer> id_578 {  drec_snd_128  };
                      ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_579;
                      {
                        Vec<1, Pointer> p_ref_131 { id_578 };
                        bool while_flag_580 { true };
                        do {
                          uint8_t id_581 { 0 };
                          Pointer id_582 { p_ref_131[id_581] };
                          ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 id_583 { id_582.readU8() };
                          bool let_res_584;
                          {
                            ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_132 { id_583 };
                            bool letpair_res_585;
                            {
                              auto leb128_fst_133 { std::get<0>(leb128_132) };
                              auto leb128_snd_134 { std::get<1>(leb128_132) };
                              uint8_t id_586 { 0 };
                              Void id_587 { ((void)(p_ref_131[id_586] = leb128_snd_134), ::dessser::Void()) };
                              (void)id_587;
                              uint8_t id_588 { 0 };
                              uint8_t id_589 { 127 };
                              uint8_t id_590 { uint8_t(leb128_fst_133 & id_589) };
                              uint32_t id_591 { uint32_t(id_590) };
                              uint8_t id_592 { 0 };
                              uint8_t id_593 { shft_ref_130[id_592] };
                              uint32_t id_594 { uint32_t(id_591 << id_593) };
                              uint8_t id_595 { 0 };
                              uint32_t id_596 { leb_ref_129[id_595] };
                              uint32_t id_597 { uint32_t(id_594 | id_596) };
                              Void id_598 { ((void)(leb_ref_129[id_588] = id_597), ::dessser::Void()) };
                              (void)id_598;
                              uint8_t id_599 { 0 };
                              uint8_t id_600 { 0 };
                              uint8_t id_601 { shft_ref_130[id_600] };
                              uint8_t id_602 { 7 };
                              uint8_t id_603 { uint8_t(id_601 + id_602) };
                              Void id_604 { ((void)(shft_ref_130[id_599] = id_603), ::dessser::Void()) };
                              (void)id_604;
                              uint8_t id_605 { 128 };
                              bool id_606 { bool(leb128_fst_133 >= id_605) };
                              letpair_res_585 = id_606;
                            }
                            let_res_584 = letpair_res_585;
                          }
                          while_flag_580 = let_res_584;
                          if (while_flag_580) {
                            (void)::dessser::Void();
                          }
                        } while (while_flag_580);
                        (void)::dessser::Void();
                        uint8_t id_607 { 0 };
                        uint32_t id_608 { leb_ref_129[id_607] };
                        Size id_609 { Size(id_608) };
                        uint8_t id_610 { 0 };
                        Pointer id_611 { p_ref_131[id_610] };
                        ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa id_612 { id_609, id_611 };
                        let_res_579 = id_612;
                      }
                      let_res_577 = let_res_579;
                    }
                    let_res_574 = let_res_577;
                  }
                  ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb let_res_613;
                  {
                    ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa dbytes1_135 { let_res_574 };
                    ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb letpair_res_614;
                    {
                      auto dbytes1_fst_136 { std::get<0>(dbytes1_135) };
                      auto dbytes1_snd_137 { std::get<1>(dbytes1_135) };
                      ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_615 { dbytes1_snd_137.readBytes(dbytes1_fst_136) };
                      letpair_res_614 = id_615;
                    }
                    let_res_613 = letpair_res_614;
                  }
                  ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e letpair_res_616;
                  {
                    auto drec_fst_139 { std::get<0>(let_res_613) };
                    auto drec_snd_140 { std::get<1>(let_res_613) };
                    ::dessser::gen::sync_msg::t206fd5d881820fd19331922d3e213def id_617 { drec_fst_115, drec_fst_127, drec_fst_139 };
                    ::dessser::gen::sync_msg::t id_618 { std::in_place_index<0>, id_617 };
                    ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e id_619 { id_618, drec_snd_140 };
                    letpair_res_616 = id_619;
                  }
                  letpair_res_571 = letpair_res_616;
                }
                let_res_570 = letpair_res_571;
              }
              letpair_res_525 = let_res_570;
            }
            let_res_524 = letpair_res_525;
          }
          choose_res_479 = let_res_524;
        } else {
          uint16_t id_620 { 1 };
          bool id_621 { bool(id_620 == dsum1_fst_64) };
          ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e choose_res_622;
          if (id_621) {
            uint32_t id_623 { 0U };
            Vec<1, uint32_t> id_624 {  id_623  };
            ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_625;
            {
              Vec<1, uint32_t> leb_ref_93 { id_624 };
              uint8_t id_626 { 0 };
              Vec<1, uint8_t> id_627 {  id_626  };
              ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_628;
              {
                Vec<1, uint8_t> shft_ref_94 { id_627 };
                Vec<1, Pointer> id_629 {  dsum1_snd_65  };
                ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_630;
                {
                  Vec<1, Pointer> p_ref_95 { id_629 };
                  bool while_flag_631 { true };
                  do {
                    uint8_t id_632 { 0 };
                    Pointer id_633 { p_ref_95[id_632] };
                    ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 id_634 { id_633.readU8() };
                    bool let_res_635;
                    {
                      ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_96 { id_634 };
                      bool letpair_res_636;
                      {
                        auto leb128_fst_97 { std::get<0>(leb128_96) };
                        auto leb128_snd_98 { std::get<1>(leb128_96) };
                        uint8_t id_637 { 0 };
                        Void id_638 { ((void)(p_ref_95[id_637] = leb128_snd_98), ::dessser::Void()) };
                        (void)id_638;
                        uint8_t id_639 { 0 };
                        uint8_t id_640 { 127 };
                        uint8_t id_641 { uint8_t(leb128_fst_97 & id_640) };
                        uint32_t id_642 { uint32_t(id_641) };
                        uint8_t id_643 { 0 };
                        uint8_t id_644 { shft_ref_94[id_643] };
                        uint32_t id_645 { uint32_t(id_642 << id_644) };
                        uint8_t id_646 { 0 };
                        uint32_t id_647 { leb_ref_93[id_646] };
                        uint32_t id_648 { uint32_t(id_645 | id_647) };
                        Void id_649 { ((void)(leb_ref_93[id_639] = id_648), ::dessser::Void()) };
                        (void)id_649;
                        uint8_t id_650 { 0 };
                        uint8_t id_651 { 0 };
                        uint8_t id_652 { shft_ref_94[id_651] };
                        uint8_t id_653 { 7 };
                        uint8_t id_654 { uint8_t(id_652 + id_653) };
                        Void id_655 { ((void)(shft_ref_94[id_650] = id_654), ::dessser::Void()) };
                        (void)id_655;
                        uint8_t id_656 { 128 };
                        bool id_657 { bool(leb128_fst_97 >= id_656) };
                        letpair_res_636 = id_657;
                      }
                      let_res_635 = letpair_res_636;
                    }
                    while_flag_631 = let_res_635;
                    if (while_flag_631) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_631);
                  (void)::dessser::Void();
                  uint8_t id_658 { 0 };
                  uint32_t id_659 { leb_ref_93[id_658] };
                  Size id_660 { Size(id_659) };
                  uint8_t id_661 { 0 };
                  Pointer id_662 { p_ref_95[id_661] };
                  ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa id_663 { id_660, id_662 };
                  let_res_630 = id_663;
                }
                let_res_628 = let_res_630;
              }
              let_res_625 = let_res_628;
            }
            ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb let_res_664;
            {
              ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa dbytes1_99 { let_res_625 };
              ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb letpair_res_665;
              {
                auto dbytes1_fst_100 { std::get<0>(dbytes1_99) };
                auto dbytes1_snd_101 { std::get<1>(dbytes1_99) };
                ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_666 { dbytes1_snd_101.readBytes(dbytes1_fst_100) };
                letpair_res_665 = id_666;
              }
              let_res_664 = letpair_res_665;
            }
            ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e letpair_res_667;
            {
              auto dsum2_fst_103 { std::get<0>(let_res_664) };
              auto dsum2_snd_104 { std::get<1>(let_res_664) };
              ::dessser::gen::sync_msg::t id_668 { std::in_place_index<1>, dsum2_fst_103 };
              ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e id_669 { id_668, dsum2_snd_104 };
              letpair_res_667 = id_669;
            }
            choose_res_622 = letpair_res_667;
          } else {
            uint16_t id_670 { 2 };
            bool id_671 { bool(id_670 == dsum1_fst_64) };
            ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e choose_res_672;
            if (id_671) {
              uint32_t id_673 { 0U };
              Vec<1, uint32_t> id_674 {  id_673  };
              ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_675;
              {
                Vec<1, uint32_t> leb_ref_81 { id_674 };
                uint8_t id_676 { 0 };
                Vec<1, uint8_t> id_677 {  id_676  };
                ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_678;
                {
                  Vec<1, uint8_t> shft_ref_82 { id_677 };
                  Vec<1, Pointer> id_679 {  dsum1_snd_65  };
                  ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_680;
                  {
                    Vec<1, Pointer> p_ref_83 { id_679 };
                    bool while_flag_681 { true };
                    do {
                      uint8_t id_682 { 0 };
                      Pointer id_683 { p_ref_83[id_682] };
                      ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 id_684 { id_683.readU8() };
                      bool let_res_685;
                      {
                        ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_84 { id_684 };
                        bool letpair_res_686;
                        {
                          auto leb128_fst_85 { std::get<0>(leb128_84) };
                          auto leb128_snd_86 { std::get<1>(leb128_84) };
                          uint8_t id_687 { 0 };
                          Void id_688 { ((void)(p_ref_83[id_687] = leb128_snd_86), ::dessser::Void()) };
                          (void)id_688;
                          uint8_t id_689 { 0 };
                          uint8_t id_690 { 127 };
                          uint8_t id_691 { uint8_t(leb128_fst_85 & id_690) };
                          uint32_t id_692 { uint32_t(id_691) };
                          uint8_t id_693 { 0 };
                          uint8_t id_694 { shft_ref_82[id_693] };
                          uint32_t id_695 { uint32_t(id_692 << id_694) };
                          uint8_t id_696 { 0 };
                          uint32_t id_697 { leb_ref_81[id_696] };
                          uint32_t id_698 { uint32_t(id_695 | id_697) };
                          Void id_699 { ((void)(leb_ref_81[id_689] = id_698), ::dessser::Void()) };
                          (void)id_699;
                          uint8_t id_700 { 0 };
                          uint8_t id_701 { 0 };
                          uint8_t id_702 { shft_ref_82[id_701] };
                          uint8_t id_703 { 7 };
                          uint8_t id_704 { uint8_t(id_702 + id_703) };
                          Void id_705 { ((void)(shft_ref_82[id_700] = id_704), ::dessser::Void()) };
                          (void)id_705;
                          uint8_t id_706 { 128 };
                          bool id_707 { bool(leb128_fst_85 >= id_706) };
                          letpair_res_686 = id_707;
                        }
                        let_res_685 = letpair_res_686;
                      }
                      while_flag_681 = let_res_685;
                      if (while_flag_681) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_681);
                    (void)::dessser::Void();
                    uint8_t id_708 { 0 };
                    uint32_t id_709 { leb_ref_81[id_708] };
                    Size id_710 { Size(id_709) };
                    uint8_t id_711 { 0 };
                    Pointer id_712 { p_ref_83[id_711] };
                    ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa id_713 { id_710, id_712 };
                    let_res_680 = id_713;
                  }
                  let_res_678 = let_res_680;
                }
                let_res_675 = let_res_678;
              }
              ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb let_res_714;
              {
                ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa dbytes1_87 { let_res_675 };
                ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb letpair_res_715;
                {
                  auto dbytes1_fst_88 { std::get<0>(dbytes1_87) };
                  auto dbytes1_snd_89 { std::get<1>(dbytes1_87) };
                  ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_716 { dbytes1_snd_89.readBytes(dbytes1_fst_88) };
                  letpair_res_715 = id_716;
                }
                let_res_714 = letpair_res_715;
              }
              ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e letpair_res_717;
              {
                auto dsum2_fst_91 { std::get<0>(let_res_714) };
                auto dsum2_snd_92 { std::get<1>(let_res_714) };
                ::dessser::gen::sync_msg::t id_718 { std::in_place_index<2>, dsum2_fst_91 };
                ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e id_719 { id_718, dsum2_snd_92 };
                letpair_res_717 = id_719;
              }
              choose_res_672 = letpair_res_717;
            } else {
              uint16_t id_720 { 3 };
              bool id_721 { bool(dsum1_fst_64 == id_720) };
              Void id_722 { ((void)(assert(id_721)), ::dessser::Void()) };
              (void)id_722;
              uint32_t id_723 { 0U };
              Vec<1, uint32_t> id_724 {  id_723  };
              ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_725;
              {
                Vec<1, uint32_t> leb_ref_66 { id_724 };
                uint8_t id_726 { 0 };
                Vec<1, uint8_t> id_727 {  id_726  };
                ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_728;
                {
                  Vec<1, uint8_t> shft_ref_67 { id_727 };
                  Vec<1, Pointer> id_729 {  dsum1_snd_65  };
                  ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_730;
                  {
                    Vec<1, Pointer> p_ref_68 { id_729 };
                    bool while_flag_731 { true };
                    do {
                      uint8_t id_732 { 0 };
                      Pointer id_733 { p_ref_68[id_732] };
                      ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 id_734 { id_733.readU8() };
                      bool let_res_735;
                      {
                        ::dessser::gen::sync_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_69 { id_734 };
                        bool letpair_res_736;
                        {
                          auto leb128_fst_70 { std::get<0>(leb128_69) };
                          auto leb128_snd_71 { std::get<1>(leb128_69) };
                          uint8_t id_737 { 0 };
                          Void id_738 { ((void)(p_ref_68[id_737] = leb128_snd_71), ::dessser::Void()) };
                          (void)id_738;
                          uint8_t id_739 { 0 };
                          uint8_t id_740 { 127 };
                          uint8_t id_741 { uint8_t(leb128_fst_70 & id_740) };
                          uint32_t id_742 { uint32_t(id_741) };
                          uint8_t id_743 { 0 };
                          uint8_t id_744 { shft_ref_67[id_743] };
                          uint32_t id_745 { uint32_t(id_742 << id_744) };
                          uint8_t id_746 { 0 };
                          uint32_t id_747 { leb_ref_66[id_746] };
                          uint32_t id_748 { uint32_t(id_745 | id_747) };
                          Void id_749 { ((void)(leb_ref_66[id_739] = id_748), ::dessser::Void()) };
                          (void)id_749;
                          uint8_t id_750 { 0 };
                          uint8_t id_751 { 0 };
                          uint8_t id_752 { shft_ref_67[id_751] };
                          uint8_t id_753 { 7 };
                          uint8_t id_754 { uint8_t(id_752 + id_753) };
                          Void id_755 { ((void)(shft_ref_67[id_750] = id_754), ::dessser::Void()) };
                          (void)id_755;
                          uint8_t id_756 { 128 };
                          bool id_757 { bool(leb128_fst_70 >= id_756) };
                          letpair_res_736 = id_757;
                        }
                        let_res_735 = letpair_res_736;
                      }
                      while_flag_731 = let_res_735;
                      if (while_flag_731) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_731);
                    (void)::dessser::Void();
                    uint8_t id_758 { 0 };
                    uint32_t id_759 { leb_ref_66[id_758] };
                    Size id_760 { Size(id_759) };
                    uint8_t id_761 { 0 };
                    Pointer id_762 { p_ref_68[id_761] };
                    ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa id_763 { id_760, id_762 };
                    let_res_730 = id_763;
                  }
                  let_res_728 = let_res_730;
                }
                let_res_725 = let_res_728;
              }
              ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e let_res_764;
              {
                ::dessser::gen::sync_msg::t12fb9c475959b52bf7b17b155a955ffa dstring1_72 { let_res_725 };
                ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e letpair_res_765;
                {
                  auto dstring1_fst_73 { std::get<0>(dstring1_72) };
                  auto dstring1_snd_74 { std::get<1>(dstring1_72) };
                  ::dessser::gen::sync_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_766 { dstring1_snd_74.readBytes(dstring1_fst_73) };
                  ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e letpair_res_767;
                  {
                    auto dstring2_fst_76 { std::get<0>(id_766) };
                    auto dstring2_snd_77 { std::get<1>(id_766) };
                    std::string id_768 { dstring2_fst_76.toString() };
                    ::dessser::gen::sync_msg::t id_769 { std::in_place_index<3>, id_768 };
                    ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e id_770 { id_769, dstring2_snd_77 };
                    letpair_res_767 = id_770;
                  }
                  letpair_res_765 = letpair_res_767;
                }
                let_res_764 = letpair_res_765;
              }
              choose_res_672 = let_res_764;
            }
            choose_res_622 = choose_res_672;
          }
          choose_res_479 = choose_res_622;
        }
        letpair_res_476 = choose_res_479;
      }
      let_res_475 = letpair_res_476;
    }
    return let_res_475;
  }
   };
  return fun471;
}
std::function<::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_145" "make_snd_146" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_145") (identifier "make_snd_146"))))
 */
static std::function<::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e(Pointer &)> fun771 { [&](Pointer p_0) {
    ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e id_772 { of_row_binary(p_0) };
    ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e letpair_res_773;
    {
      auto make_fst_145 { std::get<0>(id_772) };
      auto make_snd_146 { std::get<1>(id_772) };
      ::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e id_774 { make_fst_145, make_snd_146 };
      letpair_res_773 = id_774;
    }
    return letpair_res_773;
  }
   };
  return fun771;
}
std::function<::dessser::gen::sync_msg::tc374fe7e38202b30396ee364cbb6d53e(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted Bytes | ClearText Bytes | Error STRING]" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::sync_msg::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_msg::t &,Pointer &)> fun775 { [&](::dessser::gen::sync_msg::t p_0, Pointer p_1) {
    Pointer id_776 { to_row_binary(p_0, p_1) };
    return id_776;
  }
   };
  return fun775;
}
std::function<Pointer(::dessser::gen::sync_msg::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
