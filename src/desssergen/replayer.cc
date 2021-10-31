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
#include "desssergen/time_range.h"


namespace dessser::gen::replayer {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  Arr<uint16_t> channels;
  double creation;
  std::optional<std::string> exit_status;
  double last_killed;
  std::optional<uint32_t> pid;
  dessser::gen::time_range::t_ext time_range;
  t(Arr<uint16_t> channels_, double creation_, std::optional<std::string> exit_status_, double last_killed_, std::optional<uint32_t> pid_, dessser::gen::time_range::t_ext time_range_) : channels(channels_), creation(creation_), exit_status(exit_status_), last_killed(last_killed_), pid(pid_), time_range(time_range_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.channels == b.channels && a.creation == b.creation && ((a.exit_status && b.exit_status && a.exit_status.value() == b.exit_status.value()) || (!a.exit_status && !b.exit_status)) && a.last_killed == b.last_killed && ((a.pid && b.pid && a.pid.value() == b.pid.value()) || (!a.pid && !b.pid)) && ::dessser::gen::time_range::Deref(a.time_range) == ::dessser::gen::time_range::Deref(b.time_range);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t6917ef55820d0fab931ee64de5c03063 : public std::tuple<
  ::dessser::gen::replayer::t*,
  Pointer
> {
  using tuple::tuple;
  t6917ef55820d0fab931ee64de5c03063(std::tuple<::dessser::gen::replayer::t*, Pointer> p)
    : std::tuple<::dessser::gen::replayer::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6917ef55820d0fab931ee64de5c03063 const &a, t6917ef55820d0fab931ee64de5c03063 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6917ef55820d0fab931ee64de5c03063 const &a, t6917ef55820d0fab931ee64de5c03063 const &b) {
  return !operator==(a, b);
}
struct t12b2d6d50de8cb59e40a3787e527a60e : public std::tuple<
  dessser::gen::time_range::t_ext,
  Pointer
> {
  using tuple::tuple;
  t12b2d6d50de8cb59e40a3787e527a60e(std::tuple<dessser::gen::time_range::t_ext, Pointer> p)
    : std::tuple<dessser::gen::time_range::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12b2d6d50de8cb59e40a3787e527a60e const &a, t12b2d6d50de8cb59e40a3787e527a60e const &b) {
  return ::dessser::gen::time_range::Deref(std::get<0>(a)) == ::dessser::gen::time_range::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12b2d6d50de8cb59e40a3787e527a60e const &a, t12b2d6d50de8cb59e40a3787e527a60e const &b) {
  return !operator==(a, b);
}
struct tf568409f41c9c0a265f7302110fc9084 : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  tf568409f41c9c0a265f7302110fc9084(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf568409f41c9c0a265f7302110fc9084 const &a, tf568409f41c9c0a265f7302110fc9084 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf568409f41c9c0a265f7302110fc9084 const &a, tf568409f41c9c0a265f7302110fc9084 const &b) {
  return !operator==(a, b);
}
struct t5375de390f9cb5ae2ee5880ea1674828 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t5375de390f9cb5ae2ee5880ea1674828(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5375de390f9cb5ae2ee5880ea1674828 const &a, t5375de390f9cb5ae2ee5880ea1674828 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5375de390f9cb5ae2ee5880ea1674828 const &a, t5375de390f9cb5ae2ee5880ea1674828 const &b) {
  return !operator==(a, b);
}
struct t49bba4334bc61fea37f22a58b9f26083 : public std::tuple<
  std::optional<uint32_t>,
  Pointer
> {
  using tuple::tuple;
  t49bba4334bc61fea37f22a58b9f26083(std::tuple<std::optional<uint32_t>, Pointer> p)
    : std::tuple<std::optional<uint32_t>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t49bba4334bc61fea37f22a58b9f26083 const &a, t49bba4334bc61fea37f22a58b9f26083 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t49bba4334bc61fea37f22a58b9f26083 const &a, t49bba4334bc61fea37f22a58b9f26083 const &b) {
  return !operator==(a, b);
}
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t883c6ffea47c0d7b950fe35881e3d737 const &a, t883c6ffea47c0d7b950fe35881e3d737 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t883c6ffea47c0d7b950fe35881e3d737 const &a, t883c6ffea47c0d7b950fe35881e3d737 const &b) {
  return !operator==(a, b);
}
struct t510d2765299691f9f1b747bd6e4d91c0 : public std::tuple<
  std::optional<std::string>,
  Pointer
> {
  using tuple::tuple;
  t510d2765299691f9f1b747bd6e4d91c0(std::tuple<std::optional<std::string>, Pointer> p)
    : std::tuple<std::optional<std::string>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t510d2765299691f9f1b747bd6e4d91c0 const &a, t510d2765299691f9f1b747bd6e4d91c0 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t510d2765299691f9f1b747bd6e4d91c0 const &a, t510d2765299691f9f1b747bd6e4d91c0 const &b) {
  return !operator==(a, b);
}
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
  return !operator==(a, b);
}
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return !operator==(a, b);
}
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
  return !operator==(a, b);
}
struct t73f706a5ebfbedb57bd324a4876b007a : public std::tuple<
  Lst<uint16_t>,
  Pointer
> {
  using tuple::tuple;
  t73f706a5ebfbedb57bd324a4876b007a(std::tuple<Lst<uint16_t>, Pointer> p)
    : std::tuple<Lst<uint16_t>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t73f706a5ebfbedb57bd324a4876b007a const &a, t73f706a5ebfbedb57bd324a4876b007a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t73f706a5ebfbedb57bd324a4876b007a const &a, t73f706a5ebfbedb57bd324a4876b007a const &b) {
  return !operator==(a, b);
}
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7609d344c1ba69d0f80fec236d4c216b const &a, t7609d344c1ba69d0f80fec236d4c216b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7609d344c1ba69d0f80fec236d4c216b const &a, t7609d344c1ba69d0f80fec236d4c216b const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{time_range: $time_range; creation: FLOAT; pid: U32?; last_killed: FLOAT; exit_status: STRING?; channels: U16[]}" "Ptr")
      (let "srec_dst_149"
        (let "srec_dst_146"
          (let "srec_dst_145"
            (let "srec_dst_144"
              (let "srec_dst_143" (apply (ext-identifier time_range to-row-binary) (get-field "time_range" (param 0)) (param 1))
                (write-u64 little-endian (identifier "srec_dst_143") (u64-of-float (get-field "creation" (param 0)))))
              (if (is-null (get-field "pid" (param 0))) (write-u8 (identifier "srec_dst_144") (u8 1)) (write-u32 little-endian (write-u8 (identifier "srec_dst_144") (u8 0)) (force (get-field "pid" (param 0))))))
            (write-u64 little-endian (identifier "srec_dst_145") (u64-of-float (get-field "last_killed" (param 0)))))
          (if (is-null (get-field "exit_status" (param 0))) (write-u8 (identifier "srec_dst_146") (u8 1))
            (write-bytes
              (let "leb128_sz_147" (make-vec (string-length (force (get-field "exit_status" (param 0)))))
                (let "leb128_ptr_148" (make-vec (write-u8 (identifier "srec_dst_146") (u8 0)))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_148")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_148"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_147"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_147"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_147"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_147") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_147")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_147")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_148"))))) 
              (bytes-of-string (force (get-field "exit_status" (param 0)))))))
        (let "dst_ref_152"
          (make-vec
            (let "leb128_sz_150" (make-vec (cardinality (get-field "channels" (param 0))))
              (let "leb128_ptr_151" (make-vec (identifier "srec_dst_149"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_151")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_151"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_150"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_150"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_150"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_150") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_150")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_150")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_151"))))))
          (let "n_ref_153" (make-vec (i32 0))
            (seq
              (for-each "x_154" (get-field "channels" (param 0))
                (seq (set-vec (u8 0) (identifier "dst_ref_152") (write-u16 little-endian (unsafe-nth (u8 0) (identifier "dst_ref_152")) (identifier "x_154")))
                  (set-vec (u8 0) (identifier "n_ref_153") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_153")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_152")))))))
 */
static std::function<Pointer(::dessser::gen::replayer::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::replayer::t*,Pointer)> fun0 { [&fun0](::dessser::gen::replayer::t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::time_range::to_row_binary };
    dessser::gen::time_range::t_ext id_2 { (*p_0).time_range };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_143 { id_3 };
      double id_5 { (*p_0).creation };
      uint64_t id_6 { qword_of_float(id_5) };
      Pointer id_7 { srec_dst_143.writeU64Le(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_144 { let_res_4 };
      std::optional<uint32_t> id_9 { (*p_0).pid };
      bool id_10 { !(id_9.has_value ()) };
      Pointer choose_res_11;
      if (id_10) {
        uint8_t id_12 { 1 };
        Pointer id_13 { srec_dst_144.writeU8(id_12) };
        choose_res_11 = id_13;
      } else {
        uint8_t id_14 { 0 };
        Pointer id_15 { srec_dst_144.writeU8(id_14) };
        std::optional<uint32_t> id_16 { (*p_0).pid };
        uint32_t id_17 { id_16.value() };
        Pointer id_18 { id_15.writeU32Le(id_17) };
        choose_res_11 = id_18;
      }
      let_res_8 = choose_res_11;
    }
    Pointer let_res_19;
    {
      Pointer srec_dst_145 { let_res_8 };
      double id_20 { (*p_0).last_killed };
      uint64_t id_21 { qword_of_float(id_20) };
      Pointer id_22 { srec_dst_145.writeU64Le(id_21) };
      let_res_19 = id_22;
    }
    Pointer let_res_23;
    {
      Pointer srec_dst_146 { let_res_19 };
      std::optional<std::string> id_24 { (*p_0).exit_status };
      bool id_25 { !(id_24.has_value ()) };
      Pointer choose_res_26;
      if (id_25) {
        uint8_t id_27 { 1 };
        Pointer id_28 { srec_dst_146.writeU8(id_27) };
        choose_res_26 = id_28;
      } else {
        std::optional<std::string> id_29 { (*p_0).exit_status };
        std::string id_30 { id_29.value() };
        uint32_t id_31 { (uint32_t)id_30.size() };
        Vec<1, uint32_t> id_32 {  id_31  };
        Pointer let_res_33;
        {
          Vec<1, uint32_t> leb128_sz_147 { id_32 };
          uint8_t id_34 { 0 };
          Pointer id_35 { srec_dst_146.writeU8(id_34) };
          Vec<1, Pointer> id_36 {  id_35  };
          Pointer let_res_37;
          {
            Vec<1, Pointer> leb128_ptr_148 { id_36 };
            bool while_flag_38 { true };
            do {
              uint8_t id_39 { 0 };
              uint8_t id_40 { 0 };
              Pointer id_41 { leb128_ptr_148[id_40] };
              uint32_t id_42 { 128U };
              uint8_t id_43 { 0 };
              uint32_t id_44 { leb128_sz_147[id_43] };
              bool id_45 { bool(id_42 > id_44) };
              uint8_t choose_res_46;
              if (id_45) {
                uint8_t id_47 { 0 };
                uint32_t id_48 { leb128_sz_147[id_47] };
                uint8_t id_49 { uint8_t(id_48) };
                choose_res_46 = id_49;
              } else {
                uint8_t id_50 { 0 };
                uint32_t id_51 { leb128_sz_147[id_50] };
                uint8_t id_52 { uint8_t(id_51) };
                uint8_t id_53 { 128 };
                uint8_t id_54 { uint8_t(id_52 | id_53) };
                choose_res_46 = id_54;
              }
              Pointer id_55 { id_41.writeU8(choose_res_46) };
              Void id_56 { ((void)(leb128_ptr_148[id_39] = id_55), VOID) };
              (void)id_56;
              uint8_t id_57 { 0 };
              uint8_t id_58 { 0 };
              uint32_t id_59 { leb128_sz_147[id_58] };
              uint8_t id_60 { 7 };
              uint32_t id_61 { uint32_t(id_59 >> id_60) };
              Void id_62 { ((void)(leb128_sz_147[id_57] = id_61), VOID) };
              (void)id_62;
              uint8_t id_63 { 0 };
              uint32_t id_64 { leb128_sz_147[id_63] };
              uint32_t id_65 { 0U };
              bool id_66 { bool(id_64 > id_65) };
              while_flag_38 = id_66;
              if (while_flag_38) {
                (void)VOID;
              }
            } while (while_flag_38);
            (void)VOID;
            uint8_t id_67 { 0 };
            Pointer id_68 { leb128_ptr_148[id_67] };
            let_res_37 = id_68;
          }
          let_res_33 = let_res_37;
        }
        std::optional<std::string> id_69 { (*p_0).exit_status };
        std::string id_70 { id_69.value() };
        Bytes id_71 { id_70 };
        Pointer id_72 { let_res_33.writeBytes(id_71) };
        choose_res_26 = id_72;
      }
      let_res_23 = choose_res_26;
    }
    Pointer let_res_73;
    {
      Pointer srec_dst_149 { let_res_23 };
      Arr<uint16_t> id_74 { (*p_0).channels };
      uint32_t id_75 { id_74.size() };
      Vec<1, uint32_t> id_76 {  id_75  };
      Pointer let_res_77;
      {
        Vec<1, uint32_t> leb128_sz_150 { id_76 };
        Vec<1, Pointer> id_78 {  srec_dst_149  };
        Pointer let_res_79;
        {
          Vec<1, Pointer> leb128_ptr_151 { id_78 };
          bool while_flag_80 { true };
          do {
            uint8_t id_81 { 0 };
            uint8_t id_82 { 0 };
            Pointer id_83 { leb128_ptr_151[id_82] };
            uint32_t id_84 { 128U };
            uint8_t id_85 { 0 };
            uint32_t id_86 { leb128_sz_150[id_85] };
            bool id_87 { bool(id_84 > id_86) };
            uint8_t choose_res_88;
            if (id_87) {
              uint8_t id_89 { 0 };
              uint32_t id_90 { leb128_sz_150[id_89] };
              uint8_t id_91 { uint8_t(id_90) };
              choose_res_88 = id_91;
            } else {
              uint8_t id_92 { 0 };
              uint32_t id_93 { leb128_sz_150[id_92] };
              uint8_t id_94 { uint8_t(id_93) };
              uint8_t id_95 { 128 };
              uint8_t id_96 { uint8_t(id_94 | id_95) };
              choose_res_88 = id_96;
            }
            Pointer id_97 { id_83.writeU8(choose_res_88) };
            Void id_98 { ((void)(leb128_ptr_151[id_81] = id_97), VOID) };
            (void)id_98;
            uint8_t id_99 { 0 };
            uint8_t id_100 { 0 };
            uint32_t id_101 { leb128_sz_150[id_100] };
            uint8_t id_102 { 7 };
            uint32_t id_103 { uint32_t(id_101 >> id_102) };
            Void id_104 { ((void)(leb128_sz_150[id_99] = id_103), VOID) };
            (void)id_104;
            uint8_t id_105 { 0 };
            uint32_t id_106 { leb128_sz_150[id_105] };
            uint32_t id_107 { 0U };
            bool id_108 { bool(id_106 > id_107) };
            while_flag_80 = id_108;
            if (while_flag_80) {
              (void)VOID;
            }
          } while (while_flag_80);
          (void)VOID;
          uint8_t id_109 { 0 };
          Pointer id_110 { leb128_ptr_151[id_109] };
          let_res_79 = id_110;
        }
        let_res_77 = let_res_79;
      }
      Vec<1, Pointer> id_111 {  let_res_77  };
      Pointer let_res_112;
      {
        Vec<1, Pointer> dst_ref_152 { id_111 };
        int32_t id_113 { 0L };
        Vec<1, int32_t> id_114 {  id_113  };
        Pointer let_res_115;
        {
          Vec<1, int32_t> n_ref_153 { id_114 };
          Arr<uint16_t> id_116 { (*p_0).channels };
          for (uint16_t x_154 : id_116) {
            uint8_t id_117 { 0 };
            uint8_t id_118 { 0 };
            Pointer id_119 { dst_ref_152[id_118] };
            Pointer id_120 { id_119.writeU16Le(x_154) };
            Void id_121 { ((void)(dst_ref_152[id_117] = id_120), VOID) };
            (void)id_121;
            uint8_t id_122 { 0 };
            int32_t id_123 { 1L };
            uint8_t id_124 { 0 };
            int32_t id_125 { n_ref_153[id_124] };
            int32_t id_126 { int32_t(id_123 + id_125) };
            Void id_127 { ((void)(n_ref_153[id_122] = id_126), VOID) };
            (void)id_127;
            (void)id_127;
          }
          (void)VOID;
          uint8_t id_128 { 0 };
          Pointer id_129 { dst_ref_152[id_128] };
          let_res_115 = id_129;
        }
        let_res_112 = let_res_115;
      }
      let_res_73 = let_res_112;
    }
    return let_res_73;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::replayer::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{time_range: $time_range; creation: FLOAT; pid: U32?; last_killed: FLOAT; exit_status: STRING?; channels: U16[]}")
      (let "sz_138"
        (let "sz_134"
          (add
            (let "sz_132" (add (apply (ext-identifier time_range sersize-of-row-binary) (get-field "time_range" (param 0))) (size 8))
              (if (is-null (get-field "pid" (param 0))) (add (identifier "sz_132") (size 1)) (add (add (identifier "sz_132") (size 4)) (size 1)))) 
            (size 8))
          (if (is-null (get-field "exit_status" (param 0))) (add (identifier "sz_134") (size 1))
            (add
              (add (identifier "sz_134")
                (add
                  (let "n_ref_136" (make-vec (string-length (force (get-field "exit_status" (param 0)))))
                    (let "lebsz_ref_137" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_136")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_137")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_137") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_137")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_137")))))) 
                  (size-of-u32 (string-length (force (get-field "exit_status" (param 0))))))) 
              (size 1))))
        (let "sz_ref_141"
          (make-vec
            (add (identifier "sz_138")
              (let "n_ref_139" (make-vec (cardinality (get-field "channels" (param 0))))
                (let "lebsz_ref_140" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_139")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_140")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_140") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_140")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_140"))))))))
          (seq
            (let "repeat_n_142" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "channels" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_142")))
                (seq (set-vec (u8 0) (identifier "sz_ref_141") (add (unsafe-nth (u8 0) (identifier "sz_ref_141")) (size 2)))
                  (set-vec (u8 0) (identifier "repeat_n_142") (add (unsafe-nth (u8 0) (identifier "repeat_n_142")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_141"))))))
 */
static std::function<Size(::dessser::gen::replayer::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::replayer::t*)> fun130 { [&fun130](::dessser::gen::replayer::t* p_0) {
    auto fun131 { dessser::gen::time_range::sersize_of_row_binary };
    dessser::gen::time_range::t_ext id_132 { (*p_0).time_range };
    Size id_133 { fun131(id_132) };
    Size id_134 { 8UL };
    Size id_135 { Size(id_133 + id_134) };
    Size let_res_136;
    {
      Size sz_132 { id_135 };
      std::optional<uint32_t> id_137 { (*p_0).pid };
      bool id_138 { !(id_137.has_value ()) };
      Size choose_res_139;
      if (id_138) {
        Size id_140 { 1UL };
        Size id_141 { Size(sz_132 + id_140) };
        choose_res_139 = id_141;
      } else {
        Size id_142 { 4UL };
        Size id_143 { Size(sz_132 + id_142) };
        Size id_144 { 1UL };
        Size id_145 { Size(id_143 + id_144) };
        choose_res_139 = id_145;
      }
      let_res_136 = choose_res_139;
    }
    Size id_146 { 8UL };
    Size id_147 { Size(let_res_136 + id_146) };
    Size let_res_148;
    {
      Size sz_134 { id_147 };
      std::optional<std::string> id_149 { (*p_0).exit_status };
      bool id_150 { !(id_149.has_value ()) };
      Size choose_res_151;
      if (id_150) {
        Size id_152 { 1UL };
        Size id_153 { Size(sz_134 + id_152) };
        choose_res_151 = id_153;
      } else {
        std::optional<std::string> id_154 { (*p_0).exit_status };
        std::string id_155 { id_154.value() };
        uint32_t id_156 { (uint32_t)id_155.size() };
        Vec<1, uint32_t> id_157 {  id_156  };
        Size let_res_158;
        {
          Vec<1, uint32_t> n_ref_136 { id_157 };
          uint32_t id_159 { 1U };
          Vec<1, uint32_t> id_160 {  id_159  };
          Size let_res_161;
          {
            Vec<1, uint32_t> lebsz_ref_137 { id_160 };
            bool while_flag_162 { true };
            do {
              uint8_t id_163 { 0 };
              uint32_t id_164 { n_ref_136[id_163] };
              uint8_t id_165 { 0 };
              uint32_t id_166 { lebsz_ref_137[id_165] };
              uint8_t id_167 { 7 };
              uint32_t id_168 { uint32_t(id_166 << id_167) };
              bool id_169 { bool(id_164 >= id_168) };
              while_flag_162 = id_169;
              if (while_flag_162) {
                uint8_t id_170 { 0 };
                uint8_t id_171 { 0 };
                uint32_t id_172 { lebsz_ref_137[id_171] };
                uint32_t id_173 { 1U };
                uint32_t id_174 { uint32_t(id_172 + id_173) };
                Void id_175 { ((void)(lebsz_ref_137[id_170] = id_174), VOID) };
                (void)id_175;
              }
            } while (while_flag_162);
            (void)VOID;
            uint8_t id_176 { 0 };
            uint32_t id_177 { lebsz_ref_137[id_176] };
            Size id_178 { Size(id_177) };
            let_res_161 = id_178;
          }
          let_res_158 = let_res_161;
        }
        std::optional<std::string> id_179 { (*p_0).exit_status };
        std::string id_180 { id_179.value() };
        uint32_t id_181 { (uint32_t)id_180.size() };
        Size id_182 { Size(id_181) };
        Size id_183 { Size(let_res_158 + id_182) };
        Size id_184 { Size(sz_134 + id_183) };
        Size id_185 { 1UL };
        Size id_186 { Size(id_184 + id_185) };
        choose_res_151 = id_186;
      }
      let_res_148 = choose_res_151;
    }
    Size let_res_187;
    {
      Size sz_138 { let_res_148 };
      Arr<uint16_t> id_188 { (*p_0).channels };
      uint32_t id_189 { id_188.size() };
      Vec<1, uint32_t> id_190 {  id_189  };
      Size let_res_191;
      {
        Vec<1, uint32_t> n_ref_139 { id_190 };
        uint32_t id_192 { 1U };
        Vec<1, uint32_t> id_193 {  id_192  };
        Size let_res_194;
        {
          Vec<1, uint32_t> lebsz_ref_140 { id_193 };
          bool while_flag_195 { true };
          do {
            uint8_t id_196 { 0 };
            uint32_t id_197 { n_ref_139[id_196] };
            uint8_t id_198 { 0 };
            uint32_t id_199 { lebsz_ref_140[id_198] };
            uint8_t id_200 { 7 };
            uint32_t id_201 { uint32_t(id_199 << id_200) };
            bool id_202 { bool(id_197 >= id_201) };
            while_flag_195 = id_202;
            if (while_flag_195) {
              uint8_t id_203 { 0 };
              uint8_t id_204 { 0 };
              uint32_t id_205 { lebsz_ref_140[id_204] };
              uint32_t id_206 { 1U };
              uint32_t id_207 { uint32_t(id_205 + id_206) };
              Void id_208 { ((void)(lebsz_ref_140[id_203] = id_207), VOID) };
              (void)id_208;
            }
          } while (while_flag_195);
          (void)VOID;
          uint8_t id_209 { 0 };
          uint32_t id_210 { lebsz_ref_140[id_209] };
          Size id_211 { Size(id_210) };
          let_res_194 = id_211;
        }
        let_res_191 = let_res_194;
      }
      Size id_212 { Size(sz_138 + let_res_191) };
      Vec<1, Size> id_213 {  id_212  };
      Size let_res_214;
      {
        Vec<1, Size> sz_ref_141 { id_213 };
        int32_t id_215 { 0L };
        Vec<1, int32_t> id_216 {  id_215  };
        {
          Vec<1, int32_t> repeat_n_142 { id_216 };
          bool while_flag_217 { true };
          do {
            Arr<uint16_t> id_218 { (*p_0).channels };
            uint32_t id_219 { id_218.size() };
            int32_t id_220 { int32_t(id_219) };
            uint8_t id_221 { 0 };
            int32_t id_222 { repeat_n_142[id_221] };
            bool id_223 { bool(id_220 > id_222) };
            while_flag_217 = id_223;
            if (while_flag_217) {
              uint8_t id_224 { 0 };
              uint8_t id_225 { 0 };
              Size id_226 { sz_ref_141[id_225] };
              Size id_227 { 2UL };
              Size id_228 { Size(id_226 + id_227) };
              Void id_229 { ((void)(sz_ref_141[id_224] = id_228), VOID) };
              (void)id_229;
              uint8_t id_230 { 0 };
              uint8_t id_231 { 0 };
              int32_t id_232 { repeat_n_142[id_231] };
              int32_t id_233 { 1L };
              int32_t id_234 { int32_t(id_232 + id_233) };
              Void id_235 { ((void)(repeat_n_142[id_230] = id_234), VOID) };
              (void)id_235;
              (void)id_235;
            }
          } while (while_flag_217);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_236 { 0 };
        Size id_237 { sz_ref_141[id_236] };
        let_res_214 = id_237;
      }
      let_res_187 = let_res_214;
    }
    return let_res_187;
  }
   };
  return fun130;
}
std::function<Size(::dessser::gen::replayer::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier time_range of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_62" (let-pair "dfloat_fst_60" "dfloat_snd_61" (read-u64 little-endian (identifier "drec_snd_58")) (make-tup (float-of-u64 (identifier "dfloat_fst_60")) (identifier "dfloat_snd_61")))
            (let-pair "drec_fst_63" "drec_snd_64" (identifier "drec_62")
              (let "drec_71"
                (if (eq (peek-u8 (identifier "drec_snd_64") (size 0)) (u8 1)) 
                  (make-tup (null "U32") (ptr-add (identifier "drec_snd_64") (size 1)))
                  (let-pair "du32_fst_66" "du32_snd_67" (read-u32 little-endian (ptr-add (identifier "drec_snd_64") (size 1))) (make-tup (not-null (identifier "du32_fst_66")) (identifier "du32_snd_67"))))
                (let-pair "drec_fst_72" "drec_snd_73" (identifier "drec_71")
                  (let "drec_77" (let-pair "dfloat_fst_75" "dfloat_snd_76" (read-u64 little-endian (identifier "drec_snd_73")) (make-tup (float-of-u64 (identifier "dfloat_fst_75")) (identifier "dfloat_snd_76")))
                    (let-pair "drec_fst_78" "drec_snd_79" (identifier "drec_77")
                      (let "drec_95"
                        (if (eq (peek-u8 (identifier "drec_snd_79") (size 0)) (u8 1)) 
                          (make-tup (null "STRING") (ptr-add (identifier "drec_snd_79") (size 1)))
                          (let "dstring1_86"
                            (let "leb_ref_80" (make-vec (u32 0))
                              (let "shft_ref_81" (make-vec (u8 0))
                                (let "p_ref_82" (make-vec (ptr-add (identifier "drec_snd_79") (size 1)))
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
                            (let-pair "dstring1_fst_87" "dstring1_snd_88" 
                              (identifier "dstring1_86")
                              (let-pair "dstring2_fst_90" "dstring2_snd_91" 
                                (read-bytes (identifier "dstring1_snd_88") (identifier "dstring1_fst_87")) 
                                (make-tup (not-null (string-of-bytes (identifier "dstring2_fst_90"))) (identifier "dstring2_snd_91"))))))
                        (let-pair "drec_fst_96" "drec_snd_97" (identifier "drec_95")
                          (let-pair "dlist4_fst_122" "dlist4_snd_123"
                            (let "dlist1_107"
                              (let "leb_ref_98" (make-vec (u32 0))
                                (let "shft_ref_99" (make-vec (u8 0))
                                  (let "p_ref_100" (make-vec (identifier "drec_snd_97"))
                                    (seq
                                      (while
                                        (let "leb128_101" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_100")))
                                          (let-pair "leb128_fst_102" "leb128_snd_103" 
                                            (identifier "leb128_101")
                                            (seq (set-vec (u8 0) (identifier "p_ref_100") (identifier "leb128_snd_103"))
                                              (set-vec (u8 0) (identifier "leb_ref_98")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_102") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_99"))) (unsafe-nth (u8 0) (identifier "leb_ref_98"))))
                                              (set-vec (u8 0) (identifier "shft_ref_99") (add (unsafe-nth (u8 0) (identifier "shft_ref_99")) (u8 7))) 
                                              (ge (identifier "leb128_fst_102") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_98")) (unsafe-nth (u8 0) (identifier "p_ref_100")))))))
                              (let-pair "dlist1_fst_108" "dlist1_snd_109" 
                                (identifier "dlist1_107")
                                (let "inits_src_ref_110" (make-vec (make-tup (end-of-list "U16") (identifier "dlist1_snd_109")))
                                  (seq
                                    (let "repeat_n_111" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_108")) (unsafe-nth (u8 0) (identifier "repeat_n_111")))
                                        (seq
                                          (let "dlist2_112" (unsafe-nth (u8 0) (identifier "inits_src_ref_110"))
                                            (let-pair "dlist2_fst_113" "dlist2_snd_114" 
                                              (identifier "dlist2_112")
                                              (set-vec (u8 0) (identifier "inits_src_ref_110")
                                                (let-pair "du16_fst_116" "du16_snd_117" 
                                                  (read-u16 little-endian (identifier "dlist2_snd_114")) 
                                                  (make-tup (cons (identifier "du16_fst_116") (identifier "dlist2_fst_113")) (identifier "du16_snd_117"))))))
                                          (set-vec (u8 0) (identifier "repeat_n_111") (add (unsafe-nth (u8 0) (identifier "repeat_n_111")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_110"))))))
                            (make-tup
                              (make-rec (string "channels") (arr-of-lst-rev (identifier "dlist4_fst_122")) 
                                (string "exit_status") (identifier "drec_fst_96") 
                                (string "last_killed") (identifier "drec_fst_78") 
                                (string "pid") (identifier "drec_fst_72") 
                                (string "creation") (identifier "drec_fst_63") 
                                (string "time_range") (identifier "drec_fst_57")) 
                              (identifier "dlist4_snd_123"))))))))))))))
 */
static std::function<::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063(Pointer)> fun238 { [&fun238](Pointer p_0) {
    auto fun239 { dessser::gen::time_range::of_row_binary };
    ::dessser::gen::replayer::t12b2d6d50de8cb59e40a3787e527a60e id_240 { fun239(p_0) };
    ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 let_res_241;
    {
      ::dessser::gen::replayer::t12b2d6d50de8cb59e40a3787e527a60e drec_56 { id_240 };
      ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 letpair_res_242;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        ::dessser::gen::replayer::tf568409f41c9c0a265f7302110fc9084 id_243 { drec_snd_58.readU64Le() };
        ::dessser::gen::replayer::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_244;
        {
          auto dfloat_fst_60 { std::get<0>(id_243) };
          auto dfloat_snd_61 { std::get<1>(id_243) };
          double id_245 { float_of_qword(dfloat_fst_60) };
          ::dessser::gen::replayer::t5375de390f9cb5ae2ee5880ea1674828 id_246 { id_245, dfloat_snd_61 };
          letpair_res_244 = id_246;
        }
        ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 let_res_247;
        {
          ::dessser::gen::replayer::t5375de390f9cb5ae2ee5880ea1674828 drec_62 { letpair_res_244 };
          ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 letpair_res_248;
          {
            auto drec_fst_63 { std::get<0>(drec_62) };
            auto drec_snd_64 { std::get<1>(drec_62) };
            Size id_249 { 0UL };
            uint8_t id_250 { drec_snd_64.peekU8(id_249) };
            uint8_t id_251 { 1 };
            bool id_252 { bool(id_250 == id_251) };
            ::dessser::gen::replayer::t49bba4334bc61fea37f22a58b9f26083 choose_res_253;
            if (id_252) {
              std::optional<uint32_t> id_254 { std::nullopt };
              Size id_255 { 1UL };
              Pointer id_256 { drec_snd_64.skip(id_255) };
              ::dessser::gen::replayer::t49bba4334bc61fea37f22a58b9f26083 id_257 { id_254, id_256 };
              choose_res_253 = id_257;
            } else {
              Size id_258 { 1UL };
              Pointer id_259 { drec_snd_64.skip(id_258) };
              ::dessser::gen::replayer::t883c6ffea47c0d7b950fe35881e3d737 id_260 { id_259.readU32Le() };
              ::dessser::gen::replayer::t49bba4334bc61fea37f22a58b9f26083 letpair_res_261;
              {
                auto du32_fst_66 { std::get<0>(id_260) };
                auto du32_snd_67 { std::get<1>(id_260) };
                std::optional<uint32_t> id_262 { du32_fst_66 };
                ::dessser::gen::replayer::t49bba4334bc61fea37f22a58b9f26083 id_263 { id_262, du32_snd_67 };
                letpair_res_261 = id_263;
              }
              choose_res_253 = letpair_res_261;
            }
            ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 let_res_264;
            {
              ::dessser::gen::replayer::t49bba4334bc61fea37f22a58b9f26083 drec_71 { choose_res_253 };
              ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 letpair_res_265;
              {
                auto drec_fst_72 { std::get<0>(drec_71) };
                auto drec_snd_73 { std::get<1>(drec_71) };
                ::dessser::gen::replayer::tf568409f41c9c0a265f7302110fc9084 id_266 { drec_snd_73.readU64Le() };
                ::dessser::gen::replayer::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_267;
                {
                  auto dfloat_fst_75 { std::get<0>(id_266) };
                  auto dfloat_snd_76 { std::get<1>(id_266) };
                  double id_268 { float_of_qword(dfloat_fst_75) };
                  ::dessser::gen::replayer::t5375de390f9cb5ae2ee5880ea1674828 id_269 { id_268, dfloat_snd_76 };
                  letpair_res_267 = id_269;
                }
                ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 let_res_270;
                {
                  ::dessser::gen::replayer::t5375de390f9cb5ae2ee5880ea1674828 drec_77 { letpair_res_267 };
                  ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 letpair_res_271;
                  {
                    auto drec_fst_78 { std::get<0>(drec_77) };
                    auto drec_snd_79 { std::get<1>(drec_77) };
                    Size id_272 { 0UL };
                    uint8_t id_273 { drec_snd_79.peekU8(id_272) };
                    uint8_t id_274 { 1 };
                    bool id_275 { bool(id_273 == id_274) };
                    ::dessser::gen::replayer::t510d2765299691f9f1b747bd6e4d91c0 choose_res_276;
                    if (id_275) {
                      std::optional<std::string> id_277 { std::nullopt };
                      Size id_278 { 1UL };
                      Pointer id_279 { drec_snd_79.skip(id_278) };
                      ::dessser::gen::replayer::t510d2765299691f9f1b747bd6e4d91c0 id_280 { id_277, id_279 };
                      choose_res_276 = id_280;
                    } else {
                      uint32_t id_281 { 0U };
                      Vec<1, uint32_t> id_282 {  id_281  };
                      ::dessser::gen::replayer::t044960e524fd6ec1bfc06410ce526709 let_res_283;
                      {
                        Vec<1, uint32_t> leb_ref_80 { id_282 };
                        uint8_t id_284 { 0 };
                        Vec<1, uint8_t> id_285 {  id_284  };
                        ::dessser::gen::replayer::t044960e524fd6ec1bfc06410ce526709 let_res_286;
                        {
                          Vec<1, uint8_t> shft_ref_81 { id_285 };
                          Size id_287 { 1UL };
                          Pointer id_288 { drec_snd_79.skip(id_287) };
                          Vec<1, Pointer> id_289 {  id_288  };
                          ::dessser::gen::replayer::t044960e524fd6ec1bfc06410ce526709 let_res_290;
                          {
                            Vec<1, Pointer> p_ref_82 { id_289 };
                            bool while_flag_291 { true };
                            do {
                              uint8_t id_292 { 0 };
                              Pointer id_293 { p_ref_82[id_292] };
                              ::dessser::gen::replayer::t1566bd611d8a2b90669c241f5e8d6ff1 id_294 { id_293.readU8() };
                              bool let_res_295;
                              {
                                ::dessser::gen::replayer::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_83 { id_294 };
                                bool letpair_res_296;
                                {
                                  auto leb128_fst_84 { std::get<0>(leb128_83) };
                                  auto leb128_snd_85 { std::get<1>(leb128_83) };
                                  uint8_t id_297 { 0 };
                                  Void id_298 { ((void)(p_ref_82[id_297] = leb128_snd_85), VOID) };
                                  (void)id_298;
                                  uint8_t id_299 { 0 };
                                  uint8_t id_300 { 127 };
                                  uint8_t id_301 { uint8_t(leb128_fst_84 & id_300) };
                                  uint32_t id_302 { uint32_t(id_301) };
                                  uint8_t id_303 { 0 };
                                  uint8_t id_304 { shft_ref_81[id_303] };
                                  uint32_t id_305 { uint32_t(id_302 << id_304) };
                                  uint8_t id_306 { 0 };
                                  uint32_t id_307 { leb_ref_80[id_306] };
                                  uint32_t id_308 { uint32_t(id_305 | id_307) };
                                  Void id_309 { ((void)(leb_ref_80[id_299] = id_308), VOID) };
                                  (void)id_309;
                                  uint8_t id_310 { 0 };
                                  uint8_t id_311 { 0 };
                                  uint8_t id_312 { shft_ref_81[id_311] };
                                  uint8_t id_313 { 7 };
                                  uint8_t id_314 { uint8_t(id_312 + id_313) };
                                  Void id_315 { ((void)(shft_ref_81[id_310] = id_314), VOID) };
                                  (void)id_315;
                                  uint8_t id_316 { 128 };
                                  bool id_317 { bool(leb128_fst_84 >= id_316) };
                                  letpair_res_296 = id_317;
                                }
                                let_res_295 = letpair_res_296;
                              }
                              while_flag_291 = let_res_295;
                              if (while_flag_291) {
                                (void)VOID;
                              }
                            } while (while_flag_291);
                            (void)VOID;
                            uint8_t id_318 { 0 };
                            uint32_t id_319 { leb_ref_80[id_318] };
                            Size id_320 { Size(id_319) };
                            uint8_t id_321 { 0 };
                            Pointer id_322 { p_ref_82[id_321] };
                            ::dessser::gen::replayer::t044960e524fd6ec1bfc06410ce526709 id_323 { id_320, id_322 };
                            let_res_290 = id_323;
                          }
                          let_res_286 = let_res_290;
                        }
                        let_res_283 = let_res_286;
                      }
                      ::dessser::gen::replayer::t510d2765299691f9f1b747bd6e4d91c0 let_res_324;
                      {
                        ::dessser::gen::replayer::t044960e524fd6ec1bfc06410ce526709 dstring1_86 { let_res_283 };
                        ::dessser::gen::replayer::t510d2765299691f9f1b747bd6e4d91c0 letpair_res_325;
                        {
                          auto dstring1_fst_87 { std::get<0>(dstring1_86) };
                          auto dstring1_snd_88 { std::get<1>(dstring1_86) };
                          ::dessser::gen::replayer::t5887709cc43c8c8e24d28211e8c970a2 id_326 { dstring1_snd_88.readBytes(dstring1_fst_87) };
                          ::dessser::gen::replayer::t510d2765299691f9f1b747bd6e4d91c0 letpair_res_327;
                          {
                            auto dstring2_fst_90 { std::get<0>(id_326) };
                            auto dstring2_snd_91 { std::get<1>(id_326) };
                            std::string id_328 { dstring2_fst_90.toString() };
                            std::optional<std::string> id_329 { id_328 };
                            ::dessser::gen::replayer::t510d2765299691f9f1b747bd6e4d91c0 id_330 { id_329, dstring2_snd_91 };
                            letpair_res_327 = id_330;
                          }
                          letpair_res_325 = letpair_res_327;
                        }
                        let_res_324 = letpair_res_325;
                      }
                      choose_res_276 = let_res_324;
                    }
                    ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 let_res_331;
                    {
                      ::dessser::gen::replayer::t510d2765299691f9f1b747bd6e4d91c0 drec_95 { choose_res_276 };
                      ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 letpair_res_332;
                      {
                        auto drec_fst_96 { std::get<0>(drec_95) };
                        auto drec_snd_97 { std::get<1>(drec_95) };
                        uint32_t id_333 { 0U };
                        Vec<1, uint32_t> id_334 {  id_333  };
                        ::dessser::gen::replayer::t883c6ffea47c0d7b950fe35881e3d737 let_res_335;
                        {
                          Vec<1, uint32_t> leb_ref_98 { id_334 };
                          uint8_t id_336 { 0 };
                          Vec<1, uint8_t> id_337 {  id_336  };
                          ::dessser::gen::replayer::t883c6ffea47c0d7b950fe35881e3d737 let_res_338;
                          {
                            Vec<1, uint8_t> shft_ref_99 { id_337 };
                            Vec<1, Pointer> id_339 {  drec_snd_97  };
                            ::dessser::gen::replayer::t883c6ffea47c0d7b950fe35881e3d737 let_res_340;
                            {
                              Vec<1, Pointer> p_ref_100 { id_339 };
                              bool while_flag_341 { true };
                              do {
                                uint8_t id_342 { 0 };
                                Pointer id_343 { p_ref_100[id_342] };
                                ::dessser::gen::replayer::t1566bd611d8a2b90669c241f5e8d6ff1 id_344 { id_343.readU8() };
                                bool let_res_345;
                                {
                                  ::dessser::gen::replayer::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_101 { id_344 };
                                  bool letpair_res_346;
                                  {
                                    auto leb128_fst_102 { std::get<0>(leb128_101) };
                                    auto leb128_snd_103 { std::get<1>(leb128_101) };
                                    uint8_t id_347 { 0 };
                                    Void id_348 { ((void)(p_ref_100[id_347] = leb128_snd_103), VOID) };
                                    (void)id_348;
                                    uint8_t id_349 { 0 };
                                    uint8_t id_350 { 127 };
                                    uint8_t id_351 { uint8_t(leb128_fst_102 & id_350) };
                                    uint32_t id_352 { uint32_t(id_351) };
                                    uint8_t id_353 { 0 };
                                    uint8_t id_354 { shft_ref_99[id_353] };
                                    uint32_t id_355 { uint32_t(id_352 << id_354) };
                                    uint8_t id_356 { 0 };
                                    uint32_t id_357 { leb_ref_98[id_356] };
                                    uint32_t id_358 { uint32_t(id_355 | id_357) };
                                    Void id_359 { ((void)(leb_ref_98[id_349] = id_358), VOID) };
                                    (void)id_359;
                                    uint8_t id_360 { 0 };
                                    uint8_t id_361 { 0 };
                                    uint8_t id_362 { shft_ref_99[id_361] };
                                    uint8_t id_363 { 7 };
                                    uint8_t id_364 { uint8_t(id_362 + id_363) };
                                    Void id_365 { ((void)(shft_ref_99[id_360] = id_364), VOID) };
                                    (void)id_365;
                                    uint8_t id_366 { 128 };
                                    bool id_367 { bool(leb128_fst_102 >= id_366) };
                                    letpair_res_346 = id_367;
                                  }
                                  let_res_345 = letpair_res_346;
                                }
                                while_flag_341 = let_res_345;
                                if (while_flag_341) {
                                  (void)VOID;
                                }
                              } while (while_flag_341);
                              (void)VOID;
                              uint8_t id_368 { 0 };
                              uint32_t id_369 { leb_ref_98[id_368] };
                              uint8_t id_370 { 0 };
                              Pointer id_371 { p_ref_100[id_370] };
                              ::dessser::gen::replayer::t883c6ffea47c0d7b950fe35881e3d737 id_372 { id_369, id_371 };
                              let_res_340 = id_372;
                            }
                            let_res_338 = let_res_340;
                          }
                          let_res_335 = let_res_338;
                        }
                        ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a let_res_373;
                        {
                          ::dessser::gen::replayer::t883c6ffea47c0d7b950fe35881e3d737 dlist1_107 { let_res_335 };
                          ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a letpair_res_374;
                          {
                            auto dlist1_fst_108 { std::get<0>(dlist1_107) };
                            auto dlist1_snd_109 { std::get<1>(dlist1_107) };
                            Lst<uint16_t> endoflist_375;
                            ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a id_376 { endoflist_375, dlist1_snd_109 };
                            Vec<1, ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a> id_377 {  id_376  };
                            ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a let_res_378;
                            {
                              Vec<1, ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a> inits_src_ref_110 { id_377 };
                              int32_t id_379 { 0L };
                              Vec<1, int32_t> id_380 {  id_379  };
                              {
                                Vec<1, int32_t> repeat_n_111 { id_380 };
                                bool while_flag_381 { true };
                                do {
                                  int32_t id_382 { int32_t(dlist1_fst_108) };
                                  uint8_t id_383 { 0 };
                                  int32_t id_384 { repeat_n_111[id_383] };
                                  bool id_385 { bool(id_382 > id_384) };
                                  while_flag_381 = id_385;
                                  if (while_flag_381) {
                                    uint8_t id_386 { 0 };
                                    ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a id_387 { inits_src_ref_110[id_386] };
                                    {
                                      ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a dlist2_112 { id_387 };
                                      {
                                        auto dlist2_fst_113 { std::get<0>(dlist2_112) };
                                        auto dlist2_snd_114 { std::get<1>(dlist2_112) };
                                        uint8_t id_388 { 0 };
                                        ::dessser::gen::replayer::t7609d344c1ba69d0f80fec236d4c216b id_389 { dlist2_snd_114.readU16Le() };
                                        ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a letpair_res_390;
                                        {
                                          auto du16_fst_116 { std::get<0>(id_389) };
                                          auto du16_snd_117 { std::get<1>(id_389) };
                                          Lst<uint16_t> id_391 { du16_fst_116, dlist2_fst_113 };
                                          ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a id_392 { id_391, du16_snd_117 };
                                          letpair_res_390 = id_392;
                                        }
                                        Void id_393 { ((void)(inits_src_ref_110[id_388] = letpair_res_390), VOID) };
                                        (void)id_393;
                                      }
                                      (void)VOID;
                                    }
                                    (void)VOID;
                                    uint8_t id_394 { 0 };
                                    uint8_t id_395 { 0 };
                                    int32_t id_396 { repeat_n_111[id_395] };
                                    int32_t id_397 { 1L };
                                    int32_t id_398 { int32_t(id_396 + id_397) };
                                    Void id_399 { ((void)(repeat_n_111[id_394] = id_398), VOID) };
                                    (void)id_399;
                                    (void)id_399;
                                  }
                                } while (while_flag_381);
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_400 { 0 };
                              ::dessser::gen::replayer::t73f706a5ebfbedb57bd324a4876b007a id_401 { inits_src_ref_110[id_400] };
                              let_res_378 = id_401;
                            }
                            letpair_res_374 = let_res_378;
                          }
                          let_res_373 = letpair_res_374;
                        }
                        ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 letpair_res_402;
                        {
                          auto dlist4_fst_122 { std::get<0>(let_res_373) };
                          auto dlist4_snd_123 { std::get<1>(let_res_373) };
                          Arr<uint16_t> id_403 { dlist4_fst_122.toListRev() };
                          ::dessser::gen::replayer::t* id_404 { new ::dessser::gen::replayer::t({ id_403, drec_fst_63, drec_fst_96, drec_fst_78, drec_fst_72, drec_fst_57 }) };
                          ::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063 id_405 { id_404, dlist4_snd_123 };
                          letpair_res_402 = id_405;
                        }
                        letpair_res_332 = letpair_res_402;
                      }
                      let_res_331 = letpair_res_332;
                    }
                    letpair_res_271 = let_res_331;
                  }
                  let_res_270 = letpair_res_271;
                }
                letpair_res_265 = let_res_270;
              }
              let_res_264 = letpair_res_265;
            }
            letpair_res_248 = let_res_264;
          }
          let_res_247 = letpair_res_248;
        }
        letpair_res_242 = let_res_247;
      }
      let_res_241 = letpair_res_242;
    }
    return let_res_241;
  }
   };
  return fun238;
}
std::function<::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
