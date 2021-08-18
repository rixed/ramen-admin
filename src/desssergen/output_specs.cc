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
struct ta0e29e77f0acb0eb5f11e4458453275a : public std::variant<
  dessser::gen::file_path::t_ext,
  std::string,
  std::string
> { using variant::variant; };
struct t85afb1ddd9e9c7584ddc9641e56d5259 {
  bool with_index;
  uint32_t batch_size;
  uint32_t num_batches;
  bool operator==(t85afb1ddd9e9c7584ddc9641e56d5259 const &other) const {
    return with_index == other.with_index && batch_size == other.batch_size && num_batches == other.num_batches;
  }
};
struct tfab2a4fd81d3f08b2a2e9a273cf4a0a2 : public std::variant<
  Void,
  t85afb1ddd9e9c7584ddc9641e56d5259
> { using variant::variant; };
typedef std::tuple<
  uint16_t,
  Arr<dessser::gen::raql_value::t_ext>
> t4b7f8f0e420ffe218b8bc466a29068c5;

struct tff75d16e75a2c4d2863a7b1192f88f0c : public std::tuple<
  double,
  int16_t,
  uint32_t
> { using tuple::tuple; };
typedef std::tuple<
  uint16_t,
  tff75d16e75a2c4d2863a7b1192f88f0c
> t22a714ea36a3b324d44e75eb47493150;

struct tc5896c929a1575847e04404d6e3e9b96 {
  tfab2a4fd81d3f08b2a2e9a273cf4a0a2 file_type;
  dessser::gen::fieldmask::t_ext fieldmask;
  Arr<t4b7f8f0e420ffe218b8bc466a29068c5> filters;
  Arr<t22a714ea36a3b324d44e75eb47493150> channels;
  bool operator==(tc5896c929a1575847e04404d6e3e9b96 const &other) const {
    return file_type == other.file_type && fieldmask == other.fieldmask && filters == other.filters && channels == other.channels;
  }
};
typedef std::tuple<
  ta0e29e77f0acb0eb5f11e4458453275a,
  tc5896c929a1575847e04404d6e3e9b96
> t5b5f28d070eb85f8046479df0051225b;

typedef Arr<t5b5f28d070eb85f8046479df0051225b> t;
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
  Lst<t5b5f28d070eb85f8046479df0051225b>,
  Pointer
> te50b958a36465a4651705737b018bd7a;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  ta0e29e77f0acb0eb5f11e4458453275a,
  Pointer
> ta8afea4d612b1e9184fb2092476fdaa7;

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
  tfab2a4fd81d3f08b2a2e9a273cf4a0a2,
  Pointer
> t158eb66ba798bc5380478692292da7e1;

typedef std::tuple<
  bool,
  Pointer
> t4138de986e20d18b01e4c493dc9d5451;

typedef std::tuple<
  dessser::gen::fieldmask::t_ext,
  Pointer
> t65efc37c44620d2af7a978cf67ad8a5b;

typedef std::tuple<
  Lst<t4b7f8f0e420ffe218b8bc466a29068c5>,
  Pointer
> t4bb0296b7c670bf357b420ee069396e5;

typedef std::tuple<
  Lst<dessser::gen::raql_value::t_ext>,
  Pointer
> t926078c4ade3e1c01ca9446f92019ce0;

typedef std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> t9cfa78b25ddcb5afc14daf6a802a6f88;

typedef std::tuple<
  Arr<t4b7f8f0e420ffe218b8bc466a29068c5>,
  Pointer
> ta4a7ff0e30d8b86e7b4596cdcfc47732;

typedef std::tuple<
  Lst<t22a714ea36a3b324d44e75eb47493150>,
  Pointer
> t3b5f41d7f03bcceefd95038c1a32b873;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

typedef std::tuple<
  double,
  Pointer
> taebed00ad7fdb3f7ced11d3cfd58aade;

typedef std::tuple<
  int16_t,
  Pointer
> t7a480586af66fc37ae6bc54fa3d03602;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("([DirectFile $file_path | IndirectFile STRING | SyncKey STRING]; {file_type: [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]; fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (FLOAT; I16; U32))[]})[]" "Ptr")
      (let "dst_ref_322"
        (make-vec
          (let "leb128_sz_320" (make-vec (cardinality (param 0)))
            (let "leb128_ptr_321" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_321")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_321"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_320"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_320"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_320"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_320") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_320")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_320")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_321"))))))
        (let "n_ref_323" (make-vec (i32 0))
          (seq
            (for-each "x_324" (param 0)
              (seq
                (set-vec (u8 0) (identifier "dst_ref_322")
                  (let "stup_dst_332"
                    (let "stup_dst_325" (unsafe-nth (u8 0) (identifier "dst_ref_322"))
                      (let "ssum_dst_327" (write-u16 little-endian (identifier "stup_dst_325") (label-of (get-item 0 (identifier "x_324"))))
                        (if (eq (u16 0) (label-of (get-item 0 (identifier "x_324")))) 
                          (apply (ext-identifier file_path to-row-binary) (get-alt "DirectFile" (get-item 0 (identifier "x_324"))) (identifier "ssum_dst_327"))
                          (if (eq (u16 1) (label-of (get-item 0 (identifier "x_324"))))
                            (write-bytes
                              (let "leb128_sz_330" (make-vec (string-length (get-alt "IndirectFile" (get-item 0 (identifier "x_324")))))
                                (let "leb128_ptr_331" (make-vec (identifier "ssum_dst_327"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_331")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_331"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_330"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_330"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_330"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_330") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_330")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_330")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_331"))))) 
                              (bytes-of-string (get-alt "IndirectFile" (get-item 0 (identifier "x_324")))))
                            (seq (assert (eq (label-of (get-item 0 (identifier "x_324"))) (u16 2)))
                              (write-bytes
                                (let "leb128_sz_328" (make-vec (string-length (get-alt "SyncKey" (get-item 0 (identifier "x_324")))))
                                  (let "leb128_ptr_329" (make-vec (identifier "ssum_dst_327"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_329")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_329"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_328"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_328"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_328"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_328") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_328")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_328")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_329"))))) 
                                (bytes-of-string (get-alt "SyncKey" (get-item 0 (identifier "x_324"))))))))))
                    (let "srec_dst_351"
                      (let "srec_dst_338"
                        (let "srec_dst_337"
                          (let "ssum_dst_334" (write-u16 little-endian (identifier "stup_dst_332") (label-of (get-field "file_type" (get-item 1 (identifier "x_324")))))
                            (if (eq (u16 0) (label-of (get-field "file_type" (get-item 1 (identifier "x_324"))))) 
                              (identifier "ssum_dst_334")
                              (seq (assert (eq (label-of (get-field "file_type" (get-item 1 (identifier "x_324")))) (u16 1)))
                                (let "srec_dst_336"
                                  (let "srec_dst_335" (write-u8 (identifier "ssum_dst_334") (u8-of-bool (get-field "with_index" (get-alt "Orc" (get-field "file_type" (get-item 1 (identifier "x_324")))))))
                                    (write-u32 little-endian (identifier "srec_dst_335") (get-field "batch_size" (get-alt "Orc" (get-field "file_type" (get-item 1 (identifier "x_324")))))))
                                  (write-u32 little-endian (identifier "srec_dst_336") (get-field "num_batches" (get-alt "Orc" (get-field "file_type" (get-item 1 (identifier "x_324"))))))))))
                          (apply (ext-identifier fieldmask to-row-binary) (get-field "fieldmask" (get-item 1 (identifier "x_324"))) (identifier "srec_dst_337")))
                        (let "dst_ref_341"
                          (make-vec
                            (let "leb128_sz_339" (make-vec (cardinality (get-field "filters" (get-item 1 (identifier "x_324")))))
                              (let "leb128_ptr_340" (make-vec (identifier "srec_dst_338"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_340")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_340"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_339"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_339"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_339"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_339") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_339")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_339")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_340"))))))
                          (let "n_ref_342" (make-vec (i32 0))
                            (seq
                              (for-each "x_343" (get-field "filters" (get-item 1 (identifier "x_324")))
                                (seq
                                  (set-vec (u8 0) (identifier "dst_ref_341")
                                    (let "stup_dst_345" (let "stup_dst_344" (unsafe-nth (u8 0) (identifier "dst_ref_341")) (write-u16 little-endian (identifier "stup_dst_344") (get-item 0 (identifier "x_343"))))
                                      (let "dst_ref_348"
                                        (make-vec
                                          (let "leb128_sz_346" (make-vec (cardinality (get-item 1 (identifier "x_343"))))
                                            (let "leb128_ptr_347" (make-vec (identifier "stup_dst_345"))
                                              (seq
                                                (while
                                                  (seq
                                                    (set-vec (u8 0) (identifier "leb128_ptr_347")
                                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_347"))
                                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_346"))) 
                                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_346"))) 
                                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_346"))) (u8 128)))))
                                                    (set-vec (u8 0) (identifier "leb128_sz_346") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_346")) (u8 7)))
                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_346")) (u32 0))) 
                                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_347"))))))
                                        (let "n_ref_349" (make-vec (i32 0))
                                          (seq
                                            (for-each "x_350" (get-item 1 (identifier "x_343"))
                                              (seq (set-vec (u8 0) (identifier "dst_ref_348") (apply (ext-identifier raql_value to-row-binary) (identifier "x_350") (unsafe-nth (u8 0) (identifier "dst_ref_348"))))
                                                (set-vec (u8 0) (identifier "n_ref_349") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_349")))))) 
                                            (unsafe-nth (u8 0) (identifier "dst_ref_348"))))))) 
                                  (set-vec (u8 0) (identifier "n_ref_342") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_342")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_341"))))))
                      (let "dst_ref_354"
                        (make-vec
                          (let "leb128_sz_352" (make-vec (cardinality (get-field "channels" (get-item 1 (identifier "x_324")))))
                            (let "leb128_ptr_353" (make-vec (identifier "srec_dst_351"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_353")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_353"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_352"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_352"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_352"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_352") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_352")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_352")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_353"))))))
                        (let "n_ref_355" (make-vec (i32 0))
                          (seq
                            (for-each "x_356" (get-field "channels" (get-item 1 (identifier "x_324")))
                              (seq
                                (set-vec (u8 0) (identifier "dst_ref_354")
                                  (let "stup_dst_358" (let "stup_dst_357" (unsafe-nth (u8 0) (identifier "dst_ref_354")) (write-u16 little-endian (identifier "stup_dst_357") (get-item 0 (identifier "x_356"))))
                                    (let "stup_dst_360"
                                      (let "stup_dst_359" (write-u64 little-endian (identifier "stup_dst_358") (u64-of-float (get-item 0 (get-item 1 (identifier "x_356")))))
                                        (write-u16 little-endian (identifier "stup_dst_359") (to-u16 (get-item 1 (get-item 1 (identifier "x_356"))))))
                                      (write-u32 little-endian (identifier "stup_dst_360") (get-item 2 (get-item 1 (identifier "x_356")))))))
                                (set-vec (u8 0) (identifier "n_ref_355") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_355")))))) 
                            (unsafe-nth (u8 0) (identifier "dst_ref_354")))))))) 
                (set-vec (u8 0) (identifier "n_ref_323") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_323")))))) 
            (unsafe-nth (u8 0) (identifier "dst_ref_322"))))))
 */
static std::function<Pointer(t&,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t&,Pointer)> fun0 { [&fun0](t& p_0, Pointer p_1) {
    uint32_t id_1 { p_0.size() };
    Vec<1, uint32_t> id_2 {  id_1  };
    Pointer let_res_3;
    {
      Vec<1, uint32_t> leb128_sz_320 { id_2 };
      Vec<1, Pointer> id_4 {  p_1  };
      Pointer let_res_5;
      {
        Vec<1, Pointer> leb128_ptr_321 { id_4 };
        bool while_flag_6 { true };
        do {
          uint8_t id_7 { 0 };
          uint8_t id_8 { 0 };
          Pointer id_9 { leb128_ptr_321[id_8] };
          uint32_t id_10 { 128U };
          uint8_t id_11 { 0 };
          uint32_t id_12 { leb128_sz_320[id_11] };
          bool id_13 { bool(id_10 > id_12) };
          uint8_t choose_res_14;
          if (id_13) {
            uint8_t id_15 { 0 };
            uint32_t id_16 { leb128_sz_320[id_15] };
            uint8_t id_17 { uint8_t(id_16) };
            choose_res_14 = id_17;
          } else {
            uint8_t id_18 { 0 };
            uint32_t id_19 { leb128_sz_320[id_18] };
            uint8_t id_20 { uint8_t(id_19) };
            uint8_t id_21 { 128 };
            uint8_t id_22 { uint8_t(id_20 | id_21) };
            choose_res_14 = id_22;
          }
          Pointer id_23 { id_9.writeU8(choose_res_14) };
          Void id_24 { ((void)(leb128_ptr_321[id_7] = id_23), VOID) };
          (void)id_24;
          uint8_t id_25 { 0 };
          uint8_t id_26 { 0 };
          uint32_t id_27 { leb128_sz_320[id_26] };
          uint8_t id_28 { 7 };
          uint32_t id_29 { uint32_t(id_27 >> id_28) };
          Void id_30 { ((void)(leb128_sz_320[id_25] = id_29), VOID) };
          (void)id_30;
          uint8_t id_31 { 0 };
          uint32_t id_32 { leb128_sz_320[id_31] };
          uint32_t id_33 { 0U };
          bool id_34 { bool(id_32 > id_33) };
          while_flag_6 = id_34;
          if (while_flag_6) {
            (void)VOID;
          }
        } while (while_flag_6);
        (void)VOID;
        uint8_t id_35 { 0 };
        Pointer id_36 { leb128_ptr_321[id_35] };
        let_res_5 = id_36;
      }
      let_res_3 = let_res_5;
    }
    Vec<1, Pointer> id_37 {  let_res_3  };
    Pointer let_res_38;
    {
      Vec<1, Pointer> dst_ref_322 { id_37 };
      int32_t id_39 { 0L };
      Vec<1, int32_t> id_40 {  id_39  };
      Pointer let_res_41;
      {
        Vec<1, int32_t> n_ref_323 { id_40 };
        for (t5b5f28d070eb85f8046479df0051225b x_324 : p_0) {
          uint8_t id_42 { 0 };
          uint8_t id_43 { 0 };
          Pointer id_44 { dst_ref_322[id_43] };
          Pointer let_res_45;
          {
            Pointer stup_dst_325 { id_44 };
            ta0e29e77f0acb0eb5f11e4458453275a id_46 { std::get<0>(x_324) };
            uint16_t id_47 { uint16_t(id_46.index()) };
            Pointer id_48 { stup_dst_325.writeU16Le(id_47) };
            Pointer let_res_49;
            {
              Pointer ssum_dst_327 { id_48 };
              uint16_t id_50 { 0 };
              ta0e29e77f0acb0eb5f11e4458453275a id_51 { std::get<0>(x_324) };
              uint16_t id_52 { uint16_t(id_51.index()) };
              bool id_53 { bool(id_50 == id_52) };
              Pointer choose_res_54;
              if (id_53) {
                auto fun55 { dessser::gen::file_path::to_row_binary };
                ta0e29e77f0acb0eb5f11e4458453275a id_56 { std::get<0>(x_324) };
                dessser::gen::file_path::t_ext id_57 { std::get<0>(id_56) };
                Pointer id_58 { fun55(id_57, ssum_dst_327) };
                choose_res_54 = id_58;
              } else {
                uint16_t id_59 { 1 };
                ta0e29e77f0acb0eb5f11e4458453275a id_60 { std::get<0>(x_324) };
                uint16_t id_61 { uint16_t(id_60.index()) };
                bool id_62 { bool(id_59 == id_61) };
                Pointer choose_res_63;
                if (id_62) {
                  ta0e29e77f0acb0eb5f11e4458453275a id_64 { std::get<0>(x_324) };
                  std::string id_65 { std::get<1>(id_64) };
                  uint32_t id_66 { (uint32_t)id_65.size() };
                  Vec<1, uint32_t> id_67 {  id_66  };
                  Pointer let_res_68;
                  {
                    Vec<1, uint32_t> leb128_sz_330 { id_67 };
                    Vec<1, Pointer> id_69 {  ssum_dst_327  };
                    Pointer let_res_70;
                    {
                      Vec<1, Pointer> leb128_ptr_331 { id_69 };
                      bool while_flag_71 { true };
                      do {
                        uint8_t id_72 { 0 };
                        uint8_t id_73 { 0 };
                        Pointer id_74 { leb128_ptr_331[id_73] };
                        uint32_t id_75 { 128U };
                        uint8_t id_76 { 0 };
                        uint32_t id_77 { leb128_sz_330[id_76] };
                        bool id_78 { bool(id_75 > id_77) };
                        uint8_t choose_res_79;
                        if (id_78) {
                          uint8_t id_80 { 0 };
                          uint32_t id_81 { leb128_sz_330[id_80] };
                          uint8_t id_82 { uint8_t(id_81) };
                          choose_res_79 = id_82;
                        } else {
                          uint8_t id_83 { 0 };
                          uint32_t id_84 { leb128_sz_330[id_83] };
                          uint8_t id_85 { uint8_t(id_84) };
                          uint8_t id_86 { 128 };
                          uint8_t id_87 { uint8_t(id_85 | id_86) };
                          choose_res_79 = id_87;
                        }
                        Pointer id_88 { id_74.writeU8(choose_res_79) };
                        Void id_89 { ((void)(leb128_ptr_331[id_72] = id_88), VOID) };
                        (void)id_89;
                        uint8_t id_90 { 0 };
                        uint8_t id_91 { 0 };
                        uint32_t id_92 { leb128_sz_330[id_91] };
                        uint8_t id_93 { 7 };
                        uint32_t id_94 { uint32_t(id_92 >> id_93) };
                        Void id_95 { ((void)(leb128_sz_330[id_90] = id_94), VOID) };
                        (void)id_95;
                        uint8_t id_96 { 0 };
                        uint32_t id_97 { leb128_sz_330[id_96] };
                        uint32_t id_98 { 0U };
                        bool id_99 { bool(id_97 > id_98) };
                        while_flag_71 = id_99;
                        if (while_flag_71) {
                          (void)VOID;
                        }
                      } while (while_flag_71);
                      (void)VOID;
                      uint8_t id_100 { 0 };
                      Pointer id_101 { leb128_ptr_331[id_100] };
                      let_res_70 = id_101;
                    }
                    let_res_68 = let_res_70;
                  }
                  ta0e29e77f0acb0eb5f11e4458453275a id_102 { std::get<0>(x_324) };
                  std::string id_103 { std::get<1>(id_102) };
                  Bytes id_104 { id_103 };
                  Pointer id_105 { let_res_68.writeBytes(id_104) };
                  choose_res_63 = id_105;
                } else {
                  ta0e29e77f0acb0eb5f11e4458453275a id_106 { std::get<0>(x_324) };
                  uint16_t id_107 { uint16_t(id_106.index()) };
                  uint16_t id_108 { 2 };
                  bool id_109 { bool(id_107 == id_108) };
                  Void id_110 { ((void)(assert(id_109)), VOID) };
                  (void)id_110;
                  ta0e29e77f0acb0eb5f11e4458453275a id_111 { std::get<0>(x_324) };
                  std::string id_112 { std::get<2>(id_111) };
                  uint32_t id_113 { (uint32_t)id_112.size() };
                  Vec<1, uint32_t> id_114 {  id_113  };
                  Pointer let_res_115;
                  {
                    Vec<1, uint32_t> leb128_sz_328 { id_114 };
                    Vec<1, Pointer> id_116 {  ssum_dst_327  };
                    Pointer let_res_117;
                    {
                      Vec<1, Pointer> leb128_ptr_329 { id_116 };
                      bool while_flag_118 { true };
                      do {
                        uint8_t id_119 { 0 };
                        uint8_t id_120 { 0 };
                        Pointer id_121 { leb128_ptr_329[id_120] };
                        uint32_t id_122 { 128U };
                        uint8_t id_123 { 0 };
                        uint32_t id_124 { leb128_sz_328[id_123] };
                        bool id_125 { bool(id_122 > id_124) };
                        uint8_t choose_res_126;
                        if (id_125) {
                          uint8_t id_127 { 0 };
                          uint32_t id_128 { leb128_sz_328[id_127] };
                          uint8_t id_129 { uint8_t(id_128) };
                          choose_res_126 = id_129;
                        } else {
                          uint8_t id_130 { 0 };
                          uint32_t id_131 { leb128_sz_328[id_130] };
                          uint8_t id_132 { uint8_t(id_131) };
                          uint8_t id_133 { 128 };
                          uint8_t id_134 { uint8_t(id_132 | id_133) };
                          choose_res_126 = id_134;
                        }
                        Pointer id_135 { id_121.writeU8(choose_res_126) };
                        Void id_136 { ((void)(leb128_ptr_329[id_119] = id_135), VOID) };
                        (void)id_136;
                        uint8_t id_137 { 0 };
                        uint8_t id_138 { 0 };
                        uint32_t id_139 { leb128_sz_328[id_138] };
                        uint8_t id_140 { 7 };
                        uint32_t id_141 { uint32_t(id_139 >> id_140) };
                        Void id_142 { ((void)(leb128_sz_328[id_137] = id_141), VOID) };
                        (void)id_142;
                        uint8_t id_143 { 0 };
                        uint32_t id_144 { leb128_sz_328[id_143] };
                        uint32_t id_145 { 0U };
                        bool id_146 { bool(id_144 > id_145) };
                        while_flag_118 = id_146;
                        if (while_flag_118) {
                          (void)VOID;
                        }
                      } while (while_flag_118);
                      (void)VOID;
                      uint8_t id_147 { 0 };
                      Pointer id_148 { leb128_ptr_329[id_147] };
                      let_res_117 = id_148;
                    }
                    let_res_115 = let_res_117;
                  }
                  ta0e29e77f0acb0eb5f11e4458453275a id_149 { std::get<0>(x_324) };
                  std::string id_150 { std::get<2>(id_149) };
                  Bytes id_151 { id_150 };
                  Pointer id_152 { let_res_115.writeBytes(id_151) };
                  choose_res_63 = id_152;
                }
                choose_res_54 = choose_res_63;
              }
              let_res_49 = choose_res_54;
            }
            let_res_45 = let_res_49;
          }
          Pointer let_res_153;
          {
            Pointer stup_dst_332 { let_res_45 };
            tc5896c929a1575847e04404d6e3e9b96 id_154 { std::get<1>(x_324) };
            tfab2a4fd81d3f08b2a2e9a273cf4a0a2 id_155 { id_154.file_type };
            uint16_t id_156 { uint16_t(id_155.index()) };
            Pointer id_157 { stup_dst_332.writeU16Le(id_156) };
            Pointer let_res_158;
            {
              Pointer ssum_dst_334 { id_157 };
              uint16_t id_159 { 0 };
              tc5896c929a1575847e04404d6e3e9b96 id_160 { std::get<1>(x_324) };
              tfab2a4fd81d3f08b2a2e9a273cf4a0a2 id_161 { id_160.file_type };
              uint16_t id_162 { uint16_t(id_161.index()) };
              bool id_163 { bool(id_159 == id_162) };
              Pointer choose_res_164;
              if (id_163) {
                choose_res_164 = ssum_dst_334;
              } else {
                tc5896c929a1575847e04404d6e3e9b96 id_165 { std::get<1>(x_324) };
                tfab2a4fd81d3f08b2a2e9a273cf4a0a2 id_166 { id_165.file_type };
                uint16_t id_167 { uint16_t(id_166.index()) };
                uint16_t id_168 { 1 };
                bool id_169 { bool(id_167 == id_168) };
                Void id_170 { ((void)(assert(id_169)), VOID) };
                (void)id_170;
                tc5896c929a1575847e04404d6e3e9b96 id_171 { std::get<1>(x_324) };
                tfab2a4fd81d3f08b2a2e9a273cf4a0a2 id_172 { id_171.file_type };
                t85afb1ddd9e9c7584ddc9641e56d5259 id_173 { std::get<1>(id_172) };
                bool id_174 { id_173.with_index };
                uint8_t id_175 { uint8_t(id_174) };
                Pointer id_176 { ssum_dst_334.writeU8(id_175) };
                Pointer let_res_177;
                {
                  Pointer srec_dst_335 { id_176 };
                  tc5896c929a1575847e04404d6e3e9b96 id_178 { std::get<1>(x_324) };
                  tfab2a4fd81d3f08b2a2e9a273cf4a0a2 id_179 { id_178.file_type };
                  t85afb1ddd9e9c7584ddc9641e56d5259 id_180 { std::get<1>(id_179) };
                  uint32_t id_181 { id_180.batch_size };
                  Pointer id_182 { srec_dst_335.writeU32Le(id_181) };
                  let_res_177 = id_182;
                }
                Pointer let_res_183;
                {
                  Pointer srec_dst_336 { let_res_177 };
                  tc5896c929a1575847e04404d6e3e9b96 id_184 { std::get<1>(x_324) };
                  tfab2a4fd81d3f08b2a2e9a273cf4a0a2 id_185 { id_184.file_type };
                  t85afb1ddd9e9c7584ddc9641e56d5259 id_186 { std::get<1>(id_185) };
                  uint32_t id_187 { id_186.num_batches };
                  Pointer id_188 { srec_dst_336.writeU32Le(id_187) };
                  let_res_183 = id_188;
                }
                choose_res_164 = let_res_183;
              }
              let_res_158 = choose_res_164;
            }
            Pointer let_res_189;
            {
              Pointer srec_dst_337 { let_res_158 };
              auto fun190 { dessser::gen::fieldmask::to_row_binary };
              tc5896c929a1575847e04404d6e3e9b96 id_191 { std::get<1>(x_324) };
              dessser::gen::fieldmask::t_ext id_192 { id_191.fieldmask };
              Pointer id_193 { fun190(id_192, srec_dst_337) };
              let_res_189 = id_193;
            }
            Pointer let_res_194;
            {
              Pointer srec_dst_338 { let_res_189 };
              tc5896c929a1575847e04404d6e3e9b96 id_195 { std::get<1>(x_324) };
              Arr<t4b7f8f0e420ffe218b8bc466a29068c5> id_196 { id_195.filters };
              uint32_t id_197 { id_196.size() };
              Vec<1, uint32_t> id_198 {  id_197  };
              Pointer let_res_199;
              {
                Vec<1, uint32_t> leb128_sz_339 { id_198 };
                Vec<1, Pointer> id_200 {  srec_dst_338  };
                Pointer let_res_201;
                {
                  Vec<1, Pointer> leb128_ptr_340 { id_200 };
                  bool while_flag_202 { true };
                  do {
                    uint8_t id_203 { 0 };
                    uint8_t id_204 { 0 };
                    Pointer id_205 { leb128_ptr_340[id_204] };
                    uint32_t id_206 { 128U };
                    uint8_t id_207 { 0 };
                    uint32_t id_208 { leb128_sz_339[id_207] };
                    bool id_209 { bool(id_206 > id_208) };
                    uint8_t choose_res_210;
                    if (id_209) {
                      uint8_t id_211 { 0 };
                      uint32_t id_212 { leb128_sz_339[id_211] };
                      uint8_t id_213 { uint8_t(id_212) };
                      choose_res_210 = id_213;
                    } else {
                      uint8_t id_214 { 0 };
                      uint32_t id_215 { leb128_sz_339[id_214] };
                      uint8_t id_216 { uint8_t(id_215) };
                      uint8_t id_217 { 128 };
                      uint8_t id_218 { uint8_t(id_216 | id_217) };
                      choose_res_210 = id_218;
                    }
                    Pointer id_219 { id_205.writeU8(choose_res_210) };
                    Void id_220 { ((void)(leb128_ptr_340[id_203] = id_219), VOID) };
                    (void)id_220;
                    uint8_t id_221 { 0 };
                    uint8_t id_222 { 0 };
                    uint32_t id_223 { leb128_sz_339[id_222] };
                    uint8_t id_224 { 7 };
                    uint32_t id_225 { uint32_t(id_223 >> id_224) };
                    Void id_226 { ((void)(leb128_sz_339[id_221] = id_225), VOID) };
                    (void)id_226;
                    uint8_t id_227 { 0 };
                    uint32_t id_228 { leb128_sz_339[id_227] };
                    uint32_t id_229 { 0U };
                    bool id_230 { bool(id_228 > id_229) };
                    while_flag_202 = id_230;
                    if (while_flag_202) {
                      (void)VOID;
                    }
                  } while (while_flag_202);
                  (void)VOID;
                  uint8_t id_231 { 0 };
                  Pointer id_232 { leb128_ptr_340[id_231] };
                  let_res_201 = id_232;
                }
                let_res_199 = let_res_201;
              }
              Vec<1, Pointer> id_233 {  let_res_199  };
              Pointer let_res_234;
              {
                Vec<1, Pointer> dst_ref_341 { id_233 };
                int32_t id_235 { 0L };
                Vec<1, int32_t> id_236 {  id_235  };
                Pointer let_res_237;
                {
                  Vec<1, int32_t> n_ref_342 { id_236 };
                  tc5896c929a1575847e04404d6e3e9b96 id_238 { std::get<1>(x_324) };
                  Arr<t4b7f8f0e420ffe218b8bc466a29068c5> id_239 { id_238.filters };
                  for (t4b7f8f0e420ffe218b8bc466a29068c5 x_343 : id_239) {
                    uint8_t id_240 { 0 };
                    uint8_t id_241 { 0 };
                    Pointer id_242 { dst_ref_341[id_241] };
                    Pointer let_res_243;
                    {
                      Pointer stup_dst_344 { id_242 };
                      uint16_t id_244 { std::get<0>(x_343) };
                      Pointer id_245 { stup_dst_344.writeU16Le(id_244) };
                      let_res_243 = id_245;
                    }
                    Pointer let_res_246;
                    {
                      Pointer stup_dst_345 { let_res_243 };
                      Arr<dessser::gen::raql_value::t_ext> id_247 { std::get<1>(x_343) };
                      uint32_t id_248 { id_247.size() };
                      Vec<1, uint32_t> id_249 {  id_248  };
                      Pointer let_res_250;
                      {
                        Vec<1, uint32_t> leb128_sz_346 { id_249 };
                        Vec<1, Pointer> id_251 {  stup_dst_345  };
                        Pointer let_res_252;
                        {
                          Vec<1, Pointer> leb128_ptr_347 { id_251 };
                          bool while_flag_253 { true };
                          do {
                            uint8_t id_254 { 0 };
                            uint8_t id_255 { 0 };
                            Pointer id_256 { leb128_ptr_347[id_255] };
                            uint32_t id_257 { 128U };
                            uint8_t id_258 { 0 };
                            uint32_t id_259 { leb128_sz_346[id_258] };
                            bool id_260 { bool(id_257 > id_259) };
                            uint8_t choose_res_261;
                            if (id_260) {
                              uint8_t id_262 { 0 };
                              uint32_t id_263 { leb128_sz_346[id_262] };
                              uint8_t id_264 { uint8_t(id_263) };
                              choose_res_261 = id_264;
                            } else {
                              uint8_t id_265 { 0 };
                              uint32_t id_266 { leb128_sz_346[id_265] };
                              uint8_t id_267 { uint8_t(id_266) };
                              uint8_t id_268 { 128 };
                              uint8_t id_269 { uint8_t(id_267 | id_268) };
                              choose_res_261 = id_269;
                            }
                            Pointer id_270 { id_256.writeU8(choose_res_261) };
                            Void id_271 { ((void)(leb128_ptr_347[id_254] = id_270), VOID) };
                            (void)id_271;
                            uint8_t id_272 { 0 };
                            uint8_t id_273 { 0 };
                            uint32_t id_274 { leb128_sz_346[id_273] };
                            uint8_t id_275 { 7 };
                            uint32_t id_276 { uint32_t(id_274 >> id_275) };
                            Void id_277 { ((void)(leb128_sz_346[id_272] = id_276), VOID) };
                            (void)id_277;
                            uint8_t id_278 { 0 };
                            uint32_t id_279 { leb128_sz_346[id_278] };
                            uint32_t id_280 { 0U };
                            bool id_281 { bool(id_279 > id_280) };
                            while_flag_253 = id_281;
                            if (while_flag_253) {
                              (void)VOID;
                            }
                          } while (while_flag_253);
                          (void)VOID;
                          uint8_t id_282 { 0 };
                          Pointer id_283 { leb128_ptr_347[id_282] };
                          let_res_252 = id_283;
                        }
                        let_res_250 = let_res_252;
                      }
                      Vec<1, Pointer> id_284 {  let_res_250  };
                      Pointer let_res_285;
                      {
                        Vec<1, Pointer> dst_ref_348 { id_284 };
                        int32_t id_286 { 0L };
                        Vec<1, int32_t> id_287 {  id_286  };
                        Pointer let_res_288;
                        {
                          Vec<1, int32_t> n_ref_349 { id_287 };
                          Arr<dessser::gen::raql_value::t_ext> id_289 { std::get<1>(x_343) };
                          for (dessser::gen::raql_value::t_ext x_350 : id_289) {
                            uint8_t id_290 { 0 };
                            auto fun291 { dessser::gen::raql_value::to_row_binary };
                            uint8_t id_292 { 0 };
                            Pointer id_293 { dst_ref_348[id_292] };
                            Pointer id_294 { fun291(x_350, id_293) };
                            Void id_295 { ((void)(dst_ref_348[id_290] = id_294), VOID) };
                            (void)id_295;
                            uint8_t id_296 { 0 };
                            int32_t id_297 { 1L };
                            uint8_t id_298 { 0 };
                            int32_t id_299 { n_ref_349[id_298] };
                            int32_t id_300 { int32_t(id_297 + id_299) };
                            Void id_301 { ((void)(n_ref_349[id_296] = id_300), VOID) };
                            (void)id_301;
                            (void)id_301;
                          }
                          (void)VOID;
                          uint8_t id_302 { 0 };
                          Pointer id_303 { dst_ref_348[id_302] };
                          let_res_288 = id_303;
                        }
                        let_res_285 = let_res_288;
                      }
                      let_res_246 = let_res_285;
                    }
                    Void id_304 { ((void)(dst_ref_341[id_240] = let_res_246), VOID) };
                    (void)id_304;
                    uint8_t id_305 { 0 };
                    int32_t id_306 { 1L };
                    uint8_t id_307 { 0 };
                    int32_t id_308 { n_ref_342[id_307] };
                    int32_t id_309 { int32_t(id_306 + id_308) };
                    Void id_310 { ((void)(n_ref_342[id_305] = id_309), VOID) };
                    (void)id_310;
                    (void)id_310;
                  }
                  (void)VOID;
                  uint8_t id_311 { 0 };
                  Pointer id_312 { dst_ref_341[id_311] };
                  let_res_237 = id_312;
                }
                let_res_234 = let_res_237;
              }
              let_res_194 = let_res_234;
            }
            Pointer let_res_313;
            {
              Pointer srec_dst_351 { let_res_194 };
              tc5896c929a1575847e04404d6e3e9b96 id_314 { std::get<1>(x_324) };
              Arr<t22a714ea36a3b324d44e75eb47493150> id_315 { id_314.channels };
              uint32_t id_316 { id_315.size() };
              Vec<1, uint32_t> id_317 {  id_316  };
              Pointer let_res_318;
              {
                Vec<1, uint32_t> leb128_sz_352 { id_317 };
                Vec<1, Pointer> id_319 {  srec_dst_351  };
                Pointer let_res_320;
                {
                  Vec<1, Pointer> leb128_ptr_353 { id_319 };
                  bool while_flag_321 { true };
                  do {
                    uint8_t id_322 { 0 };
                    uint8_t id_323 { 0 };
                    Pointer id_324 { leb128_ptr_353[id_323] };
                    uint32_t id_325 { 128U };
                    uint8_t id_326 { 0 };
                    uint32_t id_327 { leb128_sz_352[id_326] };
                    bool id_328 { bool(id_325 > id_327) };
                    uint8_t choose_res_329;
                    if (id_328) {
                      uint8_t id_330 { 0 };
                      uint32_t id_331 { leb128_sz_352[id_330] };
                      uint8_t id_332 { uint8_t(id_331) };
                      choose_res_329 = id_332;
                    } else {
                      uint8_t id_333 { 0 };
                      uint32_t id_334 { leb128_sz_352[id_333] };
                      uint8_t id_335 { uint8_t(id_334) };
                      uint8_t id_336 { 128 };
                      uint8_t id_337 { uint8_t(id_335 | id_336) };
                      choose_res_329 = id_337;
                    }
                    Pointer id_338 { id_324.writeU8(choose_res_329) };
                    Void id_339 { ((void)(leb128_ptr_353[id_322] = id_338), VOID) };
                    (void)id_339;
                    uint8_t id_340 { 0 };
                    uint8_t id_341 { 0 };
                    uint32_t id_342 { leb128_sz_352[id_341] };
                    uint8_t id_343 { 7 };
                    uint32_t id_344 { uint32_t(id_342 >> id_343) };
                    Void id_345 { ((void)(leb128_sz_352[id_340] = id_344), VOID) };
                    (void)id_345;
                    uint8_t id_346 { 0 };
                    uint32_t id_347 { leb128_sz_352[id_346] };
                    uint32_t id_348 { 0U };
                    bool id_349 { bool(id_347 > id_348) };
                    while_flag_321 = id_349;
                    if (while_flag_321) {
                      (void)VOID;
                    }
                  } while (while_flag_321);
                  (void)VOID;
                  uint8_t id_350 { 0 };
                  Pointer id_351 { leb128_ptr_353[id_350] };
                  let_res_320 = id_351;
                }
                let_res_318 = let_res_320;
              }
              Vec<1, Pointer> id_352 {  let_res_318  };
              Pointer let_res_353;
              {
                Vec<1, Pointer> dst_ref_354 { id_352 };
                int32_t id_354 { 0L };
                Vec<1, int32_t> id_355 {  id_354  };
                Pointer let_res_356;
                {
                  Vec<1, int32_t> n_ref_355 { id_355 };
                  tc5896c929a1575847e04404d6e3e9b96 id_357 { std::get<1>(x_324) };
                  Arr<t22a714ea36a3b324d44e75eb47493150> id_358 { id_357.channels };
                  for (t22a714ea36a3b324d44e75eb47493150 x_356 : id_358) {
                    uint8_t id_359 { 0 };
                    uint8_t id_360 { 0 };
                    Pointer id_361 { dst_ref_354[id_360] };
                    Pointer let_res_362;
                    {
                      Pointer stup_dst_357 { id_361 };
                      uint16_t id_363 { std::get<0>(x_356) };
                      Pointer id_364 { stup_dst_357.writeU16Le(id_363) };
                      let_res_362 = id_364;
                    }
                    Pointer let_res_365;
                    {
                      Pointer stup_dst_358 { let_res_362 };
                      tff75d16e75a2c4d2863a7b1192f88f0c id_366 { std::get<1>(x_356) };
                      double id_367 { std::get<0>(id_366) };
                      uint64_t id_368 { qword_of_float(id_367) };
                      Pointer id_369 { stup_dst_358.writeU64Le(id_368) };
                      Pointer let_res_370;
                      {
                        Pointer stup_dst_359 { id_369 };
                        tff75d16e75a2c4d2863a7b1192f88f0c id_371 { std::get<1>(x_356) };
                        int16_t id_372 { std::get<1>(id_371) };
                        uint16_t id_373 { uint16_t(id_372) };
                        Pointer id_374 { stup_dst_359.writeU16Le(id_373) };
                        let_res_370 = id_374;
                      }
                      Pointer let_res_375;
                      {
                        Pointer stup_dst_360 { let_res_370 };
                        tff75d16e75a2c4d2863a7b1192f88f0c id_376 { std::get<1>(x_356) };
                        uint32_t id_377 { std::get<2>(id_376) };
                        Pointer id_378 { stup_dst_360.writeU32Le(id_377) };
                        let_res_375 = id_378;
                      }
                      let_res_365 = let_res_375;
                    }
                    Void id_379 { ((void)(dst_ref_354[id_359] = let_res_365), VOID) };
                    (void)id_379;
                    uint8_t id_380 { 0 };
                    int32_t id_381 { 1L };
                    uint8_t id_382 { 0 };
                    int32_t id_383 { n_ref_355[id_382] };
                    int32_t id_384 { int32_t(id_381 + id_383) };
                    Void id_385 { ((void)(n_ref_355[id_380] = id_384), VOID) };
                    (void)id_385;
                    (void)id_385;
                  }
                  (void)VOID;
                  uint8_t id_386 { 0 };
                  Pointer id_387 { dst_ref_354[id_386] };
                  let_res_356 = id_387;
                }
                let_res_353 = let_res_356;
              }
              let_res_313 = let_res_353;
            }
            let_res_153 = let_res_313;
          }
          Void id_388 { ((void)(dst_ref_322[id_42] = let_res_153), VOID) };
          (void)id_388;
          uint8_t id_389 { 0 };
          int32_t id_390 { 1L };
          uint8_t id_391 { 0 };
          int32_t id_392 { n_ref_323[id_391] };
          int32_t id_393 { int32_t(id_390 + id_392) };
          Void id_394 { ((void)(n_ref_323[id_389] = id_393), VOID) };
          (void)id_394;
          (void)id_394;
        }
        (void)VOID;
        uint8_t id_395 { 0 };
        Pointer id_396 { dst_ref_322[id_395] };
        let_res_41 = id_396;
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
    (fun ("([DirectFile $file_path | IndirectFile STRING | SyncKey STRING]; {file_type: [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]; fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (FLOAT; I16; U32))[]})[]")
      (let "sz_ref_282"
        (make-vec
          (let "n_ref_280" (make-vec (cardinality (param 0)))
            (let "lebsz_ref_281" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_280")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_281")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_281") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_281")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_281")))))))
        (seq
          (let "repeat_n_283" (make-vec (i32 0))
            (while (gt (to-i32 (cardinality (param 0))) (unsafe-nth (u8 0) (identifier "repeat_n_283")))
              (seq
                (set-vec (u8 0) (identifier "sz_ref_282")
                  (let "sz_292"
                    (let "sz_284" (unsafe-nth (u8 0) (identifier "sz_ref_282"))
                      (let "label2_285" (label-of (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))
                        (if (eq (u16 0) (identifier "label2_285"))
                          (add (add (identifier "sz_284") (size 2))
                            (apply (ext-identifier file_path sersize-of-row-binary) (get-alt "DirectFile" (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))
                          (if (eq (u16 1) (identifier "label2_285"))
                            (add (add (identifier "sz_284") (size 2))
                              (let "wlen_289" (string-length (get-alt "IndirectFile" (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0)))))
                                (add
                                  (let "n_ref_290" (make-vec (identifier "wlen_289"))
                                    (let "lebsz_ref_291" (make-vec (u32 1))
                                      (seq
                                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_290")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_291")) (u8 7)))
                                          (set-vec (u8 0) (identifier "lebsz_ref_291") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_291")) (u32 1)))) 
                                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_291")))))) 
                                  (size-of-u32 (identifier "wlen_289")))))
                            (seq (assert (eq (identifier "label2_285") (u16 2)))
                              (add (add (identifier "sz_284") (size 2))
                                (let "wlen_286" (string-length (get-alt "SyncKey" (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0)))))
                                  (add
                                    (let "n_ref_287" (make-vec (identifier "wlen_286"))
                                      (let "lebsz_ref_288" (make-vec (u32 1))
                                        (seq
                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_287")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_288")) (u8 7)))
                                            (set-vec (u8 0) (identifier "lebsz_ref_288") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_288")) (u32 1)))) 
                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_288")))))) 
                                    (size-of-u32 (identifier "wlen_286"))))))))))
                    (let "sz_310"
                      (let "sz_299"
                        (let "sz_298"
                          (let "label2_294" (label-of (get-field "file_type" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0)))))
                            (if (eq (u16 0) (identifier "label2_294")) 
                              (add (identifier "sz_292") (size 2)) (seq (assert (eq (identifier "label2_294") (u16 1))) (add (add (add (add (identifier "sz_292") (size 2)) (size 1)) (size 4)) (size 4)))))
                          (add (identifier "sz_298") (apply (ext-identifier fieldmask sersize-of-row-binary) (get-field "fieldmask" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0)))))))
                        (let "sz_ref_302"
                          (make-vec
                            (add (identifier "sz_299")
                              (let "n_ref_300" (make-vec (cardinality (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))
                                (let "lebsz_ref_301" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_300")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_301")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_301") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_301")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_301"))))))))
                          (seq
                            (let "repeat_n_303" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_303")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_302")
                                    (let "sz_305" (add (unsafe-nth (u8 0) (identifier "sz_ref_302")) (size 2))
                                      (let "sz_ref_308"
                                        (make-vec
                                          (add (identifier "sz_305")
                                            (let "n_ref_306"
                                              (make-vec
                                                (cardinality
                                                  (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_303")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))))
                                              (let "lebsz_ref_307" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_306")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_307")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_307") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_307")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_307"))))))))
                                        (seq
                                          (let "repeat_n_309" (make-vec (i32 0))
                                            (while
                                              (gt
                                                (to-i32
                                                  (cardinality
                                                    (get-item 1
                                                      (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_303")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))))
                                                (unsafe-nth (u8 0) (identifier "repeat_n_309")))
                                              (seq
                                                (set-vec (u8 0) (identifier "sz_ref_308")
                                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_308"))
                                                    (apply (ext-identifier raql_value sersize-of-row-binary)
                                                      (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_309"))
                                                        (get-item 1
                                                          (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_303")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))))))
                                                (set-vec (u8 0) (identifier "repeat_n_309") (add (unsafe-nth (u8 0) (identifier "repeat_n_309")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "sz_ref_308")))))) 
                                  (set-vec (u8 0) (identifier "repeat_n_303") (add (unsafe-nth (u8 0) (identifier "repeat_n_303")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_302")))))
                      (let "sz_ref_313"
                        (make-vec
                          (add (identifier "sz_310")
                            (let "n_ref_311" (make-vec (cardinality (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0))))))
                              (let "lebsz_ref_312" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_311")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_312")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_312") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_312")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_312"))))))))
                        (seq
                          (let "repeat_n_314" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_283")) (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_314")))
                              (seq (set-vec (u8 0) (identifier "sz_ref_313") (add (add (add (add (unsafe-nth (u8 0) (identifier "sz_ref_313")) (size 2)) (size 8)) (size 2)) (size 4)))
                                (set-vec (u8 0) (identifier "repeat_n_314") (add (unsafe-nth (u8 0) (identifier "repeat_n_314")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_313"))))))) 
                (set-vec (u8 0) (identifier "repeat_n_283") (add (unsafe-nth (u8 0) (identifier "repeat_n_283")) (i32 1)))))) 
          (unsafe-nth (u8 0) (identifier "sz_ref_282")))))
 */
static std::function<Size(t&)> sersize_of_row_binary_init()
{
  std::function<Size(t&)> fun397 { [&fun397](t& p_0) {
    uint32_t id_398 { p_0.size() };
    Vec<1, uint32_t> id_399 {  id_398  };
    Size let_res_400;
    {
      Vec<1, uint32_t> n_ref_280 { id_399 };
      uint32_t id_401 { 1U };
      Vec<1, uint32_t> id_402 {  id_401  };
      Size let_res_403;
      {
        Vec<1, uint32_t> lebsz_ref_281 { id_402 };
        bool while_flag_404 { true };
        do {
          uint8_t id_405 { 0 };
          uint32_t id_406 { n_ref_280[id_405] };
          uint8_t id_407 { 0 };
          uint32_t id_408 { lebsz_ref_281[id_407] };
          uint8_t id_409 { 7 };
          uint32_t id_410 { uint32_t(id_408 << id_409) };
          bool id_411 { bool(id_406 >= id_410) };
          while_flag_404 = id_411;
          if (while_flag_404) {
            uint8_t id_412 { 0 };
            uint8_t id_413 { 0 };
            uint32_t id_414 { lebsz_ref_281[id_413] };
            uint32_t id_415 { 1U };
            uint32_t id_416 { uint32_t(id_414 + id_415) };
            Void id_417 { ((void)(lebsz_ref_281[id_412] = id_416), VOID) };
            (void)id_417;
          }
        } while (while_flag_404);
        (void)VOID;
        uint8_t id_418 { 0 };
        uint32_t id_419 { lebsz_ref_281[id_418] };
        Size id_420 { Size(id_419) };
        let_res_403 = id_420;
      }
      let_res_400 = let_res_403;
    }
    Vec<1, Size> id_421 {  let_res_400  };
    Size let_res_422;
    {
      Vec<1, Size> sz_ref_282 { id_421 };
      int32_t id_423 { 0L };
      Vec<1, int32_t> id_424 {  id_423  };
      {
        Vec<1, int32_t> repeat_n_283 { id_424 };
        bool while_flag_425 { true };
        do {
          uint32_t id_426 { p_0.size() };
          int32_t id_427 { int32_t(id_426) };
          uint8_t id_428 { 0 };
          int32_t id_429 { repeat_n_283[id_428] };
          bool id_430 { bool(id_427 > id_429) };
          while_flag_425 = id_430;
          if (while_flag_425) {
            uint8_t id_431 { 0 };
            uint8_t id_432 { 0 };
            Size id_433 { sz_ref_282[id_432] };
            Size let_res_434;
            {
              Size sz_284 { id_433 };
              uint8_t id_435 { 0 };
              int32_t id_436 { repeat_n_283[id_435] };
              t5b5f28d070eb85f8046479df0051225b id_437 { p_0[id_436] };
              ta0e29e77f0acb0eb5f11e4458453275a id_438 { std::get<0>(id_437) };
              uint16_t id_439 { uint16_t(id_438.index()) };
              Size let_res_440;
              {
                uint16_t label2_285 { id_439 };
                uint16_t id_441 { 0 };
                bool id_442 { bool(id_441 == label2_285) };
                Size choose_res_443;
                if (id_442) {
                  Size id_444 { 2UL };
                  Size id_445 { Size(sz_284 + id_444) };
                  auto fun446 { dessser::gen::file_path::sersize_of_row_binary };
                  uint8_t id_447 { 0 };
                  int32_t id_448 { repeat_n_283[id_447] };
                  t5b5f28d070eb85f8046479df0051225b id_449 { p_0[id_448] };
                  ta0e29e77f0acb0eb5f11e4458453275a id_450 { std::get<0>(id_449) };
                  dessser::gen::file_path::t_ext id_451 { std::get<0>(id_450) };
                  Size id_452 { fun446(id_451) };
                  Size id_453 { Size(id_445 + id_452) };
                  choose_res_443 = id_453;
                } else {
                  uint16_t id_454 { 1 };
                  bool id_455 { bool(id_454 == label2_285) };
                  Size choose_res_456;
                  if (id_455) {
                    Size id_457 { 2UL };
                    Size id_458 { Size(sz_284 + id_457) };
                    uint8_t id_459 { 0 };
                    int32_t id_460 { repeat_n_283[id_459] };
                    t5b5f28d070eb85f8046479df0051225b id_461 { p_0[id_460] };
                    ta0e29e77f0acb0eb5f11e4458453275a id_462 { std::get<0>(id_461) };
                    std::string id_463 { std::get<1>(id_462) };
                    uint32_t id_464 { (uint32_t)id_463.size() };
                    Size let_res_465;
                    {
                      uint32_t wlen_289 { id_464 };
                      Vec<1, uint32_t> id_466 {  wlen_289  };
                      Size let_res_467;
                      {
                        Vec<1, uint32_t> n_ref_290 { id_466 };
                        uint32_t id_468 { 1U };
                        Vec<1, uint32_t> id_469 {  id_468  };
                        Size let_res_470;
                        {
                          Vec<1, uint32_t> lebsz_ref_291 { id_469 };
                          bool while_flag_471 { true };
                          do {
                            uint8_t id_472 { 0 };
                            uint32_t id_473 { n_ref_290[id_472] };
                            uint8_t id_474 { 0 };
                            uint32_t id_475 { lebsz_ref_291[id_474] };
                            uint8_t id_476 { 7 };
                            uint32_t id_477 { uint32_t(id_475 << id_476) };
                            bool id_478 { bool(id_473 >= id_477) };
                            while_flag_471 = id_478;
                            if (while_flag_471) {
                              uint8_t id_479 { 0 };
                              uint8_t id_480 { 0 };
                              uint32_t id_481 { lebsz_ref_291[id_480] };
                              uint32_t id_482 { 1U };
                              uint32_t id_483 { uint32_t(id_481 + id_482) };
                              Void id_484 { ((void)(lebsz_ref_291[id_479] = id_483), VOID) };
                              (void)id_484;
                            }
                          } while (while_flag_471);
                          (void)VOID;
                          uint8_t id_485 { 0 };
                          uint32_t id_486 { lebsz_ref_291[id_485] };
                          Size id_487 { Size(id_486) };
                          let_res_470 = id_487;
                        }
                        let_res_467 = let_res_470;
                      }
                      Size id_488 { Size(wlen_289) };
                      Size id_489 { Size(let_res_467 + id_488) };
                      let_res_465 = id_489;
                    }
                    Size id_490 { Size(id_458 + let_res_465) };
                    choose_res_456 = id_490;
                  } else {
                    uint16_t id_491 { 2 };
                    bool id_492 { bool(label2_285 == id_491) };
                    Void id_493 { ((void)(assert(id_492)), VOID) };
                    (void)id_493;
                    Size id_494 { 2UL };
                    Size id_495 { Size(sz_284 + id_494) };
                    uint8_t id_496 { 0 };
                    int32_t id_497 { repeat_n_283[id_496] };
                    t5b5f28d070eb85f8046479df0051225b id_498 { p_0[id_497] };
                    ta0e29e77f0acb0eb5f11e4458453275a id_499 { std::get<0>(id_498) };
                    std::string id_500 { std::get<2>(id_499) };
                    uint32_t id_501 { (uint32_t)id_500.size() };
                    Size let_res_502;
                    {
                      uint32_t wlen_286 { id_501 };
                      Vec<1, uint32_t> id_503 {  wlen_286  };
                      Size let_res_504;
                      {
                        Vec<1, uint32_t> n_ref_287 { id_503 };
                        uint32_t id_505 { 1U };
                        Vec<1, uint32_t> id_506 {  id_505  };
                        Size let_res_507;
                        {
                          Vec<1, uint32_t> lebsz_ref_288 { id_506 };
                          bool while_flag_508 { true };
                          do {
                            uint8_t id_509 { 0 };
                            uint32_t id_510 { n_ref_287[id_509] };
                            uint8_t id_511 { 0 };
                            uint32_t id_512 { lebsz_ref_288[id_511] };
                            uint8_t id_513 { 7 };
                            uint32_t id_514 { uint32_t(id_512 << id_513) };
                            bool id_515 { bool(id_510 >= id_514) };
                            while_flag_508 = id_515;
                            if (while_flag_508) {
                              uint8_t id_516 { 0 };
                              uint8_t id_517 { 0 };
                              uint32_t id_518 { lebsz_ref_288[id_517] };
                              uint32_t id_519 { 1U };
                              uint32_t id_520 { uint32_t(id_518 + id_519) };
                              Void id_521 { ((void)(lebsz_ref_288[id_516] = id_520), VOID) };
                              (void)id_521;
                            }
                          } while (while_flag_508);
                          (void)VOID;
                          uint8_t id_522 { 0 };
                          uint32_t id_523 { lebsz_ref_288[id_522] };
                          Size id_524 { Size(id_523) };
                          let_res_507 = id_524;
                        }
                        let_res_504 = let_res_507;
                      }
                      Size id_525 { Size(wlen_286) };
                      Size id_526 { Size(let_res_504 + id_525) };
                      let_res_502 = id_526;
                    }
                    Size id_527 { Size(id_495 + let_res_502) };
                    choose_res_456 = id_527;
                  }
                  choose_res_443 = choose_res_456;
                }
                let_res_440 = choose_res_443;
              }
              let_res_434 = let_res_440;
            }
            Size let_res_528;
            {
              Size sz_292 { let_res_434 };
              uint8_t id_529 { 0 };
              int32_t id_530 { repeat_n_283[id_529] };
              t5b5f28d070eb85f8046479df0051225b id_531 { p_0[id_530] };
              tc5896c929a1575847e04404d6e3e9b96 id_532 { std::get<1>(id_531) };
              tfab2a4fd81d3f08b2a2e9a273cf4a0a2 id_533 { id_532.file_type };
              uint16_t id_534 { uint16_t(id_533.index()) };
              Size let_res_535;
              {
                uint16_t label2_294 { id_534 };
                uint16_t id_536 { 0 };
                bool id_537 { bool(id_536 == label2_294) };
                Size choose_res_538;
                if (id_537) {
                  Size id_539 { 2UL };
                  Size id_540 { Size(sz_292 + id_539) };
                  choose_res_538 = id_540;
                } else {
                  uint16_t id_541 { 1 };
                  bool id_542 { bool(label2_294 == id_541) };
                  Void id_543 { ((void)(assert(id_542)), VOID) };
                  (void)id_543;
                  Size id_544 { 2UL };
                  Size id_545 { Size(sz_292 + id_544) };
                  Size id_546 { 1UL };
                  Size id_547 { Size(id_545 + id_546) };
                  Size id_548 { 4UL };
                  Size id_549 { Size(id_547 + id_548) };
                  Size id_550 { 4UL };
                  Size id_551 { Size(id_549 + id_550) };
                  choose_res_538 = id_551;
                }
                let_res_535 = choose_res_538;
              }
              Size let_res_552;
              {
                Size sz_298 { let_res_535 };
                auto fun553 { dessser::gen::fieldmask::sersize_of_row_binary };
                uint8_t id_554 { 0 };
                int32_t id_555 { repeat_n_283[id_554] };
                t5b5f28d070eb85f8046479df0051225b id_556 { p_0[id_555] };
                tc5896c929a1575847e04404d6e3e9b96 id_557 { std::get<1>(id_556) };
                dessser::gen::fieldmask::t_ext id_558 { id_557.fieldmask };
                Size id_559 { fun553(id_558) };
                Size id_560 { Size(sz_298 + id_559) };
                let_res_552 = id_560;
              }
              Size let_res_561;
              {
                Size sz_299 { let_res_552 };
                uint8_t id_562 { 0 };
                int32_t id_563 { repeat_n_283[id_562] };
                t5b5f28d070eb85f8046479df0051225b id_564 { p_0[id_563] };
                tc5896c929a1575847e04404d6e3e9b96 id_565 { std::get<1>(id_564) };
                Arr<t4b7f8f0e420ffe218b8bc466a29068c5> id_566 { id_565.filters };
                uint32_t id_567 { id_566.size() };
                Vec<1, uint32_t> id_568 {  id_567  };
                Size let_res_569;
                {
                  Vec<1, uint32_t> n_ref_300 { id_568 };
                  uint32_t id_570 { 1U };
                  Vec<1, uint32_t> id_571 {  id_570  };
                  Size let_res_572;
                  {
                    Vec<1, uint32_t> lebsz_ref_301 { id_571 };
                    bool while_flag_573 { true };
                    do {
                      uint8_t id_574 { 0 };
                      uint32_t id_575 { n_ref_300[id_574] };
                      uint8_t id_576 { 0 };
                      uint32_t id_577 { lebsz_ref_301[id_576] };
                      uint8_t id_578 { 7 };
                      uint32_t id_579 { uint32_t(id_577 << id_578) };
                      bool id_580 { bool(id_575 >= id_579) };
                      while_flag_573 = id_580;
                      if (while_flag_573) {
                        uint8_t id_581 { 0 };
                        uint8_t id_582 { 0 };
                        uint32_t id_583 { lebsz_ref_301[id_582] };
                        uint32_t id_584 { 1U };
                        uint32_t id_585 { uint32_t(id_583 + id_584) };
                        Void id_586 { ((void)(lebsz_ref_301[id_581] = id_585), VOID) };
                        (void)id_586;
                      }
                    } while (while_flag_573);
                    (void)VOID;
                    uint8_t id_587 { 0 };
                    uint32_t id_588 { lebsz_ref_301[id_587] };
                    Size id_589 { Size(id_588) };
                    let_res_572 = id_589;
                  }
                  let_res_569 = let_res_572;
                }
                Size id_590 { Size(sz_299 + let_res_569) };
                Vec<1, Size> id_591 {  id_590  };
                Size let_res_592;
                {
                  Vec<1, Size> sz_ref_302 { id_591 };
                  int32_t id_593 { 0L };
                  Vec<1, int32_t> id_594 {  id_593  };
                  {
                    Vec<1, int32_t> repeat_n_303 { id_594 };
                    bool while_flag_595 { true };
                    do {
                      uint8_t id_596 { 0 };
                      int32_t id_597 { repeat_n_283[id_596] };
                      t5b5f28d070eb85f8046479df0051225b id_598 { p_0[id_597] };
                      tc5896c929a1575847e04404d6e3e9b96 id_599 { std::get<1>(id_598) };
                      Arr<t4b7f8f0e420ffe218b8bc466a29068c5> id_600 { id_599.filters };
                      uint32_t id_601 { id_600.size() };
                      int32_t id_602 { int32_t(id_601) };
                      uint8_t id_603 { 0 };
                      int32_t id_604 { repeat_n_303[id_603] };
                      bool id_605 { bool(id_602 > id_604) };
                      while_flag_595 = id_605;
                      if (while_flag_595) {
                        uint8_t id_606 { 0 };
                        uint8_t id_607 { 0 };
                        Size id_608 { sz_ref_302[id_607] };
                        Size id_609 { 2UL };
                        Size id_610 { Size(id_608 + id_609) };
                        Size let_res_611;
                        {
                          Size sz_305 { id_610 };
                          uint8_t id_612 { 0 };
                          int32_t id_613 { repeat_n_303[id_612] };
                          uint8_t id_614 { 0 };
                          int32_t id_615 { repeat_n_283[id_614] };
                          t5b5f28d070eb85f8046479df0051225b id_616 { p_0[id_615] };
                          tc5896c929a1575847e04404d6e3e9b96 id_617 { std::get<1>(id_616) };
                          Arr<t4b7f8f0e420ffe218b8bc466a29068c5> id_618 { id_617.filters };
                          t4b7f8f0e420ffe218b8bc466a29068c5 id_619 { id_618[id_613] };
                          Arr<dessser::gen::raql_value::t_ext> id_620 { std::get<1>(id_619) };
                          uint32_t id_621 { id_620.size() };
                          Vec<1, uint32_t> id_622 {  id_621  };
                          Size let_res_623;
                          {
                            Vec<1, uint32_t> n_ref_306 { id_622 };
                            uint32_t id_624 { 1U };
                            Vec<1, uint32_t> id_625 {  id_624  };
                            Size let_res_626;
                            {
                              Vec<1, uint32_t> lebsz_ref_307 { id_625 };
                              bool while_flag_627 { true };
                              do {
                                uint8_t id_628 { 0 };
                                uint32_t id_629 { n_ref_306[id_628] };
                                uint8_t id_630 { 0 };
                                uint32_t id_631 { lebsz_ref_307[id_630] };
                                uint8_t id_632 { 7 };
                                uint32_t id_633 { uint32_t(id_631 << id_632) };
                                bool id_634 { bool(id_629 >= id_633) };
                                while_flag_627 = id_634;
                                if (while_flag_627) {
                                  uint8_t id_635 { 0 };
                                  uint8_t id_636 { 0 };
                                  uint32_t id_637 { lebsz_ref_307[id_636] };
                                  uint32_t id_638 { 1U };
                                  uint32_t id_639 { uint32_t(id_637 + id_638) };
                                  Void id_640 { ((void)(lebsz_ref_307[id_635] = id_639), VOID) };
                                  (void)id_640;
                                }
                              } while (while_flag_627);
                              (void)VOID;
                              uint8_t id_641 { 0 };
                              uint32_t id_642 { lebsz_ref_307[id_641] };
                              Size id_643 { Size(id_642) };
                              let_res_626 = id_643;
                            }
                            let_res_623 = let_res_626;
                          }
                          Size id_644 { Size(sz_305 + let_res_623) };
                          Vec<1, Size> id_645 {  id_644  };
                          Size let_res_646;
                          {
                            Vec<1, Size> sz_ref_308 { id_645 };
                            int32_t id_647 { 0L };
                            Vec<1, int32_t> id_648 {  id_647  };
                            {
                              Vec<1, int32_t> repeat_n_309 { id_648 };
                              bool while_flag_649 { true };
                              do {
                                uint8_t id_650 { 0 };
                                int32_t id_651 { repeat_n_303[id_650] };
                                uint8_t id_652 { 0 };
                                int32_t id_653 { repeat_n_283[id_652] };
                                t5b5f28d070eb85f8046479df0051225b id_654 { p_0[id_653] };
                                tc5896c929a1575847e04404d6e3e9b96 id_655 { std::get<1>(id_654) };
                                Arr<t4b7f8f0e420ffe218b8bc466a29068c5> id_656 { id_655.filters };
                                t4b7f8f0e420ffe218b8bc466a29068c5 id_657 { id_656[id_651] };
                                Arr<dessser::gen::raql_value::t_ext> id_658 { std::get<1>(id_657) };
                                uint32_t id_659 { id_658.size() };
                                int32_t id_660 { int32_t(id_659) };
                                uint8_t id_661 { 0 };
                                int32_t id_662 { repeat_n_309[id_661] };
                                bool id_663 { bool(id_660 > id_662) };
                                while_flag_649 = id_663;
                                if (while_flag_649) {
                                  uint8_t id_664 { 0 };
                                  uint8_t id_665 { 0 };
                                  Size id_666 { sz_ref_308[id_665] };
                                  auto fun667 { dessser::gen::raql_value::sersize_of_row_binary };
                                  uint8_t id_668 { 0 };
                                  int32_t id_669 { repeat_n_309[id_668] };
                                  uint8_t id_670 { 0 };
                                  int32_t id_671 { repeat_n_303[id_670] };
                                  uint8_t id_672 { 0 };
                                  int32_t id_673 { repeat_n_283[id_672] };
                                  t5b5f28d070eb85f8046479df0051225b id_674 { p_0[id_673] };
                                  tc5896c929a1575847e04404d6e3e9b96 id_675 { std::get<1>(id_674) };
                                  Arr<t4b7f8f0e420ffe218b8bc466a29068c5> id_676 { id_675.filters };
                                  t4b7f8f0e420ffe218b8bc466a29068c5 id_677 { id_676[id_671] };
                                  Arr<dessser::gen::raql_value::t_ext> id_678 { std::get<1>(id_677) };
                                  dessser::gen::raql_value::t_ext id_679 { id_678[id_669] };
                                  Size id_680 { fun667(id_679) };
                                  Size id_681 { Size(id_666 + id_680) };
                                  Void id_682 { ((void)(sz_ref_308[id_664] = id_681), VOID) };
                                  (void)id_682;
                                  uint8_t id_683 { 0 };
                                  uint8_t id_684 { 0 };
                                  int32_t id_685 { repeat_n_309[id_684] };
                                  int32_t id_686 { 1L };
                                  int32_t id_687 { int32_t(id_685 + id_686) };
                                  Void id_688 { ((void)(repeat_n_309[id_683] = id_687), VOID) };
                                  (void)id_688;
                                  (void)id_688;
                                }
                              } while (while_flag_649);
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_689 { 0 };
                            Size id_690 { sz_ref_308[id_689] };
                            let_res_646 = id_690;
                          }
                          let_res_611 = let_res_646;
                        }
                        Void id_691 { ((void)(sz_ref_302[id_606] = let_res_611), VOID) };
                        (void)id_691;
                        uint8_t id_692 { 0 };
                        uint8_t id_693 { 0 };
                        int32_t id_694 { repeat_n_303[id_693] };
                        int32_t id_695 { 1L };
                        int32_t id_696 { int32_t(id_694 + id_695) };
                        Void id_697 { ((void)(repeat_n_303[id_692] = id_696), VOID) };
                        (void)id_697;
                        (void)id_697;
                      }
                    } while (while_flag_595);
                    (void)VOID;
                  }
                  (void)VOID;
                  uint8_t id_698 { 0 };
                  Size id_699 { sz_ref_302[id_698] };
                  let_res_592 = id_699;
                }
                let_res_561 = let_res_592;
              }
              Size let_res_700;
              {
                Size sz_310 { let_res_561 };
                uint8_t id_701 { 0 };
                int32_t id_702 { repeat_n_283[id_701] };
                t5b5f28d070eb85f8046479df0051225b id_703 { p_0[id_702] };
                tc5896c929a1575847e04404d6e3e9b96 id_704 { std::get<1>(id_703) };
                Arr<t22a714ea36a3b324d44e75eb47493150> id_705 { id_704.channels };
                uint32_t id_706 { id_705.size() };
                Vec<1, uint32_t> id_707 {  id_706  };
                Size let_res_708;
                {
                  Vec<1, uint32_t> n_ref_311 { id_707 };
                  uint32_t id_709 { 1U };
                  Vec<1, uint32_t> id_710 {  id_709  };
                  Size let_res_711;
                  {
                    Vec<1, uint32_t> lebsz_ref_312 { id_710 };
                    bool while_flag_712 { true };
                    do {
                      uint8_t id_713 { 0 };
                      uint32_t id_714 { n_ref_311[id_713] };
                      uint8_t id_715 { 0 };
                      uint32_t id_716 { lebsz_ref_312[id_715] };
                      uint8_t id_717 { 7 };
                      uint32_t id_718 { uint32_t(id_716 << id_717) };
                      bool id_719 { bool(id_714 >= id_718) };
                      while_flag_712 = id_719;
                      if (while_flag_712) {
                        uint8_t id_720 { 0 };
                        uint8_t id_721 { 0 };
                        uint32_t id_722 { lebsz_ref_312[id_721] };
                        uint32_t id_723 { 1U };
                        uint32_t id_724 { uint32_t(id_722 + id_723) };
                        Void id_725 { ((void)(lebsz_ref_312[id_720] = id_724), VOID) };
                        (void)id_725;
                      }
                    } while (while_flag_712);
                    (void)VOID;
                    uint8_t id_726 { 0 };
                    uint32_t id_727 { lebsz_ref_312[id_726] };
                    Size id_728 { Size(id_727) };
                    let_res_711 = id_728;
                  }
                  let_res_708 = let_res_711;
                }
                Size id_729 { Size(sz_310 + let_res_708) };
                Vec<1, Size> id_730 {  id_729  };
                Size let_res_731;
                {
                  Vec<1, Size> sz_ref_313 { id_730 };
                  int32_t id_732 { 0L };
                  Vec<1, int32_t> id_733 {  id_732  };
                  {
                    Vec<1, int32_t> repeat_n_314 { id_733 };
                    bool while_flag_734 { true };
                    do {
                      uint8_t id_735 { 0 };
                      int32_t id_736 { repeat_n_283[id_735] };
                      t5b5f28d070eb85f8046479df0051225b id_737 { p_0[id_736] };
                      tc5896c929a1575847e04404d6e3e9b96 id_738 { std::get<1>(id_737) };
                      Arr<t22a714ea36a3b324d44e75eb47493150> id_739 { id_738.channels };
                      uint32_t id_740 { id_739.size() };
                      int32_t id_741 { int32_t(id_740) };
                      uint8_t id_742 { 0 };
                      int32_t id_743 { repeat_n_314[id_742] };
                      bool id_744 { bool(id_741 > id_743) };
                      while_flag_734 = id_744;
                      if (while_flag_734) {
                        uint8_t id_745 { 0 };
                        uint8_t id_746 { 0 };
                        Size id_747 { sz_ref_313[id_746] };
                        Size id_748 { 2UL };
                        Size id_749 { Size(id_747 + id_748) };
                        Size id_750 { 8UL };
                        Size id_751 { Size(id_749 + id_750) };
                        Size id_752 { 2UL };
                        Size id_753 { Size(id_751 + id_752) };
                        Size id_754 { 4UL };
                        Size id_755 { Size(id_753 + id_754) };
                        Void id_756 { ((void)(sz_ref_313[id_745] = id_755), VOID) };
                        (void)id_756;
                        uint8_t id_757 { 0 };
                        uint8_t id_758 { 0 };
                        int32_t id_759 { repeat_n_314[id_758] };
                        int32_t id_760 { 1L };
                        int32_t id_761 { int32_t(id_759 + id_760) };
                        Void id_762 { ((void)(repeat_n_314[id_757] = id_761), VOID) };
                        (void)id_762;
                        (void)id_762;
                      }
                    } while (while_flag_734);
                    (void)VOID;
                  }
                  (void)VOID;
                  uint8_t id_763 { 0 };
                  Size id_764 { sz_ref_313[id_763] };
                  let_res_731 = id_764;
                }
                let_res_700 = let_res_731;
              }
              let_res_528 = let_res_700;
            }
            Void id_765 { ((void)(sz_ref_282[id_431] = let_res_528), VOID) };
            (void)id_765;
            uint8_t id_766 { 0 };
            uint8_t id_767 { 0 };
            int32_t id_768 { repeat_n_283[id_767] };
            int32_t id_769 { 1L };
            int32_t id_770 { int32_t(id_768 + id_769) };
            Void id_771 { ((void)(repeat_n_283[id_766] = id_770), VOID) };
            (void)id_771;
            (void)id_771;
          }
        } while (while_flag_425);
        (void)VOID;
      }
      (void)VOID;
      uint8_t id_772 { 0 };
      Size id_773 { sz_ref_282[id_772] };
      let_res_422 = id_773;
    }
    return let_res_422;
  }
   };
  return fun397;
}
std::function<Size(t&)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "dlist4_fst_275" "dlist4_snd_276"
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
                (make-tup
                  (end-of-list "([DirectFile $file_path | IndirectFile STRING | SyncKey STRING]; {file_type: [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]; fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (FLOAT; I16; U32))[]})")
                  (identifier "dlist1_snd_67")))
              (seq
                (let "repeat_n_69" (make-vec (i32 0))
                  (while (gt (to-i32 (identifier "dlist1_fst_66")) (unsafe-nth (u8 0) (identifier "repeat_n_69")))
                    (seq
                      (let "dlist2_70" (unsafe-nth (u8 0) (identifier "inits_src_ref_68"))
                        (let-pair "dlist2_fst_71" "dlist2_snd_72" (identifier "dlist2_70")
                          (set-vec (u8 0) (identifier "inits_src_ref_68")
                            (let "dtup_115"
                              (let "dsum1_79" (let-pair "du16_fst_74" "du16_snd_75" (read-u16 little-endian (identifier "dlist2_snd_72")) (make-tup (identifier "du16_fst_74") (identifier "du16_snd_75")))
                                (let-pair "dsum1_fst_80" "dsum1_snd_81" 
                                  (identifier "dsum1_79")
                                  (if (eq (u16 0) (identifier "dsum1_fst_80"))
                                    (let-pair "dsum2_fst_113" "dsum2_snd_114" 
                                      (apply (ext-identifier file_path of-row-binary) (identifier "dsum1_snd_81"))
                                      (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey STRING]" 0 (identifier "dsum2_fst_113")) (identifier "dsum2_snd_114")))
                                    (if (eq (u16 1) (identifier "dsum1_fst_80"))
                                      (let "dstring1_103"
                                        (let "leb_ref_97" (make-vec (u32 0))
                                          (let "shft_ref_98" (make-vec (u8 0))
                                            (let "p_ref_99" (make-vec (identifier "dsum1_snd_81"))
                                              (seq
                                                (while
                                                  (let "leb128_100" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_99")))
                                                    (let-pair "leb128_fst_101" "leb128_snd_102" 
                                                      (identifier "leb128_100")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_99") (identifier "leb128_snd_102"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_97")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_101") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_98")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_97")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_98") (add (unsafe-nth (u8 0) (identifier "shft_ref_98")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_101") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_97"))) (unsafe-nth (u8 0) (identifier "p_ref_99")))))))
                                        (let-pair "dstring1_fst_104" "dstring1_snd_105" 
                                          (identifier "dstring1_103")
                                          (let-pair "dstring2_fst_107" "dstring2_snd_108" 
                                            (read-bytes (identifier "dstring1_snd_105") (identifier "dstring1_fst_104"))
                                            (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey STRING]" 1 (string-of-bytes (identifier "dstring2_fst_107"))) (identifier "dstring2_snd_108")))))
                                      (seq (assert (eq (identifier "dsum1_fst_80") (u16 2)))
                                        (let "dstring1_88"
                                          (let "leb_ref_82" (make-vec (u32 0))
                                            (let "shft_ref_83" (make-vec (u8 0))
                                              (let "p_ref_84" (make-vec (identifier "dsum1_snd_81"))
                                                (seq
                                                  (while
                                                    (let "leb128_85" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_84")))
                                                      (let-pair "leb128_fst_86" "leb128_snd_87" 
                                                        (identifier "leb128_85")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_84") (identifier "leb128_snd_87"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_82")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_86") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_83")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_82")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_83") (add (unsafe-nth (u8 0) (identifier "shft_ref_83")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_86") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_82"))) (unsafe-nth (u8 0) (identifier "p_ref_84")))))))
                                          (let-pair "dstring1_fst_89" "dstring1_snd_90" 
                                            (identifier "dstring1_88")
                                            (let-pair "dstring2_fst_92" "dstring2_snd_93" 
                                              (read-bytes (identifier "dstring1_snd_90") (identifier "dstring1_fst_89"))
                                              (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey STRING]" 2 (string-of-bytes (identifier "dstring2_fst_92"))) (identifier "dstring2_snd_93"))))))))))
                              (let-pair "dtup_fst_116" "dtup_snd_117" 
                                (identifier "dtup_115")
                                (let "drec_151"
                                  (let "dsum1_124" (let-pair "du16_fst_119" "du16_snd_120" (read-u16 little-endian (identifier "dtup_snd_117")) (make-tup (identifier "du16_fst_119") (identifier "du16_snd_120")))
                                    (let-pair "dsum1_fst_125" "dsum1_snd_126" 
                                      (identifier "dsum1_124")
                                      (if (eq (u16 0) (identifier "dsum1_fst_125")) 
                                        (make-tup (construct "[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" 0 (nop)) (identifier "dsum1_snd_126"))
                                        (seq (assert (eq (identifier "dsum1_fst_125") (u16 1)))
                                          (let "drec_130" (let-pair "dbool_fst_128" "dbool_snd_129" (read-u8 (identifier "dsum1_snd_126")) (make-tup (not (eq (identifier "dbool_fst_128") (u8 0))) (identifier "dbool_snd_129")))
                                            (let-pair "drec_fst_131" "drec_snd_132" 
                                              (identifier "drec_130")
                                              (let "drec_136" (let-pair "du32_fst_134" "du32_snd_135" (read-u32 little-endian (identifier "drec_snd_132")) (make-tup (identifier "du32_fst_134") (identifier "du32_snd_135")))
                                                (let-pair "drec_fst_137" "drec_snd_138" 
                                                  (identifier "drec_136")
                                                  (let-pair "du32_fst_140" "du32_snd_141" 
                                                    (read-u32 little-endian (identifier "drec_snd_138"))
                                                    (make-tup
                                                      (construct "[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" 1
                                                        (make-rec (string "with_index") (identifier "drec_fst_131") (string "batch_size") (identifier "drec_fst_137") (string "num_batches") (identifier "du32_fst_140")))
                                                      (identifier "du32_snd_141")))))))))))
                                  (let-pair "drec_fst_152" "drec_snd_153" 
                                    (identifier "drec_151")
                                    (let "drec_154" (apply (ext-identifier fieldmask of-row-binary) (identifier "drec_snd_153"))
                                      (let-pair "drec_fst_155" "drec_snd_156" 
                                        (identifier "drec_154")
                                        (let "drec_212"
                                          (let-pair "dlist4_fst_210" "dlist4_snd_211"
                                            (let "dlist1_166"
                                              (let "leb_ref_157" (make-vec (u32 0))
                                                (let "shft_ref_158" (make-vec (u8 0))
                                                  (let "p_ref_159" (make-vec (identifier "drec_snd_156"))
                                                    (seq
                                                      (while
                                                        (let "leb128_160" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_159")))
                                                          (let-pair "leb128_fst_161" "leb128_snd_162" 
                                                            (identifier "leb128_160")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_159") (identifier "leb128_snd_162"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_157")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_161") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_158")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_157")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_158") (add (unsafe-nth (u8 0) (identifier "shft_ref_158")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_161") (u8 128))))) 
                                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_157")) (unsafe-nth (u8 0) (identifier "p_ref_159")))))))
                                              (let-pair "dlist1_fst_167" "dlist1_snd_168" 
                                                (identifier "dlist1_166")
                                                (let "inits_src_ref_169" 
                                                  (make-vec (make-tup (end-of-list "(U16; $raql_value[])") (identifier "dlist1_snd_168")))
                                                  (seq
                                                    (let "repeat_n_170" 
                                                      (make-vec (i32 0))
                                                      (while (gt (to-i32 (identifier "dlist1_fst_167")) (unsafe-nth (u8 0) (identifier "repeat_n_170")))
                                                        (seq
                                                          (let "dlist2_171" 
                                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_169"))
                                                            (let-pair "dlist2_fst_172" "dlist2_snd_173" 
                                                              (identifier "dlist2_171")
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "inits_src_ref_169")
                                                                (let "dtup_177"
                                                                  (let-pair "du16_fst_175" "du16_snd_176" (read-u16 little-endian (identifier "dlist2_snd_173")) (make-tup (identifier "du16_fst_175") (identifier "du16_snd_176")))
                                                                  (let-pair "dtup_fst_178" "dtup_snd_179" 
                                                                    (identifier "dtup_177")
                                                                    (let-pair "dlist4_fst_201" "dlist4_snd_202"
                                                                    (let "dlist1_189"
                                                                    (let "leb_ref_180" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_181" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_182" 
                                                                    (make-vec (identifier "dtup_snd_179"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_183" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_182")))
                                                                    (let-pair "leb128_fst_184" "leb128_snd_185" 
                                                                    (identifier "leb128_183")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_182") (identifier "leb128_snd_185"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_180")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_184") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_181")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_180")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_181") (add (unsafe-nth (u8 0) (identifier "shft_ref_181")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_184") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_180")) (unsafe-nth (u8 0) (identifier "p_ref_182")))))))
                                                                    (let-pair "dlist1_fst_190" "dlist1_snd_191" 
                                                                    (identifier "dlist1_189")
                                                                    (let "inits_src_ref_192" 
                                                                    (make-vec (make-tup (end-of-list "$raql_value") (identifier "dlist1_snd_191")))
                                                                    (seq
                                                                    (let "repeat_n_193" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_190")) (unsafe-nth (u8 0) (identifier "repeat_n_193")))
                                                                    (seq
                                                                    (let "dlist2_194" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_192"))
                                                                    (let-pair "dlist2_fst_195" "dlist2_snd_196" 
                                                                    (identifier "dlist2_194")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_192")
                                                                    (let-pair "dlist3_fst_198" "dlist3_snd_199" 
                                                                    (apply (ext-identifier raql_value of-row-binary) (identifier "dlist2_snd_196"))
                                                                    (make-tup (cons (identifier "dlist3_fst_198") (identifier "dlist2_fst_195")) (identifier "dlist3_snd_199"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_193") (add (unsafe-nth (u8 0) (identifier "repeat_n_193")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_192"))))))
                                                                    (make-tup 
                                                                    (cons (make-tup (identifier "dtup_fst_178") (arr-of-lst-rev (identifier "dlist4_fst_201"))) (identifier "dlist2_fst_172")) 
                                                                    (identifier "dlist4_snd_202")))))))) 
                                                          (set-vec (u8 0) (identifier "repeat_n_170") (add (unsafe-nth (u8 0) (identifier "repeat_n_170")) (i32 1)))))) 
                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_169")))))) 
                                            (make-tup (arr-of-lst-rev (identifier "dlist4_fst_210")) (identifier "dlist4_snd_211")))
                                          (let-pair "drec_fst_213" "drec_snd_214" 
                                            (identifier "drec_212")
                                            (let-pair "dlist4_fst_263" "dlist4_snd_264"
                                              (let "dlist1_224"
                                                (let "leb_ref_215" (make-vec (u32 0))
                                                  (let "shft_ref_216" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_217" 
                                                      (make-vec (identifier "drec_snd_214"))
                                                      (seq
                                                        (while
                                                          (let "leb128_218" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_217")))
                                                            (let-pair "leb128_fst_219" "leb128_snd_220" 
                                                              (identifier "leb128_218")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_217") (identifier "leb128_snd_220"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_215")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_219") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_216")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_215")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_216") (add (unsafe-nth (u8 0) (identifier "shft_ref_216")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_219") (u8 128))))) 
                                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_215")) (unsafe-nth (u8 0) (identifier "p_ref_217")))))))
                                                (let-pair "dlist1_fst_225" "dlist1_snd_226" 
                                                  (identifier "dlist1_224")
                                                  (let "inits_src_ref_227" 
                                                    (make-vec (make-tup (end-of-list "(U16; (FLOAT; I16; U32))") (identifier "dlist1_snd_226")))
                                                    (seq
                                                      (let "repeat_n_228" 
                                                        (make-vec (i32 0))
                                                        (while (gt (to-i32 (identifier "dlist1_fst_225")) (unsafe-nth (u8 0) (identifier "repeat_n_228")))
                                                          (seq
                                                            (let "dlist2_229" 
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_227"))
                                                              (let-pair "dlist2_fst_230" "dlist2_snd_231" 
                                                                (identifier "dlist2_229")
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "inits_src_ref_227")
                                                                  (let "dtup_235"
                                                                    (let-pair "du16_fst_233" "du16_snd_234" 
                                                                    (read-u16 little-endian (identifier "dlist2_snd_231")) 
                                                                    (make-tup (identifier "du16_fst_233") (identifier "du16_snd_234")))
                                                                    (let-pair "dtup_fst_236" "dtup_snd_237" 
                                                                    (identifier "dtup_235")
                                                                    (let "dtup_241"
                                                                    (let-pair "dfloat_fst_239" "dfloat_snd_240" 
                                                                    (read-u64 little-endian (identifier "dtup_snd_237")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_239")) (identifier "dfloat_snd_240")))
                                                                    (let-pair "dtup_fst_242" "dtup_snd_243" 
                                                                    (identifier "dtup_241")
                                                                    (let "dtup_247"
                                                                    (let-pair "di16_fst_245" "di16_snd_246" 
                                                                    (read-u16 little-endian (identifier "dtup_snd_243")) 
                                                                    (make-tup (to-i16 (identifier "di16_fst_245")) (identifier "di16_snd_246")))
                                                                    (let-pair "dtup_fst_248" "dtup_snd_249" 
                                                                    (identifier "dtup_247")
                                                                    (let-pair "du32_fst_251" "du32_snd_252" 
                                                                    (read-u32 little-endian (identifier "dtup_snd_249"))
                                                                    (make-tup
                                                                    (cons 
                                                                    (make-tup (identifier "dtup_fst_236") (make-tup (identifier "dtup_fst_242") (identifier "dtup_fst_248") (identifier "du32_fst_251")))
                                                                    (identifier "dlist2_fst_230")) 
                                                                    (identifier "du32_snd_252")))))))))))) 
                                                            (set-vec (u8 0) (identifier "repeat_n_228") (add (unsafe-nth (u8 0) (identifier "repeat_n_228")) (i32 1)))))) 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_227"))))))
                                              (make-tup
                                                (cons
                                                  (make-tup (identifier "dtup_fst_116")
                                                    (make-rec (string "file_type") 
                                                      (identifier "drec_fst_152") 
                                                      (string "fieldmask") 
                                                      (identifier "drec_fst_155") 
                                                      (string "filters") 
                                                      (identifier "drec_fst_213") 
                                                      (string "channels") 
                                                      (arr-of-lst-rev (identifier "dlist4_fst_263")))) 
                                                  (identifier "dlist2_fst_71")) 
                                                (identifier "dlist4_snd_264")))))))))))))) 
                      (set-vec (u8 0) (identifier "repeat_n_69") (add (unsafe-nth (u8 0) (identifier "repeat_n_69")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "inits_src_ref_68")))))) 
        (make-tup (arr-of-lst-rev (identifier "dlist4_fst_275")) (identifier "dlist4_snd_276"))))
 */
static std::function<t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary_init()
{
  std::function<t519c57b31160411c6989716f3a9782e0(Pointer)> fun774 { [&fun774](Pointer p_0) {
    uint32_t id_775 { 0U };
    Vec<1, uint32_t> id_776 {  id_775  };
    t405eb186408556fed8f2c41523c07d13 let_res_777;
    {
      Vec<1, uint32_t> leb_ref_56 { id_776 };
      uint8_t id_778 { 0 };
      Vec<1, uint8_t> id_779 {  id_778  };
      t405eb186408556fed8f2c41523c07d13 let_res_780;
      {
        Vec<1, uint8_t> shft_ref_57 { id_779 };
        Vec<1, Pointer> id_781 {  p_0  };
        t405eb186408556fed8f2c41523c07d13 let_res_782;
        {
          Vec<1, Pointer> p_ref_58 { id_781 };
          bool while_flag_783 { true };
          do {
            uint8_t id_784 { 0 };
            Pointer id_785 { p_ref_58[id_784] };
            tb3f98ea670610d40658a618de3ec7b90 id_786 { id_785.readU8() };
            bool let_res_787;
            {
              tb3f98ea670610d40658a618de3ec7b90 leb128_59 { id_786 };
              bool letpair_res_788;
              {
                auto leb128_fst_60 { std::get<0>(leb128_59) };
                auto leb128_snd_61 { std::get<1>(leb128_59) };
                uint8_t id_789 { 0 };
                Void id_790 { ((void)(p_ref_58[id_789] = leb128_snd_61), VOID) };
                (void)id_790;
                uint8_t id_791 { 0 };
                uint8_t id_792 { 127 };
                uint8_t id_793 { uint8_t(leb128_fst_60 & id_792) };
                uint32_t id_794 { uint32_t(id_793) };
                uint8_t id_795 { 0 };
                uint8_t id_796 { shft_ref_57[id_795] };
                uint32_t id_797 { uint32_t(id_794 << id_796) };
                uint8_t id_798 { 0 };
                uint32_t id_799 { leb_ref_56[id_798] };
                uint32_t id_800 { uint32_t(id_797 | id_799) };
                Void id_801 { ((void)(leb_ref_56[id_791] = id_800), VOID) };
                (void)id_801;
                uint8_t id_802 { 0 };
                uint8_t id_803 { 0 };
                uint8_t id_804 { shft_ref_57[id_803] };
                uint8_t id_805 { 7 };
                uint8_t id_806 { uint8_t(id_804 + id_805) };
                Void id_807 { ((void)(shft_ref_57[id_802] = id_806), VOID) };
                (void)id_807;
                uint8_t id_808 { 128 };
                bool id_809 { bool(leb128_fst_60 >= id_808) };
                letpair_res_788 = id_809;
              }
              let_res_787 = letpair_res_788;
            }
            while_flag_783 = let_res_787;
            if (while_flag_783) {
              (void)VOID;
            }
          } while (while_flag_783);
          (void)VOID;
          uint8_t id_810 { 0 };
          uint32_t id_811 { leb_ref_56[id_810] };
          uint8_t id_812 { 0 };
          Pointer id_813 { p_ref_58[id_812] };
          t405eb186408556fed8f2c41523c07d13 id_814 { id_811, id_813 };
          let_res_782 = id_814;
        }
        let_res_780 = let_res_782;
      }
      let_res_777 = let_res_780;
    }
    te50b958a36465a4651705737b018bd7a let_res_815;
    {
      t405eb186408556fed8f2c41523c07d13 dlist1_65 { let_res_777 };
      te50b958a36465a4651705737b018bd7a letpair_res_816;
      {
        auto dlist1_fst_66 { std::get<0>(dlist1_65) };
        auto dlist1_snd_67 { std::get<1>(dlist1_65) };
        Lst<t5b5f28d070eb85f8046479df0051225b> endoflist_817;
        te50b958a36465a4651705737b018bd7a id_818 { endoflist_817, dlist1_snd_67 };
        Vec<1, te50b958a36465a4651705737b018bd7a> id_819 {  id_818  };
        te50b958a36465a4651705737b018bd7a let_res_820;
        {
          Vec<1, te50b958a36465a4651705737b018bd7a> inits_src_ref_68 { id_819 };
          int32_t id_821 { 0L };
          Vec<1, int32_t> id_822 {  id_821  };
          {
            Vec<1, int32_t> repeat_n_69 { id_822 };
            bool while_flag_823 { true };
            do {
              int32_t id_824 { int32_t(dlist1_fst_66) };
              uint8_t id_825 { 0 };
              int32_t id_826 { repeat_n_69[id_825] };
              bool id_827 { bool(id_824 > id_826) };
              while_flag_823 = id_827;
              if (while_flag_823) {
                uint8_t id_828 { 0 };
                te50b958a36465a4651705737b018bd7a id_829 { inits_src_ref_68[id_828] };
                {
                  te50b958a36465a4651705737b018bd7a dlist2_70 { id_829 };
                  {
                    auto dlist2_fst_71 { std::get<0>(dlist2_70) };
                    auto dlist2_snd_72 { std::get<1>(dlist2_70) };
                    uint8_t id_830 { 0 };
                    t22a32080ad88ab548b80077a17b7dd46 id_831 { dlist2_snd_72.readU16Le() };
                    t22a32080ad88ab548b80077a17b7dd46 letpair_res_832;
                    {
                      auto du16_fst_74 { std::get<0>(id_831) };
                      auto du16_snd_75 { std::get<1>(id_831) };
                      t22a32080ad88ab548b80077a17b7dd46 id_833 { du16_fst_74, du16_snd_75 };
                      letpair_res_832 = id_833;
                    }
                    ta8afea4d612b1e9184fb2092476fdaa7 let_res_834;
                    {
                      t22a32080ad88ab548b80077a17b7dd46 dsum1_79 { letpair_res_832 };
                      ta8afea4d612b1e9184fb2092476fdaa7 letpair_res_835;
                      {
                        auto dsum1_fst_80 { std::get<0>(dsum1_79) };
                        auto dsum1_snd_81 { std::get<1>(dsum1_79) };
                        uint16_t id_836 { 0 };
                        bool id_837 { bool(id_836 == dsum1_fst_80) };
                        ta8afea4d612b1e9184fb2092476fdaa7 choose_res_838;
                        if (id_837) {
                          auto fun839 { dessser::gen::file_path::of_row_binary };
                          tad3a94e851c33888b2891405a4005268 id_840 { fun839(dsum1_snd_81) };
                          ta8afea4d612b1e9184fb2092476fdaa7 letpair_res_841;
                          {
                            auto dsum2_fst_113 { std::get<0>(id_840) };
                            auto dsum2_snd_114 { std::get<1>(id_840) };
                            ta0e29e77f0acb0eb5f11e4458453275a id_842 { std::in_place_index<0>, dsum2_fst_113 };
                            ta8afea4d612b1e9184fb2092476fdaa7 id_843 { id_842, dsum2_snd_114 };
                            letpair_res_841 = id_843;
                          }
                          choose_res_838 = letpair_res_841;
                        } else {
                          uint16_t id_844 { 1 };
                          bool id_845 { bool(id_844 == dsum1_fst_80) };
                          ta8afea4d612b1e9184fb2092476fdaa7 choose_res_846;
                          if (id_845) {
                            uint32_t id_847 { 0U };
                            Vec<1, uint32_t> id_848 {  id_847  };
                            t8beb80162423aee37bd383e9b6834c9c let_res_849;
                            {
                              Vec<1, uint32_t> leb_ref_97 { id_848 };
                              uint8_t id_850 { 0 };
                              Vec<1, uint8_t> id_851 {  id_850  };
                              t8beb80162423aee37bd383e9b6834c9c let_res_852;
                              {
                                Vec<1, uint8_t> shft_ref_98 { id_851 };
                                Vec<1, Pointer> id_853 {  dsum1_snd_81  };
                                t8beb80162423aee37bd383e9b6834c9c let_res_854;
                                {
                                  Vec<1, Pointer> p_ref_99 { id_853 };
                                  bool while_flag_855 { true };
                                  do {
                                    uint8_t id_856 { 0 };
                                    Pointer id_857 { p_ref_99[id_856] };
                                    tb3f98ea670610d40658a618de3ec7b90 id_858 { id_857.readU8() };
                                    bool let_res_859;
                                    {
                                      tb3f98ea670610d40658a618de3ec7b90 leb128_100 { id_858 };
                                      bool letpair_res_860;
                                      {
                                        auto leb128_fst_101 { std::get<0>(leb128_100) };
                                        auto leb128_snd_102 { std::get<1>(leb128_100) };
                                        uint8_t id_861 { 0 };
                                        Void id_862 { ((void)(p_ref_99[id_861] = leb128_snd_102), VOID) };
                                        (void)id_862;
                                        uint8_t id_863 { 0 };
                                        uint8_t id_864 { 127 };
                                        uint8_t id_865 { uint8_t(leb128_fst_101 & id_864) };
                                        uint32_t id_866 { uint32_t(id_865) };
                                        uint8_t id_867 { 0 };
                                        uint8_t id_868 { shft_ref_98[id_867] };
                                        uint32_t id_869 { uint32_t(id_866 << id_868) };
                                        uint8_t id_870 { 0 };
                                        uint32_t id_871 { leb_ref_97[id_870] };
                                        uint32_t id_872 { uint32_t(id_869 | id_871) };
                                        Void id_873 { ((void)(leb_ref_97[id_863] = id_872), VOID) };
                                        (void)id_873;
                                        uint8_t id_874 { 0 };
                                        uint8_t id_875 { 0 };
                                        uint8_t id_876 { shft_ref_98[id_875] };
                                        uint8_t id_877 { 7 };
                                        uint8_t id_878 { uint8_t(id_876 + id_877) };
                                        Void id_879 { ((void)(shft_ref_98[id_874] = id_878), VOID) };
                                        (void)id_879;
                                        uint8_t id_880 { 128 };
                                        bool id_881 { bool(leb128_fst_101 >= id_880) };
                                        letpair_res_860 = id_881;
                                      }
                                      let_res_859 = letpair_res_860;
                                    }
                                    while_flag_855 = let_res_859;
                                    if (while_flag_855) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_855);
                                  (void)VOID;
                                  uint8_t id_882 { 0 };
                                  uint32_t id_883 { leb_ref_97[id_882] };
                                  Size id_884 { Size(id_883) };
                                  uint8_t id_885 { 0 };
                                  Pointer id_886 { p_ref_99[id_885] };
                                  t8beb80162423aee37bd383e9b6834c9c id_887 { id_884, id_886 };
                                  let_res_854 = id_887;
                                }
                                let_res_852 = let_res_854;
                              }
                              let_res_849 = let_res_852;
                            }
                            ta8afea4d612b1e9184fb2092476fdaa7 let_res_888;
                            {
                              t8beb80162423aee37bd383e9b6834c9c dstring1_103 { let_res_849 };
                              ta8afea4d612b1e9184fb2092476fdaa7 letpair_res_889;
                              {
                                auto dstring1_fst_104 { std::get<0>(dstring1_103) };
                                auto dstring1_snd_105 { std::get<1>(dstring1_103) };
                                t188345aa49abd0cb47ff73fedc219f08 id_890 { dstring1_snd_105.readBytes(dstring1_fst_104) };
                                ta8afea4d612b1e9184fb2092476fdaa7 letpair_res_891;
                                {
                                  auto dstring2_fst_107 { std::get<0>(id_890) };
                                  auto dstring2_snd_108 { std::get<1>(id_890) };
                                  std::string id_892 { dstring2_fst_107.toString() };
                                  ta0e29e77f0acb0eb5f11e4458453275a id_893 { std::in_place_index<1>, id_892 };
                                  ta8afea4d612b1e9184fb2092476fdaa7 id_894 { id_893, dstring2_snd_108 };
                                  letpair_res_891 = id_894;
                                }
                                letpair_res_889 = letpair_res_891;
                              }
                              let_res_888 = letpair_res_889;
                            }
                            choose_res_846 = let_res_888;
                          } else {
                            uint16_t id_895 { 2 };
                            bool id_896 { bool(dsum1_fst_80 == id_895) };
                            Void id_897 { ((void)(assert(id_896)), VOID) };
                            (void)id_897;
                            uint32_t id_898 { 0U };
                            Vec<1, uint32_t> id_899 {  id_898  };
                            t8beb80162423aee37bd383e9b6834c9c let_res_900;
                            {
                              Vec<1, uint32_t> leb_ref_82 { id_899 };
                              uint8_t id_901 { 0 };
                              Vec<1, uint8_t> id_902 {  id_901  };
                              t8beb80162423aee37bd383e9b6834c9c let_res_903;
                              {
                                Vec<1, uint8_t> shft_ref_83 { id_902 };
                                Vec<1, Pointer> id_904 {  dsum1_snd_81  };
                                t8beb80162423aee37bd383e9b6834c9c let_res_905;
                                {
                                  Vec<1, Pointer> p_ref_84 { id_904 };
                                  bool while_flag_906 { true };
                                  do {
                                    uint8_t id_907 { 0 };
                                    Pointer id_908 { p_ref_84[id_907] };
                                    tb3f98ea670610d40658a618de3ec7b90 id_909 { id_908.readU8() };
                                    bool let_res_910;
                                    {
                                      tb3f98ea670610d40658a618de3ec7b90 leb128_85 { id_909 };
                                      bool letpair_res_911;
                                      {
                                        auto leb128_fst_86 { std::get<0>(leb128_85) };
                                        auto leb128_snd_87 { std::get<1>(leb128_85) };
                                        uint8_t id_912 { 0 };
                                        Void id_913 { ((void)(p_ref_84[id_912] = leb128_snd_87), VOID) };
                                        (void)id_913;
                                        uint8_t id_914 { 0 };
                                        uint8_t id_915 { 127 };
                                        uint8_t id_916 { uint8_t(leb128_fst_86 & id_915) };
                                        uint32_t id_917 { uint32_t(id_916) };
                                        uint8_t id_918 { 0 };
                                        uint8_t id_919 { shft_ref_83[id_918] };
                                        uint32_t id_920 { uint32_t(id_917 << id_919) };
                                        uint8_t id_921 { 0 };
                                        uint32_t id_922 { leb_ref_82[id_921] };
                                        uint32_t id_923 { uint32_t(id_920 | id_922) };
                                        Void id_924 { ((void)(leb_ref_82[id_914] = id_923), VOID) };
                                        (void)id_924;
                                        uint8_t id_925 { 0 };
                                        uint8_t id_926 { 0 };
                                        uint8_t id_927 { shft_ref_83[id_926] };
                                        uint8_t id_928 { 7 };
                                        uint8_t id_929 { uint8_t(id_927 + id_928) };
                                        Void id_930 { ((void)(shft_ref_83[id_925] = id_929), VOID) };
                                        (void)id_930;
                                        uint8_t id_931 { 128 };
                                        bool id_932 { bool(leb128_fst_86 >= id_931) };
                                        letpair_res_911 = id_932;
                                      }
                                      let_res_910 = letpair_res_911;
                                    }
                                    while_flag_906 = let_res_910;
                                    if (while_flag_906) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_906);
                                  (void)VOID;
                                  uint8_t id_933 { 0 };
                                  uint32_t id_934 { leb_ref_82[id_933] };
                                  Size id_935 { Size(id_934) };
                                  uint8_t id_936 { 0 };
                                  Pointer id_937 { p_ref_84[id_936] };
                                  t8beb80162423aee37bd383e9b6834c9c id_938 { id_935, id_937 };
                                  let_res_905 = id_938;
                                }
                                let_res_903 = let_res_905;
                              }
                              let_res_900 = let_res_903;
                            }
                            ta8afea4d612b1e9184fb2092476fdaa7 let_res_939;
                            {
                              t8beb80162423aee37bd383e9b6834c9c dstring1_88 { let_res_900 };
                              ta8afea4d612b1e9184fb2092476fdaa7 letpair_res_940;
                              {
                                auto dstring1_fst_89 { std::get<0>(dstring1_88) };
                                auto dstring1_snd_90 { std::get<1>(dstring1_88) };
                                t188345aa49abd0cb47ff73fedc219f08 id_941 { dstring1_snd_90.readBytes(dstring1_fst_89) };
                                ta8afea4d612b1e9184fb2092476fdaa7 letpair_res_942;
                                {
                                  auto dstring2_fst_92 { std::get<0>(id_941) };
                                  auto dstring2_snd_93 { std::get<1>(id_941) };
                                  std::string id_943 { dstring2_fst_92.toString() };
                                  ta0e29e77f0acb0eb5f11e4458453275a id_944 { std::in_place_index<2>, id_943 };
                                  ta8afea4d612b1e9184fb2092476fdaa7 id_945 { id_944, dstring2_snd_93 };
                                  letpair_res_942 = id_945;
                                }
                                letpair_res_940 = letpair_res_942;
                              }
                              let_res_939 = letpair_res_940;
                            }
                            choose_res_846 = let_res_939;
                          }
                          choose_res_838 = choose_res_846;
                        }
                        letpair_res_835 = choose_res_838;
                      }
                      let_res_834 = letpair_res_835;
                    }
                    te50b958a36465a4651705737b018bd7a let_res_946;
                    {
                      ta8afea4d612b1e9184fb2092476fdaa7 dtup_115 { let_res_834 };
                      te50b958a36465a4651705737b018bd7a letpair_res_947;
                      {
                        auto dtup_fst_116 { std::get<0>(dtup_115) };
                        auto dtup_snd_117 { std::get<1>(dtup_115) };
                        t22a32080ad88ab548b80077a17b7dd46 id_948 { dtup_snd_117.readU16Le() };
                        t22a32080ad88ab548b80077a17b7dd46 letpair_res_949;
                        {
                          auto du16_fst_119 { std::get<0>(id_948) };
                          auto du16_snd_120 { std::get<1>(id_948) };
                          t22a32080ad88ab548b80077a17b7dd46 id_950 { du16_fst_119, du16_snd_120 };
                          letpair_res_949 = id_950;
                        }
                        t158eb66ba798bc5380478692292da7e1 let_res_951;
                        {
                          t22a32080ad88ab548b80077a17b7dd46 dsum1_124 { letpair_res_949 };
                          t158eb66ba798bc5380478692292da7e1 letpair_res_952;
                          {
                            auto dsum1_fst_125 { std::get<0>(dsum1_124) };
                            auto dsum1_snd_126 { std::get<1>(dsum1_124) };
                            uint16_t id_953 { 0 };
                            bool id_954 { bool(id_953 == dsum1_fst_125) };
                            t158eb66ba798bc5380478692292da7e1 choose_res_955;
                            if (id_954) {
                              (void)VOID;
                              tfab2a4fd81d3f08b2a2e9a273cf4a0a2 id_956 { std::in_place_index<0>, VOID };
                              t158eb66ba798bc5380478692292da7e1 id_957 { id_956, dsum1_snd_126 };
                              choose_res_955 = id_957;
                            } else {
                              uint16_t id_958 { 1 };
                              bool id_959 { bool(dsum1_fst_125 == id_958) };
                              Void id_960 { ((void)(assert(id_959)), VOID) };
                              (void)id_960;
                              tb3f98ea670610d40658a618de3ec7b90 id_961 { dsum1_snd_126.readU8() };
                              t4138de986e20d18b01e4c493dc9d5451 letpair_res_962;
                              {
                                auto dbool_fst_128 { std::get<0>(id_961) };
                                auto dbool_snd_129 { std::get<1>(id_961) };
                                uint8_t id_963 { 0 };
                                bool id_964 { bool(dbool_fst_128 == id_963) };
                                bool id_965 { ! id_964 };
                                t4138de986e20d18b01e4c493dc9d5451 id_966 { id_965, dbool_snd_129 };
                                letpair_res_962 = id_966;
                              }
                              t158eb66ba798bc5380478692292da7e1 let_res_967;
                              {
                                t4138de986e20d18b01e4c493dc9d5451 drec_130 { letpair_res_962 };
                                t158eb66ba798bc5380478692292da7e1 letpair_res_968;
                                {
                                  auto drec_fst_131 { std::get<0>(drec_130) };
                                  auto drec_snd_132 { std::get<1>(drec_130) };
                                  t405eb186408556fed8f2c41523c07d13 id_969 { drec_snd_132.readU32Le() };
                                  t405eb186408556fed8f2c41523c07d13 letpair_res_970;
                                  {
                                    auto du32_fst_134 { std::get<0>(id_969) };
                                    auto du32_snd_135 { std::get<1>(id_969) };
                                    t405eb186408556fed8f2c41523c07d13 id_971 { du32_fst_134, du32_snd_135 };
                                    letpair_res_970 = id_971;
                                  }
                                  t158eb66ba798bc5380478692292da7e1 let_res_972;
                                  {
                                    t405eb186408556fed8f2c41523c07d13 drec_136 { letpair_res_970 };
                                    t158eb66ba798bc5380478692292da7e1 letpair_res_973;
                                    {
                                      auto drec_fst_137 { std::get<0>(drec_136) };
                                      auto drec_snd_138 { std::get<1>(drec_136) };
                                      t405eb186408556fed8f2c41523c07d13 id_974 { drec_snd_138.readU32Le() };
                                      t158eb66ba798bc5380478692292da7e1 letpair_res_975;
                                      {
                                        auto du32_fst_140 { std::get<0>(id_974) };
                                        auto du32_snd_141 { std::get<1>(id_974) };
                                        t85afb1ddd9e9c7584ddc9641e56d5259 id_976 { .with_index = drec_fst_131, .batch_size = drec_fst_137, .num_batches = du32_fst_140 };
                                        tfab2a4fd81d3f08b2a2e9a273cf4a0a2 id_977 { std::in_place_index<1>, id_976 };
                                        t158eb66ba798bc5380478692292da7e1 id_978 { id_977, du32_snd_141 };
                                        letpair_res_975 = id_978;
                                      }
                                      letpair_res_973 = letpair_res_975;
                                    }
                                    let_res_972 = letpair_res_973;
                                  }
                                  letpair_res_968 = let_res_972;
                                }
                                let_res_967 = letpair_res_968;
                              }
                              choose_res_955 = let_res_967;
                            }
                            letpair_res_952 = choose_res_955;
                          }
                          let_res_951 = letpair_res_952;
                        }
                        te50b958a36465a4651705737b018bd7a let_res_979;
                        {
                          t158eb66ba798bc5380478692292da7e1 drec_151 { let_res_951 };
                          te50b958a36465a4651705737b018bd7a letpair_res_980;
                          {
                            auto drec_fst_152 { std::get<0>(drec_151) };
                            auto drec_snd_153 { std::get<1>(drec_151) };
                            auto fun981 { dessser::gen::fieldmask::of_row_binary };
                            t65efc37c44620d2af7a978cf67ad8a5b id_982 { fun981(drec_snd_153) };
                            te50b958a36465a4651705737b018bd7a let_res_983;
                            {
                              t65efc37c44620d2af7a978cf67ad8a5b drec_154 { id_982 };
                              te50b958a36465a4651705737b018bd7a letpair_res_984;
                              {
                                auto drec_fst_155 { std::get<0>(drec_154) };
                                auto drec_snd_156 { std::get<1>(drec_154) };
                                uint32_t id_985 { 0U };
                                Vec<1, uint32_t> id_986 {  id_985  };
                                t405eb186408556fed8f2c41523c07d13 let_res_987;
                                {
                                  Vec<1, uint32_t> leb_ref_157 { id_986 };
                                  uint8_t id_988 { 0 };
                                  Vec<1, uint8_t> id_989 {  id_988  };
                                  t405eb186408556fed8f2c41523c07d13 let_res_990;
                                  {
                                    Vec<1, uint8_t> shft_ref_158 { id_989 };
                                    Vec<1, Pointer> id_991 {  drec_snd_156  };
                                    t405eb186408556fed8f2c41523c07d13 let_res_992;
                                    {
                                      Vec<1, Pointer> p_ref_159 { id_991 };
                                      bool while_flag_993 { true };
                                      do {
                                        uint8_t id_994 { 0 };
                                        Pointer id_995 { p_ref_159[id_994] };
                                        tb3f98ea670610d40658a618de3ec7b90 id_996 { id_995.readU8() };
                                        bool let_res_997;
                                        {
                                          tb3f98ea670610d40658a618de3ec7b90 leb128_160 { id_996 };
                                          bool letpair_res_998;
                                          {
                                            auto leb128_fst_161 { std::get<0>(leb128_160) };
                                            auto leb128_snd_162 { std::get<1>(leb128_160) };
                                            uint8_t id_999 { 0 };
                                            Void id_1000 { ((void)(p_ref_159[id_999] = leb128_snd_162), VOID) };
                                            (void)id_1000;
                                            uint8_t id_1001 { 0 };
                                            uint8_t id_1002 { 127 };
                                            uint8_t id_1003 { uint8_t(leb128_fst_161 & id_1002) };
                                            uint32_t id_1004 { uint32_t(id_1003) };
                                            uint8_t id_1005 { 0 };
                                            uint8_t id_1006 { shft_ref_158[id_1005] };
                                            uint32_t id_1007 { uint32_t(id_1004 << id_1006) };
                                            uint8_t id_1008 { 0 };
                                            uint32_t id_1009 { leb_ref_157[id_1008] };
                                            uint32_t id_1010 { uint32_t(id_1007 | id_1009) };
                                            Void id_1011 { ((void)(leb_ref_157[id_1001] = id_1010), VOID) };
                                            (void)id_1011;
                                            uint8_t id_1012 { 0 };
                                            uint8_t id_1013 { 0 };
                                            uint8_t id_1014 { shft_ref_158[id_1013] };
                                            uint8_t id_1015 { 7 };
                                            uint8_t id_1016 { uint8_t(id_1014 + id_1015) };
                                            Void id_1017 { ((void)(shft_ref_158[id_1012] = id_1016), VOID) };
                                            (void)id_1017;
                                            uint8_t id_1018 { 128 };
                                            bool id_1019 { bool(leb128_fst_161 >= id_1018) };
                                            letpair_res_998 = id_1019;
                                          }
                                          let_res_997 = letpair_res_998;
                                        }
                                        while_flag_993 = let_res_997;
                                        if (while_flag_993) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_993);
                                      (void)VOID;
                                      uint8_t id_1020 { 0 };
                                      uint32_t id_1021 { leb_ref_157[id_1020] };
                                      uint8_t id_1022 { 0 };
                                      Pointer id_1023 { p_ref_159[id_1022] };
                                      t405eb186408556fed8f2c41523c07d13 id_1024 { id_1021, id_1023 };
                                      let_res_992 = id_1024;
                                    }
                                    let_res_990 = let_res_992;
                                  }
                                  let_res_987 = let_res_990;
                                }
                                t4bb0296b7c670bf357b420ee069396e5 let_res_1025;
                                {
                                  t405eb186408556fed8f2c41523c07d13 dlist1_166 { let_res_987 };
                                  t4bb0296b7c670bf357b420ee069396e5 letpair_res_1026;
                                  {
                                    auto dlist1_fst_167 { std::get<0>(dlist1_166) };
                                    auto dlist1_snd_168 { std::get<1>(dlist1_166) };
                                    Lst<t4b7f8f0e420ffe218b8bc466a29068c5> endoflist_1027;
                                    t4bb0296b7c670bf357b420ee069396e5 id_1028 { endoflist_1027, dlist1_snd_168 };
                                    Vec<1, t4bb0296b7c670bf357b420ee069396e5> id_1029 {  id_1028  };
                                    t4bb0296b7c670bf357b420ee069396e5 let_res_1030;
                                    {
                                      Vec<1, t4bb0296b7c670bf357b420ee069396e5> inits_src_ref_169 { id_1029 };
                                      int32_t id_1031 { 0L };
                                      Vec<1, int32_t> id_1032 {  id_1031  };
                                      {
                                        Vec<1, int32_t> repeat_n_170 { id_1032 };
                                        bool while_flag_1033 { true };
                                        do {
                                          int32_t id_1034 { int32_t(dlist1_fst_167) };
                                          uint8_t id_1035 { 0 };
                                          int32_t id_1036 { repeat_n_170[id_1035] };
                                          bool id_1037 { bool(id_1034 > id_1036) };
                                          while_flag_1033 = id_1037;
                                          if (while_flag_1033) {
                                            uint8_t id_1038 { 0 };
                                            t4bb0296b7c670bf357b420ee069396e5 id_1039 { inits_src_ref_169[id_1038] };
                                            {
                                              t4bb0296b7c670bf357b420ee069396e5 dlist2_171 { id_1039 };
                                              {
                                                auto dlist2_fst_172 { std::get<0>(dlist2_171) };
                                                auto dlist2_snd_173 { std::get<1>(dlist2_171) };
                                                uint8_t id_1040 { 0 };
                                                t22a32080ad88ab548b80077a17b7dd46 id_1041 { dlist2_snd_173.readU16Le() };
                                                t22a32080ad88ab548b80077a17b7dd46 letpair_res_1042;
                                                {
                                                  auto du16_fst_175 { std::get<0>(id_1041) };
                                                  auto du16_snd_176 { std::get<1>(id_1041) };
                                                  t22a32080ad88ab548b80077a17b7dd46 id_1043 { du16_fst_175, du16_snd_176 };
                                                  letpair_res_1042 = id_1043;
                                                }
                                                t4bb0296b7c670bf357b420ee069396e5 let_res_1044;
                                                {
                                                  t22a32080ad88ab548b80077a17b7dd46 dtup_177 { letpair_res_1042 };
                                                  t4bb0296b7c670bf357b420ee069396e5 letpair_res_1045;
                                                  {
                                                    auto dtup_fst_178 { std::get<0>(dtup_177) };
                                                    auto dtup_snd_179 { std::get<1>(dtup_177) };
                                                    uint32_t id_1046 { 0U };
                                                    Vec<1, uint32_t> id_1047 {  id_1046  };
                                                    t405eb186408556fed8f2c41523c07d13 let_res_1048;
                                                    {
                                                      Vec<1, uint32_t> leb_ref_180 { id_1047 };
                                                      uint8_t id_1049 { 0 };
                                                      Vec<1, uint8_t> id_1050 {  id_1049  };
                                                      t405eb186408556fed8f2c41523c07d13 let_res_1051;
                                                      {
                                                        Vec<1, uint8_t> shft_ref_181 { id_1050 };
                                                        Vec<1, Pointer> id_1052 {  dtup_snd_179  };
                                                        t405eb186408556fed8f2c41523c07d13 let_res_1053;
                                                        {
                                                          Vec<1, Pointer> p_ref_182 { id_1052 };
                                                          bool while_flag_1054 { true };
                                                          do {
                                                            uint8_t id_1055 { 0 };
                                                            Pointer id_1056 { p_ref_182[id_1055] };
                                                            tb3f98ea670610d40658a618de3ec7b90 id_1057 { id_1056.readU8() };
                                                            bool let_res_1058;
                                                            {
                                                              tb3f98ea670610d40658a618de3ec7b90 leb128_183 { id_1057 };
                                                              bool letpair_res_1059;
                                                              {
                                                                auto leb128_fst_184 { std::get<0>(leb128_183) };
                                                                auto leb128_snd_185 { std::get<1>(leb128_183) };
                                                                uint8_t id_1060 { 0 };
                                                                Void id_1061 { ((void)(p_ref_182[id_1060] = leb128_snd_185), VOID) };
                                                                (void)id_1061;
                                                                uint8_t id_1062 { 0 };
                                                                uint8_t id_1063 { 127 };
                                                                uint8_t id_1064 { uint8_t(leb128_fst_184 & id_1063) };
                                                                uint32_t id_1065 { uint32_t(id_1064) };
                                                                uint8_t id_1066 { 0 };
                                                                uint8_t id_1067 { shft_ref_181[id_1066] };
                                                                uint32_t id_1068 { uint32_t(id_1065 << id_1067) };
                                                                uint8_t id_1069 { 0 };
                                                                uint32_t id_1070 { leb_ref_180[id_1069] };
                                                                uint32_t id_1071 { uint32_t(id_1068 | id_1070) };
                                                                Void id_1072 { ((void)(leb_ref_180[id_1062] = id_1071), VOID) };
                                                                (void)id_1072;
                                                                uint8_t id_1073 { 0 };
                                                                uint8_t id_1074 { 0 };
                                                                uint8_t id_1075 { shft_ref_181[id_1074] };
                                                                uint8_t id_1076 { 7 };
                                                                uint8_t id_1077 { uint8_t(id_1075 + id_1076) };
                                                                Void id_1078 { ((void)(shft_ref_181[id_1073] = id_1077), VOID) };
                                                                (void)id_1078;
                                                                uint8_t id_1079 { 128 };
                                                                bool id_1080 { bool(leb128_fst_184 >= id_1079) };
                                                                letpair_res_1059 = id_1080;
                                                              }
                                                              let_res_1058 = letpair_res_1059;
                                                            }
                                                            while_flag_1054 = let_res_1058;
                                                            if (while_flag_1054) {
                                                              (void)VOID;
                                                            }
                                                          } while (while_flag_1054);
                                                          (void)VOID;
                                                          uint8_t id_1081 { 0 };
                                                          uint32_t id_1082 { leb_ref_180[id_1081] };
                                                          uint8_t id_1083 { 0 };
                                                          Pointer id_1084 { p_ref_182[id_1083] };
                                                          t405eb186408556fed8f2c41523c07d13 id_1085 { id_1082, id_1084 };
                                                          let_res_1053 = id_1085;
                                                        }
                                                        let_res_1051 = let_res_1053;
                                                      }
                                                      let_res_1048 = let_res_1051;
                                                    }
                                                    t926078c4ade3e1c01ca9446f92019ce0 let_res_1086;
                                                    {
                                                      t405eb186408556fed8f2c41523c07d13 dlist1_189 { let_res_1048 };
                                                      t926078c4ade3e1c01ca9446f92019ce0 letpair_res_1087;
                                                      {
                                                        auto dlist1_fst_190 { std::get<0>(dlist1_189) };
                                                        auto dlist1_snd_191 { std::get<1>(dlist1_189) };
                                                        Lst<dessser::gen::raql_value::t_ext> endoflist_1088;
                                                        t926078c4ade3e1c01ca9446f92019ce0 id_1089 { endoflist_1088, dlist1_snd_191 };
                                                        Vec<1, t926078c4ade3e1c01ca9446f92019ce0> id_1090 {  id_1089  };
                                                        t926078c4ade3e1c01ca9446f92019ce0 let_res_1091;
                                                        {
                                                          Vec<1, t926078c4ade3e1c01ca9446f92019ce0> inits_src_ref_192 { id_1090 };
                                                          int32_t id_1092 { 0L };
                                                          Vec<1, int32_t> id_1093 {  id_1092  };
                                                          {
                                                            Vec<1, int32_t> repeat_n_193 { id_1093 };
                                                            bool while_flag_1094 { true };
                                                            do {
                                                              int32_t id_1095 { int32_t(dlist1_fst_190) };
                                                              uint8_t id_1096 { 0 };
                                                              int32_t id_1097 { repeat_n_193[id_1096] };
                                                              bool id_1098 { bool(id_1095 > id_1097) };
                                                              while_flag_1094 = id_1098;
                                                              if (while_flag_1094) {
                                                                uint8_t id_1099 { 0 };
                                                                t926078c4ade3e1c01ca9446f92019ce0 id_1100 { inits_src_ref_192[id_1099] };
                                                                {
                                                                  t926078c4ade3e1c01ca9446f92019ce0 dlist2_194 { id_1100 };
                                                                  {
                                                                    auto dlist2_fst_195 { std::get<0>(dlist2_194) };
                                                                    auto dlist2_snd_196 { std::get<1>(dlist2_194) };
                                                                    uint8_t id_1101 { 0 };
                                                                    auto fun1102 { dessser::gen::raql_value::of_row_binary };
                                                                    t9cfa78b25ddcb5afc14daf6a802a6f88 id_1103 { fun1102(dlist2_snd_196) };
                                                                    t926078c4ade3e1c01ca9446f92019ce0 letpair_res_1104;
                                                                    {
                                                                      auto dlist3_fst_198 { std::get<0>(id_1103) };
                                                                      auto dlist3_snd_199 { std::get<1>(id_1103) };
                                                                      Lst<dessser::gen::raql_value::t_ext> id_1105 { dlist3_fst_198, dlist2_fst_195 };
                                                                      t926078c4ade3e1c01ca9446f92019ce0 id_1106 { id_1105, dlist3_snd_199 };
                                                                      letpair_res_1104 = id_1106;
                                                                    }
                                                                    Void id_1107 { ((void)(inits_src_ref_192[id_1101] = letpair_res_1104), VOID) };
                                                                    (void)id_1107;
                                                                  }
                                                                  (void)VOID;
                                                                }
                                                                (void)VOID;
                                                                uint8_t id_1108 { 0 };
                                                                uint8_t id_1109 { 0 };
                                                                int32_t id_1110 { repeat_n_193[id_1109] };
                                                                int32_t id_1111 { 1L };
                                                                int32_t id_1112 { int32_t(id_1110 + id_1111) };
                                                                Void id_1113 { ((void)(repeat_n_193[id_1108] = id_1112), VOID) };
                                                                (void)id_1113;
                                                                (void)id_1113;
                                                              }
                                                            } while (while_flag_1094);
                                                            (void)VOID;
                                                          }
                                                          (void)VOID;
                                                          uint8_t id_1114 { 0 };
                                                          t926078c4ade3e1c01ca9446f92019ce0 id_1115 { inits_src_ref_192[id_1114] };
                                                          let_res_1091 = id_1115;
                                                        }
                                                        letpair_res_1087 = let_res_1091;
                                                      }
                                                      let_res_1086 = letpair_res_1087;
                                                    }
                                                    t4bb0296b7c670bf357b420ee069396e5 letpair_res_1116;
                                                    {
                                                      auto dlist4_fst_201 { std::get<0>(let_res_1086) };
                                                      auto dlist4_snd_202 { std::get<1>(let_res_1086) };
                                                      Arr<dessser::gen::raql_value::t_ext> id_1117 { dlist4_fst_201.toListRev() };
                                                      t4b7f8f0e420ffe218b8bc466a29068c5 id_1118 { dtup_fst_178, id_1117 };
                                                      Lst<t4b7f8f0e420ffe218b8bc466a29068c5> id_1119 { id_1118, dlist2_fst_172 };
                                                      t4bb0296b7c670bf357b420ee069396e5 id_1120 { id_1119, dlist4_snd_202 };
                                                      letpair_res_1116 = id_1120;
                                                    }
                                                    letpair_res_1045 = letpair_res_1116;
                                                  }
                                                  let_res_1044 = letpair_res_1045;
                                                }
                                                Void id_1121 { ((void)(inits_src_ref_169[id_1040] = let_res_1044), VOID) };
                                                (void)id_1121;
                                              }
                                              (void)VOID;
                                            }
                                            (void)VOID;
                                            uint8_t id_1122 { 0 };
                                            uint8_t id_1123 { 0 };
                                            int32_t id_1124 { repeat_n_170[id_1123] };
                                            int32_t id_1125 { 1L };
                                            int32_t id_1126 { int32_t(id_1124 + id_1125) };
                                            Void id_1127 { ((void)(repeat_n_170[id_1122] = id_1126), VOID) };
                                            (void)id_1127;
                                            (void)id_1127;
                                          }
                                        } while (while_flag_1033);
                                        (void)VOID;
                                      }
                                      (void)VOID;
                                      uint8_t id_1128 { 0 };
                                      t4bb0296b7c670bf357b420ee069396e5 id_1129 { inits_src_ref_169[id_1128] };
                                      let_res_1030 = id_1129;
                                    }
                                    letpair_res_1026 = let_res_1030;
                                  }
                                  let_res_1025 = letpair_res_1026;
                                }
                                ta4a7ff0e30d8b86e7b4596cdcfc47732 letpair_res_1130;
                                {
                                  auto dlist4_fst_210 { std::get<0>(let_res_1025) };
                                  auto dlist4_snd_211 { std::get<1>(let_res_1025) };
                                  Arr<t4b7f8f0e420ffe218b8bc466a29068c5> id_1131 { dlist4_fst_210.toListRev() };
                                  ta4a7ff0e30d8b86e7b4596cdcfc47732 id_1132 { id_1131, dlist4_snd_211 };
                                  letpair_res_1130 = id_1132;
                                }
                                te50b958a36465a4651705737b018bd7a let_res_1133;
                                {
                                  ta4a7ff0e30d8b86e7b4596cdcfc47732 drec_212 { letpair_res_1130 };
                                  te50b958a36465a4651705737b018bd7a letpair_res_1134;
                                  {
                                    auto drec_fst_213 { std::get<0>(drec_212) };
                                    auto drec_snd_214 { std::get<1>(drec_212) };
                                    uint32_t id_1135 { 0U };
                                    Vec<1, uint32_t> id_1136 {  id_1135  };
                                    t405eb186408556fed8f2c41523c07d13 let_res_1137;
                                    {
                                      Vec<1, uint32_t> leb_ref_215 { id_1136 };
                                      uint8_t id_1138 { 0 };
                                      Vec<1, uint8_t> id_1139 {  id_1138  };
                                      t405eb186408556fed8f2c41523c07d13 let_res_1140;
                                      {
                                        Vec<1, uint8_t> shft_ref_216 { id_1139 };
                                        Vec<1, Pointer> id_1141 {  drec_snd_214  };
                                        t405eb186408556fed8f2c41523c07d13 let_res_1142;
                                        {
                                          Vec<1, Pointer> p_ref_217 { id_1141 };
                                          bool while_flag_1143 { true };
                                          do {
                                            uint8_t id_1144 { 0 };
                                            Pointer id_1145 { p_ref_217[id_1144] };
                                            tb3f98ea670610d40658a618de3ec7b90 id_1146 { id_1145.readU8() };
                                            bool let_res_1147;
                                            {
                                              tb3f98ea670610d40658a618de3ec7b90 leb128_218 { id_1146 };
                                              bool letpair_res_1148;
                                              {
                                                auto leb128_fst_219 { std::get<0>(leb128_218) };
                                                auto leb128_snd_220 { std::get<1>(leb128_218) };
                                                uint8_t id_1149 { 0 };
                                                Void id_1150 { ((void)(p_ref_217[id_1149] = leb128_snd_220), VOID) };
                                                (void)id_1150;
                                                uint8_t id_1151 { 0 };
                                                uint8_t id_1152 { 127 };
                                                uint8_t id_1153 { uint8_t(leb128_fst_219 & id_1152) };
                                                uint32_t id_1154 { uint32_t(id_1153) };
                                                uint8_t id_1155 { 0 };
                                                uint8_t id_1156 { shft_ref_216[id_1155] };
                                                uint32_t id_1157 { uint32_t(id_1154 << id_1156) };
                                                uint8_t id_1158 { 0 };
                                                uint32_t id_1159 { leb_ref_215[id_1158] };
                                                uint32_t id_1160 { uint32_t(id_1157 | id_1159) };
                                                Void id_1161 { ((void)(leb_ref_215[id_1151] = id_1160), VOID) };
                                                (void)id_1161;
                                                uint8_t id_1162 { 0 };
                                                uint8_t id_1163 { 0 };
                                                uint8_t id_1164 { shft_ref_216[id_1163] };
                                                uint8_t id_1165 { 7 };
                                                uint8_t id_1166 { uint8_t(id_1164 + id_1165) };
                                                Void id_1167 { ((void)(shft_ref_216[id_1162] = id_1166), VOID) };
                                                (void)id_1167;
                                                uint8_t id_1168 { 128 };
                                                bool id_1169 { bool(leb128_fst_219 >= id_1168) };
                                                letpair_res_1148 = id_1169;
                                              }
                                              let_res_1147 = letpair_res_1148;
                                            }
                                            while_flag_1143 = let_res_1147;
                                            if (while_flag_1143) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_1143);
                                          (void)VOID;
                                          uint8_t id_1170 { 0 };
                                          uint32_t id_1171 { leb_ref_215[id_1170] };
                                          uint8_t id_1172 { 0 };
                                          Pointer id_1173 { p_ref_217[id_1172] };
                                          t405eb186408556fed8f2c41523c07d13 id_1174 { id_1171, id_1173 };
                                          let_res_1142 = id_1174;
                                        }
                                        let_res_1140 = let_res_1142;
                                      }
                                      let_res_1137 = let_res_1140;
                                    }
                                    t3b5f41d7f03bcceefd95038c1a32b873 let_res_1175;
                                    {
                                      t405eb186408556fed8f2c41523c07d13 dlist1_224 { let_res_1137 };
                                      t3b5f41d7f03bcceefd95038c1a32b873 letpair_res_1176;
                                      {
                                        auto dlist1_fst_225 { std::get<0>(dlist1_224) };
                                        auto dlist1_snd_226 { std::get<1>(dlist1_224) };
                                        Lst<t22a714ea36a3b324d44e75eb47493150> endoflist_1177;
                                        t3b5f41d7f03bcceefd95038c1a32b873 id_1178 { endoflist_1177, dlist1_snd_226 };
                                        Vec<1, t3b5f41d7f03bcceefd95038c1a32b873> id_1179 {  id_1178  };
                                        t3b5f41d7f03bcceefd95038c1a32b873 let_res_1180;
                                        {
                                          Vec<1, t3b5f41d7f03bcceefd95038c1a32b873> inits_src_ref_227 { id_1179 };
                                          int32_t id_1181 { 0L };
                                          Vec<1, int32_t> id_1182 {  id_1181  };
                                          {
                                            Vec<1, int32_t> repeat_n_228 { id_1182 };
                                            bool while_flag_1183 { true };
                                            do {
                                              int32_t id_1184 { int32_t(dlist1_fst_225) };
                                              uint8_t id_1185 { 0 };
                                              int32_t id_1186 { repeat_n_228[id_1185] };
                                              bool id_1187 { bool(id_1184 > id_1186) };
                                              while_flag_1183 = id_1187;
                                              if (while_flag_1183) {
                                                uint8_t id_1188 { 0 };
                                                t3b5f41d7f03bcceefd95038c1a32b873 id_1189 { inits_src_ref_227[id_1188] };
                                                {
                                                  t3b5f41d7f03bcceefd95038c1a32b873 dlist2_229 { id_1189 };
                                                  {
                                                    auto dlist2_fst_230 { std::get<0>(dlist2_229) };
                                                    auto dlist2_snd_231 { std::get<1>(dlist2_229) };
                                                    uint8_t id_1190 { 0 };
                                                    t22a32080ad88ab548b80077a17b7dd46 id_1191 { dlist2_snd_231.readU16Le() };
                                                    t22a32080ad88ab548b80077a17b7dd46 letpair_res_1192;
                                                    {
                                                      auto du16_fst_233 { std::get<0>(id_1191) };
                                                      auto du16_snd_234 { std::get<1>(id_1191) };
                                                      t22a32080ad88ab548b80077a17b7dd46 id_1193 { du16_fst_233, du16_snd_234 };
                                                      letpair_res_1192 = id_1193;
                                                    }
                                                    t3b5f41d7f03bcceefd95038c1a32b873 let_res_1194;
                                                    {
                                                      t22a32080ad88ab548b80077a17b7dd46 dtup_235 { letpair_res_1192 };
                                                      t3b5f41d7f03bcceefd95038c1a32b873 letpair_res_1195;
                                                      {
                                                        auto dtup_fst_236 { std::get<0>(dtup_235) };
                                                        auto dtup_snd_237 { std::get<1>(dtup_235) };
                                                        t7a47220550fc5126a7b79f1e0c10c645 id_1196 { dtup_snd_237.readU64Le() };
                                                        taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_1197;
                                                        {
                                                          auto dfloat_fst_239 { std::get<0>(id_1196) };
                                                          auto dfloat_snd_240 { std::get<1>(id_1196) };
                                                          double id_1198 { float_of_qword(dfloat_fst_239) };
                                                          taebed00ad7fdb3f7ced11d3cfd58aade id_1199 { id_1198, dfloat_snd_240 };
                                                          letpair_res_1197 = id_1199;
                                                        }
                                                        t3b5f41d7f03bcceefd95038c1a32b873 let_res_1200;
                                                        {
                                                          taebed00ad7fdb3f7ced11d3cfd58aade dtup_241 { letpair_res_1197 };
                                                          t3b5f41d7f03bcceefd95038c1a32b873 letpair_res_1201;
                                                          {
                                                            auto dtup_fst_242 { std::get<0>(dtup_241) };
                                                            auto dtup_snd_243 { std::get<1>(dtup_241) };
                                                            t22a32080ad88ab548b80077a17b7dd46 id_1202 { dtup_snd_243.readU16Le() };
                                                            t7a480586af66fc37ae6bc54fa3d03602 letpair_res_1203;
                                                            {
                                                              auto di16_fst_245 { std::get<0>(id_1202) };
                                                              auto di16_snd_246 { std::get<1>(id_1202) };
                                                              int16_t id_1204 { int16_t(di16_fst_245) };
                                                              t7a480586af66fc37ae6bc54fa3d03602 id_1205 { id_1204, di16_snd_246 };
                                                              letpair_res_1203 = id_1205;
                                                            }
                                                            t3b5f41d7f03bcceefd95038c1a32b873 let_res_1206;
                                                            {
                                                              t7a480586af66fc37ae6bc54fa3d03602 dtup_247 { letpair_res_1203 };
                                                              t3b5f41d7f03bcceefd95038c1a32b873 letpair_res_1207;
                                                              {
                                                                auto dtup_fst_248 { std::get<0>(dtup_247) };
                                                                auto dtup_snd_249 { std::get<1>(dtup_247) };
                                                                t405eb186408556fed8f2c41523c07d13 id_1208 { dtup_snd_249.readU32Le() };
                                                                t3b5f41d7f03bcceefd95038c1a32b873 letpair_res_1209;
                                                                {
                                                                  auto du32_fst_251 { std::get<0>(id_1208) };
                                                                  auto du32_snd_252 { std::get<1>(id_1208) };
                                                                  tff75d16e75a2c4d2863a7b1192f88f0c id_1210 { dtup_fst_242, dtup_fst_248, du32_fst_251 };
                                                                  t22a714ea36a3b324d44e75eb47493150 id_1211 { dtup_fst_236, id_1210 };
                                                                  Lst<t22a714ea36a3b324d44e75eb47493150> id_1212 { id_1211, dlist2_fst_230 };
                                                                  t3b5f41d7f03bcceefd95038c1a32b873 id_1213 { id_1212, du32_snd_252 };
                                                                  letpair_res_1209 = id_1213;
                                                                }
                                                                letpair_res_1207 = letpair_res_1209;
                                                              }
                                                              let_res_1206 = letpair_res_1207;
                                                            }
                                                            letpair_res_1201 = let_res_1206;
                                                          }
                                                          let_res_1200 = letpair_res_1201;
                                                        }
                                                        letpair_res_1195 = let_res_1200;
                                                      }
                                                      let_res_1194 = letpair_res_1195;
                                                    }
                                                    Void id_1214 { ((void)(inits_src_ref_227[id_1190] = let_res_1194), VOID) };
                                                    (void)id_1214;
                                                  }
                                                  (void)VOID;
                                                }
                                                (void)VOID;
                                                uint8_t id_1215 { 0 };
                                                uint8_t id_1216 { 0 };
                                                int32_t id_1217 { repeat_n_228[id_1216] };
                                                int32_t id_1218 { 1L };
                                                int32_t id_1219 { int32_t(id_1217 + id_1218) };
                                                Void id_1220 { ((void)(repeat_n_228[id_1215] = id_1219), VOID) };
                                                (void)id_1220;
                                                (void)id_1220;
                                              }
                                            } while (while_flag_1183);
                                            (void)VOID;
                                          }
                                          (void)VOID;
                                          uint8_t id_1221 { 0 };
                                          t3b5f41d7f03bcceefd95038c1a32b873 id_1222 { inits_src_ref_227[id_1221] };
                                          let_res_1180 = id_1222;
                                        }
                                        letpair_res_1176 = let_res_1180;
                                      }
                                      let_res_1175 = letpair_res_1176;
                                    }
                                    te50b958a36465a4651705737b018bd7a letpair_res_1223;
                                    {
                                      auto dlist4_fst_263 { std::get<0>(let_res_1175) };
                                      auto dlist4_snd_264 { std::get<1>(let_res_1175) };
                                      Arr<t22a714ea36a3b324d44e75eb47493150> id_1224 { dlist4_fst_263.toListRev() };
                                      tc5896c929a1575847e04404d6e3e9b96 id_1225 { .file_type = drec_fst_152, .fieldmask = drec_fst_155, .filters = drec_fst_213, .channels = id_1224 };
                                      t5b5f28d070eb85f8046479df0051225b id_1226 { dtup_fst_116, id_1225 };
                                      Lst<t5b5f28d070eb85f8046479df0051225b> id_1227 { id_1226, dlist2_fst_71 };
                                      te50b958a36465a4651705737b018bd7a id_1228 { id_1227, dlist4_snd_264 };
                                      letpair_res_1223 = id_1228;
                                    }
                                    letpair_res_1134 = letpair_res_1223;
                                  }
                                  let_res_1133 = letpair_res_1134;
                                }
                                letpair_res_984 = let_res_1133;
                              }
                              let_res_983 = letpair_res_984;
                            }
                            letpair_res_980 = let_res_983;
                          }
                          let_res_979 = letpair_res_980;
                        }
                        letpair_res_947 = let_res_979;
                      }
                      let_res_946 = letpair_res_947;
                    }
                    Void id_1229 { ((void)(inits_src_ref_68[id_830] = let_res_946), VOID) };
                    (void)id_1229;
                  }
                  (void)VOID;
                }
                (void)VOID;
                uint8_t id_1230 { 0 };
                uint8_t id_1231 { 0 };
                int32_t id_1232 { repeat_n_69[id_1231] };
                int32_t id_1233 { 1L };
                int32_t id_1234 { int32_t(id_1232 + id_1233) };
                Void id_1235 { ((void)(repeat_n_69[id_1230] = id_1234), VOID) };
                (void)id_1235;
                (void)id_1235;
              }
            } while (while_flag_823);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_1236 { 0 };
          te50b958a36465a4651705737b018bd7a id_1237 { inits_src_ref_68[id_1236] };
          let_res_820 = id_1237;
        }
        letpair_res_816 = let_res_820;
      }
      let_res_815 = letpair_res_816;
    }
    t519c57b31160411c6989716f3a9782e0 letpair_res_1238;
    {
      auto dlist4_fst_275 { std::get<0>(let_res_815) };
      auto dlist4_snd_276 { std::get<1>(let_res_815) };
      t id_1239 { dlist4_fst_275.toListRev() };
      t519c57b31160411c6989716f3a9782e0 id_1240 { id_1239, dlist4_snd_276 };
      letpair_res_1238 = id_1240;
    }
    return letpair_res_1238;
  }
   };
  return fun774;
}
std::function<t519c57b31160411c6989716f3a9782e0(Pointer)> of_row_binary(of_row_binary_init());

typedef t t_ext;

}
