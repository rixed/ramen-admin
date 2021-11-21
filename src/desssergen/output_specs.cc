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
#include "desssergen/sync_key.h"
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
> {
  using tuple::tuple;
};
struct t55234e0caf6cba9a33ddd852496b1d7b {
  uint32_t batch_size;
  uint32_t num_batches;
  bool with_index;
  t55234e0caf6cba9a33ddd852496b1d7b(uint32_t batch_size_, uint32_t num_batches_, bool with_index_) : batch_size(batch_size_), num_batches(num_batches_), with_index(with_index_) {}
  t55234e0caf6cba9a33ddd852496b1d7b() = default;
};
struct file_type : public std::variant<
  Void, // RingBuf
  ::dessser::gen::output_specs::t55234e0caf6cba9a33ddd852496b1d7b // Orc
> { using variant::variant; };

struct recipient : public std::variant<
  dessser::gen::file_path::t_ext, // DirectFile
  std::string, // IndirectFile
  dessser::gen::sync_key::t_ext // SyncKey
> { using variant::variant; };

struct t784c9e092e6dc8e0c9c5fd1cc3093085 : public std::tuple<
  uint16_t,
  std::shared_ptr<::dessser::gen::output_specs::channel_specs> 
> {
  using tuple::tuple;
  t784c9e092e6dc8e0c9c5fd1cc3093085(std::tuple<uint16_t, std::shared_ptr<::dessser::gen::output_specs::channel_specs> > p)
    : std::tuple<uint16_t, std::shared_ptr<::dessser::gen::output_specs::channel_specs> >(std::get<0>(p), std::get<1>(p)) {}
};
struct t0b14edd3739ead719254746b30f1350c : public std::tuple<
  uint16_t,
  Arr<dessser::gen::raql_value::t_ext>
> {
  using tuple::tuple;
  t0b14edd3739ead719254746b30f1350c(std::tuple<uint16_t, Arr<dessser::gen::raql_value::t_ext>> p)
    : std::tuple<uint16_t, Arr<dessser::gen::raql_value::t_ext>>(std::get<0>(p), std::get<1>(p)) {}
};
struct td4b276c89163d76d7a872961502751f6 {
  Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> channels;
  dessser::gen::fieldmask::t_ext fieldmask;
  std::shared_ptr<::dessser::gen::output_specs::file_type>  file_type;
  Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> filters;
  td4b276c89163d76d7a872961502751f6(Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> channels_, dessser::gen::fieldmask::t_ext fieldmask_, std::shared_ptr<::dessser::gen::output_specs::file_type>  file_type_, Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> filters_) : channels(channels_), fieldmask(fieldmask_), file_type(file_type_), filters(filters_) {}
  td4b276c89163d76d7a872961502751f6() = default;
};
struct tba04231272fbebb3d3653fbc82bc2eee : public std::tuple<
  std::shared_ptr<::dessser::gen::output_specs::recipient> ,
  ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6
> {
  using tuple::tuple;
  tba04231272fbebb3d3653fbc82bc2eee(std::tuple<std::shared_ptr<::dessser::gen::output_specs::recipient> , ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6> p)
    : std::tuple<std::shared_ptr<::dessser::gen::output_specs::recipient> , ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6>(std::get<0>(p), std::get<1>(p)) {}
};
typedef Arr<::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee> t;
struct t092f0ef972407382249d7ed7a5dafaca : public std::tuple<
  std::shared_ptr<::dessser::gen::output_specs::channel_specs> ,
  Pointer
> {
  using tuple::tuple;
  t092f0ef972407382249d7ed7a5dafaca(std::tuple<std::shared_ptr<::dessser::gen::output_specs::channel_specs> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::output_specs::channel_specs> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
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
struct tb196bf1fcefaf5153b7e0f5e479aaa96 : public std::tuple<
  int16_t,
  Pointer
> {
  using tuple::tuple;
  tb196bf1fcefaf5153b7e0f5e479aaa96(std::tuple<int16_t, Pointer> p)
    : std::tuple<int16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tdad017d875a8dc0f7c36bbe3dba6e956 : public std::tuple<
  std::shared_ptr<::dessser::gen::output_specs::file_type> ,
  Pointer
> {
  using tuple::tuple;
  tdad017d875a8dc0f7c36bbe3dba6e956(std::tuple<std::shared_ptr<::dessser::gen::output_specs::file_type> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::output_specs::file_type> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
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
struct te1550c6bf972eb31c7ccc68cf1702abf : public std::tuple<
  std::shared_ptr<::dessser::gen::output_specs::recipient> ,
  Pointer
> {
  using tuple::tuple;
  te1550c6bf972eb31c7ccc68cf1702abf(std::tuple<std::shared_ptr<::dessser::gen::output_specs::recipient> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::output_specs::recipient> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tb06ffbf6da2300d8f0de21eea734e5f2 : public std::tuple<
  dessser::gen::file_path::t_ext,
  Pointer
> {
  using tuple::tuple;
  tb06ffbf6da2300d8f0de21eea734e5f2(std::tuple<dessser::gen::file_path::t_ext, Pointer> p)
    : std::tuple<dessser::gen::file_path::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t9bda35a83af38220b883fe5d84e6ed9f : public std::tuple<
  dessser::gen::sync_key::t_ext,
  Pointer
> {
  using tuple::tuple;
  t9bda35a83af38220b883fe5d84e6ed9f(std::tuple<dessser::gen::sync_key::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_key::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tf6138ae5919ddcb1cb9a935a9dc7190a : public std::tuple<
  t,
  Pointer
> {
  using tuple::tuple;
  tf6138ae5919ddcb1cb9a935a9dc7190a(std::tuple<t, Pointer> p)
    : std::tuple<t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tc4746cf3f8f0513f3aae473e0bf0b2f4 : public std::tuple<
  Lst<::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee>,
  Pointer
> {
  using tuple::tuple;
  tc4746cf3f8f0513f3aae473e0bf0b2f4(std::tuple<Lst<::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t6c50fda18fa5bc68dda356ef9db827b3 : public std::tuple<
  dessser::gen::fieldmask::t_ext,
  Pointer
> {
  using tuple::tuple;
  t6c50fda18fa5bc68dda356ef9db827b3(std::tuple<dessser::gen::fieldmask::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fieldmask::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t16a148636af6320e05565c76894bdc78 : public std::tuple<
  Lst<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c>,
  Pointer
> {
  using tuple::tuple;
  t16a148636af6320e05565c76894bdc78(std::tuple<Lst<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t4041a0c8c314c2948e196f0dd185cea7 : public std::tuple<
  Lst<dessser::gen::raql_value::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t4041a0c8c314c2948e196f0dd185cea7(std::tuple<Lst<dessser::gen::raql_value::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::raql_value::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct td46b7b5194a84c2e11400d9ca5d84700 : public std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> {
  using tuple::tuple;
  td46b7b5194a84c2e11400d9ca5d84700(std::tuple<dessser::gen::raql_value::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_value::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t620f8762f21414f954a253b6ac73fbb9 : public std::tuple<
  Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c>,
  Pointer
> {
  using tuple::tuple;
  t620f8762f21414f954a253b6ac73fbb9(std::tuple<Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c>, Pointer> p)
    : std::tuple<Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct te2926311cf5a61b7e881f6a30e23afe0 : public std::tuple<
  Lst<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085>,
  Pointer
> {
  using tuple::tuple;
  te2926311cf5a61b7e881f6a30e23afe0(std::tuple<Lst<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("(FLOAT; I16; U32)" "Ptr")
      (let "stup_dst_323" (let "stup_dst_322" (write-u64 little-endian (param 1) (u64-of-float (get-item 0 (param 0)))) (write-u16 little-endian (identifier "stup_dst_322") (to-u16 (get-item 1 (param 0)))))
        (write-u32 little-endian (identifier "stup_dst_323") (get-item 2 (param 0)))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::channel_specs> ,Pointer)> channel_specs_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::channel_specs> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::output_specs::channel_specs>  p_0, Pointer p_1) {
    double id_1 { std::get<0>((*p_0)) };
    uint64_t id_2 { qword_of_float(id_1) };
    Pointer id_3 { p_1.writeU64Le(id_2) };
    Pointer let_res_4;
    {
      Pointer stup_dst_322 { id_3 };
      int16_t id_5 { std::get<1>((*p_0)) };
      uint16_t id_6 { uint16_t(id_5) };
      Pointer id_7 { stup_dst_322.writeU16Le(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer stup_dst_323 { let_res_4 };
      uint32_t id_9 { std::get<2>((*p_0)) };
      Pointer id_10 { stup_dst_323.writeU32Le(id_9) };
      let_res_8 = id_10;
    }
    return let_res_8;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::channel_specs> ,Pointer)> channel_specs_to_row_binary(channel_specs_to_row_binary_init());

/* 
    (fun ("[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" "Ptr")
      (let "ssum_dst_319" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_319")
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (let "srec_dst_321"
              (let "srec_dst_320" (write-u8 (identifier "ssum_dst_319") (u8-of-bool (get-field "with_index" (get-alt "Orc" (param 0)))))
                (write-u32 little-endian (identifier "srec_dst_320") (get-field "batch_size" (get-alt "Orc" (param 0))))) 
              (write-u32 little-endian (identifier "srec_dst_321") (get-field "num_batches" (get-alt "Orc" (param 0)))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::file_type> ,Pointer)> file_type_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::file_type> ,Pointer)> fun11 { [&fun11](std::shared_ptr<::dessser::gen::output_specs::file_type>  p_0, Pointer p_1) {
    uint16_t id_12 { uint16_t((*p_0).index()) };
    Pointer id_13 { p_1.writeU16Le(id_12) };
    Pointer let_res_14;
    {
      Pointer ssum_dst_319 { id_13 };
      uint16_t id_15 { 0 };
      uint16_t id_16 { uint16_t((*p_0).index()) };
      bool id_17 { bool(id_15 == id_16) };
      Pointer choose_res_18;
      if (id_17) {
        choose_res_18 = ssum_dst_319;
      } else {
        uint16_t id_19 { uint16_t((*p_0).index()) };
        uint16_t id_20 { 1 };
        bool id_21 { bool(id_19 == id_20) };
        Void id_22 { ((void)(assert(id_21)), VOID) };
        (void)id_22;
        ::dessser::gen::output_specs::t55234e0caf6cba9a33ddd852496b1d7b id_23 { std::get<1 /* Orc */>((*p_0)) };
        bool id_24 { id_23.with_index };
        uint8_t id_25 { uint8_t(id_24) };
        Pointer id_26 { ssum_dst_319.writeU8(id_25) };
        Pointer let_res_27;
        {
          Pointer srec_dst_320 { id_26 };
          ::dessser::gen::output_specs::t55234e0caf6cba9a33ddd852496b1d7b id_28 { std::get<1 /* Orc */>((*p_0)) };
          uint32_t id_29 { id_28.batch_size };
          Pointer id_30 { srec_dst_320.writeU32Le(id_29) };
          let_res_27 = id_30;
        }
        Pointer let_res_31;
        {
          Pointer srec_dst_321 { let_res_27 };
          ::dessser::gen::output_specs::t55234e0caf6cba9a33ddd852496b1d7b id_32 { std::get<1 /* Orc */>((*p_0)) };
          uint32_t id_33 { id_32.num_batches };
          Pointer id_34 { srec_dst_321.writeU32Le(id_33) };
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
std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::file_type> ,Pointer)> file_type_to_row_binary(file_type_to_row_binary_init());

/* 
    (fun ("[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]" "Ptr")
      (let "ssum_dst_315" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (apply (ext-identifier file_path to-row-binary) (get-alt "DirectFile" (param 0)) (identifier "ssum_dst_315"))
          (if (eq (u16 1) (label-of (param 0)))
            (write-bytes
              (let "leb128_sz_316" (make-vec (string-length (get-alt "IndirectFile" (param 0))))
                (let "leb128_ptr_317" (make-vec (identifier "ssum_dst_315"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_317")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_317"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_316"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_316"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_316"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_316") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_316")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_316")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_317"))))) 
              (bytes-of-string (get-alt "IndirectFile" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 2))) (apply (ext-identifier sync_key to-row-binary) (get-alt "SyncKey" (param 0)) (identifier "ssum_dst_315")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::recipient> ,Pointer)> recipient_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::recipient> ,Pointer)> fun35 { [&fun35](std::shared_ptr<::dessser::gen::output_specs::recipient>  p_0, Pointer p_1) {
    uint16_t id_36 { uint16_t((*p_0).index()) };
    Pointer id_37 { p_1.writeU16Le(id_36) };
    Pointer let_res_38;
    {
      Pointer ssum_dst_315 { id_37 };
      uint16_t id_39 { 0 };
      uint16_t id_40 { uint16_t((*p_0).index()) };
      bool id_41 { bool(id_39 == id_40) };
      Pointer choose_res_42;
      if (id_41) {
        auto fun43 { dessser::gen::file_path::to_row_binary };
        dessser::gen::file_path::t_ext id_44 { std::get<0 /* DirectFile */>((*p_0)) };
        Pointer id_45 { fun43(id_44, ssum_dst_315) };
        choose_res_42 = id_45;
      } else {
        uint16_t id_46 { 1 };
        uint16_t id_47 { uint16_t((*p_0).index()) };
        bool id_48 { bool(id_46 == id_47) };
        Pointer choose_res_49;
        if (id_48) {
          std::string id_50 { std::get<1 /* IndirectFile */>((*p_0)) };
          uint32_t id_51 { (uint32_t)id_50.size() };
          Vec<1, uint32_t> id_52 {  id_51  };
          Pointer let_res_53;
          {
            Vec<1, uint32_t> leb128_sz_316 { id_52 };
            Vec<1, Pointer> id_54 {  ssum_dst_315  };
            Pointer let_res_55;
            {
              Vec<1, Pointer> leb128_ptr_317 { id_54 };
              bool while_flag_56 { true };
              do {
                uint8_t id_57 { 0 };
                uint8_t id_58 { 0 };
                Pointer id_59 { leb128_ptr_317[id_58] };
                uint32_t id_60 { 128U };
                uint8_t id_61 { 0 };
                uint32_t id_62 { leb128_sz_316[id_61] };
                bool id_63 { bool(id_60 > id_62) };
                uint8_t choose_res_64;
                if (id_63) {
                  uint8_t id_65 { 0 };
                  uint32_t id_66 { leb128_sz_316[id_65] };
                  uint8_t id_67 { uint8_t(id_66) };
                  choose_res_64 = id_67;
                } else {
                  uint8_t id_68 { 0 };
                  uint32_t id_69 { leb128_sz_316[id_68] };
                  uint8_t id_70 { uint8_t(id_69) };
                  uint8_t id_71 { 128 };
                  uint8_t id_72 { uint8_t(id_70 | id_71) };
                  choose_res_64 = id_72;
                }
                Pointer id_73 { id_59.writeU8(choose_res_64) };
                Void id_74 { ((void)(leb128_ptr_317[id_57] = id_73), VOID) };
                (void)id_74;
                uint8_t id_75 { 0 };
                uint8_t id_76 { 0 };
                uint32_t id_77 { leb128_sz_316[id_76] };
                uint8_t id_78 { 7 };
                uint32_t id_79 { uint32_t(id_77 >> id_78) };
                Void id_80 { ((void)(leb128_sz_316[id_75] = id_79), VOID) };
                (void)id_80;
                uint8_t id_81 { 0 };
                uint32_t id_82 { leb128_sz_316[id_81] };
                uint32_t id_83 { 0U };
                bool id_84 { bool(id_82 > id_83) };
                while_flag_56 = id_84;
                if (while_flag_56) {
                  (void)VOID;
                }
              } while (while_flag_56);
              (void)VOID;
              uint8_t id_85 { 0 };
              Pointer id_86 { leb128_ptr_317[id_85] };
              let_res_55 = id_86;
            }
            let_res_53 = let_res_55;
          }
          std::string id_87 { std::get<1 /* IndirectFile */>((*p_0)) };
          Bytes id_88 { id_87 };
          Pointer id_89 { let_res_53.writeBytes(id_88) };
          choose_res_49 = id_89;
        } else {
          uint16_t id_90 { uint16_t((*p_0).index()) };
          uint16_t id_91 { 2 };
          bool id_92 { bool(id_90 == id_91) };
          Void id_93 { ((void)(assert(id_92)), VOID) };
          (void)id_93;
          auto fun94 { dessser::gen::sync_key::to_row_binary };
          dessser::gen::sync_key::t_ext id_95 { std::get<2 /* SyncKey */>((*p_0)) };
          Pointer id_96 { fun94(id_95, ssum_dst_315) };
          choose_res_49 = id_96;
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
std::function<Pointer(std::shared_ptr<::dessser::gen::output_specs::recipient> ,Pointer)> recipient_to_row_binary(recipient_to_row_binary_init());

/* 
    (fun ("((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})[]" "Ptr")
      (let "dst_ref_326"
        (make-vec
          (let "leb128_sz_324" (make-vec (cardinality (param 0)))
            (let "leb128_ptr_325" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_325")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_325"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_324"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_324"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_324"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_324") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_324")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_324")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_325"))))))
        (let "n_ref_327" (make-vec (i32 0))
          (seq
            (for-each "x_328" (param 0)
              (seq
                (set-vec (u8 0) (identifier "dst_ref_326")
                  (let "stup_dst_330" (let "stup_dst_329" (unsafe-nth (u8 0) (identifier "dst_ref_326")) (apply (identifier "recipient-to-row-binary") (get-item 0 (identifier "x_328")) (identifier "stup_dst_329")))
                    (let "srec_dst_345"
                      (let "srec_dst_332"
                        (let "srec_dst_331" (apply (identifier "file_type-to-row-binary") (get-field "file_type" (get-item 1 (identifier "x_328"))) (identifier "stup_dst_330"))
                          (apply (ext-identifier fieldmask to-row-binary) (get-field "fieldmask" (get-item 1 (identifier "x_328"))) (identifier "srec_dst_331")))
                        (let "dst_ref_335"
                          (make-vec
                            (let "leb128_sz_333" (make-vec (cardinality (get-field "filters" (get-item 1 (identifier "x_328")))))
                              (let "leb128_ptr_334" (make-vec (identifier "srec_dst_332"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_334")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_334"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_333"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_333"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_333"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_333") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_333")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_333")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_334"))))))
                          (let "n_ref_336" (make-vec (i32 0))
                            (seq
                              (for-each "x_337" (get-field "filters" (get-item 1 (identifier "x_328")))
                                (seq
                                  (set-vec (u8 0) (identifier "dst_ref_335")
                                    (let "stup_dst_339" (let "stup_dst_338" (unsafe-nth (u8 0) (identifier "dst_ref_335")) (write-u16 little-endian (identifier "stup_dst_338") (get-item 0 (identifier "x_337"))))
                                      (let "dst_ref_342"
                                        (make-vec
                                          (let "leb128_sz_340" (make-vec (cardinality (get-item 1 (identifier "x_337"))))
                                            (let "leb128_ptr_341" (make-vec (identifier "stup_dst_339"))
                                              (seq
                                                (while
                                                  (seq
                                                    (set-vec (u8 0) (identifier "leb128_ptr_341")
                                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_341"))
                                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_340"))) 
                                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_340"))) 
                                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_340"))) (u8 128)))))
                                                    (set-vec (u8 0) (identifier "leb128_sz_340") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_340")) (u8 7)))
                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_340")) (u32 0))) 
                                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_341"))))))
                                        (let "n_ref_343" (make-vec (i32 0))
                                          (seq
                                            (for-each "x_344" (get-item 1 (identifier "x_337"))
                                              (seq (set-vec (u8 0) (identifier "dst_ref_342") (apply (ext-identifier raql_value to-row-binary) (identifier "x_344") (unsafe-nth (u8 0) (identifier "dst_ref_342"))))
                                                (set-vec (u8 0) (identifier "n_ref_343") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_343")))))) 
                                            (unsafe-nth (u8 0) (identifier "dst_ref_342"))))))) 
                                  (set-vec (u8 0) (identifier "n_ref_336") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_336")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_335"))))))
                      (let "dst_ref_348"
                        (make-vec
                          (let "leb128_sz_346" (make-vec (cardinality (get-field "channels" (get-item 1 (identifier "x_328")))))
                            (let "leb128_ptr_347" (make-vec (identifier "srec_dst_345"))
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
                            (for-each "x_350" (get-field "channels" (get-item 1 (identifier "x_328")))
                              (seq
                                (set-vec (u8 0) (identifier "dst_ref_348")
                                  (let "stup_dst_352" (let "stup_dst_351" (unsafe-nth (u8 0) (identifier "dst_ref_348")) (write-u16 little-endian (identifier "stup_dst_351") (get-item 0 (identifier "x_350"))))
                                    (apply (identifier "channel_specs-to-row-binary") (get-item 1 (identifier "x_350")) (identifier "stup_dst_352"))))
                                (set-vec (u8 0) (identifier "n_ref_349") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_349")))))) 
                            (unsafe-nth (u8 0) (identifier "dst_ref_348")))))))) 
                (set-vec (u8 0) (identifier "n_ref_327") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_327")))))) 
            (unsafe-nth (u8 0) (identifier "dst_ref_326"))))))
 */
static std::function<Pointer(t&,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t&,Pointer)> fun97 { [&fun97](t& p_0, Pointer p_1) {
    uint32_t id_98 { p_0.size() };
    Vec<1, uint32_t> id_99 {  id_98  };
    Pointer let_res_100;
    {
      Vec<1, uint32_t> leb128_sz_324 { id_99 };
      Vec<1, Pointer> id_101 {  p_1  };
      Pointer let_res_102;
      {
        Vec<1, Pointer> leb128_ptr_325 { id_101 };
        bool while_flag_103 { true };
        do {
          uint8_t id_104 { 0 };
          uint8_t id_105 { 0 };
          Pointer id_106 { leb128_ptr_325[id_105] };
          uint32_t id_107 { 128U };
          uint8_t id_108 { 0 };
          uint32_t id_109 { leb128_sz_324[id_108] };
          bool id_110 { bool(id_107 > id_109) };
          uint8_t choose_res_111;
          if (id_110) {
            uint8_t id_112 { 0 };
            uint32_t id_113 { leb128_sz_324[id_112] };
            uint8_t id_114 { uint8_t(id_113) };
            choose_res_111 = id_114;
          } else {
            uint8_t id_115 { 0 };
            uint32_t id_116 { leb128_sz_324[id_115] };
            uint8_t id_117 { uint8_t(id_116) };
            uint8_t id_118 { 128 };
            uint8_t id_119 { uint8_t(id_117 | id_118) };
            choose_res_111 = id_119;
          }
          Pointer id_120 { id_106.writeU8(choose_res_111) };
          Void id_121 { ((void)(leb128_ptr_325[id_104] = id_120), VOID) };
          (void)id_121;
          uint8_t id_122 { 0 };
          uint8_t id_123 { 0 };
          uint32_t id_124 { leb128_sz_324[id_123] };
          uint8_t id_125 { 7 };
          uint32_t id_126 { uint32_t(id_124 >> id_125) };
          Void id_127 { ((void)(leb128_sz_324[id_122] = id_126), VOID) };
          (void)id_127;
          uint8_t id_128 { 0 };
          uint32_t id_129 { leb128_sz_324[id_128] };
          uint32_t id_130 { 0U };
          bool id_131 { bool(id_129 > id_130) };
          while_flag_103 = id_131;
          if (while_flag_103) {
            (void)VOID;
          }
        } while (while_flag_103);
        (void)VOID;
        uint8_t id_132 { 0 };
        Pointer id_133 { leb128_ptr_325[id_132] };
        let_res_102 = id_133;
      }
      let_res_100 = let_res_102;
    }
    Vec<1, Pointer> id_134 {  let_res_100  };
    Pointer let_res_135;
    {
      Vec<1, Pointer> dst_ref_326 { id_134 };
      int32_t id_136 { 0L };
      Vec<1, int32_t> id_137 {  id_136  };
      Pointer let_res_138;
      {
        Vec<1, int32_t> n_ref_327 { id_137 };
        for (::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee x_328 : p_0) {
          uint8_t id_139 { 0 };
          uint8_t id_140 { 0 };
          Pointer id_141 { dst_ref_326[id_140] };
          Pointer let_res_142;
          {
            Pointer stup_dst_329 { id_141 };
            std::shared_ptr<::dessser::gen::output_specs::recipient>  id_143 { std::get<0>(x_328) };
            Pointer id_144 { recipient_to_row_binary(id_143, stup_dst_329) };
            let_res_142 = id_144;
          }
          Pointer let_res_145;
          {
            Pointer stup_dst_330 { let_res_142 };
            ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_146 { std::get<1>(x_328) };
            std::shared_ptr<::dessser::gen::output_specs::file_type>  id_147 { id_146.file_type };
            Pointer id_148 { file_type_to_row_binary(id_147, stup_dst_330) };
            Pointer let_res_149;
            {
              Pointer srec_dst_331 { id_148 };
              auto fun150 { dessser::gen::fieldmask::to_row_binary };
              ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_151 { std::get<1>(x_328) };
              dessser::gen::fieldmask::t_ext id_152 { id_151.fieldmask };
              Pointer id_153 { fun150(id_152, srec_dst_331) };
              let_res_149 = id_153;
            }
            Pointer let_res_154;
            {
              Pointer srec_dst_332 { let_res_149 };
              ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_155 { std::get<1>(x_328) };
              Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> id_156 { id_155.filters };
              uint32_t id_157 { id_156.size() };
              Vec<1, uint32_t> id_158 {  id_157  };
              Pointer let_res_159;
              {
                Vec<1, uint32_t> leb128_sz_333 { id_158 };
                Vec<1, Pointer> id_160 {  srec_dst_332  };
                Pointer let_res_161;
                {
                  Vec<1, Pointer> leb128_ptr_334 { id_160 };
                  bool while_flag_162 { true };
                  do {
                    uint8_t id_163 { 0 };
                    uint8_t id_164 { 0 };
                    Pointer id_165 { leb128_ptr_334[id_164] };
                    uint32_t id_166 { 128U };
                    uint8_t id_167 { 0 };
                    uint32_t id_168 { leb128_sz_333[id_167] };
                    bool id_169 { bool(id_166 > id_168) };
                    uint8_t choose_res_170;
                    if (id_169) {
                      uint8_t id_171 { 0 };
                      uint32_t id_172 { leb128_sz_333[id_171] };
                      uint8_t id_173 { uint8_t(id_172) };
                      choose_res_170 = id_173;
                    } else {
                      uint8_t id_174 { 0 };
                      uint32_t id_175 { leb128_sz_333[id_174] };
                      uint8_t id_176 { uint8_t(id_175) };
                      uint8_t id_177 { 128 };
                      uint8_t id_178 { uint8_t(id_176 | id_177) };
                      choose_res_170 = id_178;
                    }
                    Pointer id_179 { id_165.writeU8(choose_res_170) };
                    Void id_180 { ((void)(leb128_ptr_334[id_163] = id_179), VOID) };
                    (void)id_180;
                    uint8_t id_181 { 0 };
                    uint8_t id_182 { 0 };
                    uint32_t id_183 { leb128_sz_333[id_182] };
                    uint8_t id_184 { 7 };
                    uint32_t id_185 { uint32_t(id_183 >> id_184) };
                    Void id_186 { ((void)(leb128_sz_333[id_181] = id_185), VOID) };
                    (void)id_186;
                    uint8_t id_187 { 0 };
                    uint32_t id_188 { leb128_sz_333[id_187] };
                    uint32_t id_189 { 0U };
                    bool id_190 { bool(id_188 > id_189) };
                    while_flag_162 = id_190;
                    if (while_flag_162) {
                      (void)VOID;
                    }
                  } while (while_flag_162);
                  (void)VOID;
                  uint8_t id_191 { 0 };
                  Pointer id_192 { leb128_ptr_334[id_191] };
                  let_res_161 = id_192;
                }
                let_res_159 = let_res_161;
              }
              Vec<1, Pointer> id_193 {  let_res_159  };
              Pointer let_res_194;
              {
                Vec<1, Pointer> dst_ref_335 { id_193 };
                int32_t id_195 { 0L };
                Vec<1, int32_t> id_196 {  id_195  };
                Pointer let_res_197;
                {
                  Vec<1, int32_t> n_ref_336 { id_196 };
                  ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_198 { std::get<1>(x_328) };
                  Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> id_199 { id_198.filters };
                  for (::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c x_337 : id_199) {
                    uint8_t id_200 { 0 };
                    uint8_t id_201 { 0 };
                    Pointer id_202 { dst_ref_335[id_201] };
                    Pointer let_res_203;
                    {
                      Pointer stup_dst_338 { id_202 };
                      uint16_t id_204 { std::get<0>(x_337) };
                      Pointer id_205 { stup_dst_338.writeU16Le(id_204) };
                      let_res_203 = id_205;
                    }
                    Pointer let_res_206;
                    {
                      Pointer stup_dst_339 { let_res_203 };
                      Arr<dessser::gen::raql_value::t_ext> id_207 { std::get<1>(x_337) };
                      uint32_t id_208 { id_207.size() };
                      Vec<1, uint32_t> id_209 {  id_208  };
                      Pointer let_res_210;
                      {
                        Vec<1, uint32_t> leb128_sz_340 { id_209 };
                        Vec<1, Pointer> id_211 {  stup_dst_339  };
                        Pointer let_res_212;
                        {
                          Vec<1, Pointer> leb128_ptr_341 { id_211 };
                          bool while_flag_213 { true };
                          do {
                            uint8_t id_214 { 0 };
                            uint8_t id_215 { 0 };
                            Pointer id_216 { leb128_ptr_341[id_215] };
                            uint32_t id_217 { 128U };
                            uint8_t id_218 { 0 };
                            uint32_t id_219 { leb128_sz_340[id_218] };
                            bool id_220 { bool(id_217 > id_219) };
                            uint8_t choose_res_221;
                            if (id_220) {
                              uint8_t id_222 { 0 };
                              uint32_t id_223 { leb128_sz_340[id_222] };
                              uint8_t id_224 { uint8_t(id_223) };
                              choose_res_221 = id_224;
                            } else {
                              uint8_t id_225 { 0 };
                              uint32_t id_226 { leb128_sz_340[id_225] };
                              uint8_t id_227 { uint8_t(id_226) };
                              uint8_t id_228 { 128 };
                              uint8_t id_229 { uint8_t(id_227 | id_228) };
                              choose_res_221 = id_229;
                            }
                            Pointer id_230 { id_216.writeU8(choose_res_221) };
                            Void id_231 { ((void)(leb128_ptr_341[id_214] = id_230), VOID) };
                            (void)id_231;
                            uint8_t id_232 { 0 };
                            uint8_t id_233 { 0 };
                            uint32_t id_234 { leb128_sz_340[id_233] };
                            uint8_t id_235 { 7 };
                            uint32_t id_236 { uint32_t(id_234 >> id_235) };
                            Void id_237 { ((void)(leb128_sz_340[id_232] = id_236), VOID) };
                            (void)id_237;
                            uint8_t id_238 { 0 };
                            uint32_t id_239 { leb128_sz_340[id_238] };
                            uint32_t id_240 { 0U };
                            bool id_241 { bool(id_239 > id_240) };
                            while_flag_213 = id_241;
                            if (while_flag_213) {
                              (void)VOID;
                            }
                          } while (while_flag_213);
                          (void)VOID;
                          uint8_t id_242 { 0 };
                          Pointer id_243 { leb128_ptr_341[id_242] };
                          let_res_212 = id_243;
                        }
                        let_res_210 = let_res_212;
                      }
                      Vec<1, Pointer> id_244 {  let_res_210  };
                      Pointer let_res_245;
                      {
                        Vec<1, Pointer> dst_ref_342 { id_244 };
                        int32_t id_246 { 0L };
                        Vec<1, int32_t> id_247 {  id_246  };
                        Pointer let_res_248;
                        {
                          Vec<1, int32_t> n_ref_343 { id_247 };
                          Arr<dessser::gen::raql_value::t_ext> id_249 { std::get<1>(x_337) };
                          for (dessser::gen::raql_value::t_ext x_344 : id_249) {
                            uint8_t id_250 { 0 };
                            auto fun251 { dessser::gen::raql_value::to_row_binary };
                            uint8_t id_252 { 0 };
                            Pointer id_253 { dst_ref_342[id_252] };
                            Pointer id_254 { fun251(x_344, id_253) };
                            Void id_255 { ((void)(dst_ref_342[id_250] = id_254), VOID) };
                            (void)id_255;
                            uint8_t id_256 { 0 };
                            int32_t id_257 { 1L };
                            uint8_t id_258 { 0 };
                            int32_t id_259 { n_ref_343[id_258] };
                            int32_t id_260 { int32_t(id_257 + id_259) };
                            Void id_261 { ((void)(n_ref_343[id_256] = id_260), VOID) };
                            (void)id_261;
                            (void)id_261;
                          }
                          (void)VOID;
                          uint8_t id_262 { 0 };
                          Pointer id_263 { dst_ref_342[id_262] };
                          let_res_248 = id_263;
                        }
                        let_res_245 = let_res_248;
                      }
                      let_res_206 = let_res_245;
                    }
                    Void id_264 { ((void)(dst_ref_335[id_200] = let_res_206), VOID) };
                    (void)id_264;
                    uint8_t id_265 { 0 };
                    int32_t id_266 { 1L };
                    uint8_t id_267 { 0 };
                    int32_t id_268 { n_ref_336[id_267] };
                    int32_t id_269 { int32_t(id_266 + id_268) };
                    Void id_270 { ((void)(n_ref_336[id_265] = id_269), VOID) };
                    (void)id_270;
                    (void)id_270;
                  }
                  (void)VOID;
                  uint8_t id_271 { 0 };
                  Pointer id_272 { dst_ref_335[id_271] };
                  let_res_197 = id_272;
                }
                let_res_194 = let_res_197;
              }
              let_res_154 = let_res_194;
            }
            Pointer let_res_273;
            {
              Pointer srec_dst_345 { let_res_154 };
              ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_274 { std::get<1>(x_328) };
              Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> id_275 { id_274.channels };
              uint32_t id_276 { id_275.size() };
              Vec<1, uint32_t> id_277 {  id_276  };
              Pointer let_res_278;
              {
                Vec<1, uint32_t> leb128_sz_346 { id_277 };
                Vec<1, Pointer> id_279 {  srec_dst_345  };
                Pointer let_res_280;
                {
                  Vec<1, Pointer> leb128_ptr_347 { id_279 };
                  bool while_flag_281 { true };
                  do {
                    uint8_t id_282 { 0 };
                    uint8_t id_283 { 0 };
                    Pointer id_284 { leb128_ptr_347[id_283] };
                    uint32_t id_285 { 128U };
                    uint8_t id_286 { 0 };
                    uint32_t id_287 { leb128_sz_346[id_286] };
                    bool id_288 { bool(id_285 > id_287) };
                    uint8_t choose_res_289;
                    if (id_288) {
                      uint8_t id_290 { 0 };
                      uint32_t id_291 { leb128_sz_346[id_290] };
                      uint8_t id_292 { uint8_t(id_291) };
                      choose_res_289 = id_292;
                    } else {
                      uint8_t id_293 { 0 };
                      uint32_t id_294 { leb128_sz_346[id_293] };
                      uint8_t id_295 { uint8_t(id_294) };
                      uint8_t id_296 { 128 };
                      uint8_t id_297 { uint8_t(id_295 | id_296) };
                      choose_res_289 = id_297;
                    }
                    Pointer id_298 { id_284.writeU8(choose_res_289) };
                    Void id_299 { ((void)(leb128_ptr_347[id_282] = id_298), VOID) };
                    (void)id_299;
                    uint8_t id_300 { 0 };
                    uint8_t id_301 { 0 };
                    uint32_t id_302 { leb128_sz_346[id_301] };
                    uint8_t id_303 { 7 };
                    uint32_t id_304 { uint32_t(id_302 >> id_303) };
                    Void id_305 { ((void)(leb128_sz_346[id_300] = id_304), VOID) };
                    (void)id_305;
                    uint8_t id_306 { 0 };
                    uint32_t id_307 { leb128_sz_346[id_306] };
                    uint32_t id_308 { 0U };
                    bool id_309 { bool(id_307 > id_308) };
                    while_flag_281 = id_309;
                    if (while_flag_281) {
                      (void)VOID;
                    }
                  } while (while_flag_281);
                  (void)VOID;
                  uint8_t id_310 { 0 };
                  Pointer id_311 { leb128_ptr_347[id_310] };
                  let_res_280 = id_311;
                }
                let_res_278 = let_res_280;
              }
              Vec<1, Pointer> id_312 {  let_res_278  };
              Pointer let_res_313;
              {
                Vec<1, Pointer> dst_ref_348 { id_312 };
                int32_t id_314 { 0L };
                Vec<1, int32_t> id_315 {  id_314  };
                Pointer let_res_316;
                {
                  Vec<1, int32_t> n_ref_349 { id_315 };
                  ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_317 { std::get<1>(x_328) };
                  Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> id_318 { id_317.channels };
                  for (::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085 x_350 : id_318) {
                    uint8_t id_319 { 0 };
                    uint8_t id_320 { 0 };
                    Pointer id_321 { dst_ref_348[id_320] };
                    Pointer let_res_322;
                    {
                      Pointer stup_dst_351 { id_321 };
                      uint16_t id_323 { std::get<0>(x_350) };
                      Pointer id_324 { stup_dst_351.writeU16Le(id_323) };
                      let_res_322 = id_324;
                    }
                    Pointer let_res_325;
                    {
                      Pointer stup_dst_352 { let_res_322 };
                      std::shared_ptr<::dessser::gen::output_specs::channel_specs>  id_326 { std::get<1>(x_350) };
                      Pointer id_327 { channel_specs_to_row_binary(id_326, stup_dst_352) };
                      let_res_325 = id_327;
                    }
                    Void id_328 { ((void)(dst_ref_348[id_319] = let_res_325), VOID) };
                    (void)id_328;
                    uint8_t id_329 { 0 };
                    int32_t id_330 { 1L };
                    uint8_t id_331 { 0 };
                    int32_t id_332 { n_ref_349[id_331] };
                    int32_t id_333 { int32_t(id_330 + id_332) };
                    Void id_334 { ((void)(n_ref_349[id_329] = id_333), VOID) };
                    (void)id_334;
                    (void)id_334;
                  }
                  (void)VOID;
                  uint8_t id_335 { 0 };
                  Pointer id_336 { dst_ref_348[id_335] };
                  let_res_316 = id_336;
                }
                let_res_313 = let_res_316;
              }
              let_res_273 = let_res_313;
            }
            let_res_145 = let_res_273;
          }
          Void id_337 { ((void)(dst_ref_326[id_139] = let_res_145), VOID) };
          (void)id_337;
          uint8_t id_338 { 0 };
          int32_t id_339 { 1L };
          uint8_t id_340 { 0 };
          int32_t id_341 { n_ref_327[id_340] };
          int32_t id_342 { int32_t(id_339 + id_341) };
          Void id_343 { ((void)(n_ref_327[id_338] = id_342), VOID) };
          (void)id_343;
          (void)id_343;
        }
        (void)VOID;
        uint8_t id_344 { 0 };
        Pointer id_345 { dst_ref_326[id_344] };
        let_res_138 = id_345;
      }
      let_res_135 = let_res_138;
    }
    return let_res_135;
  }
   };
  return fun97;
}
std::function<Pointer(t&,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("(FLOAT; I16; U32)") (size 14))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::output_specs::channel_specs> )> channel_specs_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::output_specs::channel_specs> )> fun346 { [&fun346](std::shared_ptr<::dessser::gen::output_specs::channel_specs>  p_0) {
    Size id_347 { 14UL };
    return id_347;
  }
   };
  return fun346;
}
std::function<Size(std::shared_ptr<::dessser::gen::output_specs::channel_specs> )> channel_specs_sersize_of_row_binary(channel_specs_sersize_of_row_binary_init());

/* 
    (fun ("[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]") (if (eq (u16 0) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 1))) (size 11))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::output_specs::file_type> )> file_type_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::output_specs::file_type> )> fun348 { [&fun348](std::shared_ptr<::dessser::gen::output_specs::file_type>  p_0) {
    uint16_t id_349 { 0 };
    uint16_t id_350 { uint16_t((*p_0).index()) };
    bool id_351 { bool(id_349 == id_350) };
    Size choose_res_352;
    if (id_351) {
      Size id_353 { 2UL };
      choose_res_352 = id_353;
    } else {
      uint16_t id_354 { uint16_t((*p_0).index()) };
      uint16_t id_355 { 1 };
      bool id_356 { bool(id_354 == id_355) };
      Void id_357 { ((void)(assert(id_356)), VOID) };
      (void)id_357;
      Size id_358 { 11UL };
      choose_res_352 = id_358;
    }
    return choose_res_352;
  }
   };
  return fun348;
}
std::function<Size(std::shared_ptr<::dessser::gen::output_specs::file_type> )> file_type_sersize_of_row_binary(file_type_sersize_of_row_binary_init());

/* 
    (fun ("[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]")
      (if (eq (u16 0) (label-of (param 0))) (add (size 2) (apply (ext-identifier file_path sersize-of-row-binary) (get-alt "DirectFile" (param 0))))
        (if (eq (u16 1) (label-of (param 0)))
          (add (size 2)
            (add
              (let "n_ref_279" (make-vec (string-length (get-alt "IndirectFile" (param 0))))
                (let "lebsz_ref_280" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_279")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_280")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_280") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_280")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_280")))))) 
              (size-of-u32 (string-length (get-alt "IndirectFile" (param 0))))))
          (seq (assert (eq (label-of (param 0)) (u16 2))) (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-alt "SyncKey" (param 0))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::output_specs::recipient> )> recipient_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::output_specs::recipient> )> fun359 { [&fun359](std::shared_ptr<::dessser::gen::output_specs::recipient>  p_0) {
    uint16_t id_360 { 0 };
    uint16_t id_361 { uint16_t((*p_0).index()) };
    bool id_362 { bool(id_360 == id_361) };
    Size choose_res_363;
    if (id_362) {
      Size id_364 { 2UL };
      auto fun365 { dessser::gen::file_path::sersize_of_row_binary };
      dessser::gen::file_path::t_ext id_366 { std::get<0 /* DirectFile */>((*p_0)) };
      Size id_367 { fun365(id_366) };
      Size id_368 { Size(id_364 + id_367) };
      choose_res_363 = id_368;
    } else {
      uint16_t id_369 { 1 };
      uint16_t id_370 { uint16_t((*p_0).index()) };
      bool id_371 { bool(id_369 == id_370) };
      Size choose_res_372;
      if (id_371) {
        Size id_373 { 2UL };
        std::string id_374 { std::get<1 /* IndirectFile */>((*p_0)) };
        uint32_t id_375 { (uint32_t)id_374.size() };
        Vec<1, uint32_t> id_376 {  id_375  };
        Size let_res_377;
        {
          Vec<1, uint32_t> n_ref_279 { id_376 };
          uint32_t id_378 { 1U };
          Vec<1, uint32_t> id_379 {  id_378  };
          Size let_res_380;
          {
            Vec<1, uint32_t> lebsz_ref_280 { id_379 };
            bool while_flag_381 { true };
            do {
              uint8_t id_382 { 0 };
              uint32_t id_383 { n_ref_279[id_382] };
              uint8_t id_384 { 0 };
              uint32_t id_385 { lebsz_ref_280[id_384] };
              uint8_t id_386 { 7 };
              uint32_t id_387 { uint32_t(id_385 << id_386) };
              bool id_388 { bool(id_383 >= id_387) };
              while_flag_381 = id_388;
              if (while_flag_381) {
                uint8_t id_389 { 0 };
                uint8_t id_390 { 0 };
                uint32_t id_391 { lebsz_ref_280[id_390] };
                uint32_t id_392 { 1U };
                uint32_t id_393 { uint32_t(id_391 + id_392) };
                Void id_394 { ((void)(lebsz_ref_280[id_389] = id_393), VOID) };
                (void)id_394;
              }
            } while (while_flag_381);
            (void)VOID;
            uint8_t id_395 { 0 };
            uint32_t id_396 { lebsz_ref_280[id_395] };
            Size id_397 { Size(id_396) };
            let_res_380 = id_397;
          }
          let_res_377 = let_res_380;
        }
        std::string id_398 { std::get<1 /* IndirectFile */>((*p_0)) };
        uint32_t id_399 { (uint32_t)id_398.size() };
        Size id_400 { Size(id_399) };
        Size id_401 { Size(let_res_377 + id_400) };
        Size id_402 { Size(id_373 + id_401) };
        choose_res_372 = id_402;
      } else {
        uint16_t id_403 { uint16_t((*p_0).index()) };
        uint16_t id_404 { 2 };
        bool id_405 { bool(id_403 == id_404) };
        Void id_406 { ((void)(assert(id_405)), VOID) };
        (void)id_406;
        Size id_407 { 2UL };
        auto fun408 { dessser::gen::sync_key::sersize_of_row_binary };
        dessser::gen::sync_key::t_ext id_409 { std::get<2 /* SyncKey */>((*p_0)) };
        Size id_410 { fun408(id_409) };
        Size id_411 { Size(id_407 + id_410) };
        choose_res_372 = id_411;
      }
      choose_res_363 = choose_res_372;
    }
    return choose_res_363;
  }
   };
  return fun359;
}
std::function<Size(std::shared_ptr<::dessser::gen::output_specs::recipient> )> recipient_sersize_of_row_binary(recipient_sersize_of_row_binary_init());

/* 
    (fun ("((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})[]")
      (let "sz_ref_290"
        (make-vec
          (let "n_ref_288" (make-vec (cardinality (param 0)))
            (let "lebsz_ref_289" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_288")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_289")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_289") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_289")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_289")))))))
        (seq
          (let "repeat_n_291" (make-vec (i32 0))
            (while (gt (to-i32 (cardinality (param 0))) (unsafe-nth (u8 0) (identifier "repeat_n_291")))
              (seq
                (set-vec (u8 0) (identifier "sz_ref_290")
                  (let "sz_293"
                    (let "sz_292" (unsafe-nth (u8 0) (identifier "sz_ref_290"))
                      (add (identifier "sz_292") (apply (identifier "recipient-sersize-of-row-binary") (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0))))))
                    (let "sz_307"
                      (let "sz_296"
                        (let "sz_295" (add (identifier "sz_293") (apply (identifier "file_type-sersize-of-row-binary") (get-field "file_type" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0))))))
                          (add (identifier "sz_295") (apply (ext-identifier fieldmask sersize-of-row-binary) (get-field "fieldmask" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0)))))))
                        (let "sz_ref_299"
                          (make-vec
                            (add (identifier "sz_296")
                              (let "n_ref_297" (make-vec (cardinality (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0))))))
                                (let "lebsz_ref_298" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_297")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_298")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_298") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_298")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_298"))))))))
                          (seq
                            (let "repeat_n_300" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_300")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_299")
                                    (let "sz_302" (add (unsafe-nth (u8 0) (identifier "sz_ref_299")) (size 2))
                                      (let "sz_ref_305"
                                        (make-vec
                                          (add (identifier "sz_302")
                                            (let "n_ref_303"
                                              (make-vec
                                                (cardinality
                                                  (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_300")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0))))))))
                                              (let "lebsz_ref_304" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_303")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_304")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_304") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_304")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_304"))))))))
                                        (seq
                                          (let "repeat_n_306" (make-vec (i32 0))
                                            (while
                                              (gt
                                                (to-i32
                                                  (cardinality
                                                    (get-item 1
                                                      (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_300")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0))))))))
                                                (unsafe-nth (u8 0) (identifier "repeat_n_306")))
                                              (seq
                                                (set-vec (u8 0) (identifier "sz_ref_305")
                                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_305"))
                                                    (apply (ext-identifier raql_value sersize-of-row-binary)
                                                      (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_306"))
                                                        (get-item 1
                                                          (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_300")) (get-field "filters" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0))))))))))
                                                (set-vec (u8 0) (identifier "repeat_n_306") (add (unsafe-nth (u8 0) (identifier "repeat_n_306")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "sz_ref_305")))))) 
                                  (set-vec (u8 0) (identifier "repeat_n_300") (add (unsafe-nth (u8 0) (identifier "repeat_n_300")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_299")))))
                      (let "sz_ref_310"
                        (make-vec
                          (add (identifier "sz_307")
                            (let "n_ref_308" (make-vec (cardinality (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0))))))
                              (let "lebsz_ref_309" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_308")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_309")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_309") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_309")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_309"))))))))
                        (seq
                          (let "repeat_n_311" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_311")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_310")
                                  (let "sz_313" (add (unsafe-nth (u8 0) (identifier "sz_ref_310")) (size 2))
                                    (add (identifier "sz_313")
                                      (apply (identifier "channel_specs-sersize-of-row-binary")
                                        (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_311")) (get-field "channels" (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_291")) (param 0))))))))))
                                (set-vec (u8 0) (identifier "repeat_n_311") (add (unsafe-nth (u8 0) (identifier "repeat_n_311")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_310"))))))) 
                (set-vec (u8 0) (identifier "repeat_n_291") (add (unsafe-nth (u8 0) (identifier "repeat_n_291")) (i32 1)))))) 
          (unsafe-nth (u8 0) (identifier "sz_ref_290")))))
 */
static std::function<Size(t&)> sersize_of_row_binary_init()
{
  std::function<Size(t&)> fun412 { [&fun412](t& p_0) {
    uint32_t id_413 { p_0.size() };
    Vec<1, uint32_t> id_414 {  id_413  };
    Size let_res_415;
    {
      Vec<1, uint32_t> n_ref_288 { id_414 };
      uint32_t id_416 { 1U };
      Vec<1, uint32_t> id_417 {  id_416  };
      Size let_res_418;
      {
        Vec<1, uint32_t> lebsz_ref_289 { id_417 };
        bool while_flag_419 { true };
        do {
          uint8_t id_420 { 0 };
          uint32_t id_421 { n_ref_288[id_420] };
          uint8_t id_422 { 0 };
          uint32_t id_423 { lebsz_ref_289[id_422] };
          uint8_t id_424 { 7 };
          uint32_t id_425 { uint32_t(id_423 << id_424) };
          bool id_426 { bool(id_421 >= id_425) };
          while_flag_419 = id_426;
          if (while_flag_419) {
            uint8_t id_427 { 0 };
            uint8_t id_428 { 0 };
            uint32_t id_429 { lebsz_ref_289[id_428] };
            uint32_t id_430 { 1U };
            uint32_t id_431 { uint32_t(id_429 + id_430) };
            Void id_432 { ((void)(lebsz_ref_289[id_427] = id_431), VOID) };
            (void)id_432;
          }
        } while (while_flag_419);
        (void)VOID;
        uint8_t id_433 { 0 };
        uint32_t id_434 { lebsz_ref_289[id_433] };
        Size id_435 { Size(id_434) };
        let_res_418 = id_435;
      }
      let_res_415 = let_res_418;
    }
    Vec<1, Size> id_436 {  let_res_415  };
    Size let_res_437;
    {
      Vec<1, Size> sz_ref_290 { id_436 };
      int32_t id_438 { 0L };
      Vec<1, int32_t> id_439 {  id_438  };
      {
        Vec<1, int32_t> repeat_n_291 { id_439 };
        bool while_flag_440 { true };
        do {
          uint32_t id_441 { p_0.size() };
          int32_t id_442 { int32_t(id_441) };
          uint8_t id_443 { 0 };
          int32_t id_444 { repeat_n_291[id_443] };
          bool id_445 { bool(id_442 > id_444) };
          while_flag_440 = id_445;
          if (while_flag_440) {
            uint8_t id_446 { 0 };
            uint8_t id_447 { 0 };
            Size id_448 { sz_ref_290[id_447] };
            Size let_res_449;
            {
              Size sz_292 { id_448 };
              uint8_t id_450 { 0 };
              int32_t id_451 { repeat_n_291[id_450] };
              ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_452 { p_0[id_451] };
              std::shared_ptr<::dessser::gen::output_specs::recipient>  id_453 { std::get<0>(id_452) };
              Size id_454 { recipient_sersize_of_row_binary(id_453) };
              Size id_455 { Size(sz_292 + id_454) };
              let_res_449 = id_455;
            }
            Size let_res_456;
            {
              Size sz_293 { let_res_449 };
              uint8_t id_457 { 0 };
              int32_t id_458 { repeat_n_291[id_457] };
              ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_459 { p_0[id_458] };
              ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_460 { std::get<1>(id_459) };
              std::shared_ptr<::dessser::gen::output_specs::file_type>  id_461 { id_460.file_type };
              Size id_462 { file_type_sersize_of_row_binary(id_461) };
              Size id_463 { Size(sz_293 + id_462) };
              Size let_res_464;
              {
                Size sz_295 { id_463 };
                auto fun465 { dessser::gen::fieldmask::sersize_of_row_binary };
                uint8_t id_466 { 0 };
                int32_t id_467 { repeat_n_291[id_466] };
                ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_468 { p_0[id_467] };
                ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_469 { std::get<1>(id_468) };
                dessser::gen::fieldmask::t_ext id_470 { id_469.fieldmask };
                Size id_471 { fun465(id_470) };
                Size id_472 { Size(sz_295 + id_471) };
                let_res_464 = id_472;
              }
              Size let_res_473;
              {
                Size sz_296 { let_res_464 };
                uint8_t id_474 { 0 };
                int32_t id_475 { repeat_n_291[id_474] };
                ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_476 { p_0[id_475] };
                ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_477 { std::get<1>(id_476) };
                Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> id_478 { id_477.filters };
                uint32_t id_479 { id_478.size() };
                Vec<1, uint32_t> id_480 {  id_479  };
                Size let_res_481;
                {
                  Vec<1, uint32_t> n_ref_297 { id_480 };
                  uint32_t id_482 { 1U };
                  Vec<1, uint32_t> id_483 {  id_482  };
                  Size let_res_484;
                  {
                    Vec<1, uint32_t> lebsz_ref_298 { id_483 };
                    bool while_flag_485 { true };
                    do {
                      uint8_t id_486 { 0 };
                      uint32_t id_487 { n_ref_297[id_486] };
                      uint8_t id_488 { 0 };
                      uint32_t id_489 { lebsz_ref_298[id_488] };
                      uint8_t id_490 { 7 };
                      uint32_t id_491 { uint32_t(id_489 << id_490) };
                      bool id_492 { bool(id_487 >= id_491) };
                      while_flag_485 = id_492;
                      if (while_flag_485) {
                        uint8_t id_493 { 0 };
                        uint8_t id_494 { 0 };
                        uint32_t id_495 { lebsz_ref_298[id_494] };
                        uint32_t id_496 { 1U };
                        uint32_t id_497 { uint32_t(id_495 + id_496) };
                        Void id_498 { ((void)(lebsz_ref_298[id_493] = id_497), VOID) };
                        (void)id_498;
                      }
                    } while (while_flag_485);
                    (void)VOID;
                    uint8_t id_499 { 0 };
                    uint32_t id_500 { lebsz_ref_298[id_499] };
                    Size id_501 { Size(id_500) };
                    let_res_484 = id_501;
                  }
                  let_res_481 = let_res_484;
                }
                Size id_502 { Size(sz_296 + let_res_481) };
                Vec<1, Size> id_503 {  id_502  };
                Size let_res_504;
                {
                  Vec<1, Size> sz_ref_299 { id_503 };
                  int32_t id_505 { 0L };
                  Vec<1, int32_t> id_506 {  id_505  };
                  {
                    Vec<1, int32_t> repeat_n_300 { id_506 };
                    bool while_flag_507 { true };
                    do {
                      uint8_t id_508 { 0 };
                      int32_t id_509 { repeat_n_291[id_508] };
                      ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_510 { p_0[id_509] };
                      ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_511 { std::get<1>(id_510) };
                      Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> id_512 { id_511.filters };
                      uint32_t id_513 { id_512.size() };
                      int32_t id_514 { int32_t(id_513) };
                      uint8_t id_515 { 0 };
                      int32_t id_516 { repeat_n_300[id_515] };
                      bool id_517 { bool(id_514 > id_516) };
                      while_flag_507 = id_517;
                      if (while_flag_507) {
                        uint8_t id_518 { 0 };
                        uint8_t id_519 { 0 };
                        Size id_520 { sz_ref_299[id_519] };
                        Size id_521 { 2UL };
                        Size id_522 { Size(id_520 + id_521) };
                        Size let_res_523;
                        {
                          Size sz_302 { id_522 };
                          uint8_t id_524 { 0 };
                          int32_t id_525 { repeat_n_300[id_524] };
                          uint8_t id_526 { 0 };
                          int32_t id_527 { repeat_n_291[id_526] };
                          ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_528 { p_0[id_527] };
                          ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_529 { std::get<1>(id_528) };
                          Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> id_530 { id_529.filters };
                          ::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c id_531 { id_530[id_525] };
                          Arr<dessser::gen::raql_value::t_ext> id_532 { std::get<1>(id_531) };
                          uint32_t id_533 { id_532.size() };
                          Vec<1, uint32_t> id_534 {  id_533  };
                          Size let_res_535;
                          {
                            Vec<1, uint32_t> n_ref_303 { id_534 };
                            uint32_t id_536 { 1U };
                            Vec<1, uint32_t> id_537 {  id_536  };
                            Size let_res_538;
                            {
                              Vec<1, uint32_t> lebsz_ref_304 { id_537 };
                              bool while_flag_539 { true };
                              do {
                                uint8_t id_540 { 0 };
                                uint32_t id_541 { n_ref_303[id_540] };
                                uint8_t id_542 { 0 };
                                uint32_t id_543 { lebsz_ref_304[id_542] };
                                uint8_t id_544 { 7 };
                                uint32_t id_545 { uint32_t(id_543 << id_544) };
                                bool id_546 { bool(id_541 >= id_545) };
                                while_flag_539 = id_546;
                                if (while_flag_539) {
                                  uint8_t id_547 { 0 };
                                  uint8_t id_548 { 0 };
                                  uint32_t id_549 { lebsz_ref_304[id_548] };
                                  uint32_t id_550 { 1U };
                                  uint32_t id_551 { uint32_t(id_549 + id_550) };
                                  Void id_552 { ((void)(lebsz_ref_304[id_547] = id_551), VOID) };
                                  (void)id_552;
                                }
                              } while (while_flag_539);
                              (void)VOID;
                              uint8_t id_553 { 0 };
                              uint32_t id_554 { lebsz_ref_304[id_553] };
                              Size id_555 { Size(id_554) };
                              let_res_538 = id_555;
                            }
                            let_res_535 = let_res_538;
                          }
                          Size id_556 { Size(sz_302 + let_res_535) };
                          Vec<1, Size> id_557 {  id_556  };
                          Size let_res_558;
                          {
                            Vec<1, Size> sz_ref_305 { id_557 };
                            int32_t id_559 { 0L };
                            Vec<1, int32_t> id_560 {  id_559  };
                            {
                              Vec<1, int32_t> repeat_n_306 { id_560 };
                              bool while_flag_561 { true };
                              do {
                                uint8_t id_562 { 0 };
                                int32_t id_563 { repeat_n_300[id_562] };
                                uint8_t id_564 { 0 };
                                int32_t id_565 { repeat_n_291[id_564] };
                                ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_566 { p_0[id_565] };
                                ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_567 { std::get<1>(id_566) };
                                Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> id_568 { id_567.filters };
                                ::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c id_569 { id_568[id_563] };
                                Arr<dessser::gen::raql_value::t_ext> id_570 { std::get<1>(id_569) };
                                uint32_t id_571 { id_570.size() };
                                int32_t id_572 { int32_t(id_571) };
                                uint8_t id_573 { 0 };
                                int32_t id_574 { repeat_n_306[id_573] };
                                bool id_575 { bool(id_572 > id_574) };
                                while_flag_561 = id_575;
                                if (while_flag_561) {
                                  uint8_t id_576 { 0 };
                                  uint8_t id_577 { 0 };
                                  Size id_578 { sz_ref_305[id_577] };
                                  auto fun579 { dessser::gen::raql_value::sersize_of_row_binary };
                                  uint8_t id_580 { 0 };
                                  int32_t id_581 { repeat_n_306[id_580] };
                                  uint8_t id_582 { 0 };
                                  int32_t id_583 { repeat_n_300[id_582] };
                                  uint8_t id_584 { 0 };
                                  int32_t id_585 { repeat_n_291[id_584] };
                                  ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_586 { p_0[id_585] };
                                  ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_587 { std::get<1>(id_586) };
                                  Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> id_588 { id_587.filters };
                                  ::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c id_589 { id_588[id_583] };
                                  Arr<dessser::gen::raql_value::t_ext> id_590 { std::get<1>(id_589) };
                                  dessser::gen::raql_value::t_ext id_591 { id_590[id_581] };
                                  Size id_592 { fun579(id_591) };
                                  Size id_593 { Size(id_578 + id_592) };
                                  Void id_594 { ((void)(sz_ref_305[id_576] = id_593), VOID) };
                                  (void)id_594;
                                  uint8_t id_595 { 0 };
                                  uint8_t id_596 { 0 };
                                  int32_t id_597 { repeat_n_306[id_596] };
                                  int32_t id_598 { 1L };
                                  int32_t id_599 { int32_t(id_597 + id_598) };
                                  Void id_600 { ((void)(repeat_n_306[id_595] = id_599), VOID) };
                                  (void)id_600;
                                  (void)id_600;
                                }
                              } while (while_flag_561);
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_601 { 0 };
                            Size id_602 { sz_ref_305[id_601] };
                            let_res_558 = id_602;
                          }
                          let_res_523 = let_res_558;
                        }
                        Void id_603 { ((void)(sz_ref_299[id_518] = let_res_523), VOID) };
                        (void)id_603;
                        uint8_t id_604 { 0 };
                        uint8_t id_605 { 0 };
                        int32_t id_606 { repeat_n_300[id_605] };
                        int32_t id_607 { 1L };
                        int32_t id_608 { int32_t(id_606 + id_607) };
                        Void id_609 { ((void)(repeat_n_300[id_604] = id_608), VOID) };
                        (void)id_609;
                        (void)id_609;
                      }
                    } while (while_flag_507);
                    (void)VOID;
                  }
                  (void)VOID;
                  uint8_t id_610 { 0 };
                  Size id_611 { sz_ref_299[id_610] };
                  let_res_504 = id_611;
                }
                let_res_473 = let_res_504;
              }
              Size let_res_612;
              {
                Size sz_307 { let_res_473 };
                uint8_t id_613 { 0 };
                int32_t id_614 { repeat_n_291[id_613] };
                ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_615 { p_0[id_614] };
                ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_616 { std::get<1>(id_615) };
                Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> id_617 { id_616.channels };
                uint32_t id_618 { id_617.size() };
                Vec<1, uint32_t> id_619 {  id_618  };
                Size let_res_620;
                {
                  Vec<1, uint32_t> n_ref_308 { id_619 };
                  uint32_t id_621 { 1U };
                  Vec<1, uint32_t> id_622 {  id_621  };
                  Size let_res_623;
                  {
                    Vec<1, uint32_t> lebsz_ref_309 { id_622 };
                    bool while_flag_624 { true };
                    do {
                      uint8_t id_625 { 0 };
                      uint32_t id_626 { n_ref_308[id_625] };
                      uint8_t id_627 { 0 };
                      uint32_t id_628 { lebsz_ref_309[id_627] };
                      uint8_t id_629 { 7 };
                      uint32_t id_630 { uint32_t(id_628 << id_629) };
                      bool id_631 { bool(id_626 >= id_630) };
                      while_flag_624 = id_631;
                      if (while_flag_624) {
                        uint8_t id_632 { 0 };
                        uint8_t id_633 { 0 };
                        uint32_t id_634 { lebsz_ref_309[id_633] };
                        uint32_t id_635 { 1U };
                        uint32_t id_636 { uint32_t(id_634 + id_635) };
                        Void id_637 { ((void)(lebsz_ref_309[id_632] = id_636), VOID) };
                        (void)id_637;
                      }
                    } while (while_flag_624);
                    (void)VOID;
                    uint8_t id_638 { 0 };
                    uint32_t id_639 { lebsz_ref_309[id_638] };
                    Size id_640 { Size(id_639) };
                    let_res_623 = id_640;
                  }
                  let_res_620 = let_res_623;
                }
                Size id_641 { Size(sz_307 + let_res_620) };
                Vec<1, Size> id_642 {  id_641  };
                Size let_res_643;
                {
                  Vec<1, Size> sz_ref_310 { id_642 };
                  int32_t id_644 { 0L };
                  Vec<1, int32_t> id_645 {  id_644  };
                  {
                    Vec<1, int32_t> repeat_n_311 { id_645 };
                    bool while_flag_646 { true };
                    do {
                      uint8_t id_647 { 0 };
                      int32_t id_648 { repeat_n_291[id_647] };
                      ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_649 { p_0[id_648] };
                      ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_650 { std::get<1>(id_649) };
                      Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> id_651 { id_650.channels };
                      uint32_t id_652 { id_651.size() };
                      int32_t id_653 { int32_t(id_652) };
                      uint8_t id_654 { 0 };
                      int32_t id_655 { repeat_n_311[id_654] };
                      bool id_656 { bool(id_653 > id_655) };
                      while_flag_646 = id_656;
                      if (while_flag_646) {
                        uint8_t id_657 { 0 };
                        uint8_t id_658 { 0 };
                        Size id_659 { sz_ref_310[id_658] };
                        Size id_660 { 2UL };
                        Size id_661 { Size(id_659 + id_660) };
                        Size let_res_662;
                        {
                          Size sz_313 { id_661 };
                          uint8_t id_663 { 0 };
                          int32_t id_664 { repeat_n_311[id_663] };
                          uint8_t id_665 { 0 };
                          int32_t id_666 { repeat_n_291[id_665] };
                          ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_667 { p_0[id_666] };
                          ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_668 { std::get<1>(id_667) };
                          Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> id_669 { id_668.channels };
                          ::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085 id_670 { id_669[id_664] };
                          std::shared_ptr<::dessser::gen::output_specs::channel_specs>  id_671 { std::get<1>(id_670) };
                          Size id_672 { channel_specs_sersize_of_row_binary(id_671) };
                          Size id_673 { Size(sz_313 + id_672) };
                          let_res_662 = id_673;
                        }
                        Void id_674 { ((void)(sz_ref_310[id_657] = let_res_662), VOID) };
                        (void)id_674;
                        uint8_t id_675 { 0 };
                        uint8_t id_676 { 0 };
                        int32_t id_677 { repeat_n_311[id_676] };
                        int32_t id_678 { 1L };
                        int32_t id_679 { int32_t(id_677 + id_678) };
                        Void id_680 { ((void)(repeat_n_311[id_675] = id_679), VOID) };
                        (void)id_680;
                        (void)id_680;
                      }
                    } while (while_flag_646);
                    (void)VOID;
                  }
                  (void)VOID;
                  uint8_t id_681 { 0 };
                  Size id_682 { sz_ref_310[id_681] };
                  let_res_643 = id_682;
                }
                let_res_612 = let_res_643;
              }
              let_res_456 = let_res_612;
            }
            Void id_683 { ((void)(sz_ref_290[id_446] = let_res_456), VOID) };
            (void)id_683;
            uint8_t id_684 { 0 };
            uint8_t id_685 { 0 };
            int32_t id_686 { repeat_n_291[id_685] };
            int32_t id_687 { 1L };
            int32_t id_688 { int32_t(id_686 + id_687) };
            Void id_689 { ((void)(repeat_n_291[id_684] = id_688), VOID) };
            (void)id_689;
            (void)id_689;
          }
        } while (while_flag_440);
        (void)VOID;
      }
      (void)VOID;
      uint8_t id_690 { 0 };
      Size id_691 { sz_ref_290[id_690] };
      let_res_437 = id_691;
    }
    return let_res_437;
  }
   };
  return fun412;
}
std::function<Size(t&)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_128" (let-pair "dfloat_fst_126" "dfloat_snd_127" (read-u64 little-endian (param 0)) (make-tup (float-of-u64 (identifier "dfloat_fst_126")) (identifier "dfloat_snd_127")))
        (let-pair "dtup_fst_129" "dtup_snd_130" (identifier "dtup_128")
          (let "dtup_134" (let-pair "di16_fst_132" "di16_snd_133" (read-u16 little-endian (identifier "dtup_snd_130")) (make-tup (to-i16 (identifier "di16_fst_132")) (identifier "di16_snd_133")))
            (let-pair "dtup_fst_135" "dtup_snd_136" (identifier "dtup_134")
              (let-pair "du32_fst_138" "du32_snd_139" (read-u32 little-endian (identifier "dtup_snd_136"))
                (make-tup (make-tup (identifier "dtup_fst_129") (identifier "dtup_fst_135") (identifier "du32_fst_138")) (identifier "du32_snd_139"))))))))
 */
static std::function<::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca(Pointer)> channel_specs_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca(Pointer)> fun692 { [&fun692](Pointer p_0) {
    ::dessser::gen::output_specs::tf568409f41c9c0a265f7302110fc9084 id_693 { p_0.readU64Le() };
    ::dessser::gen::output_specs::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_694;
    {
      auto dfloat_fst_126 { std::get<0>(id_693) };
      auto dfloat_snd_127 { std::get<1>(id_693) };
      double id_695 { float_of_qword(dfloat_fst_126) };
      ::dessser::gen::output_specs::t5375de390f9cb5ae2ee5880ea1674828 id_696 { id_695, dfloat_snd_127 };
      letpair_res_694 = id_696;
    }
    ::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca let_res_697;
    {
      ::dessser::gen::output_specs::t5375de390f9cb5ae2ee5880ea1674828 dtup_128 { letpair_res_694 };
      ::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca letpair_res_698;
      {
        auto dtup_fst_129 { std::get<0>(dtup_128) };
        auto dtup_snd_130 { std::get<1>(dtup_128) };
        ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b id_699 { dtup_snd_130.readU16Le() };
        ::dessser::gen::output_specs::tb196bf1fcefaf5153b7e0f5e479aaa96 letpair_res_700;
        {
          auto di16_fst_132 { std::get<0>(id_699) };
          auto di16_snd_133 { std::get<1>(id_699) };
          int16_t id_701 { int16_t(di16_fst_132) };
          ::dessser::gen::output_specs::tb196bf1fcefaf5153b7e0f5e479aaa96 id_702 { id_701, di16_snd_133 };
          letpair_res_700 = id_702;
        }
        ::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca let_res_703;
        {
          ::dessser::gen::output_specs::tb196bf1fcefaf5153b7e0f5e479aaa96 dtup_134 { letpair_res_700 };
          ::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca letpair_res_704;
          {
            auto dtup_fst_135 { std::get<0>(dtup_134) };
            auto dtup_snd_136 { std::get<1>(dtup_134) };
            ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 id_705 { dtup_snd_136.readU32Le() };
            ::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca letpair_res_706;
            {
              auto du32_fst_138 { std::get<0>(id_705) };
              auto du32_snd_139 { std::get<1>(id_705) };
              std::shared_ptr<::dessser::gen::output_specs::channel_specs>  id_707 { std::make_shared<::dessser::gen::output_specs::channel_specs>(dtup_fst_129, dtup_fst_135, du32_fst_138) };
              ::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca id_708 { id_707, du32_snd_139 };
              letpair_res_706 = id_708;
            }
            letpair_res_704 = letpair_res_706;
          }
          let_res_703 = letpair_res_704;
        }
        letpair_res_698 = let_res_703;
      }
      let_res_697 = letpair_res_698;
    }
    return let_res_697;
  }
   };
  return fun692;
}
std::function<::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca(Pointer)> channel_specs_of_row_binary(channel_specs_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_123" "make_snd_124"
        (let "dsum1_95" (let-pair "du16_fst_90" "du16_snd_91" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_90") (identifier "du16_snd_91")))
          (let-pair "dsum1_fst_96" "dsum1_snd_97" (identifier "dsum1_95")
            (if (eq (u16 0) (identifier "dsum1_fst_96")) (make-tup (construct "[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" 0 (nop)) (identifier "dsum1_snd_97"))
              (seq (assert (eq (identifier "dsum1_fst_96") (u16 1)))
                (let "drec_101" (let-pair "dbool_fst_99" "dbool_snd_100" (read-u8 (identifier "dsum1_snd_97")) (make-tup (not (eq (identifier "dbool_fst_99") (u8 0))) (identifier "dbool_snd_100")))
                  (let-pair "drec_fst_102" "drec_snd_103" (identifier "drec_101")
                    (let "drec_107" (let-pair "du32_fst_105" "du32_snd_106" (read-u32 little-endian (identifier "drec_snd_103")) (make-tup (identifier "du32_fst_105") (identifier "du32_snd_106")))
                      (let-pair "drec_fst_108" "drec_snd_109" (identifier "drec_107")
                        (let-pair "du32_fst_111" "du32_snd_112" (read-u32 little-endian (identifier "drec_snd_109"))
                          (make-tup
                            (construct "[RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]" 1
                              (make-rec (string "num_batches") (identifier "du32_fst_111") (string "batch_size") (identifier "drec_fst_108") (string "with_index") (identifier "drec_fst_102"))) 
                            (identifier "du32_snd_112"))))))))))) (make-tup (identifier "make_fst_123") (identifier "make_snd_124"))))
 */
static std::function<::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956(Pointer)> file_type_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956(Pointer)> fun709 { [&fun709](Pointer p_0) {
    ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b id_710 { p_0.readU16Le() };
    ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b letpair_res_711;
    {
      auto du16_fst_90 { std::get<0>(id_710) };
      auto du16_snd_91 { std::get<1>(id_710) };
      ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b id_712 { du16_fst_90, du16_snd_91 };
      letpair_res_711 = id_712;
    }
    ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 let_res_713;
    {
      ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b dsum1_95 { letpair_res_711 };
      ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 letpair_res_714;
      {
        auto dsum1_fst_96 { std::get<0>(dsum1_95) };
        auto dsum1_snd_97 { std::get<1>(dsum1_95) };
        uint16_t id_715 { 0 };
        bool id_716 { bool(id_715 == dsum1_fst_96) };
        ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 choose_res_717;
        if (id_716) {
          (void)VOID;
          std::shared_ptr<::dessser::gen::output_specs::file_type>  id_718 { std::make_shared<::dessser::gen::output_specs::file_type>(std::in_place_index<0>, VOID) };
          ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 id_719 { id_718, dsum1_snd_97 };
          choose_res_717 = id_719;
        } else {
          uint16_t id_720 { 1 };
          bool id_721 { bool(dsum1_fst_96 == id_720) };
          Void id_722 { ((void)(assert(id_721)), VOID) };
          (void)id_722;
          ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 id_723 { dsum1_snd_97.readU8() };
          ::dessser::gen::output_specs::t8f6cce063b0da10e7eea29b507eded2e letpair_res_724;
          {
            auto dbool_fst_99 { std::get<0>(id_723) };
            auto dbool_snd_100 { std::get<1>(id_723) };
            uint8_t id_725 { 0 };
            bool id_726 { bool(dbool_fst_99 == id_725) };
            bool id_727 { ! id_726 };
            ::dessser::gen::output_specs::t8f6cce063b0da10e7eea29b507eded2e id_728 { id_727, dbool_snd_100 };
            letpair_res_724 = id_728;
          }
          ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 let_res_729;
          {
            ::dessser::gen::output_specs::t8f6cce063b0da10e7eea29b507eded2e drec_101 { letpair_res_724 };
            ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 letpair_res_730;
            {
              auto drec_fst_102 { std::get<0>(drec_101) };
              auto drec_snd_103 { std::get<1>(drec_101) };
              ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 id_731 { drec_snd_103.readU32Le() };
              ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_732;
              {
                auto du32_fst_105 { std::get<0>(id_731) };
                auto du32_snd_106 { std::get<1>(id_731) };
                ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 id_733 { du32_fst_105, du32_snd_106 };
                letpair_res_732 = id_733;
              }
              ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 let_res_734;
              {
                ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 drec_107 { letpair_res_732 };
                ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 letpair_res_735;
                {
                  auto drec_fst_108 { std::get<0>(drec_107) };
                  auto drec_snd_109 { std::get<1>(drec_107) };
                  ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 id_736 { drec_snd_109.readU32Le() };
                  ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 letpair_res_737;
                  {
                    auto du32_fst_111 { std::get<0>(id_736) };
                    auto du32_snd_112 { std::get<1>(id_736) };
                    ::dessser::gen::output_specs::t55234e0caf6cba9a33ddd852496b1d7b id_738 { drec_fst_108, du32_fst_111, drec_fst_102 };
                    std::shared_ptr<::dessser::gen::output_specs::file_type>  id_739 { std::make_shared<::dessser::gen::output_specs::file_type>(std::in_place_index<1>, id_738) };
                    ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 id_740 { id_739, du32_snd_112 };
                    letpair_res_737 = id_740;
                  }
                  letpair_res_735 = letpair_res_737;
                }
                let_res_734 = letpair_res_735;
              }
              letpair_res_730 = let_res_734;
            }
            let_res_729 = letpair_res_730;
          }
          choose_res_717 = let_res_729;
        }
        letpair_res_714 = choose_res_717;
      }
      let_res_713 = letpair_res_714;
    }
    ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 letpair_res_741;
    {
      auto make_fst_123 { std::get<0>(let_res_713) };
      auto make_snd_124 { std::get<1>(let_res_713) };
      ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 id_742 { make_fst_123, make_snd_124 };
      letpair_res_741 = id_742;
    }
    return letpair_res_741;
  }
   };
  return fun709;
}
std::function<::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956(Pointer)> file_type_of_row_binary(file_type_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_87" "make_snd_88"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let-pair "dsum2_fst_84" "dsum2_snd_85" (apply (ext-identifier file_path of-row-binary) (identifier "dsum1_snd_64"))
                (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]" 0 (identifier "dsum2_fst_84")) (identifier "dsum2_snd_85")))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let "dstring1_74"
                  (let "leb_ref_68" (make-vec (u32 0))
                    (let "shft_ref_69" (make-vec (u8 0))
                      (let "p_ref_70" (make-vec (identifier "dsum1_snd_64"))
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
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_68"))) (unsafe-nth (u8 0) (identifier "p_ref_70")))))))
                  (let-pair "dstring1_fst_75" "dstring1_snd_76" (identifier "dstring1_74")
                    (let-pair "dstring2_fst_78" "dstring2_snd_79" (read-bytes (identifier "dstring1_snd_76") (identifier "dstring1_fst_75"))
                      (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]" 1 (string-of-bytes (identifier "dstring2_fst_78"))) (identifier "dstring2_snd_79")))))
                (seq (assert (eq (identifier "dsum1_fst_63") (u16 2)))
                  (let-pair "dsum2_fst_66" "dsum2_snd_67" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                    (make-tup (construct "[DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]" 2 (identifier "dsum2_fst_66")) (identifier "dsum2_snd_67"))))))))
        (make-tup (identifier "make_fst_87") (identifier "make_snd_88"))))
 */
static std::function<::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf(Pointer)> recipient_of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf(Pointer)> fun743 { [&fun743](Pointer p_0) {
    ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b id_744 { p_0.readU16Le() };
    ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b letpair_res_745;
    {
      auto du16_fst_57 { std::get<0>(id_744) };
      auto du16_snd_58 { std::get<1>(id_744) };
      ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b id_746 { du16_fst_57, du16_snd_58 };
      letpair_res_745 = id_746;
    }
    ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf let_res_747;
    {
      ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_745 };
      ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf letpair_res_748;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_749 { 0 };
        bool id_750 { bool(id_749 == dsum1_fst_63) };
        ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf choose_res_751;
        if (id_750) {
          auto fun752 { dessser::gen::file_path::of_row_binary };
          ::dessser::gen::output_specs::tb06ffbf6da2300d8f0de21eea734e5f2 id_753 { fun752(dsum1_snd_64) };
          ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf letpair_res_754;
          {
            auto dsum2_fst_84 { std::get<0>(id_753) };
            auto dsum2_snd_85 { std::get<1>(id_753) };
            std::shared_ptr<::dessser::gen::output_specs::recipient>  id_755 { std::make_shared<::dessser::gen::output_specs::recipient>(std::in_place_index<0>, dsum2_fst_84) };
            ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf id_756 { id_755, dsum2_snd_85 };
            letpair_res_754 = id_756;
          }
          choose_res_751 = letpair_res_754;
        } else {
          uint16_t id_757 { 1 };
          bool id_758 { bool(id_757 == dsum1_fst_63) };
          ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf choose_res_759;
          if (id_758) {
            uint32_t id_760 { 0U };
            Vec<1, uint32_t> id_761 {  id_760  };
            ::dessser::gen::output_specs::t044960e524fd6ec1bfc06410ce526709 let_res_762;
            {
              Vec<1, uint32_t> leb_ref_68 { id_761 };
              uint8_t id_763 { 0 };
              Vec<1, uint8_t> id_764 {  id_763  };
              ::dessser::gen::output_specs::t044960e524fd6ec1bfc06410ce526709 let_res_765;
              {
                Vec<1, uint8_t> shft_ref_69 { id_764 };
                Vec<1, Pointer> id_766 {  dsum1_snd_64  };
                ::dessser::gen::output_specs::t044960e524fd6ec1bfc06410ce526709 let_res_767;
                {
                  Vec<1, Pointer> p_ref_70 { id_766 };
                  bool while_flag_768 { true };
                  do {
                    uint8_t id_769 { 0 };
                    Pointer id_770 { p_ref_70[id_769] };
                    ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 id_771 { id_770.readU8() };
                    bool let_res_772;
                    {
                      ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_71 { id_771 };
                      bool letpair_res_773;
                      {
                        auto leb128_fst_72 { std::get<0>(leb128_71) };
                        auto leb128_snd_73 { std::get<1>(leb128_71) };
                        uint8_t id_774 { 0 };
                        Void id_775 { ((void)(p_ref_70[id_774] = leb128_snd_73), VOID) };
                        (void)id_775;
                        uint8_t id_776 { 0 };
                        uint8_t id_777 { 127 };
                        uint8_t id_778 { uint8_t(leb128_fst_72 & id_777) };
                        uint32_t id_779 { uint32_t(id_778) };
                        uint8_t id_780 { 0 };
                        uint8_t id_781 { shft_ref_69[id_780] };
                        uint32_t id_782 { uint32_t(id_779 << id_781) };
                        uint8_t id_783 { 0 };
                        uint32_t id_784 { leb_ref_68[id_783] };
                        uint32_t id_785 { uint32_t(id_782 | id_784) };
                        Void id_786 { ((void)(leb_ref_68[id_776] = id_785), VOID) };
                        (void)id_786;
                        uint8_t id_787 { 0 };
                        uint8_t id_788 { 0 };
                        uint8_t id_789 { shft_ref_69[id_788] };
                        uint8_t id_790 { 7 };
                        uint8_t id_791 { uint8_t(id_789 + id_790) };
                        Void id_792 { ((void)(shft_ref_69[id_787] = id_791), VOID) };
                        (void)id_792;
                        uint8_t id_793 { 128 };
                        bool id_794 { bool(leb128_fst_72 >= id_793) };
                        letpair_res_773 = id_794;
                      }
                      let_res_772 = letpair_res_773;
                    }
                    while_flag_768 = let_res_772;
                    if (while_flag_768) {
                      (void)VOID;
                    }
                  } while (while_flag_768);
                  (void)VOID;
                  uint8_t id_795 { 0 };
                  uint32_t id_796 { leb_ref_68[id_795] };
                  Size id_797 { Size(id_796) };
                  uint8_t id_798 { 0 };
                  Pointer id_799 { p_ref_70[id_798] };
                  ::dessser::gen::output_specs::t044960e524fd6ec1bfc06410ce526709 id_800 { id_797, id_799 };
                  let_res_767 = id_800;
                }
                let_res_765 = let_res_767;
              }
              let_res_762 = let_res_765;
            }
            ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf let_res_801;
            {
              ::dessser::gen::output_specs::t044960e524fd6ec1bfc06410ce526709 dstring1_74 { let_res_762 };
              ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf letpair_res_802;
              {
                auto dstring1_fst_75 { std::get<0>(dstring1_74) };
                auto dstring1_snd_76 { std::get<1>(dstring1_74) };
                ::dessser::gen::output_specs::t5887709cc43c8c8e24d28211e8c970a2 id_803 { dstring1_snd_76.readBytes(dstring1_fst_75) };
                ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf letpair_res_804;
                {
                  auto dstring2_fst_78 { std::get<0>(id_803) };
                  auto dstring2_snd_79 { std::get<1>(id_803) };
                  std::string id_805 { dstring2_fst_78.toString() };
                  std::shared_ptr<::dessser::gen::output_specs::recipient>  id_806 { std::make_shared<::dessser::gen::output_specs::recipient>(std::in_place_index<1>, id_805) };
                  ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf id_807 { id_806, dstring2_snd_79 };
                  letpair_res_804 = id_807;
                }
                letpair_res_802 = letpair_res_804;
              }
              let_res_801 = letpair_res_802;
            }
            choose_res_759 = let_res_801;
          } else {
            uint16_t id_808 { 2 };
            bool id_809 { bool(dsum1_fst_63 == id_808) };
            Void id_810 { ((void)(assert(id_809)), VOID) };
            (void)id_810;
            auto fun811 { dessser::gen::sync_key::of_row_binary };
            ::dessser::gen::output_specs::t9bda35a83af38220b883fe5d84e6ed9f id_812 { fun811(dsum1_snd_64) };
            ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf letpair_res_813;
            {
              auto dsum2_fst_66 { std::get<0>(id_812) };
              auto dsum2_snd_67 { std::get<1>(id_812) };
              std::shared_ptr<::dessser::gen::output_specs::recipient>  id_814 { std::make_shared<::dessser::gen::output_specs::recipient>(std::in_place_index<2>, dsum2_fst_66) };
              ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf id_815 { id_814, dsum2_snd_67 };
              letpair_res_813 = id_815;
            }
            choose_res_759 = letpair_res_813;
          }
          choose_res_751 = choose_res_759;
        }
        letpair_res_748 = choose_res_751;
      }
      let_res_747 = letpair_res_748;
    }
    ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf letpair_res_816;
    {
      auto make_fst_87 { std::get<0>(let_res_747) };
      auto make_snd_88 { std::get<1>(let_res_747) };
      ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf id_817 { make_fst_87, make_snd_88 };
      letpair_res_816 = id_817;
    }
    return letpair_res_816;
  }
   };
  return fun743;
}
std::function<::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf(Pointer)> recipient_of_row_binary(recipient_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "dlist4_fst_272" "dlist4_snd_273"
        (let "dlist1_155"
          (let "leb_ref_146" (make-vec (u32 0))
            (let "shft_ref_147" (make-vec (u8 0))
              (let "p_ref_148" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_149" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_148")))
                      (let-pair "leb128_fst_150" "leb128_snd_151" (identifier "leb128_149")
                        (seq (set-vec (u8 0) (identifier "p_ref_148") (identifier "leb128_snd_151"))
                          (set-vec (u8 0) (identifier "leb_ref_146")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_150") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_147"))) (unsafe-nth (u8 0) (identifier "leb_ref_146"))))
                          (set-vec (u8 0) (identifier "shft_ref_147") (add (unsafe-nth (u8 0) (identifier "shft_ref_147")) (u8 7))) 
                          (ge (identifier "leb128_fst_150") (u8 128))))) 
                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_146")) (unsafe-nth (u8 0) (identifier "p_ref_148")))))))
          (let-pair "dlist1_fst_156" "dlist1_snd_157" (identifier "dlist1_155")
            (let "inits_src_ref_158"
              (make-vec
                (make-tup
                  (end-of-list "((recipient AS [DirectFile $file_path | IndirectFile STRING | SyncKey $sync_key]); {file_type: (file_type AS [RingBuf Void | Orc {with_index: BOOL; batch_size: U32; num_batches: U32}]); fieldmask: $fieldmask; filters: (U16; $raql_value[])[]; channels: (U16; (channel_specs AS (FLOAT; I16; U32)))[]})")
                  (identifier "dlist1_snd_157")))
              (seq
                (let "repeat_n_159" (make-vec (i32 0))
                  (while (gt (to-i32 (identifier "dlist1_fst_156")) (unsafe-nth (u8 0) (identifier "repeat_n_159")))
                    (seq
                      (let "dlist2_160" (unsafe-nth (u8 0) (identifier "inits_src_ref_158"))
                        (let-pair "dlist2_fst_161" "dlist2_snd_162" (identifier "dlist2_160")
                          (set-vec (u8 0) (identifier "inits_src_ref_158")
                            (let "dtup_163" (apply (identifier "recipient-of-row-binary") (identifier "dlist2_snd_162"))
                              (let-pair "dtup_fst_164" "dtup_snd_165" 
                                (identifier "dtup_163")
                                (let "drec_166" (apply (identifier "file_type-of-row-binary") (identifier "dtup_snd_165"))
                                  (let-pair "drec_fst_167" "drec_snd_168" 
                                    (identifier "drec_166")
                                    (let "drec_169" (apply (ext-identifier fieldmask of-row-binary) (identifier "drec_snd_168"))
                                      (let-pair "drec_fst_170" "drec_snd_171" 
                                        (identifier "drec_169")
                                        (let "drec_227"
                                          (let-pair "dlist4_fst_225" "dlist4_snd_226"
                                            (let "dlist1_181"
                                              (let "leb_ref_172" (make-vec (u32 0))
                                                (let "shft_ref_173" (make-vec (u8 0))
                                                  (let "p_ref_174" (make-vec (identifier "drec_snd_171"))
                                                    (seq
                                                      (while
                                                        (let "leb128_175" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_174")))
                                                          (let-pair "leb128_fst_176" "leb128_snd_177" 
                                                            (identifier "leb128_175")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_174") (identifier "leb128_snd_177"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_172")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_176") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_173")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_172")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_173") (add (unsafe-nth (u8 0) (identifier "shft_ref_173")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_176") (u8 128))))) 
                                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_172")) (unsafe-nth (u8 0) (identifier "p_ref_174")))))))
                                              (let-pair "dlist1_fst_182" "dlist1_snd_183" 
                                                (identifier "dlist1_181")
                                                (let "inits_src_ref_184" 
                                                  (make-vec (make-tup (end-of-list "(U16; $raql_value[])") (identifier "dlist1_snd_183")))
                                                  (seq
                                                    (let "repeat_n_185" 
                                                      (make-vec (i32 0))
                                                      (while (gt (to-i32 (identifier "dlist1_fst_182")) (unsafe-nth (u8 0) (identifier "repeat_n_185")))
                                                        (seq
                                                          (let "dlist2_186" 
                                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_184"))
                                                            (let-pair "dlist2_fst_187" "dlist2_snd_188" 
                                                              (identifier "dlist2_186")
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "inits_src_ref_184")
                                                                (let "dtup_192"
                                                                  (let-pair "du16_fst_190" "du16_snd_191" (read-u16 little-endian (identifier "dlist2_snd_188")) (make-tup (identifier "du16_fst_190") (identifier "du16_snd_191")))
                                                                  (let-pair "dtup_fst_193" "dtup_snd_194" 
                                                                    (identifier "dtup_192")
                                                                    (let-pair "dlist4_fst_216" "dlist4_snd_217"
                                                                    (let "dlist1_204"
                                                                    (let "leb_ref_195" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_196" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_197" 
                                                                    (make-vec (identifier "dtup_snd_194"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_198" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_197")))
                                                                    (let-pair "leb128_fst_199" "leb128_snd_200" 
                                                                    (identifier "leb128_198")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_197") (identifier "leb128_snd_200"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_195")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_199") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_196")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_195")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_196") (add (unsafe-nth (u8 0) (identifier "shft_ref_196")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_199") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_195")) (unsafe-nth (u8 0) (identifier "p_ref_197")))))))
                                                                    (let-pair "dlist1_fst_205" "dlist1_snd_206" 
                                                                    (identifier "dlist1_204")
                                                                    (let "inits_src_ref_207" 
                                                                    (make-vec (make-tup (end-of-list "$raql_value") (identifier "dlist1_snd_206")))
                                                                    (seq
                                                                    (let "repeat_n_208" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_205")) (unsafe-nth (u8 0) (identifier "repeat_n_208")))
                                                                    (seq
                                                                    (let "dlist2_209" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_207"))
                                                                    (let-pair "dlist2_fst_210" "dlist2_snd_211" 
                                                                    (identifier "dlist2_209")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_207")
                                                                    (let-pair "dlist3_fst_213" "dlist3_snd_214" 
                                                                    (apply (ext-identifier raql_value of-row-binary) (identifier "dlist2_snd_211"))
                                                                    (make-tup (cons (identifier "dlist3_fst_213") (identifier "dlist2_fst_210")) (identifier "dlist3_snd_214"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_208") (add (unsafe-nth (u8 0) (identifier "repeat_n_208")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_207"))))))
                                                                    (make-tup 
                                                                    (cons (make-tup (identifier "dtup_fst_193") (arr-of-lst-rev (identifier "dlist4_fst_216"))) (identifier "dlist2_fst_187")) 
                                                                    (identifier "dlist4_snd_217")))))))) 
                                                          (set-vec (u8 0) (identifier "repeat_n_185") (add (unsafe-nth (u8 0) (identifier "repeat_n_185")) (i32 1)))))) 
                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_184")))))) 
                                            (make-tup (arr-of-lst-rev (identifier "dlist4_fst_225")) (identifier "dlist4_snd_226")))
                                          (let-pair "drec_fst_228" "drec_snd_229" 
                                            (identifier "drec_227")
                                            (let-pair "dlist4_fst_260" "dlist4_snd_261"
                                              (let "dlist1_239"
                                                (let "leb_ref_230" (make-vec (u32 0))
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
                                                              (seq (set-vec (u8 0) (identifier "p_ref_232") (identifier "leb128_snd_235"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_230")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_234") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_231")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_230")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_231") (add (unsafe-nth (u8 0) (identifier "shft_ref_231")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_234") (u8 128))))) 
                                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_230")) (unsafe-nth (u8 0) (identifier "p_ref_232")))))))
                                                (let-pair "dlist1_fst_240" "dlist1_snd_241" 
                                                  (identifier "dlist1_239")
                                                  (let "inits_src_ref_242" 
                                                    (make-vec (make-tup (end-of-list "(U16; (channel_specs AS (FLOAT; I16; U32)))") (identifier "dlist1_snd_241")))
                                                    (seq
                                                      (let "repeat_n_243" 
                                                        (make-vec (i32 0))
                                                        (while (gt (to-i32 (identifier "dlist1_fst_240")) (unsafe-nth (u8 0) (identifier "repeat_n_243")))
                                                          (seq
                                                            (let "dlist2_244" 
                                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_242"))
                                                              (let-pair "dlist2_fst_245" "dlist2_snd_246" 
                                                                (identifier "dlist2_244")
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "inits_src_ref_242")
                                                                  (let "dtup_250"
                                                                    (let-pair "du16_fst_248" "du16_snd_249" 
                                                                    (read-u16 little-endian (identifier "dlist2_snd_246")) 
                                                                    (make-tup (identifier "du16_fst_248") (identifier "du16_snd_249")))
                                                                    (let-pair "dtup_fst_251" "dtup_snd_252" 
                                                                    (identifier "dtup_250")
                                                                    (let-pair "dtup_fst_254" "dtup_snd_255" 
                                                                    (apply (identifier "channel_specs-of-row-binary") (identifier "dtup_snd_252"))
                                                                    (make-tup (cons (make-tup (identifier "dtup_fst_251") (identifier "dtup_fst_254")) (identifier "dlist2_fst_245")) (identifier "dtup_snd_255"))))))))
                                                            (set-vec (u8 0) (identifier "repeat_n_243") (add (unsafe-nth (u8 0) (identifier "repeat_n_243")) (i32 1)))))) 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_242"))))))
                                              (make-tup
                                                (cons
                                                  (make-tup (identifier "dtup_fst_164")
                                                    (make-rec (string "channels") 
                                                      (arr-of-lst-rev (identifier "dlist4_fst_260")) 
                                                      (string "filters") 
                                                      (identifier "drec_fst_228") 
                                                      (string "fieldmask") 
                                                      (identifier "drec_fst_170") 
                                                      (string "file_type") 
                                                      (identifier "drec_fst_167"))) 
                                                  (identifier "dlist2_fst_161")) 
                                                (identifier "dlist4_snd_261")))))))))))))) 
                      (set-vec (u8 0) (identifier "repeat_n_159") (add (unsafe-nth (u8 0) (identifier "repeat_n_159")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "inits_src_ref_158")))))) 
        (make-tup (arr-of-lst-rev (identifier "dlist4_fst_272")) (identifier "dlist4_snd_273"))))
 */
static std::function<::dessser::gen::output_specs::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::output_specs::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> fun818 { [&fun818](Pointer p_0) {
    uint32_t id_819 { 0U };
    Vec<1, uint32_t> id_820 {  id_819  };
    ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_821;
    {
      Vec<1, uint32_t> leb_ref_146 { id_820 };
      uint8_t id_822 { 0 };
      Vec<1, uint8_t> id_823 {  id_822  };
      ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_824;
      {
        Vec<1, uint8_t> shft_ref_147 { id_823 };
        Vec<1, Pointer> id_825 {  p_0  };
        ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_826;
        {
          Vec<1, Pointer> p_ref_148 { id_825 };
          bool while_flag_827 { true };
          do {
            uint8_t id_828 { 0 };
            Pointer id_829 { p_ref_148[id_828] };
            ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 id_830 { id_829.readU8() };
            bool let_res_831;
            {
              ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_149 { id_830 };
              bool letpair_res_832;
              {
                auto leb128_fst_150 { std::get<0>(leb128_149) };
                auto leb128_snd_151 { std::get<1>(leb128_149) };
                uint8_t id_833 { 0 };
                Void id_834 { ((void)(p_ref_148[id_833] = leb128_snd_151), VOID) };
                (void)id_834;
                uint8_t id_835 { 0 };
                uint8_t id_836 { 127 };
                uint8_t id_837 { uint8_t(leb128_fst_150 & id_836) };
                uint32_t id_838 { uint32_t(id_837) };
                uint8_t id_839 { 0 };
                uint8_t id_840 { shft_ref_147[id_839] };
                uint32_t id_841 { uint32_t(id_838 << id_840) };
                uint8_t id_842 { 0 };
                uint32_t id_843 { leb_ref_146[id_842] };
                uint32_t id_844 { uint32_t(id_841 | id_843) };
                Void id_845 { ((void)(leb_ref_146[id_835] = id_844), VOID) };
                (void)id_845;
                uint8_t id_846 { 0 };
                uint8_t id_847 { 0 };
                uint8_t id_848 { shft_ref_147[id_847] };
                uint8_t id_849 { 7 };
                uint8_t id_850 { uint8_t(id_848 + id_849) };
                Void id_851 { ((void)(shft_ref_147[id_846] = id_850), VOID) };
                (void)id_851;
                uint8_t id_852 { 128 };
                bool id_853 { bool(leb128_fst_150 >= id_852) };
                letpair_res_832 = id_853;
              }
              let_res_831 = letpair_res_832;
            }
            while_flag_827 = let_res_831;
            if (while_flag_827) {
              (void)VOID;
            }
          } while (while_flag_827);
          (void)VOID;
          uint8_t id_854 { 0 };
          uint32_t id_855 { leb_ref_146[id_854] };
          uint8_t id_856 { 0 };
          Pointer id_857 { p_ref_148[id_856] };
          ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 id_858 { id_855, id_857 };
          let_res_826 = id_858;
        }
        let_res_824 = let_res_826;
      }
      let_res_821 = let_res_824;
    }
    ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 let_res_859;
    {
      ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 dlist1_155 { let_res_821 };
      ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 letpair_res_860;
      {
        auto dlist1_fst_156 { std::get<0>(dlist1_155) };
        auto dlist1_snd_157 { std::get<1>(dlist1_155) };
        Lst<::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee> endoflist_861;
        ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 id_862 { endoflist_861, dlist1_snd_157 };
        Vec<1, ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4> id_863 {  id_862  };
        ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 let_res_864;
        {
          Vec<1, ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4> inits_src_ref_158 { id_863 };
          int32_t id_865 { 0L };
          Vec<1, int32_t> id_866 {  id_865  };
          {
            Vec<1, int32_t> repeat_n_159 { id_866 };
            bool while_flag_867 { true };
            do {
              int32_t id_868 { int32_t(dlist1_fst_156) };
              uint8_t id_869 { 0 };
              int32_t id_870 { repeat_n_159[id_869] };
              bool id_871 { bool(id_868 > id_870) };
              while_flag_867 = id_871;
              if (while_flag_867) {
                uint8_t id_872 { 0 };
                ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 id_873 { inits_src_ref_158[id_872] };
                {
                  ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 dlist2_160 { id_873 };
                  {
                    auto dlist2_fst_161 { std::get<0>(dlist2_160) };
                    auto dlist2_snd_162 { std::get<1>(dlist2_160) };
                    uint8_t id_874 { 0 };
                    ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf id_875 { recipient_of_row_binary(dlist2_snd_162) };
                    ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 let_res_876;
                    {
                      ::dessser::gen::output_specs::te1550c6bf972eb31c7ccc68cf1702abf dtup_163 { id_875 };
                      ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 letpair_res_877;
                      {
                        auto dtup_fst_164 { std::get<0>(dtup_163) };
                        auto dtup_snd_165 { std::get<1>(dtup_163) };
                        ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 id_878 { file_type_of_row_binary(dtup_snd_165) };
                        ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 let_res_879;
                        {
                          ::dessser::gen::output_specs::tdad017d875a8dc0f7c36bbe3dba6e956 drec_166 { id_878 };
                          ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 letpair_res_880;
                          {
                            auto drec_fst_167 { std::get<0>(drec_166) };
                            auto drec_snd_168 { std::get<1>(drec_166) };
                            auto fun881 { dessser::gen::fieldmask::of_row_binary };
                            ::dessser::gen::output_specs::t6c50fda18fa5bc68dda356ef9db827b3 id_882 { fun881(drec_snd_168) };
                            ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 let_res_883;
                            {
                              ::dessser::gen::output_specs::t6c50fda18fa5bc68dda356ef9db827b3 drec_169 { id_882 };
                              ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 letpair_res_884;
                              {
                                auto drec_fst_170 { std::get<0>(drec_169) };
                                auto drec_snd_171 { std::get<1>(drec_169) };
                                uint32_t id_885 { 0U };
                                Vec<1, uint32_t> id_886 {  id_885  };
                                ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_887;
                                {
                                  Vec<1, uint32_t> leb_ref_172 { id_886 };
                                  uint8_t id_888 { 0 };
                                  Vec<1, uint8_t> id_889 {  id_888  };
                                  ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_890;
                                  {
                                    Vec<1, uint8_t> shft_ref_173 { id_889 };
                                    Vec<1, Pointer> id_891 {  drec_snd_171  };
                                    ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_892;
                                    {
                                      Vec<1, Pointer> p_ref_174 { id_891 };
                                      bool while_flag_893 { true };
                                      do {
                                        uint8_t id_894 { 0 };
                                        Pointer id_895 { p_ref_174[id_894] };
                                        ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 id_896 { id_895.readU8() };
                                        bool let_res_897;
                                        {
                                          ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_175 { id_896 };
                                          bool letpair_res_898;
                                          {
                                            auto leb128_fst_176 { std::get<0>(leb128_175) };
                                            auto leb128_snd_177 { std::get<1>(leb128_175) };
                                            uint8_t id_899 { 0 };
                                            Void id_900 { ((void)(p_ref_174[id_899] = leb128_snd_177), VOID) };
                                            (void)id_900;
                                            uint8_t id_901 { 0 };
                                            uint8_t id_902 { 127 };
                                            uint8_t id_903 { uint8_t(leb128_fst_176 & id_902) };
                                            uint32_t id_904 { uint32_t(id_903) };
                                            uint8_t id_905 { 0 };
                                            uint8_t id_906 { shft_ref_173[id_905] };
                                            uint32_t id_907 { uint32_t(id_904 << id_906) };
                                            uint8_t id_908 { 0 };
                                            uint32_t id_909 { leb_ref_172[id_908] };
                                            uint32_t id_910 { uint32_t(id_907 | id_909) };
                                            Void id_911 { ((void)(leb_ref_172[id_901] = id_910), VOID) };
                                            (void)id_911;
                                            uint8_t id_912 { 0 };
                                            uint8_t id_913 { 0 };
                                            uint8_t id_914 { shft_ref_173[id_913] };
                                            uint8_t id_915 { 7 };
                                            uint8_t id_916 { uint8_t(id_914 + id_915) };
                                            Void id_917 { ((void)(shft_ref_173[id_912] = id_916), VOID) };
                                            (void)id_917;
                                            uint8_t id_918 { 128 };
                                            bool id_919 { bool(leb128_fst_176 >= id_918) };
                                            letpair_res_898 = id_919;
                                          }
                                          let_res_897 = letpair_res_898;
                                        }
                                        while_flag_893 = let_res_897;
                                        if (while_flag_893) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_893);
                                      (void)VOID;
                                      uint8_t id_920 { 0 };
                                      uint32_t id_921 { leb_ref_172[id_920] };
                                      uint8_t id_922 { 0 };
                                      Pointer id_923 { p_ref_174[id_922] };
                                      ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 id_924 { id_921, id_923 };
                                      let_res_892 = id_924;
                                    }
                                    let_res_890 = let_res_892;
                                  }
                                  let_res_887 = let_res_890;
                                }
                                ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 let_res_925;
                                {
                                  ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 dlist1_181 { let_res_887 };
                                  ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 letpair_res_926;
                                  {
                                    auto dlist1_fst_182 { std::get<0>(dlist1_181) };
                                    auto dlist1_snd_183 { std::get<1>(dlist1_181) };
                                    Lst<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> endoflist_927;
                                    ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 id_928 { endoflist_927, dlist1_snd_183 };
                                    Vec<1, ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78> id_929 {  id_928  };
                                    ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 let_res_930;
                                    {
                                      Vec<1, ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78> inits_src_ref_184 { id_929 };
                                      int32_t id_931 { 0L };
                                      Vec<1, int32_t> id_932 {  id_931  };
                                      {
                                        Vec<1, int32_t> repeat_n_185 { id_932 };
                                        bool while_flag_933 { true };
                                        do {
                                          int32_t id_934 { int32_t(dlist1_fst_182) };
                                          uint8_t id_935 { 0 };
                                          int32_t id_936 { repeat_n_185[id_935] };
                                          bool id_937 { bool(id_934 > id_936) };
                                          while_flag_933 = id_937;
                                          if (while_flag_933) {
                                            uint8_t id_938 { 0 };
                                            ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 id_939 { inits_src_ref_184[id_938] };
                                            {
                                              ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 dlist2_186 { id_939 };
                                              {
                                                auto dlist2_fst_187 { std::get<0>(dlist2_186) };
                                                auto dlist2_snd_188 { std::get<1>(dlist2_186) };
                                                uint8_t id_940 { 0 };
                                                ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b id_941 { dlist2_snd_188.readU16Le() };
                                                ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b letpair_res_942;
                                                {
                                                  auto du16_fst_190 { std::get<0>(id_941) };
                                                  auto du16_snd_191 { std::get<1>(id_941) };
                                                  ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b id_943 { du16_fst_190, du16_snd_191 };
                                                  letpair_res_942 = id_943;
                                                }
                                                ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 let_res_944;
                                                {
                                                  ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b dtup_192 { letpair_res_942 };
                                                  ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 letpair_res_945;
                                                  {
                                                    auto dtup_fst_193 { std::get<0>(dtup_192) };
                                                    auto dtup_snd_194 { std::get<1>(dtup_192) };
                                                    uint32_t id_946 { 0U };
                                                    Vec<1, uint32_t> id_947 {  id_946  };
                                                    ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_948;
                                                    {
                                                      Vec<1, uint32_t> leb_ref_195 { id_947 };
                                                      uint8_t id_949 { 0 };
                                                      Vec<1, uint8_t> id_950 {  id_949  };
                                                      ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_951;
                                                      {
                                                        Vec<1, uint8_t> shft_ref_196 { id_950 };
                                                        Vec<1, Pointer> id_952 {  dtup_snd_194  };
                                                        ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_953;
                                                        {
                                                          Vec<1, Pointer> p_ref_197 { id_952 };
                                                          bool while_flag_954 { true };
                                                          do {
                                                            uint8_t id_955 { 0 };
                                                            Pointer id_956 { p_ref_197[id_955] };
                                                            ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 id_957 { id_956.readU8() };
                                                            bool let_res_958;
                                                            {
                                                              ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_198 { id_957 };
                                                              bool letpair_res_959;
                                                              {
                                                                auto leb128_fst_199 { std::get<0>(leb128_198) };
                                                                auto leb128_snd_200 { std::get<1>(leb128_198) };
                                                                uint8_t id_960 { 0 };
                                                                Void id_961 { ((void)(p_ref_197[id_960] = leb128_snd_200), VOID) };
                                                                (void)id_961;
                                                                uint8_t id_962 { 0 };
                                                                uint8_t id_963 { 127 };
                                                                uint8_t id_964 { uint8_t(leb128_fst_199 & id_963) };
                                                                uint32_t id_965 { uint32_t(id_964) };
                                                                uint8_t id_966 { 0 };
                                                                uint8_t id_967 { shft_ref_196[id_966] };
                                                                uint32_t id_968 { uint32_t(id_965 << id_967) };
                                                                uint8_t id_969 { 0 };
                                                                uint32_t id_970 { leb_ref_195[id_969] };
                                                                uint32_t id_971 { uint32_t(id_968 | id_970) };
                                                                Void id_972 { ((void)(leb_ref_195[id_962] = id_971), VOID) };
                                                                (void)id_972;
                                                                uint8_t id_973 { 0 };
                                                                uint8_t id_974 { 0 };
                                                                uint8_t id_975 { shft_ref_196[id_974] };
                                                                uint8_t id_976 { 7 };
                                                                uint8_t id_977 { uint8_t(id_975 + id_976) };
                                                                Void id_978 { ((void)(shft_ref_196[id_973] = id_977), VOID) };
                                                                (void)id_978;
                                                                uint8_t id_979 { 128 };
                                                                bool id_980 { bool(leb128_fst_199 >= id_979) };
                                                                letpair_res_959 = id_980;
                                                              }
                                                              let_res_958 = letpair_res_959;
                                                            }
                                                            while_flag_954 = let_res_958;
                                                            if (while_flag_954) {
                                                              (void)VOID;
                                                            }
                                                          } while (while_flag_954);
                                                          (void)VOID;
                                                          uint8_t id_981 { 0 };
                                                          uint32_t id_982 { leb_ref_195[id_981] };
                                                          uint8_t id_983 { 0 };
                                                          Pointer id_984 { p_ref_197[id_983] };
                                                          ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 id_985 { id_982, id_984 };
                                                          let_res_953 = id_985;
                                                        }
                                                        let_res_951 = let_res_953;
                                                      }
                                                      let_res_948 = let_res_951;
                                                    }
                                                    ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7 let_res_986;
                                                    {
                                                      ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 dlist1_204 { let_res_948 };
                                                      ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7 letpair_res_987;
                                                      {
                                                        auto dlist1_fst_205 { std::get<0>(dlist1_204) };
                                                        auto dlist1_snd_206 { std::get<1>(dlist1_204) };
                                                        Lst<dessser::gen::raql_value::t_ext> endoflist_988;
                                                        ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7 id_989 { endoflist_988, dlist1_snd_206 };
                                                        Vec<1, ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7> id_990 {  id_989  };
                                                        ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7 let_res_991;
                                                        {
                                                          Vec<1, ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7> inits_src_ref_207 { id_990 };
                                                          int32_t id_992 { 0L };
                                                          Vec<1, int32_t> id_993 {  id_992  };
                                                          {
                                                            Vec<1, int32_t> repeat_n_208 { id_993 };
                                                            bool while_flag_994 { true };
                                                            do {
                                                              int32_t id_995 { int32_t(dlist1_fst_205) };
                                                              uint8_t id_996 { 0 };
                                                              int32_t id_997 { repeat_n_208[id_996] };
                                                              bool id_998 { bool(id_995 > id_997) };
                                                              while_flag_994 = id_998;
                                                              if (while_flag_994) {
                                                                uint8_t id_999 { 0 };
                                                                ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7 id_1000 { inits_src_ref_207[id_999] };
                                                                {
                                                                  ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7 dlist2_209 { id_1000 };
                                                                  {
                                                                    auto dlist2_fst_210 { std::get<0>(dlist2_209) };
                                                                    auto dlist2_snd_211 { std::get<1>(dlist2_209) };
                                                                    uint8_t id_1001 { 0 };
                                                                    auto fun1002 { dessser::gen::raql_value::of_row_binary };
                                                                    ::dessser::gen::output_specs::td46b7b5194a84c2e11400d9ca5d84700 id_1003 { fun1002(dlist2_snd_211) };
                                                                    ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7 letpair_res_1004;
                                                                    {
                                                                      auto dlist3_fst_213 { std::get<0>(id_1003) };
                                                                      auto dlist3_snd_214 { std::get<1>(id_1003) };
                                                                      Lst<dessser::gen::raql_value::t_ext> id_1005 { dlist3_fst_213, dlist2_fst_210 };
                                                                      ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7 id_1006 { id_1005, dlist3_snd_214 };
                                                                      letpair_res_1004 = id_1006;
                                                                    }
                                                                    Void id_1007 { ((void)(inits_src_ref_207[id_1001] = letpair_res_1004), VOID) };
                                                                    (void)id_1007;
                                                                  }
                                                                  (void)VOID;
                                                                }
                                                                (void)VOID;
                                                                uint8_t id_1008 { 0 };
                                                                uint8_t id_1009 { 0 };
                                                                int32_t id_1010 { repeat_n_208[id_1009] };
                                                                int32_t id_1011 { 1L };
                                                                int32_t id_1012 { int32_t(id_1010 + id_1011) };
                                                                Void id_1013 { ((void)(repeat_n_208[id_1008] = id_1012), VOID) };
                                                                (void)id_1013;
                                                                (void)id_1013;
                                                              }
                                                            } while (while_flag_994);
                                                            (void)VOID;
                                                          }
                                                          (void)VOID;
                                                          uint8_t id_1014 { 0 };
                                                          ::dessser::gen::output_specs::t4041a0c8c314c2948e196f0dd185cea7 id_1015 { inits_src_ref_207[id_1014] };
                                                          let_res_991 = id_1015;
                                                        }
                                                        letpair_res_987 = let_res_991;
                                                      }
                                                      let_res_986 = letpair_res_987;
                                                    }
                                                    ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 letpair_res_1016;
                                                    {
                                                      auto dlist4_fst_216 { std::get<0>(let_res_986) };
                                                      auto dlist4_snd_217 { std::get<1>(let_res_986) };
                                                      Arr<dessser::gen::raql_value::t_ext> id_1017 { dlist4_fst_216.toListRev() };
                                                      ::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c id_1018 { dtup_fst_193, id_1017 };
                                                      Lst<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> id_1019 { id_1018, dlist2_fst_187 };
                                                      ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 id_1020 { id_1019, dlist4_snd_217 };
                                                      letpair_res_1016 = id_1020;
                                                    }
                                                    letpair_res_945 = letpair_res_1016;
                                                  }
                                                  let_res_944 = letpair_res_945;
                                                }
                                                Void id_1021 { ((void)(inits_src_ref_184[id_940] = let_res_944), VOID) };
                                                (void)id_1021;
                                              }
                                              (void)VOID;
                                            }
                                            (void)VOID;
                                            uint8_t id_1022 { 0 };
                                            uint8_t id_1023 { 0 };
                                            int32_t id_1024 { repeat_n_185[id_1023] };
                                            int32_t id_1025 { 1L };
                                            int32_t id_1026 { int32_t(id_1024 + id_1025) };
                                            Void id_1027 { ((void)(repeat_n_185[id_1022] = id_1026), VOID) };
                                            (void)id_1027;
                                            (void)id_1027;
                                          }
                                        } while (while_flag_933);
                                        (void)VOID;
                                      }
                                      (void)VOID;
                                      uint8_t id_1028 { 0 };
                                      ::dessser::gen::output_specs::t16a148636af6320e05565c76894bdc78 id_1029 { inits_src_ref_184[id_1028] };
                                      let_res_930 = id_1029;
                                    }
                                    letpair_res_926 = let_res_930;
                                  }
                                  let_res_925 = letpair_res_926;
                                }
                                ::dessser::gen::output_specs::t620f8762f21414f954a253b6ac73fbb9 letpair_res_1030;
                                {
                                  auto dlist4_fst_225 { std::get<0>(let_res_925) };
                                  auto dlist4_snd_226 { std::get<1>(let_res_925) };
                                  Arr<::dessser::gen::output_specs::t0b14edd3739ead719254746b30f1350c> id_1031 { dlist4_fst_225.toListRev() };
                                  ::dessser::gen::output_specs::t620f8762f21414f954a253b6ac73fbb9 id_1032 { id_1031, dlist4_snd_226 };
                                  letpair_res_1030 = id_1032;
                                }
                                ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 let_res_1033;
                                {
                                  ::dessser::gen::output_specs::t620f8762f21414f954a253b6ac73fbb9 drec_227 { letpair_res_1030 };
                                  ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 letpair_res_1034;
                                  {
                                    auto drec_fst_228 { std::get<0>(drec_227) };
                                    auto drec_snd_229 { std::get<1>(drec_227) };
                                    uint32_t id_1035 { 0U };
                                    Vec<1, uint32_t> id_1036 {  id_1035  };
                                    ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_1037;
                                    {
                                      Vec<1, uint32_t> leb_ref_230 { id_1036 };
                                      uint8_t id_1038 { 0 };
                                      Vec<1, uint8_t> id_1039 {  id_1038  };
                                      ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_1040;
                                      {
                                        Vec<1, uint8_t> shft_ref_231 { id_1039 };
                                        Vec<1, Pointer> id_1041 {  drec_snd_229  };
                                        ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 let_res_1042;
                                        {
                                          Vec<1, Pointer> p_ref_232 { id_1041 };
                                          bool while_flag_1043 { true };
                                          do {
                                            uint8_t id_1044 { 0 };
                                            Pointer id_1045 { p_ref_232[id_1044] };
                                            ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 id_1046 { id_1045.readU8() };
                                            bool let_res_1047;
                                            {
                                              ::dessser::gen::output_specs::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_233 { id_1046 };
                                              bool letpair_res_1048;
                                              {
                                                auto leb128_fst_234 { std::get<0>(leb128_233) };
                                                auto leb128_snd_235 { std::get<1>(leb128_233) };
                                                uint8_t id_1049 { 0 };
                                                Void id_1050 { ((void)(p_ref_232[id_1049] = leb128_snd_235), VOID) };
                                                (void)id_1050;
                                                uint8_t id_1051 { 0 };
                                                uint8_t id_1052 { 127 };
                                                uint8_t id_1053 { uint8_t(leb128_fst_234 & id_1052) };
                                                uint32_t id_1054 { uint32_t(id_1053) };
                                                uint8_t id_1055 { 0 };
                                                uint8_t id_1056 { shft_ref_231[id_1055] };
                                                uint32_t id_1057 { uint32_t(id_1054 << id_1056) };
                                                uint8_t id_1058 { 0 };
                                                uint32_t id_1059 { leb_ref_230[id_1058] };
                                                uint32_t id_1060 { uint32_t(id_1057 | id_1059) };
                                                Void id_1061 { ((void)(leb_ref_230[id_1051] = id_1060), VOID) };
                                                (void)id_1061;
                                                uint8_t id_1062 { 0 };
                                                uint8_t id_1063 { 0 };
                                                uint8_t id_1064 { shft_ref_231[id_1063] };
                                                uint8_t id_1065 { 7 };
                                                uint8_t id_1066 { uint8_t(id_1064 + id_1065) };
                                                Void id_1067 { ((void)(shft_ref_231[id_1062] = id_1066), VOID) };
                                                (void)id_1067;
                                                uint8_t id_1068 { 128 };
                                                bool id_1069 { bool(leb128_fst_234 >= id_1068) };
                                                letpair_res_1048 = id_1069;
                                              }
                                              let_res_1047 = letpair_res_1048;
                                            }
                                            while_flag_1043 = let_res_1047;
                                            if (while_flag_1043) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_1043);
                                          (void)VOID;
                                          uint8_t id_1070 { 0 };
                                          uint32_t id_1071 { leb_ref_230[id_1070] };
                                          uint8_t id_1072 { 0 };
                                          Pointer id_1073 { p_ref_232[id_1072] };
                                          ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 id_1074 { id_1071, id_1073 };
                                          let_res_1042 = id_1074;
                                        }
                                        let_res_1040 = let_res_1042;
                                      }
                                      let_res_1037 = let_res_1040;
                                    }
                                    ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 let_res_1075;
                                    {
                                      ::dessser::gen::output_specs::t883c6ffea47c0d7b950fe35881e3d737 dlist1_239 { let_res_1037 };
                                      ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 letpair_res_1076;
                                      {
                                        auto dlist1_fst_240 { std::get<0>(dlist1_239) };
                                        auto dlist1_snd_241 { std::get<1>(dlist1_239) };
                                        Lst<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> endoflist_1077;
                                        ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 id_1078 { endoflist_1077, dlist1_snd_241 };
                                        Vec<1, ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0> id_1079 {  id_1078  };
                                        ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 let_res_1080;
                                        {
                                          Vec<1, ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0> inits_src_ref_242 { id_1079 };
                                          int32_t id_1081 { 0L };
                                          Vec<1, int32_t> id_1082 {  id_1081  };
                                          {
                                            Vec<1, int32_t> repeat_n_243 { id_1082 };
                                            bool while_flag_1083 { true };
                                            do {
                                              int32_t id_1084 { int32_t(dlist1_fst_240) };
                                              uint8_t id_1085 { 0 };
                                              int32_t id_1086 { repeat_n_243[id_1085] };
                                              bool id_1087 { bool(id_1084 > id_1086) };
                                              while_flag_1083 = id_1087;
                                              if (while_flag_1083) {
                                                uint8_t id_1088 { 0 };
                                                ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 id_1089 { inits_src_ref_242[id_1088] };
                                                {
                                                  ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 dlist2_244 { id_1089 };
                                                  {
                                                    auto dlist2_fst_245 { std::get<0>(dlist2_244) };
                                                    auto dlist2_snd_246 { std::get<1>(dlist2_244) };
                                                    uint8_t id_1090 { 0 };
                                                    ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b id_1091 { dlist2_snd_246.readU16Le() };
                                                    ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1092;
                                                    {
                                                      auto du16_fst_248 { std::get<0>(id_1091) };
                                                      auto du16_snd_249 { std::get<1>(id_1091) };
                                                      ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b id_1093 { du16_fst_248, du16_snd_249 };
                                                      letpair_res_1092 = id_1093;
                                                    }
                                                    ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 let_res_1094;
                                                    {
                                                      ::dessser::gen::output_specs::t7609d344c1ba69d0f80fec236d4c216b dtup_250 { letpair_res_1092 };
                                                      ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 letpair_res_1095;
                                                      {
                                                        auto dtup_fst_251 { std::get<0>(dtup_250) };
                                                        auto dtup_snd_252 { std::get<1>(dtup_250) };
                                                        ::dessser::gen::output_specs::t092f0ef972407382249d7ed7a5dafaca id_1096 { channel_specs_of_row_binary(dtup_snd_252) };
                                                        ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 letpair_res_1097;
                                                        {
                                                          auto dtup_fst_254 { std::get<0>(id_1096) };
                                                          auto dtup_snd_255 { std::get<1>(id_1096) };
                                                          ::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085 id_1098 { dtup_fst_251, dtup_fst_254 };
                                                          Lst<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> id_1099 { id_1098, dlist2_fst_245 };
                                                          ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 id_1100 { id_1099, dtup_snd_255 };
                                                          letpair_res_1097 = id_1100;
                                                        }
                                                        letpair_res_1095 = letpair_res_1097;
                                                      }
                                                      let_res_1094 = letpair_res_1095;
                                                    }
                                                    Void id_1101 { ((void)(inits_src_ref_242[id_1090] = let_res_1094), VOID) };
                                                    (void)id_1101;
                                                  }
                                                  (void)VOID;
                                                }
                                                (void)VOID;
                                                uint8_t id_1102 { 0 };
                                                uint8_t id_1103 { 0 };
                                                int32_t id_1104 { repeat_n_243[id_1103] };
                                                int32_t id_1105 { 1L };
                                                int32_t id_1106 { int32_t(id_1104 + id_1105) };
                                                Void id_1107 { ((void)(repeat_n_243[id_1102] = id_1106), VOID) };
                                                (void)id_1107;
                                                (void)id_1107;
                                              }
                                            } while (while_flag_1083);
                                            (void)VOID;
                                          }
                                          (void)VOID;
                                          uint8_t id_1108 { 0 };
                                          ::dessser::gen::output_specs::te2926311cf5a61b7e881f6a30e23afe0 id_1109 { inits_src_ref_242[id_1108] };
                                          let_res_1080 = id_1109;
                                        }
                                        letpair_res_1076 = let_res_1080;
                                      }
                                      let_res_1075 = letpair_res_1076;
                                    }
                                    ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 letpair_res_1110;
                                    {
                                      auto dlist4_fst_260 { std::get<0>(let_res_1075) };
                                      auto dlist4_snd_261 { std::get<1>(let_res_1075) };
                                      Arr<::dessser::gen::output_specs::t784c9e092e6dc8e0c9c5fd1cc3093085> id_1111 { dlist4_fst_260.toListRev() };
                                      ::dessser::gen::output_specs::td4b276c89163d76d7a872961502751f6 id_1112 { id_1111, drec_fst_170, drec_fst_167, drec_fst_228 };
                                      ::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee id_1113 { dtup_fst_164, id_1112 };
                                      Lst<::dessser::gen::output_specs::tba04231272fbebb3d3653fbc82bc2eee> id_1114 { id_1113, dlist2_fst_161 };
                                      ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 id_1115 { id_1114, dlist4_snd_261 };
                                      letpair_res_1110 = id_1115;
                                    }
                                    letpair_res_1034 = letpair_res_1110;
                                  }
                                  let_res_1033 = letpair_res_1034;
                                }
                                letpair_res_884 = let_res_1033;
                              }
                              let_res_883 = letpair_res_884;
                            }
                            letpair_res_880 = let_res_883;
                          }
                          let_res_879 = letpair_res_880;
                        }
                        letpair_res_877 = let_res_879;
                      }
                      let_res_876 = letpair_res_877;
                    }
                    Void id_1116 { ((void)(inits_src_ref_158[id_874] = let_res_876), VOID) };
                    (void)id_1116;
                  }
                  (void)VOID;
                }
                (void)VOID;
                uint8_t id_1117 { 0 };
                uint8_t id_1118 { 0 };
                int32_t id_1119 { repeat_n_159[id_1118] };
                int32_t id_1120 { 1L };
                int32_t id_1121 { int32_t(id_1119 + id_1120) };
                Void id_1122 { ((void)(repeat_n_159[id_1117] = id_1121), VOID) };
                (void)id_1122;
                (void)id_1122;
              }
            } while (while_flag_867);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_1123 { 0 };
          ::dessser::gen::output_specs::tc4746cf3f8f0513f3aae473e0bf0b2f4 id_1124 { inits_src_ref_158[id_1123] };
          let_res_864 = id_1124;
        }
        letpair_res_860 = let_res_864;
      }
      let_res_859 = letpair_res_860;
    }
    ::dessser::gen::output_specs::tf6138ae5919ddcb1cb9a935a9dc7190a letpair_res_1125;
    {
      auto dlist4_fst_272 { std::get<0>(let_res_859) };
      auto dlist4_snd_273 { std::get<1>(let_res_859) };
      t id_1126 { dlist4_fst_272.toListRev() };
      ::dessser::gen::output_specs::tf6138ae5919ddcb1cb9a935a9dc7190a id_1127 { id_1126, dlist4_snd_273 };
      letpair_res_1125 = id_1127;
    }
    return letpair_res_1125;
  }
   };
  return fun818;
}
std::function<::dessser::gen::output_specs::tf6138ae5919ddcb1cb9a935a9dc7190a(Pointer)> of_row_binary(of_row_binary_init());


}
