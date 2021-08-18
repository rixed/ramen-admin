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
#include "desssergen/fq_function_name.h"


namespace dessser::gen::replay_request {
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
  dessser::gen::fq_function_name::t_ext target;
  double since;
  double until;
  bool explain;
  std::string resp_key;
  bool operator==(t const &other) const {
    return target == other.target && since == other.since && until == other.until && explain == other.explain && resp_key == other.resp_key;
  }
};
typedef std::tuple<
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

typedef std::tuple<
  dessser::gen::fq_function_name::t_ext,
  Pointer
> taa97936972d3c557dfc41dd27d2203f0;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

typedef std::tuple<
  double,
  Pointer
> taebed00ad7fdb3f7ced11d3cfd58aade;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  bool,
  Pointer
> t4138de986e20d18b01e4c493dc9d5451;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{target: $fq_function_name; since: FLOAT; until: FLOAT; explain: BOOL; resp_key: STRING}" "Ptr")
      (let "srec_dst_106"
        (let "srec_dst_105"
          (let "srec_dst_104"
            (let "srec_dst_103" (apply (ext-identifier fq_function_name to-row-binary) (get-field "target" (param 0)) (param 1)) (write-u64 little-endian (identifier "srec_dst_103") (u64-of-float (get-field "since" (param 0)))))
            (write-u64 little-endian (identifier "srec_dst_104") (u64-of-float (get-field "until" (param 0))))) 
          (write-u8 (identifier "srec_dst_105") (u8-of-bool (get-field "explain" (param 0)))))
        (write-bytes
          (let "leb128_sz_107" (make-vec (string-length (get-field "resp_key" (param 0))))
            (let "leb128_ptr_108" (make-vec (identifier "srec_dst_106"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_108")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_108"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_107"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_107"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_107"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_107") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_107")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_107")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_108"))))) 
          (bytes-of-string (get-field "resp_key" (param 0))))))
 */
static std::function<Pointer(t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t*,Pointer)> fun0 { [&fun0](t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::fq_function_name::to_row_binary };
    dessser::gen::fq_function_name::t_ext id_2 { p_0->target };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_103 { id_3 };
      double id_5 { p_0->since };
      uint64_t id_6 { qword_of_float(id_5) };
      Pointer id_7 { srec_dst_103.writeU64Le(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_104 { let_res_4 };
      double id_9 { p_0->until };
      uint64_t id_10 { qword_of_float(id_9) };
      Pointer id_11 { srec_dst_104.writeU64Le(id_10) };
      let_res_8 = id_11;
    }
    Pointer let_res_12;
    {
      Pointer srec_dst_105 { let_res_8 };
      bool id_13 { p_0->explain };
      uint8_t id_14 { uint8_t(id_13) };
      Pointer id_15 { srec_dst_105.writeU8(id_14) };
      let_res_12 = id_15;
    }
    Pointer let_res_16;
    {
      Pointer srec_dst_106 { let_res_12 };
      std::string id_17 { p_0->resp_key };
      uint32_t id_18 { (uint32_t)id_17.size() };
      Vec<1, uint32_t> id_19 {  id_18  };
      Pointer let_res_20;
      {
        Vec<1, uint32_t> leb128_sz_107 { id_19 };
        Vec<1, Pointer> id_21 {  srec_dst_106  };
        Pointer let_res_22;
        {
          Vec<1, Pointer> leb128_ptr_108 { id_21 };
          bool while_flag_23 { true };
          do {
            uint8_t id_24 { 0 };
            uint8_t id_25 { 0 };
            Pointer id_26 { leb128_ptr_108[id_25] };
            uint32_t id_27 { 128U };
            uint8_t id_28 { 0 };
            uint32_t id_29 { leb128_sz_107[id_28] };
            bool id_30 { bool(id_27 > id_29) };
            uint8_t choose_res_31;
            if (id_30) {
              uint8_t id_32 { 0 };
              uint32_t id_33 { leb128_sz_107[id_32] };
              uint8_t id_34 { uint8_t(id_33) };
              choose_res_31 = id_34;
            } else {
              uint8_t id_35 { 0 };
              uint32_t id_36 { leb128_sz_107[id_35] };
              uint8_t id_37 { uint8_t(id_36) };
              uint8_t id_38 { 128 };
              uint8_t id_39 { uint8_t(id_37 | id_38) };
              choose_res_31 = id_39;
            }
            Pointer id_40 { id_26.writeU8(choose_res_31) };
            Void id_41 { ((void)(leb128_ptr_108[id_24] = id_40), VOID) };
            (void)id_41;
            uint8_t id_42 { 0 };
            uint8_t id_43 { 0 };
            uint32_t id_44 { leb128_sz_107[id_43] };
            uint8_t id_45 { 7 };
            uint32_t id_46 { uint32_t(id_44 >> id_45) };
            Void id_47 { ((void)(leb128_sz_107[id_42] = id_46), VOID) };
            (void)id_47;
            uint8_t id_48 { 0 };
            uint32_t id_49 { leb128_sz_107[id_48] };
            uint32_t id_50 { 0U };
            bool id_51 { bool(id_49 > id_50) };
            while_flag_23 = id_51;
            if (while_flag_23) {
              (void)VOID;
            }
          } while (while_flag_23);
          (void)VOID;
          uint8_t id_52 { 0 };
          Pointer id_53 { leb128_ptr_108[id_52] };
          let_res_22 = id_53;
        }
        let_res_20 = let_res_22;
      }
      std::string id_54 { p_0->resp_key };
      Bytes id_55 { id_54 };
      Pointer id_56 { let_res_20.writeBytes(id_55) };
      let_res_16 = id_56;
    }
    return let_res_16;
  }
   };
  return fun0;
}
std::function<Pointer(t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{target: $fq_function_name; since: FLOAT; until: FLOAT; explain: BOOL; resp_key: STRING}")
      (let "sz_99" (add (add (add (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-field "target" (param 0))) (size 8)) (size 8)) (size 1))
        (add (identifier "sz_99")
          (add
            (let "n_ref_101" (make-vec (string-length (get-field "resp_key" (param 0))))
              (let "lebsz_ref_102" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_101")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_102")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_102") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_102")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_102")))))) 
            (size-of-u32 (string-length (get-field "resp_key" (param 0))))))))
 */
static std::function<Size(t*)> sersize_of_row_binary_init()
{
  std::function<Size(t*)> fun57 { [&fun57](t* p_0) {
    auto fun58 { dessser::gen::fq_function_name::sersize_of_row_binary };
    dessser::gen::fq_function_name::t_ext id_59 { p_0->target };
    Size id_60 { fun58(id_59) };
    Size id_61 { 8UL };
    Size id_62 { Size(id_60 + id_61) };
    Size id_63 { 8UL };
    Size id_64 { Size(id_62 + id_63) };
    Size id_65 { 1UL };
    Size id_66 { Size(id_64 + id_65) };
    Size let_res_67;
    {
      Size sz_99 { id_66 };
      std::string id_68 { p_0->resp_key };
      uint32_t id_69 { (uint32_t)id_68.size() };
      Vec<1, uint32_t> id_70 {  id_69  };
      Size let_res_71;
      {
        Vec<1, uint32_t> n_ref_101 { id_70 };
        uint32_t id_72 { 1U };
        Vec<1, uint32_t> id_73 {  id_72  };
        Size let_res_74;
        {
          Vec<1, uint32_t> lebsz_ref_102 { id_73 };
          bool while_flag_75 { true };
          do {
            uint8_t id_76 { 0 };
            uint32_t id_77 { n_ref_101[id_76] };
            uint8_t id_78 { 0 };
            uint32_t id_79 { lebsz_ref_102[id_78] };
            uint8_t id_80 { 7 };
            uint32_t id_81 { uint32_t(id_79 << id_80) };
            bool id_82 { bool(id_77 >= id_81) };
            while_flag_75 = id_82;
            if (while_flag_75) {
              uint8_t id_83 { 0 };
              uint8_t id_84 { 0 };
              uint32_t id_85 { lebsz_ref_102[id_84] };
              uint32_t id_86 { 1U };
              uint32_t id_87 { uint32_t(id_85 + id_86) };
              Void id_88 { ((void)(lebsz_ref_102[id_83] = id_87), VOID) };
              (void)id_88;
            }
          } while (while_flag_75);
          (void)VOID;
          uint8_t id_89 { 0 };
          uint32_t id_90 { lebsz_ref_102[id_89] };
          Size id_91 { Size(id_90) };
          let_res_74 = id_91;
        }
        let_res_71 = let_res_74;
      }
      std::string id_92 { p_0->resp_key };
      uint32_t id_93 { (uint32_t)id_92.size() };
      Size id_94 { Size(id_93) };
      Size id_95 { Size(let_res_71 + id_94) };
      Size id_96 { Size(sz_99 + id_95) };
      let_res_67 = id_96;
    }
    return let_res_67;
  }
   };
  return fun57;
}
std::function<Size(t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier fq_function_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_62" (let-pair "dfloat_fst_60" "dfloat_snd_61" (read-u64 little-endian (identifier "drec_snd_58")) (make-tup (float-of-u64 (identifier "dfloat_fst_60")) (identifier "dfloat_snd_61")))
            (let-pair "drec_fst_63" "drec_snd_64" (identifier "drec_62")
              (let "drec_68" (let-pair "dfloat_fst_66" "dfloat_snd_67" (read-u64 little-endian (identifier "drec_snd_64")) (make-tup (float-of-u64 (identifier "dfloat_fst_66")) (identifier "dfloat_snd_67")))
                (let-pair "drec_fst_69" "drec_snd_70" (identifier "drec_68")
                  (let "drec_74" (let-pair "dbool_fst_72" "dbool_snd_73" (read-u8 (identifier "drec_snd_70")) (make-tup (not (eq (identifier "dbool_fst_72") (u8 0))) (identifier "dbool_snd_73")))
                    (let-pair "drec_fst_75" "drec_snd_76" (identifier "drec_74")
                      (let "dstring1_83"
                        (let "leb_ref_77" (make-vec (u32 0))
                          (let "shft_ref_78" (make-vec (u8 0))
                            (let "p_ref_79" (make-vec (identifier "drec_snd_76"))
                              (seq
                                (while
                                  (let "leb128_80" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_79")))
                                    (let-pair "leb128_fst_81" "leb128_snd_82" 
                                      (identifier "leb128_80")
                                      (seq (set-vec (u8 0) (identifier "p_ref_79") (identifier "leb128_snd_82"))
                                        (set-vec (u8 0) (identifier "leb_ref_77")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_81") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_78"))) (unsafe-nth (u8 0) (identifier "leb_ref_77"))))
                                        (set-vec (u8 0) (identifier "shft_ref_78") (add (unsafe-nth (u8 0) (identifier "shft_ref_78")) (u8 7))) 
                                        (ge (identifier "leb128_fst_81") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_77"))) (unsafe-nth (u8 0) (identifier "p_ref_79")))))))
                        (let-pair "dstring1_fst_84" "dstring1_snd_85" 
                          (identifier "dstring1_83")
                          (let-pair "dstring2_fst_87" "dstring2_snd_88" 
                            (read-bytes (identifier "dstring1_snd_85") (identifier "dstring1_fst_84"))
                            (make-tup
                              (make-rec (string "target") (identifier "drec_fst_57") 
                                (string "since") (identifier "drec_fst_63") 
                                (string "until") (identifier "drec_fst_69") 
                                (string "explain") (identifier "drec_fst_75") 
                                (string "resp_key") (string-of-bytes (identifier "dstring2_fst_87"))) 
                              (identifier "dstring2_snd_88"))))))))))))))
 */
static std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary_init()
{
  std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> fun97 { [&fun97](Pointer p_0) {
    auto fun98 { dessser::gen::fq_function_name::of_row_binary };
    taa97936972d3c557dfc41dd27d2203f0 id_99 { fun98(p_0) };
    t45217dce3db5a9a49037839afd0048e8 let_res_100;
    {
      taa97936972d3c557dfc41dd27d2203f0 drec_56 { id_99 };
      t45217dce3db5a9a49037839afd0048e8 letpair_res_101;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        t7a47220550fc5126a7b79f1e0c10c645 id_102 { drec_snd_58.readU64Le() };
        taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_103;
        {
          auto dfloat_fst_60 { std::get<0>(id_102) };
          auto dfloat_snd_61 { std::get<1>(id_102) };
          double id_104 { float_of_qword(dfloat_fst_60) };
          taebed00ad7fdb3f7ced11d3cfd58aade id_105 { id_104, dfloat_snd_61 };
          letpair_res_103 = id_105;
        }
        t45217dce3db5a9a49037839afd0048e8 let_res_106;
        {
          taebed00ad7fdb3f7ced11d3cfd58aade drec_62 { letpair_res_103 };
          t45217dce3db5a9a49037839afd0048e8 letpair_res_107;
          {
            auto drec_fst_63 { std::get<0>(drec_62) };
            auto drec_snd_64 { std::get<1>(drec_62) };
            t7a47220550fc5126a7b79f1e0c10c645 id_108 { drec_snd_64.readU64Le() };
            taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_109;
            {
              auto dfloat_fst_66 { std::get<0>(id_108) };
              auto dfloat_snd_67 { std::get<1>(id_108) };
              double id_110 { float_of_qword(dfloat_fst_66) };
              taebed00ad7fdb3f7ced11d3cfd58aade id_111 { id_110, dfloat_snd_67 };
              letpair_res_109 = id_111;
            }
            t45217dce3db5a9a49037839afd0048e8 let_res_112;
            {
              taebed00ad7fdb3f7ced11d3cfd58aade drec_68 { letpair_res_109 };
              t45217dce3db5a9a49037839afd0048e8 letpair_res_113;
              {
                auto drec_fst_69 { std::get<0>(drec_68) };
                auto drec_snd_70 { std::get<1>(drec_68) };
                tb3f98ea670610d40658a618de3ec7b90 id_114 { drec_snd_70.readU8() };
                t4138de986e20d18b01e4c493dc9d5451 letpair_res_115;
                {
                  auto dbool_fst_72 { std::get<0>(id_114) };
                  auto dbool_snd_73 { std::get<1>(id_114) };
                  uint8_t id_116 { 0 };
                  bool id_117 { bool(dbool_fst_72 == id_116) };
                  bool id_118 { ! id_117 };
                  t4138de986e20d18b01e4c493dc9d5451 id_119 { id_118, dbool_snd_73 };
                  letpair_res_115 = id_119;
                }
                t45217dce3db5a9a49037839afd0048e8 let_res_120;
                {
                  t4138de986e20d18b01e4c493dc9d5451 drec_74 { letpair_res_115 };
                  t45217dce3db5a9a49037839afd0048e8 letpair_res_121;
                  {
                    auto drec_fst_75 { std::get<0>(drec_74) };
                    auto drec_snd_76 { std::get<1>(drec_74) };
                    uint32_t id_122 { 0U };
                    Vec<1, uint32_t> id_123 {  id_122  };
                    t8beb80162423aee37bd383e9b6834c9c let_res_124;
                    {
                      Vec<1, uint32_t> leb_ref_77 { id_123 };
                      uint8_t id_125 { 0 };
                      Vec<1, uint8_t> id_126 {  id_125  };
                      t8beb80162423aee37bd383e9b6834c9c let_res_127;
                      {
                        Vec<1, uint8_t> shft_ref_78 { id_126 };
                        Vec<1, Pointer> id_128 {  drec_snd_76  };
                        t8beb80162423aee37bd383e9b6834c9c let_res_129;
                        {
                          Vec<1, Pointer> p_ref_79 { id_128 };
                          bool while_flag_130 { true };
                          do {
                            uint8_t id_131 { 0 };
                            Pointer id_132 { p_ref_79[id_131] };
                            tb3f98ea670610d40658a618de3ec7b90 id_133 { id_132.readU8() };
                            bool let_res_134;
                            {
                              tb3f98ea670610d40658a618de3ec7b90 leb128_80 { id_133 };
                              bool letpair_res_135;
                              {
                                auto leb128_fst_81 { std::get<0>(leb128_80) };
                                auto leb128_snd_82 { std::get<1>(leb128_80) };
                                uint8_t id_136 { 0 };
                                Void id_137 { ((void)(p_ref_79[id_136] = leb128_snd_82), VOID) };
                                (void)id_137;
                                uint8_t id_138 { 0 };
                                uint8_t id_139 { 127 };
                                uint8_t id_140 { uint8_t(leb128_fst_81 & id_139) };
                                uint32_t id_141 { uint32_t(id_140) };
                                uint8_t id_142 { 0 };
                                uint8_t id_143 { shft_ref_78[id_142] };
                                uint32_t id_144 { uint32_t(id_141 << id_143) };
                                uint8_t id_145 { 0 };
                                uint32_t id_146 { leb_ref_77[id_145] };
                                uint32_t id_147 { uint32_t(id_144 | id_146) };
                                Void id_148 { ((void)(leb_ref_77[id_138] = id_147), VOID) };
                                (void)id_148;
                                uint8_t id_149 { 0 };
                                uint8_t id_150 { 0 };
                                uint8_t id_151 { shft_ref_78[id_150] };
                                uint8_t id_152 { 7 };
                                uint8_t id_153 { uint8_t(id_151 + id_152) };
                                Void id_154 { ((void)(shft_ref_78[id_149] = id_153), VOID) };
                                (void)id_154;
                                uint8_t id_155 { 128 };
                                bool id_156 { bool(leb128_fst_81 >= id_155) };
                                letpair_res_135 = id_156;
                              }
                              let_res_134 = letpair_res_135;
                            }
                            while_flag_130 = let_res_134;
                            if (while_flag_130) {
                              (void)VOID;
                            }
                          } while (while_flag_130);
                          (void)VOID;
                          uint8_t id_157 { 0 };
                          uint32_t id_158 { leb_ref_77[id_157] };
                          Size id_159 { Size(id_158) };
                          uint8_t id_160 { 0 };
                          Pointer id_161 { p_ref_79[id_160] };
                          t8beb80162423aee37bd383e9b6834c9c id_162 { id_159, id_161 };
                          let_res_129 = id_162;
                        }
                        let_res_127 = let_res_129;
                      }
                      let_res_124 = let_res_127;
                    }
                    t45217dce3db5a9a49037839afd0048e8 let_res_163;
                    {
                      t8beb80162423aee37bd383e9b6834c9c dstring1_83 { let_res_124 };
                      t45217dce3db5a9a49037839afd0048e8 letpair_res_164;
                      {
                        auto dstring1_fst_84 { std::get<0>(dstring1_83) };
                        auto dstring1_snd_85 { std::get<1>(dstring1_83) };
                        t188345aa49abd0cb47ff73fedc219f08 id_165 { dstring1_snd_85.readBytes(dstring1_fst_84) };
                        t45217dce3db5a9a49037839afd0048e8 letpair_res_166;
                        {
                          auto dstring2_fst_87 { std::get<0>(id_165) };
                          auto dstring2_snd_88 { std::get<1>(id_165) };
                          std::string id_167 { dstring2_fst_87.toString() };
                          t* id_168 { new t({ .target = drec_fst_57, .since = drec_fst_63, .until = drec_fst_69, .explain = drec_fst_75, .resp_key = id_167 }) };
                          t45217dce3db5a9a49037839afd0048e8 id_169 { id_168, dstring2_snd_88 };
                          letpair_res_166 = id_169;
                        }
                        letpair_res_164 = letpair_res_166;
                      }
                      let_res_163 = letpair_res_164;
                    }
                    letpair_res_121 = let_res_163;
                  }
                  let_res_120 = letpair_res_121;
                }
                letpair_res_113 = let_res_120;
              }
              let_res_112 = letpair_res_113;
            }
            letpair_res_107 = let_res_112;
          }
          let_res_106 = letpair_res_107;
        }
        letpair_res_101 = let_res_106;
      }
      let_res_100 = letpair_res_101;
    }
    return let_res_100;
  }
   };
  return fun97;
}
std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
