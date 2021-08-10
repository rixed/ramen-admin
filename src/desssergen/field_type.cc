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

namespace dessser::gen::field_type {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_name::t name;
  dessser::gen::raql_type::t typ;
  std::optional<dessser::gen::units::t> units;
  std::string doc;
  std::optional<std::string> aggr;
  bool operator==(t const &other) const {
    return name == other.name && typ == other.typ && units == other.units && doc == other.doc && aggr == other.aggr;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "typ:" << r.typ << ',';
  os << "units:" << r.units << ',';
  os << "doc:" << r.doc << ',';
  os << "aggr:" << r.aggr;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  dessser::gen::field_name::t,
  Pointer
> c50aa083fa818c6eeca389b0025dda98;

typedef std::tuple<
  dessser::gen::raql_type::t,
  Pointer
> v_1afe9f73328d6d7bdf808b1d2eb2af22;

typedef std::tuple<
  std::optional<dessser::gen::units::t>,
  Pointer
> bf974315651fdd731eda317cf9d211f4;

typedef std::tuple<
  dessser::gen::units::t,
  Pointer
> v_765fc2dfa0d4b4acfe348a1dcf7356d2;

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
  std::optional<std::string>,
  Pointer
> fe18be5220bdca71492df7686dadc3c2;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{name: $field_name; typ: $raql_type; units: $units?; doc: STRING; aggr: STRING?}" "Ptr")
      (let "srec_dst_120"
        (let "srec_dst_117"
          (let "srec_dst_116"
            (let "srec_dst_115" (apply (ext-identifier field_name to-row-binary) (get-field "name" (param 0)) (param 1)) (apply (ext-identifier raql_type to-row-binary) (get-field "typ" (param 0)) (identifier "srec_dst_115")))
            (if (is-null (get-field "units" (param 0))) (write-u8 (identifier "srec_dst_116") (u8 1))
              (apply (ext-identifier units to-row-binary) (force (get-field "units" (param 0))) (write-u8 (identifier "srec_dst_116") (u8 0)))))
          (write-bytes
            (let "leb128_sz_118" (make-vec (string-length (get-field "doc" (param 0))))
              (let "leb128_ptr_119" (make-vec (identifier "srec_dst_117"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_119")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_119"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_118"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_118"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_118"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_118") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_118")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_118")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_119"))))) 
            (bytes-of-string (get-field "doc" (param 0)))))
        (if (is-null (get-field "aggr" (param 0))) (write-u8 (identifier "srec_dst_120") (u8 1))
          (write-bytes
            (let "leb128_sz_121" (make-vec (string-length (force (get-field "aggr" (param 0)))))
              (let "leb128_ptr_122" (make-vec (write-u8 (identifier "srec_dst_120") (u8 0)))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_122")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_122"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_121"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_121"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_121"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_121") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_121")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_121")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_122"))))) 
            (bytes-of-string (force (get-field "aggr" (param 0))))))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    std::function<Pointer(dessser::gen::field_name::t,Pointer)> id_1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t id_2 { p_0.name };
    Pointer id_3 { id_1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_115 { id_3 };
      std::function<Pointer(dessser::gen::raql_type::t,Pointer)> id_5 { dessser::gen::raql_type::to_row_binary };
      dessser::gen::raql_type::t id_6 { p_0.typ };
      Pointer id_7 { id_5(id_6, srec_dst_115) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_116 { let_res_4 };
      std::optional<dessser::gen::units::t> id_9 { p_0.units };
      bool id_10 { !(id_9.has_value ()) };
      Pointer choose_res_11;
      if (id_10) {
        uint8_t id_12 { 1 };
        Pointer id_13 { srec_dst_116.writeU8(id_12) };
        choose_res_11 = id_13;
      } else {
        std::function<Pointer(dessser::gen::units::t,Pointer)> id_14 { dessser::gen::units::to_row_binary };
        std::optional<dessser::gen::units::t> id_15 { p_0.units };
        dessser::gen::units::t id_16 { id_15.value() };
        uint8_t id_17 { 0 };
        Pointer id_18 { srec_dst_116.writeU8(id_17) };
        Pointer id_19 { id_14(id_16, id_18) };
        choose_res_11 = id_19;
      }
      let_res_8 = choose_res_11;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_117 { let_res_8 };
      std::string id_21 { p_0.doc };
      uint32_t id_22 { (uint32_t)id_21.size() };
      Vec<1, uint32_t> id_23 {  id_22  };
      Pointer let_res_24;
      {
        Vec<1, uint32_t> leb128_sz_118 { id_23 };
        Vec<1, Pointer> id_25 {  srec_dst_117  };
        Pointer let_res_26;
        {
          Vec<1, Pointer> leb128_ptr_119 { id_25 };
          bool while_flag_27 { true };
          do {
            uint8_t id_28 { 0 };
            uint8_t id_29 { 0 };
            Pointer id_30 { leb128_ptr_119[id_29] };
            uint32_t id_31 { 128U };
            uint8_t id_32 { 0 };
            uint32_t id_33 { leb128_sz_118[id_32] };
            bool id_34 { bool(id_31 > id_33) };
            uint8_t choose_res_35;
            if (id_34) {
              uint8_t id_36 { 0 };
              uint32_t id_37 { leb128_sz_118[id_36] };
              uint8_t id_38 { uint8_t(id_37) };
              choose_res_35 = id_38;
            } else {
              uint8_t id_39 { 0 };
              uint32_t id_40 { leb128_sz_118[id_39] };
              uint8_t id_41 { uint8_t(id_40) };
              uint8_t id_42 { 128 };
              uint8_t id_43 { uint8_t(id_41 | id_42) };
              choose_res_35 = id_43;
            }
            Pointer id_44 { id_30.writeU8(choose_res_35) };
            Void id_45 { ((void)(leb128_ptr_119[id_28] = id_44), VOID) };
            uint8_t id_46 { 0 };
            uint8_t id_47 { 0 };
            uint32_t id_48 { leb128_sz_118[id_47] };
            uint8_t id_49 { 7 };
            uint32_t id_50 { uint32_t(id_48 >> id_49) };
            Void id_51 { ((void)(leb128_sz_118[id_46] = id_50), VOID) };
            uint8_t id_52 { 0 };
            uint32_t id_53 { leb128_sz_118[id_52] };
            uint32_t id_54 { 0U };
            bool id_55 { bool(id_53 > id_54) };
            while_flag_27 = id_55;
            if (while_flag_27) {
            }
          } while (while_flag_27);
          uint8_t id_56 { 0 };
          Pointer id_57 { leb128_ptr_119[id_56] };
          let_res_26 = id_57;
        }
        let_res_24 = let_res_26;
      }
      std::string id_58 { p_0.doc };
      Bytes id_59 { id_58 };
      Pointer id_60 { let_res_24.writeBytes(id_59) };
      let_res_20 = id_60;
    }
    Pointer let_res_61;
    {
      Pointer srec_dst_120 { let_res_20 };
      std::optional<std::string> id_62 { p_0.aggr };
      bool id_63 { !(id_62.has_value ()) };
      Pointer choose_res_64;
      if (id_63) {
        uint8_t id_65 { 1 };
        Pointer id_66 { srec_dst_120.writeU8(id_65) };
        choose_res_64 = id_66;
      } else {
        std::optional<std::string> id_67 { p_0.aggr };
        std::string id_68 { id_67.value() };
        uint32_t id_69 { (uint32_t)id_68.size() };
        Vec<1, uint32_t> id_70 {  id_69  };
        Pointer let_res_71;
        {
          Vec<1, uint32_t> leb128_sz_121 { id_70 };
          uint8_t id_72 { 0 };
          Pointer id_73 { srec_dst_120.writeU8(id_72) };
          Vec<1, Pointer> id_74 {  id_73  };
          Pointer let_res_75;
          {
            Vec<1, Pointer> leb128_ptr_122 { id_74 };
            bool while_flag_76 { true };
            do {
              uint8_t id_77 { 0 };
              uint8_t id_78 { 0 };
              Pointer id_79 { leb128_ptr_122[id_78] };
              uint32_t id_80 { 128U };
              uint8_t id_81 { 0 };
              uint32_t id_82 { leb128_sz_121[id_81] };
              bool id_83 { bool(id_80 > id_82) };
              uint8_t choose_res_84;
              if (id_83) {
                uint8_t id_85 { 0 };
                uint32_t id_86 { leb128_sz_121[id_85] };
                uint8_t id_87 { uint8_t(id_86) };
                choose_res_84 = id_87;
              } else {
                uint8_t id_88 { 0 };
                uint32_t id_89 { leb128_sz_121[id_88] };
                uint8_t id_90 { uint8_t(id_89) };
                uint8_t id_91 { 128 };
                uint8_t id_92 { uint8_t(id_90 | id_91) };
                choose_res_84 = id_92;
              }
              Pointer id_93 { id_79.writeU8(choose_res_84) };
              Void id_94 { ((void)(leb128_ptr_122[id_77] = id_93), VOID) };
              uint8_t id_95 { 0 };
              uint8_t id_96 { 0 };
              uint32_t id_97 { leb128_sz_121[id_96] };
              uint8_t id_98 { 7 };
              uint32_t id_99 { uint32_t(id_97 >> id_98) };
              Void id_100 { ((void)(leb128_sz_121[id_95] = id_99), VOID) };
              uint8_t id_101 { 0 };
              uint32_t id_102 { leb128_sz_121[id_101] };
              uint32_t id_103 { 0U };
              bool id_104 { bool(id_102 > id_103) };
              while_flag_76 = id_104;
              if (while_flag_76) {
              }
            } while (while_flag_76);
            uint8_t id_105 { 0 };
            Pointer id_106 { leb128_ptr_122[id_105] };
            let_res_75 = id_106;
          }
          let_res_71 = let_res_75;
        }
        std::optional<std::string> id_107 { p_0.aggr };
        std::string id_108 { id_107.value() };
        Bytes id_109 { id_108 };
        Pointer id_110 { let_res_71.writeBytes(id_109) };
        choose_res_64 = id_110;
      }
      let_res_61 = choose_res_64;
    }
    return let_res_61;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{name: $field_name; typ: $raql_type; units: $units?; doc: STRING; aggr: STRING?}")
      (let "sz_111"
        (let "sz_107"
          (let "sz_106"
            (let "sz_105" (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (param 0))) (add (identifier "sz_105") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "typ" (param 0)))))
            (if (is-null (get-field "units" (param 0))) (add (identifier "sz_106") (size 1)) (add (add (identifier "sz_106") (apply (ext-identifier units sersize-of-row-binary) (force (get-field "units" (param 0))))) (size 1))))
          (add (identifier "sz_107")
            (add
              (let "n_ref_109" (make-vec (string-length (get-field "doc" (param 0))))
                (let "lebsz_ref_110" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_109")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_110")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_110") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_110")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_110")))))) 
              (size-of-u32 (string-length (get-field "doc" (param 0)))))))
        (if (is-null (get-field "aggr" (param 0))) (add (identifier "sz_111") (size 1))
          (add
            (add (identifier "sz_111")
              (add
                (let "n_ref_113" (make-vec (string-length (force (get-field "aggr" (param 0)))))
                  (let "lebsz_ref_114" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_113")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_114")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_114") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_114")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_114")))))) 
                (size-of-u32 (string-length (force (get-field "aggr" (param 0))))))) 
            (size 1)))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun111 { [&fun111](t p_0) {
    std::function<Size(dessser::gen::field_name::t)> id_112 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t id_113 { p_0.name };
    Size id_114 { id_112(id_113) };
    Size let_res_115;
    {
      Size sz_105 { id_114 };
      std::function<Size(dessser::gen::raql_type::t)> id_116 { dessser::gen::raql_type::sersize_of_row_binary };
      dessser::gen::raql_type::t id_117 { p_0.typ };
      Size id_118 { id_116(id_117) };
      Size id_119 { Size(sz_105 + id_118) };
      let_res_115 = id_119;
    }
    Size let_res_120;
    {
      Size sz_106 { let_res_115 };
      std::optional<dessser::gen::units::t> id_121 { p_0.units };
      bool id_122 { !(id_121.has_value ()) };
      Size choose_res_123;
      if (id_122) {
        Size id_124 { 1UL };
        Size id_125 { Size(sz_106 + id_124) };
        choose_res_123 = id_125;
      } else {
        std::function<Size(dessser::gen::units::t)> id_126 { dessser::gen::units::sersize_of_row_binary };
        std::optional<dessser::gen::units::t> id_127 { p_0.units };
        dessser::gen::units::t id_128 { id_127.value() };
        Size id_129 { id_126(id_128) };
        Size id_130 { Size(sz_106 + id_129) };
        Size id_131 { 1UL };
        Size id_132 { Size(id_130 + id_131) };
        choose_res_123 = id_132;
      }
      let_res_120 = choose_res_123;
    }
    Size let_res_133;
    {
      Size sz_107 { let_res_120 };
      std::string id_134 { p_0.doc };
      uint32_t id_135 { (uint32_t)id_134.size() };
      Vec<1, uint32_t> id_136 {  id_135  };
      Size let_res_137;
      {
        Vec<1, uint32_t> n_ref_109 { id_136 };
        uint32_t id_138 { 1U };
        Vec<1, uint32_t> id_139 {  id_138  };
        Size let_res_140;
        {
          Vec<1, uint32_t> lebsz_ref_110 { id_139 };
          bool while_flag_141 { true };
          do {
            uint8_t id_142 { 0 };
            uint32_t id_143 { n_ref_109[id_142] };
            uint8_t id_144 { 0 };
            uint32_t id_145 { lebsz_ref_110[id_144] };
            uint8_t id_146 { 7 };
            uint32_t id_147 { uint32_t(id_145 << id_146) };
            bool id_148 { bool(id_143 >= id_147) };
            while_flag_141 = id_148;
            if (while_flag_141) {
              uint8_t id_149 { 0 };
              uint8_t id_150 { 0 };
              uint32_t id_151 { lebsz_ref_110[id_150] };
              uint32_t id_152 { 1U };
              uint32_t id_153 { uint32_t(id_151 + id_152) };
              Void id_154 { ((void)(lebsz_ref_110[id_149] = id_153), VOID) };
            }
          } while (while_flag_141);
          uint8_t id_155 { 0 };
          uint32_t id_156 { lebsz_ref_110[id_155] };
          Size id_157 { Size(id_156) };
          let_res_140 = id_157;
        }
        let_res_137 = let_res_140;
      }
      std::string id_158 { p_0.doc };
      uint32_t id_159 { (uint32_t)id_158.size() };
      Size id_160 { Size(id_159) };
      Size id_161 { Size(let_res_137 + id_160) };
      Size id_162 { Size(sz_107 + id_161) };
      let_res_133 = id_162;
    }
    Size let_res_163;
    {
      Size sz_111 { let_res_133 };
      std::optional<std::string> id_164 { p_0.aggr };
      bool id_165 { !(id_164.has_value ()) };
      Size choose_res_166;
      if (id_165) {
        Size id_167 { 1UL };
        Size id_168 { Size(sz_111 + id_167) };
        choose_res_166 = id_168;
      } else {
        std::optional<std::string> id_169 { p_0.aggr };
        std::string id_170 { id_169.value() };
        uint32_t id_171 { (uint32_t)id_170.size() };
        Vec<1, uint32_t> id_172 {  id_171  };
        Size let_res_173;
        {
          Vec<1, uint32_t> n_ref_113 { id_172 };
          uint32_t id_174 { 1U };
          Vec<1, uint32_t> id_175 {  id_174  };
          Size let_res_176;
          {
            Vec<1, uint32_t> lebsz_ref_114 { id_175 };
            bool while_flag_177 { true };
            do {
              uint8_t id_178 { 0 };
              uint32_t id_179 { n_ref_113[id_178] };
              uint8_t id_180 { 0 };
              uint32_t id_181 { lebsz_ref_114[id_180] };
              uint8_t id_182 { 7 };
              uint32_t id_183 { uint32_t(id_181 << id_182) };
              bool id_184 { bool(id_179 >= id_183) };
              while_flag_177 = id_184;
              if (while_flag_177) {
                uint8_t id_185 { 0 };
                uint8_t id_186 { 0 };
                uint32_t id_187 { lebsz_ref_114[id_186] };
                uint32_t id_188 { 1U };
                uint32_t id_189 { uint32_t(id_187 + id_188) };
                Void id_190 { ((void)(lebsz_ref_114[id_185] = id_189), VOID) };
              }
            } while (while_flag_177);
            uint8_t id_191 { 0 };
            uint32_t id_192 { lebsz_ref_114[id_191] };
            Size id_193 { Size(id_192) };
            let_res_176 = id_193;
          }
          let_res_173 = let_res_176;
        }
        std::optional<std::string> id_194 { p_0.aggr };
        std::string id_195 { id_194.value() };
        uint32_t id_196 { (uint32_t)id_195.size() };
        Size id_197 { Size(id_196) };
        Size id_198 { Size(let_res_173 + id_197) };
        Size id_199 { Size(sz_111 + id_198) };
        Size id_200 { 1UL };
        Size id_201 { Size(id_199 + id_200) };
        choose_res_166 = id_201;
      }
      let_res_163 = choose_res_166;
    }
    return let_res_163;
  }
   };
  return fun111;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_59" (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_58"))
            (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
              (let "drec_65"
                (if (eq (peek-u8 (identifier "drec_snd_61") (size 0)) (u8 1)) 
                  (make-tup (null "$units") (ptr-add (identifier "drec_snd_61") (size 1)))
                  (let-pair "make1_1_fst_63" "make1_1_snd_64" (apply (ext-identifier units of-row-binary) (ptr-add (identifier "drec_snd_61") (size 1)))
                    (make-tup (not-null (identifier "make1_1_fst_63")) (identifier "make1_1_snd_64"))))
                (let-pair "drec_fst_66" "drec_snd_67" (identifier "drec_65")
                  (let "drec_80"
                    (let "dstring1_74"
                      (let "leb_ref_68" (make-vec (u32 0))
                        (let "shft_ref_69" (make-vec (u8 0))
                          (let "p_ref_70" (make-vec (identifier "drec_snd_67"))
                            (seq
                              (while
                                (let "leb128_71" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_70")))
                                  (let-pair "leb128_fst_72" "leb128_snd_73" 
                                    (identifier "leb128_71")
                                    (seq (set-vec (u8 0) (identifier "p_ref_70") (identifier "leb128_snd_73"))
                                      (set-vec (u8 0) (identifier "leb_ref_68")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_72") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_69"))) (unsafe-nth (u8 0) (identifier "leb_ref_68"))))
                                      (set-vec (u8 0) (identifier "shft_ref_69") (add (unsafe-nth (u8 0) (identifier "shft_ref_69")) (u8 7))) 
                                      (ge (identifier "leb128_fst_72") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_68"))) (unsafe-nth (u8 0) (identifier "p_ref_70")))))))
                      (let-pair "dstring1_fst_75" "dstring1_snd_76" (identifier "dstring1_74")
                        (let-pair "dstring2_fst_78" "dstring2_snd_79" 
                          (read-bytes (identifier "dstring1_snd_76") (identifier "dstring1_fst_75")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_78")) (identifier "dstring2_snd_79")))))
                    (let-pair "drec_fst_81" "drec_snd_82" (identifier "drec_80")
                      (let-pair "drec_fst_99" "drec_snd_100"
                        (if (eq (peek-u8 (identifier "drec_snd_82") (size 0)) (u8 1)) 
                          (make-tup (null "STRING") (ptr-add (identifier "drec_snd_82") (size 1)))
                          (let "dstring1_89"
                            (let "leb_ref_83" (make-vec (u32 0))
                              (let "shft_ref_84" (make-vec (u8 0))
                                (let "p_ref_85" (make-vec (ptr-add (identifier "drec_snd_82") (size 1)))
                                  (seq
                                    (while
                                      (let "leb128_86" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_85")))
                                        (let-pair "leb128_fst_87" "leb128_snd_88" 
                                          (identifier "leb128_86")
                                          (seq (set-vec (u8 0) (identifier "p_ref_85") (identifier "leb128_snd_88"))
                                            (set-vec (u8 0) (identifier "leb_ref_83")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_87") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_84"))) (unsafe-nth (u8 0) (identifier "leb_ref_83"))))
                                            (set-vec (u8 0) (identifier "shft_ref_84") (add (unsafe-nth (u8 0) (identifier "shft_ref_84")) (u8 7))) 
                                            (ge (identifier "leb128_fst_87") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_83"))) (unsafe-nth (u8 0) (identifier "p_ref_85")))))))
                            (let-pair "dstring1_fst_90" "dstring1_snd_91" 
                              (identifier "dstring1_89")
                              (let-pair "dstring2_fst_93" "dstring2_snd_94" 
                                (read-bytes (identifier "dstring1_snd_91") (identifier "dstring1_fst_90")) 
                                (make-tup (not-null (string-of-bytes (identifier "dstring2_fst_93"))) (identifier "dstring2_snd_94"))))))
                        (make-tup
                          (make-rec (string "name") (identifier "drec_fst_57") 
                            (string "typ") (identifier "drec_fst_60") 
                            (string "units") (identifier "drec_fst_66") 
                            (string "doc") (identifier "drec_fst_81") 
                            (string "aggr") (identifier "drec_fst_99")) 
                          (identifier "drec_snd_100"))))))))))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun202 { [&fun202](Pointer p_0) {
    std::function<c50aa083fa818c6eeca389b0025dda98(Pointer)> id_203 { dessser::gen::field_name::of_row_binary };
    c50aa083fa818c6eeca389b0025dda98 id_204 { id_203(p_0) };
    f63f919559f0d70225bd0da5dd9bcafc let_res_205;
    {
      c50aa083fa818c6eeca389b0025dda98 drec_56 { id_204 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_206;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        std::function<v_1afe9f73328d6d7bdf808b1d2eb2af22(Pointer)> id_207 { dessser::gen::raql_type::of_row_binary };
        v_1afe9f73328d6d7bdf808b1d2eb2af22 id_208 { id_207(drec_snd_58) };
        f63f919559f0d70225bd0da5dd9bcafc let_res_209;
        {
          v_1afe9f73328d6d7bdf808b1d2eb2af22 drec_59 { id_208 };
          f63f919559f0d70225bd0da5dd9bcafc letpair_res_210;
          {
            auto drec_fst_60 { std::get<0>(drec_59) };
            auto drec_snd_61 { std::get<1>(drec_59) };
            Size id_211 { 0UL };
            uint8_t id_212 { drec_snd_61.peekU8(id_211) };
            uint8_t id_213 { 1 };
            bool id_214 { bool(id_212 == id_213) };
            bf974315651fdd731eda317cf9d211f4 choose_res_215;
            if (id_214) {
              std::optional<dessser::gen::units::t> id_216 { std::nullopt };
              Size id_217 { 1UL };
              Pointer id_218 { drec_snd_61.skip(id_217) };
              bf974315651fdd731eda317cf9d211f4 id_219 {  id_216, id_218  };
              choose_res_215 = id_219;
            } else {
              std::function<v_765fc2dfa0d4b4acfe348a1dcf7356d2(Pointer)> id_220 { dessser::gen::units::of_row_binary };
              Size id_221 { 1UL };
              Pointer id_222 { drec_snd_61.skip(id_221) };
              v_765fc2dfa0d4b4acfe348a1dcf7356d2 id_223 { id_220(id_222) };
              bf974315651fdd731eda317cf9d211f4 letpair_res_224;
              {
                auto make1_1_fst_63 { std::get<0>(id_223) };
                auto make1_1_snd_64 { std::get<1>(id_223) };
                std::optional<dessser::gen::units::t> id_225 { make1_1_fst_63 };
                bf974315651fdd731eda317cf9d211f4 id_226 {  id_225, make1_1_snd_64  };
                letpair_res_224 = id_226;
              }
              choose_res_215 = letpair_res_224;
            }
            f63f919559f0d70225bd0da5dd9bcafc let_res_227;
            {
              bf974315651fdd731eda317cf9d211f4 drec_65 { choose_res_215 };
              f63f919559f0d70225bd0da5dd9bcafc letpair_res_228;
              {
                auto drec_fst_66 { std::get<0>(drec_65) };
                auto drec_snd_67 { std::get<1>(drec_65) };
                uint32_t id_229 { 0U };
                Vec<1, uint32_t> id_230 {  id_229  };
                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_231;
                {
                  Vec<1, uint32_t> leb_ref_68 { id_230 };
                  uint8_t id_232 { 0 };
                  Vec<1, uint8_t> id_233 {  id_232  };
                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_234;
                  {
                    Vec<1, uint8_t> shft_ref_69 { id_233 };
                    Vec<1, Pointer> id_235 {  drec_snd_67  };
                    v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_236;
                    {
                      Vec<1, Pointer> p_ref_70 { id_235 };
                      bool while_flag_237 { true };
                      do {
                        uint8_t id_238 { 0 };
                        Pointer id_239 { p_ref_70[id_238] };
                        v_1d5843897434feb24d158f3793db9189 id_240 { id_239.readU8() };
                        bool let_res_241;
                        {
                          v_1d5843897434feb24d158f3793db9189 leb128_71 { id_240 };
                          bool letpair_res_242;
                          {
                            auto leb128_fst_72 { std::get<0>(leb128_71) };
                            auto leb128_snd_73 { std::get<1>(leb128_71) };
                            uint8_t id_243 { 0 };
                            Void id_244 { ((void)(p_ref_70[id_243] = leb128_snd_73), VOID) };
                            uint8_t id_245 { 0 };
                            uint8_t id_246 { 127 };
                            uint8_t id_247 { uint8_t(leb128_fst_72 & id_246) };
                            uint32_t id_248 { uint32_t(id_247) };
                            uint8_t id_249 { 0 };
                            uint8_t id_250 { shft_ref_69[id_249] };
                            uint32_t id_251 { uint32_t(id_248 << id_250) };
                            uint8_t id_252 { 0 };
                            uint32_t id_253 { leb_ref_68[id_252] };
                            uint32_t id_254 { uint32_t(id_251 | id_253) };
                            Void id_255 { ((void)(leb_ref_68[id_245] = id_254), VOID) };
                            uint8_t id_256 { 0 };
                            uint8_t id_257 { 0 };
                            uint8_t id_258 { shft_ref_69[id_257] };
                            uint8_t id_259 { 7 };
                            uint8_t id_260 { uint8_t(id_258 + id_259) };
                            Void id_261 { ((void)(shft_ref_69[id_256] = id_260), VOID) };
                            uint8_t id_262 { 128 };
                            bool id_263 { bool(leb128_fst_72 >= id_262) };
                            letpair_res_242 = id_263;
                          }
                          let_res_241 = letpair_res_242;
                        }
                        while_flag_237 = let_res_241;
                        if (while_flag_237) {
                        }
                      } while (while_flag_237);
                      uint8_t id_264 { 0 };
                      uint32_t id_265 { leb_ref_68[id_264] };
                      Size id_266 { Size(id_265) };
                      uint8_t id_267 { 0 };
                      Pointer id_268 { p_ref_70[id_267] };
                      v_41b0681ed7f1f185fd3e6c4dcdc13110 id_269 {  id_266, id_268  };
                      let_res_236 = id_269;
                    }
                    let_res_234 = let_res_236;
                  }
                  let_res_231 = let_res_234;
                }
                v_46a5e81c2410b000ff0adea6dc198147 let_res_270;
                {
                  v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_74 { let_res_231 };
                  v_46a5e81c2410b000ff0adea6dc198147 letpair_res_271;
                  {
                    auto dstring1_fst_75 { std::get<0>(dstring1_74) };
                    auto dstring1_snd_76 { std::get<1>(dstring1_74) };
                    f921d1e0a170c3c04148c21704db9c45 id_272 { dstring1_snd_76.readBytes(dstring1_fst_75) };
                    v_46a5e81c2410b000ff0adea6dc198147 letpair_res_273;
                    {
                      auto dstring2_fst_78 { std::get<0>(id_272) };
                      auto dstring2_snd_79 { std::get<1>(id_272) };
                      std::string id_274 { dstring2_fst_78.toString() };
                      v_46a5e81c2410b000ff0adea6dc198147 id_275 {  id_274, dstring2_snd_79  };
                      letpair_res_273 = id_275;
                    }
                    letpair_res_271 = letpair_res_273;
                  }
                  let_res_270 = letpair_res_271;
                }
                f63f919559f0d70225bd0da5dd9bcafc let_res_276;
                {
                  v_46a5e81c2410b000ff0adea6dc198147 drec_80 { let_res_270 };
                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_277;
                  {
                    auto drec_fst_81 { std::get<0>(drec_80) };
                    auto drec_snd_82 { std::get<1>(drec_80) };
                    Size id_278 { 0UL };
                    uint8_t id_279 { drec_snd_82.peekU8(id_278) };
                    uint8_t id_280 { 1 };
                    bool id_281 { bool(id_279 == id_280) };
                    fe18be5220bdca71492df7686dadc3c2 choose_res_282;
                    if (id_281) {
                      std::optional<std::string> id_283 { std::nullopt };
                      Size id_284 { 1UL };
                      Pointer id_285 { drec_snd_82.skip(id_284) };
                      fe18be5220bdca71492df7686dadc3c2 id_286 {  id_283, id_285  };
                      choose_res_282 = id_286;
                    } else {
                      uint32_t id_287 { 0U };
                      Vec<1, uint32_t> id_288 {  id_287  };
                      v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_289;
                      {
                        Vec<1, uint32_t> leb_ref_83 { id_288 };
                        uint8_t id_290 { 0 };
                        Vec<1, uint8_t> id_291 {  id_290  };
                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_292;
                        {
                          Vec<1, uint8_t> shft_ref_84 { id_291 };
                          Size id_293 { 1UL };
                          Pointer id_294 { drec_snd_82.skip(id_293) };
                          Vec<1, Pointer> id_295 {  id_294  };
                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_296;
                          {
                            Vec<1, Pointer> p_ref_85 { id_295 };
                            bool while_flag_297 { true };
                            do {
                              uint8_t id_298 { 0 };
                              Pointer id_299 { p_ref_85[id_298] };
                              v_1d5843897434feb24d158f3793db9189 id_300 { id_299.readU8() };
                              bool let_res_301;
                              {
                                v_1d5843897434feb24d158f3793db9189 leb128_86 { id_300 };
                                bool letpair_res_302;
                                {
                                  auto leb128_fst_87 { std::get<0>(leb128_86) };
                                  auto leb128_snd_88 { std::get<1>(leb128_86) };
                                  uint8_t id_303 { 0 };
                                  Void id_304 { ((void)(p_ref_85[id_303] = leb128_snd_88), VOID) };
                                  uint8_t id_305 { 0 };
                                  uint8_t id_306 { 127 };
                                  uint8_t id_307 { uint8_t(leb128_fst_87 & id_306) };
                                  uint32_t id_308 { uint32_t(id_307) };
                                  uint8_t id_309 { 0 };
                                  uint8_t id_310 { shft_ref_84[id_309] };
                                  uint32_t id_311 { uint32_t(id_308 << id_310) };
                                  uint8_t id_312 { 0 };
                                  uint32_t id_313 { leb_ref_83[id_312] };
                                  uint32_t id_314 { uint32_t(id_311 | id_313) };
                                  Void id_315 { ((void)(leb_ref_83[id_305] = id_314), VOID) };
                                  uint8_t id_316 { 0 };
                                  uint8_t id_317 { 0 };
                                  uint8_t id_318 { shft_ref_84[id_317] };
                                  uint8_t id_319 { 7 };
                                  uint8_t id_320 { uint8_t(id_318 + id_319) };
                                  Void id_321 { ((void)(shft_ref_84[id_316] = id_320), VOID) };
                                  uint8_t id_322 { 128 };
                                  bool id_323 { bool(leb128_fst_87 >= id_322) };
                                  letpair_res_302 = id_323;
                                }
                                let_res_301 = letpair_res_302;
                              }
                              while_flag_297 = let_res_301;
                              if (while_flag_297) {
                              }
                            } while (while_flag_297);
                            uint8_t id_324 { 0 };
                            uint32_t id_325 { leb_ref_83[id_324] };
                            Size id_326 { Size(id_325) };
                            uint8_t id_327 { 0 };
                            Pointer id_328 { p_ref_85[id_327] };
                            v_41b0681ed7f1f185fd3e6c4dcdc13110 id_329 {  id_326, id_328  };
                            let_res_296 = id_329;
                          }
                          let_res_292 = let_res_296;
                        }
                        let_res_289 = let_res_292;
                      }
                      fe18be5220bdca71492df7686dadc3c2 let_res_330;
                      {
                        v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_89 { let_res_289 };
                        fe18be5220bdca71492df7686dadc3c2 letpair_res_331;
                        {
                          auto dstring1_fst_90 { std::get<0>(dstring1_89) };
                          auto dstring1_snd_91 { std::get<1>(dstring1_89) };
                          f921d1e0a170c3c04148c21704db9c45 id_332 { dstring1_snd_91.readBytes(dstring1_fst_90) };
                          fe18be5220bdca71492df7686dadc3c2 letpair_res_333;
                          {
                            auto dstring2_fst_93 { std::get<0>(id_332) };
                            auto dstring2_snd_94 { std::get<1>(id_332) };
                            std::string id_334 { dstring2_fst_93.toString() };
                            std::optional<std::string> id_335 { id_334 };
                            fe18be5220bdca71492df7686dadc3c2 id_336 {  id_335, dstring2_snd_94  };
                            letpair_res_333 = id_336;
                          }
                          letpair_res_331 = letpair_res_333;
                        }
                        let_res_330 = letpair_res_331;
                      }
                      choose_res_282 = let_res_330;
                    }
                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_337;
                    {
                      auto drec_fst_99 { std::get<0>(choose_res_282) };
                      auto drec_snd_100 { std::get<1>(choose_res_282) };
                      t id_338 {  .name = drec_fst_57, .typ = drec_fst_60, .units = drec_fst_66, .doc = drec_fst_81, .aggr = drec_fst_99  };
                      f63f919559f0d70225bd0da5dd9bcafc id_339 {  id_338, drec_snd_100  };
                      letpair_res_337 = id_339;
                    }
                    letpair_res_277 = letpair_res_337;
                  }
                  let_res_276 = letpair_res_277;
                }
                letpair_res_228 = let_res_276;
              }
              let_res_227 = letpair_res_228;
            }
            letpair_res_210 = let_res_227;
          }
          let_res_209 = letpair_res_210;
        }
        letpair_res_206 = let_res_209;
      }
      let_res_205 = letpair_res_206;
    }
    return let_res_205;
  }
   };
  return fun202;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
