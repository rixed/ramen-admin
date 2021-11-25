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
#include "desssergen/raql_variable.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_variable.h"

namespace dessser::gen::raql_binding_key {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t40f56917851bc62b1c9e1a72700c3bed : public std::tuple<
  dessser::gen::raql_variable::t_ext,
  dessser::gen::field_name::t_ext
> {
  using tuple::tuple;
  t40f56917851bc62b1c9e1a72700c3bed(std::tuple<dessser::gen::raql_variable::t_ext, dessser::gen::field_name::t_ext> p)
    : std::tuple<dessser::gen::raql_variable::t_ext, dessser::gen::field_name::t_ext>(std::get<0>(p), std::get<1>(p)) {}
};
struct t : public std::variant<
  uint32_t, // State
  ::dessser::gen::raql_binding_key::t40f56917851bc62b1c9e1a72700c3bed, // RecordField
  dessser::gen::raql_variable::t_ext, // RecordValue
  std::string // Direct
> { using variant::variant; };

struct tb153335fc05f1eec6819ab87a88b916a : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_binding_key::t> ,
  Pointer
> {
  using tuple::tuple;
  tb153335fc05f1eec6819ab87a88b916a(std::tuple<std::shared_ptr<::dessser::gen::raql_binding_key::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_binding_key::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t8b22e447956958a21d977c854a5cd7c0 : public std::tuple<
  dessser::gen::raql_variable::t_ext,
  Pointer
> {
  using tuple::tuple;
  t8b22e447956958a21d977c854a5cd7c0(std::tuple<dessser::gen::raql_variable::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_variable::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tacdfdbd490062d58073ca57b70932e6d : public std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tacdfdbd490062d58073ca57b70932e6d(std::tuple<dessser::gen::field_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::field_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[State U32 | RecordField ($raql_variable; $field_name) | RecordValue $raql_variable | Direct STRING]" "Ptr")
      (let "ssum_dst_108" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (write-u32 little-endian (identifier "ssum_dst_108") (get-alt "State" (param 0)))
          (if (eq (u16 1) (label-of (param 0)))
            (let "stup_dst_111" (apply (ext-identifier raql_variable to-row-binary) (get-item 0 (get-alt "RecordField" (param 0))) (identifier "ssum_dst_108"))
              (apply (ext-identifier field_name to-row-binary) (get-item 1 (get-alt "RecordField" (param 0))) (identifier "stup_dst_111")))
            (if (eq (u16 2) (label-of (param 0))) (apply (ext-identifier raql_variable to-row-binary) (get-alt "RecordValue" (param 0)) (identifier "ssum_dst_108"))
              (seq (assert (eq (label-of (param 0)) (u16 3)))
                (write-bytes
                  (let "leb128_sz_109" (make-vec (string-length (get-alt "Direct" (param 0))))
                    (let "leb128_ptr_110" (make-vec (identifier "ssum_dst_108"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_110")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_110"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_109"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_109"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_109"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_109") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_109")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_109")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_110"))))) 
                  (bytes-of-string (get-alt "Direct" (param 0))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_binding_key::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_binding_key::t> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::raql_binding_key::t>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_108 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        uint32_t id_8 { std::get<0 /* State */>((*p_0)) };
        Pointer id_9 { ssum_dst_108.writeU32Le(id_8) };
        choose_res_7 = id_9;
      } else {
        uint16_t id_10 { 1 };
        uint16_t id_11 { uint16_t((*p_0).index()) };
        bool id_12 { bool(id_10 == id_11) };
        Pointer choose_res_13;
        if (id_12) {
          auto fun14 { dessser::gen::raql_variable::to_row_binary };
          ::dessser::gen::raql_binding_key::t40f56917851bc62b1c9e1a72700c3bed id_15 { std::get<1 /* RecordField */>((*p_0)) };
          dessser::gen::raql_variable::t_ext id_16 { std::get<0>(id_15) };
          Pointer id_17 { fun14(id_16, ssum_dst_108) };
          Pointer let_res_18;
          {
            Pointer stup_dst_111 { id_17 };
            auto fun19 { dessser::gen::field_name::to_row_binary };
            ::dessser::gen::raql_binding_key::t40f56917851bc62b1c9e1a72700c3bed id_20 { std::get<1 /* RecordField */>((*p_0)) };
            dessser::gen::field_name::t_ext id_21 { std::get<1>(id_20) };
            Pointer id_22 { fun19(id_21, stup_dst_111) };
            let_res_18 = id_22;
          }
          choose_res_13 = let_res_18;
        } else {
          uint16_t id_23 { 2 };
          uint16_t id_24 { uint16_t((*p_0).index()) };
          bool id_25 { bool(id_23 == id_24) };
          Pointer choose_res_26;
          if (id_25) {
            auto fun27 { dessser::gen::raql_variable::to_row_binary };
            dessser::gen::raql_variable::t_ext id_28 { std::get<2 /* RecordValue */>((*p_0)) };
            Pointer id_29 { fun27(id_28, ssum_dst_108) };
            choose_res_26 = id_29;
          } else {
            uint16_t id_30 { uint16_t((*p_0).index()) };
            uint16_t id_31 { 3 };
            bool id_32 { bool(id_30 == id_31) };
            Void id_33 { ((void)(assert(id_32)), ::dessser::VOID) };
            (void)id_33;
            std::string id_34 { std::get<3 /* Direct */>((*p_0)) };
            uint32_t id_35 { (uint32_t)id_34.size() };
            Vec<1, uint32_t> id_36 {  id_35  };
            Pointer let_res_37;
            {
              Vec<1, uint32_t> leb128_sz_109 { id_36 };
              Vec<1, Pointer> id_38 {  ssum_dst_108  };
              Pointer let_res_39;
              {
                Vec<1, Pointer> leb128_ptr_110 { id_38 };
                bool while_flag_40 { true };
                do {
                  uint8_t id_41 { 0 };
                  uint8_t id_42 { 0 };
                  Pointer id_43 { leb128_ptr_110[id_42] };
                  uint32_t id_44 { 128U };
                  uint8_t id_45 { 0 };
                  uint32_t id_46 { leb128_sz_109[id_45] };
                  bool id_47 { bool(id_44 > id_46) };
                  uint8_t choose_res_48;
                  if (id_47) {
                    uint8_t id_49 { 0 };
                    uint32_t id_50 { leb128_sz_109[id_49] };
                    uint8_t id_51 { uint8_t(id_50) };
                    choose_res_48 = id_51;
                  } else {
                    uint8_t id_52 { 0 };
                    uint32_t id_53 { leb128_sz_109[id_52] };
                    uint8_t id_54 { uint8_t(id_53) };
                    uint8_t id_55 { 128 };
                    uint8_t id_56 { uint8_t(id_54 | id_55) };
                    choose_res_48 = id_56;
                  }
                  Pointer id_57 { id_43.writeU8(choose_res_48) };
                  Void id_58 { ((void)(leb128_ptr_110[id_41] = id_57), ::dessser::VOID) };
                  (void)id_58;
                  uint8_t id_59 { 0 };
                  uint8_t id_60 { 0 };
                  uint32_t id_61 { leb128_sz_109[id_60] };
                  uint8_t id_62 { 7 };
                  uint32_t id_63 { uint32_t(id_61 >> id_62) };
                  Void id_64 { ((void)(leb128_sz_109[id_59] = id_63), ::dessser::VOID) };
                  (void)id_64;
                  uint8_t id_65 { 0 };
                  uint32_t id_66 { leb128_sz_109[id_65] };
                  uint32_t id_67 { 0U };
                  bool id_68 { bool(id_66 > id_67) };
                  while_flag_40 = id_68;
                  if (while_flag_40) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_40);
                (void)::dessser::VOID;
                uint8_t id_69 { 0 };
                Pointer id_70 { leb128_ptr_110[id_69] };
                let_res_39 = id_70;
              }
              let_res_37 = let_res_39;
            }
            std::string id_71 { std::get<3 /* Direct */>((*p_0)) };
            Bytes id_72 { id_71 };
            Pointer id_73 { let_res_37.writeBytes(id_72) };
            choose_res_26 = id_73;
          }
          choose_res_13 = choose_res_26;
        }
        choose_res_7 = choose_res_13;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_binding_key::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[State U32 | RecordField ($raql_variable; $field_name) | RecordValue $raql_variable | Direct STRING]")
      (if (eq (u16 0) (label-of (param 0))) (size 6)
        (if (eq (u16 1) (label-of (param 0)))
          (let "sz_106" (add (size 2) (apply (ext-identifier raql_variable sersize-of-row-binary) (get-item 0 (get-alt "RecordField" (param 0)))))
            (add (identifier "sz_106") (apply (ext-identifier field_name sersize-of-row-binary) (get-item 1 (get-alt "RecordField" (param 0))))))
          (if (eq (u16 2) (label-of (param 0))) (add (size 2) (apply (ext-identifier raql_variable sersize-of-row-binary) (get-alt "RecordValue" (param 0))))
            (seq (assert (eq (label-of (param 0)) (u16 3)))
              (add (size 2)
                (add
                  (let "n_ref_103" (make-vec (string-length (get-alt "Direct" (param 0))))
                    (let "lebsz_ref_104" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_103")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_104")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_104") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_104")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_104")))))) 
                  (size-of-u32 (string-length (get-alt "Direct" (param 0)))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_binding_key::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_binding_key::t> )> fun74 { [&fun74](std::shared_ptr<::dessser::gen::raql_binding_key::t>  p_0) {
    uint16_t id_75 { 0 };
    uint16_t id_76 { uint16_t((*p_0).index()) };
    bool id_77 { bool(id_75 == id_76) };
    Size choose_res_78;
    if (id_77) {
      Size id_79 { 6UL };
      choose_res_78 = id_79;
    } else {
      uint16_t id_80 { 1 };
      uint16_t id_81 { uint16_t((*p_0).index()) };
      bool id_82 { bool(id_80 == id_81) };
      Size choose_res_83;
      if (id_82) {
        Size id_84 { 2UL };
        auto fun85 { dessser::gen::raql_variable::sersize_of_row_binary };
        ::dessser::gen::raql_binding_key::t40f56917851bc62b1c9e1a72700c3bed id_86 { std::get<1 /* RecordField */>((*p_0)) };
        dessser::gen::raql_variable::t_ext id_87 { std::get<0>(id_86) };
        Size id_88 { fun85(id_87) };
        Size id_89 { Size(id_84 + id_88) };
        Size let_res_90;
        {
          Size sz_106 { id_89 };
          auto fun91 { dessser::gen::field_name::sersize_of_row_binary };
          ::dessser::gen::raql_binding_key::t40f56917851bc62b1c9e1a72700c3bed id_92 { std::get<1 /* RecordField */>((*p_0)) };
          dessser::gen::field_name::t_ext id_93 { std::get<1>(id_92) };
          Size id_94 { fun91(id_93) };
          Size id_95 { Size(sz_106 + id_94) };
          let_res_90 = id_95;
        }
        choose_res_83 = let_res_90;
      } else {
        uint16_t id_96 { 2 };
        uint16_t id_97 { uint16_t((*p_0).index()) };
        bool id_98 { bool(id_96 == id_97) };
        Size choose_res_99;
        if (id_98) {
          Size id_100 { 2UL };
          auto fun101 { dessser::gen::raql_variable::sersize_of_row_binary };
          dessser::gen::raql_variable::t_ext id_102 { std::get<2 /* RecordValue */>((*p_0)) };
          Size id_103 { fun101(id_102) };
          Size id_104 { Size(id_100 + id_103) };
          choose_res_99 = id_104;
        } else {
          uint16_t id_105 { uint16_t((*p_0).index()) };
          uint16_t id_106 { 3 };
          bool id_107 { bool(id_105 == id_106) };
          Void id_108 { ((void)(assert(id_107)), ::dessser::VOID) };
          (void)id_108;
          Size id_109 { 2UL };
          std::string id_110 { std::get<3 /* Direct */>((*p_0)) };
          uint32_t id_111 { (uint32_t)id_110.size() };
          Vec<1, uint32_t> id_112 {  id_111  };
          Size let_res_113;
          {
            Vec<1, uint32_t> n_ref_103 { id_112 };
            uint32_t id_114 { 1U };
            Vec<1, uint32_t> id_115 {  id_114  };
            Size let_res_116;
            {
              Vec<1, uint32_t> lebsz_ref_104 { id_115 };
              bool while_flag_117 { true };
              do {
                uint8_t id_118 { 0 };
                uint32_t id_119 { n_ref_103[id_118] };
                uint8_t id_120 { 0 };
                uint32_t id_121 { lebsz_ref_104[id_120] };
                uint8_t id_122 { 7 };
                uint32_t id_123 { uint32_t(id_121 << id_122) };
                bool id_124 { bool(id_119 >= id_123) };
                while_flag_117 = id_124;
                if (while_flag_117) {
                  uint8_t id_125 { 0 };
                  uint8_t id_126 { 0 };
                  uint32_t id_127 { lebsz_ref_104[id_126] };
                  uint32_t id_128 { 1U };
                  uint32_t id_129 { uint32_t(id_127 + id_128) };
                  Void id_130 { ((void)(lebsz_ref_104[id_125] = id_129), ::dessser::VOID) };
                  (void)id_130;
                }
              } while (while_flag_117);
              (void)::dessser::VOID;
              uint8_t id_131 { 0 };
              uint32_t id_132 { lebsz_ref_104[id_131] };
              Size id_133 { Size(id_132) };
              let_res_116 = id_133;
            }
            let_res_113 = let_res_116;
          }
          std::string id_134 { std::get<3 /* Direct */>((*p_0)) };
          uint32_t id_135 { (uint32_t)id_134.size() };
          Size id_136 { Size(id_135) };
          Size id_137 { Size(let_res_113 + id_136) };
          Size id_138 { Size(id_109 + id_137) };
          choose_res_99 = id_138;
        }
        choose_res_83 = choose_res_99;
      }
      choose_res_78 = choose_res_83;
    }
    return choose_res_78;
  }
   };
  return fun74;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_binding_key::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_99" "make_snd_100"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let-pair "du32_fst_93" "du32_snd_94" (read-u32 little-endian (identifier "dsum1_snd_64"))
                (make-tup (construct "[State U32 | RecordField ($raql_variable; $field_name) | RecordValue $raql_variable | Direct STRING]" 0 (identifier "du32_fst_93")) (identifier "du32_snd_94")))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let "dtup_83" (apply (ext-identifier raql_variable of-row-binary) (identifier "dsum1_snd_64"))
                  (let-pair "dtup_fst_84" "dtup_snd_85" (identifier "dtup_83")
                    (let-pair "dtup_fst_87" "dtup_snd_88" (apply (ext-identifier field_name of-row-binary) (identifier "dtup_snd_85"))
                      (make-tup (construct "[State U32 | RecordField ($raql_variable; $field_name) | RecordValue $raql_variable | Direct STRING]" 1 (make-tup (identifier "dtup_fst_84") (identifier "dtup_fst_87")))
                        (identifier "dtup_snd_88")))))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (let-pair "dsum2_fst_81" "dsum2_snd_82" (apply (ext-identifier raql_variable of-row-binary) (identifier "dsum1_snd_64"))
                    (make-tup (construct "[State U32 | RecordField ($raql_variable; $field_name) | RecordValue $raql_variable | Direct STRING]" 2 (identifier "dsum2_fst_81")) (identifier "dsum2_snd_82")))
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
                          (make-tup (construct "[State U32 | RecordField ($raql_variable; $field_name) | RecordValue $raql_variable | Direct STRING]" 3 (string-of-bytes (identifier "dstring2_fst_75")))
                            (identifier "dstring2_snd_76"))))))))))) 
        (make-tup (identifier "make_fst_99") (identifier "make_snd_100"))))
 */
static std::function<::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a(Pointer)> fun139 { [&fun139](Pointer p_0) {
    ::dessser::gen::raql_binding_key::t7609d344c1ba69d0f80fec236d4c216b id_140 { p_0.readU16Le() };
    ::dessser::gen::raql_binding_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_141;
    {
      auto du16_fst_57 { std::get<0>(id_140) };
      auto du16_snd_58 { std::get<1>(id_140) };
      ::dessser::gen::raql_binding_key::t7609d344c1ba69d0f80fec236d4c216b id_142 { du16_fst_57, du16_snd_58 };
      letpair_res_141 = id_142;
    }
    ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a let_res_143;
    {
      ::dessser::gen::raql_binding_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_141 };
      ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a letpair_res_144;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_145 { 0 };
        bool id_146 { bool(id_145 == dsum1_fst_63) };
        ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a choose_res_147;
        if (id_146) {
          ::dessser::gen::raql_binding_key::t883c6ffea47c0d7b950fe35881e3d737 id_148 { dsum1_snd_64.readU32Le() };
          ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a letpair_res_149;
          {
            auto du32_fst_93 { std::get<0>(id_148) };
            auto du32_snd_94 { std::get<1>(id_148) };
            std::shared_ptr<::dessser::gen::raql_binding_key::t>  id_150 { std::make_shared<::dessser::gen::raql_binding_key::t>(std::in_place_index<0>, du32_fst_93) };
            ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a id_151 { id_150, du32_snd_94 };
            letpair_res_149 = id_151;
          }
          choose_res_147 = letpair_res_149;
        } else {
          uint16_t id_152 { 1 };
          bool id_153 { bool(id_152 == dsum1_fst_63) };
          ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a choose_res_154;
          if (id_153) {
            auto fun155 { dessser::gen::raql_variable::of_row_binary };
            ::dessser::gen::raql_binding_key::t8b22e447956958a21d977c854a5cd7c0 id_156 { fun155(dsum1_snd_64) };
            ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a let_res_157;
            {
              ::dessser::gen::raql_binding_key::t8b22e447956958a21d977c854a5cd7c0 dtup_83 { id_156 };
              ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a letpair_res_158;
              {
                auto dtup_fst_84 { std::get<0>(dtup_83) };
                auto dtup_snd_85 { std::get<1>(dtup_83) };
                auto fun159 { dessser::gen::field_name::of_row_binary };
                ::dessser::gen::raql_binding_key::tacdfdbd490062d58073ca57b70932e6d id_160 { fun159(dtup_snd_85) };
                ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a letpair_res_161;
                {
                  auto dtup_fst_87 { std::get<0>(id_160) };
                  auto dtup_snd_88 { std::get<1>(id_160) };
                  ::dessser::gen::raql_binding_key::t40f56917851bc62b1c9e1a72700c3bed id_162 { dtup_fst_84, dtup_fst_87 };
                  std::shared_ptr<::dessser::gen::raql_binding_key::t>  id_163 { std::make_shared<::dessser::gen::raql_binding_key::t>(std::in_place_index<1>, id_162) };
                  ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a id_164 { id_163, dtup_snd_88 };
                  letpair_res_161 = id_164;
                }
                letpair_res_158 = letpair_res_161;
              }
              let_res_157 = letpair_res_158;
            }
            choose_res_154 = let_res_157;
          } else {
            uint16_t id_165 { 2 };
            bool id_166 { bool(id_165 == dsum1_fst_63) };
            ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a choose_res_167;
            if (id_166) {
              auto fun168 { dessser::gen::raql_variable::of_row_binary };
              ::dessser::gen::raql_binding_key::t8b22e447956958a21d977c854a5cd7c0 id_169 { fun168(dsum1_snd_64) };
              ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a letpair_res_170;
              {
                auto dsum2_fst_81 { std::get<0>(id_169) };
                auto dsum2_snd_82 { std::get<1>(id_169) };
                std::shared_ptr<::dessser::gen::raql_binding_key::t>  id_171 { std::make_shared<::dessser::gen::raql_binding_key::t>(std::in_place_index<2>, dsum2_fst_81) };
                ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a id_172 { id_171, dsum2_snd_82 };
                letpair_res_170 = id_172;
              }
              choose_res_167 = letpair_res_170;
            } else {
              uint16_t id_173 { 3 };
              bool id_174 { bool(dsum1_fst_63 == id_173) };
              Void id_175 { ((void)(assert(id_174)), ::dessser::VOID) };
              (void)id_175;
              uint32_t id_176 { 0U };
              Vec<1, uint32_t> id_177 {  id_176  };
              ::dessser::gen::raql_binding_key::t044960e524fd6ec1bfc06410ce526709 let_res_178;
              {
                Vec<1, uint32_t> leb_ref_65 { id_177 };
                uint8_t id_179 { 0 };
                Vec<1, uint8_t> id_180 {  id_179  };
                ::dessser::gen::raql_binding_key::t044960e524fd6ec1bfc06410ce526709 let_res_181;
                {
                  Vec<1, uint8_t> shft_ref_66 { id_180 };
                  Vec<1, Pointer> id_182 {  dsum1_snd_64  };
                  ::dessser::gen::raql_binding_key::t044960e524fd6ec1bfc06410ce526709 let_res_183;
                  {
                    Vec<1, Pointer> p_ref_67 { id_182 };
                    bool while_flag_184 { true };
                    do {
                      uint8_t id_185 { 0 };
                      Pointer id_186 { p_ref_67[id_185] };
                      ::dessser::gen::raql_binding_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_187 { id_186.readU8() };
                      bool let_res_188;
                      {
                        ::dessser::gen::raql_binding_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_68 { id_187 };
                        bool letpair_res_189;
                        {
                          auto leb128_fst_69 { std::get<0>(leb128_68) };
                          auto leb128_snd_70 { std::get<1>(leb128_68) };
                          uint8_t id_190 { 0 };
                          Void id_191 { ((void)(p_ref_67[id_190] = leb128_snd_70), ::dessser::VOID) };
                          (void)id_191;
                          uint8_t id_192 { 0 };
                          uint8_t id_193 { 127 };
                          uint8_t id_194 { uint8_t(leb128_fst_69 & id_193) };
                          uint32_t id_195 { uint32_t(id_194) };
                          uint8_t id_196 { 0 };
                          uint8_t id_197 { shft_ref_66[id_196] };
                          uint32_t id_198 { uint32_t(id_195 << id_197) };
                          uint8_t id_199 { 0 };
                          uint32_t id_200 { leb_ref_65[id_199] };
                          uint32_t id_201 { uint32_t(id_198 | id_200) };
                          Void id_202 { ((void)(leb_ref_65[id_192] = id_201), ::dessser::VOID) };
                          (void)id_202;
                          uint8_t id_203 { 0 };
                          uint8_t id_204 { 0 };
                          uint8_t id_205 { shft_ref_66[id_204] };
                          uint8_t id_206 { 7 };
                          uint8_t id_207 { uint8_t(id_205 + id_206) };
                          Void id_208 { ((void)(shft_ref_66[id_203] = id_207), ::dessser::VOID) };
                          (void)id_208;
                          uint8_t id_209 { 128 };
                          bool id_210 { bool(leb128_fst_69 >= id_209) };
                          letpair_res_189 = id_210;
                        }
                        let_res_188 = letpair_res_189;
                      }
                      while_flag_184 = let_res_188;
                      if (while_flag_184) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_184);
                    (void)::dessser::VOID;
                    uint8_t id_211 { 0 };
                    uint32_t id_212 { leb_ref_65[id_211] };
                    Size id_213 { Size(id_212) };
                    uint8_t id_214 { 0 };
                    Pointer id_215 { p_ref_67[id_214] };
                    ::dessser::gen::raql_binding_key::t044960e524fd6ec1bfc06410ce526709 id_216 { id_213, id_215 };
                    let_res_183 = id_216;
                  }
                  let_res_181 = let_res_183;
                }
                let_res_178 = let_res_181;
              }
              ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a let_res_217;
              {
                ::dessser::gen::raql_binding_key::t044960e524fd6ec1bfc06410ce526709 dstring1_71 { let_res_178 };
                ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a letpair_res_218;
                {
                  auto dstring1_fst_72 { std::get<0>(dstring1_71) };
                  auto dstring1_snd_73 { std::get<1>(dstring1_71) };
                  ::dessser::gen::raql_binding_key::t5887709cc43c8c8e24d28211e8c970a2 id_219 { dstring1_snd_73.readBytes(dstring1_fst_72) };
                  ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a letpair_res_220;
                  {
                    auto dstring2_fst_75 { std::get<0>(id_219) };
                    auto dstring2_snd_76 { std::get<1>(id_219) };
                    std::string id_221 { dstring2_fst_75.toString() };
                    std::shared_ptr<::dessser::gen::raql_binding_key::t>  id_222 { std::make_shared<::dessser::gen::raql_binding_key::t>(std::in_place_index<3>, id_221) };
                    ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a id_223 { id_222, dstring2_snd_76 };
                    letpair_res_220 = id_223;
                  }
                  letpair_res_218 = letpair_res_220;
                }
                let_res_217 = letpair_res_218;
              }
              choose_res_167 = let_res_217;
            }
            choose_res_154 = choose_res_167;
          }
          choose_res_147 = choose_res_154;
        }
        letpair_res_144 = choose_res_147;
      }
      let_res_143 = letpair_res_144;
    }
    ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a letpair_res_224;
    {
      auto make_fst_99 { std::get<0>(let_res_143) };
      auto make_snd_100 { std::get<1>(let_res_143) };
      ::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a id_225 { make_fst_99, make_snd_100 };
      letpair_res_224 = id_225;
    }
    return letpair_res_224;
  }
   };
  return fun139;
}
std::function<::dessser::gen::raql_binding_key::tb153335fc05f1eec6819ab87a88b916a(Pointer)> of_row_binary(of_row_binary_init());


}
