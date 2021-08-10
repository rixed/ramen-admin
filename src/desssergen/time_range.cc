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
struct v_1d53ca1dfc33d45608c16f60daf686b4 {
  double since;
  double until;
  bool growing;
  bool operator==(v_1d53ca1dfc33d45608c16f60daf686b4 const &other) const {
    return since == other.since && until == other.until && growing == other.growing;
  }
};
std::ostream &operator<<(std::ostream &os, v_1d53ca1dfc33d45608c16f60daf686b4 const &r) {
  os << '{';
  os << "since:" << r.since << ',';
  os << "until:" << r.until << ',';
  os << "growing:" << r.growing;
  os << '}';
  return os;
}

typedef std::tuple<
  Arr<v_1d53ca1dfc33d45608c16f60daf686b4>,
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
  Lst<v_1d53ca1dfc33d45608c16f60daf686b4>,
  Pointer
> v_887ec5102464ddc3991f34608f0b97c3;

typedef std::tuple<
  uint64_t,
  Pointer
> b62e103e7915a76f45f02f7c6f667c79;

typedef std::tuple<
  double,
  Pointer
> v_41a5a8cf414de9bfdc6375241fcc910a;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{since: FLOAT; until: FLOAT; growing: BOOL}[]" "Ptr")
      (let "dst_ref_109"
        (make-vec
          (let "leb128_sz_107" (make-vec (cardinality (param 0)))
            (let "leb128_ptr_108" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_108")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_108"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_107"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_107"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_107"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_107") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_107")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_107")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_108"))))))
        (let "n_ref_110" (make-vec (i32 0))
          (seq
            (for-each "x_111" (param 0)
              (seq
                (set-vec (u8 0) (identifier "dst_ref_109")
                  (let "srec_dst_114"
                    (let "srec_dst_113" (let "srec_dst_112" (unsafe-nth (u8 0) (identifier "dst_ref_109")) (write-u64 little-endian (identifier "srec_dst_112") (u64-of-float (get-field "since" (identifier "x_111")))))
                      (write-u64 little-endian (identifier "srec_dst_113") (u64-of-float (get-field "until" (identifier "x_111"))))) 
                    (write-u8 (identifier "srec_dst_114") (u8-of-bool (get-field "growing" (identifier "x_111")))))) 
                (set-vec (u8 0) (identifier "n_ref_110") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_110")))))) 
            (unsafe-nth (u8 0) (identifier "dst_ref_109"))))))
 */
static std::function<Pointer(Arr<v_1d53ca1dfc33d45608c16f60daf686b4>&,Pointer)> to_row_binary_init()
{
  std::function<Pointer(Arr<v_1d53ca1dfc33d45608c16f60daf686b4>&,Pointer)> fun0 { [&fun0](Arr<v_1d53ca1dfc33d45608c16f60daf686b4>& p_0, Pointer p_1) {
    uint32_t id_1 { p_0.size() };
    Vec<1, uint32_t> id_2 {  id_1  };
    Pointer let_res_3;
    {
      Vec<1, uint32_t> leb128_sz_107 { id_2 };
      Vec<1, Pointer> id_4 {  p_1  };
      Pointer let_res_5;
      {
        Vec<1, Pointer> leb128_ptr_108 { id_4 };
        bool while_flag_6 { true };
        do {
          uint8_t id_7 { 0 };
          uint8_t id_8 { 0 };
          Pointer id_9 { leb128_ptr_108[id_8] };
          uint32_t id_10 { 128U };
          uint8_t id_11 { 0 };
          uint32_t id_12 { leb128_sz_107[id_11] };
          bool id_13 { bool(id_10 > id_12) };
          uint8_t choose_res_14;
          if (id_13) {
            uint8_t id_15 { 0 };
            uint32_t id_16 { leb128_sz_107[id_15] };
            uint8_t id_17 { uint8_t(id_16) };
            choose_res_14 = id_17;
          } else {
            uint8_t id_18 { 0 };
            uint32_t id_19 { leb128_sz_107[id_18] };
            uint8_t id_20 { uint8_t(id_19) };
            uint8_t id_21 { 128 };
            uint8_t id_22 { uint8_t(id_20 | id_21) };
            choose_res_14 = id_22;
          }
          Pointer id_23 { id_9.writeU8(choose_res_14) };
          Void id_24 { ((void)(leb128_ptr_108[id_7] = id_23), VOID) };
          uint8_t id_25 { 0 };
          uint8_t id_26 { 0 };
          uint32_t id_27 { leb128_sz_107[id_26] };
          uint8_t id_28 { 7 };
          uint32_t id_29 { uint32_t(id_27 >> id_28) };
          Void id_30 { ((void)(leb128_sz_107[id_25] = id_29), VOID) };
          uint8_t id_31 { 0 };
          uint32_t id_32 { leb128_sz_107[id_31] };
          uint32_t id_33 { 0U };
          bool id_34 { bool(id_32 > id_33) };
          while_flag_6 = id_34;
          if (while_flag_6) {
          }
        } while (while_flag_6);
        uint8_t id_35 { 0 };
        Pointer id_36 { leb128_ptr_108[id_35] };
        let_res_5 = id_36;
      }
      let_res_3 = let_res_5;
    }
    Vec<1, Pointer> id_37 {  let_res_3  };
    Pointer let_res_38;
    {
      Vec<1, Pointer> dst_ref_109 { id_37 };
      int32_t id_39 { 0L };
      Vec<1, int32_t> id_40 {  id_39  };
      Pointer let_res_41;
      {
        Vec<1, int32_t> n_ref_110 { id_40 };
        for (v_1d53ca1dfc33d45608c16f60daf686b4 x_111 : p_0) {
          uint8_t id_42 { 0 };
          uint8_t id_43 { 0 };
          Pointer id_44 { dst_ref_109[id_43] };
          Pointer let_res_45;
          {
            Pointer srec_dst_112 { id_44 };
            double id_46 { x_111.since };
            uint64_t id_47 { qword_of_float(id_46) };
            Pointer id_48 { srec_dst_112.writeU64Le(id_47) };
            let_res_45 = id_48;
          }
          Pointer let_res_49;
          {
            Pointer srec_dst_113 { let_res_45 };
            double id_50 { x_111.until };
            uint64_t id_51 { qword_of_float(id_50) };
            Pointer id_52 { srec_dst_113.writeU64Le(id_51) };
            let_res_49 = id_52;
          }
          Pointer let_res_53;
          {
            Pointer srec_dst_114 { let_res_49 };
            bool id_54 { x_111.growing };
            uint8_t id_55 { uint8_t(id_54) };
            Pointer id_56 { srec_dst_114.writeU8(id_55) };
            let_res_53 = id_56;
          }
          Void id_57 { ((void)(dst_ref_109[id_42] = let_res_53), VOID) };
          uint8_t id_58 { 0 };
          int32_t id_59 { 1L };
          uint8_t id_60 { 0 };
          int32_t id_61 { n_ref_110[id_60] };
          int32_t id_62 { int32_t(id_59 + id_61) };
          Void id_63 { ((void)(n_ref_110[id_58] = id_62), VOID) };
        }
        uint8_t id_64 { 0 };
        Pointer id_65 { dst_ref_109[id_64] };
        let_res_41 = id_65;
      }
      let_res_38 = let_res_41;
    }
    return let_res_38;
  }
   };
  return fun0;
}
std::function<Pointer(Arr<v_1d53ca1dfc33d45608c16f60daf686b4>&,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{since: FLOAT; until: FLOAT; growing: BOOL}[]")
      (let "sz_ref_102"
        (make-vec
          (let "n_ref_100" (make-vec (cardinality (param 0)))
            (let "lebsz_ref_101" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_100")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_101")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_101") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_101")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_101")))))))
        (seq
          (let "repeat_n_103" (make-vec (i32 0))
            (while (gt (to-i32 (cardinality (param 0))) (unsafe-nth (u8 0) (identifier "repeat_n_103")))
              (seq (set-vec (u8 0) (identifier "sz_ref_102") (add (add (add (unsafe-nth (u8 0) (identifier "sz_ref_102")) (size 8)) (size 8)) (size 1)))
                (set-vec (u8 0) (identifier "repeat_n_103") (add (unsafe-nth (u8 0) (identifier "repeat_n_103")) (i32 1)))))) 
          (unsafe-nth (u8 0) (identifier "sz_ref_102")))))
 */
static std::function<Size(Arr<v_1d53ca1dfc33d45608c16f60daf686b4>&)> sersize_of_row_binary_init()
{
  std::function<Size(Arr<v_1d53ca1dfc33d45608c16f60daf686b4>&)> fun66 { [&fun66](Arr<v_1d53ca1dfc33d45608c16f60daf686b4>& p_0) {
    uint32_t id_67 { p_0.size() };
    Vec<1, uint32_t> id_68 {  id_67  };
    Size let_res_69;
    {
      Vec<1, uint32_t> n_ref_100 { id_68 };
      uint32_t id_70 { 1U };
      Vec<1, uint32_t> id_71 {  id_70  };
      Size let_res_72;
      {
        Vec<1, uint32_t> lebsz_ref_101 { id_71 };
        bool while_flag_73 { true };
        do {
          uint8_t id_74 { 0 };
          uint32_t id_75 { n_ref_100[id_74] };
          uint8_t id_76 { 0 };
          uint32_t id_77 { lebsz_ref_101[id_76] };
          uint8_t id_78 { 7 };
          uint32_t id_79 { uint32_t(id_77 << id_78) };
          bool id_80 { bool(id_75 >= id_79) };
          while_flag_73 = id_80;
          if (while_flag_73) {
            uint8_t id_81 { 0 };
            uint8_t id_82 { 0 };
            uint32_t id_83 { lebsz_ref_101[id_82] };
            uint32_t id_84 { 1U };
            uint32_t id_85 { uint32_t(id_83 + id_84) };
            Void id_86 { ((void)(lebsz_ref_101[id_81] = id_85), VOID) };
          }
        } while (while_flag_73);
        uint8_t id_87 { 0 };
        uint32_t id_88 { lebsz_ref_101[id_87] };
        Size id_89 { Size(id_88) };
        let_res_72 = id_89;
      }
      let_res_69 = let_res_72;
    }
    Vec<1, Size> id_90 {  let_res_69  };
    Size let_res_91;
    {
      Vec<1, Size> sz_ref_102 { id_90 };
      int32_t id_92 { 0L };
      Vec<1, int32_t> id_93 {  id_92  };
      {
        Vec<1, int32_t> repeat_n_103 { id_93 };
        bool while_flag_94 { true };
        do {
          uint32_t id_95 { p_0.size() };
          int32_t id_96 { int32_t(id_95) };
          uint8_t id_97 { 0 };
          int32_t id_98 { repeat_n_103[id_97] };
          bool id_99 { bool(id_96 > id_98) };
          while_flag_94 = id_99;
          if (while_flag_94) {
            uint8_t id_100 { 0 };
            uint8_t id_101 { 0 };
            Size id_102 { sz_ref_102[id_101] };
            Size id_103 { 8UL };
            Size id_104 { Size(id_102 + id_103) };
            Size id_105 { 8UL };
            Size id_106 { Size(id_104 + id_105) };
            Size id_107 { 1UL };
            Size id_108 { Size(id_106 + id_107) };
            Void id_109 { ((void)(sz_ref_102[id_100] = id_108), VOID) };
            uint8_t id_110 { 0 };
            uint8_t id_111 { 0 };
            int32_t id_112 { repeat_n_103[id_111] };
            int32_t id_113 { 1L };
            int32_t id_114 { int32_t(id_112 + id_113) };
            Void id_115 { ((void)(repeat_n_103[id_110] = id_114), VOID) };
          }
        } while (while_flag_94);
      }
      uint8_t id_116 { 0 };
      Size id_117 { sz_ref_102[id_116] };
      let_res_91 = id_117;
    }
    return let_res_91;
  }
   };
  return fun66;
}
std::function<Size(Arr<v_1d53ca1dfc33d45608c16f60daf686b4>&)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "dlist4_fst_95" "dlist4_snd_96"
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
            (let "inits_src_ref_68" (make-vec (make-tup (end-of-list "{since: FLOAT; until: FLOAT; growing: BOOL}") (identifier "dlist1_snd_67")))
              (seq
                (let "repeat_n_69" (make-vec (i32 0))
                  (while (gt (to-i32 (identifier "dlist1_fst_66")) (unsafe-nth (u8 0) (identifier "repeat_n_69")))
                    (seq
                      (let "dlist2_70" (unsafe-nth (u8 0) (identifier "inits_src_ref_68"))
                        (let-pair "dlist2_fst_71" "dlist2_snd_72" (identifier "dlist2_70")
                          (set-vec (u8 0) (identifier "inits_src_ref_68")
                            (let "drec_76" (let-pair "dfloat_fst_74" "dfloat_snd_75" (read-u64 little-endian (identifier "dlist2_snd_72")) (make-tup (float-of-u64 (identifier "dfloat_fst_74")) (identifier "dfloat_snd_75")))
                              (let-pair "drec_fst_77" "drec_snd_78" (identifier "drec_76")
                                (let "drec_82" (let-pair "dfloat_fst_80" "dfloat_snd_81" (read-u64 little-endian (identifier "drec_snd_78")) (make-tup (float-of-u64 (identifier "dfloat_fst_80")) (identifier "dfloat_snd_81")))
                                  (let-pair "drec_fst_83" "drec_snd_84" 
                                    (identifier "drec_82")
                                    (let-pair "dbool_fst_86" "dbool_snd_87" 
                                      (read-u8 (identifier "drec_snd_84"))
                                      (make-tup
                                        (cons (make-rec (string "since") (identifier "drec_fst_77") (string "until") (identifier "drec_fst_83") (string "growing") (not (eq (identifier "dbool_fst_86") (u8 0))))
                                          (identifier "dlist2_fst_71")) 
                                        (identifier "dbool_snd_87")))))))))) 
                      (set-vec (u8 0) (identifier "repeat_n_69") (add (unsafe-nth (u8 0) (identifier "repeat_n_69")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "inits_src_ref_68")))))) 
        (make-tup (arr-of-lst-rev (identifier "dlist4_fst_95")) (identifier "dlist4_snd_96"))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun118 { [&fun118](Pointer p_0) {
    uint32_t id_119 { 0U };
    Vec<1, uint32_t> id_120 {  id_119  };
    ac0fbd05039f742d2f1d9ac182e392ab let_res_121;
    {
      Vec<1, uint32_t> leb_ref_56 { id_120 };
      uint8_t id_122 { 0 };
      Vec<1, uint8_t> id_123 {  id_122  };
      ac0fbd05039f742d2f1d9ac182e392ab let_res_124;
      {
        Vec<1, uint8_t> shft_ref_57 { id_123 };
        Vec<1, Pointer> id_125 {  p_0  };
        ac0fbd05039f742d2f1d9ac182e392ab let_res_126;
        {
          Vec<1, Pointer> p_ref_58 { id_125 };
          bool while_flag_127 { true };
          do {
            uint8_t id_128 { 0 };
            Pointer id_129 { p_ref_58[id_128] };
            v_1d5843897434feb24d158f3793db9189 id_130 { id_129.readU8() };
            bool let_res_131;
            {
              v_1d5843897434feb24d158f3793db9189 leb128_59 { id_130 };
              bool letpair_res_132;
              {
                auto leb128_fst_60 { std::get<0>(leb128_59) };
                auto leb128_snd_61 { std::get<1>(leb128_59) };
                uint8_t id_133 { 0 };
                Void id_134 { ((void)(p_ref_58[id_133] = leb128_snd_61), VOID) };
                uint8_t id_135 { 0 };
                uint8_t id_136 { 127 };
                uint8_t id_137 { uint8_t(leb128_fst_60 & id_136) };
                uint32_t id_138 { uint32_t(id_137) };
                uint8_t id_139 { 0 };
                uint8_t id_140 { shft_ref_57[id_139] };
                uint32_t id_141 { uint32_t(id_138 << id_140) };
                uint8_t id_142 { 0 };
                uint32_t id_143 { leb_ref_56[id_142] };
                uint32_t id_144 { uint32_t(id_141 | id_143) };
                Void id_145 { ((void)(leb_ref_56[id_135] = id_144), VOID) };
                uint8_t id_146 { 0 };
                uint8_t id_147 { 0 };
                uint8_t id_148 { shft_ref_57[id_147] };
                uint8_t id_149 { 7 };
                uint8_t id_150 { uint8_t(id_148 + id_149) };
                Void id_151 { ((void)(shft_ref_57[id_146] = id_150), VOID) };
                uint8_t id_152 { 128 };
                bool id_153 { bool(leb128_fst_60 >= id_152) };
                letpair_res_132 = id_153;
              }
              let_res_131 = letpair_res_132;
            }
            while_flag_127 = let_res_131;
            if (while_flag_127) {
            }
          } while (while_flag_127);
          uint8_t id_154 { 0 };
          uint32_t id_155 { leb_ref_56[id_154] };
          uint8_t id_156 { 0 };
          Pointer id_157 { p_ref_58[id_156] };
          ac0fbd05039f742d2f1d9ac182e392ab id_158 {  id_155, id_157  };
          let_res_126 = id_158;
        }
        let_res_124 = let_res_126;
      }
      let_res_121 = let_res_124;
    }
    v_887ec5102464ddc3991f34608f0b97c3 let_res_159;
    {
      ac0fbd05039f742d2f1d9ac182e392ab dlist1_65 { let_res_121 };
      v_887ec5102464ddc3991f34608f0b97c3 letpair_res_160;
      {
        auto dlist1_fst_66 { std::get<0>(dlist1_65) };
        auto dlist1_snd_67 { std::get<1>(dlist1_65) };
        Lst<v_1d53ca1dfc33d45608c16f60daf686b4> endoflist_161;
        v_887ec5102464ddc3991f34608f0b97c3 id_162 {  endoflist_161, dlist1_snd_67  };
        Vec<1, v_887ec5102464ddc3991f34608f0b97c3> id_163 {  id_162  };
        v_887ec5102464ddc3991f34608f0b97c3 let_res_164;
        {
          Vec<1, v_887ec5102464ddc3991f34608f0b97c3> inits_src_ref_68 { id_163 };
          int32_t id_165 { 0L };
          Vec<1, int32_t> id_166 {  id_165  };
          {
            Vec<1, int32_t> repeat_n_69 { id_166 };
            bool while_flag_167 { true };
            do {
              int32_t id_168 { int32_t(dlist1_fst_66) };
              uint8_t id_169 { 0 };
              int32_t id_170 { repeat_n_69[id_169] };
              bool id_171 { bool(id_168 > id_170) };
              while_flag_167 = id_171;
              if (while_flag_167) {
                uint8_t id_172 { 0 };
                v_887ec5102464ddc3991f34608f0b97c3 id_173 { inits_src_ref_68[id_172] };
                {
                  v_887ec5102464ddc3991f34608f0b97c3 dlist2_70 { id_173 };
                  {
                    auto dlist2_fst_71 { std::get<0>(dlist2_70) };
                    auto dlist2_snd_72 { std::get<1>(dlist2_70) };
                    uint8_t id_174 { 0 };
                    b62e103e7915a76f45f02f7c6f667c79 id_175 { dlist2_snd_72.readU64Le() };
                    v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_176;
                    {
                      auto dfloat_fst_74 { std::get<0>(id_175) };
                      auto dfloat_snd_75 { std::get<1>(id_175) };
                      double id_177 { float_of_qword(dfloat_fst_74) };
                      v_41a5a8cf414de9bfdc6375241fcc910a id_178 {  id_177, dfloat_snd_75  };
                      letpair_res_176 = id_178;
                    }
                    v_887ec5102464ddc3991f34608f0b97c3 let_res_179;
                    {
                      v_41a5a8cf414de9bfdc6375241fcc910a drec_76 { letpair_res_176 };
                      v_887ec5102464ddc3991f34608f0b97c3 letpair_res_180;
                      {
                        auto drec_fst_77 { std::get<0>(drec_76) };
                        auto drec_snd_78 { std::get<1>(drec_76) };
                        b62e103e7915a76f45f02f7c6f667c79 id_181 { drec_snd_78.readU64Le() };
                        v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_182;
                        {
                          auto dfloat_fst_80 { std::get<0>(id_181) };
                          auto dfloat_snd_81 { std::get<1>(id_181) };
                          double id_183 { float_of_qword(dfloat_fst_80) };
                          v_41a5a8cf414de9bfdc6375241fcc910a id_184 {  id_183, dfloat_snd_81  };
                          letpair_res_182 = id_184;
                        }
                        v_887ec5102464ddc3991f34608f0b97c3 let_res_185;
                        {
                          v_41a5a8cf414de9bfdc6375241fcc910a drec_82 { letpair_res_182 };
                          v_887ec5102464ddc3991f34608f0b97c3 letpair_res_186;
                          {
                            auto drec_fst_83 { std::get<0>(drec_82) };
                            auto drec_snd_84 { std::get<1>(drec_82) };
                            v_1d5843897434feb24d158f3793db9189 id_187 { drec_snd_84.readU8() };
                            v_887ec5102464ddc3991f34608f0b97c3 letpair_res_188;
                            {
                              auto dbool_fst_86 { std::get<0>(id_187) };
                              auto dbool_snd_87 { std::get<1>(id_187) };
                              uint8_t id_189 { 0 };
                              bool id_190 { bool(dbool_fst_86 == id_189) };
                              bool id_191 { ! id_190 };
                              v_1d53ca1dfc33d45608c16f60daf686b4 id_192 {  .since = drec_fst_77, .until = drec_fst_83, .growing = id_191  };
                              Lst<v_1d53ca1dfc33d45608c16f60daf686b4> id_193 { id_192, dlist2_fst_71 };
                              v_887ec5102464ddc3991f34608f0b97c3 id_194 {  id_193, dbool_snd_87  };
                              letpair_res_188 = id_194;
                            }
                            letpair_res_186 = letpair_res_188;
                          }
                          let_res_185 = letpair_res_186;
                        }
                        letpair_res_180 = let_res_185;
                      }
                      let_res_179 = letpair_res_180;
                    }
                    Void id_195 { ((void)(inits_src_ref_68[id_174] = let_res_179), VOID) };
                  }
                }
                uint8_t id_196 { 0 };
                uint8_t id_197 { 0 };
                int32_t id_198 { repeat_n_69[id_197] };
                int32_t id_199 { 1L };
                int32_t id_200 { int32_t(id_198 + id_199) };
                Void id_201 { ((void)(repeat_n_69[id_196] = id_200), VOID) };
              }
            } while (while_flag_167);
          }
          uint8_t id_202 { 0 };
          v_887ec5102464ddc3991f34608f0b97c3 id_203 { inits_src_ref_68[id_202] };
          let_res_164 = id_203;
        }
        letpair_res_160 = let_res_164;
      }
      let_res_159 = letpair_res_160;
    }
    f63f919559f0d70225bd0da5dd9bcafc letpair_res_204;
    {
      auto dlist4_fst_95 { std::get<0>(let_res_159) };
      auto dlist4_snd_96 { std::get<1>(let_res_159) };
      Arr<v_1d53ca1dfc33d45608c16f60daf686b4> id_205 { dlist4_fst_95.toListRev() };
      f63f919559f0d70225bd0da5dd9bcafc id_206 {  id_205, dlist4_snd_96  };
      letpair_res_204 = id_206;
    }
    return letpair_res_204;
  }
   };
  return fun118;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
