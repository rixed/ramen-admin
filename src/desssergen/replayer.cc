#include <algorithm>
#include <charconv>  // for from_chars
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
struct t40120715e1a398c85256df6891079958 : public std::tuple<
  uint16_t,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(t40120715e1a398c85256df6891079958 const &a, t40120715e1a398c85256df6891079958 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t40120715e1a398c85256df6891079958 const &a, t40120715e1a398c85256df6891079958 const &b) {
  return !operator==(a, b);
}
struct t {
  dessser::gen::time_range::t_ext time_range;
  double creation;
  std::optional<uint32_t> pid;
  double last_killed;
  std::optional<std::string> exit_status;
  Arr<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> channels;
  t(dessser::gen::time_range::t_ext time_range_, double creation_, std::optional<uint32_t> pid_, double last_killed_, std::optional<std::string> exit_status_, Arr<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> channels_) : time_range(time_range_), creation(creation_), pid(pid_), last_killed(last_killed_), exit_status(exit_status_), channels(channels_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::time_range::Deref(a.time_range) == ::dessser::gen::time_range::Deref(b.time_range) && a.creation == b.creation && ((a.pid && b.pid && a.pid.value() == b.pid.value()) || (!a.pid && !b.pid)) && a.last_killed == b.last_killed && ((a.exit_status && b.exit_status && a.exit_status.value() == b.exit_status.value()) || (!a.exit_status && !b.exit_status)) && a.channels == b.channels;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t43148a704ce6e620b06d3626aee0c192 : public std::tuple<
  ::dessser::gen::replayer::t,
  Pointer
> {
  using tuple::tuple;
  t43148a704ce6e620b06d3626aee0c192(std::tuple<::dessser::gen::replayer::t, Pointer> p)
    : std::tuple<::dessser::gen::replayer::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t43148a704ce6e620b06d3626aee0c192 const &a, t43148a704ce6e620b06d3626aee0c192 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t43148a704ce6e620b06d3626aee0c192 const &a, t43148a704ce6e620b06d3626aee0c192 const &b) {
  return !operator==(a, b);
}
struct t7ed2098d1a18c9b684db63350a7b96cb : public std::tuple<
  dessser::gen::time_range::t_ext,
  Pointer
> {
  using tuple::tuple;
  t7ed2098d1a18c9b684db63350a7b96cb(std::tuple<dessser::gen::time_range::t_ext, Pointer> p)
    : std::tuple<dessser::gen::time_range::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7ed2098d1a18c9b684db63350a7b96cb const &a, t7ed2098d1a18c9b684db63350a7b96cb const &b) {
  return ::dessser::gen::time_range::Deref(std::get<0>(a)) == ::dessser::gen::time_range::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7ed2098d1a18c9b684db63350a7b96cb const &a, t7ed2098d1a18c9b684db63350a7b96cb const &b) {
  return !operator==(a, b);
}
struct td2cd337bb3c8bc04d5603393d084985b : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  td2cd337bb3c8bc04d5603393d084985b(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return !operator==(a, b);
}
struct t9a758baeff17224a77e1a522010b4168 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t9a758baeff17224a77e1a522010b4168(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return !operator==(a, b);
}
struct t112740284841ba75ec1e9fc60758e609 : public std::tuple<
  std::optional<uint32_t>,
  Pointer
> {
  using tuple::tuple;
  t112740284841ba75ec1e9fc60758e609(std::tuple<std::optional<uint32_t>, Pointer> p)
    : std::tuple<std::optional<uint32_t>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t112740284841ba75ec1e9fc60758e609 const &a, t112740284841ba75ec1e9fc60758e609 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t112740284841ba75ec1e9fc60758e609 const &a, t112740284841ba75ec1e9fc60758e609 const &b) {
  return !operator==(a, b);
}
struct t491c44439106a32f896827242e8e76a1 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t491c44439106a32f896827242e8e76a1(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return !operator==(a, b);
}
struct ta18b971ad5bf537b68fb1bbf5fd2b926 : public std::tuple<
  std::optional<std::string>,
  Pointer
> {
  using tuple::tuple;
  ta18b971ad5bf537b68fb1bbf5fd2b926(std::tuple<std::optional<std::string>, Pointer> p)
    : std::tuple<std::optional<std::string>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta18b971ad5bf537b68fb1bbf5fd2b926 const &a, ta18b971ad5bf537b68fb1bbf5fd2b926 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta18b971ad5bf537b68fb1bbf5fd2b926 const &a, ta18b971ad5bf537b68fb1bbf5fd2b926 const &b) {
  return !operator==(a, b);
}
struct t12fb9c475959b52bf7b17b155a955ffa : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t12fb9c475959b52bf7b17b155a955ffa(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return !operator==(a, b);
}
struct t1a5d74abf838df33f185a72a8912f5c9 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1a5d74abf838df33f185a72a8912f5c9(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return !operator==(a, b);
}
struct t9ef6882174ae71a34a3c5ef6b29242fb : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t9ef6882174ae71a34a3c5ef6b29242fb(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return !operator==(a, b);
}
struct t81bc7f129035597d3aeaf7708866bb06 : public std::tuple<
  Lst<::dessser::gen::replayer::t40120715e1a398c85256df6891079958>,
  Pointer
> {
  using tuple::tuple;
  t81bc7f129035597d3aeaf7708866bb06(std::tuple<Lst<::dessser::gen::replayer::t40120715e1a398c85256df6891079958>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::replayer::t40120715e1a398c85256df6891079958>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t81bc7f129035597d3aeaf7708866bb06 const &a, t81bc7f129035597d3aeaf7708866bb06 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t81bc7f129035597d3aeaf7708866bb06 const &a, t81bc7f129035597d3aeaf7708866bb06 const &b) {
  return !operator==(a, b);
}
struct ta97bb48ed75bbda6173555873826c8c6 : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  ta97bb48ed75bbda6173555873826c8c6(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{time_range: $time_range; creation: FLOAT; pid: U32?; last_killed: FLOAT; exit_status: STRING?; channels: (U16; BOOL)[]}" "Ptr")
      (let "srec_dst_161"
        (let "srec_dst_158"
          (let "srec_dst_157"
            (let "srec_dst_156"
              (let "srec_dst_155" (apply (ext-identifier time_range to-row-binary) (get-field "time_range" (param 0)) (param 1))
                (write-u64 little-endian (identifier "srec_dst_155") (u64-of-float (get-field "creation" (param 0)))))
              (if (is-null (get-field "pid" (param 0))) (write-u8 (identifier "srec_dst_156") (u8 1)) (write-u32 little-endian (write-u8 (identifier "srec_dst_156") (u8 0)) (force (get-field "pid" (param 0))))))
            (write-u64 little-endian (identifier "srec_dst_157") (u64-of-float (get-field "last_killed" (param 0)))))
          (if (is-null (get-field "exit_status" (param 0))) (write-u8 (identifier "srec_dst_158") (u8 1))
            (write-bytes
              (let "leb128_sz_159" (make-vec (string-length (force (get-field "exit_status" (param 0)))))
                (let "leb128_ptr_160" (make-vec (write-u8 (identifier "srec_dst_158") (u8 0)))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_160")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_160"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_159"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_159"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_159"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_159") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_159")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_159")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_160"))))) 
              (bytes-of-string (force (get-field "exit_status" (param 0)))))))
        (let "dst_ref_164"
          (make-vec
            (let "leb128_sz_162" (make-vec (cardinality (get-field "channels" (param 0))))
              (let "leb128_ptr_163" (make-vec (identifier "srec_dst_161"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_163")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_163"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_162"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_162"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_162"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_162") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_162")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_162")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_163"))))))
          (let "n_ref_165" (make-vec (i32 0))
            (seq
              (for-each "x_166" (get-field "channels" (param 0))
                (seq
                  (set-vec (u8 0) (identifier "dst_ref_164")
                    (let "stup_dst_168" (let "stup_dst_167" (unsafe-nth (u8 0) (identifier "dst_ref_164")) (write-u16 little-endian (identifier "stup_dst_167") (get-item 0 (identifier "x_166"))))
                      (write-u8 (identifier "stup_dst_168") (u8-of-bool (get-item 1 (identifier "x_166")))))) 
                  (set-vec (u8 0) (identifier "n_ref_165") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_165")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_164")))))))
 */
static std::function<Pointer(::dessser::gen::replayer::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::replayer::t &,Pointer &)> fun0 { [&](::dessser::gen::replayer::t p_0, Pointer p_1) {
    auto fun1 { dessser::gen::time_range::to_row_binary };
    dessser::gen::time_range::t_ext id_2 { p_0.time_range };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_155 { id_3 };
      double id_5 { p_0.creation };
      uint64_t id_6 { qword_of_float(id_5) };
      Pointer id_7 { srec_dst_155.writeU64Le(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_156 { let_res_4 };
      std::optional<uint32_t> id_9 { p_0.pid };
      bool id_10 { !(id_9.has_value ()) };
      Pointer choose_res_11;
      if (id_10) {
        uint8_t id_12 { 1 };
        Pointer id_13 { srec_dst_156.writeU8(id_12) };
        choose_res_11 = id_13;
      } else {
        uint8_t id_14 { 0 };
        Pointer id_15 { srec_dst_156.writeU8(id_14) };
        std::optional<uint32_t> id_16 { p_0.pid };
        uint32_t id_17 { id_16.value() };
        Pointer id_18 { id_15.writeU32Le(id_17) };
        choose_res_11 = id_18;
      }
      let_res_8 = choose_res_11;
    }
    Pointer let_res_19;
    {
      Pointer srec_dst_157 { let_res_8 };
      double id_20 { p_0.last_killed };
      uint64_t id_21 { qword_of_float(id_20) };
      Pointer id_22 { srec_dst_157.writeU64Le(id_21) };
      let_res_19 = id_22;
    }
    Pointer let_res_23;
    {
      Pointer srec_dst_158 { let_res_19 };
      std::optional<std::string> id_24 { p_0.exit_status };
      bool id_25 { !(id_24.has_value ()) };
      Pointer choose_res_26;
      if (id_25) {
        uint8_t id_27 { 1 };
        Pointer id_28 { srec_dst_158.writeU8(id_27) };
        choose_res_26 = id_28;
      } else {
        std::optional<std::string> id_29 { p_0.exit_status };
        std::string id_30 { id_29.value() };
        uint32_t id_31 { (uint32_t)id_30.size() };
        Vec<1, uint32_t> id_32 {  id_31  };
        Pointer let_res_33;
        {
          Vec<1, uint32_t> leb128_sz_159 { id_32 };
          uint8_t id_34 { 0 };
          Pointer id_35 { srec_dst_158.writeU8(id_34) };
          Vec<1, Pointer> id_36 {  id_35  };
          Pointer let_res_37;
          {
            Vec<1, Pointer> leb128_ptr_160 { id_36 };
            bool while_flag_38 { true };
            do {
              uint8_t id_39 { 0 };
              uint8_t id_40 { 0 };
              Pointer id_41 { leb128_ptr_160[id_40] };
              uint32_t id_42 { 128U };
              uint8_t id_43 { 0 };
              uint32_t id_44 { leb128_sz_159[id_43] };
              bool id_45 { bool(id_42 > id_44) };
              uint8_t choose_res_46;
              if (id_45) {
                uint8_t id_47 { 0 };
                uint32_t id_48 { leb128_sz_159[id_47] };
                uint8_t id_49 { uint8_t(id_48) };
                choose_res_46 = id_49;
              } else {
                uint8_t id_50 { 0 };
                uint32_t id_51 { leb128_sz_159[id_50] };
                uint8_t id_52 { uint8_t(id_51) };
                uint8_t id_53 { 128 };
                uint8_t id_54 { uint8_t(id_52 | id_53) };
                choose_res_46 = id_54;
              }
              Pointer id_55 { id_41.writeU8(choose_res_46) };
              Void id_56 { ((void)(leb128_ptr_160[id_39] = id_55), ::dessser::Void()) };
              (void)id_56;
              uint8_t id_57 { 0 };
              uint8_t id_58 { 0 };
              uint32_t id_59 { leb128_sz_159[id_58] };
              uint8_t id_60 { 7 };
              uint32_t id_61 { uint32_t(id_59 >> id_60) };
              Void id_62 { ((void)(leb128_sz_159[id_57] = id_61), ::dessser::Void()) };
              (void)id_62;
              uint8_t id_63 { 0 };
              uint32_t id_64 { leb128_sz_159[id_63] };
              uint32_t id_65 { 0U };
              bool id_66 { bool(id_64 > id_65) };
              while_flag_38 = id_66;
              if (while_flag_38) {
                (void)::dessser::Void();
              }
            } while (while_flag_38);
            (void)::dessser::Void();
            uint8_t id_67 { 0 };
            Pointer id_68 { leb128_ptr_160[id_67] };
            let_res_37 = id_68;
          }
          let_res_33 = let_res_37;
        }
        std::optional<std::string> id_69 { p_0.exit_status };
        std::string id_70 { id_69.value() };
        Bytes id_71 { id_70 };
        Pointer id_72 { let_res_33.writeBytes(id_71) };
        choose_res_26 = id_72;
      }
      let_res_23 = choose_res_26;
    }
    Pointer let_res_73;
    {
      Pointer srec_dst_161 { let_res_23 };
      Arr<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> id_74 { p_0.channels };
      uint32_t id_75 { id_74.size() };
      Vec<1, uint32_t> id_76 {  id_75  };
      Pointer let_res_77;
      {
        Vec<1, uint32_t> leb128_sz_162 { id_76 };
        Vec<1, Pointer> id_78 {  srec_dst_161  };
        Pointer let_res_79;
        {
          Vec<1, Pointer> leb128_ptr_163 { id_78 };
          bool while_flag_80 { true };
          do {
            uint8_t id_81 { 0 };
            uint8_t id_82 { 0 };
            Pointer id_83 { leb128_ptr_163[id_82] };
            uint32_t id_84 { 128U };
            uint8_t id_85 { 0 };
            uint32_t id_86 { leb128_sz_162[id_85] };
            bool id_87 { bool(id_84 > id_86) };
            uint8_t choose_res_88;
            if (id_87) {
              uint8_t id_89 { 0 };
              uint32_t id_90 { leb128_sz_162[id_89] };
              uint8_t id_91 { uint8_t(id_90) };
              choose_res_88 = id_91;
            } else {
              uint8_t id_92 { 0 };
              uint32_t id_93 { leb128_sz_162[id_92] };
              uint8_t id_94 { uint8_t(id_93) };
              uint8_t id_95 { 128 };
              uint8_t id_96 { uint8_t(id_94 | id_95) };
              choose_res_88 = id_96;
            }
            Pointer id_97 { id_83.writeU8(choose_res_88) };
            Void id_98 { ((void)(leb128_ptr_163[id_81] = id_97), ::dessser::Void()) };
            (void)id_98;
            uint8_t id_99 { 0 };
            uint8_t id_100 { 0 };
            uint32_t id_101 { leb128_sz_162[id_100] };
            uint8_t id_102 { 7 };
            uint32_t id_103 { uint32_t(id_101 >> id_102) };
            Void id_104 { ((void)(leb128_sz_162[id_99] = id_103), ::dessser::Void()) };
            (void)id_104;
            uint8_t id_105 { 0 };
            uint32_t id_106 { leb128_sz_162[id_105] };
            uint32_t id_107 { 0U };
            bool id_108 { bool(id_106 > id_107) };
            while_flag_80 = id_108;
            if (while_flag_80) {
              (void)::dessser::Void();
            }
          } while (while_flag_80);
          (void)::dessser::Void();
          uint8_t id_109 { 0 };
          Pointer id_110 { leb128_ptr_163[id_109] };
          let_res_79 = id_110;
        }
        let_res_77 = let_res_79;
      }
      Vec<1, Pointer> id_111 {  let_res_77  };
      Pointer let_res_112;
      {
        Vec<1, Pointer> dst_ref_164 { id_111 };
        int32_t id_113 { 0L };
        Vec<1, int32_t> id_114 {  id_113  };
        Pointer let_res_115;
        {
          Vec<1, int32_t> n_ref_165 { id_114 };
          Arr<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> id_116 { p_0.channels };
          for (::dessser::gen::replayer::t40120715e1a398c85256df6891079958 const &x_166 : id_116) {
            uint8_t id_117 { 0 };
            uint8_t id_118 { 0 };
            Pointer id_119 { dst_ref_164[id_118] };
            Pointer let_res_120;
            {
              Pointer stup_dst_167 { id_119 };
              uint16_t id_121 { std::get<0>(x_166) };
              Pointer id_122 { stup_dst_167.writeU16Le(id_121) };
              let_res_120 = id_122;
            }
            Pointer let_res_123;
            {
              Pointer stup_dst_168 { let_res_120 };
              bool id_124 { std::get<1>(x_166) };
              uint8_t id_125 { uint8_t(id_124) };
              Pointer id_126 { stup_dst_168.writeU8(id_125) };
              let_res_123 = id_126;
            }
            Void id_127 { ((void)(dst_ref_164[id_117] = let_res_123), ::dessser::Void()) };
            (void)id_127;
            uint8_t id_128 { 0 };
            int32_t id_129 { 1L };
            uint8_t id_130 { 0 };
            int32_t id_131 { n_ref_165[id_130] };
            int32_t id_132 { int32_t(id_129 + id_131) };
            Void id_133 { ((void)(n_ref_165[id_128] = id_132), ::dessser::Void()) };
            (void)id_133;
            (void)id_133;
          }
          (void)::dessser::Void();
          uint8_t id_134 { 0 };
          Pointer id_135 { dst_ref_164[id_134] };
          let_res_115 = id_135;
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
std::function<Pointer(::dessser::gen::replayer::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{time_range: $time_range; creation: FLOAT; pid: U32?; last_killed: FLOAT; exit_status: STRING?; channels: (U16; BOOL)[]}")
      (let "sz_148"
        (let "sz_144"
          (add
            (let "sz_142" (add (apply (ext-identifier time_range sersize-of-row-binary) (get-field "time_range" (param 0))) (size 8))
              (if (is-null (get-field "pid" (param 0))) (add (identifier "sz_142") (size 1)) (add (add (identifier "sz_142") (size 4)) (size 1)))) 
            (size 8))
          (if (is-null (get-field "exit_status" (param 0))) (add (identifier "sz_144") (size 1))
            (add
              (add (identifier "sz_144")
                (add
                  (let "n_ref_146" (make-vec (string-length (force (get-field "exit_status" (param 0)))))
                    (let "lebsz_ref_147" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_146")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_147")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_147") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_147")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_147")))))) 
                  (size-of-u32 (string-length (force (get-field "exit_status" (param 0))))))) 
              (size 1))))
        (let "sz_ref_151"
          (make-vec
            (add (identifier "sz_148")
              (let "n_ref_149" (make-vec (cardinality (get-field "channels" (param 0))))
                (let "lebsz_ref_150" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_149")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_150")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_150") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_150")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_150"))))))))
          (seq
            (let "repeat_n_152" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "channels" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_152")))
                (seq (set-vec (u8 0) (identifier "sz_ref_151") (add (add (unsafe-nth (u8 0) (identifier "sz_ref_151")) (size 2)) (size 1)))
                  (set-vec (u8 0) (identifier "repeat_n_152") (add (unsafe-nth (u8 0) (identifier "repeat_n_152")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_151"))))))
 */
static std::function<Size(::dessser::gen::replayer::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::replayer::t &)> fun136 { [&](::dessser::gen::replayer::t p_0) {
    auto fun137 { dessser::gen::time_range::sersize_of_row_binary };
    dessser::gen::time_range::t_ext id_138 { p_0.time_range };
    Size id_139 { fun137(id_138) };
    Size id_140 { 8UL };
    Size id_141 { Size(id_139 + id_140) };
    Size let_res_142;
    {
      Size sz_142 { id_141 };
      std::optional<uint32_t> id_143 { p_0.pid };
      bool id_144 { !(id_143.has_value ()) };
      Size choose_res_145;
      if (id_144) {
        Size id_146 { 1UL };
        Size id_147 { Size(sz_142 + id_146) };
        choose_res_145 = id_147;
      } else {
        Size id_148 { 4UL };
        Size id_149 { Size(sz_142 + id_148) };
        Size id_150 { 1UL };
        Size id_151 { Size(id_149 + id_150) };
        choose_res_145 = id_151;
      }
      let_res_142 = choose_res_145;
    }
    Size id_152 { 8UL };
    Size id_153 { Size(let_res_142 + id_152) };
    Size let_res_154;
    {
      Size sz_144 { id_153 };
      std::optional<std::string> id_155 { p_0.exit_status };
      bool id_156 { !(id_155.has_value ()) };
      Size choose_res_157;
      if (id_156) {
        Size id_158 { 1UL };
        Size id_159 { Size(sz_144 + id_158) };
        choose_res_157 = id_159;
      } else {
        std::optional<std::string> id_160 { p_0.exit_status };
        std::string id_161 { id_160.value() };
        uint32_t id_162 { (uint32_t)id_161.size() };
        Vec<1, uint32_t> id_163 {  id_162  };
        Size let_res_164;
        {
          Vec<1, uint32_t> n_ref_146 { id_163 };
          uint32_t id_165 { 1U };
          Vec<1, uint32_t> id_166 {  id_165  };
          Size let_res_167;
          {
            Vec<1, uint32_t> lebsz_ref_147 { id_166 };
            bool while_flag_168 { true };
            do {
              uint8_t id_169 { 0 };
              uint32_t id_170 { n_ref_146[id_169] };
              uint8_t id_171 { 0 };
              uint32_t id_172 { lebsz_ref_147[id_171] };
              uint8_t id_173 { 7 };
              uint32_t id_174 { uint32_t(id_172 << id_173) };
              bool id_175 { bool(id_170 >= id_174) };
              while_flag_168 = id_175;
              if (while_flag_168) {
                uint8_t id_176 { 0 };
                uint8_t id_177 { 0 };
                uint32_t id_178 { lebsz_ref_147[id_177] };
                uint32_t id_179 { 1U };
                uint32_t id_180 { uint32_t(id_178 + id_179) };
                Void id_181 { ((void)(lebsz_ref_147[id_176] = id_180), ::dessser::Void()) };
                (void)id_181;
              }
            } while (while_flag_168);
            (void)::dessser::Void();
            uint8_t id_182 { 0 };
            uint32_t id_183 { lebsz_ref_147[id_182] };
            Size id_184 { Size(id_183) };
            let_res_167 = id_184;
          }
          let_res_164 = let_res_167;
        }
        std::optional<std::string> id_185 { p_0.exit_status };
        std::string id_186 { id_185.value() };
        uint32_t id_187 { (uint32_t)id_186.size() };
        Size id_188 { Size(id_187) };
        Size id_189 { Size(let_res_164 + id_188) };
        Size id_190 { Size(sz_144 + id_189) };
        Size id_191 { 1UL };
        Size id_192 { Size(id_190 + id_191) };
        choose_res_157 = id_192;
      }
      let_res_154 = choose_res_157;
    }
    Size let_res_193;
    {
      Size sz_148 { let_res_154 };
      Arr<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> id_194 { p_0.channels };
      uint32_t id_195 { id_194.size() };
      Vec<1, uint32_t> id_196 {  id_195  };
      Size let_res_197;
      {
        Vec<1, uint32_t> n_ref_149 { id_196 };
        uint32_t id_198 { 1U };
        Vec<1, uint32_t> id_199 {  id_198  };
        Size let_res_200;
        {
          Vec<1, uint32_t> lebsz_ref_150 { id_199 };
          bool while_flag_201 { true };
          do {
            uint8_t id_202 { 0 };
            uint32_t id_203 { n_ref_149[id_202] };
            uint8_t id_204 { 0 };
            uint32_t id_205 { lebsz_ref_150[id_204] };
            uint8_t id_206 { 7 };
            uint32_t id_207 { uint32_t(id_205 << id_206) };
            bool id_208 { bool(id_203 >= id_207) };
            while_flag_201 = id_208;
            if (while_flag_201) {
              uint8_t id_209 { 0 };
              uint8_t id_210 { 0 };
              uint32_t id_211 { lebsz_ref_150[id_210] };
              uint32_t id_212 { 1U };
              uint32_t id_213 { uint32_t(id_211 + id_212) };
              Void id_214 { ((void)(lebsz_ref_150[id_209] = id_213), ::dessser::Void()) };
              (void)id_214;
            }
          } while (while_flag_201);
          (void)::dessser::Void();
          uint8_t id_215 { 0 };
          uint32_t id_216 { lebsz_ref_150[id_215] };
          Size id_217 { Size(id_216) };
          let_res_200 = id_217;
        }
        let_res_197 = let_res_200;
      }
      Size id_218 { Size(sz_148 + let_res_197) };
      Vec<1, Size> id_219 {  id_218  };
      Size let_res_220;
      {
        Vec<1, Size> sz_ref_151 { id_219 };
        int32_t id_221 { 0L };
        Vec<1, int32_t> id_222 {  id_221  };
        {
          Vec<1, int32_t> repeat_n_152 { id_222 };
          bool while_flag_223 { true };
          do {
            Arr<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> id_224 { p_0.channels };
            uint32_t id_225 { id_224.size() };
            int32_t id_226 { int32_t(id_225) };
            uint8_t id_227 { 0 };
            int32_t id_228 { repeat_n_152[id_227] };
            bool id_229 { bool(id_226 > id_228) };
            while_flag_223 = id_229;
            if (while_flag_223) {
              uint8_t id_230 { 0 };
              uint8_t id_231 { 0 };
              Size id_232 { sz_ref_151[id_231] };
              Size id_233 { 2UL };
              Size id_234 { Size(id_232 + id_233) };
              Size id_235 { 1UL };
              Size id_236 { Size(id_234 + id_235) };
              Void id_237 { ((void)(sz_ref_151[id_230] = id_236), ::dessser::Void()) };
              (void)id_237;
              uint8_t id_238 { 0 };
              uint8_t id_239 { 0 };
              int32_t id_240 { repeat_n_152[id_239] };
              int32_t id_241 { 1L };
              int32_t id_242 { int32_t(id_240 + id_241) };
              Void id_243 { ((void)(repeat_n_152[id_238] = id_242), ::dessser::Void()) };
              (void)id_243;
              (void)id_243;
            }
          } while (while_flag_223);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_244 { 0 };
        Size id_245 { sz_ref_151[id_244] };
        let_res_220 = id_245;
      }
      let_res_193 = let_res_220;
    }
    return let_res_193;
  }
   };
  return fun136;
}
std::function<Size(::dessser::gen::replayer::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_57" (apply (ext-identifier time_range of-row-binary) (param 0))
        (let-pair "drec_fst_58" "drec_snd_59" (identifier "drec_57")
          (let "drec_63" (let-pair "dfloat_fst_61" "dfloat_snd_62" (read-u64 little-endian (identifier "drec_snd_59")) (make-tup (float-of-u64 (identifier "dfloat_fst_61")) (identifier "dfloat_snd_62")))
            (let-pair "drec_fst_64" "drec_snd_65" (identifier "drec_63")
              (let "drec_72"
                (if (eq (peek-u8 (identifier "drec_snd_65") (size 0)) (u8 1)) 
                  (make-tup (null "U32") (ptr-add (identifier "drec_snd_65") (size 1)))
                  (let-pair "du32_fst_67" "du32_snd_68" (read-u32 little-endian (ptr-add (identifier "drec_snd_65") (size 1))) (make-tup (not-null (identifier "du32_fst_67")) (identifier "du32_snd_68"))))
                (let-pair "drec_fst_73" "drec_snd_74" (identifier "drec_72")
                  (let "drec_78" (let-pair "dfloat_fst_76" "dfloat_snd_77" (read-u64 little-endian (identifier "drec_snd_74")) (make-tup (float-of-u64 (identifier "dfloat_fst_76")) (identifier "dfloat_snd_77")))
                    (let-pair "drec_fst_79" "drec_snd_80" (identifier "drec_78")
                      (let "drec_96"
                        (if (eq (peek-u8 (identifier "drec_snd_80") (size 0)) (u8 1)) 
                          (make-tup (null "STRING") (ptr-add (identifier "drec_snd_80") (size 1)))
                          (let "dstring1_87"
                            (let "leb_ref_81" (make-vec (u32 0))
                              (let "shft_ref_82" (make-vec (u8 0))
                                (let "p_ref_83" (make-vec (ptr-add (identifier "drec_snd_80") (size 1)))
                                  (seq
                                    (while
                                      (let "leb128_84" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_83")))
                                        (let-pair "leb128_fst_85" "leb128_snd_86" 
                                          (identifier "leb128_84")
                                          (seq (set-vec (u8 0) (identifier "p_ref_83") (identifier "leb128_snd_86"))
                                            (set-vec (u8 0) (identifier "leb_ref_81")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_85") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_82"))) (unsafe-nth (u8 0) (identifier "leb_ref_81"))))
                                            (set-vec (u8 0) (identifier "shft_ref_82") (add (unsafe-nth (u8 0) (identifier "shft_ref_82")) (u8 7))) 
                                            (ge (identifier "leb128_fst_85") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_81"))) (unsafe-nth (u8 0) (identifier "p_ref_83")))))))
                            (let-pair "dstring1_fst_88" "dstring1_snd_89" 
                              (identifier "dstring1_87")
                              (let-pair "dstring2_fst_91" "dstring2_snd_92" 
                                (read-bytes (identifier "dstring1_snd_89") (identifier "dstring1_fst_88")) 
                                (make-tup (not-null (string-of-bytes (identifier "dstring2_fst_91"))) (identifier "dstring2_snd_92"))))))
                        (let-pair "drec_fst_97" "drec_snd_98" (identifier "drec_96")
                          (let-pair "dlist4_fst_132" "dlist4_snd_133"
                            (let "dlist1_108"
                              (let "leb_ref_99" (make-vec (u32 0))
                                (let "shft_ref_100" (make-vec (u8 0))
                                  (let "p_ref_101" (make-vec (identifier "drec_snd_98"))
                                    (seq
                                      (while
                                        (let "leb128_102" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_101")))
                                          (let-pair "leb128_fst_103" "leb128_snd_104" 
                                            (identifier "leb128_102")
                                            (seq (set-vec (u8 0) (identifier "p_ref_101") (identifier "leb128_snd_104"))
                                              (set-vec (u8 0) (identifier "leb_ref_99")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_103") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_100"))) (unsafe-nth (u8 0) (identifier "leb_ref_99"))))
                                              (set-vec (u8 0) (identifier "shft_ref_100") (add (unsafe-nth (u8 0) (identifier "shft_ref_100")) (u8 7))) 
                                              (ge (identifier "leb128_fst_103") (u8 128))))) 
                                        (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_99")) (unsafe-nth (u8 0) (identifier "p_ref_101")))))))
                              (let-pair "dlist1_fst_109" "dlist1_snd_110" 
                                (identifier "dlist1_108")
                                (let "inits_src_ref_111" (make-vec (make-tup (end-of-list "(U16; BOOL)") (identifier "dlist1_snd_110")))
                                  (seq
                                    (let "repeat_n_112" (make-vec (i32 0))
                                      (while (gt (to-i32 (identifier "dlist1_fst_109")) (unsafe-nth (u8 0) (identifier "repeat_n_112")))
                                        (seq
                                          (let "dlist2_113" (unsafe-nth (u8 0) (identifier "inits_src_ref_111"))
                                            (let-pair "dlist2_fst_114" "dlist2_snd_115" 
                                              (identifier "dlist2_113")
                                              (set-vec (u8 0) (identifier "inits_src_ref_111")
                                                (let "dtup_119" (let-pair "du16_fst_117" "du16_snd_118" (read-u16 little-endian (identifier "dlist2_snd_115")) (make-tup (identifier "du16_fst_117") (identifier "du16_snd_118")))
                                                  (let-pair "dtup_fst_120" "dtup_snd_121" 
                                                    (identifier "dtup_119")
                                                    (let-pair "dbool_fst_123" "dbool_snd_124" 
                                                      (read-u8 (identifier "dtup_snd_121"))
                                                      (make-tup (cons (make-tup (identifier "dtup_fst_120") (not (eq (identifier "dbool_fst_123") (u8 0)))) (identifier "dlist2_fst_114")) (identifier "dbool_snd_124"))))))))
                                          (set-vec (u8 0) (identifier "repeat_n_112") (add (unsafe-nth (u8 0) (identifier "repeat_n_112")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_111"))))))
                            (make-tup
                              (make-rec (string "channels") (arr-of-lst-rev (identifier "dlist4_fst_132")) 
                                (string "exit_status") (identifier "drec_fst_97") 
                                (string "last_killed") (identifier "drec_fst_79") 
                                (string "pid") (identifier "drec_fst_73") 
                                (string "creation") (identifier "drec_fst_64") 
                                (string "time_range") (identifier "drec_fst_58")) 
                              (identifier "dlist4_snd_133"))))))))))))))
 */
static std::function<::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192(Pointer &)> fun246 { [&](Pointer p_0) {
    auto fun247 { dessser::gen::time_range::of_row_binary };
    ::dessser::gen::replayer::t7ed2098d1a18c9b684db63350a7b96cb id_248 { fun247(p_0) };
    ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 let_res_249;
    {
      ::dessser::gen::replayer::t7ed2098d1a18c9b684db63350a7b96cb drec_57 { id_248 };
      ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 letpair_res_250;
      {
        auto drec_fst_58 { std::get<0>(drec_57) };
        auto drec_snd_59 { std::get<1>(drec_57) };
        ::dessser::gen::replayer::td2cd337bb3c8bc04d5603393d084985b id_251 { drec_snd_59.readU64Le() };
        ::dessser::gen::replayer::t9a758baeff17224a77e1a522010b4168 letpair_res_252;
        {
          auto dfloat_fst_61 { std::get<0>(id_251) };
          auto dfloat_snd_62 { std::get<1>(id_251) };
          double id_253 { float_of_qword(dfloat_fst_61) };
          ::dessser::gen::replayer::t9a758baeff17224a77e1a522010b4168 id_254 { id_253, dfloat_snd_62 };
          letpair_res_252 = id_254;
        }
        ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 let_res_255;
        {
          ::dessser::gen::replayer::t9a758baeff17224a77e1a522010b4168 drec_63 { letpair_res_252 };
          ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 letpair_res_256;
          {
            auto drec_fst_64 { std::get<0>(drec_63) };
            auto drec_snd_65 { std::get<1>(drec_63) };
            Size id_257 { 0UL };
            uint8_t id_258 { drec_snd_65.peekU8(id_257) };
            uint8_t id_259 { 1 };
            bool id_260 { bool(id_258 == id_259) };
            ::dessser::gen::replayer::t112740284841ba75ec1e9fc60758e609 choose_res_261;
            if (id_260) {
              std::optional<uint32_t> id_262 { std::nullopt };
              Size id_263 { 1UL };
              Pointer id_264 { drec_snd_65.skip(id_263) };
              ::dessser::gen::replayer::t112740284841ba75ec1e9fc60758e609 id_265 { id_262, id_264 };
              choose_res_261 = id_265;
            } else {
              Size id_266 { 1UL };
              Pointer id_267 { drec_snd_65.skip(id_266) };
              ::dessser::gen::replayer::t491c44439106a32f896827242e8e76a1 id_268 { id_267.readU32Le() };
              ::dessser::gen::replayer::t112740284841ba75ec1e9fc60758e609 letpair_res_269;
              {
                auto du32_fst_67 { std::get<0>(id_268) };
                auto du32_snd_68 { std::get<1>(id_268) };
                std::optional<uint32_t> id_270 { du32_fst_67 };
                ::dessser::gen::replayer::t112740284841ba75ec1e9fc60758e609 id_271 { id_270, du32_snd_68 };
                letpair_res_269 = id_271;
              }
              choose_res_261 = letpair_res_269;
            }
            ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 let_res_272;
            {
              ::dessser::gen::replayer::t112740284841ba75ec1e9fc60758e609 drec_72 { choose_res_261 };
              ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 letpair_res_273;
              {
                auto drec_fst_73 { std::get<0>(drec_72) };
                auto drec_snd_74 { std::get<1>(drec_72) };
                ::dessser::gen::replayer::td2cd337bb3c8bc04d5603393d084985b id_274 { drec_snd_74.readU64Le() };
                ::dessser::gen::replayer::t9a758baeff17224a77e1a522010b4168 letpair_res_275;
                {
                  auto dfloat_fst_76 { std::get<0>(id_274) };
                  auto dfloat_snd_77 { std::get<1>(id_274) };
                  double id_276 { float_of_qword(dfloat_fst_76) };
                  ::dessser::gen::replayer::t9a758baeff17224a77e1a522010b4168 id_277 { id_276, dfloat_snd_77 };
                  letpair_res_275 = id_277;
                }
                ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 let_res_278;
                {
                  ::dessser::gen::replayer::t9a758baeff17224a77e1a522010b4168 drec_78 { letpair_res_275 };
                  ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 letpair_res_279;
                  {
                    auto drec_fst_79 { std::get<0>(drec_78) };
                    auto drec_snd_80 { std::get<1>(drec_78) };
                    Size id_280 { 0UL };
                    uint8_t id_281 { drec_snd_80.peekU8(id_280) };
                    uint8_t id_282 { 1 };
                    bool id_283 { bool(id_281 == id_282) };
                    ::dessser::gen::replayer::ta18b971ad5bf537b68fb1bbf5fd2b926 choose_res_284;
                    if (id_283) {
                      std::optional<std::string> id_285 { std::nullopt };
                      Size id_286 { 1UL };
                      Pointer id_287 { drec_snd_80.skip(id_286) };
                      ::dessser::gen::replayer::ta18b971ad5bf537b68fb1bbf5fd2b926 id_288 { id_285, id_287 };
                      choose_res_284 = id_288;
                    } else {
                      uint32_t id_289 { 0U };
                      Vec<1, uint32_t> id_290 {  id_289  };
                      ::dessser::gen::replayer::t12fb9c475959b52bf7b17b155a955ffa let_res_291;
                      {
                        Vec<1, uint32_t> leb_ref_81 { id_290 };
                        uint8_t id_292 { 0 };
                        Vec<1, uint8_t> id_293 {  id_292  };
                        ::dessser::gen::replayer::t12fb9c475959b52bf7b17b155a955ffa let_res_294;
                        {
                          Vec<1, uint8_t> shft_ref_82 { id_293 };
                          Size id_295 { 1UL };
                          Pointer id_296 { drec_snd_80.skip(id_295) };
                          Vec<1, Pointer> id_297 {  id_296  };
                          ::dessser::gen::replayer::t12fb9c475959b52bf7b17b155a955ffa let_res_298;
                          {
                            Vec<1, Pointer> p_ref_83 { id_297 };
                            bool while_flag_299 { true };
                            do {
                              uint8_t id_300 { 0 };
                              Pointer id_301 { p_ref_83[id_300] };
                              ::dessser::gen::replayer::t1a5d74abf838df33f185a72a8912f5c9 id_302 { id_301.readU8() };
                              bool let_res_303;
                              {
                                ::dessser::gen::replayer::t1a5d74abf838df33f185a72a8912f5c9 leb128_84 { id_302 };
                                bool letpair_res_304;
                                {
                                  auto leb128_fst_85 { std::get<0>(leb128_84) };
                                  auto leb128_snd_86 { std::get<1>(leb128_84) };
                                  uint8_t id_305 { 0 };
                                  Void id_306 { ((void)(p_ref_83[id_305] = leb128_snd_86), ::dessser::Void()) };
                                  (void)id_306;
                                  uint8_t id_307 { 0 };
                                  uint8_t id_308 { 127 };
                                  uint8_t id_309 { uint8_t(leb128_fst_85 & id_308) };
                                  uint32_t id_310 { uint32_t(id_309) };
                                  uint8_t id_311 { 0 };
                                  uint8_t id_312 { shft_ref_82[id_311] };
                                  uint32_t id_313 { uint32_t(id_310 << id_312) };
                                  uint8_t id_314 { 0 };
                                  uint32_t id_315 { leb_ref_81[id_314] };
                                  uint32_t id_316 { uint32_t(id_313 | id_315) };
                                  Void id_317 { ((void)(leb_ref_81[id_307] = id_316), ::dessser::Void()) };
                                  (void)id_317;
                                  uint8_t id_318 { 0 };
                                  uint8_t id_319 { 0 };
                                  uint8_t id_320 { shft_ref_82[id_319] };
                                  uint8_t id_321 { 7 };
                                  uint8_t id_322 { uint8_t(id_320 + id_321) };
                                  Void id_323 { ((void)(shft_ref_82[id_318] = id_322), ::dessser::Void()) };
                                  (void)id_323;
                                  uint8_t id_324 { 128 };
                                  bool id_325 { bool(leb128_fst_85 >= id_324) };
                                  letpair_res_304 = id_325;
                                }
                                let_res_303 = letpair_res_304;
                              }
                              while_flag_299 = let_res_303;
                              if (while_flag_299) {
                                (void)::dessser::Void();
                              }
                            } while (while_flag_299);
                            (void)::dessser::Void();
                            uint8_t id_326 { 0 };
                            uint32_t id_327 { leb_ref_81[id_326] };
                            Size id_328 { Size(id_327) };
                            uint8_t id_329 { 0 };
                            Pointer id_330 { p_ref_83[id_329] };
                            ::dessser::gen::replayer::t12fb9c475959b52bf7b17b155a955ffa id_331 { id_328, id_330 };
                            let_res_298 = id_331;
                          }
                          let_res_294 = let_res_298;
                        }
                        let_res_291 = let_res_294;
                      }
                      ::dessser::gen::replayer::ta18b971ad5bf537b68fb1bbf5fd2b926 let_res_332;
                      {
                        ::dessser::gen::replayer::t12fb9c475959b52bf7b17b155a955ffa dstring1_87 { let_res_291 };
                        ::dessser::gen::replayer::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_333;
                        {
                          auto dstring1_fst_88 { std::get<0>(dstring1_87) };
                          auto dstring1_snd_89 { std::get<1>(dstring1_87) };
                          ::dessser::gen::replayer::t9ef6882174ae71a34a3c5ef6b29242fb id_334 { dstring1_snd_89.readBytes(dstring1_fst_88) };
                          ::dessser::gen::replayer::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_335;
                          {
                            auto dstring2_fst_91 { std::get<0>(id_334) };
                            auto dstring2_snd_92 { std::get<1>(id_334) };
                            std::string id_336 { dstring2_fst_91.toString() };
                            std::optional<std::string> id_337 { id_336 };
                            ::dessser::gen::replayer::ta18b971ad5bf537b68fb1bbf5fd2b926 id_338 { id_337, dstring2_snd_92 };
                            letpair_res_335 = id_338;
                          }
                          letpair_res_333 = letpair_res_335;
                        }
                        let_res_332 = letpair_res_333;
                      }
                      choose_res_284 = let_res_332;
                    }
                    ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 let_res_339;
                    {
                      ::dessser::gen::replayer::ta18b971ad5bf537b68fb1bbf5fd2b926 drec_96 { choose_res_284 };
                      ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 letpair_res_340;
                      {
                        auto drec_fst_97 { std::get<0>(drec_96) };
                        auto drec_snd_98 { std::get<1>(drec_96) };
                        uint32_t id_341 { 0U };
                        Vec<1, uint32_t> id_342 {  id_341  };
                        ::dessser::gen::replayer::t491c44439106a32f896827242e8e76a1 let_res_343;
                        {
                          Vec<1, uint32_t> leb_ref_99 { id_342 };
                          uint8_t id_344 { 0 };
                          Vec<1, uint8_t> id_345 {  id_344  };
                          ::dessser::gen::replayer::t491c44439106a32f896827242e8e76a1 let_res_346;
                          {
                            Vec<1, uint8_t> shft_ref_100 { id_345 };
                            Vec<1, Pointer> id_347 {  drec_snd_98  };
                            ::dessser::gen::replayer::t491c44439106a32f896827242e8e76a1 let_res_348;
                            {
                              Vec<1, Pointer> p_ref_101 { id_347 };
                              bool while_flag_349 { true };
                              do {
                                uint8_t id_350 { 0 };
                                Pointer id_351 { p_ref_101[id_350] };
                                ::dessser::gen::replayer::t1a5d74abf838df33f185a72a8912f5c9 id_352 { id_351.readU8() };
                                bool let_res_353;
                                {
                                  ::dessser::gen::replayer::t1a5d74abf838df33f185a72a8912f5c9 leb128_102 { id_352 };
                                  bool letpair_res_354;
                                  {
                                    auto leb128_fst_103 { std::get<0>(leb128_102) };
                                    auto leb128_snd_104 { std::get<1>(leb128_102) };
                                    uint8_t id_355 { 0 };
                                    Void id_356 { ((void)(p_ref_101[id_355] = leb128_snd_104), ::dessser::Void()) };
                                    (void)id_356;
                                    uint8_t id_357 { 0 };
                                    uint8_t id_358 { 127 };
                                    uint8_t id_359 { uint8_t(leb128_fst_103 & id_358) };
                                    uint32_t id_360 { uint32_t(id_359) };
                                    uint8_t id_361 { 0 };
                                    uint8_t id_362 { shft_ref_100[id_361] };
                                    uint32_t id_363 { uint32_t(id_360 << id_362) };
                                    uint8_t id_364 { 0 };
                                    uint32_t id_365 { leb_ref_99[id_364] };
                                    uint32_t id_366 { uint32_t(id_363 | id_365) };
                                    Void id_367 { ((void)(leb_ref_99[id_357] = id_366), ::dessser::Void()) };
                                    (void)id_367;
                                    uint8_t id_368 { 0 };
                                    uint8_t id_369 { 0 };
                                    uint8_t id_370 { shft_ref_100[id_369] };
                                    uint8_t id_371 { 7 };
                                    uint8_t id_372 { uint8_t(id_370 + id_371) };
                                    Void id_373 { ((void)(shft_ref_100[id_368] = id_372), ::dessser::Void()) };
                                    (void)id_373;
                                    uint8_t id_374 { 128 };
                                    bool id_375 { bool(leb128_fst_103 >= id_374) };
                                    letpair_res_354 = id_375;
                                  }
                                  let_res_353 = letpair_res_354;
                                }
                                while_flag_349 = let_res_353;
                                if (while_flag_349) {
                                  (void)::dessser::Void();
                                }
                              } while (while_flag_349);
                              (void)::dessser::Void();
                              uint8_t id_376 { 0 };
                              uint32_t id_377 { leb_ref_99[id_376] };
                              uint8_t id_378 { 0 };
                              Pointer id_379 { p_ref_101[id_378] };
                              ::dessser::gen::replayer::t491c44439106a32f896827242e8e76a1 id_380 { id_377, id_379 };
                              let_res_348 = id_380;
                            }
                            let_res_346 = let_res_348;
                          }
                          let_res_343 = let_res_346;
                        }
                        ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 let_res_381;
                        {
                          ::dessser::gen::replayer::t491c44439106a32f896827242e8e76a1 dlist1_108 { let_res_343 };
                          ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 letpair_res_382;
                          {
                            auto dlist1_fst_109 { std::get<0>(dlist1_108) };
                            auto dlist1_snd_110 { std::get<1>(dlist1_108) };
                            Lst<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> endoflist_383;
                            ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 id_384 { endoflist_383, dlist1_snd_110 };
                            Vec<1, ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06> id_385 {  id_384  };
                            ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 let_res_386;
                            {
                              Vec<1, ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06> inits_src_ref_111 { id_385 };
                              int32_t id_387 { 0L };
                              Vec<1, int32_t> id_388 {  id_387  };
                              {
                                Vec<1, int32_t> repeat_n_112 { id_388 };
                                bool while_flag_389 { true };
                                do {
                                  int32_t id_390 { int32_t(dlist1_fst_109) };
                                  uint8_t id_391 { 0 };
                                  int32_t id_392 { repeat_n_112[id_391] };
                                  bool id_393 { bool(id_390 > id_392) };
                                  while_flag_389 = id_393;
                                  if (while_flag_389) {
                                    uint8_t id_394 { 0 };
                                    ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 id_395 { inits_src_ref_111[id_394] };
                                    {
                                      ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 dlist2_113 { id_395 };
                                      {
                                        auto dlist2_fst_114 { std::get<0>(dlist2_113) };
                                        auto dlist2_snd_115 { std::get<1>(dlist2_113) };
                                        uint8_t id_396 { 0 };
                                        ::dessser::gen::replayer::ta97bb48ed75bbda6173555873826c8c6 id_397 { dlist2_snd_115.readU16Le() };
                                        ::dessser::gen::replayer::ta97bb48ed75bbda6173555873826c8c6 letpair_res_398;
                                        {
                                          auto du16_fst_117 { std::get<0>(id_397) };
                                          auto du16_snd_118 { std::get<1>(id_397) };
                                          ::dessser::gen::replayer::ta97bb48ed75bbda6173555873826c8c6 id_399 { du16_fst_117, du16_snd_118 };
                                          letpair_res_398 = id_399;
                                        }
                                        ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 let_res_400;
                                        {
                                          ::dessser::gen::replayer::ta97bb48ed75bbda6173555873826c8c6 dtup_119 { letpair_res_398 };
                                          ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 letpair_res_401;
                                          {
                                            auto dtup_fst_120 { std::get<0>(dtup_119) };
                                            auto dtup_snd_121 { std::get<1>(dtup_119) };
                                            ::dessser::gen::replayer::t1a5d74abf838df33f185a72a8912f5c9 id_402 { dtup_snd_121.readU8() };
                                            ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 letpair_res_403;
                                            {
                                              auto dbool_fst_123 { std::get<0>(id_402) };
                                              auto dbool_snd_124 { std::get<1>(id_402) };
                                              uint8_t id_404 { 0 };
                                              bool id_405 { bool(dbool_fst_123 == id_404) };
                                              bool id_406 { ! id_405 };
                                              ::dessser::gen::replayer::t40120715e1a398c85256df6891079958 id_407 { dtup_fst_120, id_406 };
                                              Lst<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> id_408 { id_407, dlist2_fst_114 };
                                              ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 id_409 { id_408, dbool_snd_124 };
                                              letpair_res_403 = id_409;
                                            }
                                            letpair_res_401 = letpair_res_403;
                                          }
                                          let_res_400 = letpair_res_401;
                                        }
                                        Void id_410 { ((void)(inits_src_ref_111[id_396] = let_res_400), ::dessser::Void()) };
                                        (void)id_410;
                                      }
                                      (void)::dessser::Void();
                                    }
                                    (void)::dessser::Void();
                                    uint8_t id_411 { 0 };
                                    uint8_t id_412 { 0 };
                                    int32_t id_413 { repeat_n_112[id_412] };
                                    int32_t id_414 { 1L };
                                    int32_t id_415 { int32_t(id_413 + id_414) };
                                    Void id_416 { ((void)(repeat_n_112[id_411] = id_415), ::dessser::Void()) };
                                    (void)id_416;
                                    (void)id_416;
                                  }
                                } while (while_flag_389);
                                (void)::dessser::Void();
                              }
                              (void)::dessser::Void();
                              uint8_t id_417 { 0 };
                              ::dessser::gen::replayer::t81bc7f129035597d3aeaf7708866bb06 id_418 { inits_src_ref_111[id_417] };
                              let_res_386 = id_418;
                            }
                            letpair_res_382 = let_res_386;
                          }
                          let_res_381 = letpair_res_382;
                        }
                        ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 letpair_res_419;
                        {
                          auto dlist4_fst_132 { std::get<0>(let_res_381) };
                          auto dlist4_snd_133 { std::get<1>(let_res_381) };
                          Arr<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> id_420 { dlist4_fst_132.toArrRev() };
                          ::dessser::gen::replayer::t id_421 { drec_fst_58, drec_fst_64, drec_fst_73, drec_fst_79, drec_fst_97, id_420 };
                          ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 id_422 { id_421, dlist4_snd_133 };
                          letpair_res_419 = id_422;
                        }
                        letpair_res_340 = letpair_res_419;
                      }
                      let_res_339 = letpair_res_340;
                    }
                    letpair_res_279 = let_res_339;
                  }
                  let_res_278 = letpair_res_279;
                }
                letpair_res_273 = let_res_278;
              }
              let_res_272 = letpair_res_273;
            }
            letpair_res_256 = let_res_272;
          }
          let_res_255 = letpair_res_256;
        }
        letpair_res_250 = let_res_255;
      }
      let_res_249 = letpair_res_250;
    }
    return let_res_249;
  }
   };
  return fun246;
}
std::function<::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_138" "make_snd_139" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_138") (identifier "make_snd_139"))))
 */
static std::function<::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192(Pointer &)> fun423 { [&](Pointer p_0) {
    ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 id_424 { of_row_binary(p_0) };
    ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 letpair_res_425;
    {
      auto make_fst_138 { std::get<0>(id_424) };
      auto make_snd_139 { std::get<1>(id_424) };
      ::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192 id_426 { make_fst_138, make_snd_139 };
      letpair_res_425 = id_426;
    }
    return letpair_res_425;
  }
   };
  return fun423;
}
std::function<::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{time_range: $time_range; creation: FLOAT; pid: U32?; last_killed: FLOAT; exit_status: STRING?; channels: (U16; BOOL)[]}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::replayer::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::replayer::t &,Pointer &)> fun427 { [&](::dessser::gen::replayer::t p_0, Pointer p_1) {
    Pointer id_428 { to_row_binary(p_0, p_1) };
    return id_428;
  }
   };
  return fun427;
}
std::function<Pointer(::dessser::gen::replayer::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
