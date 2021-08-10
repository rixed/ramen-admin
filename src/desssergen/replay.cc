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
struct ed5c0948580fc7adda63d975e64ca75f : public std::variant<
  *file_path,
  std::string
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, ed5c0948580fc7adda63d975e64ca75f const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  *fq_function_name,
  *fq_function_name
> v_350131e9cf91ccd34558b5986f609d67;

struct t {
  uint16_t channel;
  *fq_function_name target;
  std::string target_fieldmask;
  double since;
  double until;
  ed5c0948580fc7adda63d975e64ca75f recipient;
  Arr<*fq_function_name> sources;
  Arr<v_350131e9cf91ccd34558b5986f609d67> links;
  double timeout_date;
  bool operator==(t const &other) const {
    return channel == other.channel && target == other.target && target_fieldmask == other.target_fieldmask && since == other.since && until == other.until && recipient == other.recipient && sources == other.sources && links == other.links && timeout_date == other.timeout_date;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "channel:" << r.channel << ',';
  os << "target:" << r.target << ',';
  os << "target_fieldmask:" << r.target_fieldmask << ',';
  os << "since:" << r.since << ',';
  os << "until:" << r.until << ',';
  os << "recipient:" << r.recipient << ',';
  os << "sources:" << r.sources << ',';
  os << "links:" << r.links << ',';
  os << "timeout_date:" << r.timeout_date;
  os << '}';
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
  *fq_function_name,
  Pointer
> v_595d647e09de2457b04e9f962eaa6fd7;

typedef std::tuple<
  Size,
  Pointer
> v_41b0681ed7f1f185fd3e6c4dcdc13110;

typedef std::tuple<
  uint8_t,
  Pointer
> v_1d5843897434feb24d158f3793db9189;

typedef std::tuple<
  std::string,
  Pointer
> v_46a5e81c2410b000ff0adea6dc198147;

typedef std::tuple<
  Bytes,
  Pointer
> f921d1e0a170c3c04148c21704db9c45;

typedef std::tuple<
  uint64_t,
  Pointer
> b62e103e7915a76f45f02f7c6f667c79;

typedef std::tuple<
  double,
  Pointer
> v_41a5a8cf414de9bfdc6375241fcc910a;

typedef std::tuple<
  ed5c0948580fc7adda63d975e64ca75f,
  Pointer
> v_58fbd625a4be51bb7608182ae7c896be;

typedef std::tuple<
  *file_path,
  Pointer
> f0ce35c43c556a289e4bbac0d50849f5;

typedef std::tuple<
  uint32_t,
  Pointer
> ac0fbd05039f742d2f1d9ac182e392ab;

typedef std::tuple<
  Lst<*fq_function_name>,
  Pointer
> e5c39a971595e219b777c7cddbdac2d5;

typedef std::tuple<
  Arr<*fq_function_name>,
  Pointer
> eb64375e5e0c7fea2870ffafcb470176;

typedef std::tuple<
  Lst<v_350131e9cf91ccd34558b5986f609d67>,
  Pointer
> v_2dc6eb72e24ae843c30144dafeaae4e5;

typedef std::tuple<
  Arr<v_350131e9cf91ccd34558b5986f609d67>,
  Pointer
> v_09420c3639fb0fa3828f3fd631ab7a1f;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{channel: U16; target: $fq_function_name; target_fieldmask: STRING; since: FLOAT; until: FLOAT; recipient: [RingBuf $file_path | SyncKey STRING]; sources: $fq_function_name[]; links: ($fq_function_name; $fq_function_name)[]; timeout_date: FLOAT}" "Ptr")
      (let "srec_dst_240"
        (let "srec_dst_232"
          (let "srec_dst_226"
            (let "srec_dst_221"
              (let "srec_dst_220"
                (let "srec_dst_219"
                  (let "srec_dst_216"
                    (let "srec_dst_215" (write-u16 little-endian (param 1) (get-field "channel" (param 0))) (apply (ext-identifier fq_function_name to-row-binary) (get-field "target" (param 0)) (identifier "srec_dst_215")))
                    (write-bytes
                      (let "leb128_sz_217" (make-vec (string-length (get-field "target_fieldmask" (param 0))))
                        (let "leb128_ptr_218" (make-vec (identifier "srec_dst_216"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_218")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_218"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_217"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_217"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_217"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_217") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_217")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_217")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_218"))))) 
                      (bytes-of-string (get-field "target_fieldmask" (param 0))))) 
                  (write-u64 little-endian (identifier "srec_dst_219") (u64-of-float (get-field "since" (param 0))))) 
                (write-u64 little-endian (identifier "srec_dst_220") (u64-of-float (get-field "until" (param 0)))))
              (let "ssum_dst_223" (write-u16 little-endian (identifier "srec_dst_221") (label-of (get-field "recipient" (param 0))))
                (if (eq (u16 0) (label-of (get-field "recipient" (param 0)))) 
                  (apply (ext-identifier file_path to-row-binary) (get-alt "RingBuf" (get-field "recipient" (param 0))) (identifier "ssum_dst_223"))
                  (seq (assert (eq (label-of (get-field "recipient" (param 0))) (u16 1)))
                    (write-bytes
                      (let "leb128_sz_224" (make-vec (string-length (get-alt "SyncKey" (get-field "recipient" (param 0)))))
                        (let "leb128_ptr_225" (make-vec (identifier "ssum_dst_223"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_225")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_225"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_224"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_224"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_224"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_224") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_224")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_224")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_225"))))) 
                      (bytes-of-string (get-alt "SyncKey" (get-field "recipient" (param 0)))))))))
            (let "dst_ref_229"
              (make-vec
                (let "leb128_sz_227" (make-vec (cardinality (get-field "sources" (param 0))))
                  (let "leb128_ptr_228" (make-vec (identifier "srec_dst_226"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_228")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_228"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_227"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_227"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_227"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_227") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_227")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_227")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_228"))))))
              (let "n_ref_230" (make-vec (i32 0))
                (seq
                  (for-each "x_231" (get-field "sources" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_229") (apply (ext-identifier fq_function_name to-row-binary) (identifier "x_231") (unsafe-nth (u8 0) (identifier "dst_ref_229"))))
                      (set-vec (u8 0) (identifier "n_ref_230") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_230")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_229"))))))
          (let "dst_ref_235"
            (make-vec
              (let "leb128_sz_233" (make-vec (cardinality (get-field "links" (param 0))))
                (let "leb128_ptr_234" (make-vec (identifier "srec_dst_232"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_234")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_234"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_233"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_233"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_233"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_233") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_233")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_233")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_234"))))))
            (let "n_ref_236" (make-vec (i32 0))
              (seq
                (for-each "x_237" (get-field "links" (param 0))
                  (seq
                    (set-vec (u8 0) (identifier "dst_ref_235")
                      (let "stup_dst_239" (let "stup_dst_238" (unsafe-nth (u8 0) (identifier "dst_ref_235")) (apply (ext-identifier fq_function_name to-row-binary) (get-item 0 (identifier "x_237")) (identifier "stup_dst_238")))
                        (apply (ext-identifier fq_function_name to-row-binary) (get-item 1 (identifier "x_237")) (identifier "stup_dst_239"))))
                    (set-vec (u8 0) (identifier "n_ref_236") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_236")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_235")))))) (write-u64 little-endian (identifier "srec_dst_240") (u64-of-float (get-field "timeout_date" (param 0))))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    uint16_t id_1 { p_0.channel };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_215 { id_2 };
      std::function<Pointer(*fq_function_name,Pointer)> id_4 { dessser_gen::fq_function_name.to_row_binary };
      *fq_function_name id_5 { p_0.target };
      Pointer id_6 { id_4(id_5, srec_dst_215) };
      let_res_3 = id_6;
    }
    Pointer let_res_7;
    {
      Pointer srec_dst_216 { let_res_3 };
      std::string id_8 { p_0.target_fieldmask };
      uint32_t id_9 { (uint32_t)id_8.size() };
      Vec<1, uint32_t> id_10 {  id_9  };
      Pointer let_res_11;
      {
        Vec<1, uint32_t> leb128_sz_217 { id_10 };
        Vec<1, Pointer> id_12 {  srec_dst_216  };
        Pointer let_res_13;
        {
          Vec<1, Pointer> leb128_ptr_218 { id_12 };
          bool while_flag_14 { true };
          do {
            uint8_t id_15 { 0 };
            uint8_t id_16 { 0 };
            Pointer id_17 { leb128_ptr_218[id_16] };
            uint32_t id_18 { 128U };
            uint8_t id_19 { 0 };
            uint32_t id_20 { leb128_sz_217[id_19] };
            bool id_21 { bool(id_18 > id_20) };
            uint8_t choose_res_22;
            if (id_21) {
              uint8_t id_23 { 0 };
              uint32_t id_24 { leb128_sz_217[id_23] };
              uint8_t id_25 { uint8_t(id_24) };
              choose_res_22 = id_25;
            } else {
              uint8_t id_26 { 0 };
              uint32_t id_27 { leb128_sz_217[id_26] };
              uint8_t id_28 { uint8_t(id_27) };
              uint8_t id_29 { 128 };
              uint8_t id_30 { uint8_t(id_28 | id_29) };
              choose_res_22 = id_30;
            }
            Pointer id_31 { id_17.writeU8(choose_res_22) };
            Void id_32 { ((void)(leb128_ptr_218[id_15] = id_31), VOID) };
            uint8_t id_33 { 0 };
            uint8_t id_34 { 0 };
            uint32_t id_35 { leb128_sz_217[id_34] };
            uint8_t id_36 { 7 };
            uint32_t id_37 { uint32_t(id_35 >> id_36) };
            Void id_38 { ((void)(leb128_sz_217[id_33] = id_37), VOID) };
            uint8_t id_39 { 0 };
            uint32_t id_40 { leb128_sz_217[id_39] };
            uint32_t id_41 { 0U };
            bool id_42 { bool(id_40 > id_41) };
            while_flag_14 = id_42;
            if (while_flag_14) {
            }
          } while (while_flag_14);
          uint8_t id_43 { 0 };
          Pointer id_44 { leb128_ptr_218[id_43] };
          let_res_13 = id_44;
        }
        let_res_11 = let_res_13;
      }
      std::string id_45 { p_0.target_fieldmask };
      Bytes id_46 { id_45 };
      Pointer id_47 { let_res_11.writeBytes(id_46) };
      let_res_7 = id_47;
    }
    Pointer let_res_48;
    {
      Pointer srec_dst_219 { let_res_7 };
      double id_49 { p_0.since };
      uint64_t id_50 { qword_of_float(id_49) };
      Pointer id_51 { srec_dst_219.writeU64Le(id_50) };
      let_res_48 = id_51;
    }
    Pointer let_res_52;
    {
      Pointer srec_dst_220 { let_res_48 };
      double id_53 { p_0.until };
      uint64_t id_54 { qword_of_float(id_53) };
      Pointer id_55 { srec_dst_220.writeU64Le(id_54) };
      let_res_52 = id_55;
    }
    Pointer let_res_56;
    {
      Pointer srec_dst_221 { let_res_52 };
      ed5c0948580fc7adda63d975e64ca75f id_57 { p_0.recipient };
      uint16_t id_58 { uint16_t(id_57.index()) };
      Pointer id_59 { srec_dst_221.writeU16Le(id_58) };
      Pointer let_res_60;
      {
        Pointer ssum_dst_223 { id_59 };
        uint16_t id_61 { 0 };
        ed5c0948580fc7adda63d975e64ca75f id_62 { p_0.recipient };
        uint16_t id_63 { uint16_t(id_62.index()) };
        bool id_64 { bool(id_61 == id_63) };
        Pointer choose_res_65;
        if (id_64) {
          std::function<Pointer(*file_path,Pointer)> id_66 { dessser_gen::file_path.to_row_binary };
          ed5c0948580fc7adda63d975e64ca75f id_67 { p_0.recipient };
          *file_path id_68 { std::get<0>(id_67) };
          Pointer id_69 { id_66(id_68, ssum_dst_223) };
          choose_res_65 = id_69;
        } else {
          ed5c0948580fc7adda63d975e64ca75f id_70 { p_0.recipient };
          uint16_t id_71 { uint16_t(id_70.index()) };
          uint16_t id_72 { 1 };
          bool id_73 { bool(id_71 == id_72) };
          Void id_74 { ((void)(assert(id_73)), VOID) };
          ed5c0948580fc7adda63d975e64ca75f id_75 { p_0.recipient };
          std::string id_76 { std::get<1>(id_75) };
          uint32_t id_77 { (uint32_t)id_76.size() };
          Vec<1, uint32_t> id_78 {  id_77  };
          Pointer let_res_79;
          {
            Vec<1, uint32_t> leb128_sz_224 { id_78 };
            Vec<1, Pointer> id_80 {  ssum_dst_223  };
            Pointer let_res_81;
            {
              Vec<1, Pointer> leb128_ptr_225 { id_80 };
              bool while_flag_82 { true };
              do {
                uint8_t id_83 { 0 };
                uint8_t id_84 { 0 };
                Pointer id_85 { leb128_ptr_225[id_84] };
                uint32_t id_86 { 128U };
                uint8_t id_87 { 0 };
                uint32_t id_88 { leb128_sz_224[id_87] };
                bool id_89 { bool(id_86 > id_88) };
                uint8_t choose_res_90;
                if (id_89) {
                  uint8_t id_91 { 0 };
                  uint32_t id_92 { leb128_sz_224[id_91] };
                  uint8_t id_93 { uint8_t(id_92) };
                  choose_res_90 = id_93;
                } else {
                  uint8_t id_94 { 0 };
                  uint32_t id_95 { leb128_sz_224[id_94] };
                  uint8_t id_96 { uint8_t(id_95) };
                  uint8_t id_97 { 128 };
                  uint8_t id_98 { uint8_t(id_96 | id_97) };
                  choose_res_90 = id_98;
                }
                Pointer id_99 { id_85.writeU8(choose_res_90) };
                Void id_100 { ((void)(leb128_ptr_225[id_83] = id_99), VOID) };
                uint8_t id_101 { 0 };
                uint8_t id_102 { 0 };
                uint32_t id_103 { leb128_sz_224[id_102] };
                uint8_t id_104 { 7 };
                uint32_t id_105 { uint32_t(id_103 >> id_104) };
                Void id_106 { ((void)(leb128_sz_224[id_101] = id_105), VOID) };
                uint8_t id_107 { 0 };
                uint32_t id_108 { leb128_sz_224[id_107] };
                uint32_t id_109 { 0U };
                bool id_110 { bool(id_108 > id_109) };
                while_flag_82 = id_110;
                if (while_flag_82) {
                }
              } while (while_flag_82);
              uint8_t id_111 { 0 };
              Pointer id_112 { leb128_ptr_225[id_111] };
              let_res_81 = id_112;
            }
            let_res_79 = let_res_81;
          }
          ed5c0948580fc7adda63d975e64ca75f id_113 { p_0.recipient };
          std::string id_114 { std::get<1>(id_113) };
          Bytes id_115 { id_114 };
          Pointer id_116 { let_res_79.writeBytes(id_115) };
          choose_res_65 = id_116;
        }
        let_res_60 = choose_res_65;
      }
      let_res_56 = let_res_60;
    }
    Pointer let_res_117;
    {
      Pointer srec_dst_226 { let_res_56 };
      Arr<*fq_function_name> id_118 { p_0.sources };
      uint32_t id_119 { id_118.size() };
      Vec<1, uint32_t> id_120 {  id_119  };
      Pointer let_res_121;
      {
        Vec<1, uint32_t> leb128_sz_227 { id_120 };
        Vec<1, Pointer> id_122 {  srec_dst_226  };
        Pointer let_res_123;
        {
          Vec<1, Pointer> leb128_ptr_228 { id_122 };
          bool while_flag_124 { true };
          do {
            uint8_t id_125 { 0 };
            uint8_t id_126 { 0 };
            Pointer id_127 { leb128_ptr_228[id_126] };
            uint32_t id_128 { 128U };
            uint8_t id_129 { 0 };
            uint32_t id_130 { leb128_sz_227[id_129] };
            bool id_131 { bool(id_128 > id_130) };
            uint8_t choose_res_132;
            if (id_131) {
              uint8_t id_133 { 0 };
              uint32_t id_134 { leb128_sz_227[id_133] };
              uint8_t id_135 { uint8_t(id_134) };
              choose_res_132 = id_135;
            } else {
              uint8_t id_136 { 0 };
              uint32_t id_137 { leb128_sz_227[id_136] };
              uint8_t id_138 { uint8_t(id_137) };
              uint8_t id_139 { 128 };
              uint8_t id_140 { uint8_t(id_138 | id_139) };
              choose_res_132 = id_140;
            }
            Pointer id_141 { id_127.writeU8(choose_res_132) };
            Void id_142 { ((void)(leb128_ptr_228[id_125] = id_141), VOID) };
            uint8_t id_143 { 0 };
            uint8_t id_144 { 0 };
            uint32_t id_145 { leb128_sz_227[id_144] };
            uint8_t id_146 { 7 };
            uint32_t id_147 { uint32_t(id_145 >> id_146) };
            Void id_148 { ((void)(leb128_sz_227[id_143] = id_147), VOID) };
            uint8_t id_149 { 0 };
            uint32_t id_150 { leb128_sz_227[id_149] };
            uint32_t id_151 { 0U };
            bool id_152 { bool(id_150 > id_151) };
            while_flag_124 = id_152;
            if (while_flag_124) {
            }
          } while (while_flag_124);
          uint8_t id_153 { 0 };
          Pointer id_154 { leb128_ptr_228[id_153] };
          let_res_123 = id_154;
        }
        let_res_121 = let_res_123;
      }
      Vec<1, Pointer> id_155 {  let_res_121  };
      Pointer let_res_156;
      {
        Vec<1, Pointer> dst_ref_229 { id_155 };
        int32_t id_157 { 0L };
        Vec<1, int32_t> id_158 {  id_157  };
        Pointer let_res_159;
        {
          Vec<1, int32_t> n_ref_230 { id_158 };
          Arr<*fq_function_name> id_160 { p_0.sources };
          for (*fq_function_name x_231 : id_160) {
            uint8_t id_161 { 0 };
            std::function<Pointer(*fq_function_name,Pointer)> id_162 { dessser_gen::fq_function_name.to_row_binary };
            uint8_t id_163 { 0 };
            Pointer id_164 { dst_ref_229[id_163] };
            Pointer id_165 { id_162(x_231, id_164) };
            Void id_166 { ((void)(dst_ref_229[id_161] = id_165), VOID) };
            uint8_t id_167 { 0 };
            int32_t id_168 { 1L };
            uint8_t id_169 { 0 };
            int32_t id_170 { n_ref_230[id_169] };
            int32_t id_171 { int32_t(id_168 + id_170) };
            Void id_172 { ((void)(n_ref_230[id_167] = id_171), VOID) };
          }
          uint8_t id_173 { 0 };
          Pointer id_174 { dst_ref_229[id_173] };
          let_res_159 = id_174;
        }
        let_res_156 = let_res_159;
      }
      let_res_117 = let_res_156;
    }
    Pointer let_res_175;
    {
      Pointer srec_dst_232 { let_res_117 };
      Arr<v_350131e9cf91ccd34558b5986f609d67> id_176 { p_0.links };
      uint32_t id_177 { id_176.size() };
      Vec<1, uint32_t> id_178 {  id_177  };
      Pointer let_res_179;
      {
        Vec<1, uint32_t> leb128_sz_233 { id_178 };
        Vec<1, Pointer> id_180 {  srec_dst_232  };
        Pointer let_res_181;
        {
          Vec<1, Pointer> leb128_ptr_234 { id_180 };
          bool while_flag_182 { true };
          do {
            uint8_t id_183 { 0 };
            uint8_t id_184 { 0 };
            Pointer id_185 { leb128_ptr_234[id_184] };
            uint32_t id_186 { 128U };
            uint8_t id_187 { 0 };
            uint32_t id_188 { leb128_sz_233[id_187] };
            bool id_189 { bool(id_186 > id_188) };
            uint8_t choose_res_190;
            if (id_189) {
              uint8_t id_191 { 0 };
              uint32_t id_192 { leb128_sz_233[id_191] };
              uint8_t id_193 { uint8_t(id_192) };
              choose_res_190 = id_193;
            } else {
              uint8_t id_194 { 0 };
              uint32_t id_195 { leb128_sz_233[id_194] };
              uint8_t id_196 { uint8_t(id_195) };
              uint8_t id_197 { 128 };
              uint8_t id_198 { uint8_t(id_196 | id_197) };
              choose_res_190 = id_198;
            }
            Pointer id_199 { id_185.writeU8(choose_res_190) };
            Void id_200 { ((void)(leb128_ptr_234[id_183] = id_199), VOID) };
            uint8_t id_201 { 0 };
            uint8_t id_202 { 0 };
            uint32_t id_203 { leb128_sz_233[id_202] };
            uint8_t id_204 { 7 };
            uint32_t id_205 { uint32_t(id_203 >> id_204) };
            Void id_206 { ((void)(leb128_sz_233[id_201] = id_205), VOID) };
            uint8_t id_207 { 0 };
            uint32_t id_208 { leb128_sz_233[id_207] };
            uint32_t id_209 { 0U };
            bool id_210 { bool(id_208 > id_209) };
            while_flag_182 = id_210;
            if (while_flag_182) {
            }
          } while (while_flag_182);
          uint8_t id_211 { 0 };
          Pointer id_212 { leb128_ptr_234[id_211] };
          let_res_181 = id_212;
        }
        let_res_179 = let_res_181;
      }
      Vec<1, Pointer> id_213 {  let_res_179  };
      Pointer let_res_214;
      {
        Vec<1, Pointer> dst_ref_235 { id_213 };
        int32_t id_215 { 0L };
        Vec<1, int32_t> id_216 {  id_215  };
        Pointer let_res_217;
        {
          Vec<1, int32_t> n_ref_236 { id_216 };
          Arr<v_350131e9cf91ccd34558b5986f609d67> id_218 { p_0.links };
          for (v_350131e9cf91ccd34558b5986f609d67 x_237 : id_218) {
            uint8_t id_219 { 0 };
            uint8_t id_220 { 0 };
            Pointer id_221 { dst_ref_235[id_220] };
            Pointer let_res_222;
            {
              Pointer stup_dst_238 { id_221 };
              std::function<Pointer(*fq_function_name,Pointer)> id_223 { dessser_gen::fq_function_name.to_row_binary };
              *fq_function_name id_224 { std::get<0>(x_237) };
              Pointer id_225 { id_223(id_224, stup_dst_238) };
              let_res_222 = id_225;
            }
            Pointer let_res_226;
            {
              Pointer stup_dst_239 { let_res_222 };
              std::function<Pointer(*fq_function_name,Pointer)> id_227 { dessser_gen::fq_function_name.to_row_binary };
              *fq_function_name id_228 { std::get<1>(x_237) };
              Pointer id_229 { id_227(id_228, stup_dst_239) };
              let_res_226 = id_229;
            }
            Void id_230 { ((void)(dst_ref_235[id_219] = let_res_226), VOID) };
            uint8_t id_231 { 0 };
            int32_t id_232 { 1L };
            uint8_t id_233 { 0 };
            int32_t id_234 { n_ref_236[id_233] };
            int32_t id_235 { int32_t(id_232 + id_234) };
            Void id_236 { ((void)(n_ref_236[id_231] = id_235), VOID) };
          }
          uint8_t id_237 { 0 };
          Pointer id_238 { dst_ref_235[id_237] };
          let_res_217 = id_238;
        }
        let_res_214 = let_res_217;
      }
      let_res_175 = let_res_214;
    }
    Pointer let_res_239;
    {
      Pointer srec_dst_240 { let_res_175 };
      double id_240 { p_0.timeout_date };
      uint64_t id_241 { qword_of_float(id_240) };
      Pointer id_242 { srec_dst_240.writeU64Le(id_241) };
      let_res_239 = id_242;
    }
    return let_res_239;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{channel: U16; target: $fq_function_name; target_fieldmask: STRING; since: FLOAT; until: FLOAT; recipient: [RingBuf $file_path | SyncKey STRING]; sources: $fq_function_name[]; links: ($fq_function_name; $fq_function_name)[]; timeout_date: FLOAT}")
      (add
        (let "sz_207"
          (let "sz_202"
            (let "sz_197"
              (add
                (add
                  (let "sz_191" (add (size 2) (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-field "target" (param 0))))
                    (add (identifier "sz_191")
                      (add
                        (let "n_ref_193" (make-vec (string-length (get-field "target_fieldmask" (param 0))))
                          (let "lebsz_ref_194" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_193")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_194")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_194") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_194")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_194")))))) 
                        (size-of-u32 (string-length (get-field "target_fieldmask" (param 0))))))) 
                  (size 8)) (size 8))
              (if (eq (u16 0) (label-of (get-field "recipient" (param 0)))) 
                (add (add (identifier "sz_197") (size 2)) (apply (ext-identifier file_path sersize-of-row-binary) (get-alt "RingBuf" (get-field "recipient" (param 0)))))
                (seq (assert (eq (label-of (get-field "recipient" (param 0))) (u16 1)))
                  (add (add (identifier "sz_197") (size 2))
                    (add
                      (let "n_ref_200" (make-vec (string-length (get-alt "SyncKey" (get-field "recipient" (param 0)))))
                        (let "lebsz_ref_201" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_200")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_201")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_201") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_201")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_201")))))) 
                      (size-of-u32 (string-length (get-alt "SyncKey" (get-field "recipient" (param 0))))))))))
            (let "sz_ref_205"
              (make-vec
                (add (identifier "sz_202")
                  (let "n_ref_203" (make-vec (cardinality (get-field "sources" (param 0))))
                    (let "lebsz_ref_204" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_203")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_204")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_204") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_204")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_204"))))))))
              (seq
                (let "repeat_n_206" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "sources" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_206")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_205")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_205"))
                          (apply (ext-identifier fq_function_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_206")) (get-field "sources" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_206") (add (unsafe-nth (u8 0) (identifier "repeat_n_206")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_205")))))
          (let "sz_ref_210"
            (make-vec
              (add (identifier "sz_207")
                (let "n_ref_208" (make-vec (cardinality (get-field "links" (param 0))))
                  (let "lebsz_ref_209" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_208")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_209")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_209") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_209")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_209"))))))))
            (seq
              (let "repeat_n_211" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "links" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_211")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_210")
                      (let "sz_213"
                        (let "sz_212" (unsafe-nth (u8 0) (identifier "sz_ref_210"))
                          (add (identifier "sz_212") (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_211")) (get-field "links" (param 0)))))))
                        (add (identifier "sz_213") (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_211")) (get-field "links" (param 0))))))))
                    (set-vec (u8 0) (identifier "repeat_n_211") (add (unsafe-nth (u8 0) (identifier "repeat_n_211")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_210"))))) (size 8)))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun243 { [&fun243](t p_0) {
    Size id_244 { 2UL };
    std::function<Size(*fq_function_name)> id_245 { dessser_gen::fq_function_name.sersize_of_row_binary };
    *fq_function_name id_246 { p_0.target };
    Size id_247 { id_245(id_246) };
    Size id_248 { Size(id_244 + id_247) };
    Size let_res_249;
    {
      Size sz_191 { id_248 };
      std::string id_250 { p_0.target_fieldmask };
      uint32_t id_251 { (uint32_t)id_250.size() };
      Vec<1, uint32_t> id_252 {  id_251  };
      Size let_res_253;
      {
        Vec<1, uint32_t> n_ref_193 { id_252 };
        uint32_t id_254 { 1U };
        Vec<1, uint32_t> id_255 {  id_254  };
        Size let_res_256;
        {
          Vec<1, uint32_t> lebsz_ref_194 { id_255 };
          bool while_flag_257 { true };
          do {
            uint8_t id_258 { 0 };
            uint32_t id_259 { n_ref_193[id_258] };
            uint8_t id_260 { 0 };
            uint32_t id_261 { lebsz_ref_194[id_260] };
            uint8_t id_262 { 7 };
            uint32_t id_263 { uint32_t(id_261 << id_262) };
            bool id_264 { bool(id_259 >= id_263) };
            while_flag_257 = id_264;
            if (while_flag_257) {
              uint8_t id_265 { 0 };
              uint8_t id_266 { 0 };
              uint32_t id_267 { lebsz_ref_194[id_266] };
              uint32_t id_268 { 1U };
              uint32_t id_269 { uint32_t(id_267 + id_268) };
              Void id_270 { ((void)(lebsz_ref_194[id_265] = id_269), VOID) };
            }
          } while (while_flag_257);
          uint8_t id_271 { 0 };
          uint32_t id_272 { lebsz_ref_194[id_271] };
          Size id_273 { Size(id_272) };
          let_res_256 = id_273;
        }
        let_res_253 = let_res_256;
      }
      std::string id_274 { p_0.target_fieldmask };
      uint32_t id_275 { (uint32_t)id_274.size() };
      Size id_276 { Size(id_275) };
      Size id_277 { Size(let_res_253 + id_276) };
      Size id_278 { Size(sz_191 + id_277) };
      let_res_249 = id_278;
    }
    Size id_279 { 8UL };
    Size id_280 { Size(let_res_249 + id_279) };
    Size id_281 { 8UL };
    Size id_282 { Size(id_280 + id_281) };
    Size let_res_283;
    {
      Size sz_197 { id_282 };
      uint16_t id_284 { 0 };
      ed5c0948580fc7adda63d975e64ca75f id_285 { p_0.recipient };
      uint16_t id_286 { uint16_t(id_285.index()) };
      bool id_287 { bool(id_284 == id_286) };
      Size choose_res_288;
      if (id_287) {
        Size id_289 { 2UL };
        Size id_290 { Size(sz_197 + id_289) };
        std::function<Size(*file_path)> id_291 { dessser_gen::file_path.sersize_of_row_binary };
        ed5c0948580fc7adda63d975e64ca75f id_292 { p_0.recipient };
        *file_path id_293 { std::get<0>(id_292) };
        Size id_294 { id_291(id_293) };
        Size id_295 { Size(id_290 + id_294) };
        choose_res_288 = id_295;
      } else {
        ed5c0948580fc7adda63d975e64ca75f id_296 { p_0.recipient };
        uint16_t id_297 { uint16_t(id_296.index()) };
        uint16_t id_298 { 1 };
        bool id_299 { bool(id_297 == id_298) };
        Void id_300 { ((void)(assert(id_299)), VOID) };
        Size id_301 { 2UL };
        Size id_302 { Size(sz_197 + id_301) };
        ed5c0948580fc7adda63d975e64ca75f id_303 { p_0.recipient };
        std::string id_304 { std::get<1>(id_303) };
        uint32_t id_305 { (uint32_t)id_304.size() };
        Vec<1, uint32_t> id_306 {  id_305  };
        Size let_res_307;
        {
          Vec<1, uint32_t> n_ref_200 { id_306 };
          uint32_t id_308 { 1U };
          Vec<1, uint32_t> id_309 {  id_308  };
          Size let_res_310;
          {
            Vec<1, uint32_t> lebsz_ref_201 { id_309 };
            bool while_flag_311 { true };
            do {
              uint8_t id_312 { 0 };
              uint32_t id_313 { n_ref_200[id_312] };
              uint8_t id_314 { 0 };
              uint32_t id_315 { lebsz_ref_201[id_314] };
              uint8_t id_316 { 7 };
              uint32_t id_317 { uint32_t(id_315 << id_316) };
              bool id_318 { bool(id_313 >= id_317) };
              while_flag_311 = id_318;
              if (while_flag_311) {
                uint8_t id_319 { 0 };
                uint8_t id_320 { 0 };
                uint32_t id_321 { lebsz_ref_201[id_320] };
                uint32_t id_322 { 1U };
                uint32_t id_323 { uint32_t(id_321 + id_322) };
                Void id_324 { ((void)(lebsz_ref_201[id_319] = id_323), VOID) };
              }
            } while (while_flag_311);
            uint8_t id_325 { 0 };
            uint32_t id_326 { lebsz_ref_201[id_325] };
            Size id_327 { Size(id_326) };
            let_res_310 = id_327;
          }
          let_res_307 = let_res_310;
        }
        ed5c0948580fc7adda63d975e64ca75f id_328 { p_0.recipient };
        std::string id_329 { std::get<1>(id_328) };
        uint32_t id_330 { (uint32_t)id_329.size() };
        Size id_331 { Size(id_330) };
        Size id_332 { Size(let_res_307 + id_331) };
        Size id_333 { Size(id_302 + id_332) };
        choose_res_288 = id_333;
      }
      let_res_283 = choose_res_288;
    }
    Size let_res_334;
    {
      Size sz_202 { let_res_283 };
      Arr<*fq_function_name> id_335 { p_0.sources };
      uint32_t id_336 { id_335.size() };
      Vec<1, uint32_t> id_337 {  id_336  };
      Size let_res_338;
      {
        Vec<1, uint32_t> n_ref_203 { id_337 };
        uint32_t id_339 { 1U };
        Vec<1, uint32_t> id_340 {  id_339  };
        Size let_res_341;
        {
          Vec<1, uint32_t> lebsz_ref_204 { id_340 };
          bool while_flag_342 { true };
          do {
            uint8_t id_343 { 0 };
            uint32_t id_344 { n_ref_203[id_343] };
            uint8_t id_345 { 0 };
            uint32_t id_346 { lebsz_ref_204[id_345] };
            uint8_t id_347 { 7 };
            uint32_t id_348 { uint32_t(id_346 << id_347) };
            bool id_349 { bool(id_344 >= id_348) };
            while_flag_342 = id_349;
            if (while_flag_342) {
              uint8_t id_350 { 0 };
              uint8_t id_351 { 0 };
              uint32_t id_352 { lebsz_ref_204[id_351] };
              uint32_t id_353 { 1U };
              uint32_t id_354 { uint32_t(id_352 + id_353) };
              Void id_355 { ((void)(lebsz_ref_204[id_350] = id_354), VOID) };
            }
          } while (while_flag_342);
          uint8_t id_356 { 0 };
          uint32_t id_357 { lebsz_ref_204[id_356] };
          Size id_358 { Size(id_357) };
          let_res_341 = id_358;
        }
        let_res_338 = let_res_341;
      }
      Size id_359 { Size(sz_202 + let_res_338) };
      Vec<1, Size> id_360 {  id_359  };
      Size let_res_361;
      {
        Vec<1, Size> sz_ref_205 { id_360 };
        int32_t id_362 { 0L };
        Vec<1, int32_t> id_363 {  id_362  };
        {
          Vec<1, int32_t> repeat_n_206 { id_363 };
          bool while_flag_364 { true };
          do {
            Arr<*fq_function_name> id_365 { p_0.sources };
            uint32_t id_366 { id_365.size() };
            int32_t id_367 { int32_t(id_366) };
            uint8_t id_368 { 0 };
            int32_t id_369 { repeat_n_206[id_368] };
            bool id_370 { bool(id_367 > id_369) };
            while_flag_364 = id_370;
            if (while_flag_364) {
              uint8_t id_371 { 0 };
              uint8_t id_372 { 0 };
              Size id_373 { sz_ref_205[id_372] };
              std::function<Size(*fq_function_name)> id_374 { dessser_gen::fq_function_name.sersize_of_row_binary };
              uint8_t id_375 { 0 };
              int32_t id_376 { repeat_n_206[id_375] };
              Arr<*fq_function_name> id_377 { p_0.sources };
              *fq_function_name id_378 { id_377[id_376] };
              Size id_379 { id_374(id_378) };
              Size id_380 { Size(id_373 + id_379) };
              Void id_381 { ((void)(sz_ref_205[id_371] = id_380), VOID) };
              uint8_t id_382 { 0 };
              uint8_t id_383 { 0 };
              int32_t id_384 { repeat_n_206[id_383] };
              int32_t id_385 { 1L };
              int32_t id_386 { int32_t(id_384 + id_385) };
              Void id_387 { ((void)(repeat_n_206[id_382] = id_386), VOID) };
            }
          } while (while_flag_364);
        }
        uint8_t id_388 { 0 };
        Size id_389 { sz_ref_205[id_388] };
        let_res_361 = id_389;
      }
      let_res_334 = let_res_361;
    }
    Size let_res_390;
    {
      Size sz_207 { let_res_334 };
      Arr<v_350131e9cf91ccd34558b5986f609d67> id_391 { p_0.links };
      uint32_t id_392 { id_391.size() };
      Vec<1, uint32_t> id_393 {  id_392  };
      Size let_res_394;
      {
        Vec<1, uint32_t> n_ref_208 { id_393 };
        uint32_t id_395 { 1U };
        Vec<1, uint32_t> id_396 {  id_395  };
        Size let_res_397;
        {
          Vec<1, uint32_t> lebsz_ref_209 { id_396 };
          bool while_flag_398 { true };
          do {
            uint8_t id_399 { 0 };
            uint32_t id_400 { n_ref_208[id_399] };
            uint8_t id_401 { 0 };
            uint32_t id_402 { lebsz_ref_209[id_401] };
            uint8_t id_403 { 7 };
            uint32_t id_404 { uint32_t(id_402 << id_403) };
            bool id_405 { bool(id_400 >= id_404) };
            while_flag_398 = id_405;
            if (while_flag_398) {
              uint8_t id_406 { 0 };
              uint8_t id_407 { 0 };
              uint32_t id_408 { lebsz_ref_209[id_407] };
              uint32_t id_409 { 1U };
              uint32_t id_410 { uint32_t(id_408 + id_409) };
              Void id_411 { ((void)(lebsz_ref_209[id_406] = id_410), VOID) };
            }
          } while (while_flag_398);
          uint8_t id_412 { 0 };
          uint32_t id_413 { lebsz_ref_209[id_412] };
          Size id_414 { Size(id_413) };
          let_res_397 = id_414;
        }
        let_res_394 = let_res_397;
      }
      Size id_415 { Size(sz_207 + let_res_394) };
      Vec<1, Size> id_416 {  id_415  };
      Size let_res_417;
      {
        Vec<1, Size> sz_ref_210 { id_416 };
        int32_t id_418 { 0L };
        Vec<1, int32_t> id_419 {  id_418  };
        {
          Vec<1, int32_t> repeat_n_211 { id_419 };
          bool while_flag_420 { true };
          do {
            Arr<v_350131e9cf91ccd34558b5986f609d67> id_421 { p_0.links };
            uint32_t id_422 { id_421.size() };
            int32_t id_423 { int32_t(id_422) };
            uint8_t id_424 { 0 };
            int32_t id_425 { repeat_n_211[id_424] };
            bool id_426 { bool(id_423 > id_425) };
            while_flag_420 = id_426;
            if (while_flag_420) {
              uint8_t id_427 { 0 };
              uint8_t id_428 { 0 };
              Size id_429 { sz_ref_210[id_428] };
              Size let_res_430;
              {
                Size sz_212 { id_429 };
                std::function<Size(*fq_function_name)> id_431 { dessser_gen::fq_function_name.sersize_of_row_binary };
                uint8_t id_432 { 0 };
                int32_t id_433 { repeat_n_211[id_432] };
                Arr<v_350131e9cf91ccd34558b5986f609d67> id_434 { p_0.links };
                v_350131e9cf91ccd34558b5986f609d67 id_435 { id_434[id_433] };
                *fq_function_name id_436 { std::get<0>(id_435) };
                Size id_437 { id_431(id_436) };
                Size id_438 { Size(sz_212 + id_437) };
                let_res_430 = id_438;
              }
              Size let_res_439;
              {
                Size sz_213 { let_res_430 };
                std::function<Size(*fq_function_name)> id_440 { dessser_gen::fq_function_name.sersize_of_row_binary };
                uint8_t id_441 { 0 };
                int32_t id_442 { repeat_n_211[id_441] };
                Arr<v_350131e9cf91ccd34558b5986f609d67> id_443 { p_0.links };
                v_350131e9cf91ccd34558b5986f609d67 id_444 { id_443[id_442] };
                *fq_function_name id_445 { std::get<1>(id_444) };
                Size id_446 { id_440(id_445) };
                Size id_447 { Size(sz_213 + id_446) };
                let_res_439 = id_447;
              }
              Void id_448 { ((void)(sz_ref_210[id_427] = let_res_439), VOID) };
              uint8_t id_449 { 0 };
              uint8_t id_450 { 0 };
              int32_t id_451 { repeat_n_211[id_450] };
              int32_t id_452 { 1L };
              int32_t id_453 { int32_t(id_451 + id_452) };
              Void id_454 { ((void)(repeat_n_211[id_449] = id_453), VOID) };
            }
          } while (while_flag_420);
        }
        uint8_t id_455 { 0 };
        Size id_456 { sz_ref_210[id_455] };
        let_res_417 = id_456;
      }
      let_res_390 = let_res_417;
    }
    Size id_457 { 8UL };
    Size id_458 { Size(let_res_390 + id_457) };
    return id_458;
  }
   };
  return fun243;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_59" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
          (let "drec_62" (apply (ext-identifier fq_function_name of-row-binary) (identifier "drec_snd_61"))
            (let-pair "drec_fst_63" "drec_snd_64" (identifier "drec_62")
              (let "drec_77"
                (let "dstring1_71"
                  (let "leb_ref_65" (make-vec (u32 0))
                    (let "shft_ref_66" (make-vec (u8 0))
                      (let "p_ref_67" (make-vec (identifier "drec_snd_64"))
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
                    (let-pair "dstring2_fst_75" "dstring2_snd_76" (read-bytes (identifier "dstring1_snd_73") (identifier "dstring1_fst_72"))
                      (make-tup (string-of-bytes (identifier "dstring2_fst_75")) (identifier "dstring2_snd_76")))))
                (let-pair "drec_fst_78" "drec_snd_79" (identifier "drec_77")
                  (let "drec_83" (let-pair "dfloat_fst_81" "dfloat_snd_82" (read-u64 little-endian (identifier "drec_snd_79")) (make-tup (float-of-u64 (identifier "dfloat_fst_81")) (identifier "dfloat_snd_82")))
                    (let-pair "drec_fst_84" "drec_snd_85" (identifier "drec_83")
                      (let "drec_89" (let-pair "dfloat_fst_87" "dfloat_snd_88" (read-u64 little-endian (identifier "drec_snd_85")) (make-tup (float-of-u64 (identifier "dfloat_fst_87")) (identifier "dfloat_snd_88")))
                        (let-pair "drec_fst_90" "drec_snd_91" (identifier "drec_89")
                          (let "drec_119"
                            (let "dsum1_98" (let-pair "du16_fst_93" "du16_snd_94" (read-u16 little-endian (identifier "drec_snd_91")) (make-tup (identifier "du16_fst_93") (identifier "du16_snd_94")))
                              (let-pair "dsum1_fst_99" "dsum1_snd_100" 
                                (identifier "dsum1_98")
                                (if (eq (u16 0) (identifier "dsum1_fst_99"))
                                  (let-pair "dsum2_fst_117" "dsum2_snd_118" 
                                    (apply (ext-identifier file_path of-row-binary) (identifier "dsum1_snd_100"))
                                    (make-tup (construct "[RingBuf $file_path | SyncKey STRING]" 0 (identifier "dsum2_fst_117")) (identifier "dsum2_snd_118")))
                                  (seq (assert (eq (identifier "dsum1_fst_99") (u16 1)))
                                    (let "dstring1_107"
                                      (let "leb_ref_101" (make-vec (u32 0))
                                        (let "shft_ref_102" (make-vec (u8 0))
                                          (let "p_ref_103" (make-vec (identifier "dsum1_snd_100"))
                                            (seq
                                              (while
                                                (let "leb128_104" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_103")))
                                                  (let-pair "leb128_fst_105" "leb128_snd_106" 
                                                    (identifier "leb128_104")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_103") (identifier "leb128_snd_106"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_101")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_105") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_102")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_101")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_102") (add (unsafe-nth (u8 0) (identifier "shft_ref_102")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_105") (u8 128))))) 
                                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_101"))) (unsafe-nth (u8 0) (identifier "p_ref_103")))))))
                                      (let-pair "dstring1_fst_108" "dstring1_snd_109" 
                                        (identifier "dstring1_107")
                                        (let-pair "dstring2_fst_111" "dstring2_snd_112" 
                                          (read-bytes (identifier "dstring1_snd_109") (identifier "dstring1_fst_108"))
                                          (make-tup (construct "[RingBuf $file_path | SyncKey STRING]" 1 (string-of-bytes (identifier "dstring2_fst_111"))) (identifier "dstring2_snd_112")))))))))
                            (let-pair "drec_fst_120" "drec_snd_121" (identifier "drec_119")
                              (let "drec_145"
                                (let-pair "dlist4_fst_143" "dlist4_snd_144"
                                  (let "dlist1_131"
                                    (let "leb_ref_122" (make-vec (u32 0))
                                      (let "shft_ref_123" (make-vec (u8 0))
                                        (let "p_ref_124" (make-vec (identifier "drec_snd_121"))
                                          (seq
                                            (while
                                              (let "leb128_125" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_124")))
                                                (let-pair "leb128_fst_126" "leb128_snd_127" 
                                                  (identifier "leb128_125")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_124") (identifier "leb128_snd_127"))
                                                    (set-vec (u8 0) (identifier "leb_ref_122")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_126") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_123"))) (unsafe-nth (u8 0) (identifier "leb_ref_122"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_123") (add (unsafe-nth (u8 0) (identifier "shft_ref_123")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_126") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_122")) (unsafe-nth (u8 0) (identifier "p_ref_124")))))))
                                    (let-pair "dlist1_fst_132" "dlist1_snd_133" 
                                      (identifier "dlist1_131")
                                      (let "inits_src_ref_134" (make-vec (make-tup (end-of-list "$fq_function_name") (identifier "dlist1_snd_133")))
                                        (seq
                                          (let "repeat_n_135" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_132")) (unsafe-nth (u8 0) (identifier "repeat_n_135")))
                                              (seq
                                                (let "dlist2_136" (unsafe-nth (u8 0) (identifier "inits_src_ref_134"))
                                                  (let-pair "dlist2_fst_137" "dlist2_snd_138" 
                                                    (identifier "dlist2_136")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_134")
                                                      (let-pair "dlist3_fst_140" "dlist3_snd_141" 
                                                        (apply (ext-identifier fq_function_name of-row-binary) (identifier "dlist2_snd_138"))
                                                        (make-tup (cons (identifier "dlist3_fst_140") (identifier "dlist2_fst_137")) (identifier "dlist3_snd_141"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_135") (add (unsafe-nth (u8 0) (identifier "repeat_n_135")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_134")))))) 
                                  (make-tup (arr-of-lst-rev (identifier "dlist4_fst_143")) (identifier "dlist4_snd_144")))
                                (let-pair "drec_fst_146" "drec_snd_147" 
                                  (identifier "drec_145")
                                  (let "drec_177"
                                    (let-pair "dlist4_fst_175" "dlist4_snd_176"
                                      (let "dlist1_157"
                                        (let "leb_ref_148" (make-vec (u32 0))
                                          (let "shft_ref_149" (make-vec (u8 0))
                                            (let "p_ref_150" (make-vec (identifier "drec_snd_147"))
                                              (seq
                                                (while
                                                  (let "leb128_151" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_150")))
                                                    (let-pair "leb128_fst_152" "leb128_snd_153" 
                                                      (identifier "leb128_151")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_150") (identifier "leb128_snd_153"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_148")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_152") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_149")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_148")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_149") (add (unsafe-nth (u8 0) (identifier "shft_ref_149")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_152") (u8 128))))) 
                                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_148")) (unsafe-nth (u8 0) (identifier "p_ref_150")))))))
                                        (let-pair "dlist1_fst_158" "dlist1_snd_159" 
                                          (identifier "dlist1_157")
                                          (let "inits_src_ref_160" (make-vec (make-tup (end-of-list "($fq_function_name; $fq_function_name)") (identifier "dlist1_snd_159")))
                                            (seq
                                              (let "repeat_n_161" (make-vec (i32 0))
                                                (while (gt (to-i32 (identifier "dlist1_fst_158")) (unsafe-nth (u8 0) (identifier "repeat_n_161")))
                                                  (seq
                                                    (let "dlist2_162" 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_160"))
                                                      (let-pair "dlist2_fst_163" "dlist2_snd_164" 
                                                        (identifier "dlist2_162")
                                                        (set-vec (u8 0) 
                                                          (identifier "inits_src_ref_160")
                                                          (let "dtup_165" 
                                                            (apply (ext-identifier fq_function_name of-row-binary) (identifier "dlist2_snd_164"))
                                                            (let-pair "dtup_fst_166" "dtup_snd_167" 
                                                              (identifier "dtup_165")
                                                              (let-pair "dtup_fst_169" "dtup_snd_170" 
                                                                (apply (ext-identifier fq_function_name of-row-binary) (identifier "dtup_snd_167"))
                                                                (make-tup (cons (make-tup (identifier "dtup_fst_166") (identifier "dtup_fst_169")) (identifier "dlist2_fst_163")) (identifier "dtup_snd_170"))))))))
                                                    (set-vec (u8 0) (identifier "repeat_n_161") (add (unsafe-nth (u8 0) (identifier "repeat_n_161")) (i32 1)))))) 
                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_160")))))) 
                                      (make-tup (arr-of-lst-rev (identifier "dlist4_fst_175")) (identifier "dlist4_snd_176")))
                                    (let-pair "drec_fst_178" "drec_snd_179" 
                                      (identifier "drec_177")
                                      (let-pair "dfloat_fst_181" "dfloat_snd_182" 
                                        (read-u64 little-endian (identifier "drec_snd_179"))
                                        (make-tup
                                          (make-rec (string "channel") 
                                            (identifier "drec_fst_60") 
                                            (string "target") (identifier "drec_fst_63") 
                                            (string "target_fieldmask") 
                                            (identifier "drec_fst_78") 
                                            (string "since") (identifier "drec_fst_84") 
                                            (string "until") (identifier "drec_fst_90") 
                                            (string "recipient") (identifier "drec_fst_120") 
                                            (string "sources") (identifier "drec_fst_146") 
                                            (string "links") (identifier "drec_fst_178") 
                                            (string "timeout_date") (float-of-u64 (identifier "dfloat_fst_181"))) 
                                          (identifier "dfloat_snd_182"))))))))))))))))))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun459 { [&fun459](Pointer p_0) {
    v_362f9d9108a6902af48b6c83d5377ea1 id_460 { p_0.readU16Le() };
    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_461;
    {
      auto du16_fst_57 { std::get<0>(id_460) };
      auto du16_snd_58 { std::get<1>(id_460) };
      v_362f9d9108a6902af48b6c83d5377ea1 id_462 {  du16_fst_57, du16_snd_58  };
      letpair_res_461 = id_462;
    }
    f63f919559f0d70225bd0da5dd9bcafc let_res_463;
    {
      v_362f9d9108a6902af48b6c83d5377ea1 drec_59 { letpair_res_461 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_464;
      {
        auto drec_fst_60 { std::get<0>(drec_59) };
        auto drec_snd_61 { std::get<1>(drec_59) };
        std::function<v_595d647e09de2457b04e9f962eaa6fd7(Pointer)> id_465 { dessser_gen::fq_function_name.of_row_binary };
        v_595d647e09de2457b04e9f962eaa6fd7 id_466 { id_465(drec_snd_61) };
        f63f919559f0d70225bd0da5dd9bcafc let_res_467;
        {
          v_595d647e09de2457b04e9f962eaa6fd7 drec_62 { id_466 };
          f63f919559f0d70225bd0da5dd9bcafc letpair_res_468;
          {
            auto drec_fst_63 { std::get<0>(drec_62) };
            auto drec_snd_64 { std::get<1>(drec_62) };
            uint32_t id_469 { 0U };
            Vec<1, uint32_t> id_470 {  id_469  };
            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_471;
            {
              Vec<1, uint32_t> leb_ref_65 { id_470 };
              uint8_t id_472 { 0 };
              Vec<1, uint8_t> id_473 {  id_472  };
              v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_474;
              {
                Vec<1, uint8_t> shft_ref_66 { id_473 };
                Vec<1, Pointer> id_475 {  drec_snd_64  };
                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_476;
                {
                  Vec<1, Pointer> p_ref_67 { id_475 };
                  bool while_flag_477 { true };
                  do {
                    uint8_t id_478 { 0 };
                    Pointer id_479 { p_ref_67[id_478] };
                    v_1d5843897434feb24d158f3793db9189 id_480 { id_479.readU8() };
                    bool let_res_481;
                    {
                      v_1d5843897434feb24d158f3793db9189 leb128_68 { id_480 };
                      bool letpair_res_482;
                      {
                        auto leb128_fst_69 { std::get<0>(leb128_68) };
                        auto leb128_snd_70 { std::get<1>(leb128_68) };
                        uint8_t id_483 { 0 };
                        Void id_484 { ((void)(p_ref_67[id_483] = leb128_snd_70), VOID) };
                        uint8_t id_485 { 0 };
                        uint8_t id_486 { 127 };
                        uint8_t id_487 { uint8_t(leb128_fst_69 & id_486) };
                        uint32_t id_488 { uint32_t(id_487) };
                        uint8_t id_489 { 0 };
                        uint8_t id_490 { shft_ref_66[id_489] };
                        uint32_t id_491 { uint32_t(id_488 << id_490) };
                        uint8_t id_492 { 0 };
                        uint32_t id_493 { leb_ref_65[id_492] };
                        uint32_t id_494 { uint32_t(id_491 | id_493) };
                        Void id_495 { ((void)(leb_ref_65[id_485] = id_494), VOID) };
                        uint8_t id_496 { 0 };
                        uint8_t id_497 { 0 };
                        uint8_t id_498 { shft_ref_66[id_497] };
                        uint8_t id_499 { 7 };
                        uint8_t id_500 { uint8_t(id_498 + id_499) };
                        Void id_501 { ((void)(shft_ref_66[id_496] = id_500), VOID) };
                        uint8_t id_502 { 128 };
                        bool id_503 { bool(leb128_fst_69 >= id_502) };
                        letpair_res_482 = id_503;
                      }
                      let_res_481 = letpair_res_482;
                    }
                    while_flag_477 = let_res_481;
                    if (while_flag_477) {
                    }
                  } while (while_flag_477);
                  uint8_t id_504 { 0 };
                  uint32_t id_505 { leb_ref_65[id_504] };
                  Size id_506 { Size(id_505) };
                  uint8_t id_507 { 0 };
                  Pointer id_508 { p_ref_67[id_507] };
                  v_41b0681ed7f1f185fd3e6c4dcdc13110 id_509 {  id_506, id_508  };
                  let_res_476 = id_509;
                }
                let_res_474 = let_res_476;
              }
              let_res_471 = let_res_474;
            }
            v_46a5e81c2410b000ff0adea6dc198147 let_res_510;
            {
              v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_71 { let_res_471 };
              v_46a5e81c2410b000ff0adea6dc198147 letpair_res_511;
              {
                auto dstring1_fst_72 { std::get<0>(dstring1_71) };
                auto dstring1_snd_73 { std::get<1>(dstring1_71) };
                f921d1e0a170c3c04148c21704db9c45 id_512 { dstring1_snd_73.readBytes(dstring1_fst_72) };
                v_46a5e81c2410b000ff0adea6dc198147 letpair_res_513;
                {
                  auto dstring2_fst_75 { std::get<0>(id_512) };
                  auto dstring2_snd_76 { std::get<1>(id_512) };
                  std::string id_514 { dstring2_fst_75.toString() };
                  v_46a5e81c2410b000ff0adea6dc198147 id_515 {  id_514, dstring2_snd_76  };
                  letpair_res_513 = id_515;
                }
                letpair_res_511 = letpair_res_513;
              }
              let_res_510 = letpair_res_511;
            }
            f63f919559f0d70225bd0da5dd9bcafc let_res_516;
            {
              v_46a5e81c2410b000ff0adea6dc198147 drec_77 { let_res_510 };
              f63f919559f0d70225bd0da5dd9bcafc letpair_res_517;
              {
                auto drec_fst_78 { std::get<0>(drec_77) };
                auto drec_snd_79 { std::get<1>(drec_77) };
                b62e103e7915a76f45f02f7c6f667c79 id_518 { drec_snd_79.readU64Le() };
                v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_519;
                {
                  auto dfloat_fst_81 { std::get<0>(id_518) };
                  auto dfloat_snd_82 { std::get<1>(id_518) };
                  double id_520 { float_of_qword(dfloat_fst_81) };
                  v_41a5a8cf414de9bfdc6375241fcc910a id_521 {  id_520, dfloat_snd_82  };
                  letpair_res_519 = id_521;
                }
                f63f919559f0d70225bd0da5dd9bcafc let_res_522;
                {
                  v_41a5a8cf414de9bfdc6375241fcc910a drec_83 { letpair_res_519 };
                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_523;
                  {
                    auto drec_fst_84 { std::get<0>(drec_83) };
                    auto drec_snd_85 { std::get<1>(drec_83) };
                    b62e103e7915a76f45f02f7c6f667c79 id_524 { drec_snd_85.readU64Le() };
                    v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_525;
                    {
                      auto dfloat_fst_87 { std::get<0>(id_524) };
                      auto dfloat_snd_88 { std::get<1>(id_524) };
                      double id_526 { float_of_qword(dfloat_fst_87) };
                      v_41a5a8cf414de9bfdc6375241fcc910a id_527 {  id_526, dfloat_snd_88  };
                      letpair_res_525 = id_527;
                    }
                    f63f919559f0d70225bd0da5dd9bcafc let_res_528;
                    {
                      v_41a5a8cf414de9bfdc6375241fcc910a drec_89 { letpair_res_525 };
                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_529;
                      {
                        auto drec_fst_90 { std::get<0>(drec_89) };
                        auto drec_snd_91 { std::get<1>(drec_89) };
                        v_362f9d9108a6902af48b6c83d5377ea1 id_530 { drec_snd_91.readU16Le() };
                        v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_531;
                        {
                          auto du16_fst_93 { std::get<0>(id_530) };
                          auto du16_snd_94 { std::get<1>(id_530) };
                          v_362f9d9108a6902af48b6c83d5377ea1 id_532 {  du16_fst_93, du16_snd_94  };
                          letpair_res_531 = id_532;
                        }
                        v_58fbd625a4be51bb7608182ae7c896be let_res_533;
                        {
                          v_362f9d9108a6902af48b6c83d5377ea1 dsum1_98 { letpair_res_531 };
                          v_58fbd625a4be51bb7608182ae7c896be letpair_res_534;
                          {
                            auto dsum1_fst_99 { std::get<0>(dsum1_98) };
                            auto dsum1_snd_100 { std::get<1>(dsum1_98) };
                            uint16_t id_535 { 0 };
                            bool id_536 { bool(id_535 == dsum1_fst_99) };
                            v_58fbd625a4be51bb7608182ae7c896be choose_res_537;
                            if (id_536) {
                              std::function<f0ce35c43c556a289e4bbac0d50849f5(Pointer)> id_538 { dessser_gen::file_path.of_row_binary };
                              f0ce35c43c556a289e4bbac0d50849f5 id_539 { id_538(dsum1_snd_100) };
                              v_58fbd625a4be51bb7608182ae7c896be letpair_res_540;
                              {
                                auto dsum2_fst_117 { std::get<0>(id_539) };
                                auto dsum2_snd_118 { std::get<1>(id_539) };
                                ed5c0948580fc7adda63d975e64ca75f id_541 { std::in_place_index<0>, dsum2_fst_117 };
                                v_58fbd625a4be51bb7608182ae7c896be id_542 {  id_541, dsum2_snd_118  };
                                letpair_res_540 = id_542;
                              }
                              choose_res_537 = letpair_res_540;
                            } else {
                              uint16_t id_543 { 1 };
                              bool id_544 { bool(dsum1_fst_99 == id_543) };
                              Void id_545 { ((void)(assert(id_544)), VOID) };
                              uint32_t id_546 { 0U };
                              Vec<1, uint32_t> id_547 {  id_546  };
                              v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_548;
                              {
                                Vec<1, uint32_t> leb_ref_101 { id_547 };
                                uint8_t id_549 { 0 };
                                Vec<1, uint8_t> id_550 {  id_549  };
                                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_551;
                                {
                                  Vec<1, uint8_t> shft_ref_102 { id_550 };
                                  Vec<1, Pointer> id_552 {  dsum1_snd_100  };
                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_553;
                                  {
                                    Vec<1, Pointer> p_ref_103 { id_552 };
                                    bool while_flag_554 { true };
                                    do {
                                      uint8_t id_555 { 0 };
                                      Pointer id_556 { p_ref_103[id_555] };
                                      v_1d5843897434feb24d158f3793db9189 id_557 { id_556.readU8() };
                                      bool let_res_558;
                                      {
                                        v_1d5843897434feb24d158f3793db9189 leb128_104 { id_557 };
                                        bool letpair_res_559;
                                        {
                                          auto leb128_fst_105 { std::get<0>(leb128_104) };
                                          auto leb128_snd_106 { std::get<1>(leb128_104) };
                                          uint8_t id_560 { 0 };
                                          Void id_561 { ((void)(p_ref_103[id_560] = leb128_snd_106), VOID) };
                                          uint8_t id_562 { 0 };
                                          uint8_t id_563 { 127 };
                                          uint8_t id_564 { uint8_t(leb128_fst_105 & id_563) };
                                          uint32_t id_565 { uint32_t(id_564) };
                                          uint8_t id_566 { 0 };
                                          uint8_t id_567 { shft_ref_102[id_566] };
                                          uint32_t id_568 { uint32_t(id_565 << id_567) };
                                          uint8_t id_569 { 0 };
                                          uint32_t id_570 { leb_ref_101[id_569] };
                                          uint32_t id_571 { uint32_t(id_568 | id_570) };
                                          Void id_572 { ((void)(leb_ref_101[id_562] = id_571), VOID) };
                                          uint8_t id_573 { 0 };
                                          uint8_t id_574 { 0 };
                                          uint8_t id_575 { shft_ref_102[id_574] };
                                          uint8_t id_576 { 7 };
                                          uint8_t id_577 { uint8_t(id_575 + id_576) };
                                          Void id_578 { ((void)(shft_ref_102[id_573] = id_577), VOID) };
                                          uint8_t id_579 { 128 };
                                          bool id_580 { bool(leb128_fst_105 >= id_579) };
                                          letpair_res_559 = id_580;
                                        }
                                        let_res_558 = letpair_res_559;
                                      }
                                      while_flag_554 = let_res_558;
                                      if (while_flag_554) {
                                      }
                                    } while (while_flag_554);
                                    uint8_t id_581 { 0 };
                                    uint32_t id_582 { leb_ref_101[id_581] };
                                    Size id_583 { Size(id_582) };
                                    uint8_t id_584 { 0 };
                                    Pointer id_585 { p_ref_103[id_584] };
                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 id_586 {  id_583, id_585  };
                                    let_res_553 = id_586;
                                  }
                                  let_res_551 = let_res_553;
                                }
                                let_res_548 = let_res_551;
                              }
                              v_58fbd625a4be51bb7608182ae7c896be let_res_587;
                              {
                                v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_107 { let_res_548 };
                                v_58fbd625a4be51bb7608182ae7c896be letpair_res_588;
                                {
                                  auto dstring1_fst_108 { std::get<0>(dstring1_107) };
                                  auto dstring1_snd_109 { std::get<1>(dstring1_107) };
                                  f921d1e0a170c3c04148c21704db9c45 id_589 { dstring1_snd_109.readBytes(dstring1_fst_108) };
                                  v_58fbd625a4be51bb7608182ae7c896be letpair_res_590;
                                  {
                                    auto dstring2_fst_111 { std::get<0>(id_589) };
                                    auto dstring2_snd_112 { std::get<1>(id_589) };
                                    std::string id_591 { dstring2_fst_111.toString() };
                                    ed5c0948580fc7adda63d975e64ca75f id_592 { std::in_place_index<1>, id_591 };
                                    v_58fbd625a4be51bb7608182ae7c896be id_593 {  id_592, dstring2_snd_112  };
                                    letpair_res_590 = id_593;
                                  }
                                  letpair_res_588 = letpair_res_590;
                                }
                                let_res_587 = letpair_res_588;
                              }
                              choose_res_537 = let_res_587;
                            }
                            letpair_res_534 = choose_res_537;
                          }
                          let_res_533 = letpair_res_534;
                        }
                        f63f919559f0d70225bd0da5dd9bcafc let_res_594;
                        {
                          v_58fbd625a4be51bb7608182ae7c896be drec_119 { let_res_533 };
                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_595;
                          {
                            auto drec_fst_120 { std::get<0>(drec_119) };
                            auto drec_snd_121 { std::get<1>(drec_119) };
                            uint32_t id_596 { 0U };
                            Vec<1, uint32_t> id_597 {  id_596  };
                            ac0fbd05039f742d2f1d9ac182e392ab let_res_598;
                            {
                              Vec<1, uint32_t> leb_ref_122 { id_597 };
                              uint8_t id_599 { 0 };
                              Vec<1, uint8_t> id_600 {  id_599  };
                              ac0fbd05039f742d2f1d9ac182e392ab let_res_601;
                              {
                                Vec<1, uint8_t> shft_ref_123 { id_600 };
                                Vec<1, Pointer> id_602 {  drec_snd_121  };
                                ac0fbd05039f742d2f1d9ac182e392ab let_res_603;
                                {
                                  Vec<1, Pointer> p_ref_124 { id_602 };
                                  bool while_flag_604 { true };
                                  do {
                                    uint8_t id_605 { 0 };
                                    Pointer id_606 { p_ref_124[id_605] };
                                    v_1d5843897434feb24d158f3793db9189 id_607 { id_606.readU8() };
                                    bool let_res_608;
                                    {
                                      v_1d5843897434feb24d158f3793db9189 leb128_125 { id_607 };
                                      bool letpair_res_609;
                                      {
                                        auto leb128_fst_126 { std::get<0>(leb128_125) };
                                        auto leb128_snd_127 { std::get<1>(leb128_125) };
                                        uint8_t id_610 { 0 };
                                        Void id_611 { ((void)(p_ref_124[id_610] = leb128_snd_127), VOID) };
                                        uint8_t id_612 { 0 };
                                        uint8_t id_613 { 127 };
                                        uint8_t id_614 { uint8_t(leb128_fst_126 & id_613) };
                                        uint32_t id_615 { uint32_t(id_614) };
                                        uint8_t id_616 { 0 };
                                        uint8_t id_617 { shft_ref_123[id_616] };
                                        uint32_t id_618 { uint32_t(id_615 << id_617) };
                                        uint8_t id_619 { 0 };
                                        uint32_t id_620 { leb_ref_122[id_619] };
                                        uint32_t id_621 { uint32_t(id_618 | id_620) };
                                        Void id_622 { ((void)(leb_ref_122[id_612] = id_621), VOID) };
                                        uint8_t id_623 { 0 };
                                        uint8_t id_624 { 0 };
                                        uint8_t id_625 { shft_ref_123[id_624] };
                                        uint8_t id_626 { 7 };
                                        uint8_t id_627 { uint8_t(id_625 + id_626) };
                                        Void id_628 { ((void)(shft_ref_123[id_623] = id_627), VOID) };
                                        uint8_t id_629 { 128 };
                                        bool id_630 { bool(leb128_fst_126 >= id_629) };
                                        letpair_res_609 = id_630;
                                      }
                                      let_res_608 = letpair_res_609;
                                    }
                                    while_flag_604 = let_res_608;
                                    if (while_flag_604) {
                                    }
                                  } while (while_flag_604);
                                  uint8_t id_631 { 0 };
                                  uint32_t id_632 { leb_ref_122[id_631] };
                                  uint8_t id_633 { 0 };
                                  Pointer id_634 { p_ref_124[id_633] };
                                  ac0fbd05039f742d2f1d9ac182e392ab id_635 {  id_632, id_634  };
                                  let_res_603 = id_635;
                                }
                                let_res_601 = let_res_603;
                              }
                              let_res_598 = let_res_601;
                            }
                            e5c39a971595e219b777c7cddbdac2d5 let_res_636;
                            {
                              ac0fbd05039f742d2f1d9ac182e392ab dlist1_131 { let_res_598 };
                              e5c39a971595e219b777c7cddbdac2d5 letpair_res_637;
                              {
                                auto dlist1_fst_132 { std::get<0>(dlist1_131) };
                                auto dlist1_snd_133 { std::get<1>(dlist1_131) };
                                Lst<*fq_function_name> endoflist_638;
                                e5c39a971595e219b777c7cddbdac2d5 id_639 {  endoflist_638, dlist1_snd_133  };
                                Vec<1, e5c39a971595e219b777c7cddbdac2d5> id_640 {  id_639  };
                                e5c39a971595e219b777c7cddbdac2d5 let_res_641;
                                {
                                  Vec<1, e5c39a971595e219b777c7cddbdac2d5> inits_src_ref_134 { id_640 };
                                  int32_t id_642 { 0L };
                                  Vec<1, int32_t> id_643 {  id_642  };
                                  {
                                    Vec<1, int32_t> repeat_n_135 { id_643 };
                                    bool while_flag_644 { true };
                                    do {
                                      int32_t id_645 { int32_t(dlist1_fst_132) };
                                      uint8_t id_646 { 0 };
                                      int32_t id_647 { repeat_n_135[id_646] };
                                      bool id_648 { bool(id_645 > id_647) };
                                      while_flag_644 = id_648;
                                      if (while_flag_644) {
                                        uint8_t id_649 { 0 };
                                        e5c39a971595e219b777c7cddbdac2d5 id_650 { inits_src_ref_134[id_649] };
                                        {
                                          e5c39a971595e219b777c7cddbdac2d5 dlist2_136 { id_650 };
                                          {
                                            auto dlist2_fst_137 { std::get<0>(dlist2_136) };
                                            auto dlist2_snd_138 { std::get<1>(dlist2_136) };
                                            uint8_t id_651 { 0 };
                                            std::function<v_595d647e09de2457b04e9f962eaa6fd7(Pointer)> id_652 { dessser_gen::fq_function_name.of_row_binary };
                                            v_595d647e09de2457b04e9f962eaa6fd7 id_653 { id_652(dlist2_snd_138) };
                                            e5c39a971595e219b777c7cddbdac2d5 letpair_res_654;
                                            {
                                              auto dlist3_fst_140 { std::get<0>(id_653) };
                                              auto dlist3_snd_141 { std::get<1>(id_653) };
                                              Lst<*fq_function_name> id_655 { dlist3_fst_140, dlist2_fst_137 };
                                              e5c39a971595e219b777c7cddbdac2d5 id_656 {  id_655, dlist3_snd_141  };
                                              letpair_res_654 = id_656;
                                            }
                                            Void id_657 { ((void)(inits_src_ref_134[id_651] = letpair_res_654), VOID) };
                                          }
                                        }
                                        uint8_t id_658 { 0 };
                                        uint8_t id_659 { 0 };
                                        int32_t id_660 { repeat_n_135[id_659] };
                                        int32_t id_661 { 1L };
                                        int32_t id_662 { int32_t(id_660 + id_661) };
                                        Void id_663 { ((void)(repeat_n_135[id_658] = id_662), VOID) };
                                      }
                                    } while (while_flag_644);
                                  }
                                  uint8_t id_664 { 0 };
                                  e5c39a971595e219b777c7cddbdac2d5 id_665 { inits_src_ref_134[id_664] };
                                  let_res_641 = id_665;
                                }
                                letpair_res_637 = let_res_641;
                              }
                              let_res_636 = letpair_res_637;
                            }
                            eb64375e5e0c7fea2870ffafcb470176 letpair_res_666;
                            {
                              auto dlist4_fst_143 { std::get<0>(let_res_636) };
                              auto dlist4_snd_144 { std::get<1>(let_res_636) };
                              Arr<*fq_function_name> id_667 { dlist4_fst_143.toListRev() };
                              eb64375e5e0c7fea2870ffafcb470176 id_668 {  id_667, dlist4_snd_144  };
                              letpair_res_666 = id_668;
                            }
                            f63f919559f0d70225bd0da5dd9bcafc let_res_669;
                            {
                              eb64375e5e0c7fea2870ffafcb470176 drec_145 { letpair_res_666 };
                              f63f919559f0d70225bd0da5dd9bcafc letpair_res_670;
                              {
                                auto drec_fst_146 { std::get<0>(drec_145) };
                                auto drec_snd_147 { std::get<1>(drec_145) };
                                uint32_t id_671 { 0U };
                                Vec<1, uint32_t> id_672 {  id_671  };
                                ac0fbd05039f742d2f1d9ac182e392ab let_res_673;
                                {
                                  Vec<1, uint32_t> leb_ref_148 { id_672 };
                                  uint8_t id_674 { 0 };
                                  Vec<1, uint8_t> id_675 {  id_674  };
                                  ac0fbd05039f742d2f1d9ac182e392ab let_res_676;
                                  {
                                    Vec<1, uint8_t> shft_ref_149 { id_675 };
                                    Vec<1, Pointer> id_677 {  drec_snd_147  };
                                    ac0fbd05039f742d2f1d9ac182e392ab let_res_678;
                                    {
                                      Vec<1, Pointer> p_ref_150 { id_677 };
                                      bool while_flag_679 { true };
                                      do {
                                        uint8_t id_680 { 0 };
                                        Pointer id_681 { p_ref_150[id_680] };
                                        v_1d5843897434feb24d158f3793db9189 id_682 { id_681.readU8() };
                                        bool let_res_683;
                                        {
                                          v_1d5843897434feb24d158f3793db9189 leb128_151 { id_682 };
                                          bool letpair_res_684;
                                          {
                                            auto leb128_fst_152 { std::get<0>(leb128_151) };
                                            auto leb128_snd_153 { std::get<1>(leb128_151) };
                                            uint8_t id_685 { 0 };
                                            Void id_686 { ((void)(p_ref_150[id_685] = leb128_snd_153), VOID) };
                                            uint8_t id_687 { 0 };
                                            uint8_t id_688 { 127 };
                                            uint8_t id_689 { uint8_t(leb128_fst_152 & id_688) };
                                            uint32_t id_690 { uint32_t(id_689) };
                                            uint8_t id_691 { 0 };
                                            uint8_t id_692 { shft_ref_149[id_691] };
                                            uint32_t id_693 { uint32_t(id_690 << id_692) };
                                            uint8_t id_694 { 0 };
                                            uint32_t id_695 { leb_ref_148[id_694] };
                                            uint32_t id_696 { uint32_t(id_693 | id_695) };
                                            Void id_697 { ((void)(leb_ref_148[id_687] = id_696), VOID) };
                                            uint8_t id_698 { 0 };
                                            uint8_t id_699 { 0 };
                                            uint8_t id_700 { shft_ref_149[id_699] };
                                            uint8_t id_701 { 7 };
                                            uint8_t id_702 { uint8_t(id_700 + id_701) };
                                            Void id_703 { ((void)(shft_ref_149[id_698] = id_702), VOID) };
                                            uint8_t id_704 { 128 };
                                            bool id_705 { bool(leb128_fst_152 >= id_704) };
                                            letpair_res_684 = id_705;
                                          }
                                          let_res_683 = letpair_res_684;
                                        }
                                        while_flag_679 = let_res_683;
                                        if (while_flag_679) {
                                        }
                                      } while (while_flag_679);
                                      uint8_t id_706 { 0 };
                                      uint32_t id_707 { leb_ref_148[id_706] };
                                      uint8_t id_708 { 0 };
                                      Pointer id_709 { p_ref_150[id_708] };
                                      ac0fbd05039f742d2f1d9ac182e392ab id_710 {  id_707, id_709  };
                                      let_res_678 = id_710;
                                    }
                                    let_res_676 = let_res_678;
                                  }
                                  let_res_673 = let_res_676;
                                }
                                v_2dc6eb72e24ae843c30144dafeaae4e5 let_res_711;
                                {
                                  ac0fbd05039f742d2f1d9ac182e392ab dlist1_157 { let_res_673 };
                                  v_2dc6eb72e24ae843c30144dafeaae4e5 letpair_res_712;
                                  {
                                    auto dlist1_fst_158 { std::get<0>(dlist1_157) };
                                    auto dlist1_snd_159 { std::get<1>(dlist1_157) };
                                    Lst<v_350131e9cf91ccd34558b5986f609d67> endoflist_713;
                                    v_2dc6eb72e24ae843c30144dafeaae4e5 id_714 {  endoflist_713, dlist1_snd_159  };
                                    Vec<1, v_2dc6eb72e24ae843c30144dafeaae4e5> id_715 {  id_714  };
                                    v_2dc6eb72e24ae843c30144dafeaae4e5 let_res_716;
                                    {
                                      Vec<1, v_2dc6eb72e24ae843c30144dafeaae4e5> inits_src_ref_160 { id_715 };
                                      int32_t id_717 { 0L };
                                      Vec<1, int32_t> id_718 {  id_717  };
                                      {
                                        Vec<1, int32_t> repeat_n_161 { id_718 };
                                        bool while_flag_719 { true };
                                        do {
                                          int32_t id_720 { int32_t(dlist1_fst_158) };
                                          uint8_t id_721 { 0 };
                                          int32_t id_722 { repeat_n_161[id_721] };
                                          bool id_723 { bool(id_720 > id_722) };
                                          while_flag_719 = id_723;
                                          if (while_flag_719) {
                                            uint8_t id_724 { 0 };
                                            v_2dc6eb72e24ae843c30144dafeaae4e5 id_725 { inits_src_ref_160[id_724] };
                                            {
                                              v_2dc6eb72e24ae843c30144dafeaae4e5 dlist2_162 { id_725 };
                                              {
                                                auto dlist2_fst_163 { std::get<0>(dlist2_162) };
                                                auto dlist2_snd_164 { std::get<1>(dlist2_162) };
                                                uint8_t id_726 { 0 };
                                                std::function<v_595d647e09de2457b04e9f962eaa6fd7(Pointer)> id_727 { dessser_gen::fq_function_name.of_row_binary };
                                                v_595d647e09de2457b04e9f962eaa6fd7 id_728 { id_727(dlist2_snd_164) };
                                                v_2dc6eb72e24ae843c30144dafeaae4e5 let_res_729;
                                                {
                                                  v_595d647e09de2457b04e9f962eaa6fd7 dtup_165 { id_728 };
                                                  v_2dc6eb72e24ae843c30144dafeaae4e5 letpair_res_730;
                                                  {
                                                    auto dtup_fst_166 { std::get<0>(dtup_165) };
                                                    auto dtup_snd_167 { std::get<1>(dtup_165) };
                                                    std::function<v_595d647e09de2457b04e9f962eaa6fd7(Pointer)> id_731 { dessser_gen::fq_function_name.of_row_binary };
                                                    v_595d647e09de2457b04e9f962eaa6fd7 id_732 { id_731(dtup_snd_167) };
                                                    v_2dc6eb72e24ae843c30144dafeaae4e5 letpair_res_733;
                                                    {
                                                      auto dtup_fst_169 { std::get<0>(id_732) };
                                                      auto dtup_snd_170 { std::get<1>(id_732) };
                                                      v_350131e9cf91ccd34558b5986f609d67 id_734 {  dtup_fst_166, dtup_fst_169  };
                                                      Lst<v_350131e9cf91ccd34558b5986f609d67> id_735 { id_734, dlist2_fst_163 };
                                                      v_2dc6eb72e24ae843c30144dafeaae4e5 id_736 {  id_735, dtup_snd_170  };
                                                      letpair_res_733 = id_736;
                                                    }
                                                    letpair_res_730 = letpair_res_733;
                                                  }
                                                  let_res_729 = letpair_res_730;
                                                }
                                                Void id_737 { ((void)(inits_src_ref_160[id_726] = let_res_729), VOID) };
                                              }
                                            }
                                            uint8_t id_738 { 0 };
                                            uint8_t id_739 { 0 };
                                            int32_t id_740 { repeat_n_161[id_739] };
                                            int32_t id_741 { 1L };
                                            int32_t id_742 { int32_t(id_740 + id_741) };
                                            Void id_743 { ((void)(repeat_n_161[id_738] = id_742), VOID) };
                                          }
                                        } while (while_flag_719);
                                      }
                                      uint8_t id_744 { 0 };
                                      v_2dc6eb72e24ae843c30144dafeaae4e5 id_745 { inits_src_ref_160[id_744] };
                                      let_res_716 = id_745;
                                    }
                                    letpair_res_712 = let_res_716;
                                  }
                                  let_res_711 = letpair_res_712;
                                }
                                v_09420c3639fb0fa3828f3fd631ab7a1f letpair_res_746;
                                {
                                  auto dlist4_fst_175 { std::get<0>(let_res_711) };
                                  auto dlist4_snd_176 { std::get<1>(let_res_711) };
                                  Arr<v_350131e9cf91ccd34558b5986f609d67> id_747 { dlist4_fst_175.toListRev() };
                                  v_09420c3639fb0fa3828f3fd631ab7a1f id_748 {  id_747, dlist4_snd_176  };
                                  letpair_res_746 = id_748;
                                }
                                f63f919559f0d70225bd0da5dd9bcafc let_res_749;
                                {
                                  v_09420c3639fb0fa3828f3fd631ab7a1f drec_177 { letpair_res_746 };
                                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_750;
                                  {
                                    auto drec_fst_178 { std::get<0>(drec_177) };
                                    auto drec_snd_179 { std::get<1>(drec_177) };
                                    b62e103e7915a76f45f02f7c6f667c79 id_751 { drec_snd_179.readU64Le() };
                                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_752;
                                    {
                                      auto dfloat_fst_181 { std::get<0>(id_751) };
                                      auto dfloat_snd_182 { std::get<1>(id_751) };
                                      double id_753 { float_of_qword(dfloat_fst_181) };
                                      t id_754 {  .channel = drec_fst_60, .target = drec_fst_63, .target_fieldmask = drec_fst_78, .since = drec_fst_84, .until = drec_fst_90, .recipient = drec_fst_120, .sources = drec_fst_146, .links = drec_fst_178, .timeout_date = id_753  };
                                      f63f919559f0d70225bd0da5dd9bcafc id_755 {  id_754, dfloat_snd_182  };
                                      letpair_res_752 = id_755;
                                    }
                                    letpair_res_750 = letpair_res_752;
                                  }
                                  let_res_749 = letpair_res_750;
                                }
                                letpair_res_670 = let_res_749;
                              }
                              let_res_669 = letpair_res_670;
                            }
                            letpair_res_595 = let_res_669;
                          }
                          let_res_594 = letpair_res_595;
                        }
                        letpair_res_529 = let_res_594;
                      }
                      let_res_528 = letpair_res_529;
                    }
                    letpair_res_523 = let_res_528;
                  }
                  let_res_522 = letpair_res_523;
                }
                letpair_res_517 = let_res_522;
              }
              let_res_516 = letpair_res_517;
            }
            letpair_res_468 = let_res_516;
          }
          let_res_467 = letpair_res_468;
        }
        letpair_res_464 = let_res_467;
      }
      let_res_463 = letpair_res_464;
    }
    return let_res_463;
  }
   };
  return fun459;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
