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

namespace dessser::gen::target_config {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct v_13778ae74488ba3447259adc9816e04e {
  bool enabled;
  bool debug;
  double report_period;
  dessser::gen::file_path::t cwd;
  Arr<dessser::gen::program_run_parameter::t> params;
  std::string on_site;
  bool automatic;
  bool operator==(v_13778ae74488ba3447259adc9816e04e const &other) const {
    return enabled == other.enabled && debug == other.debug && report_period == other.report_period && cwd == other.cwd && params == other.params && on_site == other.on_site && automatic == other.automatic;
  }
};
std::ostream &operator<<(std::ostream &os, v_13778ae74488ba3447259adc9816e04e const &r) {
  os << '{';
  os << "enabled:" << r.enabled << ',';
  os << "debug:" << r.debug << ',';
  os << "report_period:" << r.report_period << ',';
  os << "cwd:" << r.cwd << ',';
  os << "params:" << r.params << ',';
  os << "on_site:" << r.on_site << ',';
  os << "automatic:" << r.automatic;
  os << '}';
  return os;
}

typedef std::tuple<
  dessser::gen::program_name::t,
  v_13778ae74488ba3447259adc9816e04e
> cc18b22dfb71145a271a6ff24f6a72b1;

typedef Arr<cc18b22dfb71145a271a6ff24f6a72b1> t;
typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  uint32_t,
  Pointer
> ac0fbd05039f742d2f1d9ac182e392ab;

typedef std::tuple<
  uint8_t,
  Pointer
> v_1d5843897434feb24d158f3793db9189;

typedef std::tuple<
  Lst<cc18b22dfb71145a271a6ff24f6a72b1>,
  Pointer
> v_478c17794159145a25a7b9622851ad8e;

typedef std::tuple<
  dessser::gen::program_name::t,
  Pointer
> f6e2f55e3ebc4a068d1f568f5860423e;

typedef std::tuple<
  bool,
  Pointer
> f2a48a42f9c827f487e53ee52a4e9e2f;

typedef std::tuple<
  uint64_t,
  Pointer
> b62e103e7915a76f45f02f7c6f667c79;

typedef std::tuple<
  double,
  Pointer
> v_41a5a8cf414de9bfdc6375241fcc910a;

typedef std::tuple<
  dessser::gen::file_path::t,
  Pointer
> f0ce35c43c556a289e4bbac0d50849f5;

typedef std::tuple<
  Lst<dessser::gen::program_run_parameter::t>,
  Pointer
> v_6ff2026c09f75e223ce21e637140a238;

typedef std::tuple<
  dessser::gen::program_run_parameter::t,
  Pointer
> v_97e7003b69c0f14d17f9608e0f17d035;

typedef std::tuple<
  Arr<dessser::gen::program_run_parameter::t>,
  Pointer
> v_173c41cb615a30ffc96dea16ddfd38ef;

typedef std::tuple<
  Size,
  Pointer
> v_41b0681ed7f1f185fd3e6c4dcdc13110;

typedef std::tuple<
  std::string,
  Pointer
> v_46a5e81c2410b000ff0adea6dc198147;

typedef std::tuple<
  Bytes,
  Pointer
> f921d1e0a170c3c04148c21704db9c45;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("($program_name; {enabled: BOOL; debug: BOOL; report_period: FLOAT; cwd: $file_path; params: $program_run_parameter[]; on_site: STRING; automatic: BOOL})[]" "Ptr")
      (let "dst_ref_178"
        (make-vec
          (let "leb128_sz_176" (make-vec (cardinality (param 0)))
            (let "leb128_ptr_177" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_177")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_177"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_176"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_176"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_176"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_176") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_176")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_176")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_177"))))))
        (let "n_ref_179" (make-vec (i32 0))
          (seq
            (for-each "x_180" (param 0)
              (seq
                (set-vec (u8 0) (identifier "dst_ref_178")
                  (let "stup_dst_182" (let "stup_dst_181" (unsafe-nth (u8 0) (identifier "dst_ref_178")) (apply (ext-identifier program_name to-row-binary) (get-item 0 (identifier "x_180")) (identifier "stup_dst_181")))
                    (let "srec_dst_195"
                      (let "srec_dst_192"
                        (let "srec_dst_186"
                          (let "srec_dst_185"
                            (let "srec_dst_184"
                              (let "srec_dst_183" (write-u8 (identifier "stup_dst_182") (u8-of-bool (get-field "enabled" (get-item 1 (identifier "x_180")))))
                                (write-u8 (identifier "srec_dst_183") (u8-of-bool (get-field "debug" (get-item 1 (identifier "x_180"))))))
                              (write-u64 little-endian (identifier "srec_dst_184") (u64-of-float (get-field "report_period" (get-item 1 (identifier "x_180"))))))
                            (apply (ext-identifier file_path to-row-binary) (get-field "cwd" (get-item 1 (identifier "x_180"))) (identifier "srec_dst_185")))
                          (let "dst_ref_189"
                            (make-vec
                              (let "leb128_sz_187" (make-vec (cardinality (get-field "params" (get-item 1 (identifier "x_180")))))
                                (let "leb128_ptr_188" (make-vec (identifier "srec_dst_186"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_188")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_188"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_187"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_187"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_187"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_187") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_187")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_187")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_188"))))))
                            (let "n_ref_190" (make-vec (i32 0))
                              (seq
                                (for-each "x_191" (get-field "params" (get-item 1 (identifier "x_180")))
                                  (seq (set-vec (u8 0) (identifier "dst_ref_189") (apply (ext-identifier program_run_parameter to-row-binary) (identifier "x_191") (unsafe-nth (u8 0) (identifier "dst_ref_189"))))
                                    (set-vec (u8 0) (identifier "n_ref_190") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_190")))))) 
                                (unsafe-nth (u8 0) (identifier "dst_ref_189"))))))
                        (write-bytes
                          (let "leb128_sz_193" (make-vec (string-length (get-field "on_site" (get-item 1 (identifier "x_180")))))
                            (let "leb128_ptr_194" (make-vec (identifier "srec_dst_192"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_194")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_194"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_193"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_193"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_193"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_193") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_193")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_193")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_194"))))) 
                          (bytes-of-string (get-field "on_site" (get-item 1 (identifier "x_180")))))) 
                      (write-u8 (identifier "srec_dst_195") (u8-of-bool (get-field "automatic" (get-item 1 (identifier "x_180"))))))))
                (set-vec (u8 0) (identifier "n_ref_179") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_179")))))) 
            (unsafe-nth (u8 0) (identifier "dst_ref_178"))))))
 */
static std::function<Pointer(t&,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t&,Pointer)> fun0 { [&fun0](t& p_0, Pointer p_1) {
    uint32_t id_1 { p_0.size() };
    Vec<1, uint32_t> id_2 {  id_1  };
    Pointer let_res_3;
    {
      Vec<1, uint32_t> leb128_sz_176 { id_2 };
      Vec<1, Pointer> id_4 {  p_1  };
      Pointer let_res_5;
      {
        Vec<1, Pointer> leb128_ptr_177 { id_4 };
        bool while_flag_6 { true };
        do {
          uint8_t id_7 { 0 };
          uint8_t id_8 { 0 };
          Pointer id_9 { leb128_ptr_177[id_8] };
          uint32_t id_10 { 128U };
          uint8_t id_11 { 0 };
          uint32_t id_12 { leb128_sz_176[id_11] };
          bool id_13 { bool(id_10 > id_12) };
          uint8_t choose_res_14;
          if (id_13) {
            uint8_t id_15 { 0 };
            uint32_t id_16 { leb128_sz_176[id_15] };
            uint8_t id_17 { uint8_t(id_16) };
            choose_res_14 = id_17;
          } else {
            uint8_t id_18 { 0 };
            uint32_t id_19 { leb128_sz_176[id_18] };
            uint8_t id_20 { uint8_t(id_19) };
            uint8_t id_21 { 128 };
            uint8_t id_22 { uint8_t(id_20 | id_21) };
            choose_res_14 = id_22;
          }
          Pointer id_23 { id_9.writeU8(choose_res_14) };
          Void id_24 { ((void)(leb128_ptr_177[id_7] = id_23), VOID) };
          uint8_t id_25 { 0 };
          uint8_t id_26 { 0 };
          uint32_t id_27 { leb128_sz_176[id_26] };
          uint8_t id_28 { 7 };
          uint32_t id_29 { uint32_t(id_27 >> id_28) };
          Void id_30 { ((void)(leb128_sz_176[id_25] = id_29), VOID) };
          uint8_t id_31 { 0 };
          uint32_t id_32 { leb128_sz_176[id_31] };
          uint32_t id_33 { 0U };
          bool id_34 { bool(id_32 > id_33) };
          while_flag_6 = id_34;
          if (while_flag_6) {
          }
        } while (while_flag_6);
        uint8_t id_35 { 0 };
        Pointer id_36 { leb128_ptr_177[id_35] };
        let_res_5 = id_36;
      }
      let_res_3 = let_res_5;
    }
    Vec<1, Pointer> id_37 {  let_res_3  };
    Pointer let_res_38;
    {
      Vec<1, Pointer> dst_ref_178 { id_37 };
      int32_t id_39 { 0L };
      Vec<1, int32_t> id_40 {  id_39  };
      Pointer let_res_41;
      {
        Vec<1, int32_t> n_ref_179 { id_40 };
        for (cc18b22dfb71145a271a6ff24f6a72b1 x_180 : p_0) {
          uint8_t id_42 { 0 };
          uint8_t id_43 { 0 };
          Pointer id_44 { dst_ref_178[id_43] };
          Pointer let_res_45;
          {
            Pointer stup_dst_181 { id_44 };
            std::function<Pointer(dessser::gen::program_name::t,Pointer)> id_46 { dessser::gen::program_name::to_row_binary };
            dessser::gen::program_name::t id_47 { std::get<0>(x_180) };
            Pointer id_48 { id_46(id_47, stup_dst_181) };
            let_res_45 = id_48;
          }
          Pointer let_res_49;
          {
            Pointer stup_dst_182 { let_res_45 };
            v_13778ae74488ba3447259adc9816e04e id_50 { std::get<1>(x_180) };
            bool id_51 { id_50.enabled };
            uint8_t id_52 { uint8_t(id_51) };
            Pointer id_53 { stup_dst_182.writeU8(id_52) };
            Pointer let_res_54;
            {
              Pointer srec_dst_183 { id_53 };
              v_13778ae74488ba3447259adc9816e04e id_55 { std::get<1>(x_180) };
              bool id_56 { id_55.debug };
              uint8_t id_57 { uint8_t(id_56) };
              Pointer id_58 { srec_dst_183.writeU8(id_57) };
              let_res_54 = id_58;
            }
            Pointer let_res_59;
            {
              Pointer srec_dst_184 { let_res_54 };
              v_13778ae74488ba3447259adc9816e04e id_60 { std::get<1>(x_180) };
              double id_61 { id_60.report_period };
              uint64_t id_62 { qword_of_float(id_61) };
              Pointer id_63 { srec_dst_184.writeU64Le(id_62) };
              let_res_59 = id_63;
            }
            Pointer let_res_64;
            {
              Pointer srec_dst_185 { let_res_59 };
              std::function<Pointer(dessser::gen::file_path::t,Pointer)> id_65 { dessser::gen::file_path::to_row_binary };
              v_13778ae74488ba3447259adc9816e04e id_66 { std::get<1>(x_180) };
              dessser::gen::file_path::t id_67 { id_66.cwd };
              Pointer id_68 { id_65(id_67, srec_dst_185) };
              let_res_64 = id_68;
            }
            Pointer let_res_69;
            {
              Pointer srec_dst_186 { let_res_64 };
              v_13778ae74488ba3447259adc9816e04e id_70 { std::get<1>(x_180) };
              Arr<dessser::gen::program_run_parameter::t> id_71 { id_70.params };
              uint32_t id_72 { id_71.size() };
              Vec<1, uint32_t> id_73 {  id_72  };
              Pointer let_res_74;
              {
                Vec<1, uint32_t> leb128_sz_187 { id_73 };
                Vec<1, Pointer> id_75 {  srec_dst_186  };
                Pointer let_res_76;
                {
                  Vec<1, Pointer> leb128_ptr_188 { id_75 };
                  bool while_flag_77 { true };
                  do {
                    uint8_t id_78 { 0 };
                    uint8_t id_79 { 0 };
                    Pointer id_80 { leb128_ptr_188[id_79] };
                    uint32_t id_81 { 128U };
                    uint8_t id_82 { 0 };
                    uint32_t id_83 { leb128_sz_187[id_82] };
                    bool id_84 { bool(id_81 > id_83) };
                    uint8_t choose_res_85;
                    if (id_84) {
                      uint8_t id_86 { 0 };
                      uint32_t id_87 { leb128_sz_187[id_86] };
                      uint8_t id_88 { uint8_t(id_87) };
                      choose_res_85 = id_88;
                    } else {
                      uint8_t id_89 { 0 };
                      uint32_t id_90 { leb128_sz_187[id_89] };
                      uint8_t id_91 { uint8_t(id_90) };
                      uint8_t id_92 { 128 };
                      uint8_t id_93 { uint8_t(id_91 | id_92) };
                      choose_res_85 = id_93;
                    }
                    Pointer id_94 { id_80.writeU8(choose_res_85) };
                    Void id_95 { ((void)(leb128_ptr_188[id_78] = id_94), VOID) };
                    uint8_t id_96 { 0 };
                    uint8_t id_97 { 0 };
                    uint32_t id_98 { leb128_sz_187[id_97] };
                    uint8_t id_99 { 7 };
                    uint32_t id_100 { uint32_t(id_98 >> id_99) };
                    Void id_101 { ((void)(leb128_sz_187[id_96] = id_100), VOID) };
                    uint8_t id_102 { 0 };
                    uint32_t id_103 { leb128_sz_187[id_102] };
                    uint32_t id_104 { 0U };
                    bool id_105 { bool(id_103 > id_104) };
                    while_flag_77 = id_105;
                    if (while_flag_77) {
                    }
                  } while (while_flag_77);
                  uint8_t id_106 { 0 };
                  Pointer id_107 { leb128_ptr_188[id_106] };
                  let_res_76 = id_107;
                }
                let_res_74 = let_res_76;
              }
              Vec<1, Pointer> id_108 {  let_res_74  };
              Pointer let_res_109;
              {
                Vec<1, Pointer> dst_ref_189 { id_108 };
                int32_t id_110 { 0L };
                Vec<1, int32_t> id_111 {  id_110  };
                Pointer let_res_112;
                {
                  Vec<1, int32_t> n_ref_190 { id_111 };
                  v_13778ae74488ba3447259adc9816e04e id_113 { std::get<1>(x_180) };
                  Arr<dessser::gen::program_run_parameter::t> id_114 { id_113.params };
                  for (dessser::gen::program_run_parameter::t x_191 : id_114) {
                    uint8_t id_115 { 0 };
                    std::function<Pointer(dessser::gen::program_run_parameter::t,Pointer)> id_116 { dessser::gen::program_run_parameter::to_row_binary };
                    uint8_t id_117 { 0 };
                    Pointer id_118 { dst_ref_189[id_117] };
                    Pointer id_119 { id_116(x_191, id_118) };
                    Void id_120 { ((void)(dst_ref_189[id_115] = id_119), VOID) };
                    uint8_t id_121 { 0 };
                    int32_t id_122 { 1L };
                    uint8_t id_123 { 0 };
                    int32_t id_124 { n_ref_190[id_123] };
                    int32_t id_125 { int32_t(id_122 + id_124) };
                    Void id_126 { ((void)(n_ref_190[id_121] = id_125), VOID) };
                  }
                  uint8_t id_127 { 0 };
                  Pointer id_128 { dst_ref_189[id_127] };
                  let_res_112 = id_128;
                }
                let_res_109 = let_res_112;
              }
              let_res_69 = let_res_109;
            }
            Pointer let_res_129;
            {
              Pointer srec_dst_192 { let_res_69 };
              v_13778ae74488ba3447259adc9816e04e id_130 { std::get<1>(x_180) };
              std::string id_131 { id_130.on_site };
              uint32_t id_132 { (uint32_t)id_131.size() };
              Vec<1, uint32_t> id_133 {  id_132  };
              Pointer let_res_134;
              {
                Vec<1, uint32_t> leb128_sz_193 { id_133 };
                Vec<1, Pointer> id_135 {  srec_dst_192  };
                Pointer let_res_136;
                {
                  Vec<1, Pointer> leb128_ptr_194 { id_135 };
                  bool while_flag_137 { true };
                  do {
                    uint8_t id_138 { 0 };
                    uint8_t id_139 { 0 };
                    Pointer id_140 { leb128_ptr_194[id_139] };
                    uint32_t id_141 { 128U };
                    uint8_t id_142 { 0 };
                    uint32_t id_143 { leb128_sz_193[id_142] };
                    bool id_144 { bool(id_141 > id_143) };
                    uint8_t choose_res_145;
                    if (id_144) {
                      uint8_t id_146 { 0 };
                      uint32_t id_147 { leb128_sz_193[id_146] };
                      uint8_t id_148 { uint8_t(id_147) };
                      choose_res_145 = id_148;
                    } else {
                      uint8_t id_149 { 0 };
                      uint32_t id_150 { leb128_sz_193[id_149] };
                      uint8_t id_151 { uint8_t(id_150) };
                      uint8_t id_152 { 128 };
                      uint8_t id_153 { uint8_t(id_151 | id_152) };
                      choose_res_145 = id_153;
                    }
                    Pointer id_154 { id_140.writeU8(choose_res_145) };
                    Void id_155 { ((void)(leb128_ptr_194[id_138] = id_154), VOID) };
                    uint8_t id_156 { 0 };
                    uint8_t id_157 { 0 };
                    uint32_t id_158 { leb128_sz_193[id_157] };
                    uint8_t id_159 { 7 };
                    uint32_t id_160 { uint32_t(id_158 >> id_159) };
                    Void id_161 { ((void)(leb128_sz_193[id_156] = id_160), VOID) };
                    uint8_t id_162 { 0 };
                    uint32_t id_163 { leb128_sz_193[id_162] };
                    uint32_t id_164 { 0U };
                    bool id_165 { bool(id_163 > id_164) };
                    while_flag_137 = id_165;
                    if (while_flag_137) {
                    }
                  } while (while_flag_137);
                  uint8_t id_166 { 0 };
                  Pointer id_167 { leb128_ptr_194[id_166] };
                  let_res_136 = id_167;
                }
                let_res_134 = let_res_136;
              }
              v_13778ae74488ba3447259adc9816e04e id_168 { std::get<1>(x_180) };
              std::string id_169 { id_168.on_site };
              Bytes id_170 { id_169 };
              Pointer id_171 { let_res_134.writeBytes(id_170) };
              let_res_129 = id_171;
            }
            Pointer let_res_172;
            {
              Pointer srec_dst_195 { let_res_129 };
              v_13778ae74488ba3447259adc9816e04e id_173 { std::get<1>(x_180) };
              bool id_174 { id_173.automatic };
              uint8_t id_175 { uint8_t(id_174) };
              Pointer id_176 { srec_dst_195.writeU8(id_175) };
              let_res_172 = id_176;
            }
            let_res_49 = let_res_172;
          }
          Void id_177 { ((void)(dst_ref_178[id_42] = let_res_49), VOID) };
          uint8_t id_178 { 0 };
          int32_t id_179 { 1L };
          uint8_t id_180 { 0 };
          int32_t id_181 { n_ref_179[id_180] };
          int32_t id_182 { int32_t(id_179 + id_181) };
          Void id_183 { ((void)(n_ref_179[id_178] = id_182), VOID) };
        }
        uint8_t id_184 { 0 };
        Pointer id_185 { dst_ref_178[id_184] };
        let_res_41 = id_185;
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
    (fun ("($program_name; {enabled: BOOL; debug: BOOL; report_period: FLOAT; cwd: $file_path; params: $program_run_parameter[]; on_site: STRING; automatic: BOOL})[]")
      (let "sz_ref_158"
        (make-vec
          (let "n_ref_156" (make-vec (cardinality (param 0)))
            (let "lebsz_ref_157" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_156")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_157")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_157") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_157")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_157")))))))
        (seq
          (let "repeat_n_159" (make-vec (i32 0))
            (while (gt (to-i32 (cardinality (param 0))) (unsafe-nth (u8 0) (identifier "repeat_n_159")))
              (seq
                (set-vec (u8 0) (identifier "sz_ref_158")
                  (let "sz_161"
                    (let "sz_160" (unsafe-nth (u8 0) (identifier "sz_ref_158"))
                      (add (identifier "sz_160") (apply (ext-identifier program_name sersize-of-row-binary) (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_159")) (param 0))))))
                    (add
                      (let "sz_171"
                        (let "sz_166"
                          (add (add (add (add (identifier "sz_161") (size 1)) (size 1)) (size 8))
                            (apply (ext-identifier file_path sersize-of-row-binary) (get-field "cwd" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_159")) (param 0))))))
                          (let "sz_ref_169"
                            (make-vec
                              (add (identifier "sz_166")
                                (let "n_ref_167" (make-vec (cardinality (get-field "params" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_159")) (param 0))))))
                                  (let "lebsz_ref_168" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_167")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_168")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_168") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_168")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_168"))))))))
                            (seq
                              (let "repeat_n_170" (make-vec (i32 0))
                                (while (gt (to-i32 (cardinality (get-field "params" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_159")) (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_170")))
                                  (seq
                                    (set-vec (u8 0) (identifier "sz_ref_169")
                                      (add (unsafe-nth (u8 0) (identifier "sz_ref_169"))
                                        (apply (ext-identifier program_run_parameter sersize-of-row-binary)
                                          (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_170")) (get-field "params" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_159")) (param 0))))))))
                                    (set-vec (u8 0) (identifier "repeat_n_170") (add (unsafe-nth (u8 0) (identifier "repeat_n_170")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "sz_ref_169")))))
                        (add (identifier "sz_171")
                          (let "wlen_172" (string-length (get-field "on_site" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_159")) (param 0)))))
                            (add
                              (let "n_ref_173" (make-vec (identifier "wlen_172"))
                                (let "lebsz_ref_174" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_173")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_174")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_174") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_174")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_174")))))) 
                              (size-of-u32 (identifier "wlen_172")))))) 
                      (size 1)))) (set-vec (u8 0) (identifier "repeat_n_159") (add (unsafe-nth (u8 0) (identifier "repeat_n_159")) (i32 1)))))) 
          (unsafe-nth (u8 0) (identifier "sz_ref_158")))))
 */
static std::function<Size(t&)> sersize_of_row_binary_init()
{
  std::function<Size(t&)> fun186 { [&fun186](t& p_0) {
    uint32_t id_187 { p_0.size() };
    Vec<1, uint32_t> id_188 {  id_187  };
    Size let_res_189;
    {
      Vec<1, uint32_t> n_ref_156 { id_188 };
      uint32_t id_190 { 1U };
      Vec<1, uint32_t> id_191 {  id_190  };
      Size let_res_192;
      {
        Vec<1, uint32_t> lebsz_ref_157 { id_191 };
        bool while_flag_193 { true };
        do {
          uint8_t id_194 { 0 };
          uint32_t id_195 { n_ref_156[id_194] };
          uint8_t id_196 { 0 };
          uint32_t id_197 { lebsz_ref_157[id_196] };
          uint8_t id_198 { 7 };
          uint32_t id_199 { uint32_t(id_197 << id_198) };
          bool id_200 { bool(id_195 >= id_199) };
          while_flag_193 = id_200;
          if (while_flag_193) {
            uint8_t id_201 { 0 };
            uint8_t id_202 { 0 };
            uint32_t id_203 { lebsz_ref_157[id_202] };
            uint32_t id_204 { 1U };
            uint32_t id_205 { uint32_t(id_203 + id_204) };
            Void id_206 { ((void)(lebsz_ref_157[id_201] = id_205), VOID) };
          }
        } while (while_flag_193);
        uint8_t id_207 { 0 };
        uint32_t id_208 { lebsz_ref_157[id_207] };
        Size id_209 { Size(id_208) };
        let_res_192 = id_209;
      }
      let_res_189 = let_res_192;
    }
    Vec<1, Size> id_210 {  let_res_189  };
    Size let_res_211;
    {
      Vec<1, Size> sz_ref_158 { id_210 };
      int32_t id_212 { 0L };
      Vec<1, int32_t> id_213 {  id_212  };
      {
        Vec<1, int32_t> repeat_n_159 { id_213 };
        bool while_flag_214 { true };
        do {
          uint32_t id_215 { p_0.size() };
          int32_t id_216 { int32_t(id_215) };
          uint8_t id_217 { 0 };
          int32_t id_218 { repeat_n_159[id_217] };
          bool id_219 { bool(id_216 > id_218) };
          while_flag_214 = id_219;
          if (while_flag_214) {
            uint8_t id_220 { 0 };
            uint8_t id_221 { 0 };
            Size id_222 { sz_ref_158[id_221] };
            Size let_res_223;
            {
              Size sz_160 { id_222 };
              std::function<Size(dessser::gen::program_name::t)> id_224 { dessser::gen::program_name::sersize_of_row_binary };
              uint8_t id_225 { 0 };
              int32_t id_226 { repeat_n_159[id_225] };
              cc18b22dfb71145a271a6ff24f6a72b1 id_227 { p_0[id_226] };
              dessser::gen::program_name::t id_228 { std::get<0>(id_227) };
              Size id_229 { id_224(id_228) };
              Size id_230 { Size(sz_160 + id_229) };
              let_res_223 = id_230;
            }
            Size let_res_231;
            {
              Size sz_161 { let_res_223 };
              Size id_232 { 1UL };
              Size id_233 { Size(sz_161 + id_232) };
              Size id_234 { 1UL };
              Size id_235 { Size(id_233 + id_234) };
              Size id_236 { 8UL };
              Size id_237 { Size(id_235 + id_236) };
              std::function<Size(dessser::gen::file_path::t)> id_238 { dessser::gen::file_path::sersize_of_row_binary };
              uint8_t id_239 { 0 };
              int32_t id_240 { repeat_n_159[id_239] };
              cc18b22dfb71145a271a6ff24f6a72b1 id_241 { p_0[id_240] };
              v_13778ae74488ba3447259adc9816e04e id_242 { std::get<1>(id_241) };
              dessser::gen::file_path::t id_243 { id_242.cwd };
              Size id_244 { id_238(id_243) };
              Size id_245 { Size(id_237 + id_244) };
              Size let_res_246;
              {
                Size sz_166 { id_245 };
                uint8_t id_247 { 0 };
                int32_t id_248 { repeat_n_159[id_247] };
                cc18b22dfb71145a271a6ff24f6a72b1 id_249 { p_0[id_248] };
                v_13778ae74488ba3447259adc9816e04e id_250 { std::get<1>(id_249) };
                Arr<dessser::gen::program_run_parameter::t> id_251 { id_250.params };
                uint32_t id_252 { id_251.size() };
                Vec<1, uint32_t> id_253 {  id_252  };
                Size let_res_254;
                {
                  Vec<1, uint32_t> n_ref_167 { id_253 };
                  uint32_t id_255 { 1U };
                  Vec<1, uint32_t> id_256 {  id_255  };
                  Size let_res_257;
                  {
                    Vec<1, uint32_t> lebsz_ref_168 { id_256 };
                    bool while_flag_258 { true };
                    do {
                      uint8_t id_259 { 0 };
                      uint32_t id_260 { n_ref_167[id_259] };
                      uint8_t id_261 { 0 };
                      uint32_t id_262 { lebsz_ref_168[id_261] };
                      uint8_t id_263 { 7 };
                      uint32_t id_264 { uint32_t(id_262 << id_263) };
                      bool id_265 { bool(id_260 >= id_264) };
                      while_flag_258 = id_265;
                      if (while_flag_258) {
                        uint8_t id_266 { 0 };
                        uint8_t id_267 { 0 };
                        uint32_t id_268 { lebsz_ref_168[id_267] };
                        uint32_t id_269 { 1U };
                        uint32_t id_270 { uint32_t(id_268 + id_269) };
                        Void id_271 { ((void)(lebsz_ref_168[id_266] = id_270), VOID) };
                      }
                    } while (while_flag_258);
                    uint8_t id_272 { 0 };
                    uint32_t id_273 { lebsz_ref_168[id_272] };
                    Size id_274 { Size(id_273) };
                    let_res_257 = id_274;
                  }
                  let_res_254 = let_res_257;
                }
                Size id_275 { Size(sz_166 + let_res_254) };
                Vec<1, Size> id_276 {  id_275  };
                Size let_res_277;
                {
                  Vec<1, Size> sz_ref_169 { id_276 };
                  int32_t id_278 { 0L };
                  Vec<1, int32_t> id_279 {  id_278  };
                  {
                    Vec<1, int32_t> repeat_n_170 { id_279 };
                    bool while_flag_280 { true };
                    do {
                      uint8_t id_281 { 0 };
                      int32_t id_282 { repeat_n_159[id_281] };
                      cc18b22dfb71145a271a6ff24f6a72b1 id_283 { p_0[id_282] };
                      v_13778ae74488ba3447259adc9816e04e id_284 { std::get<1>(id_283) };
                      Arr<dessser::gen::program_run_parameter::t> id_285 { id_284.params };
                      uint32_t id_286 { id_285.size() };
                      int32_t id_287 { int32_t(id_286) };
                      uint8_t id_288 { 0 };
                      int32_t id_289 { repeat_n_170[id_288] };
                      bool id_290 { bool(id_287 > id_289) };
                      while_flag_280 = id_290;
                      if (while_flag_280) {
                        uint8_t id_291 { 0 };
                        uint8_t id_292 { 0 };
                        Size id_293 { sz_ref_169[id_292] };
                        std::function<Size(dessser::gen::program_run_parameter::t)> id_294 { dessser::gen::program_run_parameter::sersize_of_row_binary };
                        uint8_t id_295 { 0 };
                        int32_t id_296 { repeat_n_170[id_295] };
                        uint8_t id_297 { 0 };
                        int32_t id_298 { repeat_n_159[id_297] };
                        cc18b22dfb71145a271a6ff24f6a72b1 id_299 { p_0[id_298] };
                        v_13778ae74488ba3447259adc9816e04e id_300 { std::get<1>(id_299) };
                        Arr<dessser::gen::program_run_parameter::t> id_301 { id_300.params };
                        dessser::gen::program_run_parameter::t id_302 { id_301[id_296] };
                        Size id_303 { id_294(id_302) };
                        Size id_304 { Size(id_293 + id_303) };
                        Void id_305 { ((void)(sz_ref_169[id_291] = id_304), VOID) };
                        uint8_t id_306 { 0 };
                        uint8_t id_307 { 0 };
                        int32_t id_308 { repeat_n_170[id_307] };
                        int32_t id_309 { 1L };
                        int32_t id_310 { int32_t(id_308 + id_309) };
                        Void id_311 { ((void)(repeat_n_170[id_306] = id_310), VOID) };
                      }
                    } while (while_flag_280);
                  }
                  uint8_t id_312 { 0 };
                  Size id_313 { sz_ref_169[id_312] };
                  let_res_277 = id_313;
                }
                let_res_246 = let_res_277;
              }
              Size let_res_314;
              {
                Size sz_171 { let_res_246 };
                uint8_t id_315 { 0 };
                int32_t id_316 { repeat_n_159[id_315] };
                cc18b22dfb71145a271a6ff24f6a72b1 id_317 { p_0[id_316] };
                v_13778ae74488ba3447259adc9816e04e id_318 { std::get<1>(id_317) };
                std::string id_319 { id_318.on_site };
                uint32_t id_320 { (uint32_t)id_319.size() };
                Size let_res_321;
                {
                  uint32_t wlen_172 { id_320 };
                  Vec<1, uint32_t> id_322 {  wlen_172  };
                  Size let_res_323;
                  {
                    Vec<1, uint32_t> n_ref_173 { id_322 };
                    uint32_t id_324 { 1U };
                    Vec<1, uint32_t> id_325 {  id_324  };
                    Size let_res_326;
                    {
                      Vec<1, uint32_t> lebsz_ref_174 { id_325 };
                      bool while_flag_327 { true };
                      do {
                        uint8_t id_328 { 0 };
                        uint32_t id_329 { n_ref_173[id_328] };
                        uint8_t id_330 { 0 };
                        uint32_t id_331 { lebsz_ref_174[id_330] };
                        uint8_t id_332 { 7 };
                        uint32_t id_333 { uint32_t(id_331 << id_332) };
                        bool id_334 { bool(id_329 >= id_333) };
                        while_flag_327 = id_334;
                        if (while_flag_327) {
                          uint8_t id_335 { 0 };
                          uint8_t id_336 { 0 };
                          uint32_t id_337 { lebsz_ref_174[id_336] };
                          uint32_t id_338 { 1U };
                          uint32_t id_339 { uint32_t(id_337 + id_338) };
                          Void id_340 { ((void)(lebsz_ref_174[id_335] = id_339), VOID) };
                        }
                      } while (while_flag_327);
                      uint8_t id_341 { 0 };
                      uint32_t id_342 { lebsz_ref_174[id_341] };
                      Size id_343 { Size(id_342) };
                      let_res_326 = id_343;
                    }
                    let_res_323 = let_res_326;
                  }
                  Size id_344 { Size(wlen_172) };
                  Size id_345 { Size(let_res_323 + id_344) };
                  let_res_321 = id_345;
                }
                Size id_346 { Size(sz_171 + let_res_321) };
                let_res_314 = id_346;
              }
              Size id_347 { 1UL };
              Size id_348 { Size(let_res_314 + id_347) };
              let_res_231 = id_348;
            }
            Void id_349 { ((void)(sz_ref_158[id_220] = let_res_231), VOID) };
            uint8_t id_350 { 0 };
            uint8_t id_351 { 0 };
            int32_t id_352 { repeat_n_159[id_351] };
            int32_t id_353 { 1L };
            int32_t id_354 { int32_t(id_352 + id_353) };
            Void id_355 { ((void)(repeat_n_159[id_350] = id_354), VOID) };
          }
        } while (while_flag_214);
      }
      uint8_t id_356 { 0 };
      Size id_357 { sz_ref_158[id_356] };
      let_res_211 = id_357;
    }
    return let_res_211;
  }
   };
  return fun186;
}
std::function<Size(t&)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "dlist4_fst_151" "dlist4_snd_152"
        (let "dlist1_65"
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
                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_56")) (unsafe-nth (u8 0) (identifier "p_ref_58")))))))
          (let-pair "dlist1_fst_66" "dlist1_snd_67" (identifier "dlist1_65")
            (let "inits_src_ref_68"
              (make-vec
                (make-tup (end-of-list "($program_name; {enabled: BOOL; debug: BOOL; report_period: FLOAT; cwd: $file_path; params: $program_run_parameter[]; on_site: STRING; automatic: BOOL})") (identifier "dlist1_snd_67")))
              (seq
                (let "repeat_n_69" (make-vec (i32 0))
                  (while (gt (to-i32 (identifier "dlist1_fst_66")) (unsafe-nth (u8 0) (identifier "repeat_n_69")))
                    (seq
                      (let "dlist2_70" (unsafe-nth (u8 0) (identifier "inits_src_ref_68"))
                        (let-pair "dlist2_fst_71" "dlist2_snd_72" (identifier "dlist2_70")
                          (set-vec (u8 0) (identifier "inits_src_ref_68")
                            (let "dtup_73" (apply (ext-identifier program_name of-row-binary) (identifier "dlist2_snd_72"))
                              (let-pair "dtup_fst_74" "dtup_snd_75" (identifier "dtup_73")
                                (let "drec_79" (let-pair "dbool_fst_77" "dbool_snd_78" (read-u8 (identifier "dtup_snd_75")) (make-tup (not (eq (identifier "dbool_fst_77") (u8 0))) (identifier "dbool_snd_78")))
                                  (let-pair "drec_fst_80" "drec_snd_81" 
                                    (identifier "drec_79")
                                    (let "drec_85" (let-pair "dbool_fst_83" "dbool_snd_84" (read-u8 (identifier "drec_snd_81")) (make-tup (not (eq (identifier "dbool_fst_83") (u8 0))) (identifier "dbool_snd_84")))
                                      (let-pair "drec_fst_86" "drec_snd_87" 
                                        (identifier "drec_85")
                                        (let "drec_91"
                                          (let-pair "dfloat_fst_89" "dfloat_snd_90" (read-u64 little-endian (identifier "drec_snd_87")) (make-tup (float-of-u64 (identifier "dfloat_fst_89")) (identifier "dfloat_snd_90")))
                                          (let-pair "drec_fst_92" "drec_snd_93" 
                                            (identifier "drec_91")
                                            (let "drec_94" (apply (ext-identifier file_path of-row-binary) (identifier "drec_snd_93"))
                                              (let-pair "drec_fst_95" "drec_snd_96" 
                                                (identifier "drec_94")
                                                (let "drec_120"
                                                  (let-pair "dlist4_fst_118" "dlist4_snd_119"
                                                    (let "dlist1_106"
                                                      (let "leb_ref_97" 
                                                        (make-vec (u32 0))
                                                        (let "shft_ref_98" 
                                                          (make-vec (u8 0))
                                                          (let "p_ref_99" 
                                                            (make-vec (identifier "drec_snd_96"))
                                                            (seq
                                                              (while
                                                                (let "leb128_100" 
                                                                  (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_99")))
                                                                  (let-pair "leb128_fst_101" "leb128_snd_102" 
                                                                    (identifier "leb128_100")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_99") (identifier "leb128_snd_102"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_97")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_101") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_98")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_97")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_98") (add (unsafe-nth (u8 0) (identifier "shft_ref_98")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_101") (u8 128))))) 
                                                                (nop)) 
                                                              (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_97")) (unsafe-nth (u8 0) (identifier "p_ref_99")))))))
                                                      (let-pair "dlist1_fst_107" "dlist1_snd_108" 
                                                        (identifier "dlist1_106")
                                                        (let "inits_src_ref_109" 
                                                          (make-vec (make-tup (end-of-list "$program_run_parameter") (identifier "dlist1_snd_108")))
                                                          (seq
                                                            (let "repeat_n_110" 
                                                              (make-vec (i32 0))
                                                              (while 
                                                                (gt (to-i32 (identifier "dlist1_fst_107")) (unsafe-nth (u8 0) (identifier "repeat_n_110")))
                                                                (seq
                                                                  (let "dlist2_111" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_109"))
                                                                    (let-pair "dlist2_fst_112" "dlist2_snd_113" 
                                                                    (identifier "dlist2_111")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_109")
                                                                    (let-pair "dlist3_fst_115" "dlist3_snd_116" 
                                                                    (apply (ext-identifier program_run_parameter of-row-binary) (identifier "dlist2_snd_113"))
                                                                    (make-tup (cons (identifier "dlist3_fst_115") (identifier "dlist2_fst_112")) (identifier "dlist3_snd_116"))))))
                                                                  (set-vec (u8 0) (identifier "repeat_n_110") (add (unsafe-nth (u8 0) (identifier "repeat_n_110")) (i32 1)))))) 
                                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_109")))))) 
                                                    (make-tup (arr-of-lst-rev (identifier "dlist4_fst_118")) (identifier "dlist4_snd_119")))
                                                  (let-pair "drec_fst_121" "drec_snd_122" 
                                                    (identifier "drec_120")
                                                    (let "drec_135"
                                                      (let "dstring1_129"
                                                        (let "leb_ref_123" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_124" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_125" 
                                                              (make-vec (identifier "drec_snd_122"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_126" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_125")))
                                                                    (let-pair "leb128_fst_127" "leb128_snd_128" 
                                                                    (identifier "leb128_126")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_125") (identifier "leb128_snd_128"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_123")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_127") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_124")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_123")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_124") (add (unsafe-nth (u8 0) (identifier "shft_ref_124")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_127") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_123"))) (unsafe-nth (u8 0) (identifier "p_ref_125")))))))
                                                        (let-pair "dstring1_fst_130" "dstring1_snd_131" 
                                                          (identifier "dstring1_129")
                                                          (let-pair "dstring2_fst_133" "dstring2_snd_134" 
                                                            (read-bytes (identifier "dstring1_snd_131") (identifier "dstring1_fst_130"))
                                                            (make-tup (string-of-bytes (identifier "dstring2_fst_133")) (identifier "dstring2_snd_134")))))
                                                      (let-pair "drec_fst_136" "drec_snd_137" 
                                                        (identifier "drec_135")
                                                        (let-pair "dbool_fst_139" "dbool_snd_140" 
                                                          (read-u8 (identifier "drec_snd_137"))
                                                          (make-tup
                                                            (cons
                                                              (make-tup 
                                                                (identifier "dtup_fst_74")
                                                                (make-rec 
                                                                  (string "enabled") 
                                                                  (identifier "drec_fst_80") 
                                                                  (string "debug") 
                                                                  (identifier "drec_fst_86") 
                                                                  (string "report_period") 
                                                                  (identifier "drec_fst_92") 
                                                                  (string "cwd") 
                                                                  (identifier "drec_fst_95") 
                                                                  (string "params") 
                                                                  (identifier "drec_fst_121") 
                                                                  (string "on_site") 
                                                                  (identifier "drec_fst_136") 
                                                                  (string "automatic") 
                                                                  (not (eq (identifier "dbool_fst_139") (u8 0))))) 
                                                              (identifier "dlist2_fst_71")) 
                                                            (identifier "dbool_snd_140")))))))))))))))))))) 
                      (set-vec (u8 0) (identifier "repeat_n_69") (add (unsafe-nth (u8 0) (identifier "repeat_n_69")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "inits_src_ref_68")))))) 
        (make-tup (arr-of-lst-rev (identifier "dlist4_fst_151")) (identifier "dlist4_snd_152"))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun358 { [&fun358](Pointer p_0) {
    uint32_t id_359 { 0U };
    Vec<1, uint32_t> id_360 {  id_359  };
    ac0fbd05039f742d2f1d9ac182e392ab let_res_361;
    {
      Vec<1, uint32_t> leb_ref_56 { id_360 };
      uint8_t id_362 { 0 };
      Vec<1, uint8_t> id_363 {  id_362  };
      ac0fbd05039f742d2f1d9ac182e392ab let_res_364;
      {
        Vec<1, uint8_t> shft_ref_57 { id_363 };
        Vec<1, Pointer> id_365 {  p_0  };
        ac0fbd05039f742d2f1d9ac182e392ab let_res_366;
        {
          Vec<1, Pointer> p_ref_58 { id_365 };
          bool while_flag_367 { true };
          do {
            uint8_t id_368 { 0 };
            Pointer id_369 { p_ref_58[id_368] };
            v_1d5843897434feb24d158f3793db9189 id_370 { id_369.readU8() };
            bool let_res_371;
            {
              v_1d5843897434feb24d158f3793db9189 leb128_59 { id_370 };
              bool letpair_res_372;
              {
                auto leb128_fst_60 { std::get<0>(leb128_59) };
                auto leb128_snd_61 { std::get<1>(leb128_59) };
                uint8_t id_373 { 0 };
                Void id_374 { ((void)(p_ref_58[id_373] = leb128_snd_61), VOID) };
                uint8_t id_375 { 0 };
                uint8_t id_376 { 127 };
                uint8_t id_377 { uint8_t(leb128_fst_60 & id_376) };
                uint32_t id_378 { uint32_t(id_377) };
                uint8_t id_379 { 0 };
                uint8_t id_380 { shft_ref_57[id_379] };
                uint32_t id_381 { uint32_t(id_378 << id_380) };
                uint8_t id_382 { 0 };
                uint32_t id_383 { leb_ref_56[id_382] };
                uint32_t id_384 { uint32_t(id_381 | id_383) };
                Void id_385 { ((void)(leb_ref_56[id_375] = id_384), VOID) };
                uint8_t id_386 { 0 };
                uint8_t id_387 { 0 };
                uint8_t id_388 { shft_ref_57[id_387] };
                uint8_t id_389 { 7 };
                uint8_t id_390 { uint8_t(id_388 + id_389) };
                Void id_391 { ((void)(shft_ref_57[id_386] = id_390), VOID) };
                uint8_t id_392 { 128 };
                bool id_393 { bool(leb128_fst_60 >= id_392) };
                letpair_res_372 = id_393;
              }
              let_res_371 = letpair_res_372;
            }
            while_flag_367 = let_res_371;
            if (while_flag_367) {
            }
          } while (while_flag_367);
          uint8_t id_394 { 0 };
          uint32_t id_395 { leb_ref_56[id_394] };
          uint8_t id_396 { 0 };
          Pointer id_397 { p_ref_58[id_396] };
          ac0fbd05039f742d2f1d9ac182e392ab id_398 {  id_395, id_397  };
          let_res_366 = id_398;
        }
        let_res_364 = let_res_366;
      }
      let_res_361 = let_res_364;
    }
    v_478c17794159145a25a7b9622851ad8e let_res_399;
    {
      ac0fbd05039f742d2f1d9ac182e392ab dlist1_65 { let_res_361 };
      v_478c17794159145a25a7b9622851ad8e letpair_res_400;
      {
        auto dlist1_fst_66 { std::get<0>(dlist1_65) };
        auto dlist1_snd_67 { std::get<1>(dlist1_65) };
        Lst<cc18b22dfb71145a271a6ff24f6a72b1> endoflist_401;
        v_478c17794159145a25a7b9622851ad8e id_402 {  endoflist_401, dlist1_snd_67  };
        Vec<1, v_478c17794159145a25a7b9622851ad8e> id_403 {  id_402  };
        v_478c17794159145a25a7b9622851ad8e let_res_404;
        {
          Vec<1, v_478c17794159145a25a7b9622851ad8e> inits_src_ref_68 { id_403 };
          int32_t id_405 { 0L };
          Vec<1, int32_t> id_406 {  id_405  };
          {
            Vec<1, int32_t> repeat_n_69 { id_406 };
            bool while_flag_407 { true };
            do {
              int32_t id_408 { int32_t(dlist1_fst_66) };
              uint8_t id_409 { 0 };
              int32_t id_410 { repeat_n_69[id_409] };
              bool id_411 { bool(id_408 > id_410) };
              while_flag_407 = id_411;
              if (while_flag_407) {
                uint8_t id_412 { 0 };
                v_478c17794159145a25a7b9622851ad8e id_413 { inits_src_ref_68[id_412] };
                {
                  v_478c17794159145a25a7b9622851ad8e dlist2_70 { id_413 };
                  {
                    auto dlist2_fst_71 { std::get<0>(dlist2_70) };
                    auto dlist2_snd_72 { std::get<1>(dlist2_70) };
                    uint8_t id_414 { 0 };
                    std::function<f6e2f55e3ebc4a068d1f568f5860423e(Pointer)> id_415 { dessser::gen::program_name::of_row_binary };
                    f6e2f55e3ebc4a068d1f568f5860423e id_416 { id_415(dlist2_snd_72) };
                    v_478c17794159145a25a7b9622851ad8e let_res_417;
                    {
                      f6e2f55e3ebc4a068d1f568f5860423e dtup_73 { id_416 };
                      v_478c17794159145a25a7b9622851ad8e letpair_res_418;
                      {
                        auto dtup_fst_74 { std::get<0>(dtup_73) };
                        auto dtup_snd_75 { std::get<1>(dtup_73) };
                        v_1d5843897434feb24d158f3793db9189 id_419 { dtup_snd_75.readU8() };
                        f2a48a42f9c827f487e53ee52a4e9e2f letpair_res_420;
                        {
                          auto dbool_fst_77 { std::get<0>(id_419) };
                          auto dbool_snd_78 { std::get<1>(id_419) };
                          uint8_t id_421 { 0 };
                          bool id_422 { bool(dbool_fst_77 == id_421) };
                          bool id_423 { ! id_422 };
                          f2a48a42f9c827f487e53ee52a4e9e2f id_424 {  id_423, dbool_snd_78  };
                          letpair_res_420 = id_424;
                        }
                        v_478c17794159145a25a7b9622851ad8e let_res_425;
                        {
                          f2a48a42f9c827f487e53ee52a4e9e2f drec_79 { letpair_res_420 };
                          v_478c17794159145a25a7b9622851ad8e letpair_res_426;
                          {
                            auto drec_fst_80 { std::get<0>(drec_79) };
                            auto drec_snd_81 { std::get<1>(drec_79) };
                            v_1d5843897434feb24d158f3793db9189 id_427 { drec_snd_81.readU8() };
                            f2a48a42f9c827f487e53ee52a4e9e2f letpair_res_428;
                            {
                              auto dbool_fst_83 { std::get<0>(id_427) };
                              auto dbool_snd_84 { std::get<1>(id_427) };
                              uint8_t id_429 { 0 };
                              bool id_430 { bool(dbool_fst_83 == id_429) };
                              bool id_431 { ! id_430 };
                              f2a48a42f9c827f487e53ee52a4e9e2f id_432 {  id_431, dbool_snd_84  };
                              letpair_res_428 = id_432;
                            }
                            v_478c17794159145a25a7b9622851ad8e let_res_433;
                            {
                              f2a48a42f9c827f487e53ee52a4e9e2f drec_85 { letpair_res_428 };
                              v_478c17794159145a25a7b9622851ad8e letpair_res_434;
                              {
                                auto drec_fst_86 { std::get<0>(drec_85) };
                                auto drec_snd_87 { std::get<1>(drec_85) };
                                b62e103e7915a76f45f02f7c6f667c79 id_435 { drec_snd_87.readU64Le() };
                                v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_436;
                                {
                                  auto dfloat_fst_89 { std::get<0>(id_435) };
                                  auto dfloat_snd_90 { std::get<1>(id_435) };
                                  double id_437 { float_of_qword(dfloat_fst_89) };
                                  v_41a5a8cf414de9bfdc6375241fcc910a id_438 {  id_437, dfloat_snd_90  };
                                  letpair_res_436 = id_438;
                                }
                                v_478c17794159145a25a7b9622851ad8e let_res_439;
                                {
                                  v_41a5a8cf414de9bfdc6375241fcc910a drec_91 { letpair_res_436 };
                                  v_478c17794159145a25a7b9622851ad8e letpair_res_440;
                                  {
                                    auto drec_fst_92 { std::get<0>(drec_91) };
                                    auto drec_snd_93 { std::get<1>(drec_91) };
                                    std::function<f0ce35c43c556a289e4bbac0d50849f5(Pointer)> id_441 { dessser::gen::file_path::of_row_binary };
                                    f0ce35c43c556a289e4bbac0d50849f5 id_442 { id_441(drec_snd_93) };
                                    v_478c17794159145a25a7b9622851ad8e let_res_443;
                                    {
                                      f0ce35c43c556a289e4bbac0d50849f5 drec_94 { id_442 };
                                      v_478c17794159145a25a7b9622851ad8e letpair_res_444;
                                      {
                                        auto drec_fst_95 { std::get<0>(drec_94) };
                                        auto drec_snd_96 { std::get<1>(drec_94) };
                                        uint32_t id_445 { 0U };
                                        Vec<1, uint32_t> id_446 {  id_445  };
                                        ac0fbd05039f742d2f1d9ac182e392ab let_res_447;
                                        {
                                          Vec<1, uint32_t> leb_ref_97 { id_446 };
                                          uint8_t id_448 { 0 };
                                          Vec<1, uint8_t> id_449 {  id_448  };
                                          ac0fbd05039f742d2f1d9ac182e392ab let_res_450;
                                          {
                                            Vec<1, uint8_t> shft_ref_98 { id_449 };
                                            Vec<1, Pointer> id_451 {  drec_snd_96  };
                                            ac0fbd05039f742d2f1d9ac182e392ab let_res_452;
                                            {
                                              Vec<1, Pointer> p_ref_99 { id_451 };
                                              bool while_flag_453 { true };
                                              do {
                                                uint8_t id_454 { 0 };
                                                Pointer id_455 { p_ref_99[id_454] };
                                                v_1d5843897434feb24d158f3793db9189 id_456 { id_455.readU8() };
                                                bool let_res_457;
                                                {
                                                  v_1d5843897434feb24d158f3793db9189 leb128_100 { id_456 };
                                                  bool letpair_res_458;
                                                  {
                                                    auto leb128_fst_101 { std::get<0>(leb128_100) };
                                                    auto leb128_snd_102 { std::get<1>(leb128_100) };
                                                    uint8_t id_459 { 0 };
                                                    Void id_460 { ((void)(p_ref_99[id_459] = leb128_snd_102), VOID) };
                                                    uint8_t id_461 { 0 };
                                                    uint8_t id_462 { 127 };
                                                    uint8_t id_463 { uint8_t(leb128_fst_101 & id_462) };
                                                    uint32_t id_464 { uint32_t(id_463) };
                                                    uint8_t id_465 { 0 };
                                                    uint8_t id_466 { shft_ref_98[id_465] };
                                                    uint32_t id_467 { uint32_t(id_464 << id_466) };
                                                    uint8_t id_468 { 0 };
                                                    uint32_t id_469 { leb_ref_97[id_468] };
                                                    uint32_t id_470 { uint32_t(id_467 | id_469) };
                                                    Void id_471 { ((void)(leb_ref_97[id_461] = id_470), VOID) };
                                                    uint8_t id_472 { 0 };
                                                    uint8_t id_473 { 0 };
                                                    uint8_t id_474 { shft_ref_98[id_473] };
                                                    uint8_t id_475 { 7 };
                                                    uint8_t id_476 { uint8_t(id_474 + id_475) };
                                                    Void id_477 { ((void)(shft_ref_98[id_472] = id_476), VOID) };
                                                    uint8_t id_478 { 128 };
                                                    bool id_479 { bool(leb128_fst_101 >= id_478) };
                                                    letpair_res_458 = id_479;
                                                  }
                                                  let_res_457 = letpair_res_458;
                                                }
                                                while_flag_453 = let_res_457;
                                                if (while_flag_453) {
                                                }
                                              } while (while_flag_453);
                                              uint8_t id_480 { 0 };
                                              uint32_t id_481 { leb_ref_97[id_480] };
                                              uint8_t id_482 { 0 };
                                              Pointer id_483 { p_ref_99[id_482] };
                                              ac0fbd05039f742d2f1d9ac182e392ab id_484 {  id_481, id_483  };
                                              let_res_452 = id_484;
                                            }
                                            let_res_450 = let_res_452;
                                          }
                                          let_res_447 = let_res_450;
                                        }
                                        v_6ff2026c09f75e223ce21e637140a238 let_res_485;
                                        {
                                          ac0fbd05039f742d2f1d9ac182e392ab dlist1_106 { let_res_447 };
                                          v_6ff2026c09f75e223ce21e637140a238 letpair_res_486;
                                          {
                                            auto dlist1_fst_107 { std::get<0>(dlist1_106) };
                                            auto dlist1_snd_108 { std::get<1>(dlist1_106) };
                                            Lst<dessser::gen::program_run_parameter::t> endoflist_487;
                                            v_6ff2026c09f75e223ce21e637140a238 id_488 {  endoflist_487, dlist1_snd_108  };
                                            Vec<1, v_6ff2026c09f75e223ce21e637140a238> id_489 {  id_488  };
                                            v_6ff2026c09f75e223ce21e637140a238 let_res_490;
                                            {
                                              Vec<1, v_6ff2026c09f75e223ce21e637140a238> inits_src_ref_109 { id_489 };
                                              int32_t id_491 { 0L };
                                              Vec<1, int32_t> id_492 {  id_491  };
                                              {
                                                Vec<1, int32_t> repeat_n_110 { id_492 };
                                                bool while_flag_493 { true };
                                                do {
                                                  int32_t id_494 { int32_t(dlist1_fst_107) };
                                                  uint8_t id_495 { 0 };
                                                  int32_t id_496 { repeat_n_110[id_495] };
                                                  bool id_497 { bool(id_494 > id_496) };
                                                  while_flag_493 = id_497;
                                                  if (while_flag_493) {
                                                    uint8_t id_498 { 0 };
                                                    v_6ff2026c09f75e223ce21e637140a238 id_499 { inits_src_ref_109[id_498] };
                                                    {
                                                      v_6ff2026c09f75e223ce21e637140a238 dlist2_111 { id_499 };
                                                      {
                                                        auto dlist2_fst_112 { std::get<0>(dlist2_111) };
                                                        auto dlist2_snd_113 { std::get<1>(dlist2_111) };
                                                        uint8_t id_500 { 0 };
                                                        std::function<v_97e7003b69c0f14d17f9608e0f17d035(Pointer)> id_501 { dessser::gen::program_run_parameter::of_row_binary };
                                                        v_97e7003b69c0f14d17f9608e0f17d035 id_502 { id_501(dlist2_snd_113) };
                                                        v_6ff2026c09f75e223ce21e637140a238 letpair_res_503;
                                                        {
                                                          auto dlist3_fst_115 { std::get<0>(id_502) };
                                                          auto dlist3_snd_116 { std::get<1>(id_502) };
                                                          Lst<dessser::gen::program_run_parameter::t> id_504 { dlist3_fst_115, dlist2_fst_112 };
                                                          v_6ff2026c09f75e223ce21e637140a238 id_505 {  id_504, dlist3_snd_116  };
                                                          letpair_res_503 = id_505;
                                                        }
                                                        Void id_506 { ((void)(inits_src_ref_109[id_500] = letpair_res_503), VOID) };
                                                      }
                                                    }
                                                    uint8_t id_507 { 0 };
                                                    uint8_t id_508 { 0 };
                                                    int32_t id_509 { repeat_n_110[id_508] };
                                                    int32_t id_510 { 1L };
                                                    int32_t id_511 { int32_t(id_509 + id_510) };
                                                    Void id_512 { ((void)(repeat_n_110[id_507] = id_511), VOID) };
                                                  }
                                                } while (while_flag_493);
                                              }
                                              uint8_t id_513 { 0 };
                                              v_6ff2026c09f75e223ce21e637140a238 id_514 { inits_src_ref_109[id_513] };
                                              let_res_490 = id_514;
                                            }
                                            letpair_res_486 = let_res_490;
                                          }
                                          let_res_485 = letpair_res_486;
                                        }
                                        v_173c41cb615a30ffc96dea16ddfd38ef letpair_res_515;
                                        {
                                          auto dlist4_fst_118 { std::get<0>(let_res_485) };
                                          auto dlist4_snd_119 { std::get<1>(let_res_485) };
                                          Arr<dessser::gen::program_run_parameter::t> id_516 { dlist4_fst_118.toListRev() };
                                          v_173c41cb615a30ffc96dea16ddfd38ef id_517 {  id_516, dlist4_snd_119  };
                                          letpair_res_515 = id_517;
                                        }
                                        v_478c17794159145a25a7b9622851ad8e let_res_518;
                                        {
                                          v_173c41cb615a30ffc96dea16ddfd38ef drec_120 { letpair_res_515 };
                                          v_478c17794159145a25a7b9622851ad8e letpair_res_519;
                                          {
                                            auto drec_fst_121 { std::get<0>(drec_120) };
                                            auto drec_snd_122 { std::get<1>(drec_120) };
                                            uint32_t id_520 { 0U };
                                            Vec<1, uint32_t> id_521 {  id_520  };
                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_522;
                                            {
                                              Vec<1, uint32_t> leb_ref_123 { id_521 };
                                              uint8_t id_523 { 0 };
                                              Vec<1, uint8_t> id_524 {  id_523  };
                                              v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_525;
                                              {
                                                Vec<1, uint8_t> shft_ref_124 { id_524 };
                                                Vec<1, Pointer> id_526 {  drec_snd_122  };
                                                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_527;
                                                {
                                                  Vec<1, Pointer> p_ref_125 { id_526 };
                                                  bool while_flag_528 { true };
                                                  do {
                                                    uint8_t id_529 { 0 };
                                                    Pointer id_530 { p_ref_125[id_529] };
                                                    v_1d5843897434feb24d158f3793db9189 id_531 { id_530.readU8() };
                                                    bool let_res_532;
                                                    {
                                                      v_1d5843897434feb24d158f3793db9189 leb128_126 { id_531 };
                                                      bool letpair_res_533;
                                                      {
                                                        auto leb128_fst_127 { std::get<0>(leb128_126) };
                                                        auto leb128_snd_128 { std::get<1>(leb128_126) };
                                                        uint8_t id_534 { 0 };
                                                        Void id_535 { ((void)(p_ref_125[id_534] = leb128_snd_128), VOID) };
                                                        uint8_t id_536 { 0 };
                                                        uint8_t id_537 { 127 };
                                                        uint8_t id_538 { uint8_t(leb128_fst_127 & id_537) };
                                                        uint32_t id_539 { uint32_t(id_538) };
                                                        uint8_t id_540 { 0 };
                                                        uint8_t id_541 { shft_ref_124[id_540] };
                                                        uint32_t id_542 { uint32_t(id_539 << id_541) };
                                                        uint8_t id_543 { 0 };
                                                        uint32_t id_544 { leb_ref_123[id_543] };
                                                        uint32_t id_545 { uint32_t(id_542 | id_544) };
                                                        Void id_546 { ((void)(leb_ref_123[id_536] = id_545), VOID) };
                                                        uint8_t id_547 { 0 };
                                                        uint8_t id_548 { 0 };
                                                        uint8_t id_549 { shft_ref_124[id_548] };
                                                        uint8_t id_550 { 7 };
                                                        uint8_t id_551 { uint8_t(id_549 + id_550) };
                                                        Void id_552 { ((void)(shft_ref_124[id_547] = id_551), VOID) };
                                                        uint8_t id_553 { 128 };
                                                        bool id_554 { bool(leb128_fst_127 >= id_553) };
                                                        letpair_res_533 = id_554;
                                                      }
                                                      let_res_532 = letpair_res_533;
                                                    }
                                                    while_flag_528 = let_res_532;
                                                    if (while_flag_528) {
                                                    }
                                                  } while (while_flag_528);
                                                  uint8_t id_555 { 0 };
                                                  uint32_t id_556 { leb_ref_123[id_555] };
                                                  Size id_557 { Size(id_556) };
                                                  uint8_t id_558 { 0 };
                                                  Pointer id_559 { p_ref_125[id_558] };
                                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 id_560 {  id_557, id_559  };
                                                  let_res_527 = id_560;
                                                }
                                                let_res_525 = let_res_527;
                                              }
                                              let_res_522 = let_res_525;
                                            }
                                            v_46a5e81c2410b000ff0adea6dc198147 let_res_561;
                                            {
                                              v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_129 { let_res_522 };
                                              v_46a5e81c2410b000ff0adea6dc198147 letpair_res_562;
                                              {
                                                auto dstring1_fst_130 { std::get<0>(dstring1_129) };
                                                auto dstring1_snd_131 { std::get<1>(dstring1_129) };
                                                f921d1e0a170c3c04148c21704db9c45 id_563 { dstring1_snd_131.readBytes(dstring1_fst_130) };
                                                v_46a5e81c2410b000ff0adea6dc198147 letpair_res_564;
                                                {
                                                  auto dstring2_fst_133 { std::get<0>(id_563) };
                                                  auto dstring2_snd_134 { std::get<1>(id_563) };
                                                  std::string id_565 { dstring2_fst_133.toString() };
                                                  v_46a5e81c2410b000ff0adea6dc198147 id_566 {  id_565, dstring2_snd_134  };
                                                  letpair_res_564 = id_566;
                                                }
                                                letpair_res_562 = letpair_res_564;
                                              }
                                              let_res_561 = letpair_res_562;
                                            }
                                            v_478c17794159145a25a7b9622851ad8e let_res_567;
                                            {
                                              v_46a5e81c2410b000ff0adea6dc198147 drec_135 { let_res_561 };
                                              v_478c17794159145a25a7b9622851ad8e letpair_res_568;
                                              {
                                                auto drec_fst_136 { std::get<0>(drec_135) };
                                                auto drec_snd_137 { std::get<1>(drec_135) };
                                                v_1d5843897434feb24d158f3793db9189 id_569 { drec_snd_137.readU8() };
                                                v_478c17794159145a25a7b9622851ad8e letpair_res_570;
                                                {
                                                  auto dbool_fst_139 { std::get<0>(id_569) };
                                                  auto dbool_snd_140 { std::get<1>(id_569) };
                                                  uint8_t id_571 { 0 };
                                                  bool id_572 { bool(dbool_fst_139 == id_571) };
                                                  bool id_573 { ! id_572 };
                                                  v_13778ae74488ba3447259adc9816e04e id_574 {  .enabled = drec_fst_80, .debug = drec_fst_86, .report_period = drec_fst_92, .cwd = drec_fst_95, .params = drec_fst_121, .on_site = drec_fst_136, .automatic = id_573  };
                                                  cc18b22dfb71145a271a6ff24f6a72b1 id_575 {  dtup_fst_74, id_574  };
                                                  Lst<cc18b22dfb71145a271a6ff24f6a72b1> id_576 { id_575, dlist2_fst_71 };
                                                  v_478c17794159145a25a7b9622851ad8e id_577 {  id_576, dbool_snd_140  };
                                                  letpair_res_570 = id_577;
                                                }
                                                letpair_res_568 = letpair_res_570;
                                              }
                                              let_res_567 = letpair_res_568;
                                            }
                                            letpair_res_519 = let_res_567;
                                          }
                                          let_res_518 = letpair_res_519;
                                        }
                                        letpair_res_444 = let_res_518;
                                      }
                                      let_res_443 = letpair_res_444;
                                    }
                                    letpair_res_440 = let_res_443;
                                  }
                                  let_res_439 = letpair_res_440;
                                }
                                letpair_res_434 = let_res_439;
                              }
                              let_res_433 = letpair_res_434;
                            }
                            letpair_res_426 = let_res_433;
                          }
                          let_res_425 = letpair_res_426;
                        }
                        letpair_res_418 = let_res_425;
                      }
                      let_res_417 = letpair_res_418;
                    }
                    Void id_578 { ((void)(inits_src_ref_68[id_414] = let_res_417), VOID) };
                  }
                }
                uint8_t id_579 { 0 };
                uint8_t id_580 { 0 };
                int32_t id_581 { repeat_n_69[id_580] };
                int32_t id_582 { 1L };
                int32_t id_583 { int32_t(id_581 + id_582) };
                Void id_584 { ((void)(repeat_n_69[id_579] = id_583), VOID) };
              }
            } while (while_flag_407);
          }
          uint8_t id_585 { 0 };
          v_478c17794159145a25a7b9622851ad8e id_586 { inits_src_ref_68[id_585] };
          let_res_404 = id_586;
        }
        letpair_res_400 = let_res_404;
      }
      let_res_399 = letpair_res_400;
    }
    f63f919559f0d70225bd0da5dd9bcafc letpair_res_587;
    {
      auto dlist4_fst_151 { std::get<0>(let_res_399) };
      auto dlist4_snd_152 { std::get<1>(let_res_399) };
      t id_588 { dlist4_fst_151.toListRev() };
      f63f919559f0d70225bd0da5dd9bcafc id_589 {  id_588, dlist4_snd_152  };
      letpair_res_587 = id_589;
    }
    return letpair_res_587;
  }
   };
  return fun358;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
