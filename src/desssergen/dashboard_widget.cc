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

namespace dessser::gen::dashboard_widget {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct tc758d36a6b58d564436d5e1104817704 : public std::variant<
  Void, // Unused
  Void, // Independent
  Void, // Stacked
  Void // StackCentered
> { using variant::variant; };

struct t4014451f4abcdfd5489869fefe1eca82 {
  uint8_t axis;
  uint32_t color;
  std::string column;
  Arr<std::string> factors;
  double opacity;
  ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 representation;
  t4014451f4abcdfd5489869fefe1eca82(uint8_t axis_, uint32_t color_, std::string column_, Arr<std::string> factors_, double opacity_, ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 representation_) : axis(axis_), color(color_), column(column_), factors(factors_), opacity(opacity_), representation(representation_) {}
  t4014451f4abcdfd5489869fefe1eca82() = default;
};
struct source {
  Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> fields;
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  source(Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> fields_, dessser::gen::fq_function_name::t_ext name_, bool visible_) : fields(fields_), name(name_), visible(visible_) {}
  source() = default;
};
struct scale : public std::variant<
  Void, // Linear
  Void // Logarithmic
> { using variant::variant; };

struct axis {
  bool force_zero;
  bool left;
  std::shared_ptr<::dessser::gen::dashboard_widget::scale>  scale;
  axis(bool force_zero_, bool left_, std::shared_ptr<::dessser::gen::dashboard_widget::scale>  scale_) : force_zero(force_zero_), left(left_), scale(scale_) {}
  axis() = default;
};
struct type : public std::variant<
  Void // Plot
> { using variant::variant; };

struct chart {
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > axes;
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > sources;
  std::string title;
  std::shared_ptr<::dessser::gen::dashboard_widget::type>  type;
  chart(Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > axes_, Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > sources_, std::string title_, std::shared_ptr<::dessser::gen::dashboard_widget::type>  type_) : axes(axes_), sources(sources_), title(title_), type(type_) {}
  chart() = default;
};
struct t : public std::variant<
  std::string, // Text
  std::shared_ptr<::dessser::gen::dashboard_widget::chart>  // Chart
> { using variant::variant; };

struct t97cba01e43a21515748b36fb32be3b3e : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::source> ,
  Pointer
> {
  using tuple::tuple;
  t97cba01e43a21515748b36fb32be3b3e(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::source> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::source> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tc67a116b5bcd191e2624b1f2b2b1794a : public std::tuple<
  dessser::gen::fq_function_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tc67a116b5bcd191e2624b1f2b2b1794a(std::tuple<dessser::gen::fq_function_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_function_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t8f6cce063b0da10e7eea29b507eded2e : public std::tuple<
  bool,
  Pointer
> {
  using tuple::tuple;
  t8f6cce063b0da10e7eea29b507eded2e(std::tuple<bool, Pointer> p)
    : std::tuple<bool, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t3fd42cf02103165757b46133ec4aa4a0 : public std::tuple<
  Lst<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82>,
  Pointer
> {
  using tuple::tuple;
  t3fd42cf02103165757b46133ec4aa4a0(std::tuple<Lst<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tf568409f41c9c0a265f7302110fc9084 : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  tf568409f41c9c0a265f7302110fc9084(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5375de390f9cb5ae2ee5880ea1674828 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t5375de390f9cb5ae2ee5880ea1674828(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tf0dc70c5b7a2a10580e331c050ed9881 : public std::tuple<
  ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704,
  Pointer
> {
  using tuple::tuple;
  tf0dc70c5b7a2a10580e331c050ed9881(std::tuple<::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704, Pointer> p)
    : std::tuple<::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t3fd8221434e489b54b5c4356ebff5005 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t3fd8221434e489b54b5c4356ebff5005(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t97f2951ce89391326d7f22e0db17439d : public std::tuple<
  Lst<std::string>,
  Pointer
> {
  using tuple::tuple;
  t97f2951ce89391326d7f22e0db17439d(std::tuple<Lst<std::string>, Pointer> p)
    : std::tuple<Lst<std::string>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tae8f20319160c4730608853dfb7fd182 : public std::tuple<
  Arr<std::string>,
  Pointer
> {
  using tuple::tuple;
  tae8f20319160c4730608853dfb7fd182(std::tuple<Arr<std::string>, Pointer> p)
    : std::tuple<Arr<std::string>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tf9ef46e559cc4aa51a61b6310df405c7 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,
  Pointer
> {
  using tuple::tuple;
  tf9ef46e559cc4aa51a61b6310df405c7(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::scale> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::scale> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t6ac8518a7138f46f9eb6363b25e26552 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,
  Pointer
> {
  using tuple::tuple;
  t6ac8518a7138f46f9eb6363b25e26552(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::axis> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::axis> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tb8736edae5c2876425e55b9d652a8681 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::type> ,
  Pointer
> {
  using tuple::tuple;
  tb8736edae5c2876425e55b9d652a8681(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::type> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::type> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tef7a76372bf1c1fa490f519ad932fc70 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,
  Pointer
> {
  using tuple::tuple;
  tef7a76372bf1c1fa490f519ad932fc70(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::chart> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::chart> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t589749b27ef8c95365b7c84b8d0c65b3 : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::dashboard_widget::axis> >,
  Pointer
> {
  using tuple::tuple;
  t589749b27ef8c95365b7c84b8d0c65b3(std::tuple<Lst<std::shared_ptr<::dessser::gen::dashboard_widget::axis> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::dashboard_widget::axis> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tb55c7f64967782dbcd42b37a9d7d6eed : public std::tuple<
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> >,
  Pointer
> {
  using tuple::tuple;
  tb55c7f64967782dbcd42b37a9d7d6eed(std::tuple<Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> >, Pointer> p)
    : std::tuple<Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct ta2a89e8ea0837477e804ea533f6f5569 : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::dashboard_widget::source> >,
  Pointer
> {
  using tuple::tuple;
  ta2a89e8ea0837477e804ea533f6f5569(std::tuple<Lst<std::shared_ptr<::dessser::gen::dashboard_widget::source> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::dashboard_widget::source> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t206086bb48fe7c1f7a2a1b42bad30939 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::t> ,
  Pointer
> {
  using tuple::tuple;
  t206086bb48fe7c1f7a2a1b42bad30939(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]}" "Ptr")
      (let "srec_dst_398" (let "srec_dst_397" (apply (ext-identifier fq_function_name to-row-binary) (get-field "name" (param 0)) (param 1)) (write-u8 (identifier "srec_dst_397") (u8-of-bool (get-field "visible" (param 0)))))
        (let "dst_ref_401"
          (make-vec
            (let "leb128_sz_399" (make-vec (cardinality (get-field "fields" (param 0))))
              (let "leb128_ptr_400" (make-vec (identifier "srec_dst_398"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_400")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_400"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_399"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_399"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_399"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_399") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_399")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_399")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_400"))))))
          (let "n_ref_402" (make-vec (i32 0))
            (seq
              (for-each "x_403" (get-field "fields" (param 0))
                (seq
                  (set-vec (u8 0) (identifier "dst_ref_401")
                    (let "srec_dst_420"
                      (let "srec_dst_412"
                        (let "srec_dst_409"
                          (let "srec_dst_406"
                            (let "srec_dst_405" (let "srec_dst_404" (unsafe-nth (u8 0) (identifier "dst_ref_401")) (write-u64 little-endian (identifier "srec_dst_404") (u64-of-float (get-field "opacity" (identifier "x_403")))))
                              (write-u32 little-endian (identifier "srec_dst_405") (get-field "color" (identifier "x_403"))))
                            (let "ssum_dst_408" (write-u16 little-endian (identifier "srec_dst_406") (label-of (get-field "representation" (identifier "x_403"))))
                              (if (eq (u16 0) (label-of (get-field "representation" (identifier "x_403")))) 
                                (identifier "ssum_dst_408")
                                (if (eq (u16 1) (label-of (get-field "representation" (identifier "x_403")))) 
                                  (identifier "ssum_dst_408")
                                  (if (eq (u16 2) (label-of (get-field "representation" (identifier "x_403")))) 
                                    (identifier "ssum_dst_408") (seq (assert (eq (label-of (get-field "representation" (identifier "x_403"))) (u16 3))) (identifier "ssum_dst_408")))))))
                          (write-bytes
                            (let "leb128_sz_410" (make-vec (string-length (get-field "column" (identifier "x_403"))))
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
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_411"))))) 
                            (bytes-of-string (get-field "column" (identifier "x_403")))))
                        (let "dst_ref_415"
                          (make-vec
                            (let "leb128_sz_413" (make-vec (cardinality (get-field "factors" (identifier "x_403"))))
                              (let "leb128_ptr_414" (make-vec (identifier "srec_dst_412"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_414")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_414"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_413"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_413"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_413"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_413") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_413")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_413")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_414"))))))
                          (let "n_ref_416" (make-vec (i32 0))
                            (seq
                              (for-each "x_417" (get-field "factors" (identifier "x_403"))
                                (seq
                                  (set-vec (u8 0) (identifier "dst_ref_415")
                                    (write-bytes
                                      (let "leb128_sz_418" (make-vec (string-length (identifier "x_417")))
                                        (let "leb128_ptr_419" (make-vec (unsafe-nth (u8 0) (identifier "dst_ref_415")))
                                          (seq
                                            (while
                                              (seq
                                                (set-vec (u8 0) (identifier "leb128_ptr_419")
                                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_419"))
                                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_418"))) 
                                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_418"))) 
                                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_418"))) (u8 128)))))
                                                (set-vec (u8 0) (identifier "leb128_sz_418") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_418")) (u8 7))) 
                                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_418")) (u32 0))) 
                                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_419"))))) 
                                      (bytes-of-string (identifier "x_417")))) 
                                  (set-vec (u8 0) (identifier "n_ref_416") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_416")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_415")))))) 
                      (write-u8 (identifier "srec_dst_420") (get-field "axis" (identifier "x_403"))))) 
                  (set-vec (u8 0) (identifier "n_ref_402") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_402")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_401")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::source> ,Pointer)> source_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::source> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::dashboard_widget::source>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::fq_function_name::to_row_binary };
    dessser::gen::fq_function_name::t_ext id_2 { (*p_0).name };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_397 { id_3 };
      bool id_5 { (*p_0).visible };
      uint8_t id_6 { uint8_t(id_5) };
      Pointer id_7 { srec_dst_397.writeU8(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_398 { let_res_4 };
      Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_9 { (*p_0).fields };
      uint32_t id_10 { id_9.size() };
      Vec<1, uint32_t> id_11 {  id_10  };
      Pointer let_res_12;
      {
        Vec<1, uint32_t> leb128_sz_399 { id_11 };
        Vec<1, Pointer> id_13 {  srec_dst_398  };
        Pointer let_res_14;
        {
          Vec<1, Pointer> leb128_ptr_400 { id_13 };
          bool while_flag_15 { true };
          do {
            uint8_t id_16 { 0 };
            uint8_t id_17 { 0 };
            Pointer id_18 { leb128_ptr_400[id_17] };
            uint32_t id_19 { 128U };
            uint8_t id_20 { 0 };
            uint32_t id_21 { leb128_sz_399[id_20] };
            bool id_22 { bool(id_19 > id_21) };
            uint8_t choose_res_23;
            if (id_22) {
              uint8_t id_24 { 0 };
              uint32_t id_25 { leb128_sz_399[id_24] };
              uint8_t id_26 { uint8_t(id_25) };
              choose_res_23 = id_26;
            } else {
              uint8_t id_27 { 0 };
              uint32_t id_28 { leb128_sz_399[id_27] };
              uint8_t id_29 { uint8_t(id_28) };
              uint8_t id_30 { 128 };
              uint8_t id_31 { uint8_t(id_29 | id_30) };
              choose_res_23 = id_31;
            }
            Pointer id_32 { id_18.writeU8(choose_res_23) };
            Void id_33 { ((void)(leb128_ptr_400[id_16] = id_32), ::dessser::VOID) };
            (void)id_33;
            uint8_t id_34 { 0 };
            uint8_t id_35 { 0 };
            uint32_t id_36 { leb128_sz_399[id_35] };
            uint8_t id_37 { 7 };
            uint32_t id_38 { uint32_t(id_36 >> id_37) };
            Void id_39 { ((void)(leb128_sz_399[id_34] = id_38), ::dessser::VOID) };
            (void)id_39;
            uint8_t id_40 { 0 };
            uint32_t id_41 { leb128_sz_399[id_40] };
            uint32_t id_42 { 0U };
            bool id_43 { bool(id_41 > id_42) };
            while_flag_15 = id_43;
            if (while_flag_15) {
              (void)::dessser::VOID;
            }
          } while (while_flag_15);
          (void)::dessser::VOID;
          uint8_t id_44 { 0 };
          Pointer id_45 { leb128_ptr_400[id_44] };
          let_res_14 = id_45;
        }
        let_res_12 = let_res_14;
      }
      Vec<1, Pointer> id_46 {  let_res_12  };
      Pointer let_res_47;
      {
        Vec<1, Pointer> dst_ref_401 { id_46 };
        int32_t id_48 { 0L };
        Vec<1, int32_t> id_49 {  id_48  };
        Pointer let_res_50;
        {
          Vec<1, int32_t> n_ref_402 { id_49 };
          Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_51 { (*p_0).fields };
          for (::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 x_403 : id_51) {
            uint8_t id_52 { 0 };
            uint8_t id_53 { 0 };
            Pointer id_54 { dst_ref_401[id_53] };
            Pointer let_res_55;
            {
              Pointer srec_dst_404 { id_54 };
              double id_56 { x_403.opacity };
              uint64_t id_57 { qword_of_float(id_56) };
              Pointer id_58 { srec_dst_404.writeU64Le(id_57) };
              let_res_55 = id_58;
            }
            Pointer let_res_59;
            {
              Pointer srec_dst_405 { let_res_55 };
              uint32_t id_60 { x_403.color };
              Pointer id_61 { srec_dst_405.writeU32Le(id_60) };
              let_res_59 = id_61;
            }
            Pointer let_res_62;
            {
              Pointer srec_dst_406 { let_res_59 };
              ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_63 { x_403.representation };
              uint16_t id_64 { uint16_t(id_63.index()) };
              Pointer id_65 { srec_dst_406.writeU16Le(id_64) };
              Pointer let_res_66;
              {
                Pointer ssum_dst_408 { id_65 };
                uint16_t id_67 { 0 };
                ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_68 { x_403.representation };
                uint16_t id_69 { uint16_t(id_68.index()) };
                bool id_70 { bool(id_67 == id_69) };
                Pointer choose_res_71;
                if (id_70) {
                  choose_res_71 = ssum_dst_408;
                } else {
                  uint16_t id_72 { 1 };
                  ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_73 { x_403.representation };
                  uint16_t id_74 { uint16_t(id_73.index()) };
                  bool id_75 { bool(id_72 == id_74) };
                  Pointer choose_res_76;
                  if (id_75) {
                    choose_res_76 = ssum_dst_408;
                  } else {
                    uint16_t id_77 { 2 };
                    ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_78 { x_403.representation };
                    uint16_t id_79 { uint16_t(id_78.index()) };
                    bool id_80 { bool(id_77 == id_79) };
                    Pointer choose_res_81;
                    if (id_80) {
                      choose_res_81 = ssum_dst_408;
                    } else {
                      ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_82 { x_403.representation };
                      uint16_t id_83 { uint16_t(id_82.index()) };
                      uint16_t id_84 { 3 };
                      bool id_85 { bool(id_83 == id_84) };
                      Void id_86 { ((void)(assert(id_85)), ::dessser::VOID) };
                      (void)id_86;
                      choose_res_81 = ssum_dst_408;
                    }
                    choose_res_76 = choose_res_81;
                  }
                  choose_res_71 = choose_res_76;
                }
                let_res_66 = choose_res_71;
              }
              let_res_62 = let_res_66;
            }
            Pointer let_res_87;
            {
              Pointer srec_dst_409 { let_res_62 };
              std::string id_88 { x_403.column };
              uint32_t id_89 { (uint32_t)id_88.size() };
              Vec<1, uint32_t> id_90 {  id_89  };
              Pointer let_res_91;
              {
                Vec<1, uint32_t> leb128_sz_410 { id_90 };
                Vec<1, Pointer> id_92 {  srec_dst_409  };
                Pointer let_res_93;
                {
                  Vec<1, Pointer> leb128_ptr_411 { id_92 };
                  bool while_flag_94 { true };
                  do {
                    uint8_t id_95 { 0 };
                    uint8_t id_96 { 0 };
                    Pointer id_97 { leb128_ptr_411[id_96] };
                    uint32_t id_98 { 128U };
                    uint8_t id_99 { 0 };
                    uint32_t id_100 { leb128_sz_410[id_99] };
                    bool id_101 { bool(id_98 > id_100) };
                    uint8_t choose_res_102;
                    if (id_101) {
                      uint8_t id_103 { 0 };
                      uint32_t id_104 { leb128_sz_410[id_103] };
                      uint8_t id_105 { uint8_t(id_104) };
                      choose_res_102 = id_105;
                    } else {
                      uint8_t id_106 { 0 };
                      uint32_t id_107 { leb128_sz_410[id_106] };
                      uint8_t id_108 { uint8_t(id_107) };
                      uint8_t id_109 { 128 };
                      uint8_t id_110 { uint8_t(id_108 | id_109) };
                      choose_res_102 = id_110;
                    }
                    Pointer id_111 { id_97.writeU8(choose_res_102) };
                    Void id_112 { ((void)(leb128_ptr_411[id_95] = id_111), ::dessser::VOID) };
                    (void)id_112;
                    uint8_t id_113 { 0 };
                    uint8_t id_114 { 0 };
                    uint32_t id_115 { leb128_sz_410[id_114] };
                    uint8_t id_116 { 7 };
                    uint32_t id_117 { uint32_t(id_115 >> id_116) };
                    Void id_118 { ((void)(leb128_sz_410[id_113] = id_117), ::dessser::VOID) };
                    (void)id_118;
                    uint8_t id_119 { 0 };
                    uint32_t id_120 { leb128_sz_410[id_119] };
                    uint32_t id_121 { 0U };
                    bool id_122 { bool(id_120 > id_121) };
                    while_flag_94 = id_122;
                    if (while_flag_94) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_94);
                  (void)::dessser::VOID;
                  uint8_t id_123 { 0 };
                  Pointer id_124 { leb128_ptr_411[id_123] };
                  let_res_93 = id_124;
                }
                let_res_91 = let_res_93;
              }
              std::string id_125 { x_403.column };
              Bytes id_126 { id_125 };
              Pointer id_127 { let_res_91.writeBytes(id_126) };
              let_res_87 = id_127;
            }
            Pointer let_res_128;
            {
              Pointer srec_dst_412 { let_res_87 };
              Arr<std::string> id_129 { x_403.factors };
              uint32_t id_130 { id_129.size() };
              Vec<1, uint32_t> id_131 {  id_130  };
              Pointer let_res_132;
              {
                Vec<1, uint32_t> leb128_sz_413 { id_131 };
                Vec<1, Pointer> id_133 {  srec_dst_412  };
                Pointer let_res_134;
                {
                  Vec<1, Pointer> leb128_ptr_414 { id_133 };
                  bool while_flag_135 { true };
                  do {
                    uint8_t id_136 { 0 };
                    uint8_t id_137 { 0 };
                    Pointer id_138 { leb128_ptr_414[id_137] };
                    uint32_t id_139 { 128U };
                    uint8_t id_140 { 0 };
                    uint32_t id_141 { leb128_sz_413[id_140] };
                    bool id_142 { bool(id_139 > id_141) };
                    uint8_t choose_res_143;
                    if (id_142) {
                      uint8_t id_144 { 0 };
                      uint32_t id_145 { leb128_sz_413[id_144] };
                      uint8_t id_146 { uint8_t(id_145) };
                      choose_res_143 = id_146;
                    } else {
                      uint8_t id_147 { 0 };
                      uint32_t id_148 { leb128_sz_413[id_147] };
                      uint8_t id_149 { uint8_t(id_148) };
                      uint8_t id_150 { 128 };
                      uint8_t id_151 { uint8_t(id_149 | id_150) };
                      choose_res_143 = id_151;
                    }
                    Pointer id_152 { id_138.writeU8(choose_res_143) };
                    Void id_153 { ((void)(leb128_ptr_414[id_136] = id_152), ::dessser::VOID) };
                    (void)id_153;
                    uint8_t id_154 { 0 };
                    uint8_t id_155 { 0 };
                    uint32_t id_156 { leb128_sz_413[id_155] };
                    uint8_t id_157 { 7 };
                    uint32_t id_158 { uint32_t(id_156 >> id_157) };
                    Void id_159 { ((void)(leb128_sz_413[id_154] = id_158), ::dessser::VOID) };
                    (void)id_159;
                    uint8_t id_160 { 0 };
                    uint32_t id_161 { leb128_sz_413[id_160] };
                    uint32_t id_162 { 0U };
                    bool id_163 { bool(id_161 > id_162) };
                    while_flag_135 = id_163;
                    if (while_flag_135) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_135);
                  (void)::dessser::VOID;
                  uint8_t id_164 { 0 };
                  Pointer id_165 { leb128_ptr_414[id_164] };
                  let_res_134 = id_165;
                }
                let_res_132 = let_res_134;
              }
              Vec<1, Pointer> id_166 {  let_res_132  };
              Pointer let_res_167;
              {
                Vec<1, Pointer> dst_ref_415 { id_166 };
                int32_t id_168 { 0L };
                Vec<1, int32_t> id_169 {  id_168  };
                Pointer let_res_170;
                {
                  Vec<1, int32_t> n_ref_416 { id_169 };
                  Arr<std::string> id_171 { x_403.factors };
                  for (std::string x_417 : id_171) {
                    uint8_t id_172 { 0 };
                    uint32_t id_173 { (uint32_t)x_417.size() };
                    Vec<1, uint32_t> id_174 {  id_173  };
                    Pointer let_res_175;
                    {
                      Vec<1, uint32_t> leb128_sz_418 { id_174 };
                      uint8_t id_176 { 0 };
                      Pointer id_177 { dst_ref_415[id_176] };
                      Vec<1, Pointer> id_178 {  id_177  };
                      Pointer let_res_179;
                      {
                        Vec<1, Pointer> leb128_ptr_419 { id_178 };
                        bool while_flag_180 { true };
                        do {
                          uint8_t id_181 { 0 };
                          uint8_t id_182 { 0 };
                          Pointer id_183 { leb128_ptr_419[id_182] };
                          uint32_t id_184 { 128U };
                          uint8_t id_185 { 0 };
                          uint32_t id_186 { leb128_sz_418[id_185] };
                          bool id_187 { bool(id_184 > id_186) };
                          uint8_t choose_res_188;
                          if (id_187) {
                            uint8_t id_189 { 0 };
                            uint32_t id_190 { leb128_sz_418[id_189] };
                            uint8_t id_191 { uint8_t(id_190) };
                            choose_res_188 = id_191;
                          } else {
                            uint8_t id_192 { 0 };
                            uint32_t id_193 { leb128_sz_418[id_192] };
                            uint8_t id_194 { uint8_t(id_193) };
                            uint8_t id_195 { 128 };
                            uint8_t id_196 { uint8_t(id_194 | id_195) };
                            choose_res_188 = id_196;
                          }
                          Pointer id_197 { id_183.writeU8(choose_res_188) };
                          Void id_198 { ((void)(leb128_ptr_419[id_181] = id_197), ::dessser::VOID) };
                          (void)id_198;
                          uint8_t id_199 { 0 };
                          uint8_t id_200 { 0 };
                          uint32_t id_201 { leb128_sz_418[id_200] };
                          uint8_t id_202 { 7 };
                          uint32_t id_203 { uint32_t(id_201 >> id_202) };
                          Void id_204 { ((void)(leb128_sz_418[id_199] = id_203), ::dessser::VOID) };
                          (void)id_204;
                          uint8_t id_205 { 0 };
                          uint32_t id_206 { leb128_sz_418[id_205] };
                          uint32_t id_207 { 0U };
                          bool id_208 { bool(id_206 > id_207) };
                          while_flag_180 = id_208;
                          if (while_flag_180) {
                            (void)::dessser::VOID;
                          }
                        } while (while_flag_180);
                        (void)::dessser::VOID;
                        uint8_t id_209 { 0 };
                        Pointer id_210 { leb128_ptr_419[id_209] };
                        let_res_179 = id_210;
                      }
                      let_res_175 = let_res_179;
                    }
                    Bytes id_211 { x_417 };
                    Pointer id_212 { let_res_175.writeBytes(id_211) };
                    Void id_213 { ((void)(dst_ref_415[id_172] = id_212), ::dessser::VOID) };
                    (void)id_213;
                    uint8_t id_214 { 0 };
                    int32_t id_215 { 1L };
                    uint8_t id_216 { 0 };
                    int32_t id_217 { n_ref_416[id_216] };
                    int32_t id_218 { int32_t(id_215 + id_217) };
                    Void id_219 { ((void)(n_ref_416[id_214] = id_218), ::dessser::VOID) };
                    (void)id_219;
                    (void)id_219;
                  }
                  (void)::dessser::VOID;
                  uint8_t id_220 { 0 };
                  Pointer id_221 { dst_ref_415[id_220] };
                  let_res_170 = id_221;
                }
                let_res_167 = let_res_170;
              }
              let_res_128 = let_res_167;
            }
            Pointer let_res_222;
            {
              Pointer srec_dst_420 { let_res_128 };
              uint8_t id_223 { x_403.axis };
              Pointer id_224 { srec_dst_420.writeU8(id_223) };
              let_res_222 = id_224;
            }
            Void id_225 { ((void)(dst_ref_401[id_52] = let_res_222), ::dessser::VOID) };
            (void)id_225;
            uint8_t id_226 { 0 };
            int32_t id_227 { 1L };
            uint8_t id_228 { 0 };
            int32_t id_229 { n_ref_402[id_228] };
            int32_t id_230 { int32_t(id_227 + id_229) };
            Void id_231 { ((void)(n_ref_402[id_226] = id_230), ::dessser::VOID) };
            (void)id_231;
            (void)id_231;
          }
          (void)::dessser::VOID;
          uint8_t id_232 { 0 };
          Pointer id_233 { dst_ref_401[id_232] };
          let_res_50 = id_233;
        }
        let_res_47 = let_res_50;
      }
      let_res_8 = let_res_47;
    }
    return let_res_8;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::source> ,Pointer)> source_to_row_binary(source_to_row_binary_init());

/* 
    (fun ("[Linear Void | Logarithmic Void]" "Ptr")
      (let "ssum_dst_394" (write-u16 little-endian (param 1) (label-of (param 0))) (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_394") (seq (assert (eq (label-of (param 0)) (u16 1))) (identifier "ssum_dst_394")))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,Pointer)> scale_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,Pointer)> fun234 { [&fun234](std::shared_ptr<::dessser::gen::dashboard_widget::scale>  p_0, Pointer p_1) {
    uint16_t id_235 { uint16_t((*p_0).index()) };
    Pointer id_236 { p_1.writeU16Le(id_235) };
    Pointer let_res_237;
    {
      Pointer ssum_dst_394 { id_236 };
      uint16_t id_238 { 0 };
      uint16_t id_239 { uint16_t((*p_0).index()) };
      bool id_240 { bool(id_238 == id_239) };
      Pointer choose_res_241;
      if (id_240) {
        choose_res_241 = ssum_dst_394;
      } else {
        uint16_t id_242 { uint16_t((*p_0).index()) };
        uint16_t id_243 { 1 };
        bool id_244 { bool(id_242 == id_243) };
        Void id_245 { ((void)(assert(id_244)), ::dessser::VOID) };
        (void)id_245;
        choose_res_241 = ssum_dst_394;
      }
      let_res_237 = choose_res_241;
    }
    return let_res_237;
  }
   };
  return fun234;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,Pointer)> scale_to_row_binary(scale_to_row_binary_init());

/* 
    (fun ("{left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])}" "Ptr")
      (let "srec_dst_396" (let "srec_dst_395" (write-u8 (param 1) (u8-of-bool (get-field "left" (param 0)))) (write-u8 (identifier "srec_dst_395") (u8-of-bool (get-field "force_zero" (param 0)))))
        (apply (identifier "scale-to-row-binary") (get-field "scale" (param 0)) (identifier "srec_dst_396"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,Pointer)> axis_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,Pointer)> fun246 { [&fun246](std::shared_ptr<::dessser::gen::dashboard_widget::axis>  p_0, Pointer p_1) {
    bool id_247 { (*p_0).left };
    uint8_t id_248 { uint8_t(id_247) };
    Pointer id_249 { p_1.writeU8(id_248) };
    Pointer let_res_250;
    {
      Pointer srec_dst_395 { id_249 };
      bool id_251 { (*p_0).force_zero };
      uint8_t id_252 { uint8_t(id_251) };
      Pointer id_253 { srec_dst_395.writeU8(id_252) };
      let_res_250 = id_253;
    }
    Pointer let_res_254;
    {
      Pointer srec_dst_396 { let_res_250 };
      std::shared_ptr<::dessser::gen::dashboard_widget::scale>  id_255 { (*p_0).scale };
      Pointer id_256 { scale_to_row_binary(id_255, srec_dst_396) };
      let_res_254 = id_256;
    }
    return let_res_254;
  }
   };
  return fun246;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,Pointer)> axis_to_row_binary(axis_to_row_binary_init());

/* 
    (fun ("[Plot Void]" "Ptr") (let "ssum_dst_392" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (identifier "ssum_dst_392"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::type> ,Pointer)> type_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::type> ,Pointer)> fun257 { [&fun257](std::shared_ptr<::dessser::gen::dashboard_widget::type>  p_0, Pointer p_1) {
    uint16_t id_258 { uint16_t((*p_0).index()) };
    Pointer id_259 { p_1.writeU16Le(id_258) };
    Pointer let_res_260;
    {
      Pointer ssum_dst_392 { id_259 };
      uint16_t id_261 { uint16_t((*p_0).index()) };
      uint16_t id_262 { 0 };
      bool id_263 { bool(id_261 == id_262) };
      Void id_264 { ((void)(assert(id_263)), ::dessser::VOID) };
      (void)id_264;
      let_res_260 = ssum_dst_392;
    }
    return let_res_260;
  }
   };
  return fun257;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::type> ,Pointer)> type_to_row_binary(type_to_row_binary_init());

/* 
    (fun ("{title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]})[]}" "Ptr")
      (let "srec_dst_430"
        (let "srec_dst_424"
          (let "srec_dst_423"
            (write-bytes
              (let "leb128_sz_421" (make-vec (string-length (get-field "title" (param 0))))
                (let "leb128_ptr_422" (make-vec (param 1))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_422")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_422"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_421"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_421"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_421"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_421") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_421")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_421")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_422"))))) 
              (bytes-of-string (get-field "title" (param 0)))) (apply (identifier "type-to-row-binary") (get-field "type" (param 0)) (identifier "srec_dst_423")))
          (let "dst_ref_427"
            (make-vec
              (let "leb128_sz_425" (make-vec (cardinality (get-field "axes" (param 0))))
                (let "leb128_ptr_426" (make-vec (identifier "srec_dst_424"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_426")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_426"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_425"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_425"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_425"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_425") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_425")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_425")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_426"))))))
            (let "n_ref_428" (make-vec (i32 0))
              (seq
                (for-each "x_429" (get-field "axes" (param 0))
                  (seq (set-vec (u8 0) (identifier "dst_ref_427") (apply (identifier "axis-to-row-binary") (identifier "x_429") (unsafe-nth (u8 0) (identifier "dst_ref_427"))))
                    (set-vec (u8 0) (identifier "n_ref_428") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_428")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_427"))))))
        (let "dst_ref_433"
          (make-vec
            (let "leb128_sz_431" (make-vec (cardinality (get-field "sources" (param 0))))
              (let "leb128_ptr_432" (make-vec (identifier "srec_dst_430"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_432")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_432"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_431"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_431"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_431"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_431") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_431")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_431")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_432"))))))
          (let "n_ref_434" (make-vec (i32 0))
            (seq
              (for-each "x_435" (get-field "sources" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_433") (apply (identifier "source-to-row-binary") (identifier "x_435") (unsafe-nth (u8 0) (identifier "dst_ref_433"))))
                  (set-vec (u8 0) (identifier "n_ref_434") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_434")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_433")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,Pointer)> chart_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,Pointer)> fun265 { [&fun265](std::shared_ptr<::dessser::gen::dashboard_widget::chart>  p_0, Pointer p_1) {
    std::string id_266 { (*p_0).title };
    uint32_t id_267 { (uint32_t)id_266.size() };
    Vec<1, uint32_t> id_268 {  id_267  };
    Pointer let_res_269;
    {
      Vec<1, uint32_t> leb128_sz_421 { id_268 };
      Vec<1, Pointer> id_270 {  p_1  };
      Pointer let_res_271;
      {
        Vec<1, Pointer> leb128_ptr_422 { id_270 };
        bool while_flag_272 { true };
        do {
          uint8_t id_273 { 0 };
          uint8_t id_274 { 0 };
          Pointer id_275 { leb128_ptr_422[id_274] };
          uint32_t id_276 { 128U };
          uint8_t id_277 { 0 };
          uint32_t id_278 { leb128_sz_421[id_277] };
          bool id_279 { bool(id_276 > id_278) };
          uint8_t choose_res_280;
          if (id_279) {
            uint8_t id_281 { 0 };
            uint32_t id_282 { leb128_sz_421[id_281] };
            uint8_t id_283 { uint8_t(id_282) };
            choose_res_280 = id_283;
          } else {
            uint8_t id_284 { 0 };
            uint32_t id_285 { leb128_sz_421[id_284] };
            uint8_t id_286 { uint8_t(id_285) };
            uint8_t id_287 { 128 };
            uint8_t id_288 { uint8_t(id_286 | id_287) };
            choose_res_280 = id_288;
          }
          Pointer id_289 { id_275.writeU8(choose_res_280) };
          Void id_290 { ((void)(leb128_ptr_422[id_273] = id_289), ::dessser::VOID) };
          (void)id_290;
          uint8_t id_291 { 0 };
          uint8_t id_292 { 0 };
          uint32_t id_293 { leb128_sz_421[id_292] };
          uint8_t id_294 { 7 };
          uint32_t id_295 { uint32_t(id_293 >> id_294) };
          Void id_296 { ((void)(leb128_sz_421[id_291] = id_295), ::dessser::VOID) };
          (void)id_296;
          uint8_t id_297 { 0 };
          uint32_t id_298 { leb128_sz_421[id_297] };
          uint32_t id_299 { 0U };
          bool id_300 { bool(id_298 > id_299) };
          while_flag_272 = id_300;
          if (while_flag_272) {
            (void)::dessser::VOID;
          }
        } while (while_flag_272);
        (void)::dessser::VOID;
        uint8_t id_301 { 0 };
        Pointer id_302 { leb128_ptr_422[id_301] };
        let_res_271 = id_302;
      }
      let_res_269 = let_res_271;
    }
    std::string id_303 { (*p_0).title };
    Bytes id_304 { id_303 };
    Pointer id_305 { let_res_269.writeBytes(id_304) };
    Pointer let_res_306;
    {
      Pointer srec_dst_423 { id_305 };
      std::shared_ptr<::dessser::gen::dashboard_widget::type>  id_307 { (*p_0).type };
      Pointer id_308 { type_to_row_binary(id_307, srec_dst_423) };
      let_res_306 = id_308;
    }
    Pointer let_res_309;
    {
      Pointer srec_dst_424 { let_res_306 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_310 { (*p_0).axes };
      uint32_t id_311 { id_310.size() };
      Vec<1, uint32_t> id_312 {  id_311  };
      Pointer let_res_313;
      {
        Vec<1, uint32_t> leb128_sz_425 { id_312 };
        Vec<1, Pointer> id_314 {  srec_dst_424  };
        Pointer let_res_315;
        {
          Vec<1, Pointer> leb128_ptr_426 { id_314 };
          bool while_flag_316 { true };
          do {
            uint8_t id_317 { 0 };
            uint8_t id_318 { 0 };
            Pointer id_319 { leb128_ptr_426[id_318] };
            uint32_t id_320 { 128U };
            uint8_t id_321 { 0 };
            uint32_t id_322 { leb128_sz_425[id_321] };
            bool id_323 { bool(id_320 > id_322) };
            uint8_t choose_res_324;
            if (id_323) {
              uint8_t id_325 { 0 };
              uint32_t id_326 { leb128_sz_425[id_325] };
              uint8_t id_327 { uint8_t(id_326) };
              choose_res_324 = id_327;
            } else {
              uint8_t id_328 { 0 };
              uint32_t id_329 { leb128_sz_425[id_328] };
              uint8_t id_330 { uint8_t(id_329) };
              uint8_t id_331 { 128 };
              uint8_t id_332 { uint8_t(id_330 | id_331) };
              choose_res_324 = id_332;
            }
            Pointer id_333 { id_319.writeU8(choose_res_324) };
            Void id_334 { ((void)(leb128_ptr_426[id_317] = id_333), ::dessser::VOID) };
            (void)id_334;
            uint8_t id_335 { 0 };
            uint8_t id_336 { 0 };
            uint32_t id_337 { leb128_sz_425[id_336] };
            uint8_t id_338 { 7 };
            uint32_t id_339 { uint32_t(id_337 >> id_338) };
            Void id_340 { ((void)(leb128_sz_425[id_335] = id_339), ::dessser::VOID) };
            (void)id_340;
            uint8_t id_341 { 0 };
            uint32_t id_342 { leb128_sz_425[id_341] };
            uint32_t id_343 { 0U };
            bool id_344 { bool(id_342 > id_343) };
            while_flag_316 = id_344;
            if (while_flag_316) {
              (void)::dessser::VOID;
            }
          } while (while_flag_316);
          (void)::dessser::VOID;
          uint8_t id_345 { 0 };
          Pointer id_346 { leb128_ptr_426[id_345] };
          let_res_315 = id_346;
        }
        let_res_313 = let_res_315;
      }
      Vec<1, Pointer> id_347 {  let_res_313  };
      Pointer let_res_348;
      {
        Vec<1, Pointer> dst_ref_427 { id_347 };
        int32_t id_349 { 0L };
        Vec<1, int32_t> id_350 {  id_349  };
        Pointer let_res_351;
        {
          Vec<1, int32_t> n_ref_428 { id_350 };
          Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_352 { (*p_0).axes };
          for (std::shared_ptr<::dessser::gen::dashboard_widget::axis>  x_429 : id_352) {
            uint8_t id_353 { 0 };
            uint8_t id_354 { 0 };
            Pointer id_355 { dst_ref_427[id_354] };
            Pointer id_356 { axis_to_row_binary(x_429, id_355) };
            Void id_357 { ((void)(dst_ref_427[id_353] = id_356), ::dessser::VOID) };
            (void)id_357;
            uint8_t id_358 { 0 };
            int32_t id_359 { 1L };
            uint8_t id_360 { 0 };
            int32_t id_361 { n_ref_428[id_360] };
            int32_t id_362 { int32_t(id_359 + id_361) };
            Void id_363 { ((void)(n_ref_428[id_358] = id_362), ::dessser::VOID) };
            (void)id_363;
            (void)id_363;
          }
          (void)::dessser::VOID;
          uint8_t id_364 { 0 };
          Pointer id_365 { dst_ref_427[id_364] };
          let_res_351 = id_365;
        }
        let_res_348 = let_res_351;
      }
      let_res_309 = let_res_348;
    }
    Pointer let_res_366;
    {
      Pointer srec_dst_430 { let_res_309 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_367 { (*p_0).sources };
      uint32_t id_368 { id_367.size() };
      Vec<1, uint32_t> id_369 {  id_368  };
      Pointer let_res_370;
      {
        Vec<1, uint32_t> leb128_sz_431 { id_369 };
        Vec<1, Pointer> id_371 {  srec_dst_430  };
        Pointer let_res_372;
        {
          Vec<1, Pointer> leb128_ptr_432 { id_371 };
          bool while_flag_373 { true };
          do {
            uint8_t id_374 { 0 };
            uint8_t id_375 { 0 };
            Pointer id_376 { leb128_ptr_432[id_375] };
            uint32_t id_377 { 128U };
            uint8_t id_378 { 0 };
            uint32_t id_379 { leb128_sz_431[id_378] };
            bool id_380 { bool(id_377 > id_379) };
            uint8_t choose_res_381;
            if (id_380) {
              uint8_t id_382 { 0 };
              uint32_t id_383 { leb128_sz_431[id_382] };
              uint8_t id_384 { uint8_t(id_383) };
              choose_res_381 = id_384;
            } else {
              uint8_t id_385 { 0 };
              uint32_t id_386 { leb128_sz_431[id_385] };
              uint8_t id_387 { uint8_t(id_386) };
              uint8_t id_388 { 128 };
              uint8_t id_389 { uint8_t(id_387 | id_388) };
              choose_res_381 = id_389;
            }
            Pointer id_390 { id_376.writeU8(choose_res_381) };
            Void id_391 { ((void)(leb128_ptr_432[id_374] = id_390), ::dessser::VOID) };
            (void)id_391;
            uint8_t id_392 { 0 };
            uint8_t id_393 { 0 };
            uint32_t id_394 { leb128_sz_431[id_393] };
            uint8_t id_395 { 7 };
            uint32_t id_396 { uint32_t(id_394 >> id_395) };
            Void id_397 { ((void)(leb128_sz_431[id_392] = id_396), ::dessser::VOID) };
            (void)id_397;
            uint8_t id_398 { 0 };
            uint32_t id_399 { leb128_sz_431[id_398] };
            uint32_t id_400 { 0U };
            bool id_401 { bool(id_399 > id_400) };
            while_flag_373 = id_401;
            if (while_flag_373) {
              (void)::dessser::VOID;
            }
          } while (while_flag_373);
          (void)::dessser::VOID;
          uint8_t id_402 { 0 };
          Pointer id_403 { leb128_ptr_432[id_402] };
          let_res_372 = id_403;
        }
        let_res_370 = let_res_372;
      }
      Vec<1, Pointer> id_404 {  let_res_370  };
      Pointer let_res_405;
      {
        Vec<1, Pointer> dst_ref_433 { id_404 };
        int32_t id_406 { 0L };
        Vec<1, int32_t> id_407 {  id_406  };
        Pointer let_res_408;
        {
          Vec<1, int32_t> n_ref_434 { id_407 };
          Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_409 { (*p_0).sources };
          for (std::shared_ptr<::dessser::gen::dashboard_widget::source>  x_435 : id_409) {
            uint8_t id_410 { 0 };
            uint8_t id_411 { 0 };
            Pointer id_412 { dst_ref_433[id_411] };
            Pointer id_413 { source_to_row_binary(x_435, id_412) };
            Void id_414 { ((void)(dst_ref_433[id_410] = id_413), ::dessser::VOID) };
            (void)id_414;
            uint8_t id_415 { 0 };
            int32_t id_416 { 1L };
            uint8_t id_417 { 0 };
            int32_t id_418 { n_ref_434[id_417] };
            int32_t id_419 { int32_t(id_416 + id_418) };
            Void id_420 { ((void)(n_ref_434[id_415] = id_419), ::dessser::VOID) };
            (void)id_420;
            (void)id_420;
          }
          (void)::dessser::VOID;
          uint8_t id_421 { 0 };
          Pointer id_422 { dst_ref_433[id_421] };
          let_res_408 = id_422;
        }
        let_res_405 = let_res_408;
      }
      let_res_366 = let_res_405;
    }
    return let_res_366;
  }
   };
  return fun265;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,Pointer)> chart_to_row_binary(chart_to_row_binary_init());

/* 
    (fun ("[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]})[]})]" "Ptr")
      (let "ssum_dst_437" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_438" (make-vec (string-length (get-alt "Text" (param 0))))
              (let "leb128_ptr_439" (make-vec (identifier "ssum_dst_437"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_439")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_439"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_438"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_438"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_438"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_438") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_438")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_438")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_439"))))) 
            (bytes-of-string (get-alt "Text" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "chart-to-row-binary") (get-alt "Chart" (param 0)) (identifier "ssum_dst_437"))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::t> ,Pointer)> fun423 { [&fun423](std::shared_ptr<::dessser::gen::dashboard_widget::t>  p_0, Pointer p_1) {
    uint16_t id_424 { uint16_t((*p_0).index()) };
    Pointer id_425 { p_1.writeU16Le(id_424) };
    Pointer let_res_426;
    {
      Pointer ssum_dst_437 { id_425 };
      uint16_t id_427 { 0 };
      uint16_t id_428 { uint16_t((*p_0).index()) };
      bool id_429 { bool(id_427 == id_428) };
      Pointer choose_res_430;
      if (id_429) {
        std::string id_431 { std::get<0 /* Text */>((*p_0)) };
        uint32_t id_432 { (uint32_t)id_431.size() };
        Vec<1, uint32_t> id_433 {  id_432  };
        Pointer let_res_434;
        {
          Vec<1, uint32_t> leb128_sz_438 { id_433 };
          Vec<1, Pointer> id_435 {  ssum_dst_437  };
          Pointer let_res_436;
          {
            Vec<1, Pointer> leb128_ptr_439 { id_435 };
            bool while_flag_437 { true };
            do {
              uint8_t id_438 { 0 };
              uint8_t id_439 { 0 };
              Pointer id_440 { leb128_ptr_439[id_439] };
              uint32_t id_441 { 128U };
              uint8_t id_442 { 0 };
              uint32_t id_443 { leb128_sz_438[id_442] };
              bool id_444 { bool(id_441 > id_443) };
              uint8_t choose_res_445;
              if (id_444) {
                uint8_t id_446 { 0 };
                uint32_t id_447 { leb128_sz_438[id_446] };
                uint8_t id_448 { uint8_t(id_447) };
                choose_res_445 = id_448;
              } else {
                uint8_t id_449 { 0 };
                uint32_t id_450 { leb128_sz_438[id_449] };
                uint8_t id_451 { uint8_t(id_450) };
                uint8_t id_452 { 128 };
                uint8_t id_453 { uint8_t(id_451 | id_452) };
                choose_res_445 = id_453;
              }
              Pointer id_454 { id_440.writeU8(choose_res_445) };
              Void id_455 { ((void)(leb128_ptr_439[id_438] = id_454), ::dessser::VOID) };
              (void)id_455;
              uint8_t id_456 { 0 };
              uint8_t id_457 { 0 };
              uint32_t id_458 { leb128_sz_438[id_457] };
              uint8_t id_459 { 7 };
              uint32_t id_460 { uint32_t(id_458 >> id_459) };
              Void id_461 { ((void)(leb128_sz_438[id_456] = id_460), ::dessser::VOID) };
              (void)id_461;
              uint8_t id_462 { 0 };
              uint32_t id_463 { leb128_sz_438[id_462] };
              uint32_t id_464 { 0U };
              bool id_465 { bool(id_463 > id_464) };
              while_flag_437 = id_465;
              if (while_flag_437) {
                (void)::dessser::VOID;
              }
            } while (while_flag_437);
            (void)::dessser::VOID;
            uint8_t id_466 { 0 };
            Pointer id_467 { leb128_ptr_439[id_466] };
            let_res_436 = id_467;
          }
          let_res_434 = let_res_436;
        }
        std::string id_468 { std::get<0 /* Text */>((*p_0)) };
        Bytes id_469 { id_468 };
        Pointer id_470 { let_res_434.writeBytes(id_469) };
        choose_res_430 = id_470;
      } else {
        uint16_t id_471 { uint16_t((*p_0).index()) };
        uint16_t id_472 { 1 };
        bool id_473 { bool(id_471 == id_472) };
        Void id_474 { ((void)(assert(id_473)), ::dessser::VOID) };
        (void)id_474;
        std::shared_ptr<::dessser::gen::dashboard_widget::chart>  id_475 { std::get<1 /* Chart */>((*p_0)) };
        Pointer id_476 { chart_to_row_binary(id_475, ssum_dst_437) };
        choose_res_430 = id_476;
      }
      let_res_426 = choose_res_430;
    }
    return let_res_426;
  }
   };
  return fun423;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]}")
      (let "sz_350" (add (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-field "name" (param 0))) (size 1))
        (let "sz_ref_353"
          (make-vec
            (add (identifier "sz_350")
              (let "n_ref_351" (make-vec (cardinality (get-field "fields" (param 0))))
                (let "lebsz_ref_352" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_351")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_352")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_352") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_352")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_352"))))))))
          (seq
            (let "repeat_n_354" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "fields" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_354")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_353")
                    (add
                      (let "sz_363"
                        (let "sz_359"
                          (let "sz_357" (add (add (unsafe-nth (u8 0) (identifier "sz_ref_353")) (size 8)) (size 4))
                            (let "label2_358" (label-of (get-field "representation" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_354")) (get-field "fields" (param 0)))))
                              (if (eq (u16 0) (identifier "label2_358")) 
                                (add (identifier "sz_357") (size 2))
                                (if (eq (u16 1) (identifier "label2_358")) 
                                  (add (identifier "sz_357") (size 2))
                                  (if (eq (u16 2) (identifier "label2_358")) (add (identifier "sz_357") (size 2)) (seq (assert (eq (identifier "label2_358") (u16 3))) (add (identifier "sz_357") (size 2))))))))
                          (add (identifier "sz_359")
                            (let "wlen_360" (string-length (get-field "column" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_354")) (get-field "fields" (param 0)))))
                              (add
                                (let "n_ref_361" (make-vec (identifier "wlen_360"))
                                  (let "lebsz_ref_362" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_361")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_362")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_362") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_362")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_362")))))) 
                                (size-of-u32 (identifier "wlen_360"))))))
                        (let "sz_ref_366"
                          (make-vec
                            (add (identifier "sz_363")
                              (let "n_ref_364" (make-vec (cardinality (get-field "factors" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_354")) (get-field "fields" (param 0))))))
                                (let "lebsz_ref_365" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_364")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_365")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_365") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_365")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_365"))))))))
                          (seq
                            (let "repeat_n_367" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "factors" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_354")) (get-field "fields" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_367")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_366")
                                    (add (unsafe-nth (u8 0) (identifier "sz_ref_366"))
                                      (let "wlen_368"
                                        (string-length
                                          (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_367")) (get-field "factors" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_354")) (get-field "fields" (param 0))))))
                                        (add
                                          (let "n_ref_369" (make-vec (identifier "wlen_368"))
                                            (let "lebsz_ref_370" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_369")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_370")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_370") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_370")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_370")))))) 
                                          (size-of-u32 (identifier "wlen_368")))))) 
                                  (set-vec (u8 0) (identifier "repeat_n_367") (add (unsafe-nth (u8 0) (identifier "repeat_n_367")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_366"))))) 
                      (size 1))) (set-vec (u8 0) (identifier "repeat_n_354") (add (unsafe-nth (u8 0) (identifier "repeat_n_354")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_353"))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::source> )> source_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::source> )> fun477 { [&fun477](std::shared_ptr<::dessser::gen::dashboard_widget::source>  p_0) {
    auto fun478 { dessser::gen::fq_function_name::sersize_of_row_binary };
    dessser::gen::fq_function_name::t_ext id_479 { (*p_0).name };
    Size id_480 { fun478(id_479) };
    Size id_481 { 1UL };
    Size id_482 { Size(id_480 + id_481) };
    Size let_res_483;
    {
      Size sz_350 { id_482 };
      Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_484 { (*p_0).fields };
      uint32_t id_485 { id_484.size() };
      Vec<1, uint32_t> id_486 {  id_485  };
      Size let_res_487;
      {
        Vec<1, uint32_t> n_ref_351 { id_486 };
        uint32_t id_488 { 1U };
        Vec<1, uint32_t> id_489 {  id_488  };
        Size let_res_490;
        {
          Vec<1, uint32_t> lebsz_ref_352 { id_489 };
          bool while_flag_491 { true };
          do {
            uint8_t id_492 { 0 };
            uint32_t id_493 { n_ref_351[id_492] };
            uint8_t id_494 { 0 };
            uint32_t id_495 { lebsz_ref_352[id_494] };
            uint8_t id_496 { 7 };
            uint32_t id_497 { uint32_t(id_495 << id_496) };
            bool id_498 { bool(id_493 >= id_497) };
            while_flag_491 = id_498;
            if (while_flag_491) {
              uint8_t id_499 { 0 };
              uint8_t id_500 { 0 };
              uint32_t id_501 { lebsz_ref_352[id_500] };
              uint32_t id_502 { 1U };
              uint32_t id_503 { uint32_t(id_501 + id_502) };
              Void id_504 { ((void)(lebsz_ref_352[id_499] = id_503), ::dessser::VOID) };
              (void)id_504;
            }
          } while (while_flag_491);
          (void)::dessser::VOID;
          uint8_t id_505 { 0 };
          uint32_t id_506 { lebsz_ref_352[id_505] };
          Size id_507 { Size(id_506) };
          let_res_490 = id_507;
        }
        let_res_487 = let_res_490;
      }
      Size id_508 { Size(sz_350 + let_res_487) };
      Vec<1, Size> id_509 {  id_508  };
      Size let_res_510;
      {
        Vec<1, Size> sz_ref_353 { id_509 };
        int32_t id_511 { 0L };
        Vec<1, int32_t> id_512 {  id_511  };
        {
          Vec<1, int32_t> repeat_n_354 { id_512 };
          bool while_flag_513 { true };
          do {
            Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_514 { (*p_0).fields };
            uint32_t id_515 { id_514.size() };
            int32_t id_516 { int32_t(id_515) };
            uint8_t id_517 { 0 };
            int32_t id_518 { repeat_n_354[id_517] };
            bool id_519 { bool(id_516 > id_518) };
            while_flag_513 = id_519;
            if (while_flag_513) {
              uint8_t id_520 { 0 };
              uint8_t id_521 { 0 };
              Size id_522 { sz_ref_353[id_521] };
              Size id_523 { 8UL };
              Size id_524 { Size(id_522 + id_523) };
              Size id_525 { 4UL };
              Size id_526 { Size(id_524 + id_525) };
              Size let_res_527;
              {
                Size sz_357 { id_526 };
                uint8_t id_528 { 0 };
                int32_t id_529 { repeat_n_354[id_528] };
                Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_530 { (*p_0).fields };
                ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_531 { id_530[id_529] };
                ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_532 { id_531.representation };
                uint16_t id_533 { uint16_t(id_532.index()) };
                Size let_res_534;
                {
                  uint16_t label2_358 { id_533 };
                  uint16_t id_535 { 0 };
                  bool id_536 { bool(id_535 == label2_358) };
                  Size choose_res_537;
                  if (id_536) {
                    Size id_538 { 2UL };
                    Size id_539 { Size(sz_357 + id_538) };
                    choose_res_537 = id_539;
                  } else {
                    uint16_t id_540 { 1 };
                    bool id_541 { bool(id_540 == label2_358) };
                    Size choose_res_542;
                    if (id_541) {
                      Size id_543 { 2UL };
                      Size id_544 { Size(sz_357 + id_543) };
                      choose_res_542 = id_544;
                    } else {
                      uint16_t id_545 { 2 };
                      bool id_546 { bool(id_545 == label2_358) };
                      Size choose_res_547;
                      if (id_546) {
                        Size id_548 { 2UL };
                        Size id_549 { Size(sz_357 + id_548) };
                        choose_res_547 = id_549;
                      } else {
                        uint16_t id_550 { 3 };
                        bool id_551 { bool(label2_358 == id_550) };
                        Void id_552 { ((void)(assert(id_551)), ::dessser::VOID) };
                        (void)id_552;
                        Size id_553 { 2UL };
                        Size id_554 { Size(sz_357 + id_553) };
                        choose_res_547 = id_554;
                      }
                      choose_res_542 = choose_res_547;
                    }
                    choose_res_537 = choose_res_542;
                  }
                  let_res_534 = choose_res_537;
                }
                let_res_527 = let_res_534;
              }
              Size let_res_555;
              {
                Size sz_359 { let_res_527 };
                uint8_t id_556 { 0 };
                int32_t id_557 { repeat_n_354[id_556] };
                Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_558 { (*p_0).fields };
                ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_559 { id_558[id_557] };
                std::string id_560 { id_559.column };
                uint32_t id_561 { (uint32_t)id_560.size() };
                Size let_res_562;
                {
                  uint32_t wlen_360 { id_561 };
                  Vec<1, uint32_t> id_563 {  wlen_360  };
                  Size let_res_564;
                  {
                    Vec<1, uint32_t> n_ref_361 { id_563 };
                    uint32_t id_565 { 1U };
                    Vec<1, uint32_t> id_566 {  id_565  };
                    Size let_res_567;
                    {
                      Vec<1, uint32_t> lebsz_ref_362 { id_566 };
                      bool while_flag_568 { true };
                      do {
                        uint8_t id_569 { 0 };
                        uint32_t id_570 { n_ref_361[id_569] };
                        uint8_t id_571 { 0 };
                        uint32_t id_572 { lebsz_ref_362[id_571] };
                        uint8_t id_573 { 7 };
                        uint32_t id_574 { uint32_t(id_572 << id_573) };
                        bool id_575 { bool(id_570 >= id_574) };
                        while_flag_568 = id_575;
                        if (while_flag_568) {
                          uint8_t id_576 { 0 };
                          uint8_t id_577 { 0 };
                          uint32_t id_578 { lebsz_ref_362[id_577] };
                          uint32_t id_579 { 1U };
                          uint32_t id_580 { uint32_t(id_578 + id_579) };
                          Void id_581 { ((void)(lebsz_ref_362[id_576] = id_580), ::dessser::VOID) };
                          (void)id_581;
                        }
                      } while (while_flag_568);
                      (void)::dessser::VOID;
                      uint8_t id_582 { 0 };
                      uint32_t id_583 { lebsz_ref_362[id_582] };
                      Size id_584 { Size(id_583) };
                      let_res_567 = id_584;
                    }
                    let_res_564 = let_res_567;
                  }
                  Size id_585 { Size(wlen_360) };
                  Size id_586 { Size(let_res_564 + id_585) };
                  let_res_562 = id_586;
                }
                Size id_587 { Size(sz_359 + let_res_562) };
                let_res_555 = id_587;
              }
              Size let_res_588;
              {
                Size sz_363 { let_res_555 };
                uint8_t id_589 { 0 };
                int32_t id_590 { repeat_n_354[id_589] };
                Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_591 { (*p_0).fields };
                ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_592 { id_591[id_590] };
                Arr<std::string> id_593 { id_592.factors };
                uint32_t id_594 { id_593.size() };
                Vec<1, uint32_t> id_595 {  id_594  };
                Size let_res_596;
                {
                  Vec<1, uint32_t> n_ref_364 { id_595 };
                  uint32_t id_597 { 1U };
                  Vec<1, uint32_t> id_598 {  id_597  };
                  Size let_res_599;
                  {
                    Vec<1, uint32_t> lebsz_ref_365 { id_598 };
                    bool while_flag_600 { true };
                    do {
                      uint8_t id_601 { 0 };
                      uint32_t id_602 { n_ref_364[id_601] };
                      uint8_t id_603 { 0 };
                      uint32_t id_604 { lebsz_ref_365[id_603] };
                      uint8_t id_605 { 7 };
                      uint32_t id_606 { uint32_t(id_604 << id_605) };
                      bool id_607 { bool(id_602 >= id_606) };
                      while_flag_600 = id_607;
                      if (while_flag_600) {
                        uint8_t id_608 { 0 };
                        uint8_t id_609 { 0 };
                        uint32_t id_610 { lebsz_ref_365[id_609] };
                        uint32_t id_611 { 1U };
                        uint32_t id_612 { uint32_t(id_610 + id_611) };
                        Void id_613 { ((void)(lebsz_ref_365[id_608] = id_612), ::dessser::VOID) };
                        (void)id_613;
                      }
                    } while (while_flag_600);
                    (void)::dessser::VOID;
                    uint8_t id_614 { 0 };
                    uint32_t id_615 { lebsz_ref_365[id_614] };
                    Size id_616 { Size(id_615) };
                    let_res_599 = id_616;
                  }
                  let_res_596 = let_res_599;
                }
                Size id_617 { Size(sz_363 + let_res_596) };
                Vec<1, Size> id_618 {  id_617  };
                Size let_res_619;
                {
                  Vec<1, Size> sz_ref_366 { id_618 };
                  int32_t id_620 { 0L };
                  Vec<1, int32_t> id_621 {  id_620  };
                  {
                    Vec<1, int32_t> repeat_n_367 { id_621 };
                    bool while_flag_622 { true };
                    do {
                      uint8_t id_623 { 0 };
                      int32_t id_624 { repeat_n_354[id_623] };
                      Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_625 { (*p_0).fields };
                      ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_626 { id_625[id_624] };
                      Arr<std::string> id_627 { id_626.factors };
                      uint32_t id_628 { id_627.size() };
                      int32_t id_629 { int32_t(id_628) };
                      uint8_t id_630 { 0 };
                      int32_t id_631 { repeat_n_367[id_630] };
                      bool id_632 { bool(id_629 > id_631) };
                      while_flag_622 = id_632;
                      if (while_flag_622) {
                        uint8_t id_633 { 0 };
                        uint8_t id_634 { 0 };
                        Size id_635 { sz_ref_366[id_634] };
                        uint8_t id_636 { 0 };
                        int32_t id_637 { repeat_n_367[id_636] };
                        uint8_t id_638 { 0 };
                        int32_t id_639 { repeat_n_354[id_638] };
                        Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_640 { (*p_0).fields };
                        ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_641 { id_640[id_639] };
                        Arr<std::string> id_642 { id_641.factors };
                        std::string id_643 { id_642[id_637] };
                        uint32_t id_644 { (uint32_t)id_643.size() };
                        Size let_res_645;
                        {
                          uint32_t wlen_368 { id_644 };
                          Vec<1, uint32_t> id_646 {  wlen_368  };
                          Size let_res_647;
                          {
                            Vec<1, uint32_t> n_ref_369 { id_646 };
                            uint32_t id_648 { 1U };
                            Vec<1, uint32_t> id_649 {  id_648  };
                            Size let_res_650;
                            {
                              Vec<1, uint32_t> lebsz_ref_370 { id_649 };
                              bool while_flag_651 { true };
                              do {
                                uint8_t id_652 { 0 };
                                uint32_t id_653 { n_ref_369[id_652] };
                                uint8_t id_654 { 0 };
                                uint32_t id_655 { lebsz_ref_370[id_654] };
                                uint8_t id_656 { 7 };
                                uint32_t id_657 { uint32_t(id_655 << id_656) };
                                bool id_658 { bool(id_653 >= id_657) };
                                while_flag_651 = id_658;
                                if (while_flag_651) {
                                  uint8_t id_659 { 0 };
                                  uint8_t id_660 { 0 };
                                  uint32_t id_661 { lebsz_ref_370[id_660] };
                                  uint32_t id_662 { 1U };
                                  uint32_t id_663 { uint32_t(id_661 + id_662) };
                                  Void id_664 { ((void)(lebsz_ref_370[id_659] = id_663), ::dessser::VOID) };
                                  (void)id_664;
                                }
                              } while (while_flag_651);
                              (void)::dessser::VOID;
                              uint8_t id_665 { 0 };
                              uint32_t id_666 { lebsz_ref_370[id_665] };
                              Size id_667 { Size(id_666) };
                              let_res_650 = id_667;
                            }
                            let_res_647 = let_res_650;
                          }
                          Size id_668 { Size(wlen_368) };
                          Size id_669 { Size(let_res_647 + id_668) };
                          let_res_645 = id_669;
                        }
                        Size id_670 { Size(id_635 + let_res_645) };
                        Void id_671 { ((void)(sz_ref_366[id_633] = id_670), ::dessser::VOID) };
                        (void)id_671;
                        uint8_t id_672 { 0 };
                        uint8_t id_673 { 0 };
                        int32_t id_674 { repeat_n_367[id_673] };
                        int32_t id_675 { 1L };
                        int32_t id_676 { int32_t(id_674 + id_675) };
                        Void id_677 { ((void)(repeat_n_367[id_672] = id_676), ::dessser::VOID) };
                        (void)id_677;
                        (void)id_677;
                      }
                    } while (while_flag_622);
                    (void)::dessser::VOID;
                  }
                  (void)::dessser::VOID;
                  uint8_t id_678 { 0 };
                  Size id_679 { sz_ref_366[id_678] };
                  let_res_619 = id_679;
                }
                let_res_588 = let_res_619;
              }
              Size id_680 { 1UL };
              Size id_681 { Size(let_res_588 + id_680) };
              Void id_682 { ((void)(sz_ref_353[id_520] = id_681), ::dessser::VOID) };
              (void)id_682;
              uint8_t id_683 { 0 };
              uint8_t id_684 { 0 };
              int32_t id_685 { repeat_n_354[id_684] };
              int32_t id_686 { 1L };
              int32_t id_687 { int32_t(id_685 + id_686) };
              Void id_688 { ((void)(repeat_n_354[id_683] = id_687), ::dessser::VOID) };
              (void)id_688;
              (void)id_688;
            }
          } while (while_flag_513);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_689 { 0 };
        Size id_690 { sz_ref_353[id_689] };
        let_res_510 = id_690;
      }
      let_res_483 = let_res_510;
    }
    return let_res_483;
  }
   };
  return fun477;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::source> )> source_sersize_of_row_binary(source_sersize_of_row_binary_init());

/* 
    (fun ("[Linear Void | Logarithmic Void]") (if (eq (u16 0) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 1))) (size 2))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::scale> )> scale_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::scale> )> fun691 { [&fun691](std::shared_ptr<::dessser::gen::dashboard_widget::scale>  p_0) {
    uint16_t id_692 { 0 };
    uint16_t id_693 { uint16_t((*p_0).index()) };
    bool id_694 { bool(id_692 == id_693) };
    Size choose_res_695;
    if (id_694) {
      Size id_696 { 2UL };
      choose_res_695 = id_696;
    } else {
      uint16_t id_697 { uint16_t((*p_0).index()) };
      uint16_t id_698 { 1 };
      bool id_699 { bool(id_697 == id_698) };
      Void id_700 { ((void)(assert(id_699)), ::dessser::VOID) };
      (void)id_700;
      Size id_701 { 2UL };
      choose_res_695 = id_701;
    }
    return choose_res_695;
  }
   };
  return fun691;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::scale> )> scale_sersize_of_row_binary(scale_sersize_of_row_binary_init());

/* 
    (fun ("{left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])}") (add (size 2) (apply (identifier "scale-sersize-of-row-binary") (get-field "scale" (param 0)))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::axis> )> axis_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::axis> )> fun702 { [&fun702](std::shared_ptr<::dessser::gen::dashboard_widget::axis>  p_0) {
    Size id_703 { 2UL };
    std::shared_ptr<::dessser::gen::dashboard_widget::scale>  id_704 { (*p_0).scale };
    Size id_705 { scale_sersize_of_row_binary(id_704) };
    Size id_706 { Size(id_703 + id_705) };
    return id_706;
  }
   };
  return fun702;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::axis> )> axis_sersize_of_row_binary(axis_sersize_of_row_binary_init());

/* 
    (fun ("[Plot Void]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 2)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::type> )> type_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::type> )> fun707 { [&fun707](std::shared_ptr<::dessser::gen::dashboard_widget::type>  p_0) {
    uint16_t id_708 { uint16_t((*p_0).index()) };
    uint16_t id_709 { 0 };
    bool id_710 { bool(id_708 == id_709) };
    Void id_711 { ((void)(assert(id_710)), ::dessser::VOID) };
    (void)id_711;
    Size id_712 { 2UL };
    return id_712;
  }
   };
  return fun707;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::type> )> type_sersize_of_row_binary(type_sersize_of_row_binary_init());

/* 
    (fun ("{title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]})[]}")
      (let "sz_382"
        (let "sz_377"
          (let "sz_376"
            (add
              (let "n_ref_374" (make-vec (string-length (get-field "title" (param 0))))
                (let "lebsz_ref_375" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_374")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_375")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_375") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_375")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_375")))))) 
              (size-of-u32 (string-length (get-field "title" (param 0))))) 
            (add (identifier "sz_376") (apply (identifier "type-sersize-of-row-binary") (get-field "type" (param 0)))))
          (let "sz_ref_380"
            (make-vec
              (add (identifier "sz_377")
                (let "n_ref_378" (make-vec (cardinality (get-field "axes" (param 0))))
                  (let "lebsz_ref_379" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_378")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_379")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_379") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_379")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_379"))))))))
            (seq
              (let "repeat_n_381" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "axes" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_381")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_380")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_380")) (apply (identifier "axis-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_381")) (get-field "axes" (param 0))))))
                    (set-vec (u8 0) (identifier "repeat_n_381") (add (unsafe-nth (u8 0) (identifier "repeat_n_381")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_380")))))
        (let "sz_ref_385"
          (make-vec
            (add (identifier "sz_382")
              (let "n_ref_383" (make-vec (cardinality (get-field "sources" (param 0))))
                (let "lebsz_ref_384" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_383")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_384")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_384") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_384")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_384"))))))))
          (seq
            (let "repeat_n_386" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "sources" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_386")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_385")
                    (add (unsafe-nth (u8 0) (identifier "sz_ref_385")) (apply (identifier "source-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_386")) (get-field "sources" (param 0))))))
                  (set-vec (u8 0) (identifier "repeat_n_386") (add (unsafe-nth (u8 0) (identifier "repeat_n_386")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_385"))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::chart> )> chart_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::chart> )> fun713 { [&fun713](std::shared_ptr<::dessser::gen::dashboard_widget::chart>  p_0) {
    std::string id_714 { (*p_0).title };
    uint32_t id_715 { (uint32_t)id_714.size() };
    Vec<1, uint32_t> id_716 {  id_715  };
    Size let_res_717;
    {
      Vec<1, uint32_t> n_ref_374 { id_716 };
      uint32_t id_718 { 1U };
      Vec<1, uint32_t> id_719 {  id_718  };
      Size let_res_720;
      {
        Vec<1, uint32_t> lebsz_ref_375 { id_719 };
        bool while_flag_721 { true };
        do {
          uint8_t id_722 { 0 };
          uint32_t id_723 { n_ref_374[id_722] };
          uint8_t id_724 { 0 };
          uint32_t id_725 { lebsz_ref_375[id_724] };
          uint8_t id_726 { 7 };
          uint32_t id_727 { uint32_t(id_725 << id_726) };
          bool id_728 { bool(id_723 >= id_727) };
          while_flag_721 = id_728;
          if (while_flag_721) {
            uint8_t id_729 { 0 };
            uint8_t id_730 { 0 };
            uint32_t id_731 { lebsz_ref_375[id_730] };
            uint32_t id_732 { 1U };
            uint32_t id_733 { uint32_t(id_731 + id_732) };
            Void id_734 { ((void)(lebsz_ref_375[id_729] = id_733), ::dessser::VOID) };
            (void)id_734;
          }
        } while (while_flag_721);
        (void)::dessser::VOID;
        uint8_t id_735 { 0 };
        uint32_t id_736 { lebsz_ref_375[id_735] };
        Size id_737 { Size(id_736) };
        let_res_720 = id_737;
      }
      let_res_717 = let_res_720;
    }
    std::string id_738 { (*p_0).title };
    uint32_t id_739 { (uint32_t)id_738.size() };
    Size id_740 { Size(id_739) };
    Size id_741 { Size(let_res_717 + id_740) };
    Size let_res_742;
    {
      Size sz_376 { id_741 };
      std::shared_ptr<::dessser::gen::dashboard_widget::type>  id_743 { (*p_0).type };
      Size id_744 { type_sersize_of_row_binary(id_743) };
      Size id_745 { Size(sz_376 + id_744) };
      let_res_742 = id_745;
    }
    Size let_res_746;
    {
      Size sz_377 { let_res_742 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_747 { (*p_0).axes };
      uint32_t id_748 { id_747.size() };
      Vec<1, uint32_t> id_749 {  id_748  };
      Size let_res_750;
      {
        Vec<1, uint32_t> n_ref_378 { id_749 };
        uint32_t id_751 { 1U };
        Vec<1, uint32_t> id_752 {  id_751  };
        Size let_res_753;
        {
          Vec<1, uint32_t> lebsz_ref_379 { id_752 };
          bool while_flag_754 { true };
          do {
            uint8_t id_755 { 0 };
            uint32_t id_756 { n_ref_378[id_755] };
            uint8_t id_757 { 0 };
            uint32_t id_758 { lebsz_ref_379[id_757] };
            uint8_t id_759 { 7 };
            uint32_t id_760 { uint32_t(id_758 << id_759) };
            bool id_761 { bool(id_756 >= id_760) };
            while_flag_754 = id_761;
            if (while_flag_754) {
              uint8_t id_762 { 0 };
              uint8_t id_763 { 0 };
              uint32_t id_764 { lebsz_ref_379[id_763] };
              uint32_t id_765 { 1U };
              uint32_t id_766 { uint32_t(id_764 + id_765) };
              Void id_767 { ((void)(lebsz_ref_379[id_762] = id_766), ::dessser::VOID) };
              (void)id_767;
            }
          } while (while_flag_754);
          (void)::dessser::VOID;
          uint8_t id_768 { 0 };
          uint32_t id_769 { lebsz_ref_379[id_768] };
          Size id_770 { Size(id_769) };
          let_res_753 = id_770;
        }
        let_res_750 = let_res_753;
      }
      Size id_771 { Size(sz_377 + let_res_750) };
      Vec<1, Size> id_772 {  id_771  };
      Size let_res_773;
      {
        Vec<1, Size> sz_ref_380 { id_772 };
        int32_t id_774 { 0L };
        Vec<1, int32_t> id_775 {  id_774  };
        {
          Vec<1, int32_t> repeat_n_381 { id_775 };
          bool while_flag_776 { true };
          do {
            Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_777 { (*p_0).axes };
            uint32_t id_778 { id_777.size() };
            int32_t id_779 { int32_t(id_778) };
            uint8_t id_780 { 0 };
            int32_t id_781 { repeat_n_381[id_780] };
            bool id_782 { bool(id_779 > id_781) };
            while_flag_776 = id_782;
            if (while_flag_776) {
              uint8_t id_783 { 0 };
              uint8_t id_784 { 0 };
              Size id_785 { sz_ref_380[id_784] };
              uint8_t id_786 { 0 };
              int32_t id_787 { repeat_n_381[id_786] };
              Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_788 { (*p_0).axes };
              std::shared_ptr<::dessser::gen::dashboard_widget::axis>  id_789 { id_788[id_787] };
              Size id_790 { axis_sersize_of_row_binary(id_789) };
              Size id_791 { Size(id_785 + id_790) };
              Void id_792 { ((void)(sz_ref_380[id_783] = id_791), ::dessser::VOID) };
              (void)id_792;
              uint8_t id_793 { 0 };
              uint8_t id_794 { 0 };
              int32_t id_795 { repeat_n_381[id_794] };
              int32_t id_796 { 1L };
              int32_t id_797 { int32_t(id_795 + id_796) };
              Void id_798 { ((void)(repeat_n_381[id_793] = id_797), ::dessser::VOID) };
              (void)id_798;
              (void)id_798;
            }
          } while (while_flag_776);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_799 { 0 };
        Size id_800 { sz_ref_380[id_799] };
        let_res_773 = id_800;
      }
      let_res_746 = let_res_773;
    }
    Size let_res_801;
    {
      Size sz_382 { let_res_746 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_802 { (*p_0).sources };
      uint32_t id_803 { id_802.size() };
      Vec<1, uint32_t> id_804 {  id_803  };
      Size let_res_805;
      {
        Vec<1, uint32_t> n_ref_383 { id_804 };
        uint32_t id_806 { 1U };
        Vec<1, uint32_t> id_807 {  id_806  };
        Size let_res_808;
        {
          Vec<1, uint32_t> lebsz_ref_384 { id_807 };
          bool while_flag_809 { true };
          do {
            uint8_t id_810 { 0 };
            uint32_t id_811 { n_ref_383[id_810] };
            uint8_t id_812 { 0 };
            uint32_t id_813 { lebsz_ref_384[id_812] };
            uint8_t id_814 { 7 };
            uint32_t id_815 { uint32_t(id_813 << id_814) };
            bool id_816 { bool(id_811 >= id_815) };
            while_flag_809 = id_816;
            if (while_flag_809) {
              uint8_t id_817 { 0 };
              uint8_t id_818 { 0 };
              uint32_t id_819 { lebsz_ref_384[id_818] };
              uint32_t id_820 { 1U };
              uint32_t id_821 { uint32_t(id_819 + id_820) };
              Void id_822 { ((void)(lebsz_ref_384[id_817] = id_821), ::dessser::VOID) };
              (void)id_822;
            }
          } while (while_flag_809);
          (void)::dessser::VOID;
          uint8_t id_823 { 0 };
          uint32_t id_824 { lebsz_ref_384[id_823] };
          Size id_825 { Size(id_824) };
          let_res_808 = id_825;
        }
        let_res_805 = let_res_808;
      }
      Size id_826 { Size(sz_382 + let_res_805) };
      Vec<1, Size> id_827 {  id_826  };
      Size let_res_828;
      {
        Vec<1, Size> sz_ref_385 { id_827 };
        int32_t id_829 { 0L };
        Vec<1, int32_t> id_830 {  id_829  };
        {
          Vec<1, int32_t> repeat_n_386 { id_830 };
          bool while_flag_831 { true };
          do {
            Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_832 { (*p_0).sources };
            uint32_t id_833 { id_832.size() };
            int32_t id_834 { int32_t(id_833) };
            uint8_t id_835 { 0 };
            int32_t id_836 { repeat_n_386[id_835] };
            bool id_837 { bool(id_834 > id_836) };
            while_flag_831 = id_837;
            if (while_flag_831) {
              uint8_t id_838 { 0 };
              uint8_t id_839 { 0 };
              Size id_840 { sz_ref_385[id_839] };
              uint8_t id_841 { 0 };
              int32_t id_842 { repeat_n_386[id_841] };
              Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_843 { (*p_0).sources };
              std::shared_ptr<::dessser::gen::dashboard_widget::source>  id_844 { id_843[id_842] };
              Size id_845 { source_sersize_of_row_binary(id_844) };
              Size id_846 { Size(id_840 + id_845) };
              Void id_847 { ((void)(sz_ref_385[id_838] = id_846), ::dessser::VOID) };
              (void)id_847;
              uint8_t id_848 { 0 };
              uint8_t id_849 { 0 };
              int32_t id_850 { repeat_n_386[id_849] };
              int32_t id_851 { 1L };
              int32_t id_852 { int32_t(id_850 + id_851) };
              Void id_853 { ((void)(repeat_n_386[id_848] = id_852), ::dessser::VOID) };
              (void)id_853;
              (void)id_853;
            }
          } while (while_flag_831);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_854 { 0 };
        Size id_855 { sz_ref_385[id_854] };
        let_res_828 = id_855;
      }
      let_res_801 = let_res_828;
    }
    return let_res_801;
  }
   };
  return fun713;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::chart> )> chart_sersize_of_row_binary(chart_sersize_of_row_binary_init());

/* 
    (fun ("[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]})[]})]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_389" (make-vec (string-length (get-alt "Text" (param 0))))
              (let "lebsz_ref_390" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_389")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_390")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_390") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_390")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_390")))))) 
            (size-of-u32 (string-length (get-alt "Text" (param 0)))))) 
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "chart-sersize-of-row-binary") (get-alt "Chart" (param 0)))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::t> )> fun856 { [&fun856](std::shared_ptr<::dessser::gen::dashboard_widget::t>  p_0) {
    uint16_t id_857 { 0 };
    uint16_t id_858 { uint16_t((*p_0).index()) };
    bool id_859 { bool(id_857 == id_858) };
    Size choose_res_860;
    if (id_859) {
      Size id_861 { 2UL };
      std::string id_862 { std::get<0 /* Text */>((*p_0)) };
      uint32_t id_863 { (uint32_t)id_862.size() };
      Vec<1, uint32_t> id_864 {  id_863  };
      Size let_res_865;
      {
        Vec<1, uint32_t> n_ref_389 { id_864 };
        uint32_t id_866 { 1U };
        Vec<1, uint32_t> id_867 {  id_866  };
        Size let_res_868;
        {
          Vec<1, uint32_t> lebsz_ref_390 { id_867 };
          bool while_flag_869 { true };
          do {
            uint8_t id_870 { 0 };
            uint32_t id_871 { n_ref_389[id_870] };
            uint8_t id_872 { 0 };
            uint32_t id_873 { lebsz_ref_390[id_872] };
            uint8_t id_874 { 7 };
            uint32_t id_875 { uint32_t(id_873 << id_874) };
            bool id_876 { bool(id_871 >= id_875) };
            while_flag_869 = id_876;
            if (while_flag_869) {
              uint8_t id_877 { 0 };
              uint8_t id_878 { 0 };
              uint32_t id_879 { lebsz_ref_390[id_878] };
              uint32_t id_880 { 1U };
              uint32_t id_881 { uint32_t(id_879 + id_880) };
              Void id_882 { ((void)(lebsz_ref_390[id_877] = id_881), ::dessser::VOID) };
              (void)id_882;
            }
          } while (while_flag_869);
          (void)::dessser::VOID;
          uint8_t id_883 { 0 };
          uint32_t id_884 { lebsz_ref_390[id_883] };
          Size id_885 { Size(id_884) };
          let_res_868 = id_885;
        }
        let_res_865 = let_res_868;
      }
      std::string id_886 { std::get<0 /* Text */>((*p_0)) };
      uint32_t id_887 { (uint32_t)id_886.size() };
      Size id_888 { Size(id_887) };
      Size id_889 { Size(let_res_865 + id_888) };
      Size id_890 { Size(id_861 + id_889) };
      choose_res_860 = id_890;
    } else {
      uint16_t id_891 { uint16_t((*p_0).index()) };
      uint16_t id_892 { 1 };
      bool id_893 { bool(id_891 == id_892) };
      Void id_894 { ((void)(assert(id_893)), ::dessser::VOID) };
      (void)id_894;
      Size id_895 { 2UL };
      std::shared_ptr<::dessser::gen::dashboard_widget::chart>  id_896 { std::get<1 /* Chart */>((*p_0)) };
      Size id_897 { chart_sersize_of_row_binary(id_896) };
      Size id_898 { Size(id_895 + id_897) };
      choose_res_860 = id_898;
    }
    return choose_res_860;
  }
   };
  return fun856;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_107" (apply (ext-identifier fq_function_name of-row-binary) (param 0))
        (let-pair "drec_fst_108" "drec_snd_109" (identifier "drec_107")
          (let "drec_113" (let-pair "dbool_fst_111" "dbool_snd_112" (read-u8 (identifier "drec_snd_109")) (make-tup (not (eq (identifier "dbool_fst_111") (u8 0))) (identifier "dbool_snd_112")))
            (let-pair "drec_fst_114" "drec_snd_115" (identifier "drec_113")
              (let-pair "dlist4_fst_232" "dlist4_snd_233"
                (let "dlist1_125"
                  (let "leb_ref_116" (make-vec (u32 0))
                    (let "shft_ref_117" (make-vec (u8 0))
                      (let "p_ref_118" (make-vec (identifier "drec_snd_115"))
                        (seq
                          (while
                            (let "leb128_119" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_118")))
                              (let-pair "leb128_fst_120" "leb128_snd_121" 
                                (identifier "leb128_119")
                                (seq (set-vec (u8 0) (identifier "p_ref_118") (identifier "leb128_snd_121"))
                                  (set-vec (u8 0) (identifier "leb_ref_116")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_120") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_117"))) (unsafe-nth (u8 0) (identifier "leb_ref_116"))))
                                  (set-vec (u8 0) (identifier "shft_ref_117") (add (unsafe-nth (u8 0) (identifier "shft_ref_117")) (u8 7))) 
                                  (ge (identifier "leb128_fst_120") (u8 128))))) 
                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_116")) (unsafe-nth (u8 0) (identifier "p_ref_118")))))))
                  (let-pair "dlist1_fst_126" "dlist1_snd_127" (identifier "dlist1_125")
                    (let "inits_src_ref_128"
                      (make-vec
                        (make-tup (end-of-list "{opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}")
                          (identifier "dlist1_snd_127")))
                      (seq
                        (let "repeat_n_129" (make-vec (i32 0))
                          (while (gt (to-i32 (identifier "dlist1_fst_126")) (unsafe-nth (u8 0) (identifier "repeat_n_129")))
                            (seq
                              (let "dlist2_130" (unsafe-nth (u8 0) (identifier "inits_src_ref_128"))
                                (let-pair "dlist2_fst_131" "dlist2_snd_132" 
                                  (identifier "dlist2_130")
                                  (set-vec (u8 0) (identifier "inits_src_ref_128")
                                    (let "drec_136"
                                      (let-pair "dfloat_fst_134" "dfloat_snd_135" (read-u64 little-endian (identifier "dlist2_snd_132")) (make-tup (float-of-u64 (identifier "dfloat_fst_134")) (identifier "dfloat_snd_135")))
                                      (let-pair "drec_fst_137" "drec_snd_138" 
                                        (identifier "drec_136")
                                        (let "drec_142" (let-pair "du32_fst_140" "du32_snd_141" (read-u32 little-endian (identifier "drec_snd_138")) (make-tup (identifier "du32_fst_140") (identifier "du32_snd_141")))
                                          (let-pair "drec_fst_143" "drec_snd_144" 
                                            (identifier "drec_142")
                                            (let "drec_166"
                                              (let "dsum1_151" (let-pair "du16_fst_146" "du16_snd_147" (read-u16 little-endian (identifier "drec_snd_144")) (make-tup (identifier "du16_fst_146") (identifier "du16_snd_147")))
                                                (let-pair "dsum1_fst_152" "dsum1_snd_153" 
                                                  (identifier "dsum1_151")
                                                  (if (eq (u16 0) (identifier "dsum1_fst_152")) 
                                                    (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 0 (nop)) (identifier "dsum1_snd_153"))
                                                    (if (eq (u16 1) (identifier "dsum1_fst_152")) 
                                                      (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 1 (nop)) (identifier "dsum1_snd_153"))
                                                      (if (eq (u16 2) (identifier "dsum1_fst_152"))
                                                        (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 2 (nop)) (identifier "dsum1_snd_153"))
                                                        (seq (assert (eq (identifier "dsum1_fst_152") (u16 3)))
                                                          (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 3 (nop)) (identifier "dsum1_snd_153"))))))))
                                              (let-pair "drec_fst_167" "drec_snd_168" 
                                                (identifier "drec_166")
                                                (let "drec_181"
                                                  (let "dstring1_175"
                                                    (let "leb_ref_169" 
                                                      (make-vec (u32 0))
                                                      (let "shft_ref_170" 
                                                        (make-vec (u8 0))
                                                        (let "p_ref_171" 
                                                          (make-vec (identifier "drec_snd_168"))
                                                          (seq
                                                            (while
                                                              (let "leb128_172" 
                                                                (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_171")))
                                                                (let-pair "leb128_fst_173" "leb128_snd_174" 
                                                                  (identifier "leb128_172")
                                                                  (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_171") (identifier "leb128_snd_174"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_169")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_173") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_170")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_169")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_170") (add (unsafe-nth (u8 0) (identifier "shft_ref_170")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_173") (u8 128))))) 
                                                              (nop)) 
                                                            (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_169"))) (unsafe-nth (u8 0) (identifier "p_ref_171")))))))
                                                    (let-pair "dstring1_fst_176" "dstring1_snd_177" 
                                                      (identifier "dstring1_175")
                                                      (let-pair "dstring2_fst_179" "dstring2_snd_180" 
                                                        (read-bytes (identifier "dstring1_snd_177") (identifier "dstring1_fst_176")) 
                                                        (make-tup (string-of-bytes (identifier "dstring2_fst_179")) (identifier "dstring2_snd_180")))))
                                                  (let-pair "drec_fst_182" "drec_snd_183" 
                                                    (identifier "drec_181")
                                                    (let "drec_219"
                                                      (let-pair "dlist4_fst_217" "dlist4_snd_218"
                                                        (let "dlist1_193"
                                                          (let "leb_ref_184" 
                                                            (make-vec (u32 0))
                                                            (let "shft_ref_185" 
                                                              (make-vec (u8 0))
                                                              (let "p_ref_186" 
                                                                (make-vec (identifier "drec_snd_183"))
                                                                (seq
                                                                  (while
                                                                    (let "leb128_187" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_186")))
                                                                    (let-pair "leb128_fst_188" "leb128_snd_189" 
                                                                    (identifier "leb128_187")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_186") (identifier "leb128_snd_189"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_184")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_188") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_185")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_184")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_185") (add (unsafe-nth (u8 0) (identifier "shft_ref_185")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_188") (u8 128))))) 
                                                                    (nop)) 
                                                                  (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_184")) (unsafe-nth (u8 0) (identifier "p_ref_186")))))))
                                                          (let-pair "dlist1_fst_194" "dlist1_snd_195" 
                                                            (identifier "dlist1_193")
                                                            (let "inits_src_ref_196" 
                                                              (make-vec (make-tup (end-of-list "STRING") (identifier "dlist1_snd_195")))
                                                              (seq
                                                                (let "repeat_n_197" 
                                                                  (make-vec (i32 0))
                                                                  (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_194")) (unsafe-nth (u8 0) (identifier "repeat_n_197")))
                                                                    (seq
                                                                    (let "dlist2_198" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_196"))
                                                                    (let-pair "dlist2_fst_199" "dlist2_snd_200" 
                                                                    (identifier "dlist2_198")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_196")
                                                                    (let "dstring1_207"
                                                                    (let "leb_ref_201" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_202" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_203" 
                                                                    (make-vec (identifier "dlist2_snd_200"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_204" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_203")))
                                                                    (let-pair "leb128_fst_205" "leb128_snd_206" 
                                                                    (identifier "leb128_204")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_203") (identifier "leb128_snd_206"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_201")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_205") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_202")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_201")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_202") (add (unsafe-nth (u8 0) (identifier "shft_ref_202")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_205") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_201"))) (unsafe-nth (u8 0) (identifier "p_ref_203")))))))
                                                                    (let-pair "dstring1_fst_208" "dstring1_snd_209" 
                                                                    (identifier "dstring1_207")
                                                                    (let-pair "dstring2_fst_211" "dstring2_snd_212" 
                                                                    (read-bytes (identifier "dstring1_snd_209") (identifier "dstring1_fst_208"))
                                                                    (make-tup (cons (string-of-bytes (identifier "dstring2_fst_211")) (identifier "dlist2_fst_199")) (identifier "dstring2_snd_212"))))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_197") (add (unsafe-nth (u8 0) (identifier "repeat_n_197")) (i32 1))))))
                                                                (unsafe-nth (u8 0) (identifier "inits_src_ref_196")))))) 
                                                        (make-tup (arr-of-lst-rev (identifier "dlist4_fst_217")) (identifier "dlist4_snd_218")))
                                                      (let-pair "drec_fst_220" "drec_snd_221" 
                                                        (identifier "drec_219")
                                                        (let-pair "du8_fst_223" "du8_snd_224" 
                                                          (read-u8 (identifier "drec_snd_221"))
                                                          (make-tup
                                                            (cons
                                                              (make-rec 
                                                                (string "axis") 
                                                                (identifier "du8_fst_223") 
                                                                (string "factors") 
                                                                (identifier "drec_fst_220") 
                                                                (string "column") 
                                                                (identifier "drec_fst_182") 
                                                                (string "representation") 
                                                                (identifier "drec_fst_167") 
                                                                (string "color") 
                                                                (identifier "drec_fst_143") 
                                                                (string "opacity") 
                                                                (identifier "drec_fst_137")) 
                                                              (identifier "dlist2_fst_131")) 
                                                            (identifier "du8_snd_224")))))))))))))))) 
                              (set-vec (u8 0) (identifier "repeat_n_129") (add (unsafe-nth (u8 0) (identifier "repeat_n_129")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "inits_src_ref_128"))))))
                (make-tup (make-rec (string "fields") (arr-of-lst-rev (identifier "dlist4_fst_232")) (string "visible") (identifier "drec_fst_114") (string "name") (identifier "drec_fst_108")) (identifier "dlist4_snd_233"))))))))
 */
static std::function<::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e(Pointer)> source_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e(Pointer)> fun899 { [&fun899](Pointer p_0) {
    auto fun900 { dessser::gen::fq_function_name::of_row_binary };
    ::dessser::gen::dashboard_widget::tc67a116b5bcd191e2624b1f2b2b1794a id_901 { fun900(p_0) };
    ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e let_res_902;
    {
      ::dessser::gen::dashboard_widget::tc67a116b5bcd191e2624b1f2b2b1794a drec_107 { id_901 };
      ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e letpair_res_903;
      {
        auto drec_fst_108 { std::get<0>(drec_107) };
        auto drec_snd_109 { std::get<1>(drec_107) };
        ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_904 { drec_snd_109.readU8() };
        ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e letpair_res_905;
        {
          auto dbool_fst_111 { std::get<0>(id_904) };
          auto dbool_snd_112 { std::get<1>(id_904) };
          uint8_t id_906 { 0 };
          bool id_907 { bool(dbool_fst_111 == id_906) };
          bool id_908 { ! id_907 };
          ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e id_909 { id_908, dbool_snd_112 };
          letpair_res_905 = id_909;
        }
        ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e let_res_910;
        {
          ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e drec_113 { letpair_res_905 };
          ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e letpair_res_911;
          {
            auto drec_fst_114 { std::get<0>(drec_113) };
            auto drec_snd_115 { std::get<1>(drec_113) };
            uint32_t id_912 { 0U };
            Vec<1, uint32_t> id_913 {  id_912  };
            ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_914;
            {
              Vec<1, uint32_t> leb_ref_116 { id_913 };
              uint8_t id_915 { 0 };
              Vec<1, uint8_t> id_916 {  id_915  };
              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_917;
              {
                Vec<1, uint8_t> shft_ref_117 { id_916 };
                Vec<1, Pointer> id_918 {  drec_snd_115  };
                ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_919;
                {
                  Vec<1, Pointer> p_ref_118 { id_918 };
                  bool while_flag_920 { true };
                  do {
                    uint8_t id_921 { 0 };
                    Pointer id_922 { p_ref_118[id_921] };
                    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_923 { id_922.readU8() };
                    bool let_res_924;
                    {
                      ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_119 { id_923 };
                      bool letpair_res_925;
                      {
                        auto leb128_fst_120 { std::get<0>(leb128_119) };
                        auto leb128_snd_121 { std::get<1>(leb128_119) };
                        uint8_t id_926 { 0 };
                        Void id_927 { ((void)(p_ref_118[id_926] = leb128_snd_121), ::dessser::VOID) };
                        (void)id_927;
                        uint8_t id_928 { 0 };
                        uint8_t id_929 { 127 };
                        uint8_t id_930 { uint8_t(leb128_fst_120 & id_929) };
                        uint32_t id_931 { uint32_t(id_930) };
                        uint8_t id_932 { 0 };
                        uint8_t id_933 { shft_ref_117[id_932] };
                        uint32_t id_934 { uint32_t(id_931 << id_933) };
                        uint8_t id_935 { 0 };
                        uint32_t id_936 { leb_ref_116[id_935] };
                        uint32_t id_937 { uint32_t(id_934 | id_936) };
                        Void id_938 { ((void)(leb_ref_116[id_928] = id_937), ::dessser::VOID) };
                        (void)id_938;
                        uint8_t id_939 { 0 };
                        uint8_t id_940 { 0 };
                        uint8_t id_941 { shft_ref_117[id_940] };
                        uint8_t id_942 { 7 };
                        uint8_t id_943 { uint8_t(id_941 + id_942) };
                        Void id_944 { ((void)(shft_ref_117[id_939] = id_943), ::dessser::VOID) };
                        (void)id_944;
                        uint8_t id_945 { 128 };
                        bool id_946 { bool(leb128_fst_120 >= id_945) };
                        letpair_res_925 = id_946;
                      }
                      let_res_924 = letpair_res_925;
                    }
                    while_flag_920 = let_res_924;
                    if (while_flag_920) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_920);
                  (void)::dessser::VOID;
                  uint8_t id_947 { 0 };
                  uint32_t id_948 { leb_ref_116[id_947] };
                  uint8_t id_949 { 0 };
                  Pointer id_950 { p_ref_118[id_949] };
                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_951 { id_948, id_950 };
                  let_res_919 = id_951;
                }
                let_res_917 = let_res_919;
              }
              let_res_914 = let_res_917;
            }
            ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 let_res_952;
            {
              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 dlist1_125 { let_res_914 };
              ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 letpair_res_953;
              {
                auto dlist1_fst_126 { std::get<0>(dlist1_125) };
                auto dlist1_snd_127 { std::get<1>(dlist1_125) };
                Lst<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> endoflist_954;
                ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 id_955 { endoflist_954, dlist1_snd_127 };
                Vec<1, ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0> id_956 {  id_955  };
                ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 let_res_957;
                {
                  Vec<1, ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0> inits_src_ref_128 { id_956 };
                  int32_t id_958 { 0L };
                  Vec<1, int32_t> id_959 {  id_958  };
                  {
                    Vec<1, int32_t> repeat_n_129 { id_959 };
                    bool while_flag_960 { true };
                    do {
                      int32_t id_961 { int32_t(dlist1_fst_126) };
                      uint8_t id_962 { 0 };
                      int32_t id_963 { repeat_n_129[id_962] };
                      bool id_964 { bool(id_961 > id_963) };
                      while_flag_960 = id_964;
                      if (while_flag_960) {
                        uint8_t id_965 { 0 };
                        ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 id_966 { inits_src_ref_128[id_965] };
                        {
                          ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 dlist2_130 { id_966 };
                          {
                            auto dlist2_fst_131 { std::get<0>(dlist2_130) };
                            auto dlist2_snd_132 { std::get<1>(dlist2_130) };
                            uint8_t id_967 { 0 };
                            ::dessser::gen::dashboard_widget::tf568409f41c9c0a265f7302110fc9084 id_968 { dlist2_snd_132.readU64Le() };
                            ::dessser::gen::dashboard_widget::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_969;
                            {
                              auto dfloat_fst_134 { std::get<0>(id_968) };
                              auto dfloat_snd_135 { std::get<1>(id_968) };
                              double id_970 { float_of_qword(dfloat_fst_134) };
                              ::dessser::gen::dashboard_widget::t5375de390f9cb5ae2ee5880ea1674828 id_971 { id_970, dfloat_snd_135 };
                              letpair_res_969 = id_971;
                            }
                            ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 let_res_972;
                            {
                              ::dessser::gen::dashboard_widget::t5375de390f9cb5ae2ee5880ea1674828 drec_136 { letpair_res_969 };
                              ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 letpair_res_973;
                              {
                                auto drec_fst_137 { std::get<0>(drec_136) };
                                auto drec_snd_138 { std::get<1>(drec_136) };
                                ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_974 { drec_snd_138.readU32Le() };
                                ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_975;
                                {
                                  auto du32_fst_140 { std::get<0>(id_974) };
                                  auto du32_snd_141 { std::get<1>(id_974) };
                                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_976 { du32_fst_140, du32_snd_141 };
                                  letpair_res_975 = id_976;
                                }
                                ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 let_res_977;
                                {
                                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 drec_142 { letpair_res_975 };
                                  ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 letpair_res_978;
                                  {
                                    auto drec_fst_143 { std::get<0>(drec_142) };
                                    auto drec_snd_144 { std::get<1>(drec_142) };
                                    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_979 { drec_snd_144.readU16Le() };
                                    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b letpair_res_980;
                                    {
                                      auto du16_fst_146 { std::get<0>(id_979) };
                                      auto du16_snd_147 { std::get<1>(id_979) };
                                      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_981 { du16_fst_146, du16_snd_147 };
                                      letpair_res_980 = id_981;
                                    }
                                    ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 let_res_982;
                                    {
                                      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b dsum1_151 { letpair_res_980 };
                                      ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 letpair_res_983;
                                      {
                                        auto dsum1_fst_152 { std::get<0>(dsum1_151) };
                                        auto dsum1_snd_153 { std::get<1>(dsum1_151) };
                                        uint16_t id_984 { 0 };
                                        bool id_985 { bool(id_984 == dsum1_fst_152) };
                                        ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 choose_res_986;
                                        if (id_985) {
                                          (void)::dessser::VOID;
                                          ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_987 { std::in_place_index<0>, ::dessser::VOID };
                                          ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 id_988 { id_987, dsum1_snd_153 };
                                          choose_res_986 = id_988;
                                        } else {
                                          uint16_t id_989 { 1 };
                                          bool id_990 { bool(id_989 == dsum1_fst_152) };
                                          ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 choose_res_991;
                                          if (id_990) {
                                            (void)::dessser::VOID;
                                            ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_992 { std::in_place_index<1>, ::dessser::VOID };
                                            ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 id_993 { id_992, dsum1_snd_153 };
                                            choose_res_991 = id_993;
                                          } else {
                                            uint16_t id_994 { 2 };
                                            bool id_995 { bool(id_994 == dsum1_fst_152) };
                                            ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 choose_res_996;
                                            if (id_995) {
                                              (void)::dessser::VOID;
                                              ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_997 { std::in_place_index<2>, ::dessser::VOID };
                                              ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 id_998 { id_997, dsum1_snd_153 };
                                              choose_res_996 = id_998;
                                            } else {
                                              uint16_t id_999 { 3 };
                                              bool id_1000 { bool(dsum1_fst_152 == id_999) };
                                              Void id_1001 { ((void)(assert(id_1000)), ::dessser::VOID) };
                                              (void)id_1001;
                                              (void)::dessser::VOID;
                                              ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_1002 { std::in_place_index<3>, ::dessser::VOID };
                                              ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 id_1003 { id_1002, dsum1_snd_153 };
                                              choose_res_996 = id_1003;
                                            }
                                            choose_res_991 = choose_res_996;
                                          }
                                          choose_res_986 = choose_res_991;
                                        }
                                        letpair_res_983 = choose_res_986;
                                      }
                                      let_res_982 = letpair_res_983;
                                    }
                                    ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 let_res_1004;
                                    {
                                      ::dessser::gen::dashboard_widget::tf0dc70c5b7a2a10580e331c050ed9881 drec_166 { let_res_982 };
                                      ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 letpair_res_1005;
                                      {
                                        auto drec_fst_167 { std::get<0>(drec_166) };
                                        auto drec_snd_168 { std::get<1>(drec_166) };
                                        uint32_t id_1006 { 0U };
                                        Vec<1, uint32_t> id_1007 {  id_1006  };
                                        ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1008;
                                        {
                                          Vec<1, uint32_t> leb_ref_169 { id_1007 };
                                          uint8_t id_1009 { 0 };
                                          Vec<1, uint8_t> id_1010 {  id_1009  };
                                          ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1011;
                                          {
                                            Vec<1, uint8_t> shft_ref_170 { id_1010 };
                                            Vec<1, Pointer> id_1012 {  drec_snd_168  };
                                            ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1013;
                                            {
                                              Vec<1, Pointer> p_ref_171 { id_1012 };
                                              bool while_flag_1014 { true };
                                              do {
                                                uint8_t id_1015 { 0 };
                                                Pointer id_1016 { p_ref_171[id_1015] };
                                                ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1017 { id_1016.readU8() };
                                                bool let_res_1018;
                                                {
                                                  ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_172 { id_1017 };
                                                  bool letpair_res_1019;
                                                  {
                                                    auto leb128_fst_173 { std::get<0>(leb128_172) };
                                                    auto leb128_snd_174 { std::get<1>(leb128_172) };
                                                    uint8_t id_1020 { 0 };
                                                    Void id_1021 { ((void)(p_ref_171[id_1020] = leb128_snd_174), ::dessser::VOID) };
                                                    (void)id_1021;
                                                    uint8_t id_1022 { 0 };
                                                    uint8_t id_1023 { 127 };
                                                    uint8_t id_1024 { uint8_t(leb128_fst_173 & id_1023) };
                                                    uint32_t id_1025 { uint32_t(id_1024) };
                                                    uint8_t id_1026 { 0 };
                                                    uint8_t id_1027 { shft_ref_170[id_1026] };
                                                    uint32_t id_1028 { uint32_t(id_1025 << id_1027) };
                                                    uint8_t id_1029 { 0 };
                                                    uint32_t id_1030 { leb_ref_169[id_1029] };
                                                    uint32_t id_1031 { uint32_t(id_1028 | id_1030) };
                                                    Void id_1032 { ((void)(leb_ref_169[id_1022] = id_1031), ::dessser::VOID) };
                                                    (void)id_1032;
                                                    uint8_t id_1033 { 0 };
                                                    uint8_t id_1034 { 0 };
                                                    uint8_t id_1035 { shft_ref_170[id_1034] };
                                                    uint8_t id_1036 { 7 };
                                                    uint8_t id_1037 { uint8_t(id_1035 + id_1036) };
                                                    Void id_1038 { ((void)(shft_ref_170[id_1033] = id_1037), ::dessser::VOID) };
                                                    (void)id_1038;
                                                    uint8_t id_1039 { 128 };
                                                    bool id_1040 { bool(leb128_fst_173 >= id_1039) };
                                                    letpair_res_1019 = id_1040;
                                                  }
                                                  let_res_1018 = letpair_res_1019;
                                                }
                                                while_flag_1014 = let_res_1018;
                                                if (while_flag_1014) {
                                                  (void)::dessser::VOID;
                                                }
                                              } while (while_flag_1014);
                                              (void)::dessser::VOID;
                                              uint8_t id_1041 { 0 };
                                              uint32_t id_1042 { leb_ref_169[id_1041] };
                                              Size id_1043 { Size(id_1042) };
                                              uint8_t id_1044 { 0 };
                                              Pointer id_1045 { p_ref_171[id_1044] };
                                              ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 id_1046 { id_1043, id_1045 };
                                              let_res_1013 = id_1046;
                                            }
                                            let_res_1011 = let_res_1013;
                                          }
                                          let_res_1008 = let_res_1011;
                                        }
                                        ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 let_res_1047;
                                        {
                                          ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 dstring1_175 { let_res_1008 };
                                          ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 letpair_res_1048;
                                          {
                                            auto dstring1_fst_176 { std::get<0>(dstring1_175) };
                                            auto dstring1_snd_177 { std::get<1>(dstring1_175) };
                                            ::dessser::gen::dashboard_widget::t5887709cc43c8c8e24d28211e8c970a2 id_1049 { dstring1_snd_177.readBytes(dstring1_fst_176) };
                                            ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 letpair_res_1050;
                                            {
                                              auto dstring2_fst_179 { std::get<0>(id_1049) };
                                              auto dstring2_snd_180 { std::get<1>(id_1049) };
                                              std::string id_1051 { dstring2_fst_179.toString() };
                                              ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 id_1052 { id_1051, dstring2_snd_180 };
                                              letpair_res_1050 = id_1052;
                                            }
                                            letpair_res_1048 = letpair_res_1050;
                                          }
                                          let_res_1047 = letpair_res_1048;
                                        }
                                        ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 let_res_1053;
                                        {
                                          ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 drec_181 { let_res_1047 };
                                          ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 letpair_res_1054;
                                          {
                                            auto drec_fst_182 { std::get<0>(drec_181) };
                                            auto drec_snd_183 { std::get<1>(drec_181) };
                                            uint32_t id_1055 { 0U };
                                            Vec<1, uint32_t> id_1056 {  id_1055  };
                                            ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1057;
                                            {
                                              Vec<1, uint32_t> leb_ref_184 { id_1056 };
                                              uint8_t id_1058 { 0 };
                                              Vec<1, uint8_t> id_1059 {  id_1058  };
                                              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1060;
                                              {
                                                Vec<1, uint8_t> shft_ref_185 { id_1059 };
                                                Vec<1, Pointer> id_1061 {  drec_snd_183  };
                                                ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1062;
                                                {
                                                  Vec<1, Pointer> p_ref_186 { id_1061 };
                                                  bool while_flag_1063 { true };
                                                  do {
                                                    uint8_t id_1064 { 0 };
                                                    Pointer id_1065 { p_ref_186[id_1064] };
                                                    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1066 { id_1065.readU8() };
                                                    bool let_res_1067;
                                                    {
                                                      ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_187 { id_1066 };
                                                      bool letpair_res_1068;
                                                      {
                                                        auto leb128_fst_188 { std::get<0>(leb128_187) };
                                                        auto leb128_snd_189 { std::get<1>(leb128_187) };
                                                        uint8_t id_1069 { 0 };
                                                        Void id_1070 { ((void)(p_ref_186[id_1069] = leb128_snd_189), ::dessser::VOID) };
                                                        (void)id_1070;
                                                        uint8_t id_1071 { 0 };
                                                        uint8_t id_1072 { 127 };
                                                        uint8_t id_1073 { uint8_t(leb128_fst_188 & id_1072) };
                                                        uint32_t id_1074 { uint32_t(id_1073) };
                                                        uint8_t id_1075 { 0 };
                                                        uint8_t id_1076 { shft_ref_185[id_1075] };
                                                        uint32_t id_1077 { uint32_t(id_1074 << id_1076) };
                                                        uint8_t id_1078 { 0 };
                                                        uint32_t id_1079 { leb_ref_184[id_1078] };
                                                        uint32_t id_1080 { uint32_t(id_1077 | id_1079) };
                                                        Void id_1081 { ((void)(leb_ref_184[id_1071] = id_1080), ::dessser::VOID) };
                                                        (void)id_1081;
                                                        uint8_t id_1082 { 0 };
                                                        uint8_t id_1083 { 0 };
                                                        uint8_t id_1084 { shft_ref_185[id_1083] };
                                                        uint8_t id_1085 { 7 };
                                                        uint8_t id_1086 { uint8_t(id_1084 + id_1085) };
                                                        Void id_1087 { ((void)(shft_ref_185[id_1082] = id_1086), ::dessser::VOID) };
                                                        (void)id_1087;
                                                        uint8_t id_1088 { 128 };
                                                        bool id_1089 { bool(leb128_fst_188 >= id_1088) };
                                                        letpair_res_1068 = id_1089;
                                                      }
                                                      let_res_1067 = letpair_res_1068;
                                                    }
                                                    while_flag_1063 = let_res_1067;
                                                    if (while_flag_1063) {
                                                      (void)::dessser::VOID;
                                                    }
                                                  } while (while_flag_1063);
                                                  (void)::dessser::VOID;
                                                  uint8_t id_1090 { 0 };
                                                  uint32_t id_1091 { leb_ref_184[id_1090] };
                                                  uint8_t id_1092 { 0 };
                                                  Pointer id_1093 { p_ref_186[id_1092] };
                                                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_1094 { id_1091, id_1093 };
                                                  let_res_1062 = id_1094;
                                                }
                                                let_res_1060 = let_res_1062;
                                              }
                                              let_res_1057 = let_res_1060;
                                            }
                                            ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d let_res_1095;
                                            {
                                              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 dlist1_193 { let_res_1057 };
                                              ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d letpair_res_1096;
                                              {
                                                auto dlist1_fst_194 { std::get<0>(dlist1_193) };
                                                auto dlist1_snd_195 { std::get<1>(dlist1_193) };
                                                Lst<std::string> endoflist_1097;
                                                ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d id_1098 { endoflist_1097, dlist1_snd_195 };
                                                Vec<1, ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d> id_1099 {  id_1098  };
                                                ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d let_res_1100;
                                                {
                                                  Vec<1, ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d> inits_src_ref_196 { id_1099 };
                                                  int32_t id_1101 { 0L };
                                                  Vec<1, int32_t> id_1102 {  id_1101  };
                                                  {
                                                    Vec<1, int32_t> repeat_n_197 { id_1102 };
                                                    bool while_flag_1103 { true };
                                                    do {
                                                      int32_t id_1104 { int32_t(dlist1_fst_194) };
                                                      uint8_t id_1105 { 0 };
                                                      int32_t id_1106 { repeat_n_197[id_1105] };
                                                      bool id_1107 { bool(id_1104 > id_1106) };
                                                      while_flag_1103 = id_1107;
                                                      if (while_flag_1103) {
                                                        uint8_t id_1108 { 0 };
                                                        ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d id_1109 { inits_src_ref_196[id_1108] };
                                                        {
                                                          ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d dlist2_198 { id_1109 };
                                                          {
                                                            auto dlist2_fst_199 { std::get<0>(dlist2_198) };
                                                            auto dlist2_snd_200 { std::get<1>(dlist2_198) };
                                                            uint8_t id_1110 { 0 };
                                                            uint32_t id_1111 { 0U };
                                                            Vec<1, uint32_t> id_1112 {  id_1111  };
                                                            ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1113;
                                                            {
                                                              Vec<1, uint32_t> leb_ref_201 { id_1112 };
                                                              uint8_t id_1114 { 0 };
                                                              Vec<1, uint8_t> id_1115 {  id_1114  };
                                                              ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1116;
                                                              {
                                                                Vec<1, uint8_t> shft_ref_202 { id_1115 };
                                                                Vec<1, Pointer> id_1117 {  dlist2_snd_200  };
                                                                ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1118;
                                                                {
                                                                  Vec<1, Pointer> p_ref_203 { id_1117 };
                                                                  bool while_flag_1119 { true };
                                                                  do {
                                                                    uint8_t id_1120 { 0 };
                                                                    Pointer id_1121 { p_ref_203[id_1120] };
                                                                    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1122 { id_1121.readU8() };
                                                                    bool let_res_1123;
                                                                    {
                                                                      ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_204 { id_1122 };
                                                                      bool letpair_res_1124;
                                                                      {
                                                                        auto leb128_fst_205 { std::get<0>(leb128_204) };
                                                                        auto leb128_snd_206 { std::get<1>(leb128_204) };
                                                                        uint8_t id_1125 { 0 };
                                                                        Void id_1126 { ((void)(p_ref_203[id_1125] = leb128_snd_206), ::dessser::VOID) };
                                                                        (void)id_1126;
                                                                        uint8_t id_1127 { 0 };
                                                                        uint8_t id_1128 { 127 };
                                                                        uint8_t id_1129 { uint8_t(leb128_fst_205 & id_1128) };
                                                                        uint32_t id_1130 { uint32_t(id_1129) };
                                                                        uint8_t id_1131 { 0 };
                                                                        uint8_t id_1132 { shft_ref_202[id_1131] };
                                                                        uint32_t id_1133 { uint32_t(id_1130 << id_1132) };
                                                                        uint8_t id_1134 { 0 };
                                                                        uint32_t id_1135 { leb_ref_201[id_1134] };
                                                                        uint32_t id_1136 { uint32_t(id_1133 | id_1135) };
                                                                        Void id_1137 { ((void)(leb_ref_201[id_1127] = id_1136), ::dessser::VOID) };
                                                                        (void)id_1137;
                                                                        uint8_t id_1138 { 0 };
                                                                        uint8_t id_1139 { 0 };
                                                                        uint8_t id_1140 { shft_ref_202[id_1139] };
                                                                        uint8_t id_1141 { 7 };
                                                                        uint8_t id_1142 { uint8_t(id_1140 + id_1141) };
                                                                        Void id_1143 { ((void)(shft_ref_202[id_1138] = id_1142), ::dessser::VOID) };
                                                                        (void)id_1143;
                                                                        uint8_t id_1144 { 128 };
                                                                        bool id_1145 { bool(leb128_fst_205 >= id_1144) };
                                                                        letpair_res_1124 = id_1145;
                                                                      }
                                                                      let_res_1123 = letpair_res_1124;
                                                                    }
                                                                    while_flag_1119 = let_res_1123;
                                                                    if (while_flag_1119) {
                                                                      (void)::dessser::VOID;
                                                                    }
                                                                  } while (while_flag_1119);
                                                                  (void)::dessser::VOID;
                                                                  uint8_t id_1146 { 0 };
                                                                  uint32_t id_1147 { leb_ref_201[id_1146] };
                                                                  Size id_1148 { Size(id_1147) };
                                                                  uint8_t id_1149 { 0 };
                                                                  Pointer id_1150 { p_ref_203[id_1149] };
                                                                  ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 id_1151 { id_1148, id_1150 };
                                                                  let_res_1118 = id_1151;
                                                                }
                                                                let_res_1116 = let_res_1118;
                                                              }
                                                              let_res_1113 = let_res_1116;
                                                            }
                                                            ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d let_res_1152;
                                                            {
                                                              ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 dstring1_207 { let_res_1113 };
                                                              ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d letpair_res_1153;
                                                              {
                                                                auto dstring1_fst_208 { std::get<0>(dstring1_207) };
                                                                auto dstring1_snd_209 { std::get<1>(dstring1_207) };
                                                                ::dessser::gen::dashboard_widget::t5887709cc43c8c8e24d28211e8c970a2 id_1154 { dstring1_snd_209.readBytes(dstring1_fst_208) };
                                                                ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d letpair_res_1155;
                                                                {
                                                                  auto dstring2_fst_211 { std::get<0>(id_1154) };
                                                                  auto dstring2_snd_212 { std::get<1>(id_1154) };
                                                                  std::string id_1156 { dstring2_fst_211.toString() };
                                                                  Lst<std::string> id_1157 { id_1156, dlist2_fst_199 };
                                                                  ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d id_1158 { id_1157, dstring2_snd_212 };
                                                                  letpair_res_1155 = id_1158;
                                                                }
                                                                letpair_res_1153 = letpair_res_1155;
                                                              }
                                                              let_res_1152 = letpair_res_1153;
                                                            }
                                                            Void id_1159 { ((void)(inits_src_ref_196[id_1110] = let_res_1152), ::dessser::VOID) };
                                                            (void)id_1159;
                                                          }
                                                          (void)::dessser::VOID;
                                                        }
                                                        (void)::dessser::VOID;
                                                        uint8_t id_1160 { 0 };
                                                        uint8_t id_1161 { 0 };
                                                        int32_t id_1162 { repeat_n_197[id_1161] };
                                                        int32_t id_1163 { 1L };
                                                        int32_t id_1164 { int32_t(id_1162 + id_1163) };
                                                        Void id_1165 { ((void)(repeat_n_197[id_1160] = id_1164), ::dessser::VOID) };
                                                        (void)id_1165;
                                                        (void)id_1165;
                                                      }
                                                    } while (while_flag_1103);
                                                    (void)::dessser::VOID;
                                                  }
                                                  (void)::dessser::VOID;
                                                  uint8_t id_1166 { 0 };
                                                  ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d id_1167 { inits_src_ref_196[id_1166] };
                                                  let_res_1100 = id_1167;
                                                }
                                                letpair_res_1096 = let_res_1100;
                                              }
                                              let_res_1095 = letpair_res_1096;
                                            }
                                            ::dessser::gen::dashboard_widget::tae8f20319160c4730608853dfb7fd182 letpair_res_1168;
                                            {
                                              auto dlist4_fst_217 { std::get<0>(let_res_1095) };
                                              auto dlist4_snd_218 { std::get<1>(let_res_1095) };
                                              Arr<std::string> id_1169 { dlist4_fst_217.toListRev() };
                                              ::dessser::gen::dashboard_widget::tae8f20319160c4730608853dfb7fd182 id_1170 { id_1169, dlist4_snd_218 };
                                              letpair_res_1168 = id_1170;
                                            }
                                            ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 let_res_1171;
                                            {
                                              ::dessser::gen::dashboard_widget::tae8f20319160c4730608853dfb7fd182 drec_219 { letpair_res_1168 };
                                              ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 letpair_res_1172;
                                              {
                                                auto drec_fst_220 { std::get<0>(drec_219) };
                                                auto drec_snd_221 { std::get<1>(drec_219) };
                                                ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1173 { drec_snd_221.readU8() };
                                                ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 letpair_res_1174;
                                                {
                                                  auto du8_fst_223 { std::get<0>(id_1173) };
                                                  auto du8_snd_224 { std::get<1>(id_1173) };
                                                  ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_1175 { du8_fst_223, drec_fst_143, drec_fst_182, drec_fst_220, drec_fst_137, drec_fst_167 };
                                                  Lst<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_1176 { id_1175, dlist2_fst_131 };
                                                  ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 id_1177 { id_1176, du8_snd_224 };
                                                  letpair_res_1174 = id_1177;
                                                }
                                                letpair_res_1172 = letpair_res_1174;
                                              }
                                              let_res_1171 = letpair_res_1172;
                                            }
                                            letpair_res_1054 = let_res_1171;
                                          }
                                          let_res_1053 = letpair_res_1054;
                                        }
                                        letpair_res_1005 = let_res_1053;
                                      }
                                      let_res_1004 = letpair_res_1005;
                                    }
                                    letpair_res_978 = let_res_1004;
                                  }
                                  let_res_977 = letpair_res_978;
                                }
                                letpair_res_973 = let_res_977;
                              }
                              let_res_972 = letpair_res_973;
                            }
                            Void id_1178 { ((void)(inits_src_ref_128[id_967] = let_res_972), ::dessser::VOID) };
                            (void)id_1178;
                          }
                          (void)::dessser::VOID;
                        }
                        (void)::dessser::VOID;
                        uint8_t id_1179 { 0 };
                        uint8_t id_1180 { 0 };
                        int32_t id_1181 { repeat_n_129[id_1180] };
                        int32_t id_1182 { 1L };
                        int32_t id_1183 { int32_t(id_1181 + id_1182) };
                        Void id_1184 { ((void)(repeat_n_129[id_1179] = id_1183), ::dessser::VOID) };
                        (void)id_1184;
                        (void)id_1184;
                      }
                    } while (while_flag_960);
                    (void)::dessser::VOID;
                  }
                  (void)::dessser::VOID;
                  uint8_t id_1185 { 0 };
                  ::dessser::gen::dashboard_widget::t3fd42cf02103165757b46133ec4aa4a0 id_1186 { inits_src_ref_128[id_1185] };
                  let_res_957 = id_1186;
                }
                letpair_res_953 = let_res_957;
              }
              let_res_952 = letpair_res_953;
            }
            ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e letpair_res_1187;
            {
              auto dlist4_fst_232 { std::get<0>(let_res_952) };
              auto dlist4_snd_233 { std::get<1>(let_res_952) };
              Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_1188 { dlist4_fst_232.toListRev() };
              std::shared_ptr<::dessser::gen::dashboard_widget::source>  id_1189 { std::make_shared<::dessser::gen::dashboard_widget::source>(id_1188, drec_fst_108, drec_fst_114) };
              ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e id_1190 { id_1189, dlist4_snd_233 };
              letpair_res_1187 = id_1190;
            }
            letpair_res_911 = letpair_res_1187;
          }
          let_res_910 = letpair_res_911;
        }
        letpair_res_903 = let_res_910;
      }
      let_res_902 = letpair_res_903;
    }
    return let_res_902;
  }
   };
  return fun899;
}
std::function<::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e(Pointer)> source_of_row_binary(source_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_87" "make_snd_88"
        (let "dsum1_77" (let-pair "du16_fst_72" "du16_snd_73" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_72") (identifier "du16_snd_73")))
          (let-pair "dsum1_fst_78" "dsum1_snd_79" (identifier "dsum1_77")
            (if (eq (u16 0) (identifier "dsum1_fst_78")) (make-tup (construct "[Linear Void | Logarithmic Void]" 0 (nop)) (identifier "dsum1_snd_79"))
              (seq (assert (eq (identifier "dsum1_fst_78") (u16 1))) (make-tup (construct "[Linear Void | Logarithmic Void]" 1 (nop)) (identifier "dsum1_snd_79"))))))
        (make-tup (identifier "make_fst_87") (identifier "make_snd_88"))))
 */
static std::function<::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7(Pointer)> scale_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7(Pointer)> fun1191 { [&fun1191](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1192 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1193;
    {
      auto du16_fst_72 { std::get<0>(id_1192) };
      auto du16_snd_73 { std::get<1>(id_1192) };
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1194 { du16_fst_72, du16_snd_73 };
      letpair_res_1193 = id_1194;
    }
    ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 let_res_1195;
    {
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b dsum1_77 { letpair_res_1193 };
      ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 letpair_res_1196;
      {
        auto dsum1_fst_78 { std::get<0>(dsum1_77) };
        auto dsum1_snd_79 { std::get<1>(dsum1_77) };
        uint16_t id_1197 { 0 };
        bool id_1198 { bool(id_1197 == dsum1_fst_78) };
        ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 choose_res_1199;
        if (id_1198) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::dashboard_widget::scale>  id_1200 { std::make_shared<::dessser::gen::dashboard_widget::scale>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 id_1201 { id_1200, dsum1_snd_79 };
          choose_res_1199 = id_1201;
        } else {
          uint16_t id_1202 { 1 };
          bool id_1203 { bool(dsum1_fst_78 == id_1202) };
          Void id_1204 { ((void)(assert(id_1203)), ::dessser::VOID) };
          (void)id_1204;
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::dashboard_widget::scale>  id_1205 { std::make_shared<::dessser::gen::dashboard_widget::scale>(std::in_place_index<1>, ::dessser::VOID) };
          ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 id_1206 { id_1205, dsum1_snd_79 };
          choose_res_1199 = id_1206;
        }
        letpair_res_1196 = choose_res_1199;
      }
      let_res_1195 = letpair_res_1196;
    }
    ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 letpair_res_1207;
    {
      auto make_fst_87 { std::get<0>(let_res_1195) };
      auto make_snd_88 { std::get<1>(let_res_1195) };
      ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 id_1208 { make_fst_87, make_snd_88 };
      letpair_res_1207 = id_1208;
    }
    return letpair_res_1207;
  }
   };
  return fun1191;
}
std::function<::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7(Pointer)> scale_of_row_binary(scale_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_92" (let-pair "dbool_fst_90" "dbool_snd_91" (read-u8 (param 0)) (make-tup (not (eq (identifier "dbool_fst_90") (u8 0))) (identifier "dbool_snd_91")))
        (let-pair "drec_fst_93" "drec_snd_94" (identifier "drec_92")
          (let "drec_98" (let-pair "dbool_fst_96" "dbool_snd_97" (read-u8 (identifier "drec_snd_94")) (make-tup (not (eq (identifier "dbool_fst_96") (u8 0))) (identifier "dbool_snd_97")))
            (let-pair "drec_fst_99" "drec_snd_100" (identifier "drec_98")
              (let-pair "drec_fst_102" "drec_snd_103" (apply (identifier "scale-of-row-binary") (identifier "drec_snd_100"))
                (make-tup (make-rec (string "scale") (identifier "drec_fst_102") (string "force_zero") (identifier "drec_fst_99") (string "left") (identifier "drec_fst_93")) (identifier "drec_snd_103"))))))))
 */
static std::function<::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552(Pointer)> axis_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552(Pointer)> fun1209 { [&fun1209](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1210 { p_0.readU8() };
    ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e letpair_res_1211;
    {
      auto dbool_fst_90 { std::get<0>(id_1210) };
      auto dbool_snd_91 { std::get<1>(id_1210) };
      uint8_t id_1212 { 0 };
      bool id_1213 { bool(dbool_fst_90 == id_1212) };
      bool id_1214 { ! id_1213 };
      ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e id_1215 { id_1214, dbool_snd_91 };
      letpair_res_1211 = id_1215;
    }
    ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 let_res_1216;
    {
      ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e drec_92 { letpair_res_1211 };
      ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 letpair_res_1217;
      {
        auto drec_fst_93 { std::get<0>(drec_92) };
        auto drec_snd_94 { std::get<1>(drec_92) };
        ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1218 { drec_snd_94.readU8() };
        ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e letpair_res_1219;
        {
          auto dbool_fst_96 { std::get<0>(id_1218) };
          auto dbool_snd_97 { std::get<1>(id_1218) };
          uint8_t id_1220 { 0 };
          bool id_1221 { bool(dbool_fst_96 == id_1220) };
          bool id_1222 { ! id_1221 };
          ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e id_1223 { id_1222, dbool_snd_97 };
          letpair_res_1219 = id_1223;
        }
        ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 let_res_1224;
        {
          ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e drec_98 { letpair_res_1219 };
          ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 letpair_res_1225;
          {
            auto drec_fst_99 { std::get<0>(drec_98) };
            auto drec_snd_100 { std::get<1>(drec_98) };
            ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 id_1226 { scale_of_row_binary(drec_snd_100) };
            ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 letpair_res_1227;
            {
              auto drec_fst_102 { std::get<0>(id_1226) };
              auto drec_snd_103 { std::get<1>(id_1226) };
              std::shared_ptr<::dessser::gen::dashboard_widget::axis>  id_1228 { std::make_shared<::dessser::gen::dashboard_widget::axis>(drec_fst_99, drec_fst_93, drec_fst_102) };
              ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 id_1229 { id_1228, drec_snd_103 };
              letpair_res_1227 = id_1229;
            }
            letpair_res_1225 = letpair_res_1227;
          }
          let_res_1224 = letpair_res_1225;
        }
        letpair_res_1217 = let_res_1224;
      }
      let_res_1216 = letpair_res_1217;
    }
    return let_res_1216;
  }
   };
  return fun1209;
}
std::function<::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552(Pointer)> axis_of_row_binary(axis_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62") (seq (assert (eq (identifier "dsum1_fst_63") (u16 0))) (make-tup (construct "[Plot Void]" 0 (nop)) (identifier "dsum1_snd_64"))))))
 */
static std::function<::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681(Pointer)> type_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681(Pointer)> fun1230 { [&fun1230](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1231 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1232;
    {
      auto du16_fst_57 { std::get<0>(id_1231) };
      auto du16_snd_58 { std::get<1>(id_1231) };
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1233 { du16_fst_57, du16_snd_58 };
      letpair_res_1232 = id_1233;
    }
    ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 let_res_1234;
    {
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_1232 };
      ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 letpair_res_1235;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_1236 { 0 };
        bool id_1237 { bool(dsum1_fst_63 == id_1236) };
        Void id_1238 { ((void)(assert(id_1237)), ::dessser::VOID) };
        (void)id_1238;
        (void)::dessser::VOID;
        std::shared_ptr<::dessser::gen::dashboard_widget::type>  id_1239 { std::make_shared<::dessser::gen::dashboard_widget::type>(std::in_place_index<0>, ::dessser::VOID) };
        ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 id_1240 { id_1239, dsum1_snd_64 };
        letpair_res_1235 = id_1240;
      }
      let_res_1234 = letpair_res_1235;
    }
    return let_res_1234;
  }
   };
  return fun1230;
}
std::function<::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681(Pointer)> type_of_row_binary(type_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_252"
        (let "dstring1_246"
          (let "leb_ref_240" (make-vec (u32 0))
            (let "shft_ref_241" (make-vec (u8 0))
              (let "p_ref_242" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_243" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_242")))
                      (let-pair "leb128_fst_244" "leb128_snd_245" (identifier "leb128_243")
                        (seq (set-vec (u8 0) (identifier "p_ref_242") (identifier "leb128_snd_245"))
                          (set-vec (u8 0) (identifier "leb_ref_240")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_244") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_241"))) (unsafe-nth (u8 0) (identifier "leb_ref_240"))))
                          (set-vec (u8 0) (identifier "shft_ref_241") (add (unsafe-nth (u8 0) (identifier "shft_ref_241")) (u8 7))) 
                          (ge (identifier "leb128_fst_244") (u8 128))))) 
                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_240"))) (unsafe-nth (u8 0) (identifier "p_ref_242")))))))
          (let-pair "dstring1_fst_247" "dstring1_snd_248" (identifier "dstring1_246")
            (let-pair "dstring2_fst_250" "dstring2_snd_251" (read-bytes (identifier "dstring1_snd_248") (identifier "dstring1_fst_247"))
              (make-tup (string-of-bytes (identifier "dstring2_fst_250")) (identifier "dstring2_snd_251")))))
        (let-pair "drec_fst_253" "drec_snd_254" (identifier "drec_252")
          (let "drec_255" (apply (identifier "type-of-row-binary") (identifier "drec_snd_254"))
            (let-pair "drec_fst_256" "drec_snd_257" (identifier "drec_255")
              (let "drec_281"
                (let-pair "dlist4_fst_279" "dlist4_snd_280"
                  (let "dlist1_267"
                    (let "leb_ref_258" (make-vec (u32 0))
                      (let "shft_ref_259" (make-vec (u8 0))
                        (let "p_ref_260" (make-vec (identifier "drec_snd_257"))
                          (seq
                            (while
                              (let "leb128_261" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_260")))
                                (let-pair "leb128_fst_262" "leb128_snd_263" 
                                  (identifier "leb128_261")
                                  (seq (set-vec (u8 0) (identifier "p_ref_260") (identifier "leb128_snd_263"))
                                    (set-vec (u8 0) (identifier "leb_ref_258")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_262") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_259"))) (unsafe-nth (u8 0) (identifier "leb_ref_258"))))
                                    (set-vec (u8 0) (identifier "shft_ref_259") (add (unsafe-nth (u8 0) (identifier "shft_ref_259")) (u8 7))) 
                                    (ge (identifier "leb128_fst_262") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_258")) (unsafe-nth (u8 0) (identifier "p_ref_260")))))))
                    (let-pair "dlist1_fst_268" "dlist1_snd_269" (identifier "dlist1_267")
                      (let "inits_src_ref_270" (make-vec (make-tup (end-of-list "(axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})") (identifier "dlist1_snd_269")))
                        (seq
                          (let "repeat_n_271" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_268")) (unsafe-nth (u8 0) (identifier "repeat_n_271")))
                              (seq
                                (let "dlist2_272" (unsafe-nth (u8 0) (identifier "inits_src_ref_270"))
                                  (let-pair "dlist2_fst_273" "dlist2_snd_274" 
                                    (identifier "dlist2_272")
                                    (set-vec (u8 0) (identifier "inits_src_ref_270")
                                      (let-pair "dlist3_fst_276" "dlist3_snd_277" 
                                        (apply (identifier "axis-of-row-binary") (identifier "dlist2_snd_274")) 
                                        (make-tup (cons (identifier "dlist3_fst_276") (identifier "dlist2_fst_273")) (identifier "dlist3_snd_277"))))))
                                (set-vec (u8 0) (identifier "repeat_n_271") (add (unsafe-nth (u8 0) (identifier "repeat_n_271")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_270")))))) 
                  (make-tup (arr-of-lst-rev (identifier "dlist4_fst_279")) (identifier "dlist4_snd_280")))
                (let-pair "drec_fst_282" "drec_snd_283" (identifier "drec_281")
                  (let-pair "dlist4_fst_305" "dlist4_snd_306"
                    (let "dlist1_293"
                      (let "leb_ref_284" (make-vec (u32 0))
                        (let "shft_ref_285" (make-vec (u8 0))
                          (let "p_ref_286" (make-vec (identifier "drec_snd_283"))
                            (seq
                              (while
                                (let "leb128_287" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_286")))
                                  (let-pair "leb128_fst_288" "leb128_snd_289" 
                                    (identifier "leb128_287")
                                    (seq (set-vec (u8 0) (identifier "p_ref_286") (identifier "leb128_snd_289"))
                                      (set-vec (u8 0) (identifier "leb_ref_284")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_288") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_285"))) (unsafe-nth (u8 0) (identifier "leb_ref_284"))))
                                      (set-vec (u8 0) (identifier "shft_ref_285") (add (unsafe-nth (u8 0) (identifier "shft_ref_285")) (u8 7))) 
                                      (ge (identifier "leb128_fst_288") (u8 128))))) 
                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_284")) (unsafe-nth (u8 0) (identifier "p_ref_286")))))))
                      (let-pair "dlist1_fst_294" "dlist1_snd_295" (identifier "dlist1_293")
                        (let "inits_src_ref_296"
                          (make-vec
                            (make-tup
                              (end-of-list "(source AS {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]})")
                              (identifier "dlist1_snd_295")))
                          (seq
                            (let "repeat_n_297" (make-vec (i32 0))
                              (while (gt (to-i32 (identifier "dlist1_fst_294")) (unsafe-nth (u8 0) (identifier "repeat_n_297")))
                                (seq
                                  (let "dlist2_298" (unsafe-nth (u8 0) (identifier "inits_src_ref_296"))
                                    (let-pair "dlist2_fst_299" "dlist2_snd_300" 
                                      (identifier "dlist2_298")
                                      (set-vec (u8 0) (identifier "inits_src_ref_296")
                                        (let-pair "dlist3_fst_302" "dlist3_snd_303" 
                                          (apply (identifier "source-of-row-binary") (identifier "dlist2_snd_300")) 
                                          (make-tup (cons (identifier "dlist3_fst_302") (identifier "dlist2_fst_299")) (identifier "dlist3_snd_303"))))))
                                  (set-vec (u8 0) (identifier "repeat_n_297") (add (unsafe-nth (u8 0) (identifier "repeat_n_297")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "inits_src_ref_296"))))))
                    (make-tup
                      (make-rec (string "sources") (arr-of-lst-rev (identifier "dlist4_fst_305")) 
                        (string "axes") (identifier "drec_fst_282") (string "type") 
                        (identifier "drec_fst_256") (string "title") 
                        (identifier "drec_fst_253")) (identifier "dlist4_snd_306"))))))))))
 */
static std::function<::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70(Pointer)> chart_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70(Pointer)> fun1241 { [&fun1241](Pointer p_0) {
    uint32_t id_1242 { 0U };
    Vec<1, uint32_t> id_1243 {  id_1242  };
    ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1244;
    {
      Vec<1, uint32_t> leb_ref_240 { id_1243 };
      uint8_t id_1245 { 0 };
      Vec<1, uint8_t> id_1246 {  id_1245  };
      ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1247;
      {
        Vec<1, uint8_t> shft_ref_241 { id_1246 };
        Vec<1, Pointer> id_1248 {  p_0  };
        ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1249;
        {
          Vec<1, Pointer> p_ref_242 { id_1248 };
          bool while_flag_1250 { true };
          do {
            uint8_t id_1251 { 0 };
            Pointer id_1252 { p_ref_242[id_1251] };
            ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1253 { id_1252.readU8() };
            bool let_res_1254;
            {
              ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_243 { id_1253 };
              bool letpair_res_1255;
              {
                auto leb128_fst_244 { std::get<0>(leb128_243) };
                auto leb128_snd_245 { std::get<1>(leb128_243) };
                uint8_t id_1256 { 0 };
                Void id_1257 { ((void)(p_ref_242[id_1256] = leb128_snd_245), ::dessser::VOID) };
                (void)id_1257;
                uint8_t id_1258 { 0 };
                uint8_t id_1259 { 127 };
                uint8_t id_1260 { uint8_t(leb128_fst_244 & id_1259) };
                uint32_t id_1261 { uint32_t(id_1260) };
                uint8_t id_1262 { 0 };
                uint8_t id_1263 { shft_ref_241[id_1262] };
                uint32_t id_1264 { uint32_t(id_1261 << id_1263) };
                uint8_t id_1265 { 0 };
                uint32_t id_1266 { leb_ref_240[id_1265] };
                uint32_t id_1267 { uint32_t(id_1264 | id_1266) };
                Void id_1268 { ((void)(leb_ref_240[id_1258] = id_1267), ::dessser::VOID) };
                (void)id_1268;
                uint8_t id_1269 { 0 };
                uint8_t id_1270 { 0 };
                uint8_t id_1271 { shft_ref_241[id_1270] };
                uint8_t id_1272 { 7 };
                uint8_t id_1273 { uint8_t(id_1271 + id_1272) };
                Void id_1274 { ((void)(shft_ref_241[id_1269] = id_1273), ::dessser::VOID) };
                (void)id_1274;
                uint8_t id_1275 { 128 };
                bool id_1276 { bool(leb128_fst_244 >= id_1275) };
                letpair_res_1255 = id_1276;
              }
              let_res_1254 = letpair_res_1255;
            }
            while_flag_1250 = let_res_1254;
            if (while_flag_1250) {
              (void)::dessser::VOID;
            }
          } while (while_flag_1250);
          (void)::dessser::VOID;
          uint8_t id_1277 { 0 };
          uint32_t id_1278 { leb_ref_240[id_1277] };
          Size id_1279 { Size(id_1278) };
          uint8_t id_1280 { 0 };
          Pointer id_1281 { p_ref_242[id_1280] };
          ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 id_1282 { id_1279, id_1281 };
          let_res_1249 = id_1282;
        }
        let_res_1247 = let_res_1249;
      }
      let_res_1244 = let_res_1247;
    }
    ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 let_res_1283;
    {
      ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 dstring1_246 { let_res_1244 };
      ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 letpair_res_1284;
      {
        auto dstring1_fst_247 { std::get<0>(dstring1_246) };
        auto dstring1_snd_248 { std::get<1>(dstring1_246) };
        ::dessser::gen::dashboard_widget::t5887709cc43c8c8e24d28211e8c970a2 id_1285 { dstring1_snd_248.readBytes(dstring1_fst_247) };
        ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 letpair_res_1286;
        {
          auto dstring2_fst_250 { std::get<0>(id_1285) };
          auto dstring2_snd_251 { std::get<1>(id_1285) };
          std::string id_1287 { dstring2_fst_250.toString() };
          ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 id_1288 { id_1287, dstring2_snd_251 };
          letpair_res_1286 = id_1288;
        }
        letpair_res_1284 = letpair_res_1286;
      }
      let_res_1283 = letpair_res_1284;
    }
    ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 let_res_1289;
    {
      ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 drec_252 { let_res_1283 };
      ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 letpair_res_1290;
      {
        auto drec_fst_253 { std::get<0>(drec_252) };
        auto drec_snd_254 { std::get<1>(drec_252) };
        ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 id_1291 { type_of_row_binary(drec_snd_254) };
        ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 let_res_1292;
        {
          ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 drec_255 { id_1291 };
          ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 letpair_res_1293;
          {
            auto drec_fst_256 { std::get<0>(drec_255) };
            auto drec_snd_257 { std::get<1>(drec_255) };
            uint32_t id_1294 { 0U };
            Vec<1, uint32_t> id_1295 {  id_1294  };
            ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1296;
            {
              Vec<1, uint32_t> leb_ref_258 { id_1295 };
              uint8_t id_1297 { 0 };
              Vec<1, uint8_t> id_1298 {  id_1297  };
              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1299;
              {
                Vec<1, uint8_t> shft_ref_259 { id_1298 };
                Vec<1, Pointer> id_1300 {  drec_snd_257  };
                ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1301;
                {
                  Vec<1, Pointer> p_ref_260 { id_1300 };
                  bool while_flag_1302 { true };
                  do {
                    uint8_t id_1303 { 0 };
                    Pointer id_1304 { p_ref_260[id_1303] };
                    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1305 { id_1304.readU8() };
                    bool let_res_1306;
                    {
                      ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_261 { id_1305 };
                      bool letpair_res_1307;
                      {
                        auto leb128_fst_262 { std::get<0>(leb128_261) };
                        auto leb128_snd_263 { std::get<1>(leb128_261) };
                        uint8_t id_1308 { 0 };
                        Void id_1309 { ((void)(p_ref_260[id_1308] = leb128_snd_263), ::dessser::VOID) };
                        (void)id_1309;
                        uint8_t id_1310 { 0 };
                        uint8_t id_1311 { 127 };
                        uint8_t id_1312 { uint8_t(leb128_fst_262 & id_1311) };
                        uint32_t id_1313 { uint32_t(id_1312) };
                        uint8_t id_1314 { 0 };
                        uint8_t id_1315 { shft_ref_259[id_1314] };
                        uint32_t id_1316 { uint32_t(id_1313 << id_1315) };
                        uint8_t id_1317 { 0 };
                        uint32_t id_1318 { leb_ref_258[id_1317] };
                        uint32_t id_1319 { uint32_t(id_1316 | id_1318) };
                        Void id_1320 { ((void)(leb_ref_258[id_1310] = id_1319), ::dessser::VOID) };
                        (void)id_1320;
                        uint8_t id_1321 { 0 };
                        uint8_t id_1322 { 0 };
                        uint8_t id_1323 { shft_ref_259[id_1322] };
                        uint8_t id_1324 { 7 };
                        uint8_t id_1325 { uint8_t(id_1323 + id_1324) };
                        Void id_1326 { ((void)(shft_ref_259[id_1321] = id_1325), ::dessser::VOID) };
                        (void)id_1326;
                        uint8_t id_1327 { 128 };
                        bool id_1328 { bool(leb128_fst_262 >= id_1327) };
                        letpair_res_1307 = id_1328;
                      }
                      let_res_1306 = letpair_res_1307;
                    }
                    while_flag_1302 = let_res_1306;
                    if (while_flag_1302) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_1302);
                  (void)::dessser::VOID;
                  uint8_t id_1329 { 0 };
                  uint32_t id_1330 { leb_ref_258[id_1329] };
                  uint8_t id_1331 { 0 };
                  Pointer id_1332 { p_ref_260[id_1331] };
                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_1333 { id_1330, id_1332 };
                  let_res_1301 = id_1333;
                }
                let_res_1299 = let_res_1301;
              }
              let_res_1296 = let_res_1299;
            }
            ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 let_res_1334;
            {
              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 dlist1_267 { let_res_1296 };
              ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 letpair_res_1335;
              {
                auto dlist1_fst_268 { std::get<0>(dlist1_267) };
                auto dlist1_snd_269 { std::get<1>(dlist1_267) };
                Lst<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > endoflist_1336;
                ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 id_1337 { endoflist_1336, dlist1_snd_269 };
                Vec<1, ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3> id_1338 {  id_1337  };
                ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 let_res_1339;
                {
                  Vec<1, ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3> inits_src_ref_270 { id_1338 };
                  int32_t id_1340 { 0L };
                  Vec<1, int32_t> id_1341 {  id_1340  };
                  {
                    Vec<1, int32_t> repeat_n_271 { id_1341 };
                    bool while_flag_1342 { true };
                    do {
                      int32_t id_1343 { int32_t(dlist1_fst_268) };
                      uint8_t id_1344 { 0 };
                      int32_t id_1345 { repeat_n_271[id_1344] };
                      bool id_1346 { bool(id_1343 > id_1345) };
                      while_flag_1342 = id_1346;
                      if (while_flag_1342) {
                        uint8_t id_1347 { 0 };
                        ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 id_1348 { inits_src_ref_270[id_1347] };
                        {
                          ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 dlist2_272 { id_1348 };
                          {
                            auto dlist2_fst_273 { std::get<0>(dlist2_272) };
                            auto dlist2_snd_274 { std::get<1>(dlist2_272) };
                            uint8_t id_1349 { 0 };
                            ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 id_1350 { axis_of_row_binary(dlist2_snd_274) };
                            ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 letpair_res_1351;
                            {
                              auto dlist3_fst_276 { std::get<0>(id_1350) };
                              auto dlist3_snd_277 { std::get<1>(id_1350) };
                              Lst<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_1352 { dlist3_fst_276, dlist2_fst_273 };
                              ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 id_1353 { id_1352, dlist3_snd_277 };
                              letpair_res_1351 = id_1353;
                            }
                            Void id_1354 { ((void)(inits_src_ref_270[id_1349] = letpair_res_1351), ::dessser::VOID) };
                            (void)id_1354;
                          }
                          (void)::dessser::VOID;
                        }
                        (void)::dessser::VOID;
                        uint8_t id_1355 { 0 };
                        uint8_t id_1356 { 0 };
                        int32_t id_1357 { repeat_n_271[id_1356] };
                        int32_t id_1358 { 1L };
                        int32_t id_1359 { int32_t(id_1357 + id_1358) };
                        Void id_1360 { ((void)(repeat_n_271[id_1355] = id_1359), ::dessser::VOID) };
                        (void)id_1360;
                        (void)id_1360;
                      }
                    } while (while_flag_1342);
                    (void)::dessser::VOID;
                  }
                  (void)::dessser::VOID;
                  uint8_t id_1361 { 0 };
                  ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 id_1362 { inits_src_ref_270[id_1361] };
                  let_res_1339 = id_1362;
                }
                letpair_res_1335 = let_res_1339;
              }
              let_res_1334 = letpair_res_1335;
            }
            ::dessser::gen::dashboard_widget::tb55c7f64967782dbcd42b37a9d7d6eed letpair_res_1363;
            {
              auto dlist4_fst_279 { std::get<0>(let_res_1334) };
              auto dlist4_snd_280 { std::get<1>(let_res_1334) };
              Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_1364 { dlist4_fst_279.toListRev() };
              ::dessser::gen::dashboard_widget::tb55c7f64967782dbcd42b37a9d7d6eed id_1365 { id_1364, dlist4_snd_280 };
              letpair_res_1363 = id_1365;
            }
            ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 let_res_1366;
            {
              ::dessser::gen::dashboard_widget::tb55c7f64967782dbcd42b37a9d7d6eed drec_281 { letpair_res_1363 };
              ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 letpair_res_1367;
              {
                auto drec_fst_282 { std::get<0>(drec_281) };
                auto drec_snd_283 { std::get<1>(drec_281) };
                uint32_t id_1368 { 0U };
                Vec<1, uint32_t> id_1369 {  id_1368  };
                ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1370;
                {
                  Vec<1, uint32_t> leb_ref_284 { id_1369 };
                  uint8_t id_1371 { 0 };
                  Vec<1, uint8_t> id_1372 {  id_1371  };
                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1373;
                  {
                    Vec<1, uint8_t> shft_ref_285 { id_1372 };
                    Vec<1, Pointer> id_1374 {  drec_snd_283  };
                    ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1375;
                    {
                      Vec<1, Pointer> p_ref_286 { id_1374 };
                      bool while_flag_1376 { true };
                      do {
                        uint8_t id_1377 { 0 };
                        Pointer id_1378 { p_ref_286[id_1377] };
                        ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1379 { id_1378.readU8() };
                        bool let_res_1380;
                        {
                          ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_287 { id_1379 };
                          bool letpair_res_1381;
                          {
                            auto leb128_fst_288 { std::get<0>(leb128_287) };
                            auto leb128_snd_289 { std::get<1>(leb128_287) };
                            uint8_t id_1382 { 0 };
                            Void id_1383 { ((void)(p_ref_286[id_1382] = leb128_snd_289), ::dessser::VOID) };
                            (void)id_1383;
                            uint8_t id_1384 { 0 };
                            uint8_t id_1385 { 127 };
                            uint8_t id_1386 { uint8_t(leb128_fst_288 & id_1385) };
                            uint32_t id_1387 { uint32_t(id_1386) };
                            uint8_t id_1388 { 0 };
                            uint8_t id_1389 { shft_ref_285[id_1388] };
                            uint32_t id_1390 { uint32_t(id_1387 << id_1389) };
                            uint8_t id_1391 { 0 };
                            uint32_t id_1392 { leb_ref_284[id_1391] };
                            uint32_t id_1393 { uint32_t(id_1390 | id_1392) };
                            Void id_1394 { ((void)(leb_ref_284[id_1384] = id_1393), ::dessser::VOID) };
                            (void)id_1394;
                            uint8_t id_1395 { 0 };
                            uint8_t id_1396 { 0 };
                            uint8_t id_1397 { shft_ref_285[id_1396] };
                            uint8_t id_1398 { 7 };
                            uint8_t id_1399 { uint8_t(id_1397 + id_1398) };
                            Void id_1400 { ((void)(shft_ref_285[id_1395] = id_1399), ::dessser::VOID) };
                            (void)id_1400;
                            uint8_t id_1401 { 128 };
                            bool id_1402 { bool(leb128_fst_288 >= id_1401) };
                            letpair_res_1381 = id_1402;
                          }
                          let_res_1380 = letpair_res_1381;
                        }
                        while_flag_1376 = let_res_1380;
                        if (while_flag_1376) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_1376);
                      (void)::dessser::VOID;
                      uint8_t id_1403 { 0 };
                      uint32_t id_1404 { leb_ref_284[id_1403] };
                      uint8_t id_1405 { 0 };
                      Pointer id_1406 { p_ref_286[id_1405] };
                      ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_1407 { id_1404, id_1406 };
                      let_res_1375 = id_1407;
                    }
                    let_res_1373 = let_res_1375;
                  }
                  let_res_1370 = let_res_1373;
                }
                ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 let_res_1408;
                {
                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 dlist1_293 { let_res_1370 };
                  ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 letpair_res_1409;
                  {
                    auto dlist1_fst_294 { std::get<0>(dlist1_293) };
                    auto dlist1_snd_295 { std::get<1>(dlist1_293) };
                    Lst<std::shared_ptr<::dessser::gen::dashboard_widget::source> > endoflist_1410;
                    ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 id_1411 { endoflist_1410, dlist1_snd_295 };
                    Vec<1, ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569> id_1412 {  id_1411  };
                    ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 let_res_1413;
                    {
                      Vec<1, ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569> inits_src_ref_296 { id_1412 };
                      int32_t id_1414 { 0L };
                      Vec<1, int32_t> id_1415 {  id_1414  };
                      {
                        Vec<1, int32_t> repeat_n_297 { id_1415 };
                        bool while_flag_1416 { true };
                        do {
                          int32_t id_1417 { int32_t(dlist1_fst_294) };
                          uint8_t id_1418 { 0 };
                          int32_t id_1419 { repeat_n_297[id_1418] };
                          bool id_1420 { bool(id_1417 > id_1419) };
                          while_flag_1416 = id_1420;
                          if (while_flag_1416) {
                            uint8_t id_1421 { 0 };
                            ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 id_1422 { inits_src_ref_296[id_1421] };
                            {
                              ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 dlist2_298 { id_1422 };
                              {
                                auto dlist2_fst_299 { std::get<0>(dlist2_298) };
                                auto dlist2_snd_300 { std::get<1>(dlist2_298) };
                                uint8_t id_1423 { 0 };
                                ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e id_1424 { source_of_row_binary(dlist2_snd_300) };
                                ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 letpair_res_1425;
                                {
                                  auto dlist3_fst_302 { std::get<0>(id_1424) };
                                  auto dlist3_snd_303 { std::get<1>(id_1424) };
                                  Lst<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_1426 { dlist3_fst_302, dlist2_fst_299 };
                                  ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 id_1427 { id_1426, dlist3_snd_303 };
                                  letpair_res_1425 = id_1427;
                                }
                                Void id_1428 { ((void)(inits_src_ref_296[id_1423] = letpair_res_1425), ::dessser::VOID) };
                                (void)id_1428;
                              }
                              (void)::dessser::VOID;
                            }
                            (void)::dessser::VOID;
                            uint8_t id_1429 { 0 };
                            uint8_t id_1430 { 0 };
                            int32_t id_1431 { repeat_n_297[id_1430] };
                            int32_t id_1432 { 1L };
                            int32_t id_1433 { int32_t(id_1431 + id_1432) };
                            Void id_1434 { ((void)(repeat_n_297[id_1429] = id_1433), ::dessser::VOID) };
                            (void)id_1434;
                            (void)id_1434;
                          }
                        } while (while_flag_1416);
                        (void)::dessser::VOID;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_1435 { 0 };
                      ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 id_1436 { inits_src_ref_296[id_1435] };
                      let_res_1413 = id_1436;
                    }
                    letpair_res_1409 = let_res_1413;
                  }
                  let_res_1408 = letpair_res_1409;
                }
                ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 letpair_res_1437;
                {
                  auto dlist4_fst_305 { std::get<0>(let_res_1408) };
                  auto dlist4_snd_306 { std::get<1>(let_res_1408) };
                  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_1438 { dlist4_fst_305.toListRev() };
                  std::shared_ptr<::dessser::gen::dashboard_widget::chart>  id_1439 { std::make_shared<::dessser::gen::dashboard_widget::chart>(drec_fst_282, id_1438, drec_fst_253, drec_fst_256) };
                  ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 id_1440 { id_1439, dlist4_snd_306 };
                  letpair_res_1437 = id_1440;
                }
                letpair_res_1367 = letpair_res_1437;
              }
              let_res_1366 = letpair_res_1367;
            }
            letpair_res_1293 = let_res_1366;
          }
          let_res_1292 = letpair_res_1293;
        }
        letpair_res_1290 = let_res_1292;
      }
      let_res_1289 = letpair_res_1290;
    }
    return let_res_1289;
  }
   };
  return fun1241;
}
std::function<::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70(Pointer)> chart_of_row_binary(chart_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_341" "make_snd_342"
        (let "dsum1_319" (let-pair "du16_fst_314" "du16_snd_315" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_314") (identifier "du16_snd_315")))
          (let-pair "dsum1_fst_320" "dsum1_snd_321" (identifier "dsum1_319")
            (if (eq (u16 0) (identifier "dsum1_fst_320"))
              (let "dstring1_331"
                (let "leb_ref_325" (make-vec (u32 0))
                  (let "shft_ref_326" (make-vec (u8 0))
                    (let "p_ref_327" (make-vec (identifier "dsum1_snd_321"))
                      (seq
                        (while
                          (let "leb128_328" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_327")))
                            (let-pair "leb128_fst_329" "leb128_snd_330" 
                              (identifier "leb128_328")
                              (seq (set-vec (u8 0) (identifier "p_ref_327") (identifier "leb128_snd_330"))
                                (set-vec (u8 0) (identifier "leb_ref_325")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_329") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_326"))) (unsafe-nth (u8 0) (identifier "leb_ref_325"))))
                                (set-vec (u8 0) (identifier "shft_ref_326") (add (unsafe-nth (u8 0) (identifier "shft_ref_326")) (u8 7))) 
                                (ge (identifier "leb128_fst_329") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_325"))) (unsafe-nth (u8 0) (identifier "p_ref_327")))))))
                (let-pair "dstring1_fst_332" "dstring1_snd_333" (identifier "dstring1_331")
                  (let-pair "dstring2_fst_335" "dstring2_snd_336" (read-bytes (identifier "dstring1_snd_333") (identifier "dstring1_fst_332"))
                    (make-tup
                      (construct "[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]})[]})]" 0
                        (string-of-bytes (identifier "dstring2_fst_335"))) 
                      (identifier "dstring2_snd_336")))))
              (seq (assert (eq (identifier "dsum1_fst_320") (u16 1)))
                (let-pair "dsum2_fst_323" "dsum2_snd_324" (apply (identifier "chart-of-row-binary") (identifier "dsum1_snd_321"))
                  (make-tup
                    (construct "[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]})[]})]" 1
                      (identifier "dsum2_fst_323")) (identifier "dsum2_snd_324"))))))) 
        (make-tup (identifier "make_fst_341") (identifier "make_snd_342"))))
 */
static std::function<::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939(Pointer)> fun1441 { [&fun1441](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1442 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1443;
    {
      auto du16_fst_314 { std::get<0>(id_1442) };
      auto du16_snd_315 { std::get<1>(id_1442) };
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1444 { du16_fst_314, du16_snd_315 };
      letpair_res_1443 = id_1444;
    }
    ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 let_res_1445;
    {
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b dsum1_319 { letpair_res_1443 };
      ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1446;
      {
        auto dsum1_fst_320 { std::get<0>(dsum1_319) };
        auto dsum1_snd_321 { std::get<1>(dsum1_319) };
        uint16_t id_1447 { 0 };
        bool id_1448 { bool(id_1447 == dsum1_fst_320) };
        ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 choose_res_1449;
        if (id_1448) {
          uint32_t id_1450 { 0U };
          Vec<1, uint32_t> id_1451 {  id_1450  };
          ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1452;
          {
            Vec<1, uint32_t> leb_ref_325 { id_1451 };
            uint8_t id_1453 { 0 };
            Vec<1, uint8_t> id_1454 {  id_1453  };
            ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1455;
            {
              Vec<1, uint8_t> shft_ref_326 { id_1454 };
              Vec<1, Pointer> id_1456 {  dsum1_snd_321  };
              ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1457;
              {
                Vec<1, Pointer> p_ref_327 { id_1456 };
                bool while_flag_1458 { true };
                do {
                  uint8_t id_1459 { 0 };
                  Pointer id_1460 { p_ref_327[id_1459] };
                  ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1461 { id_1460.readU8() };
                  bool let_res_1462;
                  {
                    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_328 { id_1461 };
                    bool letpair_res_1463;
                    {
                      auto leb128_fst_329 { std::get<0>(leb128_328) };
                      auto leb128_snd_330 { std::get<1>(leb128_328) };
                      uint8_t id_1464 { 0 };
                      Void id_1465 { ((void)(p_ref_327[id_1464] = leb128_snd_330), ::dessser::VOID) };
                      (void)id_1465;
                      uint8_t id_1466 { 0 };
                      uint8_t id_1467 { 127 };
                      uint8_t id_1468 { uint8_t(leb128_fst_329 & id_1467) };
                      uint32_t id_1469 { uint32_t(id_1468) };
                      uint8_t id_1470 { 0 };
                      uint8_t id_1471 { shft_ref_326[id_1470] };
                      uint32_t id_1472 { uint32_t(id_1469 << id_1471) };
                      uint8_t id_1473 { 0 };
                      uint32_t id_1474 { leb_ref_325[id_1473] };
                      uint32_t id_1475 { uint32_t(id_1472 | id_1474) };
                      Void id_1476 { ((void)(leb_ref_325[id_1466] = id_1475), ::dessser::VOID) };
                      (void)id_1476;
                      uint8_t id_1477 { 0 };
                      uint8_t id_1478 { 0 };
                      uint8_t id_1479 { shft_ref_326[id_1478] };
                      uint8_t id_1480 { 7 };
                      uint8_t id_1481 { uint8_t(id_1479 + id_1480) };
                      Void id_1482 { ((void)(shft_ref_326[id_1477] = id_1481), ::dessser::VOID) };
                      (void)id_1482;
                      uint8_t id_1483 { 128 };
                      bool id_1484 { bool(leb128_fst_329 >= id_1483) };
                      letpair_res_1463 = id_1484;
                    }
                    let_res_1462 = letpair_res_1463;
                  }
                  while_flag_1458 = let_res_1462;
                  if (while_flag_1458) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_1458);
                (void)::dessser::VOID;
                uint8_t id_1485 { 0 };
                uint32_t id_1486 { leb_ref_325[id_1485] };
                Size id_1487 { Size(id_1486) };
                uint8_t id_1488 { 0 };
                Pointer id_1489 { p_ref_327[id_1488] };
                ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 id_1490 { id_1487, id_1489 };
                let_res_1457 = id_1490;
              }
              let_res_1455 = let_res_1457;
            }
            let_res_1452 = let_res_1455;
          }
          ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 let_res_1491;
          {
            ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 dstring1_331 { let_res_1452 };
            ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1492;
            {
              auto dstring1_fst_332 { std::get<0>(dstring1_331) };
              auto dstring1_snd_333 { std::get<1>(dstring1_331) };
              ::dessser::gen::dashboard_widget::t5887709cc43c8c8e24d28211e8c970a2 id_1493 { dstring1_snd_333.readBytes(dstring1_fst_332) };
              ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1494;
              {
                auto dstring2_fst_335 { std::get<0>(id_1493) };
                auto dstring2_snd_336 { std::get<1>(id_1493) };
                std::string id_1495 { dstring2_fst_335.toString() };
                std::shared_ptr<::dessser::gen::dashboard_widget::t>  id_1496 { std::make_shared<::dessser::gen::dashboard_widget::t>(std::in_place_index<0>, id_1495) };
                ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 id_1497 { id_1496, dstring2_snd_336 };
                letpair_res_1494 = id_1497;
              }
              letpair_res_1492 = letpair_res_1494;
            }
            let_res_1491 = letpair_res_1492;
          }
          choose_res_1449 = let_res_1491;
        } else {
          uint16_t id_1498 { 1 };
          bool id_1499 { bool(dsum1_fst_320 == id_1498) };
          Void id_1500 { ((void)(assert(id_1499)), ::dessser::VOID) };
          (void)id_1500;
          ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 id_1501 { chart_of_row_binary(dsum1_snd_321) };
          ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1502;
          {
            auto dsum2_fst_323 { std::get<0>(id_1501) };
            auto dsum2_snd_324 { std::get<1>(id_1501) };
            std::shared_ptr<::dessser::gen::dashboard_widget::t>  id_1503 { std::make_shared<::dessser::gen::dashboard_widget::t>(std::in_place_index<1>, dsum2_fst_323) };
            ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 id_1504 { id_1503, dsum2_snd_324 };
            letpair_res_1502 = id_1504;
          }
          choose_res_1449 = letpair_res_1502;
        }
        letpair_res_1446 = choose_res_1449;
      }
      let_res_1445 = letpair_res_1446;
    }
    ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1505;
    {
      auto make_fst_341 { std::get<0>(let_res_1445) };
      auto make_snd_342 { std::get<1>(let_res_1445) };
      ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 id_1506 { make_fst_341, make_snd_342 };
      letpair_res_1505 = id_1506;
    }
    return letpair_res_1505;
  }
   };
  return fun1441;
}
std::function<::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939(Pointer)> of_row_binary(of_row_binary_init());


}
