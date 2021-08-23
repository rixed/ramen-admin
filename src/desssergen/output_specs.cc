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
#include "desssergen/raql_value.h"
#include "desssergen/fieldmask.h"
#include "desssergen/file_path.h"


namespace dessser::gen::output_specs {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct channel_specs : public std::tuple<
  double,
  int16_t,
  uint32_t
> { using tuple::tuple; };
struct t16c4cfbc5913dcc373c4d91afa31a65d {
  uint32_t batch_size;
  uint32_t num_batches;
  bool with_index;
  bool operator==(t16c4cfbc5913dcc373c4d91afa31a65d const &other) const {
    return batch_size == other.batch_size && num_batches == other.num_batches && with_index == other.with_index;
  }
};
struct file_type : public std::variant<
  Void,
  ::dessser::gen::output_specs::t16c4cfbc5913dcc373c4d91afa31a65d
> { using variant::variant; };
struct recipient : public std::variant<
  dessser::gen::file_path::t_ext,
  std::string,
  std::string
> { using variant::variant; };
typedef std::tuple<
  uint16_t,
  ::dessser::gen::output_specs::channel_specs*
> t0e5aeccd6bdb25fe3e41dac725c20413;

typedef std::tuple<
  uint16_t,
  Arr<dessser::gen::raql_value::t_ext>
> t4b7f8f0e420ffe218b8bc466a29068c5;

struct t92f55efe014c86abbab68bfc5de4a3b0 {
  Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> channels;
  dessser::gen::fieldmask::t_ext fieldmask;
  ::dessser::gen::output_specs::file_type* file_type;
  Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> filters;
  bool operator==(t92f55efe014c86abbab68bfc5de4a3b0 const &other) const {
    return channels == other.channels && fieldmask == other.fieldmask && file_type == other.file_type && filters == other.filters;
  }
};
typedef std::tuple<
  ::dessser::gen::output_specs::recipient*,
  ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0
> tc5008a31fa7e282d367c2301cc4f4334;

typedef Arr<::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334> t;
typedef std::tuple<
  ::dessser::gen::output_specs::channel_specs*,
  Pointer
> t6df20c301dedeef88b07b4e609cf70cc;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

typedef std::tuple<
  double,
  Pointer
> taebed00ad7fdb3f7ced11d3cfd58aade;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  int16_t,
  Pointer
> t7a480586af66fc37ae6bc54fa3d03602;

typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  ::dessser::gen::output_specs::file_type*,
  Pointer
> tc1a246d65b8ec8a1b6abc7902e02e4ae;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  bool,
  Pointer
> t4138de986e20d18b01e4c493dc9d5451;

typedef std::tuple<
  ::dessser::gen::output_specs::recipient*,
  Pointer
> tef522899602bf7c23a3b80730ab356df;

typedef std::tuple<
  dessser::gen::file_path::t_ext,
  Pointer
> tad3a94e851c33888b2891405a4005268;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

typedef std::tuple<
  t,
  Pointer
> t519c57b31160411c6989716f3a9782e0;

typedef std::tuple<
  Lst<::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334>,
  Pointer
> tb8cbc3be8a7d997e57f8bd003142375d;

typedef std::tuple<
  dessser::gen::fieldmask::t_ext,
  Pointer
> t65efc37c44620d2af7a978cf67ad8a5b;

typedef std::tuple<
  Lst<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5>,
  Pointer
> t9bf9d023de0a28608cb4fee6b41b5142;

typedef std::tuple<
  Lst<dessser::gen::raql_value::t_ext>,
  Pointer
> t926078c4ade3e1c01ca9446f92019ce0;

typedef std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> t9cfa78b25ddcb5afc14daf6a802a6f88;

typedef std::tuple<
  Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5>,
  Pointer
> tf52ce74d21915aee451d96c2d72ff42e;

typedef std::tuple<
  Lst<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413>,
  Pointer
> tcade6c15df3647aa3a87a1f7a3c4618f;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("(FLOAT; I16; U32)" "Ptr")
      (let "stup_dst_340" (let "stup_dst_339" (write-u64 little-endian (param 1) (u64-of-float (get-item 0 (param 0)))) (write-u16 little-endian (identifier "stup_dst_339") (to-u16 (get-item 1 (param 0)))))
        (write-u32 little-endian (identifier "stup_dst_340") (get-item 2 (param 0)))))
 */
static std::function<Pointer(::dessser::gen::output_specs::channel_specs*,Pointer)> channel_specs_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::output_specs::channel_specs*,Pointer)> fun0 { [&fun0](::dessser::gen::output_specs::channel_specs* p_0, Pointer p_1) {
    double id_1 { std::get<0>(*p_0) };
    uint64_t id_2 { qword_of_float(id_1) };
    Pointer id_3 { p_1.writeU64Le(id_2) };
    Pointer let_res_4;
    {
      Pointer stup_dst_339 { id_3 };
      int16_t id_5 { std::get<1>(*p_0) };
      uint16_t id_6 { uint16_t(id_5) };
      Pointer id_7 { stup_dst_339.writeU16Le(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer stup_dst_340 { let_res_4 };
      uint32_t id_9 { std::get<2>(*p_0) };
      Pointer id_10 { stup_dst_340.writeU32Le(id_9) };
      let_res_8 = id_10;
    }
    return let_res_8;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::output_specs::channel_specs*,Pointer)> channel_specs_to_row_binary(channel_specs_to_row_binary_init());

/* 
    (fun ("[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" "Ptr")
      (let "ssum_dst_336" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_336")
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "srec_dst_338"
              (let "srec_dst_337" (write-u8 (identifier "ssum_dst_336") (u8-of-bool (get-field "with_index" (get-alt "Orc" (param 0)))))
                (write-u32 little-endian (identifier "srec_dst_337") (get-field "batch_size" (get-alt "Orc" (param 0))))) 
              (write-u32 little-endian (identifier "srec_dst_338") (get-field "num_batches" (get-alt "Orc" (param 0)))))))))
 */
static std::function<Pointer(::dessser::gen::output_specs::file_type*,Pointer)> file_type_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::output_specs::file_type*,Pointer)> fun11 { [&fun11](::dessser::gen::output_specs::file_type* p_0, Pointer p_1) {
    uint16_t id_12 { uint16_t(p_0->index()) };
    Pointer id_13 { p_1.writeU16Le(id_12) };
    Pointer let_res_14;
    {
      Pointer ssum_dst_336 { id_13 };
      uint16_t id_15 { 0 };
      uint16_t id_16 { uint16_t(p_0->index()) };
      bool id_17 { bool(id_15 == id_16) };
      Pointer choose_res_18;
      if (id_17) {
        choose_res_18 = ssum_dst_336;
      } else {
        uint16_t id_19 { uint16_t(p_0->index()) };
        uint16_t id_20 { 1 };
        bool id_21 { bool(id_19 == id_20) };
        Void id_22 { ((void)(assert(id_21)), VOID) };
        (void)id_22;
        ::dessser::gen::output_specs::t16c4cfbc5913dcc373c4d91afa31a65d id_23 { std::get<1>(*p_0) };
        bool id_24 { id_23.with_index };
        uint8_t id_25 { uint8_t(id_24) };
        Pointer id_26 { ssum_dst_336.writeU8(id_25) };
        Pointer let_res_27;
        {
          Pointer srec_dst_337 { id_26 };
          ::dessser::gen::output_specs::t16c4cfbc5913dcc373c4d91afa31a65d id_28 { std::get<1>(*p_0) };
          uint32_t id_29 { id_28.batch_size };
          Pointer id_30 { srec_dst_337.writeU32Le(id_29) };
          let_res_27 = id_30;
        }
        Pointer let_res_31;
        {
          Pointer srec_dst_338 { let_res_27 };
          ::dessser::gen::output_specs::t16c4cfbc5913dcc373c4d91afa31a65d id_32 { std::get<1>(*p_0) };
          uint32_t id_33 { id_32.num_batches };
          Pointer id_34 { srec_dst_338.writeU32Le(id_33) };
          let_res_31 = id_34;
        }
        choose_res_18 = let_res_31;
      }
      let_res_14 = choose_res_18;
    }
    return let_res_14;
  }
   };
  return fun11;
}
std::function<Pointer(::dessser::gen::output_specs::file_type*,Pointer)> file_type_to_row_binary(file_type_to_row_binary_init());

/* 
    (fun ("[DirectFile $file_path | IndirectFile STRING | SyncKey STRING]" "Ptr")
      (let "ssum_dst_330" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (apply (ext-identifier file_path to-row-binary) (get-alt "DirectFile" (param 0)) (identifier "ssum_dst_330"))
          (if (eq (u16 1) (label-of (param 0)))
            (write-bytes
              (let "leb128_sz_333" (make-vec (string-length (get-alt "IndirectFile" (param 0))))
                (let "leb128_ptr_334" (make-vec (identifier "ssum_dst_330"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_334")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_334"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_333"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_333"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_333"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_333") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_333")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_333")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_334"))))) 
              (bytes-of-string (get-alt "IndirectFile" (param 0))))
            (seq (assert (eq (label-of (param 0)) (u16 2)))
              (write-bytes
                (let "leb128_sz_331" (make-vec (string-length (get-alt "SyncKey" (param 0))))
                  (let "leb128_ptr_332" (make-vec (identifier "ssum_dst_330"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_332")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_332"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_331"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_331"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_331"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_331") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_331")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_331")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_332"))))) 
                (bytes-of-string (get-alt "SyncKey" (param 0)))))))))
 */
static std::function<Pointer(::dessser::gen::output_specs::recipient*,Pointer)> recipient_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::output_specs::recipient*,Pointer)> fun35 { [&fun35](::dessser::gen::output_specs::recipient* p_0, Pointer p_1) {
    uint16_t id_36 { uint16_t(p_0->index()) };
    Pointer id_37 { p_1.writeU16Le(id_36) };
    Pointer let_res_38;
    {
      Pointer ssum_dst_330 { id_37 };
      uint16_t id_39 { 0 };
      uint16_t id_40 { uint16_t(p_0->index()) };
      bool id_41 { bool(id_39 == id_40) };
      Pointer choose_res_42;
      if (id_41) {
        auto fun43 { dessser::gen::file_path::to_row_binary };
        dessser::gen::file_path::t_ext id_44 { std::get<0>(*p_0) };
        Pointer id_45 { fun43(id_44, ssum_dst_330) };
        choose_res_42 = id_45;
      } else {
        uint16_t id_46 { 1 };
        uint16_t id_47 { uint16_t(p_0->index()) };
        bool id_48 { bool(id_46 == id_47) };
        Pointer choose_res_49;
        if (id_48) {
          std::string id_50 { std::get<1>(*p_0) };
          uint32_t id_51 { (uint32_t)id_50.size() };
          Vec<1, uint32_t> id_52 {  id_51  };
          Pointer let_res_53;
          {
            Vec<1, uint32_t> leb128_sz_333 { id_52 };
            Vec<1, Pointer> id_54 {  ssum_dst_330  };
            Pointer let_res_55;
            {
              Vec<1, Pointer> leb128_ptr_334 { id_54 };
              bool while_flag_56 { true };
              do {
                uint8_t id_57 { 0 };
                uint8_t id_58 { 0 };
                Pointer id_59 { leb128_ptr_334[id_58] };
                uint32_t id_60 { 128U };
                uint8_t id_61 { 0 };
                uint32_t id_62 { leb128_sz_333[id_61] };
                bool id_63 { bool(id_60 > id_62) };
                uint8_t choose_res_64;
                if (id_63) {
                  uint8_t id_65 { 0 };
                  uint32_t id_66 { leb128_sz_333[id_65] };
                  uint8_t id_67 { uint8_t(id_66) };
                  choose_res_64 = id_67;
                } else {
                  uint8_t id_68 { 0 };
                  uint32_t id_69 { leb128_sz_333[id_68] };
                  uint8_t id_70 { uint8_t(id_69) };
                  uint8_t id_71 { 128 };
                  uint8_t id_72 { uint8_t(id_70 | id_71) };
                  choose_res_64 = id_72;
                }
                Pointer id_73 { id_59.writeU8(choose_res_64) };
                Void id_74 { ((void)(leb128_ptr_334[id_57] = id_73), VOID) };
                (void)id_74;
                uint8_t id_75 { 0 };
                uint8_t id_76 { 0 };
                uint32_t id_77 { leb128_sz_333[id_76] };
                uint8_t id_78 { 7 };
                uint32_t id_79 { uint32_t(id_77 >> id_78) };
                Void id_80 { ((void)(leb128_sz_333[id_75] = id_79), VOID) };
                (void)id_80;
                uint8_t id_81 { 0 };
                uint32_t id_82 { leb128_sz_333[id_81] };
                uint32_t id_83 { 0U };
                bool id_84 { bool(id_82 > id_83) };
                while_flag_56 = id_84;
                if (while_flag_56) {
                  (void)VOID;
                }
              } while (while_flag_56);
              (void)VOID;
              uint8_t id_85 { 0 };
              Pointer id_86 { leb128_ptr_334[id_85] };
              let_res_55 = id_86;
            }
            let_res_53 = let_res_55;
          }
          std::string id_87 { std::get<1>(*p_0) };
          Bytes id_88 { id_87 };
          Pointer id_89 { let_res_53.writeBytes(id_88) };
          choose_res_49 = id_89;
        } else {
          uint16_t id_90 { uint16_t(p_0->index()) };
          uint16_t id_91 { 2 };
          bool id_92 { bool(id_90 == id_91) };
          Void id_93 { ((void)(assert(id_92)), VOID) };
          (void)id_93;
          std::string id_94 { std::get<2>(*p_0) };
          uint32_t id_95 { (uint32_t)id_94.size() };
          Vec<1, uint32_t> id_96 {  id_95  };
          Pointer let_res_97;
          {
            Vec<1, uint32_t> leb128_sz_331 { id_96 };
            Vec<1, Pointer> id_98 {  ssum_dst_330  };
            Pointer let_res_99;
            {
              Vec<1, Pointer> leb128_ptr_332 { id_98 };
              bool while_flag_100 { true };
              do {
                uint8_t id_101 { 0 };
                uint8_t id_102 { 0 };
                Pointer id_103 { leb128_ptr_332[id_102] };
                uint32_t id_104 { 128U };
                uint8_t id_105 { 0 };
                uint32_t id_106 { leb128_sz_331[id_105] };
                bool id_107 { bool(id_104 > id_106) };
                uint8_t choose_res_108;
                if (id_107) {
                  uint8_t id_109 { 0 };
                  uint32_t id_110 { leb128_sz_331[id_109] };
                  uint8_t id_111 { uint8_t(id_110) };
                  choose_res_108 = id_111;
                } else {
                  uint8_t id_112 { 0 };
                  uint32_t id_113 { leb128_sz_331[id_112] };
                  uint8_t id_114 { uint8_t(id_113) };
                  uint8_t id_115 { 128 };
                  uint8_t id_116 { uint8_t(id_114 | id_115) };
                  choose_res_108 = id_116;
                }
                Pointer id_117 { id_103.writeU8(choose_res_108) };
                Void id_118 { ((void)(leb128_ptr_332[id_101] = id_117), VOID) };
                (void)id_118;
                uint8_t id_119 { 0 };
                uint8_t id_120 { 0 };
                uint32_t id_121 { leb128_sz_331[id_120] };
                uint8_t id_122 { 7 };
                uint32_t id_123 { uint32_t(id_121 >> id_122) };
                Void id_124 { ((void)(leb128_sz_331[id_119] = id_123), VOID) };
                (void)id_124;
                uint8_t id_125 { 0 };
                uint32_t id_126 { leb128_sz_331[id_125] };
                uint32_t id_127 { 0U };
                bool id_128 { bool(id_126 > id_127) };
                while_flag_100 = id_128;
                if (while_flag_100) {
                  (void)VOID;
                }
              } while (while_flag_100);
              (void)VOID;
              uint8_t id_129 { 0 };
              Pointer id_130 { leb128_ptr_332[id_129] };
              let_res_99 = id_130;
            }
            let_res_97 = let_res_99;
          }
          std::string id_131 { std::get<2>(*p_0) };
          Bytes id_132 { id_131 };
          Pointer id_133 { let_res_97.writeBytes(id_132) };
          choose_res_49 = id_133;
        }
        choose_res_42 = choose_res_49;
      }
      let_res_38 = choose_res_42;
    }
    return let_res_38;
  }
   };
  return fun35;
}
std::function<Pointer(::dessser::gen::output_specs::recipient*,Pointer)> recipient_to_row_binary(recipient_to_row_binary_init());

/* 
    (fun ("((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey STRING]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})[]" "Ptr")
      (let "dst_ref_343"
        (make-vec
          (let "leb128_sz_341" (make-vec (cardinality (param 0)))
            (let "leb128_ptr_342" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_342")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_342"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_341"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_341"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_341"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_341") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_341")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_341")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_342"))))))
        (let "n_ref_344" (make-vec (i32 0))
          (seq
            (for-each "x_345" (param 0)
              (seq
                (set-vec (u8 0) (identifier "dst_ref_343")
                  (let "stup_dst_347" (let "stup_dst_346" (unsafe-nth (u8 0) (identifier "dst_ref_343")) (apply (identifier "recipient-to-row-binary") (get-item 0 (identifier "x_345")) (identifier "stup_dst_346")))
                    (let "srec_dst_362"
                      (let "srec_dst_349"
                        (let "srec_dst_348" (apply (identifier "file_type-to-row-binary") (get-field "file_type" (get-item 1 (identifier "x_345"))) (identifier "stup_dst_347"))
                          (apply (ext-identifier fieldmask to-row-binary) (get-field "fieldmask" (get-item 1 (identifier "x_345"))) (identifier "srec_dst_348")))
                        (let "dst_ref_352"
                          (make-vec
                            (let "leb128_sz_350" (make-vec (cardinality (get-field "filters" (get-item 1 (identifier "x_345")))))
                              (let "leb128_ptr_351" (make-vec (identifier "srec_dst_349"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_351")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_351"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_350"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_350"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_350"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_350") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_350")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_350")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_351"))))))
                          (let "n_ref_353" (make-vec (i32 0))
                            (seq
                              (for-each "x_354" (get-field "filters" (get-item 1 (identifier "x_345")))
                                (seq
                                  (set-vec (u8 0) (identifier "dst_ref_352")
                                    (let "stup_dst_356" (let "stup_dst_355" (unsafe-nth (u8 0) (identifier "dst_ref_352")) (write-u16 little-endian (identifier "stup_dst_355") (get-item 0 (identifier "x_354"))))
                                      (let "dst_ref_359"
                                        (make-vec
                                          (let "leb128_sz_357" (make-vec (cardinality (get-item 1 (identifier "x_354"))))
                                            (let "leb128_ptr_358" (make-vec (identifier "stup_dst_356"))
                                              (seq
                                                (while
                                                  (seq
                                                    (set-vec (u8 0) (identifier "leb128_ptr_358")
                                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_358"))
                                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_357"))) 
                                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_357"))) 
                                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_357"))) (u8 128)))))
                                                    (set-vec (u8 0) (identifier "leb128_sz_357") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_357")) (u8 7)))
                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_357")) (u32 0))) 
                                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_358"))))))
                                        (let "n_ref_360" (make-vec (i32 0))
                                          (seq
                                            (for-each "x_361" (get-item 1 (identifier "x_354"))
                                              (seq (set-vec (u8 0) (identifier "dst_ref_359") (apply (ext-identifier raql_value to-row-binary) (identifier "x_361") (unsafe-nth (u8 0) (identifier "dst_ref_359"))))
                                                (set-vec (u8 0) (identifier "n_ref_360") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_360")))))) 
                                            (unsafe-nth (u8 0) (identifier "dst_ref_359"))))))) 
                                  (set-vec (u8 0) (identifier "n_ref_353") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_353")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_352"))))))
                      (let "dst_ref_365"
                        (make-vec
                          (let "leb128_sz_363" (make-vec (cardinality (get-field "channels" (get-item 1 (identifier "x_345")))))
                            (let "leb128_ptr_364" (make-vec (identifier "srec_dst_362"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_364")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_364"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_363"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_363"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_363"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_363") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_363")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_363")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_364"))))))
                        (let "n_ref_366" (make-vec (i32 0))
                          (seq
                            (for-each "x_367" (get-field "channels" (get-item 1 (identifier "x_345")))
                              (seq
                                (set-vec (u8 0) (identifier "dst_ref_365")
                                  (let "stup_dst_369" (let "stup_dst_368" (unsafe-nth (u8 0) (identifier "dst_ref_365")) (write-u16 little-endian (identifier "stup_dst_368") (get-item 0 (identifier "x_367"))))
                                    (apply (identifier "channel_specs-to-row-binary") (get-item 1 (identifier "x_367")) (identifier "stup_dst_369"))))
                                (set-vec (u8 0) (identifier "n_ref_366") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_366")))))) 
                            (unsafe-nth (u8 0) (identifier "dst_ref_365")))))))) 
                (set-vec (u8 0) (identifier "n_ref_344") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_344")))))) 
            (unsafe-nth (u8 0) (identifier "dst_ref_343"))))))
 */
static std::function<Pointer(t&,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t&,Pointer)> fun134 { [&fun134](t& p_0, Pointer p_1) {
    uint32_t id_135 { p_0.size() };
    Vec<1, uint32_t> id_136 {  id_135  };
    Pointer let_res_137;
    {
      Vec<1, uint32_t> leb128_sz_341 { id_136 };
      Vec<1, Pointer> id_138 {  p_1  };
      Pointer let_res_139;
      {
        Vec<1, Pointer> leb128_ptr_342 { id_138 };
        bool while_flag_140 { true };
        do {
          uint8_t id_141 { 0 };
          uint8_t id_142 { 0 };
          Pointer id_143 { leb128_ptr_342[id_142] };
          uint32_t id_144 { 128U };
          uint8_t id_145 { 0 };
          uint32_t id_146 { leb128_sz_341[id_145] };
          bool id_147 { bool(id_144 > id_146) };
          uint8_t choose_res_148;
          if (id_147) {
            uint8_t id_149 { 0 };
            uint32_t id_150 { leb128_sz_341[id_149] };
            uint8_t id_151 { uint8_t(id_150) };
            choose_res_148 = id_151;
          } else {
            uint8_t id_152 { 0 };
            uint32_t id_153 { leb128_sz_341[id_152] };
            uint8_t id_154 { uint8_t(id_153) };
            uint8_t id_155 { 128 };
            uint8_t id_156 { uint8_t(id_154 | id_155) };
            choose_res_148 = id_156;
          }
          Pointer id_157 { id_143.writeU8(choose_res_148) };
          Void id_158 { ((void)(leb128_ptr_342[id_141] = id_157), VOID) };
          (void)id_158;
          uint8_t id_159 { 0 };
          uint8_t id_160 { 0 };
          uint32_t id_161 { leb128_sz_341[id_160] };
          uint8_t id_162 { 7 };
          uint32_t id_163 { uint32_t(id_161 >> id_162) };
          Void id_164 { ((void)(leb128_sz_341[id_159] = id_163), VOID) };
          (void)id_164;
          uint8_t id_165 { 0 };
          uint32_t id_166 { leb128_sz_341[id_165] };
          uint32_t id_167 { 0U };
          bool id_168 { bool(id_166 > id_167) };
          while_flag_140 = id_168;
          if (while_flag_140) {
            (void)VOID;
          }
        } while (while_flag_140);
        (void)VOID;
        uint8_t id_169 { 0 };
        Pointer id_170 { leb128_ptr_342[id_169] };
        let_res_139 = id_170;
      }
      let_res_137 = let_res_139;
    }
    Vec<1, Pointer> id_171 {  let_res_137  };
    Pointer let_res_172;
    {
      Vec<1, Pointer> dst_ref_343 { id_171 };
      int32_t id_173 { 0L };
      Vec<1, int32_t> id_174 {  id_173  };
      Pointer let_res_175;
      {
        Vec<1, int32_t> n_ref_344 { id_174 };
        for (::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 x_345 : p_0) {
          uint8_t id_176 { 0 };
          uint8_t id_177 { 0 };
          Pointer id_178 { dst_ref_343[id_177] };
          Pointer let_res_179;
          {
            Pointer stup_dst_346 { id_178 };
            ::dessser::gen::output_specs::recipient* id_180 { std::get<0>(x_345) };
            Pointer id_181 { recipient_to_row_binary(id_180, stup_dst_346) };
            let_res_179 = id_181;
          }
          Pointer let_res_182;
          {
            Pointer stup_dst_347 { let_res_179 };
            ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_183 { std::get<1>(x_345) };
            ::dessser::gen::output_specs::file_type* id_184 { id_183.file_type };
            Pointer id_185 { file_type_to_row_binary(id_184, stup_dst_347) };
            Pointer let_res_186;
            {
              Pointer srec_dst_348 { id_185 };
              auto fun187 { dessser::gen::fieldmask::to_row_binary };
              ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_188 { std::get<1>(x_345) };
              dessser::gen::fieldmask::t_ext id_189 { id_188.fieldmask };
              Pointer id_190 { fun187(id_189, srec_dst_348) };
              let_res_186 = id_190;
            }
            Pointer let_res_191;
            {
              Pointer srec_dst_349 { let_res_186 };
              ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_192 { std::get<1>(x_345) };
              Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> id_193 { id_192.filters };
              uint32_t id_194 { id_193.size() };
              Vec<1, uint32_t> id_195 {  id_194  };
              Pointer let_res_196;
              {
                Vec<1, uint32_t> leb128_sz_350 { id_195 };
                Vec<1, Pointer> id_197 {  srec_dst_349  };
                Pointer let_res_198;
                {
                  Vec<1, Pointer> leb128_ptr_351 { id_197 };
                  bool while_flag_199 { true };
                  do {
                    uint8_t id_200 { 0 };
                    uint8_t id_201 { 0 };
                    Pointer id_202 { leb128_ptr_351[id_201] };
                    uint32_t id_203 { 128U };
                    uint8_t id_204 { 0 };
                    uint32_t id_205 { leb128_sz_350[id_204] };
                    bool id_206 { bool(id_203 > id_205) };
                    uint8_t choose_res_207;
                    if (id_206) {
                      uint8_t id_208 { 0 };
                      uint32_t id_209 { leb128_sz_350[id_208] };
                      uint8_t id_210 { uint8_t(id_209) };
                      choose_res_207 = id_210;
                    } else {
                      uint8_t id_211 { 0 };
                      uint32_t id_212 { leb128_sz_350[id_211] };
                      uint8_t id_213 { uint8_t(id_212) };
                      uint8_t id_214 { 128 };
                      uint8_t id_215 { uint8_t(id_213 | id_214) };
                      choose_res_207 = id_215;
                    }
                    Pointer id_216 { id_202.writeU8(choose_res_207) };
                    Void id_217 { ((void)(leb128_ptr_351[id_200] = id_216), VOID) };
                    (void)id_217;
                    uint8_t id_218 { 0 };
                    uint8_t id_219 { 0 };
                    uint32_t id_220 { leb128_sz_350[id_219] };
                    uint8_t id_221 { 7 };
                    uint32_t id_222 { uint32_t(id_220 >> id_221) };
                    Void id_223 { ((void)(leb128_sz_350[id_218] = id_222), VOID) };
                    (void)id_223;
                    uint8_t id_224 { 0 };
                    uint32_t id_225 { leb128_sz_350[id_224] };
                    uint32_t id_226 { 0U };
                    bool id_227 { bool(id_225 > id_226) };
                    while_flag_199 = id_227;
                    if (while_flag_199) {
                      (void)VOID;
                    }
                  } while (while_flag_199);
                  (void)VOID;
                  uint8_t id_228 { 0 };
                  Pointer id_229 { leb128_ptr_351[id_228] };
                  let_res_198 = id_229;
                }
                let_res_196 = let_res_198;
              }
              Vec<1, Pointer> id_230 {  let_res_196  };
              Pointer let_res_231;
              {
                Vec<1, Pointer> dst_ref_352 { id_230 };
                int32_t id_232 { 0L };
                Vec<1, int32_t> id_233 {  id_232  };
                Pointer let_res_234;
                {
                  Vec<1, int32_t> n_ref_353 { id_233 };
                  ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_235 { std::get<1>(x_345) };
                  Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> id_236 { id_235.filters };
                  for (::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5 x_354 : id_236) {
                    uint8_t id_237 { 0 };
                    uint8_t id_238 { 0 };
                    Pointer id_239 { dst_ref_352[id_238] };
                    Pointer let_res_240;
                    {
                      Pointer stup_dst_355 { id_239 };
                      uint16_t id_241 { std::get<0>(x_354) };
                      Pointer id_242 { stup_dst_355.writeU16Le(id_241) };
                      let_res_240 = id_242;
                    }
                    Pointer let_res_243;
                    {
                      Pointer stup_dst_356 { let_res_240 };
                      Arr<dessser::gen::raql_value::t_ext> id_244 { std::get<1>(x_354) };
                      uint32_t id_245 { id_244.size() };
                      Vec<1, uint32_t> id_246 {  id_245  };
                      Pointer let_res_247;
                      {
                        Vec<1, uint32_t> leb128_sz_357 { id_246 };
                        Vec<1, Pointer> id_248 {  stup_dst_356  };
                        Pointer let_res_249;
                        {
                          Vec<1, Pointer> leb128_ptr_358 { id_248 };
                          bool while_flag_250 { true };
                          do {
                            uint8_t id_251 { 0 };
                            uint8_t id_252 { 0 };
                            Pointer id_253 { leb128_ptr_358[id_252] };
                            uint32_t id_254 { 128U };
                            uint8_t id_255 { 0 };
                            uint32_t id_256 { leb128_sz_357[id_255] };
                            bool id_257 { bool(id_254 > id_256) };
                            uint8_t choose_res_258;
                            if (id_257) {
                              uint8_t id_259 { 0 };
                              uint32_t id_260 { leb128_sz_357[id_259] };
                              uint8_t id_261 { uint8_t(id_260) };
                              choose_res_258 = id_261;
                            } else {
                              uint8_t id_262 { 0 };
                              uint32_t id_263 { leb128_sz_357[id_262] };
                              uint8_t id_264 { uint8_t(id_263) };
                              uint8_t id_265 { 128 };
                              uint8_t id_266 { uint8_t(id_264 | id_265) };
                              choose_res_258 = id_266;
                            }
                            Pointer id_267 { id_253.writeU8(choose_res_258) };
                            Void id_268 { ((void)(leb128_ptr_358[id_251] = id_267), VOID) };
                            (void)id_268;
                            uint8_t id_269 { 0 };
                            uint8_t id_270 { 0 };
                            uint32_t id_271 { leb128_sz_357[id_270] };
                            uint8_t id_272 { 7 };
                            uint32_t id_273 { uint32_t(id_271 >> id_272) };
                            Void id_274 { ((void)(leb128_sz_357[id_269] = id_273), VOID) };
                            (void)id_274;
                            uint8_t id_275 { 0 };
                            uint32_t id_276 { leb128_sz_357[id_275] };
                            uint32_t id_277 { 0U };
                            bool id_278 { bool(id_276 > id_277) };
                            while_flag_250 = id_278;
                            if (while_flag_250) {
                              (void)VOID;
                            }
                          } while (while_flag_250);
                          (void)VOID;
                          uint8_t id_279 { 0 };
                          Pointer id_280 { leb128_ptr_358[id_279] };
                          let_res_249 = id_280;
                        }
                        let_res_247 = let_res_249;
                      }
                      Vec<1, Pointer> id_281 {  let_res_247  };
                      Pointer let_res_282;
                      {
                        Vec<1, Pointer> dst_ref_359 { id_281 };
                        int32_t id_283 { 0L };
                        Vec<1, int32_t> id_284 {  id_283  };
                        Pointer let_res_285;
                        {
                          Vec<1, int32_t> n_ref_360 { id_284 };
                          Arr<dessser::gen::raql_value::t_ext> id_286 { std::get<1>(x_354) };
                          for (dessser::gen::raql_value::t_ext x_361 : id_286) {
                            uint8_t id_287 { 0 };
                            auto fun288 { dessser::gen::raql_value::to_row_binary };
                            uint8_t id_289 { 0 };
                            Pointer id_290 { dst_ref_359[id_289] };
                            Pointer id_291 { fun288(x_361, id_290) };
                            Void id_292 { ((void)(dst_ref_359[id_287] = id_291), VOID) };
                            (void)id_292;
                            uint8_t id_293 { 0 };
                            int32_t id_294 { 1L };
                            uint8_t id_295 { 0 };
                            int32_t id_296 { n_ref_360[id_295] };
                            int32_t id_297 { int32_t(id_294 + id_296) };
                            Void id_298 { ((void)(n_ref_360[id_293] = id_297), VOID) };
                            (void)id_298;
                            (void)id_298;
                          }
                          (void)VOID;
                          uint8_t id_299 { 0 };
                          Pointer id_300 { dst_ref_359[id_299] };
                          let_res_285 = id_300;
                        }
                        let_res_282 = let_res_285;
                      }
                      let_res_243 = let_res_282;
                    }
                    Void id_301 { ((void)(dst_ref_352[id_237] = let_res_243), VOID) };
                    (void)id_301;
                    uint8_t id_302 { 0 };
                    int32_t id_303 { 1L };
                    uint8_t id_304 { 0 };
                    int32_t id_305 { n_ref_353[id_304] };
                    int32_t id_306 { int32_t(id_303 + id_305) };
                    Void id_307 { ((void)(n_ref_353[id_302] = id_306), VOID) };
                    (void)id_307;
                    (void)id_307;
                  }
                  (void)VOID;
                  uint8_t id_308 { 0 };
                  Pointer id_309 { dst_ref_352[id_308] };
                  let_res_234 = id_309;
                }
                let_res_231 = let_res_234;
              }
              let_res_191 = let_res_231;
            }
            Pointer let_res_310;
            {
              Pointer srec_dst_362 { let_res_191 };
              ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_311 { std::get<1>(x_345) };
              Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> id_312 { id_311.channels };
              uint32_t id_313 { id_312.size() };
              Vec<1, uint32_t> id_314 {  id_313  };
              Pointer let_res_315;
              {
                Vec<1, uint32_t> leb128_sz_363 { id_314 };
                Vec<1, Pointer> id_316 {  srec_dst_362  };
                Pointer let_res_317;
                {
                  Vec<1, Pointer> leb128_ptr_364 { id_316 };
                  bool while_flag_318 { true };
                  do {
                    uint8_t id_319 { 0 };
                    uint8_t id_320 { 0 };
                    Pointer id_321 { leb128_ptr_364[id_320] };
                    uint32_t id_322 { 128U };
                    uint8_t id_323 { 0 };
                    uint32_t id_324 { leb128_sz_363[id_323] };
                    bool id_325 { bool(id_322 > id_324) };
                    uint8_t choose_res_326;
                    if (id_325) {
                      uint8_t id_327 { 0 };
                      uint32_t id_328 { leb128_sz_363[id_327] };
                      uint8_t id_329 { uint8_t(id_328) };
                      choose_res_326 = id_329;
                    } else {
                      uint8_t id_330 { 0 };
                      uint32_t id_331 { leb128_sz_363[id_330] };
                      uint8_t id_332 { uint8_t(id_331) };
                      uint8_t id_333 { 128 };
                      uint8_t id_334 { uint8_t(id_332 | id_333) };
                      choose_res_326 = id_334;
                    }
                    Pointer id_335 { id_321.writeU8(choose_res_326) };
                    Void id_336 { ((void)(leb128_ptr_364[id_319] = id_335), VOID) };
                    (void)id_336;
                    uint8_t id_337 { 0 };
                    uint8_t id_338 { 0 };
                    uint32_t id_339 { leb128_sz_363[id_338] };
                    uint8_t id_340 { 7 };
                    uint32_t id_341 { uint32_t(id_339 >> id_340) };
                    Void id_342 { ((void)(leb128_sz_363[id_337] = id_341), VOID) };
                    (void)id_342;
                    uint8_t id_343 { 0 };
                    uint32_t id_344 { leb128_sz_363[id_343] };
                    uint32_t id_345 { 0U };
                    bool id_346 { bool(id_344 > id_345) };
                    while_flag_318 = id_346;
                    if (while_flag_318) {
                      (void)VOID;
                    }
                  } while (while_flag_318);
                  (void)VOID;
                  uint8_t id_347 { 0 };
                  Pointer id_348 { leb128_ptr_364[id_347] };
                  let_res_317 = id_348;
                }
                let_res_315 = let_res_317;
              }
              Vec<1, Pointer> id_349 {  let_res_315  };
              Pointer let_res_350;
              {
                Vec<1, Pointer> dst_ref_365 { id_349 };
                int32_t id_351 { 0L };
                Vec<1, int32_t> id_352 {  id_351  };
                Pointer let_res_353;
                {
                  Vec<1, int32_t> n_ref_366 { id_352 };
                  ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_354 { std::get<1>(x_345) };
                  Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> id_355 { id_354.channels };
                  for (::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413 x_367 : id_355) {
                    uint8_t id_356 { 0 };
                    uint8_t id_357 { 0 };
                    Pointer id_358 { dst_ref_365[id_357] };
                    Pointer let_res_359;
                    {
                      Pointer stup_dst_368 { id_358 };
                      uint16_t id_360 { std::get<0>(x_367) };
                      Pointer id_361 { stup_dst_368.writeU16Le(id_360) };
                      let_res_359 = id_361;
                    }
                    Pointer let_res_362;
                    {
                      Pointer stup_dst_369 { let_res_359 };
                      ::dessser::gen::output_specs::channel_specs* id_363 { std::get<1>(x_367) };
                      Pointer id_364 { channel_specs_to_row_binary(id_363, stup_dst_369) };
                      let_res_362 = id_364;
                    }
                    Void id_365 { ((void)(dst_ref_365[id_356] = let_res_362), VOID) };
                    (void)id_365;
                    uint8_t id_366 { 0 };
                    int32_t id_367 { 1L };
                    uint8_t id_368 { 0 };
                    int32_t id_369 { n_ref_366[id_368] };
                    int32_t id_370 { int32_t(id_367 + id_369) };
                    Void id_371 { ((void)(n_ref_366[id_366] = id_370), VOID) };
                    (void)id_371;
                    (void)id_371;
                  }
                  (void)VOID;
                  uint8_t id_372 { 0 };
                  Pointer id_373 { dst_ref_365[id_372] };
                  let_res_353 = id_373;
                }
                let_res_350 = let_res_353;
              }
              let_res_310 = let_res_350;
            }
            let_res_182 = let_res_310;
          }
          Void id_374 { ((void)(dst_ref_343[id_176] = let_res_182), VOID) };
          (void)id_374;
          uint8_t id_375 { 0 };
          int32_t id_376 { 1L };
          uint8_t id_377 { 0 };
          int32_t id_378 { n_ref_344[id_377] };
          int32_t id_379 { int32_t(id_376 + id_378) };
          Void id_380 { ((void)(n_ref_344[id_375] = id_379), VOID) };
          (void)id_380;
          (void)id_380;
        }
        (void)VOID;
        uint8_t id_381 { 0 };
        Pointer id_382 { dst_ref_343[id_381] };
        let_res_175 = id_382;
      }
      let_res_172 = let_res_175;
    }
    return let_res_172;
  }
   };
  return fun134;
}
std::function<Pointer(t&,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("(FLOAT; I16; U32)") (size 14))
 */
static std::function<Size(::dessser::gen::output_specs::channel_specs*)> channel_specs_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::output_specs::channel_specs*)> fun383 { [&fun383](::dessser::gen::output_specs::channel_specs* p_0) {
    Size id_384 { 14UL };
    return id_384;
  }
   };
  return fun383;
}
std::function<Size(::dessser::gen::output_specs::channel_specs*)> channel_specs_sersize_of_row_binary(channel_specs_sersize_of_row_binary_init());

/* 
    (fun ("[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]") (if (eq (u16 0) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 1))) (size 11))))
 */
static std::function<Size(::dessser::gen::output_specs::file_type*)> file_type_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::output_specs::file_type*)> fun385 { [&fun385](::dessser::gen::output_specs::file_type* p_0) {
    uint16_t id_386 { 0 };
    uint16_t id_387 { uint16_t(p_0->index()) };
    bool id_388 { bool(id_386 == id_387) };
    Size choose_res_389;
    if (id_388) {
      Size id_390 { 2UL };
      choose_res_389 = id_390;
    } else {
      uint16_t id_391 { uint16_t(p_0->index()) };
      uint16_t id_392 { 1 };
      bool id_393 { bool(id_391 == id_392) };
      Void id_394 { ((void)(assert(id_393)), VOID) };
      (void)id_394;
      Size id_395 { 11UL };
      choose_res_389 = id_395;
    }
    return choose_res_389;
  }
   };
  return fun385;
}
std::function<Size(::dessser::gen::output_specs::file_type*)> file_type_sersize_of_row_binary(file_type_sersize_of_row_binary_init());

/* 
    (fun ("[DirectFile $file_path | IndirectFile STRING | SyncKey STRING]")
      (if (eq (u16 0) (label-of (param 0))) (add (size 2) (apply (ext-identifier file_path sersize-of-row-binary) (get-alt "DirectFile" (param 0))))
        (if (eq (u16 1) (label-of (param 0)))
          (add (size 2)
            (add
              (let "n_ref_294" (make-vec (string-length (get-alt "IndirectFile" (param 0))))
                (let "lebsz_ref_295" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_294")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_295")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_295") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_295")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_295")))))) 
              (size-of-u32 (string-length (get-alt "IndirectFile" (param 0))))))
          (seq (assert (eq (label-of (param 0)) (u16 2)))
            (add (size 2)
              (add
                (let "n_ref_291" (make-vec (string-length (get-alt "SyncKey" (param 0))))
                  (let "lebsz_ref_292" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_291")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_292")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_292") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_292")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_292")))))) 
                (size-of-u32 (string-length (get-alt "SyncKey" (param 0))))))))))
 */
static std::function<Size(::dessser::gen::output_specs::recipient*)> recipient_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::output_specs::recipient*)> fun396 { [&fun396](::dessser::gen::output_specs::recipient* p_0) {
    uint16_t id_397 { 0 };
    uint16_t id_398 { uint16_t(p_0->index()) };
    bool id_399 { bool(id_397 == id_398) };
    Size choose_res_400;
    if (id_399) {
      Size id_401 { 2UL };
      auto fun402 { dessser::gen::file_path::sersize_of_row_binary };
      dessser::gen::file_path::t_ext id_403 { std::get<0>(*p_0) };
      Size id_404 { fun402(id_403) };
      Size id_405 { Size(id_401 + id_404) };
      choose_res_400 = id_405;
    } else {
      uint16_t id_406 { 1 };
      uint16_t id_407 { uint16_t(p_0->index()) };
      bool id_408 { bool(id_406 == id_407) };
      Size choose_res_409;
      if (id_408) {
        Size id_410 { 2UL };
        std::string id_411 { std::get<1>(*p_0) };
        uint32_t id_412 { (uint32_t)id_411.size() };
        Vec<1, uint32_t> id_413 {  id_412  };
        Size let_res_414;
        {
          Vec<1, uint32_t> n_ref_294 { id_413 };
          uint32_t id_415 { 1U };
          Vec<1, uint32_t> id_416 {  id_415  };
          Size let_res_417;
          {
            Vec<1, uint32_t> lebsz_ref_295 { id_416 };
            bool while_flag_418 { true };
            do {
              uint8_t id_419 { 0 };
              uint32_t id_420 { n_ref_294[id_419] };
              uint8_t id_421 { 0 };
              uint32_t id_422 { lebsz_ref_295[id_421] };
              uint8_t id_423 { 7 };
              uint32_t id_424 { uint32_t(id_422 << id_423) };
              bool id_425 { bool(id_420 >= id_424) };
              while_flag_418 = id_425;
              if (while_flag_418) {
                uint8_t id_426 { 0 };
                uint8_t id_427 { 0 };
                uint32_t id_428 { lebsz_ref_295[id_427] };
                uint32_t id_429 { 1U };
                uint32_t id_430 { uint32_t(id_428 + id_429) };
                Void id_431 { ((void)(lebsz_ref_295[id_426] = id_430), VOID) };
                (void)id_431;
              }
            } while (while_flag_418);
            (void)VOID;
            uint8_t id_432 { 0 };
            uint32_t id_433 { lebsz_ref_295[id_432] };
            Size id_434 { Size(id_433) };
            let_res_417 = id_434;
          }
          let_res_414 = let_res_417;
        }
        std::string id_435 { std::get<1>(*p_0) };
        uint32_t id_436 { (uint32_t)id_435.size() };
        Size id_437 { Size(id_436) };
        Size id_438 { Size(let_res_414 + id_437) };
        Size id_439 { Size(id_410 + id_438) };
        choose_res_409 = id_439;
      } else {
        uint16_t id_440 { uint16_t(p_0->index()) };
        uint16_t id_441 { 2 };
        bool id_442 { bool(id_440 == id_441) };
        Void id_443 { ((void)(assert(id_442)), VOID) };
        (void)id_443;
        Size id_444 { 2UL };
        std::string id_445 { std::get<2>(*p_0) };
        uint32_t id_446 { (uint32_t)id_445.size() };
        Vec<1, uint32_t> id_447 {  id_446  };
        Size let_res_448;
        {
          Vec<1, uint32_t> n_ref_291 { id_447 };
          uint32_t id_449 { 1U };
          Vec<1, uint32_t> id_450 {  id_449  };
          Size let_res_451;
          {
            Vec<1, uint32_t> lebsz_ref_292 { id_450 };
            bool while_flag_452 { true };
            do {
              uint8_t id_453 { 0 };
              uint32_t id_454 { n_ref_291[id_453] };
              uint8_t id_455 { 0 };
              uint32_t id_456 { lebsz_ref_292[id_455] };
              uint8_t id_457 { 7 };
              uint32_t id_458 { uint32_t(id_456 << id_457) };
              bool id_459 { bool(id_454 >= id_458) };
              while_flag_452 = id_459;
              if (while_flag_452) {
                uint8_t id_460 { 0 };
                uint8_t id_461 { 0 };
                uint32_t id_462 { lebsz_ref_292[id_461] };
                uint32_t id_463 { 1U };
                uint32_t id_464 { uint32_t(id_462 + id_463) };
                Void id_465 { ((void)(lebsz_ref_292[id_460] = id_464), VOID) };
                (void)id_465;
              }
            } while (while_flag_452);
            (void)VOID;
            uint8_t id_466 { 0 };
            uint32_t id_467 { lebsz_ref_292[id_466] };
            Size id_468 { Size(id_467) };
            let_res_451 = id_468;
          }
          let_res_448 = let_res_451;
        }
        std::string id_469 { std::get<2>(*p_0) };
        uint32_t id_470 { (uint32_t)id_469.size() };
        Size id_471 { Size(id_470) };
        Size id_472 { Size(let_res_448 + id_471) };
        Size id_473 { Size(id_444 + id_472) };
        choose_res_409 = id_473;
      }
      choose_res_400 = choose_res_409;
    }
    return choose_res_400;
  }
   };
  return fun396;
}
std::function<Size(::dessser::gen::output_specs::recipient*)> recipient_sersize_of_row_binary(recipient_sersize_of_row_binary_init());

/* 
    (fun ("((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey STRING]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})[]")
      (let "sz_ref_305"
        (make-vec
          (let "n_ref_303" (make-vec (cardinality (param 0)))
            (let "lebsz_ref_304" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_303")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_304")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_304") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_304")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_304")))))))
        (seq
          (let "repeat_n_306" (make-vec (i32 0))
            (while (gt (to-i32 (cardinality (param 0))) (unsafe-nth (u8 0) (identifier "repeat_n_306")))
              (seq
                (set-vec (u8 0) (identifier "sz_ref_305")
                  (let "sz_308"
                    (let "sz_307" (unsafe-nth (u8 0) (identifier "sz_ref_305"))
                      (add (identifier "sz_307") (apply (identifier "recipient-sersize-of-row-binary") (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0))))))
                    (let "sz_322"
                      (let "sz_311"
                        (let "sz_310" (add (identifier "sz_308") (apply (identifier "file_type-sersize-of-row-binary") (get-field "file_type" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0))))))
                          (add (identifier "sz_310") (apply (ext-identifier fieldmask sersize-of-row-binary) (get-field "fieldmask" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0)))))))
                        (let "sz_ref_314"
                          (make-vec
                            (add (identifier "sz_311")
                              (let "n_ref_312" (make-vec (cardinality (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0))))))
                                (let "lebsz_ref_313" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_312")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_313")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_313") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_313")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_313"))))))))
                          (seq
                            (let "repeat_n_315" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_315")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_314")
                                    (let "sz_317" (add (unsafe-nth (u8 0) (identifier "sz_ref_314")) (size 2))
                                      (let "sz_ref_320"
                                        (make-vec
                                          (add (identifier "sz_317")
                                            (let "n_ref_318"
                                              (make-vec
                                                (cardinality
                                                  (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_315")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0))))))))
                                              (let "lebsz_ref_319" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_318")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_319")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_319") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_319")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_319"))))))))
                                        (seq
                                          (let "repeat_n_321" (make-vec (i32 0))
                                            (while
                                              (gt
                                                (to-i32
                                                  (cardinality
                                                    (get-item 1
                                                      (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_315")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0))))))))
                                                (unsafe-nth (u8 0) (identifier "repeat_n_321")))
                                              (seq
                                                (set-vec (u8 0) (identifier "sz_ref_320")
                                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_320"))
                                                    (apply (ext-identifier raql_value sersize-of-row-binary)
                                                      (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_321"))
                                                        (get-item 1
                                                          (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_315")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0))))))))))
                                                (set-vec (u8 0) (identifier "repeat_n_321") (add (unsafe-nth (u8 0) (identifier "repeat_n_321")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "sz_ref_320")))))) 
                                  (set-vec (u8 0) (identifier "repeat_n_315") (add (unsafe-nth (u8 0) (identifier "repeat_n_315")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_314")))))
                      (let "sz_ref_325"
                        (make-vec
                          (add (identifier "sz_322")
                            (let "n_ref_323" (make-vec (cardinality (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0))))))
                              (let "lebsz_ref_324" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_323")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_324")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_324") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_324")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_324"))))))))
                        (seq
                          (let "repeat_n_326" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_326")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_325")
                                  (let "sz_328" (add (unsafe-nth (u8 0) (identifier "sz_ref_325")) (size 2))
                                    (add (identifier "sz_328")
                                      (apply (identifier "channel_specs-sersize-of-row-binary")
                                        (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_326")) (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306")) (param 0))))))))))
                                (set-vec (u8 0) (identifier "repeat_n_326") (add (unsafe-nth (u8 0) (identifier "repeat_n_326")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_325"))))))) 
                (set-vec (u8 0) (identifier "repeat_n_306") (add (unsafe-nth (u8 0) (identifier "repeat_n_306")) (i32 1)))))) 
          (unsafe-nth (u8 0) (identifier "sz_ref_305")))))
 */
static std::function<Size(t&)> sersize_of_row_binary_init()
{
  std::function<Size(t&)> fun474 { [&fun474](t& p_0) {
    uint32_t id_475 { p_0.size() };
    Vec<1, uint32_t> id_476 {  id_475  };
    Size let_res_477;
    {
      Vec<1, uint32_t> n_ref_303 { id_476 };
      uint32_t id_478 { 1U };
      Vec<1, uint32_t> id_479 {  id_478  };
      Size let_res_480;
      {
        Vec<1, uint32_t> lebsz_ref_304 { id_479 };
        bool while_flag_481 { true };
        do {
          uint8_t id_482 { 0 };
          uint32_t id_483 { n_ref_303[id_482] };
          uint8_t id_484 { 0 };
          uint32_t id_485 { lebsz_ref_304[id_484] };
          uint8_t id_486 { 7 };
          uint32_t id_487 { uint32_t(id_485 << id_486) };
          bool id_488 { bool(id_483 >= id_487) };
          while_flag_481 = id_488;
          if (while_flag_481) {
            uint8_t id_489 { 0 };
            uint8_t id_490 { 0 };
            uint32_t id_491 { lebsz_ref_304[id_490] };
            uint32_t id_492 { 1U };
            uint32_t id_493 { uint32_t(id_491 + id_492) };
            Void id_494 { ((void)(lebsz_ref_304[id_489] = id_493), VOID) };
            (void)id_494;
          }
        } while (while_flag_481);
        (void)VOID;
        uint8_t id_495 { 0 };
        uint32_t id_496 { lebsz_ref_304[id_495] };
        Size id_497 { Size(id_496) };
        let_res_480 = id_497;
      }
      let_res_477 = let_res_480;
    }
    Vec<1, Size> id_498 {  let_res_477  };
    Size let_res_499;
    {
      Vec<1, Size> sz_ref_305 { id_498 };
      int32_t id_500 { 0L };
      Vec<1, int32_t> id_501 {  id_500  };
      {
        Vec<1, int32_t> repeat_n_306 { id_501 };
        bool while_flag_502 { true };
        do {
          uint32_t id_503 { p_0.size() };
          int32_t id_504 { int32_t(id_503) };
          uint8_t id_505 { 0 };
          int32_t id_506 { repeat_n_306[id_505] };
          bool id_507 { bool(id_504 > id_506) };
          while_flag_502 = id_507;
          if (while_flag_502) {
            uint8_t id_508 { 0 };
            uint8_t id_509 { 0 };
            Size id_510 { sz_ref_305[id_509] };
            Size let_res_511;
            {
              Size sz_307 { id_510 };
              uint8_t id_512 { 0 };
              int32_t id_513 { repeat_n_306[id_512] };
              ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_514 { p_0[id_513] };
              ::dessser::gen::output_specs::recipient* id_515 { std::get<0>(id_514) };
              Size id_516 { recipient_sersize_of_row_binary(id_515) };
              Size id_517 { Size(sz_307 + id_516) };
              let_res_511 = id_517;
            }
            Size let_res_518;
            {
              Size sz_308 { let_res_511 };
              uint8_t id_519 { 0 };
              int32_t id_520 { repeat_n_306[id_519] };
              ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_521 { p_0[id_520] };
              ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_522 { std::get<1>(id_521) };
              ::dessser::gen::output_specs::file_type* id_523 { id_522.file_type };
              Size id_524 { file_type_sersize_of_row_binary(id_523) };
              Size id_525 { Size(sz_308 + id_524) };
              Size let_res_526;
              {
                Size sz_310 { id_525 };
                auto fun527 { dessser::gen::fieldmask::sersize_of_row_binary };
                uint8_t id_528 { 0 };
                int32_t id_529 { repeat_n_306[id_528] };
                ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_530 { p_0[id_529] };
                ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_531 { std::get<1>(id_530) };
                dessser::gen::fieldmask::t_ext id_532 { id_531.fieldmask };
                Size id_533 { fun527(id_532) };
                Size id_534 { Size(sz_310 + id_533) };
                let_res_526 = id_534;
              }
              Size let_res_535;
              {
                Size sz_311 { let_res_526 };
                uint8_t id_536 { 0 };
                int32_t id_537 { repeat_n_306[id_536] };
                ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_538 { p_0[id_537] };
                ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_539 { std::get<1>(id_538) };
                Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> id_540 { id_539.filters };
                uint32_t id_541 { id_540.size() };
                Vec<1, uint32_t> id_542 {  id_541  };
                Size let_res_543;
                {
                  Vec<1, uint32_t> n_ref_312 { id_542 };
                  uint32_t id_544 { 1U };
                  Vec<1, uint32_t> id_545 {  id_544  };
                  Size let_res_546;
                  {
                    Vec<1, uint32_t> lebsz_ref_313 { id_545 };
                    bool while_flag_547 { true };
                    do {
                      uint8_t id_548 { 0 };
                      uint32_t id_549 { n_ref_312[id_548] };
                      uint8_t id_550 { 0 };
                      uint32_t id_551 { lebsz_ref_313[id_550] };
                      uint8_t id_552 { 7 };
                      uint32_t id_553 { uint32_t(id_551 << id_552) };
                      bool id_554 { bool(id_549 >= id_553) };
                      while_flag_547 = id_554;
                      if (while_flag_547) {
                        uint8_t id_555 { 0 };
                        uint8_t id_556 { 0 };
                        uint32_t id_557 { lebsz_ref_313[id_556] };
                        uint32_t id_558 { 1U };
                        uint32_t id_559 { uint32_t(id_557 + id_558) };
                        Void id_560 { ((void)(lebsz_ref_313[id_555] = id_559), VOID) };
                        (void)id_560;
                      }
                    } while (while_flag_547);
                    (void)VOID;
                    uint8_t id_561 { 0 };
                    uint32_t id_562 { lebsz_ref_313[id_561] };
                    Size id_563 { Size(id_562) };
                    let_res_546 = id_563;
                  }
                  let_res_543 = let_res_546;
                }
                Size id_564 { Size(sz_311 + let_res_543) };
                Vec<1, Size> id_565 {  id_564  };
                Size let_res_566;
                {
                  Vec<1, Size> sz_ref_314 { id_565 };
                  int32_t id_567 { 0L };
                  Vec<1, int32_t> id_568 {  id_567  };
                  {
                    Vec<1, int32_t> repeat_n_315 { id_568 };
                    bool while_flag_569 { true };
                    do {
                      uint8_t id_570 { 0 };
                      int32_t id_571 { repeat_n_306[id_570] };
                      ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_572 { p_0[id_571] };
                      ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_573 { std::get<1>(id_572) };
                      Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> id_574 { id_573.filters };
                      uint32_t id_575 { id_574.size() };
                      int32_t id_576 { int32_t(id_575) };
                      uint8_t id_577 { 0 };
                      int32_t id_578 { repeat_n_315[id_577] };
                      bool id_579 { bool(id_576 > id_578) };
                      while_flag_569 = id_579;
                      if (while_flag_569) {
                        uint8_t id_580 { 0 };
                        uint8_t id_581 { 0 };
                        Size id_582 { sz_ref_314[id_581] };
                        Size id_583 { 2UL };
                        Size id_584 { Size(id_582 + id_583) };
                        Size let_res_585;
                        {
                          Size sz_317 { id_584 };
                          uint8_t id_586 { 0 };
                          int32_t id_587 { repeat_n_315[id_586] };
                          uint8_t id_588 { 0 };
                          int32_t id_589 { repeat_n_306[id_588] };
                          ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_590 { p_0[id_589] };
                          ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_591 { std::get<1>(id_590) };
                          Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> id_592 { id_591.filters };
                          ::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5 id_593 { id_592[id_587] };
                          Arr<dessser::gen::raql_value::t_ext> id_594 { std::get<1>(id_593) };
                          uint32_t id_595 { id_594.size() };
                          Vec<1, uint32_t> id_596 {  id_595  };
                          Size let_res_597;
                          {
                            Vec<1, uint32_t> n_ref_318 { id_596 };
                            uint32_t id_598 { 1U };
                            Vec<1, uint32_t> id_599 {  id_598  };
                            Size let_res_600;
                            {
                              Vec<1, uint32_t> lebsz_ref_319 { id_599 };
                              bool while_flag_601 { true };
                              do {
                                uint8_t id_602 { 0 };
                                uint32_t id_603 { n_ref_318[id_602] };
                                uint8_t id_604 { 0 };
                                uint32_t id_605 { lebsz_ref_319[id_604] };
                                uint8_t id_606 { 7 };
                                uint32_t id_607 { uint32_t(id_605 << id_606) };
                                bool id_608 { bool(id_603 >= id_607) };
                                while_flag_601 = id_608;
                                if (while_flag_601) {
                                  uint8_t id_609 { 0 };
                                  uint8_t id_610 { 0 };
                                  uint32_t id_611 { lebsz_ref_319[id_610] };
                                  uint32_t id_612 { 1U };
                                  uint32_t id_613 { uint32_t(id_611 + id_612) };
                                  Void id_614 { ((void)(lebsz_ref_319[id_609] = id_613), VOID) };
                                  (void)id_614;
                                }
                              } while (while_flag_601);
                              (void)VOID;
                              uint8_t id_615 { 0 };
                              uint32_t id_616 { lebsz_ref_319[id_615] };
                              Size id_617 { Size(id_616) };
                              let_res_600 = id_617;
                            }
                            let_res_597 = let_res_600;
                          }
                          Size id_618 { Size(sz_317 + let_res_597) };
                          Vec<1, Size> id_619 {  id_618  };
                          Size let_res_620;
                          {
                            Vec<1, Size> sz_ref_320 { id_619 };
                            int32_t id_621 { 0L };
                            Vec<1, int32_t> id_622 {  id_621  };
                            {
                              Vec<1, int32_t> repeat_n_321 { id_622 };
                              bool while_flag_623 { true };
                              do {
                                uint8_t id_624 { 0 };
                                int32_t id_625 { repeat_n_315[id_624] };
                                uint8_t id_626 { 0 };
                                int32_t id_627 { repeat_n_306[id_626] };
                                ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_628 { p_0[id_627] };
                                ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_629 { std::get<1>(id_628) };
                                Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> id_630 { id_629.filters };
                                ::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5 id_631 { id_630[id_625] };
                                Arr<dessser::gen::raql_value::t_ext> id_632 { std::get<1>(id_631) };
                                uint32_t id_633 { id_632.size() };
                                int32_t id_634 { int32_t(id_633) };
                                uint8_t id_635 { 0 };
                                int32_t id_636 { repeat_n_321[id_635] };
                                bool id_637 { bool(id_634 > id_636) };
                                while_flag_623 = id_637;
                                if (while_flag_623) {
                                  uint8_t id_638 { 0 };
                                  uint8_t id_639 { 0 };
                                  Size id_640 { sz_ref_320[id_639] };
                                  auto fun641 { dessser::gen::raql_value::sersize_of_row_binary };
                                  uint8_t id_642 { 0 };
                                  int32_t id_643 { repeat_n_321[id_642] };
                                  uint8_t id_644 { 0 };
                                  int32_t id_645 { repeat_n_315[id_644] };
                                  uint8_t id_646 { 0 };
                                  int32_t id_647 { repeat_n_306[id_646] };
                                  ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_648 { p_0[id_647] };
                                  ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_649 { std::get<1>(id_648) };
                                  Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> id_650 { id_649.filters };
                                  ::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5 id_651 { id_650[id_645] };
                                  Arr<dessser::gen::raql_value::t_ext> id_652 { std::get<1>(id_651) };
                                  dessser::gen::raql_value::t_ext id_653 { id_652[id_643] };
                                  Size id_654 { fun641(id_653) };
                                  Size id_655 { Size(id_640 + id_654) };
                                  Void id_656 { ((void)(sz_ref_320[id_638] = id_655), VOID) };
                                  (void)id_656;
                                  uint8_t id_657 { 0 };
                                  uint8_t id_658 { 0 };
                                  int32_t id_659 { repeat_n_321[id_658] };
                                  int32_t id_660 { 1L };
                                  int32_t id_661 { int32_t(id_659 + id_660) };
                                  Void id_662 { ((void)(repeat_n_321[id_657] = id_661), VOID) };
                                  (void)id_662;
                                  (void)id_662;
                                }
                              } while (while_flag_623);
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_663 { 0 };
                            Size id_664 { sz_ref_320[id_663] };
                            let_res_620 = id_664;
                          }
                          let_res_585 = let_res_620;
                        }
                        Void id_665 { ((void)(sz_ref_314[id_580] = let_res_585), VOID) };
                        (void)id_665;
                        uint8_t id_666 { 0 };
                        uint8_t id_667 { 0 };
                        int32_t id_668 { repeat_n_315[id_667] };
                        int32_t id_669 { 1L };
                        int32_t id_670 { int32_t(id_668 + id_669) };
                        Void id_671 { ((void)(repeat_n_315[id_666] = id_670), VOID) };
                        (void)id_671;
                        (void)id_671;
                      }
                    } while (while_flag_569);
                    (void)VOID;
                  }
                  (void)VOID;
                  uint8_t id_672 { 0 };
                  Size id_673 { sz_ref_314[id_672] };
                  let_res_566 = id_673;
                }
                let_res_535 = let_res_566;
              }
              Size let_res_674;
              {
                Size sz_322 { let_res_535 };
                uint8_t id_675 { 0 };
                int32_t id_676 { repeat_n_306[id_675] };
                ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_677 { p_0[id_676] };
                ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_678 { std::get<1>(id_677) };
                Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> id_679 { id_678.channels };
                uint32_t id_680 { id_679.size() };
                Vec<1, uint32_t> id_681 {  id_680  };
                Size let_res_682;
                {
                  Vec<1, uint32_t> n_ref_323 { id_681 };
                  uint32_t id_683 { 1U };
                  Vec<1, uint32_t> id_684 {  id_683  };
                  Size let_res_685;
                  {
                    Vec<1, uint32_t> lebsz_ref_324 { id_684 };
                    bool while_flag_686 { true };
                    do {
                      uint8_t id_687 { 0 };
                      uint32_t id_688 { n_ref_323[id_687] };
                      uint8_t id_689 { 0 };
                      uint32_t id_690 { lebsz_ref_324[id_689] };
                      uint8_t id_691 { 7 };
                      uint32_t id_692 { uint32_t(id_690 << id_691) };
                      bool id_693 { bool(id_688 >= id_692) };
                      while_flag_686 = id_693;
                      if (while_flag_686) {
                        uint8_t id_694 { 0 };
                        uint8_t id_695 { 0 };
                        uint32_t id_696 { lebsz_ref_324[id_695] };
                        uint32_t id_697 { 1U };
                        uint32_t id_698 { uint32_t(id_696 + id_697) };
                        Void id_699 { ((void)(lebsz_ref_324[id_694] = id_698), VOID) };
                        (void)id_699;
                      }
                    } while (while_flag_686);
                    (void)VOID;
                    uint8_t id_700 { 0 };
                    uint32_t id_701 { lebsz_ref_324[id_700] };
                    Size id_702 { Size(id_701) };
                    let_res_685 = id_702;
                  }
                  let_res_682 = let_res_685;
                }
                Size id_703 { Size(sz_322 + let_res_682) };
                Vec<1, Size> id_704 {  id_703  };
                Size let_res_705;
                {
                  Vec<1, Size> sz_ref_325 { id_704 };
                  int32_t id_706 { 0L };
                  Vec<1, int32_t> id_707 {  id_706  };
                  {
                    Vec<1, int32_t> repeat_n_326 { id_707 };
                    bool while_flag_708 { true };
                    do {
                      uint8_t id_709 { 0 };
                      int32_t id_710 { repeat_n_306[id_709] };
                      ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_711 { p_0[id_710] };
                      ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_712 { std::get<1>(id_711) };
                      Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> id_713 { id_712.channels };
                      uint32_t id_714 { id_713.size() };
                      int32_t id_715 { int32_t(id_714) };
                      uint8_t id_716 { 0 };
                      int32_t id_717 { repeat_n_326[id_716] };
                      bool id_718 { bool(id_715 > id_717) };
                      while_flag_708 = id_718;
                      if (while_flag_708) {
                        uint8_t id_719 { 0 };
                        uint8_t id_720 { 0 };
                        Size id_721 { sz_ref_325[id_720] };
                        Size id_722 { 2UL };
                        Size id_723 { Size(id_721 + id_722) };
                        Size let_res_724;
                        {
                          Size sz_328 { id_723 };
                          uint8_t id_725 { 0 };
                          int32_t id_726 { repeat_n_326[id_725] };
                          uint8_t id_727 { 0 };
                          int32_t id_728 { repeat_n_306[id_727] };
                          ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_729 { p_0[id_728] };
                          ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_730 { std::get<1>(id_729) };
                          Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> id_731 { id_730.channels };
                          ::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413 id_732 { id_731[id_726] };
                          ::dessser::gen::output_specs::channel_specs* id_733 { std::get<1>(id_732) };
                          Size id_734 { channel_specs_sersize_of_row_binary(id_733) };
                          Size id_735 { Size(sz_328 + id_734) };
                          let_res_724 = id_735;
                        }
                        Void id_736 { ((void)(sz_ref_325[id_719] = let_res_724), VOID) };
                        (void)id_736;
                        uint8_t id_737 { 0 };
                        uint8_t id_738 { 0 };
                        int32_t id_739 { repeat_n_326[id_738] };
                        int32_t id_740 { 1L };
                        int32_t id_741 { int32_t(id_739 + id_740) };
                        Void id_742 { ((void)(repeat_n_326[id_737] = id_741), VOID) };
                        (void)id_742;
                        (void)id_742;
                      }
                    } while (while_flag_708);
                    (void)VOID;
                  }
                  (void)VOID;
                  uint8_t id_743 { 0 };
                  Size id_744 { sz_ref_325[id_743] };
                  let_res_705 = id_744;
                }
                let_res_674 = let_res_705;
              }
              let_res_518 = let_res_674;
            }
            Void id_745 { ((void)(sz_ref_305[id_508] = let_res_518), VOID) };
            (void)id_745;
            uint8_t id_746 { 0 };
            uint8_t id_747 { 0 };
            int32_t id_748 { repeat_n_306[id_747] };
            int32_t id_749 { 1L };
            int32_t id_750 { int32_t(id_748 + id_749) };
            Void id_751 { ((void)(repeat_n_306[id_746] = id_750), VOID) };
            (void)id_751;
            (void)id_751;
          }
        } while (while_flag_502);
        (void)VOID;
      }
      (void)VOID;
      uint8_t id_752 { 0 };
      Size id_753 { sz_ref_305[id_752] };
      let_res_499 = id_753;
    }
    return let_res_499;
  }
   };
  return fun474;
}
std::function<Size(t&)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_140" (let-pair "dfloat_fst_138" "dfloat_snd_139" (read-u64 little-endian (param 0)) (make-tup (float-of-u64 (identifier "dfloat_fst_138")) (identifier "dfloat_snd_139")))
        (let-pair "dtup_fst_141" "dtup_snd_142" (identifier "dtup_140")
          (let "dtup_146" (let-pair "di16_fst_144" "di16_snd_145" (read-u16 little-endian (identifier "dtup_snd_142")) (make-tup (to-i16 (identifier "di16_fst_144")) (identifier "di16_snd_145")))
            (let-pair "dtup_fst_147" "dtup_snd_148" (identifier "dtup_146")
              (let-pair "du32_fst_150" "du32_snd_151" (read-u32 little-endian (identifier "dtup_snd_148"))
                (make-tup (make-tup (identifier "dtup_fst_141") (identifier "dtup_fst_147") (identifier "du32_fst_150")) (identifier "du32_snd_151"))))))))
 */
static std::function<::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc(Pointer)> channel_specs_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc(Pointer)> fun754 { [&fun754](Pointer p_0) {
    ::dessser::gen::output_specs::t7a47220550fc5126a7b79f1e0c10c645 id_755 { p_0.readU64Le() };
    ::dessser::gen::output_specs::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_756;
    {
      auto dfloat_fst_138 { std::get<0>(id_755) };
      auto dfloat_snd_139 { std::get<1>(id_755) };
      double id_757 { float_of_qword(dfloat_fst_138) };
      ::dessser::gen::output_specs::taebed00ad7fdb3f7ced11d3cfd58aade id_758 { id_757, dfloat_snd_139 };
      letpair_res_756 = id_758;
    }
    ::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc let_res_759;
    {
      ::dessser::gen::output_specs::taebed00ad7fdb3f7ced11d3cfd58aade dtup_140 { letpair_res_756 };
      ::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc letpair_res_760;
      {
        auto dtup_fst_141 { std::get<0>(dtup_140) };
        auto dtup_snd_142 { std::get<1>(dtup_140) };
        ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 id_761 { dtup_snd_142.readU16Le() };
        ::dessser::gen::output_specs::t7a480586af66fc37ae6bc54fa3d03602 letpair_res_762;
        {
          auto di16_fst_144 { std::get<0>(id_761) };
          auto di16_snd_145 { std::get<1>(id_761) };
          int16_t id_763 { int16_t(di16_fst_144) };
          ::dessser::gen::output_specs::t7a480586af66fc37ae6bc54fa3d03602 id_764 { id_763, di16_snd_145 };
          letpair_res_762 = id_764;
        }
        ::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc let_res_765;
        {
          ::dessser::gen::output_specs::t7a480586af66fc37ae6bc54fa3d03602 dtup_146 { letpair_res_762 };
          ::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc letpair_res_766;
          {
            auto dtup_fst_147 { std::get<0>(dtup_146) };
            auto dtup_snd_148 { std::get<1>(dtup_146) };
            ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 id_767 { dtup_snd_148.readU32Le() };
            ::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc letpair_res_768;
            {
              auto du32_fst_150 { std::get<0>(id_767) };
              auto du32_snd_151 { std::get<1>(id_767) };
              ::dessser::gen::output_specs::channel_specs* id_769 { new ::dessser::gen::output_specs::channel_specs({ dtup_fst_141, dtup_fst_147, du32_fst_150 }) };
              ::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc id_770 { id_769, du32_snd_151 };
              letpair_res_768 = id_770;
            }
            letpair_res_766 = letpair_res_768;
          }
          let_res_765 = letpair_res_766;
        }
        letpair_res_760 = let_res_765;
      }
      let_res_759 = letpair_res_760;
    }
    return let_res_759;
  }
   };
  return fun754;
}
std::function<::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc(Pointer)> channel_specs_of_row_binary(channel_specs_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_135" "make_snd_136"
        (let "dsum1_107" (let-pair "du16_fst_102" "du16_snd_103" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_102") (identifier "du16_snd_103")))
          (let-pair "dsum1_fst_108" "dsum1_snd_109" (identifier "dsum1_107")
            (if (eq (u16 0) (identifier "dsum1_fst_108")) (make-tup (construct "[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" 0 (nop)) (identifier "dsum1_snd_109"))
              (seq (assert (eq (identifier "dsum1_fst_108") (u16 1)))
                (let "drec_113" (let-pair "dbool_fst_111" "dbool_snd_112" (read-u8 (identifier "dsum1_snd_109")) (make-tup (not (eq (identifier "dbool_fst_111") (u8 0))) (identifier "dbool_snd_112")))
                  (let-pair "drec_fst_114" "drec_snd_115" (identifier "drec_113")
                    (let "drec_119" (let-pair "du32_fst_117" "du32_snd_118" (read-u32 little-endian (identifier "drec_snd_115")) (make-tup (identifier "du32_fst_117") (identifier "du32_snd_118")))
                      (let-pair "drec_fst_120" "drec_snd_121" (identifier "drec_119")
                        (let-pair "du32_fst_123" "du32_snd_124" (read-u32 little-endian (identifier "drec_snd_121"))
                          (make-tup
                            (construct "[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" 1
                              (make-rec (string "num_batches") (identifier "du32_fst_123") (string "batch_size") (identifier "drec_fst_120") (string "with_index") (identifier "drec_fst_114"))) 
                            (identifier "du32_snd_124"))))))))))) (make-tup (identifier "make_fst_135") (identifier "make_snd_136"))))
 */
static std::function<::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae(Pointer)> file_type_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae(Pointer)> fun771 { [&fun771](Pointer p_0) {
    ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 id_772 { p_0.readU16Le() };
    ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 letpair_res_773;
    {
      auto du16_fst_102 { std::get<0>(id_772) };
      auto du16_snd_103 { std::get<1>(id_772) };
      ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 id_774 { du16_fst_102, du16_snd_103 };
      letpair_res_773 = id_774;
    }
    ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae let_res_775;
    {
      ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 dsum1_107 { letpair_res_773 };
      ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae letpair_res_776;
      {
        auto dsum1_fst_108 { std::get<0>(dsum1_107) };
        auto dsum1_snd_109 { std::get<1>(dsum1_107) };
        uint16_t id_777 { 0 };
        bool id_778 { bool(id_777 == dsum1_fst_108) };
        ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae choose_res_779;
        if (id_778) {
          (void)VOID;
          ::dessser::gen::output_specs::file_type* id_780 { new ::dessser::gen::output_specs::file_type(std::in_place_index<0>, VOID) };
          ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae id_781 { id_780, dsum1_snd_109 };
          choose_res_779 = id_781;
        } else {
          uint16_t id_782 { 1 };
          bool id_783 { bool(dsum1_fst_108 == id_782) };
          Void id_784 { ((void)(assert(id_783)), VOID) };
          (void)id_784;
          ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 id_785 { dsum1_snd_109.readU8() };
          ::dessser::gen::output_specs::t4138de986e20d18b01e4c493dc9d5451 letpair_res_786;
          {
            auto dbool_fst_111 { std::get<0>(id_785) };
            auto dbool_snd_112 { std::get<1>(id_785) };
            uint8_t id_787 { 0 };
            bool id_788 { bool(dbool_fst_111 == id_787) };
            bool id_789 { ! id_788 };
            ::dessser::gen::output_specs::t4138de986e20d18b01e4c493dc9d5451 id_790 { id_789, dbool_snd_112 };
            letpair_res_786 = id_790;
          }
          ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae let_res_791;
          {
            ::dessser::gen::output_specs::t4138de986e20d18b01e4c493dc9d5451 drec_113 { letpair_res_786 };
            ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae letpair_res_792;
            {
              auto drec_fst_114 { std::get<0>(drec_113) };
              auto drec_snd_115 { std::get<1>(drec_113) };
              ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 id_793 { drec_snd_115.readU32Le() };
              ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 letpair_res_794;
              {
                auto du32_fst_117 { std::get<0>(id_793) };
                auto du32_snd_118 { std::get<1>(id_793) };
                ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 id_795 { du32_fst_117, du32_snd_118 };
                letpair_res_794 = id_795;
              }
              ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae let_res_796;
              {
                ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 drec_119 { letpair_res_794 };
                ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae letpair_res_797;
                {
                  auto drec_fst_120 { std::get<0>(drec_119) };
                  auto drec_snd_121 { std::get<1>(drec_119) };
                  ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 id_798 { drec_snd_121.readU32Le() };
                  ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae letpair_res_799;
                  {
                    auto du32_fst_123 { std::get<0>(id_798) };
                    auto du32_snd_124 { std::get<1>(id_798) };
                    ::dessser::gen::output_specs::t16c4cfbc5913dcc373c4d91afa31a65d id_800 { .batch_size = drec_fst_120, .num_batches = du32_fst_123, .with_index = drec_fst_114 };
                    ::dessser::gen::output_specs::file_type* id_801 { new ::dessser::gen::output_specs::file_type(std::in_place_index<1>, id_800) };
                    ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae id_802 { id_801, du32_snd_124 };
                    letpair_res_799 = id_802;
                  }
                  letpair_res_797 = letpair_res_799;
                }
                let_res_796 = letpair_res_797;
              }
              letpair_res_792 = let_res_796;
            }
            let_res_791 = letpair_res_792;
          }
          choose_res_779 = let_res_791;
        }
        letpair_res_776 = choose_res_779;
      }
      let_res_775 = letpair_res_776;
    }
    ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae letpair_res_803;
    {
      auto make_fst_135 { std::get<0>(let_res_775) };
      auto make_snd_136 { std::get<1>(let_res_775) };
      ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae id_804 { make_fst_135, make_snd_136 };
      letpair_res_803 = id_804;
    }
    return letpair_res_803;
  }
   };
  return fun771;
}
std::function<::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae(Pointer)> file_type_of_row_binary(file_type_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_99" "make_snd_100"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let-pair "dsum2_fst_96" "dsum2_snd_97" (apply (ext-identifier file_path of-row-binary) (identifier "dsum1_snd_64"))
                (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey STRING]" 0 (identifier "dsum2_fst_96")) (identifier "dsum2_snd_97")))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let "dstring1_86"
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
                  (let-pair "dstring1_fst_87" "dstring1_snd_88" (identifier "dstring1_86")
                    (let-pair "dstring2_fst_90" "dstring2_snd_91" (read-bytes (identifier "dstring1_snd_88") (identifier "dstring1_fst_87"))
                      (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey STRING]" 1 (string-of-bytes (identifier "dstring2_fst_90"))) (identifier "dstring2_snd_91")))))
                (seq (assert (eq (identifier "dsum1_fst_63") (u16 2)))
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
                      (let-pair "dstring2_fst_75" "dstring2_snd_76" (read-bytes (identifier "dstring1_snd_73") (identifier "dstring1_fst_72"))
                        (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey STRING]" 2 (string-of-bytes (identifier "dstring2_fst_75"))) (identifier "dstring2_snd_76"))))))))))
        (make-tup (identifier "make_fst_99") (identifier "make_snd_100"))))
 */
static std::function<::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df(Pointer)> recipient_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df(Pointer)> fun805 { [&fun805](Pointer p_0) {
    ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 id_806 { p_0.readU16Le() };
    ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 letpair_res_807;
    {
      auto du16_fst_57 { std::get<0>(id_806) };
      auto du16_snd_58 { std::get<1>(id_806) };
      ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 id_808 { du16_fst_57, du16_snd_58 };
      letpair_res_807 = id_808;
    }
    ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df let_res_809;
    {
      ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_807 };
      ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df letpair_res_810;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_811 { 0 };
        bool id_812 { bool(id_811 == dsum1_fst_63) };
        ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df choose_res_813;
        if (id_812) {
          auto fun814 { dessser::gen::file_path::of_row_binary };
          ::dessser::gen::output_specs::tad3a94e851c33888b2891405a4005268 id_815 { fun814(dsum1_snd_64) };
          ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df letpair_res_816;
          {
            auto dsum2_fst_96 { std::get<0>(id_815) };
            auto dsum2_snd_97 { std::get<1>(id_815) };
            ::dessser::gen::output_specs::recipient* id_817 { new ::dessser::gen::output_specs::recipient(std::in_place_index<0>, dsum2_fst_96) };
            ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df id_818 { id_817, dsum2_snd_97 };
            letpair_res_816 = id_818;
          }
          choose_res_813 = letpair_res_816;
        } else {
          uint16_t id_819 { 1 };
          bool id_820 { bool(id_819 == dsum1_fst_63) };
          ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df choose_res_821;
          if (id_820) {
            uint32_t id_822 { 0U };
            Vec<1, uint32_t> id_823 {  id_822  };
            ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c let_res_824;
            {
              Vec<1, uint32_t> leb_ref_80 { id_823 };
              uint8_t id_825 { 0 };
              Vec<1, uint8_t> id_826 {  id_825  };
              ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c let_res_827;
              {
                Vec<1, uint8_t> shft_ref_81 { id_826 };
                Vec<1, Pointer> id_828 {  dsum1_snd_64  };
                ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c let_res_829;
                {
                  Vec<1, Pointer> p_ref_82 { id_828 };
                  bool while_flag_830 { true };
                  do {
                    uint8_t id_831 { 0 };
                    Pointer id_832 { p_ref_82[id_831] };
                    ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 id_833 { id_832.readU8() };
                    bool let_res_834;
                    {
                      ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 leb128_83 { id_833 };
                      bool letpair_res_835;
                      {
                        auto leb128_fst_84 { std::get<0>(leb128_83) };
                        auto leb128_snd_85 { std::get<1>(leb128_83) };
                        uint8_t id_836 { 0 };
                        Void id_837 { ((void)(p_ref_82[id_836] = leb128_snd_85), VOID) };
                        (void)id_837;
                        uint8_t id_838 { 0 };
                        uint8_t id_839 { 127 };
                        uint8_t id_840 { uint8_t(leb128_fst_84 & id_839) };
                        uint32_t id_841 { uint32_t(id_840) };
                        uint8_t id_842 { 0 };
                        uint8_t id_843 { shft_ref_81[id_842] };
                        uint32_t id_844 { uint32_t(id_841 << id_843) };
                        uint8_t id_845 { 0 };
                        uint32_t id_846 { leb_ref_80[id_845] };
                        uint32_t id_847 { uint32_t(id_844 | id_846) };
                        Void id_848 { ((void)(leb_ref_80[id_838] = id_847), VOID) };
                        (void)id_848;
                        uint8_t id_849 { 0 };
                        uint8_t id_850 { 0 };
                        uint8_t id_851 { shft_ref_81[id_850] };
                        uint8_t id_852 { 7 };
                        uint8_t id_853 { uint8_t(id_851 + id_852) };
                        Void id_854 { ((void)(shft_ref_81[id_849] = id_853), VOID) };
                        (void)id_854;
                        uint8_t id_855 { 128 };
                        bool id_856 { bool(leb128_fst_84 >= id_855) };
                        letpair_res_835 = id_856;
                      }
                      let_res_834 = letpair_res_835;
                    }
                    while_flag_830 = let_res_834;
                    if (while_flag_830) {
                      (void)VOID;
                    }
                  } while (while_flag_830);
                  (void)VOID;
                  uint8_t id_857 { 0 };
                  uint32_t id_858 { leb_ref_80[id_857] };
                  Size id_859 { Size(id_858) };
                  uint8_t id_860 { 0 };
                  Pointer id_861 { p_ref_82[id_860] };
                  ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c id_862 { id_859, id_861 };
                  let_res_829 = id_862;
                }
                let_res_827 = let_res_829;
              }
              let_res_824 = let_res_827;
            }
            ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df let_res_863;
            {
              ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c dstring1_86 { let_res_824 };
              ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df letpair_res_864;
              {
                auto dstring1_fst_87 { std::get<0>(dstring1_86) };
                auto dstring1_snd_88 { std::get<1>(dstring1_86) };
                ::dessser::gen::output_specs::t188345aa49abd0cb47ff73fedc219f08 id_865 { dstring1_snd_88.readBytes(dstring1_fst_87) };
                ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df letpair_res_866;
                {
                  auto dstring2_fst_90 { std::get<0>(id_865) };
                  auto dstring2_snd_91 { std::get<1>(id_865) };
                  std::string id_867 { dstring2_fst_90.toString() };
                  ::dessser::gen::output_specs::recipient* id_868 { new ::dessser::gen::output_specs::recipient(std::in_place_index<1>, id_867) };
                  ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df id_869 { id_868, dstring2_snd_91 };
                  letpair_res_866 = id_869;
                }
                letpair_res_864 = letpair_res_866;
              }
              let_res_863 = letpair_res_864;
            }
            choose_res_821 = let_res_863;
          } else {
            uint16_t id_870 { 2 };
            bool id_871 { bool(dsum1_fst_63 == id_870) };
            Void id_872 { ((void)(assert(id_871)), VOID) };
            (void)id_872;
            uint32_t id_873 { 0U };
            Vec<1, uint32_t> id_874 {  id_873  };
            ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c let_res_875;
            {
              Vec<1, uint32_t> leb_ref_65 { id_874 };
              uint8_t id_876 { 0 };
              Vec<1, uint8_t> id_877 {  id_876  };
              ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c let_res_878;
              {
                Vec<1, uint8_t> shft_ref_66 { id_877 };
                Vec<1, Pointer> id_879 {  dsum1_snd_64  };
                ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c let_res_880;
                {
                  Vec<1, Pointer> p_ref_67 { id_879 };
                  bool while_flag_881 { true };
                  do {
                    uint8_t id_882 { 0 };
                    Pointer id_883 { p_ref_67[id_882] };
                    ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 id_884 { id_883.readU8() };
                    bool let_res_885;
                    {
                      ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 leb128_68 { id_884 };
                      bool letpair_res_886;
                      {
                        auto leb128_fst_69 { std::get<0>(leb128_68) };
                        auto leb128_snd_70 { std::get<1>(leb128_68) };
                        uint8_t id_887 { 0 };
                        Void id_888 { ((void)(p_ref_67[id_887] = leb128_snd_70), VOID) };
                        (void)id_888;
                        uint8_t id_889 { 0 };
                        uint8_t id_890 { 127 };
                        uint8_t id_891 { uint8_t(leb128_fst_69 & id_890) };
                        uint32_t id_892 { uint32_t(id_891) };
                        uint8_t id_893 { 0 };
                        uint8_t id_894 { shft_ref_66[id_893] };
                        uint32_t id_895 { uint32_t(id_892 << id_894) };
                        uint8_t id_896 { 0 };
                        uint32_t id_897 { leb_ref_65[id_896] };
                        uint32_t id_898 { uint32_t(id_895 | id_897) };
                        Void id_899 { ((void)(leb_ref_65[id_889] = id_898), VOID) };
                        (void)id_899;
                        uint8_t id_900 { 0 };
                        uint8_t id_901 { 0 };
                        uint8_t id_902 { shft_ref_66[id_901] };
                        uint8_t id_903 { 7 };
                        uint8_t id_904 { uint8_t(id_902 + id_903) };
                        Void id_905 { ((void)(shft_ref_66[id_900] = id_904), VOID) };
                        (void)id_905;
                        uint8_t id_906 { 128 };
                        bool id_907 { bool(leb128_fst_69 >= id_906) };
                        letpair_res_886 = id_907;
                      }
                      let_res_885 = letpair_res_886;
                    }
                    while_flag_881 = let_res_885;
                    if (while_flag_881) {
                      (void)VOID;
                    }
                  } while (while_flag_881);
                  (void)VOID;
                  uint8_t id_908 { 0 };
                  uint32_t id_909 { leb_ref_65[id_908] };
                  Size id_910 { Size(id_909) };
                  uint8_t id_911 { 0 };
                  Pointer id_912 { p_ref_67[id_911] };
                  ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c id_913 { id_910, id_912 };
                  let_res_880 = id_913;
                }
                let_res_878 = let_res_880;
              }
              let_res_875 = let_res_878;
            }
            ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df let_res_914;
            {
              ::dessser::gen::output_specs::t8beb80162423aee37bd383e9b6834c9c dstring1_71 { let_res_875 };
              ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df letpair_res_915;
              {
                auto dstring1_fst_72 { std::get<0>(dstring1_71) };
                auto dstring1_snd_73 { std::get<1>(dstring1_71) };
                ::dessser::gen::output_specs::t188345aa49abd0cb47ff73fedc219f08 id_916 { dstring1_snd_73.readBytes(dstring1_fst_72) };
                ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df letpair_res_917;
                {
                  auto dstring2_fst_75 { std::get<0>(id_916) };
                  auto dstring2_snd_76 { std::get<1>(id_916) };
                  std::string id_918 { dstring2_fst_75.toString() };
                  ::dessser::gen::output_specs::recipient* id_919 { new ::dessser::gen::output_specs::recipient(std::in_place_index<2>, id_918) };
                  ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df id_920 { id_919, dstring2_snd_76 };
                  letpair_res_917 = id_920;
                }
                letpair_res_915 = letpair_res_917;
              }
              let_res_914 = letpair_res_915;
            }
            choose_res_821 = let_res_914;
          }
          choose_res_813 = choose_res_821;
        }
        letpair_res_810 = choose_res_813;
      }
      let_res_809 = letpair_res_810;
    }
    ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df letpair_res_921;
    {
      auto make_fst_99 { std::get<0>(let_res_809) };
      auto make_snd_100 { std::get<1>(let_res_809) };
      ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df id_922 { make_fst_99, make_snd_100 };
      letpair_res_921 = id_922;
    }
    return letpair_res_921;
  }
   };
  return fun805;
}
std::function<::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df(Pointer)> recipient_of_row_binary(recipient_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "dlist4_fst_284" "dlist4_snd_285"
        (let "dlist1_167"
          (let "leb_ref_158" (make-vec (u32 0))
            (let "shft_ref_159" (make-vec (u8 0))
              (let "p_ref_160" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_161" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_160")))
                      (let-pair "leb128_fst_162" "leb128_snd_163" (identifier "leb128_161")
                        (seq (set-vec (u8 0) (identifier "p_ref_160") (identifier "leb128_snd_163"))
                          (set-vec (u8 0) (identifier "leb_ref_158")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_162") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_159"))) (unsafe-nth (u8 0) (identifier "leb_ref_158"))))
                          (set-vec (u8 0) (identifier "shft_ref_159") (add (unsafe-nth (u8 0) (identifier "shft_ref_159")) (u8 7))) 
                          (ge (identifier "leb128_fst_162") (u8 128))))) 
                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_158")) (unsafe-nth (u8 0) (identifier "p_ref_160")))))))
          (let-pair "dlist1_fst_168" "dlist1_snd_169" (identifier "dlist1_167")
            (let "inits_src_ref_170"
              (make-vec
                (make-tup
                  (end-of-list "((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey STRING]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})")
                  (identifier "dlist1_snd_169")))
              (seq
                (let "repeat_n_171" (make-vec (i32 0))
                  (while (gt (to-i32 (identifier "dlist1_fst_168")) (unsafe-nth (u8 0) (identifier "repeat_n_171")))
                    (seq
                      (let "dlist2_172" (unsafe-nth (u8 0) (identifier "inits_src_ref_170"))
                        (let-pair "dlist2_fst_173" "dlist2_snd_174" (identifier "dlist2_172")
                          (set-vec (u8 0) (identifier "inits_src_ref_170")
                            (let "dtup_175" (apply (identifier "recipient-of-row-binary") (identifier "dlist2_snd_174"))
                              (let-pair "dtup_fst_176" "dtup_snd_177" 
                                (identifier "dtup_175")
                                (let "drec_178" (apply (identifier "file_type-of-row-binary") (identifier "dtup_snd_177"))
                                  (let-pair "drec_fst_179" "drec_snd_180" 
                                    (identifier "drec_178")
                                    (let "drec_181" (apply (ext-identifier fieldmask of-row-binary) (identifier "drec_snd_180"))
                                      (let-pair "drec_fst_182" "drec_snd_183" 
                                        (identifier "drec_181")
                                        (let "drec_239"
                                          (let-pair "dlist4_fst_237" "dlist4_snd_238"
                                            (let "dlist1_193"
                                              (let "leb_ref_184" (make-vec (u32 0))
                                                (let "shft_ref_185" (make-vec (u8 0))
                                                  (let "p_ref_186" (make-vec (identifier "drec_snd_183"))
                                                    (seq
                                                      (while
                                                        (let "leb128_187" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_186")))
                                                          (let-pair "leb128_fst_188" "leb128_snd_189" 
                                                            (identifier "leb128_187")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_186") (identifier "leb128_snd_189"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_184")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_188") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_185")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_184")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_185") (add (unsafe-nth (u8 0) (identifier "shft_ref_185")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_188") (u8 128))))) 
                                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_184")) (unsafe-nth (u8 0) (identifier "p_ref_186")))))))
                                              (let-pair "dlist1_fst_194" "dlist1_snd_195" 
                                                (identifier "dlist1_193")
                                                (let "inits_src_ref_196" 
                                                  (make-vec (make-tup (end-of-list "(U16; $raql_value[])") (identifier "dlist1_snd_195")))
                                                  (seq
                                                    (let "repeat_n_197" 
                                                      (make-vec (i32 0))
                                                      (while (gt (to-i32 (identifier "dlist1_fst_194")) (unsafe-nth (u8 0) (identifier "repeat_n_197")))
                                                        (seq
                                                          (let "dlist2_198" 
                                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_196"))
                                                            (let-pair "dlist2_fst_199" "dlist2_snd_200" 
                                                              (identifier "dlist2_198")
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "inits_src_ref_196")
                                                                (let "dtup_204"
                                                                  (let-pair "du16_fst_202" "du16_snd_203" (read-u16 little-endian (identifier "dlist2_snd_200")) (make-tup (identifier "du16_fst_202") (identifier "du16_snd_203")))
                                                                  (let-pair "dtup_fst_205" "dtup_snd_206" 
                                                                    (identifier "dtup_204")
                                                                    (let-pair "dlist4_fst_228" "dlist4_snd_229"
                                                                    (let "dlist1_216"
                                                                    (let "leb_ref_207" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_208" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_209" 
                                                                    (make-vec (identifier "dtup_snd_206"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_210" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_209")))
                                                                    (let-pair "leb128_fst_211" "leb128_snd_212" 
                                                                    (identifier "leb128_210")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_209") (identifier "leb128_snd_212"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_207")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_211") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_208")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_207")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_208") (add (unsafe-nth (u8 0) (identifier "shft_ref_208")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_211") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_207")) (unsafe-nth (u8 0) (identifier "p_ref_209")))))))
                                                                    (let-pair "dlist1_fst_217" "dlist1_snd_218" 
                                                                    (identifier "dlist1_216")
                                                                    (let "inits_src_ref_219" 
                                                                    (make-vec (make-tup (end-of-list "$raql_value") (identifier "dlist1_snd_218")))
                                                                    (seq
                                                                    (let "repeat_n_220" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_217")) (unsafe-nth (u8 0) (identifier "repeat_n_220")))
                                                                    (seq
                                                                    (let "dlist2_221" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_219"))
                                                                    (let-pair "dlist2_fst_222" "dlist2_snd_223" 
                                                                    (identifier "dlist2_221")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_219")
                                                                    (let-pair "dlist3_fst_225" "dlist3_snd_226" 
                                                                    (apply (ext-identifier raql_value of-row-binary) (identifier "dlist2_snd_223"))
                                                                    (make-tup (cons (identifier "dlist3_fst_225") (identifier "dlist2_fst_222")) (identifier "dlist3_snd_226"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_220") (add (unsafe-nth (u8 0) (identifier "repeat_n_220")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_219"))))))
                                                                    (make-tup 
                                                                    (cons (make-tup (identifier "dtup_fst_205") (arr-of-lst-rev (identifier "dlist4_fst_228"))) (identifier "dlist2_fst_199")) 
                                                                    (identifier "dlist4_snd_229")))))))) 
                                                          (set-vec (u8 0) (identifier "repeat_n_197") (add (unsafe-nth (u8 0) (identifier "repeat_n_197")) (i32 1)))))) 
                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_196")))))) 
                                            (make-tup (arr-of-lst-rev (identifier "dlist4_fst_237")) (identifier "dlist4_snd_238")))
                                          (let-pair "drec_fst_240" "drec_snd_241" 
                                            (identifier "drec_239")
                                            (let-pair "dlist4_fst_272" "dlist4_snd_273"
                                              (let "dlist1_251"
                                                (let "leb_ref_242" (make-vec (u32 0))
                                                  (let "shft_ref_243" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_244" 
                                                      (make-vec (identifier "drec_snd_241"))
                                                      (seq
                                                        (while
                                                          (let "leb128_245" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_244")))
                                                            (let-pair "leb128_fst_246" "leb128_snd_247" 
                                                              (identifier "leb128_245")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_244") (identifier "leb128_snd_247"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_242")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_246") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_243")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_242")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_243") (add (unsafe-nth (u8 0) (identifier "shft_ref_243")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_246") (u8 128))))) 
                                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_242")) (unsafe-nth (u8 0) (identifier "p_ref_244")))))))
                                                (let-pair "dlist1_fst_252" "dlist1_snd_253" 
                                                  (identifier "dlist1_251")
                                                  (let "inits_src_ref_254" 
                                                    (make-vec (make-tup (end-of-list "(U16; (channel_specs AS (FLOAT; I16; U32)))") (identifier "dlist1_snd_253")))
                                                    (seq
                                                      (let "repeat_n_255" 
                                                        (make-vec (i32 0))
                                                        (while (gt (to-i32 (identifier "dlist1_fst_252")) (unsafe-nth (u8 0) (identifier "repeat_n_255")))
                                                          (seq
                                                            (let "dlist2_256" 
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_254"))
                                                              (let-pair "dlist2_fst_257" "dlist2_snd_258" 
                                                                (identifier "dlist2_256")
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "inits_src_ref_254")
                                                                  (let "dtup_262"
                                                                    (let-pair "du16_fst_260" "du16_snd_261" 
                                                                    (read-u16 little-endian (identifier "dlist2_snd_258")) 
                                                                    (make-tup (identifier "du16_fst_260") (identifier "du16_snd_261")))
                                                                    (let-pair "dtup_fst_263" "dtup_snd_264" 
                                                                    (identifier "dtup_262")
                                                                    (let-pair "dtup_fst_266" "dtup_snd_267" 
                                                                    (apply (identifier "channel_specs-of-row-binary") (identifier "dtup_snd_264"))
                                                                    (make-tup (cons (make-tup (identifier "dtup_fst_263") (identifier "dtup_fst_266")) (identifier "dlist2_fst_257")) (identifier "dtup_snd_267"))))))))
                                                            (set-vec (u8 0) (identifier "repeat_n_255") (add (unsafe-nth (u8 0) (identifier "repeat_n_255")) (i32 1)))))) 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_254"))))))
                                              (make-tup
                                                (cons
                                                  (make-tup (identifier "dtup_fst_176")
                                                    (make-rec (string "channels") 
                                                      (arr-of-lst-rev (identifier "dlist4_fst_272")) 
                                                      (string "filters") 
                                                      (identifier "drec_fst_240") 
                                                      (string "fieldmask") 
                                                      (identifier "drec_fst_182") 
                                                      (string "file_type") 
                                                      (identifier "drec_fst_179"))) 
                                                  (identifier "dlist2_fst_173")) 
                                                (identifier "dlist4_snd_273")))))))))))))) 
                      (set-vec (u8 0) (identifier "repeat_n_171") (add (unsafe-nth (u8 0) (identifier "repeat_n_171")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "inits_src_ref_170")))))) 
        (make-tup (arr-of-lst-rev (identifier "dlist4_fst_284")) (identifier "dlist4_snd_285"))))
 */
static std::function<::dessser::gen::output_specs::t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::t519c57b31160411c6989716f3a9782e0(Pointer)> fun923 { [&fun923](Pointer p_0) {
    uint32_t id_924 { 0U };
    Vec<1, uint32_t> id_925 {  id_924  };
    ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_926;
    {
      Vec<1, uint32_t> leb_ref_158 { id_925 };
      uint8_t id_927 { 0 };
      Vec<1, uint8_t> id_928 {  id_927  };
      ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_929;
      {
        Vec<1, uint8_t> shft_ref_159 { id_928 };
        Vec<1, Pointer> id_930 {  p_0  };
        ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_931;
        {
          Vec<1, Pointer> p_ref_160 { id_930 };
          bool while_flag_932 { true };
          do {
            uint8_t id_933 { 0 };
            Pointer id_934 { p_ref_160[id_933] };
            ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 id_935 { id_934.readU8() };
            bool let_res_936;
            {
              ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 leb128_161 { id_935 };
              bool letpair_res_937;
              {
                auto leb128_fst_162 { std::get<0>(leb128_161) };
                auto leb128_snd_163 { std::get<1>(leb128_161) };
                uint8_t id_938 { 0 };
                Void id_939 { ((void)(p_ref_160[id_938] = leb128_snd_163), VOID) };
                (void)id_939;
                uint8_t id_940 { 0 };
                uint8_t id_941 { 127 };
                uint8_t id_942 { uint8_t(leb128_fst_162 & id_941) };
                uint32_t id_943 { uint32_t(id_942) };
                uint8_t id_944 { 0 };
                uint8_t id_945 { shft_ref_159[id_944] };
                uint32_t id_946 { uint32_t(id_943 << id_945) };
                uint8_t id_947 { 0 };
                uint32_t id_948 { leb_ref_158[id_947] };
                uint32_t id_949 { uint32_t(id_946 | id_948) };
                Void id_950 { ((void)(leb_ref_158[id_940] = id_949), VOID) };
                (void)id_950;
                uint8_t id_951 { 0 };
                uint8_t id_952 { 0 };
                uint8_t id_953 { shft_ref_159[id_952] };
                uint8_t id_954 { 7 };
                uint8_t id_955 { uint8_t(id_953 + id_954) };
                Void id_956 { ((void)(shft_ref_159[id_951] = id_955), VOID) };
                (void)id_956;
                uint8_t id_957 { 128 };
                bool id_958 { bool(leb128_fst_162 >= id_957) };
                letpair_res_937 = id_958;
              }
              let_res_936 = letpair_res_937;
            }
            while_flag_932 = let_res_936;
            if (while_flag_932) {
              (void)VOID;
            }
          } while (while_flag_932);
          (void)VOID;
          uint8_t id_959 { 0 };
          uint32_t id_960 { leb_ref_158[id_959] };
          uint8_t id_961 { 0 };
          Pointer id_962 { p_ref_160[id_961] };
          ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 id_963 { id_960, id_962 };
          let_res_931 = id_963;
        }
        let_res_929 = let_res_931;
      }
      let_res_926 = let_res_929;
    }
    ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d let_res_964;
    {
      ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 dlist1_167 { let_res_926 };
      ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d letpair_res_965;
      {
        auto dlist1_fst_168 { std::get<0>(dlist1_167) };
        auto dlist1_snd_169 { std::get<1>(dlist1_167) };
        Lst<::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334> endoflist_966;
        ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d id_967 { endoflist_966, dlist1_snd_169 };
        Vec<1, ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d> id_968 {  id_967  };
        ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d let_res_969;
        {
          Vec<1, ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d> inits_src_ref_170 { id_968 };
          int32_t id_970 { 0L };
          Vec<1, int32_t> id_971 {  id_970  };
          {
            Vec<1, int32_t> repeat_n_171 { id_971 };
            bool while_flag_972 { true };
            do {
              int32_t id_973 { int32_t(dlist1_fst_168) };
              uint8_t id_974 { 0 };
              int32_t id_975 { repeat_n_171[id_974] };
              bool id_976 { bool(id_973 > id_975) };
              while_flag_972 = id_976;
              if (while_flag_972) {
                uint8_t id_977 { 0 };
                ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d id_978 { inits_src_ref_170[id_977] };
                {
                  ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d dlist2_172 { id_978 };
                  {
                    auto dlist2_fst_173 { std::get<0>(dlist2_172) };
                    auto dlist2_snd_174 { std::get<1>(dlist2_172) };
                    uint8_t id_979 { 0 };
                    ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df id_980 { recipient_of_row_binary(dlist2_snd_174) };
                    ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d let_res_981;
                    {
                      ::dessser::gen::output_specs::tef522899602bf7c23a3b80730ab356df dtup_175 { id_980 };
                      ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d letpair_res_982;
                      {
                        auto dtup_fst_176 { std::get<0>(dtup_175) };
                        auto dtup_snd_177 { std::get<1>(dtup_175) };
                        ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae id_983 { file_type_of_row_binary(dtup_snd_177) };
                        ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d let_res_984;
                        {
                          ::dessser::gen::output_specs::tc1a246d65b8ec8a1b6abc7902e02e4ae drec_178 { id_983 };
                          ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d letpair_res_985;
                          {
                            auto drec_fst_179 { std::get<0>(drec_178) };
                            auto drec_snd_180 { std::get<1>(drec_178) };
                            auto fun986 { dessser::gen::fieldmask::of_row_binary };
                            ::dessser::gen::output_specs::t65efc37c44620d2af7a978cf67ad8a5b id_987 { fun986(drec_snd_180) };
                            ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d let_res_988;
                            {
                              ::dessser::gen::output_specs::t65efc37c44620d2af7a978cf67ad8a5b drec_181 { id_987 };
                              ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d letpair_res_989;
                              {
                                auto drec_fst_182 { std::get<0>(drec_181) };
                                auto drec_snd_183 { std::get<1>(drec_181) };
                                uint32_t id_990 { 0U };
                                Vec<1, uint32_t> id_991 {  id_990  };
                                ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_992;
                                {
                                  Vec<1, uint32_t> leb_ref_184 { id_991 };
                                  uint8_t id_993 { 0 };
                                  Vec<1, uint8_t> id_994 {  id_993  };
                                  ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_995;
                                  {
                                    Vec<1, uint8_t> shft_ref_185 { id_994 };
                                    Vec<1, Pointer> id_996 {  drec_snd_183  };
                                    ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_997;
                                    {
                                      Vec<1, Pointer> p_ref_186 { id_996 };
                                      bool while_flag_998 { true };
                                      do {
                                        uint8_t id_999 { 0 };
                                        Pointer id_1000 { p_ref_186[id_999] };
                                        ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 id_1001 { id_1000.readU8() };
                                        bool let_res_1002;
                                        {
                                          ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 leb128_187 { id_1001 };
                                          bool letpair_res_1003;
                                          {
                                            auto leb128_fst_188 { std::get<0>(leb128_187) };
                                            auto leb128_snd_189 { std::get<1>(leb128_187) };
                                            uint8_t id_1004 { 0 };
                                            Void id_1005 { ((void)(p_ref_186[id_1004] = leb128_snd_189), VOID) };
                                            (void)id_1005;
                                            uint8_t id_1006 { 0 };
                                            uint8_t id_1007 { 127 };
                                            uint8_t id_1008 { uint8_t(leb128_fst_188 & id_1007) };
                                            uint32_t id_1009 { uint32_t(id_1008) };
                                            uint8_t id_1010 { 0 };
                                            uint8_t id_1011 { shft_ref_185[id_1010] };
                                            uint32_t id_1012 { uint32_t(id_1009 << id_1011) };
                                            uint8_t id_1013 { 0 };
                                            uint32_t id_1014 { leb_ref_184[id_1013] };
                                            uint32_t id_1015 { uint32_t(id_1012 | id_1014) };
                                            Void id_1016 { ((void)(leb_ref_184[id_1006] = id_1015), VOID) };
                                            (void)id_1016;
                                            uint8_t id_1017 { 0 };
                                            uint8_t id_1018 { 0 };
                                            uint8_t id_1019 { shft_ref_185[id_1018] };
                                            uint8_t id_1020 { 7 };
                                            uint8_t id_1021 { uint8_t(id_1019 + id_1020) };
                                            Void id_1022 { ((void)(shft_ref_185[id_1017] = id_1021), VOID) };
                                            (void)id_1022;
                                            uint8_t id_1023 { 128 };
                                            bool id_1024 { bool(leb128_fst_188 >= id_1023) };
                                            letpair_res_1003 = id_1024;
                                          }
                                          let_res_1002 = letpair_res_1003;
                                        }
                                        while_flag_998 = let_res_1002;
                                        if (while_flag_998) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_998);
                                      (void)VOID;
                                      uint8_t id_1025 { 0 };
                                      uint32_t id_1026 { leb_ref_184[id_1025] };
                                      uint8_t id_1027 { 0 };
                                      Pointer id_1028 { p_ref_186[id_1027] };
                                      ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 id_1029 { id_1026, id_1028 };
                                      let_res_997 = id_1029;
                                    }
                                    let_res_995 = let_res_997;
                                  }
                                  let_res_992 = let_res_995;
                                }
                                ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 let_res_1030;
                                {
                                  ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 dlist1_193 { let_res_992 };
                                  ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 letpair_res_1031;
                                  {
                                    auto dlist1_fst_194 { std::get<0>(dlist1_193) };
                                    auto dlist1_snd_195 { std::get<1>(dlist1_193) };
                                    Lst<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> endoflist_1032;
                                    ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 id_1033 { endoflist_1032, dlist1_snd_195 };
                                    Vec<1, ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142> id_1034 {  id_1033  };
                                    ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 let_res_1035;
                                    {
                                      Vec<1, ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142> inits_src_ref_196 { id_1034 };
                                      int32_t id_1036 { 0L };
                                      Vec<1, int32_t> id_1037 {  id_1036  };
                                      {
                                        Vec<1, int32_t> repeat_n_197 { id_1037 };
                                        bool while_flag_1038 { true };
                                        do {
                                          int32_t id_1039 { int32_t(dlist1_fst_194) };
                                          uint8_t id_1040 { 0 };
                                          int32_t id_1041 { repeat_n_197[id_1040] };
                                          bool id_1042 { bool(id_1039 > id_1041) };
                                          while_flag_1038 = id_1042;
                                          if (while_flag_1038) {
                                            uint8_t id_1043 { 0 };
                                            ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 id_1044 { inits_src_ref_196[id_1043] };
                                            {
                                              ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 dlist2_198 { id_1044 };
                                              {
                                                auto dlist2_fst_199 { std::get<0>(dlist2_198) };
                                                auto dlist2_snd_200 { std::get<1>(dlist2_198) };
                                                uint8_t id_1045 { 0 };
                                                ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 id_1046 { dlist2_snd_200.readU16Le() };
                                                ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1047;
                                                {
                                                  auto du16_fst_202 { std::get<0>(id_1046) };
                                                  auto du16_snd_203 { std::get<1>(id_1046) };
                                                  ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 id_1048 { du16_fst_202, du16_snd_203 };
                                                  letpair_res_1047 = id_1048;
                                                }
                                                ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 let_res_1049;
                                                {
                                                  ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 dtup_204 { letpair_res_1047 };
                                                  ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 letpair_res_1050;
                                                  {
                                                    auto dtup_fst_205 { std::get<0>(dtup_204) };
                                                    auto dtup_snd_206 { std::get<1>(dtup_204) };
                                                    uint32_t id_1051 { 0U };
                                                    Vec<1, uint32_t> id_1052 {  id_1051  };
                                                    ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_1053;
                                                    {
                                                      Vec<1, uint32_t> leb_ref_207 { id_1052 };
                                                      uint8_t id_1054 { 0 };
                                                      Vec<1, uint8_t> id_1055 {  id_1054  };
                                                      ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_1056;
                                                      {
                                                        Vec<1, uint8_t> shft_ref_208 { id_1055 };
                                                        Vec<1, Pointer> id_1057 {  dtup_snd_206  };
                                                        ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_1058;
                                                        {
                                                          Vec<1, Pointer> p_ref_209 { id_1057 };
                                                          bool while_flag_1059 { true };
                                                          do {
                                                            uint8_t id_1060 { 0 };
                                                            Pointer id_1061 { p_ref_209[id_1060] };
                                                            ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 id_1062 { id_1061.readU8() };
                                                            bool let_res_1063;
                                                            {
                                                              ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 leb128_210 { id_1062 };
                                                              bool letpair_res_1064;
                                                              {
                                                                auto leb128_fst_211 { std::get<0>(leb128_210) };
                                                                auto leb128_snd_212 { std::get<1>(leb128_210) };
                                                                uint8_t id_1065 { 0 };
                                                                Void id_1066 { ((void)(p_ref_209[id_1065] = leb128_snd_212), VOID) };
                                                                (void)id_1066;
                                                                uint8_t id_1067 { 0 };
                                                                uint8_t id_1068 { 127 };
                                                                uint8_t id_1069 { uint8_t(leb128_fst_211 & id_1068) };
                                                                uint32_t id_1070 { uint32_t(id_1069) };
                                                                uint8_t id_1071 { 0 };
                                                                uint8_t id_1072 { shft_ref_208[id_1071] };
                                                                uint32_t id_1073 { uint32_t(id_1070 << id_1072) };
                                                                uint8_t id_1074 { 0 };
                                                                uint32_t id_1075 { leb_ref_207[id_1074] };
                                                                uint32_t id_1076 { uint32_t(id_1073 | id_1075) };
                                                                Void id_1077 { ((void)(leb_ref_207[id_1067] = id_1076), VOID) };
                                                                (void)id_1077;
                                                                uint8_t id_1078 { 0 };
                                                                uint8_t id_1079 { 0 };
                                                                uint8_t id_1080 { shft_ref_208[id_1079] };
                                                                uint8_t id_1081 { 7 };
                                                                uint8_t id_1082 { uint8_t(id_1080 + id_1081) };
                                                                Void id_1083 { ((void)(shft_ref_208[id_1078] = id_1082), VOID) };
                                                                (void)id_1083;
                                                                uint8_t id_1084 { 128 };
                                                                bool id_1085 { bool(leb128_fst_211 >= id_1084) };
                                                                letpair_res_1064 = id_1085;
                                                              }
                                                              let_res_1063 = letpair_res_1064;
                                                            }
                                                            while_flag_1059 = let_res_1063;
                                                            if (while_flag_1059) {
                                                              (void)VOID;
                                                            }
                                                          } while (while_flag_1059);
                                                          (void)VOID;
                                                          uint8_t id_1086 { 0 };
                                                          uint32_t id_1087 { leb_ref_207[id_1086] };
                                                          uint8_t id_1088 { 0 };
                                                          Pointer id_1089 { p_ref_209[id_1088] };
                                                          ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 id_1090 { id_1087, id_1089 };
                                                          let_res_1058 = id_1090;
                                                        }
                                                        let_res_1056 = let_res_1058;
                                                      }
                                                      let_res_1053 = let_res_1056;
                                                    }
                                                    ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0 let_res_1091;
                                                    {
                                                      ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 dlist1_216 { let_res_1053 };
                                                      ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0 letpair_res_1092;
                                                      {
                                                        auto dlist1_fst_217 { std::get<0>(dlist1_216) };
                                                        auto dlist1_snd_218 { std::get<1>(dlist1_216) };
                                                        Lst<dessser::gen::raql_value::t_ext> endoflist_1093;
                                                        ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0 id_1094 { endoflist_1093, dlist1_snd_218 };
                                                        Vec<1, ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0> id_1095 {  id_1094  };
                                                        ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0 let_res_1096;
                                                        {
                                                          Vec<1, ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0> inits_src_ref_219 { id_1095 };
                                                          int32_t id_1097 { 0L };
                                                          Vec<1, int32_t> id_1098 {  id_1097  };
                                                          {
                                                            Vec<1, int32_t> repeat_n_220 { id_1098 };
                                                            bool while_flag_1099 { true };
                                                            do {
                                                              int32_t id_1100 { int32_t(dlist1_fst_217) };
                                                              uint8_t id_1101 { 0 };
                                                              int32_t id_1102 { repeat_n_220[id_1101] };
                                                              bool id_1103 { bool(id_1100 > id_1102) };
                                                              while_flag_1099 = id_1103;
                                                              if (while_flag_1099) {
                                                                uint8_t id_1104 { 0 };
                                                                ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0 id_1105 { inits_src_ref_219[id_1104] };
                                                                {
                                                                  ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0 dlist2_221 { id_1105 };
                                                                  {
                                                                    auto dlist2_fst_222 { std::get<0>(dlist2_221) };
                                                                    auto dlist2_snd_223 { std::get<1>(dlist2_221) };
                                                                    uint8_t id_1106 { 0 };
                                                                    auto fun1107 { dessser::gen::raql_value::of_row_binary };
                                                                    ::dessser::gen::output_specs::t9cfa78b25ddcb5afc14daf6a802a6f88 id_1108 { fun1107(dlist2_snd_223) };
                                                                    ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0 letpair_res_1109;
                                                                    {
                                                                      auto dlist3_fst_225 { std::get<0>(id_1108) };
                                                                      auto dlist3_snd_226 { std::get<1>(id_1108) };
                                                                      Lst<dessser::gen::raql_value::t_ext> id_1110 { dlist3_fst_225, dlist2_fst_222 };
                                                                      ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0 id_1111 { id_1110, dlist3_snd_226 };
                                                                      letpair_res_1109 = id_1111;
                                                                    }
                                                                    Void id_1112 { ((void)(inits_src_ref_219[id_1106] = letpair_res_1109), VOID) };
                                                                    (void)id_1112;
                                                                  }
                                                                  (void)VOID;
                                                                }
                                                                (void)VOID;
                                                                uint8_t id_1113 { 0 };
                                                                uint8_t id_1114 { 0 };
                                                                int32_t id_1115 { repeat_n_220[id_1114] };
                                                                int32_t id_1116 { 1L };
                                                                int32_t id_1117 { int32_t(id_1115 + id_1116) };
                                                                Void id_1118 { ((void)(repeat_n_220[id_1113] = id_1117), VOID) };
                                                                (void)id_1118;
                                                                (void)id_1118;
                                                              }
                                                            } while (while_flag_1099);
                                                            (void)VOID;
                                                          }
                                                          (void)VOID;
                                                          uint8_t id_1119 { 0 };
                                                          ::dessser::gen::output_specs::t926078c4ade3e1c01ca9446f92019ce0 id_1120 { inits_src_ref_219[id_1119] };
                                                          let_res_1096 = id_1120;
                                                        }
                                                        letpair_res_1092 = let_res_1096;
                                                      }
                                                      let_res_1091 = letpair_res_1092;
                                                    }
                                                    ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 letpair_res_1121;
                                                    {
                                                      auto dlist4_fst_228 { std::get<0>(let_res_1091) };
                                                      auto dlist4_snd_229 { std::get<1>(let_res_1091) };
                                                      Arr<dessser::gen::raql_value::t_ext> id_1122 { dlist4_fst_228.toListRev() };
                                                      ::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5 id_1123 { dtup_fst_205, id_1122 };
                                                      Lst<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> id_1124 { id_1123, dlist2_fst_199 };
                                                      ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 id_1125 { id_1124, dlist4_snd_229 };
                                                      letpair_res_1121 = id_1125;
                                                    }
                                                    letpair_res_1050 = letpair_res_1121;
                                                  }
                                                  let_res_1049 = letpair_res_1050;
                                                }
                                                Void id_1126 { ((void)(inits_src_ref_196[id_1045] = let_res_1049), VOID) };
                                                (void)id_1126;
                                              }
                                              (void)VOID;
                                            }
                                            (void)VOID;
                                            uint8_t id_1127 { 0 };
                                            uint8_t id_1128 { 0 };
                                            int32_t id_1129 { repeat_n_197[id_1128] };
                                            int32_t id_1130 { 1L };
                                            int32_t id_1131 { int32_t(id_1129 + id_1130) };
                                            Void id_1132 { ((void)(repeat_n_197[id_1127] = id_1131), VOID) };
                                            (void)id_1132;
                                            (void)id_1132;
                                          }
                                        } while (while_flag_1038);
                                        (void)VOID;
                                      }
                                      (void)VOID;
                                      uint8_t id_1133 { 0 };
                                      ::dessser::gen::output_specs::t9bf9d023de0a28608cb4fee6b41b5142 id_1134 { inits_src_ref_196[id_1133] };
                                      let_res_1035 = id_1134;
                                    }
                                    letpair_res_1031 = let_res_1035;
                                  }
                                  let_res_1030 = letpair_res_1031;
                                }
                                ::dessser::gen::output_specs::tf52ce74d21915aee451d96c2d72ff42e letpair_res_1135;
                                {
                                  auto dlist4_fst_237 { std::get<0>(let_res_1030) };
                                  auto dlist4_snd_238 { std::get<1>(let_res_1030) };
                                  Arr<::dessser::gen::output_specs::t4b7f8f0e420ffe218b8bc466a29068c5> id_1136 { dlist4_fst_237.toListRev() };
                                  ::dessser::gen::output_specs::tf52ce74d21915aee451d96c2d72ff42e id_1137 { id_1136, dlist4_snd_238 };
                                  letpair_res_1135 = id_1137;
                                }
                                ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d let_res_1138;
                                {
                                  ::dessser::gen::output_specs::tf52ce74d21915aee451d96c2d72ff42e drec_239 { letpair_res_1135 };
                                  ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d letpair_res_1139;
                                  {
                                    auto drec_fst_240 { std::get<0>(drec_239) };
                                    auto drec_snd_241 { std::get<1>(drec_239) };
                                    uint32_t id_1140 { 0U };
                                    Vec<1, uint32_t> id_1141 {  id_1140  };
                                    ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_1142;
                                    {
                                      Vec<1, uint32_t> leb_ref_242 { id_1141 };
                                      uint8_t id_1143 { 0 };
                                      Vec<1, uint8_t> id_1144 {  id_1143  };
                                      ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_1145;
                                      {
                                        Vec<1, uint8_t> shft_ref_243 { id_1144 };
                                        Vec<1, Pointer> id_1146 {  drec_snd_241  };
                                        ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 let_res_1147;
                                        {
                                          Vec<1, Pointer> p_ref_244 { id_1146 };
                                          bool while_flag_1148 { true };
                                          do {
                                            uint8_t id_1149 { 0 };
                                            Pointer id_1150 { p_ref_244[id_1149] };
                                            ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 id_1151 { id_1150.readU8() };
                                            bool let_res_1152;
                                            {
                                              ::dessser::gen::output_specs::tb3f98ea670610d40658a618de3ec7b90 leb128_245 { id_1151 };
                                              bool letpair_res_1153;
                                              {
                                                auto leb128_fst_246 { std::get<0>(leb128_245) };
                                                auto leb128_snd_247 { std::get<1>(leb128_245) };
                                                uint8_t id_1154 { 0 };
                                                Void id_1155 { ((void)(p_ref_244[id_1154] = leb128_snd_247), VOID) };
                                                (void)id_1155;
                                                uint8_t id_1156 { 0 };
                                                uint8_t id_1157 { 127 };
                                                uint8_t id_1158 { uint8_t(leb128_fst_246 & id_1157) };
                                                uint32_t id_1159 { uint32_t(id_1158) };
                                                uint8_t id_1160 { 0 };
                                                uint8_t id_1161 { shft_ref_243[id_1160] };
                                                uint32_t id_1162 { uint32_t(id_1159 << id_1161) };
                                                uint8_t id_1163 { 0 };
                                                uint32_t id_1164 { leb_ref_242[id_1163] };
                                                uint32_t id_1165 { uint32_t(id_1162 | id_1164) };
                                                Void id_1166 { ((void)(leb_ref_242[id_1156] = id_1165), VOID) };
                                                (void)id_1166;
                                                uint8_t id_1167 { 0 };
                                                uint8_t id_1168 { 0 };
                                                uint8_t id_1169 { shft_ref_243[id_1168] };
                                                uint8_t id_1170 { 7 };
                                                uint8_t id_1171 { uint8_t(id_1169 + id_1170) };
                                                Void id_1172 { ((void)(shft_ref_243[id_1167] = id_1171), VOID) };
                                                (void)id_1172;
                                                uint8_t id_1173 { 128 };
                                                bool id_1174 { bool(leb128_fst_246 >= id_1173) };
                                                letpair_res_1153 = id_1174;
                                              }
                                              let_res_1152 = letpair_res_1153;
                                            }
                                            while_flag_1148 = let_res_1152;
                                            if (while_flag_1148) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_1148);
                                          (void)VOID;
                                          uint8_t id_1175 { 0 };
                                          uint32_t id_1176 { leb_ref_242[id_1175] };
                                          uint8_t id_1177 { 0 };
                                          Pointer id_1178 { p_ref_244[id_1177] };
                                          ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 id_1179 { id_1176, id_1178 };
                                          let_res_1147 = id_1179;
                                        }
                                        let_res_1145 = let_res_1147;
                                      }
                                      let_res_1142 = let_res_1145;
                                    }
                                    ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f let_res_1180;
                                    {
                                      ::dessser::gen::output_specs::t405eb186408556fed8f2c41523c07d13 dlist1_251 { let_res_1142 };
                                      ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f letpair_res_1181;
                                      {
                                        auto dlist1_fst_252 { std::get<0>(dlist1_251) };
                                        auto dlist1_snd_253 { std::get<1>(dlist1_251) };
                                        Lst<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> endoflist_1182;
                                        ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f id_1183 { endoflist_1182, dlist1_snd_253 };
                                        Vec<1, ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f> id_1184 {  id_1183  };
                                        ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f let_res_1185;
                                        {
                                          Vec<1, ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f> inits_src_ref_254 { id_1184 };
                                          int32_t id_1186 { 0L };
                                          Vec<1, int32_t> id_1187 {  id_1186  };
                                          {
                                            Vec<1, int32_t> repeat_n_255 { id_1187 };
                                            bool while_flag_1188 { true };
                                            do {
                                              int32_t id_1189 { int32_t(dlist1_fst_252) };
                                              uint8_t id_1190 { 0 };
                                              int32_t id_1191 { repeat_n_255[id_1190] };
                                              bool id_1192 { bool(id_1189 > id_1191) };
                                              while_flag_1188 = id_1192;
                                              if (while_flag_1188) {
                                                uint8_t id_1193 { 0 };
                                                ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f id_1194 { inits_src_ref_254[id_1193] };
                                                {
                                                  ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f dlist2_256 { id_1194 };
                                                  {
                                                    auto dlist2_fst_257 { std::get<0>(dlist2_256) };
                                                    auto dlist2_snd_258 { std::get<1>(dlist2_256) };
                                                    uint8_t id_1195 { 0 };
                                                    ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 id_1196 { dlist2_snd_258.readU16Le() };
                                                    ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1197;
                                                    {
                                                      auto du16_fst_260 { std::get<0>(id_1196) };
                                                      auto du16_snd_261 { std::get<1>(id_1196) };
                                                      ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 id_1198 { du16_fst_260, du16_snd_261 };
                                                      letpair_res_1197 = id_1198;
                                                    }
                                                    ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f let_res_1199;
                                                    {
                                                      ::dessser::gen::output_specs::t22a32080ad88ab548b80077a17b7dd46 dtup_262 { letpair_res_1197 };
                                                      ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f letpair_res_1200;
                                                      {
                                                        auto dtup_fst_263 { std::get<0>(dtup_262) };
                                                        auto dtup_snd_264 { std::get<1>(dtup_262) };
                                                        ::dessser::gen::output_specs::t6df20c301dedeef88b07b4e609cf70cc id_1201 { channel_specs_of_row_binary(dtup_snd_264) };
                                                        ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f letpair_res_1202;
                                                        {
                                                          auto dtup_fst_266 { std::get<0>(id_1201) };
                                                          auto dtup_snd_267 { std::get<1>(id_1201) };
                                                          ::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413 id_1203 { dtup_fst_263, dtup_fst_266 };
                                                          Lst<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> id_1204 { id_1203, dlist2_fst_257 };
                                                          ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f id_1205 { id_1204, dtup_snd_267 };
                                                          letpair_res_1202 = id_1205;
                                                        }
                                                        letpair_res_1200 = letpair_res_1202;
                                                      }
                                                      let_res_1199 = letpair_res_1200;
                                                    }
                                                    Void id_1206 { ((void)(inits_src_ref_254[id_1195] = let_res_1199), VOID) };
                                                    (void)id_1206;
                                                  }
                                                  (void)VOID;
                                                }
                                                (void)VOID;
                                                uint8_t id_1207 { 0 };
                                                uint8_t id_1208 { 0 };
                                                int32_t id_1209 { repeat_n_255[id_1208] };
                                                int32_t id_1210 { 1L };
                                                int32_t id_1211 { int32_t(id_1209 + id_1210) };
                                                Void id_1212 { ((void)(repeat_n_255[id_1207] = id_1211), VOID) };
                                                (void)id_1212;
                                                (void)id_1212;
                                              }
                                            } while (while_flag_1188);
                                            (void)VOID;
                                          }
                                          (void)VOID;
                                          uint8_t id_1213 { 0 };
                                          ::dessser::gen::output_specs::tcade6c15df3647aa3a87a1f7a3c4618f id_1214 { inits_src_ref_254[id_1213] };
                                          let_res_1185 = id_1214;
                                        }
                                        letpair_res_1181 = let_res_1185;
                                      }
                                      let_res_1180 = letpair_res_1181;
                                    }
                                    ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d letpair_res_1215;
                                    {
                                      auto dlist4_fst_272 { std::get<0>(let_res_1180) };
                                      auto dlist4_snd_273 { std::get<1>(let_res_1180) };
                                      Arr<::dessser::gen::output_specs::t0e5aeccd6bdb25fe3e41dac725c20413> id_1216 { dlist4_fst_272.toListRev() };
                                      ::dessser::gen::output_specs::t92f55efe014c86abbab68bfc5de4a3b0 id_1217 { .channels = id_1216, .fieldmask = drec_fst_182, .file_type = drec_fst_179, .filters = drec_fst_240 };
                                      ::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334 id_1218 { dtup_fst_176, id_1217 };
                                      Lst<::dessser::gen::output_specs::tc5008a31fa7e282d367c2301cc4f4334> id_1219 { id_1218, dlist2_fst_173 };
                                      ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d id_1220 { id_1219, dlist4_snd_273 };
                                      letpair_res_1215 = id_1220;
                                    }
                                    letpair_res_1139 = letpair_res_1215;
                                  }
                                  let_res_1138 = letpair_res_1139;
                                }
                                letpair_res_989 = let_res_1138;
                              }
                              let_res_988 = letpair_res_989;
                            }
                            letpair_res_985 = let_res_988;
                          }
                          let_res_984 = letpair_res_985;
                        }
                        letpair_res_982 = let_res_984;
                      }
                      let_res_981 = letpair_res_982;
                    }
                    Void id_1221 { ((void)(inits_src_ref_170[id_979] = let_res_981), VOID) };
                    (void)id_1221;
                  }
                  (void)VOID;
                }
                (void)VOID;
                uint8_t id_1222 { 0 };
                uint8_t id_1223 { 0 };
                int32_t id_1224 { repeat_n_171[id_1223] };
                int32_t id_1225 { 1L };
                int32_t id_1226 { int32_t(id_1224 + id_1225) };
                Void id_1227 { ((void)(repeat_n_171[id_1222] = id_1226), VOID) };
                (void)id_1227;
                (void)id_1227;
              }
            } while (while_flag_972);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_1228 { 0 };
          ::dessser::gen::output_specs::tb8cbc3be8a7d997e57f8bd003142375d id_1229 { inits_src_ref_170[id_1228] };
          let_res_969 = id_1229;
        }
        letpair_res_965 = let_res_969;
      }
      let_res_964 = letpair_res_965;
    }
    ::dessser::gen::output_specs::t519c57b31160411c6989716f3a9782e0 letpair_res_1230;
    {
      auto dlist4_fst_284 { std::get<0>(let_res_964) };
      auto dlist4_snd_285 { std::get<1>(let_res_964) };
      t id_1231 { dlist4_fst_284.toListRev() };
      ::dessser::gen::output_specs::t519c57b31160411c6989716f3a9782e0 id_1232 { id_1231, dlist4_snd_285 };
      letpair_res_1230 = id_1232;
    }
    return letpair_res_1230;
  }
   };
  return fun923;
}
std::function<::dessser::gen::output_specs::t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary(of_row_binary_init());

typedef t t_ext;

}
