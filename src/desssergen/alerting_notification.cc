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
#include "desssergen/fq_name.h"
#include "desssergen/site_name.h"

namespace dessser::gen::alerting_notification {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t491302cf85c6148f165ecf960720a734 : public std::tuple<
  std::string,
  std::string
> {
  using tuple::tuple;
  t491302cf85c6148f165ecf960720a734(std::tuple<std::string, std::string> p)
    : std::tuple<std::string, std::string>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t491302cf85c6148f165ecf960720a734 const &a, t491302cf85c6148f165ecf960720a734 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t491302cf85c6148f165ecf960720a734 const &a, t491302cf85c6148f165ecf960720a734 const &b) {
  return !operator==(a, b);
}
struct t {
  double certainty;
  double debounce;
  std::optional<double> event_time;
  bool firing;
  std::string name;
  Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> parameters;
  double sent_time;
  dessser::gen::site_name::t_ext site;
  bool test;
  double timeout;
  dessser::gen::fq_name::t_ext worker;
  t(double certainty_, double debounce_, std::optional<double> event_time_, bool firing_, std::string name_, Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> parameters_, double sent_time_, dessser::gen::site_name::t_ext site_, bool test_, double timeout_, dessser::gen::fq_name::t_ext worker_) : certainty(certainty_), debounce(debounce_), event_time(event_time_), firing(firing_), name(name_), parameters(parameters_), sent_time(sent_time_), site(site_), test(test_), timeout(timeout_), worker(worker_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.certainty == b.certainty && a.debounce == b.debounce && ((a.event_time && b.event_time && a.event_time.value() == b.event_time.value()) || (!a.event_time && !b.event_time)) && a.firing == b.firing && a.name == b.name && a.parameters == b.parameters && a.sent_time == b.sent_time && ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site) && a.test == b.test && a.timeout == b.timeout && ::dessser::gen::fq_name::Deref(a.worker) == ::dessser::gen::fq_name::Deref(b.worker);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t7f2136c011f4f9749d693ec511eb7e45 : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_notification::t> ,
  Pointer
> {
  using tuple::tuple;
  t7f2136c011f4f9749d693ec511eb7e45(std::tuple<std::shared_ptr<::dessser::gen::alerting_notification::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_notification::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7f2136c011f4f9749d693ec511eb7e45 const &a, t7f2136c011f4f9749d693ec511eb7e45 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7f2136c011f4f9749d693ec511eb7e45 const &a, t7f2136c011f4f9749d693ec511eb7e45 const &b) {
  return !operator==(a, b);
}
struct t5fda3fa18a9129079240e343cc4c7827 : public std::tuple<
  dessser::gen::site_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t5fda3fa18a9129079240e343cc4c7827(std::tuple<dessser::gen::site_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::site_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5fda3fa18a9129079240e343cc4c7827 const &a, t5fda3fa18a9129079240e343cc4c7827 const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5fda3fa18a9129079240e343cc4c7827 const &a, t5fda3fa18a9129079240e343cc4c7827 const &b) {
  return !operator==(a, b);
}
struct t1067cf8ed87e4e016349f71797fb0661 : public std::tuple<
  dessser::gen::fq_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t1067cf8ed87e4e016349f71797fb0661(std::tuple<dessser::gen::fq_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1067cf8ed87e4e016349f71797fb0661 const &a, t1067cf8ed87e4e016349f71797fb0661 const &b) {
  return ::dessser::gen::fq_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1067cf8ed87e4e016349f71797fb0661 const &a, t1067cf8ed87e4e016349f71797fb0661 const &b) {
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
struct t55727524d16738c6d5fa67218480136d : public std::tuple<
  std::optional<double>,
  Pointer
> {
  using tuple::tuple;
  t55727524d16738c6d5fa67218480136d(std::tuple<std::optional<double>, Pointer> p)
    : std::tuple<std::optional<double>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t55727524d16738c6d5fa67218480136d const &a, t55727524d16738c6d5fa67218480136d const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t55727524d16738c6d5fa67218480136d const &a, t55727524d16738c6d5fa67218480136d const &b) {
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
struct t803487c926190acee3805196933ede29 : public std::tuple<
  Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734>,
  Pointer
> {
  using tuple::tuple;
  t803487c926190acee3805196933ede29(std::tuple<Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t803487c926190acee3805196933ede29 const &a, t803487c926190acee3805196933ede29 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t803487c926190acee3805196933ede29 const &a, t803487c926190acee3805196933ede29 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{site: $site_name; worker: $fq_name; test: BOOL; sent_time: FLOAT; event_time: FLOAT?; name: STRING; firing: BOOL; certainty: FLOAT; debounce: FLOAT; timeout: FLOAT; parameters: (STRING; STRING)[[]]}" "Ptr")
      (let "srec_dst_218"
        (let "srec_dst_217"
          (let "srec_dst_216"
            (let "srec_dst_215"
              (let "srec_dst_214"
                (let "srec_dst_211"
                  (let "srec_dst_210"
                    (let "srec_dst_209"
                      (let "srec_dst_208"
                        (let "srec_dst_207" (apply (ext-identifier site_name to-row-binary) (get-field "site" (param 0)) (param 1))
                          (apply (ext-identifier fq_name to-row-binary) (get-field "worker" (param 0)) (identifier "srec_dst_207"))) 
                        (write-u8 (identifier "srec_dst_208") (u8-of-bool (get-field "test" (param 0))))) 
                      (write-u64 little-endian (identifier "srec_dst_209") (u64-of-float (get-field "sent_time" (param 0)))))
                    (if (is-null (get-field "event_time" (param 0))) 
                      (write-u8 (identifier "srec_dst_210") (u8 1)) (write-u64 little-endian (write-u8 (identifier "srec_dst_210") (u8 0)) (u64-of-float (force (get-field "event_time" (param 0)))))))
                  (write-bytes
                    (let "leb128_sz_212" (make-vec (string-length (get-field "name" (param 0))))
                      (let "leb128_ptr_213" (make-vec (identifier "srec_dst_211"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_213")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_213"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_212"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_212"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_212"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_212") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_212")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_212")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_213"))))) 
                    (bytes-of-string (get-field "name" (param 0))))) 
                (write-u8 (identifier "srec_dst_214") (u8-of-bool (get-field "firing" (param 0))))) 
              (write-u64 little-endian (identifier "srec_dst_215") (u64-of-float (get-field "certainty" (param 0))))) 
            (write-u64 little-endian (identifier "srec_dst_216") (u64-of-float (get-field "debounce" (param 0))))) 
          (write-u64 little-endian (identifier "srec_dst_217") (u64-of-float (get-field "timeout" (param 0)))))
        (let "dst_ref_221"
          (make-vec
            (let "leb128_sz_219" (make-vec (cardinality (get-field "parameters" (param 0))))
              (let "leb128_ptr_220" (make-vec (identifier "srec_dst_218"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_220")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_220"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_219"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_219"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_219"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_219") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_219")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_219")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_220"))))))
          (let "n_ref_222" (make-vec (i32 0))
            (seq
              (for-each "x_223" (get-field "parameters" (param 0))
                (seq
                  (set-vec (u8 0) (identifier "dst_ref_221")
                    (let "stup_dst_227"
                      (let "stup_dst_224" (unsafe-nth (u8 0) (identifier "dst_ref_221"))
                        (write-bytes
                          (let "leb128_sz_225" (make-vec (string-length (get-item 0 (identifier "x_223"))))
                            (let "leb128_ptr_226" (make-vec (identifier "stup_dst_224"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_226")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_226"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_225"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_225"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_225"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_225") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_225")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_225")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_226"))))) 
                          (bytes-of-string (get-item 0 (identifier "x_223")))))
                      (write-bytes
                        (let "leb128_sz_228" (make-vec (string-length (get-item 1 (identifier "x_223"))))
                          (let "leb128_ptr_229" (make-vec (identifier "stup_dst_227"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_229")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_229"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_228"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_228"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_228"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_228") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_228")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_228")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_229"))))) 
                        (bytes-of-string (get-item 1 (identifier "x_223")))))) 
                  (set-vec (u8 0) (identifier "n_ref_222") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_222")))))) 
              (unsafe-nth (u8 0) (identifier "dst_ref_221")))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_notification::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_notification::t> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::alerting_notification::t>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::site_name::to_row_binary };
    dessser::gen::site_name::t_ext id_2 { (*p_0).site };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_207 { id_3 };
      auto fun5 { dessser::gen::fq_name::to_row_binary };
      dessser::gen::fq_name::t_ext id_6 { (*p_0).worker };
      Pointer id_7 { fun5(id_6, srec_dst_207) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_208 { let_res_4 };
      bool id_9 { (*p_0).test };
      uint8_t id_10 { uint8_t(id_9) };
      Pointer id_11 { srec_dst_208.writeU8(id_10) };
      let_res_8 = id_11;
    }
    Pointer let_res_12;
    {
      Pointer srec_dst_209 { let_res_8 };
      double id_13 { (*p_0).sent_time };
      uint64_t id_14 { qword_of_float(id_13) };
      Pointer id_15 { srec_dst_209.writeU64Le(id_14) };
      let_res_12 = id_15;
    }
    Pointer let_res_16;
    {
      Pointer srec_dst_210 { let_res_12 };
      std::optional<double> id_17 { (*p_0).event_time };
      bool id_18 { !(id_17.has_value ()) };
      Pointer choose_res_19;
      if (id_18) {
        uint8_t id_20 { 1 };
        Pointer id_21 { srec_dst_210.writeU8(id_20) };
        choose_res_19 = id_21;
      } else {
        uint8_t id_22 { 0 };
        Pointer id_23 { srec_dst_210.writeU8(id_22) };
        std::optional<double> id_24 { (*p_0).event_time };
        double id_25 { id_24.value() };
        uint64_t id_26 { qword_of_float(id_25) };
        Pointer id_27 { id_23.writeU64Le(id_26) };
        choose_res_19 = id_27;
      }
      let_res_16 = choose_res_19;
    }
    Pointer let_res_28;
    {
      Pointer srec_dst_211 { let_res_16 };
      std::string id_29 { (*p_0).name };
      uint32_t id_30 { (uint32_t)id_29.size() };
      Vec<1, uint32_t> id_31 {  id_30  };
      Pointer let_res_32;
      {
        Vec<1, uint32_t> leb128_sz_212 { id_31 };
        Vec<1, Pointer> id_33 {  srec_dst_211  };
        Pointer let_res_34;
        {
          Vec<1, Pointer> leb128_ptr_213 { id_33 };
          bool while_flag_35 { true };
          do {
            uint8_t id_36 { 0 };
            uint8_t id_37 { 0 };
            Pointer id_38 { leb128_ptr_213[id_37] };
            uint32_t id_39 { 128U };
            uint8_t id_40 { 0 };
            uint32_t id_41 { leb128_sz_212[id_40] };
            bool id_42 { bool(id_39 > id_41) };
            uint8_t choose_res_43;
            if (id_42) {
              uint8_t id_44 { 0 };
              uint32_t id_45 { leb128_sz_212[id_44] };
              uint8_t id_46 { uint8_t(id_45) };
              choose_res_43 = id_46;
            } else {
              uint8_t id_47 { 0 };
              uint32_t id_48 { leb128_sz_212[id_47] };
              uint8_t id_49 { uint8_t(id_48) };
              uint8_t id_50 { 128 };
              uint8_t id_51 { uint8_t(id_49 | id_50) };
              choose_res_43 = id_51;
            }
            Pointer id_52 { id_38.writeU8(choose_res_43) };
            Void id_53 { ((void)(leb128_ptr_213[id_36] = id_52), ::dessser::VOID) };
            (void)id_53;
            uint8_t id_54 { 0 };
            uint8_t id_55 { 0 };
            uint32_t id_56 { leb128_sz_212[id_55] };
            uint8_t id_57 { 7 };
            uint32_t id_58 { uint32_t(id_56 >> id_57) };
            Void id_59 { ((void)(leb128_sz_212[id_54] = id_58), ::dessser::VOID) };
            (void)id_59;
            uint8_t id_60 { 0 };
            uint32_t id_61 { leb128_sz_212[id_60] };
            uint32_t id_62 { 0U };
            bool id_63 { bool(id_61 > id_62) };
            while_flag_35 = id_63;
            if (while_flag_35) {
              (void)::dessser::VOID;
            }
          } while (while_flag_35);
          (void)::dessser::VOID;
          uint8_t id_64 { 0 };
          Pointer id_65 { leb128_ptr_213[id_64] };
          let_res_34 = id_65;
        }
        let_res_32 = let_res_34;
      }
      std::string id_66 { (*p_0).name };
      Bytes id_67 { id_66 };
      Pointer id_68 { let_res_32.writeBytes(id_67) };
      let_res_28 = id_68;
    }
    Pointer let_res_69;
    {
      Pointer srec_dst_214 { let_res_28 };
      bool id_70 { (*p_0).firing };
      uint8_t id_71 { uint8_t(id_70) };
      Pointer id_72 { srec_dst_214.writeU8(id_71) };
      let_res_69 = id_72;
    }
    Pointer let_res_73;
    {
      Pointer srec_dst_215 { let_res_69 };
      double id_74 { (*p_0).certainty };
      uint64_t id_75 { qword_of_float(id_74) };
      Pointer id_76 { srec_dst_215.writeU64Le(id_75) };
      let_res_73 = id_76;
    }
    Pointer let_res_77;
    {
      Pointer srec_dst_216 { let_res_73 };
      double id_78 { (*p_0).debounce };
      uint64_t id_79 { qword_of_float(id_78) };
      Pointer id_80 { srec_dst_216.writeU64Le(id_79) };
      let_res_77 = id_80;
    }
    Pointer let_res_81;
    {
      Pointer srec_dst_217 { let_res_77 };
      double id_82 { (*p_0).timeout };
      uint64_t id_83 { qword_of_float(id_82) };
      Pointer id_84 { srec_dst_217.writeU64Le(id_83) };
      let_res_81 = id_84;
    }
    Pointer let_res_85;
    {
      Pointer srec_dst_218 { let_res_81 };
      Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> id_86 { (*p_0).parameters };
      uint32_t id_87 { id_86.size() };
      Vec<1, uint32_t> id_88 {  id_87  };
      Pointer let_res_89;
      {
        Vec<1, uint32_t> leb128_sz_219 { id_88 };
        Vec<1, Pointer> id_90 {  srec_dst_218  };
        Pointer let_res_91;
        {
          Vec<1, Pointer> leb128_ptr_220 { id_90 };
          bool while_flag_92 { true };
          do {
            uint8_t id_93 { 0 };
            uint8_t id_94 { 0 };
            Pointer id_95 { leb128_ptr_220[id_94] };
            uint32_t id_96 { 128U };
            uint8_t id_97 { 0 };
            uint32_t id_98 { leb128_sz_219[id_97] };
            bool id_99 { bool(id_96 > id_98) };
            uint8_t choose_res_100;
            if (id_99) {
              uint8_t id_101 { 0 };
              uint32_t id_102 { leb128_sz_219[id_101] };
              uint8_t id_103 { uint8_t(id_102) };
              choose_res_100 = id_103;
            } else {
              uint8_t id_104 { 0 };
              uint32_t id_105 { leb128_sz_219[id_104] };
              uint8_t id_106 { uint8_t(id_105) };
              uint8_t id_107 { 128 };
              uint8_t id_108 { uint8_t(id_106 | id_107) };
              choose_res_100 = id_108;
            }
            Pointer id_109 { id_95.writeU8(choose_res_100) };
            Void id_110 { ((void)(leb128_ptr_220[id_93] = id_109), ::dessser::VOID) };
            (void)id_110;
            uint8_t id_111 { 0 };
            uint8_t id_112 { 0 };
            uint32_t id_113 { leb128_sz_219[id_112] };
            uint8_t id_114 { 7 };
            uint32_t id_115 { uint32_t(id_113 >> id_114) };
            Void id_116 { ((void)(leb128_sz_219[id_111] = id_115), ::dessser::VOID) };
            (void)id_116;
            uint8_t id_117 { 0 };
            uint32_t id_118 { leb128_sz_219[id_117] };
            uint32_t id_119 { 0U };
            bool id_120 { bool(id_118 > id_119) };
            while_flag_92 = id_120;
            if (while_flag_92) {
              (void)::dessser::VOID;
            }
          } while (while_flag_92);
          (void)::dessser::VOID;
          uint8_t id_121 { 0 };
          Pointer id_122 { leb128_ptr_220[id_121] };
          let_res_91 = id_122;
        }
        let_res_89 = let_res_91;
      }
      Vec<1, Pointer> id_123 {  let_res_89  };
      Pointer let_res_124;
      {
        Vec<1, Pointer> dst_ref_221 { id_123 };
        int32_t id_125 { 0L };
        Vec<1, int32_t> id_126 {  id_125  };
        Pointer let_res_127;
        {
          Vec<1, int32_t> n_ref_222 { id_126 };
          Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> id_128 { (*p_0).parameters };
          for (::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734 x_223 : id_128) {
            uint8_t id_129 { 0 };
            uint8_t id_130 { 0 };
            Pointer id_131 { dst_ref_221[id_130] };
            Pointer let_res_132;
            {
              Pointer stup_dst_224 { id_131 };
              std::string id_133 { std::get<0>(x_223) };
              uint32_t id_134 { (uint32_t)id_133.size() };
              Vec<1, uint32_t> id_135 {  id_134  };
              Pointer let_res_136;
              {
                Vec<1, uint32_t> leb128_sz_225 { id_135 };
                Vec<1, Pointer> id_137 {  stup_dst_224  };
                Pointer let_res_138;
                {
                  Vec<1, Pointer> leb128_ptr_226 { id_137 };
                  bool while_flag_139 { true };
                  do {
                    uint8_t id_140 { 0 };
                    uint8_t id_141 { 0 };
                    Pointer id_142 { leb128_ptr_226[id_141] };
                    uint32_t id_143 { 128U };
                    uint8_t id_144 { 0 };
                    uint32_t id_145 { leb128_sz_225[id_144] };
                    bool id_146 { bool(id_143 > id_145) };
                    uint8_t choose_res_147;
                    if (id_146) {
                      uint8_t id_148 { 0 };
                      uint32_t id_149 { leb128_sz_225[id_148] };
                      uint8_t id_150 { uint8_t(id_149) };
                      choose_res_147 = id_150;
                    } else {
                      uint8_t id_151 { 0 };
                      uint32_t id_152 { leb128_sz_225[id_151] };
                      uint8_t id_153 { uint8_t(id_152) };
                      uint8_t id_154 { 128 };
                      uint8_t id_155 { uint8_t(id_153 | id_154) };
                      choose_res_147 = id_155;
                    }
                    Pointer id_156 { id_142.writeU8(choose_res_147) };
                    Void id_157 { ((void)(leb128_ptr_226[id_140] = id_156), ::dessser::VOID) };
                    (void)id_157;
                    uint8_t id_158 { 0 };
                    uint8_t id_159 { 0 };
                    uint32_t id_160 { leb128_sz_225[id_159] };
                    uint8_t id_161 { 7 };
                    uint32_t id_162 { uint32_t(id_160 >> id_161) };
                    Void id_163 { ((void)(leb128_sz_225[id_158] = id_162), ::dessser::VOID) };
                    (void)id_163;
                    uint8_t id_164 { 0 };
                    uint32_t id_165 { leb128_sz_225[id_164] };
                    uint32_t id_166 { 0U };
                    bool id_167 { bool(id_165 > id_166) };
                    while_flag_139 = id_167;
                    if (while_flag_139) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_139);
                  (void)::dessser::VOID;
                  uint8_t id_168 { 0 };
                  Pointer id_169 { leb128_ptr_226[id_168] };
                  let_res_138 = id_169;
                }
                let_res_136 = let_res_138;
              }
              std::string id_170 { std::get<0>(x_223) };
              Bytes id_171 { id_170 };
              Pointer id_172 { let_res_136.writeBytes(id_171) };
              let_res_132 = id_172;
            }
            Pointer let_res_173;
            {
              Pointer stup_dst_227 { let_res_132 };
              std::string id_174 { std::get<1>(x_223) };
              uint32_t id_175 { (uint32_t)id_174.size() };
              Vec<1, uint32_t> id_176 {  id_175  };
              Pointer let_res_177;
              {
                Vec<1, uint32_t> leb128_sz_228 { id_176 };
                Vec<1, Pointer> id_178 {  stup_dst_227  };
                Pointer let_res_179;
                {
                  Vec<1, Pointer> leb128_ptr_229 { id_178 };
                  bool while_flag_180 { true };
                  do {
                    uint8_t id_181 { 0 };
                    uint8_t id_182 { 0 };
                    Pointer id_183 { leb128_ptr_229[id_182] };
                    uint32_t id_184 { 128U };
                    uint8_t id_185 { 0 };
                    uint32_t id_186 { leb128_sz_228[id_185] };
                    bool id_187 { bool(id_184 > id_186) };
                    uint8_t choose_res_188;
                    if (id_187) {
                      uint8_t id_189 { 0 };
                      uint32_t id_190 { leb128_sz_228[id_189] };
                      uint8_t id_191 { uint8_t(id_190) };
                      choose_res_188 = id_191;
                    } else {
                      uint8_t id_192 { 0 };
                      uint32_t id_193 { leb128_sz_228[id_192] };
                      uint8_t id_194 { uint8_t(id_193) };
                      uint8_t id_195 { 128 };
                      uint8_t id_196 { uint8_t(id_194 | id_195) };
                      choose_res_188 = id_196;
                    }
                    Pointer id_197 { id_183.writeU8(choose_res_188) };
                    Void id_198 { ((void)(leb128_ptr_229[id_181] = id_197), ::dessser::VOID) };
                    (void)id_198;
                    uint8_t id_199 { 0 };
                    uint8_t id_200 { 0 };
                    uint32_t id_201 { leb128_sz_228[id_200] };
                    uint8_t id_202 { 7 };
                    uint32_t id_203 { uint32_t(id_201 >> id_202) };
                    Void id_204 { ((void)(leb128_sz_228[id_199] = id_203), ::dessser::VOID) };
                    (void)id_204;
                    uint8_t id_205 { 0 };
                    uint32_t id_206 { leb128_sz_228[id_205] };
                    uint32_t id_207 { 0U };
                    bool id_208 { bool(id_206 > id_207) };
                    while_flag_180 = id_208;
                    if (while_flag_180) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_180);
                  (void)::dessser::VOID;
                  uint8_t id_209 { 0 };
                  Pointer id_210 { leb128_ptr_229[id_209] };
                  let_res_179 = id_210;
                }
                let_res_177 = let_res_179;
              }
              std::string id_211 { std::get<1>(x_223) };
              Bytes id_212 { id_211 };
              Pointer id_213 { let_res_177.writeBytes(id_212) };
              let_res_173 = id_213;
            }
            Void id_214 { ((void)(dst_ref_221[id_129] = let_res_173), ::dessser::VOID) };
            (void)id_214;
            uint8_t id_215 { 0 };
            int32_t id_216 { 1L };
            uint8_t id_217 { 0 };
            int32_t id_218 { n_ref_222[id_217] };
            int32_t id_219 { int32_t(id_216 + id_218) };
            Void id_220 { ((void)(n_ref_222[id_215] = id_219), ::dessser::VOID) };
            (void)id_220;
            (void)id_220;
          }
          (void)::dessser::VOID;
          uint8_t id_221 { 0 };
          Pointer id_222 { dst_ref_221[id_221] };
          let_res_127 = id_222;
        }
        let_res_124 = let_res_127;
      }
      let_res_85 = let_res_124;
    }
    return let_res_85;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_notification::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{site: $site_name; worker: $fq_name; test: BOOL; sent_time: FLOAT; event_time: FLOAT?; name: STRING; firing: BOOL; certainty: FLOAT; debounce: FLOAT; timeout: FLOAT; parameters: (STRING; STRING)[[]]}")
      (let "sz_194"
        (add
          (add
            (add
              (add
                (let "sz_186"
                  (let "sz_185"
                    (add
                      (add
                        (let "sz_182" (apply (ext-identifier site_name sersize-of-row-binary) (get-field "site" (param 0)))
                          (add (identifier "sz_182") (apply (ext-identifier fq_name sersize-of-row-binary) (get-field "worker" (param 0))))) 
                        (size 1)) (size 8)) (if (is-null (get-field "event_time" (param 0))) (add (identifier "sz_185") (size 1)) (add (add (identifier "sz_185") (size 8)) (size 1))))
                  (add (identifier "sz_186")
                    (add
                      (let "n_ref_188" (make-vec (string-length (get-field "name" (param 0))))
                        (let "lebsz_ref_189" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_188")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_189")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_189") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_189")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_189")))))) 
                      (size-of-u32 (string-length (get-field "name" (param 0))))))) 
                (size 1)) (size 8)) (size 8)) (size 8))
        (let "sz_ref_197"
          (make-vec
            (add (identifier "sz_194")
              (let "n_ref_195" (make-vec (cardinality (get-field "parameters" (param 0))))
                (let "lebsz_ref_196" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_195")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_196")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_196") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_196")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_196"))))))))
          (seq
            (let "repeat_n_198" (make-vec (i32 0))
              (while (gt (to-i32 (cardinality (get-field "parameters" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_198")))
                (seq
                  (set-vec (u8 0) (identifier "sz_ref_197")
                    (let "sz_203"
                      (let "sz_199" (unsafe-nth (u8 0) (identifier "sz_ref_197"))
                        (add (identifier "sz_199")
                          (let "wlen_200" (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_198")) (get-field "parameters" (param 0)))))
                            (add
                              (let "n_ref_201" (make-vec (identifier "wlen_200"))
                                (let "lebsz_ref_202" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_201")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_202")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_202") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_202")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_202")))))) 
                              (size-of-u32 (identifier "wlen_200"))))))
                      (add (identifier "sz_203")
                        (let "wlen_204" (string-length (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_198")) (get-field "parameters" (param 0)))))
                          (add
                            (let "n_ref_205" (make-vec (identifier "wlen_204"))
                              (let "lebsz_ref_206" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_205")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_206")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_206") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_206")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_206")))))) 
                            (size-of-u32 (identifier "wlen_204"))))))) 
                  (set-vec (u8 0) (identifier "repeat_n_198") (add (unsafe-nth (u8 0) (identifier "repeat_n_198")) (i32 1)))))) 
            (unsafe-nth (u8 0) (identifier "sz_ref_197"))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alerting_notification::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alerting_notification::t> )> fun223 { [&fun223](std::shared_ptr<::dessser::gen::alerting_notification::t>  p_0) {
    auto fun224 { dessser::gen::site_name::sersize_of_row_binary };
    dessser::gen::site_name::t_ext id_225 { (*p_0).site };
    Size id_226 { fun224(id_225) };
    Size let_res_227;
    {
      Size sz_182 { id_226 };
      auto fun228 { dessser::gen::fq_name::sersize_of_row_binary };
      dessser::gen::fq_name::t_ext id_229 { (*p_0).worker };
      Size id_230 { fun228(id_229) };
      Size id_231 { Size(sz_182 + id_230) };
      let_res_227 = id_231;
    }
    Size id_232 { 1UL };
    Size id_233 { Size(let_res_227 + id_232) };
    Size id_234 { 8UL };
    Size id_235 { Size(id_233 + id_234) };
    Size let_res_236;
    {
      Size sz_185 { id_235 };
      std::optional<double> id_237 { (*p_0).event_time };
      bool id_238 { !(id_237.has_value ()) };
      Size choose_res_239;
      if (id_238) {
        Size id_240 { 1UL };
        Size id_241 { Size(sz_185 + id_240) };
        choose_res_239 = id_241;
      } else {
        Size id_242 { 8UL };
        Size id_243 { Size(sz_185 + id_242) };
        Size id_244 { 1UL };
        Size id_245 { Size(id_243 + id_244) };
        choose_res_239 = id_245;
      }
      let_res_236 = choose_res_239;
    }
    Size let_res_246;
    {
      Size sz_186 { let_res_236 };
      std::string id_247 { (*p_0).name };
      uint32_t id_248 { (uint32_t)id_247.size() };
      Vec<1, uint32_t> id_249 {  id_248  };
      Size let_res_250;
      {
        Vec<1, uint32_t> n_ref_188 { id_249 };
        uint32_t id_251 { 1U };
        Vec<1, uint32_t> id_252 {  id_251  };
        Size let_res_253;
        {
          Vec<1, uint32_t> lebsz_ref_189 { id_252 };
          bool while_flag_254 { true };
          do {
            uint8_t id_255 { 0 };
            uint32_t id_256 { n_ref_188[id_255] };
            uint8_t id_257 { 0 };
            uint32_t id_258 { lebsz_ref_189[id_257] };
            uint8_t id_259 { 7 };
            uint32_t id_260 { uint32_t(id_258 << id_259) };
            bool id_261 { bool(id_256 >= id_260) };
            while_flag_254 = id_261;
            if (while_flag_254) {
              uint8_t id_262 { 0 };
              uint8_t id_263 { 0 };
              uint32_t id_264 { lebsz_ref_189[id_263] };
              uint32_t id_265 { 1U };
              uint32_t id_266 { uint32_t(id_264 + id_265) };
              Void id_267 { ((void)(lebsz_ref_189[id_262] = id_266), ::dessser::VOID) };
              (void)id_267;
            }
          } while (while_flag_254);
          (void)::dessser::VOID;
          uint8_t id_268 { 0 };
          uint32_t id_269 { lebsz_ref_189[id_268] };
          Size id_270 { Size(id_269) };
          let_res_253 = id_270;
        }
        let_res_250 = let_res_253;
      }
      std::string id_271 { (*p_0).name };
      uint32_t id_272 { (uint32_t)id_271.size() };
      Size id_273 { Size(id_272) };
      Size id_274 { Size(let_res_250 + id_273) };
      Size id_275 { Size(sz_186 + id_274) };
      let_res_246 = id_275;
    }
    Size id_276 { 1UL };
    Size id_277 { Size(let_res_246 + id_276) };
    Size id_278 { 8UL };
    Size id_279 { Size(id_277 + id_278) };
    Size id_280 { 8UL };
    Size id_281 { Size(id_279 + id_280) };
    Size id_282 { 8UL };
    Size id_283 { Size(id_281 + id_282) };
    Size let_res_284;
    {
      Size sz_194 { id_283 };
      Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> id_285 { (*p_0).parameters };
      uint32_t id_286 { id_285.size() };
      Vec<1, uint32_t> id_287 {  id_286  };
      Size let_res_288;
      {
        Vec<1, uint32_t> n_ref_195 { id_287 };
        uint32_t id_289 { 1U };
        Vec<1, uint32_t> id_290 {  id_289  };
        Size let_res_291;
        {
          Vec<1, uint32_t> lebsz_ref_196 { id_290 };
          bool while_flag_292 { true };
          do {
            uint8_t id_293 { 0 };
            uint32_t id_294 { n_ref_195[id_293] };
            uint8_t id_295 { 0 };
            uint32_t id_296 { lebsz_ref_196[id_295] };
            uint8_t id_297 { 7 };
            uint32_t id_298 { uint32_t(id_296 << id_297) };
            bool id_299 { bool(id_294 >= id_298) };
            while_flag_292 = id_299;
            if (while_flag_292) {
              uint8_t id_300 { 0 };
              uint8_t id_301 { 0 };
              uint32_t id_302 { lebsz_ref_196[id_301] };
              uint32_t id_303 { 1U };
              uint32_t id_304 { uint32_t(id_302 + id_303) };
              Void id_305 { ((void)(lebsz_ref_196[id_300] = id_304), ::dessser::VOID) };
              (void)id_305;
            }
          } while (while_flag_292);
          (void)::dessser::VOID;
          uint8_t id_306 { 0 };
          uint32_t id_307 { lebsz_ref_196[id_306] };
          Size id_308 { Size(id_307) };
          let_res_291 = id_308;
        }
        let_res_288 = let_res_291;
      }
      Size id_309 { Size(sz_194 + let_res_288) };
      Vec<1, Size> id_310 {  id_309  };
      Size let_res_311;
      {
        Vec<1, Size> sz_ref_197 { id_310 };
        int32_t id_312 { 0L };
        Vec<1, int32_t> id_313 {  id_312  };
        {
          Vec<1, int32_t> repeat_n_198 { id_313 };
          bool while_flag_314 { true };
          do {
            Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> id_315 { (*p_0).parameters };
            uint32_t id_316 { id_315.size() };
            int32_t id_317 { int32_t(id_316) };
            uint8_t id_318 { 0 };
            int32_t id_319 { repeat_n_198[id_318] };
            bool id_320 { bool(id_317 > id_319) };
            while_flag_314 = id_320;
            if (while_flag_314) {
              uint8_t id_321 { 0 };
              uint8_t id_322 { 0 };
              Size id_323 { sz_ref_197[id_322] };
              Size let_res_324;
              {
                Size sz_199 { id_323 };
                uint8_t id_325 { 0 };
                int32_t id_326 { repeat_n_198[id_325] };
                Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> id_327 { (*p_0).parameters };
                ::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734 id_328 { id_327[id_326] };
                std::string id_329 { std::get<0>(id_328) };
                uint32_t id_330 { (uint32_t)id_329.size() };
                Size let_res_331;
                {
                  uint32_t wlen_200 { id_330 };
                  Vec<1, uint32_t> id_332 {  wlen_200  };
                  Size let_res_333;
                  {
                    Vec<1, uint32_t> n_ref_201 { id_332 };
                    uint32_t id_334 { 1U };
                    Vec<1, uint32_t> id_335 {  id_334  };
                    Size let_res_336;
                    {
                      Vec<1, uint32_t> lebsz_ref_202 { id_335 };
                      bool while_flag_337 { true };
                      do {
                        uint8_t id_338 { 0 };
                        uint32_t id_339 { n_ref_201[id_338] };
                        uint8_t id_340 { 0 };
                        uint32_t id_341 { lebsz_ref_202[id_340] };
                        uint8_t id_342 { 7 };
                        uint32_t id_343 { uint32_t(id_341 << id_342) };
                        bool id_344 { bool(id_339 >= id_343) };
                        while_flag_337 = id_344;
                        if (while_flag_337) {
                          uint8_t id_345 { 0 };
                          uint8_t id_346 { 0 };
                          uint32_t id_347 { lebsz_ref_202[id_346] };
                          uint32_t id_348 { 1U };
                          uint32_t id_349 { uint32_t(id_347 + id_348) };
                          Void id_350 { ((void)(lebsz_ref_202[id_345] = id_349), ::dessser::VOID) };
                          (void)id_350;
                        }
                      } while (while_flag_337);
                      (void)::dessser::VOID;
                      uint8_t id_351 { 0 };
                      uint32_t id_352 { lebsz_ref_202[id_351] };
                      Size id_353 { Size(id_352) };
                      let_res_336 = id_353;
                    }
                    let_res_333 = let_res_336;
                  }
                  Size id_354 { Size(wlen_200) };
                  Size id_355 { Size(let_res_333 + id_354) };
                  let_res_331 = id_355;
                }
                Size id_356 { Size(sz_199 + let_res_331) };
                let_res_324 = id_356;
              }
              Size let_res_357;
              {
                Size sz_203 { let_res_324 };
                uint8_t id_358 { 0 };
                int32_t id_359 { repeat_n_198[id_358] };
                Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> id_360 { (*p_0).parameters };
                ::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734 id_361 { id_360[id_359] };
                std::string id_362 { std::get<1>(id_361) };
                uint32_t id_363 { (uint32_t)id_362.size() };
                Size let_res_364;
                {
                  uint32_t wlen_204 { id_363 };
                  Vec<1, uint32_t> id_365 {  wlen_204  };
                  Size let_res_366;
                  {
                    Vec<1, uint32_t> n_ref_205 { id_365 };
                    uint32_t id_367 { 1U };
                    Vec<1, uint32_t> id_368 {  id_367  };
                    Size let_res_369;
                    {
                      Vec<1, uint32_t> lebsz_ref_206 { id_368 };
                      bool while_flag_370 { true };
                      do {
                        uint8_t id_371 { 0 };
                        uint32_t id_372 { n_ref_205[id_371] };
                        uint8_t id_373 { 0 };
                        uint32_t id_374 { lebsz_ref_206[id_373] };
                        uint8_t id_375 { 7 };
                        uint32_t id_376 { uint32_t(id_374 << id_375) };
                        bool id_377 { bool(id_372 >= id_376) };
                        while_flag_370 = id_377;
                        if (while_flag_370) {
                          uint8_t id_378 { 0 };
                          uint8_t id_379 { 0 };
                          uint32_t id_380 { lebsz_ref_206[id_379] };
                          uint32_t id_381 { 1U };
                          uint32_t id_382 { uint32_t(id_380 + id_381) };
                          Void id_383 { ((void)(lebsz_ref_206[id_378] = id_382), ::dessser::VOID) };
                          (void)id_383;
                        }
                      } while (while_flag_370);
                      (void)::dessser::VOID;
                      uint8_t id_384 { 0 };
                      uint32_t id_385 { lebsz_ref_206[id_384] };
                      Size id_386 { Size(id_385) };
                      let_res_369 = id_386;
                    }
                    let_res_366 = let_res_369;
                  }
                  Size id_387 { Size(wlen_204) };
                  Size id_388 { Size(let_res_366 + id_387) };
                  let_res_364 = id_388;
                }
                Size id_389 { Size(sz_203 + let_res_364) };
                let_res_357 = id_389;
              }
              Void id_390 { ((void)(sz_ref_197[id_321] = let_res_357), ::dessser::VOID) };
              (void)id_390;
              uint8_t id_391 { 0 };
              uint8_t id_392 { 0 };
              int32_t id_393 { repeat_n_198[id_392] };
              int32_t id_394 { 1L };
              int32_t id_395 { int32_t(id_393 + id_394) };
              Void id_396 { ((void)(repeat_n_198[id_391] = id_395), ::dessser::VOID) };
              (void)id_396;
              (void)id_396;
            }
          } while (while_flag_314);
          (void)::dessser::VOID;
        }
        (void)::dessser::VOID;
        uint8_t id_397 { 0 };
        Size id_398 { sz_ref_197[id_397] };
        let_res_311 = id_398;
      }
      let_res_284 = let_res_311;
    }
    return let_res_284;
  }
   };
  return fun223;
}
std::function<Size(std::shared_ptr<::dessser::gen::alerting_notification::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier site_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_59" (apply (ext-identifier fq_name of-row-binary) (identifier "drec_snd_58"))
            (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
              (let "drec_65" (let-pair "dbool_fst_63" "dbool_snd_64" (read-u8 (identifier "drec_snd_61")) (make-tup (not (eq (identifier "dbool_fst_63") (u8 0))) (identifier "dbool_snd_64")))
                (let-pair "drec_fst_66" "drec_snd_67" (identifier "drec_65")
                  (let "drec_71" (let-pair "dfloat_fst_69" "dfloat_snd_70" (read-u64 little-endian (identifier "drec_snd_67")) (make-tup (float-of-u64 (identifier "dfloat_fst_69")) (identifier "dfloat_snd_70")))
                    (let-pair "drec_fst_72" "drec_snd_73" (identifier "drec_71")
                      (let "drec_80"
                        (if (eq (peek-u8 (identifier "drec_snd_73") (size 0)) (u8 1)) 
                          (make-tup (null "FLOAT") (ptr-add (identifier "drec_snd_73") (size 1)))
                          (let-pair "dfloat_fst_75" "dfloat_snd_76" (read-u64 little-endian (ptr-add (identifier "drec_snd_73") (size 1)))
                            (make-tup (not-null (float-of-u64 (identifier "dfloat_fst_75"))) (identifier "dfloat_snd_76"))))
                        (let-pair "drec_fst_81" "drec_snd_82" (identifier "drec_80")
                          (let "drec_95"
                            (let "dstring1_89"
                              (let "leb_ref_83" (make-vec (u32 0))
                                (let "shft_ref_84" (make-vec (u8 0))
                                  (let "p_ref_85" (make-vec (identifier "drec_snd_82"))
                                    (seq
                                      (while
                                        (let "leb128_86" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_85")))
                                          (let-pair "leb128_fst_87" "leb128_snd_88" 
                                            (identifier "leb128_86")
                                            (seq (set-vec (u8 0) (identifier "p_ref_85") (identifier "leb128_snd_88"))
                                              (set-vec (u8 0) (identifier "leb_ref_83")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_87") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_84"))) (unsafe-nth (u8 0) (identifier "leb_ref_83"))))
                                              (set-vec (u8 0) (identifier "shft_ref_84") (add (unsafe-nth (u8 0) (identifier "shft_ref_84")) (u8 7))) 
                                              (ge (identifier "leb128_fst_87") (u8 128))))) 
                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_83"))) (unsafe-nth (u8 0) (identifier "p_ref_85")))))))
                              (let-pair "dstring1_fst_90" "dstring1_snd_91" 
                                (identifier "dstring1_89")
                                (let-pair "dstring2_fst_93" "dstring2_snd_94" 
                                  (read-bytes (identifier "dstring1_snd_91") (identifier "dstring1_fst_90")) 
                                  (make-tup (string-of-bytes (identifier "dstring2_fst_93")) (identifier "dstring2_snd_94")))))
                            (let-pair "drec_fst_96" "drec_snd_97" (identifier "drec_95")
                              (let "drec_101" (let-pair "dbool_fst_99" "dbool_snd_100" (read-u8 (identifier "drec_snd_97")) (make-tup (not (eq (identifier "dbool_fst_99") (u8 0))) (identifier "dbool_snd_100")))
                                (let-pair "drec_fst_102" "drec_snd_103" 
                                  (identifier "drec_101")
                                  (let "drec_107"
                                    (let-pair "dfloat_fst_105" "dfloat_snd_106" (read-u64 little-endian (identifier "drec_snd_103")) (make-tup (float-of-u64 (identifier "dfloat_fst_105")) (identifier "dfloat_snd_106")))
                                    (let-pair "drec_fst_108" "drec_snd_109" 
                                      (identifier "drec_107")
                                      (let "drec_113"
                                        (let-pair "dfloat_fst_111" "dfloat_snd_112" (read-u64 little-endian (identifier "drec_snd_109")) (make-tup (float-of-u64 (identifier "dfloat_fst_111")) (identifier "dfloat_snd_112")))
                                        (let-pair "drec_fst_114" "drec_snd_115" 
                                          (identifier "drec_113")
                                          (let "drec_119"
                                            (let-pair "dfloat_fst_117" "dfloat_snd_118" (read-u64 little-endian (identifier "drec_snd_115")) (make-tup (float-of-u64 (identifier "dfloat_fst_117")) (identifier "dfloat_snd_118")))
                                            (let-pair "drec_fst_120" "drec_snd_121" 
                                              (identifier "drec_119")
                                              (let-pair "dlist4_fst_173" "dlist4_snd_174"
                                                (let "dlist1_131"
                                                  (let "leb_ref_122" 
                                                    (make-vec (u32 0))
                                                    (let "shft_ref_123" 
                                                      (make-vec (u8 0))
                                                      (let "p_ref_124" 
                                                        (make-vec (identifier "drec_snd_121"))
                                                        (seq
                                                          (while
                                                            (let "leb128_125" 
                                                              (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_124")))
                                                              (let-pair "leb128_fst_126" "leb128_snd_127" 
                                                                (identifier "leb128_125")
                                                                (seq 
                                                                  (set-vec (u8 0) (identifier "p_ref_124") (identifier "leb128_snd_127"))
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_122")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_126") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_123")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_122")))) 
                                                                  (set-vec (u8 0) (identifier "shft_ref_123") (add (unsafe-nth (u8 0) (identifier "shft_ref_123")) (u8 7))) 
                                                                  (ge (identifier "leb128_fst_126") (u8 128))))) 
                                                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_122")) (unsafe-nth (u8 0) (identifier "p_ref_124")))))))
                                                  (let-pair "dlist1_fst_132" "dlist1_snd_133" 
                                                    (identifier "dlist1_131")
                                                    (let "inits_src_ref_134" 
                                                      (make-vec (make-tup (end-of-list "(STRING; STRING)") (identifier "dlist1_snd_133")))
                                                      (seq
                                                        (let "repeat_n_135" 
                                                          (make-vec (i32 0))
                                                          (while (gt (to-i32 (identifier "dlist1_fst_132")) (unsafe-nth (u8 0) (identifier "repeat_n_135")))
                                                            (seq
                                                              (let "dlist2_136" 
                                                                (unsafe-nth (u8 0) (identifier "inits_src_ref_134"))
                                                                (let-pair "dlist2_fst_137" "dlist2_snd_138" 
                                                                  (identifier "dlist2_136")
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_134")
                                                                    (let "dtup_151"
                                                                    (let "dstring1_145"
                                                                    (let "leb_ref_139" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_140" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_141" 
                                                                    (make-vec (identifier "dlist2_snd_138"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_142" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_141")))
                                                                    (let-pair "leb128_fst_143" "leb128_snd_144" 
                                                                    (identifier "leb128_142")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_141") (identifier "leb128_snd_144"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_139")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_143") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_140")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_139")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_140") (add (unsafe-nth (u8 0) (identifier "shft_ref_140")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_143") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_139"))) (unsafe-nth (u8 0) (identifier "p_ref_141")))))))
                                                                    (let-pair "dstring1_fst_146" "dstring1_snd_147" 
                                                                    (identifier "dstring1_145")
                                                                    (let-pair "dstring2_fst_149" "dstring2_snd_150" 
                                                                    (read-bytes (identifier "dstring1_snd_147") (identifier "dstring1_fst_146"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_149")) (identifier "dstring2_snd_150")))))
                                                                    (let-pair "dtup_fst_152" "dtup_snd_153" 
                                                                    (identifier "dtup_151")
                                                                    (let "dstring1_160"
                                                                    (let "leb_ref_154" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_155" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_156" 
                                                                    (make-vec (identifier "dtup_snd_153"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_157" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_156")))
                                                                    (let-pair "leb128_fst_158" "leb128_snd_159" 
                                                                    (identifier "leb128_157")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_156") (identifier "leb128_snd_159"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_154")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_158") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_155")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_154")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_155") (add (unsafe-nth (u8 0) (identifier "shft_ref_155")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_158") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_154"))) (unsafe-nth (u8 0) (identifier "p_ref_156")))))))
                                                                    (let-pair "dstring1_fst_161" "dstring1_snd_162" 
                                                                    (identifier "dstring1_160")
                                                                    (let-pair "dstring2_fst_164" "dstring2_snd_165" 
                                                                    (read-bytes (identifier "dstring1_snd_162") (identifier "dstring1_fst_161"))
                                                                    (make-tup 
                                                                    (cons (make-tup (identifier "dtup_fst_152") (string-of-bytes (identifier "dstring2_fst_164"))) (identifier "dlist2_fst_137")) 
                                                                    (identifier "dstring2_snd_165")))))))))) 
                                                              (set-vec (u8 0) (identifier "repeat_n_135") (add (unsafe-nth (u8 0) (identifier "repeat_n_135")) (i32 1)))))) 
                                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_134"))))))
                                                (make-tup
                                                  (make-rec (string "parameters") 
                                                    (identity (identifier "dlist4_fst_173")) 
                                                    (string "timeout") 
                                                    (identifier "drec_fst_120") 
                                                    (string "debounce") 
                                                    (identifier "drec_fst_114") 
                                                    (string "certainty") 
                                                    (identifier "drec_fst_108") 
                                                    (string "firing") 
                                                    (identifier "drec_fst_102") 
                                                    (string "name") (identifier "drec_fst_96") 
                                                    (string "event_time") 
                                                    (identifier "drec_fst_81") 
                                                    (string "sent_time") 
                                                    (identifier "drec_fst_72") 
                                                    (string "test") (identifier "drec_fst_66") 
                                                    (string "worker") 
                                                    (identifier "drec_fst_60") 
                                                    (string "site") (identifier "drec_fst_57")) 
                                                  (identifier "dlist4_snd_174"))))))))))))))))))))))))
 */
static std::function<::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45(Pointer)> fun399 { [&fun399](Pointer p_0) {
    auto fun400 { dessser::gen::site_name::of_row_binary };
    ::dessser::gen::alerting_notification::t5fda3fa18a9129079240e343cc4c7827 id_401 { fun400(p_0) };
    ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_402;
    {
      ::dessser::gen::alerting_notification::t5fda3fa18a9129079240e343cc4c7827 drec_56 { id_401 };
      ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_403;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        auto fun404 { dessser::gen::fq_name::of_row_binary };
        ::dessser::gen::alerting_notification::t1067cf8ed87e4e016349f71797fb0661 id_405 { fun404(drec_snd_58) };
        ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_406;
        {
          ::dessser::gen::alerting_notification::t1067cf8ed87e4e016349f71797fb0661 drec_59 { id_405 };
          ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_407;
          {
            auto drec_fst_60 { std::get<0>(drec_59) };
            auto drec_snd_61 { std::get<1>(drec_59) };
            ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 id_408 { drec_snd_61.readU8() };
            ::dessser::gen::alerting_notification::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_409;
            {
              auto dbool_fst_63 { std::get<0>(id_408) };
              auto dbool_snd_64 { std::get<1>(id_408) };
              uint8_t id_410 { 0 };
              bool id_411 { bool(dbool_fst_63 == id_410) };
              bool id_412 { ! id_411 };
              ::dessser::gen::alerting_notification::tf9a0a3fefc87c9e10a93d3a172850c26 id_413 { id_412, dbool_snd_64 };
              letpair_res_409 = id_413;
            }
            ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_414;
            {
              ::dessser::gen::alerting_notification::tf9a0a3fefc87c9e10a93d3a172850c26 drec_65 { letpair_res_409 };
              ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_415;
              {
                auto drec_fst_66 { std::get<0>(drec_65) };
                auto drec_snd_67 { std::get<1>(drec_65) };
                ::dessser::gen::alerting_notification::td2cd337bb3c8bc04d5603393d084985b id_416 { drec_snd_67.readU64Le() };
                ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 letpair_res_417;
                {
                  auto dfloat_fst_69 { std::get<0>(id_416) };
                  auto dfloat_snd_70 { std::get<1>(id_416) };
                  double id_418 { float_of_qword(dfloat_fst_69) };
                  ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 id_419 { id_418, dfloat_snd_70 };
                  letpair_res_417 = id_419;
                }
                ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_420;
                {
                  ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 drec_71 { letpair_res_417 };
                  ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_421;
                  {
                    auto drec_fst_72 { std::get<0>(drec_71) };
                    auto drec_snd_73 { std::get<1>(drec_71) };
                    Size id_422 { 0UL };
                    uint8_t id_423 { drec_snd_73.peekU8(id_422) };
                    uint8_t id_424 { 1 };
                    bool id_425 { bool(id_423 == id_424) };
                    ::dessser::gen::alerting_notification::t55727524d16738c6d5fa67218480136d choose_res_426;
                    if (id_425) {
                      std::optional<double> id_427 { std::nullopt };
                      Size id_428 { 1UL };
                      Pointer id_429 { drec_snd_73.skip(id_428) };
                      ::dessser::gen::alerting_notification::t55727524d16738c6d5fa67218480136d id_430 { id_427, id_429 };
                      choose_res_426 = id_430;
                    } else {
                      Size id_431 { 1UL };
                      Pointer id_432 { drec_snd_73.skip(id_431) };
                      ::dessser::gen::alerting_notification::td2cd337bb3c8bc04d5603393d084985b id_433 { id_432.readU64Le() };
                      ::dessser::gen::alerting_notification::t55727524d16738c6d5fa67218480136d letpair_res_434;
                      {
                        auto dfloat_fst_75 { std::get<0>(id_433) };
                        auto dfloat_snd_76 { std::get<1>(id_433) };
                        double id_435 { float_of_qword(dfloat_fst_75) };
                        std::optional<double> id_436 { id_435 };
                        ::dessser::gen::alerting_notification::t55727524d16738c6d5fa67218480136d id_437 { id_436, dfloat_snd_76 };
                        letpair_res_434 = id_437;
                      }
                      choose_res_426 = letpair_res_434;
                    }
                    ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_438;
                    {
                      ::dessser::gen::alerting_notification::t55727524d16738c6d5fa67218480136d drec_80 { choose_res_426 };
                      ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_439;
                      {
                        auto drec_fst_81 { std::get<0>(drec_80) };
                        auto drec_snd_82 { std::get<1>(drec_80) };
                        uint32_t id_440 { 0U };
                        Vec<1, uint32_t> id_441 {  id_440  };
                        ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa let_res_442;
                        {
                          Vec<1, uint32_t> leb_ref_83 { id_441 };
                          uint8_t id_443 { 0 };
                          Vec<1, uint8_t> id_444 {  id_443  };
                          ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa let_res_445;
                          {
                            Vec<1, uint8_t> shft_ref_84 { id_444 };
                            Vec<1, Pointer> id_446 {  drec_snd_82  };
                            ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa let_res_447;
                            {
                              Vec<1, Pointer> p_ref_85 { id_446 };
                              bool while_flag_448 { true };
                              do {
                                uint8_t id_449 { 0 };
                                Pointer id_450 { p_ref_85[id_449] };
                                ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 id_451 { id_450.readU8() };
                                bool let_res_452;
                                {
                                  ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 leb128_86 { id_451 };
                                  bool letpair_res_453;
                                  {
                                    auto leb128_fst_87 { std::get<0>(leb128_86) };
                                    auto leb128_snd_88 { std::get<1>(leb128_86) };
                                    uint8_t id_454 { 0 };
                                    Void id_455 { ((void)(p_ref_85[id_454] = leb128_snd_88), ::dessser::VOID) };
                                    (void)id_455;
                                    uint8_t id_456 { 0 };
                                    uint8_t id_457 { 127 };
                                    uint8_t id_458 { uint8_t(leb128_fst_87 & id_457) };
                                    uint32_t id_459 { uint32_t(id_458) };
                                    uint8_t id_460 { 0 };
                                    uint8_t id_461 { shft_ref_84[id_460] };
                                    uint32_t id_462 { uint32_t(id_459 << id_461) };
                                    uint8_t id_463 { 0 };
                                    uint32_t id_464 { leb_ref_83[id_463] };
                                    uint32_t id_465 { uint32_t(id_462 | id_464) };
                                    Void id_466 { ((void)(leb_ref_83[id_456] = id_465), ::dessser::VOID) };
                                    (void)id_466;
                                    uint8_t id_467 { 0 };
                                    uint8_t id_468 { 0 };
                                    uint8_t id_469 { shft_ref_84[id_468] };
                                    uint8_t id_470 { 7 };
                                    uint8_t id_471 { uint8_t(id_469 + id_470) };
                                    Void id_472 { ((void)(shft_ref_84[id_467] = id_471), ::dessser::VOID) };
                                    (void)id_472;
                                    uint8_t id_473 { 128 };
                                    bool id_474 { bool(leb128_fst_87 >= id_473) };
                                    letpair_res_453 = id_474;
                                  }
                                  let_res_452 = letpair_res_453;
                                }
                                while_flag_448 = let_res_452;
                                if (while_flag_448) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_448);
                              (void)::dessser::VOID;
                              uint8_t id_475 { 0 };
                              uint32_t id_476 { leb_ref_83[id_475] };
                              Size id_477 { Size(id_476) };
                              uint8_t id_478 { 0 };
                              Pointer id_479 { p_ref_85[id_478] };
                              ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa id_480 { id_477, id_479 };
                              let_res_447 = id_480;
                            }
                            let_res_445 = let_res_447;
                          }
                          let_res_442 = let_res_445;
                        }
                        ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 let_res_481;
                        {
                          ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa dstring1_89 { let_res_442 };
                          ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 letpair_res_482;
                          {
                            auto dstring1_fst_90 { std::get<0>(dstring1_89) };
                            auto dstring1_snd_91 { std::get<1>(dstring1_89) };
                            ::dessser::gen::alerting_notification::t9ef6882174ae71a34a3c5ef6b29242fb id_483 { dstring1_snd_91.readBytes(dstring1_fst_90) };
                            ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 letpair_res_484;
                            {
                              auto dstring2_fst_93 { std::get<0>(id_483) };
                              auto dstring2_snd_94 { std::get<1>(id_483) };
                              std::string id_485 { dstring2_fst_93.toString() };
                              ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 id_486 { id_485, dstring2_snd_94 };
                              letpair_res_484 = id_486;
                            }
                            letpair_res_482 = letpair_res_484;
                          }
                          let_res_481 = letpair_res_482;
                        }
                        ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_487;
                        {
                          ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 drec_95 { let_res_481 };
                          ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_488;
                          {
                            auto drec_fst_96 { std::get<0>(drec_95) };
                            auto drec_snd_97 { std::get<1>(drec_95) };
                            ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 id_489 { drec_snd_97.readU8() };
                            ::dessser::gen::alerting_notification::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_490;
                            {
                              auto dbool_fst_99 { std::get<0>(id_489) };
                              auto dbool_snd_100 { std::get<1>(id_489) };
                              uint8_t id_491 { 0 };
                              bool id_492 { bool(dbool_fst_99 == id_491) };
                              bool id_493 { ! id_492 };
                              ::dessser::gen::alerting_notification::tf9a0a3fefc87c9e10a93d3a172850c26 id_494 { id_493, dbool_snd_100 };
                              letpair_res_490 = id_494;
                            }
                            ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_495;
                            {
                              ::dessser::gen::alerting_notification::tf9a0a3fefc87c9e10a93d3a172850c26 drec_101 { letpair_res_490 };
                              ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_496;
                              {
                                auto drec_fst_102 { std::get<0>(drec_101) };
                                auto drec_snd_103 { std::get<1>(drec_101) };
                                ::dessser::gen::alerting_notification::td2cd337bb3c8bc04d5603393d084985b id_497 { drec_snd_103.readU64Le() };
                                ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 letpair_res_498;
                                {
                                  auto dfloat_fst_105 { std::get<0>(id_497) };
                                  auto dfloat_snd_106 { std::get<1>(id_497) };
                                  double id_499 { float_of_qword(dfloat_fst_105) };
                                  ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 id_500 { id_499, dfloat_snd_106 };
                                  letpair_res_498 = id_500;
                                }
                                ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_501;
                                {
                                  ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 drec_107 { letpair_res_498 };
                                  ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_502;
                                  {
                                    auto drec_fst_108 { std::get<0>(drec_107) };
                                    auto drec_snd_109 { std::get<1>(drec_107) };
                                    ::dessser::gen::alerting_notification::td2cd337bb3c8bc04d5603393d084985b id_503 { drec_snd_109.readU64Le() };
                                    ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 letpair_res_504;
                                    {
                                      auto dfloat_fst_111 { std::get<0>(id_503) };
                                      auto dfloat_snd_112 { std::get<1>(id_503) };
                                      double id_505 { float_of_qword(dfloat_fst_111) };
                                      ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 id_506 { id_505, dfloat_snd_112 };
                                      letpair_res_504 = id_506;
                                    }
                                    ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_507;
                                    {
                                      ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 drec_113 { letpair_res_504 };
                                      ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_508;
                                      {
                                        auto drec_fst_114 { std::get<0>(drec_113) };
                                        auto drec_snd_115 { std::get<1>(drec_113) };
                                        ::dessser::gen::alerting_notification::td2cd337bb3c8bc04d5603393d084985b id_509 { drec_snd_115.readU64Le() };
                                        ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 letpair_res_510;
                                        {
                                          auto dfloat_fst_117 { std::get<0>(id_509) };
                                          auto dfloat_snd_118 { std::get<1>(id_509) };
                                          double id_511 { float_of_qword(dfloat_fst_117) };
                                          ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 id_512 { id_511, dfloat_snd_118 };
                                          letpair_res_510 = id_512;
                                        }
                                        ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 let_res_513;
                                        {
                                          ::dessser::gen::alerting_notification::t9a758baeff17224a77e1a522010b4168 drec_119 { letpair_res_510 };
                                          ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_514;
                                          {
                                            auto drec_fst_120 { std::get<0>(drec_119) };
                                            auto drec_snd_121 { std::get<1>(drec_119) };
                                            uint32_t id_515 { 0U };
                                            Vec<1, uint32_t> id_516 {  id_515  };
                                            ::dessser::gen::alerting_notification::t491c44439106a32f896827242e8e76a1 let_res_517;
                                            {
                                              Vec<1, uint32_t> leb_ref_122 { id_516 };
                                              uint8_t id_518 { 0 };
                                              Vec<1, uint8_t> id_519 {  id_518  };
                                              ::dessser::gen::alerting_notification::t491c44439106a32f896827242e8e76a1 let_res_520;
                                              {
                                                Vec<1, uint8_t> shft_ref_123 { id_519 };
                                                Vec<1, Pointer> id_521 {  drec_snd_121  };
                                                ::dessser::gen::alerting_notification::t491c44439106a32f896827242e8e76a1 let_res_522;
                                                {
                                                  Vec<1, Pointer> p_ref_124 { id_521 };
                                                  bool while_flag_523 { true };
                                                  do {
                                                    uint8_t id_524 { 0 };
                                                    Pointer id_525 { p_ref_124[id_524] };
                                                    ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 id_526 { id_525.readU8() };
                                                    bool let_res_527;
                                                    {
                                                      ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 leb128_125 { id_526 };
                                                      bool letpair_res_528;
                                                      {
                                                        auto leb128_fst_126 { std::get<0>(leb128_125) };
                                                        auto leb128_snd_127 { std::get<1>(leb128_125) };
                                                        uint8_t id_529 { 0 };
                                                        Void id_530 { ((void)(p_ref_124[id_529] = leb128_snd_127), ::dessser::VOID) };
                                                        (void)id_530;
                                                        uint8_t id_531 { 0 };
                                                        uint8_t id_532 { 127 };
                                                        uint8_t id_533 { uint8_t(leb128_fst_126 & id_532) };
                                                        uint32_t id_534 { uint32_t(id_533) };
                                                        uint8_t id_535 { 0 };
                                                        uint8_t id_536 { shft_ref_123[id_535] };
                                                        uint32_t id_537 { uint32_t(id_534 << id_536) };
                                                        uint8_t id_538 { 0 };
                                                        uint32_t id_539 { leb_ref_122[id_538] };
                                                        uint32_t id_540 { uint32_t(id_537 | id_539) };
                                                        Void id_541 { ((void)(leb_ref_122[id_531] = id_540), ::dessser::VOID) };
                                                        (void)id_541;
                                                        uint8_t id_542 { 0 };
                                                        uint8_t id_543 { 0 };
                                                        uint8_t id_544 { shft_ref_123[id_543] };
                                                        uint8_t id_545 { 7 };
                                                        uint8_t id_546 { uint8_t(id_544 + id_545) };
                                                        Void id_547 { ((void)(shft_ref_123[id_542] = id_546), ::dessser::VOID) };
                                                        (void)id_547;
                                                        uint8_t id_548 { 128 };
                                                        bool id_549 { bool(leb128_fst_126 >= id_548) };
                                                        letpair_res_528 = id_549;
                                                      }
                                                      let_res_527 = letpair_res_528;
                                                    }
                                                    while_flag_523 = let_res_527;
                                                    if (while_flag_523) {
                                                      (void)::dessser::VOID;
                                                    }
                                                  } while (while_flag_523);
                                                  (void)::dessser::VOID;
                                                  uint8_t id_550 { 0 };
                                                  uint32_t id_551 { leb_ref_122[id_550] };
                                                  uint8_t id_552 { 0 };
                                                  Pointer id_553 { p_ref_124[id_552] };
                                                  ::dessser::gen::alerting_notification::t491c44439106a32f896827242e8e76a1 id_554 { id_551, id_553 };
                                                  let_res_522 = id_554;
                                                }
                                                let_res_520 = let_res_522;
                                              }
                                              let_res_517 = let_res_520;
                                            }
                                            ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 let_res_555;
                                            {
                                              ::dessser::gen::alerting_notification::t491c44439106a32f896827242e8e76a1 dlist1_131 { let_res_517 };
                                              ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 letpair_res_556;
                                              {
                                                auto dlist1_fst_132 { std::get<0>(dlist1_131) };
                                                auto dlist1_snd_133 { std::get<1>(dlist1_131) };
                                                Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> endoflist_557;
                                                ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 id_558 { endoflist_557, dlist1_snd_133 };
                                                Vec<1, ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29> id_559 {  id_558  };
                                                ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 let_res_560;
                                                {
                                                  Vec<1, ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29> inits_src_ref_134 { id_559 };
                                                  int32_t id_561 { 0L };
                                                  Vec<1, int32_t> id_562 {  id_561  };
                                                  {
                                                    Vec<1, int32_t> repeat_n_135 { id_562 };
                                                    bool while_flag_563 { true };
                                                    do {
                                                      int32_t id_564 { int32_t(dlist1_fst_132) };
                                                      uint8_t id_565 { 0 };
                                                      int32_t id_566 { repeat_n_135[id_565] };
                                                      bool id_567 { bool(id_564 > id_566) };
                                                      while_flag_563 = id_567;
                                                      if (while_flag_563) {
                                                        uint8_t id_568 { 0 };
                                                        ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 id_569 { inits_src_ref_134[id_568] };
                                                        {
                                                          ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 dlist2_136 { id_569 };
                                                          {
                                                            auto dlist2_fst_137 { std::get<0>(dlist2_136) };
                                                            auto dlist2_snd_138 { std::get<1>(dlist2_136) };
                                                            uint8_t id_570 { 0 };
                                                            uint32_t id_571 { 0U };
                                                            Vec<1, uint32_t> id_572 {  id_571  };
                                                            ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa let_res_573;
                                                            {
                                                              Vec<1, uint32_t> leb_ref_139 { id_572 };
                                                              uint8_t id_574 { 0 };
                                                              Vec<1, uint8_t> id_575 {  id_574  };
                                                              ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa let_res_576;
                                                              {
                                                                Vec<1, uint8_t> shft_ref_140 { id_575 };
                                                                Vec<1, Pointer> id_577 {  dlist2_snd_138  };
                                                                ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa let_res_578;
                                                                {
                                                                  Vec<1, Pointer> p_ref_141 { id_577 };
                                                                  bool while_flag_579 { true };
                                                                  do {
                                                                    uint8_t id_580 { 0 };
                                                                    Pointer id_581 { p_ref_141[id_580] };
                                                                    ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 id_582 { id_581.readU8() };
                                                                    bool let_res_583;
                                                                    {
                                                                      ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 leb128_142 { id_582 };
                                                                      bool letpair_res_584;
                                                                      {
                                                                        auto leb128_fst_143 { std::get<0>(leb128_142) };
                                                                        auto leb128_snd_144 { std::get<1>(leb128_142) };
                                                                        uint8_t id_585 { 0 };
                                                                        Void id_586 { ((void)(p_ref_141[id_585] = leb128_snd_144), ::dessser::VOID) };
                                                                        (void)id_586;
                                                                        uint8_t id_587 { 0 };
                                                                        uint8_t id_588 { 127 };
                                                                        uint8_t id_589 { uint8_t(leb128_fst_143 & id_588) };
                                                                        uint32_t id_590 { uint32_t(id_589) };
                                                                        uint8_t id_591 { 0 };
                                                                        uint8_t id_592 { shft_ref_140[id_591] };
                                                                        uint32_t id_593 { uint32_t(id_590 << id_592) };
                                                                        uint8_t id_594 { 0 };
                                                                        uint32_t id_595 { leb_ref_139[id_594] };
                                                                        uint32_t id_596 { uint32_t(id_593 | id_595) };
                                                                        Void id_597 { ((void)(leb_ref_139[id_587] = id_596), ::dessser::VOID) };
                                                                        (void)id_597;
                                                                        uint8_t id_598 { 0 };
                                                                        uint8_t id_599 { 0 };
                                                                        uint8_t id_600 { shft_ref_140[id_599] };
                                                                        uint8_t id_601 { 7 };
                                                                        uint8_t id_602 { uint8_t(id_600 + id_601) };
                                                                        Void id_603 { ((void)(shft_ref_140[id_598] = id_602), ::dessser::VOID) };
                                                                        (void)id_603;
                                                                        uint8_t id_604 { 128 };
                                                                        bool id_605 { bool(leb128_fst_143 >= id_604) };
                                                                        letpair_res_584 = id_605;
                                                                      }
                                                                      let_res_583 = letpair_res_584;
                                                                    }
                                                                    while_flag_579 = let_res_583;
                                                                    if (while_flag_579) {
                                                                      (void)::dessser::VOID;
                                                                    }
                                                                  } while (while_flag_579);
                                                                  (void)::dessser::VOID;
                                                                  uint8_t id_606 { 0 };
                                                                  uint32_t id_607 { leb_ref_139[id_606] };
                                                                  Size id_608 { Size(id_607) };
                                                                  uint8_t id_609 { 0 };
                                                                  Pointer id_610 { p_ref_141[id_609] };
                                                                  ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa id_611 { id_608, id_610 };
                                                                  let_res_578 = id_611;
                                                                }
                                                                let_res_576 = let_res_578;
                                                              }
                                                              let_res_573 = let_res_576;
                                                            }
                                                            ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 let_res_612;
                                                            {
                                                              ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa dstring1_145 { let_res_573 };
                                                              ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 letpair_res_613;
                                                              {
                                                                auto dstring1_fst_146 { std::get<0>(dstring1_145) };
                                                                auto dstring1_snd_147 { std::get<1>(dstring1_145) };
                                                                ::dessser::gen::alerting_notification::t9ef6882174ae71a34a3c5ef6b29242fb id_614 { dstring1_snd_147.readBytes(dstring1_fst_146) };
                                                                ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 letpair_res_615;
                                                                {
                                                                  auto dstring2_fst_149 { std::get<0>(id_614) };
                                                                  auto dstring2_snd_150 { std::get<1>(id_614) };
                                                                  std::string id_616 { dstring2_fst_149.toString() };
                                                                  ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 id_617 { id_616, dstring2_snd_150 };
                                                                  letpair_res_615 = id_617;
                                                                }
                                                                letpair_res_613 = letpair_res_615;
                                                              }
                                                              let_res_612 = letpair_res_613;
                                                            }
                                                            ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 let_res_618;
                                                            {
                                                              ::dessser::gen::alerting_notification::t13a07ee37ab40962540da8534858dc07 dtup_151 { let_res_612 };
                                                              ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 letpair_res_619;
                                                              {
                                                                auto dtup_fst_152 { std::get<0>(dtup_151) };
                                                                auto dtup_snd_153 { std::get<1>(dtup_151) };
                                                                uint32_t id_620 { 0U };
                                                                Vec<1, uint32_t> id_621 {  id_620  };
                                                                ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa let_res_622;
                                                                {
                                                                  Vec<1, uint32_t> leb_ref_154 { id_621 };
                                                                  uint8_t id_623 { 0 };
                                                                  Vec<1, uint8_t> id_624 {  id_623  };
                                                                  ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa let_res_625;
                                                                  {
                                                                    Vec<1, uint8_t> shft_ref_155 { id_624 };
                                                                    Vec<1, Pointer> id_626 {  dtup_snd_153  };
                                                                    ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa let_res_627;
                                                                    {
                                                                      Vec<1, Pointer> p_ref_156 { id_626 };
                                                                      bool while_flag_628 { true };
                                                                      do {
                                                                        uint8_t id_629 { 0 };
                                                                        Pointer id_630 { p_ref_156[id_629] };
                                                                        ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 id_631 { id_630.readU8() };
                                                                        bool let_res_632;
                                                                        {
                                                                          ::dessser::gen::alerting_notification::t1a5d74abf838df33f185a72a8912f5c9 leb128_157 { id_631 };
                                                                          bool letpair_res_633;
                                                                          {
                                                                            auto leb128_fst_158 { std::get<0>(leb128_157) };
                                                                            auto leb128_snd_159 { std::get<1>(leb128_157) };
                                                                            uint8_t id_634 { 0 };
                                                                            Void id_635 { ((void)(p_ref_156[id_634] = leb128_snd_159), ::dessser::VOID) };
                                                                            (void)id_635;
                                                                            uint8_t id_636 { 0 };
                                                                            uint8_t id_637 { 127 };
                                                                            uint8_t id_638 { uint8_t(leb128_fst_158 & id_637) };
                                                                            uint32_t id_639 { uint32_t(id_638) };
                                                                            uint8_t id_640 { 0 };
                                                                            uint8_t id_641 { shft_ref_155[id_640] };
                                                                            uint32_t id_642 { uint32_t(id_639 << id_641) };
                                                                            uint8_t id_643 { 0 };
                                                                            uint32_t id_644 { leb_ref_154[id_643] };
                                                                            uint32_t id_645 { uint32_t(id_642 | id_644) };
                                                                            Void id_646 { ((void)(leb_ref_154[id_636] = id_645), ::dessser::VOID) };
                                                                            (void)id_646;
                                                                            uint8_t id_647 { 0 };
                                                                            uint8_t id_648 { 0 };
                                                                            uint8_t id_649 { shft_ref_155[id_648] };
                                                                            uint8_t id_650 { 7 };
                                                                            uint8_t id_651 { uint8_t(id_649 + id_650) };
                                                                            Void id_652 { ((void)(shft_ref_155[id_647] = id_651), ::dessser::VOID) };
                                                                            (void)id_652;
                                                                            uint8_t id_653 { 128 };
                                                                            bool id_654 { bool(leb128_fst_158 >= id_653) };
                                                                            letpair_res_633 = id_654;
                                                                          }
                                                                          let_res_632 = letpair_res_633;
                                                                        }
                                                                        while_flag_628 = let_res_632;
                                                                        if (while_flag_628) {
                                                                          (void)::dessser::VOID;
                                                                        }
                                                                      } while (while_flag_628);
                                                                      (void)::dessser::VOID;
                                                                      uint8_t id_655 { 0 };
                                                                      uint32_t id_656 { leb_ref_154[id_655] };
                                                                      Size id_657 { Size(id_656) };
                                                                      uint8_t id_658 { 0 };
                                                                      Pointer id_659 { p_ref_156[id_658] };
                                                                      ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa id_660 { id_657, id_659 };
                                                                      let_res_627 = id_660;
                                                                    }
                                                                    let_res_625 = let_res_627;
                                                                  }
                                                                  let_res_622 = let_res_625;
                                                                }
                                                                ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 let_res_661;
                                                                {
                                                                  ::dessser::gen::alerting_notification::t12fb9c475959b52bf7b17b155a955ffa dstring1_160 { let_res_622 };
                                                                  ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 letpair_res_662;
                                                                  {
                                                                    auto dstring1_fst_161 { std::get<0>(dstring1_160) };
                                                                    auto dstring1_snd_162 { std::get<1>(dstring1_160) };
                                                                    ::dessser::gen::alerting_notification::t9ef6882174ae71a34a3c5ef6b29242fb id_663 { dstring1_snd_162.readBytes(dstring1_fst_161) };
                                                                    ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 letpair_res_664;
                                                                    {
                                                                      auto dstring2_fst_164 { std::get<0>(id_663) };
                                                                      auto dstring2_snd_165 { std::get<1>(id_663) };
                                                                      std::string id_665 { dstring2_fst_164.toString() };
                                                                      ::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734 id_666 { dtup_fst_152, id_665 };
                                                                      Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> id_667 { id_666, dlist2_fst_137 };
                                                                      ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 id_668 { id_667, dstring2_snd_165 };
                                                                      letpair_res_664 = id_668;
                                                                    }
                                                                    letpair_res_662 = letpair_res_664;
                                                                  }
                                                                  let_res_661 = letpair_res_662;
                                                                }
                                                                letpair_res_619 = let_res_661;
                                                              }
                                                              let_res_618 = letpair_res_619;
                                                            }
                                                            Void id_669 { ((void)(inits_src_ref_134[id_570] = let_res_618), ::dessser::VOID) };
                                                            (void)id_669;
                                                          }
                                                          (void)::dessser::VOID;
                                                        }
                                                        (void)::dessser::VOID;
                                                        uint8_t id_670 { 0 };
                                                        uint8_t id_671 { 0 };
                                                        int32_t id_672 { repeat_n_135[id_671] };
                                                        int32_t id_673 { 1L };
                                                        int32_t id_674 { int32_t(id_672 + id_673) };
                                                        Void id_675 { ((void)(repeat_n_135[id_670] = id_674), ::dessser::VOID) };
                                                        (void)id_675;
                                                        (void)id_675;
                                                      }
                                                    } while (while_flag_563);
                                                    (void)::dessser::VOID;
                                                  }
                                                  (void)::dessser::VOID;
                                                  uint8_t id_676 { 0 };
                                                  ::dessser::gen::alerting_notification::t803487c926190acee3805196933ede29 id_677 { inits_src_ref_134[id_676] };
                                                  let_res_560 = id_677;
                                                }
                                                letpair_res_556 = let_res_560;
                                              }
                                              let_res_555 = letpair_res_556;
                                            }
                                            ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_678;
                                            {
                                              auto dlist4_fst_173 { std::get<0>(let_res_555) };
                                              auto dlist4_snd_174 { std::get<1>(let_res_555) };
                                              std::shared_ptr<::dessser::gen::alerting_notification::t>  id_679 { std::make_shared<::dessser::gen::alerting_notification::t>(drec_fst_108, drec_fst_114, drec_fst_81, drec_fst_102, drec_fst_96, dlist4_fst_173, drec_fst_72, drec_fst_57, drec_fst_66, drec_fst_120, drec_fst_60) };
                                              ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 id_680 { id_679, dlist4_snd_174 };
                                              letpair_res_678 = id_680;
                                            }
                                            letpair_res_514 = letpair_res_678;
                                          }
                                          let_res_513 = letpair_res_514;
                                        }
                                        letpair_res_508 = let_res_513;
                                      }
                                      let_res_507 = letpair_res_508;
                                    }
                                    letpair_res_502 = let_res_507;
                                  }
                                  let_res_501 = letpair_res_502;
                                }
                                letpair_res_496 = let_res_501;
                              }
                              let_res_495 = letpair_res_496;
                            }
                            letpair_res_488 = let_res_495;
                          }
                          let_res_487 = letpair_res_488;
                        }
                        letpair_res_439 = let_res_487;
                      }
                      let_res_438 = letpair_res_439;
                    }
                    letpair_res_421 = let_res_438;
                  }
                  let_res_420 = letpair_res_421;
                }
                letpair_res_415 = let_res_420;
              }
              let_res_414 = letpair_res_415;
            }
            letpair_res_407 = let_res_414;
          }
          let_res_406 = letpair_res_407;
        }
        letpair_res_403 = let_res_406;
      }
      let_res_402 = letpair_res_403;
    }
    return let_res_402;
  }
   };
  return fun399;
}
std::function<::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_179" "make_snd_180" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_179") (identifier "make_snd_180"))))
 */
static std::function<::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45(Pointer)> fun681 { [&fun681](Pointer p_0) {
    ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 id_682 { of_row_binary(p_0) };
    ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 letpair_res_683;
    {
      auto make_fst_179 { std::get<0>(id_682) };
      auto make_snd_180 { std::get<1>(id_682) };
      ::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45 id_684 { make_fst_179, make_snd_180 };
      letpair_res_683 = id_684;
    }
    return letpair_res_683;
  }
   };
  return fun681;
}
std::function<::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{site: $site_name; worker: $fq_name; test: BOOL; sent_time: FLOAT; event_time: FLOAT?; name: STRING; firing: BOOL; certainty: FLOAT; debounce: FLOAT; timeout: FLOAT; parameters: (STRING; STRING)[[]]}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_notification::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_notification::t> ,Pointer)> fun685 { [&fun685](std::shared_ptr<::dessser::gen::alerting_notification::t>  p_0, Pointer p_1) {
    Pointer id_686 { to_row_binary(p_0, p_1) };
    return id_686;
  }
   };
  return fun685;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_notification::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
