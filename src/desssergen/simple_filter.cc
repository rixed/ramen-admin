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
#include "desssergen/field_name.h"


namespace dessser::gen::simple_filter {
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
  dessser::gen::field_name::t_ext lhs;
  std::string op;
  std::string rhs;
  bool operator==(t const &other) const {
    return lhs == other.lhs && op == other.op && rhs == other.rhs;
  }
};
typedef std::tuple<
  ::dessser::gen::simple_filter::t*,
  Pointer
> t5ec462bd9f9d5a838e7e865b5af804fe;

typedef std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> t273a2b7978f5b466a128a51c1cc4a27b;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  std::string,
  Pointer
> tef94b55d8809251f13165d9a05bd9d0e;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{lhs: $field_name; rhs: STRING; op: STRING}" "Ptr")
      (let "srec_dst_104"
        (let "srec_dst_101" (apply (ext-identifier field_name to-row-binary) (get-field "lhs" (param 0)) (param 1))
          (write-bytes
            (let "leb128_sz_102" (make-vec (string-length (get-field "rhs" (param 0))))
              (let "leb128_ptr_103" (make-vec (identifier "srec_dst_101"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_103")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_103"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_102"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_102"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_102"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_102") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_102")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_102")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_103"))))) 
            (bytes-of-string (get-field "rhs" (param 0)))))
        (write-bytes
          (let "leb128_sz_105" (make-vec (string-length (get-field "op" (param 0))))
            (let "leb128_ptr_106" (make-vec (identifier "srec_dst_104"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_106")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_106"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_105"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_105"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_105"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_105") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_105")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_105")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_106"))))) 
          (bytes-of-string (get-field "op" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::simple_filter::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::simple_filter::t*,Pointer)> fun0 { [&fun0](::dessser::gen::simple_filter::t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t_ext id_2 { p_0->lhs };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_101 { id_3 };
      std::string id_5 { p_0->rhs };
      uint32_t id_6 { (uint32_t)id_5.size() };
      Vec<1, uint32_t> id_7 {  id_6  };
      Pointer let_res_8;
      {
        Vec<1, uint32_t> leb128_sz_102 { id_7 };
        Vec<1, Pointer> id_9 {  srec_dst_101  };
        Pointer let_res_10;
        {
          Vec<1, Pointer> leb128_ptr_103 { id_9 };
          bool while_flag_11 { true };
          do {
            uint8_t id_12 { 0 };
            uint8_t id_13 { 0 };
            Pointer id_14 { leb128_ptr_103[id_13] };
            uint32_t id_15 { 128U };
            uint8_t id_16 { 0 };
            uint32_t id_17 { leb128_sz_102[id_16] };
            bool id_18 { bool(id_15 > id_17) };
            uint8_t choose_res_19;
            if (id_18) {
              uint8_t id_20 { 0 };
              uint32_t id_21 { leb128_sz_102[id_20] };
              uint8_t id_22 { uint8_t(id_21) };
              choose_res_19 = id_22;
            } else {
              uint8_t id_23 { 0 };
              uint32_t id_24 { leb128_sz_102[id_23] };
              uint8_t id_25 { uint8_t(id_24) };
              uint8_t id_26 { 128 };
              uint8_t id_27 { uint8_t(id_25 | id_26) };
              choose_res_19 = id_27;
            }
            Pointer id_28 { id_14.writeU8(choose_res_19) };
            Void id_29 { ((void)(leb128_ptr_103[id_12] = id_28), VOID) };
            (void)id_29;
            uint8_t id_30 { 0 };
            uint8_t id_31 { 0 };
            uint32_t id_32 { leb128_sz_102[id_31] };
            uint8_t id_33 { 7 };
            uint32_t id_34 { uint32_t(id_32 >> id_33) };
            Void id_35 { ((void)(leb128_sz_102[id_30] = id_34), VOID) };
            (void)id_35;
            uint8_t id_36 { 0 };
            uint32_t id_37 { leb128_sz_102[id_36] };
            uint32_t id_38 { 0U };
            bool id_39 { bool(id_37 > id_38) };
            while_flag_11 = id_39;
            if (while_flag_11) {
              (void)VOID;
            }
          } while (while_flag_11);
          (void)VOID;
          uint8_t id_40 { 0 };
          Pointer id_41 { leb128_ptr_103[id_40] };
          let_res_10 = id_41;
        }
        let_res_8 = let_res_10;
      }
      std::string id_42 { p_0->rhs };
      Bytes id_43 { id_42 };
      Pointer id_44 { let_res_8.writeBytes(id_43) };
      let_res_4 = id_44;
    }
    Pointer let_res_45;
    {
      Pointer srec_dst_104 { let_res_4 };
      std::string id_46 { p_0->op };
      uint32_t id_47 { (uint32_t)id_46.size() };
      Vec<1, uint32_t> id_48 {  id_47  };
      Pointer let_res_49;
      {
        Vec<1, uint32_t> leb128_sz_105 { id_48 };
        Vec<1, Pointer> id_50 {  srec_dst_104  };
        Pointer let_res_51;
        {
          Vec<1, Pointer> leb128_ptr_106 { id_50 };
          bool while_flag_52 { true };
          do {
            uint8_t id_53 { 0 };
            uint8_t id_54 { 0 };
            Pointer id_55 { leb128_ptr_106[id_54] };
            uint32_t id_56 { 128U };
            uint8_t id_57 { 0 };
            uint32_t id_58 { leb128_sz_105[id_57] };
            bool id_59 { bool(id_56 > id_58) };
            uint8_t choose_res_60;
            if (id_59) {
              uint8_t id_61 { 0 };
              uint32_t id_62 { leb128_sz_105[id_61] };
              uint8_t id_63 { uint8_t(id_62) };
              choose_res_60 = id_63;
            } else {
              uint8_t id_64 { 0 };
              uint32_t id_65 { leb128_sz_105[id_64] };
              uint8_t id_66 { uint8_t(id_65) };
              uint8_t id_67 { 128 };
              uint8_t id_68 { uint8_t(id_66 | id_67) };
              choose_res_60 = id_68;
            }
            Pointer id_69 { id_55.writeU8(choose_res_60) };
            Void id_70 { ((void)(leb128_ptr_106[id_53] = id_69), VOID) };
            (void)id_70;
            uint8_t id_71 { 0 };
            uint8_t id_72 { 0 };
            uint32_t id_73 { leb128_sz_105[id_72] };
            uint8_t id_74 { 7 };
            uint32_t id_75 { uint32_t(id_73 >> id_74) };
            Void id_76 { ((void)(leb128_sz_105[id_71] = id_75), VOID) };
            (void)id_76;
            uint8_t id_77 { 0 };
            uint32_t id_78 { leb128_sz_105[id_77] };
            uint32_t id_79 { 0U };
            bool id_80 { bool(id_78 > id_79) };
            while_flag_52 = id_80;
            if (while_flag_52) {
              (void)VOID;
            }
          } while (while_flag_52);
          (void)VOID;
          uint8_t id_81 { 0 };
          Pointer id_82 { leb128_ptr_106[id_81] };
          let_res_51 = id_82;
        }
        let_res_49 = let_res_51;
      }
      std::string id_83 { p_0->op };
      Bytes id_84 { id_83 };
      Pointer id_85 { let_res_49.writeBytes(id_84) };
      let_res_45 = id_85;
    }
    return let_res_45;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::simple_filter::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{lhs: $field_name; rhs: STRING; op: STRING}")
      (let "sz_97"
        (let "sz_93" (apply (ext-identifier field_name sersize-of-row-binary) (get-field "lhs" (param 0)))
          (add (identifier "sz_93")
            (add
              (let "n_ref_95" (make-vec (string-length (get-field "rhs" (param 0))))
                (let "lebsz_ref_96" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_95")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_96")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_96") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_96")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_96")))))) 
              (size-of-u32 (string-length (get-field "rhs" (param 0)))))))
        (add (identifier "sz_97")
          (add
            (let "n_ref_99" (make-vec (string-length (get-field "op" (param 0))))
              (let "lebsz_ref_100" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_99")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_100")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_100") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_100")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_100")))))) 
            (size-of-u32 (string-length (get-field "op" (param 0))))))))
 */
static std::function<Size(::dessser::gen::simple_filter::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::simple_filter::t*)> fun86 { [&fun86](::dessser::gen::simple_filter::t* p_0) {
    auto fun87 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t_ext id_88 { p_0->lhs };
    Size id_89 { fun87(id_88) };
    Size let_res_90;
    {
      Size sz_93 { id_89 };
      std::string id_91 { p_0->rhs };
      uint32_t id_92 { (uint32_t)id_91.size() };
      Vec<1, uint32_t> id_93 {  id_92  };
      Size let_res_94;
      {
        Vec<1, uint32_t> n_ref_95 { id_93 };
        uint32_t id_95 { 1U };
        Vec<1, uint32_t> id_96 {  id_95  };
        Size let_res_97;
        {
          Vec<1, uint32_t> lebsz_ref_96 { id_96 };
          bool while_flag_98 { true };
          do {
            uint8_t id_99 { 0 };
            uint32_t id_100 { n_ref_95[id_99] };
            uint8_t id_101 { 0 };
            uint32_t id_102 { lebsz_ref_96[id_101] };
            uint8_t id_103 { 7 };
            uint32_t id_104 { uint32_t(id_102 << id_103) };
            bool id_105 { bool(id_100 >= id_104) };
            while_flag_98 = id_105;
            if (while_flag_98) {
              uint8_t id_106 { 0 };
              uint8_t id_107 { 0 };
              uint32_t id_108 { lebsz_ref_96[id_107] };
              uint32_t id_109 { 1U };
              uint32_t id_110 { uint32_t(id_108 + id_109) };
              Void id_111 { ((void)(lebsz_ref_96[id_106] = id_110), VOID) };
              (void)id_111;
            }
          } while (while_flag_98);
          (void)VOID;
          uint8_t id_112 { 0 };
          uint32_t id_113 { lebsz_ref_96[id_112] };
          Size id_114 { Size(id_113) };
          let_res_97 = id_114;
        }
        let_res_94 = let_res_97;
      }
      std::string id_115 { p_0->rhs };
      uint32_t id_116 { (uint32_t)id_115.size() };
      Size id_117 { Size(id_116) };
      Size id_118 { Size(let_res_94 + id_117) };
      Size id_119 { Size(sz_93 + id_118) };
      let_res_90 = id_119;
    }
    Size let_res_120;
    {
      Size sz_97 { let_res_90 };
      std::string id_121 { p_0->op };
      uint32_t id_122 { (uint32_t)id_121.size() };
      Vec<1, uint32_t> id_123 {  id_122  };
      Size let_res_124;
      {
        Vec<1, uint32_t> n_ref_99 { id_123 };
        uint32_t id_125 { 1U };
        Vec<1, uint32_t> id_126 {  id_125  };
        Size let_res_127;
        {
          Vec<1, uint32_t> lebsz_ref_100 { id_126 };
          bool while_flag_128 { true };
          do {
            uint8_t id_129 { 0 };
            uint32_t id_130 { n_ref_99[id_129] };
            uint8_t id_131 { 0 };
            uint32_t id_132 { lebsz_ref_100[id_131] };
            uint8_t id_133 { 7 };
            uint32_t id_134 { uint32_t(id_132 << id_133) };
            bool id_135 { bool(id_130 >= id_134) };
            while_flag_128 = id_135;
            if (while_flag_128) {
              uint8_t id_136 { 0 };
              uint8_t id_137 { 0 };
              uint32_t id_138 { lebsz_ref_100[id_137] };
              uint32_t id_139 { 1U };
              uint32_t id_140 { uint32_t(id_138 + id_139) };
              Void id_141 { ((void)(lebsz_ref_100[id_136] = id_140), VOID) };
              (void)id_141;
            }
          } while (while_flag_128);
          (void)VOID;
          uint8_t id_142 { 0 };
          uint32_t id_143 { lebsz_ref_100[id_142] };
          Size id_144 { Size(id_143) };
          let_res_127 = id_144;
        }
        let_res_124 = let_res_127;
      }
      std::string id_145 { p_0->op };
      uint32_t id_146 { (uint32_t)id_145.size() };
      Size id_147 { Size(id_146) };
      Size id_148 { Size(let_res_124 + id_147) };
      Size id_149 { Size(sz_97 + id_148) };
      let_res_120 = id_149;
    }
    return let_res_120;
  }
   };
  return fun86;
}
std::function<Size(::dessser::gen::simple_filter::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_71"
            (let "dstring1_65"
              (let "leb_ref_59" (make-vec (u32 0))
                (let "shft_ref_60" (make-vec (u8 0))
                  (let "p_ref_61" (make-vec (identifier "drec_snd_58"))
                    (seq
                      (while
                        (let "leb128_62" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_61")))
                          (let-pair "leb128_fst_63" "leb128_snd_64" (identifier "leb128_62")
                            (seq (set-vec (u8 0) (identifier "p_ref_61") (identifier "leb128_snd_64"))
                              (set-vec (u8 0) (identifier "leb_ref_59")
                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_63") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_60"))) (unsafe-nth (u8 0) (identifier "leb_ref_59"))))
                              (set-vec (u8 0) (identifier "shft_ref_60") (add (unsafe-nth (u8 0) (identifier "shft_ref_60")) (u8 7))) 
                              (ge (identifier "leb128_fst_63") (u8 128))))) 
                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_59"))) (unsafe-nth (u8 0) (identifier "p_ref_61")))))))
              (let-pair "dstring1_fst_66" "dstring1_snd_67" (identifier "dstring1_65")
                (let-pair "dstring2_fst_69" "dstring2_snd_70" (read-bytes (identifier "dstring1_snd_67") (identifier "dstring1_fst_66")) (make-tup (string-of-bytes (identifier "dstring2_fst_69")) (identifier "dstring2_snd_70")))))
            (let-pair "drec_fst_72" "drec_snd_73" (identifier "drec_71")
              (let "dstring1_80"
                (let "leb_ref_74" (make-vec (u32 0))
                  (let "shft_ref_75" (make-vec (u8 0))
                    (let "p_ref_76" (make-vec (identifier "drec_snd_73"))
                      (seq
                        (while
                          (let "leb128_77" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_76")))
                            (let-pair "leb128_fst_78" "leb128_snd_79" 
                              (identifier "leb128_77")
                              (seq (set-vec (u8 0) (identifier "p_ref_76") (identifier "leb128_snd_79"))
                                (set-vec (u8 0) (identifier "leb_ref_74")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_78") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_75"))) (unsafe-nth (u8 0) (identifier "leb_ref_74"))))
                                (set-vec (u8 0) (identifier "shft_ref_75") (add (unsafe-nth (u8 0) (identifier "shft_ref_75")) (u8 7))) 
                                (ge (identifier "leb128_fst_78") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_74"))) (unsafe-nth (u8 0) (identifier "p_ref_76")))))))
                (let-pair "dstring1_fst_81" "dstring1_snd_82" (identifier "dstring1_80")
                  (let-pair "dstring2_fst_84" "dstring2_snd_85" (read-bytes (identifier "dstring1_snd_82") (identifier "dstring1_fst_81"))
                    (make-tup (make-rec (string "op") (string-of-bytes (identifier "dstring2_fst_84")) (string "rhs") (identifier "drec_fst_72") (string "lhs") (identifier "drec_fst_57")) (identifier "dstring2_snd_85"))))))))))
 */
static std::function<::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe(Pointer)> fun150 { [&fun150](Pointer p_0) {
    auto fun151 { dessser::gen::field_name::of_row_binary };
    ::dessser::gen::simple_filter::t273a2b7978f5b466a128a51c1cc4a27b id_152 { fun151(p_0) };
    ::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe let_res_153;
    {
      ::dessser::gen::simple_filter::t273a2b7978f5b466a128a51c1cc4a27b drec_56 { id_152 };
      ::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe letpair_res_154;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        uint32_t id_155 { 0U };
        Vec<1, uint32_t> id_156 {  id_155  };
        ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c let_res_157;
        {
          Vec<1, uint32_t> leb_ref_59 { id_156 };
          uint8_t id_158 { 0 };
          Vec<1, uint8_t> id_159 {  id_158  };
          ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c let_res_160;
          {
            Vec<1, uint8_t> shft_ref_60 { id_159 };
            Vec<1, Pointer> id_161 {  drec_snd_58  };
            ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c let_res_162;
            {
              Vec<1, Pointer> p_ref_61 { id_161 };
              bool while_flag_163 { true };
              do {
                uint8_t id_164 { 0 };
                Pointer id_165 { p_ref_61[id_164] };
                ::dessser::gen::simple_filter::tb3f98ea670610d40658a618de3ec7b90 id_166 { id_165.readU8() };
                bool let_res_167;
                {
                  ::dessser::gen::simple_filter::tb3f98ea670610d40658a618de3ec7b90 leb128_62 { id_166 };
                  bool letpair_res_168;
                  {
                    auto leb128_fst_63 { std::get<0>(leb128_62) };
                    auto leb128_snd_64 { std::get<1>(leb128_62) };
                    uint8_t id_169 { 0 };
                    Void id_170 { ((void)(p_ref_61[id_169] = leb128_snd_64), VOID) };
                    (void)id_170;
                    uint8_t id_171 { 0 };
                    uint8_t id_172 { 127 };
                    uint8_t id_173 { uint8_t(leb128_fst_63 & id_172) };
                    uint32_t id_174 { uint32_t(id_173) };
                    uint8_t id_175 { 0 };
                    uint8_t id_176 { shft_ref_60[id_175] };
                    uint32_t id_177 { uint32_t(id_174 << id_176) };
                    uint8_t id_178 { 0 };
                    uint32_t id_179 { leb_ref_59[id_178] };
                    uint32_t id_180 { uint32_t(id_177 | id_179) };
                    Void id_181 { ((void)(leb_ref_59[id_171] = id_180), VOID) };
                    (void)id_181;
                    uint8_t id_182 { 0 };
                    uint8_t id_183 { 0 };
                    uint8_t id_184 { shft_ref_60[id_183] };
                    uint8_t id_185 { 7 };
                    uint8_t id_186 { uint8_t(id_184 + id_185) };
                    Void id_187 { ((void)(shft_ref_60[id_182] = id_186), VOID) };
                    (void)id_187;
                    uint8_t id_188 { 128 };
                    bool id_189 { bool(leb128_fst_63 >= id_188) };
                    letpair_res_168 = id_189;
                  }
                  let_res_167 = letpair_res_168;
                }
                while_flag_163 = let_res_167;
                if (while_flag_163) {
                  (void)VOID;
                }
              } while (while_flag_163);
              (void)VOID;
              uint8_t id_190 { 0 };
              uint32_t id_191 { leb_ref_59[id_190] };
              Size id_192 { Size(id_191) };
              uint8_t id_193 { 0 };
              Pointer id_194 { p_ref_61[id_193] };
              ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c id_195 { id_192, id_194 };
              let_res_162 = id_195;
            }
            let_res_160 = let_res_162;
          }
          let_res_157 = let_res_160;
        }
        ::dessser::gen::simple_filter::tef94b55d8809251f13165d9a05bd9d0e let_res_196;
        {
          ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c dstring1_65 { let_res_157 };
          ::dessser::gen::simple_filter::tef94b55d8809251f13165d9a05bd9d0e letpair_res_197;
          {
            auto dstring1_fst_66 { std::get<0>(dstring1_65) };
            auto dstring1_snd_67 { std::get<1>(dstring1_65) };
            ::dessser::gen::simple_filter::t188345aa49abd0cb47ff73fedc219f08 id_198 { dstring1_snd_67.readBytes(dstring1_fst_66) };
            ::dessser::gen::simple_filter::tef94b55d8809251f13165d9a05bd9d0e letpair_res_199;
            {
              auto dstring2_fst_69 { std::get<0>(id_198) };
              auto dstring2_snd_70 { std::get<1>(id_198) };
              std::string id_200 { dstring2_fst_69.toString() };
              ::dessser::gen::simple_filter::tef94b55d8809251f13165d9a05bd9d0e id_201 { id_200, dstring2_snd_70 };
              letpair_res_199 = id_201;
            }
            letpair_res_197 = letpair_res_199;
          }
          let_res_196 = letpair_res_197;
        }
        ::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe let_res_202;
        {
          ::dessser::gen::simple_filter::tef94b55d8809251f13165d9a05bd9d0e drec_71 { let_res_196 };
          ::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe letpair_res_203;
          {
            auto drec_fst_72 { std::get<0>(drec_71) };
            auto drec_snd_73 { std::get<1>(drec_71) };
            uint32_t id_204 { 0U };
            Vec<1, uint32_t> id_205 {  id_204  };
            ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c let_res_206;
            {
              Vec<1, uint32_t> leb_ref_74 { id_205 };
              uint8_t id_207 { 0 };
              Vec<1, uint8_t> id_208 {  id_207  };
              ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c let_res_209;
              {
                Vec<1, uint8_t> shft_ref_75 { id_208 };
                Vec<1, Pointer> id_210 {  drec_snd_73  };
                ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c let_res_211;
                {
                  Vec<1, Pointer> p_ref_76 { id_210 };
                  bool while_flag_212 { true };
                  do {
                    uint8_t id_213 { 0 };
                    Pointer id_214 { p_ref_76[id_213] };
                    ::dessser::gen::simple_filter::tb3f98ea670610d40658a618de3ec7b90 id_215 { id_214.readU8() };
                    bool let_res_216;
                    {
                      ::dessser::gen::simple_filter::tb3f98ea670610d40658a618de3ec7b90 leb128_77 { id_215 };
                      bool letpair_res_217;
                      {
                        auto leb128_fst_78 { std::get<0>(leb128_77) };
                        auto leb128_snd_79 { std::get<1>(leb128_77) };
                        uint8_t id_218 { 0 };
                        Void id_219 { ((void)(p_ref_76[id_218] = leb128_snd_79), VOID) };
                        (void)id_219;
                        uint8_t id_220 { 0 };
                        uint8_t id_221 { 127 };
                        uint8_t id_222 { uint8_t(leb128_fst_78 & id_221) };
                        uint32_t id_223 { uint32_t(id_222) };
                        uint8_t id_224 { 0 };
                        uint8_t id_225 { shft_ref_75[id_224] };
                        uint32_t id_226 { uint32_t(id_223 << id_225) };
                        uint8_t id_227 { 0 };
                        uint32_t id_228 { leb_ref_74[id_227] };
                        uint32_t id_229 { uint32_t(id_226 | id_228) };
                        Void id_230 { ((void)(leb_ref_74[id_220] = id_229), VOID) };
                        (void)id_230;
                        uint8_t id_231 { 0 };
                        uint8_t id_232 { 0 };
                        uint8_t id_233 { shft_ref_75[id_232] };
                        uint8_t id_234 { 7 };
                        uint8_t id_235 { uint8_t(id_233 + id_234) };
                        Void id_236 { ((void)(shft_ref_75[id_231] = id_235), VOID) };
                        (void)id_236;
                        uint8_t id_237 { 128 };
                        bool id_238 { bool(leb128_fst_78 >= id_237) };
                        letpair_res_217 = id_238;
                      }
                      let_res_216 = letpair_res_217;
                    }
                    while_flag_212 = let_res_216;
                    if (while_flag_212) {
                      (void)VOID;
                    }
                  } while (while_flag_212);
                  (void)VOID;
                  uint8_t id_239 { 0 };
                  uint32_t id_240 { leb_ref_74[id_239] };
                  Size id_241 { Size(id_240) };
                  uint8_t id_242 { 0 };
                  Pointer id_243 { p_ref_76[id_242] };
                  ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c id_244 { id_241, id_243 };
                  let_res_211 = id_244;
                }
                let_res_209 = let_res_211;
              }
              let_res_206 = let_res_209;
            }
            ::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe let_res_245;
            {
              ::dessser::gen::simple_filter::t8beb80162423aee37bd383e9b6834c9c dstring1_80 { let_res_206 };
              ::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe letpair_res_246;
              {
                auto dstring1_fst_81 { std::get<0>(dstring1_80) };
                auto dstring1_snd_82 { std::get<1>(dstring1_80) };
                ::dessser::gen::simple_filter::t188345aa49abd0cb47ff73fedc219f08 id_247 { dstring1_snd_82.readBytes(dstring1_fst_81) };
                ::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe letpair_res_248;
                {
                  auto dstring2_fst_84 { std::get<0>(id_247) };
                  auto dstring2_snd_85 { std::get<1>(id_247) };
                  std::string id_249 { dstring2_fst_84.toString() };
                  ::dessser::gen::simple_filter::t* id_250 { new ::dessser::gen::simple_filter::t({ .lhs = drec_fst_57, .op = id_249, .rhs = drec_fst_72 }) };
                  ::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe id_251 { id_250, dstring2_snd_85 };
                  letpair_res_248 = id_251;
                }
                letpair_res_246 = letpair_res_248;
              }
              let_res_245 = letpair_res_246;
            }
            letpair_res_203 = let_res_245;
          }
          let_res_202 = letpair_res_203;
        }
        letpair_res_154 = let_res_202;
      }
      let_res_153 = letpair_res_154;
    }
    return let_res_153;
  }
   };
  return fun150;
}
std::function<::dessser::gen::simple_filter::t5ec462bd9f9d5a838e7e865b5af804fe(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
