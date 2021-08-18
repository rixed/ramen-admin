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
typedef std::tuple<
  double,
  bool
> tea0eebdc0b2e9b51f69e77168901ab2f;

typedef std::tuple<
  std::string,
  tea0eebdc0b2e9b51f69e77168901ab2f
> t3a9ea1f12a4e632b6e111d6d47b80632;

typedef Arr<t3a9ea1f12a4e632b6e111d6d47b80632> t;
typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  Lst<t3a9ea1f12a4e632b6e111d6d47b80632>,
  Pointer
> t8b191373a530a22f6a1b92183fc54a25;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  std::string,
  Pointer
> tef94b55d8809251f13165d9a05bd9d0e;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

typedef std::tuple<
  double,
  Pointer
> taebed00ad7fdb3f7ced11d3cfd58aade;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("(STRING; (FLOAT; BOOL))[]" "Ptr")
      (let "dst_ref_125"
        (make-vec
          (let "leb128_sz_123" (make-vec (cardinality (param 0)))
            (let "leb128_ptr_124" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_124")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_124"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_123"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_123"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_123"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_123") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_123")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_123")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_124"))))))
        (let "n_ref_126" (make-vec (i32 0))
          (seq
            (for-each "x_127" (param 0)
              (seq
                (set-vec (u8 0) (identifier "dst_ref_125")
                  (let "stup_dst_131"
                    (let "stup_dst_128" (unsafe-nth (u8 0) (identifier "dst_ref_125"))
                      (write-bytes
                        (let "leb128_sz_129" (make-vec (string-length (get-item 0 (identifier "x_127"))))
                          (let "leb128_ptr_130" (make-vec (identifier "stup_dst_128"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_130")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_130"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_129"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_129"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_129"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_129") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_129")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_129")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_130"))))) 
                        (bytes-of-string (get-item 0 (identifier "x_127")))))
                    (let "stup_dst_132" (write-u64 little-endian (identifier "stup_dst_131") (u64-of-float (get-item 0 (get-item 1 (identifier "x_127")))))
                      (write-u8 (identifier "stup_dst_132") (u8-of-bool (get-item 1 (get-item 1 (identifier "x_127")))))))) 
                (set-vec (u8 0) (identifier "n_ref_126") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_126")))))) 
            (unsafe-nth (u8 0) (identifier "dst_ref_125"))))))
 */
static std::function<Pointer(t&,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t&,Pointer)> fun0 { [&fun0](t& p_0, Pointer p_1) {
    uint32_t id_1 { p_0.size() };
    Vec<1, uint32_t> id_2 {  id_1  };
    Pointer let_res_3;
    {
      Vec<1, uint32_t> leb128_sz_123 { id_2 };
      Vec<1, Pointer> id_4 {  p_1  };
      Pointer let_res_5;
      {
        Vec<1, Pointer> leb128_ptr_124 { id_4 };
        bool while_flag_6 { true };
        do {
          uint8_t id_7 { 0 };
          uint8_t id_8 { 0 };
          Pointer id_9 { leb128_ptr_124[id_8] };
          uint32_t id_10 { 128U };
          uint8_t id_11 { 0 };
          uint32_t id_12 { leb128_sz_123[id_11] };
          bool id_13 { bool(id_10 > id_12) };
          uint8_t choose_res_14;
          if (id_13) {
            uint8_t id_15 { 0 };
            uint32_t id_16 { leb128_sz_123[id_15] };
            uint8_t id_17 { uint8_t(id_16) };
            choose_res_14 = id_17;
          } else {
            uint8_t id_18 { 0 };
            uint32_t id_19 { leb128_sz_123[id_18] };
            uint8_t id_20 { uint8_t(id_19) };
            uint8_t id_21 { 128 };
            uint8_t id_22 { uint8_t(id_20 | id_21) };
            choose_res_14 = id_22;
          }
          Pointer id_23 { id_9.writeU8(choose_res_14) };
          Void id_24 { ((void)(leb128_ptr_124[id_7] = id_23), VOID) };
          (void)id_24;
          uint8_t id_25 { 0 };
          uint8_t id_26 { 0 };
          uint32_t id_27 { leb128_sz_123[id_26] };
          uint8_t id_28 { 7 };
          uint32_t id_29 { uint32_t(id_27 >> id_28) };
          Void id_30 { ((void)(leb128_sz_123[id_25] = id_29), VOID) };
          (void)id_30;
          uint8_t id_31 { 0 };
          uint32_t id_32 { leb128_sz_123[id_31] };
          uint32_t id_33 { 0U };
          bool id_34 { bool(id_32 > id_33) };
          while_flag_6 = id_34;
          if (while_flag_6) {
            (void)VOID;
          }
        } while (while_flag_6);
        (void)VOID;
        uint8_t id_35 { 0 };
        Pointer id_36 { leb128_ptr_124[id_35] };
        let_res_5 = id_36;
      }
      let_res_3 = let_res_5;
    }
    Vec<1, Pointer> id_37 {  let_res_3  };
    Pointer let_res_38;
    {
      Vec<1, Pointer> dst_ref_125 { id_37 };
      int32_t id_39 { 0L };
      Vec<1, int32_t> id_40 {  id_39  };
      Pointer let_res_41;
      {
        Vec<1, int32_t> n_ref_126 { id_40 };
        for (t3a9ea1f12a4e632b6e111d6d47b80632 x_127 : p_0) {
          uint8_t id_42 { 0 };
          uint8_t id_43 { 0 };
          Pointer id_44 { dst_ref_125[id_43] };
          Pointer let_res_45;
          {
            Pointer stup_dst_128 { id_44 };
            std::string id_46 { std::get<0>(x_127) };
            uint32_t id_47 { (uint32_t)id_46.size() };
            Vec<1, uint32_t> id_48 {  id_47  };
            Pointer let_res_49;
            {
              Vec<1, uint32_t> leb128_sz_129 { id_48 };
              Vec<1, Pointer> id_50 {  stup_dst_128  };
              Pointer let_res_51;
              {
                Vec<1, Pointer> leb128_ptr_130 { id_50 };
                bool while_flag_52 { true };
                do {
                  uint8_t id_53 { 0 };
                  uint8_t id_54 { 0 };
                  Pointer id_55 { leb128_ptr_130[id_54] };
                  uint32_t id_56 { 128U };
                  uint8_t id_57 { 0 };
                  uint32_t id_58 { leb128_sz_129[id_57] };
                  bool id_59 { bool(id_56 > id_58) };
                  uint8_t choose_res_60;
                  if (id_59) {
                    uint8_t id_61 { 0 };
                    uint32_t id_62 { leb128_sz_129[id_61] };
                    uint8_t id_63 { uint8_t(id_62) };
                    choose_res_60 = id_63;
                  } else {
                    uint8_t id_64 { 0 };
                    uint32_t id_65 { leb128_sz_129[id_64] };
                    uint8_t id_66 { uint8_t(id_65) };
                    uint8_t id_67 { 128 };
                    uint8_t id_68 { uint8_t(id_66 | id_67) };
                    choose_res_60 = id_68;
                  }
                  Pointer id_69 { id_55.writeU8(choose_res_60) };
                  Void id_70 { ((void)(leb128_ptr_130[id_53] = id_69), VOID) };
                  (void)id_70;
                  uint8_t id_71 { 0 };
                  uint8_t id_72 { 0 };
                  uint32_t id_73 { leb128_sz_129[id_72] };
                  uint8_t id_74 { 7 };
                  uint32_t id_75 { uint32_t(id_73 >> id_74) };
                  Void id_76 { ((void)(leb128_sz_129[id_71] = id_75), VOID) };
                  (void)id_76;
                  uint8_t id_77 { 0 };
                  uint32_t id_78 { leb128_sz_129[id_77] };
                  uint32_t id_79 { 0U };
                  bool id_80 { bool(id_78 > id_79) };
                  while_flag_52 = id_80;
                  if (while_flag_52) {
                    (void)VOID;
                  }
                } while (while_flag_52);
                (void)VOID;
                uint8_t id_81 { 0 };
                Pointer id_82 { leb128_ptr_130[id_81] };
                let_res_51 = id_82;
              }
              let_res_49 = let_res_51;
            }
            std::string id_83 { std::get<0>(x_127) };
            Bytes id_84 { id_83 };
            Pointer id_85 { let_res_49.writeBytes(id_84) };
            let_res_45 = id_85;
          }
          Pointer let_res_86;
          {
            Pointer stup_dst_131 { let_res_45 };
            tea0eebdc0b2e9b51f69e77168901ab2f id_87 { std::get<1>(x_127) };
            double id_88 { std::get<0>(id_87) };
            uint64_t id_89 { qword_of_float(id_88) };
            Pointer id_90 { stup_dst_131.writeU64Le(id_89) };
            Pointer let_res_91;
            {
              Pointer stup_dst_132 { id_90 };
              tea0eebdc0b2e9b51f69e77168901ab2f id_92 { std::get<1>(x_127) };
              bool id_93 { std::get<1>(id_92) };
              uint8_t id_94 { uint8_t(id_93) };
              Pointer id_95 { stup_dst_132.writeU8(id_94) };
              let_res_91 = id_95;
            }
            let_res_86 = let_res_91;
          }
          Void id_96 { ((void)(dst_ref_125[id_42] = let_res_86), VOID) };
          (void)id_96;
          uint8_t id_97 { 0 };
          int32_t id_98 { 1L };
          uint8_t id_99 { 0 };
          int32_t id_100 { n_ref_126[id_99] };
          int32_t id_101 { int32_t(id_98 + id_100) };
          Void id_102 { ((void)(n_ref_126[id_97] = id_101), VOID) };
          (void)id_102;
          (void)id_102;
        }
        (void)VOID;
        uint8_t id_103 { 0 };
        Pointer id_104 { dst_ref_125[id_103] };
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
      (let "sz_ref_114"
        (make-vec
          (let "n_ref_112" (make-vec (cardinality (param 0)))
            (let "lebsz_ref_113" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_112")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_113")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_113") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_113")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_113")))))))
        (seq
          (let "repeat_n_115" (make-vec (i32 0))
            (while (gt (to-i32 (cardinality (param 0))) (unsafe-nth (u8 0) (identifier "repeat_n_115")))
              (seq
                (set-vec (u8 0) (identifier "sz_ref_114")
                  (add
                    (add
                      (let "sz_116" (unsafe-nth (u8 0) (identifier "sz_ref_114"))
                        (add (identifier "sz_116")
                          (let "wlen_117" (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_115")) (param 0))))
                            (add
                              (let "n_ref_118" (make-vec (identifier "wlen_117"))
                                (let "lebsz_ref_119" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_118")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_119")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_119") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_119")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_119")))))) 
                              (size-of-u32 (identifier "wlen_117")))))) 
                      (size 8)) (size 1))) (set-vec (u8 0) (identifier "repeat_n_115") (add (unsafe-nth (u8 0) (identifier "repeat_n_115")) (i32 1)))))) 
          (unsafe-nth (u8 0) (identifier "sz_ref_114")))))
 */
static std::function<Size(t&)> sersize_of_row_binary_init()
{
  std::function<Size(t&)> fun105 { [&fun105](t& p_0) {
    uint32_t id_106 { p_0.size() };
    Vec<1, uint32_t> id_107 {  id_106  };
    Size let_res_108;
    {
      Vec<1, uint32_t> n_ref_112 { id_107 };
      uint32_t id_109 { 1U };
      Vec<1, uint32_t> id_110 {  id_109  };
      Size let_res_111;
      {
        Vec<1, uint32_t> lebsz_ref_113 { id_110 };
        bool while_flag_112 { true };
        do {
          uint8_t id_113 { 0 };
          uint32_t id_114 { n_ref_112[id_113] };
          uint8_t id_115 { 0 };
          uint32_t id_116 { lebsz_ref_113[id_115] };
          uint8_t id_117 { 7 };
          uint32_t id_118 { uint32_t(id_116 << id_117) };
          bool id_119 { bool(id_114 >= id_118) };
          while_flag_112 = id_119;
          if (while_flag_112) {
            uint8_t id_120 { 0 };
            uint8_t id_121 { 0 };
            uint32_t id_122 { lebsz_ref_113[id_121] };
            uint32_t id_123 { 1U };
            uint32_t id_124 { uint32_t(id_122 + id_123) };
            Void id_125 { ((void)(lebsz_ref_113[id_120] = id_124), VOID) };
            (void)id_125;
          }
        } while (while_flag_112);
        (void)VOID;
        uint8_t id_126 { 0 };
        uint32_t id_127 { lebsz_ref_113[id_126] };
        Size id_128 { Size(id_127) };
        let_res_111 = id_128;
      }
      let_res_108 = let_res_111;
    }
    Vec<1, Size> id_129 {  let_res_108  };
    Size let_res_130;
    {
      Vec<1, Size> sz_ref_114 { id_129 };
      int32_t id_131 { 0L };
      Vec<1, int32_t> id_132 {  id_131  };
      {
        Vec<1, int32_t> repeat_n_115 { id_132 };
        bool while_flag_133 { true };
        do {
          uint32_t id_134 { p_0.size() };
          int32_t id_135 { int32_t(id_134) };
          uint8_t id_136 { 0 };
          int32_t id_137 { repeat_n_115[id_136] };
          bool id_138 { bool(id_135 > id_137) };
          while_flag_133 = id_138;
          if (while_flag_133) {
            uint8_t id_139 { 0 };
            uint8_t id_140 { 0 };
            Size id_141 { sz_ref_114[id_140] };
            Size let_res_142;
            {
              Size sz_116 { id_141 };
              uint8_t id_143 { 0 };
              int32_t id_144 { repeat_n_115[id_143] };
              t3a9ea1f12a4e632b6e111d6d47b80632 id_145 { p_0[id_144] };
              std::string id_146 { std::get<0>(id_145) };
              uint32_t id_147 { (uint32_t)id_146.size() };
              Size let_res_148;
              {
                uint32_t wlen_117 { id_147 };
                Vec<1, uint32_t> id_149 {  wlen_117  };
                Size let_res_150;
                {
                  Vec<1, uint32_t> n_ref_118 { id_149 };
                  uint32_t id_151 { 1U };
                  Vec<1, uint32_t> id_152 {  id_151  };
                  Size let_res_153;
                  {
                    Vec<1, uint32_t> lebsz_ref_119 { id_152 };
                    bool while_flag_154 { true };
                    do {
                      uint8_t id_155 { 0 };
                      uint32_t id_156 { n_ref_118[id_155] };
                      uint8_t id_157 { 0 };
                      uint32_t id_158 { lebsz_ref_119[id_157] };
                      uint8_t id_159 { 7 };
                      uint32_t id_160 { uint32_t(id_158 << id_159) };
                      bool id_161 { bool(id_156 >= id_160) };
                      while_flag_154 = id_161;
                      if (while_flag_154) {
                        uint8_t id_162 { 0 };
                        uint8_t id_163 { 0 };
                        uint32_t id_164 { lebsz_ref_119[id_163] };
                        uint32_t id_165 { 1U };
                        uint32_t id_166 { uint32_t(id_164 + id_165) };
                        Void id_167 { ((void)(lebsz_ref_119[id_162] = id_166), VOID) };
                        (void)id_167;
                      }
                    } while (while_flag_154);
                    (void)VOID;
                    uint8_t id_168 { 0 };
                    uint32_t id_169 { lebsz_ref_119[id_168] };
                    Size id_170 { Size(id_169) };
                    let_res_153 = id_170;
                  }
                  let_res_150 = let_res_153;
                }
                Size id_171 { Size(wlen_117) };
                Size id_172 { Size(let_res_150 + id_171) };
                let_res_148 = id_172;
              }
              Size id_173 { Size(sz_116 + let_res_148) };
              let_res_142 = id_173;
            }
            Size id_174 { 8UL };
            Size id_175 { Size(let_res_142 + id_174) };
            Size id_176 { 1UL };
            Size id_177 { Size(id_175 + id_176) };
            Void id_178 { ((void)(sz_ref_114[id_139] = id_177), VOID) };
            (void)id_178;
            uint8_t id_179 { 0 };
            uint8_t id_180 { 0 };
            int32_t id_181 { repeat_n_115[id_180] };
            int32_t id_182 { 1L };
            int32_t id_183 { int32_t(id_181 + id_182) };
            Void id_184 { ((void)(repeat_n_115[id_179] = id_183), VOID) };
            (void)id_184;
            (void)id_184;
          }
        } while (while_flag_133);
        (void)VOID;
      }
      (void)VOID;
      uint8_t id_185 { 0 };
      Size id_186 { sz_ref_114[id_185] };
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
      (let-pair "dlist4_fst_107" "dlist4_snd_108"
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
            (let "inits_src_ref_68" (make-vec (make-tup (end-of-list "(STRING; (FLOAT; BOOL))") (identifier "dlist1_snd_67")))
              (seq
                (let "repeat_n_69" (make-vec (i32 0))
                  (while (gt (to-i32 (identifier "dlist1_fst_66")) (unsafe-nth (u8 0) (identifier "repeat_n_69")))
                    (seq
                      (let "dlist2_70" (unsafe-nth (u8 0) (identifier "inits_src_ref_68"))
                        (let-pair "dlist2_fst_71" "dlist2_snd_72" (identifier "dlist2_70")
                          (set-vec (u8 0) (identifier "inits_src_ref_68")
                            (let "dtup_85"
                              (let "dstring1_79"
                                (let "leb_ref_73" (make-vec (u32 0))
                                  (let "shft_ref_74" (make-vec (u8 0))
                                    (let "p_ref_75" (make-vec (identifier "dlist2_snd_72"))
                                      (seq
                                        (while
                                          (let "leb128_76" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_75")))
                                            (let-pair "leb128_fst_77" "leb128_snd_78" 
                                              (identifier "leb128_76")
                                              (seq (set-vec (u8 0) (identifier "p_ref_75") (identifier "leb128_snd_78"))
                                                (set-vec (u8 0) (identifier "leb_ref_73")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_77") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_74"))) (unsafe-nth (u8 0) (identifier "leb_ref_73"))))
                                                (set-vec (u8 0) (identifier "shft_ref_74") (add (unsafe-nth (u8 0) (identifier "shft_ref_74")) (u8 7))) 
                                                (ge (identifier "leb128_fst_77") (u8 128))))) 
                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_73"))) (unsafe-nth (u8 0) (identifier "p_ref_75")))))))
                                (let-pair "dstring1_fst_80" "dstring1_snd_81" 
                                  (identifier "dstring1_79")
                                  (let-pair "dstring2_fst_83" "dstring2_snd_84" 
                                    (read-bytes (identifier "dstring1_snd_81") (identifier "dstring1_fst_80")) 
                                    (make-tup (string-of-bytes (identifier "dstring2_fst_83")) (identifier "dstring2_snd_84")))))
                              (let-pair "dtup_fst_86" "dtup_snd_87" (identifier "dtup_85")
                                (let "dtup_91" (let-pair "dfloat_fst_89" "dfloat_snd_90" (read-u64 little-endian (identifier "dtup_snd_87")) (make-tup (float-of-u64 (identifier "dfloat_fst_89")) (identifier "dfloat_snd_90")))
                                  (let-pair "dtup_fst_92" "dtup_snd_93" 
                                    (identifier "dtup_91")
                                    (let-pair "dbool_fst_95" "dbool_snd_96" 
                                      (read-u8 (identifier "dtup_snd_93"))
                                      (make-tup (cons (make-tup (identifier "dtup_fst_86") (make-tup (identifier "dtup_fst_92") (not (eq (identifier "dbool_fst_95") (u8 0))))) (identifier "dlist2_fst_71"))
                                        (identifier "dbool_snd_96")))))))))) 
                      (set-vec (u8 0) (identifier "repeat_n_69") (add (unsafe-nth (u8 0) (identifier "repeat_n_69")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "inits_src_ref_68")))))) 
        (make-tup (arr-of-lst-rev (identifier "dlist4_fst_107")) (identifier "dlist4_snd_108"))))
 */
static std::function<t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary_init()
{
  std::function<t519c57b31160411c6989716f3a9782e0(Pointer)> fun187 { [&fun187](Pointer p_0) {
    uint32_t id_188 { 0U };
    Vec<1, uint32_t> id_189 {  id_188  };
    t405eb186408556fed8f2c41523c07d13 let_res_190;
    {
      Vec<1, uint32_t> leb_ref_56 { id_189 };
      uint8_t id_191 { 0 };
      Vec<1, uint8_t> id_192 {  id_191  };
      t405eb186408556fed8f2c41523c07d13 let_res_193;
      {
        Vec<1, uint8_t> shft_ref_57 { id_192 };
        Vec<1, Pointer> id_194 {  p_0  };
        t405eb186408556fed8f2c41523c07d13 let_res_195;
        {
          Vec<1, Pointer> p_ref_58 { id_194 };
          bool while_flag_196 { true };
          do {
            uint8_t id_197 { 0 };
            Pointer id_198 { p_ref_58[id_197] };
            tb3f98ea670610d40658a618de3ec7b90 id_199 { id_198.readU8() };
            bool let_res_200;
            {
              tb3f98ea670610d40658a618de3ec7b90 leb128_59 { id_199 };
              bool letpair_res_201;
              {
                auto leb128_fst_60 { std::get<0>(leb128_59) };
                auto leb128_snd_61 { std::get<1>(leb128_59) };
                uint8_t id_202 { 0 };
                Void id_203 { ((void)(p_ref_58[id_202] = leb128_snd_61), VOID) };
                (void)id_203;
                uint8_t id_204 { 0 };
                uint8_t id_205 { 127 };
                uint8_t id_206 { uint8_t(leb128_fst_60 & id_205) };
                uint32_t id_207 { uint32_t(id_206) };
                uint8_t id_208 { 0 };
                uint8_t id_209 { shft_ref_57[id_208] };
                uint32_t id_210 { uint32_t(id_207 << id_209) };
                uint8_t id_211 { 0 };
                uint32_t id_212 { leb_ref_56[id_211] };
                uint32_t id_213 { uint32_t(id_210 | id_212) };
                Void id_214 { ((void)(leb_ref_56[id_204] = id_213), VOID) };
                (void)id_214;
                uint8_t id_215 { 0 };
                uint8_t id_216 { 0 };
                uint8_t id_217 { shft_ref_57[id_216] };
                uint8_t id_218 { 7 };
                uint8_t id_219 { uint8_t(id_217 + id_218) };
                Void id_220 { ((void)(shft_ref_57[id_215] = id_219), VOID) };
                (void)id_220;
                uint8_t id_221 { 128 };
                bool id_222 { bool(leb128_fst_60 >= id_221) };
                letpair_res_201 = id_222;
              }
              let_res_200 = letpair_res_201;
            }
            while_flag_196 = let_res_200;
            if (while_flag_196) {
              (void)VOID;
            }
          } while (while_flag_196);
          (void)VOID;
          uint8_t id_223 { 0 };
          uint32_t id_224 { leb_ref_56[id_223] };
          uint8_t id_225 { 0 };
          Pointer id_226 { p_ref_58[id_225] };
          t405eb186408556fed8f2c41523c07d13 id_227 { id_224, id_226 };
          let_res_195 = id_227;
        }
        let_res_193 = let_res_195;
      }
      let_res_190 = let_res_193;
    }
    t8b191373a530a22f6a1b92183fc54a25 let_res_228;
    {
      t405eb186408556fed8f2c41523c07d13 dlist1_65 { let_res_190 };
      t8b191373a530a22f6a1b92183fc54a25 letpair_res_229;
      {
        auto dlist1_fst_66 { std::get<0>(dlist1_65) };
        auto dlist1_snd_67 { std::get<1>(dlist1_65) };
        Lst<t3a9ea1f12a4e632b6e111d6d47b80632> endoflist_230;
        t8b191373a530a22f6a1b92183fc54a25 id_231 { endoflist_230, dlist1_snd_67 };
        Vec<1, t8b191373a530a22f6a1b92183fc54a25> id_232 {  id_231  };
        t8b191373a530a22f6a1b92183fc54a25 let_res_233;
        {
          Vec<1, t8b191373a530a22f6a1b92183fc54a25> inits_src_ref_68 { id_232 };
          int32_t id_234 { 0L };
          Vec<1, int32_t> id_235 {  id_234  };
          {
            Vec<1, int32_t> repeat_n_69 { id_235 };
            bool while_flag_236 { true };
            do {
              int32_t id_237 { int32_t(dlist1_fst_66) };
              uint8_t id_238 { 0 };
              int32_t id_239 { repeat_n_69[id_238] };
              bool id_240 { bool(id_237 > id_239) };
              while_flag_236 = id_240;
              if (while_flag_236) {
                uint8_t id_241 { 0 };
                t8b191373a530a22f6a1b92183fc54a25 id_242 { inits_src_ref_68[id_241] };
                {
                  t8b191373a530a22f6a1b92183fc54a25 dlist2_70 { id_242 };
                  {
                    auto dlist2_fst_71 { std::get<0>(dlist2_70) };
                    auto dlist2_snd_72 { std::get<1>(dlist2_70) };
                    uint8_t id_243 { 0 };
                    uint32_t id_244 { 0U };
                    Vec<1, uint32_t> id_245 {  id_244  };
                    t8beb80162423aee37bd383e9b6834c9c let_res_246;
                    {
                      Vec<1, uint32_t> leb_ref_73 { id_245 };
                      uint8_t id_247 { 0 };
                      Vec<1, uint8_t> id_248 {  id_247  };
                      t8beb80162423aee37bd383e9b6834c9c let_res_249;
                      {
                        Vec<1, uint8_t> shft_ref_74 { id_248 };
                        Vec<1, Pointer> id_250 {  dlist2_snd_72  };
                        t8beb80162423aee37bd383e9b6834c9c let_res_251;
                        {
                          Vec<1, Pointer> p_ref_75 { id_250 };
                          bool while_flag_252 { true };
                          do {
                            uint8_t id_253 { 0 };
                            Pointer id_254 { p_ref_75[id_253] };
                            tb3f98ea670610d40658a618de3ec7b90 id_255 { id_254.readU8() };
                            bool let_res_256;
                            {
                              tb3f98ea670610d40658a618de3ec7b90 leb128_76 { id_255 };
                              bool letpair_res_257;
                              {
                                auto leb128_fst_77 { std::get<0>(leb128_76) };
                                auto leb128_snd_78 { std::get<1>(leb128_76) };
                                uint8_t id_258 { 0 };
                                Void id_259 { ((void)(p_ref_75[id_258] = leb128_snd_78), VOID) };
                                (void)id_259;
                                uint8_t id_260 { 0 };
                                uint8_t id_261 { 127 };
                                uint8_t id_262 { uint8_t(leb128_fst_77 & id_261) };
                                uint32_t id_263 { uint32_t(id_262) };
                                uint8_t id_264 { 0 };
                                uint8_t id_265 { shft_ref_74[id_264] };
                                uint32_t id_266 { uint32_t(id_263 << id_265) };
                                uint8_t id_267 { 0 };
                                uint32_t id_268 { leb_ref_73[id_267] };
                                uint32_t id_269 { uint32_t(id_266 | id_268) };
                                Void id_270 { ((void)(leb_ref_73[id_260] = id_269), VOID) };
                                (void)id_270;
                                uint8_t id_271 { 0 };
                                uint8_t id_272 { 0 };
                                uint8_t id_273 { shft_ref_74[id_272] };
                                uint8_t id_274 { 7 };
                                uint8_t id_275 { uint8_t(id_273 + id_274) };
                                Void id_276 { ((void)(shft_ref_74[id_271] = id_275), VOID) };
                                (void)id_276;
                                uint8_t id_277 { 128 };
                                bool id_278 { bool(leb128_fst_77 >= id_277) };
                                letpair_res_257 = id_278;
                              }
                              let_res_256 = letpair_res_257;
                            }
                            while_flag_252 = let_res_256;
                            if (while_flag_252) {
                              (void)VOID;
                            }
                          } while (while_flag_252);
                          (void)VOID;
                          uint8_t id_279 { 0 };
                          uint32_t id_280 { leb_ref_73[id_279] };
                          Size id_281 { Size(id_280) };
                          uint8_t id_282 { 0 };
                          Pointer id_283 { p_ref_75[id_282] };
                          t8beb80162423aee37bd383e9b6834c9c id_284 { id_281, id_283 };
                          let_res_251 = id_284;
                        }
                        let_res_249 = let_res_251;
                      }
                      let_res_246 = let_res_249;
                    }
                    tef94b55d8809251f13165d9a05bd9d0e let_res_285;
                    {
                      t8beb80162423aee37bd383e9b6834c9c dstring1_79 { let_res_246 };
                      tef94b55d8809251f13165d9a05bd9d0e letpair_res_286;
                      {
                        auto dstring1_fst_80 { std::get<0>(dstring1_79) };
                        auto dstring1_snd_81 { std::get<1>(dstring1_79) };
                        t188345aa49abd0cb47ff73fedc219f08 id_287 { dstring1_snd_81.readBytes(dstring1_fst_80) };
                        tef94b55d8809251f13165d9a05bd9d0e letpair_res_288;
                        {
                          auto dstring2_fst_83 { std::get<0>(id_287) };
                          auto dstring2_snd_84 { std::get<1>(id_287) };
                          std::string id_289 { dstring2_fst_83.toString() };
                          tef94b55d8809251f13165d9a05bd9d0e id_290 { id_289, dstring2_snd_84 };
                          letpair_res_288 = id_290;
                        }
                        letpair_res_286 = letpair_res_288;
                      }
                      let_res_285 = letpair_res_286;
                    }
                    t8b191373a530a22f6a1b92183fc54a25 let_res_291;
                    {
                      tef94b55d8809251f13165d9a05bd9d0e dtup_85 { let_res_285 };
                      t8b191373a530a22f6a1b92183fc54a25 letpair_res_292;
                      {
                        auto dtup_fst_86 { std::get<0>(dtup_85) };
                        auto dtup_snd_87 { std::get<1>(dtup_85) };
                        t7a47220550fc5126a7b79f1e0c10c645 id_293 { dtup_snd_87.readU64Le() };
                        taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_294;
                        {
                          auto dfloat_fst_89 { std::get<0>(id_293) };
                          auto dfloat_snd_90 { std::get<1>(id_293) };
                          double id_295 { float_of_qword(dfloat_fst_89) };
                          taebed00ad7fdb3f7ced11d3cfd58aade id_296 { id_295, dfloat_snd_90 };
                          letpair_res_294 = id_296;
                        }
                        t8b191373a530a22f6a1b92183fc54a25 let_res_297;
                        {
                          taebed00ad7fdb3f7ced11d3cfd58aade dtup_91 { letpair_res_294 };
                          t8b191373a530a22f6a1b92183fc54a25 letpair_res_298;
                          {
                            auto dtup_fst_92 { std::get<0>(dtup_91) };
                            auto dtup_snd_93 { std::get<1>(dtup_91) };
                            tb3f98ea670610d40658a618de3ec7b90 id_299 { dtup_snd_93.readU8() };
                            t8b191373a530a22f6a1b92183fc54a25 letpair_res_300;
                            {
                              auto dbool_fst_95 { std::get<0>(id_299) };
                              auto dbool_snd_96 { std::get<1>(id_299) };
                              uint8_t id_301 { 0 };
                              bool id_302 { bool(dbool_fst_95 == id_301) };
                              bool id_303 { ! id_302 };
                              tea0eebdc0b2e9b51f69e77168901ab2f id_304 { dtup_fst_92, id_303 };
                              t3a9ea1f12a4e632b6e111d6d47b80632 id_305 { dtup_fst_86, id_304 };
                              Lst<t3a9ea1f12a4e632b6e111d6d47b80632> id_306 { id_305, dlist2_fst_71 };
                              t8b191373a530a22f6a1b92183fc54a25 id_307 { id_306, dbool_snd_96 };
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
                    Void id_308 { ((void)(inits_src_ref_68[id_243] = let_res_291), VOID) };
                    (void)id_308;
                  }
                  (void)VOID;
                }
                (void)VOID;
                uint8_t id_309 { 0 };
                uint8_t id_310 { 0 };
                int32_t id_311 { repeat_n_69[id_310] };
                int32_t id_312 { 1L };
                int32_t id_313 { int32_t(id_311 + id_312) };
                Void id_314 { ((void)(repeat_n_69[id_309] = id_313), VOID) };
                (void)id_314;
                (void)id_314;
              }
            } while (while_flag_236);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_315 { 0 };
          t8b191373a530a22f6a1b92183fc54a25 id_316 { inits_src_ref_68[id_315] };
          let_res_233 = id_316;
        }
        letpair_res_229 = let_res_233;
      }
      let_res_228 = letpair_res_229;
    }
    t519c57b31160411c6989716f3a9782e0 letpair_res_317;
    {
      auto dlist4_fst_107 { std::get<0>(let_res_228) };
      auto dlist4_snd_108 { std::get<1>(let_res_228) };
      t id_318 { dlist4_fst_107.toListRev() };
      t519c57b31160411c6989716f3a9782e0 id_319 { id_318, dlist4_snd_108 };
      letpair_res_317 = id_319;
    }
    return letpair_res_317;
  }
   };
  return fun187;
}
std::function<t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary(of_row_binary_init());

typedef t t_ext;

}
