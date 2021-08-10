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

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct v_940f244208f0d3b12c9ae508dcaea75c {
  *sync_key k;
  *sync_value v;
  std::string uid;
  double mtime;
  bool operator==(v_940f244208f0d3b12c9ae508dcaea75c const &other) const {
    return k == other.k && v == other.v && uid == other.uid && mtime == other.mtime;
  }
};
std::ostream &operator<<(std::ostream &os, v_940f244208f0d3b12c9ae508dcaea75c const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "v:" << r.v << ',';
  os << "uid:" << r.uid << ',';
  os << "mtime:" << r.mtime;
  os << '}';
  return os;
}

struct v_5e1953df5130fdcab794186d201fd5e8 {
  *sync_key k;
  *sync_value v;
  std::string uid;
  double mtime;
  bool can_write;
  bool can_del;
  std::string owner;
  double expiry;
  bool operator==(v_5e1953df5130fdcab794186d201fd5e8 const &other) const {
    return k == other.k && v == other.v && uid == other.uid && mtime == other.mtime && can_write == other.can_write && can_del == other.can_del && owner == other.owner && expiry == other.expiry;
  }
};
std::ostream &operator<<(std::ostream &os, v_5e1953df5130fdcab794186d201fd5e8 const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "v:" << r.v << ',';
  os << "uid:" << r.uid << ',';
  os << "mtime:" << r.mtime << ',';
  os << "can_write:" << r.can_write << ',';
  os << "can_del:" << r.can_del << ',';
  os << "owner:" << r.owner << ',';
  os << "expiry:" << r.expiry;
  os << '}';
  return os;
}

struct v_3cca14702fcf070f776a6badc4224e9d {
  *sync_key k;
  std::string owner;
  double expiry;
  bool operator==(v_3cca14702fcf070f776a6badc4224e9d const &other) const {
    return k == other.k && owner == other.owner && expiry == other.expiry;
  }
};
std::ostream &operator<<(std::ostream &os, v_3cca14702fcf070f776a6badc4224e9d const &r) {
  os << '{';
  os << "k:" << r.k << ',';
  os << "owner:" << r.owner << ',';
  os << "expiry:" << r.expiry;
  os << '}';
  return os;
}

struct t : public std::variant<
  *sync_socket,
  std::string,
  v_940f244208f0d3b12c9ae508dcaea75c,
  v_5e1953df5130fdcab794186d201fd5e8,
  *sync_key,
  v_3cca14702fcf070f776a6badc4224e9d,
  *sync_key
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
  }
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  uint16_t,
  Pointer
> v_362f9d9108a6902af48b6c83d5377ea1;

typedef std::tuple<
  *sync_socket,
  Pointer
> v_7036a8b0fbd8a7ca699aed2c44f6fdba;

typedef std::tuple<
  Size,
  Pointer
> v_41b0681ed7f1f185fd3e6c4dcdc13110;

typedef std::tuple<
  uint8_t,
  Pointer
> v_1d5843897434feb24d158f3793db9189;

typedef std::tuple<
  Bytes,
  Pointer
> f921d1e0a170c3c04148c21704db9c45;

typedef std::tuple<
  *sync_key,
  Pointer
> v_25d2fb9e36d1852487ae5e50cde3ed3c;

typedef std::tuple<
  *sync_value,
  Pointer
> v_1d33d755cf2eeb43eecb39ad040d8020;

typedef std::tuple<
  std::string,
  Pointer
> v_46a5e81c2410b000ff0adea6dc198147;

typedef std::tuple<
  uint64_t,
  Pointer
> b62e103e7915a76f45f02f7c6f667c79;

typedef std::tuple<
  double,
  Pointer
> v_41a5a8cf414de9bfdc6375241fcc910a;

typedef std::tuple<
  bool,
  Pointer
> f2a48a42f9c827f487e53ee52a4e9e2f;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey $sync_key | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" "Ptr")
      (let "ssum_dst_244" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (apply (ext-identifier sync_socket to-row-binary) (get-alt "AuthOk" (param 0)) (identifier "ssum_dst_244"))
          (if (eq (u16 1) (label-of (param 0)))
            (write-bytes
              (let "leb128_sz_265" (make-vec (string-length (get-alt "AuthErr" (param 0))))
                (let "leb128_ptr_266" (make-vec (identifier "ssum_dst_244"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_266")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_266"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_265"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_265"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_265"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_265") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_265")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_265")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_266"))))) 
              (bytes-of-string (get-alt "AuthErr" (param 0))))
            (if (eq (u16 2) (label-of (param 0)))
              (let "srec_dst_264"
                (let "srec_dst_261"
                  (let "srec_dst_260" (apply (ext-identifier sync_key to-row-binary) (get-field "k" (get-alt "SetKey" (param 0))) (identifier "ssum_dst_244"))
                    (apply (ext-identifier sync_value to-row-binary) (get-field "v" (get-alt "SetKey" (param 0))) (identifier "srec_dst_260")))
                  (write-bytes
                    (let "leb128_sz_262" (make-vec (string-length (get-field "uid" (get-alt "SetKey" (param 0)))))
                      (let "leb128_ptr_263" (make-vec (identifier "srec_dst_261"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_263")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_263"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_262"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_262"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_262"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_262") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_262")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_262")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_263"))))) 
                    (bytes-of-string (get-field "uid" (get-alt "SetKey" (param 0)))))) 
                (write-u64 little-endian (identifier "srec_dst_264") (u64-of-float (get-field "mtime" (get-alt "SetKey" (param 0))))))
              (if (eq (u16 3) (label-of (param 0)))
                (let "srec_dst_259"
                  (let "srec_dst_256"
                    (let "srec_dst_255"
                      (let "srec_dst_254"
                        (let "srec_dst_253"
                          (let "srec_dst_250"
                            (let "srec_dst_249" (apply (ext-identifier sync_key to-row-binary) (get-field "k" (get-alt "NewKey" (param 0))) (identifier "ssum_dst_244"))
                              (apply (ext-identifier sync_value to-row-binary) (get-field "v" (get-alt "NewKey" (param 0))) (identifier "srec_dst_249")))
                            (write-bytes
                              (let "leb128_sz_251" (make-vec (string-length (get-field "uid" (get-alt "NewKey" (param 0)))))
                                (let "leb128_ptr_252" (make-vec (identifier "srec_dst_250"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_252")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_252"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_251"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_251"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_251"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_251") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_251")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_251")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_252"))))) 
                              (bytes-of-string (get-field "uid" (get-alt "NewKey" (param 0)))))) 
                          (write-u64 little-endian (identifier "srec_dst_253") (u64-of-float (get-field "mtime" (get-alt "NewKey" (param 0))))))
                        (write-u8 (identifier "srec_dst_254") (u8-of-bool (get-field "can_write" (get-alt "NewKey" (param 0))))))
                      (write-u8 (identifier "srec_dst_255") (u8-of-bool (get-field "can_del" (get-alt "NewKey" (param 0))))))
                    (write-bytes
                      (let "leb128_sz_257" (make-vec (string-length (get-field "owner" (get-alt "NewKey" (param 0)))))
                        (let "leb128_ptr_258" (make-vec (identifier "srec_dst_256"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_258")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_258"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_257"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_257"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_257"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_257") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_257")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_257")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_258"))))) 
                      (bytes-of-string (get-field "owner" (get-alt "NewKey" (param 0)))))) 
                  (write-u64 little-endian (identifier "srec_dst_259") (u64-of-float (get-field "expiry" (get-alt "NewKey" (param 0))))))
                (if (eq (u16 4) (label-of (param 0))) (apply (ext-identifier sync_key to-row-binary) (get-alt "DelKey" (param 0)) (identifier "ssum_dst_244"))
                  (if (eq (u16 5) (label-of (param 0)))
                    (let "srec_dst_248"
                      (let "srec_dst_245" (apply (ext-identifier sync_key to-row-binary) (get-field "k" (get-alt "LockKey" (param 0))) (identifier "ssum_dst_244"))
                        (write-bytes
                          (let "leb128_sz_246" (make-vec (string-length (get-field "owner" (get-alt "LockKey" (param 0)))))
                            (let "leb128_ptr_247" (make-vec (identifier "srec_dst_245"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_247")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_247"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_246"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_246"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_246"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_246") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_246")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_246")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_247"))))) 
                          (bytes-of-string (get-field "owner" (get-alt "LockKey" (param 0)))))) 
                      (write-u64 little-endian (identifier "srec_dst_248") (u64-of-float (get-field "expiry" (get-alt "LockKey" (param 0))))))
                    (seq (assert (eq (label-of (param 0)) (u16 6))) (apply (ext-identifier sync_key to-row-binary) (get-alt "UnlockKey" (param 0)) (identifier "ssum_dst_244")))))))))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0.index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_244 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0.index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        std::function<Pointer(*sync_socket,Pointer)> id_8 { dessser_gen::sync_socket.to_row_binary };
        *sync_socket id_9 { std::get<0>(p_0) };
        Pointer id_10 { id_8(id_9, ssum_dst_244) };
        choose_res_7 = id_10;
      } else {
        uint16_t id_11 { 1 };
        uint16_t id_12 { uint16_t(p_0.index()) };
        bool id_13 { bool(id_11 == id_12) };
        Pointer choose_res_14;
        if (id_13) {
          std::string id_15 { std::get<1>(p_0) };
          uint32_t id_16 { (uint32_t)id_15.size() };
          Vec<1, uint32_t> id_17 {  id_16  };
          Pointer let_res_18;
          {
            Vec<1, uint32_t> leb128_sz_265 { id_17 };
            Vec<1, Pointer> id_19 {  ssum_dst_244  };
            Pointer let_res_20;
            {
              Vec<1, Pointer> leb128_ptr_266 { id_19 };
              bool while_flag_21 { true };
              do {
                uint8_t id_22 { 0 };
                uint8_t id_23 { 0 };
                Pointer id_24 { leb128_ptr_266[id_23] };
                uint32_t id_25 { 128U };
                uint8_t id_26 { 0 };
                uint32_t id_27 { leb128_sz_265[id_26] };
                bool id_28 { bool(id_25 > id_27) };
                uint8_t choose_res_29;
                if (id_28) {
                  uint8_t id_30 { 0 };
                  uint32_t id_31 { leb128_sz_265[id_30] };
                  uint8_t id_32 { uint8_t(id_31) };
                  choose_res_29 = id_32;
                } else {
                  uint8_t id_33 { 0 };
                  uint32_t id_34 { leb128_sz_265[id_33] };
                  uint8_t id_35 { uint8_t(id_34) };
                  uint8_t id_36 { 128 };
                  uint8_t id_37 { uint8_t(id_35 | id_36) };
                  choose_res_29 = id_37;
                }
                Pointer id_38 { id_24.writeU8(choose_res_29) };
                Void id_39 { ((void)(leb128_ptr_266[id_22] = id_38), VOID) };
                uint8_t id_40 { 0 };
                uint8_t id_41 { 0 };
                uint32_t id_42 { leb128_sz_265[id_41] };
                uint8_t id_43 { 7 };
                uint32_t id_44 { uint32_t(id_42 >> id_43) };
                Void id_45 { ((void)(leb128_sz_265[id_40] = id_44), VOID) };
                uint8_t id_46 { 0 };
                uint32_t id_47 { leb128_sz_265[id_46] };
                uint32_t id_48 { 0U };
                bool id_49 { bool(id_47 > id_48) };
                while_flag_21 = id_49;
                if (while_flag_21) {
                }
              } while (while_flag_21);
              uint8_t id_50 { 0 };
              Pointer id_51 { leb128_ptr_266[id_50] };
              let_res_20 = id_51;
            }
            let_res_18 = let_res_20;
          }
          std::string id_52 { std::get<1>(p_0) };
          Bytes id_53 { id_52 };
          Pointer id_54 { let_res_18.writeBytes(id_53) };
          choose_res_14 = id_54;
        } else {
          uint16_t id_55 { 2 };
          uint16_t id_56 { uint16_t(p_0.index()) };
          bool id_57 { bool(id_55 == id_56) };
          Pointer choose_res_58;
          if (id_57) {
            std::function<Pointer(*sync_key,Pointer)> id_59 { dessser_gen::sync_key.to_row_binary };
            v_940f244208f0d3b12c9ae508dcaea75c id_60 { std::get<2>(p_0) };
            *sync_key id_61 { id_60.k };
            Pointer id_62 { id_59(id_61, ssum_dst_244) };
            Pointer let_res_63;
            {
              Pointer srec_dst_260 { id_62 };
              std::function<Pointer(*sync_value,Pointer)> id_64 { dessser_gen::sync_value.to_row_binary };
              v_940f244208f0d3b12c9ae508dcaea75c id_65 { std::get<2>(p_0) };
              *sync_value id_66 { id_65.v };
              Pointer id_67 { id_64(id_66, srec_dst_260) };
              let_res_63 = id_67;
            }
            Pointer let_res_68;
            {
              Pointer srec_dst_261 { let_res_63 };
              v_940f244208f0d3b12c9ae508dcaea75c id_69 { std::get<2>(p_0) };
              std::string id_70 { id_69.uid };
              uint32_t id_71 { (uint32_t)id_70.size() };
              Vec<1, uint32_t> id_72 {  id_71  };
              Pointer let_res_73;
              {
                Vec<1, uint32_t> leb128_sz_262 { id_72 };
                Vec<1, Pointer> id_74 {  srec_dst_261  };
                Pointer let_res_75;
                {
                  Vec<1, Pointer> leb128_ptr_263 { id_74 };
                  bool while_flag_76 { true };
                  do {
                    uint8_t id_77 { 0 };
                    uint8_t id_78 { 0 };
                    Pointer id_79 { leb128_ptr_263[id_78] };
                    uint32_t id_80 { 128U };
                    uint8_t id_81 { 0 };
                    uint32_t id_82 { leb128_sz_262[id_81] };
                    bool id_83 { bool(id_80 > id_82) };
                    uint8_t choose_res_84;
                    if (id_83) {
                      uint8_t id_85 { 0 };
                      uint32_t id_86 { leb128_sz_262[id_85] };
                      uint8_t id_87 { uint8_t(id_86) };
                      choose_res_84 = id_87;
                    } else {
                      uint8_t id_88 { 0 };
                      uint32_t id_89 { leb128_sz_262[id_88] };
                      uint8_t id_90 { uint8_t(id_89) };
                      uint8_t id_91 { 128 };
                      uint8_t id_92 { uint8_t(id_90 | id_91) };
                      choose_res_84 = id_92;
                    }
                    Pointer id_93 { id_79.writeU8(choose_res_84) };
                    Void id_94 { ((void)(leb128_ptr_263[id_77] = id_93), VOID) };
                    uint8_t id_95 { 0 };
                    uint8_t id_96 { 0 };
                    uint32_t id_97 { leb128_sz_262[id_96] };
                    uint8_t id_98 { 7 };
                    uint32_t id_99 { uint32_t(id_97 >> id_98) };
                    Void id_100 { ((void)(leb128_sz_262[id_95] = id_99), VOID) };
                    uint8_t id_101 { 0 };
                    uint32_t id_102 { leb128_sz_262[id_101] };
                    uint32_t id_103 { 0U };
                    bool id_104 { bool(id_102 > id_103) };
                    while_flag_76 = id_104;
                    if (while_flag_76) {
                    }
                  } while (while_flag_76);
                  uint8_t id_105 { 0 };
                  Pointer id_106 { leb128_ptr_263[id_105] };
                  let_res_75 = id_106;
                }
                let_res_73 = let_res_75;
              }
              v_940f244208f0d3b12c9ae508dcaea75c id_107 { std::get<2>(p_0) };
              std::string id_108 { id_107.uid };
              Bytes id_109 { id_108 };
              Pointer id_110 { let_res_73.writeBytes(id_109) };
              let_res_68 = id_110;
            }
            Pointer let_res_111;
            {
              Pointer srec_dst_264 { let_res_68 };
              v_940f244208f0d3b12c9ae508dcaea75c id_112 { std::get<2>(p_0) };
              double id_113 { id_112.mtime };
              uint64_t id_114 { qword_of_float(id_113) };
              Pointer id_115 { srec_dst_264.writeU64Le(id_114) };
              let_res_111 = id_115;
            }
            choose_res_58 = let_res_111;
          } else {
            uint16_t id_116 { 3 };
            uint16_t id_117 { uint16_t(p_0.index()) };
            bool id_118 { bool(id_116 == id_117) };
            Pointer choose_res_119;
            if (id_118) {
              std::function<Pointer(*sync_key,Pointer)> id_120 { dessser_gen::sync_key.to_row_binary };
              v_5e1953df5130fdcab794186d201fd5e8 id_121 { std::get<3>(p_0) };
              *sync_key id_122 { id_121.k };
              Pointer id_123 { id_120(id_122, ssum_dst_244) };
              Pointer let_res_124;
              {
                Pointer srec_dst_249 { id_123 };
                std::function<Pointer(*sync_value,Pointer)> id_125 { dessser_gen::sync_value.to_row_binary };
                v_5e1953df5130fdcab794186d201fd5e8 id_126 { std::get<3>(p_0) };
                *sync_value id_127 { id_126.v };
                Pointer id_128 { id_125(id_127, srec_dst_249) };
                let_res_124 = id_128;
              }
              Pointer let_res_129;
              {
                Pointer srec_dst_250 { let_res_124 };
                v_5e1953df5130fdcab794186d201fd5e8 id_130 { std::get<3>(p_0) };
                std::string id_131 { id_130.uid };
                uint32_t id_132 { (uint32_t)id_131.size() };
                Vec<1, uint32_t> id_133 {  id_132  };
                Pointer let_res_134;
                {
                  Vec<1, uint32_t> leb128_sz_251 { id_133 };
                  Vec<1, Pointer> id_135 {  srec_dst_250  };
                  Pointer let_res_136;
                  {
                    Vec<1, Pointer> leb128_ptr_252 { id_135 };
                    bool while_flag_137 { true };
                    do {
                      uint8_t id_138 { 0 };
                      uint8_t id_139 { 0 };
                      Pointer id_140 { leb128_ptr_252[id_139] };
                      uint32_t id_141 { 128U };
                      uint8_t id_142 { 0 };
                      uint32_t id_143 { leb128_sz_251[id_142] };
                      bool id_144 { bool(id_141 > id_143) };
                      uint8_t choose_res_145;
                      if (id_144) {
                        uint8_t id_146 { 0 };
                        uint32_t id_147 { leb128_sz_251[id_146] };
                        uint8_t id_148 { uint8_t(id_147) };
                        choose_res_145 = id_148;
                      } else {
                        uint8_t id_149 { 0 };
                        uint32_t id_150 { leb128_sz_251[id_149] };
                        uint8_t id_151 { uint8_t(id_150) };
                        uint8_t id_152 { 128 };
                        uint8_t id_153 { uint8_t(id_151 | id_152) };
                        choose_res_145 = id_153;
                      }
                      Pointer id_154 { id_140.writeU8(choose_res_145) };
                      Void id_155 { ((void)(leb128_ptr_252[id_138] = id_154), VOID) };
                      uint8_t id_156 { 0 };
                      uint8_t id_157 { 0 };
                      uint32_t id_158 { leb128_sz_251[id_157] };
                      uint8_t id_159 { 7 };
                      uint32_t id_160 { uint32_t(id_158 >> id_159) };
                      Void id_161 { ((void)(leb128_sz_251[id_156] = id_160), VOID) };
                      uint8_t id_162 { 0 };
                      uint32_t id_163 { leb128_sz_251[id_162] };
                      uint32_t id_164 { 0U };
                      bool id_165 { bool(id_163 > id_164) };
                      while_flag_137 = id_165;
                      if (while_flag_137) {
                      }
                    } while (while_flag_137);
                    uint8_t id_166 { 0 };
                    Pointer id_167 { leb128_ptr_252[id_166] };
                    let_res_136 = id_167;
                  }
                  let_res_134 = let_res_136;
                }
                v_5e1953df5130fdcab794186d201fd5e8 id_168 { std::get<3>(p_0) };
                std::string id_169 { id_168.uid };
                Bytes id_170 { id_169 };
                Pointer id_171 { let_res_134.writeBytes(id_170) };
                let_res_129 = id_171;
              }
              Pointer let_res_172;
              {
                Pointer srec_dst_253 { let_res_129 };
                v_5e1953df5130fdcab794186d201fd5e8 id_173 { std::get<3>(p_0) };
                double id_174 { id_173.mtime };
                uint64_t id_175 { qword_of_float(id_174) };
                Pointer id_176 { srec_dst_253.writeU64Le(id_175) };
                let_res_172 = id_176;
              }
              Pointer let_res_177;
              {
                Pointer srec_dst_254 { let_res_172 };
                v_5e1953df5130fdcab794186d201fd5e8 id_178 { std::get<3>(p_0) };
                bool id_179 { id_178.can_write };
                uint8_t id_180 { uint8_t(id_179) };
                Pointer id_181 { srec_dst_254.writeU8(id_180) };
                let_res_177 = id_181;
              }
              Pointer let_res_182;
              {
                Pointer srec_dst_255 { let_res_177 };
                v_5e1953df5130fdcab794186d201fd5e8 id_183 { std::get<3>(p_0) };
                bool id_184 { id_183.can_del };
                uint8_t id_185 { uint8_t(id_184) };
                Pointer id_186 { srec_dst_255.writeU8(id_185) };
                let_res_182 = id_186;
              }
              Pointer let_res_187;
              {
                Pointer srec_dst_256 { let_res_182 };
                v_5e1953df5130fdcab794186d201fd5e8 id_188 { std::get<3>(p_0) };
                std::string id_189 { id_188.owner };
                uint32_t id_190 { (uint32_t)id_189.size() };
                Vec<1, uint32_t> id_191 {  id_190  };
                Pointer let_res_192;
                {
                  Vec<1, uint32_t> leb128_sz_257 { id_191 };
                  Vec<1, Pointer> id_193 {  srec_dst_256  };
                  Pointer let_res_194;
                  {
                    Vec<1, Pointer> leb128_ptr_258 { id_193 };
                    bool while_flag_195 { true };
                    do {
                      uint8_t id_196 { 0 };
                      uint8_t id_197 { 0 };
                      Pointer id_198 { leb128_ptr_258[id_197] };
                      uint32_t id_199 { 128U };
                      uint8_t id_200 { 0 };
                      uint32_t id_201 { leb128_sz_257[id_200] };
                      bool id_202 { bool(id_199 > id_201) };
                      uint8_t choose_res_203;
                      if (id_202) {
                        uint8_t id_204 { 0 };
                        uint32_t id_205 { leb128_sz_257[id_204] };
                        uint8_t id_206 { uint8_t(id_205) };
                        choose_res_203 = id_206;
                      } else {
                        uint8_t id_207 { 0 };
                        uint32_t id_208 { leb128_sz_257[id_207] };
                        uint8_t id_209 { uint8_t(id_208) };
                        uint8_t id_210 { 128 };
                        uint8_t id_211 { uint8_t(id_209 | id_210) };
                        choose_res_203 = id_211;
                      }
                      Pointer id_212 { id_198.writeU8(choose_res_203) };
                      Void id_213 { ((void)(leb128_ptr_258[id_196] = id_212), VOID) };
                      uint8_t id_214 { 0 };
                      uint8_t id_215 { 0 };
                      uint32_t id_216 { leb128_sz_257[id_215] };
                      uint8_t id_217 { 7 };
                      uint32_t id_218 { uint32_t(id_216 >> id_217) };
                      Void id_219 { ((void)(leb128_sz_257[id_214] = id_218), VOID) };
                      uint8_t id_220 { 0 };
                      uint32_t id_221 { leb128_sz_257[id_220] };
                      uint32_t id_222 { 0U };
                      bool id_223 { bool(id_221 > id_222) };
                      while_flag_195 = id_223;
                      if (while_flag_195) {
                      }
                    } while (while_flag_195);
                    uint8_t id_224 { 0 };
                    Pointer id_225 { leb128_ptr_258[id_224] };
                    let_res_194 = id_225;
                  }
                  let_res_192 = let_res_194;
                }
                v_5e1953df5130fdcab794186d201fd5e8 id_226 { std::get<3>(p_0) };
                std::string id_227 { id_226.owner };
                Bytes id_228 { id_227 };
                Pointer id_229 { let_res_192.writeBytes(id_228) };
                let_res_187 = id_229;
              }
              Pointer let_res_230;
              {
                Pointer srec_dst_259 { let_res_187 };
                v_5e1953df5130fdcab794186d201fd5e8 id_231 { std::get<3>(p_0) };
                double id_232 { id_231.expiry };
                uint64_t id_233 { qword_of_float(id_232) };
                Pointer id_234 { srec_dst_259.writeU64Le(id_233) };
                let_res_230 = id_234;
              }
              choose_res_119 = let_res_230;
            } else {
              uint16_t id_235 { 4 };
              uint16_t id_236 { uint16_t(p_0.index()) };
              bool id_237 { bool(id_235 == id_236) };
              Pointer choose_res_238;
              if (id_237) {
                std::function<Pointer(*sync_key,Pointer)> id_239 { dessser_gen::sync_key.to_row_binary };
                *sync_key id_240 { std::get<4>(p_0) };
                Pointer id_241 { id_239(id_240, ssum_dst_244) };
                choose_res_238 = id_241;
              } else {
                uint16_t id_242 { 5 };
                uint16_t id_243 { uint16_t(p_0.index()) };
                bool id_244 { bool(id_242 == id_243) };
                Pointer choose_res_245;
                if (id_244) {
                  std::function<Pointer(*sync_key,Pointer)> id_246 { dessser_gen::sync_key.to_row_binary };
                  v_3cca14702fcf070f776a6badc4224e9d id_247 { std::get<5>(p_0) };
                  *sync_key id_248 { id_247.k };
                  Pointer id_249 { id_246(id_248, ssum_dst_244) };
                  Pointer let_res_250;
                  {
                    Pointer srec_dst_245 { id_249 };
                    v_3cca14702fcf070f776a6badc4224e9d id_251 { std::get<5>(p_0) };
                    std::string id_252 { id_251.owner };
                    uint32_t id_253 { (uint32_t)id_252.size() };
                    Vec<1, uint32_t> id_254 {  id_253  };
                    Pointer let_res_255;
                    {
                      Vec<1, uint32_t> leb128_sz_246 { id_254 };
                      Vec<1, Pointer> id_256 {  srec_dst_245  };
                      Pointer let_res_257;
                      {
                        Vec<1, Pointer> leb128_ptr_247 { id_256 };
                        bool while_flag_258 { true };
                        do {
                          uint8_t id_259 { 0 };
                          uint8_t id_260 { 0 };
                          Pointer id_261 { leb128_ptr_247[id_260] };
                          uint32_t id_262 { 128U };
                          uint8_t id_263 { 0 };
                          uint32_t id_264 { leb128_sz_246[id_263] };
                          bool id_265 { bool(id_262 > id_264) };
                          uint8_t choose_res_266;
                          if (id_265) {
                            uint8_t id_267 { 0 };
                            uint32_t id_268 { leb128_sz_246[id_267] };
                            uint8_t id_269 { uint8_t(id_268) };
                            choose_res_266 = id_269;
                          } else {
                            uint8_t id_270 { 0 };
                            uint32_t id_271 { leb128_sz_246[id_270] };
                            uint8_t id_272 { uint8_t(id_271) };
                            uint8_t id_273 { 128 };
                            uint8_t id_274 { uint8_t(id_272 | id_273) };
                            choose_res_266 = id_274;
                          }
                          Pointer id_275 { id_261.writeU8(choose_res_266) };
                          Void id_276 { ((void)(leb128_ptr_247[id_259] = id_275), VOID) };
                          uint8_t id_277 { 0 };
                          uint8_t id_278 { 0 };
                          uint32_t id_279 { leb128_sz_246[id_278] };
                          uint8_t id_280 { 7 };
                          uint32_t id_281 { uint32_t(id_279 >> id_280) };
                          Void id_282 { ((void)(leb128_sz_246[id_277] = id_281), VOID) };
                          uint8_t id_283 { 0 };
                          uint32_t id_284 { leb128_sz_246[id_283] };
                          uint32_t id_285 { 0U };
                          bool id_286 { bool(id_284 > id_285) };
                          while_flag_258 = id_286;
                          if (while_flag_258) {
                          }
                        } while (while_flag_258);
                        uint8_t id_287 { 0 };
                        Pointer id_288 { leb128_ptr_247[id_287] };
                        let_res_257 = id_288;
                      }
                      let_res_255 = let_res_257;
                    }
                    v_3cca14702fcf070f776a6badc4224e9d id_289 { std::get<5>(p_0) };
                    std::string id_290 { id_289.owner };
                    Bytes id_291 { id_290 };
                    Pointer id_292 { let_res_255.writeBytes(id_291) };
                    let_res_250 = id_292;
                  }
                  Pointer let_res_293;
                  {
                    Pointer srec_dst_248 { let_res_250 };
                    v_3cca14702fcf070f776a6badc4224e9d id_294 { std::get<5>(p_0) };
                    double id_295 { id_294.expiry };
                    uint64_t id_296 { qword_of_float(id_295) };
                    Pointer id_297 { srec_dst_248.writeU64Le(id_296) };
                    let_res_293 = id_297;
                  }
                  choose_res_245 = let_res_293;
                } else {
                  uint16_t id_298 { uint16_t(p_0.index()) };
                  uint16_t id_299 { 6 };
                  bool id_300 { bool(id_298 == id_299) };
                  Void id_301 { ((void)(assert(id_300)), VOID) };
                  std::function<Pointer(*sync_key,Pointer)> id_302 { dessser_gen::sync_key.to_row_binary };
                  *sync_key id_303 { std::get<6>(p_0) };
                  Pointer id_304 { id_302(id_303, ssum_dst_244) };
                  choose_res_245 = id_304;
                }
                choose_res_238 = choose_res_245;
              }
              choose_res_119 = choose_res_238;
            }
            choose_res_58 = choose_res_119;
          }
          choose_res_14 = choose_res_58;
        }
        choose_res_7 = choose_res_14;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey $sync_key | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]")
      (if (eq (u16 0) (label-of (param 0))) (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (get-alt "AuthOk" (param 0))))
        (if (eq (u16 1) (label-of (param 0)))
          (add (size 2)
            (add
              (let "n_ref_241" (make-vec (string-length (get-alt "AuthErr" (param 0))))
                (let "lebsz_ref_242" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_241")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_242")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_242") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_242")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_242")))))) 
              (size-of-u32 (string-length (get-alt "AuthErr" (param 0))))))
          (if (eq (u16 2) (label-of (param 0)))
            (add
              (let "sz_235"
                (let "sz_234" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-field "k" (get-alt "SetKey" (param 0)))))
                  (add (identifier "sz_234") (apply (ext-identifier sync_value sersize-of-row-binary) (get-field "v" (get-alt "SetKey" (param 0))))))
                (add (identifier "sz_235")
                  (add
                    (let "n_ref_237" (make-vec (string-length (get-field "uid" (get-alt "SetKey" (param 0)))))
                      (let "lebsz_ref_238" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_237")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_238")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_238") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_238")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_238")))))) 
                    (size-of-u32 (string-length (get-field "uid" (get-alt "SetKey" (param 0)))))))) 
              (size 8))
            (if (eq (u16 3) (label-of (param 0)))
              (add
                (let "sz_228"
                  (add
                    (add
                      (add
                        (let "sz_221"
                          (let "sz_220" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-field "k" (get-alt "NewKey" (param 0)))))
                            (add (identifier "sz_220") (apply (ext-identifier sync_value sersize-of-row-binary) (get-field "v" (get-alt "NewKey" (param 0))))))
                          (add (identifier "sz_221")
                            (add
                              (let "n_ref_223" (make-vec (string-length (get-field "uid" (get-alt "NewKey" (param 0)))))
                                (let "lebsz_ref_224" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_223")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_224")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_224") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_224")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_224")))))) 
                              (size-of-u32 (string-length (get-field "uid" (get-alt "NewKey" (param 0)))))))) 
                        (size 8)) (size 1)) (size 1))
                  (add (identifier "sz_228")
                    (add
                      (let "n_ref_230" (make-vec (string-length (get-field "owner" (get-alt "NewKey" (param 0)))))
                        (let "lebsz_ref_231" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_230")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_231")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_231") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_231")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_231")))))) 
                      (size-of-u32 (string-length (get-field "owner" (get-alt "NewKey" (param 0)))))))) 
                (size 8))
              (if (eq (u16 4) (label-of (param 0))) (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-alt "DelKey" (param 0))))
                (if (eq (u16 5) (label-of (param 0)))
                  (add
                    (let "sz_214" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-field "k" (get-alt "LockKey" (param 0)))))
                      (add (identifier "sz_214")
                        (add
                          (let "n_ref_216" (make-vec (string-length (get-field "owner" (get-alt "LockKey" (param 0)))))
                            (let "lebsz_ref_217" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_216")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_217")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_217") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_217")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_217")))))) 
                          (size-of-u32 (string-length (get-field "owner" (get-alt "LockKey" (param 0)))))))) 
                    (size 8)) (seq (assert (eq (label-of (param 0)) (u16 6))) (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-alt "UnlockKey" (param 0))))))))))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun305 { [&fun305](t p_0) {
    uint16_t id_306 { 0 };
    uint16_t id_307 { uint16_t(p_0.index()) };
    bool id_308 { bool(id_306 == id_307) };
    Size choose_res_309;
    if (id_308) {
      Size id_310 { 2UL };
      std::function<Size(*sync_socket)> id_311 { dessser_gen::sync_socket.sersize_of_row_binary };
      *sync_socket id_312 { std::get<0>(p_0) };
      Size id_313 { id_311(id_312) };
      Size id_314 { Size(id_310 + id_313) };
      choose_res_309 = id_314;
    } else {
      uint16_t id_315 { 1 };
      uint16_t id_316 { uint16_t(p_0.index()) };
      bool id_317 { bool(id_315 == id_316) };
      Size choose_res_318;
      if (id_317) {
        Size id_319 { 2UL };
        std::string id_320 { std::get<1>(p_0) };
        uint32_t id_321 { (uint32_t)id_320.size() };
        Vec<1, uint32_t> id_322 {  id_321  };
        Size let_res_323;
        {
          Vec<1, uint32_t> n_ref_241 { id_322 };
          uint32_t id_324 { 1U };
          Vec<1, uint32_t> id_325 {  id_324  };
          Size let_res_326;
          {
            Vec<1, uint32_t> lebsz_ref_242 { id_325 };
            bool while_flag_327 { true };
            do {
              uint8_t id_328 { 0 };
              uint32_t id_329 { n_ref_241[id_328] };
              uint8_t id_330 { 0 };
              uint32_t id_331 { lebsz_ref_242[id_330] };
              uint8_t id_332 { 7 };
              uint32_t id_333 { uint32_t(id_331 << id_332) };
              bool id_334 { bool(id_329 >= id_333) };
              while_flag_327 = id_334;
              if (while_flag_327) {
                uint8_t id_335 { 0 };
                uint8_t id_336 { 0 };
                uint32_t id_337 { lebsz_ref_242[id_336] };
                uint32_t id_338 { 1U };
                uint32_t id_339 { uint32_t(id_337 + id_338) };
                Void id_340 { ((void)(lebsz_ref_242[id_335] = id_339), VOID) };
              }
            } while (while_flag_327);
            uint8_t id_341 { 0 };
            uint32_t id_342 { lebsz_ref_242[id_341] };
            Size id_343 { Size(id_342) };
            let_res_326 = id_343;
          }
          let_res_323 = let_res_326;
        }
        std::string id_344 { std::get<1>(p_0) };
        uint32_t id_345 { (uint32_t)id_344.size() };
        Size id_346 { Size(id_345) };
        Size id_347 { Size(let_res_323 + id_346) };
        Size id_348 { Size(id_319 + id_347) };
        choose_res_318 = id_348;
      } else {
        uint16_t id_349 { 2 };
        uint16_t id_350 { uint16_t(p_0.index()) };
        bool id_351 { bool(id_349 == id_350) };
        Size choose_res_352;
        if (id_351) {
          Size id_353 { 2UL };
          std::function<Size(*sync_key)> id_354 { dessser_gen::sync_key.sersize_of_row_binary };
          v_940f244208f0d3b12c9ae508dcaea75c id_355 { std::get<2>(p_0) };
          *sync_key id_356 { id_355.k };
          Size id_357 { id_354(id_356) };
          Size id_358 { Size(id_353 + id_357) };
          Size let_res_359;
          {
            Size sz_234 { id_358 };
            std::function<Size(*sync_value)> id_360 { dessser_gen::sync_value.sersize_of_row_binary };
            v_940f244208f0d3b12c9ae508dcaea75c id_361 { std::get<2>(p_0) };
            *sync_value id_362 { id_361.v };
            Size id_363 { id_360(id_362) };
            Size id_364 { Size(sz_234 + id_363) };
            let_res_359 = id_364;
          }
          Size let_res_365;
          {
            Size sz_235 { let_res_359 };
            v_940f244208f0d3b12c9ae508dcaea75c id_366 { std::get<2>(p_0) };
            std::string id_367 { id_366.uid };
            uint32_t id_368 { (uint32_t)id_367.size() };
            Vec<1, uint32_t> id_369 {  id_368  };
            Size let_res_370;
            {
              Vec<1, uint32_t> n_ref_237 { id_369 };
              uint32_t id_371 { 1U };
              Vec<1, uint32_t> id_372 {  id_371  };
              Size let_res_373;
              {
                Vec<1, uint32_t> lebsz_ref_238 { id_372 };
                bool while_flag_374 { true };
                do {
                  uint8_t id_375 { 0 };
                  uint32_t id_376 { n_ref_237[id_375] };
                  uint8_t id_377 { 0 };
                  uint32_t id_378 { lebsz_ref_238[id_377] };
                  uint8_t id_379 { 7 };
                  uint32_t id_380 { uint32_t(id_378 << id_379) };
                  bool id_381 { bool(id_376 >= id_380) };
                  while_flag_374 = id_381;
                  if (while_flag_374) {
                    uint8_t id_382 { 0 };
                    uint8_t id_383 { 0 };
                    uint32_t id_384 { lebsz_ref_238[id_383] };
                    uint32_t id_385 { 1U };
                    uint32_t id_386 { uint32_t(id_384 + id_385) };
                    Void id_387 { ((void)(lebsz_ref_238[id_382] = id_386), VOID) };
                  }
                } while (while_flag_374);
                uint8_t id_388 { 0 };
                uint32_t id_389 { lebsz_ref_238[id_388] };
                Size id_390 { Size(id_389) };
                let_res_373 = id_390;
              }
              let_res_370 = let_res_373;
            }
            v_940f244208f0d3b12c9ae508dcaea75c id_391 { std::get<2>(p_0) };
            std::string id_392 { id_391.uid };
            uint32_t id_393 { (uint32_t)id_392.size() };
            Size id_394 { Size(id_393) };
            Size id_395 { Size(let_res_370 + id_394) };
            Size id_396 { Size(sz_235 + id_395) };
            let_res_365 = id_396;
          }
          Size id_397 { 8UL };
          Size id_398 { Size(let_res_365 + id_397) };
          choose_res_352 = id_398;
        } else {
          uint16_t id_399 { 3 };
          uint16_t id_400 { uint16_t(p_0.index()) };
          bool id_401 { bool(id_399 == id_400) };
          Size choose_res_402;
          if (id_401) {
            Size id_403 { 2UL };
            std::function<Size(*sync_key)> id_404 { dessser_gen::sync_key.sersize_of_row_binary };
            v_5e1953df5130fdcab794186d201fd5e8 id_405 { std::get<3>(p_0) };
            *sync_key id_406 { id_405.k };
            Size id_407 { id_404(id_406) };
            Size id_408 { Size(id_403 + id_407) };
            Size let_res_409;
            {
              Size sz_220 { id_408 };
              std::function<Size(*sync_value)> id_410 { dessser_gen::sync_value.sersize_of_row_binary };
              v_5e1953df5130fdcab794186d201fd5e8 id_411 { std::get<3>(p_0) };
              *sync_value id_412 { id_411.v };
              Size id_413 { id_410(id_412) };
              Size id_414 { Size(sz_220 + id_413) };
              let_res_409 = id_414;
            }
            Size let_res_415;
            {
              Size sz_221 { let_res_409 };
              v_5e1953df5130fdcab794186d201fd5e8 id_416 { std::get<3>(p_0) };
              std::string id_417 { id_416.uid };
              uint32_t id_418 { (uint32_t)id_417.size() };
              Vec<1, uint32_t> id_419 {  id_418  };
              Size let_res_420;
              {
                Vec<1, uint32_t> n_ref_223 { id_419 };
                uint32_t id_421 { 1U };
                Vec<1, uint32_t> id_422 {  id_421  };
                Size let_res_423;
                {
                  Vec<1, uint32_t> lebsz_ref_224 { id_422 };
                  bool while_flag_424 { true };
                  do {
                    uint8_t id_425 { 0 };
                    uint32_t id_426 { n_ref_223[id_425] };
                    uint8_t id_427 { 0 };
                    uint32_t id_428 { lebsz_ref_224[id_427] };
                    uint8_t id_429 { 7 };
                    uint32_t id_430 { uint32_t(id_428 << id_429) };
                    bool id_431 { bool(id_426 >= id_430) };
                    while_flag_424 = id_431;
                    if (while_flag_424) {
                      uint8_t id_432 { 0 };
                      uint8_t id_433 { 0 };
                      uint32_t id_434 { lebsz_ref_224[id_433] };
                      uint32_t id_435 { 1U };
                      uint32_t id_436 { uint32_t(id_434 + id_435) };
                      Void id_437 { ((void)(lebsz_ref_224[id_432] = id_436), VOID) };
                    }
                  } while (while_flag_424);
                  uint8_t id_438 { 0 };
                  uint32_t id_439 { lebsz_ref_224[id_438] };
                  Size id_440 { Size(id_439) };
                  let_res_423 = id_440;
                }
                let_res_420 = let_res_423;
              }
              v_5e1953df5130fdcab794186d201fd5e8 id_441 { std::get<3>(p_0) };
              std::string id_442 { id_441.uid };
              uint32_t id_443 { (uint32_t)id_442.size() };
              Size id_444 { Size(id_443) };
              Size id_445 { Size(let_res_420 + id_444) };
              Size id_446 { Size(sz_221 + id_445) };
              let_res_415 = id_446;
            }
            Size id_447 { 8UL };
            Size id_448 { Size(let_res_415 + id_447) };
            Size id_449 { 1UL };
            Size id_450 { Size(id_448 + id_449) };
            Size id_451 { 1UL };
            Size id_452 { Size(id_450 + id_451) };
            Size let_res_453;
            {
              Size sz_228 { id_452 };
              v_5e1953df5130fdcab794186d201fd5e8 id_454 { std::get<3>(p_0) };
              std::string id_455 { id_454.owner };
              uint32_t id_456 { (uint32_t)id_455.size() };
              Vec<1, uint32_t> id_457 {  id_456  };
              Size let_res_458;
              {
                Vec<1, uint32_t> n_ref_230 { id_457 };
                uint32_t id_459 { 1U };
                Vec<1, uint32_t> id_460 {  id_459  };
                Size let_res_461;
                {
                  Vec<1, uint32_t> lebsz_ref_231 { id_460 };
                  bool while_flag_462 { true };
                  do {
                    uint8_t id_463 { 0 };
                    uint32_t id_464 { n_ref_230[id_463] };
                    uint8_t id_465 { 0 };
                    uint32_t id_466 { lebsz_ref_231[id_465] };
                    uint8_t id_467 { 7 };
                    uint32_t id_468 { uint32_t(id_466 << id_467) };
                    bool id_469 { bool(id_464 >= id_468) };
                    while_flag_462 = id_469;
                    if (while_flag_462) {
                      uint8_t id_470 { 0 };
                      uint8_t id_471 { 0 };
                      uint32_t id_472 { lebsz_ref_231[id_471] };
                      uint32_t id_473 { 1U };
                      uint32_t id_474 { uint32_t(id_472 + id_473) };
                      Void id_475 { ((void)(lebsz_ref_231[id_470] = id_474), VOID) };
                    }
                  } while (while_flag_462);
                  uint8_t id_476 { 0 };
                  uint32_t id_477 { lebsz_ref_231[id_476] };
                  Size id_478 { Size(id_477) };
                  let_res_461 = id_478;
                }
                let_res_458 = let_res_461;
              }
              v_5e1953df5130fdcab794186d201fd5e8 id_479 { std::get<3>(p_0) };
              std::string id_480 { id_479.owner };
              uint32_t id_481 { (uint32_t)id_480.size() };
              Size id_482 { Size(id_481) };
              Size id_483 { Size(let_res_458 + id_482) };
              Size id_484 { Size(sz_228 + id_483) };
              let_res_453 = id_484;
            }
            Size id_485 { 8UL };
            Size id_486 { Size(let_res_453 + id_485) };
            choose_res_402 = id_486;
          } else {
            uint16_t id_487 { 4 };
            uint16_t id_488 { uint16_t(p_0.index()) };
            bool id_489 { bool(id_487 == id_488) };
            Size choose_res_490;
            if (id_489) {
              Size id_491 { 2UL };
              std::function<Size(*sync_key)> id_492 { dessser_gen::sync_key.sersize_of_row_binary };
              *sync_key id_493 { std::get<4>(p_0) };
              Size id_494 { id_492(id_493) };
              Size id_495 { Size(id_491 + id_494) };
              choose_res_490 = id_495;
            } else {
              uint16_t id_496 { 5 };
              uint16_t id_497 { uint16_t(p_0.index()) };
              bool id_498 { bool(id_496 == id_497) };
              Size choose_res_499;
              if (id_498) {
                Size id_500 { 2UL };
                std::function<Size(*sync_key)> id_501 { dessser_gen::sync_key.sersize_of_row_binary };
                v_3cca14702fcf070f776a6badc4224e9d id_502 { std::get<5>(p_0) };
                *sync_key id_503 { id_502.k };
                Size id_504 { id_501(id_503) };
                Size id_505 { Size(id_500 + id_504) };
                Size let_res_506;
                {
                  Size sz_214 { id_505 };
                  v_3cca14702fcf070f776a6badc4224e9d id_507 { std::get<5>(p_0) };
                  std::string id_508 { id_507.owner };
                  uint32_t id_509 { (uint32_t)id_508.size() };
                  Vec<1, uint32_t> id_510 {  id_509  };
                  Size let_res_511;
                  {
                    Vec<1, uint32_t> n_ref_216 { id_510 };
                    uint32_t id_512 { 1U };
                    Vec<1, uint32_t> id_513 {  id_512  };
                    Size let_res_514;
                    {
                      Vec<1, uint32_t> lebsz_ref_217 { id_513 };
                      bool while_flag_515 { true };
                      do {
                        uint8_t id_516 { 0 };
                        uint32_t id_517 { n_ref_216[id_516] };
                        uint8_t id_518 { 0 };
                        uint32_t id_519 { lebsz_ref_217[id_518] };
                        uint8_t id_520 { 7 };
                        uint32_t id_521 { uint32_t(id_519 << id_520) };
                        bool id_522 { bool(id_517 >= id_521) };
                        while_flag_515 = id_522;
                        if (while_flag_515) {
                          uint8_t id_523 { 0 };
                          uint8_t id_524 { 0 };
                          uint32_t id_525 { lebsz_ref_217[id_524] };
                          uint32_t id_526 { 1U };
                          uint32_t id_527 { uint32_t(id_525 + id_526) };
                          Void id_528 { ((void)(lebsz_ref_217[id_523] = id_527), VOID) };
                        }
                      } while (while_flag_515);
                      uint8_t id_529 { 0 };
                      uint32_t id_530 { lebsz_ref_217[id_529] };
                      Size id_531 { Size(id_530) };
                      let_res_514 = id_531;
                    }
                    let_res_511 = let_res_514;
                  }
                  v_3cca14702fcf070f776a6badc4224e9d id_532 { std::get<5>(p_0) };
                  std::string id_533 { id_532.owner };
                  uint32_t id_534 { (uint32_t)id_533.size() };
                  Size id_535 { Size(id_534) };
                  Size id_536 { Size(let_res_511 + id_535) };
                  Size id_537 { Size(sz_214 + id_536) };
                  let_res_506 = id_537;
                }
                Size id_538 { 8UL };
                Size id_539 { Size(let_res_506 + id_538) };
                choose_res_499 = id_539;
              } else {
                uint16_t id_540 { uint16_t(p_0.index()) };
                uint16_t id_541 { 6 };
                bool id_542 { bool(id_540 == id_541) };
                Void id_543 { ((void)(assert(id_542)), VOID) };
                Size id_544 { 2UL };
                std::function<Size(*sync_key)> id_545 { dessser_gen::sync_key.sersize_of_row_binary };
                *sync_key id_546 { std::get<6>(p_0) };
                Size id_547 { id_545(id_546) };
                Size id_548 { Size(id_544 + id_547) };
                choose_res_499 = id_548;
              }
              choose_res_490 = choose_res_499;
            }
            choose_res_402 = choose_res_490;
          }
          choose_res_352 = choose_res_402;
        }
        choose_res_318 = choose_res_352;
      }
      choose_res_309 = choose_res_318;
    }
    return choose_res_309;
  }
   };
  return fun305;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_210" "make_snd_211"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let-pair "dsum2_fst_207" "dsum2_snd_208" (apply (ext-identifier sync_socket of-row-binary) (identifier "dsum1_snd_64"))
                (make-tup
                  (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey $sync_key | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 0
                    (identifier "dsum2_fst_207")) (identifier "dsum2_snd_208")))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let "dstring1_197"
                  (let "leb_ref_191" (make-vec (u32 0))
                    (let "shft_ref_192" (make-vec (u8 0))
                      (let "p_ref_193" (make-vec (identifier "dsum1_snd_64"))
                        (seq
                          (while
                            (let "leb128_194" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_193")))
                              (let-pair "leb128_fst_195" "leb128_snd_196" 
                                (identifier "leb128_194")
                                (seq (set-vec (u8 0) (identifier "p_ref_193") (identifier "leb128_snd_196"))
                                  (set-vec (u8 0) (identifier "leb_ref_191")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_195") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_192"))) (unsafe-nth (u8 0) (identifier "leb_ref_191"))))
                                  (set-vec (u8 0) (identifier "shft_ref_192") (add (unsafe-nth (u8 0) (identifier "shft_ref_192")) (u8 7))) 
                                  (ge (identifier "leb128_fst_195") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_191"))) (unsafe-nth (u8 0) (identifier "p_ref_193")))))))
                  (let-pair "dstring1_fst_198" "dstring1_snd_199" (identifier "dstring1_197")
                    (let-pair "dstring2_fst_201" "dstring2_snd_202" (read-bytes (identifier "dstring1_snd_199") (identifier "dstring1_fst_198"))
                      (make-tup
                        (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey $sync_key | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 1
                          (string-of-bytes (identifier "dstring2_fst_201"))) 
                        (identifier "dstring2_snd_202")))))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (let "drec_161" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                    (let-pair "drec_fst_162" "drec_snd_163" (identifier "drec_161")
                      (let "drec_164" (apply (ext-identifier sync_value of-row-binary) (identifier "drec_snd_163"))
                        (let-pair "drec_fst_165" "drec_snd_166" (identifier "drec_164")
                          (let "drec_179"
                            (let "dstring1_173"
                              (let "leb_ref_167" (make-vec (u32 0))
                                (let "shft_ref_168" (make-vec (u8 0))
                                  (let "p_ref_169" (make-vec (identifier "drec_snd_166"))
                                    (seq
                                      (while
                                        (let "leb128_170" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_169")))
                                          (let-pair "leb128_fst_171" "leb128_snd_172" 
                                            (identifier "leb128_170")
                                            (seq (set-vec (u8 0) (identifier "p_ref_169") (identifier "leb128_snd_172"))
                                              (set-vec (u8 0) (identifier "leb_ref_167")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_171") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_168"))) (unsafe-nth (u8 0) (identifier "leb_ref_167"))))
                                              (set-vec (u8 0) (identifier "shft_ref_168") (add (unsafe-nth (u8 0) (identifier "shft_ref_168")) (u8 7))) 
                                              (ge (identifier "leb128_fst_171") (u8 128))))) 
                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_167"))) (unsafe-nth (u8 0) (identifier "p_ref_169")))))))
                              (let-pair "dstring1_fst_174" "dstring1_snd_175" 
                                (identifier "dstring1_173")
                                (let-pair "dstring2_fst_177" "dstring2_snd_178" 
                                  (read-bytes (identifier "dstring1_snd_175") (identifier "dstring1_fst_174")) 
                                  (make-tup (string-of-bytes (identifier "dstring2_fst_177")) (identifier "dstring2_snd_178")))))
                            (let-pair "drec_fst_180" "drec_snd_181" (identifier "drec_179")
                              (let-pair "dfloat_fst_183" "dfloat_snd_184" 
                                (read-u64 little-endian (identifier "drec_snd_181"))
                                (make-tup
                                  (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey $sync_key | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 2
                                    (make-rec (string "k") (identifier "drec_fst_162") 
                                      (string "v") (identifier "drec_fst_165") 
                                      (string "uid") (identifier "drec_fst_180") 
                                      (string "mtime") (float-of-u64 (identifier "dfloat_fst_183")))) 
                                  (identifier "dfloat_snd_184")))))))))
                  (if (eq (u16 3) (identifier "dsum1_fst_63"))
                    (let "drec_98" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                      (let-pair "drec_fst_99" "drec_snd_100" (identifier "drec_98")
                        (let "drec_101" (apply (ext-identifier sync_value of-row-binary) (identifier "drec_snd_100"))
                          (let-pair "drec_fst_102" "drec_snd_103" (identifier "drec_101")
                            (let "drec_116"
                              (let "dstring1_110"
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
                                (let-pair "dstring1_fst_111" "dstring1_snd_112" 
                                  (identifier "dstring1_110")
                                  (let-pair "dstring2_fst_114" "dstring2_snd_115" 
                                    (read-bytes (identifier "dstring1_snd_112") (identifier "dstring1_fst_111")) 
                                    (make-tup (string-of-bytes (identifier "dstring2_fst_114")) (identifier "dstring2_snd_115")))))
                              (let-pair "drec_fst_117" "drec_snd_118" 
                                (identifier "drec_116")
                                (let "drec_122"
                                  (let-pair "dfloat_fst_120" "dfloat_snd_121" (read-u64 little-endian (identifier "drec_snd_118")) (make-tup (float-of-u64 (identifier "dfloat_fst_120")) (identifier "dfloat_snd_121")))
                                  (let-pair "drec_fst_123" "drec_snd_124" 
                                    (identifier "drec_122")
                                    (let "drec_128" (let-pair "dbool_fst_126" "dbool_snd_127" (read-u8 (identifier "drec_snd_124")) (make-tup (not (eq (identifier "dbool_fst_126") (u8 0))) (identifier "dbool_snd_127")))
                                      (let-pair "drec_fst_129" "drec_snd_130" 
                                        (identifier "drec_128")
                                        (let "drec_134" (let-pair "dbool_fst_132" "dbool_snd_133" (read-u8 (identifier "drec_snd_130")) (make-tup (not (eq (identifier "dbool_fst_132") (u8 0))) (identifier "dbool_snd_133")))
                                          (let-pair "drec_fst_135" "drec_snd_136" 
                                            (identifier "drec_134")
                                            (let "drec_149"
                                              (let "dstring1_143"
                                                (let "leb_ref_137" (make-vec (u32 0))
                                                  (let "shft_ref_138" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_139" 
                                                      (make-vec (identifier "drec_snd_136"))
                                                      (seq
                                                        (while
                                                          (let "leb128_140" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_139")))
                                                            (let-pair "leb128_fst_141" "leb128_snd_142" 
                                                              (identifier "leb128_140")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_139") (identifier "leb128_snd_142"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_137")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_141") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_138")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_137")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_138") (add (unsafe-nth (u8 0) (identifier "shft_ref_138")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_141") (u8 128))))) 
                                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_137"))) (unsafe-nth (u8 0) (identifier "p_ref_139")))))))
                                                (let-pair "dstring1_fst_144" "dstring1_snd_145" 
                                                  (identifier "dstring1_143")
                                                  (let-pair "dstring2_fst_147" "dstring2_snd_148" 
                                                    (read-bytes (identifier "dstring1_snd_145") (identifier "dstring1_fst_144")) 
                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_147")) (identifier "dstring2_snd_148")))))
                                              (let-pair "drec_fst_150" "drec_snd_151" 
                                                (identifier "drec_149")
                                                (let-pair "dfloat_fst_153" "dfloat_snd_154" 
                                                  (read-u64 little-endian (identifier "drec_snd_151"))
                                                  (make-tup
                                                    (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey $sync_key | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 3
                                                      (make-rec (string "k") 
                                                        (identifier "drec_fst_99") 
                                                        (string "v") 
                                                        (identifier "drec_fst_102") 
                                                        (string "uid") 
                                                        (identifier "drec_fst_117") 
                                                        (string "mtime") 
                                                        (identifier "drec_fst_123") 
                                                        (string "can_write") 
                                                        (identifier "drec_fst_129") 
                                                        (string "can_del") 
                                                        (identifier "drec_fst_135") 
                                                        (string "owner") 
                                                        (identifier "drec_fst_150") 
                                                        (string "expiry") 
                                                        (float-of-u64 (identifier "dfloat_fst_153")))) 
                                                    (identifier "dfloat_snd_154")))))))))))))))))
                    (if (eq (u16 4) (identifier "dsum1_fst_63"))
                      (let-pair "dsum2_fst_96" "dsum2_snd_97" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                        (make-tup
                          (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey $sync_key | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 4
                            (identifier "dsum2_fst_96")) (identifier "dsum2_snd_97")))
                      (if (eq (u16 5) (identifier "dsum1_fst_63"))
                        (let "drec_68" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                          (let-pair "drec_fst_69" "drec_snd_70" (identifier "drec_68")
                            (let "drec_83"
                              (let "dstring1_77"
                                (let "leb_ref_71" (make-vec (u32 0))
                                  (let "shft_ref_72" (make-vec (u8 0))
                                    (let "p_ref_73" (make-vec (identifier "drec_snd_70"))
                                      (seq
                                        (while
                                          (let "leb128_74" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_73")))
                                            (let-pair "leb128_fst_75" "leb128_snd_76" 
                                              (identifier "leb128_74")
                                              (seq (set-vec (u8 0) (identifier "p_ref_73") (identifier "leb128_snd_76"))
                                                (set-vec (u8 0) (identifier "leb_ref_71")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_75") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_72"))) (unsafe-nth (u8 0) (identifier "leb_ref_71"))))
                                                (set-vec (u8 0) (identifier "shft_ref_72") (add (unsafe-nth (u8 0) (identifier "shft_ref_72")) (u8 7))) 
                                                (ge (identifier "leb128_fst_75") (u8 128))))) 
                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_71"))) (unsafe-nth (u8 0) (identifier "p_ref_73")))))))
                                (let-pair "dstring1_fst_78" "dstring1_snd_79" 
                                  (identifier "dstring1_77")
                                  (let-pair "dstring2_fst_81" "dstring2_snd_82" 
                                    (read-bytes (identifier "dstring1_snd_79") (identifier "dstring1_fst_78")) 
                                    (make-tup (string-of-bytes (identifier "dstring2_fst_81")) (identifier "dstring2_snd_82")))))
                              (let-pair "drec_fst_84" "drec_snd_85" (identifier "drec_83")
                                (let-pair "dfloat_fst_87" "dfloat_snd_88" 
                                  (read-u64 little-endian (identifier "drec_snd_85"))
                                  (make-tup
                                    (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey $sync_key | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 5
                                      (make-rec (string "k") (identifier "drec_fst_69") (string "owner") (identifier "drec_fst_84") (string "expiry") (float-of-u64 (identifier "dfloat_fst_87")))) 
                                    (identifier "dfloat_snd_88")))))))
                        (seq (assert (eq (identifier "dsum1_fst_63") (u16 6)))
                          (let-pair "dsum2_fst_66" "dsum2_snd_67" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                            (make-tup
                              (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey $sync_key | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 6
                                (identifier "dsum2_fst_66")) (identifier "dsum2_snd_67")))))))))))) 
        (make-tup (identifier "make_fst_210") (identifier "make_snd_211"))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun549 { [&fun549](Pointer p_0) {
    v_362f9d9108a6902af48b6c83d5377ea1 id_550 { p_0.readU16Le() };
    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_551;
    {
      auto du16_fst_57 { std::get<0>(id_550) };
      auto du16_snd_58 { std::get<1>(id_550) };
      v_362f9d9108a6902af48b6c83d5377ea1 id_552 {  du16_fst_57, du16_snd_58  };
      letpair_res_551 = id_552;
    }
    f63f919559f0d70225bd0da5dd9bcafc let_res_553;
    {
      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_62 { letpair_res_551 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_554;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_555 { 0 };
        bool id_556 { bool(id_555 == dsum1_fst_63) };
        f63f919559f0d70225bd0da5dd9bcafc choose_res_557;
        if (id_556) {
          std::function<v_7036a8b0fbd8a7ca699aed2c44f6fdba(Pointer)> id_558 { dessser_gen::sync_socket.of_row_binary };
          v_7036a8b0fbd8a7ca699aed2c44f6fdba id_559 { id_558(dsum1_snd_64) };
          f63f919559f0d70225bd0da5dd9bcafc letpair_res_560;
          {
            auto dsum2_fst_207 { std::get<0>(id_559) };
            auto dsum2_snd_208 { std::get<1>(id_559) };
            t id_561 { std::in_place_index<0>, dsum2_fst_207 };
            f63f919559f0d70225bd0da5dd9bcafc id_562 {  id_561, dsum2_snd_208  };
            letpair_res_560 = id_562;
          }
          choose_res_557 = letpair_res_560;
        } else {
          uint16_t id_563 { 1 };
          bool id_564 { bool(id_563 == dsum1_fst_63) };
          f63f919559f0d70225bd0da5dd9bcafc choose_res_565;
          if (id_564) {
            uint32_t id_566 { 0U };
            Vec<1, uint32_t> id_567 {  id_566  };
            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_568;
            {
              Vec<1, uint32_t> leb_ref_191 { id_567 };
              uint8_t id_569 { 0 };
              Vec<1, uint8_t> id_570 {  id_569  };
              v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_571;
              {
                Vec<1, uint8_t> shft_ref_192 { id_570 };
                Vec<1, Pointer> id_572 {  dsum1_snd_64  };
                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_573;
                {
                  Vec<1, Pointer> p_ref_193 { id_572 };
                  bool while_flag_574 { true };
                  do {
                    uint8_t id_575 { 0 };
                    Pointer id_576 { p_ref_193[id_575] };
                    v_1d5843897434feb24d158f3793db9189 id_577 { id_576.readU8() };
                    bool let_res_578;
                    {
                      v_1d5843897434feb24d158f3793db9189 leb128_194 { id_577 };
                      bool letpair_res_579;
                      {
                        auto leb128_fst_195 { std::get<0>(leb128_194) };
                        auto leb128_snd_196 { std::get<1>(leb128_194) };
                        uint8_t id_580 { 0 };
                        Void id_581 { ((void)(p_ref_193[id_580] = leb128_snd_196), VOID) };
                        uint8_t id_582 { 0 };
                        uint8_t id_583 { 127 };
                        uint8_t id_584 { uint8_t(leb128_fst_195 & id_583) };
                        uint32_t id_585 { uint32_t(id_584) };
                        uint8_t id_586 { 0 };
                        uint8_t id_587 { shft_ref_192[id_586] };
                        uint32_t id_588 { uint32_t(id_585 << id_587) };
                        uint8_t id_589 { 0 };
                        uint32_t id_590 { leb_ref_191[id_589] };
                        uint32_t id_591 { uint32_t(id_588 | id_590) };
                        Void id_592 { ((void)(leb_ref_191[id_582] = id_591), VOID) };
                        uint8_t id_593 { 0 };
                        uint8_t id_594 { 0 };
                        uint8_t id_595 { shft_ref_192[id_594] };
                        uint8_t id_596 { 7 };
                        uint8_t id_597 { uint8_t(id_595 + id_596) };
                        Void id_598 { ((void)(shft_ref_192[id_593] = id_597), VOID) };
                        uint8_t id_599 { 128 };
                        bool id_600 { bool(leb128_fst_195 >= id_599) };
                        letpair_res_579 = id_600;
                      }
                      let_res_578 = letpair_res_579;
                    }
                    while_flag_574 = let_res_578;
                    if (while_flag_574) {
                    }
                  } while (while_flag_574);
                  uint8_t id_601 { 0 };
                  uint32_t id_602 { leb_ref_191[id_601] };
                  Size id_603 { Size(id_602) };
                  uint8_t id_604 { 0 };
                  Pointer id_605 { p_ref_193[id_604] };
                  v_41b0681ed7f1f185fd3e6c4dcdc13110 id_606 {  id_603, id_605  };
                  let_res_573 = id_606;
                }
                let_res_571 = let_res_573;
              }
              let_res_568 = let_res_571;
            }
            f63f919559f0d70225bd0da5dd9bcafc let_res_607;
            {
              v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_197 { let_res_568 };
              f63f919559f0d70225bd0da5dd9bcafc letpair_res_608;
              {
                auto dstring1_fst_198 { std::get<0>(dstring1_197) };
                auto dstring1_snd_199 { std::get<1>(dstring1_197) };
                f921d1e0a170c3c04148c21704db9c45 id_609 { dstring1_snd_199.readBytes(dstring1_fst_198) };
                f63f919559f0d70225bd0da5dd9bcafc letpair_res_610;
                {
                  auto dstring2_fst_201 { std::get<0>(id_609) };
                  auto dstring2_snd_202 { std::get<1>(id_609) };
                  std::string id_611 { dstring2_fst_201.toString() };
                  t id_612 { std::in_place_index<1>, id_611 };
                  f63f919559f0d70225bd0da5dd9bcafc id_613 {  id_612, dstring2_snd_202  };
                  letpair_res_610 = id_613;
                }
                letpair_res_608 = letpair_res_610;
              }
              let_res_607 = letpair_res_608;
            }
            choose_res_565 = let_res_607;
          } else {
            uint16_t id_614 { 2 };
            bool id_615 { bool(id_614 == dsum1_fst_63) };
            f63f919559f0d70225bd0da5dd9bcafc choose_res_616;
            if (id_615) {
              std::function<v_25d2fb9e36d1852487ae5e50cde3ed3c(Pointer)> id_617 { dessser_gen::sync_key.of_row_binary };
              v_25d2fb9e36d1852487ae5e50cde3ed3c id_618 { id_617(dsum1_snd_64) };
              f63f919559f0d70225bd0da5dd9bcafc let_res_619;
              {
                v_25d2fb9e36d1852487ae5e50cde3ed3c drec_161 { id_618 };
                f63f919559f0d70225bd0da5dd9bcafc letpair_res_620;
                {
                  auto drec_fst_162 { std::get<0>(drec_161) };
                  auto drec_snd_163 { std::get<1>(drec_161) };
                  std::function<v_1d33d755cf2eeb43eecb39ad040d8020(Pointer)> id_621 { dessser_gen::sync_value.of_row_binary };
                  v_1d33d755cf2eeb43eecb39ad040d8020 id_622 { id_621(drec_snd_163) };
                  f63f919559f0d70225bd0da5dd9bcafc let_res_623;
                  {
                    v_1d33d755cf2eeb43eecb39ad040d8020 drec_164 { id_622 };
                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_624;
                    {
                      auto drec_fst_165 { std::get<0>(drec_164) };
                      auto drec_snd_166 { std::get<1>(drec_164) };
                      uint32_t id_625 { 0U };
                      Vec<1, uint32_t> id_626 {  id_625  };
                      v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_627;
                      {
                        Vec<1, uint32_t> leb_ref_167 { id_626 };
                        uint8_t id_628 { 0 };
                        Vec<1, uint8_t> id_629 {  id_628  };
                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_630;
                        {
                          Vec<1, uint8_t> shft_ref_168 { id_629 };
                          Vec<1, Pointer> id_631 {  drec_snd_166  };
                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_632;
                          {
                            Vec<1, Pointer> p_ref_169 { id_631 };
                            bool while_flag_633 { true };
                            do {
                              uint8_t id_634 { 0 };
                              Pointer id_635 { p_ref_169[id_634] };
                              v_1d5843897434feb24d158f3793db9189 id_636 { id_635.readU8() };
                              bool let_res_637;
                              {
                                v_1d5843897434feb24d158f3793db9189 leb128_170 { id_636 };
                                bool letpair_res_638;
                                {
                                  auto leb128_fst_171 { std::get<0>(leb128_170) };
                                  auto leb128_snd_172 { std::get<1>(leb128_170) };
                                  uint8_t id_639 { 0 };
                                  Void id_640 { ((void)(p_ref_169[id_639] = leb128_snd_172), VOID) };
                                  uint8_t id_641 { 0 };
                                  uint8_t id_642 { 127 };
                                  uint8_t id_643 { uint8_t(leb128_fst_171 & id_642) };
                                  uint32_t id_644 { uint32_t(id_643) };
                                  uint8_t id_645 { 0 };
                                  uint8_t id_646 { shft_ref_168[id_645] };
                                  uint32_t id_647 { uint32_t(id_644 << id_646) };
                                  uint8_t id_648 { 0 };
                                  uint32_t id_649 { leb_ref_167[id_648] };
                                  uint32_t id_650 { uint32_t(id_647 | id_649) };
                                  Void id_651 { ((void)(leb_ref_167[id_641] = id_650), VOID) };
                                  uint8_t id_652 { 0 };
                                  uint8_t id_653 { 0 };
                                  uint8_t id_654 { shft_ref_168[id_653] };
                                  uint8_t id_655 { 7 };
                                  uint8_t id_656 { uint8_t(id_654 + id_655) };
                                  Void id_657 { ((void)(shft_ref_168[id_652] = id_656), VOID) };
                                  uint8_t id_658 { 128 };
                                  bool id_659 { bool(leb128_fst_171 >= id_658) };
                                  letpair_res_638 = id_659;
                                }
                                let_res_637 = letpair_res_638;
                              }
                              while_flag_633 = let_res_637;
                              if (while_flag_633) {
                              }
                            } while (while_flag_633);
                            uint8_t id_660 { 0 };
                            uint32_t id_661 { leb_ref_167[id_660] };
                            Size id_662 { Size(id_661) };
                            uint8_t id_663 { 0 };
                            Pointer id_664 { p_ref_169[id_663] };
                            v_41b0681ed7f1f185fd3e6c4dcdc13110 id_665 {  id_662, id_664  };
                            let_res_632 = id_665;
                          }
                          let_res_630 = let_res_632;
                        }
                        let_res_627 = let_res_630;
                      }
                      v_46a5e81c2410b000ff0adea6dc198147 let_res_666;
                      {
                        v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_173 { let_res_627 };
                        v_46a5e81c2410b000ff0adea6dc198147 letpair_res_667;
                        {
                          auto dstring1_fst_174 { std::get<0>(dstring1_173) };
                          auto dstring1_snd_175 { std::get<1>(dstring1_173) };
                          f921d1e0a170c3c04148c21704db9c45 id_668 { dstring1_snd_175.readBytes(dstring1_fst_174) };
                          v_46a5e81c2410b000ff0adea6dc198147 letpair_res_669;
                          {
                            auto dstring2_fst_177 { std::get<0>(id_668) };
                            auto dstring2_snd_178 { std::get<1>(id_668) };
                            std::string id_670 { dstring2_fst_177.toString() };
                            v_46a5e81c2410b000ff0adea6dc198147 id_671 {  id_670, dstring2_snd_178  };
                            letpair_res_669 = id_671;
                          }
                          letpair_res_667 = letpair_res_669;
                        }
                        let_res_666 = letpair_res_667;
                      }
                      f63f919559f0d70225bd0da5dd9bcafc let_res_672;
                      {
                        v_46a5e81c2410b000ff0adea6dc198147 drec_179 { let_res_666 };
                        f63f919559f0d70225bd0da5dd9bcafc letpair_res_673;
                        {
                          auto drec_fst_180 { std::get<0>(drec_179) };
                          auto drec_snd_181 { std::get<1>(drec_179) };
                          b62e103e7915a76f45f02f7c6f667c79 id_674 { drec_snd_181.readU64Le() };
                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_675;
                          {
                            auto dfloat_fst_183 { std::get<0>(id_674) };
                            auto dfloat_snd_184 { std::get<1>(id_674) };
                            double id_676 { float_of_qword(dfloat_fst_183) };
                            v_940f244208f0d3b12c9ae508dcaea75c id_677 {  .k = drec_fst_162, .v = drec_fst_165, .uid = drec_fst_180, .mtime = id_676  };
                            t id_678 { std::in_place_index<2>, id_677 };
                            f63f919559f0d70225bd0da5dd9bcafc id_679 {  id_678, dfloat_snd_184  };
                            letpair_res_675 = id_679;
                          }
                          letpair_res_673 = letpair_res_675;
                        }
                        let_res_672 = letpair_res_673;
                      }
                      letpair_res_624 = let_res_672;
                    }
                    let_res_623 = letpair_res_624;
                  }
                  letpair_res_620 = let_res_623;
                }
                let_res_619 = letpair_res_620;
              }
              choose_res_616 = let_res_619;
            } else {
              uint16_t id_680 { 3 };
              bool id_681 { bool(id_680 == dsum1_fst_63) };
              f63f919559f0d70225bd0da5dd9bcafc choose_res_682;
              if (id_681) {
                std::function<v_25d2fb9e36d1852487ae5e50cde3ed3c(Pointer)> id_683 { dessser_gen::sync_key.of_row_binary };
                v_25d2fb9e36d1852487ae5e50cde3ed3c id_684 { id_683(dsum1_snd_64) };
                f63f919559f0d70225bd0da5dd9bcafc let_res_685;
                {
                  v_25d2fb9e36d1852487ae5e50cde3ed3c drec_98 { id_684 };
                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_686;
                  {
                    auto drec_fst_99 { std::get<0>(drec_98) };
                    auto drec_snd_100 { std::get<1>(drec_98) };
                    std::function<v_1d33d755cf2eeb43eecb39ad040d8020(Pointer)> id_687 { dessser_gen::sync_value.of_row_binary };
                    v_1d33d755cf2eeb43eecb39ad040d8020 id_688 { id_687(drec_snd_100) };
                    f63f919559f0d70225bd0da5dd9bcafc let_res_689;
                    {
                      v_1d33d755cf2eeb43eecb39ad040d8020 drec_101 { id_688 };
                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_690;
                      {
                        auto drec_fst_102 { std::get<0>(drec_101) };
                        auto drec_snd_103 { std::get<1>(drec_101) };
                        uint32_t id_691 { 0U };
                        Vec<1, uint32_t> id_692 {  id_691  };
                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_693;
                        {
                          Vec<1, uint32_t> leb_ref_104 { id_692 };
                          uint8_t id_694 { 0 };
                          Vec<1, uint8_t> id_695 {  id_694  };
                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_696;
                          {
                            Vec<1, uint8_t> shft_ref_105 { id_695 };
                            Vec<1, Pointer> id_697 {  drec_snd_103  };
                            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_698;
                            {
                              Vec<1, Pointer> p_ref_106 { id_697 };
                              bool while_flag_699 { true };
                              do {
                                uint8_t id_700 { 0 };
                                Pointer id_701 { p_ref_106[id_700] };
                                v_1d5843897434feb24d158f3793db9189 id_702 { id_701.readU8() };
                                bool let_res_703;
                                {
                                  v_1d5843897434feb24d158f3793db9189 leb128_107 { id_702 };
                                  bool letpair_res_704;
                                  {
                                    auto leb128_fst_108 { std::get<0>(leb128_107) };
                                    auto leb128_snd_109 { std::get<1>(leb128_107) };
                                    uint8_t id_705 { 0 };
                                    Void id_706 { ((void)(p_ref_106[id_705] = leb128_snd_109), VOID) };
                                    uint8_t id_707 { 0 };
                                    uint8_t id_708 { 127 };
                                    uint8_t id_709 { uint8_t(leb128_fst_108 & id_708) };
                                    uint32_t id_710 { uint32_t(id_709) };
                                    uint8_t id_711 { 0 };
                                    uint8_t id_712 { shft_ref_105[id_711] };
                                    uint32_t id_713 { uint32_t(id_710 << id_712) };
                                    uint8_t id_714 { 0 };
                                    uint32_t id_715 { leb_ref_104[id_714] };
                                    uint32_t id_716 { uint32_t(id_713 | id_715) };
                                    Void id_717 { ((void)(leb_ref_104[id_707] = id_716), VOID) };
                                    uint8_t id_718 { 0 };
                                    uint8_t id_719 { 0 };
                                    uint8_t id_720 { shft_ref_105[id_719] };
                                    uint8_t id_721 { 7 };
                                    uint8_t id_722 { uint8_t(id_720 + id_721) };
                                    Void id_723 { ((void)(shft_ref_105[id_718] = id_722), VOID) };
                                    uint8_t id_724 { 128 };
                                    bool id_725 { bool(leb128_fst_108 >= id_724) };
                                    letpair_res_704 = id_725;
                                  }
                                  let_res_703 = letpair_res_704;
                                }
                                while_flag_699 = let_res_703;
                                if (while_flag_699) {
                                }
                              } while (while_flag_699);
                              uint8_t id_726 { 0 };
                              uint32_t id_727 { leb_ref_104[id_726] };
                              Size id_728 { Size(id_727) };
                              uint8_t id_729 { 0 };
                              Pointer id_730 { p_ref_106[id_729] };
                              v_41b0681ed7f1f185fd3e6c4dcdc13110 id_731 {  id_728, id_730  };
                              let_res_698 = id_731;
                            }
                            let_res_696 = let_res_698;
                          }
                          let_res_693 = let_res_696;
                        }
                        v_46a5e81c2410b000ff0adea6dc198147 let_res_732;
                        {
                          v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_110 { let_res_693 };
                          v_46a5e81c2410b000ff0adea6dc198147 letpair_res_733;
                          {
                            auto dstring1_fst_111 { std::get<0>(dstring1_110) };
                            auto dstring1_snd_112 { std::get<1>(dstring1_110) };
                            f921d1e0a170c3c04148c21704db9c45 id_734 { dstring1_snd_112.readBytes(dstring1_fst_111) };
                            v_46a5e81c2410b000ff0adea6dc198147 letpair_res_735;
                            {
                              auto dstring2_fst_114 { std::get<0>(id_734) };
                              auto dstring2_snd_115 { std::get<1>(id_734) };
                              std::string id_736 { dstring2_fst_114.toString() };
                              v_46a5e81c2410b000ff0adea6dc198147 id_737 {  id_736, dstring2_snd_115  };
                              letpair_res_735 = id_737;
                            }
                            letpair_res_733 = letpair_res_735;
                          }
                          let_res_732 = letpair_res_733;
                        }
                        f63f919559f0d70225bd0da5dd9bcafc let_res_738;
                        {
                          v_46a5e81c2410b000ff0adea6dc198147 drec_116 { let_res_732 };
                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_739;
                          {
                            auto drec_fst_117 { std::get<0>(drec_116) };
                            auto drec_snd_118 { std::get<1>(drec_116) };
                            b62e103e7915a76f45f02f7c6f667c79 id_740 { drec_snd_118.readU64Le() };
                            v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_741;
                            {
                              auto dfloat_fst_120 { std::get<0>(id_740) };
                              auto dfloat_snd_121 { std::get<1>(id_740) };
                              double id_742 { float_of_qword(dfloat_fst_120) };
                              v_41a5a8cf414de9bfdc6375241fcc910a id_743 {  id_742, dfloat_snd_121  };
                              letpair_res_741 = id_743;
                            }
                            f63f919559f0d70225bd0da5dd9bcafc let_res_744;
                            {
                              v_41a5a8cf414de9bfdc6375241fcc910a drec_122 { letpair_res_741 };
                              f63f919559f0d70225bd0da5dd9bcafc letpair_res_745;
                              {
                                auto drec_fst_123 { std::get<0>(drec_122) };
                                auto drec_snd_124 { std::get<1>(drec_122) };
                                v_1d5843897434feb24d158f3793db9189 id_746 { drec_snd_124.readU8() };
                                f2a48a42f9c827f487e53ee52a4e9e2f letpair_res_747;
                                {
                                  auto dbool_fst_126 { std::get<0>(id_746) };
                                  auto dbool_snd_127 { std::get<1>(id_746) };
                                  uint8_t id_748 { 0 };
                                  bool id_749 { bool(dbool_fst_126 == id_748) };
                                  bool id_750 { ! id_749 };
                                  f2a48a42f9c827f487e53ee52a4e9e2f id_751 {  id_750, dbool_snd_127  };
                                  letpair_res_747 = id_751;
                                }
                                f63f919559f0d70225bd0da5dd9bcafc let_res_752;
                                {
                                  f2a48a42f9c827f487e53ee52a4e9e2f drec_128 { letpair_res_747 };
                                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_753;
                                  {
                                    auto drec_fst_129 { std::get<0>(drec_128) };
                                    auto drec_snd_130 { std::get<1>(drec_128) };
                                    v_1d5843897434feb24d158f3793db9189 id_754 { drec_snd_130.readU8() };
                                    f2a48a42f9c827f487e53ee52a4e9e2f letpair_res_755;
                                    {
                                      auto dbool_fst_132 { std::get<0>(id_754) };
                                      auto dbool_snd_133 { std::get<1>(id_754) };
                                      uint8_t id_756 { 0 };
                                      bool id_757 { bool(dbool_fst_132 == id_756) };
                                      bool id_758 { ! id_757 };
                                      f2a48a42f9c827f487e53ee52a4e9e2f id_759 {  id_758, dbool_snd_133  };
                                      letpair_res_755 = id_759;
                                    }
                                    f63f919559f0d70225bd0da5dd9bcafc let_res_760;
                                    {
                                      f2a48a42f9c827f487e53ee52a4e9e2f drec_134 { letpair_res_755 };
                                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_761;
                                      {
                                        auto drec_fst_135 { std::get<0>(drec_134) };
                                        auto drec_snd_136 { std::get<1>(drec_134) };
                                        uint32_t id_762 { 0U };
                                        Vec<1, uint32_t> id_763 {  id_762  };
                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_764;
                                        {
                                          Vec<1, uint32_t> leb_ref_137 { id_763 };
                                          uint8_t id_765 { 0 };
                                          Vec<1, uint8_t> id_766 {  id_765  };
                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_767;
                                          {
                                            Vec<1, uint8_t> shft_ref_138 { id_766 };
                                            Vec<1, Pointer> id_768 {  drec_snd_136  };
                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_769;
                                            {
                                              Vec<1, Pointer> p_ref_139 { id_768 };
                                              bool while_flag_770 { true };
                                              do {
                                                uint8_t id_771 { 0 };
                                                Pointer id_772 { p_ref_139[id_771] };
                                                v_1d5843897434feb24d158f3793db9189 id_773 { id_772.readU8() };
                                                bool let_res_774;
                                                {
                                                  v_1d5843897434feb24d158f3793db9189 leb128_140 { id_773 };
                                                  bool letpair_res_775;
                                                  {
                                                    auto leb128_fst_141 { std::get<0>(leb128_140) };
                                                    auto leb128_snd_142 { std::get<1>(leb128_140) };
                                                    uint8_t id_776 { 0 };
                                                    Void id_777 { ((void)(p_ref_139[id_776] = leb128_snd_142), VOID) };
                                                    uint8_t id_778 { 0 };
                                                    uint8_t id_779 { 127 };
                                                    uint8_t id_780 { uint8_t(leb128_fst_141 & id_779) };
                                                    uint32_t id_781 { uint32_t(id_780) };
                                                    uint8_t id_782 { 0 };
                                                    uint8_t id_783 { shft_ref_138[id_782] };
                                                    uint32_t id_784 { uint32_t(id_781 << id_783) };
                                                    uint8_t id_785 { 0 };
                                                    uint32_t id_786 { leb_ref_137[id_785] };
                                                    uint32_t id_787 { uint32_t(id_784 | id_786) };
                                                    Void id_788 { ((void)(leb_ref_137[id_778] = id_787), VOID) };
                                                    uint8_t id_789 { 0 };
                                                    uint8_t id_790 { 0 };
                                                    uint8_t id_791 { shft_ref_138[id_790] };
                                                    uint8_t id_792 { 7 };
                                                    uint8_t id_793 { uint8_t(id_791 + id_792) };
                                                    Void id_794 { ((void)(shft_ref_138[id_789] = id_793), VOID) };
                                                    uint8_t id_795 { 128 };
                                                    bool id_796 { bool(leb128_fst_141 >= id_795) };
                                                    letpair_res_775 = id_796;
                                                  }
                                                  let_res_774 = letpair_res_775;
                                                }
                                                while_flag_770 = let_res_774;
                                                if (while_flag_770) {
                                                }
                                              } while (while_flag_770);
                                              uint8_t id_797 { 0 };
                                              uint32_t id_798 { leb_ref_137[id_797] };
                                              Size id_799 { Size(id_798) };
                                              uint8_t id_800 { 0 };
                                              Pointer id_801 { p_ref_139[id_800] };
                                              v_41b0681ed7f1f185fd3e6c4dcdc13110 id_802 {  id_799, id_801  };
                                              let_res_769 = id_802;
                                            }
                                            let_res_767 = let_res_769;
                                          }
                                          let_res_764 = let_res_767;
                                        }
                                        v_46a5e81c2410b000ff0adea6dc198147 let_res_803;
                                        {
                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_143 { let_res_764 };
                                          v_46a5e81c2410b000ff0adea6dc198147 letpair_res_804;
                                          {
                                            auto dstring1_fst_144 { std::get<0>(dstring1_143) };
                                            auto dstring1_snd_145 { std::get<1>(dstring1_143) };
                                            f921d1e0a170c3c04148c21704db9c45 id_805 { dstring1_snd_145.readBytes(dstring1_fst_144) };
                                            v_46a5e81c2410b000ff0adea6dc198147 letpair_res_806;
                                            {
                                              auto dstring2_fst_147 { std::get<0>(id_805) };
                                              auto dstring2_snd_148 { std::get<1>(id_805) };
                                              std::string id_807 { dstring2_fst_147.toString() };
                                              v_46a5e81c2410b000ff0adea6dc198147 id_808 {  id_807, dstring2_snd_148  };
                                              letpair_res_806 = id_808;
                                            }
                                            letpair_res_804 = letpair_res_806;
                                          }
                                          let_res_803 = letpair_res_804;
                                        }
                                        f63f919559f0d70225bd0da5dd9bcafc let_res_809;
                                        {
                                          v_46a5e81c2410b000ff0adea6dc198147 drec_149 { let_res_803 };
                                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_810;
                                          {
                                            auto drec_fst_150 { std::get<0>(drec_149) };
                                            auto drec_snd_151 { std::get<1>(drec_149) };
                                            b62e103e7915a76f45f02f7c6f667c79 id_811 { drec_snd_151.readU64Le() };
                                            f63f919559f0d70225bd0da5dd9bcafc letpair_res_812;
                                            {
                                              auto dfloat_fst_153 { std::get<0>(id_811) };
                                              auto dfloat_snd_154 { std::get<1>(id_811) };
                                              double id_813 { float_of_qword(dfloat_fst_153) };
                                              v_5e1953df5130fdcab794186d201fd5e8 id_814 {  .k = drec_fst_99, .v = drec_fst_102, .uid = drec_fst_117, .mtime = drec_fst_123, .can_write = drec_fst_129, .can_del = drec_fst_135, .owner = drec_fst_150, .expiry = id_813  };
                                              t id_815 { std::in_place_index<3>, id_814 };
                                              f63f919559f0d70225bd0da5dd9bcafc id_816 {  id_815, dfloat_snd_154  };
                                              letpair_res_812 = id_816;
                                            }
                                            letpair_res_810 = letpair_res_812;
                                          }
                                          let_res_809 = letpair_res_810;
                                        }
                                        letpair_res_761 = let_res_809;
                                      }
                                      let_res_760 = letpair_res_761;
                                    }
                                    letpair_res_753 = let_res_760;
                                  }
                                  let_res_752 = letpair_res_753;
                                }
                                letpair_res_745 = let_res_752;
                              }
                              let_res_744 = letpair_res_745;
                            }
                            letpair_res_739 = let_res_744;
                          }
                          let_res_738 = letpair_res_739;
                        }
                        letpair_res_690 = let_res_738;
                      }
                      let_res_689 = letpair_res_690;
                    }
                    letpair_res_686 = let_res_689;
                  }
                  let_res_685 = letpair_res_686;
                }
                choose_res_682 = let_res_685;
              } else {
                uint16_t id_817 { 4 };
                bool id_818 { bool(id_817 == dsum1_fst_63) };
                f63f919559f0d70225bd0da5dd9bcafc choose_res_819;
                if (id_818) {
                  std::function<v_25d2fb9e36d1852487ae5e50cde3ed3c(Pointer)> id_820 { dessser_gen::sync_key.of_row_binary };
                  v_25d2fb9e36d1852487ae5e50cde3ed3c id_821 { id_820(dsum1_snd_64) };
                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_822;
                  {
                    auto dsum2_fst_96 { std::get<0>(id_821) };
                    auto dsum2_snd_97 { std::get<1>(id_821) };
                    t id_823 { std::in_place_index<4>, dsum2_fst_96 };
                    f63f919559f0d70225bd0da5dd9bcafc id_824 {  id_823, dsum2_snd_97  };
                    letpair_res_822 = id_824;
                  }
                  choose_res_819 = letpair_res_822;
                } else {
                  uint16_t id_825 { 5 };
                  bool id_826 { bool(id_825 == dsum1_fst_63) };
                  f63f919559f0d70225bd0da5dd9bcafc choose_res_827;
                  if (id_826) {
                    std::function<v_25d2fb9e36d1852487ae5e50cde3ed3c(Pointer)> id_828 { dessser_gen::sync_key.of_row_binary };
                    v_25d2fb9e36d1852487ae5e50cde3ed3c id_829 { id_828(dsum1_snd_64) };
                    f63f919559f0d70225bd0da5dd9bcafc let_res_830;
                    {
                      v_25d2fb9e36d1852487ae5e50cde3ed3c drec_68 { id_829 };
                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_831;
                      {
                        auto drec_fst_69 { std::get<0>(drec_68) };
                        auto drec_snd_70 { std::get<1>(drec_68) };
                        uint32_t id_832 { 0U };
                        Vec<1, uint32_t> id_833 {  id_832  };
                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_834;
                        {
                          Vec<1, uint32_t> leb_ref_71 { id_833 };
                          uint8_t id_835 { 0 };
                          Vec<1, uint8_t> id_836 {  id_835  };
                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_837;
                          {
                            Vec<1, uint8_t> shft_ref_72 { id_836 };
                            Vec<1, Pointer> id_838 {  drec_snd_70  };
                            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_839;
                            {
                              Vec<1, Pointer> p_ref_73 { id_838 };
                              bool while_flag_840 { true };
                              do {
                                uint8_t id_841 { 0 };
                                Pointer id_842 { p_ref_73[id_841] };
                                v_1d5843897434feb24d158f3793db9189 id_843 { id_842.readU8() };
                                bool let_res_844;
                                {
                                  v_1d5843897434feb24d158f3793db9189 leb128_74 { id_843 };
                                  bool letpair_res_845;
                                  {
                                    auto leb128_fst_75 { std::get<0>(leb128_74) };
                                    auto leb128_snd_76 { std::get<1>(leb128_74) };
                                    uint8_t id_846 { 0 };
                                    Void id_847 { ((void)(p_ref_73[id_846] = leb128_snd_76), VOID) };
                                    uint8_t id_848 { 0 };
                                    uint8_t id_849 { 127 };
                                    uint8_t id_850 { uint8_t(leb128_fst_75 & id_849) };
                                    uint32_t id_851 { uint32_t(id_850) };
                                    uint8_t id_852 { 0 };
                                    uint8_t id_853 { shft_ref_72[id_852] };
                                    uint32_t id_854 { uint32_t(id_851 << id_853) };
                                    uint8_t id_855 { 0 };
                                    uint32_t id_856 { leb_ref_71[id_855] };
                                    uint32_t id_857 { uint32_t(id_854 | id_856) };
                                    Void id_858 { ((void)(leb_ref_71[id_848] = id_857), VOID) };
                                    uint8_t id_859 { 0 };
                                    uint8_t id_860 { 0 };
                                    uint8_t id_861 { shft_ref_72[id_860] };
                                    uint8_t id_862 { 7 };
                                    uint8_t id_863 { uint8_t(id_861 + id_862) };
                                    Void id_864 { ((void)(shft_ref_72[id_859] = id_863), VOID) };
                                    uint8_t id_865 { 128 };
                                    bool id_866 { bool(leb128_fst_75 >= id_865) };
                                    letpair_res_845 = id_866;
                                  }
                                  let_res_844 = letpair_res_845;
                                }
                                while_flag_840 = let_res_844;
                                if (while_flag_840) {
                                }
                              } while (while_flag_840);
                              uint8_t id_867 { 0 };
                              uint32_t id_868 { leb_ref_71[id_867] };
                              Size id_869 { Size(id_868) };
                              uint8_t id_870 { 0 };
                              Pointer id_871 { p_ref_73[id_870] };
                              v_41b0681ed7f1f185fd3e6c4dcdc13110 id_872 {  id_869, id_871  };
                              let_res_839 = id_872;
                            }
                            let_res_837 = let_res_839;
                          }
                          let_res_834 = let_res_837;
                        }
                        v_46a5e81c2410b000ff0adea6dc198147 let_res_873;
                        {
                          v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_77 { let_res_834 };
                          v_46a5e81c2410b000ff0adea6dc198147 letpair_res_874;
                          {
                            auto dstring1_fst_78 { std::get<0>(dstring1_77) };
                            auto dstring1_snd_79 { std::get<1>(dstring1_77) };
                            f921d1e0a170c3c04148c21704db9c45 id_875 { dstring1_snd_79.readBytes(dstring1_fst_78) };
                            v_46a5e81c2410b000ff0adea6dc198147 letpair_res_876;
                            {
                              auto dstring2_fst_81 { std::get<0>(id_875) };
                              auto dstring2_snd_82 { std::get<1>(id_875) };
                              std::string id_877 { dstring2_fst_81.toString() };
                              v_46a5e81c2410b000ff0adea6dc198147 id_878 {  id_877, dstring2_snd_82  };
                              letpair_res_876 = id_878;
                            }
                            letpair_res_874 = letpair_res_876;
                          }
                          let_res_873 = letpair_res_874;
                        }
                        f63f919559f0d70225bd0da5dd9bcafc let_res_879;
                        {
                          v_46a5e81c2410b000ff0adea6dc198147 drec_83 { let_res_873 };
                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_880;
                          {
                            auto drec_fst_84 { std::get<0>(drec_83) };
                            auto drec_snd_85 { std::get<1>(drec_83) };
                            b62e103e7915a76f45f02f7c6f667c79 id_881 { drec_snd_85.readU64Le() };
                            f63f919559f0d70225bd0da5dd9bcafc letpair_res_882;
                            {
                              auto dfloat_fst_87 { std::get<0>(id_881) };
                              auto dfloat_snd_88 { std::get<1>(id_881) };
                              double id_883 { float_of_qword(dfloat_fst_87) };
                              v_3cca14702fcf070f776a6badc4224e9d id_884 {  .k = drec_fst_69, .owner = drec_fst_84, .expiry = id_883  };
                              t id_885 { std::in_place_index<5>, id_884 };
                              f63f919559f0d70225bd0da5dd9bcafc id_886 {  id_885, dfloat_snd_88  };
                              letpair_res_882 = id_886;
                            }
                            letpair_res_880 = letpair_res_882;
                          }
                          let_res_879 = letpair_res_880;
                        }
                        letpair_res_831 = let_res_879;
                      }
                      let_res_830 = letpair_res_831;
                    }
                    choose_res_827 = let_res_830;
                  } else {
                    uint16_t id_887 { 6 };
                    bool id_888 { bool(dsum1_fst_63 == id_887) };
                    Void id_889 { ((void)(assert(id_888)), VOID) };
                    std::function<v_25d2fb9e36d1852487ae5e50cde3ed3c(Pointer)> id_890 { dessser_gen::sync_key.of_row_binary };
                    v_25d2fb9e36d1852487ae5e50cde3ed3c id_891 { id_890(dsum1_snd_64) };
                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_892;
                    {
                      auto dsum2_fst_66 { std::get<0>(id_891) };
                      auto dsum2_snd_67 { std::get<1>(id_891) };
                      t id_893 { std::in_place_index<6>, dsum2_fst_66 };
                      f63f919559f0d70225bd0da5dd9bcafc id_894 {  id_893, dsum2_snd_67  };
                      letpair_res_892 = id_894;
                    }
                    choose_res_827 = letpair_res_892;
                  }
                  choose_res_819 = choose_res_827;
                }
                choose_res_682 = choose_res_819;
              }
              choose_res_616 = choose_res_682;
            }
            choose_res_565 = choose_res_616;
          }
          choose_res_557 = choose_res_565;
        }
        letpair_res_554 = choose_res_557;
      }
      let_res_553 = letpair_res_554;
    }
    f63f919559f0d70225bd0da5dd9bcafc letpair_res_895;
    {
      auto make_fst_210 { std::get<0>(let_res_553) };
      auto make_snd_211 { std::get<1>(let_res_553) };
      f63f919559f0d70225bd0da5dd9bcafc id_896 {  make_fst_210, make_snd_211  };
      letpair_res_895 = id_896;
    }
    return letpair_res_895;
  }
   };
  return fun549;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
