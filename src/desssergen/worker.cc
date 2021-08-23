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
#include "desssergen/func_ref.h"
#include "desssergen/func_ref.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_value.h"
#include "desssergen/field_name.h"
#include "desssergen/file_path.h"


namespace dessser::gen::worker {
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
  dessser::gen::field_name::t_ext,
  dessser::gen::raql_value::t_ext
> t83d220ac6cd554303ec130a90b325374;

struct t8fc31e51f4d30b966d0aba41171f4da5 {
  uint32_t parent_num;
  std::string tunneld_host;
  uint16_t tunneld_port;
  bool operator==(t8fc31e51f4d30b966d0aba41171f4da5 const &other) const {
    return parent_num == other.parent_num && tunneld_host == other.tunneld_host && tunneld_port == other.tunneld_port;
  }
};
struct t313b9867db010cca466a30c76e768a91 : public std::variant<
  Void,
  Arr<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5>
> { using variant::variant; };
struct t {
  Arr<dessser::gen::func_ref::t_ext> children;
  dessser::gen::file_path::t_ext cwd;
  bool debug;
  bool enabled;
  Arr<dessser::gen::field_name::t_ext> envvars;
  std::string info_signature;
  bool is_used;
  Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> params;
  std::optional<Arr<dessser::gen::func_ref::t_ext>> parents;
  double report_period;
  ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 role;
  std::string worker_signature;
  bool operator==(t const &other) const {
    return children == other.children && cwd == other.cwd && debug == other.debug && enabled == other.enabled && envvars == other.envvars && info_signature == other.info_signature && is_used == other.is_used && params == other.params && parents == other.parents && report_period == other.report_period && role == other.role && worker_signature == other.worker_signature;
  }
};
typedef std::tuple<
  ::dessser::gen::worker::t*,
  Pointer
> t2153f894ec0d3c3ed0ba5ddc0b3fd576;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  bool,
  Pointer
> t4138de986e20d18b01e4c493dc9d5451;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

typedef std::tuple<
  double,
  Pointer
> taebed00ad7fdb3f7ced11d3cfd58aade;

typedef std::tuple<
  dessser::gen::file_path::t_ext,
  Pointer
> tad3a94e851c33888b2891405a4005268;

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
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  Lst<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374>,
  Pointer
> tb5750eb88c0584267bbc885971316ec3;

typedef std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> t273a2b7978f5b466a128a51c1cc4a27b;

typedef std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> t9cfa78b25ddcb5afc14daf6a802a6f88;

typedef std::tuple<
  Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374>,
  Pointer
> t7b35b1065b089e850816816e188ccf6c;

typedef std::tuple<
  Lst<dessser::gen::field_name::t_ext>,
  Pointer
> t0dfa866705b76efff53e4aa97228a967;

typedef std::tuple<
  Arr<dessser::gen::field_name::t_ext>,
  Pointer
> t516a13ee5da1d64d6b901ea5754eb1bb;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91,
  Pointer
> tca2b2091d7f296d1f80d11eb663f798d;

typedef std::tuple<
  Lst<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5>,
  Pointer
> t38a3258f09a8f59e4b5670e7a10b06dd;

typedef std::tuple<
  std::optional<Arr<dessser::gen::func_ref::t_ext>>,
  Pointer
> t6f6d98b735276208527ab0c63bfa2f42;

typedef std::tuple<
  Lst<dessser::gen::func_ref::t_ext>,
  Pointer
> tbd412d4066b1057863e0544a21e0ab72;

typedef std::tuple<
  dessser::gen::func_ref::t_ext,
  Pointer
> td5f14eebf589a9b4c952cf9c160f9c66;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{enabled: BOOL; debug: BOOL; report_period: FLOAT; cwd: $file_path; worker_signature: STRING; info_signature: STRING; is_used: BOOL; params: ($field_name; $raql_value)[]; envvars: $field_name[]; role: [Whole Void | TopHalf {tunneld_host: STRING; tunneld_port: U16; parent_num: U32}[]]; parents: $func_ref[]?; children: $func_ref[]}" "Ptr")
      (let "srec_dst_387"
        (let "srec_dst_381"
          (let "srec_dst_368"
            (let "srec_dst_362"
              (let "srec_dst_354"
                (let "srec_dst_353"
                  (let "srec_dst_350"
                    (let "srec_dst_347"
                      (let "srec_dst_346"
                        (let "srec_dst_345" (let "srec_dst_344" (write-u8 (param 1) (u8-of-bool (get-field "enabled" (param 0)))) (write-u8 (identifier "srec_dst_344") (u8-of-bool (get-field "debug" (param 0)))))
                          (write-u64 little-endian (identifier "srec_dst_345") (u64-of-float (get-field "report_period" (param 0)))))
                        (apply (ext-identifier file_path to-row-binary) (get-field "cwd" (param 0)) (identifier "srec_dst_346")))
                      (write-bytes
                        (let "leb128_sz_348" (make-vec (string-length (get-field "worker_signature" (param 0))))
                          (let "leb128_ptr_349" (make-vec (identifier "srec_dst_347"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_349")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_349"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_348"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_348"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_348"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_348") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_348")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_348")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_349"))))) 
                        (bytes-of-string (get-field "worker_signature" (param 0)))))
                    (write-bytes
                      (let "leb128_sz_351" (make-vec (string-length (get-field "info_signature" (param 0))))
                        (let "leb128_ptr_352" (make-vec (identifier "srec_dst_350"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_352")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_352"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_351"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_351"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_351"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_351") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_351")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_351")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_352"))))) 
                      (bytes-of-string (get-field "info_signature" (param 0))))) 
                  (write-u8 (identifier "srec_dst_353") (u8-of-bool (get-field "is_used" (param 0)))))
                (let "dst_ref_357"
                  (make-vec
                    (let "leb128_sz_355" (make-vec (cardinality (get-field "params" (param 0))))
                      (let "leb128_ptr_356" (make-vec (identifier "srec_dst_354"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_356")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_356"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_355"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_355"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_355"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_355") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_355")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_355")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_356"))))))
                  (let "n_ref_358" (make-vec (i32 0))
                    (seq
                      (for-each "x_359" (get-field "params" (param 0))
                        (seq
                          (set-vec (u8 0) (identifier "dst_ref_357")
                            (let "stup_dst_361" (let "stup_dst_360" (unsafe-nth (u8 0) (identifier "dst_ref_357")) (apply (ext-identifier field_name to-row-binary) (get-item 0 (identifier "x_359")) (identifier "stup_dst_360")))
                              (apply (ext-identifier raql_value to-row-binary) (get-item 1 (identifier "x_359")) (identifier "stup_dst_361"))))
                          (set-vec (u8 0) (identifier "n_ref_358") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_358")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_357"))))))
              (let "dst_ref_365"
                (make-vec
                  (let "leb128_sz_363" (make-vec (cardinality (get-field "envvars" (param 0))))
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
                    (for-each "x_367" (get-field "envvars" (param 0))
                      (seq (set-vec (u8 0) (identifier "dst_ref_365") (apply (ext-identifier field_name to-row-binary) (identifier "x_367") (unsafe-nth (u8 0) (identifier "dst_ref_365"))))
                        (set-vec (u8 0) (identifier "n_ref_366") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_366")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_365"))))))
            (let "ssum_dst_370" (write-u16 little-endian (identifier "srec_dst_368") (label-of (get-field "role" (param 0))))
              (if (eq (u16 0) (label-of (get-field "role" (param 0)))) 
                (identifier "ssum_dst_370")
                (seq (assert (eq (label-of (get-field "role" (param 0))) (u16 1)))
                  (let "dst_ref_373"
                    (make-vec
                      (let "leb128_sz_371" (make-vec (cardinality (get-alt "TopHalf" (get-field "role" (param 0)))))
                        (let "leb128_ptr_372" (make-vec (identifier "ssum_dst_370"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_372")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_372"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_371"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_371"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_371"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_371") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_371")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_371")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_372"))))))
                    (let "n_ref_374" (make-vec (i32 0))
                      (seq
                        (for-each "x_375" (get-alt "TopHalf" (get-field "role" (param 0)))
                          (seq
                            (set-vec (u8 0) (identifier "dst_ref_373")
                              (let "srec_dst_380"
                                (let "srec_dst_379"
                                  (let "srec_dst_376" (unsafe-nth (u8 0) (identifier "dst_ref_373"))
                                    (write-bytes
                                      (let "leb128_sz_377" (make-vec (string-length (get-field "tunneld_host" (identifier "x_375"))))
                                        (let "leb128_ptr_378" (make-vec (identifier "srec_dst_376"))
                                          (seq
                                            (while
                                              (seq
                                                (set-vec (u8 0) (identifier "leb128_ptr_378")
                                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_378"))
                                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_377"))) 
                                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_377"))) 
                                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_377"))) (u8 128)))))
                                                (set-vec (u8 0) (identifier "leb128_sz_377") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_377")) (u8 7))) 
                                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_377")) (u32 0))) 
                                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_378"))))) 
                                      (bytes-of-string (get-field "tunneld_host" (identifier "x_375"))))) 
                                  (write-u16 little-endian (identifier "srec_dst_379") (get-field "tunneld_port" (identifier "x_375"))))
                                (write-u32 little-endian (identifier "srec_dst_380") (get-field "parent_num" (identifier "x_375")))))
                            (set-vec (u8 0) (identifier "n_ref_374") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_374")))))) 
                        (unsafe-nth (u8 0) (identifier "dst_ref_373")))))))))
          (if (is-null (get-field "parents" (param 0))) (write-u8 (identifier "srec_dst_381") (u8 1))
            (let "dst_ref_384"
              (make-vec
                (let "leb128_sz_382" (make-vec (cardinality (force (get-field "parents" (param 0)))))
                  (let "leb128_ptr_383" (make-vec (write-u8 (identifier "srec_dst_381") (u8 0)))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_383")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_383"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_382"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_382"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_382"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_382") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_382")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_382")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_383"))))))
              (let "n_ref_385" (make-vec (i32 0))
                (seq
                  (for-each "x_386" (force (get-field "parents" (param 0)))
                    (seq (set-vec (u8 0) (identifier "dst_ref_384") (apply (ext-identifier func_ref to-row-binary) (identifier "x_386") (unsafe-nth (u8 0) (identifier "dst_ref_384"))))
                      (set-vec (u8 0) (identifier "n_ref_385") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_385")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_384")))))))
        (let "dst_ref_390"
          (make-vec
            (let "leb128_sz_388" (make-vec (cardinality (get-field "children" (param 0))))
              (let "leb128_ptr_389" (make-vec (identifier "srec_dst_387"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_389")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_389"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_388"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_388"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_388"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_388") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_388")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_388")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_389"))))))
          (let "n_ref_391" (make-vec (i32 0))
            (seq
              (for-each "x_392" (get-field "children" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_390") (apply (ext-identifier func_ref to-row-binary) (identifier "x_392") (unsafe-nth (u8 0) (identifier "dst_ref_390"))))
                  (set-vec (u8 0) (identifier "n_ref_391") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_391")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_390")))))))
 */
static std::function<Pointer(::dessser::gen::worker::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::worker::t*,Pointer)> fun0 { [&fun0](::dessser::gen::worker::t* p_0, Pointer p_1) {
    bool id_1 { p_0->enabled };
    uint8_t id_2 { uint8_t(id_1) };
    Pointer id_3 { p_1.writeU8(id_2) };
    Pointer let_res_4;
    {
      Pointer srec_dst_344 { id_3 };
      bool id_5 { p_0->debug };
      uint8_t id_6 { uint8_t(id_5) };
      Pointer id_7 { srec_dst_344.writeU8(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_345 { let_res_4 };
      double id_9 { p_0->report_period };
      uint64_t id_10 { qword_of_float(id_9) };
      Pointer id_11 { srec_dst_345.writeU64Le(id_10) };
      let_res_8 = id_11;
    }
    Pointer let_res_12;
    {
      Pointer srec_dst_346 { let_res_8 };
      auto fun13 { dessser::gen::file_path::to_row_binary };
      dessser::gen::file_path::t_ext id_14 { p_0->cwd };
      Pointer id_15 { fun13(id_14, srec_dst_346) };
      let_res_12 = id_15;
    }
    Pointer let_res_16;
    {
      Pointer srec_dst_347 { let_res_12 };
      std::string id_17 { p_0->worker_signature };
      uint32_t id_18 { (uint32_t)id_17.size() };
      Vec<1, uint32_t> id_19 {  id_18  };
      Pointer let_res_20;
      {
        Vec<1, uint32_t> leb128_sz_348 { id_19 };
        Vec<1, Pointer> id_21 {  srec_dst_347  };
        Pointer let_res_22;
        {
          Vec<1, Pointer> leb128_ptr_349 { id_21 };
          bool while_flag_23 { true };
          do {
            uint8_t id_24 { 0 };
            uint8_t id_25 { 0 };
            Pointer id_26 { leb128_ptr_349[id_25] };
            uint32_t id_27 { 128U };
            uint8_t id_28 { 0 };
            uint32_t id_29 { leb128_sz_348[id_28] };
            bool id_30 { bool(id_27 > id_29) };
            uint8_t choose_res_31;
            if (id_30) {
              uint8_t id_32 { 0 };
              uint32_t id_33 { leb128_sz_348[id_32] };
              uint8_t id_34 { uint8_t(id_33) };
              choose_res_31 = id_34;
            } else {
              uint8_t id_35 { 0 };
              uint32_t id_36 { leb128_sz_348[id_35] };
              uint8_t id_37 { uint8_t(id_36) };
              uint8_t id_38 { 128 };
              uint8_t id_39 { uint8_t(id_37 | id_38) };
              choose_res_31 = id_39;
            }
            Pointer id_40 { id_26.writeU8(choose_res_31) };
            Void id_41 { ((void)(leb128_ptr_349[id_24] = id_40), VOID) };
            (void)id_41;
            uint8_t id_42 { 0 };
            uint8_t id_43 { 0 };
            uint32_t id_44 { leb128_sz_348[id_43] };
            uint8_t id_45 { 7 };
            uint32_t id_46 { uint32_t(id_44 >> id_45) };
            Void id_47 { ((void)(leb128_sz_348[id_42] = id_46), VOID) };
            (void)id_47;
            uint8_t id_48 { 0 };
            uint32_t id_49 { leb128_sz_348[id_48] };
            uint32_t id_50 { 0U };
            bool id_51 { bool(id_49 > id_50) };
            while_flag_23 = id_51;
            if (while_flag_23) {
              (void)VOID;
            }
          } while (while_flag_23);
          (void)VOID;
          uint8_t id_52 { 0 };
          Pointer id_53 { leb128_ptr_349[id_52] };
          let_res_22 = id_53;
        }
        let_res_20 = let_res_22;
      }
      std::string id_54 { p_0->worker_signature };
      Bytes id_55 { id_54 };
      Pointer id_56 { let_res_20.writeBytes(id_55) };
      let_res_16 = id_56;
    }
    Pointer let_res_57;
    {
      Pointer srec_dst_350 { let_res_16 };
      std::string id_58 { p_0->info_signature };
      uint32_t id_59 { (uint32_t)id_58.size() };
      Vec<1, uint32_t> id_60 {  id_59  };
      Pointer let_res_61;
      {
        Vec<1, uint32_t> leb128_sz_351 { id_60 };
        Vec<1, Pointer> id_62 {  srec_dst_350  };
        Pointer let_res_63;
        {
          Vec<1, Pointer> leb128_ptr_352 { id_62 };
          bool while_flag_64 { true };
          do {
            uint8_t id_65 { 0 };
            uint8_t id_66 { 0 };
            Pointer id_67 { leb128_ptr_352[id_66] };
            uint32_t id_68 { 128U };
            uint8_t id_69 { 0 };
            uint32_t id_70 { leb128_sz_351[id_69] };
            bool id_71 { bool(id_68 > id_70) };
            uint8_t choose_res_72;
            if (id_71) {
              uint8_t id_73 { 0 };
              uint32_t id_74 { leb128_sz_351[id_73] };
              uint8_t id_75 { uint8_t(id_74) };
              choose_res_72 = id_75;
            } else {
              uint8_t id_76 { 0 };
              uint32_t id_77 { leb128_sz_351[id_76] };
              uint8_t id_78 { uint8_t(id_77) };
              uint8_t id_79 { 128 };
              uint8_t id_80 { uint8_t(id_78 | id_79) };
              choose_res_72 = id_80;
            }
            Pointer id_81 { id_67.writeU8(choose_res_72) };
            Void id_82 { ((void)(leb128_ptr_352[id_65] = id_81), VOID) };
            (void)id_82;
            uint8_t id_83 { 0 };
            uint8_t id_84 { 0 };
            uint32_t id_85 { leb128_sz_351[id_84] };
            uint8_t id_86 { 7 };
            uint32_t id_87 { uint32_t(id_85 >> id_86) };
            Void id_88 { ((void)(leb128_sz_351[id_83] = id_87), VOID) };
            (void)id_88;
            uint8_t id_89 { 0 };
            uint32_t id_90 { leb128_sz_351[id_89] };
            uint32_t id_91 { 0U };
            bool id_92 { bool(id_90 > id_91) };
            while_flag_64 = id_92;
            if (while_flag_64) {
              (void)VOID;
            }
          } while (while_flag_64);
          (void)VOID;
          uint8_t id_93 { 0 };
          Pointer id_94 { leb128_ptr_352[id_93] };
          let_res_63 = id_94;
        }
        let_res_61 = let_res_63;
      }
      std::string id_95 { p_0->info_signature };
      Bytes id_96 { id_95 };
      Pointer id_97 { let_res_61.writeBytes(id_96) };
      let_res_57 = id_97;
    }
    Pointer let_res_98;
    {
      Pointer srec_dst_353 { let_res_57 };
      bool id_99 { p_0->is_used };
      uint8_t id_100 { uint8_t(id_99) };
      Pointer id_101 { srec_dst_353.writeU8(id_100) };
      let_res_98 = id_101;
    }
    Pointer let_res_102;
    {
      Pointer srec_dst_354 { let_res_98 };
      Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> id_103 { p_0->params };
      uint32_t id_104 { id_103.size() };
      Vec<1, uint32_t> id_105 {  id_104  };
      Pointer let_res_106;
      {
        Vec<1, uint32_t> leb128_sz_355 { id_105 };
        Vec<1, Pointer> id_107 {  srec_dst_354  };
        Pointer let_res_108;
        {
          Vec<1, Pointer> leb128_ptr_356 { id_107 };
          bool while_flag_109 { true };
          do {
            uint8_t id_110 { 0 };
            uint8_t id_111 { 0 };
            Pointer id_112 { leb128_ptr_356[id_111] };
            uint32_t id_113 { 128U };
            uint8_t id_114 { 0 };
            uint32_t id_115 { leb128_sz_355[id_114] };
            bool id_116 { bool(id_113 > id_115) };
            uint8_t choose_res_117;
            if (id_116) {
              uint8_t id_118 { 0 };
              uint32_t id_119 { leb128_sz_355[id_118] };
              uint8_t id_120 { uint8_t(id_119) };
              choose_res_117 = id_120;
            } else {
              uint8_t id_121 { 0 };
              uint32_t id_122 { leb128_sz_355[id_121] };
              uint8_t id_123 { uint8_t(id_122) };
              uint8_t id_124 { 128 };
              uint8_t id_125 { uint8_t(id_123 | id_124) };
              choose_res_117 = id_125;
            }
            Pointer id_126 { id_112.writeU8(choose_res_117) };
            Void id_127 { ((void)(leb128_ptr_356[id_110] = id_126), VOID) };
            (void)id_127;
            uint8_t id_128 { 0 };
            uint8_t id_129 { 0 };
            uint32_t id_130 { leb128_sz_355[id_129] };
            uint8_t id_131 { 7 };
            uint32_t id_132 { uint32_t(id_130 >> id_131) };
            Void id_133 { ((void)(leb128_sz_355[id_128] = id_132), VOID) };
            (void)id_133;
            uint8_t id_134 { 0 };
            uint32_t id_135 { leb128_sz_355[id_134] };
            uint32_t id_136 { 0U };
            bool id_137 { bool(id_135 > id_136) };
            while_flag_109 = id_137;
            if (while_flag_109) {
              (void)VOID;
            }
          } while (while_flag_109);
          (void)VOID;
          uint8_t id_138 { 0 };
          Pointer id_139 { leb128_ptr_356[id_138] };
          let_res_108 = id_139;
        }
        let_res_106 = let_res_108;
      }
      Vec<1, Pointer> id_140 {  let_res_106  };
      Pointer let_res_141;
      {
        Vec<1, Pointer> dst_ref_357 { id_140 };
        int32_t id_142 { 0L };
        Vec<1, int32_t> id_143 {  id_142  };
        Pointer let_res_144;
        {
          Vec<1, int32_t> n_ref_358 { id_143 };
          Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> id_145 { p_0->params };
          for (::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374 x_359 : id_145) {
            uint8_t id_146 { 0 };
            uint8_t id_147 { 0 };
            Pointer id_148 { dst_ref_357[id_147] };
            Pointer let_res_149;
            {
              Pointer stup_dst_360 { id_148 };
              auto fun150 { dessser::gen::field_name::to_row_binary };
              dessser::gen::field_name::t_ext id_151 { std::get<0>(x_359) };
              Pointer id_152 { fun150(id_151, stup_dst_360) };
              let_res_149 = id_152;
            }
            Pointer let_res_153;
            {
              Pointer stup_dst_361 { let_res_149 };
              auto fun154 { dessser::gen::raql_value::to_row_binary };
              dessser::gen::raql_value::t_ext id_155 { std::get<1>(x_359) };
              Pointer id_156 { fun154(id_155, stup_dst_361) };
              let_res_153 = id_156;
            }
            Void id_157 { ((void)(dst_ref_357[id_146] = let_res_153), VOID) };
            (void)id_157;
            uint8_t id_158 { 0 };
            int32_t id_159 { 1L };
            uint8_t id_160 { 0 };
            int32_t id_161 { n_ref_358[id_160] };
            int32_t id_162 { int32_t(id_159 + id_161) };
            Void id_163 { ((void)(n_ref_358[id_158] = id_162), VOID) };
            (void)id_163;
            (void)id_163;
          }
          (void)VOID;
          uint8_t id_164 { 0 };
          Pointer id_165 { dst_ref_357[id_164] };
          let_res_144 = id_165;
        }
        let_res_141 = let_res_144;
      }
      let_res_102 = let_res_141;
    }
    Pointer let_res_166;
    {
      Pointer srec_dst_362 { let_res_102 };
      Arr<dessser::gen::field_name::t_ext> id_167 { p_0->envvars };
      uint32_t id_168 { id_167.size() };
      Vec<1, uint32_t> id_169 {  id_168  };
      Pointer let_res_170;
      {
        Vec<1, uint32_t> leb128_sz_363 { id_169 };
        Vec<1, Pointer> id_171 {  srec_dst_362  };
        Pointer let_res_172;
        {
          Vec<1, Pointer> leb128_ptr_364 { id_171 };
          bool while_flag_173 { true };
          do {
            uint8_t id_174 { 0 };
            uint8_t id_175 { 0 };
            Pointer id_176 { leb128_ptr_364[id_175] };
            uint32_t id_177 { 128U };
            uint8_t id_178 { 0 };
            uint32_t id_179 { leb128_sz_363[id_178] };
            bool id_180 { bool(id_177 > id_179) };
            uint8_t choose_res_181;
            if (id_180) {
              uint8_t id_182 { 0 };
              uint32_t id_183 { leb128_sz_363[id_182] };
              uint8_t id_184 { uint8_t(id_183) };
              choose_res_181 = id_184;
            } else {
              uint8_t id_185 { 0 };
              uint32_t id_186 { leb128_sz_363[id_185] };
              uint8_t id_187 { uint8_t(id_186) };
              uint8_t id_188 { 128 };
              uint8_t id_189 { uint8_t(id_187 | id_188) };
              choose_res_181 = id_189;
            }
            Pointer id_190 { id_176.writeU8(choose_res_181) };
            Void id_191 { ((void)(leb128_ptr_364[id_174] = id_190), VOID) };
            (void)id_191;
            uint8_t id_192 { 0 };
            uint8_t id_193 { 0 };
            uint32_t id_194 { leb128_sz_363[id_193] };
            uint8_t id_195 { 7 };
            uint32_t id_196 { uint32_t(id_194 >> id_195) };
            Void id_197 { ((void)(leb128_sz_363[id_192] = id_196), VOID) };
            (void)id_197;
            uint8_t id_198 { 0 };
            uint32_t id_199 { leb128_sz_363[id_198] };
            uint32_t id_200 { 0U };
            bool id_201 { bool(id_199 > id_200) };
            while_flag_173 = id_201;
            if (while_flag_173) {
              (void)VOID;
            }
          } while (while_flag_173);
          (void)VOID;
          uint8_t id_202 { 0 };
          Pointer id_203 { leb128_ptr_364[id_202] };
          let_res_172 = id_203;
        }
        let_res_170 = let_res_172;
      }
      Vec<1, Pointer> id_204 {  let_res_170  };
      Pointer let_res_205;
      {
        Vec<1, Pointer> dst_ref_365 { id_204 };
        int32_t id_206 { 0L };
        Vec<1, int32_t> id_207 {  id_206  };
        Pointer let_res_208;
        {
          Vec<1, int32_t> n_ref_366 { id_207 };
          Arr<dessser::gen::field_name::t_ext> id_209 { p_0->envvars };
          for (dessser::gen::field_name::t_ext x_367 : id_209) {
            uint8_t id_210 { 0 };
            auto fun211 { dessser::gen::field_name::to_row_binary };
            uint8_t id_212 { 0 };
            Pointer id_213 { dst_ref_365[id_212] };
            Pointer id_214 { fun211(x_367, id_213) };
            Void id_215 { ((void)(dst_ref_365[id_210] = id_214), VOID) };
            (void)id_215;
            uint8_t id_216 { 0 };
            int32_t id_217 { 1L };
            uint8_t id_218 { 0 };
            int32_t id_219 { n_ref_366[id_218] };
            int32_t id_220 { int32_t(id_217 + id_219) };
            Void id_221 { ((void)(n_ref_366[id_216] = id_220), VOID) };
            (void)id_221;
            (void)id_221;
          }
          (void)VOID;
          uint8_t id_222 { 0 };
          Pointer id_223 { dst_ref_365[id_222] };
          let_res_208 = id_223;
        }
        let_res_205 = let_res_208;
      }
      let_res_166 = let_res_205;
    }
    Pointer let_res_224;
    {
      Pointer srec_dst_368 { let_res_166 };
      ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_225 { p_0->role };
      uint16_t id_226 { uint16_t(id_225.index()) };
      Pointer id_227 { srec_dst_368.writeU16Le(id_226) };
      Pointer let_res_228;
      {
        Pointer ssum_dst_370 { id_227 };
        uint16_t id_229 { 0 };
        ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_230 { p_0->role };
        uint16_t id_231 { uint16_t(id_230.index()) };
        bool id_232 { bool(id_229 == id_231) };
        Pointer choose_res_233;
        if (id_232) {
          choose_res_233 = ssum_dst_370;
        } else {
          ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_234 { p_0->role };
          uint16_t id_235 { uint16_t(id_234.index()) };
          uint16_t id_236 { 1 };
          bool id_237 { bool(id_235 == id_236) };
          Void id_238 { ((void)(assert(id_237)), VOID) };
          (void)id_238;
          ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_239 { p_0->role };
          Arr<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5> id_240 { std::get<1>(id_239) };
          uint32_t id_241 { id_240.size() };
          Vec<1, uint32_t> id_242 {  id_241  };
          Pointer let_res_243;
          {
            Vec<1, uint32_t> leb128_sz_371 { id_242 };
            Vec<1, Pointer> id_244 {  ssum_dst_370  };
            Pointer let_res_245;
            {
              Vec<1, Pointer> leb128_ptr_372 { id_244 };
              bool while_flag_246 { true };
              do {
                uint8_t id_247 { 0 };
                uint8_t id_248 { 0 };
                Pointer id_249 { leb128_ptr_372[id_248] };
                uint32_t id_250 { 128U };
                uint8_t id_251 { 0 };
                uint32_t id_252 { leb128_sz_371[id_251] };
                bool id_253 { bool(id_250 > id_252) };
                uint8_t choose_res_254;
                if (id_253) {
                  uint8_t id_255 { 0 };
                  uint32_t id_256 { leb128_sz_371[id_255] };
                  uint8_t id_257 { uint8_t(id_256) };
                  choose_res_254 = id_257;
                } else {
                  uint8_t id_258 { 0 };
                  uint32_t id_259 { leb128_sz_371[id_258] };
                  uint8_t id_260 { uint8_t(id_259) };
                  uint8_t id_261 { 128 };
                  uint8_t id_262 { uint8_t(id_260 | id_261) };
                  choose_res_254 = id_262;
                }
                Pointer id_263 { id_249.writeU8(choose_res_254) };
                Void id_264 { ((void)(leb128_ptr_372[id_247] = id_263), VOID) };
                (void)id_264;
                uint8_t id_265 { 0 };
                uint8_t id_266 { 0 };
                uint32_t id_267 { leb128_sz_371[id_266] };
                uint8_t id_268 { 7 };
                uint32_t id_269 { uint32_t(id_267 >> id_268) };
                Void id_270 { ((void)(leb128_sz_371[id_265] = id_269), VOID) };
                (void)id_270;
                uint8_t id_271 { 0 };
                uint32_t id_272 { leb128_sz_371[id_271] };
                uint32_t id_273 { 0U };
                bool id_274 { bool(id_272 > id_273) };
                while_flag_246 = id_274;
                if (while_flag_246) {
                  (void)VOID;
                }
              } while (while_flag_246);
              (void)VOID;
              uint8_t id_275 { 0 };
              Pointer id_276 { leb128_ptr_372[id_275] };
              let_res_245 = id_276;
            }
            let_res_243 = let_res_245;
          }
          Vec<1, Pointer> id_277 {  let_res_243  };
          Pointer let_res_278;
          {
            Vec<1, Pointer> dst_ref_373 { id_277 };
            int32_t id_279 { 0L };
            Vec<1, int32_t> id_280 {  id_279  };
            Pointer let_res_281;
            {
              Vec<1, int32_t> n_ref_374 { id_280 };
              ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_282 { p_0->role };
              Arr<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5> id_283 { std::get<1>(id_282) };
              for (::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5 x_375 : id_283) {
                uint8_t id_284 { 0 };
                uint8_t id_285 { 0 };
                Pointer id_286 { dst_ref_373[id_285] };
                Pointer let_res_287;
                {
                  Pointer srec_dst_376 { id_286 };
                  std::string id_288 { x_375.tunneld_host };
                  uint32_t id_289 { (uint32_t)id_288.size() };
                  Vec<1, uint32_t> id_290 {  id_289  };
                  Pointer let_res_291;
                  {
                    Vec<1, uint32_t> leb128_sz_377 { id_290 };
                    Vec<1, Pointer> id_292 {  srec_dst_376  };
                    Pointer let_res_293;
                    {
                      Vec<1, Pointer> leb128_ptr_378 { id_292 };
                      bool while_flag_294 { true };
                      do {
                        uint8_t id_295 { 0 };
                        uint8_t id_296 { 0 };
                        Pointer id_297 { leb128_ptr_378[id_296] };
                        uint32_t id_298 { 128U };
                        uint8_t id_299 { 0 };
                        uint32_t id_300 { leb128_sz_377[id_299] };
                        bool id_301 { bool(id_298 > id_300) };
                        uint8_t choose_res_302;
                        if (id_301) {
                          uint8_t id_303 { 0 };
                          uint32_t id_304 { leb128_sz_377[id_303] };
                          uint8_t id_305 { uint8_t(id_304) };
                          choose_res_302 = id_305;
                        } else {
                          uint8_t id_306 { 0 };
                          uint32_t id_307 { leb128_sz_377[id_306] };
                          uint8_t id_308 { uint8_t(id_307) };
                          uint8_t id_309 { 128 };
                          uint8_t id_310 { uint8_t(id_308 | id_309) };
                          choose_res_302 = id_310;
                        }
                        Pointer id_311 { id_297.writeU8(choose_res_302) };
                        Void id_312 { ((void)(leb128_ptr_378[id_295] = id_311), VOID) };
                        (void)id_312;
                        uint8_t id_313 { 0 };
                        uint8_t id_314 { 0 };
                        uint32_t id_315 { leb128_sz_377[id_314] };
                        uint8_t id_316 { 7 };
                        uint32_t id_317 { uint32_t(id_315 >> id_316) };
                        Void id_318 { ((void)(leb128_sz_377[id_313] = id_317), VOID) };
                        (void)id_318;
                        uint8_t id_319 { 0 };
                        uint32_t id_320 { leb128_sz_377[id_319] };
                        uint32_t id_321 { 0U };
                        bool id_322 { bool(id_320 > id_321) };
                        while_flag_294 = id_322;
                        if (while_flag_294) {
                          (void)VOID;
                        }
                      } while (while_flag_294);
                      (void)VOID;
                      uint8_t id_323 { 0 };
                      Pointer id_324 { leb128_ptr_378[id_323] };
                      let_res_293 = id_324;
                    }
                    let_res_291 = let_res_293;
                  }
                  std::string id_325 { x_375.tunneld_host };
                  Bytes id_326 { id_325 };
                  Pointer id_327 { let_res_291.writeBytes(id_326) };
                  let_res_287 = id_327;
                }
                Pointer let_res_328;
                {
                  Pointer srec_dst_379 { let_res_287 };
                  uint16_t id_329 { x_375.tunneld_port };
                  Pointer id_330 { srec_dst_379.writeU16Le(id_329) };
                  let_res_328 = id_330;
                }
                Pointer let_res_331;
                {
                  Pointer srec_dst_380 { let_res_328 };
                  uint32_t id_332 { x_375.parent_num };
                  Pointer id_333 { srec_dst_380.writeU32Le(id_332) };
                  let_res_331 = id_333;
                }
                Void id_334 { ((void)(dst_ref_373[id_284] = let_res_331), VOID) };
                (void)id_334;
                uint8_t id_335 { 0 };
                int32_t id_336 { 1L };
                uint8_t id_337 { 0 };
                int32_t id_338 { n_ref_374[id_337] };
                int32_t id_339 { int32_t(id_336 + id_338) };
                Void id_340 { ((void)(n_ref_374[id_335] = id_339), VOID) };
                (void)id_340;
                (void)id_340;
              }
              (void)VOID;
              uint8_t id_341 { 0 };
              Pointer id_342 { dst_ref_373[id_341] };
              let_res_281 = id_342;
            }
            let_res_278 = let_res_281;
          }
          choose_res_233 = let_res_278;
        }
        let_res_228 = choose_res_233;
      }
      let_res_224 = let_res_228;
    }
    Pointer let_res_343;
    {
      Pointer srec_dst_381 { let_res_224 };
      std::optional<Arr<dessser::gen::func_ref::t_ext>> id_344 { p_0->parents };
      bool id_345 { !(id_344.has_value ()) };
      Pointer choose_res_346;
      if (id_345) {
        uint8_t id_347 { 1 };
        Pointer id_348 { srec_dst_381.writeU8(id_347) };
        choose_res_346 = id_348;
      } else {
        std::optional<Arr<dessser::gen::func_ref::t_ext>> id_349 { p_0->parents };
        Arr<dessser::gen::func_ref::t_ext> id_350 { id_349.value() };
        uint32_t id_351 { id_350.size() };
        Vec<1, uint32_t> id_352 {  id_351  };
        Pointer let_res_353;
        {
          Vec<1, uint32_t> leb128_sz_382 { id_352 };
          uint8_t id_354 { 0 };
          Pointer id_355 { srec_dst_381.writeU8(id_354) };
          Vec<1, Pointer> id_356 {  id_355  };
          Pointer let_res_357;
          {
            Vec<1, Pointer> leb128_ptr_383 { id_356 };
            bool while_flag_358 { true };
            do {
              uint8_t id_359 { 0 };
              uint8_t id_360 { 0 };
              Pointer id_361 { leb128_ptr_383[id_360] };
              uint32_t id_362 { 128U };
              uint8_t id_363 { 0 };
              uint32_t id_364 { leb128_sz_382[id_363] };
              bool id_365 { bool(id_362 > id_364) };
              uint8_t choose_res_366;
              if (id_365) {
                uint8_t id_367 { 0 };
                uint32_t id_368 { leb128_sz_382[id_367] };
                uint8_t id_369 { uint8_t(id_368) };
                choose_res_366 = id_369;
              } else {
                uint8_t id_370 { 0 };
                uint32_t id_371 { leb128_sz_382[id_370] };
                uint8_t id_372 { uint8_t(id_371) };
                uint8_t id_373 { 128 };
                uint8_t id_374 { uint8_t(id_372 | id_373) };
                choose_res_366 = id_374;
              }
              Pointer id_375 { id_361.writeU8(choose_res_366) };
              Void id_376 { ((void)(leb128_ptr_383[id_359] = id_375), VOID) };
              (void)id_376;
              uint8_t id_377 { 0 };
              uint8_t id_378 { 0 };
              uint32_t id_379 { leb128_sz_382[id_378] };
              uint8_t id_380 { 7 };
              uint32_t id_381 { uint32_t(id_379 >> id_380) };
              Void id_382 { ((void)(leb128_sz_382[id_377] = id_381), VOID) };
              (void)id_382;
              uint8_t id_383 { 0 };
              uint32_t id_384 { leb128_sz_382[id_383] };
              uint32_t id_385 { 0U };
              bool id_386 { bool(id_384 > id_385) };
              while_flag_358 = id_386;
              if (while_flag_358) {
                (void)VOID;
              }
            } while (while_flag_358);
            (void)VOID;
            uint8_t id_387 { 0 };
            Pointer id_388 { leb128_ptr_383[id_387] };
            let_res_357 = id_388;
          }
          let_res_353 = let_res_357;
        }
        Vec<1, Pointer> id_389 {  let_res_353  };
        Pointer let_res_390;
        {
          Vec<1, Pointer> dst_ref_384 { id_389 };
          int32_t id_391 { 0L };
          Vec<1, int32_t> id_392 {  id_391  };
          Pointer let_res_393;
          {
            Vec<1, int32_t> n_ref_385 { id_392 };
            std::optional<Arr<dessser::gen::func_ref::t_ext>> id_394 { p_0->parents };
            Arr<dessser::gen::func_ref::t_ext> id_395 { id_394.value() };
            for (dessser::gen::func_ref::t_ext x_386 : id_395) {
              uint8_t id_396 { 0 };
              auto fun397 { dessser::gen::func_ref::to_row_binary };
              uint8_t id_398 { 0 };
              Pointer id_399 { dst_ref_384[id_398] };
              Pointer id_400 { fun397(x_386, id_399) };
              Void id_401 { ((void)(dst_ref_384[id_396] = id_400), VOID) };
              (void)id_401;
              uint8_t id_402 { 0 };
              int32_t id_403 { 1L };
              uint8_t id_404 { 0 };
              int32_t id_405 { n_ref_385[id_404] };
              int32_t id_406 { int32_t(id_403 + id_405) };
              Void id_407 { ((void)(n_ref_385[id_402] = id_406), VOID) };
              (void)id_407;
              (void)id_407;
            }
            (void)VOID;
            uint8_t id_408 { 0 };
            Pointer id_409 { dst_ref_384[id_408] };
            let_res_393 = id_409;
          }
          let_res_390 = let_res_393;
        }
        choose_res_346 = let_res_390;
      }
      let_res_343 = choose_res_346;
    }
    Pointer let_res_410;
    {
      Pointer srec_dst_387 { let_res_343 };
      Arr<dessser::gen::func_ref::t_ext> id_411 { p_0->children };
      uint32_t id_412 { id_411.size() };
      Vec<1, uint32_t> id_413 {  id_412  };
      Pointer let_res_414;
      {
        Vec<1, uint32_t> leb128_sz_388 { id_413 };
        Vec<1, Pointer> id_415 {  srec_dst_387  };
        Pointer let_res_416;
        {
          Vec<1, Pointer> leb128_ptr_389 { id_415 };
          bool while_flag_417 { true };
          do {
            uint8_t id_418 { 0 };
            uint8_t id_419 { 0 };
            Pointer id_420 { leb128_ptr_389[id_419] };
            uint32_t id_421 { 128U };
            uint8_t id_422 { 0 };
            uint32_t id_423 { leb128_sz_388[id_422] };
            bool id_424 { bool(id_421 > id_423) };
            uint8_t choose_res_425;
            if (id_424) {
              uint8_t id_426 { 0 };
              uint32_t id_427 { leb128_sz_388[id_426] };
              uint8_t id_428 { uint8_t(id_427) };
              choose_res_425 = id_428;
            } else {
              uint8_t id_429 { 0 };
              uint32_t id_430 { leb128_sz_388[id_429] };
              uint8_t id_431 { uint8_t(id_430) };
              uint8_t id_432 { 128 };
              uint8_t id_433 { uint8_t(id_431 | id_432) };
              choose_res_425 = id_433;
            }
            Pointer id_434 { id_420.writeU8(choose_res_425) };
            Void id_435 { ((void)(leb128_ptr_389[id_418] = id_434), VOID) };
            (void)id_435;
            uint8_t id_436 { 0 };
            uint8_t id_437 { 0 };
            uint32_t id_438 { leb128_sz_388[id_437] };
            uint8_t id_439 { 7 };
            uint32_t id_440 { uint32_t(id_438 >> id_439) };
            Void id_441 { ((void)(leb128_sz_388[id_436] = id_440), VOID) };
            (void)id_441;
            uint8_t id_442 { 0 };
            uint32_t id_443 { leb128_sz_388[id_442] };
            uint32_t id_444 { 0U };
            bool id_445 { bool(id_443 > id_444) };
            while_flag_417 = id_445;
            if (while_flag_417) {
              (void)VOID;
            }
          } while (while_flag_417);
          (void)VOID;
          uint8_t id_446 { 0 };
          Pointer id_447 { leb128_ptr_389[id_446] };
          let_res_416 = id_447;
        }
        let_res_414 = let_res_416;
      }
      Vec<1, Pointer> id_448 {  let_res_414  };
      Pointer let_res_449;
      {
        Vec<1, Pointer> dst_ref_390 { id_448 };
        int32_t id_450 { 0L };
        Vec<1, int32_t> id_451 {  id_450  };
        Pointer let_res_452;
        {
          Vec<1, int32_t> n_ref_391 { id_451 };
          Arr<dessser::gen::func_ref::t_ext> id_453 { p_0->children };
          for (dessser::gen::func_ref::t_ext x_392 : id_453) {
            uint8_t id_454 { 0 };
            auto fun455 { dessser::gen::func_ref::to_row_binary };
            uint8_t id_456 { 0 };
            Pointer id_457 { dst_ref_390[id_456] };
            Pointer id_458 { fun455(x_392, id_457) };
            Void id_459 { ((void)(dst_ref_390[id_454] = id_458), VOID) };
            (void)id_459;
            uint8_t id_460 { 0 };
            int32_t id_461 { 1L };
            uint8_t id_462 { 0 };
            int32_t id_463 { n_ref_391[id_462] };
            int32_t id_464 { int32_t(id_461 + id_463) };
            Void id_465 { ((void)(n_ref_391[id_460] = id_464), VOID) };
            (void)id_465;
            (void)id_465;
          }
          (void)VOID;
          uint8_t id_466 { 0 };
          Pointer id_467 { dst_ref_390[id_466] };
          let_res_452 = id_467;
        }
        let_res_449 = let_res_452;
      }
      let_res_410 = let_res_449;
    }
    return let_res_410;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::worker::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{enabled: BOOL; debug: BOOL; report_period: FLOAT; cwd: $file_path; worker_signature: STRING; info_signature: STRING; is_used: BOOL; params: ($field_name; $raql_value)[]; envvars: $field_name[]; role: [Whole Void | TopHalf {tunneld_host: STRING; tunneld_port: U16; parent_num: U32}[]]; parents: $func_ref[]?; children: $func_ref[]}")
      (let "sz_339"
        (let "sz_334"
          (let "sz_322"
            (let "sz_317"
              (let "sz_310"
                (add
                  (let "sz_305"
                    (let "sz_301" (add (size 10) (apply (ext-identifier file_path sersize-of-row-binary) (get-field "cwd" (param 0))))
                      (add (identifier "sz_301")
                        (add
                          (let "n_ref_303" (make-vec (string-length (get-field "worker_signature" (param 0))))
                            (let "lebsz_ref_304" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_303")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_304")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_304") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_304")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_304")))))) 
                          (size-of-u32 (string-length (get-field "worker_signature" (param 0)))))))
                    (add (identifier "sz_305")
                      (add
                        (let "n_ref_307" (make-vec (string-length (get-field "info_signature" (param 0))))
                          (let "lebsz_ref_308" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_307")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_308")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_308") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_308")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_308")))))) 
                        (size-of-u32 (string-length (get-field "info_signature" (param 0))))))) 
                  (size 1))
                (let "sz_ref_313"
                  (make-vec
                    (add (identifier "sz_310")
                      (let "n_ref_311" (make-vec (cardinality (get-field "params" (param 0))))
                        (let "lebsz_ref_312" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_311")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_312")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_312") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_312")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_312"))))))))
                  (seq
                    (let "repeat_n_314" (make-vec (i32 0))
                      (while (gt (to-i32 (cardinality (get-field "params" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_314")))
                        (seq
                          (set-vec (u8 0) (identifier "sz_ref_313")
                            (let "sz_316"
                              (let "sz_315" (unsafe-nth (u8 0) (identifier "sz_ref_313"))
                                (add (identifier "sz_315") (apply (ext-identifier field_name sersize-of-row-binary) (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_314")) (get-field "params" (param 0)))))))
                              (add (identifier "sz_316") (apply (ext-identifier raql_value sersize-of-row-binary) (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_314")) (get-field "params" (param 0))))))))
                          (set-vec (u8 0) (identifier "repeat_n_314") (add (unsafe-nth (u8 0) (identifier "repeat_n_314")) (i32 1)))))) 
                    (unsafe-nth (u8 0) (identifier "sz_ref_313")))))
              (let "sz_ref_320"
                (make-vec
                  (add (identifier "sz_317")
                    (let "n_ref_318" (make-vec (cardinality (get-field "envvars" (param 0))))
                      (let "lebsz_ref_319" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_318")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_319")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_319") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_319")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_319"))))))))
                (seq
                  (let "repeat_n_321" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "envvars" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_321")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_320")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_320")) (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_321")) (get-field "envvars" (param 0))))))
                        (set-vec (u8 0) (identifier "repeat_n_321") (add (unsafe-nth (u8 0) (identifier "repeat_n_321")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_320")))))
            (if (eq (u16 0) (label-of (get-field "role" (param 0)))) 
              (add (identifier "sz_322") (size 2))
              (seq (assert (eq (label-of (get-field "role" (param 0))) (u16 1)))
                (let "sz_ref_326"
                  (make-vec
                    (add (add (identifier "sz_322") (size 2))
                      (let "n_ref_324" (make-vec (cardinality (get-alt "TopHalf" (get-field "role" (param 0)))))
                        (let "lebsz_ref_325" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_324")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_325")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_325") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_325")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_325"))))))))
                  (seq
                    (let "repeat_n_327" (make-vec (i32 0))
                      (while (gt (to-i32 (cardinality (get-alt "TopHalf" (get-field "role" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_327")))
                        (seq
                          (set-vec (u8 0) (identifier "sz_ref_326")
                            (add
                              (add
                                (let "sz_328" (unsafe-nth (u8 0) (identifier "sz_ref_326"))
                                  (add (identifier "sz_328")
                                    (let "wlen_329" (string-length (get-field "tunneld_host" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_327")) (get-alt "TopHalf" (get-field "role" (param 0))))))
                                      (add
                                        (let "n_ref_330" (make-vec (identifier "wlen_329"))
                                          (let "lebsz_ref_331" (make-vec (u32 1))
                                            (seq
                                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_330")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_331")) (u8 7)))
                                                (set-vec (u8 0) (identifier "lebsz_ref_331") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_331")) (u32 1)))) 
                                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_331")))))) 
                                        (size-of-u32 (identifier "wlen_329")))))) 
                                (size 2)) (size 4))) (set-vec (u8 0) (identifier "repeat_n_327") (add (unsafe-nth (u8 0) (identifier "repeat_n_327")) (i32 1)))))) 
                    (unsafe-nth (u8 0) (identifier "sz_ref_326")))))))
          (if (is-null (get-field "parents" (param 0))) (add (identifier "sz_334") (size 1))
            (add
              (let "sz_ref_337"
                (make-vec
                  (add (identifier "sz_334")
                    (let "n_ref_335" (make-vec (cardinality (force (get-field "parents" (param 0)))))
                      (let "lebsz_ref_336" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_335")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_336")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_336") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_336")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_336"))))))))
                (seq
                  (let "repeat_n_338" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (force (get-field "parents" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_338")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_337")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_337"))
                            (apply (ext-identifier func_ref sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_338")) (force (get-field "parents" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_338") (add (unsafe-nth (u8 0) (identifier "repeat_n_338")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_337")))) (size 1))))
        (let "sz_ref_342"
          (make-vec
            (add (identifier "sz_339")
              (let "n_ref_340" (make-vec (cardinality (get-field "children" (param 0))))
                (let "lebsz_ref_341" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_340")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_341")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_341") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_341")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_341"))))))))
          (seq
            (let "repeat_n_343" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "children" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_343")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_342")
                    (add (unsafe-nth (u8 0) (identifier "sz_ref_342")) (apply (ext-identifier func_ref sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_343")) (get-field "children" (param 0))))))
                  (set-vec (u8 0) (identifier "repeat_n_343") (add (unsafe-nth (u8 0) (identifier "repeat_n_343")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_342"))))))
 */
static std::function<Size(::dessser::gen::worker::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::worker::t*)> fun468 { [&fun468](::dessser::gen::worker::t* p_0) {
    Size id_469 { 10UL };
    auto fun470 { dessser::gen::file_path::sersize_of_row_binary };
    dessser::gen::file_path::t_ext id_471 { p_0->cwd };
    Size id_472 { fun470(id_471) };
    Size id_473 { Size(id_469 + id_472) };
    Size let_res_474;
    {
      Size sz_301 { id_473 };
      std::string id_475 { p_0->worker_signature };
      uint32_t id_476 { (uint32_t)id_475.size() };
      Vec<1, uint32_t> id_477 {  id_476  };
      Size let_res_478;
      {
        Vec<1, uint32_t> n_ref_303 { id_477 };
        uint32_t id_479 { 1U };
        Vec<1, uint32_t> id_480 {  id_479  };
        Size let_res_481;
        {
          Vec<1, uint32_t> lebsz_ref_304 { id_480 };
          bool while_flag_482 { true };
          do {
            uint8_t id_483 { 0 };
            uint32_t id_484 { n_ref_303[id_483] };
            uint8_t id_485 { 0 };
            uint32_t id_486 { lebsz_ref_304[id_485] };
            uint8_t id_487 { 7 };
            uint32_t id_488 { uint32_t(id_486 << id_487) };
            bool id_489 { bool(id_484 >= id_488) };
            while_flag_482 = id_489;
            if (while_flag_482) {
              uint8_t id_490 { 0 };
              uint8_t id_491 { 0 };
              uint32_t id_492 { lebsz_ref_304[id_491] };
              uint32_t id_493 { 1U };
              uint32_t id_494 { uint32_t(id_492 + id_493) };
              Void id_495 { ((void)(lebsz_ref_304[id_490] = id_494), VOID) };
              (void)id_495;
            }
          } while (while_flag_482);
          (void)VOID;
          uint8_t id_496 { 0 };
          uint32_t id_497 { lebsz_ref_304[id_496] };
          Size id_498 { Size(id_497) };
          let_res_481 = id_498;
        }
        let_res_478 = let_res_481;
      }
      std::string id_499 { p_0->worker_signature };
      uint32_t id_500 { (uint32_t)id_499.size() };
      Size id_501 { Size(id_500) };
      Size id_502 { Size(let_res_478 + id_501) };
      Size id_503 { Size(sz_301 + id_502) };
      let_res_474 = id_503;
    }
    Size let_res_504;
    {
      Size sz_305 { let_res_474 };
      std::string id_505 { p_0->info_signature };
      uint32_t id_506 { (uint32_t)id_505.size() };
      Vec<1, uint32_t> id_507 {  id_506  };
      Size let_res_508;
      {
        Vec<1, uint32_t> n_ref_307 { id_507 };
        uint32_t id_509 { 1U };
        Vec<1, uint32_t> id_510 {  id_509  };
        Size let_res_511;
        {
          Vec<1, uint32_t> lebsz_ref_308 { id_510 };
          bool while_flag_512 { true };
          do {
            uint8_t id_513 { 0 };
            uint32_t id_514 { n_ref_307[id_513] };
            uint8_t id_515 { 0 };
            uint32_t id_516 { lebsz_ref_308[id_515] };
            uint8_t id_517 { 7 };
            uint32_t id_518 { uint32_t(id_516 << id_517) };
            bool id_519 { bool(id_514 >= id_518) };
            while_flag_512 = id_519;
            if (while_flag_512) {
              uint8_t id_520 { 0 };
              uint8_t id_521 { 0 };
              uint32_t id_522 { lebsz_ref_308[id_521] };
              uint32_t id_523 { 1U };
              uint32_t id_524 { uint32_t(id_522 + id_523) };
              Void id_525 { ((void)(lebsz_ref_308[id_520] = id_524), VOID) };
              (void)id_525;
            }
          } while (while_flag_512);
          (void)VOID;
          uint8_t id_526 { 0 };
          uint32_t id_527 { lebsz_ref_308[id_526] };
          Size id_528 { Size(id_527) };
          let_res_511 = id_528;
        }
        let_res_508 = let_res_511;
      }
      std::string id_529 { p_0->info_signature };
      uint32_t id_530 { (uint32_t)id_529.size() };
      Size id_531 { Size(id_530) };
      Size id_532 { Size(let_res_508 + id_531) };
      Size id_533 { Size(sz_305 + id_532) };
      let_res_504 = id_533;
    }
    Size id_534 { 1UL };
    Size id_535 { Size(let_res_504 + id_534) };
    Size let_res_536;
    {
      Size sz_310 { id_535 };
      Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> id_537 { p_0->params };
      uint32_t id_538 { id_537.size() };
      Vec<1, uint32_t> id_539 {  id_538  };
      Size let_res_540;
      {
        Vec<1, uint32_t> n_ref_311 { id_539 };
        uint32_t id_541 { 1U };
        Vec<1, uint32_t> id_542 {  id_541  };
        Size let_res_543;
        {
          Vec<1, uint32_t> lebsz_ref_312 { id_542 };
          bool while_flag_544 { true };
          do {
            uint8_t id_545 { 0 };
            uint32_t id_546 { n_ref_311[id_545] };
            uint8_t id_547 { 0 };
            uint32_t id_548 { lebsz_ref_312[id_547] };
            uint8_t id_549 { 7 };
            uint32_t id_550 { uint32_t(id_548 << id_549) };
            bool id_551 { bool(id_546 >= id_550) };
            while_flag_544 = id_551;
            if (while_flag_544) {
              uint8_t id_552 { 0 };
              uint8_t id_553 { 0 };
              uint32_t id_554 { lebsz_ref_312[id_553] };
              uint32_t id_555 { 1U };
              uint32_t id_556 { uint32_t(id_554 + id_555) };
              Void id_557 { ((void)(lebsz_ref_312[id_552] = id_556), VOID) };
              (void)id_557;
            }
          } while (while_flag_544);
          (void)VOID;
          uint8_t id_558 { 0 };
          uint32_t id_559 { lebsz_ref_312[id_558] };
          Size id_560 { Size(id_559) };
          let_res_543 = id_560;
        }
        let_res_540 = let_res_543;
      }
      Size id_561 { Size(sz_310 + let_res_540) };
      Vec<1, Size> id_562 {  id_561  };
      Size let_res_563;
      {
        Vec<1, Size> sz_ref_313 { id_562 };
        int32_t id_564 { 0L };
        Vec<1, int32_t> id_565 {  id_564  };
        {
          Vec<1, int32_t> repeat_n_314 { id_565 };
          bool while_flag_566 { true };
          do {
            Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> id_567 { p_0->params };
            uint32_t id_568 { id_567.size() };
            int32_t id_569 { int32_t(id_568) };
            uint8_t id_570 { 0 };
            int32_t id_571 { repeat_n_314[id_570] };
            bool id_572 { bool(id_569 > id_571) };
            while_flag_566 = id_572;
            if (while_flag_566) {
              uint8_t id_573 { 0 };
              uint8_t id_574 { 0 };
              Size id_575 { sz_ref_313[id_574] };
              Size let_res_576;
              {
                Size sz_315 { id_575 };
                auto fun577 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_578 { 0 };
                int32_t id_579 { repeat_n_314[id_578] };
                Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> id_580 { p_0->params };
                ::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374 id_581 { id_580[id_579] };
                dessser::gen::field_name::t_ext id_582 { std::get<0>(id_581) };
                Size id_583 { fun577(id_582) };
                Size id_584 { Size(sz_315 + id_583) };
                let_res_576 = id_584;
              }
              Size let_res_585;
              {
                Size sz_316 { let_res_576 };
                auto fun586 { dessser::gen::raql_value::sersize_of_row_binary };
                uint8_t id_587 { 0 };
                int32_t id_588 { repeat_n_314[id_587] };
                Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> id_589 { p_0->params };
                ::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374 id_590 { id_589[id_588] };
                dessser::gen::raql_value::t_ext id_591 { std::get<1>(id_590) };
                Size id_592 { fun586(id_591) };
                Size id_593 { Size(sz_316 + id_592) };
                let_res_585 = id_593;
              }
              Void id_594 { ((void)(sz_ref_313[id_573] = let_res_585), VOID) };
              (void)id_594;
              uint8_t id_595 { 0 };
              uint8_t id_596 { 0 };
              int32_t id_597 { repeat_n_314[id_596] };
              int32_t id_598 { 1L };
              int32_t id_599 { int32_t(id_597 + id_598) };
              Void id_600 { ((void)(repeat_n_314[id_595] = id_599), VOID) };
              (void)id_600;
              (void)id_600;
            }
          } while (while_flag_566);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_601 { 0 };
        Size id_602 { sz_ref_313[id_601] };
        let_res_563 = id_602;
      }
      let_res_536 = let_res_563;
    }
    Size let_res_603;
    {
      Size sz_317 { let_res_536 };
      Arr<dessser::gen::field_name::t_ext> id_604 { p_0->envvars };
      uint32_t id_605 { id_604.size() };
      Vec<1, uint32_t> id_606 {  id_605  };
      Size let_res_607;
      {
        Vec<1, uint32_t> n_ref_318 { id_606 };
        uint32_t id_608 { 1U };
        Vec<1, uint32_t> id_609 {  id_608  };
        Size let_res_610;
        {
          Vec<1, uint32_t> lebsz_ref_319 { id_609 };
          bool while_flag_611 { true };
          do {
            uint8_t id_612 { 0 };
            uint32_t id_613 { n_ref_318[id_612] };
            uint8_t id_614 { 0 };
            uint32_t id_615 { lebsz_ref_319[id_614] };
            uint8_t id_616 { 7 };
            uint32_t id_617 { uint32_t(id_615 << id_616) };
            bool id_618 { bool(id_613 >= id_617) };
            while_flag_611 = id_618;
            if (while_flag_611) {
              uint8_t id_619 { 0 };
              uint8_t id_620 { 0 };
              uint32_t id_621 { lebsz_ref_319[id_620] };
              uint32_t id_622 { 1U };
              uint32_t id_623 { uint32_t(id_621 + id_622) };
              Void id_624 { ((void)(lebsz_ref_319[id_619] = id_623), VOID) };
              (void)id_624;
            }
          } while (while_flag_611);
          (void)VOID;
          uint8_t id_625 { 0 };
          uint32_t id_626 { lebsz_ref_319[id_625] };
          Size id_627 { Size(id_626) };
          let_res_610 = id_627;
        }
        let_res_607 = let_res_610;
      }
      Size id_628 { Size(sz_317 + let_res_607) };
      Vec<1, Size> id_629 {  id_628  };
      Size let_res_630;
      {
        Vec<1, Size> sz_ref_320 { id_629 };
        int32_t id_631 { 0L };
        Vec<1, int32_t> id_632 {  id_631  };
        {
          Vec<1, int32_t> repeat_n_321 { id_632 };
          bool while_flag_633 { true };
          do {
            Arr<dessser::gen::field_name::t_ext> id_634 { p_0->envvars };
            uint32_t id_635 { id_634.size() };
            int32_t id_636 { int32_t(id_635) };
            uint8_t id_637 { 0 };
            int32_t id_638 { repeat_n_321[id_637] };
            bool id_639 { bool(id_636 > id_638) };
            while_flag_633 = id_639;
            if (while_flag_633) {
              uint8_t id_640 { 0 };
              uint8_t id_641 { 0 };
              Size id_642 { sz_ref_320[id_641] };
              auto fun643 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_644 { 0 };
              int32_t id_645 { repeat_n_321[id_644] };
              Arr<dessser::gen::field_name::t_ext> id_646 { p_0->envvars };
              dessser::gen::field_name::t_ext id_647 { id_646[id_645] };
              Size id_648 { fun643(id_647) };
              Size id_649 { Size(id_642 + id_648) };
              Void id_650 { ((void)(sz_ref_320[id_640] = id_649), VOID) };
              (void)id_650;
              uint8_t id_651 { 0 };
              uint8_t id_652 { 0 };
              int32_t id_653 { repeat_n_321[id_652] };
              int32_t id_654 { 1L };
              int32_t id_655 { int32_t(id_653 + id_654) };
              Void id_656 { ((void)(repeat_n_321[id_651] = id_655), VOID) };
              (void)id_656;
              (void)id_656;
            }
          } while (while_flag_633);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_657 { 0 };
        Size id_658 { sz_ref_320[id_657] };
        let_res_630 = id_658;
      }
      let_res_603 = let_res_630;
    }
    Size let_res_659;
    {
      Size sz_322 { let_res_603 };
      uint16_t id_660 { 0 };
      ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_661 { p_0->role };
      uint16_t id_662 { uint16_t(id_661.index()) };
      bool id_663 { bool(id_660 == id_662) };
      Size choose_res_664;
      if (id_663) {
        Size id_665 { 2UL };
        Size id_666 { Size(sz_322 + id_665) };
        choose_res_664 = id_666;
      } else {
        ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_667 { p_0->role };
        uint16_t id_668 { uint16_t(id_667.index()) };
        uint16_t id_669 { 1 };
        bool id_670 { bool(id_668 == id_669) };
        Void id_671 { ((void)(assert(id_670)), VOID) };
        (void)id_671;
        Size id_672 { 2UL };
        Size id_673 { Size(sz_322 + id_672) };
        ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_674 { p_0->role };
        Arr<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5> id_675 { std::get<1>(id_674) };
        uint32_t id_676 { id_675.size() };
        Vec<1, uint32_t> id_677 {  id_676  };
        Size let_res_678;
        {
          Vec<1, uint32_t> n_ref_324 { id_677 };
          uint32_t id_679 { 1U };
          Vec<1, uint32_t> id_680 {  id_679  };
          Size let_res_681;
          {
            Vec<1, uint32_t> lebsz_ref_325 { id_680 };
            bool while_flag_682 { true };
            do {
              uint8_t id_683 { 0 };
              uint32_t id_684 { n_ref_324[id_683] };
              uint8_t id_685 { 0 };
              uint32_t id_686 { lebsz_ref_325[id_685] };
              uint8_t id_687 { 7 };
              uint32_t id_688 { uint32_t(id_686 << id_687) };
              bool id_689 { bool(id_684 >= id_688) };
              while_flag_682 = id_689;
              if (while_flag_682) {
                uint8_t id_690 { 0 };
                uint8_t id_691 { 0 };
                uint32_t id_692 { lebsz_ref_325[id_691] };
                uint32_t id_693 { 1U };
                uint32_t id_694 { uint32_t(id_692 + id_693) };
                Void id_695 { ((void)(lebsz_ref_325[id_690] = id_694), VOID) };
                (void)id_695;
              }
            } while (while_flag_682);
            (void)VOID;
            uint8_t id_696 { 0 };
            uint32_t id_697 { lebsz_ref_325[id_696] };
            Size id_698 { Size(id_697) };
            let_res_681 = id_698;
          }
          let_res_678 = let_res_681;
        }
        Size id_699 { Size(id_673 + let_res_678) };
        Vec<1, Size> id_700 {  id_699  };
        Size let_res_701;
        {
          Vec<1, Size> sz_ref_326 { id_700 };
          int32_t id_702 { 0L };
          Vec<1, int32_t> id_703 {  id_702  };
          {
            Vec<1, int32_t> repeat_n_327 { id_703 };
            bool while_flag_704 { true };
            do {
              ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_705 { p_0->role };
              Arr<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5> id_706 { std::get<1>(id_705) };
              uint32_t id_707 { id_706.size() };
              int32_t id_708 { int32_t(id_707) };
              uint8_t id_709 { 0 };
              int32_t id_710 { repeat_n_327[id_709] };
              bool id_711 { bool(id_708 > id_710) };
              while_flag_704 = id_711;
              if (while_flag_704) {
                uint8_t id_712 { 0 };
                uint8_t id_713 { 0 };
                Size id_714 { sz_ref_326[id_713] };
                Size let_res_715;
                {
                  Size sz_328 { id_714 };
                  uint8_t id_716 { 0 };
                  int32_t id_717 { repeat_n_327[id_716] };
                  ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_718 { p_0->role };
                  Arr<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5> id_719 { std::get<1>(id_718) };
                  ::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5 id_720 { id_719[id_717] };
                  std::string id_721 { id_720.tunneld_host };
                  uint32_t id_722 { (uint32_t)id_721.size() };
                  Size let_res_723;
                  {
                    uint32_t wlen_329 { id_722 };
                    Vec<1, uint32_t> id_724 {  wlen_329  };
                    Size let_res_725;
                    {
                      Vec<1, uint32_t> n_ref_330 { id_724 };
                      uint32_t id_726 { 1U };
                      Vec<1, uint32_t> id_727 {  id_726  };
                      Size let_res_728;
                      {
                        Vec<1, uint32_t> lebsz_ref_331 { id_727 };
                        bool while_flag_729 { true };
                        do {
                          uint8_t id_730 { 0 };
                          uint32_t id_731 { n_ref_330[id_730] };
                          uint8_t id_732 { 0 };
                          uint32_t id_733 { lebsz_ref_331[id_732] };
                          uint8_t id_734 { 7 };
                          uint32_t id_735 { uint32_t(id_733 << id_734) };
                          bool id_736 { bool(id_731 >= id_735) };
                          while_flag_729 = id_736;
                          if (while_flag_729) {
                            uint8_t id_737 { 0 };
                            uint8_t id_738 { 0 };
                            uint32_t id_739 { lebsz_ref_331[id_738] };
                            uint32_t id_740 { 1U };
                            uint32_t id_741 { uint32_t(id_739 + id_740) };
                            Void id_742 { ((void)(lebsz_ref_331[id_737] = id_741), VOID) };
                            (void)id_742;
                          }
                        } while (while_flag_729);
                        (void)VOID;
                        uint8_t id_743 { 0 };
                        uint32_t id_744 { lebsz_ref_331[id_743] };
                        Size id_745 { Size(id_744) };
                        let_res_728 = id_745;
                      }
                      let_res_725 = let_res_728;
                    }
                    Size id_746 { Size(wlen_329) };
                    Size id_747 { Size(let_res_725 + id_746) };
                    let_res_723 = id_747;
                  }
                  Size id_748 { Size(sz_328 + let_res_723) };
                  let_res_715 = id_748;
                }
                Size id_749 { 2UL };
                Size id_750 { Size(let_res_715 + id_749) };
                Size id_751 { 4UL };
                Size id_752 { Size(id_750 + id_751) };
                Void id_753 { ((void)(sz_ref_326[id_712] = id_752), VOID) };
                (void)id_753;
                uint8_t id_754 { 0 };
                uint8_t id_755 { 0 };
                int32_t id_756 { repeat_n_327[id_755] };
                int32_t id_757 { 1L };
                int32_t id_758 { int32_t(id_756 + id_757) };
                Void id_759 { ((void)(repeat_n_327[id_754] = id_758), VOID) };
                (void)id_759;
                (void)id_759;
              }
            } while (while_flag_704);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_760 { 0 };
          Size id_761 { sz_ref_326[id_760] };
          let_res_701 = id_761;
        }
        choose_res_664 = let_res_701;
      }
      let_res_659 = choose_res_664;
    }
    Size let_res_762;
    {
      Size sz_334 { let_res_659 };
      std::optional<Arr<dessser::gen::func_ref::t_ext>> id_763 { p_0->parents };
      bool id_764 { !(id_763.has_value ()) };
      Size choose_res_765;
      if (id_764) {
        Size id_766 { 1UL };
        Size id_767 { Size(sz_334 + id_766) };
        choose_res_765 = id_767;
      } else {
        std::optional<Arr<dessser::gen::func_ref::t_ext>> id_768 { p_0->parents };
        Arr<dessser::gen::func_ref::t_ext> id_769 { id_768.value() };
        uint32_t id_770 { id_769.size() };
        Vec<1, uint32_t> id_771 {  id_770  };
        Size let_res_772;
        {
          Vec<1, uint32_t> n_ref_335 { id_771 };
          uint32_t id_773 { 1U };
          Vec<1, uint32_t> id_774 {  id_773  };
          Size let_res_775;
          {
            Vec<1, uint32_t> lebsz_ref_336 { id_774 };
            bool while_flag_776 { true };
            do {
              uint8_t id_777 { 0 };
              uint32_t id_778 { n_ref_335[id_777] };
              uint8_t id_779 { 0 };
              uint32_t id_780 { lebsz_ref_336[id_779] };
              uint8_t id_781 { 7 };
              uint32_t id_782 { uint32_t(id_780 << id_781) };
              bool id_783 { bool(id_778 >= id_782) };
              while_flag_776 = id_783;
              if (while_flag_776) {
                uint8_t id_784 { 0 };
                uint8_t id_785 { 0 };
                uint32_t id_786 { lebsz_ref_336[id_785] };
                uint32_t id_787 { 1U };
                uint32_t id_788 { uint32_t(id_786 + id_787) };
                Void id_789 { ((void)(lebsz_ref_336[id_784] = id_788), VOID) };
                (void)id_789;
              }
            } while (while_flag_776);
            (void)VOID;
            uint8_t id_790 { 0 };
            uint32_t id_791 { lebsz_ref_336[id_790] };
            Size id_792 { Size(id_791) };
            let_res_775 = id_792;
          }
          let_res_772 = let_res_775;
        }
        Size id_793 { Size(sz_334 + let_res_772) };
        Vec<1, Size> id_794 {  id_793  };
        Size let_res_795;
        {
          Vec<1, Size> sz_ref_337 { id_794 };
          int32_t id_796 { 0L };
          Vec<1, int32_t> id_797 {  id_796  };
          {
            Vec<1, int32_t> repeat_n_338 { id_797 };
            bool while_flag_798 { true };
            do {
              std::optional<Arr<dessser::gen::func_ref::t_ext>> id_799 { p_0->parents };
              Arr<dessser::gen::func_ref::t_ext> id_800 { id_799.value() };
              uint32_t id_801 { id_800.size() };
              int32_t id_802 { int32_t(id_801) };
              uint8_t id_803 { 0 };
              int32_t id_804 { repeat_n_338[id_803] };
              bool id_805 { bool(id_802 > id_804) };
              while_flag_798 = id_805;
              if (while_flag_798) {
                uint8_t id_806 { 0 };
                uint8_t id_807 { 0 };
                Size id_808 { sz_ref_337[id_807] };
                auto fun809 { dessser::gen::func_ref::sersize_of_row_binary };
                uint8_t id_810 { 0 };
                int32_t id_811 { repeat_n_338[id_810] };
                std::optional<Arr<dessser::gen::func_ref::t_ext>> id_812 { p_0->parents };
                Arr<dessser::gen::func_ref::t_ext> id_813 { id_812.value() };
                dessser::gen::func_ref::t_ext id_814 { id_813[id_811] };
                Size id_815 { fun809(id_814) };
                Size id_816 { Size(id_808 + id_815) };
                Void id_817 { ((void)(sz_ref_337[id_806] = id_816), VOID) };
                (void)id_817;
                uint8_t id_818 { 0 };
                uint8_t id_819 { 0 };
                int32_t id_820 { repeat_n_338[id_819] };
                int32_t id_821 { 1L };
                int32_t id_822 { int32_t(id_820 + id_821) };
                Void id_823 { ((void)(repeat_n_338[id_818] = id_822), VOID) };
                (void)id_823;
                (void)id_823;
              }
            } while (while_flag_798);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_824 { 0 };
          Size id_825 { sz_ref_337[id_824] };
          let_res_795 = id_825;
        }
        Size id_826 { 1UL };
        Size id_827 { Size(let_res_795 + id_826) };
        choose_res_765 = id_827;
      }
      let_res_762 = choose_res_765;
    }
    Size let_res_828;
    {
      Size sz_339 { let_res_762 };
      Arr<dessser::gen::func_ref::t_ext> id_829 { p_0->children };
      uint32_t id_830 { id_829.size() };
      Vec<1, uint32_t> id_831 {  id_830  };
      Size let_res_832;
      {
        Vec<1, uint32_t> n_ref_340 { id_831 };
        uint32_t id_833 { 1U };
        Vec<1, uint32_t> id_834 {  id_833  };
        Size let_res_835;
        {
          Vec<1, uint32_t> lebsz_ref_341 { id_834 };
          bool while_flag_836 { true };
          do {
            uint8_t id_837 { 0 };
            uint32_t id_838 { n_ref_340[id_837] };
            uint8_t id_839 { 0 };
            uint32_t id_840 { lebsz_ref_341[id_839] };
            uint8_t id_841 { 7 };
            uint32_t id_842 { uint32_t(id_840 << id_841) };
            bool id_843 { bool(id_838 >= id_842) };
            while_flag_836 = id_843;
            if (while_flag_836) {
              uint8_t id_844 { 0 };
              uint8_t id_845 { 0 };
              uint32_t id_846 { lebsz_ref_341[id_845] };
              uint32_t id_847 { 1U };
              uint32_t id_848 { uint32_t(id_846 + id_847) };
              Void id_849 { ((void)(lebsz_ref_341[id_844] = id_848), VOID) };
              (void)id_849;
            }
          } while (while_flag_836);
          (void)VOID;
          uint8_t id_850 { 0 };
          uint32_t id_851 { lebsz_ref_341[id_850] };
          Size id_852 { Size(id_851) };
          let_res_835 = id_852;
        }
        let_res_832 = let_res_835;
      }
      Size id_853 { Size(sz_339 + let_res_832) };
      Vec<1, Size> id_854 {  id_853  };
      Size let_res_855;
      {
        Vec<1, Size> sz_ref_342 { id_854 };
        int32_t id_856 { 0L };
        Vec<1, int32_t> id_857 {  id_856  };
        {
          Vec<1, int32_t> repeat_n_343 { id_857 };
          bool while_flag_858 { true };
          do {
            Arr<dessser::gen::func_ref::t_ext> id_859 { p_0->children };
            uint32_t id_860 { id_859.size() };
            int32_t id_861 { int32_t(id_860) };
            uint8_t id_862 { 0 };
            int32_t id_863 { repeat_n_343[id_862] };
            bool id_864 { bool(id_861 > id_863) };
            while_flag_858 = id_864;
            if (while_flag_858) {
              uint8_t id_865 { 0 };
              uint8_t id_866 { 0 };
              Size id_867 { sz_ref_342[id_866] };
              auto fun868 { dessser::gen::func_ref::sersize_of_row_binary };
              uint8_t id_869 { 0 };
              int32_t id_870 { repeat_n_343[id_869] };
              Arr<dessser::gen::func_ref::t_ext> id_871 { p_0->children };
              dessser::gen::func_ref::t_ext id_872 { id_871[id_870] };
              Size id_873 { fun868(id_872) };
              Size id_874 { Size(id_867 + id_873) };
              Void id_875 { ((void)(sz_ref_342[id_865] = id_874), VOID) };
              (void)id_875;
              uint8_t id_876 { 0 };
              uint8_t id_877 { 0 };
              int32_t id_878 { repeat_n_343[id_877] };
              int32_t id_879 { 1L };
              int32_t id_880 { int32_t(id_878 + id_879) };
              Void id_881 { ((void)(repeat_n_343[id_876] = id_880), VOID) };
              (void)id_881;
              (void)id_881;
            }
          } while (while_flag_858);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_882 { 0 };
        Size id_883 { sz_ref_342[id_882] };
        let_res_855 = id_883;
      }
      let_res_828 = let_res_855;
    }
    return let_res_828;
  }
   };
  return fun468;
}
std::function<Size(::dessser::gen::worker::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_59" (let-pair "dbool_fst_57" "dbool_snd_58" (read-u8 (param 0)) (make-tup (not (eq (identifier "dbool_fst_57") (u8 0))) (identifier "dbool_snd_58")))
        (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
          (let "drec_65" (let-pair "dbool_fst_63" "dbool_snd_64" (read-u8 (identifier "drec_snd_61")) (make-tup (not (eq (identifier "dbool_fst_63") (u8 0))) (identifier "dbool_snd_64")))
            (let-pair "drec_fst_66" "drec_snd_67" (identifier "drec_65")
              (let "drec_71" (let-pair "dfloat_fst_69" "dfloat_snd_70" (read-u64 little-endian (identifier "drec_snd_67")) (make-tup (float-of-u64 (identifier "dfloat_fst_69")) (identifier "dfloat_snd_70")))
                (let-pair "drec_fst_72" "drec_snd_73" (identifier "drec_71")
                  (let "drec_74" (apply (ext-identifier file_path of-row-binary) (identifier "drec_snd_73"))
                    (let-pair "drec_fst_75" "drec_snd_76" (identifier "drec_74")
                      (let "drec_89"
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
                              (make-tup (string-of-bytes (identifier "dstring2_fst_87")) (identifier "dstring2_snd_88")))))
                        (let-pair "drec_fst_90" "drec_snd_91" (identifier "drec_89")
                          (let "drec_104"
                            (let "dstring1_98"
                              (let "leb_ref_92" (make-vec (u32 0))
                                (let "shft_ref_93" (make-vec (u8 0))
                                  (let "p_ref_94" (make-vec (identifier "drec_snd_91"))
                                    (seq
                                      (while
                                        (let "leb128_95" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_94")))
                                          (let-pair "leb128_fst_96" "leb128_snd_97" 
                                            (identifier "leb128_95")
                                            (seq (set-vec (u8 0) (identifier "p_ref_94") (identifier "leb128_snd_97"))
                                              (set-vec (u8 0) (identifier "leb_ref_92")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_96") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_93"))) (unsafe-nth (u8 0) (identifier "leb_ref_92"))))
                                              (set-vec (u8 0) (identifier "shft_ref_93") (add (unsafe-nth (u8 0) (identifier "shft_ref_93")) (u8 7))) 
                                              (ge (identifier "leb128_fst_96") (u8 128))))) 
                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_92"))) (unsafe-nth (u8 0) (identifier "p_ref_94")))))))
                              (let-pair "dstring1_fst_99" "dstring1_snd_100" 
                                (identifier "dstring1_98")
                                (let-pair "dstring2_fst_102" "dstring2_snd_103" 
                                  (read-bytes (identifier "dstring1_snd_100") (identifier "dstring1_fst_99")) 
                                  (make-tup (string-of-bytes (identifier "dstring2_fst_102")) (identifier "dstring2_snd_103")))))
                            (let-pair "drec_fst_105" "drec_snd_106" (identifier "drec_104")
                              (let "drec_110" (let-pair "dbool_fst_108" "dbool_snd_109" (read-u8 (identifier "drec_snd_106")) (make-tup (not (eq (identifier "dbool_fst_108") (u8 0))) (identifier "dbool_snd_109")))
                                (let-pair "drec_fst_111" "drec_snd_112" 
                                  (identifier "drec_110")
                                  (let "drec_142"
                                    (let-pair "dlist4_fst_140" "dlist4_snd_141"
                                      (let "dlist1_122"
                                        (let "leb_ref_113" (make-vec (u32 0))
                                          (let "shft_ref_114" (make-vec (u8 0))
                                            (let "p_ref_115" (make-vec (identifier "drec_snd_112"))
                                              (seq
                                                (while
                                                  (let "leb128_116" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_115")))
                                                    (let-pair "leb128_fst_117" "leb128_snd_118" 
                                                      (identifier "leb128_116")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_115") (identifier "leb128_snd_118"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_113")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_117") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_114")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_113")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_114") (add (unsafe-nth (u8 0) (identifier "shft_ref_114")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_117") (u8 128))))) 
                                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_113")) (unsafe-nth (u8 0) (identifier "p_ref_115")))))))
                                        (let-pair "dlist1_fst_123" "dlist1_snd_124" 
                                          (identifier "dlist1_122")
                                          (let "inits_src_ref_125" (make-vec (make-tup (end-of-list "($field_name; $raql_value)") (identifier "dlist1_snd_124")))
                                            (seq
                                              (let "repeat_n_126" (make-vec (i32 0))
                                                (while (gt (to-i32 (identifier "dlist1_fst_123")) (unsafe-nth (u8 0) (identifier "repeat_n_126")))
                                                  (seq
                                                    (let "dlist2_127" 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_125"))
                                                      (let-pair "dlist2_fst_128" "dlist2_snd_129" 
                                                        (identifier "dlist2_127")
                                                        (set-vec (u8 0) 
                                                          (identifier "inits_src_ref_125")
                                                          (let "dtup_130" 
                                                            (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_129"))
                                                            (let-pair "dtup_fst_131" "dtup_snd_132" 
                                                              (identifier "dtup_130")
                                                              (let-pair "dtup_fst_134" "dtup_snd_135" 
                                                                (apply (ext-identifier raql_value of-row-binary) (identifier "dtup_snd_132"))
                                                                (make-tup (cons (make-tup (identifier "dtup_fst_131") (identifier "dtup_fst_134")) (identifier "dlist2_fst_128")) (identifier "dtup_snd_135"))))))))
                                                    (set-vec (u8 0) (identifier "repeat_n_126") (add (unsafe-nth (u8 0) (identifier "repeat_n_126")) (i32 1)))))) 
                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_125")))))) 
                                      (make-tup (arr-of-lst-rev (identifier "dlist4_fst_140")) (identifier "dlist4_snd_141")))
                                    (let-pair "drec_fst_143" "drec_snd_144" 
                                      (identifier "drec_142")
                                      (let "drec_168"
                                        (let-pair "dlist4_fst_166" "dlist4_snd_167"
                                          (let "dlist1_154"
                                            (let "leb_ref_145" (make-vec (u32 0))
                                              (let "shft_ref_146" (make-vec (u8 0))
                                                (let "p_ref_147" (make-vec (identifier "drec_snd_144"))
                                                  (seq
                                                    (while
                                                      (let "leb128_148" 
                                                        (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_147")))
                                                        (let-pair "leb128_fst_149" "leb128_snd_150" 
                                                          (identifier "leb128_148")
                                                          (seq (set-vec (u8 0) (identifier "p_ref_147") (identifier "leb128_snd_150"))
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb_ref_145")
                                                              (bit-or 
                                                                (left-shift (to-u32 (bit-and (identifier "leb128_fst_149") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_146")))
                                                                (unsafe-nth (u8 0) (identifier "leb_ref_145")))) 
                                                            (set-vec (u8 0) (identifier "shft_ref_146") (add (unsafe-nth (u8 0) (identifier "shft_ref_146")) (u8 7))) 
                                                            (ge (identifier "leb128_fst_149") (u8 128))))) 
                                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_145")) (unsafe-nth (u8 0) (identifier "p_ref_147")))))))
                                            (let-pair "dlist1_fst_155" "dlist1_snd_156" 
                                              (identifier "dlist1_154")
                                              (let "inits_src_ref_157" 
                                                (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_156")))
                                                (seq
                                                  (let "repeat_n_158" 
                                                    (make-vec (i32 0))
                                                    (while (gt (to-i32 (identifier "dlist1_fst_155")) (unsafe-nth (u8 0) (identifier "repeat_n_158")))
                                                      (seq
                                                        (let "dlist2_159" 
                                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_157"))
                                                          (let-pair "dlist2_fst_160" "dlist2_snd_161" 
                                                            (identifier "dlist2_159")
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "inits_src_ref_157")
                                                              (let-pair "dlist3_fst_163" "dlist3_snd_164" 
                                                                (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_161"))
                                                                (make-tup (cons (identifier "dlist3_fst_163") (identifier "dlist2_fst_160")) (identifier "dlist3_snd_164"))))))
                                                        (set-vec (u8 0) (identifier "repeat_n_158") (add (unsafe-nth (u8 0) (identifier "repeat_n_158")) (i32 1)))))) 
                                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_157")))))) 
                                          (make-tup (arr-of-lst-rev (identifier "dlist4_fst_166")) (identifier "dlist4_snd_167")))
                                        (let-pair "drec_fst_169" "drec_snd_170" 
                                          (identifier "drec_168")
                                          (let "drec_236"
                                            (let "dsum1_177" (let-pair "du16_fst_172" "du16_snd_173" (read-u16 little-endian (identifier "drec_snd_170")) (make-tup (identifier "du16_fst_172") (identifier "du16_snd_173")))
                                              (let-pair "dsum1_fst_178" "dsum1_snd_179" 
                                                (identifier "dsum1_177")
                                                (if (eq (u16 0) (identifier "dsum1_fst_178"))
                                                  (make-tup (construct "[Whole Void | TopHalf {tunneld_host: STRING; tunneld_port: U16; parent_num: U32}[]]" 0 (nop)) (identifier "dsum1_snd_179"))
                                                  (seq (assert (eq (identifier "dsum1_fst_178") (u16 1)))
                                                    (let-pair "dlist4_fst_228" "dlist4_snd_229"
                                                      (let "dlist1_189"
                                                        (let "leb_ref_180" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_181" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_182" 
                                                              (make-vec (identifier "dsum1_snd_179"))
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
                                                            (make-vec (make-tup (end-of-list "{tunneld_host: STRING; tunneld_port: U16; parent_num: U32}") (identifier "dlist1_snd_191")))
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
                                                                    (let "drec_209"
                                                                    (let "dstring1_203"
                                                                    (let "leb_ref_197" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_198" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_199" 
                                                                    (make-vec (identifier "dlist2_snd_196"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_200" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_199")))
                                                                    (let-pair "leb128_fst_201" "leb128_snd_202" 
                                                                    (identifier "leb128_200")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_199") (identifier "leb128_snd_202"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_197")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_201") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_198")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_197")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_198") (add (unsafe-nth (u8 0) (identifier "shft_ref_198")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_201") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_197"))) (unsafe-nth (u8 0) (identifier "p_ref_199")))))))
                                                                    (let-pair "dstring1_fst_204" "dstring1_snd_205" 
                                                                    (identifier "dstring1_203")
                                                                    (let-pair "dstring2_fst_207" "dstring2_snd_208" 
                                                                    (read-bytes (identifier "dstring1_snd_205") (identifier "dstring1_fst_204"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_207")) (identifier "dstring2_snd_208")))))
                                                                    (let-pair "drec_fst_210" "drec_snd_211" 
                                                                    (identifier "drec_209")
                                                                    (let "drec_215"
                                                                    (let-pair "du16_fst_213" "du16_snd_214" (read-u16 little-endian (identifier "drec_snd_211")) (make-tup (identifier "du16_fst_213") (identifier "du16_snd_214")))
                                                                    (let-pair "drec_fst_216" "drec_snd_217" 
                                                                    (identifier "drec_215")
                                                                    (let-pair "du32_fst_219" "du32_snd_220" 
                                                                    (read-u32 little-endian (identifier "drec_snd_217"))
                                                                    (make-tup
                                                                    (cons
                                                                    (make-rec 
                                                                    (string "parent_num") 
                                                                    (identifier "du32_fst_219") 
                                                                    (string "tunneld_port") 
                                                                    (identifier "drec_fst_216") 
                                                                    (string "tunneld_host") 
                                                                    (identifier "drec_fst_210")) 
                                                                    (identifier "dlist2_fst_195")) 
                                                                    (identifier "du32_snd_220")))))))))) 
                                                                    (set-vec (u8 0) (identifier "repeat_n_193") (add (unsafe-nth (u8 0) (identifier "repeat_n_193")) (i32 1))))))
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_192"))))))
                                                      (make-tup (construct "[Whole Void | TopHalf {tunneld_host: STRING; tunneld_port: U16; parent_num: U32}[]]" 1 (arr-of-lst-rev (identifier "dlist4_fst_228")))
                                                        (identifier "dlist4_snd_229")))))))
                                            (let-pair "drec_fst_237" "drec_snd_238" 
                                              (identifier "drec_236")
                                              (let "drec_265"
                                                (if (eq (peek-u8 (identifier "drec_snd_238") (size 0)) (u8 1)) 
                                                  (make-tup (null "$func_ref[]") (ptr-add (identifier "drec_snd_238") (size 1)))
                                                  (let-pair "dlist4_fst_260" "dlist4_snd_261"
                                                    (let "dlist1_248"
                                                      (let "leb_ref_239" 
                                                        (make-vec (u32 0))
                                                        (let "shft_ref_240" 
                                                          (make-vec (u8 0))
                                                          (let "p_ref_241" 
                                                            (make-vec (ptr-add (identifier "drec_snd_238") (size 1)))
                                                            (seq
                                                              (while
                                                                (let "leb128_242" 
                                                                  (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_241")))
                                                                  (let-pair "leb128_fst_243" "leb128_snd_244" 
                                                                    (identifier "leb128_242")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_241") (identifier "leb128_snd_244"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_239")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_243") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_240")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_239")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_240") (add (unsafe-nth (u8 0) (identifier "shft_ref_240")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_243") (u8 128))))) 
                                                                (nop)) 
                                                              (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_239")) (unsafe-nth (u8 0) (identifier "p_ref_241")))))))
                                                      (let-pair "dlist1_fst_249" "dlist1_snd_250" 
                                                        (identifier "dlist1_248")
                                                        (let "inits_src_ref_251" 
                                                          (make-vec (make-tup (end-of-list "$func_ref") (identifier "dlist1_snd_250")))
                                                          (seq
                                                            (let "repeat_n_252" 
                                                              (make-vec (i32 0))
                                                              (while 
                                                                (gt (to-i32 (identifier "dlist1_fst_249")) (unsafe-nth (u8 0) (identifier "repeat_n_252")))
                                                                (seq
                                                                  (let "dlist2_253" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_251"))
                                                                    (let-pair "dlist2_fst_254" "dlist2_snd_255" 
                                                                    (identifier "dlist2_253")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_251")
                                                                    (let-pair "dlist3_fst_257" "dlist3_snd_258" 
                                                                    (apply (ext-identifier func_ref of-row-binary) (identifier "dlist2_snd_255"))
                                                                    (make-tup (cons (identifier "dlist3_fst_257") (identifier "dlist2_fst_254")) (identifier "dlist3_snd_258"))))))
                                                                  (set-vec (u8 0) (identifier "repeat_n_252") (add (unsafe-nth (u8 0) (identifier "repeat_n_252")) (i32 1)))))) 
                                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_251")))))) 
                                                    (make-tup (not-null (arr-of-lst-rev (identifier "dlist4_fst_260"))) (identifier "dlist4_snd_261"))))
                                                (let-pair "drec_fst_266" "drec_snd_267" 
                                                  (identifier "drec_265")
                                                  (let-pair "dlist4_fst_289" "dlist4_snd_290"
                                                    (let "dlist1_277"
                                                      (let "leb_ref_268" 
                                                        (make-vec (u32 0))
                                                        (let "shft_ref_269" 
                                                          (make-vec (u8 0))
                                                          (let "p_ref_270" 
                                                            (make-vec (identifier "drec_snd_267"))
                                                            (seq
                                                              (while
                                                                (let "leb128_271" 
                                                                  (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_270")))
                                                                  (let-pair "leb128_fst_272" "leb128_snd_273" 
                                                                    (identifier "leb128_271")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_270") (identifier "leb128_snd_273"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_268")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_272") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_269")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_268")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_269") (add (unsafe-nth (u8 0) (identifier "shft_ref_269")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_272") (u8 128))))) 
                                                                (nop)) 
                                                              (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_268")) (unsafe-nth (u8 0) (identifier "p_ref_270")))))))
                                                      (let-pair "dlist1_fst_278" "dlist1_snd_279" 
                                                        (identifier "dlist1_277")
                                                        (let "inits_src_ref_280" 
                                                          (make-vec (make-tup (end-of-list "$func_ref") (identifier "dlist1_snd_279")))
                                                          (seq
                                                            (let "repeat_n_281" 
                                                              (make-vec (i32 0))
                                                              (while 
                                                                (gt (to-i32 (identifier "dlist1_fst_278")) (unsafe-nth (u8 0) (identifier "repeat_n_281")))
                                                                (seq
                                                                  (let "dlist2_282" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_280"))
                                                                    (let-pair "dlist2_fst_283" "dlist2_snd_284" 
                                                                    (identifier "dlist2_282")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_280")
                                                                    (let-pair "dlist3_fst_286" "dlist3_snd_287" 
                                                                    (apply (ext-identifier func_ref of-row-binary) (identifier "dlist2_snd_284"))
                                                                    (make-tup (cons (identifier "dlist3_fst_286") (identifier "dlist2_fst_283")) (identifier "dlist3_snd_287"))))))
                                                                  (set-vec (u8 0) (identifier "repeat_n_281") (add (unsafe-nth (u8 0) (identifier "repeat_n_281")) (i32 1)))))) 
                                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_280"))))))
                                                    (make-tup
                                                      (make-rec (string "children") 
                                                        (arr-of-lst-rev (identifier "dlist4_fst_289")) 
                                                        (string "parents") 
                                                        (identifier "drec_fst_266") 
                                                        (string "role") 
                                                        (identifier "drec_fst_237") 
                                                        (string "envvars") 
                                                        (identifier "drec_fst_169") 
                                                        (string "params") 
                                                        (identifier "drec_fst_143") 
                                                        (string "is_used") 
                                                        (identifier "drec_fst_111") 
                                                        (string "info_signature") 
                                                        (identifier "drec_fst_105") 
                                                        (string "worker_signature") 
                                                        (identifier "drec_fst_90") 
                                                        (string "cwd") 
                                                        (identifier "drec_fst_75") 
                                                        (string "report_period") 
                                                        (identifier "drec_fst_72") 
                                                        (string "debug") 
                                                        (identifier "drec_fst_66") 
                                                        (string "enabled") 
                                                        (identifier "drec_fst_60")) 
                                                      (identifier "dlist4_snd_290"))))))))))))))))))))))))))
 */
static std::function<::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576(Pointer)> fun884 { [&fun884](Pointer p_0) {
    ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_885 { p_0.readU8() };
    ::dessser::gen::worker::t4138de986e20d18b01e4c493dc9d5451 letpair_res_886;
    {
      auto dbool_fst_57 { std::get<0>(id_885) };
      auto dbool_snd_58 { std::get<1>(id_885) };
      uint8_t id_887 { 0 };
      bool id_888 { bool(dbool_fst_57 == id_887) };
      bool id_889 { ! id_888 };
      ::dessser::gen::worker::t4138de986e20d18b01e4c493dc9d5451 id_890 { id_889, dbool_snd_58 };
      letpair_res_886 = id_890;
    }
    ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_891;
    {
      ::dessser::gen::worker::t4138de986e20d18b01e4c493dc9d5451 drec_59 { letpair_res_886 };
      ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_892;
      {
        auto drec_fst_60 { std::get<0>(drec_59) };
        auto drec_snd_61 { std::get<1>(drec_59) };
        ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_893 { drec_snd_61.readU8() };
        ::dessser::gen::worker::t4138de986e20d18b01e4c493dc9d5451 letpair_res_894;
        {
          auto dbool_fst_63 { std::get<0>(id_893) };
          auto dbool_snd_64 { std::get<1>(id_893) };
          uint8_t id_895 { 0 };
          bool id_896 { bool(dbool_fst_63 == id_895) };
          bool id_897 { ! id_896 };
          ::dessser::gen::worker::t4138de986e20d18b01e4c493dc9d5451 id_898 { id_897, dbool_snd_64 };
          letpair_res_894 = id_898;
        }
        ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_899;
        {
          ::dessser::gen::worker::t4138de986e20d18b01e4c493dc9d5451 drec_65 { letpair_res_894 };
          ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_900;
          {
            auto drec_fst_66 { std::get<0>(drec_65) };
            auto drec_snd_67 { std::get<1>(drec_65) };
            ::dessser::gen::worker::t7a47220550fc5126a7b79f1e0c10c645 id_901 { drec_snd_67.readU64Le() };
            ::dessser::gen::worker::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_902;
            {
              auto dfloat_fst_69 { std::get<0>(id_901) };
              auto dfloat_snd_70 { std::get<1>(id_901) };
              double id_903 { float_of_qword(dfloat_fst_69) };
              ::dessser::gen::worker::taebed00ad7fdb3f7ced11d3cfd58aade id_904 { id_903, dfloat_snd_70 };
              letpair_res_902 = id_904;
            }
            ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_905;
            {
              ::dessser::gen::worker::taebed00ad7fdb3f7ced11d3cfd58aade drec_71 { letpair_res_902 };
              ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_906;
              {
                auto drec_fst_72 { std::get<0>(drec_71) };
                auto drec_snd_73 { std::get<1>(drec_71) };
                auto fun907 { dessser::gen::file_path::of_row_binary };
                ::dessser::gen::worker::tad3a94e851c33888b2891405a4005268 id_908 { fun907(drec_snd_73) };
                ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_909;
                {
                  ::dessser::gen::worker::tad3a94e851c33888b2891405a4005268 drec_74 { id_908 };
                  ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_910;
                  {
                    auto drec_fst_75 { std::get<0>(drec_74) };
                    auto drec_snd_76 { std::get<1>(drec_74) };
                    uint32_t id_911 { 0U };
                    Vec<1, uint32_t> id_912 {  id_911  };
                    ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c let_res_913;
                    {
                      Vec<1, uint32_t> leb_ref_77 { id_912 };
                      uint8_t id_914 { 0 };
                      Vec<1, uint8_t> id_915 {  id_914  };
                      ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c let_res_916;
                      {
                        Vec<1, uint8_t> shft_ref_78 { id_915 };
                        Vec<1, Pointer> id_917 {  drec_snd_76  };
                        ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c let_res_918;
                        {
                          Vec<1, Pointer> p_ref_79 { id_917 };
                          bool while_flag_919 { true };
                          do {
                            uint8_t id_920 { 0 };
                            Pointer id_921 { p_ref_79[id_920] };
                            ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_922 { id_921.readU8() };
                            bool let_res_923;
                            {
                              ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 leb128_80 { id_922 };
                              bool letpair_res_924;
                              {
                                auto leb128_fst_81 { std::get<0>(leb128_80) };
                                auto leb128_snd_82 { std::get<1>(leb128_80) };
                                uint8_t id_925 { 0 };
                                Void id_926 { ((void)(p_ref_79[id_925] = leb128_snd_82), VOID) };
                                (void)id_926;
                                uint8_t id_927 { 0 };
                                uint8_t id_928 { 127 };
                                uint8_t id_929 { uint8_t(leb128_fst_81 & id_928) };
                                uint32_t id_930 { uint32_t(id_929) };
                                uint8_t id_931 { 0 };
                                uint8_t id_932 { shft_ref_78[id_931] };
                                uint32_t id_933 { uint32_t(id_930 << id_932) };
                                uint8_t id_934 { 0 };
                                uint32_t id_935 { leb_ref_77[id_934] };
                                uint32_t id_936 { uint32_t(id_933 | id_935) };
                                Void id_937 { ((void)(leb_ref_77[id_927] = id_936), VOID) };
                                (void)id_937;
                                uint8_t id_938 { 0 };
                                uint8_t id_939 { 0 };
                                uint8_t id_940 { shft_ref_78[id_939] };
                                uint8_t id_941 { 7 };
                                uint8_t id_942 { uint8_t(id_940 + id_941) };
                                Void id_943 { ((void)(shft_ref_78[id_938] = id_942), VOID) };
                                (void)id_943;
                                uint8_t id_944 { 128 };
                                bool id_945 { bool(leb128_fst_81 >= id_944) };
                                letpair_res_924 = id_945;
                              }
                              let_res_923 = letpair_res_924;
                            }
                            while_flag_919 = let_res_923;
                            if (while_flag_919) {
                              (void)VOID;
                            }
                          } while (while_flag_919);
                          (void)VOID;
                          uint8_t id_946 { 0 };
                          uint32_t id_947 { leb_ref_77[id_946] };
                          Size id_948 { Size(id_947) };
                          uint8_t id_949 { 0 };
                          Pointer id_950 { p_ref_79[id_949] };
                          ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c id_951 { id_948, id_950 };
                          let_res_918 = id_951;
                        }
                        let_res_916 = let_res_918;
                      }
                      let_res_913 = let_res_916;
                    }
                    ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e let_res_952;
                    {
                      ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c dstring1_83 { let_res_913 };
                      ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e letpair_res_953;
                      {
                        auto dstring1_fst_84 { std::get<0>(dstring1_83) };
                        auto dstring1_snd_85 { std::get<1>(dstring1_83) };
                        ::dessser::gen::worker::t188345aa49abd0cb47ff73fedc219f08 id_954 { dstring1_snd_85.readBytes(dstring1_fst_84) };
                        ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e letpair_res_955;
                        {
                          auto dstring2_fst_87 { std::get<0>(id_954) };
                          auto dstring2_snd_88 { std::get<1>(id_954) };
                          std::string id_956 { dstring2_fst_87.toString() };
                          ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e id_957 { id_956, dstring2_snd_88 };
                          letpair_res_955 = id_957;
                        }
                        letpair_res_953 = letpair_res_955;
                      }
                      let_res_952 = letpair_res_953;
                    }
                    ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_958;
                    {
                      ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e drec_89 { let_res_952 };
                      ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_959;
                      {
                        auto drec_fst_90 { std::get<0>(drec_89) };
                        auto drec_snd_91 { std::get<1>(drec_89) };
                        uint32_t id_960 { 0U };
                        Vec<1, uint32_t> id_961 {  id_960  };
                        ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c let_res_962;
                        {
                          Vec<1, uint32_t> leb_ref_92 { id_961 };
                          uint8_t id_963 { 0 };
                          Vec<1, uint8_t> id_964 {  id_963  };
                          ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c let_res_965;
                          {
                            Vec<1, uint8_t> shft_ref_93 { id_964 };
                            Vec<1, Pointer> id_966 {  drec_snd_91  };
                            ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c let_res_967;
                            {
                              Vec<1, Pointer> p_ref_94 { id_966 };
                              bool while_flag_968 { true };
                              do {
                                uint8_t id_969 { 0 };
                                Pointer id_970 { p_ref_94[id_969] };
                                ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_971 { id_970.readU8() };
                                bool let_res_972;
                                {
                                  ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 leb128_95 { id_971 };
                                  bool letpair_res_973;
                                  {
                                    auto leb128_fst_96 { std::get<0>(leb128_95) };
                                    auto leb128_snd_97 { std::get<1>(leb128_95) };
                                    uint8_t id_974 { 0 };
                                    Void id_975 { ((void)(p_ref_94[id_974] = leb128_snd_97), VOID) };
                                    (void)id_975;
                                    uint8_t id_976 { 0 };
                                    uint8_t id_977 { 127 };
                                    uint8_t id_978 { uint8_t(leb128_fst_96 & id_977) };
                                    uint32_t id_979 { uint32_t(id_978) };
                                    uint8_t id_980 { 0 };
                                    uint8_t id_981 { shft_ref_93[id_980] };
                                    uint32_t id_982 { uint32_t(id_979 << id_981) };
                                    uint8_t id_983 { 0 };
                                    uint32_t id_984 { leb_ref_92[id_983] };
                                    uint32_t id_985 { uint32_t(id_982 | id_984) };
                                    Void id_986 { ((void)(leb_ref_92[id_976] = id_985), VOID) };
                                    (void)id_986;
                                    uint8_t id_987 { 0 };
                                    uint8_t id_988 { 0 };
                                    uint8_t id_989 { shft_ref_93[id_988] };
                                    uint8_t id_990 { 7 };
                                    uint8_t id_991 { uint8_t(id_989 + id_990) };
                                    Void id_992 { ((void)(shft_ref_93[id_987] = id_991), VOID) };
                                    (void)id_992;
                                    uint8_t id_993 { 128 };
                                    bool id_994 { bool(leb128_fst_96 >= id_993) };
                                    letpair_res_973 = id_994;
                                  }
                                  let_res_972 = letpair_res_973;
                                }
                                while_flag_968 = let_res_972;
                                if (while_flag_968) {
                                  (void)VOID;
                                }
                              } while (while_flag_968);
                              (void)VOID;
                              uint8_t id_995 { 0 };
                              uint32_t id_996 { leb_ref_92[id_995] };
                              Size id_997 { Size(id_996) };
                              uint8_t id_998 { 0 };
                              Pointer id_999 { p_ref_94[id_998] };
                              ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c id_1000 { id_997, id_999 };
                              let_res_967 = id_1000;
                            }
                            let_res_965 = let_res_967;
                          }
                          let_res_962 = let_res_965;
                        }
                        ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e let_res_1001;
                        {
                          ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c dstring1_98 { let_res_962 };
                          ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1002;
                          {
                            auto dstring1_fst_99 { std::get<0>(dstring1_98) };
                            auto dstring1_snd_100 { std::get<1>(dstring1_98) };
                            ::dessser::gen::worker::t188345aa49abd0cb47ff73fedc219f08 id_1003 { dstring1_snd_100.readBytes(dstring1_fst_99) };
                            ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1004;
                            {
                              auto dstring2_fst_102 { std::get<0>(id_1003) };
                              auto dstring2_snd_103 { std::get<1>(id_1003) };
                              std::string id_1005 { dstring2_fst_102.toString() };
                              ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e id_1006 { id_1005, dstring2_snd_103 };
                              letpair_res_1004 = id_1006;
                            }
                            letpair_res_1002 = letpair_res_1004;
                          }
                          let_res_1001 = letpair_res_1002;
                        }
                        ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_1007;
                        {
                          ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e drec_104 { let_res_1001 };
                          ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_1008;
                          {
                            auto drec_fst_105 { std::get<0>(drec_104) };
                            auto drec_snd_106 { std::get<1>(drec_104) };
                            ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_1009 { drec_snd_106.readU8() };
                            ::dessser::gen::worker::t4138de986e20d18b01e4c493dc9d5451 letpair_res_1010;
                            {
                              auto dbool_fst_108 { std::get<0>(id_1009) };
                              auto dbool_snd_109 { std::get<1>(id_1009) };
                              uint8_t id_1011 { 0 };
                              bool id_1012 { bool(dbool_fst_108 == id_1011) };
                              bool id_1013 { ! id_1012 };
                              ::dessser::gen::worker::t4138de986e20d18b01e4c493dc9d5451 id_1014 { id_1013, dbool_snd_109 };
                              letpair_res_1010 = id_1014;
                            }
                            ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_1015;
                            {
                              ::dessser::gen::worker::t4138de986e20d18b01e4c493dc9d5451 drec_110 { letpair_res_1010 };
                              ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_1016;
                              {
                                auto drec_fst_111 { std::get<0>(drec_110) };
                                auto drec_snd_112 { std::get<1>(drec_110) };
                                uint32_t id_1017 { 0U };
                                Vec<1, uint32_t> id_1018 {  id_1017  };
                                ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1019;
                                {
                                  Vec<1, uint32_t> leb_ref_113 { id_1018 };
                                  uint8_t id_1020 { 0 };
                                  Vec<1, uint8_t> id_1021 {  id_1020  };
                                  ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1022;
                                  {
                                    Vec<1, uint8_t> shft_ref_114 { id_1021 };
                                    Vec<1, Pointer> id_1023 {  drec_snd_112  };
                                    ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1024;
                                    {
                                      Vec<1, Pointer> p_ref_115 { id_1023 };
                                      bool while_flag_1025 { true };
                                      do {
                                        uint8_t id_1026 { 0 };
                                        Pointer id_1027 { p_ref_115[id_1026] };
                                        ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_1028 { id_1027.readU8() };
                                        bool let_res_1029;
                                        {
                                          ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 leb128_116 { id_1028 };
                                          bool letpair_res_1030;
                                          {
                                            auto leb128_fst_117 { std::get<0>(leb128_116) };
                                            auto leb128_snd_118 { std::get<1>(leb128_116) };
                                            uint8_t id_1031 { 0 };
                                            Void id_1032 { ((void)(p_ref_115[id_1031] = leb128_snd_118), VOID) };
                                            (void)id_1032;
                                            uint8_t id_1033 { 0 };
                                            uint8_t id_1034 { 127 };
                                            uint8_t id_1035 { uint8_t(leb128_fst_117 & id_1034) };
                                            uint32_t id_1036 { uint32_t(id_1035) };
                                            uint8_t id_1037 { 0 };
                                            uint8_t id_1038 { shft_ref_114[id_1037] };
                                            uint32_t id_1039 { uint32_t(id_1036 << id_1038) };
                                            uint8_t id_1040 { 0 };
                                            uint32_t id_1041 { leb_ref_113[id_1040] };
                                            uint32_t id_1042 { uint32_t(id_1039 | id_1041) };
                                            Void id_1043 { ((void)(leb_ref_113[id_1033] = id_1042), VOID) };
                                            (void)id_1043;
                                            uint8_t id_1044 { 0 };
                                            uint8_t id_1045 { 0 };
                                            uint8_t id_1046 { shft_ref_114[id_1045] };
                                            uint8_t id_1047 { 7 };
                                            uint8_t id_1048 { uint8_t(id_1046 + id_1047) };
                                            Void id_1049 { ((void)(shft_ref_114[id_1044] = id_1048), VOID) };
                                            (void)id_1049;
                                            uint8_t id_1050 { 128 };
                                            bool id_1051 { bool(leb128_fst_117 >= id_1050) };
                                            letpair_res_1030 = id_1051;
                                          }
                                          let_res_1029 = letpair_res_1030;
                                        }
                                        while_flag_1025 = let_res_1029;
                                        if (while_flag_1025) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_1025);
                                      (void)VOID;
                                      uint8_t id_1052 { 0 };
                                      uint32_t id_1053 { leb_ref_113[id_1052] };
                                      uint8_t id_1054 { 0 };
                                      Pointer id_1055 { p_ref_115[id_1054] };
                                      ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 id_1056 { id_1053, id_1055 };
                                      let_res_1024 = id_1056;
                                    }
                                    let_res_1022 = let_res_1024;
                                  }
                                  let_res_1019 = let_res_1022;
                                }
                                ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 let_res_1057;
                                {
                                  ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 dlist1_122 { let_res_1019 };
                                  ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 letpair_res_1058;
                                  {
                                    auto dlist1_fst_123 { std::get<0>(dlist1_122) };
                                    auto dlist1_snd_124 { std::get<1>(dlist1_122) };
                                    Lst<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> endoflist_1059;
                                    ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 id_1060 { endoflist_1059, dlist1_snd_124 };
                                    Vec<1, ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3> id_1061 {  id_1060  };
                                    ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 let_res_1062;
                                    {
                                      Vec<1, ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3> inits_src_ref_125 { id_1061 };
                                      int32_t id_1063 { 0L };
                                      Vec<1, int32_t> id_1064 {  id_1063  };
                                      {
                                        Vec<1, int32_t> repeat_n_126 { id_1064 };
                                        bool while_flag_1065 { true };
                                        do {
                                          int32_t id_1066 { int32_t(dlist1_fst_123) };
                                          uint8_t id_1067 { 0 };
                                          int32_t id_1068 { repeat_n_126[id_1067] };
                                          bool id_1069 { bool(id_1066 > id_1068) };
                                          while_flag_1065 = id_1069;
                                          if (while_flag_1065) {
                                            uint8_t id_1070 { 0 };
                                            ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 id_1071 { inits_src_ref_125[id_1070] };
                                            {
                                              ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 dlist2_127 { id_1071 };
                                              {
                                                auto dlist2_fst_128 { std::get<0>(dlist2_127) };
                                                auto dlist2_snd_129 { std::get<1>(dlist2_127) };
                                                uint8_t id_1072 { 0 };
                                                auto fun1073 { dessser::gen::field_name::of_row_binary };
                                                ::dessser::gen::worker::t273a2b7978f5b466a128a51c1cc4a27b id_1074 { fun1073(dlist2_snd_129) };
                                                ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 let_res_1075;
                                                {
                                                  ::dessser::gen::worker::t273a2b7978f5b466a128a51c1cc4a27b dtup_130 { id_1074 };
                                                  ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 letpair_res_1076;
                                                  {
                                                    auto dtup_fst_131 { std::get<0>(dtup_130) };
                                                    auto dtup_snd_132 { std::get<1>(dtup_130) };
                                                    auto fun1077 { dessser::gen::raql_value::of_row_binary };
                                                    ::dessser::gen::worker::t9cfa78b25ddcb5afc14daf6a802a6f88 id_1078 { fun1077(dtup_snd_132) };
                                                    ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 letpair_res_1079;
                                                    {
                                                      auto dtup_fst_134 { std::get<0>(id_1078) };
                                                      auto dtup_snd_135 { std::get<1>(id_1078) };
                                                      ::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374 id_1080 { dtup_fst_131, dtup_fst_134 };
                                                      Lst<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> id_1081 { id_1080, dlist2_fst_128 };
                                                      ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 id_1082 { id_1081, dtup_snd_135 };
                                                      letpair_res_1079 = id_1082;
                                                    }
                                                    letpair_res_1076 = letpair_res_1079;
                                                  }
                                                  let_res_1075 = letpair_res_1076;
                                                }
                                                Void id_1083 { ((void)(inits_src_ref_125[id_1072] = let_res_1075), VOID) };
                                                (void)id_1083;
                                              }
                                              (void)VOID;
                                            }
                                            (void)VOID;
                                            uint8_t id_1084 { 0 };
                                            uint8_t id_1085 { 0 };
                                            int32_t id_1086 { repeat_n_126[id_1085] };
                                            int32_t id_1087 { 1L };
                                            int32_t id_1088 { int32_t(id_1086 + id_1087) };
                                            Void id_1089 { ((void)(repeat_n_126[id_1084] = id_1088), VOID) };
                                            (void)id_1089;
                                            (void)id_1089;
                                          }
                                        } while (while_flag_1065);
                                        (void)VOID;
                                      }
                                      (void)VOID;
                                      uint8_t id_1090 { 0 };
                                      ::dessser::gen::worker::tb5750eb88c0584267bbc885971316ec3 id_1091 { inits_src_ref_125[id_1090] };
                                      let_res_1062 = id_1091;
                                    }
                                    letpair_res_1058 = let_res_1062;
                                  }
                                  let_res_1057 = letpair_res_1058;
                                }
                                ::dessser::gen::worker::t7b35b1065b089e850816816e188ccf6c letpair_res_1092;
                                {
                                  auto dlist4_fst_140 { std::get<0>(let_res_1057) };
                                  auto dlist4_snd_141 { std::get<1>(let_res_1057) };
                                  Arr<::dessser::gen::worker::t83d220ac6cd554303ec130a90b325374> id_1093 { dlist4_fst_140.toListRev() };
                                  ::dessser::gen::worker::t7b35b1065b089e850816816e188ccf6c id_1094 { id_1093, dlist4_snd_141 };
                                  letpair_res_1092 = id_1094;
                                }
                                ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_1095;
                                {
                                  ::dessser::gen::worker::t7b35b1065b089e850816816e188ccf6c drec_142 { letpair_res_1092 };
                                  ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_1096;
                                  {
                                    auto drec_fst_143 { std::get<0>(drec_142) };
                                    auto drec_snd_144 { std::get<1>(drec_142) };
                                    uint32_t id_1097 { 0U };
                                    Vec<1, uint32_t> id_1098 {  id_1097  };
                                    ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1099;
                                    {
                                      Vec<1, uint32_t> leb_ref_145 { id_1098 };
                                      uint8_t id_1100 { 0 };
                                      Vec<1, uint8_t> id_1101 {  id_1100  };
                                      ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1102;
                                      {
                                        Vec<1, uint8_t> shft_ref_146 { id_1101 };
                                        Vec<1, Pointer> id_1103 {  drec_snd_144  };
                                        ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1104;
                                        {
                                          Vec<1, Pointer> p_ref_147 { id_1103 };
                                          bool while_flag_1105 { true };
                                          do {
                                            uint8_t id_1106 { 0 };
                                            Pointer id_1107 { p_ref_147[id_1106] };
                                            ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_1108 { id_1107.readU8() };
                                            bool let_res_1109;
                                            {
                                              ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 leb128_148 { id_1108 };
                                              bool letpair_res_1110;
                                              {
                                                auto leb128_fst_149 { std::get<0>(leb128_148) };
                                                auto leb128_snd_150 { std::get<1>(leb128_148) };
                                                uint8_t id_1111 { 0 };
                                                Void id_1112 { ((void)(p_ref_147[id_1111] = leb128_snd_150), VOID) };
                                                (void)id_1112;
                                                uint8_t id_1113 { 0 };
                                                uint8_t id_1114 { 127 };
                                                uint8_t id_1115 { uint8_t(leb128_fst_149 & id_1114) };
                                                uint32_t id_1116 { uint32_t(id_1115) };
                                                uint8_t id_1117 { 0 };
                                                uint8_t id_1118 { shft_ref_146[id_1117] };
                                                uint32_t id_1119 { uint32_t(id_1116 << id_1118) };
                                                uint8_t id_1120 { 0 };
                                                uint32_t id_1121 { leb_ref_145[id_1120] };
                                                uint32_t id_1122 { uint32_t(id_1119 | id_1121) };
                                                Void id_1123 { ((void)(leb_ref_145[id_1113] = id_1122), VOID) };
                                                (void)id_1123;
                                                uint8_t id_1124 { 0 };
                                                uint8_t id_1125 { 0 };
                                                uint8_t id_1126 { shft_ref_146[id_1125] };
                                                uint8_t id_1127 { 7 };
                                                uint8_t id_1128 { uint8_t(id_1126 + id_1127) };
                                                Void id_1129 { ((void)(shft_ref_146[id_1124] = id_1128), VOID) };
                                                (void)id_1129;
                                                uint8_t id_1130 { 128 };
                                                bool id_1131 { bool(leb128_fst_149 >= id_1130) };
                                                letpair_res_1110 = id_1131;
                                              }
                                              let_res_1109 = letpair_res_1110;
                                            }
                                            while_flag_1105 = let_res_1109;
                                            if (while_flag_1105) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_1105);
                                          (void)VOID;
                                          uint8_t id_1132 { 0 };
                                          uint32_t id_1133 { leb_ref_145[id_1132] };
                                          uint8_t id_1134 { 0 };
                                          Pointer id_1135 { p_ref_147[id_1134] };
                                          ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 id_1136 { id_1133, id_1135 };
                                          let_res_1104 = id_1136;
                                        }
                                        let_res_1102 = let_res_1104;
                                      }
                                      let_res_1099 = let_res_1102;
                                    }
                                    ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967 let_res_1137;
                                    {
                                      ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 dlist1_154 { let_res_1099 };
                                      ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967 letpair_res_1138;
                                      {
                                        auto dlist1_fst_155 { std::get<0>(dlist1_154) };
                                        auto dlist1_snd_156 { std::get<1>(dlist1_154) };
                                        Lst<dessser::gen::field_name::t_ext> endoflist_1139;
                                        ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967 id_1140 { endoflist_1139, dlist1_snd_156 };
                                        Vec<1, ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967> id_1141 {  id_1140  };
                                        ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967 let_res_1142;
                                        {
                                          Vec<1, ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967> inits_src_ref_157 { id_1141 };
                                          int32_t id_1143 { 0L };
                                          Vec<1, int32_t> id_1144 {  id_1143  };
                                          {
                                            Vec<1, int32_t> repeat_n_158 { id_1144 };
                                            bool while_flag_1145 { true };
                                            do {
                                              int32_t id_1146 { int32_t(dlist1_fst_155) };
                                              uint8_t id_1147 { 0 };
                                              int32_t id_1148 { repeat_n_158[id_1147] };
                                              bool id_1149 { bool(id_1146 > id_1148) };
                                              while_flag_1145 = id_1149;
                                              if (while_flag_1145) {
                                                uint8_t id_1150 { 0 };
                                                ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967 id_1151 { inits_src_ref_157[id_1150] };
                                                {
                                                  ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967 dlist2_159 { id_1151 };
                                                  {
                                                    auto dlist2_fst_160 { std::get<0>(dlist2_159) };
                                                    auto dlist2_snd_161 { std::get<1>(dlist2_159) };
                                                    uint8_t id_1152 { 0 };
                                                    auto fun1153 { dessser::gen::field_name::of_row_binary };
                                                    ::dessser::gen::worker::t273a2b7978f5b466a128a51c1cc4a27b id_1154 { fun1153(dlist2_snd_161) };
                                                    ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967 letpair_res_1155;
                                                    {
                                                      auto dlist3_fst_163 { std::get<0>(id_1154) };
                                                      auto dlist3_snd_164 { std::get<1>(id_1154) };
                                                      Lst<dessser::gen::field_name::t_ext> id_1156 { dlist3_fst_163, dlist2_fst_160 };
                                                      ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967 id_1157 { id_1156, dlist3_snd_164 };
                                                      letpair_res_1155 = id_1157;
                                                    }
                                                    Void id_1158 { ((void)(inits_src_ref_157[id_1152] = letpair_res_1155), VOID) };
                                                    (void)id_1158;
                                                  }
                                                  (void)VOID;
                                                }
                                                (void)VOID;
                                                uint8_t id_1159 { 0 };
                                                uint8_t id_1160 { 0 };
                                                int32_t id_1161 { repeat_n_158[id_1160] };
                                                int32_t id_1162 { 1L };
                                                int32_t id_1163 { int32_t(id_1161 + id_1162) };
                                                Void id_1164 { ((void)(repeat_n_158[id_1159] = id_1163), VOID) };
                                                (void)id_1164;
                                                (void)id_1164;
                                              }
                                            } while (while_flag_1145);
                                            (void)VOID;
                                          }
                                          (void)VOID;
                                          uint8_t id_1165 { 0 };
                                          ::dessser::gen::worker::t0dfa866705b76efff53e4aa97228a967 id_1166 { inits_src_ref_157[id_1165] };
                                          let_res_1142 = id_1166;
                                        }
                                        letpair_res_1138 = let_res_1142;
                                      }
                                      let_res_1137 = letpair_res_1138;
                                    }
                                    ::dessser::gen::worker::t516a13ee5da1d64d6b901ea5754eb1bb letpair_res_1167;
                                    {
                                      auto dlist4_fst_166 { std::get<0>(let_res_1137) };
                                      auto dlist4_snd_167 { std::get<1>(let_res_1137) };
                                      Arr<dessser::gen::field_name::t_ext> id_1168 { dlist4_fst_166.toListRev() };
                                      ::dessser::gen::worker::t516a13ee5da1d64d6b901ea5754eb1bb id_1169 { id_1168, dlist4_snd_167 };
                                      letpair_res_1167 = id_1169;
                                    }
                                    ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_1170;
                                    {
                                      ::dessser::gen::worker::t516a13ee5da1d64d6b901ea5754eb1bb drec_168 { letpair_res_1167 };
                                      ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_1171;
                                      {
                                        auto drec_fst_169 { std::get<0>(drec_168) };
                                        auto drec_snd_170 { std::get<1>(drec_168) };
                                        ::dessser::gen::worker::t22a32080ad88ab548b80077a17b7dd46 id_1172 { drec_snd_170.readU16Le() };
                                        ::dessser::gen::worker::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1173;
                                        {
                                          auto du16_fst_172 { std::get<0>(id_1172) };
                                          auto du16_snd_173 { std::get<1>(id_1172) };
                                          ::dessser::gen::worker::t22a32080ad88ab548b80077a17b7dd46 id_1174 { du16_fst_172, du16_snd_173 };
                                          letpair_res_1173 = id_1174;
                                        }
                                        ::dessser::gen::worker::tca2b2091d7f296d1f80d11eb663f798d let_res_1175;
                                        {
                                          ::dessser::gen::worker::t22a32080ad88ab548b80077a17b7dd46 dsum1_177 { letpair_res_1173 };
                                          ::dessser::gen::worker::tca2b2091d7f296d1f80d11eb663f798d letpair_res_1176;
                                          {
                                            auto dsum1_fst_178 { std::get<0>(dsum1_177) };
                                            auto dsum1_snd_179 { std::get<1>(dsum1_177) };
                                            uint16_t id_1177 { 0 };
                                            bool id_1178 { bool(id_1177 == dsum1_fst_178) };
                                            ::dessser::gen::worker::tca2b2091d7f296d1f80d11eb663f798d choose_res_1179;
                                            if (id_1178) {
                                              (void)VOID;
                                              ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_1180 { std::in_place_index<0>, VOID };
                                              ::dessser::gen::worker::tca2b2091d7f296d1f80d11eb663f798d id_1181 { id_1180, dsum1_snd_179 };
                                              choose_res_1179 = id_1181;
                                            } else {
                                              uint16_t id_1182 { 1 };
                                              bool id_1183 { bool(dsum1_fst_178 == id_1182) };
                                              Void id_1184 { ((void)(assert(id_1183)), VOID) };
                                              (void)id_1184;
                                              uint32_t id_1185 { 0U };
                                              Vec<1, uint32_t> id_1186 {  id_1185  };
                                              ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1187;
                                              {
                                                Vec<1, uint32_t> leb_ref_180 { id_1186 };
                                                uint8_t id_1188 { 0 };
                                                Vec<1, uint8_t> id_1189 {  id_1188  };
                                                ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1190;
                                                {
                                                  Vec<1, uint8_t> shft_ref_181 { id_1189 };
                                                  Vec<1, Pointer> id_1191 {  dsum1_snd_179  };
                                                  ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1192;
                                                  {
                                                    Vec<1, Pointer> p_ref_182 { id_1191 };
                                                    bool while_flag_1193 { true };
                                                    do {
                                                      uint8_t id_1194 { 0 };
                                                      Pointer id_1195 { p_ref_182[id_1194] };
                                                      ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_1196 { id_1195.readU8() };
                                                      bool let_res_1197;
                                                      {
                                                        ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 leb128_183 { id_1196 };
                                                        bool letpair_res_1198;
                                                        {
                                                          auto leb128_fst_184 { std::get<0>(leb128_183) };
                                                          auto leb128_snd_185 { std::get<1>(leb128_183) };
                                                          uint8_t id_1199 { 0 };
                                                          Void id_1200 { ((void)(p_ref_182[id_1199] = leb128_snd_185), VOID) };
                                                          (void)id_1200;
                                                          uint8_t id_1201 { 0 };
                                                          uint8_t id_1202 { 127 };
                                                          uint8_t id_1203 { uint8_t(leb128_fst_184 & id_1202) };
                                                          uint32_t id_1204 { uint32_t(id_1203) };
                                                          uint8_t id_1205 { 0 };
                                                          uint8_t id_1206 { shft_ref_181[id_1205] };
                                                          uint32_t id_1207 { uint32_t(id_1204 << id_1206) };
                                                          uint8_t id_1208 { 0 };
                                                          uint32_t id_1209 { leb_ref_180[id_1208] };
                                                          uint32_t id_1210 { uint32_t(id_1207 | id_1209) };
                                                          Void id_1211 { ((void)(leb_ref_180[id_1201] = id_1210), VOID) };
                                                          (void)id_1211;
                                                          uint8_t id_1212 { 0 };
                                                          uint8_t id_1213 { 0 };
                                                          uint8_t id_1214 { shft_ref_181[id_1213] };
                                                          uint8_t id_1215 { 7 };
                                                          uint8_t id_1216 { uint8_t(id_1214 + id_1215) };
                                                          Void id_1217 { ((void)(shft_ref_181[id_1212] = id_1216), VOID) };
                                                          (void)id_1217;
                                                          uint8_t id_1218 { 128 };
                                                          bool id_1219 { bool(leb128_fst_184 >= id_1218) };
                                                          letpair_res_1198 = id_1219;
                                                        }
                                                        let_res_1197 = letpair_res_1198;
                                                      }
                                                      while_flag_1193 = let_res_1197;
                                                      if (while_flag_1193) {
                                                        (void)VOID;
                                                      }
                                                    } while (while_flag_1193);
                                                    (void)VOID;
                                                    uint8_t id_1220 { 0 };
                                                    uint32_t id_1221 { leb_ref_180[id_1220] };
                                                    uint8_t id_1222 { 0 };
                                                    Pointer id_1223 { p_ref_182[id_1222] };
                                                    ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 id_1224 { id_1221, id_1223 };
                                                    let_res_1192 = id_1224;
                                                  }
                                                  let_res_1190 = let_res_1192;
                                                }
                                                let_res_1187 = let_res_1190;
                                              }
                                              ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd let_res_1225;
                                              {
                                                ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 dlist1_189 { let_res_1187 };
                                                ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd letpair_res_1226;
                                                {
                                                  auto dlist1_fst_190 { std::get<0>(dlist1_189) };
                                                  auto dlist1_snd_191 { std::get<1>(dlist1_189) };
                                                  Lst<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5> endoflist_1227;
                                                  ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd id_1228 { endoflist_1227, dlist1_snd_191 };
                                                  Vec<1, ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd> id_1229 {  id_1228  };
                                                  ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd let_res_1230;
                                                  {
                                                    Vec<1, ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd> inits_src_ref_192 { id_1229 };
                                                    int32_t id_1231 { 0L };
                                                    Vec<1, int32_t> id_1232 {  id_1231  };
                                                    {
                                                      Vec<1, int32_t> repeat_n_193 { id_1232 };
                                                      bool while_flag_1233 { true };
                                                      do {
                                                        int32_t id_1234 { int32_t(dlist1_fst_190) };
                                                        uint8_t id_1235 { 0 };
                                                        int32_t id_1236 { repeat_n_193[id_1235] };
                                                        bool id_1237 { bool(id_1234 > id_1236) };
                                                        while_flag_1233 = id_1237;
                                                        if (while_flag_1233) {
                                                          uint8_t id_1238 { 0 };
                                                          ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd id_1239 { inits_src_ref_192[id_1238] };
                                                          {
                                                            ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd dlist2_194 { id_1239 };
                                                            {
                                                              auto dlist2_fst_195 { std::get<0>(dlist2_194) };
                                                              auto dlist2_snd_196 { std::get<1>(dlist2_194) };
                                                              uint8_t id_1240 { 0 };
                                                              uint32_t id_1241 { 0U };
                                                              Vec<1, uint32_t> id_1242 {  id_1241  };
                                                              ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c let_res_1243;
                                                              {
                                                                Vec<1, uint32_t> leb_ref_197 { id_1242 };
                                                                uint8_t id_1244 { 0 };
                                                                Vec<1, uint8_t> id_1245 {  id_1244  };
                                                                ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c let_res_1246;
                                                                {
                                                                  Vec<1, uint8_t> shft_ref_198 { id_1245 };
                                                                  Vec<1, Pointer> id_1247 {  dlist2_snd_196  };
                                                                  ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c let_res_1248;
                                                                  {
                                                                    Vec<1, Pointer> p_ref_199 { id_1247 };
                                                                    bool while_flag_1249 { true };
                                                                    do {
                                                                      uint8_t id_1250 { 0 };
                                                                      Pointer id_1251 { p_ref_199[id_1250] };
                                                                      ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_1252 { id_1251.readU8() };
                                                                      bool let_res_1253;
                                                                      {
                                                                        ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 leb128_200 { id_1252 };
                                                                        bool letpair_res_1254;
                                                                        {
                                                                          auto leb128_fst_201 { std::get<0>(leb128_200) };
                                                                          auto leb128_snd_202 { std::get<1>(leb128_200) };
                                                                          uint8_t id_1255 { 0 };
                                                                          Void id_1256 { ((void)(p_ref_199[id_1255] = leb128_snd_202), VOID) };
                                                                          (void)id_1256;
                                                                          uint8_t id_1257 { 0 };
                                                                          uint8_t id_1258 { 127 };
                                                                          uint8_t id_1259 { uint8_t(leb128_fst_201 & id_1258) };
                                                                          uint32_t id_1260 { uint32_t(id_1259) };
                                                                          uint8_t id_1261 { 0 };
                                                                          uint8_t id_1262 { shft_ref_198[id_1261] };
                                                                          uint32_t id_1263 { uint32_t(id_1260 << id_1262) };
                                                                          uint8_t id_1264 { 0 };
                                                                          uint32_t id_1265 { leb_ref_197[id_1264] };
                                                                          uint32_t id_1266 { uint32_t(id_1263 | id_1265) };
                                                                          Void id_1267 { ((void)(leb_ref_197[id_1257] = id_1266), VOID) };
                                                                          (void)id_1267;
                                                                          uint8_t id_1268 { 0 };
                                                                          uint8_t id_1269 { 0 };
                                                                          uint8_t id_1270 { shft_ref_198[id_1269] };
                                                                          uint8_t id_1271 { 7 };
                                                                          uint8_t id_1272 { uint8_t(id_1270 + id_1271) };
                                                                          Void id_1273 { ((void)(shft_ref_198[id_1268] = id_1272), VOID) };
                                                                          (void)id_1273;
                                                                          uint8_t id_1274 { 128 };
                                                                          bool id_1275 { bool(leb128_fst_201 >= id_1274) };
                                                                          letpair_res_1254 = id_1275;
                                                                        }
                                                                        let_res_1253 = letpair_res_1254;
                                                                      }
                                                                      while_flag_1249 = let_res_1253;
                                                                      if (while_flag_1249) {
                                                                        (void)VOID;
                                                                      }
                                                                    } while (while_flag_1249);
                                                                    (void)VOID;
                                                                    uint8_t id_1276 { 0 };
                                                                    uint32_t id_1277 { leb_ref_197[id_1276] };
                                                                    Size id_1278 { Size(id_1277) };
                                                                    uint8_t id_1279 { 0 };
                                                                    Pointer id_1280 { p_ref_199[id_1279] };
                                                                    ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c id_1281 { id_1278, id_1280 };
                                                                    let_res_1248 = id_1281;
                                                                  }
                                                                  let_res_1246 = let_res_1248;
                                                                }
                                                                let_res_1243 = let_res_1246;
                                                              }
                                                              ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e let_res_1282;
                                                              {
                                                                ::dessser::gen::worker::t8beb80162423aee37bd383e9b6834c9c dstring1_203 { let_res_1243 };
                                                                ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1283;
                                                                {
                                                                  auto dstring1_fst_204 { std::get<0>(dstring1_203) };
                                                                  auto dstring1_snd_205 { std::get<1>(dstring1_203) };
                                                                  ::dessser::gen::worker::t188345aa49abd0cb47ff73fedc219f08 id_1284 { dstring1_snd_205.readBytes(dstring1_fst_204) };
                                                                  ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1285;
                                                                  {
                                                                    auto dstring2_fst_207 { std::get<0>(id_1284) };
                                                                    auto dstring2_snd_208 { std::get<1>(id_1284) };
                                                                    std::string id_1286 { dstring2_fst_207.toString() };
                                                                    ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e id_1287 { id_1286, dstring2_snd_208 };
                                                                    letpair_res_1285 = id_1287;
                                                                  }
                                                                  letpair_res_1283 = letpair_res_1285;
                                                                }
                                                                let_res_1282 = letpair_res_1283;
                                                              }
                                                              ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd let_res_1288;
                                                              {
                                                                ::dessser::gen::worker::tef94b55d8809251f13165d9a05bd9d0e drec_209 { let_res_1282 };
                                                                ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd letpair_res_1289;
                                                                {
                                                                  auto drec_fst_210 { std::get<0>(drec_209) };
                                                                  auto drec_snd_211 { std::get<1>(drec_209) };
                                                                  ::dessser::gen::worker::t22a32080ad88ab548b80077a17b7dd46 id_1290 { drec_snd_211.readU16Le() };
                                                                  ::dessser::gen::worker::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1291;
                                                                  {
                                                                    auto du16_fst_213 { std::get<0>(id_1290) };
                                                                    auto du16_snd_214 { std::get<1>(id_1290) };
                                                                    ::dessser::gen::worker::t22a32080ad88ab548b80077a17b7dd46 id_1292 { du16_fst_213, du16_snd_214 };
                                                                    letpair_res_1291 = id_1292;
                                                                  }
                                                                  ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd let_res_1293;
                                                                  {
                                                                    ::dessser::gen::worker::t22a32080ad88ab548b80077a17b7dd46 drec_215 { letpair_res_1291 };
                                                                    ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd letpair_res_1294;
                                                                    {
                                                                      auto drec_fst_216 { std::get<0>(drec_215) };
                                                                      auto drec_snd_217 { std::get<1>(drec_215) };
                                                                      ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 id_1295 { drec_snd_217.readU32Le() };
                                                                      ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd letpair_res_1296;
                                                                      {
                                                                        auto du32_fst_219 { std::get<0>(id_1295) };
                                                                        auto du32_snd_220 { std::get<1>(id_1295) };
                                                                        ::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5 id_1297 { .parent_num = du32_fst_219, .tunneld_host = drec_fst_210, .tunneld_port = drec_fst_216 };
                                                                        Lst<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5> id_1298 { id_1297, dlist2_fst_195 };
                                                                        ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd id_1299 { id_1298, du32_snd_220 };
                                                                        letpair_res_1296 = id_1299;
                                                                      }
                                                                      letpair_res_1294 = letpair_res_1296;
                                                                    }
                                                                    let_res_1293 = letpair_res_1294;
                                                                  }
                                                                  letpair_res_1289 = let_res_1293;
                                                                }
                                                                let_res_1288 = letpair_res_1289;
                                                              }
                                                              Void id_1300 { ((void)(inits_src_ref_192[id_1240] = let_res_1288), VOID) };
                                                              (void)id_1300;
                                                            }
                                                            (void)VOID;
                                                          }
                                                          (void)VOID;
                                                          uint8_t id_1301 { 0 };
                                                          uint8_t id_1302 { 0 };
                                                          int32_t id_1303 { repeat_n_193[id_1302] };
                                                          int32_t id_1304 { 1L };
                                                          int32_t id_1305 { int32_t(id_1303 + id_1304) };
                                                          Void id_1306 { ((void)(repeat_n_193[id_1301] = id_1305), VOID) };
                                                          (void)id_1306;
                                                          (void)id_1306;
                                                        }
                                                      } while (while_flag_1233);
                                                      (void)VOID;
                                                    }
                                                    (void)VOID;
                                                    uint8_t id_1307 { 0 };
                                                    ::dessser::gen::worker::t38a3258f09a8f59e4b5670e7a10b06dd id_1308 { inits_src_ref_192[id_1307] };
                                                    let_res_1230 = id_1308;
                                                  }
                                                  letpair_res_1226 = let_res_1230;
                                                }
                                                let_res_1225 = letpair_res_1226;
                                              }
                                              ::dessser::gen::worker::tca2b2091d7f296d1f80d11eb663f798d letpair_res_1309;
                                              {
                                                auto dlist4_fst_228 { std::get<0>(let_res_1225) };
                                                auto dlist4_snd_229 { std::get<1>(let_res_1225) };
                                                Arr<::dessser::gen::worker::t8fc31e51f4d30b966d0aba41171f4da5> id_1310 { dlist4_fst_228.toListRev() };
                                                ::dessser::gen::worker::t313b9867db010cca466a30c76e768a91 id_1311 { std::in_place_index<1>, id_1310 };
                                                ::dessser::gen::worker::tca2b2091d7f296d1f80d11eb663f798d id_1312 { id_1311, dlist4_snd_229 };
                                                letpair_res_1309 = id_1312;
                                              }
                                              choose_res_1179 = letpair_res_1309;
                                            }
                                            letpair_res_1176 = choose_res_1179;
                                          }
                                          let_res_1175 = letpair_res_1176;
                                        }
                                        ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_1313;
                                        {
                                          ::dessser::gen::worker::tca2b2091d7f296d1f80d11eb663f798d drec_236 { let_res_1175 };
                                          ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_1314;
                                          {
                                            auto drec_fst_237 { std::get<0>(drec_236) };
                                            auto drec_snd_238 { std::get<1>(drec_236) };
                                            Size id_1315 { 0UL };
                                            uint8_t id_1316 { drec_snd_238.peekU8(id_1315) };
                                            uint8_t id_1317 { 1 };
                                            bool id_1318 { bool(id_1316 == id_1317) };
                                            ::dessser::gen::worker::t6f6d98b735276208527ab0c63bfa2f42 choose_res_1319;
                                            if (id_1318) {
                                              std::optional<Arr<dessser::gen::func_ref::t_ext>> id_1320 { std::nullopt };
                                              Size id_1321 { 1UL };
                                              Pointer id_1322 { drec_snd_238.skip(id_1321) };
                                              ::dessser::gen::worker::t6f6d98b735276208527ab0c63bfa2f42 id_1323 { id_1320, id_1322 };
                                              choose_res_1319 = id_1323;
                                            } else {
                                              uint32_t id_1324 { 0U };
                                              Vec<1, uint32_t> id_1325 {  id_1324  };
                                              ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1326;
                                              {
                                                Vec<1, uint32_t> leb_ref_239 { id_1325 };
                                                uint8_t id_1327 { 0 };
                                                Vec<1, uint8_t> id_1328 {  id_1327  };
                                                ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1329;
                                                {
                                                  Vec<1, uint8_t> shft_ref_240 { id_1328 };
                                                  Size id_1330 { 1UL };
                                                  Pointer id_1331 { drec_snd_238.skip(id_1330) };
                                                  Vec<1, Pointer> id_1332 {  id_1331  };
                                                  ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1333;
                                                  {
                                                    Vec<1, Pointer> p_ref_241 { id_1332 };
                                                    bool while_flag_1334 { true };
                                                    do {
                                                      uint8_t id_1335 { 0 };
                                                      Pointer id_1336 { p_ref_241[id_1335] };
                                                      ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_1337 { id_1336.readU8() };
                                                      bool let_res_1338;
                                                      {
                                                        ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 leb128_242 { id_1337 };
                                                        bool letpair_res_1339;
                                                        {
                                                          auto leb128_fst_243 { std::get<0>(leb128_242) };
                                                          auto leb128_snd_244 { std::get<1>(leb128_242) };
                                                          uint8_t id_1340 { 0 };
                                                          Void id_1341 { ((void)(p_ref_241[id_1340] = leb128_snd_244), VOID) };
                                                          (void)id_1341;
                                                          uint8_t id_1342 { 0 };
                                                          uint8_t id_1343 { 127 };
                                                          uint8_t id_1344 { uint8_t(leb128_fst_243 & id_1343) };
                                                          uint32_t id_1345 { uint32_t(id_1344) };
                                                          uint8_t id_1346 { 0 };
                                                          uint8_t id_1347 { shft_ref_240[id_1346] };
                                                          uint32_t id_1348 { uint32_t(id_1345 << id_1347) };
                                                          uint8_t id_1349 { 0 };
                                                          uint32_t id_1350 { leb_ref_239[id_1349] };
                                                          uint32_t id_1351 { uint32_t(id_1348 | id_1350) };
                                                          Void id_1352 { ((void)(leb_ref_239[id_1342] = id_1351), VOID) };
                                                          (void)id_1352;
                                                          uint8_t id_1353 { 0 };
                                                          uint8_t id_1354 { 0 };
                                                          uint8_t id_1355 { shft_ref_240[id_1354] };
                                                          uint8_t id_1356 { 7 };
                                                          uint8_t id_1357 { uint8_t(id_1355 + id_1356) };
                                                          Void id_1358 { ((void)(shft_ref_240[id_1353] = id_1357), VOID) };
                                                          (void)id_1358;
                                                          uint8_t id_1359 { 128 };
                                                          bool id_1360 { bool(leb128_fst_243 >= id_1359) };
                                                          letpair_res_1339 = id_1360;
                                                        }
                                                        let_res_1338 = letpair_res_1339;
                                                      }
                                                      while_flag_1334 = let_res_1338;
                                                      if (while_flag_1334) {
                                                        (void)VOID;
                                                      }
                                                    } while (while_flag_1334);
                                                    (void)VOID;
                                                    uint8_t id_1361 { 0 };
                                                    uint32_t id_1362 { leb_ref_239[id_1361] };
                                                    uint8_t id_1363 { 0 };
                                                    Pointer id_1364 { p_ref_241[id_1363] };
                                                    ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 id_1365 { id_1362, id_1364 };
                                                    let_res_1333 = id_1365;
                                                  }
                                                  let_res_1329 = let_res_1333;
                                                }
                                                let_res_1326 = let_res_1329;
                                              }
                                              ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 let_res_1366;
                                              {
                                                ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 dlist1_248 { let_res_1326 };
                                                ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 letpair_res_1367;
                                                {
                                                  auto dlist1_fst_249 { std::get<0>(dlist1_248) };
                                                  auto dlist1_snd_250 { std::get<1>(dlist1_248) };
                                                  Lst<dessser::gen::func_ref::t_ext> endoflist_1368;
                                                  ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 id_1369 { endoflist_1368, dlist1_snd_250 };
                                                  Vec<1, ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72> id_1370 {  id_1369  };
                                                  ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 let_res_1371;
                                                  {
                                                    Vec<1, ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72> inits_src_ref_251 { id_1370 };
                                                    int32_t id_1372 { 0L };
                                                    Vec<1, int32_t> id_1373 {  id_1372  };
                                                    {
                                                      Vec<1, int32_t> repeat_n_252 { id_1373 };
                                                      bool while_flag_1374 { true };
                                                      do {
                                                        int32_t id_1375 { int32_t(dlist1_fst_249) };
                                                        uint8_t id_1376 { 0 };
                                                        int32_t id_1377 { repeat_n_252[id_1376] };
                                                        bool id_1378 { bool(id_1375 > id_1377) };
                                                        while_flag_1374 = id_1378;
                                                        if (while_flag_1374) {
                                                          uint8_t id_1379 { 0 };
                                                          ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 id_1380 { inits_src_ref_251[id_1379] };
                                                          {
                                                            ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 dlist2_253 { id_1380 };
                                                            {
                                                              auto dlist2_fst_254 { std::get<0>(dlist2_253) };
                                                              auto dlist2_snd_255 { std::get<1>(dlist2_253) };
                                                              uint8_t id_1381 { 0 };
                                                              auto fun1382 { dessser::gen::func_ref::of_row_binary };
                                                              ::dessser::gen::worker::td5f14eebf589a9b4c952cf9c160f9c66 id_1383 { fun1382(dlist2_snd_255) };
                                                              ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 letpair_res_1384;
                                                              {
                                                                auto dlist3_fst_257 { std::get<0>(id_1383) };
                                                                auto dlist3_snd_258 { std::get<1>(id_1383) };
                                                                Lst<dessser::gen::func_ref::t_ext> id_1385 { dlist3_fst_257, dlist2_fst_254 };
                                                                ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 id_1386 { id_1385, dlist3_snd_258 };
                                                                letpair_res_1384 = id_1386;
                                                              }
                                                              Void id_1387 { ((void)(inits_src_ref_251[id_1381] = letpair_res_1384), VOID) };
                                                              (void)id_1387;
                                                            }
                                                            (void)VOID;
                                                          }
                                                          (void)VOID;
                                                          uint8_t id_1388 { 0 };
                                                          uint8_t id_1389 { 0 };
                                                          int32_t id_1390 { repeat_n_252[id_1389] };
                                                          int32_t id_1391 { 1L };
                                                          int32_t id_1392 { int32_t(id_1390 + id_1391) };
                                                          Void id_1393 { ((void)(repeat_n_252[id_1388] = id_1392), VOID) };
                                                          (void)id_1393;
                                                          (void)id_1393;
                                                        }
                                                      } while (while_flag_1374);
                                                      (void)VOID;
                                                    }
                                                    (void)VOID;
                                                    uint8_t id_1394 { 0 };
                                                    ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 id_1395 { inits_src_ref_251[id_1394] };
                                                    let_res_1371 = id_1395;
                                                  }
                                                  letpair_res_1367 = let_res_1371;
                                                }
                                                let_res_1366 = letpair_res_1367;
                                              }
                                              ::dessser::gen::worker::t6f6d98b735276208527ab0c63bfa2f42 letpair_res_1396;
                                              {
                                                auto dlist4_fst_260 { std::get<0>(let_res_1366) };
                                                auto dlist4_snd_261 { std::get<1>(let_res_1366) };
                                                Arr<dessser::gen::func_ref::t_ext> id_1397 { dlist4_fst_260.toListRev() };
                                                std::optional<Arr<dessser::gen::func_ref::t_ext>> id_1398 { id_1397 };
                                                ::dessser::gen::worker::t6f6d98b735276208527ab0c63bfa2f42 id_1399 { id_1398, dlist4_snd_261 };
                                                letpair_res_1396 = id_1399;
                                              }
                                              choose_res_1319 = letpair_res_1396;
                                            }
                                            ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 let_res_1400;
                                            {
                                              ::dessser::gen::worker::t6f6d98b735276208527ab0c63bfa2f42 drec_265 { choose_res_1319 };
                                              ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_1401;
                                              {
                                                auto drec_fst_266 { std::get<0>(drec_265) };
                                                auto drec_snd_267 { std::get<1>(drec_265) };
                                                uint32_t id_1402 { 0U };
                                                Vec<1, uint32_t> id_1403 {  id_1402  };
                                                ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1404;
                                                {
                                                  Vec<1, uint32_t> leb_ref_268 { id_1403 };
                                                  uint8_t id_1405 { 0 };
                                                  Vec<1, uint8_t> id_1406 {  id_1405  };
                                                  ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1407;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_269 { id_1406 };
                                                    Vec<1, Pointer> id_1408 {  drec_snd_267  };
                                                    ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 let_res_1409;
                                                    {
                                                      Vec<1, Pointer> p_ref_270 { id_1408 };
                                                      bool while_flag_1410 { true };
                                                      do {
                                                        uint8_t id_1411 { 0 };
                                                        Pointer id_1412 { p_ref_270[id_1411] };
                                                        ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 id_1413 { id_1412.readU8() };
                                                        bool let_res_1414;
                                                        {
                                                          ::dessser::gen::worker::tb3f98ea670610d40658a618de3ec7b90 leb128_271 { id_1413 };
                                                          bool letpair_res_1415;
                                                          {
                                                            auto leb128_fst_272 { std::get<0>(leb128_271) };
                                                            auto leb128_snd_273 { std::get<1>(leb128_271) };
                                                            uint8_t id_1416 { 0 };
                                                            Void id_1417 { ((void)(p_ref_270[id_1416] = leb128_snd_273), VOID) };
                                                            (void)id_1417;
                                                            uint8_t id_1418 { 0 };
                                                            uint8_t id_1419 { 127 };
                                                            uint8_t id_1420 { uint8_t(leb128_fst_272 & id_1419) };
                                                            uint32_t id_1421 { uint32_t(id_1420) };
                                                            uint8_t id_1422 { 0 };
                                                            uint8_t id_1423 { shft_ref_269[id_1422] };
                                                            uint32_t id_1424 { uint32_t(id_1421 << id_1423) };
                                                            uint8_t id_1425 { 0 };
                                                            uint32_t id_1426 { leb_ref_268[id_1425] };
                                                            uint32_t id_1427 { uint32_t(id_1424 | id_1426) };
                                                            Void id_1428 { ((void)(leb_ref_268[id_1418] = id_1427), VOID) };
                                                            (void)id_1428;
                                                            uint8_t id_1429 { 0 };
                                                            uint8_t id_1430 { 0 };
                                                            uint8_t id_1431 { shft_ref_269[id_1430] };
                                                            uint8_t id_1432 { 7 };
                                                            uint8_t id_1433 { uint8_t(id_1431 + id_1432) };
                                                            Void id_1434 { ((void)(shft_ref_269[id_1429] = id_1433), VOID) };
                                                            (void)id_1434;
                                                            uint8_t id_1435 { 128 };
                                                            bool id_1436 { bool(leb128_fst_272 >= id_1435) };
                                                            letpair_res_1415 = id_1436;
                                                          }
                                                          let_res_1414 = letpair_res_1415;
                                                        }
                                                        while_flag_1410 = let_res_1414;
                                                        if (while_flag_1410) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_1410);
                                                      (void)VOID;
                                                      uint8_t id_1437 { 0 };
                                                      uint32_t id_1438 { leb_ref_268[id_1437] };
                                                      uint8_t id_1439 { 0 };
                                                      Pointer id_1440 { p_ref_270[id_1439] };
                                                      ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 id_1441 { id_1438, id_1440 };
                                                      let_res_1409 = id_1441;
                                                    }
                                                    let_res_1407 = let_res_1409;
                                                  }
                                                  let_res_1404 = let_res_1407;
                                                }
                                                ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 let_res_1442;
                                                {
                                                  ::dessser::gen::worker::t405eb186408556fed8f2c41523c07d13 dlist1_277 { let_res_1404 };
                                                  ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 letpair_res_1443;
                                                  {
                                                    auto dlist1_fst_278 { std::get<0>(dlist1_277) };
                                                    auto dlist1_snd_279 { std::get<1>(dlist1_277) };
                                                    Lst<dessser::gen::func_ref::t_ext> endoflist_1444;
                                                    ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 id_1445 { endoflist_1444, dlist1_snd_279 };
                                                    Vec<1, ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72> id_1446 {  id_1445  };
                                                    ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 let_res_1447;
                                                    {
                                                      Vec<1, ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72> inits_src_ref_280 { id_1446 };
                                                      int32_t id_1448 { 0L };
                                                      Vec<1, int32_t> id_1449 {  id_1448  };
                                                      {
                                                        Vec<1, int32_t> repeat_n_281 { id_1449 };
                                                        bool while_flag_1450 { true };
                                                        do {
                                                          int32_t id_1451 { int32_t(dlist1_fst_278) };
                                                          uint8_t id_1452 { 0 };
                                                          int32_t id_1453 { repeat_n_281[id_1452] };
                                                          bool id_1454 { bool(id_1451 > id_1453) };
                                                          while_flag_1450 = id_1454;
                                                          if (while_flag_1450) {
                                                            uint8_t id_1455 { 0 };
                                                            ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 id_1456 { inits_src_ref_280[id_1455] };
                                                            {
                                                              ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 dlist2_282 { id_1456 };
                                                              {
                                                                auto dlist2_fst_283 { std::get<0>(dlist2_282) };
                                                                auto dlist2_snd_284 { std::get<1>(dlist2_282) };
                                                                uint8_t id_1457 { 0 };
                                                                auto fun1458 { dessser::gen::func_ref::of_row_binary };
                                                                ::dessser::gen::worker::td5f14eebf589a9b4c952cf9c160f9c66 id_1459 { fun1458(dlist2_snd_284) };
                                                                ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 letpair_res_1460;
                                                                {
                                                                  auto dlist3_fst_286 { std::get<0>(id_1459) };
                                                                  auto dlist3_snd_287 { std::get<1>(id_1459) };
                                                                  Lst<dessser::gen::func_ref::t_ext> id_1461 { dlist3_fst_286, dlist2_fst_283 };
                                                                  ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 id_1462 { id_1461, dlist3_snd_287 };
                                                                  letpair_res_1460 = id_1462;
                                                                }
                                                                Void id_1463 { ((void)(inits_src_ref_280[id_1457] = letpair_res_1460), VOID) };
                                                                (void)id_1463;
                                                              }
                                                              (void)VOID;
                                                            }
                                                            (void)VOID;
                                                            uint8_t id_1464 { 0 };
                                                            uint8_t id_1465 { 0 };
                                                            int32_t id_1466 { repeat_n_281[id_1465] };
                                                            int32_t id_1467 { 1L };
                                                            int32_t id_1468 { int32_t(id_1466 + id_1467) };
                                                            Void id_1469 { ((void)(repeat_n_281[id_1464] = id_1468), VOID) };
                                                            (void)id_1469;
                                                            (void)id_1469;
                                                          }
                                                        } while (while_flag_1450);
                                                        (void)VOID;
                                                      }
                                                      (void)VOID;
                                                      uint8_t id_1470 { 0 };
                                                      ::dessser::gen::worker::tbd412d4066b1057863e0544a21e0ab72 id_1471 { inits_src_ref_280[id_1470] };
                                                      let_res_1447 = id_1471;
                                                    }
                                                    letpair_res_1443 = let_res_1447;
                                                  }
                                                  let_res_1442 = letpair_res_1443;
                                                }
                                                ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 letpair_res_1472;
                                                {
                                                  auto dlist4_fst_289 { std::get<0>(let_res_1442) };
                                                  auto dlist4_snd_290 { std::get<1>(let_res_1442) };
                                                  Arr<dessser::gen::func_ref::t_ext> id_1473 { dlist4_fst_289.toListRev() };
                                                  ::dessser::gen::worker::t* id_1474 { new ::dessser::gen::worker::t({ .children = id_1473, .cwd = drec_fst_75, .debug = drec_fst_66, .enabled = drec_fst_60, .envvars = drec_fst_169, .info_signature = drec_fst_105, .is_used = drec_fst_111, .params = drec_fst_143, .parents = drec_fst_266, .report_period = drec_fst_72, .role = drec_fst_237, .worker_signature = drec_fst_90 }) };
                                                  ::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576 id_1475 { id_1474, dlist4_snd_290 };
                                                  letpair_res_1472 = id_1475;
                                                }
                                                letpair_res_1401 = letpair_res_1472;
                                              }
                                              let_res_1400 = letpair_res_1401;
                                            }
                                            letpair_res_1314 = let_res_1400;
                                          }
                                          let_res_1313 = letpair_res_1314;
                                        }
                                        letpair_res_1171 = let_res_1313;
                                      }
                                      let_res_1170 = letpair_res_1171;
                                    }
                                    letpair_res_1096 = let_res_1170;
                                  }
                                  let_res_1095 = letpair_res_1096;
                                }
                                letpair_res_1016 = let_res_1095;
                              }
                              let_res_1015 = letpair_res_1016;
                            }
                            letpair_res_1008 = let_res_1015;
                          }
                          let_res_1007 = letpair_res_1008;
                        }
                        letpair_res_959 = let_res_1007;
                      }
                      let_res_958 = letpair_res_959;
                    }
                    letpair_res_910 = let_res_958;
                  }
                  let_res_909 = letpair_res_910;
                }
                letpair_res_906 = let_res_909;
              }
              let_res_905 = letpair_res_906;
            }
            letpair_res_900 = let_res_905;
          }
          let_res_899 = letpair_res_900;
        }
        letpair_res_892 = let_res_899;
      }
      let_res_891 = letpair_res_892;
    }
    return let_res_891;
  }
   };
  return fun884;
}
std::function<::dessser::gen::worker::t2153f894ec0d3c3ed0ba5ddc0b3fd576(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
