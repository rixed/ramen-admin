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
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/field_name.h"
#include "desssergen/fq_name.h"


namespace dessser::gen::alert {
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
  std::string
> t7d737a471b58c17b56f5c31f8c6e717d;

struct t131662737cd7ca0ff4503bc447b90c1f : public std::variant<
  double, // Absolute
  double // Relative
> { using variant::variant; };

struct tbea317b67d84f7d9cf6a71dc11d82f92 {
  double avg_window;
  ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f max_distance;
  double percentile;
  uint32_t sample_size;
  uint32_t seasonality;
  double smooth_factor;
  tbea317b67d84f7d9cf6a71dc11d82f92(double avg_window_, ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f max_distance_, double percentile_, uint32_t sample_size_, uint32_t seasonality_, double smooth_factor_) : avg_window(avg_window_), max_distance(max_distance_), percentile(percentile_), sample_size(sample_size_), seasonality(seasonality_), smooth_factor(smooth_factor_) {}
  tbea317b67d84f7d9cf6a71dc11d82f92() = default;
};
struct t7a02edca1273055c3c437ebec83c4409 : public std::variant<
  double, // Constant
  ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 // Baseline
> { using variant::variant; };

struct t {
  Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> carry_csts;
  Lst<dessser::gen::field_name::t_ext> carry_fields;
  dessser::gen::field_name::t_ext column;
  std::string desc_firing;
  std::string desc_recovery;
  std::string desc_title;
  double duration;
  bool enabled;
  std::optional<Lst<dessser::gen::field_name::t_ext>> group_by;
  Lst<dessser::gen::simple_filter::t_ext> having;
  double hysteresis;
  std::string id;
  double ratio;
  dessser::gen::fq_name::t_ext table;
  ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 threshold;
  double time_step;
  Lst<dessser::gen::field_name::t_ext> tops;
  Lst<dessser::gen::simple_filter::t_ext> where;
  t(Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> carry_csts_, Lst<dessser::gen::field_name::t_ext> carry_fields_, dessser::gen::field_name::t_ext column_, std::string desc_firing_, std::string desc_recovery_, std::string desc_title_, double duration_, bool enabled_, std::optional<Lst<dessser::gen::field_name::t_ext>> group_by_, Lst<dessser::gen::simple_filter::t_ext> having_, double hysteresis_, std::string id_, double ratio_, dessser::gen::fq_name::t_ext table_, ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 threshold_, double time_step_, Lst<dessser::gen::field_name::t_ext> tops_, Lst<dessser::gen::simple_filter::t_ext> where_) : carry_csts(carry_csts_), carry_fields(carry_fields_), column(column_), desc_firing(desc_firing_), desc_recovery(desc_recovery_), desc_title(desc_title_), duration(duration_), enabled(enabled_), group_by(group_by_), having(having_), hysteresis(hysteresis_), id(id_), ratio(ratio_), table(table_), threshold(threshold_), time_step(time_step_), tops(tops_), where(where_) {}
  t() = default;
};
typedef std::tuple<
  ::dessser::gen::alert::t*,
  Pointer
> t9dbb79f443cdcf3340bfdfbf1b06c337;

typedef std::tuple<
  dessser::gen::fq_name::t_ext,
  Pointer
> td8eaddfacf232bd15ab91a5778e12a3b;

typedef std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> t273a2b7978f5b466a128a51c1cc4a27b;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  bool,
  Pointer
> t4138de986e20d18b01e4c493dc9d5451;

typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  Lst<dessser::gen::simple_filter::t_ext>,
  Pointer
> td8c70b15de14ddb4da7c6051edb88690;

typedef std::tuple<
  dessser::gen::simple_filter::t_ext,
  Pointer
> t90fff9b602787b5715d84f577a3751a3;

typedef std::tuple<
  std::optional<Lst<dessser::gen::field_name::t_ext>>,
  Pointer
> t885b8962b524dff3368f7a529f1d466b;

typedef std::tuple<
  Lst<dessser::gen::field_name::t_ext>,
  Pointer
> t0dfa866705b76efff53e4aa97228a967;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409,
  Pointer
> tac0e3b6e05c5dec5181c5fba06bd8924;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

typedef std::tuple<
  double,
  Pointer
> taebed00ad7fdb3f7ced11d3cfd58aade;

typedef std::tuple<
  ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f,
  Pointer
> t9b54bb8575ac4acd59014f4a6b949d7a;

typedef std::tuple<
  Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d>,
  Pointer
> ta2d5056f568236dc53d3d169e5b0b0ee;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

typedef std::tuple<
  std::string,
  Pointer
> tef94b55d8809251f13165d9a05bd9d0e;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{table: $fq_name; column: $field_name; enabled: BOOL; where: $simple_filter[[]]; group-by: $field_name[[]]?; having: $simple_filter[[]]; threshold: [Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]; hysteresis: FLOAT; duration: FLOAT; ratio: FLOAT; time-step: FLOAT; tops: $field_name[[]]; carry-fields: $field_name[[]]; carry-csts: ($field_name; STRING)[[]]; id: STRING; desc-title: STRING; desc-firing: STRING; desc-recovery: STRING}" "Ptr")
      (let "srec_dst_539"
        (let "srec_dst_536"
          (let "srec_dst_533"
            (let "srec_dst_530"
              (let "srec_dst_520"
                (let "srec_dst_514"
                  (let "srec_dst_508"
                    (let "srec_dst_507"
                      (let "srec_dst_506"
                        (let "srec_dst_505"
                          (let "srec_dst_504"
                            (let "srec_dst_494"
                              (let "srec_dst_488"
                                (let "srec_dst_482"
                                  (let "srec_dst_476"
                                    (let "srec_dst_475"
                                      (let "srec_dst_474" (apply (ext-identifier fq_name to-row-binary) (get-field "table" (param 0)) (param 1))
                                        (apply (ext-identifier field_name to-row-binary) (get-field "column" (param 0)) (identifier "srec_dst_474")))
                                      (write-u8 (identifier "srec_dst_475") (u8-of-bool (get-field "enabled" (param 0)))))
                                    (let "dst_ref_479"
                                      (make-vec
                                        (let "leb128_sz_477" (make-vec (cardinality (get-field "where" (param 0))))
                                          (let "leb128_ptr_478" (make-vec (identifier "srec_dst_476"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_478")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_478"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_477"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_477"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_477"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_477") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_477")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_477")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_478"))))))
                                      (let "n_ref_480" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_481" (get-field "where" (param 0))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_479") (apply (ext-identifier simple_filter to-row-binary) (identifier "x_481") (unsafe-nth (u8 0) (identifier "dst_ref_479"))))
                                              (set-vec (u8 0) (identifier "n_ref_480") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_480")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_479"))))))
                                  (if (is-null (get-field "group-by" (param 0))) 
                                    (write-u8 (identifier "srec_dst_482") (u8 1))
                                    (let "dst_ref_485"
                                      (make-vec
                                        (let "leb128_sz_483" (make-vec (cardinality (force (get-field "group-by" (param 0)))))
                                          (let "leb128_ptr_484" (make-vec (write-u8 (identifier "srec_dst_482") (u8 0)))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_484")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_484"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_483"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_483"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_483"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_483") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_483")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_483")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_484"))))))
                                      (let "n_ref_486" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_487" (force (get-field "group-by" (param 0)))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_485") (apply (ext-identifier field_name to-row-binary) (identifier "x_487") (unsafe-nth (u8 0) (identifier "dst_ref_485"))))
                                              (set-vec (u8 0) (identifier "n_ref_486") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_486")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_485")))))))
                                (let "dst_ref_491"
                                  (make-vec
                                    (let "leb128_sz_489" (make-vec (cardinality (get-field "having" (param 0))))
                                      (let "leb128_ptr_490" (make-vec (identifier "srec_dst_488"))
                                        (seq
                                          (while
                                            (seq
                                              (set-vec (u8 0) (identifier "leb128_ptr_490")
                                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_490"))
                                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_489"))) 
                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_489"))) 
                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_489"))) (u8 128)))))
                                              (set-vec (u8 0) (identifier "leb128_sz_489") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_489")) (u8 7))) 
                                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_489")) (u32 0))) 
                                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_490"))))))
                                  (let "n_ref_492" (make-vec (i32 0))
                                    (seq
                                      (for-each "x_493" (get-field "having" (param 0))
                                        (seq (set-vec (u8 0) (identifier "dst_ref_491") (apply (ext-identifier simple_filter to-row-binary) (identifier "x_493") (unsafe-nth (u8 0) (identifier "dst_ref_491"))))
                                          (set-vec (u8 0) (identifier "n_ref_492") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_492")))))) 
                                      (unsafe-nth (u8 0) (identifier "dst_ref_491"))))))
                              (let "ssum_dst_496" (write-u16 little-endian (identifier "srec_dst_494") (label-of (get-field "threshold" (param 0))))
                                (if (eq (u16 0) (label-of (get-field "threshold" (param 0)))) 
                                  (write-u64 little-endian (identifier "ssum_dst_496") (u64-of-float (get-alt "Constant" (get-field "threshold" (param 0)))))
                                  (seq (assert (eq (label-of (get-field "threshold" (param 0))) (u16 1)))
                                    (let "srec_dst_501"
                                      (let "srec_dst_500"
                                        (let "srec_dst_499"
                                          (let "srec_dst_498"
                                            (let "srec_dst_497" (write-u64 little-endian (identifier "ssum_dst_496") (u64-of-float (get-field "avg_window" (get-alt "Baseline" (get-field "threshold" (param 0))))))
                                              (write-u32 little-endian (identifier "srec_dst_497") (get-field "sample_size" (get-alt "Baseline" (get-field "threshold" (param 0))))))
                                            (write-u64 little-endian (identifier "srec_dst_498") (u64-of-float (get-field "percentile" (get-alt "Baseline" (get-field "threshold" (param 0)))))))
                                          (write-u32 little-endian (identifier "srec_dst_499") (get-field "seasonality" (get-alt "Baseline" (get-field "threshold" (param 0))))))
                                        (write-u64 little-endian (identifier "srec_dst_500") (u64-of-float (get-field "smooth_factor" (get-alt "Baseline" (get-field "threshold" (param 0)))))))
                                      (let "ssum_dst_503" (write-u16 little-endian (identifier "srec_dst_501") (label-of (get-field "max_distance" (get-alt "Baseline" (get-field "threshold" (param 0))))))
                                        (if (eq (u16 0) (label-of (get-field "max_distance" (get-alt "Baseline" (get-field "threshold" (param 0))))))
                                          (write-u64 little-endian (identifier "ssum_dst_503") (u64-of-float (get-alt "Absolute" (get-field "max_distance" (get-alt "Baseline" (get-field "threshold" (param 0)))))))
                                          (seq (assert (eq (label-of (get-field "max_distance" (get-alt "Baseline" (get-field "threshold" (param 0))))) (u16 1)))
                                            (write-u64 little-endian (identifier "ssum_dst_503") (u64-of-float (get-alt "Relative" (get-field "max_distance" (get-alt "Baseline" (get-field "threshold" (param 0)))))))))))))))
                            (write-u64 little-endian (identifier "srec_dst_504") (u64-of-float (get-field "hysteresis" (param 0)))))
                          (write-u64 little-endian (identifier "srec_dst_505") (u64-of-float (get-field "duration" (param 0))))) 
                        (write-u64 little-endian (identifier "srec_dst_506") (u64-of-float (get-field "ratio" (param 0))))) 
                      (write-u64 little-endian (identifier "srec_dst_507") (u64-of-float (get-field "time-step" (param 0)))))
                    (let "dst_ref_511"
                      (make-vec
                        (let "leb128_sz_509" (make-vec (cardinality (get-field "tops" (param 0))))
                          (let "leb128_ptr_510" (make-vec (identifier "srec_dst_508"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_510")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_510"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_509"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_509"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_509"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_509") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_509")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_509")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_510"))))))
                      (let "n_ref_512" (make-vec (i32 0))
                        (seq
                          (for-each "x_513" (get-field "tops" (param 0))
                            (seq (set-vec (u8 0) (identifier "dst_ref_511") (apply (ext-identifier field_name to-row-binary) (identifier "x_513") (unsafe-nth (u8 0) (identifier "dst_ref_511"))))
                              (set-vec (u8 0) (identifier "n_ref_512") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_512")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_511"))))))
                  (let "dst_ref_517"
                    (make-vec
                      (let "leb128_sz_515" (make-vec (cardinality (get-field "carry-fields" (param 0))))
                        (let "leb128_ptr_516" (make-vec (identifier "srec_dst_514"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_516")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_516"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_515"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_515"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_515"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_515") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_515")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_515")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_516"))))))
                    (let "n_ref_518" (make-vec (i32 0))
                      (seq
                        (for-each "x_519" (get-field "carry-fields" (param 0))
                          (seq (set-vec (u8 0) (identifier "dst_ref_517") (apply (ext-identifier field_name to-row-binary) (identifier "x_519") (unsafe-nth (u8 0) (identifier "dst_ref_517"))))
                            (set-vec (u8 0) (identifier "n_ref_518") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_518")))))) 
                        (unsafe-nth (u8 0) (identifier "dst_ref_517"))))))
                (let "dst_ref_523"
                  (make-vec
                    (let "leb128_sz_521" (make-vec (cardinality (get-field "carry-csts" (param 0))))
                      (let "leb128_ptr_522" (make-vec (identifier "srec_dst_520"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_522")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_522"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_521"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_521"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_521"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_521") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_521")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_521")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_522"))))))
                  (let "n_ref_524" (make-vec (i32 0))
                    (seq
                      (for-each "x_525" (get-field "carry-csts" (param 0))
                        (seq
                          (set-vec (u8 0) (identifier "dst_ref_523")
                            (let "stup_dst_527" (let "stup_dst_526" (unsafe-nth (u8 0) (identifier "dst_ref_523")) (apply (ext-identifier field_name to-row-binary) (get-item 0 (identifier "x_525")) (identifier "stup_dst_526")))
                              (write-bytes
                                (let "leb128_sz_528" (make-vec (string-length (get-item 1 (identifier "x_525"))))
                                  (let "leb128_ptr_529" (make-vec (identifier "stup_dst_527"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_529")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_529"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_528"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_528"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_528"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_528") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_528")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_528")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_529"))))) 
                                (bytes-of-string (get-item 1 (identifier "x_525")))))) 
                          (set-vec (u8 0) (identifier "n_ref_524") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_524")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_523"))))))
              (write-bytes
                (let "leb128_sz_531" (make-vec (string-length (get-field "id" (param 0))))
                  (let "leb128_ptr_532" (make-vec (identifier "srec_dst_530"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_532")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_532"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_531"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_531"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_531"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_531") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_531")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_531")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_532"))))) 
                (bytes-of-string (get-field "id" (param 0)))))
            (write-bytes
              (let "leb128_sz_534" (make-vec (string-length (get-field "desc-title" (param 0))))
                (let "leb128_ptr_535" (make-vec (identifier "srec_dst_533"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_535")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_535"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_534"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_534"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_534"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_534") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_534")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_534")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_535"))))) 
              (bytes-of-string (get-field "desc-title" (param 0)))))
          (write-bytes
            (let "leb128_sz_537" (make-vec (string-length (get-field "desc-firing" (param 0))))
              (let "leb128_ptr_538" (make-vec (identifier "srec_dst_536"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_538")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_538"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_537"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_537"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_537"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_537") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_537")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_537")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_538"))))) 
            (bytes-of-string (get-field "desc-firing" (param 0)))))
        (write-bytes
          (let "leb128_sz_540" (make-vec (string-length (get-field "desc-recovery" (param 0))))
            (let "leb128_ptr_541" (make-vec (identifier "srec_dst_539"))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_541")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_541"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_540"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_540"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_540"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_540") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_540")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_540")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_541"))))) 
          (bytes-of-string (get-field "desc-recovery" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::alert::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::alert::t*,Pointer)> fun0 { [&fun0](::dessser::gen::alert::t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::fq_name::to_row_binary };
    dessser::gen::fq_name::t_ext id_2 { (*p_0).table };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_474 { id_3 };
      auto fun5 { dessser::gen::field_name::to_row_binary };
      dessser::gen::field_name::t_ext id_6 { (*p_0).column };
      Pointer id_7 { fun5(id_6, srec_dst_474) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_475 { let_res_4 };
      bool id_9 { (*p_0).enabled };
      uint8_t id_10 { uint8_t(id_9) };
      Pointer id_11 { srec_dst_475.writeU8(id_10) };
      let_res_8 = id_11;
    }
    Pointer let_res_12;
    {
      Pointer srec_dst_476 { let_res_8 };
      Lst<dessser::gen::simple_filter::t_ext> id_13 { (*p_0).where };
      uint32_t id_14 { id_13.size() };
      Vec<1, uint32_t> id_15 {  id_14  };
      Pointer let_res_16;
      {
        Vec<1, uint32_t> leb128_sz_477 { id_15 };
        Vec<1, Pointer> id_17 {  srec_dst_476  };
        Pointer let_res_18;
        {
          Vec<1, Pointer> leb128_ptr_478 { id_17 };
          bool while_flag_19 { true };
          do {
            uint8_t id_20 { 0 };
            uint8_t id_21 { 0 };
            Pointer id_22 { leb128_ptr_478[id_21] };
            uint32_t id_23 { 128U };
            uint8_t id_24 { 0 };
            uint32_t id_25 { leb128_sz_477[id_24] };
            bool id_26 { bool(id_23 > id_25) };
            uint8_t choose_res_27;
            if (id_26) {
              uint8_t id_28 { 0 };
              uint32_t id_29 { leb128_sz_477[id_28] };
              uint8_t id_30 { uint8_t(id_29) };
              choose_res_27 = id_30;
            } else {
              uint8_t id_31 { 0 };
              uint32_t id_32 { leb128_sz_477[id_31] };
              uint8_t id_33 { uint8_t(id_32) };
              uint8_t id_34 { 128 };
              uint8_t id_35 { uint8_t(id_33 | id_34) };
              choose_res_27 = id_35;
            }
            Pointer id_36 { id_22.writeU8(choose_res_27) };
            Void id_37 { ((void)(leb128_ptr_478[id_20] = id_36), VOID) };
            (void)id_37;
            uint8_t id_38 { 0 };
            uint8_t id_39 { 0 };
            uint32_t id_40 { leb128_sz_477[id_39] };
            uint8_t id_41 { 7 };
            uint32_t id_42 { uint32_t(id_40 >> id_41) };
            Void id_43 { ((void)(leb128_sz_477[id_38] = id_42), VOID) };
            (void)id_43;
            uint8_t id_44 { 0 };
            uint32_t id_45 { leb128_sz_477[id_44] };
            uint32_t id_46 { 0U };
            bool id_47 { bool(id_45 > id_46) };
            while_flag_19 = id_47;
            if (while_flag_19) {
              (void)VOID;
            }
          } while (while_flag_19);
          (void)VOID;
          uint8_t id_48 { 0 };
          Pointer id_49 { leb128_ptr_478[id_48] };
          let_res_18 = id_49;
        }
        let_res_16 = let_res_18;
      }
      Vec<1, Pointer> id_50 {  let_res_16  };
      Pointer let_res_51;
      {
        Vec<1, Pointer> dst_ref_479 { id_50 };
        int32_t id_52 { 0L };
        Vec<1, int32_t> id_53 {  id_52  };
        Pointer let_res_54;
        {
          Vec<1, int32_t> n_ref_480 { id_53 };
          Lst<dessser::gen::simple_filter::t_ext> id_55 { (*p_0).where };
          for (dessser::gen::simple_filter::t_ext x_481 : id_55) {
            uint8_t id_56 { 0 };
            auto fun57 { dessser::gen::simple_filter::to_row_binary };
            uint8_t id_58 { 0 };
            Pointer id_59 { dst_ref_479[id_58] };
            Pointer id_60 { fun57(x_481, id_59) };
            Void id_61 { ((void)(dst_ref_479[id_56] = id_60), VOID) };
            (void)id_61;
            uint8_t id_62 { 0 };
            int32_t id_63 { 1L };
            uint8_t id_64 { 0 };
            int32_t id_65 { n_ref_480[id_64] };
            int32_t id_66 { int32_t(id_63 + id_65) };
            Void id_67 { ((void)(n_ref_480[id_62] = id_66), VOID) };
            (void)id_67;
            (void)id_67;
          }
          (void)VOID;
          uint8_t id_68 { 0 };
          Pointer id_69 { dst_ref_479[id_68] };
          let_res_54 = id_69;
        }
        let_res_51 = let_res_54;
      }
      let_res_12 = let_res_51;
    }
    Pointer let_res_70;
    {
      Pointer srec_dst_482 { let_res_12 };
      std::optional<Lst<dessser::gen::field_name::t_ext>> id_71 { (*p_0).group_by };
      bool id_72 { !(id_71.has_value ()) };
      Pointer choose_res_73;
      if (id_72) {
        uint8_t id_74 { 1 };
        Pointer id_75 { srec_dst_482.writeU8(id_74) };
        choose_res_73 = id_75;
      } else {
        std::optional<Lst<dessser::gen::field_name::t_ext>> id_76 { (*p_0).group_by };
        Lst<dessser::gen::field_name::t_ext> id_77 { id_76.value() };
        uint32_t id_78 { id_77.size() };
        Vec<1, uint32_t> id_79 {  id_78  };
        Pointer let_res_80;
        {
          Vec<1, uint32_t> leb128_sz_483 { id_79 };
          uint8_t id_81 { 0 };
          Pointer id_82 { srec_dst_482.writeU8(id_81) };
          Vec<1, Pointer> id_83 {  id_82  };
          Pointer let_res_84;
          {
            Vec<1, Pointer> leb128_ptr_484 { id_83 };
            bool while_flag_85 { true };
            do {
              uint8_t id_86 { 0 };
              uint8_t id_87 { 0 };
              Pointer id_88 { leb128_ptr_484[id_87] };
              uint32_t id_89 { 128U };
              uint8_t id_90 { 0 };
              uint32_t id_91 { leb128_sz_483[id_90] };
              bool id_92 { bool(id_89 > id_91) };
              uint8_t choose_res_93;
              if (id_92) {
                uint8_t id_94 { 0 };
                uint32_t id_95 { leb128_sz_483[id_94] };
                uint8_t id_96 { uint8_t(id_95) };
                choose_res_93 = id_96;
              } else {
                uint8_t id_97 { 0 };
                uint32_t id_98 { leb128_sz_483[id_97] };
                uint8_t id_99 { uint8_t(id_98) };
                uint8_t id_100 { 128 };
                uint8_t id_101 { uint8_t(id_99 | id_100) };
                choose_res_93 = id_101;
              }
              Pointer id_102 { id_88.writeU8(choose_res_93) };
              Void id_103 { ((void)(leb128_ptr_484[id_86] = id_102), VOID) };
              (void)id_103;
              uint8_t id_104 { 0 };
              uint8_t id_105 { 0 };
              uint32_t id_106 { leb128_sz_483[id_105] };
              uint8_t id_107 { 7 };
              uint32_t id_108 { uint32_t(id_106 >> id_107) };
              Void id_109 { ((void)(leb128_sz_483[id_104] = id_108), VOID) };
              (void)id_109;
              uint8_t id_110 { 0 };
              uint32_t id_111 { leb128_sz_483[id_110] };
              uint32_t id_112 { 0U };
              bool id_113 { bool(id_111 > id_112) };
              while_flag_85 = id_113;
              if (while_flag_85) {
                (void)VOID;
              }
            } while (while_flag_85);
            (void)VOID;
            uint8_t id_114 { 0 };
            Pointer id_115 { leb128_ptr_484[id_114] };
            let_res_84 = id_115;
          }
          let_res_80 = let_res_84;
        }
        Vec<1, Pointer> id_116 {  let_res_80  };
        Pointer let_res_117;
        {
          Vec<1, Pointer> dst_ref_485 { id_116 };
          int32_t id_118 { 0L };
          Vec<1, int32_t> id_119 {  id_118  };
          Pointer let_res_120;
          {
            Vec<1, int32_t> n_ref_486 { id_119 };
            std::optional<Lst<dessser::gen::field_name::t_ext>> id_121 { (*p_0).group_by };
            Lst<dessser::gen::field_name::t_ext> id_122 { id_121.value() };
            for (dessser::gen::field_name::t_ext x_487 : id_122) {
              uint8_t id_123 { 0 };
              auto fun124 { dessser::gen::field_name::to_row_binary };
              uint8_t id_125 { 0 };
              Pointer id_126 { dst_ref_485[id_125] };
              Pointer id_127 { fun124(x_487, id_126) };
              Void id_128 { ((void)(dst_ref_485[id_123] = id_127), VOID) };
              (void)id_128;
              uint8_t id_129 { 0 };
              int32_t id_130 { 1L };
              uint8_t id_131 { 0 };
              int32_t id_132 { n_ref_486[id_131] };
              int32_t id_133 { int32_t(id_130 + id_132) };
              Void id_134 { ((void)(n_ref_486[id_129] = id_133), VOID) };
              (void)id_134;
              (void)id_134;
            }
            (void)VOID;
            uint8_t id_135 { 0 };
            Pointer id_136 { dst_ref_485[id_135] };
            let_res_120 = id_136;
          }
          let_res_117 = let_res_120;
        }
        choose_res_73 = let_res_117;
      }
      let_res_70 = choose_res_73;
    }
    Pointer let_res_137;
    {
      Pointer srec_dst_488 { let_res_70 };
      Lst<dessser::gen::simple_filter::t_ext> id_138 { (*p_0).having };
      uint32_t id_139 { id_138.size() };
      Vec<1, uint32_t> id_140 {  id_139  };
      Pointer let_res_141;
      {
        Vec<1, uint32_t> leb128_sz_489 { id_140 };
        Vec<1, Pointer> id_142 {  srec_dst_488  };
        Pointer let_res_143;
        {
          Vec<1, Pointer> leb128_ptr_490 { id_142 };
          bool while_flag_144 { true };
          do {
            uint8_t id_145 { 0 };
            uint8_t id_146 { 0 };
            Pointer id_147 { leb128_ptr_490[id_146] };
            uint32_t id_148 { 128U };
            uint8_t id_149 { 0 };
            uint32_t id_150 { leb128_sz_489[id_149] };
            bool id_151 { bool(id_148 > id_150) };
            uint8_t choose_res_152;
            if (id_151) {
              uint8_t id_153 { 0 };
              uint32_t id_154 { leb128_sz_489[id_153] };
              uint8_t id_155 { uint8_t(id_154) };
              choose_res_152 = id_155;
            } else {
              uint8_t id_156 { 0 };
              uint32_t id_157 { leb128_sz_489[id_156] };
              uint8_t id_158 { uint8_t(id_157) };
              uint8_t id_159 { 128 };
              uint8_t id_160 { uint8_t(id_158 | id_159) };
              choose_res_152 = id_160;
            }
            Pointer id_161 { id_147.writeU8(choose_res_152) };
            Void id_162 { ((void)(leb128_ptr_490[id_145] = id_161), VOID) };
            (void)id_162;
            uint8_t id_163 { 0 };
            uint8_t id_164 { 0 };
            uint32_t id_165 { leb128_sz_489[id_164] };
            uint8_t id_166 { 7 };
            uint32_t id_167 { uint32_t(id_165 >> id_166) };
            Void id_168 { ((void)(leb128_sz_489[id_163] = id_167), VOID) };
            (void)id_168;
            uint8_t id_169 { 0 };
            uint32_t id_170 { leb128_sz_489[id_169] };
            uint32_t id_171 { 0U };
            bool id_172 { bool(id_170 > id_171) };
            while_flag_144 = id_172;
            if (while_flag_144) {
              (void)VOID;
            }
          } while (while_flag_144);
          (void)VOID;
          uint8_t id_173 { 0 };
          Pointer id_174 { leb128_ptr_490[id_173] };
          let_res_143 = id_174;
        }
        let_res_141 = let_res_143;
      }
      Vec<1, Pointer> id_175 {  let_res_141  };
      Pointer let_res_176;
      {
        Vec<1, Pointer> dst_ref_491 { id_175 };
        int32_t id_177 { 0L };
        Vec<1, int32_t> id_178 {  id_177  };
        Pointer let_res_179;
        {
          Vec<1, int32_t> n_ref_492 { id_178 };
          Lst<dessser::gen::simple_filter::t_ext> id_180 { (*p_0).having };
          for (dessser::gen::simple_filter::t_ext x_493 : id_180) {
            uint8_t id_181 { 0 };
            auto fun182 { dessser::gen::simple_filter::to_row_binary };
            uint8_t id_183 { 0 };
            Pointer id_184 { dst_ref_491[id_183] };
            Pointer id_185 { fun182(x_493, id_184) };
            Void id_186 { ((void)(dst_ref_491[id_181] = id_185), VOID) };
            (void)id_186;
            uint8_t id_187 { 0 };
            int32_t id_188 { 1L };
            uint8_t id_189 { 0 };
            int32_t id_190 { n_ref_492[id_189] };
            int32_t id_191 { int32_t(id_188 + id_190) };
            Void id_192 { ((void)(n_ref_492[id_187] = id_191), VOID) };
            (void)id_192;
            (void)id_192;
          }
          (void)VOID;
          uint8_t id_193 { 0 };
          Pointer id_194 { dst_ref_491[id_193] };
          let_res_179 = id_194;
        }
        let_res_176 = let_res_179;
      }
      let_res_137 = let_res_176;
    }
    Pointer let_res_195;
    {
      Pointer srec_dst_494 { let_res_137 };
      ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_196 { (*p_0).threshold };
      uint16_t id_197 { uint16_t(id_196.index()) };
      Pointer id_198 { srec_dst_494.writeU16Le(id_197) };
      Pointer let_res_199;
      {
        Pointer ssum_dst_496 { id_198 };
        uint16_t id_200 { 0 };
        ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_201 { (*p_0).threshold };
        uint16_t id_202 { uint16_t(id_201.index()) };
        bool id_203 { bool(id_200 == id_202) };
        Pointer choose_res_204;
        if (id_203) {
          ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_205 { (*p_0).threshold };
          double id_206 { std::get<0 /* Constant */>(id_205) };
          uint64_t id_207 { qword_of_float(id_206) };
          Pointer id_208 { ssum_dst_496.writeU64Le(id_207) };
          choose_res_204 = id_208;
        } else {
          ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_209 { (*p_0).threshold };
          uint16_t id_210 { uint16_t(id_209.index()) };
          uint16_t id_211 { 1 };
          bool id_212 { bool(id_210 == id_211) };
          Void id_213 { ((void)(assert(id_212)), VOID) };
          (void)id_213;
          ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_214 { (*p_0).threshold };
          ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_215 { std::get<1 /* Baseline */>(id_214) };
          double id_216 { id_215.avg_window };
          uint64_t id_217 { qword_of_float(id_216) };
          Pointer id_218 { ssum_dst_496.writeU64Le(id_217) };
          Pointer let_res_219;
          {
            Pointer srec_dst_497 { id_218 };
            ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_220 { (*p_0).threshold };
            ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_221 { std::get<1 /* Baseline */>(id_220) };
            uint32_t id_222 { id_221.sample_size };
            Pointer id_223 { srec_dst_497.writeU32Le(id_222) };
            let_res_219 = id_223;
          }
          Pointer let_res_224;
          {
            Pointer srec_dst_498 { let_res_219 };
            ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_225 { (*p_0).threshold };
            ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_226 { std::get<1 /* Baseline */>(id_225) };
            double id_227 { id_226.percentile };
            uint64_t id_228 { qword_of_float(id_227) };
            Pointer id_229 { srec_dst_498.writeU64Le(id_228) };
            let_res_224 = id_229;
          }
          Pointer let_res_230;
          {
            Pointer srec_dst_499 { let_res_224 };
            ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_231 { (*p_0).threshold };
            ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_232 { std::get<1 /* Baseline */>(id_231) };
            uint32_t id_233 { id_232.seasonality };
            Pointer id_234 { srec_dst_499.writeU32Le(id_233) };
            let_res_230 = id_234;
          }
          Pointer let_res_235;
          {
            Pointer srec_dst_500 { let_res_230 };
            ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_236 { (*p_0).threshold };
            ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_237 { std::get<1 /* Baseline */>(id_236) };
            double id_238 { id_237.smooth_factor };
            uint64_t id_239 { qword_of_float(id_238) };
            Pointer id_240 { srec_dst_500.writeU64Le(id_239) };
            let_res_235 = id_240;
          }
          Pointer let_res_241;
          {
            Pointer srec_dst_501 { let_res_235 };
            ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_242 { (*p_0).threshold };
            ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_243 { std::get<1 /* Baseline */>(id_242) };
            ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f id_244 { id_243.max_distance };
            uint16_t id_245 { uint16_t(id_244.index()) };
            Pointer id_246 { srec_dst_501.writeU16Le(id_245) };
            Pointer let_res_247;
            {
              Pointer ssum_dst_503 { id_246 };
              uint16_t id_248 { 0 };
              ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_249 { (*p_0).threshold };
              ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_250 { std::get<1 /* Baseline */>(id_249) };
              ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f id_251 { id_250.max_distance };
              uint16_t id_252 { uint16_t(id_251.index()) };
              bool id_253 { bool(id_248 == id_252) };
              Pointer choose_res_254;
              if (id_253) {
                ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_255 { (*p_0).threshold };
                ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_256 { std::get<1 /* Baseline */>(id_255) };
                ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f id_257 { id_256.max_distance };
                double id_258 { std::get<0 /* Absolute */>(id_257) };
                uint64_t id_259 { qword_of_float(id_258) };
                Pointer id_260 { ssum_dst_503.writeU64Le(id_259) };
                choose_res_254 = id_260;
              } else {
                ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_261 { (*p_0).threshold };
                ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_262 { std::get<1 /* Baseline */>(id_261) };
                ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f id_263 { id_262.max_distance };
                uint16_t id_264 { uint16_t(id_263.index()) };
                uint16_t id_265 { 1 };
                bool id_266 { bool(id_264 == id_265) };
                Void id_267 { ((void)(assert(id_266)), VOID) };
                (void)id_267;
                ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_268 { (*p_0).threshold };
                ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_269 { std::get<1 /* Baseline */>(id_268) };
                ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f id_270 { id_269.max_distance };
                double id_271 { std::get<1 /* Relative */>(id_270) };
                uint64_t id_272 { qword_of_float(id_271) };
                Pointer id_273 { ssum_dst_503.writeU64Le(id_272) };
                choose_res_254 = id_273;
              }
              let_res_247 = choose_res_254;
            }
            let_res_241 = let_res_247;
          }
          choose_res_204 = let_res_241;
        }
        let_res_199 = choose_res_204;
      }
      let_res_195 = let_res_199;
    }
    Pointer let_res_274;
    {
      Pointer srec_dst_504 { let_res_195 };
      double id_275 { (*p_0).hysteresis };
      uint64_t id_276 { qword_of_float(id_275) };
      Pointer id_277 { srec_dst_504.writeU64Le(id_276) };
      let_res_274 = id_277;
    }
    Pointer let_res_278;
    {
      Pointer srec_dst_505 { let_res_274 };
      double id_279 { (*p_0).duration };
      uint64_t id_280 { qword_of_float(id_279) };
      Pointer id_281 { srec_dst_505.writeU64Le(id_280) };
      let_res_278 = id_281;
    }
    Pointer let_res_282;
    {
      Pointer srec_dst_506 { let_res_278 };
      double id_283 { (*p_0).ratio };
      uint64_t id_284 { qword_of_float(id_283) };
      Pointer id_285 { srec_dst_506.writeU64Le(id_284) };
      let_res_282 = id_285;
    }
    Pointer let_res_286;
    {
      Pointer srec_dst_507 { let_res_282 };
      double id_287 { (*p_0).time_step };
      uint64_t id_288 { qword_of_float(id_287) };
      Pointer id_289 { srec_dst_507.writeU64Le(id_288) };
      let_res_286 = id_289;
    }
    Pointer let_res_290;
    {
      Pointer srec_dst_508 { let_res_286 };
      Lst<dessser::gen::field_name::t_ext> id_291 { (*p_0).tops };
      uint32_t id_292 { id_291.size() };
      Vec<1, uint32_t> id_293 {  id_292  };
      Pointer let_res_294;
      {
        Vec<1, uint32_t> leb128_sz_509 { id_293 };
        Vec<1, Pointer> id_295 {  srec_dst_508  };
        Pointer let_res_296;
        {
          Vec<1, Pointer> leb128_ptr_510 { id_295 };
          bool while_flag_297 { true };
          do {
            uint8_t id_298 { 0 };
            uint8_t id_299 { 0 };
            Pointer id_300 { leb128_ptr_510[id_299] };
            uint32_t id_301 { 128U };
            uint8_t id_302 { 0 };
            uint32_t id_303 { leb128_sz_509[id_302] };
            bool id_304 { bool(id_301 > id_303) };
            uint8_t choose_res_305;
            if (id_304) {
              uint8_t id_306 { 0 };
              uint32_t id_307 { leb128_sz_509[id_306] };
              uint8_t id_308 { uint8_t(id_307) };
              choose_res_305 = id_308;
            } else {
              uint8_t id_309 { 0 };
              uint32_t id_310 { leb128_sz_509[id_309] };
              uint8_t id_311 { uint8_t(id_310) };
              uint8_t id_312 { 128 };
              uint8_t id_313 { uint8_t(id_311 | id_312) };
              choose_res_305 = id_313;
            }
            Pointer id_314 { id_300.writeU8(choose_res_305) };
            Void id_315 { ((void)(leb128_ptr_510[id_298] = id_314), VOID) };
            (void)id_315;
            uint8_t id_316 { 0 };
            uint8_t id_317 { 0 };
            uint32_t id_318 { leb128_sz_509[id_317] };
            uint8_t id_319 { 7 };
            uint32_t id_320 { uint32_t(id_318 >> id_319) };
            Void id_321 { ((void)(leb128_sz_509[id_316] = id_320), VOID) };
            (void)id_321;
            uint8_t id_322 { 0 };
            uint32_t id_323 { leb128_sz_509[id_322] };
            uint32_t id_324 { 0U };
            bool id_325 { bool(id_323 > id_324) };
            while_flag_297 = id_325;
            if (while_flag_297) {
              (void)VOID;
            }
          } while (while_flag_297);
          (void)VOID;
          uint8_t id_326 { 0 };
          Pointer id_327 { leb128_ptr_510[id_326] };
          let_res_296 = id_327;
        }
        let_res_294 = let_res_296;
      }
      Vec<1, Pointer> id_328 {  let_res_294  };
      Pointer let_res_329;
      {
        Vec<1, Pointer> dst_ref_511 { id_328 };
        int32_t id_330 { 0L };
        Vec<1, int32_t> id_331 {  id_330  };
        Pointer let_res_332;
        {
          Vec<1, int32_t> n_ref_512 { id_331 };
          Lst<dessser::gen::field_name::t_ext> id_333 { (*p_0).tops };
          for (dessser::gen::field_name::t_ext x_513 : id_333) {
            uint8_t id_334 { 0 };
            auto fun335 { dessser::gen::field_name::to_row_binary };
            uint8_t id_336 { 0 };
            Pointer id_337 { dst_ref_511[id_336] };
            Pointer id_338 { fun335(x_513, id_337) };
            Void id_339 { ((void)(dst_ref_511[id_334] = id_338), VOID) };
            (void)id_339;
            uint8_t id_340 { 0 };
            int32_t id_341 { 1L };
            uint8_t id_342 { 0 };
            int32_t id_343 { n_ref_512[id_342] };
            int32_t id_344 { int32_t(id_341 + id_343) };
            Void id_345 { ((void)(n_ref_512[id_340] = id_344), VOID) };
            (void)id_345;
            (void)id_345;
          }
          (void)VOID;
          uint8_t id_346 { 0 };
          Pointer id_347 { dst_ref_511[id_346] };
          let_res_332 = id_347;
        }
        let_res_329 = let_res_332;
      }
      let_res_290 = let_res_329;
    }
    Pointer let_res_348;
    {
      Pointer srec_dst_514 { let_res_290 };
      Lst<dessser::gen::field_name::t_ext> id_349 { (*p_0).carry_fields };
      uint32_t id_350 { id_349.size() };
      Vec<1, uint32_t> id_351 {  id_350  };
      Pointer let_res_352;
      {
        Vec<1, uint32_t> leb128_sz_515 { id_351 };
        Vec<1, Pointer> id_353 {  srec_dst_514  };
        Pointer let_res_354;
        {
          Vec<1, Pointer> leb128_ptr_516 { id_353 };
          bool while_flag_355 { true };
          do {
            uint8_t id_356 { 0 };
            uint8_t id_357 { 0 };
            Pointer id_358 { leb128_ptr_516[id_357] };
            uint32_t id_359 { 128U };
            uint8_t id_360 { 0 };
            uint32_t id_361 { leb128_sz_515[id_360] };
            bool id_362 { bool(id_359 > id_361) };
            uint8_t choose_res_363;
            if (id_362) {
              uint8_t id_364 { 0 };
              uint32_t id_365 { leb128_sz_515[id_364] };
              uint8_t id_366 { uint8_t(id_365) };
              choose_res_363 = id_366;
            } else {
              uint8_t id_367 { 0 };
              uint32_t id_368 { leb128_sz_515[id_367] };
              uint8_t id_369 { uint8_t(id_368) };
              uint8_t id_370 { 128 };
              uint8_t id_371 { uint8_t(id_369 | id_370) };
              choose_res_363 = id_371;
            }
            Pointer id_372 { id_358.writeU8(choose_res_363) };
            Void id_373 { ((void)(leb128_ptr_516[id_356] = id_372), VOID) };
            (void)id_373;
            uint8_t id_374 { 0 };
            uint8_t id_375 { 0 };
            uint32_t id_376 { leb128_sz_515[id_375] };
            uint8_t id_377 { 7 };
            uint32_t id_378 { uint32_t(id_376 >> id_377) };
            Void id_379 { ((void)(leb128_sz_515[id_374] = id_378), VOID) };
            (void)id_379;
            uint8_t id_380 { 0 };
            uint32_t id_381 { leb128_sz_515[id_380] };
            uint32_t id_382 { 0U };
            bool id_383 { bool(id_381 > id_382) };
            while_flag_355 = id_383;
            if (while_flag_355) {
              (void)VOID;
            }
          } while (while_flag_355);
          (void)VOID;
          uint8_t id_384 { 0 };
          Pointer id_385 { leb128_ptr_516[id_384] };
          let_res_354 = id_385;
        }
        let_res_352 = let_res_354;
      }
      Vec<1, Pointer> id_386 {  let_res_352  };
      Pointer let_res_387;
      {
        Vec<1, Pointer> dst_ref_517 { id_386 };
        int32_t id_388 { 0L };
        Vec<1, int32_t> id_389 {  id_388  };
        Pointer let_res_390;
        {
          Vec<1, int32_t> n_ref_518 { id_389 };
          Lst<dessser::gen::field_name::t_ext> id_391 { (*p_0).carry_fields };
          for (dessser::gen::field_name::t_ext x_519 : id_391) {
            uint8_t id_392 { 0 };
            auto fun393 { dessser::gen::field_name::to_row_binary };
            uint8_t id_394 { 0 };
            Pointer id_395 { dst_ref_517[id_394] };
            Pointer id_396 { fun393(x_519, id_395) };
            Void id_397 { ((void)(dst_ref_517[id_392] = id_396), VOID) };
            (void)id_397;
            uint8_t id_398 { 0 };
            int32_t id_399 { 1L };
            uint8_t id_400 { 0 };
            int32_t id_401 { n_ref_518[id_400] };
            int32_t id_402 { int32_t(id_399 + id_401) };
            Void id_403 { ((void)(n_ref_518[id_398] = id_402), VOID) };
            (void)id_403;
            (void)id_403;
          }
          (void)VOID;
          uint8_t id_404 { 0 };
          Pointer id_405 { dst_ref_517[id_404] };
          let_res_390 = id_405;
        }
        let_res_387 = let_res_390;
      }
      let_res_348 = let_res_387;
    }
    Pointer let_res_406;
    {
      Pointer srec_dst_520 { let_res_348 };
      Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> id_407 { (*p_0).carry_csts };
      uint32_t id_408 { id_407.size() };
      Vec<1, uint32_t> id_409 {  id_408  };
      Pointer let_res_410;
      {
        Vec<1, uint32_t> leb128_sz_521 { id_409 };
        Vec<1, Pointer> id_411 {  srec_dst_520  };
        Pointer let_res_412;
        {
          Vec<1, Pointer> leb128_ptr_522 { id_411 };
          bool while_flag_413 { true };
          do {
            uint8_t id_414 { 0 };
            uint8_t id_415 { 0 };
            Pointer id_416 { leb128_ptr_522[id_415] };
            uint32_t id_417 { 128U };
            uint8_t id_418 { 0 };
            uint32_t id_419 { leb128_sz_521[id_418] };
            bool id_420 { bool(id_417 > id_419) };
            uint8_t choose_res_421;
            if (id_420) {
              uint8_t id_422 { 0 };
              uint32_t id_423 { leb128_sz_521[id_422] };
              uint8_t id_424 { uint8_t(id_423) };
              choose_res_421 = id_424;
            } else {
              uint8_t id_425 { 0 };
              uint32_t id_426 { leb128_sz_521[id_425] };
              uint8_t id_427 { uint8_t(id_426) };
              uint8_t id_428 { 128 };
              uint8_t id_429 { uint8_t(id_427 | id_428) };
              choose_res_421 = id_429;
            }
            Pointer id_430 { id_416.writeU8(choose_res_421) };
            Void id_431 { ((void)(leb128_ptr_522[id_414] = id_430), VOID) };
            (void)id_431;
            uint8_t id_432 { 0 };
            uint8_t id_433 { 0 };
            uint32_t id_434 { leb128_sz_521[id_433] };
            uint8_t id_435 { 7 };
            uint32_t id_436 { uint32_t(id_434 >> id_435) };
            Void id_437 { ((void)(leb128_sz_521[id_432] = id_436), VOID) };
            (void)id_437;
            uint8_t id_438 { 0 };
            uint32_t id_439 { leb128_sz_521[id_438] };
            uint32_t id_440 { 0U };
            bool id_441 { bool(id_439 > id_440) };
            while_flag_413 = id_441;
            if (while_flag_413) {
              (void)VOID;
            }
          } while (while_flag_413);
          (void)VOID;
          uint8_t id_442 { 0 };
          Pointer id_443 { leb128_ptr_522[id_442] };
          let_res_412 = id_443;
        }
        let_res_410 = let_res_412;
      }
      Vec<1, Pointer> id_444 {  let_res_410  };
      Pointer let_res_445;
      {
        Vec<1, Pointer> dst_ref_523 { id_444 };
        int32_t id_446 { 0L };
        Vec<1, int32_t> id_447 {  id_446  };
        Pointer let_res_448;
        {
          Vec<1, int32_t> n_ref_524 { id_447 };
          Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> id_449 { (*p_0).carry_csts };
          for (::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d x_525 : id_449) {
            uint8_t id_450 { 0 };
            uint8_t id_451 { 0 };
            Pointer id_452 { dst_ref_523[id_451] };
            Pointer let_res_453;
            {
              Pointer stup_dst_526 { id_452 };
              auto fun454 { dessser::gen::field_name::to_row_binary };
              dessser::gen::field_name::t_ext id_455 { std::get<0>(x_525) };
              Pointer id_456 { fun454(id_455, stup_dst_526) };
              let_res_453 = id_456;
            }
            Pointer let_res_457;
            {
              Pointer stup_dst_527 { let_res_453 };
              std::string id_458 { std::get<1>(x_525) };
              uint32_t id_459 { (uint32_t)id_458.size() };
              Vec<1, uint32_t> id_460 {  id_459  };
              Pointer let_res_461;
              {
                Vec<1, uint32_t> leb128_sz_528 { id_460 };
                Vec<1, Pointer> id_462 {  stup_dst_527  };
                Pointer let_res_463;
                {
                  Vec<1, Pointer> leb128_ptr_529 { id_462 };
                  bool while_flag_464 { true };
                  do {
                    uint8_t id_465 { 0 };
                    uint8_t id_466 { 0 };
                    Pointer id_467 { leb128_ptr_529[id_466] };
                    uint32_t id_468 { 128U };
                    uint8_t id_469 { 0 };
                    uint32_t id_470 { leb128_sz_528[id_469] };
                    bool id_471 { bool(id_468 > id_470) };
                    uint8_t choose_res_472;
                    if (id_471) {
                      uint8_t id_473 { 0 };
                      uint32_t id_474 { leb128_sz_528[id_473] };
                      uint8_t id_475 { uint8_t(id_474) };
                      choose_res_472 = id_475;
                    } else {
                      uint8_t id_476 { 0 };
                      uint32_t id_477 { leb128_sz_528[id_476] };
                      uint8_t id_478 { uint8_t(id_477) };
                      uint8_t id_479 { 128 };
                      uint8_t id_480 { uint8_t(id_478 | id_479) };
                      choose_res_472 = id_480;
                    }
                    Pointer id_481 { id_467.writeU8(choose_res_472) };
                    Void id_482 { ((void)(leb128_ptr_529[id_465] = id_481), VOID) };
                    (void)id_482;
                    uint8_t id_483 { 0 };
                    uint8_t id_484 { 0 };
                    uint32_t id_485 { leb128_sz_528[id_484] };
                    uint8_t id_486 { 7 };
                    uint32_t id_487 { uint32_t(id_485 >> id_486) };
                    Void id_488 { ((void)(leb128_sz_528[id_483] = id_487), VOID) };
                    (void)id_488;
                    uint8_t id_489 { 0 };
                    uint32_t id_490 { leb128_sz_528[id_489] };
                    uint32_t id_491 { 0U };
                    bool id_492 { bool(id_490 > id_491) };
                    while_flag_464 = id_492;
                    if (while_flag_464) {
                      (void)VOID;
                    }
                  } while (while_flag_464);
                  (void)VOID;
                  uint8_t id_493 { 0 };
                  Pointer id_494 { leb128_ptr_529[id_493] };
                  let_res_463 = id_494;
                }
                let_res_461 = let_res_463;
              }
              std::string id_495 { std::get<1>(x_525) };
              Bytes id_496 { id_495 };
              Pointer id_497 { let_res_461.writeBytes(id_496) };
              let_res_457 = id_497;
            }
            Void id_498 { ((void)(dst_ref_523[id_450] = let_res_457), VOID) };
            (void)id_498;
            uint8_t id_499 { 0 };
            int32_t id_500 { 1L };
            uint8_t id_501 { 0 };
            int32_t id_502 { n_ref_524[id_501] };
            int32_t id_503 { int32_t(id_500 + id_502) };
            Void id_504 { ((void)(n_ref_524[id_499] = id_503), VOID) };
            (void)id_504;
            (void)id_504;
          }
          (void)VOID;
          uint8_t id_505 { 0 };
          Pointer id_506 { dst_ref_523[id_505] };
          let_res_448 = id_506;
        }
        let_res_445 = let_res_448;
      }
      let_res_406 = let_res_445;
    }
    Pointer let_res_507;
    {
      Pointer srec_dst_530 { let_res_406 };
      std::string id_508 { (*p_0).id };
      uint32_t id_509 { (uint32_t)id_508.size() };
      Vec<1, uint32_t> id_510 {  id_509  };
      Pointer let_res_511;
      {
        Vec<1, uint32_t> leb128_sz_531 { id_510 };
        Vec<1, Pointer> id_512 {  srec_dst_530  };
        Pointer let_res_513;
        {
          Vec<1, Pointer> leb128_ptr_532 { id_512 };
          bool while_flag_514 { true };
          do {
            uint8_t id_515 { 0 };
            uint8_t id_516 { 0 };
            Pointer id_517 { leb128_ptr_532[id_516] };
            uint32_t id_518 { 128U };
            uint8_t id_519 { 0 };
            uint32_t id_520 { leb128_sz_531[id_519] };
            bool id_521 { bool(id_518 > id_520) };
            uint8_t choose_res_522;
            if (id_521) {
              uint8_t id_523 { 0 };
              uint32_t id_524 { leb128_sz_531[id_523] };
              uint8_t id_525 { uint8_t(id_524) };
              choose_res_522 = id_525;
            } else {
              uint8_t id_526 { 0 };
              uint32_t id_527 { leb128_sz_531[id_526] };
              uint8_t id_528 { uint8_t(id_527) };
              uint8_t id_529 { 128 };
              uint8_t id_530 { uint8_t(id_528 | id_529) };
              choose_res_522 = id_530;
            }
            Pointer id_531 { id_517.writeU8(choose_res_522) };
            Void id_532 { ((void)(leb128_ptr_532[id_515] = id_531), VOID) };
            (void)id_532;
            uint8_t id_533 { 0 };
            uint8_t id_534 { 0 };
            uint32_t id_535 { leb128_sz_531[id_534] };
            uint8_t id_536 { 7 };
            uint32_t id_537 { uint32_t(id_535 >> id_536) };
            Void id_538 { ((void)(leb128_sz_531[id_533] = id_537), VOID) };
            (void)id_538;
            uint8_t id_539 { 0 };
            uint32_t id_540 { leb128_sz_531[id_539] };
            uint32_t id_541 { 0U };
            bool id_542 { bool(id_540 > id_541) };
            while_flag_514 = id_542;
            if (while_flag_514) {
              (void)VOID;
            }
          } while (while_flag_514);
          (void)VOID;
          uint8_t id_543 { 0 };
          Pointer id_544 { leb128_ptr_532[id_543] };
          let_res_513 = id_544;
        }
        let_res_511 = let_res_513;
      }
      std::string id_545 { (*p_0).id };
      Bytes id_546 { id_545 };
      Pointer id_547 { let_res_511.writeBytes(id_546) };
      let_res_507 = id_547;
    }
    Pointer let_res_548;
    {
      Pointer srec_dst_533 { let_res_507 };
      std::string id_549 { (*p_0).desc_title };
      uint32_t id_550 { (uint32_t)id_549.size() };
      Vec<1, uint32_t> id_551 {  id_550  };
      Pointer let_res_552;
      {
        Vec<1, uint32_t> leb128_sz_534 { id_551 };
        Vec<1, Pointer> id_553 {  srec_dst_533  };
        Pointer let_res_554;
        {
          Vec<1, Pointer> leb128_ptr_535 { id_553 };
          bool while_flag_555 { true };
          do {
            uint8_t id_556 { 0 };
            uint8_t id_557 { 0 };
            Pointer id_558 { leb128_ptr_535[id_557] };
            uint32_t id_559 { 128U };
            uint8_t id_560 { 0 };
            uint32_t id_561 { leb128_sz_534[id_560] };
            bool id_562 { bool(id_559 > id_561) };
            uint8_t choose_res_563;
            if (id_562) {
              uint8_t id_564 { 0 };
              uint32_t id_565 { leb128_sz_534[id_564] };
              uint8_t id_566 { uint8_t(id_565) };
              choose_res_563 = id_566;
            } else {
              uint8_t id_567 { 0 };
              uint32_t id_568 { leb128_sz_534[id_567] };
              uint8_t id_569 { uint8_t(id_568) };
              uint8_t id_570 { 128 };
              uint8_t id_571 { uint8_t(id_569 | id_570) };
              choose_res_563 = id_571;
            }
            Pointer id_572 { id_558.writeU8(choose_res_563) };
            Void id_573 { ((void)(leb128_ptr_535[id_556] = id_572), VOID) };
            (void)id_573;
            uint8_t id_574 { 0 };
            uint8_t id_575 { 0 };
            uint32_t id_576 { leb128_sz_534[id_575] };
            uint8_t id_577 { 7 };
            uint32_t id_578 { uint32_t(id_576 >> id_577) };
            Void id_579 { ((void)(leb128_sz_534[id_574] = id_578), VOID) };
            (void)id_579;
            uint8_t id_580 { 0 };
            uint32_t id_581 { leb128_sz_534[id_580] };
            uint32_t id_582 { 0U };
            bool id_583 { bool(id_581 > id_582) };
            while_flag_555 = id_583;
            if (while_flag_555) {
              (void)VOID;
            }
          } while (while_flag_555);
          (void)VOID;
          uint8_t id_584 { 0 };
          Pointer id_585 { leb128_ptr_535[id_584] };
          let_res_554 = id_585;
        }
        let_res_552 = let_res_554;
      }
      std::string id_586 { (*p_0).desc_title };
      Bytes id_587 { id_586 };
      Pointer id_588 { let_res_552.writeBytes(id_587) };
      let_res_548 = id_588;
    }
    Pointer let_res_589;
    {
      Pointer srec_dst_536 { let_res_548 };
      std::string id_590 { (*p_0).desc_firing };
      uint32_t id_591 { (uint32_t)id_590.size() };
      Vec<1, uint32_t> id_592 {  id_591  };
      Pointer let_res_593;
      {
        Vec<1, uint32_t> leb128_sz_537 { id_592 };
        Vec<1, Pointer> id_594 {  srec_dst_536  };
        Pointer let_res_595;
        {
          Vec<1, Pointer> leb128_ptr_538 { id_594 };
          bool while_flag_596 { true };
          do {
            uint8_t id_597 { 0 };
            uint8_t id_598 { 0 };
            Pointer id_599 { leb128_ptr_538[id_598] };
            uint32_t id_600 { 128U };
            uint8_t id_601 { 0 };
            uint32_t id_602 { leb128_sz_537[id_601] };
            bool id_603 { bool(id_600 > id_602) };
            uint8_t choose_res_604;
            if (id_603) {
              uint8_t id_605 { 0 };
              uint32_t id_606 { leb128_sz_537[id_605] };
              uint8_t id_607 { uint8_t(id_606) };
              choose_res_604 = id_607;
            } else {
              uint8_t id_608 { 0 };
              uint32_t id_609 { leb128_sz_537[id_608] };
              uint8_t id_610 { uint8_t(id_609) };
              uint8_t id_611 { 128 };
              uint8_t id_612 { uint8_t(id_610 | id_611) };
              choose_res_604 = id_612;
            }
            Pointer id_613 { id_599.writeU8(choose_res_604) };
            Void id_614 { ((void)(leb128_ptr_538[id_597] = id_613), VOID) };
            (void)id_614;
            uint8_t id_615 { 0 };
            uint8_t id_616 { 0 };
            uint32_t id_617 { leb128_sz_537[id_616] };
            uint8_t id_618 { 7 };
            uint32_t id_619 { uint32_t(id_617 >> id_618) };
            Void id_620 { ((void)(leb128_sz_537[id_615] = id_619), VOID) };
            (void)id_620;
            uint8_t id_621 { 0 };
            uint32_t id_622 { leb128_sz_537[id_621] };
            uint32_t id_623 { 0U };
            bool id_624 { bool(id_622 > id_623) };
            while_flag_596 = id_624;
            if (while_flag_596) {
              (void)VOID;
            }
          } while (while_flag_596);
          (void)VOID;
          uint8_t id_625 { 0 };
          Pointer id_626 { leb128_ptr_538[id_625] };
          let_res_595 = id_626;
        }
        let_res_593 = let_res_595;
      }
      std::string id_627 { (*p_0).desc_firing };
      Bytes id_628 { id_627 };
      Pointer id_629 { let_res_593.writeBytes(id_628) };
      let_res_589 = id_629;
    }
    Pointer let_res_630;
    {
      Pointer srec_dst_539 { let_res_589 };
      std::string id_631 { (*p_0).desc_recovery };
      uint32_t id_632 { (uint32_t)id_631.size() };
      Vec<1, uint32_t> id_633 {  id_632  };
      Pointer let_res_634;
      {
        Vec<1, uint32_t> leb128_sz_540 { id_633 };
        Vec<1, Pointer> id_635 {  srec_dst_539  };
        Pointer let_res_636;
        {
          Vec<1, Pointer> leb128_ptr_541 { id_635 };
          bool while_flag_637 { true };
          do {
            uint8_t id_638 { 0 };
            uint8_t id_639 { 0 };
            Pointer id_640 { leb128_ptr_541[id_639] };
            uint32_t id_641 { 128U };
            uint8_t id_642 { 0 };
            uint32_t id_643 { leb128_sz_540[id_642] };
            bool id_644 { bool(id_641 > id_643) };
            uint8_t choose_res_645;
            if (id_644) {
              uint8_t id_646 { 0 };
              uint32_t id_647 { leb128_sz_540[id_646] };
              uint8_t id_648 { uint8_t(id_647) };
              choose_res_645 = id_648;
            } else {
              uint8_t id_649 { 0 };
              uint32_t id_650 { leb128_sz_540[id_649] };
              uint8_t id_651 { uint8_t(id_650) };
              uint8_t id_652 { 128 };
              uint8_t id_653 { uint8_t(id_651 | id_652) };
              choose_res_645 = id_653;
            }
            Pointer id_654 { id_640.writeU8(choose_res_645) };
            Void id_655 { ((void)(leb128_ptr_541[id_638] = id_654), VOID) };
            (void)id_655;
            uint8_t id_656 { 0 };
            uint8_t id_657 { 0 };
            uint32_t id_658 { leb128_sz_540[id_657] };
            uint8_t id_659 { 7 };
            uint32_t id_660 { uint32_t(id_658 >> id_659) };
            Void id_661 { ((void)(leb128_sz_540[id_656] = id_660), VOID) };
            (void)id_661;
            uint8_t id_662 { 0 };
            uint32_t id_663 { leb128_sz_540[id_662] };
            uint32_t id_664 { 0U };
            bool id_665 { bool(id_663 > id_664) };
            while_flag_637 = id_665;
            if (while_flag_637) {
              (void)VOID;
            }
          } while (while_flag_637);
          (void)VOID;
          uint8_t id_666 { 0 };
          Pointer id_667 { leb128_ptr_541[id_666] };
          let_res_636 = id_667;
        }
        let_res_634 = let_res_636;
      }
      std::string id_668 { (*p_0).desc_recovery };
      Bytes id_669 { id_668 };
      Pointer id_670 { let_res_634.writeBytes(id_669) };
      let_res_630 = id_670;
    }
    return let_res_630;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::alert::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{table: $fq_name; column: $field_name; enabled: BOOL; where: $simple_filter[[]]; group-by: $field_name[[]]?; having: $simple_filter[[]]; threshold: [Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]; hysteresis: FLOAT; duration: FLOAT; ratio: FLOAT; time-step: FLOAT; tops: $field_name[[]]; carry-fields: $field_name[[]]; carry-csts: ($field_name; STRING)[[]]; id: STRING; desc-title: STRING; desc-firing: STRING; desc-recovery: STRING}")
      (let "sz_470"
        (let "sz_466"
          (let "sz_462"
            (let "sz_458"
              (let "sz_448"
                (let "sz_443"
                  (let "sz_438"
                    (add
                      (add
                        (add
                          (add
                            (let "sz_425"
                              (let "sz_420"
                                (let "sz_415"
                                  (let "sz_410"
                                    (add
                                      (let "sz_408" (apply (ext-identifier fq_name sersize-of-row-binary) (get-field "table" (param 0)))
                                        (add (identifier "sz_408") (apply (ext-identifier field_name sersize-of-row-binary) (get-field "column" (param 0))))) 
                                      (size 1))
                                    (let "sz_ref_413"
                                      (make-vec
                                        (add (identifier "sz_410")
                                          (let "n_ref_411" (make-vec (cardinality (get-field "where" (param 0))))
                                            (let "lebsz_ref_412" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_411")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_412")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_412") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_412")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_412"))))))))
                                      (seq
                                        (let "repeat_n_414" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (get-field "where" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_414")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_413")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_413"))
                                                  (apply (ext-identifier simple_filter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_414")) (get-field "where" (param 0))))))
                                              (set-vec (u8 0) (identifier "repeat_n_414") (add (unsafe-nth (u8 0) (identifier "repeat_n_414")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_413")))))
                                  (if (is-null (get-field "group-by" (param 0))) 
                                    (add (identifier "sz_415") (size 1))
                                    (add
                                      (let "sz_ref_418"
                                        (make-vec
                                          (add (identifier "sz_415")
                                            (let "n_ref_416" (make-vec (cardinality (force (get-field "group-by" (param 0)))))
                                              (let "lebsz_ref_417" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_416")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_417")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_417") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_417")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_417"))))))))
                                        (seq
                                          (let "repeat_n_419" (make-vec (i32 0))
                                            (while (gt (to-i32 (cardinality (force (get-field "group-by" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_419")))
                                              (seq
                                                (set-vec (u8 0) (identifier "sz_ref_418")
                                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_418"))
                                                    (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_419")) (force (get-field "group-by" (param 0)))))))
                                                (set-vec (u8 0) (identifier "repeat_n_419") (add (unsafe-nth (u8 0) (identifier "repeat_n_419")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "sz_ref_418")))) 
                                      (size 1))))
                                (let "sz_ref_423"
                                  (make-vec
                                    (add (identifier "sz_420")
                                      (let "n_ref_421" (make-vec (cardinality (get-field "having" (param 0))))
                                        (let "lebsz_ref_422" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_421")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_422")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_422") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_422")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_422"))))))))
                                  (seq
                                    (let "repeat_n_424" (make-vec (i32 0))
                                      (while (gt (to-i32 (cardinality (get-field "having" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_424")))
                                        (seq
                                          (set-vec (u8 0) (identifier "sz_ref_423")
                                            (add (unsafe-nth (u8 0) (identifier "sz_ref_423"))
                                              (apply (ext-identifier simple_filter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_424")) (get-field "having" (param 0))))))
                                          (set-vec (u8 0) (identifier "repeat_n_424") (add (unsafe-nth (u8 0) (identifier "repeat_n_424")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "sz_ref_423")))))
                              (if (eq (u16 0) (label-of (get-field "threshold" (param 0)))) 
                                (add (add (identifier "sz_425") (size 2)) (size 8))
                                (seq (assert (eq (label-of (get-field "threshold" (param 0))) (u16 1)))
                                  (if (eq (u16 0) (label-of (get-field "max_distance" (get-alt "Baseline" (get-field "threshold" (param 0))))))
                                    (add (add (add (add (add (add (add (add (identifier "sz_425") (size 2)) (size 8)) (size 4)) (size 8)) (size 4)) (size 8)) (size 2)) (size 8))
                                    (seq (assert (eq (label-of (get-field "max_distance" (get-alt "Baseline" (get-field "threshold" (param 0))))) (u16 1)))
                                      (add (add (add (add (add (add (add (add (identifier "sz_425") (size 2)) (size 8)) (size 4)) (size 8)) (size 4)) (size 8)) (size 2)) (size 8))))))) 
                            (size 8)) (size 8)) (size 8)) (size 8))
                    (let "sz_ref_441"
                      (make-vec
                        (add (identifier "sz_438")
                          (let "n_ref_439" (make-vec (cardinality (get-field "tops" (param 0))))
                            (let "lebsz_ref_440" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_439")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_440")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_440") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_440")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_440"))))))))
                      (seq
                        (let "repeat_n_442" (make-vec (i32 0))
                          (while (gt (to-i32 (cardinality (get-field "tops" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_442")))
                            (seq
                              (set-vec (u8 0) (identifier "sz_ref_441")
                                (add (unsafe-nth (u8 0) (identifier "sz_ref_441"))
                                  (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_442")) (get-field "tops" (param 0))))))
                              (set-vec (u8 0) (identifier "repeat_n_442") (add (unsafe-nth (u8 0) (identifier "repeat_n_442")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "sz_ref_441")))))
                  (let "sz_ref_446"
                    (make-vec
                      (add (identifier "sz_443")
                        (let "n_ref_444" (make-vec (cardinality (get-field "carry-fields" (param 0))))
                          (let "lebsz_ref_445" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_444")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_445")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_445") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_445")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_445"))))))))
                    (seq
                      (let "repeat_n_447" (make-vec (i32 0))
                        (while (gt (to-i32 (cardinality (get-field "carry-fields" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_447")))
                          (seq
                            (set-vec (u8 0) (identifier "sz_ref_446")
                              (add (unsafe-nth (u8 0) (identifier "sz_ref_446"))
                                (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_447")) (get-field "carry-fields" (param 0))))))
                            (set-vec (u8 0) (identifier "repeat_n_447") (add (unsafe-nth (u8 0) (identifier "repeat_n_447")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "sz_ref_446")))))
                (let "sz_ref_451"
                  (make-vec
                    (add (identifier "sz_448")
                      (let "n_ref_449" (make-vec (cardinality (get-field "carry-csts" (param 0))))
                        (let "lebsz_ref_450" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_449")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_450")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_450") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_450")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_450"))))))))
                  (seq
                    (let "repeat_n_452" (make-vec (i32 0))
                      (while (gt (to-i32 (cardinality (get-field "carry-csts" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_452")))
                        (seq
                          (set-vec (u8 0) (identifier "sz_ref_451")
                            (let "sz_454"
                              (let "sz_453" (unsafe-nth (u8 0) (identifier "sz_ref_451"))
                                (add (identifier "sz_453") (apply (ext-identifier field_name sersize-of-row-binary) (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_452")) (get-field "carry-csts" (param 0)))))))
                              (add (identifier "sz_454")
                                (let "wlen_455" (string-length (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_452")) (get-field "carry-csts" (param 0)))))
                                  (add
                                    (let "n_ref_456" (make-vec (identifier "wlen_455"))
                                      (let "lebsz_ref_457" (make-vec (u32 1))
                                        (seq
                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_456")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_457")) (u8 7)))
                                            (set-vec (u8 0) (identifier "lebsz_ref_457") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_457")) (u32 1)))) 
                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_457")))))) 
                                    (size-of-u32 (identifier "wlen_455"))))))) 
                          (set-vec (u8 0) (identifier "repeat_n_452") (add (unsafe-nth (u8 0) (identifier "repeat_n_452")) (i32 1)))))) 
                    (unsafe-nth (u8 0) (identifier "sz_ref_451")))))
              (add (identifier "sz_458")
                (add
                  (let "n_ref_460" (make-vec (string-length (get-field "id" (param 0))))
                    (let "lebsz_ref_461" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_460")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_461")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_461") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_461")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_461")))))) 
                  (size-of-u32 (string-length (get-field "id" (param 0)))))))
            (add (identifier "sz_462")
              (add
                (let "n_ref_464" (make-vec (string-length (get-field "desc-title" (param 0))))
                  (let "lebsz_ref_465" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_464")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_465")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_465") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_465")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_465")))))) 
                (size-of-u32 (string-length (get-field "desc-title" (param 0)))))))
          (add (identifier "sz_466")
            (add
              (let "n_ref_468" (make-vec (string-length (get-field "desc-firing" (param 0))))
                (let "lebsz_ref_469" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_468")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_469")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_469") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_469")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_469")))))) 
              (size-of-u32 (string-length (get-field "desc-firing" (param 0)))))))
        (add (identifier "sz_470")
          (add
            (let "n_ref_472" (make-vec (string-length (get-field "desc-recovery" (param 0))))
              (let "lebsz_ref_473" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_472")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_473")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_473") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_473")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_473")))))) 
            (size-of-u32 (string-length (get-field "desc-recovery" (param 0))))))))
 */
static std::function<Size(::dessser::gen::alert::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::alert::t*)> fun671 { [&fun671](::dessser::gen::alert::t* p_0) {
    auto fun672 { dessser::gen::fq_name::sersize_of_row_binary };
    dessser::gen::fq_name::t_ext id_673 { (*p_0).table };
    Size id_674 { fun672(id_673) };
    Size let_res_675;
    {
      Size sz_408 { id_674 };
      auto fun676 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_677 { (*p_0).column };
      Size id_678 { fun676(id_677) };
      Size id_679 { Size(sz_408 + id_678) };
      let_res_675 = id_679;
    }
    Size id_680 { 1UL };
    Size id_681 { Size(let_res_675 + id_680) };
    Size let_res_682;
    {
      Size sz_410 { id_681 };
      Lst<dessser::gen::simple_filter::t_ext> id_683 { (*p_0).where };
      uint32_t id_684 { id_683.size() };
      Vec<1, uint32_t> id_685 {  id_684  };
      Size let_res_686;
      {
        Vec<1, uint32_t> n_ref_411 { id_685 };
        uint32_t id_687 { 1U };
        Vec<1, uint32_t> id_688 {  id_687  };
        Size let_res_689;
        {
          Vec<1, uint32_t> lebsz_ref_412 { id_688 };
          bool while_flag_690 { true };
          do {
            uint8_t id_691 { 0 };
            uint32_t id_692 { n_ref_411[id_691] };
            uint8_t id_693 { 0 };
            uint32_t id_694 { lebsz_ref_412[id_693] };
            uint8_t id_695 { 7 };
            uint32_t id_696 { uint32_t(id_694 << id_695) };
            bool id_697 { bool(id_692 >= id_696) };
            while_flag_690 = id_697;
            if (while_flag_690) {
              uint8_t id_698 { 0 };
              uint8_t id_699 { 0 };
              uint32_t id_700 { lebsz_ref_412[id_699] };
              uint32_t id_701 { 1U };
              uint32_t id_702 { uint32_t(id_700 + id_701) };
              Void id_703 { ((void)(lebsz_ref_412[id_698] = id_702), VOID) };
              (void)id_703;
            }
          } while (while_flag_690);
          (void)VOID;
          uint8_t id_704 { 0 };
          uint32_t id_705 { lebsz_ref_412[id_704] };
          Size id_706 { Size(id_705) };
          let_res_689 = id_706;
        }
        let_res_686 = let_res_689;
      }
      Size id_707 { Size(sz_410 + let_res_686) };
      Vec<1, Size> id_708 {  id_707  };
      Size let_res_709;
      {
        Vec<1, Size> sz_ref_413 { id_708 };
        int32_t id_710 { 0L };
        Vec<1, int32_t> id_711 {  id_710  };
        {
          Vec<1, int32_t> repeat_n_414 { id_711 };
          bool while_flag_712 { true };
          do {
            Lst<dessser::gen::simple_filter::t_ext> id_713 { (*p_0).where };
            uint32_t id_714 { id_713.size() };
            int32_t id_715 { int32_t(id_714) };
            uint8_t id_716 { 0 };
            int32_t id_717 { repeat_n_414[id_716] };
            bool id_718 { bool(id_715 > id_717) };
            while_flag_712 = id_718;
            if (while_flag_712) {
              uint8_t id_719 { 0 };
              uint8_t id_720 { 0 };
              Size id_721 { sz_ref_413[id_720] };
              auto fun722 { dessser::gen::simple_filter::sersize_of_row_binary };
              uint8_t id_723 { 0 };
              int32_t id_724 { repeat_n_414[id_723] };
              Lst<dessser::gen::simple_filter::t_ext> id_725 { (*p_0).where };
              dessser::gen::simple_filter::t_ext id_726 { id_725[id_724] };
              Size id_727 { fun722(id_726) };
              Size id_728 { Size(id_721 + id_727) };
              Void id_729 { ((void)(sz_ref_413[id_719] = id_728), VOID) };
              (void)id_729;
              uint8_t id_730 { 0 };
              uint8_t id_731 { 0 };
              int32_t id_732 { repeat_n_414[id_731] };
              int32_t id_733 { 1L };
              int32_t id_734 { int32_t(id_732 + id_733) };
              Void id_735 { ((void)(repeat_n_414[id_730] = id_734), VOID) };
              (void)id_735;
              (void)id_735;
            }
          } while (while_flag_712);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_736 { 0 };
        Size id_737 { sz_ref_413[id_736] };
        let_res_709 = id_737;
      }
      let_res_682 = let_res_709;
    }
    Size let_res_738;
    {
      Size sz_415 { let_res_682 };
      std::optional<Lst<dessser::gen::field_name::t_ext>> id_739 { (*p_0).group_by };
      bool id_740 { !(id_739.has_value ()) };
      Size choose_res_741;
      if (id_740) {
        Size id_742 { 1UL };
        Size id_743 { Size(sz_415 + id_742) };
        choose_res_741 = id_743;
      } else {
        std::optional<Lst<dessser::gen::field_name::t_ext>> id_744 { (*p_0).group_by };
        Lst<dessser::gen::field_name::t_ext> id_745 { id_744.value() };
        uint32_t id_746 { id_745.size() };
        Vec<1, uint32_t> id_747 {  id_746  };
        Size let_res_748;
        {
          Vec<1, uint32_t> n_ref_416 { id_747 };
          uint32_t id_749 { 1U };
          Vec<1, uint32_t> id_750 {  id_749  };
          Size let_res_751;
          {
            Vec<1, uint32_t> lebsz_ref_417 { id_750 };
            bool while_flag_752 { true };
            do {
              uint8_t id_753 { 0 };
              uint32_t id_754 { n_ref_416[id_753] };
              uint8_t id_755 { 0 };
              uint32_t id_756 { lebsz_ref_417[id_755] };
              uint8_t id_757 { 7 };
              uint32_t id_758 { uint32_t(id_756 << id_757) };
              bool id_759 { bool(id_754 >= id_758) };
              while_flag_752 = id_759;
              if (while_flag_752) {
                uint8_t id_760 { 0 };
                uint8_t id_761 { 0 };
                uint32_t id_762 { lebsz_ref_417[id_761] };
                uint32_t id_763 { 1U };
                uint32_t id_764 { uint32_t(id_762 + id_763) };
                Void id_765 { ((void)(lebsz_ref_417[id_760] = id_764), VOID) };
                (void)id_765;
              }
            } while (while_flag_752);
            (void)VOID;
            uint8_t id_766 { 0 };
            uint32_t id_767 { lebsz_ref_417[id_766] };
            Size id_768 { Size(id_767) };
            let_res_751 = id_768;
          }
          let_res_748 = let_res_751;
        }
        Size id_769 { Size(sz_415 + let_res_748) };
        Vec<1, Size> id_770 {  id_769  };
        Size let_res_771;
        {
          Vec<1, Size> sz_ref_418 { id_770 };
          int32_t id_772 { 0L };
          Vec<1, int32_t> id_773 {  id_772  };
          {
            Vec<1, int32_t> repeat_n_419 { id_773 };
            bool while_flag_774 { true };
            do {
              std::optional<Lst<dessser::gen::field_name::t_ext>> id_775 { (*p_0).group_by };
              Lst<dessser::gen::field_name::t_ext> id_776 { id_775.value() };
              uint32_t id_777 { id_776.size() };
              int32_t id_778 { int32_t(id_777) };
              uint8_t id_779 { 0 };
              int32_t id_780 { repeat_n_419[id_779] };
              bool id_781 { bool(id_778 > id_780) };
              while_flag_774 = id_781;
              if (while_flag_774) {
                uint8_t id_782 { 0 };
                uint8_t id_783 { 0 };
                Size id_784 { sz_ref_418[id_783] };
                auto fun785 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_786 { 0 };
                int32_t id_787 { repeat_n_419[id_786] };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_788 { (*p_0).group_by };
                Lst<dessser::gen::field_name::t_ext> id_789 { id_788.value() };
                dessser::gen::field_name::t_ext id_790 { id_789[id_787] };
                Size id_791 { fun785(id_790) };
                Size id_792 { Size(id_784 + id_791) };
                Void id_793 { ((void)(sz_ref_418[id_782] = id_792), VOID) };
                (void)id_793;
                uint8_t id_794 { 0 };
                uint8_t id_795 { 0 };
                int32_t id_796 { repeat_n_419[id_795] };
                int32_t id_797 { 1L };
                int32_t id_798 { int32_t(id_796 + id_797) };
                Void id_799 { ((void)(repeat_n_419[id_794] = id_798), VOID) };
                (void)id_799;
                (void)id_799;
              }
            } while (while_flag_774);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_800 { 0 };
          Size id_801 { sz_ref_418[id_800] };
          let_res_771 = id_801;
        }
        Size id_802 { 1UL };
        Size id_803 { Size(let_res_771 + id_802) };
        choose_res_741 = id_803;
      }
      let_res_738 = choose_res_741;
    }
    Size let_res_804;
    {
      Size sz_420 { let_res_738 };
      Lst<dessser::gen::simple_filter::t_ext> id_805 { (*p_0).having };
      uint32_t id_806 { id_805.size() };
      Vec<1, uint32_t> id_807 {  id_806  };
      Size let_res_808;
      {
        Vec<1, uint32_t> n_ref_421 { id_807 };
        uint32_t id_809 { 1U };
        Vec<1, uint32_t> id_810 {  id_809  };
        Size let_res_811;
        {
          Vec<1, uint32_t> lebsz_ref_422 { id_810 };
          bool while_flag_812 { true };
          do {
            uint8_t id_813 { 0 };
            uint32_t id_814 { n_ref_421[id_813] };
            uint8_t id_815 { 0 };
            uint32_t id_816 { lebsz_ref_422[id_815] };
            uint8_t id_817 { 7 };
            uint32_t id_818 { uint32_t(id_816 << id_817) };
            bool id_819 { bool(id_814 >= id_818) };
            while_flag_812 = id_819;
            if (while_flag_812) {
              uint8_t id_820 { 0 };
              uint8_t id_821 { 0 };
              uint32_t id_822 { lebsz_ref_422[id_821] };
              uint32_t id_823 { 1U };
              uint32_t id_824 { uint32_t(id_822 + id_823) };
              Void id_825 { ((void)(lebsz_ref_422[id_820] = id_824), VOID) };
              (void)id_825;
            }
          } while (while_flag_812);
          (void)VOID;
          uint8_t id_826 { 0 };
          uint32_t id_827 { lebsz_ref_422[id_826] };
          Size id_828 { Size(id_827) };
          let_res_811 = id_828;
        }
        let_res_808 = let_res_811;
      }
      Size id_829 { Size(sz_420 + let_res_808) };
      Vec<1, Size> id_830 {  id_829  };
      Size let_res_831;
      {
        Vec<1, Size> sz_ref_423 { id_830 };
        int32_t id_832 { 0L };
        Vec<1, int32_t> id_833 {  id_832  };
        {
          Vec<1, int32_t> repeat_n_424 { id_833 };
          bool while_flag_834 { true };
          do {
            Lst<dessser::gen::simple_filter::t_ext> id_835 { (*p_0).having };
            uint32_t id_836 { id_835.size() };
            int32_t id_837 { int32_t(id_836) };
            uint8_t id_838 { 0 };
            int32_t id_839 { repeat_n_424[id_838] };
            bool id_840 { bool(id_837 > id_839) };
            while_flag_834 = id_840;
            if (while_flag_834) {
              uint8_t id_841 { 0 };
              uint8_t id_842 { 0 };
              Size id_843 { sz_ref_423[id_842] };
              auto fun844 { dessser::gen::simple_filter::sersize_of_row_binary };
              uint8_t id_845 { 0 };
              int32_t id_846 { repeat_n_424[id_845] };
              Lst<dessser::gen::simple_filter::t_ext> id_847 { (*p_0).having };
              dessser::gen::simple_filter::t_ext id_848 { id_847[id_846] };
              Size id_849 { fun844(id_848) };
              Size id_850 { Size(id_843 + id_849) };
              Void id_851 { ((void)(sz_ref_423[id_841] = id_850), VOID) };
              (void)id_851;
              uint8_t id_852 { 0 };
              uint8_t id_853 { 0 };
              int32_t id_854 { repeat_n_424[id_853] };
              int32_t id_855 { 1L };
              int32_t id_856 { int32_t(id_854 + id_855) };
              Void id_857 { ((void)(repeat_n_424[id_852] = id_856), VOID) };
              (void)id_857;
              (void)id_857;
            }
          } while (while_flag_834);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_858 { 0 };
        Size id_859 { sz_ref_423[id_858] };
        let_res_831 = id_859;
      }
      let_res_804 = let_res_831;
    }
    Size let_res_860;
    {
      Size sz_425 { let_res_804 };
      uint16_t id_861 { 0 };
      ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_862 { (*p_0).threshold };
      uint16_t id_863 { uint16_t(id_862.index()) };
      bool id_864 { bool(id_861 == id_863) };
      Size choose_res_865;
      if (id_864) {
        Size id_866 { 2UL };
        Size id_867 { Size(sz_425 + id_866) };
        Size id_868 { 8UL };
        Size id_869 { Size(id_867 + id_868) };
        choose_res_865 = id_869;
      } else {
        ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_870 { (*p_0).threshold };
        uint16_t id_871 { uint16_t(id_870.index()) };
        uint16_t id_872 { 1 };
        bool id_873 { bool(id_871 == id_872) };
        Void id_874 { ((void)(assert(id_873)), VOID) };
        (void)id_874;
        uint16_t id_875 { 0 };
        ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_876 { (*p_0).threshold };
        ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_877 { std::get<1 /* Baseline */>(id_876) };
        ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f id_878 { id_877.max_distance };
        uint16_t id_879 { uint16_t(id_878.index()) };
        bool id_880 { bool(id_875 == id_879) };
        Size choose_res_881;
        if (id_880) {
          Size id_882 { 2UL };
          Size id_883 { Size(sz_425 + id_882) };
          Size id_884 { 8UL };
          Size id_885 { Size(id_883 + id_884) };
          Size id_886 { 4UL };
          Size id_887 { Size(id_885 + id_886) };
          Size id_888 { 8UL };
          Size id_889 { Size(id_887 + id_888) };
          Size id_890 { 4UL };
          Size id_891 { Size(id_889 + id_890) };
          Size id_892 { 8UL };
          Size id_893 { Size(id_891 + id_892) };
          Size id_894 { 2UL };
          Size id_895 { Size(id_893 + id_894) };
          Size id_896 { 8UL };
          Size id_897 { Size(id_895 + id_896) };
          choose_res_881 = id_897;
        } else {
          ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_898 { (*p_0).threshold };
          ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_899 { std::get<1 /* Baseline */>(id_898) };
          ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f id_900 { id_899.max_distance };
          uint16_t id_901 { uint16_t(id_900.index()) };
          uint16_t id_902 { 1 };
          bool id_903 { bool(id_901 == id_902) };
          Void id_904 { ((void)(assert(id_903)), VOID) };
          (void)id_904;
          Size id_905 { 2UL };
          Size id_906 { Size(sz_425 + id_905) };
          Size id_907 { 8UL };
          Size id_908 { Size(id_906 + id_907) };
          Size id_909 { 4UL };
          Size id_910 { Size(id_908 + id_909) };
          Size id_911 { 8UL };
          Size id_912 { Size(id_910 + id_911) };
          Size id_913 { 4UL };
          Size id_914 { Size(id_912 + id_913) };
          Size id_915 { 8UL };
          Size id_916 { Size(id_914 + id_915) };
          Size id_917 { 2UL };
          Size id_918 { Size(id_916 + id_917) };
          Size id_919 { 8UL };
          Size id_920 { Size(id_918 + id_919) };
          choose_res_881 = id_920;
        }
        choose_res_865 = choose_res_881;
      }
      let_res_860 = choose_res_865;
    }
    Size id_921 { 8UL };
    Size id_922 { Size(let_res_860 + id_921) };
    Size id_923 { 8UL };
    Size id_924 { Size(id_922 + id_923) };
    Size id_925 { 8UL };
    Size id_926 { Size(id_924 + id_925) };
    Size id_927 { 8UL };
    Size id_928 { Size(id_926 + id_927) };
    Size let_res_929;
    {
      Size sz_438 { id_928 };
      Lst<dessser::gen::field_name::t_ext> id_930 { (*p_0).tops };
      uint32_t id_931 { id_930.size() };
      Vec<1, uint32_t> id_932 {  id_931  };
      Size let_res_933;
      {
        Vec<1, uint32_t> n_ref_439 { id_932 };
        uint32_t id_934 { 1U };
        Vec<1, uint32_t> id_935 {  id_934  };
        Size let_res_936;
        {
          Vec<1, uint32_t> lebsz_ref_440 { id_935 };
          bool while_flag_937 { true };
          do {
            uint8_t id_938 { 0 };
            uint32_t id_939 { n_ref_439[id_938] };
            uint8_t id_940 { 0 };
            uint32_t id_941 { lebsz_ref_440[id_940] };
            uint8_t id_942 { 7 };
            uint32_t id_943 { uint32_t(id_941 << id_942) };
            bool id_944 { bool(id_939 >= id_943) };
            while_flag_937 = id_944;
            if (while_flag_937) {
              uint8_t id_945 { 0 };
              uint8_t id_946 { 0 };
              uint32_t id_947 { lebsz_ref_440[id_946] };
              uint32_t id_948 { 1U };
              uint32_t id_949 { uint32_t(id_947 + id_948) };
              Void id_950 { ((void)(lebsz_ref_440[id_945] = id_949), VOID) };
              (void)id_950;
            }
          } while (while_flag_937);
          (void)VOID;
          uint8_t id_951 { 0 };
          uint32_t id_952 { lebsz_ref_440[id_951] };
          Size id_953 { Size(id_952) };
          let_res_936 = id_953;
        }
        let_res_933 = let_res_936;
      }
      Size id_954 { Size(sz_438 + let_res_933) };
      Vec<1, Size> id_955 {  id_954  };
      Size let_res_956;
      {
        Vec<1, Size> sz_ref_441 { id_955 };
        int32_t id_957 { 0L };
        Vec<1, int32_t> id_958 {  id_957  };
        {
          Vec<1, int32_t> repeat_n_442 { id_958 };
          bool while_flag_959 { true };
          do {
            Lst<dessser::gen::field_name::t_ext> id_960 { (*p_0).tops };
            uint32_t id_961 { id_960.size() };
            int32_t id_962 { int32_t(id_961) };
            uint8_t id_963 { 0 };
            int32_t id_964 { repeat_n_442[id_963] };
            bool id_965 { bool(id_962 > id_964) };
            while_flag_959 = id_965;
            if (while_flag_959) {
              uint8_t id_966 { 0 };
              uint8_t id_967 { 0 };
              Size id_968 { sz_ref_441[id_967] };
              auto fun969 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_970 { 0 };
              int32_t id_971 { repeat_n_442[id_970] };
              Lst<dessser::gen::field_name::t_ext> id_972 { (*p_0).tops };
              dessser::gen::field_name::t_ext id_973 { id_972[id_971] };
              Size id_974 { fun969(id_973) };
              Size id_975 { Size(id_968 + id_974) };
              Void id_976 { ((void)(sz_ref_441[id_966] = id_975), VOID) };
              (void)id_976;
              uint8_t id_977 { 0 };
              uint8_t id_978 { 0 };
              int32_t id_979 { repeat_n_442[id_978] };
              int32_t id_980 { 1L };
              int32_t id_981 { int32_t(id_979 + id_980) };
              Void id_982 { ((void)(repeat_n_442[id_977] = id_981), VOID) };
              (void)id_982;
              (void)id_982;
            }
          } while (while_flag_959);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_983 { 0 };
        Size id_984 { sz_ref_441[id_983] };
        let_res_956 = id_984;
      }
      let_res_929 = let_res_956;
    }
    Size let_res_985;
    {
      Size sz_443 { let_res_929 };
      Lst<dessser::gen::field_name::t_ext> id_986 { (*p_0).carry_fields };
      uint32_t id_987 { id_986.size() };
      Vec<1, uint32_t> id_988 {  id_987  };
      Size let_res_989;
      {
        Vec<1, uint32_t> n_ref_444 { id_988 };
        uint32_t id_990 { 1U };
        Vec<1, uint32_t> id_991 {  id_990  };
        Size let_res_992;
        {
          Vec<1, uint32_t> lebsz_ref_445 { id_991 };
          bool while_flag_993 { true };
          do {
            uint8_t id_994 { 0 };
            uint32_t id_995 { n_ref_444[id_994] };
            uint8_t id_996 { 0 };
            uint32_t id_997 { lebsz_ref_445[id_996] };
            uint8_t id_998 { 7 };
            uint32_t id_999 { uint32_t(id_997 << id_998) };
            bool id_1000 { bool(id_995 >= id_999) };
            while_flag_993 = id_1000;
            if (while_flag_993) {
              uint8_t id_1001 { 0 };
              uint8_t id_1002 { 0 };
              uint32_t id_1003 { lebsz_ref_445[id_1002] };
              uint32_t id_1004 { 1U };
              uint32_t id_1005 { uint32_t(id_1003 + id_1004) };
              Void id_1006 { ((void)(lebsz_ref_445[id_1001] = id_1005), VOID) };
              (void)id_1006;
            }
          } while (while_flag_993);
          (void)VOID;
          uint8_t id_1007 { 0 };
          uint32_t id_1008 { lebsz_ref_445[id_1007] };
          Size id_1009 { Size(id_1008) };
          let_res_992 = id_1009;
        }
        let_res_989 = let_res_992;
      }
      Size id_1010 { Size(sz_443 + let_res_989) };
      Vec<1, Size> id_1011 {  id_1010  };
      Size let_res_1012;
      {
        Vec<1, Size> sz_ref_446 { id_1011 };
        int32_t id_1013 { 0L };
        Vec<1, int32_t> id_1014 {  id_1013  };
        {
          Vec<1, int32_t> repeat_n_447 { id_1014 };
          bool while_flag_1015 { true };
          do {
            Lst<dessser::gen::field_name::t_ext> id_1016 { (*p_0).carry_fields };
            uint32_t id_1017 { id_1016.size() };
            int32_t id_1018 { int32_t(id_1017) };
            uint8_t id_1019 { 0 };
            int32_t id_1020 { repeat_n_447[id_1019] };
            bool id_1021 { bool(id_1018 > id_1020) };
            while_flag_1015 = id_1021;
            if (while_flag_1015) {
              uint8_t id_1022 { 0 };
              uint8_t id_1023 { 0 };
              Size id_1024 { sz_ref_446[id_1023] };
              auto fun1025 { dessser::gen::field_name::sersize_of_row_binary };
              uint8_t id_1026 { 0 };
              int32_t id_1027 { repeat_n_447[id_1026] };
              Lst<dessser::gen::field_name::t_ext> id_1028 { (*p_0).carry_fields };
              dessser::gen::field_name::t_ext id_1029 { id_1028[id_1027] };
              Size id_1030 { fun1025(id_1029) };
              Size id_1031 { Size(id_1024 + id_1030) };
              Void id_1032 { ((void)(sz_ref_446[id_1022] = id_1031), VOID) };
              (void)id_1032;
              uint8_t id_1033 { 0 };
              uint8_t id_1034 { 0 };
              int32_t id_1035 { repeat_n_447[id_1034] };
              int32_t id_1036 { 1L };
              int32_t id_1037 { int32_t(id_1035 + id_1036) };
              Void id_1038 { ((void)(repeat_n_447[id_1033] = id_1037), VOID) };
              (void)id_1038;
              (void)id_1038;
            }
          } while (while_flag_1015);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_1039 { 0 };
        Size id_1040 { sz_ref_446[id_1039] };
        let_res_1012 = id_1040;
      }
      let_res_985 = let_res_1012;
    }
    Size let_res_1041;
    {
      Size sz_448 { let_res_985 };
      Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> id_1042 { (*p_0).carry_csts };
      uint32_t id_1043 { id_1042.size() };
      Vec<1, uint32_t> id_1044 {  id_1043  };
      Size let_res_1045;
      {
        Vec<1, uint32_t> n_ref_449 { id_1044 };
        uint32_t id_1046 { 1U };
        Vec<1, uint32_t> id_1047 {  id_1046  };
        Size let_res_1048;
        {
          Vec<1, uint32_t> lebsz_ref_450 { id_1047 };
          bool while_flag_1049 { true };
          do {
            uint8_t id_1050 { 0 };
            uint32_t id_1051 { n_ref_449[id_1050] };
            uint8_t id_1052 { 0 };
            uint32_t id_1053 { lebsz_ref_450[id_1052] };
            uint8_t id_1054 { 7 };
            uint32_t id_1055 { uint32_t(id_1053 << id_1054) };
            bool id_1056 { bool(id_1051 >= id_1055) };
            while_flag_1049 = id_1056;
            if (while_flag_1049) {
              uint8_t id_1057 { 0 };
              uint8_t id_1058 { 0 };
              uint32_t id_1059 { lebsz_ref_450[id_1058] };
              uint32_t id_1060 { 1U };
              uint32_t id_1061 { uint32_t(id_1059 + id_1060) };
              Void id_1062 { ((void)(lebsz_ref_450[id_1057] = id_1061), VOID) };
              (void)id_1062;
            }
          } while (while_flag_1049);
          (void)VOID;
          uint8_t id_1063 { 0 };
          uint32_t id_1064 { lebsz_ref_450[id_1063] };
          Size id_1065 { Size(id_1064) };
          let_res_1048 = id_1065;
        }
        let_res_1045 = let_res_1048;
      }
      Size id_1066 { Size(sz_448 + let_res_1045) };
      Vec<1, Size> id_1067 {  id_1066  };
      Size let_res_1068;
      {
        Vec<1, Size> sz_ref_451 { id_1067 };
        int32_t id_1069 { 0L };
        Vec<1, int32_t> id_1070 {  id_1069  };
        {
          Vec<1, int32_t> repeat_n_452 { id_1070 };
          bool while_flag_1071 { true };
          do {
            Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> id_1072 { (*p_0).carry_csts };
            uint32_t id_1073 { id_1072.size() };
            int32_t id_1074 { int32_t(id_1073) };
            uint8_t id_1075 { 0 };
            int32_t id_1076 { repeat_n_452[id_1075] };
            bool id_1077 { bool(id_1074 > id_1076) };
            while_flag_1071 = id_1077;
            if (while_flag_1071) {
              uint8_t id_1078 { 0 };
              uint8_t id_1079 { 0 };
              Size id_1080 { sz_ref_451[id_1079] };
              Size let_res_1081;
              {
                Size sz_453 { id_1080 };
                auto fun1082 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_1083 { 0 };
                int32_t id_1084 { repeat_n_452[id_1083] };
                Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> id_1085 { (*p_0).carry_csts };
                ::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d id_1086 { id_1085[id_1084] };
                dessser::gen::field_name::t_ext id_1087 { std::get<0>(id_1086) };
                Size id_1088 { fun1082(id_1087) };
                Size id_1089 { Size(sz_453 + id_1088) };
                let_res_1081 = id_1089;
              }
              Size let_res_1090;
              {
                Size sz_454 { let_res_1081 };
                uint8_t id_1091 { 0 };
                int32_t id_1092 { repeat_n_452[id_1091] };
                Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> id_1093 { (*p_0).carry_csts };
                ::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d id_1094 { id_1093[id_1092] };
                std::string id_1095 { std::get<1>(id_1094) };
                uint32_t id_1096 { (uint32_t)id_1095.size() };
                Size let_res_1097;
                {
                  uint32_t wlen_455 { id_1096 };
                  Vec<1, uint32_t> id_1098 {  wlen_455  };
                  Size let_res_1099;
                  {
                    Vec<1, uint32_t> n_ref_456 { id_1098 };
                    uint32_t id_1100 { 1U };
                    Vec<1, uint32_t> id_1101 {  id_1100  };
                    Size let_res_1102;
                    {
                      Vec<1, uint32_t> lebsz_ref_457 { id_1101 };
                      bool while_flag_1103 { true };
                      do {
                        uint8_t id_1104 { 0 };
                        uint32_t id_1105 { n_ref_456[id_1104] };
                        uint8_t id_1106 { 0 };
                        uint32_t id_1107 { lebsz_ref_457[id_1106] };
                        uint8_t id_1108 { 7 };
                        uint32_t id_1109 { uint32_t(id_1107 << id_1108) };
                        bool id_1110 { bool(id_1105 >= id_1109) };
                        while_flag_1103 = id_1110;
                        if (while_flag_1103) {
                          uint8_t id_1111 { 0 };
                          uint8_t id_1112 { 0 };
                          uint32_t id_1113 { lebsz_ref_457[id_1112] };
                          uint32_t id_1114 { 1U };
                          uint32_t id_1115 { uint32_t(id_1113 + id_1114) };
                          Void id_1116 { ((void)(lebsz_ref_457[id_1111] = id_1115), VOID) };
                          (void)id_1116;
                        }
                      } while (while_flag_1103);
                      (void)VOID;
                      uint8_t id_1117 { 0 };
                      uint32_t id_1118 { lebsz_ref_457[id_1117] };
                      Size id_1119 { Size(id_1118) };
                      let_res_1102 = id_1119;
                    }
                    let_res_1099 = let_res_1102;
                  }
                  Size id_1120 { Size(wlen_455) };
                  Size id_1121 { Size(let_res_1099 + id_1120) };
                  let_res_1097 = id_1121;
                }
                Size id_1122 { Size(sz_454 + let_res_1097) };
                let_res_1090 = id_1122;
              }
              Void id_1123 { ((void)(sz_ref_451[id_1078] = let_res_1090), VOID) };
              (void)id_1123;
              uint8_t id_1124 { 0 };
              uint8_t id_1125 { 0 };
              int32_t id_1126 { repeat_n_452[id_1125] };
              int32_t id_1127 { 1L };
              int32_t id_1128 { int32_t(id_1126 + id_1127) };
              Void id_1129 { ((void)(repeat_n_452[id_1124] = id_1128), VOID) };
              (void)id_1129;
              (void)id_1129;
            }
          } while (while_flag_1071);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_1130 { 0 };
        Size id_1131 { sz_ref_451[id_1130] };
        let_res_1068 = id_1131;
      }
      let_res_1041 = let_res_1068;
    }
    Size let_res_1132;
    {
      Size sz_458 { let_res_1041 };
      std::string id_1133 { (*p_0).id };
      uint32_t id_1134 { (uint32_t)id_1133.size() };
      Vec<1, uint32_t> id_1135 {  id_1134  };
      Size let_res_1136;
      {
        Vec<1, uint32_t> n_ref_460 { id_1135 };
        uint32_t id_1137 { 1U };
        Vec<1, uint32_t> id_1138 {  id_1137  };
        Size let_res_1139;
        {
          Vec<1, uint32_t> lebsz_ref_461 { id_1138 };
          bool while_flag_1140 { true };
          do {
            uint8_t id_1141 { 0 };
            uint32_t id_1142 { n_ref_460[id_1141] };
            uint8_t id_1143 { 0 };
            uint32_t id_1144 { lebsz_ref_461[id_1143] };
            uint8_t id_1145 { 7 };
            uint32_t id_1146 { uint32_t(id_1144 << id_1145) };
            bool id_1147 { bool(id_1142 >= id_1146) };
            while_flag_1140 = id_1147;
            if (while_flag_1140) {
              uint8_t id_1148 { 0 };
              uint8_t id_1149 { 0 };
              uint32_t id_1150 { lebsz_ref_461[id_1149] };
              uint32_t id_1151 { 1U };
              uint32_t id_1152 { uint32_t(id_1150 + id_1151) };
              Void id_1153 { ((void)(lebsz_ref_461[id_1148] = id_1152), VOID) };
              (void)id_1153;
            }
          } while (while_flag_1140);
          (void)VOID;
          uint8_t id_1154 { 0 };
          uint32_t id_1155 { lebsz_ref_461[id_1154] };
          Size id_1156 { Size(id_1155) };
          let_res_1139 = id_1156;
        }
        let_res_1136 = let_res_1139;
      }
      std::string id_1157 { (*p_0).id };
      uint32_t id_1158 { (uint32_t)id_1157.size() };
      Size id_1159 { Size(id_1158) };
      Size id_1160 { Size(let_res_1136 + id_1159) };
      Size id_1161 { Size(sz_458 + id_1160) };
      let_res_1132 = id_1161;
    }
    Size let_res_1162;
    {
      Size sz_462 { let_res_1132 };
      std::string id_1163 { (*p_0).desc_title };
      uint32_t id_1164 { (uint32_t)id_1163.size() };
      Vec<1, uint32_t> id_1165 {  id_1164  };
      Size let_res_1166;
      {
        Vec<1, uint32_t> n_ref_464 { id_1165 };
        uint32_t id_1167 { 1U };
        Vec<1, uint32_t> id_1168 {  id_1167  };
        Size let_res_1169;
        {
          Vec<1, uint32_t> lebsz_ref_465 { id_1168 };
          bool while_flag_1170 { true };
          do {
            uint8_t id_1171 { 0 };
            uint32_t id_1172 { n_ref_464[id_1171] };
            uint8_t id_1173 { 0 };
            uint32_t id_1174 { lebsz_ref_465[id_1173] };
            uint8_t id_1175 { 7 };
            uint32_t id_1176 { uint32_t(id_1174 << id_1175) };
            bool id_1177 { bool(id_1172 >= id_1176) };
            while_flag_1170 = id_1177;
            if (while_flag_1170) {
              uint8_t id_1178 { 0 };
              uint8_t id_1179 { 0 };
              uint32_t id_1180 { lebsz_ref_465[id_1179] };
              uint32_t id_1181 { 1U };
              uint32_t id_1182 { uint32_t(id_1180 + id_1181) };
              Void id_1183 { ((void)(lebsz_ref_465[id_1178] = id_1182), VOID) };
              (void)id_1183;
            }
          } while (while_flag_1170);
          (void)VOID;
          uint8_t id_1184 { 0 };
          uint32_t id_1185 { lebsz_ref_465[id_1184] };
          Size id_1186 { Size(id_1185) };
          let_res_1169 = id_1186;
        }
        let_res_1166 = let_res_1169;
      }
      std::string id_1187 { (*p_0).desc_title };
      uint32_t id_1188 { (uint32_t)id_1187.size() };
      Size id_1189 { Size(id_1188) };
      Size id_1190 { Size(let_res_1166 + id_1189) };
      Size id_1191 { Size(sz_462 + id_1190) };
      let_res_1162 = id_1191;
    }
    Size let_res_1192;
    {
      Size sz_466 { let_res_1162 };
      std::string id_1193 { (*p_0).desc_firing };
      uint32_t id_1194 { (uint32_t)id_1193.size() };
      Vec<1, uint32_t> id_1195 {  id_1194  };
      Size let_res_1196;
      {
        Vec<1, uint32_t> n_ref_468 { id_1195 };
        uint32_t id_1197 { 1U };
        Vec<1, uint32_t> id_1198 {  id_1197  };
        Size let_res_1199;
        {
          Vec<1, uint32_t> lebsz_ref_469 { id_1198 };
          bool while_flag_1200 { true };
          do {
            uint8_t id_1201 { 0 };
            uint32_t id_1202 { n_ref_468[id_1201] };
            uint8_t id_1203 { 0 };
            uint32_t id_1204 { lebsz_ref_469[id_1203] };
            uint8_t id_1205 { 7 };
            uint32_t id_1206 { uint32_t(id_1204 << id_1205) };
            bool id_1207 { bool(id_1202 >= id_1206) };
            while_flag_1200 = id_1207;
            if (while_flag_1200) {
              uint8_t id_1208 { 0 };
              uint8_t id_1209 { 0 };
              uint32_t id_1210 { lebsz_ref_469[id_1209] };
              uint32_t id_1211 { 1U };
              uint32_t id_1212 { uint32_t(id_1210 + id_1211) };
              Void id_1213 { ((void)(lebsz_ref_469[id_1208] = id_1212), VOID) };
              (void)id_1213;
            }
          } while (while_flag_1200);
          (void)VOID;
          uint8_t id_1214 { 0 };
          uint32_t id_1215 { lebsz_ref_469[id_1214] };
          Size id_1216 { Size(id_1215) };
          let_res_1199 = id_1216;
        }
        let_res_1196 = let_res_1199;
      }
      std::string id_1217 { (*p_0).desc_firing };
      uint32_t id_1218 { (uint32_t)id_1217.size() };
      Size id_1219 { Size(id_1218) };
      Size id_1220 { Size(let_res_1196 + id_1219) };
      Size id_1221 { Size(sz_466 + id_1220) };
      let_res_1192 = id_1221;
    }
    Size let_res_1222;
    {
      Size sz_470 { let_res_1192 };
      std::string id_1223 { (*p_0).desc_recovery };
      uint32_t id_1224 { (uint32_t)id_1223.size() };
      Vec<1, uint32_t> id_1225 {  id_1224  };
      Size let_res_1226;
      {
        Vec<1, uint32_t> n_ref_472 { id_1225 };
        uint32_t id_1227 { 1U };
        Vec<1, uint32_t> id_1228 {  id_1227  };
        Size let_res_1229;
        {
          Vec<1, uint32_t> lebsz_ref_473 { id_1228 };
          bool while_flag_1230 { true };
          do {
            uint8_t id_1231 { 0 };
            uint32_t id_1232 { n_ref_472[id_1231] };
            uint8_t id_1233 { 0 };
            uint32_t id_1234 { lebsz_ref_473[id_1233] };
            uint8_t id_1235 { 7 };
            uint32_t id_1236 { uint32_t(id_1234 << id_1235) };
            bool id_1237 { bool(id_1232 >= id_1236) };
            while_flag_1230 = id_1237;
            if (while_flag_1230) {
              uint8_t id_1238 { 0 };
              uint8_t id_1239 { 0 };
              uint32_t id_1240 { lebsz_ref_473[id_1239] };
              uint32_t id_1241 { 1U };
              uint32_t id_1242 { uint32_t(id_1240 + id_1241) };
              Void id_1243 { ((void)(lebsz_ref_473[id_1238] = id_1242), VOID) };
              (void)id_1243;
            }
          } while (while_flag_1230);
          (void)VOID;
          uint8_t id_1244 { 0 };
          uint32_t id_1245 { lebsz_ref_473[id_1244] };
          Size id_1246 { Size(id_1245) };
          let_res_1229 = id_1246;
        }
        let_res_1226 = let_res_1229;
      }
      std::string id_1247 { (*p_0).desc_recovery };
      uint32_t id_1248 { (uint32_t)id_1247.size() };
      Size id_1249 { Size(id_1248) };
      Size id_1250 { Size(let_res_1226 + id_1249) };
      Size id_1251 { Size(sz_470 + id_1250) };
      let_res_1222 = id_1251;
    }
    return let_res_1222;
  }
   };
  return fun671;
}
std::function<Size(::dessser::gen::alert::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier fq_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_59" (apply (ext-identifier field_name of-row-binary) (identifier "drec_snd_58"))
            (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
              (let "drec_65" (let-pair "dbool_fst_63" "dbool_snd_64" (read-u8 (identifier "drec_snd_61")) (make-tup (not (eq (identifier "dbool_fst_63") (u8 0))) (identifier "dbool_snd_64")))
                (let-pair "drec_fst_66" "drec_snd_67" (identifier "drec_65")
                  (let "drec_91"
                    (let-pair "dlist4_fst_89" "dlist4_snd_90"
                      (let "dlist1_77"
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
                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_68")) (unsafe-nth (u8 0) (identifier "p_ref_70")))))))
                        (let-pair "dlist1_fst_78" "dlist1_snd_79" (identifier "dlist1_77")
                          (let "inits_src_ref_80" (make-vec (make-tup (end-of-list "$simple_filter") (identifier "dlist1_snd_79")))
                            (seq
                              (let "repeat_n_81" (make-vec (i32 0))
                                (while (gt (to-i32 (identifier "dlist1_fst_78")) (unsafe-nth (u8 0) (identifier "repeat_n_81")))
                                  (seq
                                    (let "dlist2_82" (unsafe-nth (u8 0) (identifier "inits_src_ref_80"))
                                      (let-pair "dlist2_fst_83" "dlist2_snd_84" 
                                        (identifier "dlist2_82")
                                        (set-vec (u8 0) (identifier "inits_src_ref_80")
                                          (let-pair "dlist3_fst_86" "dlist3_snd_87" 
                                            (apply (ext-identifier simple_filter of-row-binary) (identifier "dlist2_snd_84"))
                                            (make-tup (cons (identifier "dlist3_fst_86") (identifier "dlist2_fst_83")) (identifier "dlist3_snd_87"))))))
                                    (set-vec (u8 0) (identifier "repeat_n_81") (add (unsafe-nth (u8 0) (identifier "repeat_n_81")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "inits_src_ref_80")))))) 
                      (make-tup (identity (identifier "dlist4_fst_89")) (identifier "dlist4_snd_90")))
                    (let-pair "drec_fst_92" "drec_snd_93" (identifier "drec_91")
                      (let "drec_120"
                        (if (eq (peek-u8 (identifier "drec_snd_93") (size 0)) (u8 1)) 
                          (make-tup (null "$field_name[[]]") (ptr-add (identifier "drec_snd_93") (size 1)))
                          (let-pair "dlist4_fst_115" "dlist4_snd_116"
                            (let "dlist1_103"
                              (let "leb_ref_94" (make-vec (u32 0))
                                (let "shft_ref_95" (make-vec (u8 0))
                                  (let "p_ref_96" (make-vec (ptr-add (identifier "drec_snd_93") (size 1)))
                                    (seq
                                      (while
                                        (let "leb128_97" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_96")))
                                          (let-pair "leb128_fst_98" "leb128_snd_99" 
                                            (identifier "leb128_97")
                                            (seq (set-vec (u8 0) (identifier "p_ref_96") (identifier "leb128_snd_99"))
                                              (set-vec (u8 0) (identifier "leb_ref_94")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_98") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_95"))) (unsafe-nth (u8 0) (identifier "leb_ref_94"))))
                                              (set-vec (u8 0) (identifier "shft_ref_95") (add (unsafe-nth (u8 0) (identifier "shft_ref_95")) (u8 7))) 
                                              (ge (identifier "leb128_fst_98") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_94")) (unsafe-nth (u8 0) (identifier "p_ref_96")))))))
                              (let-pair "dlist1_fst_104" "dlist1_snd_105" 
                                (identifier "dlist1_103")
                                (let "inits_src_ref_106" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_105")))
                                  (seq
                                    (let "repeat_n_107" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_104")) (unsafe-nth (u8 0) (identifier "repeat_n_107")))
                                        (seq
                                          (let "dlist2_108" (unsafe-nth (u8 0) (identifier "inits_src_ref_106"))
                                            (let-pair "dlist2_fst_109" "dlist2_snd_110" 
                                              (identifier "dlist2_108")
                                              (set-vec (u8 0) (identifier "inits_src_ref_106")
                                                (let-pair "dlist3_fst_112" "dlist3_snd_113" 
                                                  (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_110"))
                                                  (make-tup (cons (identifier "dlist3_fst_112") (identifier "dlist2_fst_109")) (identifier "dlist3_snd_113"))))))
                                          (set-vec (u8 0) (identifier "repeat_n_107") (add (unsafe-nth (u8 0) (identifier "repeat_n_107")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_106")))))) 
                            (make-tup (not-null (identity (identifier "dlist4_fst_115"))) (identifier "dlist4_snd_116"))))
                        (let-pair "drec_fst_121" "drec_snd_122" (identifier "drec_120")
                          (let "drec_146"
                            (let-pair "dlist4_fst_144" "dlist4_snd_145"
                              (let "dlist1_132"
                                (let "leb_ref_123" (make-vec (u32 0))
                                  (let "shft_ref_124" (make-vec (u8 0))
                                    (let "p_ref_125" (make-vec (identifier "drec_snd_122"))
                                      (seq
                                        (while
                                          (let "leb128_126" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_125")))
                                            (let-pair "leb128_fst_127" "leb128_snd_128" 
                                              (identifier "leb128_126")
                                              (seq (set-vec (u8 0) (identifier "p_ref_125") (identifier "leb128_snd_128"))
                                                (set-vec (u8 0) (identifier "leb_ref_123")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_127") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_124"))) (unsafe-nth (u8 0) (identifier "leb_ref_123"))))
                                                (set-vec (u8 0) (identifier "shft_ref_124") (add (unsafe-nth (u8 0) (identifier "shft_ref_124")) (u8 7))) 
                                                (ge (identifier "leb128_fst_127") (u8 128))))) 
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_123")) (unsafe-nth (u8 0) (identifier "p_ref_125")))))))
                                (let-pair "dlist1_fst_133" "dlist1_snd_134" 
                                  (identifier "dlist1_132")
                                  (let "inits_src_ref_135" (make-vec (make-tup (end-of-list "$simple_filter") (identifier "dlist1_snd_134")))
                                    (seq
                                      (let "repeat_n_136" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_133")) (unsafe-nth (u8 0) (identifier "repeat_n_136")))
                                          (seq
                                            (let "dlist2_137" (unsafe-nth (u8 0) (identifier "inits_src_ref_135"))
                                              (let-pair "dlist2_fst_138" "dlist2_snd_139" 
                                                (identifier "dlist2_137")
                                                (set-vec (u8 0) (identifier "inits_src_ref_135")
                                                  (let-pair "dlist3_fst_141" "dlist3_snd_142" 
                                                    (apply (ext-identifier simple_filter of-row-binary) (identifier "dlist2_snd_139"))
                                                    (make-tup (cons (identifier "dlist3_fst_141") (identifier "dlist2_fst_138")) (identifier "dlist3_snd_142"))))))
                                            (set-vec (u8 0) (identifier "repeat_n_136") (add (unsafe-nth (u8 0) (identifier "repeat_n_136")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_135")))))) 
                              (make-tup (identity (identifier "dlist4_fst_144")) (identifier "dlist4_snd_145")))
                            (let-pair "drec_fst_147" "drec_snd_148" (identifier "drec_146")
                              (let "drec_221"
                                (let "dsum1_155" (let-pair "du16_fst_150" "du16_snd_151" (read-u16 little-endian (identifier "drec_snd_148")) (make-tup (identifier "du16_fst_150") (identifier "du16_snd_151")))
                                  (let-pair "dsum1_fst_156" "dsum1_snd_157" 
                                    (identifier "dsum1_155")
                                    (if (eq (u16 0) (identifier "dsum1_fst_156"))
                                      (let-pair "dfloat_fst_216" "dfloat_snd_217" 
                                        (read-u64 little-endian (identifier "dsum1_snd_157"))
                                        (make-tup
                                          (construct "[Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]" 0
                                            (float-of-u64 (identifier "dfloat_fst_216"))) 
                                          (identifier "dfloat_snd_217")))
                                      (seq (assert (eq (identifier "dsum1_fst_156") (u16 1)))
                                        (let "drec_161"
                                          (let-pair "dfloat_fst_159" "dfloat_snd_160" (read-u64 little-endian (identifier "dsum1_snd_157")) (make-tup (float-of-u64 (identifier "dfloat_fst_159")) (identifier "dfloat_snd_160")))
                                          (let-pair "drec_fst_162" "drec_snd_163" 
                                            (identifier "drec_161")
                                            (let "drec_167" (let-pair "du32_fst_165" "du32_snd_166" (read-u32 little-endian (identifier "drec_snd_163")) (make-tup (identifier "du32_fst_165") (identifier "du32_snd_166")))
                                              (let-pair "drec_fst_168" "drec_snd_169" 
                                                (identifier "drec_167")
                                                (let "drec_173"
                                                  (let-pair "dfloat_fst_171" "dfloat_snd_172" 
                                                    (read-u64 little-endian (identifier "drec_snd_169")) 
                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_171")) (identifier "dfloat_snd_172")))
                                                  (let-pair "drec_fst_174" "drec_snd_175" 
                                                    (identifier "drec_173")
                                                    (let "drec_179" (let-pair "du32_fst_177" "du32_snd_178" (read-u32 little-endian (identifier "drec_snd_175")) (make-tup (identifier "du32_fst_177") (identifier "du32_snd_178")))
                                                      (let-pair "drec_fst_180" "drec_snd_181" 
                                                        (identifier "drec_179")
                                                        (let "drec_185"
                                                          (let-pair "dfloat_fst_183" "dfloat_snd_184" 
                                                            (read-u64 little-endian (identifier "drec_snd_181")) 
                                                            (make-tup (float-of-u64 (identifier "dfloat_fst_183")) (identifier "dfloat_snd_184")))
                                                          (let-pair "drec_fst_186" "drec_snd_187" 
                                                            (identifier "drec_185")
                                                            (let-pair "drec_fst_210" "drec_snd_211"
                                                              (let "dsum1_194"
                                                                (let-pair "du16_fst_189" "du16_snd_190" (read-u16 little-endian (identifier "drec_snd_187")) (make-tup (identifier "du16_fst_189") (identifier "du16_snd_190")))
                                                                (let-pair "dsum1_fst_195" "dsum1_snd_196" 
                                                                  (identifier "dsum1_194")
                                                                  (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_195"))
                                                                    (let-pair "dfloat_fst_204" "dfloat_snd_205" 
                                                                    (read-u64 little-endian (identifier "dsum1_snd_196"))
                                                                    (make-tup (construct "[Absolute FLOAT | Relative FLOAT]" 0 (float-of-u64 (identifier "dfloat_fst_204"))) (identifier "dfloat_snd_205")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_195") (u16 1)))
                                                                    (let-pair "dfloat_fst_198" "dfloat_snd_199" 
                                                                    (read-u64 little-endian (identifier "dsum1_snd_196"))
                                                                    (make-tup (construct "[Absolute FLOAT | Relative FLOAT]" 1 (float-of-u64 (identifier "dfloat_fst_198"))) (identifier "dfloat_snd_199")))))))
                                                              (make-tup
                                                                (construct "[Constant FLOAT | Baseline {avg_window: FLOAT; sample_size: U32; percentile: FLOAT; seasonality: U32; smooth_factor: FLOAT; max_distance: [Absolute FLOAT | Relative FLOAT]}]" 1
                                                                  (make-rec 
                                                                    (string "max_distance") 
                                                                    (identifier "drec_fst_210") 
                                                                    (string "smooth_factor") 
                                                                    (identifier "drec_fst_186") 
                                                                    (string "seasonality") 
                                                                    (identifier "drec_fst_180") 
                                                                    (string "percentile") 
                                                                    (identifier "drec_fst_174") 
                                                                    (string "sample_size") 
                                                                    (identifier "drec_fst_168") 
                                                                    (string "avg_window") 
                                                                    (identifier "drec_fst_162"))) 
                                                                (identifier "drec_snd_211")))))))))))))))))
                                (let-pair "drec_fst_222" "drec_snd_223" 
                                  (identifier "drec_221")
                                  (let "drec_227"
                                    (let-pair "dfloat_fst_225" "dfloat_snd_226" (read-u64 little-endian (identifier "drec_snd_223")) (make-tup (float-of-u64 (identifier "dfloat_fst_225")) (identifier "dfloat_snd_226")))
                                    (let-pair "drec_fst_228" "drec_snd_229" 
                                      (identifier "drec_227")
                                      (let "drec_233"
                                        (let-pair "dfloat_fst_231" "dfloat_snd_232" (read-u64 little-endian (identifier "drec_snd_229")) (make-tup (float-of-u64 (identifier "dfloat_fst_231")) (identifier "dfloat_snd_232")))
                                        (let-pair "drec_fst_234" "drec_snd_235" 
                                          (identifier "drec_233")
                                          (let "drec_239"
                                            (let-pair "dfloat_fst_237" "dfloat_snd_238" (read-u64 little-endian (identifier "drec_snd_235")) (make-tup (float-of-u64 (identifier "dfloat_fst_237")) (identifier "dfloat_snd_238")))
                                            (let-pair "drec_fst_240" "drec_snd_241" 
                                              (identifier "drec_239")
                                              (let "drec_245"
                                                (let-pair "dfloat_fst_243" "dfloat_snd_244" 
                                                  (read-u64 little-endian (identifier "drec_snd_241")) 
                                                  (make-tup (float-of-u64 (identifier "dfloat_fst_243")) (identifier "dfloat_snd_244")))
                                                (let-pair "drec_fst_246" "drec_snd_247" 
                                                  (identifier "drec_245")
                                                  (let "drec_271"
                                                    (let-pair "dlist4_fst_269" "dlist4_snd_270"
                                                      (let "dlist1_257"
                                                        (let "leb_ref_248" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_249" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_250" 
                                                              (make-vec (identifier "drec_snd_247"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_251" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_250")))
                                                                    (let-pair "leb128_fst_252" "leb128_snd_253" 
                                                                    (identifier "leb128_251")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_250") (identifier "leb128_snd_253"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_248")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_252") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_249")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_248")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_249") (add (unsafe-nth (u8 0) (identifier "shft_ref_249")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_252") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_248")) (unsafe-nth (u8 0) (identifier "p_ref_250")))))))
                                                        (let-pair "dlist1_fst_258" "dlist1_snd_259" 
                                                          (identifier "dlist1_257")
                                                          (let "inits_src_ref_260" 
                                                            (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_259")))
                                                            (seq
                                                              (let "repeat_n_261" 
                                                                (make-vec (i32 0))
                                                                (while 
                                                                  (gt (to-i32 (identifier "dlist1_fst_258")) (unsafe-nth (u8 0) (identifier "repeat_n_261")))
                                                                  (seq
                                                                    (let "dlist2_262" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_260"))
                                                                    (let-pair "dlist2_fst_263" "dlist2_snd_264" 
                                                                    (identifier "dlist2_262")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_260")
                                                                    (let-pair "dlist3_fst_266" "dlist3_snd_267" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_264"))
                                                                    (make-tup (cons (identifier "dlist3_fst_266") (identifier "dlist2_fst_263")) (identifier "dlist3_snd_267"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_261") (add (unsafe-nth (u8 0) (identifier "repeat_n_261")) (i32 1))))))
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_260")))))) 
                                                      (make-tup (identity (identifier "dlist4_fst_269")) (identifier "dlist4_snd_270")))
                                                    (let-pair "drec_fst_272" "drec_snd_273" 
                                                      (identifier "drec_271")
                                                      (let "drec_297"
                                                        (let-pair "dlist4_fst_295" "dlist4_snd_296"
                                                          (let "dlist1_283"
                                                            (let "leb_ref_274" 
                                                              (make-vec (u32 0))
                                                              (let "shft_ref_275" 
                                                                (make-vec (u8 0))
                                                                (let "p_ref_276" 
                                                                  (make-vec (identifier "drec_snd_273"))
                                                                  (seq
                                                                    (while
                                                                    (let "leb128_277" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_276")))
                                                                    (let-pair "leb128_fst_278" "leb128_snd_279" 
                                                                    (identifier "leb128_277")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_276") (identifier "leb128_snd_279"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_274")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_278") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_275")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_274")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_275") (add (unsafe-nth (u8 0) (identifier "shft_ref_275")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_278") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_274")) (unsafe-nth (u8 0) (identifier "p_ref_276")))))))
                                                            (let-pair "dlist1_fst_284" "dlist1_snd_285" 
                                                              (identifier "dlist1_283")
                                                              (let "inits_src_ref_286" 
                                                                (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_285")))
                                                                (seq
                                                                  (let "repeat_n_287" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_284")) (unsafe-nth (u8 0) (identifier "repeat_n_287")))
                                                                    (seq
                                                                    (let "dlist2_288" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_286"))
                                                                    (let-pair "dlist2_fst_289" "dlist2_snd_290" 
                                                                    (identifier "dlist2_288")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_286")
                                                                    (let-pair "dlist3_fst_292" "dlist3_snd_293" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_290"))
                                                                    (make-tup (cons (identifier "dlist3_fst_292") (identifier "dlist2_fst_289")) (identifier "dlist3_snd_293"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_287") (add (unsafe-nth (u8 0) (identifier "repeat_n_287")) (i32 1))))))
                                                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_286")))))) 
                                                          (make-tup (identity (identifier "dlist4_fst_295")) (identifier "dlist4_snd_296")))
                                                        (let-pair "drec_fst_298" "drec_snd_299" 
                                                          (identifier "drec_297")
                                                          (let "drec_341"
                                                            (let-pair "dlist4_fst_339" "dlist4_snd_340"
                                                              (let "dlist1_309"
                                                                (let "leb_ref_300" 
                                                                  (make-vec (u32 0))
                                                                  (let "shft_ref_301" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_302" 
                                                                    (make-vec (identifier "drec_snd_299"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_303" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_302")))
                                                                    (let-pair "leb128_fst_304" "leb128_snd_305" 
                                                                    (identifier "leb128_303")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_302") (identifier "leb128_snd_305"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_300")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_304") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_301")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_300")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_301") (add (unsafe-nth (u8 0) (identifier "shft_ref_301")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_304") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_300")) (unsafe-nth (u8 0) (identifier "p_ref_302")))))))
                                                                (let-pair "dlist1_fst_310" "dlist1_snd_311" 
                                                                  (identifier "dlist1_309")
                                                                  (let "inits_src_ref_312" 
                                                                    (make-vec (make-tup (end-of-list "($field_name; STRING)") (identifier "dlist1_snd_311")))
                                                                    (seq
                                                                    (let "repeat_n_313" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_310")) (unsafe-nth (u8 0) (identifier "repeat_n_313")))
                                                                    (seq
                                                                    (let "dlist2_314" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_312"))
                                                                    (let-pair "dlist2_fst_315" "dlist2_snd_316" 
                                                                    (identifier "dlist2_314")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_312")
                                                                    (let "dtup_317" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_316"))
                                                                    (let-pair "dtup_fst_318" "dtup_snd_319" 
                                                                    (identifier "dtup_317")
                                                                    (let "dstring1_326"
                                                                    (let "leb_ref_320" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_321" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_322" 
                                                                    (make-vec (identifier "dtup_snd_319"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_323" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_322")))
                                                                    (let-pair "leb128_fst_324" "leb128_snd_325" 
                                                                    (identifier "leb128_323")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_322") (identifier "leb128_snd_325"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_320")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_324") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_321")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_320")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_321") (add (unsafe-nth (u8 0) (identifier "shft_ref_321")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_324") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_320"))) (unsafe-nth (u8 0) (identifier "p_ref_322")))))))
                                                                    (let-pair "dstring1_fst_327" "dstring1_snd_328" 
                                                                    (identifier "dstring1_326")
                                                                    (let-pair "dstring2_fst_330" "dstring2_snd_331" 
                                                                    (read-bytes (identifier "dstring1_snd_328") (identifier "dstring1_fst_327"))
                                                                    (make-tup 
                                                                    (cons (make-tup (identifier "dtup_fst_318") (string-of-bytes (identifier "dstring2_fst_330"))) (identifier "dlist2_fst_315")) 
                                                                    (identifier "dstring2_snd_331")))))))))) 
                                                                    (set-vec (u8 0) (identifier "repeat_n_313") (add (unsafe-nth (u8 0) (identifier "repeat_n_313")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_312")))))) 
                                                              (make-tup (identity (identifier "dlist4_fst_339")) (identifier "dlist4_snd_340")))
                                                            (let-pair "drec_fst_342" "drec_snd_343" 
                                                              (identifier "drec_341")
                                                              (let "drec_356"
                                                                (let "dstring1_350"
                                                                  (let "leb_ref_344" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_345" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_346" 
                                                                    (make-vec (identifier "drec_snd_343"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_347" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_346")))
                                                                    (let-pair "leb128_fst_348" "leb128_snd_349" 
                                                                    (identifier "leb128_347")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_346") (identifier "leb128_snd_349"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_344")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_348") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_345")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_344")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_345") (add (unsafe-nth (u8 0) (identifier "shft_ref_345")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_348") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_344"))) (unsafe-nth (u8 0) (identifier "p_ref_346")))))))
                                                                  (let-pair "dstring1_fst_351" "dstring1_snd_352" 
                                                                    (identifier "dstring1_350")
                                                                    (let-pair "dstring2_fst_354" "dstring2_snd_355" 
                                                                    (read-bytes (identifier "dstring1_snd_352") (identifier "dstring1_fst_351"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_354")) (identifier "dstring2_snd_355")))))
                                                                (let-pair "drec_fst_357" "drec_snd_358" 
                                                                  (identifier "drec_356")
                                                                  (let "drec_371"
                                                                    (let "dstring1_365"
                                                                    (let "leb_ref_359" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_360" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_361" 
                                                                    (make-vec (identifier "drec_snd_358"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_362" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_361")))
                                                                    (let-pair "leb128_fst_363" "leb128_snd_364" 
                                                                    (identifier "leb128_362")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_361") (identifier "leb128_snd_364"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_359")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_363") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_360")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_359")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_360") (add (unsafe-nth (u8 0) (identifier "shft_ref_360")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_363") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_359"))) (unsafe-nth (u8 0) (identifier "p_ref_361")))))))
                                                                    (let-pair "dstring1_fst_366" "dstring1_snd_367" 
                                                                    (identifier "dstring1_365")
                                                                    (let-pair "dstring2_fst_369" "dstring2_snd_370" 
                                                                    (read-bytes (identifier "dstring1_snd_367") (identifier "dstring1_fst_366"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_369")) (identifier "dstring2_snd_370")))))
                                                                    (let-pair "drec_fst_372" "drec_snd_373" 
                                                                    (identifier "drec_371")
                                                                    (let "drec_386"
                                                                    (let "dstring1_380"
                                                                    (let "leb_ref_374" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_375" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_376" 
                                                                    (make-vec (identifier "drec_snd_373"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_377" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_376")))
                                                                    (let-pair "leb128_fst_378" "leb128_snd_379" 
                                                                    (identifier "leb128_377")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_376") (identifier "leb128_snd_379"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_374")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_378") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_375")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_374")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_375") (add (unsafe-nth (u8 0) (identifier "shft_ref_375")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_378") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_374"))) (unsafe-nth (u8 0) (identifier "p_ref_376")))))))
                                                                    (let-pair "dstring1_fst_381" "dstring1_snd_382" 
                                                                    (identifier "dstring1_380")
                                                                    (let-pair "dstring2_fst_384" "dstring2_snd_385" 
                                                                    (read-bytes (identifier "dstring1_snd_382") (identifier "dstring1_fst_381"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_384")) (identifier "dstring2_snd_385")))))
                                                                    (let-pair "drec_fst_387" "drec_snd_388" 
                                                                    (identifier "drec_386")
                                                                    (let "dstring1_395"
                                                                    (let "leb_ref_389" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_390" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_391" 
                                                                    (make-vec (identifier "drec_snd_388"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_392" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_391")))
                                                                    (let-pair "leb128_fst_393" "leb128_snd_394" 
                                                                    (identifier "leb128_392")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_391") (identifier "leb128_snd_394"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_389")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_393") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_390")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_389")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_390") (add (unsafe-nth (u8 0) (identifier "shft_ref_390")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_393") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_389"))) (unsafe-nth (u8 0) (identifier "p_ref_391")))))))
                                                                    (let-pair "dstring1_fst_396" "dstring1_snd_397" 
                                                                    (identifier "dstring1_395")
                                                                    (let-pair "dstring2_fst_399" "dstring2_snd_400" 
                                                                    (read-bytes (identifier "dstring1_snd_397") (identifier "dstring1_fst_396"))
                                                                    (make-tup
                                                                    (make-rec 
                                                                    (string "desc-recovery") 
                                                                    (string-of-bytes (identifier "dstring2_fst_399")) 
                                                                    (string "desc-firing") 
                                                                    (identifier "drec_fst_387") 
                                                                    (string "desc-title") 
                                                                    (identifier "drec_fst_372") 
                                                                    (string "id") 
                                                                    (identifier "drec_fst_357") 
                                                                    (string "carry-csts") 
                                                                    (identifier "drec_fst_342") 
                                                                    (string "carry-fields") 
                                                                    (identifier "drec_fst_298") 
                                                                    (string "tops") 
                                                                    (identifier "drec_fst_272") 
                                                                    (string "time-step") 
                                                                    (identifier "drec_fst_246") 
                                                                    (string "ratio") 
                                                                    (identifier "drec_fst_240") 
                                                                    (string "duration") 
                                                                    (identifier "drec_fst_234") 
                                                                    (string "hysteresis") 
                                                                    (identifier "drec_fst_228") 
                                                                    (string "threshold") 
                                                                    (identifier "drec_fst_222") 
                                                                    (string "having") 
                                                                    (identifier "drec_fst_147") 
                                                                    (string "group-by") 
                                                                    (identifier "drec_fst_121") 
                                                                    (string "where") 
                                                                    (identifier "drec_fst_92") 
                                                                    (string "enabled") 
                                                                    (identifier "drec_fst_66") 
                                                                    (string "column") 
                                                                    (identifier "drec_fst_60") 
                                                                    (string "table") 
                                                                    (identifier "drec_fst_57")) 
                                                                    (identifier "dstring2_snd_400"))))))))))))))))))))))))))))))))))))))))
 */
static std::function<::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337(Pointer)> fun1252 { [&fun1252](Pointer p_0) {
    auto fun1253 { dessser::gen::fq_name::of_row_binary };
    ::dessser::gen::alert::td8eaddfacf232bd15ab91a5778e12a3b id_1254 { fun1253(p_0) };
    ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1255;
    {
      ::dessser::gen::alert::td8eaddfacf232bd15ab91a5778e12a3b drec_56 { id_1254 };
      ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1256;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        auto fun1257 { dessser::gen::field_name::of_row_binary };
        ::dessser::gen::alert::t273a2b7978f5b466a128a51c1cc4a27b id_1258 { fun1257(drec_snd_58) };
        ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1259;
        {
          ::dessser::gen::alert::t273a2b7978f5b466a128a51c1cc4a27b drec_59 { id_1258 };
          ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1260;
          {
            auto drec_fst_60 { std::get<0>(drec_59) };
            auto drec_snd_61 { std::get<1>(drec_59) };
            ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1261 { drec_snd_61.readU8() };
            ::dessser::gen::alert::t4138de986e20d18b01e4c493dc9d5451 letpair_res_1262;
            {
              auto dbool_fst_63 { std::get<0>(id_1261) };
              auto dbool_snd_64 { std::get<1>(id_1261) };
              uint8_t id_1263 { 0 };
              bool id_1264 { bool(dbool_fst_63 == id_1263) };
              bool id_1265 { ! id_1264 };
              ::dessser::gen::alert::t4138de986e20d18b01e4c493dc9d5451 id_1266 { id_1265, dbool_snd_64 };
              letpair_res_1262 = id_1266;
            }
            ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1267;
            {
              ::dessser::gen::alert::t4138de986e20d18b01e4c493dc9d5451 drec_65 { letpair_res_1262 };
              ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1268;
              {
                auto drec_fst_66 { std::get<0>(drec_65) };
                auto drec_snd_67 { std::get<1>(drec_65) };
                uint32_t id_1269 { 0U };
                Vec<1, uint32_t> id_1270 {  id_1269  };
                ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1271;
                {
                  Vec<1, uint32_t> leb_ref_68 { id_1270 };
                  uint8_t id_1272 { 0 };
                  Vec<1, uint8_t> id_1273 {  id_1272  };
                  ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1274;
                  {
                    Vec<1, uint8_t> shft_ref_69 { id_1273 };
                    Vec<1, Pointer> id_1275 {  drec_snd_67  };
                    ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1276;
                    {
                      Vec<1, Pointer> p_ref_70 { id_1275 };
                      bool while_flag_1277 { true };
                      do {
                        uint8_t id_1278 { 0 };
                        Pointer id_1279 { p_ref_70[id_1278] };
                        ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1280 { id_1279.readU8() };
                        bool let_res_1281;
                        {
                          ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_71 { id_1280 };
                          bool letpair_res_1282;
                          {
                            auto leb128_fst_72 { std::get<0>(leb128_71) };
                            auto leb128_snd_73 { std::get<1>(leb128_71) };
                            uint8_t id_1283 { 0 };
                            Void id_1284 { ((void)(p_ref_70[id_1283] = leb128_snd_73), VOID) };
                            (void)id_1284;
                            uint8_t id_1285 { 0 };
                            uint8_t id_1286 { 127 };
                            uint8_t id_1287 { uint8_t(leb128_fst_72 & id_1286) };
                            uint32_t id_1288 { uint32_t(id_1287) };
                            uint8_t id_1289 { 0 };
                            uint8_t id_1290 { shft_ref_69[id_1289] };
                            uint32_t id_1291 { uint32_t(id_1288 << id_1290) };
                            uint8_t id_1292 { 0 };
                            uint32_t id_1293 { leb_ref_68[id_1292] };
                            uint32_t id_1294 { uint32_t(id_1291 | id_1293) };
                            Void id_1295 { ((void)(leb_ref_68[id_1285] = id_1294), VOID) };
                            (void)id_1295;
                            uint8_t id_1296 { 0 };
                            uint8_t id_1297 { 0 };
                            uint8_t id_1298 { shft_ref_69[id_1297] };
                            uint8_t id_1299 { 7 };
                            uint8_t id_1300 { uint8_t(id_1298 + id_1299) };
                            Void id_1301 { ((void)(shft_ref_69[id_1296] = id_1300), VOID) };
                            (void)id_1301;
                            uint8_t id_1302 { 128 };
                            bool id_1303 { bool(leb128_fst_72 >= id_1302) };
                            letpair_res_1282 = id_1303;
                          }
                          let_res_1281 = letpair_res_1282;
                        }
                        while_flag_1277 = let_res_1281;
                        if (while_flag_1277) {
                          (void)VOID;
                        }
                      } while (while_flag_1277);
                      (void)VOID;
                      uint8_t id_1304 { 0 };
                      uint32_t id_1305 { leb_ref_68[id_1304] };
                      uint8_t id_1306 { 0 };
                      Pointer id_1307 { p_ref_70[id_1306] };
                      ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1308 { id_1305, id_1307 };
                      let_res_1276 = id_1308;
                    }
                    let_res_1274 = let_res_1276;
                  }
                  let_res_1271 = let_res_1274;
                }
                ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 let_res_1309;
                {
                  ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 dlist1_77 { let_res_1271 };
                  ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 letpair_res_1310;
                  {
                    auto dlist1_fst_78 { std::get<0>(dlist1_77) };
                    auto dlist1_snd_79 { std::get<1>(dlist1_77) };
                    Lst<dessser::gen::simple_filter::t_ext> endoflist_1311;
                    ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1312 { endoflist_1311, dlist1_snd_79 };
                    Vec<1, ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690> id_1313 {  id_1312  };
                    ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 let_res_1314;
                    {
                      Vec<1, ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690> inits_src_ref_80 { id_1313 };
                      int32_t id_1315 { 0L };
                      Vec<1, int32_t> id_1316 {  id_1315  };
                      {
                        Vec<1, int32_t> repeat_n_81 { id_1316 };
                        bool while_flag_1317 { true };
                        do {
                          int32_t id_1318 { int32_t(dlist1_fst_78) };
                          uint8_t id_1319 { 0 };
                          int32_t id_1320 { repeat_n_81[id_1319] };
                          bool id_1321 { bool(id_1318 > id_1320) };
                          while_flag_1317 = id_1321;
                          if (while_flag_1317) {
                            uint8_t id_1322 { 0 };
                            ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1323 { inits_src_ref_80[id_1322] };
                            {
                              ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 dlist2_82 { id_1323 };
                              {
                                auto dlist2_fst_83 { std::get<0>(dlist2_82) };
                                auto dlist2_snd_84 { std::get<1>(dlist2_82) };
                                uint8_t id_1324 { 0 };
                                auto fun1325 { dessser::gen::simple_filter::of_row_binary };
                                ::dessser::gen::alert::t90fff9b602787b5715d84f577a3751a3 id_1326 { fun1325(dlist2_snd_84) };
                                ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 letpair_res_1327;
                                {
                                  auto dlist3_fst_86 { std::get<0>(id_1326) };
                                  auto dlist3_snd_87 { std::get<1>(id_1326) };
                                  Lst<dessser::gen::simple_filter::t_ext> id_1328 { dlist3_fst_86, dlist2_fst_83 };
                                  ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1329 { id_1328, dlist3_snd_87 };
                                  letpair_res_1327 = id_1329;
                                }
                                Void id_1330 { ((void)(inits_src_ref_80[id_1324] = letpair_res_1327), VOID) };
                                (void)id_1330;
                              }
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_1331 { 0 };
                            uint8_t id_1332 { 0 };
                            int32_t id_1333 { repeat_n_81[id_1332] };
                            int32_t id_1334 { 1L };
                            int32_t id_1335 { int32_t(id_1333 + id_1334) };
                            Void id_1336 { ((void)(repeat_n_81[id_1331] = id_1335), VOID) };
                            (void)id_1336;
                            (void)id_1336;
                          }
                        } while (while_flag_1317);
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_1337 { 0 };
                      ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1338 { inits_src_ref_80[id_1337] };
                      let_res_1314 = id_1338;
                    }
                    letpair_res_1310 = let_res_1314;
                  }
                  let_res_1309 = letpair_res_1310;
                }
                ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 letpair_res_1339;
                {
                  auto dlist4_fst_89 { std::get<0>(let_res_1309) };
                  auto dlist4_snd_90 { std::get<1>(let_res_1309) };
                  ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1340 { dlist4_fst_89, dlist4_snd_90 };
                  letpair_res_1339 = id_1340;
                }
                ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1341;
                {
                  ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 drec_91 { letpair_res_1339 };
                  ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1342;
                  {
                    auto drec_fst_92 { std::get<0>(drec_91) };
                    auto drec_snd_93 { std::get<1>(drec_91) };
                    Size id_1343 { 0UL };
                    uint8_t id_1344 { drec_snd_93.peekU8(id_1343) };
                    uint8_t id_1345 { 1 };
                    bool id_1346 { bool(id_1344 == id_1345) };
                    ::dessser::gen::alert::t885b8962b524dff3368f7a529f1d466b choose_res_1347;
                    if (id_1346) {
                      std::optional<Lst<dessser::gen::field_name::t_ext>> id_1348 { std::nullopt };
                      Size id_1349 { 1UL };
                      Pointer id_1350 { drec_snd_93.skip(id_1349) };
                      ::dessser::gen::alert::t885b8962b524dff3368f7a529f1d466b id_1351 { id_1348, id_1350 };
                      choose_res_1347 = id_1351;
                    } else {
                      uint32_t id_1352 { 0U };
                      Vec<1, uint32_t> id_1353 {  id_1352  };
                      ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1354;
                      {
                        Vec<1, uint32_t> leb_ref_94 { id_1353 };
                        uint8_t id_1355 { 0 };
                        Vec<1, uint8_t> id_1356 {  id_1355  };
                        ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1357;
                        {
                          Vec<1, uint8_t> shft_ref_95 { id_1356 };
                          Size id_1358 { 1UL };
                          Pointer id_1359 { drec_snd_93.skip(id_1358) };
                          Vec<1, Pointer> id_1360 {  id_1359  };
                          ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1361;
                          {
                            Vec<1, Pointer> p_ref_96 { id_1360 };
                            bool while_flag_1362 { true };
                            do {
                              uint8_t id_1363 { 0 };
                              Pointer id_1364 { p_ref_96[id_1363] };
                              ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1365 { id_1364.readU8() };
                              bool let_res_1366;
                              {
                                ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_97 { id_1365 };
                                bool letpair_res_1367;
                                {
                                  auto leb128_fst_98 { std::get<0>(leb128_97) };
                                  auto leb128_snd_99 { std::get<1>(leb128_97) };
                                  uint8_t id_1368 { 0 };
                                  Void id_1369 { ((void)(p_ref_96[id_1368] = leb128_snd_99), VOID) };
                                  (void)id_1369;
                                  uint8_t id_1370 { 0 };
                                  uint8_t id_1371 { 127 };
                                  uint8_t id_1372 { uint8_t(leb128_fst_98 & id_1371) };
                                  uint32_t id_1373 { uint32_t(id_1372) };
                                  uint8_t id_1374 { 0 };
                                  uint8_t id_1375 { shft_ref_95[id_1374] };
                                  uint32_t id_1376 { uint32_t(id_1373 << id_1375) };
                                  uint8_t id_1377 { 0 };
                                  uint32_t id_1378 { leb_ref_94[id_1377] };
                                  uint32_t id_1379 { uint32_t(id_1376 | id_1378) };
                                  Void id_1380 { ((void)(leb_ref_94[id_1370] = id_1379), VOID) };
                                  (void)id_1380;
                                  uint8_t id_1381 { 0 };
                                  uint8_t id_1382 { 0 };
                                  uint8_t id_1383 { shft_ref_95[id_1382] };
                                  uint8_t id_1384 { 7 };
                                  uint8_t id_1385 { uint8_t(id_1383 + id_1384) };
                                  Void id_1386 { ((void)(shft_ref_95[id_1381] = id_1385), VOID) };
                                  (void)id_1386;
                                  uint8_t id_1387 { 128 };
                                  bool id_1388 { bool(leb128_fst_98 >= id_1387) };
                                  letpair_res_1367 = id_1388;
                                }
                                let_res_1366 = letpair_res_1367;
                              }
                              while_flag_1362 = let_res_1366;
                              if (while_flag_1362) {
                                (void)VOID;
                              }
                            } while (while_flag_1362);
                            (void)VOID;
                            uint8_t id_1389 { 0 };
                            uint32_t id_1390 { leb_ref_94[id_1389] };
                            uint8_t id_1391 { 0 };
                            Pointer id_1392 { p_ref_96[id_1391] };
                            ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1393 { id_1390, id_1392 };
                            let_res_1361 = id_1393;
                          }
                          let_res_1357 = let_res_1361;
                        }
                        let_res_1354 = let_res_1357;
                      }
                      ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 let_res_1394;
                      {
                        ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 dlist1_103 { let_res_1354 };
                        ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 letpair_res_1395;
                        {
                          auto dlist1_fst_104 { std::get<0>(dlist1_103) };
                          auto dlist1_snd_105 { std::get<1>(dlist1_103) };
                          Lst<dessser::gen::field_name::t_ext> endoflist_1396;
                          ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1397 { endoflist_1396, dlist1_snd_105 };
                          Vec<1, ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967> id_1398 {  id_1397  };
                          ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 let_res_1399;
                          {
                            Vec<1, ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967> inits_src_ref_106 { id_1398 };
                            int32_t id_1400 { 0L };
                            Vec<1, int32_t> id_1401 {  id_1400  };
                            {
                              Vec<1, int32_t> repeat_n_107 { id_1401 };
                              bool while_flag_1402 { true };
                              do {
                                int32_t id_1403 { int32_t(dlist1_fst_104) };
                                uint8_t id_1404 { 0 };
                                int32_t id_1405 { repeat_n_107[id_1404] };
                                bool id_1406 { bool(id_1403 > id_1405) };
                                while_flag_1402 = id_1406;
                                if (while_flag_1402) {
                                  uint8_t id_1407 { 0 };
                                  ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1408 { inits_src_ref_106[id_1407] };
                                  {
                                    ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 dlist2_108 { id_1408 };
                                    {
                                      auto dlist2_fst_109 { std::get<0>(dlist2_108) };
                                      auto dlist2_snd_110 { std::get<1>(dlist2_108) };
                                      uint8_t id_1409 { 0 };
                                      auto fun1410 { dessser::gen::field_name::of_row_binary };
                                      ::dessser::gen::alert::t273a2b7978f5b466a128a51c1cc4a27b id_1411 { fun1410(dlist2_snd_110) };
                                      ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 letpair_res_1412;
                                      {
                                        auto dlist3_fst_112 { std::get<0>(id_1411) };
                                        auto dlist3_snd_113 { std::get<1>(id_1411) };
                                        Lst<dessser::gen::field_name::t_ext> id_1413 { dlist3_fst_112, dlist2_fst_109 };
                                        ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1414 { id_1413, dlist3_snd_113 };
                                        letpair_res_1412 = id_1414;
                                      }
                                      Void id_1415 { ((void)(inits_src_ref_106[id_1409] = letpair_res_1412), VOID) };
                                      (void)id_1415;
                                    }
                                    (void)VOID;
                                  }
                                  (void)VOID;
                                  uint8_t id_1416 { 0 };
                                  uint8_t id_1417 { 0 };
                                  int32_t id_1418 { repeat_n_107[id_1417] };
                                  int32_t id_1419 { 1L };
                                  int32_t id_1420 { int32_t(id_1418 + id_1419) };
                                  Void id_1421 { ((void)(repeat_n_107[id_1416] = id_1420), VOID) };
                                  (void)id_1421;
                                  (void)id_1421;
                                }
                              } while (while_flag_1402);
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_1422 { 0 };
                            ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1423 { inits_src_ref_106[id_1422] };
                            let_res_1399 = id_1423;
                          }
                          letpair_res_1395 = let_res_1399;
                        }
                        let_res_1394 = letpair_res_1395;
                      }
                      ::dessser::gen::alert::t885b8962b524dff3368f7a529f1d466b letpair_res_1424;
                      {
                        auto dlist4_fst_115 { std::get<0>(let_res_1394) };
                        auto dlist4_snd_116 { std::get<1>(let_res_1394) };
                        std::optional<Lst<dessser::gen::field_name::t_ext>> id_1425 { dlist4_fst_115 };
                        ::dessser::gen::alert::t885b8962b524dff3368f7a529f1d466b id_1426 { id_1425, dlist4_snd_116 };
                        letpair_res_1424 = id_1426;
                      }
                      choose_res_1347 = letpair_res_1424;
                    }
                    ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1427;
                    {
                      ::dessser::gen::alert::t885b8962b524dff3368f7a529f1d466b drec_120 { choose_res_1347 };
                      ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1428;
                      {
                        auto drec_fst_121 { std::get<0>(drec_120) };
                        auto drec_snd_122 { std::get<1>(drec_120) };
                        uint32_t id_1429 { 0U };
                        Vec<1, uint32_t> id_1430 {  id_1429  };
                        ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1431;
                        {
                          Vec<1, uint32_t> leb_ref_123 { id_1430 };
                          uint8_t id_1432 { 0 };
                          Vec<1, uint8_t> id_1433 {  id_1432  };
                          ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1434;
                          {
                            Vec<1, uint8_t> shft_ref_124 { id_1433 };
                            Vec<1, Pointer> id_1435 {  drec_snd_122  };
                            ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1436;
                            {
                              Vec<1, Pointer> p_ref_125 { id_1435 };
                              bool while_flag_1437 { true };
                              do {
                                uint8_t id_1438 { 0 };
                                Pointer id_1439 { p_ref_125[id_1438] };
                                ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1440 { id_1439.readU8() };
                                bool let_res_1441;
                                {
                                  ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_126 { id_1440 };
                                  bool letpair_res_1442;
                                  {
                                    auto leb128_fst_127 { std::get<0>(leb128_126) };
                                    auto leb128_snd_128 { std::get<1>(leb128_126) };
                                    uint8_t id_1443 { 0 };
                                    Void id_1444 { ((void)(p_ref_125[id_1443] = leb128_snd_128), VOID) };
                                    (void)id_1444;
                                    uint8_t id_1445 { 0 };
                                    uint8_t id_1446 { 127 };
                                    uint8_t id_1447 { uint8_t(leb128_fst_127 & id_1446) };
                                    uint32_t id_1448 { uint32_t(id_1447) };
                                    uint8_t id_1449 { 0 };
                                    uint8_t id_1450 { shft_ref_124[id_1449] };
                                    uint32_t id_1451 { uint32_t(id_1448 << id_1450) };
                                    uint8_t id_1452 { 0 };
                                    uint32_t id_1453 { leb_ref_123[id_1452] };
                                    uint32_t id_1454 { uint32_t(id_1451 | id_1453) };
                                    Void id_1455 { ((void)(leb_ref_123[id_1445] = id_1454), VOID) };
                                    (void)id_1455;
                                    uint8_t id_1456 { 0 };
                                    uint8_t id_1457 { 0 };
                                    uint8_t id_1458 { shft_ref_124[id_1457] };
                                    uint8_t id_1459 { 7 };
                                    uint8_t id_1460 { uint8_t(id_1458 + id_1459) };
                                    Void id_1461 { ((void)(shft_ref_124[id_1456] = id_1460), VOID) };
                                    (void)id_1461;
                                    uint8_t id_1462 { 128 };
                                    bool id_1463 { bool(leb128_fst_127 >= id_1462) };
                                    letpair_res_1442 = id_1463;
                                  }
                                  let_res_1441 = letpair_res_1442;
                                }
                                while_flag_1437 = let_res_1441;
                                if (while_flag_1437) {
                                  (void)VOID;
                                }
                              } while (while_flag_1437);
                              (void)VOID;
                              uint8_t id_1464 { 0 };
                              uint32_t id_1465 { leb_ref_123[id_1464] };
                              uint8_t id_1466 { 0 };
                              Pointer id_1467 { p_ref_125[id_1466] };
                              ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1468 { id_1465, id_1467 };
                              let_res_1436 = id_1468;
                            }
                            let_res_1434 = let_res_1436;
                          }
                          let_res_1431 = let_res_1434;
                        }
                        ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 let_res_1469;
                        {
                          ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 dlist1_132 { let_res_1431 };
                          ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 letpair_res_1470;
                          {
                            auto dlist1_fst_133 { std::get<0>(dlist1_132) };
                            auto dlist1_snd_134 { std::get<1>(dlist1_132) };
                            Lst<dessser::gen::simple_filter::t_ext> endoflist_1471;
                            ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1472 { endoflist_1471, dlist1_snd_134 };
                            Vec<1, ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690> id_1473 {  id_1472  };
                            ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 let_res_1474;
                            {
                              Vec<1, ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690> inits_src_ref_135 { id_1473 };
                              int32_t id_1475 { 0L };
                              Vec<1, int32_t> id_1476 {  id_1475  };
                              {
                                Vec<1, int32_t> repeat_n_136 { id_1476 };
                                bool while_flag_1477 { true };
                                do {
                                  int32_t id_1478 { int32_t(dlist1_fst_133) };
                                  uint8_t id_1479 { 0 };
                                  int32_t id_1480 { repeat_n_136[id_1479] };
                                  bool id_1481 { bool(id_1478 > id_1480) };
                                  while_flag_1477 = id_1481;
                                  if (while_flag_1477) {
                                    uint8_t id_1482 { 0 };
                                    ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1483 { inits_src_ref_135[id_1482] };
                                    {
                                      ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 dlist2_137 { id_1483 };
                                      {
                                        auto dlist2_fst_138 { std::get<0>(dlist2_137) };
                                        auto dlist2_snd_139 { std::get<1>(dlist2_137) };
                                        uint8_t id_1484 { 0 };
                                        auto fun1485 { dessser::gen::simple_filter::of_row_binary };
                                        ::dessser::gen::alert::t90fff9b602787b5715d84f577a3751a3 id_1486 { fun1485(dlist2_snd_139) };
                                        ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 letpair_res_1487;
                                        {
                                          auto dlist3_fst_141 { std::get<0>(id_1486) };
                                          auto dlist3_snd_142 { std::get<1>(id_1486) };
                                          Lst<dessser::gen::simple_filter::t_ext> id_1488 { dlist3_fst_141, dlist2_fst_138 };
                                          ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1489 { id_1488, dlist3_snd_142 };
                                          letpair_res_1487 = id_1489;
                                        }
                                        Void id_1490 { ((void)(inits_src_ref_135[id_1484] = letpair_res_1487), VOID) };
                                        (void)id_1490;
                                      }
                                      (void)VOID;
                                    }
                                    (void)VOID;
                                    uint8_t id_1491 { 0 };
                                    uint8_t id_1492 { 0 };
                                    int32_t id_1493 { repeat_n_136[id_1492] };
                                    int32_t id_1494 { 1L };
                                    int32_t id_1495 { int32_t(id_1493 + id_1494) };
                                    Void id_1496 { ((void)(repeat_n_136[id_1491] = id_1495), VOID) };
                                    (void)id_1496;
                                    (void)id_1496;
                                  }
                                } while (while_flag_1477);
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_1497 { 0 };
                              ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1498 { inits_src_ref_135[id_1497] };
                              let_res_1474 = id_1498;
                            }
                            letpair_res_1470 = let_res_1474;
                          }
                          let_res_1469 = letpair_res_1470;
                        }
                        ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 letpair_res_1499;
                        {
                          auto dlist4_fst_144 { std::get<0>(let_res_1469) };
                          auto dlist4_snd_145 { std::get<1>(let_res_1469) };
                          ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 id_1500 { dlist4_fst_144, dlist4_snd_145 };
                          letpair_res_1499 = id_1500;
                        }
                        ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1501;
                        {
                          ::dessser::gen::alert::td8c70b15de14ddb4da7c6051edb88690 drec_146 { letpair_res_1499 };
                          ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1502;
                          {
                            auto drec_fst_147 { std::get<0>(drec_146) };
                            auto drec_snd_148 { std::get<1>(drec_146) };
                            ::dessser::gen::alert::t22a32080ad88ab548b80077a17b7dd46 id_1503 { drec_snd_148.readU16Le() };
                            ::dessser::gen::alert::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1504;
                            {
                              auto du16_fst_150 { std::get<0>(id_1503) };
                              auto du16_snd_151 { std::get<1>(id_1503) };
                              ::dessser::gen::alert::t22a32080ad88ab548b80077a17b7dd46 id_1505 { du16_fst_150, du16_snd_151 };
                              letpair_res_1504 = id_1505;
                            }
                            ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 let_res_1506;
                            {
                              ::dessser::gen::alert::t22a32080ad88ab548b80077a17b7dd46 dsum1_155 { letpair_res_1504 };
                              ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 letpair_res_1507;
                              {
                                auto dsum1_fst_156 { std::get<0>(dsum1_155) };
                                auto dsum1_snd_157 { std::get<1>(dsum1_155) };
                                uint16_t id_1508 { 0 };
                                bool id_1509 { bool(id_1508 == dsum1_fst_156) };
                                ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 choose_res_1510;
                                if (id_1509) {
                                  ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1511 { dsum1_snd_157.readU64Le() };
                                  ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 letpair_res_1512;
                                  {
                                    auto dfloat_fst_216 { std::get<0>(id_1511) };
                                    auto dfloat_snd_217 { std::get<1>(id_1511) };
                                    double id_1513 { float_of_qword(dfloat_fst_216) };
                                    ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_1514 { std::in_place_index<0>, id_1513 };
                                    ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 id_1515 { id_1514, dfloat_snd_217 };
                                    letpair_res_1512 = id_1515;
                                  }
                                  choose_res_1510 = letpair_res_1512;
                                } else {
                                  uint16_t id_1516 { 1 };
                                  bool id_1517 { bool(dsum1_fst_156 == id_1516) };
                                  Void id_1518 { ((void)(assert(id_1517)), VOID) };
                                  (void)id_1518;
                                  ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1519 { dsum1_snd_157.readU64Le() };
                                  ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_1520;
                                  {
                                    auto dfloat_fst_159 { std::get<0>(id_1519) };
                                    auto dfloat_snd_160 { std::get<1>(id_1519) };
                                    double id_1521 { float_of_qword(dfloat_fst_159) };
                                    ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade id_1522 { id_1521, dfloat_snd_160 };
                                    letpair_res_1520 = id_1522;
                                  }
                                  ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 let_res_1523;
                                  {
                                    ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade drec_161 { letpair_res_1520 };
                                    ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 letpair_res_1524;
                                    {
                                      auto drec_fst_162 { std::get<0>(drec_161) };
                                      auto drec_snd_163 { std::get<1>(drec_161) };
                                      ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1525 { drec_snd_163.readU32Le() };
                                      ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 letpair_res_1526;
                                      {
                                        auto du32_fst_165 { std::get<0>(id_1525) };
                                        auto du32_snd_166 { std::get<1>(id_1525) };
                                        ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1527 { du32_fst_165, du32_snd_166 };
                                        letpair_res_1526 = id_1527;
                                      }
                                      ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 let_res_1528;
                                      {
                                        ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 drec_167 { letpair_res_1526 };
                                        ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 letpair_res_1529;
                                        {
                                          auto drec_fst_168 { std::get<0>(drec_167) };
                                          auto drec_snd_169 { std::get<1>(drec_167) };
                                          ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1530 { drec_snd_169.readU64Le() };
                                          ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_1531;
                                          {
                                            auto dfloat_fst_171 { std::get<0>(id_1530) };
                                            auto dfloat_snd_172 { std::get<1>(id_1530) };
                                            double id_1532 { float_of_qword(dfloat_fst_171) };
                                            ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade id_1533 { id_1532, dfloat_snd_172 };
                                            letpair_res_1531 = id_1533;
                                          }
                                          ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 let_res_1534;
                                          {
                                            ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade drec_173 { letpair_res_1531 };
                                            ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 letpair_res_1535;
                                            {
                                              auto drec_fst_174 { std::get<0>(drec_173) };
                                              auto drec_snd_175 { std::get<1>(drec_173) };
                                              ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1536 { drec_snd_175.readU32Le() };
                                              ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 letpair_res_1537;
                                              {
                                                auto du32_fst_177 { std::get<0>(id_1536) };
                                                auto du32_snd_178 { std::get<1>(id_1536) };
                                                ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1538 { du32_fst_177, du32_snd_178 };
                                                letpair_res_1537 = id_1538;
                                              }
                                              ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 let_res_1539;
                                              {
                                                ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 drec_179 { letpair_res_1537 };
                                                ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 letpair_res_1540;
                                                {
                                                  auto drec_fst_180 { std::get<0>(drec_179) };
                                                  auto drec_snd_181 { std::get<1>(drec_179) };
                                                  ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1541 { drec_snd_181.readU64Le() };
                                                  ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_1542;
                                                  {
                                                    auto dfloat_fst_183 { std::get<0>(id_1541) };
                                                    auto dfloat_snd_184 { std::get<1>(id_1541) };
                                                    double id_1543 { float_of_qword(dfloat_fst_183) };
                                                    ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade id_1544 { id_1543, dfloat_snd_184 };
                                                    letpair_res_1542 = id_1544;
                                                  }
                                                  ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 let_res_1545;
                                                  {
                                                    ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade drec_185 { letpair_res_1542 };
                                                    ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 letpair_res_1546;
                                                    {
                                                      auto drec_fst_186 { std::get<0>(drec_185) };
                                                      auto drec_snd_187 { std::get<1>(drec_185) };
                                                      ::dessser::gen::alert::t22a32080ad88ab548b80077a17b7dd46 id_1547 { drec_snd_187.readU16Le() };
                                                      ::dessser::gen::alert::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1548;
                                                      {
                                                        auto du16_fst_189 { std::get<0>(id_1547) };
                                                        auto du16_snd_190 { std::get<1>(id_1547) };
                                                        ::dessser::gen::alert::t22a32080ad88ab548b80077a17b7dd46 id_1549 { du16_fst_189, du16_snd_190 };
                                                        letpair_res_1548 = id_1549;
                                                      }
                                                      ::dessser::gen::alert::t9b54bb8575ac4acd59014f4a6b949d7a let_res_1550;
                                                      {
                                                        ::dessser::gen::alert::t22a32080ad88ab548b80077a17b7dd46 dsum1_194 { letpair_res_1548 };
                                                        ::dessser::gen::alert::t9b54bb8575ac4acd59014f4a6b949d7a letpair_res_1551;
                                                        {
                                                          auto dsum1_fst_195 { std::get<0>(dsum1_194) };
                                                          auto dsum1_snd_196 { std::get<1>(dsum1_194) };
                                                          uint16_t id_1552 { 0 };
                                                          bool id_1553 { bool(id_1552 == dsum1_fst_195) };
                                                          ::dessser::gen::alert::t9b54bb8575ac4acd59014f4a6b949d7a choose_res_1554;
                                                          if (id_1553) {
                                                            ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1555 { dsum1_snd_196.readU64Le() };
                                                            ::dessser::gen::alert::t9b54bb8575ac4acd59014f4a6b949d7a letpair_res_1556;
                                                            {
                                                              auto dfloat_fst_204 { std::get<0>(id_1555) };
                                                              auto dfloat_snd_205 { std::get<1>(id_1555) };
                                                              double id_1557 { float_of_qword(dfloat_fst_204) };
                                                              ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f id_1558 { std::in_place_index<0>, id_1557 };
                                                              ::dessser::gen::alert::t9b54bb8575ac4acd59014f4a6b949d7a id_1559 { id_1558, dfloat_snd_205 };
                                                              letpair_res_1556 = id_1559;
                                                            }
                                                            choose_res_1554 = letpair_res_1556;
                                                          } else {
                                                            uint16_t id_1560 { 1 };
                                                            bool id_1561 { bool(dsum1_fst_195 == id_1560) };
                                                            Void id_1562 { ((void)(assert(id_1561)), VOID) };
                                                            (void)id_1562;
                                                            ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1563 { dsum1_snd_196.readU64Le() };
                                                            ::dessser::gen::alert::t9b54bb8575ac4acd59014f4a6b949d7a letpair_res_1564;
                                                            {
                                                              auto dfloat_fst_198 { std::get<0>(id_1563) };
                                                              auto dfloat_snd_199 { std::get<1>(id_1563) };
                                                              double id_1565 { float_of_qword(dfloat_fst_198) };
                                                              ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f id_1566 { std::in_place_index<1>, id_1565 };
                                                              ::dessser::gen::alert::t9b54bb8575ac4acd59014f4a6b949d7a id_1567 { id_1566, dfloat_snd_199 };
                                                              letpair_res_1564 = id_1567;
                                                            }
                                                            choose_res_1554 = letpair_res_1564;
                                                          }
                                                          letpair_res_1551 = choose_res_1554;
                                                        }
                                                        let_res_1550 = letpair_res_1551;
                                                      }
                                                      ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 letpair_res_1568;
                                                      {
                                                        auto drec_fst_210 { std::get<0>(let_res_1550) };
                                                        auto drec_snd_211 { std::get<1>(let_res_1550) };
                                                        ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 id_1569 { .avg_window = drec_fst_162, .max_distance = drec_fst_210, .percentile = drec_fst_174, .sample_size = drec_fst_168, .seasonality = drec_fst_180, .smooth_factor = drec_fst_186 };
                                                        ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 id_1570 { std::in_place_index<1>, id_1569 };
                                                        ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 id_1571 { id_1570, drec_snd_211 };
                                                        letpair_res_1568 = id_1571;
                                                      }
                                                      letpair_res_1546 = letpair_res_1568;
                                                    }
                                                    let_res_1545 = letpair_res_1546;
                                                  }
                                                  letpair_res_1540 = let_res_1545;
                                                }
                                                let_res_1539 = letpair_res_1540;
                                              }
                                              letpair_res_1535 = let_res_1539;
                                            }
                                            let_res_1534 = letpair_res_1535;
                                          }
                                          letpair_res_1529 = let_res_1534;
                                        }
                                        let_res_1528 = letpair_res_1529;
                                      }
                                      letpair_res_1524 = let_res_1528;
                                    }
                                    let_res_1523 = letpair_res_1524;
                                  }
                                  choose_res_1510 = let_res_1523;
                                }
                                letpair_res_1507 = choose_res_1510;
                              }
                              let_res_1506 = letpair_res_1507;
                            }
                            ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1572;
                            {
                              ::dessser::gen::alert::tac0e3b6e05c5dec5181c5fba06bd8924 drec_221 { let_res_1506 };
                              ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1573;
                              {
                                auto drec_fst_222 { std::get<0>(drec_221) };
                                auto drec_snd_223 { std::get<1>(drec_221) };
                                ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1574 { drec_snd_223.readU64Le() };
                                ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_1575;
                                {
                                  auto dfloat_fst_225 { std::get<0>(id_1574) };
                                  auto dfloat_snd_226 { std::get<1>(id_1574) };
                                  double id_1576 { float_of_qword(dfloat_fst_225) };
                                  ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade id_1577 { id_1576, dfloat_snd_226 };
                                  letpair_res_1575 = id_1577;
                                }
                                ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1578;
                                {
                                  ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade drec_227 { letpair_res_1575 };
                                  ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1579;
                                  {
                                    auto drec_fst_228 { std::get<0>(drec_227) };
                                    auto drec_snd_229 { std::get<1>(drec_227) };
                                    ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1580 { drec_snd_229.readU64Le() };
                                    ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_1581;
                                    {
                                      auto dfloat_fst_231 { std::get<0>(id_1580) };
                                      auto dfloat_snd_232 { std::get<1>(id_1580) };
                                      double id_1582 { float_of_qword(dfloat_fst_231) };
                                      ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade id_1583 { id_1582, dfloat_snd_232 };
                                      letpair_res_1581 = id_1583;
                                    }
                                    ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1584;
                                    {
                                      ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade drec_233 { letpair_res_1581 };
                                      ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1585;
                                      {
                                        auto drec_fst_234 { std::get<0>(drec_233) };
                                        auto drec_snd_235 { std::get<1>(drec_233) };
                                        ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1586 { drec_snd_235.readU64Le() };
                                        ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_1587;
                                        {
                                          auto dfloat_fst_237 { std::get<0>(id_1586) };
                                          auto dfloat_snd_238 { std::get<1>(id_1586) };
                                          double id_1588 { float_of_qword(dfloat_fst_237) };
                                          ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade id_1589 { id_1588, dfloat_snd_238 };
                                          letpair_res_1587 = id_1589;
                                        }
                                        ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1590;
                                        {
                                          ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade drec_239 { letpair_res_1587 };
                                          ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1591;
                                          {
                                            auto drec_fst_240 { std::get<0>(drec_239) };
                                            auto drec_snd_241 { std::get<1>(drec_239) };
                                            ::dessser::gen::alert::t7a47220550fc5126a7b79f1e0c10c645 id_1592 { drec_snd_241.readU64Le() };
                                            ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_1593;
                                            {
                                              auto dfloat_fst_243 { std::get<0>(id_1592) };
                                              auto dfloat_snd_244 { std::get<1>(id_1592) };
                                              double id_1594 { float_of_qword(dfloat_fst_243) };
                                              ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade id_1595 { id_1594, dfloat_snd_244 };
                                              letpair_res_1593 = id_1595;
                                            }
                                            ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1596;
                                            {
                                              ::dessser::gen::alert::taebed00ad7fdb3f7ced11d3cfd58aade drec_245 { letpair_res_1593 };
                                              ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1597;
                                              {
                                                auto drec_fst_246 { std::get<0>(drec_245) };
                                                auto drec_snd_247 { std::get<1>(drec_245) };
                                                uint32_t id_1598 { 0U };
                                                Vec<1, uint32_t> id_1599 {  id_1598  };
                                                ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1600;
                                                {
                                                  Vec<1, uint32_t> leb_ref_248 { id_1599 };
                                                  uint8_t id_1601 { 0 };
                                                  Vec<1, uint8_t> id_1602 {  id_1601  };
                                                  ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1603;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_249 { id_1602 };
                                                    Vec<1, Pointer> id_1604 {  drec_snd_247  };
                                                    ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1605;
                                                    {
                                                      Vec<1, Pointer> p_ref_250 { id_1604 };
                                                      bool while_flag_1606 { true };
                                                      do {
                                                        uint8_t id_1607 { 0 };
                                                        Pointer id_1608 { p_ref_250[id_1607] };
                                                        ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1609 { id_1608.readU8() };
                                                        bool let_res_1610;
                                                        {
                                                          ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_251 { id_1609 };
                                                          bool letpair_res_1611;
                                                          {
                                                            auto leb128_fst_252 { std::get<0>(leb128_251) };
                                                            auto leb128_snd_253 { std::get<1>(leb128_251) };
                                                            uint8_t id_1612 { 0 };
                                                            Void id_1613 { ((void)(p_ref_250[id_1612] = leb128_snd_253), VOID) };
                                                            (void)id_1613;
                                                            uint8_t id_1614 { 0 };
                                                            uint8_t id_1615 { 127 };
                                                            uint8_t id_1616 { uint8_t(leb128_fst_252 & id_1615) };
                                                            uint32_t id_1617 { uint32_t(id_1616) };
                                                            uint8_t id_1618 { 0 };
                                                            uint8_t id_1619 { shft_ref_249[id_1618] };
                                                            uint32_t id_1620 { uint32_t(id_1617 << id_1619) };
                                                            uint8_t id_1621 { 0 };
                                                            uint32_t id_1622 { leb_ref_248[id_1621] };
                                                            uint32_t id_1623 { uint32_t(id_1620 | id_1622) };
                                                            Void id_1624 { ((void)(leb_ref_248[id_1614] = id_1623), VOID) };
                                                            (void)id_1624;
                                                            uint8_t id_1625 { 0 };
                                                            uint8_t id_1626 { 0 };
                                                            uint8_t id_1627 { shft_ref_249[id_1626] };
                                                            uint8_t id_1628 { 7 };
                                                            uint8_t id_1629 { uint8_t(id_1627 + id_1628) };
                                                            Void id_1630 { ((void)(shft_ref_249[id_1625] = id_1629), VOID) };
                                                            (void)id_1630;
                                                            uint8_t id_1631 { 128 };
                                                            bool id_1632 { bool(leb128_fst_252 >= id_1631) };
                                                            letpair_res_1611 = id_1632;
                                                          }
                                                          let_res_1610 = letpair_res_1611;
                                                        }
                                                        while_flag_1606 = let_res_1610;
                                                        if (while_flag_1606) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_1606);
                                                      (void)VOID;
                                                      uint8_t id_1633 { 0 };
                                                      uint32_t id_1634 { leb_ref_248[id_1633] };
                                                      uint8_t id_1635 { 0 };
                                                      Pointer id_1636 { p_ref_250[id_1635] };
                                                      ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1637 { id_1634, id_1636 };
                                                      let_res_1605 = id_1637;
                                                    }
                                                    let_res_1603 = let_res_1605;
                                                  }
                                                  let_res_1600 = let_res_1603;
                                                }
                                                ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 let_res_1638;
                                                {
                                                  ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 dlist1_257 { let_res_1600 };
                                                  ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 letpair_res_1639;
                                                  {
                                                    auto dlist1_fst_258 { std::get<0>(dlist1_257) };
                                                    auto dlist1_snd_259 { std::get<1>(dlist1_257) };
                                                    Lst<dessser::gen::field_name::t_ext> endoflist_1640;
                                                    ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1641 { endoflist_1640, dlist1_snd_259 };
                                                    Vec<1, ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967> id_1642 {  id_1641  };
                                                    ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 let_res_1643;
                                                    {
                                                      Vec<1, ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967> inits_src_ref_260 { id_1642 };
                                                      int32_t id_1644 { 0L };
                                                      Vec<1, int32_t> id_1645 {  id_1644  };
                                                      {
                                                        Vec<1, int32_t> repeat_n_261 { id_1645 };
                                                        bool while_flag_1646 { true };
                                                        do {
                                                          int32_t id_1647 { int32_t(dlist1_fst_258) };
                                                          uint8_t id_1648 { 0 };
                                                          int32_t id_1649 { repeat_n_261[id_1648] };
                                                          bool id_1650 { bool(id_1647 > id_1649) };
                                                          while_flag_1646 = id_1650;
                                                          if (while_flag_1646) {
                                                            uint8_t id_1651 { 0 };
                                                            ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1652 { inits_src_ref_260[id_1651] };
                                                            {
                                                              ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 dlist2_262 { id_1652 };
                                                              {
                                                                auto dlist2_fst_263 { std::get<0>(dlist2_262) };
                                                                auto dlist2_snd_264 { std::get<1>(dlist2_262) };
                                                                uint8_t id_1653 { 0 };
                                                                auto fun1654 { dessser::gen::field_name::of_row_binary };
                                                                ::dessser::gen::alert::t273a2b7978f5b466a128a51c1cc4a27b id_1655 { fun1654(dlist2_snd_264) };
                                                                ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 letpair_res_1656;
                                                                {
                                                                  auto dlist3_fst_266 { std::get<0>(id_1655) };
                                                                  auto dlist3_snd_267 { std::get<1>(id_1655) };
                                                                  Lst<dessser::gen::field_name::t_ext> id_1657 { dlist3_fst_266, dlist2_fst_263 };
                                                                  ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1658 { id_1657, dlist3_snd_267 };
                                                                  letpair_res_1656 = id_1658;
                                                                }
                                                                Void id_1659 { ((void)(inits_src_ref_260[id_1653] = letpair_res_1656), VOID) };
                                                                (void)id_1659;
                                                              }
                                                              (void)VOID;
                                                            }
                                                            (void)VOID;
                                                            uint8_t id_1660 { 0 };
                                                            uint8_t id_1661 { 0 };
                                                            int32_t id_1662 { repeat_n_261[id_1661] };
                                                            int32_t id_1663 { 1L };
                                                            int32_t id_1664 { int32_t(id_1662 + id_1663) };
                                                            Void id_1665 { ((void)(repeat_n_261[id_1660] = id_1664), VOID) };
                                                            (void)id_1665;
                                                            (void)id_1665;
                                                          }
                                                        } while (while_flag_1646);
                                                        (void)VOID;
                                                      }
                                                      (void)VOID;
                                                      uint8_t id_1666 { 0 };
                                                      ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1667 { inits_src_ref_260[id_1666] };
                                                      let_res_1643 = id_1667;
                                                    }
                                                    letpair_res_1639 = let_res_1643;
                                                  }
                                                  let_res_1638 = letpair_res_1639;
                                                }
                                                ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 letpair_res_1668;
                                                {
                                                  auto dlist4_fst_269 { std::get<0>(let_res_1638) };
                                                  auto dlist4_snd_270 { std::get<1>(let_res_1638) };
                                                  ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1669 { dlist4_fst_269, dlist4_snd_270 };
                                                  letpair_res_1668 = id_1669;
                                                }
                                                ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1670;
                                                {
                                                  ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 drec_271 { letpair_res_1668 };
                                                  ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1671;
                                                  {
                                                    auto drec_fst_272 { std::get<0>(drec_271) };
                                                    auto drec_snd_273 { std::get<1>(drec_271) };
                                                    uint32_t id_1672 { 0U };
                                                    Vec<1, uint32_t> id_1673 {  id_1672  };
                                                    ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1674;
                                                    {
                                                      Vec<1, uint32_t> leb_ref_274 { id_1673 };
                                                      uint8_t id_1675 { 0 };
                                                      Vec<1, uint8_t> id_1676 {  id_1675  };
                                                      ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1677;
                                                      {
                                                        Vec<1, uint8_t> shft_ref_275 { id_1676 };
                                                        Vec<1, Pointer> id_1678 {  drec_snd_273  };
                                                        ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1679;
                                                        {
                                                          Vec<1, Pointer> p_ref_276 { id_1678 };
                                                          bool while_flag_1680 { true };
                                                          do {
                                                            uint8_t id_1681 { 0 };
                                                            Pointer id_1682 { p_ref_276[id_1681] };
                                                            ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1683 { id_1682.readU8() };
                                                            bool let_res_1684;
                                                            {
                                                              ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_277 { id_1683 };
                                                              bool letpair_res_1685;
                                                              {
                                                                auto leb128_fst_278 { std::get<0>(leb128_277) };
                                                                auto leb128_snd_279 { std::get<1>(leb128_277) };
                                                                uint8_t id_1686 { 0 };
                                                                Void id_1687 { ((void)(p_ref_276[id_1686] = leb128_snd_279), VOID) };
                                                                (void)id_1687;
                                                                uint8_t id_1688 { 0 };
                                                                uint8_t id_1689 { 127 };
                                                                uint8_t id_1690 { uint8_t(leb128_fst_278 & id_1689) };
                                                                uint32_t id_1691 { uint32_t(id_1690) };
                                                                uint8_t id_1692 { 0 };
                                                                uint8_t id_1693 { shft_ref_275[id_1692] };
                                                                uint32_t id_1694 { uint32_t(id_1691 << id_1693) };
                                                                uint8_t id_1695 { 0 };
                                                                uint32_t id_1696 { leb_ref_274[id_1695] };
                                                                uint32_t id_1697 { uint32_t(id_1694 | id_1696) };
                                                                Void id_1698 { ((void)(leb_ref_274[id_1688] = id_1697), VOID) };
                                                                (void)id_1698;
                                                                uint8_t id_1699 { 0 };
                                                                uint8_t id_1700 { 0 };
                                                                uint8_t id_1701 { shft_ref_275[id_1700] };
                                                                uint8_t id_1702 { 7 };
                                                                uint8_t id_1703 { uint8_t(id_1701 + id_1702) };
                                                                Void id_1704 { ((void)(shft_ref_275[id_1699] = id_1703), VOID) };
                                                                (void)id_1704;
                                                                uint8_t id_1705 { 128 };
                                                                bool id_1706 { bool(leb128_fst_278 >= id_1705) };
                                                                letpair_res_1685 = id_1706;
                                                              }
                                                              let_res_1684 = letpair_res_1685;
                                                            }
                                                            while_flag_1680 = let_res_1684;
                                                            if (while_flag_1680) {
                                                              (void)VOID;
                                                            }
                                                          } while (while_flag_1680);
                                                          (void)VOID;
                                                          uint8_t id_1707 { 0 };
                                                          uint32_t id_1708 { leb_ref_274[id_1707] };
                                                          uint8_t id_1709 { 0 };
                                                          Pointer id_1710 { p_ref_276[id_1709] };
                                                          ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1711 { id_1708, id_1710 };
                                                          let_res_1679 = id_1711;
                                                        }
                                                        let_res_1677 = let_res_1679;
                                                      }
                                                      let_res_1674 = let_res_1677;
                                                    }
                                                    ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 let_res_1712;
                                                    {
                                                      ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 dlist1_283 { let_res_1674 };
                                                      ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 letpair_res_1713;
                                                      {
                                                        auto dlist1_fst_284 { std::get<0>(dlist1_283) };
                                                        auto dlist1_snd_285 { std::get<1>(dlist1_283) };
                                                        Lst<dessser::gen::field_name::t_ext> endoflist_1714;
                                                        ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1715 { endoflist_1714, dlist1_snd_285 };
                                                        Vec<1, ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967> id_1716 {  id_1715  };
                                                        ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 let_res_1717;
                                                        {
                                                          Vec<1, ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967> inits_src_ref_286 { id_1716 };
                                                          int32_t id_1718 { 0L };
                                                          Vec<1, int32_t> id_1719 {  id_1718  };
                                                          {
                                                            Vec<1, int32_t> repeat_n_287 { id_1719 };
                                                            bool while_flag_1720 { true };
                                                            do {
                                                              int32_t id_1721 { int32_t(dlist1_fst_284) };
                                                              uint8_t id_1722 { 0 };
                                                              int32_t id_1723 { repeat_n_287[id_1722] };
                                                              bool id_1724 { bool(id_1721 > id_1723) };
                                                              while_flag_1720 = id_1724;
                                                              if (while_flag_1720) {
                                                                uint8_t id_1725 { 0 };
                                                                ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1726 { inits_src_ref_286[id_1725] };
                                                                {
                                                                  ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 dlist2_288 { id_1726 };
                                                                  {
                                                                    auto dlist2_fst_289 { std::get<0>(dlist2_288) };
                                                                    auto dlist2_snd_290 { std::get<1>(dlist2_288) };
                                                                    uint8_t id_1727 { 0 };
                                                                    auto fun1728 { dessser::gen::field_name::of_row_binary };
                                                                    ::dessser::gen::alert::t273a2b7978f5b466a128a51c1cc4a27b id_1729 { fun1728(dlist2_snd_290) };
                                                                    ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 letpair_res_1730;
                                                                    {
                                                                      auto dlist3_fst_292 { std::get<0>(id_1729) };
                                                                      auto dlist3_snd_293 { std::get<1>(id_1729) };
                                                                      Lst<dessser::gen::field_name::t_ext> id_1731 { dlist3_fst_292, dlist2_fst_289 };
                                                                      ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1732 { id_1731, dlist3_snd_293 };
                                                                      letpair_res_1730 = id_1732;
                                                                    }
                                                                    Void id_1733 { ((void)(inits_src_ref_286[id_1727] = letpair_res_1730), VOID) };
                                                                    (void)id_1733;
                                                                  }
                                                                  (void)VOID;
                                                                }
                                                                (void)VOID;
                                                                uint8_t id_1734 { 0 };
                                                                uint8_t id_1735 { 0 };
                                                                int32_t id_1736 { repeat_n_287[id_1735] };
                                                                int32_t id_1737 { 1L };
                                                                int32_t id_1738 { int32_t(id_1736 + id_1737) };
                                                                Void id_1739 { ((void)(repeat_n_287[id_1734] = id_1738), VOID) };
                                                                (void)id_1739;
                                                                (void)id_1739;
                                                              }
                                                            } while (while_flag_1720);
                                                            (void)VOID;
                                                          }
                                                          (void)VOID;
                                                          uint8_t id_1740 { 0 };
                                                          ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1741 { inits_src_ref_286[id_1740] };
                                                          let_res_1717 = id_1741;
                                                        }
                                                        letpair_res_1713 = let_res_1717;
                                                      }
                                                      let_res_1712 = letpair_res_1713;
                                                    }
                                                    ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 letpair_res_1742;
                                                    {
                                                      auto dlist4_fst_295 { std::get<0>(let_res_1712) };
                                                      auto dlist4_snd_296 { std::get<1>(let_res_1712) };
                                                      ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 id_1743 { dlist4_fst_295, dlist4_snd_296 };
                                                      letpair_res_1742 = id_1743;
                                                    }
                                                    ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1744;
                                                    {
                                                      ::dessser::gen::alert::t0dfa866705b76efff53e4aa97228a967 drec_297 { letpair_res_1742 };
                                                      ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1745;
                                                      {
                                                        auto drec_fst_298 { std::get<0>(drec_297) };
                                                        auto drec_snd_299 { std::get<1>(drec_297) };
                                                        uint32_t id_1746 { 0U };
                                                        Vec<1, uint32_t> id_1747 {  id_1746  };
                                                        ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1748;
                                                        {
                                                          Vec<1, uint32_t> leb_ref_300 { id_1747 };
                                                          uint8_t id_1749 { 0 };
                                                          Vec<1, uint8_t> id_1750 {  id_1749  };
                                                          ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1751;
                                                          {
                                                            Vec<1, uint8_t> shft_ref_301 { id_1750 };
                                                            Vec<1, Pointer> id_1752 {  drec_snd_299  };
                                                            ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 let_res_1753;
                                                            {
                                                              Vec<1, Pointer> p_ref_302 { id_1752 };
                                                              bool while_flag_1754 { true };
                                                              do {
                                                                uint8_t id_1755 { 0 };
                                                                Pointer id_1756 { p_ref_302[id_1755] };
                                                                ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1757 { id_1756.readU8() };
                                                                bool let_res_1758;
                                                                {
                                                                  ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_303 { id_1757 };
                                                                  bool letpair_res_1759;
                                                                  {
                                                                    auto leb128_fst_304 { std::get<0>(leb128_303) };
                                                                    auto leb128_snd_305 { std::get<1>(leb128_303) };
                                                                    uint8_t id_1760 { 0 };
                                                                    Void id_1761 { ((void)(p_ref_302[id_1760] = leb128_snd_305), VOID) };
                                                                    (void)id_1761;
                                                                    uint8_t id_1762 { 0 };
                                                                    uint8_t id_1763 { 127 };
                                                                    uint8_t id_1764 { uint8_t(leb128_fst_304 & id_1763) };
                                                                    uint32_t id_1765 { uint32_t(id_1764) };
                                                                    uint8_t id_1766 { 0 };
                                                                    uint8_t id_1767 { shft_ref_301[id_1766] };
                                                                    uint32_t id_1768 { uint32_t(id_1765 << id_1767) };
                                                                    uint8_t id_1769 { 0 };
                                                                    uint32_t id_1770 { leb_ref_300[id_1769] };
                                                                    uint32_t id_1771 { uint32_t(id_1768 | id_1770) };
                                                                    Void id_1772 { ((void)(leb_ref_300[id_1762] = id_1771), VOID) };
                                                                    (void)id_1772;
                                                                    uint8_t id_1773 { 0 };
                                                                    uint8_t id_1774 { 0 };
                                                                    uint8_t id_1775 { shft_ref_301[id_1774] };
                                                                    uint8_t id_1776 { 7 };
                                                                    uint8_t id_1777 { uint8_t(id_1775 + id_1776) };
                                                                    Void id_1778 { ((void)(shft_ref_301[id_1773] = id_1777), VOID) };
                                                                    (void)id_1778;
                                                                    uint8_t id_1779 { 128 };
                                                                    bool id_1780 { bool(leb128_fst_304 >= id_1779) };
                                                                    letpair_res_1759 = id_1780;
                                                                  }
                                                                  let_res_1758 = letpair_res_1759;
                                                                }
                                                                while_flag_1754 = let_res_1758;
                                                                if (while_flag_1754) {
                                                                  (void)VOID;
                                                                }
                                                              } while (while_flag_1754);
                                                              (void)VOID;
                                                              uint8_t id_1781 { 0 };
                                                              uint32_t id_1782 { leb_ref_300[id_1781] };
                                                              uint8_t id_1783 { 0 };
                                                              Pointer id_1784 { p_ref_302[id_1783] };
                                                              ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 id_1785 { id_1782, id_1784 };
                                                              let_res_1753 = id_1785;
                                                            }
                                                            let_res_1751 = let_res_1753;
                                                          }
                                                          let_res_1748 = let_res_1751;
                                                        }
                                                        ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee let_res_1786;
                                                        {
                                                          ::dessser::gen::alert::t405eb186408556fed8f2c41523c07d13 dlist1_309 { let_res_1748 };
                                                          ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee letpair_res_1787;
                                                          {
                                                            auto dlist1_fst_310 { std::get<0>(dlist1_309) };
                                                            auto dlist1_snd_311 { std::get<1>(dlist1_309) };
                                                            Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> endoflist_1788;
                                                            ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee id_1789 { endoflist_1788, dlist1_snd_311 };
                                                            Vec<1, ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee> id_1790 {  id_1789  };
                                                            ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee let_res_1791;
                                                            {
                                                              Vec<1, ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee> inits_src_ref_312 { id_1790 };
                                                              int32_t id_1792 { 0L };
                                                              Vec<1, int32_t> id_1793 {  id_1792  };
                                                              {
                                                                Vec<1, int32_t> repeat_n_313 { id_1793 };
                                                                bool while_flag_1794 { true };
                                                                do {
                                                                  int32_t id_1795 { int32_t(dlist1_fst_310) };
                                                                  uint8_t id_1796 { 0 };
                                                                  int32_t id_1797 { repeat_n_313[id_1796] };
                                                                  bool id_1798 { bool(id_1795 > id_1797) };
                                                                  while_flag_1794 = id_1798;
                                                                  if (while_flag_1794) {
                                                                    uint8_t id_1799 { 0 };
                                                                    ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee id_1800 { inits_src_ref_312[id_1799] };
                                                                    {
                                                                      ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee dlist2_314 { id_1800 };
                                                                      {
                                                                        auto dlist2_fst_315 { std::get<0>(dlist2_314) };
                                                                        auto dlist2_snd_316 { std::get<1>(dlist2_314) };
                                                                        uint8_t id_1801 { 0 };
                                                                        auto fun1802 { dessser::gen::field_name::of_row_binary };
                                                                        ::dessser::gen::alert::t273a2b7978f5b466a128a51c1cc4a27b id_1803 { fun1802(dlist2_snd_316) };
                                                                        ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee let_res_1804;
                                                                        {
                                                                          ::dessser::gen::alert::t273a2b7978f5b466a128a51c1cc4a27b dtup_317 { id_1803 };
                                                                          ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee letpair_res_1805;
                                                                          {
                                                                            auto dtup_fst_318 { std::get<0>(dtup_317) };
                                                                            auto dtup_snd_319 { std::get<1>(dtup_317) };
                                                                            uint32_t id_1806 { 0U };
                                                                            Vec<1, uint32_t> id_1807 {  id_1806  };
                                                                            ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1808;
                                                                            {
                                                                              Vec<1, uint32_t> leb_ref_320 { id_1807 };
                                                                              uint8_t id_1809 { 0 };
                                                                              Vec<1, uint8_t> id_1810 {  id_1809  };
                                                                              ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1811;
                                                                              {
                                                                                Vec<1, uint8_t> shft_ref_321 { id_1810 };
                                                                                Vec<1, Pointer> id_1812 {  dtup_snd_319  };
                                                                                ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1813;
                                                                                {
                                                                                  Vec<1, Pointer> p_ref_322 { id_1812 };
                                                                                  bool while_flag_1814 { true };
                                                                                  do {
                                                                                    uint8_t id_1815 { 0 };
                                                                                    Pointer id_1816 { p_ref_322[id_1815] };
                                                                                    ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1817 { id_1816.readU8() };
                                                                                    bool let_res_1818;
                                                                                    {
                                                                                      ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_323 { id_1817 };
                                                                                      bool letpair_res_1819;
                                                                                      {
                                                                                        auto leb128_fst_324 { std::get<0>(leb128_323) };
                                                                                        auto leb128_snd_325 { std::get<1>(leb128_323) };
                                                                                        uint8_t id_1820 { 0 };
                                                                                        Void id_1821 { ((void)(p_ref_322[id_1820] = leb128_snd_325), VOID) };
                                                                                        (void)id_1821;
                                                                                        uint8_t id_1822 { 0 };
                                                                                        uint8_t id_1823 { 127 };
                                                                                        uint8_t id_1824 { uint8_t(leb128_fst_324 & id_1823) };
                                                                                        uint32_t id_1825 { uint32_t(id_1824) };
                                                                                        uint8_t id_1826 { 0 };
                                                                                        uint8_t id_1827 { shft_ref_321[id_1826] };
                                                                                        uint32_t id_1828 { uint32_t(id_1825 << id_1827) };
                                                                                        uint8_t id_1829 { 0 };
                                                                                        uint32_t id_1830 { leb_ref_320[id_1829] };
                                                                                        uint32_t id_1831 { uint32_t(id_1828 | id_1830) };
                                                                                        Void id_1832 { ((void)(leb_ref_320[id_1822] = id_1831), VOID) };
                                                                                        (void)id_1832;
                                                                                        uint8_t id_1833 { 0 };
                                                                                        uint8_t id_1834 { 0 };
                                                                                        uint8_t id_1835 { shft_ref_321[id_1834] };
                                                                                        uint8_t id_1836 { 7 };
                                                                                        uint8_t id_1837 { uint8_t(id_1835 + id_1836) };
                                                                                        Void id_1838 { ((void)(shft_ref_321[id_1833] = id_1837), VOID) };
                                                                                        (void)id_1838;
                                                                                        uint8_t id_1839 { 128 };
                                                                                        bool id_1840 { bool(leb128_fst_324 >= id_1839) };
                                                                                        letpair_res_1819 = id_1840;
                                                                                      }
                                                                                      let_res_1818 = letpair_res_1819;
                                                                                    }
                                                                                    while_flag_1814 = let_res_1818;
                                                                                    if (while_flag_1814) {
                                                                                      (void)VOID;
                                                                                    }
                                                                                  } while (while_flag_1814);
                                                                                  (void)VOID;
                                                                                  uint8_t id_1841 { 0 };
                                                                                  uint32_t id_1842 { leb_ref_320[id_1841] };
                                                                                  Size id_1843 { Size(id_1842) };
                                                                                  uint8_t id_1844 { 0 };
                                                                                  Pointer id_1845 { p_ref_322[id_1844] };
                                                                                  ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c id_1846 { id_1843, id_1845 };
                                                                                  let_res_1813 = id_1846;
                                                                                }
                                                                                let_res_1811 = let_res_1813;
                                                                              }
                                                                              let_res_1808 = let_res_1811;
                                                                            }
                                                                            ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee let_res_1847;
                                                                            {
                                                                              ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c dstring1_326 { let_res_1808 };
                                                                              ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee letpair_res_1848;
                                                                              {
                                                                                auto dstring1_fst_327 { std::get<0>(dstring1_326) };
                                                                                auto dstring1_snd_328 { std::get<1>(dstring1_326) };
                                                                                ::dessser::gen::alert::t188345aa49abd0cb47ff73fedc219f08 id_1849 { dstring1_snd_328.readBytes(dstring1_fst_327) };
                                                                                ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee letpair_res_1850;
                                                                                {
                                                                                  auto dstring2_fst_330 { std::get<0>(id_1849) };
                                                                                  auto dstring2_snd_331 { std::get<1>(id_1849) };
                                                                                  std::string id_1851 { dstring2_fst_330.toString() };
                                                                                  ::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d id_1852 { dtup_fst_318, id_1851 };
                                                                                  Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> id_1853 { id_1852, dlist2_fst_315 };
                                                                                  ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee id_1854 { id_1853, dstring2_snd_331 };
                                                                                  letpair_res_1850 = id_1854;
                                                                                }
                                                                                letpair_res_1848 = letpair_res_1850;
                                                                              }
                                                                              let_res_1847 = letpair_res_1848;
                                                                            }
                                                                            letpair_res_1805 = let_res_1847;
                                                                          }
                                                                          let_res_1804 = letpair_res_1805;
                                                                        }
                                                                        Void id_1855 { ((void)(inits_src_ref_312[id_1801] = let_res_1804), VOID) };
                                                                        (void)id_1855;
                                                                      }
                                                                      (void)VOID;
                                                                    }
                                                                    (void)VOID;
                                                                    uint8_t id_1856 { 0 };
                                                                    uint8_t id_1857 { 0 };
                                                                    int32_t id_1858 { repeat_n_313[id_1857] };
                                                                    int32_t id_1859 { 1L };
                                                                    int32_t id_1860 { int32_t(id_1858 + id_1859) };
                                                                    Void id_1861 { ((void)(repeat_n_313[id_1856] = id_1860), VOID) };
                                                                    (void)id_1861;
                                                                    (void)id_1861;
                                                                  }
                                                                } while (while_flag_1794);
                                                                (void)VOID;
                                                              }
                                                              (void)VOID;
                                                              uint8_t id_1862 { 0 };
                                                              ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee id_1863 { inits_src_ref_312[id_1862] };
                                                              let_res_1791 = id_1863;
                                                            }
                                                            letpair_res_1787 = let_res_1791;
                                                          }
                                                          let_res_1786 = letpair_res_1787;
                                                        }
                                                        ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee letpair_res_1864;
                                                        {
                                                          auto dlist4_fst_339 { std::get<0>(let_res_1786) };
                                                          auto dlist4_snd_340 { std::get<1>(let_res_1786) };
                                                          ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee id_1865 { dlist4_fst_339, dlist4_snd_340 };
                                                          letpair_res_1864 = id_1865;
                                                        }
                                                        ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1866;
                                                        {
                                                          ::dessser::gen::alert::ta2d5056f568236dc53d3d169e5b0b0ee drec_341 { letpair_res_1864 };
                                                          ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1867;
                                                          {
                                                            auto drec_fst_342 { std::get<0>(drec_341) };
                                                            auto drec_snd_343 { std::get<1>(drec_341) };
                                                            uint32_t id_1868 { 0U };
                                                            Vec<1, uint32_t> id_1869 {  id_1868  };
                                                            ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1870;
                                                            {
                                                              Vec<1, uint32_t> leb_ref_344 { id_1869 };
                                                              uint8_t id_1871 { 0 };
                                                              Vec<1, uint8_t> id_1872 {  id_1871  };
                                                              ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1873;
                                                              {
                                                                Vec<1, uint8_t> shft_ref_345 { id_1872 };
                                                                Vec<1, Pointer> id_1874 {  drec_snd_343  };
                                                                ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1875;
                                                                {
                                                                  Vec<1, Pointer> p_ref_346 { id_1874 };
                                                                  bool while_flag_1876 { true };
                                                                  do {
                                                                    uint8_t id_1877 { 0 };
                                                                    Pointer id_1878 { p_ref_346[id_1877] };
                                                                    ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1879 { id_1878.readU8() };
                                                                    bool let_res_1880;
                                                                    {
                                                                      ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_347 { id_1879 };
                                                                      bool letpair_res_1881;
                                                                      {
                                                                        auto leb128_fst_348 { std::get<0>(leb128_347) };
                                                                        auto leb128_snd_349 { std::get<1>(leb128_347) };
                                                                        uint8_t id_1882 { 0 };
                                                                        Void id_1883 { ((void)(p_ref_346[id_1882] = leb128_snd_349), VOID) };
                                                                        (void)id_1883;
                                                                        uint8_t id_1884 { 0 };
                                                                        uint8_t id_1885 { 127 };
                                                                        uint8_t id_1886 { uint8_t(leb128_fst_348 & id_1885) };
                                                                        uint32_t id_1887 { uint32_t(id_1886) };
                                                                        uint8_t id_1888 { 0 };
                                                                        uint8_t id_1889 { shft_ref_345[id_1888] };
                                                                        uint32_t id_1890 { uint32_t(id_1887 << id_1889) };
                                                                        uint8_t id_1891 { 0 };
                                                                        uint32_t id_1892 { leb_ref_344[id_1891] };
                                                                        uint32_t id_1893 { uint32_t(id_1890 | id_1892) };
                                                                        Void id_1894 { ((void)(leb_ref_344[id_1884] = id_1893), VOID) };
                                                                        (void)id_1894;
                                                                        uint8_t id_1895 { 0 };
                                                                        uint8_t id_1896 { 0 };
                                                                        uint8_t id_1897 { shft_ref_345[id_1896] };
                                                                        uint8_t id_1898 { 7 };
                                                                        uint8_t id_1899 { uint8_t(id_1897 + id_1898) };
                                                                        Void id_1900 { ((void)(shft_ref_345[id_1895] = id_1899), VOID) };
                                                                        (void)id_1900;
                                                                        uint8_t id_1901 { 128 };
                                                                        bool id_1902 { bool(leb128_fst_348 >= id_1901) };
                                                                        letpair_res_1881 = id_1902;
                                                                      }
                                                                      let_res_1880 = letpair_res_1881;
                                                                    }
                                                                    while_flag_1876 = let_res_1880;
                                                                    if (while_flag_1876) {
                                                                      (void)VOID;
                                                                    }
                                                                  } while (while_flag_1876);
                                                                  (void)VOID;
                                                                  uint8_t id_1903 { 0 };
                                                                  uint32_t id_1904 { leb_ref_344[id_1903] };
                                                                  Size id_1905 { Size(id_1904) };
                                                                  uint8_t id_1906 { 0 };
                                                                  Pointer id_1907 { p_ref_346[id_1906] };
                                                                  ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c id_1908 { id_1905, id_1907 };
                                                                  let_res_1875 = id_1908;
                                                                }
                                                                let_res_1873 = let_res_1875;
                                                              }
                                                              let_res_1870 = let_res_1873;
                                                            }
                                                            ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e let_res_1909;
                                                            {
                                                              ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c dstring1_350 { let_res_1870 };
                                                              ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1910;
                                                              {
                                                                auto dstring1_fst_351 { std::get<0>(dstring1_350) };
                                                                auto dstring1_snd_352 { std::get<1>(dstring1_350) };
                                                                ::dessser::gen::alert::t188345aa49abd0cb47ff73fedc219f08 id_1911 { dstring1_snd_352.readBytes(dstring1_fst_351) };
                                                                ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1912;
                                                                {
                                                                  auto dstring2_fst_354 { std::get<0>(id_1911) };
                                                                  auto dstring2_snd_355 { std::get<1>(id_1911) };
                                                                  std::string id_1913 { dstring2_fst_354.toString() };
                                                                  ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e id_1914 { id_1913, dstring2_snd_355 };
                                                                  letpair_res_1912 = id_1914;
                                                                }
                                                                letpair_res_1910 = letpair_res_1912;
                                                              }
                                                              let_res_1909 = letpair_res_1910;
                                                            }
                                                            ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1915;
                                                            {
                                                              ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e drec_356 { let_res_1909 };
                                                              ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1916;
                                                              {
                                                                auto drec_fst_357 { std::get<0>(drec_356) };
                                                                auto drec_snd_358 { std::get<1>(drec_356) };
                                                                uint32_t id_1917 { 0U };
                                                                Vec<1, uint32_t> id_1918 {  id_1917  };
                                                                ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1919;
                                                                {
                                                                  Vec<1, uint32_t> leb_ref_359 { id_1918 };
                                                                  uint8_t id_1920 { 0 };
                                                                  Vec<1, uint8_t> id_1921 {  id_1920  };
                                                                  ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1922;
                                                                  {
                                                                    Vec<1, uint8_t> shft_ref_360 { id_1921 };
                                                                    Vec<1, Pointer> id_1923 {  drec_snd_358  };
                                                                    ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1924;
                                                                    {
                                                                      Vec<1, Pointer> p_ref_361 { id_1923 };
                                                                      bool while_flag_1925 { true };
                                                                      do {
                                                                        uint8_t id_1926 { 0 };
                                                                        Pointer id_1927 { p_ref_361[id_1926] };
                                                                        ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1928 { id_1927.readU8() };
                                                                        bool let_res_1929;
                                                                        {
                                                                          ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_362 { id_1928 };
                                                                          bool letpair_res_1930;
                                                                          {
                                                                            auto leb128_fst_363 { std::get<0>(leb128_362) };
                                                                            auto leb128_snd_364 { std::get<1>(leb128_362) };
                                                                            uint8_t id_1931 { 0 };
                                                                            Void id_1932 { ((void)(p_ref_361[id_1931] = leb128_snd_364), VOID) };
                                                                            (void)id_1932;
                                                                            uint8_t id_1933 { 0 };
                                                                            uint8_t id_1934 { 127 };
                                                                            uint8_t id_1935 { uint8_t(leb128_fst_363 & id_1934) };
                                                                            uint32_t id_1936 { uint32_t(id_1935) };
                                                                            uint8_t id_1937 { 0 };
                                                                            uint8_t id_1938 { shft_ref_360[id_1937] };
                                                                            uint32_t id_1939 { uint32_t(id_1936 << id_1938) };
                                                                            uint8_t id_1940 { 0 };
                                                                            uint32_t id_1941 { leb_ref_359[id_1940] };
                                                                            uint32_t id_1942 { uint32_t(id_1939 | id_1941) };
                                                                            Void id_1943 { ((void)(leb_ref_359[id_1933] = id_1942), VOID) };
                                                                            (void)id_1943;
                                                                            uint8_t id_1944 { 0 };
                                                                            uint8_t id_1945 { 0 };
                                                                            uint8_t id_1946 { shft_ref_360[id_1945] };
                                                                            uint8_t id_1947 { 7 };
                                                                            uint8_t id_1948 { uint8_t(id_1946 + id_1947) };
                                                                            Void id_1949 { ((void)(shft_ref_360[id_1944] = id_1948), VOID) };
                                                                            (void)id_1949;
                                                                            uint8_t id_1950 { 128 };
                                                                            bool id_1951 { bool(leb128_fst_363 >= id_1950) };
                                                                            letpair_res_1930 = id_1951;
                                                                          }
                                                                          let_res_1929 = letpair_res_1930;
                                                                        }
                                                                        while_flag_1925 = let_res_1929;
                                                                        if (while_flag_1925) {
                                                                          (void)VOID;
                                                                        }
                                                                      } while (while_flag_1925);
                                                                      (void)VOID;
                                                                      uint8_t id_1952 { 0 };
                                                                      uint32_t id_1953 { leb_ref_359[id_1952] };
                                                                      Size id_1954 { Size(id_1953) };
                                                                      uint8_t id_1955 { 0 };
                                                                      Pointer id_1956 { p_ref_361[id_1955] };
                                                                      ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c id_1957 { id_1954, id_1956 };
                                                                      let_res_1924 = id_1957;
                                                                    }
                                                                    let_res_1922 = let_res_1924;
                                                                  }
                                                                  let_res_1919 = let_res_1922;
                                                                }
                                                                ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e let_res_1958;
                                                                {
                                                                  ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c dstring1_365 { let_res_1919 };
                                                                  ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1959;
                                                                  {
                                                                    auto dstring1_fst_366 { std::get<0>(dstring1_365) };
                                                                    auto dstring1_snd_367 { std::get<1>(dstring1_365) };
                                                                    ::dessser::gen::alert::t188345aa49abd0cb47ff73fedc219f08 id_1960 { dstring1_snd_367.readBytes(dstring1_fst_366) };
                                                                    ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1961;
                                                                    {
                                                                      auto dstring2_fst_369 { std::get<0>(id_1960) };
                                                                      auto dstring2_snd_370 { std::get<1>(id_1960) };
                                                                      std::string id_1962 { dstring2_fst_369.toString() };
                                                                      ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e id_1963 { id_1962, dstring2_snd_370 };
                                                                      letpair_res_1961 = id_1963;
                                                                    }
                                                                    letpair_res_1959 = letpair_res_1961;
                                                                  }
                                                                  let_res_1958 = letpair_res_1959;
                                                                }
                                                                ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_1964;
                                                                {
                                                                  ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e drec_371 { let_res_1958 };
                                                                  ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_1965;
                                                                  {
                                                                    auto drec_fst_372 { std::get<0>(drec_371) };
                                                                    auto drec_snd_373 { std::get<1>(drec_371) };
                                                                    uint32_t id_1966 { 0U };
                                                                    Vec<1, uint32_t> id_1967 {  id_1966  };
                                                                    ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1968;
                                                                    {
                                                                      Vec<1, uint32_t> leb_ref_374 { id_1967 };
                                                                      uint8_t id_1969 { 0 };
                                                                      Vec<1, uint8_t> id_1970 {  id_1969  };
                                                                      ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1971;
                                                                      {
                                                                        Vec<1, uint8_t> shft_ref_375 { id_1970 };
                                                                        Vec<1, Pointer> id_1972 {  drec_snd_373  };
                                                                        ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_1973;
                                                                        {
                                                                          Vec<1, Pointer> p_ref_376 { id_1972 };
                                                                          bool while_flag_1974 { true };
                                                                          do {
                                                                            uint8_t id_1975 { 0 };
                                                                            Pointer id_1976 { p_ref_376[id_1975] };
                                                                            ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_1977 { id_1976.readU8() };
                                                                            bool let_res_1978;
                                                                            {
                                                                              ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_377 { id_1977 };
                                                                              bool letpair_res_1979;
                                                                              {
                                                                                auto leb128_fst_378 { std::get<0>(leb128_377) };
                                                                                auto leb128_snd_379 { std::get<1>(leb128_377) };
                                                                                uint8_t id_1980 { 0 };
                                                                                Void id_1981 { ((void)(p_ref_376[id_1980] = leb128_snd_379), VOID) };
                                                                                (void)id_1981;
                                                                                uint8_t id_1982 { 0 };
                                                                                uint8_t id_1983 { 127 };
                                                                                uint8_t id_1984 { uint8_t(leb128_fst_378 & id_1983) };
                                                                                uint32_t id_1985 { uint32_t(id_1984) };
                                                                                uint8_t id_1986 { 0 };
                                                                                uint8_t id_1987 { shft_ref_375[id_1986] };
                                                                                uint32_t id_1988 { uint32_t(id_1985 << id_1987) };
                                                                                uint8_t id_1989 { 0 };
                                                                                uint32_t id_1990 { leb_ref_374[id_1989] };
                                                                                uint32_t id_1991 { uint32_t(id_1988 | id_1990) };
                                                                                Void id_1992 { ((void)(leb_ref_374[id_1982] = id_1991), VOID) };
                                                                                (void)id_1992;
                                                                                uint8_t id_1993 { 0 };
                                                                                uint8_t id_1994 { 0 };
                                                                                uint8_t id_1995 { shft_ref_375[id_1994] };
                                                                                uint8_t id_1996 { 7 };
                                                                                uint8_t id_1997 { uint8_t(id_1995 + id_1996) };
                                                                                Void id_1998 { ((void)(shft_ref_375[id_1993] = id_1997), VOID) };
                                                                                (void)id_1998;
                                                                                uint8_t id_1999 { 128 };
                                                                                bool id_2000 { bool(leb128_fst_378 >= id_1999) };
                                                                                letpair_res_1979 = id_2000;
                                                                              }
                                                                              let_res_1978 = letpair_res_1979;
                                                                            }
                                                                            while_flag_1974 = let_res_1978;
                                                                            if (while_flag_1974) {
                                                                              (void)VOID;
                                                                            }
                                                                          } while (while_flag_1974);
                                                                          (void)VOID;
                                                                          uint8_t id_2001 { 0 };
                                                                          uint32_t id_2002 { leb_ref_374[id_2001] };
                                                                          Size id_2003 { Size(id_2002) };
                                                                          uint8_t id_2004 { 0 };
                                                                          Pointer id_2005 { p_ref_376[id_2004] };
                                                                          ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c id_2006 { id_2003, id_2005 };
                                                                          let_res_1973 = id_2006;
                                                                        }
                                                                        let_res_1971 = let_res_1973;
                                                                      }
                                                                      let_res_1968 = let_res_1971;
                                                                    }
                                                                    ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e let_res_2007;
                                                                    {
                                                                      ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c dstring1_380 { let_res_1968 };
                                                                      ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2008;
                                                                      {
                                                                        auto dstring1_fst_381 { std::get<0>(dstring1_380) };
                                                                        auto dstring1_snd_382 { std::get<1>(dstring1_380) };
                                                                        ::dessser::gen::alert::t188345aa49abd0cb47ff73fedc219f08 id_2009 { dstring1_snd_382.readBytes(dstring1_fst_381) };
                                                                        ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2010;
                                                                        {
                                                                          auto dstring2_fst_384 { std::get<0>(id_2009) };
                                                                          auto dstring2_snd_385 { std::get<1>(id_2009) };
                                                                          std::string id_2011 { dstring2_fst_384.toString() };
                                                                          ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e id_2012 { id_2011, dstring2_snd_385 };
                                                                          letpair_res_2010 = id_2012;
                                                                        }
                                                                        letpair_res_2008 = letpair_res_2010;
                                                                      }
                                                                      let_res_2007 = letpair_res_2008;
                                                                    }
                                                                    ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_2013;
                                                                    {
                                                                      ::dessser::gen::alert::tef94b55d8809251f13165d9a05bd9d0e drec_386 { let_res_2007 };
                                                                      ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_2014;
                                                                      {
                                                                        auto drec_fst_387 { std::get<0>(drec_386) };
                                                                        auto drec_snd_388 { std::get<1>(drec_386) };
                                                                        uint32_t id_2015 { 0U };
                                                                        Vec<1, uint32_t> id_2016 {  id_2015  };
                                                                        ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_2017;
                                                                        {
                                                                          Vec<1, uint32_t> leb_ref_389 { id_2016 };
                                                                          uint8_t id_2018 { 0 };
                                                                          Vec<1, uint8_t> id_2019 {  id_2018  };
                                                                          ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_2020;
                                                                          {
                                                                            Vec<1, uint8_t> shft_ref_390 { id_2019 };
                                                                            Vec<1, Pointer> id_2021 {  drec_snd_388  };
                                                                            ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c let_res_2022;
                                                                            {
                                                                              Vec<1, Pointer> p_ref_391 { id_2021 };
                                                                              bool while_flag_2023 { true };
                                                                              do {
                                                                                uint8_t id_2024 { 0 };
                                                                                Pointer id_2025 { p_ref_391[id_2024] };
                                                                                ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 id_2026 { id_2025.readU8() };
                                                                                bool let_res_2027;
                                                                                {
                                                                                  ::dessser::gen::alert::tb3f98ea670610d40658a618de3ec7b90 leb128_392 { id_2026 };
                                                                                  bool letpair_res_2028;
                                                                                  {
                                                                                    auto leb128_fst_393 { std::get<0>(leb128_392) };
                                                                                    auto leb128_snd_394 { std::get<1>(leb128_392) };
                                                                                    uint8_t id_2029 { 0 };
                                                                                    Void id_2030 { ((void)(p_ref_391[id_2029] = leb128_snd_394), VOID) };
                                                                                    (void)id_2030;
                                                                                    uint8_t id_2031 { 0 };
                                                                                    uint8_t id_2032 { 127 };
                                                                                    uint8_t id_2033 { uint8_t(leb128_fst_393 & id_2032) };
                                                                                    uint32_t id_2034 { uint32_t(id_2033) };
                                                                                    uint8_t id_2035 { 0 };
                                                                                    uint8_t id_2036 { shft_ref_390[id_2035] };
                                                                                    uint32_t id_2037 { uint32_t(id_2034 << id_2036) };
                                                                                    uint8_t id_2038 { 0 };
                                                                                    uint32_t id_2039 { leb_ref_389[id_2038] };
                                                                                    uint32_t id_2040 { uint32_t(id_2037 | id_2039) };
                                                                                    Void id_2041 { ((void)(leb_ref_389[id_2031] = id_2040), VOID) };
                                                                                    (void)id_2041;
                                                                                    uint8_t id_2042 { 0 };
                                                                                    uint8_t id_2043 { 0 };
                                                                                    uint8_t id_2044 { shft_ref_390[id_2043] };
                                                                                    uint8_t id_2045 { 7 };
                                                                                    uint8_t id_2046 { uint8_t(id_2044 + id_2045) };
                                                                                    Void id_2047 { ((void)(shft_ref_390[id_2042] = id_2046), VOID) };
                                                                                    (void)id_2047;
                                                                                    uint8_t id_2048 { 128 };
                                                                                    bool id_2049 { bool(leb128_fst_393 >= id_2048) };
                                                                                    letpair_res_2028 = id_2049;
                                                                                  }
                                                                                  let_res_2027 = letpair_res_2028;
                                                                                }
                                                                                while_flag_2023 = let_res_2027;
                                                                                if (while_flag_2023) {
                                                                                  (void)VOID;
                                                                                }
                                                                              } while (while_flag_2023);
                                                                              (void)VOID;
                                                                              uint8_t id_2050 { 0 };
                                                                              uint32_t id_2051 { leb_ref_389[id_2050] };
                                                                              Size id_2052 { Size(id_2051) };
                                                                              uint8_t id_2053 { 0 };
                                                                              Pointer id_2054 { p_ref_391[id_2053] };
                                                                              ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c id_2055 { id_2052, id_2054 };
                                                                              let_res_2022 = id_2055;
                                                                            }
                                                                            let_res_2020 = let_res_2022;
                                                                          }
                                                                          let_res_2017 = let_res_2020;
                                                                        }
                                                                        ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 let_res_2056;
                                                                        {
                                                                          ::dessser::gen::alert::t8beb80162423aee37bd383e9b6834c9c dstring1_395 { let_res_2017 };
                                                                          ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_2057;
                                                                          {
                                                                            auto dstring1_fst_396 { std::get<0>(dstring1_395) };
                                                                            auto dstring1_snd_397 { std::get<1>(dstring1_395) };
                                                                            ::dessser::gen::alert::t188345aa49abd0cb47ff73fedc219f08 id_2058 { dstring1_snd_397.readBytes(dstring1_fst_396) };
                                                                            ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 letpair_res_2059;
                                                                            {
                                                                              auto dstring2_fst_399 { std::get<0>(id_2058) };
                                                                              auto dstring2_snd_400 { std::get<1>(id_2058) };
                                                                              std::string id_2060 { dstring2_fst_399.toString() };
                                                                              ::dessser::gen::alert::t* id_2061 { new ::dessser::gen::alert::t({ .carry_csts = drec_fst_342, .carry_fields = drec_fst_298, .column = drec_fst_60, .desc_firing = drec_fst_387, .desc_recovery = id_2060, .desc_title = drec_fst_372, .duration = drec_fst_234, .enabled = drec_fst_66, .group_by = drec_fst_121, .having = drec_fst_147, .hysteresis = drec_fst_228, .id = drec_fst_357, .ratio = drec_fst_240, .table = drec_fst_57, .threshold = drec_fst_222, .time_step = drec_fst_246, .tops = drec_fst_272, .where = drec_fst_92 }) };
                                                                              ::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337 id_2062 { id_2061, dstring2_snd_400 };
                                                                              letpair_res_2059 = id_2062;
                                                                            }
                                                                            letpair_res_2057 = letpair_res_2059;
                                                                          }
                                                                          let_res_2056 = letpair_res_2057;
                                                                        }
                                                                        letpair_res_2014 = let_res_2056;
                                                                      }
                                                                      let_res_2013 = letpair_res_2014;
                                                                    }
                                                                    letpair_res_1965 = let_res_2013;
                                                                  }
                                                                  let_res_1964 = letpair_res_1965;
                                                                }
                                                                letpair_res_1916 = let_res_1964;
                                                              }
                                                              let_res_1915 = letpair_res_1916;
                                                            }
                                                            letpair_res_1867 = let_res_1915;
                                                          }
                                                          let_res_1866 = letpair_res_1867;
                                                        }
                                                        letpair_res_1745 = let_res_1866;
                                                      }
                                                      let_res_1744 = letpair_res_1745;
                                                    }
                                                    letpair_res_1671 = let_res_1744;
                                                  }
                                                  let_res_1670 = letpair_res_1671;
                                                }
                                                letpair_res_1597 = let_res_1670;
                                              }
                                              let_res_1596 = letpair_res_1597;
                                            }
                                            letpair_res_1591 = let_res_1596;
                                          }
                                          let_res_1590 = letpair_res_1591;
                                        }
                                        letpair_res_1585 = let_res_1590;
                                      }
                                      let_res_1584 = letpair_res_1585;
                                    }
                                    letpair_res_1579 = let_res_1584;
                                  }
                                  let_res_1578 = letpair_res_1579;
                                }
                                letpair_res_1573 = let_res_1578;
                              }
                              let_res_1572 = letpair_res_1573;
                            }
                            letpair_res_1502 = let_res_1572;
                          }
                          let_res_1501 = letpair_res_1502;
                        }
                        letpair_res_1428 = let_res_1501;
                      }
                      let_res_1427 = letpair_res_1428;
                    }
                    letpair_res_1342 = let_res_1427;
                  }
                  let_res_1341 = letpair_res_1342;
                }
                letpair_res_1268 = let_res_1341;
              }
              let_res_1267 = letpair_res_1268;
            }
            letpair_res_1260 = let_res_1267;
          }
          let_res_1259 = letpair_res_1260;
        }
        letpair_res_1256 = let_res_1259;
      }
      let_res_1255 = letpair_res_1256;
    }
    return let_res_1255;
  }
   };
  return fun1252;
}
std::function<::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
