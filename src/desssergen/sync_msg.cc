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
struct tdb9685b762777dddeea8bb04805eb8cf {
  Bytes SendSessionKey_message;
  Bytes SendSessionKey_nonce;
  Bytes public_key;
  bool operator==(tdb9685b762777dddeea8bb04805eb8cf const &other) const {
    return SendSessionKey_message == other.SendSessionKey_message && SendSessionKey_nonce == other.SendSessionKey_nonce && public_key == other.public_key;
  }
};
struct t10b7d87ea3b6637868bb9b5cc57e7b11 {
  Bytes message;
  Bytes nonce;
  bool operator==(t10b7d87ea3b6637868bb9b5cc57e7b11 const &other) const {
    return message == other.message && nonce == other.nonce;
  }
};
struct t : public std::variant<
  ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf, // SendSessionKey
  ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11, // Crypted
  Bytes, // ClearText
  std::string // Error
> { using variant::variant; };

typedef std::tuple<
  ::dessser::gen::sync_msg::t*,
  Pointer
> t225ef9f1e97f4882d6b6a9f870881a23;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted {nonce: Bytes; message: Bytes} | ClearText Bytes | Error STRING]" "Ptr")
      (let "ssum_dst_189" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_204"
            (let "srec_dst_201"
              (write-bytes
                (let "leb128_sz_199" (make-vec (u32-of-size (bytes-length (get-field "nonce" (get-alt "SendSessionKey" (param 0))))))
                  (let "leb128_ptr_200" (make-vec (identifier "ssum_dst_189"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_200")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_200"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_199"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_199"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_199"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_199") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_199")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_199")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_200"))))) 
                (get-field "nonce" (get-alt "SendSessionKey" (param 0))))
              (write-bytes
                (let "leb128_sz_202" (make-vec (u32-of-size (bytes-length (get-field "public_key" (get-alt "SendSessionKey" (param 0))))))
                  (let "leb128_ptr_203" (make-vec (identifier "srec_dst_201"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_203")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_203"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_202"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_202"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_202"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_202") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_202")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_202")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_203"))))) 
                (get-field "public_key" (get-alt "SendSessionKey" (param 0)))))
            (write-bytes
              (let "leb128_sz_205" (make-vec (u32-of-size (bytes-length (get-field "message" (get-alt "SendSessionKey" (param 0))))))
                (let "leb128_ptr_206" (make-vec (identifier "srec_dst_204"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_206")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_206"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_205"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_205"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_205"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_205") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_205")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_205")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_206"))))) 
              (get-field "message" (get-alt "SendSessionKey" (param 0)))))
          (if (eq (u16 1) (label-of (param 0)))
            (let "srec_dst_196"
              (write-bytes
                (let "leb128_sz_194" (make-vec (u32-of-size (bytes-length (get-field "nonce" (get-alt "Crypted" (param 0))))))
                  (let "leb128_ptr_195" (make-vec (identifier "ssum_dst_189"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_195")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_195"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_194"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_194"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_194"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_194") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_194")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_194")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_195"))))) 
                (get-field "nonce" (get-alt "Crypted" (param 0))))
              (write-bytes
                (let "leb128_sz_197" (make-vec (u32-of-size (bytes-length (get-field "message" (get-alt "Crypted" (param 0))))))
                  (let "leb128_ptr_198" (make-vec (identifier "srec_dst_196"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_198")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_198"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_197"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_197"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_197"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_197") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_197")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_197")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_198"))))) 
                (get-field "message" (get-alt "Crypted" (param 0)))))
            (if (eq (u16 2) (label-of (param 0)))
              (write-bytes
                (let "leb128_sz_192" (make-vec (u32-of-size (bytes-length (get-alt "ClearText" (param 0)))))
                  (let "leb128_ptr_193" (make-vec (identifier "ssum_dst_189"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_193")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_193"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_192"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_192"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_192"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_192") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_192")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_192")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_193"))))) 
                (get-alt "ClearText" (param 0)))
              (seq (assert (eq (label-of (param 0)) (u16 3)))
                (write-bytes
                  (let "leb128_sz_190" (make-vec (string-length (get-alt "Error" (param 0))))
                    (let "leb128_ptr_191" (make-vec (identifier "ssum_dst_189"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_191")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_191"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_190"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_190"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_190"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_190") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_190")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_190")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_191"))))) 
                  (bytes-of-string (get-alt "Error" (param 0))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_msg::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_msg::t*,Pointer)> fun0 { [&fun0](::dessser::gen::sync_msg::t* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0->index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_189 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0->index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_8 { std::get<0 /* SendSessionKey */>(*p_0) };
        Bytes id_9 { id_8.SendSessionKey_nonce };
        Size id_10 { id_9.length() };
        uint32_t id_11 { uint32_t(id_10) };
        Vec<1, uint32_t> id_12 {  id_11  };
        Pointer let_res_13;
        {
          Vec<1, uint32_t> leb128_sz_199 { id_12 };
          Vec<1, Pointer> id_14 {  ssum_dst_189  };
          Pointer let_res_15;
          {
            Vec<1, Pointer> leb128_ptr_200 { id_14 };
            bool while_flag_16 { true };
            do {
              uint8_t id_17 { 0 };
              uint8_t id_18 { 0 };
              Pointer id_19 { leb128_ptr_200[id_18] };
              uint32_t id_20 { 128U };
              uint8_t id_21 { 0 };
              uint32_t id_22 { leb128_sz_199[id_21] };
              bool id_23 { bool(id_20 > id_22) };
              uint8_t choose_res_24;
              if (id_23) {
                uint8_t id_25 { 0 };
                uint32_t id_26 { leb128_sz_199[id_25] };
                uint8_t id_27 { uint8_t(id_26) };
                choose_res_24 = id_27;
              } else {
                uint8_t id_28 { 0 };
                uint32_t id_29 { leb128_sz_199[id_28] };
                uint8_t id_30 { uint8_t(id_29) };
                uint8_t id_31 { 128 };
                uint8_t id_32 { uint8_t(id_30 | id_31) };
                choose_res_24 = id_32;
              }
              Pointer id_33 { id_19.writeU8(choose_res_24) };
              Void id_34 { ((void)(leb128_ptr_200[id_17] = id_33), VOID) };
              (void)id_34;
              uint8_t id_35 { 0 };
              uint8_t id_36 { 0 };
              uint32_t id_37 { leb128_sz_199[id_36] };
              uint8_t id_38 { 7 };
              uint32_t id_39 { uint32_t(id_37 >> id_38) };
              Void id_40 { ((void)(leb128_sz_199[id_35] = id_39), VOID) };
              (void)id_40;
              uint8_t id_41 { 0 };
              uint32_t id_42 { leb128_sz_199[id_41] };
              uint32_t id_43 { 0U };
              bool id_44 { bool(id_42 > id_43) };
              while_flag_16 = id_44;
              if (while_flag_16) {
                (void)VOID;
              }
            } while (while_flag_16);
            (void)VOID;
            uint8_t id_45 { 0 };
            Pointer id_46 { leb128_ptr_200[id_45] };
            let_res_15 = id_46;
          }
          let_res_13 = let_res_15;
        }
        ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_47 { std::get<0 /* SendSessionKey */>(*p_0) };
        Bytes id_48 { id_47.SendSessionKey_nonce };
        Pointer id_49 { let_res_13.writeBytes(id_48) };
        Pointer let_res_50;
        {
          Pointer srec_dst_201 { id_49 };
          ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_51 { std::get<0 /* SendSessionKey */>(*p_0) };
          Bytes id_52 { id_51.public_key };
          Size id_53 { id_52.length() };
          uint32_t id_54 { uint32_t(id_53) };
          Vec<1, uint32_t> id_55 {  id_54  };
          Pointer let_res_56;
          {
            Vec<1, uint32_t> leb128_sz_202 { id_55 };
            Vec<1, Pointer> id_57 {  srec_dst_201  };
            Pointer let_res_58;
            {
              Vec<1, Pointer> leb128_ptr_203 { id_57 };
              bool while_flag_59 { true };
              do {
                uint8_t id_60 { 0 };
                uint8_t id_61 { 0 };
                Pointer id_62 { leb128_ptr_203[id_61] };
                uint32_t id_63 { 128U };
                uint8_t id_64 { 0 };
                uint32_t id_65 { leb128_sz_202[id_64] };
                bool id_66 { bool(id_63 > id_65) };
                uint8_t choose_res_67;
                if (id_66) {
                  uint8_t id_68 { 0 };
                  uint32_t id_69 { leb128_sz_202[id_68] };
                  uint8_t id_70 { uint8_t(id_69) };
                  choose_res_67 = id_70;
                } else {
                  uint8_t id_71 { 0 };
                  uint32_t id_72 { leb128_sz_202[id_71] };
                  uint8_t id_73 { uint8_t(id_72) };
                  uint8_t id_74 { 128 };
                  uint8_t id_75 { uint8_t(id_73 | id_74) };
                  choose_res_67 = id_75;
                }
                Pointer id_76 { id_62.writeU8(choose_res_67) };
                Void id_77 { ((void)(leb128_ptr_203[id_60] = id_76), VOID) };
                (void)id_77;
                uint8_t id_78 { 0 };
                uint8_t id_79 { 0 };
                uint32_t id_80 { leb128_sz_202[id_79] };
                uint8_t id_81 { 7 };
                uint32_t id_82 { uint32_t(id_80 >> id_81) };
                Void id_83 { ((void)(leb128_sz_202[id_78] = id_82), VOID) };
                (void)id_83;
                uint8_t id_84 { 0 };
                uint32_t id_85 { leb128_sz_202[id_84] };
                uint32_t id_86 { 0U };
                bool id_87 { bool(id_85 > id_86) };
                while_flag_59 = id_87;
                if (while_flag_59) {
                  (void)VOID;
                }
              } while (while_flag_59);
              (void)VOID;
              uint8_t id_88 { 0 };
              Pointer id_89 { leb128_ptr_203[id_88] };
              let_res_58 = id_89;
            }
            let_res_56 = let_res_58;
          }
          ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_90 { std::get<0 /* SendSessionKey */>(*p_0) };
          Bytes id_91 { id_90.public_key };
          Pointer id_92 { let_res_56.writeBytes(id_91) };
          let_res_50 = id_92;
        }
        Pointer let_res_93;
        {
          Pointer srec_dst_204 { let_res_50 };
          ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_94 { std::get<0 /* SendSessionKey */>(*p_0) };
          Bytes id_95 { id_94.SendSessionKey_message };
          Size id_96 { id_95.length() };
          uint32_t id_97 { uint32_t(id_96) };
          Vec<1, uint32_t> id_98 {  id_97  };
          Pointer let_res_99;
          {
            Vec<1, uint32_t> leb128_sz_205 { id_98 };
            Vec<1, Pointer> id_100 {  srec_dst_204  };
            Pointer let_res_101;
            {
              Vec<1, Pointer> leb128_ptr_206 { id_100 };
              bool while_flag_102 { true };
              do {
                uint8_t id_103 { 0 };
                uint8_t id_104 { 0 };
                Pointer id_105 { leb128_ptr_206[id_104] };
                uint32_t id_106 { 128U };
                uint8_t id_107 { 0 };
                uint32_t id_108 { leb128_sz_205[id_107] };
                bool id_109 { bool(id_106 > id_108) };
                uint8_t choose_res_110;
                if (id_109) {
                  uint8_t id_111 { 0 };
                  uint32_t id_112 { leb128_sz_205[id_111] };
                  uint8_t id_113 { uint8_t(id_112) };
                  choose_res_110 = id_113;
                } else {
                  uint8_t id_114 { 0 };
                  uint32_t id_115 { leb128_sz_205[id_114] };
                  uint8_t id_116 { uint8_t(id_115) };
                  uint8_t id_117 { 128 };
                  uint8_t id_118 { uint8_t(id_116 | id_117) };
                  choose_res_110 = id_118;
                }
                Pointer id_119 { id_105.writeU8(choose_res_110) };
                Void id_120 { ((void)(leb128_ptr_206[id_103] = id_119), VOID) };
                (void)id_120;
                uint8_t id_121 { 0 };
                uint8_t id_122 { 0 };
                uint32_t id_123 { leb128_sz_205[id_122] };
                uint8_t id_124 { 7 };
                uint32_t id_125 { uint32_t(id_123 >> id_124) };
                Void id_126 { ((void)(leb128_sz_205[id_121] = id_125), VOID) };
                (void)id_126;
                uint8_t id_127 { 0 };
                uint32_t id_128 { leb128_sz_205[id_127] };
                uint32_t id_129 { 0U };
                bool id_130 { bool(id_128 > id_129) };
                while_flag_102 = id_130;
                if (while_flag_102) {
                  (void)VOID;
                }
              } while (while_flag_102);
              (void)VOID;
              uint8_t id_131 { 0 };
              Pointer id_132 { leb128_ptr_206[id_131] };
              let_res_101 = id_132;
            }
            let_res_99 = let_res_101;
          }
          ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_133 { std::get<0 /* SendSessionKey */>(*p_0) };
          Bytes id_134 { id_133.SendSessionKey_message };
          Pointer id_135 { let_res_99.writeBytes(id_134) };
          let_res_93 = id_135;
        }
        choose_res_7 = let_res_93;
      } else {
        uint16_t id_136 { 1 };
        uint16_t id_137 { uint16_t(p_0->index()) };
        bool id_138 { bool(id_136 == id_137) };
        Pointer choose_res_139;
        if (id_138) {
          ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11 id_140 { std::get<1 /* Crypted */>(*p_0) };
          Bytes id_141 { id_140.nonce };
          Size id_142 { id_141.length() };
          uint32_t id_143 { uint32_t(id_142) };
          Vec<1, uint32_t> id_144 {  id_143  };
          Pointer let_res_145;
          {
            Vec<1, uint32_t> leb128_sz_194 { id_144 };
            Vec<1, Pointer> id_146 {  ssum_dst_189  };
            Pointer let_res_147;
            {
              Vec<1, Pointer> leb128_ptr_195 { id_146 };
              bool while_flag_148 { true };
              do {
                uint8_t id_149 { 0 };
                uint8_t id_150 { 0 };
                Pointer id_151 { leb128_ptr_195[id_150] };
                uint32_t id_152 { 128U };
                uint8_t id_153 { 0 };
                uint32_t id_154 { leb128_sz_194[id_153] };
                bool id_155 { bool(id_152 > id_154) };
                uint8_t choose_res_156;
                if (id_155) {
                  uint8_t id_157 { 0 };
                  uint32_t id_158 { leb128_sz_194[id_157] };
                  uint8_t id_159 { uint8_t(id_158) };
                  choose_res_156 = id_159;
                } else {
                  uint8_t id_160 { 0 };
                  uint32_t id_161 { leb128_sz_194[id_160] };
                  uint8_t id_162 { uint8_t(id_161) };
                  uint8_t id_163 { 128 };
                  uint8_t id_164 { uint8_t(id_162 | id_163) };
                  choose_res_156 = id_164;
                }
                Pointer id_165 { id_151.writeU8(choose_res_156) };
                Void id_166 { ((void)(leb128_ptr_195[id_149] = id_165), VOID) };
                (void)id_166;
                uint8_t id_167 { 0 };
                uint8_t id_168 { 0 };
                uint32_t id_169 { leb128_sz_194[id_168] };
                uint8_t id_170 { 7 };
                uint32_t id_171 { uint32_t(id_169 >> id_170) };
                Void id_172 { ((void)(leb128_sz_194[id_167] = id_171), VOID) };
                (void)id_172;
                uint8_t id_173 { 0 };
                uint32_t id_174 { leb128_sz_194[id_173] };
                uint32_t id_175 { 0U };
                bool id_176 { bool(id_174 > id_175) };
                while_flag_148 = id_176;
                if (while_flag_148) {
                  (void)VOID;
                }
              } while (while_flag_148);
              (void)VOID;
              uint8_t id_177 { 0 };
              Pointer id_178 { leb128_ptr_195[id_177] };
              let_res_147 = id_178;
            }
            let_res_145 = let_res_147;
          }
          ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11 id_179 { std::get<1 /* Crypted */>(*p_0) };
          Bytes id_180 { id_179.nonce };
          Pointer id_181 { let_res_145.writeBytes(id_180) };
          Pointer let_res_182;
          {
            Pointer srec_dst_196 { id_181 };
            ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11 id_183 { std::get<1 /* Crypted */>(*p_0) };
            Bytes id_184 { id_183.message };
            Size id_185 { id_184.length() };
            uint32_t id_186 { uint32_t(id_185) };
            Vec<1, uint32_t> id_187 {  id_186  };
            Pointer let_res_188;
            {
              Vec<1, uint32_t> leb128_sz_197 { id_187 };
              Vec<1, Pointer> id_189 {  srec_dst_196  };
              Pointer let_res_190;
              {
                Vec<1, Pointer> leb128_ptr_198 { id_189 };
                bool while_flag_191 { true };
                do {
                  uint8_t id_192 { 0 };
                  uint8_t id_193 { 0 };
                  Pointer id_194 { leb128_ptr_198[id_193] };
                  uint32_t id_195 { 128U };
                  uint8_t id_196 { 0 };
                  uint32_t id_197 { leb128_sz_197[id_196] };
                  bool id_198 { bool(id_195 > id_197) };
                  uint8_t choose_res_199;
                  if (id_198) {
                    uint8_t id_200 { 0 };
                    uint32_t id_201 { leb128_sz_197[id_200] };
                    uint8_t id_202 { uint8_t(id_201) };
                    choose_res_199 = id_202;
                  } else {
                    uint8_t id_203 { 0 };
                    uint32_t id_204 { leb128_sz_197[id_203] };
                    uint8_t id_205 { uint8_t(id_204) };
                    uint8_t id_206 { 128 };
                    uint8_t id_207 { uint8_t(id_205 | id_206) };
                    choose_res_199 = id_207;
                  }
                  Pointer id_208 { id_194.writeU8(choose_res_199) };
                  Void id_209 { ((void)(leb128_ptr_198[id_192] = id_208), VOID) };
                  (void)id_209;
                  uint8_t id_210 { 0 };
                  uint8_t id_211 { 0 };
                  uint32_t id_212 { leb128_sz_197[id_211] };
                  uint8_t id_213 { 7 };
                  uint32_t id_214 { uint32_t(id_212 >> id_213) };
                  Void id_215 { ((void)(leb128_sz_197[id_210] = id_214), VOID) };
                  (void)id_215;
                  uint8_t id_216 { 0 };
                  uint32_t id_217 { leb128_sz_197[id_216] };
                  uint32_t id_218 { 0U };
                  bool id_219 { bool(id_217 > id_218) };
                  while_flag_191 = id_219;
                  if (while_flag_191) {
                    (void)VOID;
                  }
                } while (while_flag_191);
                (void)VOID;
                uint8_t id_220 { 0 };
                Pointer id_221 { leb128_ptr_198[id_220] };
                let_res_190 = id_221;
              }
              let_res_188 = let_res_190;
            }
            ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11 id_222 { std::get<1 /* Crypted */>(*p_0) };
            Bytes id_223 { id_222.message };
            Pointer id_224 { let_res_188.writeBytes(id_223) };
            let_res_182 = id_224;
          }
          choose_res_139 = let_res_182;
        } else {
          uint16_t id_225 { 2 };
          uint16_t id_226 { uint16_t(p_0->index()) };
          bool id_227 { bool(id_225 == id_226) };
          Pointer choose_res_228;
          if (id_227) {
            Bytes id_229 { std::get<2 /* ClearText */>(*p_0) };
            Size id_230 { id_229.length() };
            uint32_t id_231 { uint32_t(id_230) };
            Vec<1, uint32_t> id_232 {  id_231  };
            Pointer let_res_233;
            {
              Vec<1, uint32_t> leb128_sz_192 { id_232 };
              Vec<1, Pointer> id_234 {  ssum_dst_189  };
              Pointer let_res_235;
              {
                Vec<1, Pointer> leb128_ptr_193 { id_234 };
                bool while_flag_236 { true };
                do {
                  uint8_t id_237 { 0 };
                  uint8_t id_238 { 0 };
                  Pointer id_239 { leb128_ptr_193[id_238] };
                  uint32_t id_240 { 128U };
                  uint8_t id_241 { 0 };
                  uint32_t id_242 { leb128_sz_192[id_241] };
                  bool id_243 { bool(id_240 > id_242) };
                  uint8_t choose_res_244;
                  if (id_243) {
                    uint8_t id_245 { 0 };
                    uint32_t id_246 { leb128_sz_192[id_245] };
                    uint8_t id_247 { uint8_t(id_246) };
                    choose_res_244 = id_247;
                  } else {
                    uint8_t id_248 { 0 };
                    uint32_t id_249 { leb128_sz_192[id_248] };
                    uint8_t id_250 { uint8_t(id_249) };
                    uint8_t id_251 { 128 };
                    uint8_t id_252 { uint8_t(id_250 | id_251) };
                    choose_res_244 = id_252;
                  }
                  Pointer id_253 { id_239.writeU8(choose_res_244) };
                  Void id_254 { ((void)(leb128_ptr_193[id_237] = id_253), VOID) };
                  (void)id_254;
                  uint8_t id_255 { 0 };
                  uint8_t id_256 { 0 };
                  uint32_t id_257 { leb128_sz_192[id_256] };
                  uint8_t id_258 { 7 };
                  uint32_t id_259 { uint32_t(id_257 >> id_258) };
                  Void id_260 { ((void)(leb128_sz_192[id_255] = id_259), VOID) };
                  (void)id_260;
                  uint8_t id_261 { 0 };
                  uint32_t id_262 { leb128_sz_192[id_261] };
                  uint32_t id_263 { 0U };
                  bool id_264 { bool(id_262 > id_263) };
                  while_flag_236 = id_264;
                  if (while_flag_236) {
                    (void)VOID;
                  }
                } while (while_flag_236);
                (void)VOID;
                uint8_t id_265 { 0 };
                Pointer id_266 { leb128_ptr_193[id_265] };
                let_res_235 = id_266;
              }
              let_res_233 = let_res_235;
            }
            Bytes id_267 { std::get<2 /* ClearText */>(*p_0) };
            Pointer id_268 { let_res_233.writeBytes(id_267) };
            choose_res_228 = id_268;
          } else {
            uint16_t id_269 { uint16_t(p_0->index()) };
            uint16_t id_270 { 3 };
            bool id_271 { bool(id_269 == id_270) };
            Void id_272 { ((void)(assert(id_271)), VOID) };
            (void)id_272;
            std::string id_273 { std::get<3 /* Error */>(*p_0) };
            uint32_t id_274 { (uint32_t)id_273.size() };
            Vec<1, uint32_t> id_275 {  id_274  };
            Pointer let_res_276;
            {
              Vec<1, uint32_t> leb128_sz_190 { id_275 };
              Vec<1, Pointer> id_277 {  ssum_dst_189  };
              Pointer let_res_278;
              {
                Vec<1, Pointer> leb128_ptr_191 { id_277 };
                bool while_flag_279 { true };
                do {
                  uint8_t id_280 { 0 };
                  uint8_t id_281 { 0 };
                  Pointer id_282 { leb128_ptr_191[id_281] };
                  uint32_t id_283 { 128U };
                  uint8_t id_284 { 0 };
                  uint32_t id_285 { leb128_sz_190[id_284] };
                  bool id_286 { bool(id_283 > id_285) };
                  uint8_t choose_res_287;
                  if (id_286) {
                    uint8_t id_288 { 0 };
                    uint32_t id_289 { leb128_sz_190[id_288] };
                    uint8_t id_290 { uint8_t(id_289) };
                    choose_res_287 = id_290;
                  } else {
                    uint8_t id_291 { 0 };
                    uint32_t id_292 { leb128_sz_190[id_291] };
                    uint8_t id_293 { uint8_t(id_292) };
                    uint8_t id_294 { 128 };
                    uint8_t id_295 { uint8_t(id_293 | id_294) };
                    choose_res_287 = id_295;
                  }
                  Pointer id_296 { id_282.writeU8(choose_res_287) };
                  Void id_297 { ((void)(leb128_ptr_191[id_280] = id_296), VOID) };
                  (void)id_297;
                  uint8_t id_298 { 0 };
                  uint8_t id_299 { 0 };
                  uint32_t id_300 { leb128_sz_190[id_299] };
                  uint8_t id_301 { 7 };
                  uint32_t id_302 { uint32_t(id_300 >> id_301) };
                  Void id_303 { ((void)(leb128_sz_190[id_298] = id_302), VOID) };
                  (void)id_303;
                  uint8_t id_304 { 0 };
                  uint32_t id_305 { leb128_sz_190[id_304] };
                  uint32_t id_306 { 0U };
                  bool id_307 { bool(id_305 > id_306) };
                  while_flag_279 = id_307;
                  if (while_flag_279) {
                    (void)VOID;
                  }
                } while (while_flag_279);
                (void)VOID;
                uint8_t id_308 { 0 };
                Pointer id_309 { leb128_ptr_191[id_308] };
                let_res_278 = id_309;
              }
              let_res_276 = let_res_278;
            }
            std::string id_310 { std::get<3 /* Error */>(*p_0) };
            Bytes id_311 { id_310 };
            Pointer id_312 { let_res_276.writeBytes(id_311) };
            choose_res_228 = id_312;
          }
          choose_res_139 = choose_res_228;
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
std::function<Pointer(::dessser::gen::sync_msg::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted {nonce: Bytes; message: Bytes} | ClearText Bytes | Error STRING]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_184"
          (let "sz_180"
            (add (size 2)
              (add
                (let "n_ref_178" (make-vec (u32-of-size (bytes-length (get-field "nonce" (get-alt "SendSessionKey" (param 0))))))
                  (let "lebsz_ref_179" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_178")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_179")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_179") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_179")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_179")))))) 
                (bytes-length (get-field "nonce" (get-alt "SendSessionKey" (param 0))))))
            (add (identifier "sz_180")
              (add
                (let "n_ref_182" (make-vec (u32-of-size (bytes-length (get-field "public_key" (get-alt "SendSessionKey" (param 0))))))
                  (let "lebsz_ref_183" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_182")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_183")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_183") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_183")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_183")))))) 
                (bytes-length (get-field "public_key" (get-alt "SendSessionKey" (param 0)))))))
          (add (identifier "sz_184")
            (add
              (let "n_ref_186" (make-vec (u32-of-size (bytes-length (get-field "message" (get-alt "SendSessionKey" (param 0))))))
                (let "lebsz_ref_187" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_186")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_187")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_187") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_187")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_187")))))) 
              (bytes-length (get-field "message" (get-alt "SendSessionKey" (param 0)))))))
        (if (eq (u16 1) (label-of (param 0)))
          (let "sz_172"
            (add (size 2)
              (add
                (let "n_ref_170" (make-vec (u32-of-size (bytes-length (get-field "nonce" (get-alt "Crypted" (param 0))))))
                  (let "lebsz_ref_171" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_170")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_171")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_171") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_171")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_171")))))) 
                (bytes-length (get-field "nonce" (get-alt "Crypted" (param 0))))))
            (add (identifier "sz_172")
              (add
                (let "n_ref_174" (make-vec (u32-of-size (bytes-length (get-field "message" (get-alt "Crypted" (param 0))))))
                  (let "lebsz_ref_175" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_174")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_175")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_175") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_175")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_175")))))) 
                (bytes-length (get-field "message" (get-alt "Crypted" (param 0)))))))
          (if (eq (u16 2) (label-of (param 0)))
            (add (size 2)
              (add
                (let "n_ref_166" (make-vec (u32-of-size (bytes-length (get-alt "ClearText" (param 0)))))
                  (let "lebsz_ref_167" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_166")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_167")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_167") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_167")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_167")))))) 
                (bytes-length (get-alt "ClearText" (param 0)))))
            (seq (assert (eq (label-of (param 0)) (u16 3)))
              (add (size 2)
                (add
                  (let "n_ref_163" (make-vec (string-length (get-alt "Error" (param 0))))
                    (let "lebsz_ref_164" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_163")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_164")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_164") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_164")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_164")))))) 
                  (size-of-u32 (string-length (get-alt "Error" (param 0)))))))))))
 */
static std::function<Size(::dessser::gen::sync_msg::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_msg::t*)> fun313 { [&fun313](::dessser::gen::sync_msg::t* p_0) {
    uint16_t id_314 { 0 };
    uint16_t id_315 { uint16_t(p_0->index()) };
    bool id_316 { bool(id_314 == id_315) };
    Size choose_res_317;
    if (id_316) {
      Size id_318 { 2UL };
      ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_319 { std::get<0 /* SendSessionKey */>(*p_0) };
      Bytes id_320 { id_319.SendSessionKey_nonce };
      Size id_321 { id_320.length() };
      uint32_t id_322 { uint32_t(id_321) };
      Vec<1, uint32_t> id_323 {  id_322  };
      Size let_res_324;
      {
        Vec<1, uint32_t> n_ref_178 { id_323 };
        uint32_t id_325 { 1U };
        Vec<1, uint32_t> id_326 {  id_325  };
        Size let_res_327;
        {
          Vec<1, uint32_t> lebsz_ref_179 { id_326 };
          bool while_flag_328 { true };
          do {
            uint8_t id_329 { 0 };
            uint32_t id_330 { n_ref_178[id_329] };
            uint8_t id_331 { 0 };
            uint32_t id_332 { lebsz_ref_179[id_331] };
            uint8_t id_333 { 7 };
            uint32_t id_334 { uint32_t(id_332 << id_333) };
            bool id_335 { bool(id_330 >= id_334) };
            while_flag_328 = id_335;
            if (while_flag_328) {
              uint8_t id_336 { 0 };
              uint8_t id_337 { 0 };
              uint32_t id_338 { lebsz_ref_179[id_337] };
              uint32_t id_339 { 1U };
              uint32_t id_340 { uint32_t(id_338 + id_339) };
              Void id_341 { ((void)(lebsz_ref_179[id_336] = id_340), VOID) };
              (void)id_341;
            }
          } while (while_flag_328);
          (void)VOID;
          uint8_t id_342 { 0 };
          uint32_t id_343 { lebsz_ref_179[id_342] };
          Size id_344 { Size(id_343) };
          let_res_327 = id_344;
        }
        let_res_324 = let_res_327;
      }
      ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_345 { std::get<0 /* SendSessionKey */>(*p_0) };
      Bytes id_346 { id_345.SendSessionKey_nonce };
      Size id_347 { id_346.length() };
      Size id_348 { Size(let_res_324 + id_347) };
      Size id_349 { Size(id_318 + id_348) };
      Size let_res_350;
      {
        Size sz_180 { id_349 };
        ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_351 { std::get<0 /* SendSessionKey */>(*p_0) };
        Bytes id_352 { id_351.public_key };
        Size id_353 { id_352.length() };
        uint32_t id_354 { uint32_t(id_353) };
        Vec<1, uint32_t> id_355 {  id_354  };
        Size let_res_356;
        {
          Vec<1, uint32_t> n_ref_182 { id_355 };
          uint32_t id_357 { 1U };
          Vec<1, uint32_t> id_358 {  id_357  };
          Size let_res_359;
          {
            Vec<1, uint32_t> lebsz_ref_183 { id_358 };
            bool while_flag_360 { true };
            do {
              uint8_t id_361 { 0 };
              uint32_t id_362 { n_ref_182[id_361] };
              uint8_t id_363 { 0 };
              uint32_t id_364 { lebsz_ref_183[id_363] };
              uint8_t id_365 { 7 };
              uint32_t id_366 { uint32_t(id_364 << id_365) };
              bool id_367 { bool(id_362 >= id_366) };
              while_flag_360 = id_367;
              if (while_flag_360) {
                uint8_t id_368 { 0 };
                uint8_t id_369 { 0 };
                uint32_t id_370 { lebsz_ref_183[id_369] };
                uint32_t id_371 { 1U };
                uint32_t id_372 { uint32_t(id_370 + id_371) };
                Void id_373 { ((void)(lebsz_ref_183[id_368] = id_372), VOID) };
                (void)id_373;
              }
            } while (while_flag_360);
            (void)VOID;
            uint8_t id_374 { 0 };
            uint32_t id_375 { lebsz_ref_183[id_374] };
            Size id_376 { Size(id_375) };
            let_res_359 = id_376;
          }
          let_res_356 = let_res_359;
        }
        ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_377 { std::get<0 /* SendSessionKey */>(*p_0) };
        Bytes id_378 { id_377.public_key };
        Size id_379 { id_378.length() };
        Size id_380 { Size(let_res_356 + id_379) };
        Size id_381 { Size(sz_180 + id_380) };
        let_res_350 = id_381;
      }
      Size let_res_382;
      {
        Size sz_184 { let_res_350 };
        ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_383 { std::get<0 /* SendSessionKey */>(*p_0) };
        Bytes id_384 { id_383.SendSessionKey_message };
        Size id_385 { id_384.length() };
        uint32_t id_386 { uint32_t(id_385) };
        Vec<1, uint32_t> id_387 {  id_386  };
        Size let_res_388;
        {
          Vec<1, uint32_t> n_ref_186 { id_387 };
          uint32_t id_389 { 1U };
          Vec<1, uint32_t> id_390 {  id_389  };
          Size let_res_391;
          {
            Vec<1, uint32_t> lebsz_ref_187 { id_390 };
            bool while_flag_392 { true };
            do {
              uint8_t id_393 { 0 };
              uint32_t id_394 { n_ref_186[id_393] };
              uint8_t id_395 { 0 };
              uint32_t id_396 { lebsz_ref_187[id_395] };
              uint8_t id_397 { 7 };
              uint32_t id_398 { uint32_t(id_396 << id_397) };
              bool id_399 { bool(id_394 >= id_398) };
              while_flag_392 = id_399;
              if (while_flag_392) {
                uint8_t id_400 { 0 };
                uint8_t id_401 { 0 };
                uint32_t id_402 { lebsz_ref_187[id_401] };
                uint32_t id_403 { 1U };
                uint32_t id_404 { uint32_t(id_402 + id_403) };
                Void id_405 { ((void)(lebsz_ref_187[id_400] = id_404), VOID) };
                (void)id_405;
              }
            } while (while_flag_392);
            (void)VOID;
            uint8_t id_406 { 0 };
            uint32_t id_407 { lebsz_ref_187[id_406] };
            Size id_408 { Size(id_407) };
            let_res_391 = id_408;
          }
          let_res_388 = let_res_391;
        }
        ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_409 { std::get<0 /* SendSessionKey */>(*p_0) };
        Bytes id_410 { id_409.SendSessionKey_message };
        Size id_411 { id_410.length() };
        Size id_412 { Size(let_res_388 + id_411) };
        Size id_413 { Size(sz_184 + id_412) };
        let_res_382 = id_413;
      }
      choose_res_317 = let_res_382;
    } else {
      uint16_t id_414 { 1 };
      uint16_t id_415 { uint16_t(p_0->index()) };
      bool id_416 { bool(id_414 == id_415) };
      Size choose_res_417;
      if (id_416) {
        Size id_418 { 2UL };
        ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11 id_419 { std::get<1 /* Crypted */>(*p_0) };
        Bytes id_420 { id_419.nonce };
        Size id_421 { id_420.length() };
        uint32_t id_422 { uint32_t(id_421) };
        Vec<1, uint32_t> id_423 {  id_422  };
        Size let_res_424;
        {
          Vec<1, uint32_t> n_ref_170 { id_423 };
          uint32_t id_425 { 1U };
          Vec<1, uint32_t> id_426 {  id_425  };
          Size let_res_427;
          {
            Vec<1, uint32_t> lebsz_ref_171 { id_426 };
            bool while_flag_428 { true };
            do {
              uint8_t id_429 { 0 };
              uint32_t id_430 { n_ref_170[id_429] };
              uint8_t id_431 { 0 };
              uint32_t id_432 { lebsz_ref_171[id_431] };
              uint8_t id_433 { 7 };
              uint32_t id_434 { uint32_t(id_432 << id_433) };
              bool id_435 { bool(id_430 >= id_434) };
              while_flag_428 = id_435;
              if (while_flag_428) {
                uint8_t id_436 { 0 };
                uint8_t id_437 { 0 };
                uint32_t id_438 { lebsz_ref_171[id_437] };
                uint32_t id_439 { 1U };
                uint32_t id_440 { uint32_t(id_438 + id_439) };
                Void id_441 { ((void)(lebsz_ref_171[id_436] = id_440), VOID) };
                (void)id_441;
              }
            } while (while_flag_428);
            (void)VOID;
            uint8_t id_442 { 0 };
            uint32_t id_443 { lebsz_ref_171[id_442] };
            Size id_444 { Size(id_443) };
            let_res_427 = id_444;
          }
          let_res_424 = let_res_427;
        }
        ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11 id_445 { std::get<1 /* Crypted */>(*p_0) };
        Bytes id_446 { id_445.nonce };
        Size id_447 { id_446.length() };
        Size id_448 { Size(let_res_424 + id_447) };
        Size id_449 { Size(id_418 + id_448) };
        Size let_res_450;
        {
          Size sz_172 { id_449 };
          ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11 id_451 { std::get<1 /* Crypted */>(*p_0) };
          Bytes id_452 { id_451.message };
          Size id_453 { id_452.length() };
          uint32_t id_454 { uint32_t(id_453) };
          Vec<1, uint32_t> id_455 {  id_454  };
          Size let_res_456;
          {
            Vec<1, uint32_t> n_ref_174 { id_455 };
            uint32_t id_457 { 1U };
            Vec<1, uint32_t> id_458 {  id_457  };
            Size let_res_459;
            {
              Vec<1, uint32_t> lebsz_ref_175 { id_458 };
              bool while_flag_460 { true };
              do {
                uint8_t id_461 { 0 };
                uint32_t id_462 { n_ref_174[id_461] };
                uint8_t id_463 { 0 };
                uint32_t id_464 { lebsz_ref_175[id_463] };
                uint8_t id_465 { 7 };
                uint32_t id_466 { uint32_t(id_464 << id_465) };
                bool id_467 { bool(id_462 >= id_466) };
                while_flag_460 = id_467;
                if (while_flag_460) {
                  uint8_t id_468 { 0 };
                  uint8_t id_469 { 0 };
                  uint32_t id_470 { lebsz_ref_175[id_469] };
                  uint32_t id_471 { 1U };
                  uint32_t id_472 { uint32_t(id_470 + id_471) };
                  Void id_473 { ((void)(lebsz_ref_175[id_468] = id_472), VOID) };
                  (void)id_473;
                }
              } while (while_flag_460);
              (void)VOID;
              uint8_t id_474 { 0 };
              uint32_t id_475 { lebsz_ref_175[id_474] };
              Size id_476 { Size(id_475) };
              let_res_459 = id_476;
            }
            let_res_456 = let_res_459;
          }
          ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11 id_477 { std::get<1 /* Crypted */>(*p_0) };
          Bytes id_478 { id_477.message };
          Size id_479 { id_478.length() };
          Size id_480 { Size(let_res_456 + id_479) };
          Size id_481 { Size(sz_172 + id_480) };
          let_res_450 = id_481;
        }
        choose_res_417 = let_res_450;
      } else {
        uint16_t id_482 { 2 };
        uint16_t id_483 { uint16_t(p_0->index()) };
        bool id_484 { bool(id_482 == id_483) };
        Size choose_res_485;
        if (id_484) {
          Size id_486 { 2UL };
          Bytes id_487 { std::get<2 /* ClearText */>(*p_0) };
          Size id_488 { id_487.length() };
          uint32_t id_489 { uint32_t(id_488) };
          Vec<1, uint32_t> id_490 {  id_489  };
          Size let_res_491;
          {
            Vec<1, uint32_t> n_ref_166 { id_490 };
            uint32_t id_492 { 1U };
            Vec<1, uint32_t> id_493 {  id_492  };
            Size let_res_494;
            {
              Vec<1, uint32_t> lebsz_ref_167 { id_493 };
              bool while_flag_495 { true };
              do {
                uint8_t id_496 { 0 };
                uint32_t id_497 { n_ref_166[id_496] };
                uint8_t id_498 { 0 };
                uint32_t id_499 { lebsz_ref_167[id_498] };
                uint8_t id_500 { 7 };
                uint32_t id_501 { uint32_t(id_499 << id_500) };
                bool id_502 { bool(id_497 >= id_501) };
                while_flag_495 = id_502;
                if (while_flag_495) {
                  uint8_t id_503 { 0 };
                  uint8_t id_504 { 0 };
                  uint32_t id_505 { lebsz_ref_167[id_504] };
                  uint32_t id_506 { 1U };
                  uint32_t id_507 { uint32_t(id_505 + id_506) };
                  Void id_508 { ((void)(lebsz_ref_167[id_503] = id_507), VOID) };
                  (void)id_508;
                }
              } while (while_flag_495);
              (void)VOID;
              uint8_t id_509 { 0 };
              uint32_t id_510 { lebsz_ref_167[id_509] };
              Size id_511 { Size(id_510) };
              let_res_494 = id_511;
            }
            let_res_491 = let_res_494;
          }
          Bytes id_512 { std::get<2 /* ClearText */>(*p_0) };
          Size id_513 { id_512.length() };
          Size id_514 { Size(let_res_491 + id_513) };
          Size id_515 { Size(id_486 + id_514) };
          choose_res_485 = id_515;
        } else {
          uint16_t id_516 { uint16_t(p_0->index()) };
          uint16_t id_517 { 3 };
          bool id_518 { bool(id_516 == id_517) };
          Void id_519 { ((void)(assert(id_518)), VOID) };
          (void)id_519;
          Size id_520 { 2UL };
          std::string id_521 { std::get<3 /* Error */>(*p_0) };
          uint32_t id_522 { (uint32_t)id_521.size() };
          Vec<1, uint32_t> id_523 {  id_522  };
          Size let_res_524;
          {
            Vec<1, uint32_t> n_ref_163 { id_523 };
            uint32_t id_525 { 1U };
            Vec<1, uint32_t> id_526 {  id_525  };
            Size let_res_527;
            {
              Vec<1, uint32_t> lebsz_ref_164 { id_526 };
              bool while_flag_528 { true };
              do {
                uint8_t id_529 { 0 };
                uint32_t id_530 { n_ref_163[id_529] };
                uint8_t id_531 { 0 };
                uint32_t id_532 { lebsz_ref_164[id_531] };
                uint8_t id_533 { 7 };
                uint32_t id_534 { uint32_t(id_532 << id_533) };
                bool id_535 { bool(id_530 >= id_534) };
                while_flag_528 = id_535;
                if (while_flag_528) {
                  uint8_t id_536 { 0 };
                  uint8_t id_537 { 0 };
                  uint32_t id_538 { lebsz_ref_164[id_537] };
                  uint32_t id_539 { 1U };
                  uint32_t id_540 { uint32_t(id_538 + id_539) };
                  Void id_541 { ((void)(lebsz_ref_164[id_536] = id_540), VOID) };
                  (void)id_541;
                }
              } while (while_flag_528);
              (void)VOID;
              uint8_t id_542 { 0 };
              uint32_t id_543 { lebsz_ref_164[id_542] };
              Size id_544 { Size(id_543) };
              let_res_527 = id_544;
            }
            let_res_524 = let_res_527;
          }
          std::string id_545 { std::get<3 /* Error */>(*p_0) };
          uint32_t id_546 { (uint32_t)id_545.size() };
          Size id_547 { Size(id_546) };
          Size id_548 { Size(let_res_524 + id_547) };
          Size id_549 { Size(id_520 + id_548) };
          choose_res_485 = id_549;
        }
        choose_res_417 = choose_res_485;
      }
      choose_res_317 = choose_res_417;
    }
    return choose_res_317;
  }
   };
  return fun313;
}
std::function<Size(::dessser::gen::sync_msg::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_159" "make_snd_160"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let "drec_128"
                (let "dbytes1_125"
                  (let "leb_ref_119" (make-vec (u32 0))
                    (let "shft_ref_120" (make-vec (u8 0))
                      (let "p_ref_121" (make-vec (identifier "dsum1_snd_64"))
                        (seq
                          (while
                            (let "leb128_122" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_121")))
                              (let-pair "leb128_fst_123" "leb128_snd_124" 
                                (identifier "leb128_122")
                                (seq (set-vec (u8 0) (identifier "p_ref_121") (identifier "leb128_snd_124"))
                                  (set-vec (u8 0) (identifier "leb_ref_119")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_123") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_120"))) (unsafe-nth (u8 0) (identifier "leb_ref_119"))))
                                  (set-vec (u8 0) (identifier "shft_ref_120") (add (unsafe-nth (u8 0) (identifier "shft_ref_120")) (u8 7))) 
                                  (ge (identifier "leb128_fst_123") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_119"))) (unsafe-nth (u8 0) (identifier "p_ref_121")))))))
                  (let-pair "dbytes1_fst_126" "dbytes1_snd_127" (identifier "dbytes1_125") (read-bytes (identifier "dbytes1_snd_127") (identifier "dbytes1_fst_126"))))
                (let-pair "drec_fst_129" "drec_snd_130" (identifier "drec_128")
                  (let "drec_140"
                    (let "dbytes1_137"
                      (let "leb_ref_131" (make-vec (u32 0))
                        (let "shft_ref_132" (make-vec (u8 0))
                          (let "p_ref_133" (make-vec (identifier "drec_snd_130"))
                            (seq
                              (while
                                (let "leb128_134" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_133")))
                                  (let-pair "leb128_fst_135" "leb128_snd_136" 
                                    (identifier "leb128_134")
                                    (seq (set-vec (u8 0) (identifier "p_ref_133") (identifier "leb128_snd_136"))
                                      (set-vec (u8 0) (identifier "leb_ref_131")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_135") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_132"))) (unsafe-nth (u8 0) (identifier "leb_ref_131"))))
                                      (set-vec (u8 0) (identifier "shft_ref_132") (add (unsafe-nth (u8 0) (identifier "shft_ref_132")) (u8 7))) 
                                      (ge (identifier "leb128_fst_135") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_131"))) (unsafe-nth (u8 0) (identifier "p_ref_133")))))))
                      (let-pair "dbytes1_fst_138" "dbytes1_snd_139" (identifier "dbytes1_137") (read-bytes (identifier "dbytes1_snd_139") (identifier "dbytes1_fst_138"))))
                    (let-pair "drec_fst_141" "drec_snd_142" (identifier "drec_140")
                      (let-pair "drec_fst_153" "drec_snd_154"
                        (let "dbytes1_149"
                          (let "leb_ref_143" (make-vec (u32 0))
                            (let "shft_ref_144" (make-vec (u8 0))
                              (let "p_ref_145" (make-vec (identifier "drec_snd_142"))
                                (seq
                                  (while
                                    (let "leb128_146" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_145")))
                                      (let-pair "leb128_fst_147" "leb128_snd_148" 
                                        (identifier "leb128_146")
                                        (seq (set-vec (u8 0) (identifier "p_ref_145") (identifier "leb128_snd_148"))
                                          (set-vec (u8 0) (identifier "leb_ref_143")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_147") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_144"))) (unsafe-nth (u8 0) (identifier "leb_ref_143"))))
                                          (set-vec (u8 0) (identifier "shft_ref_144") (add (unsafe-nth (u8 0) (identifier "shft_ref_144")) (u8 7))) 
                                          (ge (identifier "leb128_fst_147") (u8 128))))) 
                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_143"))) (unsafe-nth (u8 0) (identifier "p_ref_145")))))))
                          (let-pair "dbytes1_fst_150" "dbytes1_snd_151" (identifier "dbytes1_149") (read-bytes (identifier "dbytes1_snd_151") (identifier "dbytes1_fst_150"))))
                        (make-tup
                          (construct "[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted {nonce: Bytes; message: Bytes} | ClearText Bytes | Error STRING]" 0
                            (make-rec (string "message") (identifier "drec_fst_153") (string "public_key") (identifier "drec_fst_141") (string "nonce") (identifier "drec_fst_129"))) 
                          (identifier "drec_snd_154")))))))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let "drec_101"
                  (let "dbytes1_98"
                    (let "leb_ref_92" (make-vec (u32 0))
                      (let "shft_ref_93" (make-vec (u8 0))
                        (let "p_ref_94" (make-vec (identifier "dsum1_snd_64"))
                          (seq
                            (while
                              (let "leb128_95" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_94")))
                                (let-pair "leb128_fst_96" "leb128_snd_97" 
                                  (identifier "leb128_95")
                                  (seq (set-vec (u8 0) (identifier "p_ref_94") (identifier "leb128_snd_97"))
                                    (set-vec (u8 0) (identifier "leb_ref_92")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_96") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_93"))) (unsafe-nth (u8 0) (identifier "leb_ref_92"))))
                                    (set-vec (u8 0) (identifier "shft_ref_93") (add (unsafe-nth (u8 0) (identifier "shft_ref_93")) (u8 7))) 
                                    (ge (identifier "leb128_fst_96") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_92"))) (unsafe-nth (u8 0) (identifier "p_ref_94")))))))
                    (let-pair "dbytes1_fst_99" "dbytes1_snd_100" (identifier "dbytes1_98") (read-bytes (identifier "dbytes1_snd_100") (identifier "dbytes1_fst_99"))))
                  (let-pair "drec_fst_102" "drec_snd_103" (identifier "drec_101")
                    (let-pair "drec_fst_114" "drec_snd_115"
                      (let "dbytes1_110"
                        (let "leb_ref_104" (make-vec (u32 0))
                          (let "shft_ref_105" (make-vec (u8 0))
                            (let "p_ref_106" (make-vec (identifier "drec_snd_103"))
                              (seq
                                (while
                                  (let "leb128_107" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_106")))
                                    (let-pair "leb128_fst_108" "leb128_snd_109" 
                                      (identifier "leb128_107")
                                      (seq (set-vec (u8 0) (identifier "p_ref_106") (identifier "leb128_snd_109"))
                                        (set-vec (u8 0) (identifier "leb_ref_104")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_108") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_105"))) (unsafe-nth (u8 0) (identifier "leb_ref_104"))))
                                        (set-vec (u8 0) (identifier "shft_ref_105") (add (unsafe-nth (u8 0) (identifier "shft_ref_105")) (u8 7))) 
                                        (ge (identifier "leb128_fst_108") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_104"))) (unsafe-nth (u8 0) (identifier "p_ref_106")))))))
                        (let-pair "dbytes1_fst_111" "dbytes1_snd_112" (identifier "dbytes1_110") (read-bytes (identifier "dbytes1_snd_112") (identifier "dbytes1_fst_111"))))
                      (make-tup
                        (construct "[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted {nonce: Bytes; message: Bytes} | ClearText Bytes | Error STRING]" 1
                          (make-rec (string "message") (identifier "drec_fst_114") (string "nonce") (identifier "drec_fst_102"))) 
                        (identifier "drec_snd_115")))))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (let-pair "dsum2_fst_90" "dsum2_snd_91"
                    (let "dbytes1_86"
                      (let "leb_ref_80" (make-vec (u32 0))
                        (let "shft_ref_81" (make-vec (u8 0))
                          (let "p_ref_82" (make-vec (identifier "dsum1_snd_64"))
                            (seq
                              (while
                                (let "leb128_83" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_82")))
                                  (let-pair "leb128_fst_84" "leb128_snd_85" 
                                    (identifier "leb128_83")
                                    (seq (set-vec (u8 0) (identifier "p_ref_82") (identifier "leb128_snd_85"))
                                      (set-vec (u8 0) (identifier "leb_ref_80")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_84") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_81"))) (unsafe-nth (u8 0) (identifier "leb_ref_80"))))
                                      (set-vec (u8 0) (identifier "shft_ref_81") (add (unsafe-nth (u8 0) (identifier "shft_ref_81")) (u8 7))) 
                                      (ge (identifier "leb128_fst_84") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_80"))) (unsafe-nth (u8 0) (identifier "p_ref_82")))))))
                      (let-pair "dbytes1_fst_87" "dbytes1_snd_88" (identifier "dbytes1_86") (read-bytes (identifier "dbytes1_snd_88") (identifier "dbytes1_fst_87"))))
                    (make-tup (construct "[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted {nonce: Bytes; message: Bytes} | ClearText Bytes | Error STRING]" 2 (identifier "dsum2_fst_90"))
                      (identifier "dsum2_snd_91")))
                  (seq (assert (eq (identifier "dsum1_fst_63") (u16 3)))
                    (let "dstring1_71"
                      (let "leb_ref_65" (make-vec (u32 0))
                        (let "shft_ref_66" (make-vec (u8 0))
                          (let "p_ref_67" (make-vec (identifier "dsum1_snd_64"))
                            (seq
                              (while
                                (let "leb128_68" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_67")))
                                  (let-pair "leb128_fst_69" "leb128_snd_70" 
                                    (identifier "leb128_68")
                                    (seq (set-vec (u8 0) (identifier "p_ref_67") (identifier "leb128_snd_70"))
                                      (set-vec (u8 0) (identifier "leb_ref_65")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_69") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_66"))) (unsafe-nth (u8 0) (identifier "leb_ref_65"))))
                                      (set-vec (u8 0) (identifier "shft_ref_66") (add (unsafe-nth (u8 0) (identifier "shft_ref_66")) (u8 7))) 
                                      (ge (identifier "leb128_fst_69") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_65"))) (unsafe-nth (u8 0) (identifier "p_ref_67")))))))
                      (let-pair "dstring1_fst_72" "dstring1_snd_73" (identifier "dstring1_71")
                        (let-pair "dstring2_fst_75" "dstring2_snd_76" 
                          (read-bytes (identifier "dstring1_snd_73") (identifier "dstring1_fst_72"))
                          (make-tup
                            (construct "[SendSessionKey {nonce: Bytes; public_key: Bytes; message: Bytes} | Crypted {nonce: Bytes; message: Bytes} | ClearText Bytes | Error STRING]" 3
                              (string-of-bytes (identifier "dstring2_fst_75"))) 
                            (identifier "dstring2_snd_76"))))))))))) 
        (make-tup (identifier "make_fst_159") (identifier "make_snd_160"))))
 */
static std::function<::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23(Pointer)> fun550 { [&fun550](Pointer p_0) {
    ::dessser::gen::sync_msg::t22a32080ad88ab548b80077a17b7dd46 id_551 { p_0.readU16Le() };
    ::dessser::gen::sync_msg::t22a32080ad88ab548b80077a17b7dd46 letpair_res_552;
    {
      auto du16_fst_57 { std::get<0>(id_551) };
      auto du16_snd_58 { std::get<1>(id_551) };
      ::dessser::gen::sync_msg::t22a32080ad88ab548b80077a17b7dd46 id_553 { du16_fst_57, du16_snd_58 };
      letpair_res_552 = id_553;
    }
    ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 let_res_554;
    {
      ::dessser::gen::sync_msg::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_552 };
      ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_555;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_556 { 0 };
        bool id_557 { bool(id_556 == dsum1_fst_63) };
        ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 choose_res_558;
        if (id_557) {
          uint32_t id_559 { 0U };
          Vec<1, uint32_t> id_560 {  id_559  };
          ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_561;
          {
            Vec<1, uint32_t> leb_ref_119 { id_560 };
            uint8_t id_562 { 0 };
            Vec<1, uint8_t> id_563 {  id_562  };
            ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_564;
            {
              Vec<1, uint8_t> shft_ref_120 { id_563 };
              Vec<1, Pointer> id_565 {  dsum1_snd_64  };
              ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_566;
              {
                Vec<1, Pointer> p_ref_121 { id_565 };
                bool while_flag_567 { true };
                do {
                  uint8_t id_568 { 0 };
                  Pointer id_569 { p_ref_121[id_568] };
                  ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 id_570 { id_569.readU8() };
                  bool let_res_571;
                  {
                    ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 leb128_122 { id_570 };
                    bool letpair_res_572;
                    {
                      auto leb128_fst_123 { std::get<0>(leb128_122) };
                      auto leb128_snd_124 { std::get<1>(leb128_122) };
                      uint8_t id_573 { 0 };
                      Void id_574 { ((void)(p_ref_121[id_573] = leb128_snd_124), VOID) };
                      (void)id_574;
                      uint8_t id_575 { 0 };
                      uint8_t id_576 { 127 };
                      uint8_t id_577 { uint8_t(leb128_fst_123 & id_576) };
                      uint32_t id_578 { uint32_t(id_577) };
                      uint8_t id_579 { 0 };
                      uint8_t id_580 { shft_ref_120[id_579] };
                      uint32_t id_581 { uint32_t(id_578 << id_580) };
                      uint8_t id_582 { 0 };
                      uint32_t id_583 { leb_ref_119[id_582] };
                      uint32_t id_584 { uint32_t(id_581 | id_583) };
                      Void id_585 { ((void)(leb_ref_119[id_575] = id_584), VOID) };
                      (void)id_585;
                      uint8_t id_586 { 0 };
                      uint8_t id_587 { 0 };
                      uint8_t id_588 { shft_ref_120[id_587] };
                      uint8_t id_589 { 7 };
                      uint8_t id_590 { uint8_t(id_588 + id_589) };
                      Void id_591 { ((void)(shft_ref_120[id_586] = id_590), VOID) };
                      (void)id_591;
                      uint8_t id_592 { 128 };
                      bool id_593 { bool(leb128_fst_123 >= id_592) };
                      letpair_res_572 = id_593;
                    }
                    let_res_571 = letpair_res_572;
                  }
                  while_flag_567 = let_res_571;
                  if (while_flag_567) {
                    (void)VOID;
                  }
                } while (while_flag_567);
                (void)VOID;
                uint8_t id_594 { 0 };
                uint32_t id_595 { leb_ref_119[id_594] };
                Size id_596 { Size(id_595) };
                uint8_t id_597 { 0 };
                Pointer id_598 { p_ref_121[id_597] };
                ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c id_599 { id_596, id_598 };
                let_res_566 = id_599;
              }
              let_res_564 = let_res_566;
            }
            let_res_561 = let_res_564;
          }
          ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 let_res_600;
          {
            ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c dbytes1_125 { let_res_561 };
            ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 letpair_res_601;
            {
              auto dbytes1_fst_126 { std::get<0>(dbytes1_125) };
              auto dbytes1_snd_127 { std::get<1>(dbytes1_125) };
              ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 id_602 { dbytes1_snd_127.readBytes(dbytes1_fst_126) };
              letpair_res_601 = id_602;
            }
            let_res_600 = letpair_res_601;
          }
          ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 let_res_603;
          {
            ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 drec_128 { let_res_600 };
            ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_604;
            {
              auto drec_fst_129 { std::get<0>(drec_128) };
              auto drec_snd_130 { std::get<1>(drec_128) };
              uint32_t id_605 { 0U };
              Vec<1, uint32_t> id_606 {  id_605  };
              ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_607;
              {
                Vec<1, uint32_t> leb_ref_131 { id_606 };
                uint8_t id_608 { 0 };
                Vec<1, uint8_t> id_609 {  id_608  };
                ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_610;
                {
                  Vec<1, uint8_t> shft_ref_132 { id_609 };
                  Vec<1, Pointer> id_611 {  drec_snd_130  };
                  ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_612;
                  {
                    Vec<1, Pointer> p_ref_133 { id_611 };
                    bool while_flag_613 { true };
                    do {
                      uint8_t id_614 { 0 };
                      Pointer id_615 { p_ref_133[id_614] };
                      ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 id_616 { id_615.readU8() };
                      bool let_res_617;
                      {
                        ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 leb128_134 { id_616 };
                        bool letpair_res_618;
                        {
                          auto leb128_fst_135 { std::get<0>(leb128_134) };
                          auto leb128_snd_136 { std::get<1>(leb128_134) };
                          uint8_t id_619 { 0 };
                          Void id_620 { ((void)(p_ref_133[id_619] = leb128_snd_136), VOID) };
                          (void)id_620;
                          uint8_t id_621 { 0 };
                          uint8_t id_622 { 127 };
                          uint8_t id_623 { uint8_t(leb128_fst_135 & id_622) };
                          uint32_t id_624 { uint32_t(id_623) };
                          uint8_t id_625 { 0 };
                          uint8_t id_626 { shft_ref_132[id_625] };
                          uint32_t id_627 { uint32_t(id_624 << id_626) };
                          uint8_t id_628 { 0 };
                          uint32_t id_629 { leb_ref_131[id_628] };
                          uint32_t id_630 { uint32_t(id_627 | id_629) };
                          Void id_631 { ((void)(leb_ref_131[id_621] = id_630), VOID) };
                          (void)id_631;
                          uint8_t id_632 { 0 };
                          uint8_t id_633 { 0 };
                          uint8_t id_634 { shft_ref_132[id_633] };
                          uint8_t id_635 { 7 };
                          uint8_t id_636 { uint8_t(id_634 + id_635) };
                          Void id_637 { ((void)(shft_ref_132[id_632] = id_636), VOID) };
                          (void)id_637;
                          uint8_t id_638 { 128 };
                          bool id_639 { bool(leb128_fst_135 >= id_638) };
                          letpair_res_618 = id_639;
                        }
                        let_res_617 = letpair_res_618;
                      }
                      while_flag_613 = let_res_617;
                      if (while_flag_613) {
                        (void)VOID;
                      }
                    } while (while_flag_613);
                    (void)VOID;
                    uint8_t id_640 { 0 };
                    uint32_t id_641 { leb_ref_131[id_640] };
                    Size id_642 { Size(id_641) };
                    uint8_t id_643 { 0 };
                    Pointer id_644 { p_ref_133[id_643] };
                    ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c id_645 { id_642, id_644 };
                    let_res_612 = id_645;
                  }
                  let_res_610 = let_res_612;
                }
                let_res_607 = let_res_610;
              }
              ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 let_res_646;
              {
                ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c dbytes1_137 { let_res_607 };
                ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 letpair_res_647;
                {
                  auto dbytes1_fst_138 { std::get<0>(dbytes1_137) };
                  auto dbytes1_snd_139 { std::get<1>(dbytes1_137) };
                  ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 id_648 { dbytes1_snd_139.readBytes(dbytes1_fst_138) };
                  letpair_res_647 = id_648;
                }
                let_res_646 = letpair_res_647;
              }
              ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 let_res_649;
              {
                ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 drec_140 { let_res_646 };
                ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_650;
                {
                  auto drec_fst_141 { std::get<0>(drec_140) };
                  auto drec_snd_142 { std::get<1>(drec_140) };
                  uint32_t id_651 { 0U };
                  Vec<1, uint32_t> id_652 {  id_651  };
                  ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_653;
                  {
                    Vec<1, uint32_t> leb_ref_143 { id_652 };
                    uint8_t id_654 { 0 };
                    Vec<1, uint8_t> id_655 {  id_654  };
                    ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_656;
                    {
                      Vec<1, uint8_t> shft_ref_144 { id_655 };
                      Vec<1, Pointer> id_657 {  drec_snd_142  };
                      ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_658;
                      {
                        Vec<1, Pointer> p_ref_145 { id_657 };
                        bool while_flag_659 { true };
                        do {
                          uint8_t id_660 { 0 };
                          Pointer id_661 { p_ref_145[id_660] };
                          ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 id_662 { id_661.readU8() };
                          bool let_res_663;
                          {
                            ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 leb128_146 { id_662 };
                            bool letpair_res_664;
                            {
                              auto leb128_fst_147 { std::get<0>(leb128_146) };
                              auto leb128_snd_148 { std::get<1>(leb128_146) };
                              uint8_t id_665 { 0 };
                              Void id_666 { ((void)(p_ref_145[id_665] = leb128_snd_148), VOID) };
                              (void)id_666;
                              uint8_t id_667 { 0 };
                              uint8_t id_668 { 127 };
                              uint8_t id_669 { uint8_t(leb128_fst_147 & id_668) };
                              uint32_t id_670 { uint32_t(id_669) };
                              uint8_t id_671 { 0 };
                              uint8_t id_672 { shft_ref_144[id_671] };
                              uint32_t id_673 { uint32_t(id_670 << id_672) };
                              uint8_t id_674 { 0 };
                              uint32_t id_675 { leb_ref_143[id_674] };
                              uint32_t id_676 { uint32_t(id_673 | id_675) };
                              Void id_677 { ((void)(leb_ref_143[id_667] = id_676), VOID) };
                              (void)id_677;
                              uint8_t id_678 { 0 };
                              uint8_t id_679 { 0 };
                              uint8_t id_680 { shft_ref_144[id_679] };
                              uint8_t id_681 { 7 };
                              uint8_t id_682 { uint8_t(id_680 + id_681) };
                              Void id_683 { ((void)(shft_ref_144[id_678] = id_682), VOID) };
                              (void)id_683;
                              uint8_t id_684 { 128 };
                              bool id_685 { bool(leb128_fst_147 >= id_684) };
                              letpair_res_664 = id_685;
                            }
                            let_res_663 = letpair_res_664;
                          }
                          while_flag_659 = let_res_663;
                          if (while_flag_659) {
                            (void)VOID;
                          }
                        } while (while_flag_659);
                        (void)VOID;
                        uint8_t id_686 { 0 };
                        uint32_t id_687 { leb_ref_143[id_686] };
                        Size id_688 { Size(id_687) };
                        uint8_t id_689 { 0 };
                        Pointer id_690 { p_ref_145[id_689] };
                        ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c id_691 { id_688, id_690 };
                        let_res_658 = id_691;
                      }
                      let_res_656 = let_res_658;
                    }
                    let_res_653 = let_res_656;
                  }
                  ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 let_res_692;
                  {
                    ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c dbytes1_149 { let_res_653 };
                    ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 letpair_res_693;
                    {
                      auto dbytes1_fst_150 { std::get<0>(dbytes1_149) };
                      auto dbytes1_snd_151 { std::get<1>(dbytes1_149) };
                      ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 id_694 { dbytes1_snd_151.readBytes(dbytes1_fst_150) };
                      letpair_res_693 = id_694;
                    }
                    let_res_692 = letpair_res_693;
                  }
                  ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_695;
                  {
                    auto drec_fst_153 { std::get<0>(let_res_692) };
                    auto drec_snd_154 { std::get<1>(let_res_692) };
                    ::dessser::gen::sync_msg::tdb9685b762777dddeea8bb04805eb8cf id_696 { .SendSessionKey_message = drec_fst_153, .SendSessionKey_nonce = drec_fst_129, .public_key = drec_fst_141 };
                    ::dessser::gen::sync_msg::t* id_697 { new ::dessser::gen::sync_msg::t(std::in_place_index<0>, id_696) };
                    ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 id_698 { id_697, drec_snd_154 };
                    letpair_res_695 = id_698;
                  }
                  letpair_res_650 = letpair_res_695;
                }
                let_res_649 = letpair_res_650;
              }
              letpair_res_604 = let_res_649;
            }
            let_res_603 = letpair_res_604;
          }
          choose_res_558 = let_res_603;
        } else {
          uint16_t id_699 { 1 };
          bool id_700 { bool(id_699 == dsum1_fst_63) };
          ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 choose_res_701;
          if (id_700) {
            uint32_t id_702 { 0U };
            Vec<1, uint32_t> id_703 {  id_702  };
            ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_704;
            {
              Vec<1, uint32_t> leb_ref_92 { id_703 };
              uint8_t id_705 { 0 };
              Vec<1, uint8_t> id_706 {  id_705  };
              ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_707;
              {
                Vec<1, uint8_t> shft_ref_93 { id_706 };
                Vec<1, Pointer> id_708 {  dsum1_snd_64  };
                ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_709;
                {
                  Vec<1, Pointer> p_ref_94 { id_708 };
                  bool while_flag_710 { true };
                  do {
                    uint8_t id_711 { 0 };
                    Pointer id_712 { p_ref_94[id_711] };
                    ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 id_713 { id_712.readU8() };
                    bool let_res_714;
                    {
                      ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 leb128_95 { id_713 };
                      bool letpair_res_715;
                      {
                        auto leb128_fst_96 { std::get<0>(leb128_95) };
                        auto leb128_snd_97 { std::get<1>(leb128_95) };
                        uint8_t id_716 { 0 };
                        Void id_717 { ((void)(p_ref_94[id_716] = leb128_snd_97), VOID) };
                        (void)id_717;
                        uint8_t id_718 { 0 };
                        uint8_t id_719 { 127 };
                        uint8_t id_720 { uint8_t(leb128_fst_96 & id_719) };
                        uint32_t id_721 { uint32_t(id_720) };
                        uint8_t id_722 { 0 };
                        uint8_t id_723 { shft_ref_93[id_722] };
                        uint32_t id_724 { uint32_t(id_721 << id_723) };
                        uint8_t id_725 { 0 };
                        uint32_t id_726 { leb_ref_92[id_725] };
                        uint32_t id_727 { uint32_t(id_724 | id_726) };
                        Void id_728 { ((void)(leb_ref_92[id_718] = id_727), VOID) };
                        (void)id_728;
                        uint8_t id_729 { 0 };
                        uint8_t id_730 { 0 };
                        uint8_t id_731 { shft_ref_93[id_730] };
                        uint8_t id_732 { 7 };
                        uint8_t id_733 { uint8_t(id_731 + id_732) };
                        Void id_734 { ((void)(shft_ref_93[id_729] = id_733), VOID) };
                        (void)id_734;
                        uint8_t id_735 { 128 };
                        bool id_736 { bool(leb128_fst_96 >= id_735) };
                        letpair_res_715 = id_736;
                      }
                      let_res_714 = letpair_res_715;
                    }
                    while_flag_710 = let_res_714;
                    if (while_flag_710) {
                      (void)VOID;
                    }
                  } while (while_flag_710);
                  (void)VOID;
                  uint8_t id_737 { 0 };
                  uint32_t id_738 { leb_ref_92[id_737] };
                  Size id_739 { Size(id_738) };
                  uint8_t id_740 { 0 };
                  Pointer id_741 { p_ref_94[id_740] };
                  ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c id_742 { id_739, id_741 };
                  let_res_709 = id_742;
                }
                let_res_707 = let_res_709;
              }
              let_res_704 = let_res_707;
            }
            ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 let_res_743;
            {
              ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c dbytes1_98 { let_res_704 };
              ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 letpair_res_744;
              {
                auto dbytes1_fst_99 { std::get<0>(dbytes1_98) };
                auto dbytes1_snd_100 { std::get<1>(dbytes1_98) };
                ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 id_745 { dbytes1_snd_100.readBytes(dbytes1_fst_99) };
                letpair_res_744 = id_745;
              }
              let_res_743 = letpair_res_744;
            }
            ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 let_res_746;
            {
              ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 drec_101 { let_res_743 };
              ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_747;
              {
                auto drec_fst_102 { std::get<0>(drec_101) };
                auto drec_snd_103 { std::get<1>(drec_101) };
                uint32_t id_748 { 0U };
                Vec<1, uint32_t> id_749 {  id_748  };
                ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_750;
                {
                  Vec<1, uint32_t> leb_ref_104 { id_749 };
                  uint8_t id_751 { 0 };
                  Vec<1, uint8_t> id_752 {  id_751  };
                  ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_753;
                  {
                    Vec<1, uint8_t> shft_ref_105 { id_752 };
                    Vec<1, Pointer> id_754 {  drec_snd_103  };
                    ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_755;
                    {
                      Vec<1, Pointer> p_ref_106 { id_754 };
                      bool while_flag_756 { true };
                      do {
                        uint8_t id_757 { 0 };
                        Pointer id_758 { p_ref_106[id_757] };
                        ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 id_759 { id_758.readU8() };
                        bool let_res_760;
                        {
                          ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 leb128_107 { id_759 };
                          bool letpair_res_761;
                          {
                            auto leb128_fst_108 { std::get<0>(leb128_107) };
                            auto leb128_snd_109 { std::get<1>(leb128_107) };
                            uint8_t id_762 { 0 };
                            Void id_763 { ((void)(p_ref_106[id_762] = leb128_snd_109), VOID) };
                            (void)id_763;
                            uint8_t id_764 { 0 };
                            uint8_t id_765 { 127 };
                            uint8_t id_766 { uint8_t(leb128_fst_108 & id_765) };
                            uint32_t id_767 { uint32_t(id_766) };
                            uint8_t id_768 { 0 };
                            uint8_t id_769 { shft_ref_105[id_768] };
                            uint32_t id_770 { uint32_t(id_767 << id_769) };
                            uint8_t id_771 { 0 };
                            uint32_t id_772 { leb_ref_104[id_771] };
                            uint32_t id_773 { uint32_t(id_770 | id_772) };
                            Void id_774 { ((void)(leb_ref_104[id_764] = id_773), VOID) };
                            (void)id_774;
                            uint8_t id_775 { 0 };
                            uint8_t id_776 { 0 };
                            uint8_t id_777 { shft_ref_105[id_776] };
                            uint8_t id_778 { 7 };
                            uint8_t id_779 { uint8_t(id_777 + id_778) };
                            Void id_780 { ((void)(shft_ref_105[id_775] = id_779), VOID) };
                            (void)id_780;
                            uint8_t id_781 { 128 };
                            bool id_782 { bool(leb128_fst_108 >= id_781) };
                            letpair_res_761 = id_782;
                          }
                          let_res_760 = letpair_res_761;
                        }
                        while_flag_756 = let_res_760;
                        if (while_flag_756) {
                          (void)VOID;
                        }
                      } while (while_flag_756);
                      (void)VOID;
                      uint8_t id_783 { 0 };
                      uint32_t id_784 { leb_ref_104[id_783] };
                      Size id_785 { Size(id_784) };
                      uint8_t id_786 { 0 };
                      Pointer id_787 { p_ref_106[id_786] };
                      ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c id_788 { id_785, id_787 };
                      let_res_755 = id_788;
                    }
                    let_res_753 = let_res_755;
                  }
                  let_res_750 = let_res_753;
                }
                ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 let_res_789;
                {
                  ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c dbytes1_110 { let_res_750 };
                  ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 letpair_res_790;
                  {
                    auto dbytes1_fst_111 { std::get<0>(dbytes1_110) };
                    auto dbytes1_snd_112 { std::get<1>(dbytes1_110) };
                    ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 id_791 { dbytes1_snd_112.readBytes(dbytes1_fst_111) };
                    letpair_res_790 = id_791;
                  }
                  let_res_789 = letpair_res_790;
                }
                ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_792;
                {
                  auto drec_fst_114 { std::get<0>(let_res_789) };
                  auto drec_snd_115 { std::get<1>(let_res_789) };
                  ::dessser::gen::sync_msg::t10b7d87ea3b6637868bb9b5cc57e7b11 id_793 { .message = drec_fst_114, .nonce = drec_fst_102 };
                  ::dessser::gen::sync_msg::t* id_794 { new ::dessser::gen::sync_msg::t(std::in_place_index<1>, id_793) };
                  ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 id_795 { id_794, drec_snd_115 };
                  letpair_res_792 = id_795;
                }
                letpair_res_747 = letpair_res_792;
              }
              let_res_746 = letpair_res_747;
            }
            choose_res_701 = let_res_746;
          } else {
            uint16_t id_796 { 2 };
            bool id_797 { bool(id_796 == dsum1_fst_63) };
            ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 choose_res_798;
            if (id_797) {
              uint32_t id_799 { 0U };
              Vec<1, uint32_t> id_800 {  id_799  };
              ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_801;
              {
                Vec<1, uint32_t> leb_ref_80 { id_800 };
                uint8_t id_802 { 0 };
                Vec<1, uint8_t> id_803 {  id_802  };
                ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_804;
                {
                  Vec<1, uint8_t> shft_ref_81 { id_803 };
                  Vec<1, Pointer> id_805 {  dsum1_snd_64  };
                  ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_806;
                  {
                    Vec<1, Pointer> p_ref_82 { id_805 };
                    bool while_flag_807 { true };
                    do {
                      uint8_t id_808 { 0 };
                      Pointer id_809 { p_ref_82[id_808] };
                      ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 id_810 { id_809.readU8() };
                      bool let_res_811;
                      {
                        ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 leb128_83 { id_810 };
                        bool letpair_res_812;
                        {
                          auto leb128_fst_84 { std::get<0>(leb128_83) };
                          auto leb128_snd_85 { std::get<1>(leb128_83) };
                          uint8_t id_813 { 0 };
                          Void id_814 { ((void)(p_ref_82[id_813] = leb128_snd_85), VOID) };
                          (void)id_814;
                          uint8_t id_815 { 0 };
                          uint8_t id_816 { 127 };
                          uint8_t id_817 { uint8_t(leb128_fst_84 & id_816) };
                          uint32_t id_818 { uint32_t(id_817) };
                          uint8_t id_819 { 0 };
                          uint8_t id_820 { shft_ref_81[id_819] };
                          uint32_t id_821 { uint32_t(id_818 << id_820) };
                          uint8_t id_822 { 0 };
                          uint32_t id_823 { leb_ref_80[id_822] };
                          uint32_t id_824 { uint32_t(id_821 | id_823) };
                          Void id_825 { ((void)(leb_ref_80[id_815] = id_824), VOID) };
                          (void)id_825;
                          uint8_t id_826 { 0 };
                          uint8_t id_827 { 0 };
                          uint8_t id_828 { shft_ref_81[id_827] };
                          uint8_t id_829 { 7 };
                          uint8_t id_830 { uint8_t(id_828 + id_829) };
                          Void id_831 { ((void)(shft_ref_81[id_826] = id_830), VOID) };
                          (void)id_831;
                          uint8_t id_832 { 128 };
                          bool id_833 { bool(leb128_fst_84 >= id_832) };
                          letpair_res_812 = id_833;
                        }
                        let_res_811 = letpair_res_812;
                      }
                      while_flag_807 = let_res_811;
                      if (while_flag_807) {
                        (void)VOID;
                      }
                    } while (while_flag_807);
                    (void)VOID;
                    uint8_t id_834 { 0 };
                    uint32_t id_835 { leb_ref_80[id_834] };
                    Size id_836 { Size(id_835) };
                    uint8_t id_837 { 0 };
                    Pointer id_838 { p_ref_82[id_837] };
                    ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c id_839 { id_836, id_838 };
                    let_res_806 = id_839;
                  }
                  let_res_804 = let_res_806;
                }
                let_res_801 = let_res_804;
              }
              ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 let_res_840;
              {
                ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c dbytes1_86 { let_res_801 };
                ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 letpair_res_841;
                {
                  auto dbytes1_fst_87 { std::get<0>(dbytes1_86) };
                  auto dbytes1_snd_88 { std::get<1>(dbytes1_86) };
                  ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 id_842 { dbytes1_snd_88.readBytes(dbytes1_fst_87) };
                  letpair_res_841 = id_842;
                }
                let_res_840 = letpair_res_841;
              }
              ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_843;
              {
                auto dsum2_fst_90 { std::get<0>(let_res_840) };
                auto dsum2_snd_91 { std::get<1>(let_res_840) };
                ::dessser::gen::sync_msg::t* id_844 { new ::dessser::gen::sync_msg::t(std::in_place_index<2>, dsum2_fst_90) };
                ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 id_845 { id_844, dsum2_snd_91 };
                letpair_res_843 = id_845;
              }
              choose_res_798 = letpair_res_843;
            } else {
              uint16_t id_846 { 3 };
              bool id_847 { bool(dsum1_fst_63 == id_846) };
              Void id_848 { ((void)(assert(id_847)), VOID) };
              (void)id_848;
              uint32_t id_849 { 0U };
              Vec<1, uint32_t> id_850 {  id_849  };
              ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_851;
              {
                Vec<1, uint32_t> leb_ref_65 { id_850 };
                uint8_t id_852 { 0 };
                Vec<1, uint8_t> id_853 {  id_852  };
                ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_854;
                {
                  Vec<1, uint8_t> shft_ref_66 { id_853 };
                  Vec<1, Pointer> id_855 {  dsum1_snd_64  };
                  ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c let_res_856;
                  {
                    Vec<1, Pointer> p_ref_67 { id_855 };
                    bool while_flag_857 { true };
                    do {
                      uint8_t id_858 { 0 };
                      Pointer id_859 { p_ref_67[id_858] };
                      ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 id_860 { id_859.readU8() };
                      bool let_res_861;
                      {
                        ::dessser::gen::sync_msg::tb3f98ea670610d40658a618de3ec7b90 leb128_68 { id_860 };
                        bool letpair_res_862;
                        {
                          auto leb128_fst_69 { std::get<0>(leb128_68) };
                          auto leb128_snd_70 { std::get<1>(leb128_68) };
                          uint8_t id_863 { 0 };
                          Void id_864 { ((void)(p_ref_67[id_863] = leb128_snd_70), VOID) };
                          (void)id_864;
                          uint8_t id_865 { 0 };
                          uint8_t id_866 { 127 };
                          uint8_t id_867 { uint8_t(leb128_fst_69 & id_866) };
                          uint32_t id_868 { uint32_t(id_867) };
                          uint8_t id_869 { 0 };
                          uint8_t id_870 { shft_ref_66[id_869] };
                          uint32_t id_871 { uint32_t(id_868 << id_870) };
                          uint8_t id_872 { 0 };
                          uint32_t id_873 { leb_ref_65[id_872] };
                          uint32_t id_874 { uint32_t(id_871 | id_873) };
                          Void id_875 { ((void)(leb_ref_65[id_865] = id_874), VOID) };
                          (void)id_875;
                          uint8_t id_876 { 0 };
                          uint8_t id_877 { 0 };
                          uint8_t id_878 { shft_ref_66[id_877] };
                          uint8_t id_879 { 7 };
                          uint8_t id_880 { uint8_t(id_878 + id_879) };
                          Void id_881 { ((void)(shft_ref_66[id_876] = id_880), VOID) };
                          (void)id_881;
                          uint8_t id_882 { 128 };
                          bool id_883 { bool(leb128_fst_69 >= id_882) };
                          letpair_res_862 = id_883;
                        }
                        let_res_861 = letpair_res_862;
                      }
                      while_flag_857 = let_res_861;
                      if (while_flag_857) {
                        (void)VOID;
                      }
                    } while (while_flag_857);
                    (void)VOID;
                    uint8_t id_884 { 0 };
                    uint32_t id_885 { leb_ref_65[id_884] };
                    Size id_886 { Size(id_885) };
                    uint8_t id_887 { 0 };
                    Pointer id_888 { p_ref_67[id_887] };
                    ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c id_889 { id_886, id_888 };
                    let_res_856 = id_889;
                  }
                  let_res_854 = let_res_856;
                }
                let_res_851 = let_res_854;
              }
              ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 let_res_890;
              {
                ::dessser::gen::sync_msg::t8beb80162423aee37bd383e9b6834c9c dstring1_71 { let_res_851 };
                ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_891;
                {
                  auto dstring1_fst_72 { std::get<0>(dstring1_71) };
                  auto dstring1_snd_73 { std::get<1>(dstring1_71) };
                  ::dessser::gen::sync_msg::t188345aa49abd0cb47ff73fedc219f08 id_892 { dstring1_snd_73.readBytes(dstring1_fst_72) };
                  ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_893;
                  {
                    auto dstring2_fst_75 { std::get<0>(id_892) };
                    auto dstring2_snd_76 { std::get<1>(id_892) };
                    std::string id_894 { dstring2_fst_75.toString() };
                    ::dessser::gen::sync_msg::t* id_895 { new ::dessser::gen::sync_msg::t(std::in_place_index<3>, id_894) };
                    ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 id_896 { id_895, dstring2_snd_76 };
                    letpair_res_893 = id_896;
                  }
                  letpair_res_891 = letpair_res_893;
                }
                let_res_890 = letpair_res_891;
              }
              choose_res_798 = let_res_890;
            }
            choose_res_701 = choose_res_798;
          }
          choose_res_558 = choose_res_701;
        }
        letpair_res_555 = choose_res_558;
      }
      let_res_554 = letpair_res_555;
    }
    ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 letpair_res_897;
    {
      auto make_fst_159 { std::get<0>(let_res_554) };
      auto make_snd_160 { std::get<1>(let_res_554) };
      ::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23 id_898 { make_fst_159, make_snd_160 };
      letpair_res_897 = id_898;
    }
    return letpair_res_897;
  }
   };
  return fun550;
}
std::function<::dessser::gen::sync_msg::t225ef9f1e97f4882d6b6a9f870881a23(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
