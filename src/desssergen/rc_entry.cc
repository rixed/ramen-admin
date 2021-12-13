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
#include "desssergen/program_run_parameter.h"
#include "desssergen/file_path.h"
#include "desssergen/program_name.h"

namespace dessser::gen::rc_entry {
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
  bool automatic;
  dessser::gen::file_path::t_ext cwd;
  bool debug;
  bool enabled;
  std::string on_site;
  Arr<dessser::gen::program_run_parameter::t_ext> params;
  dessser::gen::program_name::t_ext program;
  double report_period;
  t(bool automatic_, dessser::gen::file_path::t_ext cwd_, bool debug_, bool enabled_, std::string on_site_, Arr<dessser::gen::program_run_parameter::t_ext> params_, dessser::gen::program_name::t_ext program_, double report_period_) : automatic(automatic_), cwd(cwd_), debug(debug_), enabled(enabled_), on_site(on_site_), params(params_), program(program_), report_period(report_period_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.automatic == b.automatic && ::dessser::gen::file_path::Deref(a.cwd) == ::dessser::gen::file_path::Deref(b.cwd) && a.debug == b.debug && a.enabled == b.enabled && a.on_site == b.on_site && a.params == b.params && ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && a.report_period == b.report_period;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t3ac1055254e339c986a46055f673c8c3 : public std::tuple<
  std::shared_ptr<::dessser::gen::rc_entry::t> ,
  Pointer
> {
  using tuple::tuple;
  t3ac1055254e339c986a46055f673c8c3(std::tuple<std::shared_ptr<::dessser::gen::rc_entry::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::rc_entry::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3ac1055254e339c986a46055f673c8c3 const &a, t3ac1055254e339c986a46055f673c8c3 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3ac1055254e339c986a46055f673c8c3 const &a, t3ac1055254e339c986a46055f673c8c3 const &b) {
  return !operator==(a, b);
}
struct td8645decacfa82d2239ee8ec2f67634c : public std::tuple<
  dessser::gen::program_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  td8645decacfa82d2239ee8ec2f67634c(std::tuple<dessser::gen::program_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::program_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td8645decacfa82d2239ee8ec2f67634c const &a, td8645decacfa82d2239ee8ec2f67634c const &b) {
  return ::dessser::gen::program_name::Deref(std::get<0>(a)) == ::dessser::gen::program_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td8645decacfa82d2239ee8ec2f67634c const &a, td8645decacfa82d2239ee8ec2f67634c const &b) {
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
struct tf9a0a3fefc87c9e10a93d3a172850c26 : public std::tuple<
  bool,
  Pointer
> {
  using tuple::tuple;
  tf9a0a3fefc87c9e10a93d3a172850c26(std::tuple<bool, Pointer> p)
    : std::tuple<bool, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf9a0a3fefc87c9e10a93d3a172850c26 const &a, tf9a0a3fefc87c9e10a93d3a172850c26 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf9a0a3fefc87c9e10a93d3a172850c26 const &a, tf9a0a3fefc87c9e10a93d3a172850c26 const &b) {
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
struct td0a4a9551c4a7c5b58d84275e2a098f7 : public std::tuple<
  dessser::gen::file_path::t_ext,
  Pointer
> {
  using tuple::tuple;
  td0a4a9551c4a7c5b58d84275e2a098f7(std::tuple<dessser::gen::file_path::t_ext, Pointer> p)
    : std::tuple<dessser::gen::file_path::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td0a4a9551c4a7c5b58d84275e2a098f7 const &a, td0a4a9551c4a7c5b58d84275e2a098f7 const &b) {
  return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td0a4a9551c4a7c5b58d84275e2a098f7 const &a, td0a4a9551c4a7c5b58d84275e2a098f7 const &b) {
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
struct taab67abdcc93367ee872580987df9cf6 : public std::tuple<
  Lst<dessser::gen::program_run_parameter::t_ext>,
  Pointer
> {
  using tuple::tuple;
  taab67abdcc93367ee872580987df9cf6(std::tuple<Lst<dessser::gen::program_run_parameter::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::program_run_parameter::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(taab67abdcc93367ee872580987df9cf6 const &a, taab67abdcc93367ee872580987df9cf6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(taab67abdcc93367ee872580987df9cf6 const &a, taab67abdcc93367ee872580987df9cf6 const &b) {
  return !operator==(a, b);
}
struct t3d7e4d9b51a9bc2481748f08f14d9374 : public std::tuple<
  dessser::gen::program_run_parameter::t_ext,
  Pointer
> {
  using tuple::tuple;
  t3d7e4d9b51a9bc2481748f08f14d9374(std::tuple<dessser::gen::program_run_parameter::t_ext, Pointer> p)
    : std::tuple<dessser::gen::program_run_parameter::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3d7e4d9b51a9bc2481748f08f14d9374 const &a, t3d7e4d9b51a9bc2481748f08f14d9374 const &b) {
  return ::dessser::gen::program_run_parameter::Deref(std::get<0>(a)) == ::dessser::gen::program_run_parameter::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3d7e4d9b51a9bc2481748f08f14d9374 const &a, t3d7e4d9b51a9bc2481748f08f14d9374 const &b) {
  return !operator==(a, b);
}
struct t8deaa632b9b85a15bf9974356fd5ba15 : public std::tuple<
  Arr<dessser::gen::program_run_parameter::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t8deaa632b9b85a15bf9974356fd5ba15(std::tuple<Arr<dessser::gen::program_run_parameter::t_ext>, Pointer> p)
    : std::tuple<Arr<dessser::gen::program_run_parameter::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8deaa632b9b85a15bf9974356fd5ba15 const &a, t8deaa632b9b85a15bf9974356fd5ba15 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8deaa632b9b85a15bf9974356fd5ba15 const &a, t8deaa632b9b85a15bf9974356fd5ba15 const &b) {
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
struct t13a07ee37ab40962540da8534858dc07 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t13a07ee37ab40962540da8534858dc07(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{program: $program_name; enabled: BOOL; debug: BOOL; report_period: FLOAT; cwd: $file_path; params: $program_run_parameter[]; on_site: STRING; automatic: BOOL}" "Ptr")
      (let "srec_dst_158"
        (let "srec_dst_155"
          (let "srec_dst_149"
            (let "srec_dst_148"
              (let "srec_dst_147"
                (let "srec_dst_146"
                  (let "srec_dst_145" (apply (ext-identifier program_name to-row-binary) (get-field "program" (param 0)) (param 1)) (write-u8 (identifier "srec_dst_145") (u8-of-bool (get-field "enabled" (param 0)))))
                  (write-u8 (identifier "srec_dst_146") (u8-of-bool (get-field "debug" (param 0))))) 
                (write-u64 little-endian (identifier "srec_dst_147") (u64-of-float (get-field "report_period" (param 0))))) 
              (apply (ext-identifier file_path to-row-binary) (get-field "cwd" (param 0)) (identifier "srec_dst_148")))
            (let "dst_ref_152"
              (make-vec
                (let "leb128_sz_150" (make-vec (cardinality (get-field "params" (param 0))))
                  (let "leb128_ptr_151" (make-vec (identifier "srec_dst_149"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_151")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_151"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_150"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_150"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_150"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_150") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_150")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_150")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_151"))))))
              (let "n_ref_153" (make-vec (i32 0))
                (seq
                  (for-each "x_154" (get-field "params" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_152") (apply (ext-identifier program_run_parameter to-row-binary) (identifier "x_154") (unsafe-nth (u8 0) (identifier "dst_ref_152"))))
                      (set-vec (u8 0) (identifier "n_ref_153") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_153")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_152"))))))
          (write-bytes
            (let "leb128_sz_156" (make-vec (string-length (get-field "on_site" (param 0))))
              (let "leb128_ptr_157" (make-vec (identifier "srec_dst_155"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_157")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_157"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_156"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_156"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_156"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_156") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_156")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_156")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_157"))))) 
            (bytes-of-string (get-field "on_site" (param 0))))) (write-u8 (identifier "srec_dst_158") (u8-of-bool (get-field "automatic" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::rc_entry::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::rc_entry::t> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::rc_entry::t>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::program_name::to_row_binary };
    dessser::gen::program_name::t_ext id_2 { (*p_0).program };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_145 { id_3 };
      bool id_5 { (*p_0).enabled };
      uint8_t id_6 { uint8_t(id_5) };
      Pointer id_7 { srec_dst_145.writeU8(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_146 { let_res_4 };
      bool id_9 { (*p_0).debug };
      uint8_t id_10 { uint8_t(id_9) };
      Pointer id_11 { srec_dst_146.writeU8(id_10) };
      let_res_8 = id_11;
    }
    Pointer let_res_12;
    {
      Pointer srec_dst_147 { let_res_8 };
      double id_13 { (*p_0).report_period };
      uint64_t id_14 { qword_of_float(id_13) };
      Pointer id_15 { srec_dst_147.writeU64Le(id_14) };
      let_res_12 = id_15;
    }
    Pointer let_res_16;
    {
      Pointer srec_dst_148 { let_res_12 };
      auto fun17 { dessser::gen::file_path::to_row_binary };
      dessser::gen::file_path::t_ext id_18 { (*p_0).cwd };
      Pointer id_19 { fun17(id_18, srec_dst_148) };
      let_res_16 = id_19;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_149 { let_res_16 };
      Arr<dessser::gen::program_run_parameter::t_ext> id_21 { (*p_0).params };
      uint32_t id_22 { id_21.size() };
      Vec<1, uint32_t> id_23 {  id_22  };
      Pointer let_res_24;
      {
        Vec<1, uint32_t> leb128_sz_150 { id_23 };
        Vec<1, Pointer> id_25 {  srec_dst_149  };
        Pointer let_res_26;
        {
          Vec<1, Pointer> leb128_ptr_151 { id_25 };
          bool while_flag_27 { true };
          do {
            uint8_t id_28 { 0 };
            uint8_t id_29 { 0 };
            Pointer id_30 { leb128_ptr_151[id_29] };
            uint32_t id_31 { 128U };
            uint8_t id_32 { 0 };
            uint32_t id_33 { leb128_sz_150[id_32] };
            bool id_34 { bool(id_31 > id_33) };
            uint8_t choose_res_35;
            if (id_34) {
              uint8_t id_36 { 0 };
              uint32_t id_37 { leb128_sz_150[id_36] };
              uint8_t id_38 { uint8_t(id_37) };
              choose_res_35 = id_38;
            } else {
              uint8_t id_39 { 0 };
              uint32_t id_40 { leb128_sz_150[id_39] };
              uint8_t id_41 { uint8_t(id_40) };
              uint8_t id_42 { 128 };
              uint8_t id_43 { uint8_t(id_41 | id_42) };
              choose_res_35 = id_43;
            }
            Pointer id_44 { id_30.writeU8(choose_res_35) };
            Void id_45 { ((void)(leb128_ptr_151[id_28] = id_44), ::dessser::VOID) };
            (void)id_45;
            uint8_t id_46 { 0 };
            uint8_t id_47 { 0 };
            uint32_t id_48 { leb128_sz_150[id_47] };
            uint8_t id_49 { 7 };
            uint32_t id_50 { uint32_t(id_48 >> id_49) };
            Void id_51 { ((void)(leb128_sz_150[id_46] = id_50), ::dessser::VOID) };
            (void)id_51;
            uint8_t id_52 { 0 };
            uint32_t id_53 { leb128_sz_150[id_52] };
            uint32_t id_54 { 0U };
            bool id_55 { bool(id_53 > id_54) };
            while_flag_27 = id_55;
            if (while_flag_27) {
              (void)::dessser::VOID;
            }
          } while (while_flag_27);
          (void)::dessser::VOID;
          uint8_t id_56 { 0 };
          Pointer id_57 { leb128_ptr_151[id_56] };
          let_res_26 = id_57;
        }
        let_res_24 = let_res_26;
      }
      Vec<1, Pointer> id_58 {  let_res_24  };
      Pointer let_res_59;
      {
        Vec<1, Pointer> dst_ref_152 { id_58 };
        int32_t id_60 { 0L };
        Vec<1, int32_t> id_61 {  id_60  };
        Pointer let_res_62;
        {
          Vec<1, int32_t> n_ref_153 { id_61 };
          Arr<dessser::gen::program_run_parameter::t_ext> id_63 { (*p_0).params };
          for (dessser::gen::program_run_parameter::t_ext x_154 : id_63) {
            uint8_t id_64 { 0 };
            auto fun65 { dessser::gen::program_run_parameter::to_row_binary };
            uint8_t id_66 { 0 };
            Pointer id_67 { dst_ref_152[id_66] };
            Pointer id_68 { fun65(x_154, id_67) };
            Void id_69 { ((void)(dst_ref_152[id_64] = id_68), ::dessser::VOID) };
            (void)id_69;
            uint8_t id_70 { 0 };
            int32_t id_71 { 1L };
            uint8_t id_72 { 0 };
            int32_t id_73 { n_ref_153[id_72] };
            int32_t id_74 { int32_t(id_71 + id_73) };
            Void id_75 { ((void)(n_ref_153[id_70] = id_74), ::dessser::VOID) };
            (void)id_75;
            (void)id_75;
          }
          (void)::dessser::VOID;
          uint8_t id_76 { 0 };
          Pointer id_77 { dst_ref_152[id_76] };
          let_res_62 = id_77;
        }
        let_res_59 = let_res_62;
      }
      let_res_20 = let_res_59;
    }
    Pointer let_res_78;
    {
      Pointer srec_dst_155 { let_res_20 };
      std::string id_79 { (*p_0).on_site };
      uint32_t id_80 { (uint32_t)id_79.size() };
      Vec<1, uint32_t> id_81 {  id_80  };
      Pointer let_res_82;
      {
        Vec<1, uint32_t> leb128_sz_156 { id_81 };
        Vec<1, Pointer> id_83 {  srec_dst_155  };
        Pointer let_res_84;
        {
          Vec<1, Pointer> leb128_ptr_157 { id_83 };
          bool while_flag_85 { true };
          do {
            uint8_t id_86 { 0 };
            uint8_t id_87 { 0 };
            Pointer id_88 { leb128_ptr_157[id_87] };
            uint32_t id_89 { 128U };
            uint8_t id_90 { 0 };
            uint32_t id_91 { leb128_sz_156[id_90] };
            bool id_92 { bool(id_89 > id_91) };
            uint8_t choose_res_93;
            if (id_92) {
              uint8_t id_94 { 0 };
              uint32_t id_95 { leb128_sz_156[id_94] };
              uint8_t id_96 { uint8_t(id_95) };
              choose_res_93 = id_96;
            } else {
              uint8_t id_97 { 0 };
              uint32_t id_98 { leb128_sz_156[id_97] };
              uint8_t id_99 { uint8_t(id_98) };
              uint8_t id_100 { 128 };
              uint8_t id_101 { uint8_t(id_99 | id_100) };
              choose_res_93 = id_101;
            }
            Pointer id_102 { id_88.writeU8(choose_res_93) };
            Void id_103 { ((void)(leb128_ptr_157[id_86] = id_102), ::dessser::VOID) };
            (void)id_103;
            uint8_t id_104 { 0 };
            uint8_t id_105 { 0 };
            uint32_t id_106 { leb128_sz_156[id_105] };
            uint8_t id_107 { 7 };
            uint32_t id_108 { uint32_t(id_106 >> id_107) };
            Void id_109 { ((void)(leb128_sz_156[id_104] = id_108), ::dessser::VOID) };
            (void)id_109;
            uint8_t id_110 { 0 };
            uint32_t id_111 { leb128_sz_156[id_110] };
            uint32_t id_112 { 0U };
            bool id_113 { bool(id_111 > id_112) };
            while_flag_85 = id_113;
            if (while_flag_85) {
              (void)::dessser::VOID;
            }
          } while (while_flag_85);
          (void)::dessser::VOID;
          uint8_t id_114 { 0 };
          Pointer id_115 { leb128_ptr_157[id_114] };
          let_res_84 = id_115;
        }
        let_res_82 = let_res_84;
      }
      std::string id_116 { (*p_0).on_site };
      Bytes id_117 { id_116 };
      Pointer id_118 { let_res_82.writeBytes(id_117) };
      let_res_78 = id_118;
    }
    Pointer let_res_119;
    {
      Pointer srec_dst_158 { let_res_78 };
      bool id_120 { (*p_0).automatic };
      uint8_t id_121 { uint8_t(id_120) };
      Pointer id_122 { srec_dst_158.writeU8(id_121) };
      let_res_119 = id_122;
    }
    return let_res_119;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::rc_entry::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{program: $program_name; enabled: BOOL; debug: BOOL; report_period: FLOAT; cwd: $file_path; params: $program_run_parameter[]; on_site: STRING; automatic: BOOL}")
      (add
        (let "sz_140"
          (let "sz_135"
            (let "sz_134" (add (add (add (apply (ext-identifier program_name sersize-of-row-binary) (get-field "program" (param 0))) (size 1)) (size 1)) (size 8))
              (add (identifier "sz_134") (apply (ext-identifier file_path sersize-of-row-binary) (get-field "cwd" (param 0)))))
            (let "sz_ref_138"
              (make-vec
                (add (identifier "sz_135")
                  (let "n_ref_136" (make-vec (cardinality (get-field "params" (param 0))))
                    (let "lebsz_ref_137" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_136")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_137")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_137") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_137")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_137"))))))))
              (seq
                (let "repeat_n_139" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "params" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_139")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_138")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_138"))
                          (apply (ext-identifier program_run_parameter sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_139")) (get-field "params" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_139") (add (unsafe-nth (u8 0) (identifier "repeat_n_139")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_138")))))
          (add (identifier "sz_140")
            (add
              (let "n_ref_142" (make-vec (string-length (get-field "on_site" (param 0))))
                (let "lebsz_ref_143" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_142")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_143")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_143") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_143")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_143")))))) 
              (size-of-u32 (string-length (get-field "on_site" (param 0))))))) 
        (size 1)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::rc_entry::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::rc_entry::t> )> fun123 { [&fun123](std::shared_ptr<::dessser::gen::rc_entry::t>  p_0) {
    auto fun124 { dessser::gen::program_name::sersize_of_row_binary };
    dessser::gen::program_name::t_ext id_125 { (*p_0).program };
    Size id_126 { fun124(id_125) };
    Size id_127 { 1UL };
    Size id_128 { Size(id_126 + id_127) };
    Size id_129 { 1UL };
    Size id_130 { Size(id_128 + id_129) };
    Size id_131 { 8UL };
    Size id_132 { Size(id_130 + id_131) };
    Size let_res_133;
    {
      Size sz_134 { id_132 };
      auto fun134 { dessser::gen::file_path::sersize_of_row_binary };
      dessser::gen::file_path::t_ext id_135 { (*p_0).cwd };
      Size id_136 { fun134(id_135) };
      Size id_137 { Size(sz_134 + id_136) };
      let_res_133 = id_137;
    }
    Size let_res_138;
    {
      Size sz_135 { let_res_133 };
      Arr<dessser::gen::program_run_parameter::t_ext> id_139 { (*p_0).params };
      uint32_t id_140 { id_139.size() };
      Vec<1, uint32_t> id_141 {  id_140  };
      Size let_res_142;
      {
        Vec<1, uint32_t> n_ref_136 { id_141 };
        uint32_t id_143 { 1U };
        Vec<1, uint32_t> id_144 {  id_143  };
        Size let_res_145;
        {
          Vec<1, uint32_t> lebsz_ref_137 { id_144 };
          bool while_flag_146 { true };
          do {
            uint8_t id_147 { 0 };
            uint32_t id_148 { n_ref_136[id_147] };
            uint8_t id_149 { 0 };
            uint32_t id_150 { lebsz_ref_137[id_149] };
            uint8_t id_151 { 7 };
            uint32_t id_152 { uint32_t(id_150 << id_151) };
            bool id_153 { bool(id_148 >= id_152) };
            while_flag_146 = id_153;
            if (while_flag_146) {
              uint8_t id_154 { 0 };
              uint8_t id_155 { 0 };
              uint32_t id_156 { lebsz_ref_137[id_155] };
              uint32_t id_157 { 1U };
              uint32_t id_158 { uint32_t(id_156 + id_157) };
              Void id_159 { ((void)(lebsz_ref_137[id_154] = id_158), ::dessser::VOID) };
              (void)id_159;
            }
          } while (while_flag_146);
          (void)::dessser::VOID;
          uint8_t id_160 { 0 };
          uint32_t id_161 { lebsz_ref_137[id_160] };
          Size id_162 { Size(id_161) };
          let_res_145 = id_162;
        }
        let_res_142 = let_res_145;
      }
      Size id_163 { Size(sz_135 + let_res_142) };
      Vec<1, Size> id_164 {  id_163  };
      Size let_res_165;
      {
        Vec<1, Size> sz_ref_138 { id_164 };
        int32_t id_166 { 0L };
        Vec<1, int32_t> id_167 {  id_166  };
        {
          Vec<1, int32_t> repeat_n_139 { id_167 };
          bool while_flag_168 { true };
          do {
            Arr<dessser::gen::program_run_parameter::t_ext> id_169 { (*p_0).params };
            uint32_t id_170 { id_169.size() };
            int32_t id_171 { int32_t(id_170) };
            uint8_t id_172 { 0 };
            int32_t id_173 { repeat_n_139[id_172] };
            bool id_174 { bool(id_171 > id_173) };
            while_flag_168 = id_174;
            if (while_flag_168) {
              uint8_t id_175 { 0 };
              uint8_t id_176 { 0 };
              Size id_177 { sz_ref_138[id_176] };
              auto fun178 { dessser::gen::program_run_parameter::sersize_of_row_binary };
              uint8_t id_179 { 0 };
              int32_t id_180 { repeat_n_139[id_179] };
              Arr<dessser::gen::program_run_parameter::t_ext> id_181 { (*p_0).params };
              dessser::gen::program_run_parameter::t_ext id_182 { id_181[id_180] };
              Size id_183 { fun178(id_182) };
              Size id_184 { Size(id_177 + id_183) };
              Void id_185 { ((void)(sz_ref_138[id_175] = id_184), ::dessser::VOID) };
              (void)id_185;
              uint8_t id_186 { 0 };
              uint8_t id_187 { 0 };
              int32_t id_188 { repeat_n_139[id_187] };
              int32_t id_189 { 1L };
              int32_t id_190 { int32_t(id_188 + id_189) };
              Void id_191 { ((void)(repeat_n_139[id_186] = id_190), ::dessser::VOID) };
              (void)id_191;
              (void)id_191;
            }
          } while (while_flag_168);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_192 { 0 };
        Size id_193 { sz_ref_138[id_192] };
        let_res_165 = id_193;
      }
      let_res_138 = let_res_165;
    }
    Size let_res_194;
    {
      Size sz_140 { let_res_138 };
      std::string id_195 { (*p_0).on_site };
      uint32_t id_196 { (uint32_t)id_195.size() };
      Vec<1, uint32_t> id_197 {  id_196  };
      Size let_res_198;
      {
        Vec<1, uint32_t> n_ref_142 { id_197 };
        uint32_t id_199 { 1U };
        Vec<1, uint32_t> id_200 {  id_199  };
        Size let_res_201;
        {
          Vec<1, uint32_t> lebsz_ref_143 { id_200 };
          bool while_flag_202 { true };
          do {
            uint8_t id_203 { 0 };
            uint32_t id_204 { n_ref_142[id_203] };
            uint8_t id_205 { 0 };
            uint32_t id_206 { lebsz_ref_143[id_205] };
            uint8_t id_207 { 7 };
            uint32_t id_208 { uint32_t(id_206 << id_207) };
            bool id_209 { bool(id_204 >= id_208) };
            while_flag_202 = id_209;
            if (while_flag_202) {
              uint8_t id_210 { 0 };
              uint8_t id_211 { 0 };
              uint32_t id_212 { lebsz_ref_143[id_211] };
              uint32_t id_213 { 1U };
              uint32_t id_214 { uint32_t(id_212 + id_213) };
              Void id_215 { ((void)(lebsz_ref_143[id_210] = id_214), ::dessser::VOID) };
              (void)id_215;
            }
          } while (while_flag_202);
          (void)::dessser::VOID;
          uint8_t id_216 { 0 };
          uint32_t id_217 { lebsz_ref_143[id_216] };
          Size id_218 { Size(id_217) };
          let_res_201 = id_218;
        }
        let_res_198 = let_res_201;
      }
      std::string id_219 { (*p_0).on_site };
      uint32_t id_220 { (uint32_t)id_219.size() };
      Size id_221 { Size(id_220) };
      Size id_222 { Size(let_res_198 + id_221) };
      Size id_223 { Size(sz_140 + id_222) };
      let_res_194 = id_223;
    }
    Size id_224 { 1UL };
    Size id_225 { Size(let_res_194 + id_224) };
    return id_225;
  }
   };
  return fun123;
}
std::function<Size(std::shared_ptr<::dessser::gen::rc_entry::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier program_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_62" (let-pair "dbool_fst_60" "dbool_snd_61" (read-u8 (identifier "drec_snd_58")) (make-tup (not (eq (identifier "dbool_fst_60") (u8 0))) (identifier "dbool_snd_61")))
            (let-pair "drec_fst_63" "drec_snd_64" (identifier "drec_62")
              (let "drec_68" (let-pair "dbool_fst_66" "dbool_snd_67" (read-u8 (identifier "drec_snd_64")) (make-tup (not (eq (identifier "dbool_fst_66") (u8 0))) (identifier "dbool_snd_67")))
                (let-pair "drec_fst_69" "drec_snd_70" (identifier "drec_68")
                  (let "drec_74" (let-pair "dfloat_fst_72" "dfloat_snd_73" (read-u64 little-endian (identifier "drec_snd_70")) (make-tup (float-of-u64 (identifier "dfloat_fst_72")) (identifier "dfloat_snd_73")))
                    (let-pair "drec_fst_75" "drec_snd_76" (identifier "drec_74")
                      (let "drec_77" (apply (ext-identifier file_path of-row-binary) (identifier "drec_snd_76"))
                        (let-pair "drec_fst_78" "drec_snd_79" (identifier "drec_77")
                          (let "drec_103"
                            (let-pair "dlist4_fst_101" "dlist4_snd_102"
                              (let "dlist1_89"
                                (let "leb_ref_80" (make-vec (u32 0))
                                  (let "shft_ref_81" (make-vec (u8 0))
                                    (let "p_ref_82" (make-vec (identifier "drec_snd_79"))
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
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_80")) (unsafe-nth (u8 0) (identifier "p_ref_82")))))))
                                (let-pair "dlist1_fst_90" "dlist1_snd_91" 
                                  (identifier "dlist1_89")
                                  (let "inits_src_ref_92" (make-vec (make-tup (end-of-list "$program_run_parameter") (identifier "dlist1_snd_91")))
                                    (seq
                                      (let "repeat_n_93" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_90")) (unsafe-nth (u8 0) (identifier "repeat_n_93")))
                                          (seq
                                            (let "dlist2_94" (unsafe-nth (u8 0) (identifier "inits_src_ref_92"))
                                              (let-pair "dlist2_fst_95" "dlist2_snd_96" 
                                                (identifier "dlist2_94")
                                                (set-vec (u8 0) (identifier "inits_src_ref_92")
                                                  (let-pair "dlist3_fst_98" "dlist3_snd_99" 
                                                    (apply (ext-identifier program_run_parameter of-row-binary) (identifier "dlist2_snd_96"))
                                                    (make-tup (cons (identifier "dlist3_fst_98") (identifier "dlist2_fst_95")) (identifier "dlist3_snd_99"))))))
                                            (set-vec (u8 0) (identifier "repeat_n_93") (add (unsafe-nth (u8 0) (identifier "repeat_n_93")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_92")))))) 
                              (make-tup (arr-of-lst-rev (identifier "dlist4_fst_101")) (identifier "dlist4_snd_102")))
                            (let-pair "drec_fst_104" "drec_snd_105" (identifier "drec_103")
                              (let "drec_118"
                                (let "dstring1_112"
                                  (let "leb_ref_106" (make-vec (u32 0))
                                    (let "shft_ref_107" (make-vec (u8 0))
                                      (let "p_ref_108" (make-vec (identifier "drec_snd_105"))
                                        (seq
                                          (while
                                            (let "leb128_109" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_108")))
                                              (let-pair "leb128_fst_110" "leb128_snd_111" 
                                                (identifier "leb128_109")
                                                (seq (set-vec (u8 0) (identifier "p_ref_108") (identifier "leb128_snd_111"))
                                                  (set-vec (u8 0) (identifier "leb_ref_106")
                                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_110") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_107"))) (unsafe-nth (u8 0) (identifier "leb_ref_106"))))
                                                  (set-vec (u8 0) (identifier "shft_ref_107") (add (unsafe-nth (u8 0) (identifier "shft_ref_107")) (u8 7))) 
                                                  (ge (identifier "leb128_fst_110") (u8 128))))) 
                                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_106"))) (unsafe-nth (u8 0) (identifier "p_ref_108")))))))
                                  (let-pair "dstring1_fst_113" "dstring1_snd_114" 
                                    (identifier "dstring1_112")
                                    (let-pair "dstring2_fst_116" "dstring2_snd_117" 
                                      (read-bytes (identifier "dstring1_snd_114") (identifier "dstring1_fst_113")) 
                                      (make-tup (string-of-bytes (identifier "dstring2_fst_116")) (identifier "dstring2_snd_117")))))
                                (let-pair "drec_fst_119" "drec_snd_120" 
                                  (identifier "drec_118")
                                  (let-pair "dbool_fst_122" "dbool_snd_123" 
                                    (read-u8 (identifier "drec_snd_120"))
                                    (make-tup
                                      (make-rec (string "automatic") 
                                        (not (eq (identifier "dbool_fst_122") (u8 0))) 
                                        (string "on_site") (identifier "drec_fst_119") 
                                        (string "params") (identifier "drec_fst_104") 
                                        (string "cwd") (identifier "drec_fst_78") 
                                        (string "report_period") (identifier "drec_fst_75") 
                                        (string "debug") (identifier "drec_fst_69") 
                                        (string "enabled") (identifier "drec_fst_63") 
                                        (string "program") (identifier "drec_fst_57")) 
                                      (identifier "dbool_snd_123"))))))))))))))))))
 */
static std::function<::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3(Pointer)> fun226 { [&fun226](Pointer p_0) {
    auto fun227 { dessser::gen::program_name::of_row_binary };
    ::dessser::gen::rc_entry::td8645decacfa82d2239ee8ec2f67634c id_228 { fun227(p_0) };
    ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 let_res_229;
    {
      ::dessser::gen::rc_entry::td8645decacfa82d2239ee8ec2f67634c drec_56 { id_228 };
      ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 letpair_res_230;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        ::dessser::gen::rc_entry::t1a5d74abf838df33f185a72a8912f5c9 id_231 { drec_snd_58.readU8() };
        ::dessser::gen::rc_entry::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_232;
        {
          auto dbool_fst_60 { std::get<0>(id_231) };
          auto dbool_snd_61 { std::get<1>(id_231) };
          uint8_t id_233 { 0 };
          bool id_234 { bool(dbool_fst_60 == id_233) };
          bool id_235 { ! id_234 };
          ::dessser::gen::rc_entry::tf9a0a3fefc87c9e10a93d3a172850c26 id_236 { id_235, dbool_snd_61 };
          letpair_res_232 = id_236;
        }
        ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 let_res_237;
        {
          ::dessser::gen::rc_entry::tf9a0a3fefc87c9e10a93d3a172850c26 drec_62 { letpair_res_232 };
          ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 letpair_res_238;
          {
            auto drec_fst_63 { std::get<0>(drec_62) };
            auto drec_snd_64 { std::get<1>(drec_62) };
            ::dessser::gen::rc_entry::t1a5d74abf838df33f185a72a8912f5c9 id_239 { drec_snd_64.readU8() };
            ::dessser::gen::rc_entry::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_240;
            {
              auto dbool_fst_66 { std::get<0>(id_239) };
              auto dbool_snd_67 { std::get<1>(id_239) };
              uint8_t id_241 { 0 };
              bool id_242 { bool(dbool_fst_66 == id_241) };
              bool id_243 { ! id_242 };
              ::dessser::gen::rc_entry::tf9a0a3fefc87c9e10a93d3a172850c26 id_244 { id_243, dbool_snd_67 };
              letpair_res_240 = id_244;
            }
            ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 let_res_245;
            {
              ::dessser::gen::rc_entry::tf9a0a3fefc87c9e10a93d3a172850c26 drec_68 { letpair_res_240 };
              ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 letpair_res_246;
              {
                auto drec_fst_69 { std::get<0>(drec_68) };
                auto drec_snd_70 { std::get<1>(drec_68) };
                ::dessser::gen::rc_entry::td2cd337bb3c8bc04d5603393d084985b id_247 { drec_snd_70.readU64Le() };
                ::dessser::gen::rc_entry::t9a758baeff17224a77e1a522010b4168 letpair_res_248;
                {
                  auto dfloat_fst_72 { std::get<0>(id_247) };
                  auto dfloat_snd_73 { std::get<1>(id_247) };
                  double id_249 { float_of_qword(dfloat_fst_72) };
                  ::dessser::gen::rc_entry::t9a758baeff17224a77e1a522010b4168 id_250 { id_249, dfloat_snd_73 };
                  letpair_res_248 = id_250;
                }
                ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 let_res_251;
                {
                  ::dessser::gen::rc_entry::t9a758baeff17224a77e1a522010b4168 drec_74 { letpair_res_248 };
                  ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 letpair_res_252;
                  {
                    auto drec_fst_75 { std::get<0>(drec_74) };
                    auto drec_snd_76 { std::get<1>(drec_74) };
                    auto fun253 { dessser::gen::file_path::of_row_binary };
                    ::dessser::gen::rc_entry::td0a4a9551c4a7c5b58d84275e2a098f7 id_254 { fun253(drec_snd_76) };
                    ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 let_res_255;
                    {
                      ::dessser::gen::rc_entry::td0a4a9551c4a7c5b58d84275e2a098f7 drec_77 { id_254 };
                      ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 letpair_res_256;
                      {
                        auto drec_fst_78 { std::get<0>(drec_77) };
                        auto drec_snd_79 { std::get<1>(drec_77) };
                        uint32_t id_257 { 0U };
                        Vec<1, uint32_t> id_258 {  id_257  };
                        ::dessser::gen::rc_entry::t491c44439106a32f896827242e8e76a1 let_res_259;
                        {
                          Vec<1, uint32_t> leb_ref_80 { id_258 };
                          uint8_t id_260 { 0 };
                          Vec<1, uint8_t> id_261 {  id_260  };
                          ::dessser::gen::rc_entry::t491c44439106a32f896827242e8e76a1 let_res_262;
                          {
                            Vec<1, uint8_t> shft_ref_81 { id_261 };
                            Vec<1, Pointer> id_263 {  drec_snd_79  };
                            ::dessser::gen::rc_entry::t491c44439106a32f896827242e8e76a1 let_res_264;
                            {
                              Vec<1, Pointer> p_ref_82 { id_263 };
                              bool while_flag_265 { true };
                              do {
                                uint8_t id_266 { 0 };
                                Pointer id_267 { p_ref_82[id_266] };
                                ::dessser::gen::rc_entry::t1a5d74abf838df33f185a72a8912f5c9 id_268 { id_267.readU8() };
                                bool let_res_269;
                                {
                                  ::dessser::gen::rc_entry::t1a5d74abf838df33f185a72a8912f5c9 leb128_83 { id_268 };
                                  bool letpair_res_270;
                                  {
                                    auto leb128_fst_84 { std::get<0>(leb128_83) };
                                    auto leb128_snd_85 { std::get<1>(leb128_83) };
                                    uint8_t id_271 { 0 };
                                    Void id_272 { ((void)(p_ref_82[id_271] = leb128_snd_85), ::dessser::VOID) };
                                    (void)id_272;
                                    uint8_t id_273 { 0 };
                                    uint8_t id_274 { 127 };
                                    uint8_t id_275 { uint8_t(leb128_fst_84 & id_274) };
                                    uint32_t id_276 { uint32_t(id_275) };
                                    uint8_t id_277 { 0 };
                                    uint8_t id_278 { shft_ref_81[id_277] };
                                    uint32_t id_279 { uint32_t(id_276 << id_278) };
                                    uint8_t id_280 { 0 };
                                    uint32_t id_281 { leb_ref_80[id_280] };
                                    uint32_t id_282 { uint32_t(id_279 | id_281) };
                                    Void id_283 { ((void)(leb_ref_80[id_273] = id_282), ::dessser::VOID) };
                                    (void)id_283;
                                    uint8_t id_284 { 0 };
                                    uint8_t id_285 { 0 };
                                    uint8_t id_286 { shft_ref_81[id_285] };
                                    uint8_t id_287 { 7 };
                                    uint8_t id_288 { uint8_t(id_286 + id_287) };
                                    Void id_289 { ((void)(shft_ref_81[id_284] = id_288), ::dessser::VOID) };
                                    (void)id_289;
                                    uint8_t id_290 { 128 };
                                    bool id_291 { bool(leb128_fst_84 >= id_290) };
                                    letpair_res_270 = id_291;
                                  }
                                  let_res_269 = letpair_res_270;
                                }
                                while_flag_265 = let_res_269;
                                if (while_flag_265) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_265);
                              (void)::dessser::VOID;
                              uint8_t id_292 { 0 };
                              uint32_t id_293 { leb_ref_80[id_292] };
                              uint8_t id_294 { 0 };
                              Pointer id_295 { p_ref_82[id_294] };
                              ::dessser::gen::rc_entry::t491c44439106a32f896827242e8e76a1 id_296 { id_293, id_295 };
                              let_res_264 = id_296;
                            }
                            let_res_262 = let_res_264;
                          }
                          let_res_259 = let_res_262;
                        }
                        ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6 let_res_297;
                        {
                          ::dessser::gen::rc_entry::t491c44439106a32f896827242e8e76a1 dlist1_89 { let_res_259 };
                          ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6 letpair_res_298;
                          {
                            auto dlist1_fst_90 { std::get<0>(dlist1_89) };
                            auto dlist1_snd_91 { std::get<1>(dlist1_89) };
                            Lst<dessser::gen::program_run_parameter::t_ext> endoflist_299;
                            ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6 id_300 { endoflist_299, dlist1_snd_91 };
                            Vec<1, ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6> id_301 {  id_300  };
                            ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6 let_res_302;
                            {
                              Vec<1, ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6> inits_src_ref_92 { id_301 };
                              int32_t id_303 { 0L };
                              Vec<1, int32_t> id_304 {  id_303  };
                              {
                                Vec<1, int32_t> repeat_n_93 { id_304 };
                                bool while_flag_305 { true };
                                do {
                                  int32_t id_306 { int32_t(dlist1_fst_90) };
                                  uint8_t id_307 { 0 };
                                  int32_t id_308 { repeat_n_93[id_307] };
                                  bool id_309 { bool(id_306 > id_308) };
                                  while_flag_305 = id_309;
                                  if (while_flag_305) {
                                    uint8_t id_310 { 0 };
                                    ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6 id_311 { inits_src_ref_92[id_310] };
                                    {
                                      ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6 dlist2_94 { id_311 };
                                      {
                                        auto dlist2_fst_95 { std::get<0>(dlist2_94) };
                                        auto dlist2_snd_96 { std::get<1>(dlist2_94) };
                                        uint8_t id_312 { 0 };
                                        auto fun313 { dessser::gen::program_run_parameter::of_row_binary };
                                        ::dessser::gen::rc_entry::t3d7e4d9b51a9bc2481748f08f14d9374 id_314 { fun313(dlist2_snd_96) };
                                        ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6 letpair_res_315;
                                        {
                                          auto dlist3_fst_98 { std::get<0>(id_314) };
                                          auto dlist3_snd_99 { std::get<1>(id_314) };
                                          Lst<dessser::gen::program_run_parameter::t_ext> id_316 { dlist3_fst_98, dlist2_fst_95 };
                                          ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6 id_317 { id_316, dlist3_snd_99 };
                                          letpair_res_315 = id_317;
                                        }
                                        Void id_318 { ((void)(inits_src_ref_92[id_312] = letpair_res_315), ::dessser::VOID) };
                                        (void)id_318;
                                      }
                                      (void)::dessser::VOID;
                                    }
                                    (void)::dessser::VOID;
                                    uint8_t id_319 { 0 };
                                    uint8_t id_320 { 0 };
                                    int32_t id_321 { repeat_n_93[id_320] };
                                    int32_t id_322 { 1L };
                                    int32_t id_323 { int32_t(id_321 + id_322) };
                                    Void id_324 { ((void)(repeat_n_93[id_319] = id_323), ::dessser::VOID) };
                                    (void)id_324;
                                    (void)id_324;
                                  }
                                } while (while_flag_305);
                                (void)::dessser::VOID;
                              }
                              (void)::dessser::VOID;
                              uint8_t id_325 { 0 };
                              ::dessser::gen::rc_entry::taab67abdcc93367ee872580987df9cf6 id_326 { inits_src_ref_92[id_325] };
                              let_res_302 = id_326;
                            }
                            letpair_res_298 = let_res_302;
                          }
                          let_res_297 = letpair_res_298;
                        }
                        ::dessser::gen::rc_entry::t8deaa632b9b85a15bf9974356fd5ba15 letpair_res_327;
                        {
                          auto dlist4_fst_101 { std::get<0>(let_res_297) };
                          auto dlist4_snd_102 { std::get<1>(let_res_297) };
                          Arr<dessser::gen::program_run_parameter::t_ext> id_328 { dlist4_fst_101.toListRev() };
                          ::dessser::gen::rc_entry::t8deaa632b9b85a15bf9974356fd5ba15 id_329 { id_328, dlist4_snd_102 };
                          letpair_res_327 = id_329;
                        }
                        ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 let_res_330;
                        {
                          ::dessser::gen::rc_entry::t8deaa632b9b85a15bf9974356fd5ba15 drec_103 { letpair_res_327 };
                          ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 letpair_res_331;
                          {
                            auto drec_fst_104 { std::get<0>(drec_103) };
                            auto drec_snd_105 { std::get<1>(drec_103) };
                            uint32_t id_332 { 0U };
                            Vec<1, uint32_t> id_333 {  id_332  };
                            ::dessser::gen::rc_entry::t12fb9c475959b52bf7b17b155a955ffa let_res_334;
                            {
                              Vec<1, uint32_t> leb_ref_106 { id_333 };
                              uint8_t id_335 { 0 };
                              Vec<1, uint8_t> id_336 {  id_335  };
                              ::dessser::gen::rc_entry::t12fb9c475959b52bf7b17b155a955ffa let_res_337;
                              {
                                Vec<1, uint8_t> shft_ref_107 { id_336 };
                                Vec<1, Pointer> id_338 {  drec_snd_105  };
                                ::dessser::gen::rc_entry::t12fb9c475959b52bf7b17b155a955ffa let_res_339;
                                {
                                  Vec<1, Pointer> p_ref_108 { id_338 };
                                  bool while_flag_340 { true };
                                  do {
                                    uint8_t id_341 { 0 };
                                    Pointer id_342 { p_ref_108[id_341] };
                                    ::dessser::gen::rc_entry::t1a5d74abf838df33f185a72a8912f5c9 id_343 { id_342.readU8() };
                                    bool let_res_344;
                                    {
                                      ::dessser::gen::rc_entry::t1a5d74abf838df33f185a72a8912f5c9 leb128_109 { id_343 };
                                      bool letpair_res_345;
                                      {
                                        auto leb128_fst_110 { std::get<0>(leb128_109) };
                                        auto leb128_snd_111 { std::get<1>(leb128_109) };
                                        uint8_t id_346 { 0 };
                                        Void id_347 { ((void)(p_ref_108[id_346] = leb128_snd_111), ::dessser::VOID) };
                                        (void)id_347;
                                        uint8_t id_348 { 0 };
                                        uint8_t id_349 { 127 };
                                        uint8_t id_350 { uint8_t(leb128_fst_110 & id_349) };
                                        uint32_t id_351 { uint32_t(id_350) };
                                        uint8_t id_352 { 0 };
                                        uint8_t id_353 { shft_ref_107[id_352] };
                                        uint32_t id_354 { uint32_t(id_351 << id_353) };
                                        uint8_t id_355 { 0 };
                                        uint32_t id_356 { leb_ref_106[id_355] };
                                        uint32_t id_357 { uint32_t(id_354 | id_356) };
                                        Void id_358 { ((void)(leb_ref_106[id_348] = id_357), ::dessser::VOID) };
                                        (void)id_358;
                                        uint8_t id_359 { 0 };
                                        uint8_t id_360 { 0 };
                                        uint8_t id_361 { shft_ref_107[id_360] };
                                        uint8_t id_362 { 7 };
                                        uint8_t id_363 { uint8_t(id_361 + id_362) };
                                        Void id_364 { ((void)(shft_ref_107[id_359] = id_363), ::dessser::VOID) };
                                        (void)id_364;
                                        uint8_t id_365 { 128 };
                                        bool id_366 { bool(leb128_fst_110 >= id_365) };
                                        letpair_res_345 = id_366;
                                      }
                                      let_res_344 = letpair_res_345;
                                    }
                                    while_flag_340 = let_res_344;
                                    if (while_flag_340) {
                                      (void)::dessser::VOID;
                                    }
                                  } while (while_flag_340);
                                  (void)::dessser::VOID;
                                  uint8_t id_367 { 0 };
                                  uint32_t id_368 { leb_ref_106[id_367] };
                                  Size id_369 { Size(id_368) };
                                  uint8_t id_370 { 0 };
                                  Pointer id_371 { p_ref_108[id_370] };
                                  ::dessser::gen::rc_entry::t12fb9c475959b52bf7b17b155a955ffa id_372 { id_369, id_371 };
                                  let_res_339 = id_372;
                                }
                                let_res_337 = let_res_339;
                              }
                              let_res_334 = let_res_337;
                            }
                            ::dessser::gen::rc_entry::t13a07ee37ab40962540da8534858dc07 let_res_373;
                            {
                              ::dessser::gen::rc_entry::t12fb9c475959b52bf7b17b155a955ffa dstring1_112 { let_res_334 };
                              ::dessser::gen::rc_entry::t13a07ee37ab40962540da8534858dc07 letpair_res_374;
                              {
                                auto dstring1_fst_113 { std::get<0>(dstring1_112) };
                                auto dstring1_snd_114 { std::get<1>(dstring1_112) };
                                ::dessser::gen::rc_entry::t9ef6882174ae71a34a3c5ef6b29242fb id_375 { dstring1_snd_114.readBytes(dstring1_fst_113) };
                                ::dessser::gen::rc_entry::t13a07ee37ab40962540da8534858dc07 letpair_res_376;
                                {
                                  auto dstring2_fst_116 { std::get<0>(id_375) };
                                  auto dstring2_snd_117 { std::get<1>(id_375) };
                                  std::string id_377 { dstring2_fst_116.toString() };
                                  ::dessser::gen::rc_entry::t13a07ee37ab40962540da8534858dc07 id_378 { id_377, dstring2_snd_117 };
                                  letpair_res_376 = id_378;
                                }
                                letpair_res_374 = letpair_res_376;
                              }
                              let_res_373 = letpair_res_374;
                            }
                            ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 let_res_379;
                            {
                              ::dessser::gen::rc_entry::t13a07ee37ab40962540da8534858dc07 drec_118 { let_res_373 };
                              ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 letpair_res_380;
                              {
                                auto drec_fst_119 { std::get<0>(drec_118) };
                                auto drec_snd_120 { std::get<1>(drec_118) };
                                ::dessser::gen::rc_entry::t1a5d74abf838df33f185a72a8912f5c9 id_381 { drec_snd_120.readU8() };
                                ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 letpair_res_382;
                                {
                                  auto dbool_fst_122 { std::get<0>(id_381) };
                                  auto dbool_snd_123 { std::get<1>(id_381) };
                                  uint8_t id_383 { 0 };
                                  bool id_384 { bool(dbool_fst_122 == id_383) };
                                  bool id_385 { ! id_384 };
                                  std::shared_ptr<::dessser::gen::rc_entry::t>  id_386 { std::make_shared<::dessser::gen::rc_entry::t>(id_385, drec_fst_78, drec_fst_69, drec_fst_63, drec_fst_119, drec_fst_104, drec_fst_57, drec_fst_75) };
                                  ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 id_387 { id_386, dbool_snd_123 };
                                  letpair_res_382 = id_387;
                                }
                                letpair_res_380 = letpair_res_382;
                              }
                              let_res_379 = letpair_res_380;
                            }
                            letpair_res_331 = let_res_379;
                          }
                          let_res_330 = letpair_res_331;
                        }
                        letpair_res_256 = let_res_330;
                      }
                      let_res_255 = letpair_res_256;
                    }
                    letpair_res_252 = let_res_255;
                  }
                  let_res_251 = letpair_res_252;
                }
                letpair_res_246 = let_res_251;
              }
              let_res_245 = letpair_res_246;
            }
            letpair_res_238 = let_res_245;
          }
          let_res_237 = letpair_res_238;
        }
        letpair_res_230 = let_res_237;
      }
      let_res_229 = letpair_res_230;
    }
    return let_res_229;
  }
   };
  return fun226;
}
std::function<::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_128" "make_snd_129" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_128") (identifier "make_snd_129"))))
 */
static std::function<::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3(Pointer)> fun388 { [&fun388](Pointer p_0) {
    ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 id_389 { of_row_binary(p_0) };
    ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 letpair_res_390;
    {
      auto make_fst_128 { std::get<0>(id_389) };
      auto make_snd_129 { std::get<1>(id_389) };
      ::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3 id_391 { make_fst_128, make_snd_129 };
      letpair_res_390 = id_391;
    }
    return letpair_res_390;
  }
   };
  return fun388;
}
std::function<::dessser::gen::rc_entry::t3ac1055254e339c986a46055f673c8c3(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{program: $program_name; enabled: BOOL; debug: BOOL; report_period: FLOAT; cwd: $file_path; params: $program_run_parameter[]; on_site: STRING; automatic: BOOL}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::rc_entry::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::rc_entry::t> ,Pointer)> fun392 { [&fun392](std::shared_ptr<::dessser::gen::rc_entry::t>  p_0, Pointer p_1) {
    Pointer id_393 { to_row_binary(p_0, p_1) };
    return id_393;
  }
   };
  return fun392;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::rc_entry::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
