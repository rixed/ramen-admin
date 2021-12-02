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
struct representation : public std::variant<
  Void, // Unused
  Void, // Independent
  Void, // Stacked
  Void // StackCentered
> { using variant::variant; };

struct field {
  uint8_t axis;
  uint32_t color;
  std::string column;
  Arr<std::string> factors;
  double opacity;
  std::shared_ptr<::dessser::gen::dashboard_widget::representation>  representation;
  field(uint8_t axis_, uint32_t color_, std::string column_, Arr<std::string> factors_, double opacity_, std::shared_ptr<::dessser::gen::dashboard_widget::representation>  representation_) : axis(axis_), color(color_), column(column_), factors(factors_), opacity(opacity_), representation(representation_) {}
  field() = default;
};
struct source {
  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > fields;
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  source(Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > fields_, dessser::gen::fq_function_name::t_ext name_, bool visible_) : fields(fields_), name(name_), visible(visible_) {}
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

struct t8ef1c95fd186832d880a2244303e9cea : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::representation> ,
  Pointer
> {
  using tuple::tuple;
  t8ef1c95fd186832d880a2244303e9cea(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::representation> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::representation> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t14c207e65f8f77a76ec87f66e5566060 : public std::tuple<
  std::shared_ptr<::dessser::gen::dashboard_widget::field> ,
  Pointer
> {
  using tuple::tuple;
  t14c207e65f8f77a76ec87f66e5566060(std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::field> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::dashboard_widget::field> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
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
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
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
struct t8f6cce063b0da10e7eea29b507eded2e : public std::tuple<
  bool,
  Pointer
> {
  using tuple::tuple;
  t8f6cce063b0da10e7eea29b507eded2e(std::tuple<bool, Pointer> p)
    : std::tuple<bool, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tf127c32c360f30960192a3b115bf4c21 : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::dashboard_widget::field> >,
  Pointer
> {
  using tuple::tuple;
  tf127c32c360f30960192a3b115bf4c21(std::tuple<Lst<std::shared_ptr<::dessser::gen::dashboard_widget::field> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::dashboard_widget::field> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
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
    (fun ("[Unused Void | Independent Void | Stacked Void | StackCentered Void]" "Ptr")
      (let "ssum_dst_404" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_404")
          (if (eq (u16 1) (label-of (param 0))) (identifier "ssum_dst_404") (if (eq (u16 2) (label-of (param 0))) (identifier "ssum_dst_404") (seq (assert (eq (label-of (param 0)) (u16 3))) (identifier "ssum_dst_404")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::representation> ,Pointer)> representation_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::representation> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::dashboard_widget::representation>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_404 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_404;
      } else {
        uint16_t id_8 { 1 };
        uint16_t id_9 { uint16_t((*p_0).index()) };
        bool id_10 { bool(id_8 == id_9) };
        Pointer choose_res_11;
        if (id_10) {
          choose_res_11 = ssum_dst_404;
        } else {
          uint16_t id_12 { 2 };
          uint16_t id_13 { uint16_t((*p_0).index()) };
          bool id_14 { bool(id_12 == id_13) };
          Pointer choose_res_15;
          if (id_14) {
            choose_res_15 = ssum_dst_404;
          } else {
            uint16_t id_16 { uint16_t((*p_0).index()) };
            uint16_t id_17 { 3 };
            bool id_18 { bool(id_16 == id_17) };
            Void id_19 { ((void)(assert(id_18)), ::dessser::VOID) };
            (void)id_19;
            choose_res_15 = ssum_dst_404;
          }
          choose_res_11 = choose_res_15;
        }
        choose_res_7 = choose_res_11;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::representation> ,Pointer)> representation_to_row_binary(representation_to_row_binary_init());

/* 
    (fun ("{opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8}" "Ptr")
      (let "srec_dst_418"
        (let "srec_dst_410"
          (let "srec_dst_407"
            (let "srec_dst_406" (let "srec_dst_405" (write-u64 little-endian (param 1) (u64-of-float (get-field "opacity" (param 0)))) (write-u32 little-endian (identifier "srec_dst_405") (get-field "color" (param 0))))
              (apply (identifier "representation-to-row-binary") (get-field "representation" (param 0)) (identifier "srec_dst_406")))
            (write-bytes
              (let "leb128_sz_408" (make-vec (string-length (get-field "column" (param 0))))
                (let "leb128_ptr_409" (make-vec (identifier "srec_dst_407"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_409")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_409"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_408"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_408"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_408"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_408") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_408")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_408")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_409"))))) 
              (bytes-of-string (get-field "column" (param 0)))))
          (let "dst_ref_413"
            (make-vec
              (let "leb128_sz_411" (make-vec (cardinality (get-field "factors" (param 0))))
                (let "leb128_ptr_412" (make-vec (identifier "srec_dst_410"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_412")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_412"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_411"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_411"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_411"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_411") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_411")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_411")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_412"))))))
            (let "n_ref_414" (make-vec (i32 0))
              (seq
                (for-each "x_415" (get-field "factors" (param 0))
                  (seq
                    (set-vec (u8 0) (identifier "dst_ref_413")
                      (write-bytes
                        (let "leb128_sz_416" (make-vec (string-length (identifier "x_415")))
                          (let "leb128_ptr_417" (make-vec (unsafe-nth (u8 0) (identifier "dst_ref_413")))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_417")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_417"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_416"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_416"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_416"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_416") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_416")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_416")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_417"))))) 
                        (bytes-of-string (identifier "x_415")))) (set-vec (u8 0) (identifier "n_ref_414") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_414")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_413")))))) (write-u8 (identifier "srec_dst_418") (get-field "axis" (param 0)))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::field> ,Pointer)> field_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::field> ,Pointer)> fun20 { [&fun20](std::shared_ptr<::dessser::gen::dashboard_widget::field>  p_0, Pointer p_1) {
    double id_21 { (*p_0).opacity };
    uint64_t id_22 { qword_of_float(id_21) };
    Pointer id_23 { p_1.writeU64Le(id_22) };
    Pointer let_res_24;
    {
      Pointer srec_dst_405 { id_23 };
      uint32_t id_25 { (*p_0).color };
      Pointer id_26 { srec_dst_405.writeU32Le(id_25) };
      let_res_24 = id_26;
    }
    Pointer let_res_27;
    {
      Pointer srec_dst_406 { let_res_24 };
      std::shared_ptr<::dessser::gen::dashboard_widget::representation>  id_28 { (*p_0).representation };
      Pointer id_29 { representation_to_row_binary(id_28, srec_dst_406) };
      let_res_27 = id_29;
    }
    Pointer let_res_30;
    {
      Pointer srec_dst_407 { let_res_27 };
      std::string id_31 { (*p_0).column };
      uint32_t id_32 { (uint32_t)id_31.size() };
      Vec<1, uint32_t> id_33 {  id_32  };
      Pointer let_res_34;
      {
        Vec<1, uint32_t> leb128_sz_408 { id_33 };
        Vec<1, Pointer> id_35 {  srec_dst_407  };
        Pointer let_res_36;
        {
          Vec<1, Pointer> leb128_ptr_409 { id_35 };
          bool while_flag_37 { true };
          do {
            uint8_t id_38 { 0 };
            uint8_t id_39 { 0 };
            Pointer id_40 { leb128_ptr_409[id_39] };
            uint32_t id_41 { 128U };
            uint8_t id_42 { 0 };
            uint32_t id_43 { leb128_sz_408[id_42] };
            bool id_44 { bool(id_41 > id_43) };
            uint8_t choose_res_45;
            if (id_44) {
              uint8_t id_46 { 0 };
              uint32_t id_47 { leb128_sz_408[id_46] };
              uint8_t id_48 { uint8_t(id_47) };
              choose_res_45 = id_48;
            } else {
              uint8_t id_49 { 0 };
              uint32_t id_50 { leb128_sz_408[id_49] };
              uint8_t id_51 { uint8_t(id_50) };
              uint8_t id_52 { 128 };
              uint8_t id_53 { uint8_t(id_51 | id_52) };
              choose_res_45 = id_53;
            }
            Pointer id_54 { id_40.writeU8(choose_res_45) };
            Void id_55 { ((void)(leb128_ptr_409[id_38] = id_54), ::dessser::VOID) };
            (void)id_55;
            uint8_t id_56 { 0 };
            uint8_t id_57 { 0 };
            uint32_t id_58 { leb128_sz_408[id_57] };
            uint8_t id_59 { 7 };
            uint32_t id_60 { uint32_t(id_58 >> id_59) };
            Void id_61 { ((void)(leb128_sz_408[id_56] = id_60), ::dessser::VOID) };
            (void)id_61;
            uint8_t id_62 { 0 };
            uint32_t id_63 { leb128_sz_408[id_62] };
            uint32_t id_64 { 0U };
            bool id_65 { bool(id_63 > id_64) };
            while_flag_37 = id_65;
            if (while_flag_37) {
              (void)::dessser::VOID;
            }
          } while (while_flag_37);
          (void)::dessser::VOID;
          uint8_t id_66 { 0 };
          Pointer id_67 { leb128_ptr_409[id_66] };
          let_res_36 = id_67;
        }
        let_res_34 = let_res_36;
      }
      std::string id_68 { (*p_0).column };
      Bytes id_69 { id_68 };
      Pointer id_70 { let_res_34.writeBytes(id_69) };
      let_res_30 = id_70;
    }
    Pointer let_res_71;
    {
      Pointer srec_dst_410 { let_res_30 };
      Arr<std::string> id_72 { (*p_0).factors };
      uint32_t id_73 { id_72.size() };
      Vec<1, uint32_t> id_74 {  id_73  };
      Pointer let_res_75;
      {
        Vec<1, uint32_t> leb128_sz_411 { id_74 };
        Vec<1, Pointer> id_76 {  srec_dst_410  };
        Pointer let_res_77;
        {
          Vec<1, Pointer> leb128_ptr_412 { id_76 };
          bool while_flag_78 { true };
          do {
            uint8_t id_79 { 0 };
            uint8_t id_80 { 0 };
            Pointer id_81 { leb128_ptr_412[id_80] };
            uint32_t id_82 { 128U };
            uint8_t id_83 { 0 };
            uint32_t id_84 { leb128_sz_411[id_83] };
            bool id_85 { bool(id_82 > id_84) };
            uint8_t choose_res_86;
            if (id_85) {
              uint8_t id_87 { 0 };
              uint32_t id_88 { leb128_sz_411[id_87] };
              uint8_t id_89 { uint8_t(id_88) };
              choose_res_86 = id_89;
            } else {
              uint8_t id_90 { 0 };
              uint32_t id_91 { leb128_sz_411[id_90] };
              uint8_t id_92 { uint8_t(id_91) };
              uint8_t id_93 { 128 };
              uint8_t id_94 { uint8_t(id_92 | id_93) };
              choose_res_86 = id_94;
            }
            Pointer id_95 { id_81.writeU8(choose_res_86) };
            Void id_96 { ((void)(leb128_ptr_412[id_79] = id_95), ::dessser::VOID) };
            (void)id_96;
            uint8_t id_97 { 0 };
            uint8_t id_98 { 0 };
            uint32_t id_99 { leb128_sz_411[id_98] };
            uint8_t id_100 { 7 };
            uint32_t id_101 { uint32_t(id_99 >> id_100) };
            Void id_102 { ((void)(leb128_sz_411[id_97] = id_101), ::dessser::VOID) };
            (void)id_102;
            uint8_t id_103 { 0 };
            uint32_t id_104 { leb128_sz_411[id_103] };
            uint32_t id_105 { 0U };
            bool id_106 { bool(id_104 > id_105) };
            while_flag_78 = id_106;
            if (while_flag_78) {
              (void)::dessser::VOID;
            }
          } while (while_flag_78);
          (void)::dessser::VOID;
          uint8_t id_107 { 0 };
          Pointer id_108 { leb128_ptr_412[id_107] };
          let_res_77 = id_108;
        }
        let_res_75 = let_res_77;
      }
      Vec<1, Pointer> id_109 {  let_res_75  };
      Pointer let_res_110;
      {
        Vec<1, Pointer> dst_ref_413 { id_109 };
        int32_t id_111 { 0L };
        Vec<1, int32_t> id_112 {  id_111  };
        Pointer let_res_113;
        {
          Vec<1, int32_t> n_ref_414 { id_112 };
          Arr<std::string> id_114 { (*p_0).factors };
          for (std::string x_415 : id_114) {
            uint8_t id_115 { 0 };
            uint32_t id_116 { (uint32_t)x_415.size() };
            Vec<1, uint32_t> id_117 {  id_116  };
            Pointer let_res_118;
            {
              Vec<1, uint32_t> leb128_sz_416 { id_117 };
              uint8_t id_119 { 0 };
              Pointer id_120 { dst_ref_413[id_119] };
              Vec<1, Pointer> id_121 {  id_120  };
              Pointer let_res_122;
              {
                Vec<1, Pointer> leb128_ptr_417 { id_121 };
                bool while_flag_123 { true };
                do {
                  uint8_t id_124 { 0 };
                  uint8_t id_125 { 0 };
                  Pointer id_126 { leb128_ptr_417[id_125] };
                  uint32_t id_127 { 128U };
                  uint8_t id_128 { 0 };
                  uint32_t id_129 { leb128_sz_416[id_128] };
                  bool id_130 { bool(id_127 > id_129) };
                  uint8_t choose_res_131;
                  if (id_130) {
                    uint8_t id_132 { 0 };
                    uint32_t id_133 { leb128_sz_416[id_132] };
                    uint8_t id_134 { uint8_t(id_133) };
                    choose_res_131 = id_134;
                  } else {
                    uint8_t id_135 { 0 };
                    uint32_t id_136 { leb128_sz_416[id_135] };
                    uint8_t id_137 { uint8_t(id_136) };
                    uint8_t id_138 { 128 };
                    uint8_t id_139 { uint8_t(id_137 | id_138) };
                    choose_res_131 = id_139;
                  }
                  Pointer id_140 { id_126.writeU8(choose_res_131) };
                  Void id_141 { ((void)(leb128_ptr_417[id_124] = id_140), ::dessser::VOID) };
                  (void)id_141;
                  uint8_t id_142 { 0 };
                  uint8_t id_143 { 0 };
                  uint32_t id_144 { leb128_sz_416[id_143] };
                  uint8_t id_145 { 7 };
                  uint32_t id_146 { uint32_t(id_144 >> id_145) };
                  Void id_147 { ((void)(leb128_sz_416[id_142] = id_146), ::dessser::VOID) };
                  (void)id_147;
                  uint8_t id_148 { 0 };
                  uint32_t id_149 { leb128_sz_416[id_148] };
                  uint32_t id_150 { 0U };
                  bool id_151 { bool(id_149 > id_150) };
                  while_flag_123 = id_151;
                  if (while_flag_123) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_123);
                (void)::dessser::VOID;
                uint8_t id_152 { 0 };
                Pointer id_153 { leb128_ptr_417[id_152] };
                let_res_122 = id_153;
              }
              let_res_118 = let_res_122;
            }
            Bytes id_154 { x_415 };
            Pointer id_155 { let_res_118.writeBytes(id_154) };
            Void id_156 { ((void)(dst_ref_413[id_115] = id_155), ::dessser::VOID) };
            (void)id_156;
            uint8_t id_157 { 0 };
            int32_t id_158 { 1L };
            uint8_t id_159 { 0 };
            int32_t id_160 { n_ref_414[id_159] };
            int32_t id_161 { int32_t(id_158 + id_160) };
            Void id_162 { ((void)(n_ref_414[id_157] = id_161), ::dessser::VOID) };
            (void)id_162;
            (void)id_162;
          }
          (void)::dessser::VOID;
          uint8_t id_163 { 0 };
          Pointer id_164 { dst_ref_413[id_163] };
          let_res_113 = id_164;
        }
        let_res_110 = let_res_113;
      }
      let_res_71 = let_res_110;
    }
    Pointer let_res_165;
    {
      Pointer srec_dst_418 { let_res_71 };
      uint8_t id_166 { (*p_0).axis };
      Pointer id_167 { srec_dst_418.writeU8(id_166) };
      let_res_165 = id_167;
    }
    return let_res_165;
  }
   };
  return fun20;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::field> ,Pointer)> field_to_row_binary(field_to_row_binary_init());

/* 
    (fun ("{name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]}" "Ptr")
      (let "srec_dst_420" (let "srec_dst_419" (apply (ext-identifier fq_function_name to-row-binary) (get-field "name" (param 0)) (param 1)) (write-u8 (identifier "srec_dst_419") (u8-of-bool (get-field "visible" (param 0)))))
        (let "dst_ref_423"
          (make-vec
            (let "leb128_sz_421" (make-vec (cardinality (get-field "fields" (param 0))))
              (let "leb128_ptr_422" (make-vec (identifier "srec_dst_420"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_422")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_422"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_421"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_421"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_421"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_421") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_421")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_421")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_422"))))))
          (let "n_ref_424" (make-vec (i32 0))
            (seq
              (for-each "x_425" (get-field "fields" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_423") (apply (identifier "field-to-row-binary") (identifier "x_425") (unsafe-nth (u8 0) (identifier "dst_ref_423"))))
                  (set-vec (u8 0) (identifier "n_ref_424") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_424")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_423")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::source> ,Pointer)> source_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::source> ,Pointer)> fun168 { [&fun168](std::shared_ptr<::dessser::gen::dashboard_widget::source>  p_0, Pointer p_1) {
    auto fun169 { dessser::gen::fq_function_name::to_row_binary };
    dessser::gen::fq_function_name::t_ext id_170 { (*p_0).name };
    Pointer id_171 { fun169(id_170, p_1) };
    Pointer let_res_172;
    {
      Pointer srec_dst_419 { id_171 };
      bool id_173 { (*p_0).visible };
      uint8_t id_174 { uint8_t(id_173) };
      Pointer id_175 { srec_dst_419.writeU8(id_174) };
      let_res_172 = id_175;
    }
    Pointer let_res_176;
    {
      Pointer srec_dst_420 { let_res_172 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > id_177 { (*p_0).fields };
      uint32_t id_178 { id_177.size() };
      Vec<1, uint32_t> id_179 {  id_178  };
      Pointer let_res_180;
      {
        Vec<1, uint32_t> leb128_sz_421 { id_179 };
        Vec<1, Pointer> id_181 {  srec_dst_420  };
        Pointer let_res_182;
        {
          Vec<1, Pointer> leb128_ptr_422 { id_181 };
          bool while_flag_183 { true };
          do {
            uint8_t id_184 { 0 };
            uint8_t id_185 { 0 };
            Pointer id_186 { leb128_ptr_422[id_185] };
            uint32_t id_187 { 128U };
            uint8_t id_188 { 0 };
            uint32_t id_189 { leb128_sz_421[id_188] };
            bool id_190 { bool(id_187 > id_189) };
            uint8_t choose_res_191;
            if (id_190) {
              uint8_t id_192 { 0 };
              uint32_t id_193 { leb128_sz_421[id_192] };
              uint8_t id_194 { uint8_t(id_193) };
              choose_res_191 = id_194;
            } else {
              uint8_t id_195 { 0 };
              uint32_t id_196 { leb128_sz_421[id_195] };
              uint8_t id_197 { uint8_t(id_196) };
              uint8_t id_198 { 128 };
              uint8_t id_199 { uint8_t(id_197 | id_198) };
              choose_res_191 = id_199;
            }
            Pointer id_200 { id_186.writeU8(choose_res_191) };
            Void id_201 { ((void)(leb128_ptr_422[id_184] = id_200), ::dessser::VOID) };
            (void)id_201;
            uint8_t id_202 { 0 };
            uint8_t id_203 { 0 };
            uint32_t id_204 { leb128_sz_421[id_203] };
            uint8_t id_205 { 7 };
            uint32_t id_206 { uint32_t(id_204 >> id_205) };
            Void id_207 { ((void)(leb128_sz_421[id_202] = id_206), ::dessser::VOID) };
            (void)id_207;
            uint8_t id_208 { 0 };
            uint32_t id_209 { leb128_sz_421[id_208] };
            uint32_t id_210 { 0U };
            bool id_211 { bool(id_209 > id_210) };
            while_flag_183 = id_211;
            if (while_flag_183) {
              (void)::dessser::VOID;
            }
          } while (while_flag_183);
          (void)::dessser::VOID;
          uint8_t id_212 { 0 };
          Pointer id_213 { leb128_ptr_422[id_212] };
          let_res_182 = id_213;
        }
        let_res_180 = let_res_182;
      }
      Vec<1, Pointer> id_214 {  let_res_180  };
      Pointer let_res_215;
      {
        Vec<1, Pointer> dst_ref_423 { id_214 };
        int32_t id_216 { 0L };
        Vec<1, int32_t> id_217 {  id_216  };
        Pointer let_res_218;
        {
          Vec<1, int32_t> n_ref_424 { id_217 };
          Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > id_219 { (*p_0).fields };
          for (std::shared_ptr<::dessser::gen::dashboard_widget::field>  x_425 : id_219) {
            uint8_t id_220 { 0 };
            uint8_t id_221 { 0 };
            Pointer id_222 { dst_ref_423[id_221] };
            Pointer id_223 { field_to_row_binary(x_425, id_222) };
            Void id_224 { ((void)(dst_ref_423[id_220] = id_223), ::dessser::VOID) };
            (void)id_224;
            uint8_t id_225 { 0 };
            int32_t id_226 { 1L };
            uint8_t id_227 { 0 };
            int32_t id_228 { n_ref_424[id_227] };
            int32_t id_229 { int32_t(id_226 + id_228) };
            Void id_230 { ((void)(n_ref_424[id_225] = id_229), ::dessser::VOID) };
            (void)id_230;
            (void)id_230;
          }
          (void)::dessser::VOID;
          uint8_t id_231 { 0 };
          Pointer id_232 { dst_ref_423[id_231] };
          let_res_218 = id_232;
        }
        let_res_215 = let_res_218;
      }
      let_res_176 = let_res_215;
    }
    return let_res_176;
  }
   };
  return fun168;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::source> ,Pointer)> source_to_row_binary(source_to_row_binary_init());

/* 
    (fun ("[Linear Void | Logarithmic Void]" "Ptr")
      (let "ssum_dst_400" (write-u16 little-endian (param 1) (label-of (param 0))) (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_400") (seq (assert (eq (label-of (param 0)) (u16 1))) (identifier "ssum_dst_400")))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,Pointer)> scale_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,Pointer)> fun233 { [&fun233](std::shared_ptr<::dessser::gen::dashboard_widget::scale>  p_0, Pointer p_1) {
    uint16_t id_234 { uint16_t((*p_0).index()) };
    Pointer id_235 { p_1.writeU16Le(id_234) };
    Pointer let_res_236;
    {
      Pointer ssum_dst_400 { id_235 };
      uint16_t id_237 { 0 };
      uint16_t id_238 { uint16_t((*p_0).index()) };
      bool id_239 { bool(id_237 == id_238) };
      Pointer choose_res_240;
      if (id_239) {
        choose_res_240 = ssum_dst_400;
      } else {
        uint16_t id_241 { uint16_t((*p_0).index()) };
        uint16_t id_242 { 1 };
        bool id_243 { bool(id_241 == id_242) };
        Void id_244 { ((void)(assert(id_243)), ::dessser::VOID) };
        (void)id_244;
        choose_res_240 = ssum_dst_400;
      }
      let_res_236 = choose_res_240;
    }
    return let_res_236;
  }
   };
  return fun233;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::scale> ,Pointer)> scale_to_row_binary(scale_to_row_binary_init());

/* 
    (fun ("{left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])}" "Ptr")
      (let "srec_dst_402" (let "srec_dst_401" (write-u8 (param 1) (u8-of-bool (get-field "left" (param 0)))) (write-u8 (identifier "srec_dst_401") (u8-of-bool (get-field "force_zero" (param 0)))))
        (apply (identifier "scale-to-row-binary") (get-field "scale" (param 0)) (identifier "srec_dst_402"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,Pointer)> axis_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,Pointer)> fun245 { [&fun245](std::shared_ptr<::dessser::gen::dashboard_widget::axis>  p_0, Pointer p_1) {
    bool id_246 { (*p_0).left };
    uint8_t id_247 { uint8_t(id_246) };
    Pointer id_248 { p_1.writeU8(id_247) };
    Pointer let_res_249;
    {
      Pointer srec_dst_401 { id_248 };
      bool id_250 { (*p_0).force_zero };
      uint8_t id_251 { uint8_t(id_250) };
      Pointer id_252 { srec_dst_401.writeU8(id_251) };
      let_res_249 = id_252;
    }
    Pointer let_res_253;
    {
      Pointer srec_dst_402 { let_res_249 };
      std::shared_ptr<::dessser::gen::dashboard_widget::scale>  id_254 { (*p_0).scale };
      Pointer id_255 { scale_to_row_binary(id_254, srec_dst_402) };
      let_res_253 = id_255;
    }
    return let_res_253;
  }
   };
  return fun245;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::axis> ,Pointer)> axis_to_row_binary(axis_to_row_binary_init());

/* 
    (fun ("[Plot Void]" "Ptr") (let "ssum_dst_398" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (identifier "ssum_dst_398"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::type> ,Pointer)> type_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::type> ,Pointer)> fun256 { [&fun256](std::shared_ptr<::dessser::gen::dashboard_widget::type>  p_0, Pointer p_1) {
    uint16_t id_257 { uint16_t((*p_0).index()) };
    Pointer id_258 { p_1.writeU16Le(id_257) };
    Pointer let_res_259;
    {
      Pointer ssum_dst_398 { id_258 };
      uint16_t id_260 { uint16_t((*p_0).index()) };
      uint16_t id_261 { 0 };
      bool id_262 { bool(id_260 == id_261) };
      Void id_263 { ((void)(assert(id_262)), ::dessser::VOID) };
      (void)id_263;
      let_res_259 = ssum_dst_398;
    }
    return let_res_259;
  }
   };
  return fun256;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::type> ,Pointer)> type_to_row_binary(type_to_row_binary_init());

/* 
    (fun ("{title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]}" "Ptr")
      (let "srec_dst_435"
        (let "srec_dst_429"
          (let "srec_dst_428"
            (write-bytes
              (let "leb128_sz_426" (make-vec (string-length (get-field "title" (param 0))))
                (let "leb128_ptr_427" (make-vec (param 1))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_427")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_427"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_426"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_426"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_426"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_426") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_426")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_426")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_427"))))) 
              (bytes-of-string (get-field "title" (param 0)))) (apply (identifier "type-to-row-binary") (get-field "type" (param 0)) (identifier "srec_dst_428")))
          (let "dst_ref_432"
            (make-vec
              (let "leb128_sz_430" (make-vec (cardinality (get-field "axes" (param 0))))
                (let "leb128_ptr_431" (make-vec (identifier "srec_dst_429"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_431")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_431"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_430"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_430"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_430"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_430") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_430")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_430")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_431"))))))
            (let "n_ref_433" (make-vec (i32 0))
              (seq
                (for-each "x_434" (get-field "axes" (param 0))
                  (seq (set-vec (u8 0) (identifier "dst_ref_432") (apply (identifier "axis-to-row-binary") (identifier "x_434") (unsafe-nth (u8 0) (identifier "dst_ref_432"))))
                    (set-vec (u8 0) (identifier "n_ref_433") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_433")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_432"))))))
        (let "dst_ref_438"
          (make-vec
            (let "leb128_sz_436" (make-vec (cardinality (get-field "sources" (param 0))))
              (let "leb128_ptr_437" (make-vec (identifier "srec_dst_435"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_437")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_437"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_436"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_436"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_436"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_436") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_436")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_436")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_437"))))))
          (let "n_ref_439" (make-vec (i32 0))
            (seq
              (for-each "x_440" (get-field "sources" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_438") (apply (identifier "source-to-row-binary") (identifier "x_440") (unsafe-nth (u8 0) (identifier "dst_ref_438"))))
                  (set-vec (u8 0) (identifier "n_ref_439") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_439")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_438")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,Pointer)> chart_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,Pointer)> fun264 { [&fun264](std::shared_ptr<::dessser::gen::dashboard_widget::chart>  p_0, Pointer p_1) {
    std::string id_265 { (*p_0).title };
    uint32_t id_266 { (uint32_t)id_265.size() };
    Vec<1, uint32_t> id_267 {  id_266  };
    Pointer let_res_268;
    {
      Vec<1, uint32_t> leb128_sz_426 { id_267 };
      Vec<1, Pointer> id_269 {  p_1  };
      Pointer let_res_270;
      {
        Vec<1, Pointer> leb128_ptr_427 { id_269 };
        bool while_flag_271 { true };
        do {
          uint8_t id_272 { 0 };
          uint8_t id_273 { 0 };
          Pointer id_274 { leb128_ptr_427[id_273] };
          uint32_t id_275 { 128U };
          uint8_t id_276 { 0 };
          uint32_t id_277 { leb128_sz_426[id_276] };
          bool id_278 { bool(id_275 > id_277) };
          uint8_t choose_res_279;
          if (id_278) {
            uint8_t id_280 { 0 };
            uint32_t id_281 { leb128_sz_426[id_280] };
            uint8_t id_282 { uint8_t(id_281) };
            choose_res_279 = id_282;
          } else {
            uint8_t id_283 { 0 };
            uint32_t id_284 { leb128_sz_426[id_283] };
            uint8_t id_285 { uint8_t(id_284) };
            uint8_t id_286 { 128 };
            uint8_t id_287 { uint8_t(id_285 | id_286) };
            choose_res_279 = id_287;
          }
          Pointer id_288 { id_274.writeU8(choose_res_279) };
          Void id_289 { ((void)(leb128_ptr_427[id_272] = id_288), ::dessser::VOID) };
          (void)id_289;
          uint8_t id_290 { 0 };
          uint8_t id_291 { 0 };
          uint32_t id_292 { leb128_sz_426[id_291] };
          uint8_t id_293 { 7 };
          uint32_t id_294 { uint32_t(id_292 >> id_293) };
          Void id_295 { ((void)(leb128_sz_426[id_290] = id_294), ::dessser::VOID) };
          (void)id_295;
          uint8_t id_296 { 0 };
          uint32_t id_297 { leb128_sz_426[id_296] };
          uint32_t id_298 { 0U };
          bool id_299 { bool(id_297 > id_298) };
          while_flag_271 = id_299;
          if (while_flag_271) {
            (void)::dessser::VOID;
          }
        } while (while_flag_271);
        (void)::dessser::VOID;
        uint8_t id_300 { 0 };
        Pointer id_301 { leb128_ptr_427[id_300] };
        let_res_270 = id_301;
      }
      let_res_268 = let_res_270;
    }
    std::string id_302 { (*p_0).title };
    Bytes id_303 { id_302 };
    Pointer id_304 { let_res_268.writeBytes(id_303) };
    Pointer let_res_305;
    {
      Pointer srec_dst_428 { id_304 };
      std::shared_ptr<::dessser::gen::dashboard_widget::type>  id_306 { (*p_0).type };
      Pointer id_307 { type_to_row_binary(id_306, srec_dst_428) };
      let_res_305 = id_307;
    }
    Pointer let_res_308;
    {
      Pointer srec_dst_429 { let_res_305 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_309 { (*p_0).axes };
      uint32_t id_310 { id_309.size() };
      Vec<1, uint32_t> id_311 {  id_310  };
      Pointer let_res_312;
      {
        Vec<1, uint32_t> leb128_sz_430 { id_311 };
        Vec<1, Pointer> id_313 {  srec_dst_429  };
        Pointer let_res_314;
        {
          Vec<1, Pointer> leb128_ptr_431 { id_313 };
          bool while_flag_315 { true };
          do {
            uint8_t id_316 { 0 };
            uint8_t id_317 { 0 };
            Pointer id_318 { leb128_ptr_431[id_317] };
            uint32_t id_319 { 128U };
            uint8_t id_320 { 0 };
            uint32_t id_321 { leb128_sz_430[id_320] };
            bool id_322 { bool(id_319 > id_321) };
            uint8_t choose_res_323;
            if (id_322) {
              uint8_t id_324 { 0 };
              uint32_t id_325 { leb128_sz_430[id_324] };
              uint8_t id_326 { uint8_t(id_325) };
              choose_res_323 = id_326;
            } else {
              uint8_t id_327 { 0 };
              uint32_t id_328 { leb128_sz_430[id_327] };
              uint8_t id_329 { uint8_t(id_328) };
              uint8_t id_330 { 128 };
              uint8_t id_331 { uint8_t(id_329 | id_330) };
              choose_res_323 = id_331;
            }
            Pointer id_332 { id_318.writeU8(choose_res_323) };
            Void id_333 { ((void)(leb128_ptr_431[id_316] = id_332), ::dessser::VOID) };
            (void)id_333;
            uint8_t id_334 { 0 };
            uint8_t id_335 { 0 };
            uint32_t id_336 { leb128_sz_430[id_335] };
            uint8_t id_337 { 7 };
            uint32_t id_338 { uint32_t(id_336 >> id_337) };
            Void id_339 { ((void)(leb128_sz_430[id_334] = id_338), ::dessser::VOID) };
            (void)id_339;
            uint8_t id_340 { 0 };
            uint32_t id_341 { leb128_sz_430[id_340] };
            uint32_t id_342 { 0U };
            bool id_343 { bool(id_341 > id_342) };
            while_flag_315 = id_343;
            if (while_flag_315) {
              (void)::dessser::VOID;
            }
          } while (while_flag_315);
          (void)::dessser::VOID;
          uint8_t id_344 { 0 };
          Pointer id_345 { leb128_ptr_431[id_344] };
          let_res_314 = id_345;
        }
        let_res_312 = let_res_314;
      }
      Vec<1, Pointer> id_346 {  let_res_312  };
      Pointer let_res_347;
      {
        Vec<1, Pointer> dst_ref_432 { id_346 };
        int32_t id_348 { 0L };
        Vec<1, int32_t> id_349 {  id_348  };
        Pointer let_res_350;
        {
          Vec<1, int32_t> n_ref_433 { id_349 };
          Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_351 { (*p_0).axes };
          for (std::shared_ptr<::dessser::gen::dashboard_widget::axis>  x_434 : id_351) {
            uint8_t id_352 { 0 };
            uint8_t id_353 { 0 };
            Pointer id_354 { dst_ref_432[id_353] };
            Pointer id_355 { axis_to_row_binary(x_434, id_354) };
            Void id_356 { ((void)(dst_ref_432[id_352] = id_355), ::dessser::VOID) };
            (void)id_356;
            uint8_t id_357 { 0 };
            int32_t id_358 { 1L };
            uint8_t id_359 { 0 };
            int32_t id_360 { n_ref_433[id_359] };
            int32_t id_361 { int32_t(id_358 + id_360) };
            Void id_362 { ((void)(n_ref_433[id_357] = id_361), ::dessser::VOID) };
            (void)id_362;
            (void)id_362;
          }
          (void)::dessser::VOID;
          uint8_t id_363 { 0 };
          Pointer id_364 { dst_ref_432[id_363] };
          let_res_350 = id_364;
        }
        let_res_347 = let_res_350;
      }
      let_res_308 = let_res_347;
    }
    Pointer let_res_365;
    {
      Pointer srec_dst_435 { let_res_308 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_366 { (*p_0).sources };
      uint32_t id_367 { id_366.size() };
      Vec<1, uint32_t> id_368 {  id_367  };
      Pointer let_res_369;
      {
        Vec<1, uint32_t> leb128_sz_436 { id_368 };
        Vec<1, Pointer> id_370 {  srec_dst_435  };
        Pointer let_res_371;
        {
          Vec<1, Pointer> leb128_ptr_437 { id_370 };
          bool while_flag_372 { true };
          do {
            uint8_t id_373 { 0 };
            uint8_t id_374 { 0 };
            Pointer id_375 { leb128_ptr_437[id_374] };
            uint32_t id_376 { 128U };
            uint8_t id_377 { 0 };
            uint32_t id_378 { leb128_sz_436[id_377] };
            bool id_379 { bool(id_376 > id_378) };
            uint8_t choose_res_380;
            if (id_379) {
              uint8_t id_381 { 0 };
              uint32_t id_382 { leb128_sz_436[id_381] };
              uint8_t id_383 { uint8_t(id_382) };
              choose_res_380 = id_383;
            } else {
              uint8_t id_384 { 0 };
              uint32_t id_385 { leb128_sz_436[id_384] };
              uint8_t id_386 { uint8_t(id_385) };
              uint8_t id_387 { 128 };
              uint8_t id_388 { uint8_t(id_386 | id_387) };
              choose_res_380 = id_388;
            }
            Pointer id_389 { id_375.writeU8(choose_res_380) };
            Void id_390 { ((void)(leb128_ptr_437[id_373] = id_389), ::dessser::VOID) };
            (void)id_390;
            uint8_t id_391 { 0 };
            uint8_t id_392 { 0 };
            uint32_t id_393 { leb128_sz_436[id_392] };
            uint8_t id_394 { 7 };
            uint32_t id_395 { uint32_t(id_393 >> id_394) };
            Void id_396 { ((void)(leb128_sz_436[id_391] = id_395), ::dessser::VOID) };
            (void)id_396;
            uint8_t id_397 { 0 };
            uint32_t id_398 { leb128_sz_436[id_397] };
            uint32_t id_399 { 0U };
            bool id_400 { bool(id_398 > id_399) };
            while_flag_372 = id_400;
            if (while_flag_372) {
              (void)::dessser::VOID;
            }
          } while (while_flag_372);
          (void)::dessser::VOID;
          uint8_t id_401 { 0 };
          Pointer id_402 { leb128_ptr_437[id_401] };
          let_res_371 = id_402;
        }
        let_res_369 = let_res_371;
      }
      Vec<1, Pointer> id_403 {  let_res_369  };
      Pointer let_res_404;
      {
        Vec<1, Pointer> dst_ref_438 { id_403 };
        int32_t id_405 { 0L };
        Vec<1, int32_t> id_406 {  id_405  };
        Pointer let_res_407;
        {
          Vec<1, int32_t> n_ref_439 { id_406 };
          Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_408 { (*p_0).sources };
          for (std::shared_ptr<::dessser::gen::dashboard_widget::source>  x_440 : id_408) {
            uint8_t id_409 { 0 };
            uint8_t id_410 { 0 };
            Pointer id_411 { dst_ref_438[id_410] };
            Pointer id_412 { source_to_row_binary(x_440, id_411) };
            Void id_413 { ((void)(dst_ref_438[id_409] = id_412), ::dessser::VOID) };
            (void)id_413;
            uint8_t id_414 { 0 };
            int32_t id_415 { 1L };
            uint8_t id_416 { 0 };
            int32_t id_417 { n_ref_439[id_416] };
            int32_t id_418 { int32_t(id_415 + id_417) };
            Void id_419 { ((void)(n_ref_439[id_414] = id_418), ::dessser::VOID) };
            (void)id_419;
            (void)id_419;
          }
          (void)::dessser::VOID;
          uint8_t id_420 { 0 };
          Pointer id_421 { dst_ref_438[id_420] };
          let_res_407 = id_421;
        }
        let_res_404 = let_res_407;
      }
      let_res_365 = let_res_404;
    }
    return let_res_365;
  }
   };
  return fun264;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::chart> ,Pointer)> chart_to_row_binary(chart_to_row_binary_init());

/* 
    (fun ("[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]})]" "Ptr")
      (let "ssum_dst_442" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_443" (make-vec (string-length (get-alt "Text" (param 0))))
              (let "leb128_ptr_444" (make-vec (identifier "ssum_dst_442"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_444")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_444"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_443"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_443"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_443"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_443") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_443")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_443")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_444"))))) 
            (bytes-of-string (get-alt "Text" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "chart-to-row-binary") (get-alt "Chart" (param 0)) (identifier "ssum_dst_442"))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::t> ,Pointer)> fun422 { [&fun422](std::shared_ptr<::dessser::gen::dashboard_widget::t>  p_0, Pointer p_1) {
    uint16_t id_423 { uint16_t((*p_0).index()) };
    Pointer id_424 { p_1.writeU16Le(id_423) };
    Pointer let_res_425;
    {
      Pointer ssum_dst_442 { id_424 };
      uint16_t id_426 { 0 };
      uint16_t id_427 { uint16_t((*p_0).index()) };
      bool id_428 { bool(id_426 == id_427) };
      Pointer choose_res_429;
      if (id_428) {
        std::string id_430 { std::get<0 /* Text */>((*p_0)) };
        uint32_t id_431 { (uint32_t)id_430.size() };
        Vec<1, uint32_t> id_432 {  id_431  };
        Pointer let_res_433;
        {
          Vec<1, uint32_t> leb128_sz_443 { id_432 };
          Vec<1, Pointer> id_434 {  ssum_dst_442  };
          Pointer let_res_435;
          {
            Vec<1, Pointer> leb128_ptr_444 { id_434 };
            bool while_flag_436 { true };
            do {
              uint8_t id_437 { 0 };
              uint8_t id_438 { 0 };
              Pointer id_439 { leb128_ptr_444[id_438] };
              uint32_t id_440 { 128U };
              uint8_t id_441 { 0 };
              uint32_t id_442 { leb128_sz_443[id_441] };
              bool id_443 { bool(id_440 > id_442) };
              uint8_t choose_res_444;
              if (id_443) {
                uint8_t id_445 { 0 };
                uint32_t id_446 { leb128_sz_443[id_445] };
                uint8_t id_447 { uint8_t(id_446) };
                choose_res_444 = id_447;
              } else {
                uint8_t id_448 { 0 };
                uint32_t id_449 { leb128_sz_443[id_448] };
                uint8_t id_450 { uint8_t(id_449) };
                uint8_t id_451 { 128 };
                uint8_t id_452 { uint8_t(id_450 | id_451) };
                choose_res_444 = id_452;
              }
              Pointer id_453 { id_439.writeU8(choose_res_444) };
              Void id_454 { ((void)(leb128_ptr_444[id_437] = id_453), ::dessser::VOID) };
              (void)id_454;
              uint8_t id_455 { 0 };
              uint8_t id_456 { 0 };
              uint32_t id_457 { leb128_sz_443[id_456] };
              uint8_t id_458 { 7 };
              uint32_t id_459 { uint32_t(id_457 >> id_458) };
              Void id_460 { ((void)(leb128_sz_443[id_455] = id_459), ::dessser::VOID) };
              (void)id_460;
              uint8_t id_461 { 0 };
              uint32_t id_462 { leb128_sz_443[id_461] };
              uint32_t id_463 { 0U };
              bool id_464 { bool(id_462 > id_463) };
              while_flag_436 = id_464;
              if (while_flag_436) {
                (void)::dessser::VOID;
              }
            } while (while_flag_436);
            (void)::dessser::VOID;
            uint8_t id_465 { 0 };
            Pointer id_466 { leb128_ptr_444[id_465] };
            let_res_435 = id_466;
          }
          let_res_433 = let_res_435;
        }
        std::string id_467 { std::get<0 /* Text */>((*p_0)) };
        Bytes id_468 { id_467 };
        Pointer id_469 { let_res_433.writeBytes(id_468) };
        choose_res_429 = id_469;
      } else {
        uint16_t id_470 { uint16_t((*p_0).index()) };
        uint16_t id_471 { 1 };
        bool id_472 { bool(id_470 == id_471) };
        Void id_473 { ((void)(assert(id_472)), ::dessser::VOID) };
        (void)id_473;
        std::shared_ptr<::dessser::gen::dashboard_widget::chart>  id_474 { std::get<1 /* Chart */>((*p_0)) };
        Pointer id_475 { chart_to_row_binary(id_474, ssum_dst_442) };
        choose_res_429 = id_475;
      }
      let_res_425 = choose_res_429;
    }
    return let_res_425;
  }
   };
  return fun422;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::dashboard_widget::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Unused Void | Independent Void | Stacked Void | StackCentered Void]")
      (if (eq (u16 0) (label-of (param 0))) (size 2) (if (eq (u16 1) (label-of (param 0))) (size 2) (if (eq (u16 2) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 3))) (size 2))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::representation> )> representation_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::representation> )> fun476 { [&fun476](std::shared_ptr<::dessser::gen::dashboard_widget::representation>  p_0) {
    uint16_t id_477 { 0 };
    uint16_t id_478 { uint16_t((*p_0).index()) };
    bool id_479 { bool(id_477 == id_478) };
    Size choose_res_480;
    if (id_479) {
      Size id_481 { 2UL };
      choose_res_480 = id_481;
    } else {
      uint16_t id_482 { 1 };
      uint16_t id_483 { uint16_t((*p_0).index()) };
      bool id_484 { bool(id_482 == id_483) };
      Size choose_res_485;
      if (id_484) {
        Size id_486 { 2UL };
        choose_res_485 = id_486;
      } else {
        uint16_t id_487 { 2 };
        uint16_t id_488 { uint16_t((*p_0).index()) };
        bool id_489 { bool(id_487 == id_488) };
        Size choose_res_490;
        if (id_489) {
          Size id_491 { 2UL };
          choose_res_490 = id_491;
        } else {
          uint16_t id_492 { uint16_t((*p_0).index()) };
          uint16_t id_493 { 3 };
          bool id_494 { bool(id_492 == id_493) };
          Void id_495 { ((void)(assert(id_494)), ::dessser::VOID) };
          (void)id_495;
          Size id_496 { 2UL };
          choose_res_490 = id_496;
        }
        choose_res_485 = choose_res_490;
      }
      choose_res_480 = choose_res_485;
    }
    return choose_res_480;
  }
   };
  return fun476;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::representation> )> representation_sersize_of_row_binary(representation_sersize_of_row_binary_init());

/* 
    (fun ("{opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8}")
      (add
        (let "sz_362"
          (let "sz_358" (add (size 12) (apply (identifier "representation-sersize-of-row-binary") (get-field "representation" (param 0))))
            (add (identifier "sz_358")
              (add
                (let "n_ref_360" (make-vec (string-length (get-field "column" (param 0))))
                  (let "lebsz_ref_361" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_360")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_361")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_361") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_361")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_361")))))) 
                (size-of-u32 (string-length (get-field "column" (param 0)))))))
          (let "sz_ref_365"
            (make-vec
              (add (identifier "sz_362")
                (let "n_ref_363" (make-vec (cardinality (get-field "factors" (param 0))))
                  (let "lebsz_ref_364" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_363")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_364")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_364") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_364")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_364"))))))))
            (seq
              (let "repeat_n_366" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "factors" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_366")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_365")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_365"))
                        (let "wlen_367" (string-length (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_366")) (get-field "factors" (param 0))))
                          (add
                            (let "n_ref_368" (make-vec (identifier "wlen_367"))
                              (let "lebsz_ref_369" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_368")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_369")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_369") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_369")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_369")))))) 
                            (size-of-u32 (identifier "wlen_367")))))) 
                    (set-vec (u8 0) (identifier "repeat_n_366") (add (unsafe-nth (u8 0) (identifier "repeat_n_366")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_365"))))) (size 1)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::field> )> field_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::field> )> fun497 { [&fun497](std::shared_ptr<::dessser::gen::dashboard_widget::field>  p_0) {
    Size id_498 { 12UL };
    std::shared_ptr<::dessser::gen::dashboard_widget::representation>  id_499 { (*p_0).representation };
    Size id_500 { representation_sersize_of_row_binary(id_499) };
    Size id_501 { Size(id_498 + id_500) };
    Size let_res_502;
    {
      Size sz_358 { id_501 };
      std::string id_503 { (*p_0).column };
      uint32_t id_504 { (uint32_t)id_503.size() };
      Vec<1, uint32_t> id_505 {  id_504  };
      Size let_res_506;
      {
        Vec<1, uint32_t> n_ref_360 { id_505 };
        uint32_t id_507 { 1U };
        Vec<1, uint32_t> id_508 {  id_507  };
        Size let_res_509;
        {
          Vec<1, uint32_t> lebsz_ref_361 { id_508 };
          bool while_flag_510 { true };
          do {
            uint8_t id_511 { 0 };
            uint32_t id_512 { n_ref_360[id_511] };
            uint8_t id_513 { 0 };
            uint32_t id_514 { lebsz_ref_361[id_513] };
            uint8_t id_515 { 7 };
            uint32_t id_516 { uint32_t(id_514 << id_515) };
            bool id_517 { bool(id_512 >= id_516) };
            while_flag_510 = id_517;
            if (while_flag_510) {
              uint8_t id_518 { 0 };
              uint8_t id_519 { 0 };
              uint32_t id_520 { lebsz_ref_361[id_519] };
              uint32_t id_521 { 1U };
              uint32_t id_522 { uint32_t(id_520 + id_521) };
              Void id_523 { ((void)(lebsz_ref_361[id_518] = id_522), ::dessser::VOID) };
              (void)id_523;
            }
          } while (while_flag_510);
          (void)::dessser::VOID;
          uint8_t id_524 { 0 };
          uint32_t id_525 { lebsz_ref_361[id_524] };
          Size id_526 { Size(id_525) };
          let_res_509 = id_526;
        }
        let_res_506 = let_res_509;
      }
      std::string id_527 { (*p_0).column };
      uint32_t id_528 { (uint32_t)id_527.size() };
      Size id_529 { Size(id_528) };
      Size id_530 { Size(let_res_506 + id_529) };
      Size id_531 { Size(sz_358 + id_530) };
      let_res_502 = id_531;
    }
    Size let_res_532;
    {
      Size sz_362 { let_res_502 };
      Arr<std::string> id_533 { (*p_0).factors };
      uint32_t id_534 { id_533.size() };
      Vec<1, uint32_t> id_535 {  id_534  };
      Size let_res_536;
      {
        Vec<1, uint32_t> n_ref_363 { id_535 };
        uint32_t id_537 { 1U };
        Vec<1, uint32_t> id_538 {  id_537  };
        Size let_res_539;
        {
          Vec<1, uint32_t> lebsz_ref_364 { id_538 };
          bool while_flag_540 { true };
          do {
            uint8_t id_541 { 0 };
            uint32_t id_542 { n_ref_363[id_541] };
            uint8_t id_543 { 0 };
            uint32_t id_544 { lebsz_ref_364[id_543] };
            uint8_t id_545 { 7 };
            uint32_t id_546 { uint32_t(id_544 << id_545) };
            bool id_547 { bool(id_542 >= id_546) };
            while_flag_540 = id_547;
            if (while_flag_540) {
              uint8_t id_548 { 0 };
              uint8_t id_549 { 0 };
              uint32_t id_550 { lebsz_ref_364[id_549] };
              uint32_t id_551 { 1U };
              uint32_t id_552 { uint32_t(id_550 + id_551) };
              Void id_553 { ((void)(lebsz_ref_364[id_548] = id_552), ::dessser::VOID) };
              (void)id_553;
            }
          } while (while_flag_540);
          (void)::dessser::VOID;
          uint8_t id_554 { 0 };
          uint32_t id_555 { lebsz_ref_364[id_554] };
          Size id_556 { Size(id_555) };
          let_res_539 = id_556;
        }
        let_res_536 = let_res_539;
      }
      Size id_557 { Size(sz_362 + let_res_536) };
      Vec<1, Size> id_558 {  id_557  };
      Size let_res_559;
      {
        Vec<1, Size> sz_ref_365 { id_558 };
        int32_t id_560 { 0L };
        Vec<1, int32_t> id_561 {  id_560  };
        {
          Vec<1, int32_t> repeat_n_366 { id_561 };
          bool while_flag_562 { true };
          do {
            Arr<std::string> id_563 { (*p_0).factors };
            uint32_t id_564 { id_563.size() };
            int32_t id_565 { int32_t(id_564) };
            uint8_t id_566 { 0 };
            int32_t id_567 { repeat_n_366[id_566] };
            bool id_568 { bool(id_565 > id_567) };
            while_flag_562 = id_568;
            if (while_flag_562) {
              uint8_t id_569 { 0 };
              uint8_t id_570 { 0 };
              Size id_571 { sz_ref_365[id_570] };
              uint8_t id_572 { 0 };
              int32_t id_573 { repeat_n_366[id_572] };
              Arr<std::string> id_574 { (*p_0).factors };
              std::string id_575 { id_574[id_573] };
              uint32_t id_576 { (uint32_t)id_575.size() };
              Size let_res_577;
              {
                uint32_t wlen_367 { id_576 };
                Vec<1, uint32_t> id_578 {  wlen_367  };
                Size let_res_579;
                {
                  Vec<1, uint32_t> n_ref_368 { id_578 };
                  uint32_t id_580 { 1U };
                  Vec<1, uint32_t> id_581 {  id_580  };
                  Size let_res_582;
                  {
                    Vec<1, uint32_t> lebsz_ref_369 { id_581 };
                    bool while_flag_583 { true };
                    do {
                      uint8_t id_584 { 0 };
                      uint32_t id_585 { n_ref_368[id_584] };
                      uint8_t id_586 { 0 };
                      uint32_t id_587 { lebsz_ref_369[id_586] };
                      uint8_t id_588 { 7 };
                      uint32_t id_589 { uint32_t(id_587 << id_588) };
                      bool id_590 { bool(id_585 >= id_589) };
                      while_flag_583 = id_590;
                      if (while_flag_583) {
                        uint8_t id_591 { 0 };
                        uint8_t id_592 { 0 };
                        uint32_t id_593 { lebsz_ref_369[id_592] };
                        uint32_t id_594 { 1U };
                        uint32_t id_595 { uint32_t(id_593 + id_594) };
                        Void id_596 { ((void)(lebsz_ref_369[id_591] = id_595), ::dessser::VOID) };
                        (void)id_596;
                      }
                    } while (while_flag_583);
                    (void)::dessser::VOID;
                    uint8_t id_597 { 0 };
                    uint32_t id_598 { lebsz_ref_369[id_597] };
                    Size id_599 { Size(id_598) };
                    let_res_582 = id_599;
                  }
                  let_res_579 = let_res_582;
                }
                Size id_600 { Size(wlen_367) };
                Size id_601 { Size(let_res_579 + id_600) };
                let_res_577 = id_601;
              }
              Size id_602 { Size(id_571 + let_res_577) };
              Void id_603 { ((void)(sz_ref_365[id_569] = id_602), ::dessser::VOID) };
              (void)id_603;
              uint8_t id_604 { 0 };
              uint8_t id_605 { 0 };
              int32_t id_606 { repeat_n_366[id_605] };
              int32_t id_607 { 1L };
              int32_t id_608 { int32_t(id_606 + id_607) };
              Void id_609 { ((void)(repeat_n_366[id_604] = id_608), ::dessser::VOID) };
              (void)id_609;
              (void)id_609;
            }
          } while (while_flag_562);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_610 { 0 };
        Size id_611 { sz_ref_365[id_610] };
        let_res_559 = id_611;
      }
      let_res_532 = let_res_559;
    }
    Size id_612 { 1UL };
    Size id_613 { Size(let_res_532 + id_612) };
    return id_613;
  }
   };
  return fun497;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::field> )> field_sersize_of_row_binary(field_sersize_of_row_binary_init());

/* 
    (fun ("{name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]}")
      (let "sz_373" (add (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-field "name" (param 0))) (size 1))
        (let "sz_ref_376"
          (make-vec
            (add (identifier "sz_373")
              (let "n_ref_374" (make-vec (cardinality (get-field "fields" (param 0))))
                (let "lebsz_ref_375" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_374")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_375")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_375") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_375")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_375"))))))))
          (seq
            (let "repeat_n_377" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "fields" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_377")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_376")
                    (add (unsafe-nth (u8 0) (identifier "sz_ref_376")) (apply (identifier "field-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_377")) (get-field "fields" (param 0))))))
                  (set-vec (u8 0) (identifier "repeat_n_377") (add (unsafe-nth (u8 0) (identifier "repeat_n_377")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_376"))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::source> )> source_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::source> )> fun614 { [&fun614](std::shared_ptr<::dessser::gen::dashboard_widget::source>  p_0) {
    auto fun615 { dessser::gen::fq_function_name::sersize_of_row_binary };
    dessser::gen::fq_function_name::t_ext id_616 { (*p_0).name };
    Size id_617 { fun615(id_616) };
    Size id_618 { 1UL };
    Size id_619 { Size(id_617 + id_618) };
    Size let_res_620;
    {
      Size sz_373 { id_619 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > id_621 { (*p_0).fields };
      uint32_t id_622 { id_621.size() };
      Vec<1, uint32_t> id_623 {  id_622  };
      Size let_res_624;
      {
        Vec<1, uint32_t> n_ref_374 { id_623 };
        uint32_t id_625 { 1U };
        Vec<1, uint32_t> id_626 {  id_625  };
        Size let_res_627;
        {
          Vec<1, uint32_t> lebsz_ref_375 { id_626 };
          bool while_flag_628 { true };
          do {
            uint8_t id_629 { 0 };
            uint32_t id_630 { n_ref_374[id_629] };
            uint8_t id_631 { 0 };
            uint32_t id_632 { lebsz_ref_375[id_631] };
            uint8_t id_633 { 7 };
            uint32_t id_634 { uint32_t(id_632 << id_633) };
            bool id_635 { bool(id_630 >= id_634) };
            while_flag_628 = id_635;
            if (while_flag_628) {
              uint8_t id_636 { 0 };
              uint8_t id_637 { 0 };
              uint32_t id_638 { lebsz_ref_375[id_637] };
              uint32_t id_639 { 1U };
              uint32_t id_640 { uint32_t(id_638 + id_639) };
              Void id_641 { ((void)(lebsz_ref_375[id_636] = id_640), ::dessser::VOID) };
              (void)id_641;
            }
          } while (while_flag_628);
          (void)::dessser::VOID;
          uint8_t id_642 { 0 };
          uint32_t id_643 { lebsz_ref_375[id_642] };
          Size id_644 { Size(id_643) };
          let_res_627 = id_644;
        }
        let_res_624 = let_res_627;
      }
      Size id_645 { Size(sz_373 + let_res_624) };
      Vec<1, Size> id_646 {  id_645  };
      Size let_res_647;
      {
        Vec<1, Size> sz_ref_376 { id_646 };
        int32_t id_648 { 0L };
        Vec<1, int32_t> id_649 {  id_648  };
        {
          Vec<1, int32_t> repeat_n_377 { id_649 };
          bool while_flag_650 { true };
          do {
            Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > id_651 { (*p_0).fields };
            uint32_t id_652 { id_651.size() };
            int32_t id_653 { int32_t(id_652) };
            uint8_t id_654 { 0 };
            int32_t id_655 { repeat_n_377[id_654] };
            bool id_656 { bool(id_653 > id_655) };
            while_flag_650 = id_656;
            if (while_flag_650) {
              uint8_t id_657 { 0 };
              uint8_t id_658 { 0 };
              Size id_659 { sz_ref_376[id_658] };
              uint8_t id_660 { 0 };
              int32_t id_661 { repeat_n_377[id_660] };
              Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > id_662 { (*p_0).fields };
              std::shared_ptr<::dessser::gen::dashboard_widget::field>  id_663 { id_662[id_661] };
              Size id_664 { field_sersize_of_row_binary(id_663) };
              Size id_665 { Size(id_659 + id_664) };
              Void id_666 { ((void)(sz_ref_376[id_657] = id_665), ::dessser::VOID) };
              (void)id_666;
              uint8_t id_667 { 0 };
              uint8_t id_668 { 0 };
              int32_t id_669 { repeat_n_377[id_668] };
              int32_t id_670 { 1L };
              int32_t id_671 { int32_t(id_669 + id_670) };
              Void id_672 { ((void)(repeat_n_377[id_667] = id_671), ::dessser::VOID) };
              (void)id_672;
              (void)id_672;
            }
          } while (while_flag_650);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_673 { 0 };
        Size id_674 { sz_ref_376[id_673] };
        let_res_647 = id_674;
      }
      let_res_620 = let_res_647;
    }
    return let_res_620;
  }
   };
  return fun614;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::source> )> source_sersize_of_row_binary(source_sersize_of_row_binary_init());

/* 
    (fun ("[Linear Void | Logarithmic Void]") (if (eq (u16 0) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 1))) (size 2))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::scale> )> scale_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::scale> )> fun675 { [&fun675](std::shared_ptr<::dessser::gen::dashboard_widget::scale>  p_0) {
    uint16_t id_676 { 0 };
    uint16_t id_677 { uint16_t((*p_0).index()) };
    bool id_678 { bool(id_676 == id_677) };
    Size choose_res_679;
    if (id_678) {
      Size id_680 { 2UL };
      choose_res_679 = id_680;
    } else {
      uint16_t id_681 { uint16_t((*p_0).index()) };
      uint16_t id_682 { 1 };
      bool id_683 { bool(id_681 == id_682) };
      Void id_684 { ((void)(assert(id_683)), ::dessser::VOID) };
      (void)id_684;
      Size id_685 { 2UL };
      choose_res_679 = id_685;
    }
    return choose_res_679;
  }
   };
  return fun675;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::scale> )> scale_sersize_of_row_binary(scale_sersize_of_row_binary_init());

/* 
    (fun ("{left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])}") (add (size 2) (apply (identifier "scale-sersize-of-row-binary") (get-field "scale" (param 0)))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::axis> )> axis_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::axis> )> fun686 { [&fun686](std::shared_ptr<::dessser::gen::dashboard_widget::axis>  p_0) {
    Size id_687 { 2UL };
    std::shared_ptr<::dessser::gen::dashboard_widget::scale>  id_688 { (*p_0).scale };
    Size id_689 { scale_sersize_of_row_binary(id_688) };
    Size id_690 { Size(id_687 + id_689) };
    return id_690;
  }
   };
  return fun686;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::axis> )> axis_sersize_of_row_binary(axis_sersize_of_row_binary_init());

/* 
    (fun ("[Plot Void]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 2)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::type> )> type_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::type> )> fun691 { [&fun691](std::shared_ptr<::dessser::gen::dashboard_widget::type>  p_0) {
    uint16_t id_692 { uint16_t((*p_0).index()) };
    uint16_t id_693 { 0 };
    bool id_694 { bool(id_692 == id_693) };
    Void id_695 { ((void)(assert(id_694)), ::dessser::VOID) };
    (void)id_695;
    Size id_696 { 2UL };
    return id_696;
  }
   };
  return fun691;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::type> )> type_sersize_of_row_binary(type_sersize_of_row_binary_init());

/* 
    (fun ("{title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]}")
      (let "sz_388"
        (let "sz_383"
          (let "sz_382"
            (add
              (let "n_ref_380" (make-vec (string-length (get-field "title" (param 0))))
                (let "lebsz_ref_381" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_380")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_381")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_381") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_381")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_381")))))) 
              (size-of-u32 (string-length (get-field "title" (param 0))))) 
            (add (identifier "sz_382") (apply (identifier "type-sersize-of-row-binary") (get-field "type" (param 0)))))
          (let "sz_ref_386"
            (make-vec
              (add (identifier "sz_383")
                (let "n_ref_384" (make-vec (cardinality (get-field "axes" (param 0))))
                  (let "lebsz_ref_385" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_384")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_385")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_385") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_385")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_385"))))))))
            (seq
              (let "repeat_n_387" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "axes" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_387")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_386")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_386")) (apply (identifier "axis-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_387")) (get-field "axes" (param 0))))))
                    (set-vec (u8 0) (identifier "repeat_n_387") (add (unsafe-nth (u8 0) (identifier "repeat_n_387")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_386")))))
        (let "sz_ref_391"
          (make-vec
            (add (identifier "sz_388")
              (let "n_ref_389" (make-vec (cardinality (get-field "sources" (param 0))))
                (let "lebsz_ref_390" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_389")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_390")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_390") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_390")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_390"))))))))
          (seq
            (let "repeat_n_392" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "sources" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_392")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_391")
                    (add (unsafe-nth (u8 0) (identifier "sz_ref_391")) (apply (identifier "source-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_392")) (get-field "sources" (param 0))))))
                  (set-vec (u8 0) (identifier "repeat_n_392") (add (unsafe-nth (u8 0) (identifier "repeat_n_392")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_391"))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::chart> )> chart_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::chart> )> fun697 { [&fun697](std::shared_ptr<::dessser::gen::dashboard_widget::chart>  p_0) {
    std::string id_698 { (*p_0).title };
    uint32_t id_699 { (uint32_t)id_698.size() };
    Vec<1, uint32_t> id_700 {  id_699  };
    Size let_res_701;
    {
      Vec<1, uint32_t> n_ref_380 { id_700 };
      uint32_t id_702 { 1U };
      Vec<1, uint32_t> id_703 {  id_702  };
      Size let_res_704;
      {
        Vec<1, uint32_t> lebsz_ref_381 { id_703 };
        bool while_flag_705 { true };
        do {
          uint8_t id_706 { 0 };
          uint32_t id_707 { n_ref_380[id_706] };
          uint8_t id_708 { 0 };
          uint32_t id_709 { lebsz_ref_381[id_708] };
          uint8_t id_710 { 7 };
          uint32_t id_711 { uint32_t(id_709 << id_710) };
          bool id_712 { bool(id_707 >= id_711) };
          while_flag_705 = id_712;
          if (while_flag_705) {
            uint8_t id_713 { 0 };
            uint8_t id_714 { 0 };
            uint32_t id_715 { lebsz_ref_381[id_714] };
            uint32_t id_716 { 1U };
            uint32_t id_717 { uint32_t(id_715 + id_716) };
            Void id_718 { ((void)(lebsz_ref_381[id_713] = id_717), ::dessser::VOID) };
            (void)id_718;
          }
        } while (while_flag_705);
        (void)::dessser::VOID;
        uint8_t id_719 { 0 };
        uint32_t id_720 { lebsz_ref_381[id_719] };
        Size id_721 { Size(id_720) };
        let_res_704 = id_721;
      }
      let_res_701 = let_res_704;
    }
    std::string id_722 { (*p_0).title };
    uint32_t id_723 { (uint32_t)id_722.size() };
    Size id_724 { Size(id_723) };
    Size id_725 { Size(let_res_701 + id_724) };
    Size let_res_726;
    {
      Size sz_382 { id_725 };
      std::shared_ptr<::dessser::gen::dashboard_widget::type>  id_727 { (*p_0).type };
      Size id_728 { type_sersize_of_row_binary(id_727) };
      Size id_729 { Size(sz_382 + id_728) };
      let_res_726 = id_729;
    }
    Size let_res_730;
    {
      Size sz_383 { let_res_726 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_731 { (*p_0).axes };
      uint32_t id_732 { id_731.size() };
      Vec<1, uint32_t> id_733 {  id_732  };
      Size let_res_734;
      {
        Vec<1, uint32_t> n_ref_384 { id_733 };
        uint32_t id_735 { 1U };
        Vec<1, uint32_t> id_736 {  id_735  };
        Size let_res_737;
        {
          Vec<1, uint32_t> lebsz_ref_385 { id_736 };
          bool while_flag_738 { true };
          do {
            uint8_t id_739 { 0 };
            uint32_t id_740 { n_ref_384[id_739] };
            uint8_t id_741 { 0 };
            uint32_t id_742 { lebsz_ref_385[id_741] };
            uint8_t id_743 { 7 };
            uint32_t id_744 { uint32_t(id_742 << id_743) };
            bool id_745 { bool(id_740 >= id_744) };
            while_flag_738 = id_745;
            if (while_flag_738) {
              uint8_t id_746 { 0 };
              uint8_t id_747 { 0 };
              uint32_t id_748 { lebsz_ref_385[id_747] };
              uint32_t id_749 { 1U };
              uint32_t id_750 { uint32_t(id_748 + id_749) };
              Void id_751 { ((void)(lebsz_ref_385[id_746] = id_750), ::dessser::VOID) };
              (void)id_751;
            }
          } while (while_flag_738);
          (void)::dessser::VOID;
          uint8_t id_752 { 0 };
          uint32_t id_753 { lebsz_ref_385[id_752] };
          Size id_754 { Size(id_753) };
          let_res_737 = id_754;
        }
        let_res_734 = let_res_737;
      }
      Size id_755 { Size(sz_383 + let_res_734) };
      Vec<1, Size> id_756 {  id_755  };
      Size let_res_757;
      {
        Vec<1, Size> sz_ref_386 { id_756 };
        int32_t id_758 { 0L };
        Vec<1, int32_t> id_759 {  id_758  };
        {
          Vec<1, int32_t> repeat_n_387 { id_759 };
          bool while_flag_760 { true };
          do {
            Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_761 { (*p_0).axes };
            uint32_t id_762 { id_761.size() };
            int32_t id_763 { int32_t(id_762) };
            uint8_t id_764 { 0 };
            int32_t id_765 { repeat_n_387[id_764] };
            bool id_766 { bool(id_763 > id_765) };
            while_flag_760 = id_766;
            if (while_flag_760) {
              uint8_t id_767 { 0 };
              uint8_t id_768 { 0 };
              Size id_769 { sz_ref_386[id_768] };
              uint8_t id_770 { 0 };
              int32_t id_771 { repeat_n_387[id_770] };
              Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_772 { (*p_0).axes };
              std::shared_ptr<::dessser::gen::dashboard_widget::axis>  id_773 { id_772[id_771] };
              Size id_774 { axis_sersize_of_row_binary(id_773) };
              Size id_775 { Size(id_769 + id_774) };
              Void id_776 { ((void)(sz_ref_386[id_767] = id_775), ::dessser::VOID) };
              (void)id_776;
              uint8_t id_777 { 0 };
              uint8_t id_778 { 0 };
              int32_t id_779 { repeat_n_387[id_778] };
              int32_t id_780 { 1L };
              int32_t id_781 { int32_t(id_779 + id_780) };
              Void id_782 { ((void)(repeat_n_387[id_777] = id_781), ::dessser::VOID) };
              (void)id_782;
              (void)id_782;
            }
          } while (while_flag_760);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_783 { 0 };
        Size id_784 { sz_ref_386[id_783] };
        let_res_757 = id_784;
      }
      let_res_730 = let_res_757;
    }
    Size let_res_785;
    {
      Size sz_388 { let_res_730 };
      Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_786 { (*p_0).sources };
      uint32_t id_787 { id_786.size() };
      Vec<1, uint32_t> id_788 {  id_787  };
      Size let_res_789;
      {
        Vec<1, uint32_t> n_ref_389 { id_788 };
        uint32_t id_790 { 1U };
        Vec<1, uint32_t> id_791 {  id_790  };
        Size let_res_792;
        {
          Vec<1, uint32_t> lebsz_ref_390 { id_791 };
          bool while_flag_793 { true };
          do {
            uint8_t id_794 { 0 };
            uint32_t id_795 { n_ref_389[id_794] };
            uint8_t id_796 { 0 };
            uint32_t id_797 { lebsz_ref_390[id_796] };
            uint8_t id_798 { 7 };
            uint32_t id_799 { uint32_t(id_797 << id_798) };
            bool id_800 { bool(id_795 >= id_799) };
            while_flag_793 = id_800;
            if (while_flag_793) {
              uint8_t id_801 { 0 };
              uint8_t id_802 { 0 };
              uint32_t id_803 { lebsz_ref_390[id_802] };
              uint32_t id_804 { 1U };
              uint32_t id_805 { uint32_t(id_803 + id_804) };
              Void id_806 { ((void)(lebsz_ref_390[id_801] = id_805), ::dessser::VOID) };
              (void)id_806;
            }
          } while (while_flag_793);
          (void)::dessser::VOID;
          uint8_t id_807 { 0 };
          uint32_t id_808 { lebsz_ref_390[id_807] };
          Size id_809 { Size(id_808) };
          let_res_792 = id_809;
        }
        let_res_789 = let_res_792;
      }
      Size id_810 { Size(sz_388 + let_res_789) };
      Vec<1, Size> id_811 {  id_810  };
      Size let_res_812;
      {
        Vec<1, Size> sz_ref_391 { id_811 };
        int32_t id_813 { 0L };
        Vec<1, int32_t> id_814 {  id_813  };
        {
          Vec<1, int32_t> repeat_n_392 { id_814 };
          bool while_flag_815 { true };
          do {
            Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_816 { (*p_0).sources };
            uint32_t id_817 { id_816.size() };
            int32_t id_818 { int32_t(id_817) };
            uint8_t id_819 { 0 };
            int32_t id_820 { repeat_n_392[id_819] };
            bool id_821 { bool(id_818 > id_820) };
            while_flag_815 = id_821;
            if (while_flag_815) {
              uint8_t id_822 { 0 };
              uint8_t id_823 { 0 };
              Size id_824 { sz_ref_391[id_823] };
              uint8_t id_825 { 0 };
              int32_t id_826 { repeat_n_392[id_825] };
              Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_827 { (*p_0).sources };
              std::shared_ptr<::dessser::gen::dashboard_widget::source>  id_828 { id_827[id_826] };
              Size id_829 { source_sersize_of_row_binary(id_828) };
              Size id_830 { Size(id_824 + id_829) };
              Void id_831 { ((void)(sz_ref_391[id_822] = id_830), ::dessser::VOID) };
              (void)id_831;
              uint8_t id_832 { 0 };
              uint8_t id_833 { 0 };
              int32_t id_834 { repeat_n_392[id_833] };
              int32_t id_835 { 1L };
              int32_t id_836 { int32_t(id_834 + id_835) };
              Void id_837 { ((void)(repeat_n_392[id_832] = id_836), ::dessser::VOID) };
              (void)id_837;
              (void)id_837;
            }
          } while (while_flag_815);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_838 { 0 };
        Size id_839 { sz_ref_391[id_838] };
        let_res_812 = id_839;
      }
      let_res_785 = let_res_812;
    }
    return let_res_785;
  }
   };
  return fun697;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::chart> )> chart_sersize_of_row_binary(chart_sersize_of_row_binary_init());

/* 
    (fun ("[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]})]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_395" (make-vec (string-length (get-alt "Text" (param 0))))
              (let "lebsz_ref_396" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_395")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_396")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_396") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_396")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_396")))))) 
            (size-of-u32 (string-length (get-alt "Text" (param 0)))))) 
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "chart-sersize-of-row-binary") (get-alt "Chart" (param 0)))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::t> )> fun840 { [&fun840](std::shared_ptr<::dessser::gen::dashboard_widget::t>  p_0) {
    uint16_t id_841 { 0 };
    uint16_t id_842 { uint16_t((*p_0).index()) };
    bool id_843 { bool(id_841 == id_842) };
    Size choose_res_844;
    if (id_843) {
      Size id_845 { 2UL };
      std::string id_846 { std::get<0 /* Text */>((*p_0)) };
      uint32_t id_847 { (uint32_t)id_846.size() };
      Vec<1, uint32_t> id_848 {  id_847  };
      Size let_res_849;
      {
        Vec<1, uint32_t> n_ref_395 { id_848 };
        uint32_t id_850 { 1U };
        Vec<1, uint32_t> id_851 {  id_850  };
        Size let_res_852;
        {
          Vec<1, uint32_t> lebsz_ref_396 { id_851 };
          bool while_flag_853 { true };
          do {
            uint8_t id_854 { 0 };
            uint32_t id_855 { n_ref_395[id_854] };
            uint8_t id_856 { 0 };
            uint32_t id_857 { lebsz_ref_396[id_856] };
            uint8_t id_858 { 7 };
            uint32_t id_859 { uint32_t(id_857 << id_858) };
            bool id_860 { bool(id_855 >= id_859) };
            while_flag_853 = id_860;
            if (while_flag_853) {
              uint8_t id_861 { 0 };
              uint8_t id_862 { 0 };
              uint32_t id_863 { lebsz_ref_396[id_862] };
              uint32_t id_864 { 1U };
              uint32_t id_865 { uint32_t(id_863 + id_864) };
              Void id_866 { ((void)(lebsz_ref_396[id_861] = id_865), ::dessser::VOID) };
              (void)id_866;
            }
          } while (while_flag_853);
          (void)::dessser::VOID;
          uint8_t id_867 { 0 };
          uint32_t id_868 { lebsz_ref_396[id_867] };
          Size id_869 { Size(id_868) };
          let_res_852 = id_869;
        }
        let_res_849 = let_res_852;
      }
      std::string id_870 { std::get<0 /* Text */>((*p_0)) };
      uint32_t id_871 { (uint32_t)id_870.size() };
      Size id_872 { Size(id_871) };
      Size id_873 { Size(let_res_849 + id_872) };
      Size id_874 { Size(id_845 + id_873) };
      choose_res_844 = id_874;
    } else {
      uint16_t id_875 { uint16_t((*p_0).index()) };
      uint16_t id_876 { 1 };
      bool id_877 { bool(id_875 == id_876) };
      Void id_878 { ((void)(assert(id_877)), ::dessser::VOID) };
      (void)id_878;
      Size id_879 { 2UL };
      std::shared_ptr<::dessser::gen::dashboard_widget::chart>  id_880 { std::get<1 /* Chart */>((*p_0)) };
      Size id_881 { chart_sersize_of_row_binary(id_880) };
      Size id_882 { Size(id_879 + id_881) };
      choose_res_844 = id_882;
    }
    return choose_res_844;
  }
   };
  return fun840;
}
std::function<Size(std::shared_ptr<::dessser::gen::dashboard_widget::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_129" "make_snd_130"
        (let "dsum1_113" (let-pair "du16_fst_108" "du16_snd_109" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_108") (identifier "du16_snd_109")))
          (let-pair "dsum1_fst_114" "dsum1_snd_115" (identifier "dsum1_113")
            (if (eq (u16 0) (identifier "dsum1_fst_114")) (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 0 (nop)) (identifier "dsum1_snd_115"))
              (if (eq (u16 1) (identifier "dsum1_fst_114")) (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 1 (nop)) (identifier "dsum1_snd_115"))
                (if (eq (u16 2) (identifier "dsum1_fst_114")) (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 2 (nop)) (identifier "dsum1_snd_115"))
                  (seq (assert (eq (identifier "dsum1_fst_114") (u16 3))) (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 3 (nop)) (identifier "dsum1_snd_115"))))))))
        (make-tup (identifier "make_fst_129") (identifier "make_snd_130"))))
 */
static std::function<::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea(Pointer)> representation_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea(Pointer)> fun883 { [&fun883](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_884 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b letpair_res_885;
    {
      auto du16_fst_108 { std::get<0>(id_884) };
      auto du16_snd_109 { std::get<1>(id_884) };
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_886 { du16_fst_108, du16_snd_109 };
      letpair_res_885 = id_886;
    }
    ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea let_res_887;
    {
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b dsum1_113 { letpair_res_885 };
      ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea letpair_res_888;
      {
        auto dsum1_fst_114 { std::get<0>(dsum1_113) };
        auto dsum1_snd_115 { std::get<1>(dsum1_113) };
        uint16_t id_889 { 0 };
        bool id_890 { bool(id_889 == dsum1_fst_114) };
        ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea choose_res_891;
        if (id_890) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::dashboard_widget::representation>  id_892 { std::make_shared<::dessser::gen::dashboard_widget::representation>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea id_893 { id_892, dsum1_snd_115 };
          choose_res_891 = id_893;
        } else {
          uint16_t id_894 { 1 };
          bool id_895 { bool(id_894 == dsum1_fst_114) };
          ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea choose_res_896;
          if (id_895) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::dashboard_widget::representation>  id_897 { std::make_shared<::dessser::gen::dashboard_widget::representation>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea id_898 { id_897, dsum1_snd_115 };
            choose_res_896 = id_898;
          } else {
            uint16_t id_899 { 2 };
            bool id_900 { bool(id_899 == dsum1_fst_114) };
            ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea choose_res_901;
            if (id_900) {
              (void)::dessser::VOID;
              std::shared_ptr<::dessser::gen::dashboard_widget::representation>  id_902 { std::make_shared<::dessser::gen::dashboard_widget::representation>(std::in_place_index<2>, ::dessser::VOID) };
              ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea id_903 { id_902, dsum1_snd_115 };
              choose_res_901 = id_903;
            } else {
              uint16_t id_904 { 3 };
              bool id_905 { bool(dsum1_fst_114 == id_904) };
              Void id_906 { ((void)(assert(id_905)), ::dessser::VOID) };
              (void)id_906;
              (void)::dessser::VOID;
              std::shared_ptr<::dessser::gen::dashboard_widget::representation>  id_907 { std::make_shared<::dessser::gen::dashboard_widget::representation>(std::in_place_index<3>, ::dessser::VOID) };
              ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea id_908 { id_907, dsum1_snd_115 };
              choose_res_901 = id_908;
            }
            choose_res_896 = choose_res_901;
          }
          choose_res_891 = choose_res_896;
        }
        letpair_res_888 = choose_res_891;
      }
      let_res_887 = letpair_res_888;
    }
    ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea letpair_res_909;
    {
      auto make_fst_129 { std::get<0>(let_res_887) };
      auto make_snd_130 { std::get<1>(let_res_887) };
      ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea id_910 { make_fst_129, make_snd_130 };
      letpair_res_909 = id_910;
    }
    return letpair_res_909;
  }
   };
  return fun883;
}
std::function<::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea(Pointer)> representation_of_row_binary(representation_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_134" (let-pair "dfloat_fst_132" "dfloat_snd_133" (read-u64 little-endian (param 0)) (make-tup (float-of-u64 (identifier "dfloat_fst_132")) (identifier "dfloat_snd_133")))
        (let-pair "drec_fst_135" "drec_snd_136" (identifier "drec_134")
          (let "drec_140" (let-pair "du32_fst_138" "du32_snd_139" (read-u32 little-endian (identifier "drec_snd_136")) (make-tup (identifier "du32_fst_138") (identifier "du32_snd_139")))
            (let-pair "drec_fst_141" "drec_snd_142" (identifier "drec_140")
              (let "drec_143" (apply (identifier "representation-of-row-binary") (identifier "drec_snd_142"))
                (let-pair "drec_fst_144" "drec_snd_145" (identifier "drec_143")
                  (let "drec_158"
                    (let "dstring1_152"
                      (let "leb_ref_146" (make-vec (u32 0))
                        (let "shft_ref_147" (make-vec (u8 0))
                          (let "p_ref_148" (make-vec (identifier "drec_snd_145"))
                            (seq
                              (while
                                (let "leb128_149" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_148")))
                                  (let-pair "leb128_fst_150" "leb128_snd_151" 
                                    (identifier "leb128_149")
                                    (seq (set-vec (u8 0) (identifier "p_ref_148") (identifier "leb128_snd_151"))
                                      (set-vec (u8 0) (identifier "leb_ref_146")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_150") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_147"))) (unsafe-nth (u8 0) (identifier "leb_ref_146"))))
                                      (set-vec (u8 0) (identifier "shft_ref_147") (add (unsafe-nth (u8 0) (identifier "shft_ref_147")) (u8 7))) 
                                      (ge (identifier "leb128_fst_150") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_146"))) (unsafe-nth (u8 0) (identifier "p_ref_148")))))))
                      (let-pair "dstring1_fst_153" "dstring1_snd_154" 
                        (identifier "dstring1_152")
                        (let-pair "dstring2_fst_156" "dstring2_snd_157" 
                          (read-bytes (identifier "dstring1_snd_154") (identifier "dstring1_fst_153")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_156")) (identifier "dstring2_snd_157")))))
                    (let-pair "drec_fst_159" "drec_snd_160" (identifier "drec_158")
                      (let "drec_196"
                        (let-pair "dlist4_fst_194" "dlist4_snd_195"
                          (let "dlist1_170"
                            (let "leb_ref_161" (make-vec (u32 0))
                              (let "shft_ref_162" (make-vec (u8 0))
                                (let "p_ref_163" (make-vec (identifier "drec_snd_160"))
                                  (seq
                                    (while
                                      (let "leb128_164" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_163")))
                                        (let-pair "leb128_fst_165" "leb128_snd_166" 
                                          (identifier "leb128_164")
                                          (seq (set-vec (u8 0) (identifier "p_ref_163") (identifier "leb128_snd_166"))
                                            (set-vec (u8 0) (identifier "leb_ref_161")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_165") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_162"))) (unsafe-nth (u8 0) (identifier "leb_ref_161"))))
                                            (set-vec (u8 0) (identifier "shft_ref_162") (add (unsafe-nth (u8 0) (identifier "shft_ref_162")) (u8 7))) 
                                            (ge (identifier "leb128_fst_165") (u8 128))))) 
                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_161")) (unsafe-nth (u8 0) (identifier "p_ref_163")))))))
                            (let-pair "dlist1_fst_171" "dlist1_snd_172" 
                              (identifier "dlist1_170")
                              (let "inits_src_ref_173" (make-vec (make-tup (end-of-list "STRING") (identifier "dlist1_snd_172")))
                                (seq
                                  (let "repeat_n_174" (make-vec (i32 0))
                                    (while (gt (to-i32 (identifier "dlist1_fst_171")) (unsafe-nth (u8 0) (identifier "repeat_n_174")))
                                      (seq
                                        (let "dlist2_175" (unsafe-nth (u8 0) (identifier "inits_src_ref_173"))
                                          (let-pair "dlist2_fst_176" "dlist2_snd_177" 
                                            (identifier "dlist2_175")
                                            (set-vec (u8 0) (identifier "inits_src_ref_173")
                                              (let "dstring1_184"
                                                (let "leb_ref_178" (make-vec (u32 0))
                                                  (let "shft_ref_179" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_180" 
                                                      (make-vec (identifier "dlist2_snd_177"))
                                                      (seq
                                                        (while
                                                          (let "leb128_181" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_180")))
                                                            (let-pair "leb128_fst_182" "leb128_snd_183" 
                                                              (identifier "leb128_181")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_180") (identifier "leb128_snd_183"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_178")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_182") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_179")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_178")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_179") (add (unsafe-nth (u8 0) (identifier "shft_ref_179")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_182") (u8 128))))) 
                                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_178"))) (unsafe-nth (u8 0) (identifier "p_ref_180")))))))
                                                (let-pair "dstring1_fst_185" "dstring1_snd_186" 
                                                  (identifier "dstring1_184")
                                                  (let-pair "dstring2_fst_188" "dstring2_snd_189" 
                                                    (read-bytes (identifier "dstring1_snd_186") (identifier "dstring1_fst_185"))
                                                    (make-tup (cons (string-of-bytes (identifier "dstring2_fst_188")) (identifier "dlist2_fst_176")) (identifier "dstring2_snd_189"))))))))
                                        (set-vec (u8 0) (identifier "repeat_n_174") (add (unsafe-nth (u8 0) (identifier "repeat_n_174")) (i32 1)))))) 
                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_173")))))) 
                          (make-tup (arr-of-lst-rev (identifier "dlist4_fst_194")) (identifier "dlist4_snd_195")))
                        (let-pair "drec_fst_197" "drec_snd_198" (identifier "drec_196")
                          (let-pair "du8_fst_200" "du8_snd_201" (read-u8 (identifier "drec_snd_198"))
                            (make-tup
                              (make-rec (string "axis") (identifier "du8_fst_200") 
                                (string "factors") (identifier "drec_fst_197") 
                                (string "column") (identifier "drec_fst_159") 
                                (string "representation") (identifier "drec_fst_144") 
                                (string "color") (identifier "drec_fst_141") 
                                (string "opacity") (identifier "drec_fst_135")) 
                              (identifier "du8_snd_201"))))))))))))))
 */
static std::function<::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060(Pointer)> field_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060(Pointer)> fun911 { [&fun911](Pointer p_0) {
    ::dessser::gen::dashboard_widget::tf568409f41c9c0a265f7302110fc9084 id_912 { p_0.readU64Le() };
    ::dessser::gen::dashboard_widget::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_913;
    {
      auto dfloat_fst_132 { std::get<0>(id_912) };
      auto dfloat_snd_133 { std::get<1>(id_912) };
      double id_914 { float_of_qword(dfloat_fst_132) };
      ::dessser::gen::dashboard_widget::t5375de390f9cb5ae2ee5880ea1674828 id_915 { id_914, dfloat_snd_133 };
      letpair_res_913 = id_915;
    }
    ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 let_res_916;
    {
      ::dessser::gen::dashboard_widget::t5375de390f9cb5ae2ee5880ea1674828 drec_134 { letpair_res_913 };
      ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 letpair_res_917;
      {
        auto drec_fst_135 { std::get<0>(drec_134) };
        auto drec_snd_136 { std::get<1>(drec_134) };
        ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_918 { drec_snd_136.readU32Le() };
        ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_919;
        {
          auto du32_fst_138 { std::get<0>(id_918) };
          auto du32_snd_139 { std::get<1>(id_918) };
          ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_920 { du32_fst_138, du32_snd_139 };
          letpair_res_919 = id_920;
        }
        ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 let_res_921;
        {
          ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 drec_140 { letpair_res_919 };
          ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 letpair_res_922;
          {
            auto drec_fst_141 { std::get<0>(drec_140) };
            auto drec_snd_142 { std::get<1>(drec_140) };
            ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea id_923 { representation_of_row_binary(drec_snd_142) };
            ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 let_res_924;
            {
              ::dessser::gen::dashboard_widget::t8ef1c95fd186832d880a2244303e9cea drec_143 { id_923 };
              ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 letpair_res_925;
              {
                auto drec_fst_144 { std::get<0>(drec_143) };
                auto drec_snd_145 { std::get<1>(drec_143) };
                uint32_t id_926 { 0U };
                Vec<1, uint32_t> id_927 {  id_926  };
                ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_928;
                {
                  Vec<1, uint32_t> leb_ref_146 { id_927 };
                  uint8_t id_929 { 0 };
                  Vec<1, uint8_t> id_930 {  id_929  };
                  ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_931;
                  {
                    Vec<1, uint8_t> shft_ref_147 { id_930 };
                    Vec<1, Pointer> id_932 {  drec_snd_145  };
                    ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_933;
                    {
                      Vec<1, Pointer> p_ref_148 { id_932 };
                      bool while_flag_934 { true };
                      do {
                        uint8_t id_935 { 0 };
                        Pointer id_936 { p_ref_148[id_935] };
                        ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_937 { id_936.readU8() };
                        bool let_res_938;
                        {
                          ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_149 { id_937 };
                          bool letpair_res_939;
                          {
                            auto leb128_fst_150 { std::get<0>(leb128_149) };
                            auto leb128_snd_151 { std::get<1>(leb128_149) };
                            uint8_t id_940 { 0 };
                            Void id_941 { ((void)(p_ref_148[id_940] = leb128_snd_151), ::dessser::VOID) };
                            (void)id_941;
                            uint8_t id_942 { 0 };
                            uint8_t id_943 { 127 };
                            uint8_t id_944 { uint8_t(leb128_fst_150 & id_943) };
                            uint32_t id_945 { uint32_t(id_944) };
                            uint8_t id_946 { 0 };
                            uint8_t id_947 { shft_ref_147[id_946] };
                            uint32_t id_948 { uint32_t(id_945 << id_947) };
                            uint8_t id_949 { 0 };
                            uint32_t id_950 { leb_ref_146[id_949] };
                            uint32_t id_951 { uint32_t(id_948 | id_950) };
                            Void id_952 { ((void)(leb_ref_146[id_942] = id_951), ::dessser::VOID) };
                            (void)id_952;
                            uint8_t id_953 { 0 };
                            uint8_t id_954 { 0 };
                            uint8_t id_955 { shft_ref_147[id_954] };
                            uint8_t id_956 { 7 };
                            uint8_t id_957 { uint8_t(id_955 + id_956) };
                            Void id_958 { ((void)(shft_ref_147[id_953] = id_957), ::dessser::VOID) };
                            (void)id_958;
                            uint8_t id_959 { 128 };
                            bool id_960 { bool(leb128_fst_150 >= id_959) };
                            letpair_res_939 = id_960;
                          }
                          let_res_938 = letpair_res_939;
                        }
                        while_flag_934 = let_res_938;
                        if (while_flag_934) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_934);
                      (void)::dessser::VOID;
                      uint8_t id_961 { 0 };
                      uint32_t id_962 { leb_ref_146[id_961] };
                      Size id_963 { Size(id_962) };
                      uint8_t id_964 { 0 };
                      Pointer id_965 { p_ref_148[id_964] };
                      ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 id_966 { id_963, id_965 };
                      let_res_933 = id_966;
                    }
                    let_res_931 = let_res_933;
                  }
                  let_res_928 = let_res_931;
                }
                ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 let_res_967;
                {
                  ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 dstring1_152 { let_res_928 };
                  ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 letpair_res_968;
                  {
                    auto dstring1_fst_153 { std::get<0>(dstring1_152) };
                    auto dstring1_snd_154 { std::get<1>(dstring1_152) };
                    ::dessser::gen::dashboard_widget::t5887709cc43c8c8e24d28211e8c970a2 id_969 { dstring1_snd_154.readBytes(dstring1_fst_153) };
                    ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 letpair_res_970;
                    {
                      auto dstring2_fst_156 { std::get<0>(id_969) };
                      auto dstring2_snd_157 { std::get<1>(id_969) };
                      std::string id_971 { dstring2_fst_156.toString() };
                      ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 id_972 { id_971, dstring2_snd_157 };
                      letpair_res_970 = id_972;
                    }
                    letpair_res_968 = letpair_res_970;
                  }
                  let_res_967 = letpair_res_968;
                }
                ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 let_res_973;
                {
                  ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 drec_158 { let_res_967 };
                  ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 letpair_res_974;
                  {
                    auto drec_fst_159 { std::get<0>(drec_158) };
                    auto drec_snd_160 { std::get<1>(drec_158) };
                    uint32_t id_975 { 0U };
                    Vec<1, uint32_t> id_976 {  id_975  };
                    ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_977;
                    {
                      Vec<1, uint32_t> leb_ref_161 { id_976 };
                      uint8_t id_978 { 0 };
                      Vec<1, uint8_t> id_979 {  id_978  };
                      ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_980;
                      {
                        Vec<1, uint8_t> shft_ref_162 { id_979 };
                        Vec<1, Pointer> id_981 {  drec_snd_160  };
                        ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_982;
                        {
                          Vec<1, Pointer> p_ref_163 { id_981 };
                          bool while_flag_983 { true };
                          do {
                            uint8_t id_984 { 0 };
                            Pointer id_985 { p_ref_163[id_984] };
                            ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_986 { id_985.readU8() };
                            bool let_res_987;
                            {
                              ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_164 { id_986 };
                              bool letpair_res_988;
                              {
                                auto leb128_fst_165 { std::get<0>(leb128_164) };
                                auto leb128_snd_166 { std::get<1>(leb128_164) };
                                uint8_t id_989 { 0 };
                                Void id_990 { ((void)(p_ref_163[id_989] = leb128_snd_166), ::dessser::VOID) };
                                (void)id_990;
                                uint8_t id_991 { 0 };
                                uint8_t id_992 { 127 };
                                uint8_t id_993 { uint8_t(leb128_fst_165 & id_992) };
                                uint32_t id_994 { uint32_t(id_993) };
                                uint8_t id_995 { 0 };
                                uint8_t id_996 { shft_ref_162[id_995] };
                                uint32_t id_997 { uint32_t(id_994 << id_996) };
                                uint8_t id_998 { 0 };
                                uint32_t id_999 { leb_ref_161[id_998] };
                                uint32_t id_1000 { uint32_t(id_997 | id_999) };
                                Void id_1001 { ((void)(leb_ref_161[id_991] = id_1000), ::dessser::VOID) };
                                (void)id_1001;
                                uint8_t id_1002 { 0 };
                                uint8_t id_1003 { 0 };
                                uint8_t id_1004 { shft_ref_162[id_1003] };
                                uint8_t id_1005 { 7 };
                                uint8_t id_1006 { uint8_t(id_1004 + id_1005) };
                                Void id_1007 { ((void)(shft_ref_162[id_1002] = id_1006), ::dessser::VOID) };
                                (void)id_1007;
                                uint8_t id_1008 { 128 };
                                bool id_1009 { bool(leb128_fst_165 >= id_1008) };
                                letpair_res_988 = id_1009;
                              }
                              let_res_987 = letpair_res_988;
                            }
                            while_flag_983 = let_res_987;
                            if (while_flag_983) {
                              (void)::dessser::VOID;
                            }
                          } while (while_flag_983);
                          (void)::dessser::VOID;
                          uint8_t id_1010 { 0 };
                          uint32_t id_1011 { leb_ref_161[id_1010] };
                          uint8_t id_1012 { 0 };
                          Pointer id_1013 { p_ref_163[id_1012] };
                          ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_1014 { id_1011, id_1013 };
                          let_res_982 = id_1014;
                        }
                        let_res_980 = let_res_982;
                      }
                      let_res_977 = let_res_980;
                    }
                    ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d let_res_1015;
                    {
                      ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 dlist1_170 { let_res_977 };
                      ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d letpair_res_1016;
                      {
                        auto dlist1_fst_171 { std::get<0>(dlist1_170) };
                        auto dlist1_snd_172 { std::get<1>(dlist1_170) };
                        Lst<std::string> endoflist_1017;
                        ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d id_1018 { endoflist_1017, dlist1_snd_172 };
                        Vec<1, ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d> id_1019 {  id_1018  };
                        ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d let_res_1020;
                        {
                          Vec<1, ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d> inits_src_ref_173 { id_1019 };
                          int32_t id_1021 { 0L };
                          Vec<1, int32_t> id_1022 {  id_1021  };
                          {
                            Vec<1, int32_t> repeat_n_174 { id_1022 };
                            bool while_flag_1023 { true };
                            do {
                              int32_t id_1024 { int32_t(dlist1_fst_171) };
                              uint8_t id_1025 { 0 };
                              int32_t id_1026 { repeat_n_174[id_1025] };
                              bool id_1027 { bool(id_1024 > id_1026) };
                              while_flag_1023 = id_1027;
                              if (while_flag_1023) {
                                uint8_t id_1028 { 0 };
                                ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d id_1029 { inits_src_ref_173[id_1028] };
                                {
                                  ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d dlist2_175 { id_1029 };
                                  {
                                    auto dlist2_fst_176 { std::get<0>(dlist2_175) };
                                    auto dlist2_snd_177 { std::get<1>(dlist2_175) };
                                    uint8_t id_1030 { 0 };
                                    uint32_t id_1031 { 0U };
                                    Vec<1, uint32_t> id_1032 {  id_1031  };
                                    ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1033;
                                    {
                                      Vec<1, uint32_t> leb_ref_178 { id_1032 };
                                      uint8_t id_1034 { 0 };
                                      Vec<1, uint8_t> id_1035 {  id_1034  };
                                      ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1036;
                                      {
                                        Vec<1, uint8_t> shft_ref_179 { id_1035 };
                                        Vec<1, Pointer> id_1037 {  dlist2_snd_177  };
                                        ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1038;
                                        {
                                          Vec<1, Pointer> p_ref_180 { id_1037 };
                                          bool while_flag_1039 { true };
                                          do {
                                            uint8_t id_1040 { 0 };
                                            Pointer id_1041 { p_ref_180[id_1040] };
                                            ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1042 { id_1041.readU8() };
                                            bool let_res_1043;
                                            {
                                              ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_181 { id_1042 };
                                              bool letpair_res_1044;
                                              {
                                                auto leb128_fst_182 { std::get<0>(leb128_181) };
                                                auto leb128_snd_183 { std::get<1>(leb128_181) };
                                                uint8_t id_1045 { 0 };
                                                Void id_1046 { ((void)(p_ref_180[id_1045] = leb128_snd_183), ::dessser::VOID) };
                                                (void)id_1046;
                                                uint8_t id_1047 { 0 };
                                                uint8_t id_1048 { 127 };
                                                uint8_t id_1049 { uint8_t(leb128_fst_182 & id_1048) };
                                                uint32_t id_1050 { uint32_t(id_1049) };
                                                uint8_t id_1051 { 0 };
                                                uint8_t id_1052 { shft_ref_179[id_1051] };
                                                uint32_t id_1053 { uint32_t(id_1050 << id_1052) };
                                                uint8_t id_1054 { 0 };
                                                uint32_t id_1055 { leb_ref_178[id_1054] };
                                                uint32_t id_1056 { uint32_t(id_1053 | id_1055) };
                                                Void id_1057 { ((void)(leb_ref_178[id_1047] = id_1056), ::dessser::VOID) };
                                                (void)id_1057;
                                                uint8_t id_1058 { 0 };
                                                uint8_t id_1059 { 0 };
                                                uint8_t id_1060 { shft_ref_179[id_1059] };
                                                uint8_t id_1061 { 7 };
                                                uint8_t id_1062 { uint8_t(id_1060 + id_1061) };
                                                Void id_1063 { ((void)(shft_ref_179[id_1058] = id_1062), ::dessser::VOID) };
                                                (void)id_1063;
                                                uint8_t id_1064 { 128 };
                                                bool id_1065 { bool(leb128_fst_182 >= id_1064) };
                                                letpair_res_1044 = id_1065;
                                              }
                                              let_res_1043 = letpair_res_1044;
                                            }
                                            while_flag_1039 = let_res_1043;
                                            if (while_flag_1039) {
                                              (void)::dessser::VOID;
                                            }
                                          } while (while_flag_1039);
                                          (void)::dessser::VOID;
                                          uint8_t id_1066 { 0 };
                                          uint32_t id_1067 { leb_ref_178[id_1066] };
                                          Size id_1068 { Size(id_1067) };
                                          uint8_t id_1069 { 0 };
                                          Pointer id_1070 { p_ref_180[id_1069] };
                                          ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 id_1071 { id_1068, id_1070 };
                                          let_res_1038 = id_1071;
                                        }
                                        let_res_1036 = let_res_1038;
                                      }
                                      let_res_1033 = let_res_1036;
                                    }
                                    ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d let_res_1072;
                                    {
                                      ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 dstring1_184 { let_res_1033 };
                                      ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d letpair_res_1073;
                                      {
                                        auto dstring1_fst_185 { std::get<0>(dstring1_184) };
                                        auto dstring1_snd_186 { std::get<1>(dstring1_184) };
                                        ::dessser::gen::dashboard_widget::t5887709cc43c8c8e24d28211e8c970a2 id_1074 { dstring1_snd_186.readBytes(dstring1_fst_185) };
                                        ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d letpair_res_1075;
                                        {
                                          auto dstring2_fst_188 { std::get<0>(id_1074) };
                                          auto dstring2_snd_189 { std::get<1>(id_1074) };
                                          std::string id_1076 { dstring2_fst_188.toString() };
                                          Lst<std::string> id_1077 { id_1076, dlist2_fst_176 };
                                          ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d id_1078 { id_1077, dstring2_snd_189 };
                                          letpair_res_1075 = id_1078;
                                        }
                                        letpair_res_1073 = letpair_res_1075;
                                      }
                                      let_res_1072 = letpair_res_1073;
                                    }
                                    Void id_1079 { ((void)(inits_src_ref_173[id_1030] = let_res_1072), ::dessser::VOID) };
                                    (void)id_1079;
                                  }
                                  (void)::dessser::VOID;
                                }
                                (void)::dessser::VOID;
                                uint8_t id_1080 { 0 };
                                uint8_t id_1081 { 0 };
                                int32_t id_1082 { repeat_n_174[id_1081] };
                                int32_t id_1083 { 1L };
                                int32_t id_1084 { int32_t(id_1082 + id_1083) };
                                Void id_1085 { ((void)(repeat_n_174[id_1080] = id_1084), ::dessser::VOID) };
                                (void)id_1085;
                                (void)id_1085;
                              }
                            } while (while_flag_1023);
                            (void)::dessser::VOID;
                          }
                          (void)::dessser::VOID;
                          uint8_t id_1086 { 0 };
                          ::dessser::gen::dashboard_widget::t97f2951ce89391326d7f22e0db17439d id_1087 { inits_src_ref_173[id_1086] };
                          let_res_1020 = id_1087;
                        }
                        letpair_res_1016 = let_res_1020;
                      }
                      let_res_1015 = letpair_res_1016;
                    }
                    ::dessser::gen::dashboard_widget::tae8f20319160c4730608853dfb7fd182 letpair_res_1088;
                    {
                      auto dlist4_fst_194 { std::get<0>(let_res_1015) };
                      auto dlist4_snd_195 { std::get<1>(let_res_1015) };
                      Arr<std::string> id_1089 { dlist4_fst_194.toListRev() };
                      ::dessser::gen::dashboard_widget::tae8f20319160c4730608853dfb7fd182 id_1090 { id_1089, dlist4_snd_195 };
                      letpair_res_1088 = id_1090;
                    }
                    ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 let_res_1091;
                    {
                      ::dessser::gen::dashboard_widget::tae8f20319160c4730608853dfb7fd182 drec_196 { letpair_res_1088 };
                      ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 letpair_res_1092;
                      {
                        auto drec_fst_197 { std::get<0>(drec_196) };
                        auto drec_snd_198 { std::get<1>(drec_196) };
                        ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1093 { drec_snd_198.readU8() };
                        ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 letpair_res_1094;
                        {
                          auto du8_fst_200 { std::get<0>(id_1093) };
                          auto du8_snd_201 { std::get<1>(id_1093) };
                          std::shared_ptr<::dessser::gen::dashboard_widget::field>  id_1095 { std::make_shared<::dessser::gen::dashboard_widget::field>(du8_fst_200, drec_fst_141, drec_fst_159, drec_fst_197, drec_fst_135, drec_fst_144) };
                          ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 id_1096 { id_1095, du8_snd_201 };
                          letpair_res_1094 = id_1096;
                        }
                        letpair_res_1092 = letpair_res_1094;
                      }
                      let_res_1091 = letpair_res_1092;
                    }
                    letpair_res_974 = let_res_1091;
                  }
                  let_res_973 = letpair_res_974;
                }
                letpair_res_925 = let_res_973;
              }
              let_res_924 = letpair_res_925;
            }
            letpair_res_922 = let_res_924;
          }
          let_res_921 = letpair_res_922;
        }
        letpair_res_917 = let_res_921;
      }
      let_res_916 = letpair_res_917;
    }
    return let_res_916;
  }
   };
  return fun911;
}
std::function<::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060(Pointer)> field_of_row_binary(field_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_208" (apply (ext-identifier fq_function_name of-row-binary) (param 0))
        (let-pair "drec_fst_209" "drec_snd_210" (identifier "drec_208")
          (let "drec_214" (let-pair "dbool_fst_212" "dbool_snd_213" (read-u8 (identifier "drec_snd_210")) (make-tup (not (eq (identifier "dbool_fst_212") (u8 0))) (identifier "dbool_snd_213")))
            (let-pair "drec_fst_215" "drec_snd_216" (identifier "drec_214")
              (let-pair "dlist4_fst_238" "dlist4_snd_239"
                (let "dlist1_226"
                  (let "leb_ref_217" (make-vec (u32 0))
                    (let "shft_ref_218" (make-vec (u8 0))
                      (let "p_ref_219" (make-vec (identifier "drec_snd_216"))
                        (seq
                          (while
                            (let "leb128_220" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_219")))
                              (let-pair "leb128_fst_221" "leb128_snd_222" 
                                (identifier "leb128_220")
                                (seq (set-vec (u8 0) (identifier "p_ref_219") (identifier "leb128_snd_222"))
                                  (set-vec (u8 0) (identifier "leb_ref_217")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_221") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_218"))) (unsafe-nth (u8 0) (identifier "leb_ref_217"))))
                                  (set-vec (u8 0) (identifier "shft_ref_218") (add (unsafe-nth (u8 0) (identifier "shft_ref_218")) (u8 7))) 
                                  (ge (identifier "leb128_fst_221") (u8 128))))) 
                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_217")) (unsafe-nth (u8 0) (identifier "p_ref_219")))))))
                  (let-pair "dlist1_fst_227" "dlist1_snd_228" (identifier "dlist1_226")
                    (let "inits_src_ref_229"
                      (make-vec
                        (make-tup
                          (end-of-list "(field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})")
                          (identifier "dlist1_snd_228")))
                      (seq
                        (let "repeat_n_230" (make-vec (i32 0))
                          (while (gt (to-i32 (identifier "dlist1_fst_227")) (unsafe-nth (u8 0) (identifier "repeat_n_230")))
                            (seq
                              (let "dlist2_231" (unsafe-nth (u8 0) (identifier "inits_src_ref_229"))
                                (let-pair "dlist2_fst_232" "dlist2_snd_233" 
                                  (identifier "dlist2_231")
                                  (set-vec (u8 0) (identifier "inits_src_ref_229")
                                    (let-pair "dlist3_fst_235" "dlist3_snd_236" 
                                      (apply (identifier "field-of-row-binary") (identifier "dlist2_snd_233")) 
                                      (make-tup (cons (identifier "dlist3_fst_235") (identifier "dlist2_fst_232")) (identifier "dlist3_snd_236"))))))
                              (set-vec (u8 0) (identifier "repeat_n_230") (add (unsafe-nth (u8 0) (identifier "repeat_n_230")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "inits_src_ref_229"))))))
                (make-tup (make-rec (string "fields") (arr-of-lst-rev (identifier "dlist4_fst_238")) (string "visible") (identifier "drec_fst_215") (string "name") (identifier "drec_fst_209")) (identifier "dlist4_snd_239"))))))))
 */
static std::function<::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e(Pointer)> source_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e(Pointer)> fun1097 { [&fun1097](Pointer p_0) {
    auto fun1098 { dessser::gen::fq_function_name::of_row_binary };
    ::dessser::gen::dashboard_widget::tc67a116b5bcd191e2624b1f2b2b1794a id_1099 { fun1098(p_0) };
    ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e let_res_1100;
    {
      ::dessser::gen::dashboard_widget::tc67a116b5bcd191e2624b1f2b2b1794a drec_208 { id_1099 };
      ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e letpair_res_1101;
      {
        auto drec_fst_209 { std::get<0>(drec_208) };
        auto drec_snd_210 { std::get<1>(drec_208) };
        ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1102 { drec_snd_210.readU8() };
        ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e letpair_res_1103;
        {
          auto dbool_fst_212 { std::get<0>(id_1102) };
          auto dbool_snd_213 { std::get<1>(id_1102) };
          uint8_t id_1104 { 0 };
          bool id_1105 { bool(dbool_fst_212 == id_1104) };
          bool id_1106 { ! id_1105 };
          ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e id_1107 { id_1106, dbool_snd_213 };
          letpair_res_1103 = id_1107;
        }
        ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e let_res_1108;
        {
          ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e drec_214 { letpair_res_1103 };
          ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e letpair_res_1109;
          {
            auto drec_fst_215 { std::get<0>(drec_214) };
            auto drec_snd_216 { std::get<1>(drec_214) };
            uint32_t id_1110 { 0U };
            Vec<1, uint32_t> id_1111 {  id_1110  };
            ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1112;
            {
              Vec<1, uint32_t> leb_ref_217 { id_1111 };
              uint8_t id_1113 { 0 };
              Vec<1, uint8_t> id_1114 {  id_1113  };
              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1115;
              {
                Vec<1, uint8_t> shft_ref_218 { id_1114 };
                Vec<1, Pointer> id_1116 {  drec_snd_216  };
                ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1117;
                {
                  Vec<1, Pointer> p_ref_219 { id_1116 };
                  bool while_flag_1118 { true };
                  do {
                    uint8_t id_1119 { 0 };
                    Pointer id_1120 { p_ref_219[id_1119] };
                    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1121 { id_1120.readU8() };
                    bool let_res_1122;
                    {
                      ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_220 { id_1121 };
                      bool letpair_res_1123;
                      {
                        auto leb128_fst_221 { std::get<0>(leb128_220) };
                        auto leb128_snd_222 { std::get<1>(leb128_220) };
                        uint8_t id_1124 { 0 };
                        Void id_1125 { ((void)(p_ref_219[id_1124] = leb128_snd_222), ::dessser::VOID) };
                        (void)id_1125;
                        uint8_t id_1126 { 0 };
                        uint8_t id_1127 { 127 };
                        uint8_t id_1128 { uint8_t(leb128_fst_221 & id_1127) };
                        uint32_t id_1129 { uint32_t(id_1128) };
                        uint8_t id_1130 { 0 };
                        uint8_t id_1131 { shft_ref_218[id_1130] };
                        uint32_t id_1132 { uint32_t(id_1129 << id_1131) };
                        uint8_t id_1133 { 0 };
                        uint32_t id_1134 { leb_ref_217[id_1133] };
                        uint32_t id_1135 { uint32_t(id_1132 | id_1134) };
                        Void id_1136 { ((void)(leb_ref_217[id_1126] = id_1135), ::dessser::VOID) };
                        (void)id_1136;
                        uint8_t id_1137 { 0 };
                        uint8_t id_1138 { 0 };
                        uint8_t id_1139 { shft_ref_218[id_1138] };
                        uint8_t id_1140 { 7 };
                        uint8_t id_1141 { uint8_t(id_1139 + id_1140) };
                        Void id_1142 { ((void)(shft_ref_218[id_1137] = id_1141), ::dessser::VOID) };
                        (void)id_1142;
                        uint8_t id_1143 { 128 };
                        bool id_1144 { bool(leb128_fst_221 >= id_1143) };
                        letpair_res_1123 = id_1144;
                      }
                      let_res_1122 = letpair_res_1123;
                    }
                    while_flag_1118 = let_res_1122;
                    if (while_flag_1118) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_1118);
                  (void)::dessser::VOID;
                  uint8_t id_1145 { 0 };
                  uint32_t id_1146 { leb_ref_217[id_1145] };
                  uint8_t id_1147 { 0 };
                  Pointer id_1148 { p_ref_219[id_1147] };
                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_1149 { id_1146, id_1148 };
                  let_res_1117 = id_1149;
                }
                let_res_1115 = let_res_1117;
              }
              let_res_1112 = let_res_1115;
            }
            ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21 let_res_1150;
            {
              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 dlist1_226 { let_res_1112 };
              ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21 letpair_res_1151;
              {
                auto dlist1_fst_227 { std::get<0>(dlist1_226) };
                auto dlist1_snd_228 { std::get<1>(dlist1_226) };
                Lst<std::shared_ptr<::dessser::gen::dashboard_widget::field> > endoflist_1152;
                ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21 id_1153 { endoflist_1152, dlist1_snd_228 };
                Vec<1, ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21> id_1154 {  id_1153  };
                ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21 let_res_1155;
                {
                  Vec<1, ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21> inits_src_ref_229 { id_1154 };
                  int32_t id_1156 { 0L };
                  Vec<1, int32_t> id_1157 {  id_1156  };
                  {
                    Vec<1, int32_t> repeat_n_230 { id_1157 };
                    bool while_flag_1158 { true };
                    do {
                      int32_t id_1159 { int32_t(dlist1_fst_227) };
                      uint8_t id_1160 { 0 };
                      int32_t id_1161 { repeat_n_230[id_1160] };
                      bool id_1162 { bool(id_1159 > id_1161) };
                      while_flag_1158 = id_1162;
                      if (while_flag_1158) {
                        uint8_t id_1163 { 0 };
                        ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21 id_1164 { inits_src_ref_229[id_1163] };
                        {
                          ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21 dlist2_231 { id_1164 };
                          {
                            auto dlist2_fst_232 { std::get<0>(dlist2_231) };
                            auto dlist2_snd_233 { std::get<1>(dlist2_231) };
                            uint8_t id_1165 { 0 };
                            ::dessser::gen::dashboard_widget::t14c207e65f8f77a76ec87f66e5566060 id_1166 { field_of_row_binary(dlist2_snd_233) };
                            ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21 letpair_res_1167;
                            {
                              auto dlist3_fst_235 { std::get<0>(id_1166) };
                              auto dlist3_snd_236 { std::get<1>(id_1166) };
                              Lst<std::shared_ptr<::dessser::gen::dashboard_widget::field> > id_1168 { dlist3_fst_235, dlist2_fst_232 };
                              ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21 id_1169 { id_1168, dlist3_snd_236 };
                              letpair_res_1167 = id_1169;
                            }
                            Void id_1170 { ((void)(inits_src_ref_229[id_1165] = letpair_res_1167), ::dessser::VOID) };
                            (void)id_1170;
                          }
                          (void)::dessser::VOID;
                        }
                        (void)::dessser::VOID;
                        uint8_t id_1171 { 0 };
                        uint8_t id_1172 { 0 };
                        int32_t id_1173 { repeat_n_230[id_1172] };
                        int32_t id_1174 { 1L };
                        int32_t id_1175 { int32_t(id_1173 + id_1174) };
                        Void id_1176 { ((void)(repeat_n_230[id_1171] = id_1175), ::dessser::VOID) };
                        (void)id_1176;
                        (void)id_1176;
                      }
                    } while (while_flag_1158);
                    (void)::dessser::VOID;
                  }
                  (void)::dessser::VOID;
                  uint8_t id_1177 { 0 };
                  ::dessser::gen::dashboard_widget::tf127c32c360f30960192a3b115bf4c21 id_1178 { inits_src_ref_229[id_1177] };
                  let_res_1155 = id_1178;
                }
                letpair_res_1151 = let_res_1155;
              }
              let_res_1150 = letpair_res_1151;
            }
            ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e letpair_res_1179;
            {
              auto dlist4_fst_238 { std::get<0>(let_res_1150) };
              auto dlist4_snd_239 { std::get<1>(let_res_1150) };
              Arr<std::shared_ptr<::dessser::gen::dashboard_widget::field> > id_1180 { dlist4_fst_238.toListRev() };
              std::shared_ptr<::dessser::gen::dashboard_widget::source>  id_1181 { std::make_shared<::dessser::gen::dashboard_widget::source>(id_1180, drec_fst_209, drec_fst_215) };
              ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e id_1182 { id_1181, dlist4_snd_239 };
              letpair_res_1179 = id_1182;
            }
            letpair_res_1109 = letpair_res_1179;
          }
          let_res_1108 = letpair_res_1109;
        }
        letpair_res_1101 = let_res_1108;
      }
      let_res_1100 = letpair_res_1101;
    }
    return let_res_1100;
  }
   };
  return fun1097;
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
  std::function<::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7(Pointer)> fun1183 { [&fun1183](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1184 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1185;
    {
      auto du16_fst_72 { std::get<0>(id_1184) };
      auto du16_snd_73 { std::get<1>(id_1184) };
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1186 { du16_fst_72, du16_snd_73 };
      letpair_res_1185 = id_1186;
    }
    ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 let_res_1187;
    {
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b dsum1_77 { letpair_res_1185 };
      ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 letpair_res_1188;
      {
        auto dsum1_fst_78 { std::get<0>(dsum1_77) };
        auto dsum1_snd_79 { std::get<1>(dsum1_77) };
        uint16_t id_1189 { 0 };
        bool id_1190 { bool(id_1189 == dsum1_fst_78) };
        ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 choose_res_1191;
        if (id_1190) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::dashboard_widget::scale>  id_1192 { std::make_shared<::dessser::gen::dashboard_widget::scale>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 id_1193 { id_1192, dsum1_snd_79 };
          choose_res_1191 = id_1193;
        } else {
          uint16_t id_1194 { 1 };
          bool id_1195 { bool(dsum1_fst_78 == id_1194) };
          Void id_1196 { ((void)(assert(id_1195)), ::dessser::VOID) };
          (void)id_1196;
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::dashboard_widget::scale>  id_1197 { std::make_shared<::dessser::gen::dashboard_widget::scale>(std::in_place_index<1>, ::dessser::VOID) };
          ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 id_1198 { id_1197, dsum1_snd_79 };
          choose_res_1191 = id_1198;
        }
        letpair_res_1188 = choose_res_1191;
      }
      let_res_1187 = letpair_res_1188;
    }
    ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 letpair_res_1199;
    {
      auto make_fst_87 { std::get<0>(let_res_1187) };
      auto make_snd_88 { std::get<1>(let_res_1187) };
      ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 id_1200 { make_fst_87, make_snd_88 };
      letpair_res_1199 = id_1200;
    }
    return letpair_res_1199;
  }
   };
  return fun1183;
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
  std::function<::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552(Pointer)> fun1201 { [&fun1201](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1202 { p_0.readU8() };
    ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e letpair_res_1203;
    {
      auto dbool_fst_90 { std::get<0>(id_1202) };
      auto dbool_snd_91 { std::get<1>(id_1202) };
      uint8_t id_1204 { 0 };
      bool id_1205 { bool(dbool_fst_90 == id_1204) };
      bool id_1206 { ! id_1205 };
      ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e id_1207 { id_1206, dbool_snd_91 };
      letpair_res_1203 = id_1207;
    }
    ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 let_res_1208;
    {
      ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e drec_92 { letpair_res_1203 };
      ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 letpair_res_1209;
      {
        auto drec_fst_93 { std::get<0>(drec_92) };
        auto drec_snd_94 { std::get<1>(drec_92) };
        ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1210 { drec_snd_94.readU8() };
        ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e letpair_res_1211;
        {
          auto dbool_fst_96 { std::get<0>(id_1210) };
          auto dbool_snd_97 { std::get<1>(id_1210) };
          uint8_t id_1212 { 0 };
          bool id_1213 { bool(dbool_fst_96 == id_1212) };
          bool id_1214 { ! id_1213 };
          ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e id_1215 { id_1214, dbool_snd_97 };
          letpair_res_1211 = id_1215;
        }
        ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 let_res_1216;
        {
          ::dessser::gen::dashboard_widget::t8f6cce063b0da10e7eea29b507eded2e drec_98 { letpair_res_1211 };
          ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 letpair_res_1217;
          {
            auto drec_fst_99 { std::get<0>(drec_98) };
            auto drec_snd_100 { std::get<1>(drec_98) };
            ::dessser::gen::dashboard_widget::tf9ef46e559cc4aa51a61b6310df405c7 id_1218 { scale_of_row_binary(drec_snd_100) };
            ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 letpair_res_1219;
            {
              auto drec_fst_102 { std::get<0>(id_1218) };
              auto drec_snd_103 { std::get<1>(id_1218) };
              std::shared_ptr<::dessser::gen::dashboard_widget::axis>  id_1220 { std::make_shared<::dessser::gen::dashboard_widget::axis>(drec_fst_99, drec_fst_93, drec_fst_102) };
              ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 id_1221 { id_1220, drec_snd_103 };
              letpair_res_1219 = id_1221;
            }
            letpair_res_1217 = letpair_res_1219;
          }
          let_res_1216 = letpair_res_1217;
        }
        letpair_res_1209 = let_res_1216;
      }
      let_res_1208 = letpair_res_1209;
    }
    return let_res_1208;
  }
   };
  return fun1201;
}
std::function<::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552(Pointer)> axis_of_row_binary(axis_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62") (seq (assert (eq (identifier "dsum1_fst_63") (u16 0))) (make-tup (construct "[Plot Void]" 0 (nop)) (identifier "dsum1_snd_64"))))))
 */
static std::function<::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681(Pointer)> type_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681(Pointer)> fun1222 { [&fun1222](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1223 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1224;
    {
      auto du16_fst_57 { std::get<0>(id_1223) };
      auto du16_snd_58 { std::get<1>(id_1223) };
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1225 { du16_fst_57, du16_snd_58 };
      letpair_res_1224 = id_1225;
    }
    ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 let_res_1226;
    {
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_1224 };
      ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 letpair_res_1227;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_1228 { 0 };
        bool id_1229 { bool(dsum1_fst_63 == id_1228) };
        Void id_1230 { ((void)(assert(id_1229)), ::dessser::VOID) };
        (void)id_1230;
        (void)::dessser::VOID;
        std::shared_ptr<::dessser::gen::dashboard_widget::type>  id_1231 { std::make_shared<::dessser::gen::dashboard_widget::type>(std::in_place_index<0>, ::dessser::VOID) };
        ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 id_1232 { id_1231, dsum1_snd_64 };
        letpair_res_1227 = id_1232;
      }
      let_res_1226 = letpair_res_1227;
    }
    return let_res_1226;
  }
   };
  return fun1222;
}
std::function<::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681(Pointer)> type_of_row_binary(type_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_258"
        (let "dstring1_252"
          (let "leb_ref_246" (make-vec (u32 0))
            (let "shft_ref_247" (make-vec (u8 0))
              (let "p_ref_248" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_249" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_248")))
                      (let-pair "leb128_fst_250" "leb128_snd_251" (identifier "leb128_249")
                        (seq (set-vec (u8 0) (identifier "p_ref_248") (identifier "leb128_snd_251"))
                          (set-vec (u8 0) (identifier "leb_ref_246")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_250") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_247"))) (unsafe-nth (u8 0) (identifier "leb_ref_246"))))
                          (set-vec (u8 0) (identifier "shft_ref_247") (add (unsafe-nth (u8 0) (identifier "shft_ref_247")) (u8 7))) 
                          (ge (identifier "leb128_fst_250") (u8 128))))) 
                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_246"))) (unsafe-nth (u8 0) (identifier "p_ref_248")))))))
          (let-pair "dstring1_fst_253" "dstring1_snd_254" (identifier "dstring1_252")
            (let-pair "dstring2_fst_256" "dstring2_snd_257" (read-bytes (identifier "dstring1_snd_254") (identifier "dstring1_fst_253"))
              (make-tup (string-of-bytes (identifier "dstring2_fst_256")) (identifier "dstring2_snd_257")))))
        (let-pair "drec_fst_259" "drec_snd_260" (identifier "drec_258")
          (let "drec_261" (apply (identifier "type-of-row-binary") (identifier "drec_snd_260"))
            (let-pair "drec_fst_262" "drec_snd_263" (identifier "drec_261")
              (let "drec_287"
                (let-pair "dlist4_fst_285" "dlist4_snd_286"
                  (let "dlist1_273"
                    (let "leb_ref_264" (make-vec (u32 0))
                      (let "shft_ref_265" (make-vec (u8 0))
                        (let "p_ref_266" (make-vec (identifier "drec_snd_263"))
                          (seq
                            (while
                              (let "leb128_267" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_266")))
                                (let-pair "leb128_fst_268" "leb128_snd_269" 
                                  (identifier "leb128_267")
                                  (seq (set-vec (u8 0) (identifier "p_ref_266") (identifier "leb128_snd_269"))
                                    (set-vec (u8 0) (identifier "leb_ref_264")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_268") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_265"))) (unsafe-nth (u8 0) (identifier "leb_ref_264"))))
                                    (set-vec (u8 0) (identifier "shft_ref_265") (add (unsafe-nth (u8 0) (identifier "shft_ref_265")) (u8 7))) 
                                    (ge (identifier "leb128_fst_268") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_264")) (unsafe-nth (u8 0) (identifier "p_ref_266")))))))
                    (let-pair "dlist1_fst_274" "dlist1_snd_275" (identifier "dlist1_273")
                      (let "inits_src_ref_276" (make-vec (make-tup (end-of-list "(axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})") (identifier "dlist1_snd_275")))
                        (seq
                          (let "repeat_n_277" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_274")) (unsafe-nth (u8 0) (identifier "repeat_n_277")))
                              (seq
                                (let "dlist2_278" (unsafe-nth (u8 0) (identifier "inits_src_ref_276"))
                                  (let-pair "dlist2_fst_279" "dlist2_snd_280" 
                                    (identifier "dlist2_278")
                                    (set-vec (u8 0) (identifier "inits_src_ref_276")
                                      (let-pair "dlist3_fst_282" "dlist3_snd_283" 
                                        (apply (identifier "axis-of-row-binary") (identifier "dlist2_snd_280")) 
                                        (make-tup (cons (identifier "dlist3_fst_282") (identifier "dlist2_fst_279")) (identifier "dlist3_snd_283"))))))
                                (set-vec (u8 0) (identifier "repeat_n_277") (add (unsafe-nth (u8 0) (identifier "repeat_n_277")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_276")))))) 
                  (make-tup (arr-of-lst-rev (identifier "dlist4_fst_285")) (identifier "dlist4_snd_286")))
                (let-pair "drec_fst_288" "drec_snd_289" (identifier "drec_287")
                  (let-pair "dlist4_fst_311" "dlist4_snd_312"
                    (let "dlist1_299"
                      (let "leb_ref_290" (make-vec (u32 0))
                        (let "shft_ref_291" (make-vec (u8 0))
                          (let "p_ref_292" (make-vec (identifier "drec_snd_289"))
                            (seq
                              (while
                                (let "leb128_293" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_292")))
                                  (let-pair "leb128_fst_294" "leb128_snd_295" 
                                    (identifier "leb128_293")
                                    (seq (set-vec (u8 0) (identifier "p_ref_292") (identifier "leb128_snd_295"))
                                      (set-vec (u8 0) (identifier "leb_ref_290")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_294") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_291"))) (unsafe-nth (u8 0) (identifier "leb_ref_290"))))
                                      (set-vec (u8 0) (identifier "shft_ref_291") (add (unsafe-nth (u8 0) (identifier "shft_ref_291")) (u8 7))) 
                                      (ge (identifier "leb128_fst_294") (u8 128))))) 
                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_290")) (unsafe-nth (u8 0) (identifier "p_ref_292")))))))
                      (let-pair "dlist1_fst_300" "dlist1_snd_301" (identifier "dlist1_299")
                        (let "inits_src_ref_302"
                          (make-vec
                            (make-tup
                              (end-of-list "(source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})")
                              (identifier "dlist1_snd_301")))
                          (seq
                            (let "repeat_n_303" (make-vec (i32 0))
                              (while (gt (to-i32 (identifier "dlist1_fst_300")) (unsafe-nth (u8 0) (identifier "repeat_n_303")))
                                (seq
                                  (let "dlist2_304" (unsafe-nth (u8 0) (identifier "inits_src_ref_302"))
                                    (let-pair "dlist2_fst_305" "dlist2_snd_306" 
                                      (identifier "dlist2_304")
                                      (set-vec (u8 0) (identifier "inits_src_ref_302")
                                        (let-pair "dlist3_fst_308" "dlist3_snd_309" 
                                          (apply (identifier "source-of-row-binary") (identifier "dlist2_snd_306")) 
                                          (make-tup (cons (identifier "dlist3_fst_308") (identifier "dlist2_fst_305")) (identifier "dlist3_snd_309"))))))
                                  (set-vec (u8 0) (identifier "repeat_n_303") (add (unsafe-nth (u8 0) (identifier "repeat_n_303")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "inits_src_ref_302"))))))
                    (make-tup
                      (make-rec (string "sources") (arr-of-lst-rev (identifier "dlist4_fst_311")) 
                        (string "axes") (identifier "drec_fst_288") (string "type") 
                        (identifier "drec_fst_262") (string "title") 
                        (identifier "drec_fst_259")) (identifier "dlist4_snd_312"))))))))))
 */
static std::function<::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70(Pointer)> chart_of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70(Pointer)> fun1233 { [&fun1233](Pointer p_0) {
    uint32_t id_1234 { 0U };
    Vec<1, uint32_t> id_1235 {  id_1234  };
    ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1236;
    {
      Vec<1, uint32_t> leb_ref_246 { id_1235 };
      uint8_t id_1237 { 0 };
      Vec<1, uint8_t> id_1238 {  id_1237  };
      ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1239;
      {
        Vec<1, uint8_t> shft_ref_247 { id_1238 };
        Vec<1, Pointer> id_1240 {  p_0  };
        ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1241;
        {
          Vec<1, Pointer> p_ref_248 { id_1240 };
          bool while_flag_1242 { true };
          do {
            uint8_t id_1243 { 0 };
            Pointer id_1244 { p_ref_248[id_1243] };
            ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1245 { id_1244.readU8() };
            bool let_res_1246;
            {
              ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_249 { id_1245 };
              bool letpair_res_1247;
              {
                auto leb128_fst_250 { std::get<0>(leb128_249) };
                auto leb128_snd_251 { std::get<1>(leb128_249) };
                uint8_t id_1248 { 0 };
                Void id_1249 { ((void)(p_ref_248[id_1248] = leb128_snd_251), ::dessser::VOID) };
                (void)id_1249;
                uint8_t id_1250 { 0 };
                uint8_t id_1251 { 127 };
                uint8_t id_1252 { uint8_t(leb128_fst_250 & id_1251) };
                uint32_t id_1253 { uint32_t(id_1252) };
                uint8_t id_1254 { 0 };
                uint8_t id_1255 { shft_ref_247[id_1254] };
                uint32_t id_1256 { uint32_t(id_1253 << id_1255) };
                uint8_t id_1257 { 0 };
                uint32_t id_1258 { leb_ref_246[id_1257] };
                uint32_t id_1259 { uint32_t(id_1256 | id_1258) };
                Void id_1260 { ((void)(leb_ref_246[id_1250] = id_1259), ::dessser::VOID) };
                (void)id_1260;
                uint8_t id_1261 { 0 };
                uint8_t id_1262 { 0 };
                uint8_t id_1263 { shft_ref_247[id_1262] };
                uint8_t id_1264 { 7 };
                uint8_t id_1265 { uint8_t(id_1263 + id_1264) };
                Void id_1266 { ((void)(shft_ref_247[id_1261] = id_1265), ::dessser::VOID) };
                (void)id_1266;
                uint8_t id_1267 { 128 };
                bool id_1268 { bool(leb128_fst_250 >= id_1267) };
                letpair_res_1247 = id_1268;
              }
              let_res_1246 = letpair_res_1247;
            }
            while_flag_1242 = let_res_1246;
            if (while_flag_1242) {
              (void)::dessser::VOID;
            }
          } while (while_flag_1242);
          (void)::dessser::VOID;
          uint8_t id_1269 { 0 };
          uint32_t id_1270 { leb_ref_246[id_1269] };
          Size id_1271 { Size(id_1270) };
          uint8_t id_1272 { 0 };
          Pointer id_1273 { p_ref_248[id_1272] };
          ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 id_1274 { id_1271, id_1273 };
          let_res_1241 = id_1274;
        }
        let_res_1239 = let_res_1241;
      }
      let_res_1236 = let_res_1239;
    }
    ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 let_res_1275;
    {
      ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 dstring1_252 { let_res_1236 };
      ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 letpair_res_1276;
      {
        auto dstring1_fst_253 { std::get<0>(dstring1_252) };
        auto dstring1_snd_254 { std::get<1>(dstring1_252) };
        ::dessser::gen::dashboard_widget::t5887709cc43c8c8e24d28211e8c970a2 id_1277 { dstring1_snd_254.readBytes(dstring1_fst_253) };
        ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 letpair_res_1278;
        {
          auto dstring2_fst_256 { std::get<0>(id_1277) };
          auto dstring2_snd_257 { std::get<1>(id_1277) };
          std::string id_1279 { dstring2_fst_256.toString() };
          ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 id_1280 { id_1279, dstring2_snd_257 };
          letpair_res_1278 = id_1280;
        }
        letpair_res_1276 = letpair_res_1278;
      }
      let_res_1275 = letpair_res_1276;
    }
    ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 let_res_1281;
    {
      ::dessser::gen::dashboard_widget::t3fd8221434e489b54b5c4356ebff5005 drec_258 { let_res_1275 };
      ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 letpair_res_1282;
      {
        auto drec_fst_259 { std::get<0>(drec_258) };
        auto drec_snd_260 { std::get<1>(drec_258) };
        ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 id_1283 { type_of_row_binary(drec_snd_260) };
        ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 let_res_1284;
        {
          ::dessser::gen::dashboard_widget::tb8736edae5c2876425e55b9d652a8681 drec_261 { id_1283 };
          ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 letpair_res_1285;
          {
            auto drec_fst_262 { std::get<0>(drec_261) };
            auto drec_snd_263 { std::get<1>(drec_261) };
            uint32_t id_1286 { 0U };
            Vec<1, uint32_t> id_1287 {  id_1286  };
            ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1288;
            {
              Vec<1, uint32_t> leb_ref_264 { id_1287 };
              uint8_t id_1289 { 0 };
              Vec<1, uint8_t> id_1290 {  id_1289  };
              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1291;
              {
                Vec<1, uint8_t> shft_ref_265 { id_1290 };
                Vec<1, Pointer> id_1292 {  drec_snd_263  };
                ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1293;
                {
                  Vec<1, Pointer> p_ref_266 { id_1292 };
                  bool while_flag_1294 { true };
                  do {
                    uint8_t id_1295 { 0 };
                    Pointer id_1296 { p_ref_266[id_1295] };
                    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1297 { id_1296.readU8() };
                    bool let_res_1298;
                    {
                      ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_267 { id_1297 };
                      bool letpair_res_1299;
                      {
                        auto leb128_fst_268 { std::get<0>(leb128_267) };
                        auto leb128_snd_269 { std::get<1>(leb128_267) };
                        uint8_t id_1300 { 0 };
                        Void id_1301 { ((void)(p_ref_266[id_1300] = leb128_snd_269), ::dessser::VOID) };
                        (void)id_1301;
                        uint8_t id_1302 { 0 };
                        uint8_t id_1303 { 127 };
                        uint8_t id_1304 { uint8_t(leb128_fst_268 & id_1303) };
                        uint32_t id_1305 { uint32_t(id_1304) };
                        uint8_t id_1306 { 0 };
                        uint8_t id_1307 { shft_ref_265[id_1306] };
                        uint32_t id_1308 { uint32_t(id_1305 << id_1307) };
                        uint8_t id_1309 { 0 };
                        uint32_t id_1310 { leb_ref_264[id_1309] };
                        uint32_t id_1311 { uint32_t(id_1308 | id_1310) };
                        Void id_1312 { ((void)(leb_ref_264[id_1302] = id_1311), ::dessser::VOID) };
                        (void)id_1312;
                        uint8_t id_1313 { 0 };
                        uint8_t id_1314 { 0 };
                        uint8_t id_1315 { shft_ref_265[id_1314] };
                        uint8_t id_1316 { 7 };
                        uint8_t id_1317 { uint8_t(id_1315 + id_1316) };
                        Void id_1318 { ((void)(shft_ref_265[id_1313] = id_1317), ::dessser::VOID) };
                        (void)id_1318;
                        uint8_t id_1319 { 128 };
                        bool id_1320 { bool(leb128_fst_268 >= id_1319) };
                        letpair_res_1299 = id_1320;
                      }
                      let_res_1298 = letpair_res_1299;
                    }
                    while_flag_1294 = let_res_1298;
                    if (while_flag_1294) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_1294);
                  (void)::dessser::VOID;
                  uint8_t id_1321 { 0 };
                  uint32_t id_1322 { leb_ref_264[id_1321] };
                  uint8_t id_1323 { 0 };
                  Pointer id_1324 { p_ref_266[id_1323] };
                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_1325 { id_1322, id_1324 };
                  let_res_1293 = id_1325;
                }
                let_res_1291 = let_res_1293;
              }
              let_res_1288 = let_res_1291;
            }
            ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 let_res_1326;
            {
              ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 dlist1_273 { let_res_1288 };
              ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 letpair_res_1327;
              {
                auto dlist1_fst_274 { std::get<0>(dlist1_273) };
                auto dlist1_snd_275 { std::get<1>(dlist1_273) };
                Lst<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > endoflist_1328;
                ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 id_1329 { endoflist_1328, dlist1_snd_275 };
                Vec<1, ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3> id_1330 {  id_1329  };
                ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 let_res_1331;
                {
                  Vec<1, ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3> inits_src_ref_276 { id_1330 };
                  int32_t id_1332 { 0L };
                  Vec<1, int32_t> id_1333 {  id_1332  };
                  {
                    Vec<1, int32_t> repeat_n_277 { id_1333 };
                    bool while_flag_1334 { true };
                    do {
                      int32_t id_1335 { int32_t(dlist1_fst_274) };
                      uint8_t id_1336 { 0 };
                      int32_t id_1337 { repeat_n_277[id_1336] };
                      bool id_1338 { bool(id_1335 > id_1337) };
                      while_flag_1334 = id_1338;
                      if (while_flag_1334) {
                        uint8_t id_1339 { 0 };
                        ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 id_1340 { inits_src_ref_276[id_1339] };
                        {
                          ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 dlist2_278 { id_1340 };
                          {
                            auto dlist2_fst_279 { std::get<0>(dlist2_278) };
                            auto dlist2_snd_280 { std::get<1>(dlist2_278) };
                            uint8_t id_1341 { 0 };
                            ::dessser::gen::dashboard_widget::t6ac8518a7138f46f9eb6363b25e26552 id_1342 { axis_of_row_binary(dlist2_snd_280) };
                            ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 letpair_res_1343;
                            {
                              auto dlist3_fst_282 { std::get<0>(id_1342) };
                              auto dlist3_snd_283 { std::get<1>(id_1342) };
                              Lst<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_1344 { dlist3_fst_282, dlist2_fst_279 };
                              ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 id_1345 { id_1344, dlist3_snd_283 };
                              letpair_res_1343 = id_1345;
                            }
                            Void id_1346 { ((void)(inits_src_ref_276[id_1341] = letpair_res_1343), ::dessser::VOID) };
                            (void)id_1346;
                          }
                          (void)::dessser::VOID;
                        }
                        (void)::dessser::VOID;
                        uint8_t id_1347 { 0 };
                        uint8_t id_1348 { 0 };
                        int32_t id_1349 { repeat_n_277[id_1348] };
                        int32_t id_1350 { 1L };
                        int32_t id_1351 { int32_t(id_1349 + id_1350) };
                        Void id_1352 { ((void)(repeat_n_277[id_1347] = id_1351), ::dessser::VOID) };
                        (void)id_1352;
                        (void)id_1352;
                      }
                    } while (while_flag_1334);
                    (void)::dessser::VOID;
                  }
                  (void)::dessser::VOID;
                  uint8_t id_1353 { 0 };
                  ::dessser::gen::dashboard_widget::t589749b27ef8c95365b7c84b8d0c65b3 id_1354 { inits_src_ref_276[id_1353] };
                  let_res_1331 = id_1354;
                }
                letpair_res_1327 = let_res_1331;
              }
              let_res_1326 = letpair_res_1327;
            }
            ::dessser::gen::dashboard_widget::tb55c7f64967782dbcd42b37a9d7d6eed letpair_res_1355;
            {
              auto dlist4_fst_285 { std::get<0>(let_res_1326) };
              auto dlist4_snd_286 { std::get<1>(let_res_1326) };
              Arr<std::shared_ptr<::dessser::gen::dashboard_widget::axis> > id_1356 { dlist4_fst_285.toListRev() };
              ::dessser::gen::dashboard_widget::tb55c7f64967782dbcd42b37a9d7d6eed id_1357 { id_1356, dlist4_snd_286 };
              letpair_res_1355 = id_1357;
            }
            ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 let_res_1358;
            {
              ::dessser::gen::dashboard_widget::tb55c7f64967782dbcd42b37a9d7d6eed drec_287 { letpair_res_1355 };
              ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 letpair_res_1359;
              {
                auto drec_fst_288 { std::get<0>(drec_287) };
                auto drec_snd_289 { std::get<1>(drec_287) };
                uint32_t id_1360 { 0U };
                Vec<1, uint32_t> id_1361 {  id_1360  };
                ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1362;
                {
                  Vec<1, uint32_t> leb_ref_290 { id_1361 };
                  uint8_t id_1363 { 0 };
                  Vec<1, uint8_t> id_1364 {  id_1363  };
                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1365;
                  {
                    Vec<1, uint8_t> shft_ref_291 { id_1364 };
                    Vec<1, Pointer> id_1366 {  drec_snd_289  };
                    ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 let_res_1367;
                    {
                      Vec<1, Pointer> p_ref_292 { id_1366 };
                      bool while_flag_1368 { true };
                      do {
                        uint8_t id_1369 { 0 };
                        Pointer id_1370 { p_ref_292[id_1369] };
                        ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1371 { id_1370.readU8() };
                        bool let_res_1372;
                        {
                          ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_293 { id_1371 };
                          bool letpair_res_1373;
                          {
                            auto leb128_fst_294 { std::get<0>(leb128_293) };
                            auto leb128_snd_295 { std::get<1>(leb128_293) };
                            uint8_t id_1374 { 0 };
                            Void id_1375 { ((void)(p_ref_292[id_1374] = leb128_snd_295), ::dessser::VOID) };
                            (void)id_1375;
                            uint8_t id_1376 { 0 };
                            uint8_t id_1377 { 127 };
                            uint8_t id_1378 { uint8_t(leb128_fst_294 & id_1377) };
                            uint32_t id_1379 { uint32_t(id_1378) };
                            uint8_t id_1380 { 0 };
                            uint8_t id_1381 { shft_ref_291[id_1380] };
                            uint32_t id_1382 { uint32_t(id_1379 << id_1381) };
                            uint8_t id_1383 { 0 };
                            uint32_t id_1384 { leb_ref_290[id_1383] };
                            uint32_t id_1385 { uint32_t(id_1382 | id_1384) };
                            Void id_1386 { ((void)(leb_ref_290[id_1376] = id_1385), ::dessser::VOID) };
                            (void)id_1386;
                            uint8_t id_1387 { 0 };
                            uint8_t id_1388 { 0 };
                            uint8_t id_1389 { shft_ref_291[id_1388] };
                            uint8_t id_1390 { 7 };
                            uint8_t id_1391 { uint8_t(id_1389 + id_1390) };
                            Void id_1392 { ((void)(shft_ref_291[id_1387] = id_1391), ::dessser::VOID) };
                            (void)id_1392;
                            uint8_t id_1393 { 128 };
                            bool id_1394 { bool(leb128_fst_294 >= id_1393) };
                            letpair_res_1373 = id_1394;
                          }
                          let_res_1372 = letpair_res_1373;
                        }
                        while_flag_1368 = let_res_1372;
                        if (while_flag_1368) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_1368);
                      (void)::dessser::VOID;
                      uint8_t id_1395 { 0 };
                      uint32_t id_1396 { leb_ref_290[id_1395] };
                      uint8_t id_1397 { 0 };
                      Pointer id_1398 { p_ref_292[id_1397] };
                      ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 id_1399 { id_1396, id_1398 };
                      let_res_1367 = id_1399;
                    }
                    let_res_1365 = let_res_1367;
                  }
                  let_res_1362 = let_res_1365;
                }
                ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 let_res_1400;
                {
                  ::dessser::gen::dashboard_widget::t883c6ffea47c0d7b950fe35881e3d737 dlist1_299 { let_res_1362 };
                  ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 letpair_res_1401;
                  {
                    auto dlist1_fst_300 { std::get<0>(dlist1_299) };
                    auto dlist1_snd_301 { std::get<1>(dlist1_299) };
                    Lst<std::shared_ptr<::dessser::gen::dashboard_widget::source> > endoflist_1402;
                    ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 id_1403 { endoflist_1402, dlist1_snd_301 };
                    Vec<1, ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569> id_1404 {  id_1403  };
                    ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 let_res_1405;
                    {
                      Vec<1, ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569> inits_src_ref_302 { id_1404 };
                      int32_t id_1406 { 0L };
                      Vec<1, int32_t> id_1407 {  id_1406  };
                      {
                        Vec<1, int32_t> repeat_n_303 { id_1407 };
                        bool while_flag_1408 { true };
                        do {
                          int32_t id_1409 { int32_t(dlist1_fst_300) };
                          uint8_t id_1410 { 0 };
                          int32_t id_1411 { repeat_n_303[id_1410] };
                          bool id_1412 { bool(id_1409 > id_1411) };
                          while_flag_1408 = id_1412;
                          if (while_flag_1408) {
                            uint8_t id_1413 { 0 };
                            ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 id_1414 { inits_src_ref_302[id_1413] };
                            {
                              ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 dlist2_304 { id_1414 };
                              {
                                auto dlist2_fst_305 { std::get<0>(dlist2_304) };
                                auto dlist2_snd_306 { std::get<1>(dlist2_304) };
                                uint8_t id_1415 { 0 };
                                ::dessser::gen::dashboard_widget::t97cba01e43a21515748b36fb32be3b3e id_1416 { source_of_row_binary(dlist2_snd_306) };
                                ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 letpair_res_1417;
                                {
                                  auto dlist3_fst_308 { std::get<0>(id_1416) };
                                  auto dlist3_snd_309 { std::get<1>(id_1416) };
                                  Lst<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_1418 { dlist3_fst_308, dlist2_fst_305 };
                                  ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 id_1419 { id_1418, dlist3_snd_309 };
                                  letpair_res_1417 = id_1419;
                                }
                                Void id_1420 { ((void)(inits_src_ref_302[id_1415] = letpair_res_1417), ::dessser::VOID) };
                                (void)id_1420;
                              }
                              (void)::dessser::VOID;
                            }
                            (void)::dessser::VOID;
                            uint8_t id_1421 { 0 };
                            uint8_t id_1422 { 0 };
                            int32_t id_1423 { repeat_n_303[id_1422] };
                            int32_t id_1424 { 1L };
                            int32_t id_1425 { int32_t(id_1423 + id_1424) };
                            Void id_1426 { ((void)(repeat_n_303[id_1421] = id_1425), ::dessser::VOID) };
                            (void)id_1426;
                            (void)id_1426;
                          }
                        } while (while_flag_1408);
                        (void)::dessser::VOID;
                      }
                      (void)::dessser::VOID;
                      uint8_t id_1427 { 0 };
                      ::dessser::gen::dashboard_widget::ta2a89e8ea0837477e804ea533f6f5569 id_1428 { inits_src_ref_302[id_1427] };
                      let_res_1405 = id_1428;
                    }
                    letpair_res_1401 = let_res_1405;
                  }
                  let_res_1400 = letpair_res_1401;
                }
                ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 letpair_res_1429;
                {
                  auto dlist4_fst_311 { std::get<0>(let_res_1400) };
                  auto dlist4_snd_312 { std::get<1>(let_res_1400) };
                  Arr<std::shared_ptr<::dessser::gen::dashboard_widget::source> > id_1430 { dlist4_fst_311.toListRev() };
                  std::shared_ptr<::dessser::gen::dashboard_widget::chart>  id_1431 { std::make_shared<::dessser::gen::dashboard_widget::chart>(drec_fst_288, id_1430, drec_fst_259, drec_fst_262) };
                  ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 id_1432 { id_1431, dlist4_snd_312 };
                  letpair_res_1429 = id_1432;
                }
                letpair_res_1359 = letpair_res_1429;
              }
              let_res_1358 = letpair_res_1359;
            }
            letpair_res_1285 = let_res_1358;
          }
          let_res_1284 = letpair_res_1285;
        }
        letpair_res_1282 = let_res_1284;
      }
      let_res_1281 = letpair_res_1282;
    }
    return let_res_1281;
  }
   };
  return fun1233;
}
std::function<::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70(Pointer)> chart_of_row_binary(chart_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_347" "make_snd_348"
        (let "dsum1_325" (let-pair "du16_fst_320" "du16_snd_321" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_320") (identifier "du16_snd_321")))
          (let-pair "dsum1_fst_326" "dsum1_snd_327" (identifier "dsum1_325")
            (if (eq (u16 0) (identifier "dsum1_fst_326"))
              (let "dstring1_337"
                (let "leb_ref_331" (make-vec (u32 0))
                  (let "shft_ref_332" (make-vec (u8 0))
                    (let "p_ref_333" (make-vec (identifier "dsum1_snd_327"))
                      (seq
                        (while
                          (let "leb128_334" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_333")))
                            (let-pair "leb128_fst_335" "leb128_snd_336" 
                              (identifier "leb128_334")
                              (seq (set-vec (u8 0) (identifier "p_ref_333") (identifier "leb128_snd_336"))
                                (set-vec (u8 0) (identifier "leb_ref_331")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_335") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_332"))) (unsafe-nth (u8 0) (identifier "leb_ref_331"))))
                                (set-vec (u8 0) (identifier "shft_ref_332") (add (unsafe-nth (u8 0) (identifier "shft_ref_332")) (u8 7))) 
                                (ge (identifier "leb128_fst_335") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_331"))) (unsafe-nth (u8 0) (identifier "p_ref_333")))))))
                (let-pair "dstring1_fst_338" "dstring1_snd_339" (identifier "dstring1_337")
                  (let-pair "dstring2_fst_341" "dstring2_snd_342" (read-bytes (identifier "dstring1_snd_339") (identifier "dstring1_fst_338"))
                    (make-tup
                      (construct "[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]})]" 0
                        (string-of-bytes (identifier "dstring2_fst_341"))) 
                      (identifier "dstring2_snd_342")))))
              (seq (assert (eq (identifier "dsum1_fst_326") (u16 1)))
                (let-pair "dsum2_fst_329" "dsum2_snd_330" (apply (identifier "chart-of-row-binary") (identifier "dsum1_snd_327"))
                  (make-tup
                    (construct "[Text STRING | Chart (chart AS {title: STRING; type: (type AS [Plot Void]); axes: (axis AS {left: BOOL; force_zero: BOOL; scale: (scale AS [Linear Void | Logarithmic Void])})[]; sources: (source AS {name: $fq_function_name; visible: BOOL; fields: (field AS {opacity: FLOAT; color: U32; representation: (representation AS [Unused Void | Independent Void | Stacked Void | StackCentered Void]); column: STRING; factors: STRING[]; axis: U8})[]})[]})]" 1
                      (identifier "dsum2_fst_329")) (identifier "dsum2_snd_330"))))))) 
        (make-tup (identifier "make_fst_347") (identifier "make_snd_348"))))
 */
static std::function<::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939(Pointer)> fun1433 { [&fun1433](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1434 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1435;
    {
      auto du16_fst_320 { std::get<0>(id_1434) };
      auto du16_snd_321 { std::get<1>(id_1434) };
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b id_1436 { du16_fst_320, du16_snd_321 };
      letpair_res_1435 = id_1436;
    }
    ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 let_res_1437;
    {
      ::dessser::gen::dashboard_widget::t7609d344c1ba69d0f80fec236d4c216b dsum1_325 { letpair_res_1435 };
      ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1438;
      {
        auto dsum1_fst_326 { std::get<0>(dsum1_325) };
        auto dsum1_snd_327 { std::get<1>(dsum1_325) };
        uint16_t id_1439 { 0 };
        bool id_1440 { bool(id_1439 == dsum1_fst_326) };
        ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 choose_res_1441;
        if (id_1440) {
          uint32_t id_1442 { 0U };
          Vec<1, uint32_t> id_1443 {  id_1442  };
          ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1444;
          {
            Vec<1, uint32_t> leb_ref_331 { id_1443 };
            uint8_t id_1445 { 0 };
            Vec<1, uint8_t> id_1446 {  id_1445  };
            ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1447;
            {
              Vec<1, uint8_t> shft_ref_332 { id_1446 };
              Vec<1, Pointer> id_1448 {  dsum1_snd_327  };
              ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 let_res_1449;
              {
                Vec<1, Pointer> p_ref_333 { id_1448 };
                bool while_flag_1450 { true };
                do {
                  uint8_t id_1451 { 0 };
                  Pointer id_1452 { p_ref_333[id_1451] };
                  ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 id_1453 { id_1452.readU8() };
                  bool let_res_1454;
                  {
                    ::dessser::gen::dashboard_widget::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_334 { id_1453 };
                    bool letpair_res_1455;
                    {
                      auto leb128_fst_335 { std::get<0>(leb128_334) };
                      auto leb128_snd_336 { std::get<1>(leb128_334) };
                      uint8_t id_1456 { 0 };
                      Void id_1457 { ((void)(p_ref_333[id_1456] = leb128_snd_336), ::dessser::VOID) };
                      (void)id_1457;
                      uint8_t id_1458 { 0 };
                      uint8_t id_1459 { 127 };
                      uint8_t id_1460 { uint8_t(leb128_fst_335 & id_1459) };
                      uint32_t id_1461 { uint32_t(id_1460) };
                      uint8_t id_1462 { 0 };
                      uint8_t id_1463 { shft_ref_332[id_1462] };
                      uint32_t id_1464 { uint32_t(id_1461 << id_1463) };
                      uint8_t id_1465 { 0 };
                      uint32_t id_1466 { leb_ref_331[id_1465] };
                      uint32_t id_1467 { uint32_t(id_1464 | id_1466) };
                      Void id_1468 { ((void)(leb_ref_331[id_1458] = id_1467), ::dessser::VOID) };
                      (void)id_1468;
                      uint8_t id_1469 { 0 };
                      uint8_t id_1470 { 0 };
                      uint8_t id_1471 { shft_ref_332[id_1470] };
                      uint8_t id_1472 { 7 };
                      uint8_t id_1473 { uint8_t(id_1471 + id_1472) };
                      Void id_1474 { ((void)(shft_ref_332[id_1469] = id_1473), ::dessser::VOID) };
                      (void)id_1474;
                      uint8_t id_1475 { 128 };
                      bool id_1476 { bool(leb128_fst_335 >= id_1475) };
                      letpair_res_1455 = id_1476;
                    }
                    let_res_1454 = letpair_res_1455;
                  }
                  while_flag_1450 = let_res_1454;
                  if (while_flag_1450) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_1450);
                (void)::dessser::VOID;
                uint8_t id_1477 { 0 };
                uint32_t id_1478 { leb_ref_331[id_1477] };
                Size id_1479 { Size(id_1478) };
                uint8_t id_1480 { 0 };
                Pointer id_1481 { p_ref_333[id_1480] };
                ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 id_1482 { id_1479, id_1481 };
                let_res_1449 = id_1482;
              }
              let_res_1447 = let_res_1449;
            }
            let_res_1444 = let_res_1447;
          }
          ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 let_res_1483;
          {
            ::dessser::gen::dashboard_widget::t044960e524fd6ec1bfc06410ce526709 dstring1_337 { let_res_1444 };
            ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1484;
            {
              auto dstring1_fst_338 { std::get<0>(dstring1_337) };
              auto dstring1_snd_339 { std::get<1>(dstring1_337) };
              ::dessser::gen::dashboard_widget::t5887709cc43c8c8e24d28211e8c970a2 id_1485 { dstring1_snd_339.readBytes(dstring1_fst_338) };
              ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1486;
              {
                auto dstring2_fst_341 { std::get<0>(id_1485) };
                auto dstring2_snd_342 { std::get<1>(id_1485) };
                std::string id_1487 { dstring2_fst_341.toString() };
                std::shared_ptr<::dessser::gen::dashboard_widget::t>  id_1488 { std::make_shared<::dessser::gen::dashboard_widget::t>(std::in_place_index<0>, id_1487) };
                ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 id_1489 { id_1488, dstring2_snd_342 };
                letpair_res_1486 = id_1489;
              }
              letpair_res_1484 = letpair_res_1486;
            }
            let_res_1483 = letpair_res_1484;
          }
          choose_res_1441 = let_res_1483;
        } else {
          uint16_t id_1490 { 1 };
          bool id_1491 { bool(dsum1_fst_326 == id_1490) };
          Void id_1492 { ((void)(assert(id_1491)), ::dessser::VOID) };
          (void)id_1492;
          ::dessser::gen::dashboard_widget::tef7a76372bf1c1fa490f519ad932fc70 id_1493 { chart_of_row_binary(dsum1_snd_327) };
          ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1494;
          {
            auto dsum2_fst_329 { std::get<0>(id_1493) };
            auto dsum2_snd_330 { std::get<1>(id_1493) };
            std::shared_ptr<::dessser::gen::dashboard_widget::t>  id_1495 { std::make_shared<::dessser::gen::dashboard_widget::t>(std::in_place_index<1>, dsum2_fst_329) };
            ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 id_1496 { id_1495, dsum2_snd_330 };
            letpair_res_1494 = id_1496;
          }
          choose_res_1441 = letpair_res_1494;
        }
        letpair_res_1438 = choose_res_1441;
      }
      let_res_1437 = letpair_res_1438;
    }
    ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 letpair_res_1497;
    {
      auto make_fst_347 { std::get<0>(let_res_1437) };
      auto make_snd_348 { std::get<1>(let_res_1437) };
      ::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939 id_1498 { make_fst_347, make_snd_348 };
      letpair_res_1497 = id_1498;
    }
    return letpair_res_1497;
  }
   };
  return fun1433;
}
std::function<::dessser::gen::dashboard_widget::t206086bb48fe7c1f7a2a1b42bad30939(Pointer)> of_row_binary(of_row_binary_init());


}
