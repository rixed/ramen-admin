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
struct tf285c6d4be19a8e3e994b3792fed4f11 : public std::variant<
  Void, // Linear
  Void // Logarithmic
> { using variant::variant; };

struct t7a73277e81021fc63d7d1b63bc3beba6 {
  bool force_zero;
  bool left;
  ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 scale;
  t7a73277e81021fc63d7d1b63bc3beba6(bool force_zero_, bool left_, ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 scale_) : force_zero(force_zero_), left(left_), scale(scale_) {}
  t7a73277e81021fc63d7d1b63bc3beba6() = default;
};
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
struct t79826a59cc1e8c45c3ad94e8417c3225 {
  Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> fields;
  dessser::gen::fq_function_name::t_ext name;
  bool visible;
  t79826a59cc1e8c45c3ad94e8417c3225(Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> fields_, dessser::gen::fq_function_name::t_ext name_, bool visible_) : fields(fields_), name(name_), visible(visible_) {}
  t79826a59cc1e8c45c3ad94e8417c3225() = default;
};
struct t3ef59f16a0cdd3a9e330e7c5bf93b091 : public std::variant<
  Void // Plot
> { using variant::variant; };

struct ta3280375be63ffe37d86976d93bf0304 {
  Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> Chart_axis;
  Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> sources;
  std::string title;
  ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 type;
  ta3280375be63ffe37d86976d93bf0304(Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> Chart_axis_, Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> sources_, std::string title_, ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 type_) : Chart_axis(Chart_axis_), sources(sources_), title(title_), type(type_) {}
  ta3280375be63ffe37d86976d93bf0304() = default;
};
struct t : public std::variant<
  std::string, // Text
  ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 // Chart
> { using variant::variant; };

typedef std::tuple<
  ::dessser::gen::dashboard_widget::t*,
  Pointer
> t1a99c61debfb8ac5db5347b1cf1a79d1;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

typedef std::tuple<
  std::string,
  Pointer
> tef94b55d8809251f13165d9a05bd9d0e;

typedef std::tuple<
  ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091,
  Pointer
> tcf8b8a1aaccb8df8d0f0d02152cf69d9;

typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  Lst<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6>,
  Pointer
> t3784ecdaa5f49b38535148750595f444;

typedef std::tuple<
  bool,
  Pointer
> t4138de986e20d18b01e4c493dc9d5451;

typedef std::tuple<
  ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11,
  Pointer
> t18f962e0b602b25173933adabf09c5e6;

typedef std::tuple<
  Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6>,
  Pointer
> tf10289c316edef0ccee1d3f2935b6a8c;

typedef std::tuple<
  Lst<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225>,
  Pointer
> t53474d2cd1155389586730a26f802ec7;

typedef std::tuple<
  dessser::gen::fq_function_name::t_ext,
  Pointer
> taa97936972d3c557dfc41dd27d2203f0;

typedef std::tuple<
  Lst<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82>,
  Pointer
> ta52af46a94c77315ad8bf6f31a04f827;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

typedef std::tuple<
  double,
  Pointer
> taebed00ad7fdb3f7ced11d3cfd58aade;

typedef std::tuple<
  ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704,
  Pointer
> t456f791d00acb0124553dcfd0d592389;

typedef std::tuple<
  Lst<std::string>,
  Pointer
> ta48cca69b6e077e610d35192824cedc1;

typedef std::tuple<
  Arr<std::string>,
  Pointer
> t1beb4adb76e17aefcfb1b276e44e61db;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Text STRING | Chart {title: STRING; type: [Plot Void]; axis: {left: BOOL; force_zero: BOOL; scale: [Linear Void | Logarithmic Void]}[]; sources: {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]}[]}]" "Ptr")
      (let "ssum_dst_377" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_425" (make-vec (string-length (get-alt "Text" (param 0))))
              (let "leb128_ptr_426" (make-vec (identifier "ssum_dst_377"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_426")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_426"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_425"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_425"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_425"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_425") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_425")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_425")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_426"))))) 
            (bytes-of-string (get-alt "Text" (param 0))))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "srec_dst_394"
              (let "srec_dst_383"
                (let "srec_dst_380"
                  (write-bytes
                    (let "leb128_sz_378" (make-vec (string-length (get-field "title" (get-alt "Chart" (param 0)))))
                      (let "leb128_ptr_379" (make-vec (identifier "ssum_dst_377"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_379")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_379"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_378"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_378"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_378"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_378") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_378")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_378")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_379"))))) 
                    (bytes-of-string (get-field "title" (get-alt "Chart" (param 0)))))
                  (let "ssum_dst_382" (write-u16 little-endian (identifier "srec_dst_380") (label-of (get-field "type" (get-alt "Chart" (param 0)))))
                    (seq (assert (eq (label-of (get-field "type" (get-alt "Chart" (param 0)))) (u16 0))) (identifier "ssum_dst_382"))))
                (let "dst_ref_386"
                  (make-vec
                    (let "leb128_sz_384" (make-vec (cardinality (get-field "axis" (get-alt "Chart" (param 0)))))
                      (let "leb128_ptr_385" (make-vec (identifier "srec_dst_383"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_385")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_385"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_384"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_384"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_384"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_384") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_384")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_384")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_385"))))))
                  (let "n_ref_387" (make-vec (i32 0))
                    (seq
                      (for-each "x_388" (get-field "axis" (get-alt "Chart" (param 0)))
                        (seq
                          (set-vec (u8 0) (identifier "dst_ref_386")
                            (let "srec_dst_391"
                              (let "srec_dst_390" (let "srec_dst_389" (unsafe-nth (u8 0) (identifier "dst_ref_386")) (write-u8 (identifier "srec_dst_389") (u8-of-bool (get-field "left" (identifier "x_388")))))
                                (write-u8 (identifier "srec_dst_390") (u8-of-bool (get-field "force_zero" (identifier "x_388")))))
                              (let "ssum_dst_393" (write-u16 little-endian (identifier "srec_dst_391") (label-of (get-field "scale" (identifier "x_388"))))
                                (if (eq (u16 0) (label-of (get-field "scale" (identifier "x_388")))) 
                                  (identifier "ssum_dst_393") (seq (assert (eq (label-of (get-field "scale" (identifier "x_388"))) (u16 1))) (identifier "ssum_dst_393"))))))
                          (set-vec (u8 0) (identifier "n_ref_387") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_387")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_386"))))))
              (let "dst_ref_397"
                (make-vec
                  (let "leb128_sz_395" (make-vec (cardinality (get-field "sources" (get-alt "Chart" (param 0)))))
                    (let "leb128_ptr_396" (make-vec (identifier "srec_dst_394"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_396")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_396"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_395"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_395"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_395"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_395") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_395")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_395")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_396"))))))
                (let "n_ref_398" (make-vec (i32 0))
                  (seq
                    (for-each "x_399" (get-field "sources" (get-alt "Chart" (param 0)))
                      (seq
                        (set-vec (u8 0) (identifier "dst_ref_397")
                          (let "srec_dst_402"
                            (let "srec_dst_401"
                              (let "srec_dst_400" (unsafe-nth (u8 0) (identifier "dst_ref_397")) (apply (ext-identifier fq_function_name to-row-binary) (get-field "name" (identifier "x_399")) (identifier "srec_dst_400")))
                              (write-u8 (identifier "srec_dst_401") (u8-of-bool (get-field "visible" (identifier "x_399")))))
                            (let "dst_ref_405"
                              (make-vec
                                (let "leb128_sz_403" (make-vec (cardinality (get-field "fields" (identifier "x_399"))))
                                  (let "leb128_ptr_404" (make-vec (identifier "srec_dst_402"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_404")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_404"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_403"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_403"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_403"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_403") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_403")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_403")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_404"))))))
                              (let "n_ref_406" (make-vec (i32 0))
                                (seq
                                  (for-each "x_407" (get-field "fields" (identifier "x_399"))
                                    (seq
                                      (set-vec (u8 0) (identifier "dst_ref_405")
                                        (let "srec_dst_424"
                                          (let "srec_dst_416"
                                            (let "srec_dst_413"
                                              (let "srec_dst_410"
                                                (let "srec_dst_409"
                                                  (let "srec_dst_408" (unsafe-nth (u8 0) (identifier "dst_ref_405")) (write-u64 little-endian (identifier "srec_dst_408") (u64-of-float (get-field "opacity" (identifier "x_407")))))
                                                  (write-u32 little-endian (identifier "srec_dst_409") (get-field "color" (identifier "x_407"))))
                                                (let "ssum_dst_412" (write-u16 little-endian (identifier "srec_dst_410") (label-of (get-field "representation" (identifier "x_407"))))
                                                  (if (eq (u16 0) (label-of (get-field "representation" (identifier "x_407")))) 
                                                    (identifier "ssum_dst_412")
                                                    (if (eq (u16 1) (label-of (get-field "representation" (identifier "x_407")))) 
                                                      (identifier "ssum_dst_412")
                                                      (if (eq (u16 2) (label-of (get-field "representation" (identifier "x_407")))) 
                                                        (identifier "ssum_dst_412") 
                                                        (seq (assert (eq (label-of (get-field "representation" (identifier "x_407"))) (u16 3))) (identifier "ssum_dst_412")))))))
                                              (write-bytes
                                                (let "leb128_sz_414" 
                                                  (make-vec (string-length (get-field "column" (identifier "x_407"))))
                                                  (let "leb128_ptr_415" 
                                                    (make-vec (identifier "srec_dst_413"))
                                                    (seq
                                                      (while
                                                        (seq
                                                          (set-vec (u8 0) 
                                                            (identifier "leb128_ptr_415")
                                                            (write-u8 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_415"))
                                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_414"))) 
                                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_414"))) 
                                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_414"))) (u8 128)))))
                                                          (set-vec (u8 0) (identifier "leb128_sz_414") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_414")) (u8 7)))
                                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_414")) (u32 0))) 
                                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_415"))))) 
                                                (bytes-of-string (get-field "column" (identifier "x_407")))))
                                            (let "dst_ref_419"
                                              (make-vec
                                                (let "leb128_sz_417" 
                                                  (make-vec (cardinality (get-field "factors" (identifier "x_407"))))
                                                  (let "leb128_ptr_418" 
                                                    (make-vec (identifier "srec_dst_416"))
                                                    (seq
                                                      (while
                                                        (seq
                                                          (set-vec (u8 0) 
                                                            (identifier "leb128_ptr_418")
                                                            (write-u8 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_418"))
                                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_417"))) 
                                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_417"))) 
                                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_417"))) (u8 128)))))
                                                          (set-vec (u8 0) (identifier "leb128_sz_417") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_417")) (u8 7)))
                                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_417")) (u32 0))) 
                                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_418"))))))
                                              (let "n_ref_420" (make-vec (i32 0))
                                                (seq
                                                  (for-each "x_421" (get-field "factors" (identifier "x_407"))
                                                    (seq
                                                      (set-vec (u8 0) 
                                                        (identifier "dst_ref_419")
                                                        (write-bytes
                                                          (let "leb128_sz_422" 
                                                            (make-vec (string-length (identifier "x_421")))
                                                            (let "leb128_ptr_423" 
                                                              (make-vec (unsafe-nth (u8 0) (identifier "dst_ref_419")))
                                                              (seq
                                                                (while
                                                                  (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_423")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_423"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_422"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_422"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_422"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_422") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_422")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_422")) (u32 0))) 
                                                                  (nop)) 
                                                                (unsafe-nth (u8 0) (identifier "leb128_ptr_423"))))) 
                                                          (bytes-of-string (identifier "x_421")))) 
                                                      (set-vec (u8 0) (identifier "n_ref_420") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_420")))))) 
                                                  (unsafe-nth (u8 0) (identifier "dst_ref_419")))))) 
                                          (write-u8 (identifier "srec_dst_424") (get-field "axis" (identifier "x_407"))))) 
                                      (set-vec (u8 0) (identifier "n_ref_406") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_406")))))) 
                                  (unsafe-nth (u8 0) (identifier "dst_ref_405"))))))) 
                        (set-vec (u8 0) (identifier "n_ref_398") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_398")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_397"))))))))))
 */
static std::function<Pointer(::dessser::gen::dashboard_widget::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::dashboard_widget::t*,Pointer)> fun0 { [&fun0](::dessser::gen::dashboard_widget::t* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_377 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        std::string id_8 { std::get<0 /* Text */>((*p_0)) };
        uint32_t id_9 { (uint32_t)id_8.size() };
        Vec<1, uint32_t> id_10 {  id_9  };
        Pointer let_res_11;
        {
          Vec<1, uint32_t> leb128_sz_425 { id_10 };
          Vec<1, Pointer> id_12 {  ssum_dst_377  };
          Pointer let_res_13;
          {
            Vec<1, Pointer> leb128_ptr_426 { id_12 };
            bool while_flag_14 { true };
            do {
              uint8_t id_15 { 0 };
              uint8_t id_16 { 0 };
              Pointer id_17 { leb128_ptr_426[id_16] };
              uint32_t id_18 { 128U };
              uint8_t id_19 { 0 };
              uint32_t id_20 { leb128_sz_425[id_19] };
              bool id_21 { bool(id_18 > id_20) };
              uint8_t choose_res_22;
              if (id_21) {
                uint8_t id_23 { 0 };
                uint32_t id_24 { leb128_sz_425[id_23] };
                uint8_t id_25 { uint8_t(id_24) };
                choose_res_22 = id_25;
              } else {
                uint8_t id_26 { 0 };
                uint32_t id_27 { leb128_sz_425[id_26] };
                uint8_t id_28 { uint8_t(id_27) };
                uint8_t id_29 { 128 };
                uint8_t id_30 { uint8_t(id_28 | id_29) };
                choose_res_22 = id_30;
              }
              Pointer id_31 { id_17.writeU8(choose_res_22) };
              Void id_32 { ((void)(leb128_ptr_426[id_15] = id_31), VOID) };
              (void)id_32;
              uint8_t id_33 { 0 };
              uint8_t id_34 { 0 };
              uint32_t id_35 { leb128_sz_425[id_34] };
              uint8_t id_36 { 7 };
              uint32_t id_37 { uint32_t(id_35 >> id_36) };
              Void id_38 { ((void)(leb128_sz_425[id_33] = id_37), VOID) };
              (void)id_38;
              uint8_t id_39 { 0 };
              uint32_t id_40 { leb128_sz_425[id_39] };
              uint32_t id_41 { 0U };
              bool id_42 { bool(id_40 > id_41) };
              while_flag_14 = id_42;
              if (while_flag_14) {
                (void)VOID;
              }
            } while (while_flag_14);
            (void)VOID;
            uint8_t id_43 { 0 };
            Pointer id_44 { leb128_ptr_426[id_43] };
            let_res_13 = id_44;
          }
          let_res_11 = let_res_13;
        }
        std::string id_45 { std::get<0 /* Text */>((*p_0)) };
        Bytes id_46 { id_45 };
        Pointer id_47 { let_res_11.writeBytes(id_46) };
        choose_res_7 = id_47;
      } else {
        uint16_t id_48 { uint16_t((*p_0).index()) };
        uint16_t id_49 { 1 };
        bool id_50 { bool(id_48 == id_49) };
        Void id_51 { ((void)(assert(id_50)), VOID) };
        (void)id_51;
        ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_52 { std::get<1 /* Chart */>((*p_0)) };
        std::string id_53 { id_52.title };
        uint32_t id_54 { (uint32_t)id_53.size() };
        Vec<1, uint32_t> id_55 {  id_54  };
        Pointer let_res_56;
        {
          Vec<1, uint32_t> leb128_sz_378 { id_55 };
          Vec<1, Pointer> id_57 {  ssum_dst_377  };
          Pointer let_res_58;
          {
            Vec<1, Pointer> leb128_ptr_379 { id_57 };
            bool while_flag_59 { true };
            do {
              uint8_t id_60 { 0 };
              uint8_t id_61 { 0 };
              Pointer id_62 { leb128_ptr_379[id_61] };
              uint32_t id_63 { 128U };
              uint8_t id_64 { 0 };
              uint32_t id_65 { leb128_sz_378[id_64] };
              bool id_66 { bool(id_63 > id_65) };
              uint8_t choose_res_67;
              if (id_66) {
                uint8_t id_68 { 0 };
                uint32_t id_69 { leb128_sz_378[id_68] };
                uint8_t id_70 { uint8_t(id_69) };
                choose_res_67 = id_70;
              } else {
                uint8_t id_71 { 0 };
                uint32_t id_72 { leb128_sz_378[id_71] };
                uint8_t id_73 { uint8_t(id_72) };
                uint8_t id_74 { 128 };
                uint8_t id_75 { uint8_t(id_73 | id_74) };
                choose_res_67 = id_75;
              }
              Pointer id_76 { id_62.writeU8(choose_res_67) };
              Void id_77 { ((void)(leb128_ptr_379[id_60] = id_76), VOID) };
              (void)id_77;
              uint8_t id_78 { 0 };
              uint8_t id_79 { 0 };
              uint32_t id_80 { leb128_sz_378[id_79] };
              uint8_t id_81 { 7 };
              uint32_t id_82 { uint32_t(id_80 >> id_81) };
              Void id_83 { ((void)(leb128_sz_378[id_78] = id_82), VOID) };
              (void)id_83;
              uint8_t id_84 { 0 };
              uint32_t id_85 { leb128_sz_378[id_84] };
              uint32_t id_86 { 0U };
              bool id_87 { bool(id_85 > id_86) };
              while_flag_59 = id_87;
              if (while_flag_59) {
                (void)VOID;
              }
            } while (while_flag_59);
            (void)VOID;
            uint8_t id_88 { 0 };
            Pointer id_89 { leb128_ptr_379[id_88] };
            let_res_58 = id_89;
          }
          let_res_56 = let_res_58;
        }
        ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_90 { std::get<1 /* Chart */>((*p_0)) };
        std::string id_91 { id_90.title };
        Bytes id_92 { id_91 };
        Pointer id_93 { let_res_56.writeBytes(id_92) };
        Pointer let_res_94;
        {
          Pointer srec_dst_380 { id_93 };
          ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_95 { std::get<1 /* Chart */>((*p_0)) };
          ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 id_96 { id_95.type };
          uint16_t id_97 { uint16_t(id_96.index()) };
          Pointer id_98 { srec_dst_380.writeU16Le(id_97) };
          Pointer let_res_99;
          {
            Pointer ssum_dst_382 { id_98 };
            ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_100 { std::get<1 /* Chart */>((*p_0)) };
            ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 id_101 { id_100.type };
            uint16_t id_102 { uint16_t(id_101.index()) };
            uint16_t id_103 { 0 };
            bool id_104 { bool(id_102 == id_103) };
            Void id_105 { ((void)(assert(id_104)), VOID) };
            (void)id_105;
            let_res_99 = ssum_dst_382;
          }
          let_res_94 = let_res_99;
        }
        Pointer let_res_106;
        {
          Pointer srec_dst_383 { let_res_94 };
          ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_107 { std::get<1 /* Chart */>((*p_0)) };
          Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> id_108 { id_107.Chart_axis };
          uint32_t id_109 { id_108.size() };
          Vec<1, uint32_t> id_110 {  id_109  };
          Pointer let_res_111;
          {
            Vec<1, uint32_t> leb128_sz_384 { id_110 };
            Vec<1, Pointer> id_112 {  srec_dst_383  };
            Pointer let_res_113;
            {
              Vec<1, Pointer> leb128_ptr_385 { id_112 };
              bool while_flag_114 { true };
              do {
                uint8_t id_115 { 0 };
                uint8_t id_116 { 0 };
                Pointer id_117 { leb128_ptr_385[id_116] };
                uint32_t id_118 { 128U };
                uint8_t id_119 { 0 };
                uint32_t id_120 { leb128_sz_384[id_119] };
                bool id_121 { bool(id_118 > id_120) };
                uint8_t choose_res_122;
                if (id_121) {
                  uint8_t id_123 { 0 };
                  uint32_t id_124 { leb128_sz_384[id_123] };
                  uint8_t id_125 { uint8_t(id_124) };
                  choose_res_122 = id_125;
                } else {
                  uint8_t id_126 { 0 };
                  uint32_t id_127 { leb128_sz_384[id_126] };
                  uint8_t id_128 { uint8_t(id_127) };
                  uint8_t id_129 { 128 };
                  uint8_t id_130 { uint8_t(id_128 | id_129) };
                  choose_res_122 = id_130;
                }
                Pointer id_131 { id_117.writeU8(choose_res_122) };
                Void id_132 { ((void)(leb128_ptr_385[id_115] = id_131), VOID) };
                (void)id_132;
                uint8_t id_133 { 0 };
                uint8_t id_134 { 0 };
                uint32_t id_135 { leb128_sz_384[id_134] };
                uint8_t id_136 { 7 };
                uint32_t id_137 { uint32_t(id_135 >> id_136) };
                Void id_138 { ((void)(leb128_sz_384[id_133] = id_137), VOID) };
                (void)id_138;
                uint8_t id_139 { 0 };
                uint32_t id_140 { leb128_sz_384[id_139] };
                uint32_t id_141 { 0U };
                bool id_142 { bool(id_140 > id_141) };
                while_flag_114 = id_142;
                if (while_flag_114) {
                  (void)VOID;
                }
              } while (while_flag_114);
              (void)VOID;
              uint8_t id_143 { 0 };
              Pointer id_144 { leb128_ptr_385[id_143] };
              let_res_113 = id_144;
            }
            let_res_111 = let_res_113;
          }
          Vec<1, Pointer> id_145 {  let_res_111  };
          Pointer let_res_146;
          {
            Vec<1, Pointer> dst_ref_386 { id_145 };
            int32_t id_147 { 0L };
            Vec<1, int32_t> id_148 {  id_147  };
            Pointer let_res_149;
            {
              Vec<1, int32_t> n_ref_387 { id_148 };
              ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_150 { std::get<1 /* Chart */>((*p_0)) };
              Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> id_151 { id_150.Chart_axis };
              for (::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6 x_388 : id_151) {
                uint8_t id_152 { 0 };
                uint8_t id_153 { 0 };
                Pointer id_154 { dst_ref_386[id_153] };
                Pointer let_res_155;
                {
                  Pointer srec_dst_389 { id_154 };
                  bool id_156 { x_388.left };
                  uint8_t id_157 { uint8_t(id_156) };
                  Pointer id_158 { srec_dst_389.writeU8(id_157) };
                  let_res_155 = id_158;
                }
                Pointer let_res_159;
                {
                  Pointer srec_dst_390 { let_res_155 };
                  bool id_160 { x_388.force_zero };
                  uint8_t id_161 { uint8_t(id_160) };
                  Pointer id_162 { srec_dst_390.writeU8(id_161) };
                  let_res_159 = id_162;
                }
                Pointer let_res_163;
                {
                  Pointer srec_dst_391 { let_res_159 };
                  ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 id_164 { x_388.scale };
                  uint16_t id_165 { uint16_t(id_164.index()) };
                  Pointer id_166 { srec_dst_391.writeU16Le(id_165) };
                  Pointer let_res_167;
                  {
                    Pointer ssum_dst_393 { id_166 };
                    uint16_t id_168 { 0 };
                    ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 id_169 { x_388.scale };
                    uint16_t id_170 { uint16_t(id_169.index()) };
                    bool id_171 { bool(id_168 == id_170) };
                    Pointer choose_res_172;
                    if (id_171) {
                      choose_res_172 = ssum_dst_393;
                    } else {
                      ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 id_173 { x_388.scale };
                      uint16_t id_174 { uint16_t(id_173.index()) };
                      uint16_t id_175 { 1 };
                      bool id_176 { bool(id_174 == id_175) };
                      Void id_177 { ((void)(assert(id_176)), VOID) };
                      (void)id_177;
                      choose_res_172 = ssum_dst_393;
                    }
                    let_res_167 = choose_res_172;
                  }
                  let_res_163 = let_res_167;
                }
                Void id_178 { ((void)(dst_ref_386[id_152] = let_res_163), VOID) };
                (void)id_178;
                uint8_t id_179 { 0 };
                int32_t id_180 { 1L };
                uint8_t id_181 { 0 };
                int32_t id_182 { n_ref_387[id_181] };
                int32_t id_183 { int32_t(id_180 + id_182) };
                Void id_184 { ((void)(n_ref_387[id_179] = id_183), VOID) };
                (void)id_184;
                (void)id_184;
              }
              (void)VOID;
              uint8_t id_185 { 0 };
              Pointer id_186 { dst_ref_386[id_185] };
              let_res_149 = id_186;
            }
            let_res_146 = let_res_149;
          }
          let_res_106 = let_res_146;
        }
        Pointer let_res_187;
        {
          Pointer srec_dst_394 { let_res_106 };
          ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_188 { std::get<1 /* Chart */>((*p_0)) };
          Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_189 { id_188.sources };
          uint32_t id_190 { id_189.size() };
          Vec<1, uint32_t> id_191 {  id_190  };
          Pointer let_res_192;
          {
            Vec<1, uint32_t> leb128_sz_395 { id_191 };
            Vec<1, Pointer> id_193 {  srec_dst_394  };
            Pointer let_res_194;
            {
              Vec<1, Pointer> leb128_ptr_396 { id_193 };
              bool while_flag_195 { true };
              do {
                uint8_t id_196 { 0 };
                uint8_t id_197 { 0 };
                Pointer id_198 { leb128_ptr_396[id_197] };
                uint32_t id_199 { 128U };
                uint8_t id_200 { 0 };
                uint32_t id_201 { leb128_sz_395[id_200] };
                bool id_202 { bool(id_199 > id_201) };
                uint8_t choose_res_203;
                if (id_202) {
                  uint8_t id_204 { 0 };
                  uint32_t id_205 { leb128_sz_395[id_204] };
                  uint8_t id_206 { uint8_t(id_205) };
                  choose_res_203 = id_206;
                } else {
                  uint8_t id_207 { 0 };
                  uint32_t id_208 { leb128_sz_395[id_207] };
                  uint8_t id_209 { uint8_t(id_208) };
                  uint8_t id_210 { 128 };
                  uint8_t id_211 { uint8_t(id_209 | id_210) };
                  choose_res_203 = id_211;
                }
                Pointer id_212 { id_198.writeU8(choose_res_203) };
                Void id_213 { ((void)(leb128_ptr_396[id_196] = id_212), VOID) };
                (void)id_213;
                uint8_t id_214 { 0 };
                uint8_t id_215 { 0 };
                uint32_t id_216 { leb128_sz_395[id_215] };
                uint8_t id_217 { 7 };
                uint32_t id_218 { uint32_t(id_216 >> id_217) };
                Void id_219 { ((void)(leb128_sz_395[id_214] = id_218), VOID) };
                (void)id_219;
                uint8_t id_220 { 0 };
                uint32_t id_221 { leb128_sz_395[id_220] };
                uint32_t id_222 { 0U };
                bool id_223 { bool(id_221 > id_222) };
                while_flag_195 = id_223;
                if (while_flag_195) {
                  (void)VOID;
                }
              } while (while_flag_195);
              (void)VOID;
              uint8_t id_224 { 0 };
              Pointer id_225 { leb128_ptr_396[id_224] };
              let_res_194 = id_225;
            }
            let_res_192 = let_res_194;
          }
          Vec<1, Pointer> id_226 {  let_res_192  };
          Pointer let_res_227;
          {
            Vec<1, Pointer> dst_ref_397 { id_226 };
            int32_t id_228 { 0L };
            Vec<1, int32_t> id_229 {  id_228  };
            Pointer let_res_230;
            {
              Vec<1, int32_t> n_ref_398 { id_229 };
              ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_231 { std::get<1 /* Chart */>((*p_0)) };
              Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_232 { id_231.sources };
              for (::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 x_399 : id_232) {
                uint8_t id_233 { 0 };
                uint8_t id_234 { 0 };
                Pointer id_235 { dst_ref_397[id_234] };
                Pointer let_res_236;
                {
                  Pointer srec_dst_400 { id_235 };
                  auto fun237 { dessser::gen::fq_function_name::to_row_binary };
                  dessser::gen::fq_function_name::t_ext id_238 { x_399.name };
                  Pointer id_239 { fun237(id_238, srec_dst_400) };
                  let_res_236 = id_239;
                }
                Pointer let_res_240;
                {
                  Pointer srec_dst_401 { let_res_236 };
                  bool id_241 { x_399.visible };
                  uint8_t id_242 { uint8_t(id_241) };
                  Pointer id_243 { srec_dst_401.writeU8(id_242) };
                  let_res_240 = id_243;
                }
                Pointer let_res_244;
                {
                  Pointer srec_dst_402 { let_res_240 };
                  Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_245 { x_399.fields };
                  uint32_t id_246 { id_245.size() };
                  Vec<1, uint32_t> id_247 {  id_246  };
                  Pointer let_res_248;
                  {
                    Vec<1, uint32_t> leb128_sz_403 { id_247 };
                    Vec<1, Pointer> id_249 {  srec_dst_402  };
                    Pointer let_res_250;
                    {
                      Vec<1, Pointer> leb128_ptr_404 { id_249 };
                      bool while_flag_251 { true };
                      do {
                        uint8_t id_252 { 0 };
                        uint8_t id_253 { 0 };
                        Pointer id_254 { leb128_ptr_404[id_253] };
                        uint32_t id_255 { 128U };
                        uint8_t id_256 { 0 };
                        uint32_t id_257 { leb128_sz_403[id_256] };
                        bool id_258 { bool(id_255 > id_257) };
                        uint8_t choose_res_259;
                        if (id_258) {
                          uint8_t id_260 { 0 };
                          uint32_t id_261 { leb128_sz_403[id_260] };
                          uint8_t id_262 { uint8_t(id_261) };
                          choose_res_259 = id_262;
                        } else {
                          uint8_t id_263 { 0 };
                          uint32_t id_264 { leb128_sz_403[id_263] };
                          uint8_t id_265 { uint8_t(id_264) };
                          uint8_t id_266 { 128 };
                          uint8_t id_267 { uint8_t(id_265 | id_266) };
                          choose_res_259 = id_267;
                        }
                        Pointer id_268 { id_254.writeU8(choose_res_259) };
                        Void id_269 { ((void)(leb128_ptr_404[id_252] = id_268), VOID) };
                        (void)id_269;
                        uint8_t id_270 { 0 };
                        uint8_t id_271 { 0 };
                        uint32_t id_272 { leb128_sz_403[id_271] };
                        uint8_t id_273 { 7 };
                        uint32_t id_274 { uint32_t(id_272 >> id_273) };
                        Void id_275 { ((void)(leb128_sz_403[id_270] = id_274), VOID) };
                        (void)id_275;
                        uint8_t id_276 { 0 };
                        uint32_t id_277 { leb128_sz_403[id_276] };
                        uint32_t id_278 { 0U };
                        bool id_279 { bool(id_277 > id_278) };
                        while_flag_251 = id_279;
                        if (while_flag_251) {
                          (void)VOID;
                        }
                      } while (while_flag_251);
                      (void)VOID;
                      uint8_t id_280 { 0 };
                      Pointer id_281 { leb128_ptr_404[id_280] };
                      let_res_250 = id_281;
                    }
                    let_res_248 = let_res_250;
                  }
                  Vec<1, Pointer> id_282 {  let_res_248  };
                  Pointer let_res_283;
                  {
                    Vec<1, Pointer> dst_ref_405 { id_282 };
                    int32_t id_284 { 0L };
                    Vec<1, int32_t> id_285 {  id_284  };
                    Pointer let_res_286;
                    {
                      Vec<1, int32_t> n_ref_406 { id_285 };
                      Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_287 { x_399.fields };
                      for (::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 x_407 : id_287) {
                        uint8_t id_288 { 0 };
                        uint8_t id_289 { 0 };
                        Pointer id_290 { dst_ref_405[id_289] };
                        Pointer let_res_291;
                        {
                          Pointer srec_dst_408 { id_290 };
                          double id_292 { x_407.opacity };
                          uint64_t id_293 { qword_of_float(id_292) };
                          Pointer id_294 { srec_dst_408.writeU64Le(id_293) };
                          let_res_291 = id_294;
                        }
                        Pointer let_res_295;
                        {
                          Pointer srec_dst_409 { let_res_291 };
                          uint32_t id_296 { x_407.color };
                          Pointer id_297 { srec_dst_409.writeU32Le(id_296) };
                          let_res_295 = id_297;
                        }
                        Pointer let_res_298;
                        {
                          Pointer srec_dst_410 { let_res_295 };
                          ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_299 { x_407.representation };
                          uint16_t id_300 { uint16_t(id_299.index()) };
                          Pointer id_301 { srec_dst_410.writeU16Le(id_300) };
                          Pointer let_res_302;
                          {
                            Pointer ssum_dst_412 { id_301 };
                            uint16_t id_303 { 0 };
                            ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_304 { x_407.representation };
                            uint16_t id_305 { uint16_t(id_304.index()) };
                            bool id_306 { bool(id_303 == id_305) };
                            Pointer choose_res_307;
                            if (id_306) {
                              choose_res_307 = ssum_dst_412;
                            } else {
                              uint16_t id_308 { 1 };
                              ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_309 { x_407.representation };
                              uint16_t id_310 { uint16_t(id_309.index()) };
                              bool id_311 { bool(id_308 == id_310) };
                              Pointer choose_res_312;
                              if (id_311) {
                                choose_res_312 = ssum_dst_412;
                              } else {
                                uint16_t id_313 { 2 };
                                ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_314 { x_407.representation };
                                uint16_t id_315 { uint16_t(id_314.index()) };
                                bool id_316 { bool(id_313 == id_315) };
                                Pointer choose_res_317;
                                if (id_316) {
                                  choose_res_317 = ssum_dst_412;
                                } else {
                                  ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_318 { x_407.representation };
                                  uint16_t id_319 { uint16_t(id_318.index()) };
                                  uint16_t id_320 { 3 };
                                  bool id_321 { bool(id_319 == id_320) };
                                  Void id_322 { ((void)(assert(id_321)), VOID) };
                                  (void)id_322;
                                  choose_res_317 = ssum_dst_412;
                                }
                                choose_res_312 = choose_res_317;
                              }
                              choose_res_307 = choose_res_312;
                            }
                            let_res_302 = choose_res_307;
                          }
                          let_res_298 = let_res_302;
                        }
                        Pointer let_res_323;
                        {
                          Pointer srec_dst_413 { let_res_298 };
                          std::string id_324 { x_407.column };
                          uint32_t id_325 { (uint32_t)id_324.size() };
                          Vec<1, uint32_t> id_326 {  id_325  };
                          Pointer let_res_327;
                          {
                            Vec<1, uint32_t> leb128_sz_414 { id_326 };
                            Vec<1, Pointer> id_328 {  srec_dst_413  };
                            Pointer let_res_329;
                            {
                              Vec<1, Pointer> leb128_ptr_415 { id_328 };
                              bool while_flag_330 { true };
                              do {
                                uint8_t id_331 { 0 };
                                uint8_t id_332 { 0 };
                                Pointer id_333 { leb128_ptr_415[id_332] };
                                uint32_t id_334 { 128U };
                                uint8_t id_335 { 0 };
                                uint32_t id_336 { leb128_sz_414[id_335] };
                                bool id_337 { bool(id_334 > id_336) };
                                uint8_t choose_res_338;
                                if (id_337) {
                                  uint8_t id_339 { 0 };
                                  uint32_t id_340 { leb128_sz_414[id_339] };
                                  uint8_t id_341 { uint8_t(id_340) };
                                  choose_res_338 = id_341;
                                } else {
                                  uint8_t id_342 { 0 };
                                  uint32_t id_343 { leb128_sz_414[id_342] };
                                  uint8_t id_344 { uint8_t(id_343) };
                                  uint8_t id_345 { 128 };
                                  uint8_t id_346 { uint8_t(id_344 | id_345) };
                                  choose_res_338 = id_346;
                                }
                                Pointer id_347 { id_333.writeU8(choose_res_338) };
                                Void id_348 { ((void)(leb128_ptr_415[id_331] = id_347), VOID) };
                                (void)id_348;
                                uint8_t id_349 { 0 };
                                uint8_t id_350 { 0 };
                                uint32_t id_351 { leb128_sz_414[id_350] };
                                uint8_t id_352 { 7 };
                                uint32_t id_353 { uint32_t(id_351 >> id_352) };
                                Void id_354 { ((void)(leb128_sz_414[id_349] = id_353), VOID) };
                                (void)id_354;
                                uint8_t id_355 { 0 };
                                uint32_t id_356 { leb128_sz_414[id_355] };
                                uint32_t id_357 { 0U };
                                bool id_358 { bool(id_356 > id_357) };
                                while_flag_330 = id_358;
                                if (while_flag_330) {
                                  (void)VOID;
                                }
                              } while (while_flag_330);
                              (void)VOID;
                              uint8_t id_359 { 0 };
                              Pointer id_360 { leb128_ptr_415[id_359] };
                              let_res_329 = id_360;
                            }
                            let_res_327 = let_res_329;
                          }
                          std::string id_361 { x_407.column };
                          Bytes id_362 { id_361 };
                          Pointer id_363 { let_res_327.writeBytes(id_362) };
                          let_res_323 = id_363;
                        }
                        Pointer let_res_364;
                        {
                          Pointer srec_dst_416 { let_res_323 };
                          Arr<std::string> id_365 { x_407.factors };
                          uint32_t id_366 { id_365.size() };
                          Vec<1, uint32_t> id_367 {  id_366  };
                          Pointer let_res_368;
                          {
                            Vec<1, uint32_t> leb128_sz_417 { id_367 };
                            Vec<1, Pointer> id_369 {  srec_dst_416  };
                            Pointer let_res_370;
                            {
                              Vec<1, Pointer> leb128_ptr_418 { id_369 };
                              bool while_flag_371 { true };
                              do {
                                uint8_t id_372 { 0 };
                                uint8_t id_373 { 0 };
                                Pointer id_374 { leb128_ptr_418[id_373] };
                                uint32_t id_375 { 128U };
                                uint8_t id_376 { 0 };
                                uint32_t id_377 { leb128_sz_417[id_376] };
                                bool id_378 { bool(id_375 > id_377) };
                                uint8_t choose_res_379;
                                if (id_378) {
                                  uint8_t id_380 { 0 };
                                  uint32_t id_381 { leb128_sz_417[id_380] };
                                  uint8_t id_382 { uint8_t(id_381) };
                                  choose_res_379 = id_382;
                                } else {
                                  uint8_t id_383 { 0 };
                                  uint32_t id_384 { leb128_sz_417[id_383] };
                                  uint8_t id_385 { uint8_t(id_384) };
                                  uint8_t id_386 { 128 };
                                  uint8_t id_387 { uint8_t(id_385 | id_386) };
                                  choose_res_379 = id_387;
                                }
                                Pointer id_388 { id_374.writeU8(choose_res_379) };
                                Void id_389 { ((void)(leb128_ptr_418[id_372] = id_388), VOID) };
                                (void)id_389;
                                uint8_t id_390 { 0 };
                                uint8_t id_391 { 0 };
                                uint32_t id_392 { leb128_sz_417[id_391] };
                                uint8_t id_393 { 7 };
                                uint32_t id_394 { uint32_t(id_392 >> id_393) };
                                Void id_395 { ((void)(leb128_sz_417[id_390] = id_394), VOID) };
                                (void)id_395;
                                uint8_t id_396 { 0 };
                                uint32_t id_397 { leb128_sz_417[id_396] };
                                uint32_t id_398 { 0U };
                                bool id_399 { bool(id_397 > id_398) };
                                while_flag_371 = id_399;
                                if (while_flag_371) {
                                  (void)VOID;
                                }
                              } while (while_flag_371);
                              (void)VOID;
                              uint8_t id_400 { 0 };
                              Pointer id_401 { leb128_ptr_418[id_400] };
                              let_res_370 = id_401;
                            }
                            let_res_368 = let_res_370;
                          }
                          Vec<1, Pointer> id_402 {  let_res_368  };
                          Pointer let_res_403;
                          {
                            Vec<1, Pointer> dst_ref_419 { id_402 };
                            int32_t id_404 { 0L };
                            Vec<1, int32_t> id_405 {  id_404  };
                            Pointer let_res_406;
                            {
                              Vec<1, int32_t> n_ref_420 { id_405 };
                              Arr<std::string> id_407 { x_407.factors };
                              for (std::string x_421 : id_407) {
                                uint8_t id_408 { 0 };
                                uint32_t id_409 { (uint32_t)x_421.size() };
                                Vec<1, uint32_t> id_410 {  id_409  };
                                Pointer let_res_411;
                                {
                                  Vec<1, uint32_t> leb128_sz_422 { id_410 };
                                  uint8_t id_412 { 0 };
                                  Pointer id_413 { dst_ref_419[id_412] };
                                  Vec<1, Pointer> id_414 {  id_413  };
                                  Pointer let_res_415;
                                  {
                                    Vec<1, Pointer> leb128_ptr_423 { id_414 };
                                    bool while_flag_416 { true };
                                    do {
                                      uint8_t id_417 { 0 };
                                      uint8_t id_418 { 0 };
                                      Pointer id_419 { leb128_ptr_423[id_418] };
                                      uint32_t id_420 { 128U };
                                      uint8_t id_421 { 0 };
                                      uint32_t id_422 { leb128_sz_422[id_421] };
                                      bool id_423 { bool(id_420 > id_422) };
                                      uint8_t choose_res_424;
                                      if (id_423) {
                                        uint8_t id_425 { 0 };
                                        uint32_t id_426 { leb128_sz_422[id_425] };
                                        uint8_t id_427 { uint8_t(id_426) };
                                        choose_res_424 = id_427;
                                      } else {
                                        uint8_t id_428 { 0 };
                                        uint32_t id_429 { leb128_sz_422[id_428] };
                                        uint8_t id_430 { uint8_t(id_429) };
                                        uint8_t id_431 { 128 };
                                        uint8_t id_432 { uint8_t(id_430 | id_431) };
                                        choose_res_424 = id_432;
                                      }
                                      Pointer id_433 { id_419.writeU8(choose_res_424) };
                                      Void id_434 { ((void)(leb128_ptr_423[id_417] = id_433), VOID) };
                                      (void)id_434;
                                      uint8_t id_435 { 0 };
                                      uint8_t id_436 { 0 };
                                      uint32_t id_437 { leb128_sz_422[id_436] };
                                      uint8_t id_438 { 7 };
                                      uint32_t id_439 { uint32_t(id_437 >> id_438) };
                                      Void id_440 { ((void)(leb128_sz_422[id_435] = id_439), VOID) };
                                      (void)id_440;
                                      uint8_t id_441 { 0 };
                                      uint32_t id_442 { leb128_sz_422[id_441] };
                                      uint32_t id_443 { 0U };
                                      bool id_444 { bool(id_442 > id_443) };
                                      while_flag_416 = id_444;
                                      if (while_flag_416) {
                                        (void)VOID;
                                      }
                                    } while (while_flag_416);
                                    (void)VOID;
                                    uint8_t id_445 { 0 };
                                    Pointer id_446 { leb128_ptr_423[id_445] };
                                    let_res_415 = id_446;
                                  }
                                  let_res_411 = let_res_415;
                                }
                                Bytes id_447 { x_421 };
                                Pointer id_448 { let_res_411.writeBytes(id_447) };
                                Void id_449 { ((void)(dst_ref_419[id_408] = id_448), VOID) };
                                (void)id_449;
                                uint8_t id_450 { 0 };
                                int32_t id_451 { 1L };
                                uint8_t id_452 { 0 };
                                int32_t id_453 { n_ref_420[id_452] };
                                int32_t id_454 { int32_t(id_451 + id_453) };
                                Void id_455 { ((void)(n_ref_420[id_450] = id_454), VOID) };
                                (void)id_455;
                                (void)id_455;
                              }
                              (void)VOID;
                              uint8_t id_456 { 0 };
                              Pointer id_457 { dst_ref_419[id_456] };
                              let_res_406 = id_457;
                            }
                            let_res_403 = let_res_406;
                          }
                          let_res_364 = let_res_403;
                        }
                        Pointer let_res_458;
                        {
                          Pointer srec_dst_424 { let_res_364 };
                          uint8_t id_459 { x_407.axis };
                          Pointer id_460 { srec_dst_424.writeU8(id_459) };
                          let_res_458 = id_460;
                        }
                        Void id_461 { ((void)(dst_ref_405[id_288] = let_res_458), VOID) };
                        (void)id_461;
                        uint8_t id_462 { 0 };
                        int32_t id_463 { 1L };
                        uint8_t id_464 { 0 };
                        int32_t id_465 { n_ref_406[id_464] };
                        int32_t id_466 { int32_t(id_463 + id_465) };
                        Void id_467 { ((void)(n_ref_406[id_462] = id_466), VOID) };
                        (void)id_467;
                        (void)id_467;
                      }
                      (void)VOID;
                      uint8_t id_468 { 0 };
                      Pointer id_469 { dst_ref_405[id_468] };
                      let_res_286 = id_469;
                    }
                    let_res_283 = let_res_286;
                  }
                  let_res_244 = let_res_283;
                }
                Void id_470 { ((void)(dst_ref_397[id_233] = let_res_244), VOID) };
                (void)id_470;
                uint8_t id_471 { 0 };
                int32_t id_472 { 1L };
                uint8_t id_473 { 0 };
                int32_t id_474 { n_ref_398[id_473] };
                int32_t id_475 { int32_t(id_472 + id_474) };
                Void id_476 { ((void)(n_ref_398[id_471] = id_475), VOID) };
                (void)id_476;
                (void)id_476;
              }
              (void)VOID;
              uint8_t id_477 { 0 };
              Pointer id_478 { dst_ref_397[id_477] };
              let_res_230 = id_478;
            }
            let_res_227 = let_res_230;
          }
          let_res_187 = let_res_227;
        }
        choose_res_7 = let_res_187;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::dashboard_widget::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Text STRING | Chart {title: STRING; type: [Plot Void]; axis: {left: BOOL; force_zero: BOOL; scale: [Linear Void | Logarithmic Void]}[]; sources: {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]}[]}]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_374" (make-vec (string-length (get-alt "Text" (param 0))))
              (let "lebsz_ref_375" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_374")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_375")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_375") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_375")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_375")))))) 
            (size-of-u32 (string-length (get-alt "Text" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1)))
          (let "sz_344"
            (let "sz_335"
              (let "sz_333"
                (add (size 2)
                  (add
                    (let "n_ref_331" (make-vec (string-length (get-field "title" (get-alt "Chart" (param 0)))))
                      (let "lebsz_ref_332" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_331")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_332")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_332") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_332")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_332")))))) 
                    (size-of-u32 (string-length (get-field "title" (get-alt "Chart" (param 0))))))) 
                (seq (assert (eq (label-of (get-field "type" (get-alt "Chart" (param 0)))) (u16 0))) (add (identifier "sz_333") (size 2))))
              (let "sz_ref_338"
                (make-vec
                  (add (identifier "sz_335")
                    (let "n_ref_336" (make-vec (cardinality (get-field "axis" (get-alt "Chart" (param 0)))))
                      (let "lebsz_ref_337" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_336")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_337")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_337") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_337")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_337"))))))))
                (seq
                  (let "repeat_n_339" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "axis" (get-alt "Chart" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_339")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_338")
                          (let "sz_342" (add (add (unsafe-nth (u8 0) (identifier "sz_ref_338")) (size 1)) (size 1))
                            (let "label2_343" (label-of (get-field "scale" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_339")) (get-field "axis" (get-alt "Chart" (param 0))))))
                              (if (eq (u16 0) (identifier "label2_343")) (add (identifier "sz_342") (size 2)) (seq (assert (eq (identifier "label2_343") (u16 1))) (add (identifier "sz_342") (size 2)))))))
                        (set-vec (u8 0) (identifier "repeat_n_339") (add (unsafe-nth (u8 0) (identifier "repeat_n_339")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_338")))))
            (let "sz_ref_347"
              (make-vec
                (add (identifier "sz_344")
                  (let "n_ref_345" (make-vec (cardinality (get-field "sources" (get-alt "Chart" (param 0)))))
                    (let "lebsz_ref_346" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_345")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_346")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_346") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_346")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_346"))))))))
              (seq
                (let "repeat_n_348" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "sources" (get-alt "Chart" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_348")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_347")
                        (let "sz_351"
                          (add
                            (let "sz_349" (unsafe-nth (u8 0) (identifier "sz_ref_347"))
                              (add (identifier "sz_349")
                                (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-field "name" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_348")) (get-field "sources" (get-alt "Chart" (param 0))))))))
                            (size 1))
                          (let "sz_ref_354"
                            (make-vec
                              (add (identifier "sz_351")
                                (let "n_ref_352" (make-vec (cardinality (get-field "fields" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_348")) (get-field "sources" (get-alt "Chart" (param 0)))))))
                                  (let "lebsz_ref_353" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_352")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_353")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_353") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_353")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_353"))))))))
                            (seq
                              (let "repeat_n_355" (make-vec (i32 0))
                                (while
                                  (gt (to-i32 (cardinality (get-field "fields" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_348")) (get-field "sources" (get-alt "Chart" (param 0)))))))
                                    (unsafe-nth (u8 0) (identifier "repeat_n_355")))
                                  (seq
                                    (set-vec (u8 0) (identifier "sz_ref_354")
                                      (add
                                        (let "sz_364"
                                          (let "sz_360"
                                            (let "sz_358" (add (add (unsafe-nth (u8 0) (identifier "sz_ref_354")) (size 8)) (size 4))
                                              (let "label2_359"
                                                (label-of
                                                  (get-field "representation"
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_355"))
                                                      (get-field "fields" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_348")) (get-field "sources" (get-alt "Chart" (param 0))))))))
                                                (if (eq (u16 0) (identifier "label2_359")) 
                                                  (add (identifier "sz_358") (size 2))
                                                  (if (eq (u16 1) (identifier "label2_359")) 
                                                    (add (identifier "sz_358") (size 2))
                                                    (if (eq (u16 2) (identifier "label2_359")) (add (identifier "sz_358") (size 2)) (seq (assert (eq (identifier "label2_359") (u16 3))) (add (identifier "sz_358") (size 2))))))))
                                            (add (identifier "sz_360")
                                              (let "wlen_361"
                                                (string-length
                                                  (get-field "column"
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_355"))
                                                      (get-field "fields" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_348")) (get-field "sources" (get-alt "Chart" (param 0))))))))
                                                (add
                                                  (let "n_ref_362" (make-vec (identifier "wlen_361"))
                                                    (let "lebsz_ref_363" 
                                                      (make-vec (u32 1))
                                                      (seq
                                                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_362")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_363")) (u8 7)))
                                                          (set-vec (u8 0) (identifier "lebsz_ref_363") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_363")) (u32 1))))
                                                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_363")))))) 
                                                  (size-of-u32 (identifier "wlen_361"))))))
                                          (let "sz_ref_367"
                                            (make-vec
                                              (add (identifier "sz_364")
                                                (let "n_ref_365"
                                                  (make-vec
                                                    (cardinality
                                                      (get-field "factors"
                                                        (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_355"))
                                                          (get-field "fields" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_348")) (get-field "sources" (get-alt "Chart" (param 0)))))))))
                                                  (let "lebsz_ref_366" 
                                                    (make-vec (u32 1))
                                                    (seq
                                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_365")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_366")) (u8 7)))
                                                        (set-vec (u8 0) (identifier "lebsz_ref_366") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_366")) (u32 1)))) 
                                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_366"))))))))
                                            (seq
                                              (let "repeat_n_368" (make-vec (i32 0))
                                                (while
                                                  (gt
                                                    (to-i32
                                                      (cardinality
                                                        (get-field "factors"
                                                          (unsafe-nth 
                                                            (unsafe-nth (u8 0) (identifier "repeat_n_355"))
                                                            (get-field "fields" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_348")) (get-field "sources" (get-alt "Chart" (param 0)))))))))
                                                    (unsafe-nth (u8 0) (identifier "repeat_n_368")))
                                                  (seq
                                                    (set-vec (u8 0) (identifier "sz_ref_367")
                                                      (add (unsafe-nth (u8 0) (identifier "sz_ref_367"))
                                                        (let "wlen_369"
                                                          (string-length
                                                            (unsafe-nth 
                                                              (unsafe-nth (u8 0) (identifier "repeat_n_368"))
                                                              (get-field "factors"
                                                                (unsafe-nth 
                                                                  (unsafe-nth (u8 0) (identifier "repeat_n_355"))
                                                                  (get-field "fields" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_348")) (get-field "sources" (get-alt "Chart" (param 0)))))))))
                                                          (add
                                                            (let "n_ref_370" 
                                                              (make-vec (identifier "wlen_369"))
                                                              (let "lebsz_ref_371" 
                                                                (make-vec (u32 1))
                                                                (seq
                                                                  (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_370")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_371")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_371") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_371")) (u32 1))))
                                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_371")))))) 
                                                            (size-of-u32 (identifier "wlen_369")))))) 
                                                    (set-vec (u8 0) (identifier "repeat_n_368") (add (unsafe-nth (u8 0) (identifier "repeat_n_368")) (i32 1)))))) 
                                              (unsafe-nth (u8 0) (identifier "sz_ref_367"))))) 
                                        (size 1))) (set-vec (u8 0) (identifier "repeat_n_355") (add (unsafe-nth (u8 0) (identifier "repeat_n_355")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "sz_ref_354")))))) 
                      (set-vec (u8 0) (identifier "repeat_n_348") (add (unsafe-nth (u8 0) (identifier "repeat_n_348")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_347"))))))))
 */
static std::function<Size(::dessser::gen::dashboard_widget::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::dashboard_widget::t*)> fun479 { [&fun479](::dessser::gen::dashboard_widget::t* p_0) {
    uint16_t id_480 { 0 };
    uint16_t id_481 { uint16_t((*p_0).index()) };
    bool id_482 { bool(id_480 == id_481) };
    Size choose_res_483;
    if (id_482) {
      Size id_484 { 2UL };
      std::string id_485 { std::get<0 /* Text */>((*p_0)) };
      uint32_t id_486 { (uint32_t)id_485.size() };
      Vec<1, uint32_t> id_487 {  id_486  };
      Size let_res_488;
      {
        Vec<1, uint32_t> n_ref_374 { id_487 };
        uint32_t id_489 { 1U };
        Vec<1, uint32_t> id_490 {  id_489  };
        Size let_res_491;
        {
          Vec<1, uint32_t> lebsz_ref_375 { id_490 };
          bool while_flag_492 { true };
          do {
            uint8_t id_493 { 0 };
            uint32_t id_494 { n_ref_374[id_493] };
            uint8_t id_495 { 0 };
            uint32_t id_496 { lebsz_ref_375[id_495] };
            uint8_t id_497 { 7 };
            uint32_t id_498 { uint32_t(id_496 << id_497) };
            bool id_499 { bool(id_494 >= id_498) };
            while_flag_492 = id_499;
            if (while_flag_492) {
              uint8_t id_500 { 0 };
              uint8_t id_501 { 0 };
              uint32_t id_502 { lebsz_ref_375[id_501] };
              uint32_t id_503 { 1U };
              uint32_t id_504 { uint32_t(id_502 + id_503) };
              Void id_505 { ((void)(lebsz_ref_375[id_500] = id_504), VOID) };
              (void)id_505;
            }
          } while (while_flag_492);
          (void)VOID;
          uint8_t id_506 { 0 };
          uint32_t id_507 { lebsz_ref_375[id_506] };
          Size id_508 { Size(id_507) };
          let_res_491 = id_508;
        }
        let_res_488 = let_res_491;
      }
      std::string id_509 { std::get<0 /* Text */>((*p_0)) };
      uint32_t id_510 { (uint32_t)id_509.size() };
      Size id_511 { Size(id_510) };
      Size id_512 { Size(let_res_488 + id_511) };
      Size id_513 { Size(id_484 + id_512) };
      choose_res_483 = id_513;
    } else {
      uint16_t id_514 { uint16_t((*p_0).index()) };
      uint16_t id_515 { 1 };
      bool id_516 { bool(id_514 == id_515) };
      Void id_517 { ((void)(assert(id_516)), VOID) };
      (void)id_517;
      Size id_518 { 2UL };
      ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_519 { std::get<1 /* Chart */>((*p_0)) };
      std::string id_520 { id_519.title };
      uint32_t id_521 { (uint32_t)id_520.size() };
      Vec<1, uint32_t> id_522 {  id_521  };
      Size let_res_523;
      {
        Vec<1, uint32_t> n_ref_331 { id_522 };
        uint32_t id_524 { 1U };
        Vec<1, uint32_t> id_525 {  id_524  };
        Size let_res_526;
        {
          Vec<1, uint32_t> lebsz_ref_332 { id_525 };
          bool while_flag_527 { true };
          do {
            uint8_t id_528 { 0 };
            uint32_t id_529 { n_ref_331[id_528] };
            uint8_t id_530 { 0 };
            uint32_t id_531 { lebsz_ref_332[id_530] };
            uint8_t id_532 { 7 };
            uint32_t id_533 { uint32_t(id_531 << id_532) };
            bool id_534 { bool(id_529 >= id_533) };
            while_flag_527 = id_534;
            if (while_flag_527) {
              uint8_t id_535 { 0 };
              uint8_t id_536 { 0 };
              uint32_t id_537 { lebsz_ref_332[id_536] };
              uint32_t id_538 { 1U };
              uint32_t id_539 { uint32_t(id_537 + id_538) };
              Void id_540 { ((void)(lebsz_ref_332[id_535] = id_539), VOID) };
              (void)id_540;
            }
          } while (while_flag_527);
          (void)VOID;
          uint8_t id_541 { 0 };
          uint32_t id_542 { lebsz_ref_332[id_541] };
          Size id_543 { Size(id_542) };
          let_res_526 = id_543;
        }
        let_res_523 = let_res_526;
      }
      ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_544 { std::get<1 /* Chart */>((*p_0)) };
      std::string id_545 { id_544.title };
      uint32_t id_546 { (uint32_t)id_545.size() };
      Size id_547 { Size(id_546) };
      Size id_548 { Size(let_res_523 + id_547) };
      Size id_549 { Size(id_518 + id_548) };
      Size let_res_550;
      {
        Size sz_333 { id_549 };
        ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_551 { std::get<1 /* Chart */>((*p_0)) };
        ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 id_552 { id_551.type };
        uint16_t id_553 { uint16_t(id_552.index()) };
        uint16_t id_554 { 0 };
        bool id_555 { bool(id_553 == id_554) };
        Void id_556 { ((void)(assert(id_555)), VOID) };
        (void)id_556;
        Size id_557 { 2UL };
        Size id_558 { Size(sz_333 + id_557) };
        let_res_550 = id_558;
      }
      Size let_res_559;
      {
        Size sz_335 { let_res_550 };
        ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_560 { std::get<1 /* Chart */>((*p_0)) };
        Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> id_561 { id_560.Chart_axis };
        uint32_t id_562 { id_561.size() };
        Vec<1, uint32_t> id_563 {  id_562  };
        Size let_res_564;
        {
          Vec<1, uint32_t> n_ref_336 { id_563 };
          uint32_t id_565 { 1U };
          Vec<1, uint32_t> id_566 {  id_565  };
          Size let_res_567;
          {
            Vec<1, uint32_t> lebsz_ref_337 { id_566 };
            bool while_flag_568 { true };
            do {
              uint8_t id_569 { 0 };
              uint32_t id_570 { n_ref_336[id_569] };
              uint8_t id_571 { 0 };
              uint32_t id_572 { lebsz_ref_337[id_571] };
              uint8_t id_573 { 7 };
              uint32_t id_574 { uint32_t(id_572 << id_573) };
              bool id_575 { bool(id_570 >= id_574) };
              while_flag_568 = id_575;
              if (while_flag_568) {
                uint8_t id_576 { 0 };
                uint8_t id_577 { 0 };
                uint32_t id_578 { lebsz_ref_337[id_577] };
                uint32_t id_579 { 1U };
                uint32_t id_580 { uint32_t(id_578 + id_579) };
                Void id_581 { ((void)(lebsz_ref_337[id_576] = id_580), VOID) };
                (void)id_581;
              }
            } while (while_flag_568);
            (void)VOID;
            uint8_t id_582 { 0 };
            uint32_t id_583 { lebsz_ref_337[id_582] };
            Size id_584 { Size(id_583) };
            let_res_567 = id_584;
          }
          let_res_564 = let_res_567;
        }
        Size id_585 { Size(sz_335 + let_res_564) };
        Vec<1, Size> id_586 {  id_585  };
        Size let_res_587;
        {
          Vec<1, Size> sz_ref_338 { id_586 };
          int32_t id_588 { 0L };
          Vec<1, int32_t> id_589 {  id_588  };
          {
            Vec<1, int32_t> repeat_n_339 { id_589 };
            bool while_flag_590 { true };
            do {
              ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_591 { std::get<1 /* Chart */>((*p_0)) };
              Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> id_592 { id_591.Chart_axis };
              uint32_t id_593 { id_592.size() };
              int32_t id_594 { int32_t(id_593) };
              uint8_t id_595 { 0 };
              int32_t id_596 { repeat_n_339[id_595] };
              bool id_597 { bool(id_594 > id_596) };
              while_flag_590 = id_597;
              if (while_flag_590) {
                uint8_t id_598 { 0 };
                uint8_t id_599 { 0 };
                Size id_600 { sz_ref_338[id_599] };
                Size id_601 { 1UL };
                Size id_602 { Size(id_600 + id_601) };
                Size id_603 { 1UL };
                Size id_604 { Size(id_602 + id_603) };
                Size let_res_605;
                {
                  Size sz_342 { id_604 };
                  uint8_t id_606 { 0 };
                  int32_t id_607 { repeat_n_339[id_606] };
                  ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_608 { std::get<1 /* Chart */>((*p_0)) };
                  Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> id_609 { id_608.Chart_axis };
                  ::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6 id_610 { id_609[id_607] };
                  ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 id_611 { id_610.scale };
                  uint16_t id_612 { uint16_t(id_611.index()) };
                  Size let_res_613;
                  {
                    uint16_t label2_343 { id_612 };
                    uint16_t id_614 { 0 };
                    bool id_615 { bool(id_614 == label2_343) };
                    Size choose_res_616;
                    if (id_615) {
                      Size id_617 { 2UL };
                      Size id_618 { Size(sz_342 + id_617) };
                      choose_res_616 = id_618;
                    } else {
                      uint16_t id_619 { 1 };
                      bool id_620 { bool(label2_343 == id_619) };
                      Void id_621 { ((void)(assert(id_620)), VOID) };
                      (void)id_621;
                      Size id_622 { 2UL };
                      Size id_623 { Size(sz_342 + id_622) };
                      choose_res_616 = id_623;
                    }
                    let_res_613 = choose_res_616;
                  }
                  let_res_605 = let_res_613;
                }
                Void id_624 { ((void)(sz_ref_338[id_598] = let_res_605), VOID) };
                (void)id_624;
                uint8_t id_625 { 0 };
                uint8_t id_626 { 0 };
                int32_t id_627 { repeat_n_339[id_626] };
                int32_t id_628 { 1L };
                int32_t id_629 { int32_t(id_627 + id_628) };
                Void id_630 { ((void)(repeat_n_339[id_625] = id_629), VOID) };
                (void)id_630;
                (void)id_630;
              }
            } while (while_flag_590);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_631 { 0 };
          Size id_632 { sz_ref_338[id_631] };
          let_res_587 = id_632;
        }
        let_res_559 = let_res_587;
      }
      Size let_res_633;
      {
        Size sz_344 { let_res_559 };
        ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_634 { std::get<1 /* Chart */>((*p_0)) };
        Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_635 { id_634.sources };
        uint32_t id_636 { id_635.size() };
        Vec<1, uint32_t> id_637 {  id_636  };
        Size let_res_638;
        {
          Vec<1, uint32_t> n_ref_345 { id_637 };
          uint32_t id_639 { 1U };
          Vec<1, uint32_t> id_640 {  id_639  };
          Size let_res_641;
          {
            Vec<1, uint32_t> lebsz_ref_346 { id_640 };
            bool while_flag_642 { true };
            do {
              uint8_t id_643 { 0 };
              uint32_t id_644 { n_ref_345[id_643] };
              uint8_t id_645 { 0 };
              uint32_t id_646 { lebsz_ref_346[id_645] };
              uint8_t id_647 { 7 };
              uint32_t id_648 { uint32_t(id_646 << id_647) };
              bool id_649 { bool(id_644 >= id_648) };
              while_flag_642 = id_649;
              if (while_flag_642) {
                uint8_t id_650 { 0 };
                uint8_t id_651 { 0 };
                uint32_t id_652 { lebsz_ref_346[id_651] };
                uint32_t id_653 { 1U };
                uint32_t id_654 { uint32_t(id_652 + id_653) };
                Void id_655 { ((void)(lebsz_ref_346[id_650] = id_654), VOID) };
                (void)id_655;
              }
            } while (while_flag_642);
            (void)VOID;
            uint8_t id_656 { 0 };
            uint32_t id_657 { lebsz_ref_346[id_656] };
            Size id_658 { Size(id_657) };
            let_res_641 = id_658;
          }
          let_res_638 = let_res_641;
        }
        Size id_659 { Size(sz_344 + let_res_638) };
        Vec<1, Size> id_660 {  id_659  };
        Size let_res_661;
        {
          Vec<1, Size> sz_ref_347 { id_660 };
          int32_t id_662 { 0L };
          Vec<1, int32_t> id_663 {  id_662  };
          {
            Vec<1, int32_t> repeat_n_348 { id_663 };
            bool while_flag_664 { true };
            do {
              ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_665 { std::get<1 /* Chart */>((*p_0)) };
              Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_666 { id_665.sources };
              uint32_t id_667 { id_666.size() };
              int32_t id_668 { int32_t(id_667) };
              uint8_t id_669 { 0 };
              int32_t id_670 { repeat_n_348[id_669] };
              bool id_671 { bool(id_668 > id_670) };
              while_flag_664 = id_671;
              if (while_flag_664) {
                uint8_t id_672 { 0 };
                uint8_t id_673 { 0 };
                Size id_674 { sz_ref_347[id_673] };
                Size let_res_675;
                {
                  Size sz_349 { id_674 };
                  auto fun676 { dessser::gen::fq_function_name::sersize_of_row_binary };
                  uint8_t id_677 { 0 };
                  int32_t id_678 { repeat_n_348[id_677] };
                  ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_679 { std::get<1 /* Chart */>((*p_0)) };
                  Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_680 { id_679.sources };
                  ::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 id_681 { id_680[id_678] };
                  dessser::gen::fq_function_name::t_ext id_682 { id_681.name };
                  Size id_683 { fun676(id_682) };
                  Size id_684 { Size(sz_349 + id_683) };
                  let_res_675 = id_684;
                }
                Size id_685 { 1UL };
                Size id_686 { Size(let_res_675 + id_685) };
                Size let_res_687;
                {
                  Size sz_351 { id_686 };
                  uint8_t id_688 { 0 };
                  int32_t id_689 { repeat_n_348[id_688] };
                  ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_690 { std::get<1 /* Chart */>((*p_0)) };
                  Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_691 { id_690.sources };
                  ::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 id_692 { id_691[id_689] };
                  Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_693 { id_692.fields };
                  uint32_t id_694 { id_693.size() };
                  Vec<1, uint32_t> id_695 {  id_694  };
                  Size let_res_696;
                  {
                    Vec<1, uint32_t> n_ref_352 { id_695 };
                    uint32_t id_697 { 1U };
                    Vec<1, uint32_t> id_698 {  id_697  };
                    Size let_res_699;
                    {
                      Vec<1, uint32_t> lebsz_ref_353 { id_698 };
                      bool while_flag_700 { true };
                      do {
                        uint8_t id_701 { 0 };
                        uint32_t id_702 { n_ref_352[id_701] };
                        uint8_t id_703 { 0 };
                        uint32_t id_704 { lebsz_ref_353[id_703] };
                        uint8_t id_705 { 7 };
                        uint32_t id_706 { uint32_t(id_704 << id_705) };
                        bool id_707 { bool(id_702 >= id_706) };
                        while_flag_700 = id_707;
                        if (while_flag_700) {
                          uint8_t id_708 { 0 };
                          uint8_t id_709 { 0 };
                          uint32_t id_710 { lebsz_ref_353[id_709] };
                          uint32_t id_711 { 1U };
                          uint32_t id_712 { uint32_t(id_710 + id_711) };
                          Void id_713 { ((void)(lebsz_ref_353[id_708] = id_712), VOID) };
                          (void)id_713;
                        }
                      } while (while_flag_700);
                      (void)VOID;
                      uint8_t id_714 { 0 };
                      uint32_t id_715 { lebsz_ref_353[id_714] };
                      Size id_716 { Size(id_715) };
                      let_res_699 = id_716;
                    }
                    let_res_696 = let_res_699;
                  }
                  Size id_717 { Size(sz_351 + let_res_696) };
                  Vec<1, Size> id_718 {  id_717  };
                  Size let_res_719;
                  {
                    Vec<1, Size> sz_ref_354 { id_718 };
                    int32_t id_720 { 0L };
                    Vec<1, int32_t> id_721 {  id_720  };
                    {
                      Vec<1, int32_t> repeat_n_355 { id_721 };
                      bool while_flag_722 { true };
                      do {
                        uint8_t id_723 { 0 };
                        int32_t id_724 { repeat_n_348[id_723] };
                        ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_725 { std::get<1 /* Chart */>((*p_0)) };
                        Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_726 { id_725.sources };
                        ::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 id_727 { id_726[id_724] };
                        Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_728 { id_727.fields };
                        uint32_t id_729 { id_728.size() };
                        int32_t id_730 { int32_t(id_729) };
                        uint8_t id_731 { 0 };
                        int32_t id_732 { repeat_n_355[id_731] };
                        bool id_733 { bool(id_730 > id_732) };
                        while_flag_722 = id_733;
                        if (while_flag_722) {
                          uint8_t id_734 { 0 };
                          uint8_t id_735 { 0 };
                          Size id_736 { sz_ref_354[id_735] };
                          Size id_737 { 8UL };
                          Size id_738 { Size(id_736 + id_737) };
                          Size id_739 { 4UL };
                          Size id_740 { Size(id_738 + id_739) };
                          Size let_res_741;
                          {
                            Size sz_358 { id_740 };
                            uint8_t id_742 { 0 };
                            int32_t id_743 { repeat_n_355[id_742] };
                            uint8_t id_744 { 0 };
                            int32_t id_745 { repeat_n_348[id_744] };
                            ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_746 { std::get<1 /* Chart */>((*p_0)) };
                            Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_747 { id_746.sources };
                            ::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 id_748 { id_747[id_745] };
                            Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_749 { id_748.fields };
                            ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_750 { id_749[id_743] };
                            ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_751 { id_750.representation };
                            uint16_t id_752 { uint16_t(id_751.index()) };
                            Size let_res_753;
                            {
                              uint16_t label2_359 { id_752 };
                              uint16_t id_754 { 0 };
                              bool id_755 { bool(id_754 == label2_359) };
                              Size choose_res_756;
                              if (id_755) {
                                Size id_757 { 2UL };
                                Size id_758 { Size(sz_358 + id_757) };
                                choose_res_756 = id_758;
                              } else {
                                uint16_t id_759 { 1 };
                                bool id_760 { bool(id_759 == label2_359) };
                                Size choose_res_761;
                                if (id_760) {
                                  Size id_762 { 2UL };
                                  Size id_763 { Size(sz_358 + id_762) };
                                  choose_res_761 = id_763;
                                } else {
                                  uint16_t id_764 { 2 };
                                  bool id_765 { bool(id_764 == label2_359) };
                                  Size choose_res_766;
                                  if (id_765) {
                                    Size id_767 { 2UL };
                                    Size id_768 { Size(sz_358 + id_767) };
                                    choose_res_766 = id_768;
                                  } else {
                                    uint16_t id_769 { 3 };
                                    bool id_770 { bool(label2_359 == id_769) };
                                    Void id_771 { ((void)(assert(id_770)), VOID) };
                                    (void)id_771;
                                    Size id_772 { 2UL };
                                    Size id_773 { Size(sz_358 + id_772) };
                                    choose_res_766 = id_773;
                                  }
                                  choose_res_761 = choose_res_766;
                                }
                                choose_res_756 = choose_res_761;
                              }
                              let_res_753 = choose_res_756;
                            }
                            let_res_741 = let_res_753;
                          }
                          Size let_res_774;
                          {
                            Size sz_360 { let_res_741 };
                            uint8_t id_775 { 0 };
                            int32_t id_776 { repeat_n_355[id_775] };
                            uint8_t id_777 { 0 };
                            int32_t id_778 { repeat_n_348[id_777] };
                            ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_779 { std::get<1 /* Chart */>((*p_0)) };
                            Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_780 { id_779.sources };
                            ::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 id_781 { id_780[id_778] };
                            Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_782 { id_781.fields };
                            ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_783 { id_782[id_776] };
                            std::string id_784 { id_783.column };
                            uint32_t id_785 { (uint32_t)id_784.size() };
                            Size let_res_786;
                            {
                              uint32_t wlen_361 { id_785 };
                              Vec<1, uint32_t> id_787 {  wlen_361  };
                              Size let_res_788;
                              {
                                Vec<1, uint32_t> n_ref_362 { id_787 };
                                uint32_t id_789 { 1U };
                                Vec<1, uint32_t> id_790 {  id_789  };
                                Size let_res_791;
                                {
                                  Vec<1, uint32_t> lebsz_ref_363 { id_790 };
                                  bool while_flag_792 { true };
                                  do {
                                    uint8_t id_793 { 0 };
                                    uint32_t id_794 { n_ref_362[id_793] };
                                    uint8_t id_795 { 0 };
                                    uint32_t id_796 { lebsz_ref_363[id_795] };
                                    uint8_t id_797 { 7 };
                                    uint32_t id_798 { uint32_t(id_796 << id_797) };
                                    bool id_799 { bool(id_794 >= id_798) };
                                    while_flag_792 = id_799;
                                    if (while_flag_792) {
                                      uint8_t id_800 { 0 };
                                      uint8_t id_801 { 0 };
                                      uint32_t id_802 { lebsz_ref_363[id_801] };
                                      uint32_t id_803 { 1U };
                                      uint32_t id_804 { uint32_t(id_802 + id_803) };
                                      Void id_805 { ((void)(lebsz_ref_363[id_800] = id_804), VOID) };
                                      (void)id_805;
                                    }
                                  } while (while_flag_792);
                                  (void)VOID;
                                  uint8_t id_806 { 0 };
                                  uint32_t id_807 { lebsz_ref_363[id_806] };
                                  Size id_808 { Size(id_807) };
                                  let_res_791 = id_808;
                                }
                                let_res_788 = let_res_791;
                              }
                              Size id_809 { Size(wlen_361) };
                              Size id_810 { Size(let_res_788 + id_809) };
                              let_res_786 = id_810;
                            }
                            Size id_811 { Size(sz_360 + let_res_786) };
                            let_res_774 = id_811;
                          }
                          Size let_res_812;
                          {
                            Size sz_364 { let_res_774 };
                            uint8_t id_813 { 0 };
                            int32_t id_814 { repeat_n_355[id_813] };
                            uint8_t id_815 { 0 };
                            int32_t id_816 { repeat_n_348[id_815] };
                            ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_817 { std::get<1 /* Chart */>((*p_0)) };
                            Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_818 { id_817.sources };
                            ::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 id_819 { id_818[id_816] };
                            Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_820 { id_819.fields };
                            ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_821 { id_820[id_814] };
                            Arr<std::string> id_822 { id_821.factors };
                            uint32_t id_823 { id_822.size() };
                            Vec<1, uint32_t> id_824 {  id_823  };
                            Size let_res_825;
                            {
                              Vec<1, uint32_t> n_ref_365 { id_824 };
                              uint32_t id_826 { 1U };
                              Vec<1, uint32_t> id_827 {  id_826  };
                              Size let_res_828;
                              {
                                Vec<1, uint32_t> lebsz_ref_366 { id_827 };
                                bool while_flag_829 { true };
                                do {
                                  uint8_t id_830 { 0 };
                                  uint32_t id_831 { n_ref_365[id_830] };
                                  uint8_t id_832 { 0 };
                                  uint32_t id_833 { lebsz_ref_366[id_832] };
                                  uint8_t id_834 { 7 };
                                  uint32_t id_835 { uint32_t(id_833 << id_834) };
                                  bool id_836 { bool(id_831 >= id_835) };
                                  while_flag_829 = id_836;
                                  if (while_flag_829) {
                                    uint8_t id_837 { 0 };
                                    uint8_t id_838 { 0 };
                                    uint32_t id_839 { lebsz_ref_366[id_838] };
                                    uint32_t id_840 { 1U };
                                    uint32_t id_841 { uint32_t(id_839 + id_840) };
                                    Void id_842 { ((void)(lebsz_ref_366[id_837] = id_841), VOID) };
                                    (void)id_842;
                                  }
                                } while (while_flag_829);
                                (void)VOID;
                                uint8_t id_843 { 0 };
                                uint32_t id_844 { lebsz_ref_366[id_843] };
                                Size id_845 { Size(id_844) };
                                let_res_828 = id_845;
                              }
                              let_res_825 = let_res_828;
                            }
                            Size id_846 { Size(sz_364 + let_res_825) };
                            Vec<1, Size> id_847 {  id_846  };
                            Size let_res_848;
                            {
                              Vec<1, Size> sz_ref_367 { id_847 };
                              int32_t id_849 { 0L };
                              Vec<1, int32_t> id_850 {  id_849  };
                              {
                                Vec<1, int32_t> repeat_n_368 { id_850 };
                                bool while_flag_851 { true };
                                do {
                                  uint8_t id_852 { 0 };
                                  int32_t id_853 { repeat_n_355[id_852] };
                                  uint8_t id_854 { 0 };
                                  int32_t id_855 { repeat_n_348[id_854] };
                                  ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_856 { std::get<1 /* Chart */>((*p_0)) };
                                  Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_857 { id_856.sources };
                                  ::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 id_858 { id_857[id_855] };
                                  Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_859 { id_858.fields };
                                  ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_860 { id_859[id_853] };
                                  Arr<std::string> id_861 { id_860.factors };
                                  uint32_t id_862 { id_861.size() };
                                  int32_t id_863 { int32_t(id_862) };
                                  uint8_t id_864 { 0 };
                                  int32_t id_865 { repeat_n_368[id_864] };
                                  bool id_866 { bool(id_863 > id_865) };
                                  while_flag_851 = id_866;
                                  if (while_flag_851) {
                                    uint8_t id_867 { 0 };
                                    uint8_t id_868 { 0 };
                                    Size id_869 { sz_ref_367[id_868] };
                                    uint8_t id_870 { 0 };
                                    int32_t id_871 { repeat_n_368[id_870] };
                                    uint8_t id_872 { 0 };
                                    int32_t id_873 { repeat_n_355[id_872] };
                                    uint8_t id_874 { 0 };
                                    int32_t id_875 { repeat_n_348[id_874] };
                                    ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_876 { std::get<1 /* Chart */>((*p_0)) };
                                    Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_877 { id_876.sources };
                                    ::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 id_878 { id_877[id_875] };
                                    Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_879 { id_878.fields };
                                    ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_880 { id_879[id_873] };
                                    Arr<std::string> id_881 { id_880.factors };
                                    std::string id_882 { id_881[id_871] };
                                    uint32_t id_883 { (uint32_t)id_882.size() };
                                    Size let_res_884;
                                    {
                                      uint32_t wlen_369 { id_883 };
                                      Vec<1, uint32_t> id_885 {  wlen_369  };
                                      Size let_res_886;
                                      {
                                        Vec<1, uint32_t> n_ref_370 { id_885 };
                                        uint32_t id_887 { 1U };
                                        Vec<1, uint32_t> id_888 {  id_887  };
                                        Size let_res_889;
                                        {
                                          Vec<1, uint32_t> lebsz_ref_371 { id_888 };
                                          bool while_flag_890 { true };
                                          do {
                                            uint8_t id_891 { 0 };
                                            uint32_t id_892 { n_ref_370[id_891] };
                                            uint8_t id_893 { 0 };
                                            uint32_t id_894 { lebsz_ref_371[id_893] };
                                            uint8_t id_895 { 7 };
                                            uint32_t id_896 { uint32_t(id_894 << id_895) };
                                            bool id_897 { bool(id_892 >= id_896) };
                                            while_flag_890 = id_897;
                                            if (while_flag_890) {
                                              uint8_t id_898 { 0 };
                                              uint8_t id_899 { 0 };
                                              uint32_t id_900 { lebsz_ref_371[id_899] };
                                              uint32_t id_901 { 1U };
                                              uint32_t id_902 { uint32_t(id_900 + id_901) };
                                              Void id_903 { ((void)(lebsz_ref_371[id_898] = id_902), VOID) };
                                              (void)id_903;
                                            }
                                          } while (while_flag_890);
                                          (void)VOID;
                                          uint8_t id_904 { 0 };
                                          uint32_t id_905 { lebsz_ref_371[id_904] };
                                          Size id_906 { Size(id_905) };
                                          let_res_889 = id_906;
                                        }
                                        let_res_886 = let_res_889;
                                      }
                                      Size id_907 { Size(wlen_369) };
                                      Size id_908 { Size(let_res_886 + id_907) };
                                      let_res_884 = id_908;
                                    }
                                    Size id_909 { Size(id_869 + let_res_884) };
                                    Void id_910 { ((void)(sz_ref_367[id_867] = id_909), VOID) };
                                    (void)id_910;
                                    uint8_t id_911 { 0 };
                                    uint8_t id_912 { 0 };
                                    int32_t id_913 { repeat_n_368[id_912] };
                                    int32_t id_914 { 1L };
                                    int32_t id_915 { int32_t(id_913 + id_914) };
                                    Void id_916 { ((void)(repeat_n_368[id_911] = id_915), VOID) };
                                    (void)id_916;
                                    (void)id_916;
                                  }
                                } while (while_flag_851);
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_917 { 0 };
                              Size id_918 { sz_ref_367[id_917] };
                              let_res_848 = id_918;
                            }
                            let_res_812 = let_res_848;
                          }
                          Size id_919 { 1UL };
                          Size id_920 { Size(let_res_812 + id_919) };
                          Void id_921 { ((void)(sz_ref_354[id_734] = id_920), VOID) };
                          (void)id_921;
                          uint8_t id_922 { 0 };
                          uint8_t id_923 { 0 };
                          int32_t id_924 { repeat_n_355[id_923] };
                          int32_t id_925 { 1L };
                          int32_t id_926 { int32_t(id_924 + id_925) };
                          Void id_927 { ((void)(repeat_n_355[id_922] = id_926), VOID) };
                          (void)id_927;
                          (void)id_927;
                        }
                      } while (while_flag_722);
                      (void)VOID;
                    }
                    (void)VOID;
                    uint8_t id_928 { 0 };
                    Size id_929 { sz_ref_354[id_928] };
                    let_res_719 = id_929;
                  }
                  let_res_687 = let_res_719;
                }
                Void id_930 { ((void)(sz_ref_347[id_672] = let_res_687), VOID) };
                (void)id_930;
                uint8_t id_931 { 0 };
                uint8_t id_932 { 0 };
                int32_t id_933 { repeat_n_348[id_932] };
                int32_t id_934 { 1L };
                int32_t id_935 { int32_t(id_933 + id_934) };
                Void id_936 { ((void)(repeat_n_348[id_931] = id_935), VOID) };
                (void)id_936;
                (void)id_936;
              }
            } while (while_flag_664);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_937 { 0 };
          Size id_938 { sz_ref_347[id_937] };
          let_res_661 = id_938;
        }
        let_res_633 = let_res_661;
      }
      choose_res_483 = let_res_633;
    }
    return choose_res_483;
  }
   };
  return fun479;
}
std::function<Size(::dessser::gen::dashboard_widget::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_326" "make_snd_327"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let "dstring1_316"
                (let "leb_ref_310" (make-vec (u32 0))
                  (let "shft_ref_311" (make-vec (u8 0))
                    (let "p_ref_312" (make-vec (identifier "dsum1_snd_64"))
                      (seq
                        (while
                          (let "leb128_313" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_312")))
                            (let-pair "leb128_fst_314" "leb128_snd_315" 
                              (identifier "leb128_313")
                              (seq (set-vec (u8 0) (identifier "p_ref_312") (identifier "leb128_snd_315"))
                                (set-vec (u8 0) (identifier "leb_ref_310")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_314") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_311"))) (unsafe-nth (u8 0) (identifier "leb_ref_310"))))
                                (set-vec (u8 0) (identifier "shft_ref_311") (add (unsafe-nth (u8 0) (identifier "shft_ref_311")) (u8 7))) 
                                (ge (identifier "leb128_fst_314") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_310"))) (unsafe-nth (u8 0) (identifier "p_ref_312")))))))
                (let-pair "dstring1_fst_317" "dstring1_snd_318" (identifier "dstring1_316")
                  (let-pair "dstring2_fst_320" "dstring2_snd_321" (read-bytes (identifier "dstring1_snd_318") (identifier "dstring1_fst_317"))
                    (make-tup
                      (construct "[Text STRING | Chart {title: STRING; type: [Plot Void]; axis: {left: BOOL; force_zero: BOOL; scale: [Linear Void | Logarithmic Void]}[]; sources: {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]}[]}]" 0
                        (string-of-bytes (identifier "dstring2_fst_320"))) 
                      (identifier "dstring2_snd_321")))))
              (seq (assert (eq (identifier "dsum1_fst_63") (u16 1)))
                (let "drec_77"
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
                        (make-tup (string-of-bytes (identifier "dstring2_fst_75")) (identifier "dstring2_snd_76")))))
                  (let-pair "drec_fst_78" "drec_snd_79" (identifier "drec_77")
                    (let "drec_92"
                      (let "dsum1_86" (let-pair "du16_fst_81" "du16_snd_82" (read-u16 little-endian (identifier "drec_snd_79")) (make-tup (identifier "du16_fst_81") (identifier "du16_snd_82")))
                        (let-pair "dsum1_fst_87" "dsum1_snd_88" (identifier "dsum1_86") (seq (assert (eq (identifier "dsum1_fst_87") (u16 0))) (make-tup (construct "[Plot Void]" 0 (nop)) (identifier "dsum1_snd_88")))))
                      (let-pair "drec_fst_93" "drec_snd_94" (identifier "drec_92")
                        (let "drec_148"
                          (let-pair "dlist4_fst_146" "dlist4_snd_147"
                            (let "dlist1_104"
                              (let "leb_ref_95" (make-vec (u32 0))
                                (let "shft_ref_96" (make-vec (u8 0))
                                  (let "p_ref_97" (make-vec (identifier "drec_snd_94"))
                                    (seq
                                      (while
                                        (let "leb128_98" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_97")))
                                          (let-pair "leb128_fst_99" "leb128_snd_100" 
                                            (identifier "leb128_98")
                                            (seq (set-vec (u8 0) (identifier "p_ref_97") (identifier "leb128_snd_100"))
                                              (set-vec (u8 0) (identifier "leb_ref_95")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_99") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_96"))) (unsafe-nth (u8 0) (identifier "leb_ref_95"))))
                                              (set-vec (u8 0) (identifier "shft_ref_96") (add (unsafe-nth (u8 0) (identifier "shft_ref_96")) (u8 7))) 
                                              (ge (identifier "leb128_fst_99") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_95")) (unsafe-nth (u8 0) (identifier "p_ref_97")))))))
                              (let-pair "dlist1_fst_105" "dlist1_snd_106" 
                                (identifier "dlist1_104")
                                (let "inits_src_ref_107" (make-vec (make-tup (end-of-list "{left: BOOL; force_zero: BOOL; scale: [Linear Void | Logarithmic Void]}") (identifier "dlist1_snd_106")))
                                  (seq
                                    (let "repeat_n_108" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_105")) (unsafe-nth (u8 0) (identifier "repeat_n_108")))
                                        (seq
                                          (let "dlist2_109" (unsafe-nth (u8 0) (identifier "inits_src_ref_107"))
                                            (let-pair "dlist2_fst_110" "dlist2_snd_111" 
                                              (identifier "dlist2_109")
                                              (set-vec (u8 0) (identifier "inits_src_ref_107")
                                                (let "drec_115"
                                                  (let-pair "dbool_fst_113" "dbool_snd_114" (read-u8 (identifier "dlist2_snd_111")) (make-tup (not (eq (identifier "dbool_fst_113") (u8 0))) (identifier "dbool_snd_114")))
                                                  (let-pair "drec_fst_116" "drec_snd_117" 
                                                    (identifier "drec_115")
                                                    (let "drec_121"
                                                      (let-pair "dbool_fst_119" "dbool_snd_120" (read-u8 (identifier "drec_snd_117")) (make-tup (not (eq (identifier "dbool_fst_119") (u8 0))) (identifier "dbool_snd_120")))
                                                      (let-pair "drec_fst_122" "drec_snd_123" 
                                                        (identifier "drec_121")
                                                        (let-pair "drec_fst_140" "drec_snd_141"
                                                          (let "dsum1_130"
                                                            (let-pair "du16_fst_125" "du16_snd_126" (read-u16 little-endian (identifier "drec_snd_123")) (make-tup (identifier "du16_fst_125") (identifier "du16_snd_126")))
                                                            (let-pair "dsum1_fst_131" "dsum1_snd_132" 
                                                              (identifier "dsum1_130")
                                                              (if (eq (u16 0) (identifier "dsum1_fst_131")) 
                                                                (make-tup (construct "[Linear Void | Logarithmic Void]" 0 (nop)) (identifier "dsum1_snd_132"))
                                                                (seq (assert (eq (identifier "dsum1_fst_131") (u16 1))) (make-tup (construct "[Linear Void | Logarithmic Void]" 1 (nop)) (identifier "dsum1_snd_132"))))))
                                                          (make-tup
                                                            (cons (make-rec (string "scale") (identifier "drec_fst_140") (string "force_zero") (identifier "drec_fst_122") (string "left") (identifier "drec_fst_116"))
                                                              (identifier "dlist2_fst_110")) 
                                                            (identifier "drec_snd_141")))))))))) 
                                          (set-vec (u8 0) (identifier "repeat_n_108") (add (unsafe-nth (u8 0) (identifier "repeat_n_108")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_107")))))) 
                            (make-tup (arr-of-lst-rev (identifier "dlist4_fst_146")) (identifier "dlist4_snd_147")))
                          (let-pair "drec_fst_149" "drec_snd_150" (identifier "drec_148")
                            (let-pair "dlist4_fst_302" "dlist4_snd_303"
                              (let "dlist1_160"
                                (let "leb_ref_151" (make-vec (u32 0))
                                  (let "shft_ref_152" (make-vec (u8 0))
                                    (let "p_ref_153" (make-vec (identifier "drec_snd_150"))
                                      (seq
                                        (while
                                          (let "leb128_154" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_153")))
                                            (let-pair "leb128_fst_155" "leb128_snd_156" 
                                              (identifier "leb128_154")
                                              (seq (set-vec (u8 0) (identifier "p_ref_153") (identifier "leb128_snd_156"))
                                                (set-vec (u8 0) (identifier "leb_ref_151")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_155") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_152"))) (unsafe-nth (u8 0) (identifier "leb_ref_151"))))
                                                (set-vec (u8 0) (identifier "shft_ref_152") (add (unsafe-nth (u8 0) (identifier "shft_ref_152")) (u8 7))) 
                                                (ge (identifier "leb128_fst_155") (u8 128))))) 
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_151")) (unsafe-nth (u8 0) (identifier "p_ref_153")))))))
                                (let-pair "dlist1_fst_161" "dlist1_snd_162" 
                                  (identifier "dlist1_160")
                                  (let "inits_src_ref_163"
                                    (make-vec
                                      (make-tup
                                        (end-of-list "{name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]}")
                                        (identifier "dlist1_snd_162")))
                                    (seq
                                      (let "repeat_n_164" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_161")) (unsafe-nth (u8 0) (identifier "repeat_n_164")))
                                          (seq
                                            (let "dlist2_165" (unsafe-nth (u8 0) (identifier "inits_src_ref_163"))
                                              (let-pair "dlist2_fst_166" "dlist2_snd_167" 
                                                (identifier "dlist2_165")
                                                (set-vec (u8 0) (identifier "inits_src_ref_163")
                                                  (let "drec_168" (apply (ext-identifier fq_function_name of-row-binary) (identifier "dlist2_snd_167"))
                                                    (let-pair "drec_fst_169" "drec_snd_170" 
                                                      (identifier "drec_168")
                                                      (let "drec_174"
                                                        (let-pair "dbool_fst_172" "dbool_snd_173" (read-u8 (identifier "drec_snd_170")) (make-tup (not (eq (identifier "dbool_fst_172") (u8 0))) (identifier "dbool_snd_173")))
                                                        (let-pair "drec_fst_175" "drec_snd_176" 
                                                          (identifier "drec_174")
                                                          (let-pair "dlist4_fst_293" "dlist4_snd_294"
                                                            (let "dlist1_186"
                                                              (let "leb_ref_177" 
                                                                (make-vec (u32 0))
                                                                (let "shft_ref_178" 
                                                                  (make-vec (u8 0))
                                                                  (let "p_ref_179" 
                                                                    (make-vec (identifier "drec_snd_176"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_180" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_179")))
                                                                    (let-pair "leb128_fst_181" "leb128_snd_182" 
                                                                    (identifier "leb128_180")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_179") (identifier "leb128_snd_182"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_177")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_181") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_178")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_177")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_178") (add (unsafe-nth (u8 0) (identifier "shft_ref_178")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_181") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_177")) (unsafe-nth (u8 0) (identifier "p_ref_179")))))))
                                                              (let-pair "dlist1_fst_187" "dlist1_snd_188" 
                                                                (identifier "dlist1_186")
                                                                (let "inits_src_ref_189"
                                                                  (make-vec
                                                                    (make-tup
                                                                    (end-of-list "{opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}")
                                                                    (identifier "dlist1_snd_188")))
                                                                  (seq
                                                                    (let "repeat_n_190" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_187")) (unsafe-nth (u8 0) (identifier "repeat_n_190")))
                                                                    (seq
                                                                    (let "dlist2_191" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_189"))
                                                                    (let-pair "dlist2_fst_192" "dlist2_snd_193" 
                                                                    (identifier "dlist2_191")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_189")
                                                                    (let "drec_197"
                                                                    (let-pair "dfloat_fst_195" "dfloat_snd_196" 
                                                                    (read-u64 little-endian (identifier "dlist2_snd_193")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_195")) (identifier "dfloat_snd_196")))
                                                                    (let-pair "drec_fst_198" "drec_snd_199" 
                                                                    (identifier "drec_197")
                                                                    (let "drec_203"
                                                                    (let-pair "du32_fst_201" "du32_snd_202" (read-u32 little-endian (identifier "drec_snd_199")) (make-tup (identifier "du32_fst_201") (identifier "du32_snd_202")))
                                                                    (let-pair "drec_fst_204" "drec_snd_205" 
                                                                    (identifier "drec_203")
                                                                    (let "drec_227"
                                                                    (let "dsum1_212"
                                                                    (let-pair "du16_fst_207" "du16_snd_208" (read-u16 little-endian (identifier "drec_snd_205")) (make-tup (identifier "du16_fst_207") (identifier "du16_snd_208")))
                                                                    (let-pair "dsum1_fst_213" "dsum1_snd_214" 
                                                                    (identifier "dsum1_212")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_213"))
                                                                    (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 0 (nop)) (identifier "dsum1_snd_214"))
                                                                    (if 
                                                                    (eq (u16 1) (identifier "dsum1_fst_213"))
                                                                    (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 1 (nop)) (identifier "dsum1_snd_214"))
                                                                    (if 
                                                                    (eq (u16 2) (identifier "dsum1_fst_213"))
                                                                    (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 2 (nop)) (identifier "dsum1_snd_214"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_213") (u16 3)))
                                                                    (make-tup (construct "[Unused Void | Independent Void | Stacked Void | StackCentered Void]" 3 (nop)) (identifier "dsum1_snd_214"))))))))
                                                                    (let-pair "drec_fst_228" "drec_snd_229" 
                                                                    (identifier "drec_227")
                                                                    (let "drec_242"
                                                                    (let "dstring1_236"
                                                                    (let "leb_ref_230" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_231" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_232" 
                                                                    (make-vec (identifier "drec_snd_229"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_233" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_232")))
                                                                    (let-pair "leb128_fst_234" "leb128_snd_235" 
                                                                    (identifier "leb128_233")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_232") (identifier "leb128_snd_235"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_230")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_234") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_231")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_230")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_231") (add (unsafe-nth (u8 0) (identifier "shft_ref_231")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_234") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_230"))) (unsafe-nth (u8 0) (identifier "p_ref_232")))))))
                                                                    (let-pair "dstring1_fst_237" "dstring1_snd_238" 
                                                                    (identifier "dstring1_236")
                                                                    (let-pair "dstring2_fst_240" "dstring2_snd_241" 
                                                                    (read-bytes (identifier "dstring1_snd_238") (identifier "dstring1_fst_237"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_240")) (identifier "dstring2_snd_241")))))
                                                                    (let-pair "drec_fst_243" "drec_snd_244" 
                                                                    (identifier "drec_242")
                                                                    (let "drec_280"
                                                                    (let-pair "dlist4_fst_278" "dlist4_snd_279"
                                                                    (let "dlist1_254"
                                                                    (let "leb_ref_245" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_246" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_247" 
                                                                    (make-vec (identifier "drec_snd_244"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_248" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_247")))
                                                                    (let-pair "leb128_fst_249" "leb128_snd_250" 
                                                                    (identifier "leb128_248")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_247") (identifier "leb128_snd_250"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_245")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_249") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_246")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_245")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_246") (add (unsafe-nth (u8 0) (identifier "shft_ref_246")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_249") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_245")) (unsafe-nth (u8 0) (identifier "p_ref_247")))))))
                                                                    (let-pair "dlist1_fst_255" "dlist1_snd_256" 
                                                                    (identifier "dlist1_254")
                                                                    (let "inits_src_ref_257" 
                                                                    (make-vec (make-tup (end-of-list "STRING") (identifier "dlist1_snd_256")))
                                                                    (seq
                                                                    (let "repeat_n_258" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_255")) (unsafe-nth (u8 0) (identifier "repeat_n_258")))
                                                                    (seq
                                                                    (let "dlist2_259" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_257"))
                                                                    (let-pair "dlist2_fst_260" "dlist2_snd_261" 
                                                                    (identifier "dlist2_259")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_257")
                                                                    (let "dstring1_268"
                                                                    (let "leb_ref_262" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_263" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_264" 
                                                                    (make-vec (identifier "dlist2_snd_261"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_265" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_264")))
                                                                    (let-pair "leb128_fst_266" "leb128_snd_267" 
                                                                    (identifier "leb128_265")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_264") (identifier "leb128_snd_267"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_262")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_266") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_263")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_262")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_263") (add (unsafe-nth (u8 0) (identifier "shft_ref_263")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_266") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_262"))) (unsafe-nth (u8 0) (identifier "p_ref_264")))))))
                                                                    (let-pair "dstring1_fst_269" "dstring1_snd_270" 
                                                                    (identifier "dstring1_268")
                                                                    (let-pair "dstring2_fst_272" "dstring2_snd_273" 
                                                                    (read-bytes (identifier "dstring1_snd_270") (identifier "dstring1_fst_269"))
                                                                    (make-tup (cons (string-of-bytes (identifier "dstring2_fst_272")) (identifier "dlist2_fst_260")) (identifier "dstring2_snd_273"))))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_258") (add (unsafe-nth (u8 0) (identifier "repeat_n_258")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_257")))))) 
                                                                    (make-tup (arr-of-lst-rev (identifier "dlist4_fst_278")) (identifier "dlist4_snd_279")))
                                                                    (let-pair "drec_fst_281" "drec_snd_282" 
                                                                    (identifier "drec_280")
                                                                    (let-pair "du8_fst_284" "du8_snd_285" 
                                                                    (read-u8 (identifier "drec_snd_282"))
                                                                    (make-tup
                                                                    (cons
                                                                    (make-rec 
                                                                    (string "axis") 
                                                                    (identifier "du8_fst_284") 
                                                                    (string "factors") 
                                                                    (identifier "drec_fst_281") 
                                                                    (string "column") 
                                                                    (identifier "drec_fst_243") 
                                                                    (string "representation") 
                                                                    (identifier "drec_fst_228") 
                                                                    (string "color") 
                                                                    (identifier "drec_fst_204") 
                                                                    (string "opacity") 
                                                                    (identifier "drec_fst_198")) 
                                                                    (identifier "dlist2_fst_192")) 
                                                                    (identifier "du8_snd_285")))))))))))))))) 
                                                                    (set-vec (u8 0) (identifier "repeat_n_190") (add (unsafe-nth (u8 0) (identifier "repeat_n_190")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_189"))))))
                                                            (make-tup
                                                              (cons
                                                                (make-rec 
                                                                  (string "fields") 
                                                                  (arr-of-lst-rev (identifier "dlist4_fst_293")) 
                                                                  (string "visible") 
                                                                  (identifier "drec_fst_175") 
                                                                  (string "name") 
                                                                  (identifier "drec_fst_169")) 
                                                                (identifier "dlist2_fst_166")) 
                                                              (identifier "dlist4_snd_294")))))))))) 
                                            (set-vec (u8 0) (identifier "repeat_n_164") (add (unsafe-nth (u8 0) (identifier "repeat_n_164")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_163"))))))
                              (make-tup
                                (construct "[Text STRING | Chart {title: STRING; type: [Plot Void]; axis: {left: BOOL; force_zero: BOOL; scale: [Linear Void | Logarithmic Void]}[]; sources: {name: $fq_function_name; visible: BOOL; fields: {opacity: FLOAT; color: U32; representation: [Unused Void | Independent Void | Stacked Void | StackCentered Void]; column: STRING; factors: STRING[]; axis: U8}[]}[]}]" 1
                                  (make-rec (string "sources") (arr-of-lst-rev (identifier "dlist4_fst_302")) 
                                    (string "axis") (identifier "drec_fst_149") 
                                    (string "type") (identifier "drec_fst_93") 
                                    (string "title") (identifier "drec_fst_78"))) 
                                (identifier "dlist4_snd_303"))))))))))))) 
        (make-tup (identifier "make_fst_326") (identifier "make_snd_327"))))
 */
static std::function<::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1(Pointer)> fun939 { [&fun939](Pointer p_0) {
    ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 id_940 { p_0.readU16Le() };
    ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 letpair_res_941;
    {
      auto du16_fst_57 { std::get<0>(id_940) };
      auto du16_snd_58 { std::get<1>(id_940) };
      ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 id_942 { du16_fst_57, du16_snd_58 };
      letpair_res_941 = id_942;
    }
    ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 let_res_943;
    {
      ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_941 };
      ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 letpair_res_944;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_945 { 0 };
        bool id_946 { bool(id_945 == dsum1_fst_63) };
        ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 choose_res_947;
        if (id_946) {
          uint32_t id_948 { 0U };
          Vec<1, uint32_t> id_949 {  id_948  };
          ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_950;
          {
            Vec<1, uint32_t> leb_ref_310 { id_949 };
            uint8_t id_951 { 0 };
            Vec<1, uint8_t> id_952 {  id_951  };
            ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_953;
            {
              Vec<1, uint8_t> shft_ref_311 { id_952 };
              Vec<1, Pointer> id_954 {  dsum1_snd_64  };
              ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_955;
              {
                Vec<1, Pointer> p_ref_312 { id_954 };
                bool while_flag_956 { true };
                do {
                  uint8_t id_957 { 0 };
                  Pointer id_958 { p_ref_312[id_957] };
                  ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_959 { id_958.readU8() };
                  bool let_res_960;
                  {
                    ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 leb128_313 { id_959 };
                    bool letpair_res_961;
                    {
                      auto leb128_fst_314 { std::get<0>(leb128_313) };
                      auto leb128_snd_315 { std::get<1>(leb128_313) };
                      uint8_t id_962 { 0 };
                      Void id_963 { ((void)(p_ref_312[id_962] = leb128_snd_315), VOID) };
                      (void)id_963;
                      uint8_t id_964 { 0 };
                      uint8_t id_965 { 127 };
                      uint8_t id_966 { uint8_t(leb128_fst_314 & id_965) };
                      uint32_t id_967 { uint32_t(id_966) };
                      uint8_t id_968 { 0 };
                      uint8_t id_969 { shft_ref_311[id_968] };
                      uint32_t id_970 { uint32_t(id_967 << id_969) };
                      uint8_t id_971 { 0 };
                      uint32_t id_972 { leb_ref_310[id_971] };
                      uint32_t id_973 { uint32_t(id_970 | id_972) };
                      Void id_974 { ((void)(leb_ref_310[id_964] = id_973), VOID) };
                      (void)id_974;
                      uint8_t id_975 { 0 };
                      uint8_t id_976 { 0 };
                      uint8_t id_977 { shft_ref_311[id_976] };
                      uint8_t id_978 { 7 };
                      uint8_t id_979 { uint8_t(id_977 + id_978) };
                      Void id_980 { ((void)(shft_ref_311[id_975] = id_979), VOID) };
                      (void)id_980;
                      uint8_t id_981 { 128 };
                      bool id_982 { bool(leb128_fst_314 >= id_981) };
                      letpair_res_961 = id_982;
                    }
                    let_res_960 = letpair_res_961;
                  }
                  while_flag_956 = let_res_960;
                  if (while_flag_956) {
                    (void)VOID;
                  }
                } while (while_flag_956);
                (void)VOID;
                uint8_t id_983 { 0 };
                uint32_t id_984 { leb_ref_310[id_983] };
                Size id_985 { Size(id_984) };
                uint8_t id_986 { 0 };
                Pointer id_987 { p_ref_312[id_986] };
                ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c id_988 { id_985, id_987 };
                let_res_955 = id_988;
              }
              let_res_953 = let_res_955;
            }
            let_res_950 = let_res_953;
          }
          ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 let_res_989;
          {
            ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c dstring1_316 { let_res_950 };
            ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 letpair_res_990;
            {
              auto dstring1_fst_317 { std::get<0>(dstring1_316) };
              auto dstring1_snd_318 { std::get<1>(dstring1_316) };
              ::dessser::gen::dashboard_widget::t188345aa49abd0cb47ff73fedc219f08 id_991 { dstring1_snd_318.readBytes(dstring1_fst_317) };
              ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 letpair_res_992;
              {
                auto dstring2_fst_320 { std::get<0>(id_991) };
                auto dstring2_snd_321 { std::get<1>(id_991) };
                std::string id_993 { dstring2_fst_320.toString() };
                ::dessser::gen::dashboard_widget::t* id_994 { new ::dessser::gen::dashboard_widget::t(std::in_place_index<0>, id_993) };
                ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 id_995 { id_994, dstring2_snd_321 };
                letpair_res_992 = id_995;
              }
              letpair_res_990 = letpair_res_992;
            }
            let_res_989 = letpair_res_990;
          }
          choose_res_947 = let_res_989;
        } else {
          uint16_t id_996 { 1 };
          bool id_997 { bool(dsum1_fst_63 == id_996) };
          Void id_998 { ((void)(assert(id_997)), VOID) };
          (void)id_998;
          uint32_t id_999 { 0U };
          Vec<1, uint32_t> id_1000 {  id_999  };
          ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_1001;
          {
            Vec<1, uint32_t> leb_ref_65 { id_1000 };
            uint8_t id_1002 { 0 };
            Vec<1, uint8_t> id_1003 {  id_1002  };
            ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_1004;
            {
              Vec<1, uint8_t> shft_ref_66 { id_1003 };
              Vec<1, Pointer> id_1005 {  dsum1_snd_64  };
              ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_1006;
              {
                Vec<1, Pointer> p_ref_67 { id_1005 };
                bool while_flag_1007 { true };
                do {
                  uint8_t id_1008 { 0 };
                  Pointer id_1009 { p_ref_67[id_1008] };
                  ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1010 { id_1009.readU8() };
                  bool let_res_1011;
                  {
                    ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 leb128_68 { id_1010 };
                    bool letpair_res_1012;
                    {
                      auto leb128_fst_69 { std::get<0>(leb128_68) };
                      auto leb128_snd_70 { std::get<1>(leb128_68) };
                      uint8_t id_1013 { 0 };
                      Void id_1014 { ((void)(p_ref_67[id_1013] = leb128_snd_70), VOID) };
                      (void)id_1014;
                      uint8_t id_1015 { 0 };
                      uint8_t id_1016 { 127 };
                      uint8_t id_1017 { uint8_t(leb128_fst_69 & id_1016) };
                      uint32_t id_1018 { uint32_t(id_1017) };
                      uint8_t id_1019 { 0 };
                      uint8_t id_1020 { shft_ref_66[id_1019] };
                      uint32_t id_1021 { uint32_t(id_1018 << id_1020) };
                      uint8_t id_1022 { 0 };
                      uint32_t id_1023 { leb_ref_65[id_1022] };
                      uint32_t id_1024 { uint32_t(id_1021 | id_1023) };
                      Void id_1025 { ((void)(leb_ref_65[id_1015] = id_1024), VOID) };
                      (void)id_1025;
                      uint8_t id_1026 { 0 };
                      uint8_t id_1027 { 0 };
                      uint8_t id_1028 { shft_ref_66[id_1027] };
                      uint8_t id_1029 { 7 };
                      uint8_t id_1030 { uint8_t(id_1028 + id_1029) };
                      Void id_1031 { ((void)(shft_ref_66[id_1026] = id_1030), VOID) };
                      (void)id_1031;
                      uint8_t id_1032 { 128 };
                      bool id_1033 { bool(leb128_fst_69 >= id_1032) };
                      letpair_res_1012 = id_1033;
                    }
                    let_res_1011 = letpair_res_1012;
                  }
                  while_flag_1007 = let_res_1011;
                  if (while_flag_1007) {
                    (void)VOID;
                  }
                } while (while_flag_1007);
                (void)VOID;
                uint8_t id_1034 { 0 };
                uint32_t id_1035 { leb_ref_65[id_1034] };
                Size id_1036 { Size(id_1035) };
                uint8_t id_1037 { 0 };
                Pointer id_1038 { p_ref_67[id_1037] };
                ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c id_1039 { id_1036, id_1038 };
                let_res_1006 = id_1039;
              }
              let_res_1004 = let_res_1006;
            }
            let_res_1001 = let_res_1004;
          }
          ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e let_res_1040;
          {
            ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c dstring1_71 { let_res_1001 };
            ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1041;
            {
              auto dstring1_fst_72 { std::get<0>(dstring1_71) };
              auto dstring1_snd_73 { std::get<1>(dstring1_71) };
              ::dessser::gen::dashboard_widget::t188345aa49abd0cb47ff73fedc219f08 id_1042 { dstring1_snd_73.readBytes(dstring1_fst_72) };
              ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1043;
              {
                auto dstring2_fst_75 { std::get<0>(id_1042) };
                auto dstring2_snd_76 { std::get<1>(id_1042) };
                std::string id_1044 { dstring2_fst_75.toString() };
                ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e id_1045 { id_1044, dstring2_snd_76 };
                letpair_res_1043 = id_1045;
              }
              letpair_res_1041 = letpair_res_1043;
            }
            let_res_1040 = letpair_res_1041;
          }
          ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 let_res_1046;
          {
            ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e drec_77 { let_res_1040 };
            ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 letpair_res_1047;
            {
              auto drec_fst_78 { std::get<0>(drec_77) };
              auto drec_snd_79 { std::get<1>(drec_77) };
              ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 id_1048 { drec_snd_79.readU16Le() };
              ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1049;
              {
                auto du16_fst_81 { std::get<0>(id_1048) };
                auto du16_snd_82 { std::get<1>(id_1048) };
                ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 id_1050 { du16_fst_81, du16_snd_82 };
                letpair_res_1049 = id_1050;
              }
              ::dessser::gen::dashboard_widget::tcf8b8a1aaccb8df8d0f0d02152cf69d9 let_res_1051;
              {
                ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 dsum1_86 { letpair_res_1049 };
                ::dessser::gen::dashboard_widget::tcf8b8a1aaccb8df8d0f0d02152cf69d9 letpair_res_1052;
                {
                  auto dsum1_fst_87 { std::get<0>(dsum1_86) };
                  auto dsum1_snd_88 { std::get<1>(dsum1_86) };
                  uint16_t id_1053 { 0 };
                  bool id_1054 { bool(dsum1_fst_87 == id_1053) };
                  Void id_1055 { ((void)(assert(id_1054)), VOID) };
                  (void)id_1055;
                  (void)VOID;
                  ::dessser::gen::dashboard_widget::t3ef59f16a0cdd3a9e330e7c5bf93b091 id_1056 { std::in_place_index<0>, VOID };
                  ::dessser::gen::dashboard_widget::tcf8b8a1aaccb8df8d0f0d02152cf69d9 id_1057 { id_1056, dsum1_snd_88 };
                  letpair_res_1052 = id_1057;
                }
                let_res_1051 = letpair_res_1052;
              }
              ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 let_res_1058;
              {
                ::dessser::gen::dashboard_widget::tcf8b8a1aaccb8df8d0f0d02152cf69d9 drec_92 { let_res_1051 };
                ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 letpair_res_1059;
                {
                  auto drec_fst_93 { std::get<0>(drec_92) };
                  auto drec_snd_94 { std::get<1>(drec_92) };
                  uint32_t id_1060 { 0U };
                  Vec<1, uint32_t> id_1061 {  id_1060  };
                  ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1062;
                  {
                    Vec<1, uint32_t> leb_ref_95 { id_1061 };
                    uint8_t id_1063 { 0 };
                    Vec<1, uint8_t> id_1064 {  id_1063  };
                    ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1065;
                    {
                      Vec<1, uint8_t> shft_ref_96 { id_1064 };
                      Vec<1, Pointer> id_1066 {  drec_snd_94  };
                      ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1067;
                      {
                        Vec<1, Pointer> p_ref_97 { id_1066 };
                        bool while_flag_1068 { true };
                        do {
                          uint8_t id_1069 { 0 };
                          Pointer id_1070 { p_ref_97[id_1069] };
                          ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1071 { id_1070.readU8() };
                          bool let_res_1072;
                          {
                            ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 leb128_98 { id_1071 };
                            bool letpair_res_1073;
                            {
                              auto leb128_fst_99 { std::get<0>(leb128_98) };
                              auto leb128_snd_100 { std::get<1>(leb128_98) };
                              uint8_t id_1074 { 0 };
                              Void id_1075 { ((void)(p_ref_97[id_1074] = leb128_snd_100), VOID) };
                              (void)id_1075;
                              uint8_t id_1076 { 0 };
                              uint8_t id_1077 { 127 };
                              uint8_t id_1078 { uint8_t(leb128_fst_99 & id_1077) };
                              uint32_t id_1079 { uint32_t(id_1078) };
                              uint8_t id_1080 { 0 };
                              uint8_t id_1081 { shft_ref_96[id_1080] };
                              uint32_t id_1082 { uint32_t(id_1079 << id_1081) };
                              uint8_t id_1083 { 0 };
                              uint32_t id_1084 { leb_ref_95[id_1083] };
                              uint32_t id_1085 { uint32_t(id_1082 | id_1084) };
                              Void id_1086 { ((void)(leb_ref_95[id_1076] = id_1085), VOID) };
                              (void)id_1086;
                              uint8_t id_1087 { 0 };
                              uint8_t id_1088 { 0 };
                              uint8_t id_1089 { shft_ref_96[id_1088] };
                              uint8_t id_1090 { 7 };
                              uint8_t id_1091 { uint8_t(id_1089 + id_1090) };
                              Void id_1092 { ((void)(shft_ref_96[id_1087] = id_1091), VOID) };
                              (void)id_1092;
                              uint8_t id_1093 { 128 };
                              bool id_1094 { bool(leb128_fst_99 >= id_1093) };
                              letpair_res_1073 = id_1094;
                            }
                            let_res_1072 = letpair_res_1073;
                          }
                          while_flag_1068 = let_res_1072;
                          if (while_flag_1068) {
                            (void)VOID;
                          }
                        } while (while_flag_1068);
                        (void)VOID;
                        uint8_t id_1095 { 0 };
                        uint32_t id_1096 { leb_ref_95[id_1095] };
                        uint8_t id_1097 { 0 };
                        Pointer id_1098 { p_ref_97[id_1097] };
                        ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 id_1099 { id_1096, id_1098 };
                        let_res_1067 = id_1099;
                      }
                      let_res_1065 = let_res_1067;
                    }
                    let_res_1062 = let_res_1065;
                  }
                  ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 let_res_1100;
                  {
                    ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 dlist1_104 { let_res_1062 };
                    ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 letpair_res_1101;
                    {
                      auto dlist1_fst_105 { std::get<0>(dlist1_104) };
                      auto dlist1_snd_106 { std::get<1>(dlist1_104) };
                      Lst<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> endoflist_1102;
                      ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 id_1103 { endoflist_1102, dlist1_snd_106 };
                      Vec<1, ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444> id_1104 {  id_1103  };
                      ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 let_res_1105;
                      {
                        Vec<1, ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444> inits_src_ref_107 { id_1104 };
                        int32_t id_1106 { 0L };
                        Vec<1, int32_t> id_1107 {  id_1106  };
                        {
                          Vec<1, int32_t> repeat_n_108 { id_1107 };
                          bool while_flag_1108 { true };
                          do {
                            int32_t id_1109 { int32_t(dlist1_fst_105) };
                            uint8_t id_1110 { 0 };
                            int32_t id_1111 { repeat_n_108[id_1110] };
                            bool id_1112 { bool(id_1109 > id_1111) };
                            while_flag_1108 = id_1112;
                            if (while_flag_1108) {
                              uint8_t id_1113 { 0 };
                              ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 id_1114 { inits_src_ref_107[id_1113] };
                              {
                                ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 dlist2_109 { id_1114 };
                                {
                                  auto dlist2_fst_110 { std::get<0>(dlist2_109) };
                                  auto dlist2_snd_111 { std::get<1>(dlist2_109) };
                                  uint8_t id_1115 { 0 };
                                  ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1116 { dlist2_snd_111.readU8() };
                                  ::dessser::gen::dashboard_widget::t4138de986e20d18b01e4c493dc9d5451 letpair_res_1117;
                                  {
                                    auto dbool_fst_113 { std::get<0>(id_1116) };
                                    auto dbool_snd_114 { std::get<1>(id_1116) };
                                    uint8_t id_1118 { 0 };
                                    bool id_1119 { bool(dbool_fst_113 == id_1118) };
                                    bool id_1120 { ! id_1119 };
                                    ::dessser::gen::dashboard_widget::t4138de986e20d18b01e4c493dc9d5451 id_1121 { id_1120, dbool_snd_114 };
                                    letpair_res_1117 = id_1121;
                                  }
                                  ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 let_res_1122;
                                  {
                                    ::dessser::gen::dashboard_widget::t4138de986e20d18b01e4c493dc9d5451 drec_115 { letpair_res_1117 };
                                    ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 letpair_res_1123;
                                    {
                                      auto drec_fst_116 { std::get<0>(drec_115) };
                                      auto drec_snd_117 { std::get<1>(drec_115) };
                                      ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1124 { drec_snd_117.readU8() };
                                      ::dessser::gen::dashboard_widget::t4138de986e20d18b01e4c493dc9d5451 letpair_res_1125;
                                      {
                                        auto dbool_fst_119 { std::get<0>(id_1124) };
                                        auto dbool_snd_120 { std::get<1>(id_1124) };
                                        uint8_t id_1126 { 0 };
                                        bool id_1127 { bool(dbool_fst_119 == id_1126) };
                                        bool id_1128 { ! id_1127 };
                                        ::dessser::gen::dashboard_widget::t4138de986e20d18b01e4c493dc9d5451 id_1129 { id_1128, dbool_snd_120 };
                                        letpair_res_1125 = id_1129;
                                      }
                                      ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 let_res_1130;
                                      {
                                        ::dessser::gen::dashboard_widget::t4138de986e20d18b01e4c493dc9d5451 drec_121 { letpair_res_1125 };
                                        ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 letpair_res_1131;
                                        {
                                          auto drec_fst_122 { std::get<0>(drec_121) };
                                          auto drec_snd_123 { std::get<1>(drec_121) };
                                          ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 id_1132 { drec_snd_123.readU16Le() };
                                          ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1133;
                                          {
                                            auto du16_fst_125 { std::get<0>(id_1132) };
                                            auto du16_snd_126 { std::get<1>(id_1132) };
                                            ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 id_1134 { du16_fst_125, du16_snd_126 };
                                            letpair_res_1133 = id_1134;
                                          }
                                          ::dessser::gen::dashboard_widget::t18f962e0b602b25173933adabf09c5e6 let_res_1135;
                                          {
                                            ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 dsum1_130 { letpair_res_1133 };
                                            ::dessser::gen::dashboard_widget::t18f962e0b602b25173933adabf09c5e6 letpair_res_1136;
                                            {
                                              auto dsum1_fst_131 { std::get<0>(dsum1_130) };
                                              auto dsum1_snd_132 { std::get<1>(dsum1_130) };
                                              uint16_t id_1137 { 0 };
                                              bool id_1138 { bool(id_1137 == dsum1_fst_131) };
                                              ::dessser::gen::dashboard_widget::t18f962e0b602b25173933adabf09c5e6 choose_res_1139;
                                              if (id_1138) {
                                                (void)VOID;
                                                ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 id_1140 { std::in_place_index<0>, VOID };
                                                ::dessser::gen::dashboard_widget::t18f962e0b602b25173933adabf09c5e6 id_1141 { id_1140, dsum1_snd_132 };
                                                choose_res_1139 = id_1141;
                                              } else {
                                                uint16_t id_1142 { 1 };
                                                bool id_1143 { bool(dsum1_fst_131 == id_1142) };
                                                Void id_1144 { ((void)(assert(id_1143)), VOID) };
                                                (void)id_1144;
                                                (void)VOID;
                                                ::dessser::gen::dashboard_widget::tf285c6d4be19a8e3e994b3792fed4f11 id_1145 { std::in_place_index<1>, VOID };
                                                ::dessser::gen::dashboard_widget::t18f962e0b602b25173933adabf09c5e6 id_1146 { id_1145, dsum1_snd_132 };
                                                choose_res_1139 = id_1146;
                                              }
                                              letpair_res_1136 = choose_res_1139;
                                            }
                                            let_res_1135 = letpair_res_1136;
                                          }
                                          ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 letpair_res_1147;
                                          {
                                            auto drec_fst_140 { std::get<0>(let_res_1135) };
                                            auto drec_snd_141 { std::get<1>(let_res_1135) };
                                            ::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6 id_1148 { .force_zero = drec_fst_122, .left = drec_fst_116, .scale = drec_fst_140 };
                                            Lst<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> id_1149 { id_1148, dlist2_fst_110 };
                                            ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 id_1150 { id_1149, drec_snd_141 };
                                            letpair_res_1147 = id_1150;
                                          }
                                          letpair_res_1131 = letpair_res_1147;
                                        }
                                        let_res_1130 = letpair_res_1131;
                                      }
                                      letpair_res_1123 = let_res_1130;
                                    }
                                    let_res_1122 = letpair_res_1123;
                                  }
                                  Void id_1151 { ((void)(inits_src_ref_107[id_1115] = let_res_1122), VOID) };
                                  (void)id_1151;
                                }
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_1152 { 0 };
                              uint8_t id_1153 { 0 };
                              int32_t id_1154 { repeat_n_108[id_1153] };
                              int32_t id_1155 { 1L };
                              int32_t id_1156 { int32_t(id_1154 + id_1155) };
                              Void id_1157 { ((void)(repeat_n_108[id_1152] = id_1156), VOID) };
                              (void)id_1157;
                              (void)id_1157;
                            }
                          } while (while_flag_1108);
                          (void)VOID;
                        }
                        (void)VOID;
                        uint8_t id_1158 { 0 };
                        ::dessser::gen::dashboard_widget::t3784ecdaa5f49b38535148750595f444 id_1159 { inits_src_ref_107[id_1158] };
                        let_res_1105 = id_1159;
                      }
                      letpair_res_1101 = let_res_1105;
                    }
                    let_res_1100 = letpair_res_1101;
                  }
                  ::dessser::gen::dashboard_widget::tf10289c316edef0ccee1d3f2935b6a8c letpair_res_1160;
                  {
                    auto dlist4_fst_146 { std::get<0>(let_res_1100) };
                    auto dlist4_snd_147 { std::get<1>(let_res_1100) };
                    Arr<::dessser::gen::dashboard_widget::t7a73277e81021fc63d7d1b63bc3beba6> id_1161 { dlist4_fst_146.toListRev() };
                    ::dessser::gen::dashboard_widget::tf10289c316edef0ccee1d3f2935b6a8c id_1162 { id_1161, dlist4_snd_147 };
                    letpair_res_1160 = id_1162;
                  }
                  ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 let_res_1163;
                  {
                    ::dessser::gen::dashboard_widget::tf10289c316edef0ccee1d3f2935b6a8c drec_148 { letpair_res_1160 };
                    ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 letpair_res_1164;
                    {
                      auto drec_fst_149 { std::get<0>(drec_148) };
                      auto drec_snd_150 { std::get<1>(drec_148) };
                      uint32_t id_1165 { 0U };
                      Vec<1, uint32_t> id_1166 {  id_1165  };
                      ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1167;
                      {
                        Vec<1, uint32_t> leb_ref_151 { id_1166 };
                        uint8_t id_1168 { 0 };
                        Vec<1, uint8_t> id_1169 {  id_1168  };
                        ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1170;
                        {
                          Vec<1, uint8_t> shft_ref_152 { id_1169 };
                          Vec<1, Pointer> id_1171 {  drec_snd_150  };
                          ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1172;
                          {
                            Vec<1, Pointer> p_ref_153 { id_1171 };
                            bool while_flag_1173 { true };
                            do {
                              uint8_t id_1174 { 0 };
                              Pointer id_1175 { p_ref_153[id_1174] };
                              ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1176 { id_1175.readU8() };
                              bool let_res_1177;
                              {
                                ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 leb128_154 { id_1176 };
                                bool letpair_res_1178;
                                {
                                  auto leb128_fst_155 { std::get<0>(leb128_154) };
                                  auto leb128_snd_156 { std::get<1>(leb128_154) };
                                  uint8_t id_1179 { 0 };
                                  Void id_1180 { ((void)(p_ref_153[id_1179] = leb128_snd_156), VOID) };
                                  (void)id_1180;
                                  uint8_t id_1181 { 0 };
                                  uint8_t id_1182 { 127 };
                                  uint8_t id_1183 { uint8_t(leb128_fst_155 & id_1182) };
                                  uint32_t id_1184 { uint32_t(id_1183) };
                                  uint8_t id_1185 { 0 };
                                  uint8_t id_1186 { shft_ref_152[id_1185] };
                                  uint32_t id_1187 { uint32_t(id_1184 << id_1186) };
                                  uint8_t id_1188 { 0 };
                                  uint32_t id_1189 { leb_ref_151[id_1188] };
                                  uint32_t id_1190 { uint32_t(id_1187 | id_1189) };
                                  Void id_1191 { ((void)(leb_ref_151[id_1181] = id_1190), VOID) };
                                  (void)id_1191;
                                  uint8_t id_1192 { 0 };
                                  uint8_t id_1193 { 0 };
                                  uint8_t id_1194 { shft_ref_152[id_1193] };
                                  uint8_t id_1195 { 7 };
                                  uint8_t id_1196 { uint8_t(id_1194 + id_1195) };
                                  Void id_1197 { ((void)(shft_ref_152[id_1192] = id_1196), VOID) };
                                  (void)id_1197;
                                  uint8_t id_1198 { 128 };
                                  bool id_1199 { bool(leb128_fst_155 >= id_1198) };
                                  letpair_res_1178 = id_1199;
                                }
                                let_res_1177 = letpair_res_1178;
                              }
                              while_flag_1173 = let_res_1177;
                              if (while_flag_1173) {
                                (void)VOID;
                              }
                            } while (while_flag_1173);
                            (void)VOID;
                            uint8_t id_1200 { 0 };
                            uint32_t id_1201 { leb_ref_151[id_1200] };
                            uint8_t id_1202 { 0 };
                            Pointer id_1203 { p_ref_153[id_1202] };
                            ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 id_1204 { id_1201, id_1203 };
                            let_res_1172 = id_1204;
                          }
                          let_res_1170 = let_res_1172;
                        }
                        let_res_1167 = let_res_1170;
                      }
                      ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 let_res_1205;
                      {
                        ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 dlist1_160 { let_res_1167 };
                        ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 letpair_res_1206;
                        {
                          auto dlist1_fst_161 { std::get<0>(dlist1_160) };
                          auto dlist1_snd_162 { std::get<1>(dlist1_160) };
                          Lst<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> endoflist_1207;
                          ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 id_1208 { endoflist_1207, dlist1_snd_162 };
                          Vec<1, ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7> id_1209 {  id_1208  };
                          ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 let_res_1210;
                          {
                            Vec<1, ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7> inits_src_ref_163 { id_1209 };
                            int32_t id_1211 { 0L };
                            Vec<1, int32_t> id_1212 {  id_1211  };
                            {
                              Vec<1, int32_t> repeat_n_164 { id_1212 };
                              bool while_flag_1213 { true };
                              do {
                                int32_t id_1214 { int32_t(dlist1_fst_161) };
                                uint8_t id_1215 { 0 };
                                int32_t id_1216 { repeat_n_164[id_1215] };
                                bool id_1217 { bool(id_1214 > id_1216) };
                                while_flag_1213 = id_1217;
                                if (while_flag_1213) {
                                  uint8_t id_1218 { 0 };
                                  ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 id_1219 { inits_src_ref_163[id_1218] };
                                  {
                                    ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 dlist2_165 { id_1219 };
                                    {
                                      auto dlist2_fst_166 { std::get<0>(dlist2_165) };
                                      auto dlist2_snd_167 { std::get<1>(dlist2_165) };
                                      uint8_t id_1220 { 0 };
                                      auto fun1221 { dessser::gen::fq_function_name::of_row_binary };
                                      ::dessser::gen::dashboard_widget::taa97936972d3c557dfc41dd27d2203f0 id_1222 { fun1221(dlist2_snd_167) };
                                      ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 let_res_1223;
                                      {
                                        ::dessser::gen::dashboard_widget::taa97936972d3c557dfc41dd27d2203f0 drec_168 { id_1222 };
                                        ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 letpair_res_1224;
                                        {
                                          auto drec_fst_169 { std::get<0>(drec_168) };
                                          auto drec_snd_170 { std::get<1>(drec_168) };
                                          ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1225 { drec_snd_170.readU8() };
                                          ::dessser::gen::dashboard_widget::t4138de986e20d18b01e4c493dc9d5451 letpair_res_1226;
                                          {
                                            auto dbool_fst_172 { std::get<0>(id_1225) };
                                            auto dbool_snd_173 { std::get<1>(id_1225) };
                                            uint8_t id_1227 { 0 };
                                            bool id_1228 { bool(dbool_fst_172 == id_1227) };
                                            bool id_1229 { ! id_1228 };
                                            ::dessser::gen::dashboard_widget::t4138de986e20d18b01e4c493dc9d5451 id_1230 { id_1229, dbool_snd_173 };
                                            letpair_res_1226 = id_1230;
                                          }
                                          ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 let_res_1231;
                                          {
                                            ::dessser::gen::dashboard_widget::t4138de986e20d18b01e4c493dc9d5451 drec_174 { letpair_res_1226 };
                                            ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 letpair_res_1232;
                                            {
                                              auto drec_fst_175 { std::get<0>(drec_174) };
                                              auto drec_snd_176 { std::get<1>(drec_174) };
                                              uint32_t id_1233 { 0U };
                                              Vec<1, uint32_t> id_1234 {  id_1233  };
                                              ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1235;
                                              {
                                                Vec<1, uint32_t> leb_ref_177 { id_1234 };
                                                uint8_t id_1236 { 0 };
                                                Vec<1, uint8_t> id_1237 {  id_1236  };
                                                ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1238;
                                                {
                                                  Vec<1, uint8_t> shft_ref_178 { id_1237 };
                                                  Vec<1, Pointer> id_1239 {  drec_snd_176  };
                                                  ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1240;
                                                  {
                                                    Vec<1, Pointer> p_ref_179 { id_1239 };
                                                    bool while_flag_1241 { true };
                                                    do {
                                                      uint8_t id_1242 { 0 };
                                                      Pointer id_1243 { p_ref_179[id_1242] };
                                                      ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1244 { id_1243.readU8() };
                                                      bool let_res_1245;
                                                      {
                                                        ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 leb128_180 { id_1244 };
                                                        bool letpair_res_1246;
                                                        {
                                                          auto leb128_fst_181 { std::get<0>(leb128_180) };
                                                          auto leb128_snd_182 { std::get<1>(leb128_180) };
                                                          uint8_t id_1247 { 0 };
                                                          Void id_1248 { ((void)(p_ref_179[id_1247] = leb128_snd_182), VOID) };
                                                          (void)id_1248;
                                                          uint8_t id_1249 { 0 };
                                                          uint8_t id_1250 { 127 };
                                                          uint8_t id_1251 { uint8_t(leb128_fst_181 & id_1250) };
                                                          uint32_t id_1252 { uint32_t(id_1251) };
                                                          uint8_t id_1253 { 0 };
                                                          uint8_t id_1254 { shft_ref_178[id_1253] };
                                                          uint32_t id_1255 { uint32_t(id_1252 << id_1254) };
                                                          uint8_t id_1256 { 0 };
                                                          uint32_t id_1257 { leb_ref_177[id_1256] };
                                                          uint32_t id_1258 { uint32_t(id_1255 | id_1257) };
                                                          Void id_1259 { ((void)(leb_ref_177[id_1249] = id_1258), VOID) };
                                                          (void)id_1259;
                                                          uint8_t id_1260 { 0 };
                                                          uint8_t id_1261 { 0 };
                                                          uint8_t id_1262 { shft_ref_178[id_1261] };
                                                          uint8_t id_1263 { 7 };
                                                          uint8_t id_1264 { uint8_t(id_1262 + id_1263) };
                                                          Void id_1265 { ((void)(shft_ref_178[id_1260] = id_1264), VOID) };
                                                          (void)id_1265;
                                                          uint8_t id_1266 { 128 };
                                                          bool id_1267 { bool(leb128_fst_181 >= id_1266) };
                                                          letpair_res_1246 = id_1267;
                                                        }
                                                        let_res_1245 = letpair_res_1246;
                                                      }
                                                      while_flag_1241 = let_res_1245;
                                                      if (while_flag_1241) {
                                                        (void)VOID;
                                                      }
                                                    } while (while_flag_1241);
                                                    (void)VOID;
                                                    uint8_t id_1268 { 0 };
                                                    uint32_t id_1269 { leb_ref_177[id_1268] };
                                                    uint8_t id_1270 { 0 };
                                                    Pointer id_1271 { p_ref_179[id_1270] };
                                                    ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 id_1272 { id_1269, id_1271 };
                                                    let_res_1240 = id_1272;
                                                  }
                                                  let_res_1238 = let_res_1240;
                                                }
                                                let_res_1235 = let_res_1238;
                                              }
                                              ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 let_res_1273;
                                              {
                                                ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 dlist1_186 { let_res_1235 };
                                                ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 letpair_res_1274;
                                                {
                                                  auto dlist1_fst_187 { std::get<0>(dlist1_186) };
                                                  auto dlist1_snd_188 { std::get<1>(dlist1_186) };
                                                  Lst<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> endoflist_1275;
                                                  ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 id_1276 { endoflist_1275, dlist1_snd_188 };
                                                  Vec<1, ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827> id_1277 {  id_1276  };
                                                  ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 let_res_1278;
                                                  {
                                                    Vec<1, ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827> inits_src_ref_189 { id_1277 };
                                                    int32_t id_1279 { 0L };
                                                    Vec<1, int32_t> id_1280 {  id_1279  };
                                                    {
                                                      Vec<1, int32_t> repeat_n_190 { id_1280 };
                                                      bool while_flag_1281 { true };
                                                      do {
                                                        int32_t id_1282 { int32_t(dlist1_fst_187) };
                                                        uint8_t id_1283 { 0 };
                                                        int32_t id_1284 { repeat_n_190[id_1283] };
                                                        bool id_1285 { bool(id_1282 > id_1284) };
                                                        while_flag_1281 = id_1285;
                                                        if (while_flag_1281) {
                                                          uint8_t id_1286 { 0 };
                                                          ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 id_1287 { inits_src_ref_189[id_1286] };
                                                          {
                                                            ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 dlist2_191 { id_1287 };
                                                            {
                                                              auto dlist2_fst_192 { std::get<0>(dlist2_191) };
                                                              auto dlist2_snd_193 { std::get<1>(dlist2_191) };
                                                              uint8_t id_1288 { 0 };
                                                              ::dessser::gen::dashboard_widget::t7a47220550fc5126a7b79f1e0c10c645 id_1289 { dlist2_snd_193.readU64Le() };
                                                              ::dessser::gen::dashboard_widget::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_1290;
                                                              {
                                                                auto dfloat_fst_195 { std::get<0>(id_1289) };
                                                                auto dfloat_snd_196 { std::get<1>(id_1289) };
                                                                double id_1291 { float_of_qword(dfloat_fst_195) };
                                                                ::dessser::gen::dashboard_widget::taebed00ad7fdb3f7ced11d3cfd58aade id_1292 { id_1291, dfloat_snd_196 };
                                                                letpair_res_1290 = id_1292;
                                                              }
                                                              ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 let_res_1293;
                                                              {
                                                                ::dessser::gen::dashboard_widget::taebed00ad7fdb3f7ced11d3cfd58aade drec_197 { letpair_res_1290 };
                                                                ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 letpair_res_1294;
                                                                {
                                                                  auto drec_fst_198 { std::get<0>(drec_197) };
                                                                  auto drec_snd_199 { std::get<1>(drec_197) };
                                                                  ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 id_1295 { drec_snd_199.readU32Le() };
                                                                  ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 letpair_res_1296;
                                                                  {
                                                                    auto du32_fst_201 { std::get<0>(id_1295) };
                                                                    auto du32_snd_202 { std::get<1>(id_1295) };
                                                                    ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 id_1297 { du32_fst_201, du32_snd_202 };
                                                                    letpair_res_1296 = id_1297;
                                                                  }
                                                                  ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 let_res_1298;
                                                                  {
                                                                    ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 drec_203 { letpair_res_1296 };
                                                                    ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 letpair_res_1299;
                                                                    {
                                                                      auto drec_fst_204 { std::get<0>(drec_203) };
                                                                      auto drec_snd_205 { std::get<1>(drec_203) };
                                                                      ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 id_1300 { drec_snd_205.readU16Le() };
                                                                      ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1301;
                                                                      {
                                                                        auto du16_fst_207 { std::get<0>(id_1300) };
                                                                        auto du16_snd_208 { std::get<1>(id_1300) };
                                                                        ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 id_1302 { du16_fst_207, du16_snd_208 };
                                                                        letpair_res_1301 = id_1302;
                                                                      }
                                                                      ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 let_res_1303;
                                                                      {
                                                                        ::dessser::gen::dashboard_widget::t22a32080ad88ab548b80077a17b7dd46 dsum1_212 { letpair_res_1301 };
                                                                        ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 letpair_res_1304;
                                                                        {
                                                                          auto dsum1_fst_213 { std::get<0>(dsum1_212) };
                                                                          auto dsum1_snd_214 { std::get<1>(dsum1_212) };
                                                                          uint16_t id_1305 { 0 };
                                                                          bool id_1306 { bool(id_1305 == dsum1_fst_213) };
                                                                          ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 choose_res_1307;
                                                                          if (id_1306) {
                                                                            (void)VOID;
                                                                            ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_1308 { std::in_place_index<0>, VOID };
                                                                            ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 id_1309 { id_1308, dsum1_snd_214 };
                                                                            choose_res_1307 = id_1309;
                                                                          } else {
                                                                            uint16_t id_1310 { 1 };
                                                                            bool id_1311 { bool(id_1310 == dsum1_fst_213) };
                                                                            ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 choose_res_1312;
                                                                            if (id_1311) {
                                                                              (void)VOID;
                                                                              ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_1313 { std::in_place_index<1>, VOID };
                                                                              ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 id_1314 { id_1313, dsum1_snd_214 };
                                                                              choose_res_1312 = id_1314;
                                                                            } else {
                                                                              uint16_t id_1315 { 2 };
                                                                              bool id_1316 { bool(id_1315 == dsum1_fst_213) };
                                                                              ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 choose_res_1317;
                                                                              if (id_1316) {
                                                                                (void)VOID;
                                                                                ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_1318 { std::in_place_index<2>, VOID };
                                                                                ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 id_1319 { id_1318, dsum1_snd_214 };
                                                                                choose_res_1317 = id_1319;
                                                                              } else {
                                                                                uint16_t id_1320 { 3 };
                                                                                bool id_1321 { bool(dsum1_fst_213 == id_1320) };
                                                                                Void id_1322 { ((void)(assert(id_1321)), VOID) };
                                                                                (void)id_1322;
                                                                                (void)VOID;
                                                                                ::dessser::gen::dashboard_widget::tc758d36a6b58d564436d5e1104817704 id_1323 { std::in_place_index<3>, VOID };
                                                                                ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 id_1324 { id_1323, dsum1_snd_214 };
                                                                                choose_res_1317 = id_1324;
                                                                              }
                                                                              choose_res_1312 = choose_res_1317;
                                                                            }
                                                                            choose_res_1307 = choose_res_1312;
                                                                          }
                                                                          letpair_res_1304 = choose_res_1307;
                                                                        }
                                                                        let_res_1303 = letpair_res_1304;
                                                                      }
                                                                      ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 let_res_1325;
                                                                      {
                                                                        ::dessser::gen::dashboard_widget::t456f791d00acb0124553dcfd0d592389 drec_227 { let_res_1303 };
                                                                        ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 letpair_res_1326;
                                                                        {
                                                                          auto drec_fst_228 { std::get<0>(drec_227) };
                                                                          auto drec_snd_229 { std::get<1>(drec_227) };
                                                                          uint32_t id_1327 { 0U };
                                                                          Vec<1, uint32_t> id_1328 {  id_1327  };
                                                                          ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_1329;
                                                                          {
                                                                            Vec<1, uint32_t> leb_ref_230 { id_1328 };
                                                                            uint8_t id_1330 { 0 };
                                                                            Vec<1, uint8_t> id_1331 {  id_1330  };
                                                                            ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_1332;
                                                                            {
                                                                              Vec<1, uint8_t> shft_ref_231 { id_1331 };
                                                                              Vec<1, Pointer> id_1333 {  drec_snd_229  };
                                                                              ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_1334;
                                                                              {
                                                                                Vec<1, Pointer> p_ref_232 { id_1333 };
                                                                                bool while_flag_1335 { true };
                                                                                do {
                                                                                  uint8_t id_1336 { 0 };
                                                                                  Pointer id_1337 { p_ref_232[id_1336] };
                                                                                  ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1338 { id_1337.readU8() };
                                                                                  bool let_res_1339;
                                                                                  {
                                                                                    ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 leb128_233 { id_1338 };
                                                                                    bool letpair_res_1340;
                                                                                    {
                                                                                      auto leb128_fst_234 { std::get<0>(leb128_233) };
                                                                                      auto leb128_snd_235 { std::get<1>(leb128_233) };
                                                                                      uint8_t id_1341 { 0 };
                                                                                      Void id_1342 { ((void)(p_ref_232[id_1341] = leb128_snd_235), VOID) };
                                                                                      (void)id_1342;
                                                                                      uint8_t id_1343 { 0 };
                                                                                      uint8_t id_1344 { 127 };
                                                                                      uint8_t id_1345 { uint8_t(leb128_fst_234 & id_1344) };
                                                                                      uint32_t id_1346 { uint32_t(id_1345) };
                                                                                      uint8_t id_1347 { 0 };
                                                                                      uint8_t id_1348 { shft_ref_231[id_1347] };
                                                                                      uint32_t id_1349 { uint32_t(id_1346 << id_1348) };
                                                                                      uint8_t id_1350 { 0 };
                                                                                      uint32_t id_1351 { leb_ref_230[id_1350] };
                                                                                      uint32_t id_1352 { uint32_t(id_1349 | id_1351) };
                                                                                      Void id_1353 { ((void)(leb_ref_230[id_1343] = id_1352), VOID) };
                                                                                      (void)id_1353;
                                                                                      uint8_t id_1354 { 0 };
                                                                                      uint8_t id_1355 { 0 };
                                                                                      uint8_t id_1356 { shft_ref_231[id_1355] };
                                                                                      uint8_t id_1357 { 7 };
                                                                                      uint8_t id_1358 { uint8_t(id_1356 + id_1357) };
                                                                                      Void id_1359 { ((void)(shft_ref_231[id_1354] = id_1358), VOID) };
                                                                                      (void)id_1359;
                                                                                      uint8_t id_1360 { 128 };
                                                                                      bool id_1361 { bool(leb128_fst_234 >= id_1360) };
                                                                                      letpair_res_1340 = id_1361;
                                                                                    }
                                                                                    let_res_1339 = letpair_res_1340;
                                                                                  }
                                                                                  while_flag_1335 = let_res_1339;
                                                                                  if (while_flag_1335) {
                                                                                    (void)VOID;
                                                                                  }
                                                                                } while (while_flag_1335);
                                                                                (void)VOID;
                                                                                uint8_t id_1362 { 0 };
                                                                                uint32_t id_1363 { leb_ref_230[id_1362] };
                                                                                Size id_1364 { Size(id_1363) };
                                                                                uint8_t id_1365 { 0 };
                                                                                Pointer id_1366 { p_ref_232[id_1365] };
                                                                                ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c id_1367 { id_1364, id_1366 };
                                                                                let_res_1334 = id_1367;
                                                                              }
                                                                              let_res_1332 = let_res_1334;
                                                                            }
                                                                            let_res_1329 = let_res_1332;
                                                                          }
                                                                          ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e let_res_1368;
                                                                          {
                                                                            ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c dstring1_236 { let_res_1329 };
                                                                            ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1369;
                                                                            {
                                                                              auto dstring1_fst_237 { std::get<0>(dstring1_236) };
                                                                              auto dstring1_snd_238 { std::get<1>(dstring1_236) };
                                                                              ::dessser::gen::dashboard_widget::t188345aa49abd0cb47ff73fedc219f08 id_1370 { dstring1_snd_238.readBytes(dstring1_fst_237) };
                                                                              ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1371;
                                                                              {
                                                                                auto dstring2_fst_240 { std::get<0>(id_1370) };
                                                                                auto dstring2_snd_241 { std::get<1>(id_1370) };
                                                                                std::string id_1372 { dstring2_fst_240.toString() };
                                                                                ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e id_1373 { id_1372, dstring2_snd_241 };
                                                                                letpair_res_1371 = id_1373;
                                                                              }
                                                                              letpair_res_1369 = letpair_res_1371;
                                                                            }
                                                                            let_res_1368 = letpair_res_1369;
                                                                          }
                                                                          ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 let_res_1374;
                                                                          {
                                                                            ::dessser::gen::dashboard_widget::tef94b55d8809251f13165d9a05bd9d0e drec_242 { let_res_1368 };
                                                                            ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 letpair_res_1375;
                                                                            {
                                                                              auto drec_fst_243 { std::get<0>(drec_242) };
                                                                              auto drec_snd_244 { std::get<1>(drec_242) };
                                                                              uint32_t id_1376 { 0U };
                                                                              Vec<1, uint32_t> id_1377 {  id_1376  };
                                                                              ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1378;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_245 { id_1377 };
                                                                                uint8_t id_1379 { 0 };
                                                                                Vec<1, uint8_t> id_1380 {  id_1379  };
                                                                                ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1381;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_246 { id_1380 };
                                                                                  Vec<1, Pointer> id_1382 {  drec_snd_244  };
                                                                                  ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 let_res_1383;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_247 { id_1382 };
                                                                                    bool while_flag_1384 { true };
                                                                                    do {
                                                                                      uint8_t id_1385 { 0 };
                                                                                      Pointer id_1386 { p_ref_247[id_1385] };
                                                                                      ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1387 { id_1386.readU8() };
                                                                                      bool let_res_1388;
                                                                                      {
                                                                                        ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 leb128_248 { id_1387 };
                                                                                        bool letpair_res_1389;
                                                                                        {
                                                                                          auto leb128_fst_249 { std::get<0>(leb128_248) };
                                                                                          auto leb128_snd_250 { std::get<1>(leb128_248) };
                                                                                          uint8_t id_1390 { 0 };
                                                                                          Void id_1391 { ((void)(p_ref_247[id_1390] = leb128_snd_250), VOID) };
                                                                                          (void)id_1391;
                                                                                          uint8_t id_1392 { 0 };
                                                                                          uint8_t id_1393 { 127 };
                                                                                          uint8_t id_1394 { uint8_t(leb128_fst_249 & id_1393) };
                                                                                          uint32_t id_1395 { uint32_t(id_1394) };
                                                                                          uint8_t id_1396 { 0 };
                                                                                          uint8_t id_1397 { shft_ref_246[id_1396] };
                                                                                          uint32_t id_1398 { uint32_t(id_1395 << id_1397) };
                                                                                          uint8_t id_1399 { 0 };
                                                                                          uint32_t id_1400 { leb_ref_245[id_1399] };
                                                                                          uint32_t id_1401 { uint32_t(id_1398 | id_1400) };
                                                                                          Void id_1402 { ((void)(leb_ref_245[id_1392] = id_1401), VOID) };
                                                                                          (void)id_1402;
                                                                                          uint8_t id_1403 { 0 };
                                                                                          uint8_t id_1404 { 0 };
                                                                                          uint8_t id_1405 { shft_ref_246[id_1404] };
                                                                                          uint8_t id_1406 { 7 };
                                                                                          uint8_t id_1407 { uint8_t(id_1405 + id_1406) };
                                                                                          Void id_1408 { ((void)(shft_ref_246[id_1403] = id_1407), VOID) };
                                                                                          (void)id_1408;
                                                                                          uint8_t id_1409 { 128 };
                                                                                          bool id_1410 { bool(leb128_fst_249 >= id_1409) };
                                                                                          letpair_res_1389 = id_1410;
                                                                                        }
                                                                                        let_res_1388 = letpair_res_1389;
                                                                                      }
                                                                                      while_flag_1384 = let_res_1388;
                                                                                      if (while_flag_1384) {
                                                                                        (void)VOID;
                                                                                      }
                                                                                    } while (while_flag_1384);
                                                                                    (void)VOID;
                                                                                    uint8_t id_1411 { 0 };
                                                                                    uint32_t id_1412 { leb_ref_245[id_1411] };
                                                                                    uint8_t id_1413 { 0 };
                                                                                    Pointer id_1414 { p_ref_247[id_1413] };
                                                                                    ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 id_1415 { id_1412, id_1414 };
                                                                                    let_res_1383 = id_1415;
                                                                                  }
                                                                                  let_res_1381 = let_res_1383;
                                                                                }
                                                                                let_res_1378 = let_res_1381;
                                                                              }
                                                                              ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 let_res_1416;
                                                                              {
                                                                                ::dessser::gen::dashboard_widget::t405eb186408556fed8f2c41523c07d13 dlist1_254 { let_res_1378 };
                                                                                ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 letpair_res_1417;
                                                                                {
                                                                                  auto dlist1_fst_255 { std::get<0>(dlist1_254) };
                                                                                  auto dlist1_snd_256 { std::get<1>(dlist1_254) };
                                                                                  Lst<std::string> endoflist_1418;
                                                                                  ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 id_1419 { endoflist_1418, dlist1_snd_256 };
                                                                                  Vec<1, ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1> id_1420 {  id_1419  };
                                                                                  ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 let_res_1421;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1> inits_src_ref_257 { id_1420 };
                                                                                    int32_t id_1422 { 0L };
                                                                                    Vec<1, int32_t> id_1423 {  id_1422  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_258 { id_1423 };
                                                                                      bool while_flag_1424 { true };
                                                                                      do {
                                                                                        int32_t id_1425 { int32_t(dlist1_fst_255) };
                                                                                        uint8_t id_1426 { 0 };
                                                                                        int32_t id_1427 { repeat_n_258[id_1426] };
                                                                                        bool id_1428 { bool(id_1425 > id_1427) };
                                                                                        while_flag_1424 = id_1428;
                                                                                        if (while_flag_1424) {
                                                                                          uint8_t id_1429 { 0 };
                                                                                          ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 id_1430 { inits_src_ref_257[id_1429] };
                                                                                          {
                                                                                            ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 dlist2_259 { id_1430 };
                                                                                            {
                                                                                              auto dlist2_fst_260 { std::get<0>(dlist2_259) };
                                                                                              auto dlist2_snd_261 { std::get<1>(dlist2_259) };
                                                                                              uint8_t id_1431 { 0 };
                                                                                              uint32_t id_1432 { 0U };
                                                                                              Vec<1, uint32_t> id_1433 {  id_1432  };
                                                                                              ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_1434;
                                                                                              {
                                                                                                Vec<1, uint32_t> leb_ref_262 { id_1433 };
                                                                                                uint8_t id_1435 { 0 };
                                                                                                Vec<1, uint8_t> id_1436 {  id_1435  };
                                                                                                ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_1437;
                                                                                                {
                                                                                                  Vec<1, uint8_t> shft_ref_263 { id_1436 };
                                                                                                  Vec<1, Pointer> id_1438 {  dlist2_snd_261  };
                                                                                                  ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c let_res_1439;
                                                                                                  {
                                                                                                    Vec<1, Pointer> p_ref_264 { id_1438 };
                                                                                                    bool while_flag_1440 { true };
                                                                                                    do {
                                                                                                      uint8_t id_1441 { 0 };
                                                                                                      Pointer id_1442 { p_ref_264[id_1441] };
                                                                                                      ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1443 { id_1442.readU8() };
                                                                                                      bool let_res_1444;
                                                                                                      {
                                                                                                        ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 leb128_265 { id_1443 };
                                                                                                        bool letpair_res_1445;
                                                                                                        {
                                                                                                          auto leb128_fst_266 { std::get<0>(leb128_265) };
                                                                                                          auto leb128_snd_267 { std::get<1>(leb128_265) };
                                                                                                          uint8_t id_1446 { 0 };
                                                                                                          Void id_1447 { ((void)(p_ref_264[id_1446] = leb128_snd_267), VOID) };
                                                                                                          (void)id_1447;
                                                                                                          uint8_t id_1448 { 0 };
                                                                                                          uint8_t id_1449 { 127 };
                                                                                                          uint8_t id_1450 { uint8_t(leb128_fst_266 & id_1449) };
                                                                                                          uint32_t id_1451 { uint32_t(id_1450) };
                                                                                                          uint8_t id_1452 { 0 };
                                                                                                          uint8_t id_1453 { shft_ref_263[id_1452] };
                                                                                                          uint32_t id_1454 { uint32_t(id_1451 << id_1453) };
                                                                                                          uint8_t id_1455 { 0 };
                                                                                                          uint32_t id_1456 { leb_ref_262[id_1455] };
                                                                                                          uint32_t id_1457 { uint32_t(id_1454 | id_1456) };
                                                                                                          Void id_1458 { ((void)(leb_ref_262[id_1448] = id_1457), VOID) };
                                                                                                          (void)id_1458;
                                                                                                          uint8_t id_1459 { 0 };
                                                                                                          uint8_t id_1460 { 0 };
                                                                                                          uint8_t id_1461 { shft_ref_263[id_1460] };
                                                                                                          uint8_t id_1462 { 7 };
                                                                                                          uint8_t id_1463 { uint8_t(id_1461 + id_1462) };
                                                                                                          Void id_1464 { ((void)(shft_ref_263[id_1459] = id_1463), VOID) };
                                                                                                          (void)id_1464;
                                                                                                          uint8_t id_1465 { 128 };
                                                                                                          bool id_1466 { bool(leb128_fst_266 >= id_1465) };
                                                                                                          letpair_res_1445 = id_1466;
                                                                                                        }
                                                                                                        let_res_1444 = letpair_res_1445;
                                                                                                      }
                                                                                                      while_flag_1440 = let_res_1444;
                                                                                                      if (while_flag_1440) {
                                                                                                        (void)VOID;
                                                                                                      }
                                                                                                    } while (while_flag_1440);
                                                                                                    (void)VOID;
                                                                                                    uint8_t id_1467 { 0 };
                                                                                                    uint32_t id_1468 { leb_ref_262[id_1467] };
                                                                                                    Size id_1469 { Size(id_1468) };
                                                                                                    uint8_t id_1470 { 0 };
                                                                                                    Pointer id_1471 { p_ref_264[id_1470] };
                                                                                                    ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c id_1472 { id_1469, id_1471 };
                                                                                                    let_res_1439 = id_1472;
                                                                                                  }
                                                                                                  let_res_1437 = let_res_1439;
                                                                                                }
                                                                                                let_res_1434 = let_res_1437;
                                                                                              }
                                                                                              ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 let_res_1473;
                                                                                              {
                                                                                                ::dessser::gen::dashboard_widget::t8beb80162423aee37bd383e9b6834c9c dstring1_268 { let_res_1434 };
                                                                                                ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 letpair_res_1474;
                                                                                                {
                                                                                                  auto dstring1_fst_269 { std::get<0>(dstring1_268) };
                                                                                                  auto dstring1_snd_270 { std::get<1>(dstring1_268) };
                                                                                                  ::dessser::gen::dashboard_widget::t188345aa49abd0cb47ff73fedc219f08 id_1475 { dstring1_snd_270.readBytes(dstring1_fst_269) };
                                                                                                  ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 letpair_res_1476;
                                                                                                  {
                                                                                                    auto dstring2_fst_272 { std::get<0>(id_1475) };
                                                                                                    auto dstring2_snd_273 { std::get<1>(id_1475) };
                                                                                                    std::string id_1477 { dstring2_fst_272.toString() };
                                                                                                    Lst<std::string> id_1478 { id_1477, dlist2_fst_260 };
                                                                                                    ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 id_1479 { id_1478, dstring2_snd_273 };
                                                                                                    letpair_res_1476 = id_1479;
                                                                                                  }
                                                                                                  letpair_res_1474 = letpair_res_1476;
                                                                                                }
                                                                                                let_res_1473 = letpair_res_1474;
                                                                                              }
                                                                                              Void id_1480 { ((void)(inits_src_ref_257[id_1431] = let_res_1473), VOID) };
                                                                                              (void)id_1480;
                                                                                            }
                                                                                            (void)VOID;
                                                                                          }
                                                                                          (void)VOID;
                                                                                          uint8_t id_1481 { 0 };
                                                                                          uint8_t id_1482 { 0 };
                                                                                          int32_t id_1483 { repeat_n_258[id_1482] };
                                                                                          int32_t id_1484 { 1L };
                                                                                          int32_t id_1485 { int32_t(id_1483 + id_1484) };
                                                                                          Void id_1486 { ((void)(repeat_n_258[id_1481] = id_1485), VOID) };
                                                                                          (void)id_1486;
                                                                                          (void)id_1486;
                                                                                        }
                                                                                      } while (while_flag_1424);
                                                                                      (void)VOID;
                                                                                    }
                                                                                    (void)VOID;
                                                                                    uint8_t id_1487 { 0 };
                                                                                    ::dessser::gen::dashboard_widget::ta48cca69b6e077e610d35192824cedc1 id_1488 { inits_src_ref_257[id_1487] };
                                                                                    let_res_1421 = id_1488;
                                                                                  }
                                                                                  letpair_res_1417 = let_res_1421;
                                                                                }
                                                                                let_res_1416 = letpair_res_1417;
                                                                              }
                                                                              ::dessser::gen::dashboard_widget::t1beb4adb76e17aefcfb1b276e44e61db letpair_res_1489;
                                                                              {
                                                                                auto dlist4_fst_278 { std::get<0>(let_res_1416) };
                                                                                auto dlist4_snd_279 { std::get<1>(let_res_1416) };
                                                                                Arr<std::string> id_1490 { dlist4_fst_278.toListRev() };
                                                                                ::dessser::gen::dashboard_widget::t1beb4adb76e17aefcfb1b276e44e61db id_1491 { id_1490, dlist4_snd_279 };
                                                                                letpair_res_1489 = id_1491;
                                                                              }
                                                                              ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 let_res_1492;
                                                                              {
                                                                                ::dessser::gen::dashboard_widget::t1beb4adb76e17aefcfb1b276e44e61db drec_280 { letpair_res_1489 };
                                                                                ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 letpair_res_1493;
                                                                                {
                                                                                  auto drec_fst_281 { std::get<0>(drec_280) };
                                                                                  auto drec_snd_282 { std::get<1>(drec_280) };
                                                                                  ::dessser::gen::dashboard_widget::tb3f98ea670610d40658a618de3ec7b90 id_1494 { drec_snd_282.readU8() };
                                                                                  ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 letpair_res_1495;
                                                                                  {
                                                                                    auto du8_fst_284 { std::get<0>(id_1494) };
                                                                                    auto du8_snd_285 { std::get<1>(id_1494) };
                                                                                    ::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82 id_1496 { .axis = du8_fst_284, .color = drec_fst_204, .column = drec_fst_243, .factors = drec_fst_281, .opacity = drec_fst_198, .representation = drec_fst_228 };
                                                                                    Lst<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_1497 { id_1496, dlist2_fst_192 };
                                                                                    ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 id_1498 { id_1497, du8_snd_285 };
                                                                                    letpair_res_1495 = id_1498;
                                                                                  }
                                                                                  letpair_res_1493 = letpair_res_1495;
                                                                                }
                                                                                let_res_1492 = letpair_res_1493;
                                                                              }
                                                                              letpair_res_1375 = let_res_1492;
                                                                            }
                                                                            let_res_1374 = letpair_res_1375;
                                                                          }
                                                                          letpair_res_1326 = let_res_1374;
                                                                        }
                                                                        let_res_1325 = letpair_res_1326;
                                                                      }
                                                                      letpair_res_1299 = let_res_1325;
                                                                    }
                                                                    let_res_1298 = letpair_res_1299;
                                                                  }
                                                                  letpair_res_1294 = let_res_1298;
                                                                }
                                                                let_res_1293 = letpair_res_1294;
                                                              }
                                                              Void id_1499 { ((void)(inits_src_ref_189[id_1288] = let_res_1293), VOID) };
                                                              (void)id_1499;
                                                            }
                                                            (void)VOID;
                                                          }
                                                          (void)VOID;
                                                          uint8_t id_1500 { 0 };
                                                          uint8_t id_1501 { 0 };
                                                          int32_t id_1502 { repeat_n_190[id_1501] };
                                                          int32_t id_1503 { 1L };
                                                          int32_t id_1504 { int32_t(id_1502 + id_1503) };
                                                          Void id_1505 { ((void)(repeat_n_190[id_1500] = id_1504), VOID) };
                                                          (void)id_1505;
                                                          (void)id_1505;
                                                        }
                                                      } while (while_flag_1281);
                                                      (void)VOID;
                                                    }
                                                    (void)VOID;
                                                    uint8_t id_1506 { 0 };
                                                    ::dessser::gen::dashboard_widget::ta52af46a94c77315ad8bf6f31a04f827 id_1507 { inits_src_ref_189[id_1506] };
                                                    let_res_1278 = id_1507;
                                                  }
                                                  letpair_res_1274 = let_res_1278;
                                                }
                                                let_res_1273 = letpair_res_1274;
                                              }
                                              ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 letpair_res_1508;
                                              {
                                                auto dlist4_fst_293 { std::get<0>(let_res_1273) };
                                                auto dlist4_snd_294 { std::get<1>(let_res_1273) };
                                                Arr<::dessser::gen::dashboard_widget::t4014451f4abcdfd5489869fefe1eca82> id_1509 { dlist4_fst_293.toListRev() };
                                                ::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225 id_1510 { .fields = id_1509, .name = drec_fst_169, .visible = drec_fst_175 };
                                                Lst<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_1511 { id_1510, dlist2_fst_166 };
                                                ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 id_1512 { id_1511, dlist4_snd_294 };
                                                letpair_res_1508 = id_1512;
                                              }
                                              letpair_res_1232 = letpair_res_1508;
                                            }
                                            let_res_1231 = letpair_res_1232;
                                          }
                                          letpair_res_1224 = let_res_1231;
                                        }
                                        let_res_1223 = letpair_res_1224;
                                      }
                                      Void id_1513 { ((void)(inits_src_ref_163[id_1220] = let_res_1223), VOID) };
                                      (void)id_1513;
                                    }
                                    (void)VOID;
                                  }
                                  (void)VOID;
                                  uint8_t id_1514 { 0 };
                                  uint8_t id_1515 { 0 };
                                  int32_t id_1516 { repeat_n_164[id_1515] };
                                  int32_t id_1517 { 1L };
                                  int32_t id_1518 { int32_t(id_1516 + id_1517) };
                                  Void id_1519 { ((void)(repeat_n_164[id_1514] = id_1518), VOID) };
                                  (void)id_1519;
                                  (void)id_1519;
                                }
                              } while (while_flag_1213);
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_1520 { 0 };
                            ::dessser::gen::dashboard_widget::t53474d2cd1155389586730a26f802ec7 id_1521 { inits_src_ref_163[id_1520] };
                            let_res_1210 = id_1521;
                          }
                          letpair_res_1206 = let_res_1210;
                        }
                        let_res_1205 = letpair_res_1206;
                      }
                      ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 letpair_res_1522;
                      {
                        auto dlist4_fst_302 { std::get<0>(let_res_1205) };
                        auto dlist4_snd_303 { std::get<1>(let_res_1205) };
                        Arr<::dessser::gen::dashboard_widget::t79826a59cc1e8c45c3ad94e8417c3225> id_1523 { dlist4_fst_302.toListRev() };
                        ::dessser::gen::dashboard_widget::ta3280375be63ffe37d86976d93bf0304 id_1524 { .Chart_axis = drec_fst_149, .sources = id_1523, .title = drec_fst_78, .type = drec_fst_93 };
                        ::dessser::gen::dashboard_widget::t* id_1525 { new ::dessser::gen::dashboard_widget::t(std::in_place_index<1>, id_1524) };
                        ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 id_1526 { id_1525, dlist4_snd_303 };
                        letpair_res_1522 = id_1526;
                      }
                      letpair_res_1164 = letpair_res_1522;
                    }
                    let_res_1163 = letpair_res_1164;
                  }
                  letpair_res_1059 = let_res_1163;
                }
                let_res_1058 = letpair_res_1059;
              }
              letpair_res_1047 = let_res_1058;
            }
            let_res_1046 = letpair_res_1047;
          }
          choose_res_947 = let_res_1046;
        }
        letpair_res_944 = choose_res_947;
      }
      let_res_943 = letpair_res_944;
    }
    ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 letpair_res_1527;
    {
      auto make_fst_326 { std::get<0>(let_res_943) };
      auto make_snd_327 { std::get<1>(let_res_943) };
      ::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1 id_1528 { make_fst_326, make_snd_327 };
      letpair_res_1527 = id_1528;
    }
    return letpair_res_1527;
  }
   };
  return fun939;
}
std::function<::dessser::gen::dashboard_widget::t1a99c61debfb8ac5db5347b1cf1a79d1(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
