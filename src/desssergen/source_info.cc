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
#include "desssergen/src_path.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_operation.h"
#include "desssergen/retention.h"
#include "desssergen/function_name.h"
#include "desssergen/global_variable.h"
#include "desssergen/raql_expr.h"
#include "desssergen/program_parameter.h"


namespace dessser::gen::source_info {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct tb0a5947d2e730ef2c38de99be0c65701 {
  dessser::gen::function_name::t_ext name;
  std::optional<dessser::gen::retention::t_ext> retention;
  bool is_lazy;
  std::string doc;
  dessser::gen::raql_operation::t_ext operation;
  dessser::gen::raql_type::t_ext out_record;
  Lst<dessser::gen::field_name::t_ext> factors;
  std::string signature;
  std::string in_signature;
  bool operator==(tb0a5947d2e730ef2c38de99be0c65701 const &other) const {
    return name == other.name && retention == other.retention && is_lazy == other.is_lazy && doc == other.doc && operation == other.operation && out_record == other.out_record && factors == other.factors && signature == other.signature && in_signature == other.in_signature;
  }
};
struct t67d467e776d7a3f3e54efabfd5f911ed {
  Lst<dessser::gen::program_parameter::t_ext> default_params;
  dessser::gen::raql_expr::t_ext condition;
  Lst<dessser::gen::global_variable::t_ext> globals;
  Lst<tb0a5947d2e730ef2c38de99be0c65701> funcs;
  bool operator==(t67d467e776d7a3f3e54efabfd5f911ed const &other) const {
    return default_params == other.default_params && condition == other.condition && globals == other.globals && funcs == other.funcs;
  }
};
struct t0fbe0ba3da9da3292ae419be74c6cc6e {
  std::string err_msg;
  std::optional<dessser::gen::src_path::t_ext> depends_on;
  bool operator==(t0fbe0ba3da9da3292ae419be74c6cc6e const &other) const {
    return err_msg == other.err_msg && depends_on == other.depends_on;
  }
};
struct t1f2a02f42faa570bd799752d94503c06 : public std::variant<
  t67d467e776d7a3f3e54efabfd5f911ed,
  t0fbe0ba3da9da3292ae419be74c6cc6e
> { using variant::variant; };
struct t {
  std::string src_ext;
  Lst<std::string> md5s;
  t1f2a02f42faa570bd799752d94503c06 detail;
  bool operator==(t const &other) const {
    return src_ext == other.src_ext && md5s == other.md5s && detail == other.detail;
  }
};
typedef std::tuple<
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

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

typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  Lst<std::string>,
  Pointer
> ta48cca69b6e077e610d35192824cedc1;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  t1f2a02f42faa570bd799752d94503c06,
  Pointer
> tb0e3f2c9b734bb327b41592ba7807707;

typedef std::tuple<
  Lst<dessser::gen::program_parameter::t_ext>,
  Pointer
> t72c0be8b93ff5eeb0f991b2e0e95f3b9;

typedef std::tuple<
  dessser::gen::program_parameter::t_ext,
  Pointer
> t0d694f310c72fe705045b499b1bf4849;

typedef std::tuple<
  dessser::gen::raql_expr::t_ext,
  Pointer
> t1113e6691818baaf60a775527f6cc1ac;

typedef std::tuple<
  Lst<dessser::gen::global_variable::t_ext>,
  Pointer
> t8eecaa544f974ea6c77122c0d4c2f67e;

typedef std::tuple<
  dessser::gen::global_variable::t_ext,
  Pointer
> t911eab4a6da5a01e780085a224d7ed2a;

typedef std::tuple<
  Lst<tb0a5947d2e730ef2c38de99be0c65701>,
  Pointer
> t99bf25e2852182fc53ed35e1ddb06ab9;

typedef std::tuple<
  dessser::gen::function_name::t_ext,
  Pointer
> tc7d3fcfd06c0f02b3732e1754a18402b;

typedef std::tuple<
  std::optional<dessser::gen::retention::t_ext>,
  Pointer
> td0d099f587b9e25386cc3fd1ecb674a4;

typedef std::tuple<
  dessser::gen::retention::t_ext,
  Pointer
> t7c83e84e0162e9442953bc16c018e153;

typedef std::tuple<
  bool,
  Pointer
> t4138de986e20d18b01e4c493dc9d5451;

typedef std::tuple<
  dessser::gen::raql_operation::t_ext,
  Pointer
> ta546df8799999c6d44c12cb331e3c39d;

typedef std::tuple<
  dessser::gen::raql_type::t_ext,
  Pointer
> t2f923f73303f235bd6ab3a4150418dd9;

typedef std::tuple<
  Lst<dessser::gen::field_name::t_ext>,
  Pointer
> t0dfa866705b76efff53e4aa97228a967;

typedef std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> t273a2b7978f5b466a128a51c1cc4a27b;

typedef std::tuple<
  std::optional<dessser::gen::src_path::t_ext>,
  Pointer
> t704dc7dfdc8ab68dc50aa22f37a6ee27;

typedef std::tuple<
  dessser::gen::src_path::t_ext,
  Pointer
> t3aef8ea133ee816827fd8db245b58487;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}[[]]} | Failed {err_msg: STRING; depends_on: $src_path?}]}" "Ptr")
      (let "srec_dst_391"
        (let "srec_dst_383"
          (write-bytes
            (let "leb128_sz_381" (make-vec (string-length (get-field "src_ext" (param 0))))
              (let "leb128_ptr_382" (make-vec (param 1))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_382")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_382"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_381"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_381"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_381"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_381") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_381")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_381")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_382"))))) 
            (bytes-of-string (get-field "src_ext" (param 0))))
          (let "dst_ref_386"
            (make-vec
              (let "leb128_sz_384" (make-vec (cardinality (get-field "md5s" (param 0))))
                (let "leb128_ptr_385" (make-vec (identifier "srec_dst_383"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_385")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_385"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_384"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_384"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_384"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_384") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_384")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_384")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_385"))))))
            (let "n_ref_387" (make-vec (i32 0))
              (seq
                (for-each "x_388" (get-field "md5s" (param 0))
                  (seq
                    (set-vec (u8 0) (identifier "dst_ref_386")
                      (write-bytes
                        (let "leb128_sz_389" (make-vec (string-length (identifier "x_388")))
                          (let "leb128_ptr_390" (make-vec (unsafe-nth (u8 0) (identifier "dst_ref_386")))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_390")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_390"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_389"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_389"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_389"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_389") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_389")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_389")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_390"))))) 
                        (bytes-of-string (identifier "x_388")))) (set-vec (u8 0) (identifier "n_ref_387") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_387")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_386"))))))
        (let "ssum_dst_393" (write-u16 little-endian (identifier "srec_dst_391") (label-of (get-field "detail" (param 0))))
          (if (eq (u16 0) (label-of (get-field "detail" (param 0))))
            (let "srec_dst_409"
              (let "srec_dst_403"
                (let "srec_dst_402"
                  (let "dst_ref_399"
                    (make-vec
                      (let "leb128_sz_397" (make-vec (cardinality (get-field "default_params" (get-alt "Compiled" (get-field "detail" (param 0))))))
                        (let "leb128_ptr_398" (make-vec (identifier "ssum_dst_393"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_398")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_398"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_397"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_397"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_397"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_397") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_397")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_397")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_398"))))))
                    (let "n_ref_400" (make-vec (i32 0))
                      (seq
                        (for-each "x_401" (get-field "default_params" (get-alt "Compiled" (get-field "detail" (param 0))))
                          (seq (set-vec (u8 0) (identifier "dst_ref_399") (apply (ext-identifier program_parameter to-row-binary) (identifier "x_401") (unsafe-nth (u8 0) (identifier "dst_ref_399"))))
                            (set-vec (u8 0) (identifier "n_ref_400") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_400")))))) 
                        (unsafe-nth (u8 0) (identifier "dst_ref_399"))))) 
                  (apply (ext-identifier raql_expr to-row-binary) (get-field "condition" (get-alt "Compiled" (get-field "detail" (param 0)))) (identifier "srec_dst_402")))
                (let "dst_ref_406"
                  (make-vec
                    (let "leb128_sz_404" (make-vec (cardinality (get-field "globals" (get-alt "Compiled" (get-field "detail" (param 0))))))
                      (let "leb128_ptr_405" (make-vec (identifier "srec_dst_403"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_405")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_405"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_404"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_404"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_404"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_404") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_404")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_404")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_405"))))))
                  (let "n_ref_407" (make-vec (i32 0))
                    (seq
                      (for-each "x_408" (get-field "globals" (get-alt "Compiled" (get-field "detail" (param 0))))
                        (seq (set-vec (u8 0) (identifier "dst_ref_406") (apply (ext-identifier global_variable to-row-binary) (identifier "x_408") (unsafe-nth (u8 0) (identifier "dst_ref_406"))))
                          (set-vec (u8 0) (identifier "n_ref_407") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_407")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_406"))))))
              (let "dst_ref_412"
                (make-vec
                  (let "leb128_sz_410" (make-vec (cardinality (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0))))))
                    (let "leb128_ptr_411" (make-vec (identifier "srec_dst_409"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_411")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_411"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_410"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_410"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_410"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_410") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_410")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_410")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_411"))))))
                (let "n_ref_413" (make-vec (i32 0))
                  (seq
                    (for-each "x_414" (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0))))
                      (seq
                        (set-vec (u8 0) (identifier "dst_ref_412")
                          (let "srec_dst_432"
                            (let "srec_dst_429"
                              (let "srec_dst_423"
                                (let "srec_dst_422"
                                  (let "srec_dst_421"
                                    (let "srec_dst_418"
                                      (let "srec_dst_417"
                                        (let "srec_dst_416"
                                          (let "srec_dst_415" (unsafe-nth (u8 0) (identifier "dst_ref_412"))
                                            (apply (ext-identifier function_name to-row-binary) (get-field "name" (identifier "x_414")) (identifier "srec_dst_415")))
                                          (if (is-null (get-field "retention" (identifier "x_414"))) 
                                            (write-u8 (identifier "srec_dst_416") (u8 1))
                                            (apply (ext-identifier retention to-row-binary) (force (get-field "retention" (identifier "x_414"))) (write-u8 (identifier "srec_dst_416") (u8 0)))))
                                        (write-u8 (identifier "srec_dst_417") (u8-of-bool (get-field "is_lazy" (identifier "x_414")))))
                                      (write-bytes
                                        (let "leb128_sz_419" (make-vec (string-length (get-field "doc" (identifier "x_414"))))
                                          (let "leb128_ptr_420" (make-vec (identifier "srec_dst_418"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_420")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_420"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_419"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_419"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_419"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_419") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_419")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_419")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_420"))))) 
                                        (bytes-of-string (get-field "doc" (identifier "x_414"))))) 
                                    (apply (ext-identifier raql_operation to-row-binary) (get-field "operation" (identifier "x_414")) (identifier "srec_dst_421")))
                                  (apply (ext-identifier raql_type to-row-binary) (get-field "out_record" (identifier "x_414")) (identifier "srec_dst_422")))
                                (let "dst_ref_426"
                                  (make-vec
                                    (let "leb128_sz_424" (make-vec (cardinality (get-field "factors" (identifier "x_414"))))
                                      (let "leb128_ptr_425" (make-vec (identifier "srec_dst_423"))
                                        (seq
                                          (while
                                            (seq
                                              (set-vec (u8 0) (identifier "leb128_ptr_425")
                                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_425"))
                                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_424"))) 
                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_424"))) 
                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_424"))) (u8 128)))))
                                              (set-vec (u8 0) (identifier "leb128_sz_424") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_424")) (u8 7))) 
                                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_424")) (u32 0))) 
                                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_425"))))))
                                  (let "n_ref_427" (make-vec (i32 0))
                                    (seq
                                      (for-each "x_428" (get-field "factors" (identifier "x_414"))
                                        (seq (set-vec (u8 0) (identifier "dst_ref_426") (apply (ext-identifier field_name to-row-binary) (identifier "x_428") (unsafe-nth (u8 0) (identifier "dst_ref_426"))))
                                          (set-vec (u8 0) (identifier "n_ref_427") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_427")))))) 
                                      (unsafe-nth (u8 0) (identifier "dst_ref_426"))))))
                              (write-bytes
                                (let "leb128_sz_430" (make-vec (string-length (get-field "signature" (identifier "x_414"))))
                                  (let "leb128_ptr_431" (make-vec (identifier "srec_dst_429"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_431")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_431"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_430"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_430"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_430"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_430") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_430")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_430")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_431"))))) 
                                (bytes-of-string (get-field "signature" (identifier "x_414")))))
                            (write-bytes
                              (let "leb128_sz_433" (make-vec (string-length (get-field "in_signature" (identifier "x_414"))))
                                (let "leb128_ptr_434" (make-vec (identifier "srec_dst_432"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_434")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_434"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_433"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_433"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_433"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_433") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_433")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_433")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_434"))))) 
                              (bytes-of-string (get-field "in_signature" (identifier "x_414")))))) 
                        (set-vec (u8 0) (identifier "n_ref_413") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_413")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_412"))))))
            (seq (assert (eq (label-of (get-field "detail" (param 0))) (u16 1)))
              (let "srec_dst_396"
                (write-bytes
                  (let "leb128_sz_394" (make-vec (string-length (get-field "err_msg" (get-alt "Failed" (get-field "detail" (param 0))))))
                    (let "leb128_ptr_395" (make-vec (identifier "ssum_dst_393"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_395")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_395"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_394"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_394"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_394"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_394") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_394")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_394")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_395"))))) 
                  (bytes-of-string (get-field "err_msg" (get-alt "Failed" (get-field "detail" (param 0))))))
                (if (is-null (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) 
                  (write-u8 (identifier "srec_dst_396") (u8 1))
                  (apply (ext-identifier src_path to-row-binary) (force (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) (write-u8 (identifier "srec_dst_396") (u8 0))))))))))
 */
static std::function<Pointer(t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t*,Pointer)> fun0 { [&fun0](t* p_0, Pointer p_1) {
    std::string id_1 { p_0->src_ext };
    uint32_t id_2 { (uint32_t)id_1.size() };
    Vec<1, uint32_t> id_3 {  id_2  };
    Pointer let_res_4;
    {
      Vec<1, uint32_t> leb128_sz_381 { id_3 };
      Vec<1, Pointer> id_5 {  p_1  };
      Pointer let_res_6;
      {
        Vec<1, Pointer> leb128_ptr_382 { id_5 };
        bool while_flag_7 { true };
        do {
          uint8_t id_8 { 0 };
          uint8_t id_9 { 0 };
          Pointer id_10 { leb128_ptr_382[id_9] };
          uint32_t id_11 { 128U };
          uint8_t id_12 { 0 };
          uint32_t id_13 { leb128_sz_381[id_12] };
          bool id_14 { bool(id_11 > id_13) };
          uint8_t choose_res_15;
          if (id_14) {
            uint8_t id_16 { 0 };
            uint32_t id_17 { leb128_sz_381[id_16] };
            uint8_t id_18 { uint8_t(id_17) };
            choose_res_15 = id_18;
          } else {
            uint8_t id_19 { 0 };
            uint32_t id_20 { leb128_sz_381[id_19] };
            uint8_t id_21 { uint8_t(id_20) };
            uint8_t id_22 { 128 };
            uint8_t id_23 { uint8_t(id_21 | id_22) };
            choose_res_15 = id_23;
          }
          Pointer id_24 { id_10.writeU8(choose_res_15) };
          Void id_25 { ((void)(leb128_ptr_382[id_8] = id_24), VOID) };
          (void)id_25;
          uint8_t id_26 { 0 };
          uint8_t id_27 { 0 };
          uint32_t id_28 { leb128_sz_381[id_27] };
          uint8_t id_29 { 7 };
          uint32_t id_30 { uint32_t(id_28 >> id_29) };
          Void id_31 { ((void)(leb128_sz_381[id_26] = id_30), VOID) };
          (void)id_31;
          uint8_t id_32 { 0 };
          uint32_t id_33 { leb128_sz_381[id_32] };
          uint32_t id_34 { 0U };
          bool id_35 { bool(id_33 > id_34) };
          while_flag_7 = id_35;
          if (while_flag_7) {
            (void)VOID;
          }
        } while (while_flag_7);
        (void)VOID;
        uint8_t id_36 { 0 };
        Pointer id_37 { leb128_ptr_382[id_36] };
        let_res_6 = id_37;
      }
      let_res_4 = let_res_6;
    }
    std::string id_38 { p_0->src_ext };
    Bytes id_39 { id_38 };
    Pointer id_40 { let_res_4.writeBytes(id_39) };
    Pointer let_res_41;
    {
      Pointer srec_dst_383 { id_40 };
      Lst<std::string> id_42 { p_0->md5s };
      uint32_t id_43 { id_42.size() };
      Vec<1, uint32_t> id_44 {  id_43  };
      Pointer let_res_45;
      {
        Vec<1, uint32_t> leb128_sz_384 { id_44 };
        Vec<1, Pointer> id_46 {  srec_dst_383  };
        Pointer let_res_47;
        {
          Vec<1, Pointer> leb128_ptr_385 { id_46 };
          bool while_flag_48 { true };
          do {
            uint8_t id_49 { 0 };
            uint8_t id_50 { 0 };
            Pointer id_51 { leb128_ptr_385[id_50] };
            uint32_t id_52 { 128U };
            uint8_t id_53 { 0 };
            uint32_t id_54 { leb128_sz_384[id_53] };
            bool id_55 { bool(id_52 > id_54) };
            uint8_t choose_res_56;
            if (id_55) {
              uint8_t id_57 { 0 };
              uint32_t id_58 { leb128_sz_384[id_57] };
              uint8_t id_59 { uint8_t(id_58) };
              choose_res_56 = id_59;
            } else {
              uint8_t id_60 { 0 };
              uint32_t id_61 { leb128_sz_384[id_60] };
              uint8_t id_62 { uint8_t(id_61) };
              uint8_t id_63 { 128 };
              uint8_t id_64 { uint8_t(id_62 | id_63) };
              choose_res_56 = id_64;
            }
            Pointer id_65 { id_51.writeU8(choose_res_56) };
            Void id_66 { ((void)(leb128_ptr_385[id_49] = id_65), VOID) };
            (void)id_66;
            uint8_t id_67 { 0 };
            uint8_t id_68 { 0 };
            uint32_t id_69 { leb128_sz_384[id_68] };
            uint8_t id_70 { 7 };
            uint32_t id_71 { uint32_t(id_69 >> id_70) };
            Void id_72 { ((void)(leb128_sz_384[id_67] = id_71), VOID) };
            (void)id_72;
            uint8_t id_73 { 0 };
            uint32_t id_74 { leb128_sz_384[id_73] };
            uint32_t id_75 { 0U };
            bool id_76 { bool(id_74 > id_75) };
            while_flag_48 = id_76;
            if (while_flag_48) {
              (void)VOID;
            }
          } while (while_flag_48);
          (void)VOID;
          uint8_t id_77 { 0 };
          Pointer id_78 { leb128_ptr_385[id_77] };
          let_res_47 = id_78;
        }
        let_res_45 = let_res_47;
      }
      Vec<1, Pointer> id_79 {  let_res_45  };
      Pointer let_res_80;
      {
        Vec<1, Pointer> dst_ref_386 { id_79 };
        int32_t id_81 { 0L };
        Vec<1, int32_t> id_82 {  id_81  };
        Pointer let_res_83;
        {
          Vec<1, int32_t> n_ref_387 { id_82 };
          Lst<std::string> id_84 { p_0->md5s };
          for (std::string x_388 : id_84) {
            uint8_t id_85 { 0 };
            uint32_t id_86 { (uint32_t)x_388.size() };
            Vec<1, uint32_t> id_87 {  id_86  };
            Pointer let_res_88;
            {
              Vec<1, uint32_t> leb128_sz_389 { id_87 };
              uint8_t id_89 { 0 };
              Pointer id_90 { dst_ref_386[id_89] };
              Vec<1, Pointer> id_91 {  id_90  };
              Pointer let_res_92;
              {
                Vec<1, Pointer> leb128_ptr_390 { id_91 };
                bool while_flag_93 { true };
                do {
                  uint8_t id_94 { 0 };
                  uint8_t id_95 { 0 };
                  Pointer id_96 { leb128_ptr_390[id_95] };
                  uint32_t id_97 { 128U };
                  uint8_t id_98 { 0 };
                  uint32_t id_99 { leb128_sz_389[id_98] };
                  bool id_100 { bool(id_97 > id_99) };
                  uint8_t choose_res_101;
                  if (id_100) {
                    uint8_t id_102 { 0 };
                    uint32_t id_103 { leb128_sz_389[id_102] };
                    uint8_t id_104 { uint8_t(id_103) };
                    choose_res_101 = id_104;
                  } else {
                    uint8_t id_105 { 0 };
                    uint32_t id_106 { leb128_sz_389[id_105] };
                    uint8_t id_107 { uint8_t(id_106) };
                    uint8_t id_108 { 128 };
                    uint8_t id_109 { uint8_t(id_107 | id_108) };
                    choose_res_101 = id_109;
                  }
                  Pointer id_110 { id_96.writeU8(choose_res_101) };
                  Void id_111 { ((void)(leb128_ptr_390[id_94] = id_110), VOID) };
                  (void)id_111;
                  uint8_t id_112 { 0 };
                  uint8_t id_113 { 0 };
                  uint32_t id_114 { leb128_sz_389[id_113] };
                  uint8_t id_115 { 7 };
                  uint32_t id_116 { uint32_t(id_114 >> id_115) };
                  Void id_117 { ((void)(leb128_sz_389[id_112] = id_116), VOID) };
                  (void)id_117;
                  uint8_t id_118 { 0 };
                  uint32_t id_119 { leb128_sz_389[id_118] };
                  uint32_t id_120 { 0U };
                  bool id_121 { bool(id_119 > id_120) };
                  while_flag_93 = id_121;
                  if (while_flag_93) {
                    (void)VOID;
                  }
                } while (while_flag_93);
                (void)VOID;
                uint8_t id_122 { 0 };
                Pointer id_123 { leb128_ptr_390[id_122] };
                let_res_92 = id_123;
              }
              let_res_88 = let_res_92;
            }
            Bytes id_124 { x_388 };
            Pointer id_125 { let_res_88.writeBytes(id_124) };
            Void id_126 { ((void)(dst_ref_386[id_85] = id_125), VOID) };
            (void)id_126;
            uint8_t id_127 { 0 };
            int32_t id_128 { 1L };
            uint8_t id_129 { 0 };
            int32_t id_130 { n_ref_387[id_129] };
            int32_t id_131 { int32_t(id_128 + id_130) };
            Void id_132 { ((void)(n_ref_387[id_127] = id_131), VOID) };
            (void)id_132;
            (void)id_132;
          }
          (void)VOID;
          uint8_t id_133 { 0 };
          Pointer id_134 { dst_ref_386[id_133] };
          let_res_83 = id_134;
        }
        let_res_80 = let_res_83;
      }
      let_res_41 = let_res_80;
    }
    Pointer let_res_135;
    {
      Pointer srec_dst_391 { let_res_41 };
      t1f2a02f42faa570bd799752d94503c06 id_136 { p_0->detail };
      uint16_t id_137 { uint16_t(id_136.index()) };
      Pointer id_138 { srec_dst_391.writeU16Le(id_137) };
      Pointer let_res_139;
      {
        Pointer ssum_dst_393 { id_138 };
        uint16_t id_140 { 0 };
        t1f2a02f42faa570bd799752d94503c06 id_141 { p_0->detail };
        uint16_t id_142 { uint16_t(id_141.index()) };
        bool id_143 { bool(id_140 == id_142) };
        Pointer choose_res_144;
        if (id_143) {
          t1f2a02f42faa570bd799752d94503c06 id_145 { p_0->detail };
          t67d467e776d7a3f3e54efabfd5f911ed id_146 { std::get<0>(id_145) };
          Lst<dessser::gen::program_parameter::t_ext> id_147 { id_146.default_params };
          uint32_t id_148 { id_147.size() };
          Vec<1, uint32_t> id_149 {  id_148  };
          Pointer let_res_150;
          {
            Vec<1, uint32_t> leb128_sz_397 { id_149 };
            Vec<1, Pointer> id_151 {  ssum_dst_393  };
            Pointer let_res_152;
            {
              Vec<1, Pointer> leb128_ptr_398 { id_151 };
              bool while_flag_153 { true };
              do {
                uint8_t id_154 { 0 };
                uint8_t id_155 { 0 };
                Pointer id_156 { leb128_ptr_398[id_155] };
                uint32_t id_157 { 128U };
                uint8_t id_158 { 0 };
                uint32_t id_159 { leb128_sz_397[id_158] };
                bool id_160 { bool(id_157 > id_159) };
                uint8_t choose_res_161;
                if (id_160) {
                  uint8_t id_162 { 0 };
                  uint32_t id_163 { leb128_sz_397[id_162] };
                  uint8_t id_164 { uint8_t(id_163) };
                  choose_res_161 = id_164;
                } else {
                  uint8_t id_165 { 0 };
                  uint32_t id_166 { leb128_sz_397[id_165] };
                  uint8_t id_167 { uint8_t(id_166) };
                  uint8_t id_168 { 128 };
                  uint8_t id_169 { uint8_t(id_167 | id_168) };
                  choose_res_161 = id_169;
                }
                Pointer id_170 { id_156.writeU8(choose_res_161) };
                Void id_171 { ((void)(leb128_ptr_398[id_154] = id_170), VOID) };
                (void)id_171;
                uint8_t id_172 { 0 };
                uint8_t id_173 { 0 };
                uint32_t id_174 { leb128_sz_397[id_173] };
                uint8_t id_175 { 7 };
                uint32_t id_176 { uint32_t(id_174 >> id_175) };
                Void id_177 { ((void)(leb128_sz_397[id_172] = id_176), VOID) };
                (void)id_177;
                uint8_t id_178 { 0 };
                uint32_t id_179 { leb128_sz_397[id_178] };
                uint32_t id_180 { 0U };
                bool id_181 { bool(id_179 > id_180) };
                while_flag_153 = id_181;
                if (while_flag_153) {
                  (void)VOID;
                }
              } while (while_flag_153);
              (void)VOID;
              uint8_t id_182 { 0 };
              Pointer id_183 { leb128_ptr_398[id_182] };
              let_res_152 = id_183;
            }
            let_res_150 = let_res_152;
          }
          Vec<1, Pointer> id_184 {  let_res_150  };
          Pointer let_res_185;
          {
            Vec<1, Pointer> dst_ref_399 { id_184 };
            int32_t id_186 { 0L };
            Vec<1, int32_t> id_187 {  id_186  };
            Pointer let_res_188;
            {
              Vec<1, int32_t> n_ref_400 { id_187 };
              t1f2a02f42faa570bd799752d94503c06 id_189 { p_0->detail };
              t67d467e776d7a3f3e54efabfd5f911ed id_190 { std::get<0>(id_189) };
              Lst<dessser::gen::program_parameter::t_ext> id_191 { id_190.default_params };
              for (dessser::gen::program_parameter::t_ext x_401 : id_191) {
                uint8_t id_192 { 0 };
                auto fun193 { dessser::gen::program_parameter::to_row_binary };
                uint8_t id_194 { 0 };
                Pointer id_195 { dst_ref_399[id_194] };
                Pointer id_196 { fun193(x_401, id_195) };
                Void id_197 { ((void)(dst_ref_399[id_192] = id_196), VOID) };
                (void)id_197;
                uint8_t id_198 { 0 };
                int32_t id_199 { 1L };
                uint8_t id_200 { 0 };
                int32_t id_201 { n_ref_400[id_200] };
                int32_t id_202 { int32_t(id_199 + id_201) };
                Void id_203 { ((void)(n_ref_400[id_198] = id_202), VOID) };
                (void)id_203;
                (void)id_203;
              }
              (void)VOID;
              uint8_t id_204 { 0 };
              Pointer id_205 { dst_ref_399[id_204] };
              let_res_188 = id_205;
            }
            let_res_185 = let_res_188;
          }
          Pointer let_res_206;
          {
            Pointer srec_dst_402 { let_res_185 };
            auto fun207 { dessser::gen::raql_expr::to_row_binary };
            t1f2a02f42faa570bd799752d94503c06 id_208 { p_0->detail };
            t67d467e776d7a3f3e54efabfd5f911ed id_209 { std::get<0>(id_208) };
            dessser::gen::raql_expr::t_ext id_210 { id_209.condition };
            Pointer id_211 { fun207(id_210, srec_dst_402) };
            let_res_206 = id_211;
          }
          Pointer let_res_212;
          {
            Pointer srec_dst_403 { let_res_206 };
            t1f2a02f42faa570bd799752d94503c06 id_213 { p_0->detail };
            t67d467e776d7a3f3e54efabfd5f911ed id_214 { std::get<0>(id_213) };
            Lst<dessser::gen::global_variable::t_ext> id_215 { id_214.globals };
            uint32_t id_216 { id_215.size() };
            Vec<1, uint32_t> id_217 {  id_216  };
            Pointer let_res_218;
            {
              Vec<1, uint32_t> leb128_sz_404 { id_217 };
              Vec<1, Pointer> id_219 {  srec_dst_403  };
              Pointer let_res_220;
              {
                Vec<1, Pointer> leb128_ptr_405 { id_219 };
                bool while_flag_221 { true };
                do {
                  uint8_t id_222 { 0 };
                  uint8_t id_223 { 0 };
                  Pointer id_224 { leb128_ptr_405[id_223] };
                  uint32_t id_225 { 128U };
                  uint8_t id_226 { 0 };
                  uint32_t id_227 { leb128_sz_404[id_226] };
                  bool id_228 { bool(id_225 > id_227) };
                  uint8_t choose_res_229;
                  if (id_228) {
                    uint8_t id_230 { 0 };
                    uint32_t id_231 { leb128_sz_404[id_230] };
                    uint8_t id_232 { uint8_t(id_231) };
                    choose_res_229 = id_232;
                  } else {
                    uint8_t id_233 { 0 };
                    uint32_t id_234 { leb128_sz_404[id_233] };
                    uint8_t id_235 { uint8_t(id_234) };
                    uint8_t id_236 { 128 };
                    uint8_t id_237 { uint8_t(id_235 | id_236) };
                    choose_res_229 = id_237;
                  }
                  Pointer id_238 { id_224.writeU8(choose_res_229) };
                  Void id_239 { ((void)(leb128_ptr_405[id_222] = id_238), VOID) };
                  (void)id_239;
                  uint8_t id_240 { 0 };
                  uint8_t id_241 { 0 };
                  uint32_t id_242 { leb128_sz_404[id_241] };
                  uint8_t id_243 { 7 };
                  uint32_t id_244 { uint32_t(id_242 >> id_243) };
                  Void id_245 { ((void)(leb128_sz_404[id_240] = id_244), VOID) };
                  (void)id_245;
                  uint8_t id_246 { 0 };
                  uint32_t id_247 { leb128_sz_404[id_246] };
                  uint32_t id_248 { 0U };
                  bool id_249 { bool(id_247 > id_248) };
                  while_flag_221 = id_249;
                  if (while_flag_221) {
                    (void)VOID;
                  }
                } while (while_flag_221);
                (void)VOID;
                uint8_t id_250 { 0 };
                Pointer id_251 { leb128_ptr_405[id_250] };
                let_res_220 = id_251;
              }
              let_res_218 = let_res_220;
            }
            Vec<1, Pointer> id_252 {  let_res_218  };
            Pointer let_res_253;
            {
              Vec<1, Pointer> dst_ref_406 { id_252 };
              int32_t id_254 { 0L };
              Vec<1, int32_t> id_255 {  id_254  };
              Pointer let_res_256;
              {
                Vec<1, int32_t> n_ref_407 { id_255 };
                t1f2a02f42faa570bd799752d94503c06 id_257 { p_0->detail };
                t67d467e776d7a3f3e54efabfd5f911ed id_258 { std::get<0>(id_257) };
                Lst<dessser::gen::global_variable::t_ext> id_259 { id_258.globals };
                for (dessser::gen::global_variable::t_ext x_408 : id_259) {
                  uint8_t id_260 { 0 };
                  auto fun261 { dessser::gen::global_variable::to_row_binary };
                  uint8_t id_262 { 0 };
                  Pointer id_263 { dst_ref_406[id_262] };
                  Pointer id_264 { fun261(x_408, id_263) };
                  Void id_265 { ((void)(dst_ref_406[id_260] = id_264), VOID) };
                  (void)id_265;
                  uint8_t id_266 { 0 };
                  int32_t id_267 { 1L };
                  uint8_t id_268 { 0 };
                  int32_t id_269 { n_ref_407[id_268] };
                  int32_t id_270 { int32_t(id_267 + id_269) };
                  Void id_271 { ((void)(n_ref_407[id_266] = id_270), VOID) };
                  (void)id_271;
                  (void)id_271;
                }
                (void)VOID;
                uint8_t id_272 { 0 };
                Pointer id_273 { dst_ref_406[id_272] };
                let_res_256 = id_273;
              }
              let_res_253 = let_res_256;
            }
            let_res_212 = let_res_253;
          }
          Pointer let_res_274;
          {
            Pointer srec_dst_409 { let_res_212 };
            t1f2a02f42faa570bd799752d94503c06 id_275 { p_0->detail };
            t67d467e776d7a3f3e54efabfd5f911ed id_276 { std::get<0>(id_275) };
            Lst<tb0a5947d2e730ef2c38de99be0c65701> id_277 { id_276.funcs };
            uint32_t id_278 { id_277.size() };
            Vec<1, uint32_t> id_279 {  id_278  };
            Pointer let_res_280;
            {
              Vec<1, uint32_t> leb128_sz_410 { id_279 };
              Vec<1, Pointer> id_281 {  srec_dst_409  };
              Pointer let_res_282;
              {
                Vec<1, Pointer> leb128_ptr_411 { id_281 };
                bool while_flag_283 { true };
                do {
                  uint8_t id_284 { 0 };
                  uint8_t id_285 { 0 };
                  Pointer id_286 { leb128_ptr_411[id_285] };
                  uint32_t id_287 { 128U };
                  uint8_t id_288 { 0 };
                  uint32_t id_289 { leb128_sz_410[id_288] };
                  bool id_290 { bool(id_287 > id_289) };
                  uint8_t choose_res_291;
                  if (id_290) {
                    uint8_t id_292 { 0 };
                    uint32_t id_293 { leb128_sz_410[id_292] };
                    uint8_t id_294 { uint8_t(id_293) };
                    choose_res_291 = id_294;
                  } else {
                    uint8_t id_295 { 0 };
                    uint32_t id_296 { leb128_sz_410[id_295] };
                    uint8_t id_297 { uint8_t(id_296) };
                    uint8_t id_298 { 128 };
                    uint8_t id_299 { uint8_t(id_297 | id_298) };
                    choose_res_291 = id_299;
                  }
                  Pointer id_300 { id_286.writeU8(choose_res_291) };
                  Void id_301 { ((void)(leb128_ptr_411[id_284] = id_300), VOID) };
                  (void)id_301;
                  uint8_t id_302 { 0 };
                  uint8_t id_303 { 0 };
                  uint32_t id_304 { leb128_sz_410[id_303] };
                  uint8_t id_305 { 7 };
                  uint32_t id_306 { uint32_t(id_304 >> id_305) };
                  Void id_307 { ((void)(leb128_sz_410[id_302] = id_306), VOID) };
                  (void)id_307;
                  uint8_t id_308 { 0 };
                  uint32_t id_309 { leb128_sz_410[id_308] };
                  uint32_t id_310 { 0U };
                  bool id_311 { bool(id_309 > id_310) };
                  while_flag_283 = id_311;
                  if (while_flag_283) {
                    (void)VOID;
                  }
                } while (while_flag_283);
                (void)VOID;
                uint8_t id_312 { 0 };
                Pointer id_313 { leb128_ptr_411[id_312] };
                let_res_282 = id_313;
              }
              let_res_280 = let_res_282;
            }
            Vec<1, Pointer> id_314 {  let_res_280  };
            Pointer let_res_315;
            {
              Vec<1, Pointer> dst_ref_412 { id_314 };
              int32_t id_316 { 0L };
              Vec<1, int32_t> id_317 {  id_316  };
              Pointer let_res_318;
              {
                Vec<1, int32_t> n_ref_413 { id_317 };
                t1f2a02f42faa570bd799752d94503c06 id_319 { p_0->detail };
                t67d467e776d7a3f3e54efabfd5f911ed id_320 { std::get<0>(id_319) };
                Lst<tb0a5947d2e730ef2c38de99be0c65701> id_321 { id_320.funcs };
                for (tb0a5947d2e730ef2c38de99be0c65701 x_414 : id_321) {
                  uint8_t id_322 { 0 };
                  uint8_t id_323 { 0 };
                  Pointer id_324 { dst_ref_412[id_323] };
                  Pointer let_res_325;
                  {
                    Pointer srec_dst_415 { id_324 };
                    auto fun326 { dessser::gen::function_name::to_row_binary };
                    dessser::gen::function_name::t_ext id_327 { x_414.name };
                    Pointer id_328 { fun326(id_327, srec_dst_415) };
                    let_res_325 = id_328;
                  }
                  Pointer let_res_329;
                  {
                    Pointer srec_dst_416 { let_res_325 };
                    std::optional<dessser::gen::retention::t_ext> id_330 { x_414.retention };
                    bool id_331 { !(id_330.has_value ()) };
                    Pointer choose_res_332;
                    if (id_331) {
                      uint8_t id_333 { 1 };
                      Pointer id_334 { srec_dst_416.writeU8(id_333) };
                      choose_res_332 = id_334;
                    } else {
                      auto fun335 { dessser::gen::retention::to_row_binary };
                      std::optional<dessser::gen::retention::t_ext> id_336 { x_414.retention };
                      dessser::gen::retention::t_ext id_337 { id_336.value() };
                      uint8_t id_338 { 0 };
                      Pointer id_339 { srec_dst_416.writeU8(id_338) };
                      Pointer id_340 { fun335(id_337, id_339) };
                      choose_res_332 = id_340;
                    }
                    let_res_329 = choose_res_332;
                  }
                  Pointer let_res_341;
                  {
                    Pointer srec_dst_417 { let_res_329 };
                    bool id_342 { x_414.is_lazy };
                    uint8_t id_343 { uint8_t(id_342) };
                    Pointer id_344 { srec_dst_417.writeU8(id_343) };
                    let_res_341 = id_344;
                  }
                  Pointer let_res_345;
                  {
                    Pointer srec_dst_418 { let_res_341 };
                    std::string id_346 { x_414.doc };
                    uint32_t id_347 { (uint32_t)id_346.size() };
                    Vec<1, uint32_t> id_348 {  id_347  };
                    Pointer let_res_349;
                    {
                      Vec<1, uint32_t> leb128_sz_419 { id_348 };
                      Vec<1, Pointer> id_350 {  srec_dst_418  };
                      Pointer let_res_351;
                      {
                        Vec<1, Pointer> leb128_ptr_420 { id_350 };
                        bool while_flag_352 { true };
                        do {
                          uint8_t id_353 { 0 };
                          uint8_t id_354 { 0 };
                          Pointer id_355 { leb128_ptr_420[id_354] };
                          uint32_t id_356 { 128U };
                          uint8_t id_357 { 0 };
                          uint32_t id_358 { leb128_sz_419[id_357] };
                          bool id_359 { bool(id_356 > id_358) };
                          uint8_t choose_res_360;
                          if (id_359) {
                            uint8_t id_361 { 0 };
                            uint32_t id_362 { leb128_sz_419[id_361] };
                            uint8_t id_363 { uint8_t(id_362) };
                            choose_res_360 = id_363;
                          } else {
                            uint8_t id_364 { 0 };
                            uint32_t id_365 { leb128_sz_419[id_364] };
                            uint8_t id_366 { uint8_t(id_365) };
                            uint8_t id_367 { 128 };
                            uint8_t id_368 { uint8_t(id_366 | id_367) };
                            choose_res_360 = id_368;
                          }
                          Pointer id_369 { id_355.writeU8(choose_res_360) };
                          Void id_370 { ((void)(leb128_ptr_420[id_353] = id_369), VOID) };
                          (void)id_370;
                          uint8_t id_371 { 0 };
                          uint8_t id_372 { 0 };
                          uint32_t id_373 { leb128_sz_419[id_372] };
                          uint8_t id_374 { 7 };
                          uint32_t id_375 { uint32_t(id_373 >> id_374) };
                          Void id_376 { ((void)(leb128_sz_419[id_371] = id_375), VOID) };
                          (void)id_376;
                          uint8_t id_377 { 0 };
                          uint32_t id_378 { leb128_sz_419[id_377] };
                          uint32_t id_379 { 0U };
                          bool id_380 { bool(id_378 > id_379) };
                          while_flag_352 = id_380;
                          if (while_flag_352) {
                            (void)VOID;
                          }
                        } while (while_flag_352);
                        (void)VOID;
                        uint8_t id_381 { 0 };
                        Pointer id_382 { leb128_ptr_420[id_381] };
                        let_res_351 = id_382;
                      }
                      let_res_349 = let_res_351;
                    }
                    std::string id_383 { x_414.doc };
                    Bytes id_384 { id_383 };
                    Pointer id_385 { let_res_349.writeBytes(id_384) };
                    let_res_345 = id_385;
                  }
                  Pointer let_res_386;
                  {
                    Pointer srec_dst_421 { let_res_345 };
                    auto fun387 { dessser::gen::raql_operation::to_row_binary };
                    dessser::gen::raql_operation::t_ext id_388 { x_414.operation };
                    Pointer id_389 { fun387(id_388, srec_dst_421) };
                    let_res_386 = id_389;
                  }
                  Pointer let_res_390;
                  {
                    Pointer srec_dst_422 { let_res_386 };
                    auto fun391 { dessser::gen::raql_type::to_row_binary };
                    dessser::gen::raql_type::t_ext id_392 { x_414.out_record };
                    Pointer id_393 { fun391(id_392, srec_dst_422) };
                    let_res_390 = id_393;
                  }
                  Pointer let_res_394;
                  {
                    Pointer srec_dst_423 { let_res_390 };
                    Lst<dessser::gen::field_name::t_ext> id_395 { x_414.factors };
                    uint32_t id_396 { id_395.size() };
                    Vec<1, uint32_t> id_397 {  id_396  };
                    Pointer let_res_398;
                    {
                      Vec<1, uint32_t> leb128_sz_424 { id_397 };
                      Vec<1, Pointer> id_399 {  srec_dst_423  };
                      Pointer let_res_400;
                      {
                        Vec<1, Pointer> leb128_ptr_425 { id_399 };
                        bool while_flag_401 { true };
                        do {
                          uint8_t id_402 { 0 };
                          uint8_t id_403 { 0 };
                          Pointer id_404 { leb128_ptr_425[id_403] };
                          uint32_t id_405 { 128U };
                          uint8_t id_406 { 0 };
                          uint32_t id_407 { leb128_sz_424[id_406] };
                          bool id_408 { bool(id_405 > id_407) };
                          uint8_t choose_res_409;
                          if (id_408) {
                            uint8_t id_410 { 0 };
                            uint32_t id_411 { leb128_sz_424[id_410] };
                            uint8_t id_412 { uint8_t(id_411) };
                            choose_res_409 = id_412;
                          } else {
                            uint8_t id_413 { 0 };
                            uint32_t id_414 { leb128_sz_424[id_413] };
                            uint8_t id_415 { uint8_t(id_414) };
                            uint8_t id_416 { 128 };
                            uint8_t id_417 { uint8_t(id_415 | id_416) };
                            choose_res_409 = id_417;
                          }
                          Pointer id_418 { id_404.writeU8(choose_res_409) };
                          Void id_419 { ((void)(leb128_ptr_425[id_402] = id_418), VOID) };
                          (void)id_419;
                          uint8_t id_420 { 0 };
                          uint8_t id_421 { 0 };
                          uint32_t id_422 { leb128_sz_424[id_421] };
                          uint8_t id_423 { 7 };
                          uint32_t id_424 { uint32_t(id_422 >> id_423) };
                          Void id_425 { ((void)(leb128_sz_424[id_420] = id_424), VOID) };
                          (void)id_425;
                          uint8_t id_426 { 0 };
                          uint32_t id_427 { leb128_sz_424[id_426] };
                          uint32_t id_428 { 0U };
                          bool id_429 { bool(id_427 > id_428) };
                          while_flag_401 = id_429;
                          if (while_flag_401) {
                            (void)VOID;
                          }
                        } while (while_flag_401);
                        (void)VOID;
                        uint8_t id_430 { 0 };
                        Pointer id_431 { leb128_ptr_425[id_430] };
                        let_res_400 = id_431;
                      }
                      let_res_398 = let_res_400;
                    }
                    Vec<1, Pointer> id_432 {  let_res_398  };
                    Pointer let_res_433;
                    {
                      Vec<1, Pointer> dst_ref_426 { id_432 };
                      int32_t id_434 { 0L };
                      Vec<1, int32_t> id_435 {  id_434  };
                      Pointer let_res_436;
                      {
                        Vec<1, int32_t> n_ref_427 { id_435 };
                        Lst<dessser::gen::field_name::t_ext> id_437 { x_414.factors };
                        for (dessser::gen::field_name::t_ext x_428 : id_437) {
                          uint8_t id_438 { 0 };
                          auto fun439 { dessser::gen::field_name::to_row_binary };
                          uint8_t id_440 { 0 };
                          Pointer id_441 { dst_ref_426[id_440] };
                          Pointer id_442 { fun439(x_428, id_441) };
                          Void id_443 { ((void)(dst_ref_426[id_438] = id_442), VOID) };
                          (void)id_443;
                          uint8_t id_444 { 0 };
                          int32_t id_445 { 1L };
                          uint8_t id_446 { 0 };
                          int32_t id_447 { n_ref_427[id_446] };
                          int32_t id_448 { int32_t(id_445 + id_447) };
                          Void id_449 { ((void)(n_ref_427[id_444] = id_448), VOID) };
                          (void)id_449;
                          (void)id_449;
                        }
                        (void)VOID;
                        uint8_t id_450 { 0 };
                        Pointer id_451 { dst_ref_426[id_450] };
                        let_res_436 = id_451;
                      }
                      let_res_433 = let_res_436;
                    }
                    let_res_394 = let_res_433;
                  }
                  Pointer let_res_452;
                  {
                    Pointer srec_dst_429 { let_res_394 };
                    std::string id_453 { x_414.signature };
                    uint32_t id_454 { (uint32_t)id_453.size() };
                    Vec<1, uint32_t> id_455 {  id_454  };
                    Pointer let_res_456;
                    {
                      Vec<1, uint32_t> leb128_sz_430 { id_455 };
                      Vec<1, Pointer> id_457 {  srec_dst_429  };
                      Pointer let_res_458;
                      {
                        Vec<1, Pointer> leb128_ptr_431 { id_457 };
                        bool while_flag_459 { true };
                        do {
                          uint8_t id_460 { 0 };
                          uint8_t id_461 { 0 };
                          Pointer id_462 { leb128_ptr_431[id_461] };
                          uint32_t id_463 { 128U };
                          uint8_t id_464 { 0 };
                          uint32_t id_465 { leb128_sz_430[id_464] };
                          bool id_466 { bool(id_463 > id_465) };
                          uint8_t choose_res_467;
                          if (id_466) {
                            uint8_t id_468 { 0 };
                            uint32_t id_469 { leb128_sz_430[id_468] };
                            uint8_t id_470 { uint8_t(id_469) };
                            choose_res_467 = id_470;
                          } else {
                            uint8_t id_471 { 0 };
                            uint32_t id_472 { leb128_sz_430[id_471] };
                            uint8_t id_473 { uint8_t(id_472) };
                            uint8_t id_474 { 128 };
                            uint8_t id_475 { uint8_t(id_473 | id_474) };
                            choose_res_467 = id_475;
                          }
                          Pointer id_476 { id_462.writeU8(choose_res_467) };
                          Void id_477 { ((void)(leb128_ptr_431[id_460] = id_476), VOID) };
                          (void)id_477;
                          uint8_t id_478 { 0 };
                          uint8_t id_479 { 0 };
                          uint32_t id_480 { leb128_sz_430[id_479] };
                          uint8_t id_481 { 7 };
                          uint32_t id_482 { uint32_t(id_480 >> id_481) };
                          Void id_483 { ((void)(leb128_sz_430[id_478] = id_482), VOID) };
                          (void)id_483;
                          uint8_t id_484 { 0 };
                          uint32_t id_485 { leb128_sz_430[id_484] };
                          uint32_t id_486 { 0U };
                          bool id_487 { bool(id_485 > id_486) };
                          while_flag_459 = id_487;
                          if (while_flag_459) {
                            (void)VOID;
                          }
                        } while (while_flag_459);
                        (void)VOID;
                        uint8_t id_488 { 0 };
                        Pointer id_489 { leb128_ptr_431[id_488] };
                        let_res_458 = id_489;
                      }
                      let_res_456 = let_res_458;
                    }
                    std::string id_490 { x_414.signature };
                    Bytes id_491 { id_490 };
                    Pointer id_492 { let_res_456.writeBytes(id_491) };
                    let_res_452 = id_492;
                  }
                  Pointer let_res_493;
                  {
                    Pointer srec_dst_432 { let_res_452 };
                    std::string id_494 { x_414.in_signature };
                    uint32_t id_495 { (uint32_t)id_494.size() };
                    Vec<1, uint32_t> id_496 {  id_495  };
                    Pointer let_res_497;
                    {
                      Vec<1, uint32_t> leb128_sz_433 { id_496 };
                      Vec<1, Pointer> id_498 {  srec_dst_432  };
                      Pointer let_res_499;
                      {
                        Vec<1, Pointer> leb128_ptr_434 { id_498 };
                        bool while_flag_500 { true };
                        do {
                          uint8_t id_501 { 0 };
                          uint8_t id_502 { 0 };
                          Pointer id_503 { leb128_ptr_434[id_502] };
                          uint32_t id_504 { 128U };
                          uint8_t id_505 { 0 };
                          uint32_t id_506 { leb128_sz_433[id_505] };
                          bool id_507 { bool(id_504 > id_506) };
                          uint8_t choose_res_508;
                          if (id_507) {
                            uint8_t id_509 { 0 };
                            uint32_t id_510 { leb128_sz_433[id_509] };
                            uint8_t id_511 { uint8_t(id_510) };
                            choose_res_508 = id_511;
                          } else {
                            uint8_t id_512 { 0 };
                            uint32_t id_513 { leb128_sz_433[id_512] };
                            uint8_t id_514 { uint8_t(id_513) };
                            uint8_t id_515 { 128 };
                            uint8_t id_516 { uint8_t(id_514 | id_515) };
                            choose_res_508 = id_516;
                          }
                          Pointer id_517 { id_503.writeU8(choose_res_508) };
                          Void id_518 { ((void)(leb128_ptr_434[id_501] = id_517), VOID) };
                          (void)id_518;
                          uint8_t id_519 { 0 };
                          uint8_t id_520 { 0 };
                          uint32_t id_521 { leb128_sz_433[id_520] };
                          uint8_t id_522 { 7 };
                          uint32_t id_523 { uint32_t(id_521 >> id_522) };
                          Void id_524 { ((void)(leb128_sz_433[id_519] = id_523), VOID) };
                          (void)id_524;
                          uint8_t id_525 { 0 };
                          uint32_t id_526 { leb128_sz_433[id_525] };
                          uint32_t id_527 { 0U };
                          bool id_528 { bool(id_526 > id_527) };
                          while_flag_500 = id_528;
                          if (while_flag_500) {
                            (void)VOID;
                          }
                        } while (while_flag_500);
                        (void)VOID;
                        uint8_t id_529 { 0 };
                        Pointer id_530 { leb128_ptr_434[id_529] };
                        let_res_499 = id_530;
                      }
                      let_res_497 = let_res_499;
                    }
                    std::string id_531 { x_414.in_signature };
                    Bytes id_532 { id_531 };
                    Pointer id_533 { let_res_497.writeBytes(id_532) };
                    let_res_493 = id_533;
                  }
                  Void id_534 { ((void)(dst_ref_412[id_322] = let_res_493), VOID) };
                  (void)id_534;
                  uint8_t id_535 { 0 };
                  int32_t id_536 { 1L };
                  uint8_t id_537 { 0 };
                  int32_t id_538 { n_ref_413[id_537] };
                  int32_t id_539 { int32_t(id_536 + id_538) };
                  Void id_540 { ((void)(n_ref_413[id_535] = id_539), VOID) };
                  (void)id_540;
                  (void)id_540;
                }
                (void)VOID;
                uint8_t id_541 { 0 };
                Pointer id_542 { dst_ref_412[id_541] };
                let_res_318 = id_542;
              }
              let_res_315 = let_res_318;
            }
            let_res_274 = let_res_315;
          }
          choose_res_144 = let_res_274;
        } else {
          t1f2a02f42faa570bd799752d94503c06 id_543 { p_0->detail };
          uint16_t id_544 { uint16_t(id_543.index()) };
          uint16_t id_545 { 1 };
          bool id_546 { bool(id_544 == id_545) };
          Void id_547 { ((void)(assert(id_546)), VOID) };
          (void)id_547;
          t1f2a02f42faa570bd799752d94503c06 id_548 { p_0->detail };
          t0fbe0ba3da9da3292ae419be74c6cc6e id_549 { std::get<1>(id_548) };
          std::string id_550 { id_549.err_msg };
          uint32_t id_551 { (uint32_t)id_550.size() };
          Vec<1, uint32_t> id_552 {  id_551  };
          Pointer let_res_553;
          {
            Vec<1, uint32_t> leb128_sz_394 { id_552 };
            Vec<1, Pointer> id_554 {  ssum_dst_393  };
            Pointer let_res_555;
            {
              Vec<1, Pointer> leb128_ptr_395 { id_554 };
              bool while_flag_556 { true };
              do {
                uint8_t id_557 { 0 };
                uint8_t id_558 { 0 };
                Pointer id_559 { leb128_ptr_395[id_558] };
                uint32_t id_560 { 128U };
                uint8_t id_561 { 0 };
                uint32_t id_562 { leb128_sz_394[id_561] };
                bool id_563 { bool(id_560 > id_562) };
                uint8_t choose_res_564;
                if (id_563) {
                  uint8_t id_565 { 0 };
                  uint32_t id_566 { leb128_sz_394[id_565] };
                  uint8_t id_567 { uint8_t(id_566) };
                  choose_res_564 = id_567;
                } else {
                  uint8_t id_568 { 0 };
                  uint32_t id_569 { leb128_sz_394[id_568] };
                  uint8_t id_570 { uint8_t(id_569) };
                  uint8_t id_571 { 128 };
                  uint8_t id_572 { uint8_t(id_570 | id_571) };
                  choose_res_564 = id_572;
                }
                Pointer id_573 { id_559.writeU8(choose_res_564) };
                Void id_574 { ((void)(leb128_ptr_395[id_557] = id_573), VOID) };
                (void)id_574;
                uint8_t id_575 { 0 };
                uint8_t id_576 { 0 };
                uint32_t id_577 { leb128_sz_394[id_576] };
                uint8_t id_578 { 7 };
                uint32_t id_579 { uint32_t(id_577 >> id_578) };
                Void id_580 { ((void)(leb128_sz_394[id_575] = id_579), VOID) };
                (void)id_580;
                uint8_t id_581 { 0 };
                uint32_t id_582 { leb128_sz_394[id_581] };
                uint32_t id_583 { 0U };
                bool id_584 { bool(id_582 > id_583) };
                while_flag_556 = id_584;
                if (while_flag_556) {
                  (void)VOID;
                }
              } while (while_flag_556);
              (void)VOID;
              uint8_t id_585 { 0 };
              Pointer id_586 { leb128_ptr_395[id_585] };
              let_res_555 = id_586;
            }
            let_res_553 = let_res_555;
          }
          t1f2a02f42faa570bd799752d94503c06 id_587 { p_0->detail };
          t0fbe0ba3da9da3292ae419be74c6cc6e id_588 { std::get<1>(id_587) };
          std::string id_589 { id_588.err_msg };
          Bytes id_590 { id_589 };
          Pointer id_591 { let_res_553.writeBytes(id_590) };
          Pointer let_res_592;
          {
            Pointer srec_dst_396 { id_591 };
            t1f2a02f42faa570bd799752d94503c06 id_593 { p_0->detail };
            t0fbe0ba3da9da3292ae419be74c6cc6e id_594 { std::get<1>(id_593) };
            std::optional<dessser::gen::src_path::t_ext> id_595 { id_594.depends_on };
            bool id_596 { !(id_595.has_value ()) };
            Pointer choose_res_597;
            if (id_596) {
              uint8_t id_598 { 1 };
              Pointer id_599 { srec_dst_396.writeU8(id_598) };
              choose_res_597 = id_599;
            } else {
              auto fun600 { dessser::gen::src_path::to_row_binary };
              t1f2a02f42faa570bd799752d94503c06 id_601 { p_0->detail };
              t0fbe0ba3da9da3292ae419be74c6cc6e id_602 { std::get<1>(id_601) };
              std::optional<dessser::gen::src_path::t_ext> id_603 { id_602.depends_on };
              dessser::gen::src_path::t_ext id_604 { id_603.value() };
              uint8_t id_605 { 0 };
              Pointer id_606 { srec_dst_396.writeU8(id_605) };
              Pointer id_607 { fun600(id_604, id_606) };
              choose_res_597 = id_607;
            }
            let_res_592 = choose_res_597;
          }
          choose_res_144 = let_res_592;
        }
        let_res_139 = choose_res_144;
      }
      let_res_135 = let_res_139;
    }
    return let_res_135;
  }
   };
  return fun0;
}
std::function<Pointer(t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{src_ext: STRING; md5s: STRING[[]]; detail: [Compiled {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}[[]]} | Failed {err_msg: STRING; depends_on: $src_path?}]}")
      (let "sz_336"
        (let "sz_328"
          (add
            (let "n_ref_326" (make-vec (string-length (get-field "src_ext" (param 0))))
              (let "lebsz_ref_327" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_326")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_327")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_327") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_327")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_327")))))) 
            (size-of-u32 (string-length (get-field "src_ext" (param 0)))))
          (let "sz_ref_331"
            (make-vec
              (add (identifier "sz_328")
                (let "n_ref_329" (make-vec (cardinality (get-field "md5s" (param 0))))
                  (let "lebsz_ref_330" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_329")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_330")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_330") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_330")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_330"))))))))
            (seq
              (let "repeat_n_332" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "md5s" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_332")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_331")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_331"))
                        (let "wlen_333" (string-length (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_332")) (get-field "md5s" (param 0))))
                          (add
                            (let "n_ref_334" (make-vec (identifier "wlen_333"))
                              (let "lebsz_ref_335" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_334")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_335")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_335") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_335")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_335")))))) 
                            (size-of-u32 (identifier "wlen_333")))))) 
                    (set-vec (u8 0) (identifier "repeat_n_332") (add (unsafe-nth (u8 0) (identifier "repeat_n_332")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_331")))))
        (if (eq (u16 0) (label-of (get-field "detail" (param 0))))
          (let "sz_354"
            (let "sz_349"
              (let "sz_348"
                (let "sz_ref_346"
                  (make-vec
                    (add (add (identifier "sz_336") (size 2))
                      (let "n_ref_344" (make-vec (cardinality (get-field "default_params" (get-alt "Compiled" (get-field "detail" (param 0))))))
                        (let "lebsz_ref_345" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_344")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_345")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_345") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_345")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_345"))))))))
                  (seq
                    (let "repeat_n_347" (make-vec (i32 0))
                      (while (gt (to-i32 (cardinality (get-field "default_params" (get-alt "Compiled" (get-field "detail" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_347")))
                        (seq
                          (set-vec (u8 0) (identifier "sz_ref_346")
                            (add (unsafe-nth (u8 0) (identifier "sz_ref_346"))
                              (apply (ext-identifier program_parameter sersize-of-row-binary)
                                (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_347")) (get-field "default_params" (get-alt "Compiled" (get-field "detail" (param 0))))))))
                          (set-vec (u8 0) (identifier "repeat_n_347") (add (unsafe-nth (u8 0) (identifier "repeat_n_347")) (i32 1)))))) 
                    (unsafe-nth (u8 0) (identifier "sz_ref_346")))) (add (identifier "sz_348") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "condition" (get-alt "Compiled" (get-field "detail" (param 0)))))))
              (let "sz_ref_352"
                (make-vec
                  (add (identifier "sz_349")
                    (let "n_ref_350" (make-vec (cardinality (get-field "globals" (get-alt "Compiled" (get-field "detail" (param 0))))))
                      (let "lebsz_ref_351" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_350")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_351")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_351") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_351")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_351"))))))))
                (seq
                  (let "repeat_n_353" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "globals" (get-alt "Compiled" (get-field "detail" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_353")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_352")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_352"))
                            (apply (ext-identifier global_variable sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_353")) (get-field "globals" (get-alt "Compiled" (get-field "detail" (param 0))))))))
                        (set-vec (u8 0) (identifier "repeat_n_353") (add (unsafe-nth (u8 0) (identifier "repeat_n_353")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_352")))))
            (let "sz_ref_357"
              (make-vec
                (add (identifier "sz_354")
                  (let "n_ref_355" (make-vec (cardinality (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0))))))
                    (let "lebsz_ref_356" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_355")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_356")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_356") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_356")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_356"))))))))
              (seq
                (let "repeat_n_358" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_358")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_357")
                        (let "sz_377"
                          (let "sz_373"
                            (let "sz_368"
                              (let "sz_367"
                                (let "sz_366"
                                  (let "sz_362"
                                    (add
                                      (let "sz_360"
                                        (let "sz_359" (unsafe-nth (u8 0) (identifier "sz_ref_357"))
                                          (add (identifier "sz_359")
                                            (apply (ext-identifier function_name sersize-of-row-binary)
                                              (get-field "name" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0)))))))))
                                        (if (is-null (get-field "retention" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0)))))))
                                          (add (identifier "sz_360") (size 1))
                                          (add
                                            (add (identifier "sz_360")
                                              (apply (ext-identifier retention sersize-of-row-binary)
                                                (force (get-field "retention" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0))))))))) 
                                            (size 1)))) (size 1))
                                    (add (identifier "sz_362")
                                      (let "wlen_363" (string-length (get-field "doc" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0)))))))
                                        (add
                                          (let "n_ref_364" (make-vec (identifier "wlen_363"))
                                            (let "lebsz_ref_365" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_364")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_365")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_365") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_365")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_365")))))) 
                                          (size-of-u32 (identifier "wlen_363"))))))
                                  (add (identifier "sz_366")
                                    (apply (ext-identifier raql_operation sersize-of-row-binary)
                                      (get-field "operation" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0)))))))))
                                (add (identifier "sz_367")
                                  (apply (ext-identifier raql_type sersize-of-row-binary)
                                    (get-field "out_record" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0)))))))))
                              (let "sz_ref_371"
                                (make-vec
                                  (add (identifier "sz_368")
                                    (let "n_ref_369"
                                      (make-vec (cardinality (get-field "factors" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0))))))))
                                      (let "lebsz_ref_370" (make-vec (u32 1))
                                        (seq
                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_369")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_370")) (u8 7)))
                                            (set-vec (u8 0) (identifier "lebsz_ref_370") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_370")) (u32 1)))) 
                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_370"))))))))
                                (seq
                                  (let "repeat_n_372" (make-vec (i32 0))
                                    (while
                                      (gt (to-i32 (cardinality (get-field "factors" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0))))))))
                                        (unsafe-nth (u8 0) (identifier "repeat_n_372")))
                                      (seq
                                        (set-vec (u8 0) (identifier "sz_ref_371")
                                          (add (unsafe-nth (u8 0) (identifier "sz_ref_371"))
                                            (apply (ext-identifier field_name sersize-of-row-binary)
                                              (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_372"))
                                                (get-field "factors" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0))))))))))
                                        (set-vec (u8 0) (identifier "repeat_n_372") (add (unsafe-nth (u8 0) (identifier "repeat_n_372")) (i32 1)))))) 
                                  (unsafe-nth (u8 0) (identifier "sz_ref_371")))))
                            (add (identifier "sz_373")
                              (let "wlen_374" (string-length (get-field "signature" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0)))))))
                                (add
                                  (let "n_ref_375" (make-vec (identifier "wlen_374"))
                                    (let "lebsz_ref_376" (make-vec (u32 1))
                                      (seq
                                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_375")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_376")) (u8 7)))
                                          (set-vec (u8 0) (identifier "lebsz_ref_376") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_376")) (u32 1)))) 
                                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_376")))))) 
                                  (size-of-u32 (identifier "wlen_374"))))))
                          (add (identifier "sz_377")
                            (let "wlen_378" (string-length (get-field "in_signature" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_358")) (get-field "funcs" (get-alt "Compiled" (get-field "detail" (param 0)))))))
                              (add
                                (let "n_ref_379" (make-vec (identifier "wlen_378"))
                                  (let "lebsz_ref_380" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_379")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_380")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_380") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_380")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_380")))))) 
                                (size-of-u32 (identifier "wlen_378"))))))) 
                      (set-vec (u8 0) (identifier "repeat_n_358") (add (unsafe-nth (u8 0) (identifier "repeat_n_358")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_357")))))
          (seq (assert (eq (label-of (get-field "detail" (param 0))) (u16 1)))
            (let "sz_342"
              (add (add (identifier "sz_336") (size 2))
                (add
                  (let "n_ref_340" (make-vec (string-length (get-field "err_msg" (get-alt "Failed" (get-field "detail" (param 0))))))
                    (let "lebsz_ref_341" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_340")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_341")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_341") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_341")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_341")))))) 
                  (size-of-u32 (string-length (get-field "err_msg" (get-alt "Failed" (get-field "detail" (param 0))))))))
              (if (is-null (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))) 
                (add (identifier "sz_342") (size 1))
                (add (add (identifier "sz_342") (apply (ext-identifier src_path sersize-of-row-binary) (force (get-field "depends_on" (get-alt "Failed" (get-field "detail" (param 0))))))) (size 1))))))))
 */
static std::function<Size(t*)> sersize_of_row_binary_init()
{
  std::function<Size(t*)> fun608 { [&fun608](t* p_0) {
    std::string id_609 { p_0->src_ext };
    uint32_t id_610 { (uint32_t)id_609.size() };
    Vec<1, uint32_t> id_611 {  id_610  };
    Size let_res_612;
    {
      Vec<1, uint32_t> n_ref_326 { id_611 };
      uint32_t id_613 { 1U };
      Vec<1, uint32_t> id_614 {  id_613  };
      Size let_res_615;
      {
        Vec<1, uint32_t> lebsz_ref_327 { id_614 };
        bool while_flag_616 { true };
        do {
          uint8_t id_617 { 0 };
          uint32_t id_618 { n_ref_326[id_617] };
          uint8_t id_619 { 0 };
          uint32_t id_620 { lebsz_ref_327[id_619] };
          uint8_t id_621 { 7 };
          uint32_t id_622 { uint32_t(id_620 << id_621) };
          bool id_623 { bool(id_618 >= id_622) };
          while_flag_616 = id_623;
          if (while_flag_616) {
            uint8_t id_624 { 0 };
            uint8_t id_625 { 0 };
            uint32_t id_626 { lebsz_ref_327[id_625] };
            uint32_t id_627 { 1U };
            uint32_t id_628 { uint32_t(id_626 + id_627) };
            Void id_629 { ((void)(lebsz_ref_327[id_624] = id_628), VOID) };
            (void)id_629;
          }
        } while (while_flag_616);
        (void)VOID;
        uint8_t id_630 { 0 };
        uint32_t id_631 { lebsz_ref_327[id_630] };
        Size id_632 { Size(id_631) };
        let_res_615 = id_632;
      }
      let_res_612 = let_res_615;
    }
    std::string id_633 { p_0->src_ext };
    uint32_t id_634 { (uint32_t)id_633.size() };
    Size id_635 { Size(id_634) };
    Size id_636 { Size(let_res_612 + id_635) };
    Size let_res_637;
    {
      Size sz_328 { id_636 };
      Lst<std::string> id_638 { p_0->md5s };
      uint32_t id_639 { id_638.size() };
      Vec<1, uint32_t> id_640 {  id_639  };
      Size let_res_641;
      {
        Vec<1, uint32_t> n_ref_329 { id_640 };
        uint32_t id_642 { 1U };
        Vec<1, uint32_t> id_643 {  id_642  };
        Size let_res_644;
        {
          Vec<1, uint32_t> lebsz_ref_330 { id_643 };
          bool while_flag_645 { true };
          do {
            uint8_t id_646 { 0 };
            uint32_t id_647 { n_ref_329[id_646] };
            uint8_t id_648 { 0 };
            uint32_t id_649 { lebsz_ref_330[id_648] };
            uint8_t id_650 { 7 };
            uint32_t id_651 { uint32_t(id_649 << id_650) };
            bool id_652 { bool(id_647 >= id_651) };
            while_flag_645 = id_652;
            if (while_flag_645) {
              uint8_t id_653 { 0 };
              uint8_t id_654 { 0 };
              uint32_t id_655 { lebsz_ref_330[id_654] };
              uint32_t id_656 { 1U };
              uint32_t id_657 { uint32_t(id_655 + id_656) };
              Void id_658 { ((void)(lebsz_ref_330[id_653] = id_657), VOID) };
              (void)id_658;
            }
          } while (while_flag_645);
          (void)VOID;
          uint8_t id_659 { 0 };
          uint32_t id_660 { lebsz_ref_330[id_659] };
          Size id_661 { Size(id_660) };
          let_res_644 = id_661;
        }
        let_res_641 = let_res_644;
      }
      Size id_662 { Size(sz_328 + let_res_641) };
      Vec<1, Size> id_663 {  id_662  };
      Size let_res_664;
      {
        Vec<1, Size> sz_ref_331 { id_663 };
        int32_t id_665 { 0L };
        Vec<1, int32_t> id_666 {  id_665  };
        {
          Vec<1, int32_t> repeat_n_332 { id_666 };
          bool while_flag_667 { true };
          do {
            Lst<std::string> id_668 { p_0->md5s };
            uint32_t id_669 { id_668.size() };
            int32_t id_670 { int32_t(id_669) };
            uint8_t id_671 { 0 };
            int32_t id_672 { repeat_n_332[id_671] };
            bool id_673 { bool(id_670 > id_672) };
            while_flag_667 = id_673;
            if (while_flag_667) {
              uint8_t id_674 { 0 };
              uint8_t id_675 { 0 };
              Size id_676 { sz_ref_331[id_675] };
              uint8_t id_677 { 0 };
              int32_t id_678 { repeat_n_332[id_677] };
              Lst<std::string> id_679 { p_0->md5s };
              std::string id_680 { id_679[id_678] };
              uint32_t id_681 { (uint32_t)id_680.size() };
              Size let_res_682;
              {
                uint32_t wlen_333 { id_681 };
                Vec<1, uint32_t> id_683 {  wlen_333  };
                Size let_res_684;
                {
                  Vec<1, uint32_t> n_ref_334 { id_683 };
                  uint32_t id_685 { 1U };
                  Vec<1, uint32_t> id_686 {  id_685  };
                  Size let_res_687;
                  {
                    Vec<1, uint32_t> lebsz_ref_335 { id_686 };
                    bool while_flag_688 { true };
                    do {
                      uint8_t id_689 { 0 };
                      uint32_t id_690 { n_ref_334[id_689] };
                      uint8_t id_691 { 0 };
                      uint32_t id_692 { lebsz_ref_335[id_691] };
                      uint8_t id_693 { 7 };
                      uint32_t id_694 { uint32_t(id_692 << id_693) };
                      bool id_695 { bool(id_690 >= id_694) };
                      while_flag_688 = id_695;
                      if (while_flag_688) {
                        uint8_t id_696 { 0 };
                        uint8_t id_697 { 0 };
                        uint32_t id_698 { lebsz_ref_335[id_697] };
                        uint32_t id_699 { 1U };
                        uint32_t id_700 { uint32_t(id_698 + id_699) };
                        Void id_701 { ((void)(lebsz_ref_335[id_696] = id_700), VOID) };
                        (void)id_701;
                      }
                    } while (while_flag_688);
                    (void)VOID;
                    uint8_t id_702 { 0 };
                    uint32_t id_703 { lebsz_ref_335[id_702] };
                    Size id_704 { Size(id_703) };
                    let_res_687 = id_704;
                  }
                  let_res_684 = let_res_687;
                }
                Size id_705 { Size(wlen_333) };
                Size id_706 { Size(let_res_684 + id_705) };
                let_res_682 = id_706;
              }
              Size id_707 { Size(id_676 + let_res_682) };
              Void id_708 { ((void)(sz_ref_331[id_674] = id_707), VOID) };
              (void)id_708;
              uint8_t id_709 { 0 };
              uint8_t id_710 { 0 };
              int32_t id_711 { repeat_n_332[id_710] };
              int32_t id_712 { 1L };
              int32_t id_713 { int32_t(id_711 + id_712) };
              Void id_714 { ((void)(repeat_n_332[id_709] = id_713), VOID) };
              (void)id_714;
              (void)id_714;
            }
          } while (while_flag_667);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_715 { 0 };
        Size id_716 { sz_ref_331[id_715] };
        let_res_664 = id_716;
      }
      let_res_637 = let_res_664;
    }
    Size let_res_717;
    {
      Size sz_336 { let_res_637 };
      uint16_t id_718 { 0 };
      t1f2a02f42faa570bd799752d94503c06 id_719 { p_0->detail };
      uint16_t id_720 { uint16_t(id_719.index()) };
      bool id_721 { bool(id_718 == id_720) };
      Size choose_res_722;
      if (id_721) {
        Size id_723 { 2UL };
        Size id_724 { Size(sz_336 + id_723) };
        t1f2a02f42faa570bd799752d94503c06 id_725 { p_0->detail };
        t67d467e776d7a3f3e54efabfd5f911ed id_726 { std::get<0>(id_725) };
        Lst<dessser::gen::program_parameter::t_ext> id_727 { id_726.default_params };
        uint32_t id_728 { id_727.size() };
        Vec<1, uint32_t> id_729 {  id_728  };
        Size let_res_730;
        {
          Vec<1, uint32_t> n_ref_344 { id_729 };
          uint32_t id_731 { 1U };
          Vec<1, uint32_t> id_732 {  id_731  };
          Size let_res_733;
          {
            Vec<1, uint32_t> lebsz_ref_345 { id_732 };
            bool while_flag_734 { true };
            do {
              uint8_t id_735 { 0 };
              uint32_t id_736 { n_ref_344[id_735] };
              uint8_t id_737 { 0 };
              uint32_t id_738 { lebsz_ref_345[id_737] };
              uint8_t id_739 { 7 };
              uint32_t id_740 { uint32_t(id_738 << id_739) };
              bool id_741 { bool(id_736 >= id_740) };
              while_flag_734 = id_741;
              if (while_flag_734) {
                uint8_t id_742 { 0 };
                uint8_t id_743 { 0 };
                uint32_t id_744 { lebsz_ref_345[id_743] };
                uint32_t id_745 { 1U };
                uint32_t id_746 { uint32_t(id_744 + id_745) };
                Void id_747 { ((void)(lebsz_ref_345[id_742] = id_746), VOID) };
                (void)id_747;
              }
            } while (while_flag_734);
            (void)VOID;
            uint8_t id_748 { 0 };
            uint32_t id_749 { lebsz_ref_345[id_748] };
            Size id_750 { Size(id_749) };
            let_res_733 = id_750;
          }
          let_res_730 = let_res_733;
        }
        Size id_751 { Size(id_724 + let_res_730) };
        Vec<1, Size> id_752 {  id_751  };
        Size let_res_753;
        {
          Vec<1, Size> sz_ref_346 { id_752 };
          int32_t id_754 { 0L };
          Vec<1, int32_t> id_755 {  id_754  };
          {
            Vec<1, int32_t> repeat_n_347 { id_755 };
            bool while_flag_756 { true };
            do {
              t1f2a02f42faa570bd799752d94503c06 id_757 { p_0->detail };
              t67d467e776d7a3f3e54efabfd5f911ed id_758 { std::get<0>(id_757) };
              Lst<dessser::gen::program_parameter::t_ext> id_759 { id_758.default_params };
              uint32_t id_760 { id_759.size() };
              int32_t id_761 { int32_t(id_760) };
              uint8_t id_762 { 0 };
              int32_t id_763 { repeat_n_347[id_762] };
              bool id_764 { bool(id_761 > id_763) };
              while_flag_756 = id_764;
              if (while_flag_756) {
                uint8_t id_765 { 0 };
                uint8_t id_766 { 0 };
                Size id_767 { sz_ref_346[id_766] };
                auto fun768 { dessser::gen::program_parameter::sersize_of_row_binary };
                uint8_t id_769 { 0 };
                int32_t id_770 { repeat_n_347[id_769] };
                t1f2a02f42faa570bd799752d94503c06 id_771 { p_0->detail };
                t67d467e776d7a3f3e54efabfd5f911ed id_772 { std::get<0>(id_771) };
                Lst<dessser::gen::program_parameter::t_ext> id_773 { id_772.default_params };
                dessser::gen::program_parameter::t_ext id_774 { id_773[id_770] };
                Size id_775 { fun768(id_774) };
                Size id_776 { Size(id_767 + id_775) };
                Void id_777 { ((void)(sz_ref_346[id_765] = id_776), VOID) };
                (void)id_777;
                uint8_t id_778 { 0 };
                uint8_t id_779 { 0 };
                int32_t id_780 { repeat_n_347[id_779] };
                int32_t id_781 { 1L };
                int32_t id_782 { int32_t(id_780 + id_781) };
                Void id_783 { ((void)(repeat_n_347[id_778] = id_782), VOID) };
                (void)id_783;
                (void)id_783;
              }
            } while (while_flag_756);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_784 { 0 };
          Size id_785 { sz_ref_346[id_784] };
          let_res_753 = id_785;
        }
        Size let_res_786;
        {
          Size sz_348 { let_res_753 };
          auto fun787 { dessser::gen::raql_expr::sersize_of_row_binary };
          t1f2a02f42faa570bd799752d94503c06 id_788 { p_0->detail };
          t67d467e776d7a3f3e54efabfd5f911ed id_789 { std::get<0>(id_788) };
          dessser::gen::raql_expr::t_ext id_790 { id_789.condition };
          Size id_791 { fun787(id_790) };
          Size id_792 { Size(sz_348 + id_791) };
          let_res_786 = id_792;
        }
        Size let_res_793;
        {
          Size sz_349 { let_res_786 };
          t1f2a02f42faa570bd799752d94503c06 id_794 { p_0->detail };
          t67d467e776d7a3f3e54efabfd5f911ed id_795 { std::get<0>(id_794) };
          Lst<dessser::gen::global_variable::t_ext> id_796 { id_795.globals };
          uint32_t id_797 { id_796.size() };
          Vec<1, uint32_t> id_798 {  id_797  };
          Size let_res_799;
          {
            Vec<1, uint32_t> n_ref_350 { id_798 };
            uint32_t id_800 { 1U };
            Vec<1, uint32_t> id_801 {  id_800  };
            Size let_res_802;
            {
              Vec<1, uint32_t> lebsz_ref_351 { id_801 };
              bool while_flag_803 { true };
              do {
                uint8_t id_804 { 0 };
                uint32_t id_805 { n_ref_350[id_804] };
                uint8_t id_806 { 0 };
                uint32_t id_807 { lebsz_ref_351[id_806] };
                uint8_t id_808 { 7 };
                uint32_t id_809 { uint32_t(id_807 << id_808) };
                bool id_810 { bool(id_805 >= id_809) };
                while_flag_803 = id_810;
                if (while_flag_803) {
                  uint8_t id_811 { 0 };
                  uint8_t id_812 { 0 };
                  uint32_t id_813 { lebsz_ref_351[id_812] };
                  uint32_t id_814 { 1U };
                  uint32_t id_815 { uint32_t(id_813 + id_814) };
                  Void id_816 { ((void)(lebsz_ref_351[id_811] = id_815), VOID) };
                  (void)id_816;
                }
              } while (while_flag_803);
              (void)VOID;
              uint8_t id_817 { 0 };
              uint32_t id_818 { lebsz_ref_351[id_817] };
              Size id_819 { Size(id_818) };
              let_res_802 = id_819;
            }
            let_res_799 = let_res_802;
          }
          Size id_820 { Size(sz_349 + let_res_799) };
          Vec<1, Size> id_821 {  id_820  };
          Size let_res_822;
          {
            Vec<1, Size> sz_ref_352 { id_821 };
            int32_t id_823 { 0L };
            Vec<1, int32_t> id_824 {  id_823  };
            {
              Vec<1, int32_t> repeat_n_353 { id_824 };
              bool while_flag_825 { true };
              do {
                t1f2a02f42faa570bd799752d94503c06 id_826 { p_0->detail };
                t67d467e776d7a3f3e54efabfd5f911ed id_827 { std::get<0>(id_826) };
                Lst<dessser::gen::global_variable::t_ext> id_828 { id_827.globals };
                uint32_t id_829 { id_828.size() };
                int32_t id_830 { int32_t(id_829) };
                uint8_t id_831 { 0 };
                int32_t id_832 { repeat_n_353[id_831] };
                bool id_833 { bool(id_830 > id_832) };
                while_flag_825 = id_833;
                if (while_flag_825) {
                  uint8_t id_834 { 0 };
                  uint8_t id_835 { 0 };
                  Size id_836 { sz_ref_352[id_835] };
                  auto fun837 { dessser::gen::global_variable::sersize_of_row_binary };
                  uint8_t id_838 { 0 };
                  int32_t id_839 { repeat_n_353[id_838] };
                  t1f2a02f42faa570bd799752d94503c06 id_840 { p_0->detail };
                  t67d467e776d7a3f3e54efabfd5f911ed id_841 { std::get<0>(id_840) };
                  Lst<dessser::gen::global_variable::t_ext> id_842 { id_841.globals };
                  dessser::gen::global_variable::t_ext id_843 { id_842[id_839] };
                  Size id_844 { fun837(id_843) };
                  Size id_845 { Size(id_836 + id_844) };
                  Void id_846 { ((void)(sz_ref_352[id_834] = id_845), VOID) };
                  (void)id_846;
                  uint8_t id_847 { 0 };
                  uint8_t id_848 { 0 };
                  int32_t id_849 { repeat_n_353[id_848] };
                  int32_t id_850 { 1L };
                  int32_t id_851 { int32_t(id_849 + id_850) };
                  Void id_852 { ((void)(repeat_n_353[id_847] = id_851), VOID) };
                  (void)id_852;
                  (void)id_852;
                }
              } while (while_flag_825);
              (void)VOID;
            }
            (void)VOID;
            uint8_t id_853 { 0 };
            Size id_854 { sz_ref_352[id_853] };
            let_res_822 = id_854;
          }
          let_res_793 = let_res_822;
        }
        Size let_res_855;
        {
          Size sz_354 { let_res_793 };
          t1f2a02f42faa570bd799752d94503c06 id_856 { p_0->detail };
          t67d467e776d7a3f3e54efabfd5f911ed id_857 { std::get<0>(id_856) };
          Lst<tb0a5947d2e730ef2c38de99be0c65701> id_858 { id_857.funcs };
          uint32_t id_859 { id_858.size() };
          Vec<1, uint32_t> id_860 {  id_859  };
          Size let_res_861;
          {
            Vec<1, uint32_t> n_ref_355 { id_860 };
            uint32_t id_862 { 1U };
            Vec<1, uint32_t> id_863 {  id_862  };
            Size let_res_864;
            {
              Vec<1, uint32_t> lebsz_ref_356 { id_863 };
              bool while_flag_865 { true };
              do {
                uint8_t id_866 { 0 };
                uint32_t id_867 { n_ref_355[id_866] };
                uint8_t id_868 { 0 };
                uint32_t id_869 { lebsz_ref_356[id_868] };
                uint8_t id_870 { 7 };
                uint32_t id_871 { uint32_t(id_869 << id_870) };
                bool id_872 { bool(id_867 >= id_871) };
                while_flag_865 = id_872;
                if (while_flag_865) {
                  uint8_t id_873 { 0 };
                  uint8_t id_874 { 0 };
                  uint32_t id_875 { lebsz_ref_356[id_874] };
                  uint32_t id_876 { 1U };
                  uint32_t id_877 { uint32_t(id_875 + id_876) };
                  Void id_878 { ((void)(lebsz_ref_356[id_873] = id_877), VOID) };
                  (void)id_878;
                }
              } while (while_flag_865);
              (void)VOID;
              uint8_t id_879 { 0 };
              uint32_t id_880 { lebsz_ref_356[id_879] };
              Size id_881 { Size(id_880) };
              let_res_864 = id_881;
            }
            let_res_861 = let_res_864;
          }
          Size id_882 { Size(sz_354 + let_res_861) };
          Vec<1, Size> id_883 {  id_882  };
          Size let_res_884;
          {
            Vec<1, Size> sz_ref_357 { id_883 };
            int32_t id_885 { 0L };
            Vec<1, int32_t> id_886 {  id_885  };
            {
              Vec<1, int32_t> repeat_n_358 { id_886 };
              bool while_flag_887 { true };
              do {
                t1f2a02f42faa570bd799752d94503c06 id_888 { p_0->detail };
                t67d467e776d7a3f3e54efabfd5f911ed id_889 { std::get<0>(id_888) };
                Lst<tb0a5947d2e730ef2c38de99be0c65701> id_890 { id_889.funcs };
                uint32_t id_891 { id_890.size() };
                int32_t id_892 { int32_t(id_891) };
                uint8_t id_893 { 0 };
                int32_t id_894 { repeat_n_358[id_893] };
                bool id_895 { bool(id_892 > id_894) };
                while_flag_887 = id_895;
                if (while_flag_887) {
                  uint8_t id_896 { 0 };
                  uint8_t id_897 { 0 };
                  Size id_898 { sz_ref_357[id_897] };
                  Size let_res_899;
                  {
                    Size sz_359 { id_898 };
                    auto fun900 { dessser::gen::function_name::sersize_of_row_binary };
                    uint8_t id_901 { 0 };
                    int32_t id_902 { repeat_n_358[id_901] };
                    t1f2a02f42faa570bd799752d94503c06 id_903 { p_0->detail };
                    t67d467e776d7a3f3e54efabfd5f911ed id_904 { std::get<0>(id_903) };
                    Lst<tb0a5947d2e730ef2c38de99be0c65701> id_905 { id_904.funcs };
                    tb0a5947d2e730ef2c38de99be0c65701 id_906 { id_905[id_902] };
                    dessser::gen::function_name::t_ext id_907 { id_906.name };
                    Size id_908 { fun900(id_907) };
                    Size id_909 { Size(sz_359 + id_908) };
                    let_res_899 = id_909;
                  }
                  Size let_res_910;
                  {
                    Size sz_360 { let_res_899 };
                    uint8_t id_911 { 0 };
                    int32_t id_912 { repeat_n_358[id_911] };
                    t1f2a02f42faa570bd799752d94503c06 id_913 { p_0->detail };
                    t67d467e776d7a3f3e54efabfd5f911ed id_914 { std::get<0>(id_913) };
                    Lst<tb0a5947d2e730ef2c38de99be0c65701> id_915 { id_914.funcs };
                    tb0a5947d2e730ef2c38de99be0c65701 id_916 { id_915[id_912] };
                    std::optional<dessser::gen::retention::t_ext> id_917 { id_916.retention };
                    bool id_918 { !(id_917.has_value ()) };
                    Size choose_res_919;
                    if (id_918) {
                      Size id_920 { 1UL };
                      Size id_921 { Size(sz_360 + id_920) };
                      choose_res_919 = id_921;
                    } else {
                      auto fun922 { dessser::gen::retention::sersize_of_row_binary };
                      uint8_t id_923 { 0 };
                      int32_t id_924 { repeat_n_358[id_923] };
                      t1f2a02f42faa570bd799752d94503c06 id_925 { p_0->detail };
                      t67d467e776d7a3f3e54efabfd5f911ed id_926 { std::get<0>(id_925) };
                      Lst<tb0a5947d2e730ef2c38de99be0c65701> id_927 { id_926.funcs };
                      tb0a5947d2e730ef2c38de99be0c65701 id_928 { id_927[id_924] };
                      std::optional<dessser::gen::retention::t_ext> id_929 { id_928.retention };
                      dessser::gen::retention::t_ext id_930 { id_929.value() };
                      Size id_931 { fun922(id_930) };
                      Size id_932 { Size(sz_360 + id_931) };
                      Size id_933 { 1UL };
                      Size id_934 { Size(id_932 + id_933) };
                      choose_res_919 = id_934;
                    }
                    let_res_910 = choose_res_919;
                  }
                  Size id_935 { 1UL };
                  Size id_936 { Size(let_res_910 + id_935) };
                  Size let_res_937;
                  {
                    Size sz_362 { id_936 };
                    uint8_t id_938 { 0 };
                    int32_t id_939 { repeat_n_358[id_938] };
                    t1f2a02f42faa570bd799752d94503c06 id_940 { p_0->detail };
                    t67d467e776d7a3f3e54efabfd5f911ed id_941 { std::get<0>(id_940) };
                    Lst<tb0a5947d2e730ef2c38de99be0c65701> id_942 { id_941.funcs };
                    tb0a5947d2e730ef2c38de99be0c65701 id_943 { id_942[id_939] };
                    std::string id_944 { id_943.doc };
                    uint32_t id_945 { (uint32_t)id_944.size() };
                    Size let_res_946;
                    {
                      uint32_t wlen_363 { id_945 };
                      Vec<1, uint32_t> id_947 {  wlen_363  };
                      Size let_res_948;
                      {
                        Vec<1, uint32_t> n_ref_364 { id_947 };
                        uint32_t id_949 { 1U };
                        Vec<1, uint32_t> id_950 {  id_949  };
                        Size let_res_951;
                        {
                          Vec<1, uint32_t> lebsz_ref_365 { id_950 };
                          bool while_flag_952 { true };
                          do {
                            uint8_t id_953 { 0 };
                            uint32_t id_954 { n_ref_364[id_953] };
                            uint8_t id_955 { 0 };
                            uint32_t id_956 { lebsz_ref_365[id_955] };
                            uint8_t id_957 { 7 };
                            uint32_t id_958 { uint32_t(id_956 << id_957) };
                            bool id_959 { bool(id_954 >= id_958) };
                            while_flag_952 = id_959;
                            if (while_flag_952) {
                              uint8_t id_960 { 0 };
                              uint8_t id_961 { 0 };
                              uint32_t id_962 { lebsz_ref_365[id_961] };
                              uint32_t id_963 { 1U };
                              uint32_t id_964 { uint32_t(id_962 + id_963) };
                              Void id_965 { ((void)(lebsz_ref_365[id_960] = id_964), VOID) };
                              (void)id_965;
                            }
                          } while (while_flag_952);
                          (void)VOID;
                          uint8_t id_966 { 0 };
                          uint32_t id_967 { lebsz_ref_365[id_966] };
                          Size id_968 { Size(id_967) };
                          let_res_951 = id_968;
                        }
                        let_res_948 = let_res_951;
                      }
                      Size id_969 { Size(wlen_363) };
                      Size id_970 { Size(let_res_948 + id_969) };
                      let_res_946 = id_970;
                    }
                    Size id_971 { Size(sz_362 + let_res_946) };
                    let_res_937 = id_971;
                  }
                  Size let_res_972;
                  {
                    Size sz_366 { let_res_937 };
                    auto fun973 { dessser::gen::raql_operation::sersize_of_row_binary };
                    uint8_t id_974 { 0 };
                    int32_t id_975 { repeat_n_358[id_974] };
                    t1f2a02f42faa570bd799752d94503c06 id_976 { p_0->detail };
                    t67d467e776d7a3f3e54efabfd5f911ed id_977 { std::get<0>(id_976) };
                    Lst<tb0a5947d2e730ef2c38de99be0c65701> id_978 { id_977.funcs };
                    tb0a5947d2e730ef2c38de99be0c65701 id_979 { id_978[id_975] };
                    dessser::gen::raql_operation::t_ext id_980 { id_979.operation };
                    Size id_981 { fun973(id_980) };
                    Size id_982 { Size(sz_366 + id_981) };
                    let_res_972 = id_982;
                  }
                  Size let_res_983;
                  {
                    Size sz_367 { let_res_972 };
                    auto fun984 { dessser::gen::raql_type::sersize_of_row_binary };
                    uint8_t id_985 { 0 };
                    int32_t id_986 { repeat_n_358[id_985] };
                    t1f2a02f42faa570bd799752d94503c06 id_987 { p_0->detail };
                    t67d467e776d7a3f3e54efabfd5f911ed id_988 { std::get<0>(id_987) };
                    Lst<tb0a5947d2e730ef2c38de99be0c65701> id_989 { id_988.funcs };
                    tb0a5947d2e730ef2c38de99be0c65701 id_990 { id_989[id_986] };
                    dessser::gen::raql_type::t_ext id_991 { id_990.out_record };
                    Size id_992 { fun984(id_991) };
                    Size id_993 { Size(sz_367 + id_992) };
                    let_res_983 = id_993;
                  }
                  Size let_res_994;
                  {
                    Size sz_368 { let_res_983 };
                    uint8_t id_995 { 0 };
                    int32_t id_996 { repeat_n_358[id_995] };
                    t1f2a02f42faa570bd799752d94503c06 id_997 { p_0->detail };
                    t67d467e776d7a3f3e54efabfd5f911ed id_998 { std::get<0>(id_997) };
                    Lst<tb0a5947d2e730ef2c38de99be0c65701> id_999 { id_998.funcs };
                    tb0a5947d2e730ef2c38de99be0c65701 id_1000 { id_999[id_996] };
                    Lst<dessser::gen::field_name::t_ext> id_1001 { id_1000.factors };
                    uint32_t id_1002 { id_1001.size() };
                    Vec<1, uint32_t> id_1003 {  id_1002  };
                    Size let_res_1004;
                    {
                      Vec<1, uint32_t> n_ref_369 { id_1003 };
                      uint32_t id_1005 { 1U };
                      Vec<1, uint32_t> id_1006 {  id_1005  };
                      Size let_res_1007;
                      {
                        Vec<1, uint32_t> lebsz_ref_370 { id_1006 };
                        bool while_flag_1008 { true };
                        do {
                          uint8_t id_1009 { 0 };
                          uint32_t id_1010 { n_ref_369[id_1009] };
                          uint8_t id_1011 { 0 };
                          uint32_t id_1012 { lebsz_ref_370[id_1011] };
                          uint8_t id_1013 { 7 };
                          uint32_t id_1014 { uint32_t(id_1012 << id_1013) };
                          bool id_1015 { bool(id_1010 >= id_1014) };
                          while_flag_1008 = id_1015;
                          if (while_flag_1008) {
                            uint8_t id_1016 { 0 };
                            uint8_t id_1017 { 0 };
                            uint32_t id_1018 { lebsz_ref_370[id_1017] };
                            uint32_t id_1019 { 1U };
                            uint32_t id_1020 { uint32_t(id_1018 + id_1019) };
                            Void id_1021 { ((void)(lebsz_ref_370[id_1016] = id_1020), VOID) };
                            (void)id_1021;
                          }
                        } while (while_flag_1008);
                        (void)VOID;
                        uint8_t id_1022 { 0 };
                        uint32_t id_1023 { lebsz_ref_370[id_1022] };
                        Size id_1024 { Size(id_1023) };
                        let_res_1007 = id_1024;
                      }
                      let_res_1004 = let_res_1007;
                    }
                    Size id_1025 { Size(sz_368 + let_res_1004) };
                    Vec<1, Size> id_1026 {  id_1025  };
                    Size let_res_1027;
                    {
                      Vec<1, Size> sz_ref_371 { id_1026 };
                      int32_t id_1028 { 0L };
                      Vec<1, int32_t> id_1029 {  id_1028  };
                      {
                        Vec<1, int32_t> repeat_n_372 { id_1029 };
                        bool while_flag_1030 { true };
                        do {
                          uint8_t id_1031 { 0 };
                          int32_t id_1032 { repeat_n_358[id_1031] };
                          t1f2a02f42faa570bd799752d94503c06 id_1033 { p_0->detail };
                          t67d467e776d7a3f3e54efabfd5f911ed id_1034 { std::get<0>(id_1033) };
                          Lst<tb0a5947d2e730ef2c38de99be0c65701> id_1035 { id_1034.funcs };
                          tb0a5947d2e730ef2c38de99be0c65701 id_1036 { id_1035[id_1032] };
                          Lst<dessser::gen::field_name::t_ext> id_1037 { id_1036.factors };
                          uint32_t id_1038 { id_1037.size() };
                          int32_t id_1039 { int32_t(id_1038) };
                          uint8_t id_1040 { 0 };
                          int32_t id_1041 { repeat_n_372[id_1040] };
                          bool id_1042 { bool(id_1039 > id_1041) };
                          while_flag_1030 = id_1042;
                          if (while_flag_1030) {
                            uint8_t id_1043 { 0 };
                            uint8_t id_1044 { 0 };
                            Size id_1045 { sz_ref_371[id_1044] };
                            auto fun1046 { dessser::gen::field_name::sersize_of_row_binary };
                            uint8_t id_1047 { 0 };
                            int32_t id_1048 { repeat_n_372[id_1047] };
                            uint8_t id_1049 { 0 };
                            int32_t id_1050 { repeat_n_358[id_1049] };
                            t1f2a02f42faa570bd799752d94503c06 id_1051 { p_0->detail };
                            t67d467e776d7a3f3e54efabfd5f911ed id_1052 { std::get<0>(id_1051) };
                            Lst<tb0a5947d2e730ef2c38de99be0c65701> id_1053 { id_1052.funcs };
                            tb0a5947d2e730ef2c38de99be0c65701 id_1054 { id_1053[id_1050] };
                            Lst<dessser::gen::field_name::t_ext> id_1055 { id_1054.factors };
                            dessser::gen::field_name::t_ext id_1056 { id_1055[id_1048] };
                            Size id_1057 { fun1046(id_1056) };
                            Size id_1058 { Size(id_1045 + id_1057) };
                            Void id_1059 { ((void)(sz_ref_371[id_1043] = id_1058), VOID) };
                            (void)id_1059;
                            uint8_t id_1060 { 0 };
                            uint8_t id_1061 { 0 };
                            int32_t id_1062 { repeat_n_372[id_1061] };
                            int32_t id_1063 { 1L };
                            int32_t id_1064 { int32_t(id_1062 + id_1063) };
                            Void id_1065 { ((void)(repeat_n_372[id_1060] = id_1064), VOID) };
                            (void)id_1065;
                            (void)id_1065;
                          }
                        } while (while_flag_1030);
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_1066 { 0 };
                      Size id_1067 { sz_ref_371[id_1066] };
                      let_res_1027 = id_1067;
                    }
                    let_res_994 = let_res_1027;
                  }
                  Size let_res_1068;
                  {
                    Size sz_373 { let_res_994 };
                    uint8_t id_1069 { 0 };
                    int32_t id_1070 { repeat_n_358[id_1069] };
                    t1f2a02f42faa570bd799752d94503c06 id_1071 { p_0->detail };
                    t67d467e776d7a3f3e54efabfd5f911ed id_1072 { std::get<0>(id_1071) };
                    Lst<tb0a5947d2e730ef2c38de99be0c65701> id_1073 { id_1072.funcs };
                    tb0a5947d2e730ef2c38de99be0c65701 id_1074 { id_1073[id_1070] };
                    std::string id_1075 { id_1074.signature };
                    uint32_t id_1076 { (uint32_t)id_1075.size() };
                    Size let_res_1077;
                    {
                      uint32_t wlen_374 { id_1076 };
                      Vec<1, uint32_t> id_1078 {  wlen_374  };
                      Size let_res_1079;
                      {
                        Vec<1, uint32_t> n_ref_375 { id_1078 };
                        uint32_t id_1080 { 1U };
                        Vec<1, uint32_t> id_1081 {  id_1080  };
                        Size let_res_1082;
                        {
                          Vec<1, uint32_t> lebsz_ref_376 { id_1081 };
                          bool while_flag_1083 { true };
                          do {
                            uint8_t id_1084 { 0 };
                            uint32_t id_1085 { n_ref_375[id_1084] };
                            uint8_t id_1086 { 0 };
                            uint32_t id_1087 { lebsz_ref_376[id_1086] };
                            uint8_t id_1088 { 7 };
                            uint32_t id_1089 { uint32_t(id_1087 << id_1088) };
                            bool id_1090 { bool(id_1085 >= id_1089) };
                            while_flag_1083 = id_1090;
                            if (while_flag_1083) {
                              uint8_t id_1091 { 0 };
                              uint8_t id_1092 { 0 };
                              uint32_t id_1093 { lebsz_ref_376[id_1092] };
                              uint32_t id_1094 { 1U };
                              uint32_t id_1095 { uint32_t(id_1093 + id_1094) };
                              Void id_1096 { ((void)(lebsz_ref_376[id_1091] = id_1095), VOID) };
                              (void)id_1096;
                            }
                          } while (while_flag_1083);
                          (void)VOID;
                          uint8_t id_1097 { 0 };
                          uint32_t id_1098 { lebsz_ref_376[id_1097] };
                          Size id_1099 { Size(id_1098) };
                          let_res_1082 = id_1099;
                        }
                        let_res_1079 = let_res_1082;
                      }
                      Size id_1100 { Size(wlen_374) };
                      Size id_1101 { Size(let_res_1079 + id_1100) };
                      let_res_1077 = id_1101;
                    }
                    Size id_1102 { Size(sz_373 + let_res_1077) };
                    let_res_1068 = id_1102;
                  }
                  Size let_res_1103;
                  {
                    Size sz_377 { let_res_1068 };
                    uint8_t id_1104 { 0 };
                    int32_t id_1105 { repeat_n_358[id_1104] };
                    t1f2a02f42faa570bd799752d94503c06 id_1106 { p_0->detail };
                    t67d467e776d7a3f3e54efabfd5f911ed id_1107 { std::get<0>(id_1106) };
                    Lst<tb0a5947d2e730ef2c38de99be0c65701> id_1108 { id_1107.funcs };
                    tb0a5947d2e730ef2c38de99be0c65701 id_1109 { id_1108[id_1105] };
                    std::string id_1110 { id_1109.in_signature };
                    uint32_t id_1111 { (uint32_t)id_1110.size() };
                    Size let_res_1112;
                    {
                      uint32_t wlen_378 { id_1111 };
                      Vec<1, uint32_t> id_1113 {  wlen_378  };
                      Size let_res_1114;
                      {
                        Vec<1, uint32_t> n_ref_379 { id_1113 };
                        uint32_t id_1115 { 1U };
                        Vec<1, uint32_t> id_1116 {  id_1115  };
                        Size let_res_1117;
                        {
                          Vec<1, uint32_t> lebsz_ref_380 { id_1116 };
                          bool while_flag_1118 { true };
                          do {
                            uint8_t id_1119 { 0 };
                            uint32_t id_1120 { n_ref_379[id_1119] };
                            uint8_t id_1121 { 0 };
                            uint32_t id_1122 { lebsz_ref_380[id_1121] };
                            uint8_t id_1123 { 7 };
                            uint32_t id_1124 { uint32_t(id_1122 << id_1123) };
                            bool id_1125 { bool(id_1120 >= id_1124) };
                            while_flag_1118 = id_1125;
                            if (while_flag_1118) {
                              uint8_t id_1126 { 0 };
                              uint8_t id_1127 { 0 };
                              uint32_t id_1128 { lebsz_ref_380[id_1127] };
                              uint32_t id_1129 { 1U };
                              uint32_t id_1130 { uint32_t(id_1128 + id_1129) };
                              Void id_1131 { ((void)(lebsz_ref_380[id_1126] = id_1130), VOID) };
                              (void)id_1131;
                            }
                          } while (while_flag_1118);
                          (void)VOID;
                          uint8_t id_1132 { 0 };
                          uint32_t id_1133 { lebsz_ref_380[id_1132] };
                          Size id_1134 { Size(id_1133) };
                          let_res_1117 = id_1134;
                        }
                        let_res_1114 = let_res_1117;
                      }
                      Size id_1135 { Size(wlen_378) };
                      Size id_1136 { Size(let_res_1114 + id_1135) };
                      let_res_1112 = id_1136;
                    }
                    Size id_1137 { Size(sz_377 + let_res_1112) };
                    let_res_1103 = id_1137;
                  }
                  Void id_1138 { ((void)(sz_ref_357[id_896] = let_res_1103), VOID) };
                  (void)id_1138;
                  uint8_t id_1139 { 0 };
                  uint8_t id_1140 { 0 };
                  int32_t id_1141 { repeat_n_358[id_1140] };
                  int32_t id_1142 { 1L };
                  int32_t id_1143 { int32_t(id_1141 + id_1142) };
                  Void id_1144 { ((void)(repeat_n_358[id_1139] = id_1143), VOID) };
                  (void)id_1144;
                  (void)id_1144;
                }
              } while (while_flag_887);
              (void)VOID;
            }
            (void)VOID;
            uint8_t id_1145 { 0 };
            Size id_1146 { sz_ref_357[id_1145] };
            let_res_884 = id_1146;
          }
          let_res_855 = let_res_884;
        }
        choose_res_722 = let_res_855;
      } else {
        t1f2a02f42faa570bd799752d94503c06 id_1147 { p_0->detail };
        uint16_t id_1148 { uint16_t(id_1147.index()) };
        uint16_t id_1149 { 1 };
        bool id_1150 { bool(id_1148 == id_1149) };
        Void id_1151 { ((void)(assert(id_1150)), VOID) };
        (void)id_1151;
        Size id_1152 { 2UL };
        Size id_1153 { Size(sz_336 + id_1152) };
        t1f2a02f42faa570bd799752d94503c06 id_1154 { p_0->detail };
        t0fbe0ba3da9da3292ae419be74c6cc6e id_1155 { std::get<1>(id_1154) };
        std::string id_1156 { id_1155.err_msg };
        uint32_t id_1157 { (uint32_t)id_1156.size() };
        Vec<1, uint32_t> id_1158 {  id_1157  };
        Size let_res_1159;
        {
          Vec<1, uint32_t> n_ref_340 { id_1158 };
          uint32_t id_1160 { 1U };
          Vec<1, uint32_t> id_1161 {  id_1160  };
          Size let_res_1162;
          {
            Vec<1, uint32_t> lebsz_ref_341 { id_1161 };
            bool while_flag_1163 { true };
            do {
              uint8_t id_1164 { 0 };
              uint32_t id_1165 { n_ref_340[id_1164] };
              uint8_t id_1166 { 0 };
              uint32_t id_1167 { lebsz_ref_341[id_1166] };
              uint8_t id_1168 { 7 };
              uint32_t id_1169 { uint32_t(id_1167 << id_1168) };
              bool id_1170 { bool(id_1165 >= id_1169) };
              while_flag_1163 = id_1170;
              if (while_flag_1163) {
                uint8_t id_1171 { 0 };
                uint8_t id_1172 { 0 };
                uint32_t id_1173 { lebsz_ref_341[id_1172] };
                uint32_t id_1174 { 1U };
                uint32_t id_1175 { uint32_t(id_1173 + id_1174) };
                Void id_1176 { ((void)(lebsz_ref_341[id_1171] = id_1175), VOID) };
                (void)id_1176;
              }
            } while (while_flag_1163);
            (void)VOID;
            uint8_t id_1177 { 0 };
            uint32_t id_1178 { lebsz_ref_341[id_1177] };
            Size id_1179 { Size(id_1178) };
            let_res_1162 = id_1179;
          }
          let_res_1159 = let_res_1162;
        }
        t1f2a02f42faa570bd799752d94503c06 id_1180 { p_0->detail };
        t0fbe0ba3da9da3292ae419be74c6cc6e id_1181 { std::get<1>(id_1180) };
        std::string id_1182 { id_1181.err_msg };
        uint32_t id_1183 { (uint32_t)id_1182.size() };
        Size id_1184 { Size(id_1183) };
        Size id_1185 { Size(let_res_1159 + id_1184) };
        Size id_1186 { Size(id_1153 + id_1185) };
        Size let_res_1187;
        {
          Size sz_342 { id_1186 };
          t1f2a02f42faa570bd799752d94503c06 id_1188 { p_0->detail };
          t0fbe0ba3da9da3292ae419be74c6cc6e id_1189 { std::get<1>(id_1188) };
          std::optional<dessser::gen::src_path::t_ext> id_1190 { id_1189.depends_on };
          bool id_1191 { !(id_1190.has_value ()) };
          Size choose_res_1192;
          if (id_1191) {
            Size id_1193 { 1UL };
            Size id_1194 { Size(sz_342 + id_1193) };
            choose_res_1192 = id_1194;
          } else {
            auto fun1195 { dessser::gen::src_path::sersize_of_row_binary };
            t1f2a02f42faa570bd799752d94503c06 id_1196 { p_0->detail };
            t0fbe0ba3da9da3292ae419be74c6cc6e id_1197 { std::get<1>(id_1196) };
            std::optional<dessser::gen::src_path::t_ext> id_1198 { id_1197.depends_on };
            dessser::gen::src_path::t_ext id_1199 { id_1198.value() };
            Size id_1200 { fun1195(id_1199) };
            Size id_1201 { Size(sz_342 + id_1200) };
            Size id_1202 { 1UL };
            Size id_1203 { Size(id_1201 + id_1202) };
            choose_res_1192 = id_1203;
          }
          let_res_1187 = choose_res_1192;
        }
        choose_res_722 = let_res_1187;
      }
      let_res_717 = choose_res_722;
    }
    return let_res_717;
  }
   };
  return fun608;
}
std::function<Size(t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_68"
        (let "dstring1_62"
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
                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_56"))) (unsafe-nth (u8 0) (identifier "p_ref_58")))))))
          (let-pair "dstring1_fst_63" "dstring1_snd_64" (identifier "dstring1_62")
            (let-pair "dstring2_fst_66" "dstring2_snd_67" (read-bytes (identifier "dstring1_snd_64") (identifier "dstring1_fst_63")) (make-tup (string-of-bytes (identifier "dstring2_fst_66")) (identifier "dstring2_snd_67")))))
        (let-pair "drec_fst_69" "drec_snd_70" (identifier "drec_68")
          (let "drec_106"
            (let-pair "dlist4_fst_104" "dlist4_snd_105"
              (let "dlist1_80"
                (let "leb_ref_71" (make-vec (u32 0))
                  (let "shft_ref_72" (make-vec (u8 0))
                    (let "p_ref_73" (make-vec (identifier "drec_snd_70"))
                      (seq
                        (while
                          (let "leb128_74" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_73")))
                            (let-pair "leb128_fst_75" "leb128_snd_76" 
                              (identifier "leb128_74")
                              (seq (set-vec (u8 0) (identifier "p_ref_73") (identifier "leb128_snd_76"))
                                (set-vec (u8 0) (identifier "leb_ref_71")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_75") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_72"))) (unsafe-nth (u8 0) (identifier "leb_ref_71"))))
                                (set-vec (u8 0) (identifier "shft_ref_72") (add (unsafe-nth (u8 0) (identifier "shft_ref_72")) (u8 7))) 
                                (ge (identifier "leb128_fst_75") (u8 128))))) 
                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_71")) (unsafe-nth (u8 0) (identifier "p_ref_73")))))))
                (let-pair "dlist1_fst_81" "dlist1_snd_82" (identifier "dlist1_80")
                  (let "inits_src_ref_83" (make-vec (make-tup (end-of-list "STRING") (identifier "dlist1_snd_82")))
                    (seq
                      (let "repeat_n_84" (make-vec (i32 0))
                        (while (gt (to-i32 (identifier "dlist1_fst_81")) (unsafe-nth (u8 0) (identifier "repeat_n_84")))
                          (seq
                            (let "dlist2_85" (unsafe-nth (u8 0) (identifier "inits_src_ref_83"))
                              (let-pair "dlist2_fst_86" "dlist2_snd_87" 
                                (identifier "dlist2_85")
                                (set-vec (u8 0) (identifier "inits_src_ref_83")
                                  (let "dstring1_94"
                                    (let "leb_ref_88" (make-vec (u32 0))
                                      (let "shft_ref_89" (make-vec (u8 0))
                                        (let "p_ref_90" (make-vec (identifier "dlist2_snd_87"))
                                          (seq
                                            (while
                                              (let "leb128_91" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_90")))
                                                (let-pair "leb128_fst_92" "leb128_snd_93" 
                                                  (identifier "leb128_91")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_90") (identifier "leb128_snd_93"))
                                                    (set-vec (u8 0) (identifier "leb_ref_88")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_92") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_89"))) (unsafe-nth (u8 0) (identifier "leb_ref_88"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_89") (add (unsafe-nth (u8 0) (identifier "shft_ref_89")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_92") (u8 128))))) 
                                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_88"))) (unsafe-nth (u8 0) (identifier "p_ref_90")))))))
                                    (let-pair "dstring1_fst_95" "dstring1_snd_96" 
                                      (identifier "dstring1_94")
                                      (let-pair "dstring2_fst_98" "dstring2_snd_99" 
                                        (read-bytes (identifier "dstring1_snd_96") (identifier "dstring1_fst_95"))
                                        (make-tup (cons (string-of-bytes (identifier "dstring2_fst_98")) (identifier "dlist2_fst_86")) (identifier "dstring2_snd_99"))))))))
                            (set-vec (u8 0) (identifier "repeat_n_84") (add (unsafe-nth (u8 0) (identifier "repeat_n_84")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "inits_src_ref_83")))))) 
              (make-tup (identity (identifier "dlist4_fst_104")) (identifier "dlist4_snd_105")))
            (let-pair "drec_fst_107" "drec_snd_108" (identifier "drec_106")
              (let-pair "drec_fst_319" "drec_snd_320"
                (let "dsum1_115" (let-pair "du16_fst_110" "du16_snd_111" (read-u16 little-endian (identifier "drec_snd_108")) (make-tup (identifier "du16_fst_110") (identifier "du16_snd_111")))
                  (let-pair "dsum1_fst_116" "dsum1_snd_117" (identifier "dsum1_115")
                    (if (eq (u16 0) (identifier "dsum1_fst_116"))
                      (let "drec_165"
                        (let-pair "dlist4_fst_163" "dlist4_snd_164"
                          (let "dlist1_151"
                            (let "leb_ref_142" (make-vec (u32 0))
                              (let "shft_ref_143" (make-vec (u8 0))
                                (let "p_ref_144" (make-vec (identifier "dsum1_snd_117"))
                                  (seq
                                    (while
                                      (let "leb128_145" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_144")))
                                        (let-pair "leb128_fst_146" "leb128_snd_147" 
                                          (identifier "leb128_145")
                                          (seq (set-vec (u8 0) (identifier "p_ref_144") (identifier "leb128_snd_147"))
                                            (set-vec (u8 0) (identifier "leb_ref_142")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_146") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_143"))) (unsafe-nth (u8 0) (identifier "leb_ref_142"))))
                                            (set-vec (u8 0) (identifier "shft_ref_143") (add (unsafe-nth (u8 0) (identifier "shft_ref_143")) (u8 7))) 
                                            (ge (identifier "leb128_fst_146") (u8 128))))) 
                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_142")) (unsafe-nth (u8 0) (identifier "p_ref_144")))))))
                            (let-pair "dlist1_fst_152" "dlist1_snd_153" 
                              (identifier "dlist1_151")
                              (let "inits_src_ref_154" (make-vec (make-tup (end-of-list "$program_parameter") (identifier "dlist1_snd_153")))
                                (seq
                                  (let "repeat_n_155" (make-vec (i32 0))
                                    (while (gt (to-i32 (identifier "dlist1_fst_152")) (unsafe-nth (u8 0) (identifier "repeat_n_155")))
                                      (seq
                                        (let "dlist2_156" (unsafe-nth (u8 0) (identifier "inits_src_ref_154"))
                                          (let-pair "dlist2_fst_157" "dlist2_snd_158" 
                                            (identifier "dlist2_156")
                                            (set-vec (u8 0) (identifier "inits_src_ref_154")
                                              (let-pair "dlist3_fst_160" "dlist3_snd_161" 
                                                (apply (ext-identifier program_parameter of-row-binary) (identifier "dlist2_snd_158"))
                                                (make-tup (cons (identifier "dlist3_fst_160") (identifier "dlist2_fst_157")) (identifier "dlist3_snd_161"))))))
                                        (set-vec (u8 0) (identifier "repeat_n_155") (add (unsafe-nth (u8 0) (identifier "repeat_n_155")) (i32 1)))))) 
                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_154")))))) 
                          (make-tup (identity (identifier "dlist4_fst_163")) (identifier "dlist4_snd_164")))
                        (let-pair "drec_fst_166" "drec_snd_167" (identifier "drec_165")
                          (let "drec_168" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_167"))
                            (let-pair "drec_fst_169" "drec_snd_170" (identifier "drec_168")
                              (let "drec_194"
                                (let-pair "dlist4_fst_192" "dlist4_snd_193"
                                  (let "dlist1_180"
                                    (let "leb_ref_171" (make-vec (u32 0))
                                      (let "shft_ref_172" (make-vec (u8 0))
                                        (let "p_ref_173" (make-vec (identifier "drec_snd_170"))
                                          (seq
                                            (while
                                              (let "leb128_174" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_173")))
                                                (let-pair "leb128_fst_175" "leb128_snd_176" 
                                                  (identifier "leb128_174")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_173") (identifier "leb128_snd_176"))
                                                    (set-vec (u8 0) (identifier "leb_ref_171")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_175") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_172"))) (unsafe-nth (u8 0) (identifier "leb_ref_171"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_172") (add (unsafe-nth (u8 0) (identifier "shft_ref_172")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_175") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_171")) (unsafe-nth (u8 0) (identifier "p_ref_173")))))))
                                    (let-pair "dlist1_fst_181" "dlist1_snd_182" 
                                      (identifier "dlist1_180")
                                      (let "inits_src_ref_183" (make-vec (make-tup (end-of-list "$global_variable") (identifier "dlist1_snd_182")))
                                        (seq
                                          (let "repeat_n_184" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_181")) (unsafe-nth (u8 0) (identifier "repeat_n_184")))
                                              (seq
                                                (let "dlist2_185" (unsafe-nth (u8 0) (identifier "inits_src_ref_183"))
                                                  (let-pair "dlist2_fst_186" "dlist2_snd_187" 
                                                    (identifier "dlist2_185")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_183")
                                                      (let-pair "dlist3_fst_189" "dlist3_snd_190" 
                                                        (apply (ext-identifier global_variable of-row-binary) (identifier "dlist2_snd_187"))
                                                        (make-tup (cons (identifier "dlist3_fst_189") (identifier "dlist2_fst_186")) (identifier "dlist3_snd_190"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_184") (add (unsafe-nth (u8 0) (identifier "repeat_n_184")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_183")))))) 
                                  (make-tup (identity (identifier "dlist4_fst_192")) (identifier "dlist4_snd_193")))
                                (let-pair "drec_fst_195" "drec_snd_196" 
                                  (identifier "drec_194")
                                  (let-pair "dlist4_fst_310" "dlist4_snd_311"
                                    (let "dlist1_206"
                                      (let "leb_ref_197" (make-vec (u32 0))
                                        (let "shft_ref_198" (make-vec (u8 0))
                                          (let "p_ref_199" (make-vec (identifier "drec_snd_196"))
                                            (seq
                                              (while
                                                (let "leb128_200" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_199")))
                                                  (let-pair "leb128_fst_201" "leb128_snd_202" 
                                                    (identifier "leb128_200")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_199") (identifier "leb128_snd_202"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_197")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_201") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_198")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_197")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_198") (add (unsafe-nth (u8 0) (identifier "shft_ref_198")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_201") (u8 128))))) 
                                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_197")) (unsafe-nth (u8 0) (identifier "p_ref_199")))))))
                                      (let-pair "dlist1_fst_207" "dlist1_snd_208" 
                                        (identifier "dlist1_206")
                                        (let "inits_src_ref_209"
                                          (make-vec
                                            (make-tup
                                              (end-of-list "{name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}")
                                              (identifier "dlist1_snd_208")))
                                          (seq
                                            (let "repeat_n_210" (make-vec (i32 0))
                                              (while (gt (to-i32 (identifier "dlist1_fst_207")) (unsafe-nth (u8 0) (identifier "repeat_n_210")))
                                                (seq
                                                  (let "dlist2_211" (unsafe-nth (u8 0) (identifier "inits_src_ref_209"))
                                                    (let-pair "dlist2_fst_212" "dlist2_snd_213" 
                                                      (identifier "dlist2_211")
                                                      (set-vec (u8 0) 
                                                        (identifier "inits_src_ref_209")
                                                        (let "drec_214" 
                                                          (apply (ext-identifier function_name of-row-binary) (identifier "dlist2_snd_213"))
                                                          (let-pair "drec_fst_215" "drec_snd_216" 
                                                            (identifier "drec_214")
                                                            (let "drec_220"
                                                              (if (eq (peek-u8 (identifier "drec_snd_216") (size 0)) (u8 1)) 
                                                                (make-tup (null "$retention") (ptr-add (identifier "drec_snd_216") (size 1)))
                                                                (let-pair "make1_1_fst_218" "make1_1_snd_219" 
                                                                  (apply (ext-identifier retention of-row-binary) (ptr-add (identifier "drec_snd_216") (size 1)))
                                                                  (make-tup (not-null (identifier "make1_1_fst_218")) (identifier "make1_1_snd_219"))))
                                                              (let-pair "drec_fst_221" "drec_snd_222" 
                                                                (identifier "drec_220")
                                                                (let "drec_226"
                                                                  (let-pair "dbool_fst_224" "dbool_snd_225" 
                                                                    (read-u8 (identifier "drec_snd_222")) 
                                                                    (make-tup (not (eq (identifier "dbool_fst_224") (u8 0))) (identifier "dbool_snd_225")))
                                                                  (let-pair "drec_fst_227" "drec_snd_228" 
                                                                    (identifier "drec_226")
                                                                    (let "drec_241"
                                                                    (let "dstring1_235"
                                                                    (let "leb_ref_229" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_230" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_231" 
                                                                    (make-vec (identifier "drec_snd_228"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_232" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_231")))
                                                                    (let-pair "leb128_fst_233" "leb128_snd_234" 
                                                                    (identifier "leb128_232")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_231") (identifier "leb128_snd_234"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_229")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_233") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_230")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_229")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_230") (add (unsafe-nth (u8 0) (identifier "shft_ref_230")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_233") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_229"))) (unsafe-nth (u8 0) (identifier "p_ref_231")))))))
                                                                    (let-pair "dstring1_fst_236" "dstring1_snd_237" 
                                                                    (identifier "dstring1_235")
                                                                    (let-pair "dstring2_fst_239" "dstring2_snd_240" 
                                                                    (read-bytes (identifier "dstring1_snd_237") (identifier "dstring1_fst_236"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_239")) (identifier "dstring2_snd_240")))))
                                                                    (let-pair "drec_fst_242" "drec_snd_243" 
                                                                    (identifier "drec_241")
                                                                    (let "drec_244" 
                                                                    (apply (ext-identifier raql_operation of-row-binary) (identifier "drec_snd_243"))
                                                                    (let-pair "drec_fst_245" "drec_snd_246" 
                                                                    (identifier "drec_244")
                                                                    (let "drec_247" 
                                                                    (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_246"))
                                                                    (let-pair "drec_fst_248" "drec_snd_249" 
                                                                    (identifier "drec_247")
                                                                    (let "drec_273"
                                                                    (let-pair "dlist4_fst_271" "dlist4_snd_272"
                                                                    (let "dlist1_259"
                                                                    (let "leb_ref_250" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_251" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_252" 
                                                                    (make-vec (identifier "drec_snd_249"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_253" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_252")))
                                                                    (let-pair "leb128_fst_254" "leb128_snd_255" 
                                                                    (identifier "leb128_253")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_252") (identifier "leb128_snd_255"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_250")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_254") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_251")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_250")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_251") (add (unsafe-nth (u8 0) (identifier "shft_ref_251")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_254") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_250")) (unsafe-nth (u8 0) (identifier "p_ref_252")))))))
                                                                    (let-pair "dlist1_fst_260" "dlist1_snd_261" 
                                                                    (identifier "dlist1_259")
                                                                    (let "inits_src_ref_262" 
                                                                    (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_261")))
                                                                    (seq
                                                                    (let "repeat_n_263" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_260")) (unsafe-nth (u8 0) (identifier "repeat_n_263")))
                                                                    (seq
                                                                    (let "dlist2_264" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_262"))
                                                                    (let-pair "dlist2_fst_265" "dlist2_snd_266" 
                                                                    (identifier "dlist2_264")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_262")
                                                                    (let-pair "dlist3_fst_268" "dlist3_snd_269" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_266"))
                                                                    (make-tup (cons (identifier "dlist3_fst_268") (identifier "dlist2_fst_265")) (identifier "dlist3_snd_269"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_263") (add (unsafe-nth (u8 0) (identifier "repeat_n_263")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_262")))))) 
                                                                    (make-tup (identity (identifier "dlist4_fst_271")) (identifier "dlist4_snd_272")))
                                                                    (let-pair "drec_fst_274" "drec_snd_275" 
                                                                    (identifier "drec_273")
                                                                    (let "drec_288"
                                                                    (let "dstring1_282"
                                                                    (let "leb_ref_276" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_277" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_278" 
                                                                    (make-vec (identifier "drec_snd_275"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_279" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_278")))
                                                                    (let-pair "leb128_fst_280" "leb128_snd_281" 
                                                                    (identifier "leb128_279")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_278") (identifier "leb128_snd_281"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_276")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_280") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_277")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_276")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_277") (add (unsafe-nth (u8 0) (identifier "shft_ref_277")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_280") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_276"))) (unsafe-nth (u8 0) (identifier "p_ref_278")))))))
                                                                    (let-pair "dstring1_fst_283" "dstring1_snd_284" 
                                                                    (identifier "dstring1_282")
                                                                    (let-pair "dstring2_fst_286" "dstring2_snd_287" 
                                                                    (read-bytes (identifier "dstring1_snd_284") (identifier "dstring1_fst_283"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_286")) (identifier "dstring2_snd_287")))))
                                                                    (let-pair "drec_fst_289" "drec_snd_290" 
                                                                    (identifier "drec_288")
                                                                    (let "dstring1_297"
                                                                    (let "leb_ref_291" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_292" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_293" 
                                                                    (make-vec (identifier "drec_snd_290"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_294" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_293")))
                                                                    (let-pair "leb128_fst_295" "leb128_snd_296" 
                                                                    (identifier "leb128_294")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_293") (identifier "leb128_snd_296"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_291")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_295") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_292")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_291")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_292") (add (unsafe-nth (u8 0) (identifier "shft_ref_292")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_295") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_291"))) (unsafe-nth (u8 0) (identifier "p_ref_293")))))))
                                                                    (let-pair "dstring1_fst_298" "dstring1_snd_299" 
                                                                    (identifier "dstring1_297")
                                                                    (let-pair "dstring2_fst_301" "dstring2_snd_302" 
                                                                    (read-bytes (identifier "dstring1_snd_299") (identifier "dstring1_fst_298"))
                                                                    (make-tup
                                                                    (cons
                                                                    (make-rec 
                                                                    (string "name") 
                                                                    (identifier "drec_fst_215") 
                                                                    (string "retention") 
                                                                    (identifier "drec_fst_221") 
                                                                    (string "is_lazy") 
                                                                    (identifier "drec_fst_227") 
                                                                    (string "doc") 
                                                                    (identifier "drec_fst_242") 
                                                                    (string "operation") 
                                                                    (identifier "drec_fst_245") 
                                                                    (string "out_record") 
                                                                    (identifier "drec_fst_248") 
                                                                    (string "factors") 
                                                                    (identifier "drec_fst_274") 
                                                                    (string "signature") 
                                                                    (identifier "drec_fst_289") 
                                                                    (string "in_signature") 
                                                                    (string-of-bytes (identifier "dstring2_fst_301"))) 
                                                                    (identifier "dlist2_fst_212")) 
                                                                    (identifier "dstring2_snd_302"))))))))))))))))))))))))
                                                  (set-vec (u8 0) (identifier "repeat_n_210") (add (unsafe-nth (u8 0) (identifier "repeat_n_210")) (i32 1)))))) 
                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_209"))))))
                                    (make-tup
                                      (construct "[Compiled {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}[[]]} | Failed {err_msg: STRING; depends_on: $src_path?}]" 0
                                        (make-rec (string "default_params") 
                                          (identifier "drec_fst_166") 
                                          (string "condition") (identifier "drec_fst_169") 
                                          (string "globals") (identifier "drec_fst_195") 
                                          (string "funcs") (identity (identifier "dlist4_fst_310")))) 
                                      (identifier "dlist4_snd_311")))))))))
                      (seq (assert (eq (identifier "dsum1_fst_116") (u16 1)))
                        (let "drec_130"
                          (let "dstring1_124"
                            (let "leb_ref_118" (make-vec (u32 0))
                              (let "shft_ref_119" (make-vec (u8 0))
                                (let "p_ref_120" (make-vec (identifier "dsum1_snd_117"))
                                  (seq
                                    (while
                                      (let "leb128_121" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_120")))
                                        (let-pair "leb128_fst_122" "leb128_snd_123" 
                                          (identifier "leb128_121")
                                          (seq (set-vec (u8 0) (identifier "p_ref_120") (identifier "leb128_snd_123"))
                                            (set-vec (u8 0) (identifier "leb_ref_118")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_122") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_119"))) (unsafe-nth (u8 0) (identifier "leb_ref_118"))))
                                            (set-vec (u8 0) (identifier "shft_ref_119") (add (unsafe-nth (u8 0) (identifier "shft_ref_119")) (u8 7))) 
                                            (ge (identifier "leb128_fst_122") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_118"))) (unsafe-nth (u8 0) (identifier "p_ref_120")))))))
                            (let-pair "dstring1_fst_125" "dstring1_snd_126" 
                              (identifier "dstring1_124")
                              (let-pair "dstring2_fst_128" "dstring2_snd_129" 
                                (read-bytes (identifier "dstring1_snd_126") (identifier "dstring1_fst_125")) 
                                (make-tup (string-of-bytes (identifier "dstring2_fst_128")) (identifier "dstring2_snd_129")))))
                          (let-pair "drec_fst_131" "drec_snd_132" (identifier "drec_130")
                            (let-pair "drec_fst_137" "drec_snd_138"
                              (if (eq (peek-u8 (identifier "drec_snd_132") (size 0)) (u8 1)) 
                                (make-tup (null "$src_path") (ptr-add (identifier "drec_snd_132") (size 1)))
                                (let-pair "make1_1_fst_134" "make1_1_snd_135" 
                                  (apply (ext-identifier src_path of-row-binary) (ptr-add (identifier "drec_snd_132") (size 1))) 
                                  (make-tup (not-null (identifier "make1_1_fst_134")) (identifier "make1_1_snd_135"))))
                              (make-tup
                                (construct "[Compiled {default_params: $program_parameter[[]]; condition: $raql_expr; globals: $global_variable[[]]; funcs: {name: $function_name; retention: $retention?; is_lazy: BOOL; doc: STRING; operation: $raql_operation; out_record: $raql_type; factors: $field_name[[]]; signature: STRING; in_signature: STRING}[[]]} | Failed {err_msg: STRING; depends_on: $src_path?}]" 1
                                  (make-rec (string "err_msg") (identifier "drec_fst_131") (string "depends_on") (identifier "drec_fst_137"))) 
                                (identifier "drec_snd_138")))))))))
                (make-tup (make-rec (string "src_ext") (identifier "drec_fst_69") (string "md5s") (identifier "drec_fst_107") (string "detail") (identifier "drec_fst_319")) (identifier "drec_snd_320"))))))))
 */
static std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary_init()
{
  std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> fun1204 { [&fun1204](Pointer p_0) {
    uint32_t id_1205 { 0U };
    Vec<1, uint32_t> id_1206 {  id_1205  };
    t8beb80162423aee37bd383e9b6834c9c let_res_1207;
    {
      Vec<1, uint32_t> leb_ref_56 { id_1206 };
      uint8_t id_1208 { 0 };
      Vec<1, uint8_t> id_1209 {  id_1208  };
      t8beb80162423aee37bd383e9b6834c9c let_res_1210;
      {
        Vec<1, uint8_t> shft_ref_57 { id_1209 };
        Vec<1, Pointer> id_1211 {  p_0  };
        t8beb80162423aee37bd383e9b6834c9c let_res_1212;
        {
          Vec<1, Pointer> p_ref_58 { id_1211 };
          bool while_flag_1213 { true };
          do {
            uint8_t id_1214 { 0 };
            Pointer id_1215 { p_ref_58[id_1214] };
            tb3f98ea670610d40658a618de3ec7b90 id_1216 { id_1215.readU8() };
            bool let_res_1217;
            {
              tb3f98ea670610d40658a618de3ec7b90 leb128_59 { id_1216 };
              bool letpair_res_1218;
              {
                auto leb128_fst_60 { std::get<0>(leb128_59) };
                auto leb128_snd_61 { std::get<1>(leb128_59) };
                uint8_t id_1219 { 0 };
                Void id_1220 { ((void)(p_ref_58[id_1219] = leb128_snd_61), VOID) };
                (void)id_1220;
                uint8_t id_1221 { 0 };
                uint8_t id_1222 { 127 };
                uint8_t id_1223 { uint8_t(leb128_fst_60 & id_1222) };
                uint32_t id_1224 { uint32_t(id_1223) };
                uint8_t id_1225 { 0 };
                uint8_t id_1226 { shft_ref_57[id_1225] };
                uint32_t id_1227 { uint32_t(id_1224 << id_1226) };
                uint8_t id_1228 { 0 };
                uint32_t id_1229 { leb_ref_56[id_1228] };
                uint32_t id_1230 { uint32_t(id_1227 | id_1229) };
                Void id_1231 { ((void)(leb_ref_56[id_1221] = id_1230), VOID) };
                (void)id_1231;
                uint8_t id_1232 { 0 };
                uint8_t id_1233 { 0 };
                uint8_t id_1234 { shft_ref_57[id_1233] };
                uint8_t id_1235 { 7 };
                uint8_t id_1236 { uint8_t(id_1234 + id_1235) };
                Void id_1237 { ((void)(shft_ref_57[id_1232] = id_1236), VOID) };
                (void)id_1237;
                uint8_t id_1238 { 128 };
                bool id_1239 { bool(leb128_fst_60 >= id_1238) };
                letpair_res_1218 = id_1239;
              }
              let_res_1217 = letpair_res_1218;
            }
            while_flag_1213 = let_res_1217;
            if (while_flag_1213) {
              (void)VOID;
            }
          } while (while_flag_1213);
          (void)VOID;
          uint8_t id_1240 { 0 };
          uint32_t id_1241 { leb_ref_56[id_1240] };
          Size id_1242 { Size(id_1241) };
          uint8_t id_1243 { 0 };
          Pointer id_1244 { p_ref_58[id_1243] };
          t8beb80162423aee37bd383e9b6834c9c id_1245 { id_1242, id_1244 };
          let_res_1212 = id_1245;
        }
        let_res_1210 = let_res_1212;
      }
      let_res_1207 = let_res_1210;
    }
    tef94b55d8809251f13165d9a05bd9d0e let_res_1246;
    {
      t8beb80162423aee37bd383e9b6834c9c dstring1_62 { let_res_1207 };
      tef94b55d8809251f13165d9a05bd9d0e letpair_res_1247;
      {
        auto dstring1_fst_63 { std::get<0>(dstring1_62) };
        auto dstring1_snd_64 { std::get<1>(dstring1_62) };
        t188345aa49abd0cb47ff73fedc219f08 id_1248 { dstring1_snd_64.readBytes(dstring1_fst_63) };
        tef94b55d8809251f13165d9a05bd9d0e letpair_res_1249;
        {
          auto dstring2_fst_66 { std::get<0>(id_1248) };
          auto dstring2_snd_67 { std::get<1>(id_1248) };
          std::string id_1250 { dstring2_fst_66.toString() };
          tef94b55d8809251f13165d9a05bd9d0e id_1251 { id_1250, dstring2_snd_67 };
          letpair_res_1249 = id_1251;
        }
        letpair_res_1247 = letpair_res_1249;
      }
      let_res_1246 = letpair_res_1247;
    }
    t45217dce3db5a9a49037839afd0048e8 let_res_1252;
    {
      tef94b55d8809251f13165d9a05bd9d0e drec_68 { let_res_1246 };
      t45217dce3db5a9a49037839afd0048e8 letpair_res_1253;
      {
        auto drec_fst_69 { std::get<0>(drec_68) };
        auto drec_snd_70 { std::get<1>(drec_68) };
        uint32_t id_1254 { 0U };
        Vec<1, uint32_t> id_1255 {  id_1254  };
        t405eb186408556fed8f2c41523c07d13 let_res_1256;
        {
          Vec<1, uint32_t> leb_ref_71 { id_1255 };
          uint8_t id_1257 { 0 };
          Vec<1, uint8_t> id_1258 {  id_1257  };
          t405eb186408556fed8f2c41523c07d13 let_res_1259;
          {
            Vec<1, uint8_t> shft_ref_72 { id_1258 };
            Vec<1, Pointer> id_1260 {  drec_snd_70  };
            t405eb186408556fed8f2c41523c07d13 let_res_1261;
            {
              Vec<1, Pointer> p_ref_73 { id_1260 };
              bool while_flag_1262 { true };
              do {
                uint8_t id_1263 { 0 };
                Pointer id_1264 { p_ref_73[id_1263] };
                tb3f98ea670610d40658a618de3ec7b90 id_1265 { id_1264.readU8() };
                bool let_res_1266;
                {
                  tb3f98ea670610d40658a618de3ec7b90 leb128_74 { id_1265 };
                  bool letpair_res_1267;
                  {
                    auto leb128_fst_75 { std::get<0>(leb128_74) };
                    auto leb128_snd_76 { std::get<1>(leb128_74) };
                    uint8_t id_1268 { 0 };
                    Void id_1269 { ((void)(p_ref_73[id_1268] = leb128_snd_76), VOID) };
                    (void)id_1269;
                    uint8_t id_1270 { 0 };
                    uint8_t id_1271 { 127 };
                    uint8_t id_1272 { uint8_t(leb128_fst_75 & id_1271) };
                    uint32_t id_1273 { uint32_t(id_1272) };
                    uint8_t id_1274 { 0 };
                    uint8_t id_1275 { shft_ref_72[id_1274] };
                    uint32_t id_1276 { uint32_t(id_1273 << id_1275) };
                    uint8_t id_1277 { 0 };
                    uint32_t id_1278 { leb_ref_71[id_1277] };
                    uint32_t id_1279 { uint32_t(id_1276 | id_1278) };
                    Void id_1280 { ((void)(leb_ref_71[id_1270] = id_1279), VOID) };
                    (void)id_1280;
                    uint8_t id_1281 { 0 };
                    uint8_t id_1282 { 0 };
                    uint8_t id_1283 { shft_ref_72[id_1282] };
                    uint8_t id_1284 { 7 };
                    uint8_t id_1285 { uint8_t(id_1283 + id_1284) };
                    Void id_1286 { ((void)(shft_ref_72[id_1281] = id_1285), VOID) };
                    (void)id_1286;
                    uint8_t id_1287 { 128 };
                    bool id_1288 { bool(leb128_fst_75 >= id_1287) };
                    letpair_res_1267 = id_1288;
                  }
                  let_res_1266 = letpair_res_1267;
                }
                while_flag_1262 = let_res_1266;
                if (while_flag_1262) {
                  (void)VOID;
                }
              } while (while_flag_1262);
              (void)VOID;
              uint8_t id_1289 { 0 };
              uint32_t id_1290 { leb_ref_71[id_1289] };
              uint8_t id_1291 { 0 };
              Pointer id_1292 { p_ref_73[id_1291] };
              t405eb186408556fed8f2c41523c07d13 id_1293 { id_1290, id_1292 };
              let_res_1261 = id_1293;
            }
            let_res_1259 = let_res_1261;
          }
          let_res_1256 = let_res_1259;
        }
        ta48cca69b6e077e610d35192824cedc1 let_res_1294;
        {
          t405eb186408556fed8f2c41523c07d13 dlist1_80 { let_res_1256 };
          ta48cca69b6e077e610d35192824cedc1 letpair_res_1295;
          {
            auto dlist1_fst_81 { std::get<0>(dlist1_80) };
            auto dlist1_snd_82 { std::get<1>(dlist1_80) };
            Lst<std::string> endoflist_1296;
            ta48cca69b6e077e610d35192824cedc1 id_1297 { endoflist_1296, dlist1_snd_82 };
            Vec<1, ta48cca69b6e077e610d35192824cedc1> id_1298 {  id_1297  };
            ta48cca69b6e077e610d35192824cedc1 let_res_1299;
            {
              Vec<1, ta48cca69b6e077e610d35192824cedc1> inits_src_ref_83 { id_1298 };
              int32_t id_1300 { 0L };
              Vec<1, int32_t> id_1301 {  id_1300  };
              {
                Vec<1, int32_t> repeat_n_84 { id_1301 };
                bool while_flag_1302 { true };
                do {
                  int32_t id_1303 { int32_t(dlist1_fst_81) };
                  uint8_t id_1304 { 0 };
                  int32_t id_1305 { repeat_n_84[id_1304] };
                  bool id_1306 { bool(id_1303 > id_1305) };
                  while_flag_1302 = id_1306;
                  if (while_flag_1302) {
                    uint8_t id_1307 { 0 };
                    ta48cca69b6e077e610d35192824cedc1 id_1308 { inits_src_ref_83[id_1307] };
                    {
                      ta48cca69b6e077e610d35192824cedc1 dlist2_85 { id_1308 };
                      {
                        auto dlist2_fst_86 { std::get<0>(dlist2_85) };
                        auto dlist2_snd_87 { std::get<1>(dlist2_85) };
                        uint8_t id_1309 { 0 };
                        uint32_t id_1310 { 0U };
                        Vec<1, uint32_t> id_1311 {  id_1310  };
                        t8beb80162423aee37bd383e9b6834c9c let_res_1312;
                        {
                          Vec<1, uint32_t> leb_ref_88 { id_1311 };
                          uint8_t id_1313 { 0 };
                          Vec<1, uint8_t> id_1314 {  id_1313  };
                          t8beb80162423aee37bd383e9b6834c9c let_res_1315;
                          {
                            Vec<1, uint8_t> shft_ref_89 { id_1314 };
                            Vec<1, Pointer> id_1316 {  dlist2_snd_87  };
                            t8beb80162423aee37bd383e9b6834c9c let_res_1317;
                            {
                              Vec<1, Pointer> p_ref_90 { id_1316 };
                              bool while_flag_1318 { true };
                              do {
                                uint8_t id_1319 { 0 };
                                Pointer id_1320 { p_ref_90[id_1319] };
                                tb3f98ea670610d40658a618de3ec7b90 id_1321 { id_1320.readU8() };
                                bool let_res_1322;
                                {
                                  tb3f98ea670610d40658a618de3ec7b90 leb128_91 { id_1321 };
                                  bool letpair_res_1323;
                                  {
                                    auto leb128_fst_92 { std::get<0>(leb128_91) };
                                    auto leb128_snd_93 { std::get<1>(leb128_91) };
                                    uint8_t id_1324 { 0 };
                                    Void id_1325 { ((void)(p_ref_90[id_1324] = leb128_snd_93), VOID) };
                                    (void)id_1325;
                                    uint8_t id_1326 { 0 };
                                    uint8_t id_1327 { 127 };
                                    uint8_t id_1328 { uint8_t(leb128_fst_92 & id_1327) };
                                    uint32_t id_1329 { uint32_t(id_1328) };
                                    uint8_t id_1330 { 0 };
                                    uint8_t id_1331 { shft_ref_89[id_1330] };
                                    uint32_t id_1332 { uint32_t(id_1329 << id_1331) };
                                    uint8_t id_1333 { 0 };
                                    uint32_t id_1334 { leb_ref_88[id_1333] };
                                    uint32_t id_1335 { uint32_t(id_1332 | id_1334) };
                                    Void id_1336 { ((void)(leb_ref_88[id_1326] = id_1335), VOID) };
                                    (void)id_1336;
                                    uint8_t id_1337 { 0 };
                                    uint8_t id_1338 { 0 };
                                    uint8_t id_1339 { shft_ref_89[id_1338] };
                                    uint8_t id_1340 { 7 };
                                    uint8_t id_1341 { uint8_t(id_1339 + id_1340) };
                                    Void id_1342 { ((void)(shft_ref_89[id_1337] = id_1341), VOID) };
                                    (void)id_1342;
                                    uint8_t id_1343 { 128 };
                                    bool id_1344 { bool(leb128_fst_92 >= id_1343) };
                                    letpair_res_1323 = id_1344;
                                  }
                                  let_res_1322 = letpair_res_1323;
                                }
                                while_flag_1318 = let_res_1322;
                                if (while_flag_1318) {
                                  (void)VOID;
                                }
                              } while (while_flag_1318);
                              (void)VOID;
                              uint8_t id_1345 { 0 };
                              uint32_t id_1346 { leb_ref_88[id_1345] };
                              Size id_1347 { Size(id_1346) };
                              uint8_t id_1348 { 0 };
                              Pointer id_1349 { p_ref_90[id_1348] };
                              t8beb80162423aee37bd383e9b6834c9c id_1350 { id_1347, id_1349 };
                              let_res_1317 = id_1350;
                            }
                            let_res_1315 = let_res_1317;
                          }
                          let_res_1312 = let_res_1315;
                        }
                        ta48cca69b6e077e610d35192824cedc1 let_res_1351;
                        {
                          t8beb80162423aee37bd383e9b6834c9c dstring1_94 { let_res_1312 };
                          ta48cca69b6e077e610d35192824cedc1 letpair_res_1352;
                          {
                            auto dstring1_fst_95 { std::get<0>(dstring1_94) };
                            auto dstring1_snd_96 { std::get<1>(dstring1_94) };
                            t188345aa49abd0cb47ff73fedc219f08 id_1353 { dstring1_snd_96.readBytes(dstring1_fst_95) };
                            ta48cca69b6e077e610d35192824cedc1 letpair_res_1354;
                            {
                              auto dstring2_fst_98 { std::get<0>(id_1353) };
                              auto dstring2_snd_99 { std::get<1>(id_1353) };
                              std::string id_1355 { dstring2_fst_98.toString() };
                              Lst<std::string> id_1356 { id_1355, dlist2_fst_86 };
                              ta48cca69b6e077e610d35192824cedc1 id_1357 { id_1356, dstring2_snd_99 };
                              letpair_res_1354 = id_1357;
                            }
                            letpair_res_1352 = letpair_res_1354;
                          }
                          let_res_1351 = letpair_res_1352;
                        }
                        Void id_1358 { ((void)(inits_src_ref_83[id_1309] = let_res_1351), VOID) };
                        (void)id_1358;
                      }
                      (void)VOID;
                    }
                    (void)VOID;
                    uint8_t id_1359 { 0 };
                    uint8_t id_1360 { 0 };
                    int32_t id_1361 { repeat_n_84[id_1360] };
                    int32_t id_1362 { 1L };
                    int32_t id_1363 { int32_t(id_1361 + id_1362) };
                    Void id_1364 { ((void)(repeat_n_84[id_1359] = id_1363), VOID) };
                    (void)id_1364;
                    (void)id_1364;
                  }
                } while (while_flag_1302);
                (void)VOID;
              }
              (void)VOID;
              uint8_t id_1365 { 0 };
              ta48cca69b6e077e610d35192824cedc1 id_1366 { inits_src_ref_83[id_1365] };
              let_res_1299 = id_1366;
            }
            letpair_res_1295 = let_res_1299;
          }
          let_res_1294 = letpair_res_1295;
        }
        ta48cca69b6e077e610d35192824cedc1 letpair_res_1367;
        {
          auto dlist4_fst_104 { std::get<0>(let_res_1294) };
          auto dlist4_snd_105 { std::get<1>(let_res_1294) };
          ta48cca69b6e077e610d35192824cedc1 id_1368 { dlist4_fst_104, dlist4_snd_105 };
          letpair_res_1367 = id_1368;
        }
        t45217dce3db5a9a49037839afd0048e8 let_res_1369;
        {
          ta48cca69b6e077e610d35192824cedc1 drec_106 { letpair_res_1367 };
          t45217dce3db5a9a49037839afd0048e8 letpair_res_1370;
          {
            auto drec_fst_107 { std::get<0>(drec_106) };
            auto drec_snd_108 { std::get<1>(drec_106) };
            t22a32080ad88ab548b80077a17b7dd46 id_1371 { drec_snd_108.readU16Le() };
            t22a32080ad88ab548b80077a17b7dd46 letpair_res_1372;
            {
              auto du16_fst_110 { std::get<0>(id_1371) };
              auto du16_snd_111 { std::get<1>(id_1371) };
              t22a32080ad88ab548b80077a17b7dd46 id_1373 { du16_fst_110, du16_snd_111 };
              letpair_res_1372 = id_1373;
            }
            tb0e3f2c9b734bb327b41592ba7807707 let_res_1374;
            {
              t22a32080ad88ab548b80077a17b7dd46 dsum1_115 { letpair_res_1372 };
              tb0e3f2c9b734bb327b41592ba7807707 letpair_res_1375;
              {
                auto dsum1_fst_116 { std::get<0>(dsum1_115) };
                auto dsum1_snd_117 { std::get<1>(dsum1_115) };
                uint16_t id_1376 { 0 };
                bool id_1377 { bool(id_1376 == dsum1_fst_116) };
                tb0e3f2c9b734bb327b41592ba7807707 choose_res_1378;
                if (id_1377) {
                  uint32_t id_1379 { 0U };
                  Vec<1, uint32_t> id_1380 {  id_1379  };
                  t405eb186408556fed8f2c41523c07d13 let_res_1381;
                  {
                    Vec<1, uint32_t> leb_ref_142 { id_1380 };
                    uint8_t id_1382 { 0 };
                    Vec<1, uint8_t> id_1383 {  id_1382  };
                    t405eb186408556fed8f2c41523c07d13 let_res_1384;
                    {
                      Vec<1, uint8_t> shft_ref_143 { id_1383 };
                      Vec<1, Pointer> id_1385 {  dsum1_snd_117  };
                      t405eb186408556fed8f2c41523c07d13 let_res_1386;
                      {
                        Vec<1, Pointer> p_ref_144 { id_1385 };
                        bool while_flag_1387 { true };
                        do {
                          uint8_t id_1388 { 0 };
                          Pointer id_1389 { p_ref_144[id_1388] };
                          tb3f98ea670610d40658a618de3ec7b90 id_1390 { id_1389.readU8() };
                          bool let_res_1391;
                          {
                            tb3f98ea670610d40658a618de3ec7b90 leb128_145 { id_1390 };
                            bool letpair_res_1392;
                            {
                              auto leb128_fst_146 { std::get<0>(leb128_145) };
                              auto leb128_snd_147 { std::get<1>(leb128_145) };
                              uint8_t id_1393 { 0 };
                              Void id_1394 { ((void)(p_ref_144[id_1393] = leb128_snd_147), VOID) };
                              (void)id_1394;
                              uint8_t id_1395 { 0 };
                              uint8_t id_1396 { 127 };
                              uint8_t id_1397 { uint8_t(leb128_fst_146 & id_1396) };
                              uint32_t id_1398 { uint32_t(id_1397) };
                              uint8_t id_1399 { 0 };
                              uint8_t id_1400 { shft_ref_143[id_1399] };
                              uint32_t id_1401 { uint32_t(id_1398 << id_1400) };
                              uint8_t id_1402 { 0 };
                              uint32_t id_1403 { leb_ref_142[id_1402] };
                              uint32_t id_1404 { uint32_t(id_1401 | id_1403) };
                              Void id_1405 { ((void)(leb_ref_142[id_1395] = id_1404), VOID) };
                              (void)id_1405;
                              uint8_t id_1406 { 0 };
                              uint8_t id_1407 { 0 };
                              uint8_t id_1408 { shft_ref_143[id_1407] };
                              uint8_t id_1409 { 7 };
                              uint8_t id_1410 { uint8_t(id_1408 + id_1409) };
                              Void id_1411 { ((void)(shft_ref_143[id_1406] = id_1410), VOID) };
                              (void)id_1411;
                              uint8_t id_1412 { 128 };
                              bool id_1413 { bool(leb128_fst_146 >= id_1412) };
                              letpair_res_1392 = id_1413;
                            }
                            let_res_1391 = letpair_res_1392;
                          }
                          while_flag_1387 = let_res_1391;
                          if (while_flag_1387) {
                            (void)VOID;
                          }
                        } while (while_flag_1387);
                        (void)VOID;
                        uint8_t id_1414 { 0 };
                        uint32_t id_1415 { leb_ref_142[id_1414] };
                        uint8_t id_1416 { 0 };
                        Pointer id_1417 { p_ref_144[id_1416] };
                        t405eb186408556fed8f2c41523c07d13 id_1418 { id_1415, id_1417 };
                        let_res_1386 = id_1418;
                      }
                      let_res_1384 = let_res_1386;
                    }
                    let_res_1381 = let_res_1384;
                  }
                  t72c0be8b93ff5eeb0f991b2e0e95f3b9 let_res_1419;
                  {
                    t405eb186408556fed8f2c41523c07d13 dlist1_151 { let_res_1381 };
                    t72c0be8b93ff5eeb0f991b2e0e95f3b9 letpair_res_1420;
                    {
                      auto dlist1_fst_152 { std::get<0>(dlist1_151) };
                      auto dlist1_snd_153 { std::get<1>(dlist1_151) };
                      Lst<dessser::gen::program_parameter::t_ext> endoflist_1421;
                      t72c0be8b93ff5eeb0f991b2e0e95f3b9 id_1422 { endoflist_1421, dlist1_snd_153 };
                      Vec<1, t72c0be8b93ff5eeb0f991b2e0e95f3b9> id_1423 {  id_1422  };
                      t72c0be8b93ff5eeb0f991b2e0e95f3b9 let_res_1424;
                      {
                        Vec<1, t72c0be8b93ff5eeb0f991b2e0e95f3b9> inits_src_ref_154 { id_1423 };
                        int32_t id_1425 { 0L };
                        Vec<1, int32_t> id_1426 {  id_1425  };
                        {
                          Vec<1, int32_t> repeat_n_155 { id_1426 };
                          bool while_flag_1427 { true };
                          do {
                            int32_t id_1428 { int32_t(dlist1_fst_152) };
                            uint8_t id_1429 { 0 };
                            int32_t id_1430 { repeat_n_155[id_1429] };
                            bool id_1431 { bool(id_1428 > id_1430) };
                            while_flag_1427 = id_1431;
                            if (while_flag_1427) {
                              uint8_t id_1432 { 0 };
                              t72c0be8b93ff5eeb0f991b2e0e95f3b9 id_1433 { inits_src_ref_154[id_1432] };
                              {
                                t72c0be8b93ff5eeb0f991b2e0e95f3b9 dlist2_156 { id_1433 };
                                {
                                  auto dlist2_fst_157 { std::get<0>(dlist2_156) };
                                  auto dlist2_snd_158 { std::get<1>(dlist2_156) };
                                  uint8_t id_1434 { 0 };
                                  auto fun1435 { dessser::gen::program_parameter::of_row_binary };
                                  t0d694f310c72fe705045b499b1bf4849 id_1436 { fun1435(dlist2_snd_158) };
                                  t72c0be8b93ff5eeb0f991b2e0e95f3b9 letpair_res_1437;
                                  {
                                    auto dlist3_fst_160 { std::get<0>(id_1436) };
                                    auto dlist3_snd_161 { std::get<1>(id_1436) };
                                    Lst<dessser::gen::program_parameter::t_ext> id_1438 { dlist3_fst_160, dlist2_fst_157 };
                                    t72c0be8b93ff5eeb0f991b2e0e95f3b9 id_1439 { id_1438, dlist3_snd_161 };
                                    letpair_res_1437 = id_1439;
                                  }
                                  Void id_1440 { ((void)(inits_src_ref_154[id_1434] = letpair_res_1437), VOID) };
                                  (void)id_1440;
                                }
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_1441 { 0 };
                              uint8_t id_1442 { 0 };
                              int32_t id_1443 { repeat_n_155[id_1442] };
                              int32_t id_1444 { 1L };
                              int32_t id_1445 { int32_t(id_1443 + id_1444) };
                              Void id_1446 { ((void)(repeat_n_155[id_1441] = id_1445), VOID) };
                              (void)id_1446;
                              (void)id_1446;
                            }
                          } while (while_flag_1427);
                          (void)VOID;
                        }
                        (void)VOID;
                        uint8_t id_1447 { 0 };
                        t72c0be8b93ff5eeb0f991b2e0e95f3b9 id_1448 { inits_src_ref_154[id_1447] };
                        let_res_1424 = id_1448;
                      }
                      letpair_res_1420 = let_res_1424;
                    }
                    let_res_1419 = letpair_res_1420;
                  }
                  t72c0be8b93ff5eeb0f991b2e0e95f3b9 letpair_res_1449;
                  {
                    auto dlist4_fst_163 { std::get<0>(let_res_1419) };
                    auto dlist4_snd_164 { std::get<1>(let_res_1419) };
                    t72c0be8b93ff5eeb0f991b2e0e95f3b9 id_1450 { dlist4_fst_163, dlist4_snd_164 };
                    letpair_res_1449 = id_1450;
                  }
                  tb0e3f2c9b734bb327b41592ba7807707 let_res_1451;
                  {
                    t72c0be8b93ff5eeb0f991b2e0e95f3b9 drec_165 { letpair_res_1449 };
                    tb0e3f2c9b734bb327b41592ba7807707 letpair_res_1452;
                    {
                      auto drec_fst_166 { std::get<0>(drec_165) };
                      auto drec_snd_167 { std::get<1>(drec_165) };
                      auto fun1453 { dessser::gen::raql_expr::of_row_binary };
                      t1113e6691818baaf60a775527f6cc1ac id_1454 { fun1453(drec_snd_167) };
                      tb0e3f2c9b734bb327b41592ba7807707 let_res_1455;
                      {
                        t1113e6691818baaf60a775527f6cc1ac drec_168 { id_1454 };
                        tb0e3f2c9b734bb327b41592ba7807707 letpair_res_1456;
                        {
                          auto drec_fst_169 { std::get<0>(drec_168) };
                          auto drec_snd_170 { std::get<1>(drec_168) };
                          uint32_t id_1457 { 0U };
                          Vec<1, uint32_t> id_1458 {  id_1457  };
                          t405eb186408556fed8f2c41523c07d13 let_res_1459;
                          {
                            Vec<1, uint32_t> leb_ref_171 { id_1458 };
                            uint8_t id_1460 { 0 };
                            Vec<1, uint8_t> id_1461 {  id_1460  };
                            t405eb186408556fed8f2c41523c07d13 let_res_1462;
                            {
                              Vec<1, uint8_t> shft_ref_172 { id_1461 };
                              Vec<1, Pointer> id_1463 {  drec_snd_170  };
                              t405eb186408556fed8f2c41523c07d13 let_res_1464;
                              {
                                Vec<1, Pointer> p_ref_173 { id_1463 };
                                bool while_flag_1465 { true };
                                do {
                                  uint8_t id_1466 { 0 };
                                  Pointer id_1467 { p_ref_173[id_1466] };
                                  tb3f98ea670610d40658a618de3ec7b90 id_1468 { id_1467.readU8() };
                                  bool let_res_1469;
                                  {
                                    tb3f98ea670610d40658a618de3ec7b90 leb128_174 { id_1468 };
                                    bool letpair_res_1470;
                                    {
                                      auto leb128_fst_175 { std::get<0>(leb128_174) };
                                      auto leb128_snd_176 { std::get<1>(leb128_174) };
                                      uint8_t id_1471 { 0 };
                                      Void id_1472 { ((void)(p_ref_173[id_1471] = leb128_snd_176), VOID) };
                                      (void)id_1472;
                                      uint8_t id_1473 { 0 };
                                      uint8_t id_1474 { 127 };
                                      uint8_t id_1475 { uint8_t(leb128_fst_175 & id_1474) };
                                      uint32_t id_1476 { uint32_t(id_1475) };
                                      uint8_t id_1477 { 0 };
                                      uint8_t id_1478 { shft_ref_172[id_1477] };
                                      uint32_t id_1479 { uint32_t(id_1476 << id_1478) };
                                      uint8_t id_1480 { 0 };
                                      uint32_t id_1481 { leb_ref_171[id_1480] };
                                      uint32_t id_1482 { uint32_t(id_1479 | id_1481) };
                                      Void id_1483 { ((void)(leb_ref_171[id_1473] = id_1482), VOID) };
                                      (void)id_1483;
                                      uint8_t id_1484 { 0 };
                                      uint8_t id_1485 { 0 };
                                      uint8_t id_1486 { shft_ref_172[id_1485] };
                                      uint8_t id_1487 { 7 };
                                      uint8_t id_1488 { uint8_t(id_1486 + id_1487) };
                                      Void id_1489 { ((void)(shft_ref_172[id_1484] = id_1488), VOID) };
                                      (void)id_1489;
                                      uint8_t id_1490 { 128 };
                                      bool id_1491 { bool(leb128_fst_175 >= id_1490) };
                                      letpair_res_1470 = id_1491;
                                    }
                                    let_res_1469 = letpair_res_1470;
                                  }
                                  while_flag_1465 = let_res_1469;
                                  if (while_flag_1465) {
                                    (void)VOID;
                                  }
                                } while (while_flag_1465);
                                (void)VOID;
                                uint8_t id_1492 { 0 };
                                uint32_t id_1493 { leb_ref_171[id_1492] };
                                uint8_t id_1494 { 0 };
                                Pointer id_1495 { p_ref_173[id_1494] };
                                t405eb186408556fed8f2c41523c07d13 id_1496 { id_1493, id_1495 };
                                let_res_1464 = id_1496;
                              }
                              let_res_1462 = let_res_1464;
                            }
                            let_res_1459 = let_res_1462;
                          }
                          t8eecaa544f974ea6c77122c0d4c2f67e let_res_1497;
                          {
                            t405eb186408556fed8f2c41523c07d13 dlist1_180 { let_res_1459 };
                            t8eecaa544f974ea6c77122c0d4c2f67e letpair_res_1498;
                            {
                              auto dlist1_fst_181 { std::get<0>(dlist1_180) };
                              auto dlist1_snd_182 { std::get<1>(dlist1_180) };
                              Lst<dessser::gen::global_variable::t_ext> endoflist_1499;
                              t8eecaa544f974ea6c77122c0d4c2f67e id_1500 { endoflist_1499, dlist1_snd_182 };
                              Vec<1, t8eecaa544f974ea6c77122c0d4c2f67e> id_1501 {  id_1500  };
                              t8eecaa544f974ea6c77122c0d4c2f67e let_res_1502;
                              {
                                Vec<1, t8eecaa544f974ea6c77122c0d4c2f67e> inits_src_ref_183 { id_1501 };
                                int32_t id_1503 { 0L };
                                Vec<1, int32_t> id_1504 {  id_1503  };
                                {
                                  Vec<1, int32_t> repeat_n_184 { id_1504 };
                                  bool while_flag_1505 { true };
                                  do {
                                    int32_t id_1506 { int32_t(dlist1_fst_181) };
                                    uint8_t id_1507 { 0 };
                                    int32_t id_1508 { repeat_n_184[id_1507] };
                                    bool id_1509 { bool(id_1506 > id_1508) };
                                    while_flag_1505 = id_1509;
                                    if (while_flag_1505) {
                                      uint8_t id_1510 { 0 };
                                      t8eecaa544f974ea6c77122c0d4c2f67e id_1511 { inits_src_ref_183[id_1510] };
                                      {
                                        t8eecaa544f974ea6c77122c0d4c2f67e dlist2_185 { id_1511 };
                                        {
                                          auto dlist2_fst_186 { std::get<0>(dlist2_185) };
                                          auto dlist2_snd_187 { std::get<1>(dlist2_185) };
                                          uint8_t id_1512 { 0 };
                                          auto fun1513 { dessser::gen::global_variable::of_row_binary };
                                          t911eab4a6da5a01e780085a224d7ed2a id_1514 { fun1513(dlist2_snd_187) };
                                          t8eecaa544f974ea6c77122c0d4c2f67e letpair_res_1515;
                                          {
                                            auto dlist3_fst_189 { std::get<0>(id_1514) };
                                            auto dlist3_snd_190 { std::get<1>(id_1514) };
                                            Lst<dessser::gen::global_variable::t_ext> id_1516 { dlist3_fst_189, dlist2_fst_186 };
                                            t8eecaa544f974ea6c77122c0d4c2f67e id_1517 { id_1516, dlist3_snd_190 };
                                            letpair_res_1515 = id_1517;
                                          }
                                          Void id_1518 { ((void)(inits_src_ref_183[id_1512] = letpair_res_1515), VOID) };
                                          (void)id_1518;
                                        }
                                        (void)VOID;
                                      }
                                      (void)VOID;
                                      uint8_t id_1519 { 0 };
                                      uint8_t id_1520 { 0 };
                                      int32_t id_1521 { repeat_n_184[id_1520] };
                                      int32_t id_1522 { 1L };
                                      int32_t id_1523 { int32_t(id_1521 + id_1522) };
                                      Void id_1524 { ((void)(repeat_n_184[id_1519] = id_1523), VOID) };
                                      (void)id_1524;
                                      (void)id_1524;
                                    }
                                  } while (while_flag_1505);
                                  (void)VOID;
                                }
                                (void)VOID;
                                uint8_t id_1525 { 0 };
                                t8eecaa544f974ea6c77122c0d4c2f67e id_1526 { inits_src_ref_183[id_1525] };
                                let_res_1502 = id_1526;
                              }
                              letpair_res_1498 = let_res_1502;
                            }
                            let_res_1497 = letpair_res_1498;
                          }
                          t8eecaa544f974ea6c77122c0d4c2f67e letpair_res_1527;
                          {
                            auto dlist4_fst_192 { std::get<0>(let_res_1497) };
                            auto dlist4_snd_193 { std::get<1>(let_res_1497) };
                            t8eecaa544f974ea6c77122c0d4c2f67e id_1528 { dlist4_fst_192, dlist4_snd_193 };
                            letpair_res_1527 = id_1528;
                          }
                          tb0e3f2c9b734bb327b41592ba7807707 let_res_1529;
                          {
                            t8eecaa544f974ea6c77122c0d4c2f67e drec_194 { letpair_res_1527 };
                            tb0e3f2c9b734bb327b41592ba7807707 letpair_res_1530;
                            {
                              auto drec_fst_195 { std::get<0>(drec_194) };
                              auto drec_snd_196 { std::get<1>(drec_194) };
                              uint32_t id_1531 { 0U };
                              Vec<1, uint32_t> id_1532 {  id_1531  };
                              t405eb186408556fed8f2c41523c07d13 let_res_1533;
                              {
                                Vec<1, uint32_t> leb_ref_197 { id_1532 };
                                uint8_t id_1534 { 0 };
                                Vec<1, uint8_t> id_1535 {  id_1534  };
                                t405eb186408556fed8f2c41523c07d13 let_res_1536;
                                {
                                  Vec<1, uint8_t> shft_ref_198 { id_1535 };
                                  Vec<1, Pointer> id_1537 {  drec_snd_196  };
                                  t405eb186408556fed8f2c41523c07d13 let_res_1538;
                                  {
                                    Vec<1, Pointer> p_ref_199 { id_1537 };
                                    bool while_flag_1539 { true };
                                    do {
                                      uint8_t id_1540 { 0 };
                                      Pointer id_1541 { p_ref_199[id_1540] };
                                      tb3f98ea670610d40658a618de3ec7b90 id_1542 { id_1541.readU8() };
                                      bool let_res_1543;
                                      {
                                        tb3f98ea670610d40658a618de3ec7b90 leb128_200 { id_1542 };
                                        bool letpair_res_1544;
                                        {
                                          auto leb128_fst_201 { std::get<0>(leb128_200) };
                                          auto leb128_snd_202 { std::get<1>(leb128_200) };
                                          uint8_t id_1545 { 0 };
                                          Void id_1546 { ((void)(p_ref_199[id_1545] = leb128_snd_202), VOID) };
                                          (void)id_1546;
                                          uint8_t id_1547 { 0 };
                                          uint8_t id_1548 { 127 };
                                          uint8_t id_1549 { uint8_t(leb128_fst_201 & id_1548) };
                                          uint32_t id_1550 { uint32_t(id_1549) };
                                          uint8_t id_1551 { 0 };
                                          uint8_t id_1552 { shft_ref_198[id_1551] };
                                          uint32_t id_1553 { uint32_t(id_1550 << id_1552) };
                                          uint8_t id_1554 { 0 };
                                          uint32_t id_1555 { leb_ref_197[id_1554] };
                                          uint32_t id_1556 { uint32_t(id_1553 | id_1555) };
                                          Void id_1557 { ((void)(leb_ref_197[id_1547] = id_1556), VOID) };
                                          (void)id_1557;
                                          uint8_t id_1558 { 0 };
                                          uint8_t id_1559 { 0 };
                                          uint8_t id_1560 { shft_ref_198[id_1559] };
                                          uint8_t id_1561 { 7 };
                                          uint8_t id_1562 { uint8_t(id_1560 + id_1561) };
                                          Void id_1563 { ((void)(shft_ref_198[id_1558] = id_1562), VOID) };
                                          (void)id_1563;
                                          uint8_t id_1564 { 128 };
                                          bool id_1565 { bool(leb128_fst_201 >= id_1564) };
                                          letpair_res_1544 = id_1565;
                                        }
                                        let_res_1543 = letpair_res_1544;
                                      }
                                      while_flag_1539 = let_res_1543;
                                      if (while_flag_1539) {
                                        (void)VOID;
                                      }
                                    } while (while_flag_1539);
                                    (void)VOID;
                                    uint8_t id_1566 { 0 };
                                    uint32_t id_1567 { leb_ref_197[id_1566] };
                                    uint8_t id_1568 { 0 };
                                    Pointer id_1569 { p_ref_199[id_1568] };
                                    t405eb186408556fed8f2c41523c07d13 id_1570 { id_1567, id_1569 };
                                    let_res_1538 = id_1570;
                                  }
                                  let_res_1536 = let_res_1538;
                                }
                                let_res_1533 = let_res_1536;
                              }
                              t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1571;
                              {
                                t405eb186408556fed8f2c41523c07d13 dlist1_206 { let_res_1533 };
                                t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1572;
                                {
                                  auto dlist1_fst_207 { std::get<0>(dlist1_206) };
                                  auto dlist1_snd_208 { std::get<1>(dlist1_206) };
                                  Lst<tb0a5947d2e730ef2c38de99be0c65701> endoflist_1573;
                                  t99bf25e2852182fc53ed35e1ddb06ab9 id_1574 { endoflist_1573, dlist1_snd_208 };
                                  Vec<1, t99bf25e2852182fc53ed35e1ddb06ab9> id_1575 {  id_1574  };
                                  t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1576;
                                  {
                                    Vec<1, t99bf25e2852182fc53ed35e1ddb06ab9> inits_src_ref_209 { id_1575 };
                                    int32_t id_1577 { 0L };
                                    Vec<1, int32_t> id_1578 {  id_1577  };
                                    {
                                      Vec<1, int32_t> repeat_n_210 { id_1578 };
                                      bool while_flag_1579 { true };
                                      do {
                                        int32_t id_1580 { int32_t(dlist1_fst_207) };
                                        uint8_t id_1581 { 0 };
                                        int32_t id_1582 { repeat_n_210[id_1581] };
                                        bool id_1583 { bool(id_1580 > id_1582) };
                                        while_flag_1579 = id_1583;
                                        if (while_flag_1579) {
                                          uint8_t id_1584 { 0 };
                                          t99bf25e2852182fc53ed35e1ddb06ab9 id_1585 { inits_src_ref_209[id_1584] };
                                          {
                                            t99bf25e2852182fc53ed35e1ddb06ab9 dlist2_211 { id_1585 };
                                            {
                                              auto dlist2_fst_212 { std::get<0>(dlist2_211) };
                                              auto dlist2_snd_213 { std::get<1>(dlist2_211) };
                                              uint8_t id_1586 { 0 };
                                              auto fun1587 { dessser::gen::function_name::of_row_binary };
                                              tc7d3fcfd06c0f02b3732e1754a18402b id_1588 { fun1587(dlist2_snd_213) };
                                              t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1589;
                                              {
                                                tc7d3fcfd06c0f02b3732e1754a18402b drec_214 { id_1588 };
                                                t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1590;
                                                {
                                                  auto drec_fst_215 { std::get<0>(drec_214) };
                                                  auto drec_snd_216 { std::get<1>(drec_214) };
                                                  Size id_1591 { 0UL };
                                                  uint8_t id_1592 { drec_snd_216.peekU8(id_1591) };
                                                  uint8_t id_1593 { 1 };
                                                  bool id_1594 { bool(id_1592 == id_1593) };
                                                  td0d099f587b9e25386cc3fd1ecb674a4 choose_res_1595;
                                                  if (id_1594) {
                                                    std::optional<dessser::gen::retention::t_ext> id_1596 { std::nullopt };
                                                    Size id_1597 { 1UL };
                                                    Pointer id_1598 { drec_snd_216.skip(id_1597) };
                                                    td0d099f587b9e25386cc3fd1ecb674a4 id_1599 { id_1596, id_1598 };
                                                    choose_res_1595 = id_1599;
                                                  } else {
                                                    auto fun1600 { dessser::gen::retention::of_row_binary };
                                                    Size id_1601 { 1UL };
                                                    Pointer id_1602 { drec_snd_216.skip(id_1601) };
                                                    t7c83e84e0162e9442953bc16c018e153 id_1603 { fun1600(id_1602) };
                                                    td0d099f587b9e25386cc3fd1ecb674a4 letpair_res_1604;
                                                    {
                                                      auto make1_1_fst_218 { std::get<0>(id_1603) };
                                                      auto make1_1_snd_219 { std::get<1>(id_1603) };
                                                      std::optional<dessser::gen::retention::t_ext> id_1605 { make1_1_fst_218 };
                                                      td0d099f587b9e25386cc3fd1ecb674a4 id_1606 { id_1605, make1_1_snd_219 };
                                                      letpair_res_1604 = id_1606;
                                                    }
                                                    choose_res_1595 = letpair_res_1604;
                                                  }
                                                  t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1607;
                                                  {
                                                    td0d099f587b9e25386cc3fd1ecb674a4 drec_220 { choose_res_1595 };
                                                    t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1608;
                                                    {
                                                      auto drec_fst_221 { std::get<0>(drec_220) };
                                                      auto drec_snd_222 { std::get<1>(drec_220) };
                                                      tb3f98ea670610d40658a618de3ec7b90 id_1609 { drec_snd_222.readU8() };
                                                      t4138de986e20d18b01e4c493dc9d5451 letpair_res_1610;
                                                      {
                                                        auto dbool_fst_224 { std::get<0>(id_1609) };
                                                        auto dbool_snd_225 { std::get<1>(id_1609) };
                                                        uint8_t id_1611 { 0 };
                                                        bool id_1612 { bool(dbool_fst_224 == id_1611) };
                                                        bool id_1613 { ! id_1612 };
                                                        t4138de986e20d18b01e4c493dc9d5451 id_1614 { id_1613, dbool_snd_225 };
                                                        letpair_res_1610 = id_1614;
                                                      }
                                                      t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1615;
                                                      {
                                                        t4138de986e20d18b01e4c493dc9d5451 drec_226 { letpair_res_1610 };
                                                        t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1616;
                                                        {
                                                          auto drec_fst_227 { std::get<0>(drec_226) };
                                                          auto drec_snd_228 { std::get<1>(drec_226) };
                                                          uint32_t id_1617 { 0U };
                                                          Vec<1, uint32_t> id_1618 {  id_1617  };
                                                          t8beb80162423aee37bd383e9b6834c9c let_res_1619;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_229 { id_1618 };
                                                            uint8_t id_1620 { 0 };
                                                            Vec<1, uint8_t> id_1621 {  id_1620  };
                                                            t8beb80162423aee37bd383e9b6834c9c let_res_1622;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_230 { id_1621 };
                                                              Vec<1, Pointer> id_1623 {  drec_snd_228  };
                                                              t8beb80162423aee37bd383e9b6834c9c let_res_1624;
                                                              {
                                                                Vec<1, Pointer> p_ref_231 { id_1623 };
                                                                bool while_flag_1625 { true };
                                                                do {
                                                                  uint8_t id_1626 { 0 };
                                                                  Pointer id_1627 { p_ref_231[id_1626] };
                                                                  tb3f98ea670610d40658a618de3ec7b90 id_1628 { id_1627.readU8() };
                                                                  bool let_res_1629;
                                                                  {
                                                                    tb3f98ea670610d40658a618de3ec7b90 leb128_232 { id_1628 };
                                                                    bool letpair_res_1630;
                                                                    {
                                                                      auto leb128_fst_233 { std::get<0>(leb128_232) };
                                                                      auto leb128_snd_234 { std::get<1>(leb128_232) };
                                                                      uint8_t id_1631 { 0 };
                                                                      Void id_1632 { ((void)(p_ref_231[id_1631] = leb128_snd_234), VOID) };
                                                                      (void)id_1632;
                                                                      uint8_t id_1633 { 0 };
                                                                      uint8_t id_1634 { 127 };
                                                                      uint8_t id_1635 { uint8_t(leb128_fst_233 & id_1634) };
                                                                      uint32_t id_1636 { uint32_t(id_1635) };
                                                                      uint8_t id_1637 { 0 };
                                                                      uint8_t id_1638 { shft_ref_230[id_1637] };
                                                                      uint32_t id_1639 { uint32_t(id_1636 << id_1638) };
                                                                      uint8_t id_1640 { 0 };
                                                                      uint32_t id_1641 { leb_ref_229[id_1640] };
                                                                      uint32_t id_1642 { uint32_t(id_1639 | id_1641) };
                                                                      Void id_1643 { ((void)(leb_ref_229[id_1633] = id_1642), VOID) };
                                                                      (void)id_1643;
                                                                      uint8_t id_1644 { 0 };
                                                                      uint8_t id_1645 { 0 };
                                                                      uint8_t id_1646 { shft_ref_230[id_1645] };
                                                                      uint8_t id_1647 { 7 };
                                                                      uint8_t id_1648 { uint8_t(id_1646 + id_1647) };
                                                                      Void id_1649 { ((void)(shft_ref_230[id_1644] = id_1648), VOID) };
                                                                      (void)id_1649;
                                                                      uint8_t id_1650 { 128 };
                                                                      bool id_1651 { bool(leb128_fst_233 >= id_1650) };
                                                                      letpair_res_1630 = id_1651;
                                                                    }
                                                                    let_res_1629 = letpair_res_1630;
                                                                  }
                                                                  while_flag_1625 = let_res_1629;
                                                                  if (while_flag_1625) {
                                                                    (void)VOID;
                                                                  }
                                                                } while (while_flag_1625);
                                                                (void)VOID;
                                                                uint8_t id_1652 { 0 };
                                                                uint32_t id_1653 { leb_ref_229[id_1652] };
                                                                Size id_1654 { Size(id_1653) };
                                                                uint8_t id_1655 { 0 };
                                                                Pointer id_1656 { p_ref_231[id_1655] };
                                                                t8beb80162423aee37bd383e9b6834c9c id_1657 { id_1654, id_1656 };
                                                                let_res_1624 = id_1657;
                                                              }
                                                              let_res_1622 = let_res_1624;
                                                            }
                                                            let_res_1619 = let_res_1622;
                                                          }
                                                          tef94b55d8809251f13165d9a05bd9d0e let_res_1658;
                                                          {
                                                            t8beb80162423aee37bd383e9b6834c9c dstring1_235 { let_res_1619 };
                                                            tef94b55d8809251f13165d9a05bd9d0e letpair_res_1659;
                                                            {
                                                              auto dstring1_fst_236 { std::get<0>(dstring1_235) };
                                                              auto dstring1_snd_237 { std::get<1>(dstring1_235) };
                                                              t188345aa49abd0cb47ff73fedc219f08 id_1660 { dstring1_snd_237.readBytes(dstring1_fst_236) };
                                                              tef94b55d8809251f13165d9a05bd9d0e letpair_res_1661;
                                                              {
                                                                auto dstring2_fst_239 { std::get<0>(id_1660) };
                                                                auto dstring2_snd_240 { std::get<1>(id_1660) };
                                                                std::string id_1662 { dstring2_fst_239.toString() };
                                                                tef94b55d8809251f13165d9a05bd9d0e id_1663 { id_1662, dstring2_snd_240 };
                                                                letpair_res_1661 = id_1663;
                                                              }
                                                              letpair_res_1659 = letpair_res_1661;
                                                            }
                                                            let_res_1658 = letpair_res_1659;
                                                          }
                                                          t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1664;
                                                          {
                                                            tef94b55d8809251f13165d9a05bd9d0e drec_241 { let_res_1658 };
                                                            t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1665;
                                                            {
                                                              auto drec_fst_242 { std::get<0>(drec_241) };
                                                              auto drec_snd_243 { std::get<1>(drec_241) };
                                                              auto fun1666 { dessser::gen::raql_operation::of_row_binary };
                                                              ta546df8799999c6d44c12cb331e3c39d id_1667 { fun1666(drec_snd_243) };
                                                              t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1668;
                                                              {
                                                                ta546df8799999c6d44c12cb331e3c39d drec_244 { id_1667 };
                                                                t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1669;
                                                                {
                                                                  auto drec_fst_245 { std::get<0>(drec_244) };
                                                                  auto drec_snd_246 { std::get<1>(drec_244) };
                                                                  auto fun1670 { dessser::gen::raql_type::of_row_binary };
                                                                  t2f923f73303f235bd6ab3a4150418dd9 id_1671 { fun1670(drec_snd_246) };
                                                                  t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1672;
                                                                  {
                                                                    t2f923f73303f235bd6ab3a4150418dd9 drec_247 { id_1671 };
                                                                    t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1673;
                                                                    {
                                                                      auto drec_fst_248 { std::get<0>(drec_247) };
                                                                      auto drec_snd_249 { std::get<1>(drec_247) };
                                                                      uint32_t id_1674 { 0U };
                                                                      Vec<1, uint32_t> id_1675 {  id_1674  };
                                                                      t405eb186408556fed8f2c41523c07d13 let_res_1676;
                                                                      {
                                                                        Vec<1, uint32_t> leb_ref_250 { id_1675 };
                                                                        uint8_t id_1677 { 0 };
                                                                        Vec<1, uint8_t> id_1678 {  id_1677  };
                                                                        t405eb186408556fed8f2c41523c07d13 let_res_1679;
                                                                        {
                                                                          Vec<1, uint8_t> shft_ref_251 { id_1678 };
                                                                          Vec<1, Pointer> id_1680 {  drec_snd_249  };
                                                                          t405eb186408556fed8f2c41523c07d13 let_res_1681;
                                                                          {
                                                                            Vec<1, Pointer> p_ref_252 { id_1680 };
                                                                            bool while_flag_1682 { true };
                                                                            do {
                                                                              uint8_t id_1683 { 0 };
                                                                              Pointer id_1684 { p_ref_252[id_1683] };
                                                                              tb3f98ea670610d40658a618de3ec7b90 id_1685 { id_1684.readU8() };
                                                                              bool let_res_1686;
                                                                              {
                                                                                tb3f98ea670610d40658a618de3ec7b90 leb128_253 { id_1685 };
                                                                                bool letpair_res_1687;
                                                                                {
                                                                                  auto leb128_fst_254 { std::get<0>(leb128_253) };
                                                                                  auto leb128_snd_255 { std::get<1>(leb128_253) };
                                                                                  uint8_t id_1688 { 0 };
                                                                                  Void id_1689 { ((void)(p_ref_252[id_1688] = leb128_snd_255), VOID) };
                                                                                  (void)id_1689;
                                                                                  uint8_t id_1690 { 0 };
                                                                                  uint8_t id_1691 { 127 };
                                                                                  uint8_t id_1692 { uint8_t(leb128_fst_254 & id_1691) };
                                                                                  uint32_t id_1693 { uint32_t(id_1692) };
                                                                                  uint8_t id_1694 { 0 };
                                                                                  uint8_t id_1695 { shft_ref_251[id_1694] };
                                                                                  uint32_t id_1696 { uint32_t(id_1693 << id_1695) };
                                                                                  uint8_t id_1697 { 0 };
                                                                                  uint32_t id_1698 { leb_ref_250[id_1697] };
                                                                                  uint32_t id_1699 { uint32_t(id_1696 | id_1698) };
                                                                                  Void id_1700 { ((void)(leb_ref_250[id_1690] = id_1699), VOID) };
                                                                                  (void)id_1700;
                                                                                  uint8_t id_1701 { 0 };
                                                                                  uint8_t id_1702 { 0 };
                                                                                  uint8_t id_1703 { shft_ref_251[id_1702] };
                                                                                  uint8_t id_1704 { 7 };
                                                                                  uint8_t id_1705 { uint8_t(id_1703 + id_1704) };
                                                                                  Void id_1706 { ((void)(shft_ref_251[id_1701] = id_1705), VOID) };
                                                                                  (void)id_1706;
                                                                                  uint8_t id_1707 { 128 };
                                                                                  bool id_1708 { bool(leb128_fst_254 >= id_1707) };
                                                                                  letpair_res_1687 = id_1708;
                                                                                }
                                                                                let_res_1686 = letpair_res_1687;
                                                                              }
                                                                              while_flag_1682 = let_res_1686;
                                                                              if (while_flag_1682) {
                                                                                (void)VOID;
                                                                              }
                                                                            } while (while_flag_1682);
                                                                            (void)VOID;
                                                                            uint8_t id_1709 { 0 };
                                                                            uint32_t id_1710 { leb_ref_250[id_1709] };
                                                                            uint8_t id_1711 { 0 };
                                                                            Pointer id_1712 { p_ref_252[id_1711] };
                                                                            t405eb186408556fed8f2c41523c07d13 id_1713 { id_1710, id_1712 };
                                                                            let_res_1681 = id_1713;
                                                                          }
                                                                          let_res_1679 = let_res_1681;
                                                                        }
                                                                        let_res_1676 = let_res_1679;
                                                                      }
                                                                      t0dfa866705b76efff53e4aa97228a967 let_res_1714;
                                                                      {
                                                                        t405eb186408556fed8f2c41523c07d13 dlist1_259 { let_res_1676 };
                                                                        t0dfa866705b76efff53e4aa97228a967 letpair_res_1715;
                                                                        {
                                                                          auto dlist1_fst_260 { std::get<0>(dlist1_259) };
                                                                          auto dlist1_snd_261 { std::get<1>(dlist1_259) };
                                                                          Lst<dessser::gen::field_name::t_ext> endoflist_1716;
                                                                          t0dfa866705b76efff53e4aa97228a967 id_1717 { endoflist_1716, dlist1_snd_261 };
                                                                          Vec<1, t0dfa866705b76efff53e4aa97228a967> id_1718 {  id_1717  };
                                                                          t0dfa866705b76efff53e4aa97228a967 let_res_1719;
                                                                          {
                                                                            Vec<1, t0dfa866705b76efff53e4aa97228a967> inits_src_ref_262 { id_1718 };
                                                                            int32_t id_1720 { 0L };
                                                                            Vec<1, int32_t> id_1721 {  id_1720  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_263 { id_1721 };
                                                                              bool while_flag_1722 { true };
                                                                              do {
                                                                                int32_t id_1723 { int32_t(dlist1_fst_260) };
                                                                                uint8_t id_1724 { 0 };
                                                                                int32_t id_1725 { repeat_n_263[id_1724] };
                                                                                bool id_1726 { bool(id_1723 > id_1725) };
                                                                                while_flag_1722 = id_1726;
                                                                                if (while_flag_1722) {
                                                                                  uint8_t id_1727 { 0 };
                                                                                  t0dfa866705b76efff53e4aa97228a967 id_1728 { inits_src_ref_262[id_1727] };
                                                                                  {
                                                                                    t0dfa866705b76efff53e4aa97228a967 dlist2_264 { id_1728 };
                                                                                    {
                                                                                      auto dlist2_fst_265 { std::get<0>(dlist2_264) };
                                                                                      auto dlist2_snd_266 { std::get<1>(dlist2_264) };
                                                                                      uint8_t id_1729 { 0 };
                                                                                      auto fun1730 { dessser::gen::field_name::of_row_binary };
                                                                                      t273a2b7978f5b466a128a51c1cc4a27b id_1731 { fun1730(dlist2_snd_266) };
                                                                                      t0dfa866705b76efff53e4aa97228a967 letpair_res_1732;
                                                                                      {
                                                                                        auto dlist3_fst_268 { std::get<0>(id_1731) };
                                                                                        auto dlist3_snd_269 { std::get<1>(id_1731) };
                                                                                        Lst<dessser::gen::field_name::t_ext> id_1733 { dlist3_fst_268, dlist2_fst_265 };
                                                                                        t0dfa866705b76efff53e4aa97228a967 id_1734 { id_1733, dlist3_snd_269 };
                                                                                        letpair_res_1732 = id_1734;
                                                                                      }
                                                                                      Void id_1735 { ((void)(inits_src_ref_262[id_1729] = letpair_res_1732), VOID) };
                                                                                      (void)id_1735;
                                                                                    }
                                                                                    (void)VOID;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_1736 { 0 };
                                                                                  uint8_t id_1737 { 0 };
                                                                                  int32_t id_1738 { repeat_n_263[id_1737] };
                                                                                  int32_t id_1739 { 1L };
                                                                                  int32_t id_1740 { int32_t(id_1738 + id_1739) };
                                                                                  Void id_1741 { ((void)(repeat_n_263[id_1736] = id_1740), VOID) };
                                                                                  (void)id_1741;
                                                                                  (void)id_1741;
                                                                                }
                                                                              } while (while_flag_1722);
                                                                              (void)VOID;
                                                                            }
                                                                            (void)VOID;
                                                                            uint8_t id_1742 { 0 };
                                                                            t0dfa866705b76efff53e4aa97228a967 id_1743 { inits_src_ref_262[id_1742] };
                                                                            let_res_1719 = id_1743;
                                                                          }
                                                                          letpair_res_1715 = let_res_1719;
                                                                        }
                                                                        let_res_1714 = letpair_res_1715;
                                                                      }
                                                                      t0dfa866705b76efff53e4aa97228a967 letpair_res_1744;
                                                                      {
                                                                        auto dlist4_fst_271 { std::get<0>(let_res_1714) };
                                                                        auto dlist4_snd_272 { std::get<1>(let_res_1714) };
                                                                        t0dfa866705b76efff53e4aa97228a967 id_1745 { dlist4_fst_271, dlist4_snd_272 };
                                                                        letpair_res_1744 = id_1745;
                                                                      }
                                                                      t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1746;
                                                                      {
                                                                        t0dfa866705b76efff53e4aa97228a967 drec_273 { letpair_res_1744 };
                                                                        t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1747;
                                                                        {
                                                                          auto drec_fst_274 { std::get<0>(drec_273) };
                                                                          auto drec_snd_275 { std::get<1>(drec_273) };
                                                                          uint32_t id_1748 { 0U };
                                                                          Vec<1, uint32_t> id_1749 {  id_1748  };
                                                                          t8beb80162423aee37bd383e9b6834c9c let_res_1750;
                                                                          {
                                                                            Vec<1, uint32_t> leb_ref_276 { id_1749 };
                                                                            uint8_t id_1751 { 0 };
                                                                            Vec<1, uint8_t> id_1752 {  id_1751  };
                                                                            t8beb80162423aee37bd383e9b6834c9c let_res_1753;
                                                                            {
                                                                              Vec<1, uint8_t> shft_ref_277 { id_1752 };
                                                                              Vec<1, Pointer> id_1754 {  drec_snd_275  };
                                                                              t8beb80162423aee37bd383e9b6834c9c let_res_1755;
                                                                              {
                                                                                Vec<1, Pointer> p_ref_278 { id_1754 };
                                                                                bool while_flag_1756 { true };
                                                                                do {
                                                                                  uint8_t id_1757 { 0 };
                                                                                  Pointer id_1758 { p_ref_278[id_1757] };
                                                                                  tb3f98ea670610d40658a618de3ec7b90 id_1759 { id_1758.readU8() };
                                                                                  bool let_res_1760;
                                                                                  {
                                                                                    tb3f98ea670610d40658a618de3ec7b90 leb128_279 { id_1759 };
                                                                                    bool letpair_res_1761;
                                                                                    {
                                                                                      auto leb128_fst_280 { std::get<0>(leb128_279) };
                                                                                      auto leb128_snd_281 { std::get<1>(leb128_279) };
                                                                                      uint8_t id_1762 { 0 };
                                                                                      Void id_1763 { ((void)(p_ref_278[id_1762] = leb128_snd_281), VOID) };
                                                                                      (void)id_1763;
                                                                                      uint8_t id_1764 { 0 };
                                                                                      uint8_t id_1765 { 127 };
                                                                                      uint8_t id_1766 { uint8_t(leb128_fst_280 & id_1765) };
                                                                                      uint32_t id_1767 { uint32_t(id_1766) };
                                                                                      uint8_t id_1768 { 0 };
                                                                                      uint8_t id_1769 { shft_ref_277[id_1768] };
                                                                                      uint32_t id_1770 { uint32_t(id_1767 << id_1769) };
                                                                                      uint8_t id_1771 { 0 };
                                                                                      uint32_t id_1772 { leb_ref_276[id_1771] };
                                                                                      uint32_t id_1773 { uint32_t(id_1770 | id_1772) };
                                                                                      Void id_1774 { ((void)(leb_ref_276[id_1764] = id_1773), VOID) };
                                                                                      (void)id_1774;
                                                                                      uint8_t id_1775 { 0 };
                                                                                      uint8_t id_1776 { 0 };
                                                                                      uint8_t id_1777 { shft_ref_277[id_1776] };
                                                                                      uint8_t id_1778 { 7 };
                                                                                      uint8_t id_1779 { uint8_t(id_1777 + id_1778) };
                                                                                      Void id_1780 { ((void)(shft_ref_277[id_1775] = id_1779), VOID) };
                                                                                      (void)id_1780;
                                                                                      uint8_t id_1781 { 128 };
                                                                                      bool id_1782 { bool(leb128_fst_280 >= id_1781) };
                                                                                      letpair_res_1761 = id_1782;
                                                                                    }
                                                                                    let_res_1760 = letpair_res_1761;
                                                                                  }
                                                                                  while_flag_1756 = let_res_1760;
                                                                                  if (while_flag_1756) {
                                                                                    (void)VOID;
                                                                                  }
                                                                                } while (while_flag_1756);
                                                                                (void)VOID;
                                                                                uint8_t id_1783 { 0 };
                                                                                uint32_t id_1784 { leb_ref_276[id_1783] };
                                                                                Size id_1785 { Size(id_1784) };
                                                                                uint8_t id_1786 { 0 };
                                                                                Pointer id_1787 { p_ref_278[id_1786] };
                                                                                t8beb80162423aee37bd383e9b6834c9c id_1788 { id_1785, id_1787 };
                                                                                let_res_1755 = id_1788;
                                                                              }
                                                                              let_res_1753 = let_res_1755;
                                                                            }
                                                                            let_res_1750 = let_res_1753;
                                                                          }
                                                                          tef94b55d8809251f13165d9a05bd9d0e let_res_1789;
                                                                          {
                                                                            t8beb80162423aee37bd383e9b6834c9c dstring1_282 { let_res_1750 };
                                                                            tef94b55d8809251f13165d9a05bd9d0e letpair_res_1790;
                                                                            {
                                                                              auto dstring1_fst_283 { std::get<0>(dstring1_282) };
                                                                              auto dstring1_snd_284 { std::get<1>(dstring1_282) };
                                                                              t188345aa49abd0cb47ff73fedc219f08 id_1791 { dstring1_snd_284.readBytes(dstring1_fst_283) };
                                                                              tef94b55d8809251f13165d9a05bd9d0e letpair_res_1792;
                                                                              {
                                                                                auto dstring2_fst_286 { std::get<0>(id_1791) };
                                                                                auto dstring2_snd_287 { std::get<1>(id_1791) };
                                                                                std::string id_1793 { dstring2_fst_286.toString() };
                                                                                tef94b55d8809251f13165d9a05bd9d0e id_1794 { id_1793, dstring2_snd_287 };
                                                                                letpair_res_1792 = id_1794;
                                                                              }
                                                                              letpair_res_1790 = letpair_res_1792;
                                                                            }
                                                                            let_res_1789 = letpair_res_1790;
                                                                          }
                                                                          t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1795;
                                                                          {
                                                                            tef94b55d8809251f13165d9a05bd9d0e drec_288 { let_res_1789 };
                                                                            t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1796;
                                                                            {
                                                                              auto drec_fst_289 { std::get<0>(drec_288) };
                                                                              auto drec_snd_290 { std::get<1>(drec_288) };
                                                                              uint32_t id_1797 { 0U };
                                                                              Vec<1, uint32_t> id_1798 {  id_1797  };
                                                                              t8beb80162423aee37bd383e9b6834c9c let_res_1799;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_291 { id_1798 };
                                                                                uint8_t id_1800 { 0 };
                                                                                Vec<1, uint8_t> id_1801 {  id_1800  };
                                                                                t8beb80162423aee37bd383e9b6834c9c let_res_1802;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_292 { id_1801 };
                                                                                  Vec<1, Pointer> id_1803 {  drec_snd_290  };
                                                                                  t8beb80162423aee37bd383e9b6834c9c let_res_1804;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_293 { id_1803 };
                                                                                    bool while_flag_1805 { true };
                                                                                    do {
                                                                                      uint8_t id_1806 { 0 };
                                                                                      Pointer id_1807 { p_ref_293[id_1806] };
                                                                                      tb3f98ea670610d40658a618de3ec7b90 id_1808 { id_1807.readU8() };
                                                                                      bool let_res_1809;
                                                                                      {
                                                                                        tb3f98ea670610d40658a618de3ec7b90 leb128_294 { id_1808 };
                                                                                        bool letpair_res_1810;
                                                                                        {
                                                                                          auto leb128_fst_295 { std::get<0>(leb128_294) };
                                                                                          auto leb128_snd_296 { std::get<1>(leb128_294) };
                                                                                          uint8_t id_1811 { 0 };
                                                                                          Void id_1812 { ((void)(p_ref_293[id_1811] = leb128_snd_296), VOID) };
                                                                                          (void)id_1812;
                                                                                          uint8_t id_1813 { 0 };
                                                                                          uint8_t id_1814 { 127 };
                                                                                          uint8_t id_1815 { uint8_t(leb128_fst_295 & id_1814) };
                                                                                          uint32_t id_1816 { uint32_t(id_1815) };
                                                                                          uint8_t id_1817 { 0 };
                                                                                          uint8_t id_1818 { shft_ref_292[id_1817] };
                                                                                          uint32_t id_1819 { uint32_t(id_1816 << id_1818) };
                                                                                          uint8_t id_1820 { 0 };
                                                                                          uint32_t id_1821 { leb_ref_291[id_1820] };
                                                                                          uint32_t id_1822 { uint32_t(id_1819 | id_1821) };
                                                                                          Void id_1823 { ((void)(leb_ref_291[id_1813] = id_1822), VOID) };
                                                                                          (void)id_1823;
                                                                                          uint8_t id_1824 { 0 };
                                                                                          uint8_t id_1825 { 0 };
                                                                                          uint8_t id_1826 { shft_ref_292[id_1825] };
                                                                                          uint8_t id_1827 { 7 };
                                                                                          uint8_t id_1828 { uint8_t(id_1826 + id_1827) };
                                                                                          Void id_1829 { ((void)(shft_ref_292[id_1824] = id_1828), VOID) };
                                                                                          (void)id_1829;
                                                                                          uint8_t id_1830 { 128 };
                                                                                          bool id_1831 { bool(leb128_fst_295 >= id_1830) };
                                                                                          letpair_res_1810 = id_1831;
                                                                                        }
                                                                                        let_res_1809 = letpair_res_1810;
                                                                                      }
                                                                                      while_flag_1805 = let_res_1809;
                                                                                      if (while_flag_1805) {
                                                                                        (void)VOID;
                                                                                      }
                                                                                    } while (while_flag_1805);
                                                                                    (void)VOID;
                                                                                    uint8_t id_1832 { 0 };
                                                                                    uint32_t id_1833 { leb_ref_291[id_1832] };
                                                                                    Size id_1834 { Size(id_1833) };
                                                                                    uint8_t id_1835 { 0 };
                                                                                    Pointer id_1836 { p_ref_293[id_1835] };
                                                                                    t8beb80162423aee37bd383e9b6834c9c id_1837 { id_1834, id_1836 };
                                                                                    let_res_1804 = id_1837;
                                                                                  }
                                                                                  let_res_1802 = let_res_1804;
                                                                                }
                                                                                let_res_1799 = let_res_1802;
                                                                              }
                                                                              t99bf25e2852182fc53ed35e1ddb06ab9 let_res_1838;
                                                                              {
                                                                                t8beb80162423aee37bd383e9b6834c9c dstring1_297 { let_res_1799 };
                                                                                t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1839;
                                                                                {
                                                                                  auto dstring1_fst_298 { std::get<0>(dstring1_297) };
                                                                                  auto dstring1_snd_299 { std::get<1>(dstring1_297) };
                                                                                  t188345aa49abd0cb47ff73fedc219f08 id_1840 { dstring1_snd_299.readBytes(dstring1_fst_298) };
                                                                                  t99bf25e2852182fc53ed35e1ddb06ab9 letpair_res_1841;
                                                                                  {
                                                                                    auto dstring2_fst_301 { std::get<0>(id_1840) };
                                                                                    auto dstring2_snd_302 { std::get<1>(id_1840) };
                                                                                    std::string id_1842 { dstring2_fst_301.toString() };
                                                                                    tb0a5947d2e730ef2c38de99be0c65701 id_1843 { .name = drec_fst_215, .retention = drec_fst_221, .is_lazy = drec_fst_227, .doc = drec_fst_242, .operation = drec_fst_245, .out_record = drec_fst_248, .factors = drec_fst_274, .signature = drec_fst_289, .in_signature = id_1842 };
                                                                                    Lst<tb0a5947d2e730ef2c38de99be0c65701> id_1844 { id_1843, dlist2_fst_212 };
                                                                                    t99bf25e2852182fc53ed35e1ddb06ab9 id_1845 { id_1844, dstring2_snd_302 };
                                                                                    letpair_res_1841 = id_1845;
                                                                                  }
                                                                                  letpair_res_1839 = letpair_res_1841;
                                                                                }
                                                                                let_res_1838 = letpair_res_1839;
                                                                              }
                                                                              letpair_res_1796 = let_res_1838;
                                                                            }
                                                                            let_res_1795 = letpair_res_1796;
                                                                          }
                                                                          letpair_res_1747 = let_res_1795;
                                                                        }
                                                                        let_res_1746 = letpair_res_1747;
                                                                      }
                                                                      letpair_res_1673 = let_res_1746;
                                                                    }
                                                                    let_res_1672 = letpair_res_1673;
                                                                  }
                                                                  letpair_res_1669 = let_res_1672;
                                                                }
                                                                let_res_1668 = letpair_res_1669;
                                                              }
                                                              letpair_res_1665 = let_res_1668;
                                                            }
                                                            let_res_1664 = letpair_res_1665;
                                                          }
                                                          letpair_res_1616 = let_res_1664;
                                                        }
                                                        let_res_1615 = letpair_res_1616;
                                                      }
                                                      letpair_res_1608 = let_res_1615;
                                                    }
                                                    let_res_1607 = letpair_res_1608;
                                                  }
                                                  letpair_res_1590 = let_res_1607;
                                                }
                                                let_res_1589 = letpair_res_1590;
                                              }
                                              Void id_1846 { ((void)(inits_src_ref_209[id_1586] = let_res_1589), VOID) };
                                              (void)id_1846;
                                            }
                                            (void)VOID;
                                          }
                                          (void)VOID;
                                          uint8_t id_1847 { 0 };
                                          uint8_t id_1848 { 0 };
                                          int32_t id_1849 { repeat_n_210[id_1848] };
                                          int32_t id_1850 { 1L };
                                          int32_t id_1851 { int32_t(id_1849 + id_1850) };
                                          Void id_1852 { ((void)(repeat_n_210[id_1847] = id_1851), VOID) };
                                          (void)id_1852;
                                          (void)id_1852;
                                        }
                                      } while (while_flag_1579);
                                      (void)VOID;
                                    }
                                    (void)VOID;
                                    uint8_t id_1853 { 0 };
                                    t99bf25e2852182fc53ed35e1ddb06ab9 id_1854 { inits_src_ref_209[id_1853] };
                                    let_res_1576 = id_1854;
                                  }
                                  letpair_res_1572 = let_res_1576;
                                }
                                let_res_1571 = letpair_res_1572;
                              }
                              tb0e3f2c9b734bb327b41592ba7807707 letpair_res_1855;
                              {
                                auto dlist4_fst_310 { std::get<0>(let_res_1571) };
                                auto dlist4_snd_311 { std::get<1>(let_res_1571) };
                                t67d467e776d7a3f3e54efabfd5f911ed id_1856 { .default_params = drec_fst_166, .condition = drec_fst_169, .globals = drec_fst_195, .funcs = dlist4_fst_310 };
                                t1f2a02f42faa570bd799752d94503c06 id_1857 { std::in_place_index<0>, id_1856 };
                                tb0e3f2c9b734bb327b41592ba7807707 id_1858 { id_1857, dlist4_snd_311 };
                                letpair_res_1855 = id_1858;
                              }
                              letpair_res_1530 = letpair_res_1855;
                            }
                            let_res_1529 = letpair_res_1530;
                          }
                          letpair_res_1456 = let_res_1529;
                        }
                        let_res_1455 = letpair_res_1456;
                      }
                      letpair_res_1452 = let_res_1455;
                    }
                    let_res_1451 = letpair_res_1452;
                  }
                  choose_res_1378 = let_res_1451;
                } else {
                  uint16_t id_1859 { 1 };
                  bool id_1860 { bool(dsum1_fst_116 == id_1859) };
                  Void id_1861 { ((void)(assert(id_1860)), VOID) };
                  (void)id_1861;
                  uint32_t id_1862 { 0U };
                  Vec<1, uint32_t> id_1863 {  id_1862  };
                  t8beb80162423aee37bd383e9b6834c9c let_res_1864;
                  {
                    Vec<1, uint32_t> leb_ref_118 { id_1863 };
                    uint8_t id_1865 { 0 };
                    Vec<1, uint8_t> id_1866 {  id_1865  };
                    t8beb80162423aee37bd383e9b6834c9c let_res_1867;
                    {
                      Vec<1, uint8_t> shft_ref_119 { id_1866 };
                      Vec<1, Pointer> id_1868 {  dsum1_snd_117  };
                      t8beb80162423aee37bd383e9b6834c9c let_res_1869;
                      {
                        Vec<1, Pointer> p_ref_120 { id_1868 };
                        bool while_flag_1870 { true };
                        do {
                          uint8_t id_1871 { 0 };
                          Pointer id_1872 { p_ref_120[id_1871] };
                          tb3f98ea670610d40658a618de3ec7b90 id_1873 { id_1872.readU8() };
                          bool let_res_1874;
                          {
                            tb3f98ea670610d40658a618de3ec7b90 leb128_121 { id_1873 };
                            bool letpair_res_1875;
                            {
                              auto leb128_fst_122 { std::get<0>(leb128_121) };
                              auto leb128_snd_123 { std::get<1>(leb128_121) };
                              uint8_t id_1876 { 0 };
                              Void id_1877 { ((void)(p_ref_120[id_1876] = leb128_snd_123), VOID) };
                              (void)id_1877;
                              uint8_t id_1878 { 0 };
                              uint8_t id_1879 { 127 };
                              uint8_t id_1880 { uint8_t(leb128_fst_122 & id_1879) };
                              uint32_t id_1881 { uint32_t(id_1880) };
                              uint8_t id_1882 { 0 };
                              uint8_t id_1883 { shft_ref_119[id_1882] };
                              uint32_t id_1884 { uint32_t(id_1881 << id_1883) };
                              uint8_t id_1885 { 0 };
                              uint32_t id_1886 { leb_ref_118[id_1885] };
                              uint32_t id_1887 { uint32_t(id_1884 | id_1886) };
                              Void id_1888 { ((void)(leb_ref_118[id_1878] = id_1887), VOID) };
                              (void)id_1888;
                              uint8_t id_1889 { 0 };
                              uint8_t id_1890 { 0 };
                              uint8_t id_1891 { shft_ref_119[id_1890] };
                              uint8_t id_1892 { 7 };
                              uint8_t id_1893 { uint8_t(id_1891 + id_1892) };
                              Void id_1894 { ((void)(shft_ref_119[id_1889] = id_1893), VOID) };
                              (void)id_1894;
                              uint8_t id_1895 { 128 };
                              bool id_1896 { bool(leb128_fst_122 >= id_1895) };
                              letpair_res_1875 = id_1896;
                            }
                            let_res_1874 = letpair_res_1875;
                          }
                          while_flag_1870 = let_res_1874;
                          if (while_flag_1870) {
                            (void)VOID;
                          }
                        } while (while_flag_1870);
                        (void)VOID;
                        uint8_t id_1897 { 0 };
                        uint32_t id_1898 { leb_ref_118[id_1897] };
                        Size id_1899 { Size(id_1898) };
                        uint8_t id_1900 { 0 };
                        Pointer id_1901 { p_ref_120[id_1900] };
                        t8beb80162423aee37bd383e9b6834c9c id_1902 { id_1899, id_1901 };
                        let_res_1869 = id_1902;
                      }
                      let_res_1867 = let_res_1869;
                    }
                    let_res_1864 = let_res_1867;
                  }
                  tef94b55d8809251f13165d9a05bd9d0e let_res_1903;
                  {
                    t8beb80162423aee37bd383e9b6834c9c dstring1_124 { let_res_1864 };
                    tef94b55d8809251f13165d9a05bd9d0e letpair_res_1904;
                    {
                      auto dstring1_fst_125 { std::get<0>(dstring1_124) };
                      auto dstring1_snd_126 { std::get<1>(dstring1_124) };
                      t188345aa49abd0cb47ff73fedc219f08 id_1905 { dstring1_snd_126.readBytes(dstring1_fst_125) };
                      tef94b55d8809251f13165d9a05bd9d0e letpair_res_1906;
                      {
                        auto dstring2_fst_128 { std::get<0>(id_1905) };
                        auto dstring2_snd_129 { std::get<1>(id_1905) };
                        std::string id_1907 { dstring2_fst_128.toString() };
                        tef94b55d8809251f13165d9a05bd9d0e id_1908 { id_1907, dstring2_snd_129 };
                        letpair_res_1906 = id_1908;
                      }
                      letpair_res_1904 = letpair_res_1906;
                    }
                    let_res_1903 = letpair_res_1904;
                  }
                  tb0e3f2c9b734bb327b41592ba7807707 let_res_1909;
                  {
                    tef94b55d8809251f13165d9a05bd9d0e drec_130 { let_res_1903 };
                    tb0e3f2c9b734bb327b41592ba7807707 letpair_res_1910;
                    {
                      auto drec_fst_131 { std::get<0>(drec_130) };
                      auto drec_snd_132 { std::get<1>(drec_130) };
                      Size id_1911 { 0UL };
                      uint8_t id_1912 { drec_snd_132.peekU8(id_1911) };
                      uint8_t id_1913 { 1 };
                      bool id_1914 { bool(id_1912 == id_1913) };
                      t704dc7dfdc8ab68dc50aa22f37a6ee27 choose_res_1915;
                      if (id_1914) {
                        std::optional<dessser::gen::src_path::t_ext> id_1916 { std::nullopt };
                        Size id_1917 { 1UL };
                        Pointer id_1918 { drec_snd_132.skip(id_1917) };
                        t704dc7dfdc8ab68dc50aa22f37a6ee27 id_1919 { id_1916, id_1918 };
                        choose_res_1915 = id_1919;
                      } else {
                        auto fun1920 { dessser::gen::src_path::of_row_binary };
                        Size id_1921 { 1UL };
                        Pointer id_1922 { drec_snd_132.skip(id_1921) };
                        t3aef8ea133ee816827fd8db245b58487 id_1923 { fun1920(id_1922) };
                        t704dc7dfdc8ab68dc50aa22f37a6ee27 letpair_res_1924;
                        {
                          auto make1_1_fst_134 { std::get<0>(id_1923) };
                          auto make1_1_snd_135 { std::get<1>(id_1923) };
                          std::optional<dessser::gen::src_path::t_ext> id_1925 { make1_1_fst_134 };
                          t704dc7dfdc8ab68dc50aa22f37a6ee27 id_1926 { id_1925, make1_1_snd_135 };
                          letpair_res_1924 = id_1926;
                        }
                        choose_res_1915 = letpair_res_1924;
                      }
                      tb0e3f2c9b734bb327b41592ba7807707 letpair_res_1927;
                      {
                        auto drec_fst_137 { std::get<0>(choose_res_1915) };
                        auto drec_snd_138 { std::get<1>(choose_res_1915) };
                        t0fbe0ba3da9da3292ae419be74c6cc6e id_1928 { .err_msg = drec_fst_131, .depends_on = drec_fst_137 };
                        t1f2a02f42faa570bd799752d94503c06 id_1929 { std::in_place_index<1>, id_1928 };
                        tb0e3f2c9b734bb327b41592ba7807707 id_1930 { id_1929, drec_snd_138 };
                        letpair_res_1927 = id_1930;
                      }
                      letpair_res_1910 = letpair_res_1927;
                    }
                    let_res_1909 = letpair_res_1910;
                  }
                  choose_res_1378 = let_res_1909;
                }
                letpair_res_1375 = choose_res_1378;
              }
              let_res_1374 = letpair_res_1375;
            }
            t45217dce3db5a9a49037839afd0048e8 letpair_res_1931;
            {
              auto drec_fst_319 { std::get<0>(let_res_1374) };
              auto drec_snd_320 { std::get<1>(let_res_1374) };
              t* id_1932 { new t({ .src_ext = drec_fst_69, .md5s = drec_fst_107, .detail = drec_fst_319 }) };
              t45217dce3db5a9a49037839afd0048e8 id_1933 { id_1932, drec_snd_320 };
              letpair_res_1931 = id_1933;
            }
            letpair_res_1370 = letpair_res_1931;
          }
          let_res_1369 = letpair_res_1370;
        }
        letpair_res_1253 = let_res_1369;
      }
      let_res_1252 = letpair_res_1253;
    }
    return let_res_1252;
  }
   };
  return fun1204;
}
std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
