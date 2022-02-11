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
#include "desssergen/fq_function_name.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/sync_key.h"
#include "desssergen/file_path.h"
#include "desssergen/fq_function_name.h"

namespace dessser::gen::replay {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct te5110d98acb3927362000c58e13a1d40 : public std::tuple<
  dessser::gen::fq_function_name::t_ext,
  dessser::gen::fq_function_name::t_ext
> {
  using tuple::tuple;
};
inline bool operator==(te5110d98acb3927362000c58e13a1d40 const &a, te5110d98acb3927362000c58e13a1d40 const &b) {
  return ::dessser::gen::fq_function_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<0>(b)) && ::dessser::gen::fq_function_name::Deref(std::get<1>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<1>(b));
}
inline bool operator!=(te5110d98acb3927362000c58e13a1d40 const &a, te5110d98acb3927362000c58e13a1d40 const &b) {
  return !operator==(a, b);
}
struct td2e775685fdb218732b8145a467405fe : public std::variant<
  dessser::gen::file_path::t_ext, // RingBuf
  dessser::gen::sync_key::t_ext // SyncKey
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(td2e775685fdb218732b8145a467405fe const &a, td2e775685fdb218732b8145a467405fe const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)); // RingBuf
    case 1: return ::dessser::gen::sync_key::Deref(std::get<1>(a)) == ::dessser::gen::sync_key::Deref(std::get<1>(b)); // SyncKey
  };
  return false;
}
inline bool operator!=(td2e775685fdb218732b8145a467405fe const &a, td2e775685fdb218732b8145a467405fe const &b) {
  return !operator==(a, b);
}
struct t {
  uint16_t channel;
  dessser::gen::fq_function_name::t_ext target;
  std::string target_fieldmask;
  double since;
  double until;
  ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe recipient;
  Arr<dessser::gen::fq_function_name::t_ext> sources;
  Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> links;
  double timeout_date;
  t(uint16_t channel_, dessser::gen::fq_function_name::t_ext target_, std::string target_fieldmask_, double since_, double until_, ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe recipient_, Arr<dessser::gen::fq_function_name::t_ext> sources_, Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> links_, double timeout_date_) : channel(channel_), target(target_), target_fieldmask(target_fieldmask_), since(since_), until(until_), recipient(recipient_), sources(sources_), links(links_), timeout_date(timeout_date_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.channel == b.channel && ::dessser::gen::fq_function_name::Deref(a.target) == ::dessser::gen::fq_function_name::Deref(b.target) && a.target_fieldmask == b.target_fieldmask && a.since == b.since && a.until == b.until && a.recipient == b.recipient && a.sources == b.sources && a.links == b.links && a.timeout_date == b.timeout_date;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tc3ad1a607bcf0cc959516ffbd1438864 : public std::tuple<
  ::dessser::gen::replay::t,
  Pointer
> {
  using tuple::tuple;
  tc3ad1a607bcf0cc959516ffbd1438864(std::tuple<::dessser::gen::replay::t, Pointer> p)
    : std::tuple<::dessser::gen::replay::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc3ad1a607bcf0cc959516ffbd1438864 const &a, tc3ad1a607bcf0cc959516ffbd1438864 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc3ad1a607bcf0cc959516ffbd1438864 const &a, tc3ad1a607bcf0cc959516ffbd1438864 const &b) {
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
struct tafdf48d85e3efdf5b24e3fa2741562be : public std::tuple<
  dessser::gen::fq_function_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tafdf48d85e3efdf5b24e3fa2741562be(std::tuple<dessser::gen::fq_function_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_function_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tafdf48d85e3efdf5b24e3fa2741562be const &a, tafdf48d85e3efdf5b24e3fa2741562be const &b) {
  return ::dessser::gen::fq_function_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tafdf48d85e3efdf5b24e3fa2741562be const &a, tafdf48d85e3efdf5b24e3fa2741562be const &b) {
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
struct tf543a140d814d9a786a48bce0505c389 : public std::tuple<
  ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe,
  Pointer
> {
  using tuple::tuple;
  tf543a140d814d9a786a48bce0505c389(std::tuple<::dessser::gen::replay::td2e775685fdb218732b8145a467405fe, Pointer> p)
    : std::tuple<::dessser::gen::replay::td2e775685fdb218732b8145a467405fe, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf543a140d814d9a786a48bce0505c389 const &a, tf543a140d814d9a786a48bce0505c389 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf543a140d814d9a786a48bce0505c389 const &a, tf543a140d814d9a786a48bce0505c389 const &b) {
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
struct t0e7f6ba9e1ceef343afe44456f9067ec : public std::tuple<
  dessser::gen::sync_key::t_ext,
  Pointer
> {
  using tuple::tuple;
  t0e7f6ba9e1ceef343afe44456f9067ec(std::tuple<dessser::gen::sync_key::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_key::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0e7f6ba9e1ceef343afe44456f9067ec const &a, t0e7f6ba9e1ceef343afe44456f9067ec const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0e7f6ba9e1ceef343afe44456f9067ec const &a, t0e7f6ba9e1ceef343afe44456f9067ec const &b) {
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
struct t753363e387f81b7c224164f5dc43347f : public std::tuple<
  Lst<dessser::gen::fq_function_name::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t753363e387f81b7c224164f5dc43347f(std::tuple<Lst<dessser::gen::fq_function_name::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::fq_function_name::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t753363e387f81b7c224164f5dc43347f const &a, t753363e387f81b7c224164f5dc43347f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t753363e387f81b7c224164f5dc43347f const &a, t753363e387f81b7c224164f5dc43347f const &b) {
  return !operator==(a, b);
}
struct t7e337a83829e34e4f1a2127dcf8e964a : public std::tuple<
  Arr<dessser::gen::fq_function_name::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t7e337a83829e34e4f1a2127dcf8e964a(std::tuple<Arr<dessser::gen::fq_function_name::t_ext>, Pointer> p)
    : std::tuple<Arr<dessser::gen::fq_function_name::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7e337a83829e34e4f1a2127dcf8e964a const &a, t7e337a83829e34e4f1a2127dcf8e964a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7e337a83829e34e4f1a2127dcf8e964a const &a, t7e337a83829e34e4f1a2127dcf8e964a const &b) {
  return !operator==(a, b);
}
struct t423627277da8559e8b54a2ca90fab66d : public std::tuple<
  Lst<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40>,
  Pointer
> {
  using tuple::tuple;
  t423627277da8559e8b54a2ca90fab66d(std::tuple<Lst<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t423627277da8559e8b54a2ca90fab66d const &a, t423627277da8559e8b54a2ca90fab66d const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t423627277da8559e8b54a2ca90fab66d const &a, t423627277da8559e8b54a2ca90fab66d const &b) {
  return !operator==(a, b);
}
struct t28a2aa1152147e15b39aa4954f238c94 : public std::tuple<
  Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40>,
  Pointer
> {
  using tuple::tuple;
  t28a2aa1152147e15b39aa4954f238c94(std::tuple<Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40>, Pointer> p)
    : std::tuple<Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t28a2aa1152147e15b39aa4954f238c94 const &a, t28a2aa1152147e15b39aa4954f238c94 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t28a2aa1152147e15b39aa4954f238c94 const &a, t28a2aa1152147e15b39aa4954f238c94 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{channel: U16; target: $fq_function_name; target_fieldmask: STRING; since: FLOAT; until: FLOAT; recipient: [RingBuf $file_path | SyncKey $sync_key]; sources: $fq_function_name[]; links: ($fq_function_name; $fq_function_name)[]; timeout_date: FLOAT}" "Ptr")
      (let "srec_dst_224"
        (let "srec_dst_216"
          (let "srec_dst_210"
            (let "srec_dst_207"
              (let "srec_dst_206"
                (let "srec_dst_205"
                  (let "srec_dst_202"
                    (let "srec_dst_201" (write-u16 little-endian (param 1) (get-field "channel" (param 0))) (apply (ext-identifier fq_function_name to-row-binary) (get-field "target" (param 0)) (identifier "srec_dst_201")))
                    (write-bytes
                      (let "leb128_sz_203" (make-vec (string-length (get-field "target_fieldmask" (param 0))))
                        (let "leb128_ptr_204" (make-vec (identifier "srec_dst_202"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_204")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_204"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_203"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_203"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_203"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_203") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_203")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_203")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_204"))))) 
                      (bytes-of-string (get-field "target_fieldmask" (param 0))))) 
                  (write-u64 little-endian (identifier "srec_dst_205") (u64-of-float (get-field "since" (param 0))))) 
                (write-u64 little-endian (identifier "srec_dst_206") (u64-of-float (get-field "until" (param 0)))))
              (let "ssum_dst_209" (write-u16 little-endian (identifier "srec_dst_207") (label-of (get-field "recipient" (param 0))))
                (if (eq (u16 0) (label-of (get-field "recipient" (param 0)))) 
                  (apply (ext-identifier file_path to-row-binary) (get-alt "RingBuf" (get-field "recipient" (param 0))) (identifier "ssum_dst_209"))
                  (seq (assert (eq (label-of (get-field "recipient" (param 0))) (u16 1))) (apply (ext-identifier sync_key to-row-binary) (get-alt "SyncKey" (get-field "recipient" (param 0))) (identifier "ssum_dst_209"))))))
            (let "dst_ref_213"
              (make-vec
                (let "leb128_sz_211" (make-vec (cardinality (get-field "sources" (param 0))))
                  (let "leb128_ptr_212" (make-vec (identifier "srec_dst_210"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_212")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_212"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_211"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_211"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_211"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_211") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_211")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_211")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_212"))))))
              (let "n_ref_214" (make-vec (i32 0))
                (seq
                  (for-each "x_215" (get-field "sources" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_213") (apply (ext-identifier fq_function_name to-row-binary) (identifier "x_215") (unsafe-nth (u8 0) (identifier "dst_ref_213"))))
                      (set-vec (u8 0) (identifier "n_ref_214") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_214")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_213"))))))
          (let "dst_ref_219"
            (make-vec
              (let "leb128_sz_217" (make-vec (cardinality (get-field "links" (param 0))))
                (let "leb128_ptr_218" (make-vec (identifier "srec_dst_216"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_218")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_218"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_217"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_217"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_217"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_217") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_217")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_217")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_218"))))))
            (let "n_ref_220" (make-vec (i32 0))
              (seq
                (for-each "x_221" (get-field "links" (param 0))
                  (seq
                    (set-vec (u8 0) (identifier "dst_ref_219")
                      (let "stup_dst_223" (let "stup_dst_222" (unsafe-nth (u8 0) (identifier "dst_ref_219")) (apply (ext-identifier fq_function_name to-row-binary) (get-item 0 (identifier "x_221")) (identifier "stup_dst_222")))
                        (apply (ext-identifier fq_function_name to-row-binary) (get-item 1 (identifier "x_221")) (identifier "stup_dst_223"))))
                    (set-vec (u8 0) (identifier "n_ref_220") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_220")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_219")))))) (write-u64 little-endian (identifier "srec_dst_224") (u64-of-float (get-field "timeout_date" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::replay::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::replay::t &,Pointer &)> fun0 { [&](::dessser::gen::replay::t p_0, Pointer p_1) {
    uint16_t id_1 { p_0.channel };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_201 { id_2 };
      auto fun4 { dessser::gen::fq_function_name::to_row_binary };
      dessser::gen::fq_function_name::t_ext id_5 { p_0.target };
      Pointer id_6 { fun4(id_5, srec_dst_201) };
      let_res_3 = id_6;
    }
    Pointer let_res_7;
    {
      Pointer srec_dst_202 { let_res_3 };
      std::string id_8 { p_0.target_fieldmask };
      uint32_t id_9 { (uint32_t)id_8.size() };
      Vec<1, uint32_t> id_10 {  id_9  };
      Pointer let_res_11;
      {
        Vec<1, uint32_t> leb128_sz_203 { id_10 };
        Vec<1, Pointer> id_12 {  srec_dst_202  };
        Pointer let_res_13;
        {
          Vec<1, Pointer> leb128_ptr_204 { id_12 };
          bool while_flag_14 { true };
          do {
            uint8_t id_15 { 0 };
            uint8_t id_16 { 0 };
            Pointer id_17 { leb128_ptr_204[id_16] };
            uint32_t id_18 { 128U };
            uint8_t id_19 { 0 };
            uint32_t id_20 { leb128_sz_203[id_19] };
            bool id_21 { bool(id_18 > id_20) };
            uint8_t choose_res_22;
            if (id_21) {
              uint8_t id_23 { 0 };
              uint32_t id_24 { leb128_sz_203[id_23] };
              uint8_t id_25 { uint8_t(id_24) };
              choose_res_22 = id_25;
            } else {
              uint8_t id_26 { 0 };
              uint32_t id_27 { leb128_sz_203[id_26] };
              uint8_t id_28 { uint8_t(id_27) };
              uint8_t id_29 { 128 };
              uint8_t id_30 { uint8_t(id_28 | id_29) };
              choose_res_22 = id_30;
            }
            Pointer id_31 { id_17.writeU8(choose_res_22) };
            Void id_32 { ((void)(leb128_ptr_204[id_15] = id_31), ::dessser::Void()) };
            (void)id_32;
            uint8_t id_33 { 0 };
            uint8_t id_34 { 0 };
            uint32_t id_35 { leb128_sz_203[id_34] };
            uint8_t id_36 { 7 };
            uint32_t id_37 { uint32_t(id_35 >> id_36) };
            Void id_38 { ((void)(leb128_sz_203[id_33] = id_37), ::dessser::Void()) };
            (void)id_38;
            uint8_t id_39 { 0 };
            uint32_t id_40 { leb128_sz_203[id_39] };
            uint32_t id_41 { 0U };
            bool id_42 { bool(id_40 > id_41) };
            while_flag_14 = id_42;
            if (while_flag_14) {
              (void)::dessser::Void();
            }
          } while (while_flag_14);
          (void)::dessser::Void();
          uint8_t id_43 { 0 };
          Pointer id_44 { leb128_ptr_204[id_43] };
          let_res_13 = id_44;
        }
        let_res_11 = let_res_13;
      }
      std::string id_45 { p_0.target_fieldmask };
      Bytes id_46 { id_45 };
      Pointer id_47 { let_res_11.writeBytes(id_46) };
      let_res_7 = id_47;
    }
    Pointer let_res_48;
    {
      Pointer srec_dst_205 { let_res_7 };
      double id_49 { p_0.since };
      uint64_t id_50 { qword_of_float(id_49) };
      Pointer id_51 { srec_dst_205.writeU64Le(id_50) };
      let_res_48 = id_51;
    }
    Pointer let_res_52;
    {
      Pointer srec_dst_206 { let_res_48 };
      double id_53 { p_0.until };
      uint64_t id_54 { qword_of_float(id_53) };
      Pointer id_55 { srec_dst_206.writeU64Le(id_54) };
      let_res_52 = id_55;
    }
    Pointer let_res_56;
    {
      Pointer srec_dst_207 { let_res_52 };
      ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_57 { p_0.recipient };
      uint16_t id_58 { uint16_t(id_57.index()) };
      Pointer id_59 { srec_dst_207.writeU16Le(id_58) };
      Pointer let_res_60;
      {
        Pointer ssum_dst_209 { id_59 };
        uint16_t id_61 { 0 };
        ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_62 { p_0.recipient };
        uint16_t id_63 { uint16_t(id_62.index()) };
        bool id_64 { bool(id_61 == id_63) };
        Pointer choose_res_65;
        if (id_64) {
          auto fun66 { dessser::gen::file_path::to_row_binary };
          ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_67 { p_0.recipient };
          dessser::gen::file_path::t_ext id_68 { std::get<0 /* RingBuf */>(id_67) };
          Pointer id_69 { fun66(id_68, ssum_dst_209) };
          choose_res_65 = id_69;
        } else {
          ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_70 { p_0.recipient };
          uint16_t id_71 { uint16_t(id_70.index()) };
          uint16_t id_72 { 1 };
          bool id_73 { bool(id_71 == id_72) };
          Void id_74 { ((void)(assert(id_73)), ::dessser::Void()) };
          (void)id_74;
          auto fun75 { dessser::gen::sync_key::to_row_binary };
          ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_76 { p_0.recipient };
          dessser::gen::sync_key::t_ext id_77 { std::get<1 /* SyncKey */>(id_76) };
          Pointer id_78 { fun75(id_77, ssum_dst_209) };
          choose_res_65 = id_78;
        }
        let_res_60 = choose_res_65;
      }
      let_res_56 = let_res_60;
    }
    Pointer let_res_79;
    {
      Pointer srec_dst_210 { let_res_56 };
      Arr<dessser::gen::fq_function_name::t_ext> id_80 { p_0.sources };
      uint32_t id_81 { id_80.size() };
      Vec<1, uint32_t> id_82 {  id_81  };
      Pointer let_res_83;
      {
        Vec<1, uint32_t> leb128_sz_211 { id_82 };
        Vec<1, Pointer> id_84 {  srec_dst_210  };
        Pointer let_res_85;
        {
          Vec<1, Pointer> leb128_ptr_212 { id_84 };
          bool while_flag_86 { true };
          do {
            uint8_t id_87 { 0 };
            uint8_t id_88 { 0 };
            Pointer id_89 { leb128_ptr_212[id_88] };
            uint32_t id_90 { 128U };
            uint8_t id_91 { 0 };
            uint32_t id_92 { leb128_sz_211[id_91] };
            bool id_93 { bool(id_90 > id_92) };
            uint8_t choose_res_94;
            if (id_93) {
              uint8_t id_95 { 0 };
              uint32_t id_96 { leb128_sz_211[id_95] };
              uint8_t id_97 { uint8_t(id_96) };
              choose_res_94 = id_97;
            } else {
              uint8_t id_98 { 0 };
              uint32_t id_99 { leb128_sz_211[id_98] };
              uint8_t id_100 { uint8_t(id_99) };
              uint8_t id_101 { 128 };
              uint8_t id_102 { uint8_t(id_100 | id_101) };
              choose_res_94 = id_102;
            }
            Pointer id_103 { id_89.writeU8(choose_res_94) };
            Void id_104 { ((void)(leb128_ptr_212[id_87] = id_103), ::dessser::Void()) };
            (void)id_104;
            uint8_t id_105 { 0 };
            uint8_t id_106 { 0 };
            uint32_t id_107 { leb128_sz_211[id_106] };
            uint8_t id_108 { 7 };
            uint32_t id_109 { uint32_t(id_107 >> id_108) };
            Void id_110 { ((void)(leb128_sz_211[id_105] = id_109), ::dessser::Void()) };
            (void)id_110;
            uint8_t id_111 { 0 };
            uint32_t id_112 { leb128_sz_211[id_111] };
            uint32_t id_113 { 0U };
            bool id_114 { bool(id_112 > id_113) };
            while_flag_86 = id_114;
            if (while_flag_86) {
              (void)::dessser::Void();
            }
          } while (while_flag_86);
          (void)::dessser::Void();
          uint8_t id_115 { 0 };
          Pointer id_116 { leb128_ptr_212[id_115] };
          let_res_85 = id_116;
        }
        let_res_83 = let_res_85;
      }
      Vec<1, Pointer> id_117 {  let_res_83  };
      Pointer let_res_118;
      {
        Vec<1, Pointer> dst_ref_213 { id_117 };
        int32_t id_119 { 0L };
        Vec<1, int32_t> id_120 {  id_119  };
        Pointer let_res_121;
        {
          Vec<1, int32_t> n_ref_214 { id_120 };
          Arr<dessser::gen::fq_function_name::t_ext> id_122 { p_0.sources };
          for (dessser::gen::fq_function_name::t_ext &x_215 : id_122) {
            uint8_t id_123 { 0 };
            auto fun124 { dessser::gen::fq_function_name::to_row_binary };
            uint8_t id_125 { 0 };
            Pointer id_126 { dst_ref_213[id_125] };
            Pointer id_127 { fun124(x_215, id_126) };
            Void id_128 { ((void)(dst_ref_213[id_123] = id_127), ::dessser::Void()) };
            (void)id_128;
            uint8_t id_129 { 0 };
            int32_t id_130 { 1L };
            uint8_t id_131 { 0 };
            int32_t id_132 { n_ref_214[id_131] };
            int32_t id_133 { int32_t(id_130 + id_132) };
            Void id_134 { ((void)(n_ref_214[id_129] = id_133), ::dessser::Void()) };
            (void)id_134;
            (void)id_134;
          }
          (void)::dessser::Void();
          uint8_t id_135 { 0 };
          Pointer id_136 { dst_ref_213[id_135] };
          let_res_121 = id_136;
        }
        let_res_118 = let_res_121;
      }
      let_res_79 = let_res_118;
    }
    Pointer let_res_137;
    {
      Pointer srec_dst_216 { let_res_79 };
      Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> id_138 { p_0.links };
      uint32_t id_139 { id_138.size() };
      Vec<1, uint32_t> id_140 {  id_139  };
      Pointer let_res_141;
      {
        Vec<1, uint32_t> leb128_sz_217 { id_140 };
        Vec<1, Pointer> id_142 {  srec_dst_216  };
        Pointer let_res_143;
        {
          Vec<1, Pointer> leb128_ptr_218 { id_142 };
          bool while_flag_144 { true };
          do {
            uint8_t id_145 { 0 };
            uint8_t id_146 { 0 };
            Pointer id_147 { leb128_ptr_218[id_146] };
            uint32_t id_148 { 128U };
            uint8_t id_149 { 0 };
            uint32_t id_150 { leb128_sz_217[id_149] };
            bool id_151 { bool(id_148 > id_150) };
            uint8_t choose_res_152;
            if (id_151) {
              uint8_t id_153 { 0 };
              uint32_t id_154 { leb128_sz_217[id_153] };
              uint8_t id_155 { uint8_t(id_154) };
              choose_res_152 = id_155;
            } else {
              uint8_t id_156 { 0 };
              uint32_t id_157 { leb128_sz_217[id_156] };
              uint8_t id_158 { uint8_t(id_157) };
              uint8_t id_159 { 128 };
              uint8_t id_160 { uint8_t(id_158 | id_159) };
              choose_res_152 = id_160;
            }
            Pointer id_161 { id_147.writeU8(choose_res_152) };
            Void id_162 { ((void)(leb128_ptr_218[id_145] = id_161), ::dessser::Void()) };
            (void)id_162;
            uint8_t id_163 { 0 };
            uint8_t id_164 { 0 };
            uint32_t id_165 { leb128_sz_217[id_164] };
            uint8_t id_166 { 7 };
            uint32_t id_167 { uint32_t(id_165 >> id_166) };
            Void id_168 { ((void)(leb128_sz_217[id_163] = id_167), ::dessser::Void()) };
            (void)id_168;
            uint8_t id_169 { 0 };
            uint32_t id_170 { leb128_sz_217[id_169] };
            uint32_t id_171 { 0U };
            bool id_172 { bool(id_170 > id_171) };
            while_flag_144 = id_172;
            if (while_flag_144) {
              (void)::dessser::Void();
            }
          } while (while_flag_144);
          (void)::dessser::Void();
          uint8_t id_173 { 0 };
          Pointer id_174 { leb128_ptr_218[id_173] };
          let_res_143 = id_174;
        }
        let_res_141 = let_res_143;
      }
      Vec<1, Pointer> id_175 {  let_res_141  };
      Pointer let_res_176;
      {
        Vec<1, Pointer> dst_ref_219 { id_175 };
        int32_t id_177 { 0L };
        Vec<1, int32_t> id_178 {  id_177  };
        Pointer let_res_179;
        {
          Vec<1, int32_t> n_ref_220 { id_178 };
          Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> id_180 { p_0.links };
          for (::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40 &x_221 : id_180) {
            uint8_t id_181 { 0 };
            uint8_t id_182 { 0 };
            Pointer id_183 { dst_ref_219[id_182] };
            Pointer let_res_184;
            {
              Pointer stup_dst_222 { id_183 };
              auto fun185 { dessser::gen::fq_function_name::to_row_binary };
              dessser::gen::fq_function_name::t_ext id_186 { std::get<0>(x_221) };
              Pointer id_187 { fun185(id_186, stup_dst_222) };
              let_res_184 = id_187;
            }
            Pointer let_res_188;
            {
              Pointer stup_dst_223 { let_res_184 };
              auto fun189 { dessser::gen::fq_function_name::to_row_binary };
              dessser::gen::fq_function_name::t_ext id_190 { std::get<1>(x_221) };
              Pointer id_191 { fun189(id_190, stup_dst_223) };
              let_res_188 = id_191;
            }
            Void id_192 { ((void)(dst_ref_219[id_181] = let_res_188), ::dessser::Void()) };
            (void)id_192;
            uint8_t id_193 { 0 };
            int32_t id_194 { 1L };
            uint8_t id_195 { 0 };
            int32_t id_196 { n_ref_220[id_195] };
            int32_t id_197 { int32_t(id_194 + id_196) };
            Void id_198 { ((void)(n_ref_220[id_193] = id_197), ::dessser::Void()) };
            (void)id_198;
            (void)id_198;
          }
          (void)::dessser::Void();
          uint8_t id_199 { 0 };
          Pointer id_200 { dst_ref_219[id_199] };
          let_res_179 = id_200;
        }
        let_res_176 = let_res_179;
      }
      let_res_137 = let_res_176;
    }
    Pointer let_res_201;
    {
      Pointer srec_dst_224 { let_res_137 };
      double id_202 { p_0.timeout_date };
      uint64_t id_203 { qword_of_float(id_202) };
      Pointer id_204 { srec_dst_224.writeU64Le(id_203) };
      let_res_201 = id_204;
    }
    return let_res_201;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::replay::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{channel: U16; target: $fq_function_name; target_fieldmask: STRING; since: FLOAT; until: FLOAT; recipient: [RingBuf $file_path | SyncKey $sync_key]; sources: $fq_function_name[]; links: ($fq_function_name; $fq_function_name)[]; timeout_date: FLOAT}")
      (add
        (let "sz_193"
          (let "sz_188"
            (let "sz_186"
              (add
                (add
                  (let "sz_180" (add (size 2) (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-field "target" (param 0))))
                    (add (identifier "sz_180")
                      (add
                        (let "n_ref_182" (make-vec (string-length (get-field "target_fieldmask" (param 0))))
                          (let "lebsz_ref_183" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_182")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_183")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_183") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_183")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_183")))))) 
                        (size-of-u32 (string-length (get-field "target_fieldmask" (param 0))))))) 
                  (size 8)) (size 8))
              (if (eq (u16 0) (label-of (get-field "recipient" (param 0)))) 
                (add (add (identifier "sz_186") (size 2)) (apply (ext-identifier file_path sersize-of-row-binary) (get-alt "RingBuf" (get-field "recipient" (param 0)))))
                (seq (assert (eq (label-of (get-field "recipient" (param 0))) (u16 1)))
                  (add (add (identifier "sz_186") (size 2)) (apply (ext-identifier sync_key sersize-of-row-binary) (get-alt "SyncKey" (get-field "recipient" (param 0))))))))
            (let "sz_ref_191"
              (make-vec
                (add (identifier "sz_188")
                  (let "n_ref_189" (make-vec (cardinality (get-field "sources" (param 0))))
                    (let "lebsz_ref_190" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_189")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_190")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_190") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_190")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_190"))))))))
              (seq
                (let "repeat_n_192" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "sources" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_192")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_191")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_191"))
                          (apply (ext-identifier fq_function_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_192")) (get-field "sources" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_192") (add (unsafe-nth (u8 0) (identifier "repeat_n_192")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_191")))))
          (let "sz_ref_196"
            (make-vec
              (add (identifier "sz_193")
                (let "n_ref_194" (make-vec (cardinality (get-field "links" (param 0))))
                  (let "lebsz_ref_195" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_194")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_195")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_195") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_195")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_195"))))))))
            (seq
              (let "repeat_n_197" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "links" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_197")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_196")
                      (let "sz_199"
                        (let "sz_198" (unsafe-nth (u8 0) (identifier "sz_ref_196"))
                          (add (identifier "sz_198") (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_197")) (get-field "links" (param 0)))))))
                        (add (identifier "sz_199") (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_197")) (get-field "links" (param 0))))))))
                    (set-vec (u8 0) (identifier "repeat_n_197") (add (unsafe-nth (u8 0) (identifier "repeat_n_197")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_196"))))) (size 8)))
 */
static std::function<Size(::dessser::gen::replay::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::replay::t &)> fun205 { [&](::dessser::gen::replay::t p_0) {
    Size id_206 { 2UL };
    auto fun207 { dessser::gen::fq_function_name::sersize_of_row_binary };
    dessser::gen::fq_function_name::t_ext id_208 { p_0.target };
    Size id_209 { fun207(id_208) };
    Size id_210 { Size(id_206 + id_209) };
    Size let_res_211;
    {
      Size sz_180 { id_210 };
      std::string id_212 { p_0.target_fieldmask };
      uint32_t id_213 { (uint32_t)id_212.size() };
      Vec<1, uint32_t> id_214 {  id_213  };
      Size let_res_215;
      {
        Vec<1, uint32_t> n_ref_182 { id_214 };
        uint32_t id_216 { 1U };
        Vec<1, uint32_t> id_217 {  id_216  };
        Size let_res_218;
        {
          Vec<1, uint32_t> lebsz_ref_183 { id_217 };
          bool while_flag_219 { true };
          do {
            uint8_t id_220 { 0 };
            uint32_t id_221 { n_ref_182[id_220] };
            uint8_t id_222 { 0 };
            uint32_t id_223 { lebsz_ref_183[id_222] };
            uint8_t id_224 { 7 };
            uint32_t id_225 { uint32_t(id_223 << id_224) };
            bool id_226 { bool(id_221 >= id_225) };
            while_flag_219 = id_226;
            if (while_flag_219) {
              uint8_t id_227 { 0 };
              uint8_t id_228 { 0 };
              uint32_t id_229 { lebsz_ref_183[id_228] };
              uint32_t id_230 { 1U };
              uint32_t id_231 { uint32_t(id_229 + id_230) };
              Void id_232 { ((void)(lebsz_ref_183[id_227] = id_231), ::dessser::Void()) };
              (void)id_232;
            }
          } while (while_flag_219);
          (void)::dessser::Void();
          uint8_t id_233 { 0 };
          uint32_t id_234 { lebsz_ref_183[id_233] };
          Size id_235 { Size(id_234) };
          let_res_218 = id_235;
        }
        let_res_215 = let_res_218;
      }
      std::string id_236 { p_0.target_fieldmask };
      uint32_t id_237 { (uint32_t)id_236.size() };
      Size id_238 { Size(id_237) };
      Size id_239 { Size(let_res_215 + id_238) };
      Size id_240 { Size(sz_180 + id_239) };
      let_res_211 = id_240;
    }
    Size id_241 { 8UL };
    Size id_242 { Size(let_res_211 + id_241) };
    Size id_243 { 8UL };
    Size id_244 { Size(id_242 + id_243) };
    Size let_res_245;
    {
      Size sz_186 { id_244 };
      uint16_t id_246 { 0 };
      ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_247 { p_0.recipient };
      uint16_t id_248 { uint16_t(id_247.index()) };
      bool id_249 { bool(id_246 == id_248) };
      Size choose_res_250;
      if (id_249) {
        Size id_251 { 2UL };
        Size id_252 { Size(sz_186 + id_251) };
        auto fun253 { dessser::gen::file_path::sersize_of_row_binary };
        ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_254 { p_0.recipient };
        dessser::gen::file_path::t_ext id_255 { std::get<0 /* RingBuf */>(id_254) };
        Size id_256 { fun253(id_255) };
        Size id_257 { Size(id_252 + id_256) };
        choose_res_250 = id_257;
      } else {
        ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_258 { p_0.recipient };
        uint16_t id_259 { uint16_t(id_258.index()) };
        uint16_t id_260 { 1 };
        bool id_261 { bool(id_259 == id_260) };
        Void id_262 { ((void)(assert(id_261)), ::dessser::Void()) };
        (void)id_262;
        Size id_263 { 2UL };
        Size id_264 { Size(sz_186 + id_263) };
        auto fun265 { dessser::gen::sync_key::sersize_of_row_binary };
        ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_266 { p_0.recipient };
        dessser::gen::sync_key::t_ext id_267 { std::get<1 /* SyncKey */>(id_266) };
        Size id_268 { fun265(id_267) };
        Size id_269 { Size(id_264 + id_268) };
        choose_res_250 = id_269;
      }
      let_res_245 = choose_res_250;
    }
    Size let_res_270;
    {
      Size sz_188 { let_res_245 };
      Arr<dessser::gen::fq_function_name::t_ext> id_271 { p_0.sources };
      uint32_t id_272 { id_271.size() };
      Vec<1, uint32_t> id_273 {  id_272  };
      Size let_res_274;
      {
        Vec<1, uint32_t> n_ref_189 { id_273 };
        uint32_t id_275 { 1U };
        Vec<1, uint32_t> id_276 {  id_275  };
        Size let_res_277;
        {
          Vec<1, uint32_t> lebsz_ref_190 { id_276 };
          bool while_flag_278 { true };
          do {
            uint8_t id_279 { 0 };
            uint32_t id_280 { n_ref_189[id_279] };
            uint8_t id_281 { 0 };
            uint32_t id_282 { lebsz_ref_190[id_281] };
            uint8_t id_283 { 7 };
            uint32_t id_284 { uint32_t(id_282 << id_283) };
            bool id_285 { bool(id_280 >= id_284) };
            while_flag_278 = id_285;
            if (while_flag_278) {
              uint8_t id_286 { 0 };
              uint8_t id_287 { 0 };
              uint32_t id_288 { lebsz_ref_190[id_287] };
              uint32_t id_289 { 1U };
              uint32_t id_290 { uint32_t(id_288 + id_289) };
              Void id_291 { ((void)(lebsz_ref_190[id_286] = id_290), ::dessser::Void()) };
              (void)id_291;
            }
          } while (while_flag_278);
          (void)::dessser::Void();
          uint8_t id_292 { 0 };
          uint32_t id_293 { lebsz_ref_190[id_292] };
          Size id_294 { Size(id_293) };
          let_res_277 = id_294;
        }
        let_res_274 = let_res_277;
      }
      Size id_295 { Size(sz_188 + let_res_274) };
      Vec<1, Size> id_296 {  id_295  };
      Size let_res_297;
      {
        Vec<1, Size> sz_ref_191 { id_296 };
        int32_t id_298 { 0L };
        Vec<1, int32_t> id_299 {  id_298  };
        {
          Vec<1, int32_t> repeat_n_192 { id_299 };
          bool while_flag_300 { true };
          do {
            Arr<dessser::gen::fq_function_name::t_ext> id_301 { p_0.sources };
            uint32_t id_302 { id_301.size() };
            int32_t id_303 { int32_t(id_302) };
            uint8_t id_304 { 0 };
            int32_t id_305 { repeat_n_192[id_304] };
            bool id_306 { bool(id_303 > id_305) };
            while_flag_300 = id_306;
            if (while_flag_300) {
              uint8_t id_307 { 0 };
              uint8_t id_308 { 0 };
              Size id_309 { sz_ref_191[id_308] };
              auto fun310 { dessser::gen::fq_function_name::sersize_of_row_binary };
              uint8_t id_311 { 0 };
              int32_t id_312 { repeat_n_192[id_311] };
              Arr<dessser::gen::fq_function_name::t_ext> id_313 { p_0.sources };
              dessser::gen::fq_function_name::t_ext id_314 { id_313[id_312] };
              Size id_315 { fun310(id_314) };
              Size id_316 { Size(id_309 + id_315) };
              Void id_317 { ((void)(sz_ref_191[id_307] = id_316), ::dessser::Void()) };
              (void)id_317;
              uint8_t id_318 { 0 };
              uint8_t id_319 { 0 };
              int32_t id_320 { repeat_n_192[id_319] };
              int32_t id_321 { 1L };
              int32_t id_322 { int32_t(id_320 + id_321) };
              Void id_323 { ((void)(repeat_n_192[id_318] = id_322), ::dessser::Void()) };
              (void)id_323;
              (void)id_323;
            }
          } while (while_flag_300);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_324 { 0 };
        Size id_325 { sz_ref_191[id_324] };
        let_res_297 = id_325;
      }
      let_res_270 = let_res_297;
    }
    Size let_res_326;
    {
      Size sz_193 { let_res_270 };
      Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> id_327 { p_0.links };
      uint32_t id_328 { id_327.size() };
      Vec<1, uint32_t> id_329 {  id_328  };
      Size let_res_330;
      {
        Vec<1, uint32_t> n_ref_194 { id_329 };
        uint32_t id_331 { 1U };
        Vec<1, uint32_t> id_332 {  id_331  };
        Size let_res_333;
        {
          Vec<1, uint32_t> lebsz_ref_195 { id_332 };
          bool while_flag_334 { true };
          do {
            uint8_t id_335 { 0 };
            uint32_t id_336 { n_ref_194[id_335] };
            uint8_t id_337 { 0 };
            uint32_t id_338 { lebsz_ref_195[id_337] };
            uint8_t id_339 { 7 };
            uint32_t id_340 { uint32_t(id_338 << id_339) };
            bool id_341 { bool(id_336 >= id_340) };
            while_flag_334 = id_341;
            if (while_flag_334) {
              uint8_t id_342 { 0 };
              uint8_t id_343 { 0 };
              uint32_t id_344 { lebsz_ref_195[id_343] };
              uint32_t id_345 { 1U };
              uint32_t id_346 { uint32_t(id_344 + id_345) };
              Void id_347 { ((void)(lebsz_ref_195[id_342] = id_346), ::dessser::Void()) };
              (void)id_347;
            }
          } while (while_flag_334);
          (void)::dessser::Void();
          uint8_t id_348 { 0 };
          uint32_t id_349 { lebsz_ref_195[id_348] };
          Size id_350 { Size(id_349) };
          let_res_333 = id_350;
        }
        let_res_330 = let_res_333;
      }
      Size id_351 { Size(sz_193 + let_res_330) };
      Vec<1, Size> id_352 {  id_351  };
      Size let_res_353;
      {
        Vec<1, Size> sz_ref_196 { id_352 };
        int32_t id_354 { 0L };
        Vec<1, int32_t> id_355 {  id_354  };
        {
          Vec<1, int32_t> repeat_n_197 { id_355 };
          bool while_flag_356 { true };
          do {
            Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> id_357 { p_0.links };
            uint32_t id_358 { id_357.size() };
            int32_t id_359 { int32_t(id_358) };
            uint8_t id_360 { 0 };
            int32_t id_361 { repeat_n_197[id_360] };
            bool id_362 { bool(id_359 > id_361) };
            while_flag_356 = id_362;
            if (while_flag_356) {
              uint8_t id_363 { 0 };
              uint8_t id_364 { 0 };
              Size id_365 { sz_ref_196[id_364] };
              Size let_res_366;
              {
                Size sz_198 { id_365 };
                auto fun367 { dessser::gen::fq_function_name::sersize_of_row_binary };
                uint8_t id_368 { 0 };
                int32_t id_369 { repeat_n_197[id_368] };
                Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> id_370 { p_0.links };
                ::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40 id_371 { id_370[id_369] };
                dessser::gen::fq_function_name::t_ext id_372 { std::get<0>(id_371) };
                Size id_373 { fun367(id_372) };
                Size id_374 { Size(sz_198 + id_373) };
                let_res_366 = id_374;
              }
              Size let_res_375;
              {
                Size sz_199 { let_res_366 };
                auto fun376 { dessser::gen::fq_function_name::sersize_of_row_binary };
                uint8_t id_377 { 0 };
                int32_t id_378 { repeat_n_197[id_377] };
                Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> id_379 { p_0.links };
                ::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40 id_380 { id_379[id_378] };
                dessser::gen::fq_function_name::t_ext id_381 { std::get<1>(id_380) };
                Size id_382 { fun376(id_381) };
                Size id_383 { Size(sz_199 + id_382) };
                let_res_375 = id_383;
              }
              Void id_384 { ((void)(sz_ref_196[id_363] = let_res_375), ::dessser::Void()) };
              (void)id_384;
              uint8_t id_385 { 0 };
              uint8_t id_386 { 0 };
              int32_t id_387 { repeat_n_197[id_386] };
              int32_t id_388 { 1L };
              int32_t id_389 { int32_t(id_387 + id_388) };
              Void id_390 { ((void)(repeat_n_197[id_385] = id_389), ::dessser::Void()) };
              (void)id_390;
              (void)id_390;
            }
          } while (while_flag_356);
          (void)::dessser::Void();
        }
        (void)::dessser::Void();
        uint8_t id_391 { 0 };
        Size id_392 { sz_ref_196[id_391] };
        let_res_353 = id_392;
      }
      let_res_326 = let_res_353;
    }
    Size id_393 { 8UL };
    Size id_394 { Size(let_res_326 + id_393) };
    return id_394;
  }
   };
  return fun205;
}
std::function<Size(::dessser::gen::replay::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_60" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "drec_fst_61" "drec_snd_62" (identifier "drec_60")
          (let "drec_63" (apply (ext-identifier fq_function_name of-row-binary) (identifier "drec_snd_62"))
            (let-pair "drec_fst_64" "drec_snd_65" (identifier "drec_63")
              (let "drec_78"
                (let "dstring1_72"
                  (let "leb_ref_66" (make-vec (u32 0))
                    (let "shft_ref_67" (make-vec (u8 0))
                      (let "p_ref_68" (make-vec (identifier "drec_snd_65"))
                        (seq
                          (while
                            (let "leb128_69" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_68")))
                              (let-pair "leb128_fst_70" "leb128_snd_71" 
                                (identifier "leb128_69")
                                (seq (set-vec (u8 0) (identifier "p_ref_68") (identifier "leb128_snd_71"))
                                  (set-vec (u8 0) (identifier "leb_ref_66")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_70") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_67"))) (unsafe-nth (u8 0) (identifier "leb_ref_66"))))
                                  (set-vec (u8 0) (identifier "shft_ref_67") (add (unsafe-nth (u8 0) (identifier "shft_ref_67")) (u8 7))) 
                                  (ge (identifier "leb128_fst_70") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_66"))) (unsafe-nth (u8 0) (identifier "p_ref_68")))))))
                  (let-pair "dstring1_fst_73" "dstring1_snd_74" (identifier "dstring1_72")
                    (let-pair "dstring2_fst_76" "dstring2_snd_77" (read-bytes (identifier "dstring1_snd_74") (identifier "dstring1_fst_73"))
                      (make-tup (string-of-bytes (identifier "dstring2_fst_76")) (identifier "dstring2_snd_77")))))
                (let-pair "drec_fst_79" "drec_snd_80" (identifier "drec_78")
                  (let "drec_84" (let-pair "dfloat_fst_82" "dfloat_snd_83" (read-u64 little-endian (identifier "drec_snd_80")) (make-tup (float-of-u64 (identifier "dfloat_fst_82")) (identifier "dfloat_snd_83")))
                    (let-pair "drec_fst_85" "drec_snd_86" (identifier "drec_84")
                      (let "drec_90" (let-pair "dfloat_fst_88" "dfloat_snd_89" (read-u64 little-endian (identifier "drec_snd_86")) (make-tup (float-of-u64 (identifier "dfloat_fst_88")) (identifier "dfloat_snd_89")))
                        (let-pair "drec_fst_91" "drec_snd_92" (identifier "drec_90")
                          (let "drec_108"
                            (let "dsum1_99" (let-pair "du16_fst_94" "du16_snd_95" (read-u16 little-endian (identifier "drec_snd_92")) (make-tup (identifier "du16_fst_94") (identifier "du16_snd_95")))
                              (let-pair "dsum1_fst_100" "dsum1_snd_101" 
                                (identifier "dsum1_99")
                                (if (eq (u16 0) (identifier "dsum1_fst_100"))
                                  (let-pair "dsum2_fst_106" "dsum2_snd_107" 
                                    (apply (ext-identifier file_path of-row-binary) (identifier "dsum1_snd_101"))
                                    (make-tup (construct "[RingBuf $file_path | SyncKey $sync_key]" 0 (identifier "dsum2_fst_106")) (identifier "dsum2_snd_107")))
                                  (seq (assert (eq (identifier "dsum1_fst_100") (u16 1)))
                                    (let-pair "dsum2_fst_103" "dsum2_snd_104" 
                                      (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_101"))
                                      (make-tup (construct "[RingBuf $file_path | SyncKey $sync_key]" 1 (identifier "dsum2_fst_103")) (identifier "dsum2_snd_104")))))))
                            (let-pair "drec_fst_109" "drec_snd_110" (identifier "drec_108")
                              (let "drec_134"
                                (let-pair "dlist4_fst_132" "dlist4_snd_133"
                                  (let "dlist1_120"
                                    (let "leb_ref_111" (make-vec (u32 0))
                                      (let "shft_ref_112" (make-vec (u8 0))
                                        (let "p_ref_113" (make-vec (identifier "drec_snd_110"))
                                          (seq
                                            (while
                                              (let "leb128_114" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_113")))
                                                (let-pair "leb128_fst_115" "leb128_snd_116" 
                                                  (identifier "leb128_114")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_113") (identifier "leb128_snd_116"))
                                                    (set-vec (u8 0) (identifier "leb_ref_111")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_115") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_112"))) (unsafe-nth (u8 0) (identifier "leb_ref_111"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_112") (add (unsafe-nth (u8 0) (identifier "shft_ref_112")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_115") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_111")) (unsafe-nth (u8 0) (identifier "p_ref_113")))))))
                                    (let-pair "dlist1_fst_121" "dlist1_snd_122" 
                                      (identifier "dlist1_120")
                                      (let "inits_src_ref_123" (make-vec (make-tup (end-of-list "$fq_function_name") (identifier "dlist1_snd_122")))
                                        (seq
                                          (let "repeat_n_124" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_121")) (unsafe-nth (u8 0) (identifier "repeat_n_124")))
                                              (seq
                                                (let "dlist2_125" (unsafe-nth (u8 0) (identifier "inits_src_ref_123"))
                                                  (let-pair "dlist2_fst_126" "dlist2_snd_127" 
                                                    (identifier "dlist2_125")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_123")
                                                      (let-pair "dlist3_fst_129" "dlist3_snd_130" 
                                                        (apply (ext-identifier fq_function_name of-row-binary) (identifier "dlist2_snd_127"))
                                                        (make-tup (cons (identifier "dlist3_fst_129") (identifier "dlist2_fst_126")) (identifier "dlist3_snd_130"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_124") (add (unsafe-nth (u8 0) (identifier "repeat_n_124")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_123")))))) 
                                  (make-tup (arr-of-lst-rev (identifier "dlist4_fst_132")) (identifier "dlist4_snd_133")))
                                (let-pair "drec_fst_135" "drec_snd_136" 
                                  (identifier "drec_134")
                                  (let "drec_166"
                                    (let-pair "dlist4_fst_164" "dlist4_snd_165"
                                      (let "dlist1_146"
                                        (let "leb_ref_137" (make-vec (u32 0))
                                          (let "shft_ref_138" (make-vec (u8 0))
                                            (let "p_ref_139" (make-vec (identifier "drec_snd_136"))
                                              (seq
                                                (while
                                                  (let "leb128_140" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_139")))
                                                    (let-pair "leb128_fst_141" "leb128_snd_142" 
                                                      (identifier "leb128_140")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_139") (identifier "leb128_snd_142"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_137")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_141") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_138")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_137")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_138") (add (unsafe-nth (u8 0) (identifier "shft_ref_138")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_141") (u8 128))))) 
                                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_137")) (unsafe-nth (u8 0) (identifier "p_ref_139")))))))
                                        (let-pair "dlist1_fst_147" "dlist1_snd_148" 
                                          (identifier "dlist1_146")
                                          (let "inits_src_ref_149" (make-vec (make-tup (end-of-list "($fq_function_name; $fq_function_name)") (identifier "dlist1_snd_148")))
                                            (seq
                                              (let "repeat_n_150" (make-vec (i32 0))
                                                (while (gt (to-i32 (identifier "dlist1_fst_147")) (unsafe-nth (u8 0) (identifier "repeat_n_150")))
                                                  (seq
                                                    (let "dlist2_151" 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_149"))
                                                      (let-pair "dlist2_fst_152" "dlist2_snd_153" 
                                                        (identifier "dlist2_151")
                                                        (set-vec (u8 0) 
                                                          (identifier "inits_src_ref_149")
                                                          (let "dtup_154" 
                                                            (apply (ext-identifier fq_function_name of-row-binary) (identifier "dlist2_snd_153"))
                                                            (let-pair "dtup_fst_155" "dtup_snd_156" 
                                                              (identifier "dtup_154")
                                                              (let-pair "dtup_fst_158" "dtup_snd_159" 
                                                                (apply (ext-identifier fq_function_name of-row-binary) (identifier "dtup_snd_156"))
                                                                (make-tup (cons (make-tup (identifier "dtup_fst_155") (identifier "dtup_fst_158")) (identifier "dlist2_fst_152")) (identifier "dtup_snd_159"))))))))
                                                    (set-vec (u8 0) (identifier "repeat_n_150") (add (unsafe-nth (u8 0) (identifier "repeat_n_150")) (i32 1)))))) 
                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_149")))))) 
                                      (make-tup (arr-of-lst-rev (identifier "dlist4_fst_164")) (identifier "dlist4_snd_165")))
                                    (let-pair "drec_fst_167" "drec_snd_168" 
                                      (identifier "drec_166")
                                      (let-pair "dfloat_fst_170" "dfloat_snd_171" 
                                        (read-u64 little-endian (identifier "drec_snd_168"))
                                        (make-tup
                                          (make-rec (string "timeout_date") 
                                            (float-of-u64 (identifier "dfloat_fst_170")) 
                                            (string "links") (identifier "drec_fst_167") 
                                            (string "sources") (identifier "drec_fst_135") 
                                            (string "recipient") (identifier "drec_fst_109") 
                                            (string "until") (identifier "drec_fst_91") 
                                            (string "since") (identifier "drec_fst_85") 
                                            (string "target_fieldmask") 
                                            (identifier "drec_fst_79") 
                                            (string "target") (identifier "drec_fst_64") 
                                            (string "channel") (identifier "drec_fst_61")) 
                                          (identifier "dfloat_snd_171"))))))))))))))))))))
 */
static std::function<::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864(Pointer &)> fun395 { [&](Pointer p_0) {
    ::dessser::gen::replay::ta97bb48ed75bbda6173555873826c8c6 id_396 { p_0.readU16Le() };
    ::dessser::gen::replay::ta97bb48ed75bbda6173555873826c8c6 letpair_res_397;
    {
      auto du16_fst_58 { std::get<0>(id_396) };
      auto du16_snd_59 { std::get<1>(id_396) };
      ::dessser::gen::replay::ta97bb48ed75bbda6173555873826c8c6 id_398 { du16_fst_58, du16_snd_59 };
      letpair_res_397 = id_398;
    }
    ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 let_res_399;
    {
      ::dessser::gen::replay::ta97bb48ed75bbda6173555873826c8c6 drec_60 { letpair_res_397 };
      ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_400;
      {
        auto drec_fst_61 { std::get<0>(drec_60) };
        auto drec_snd_62 { std::get<1>(drec_60) };
        auto fun401 { dessser::gen::fq_function_name::of_row_binary };
        ::dessser::gen::replay::tafdf48d85e3efdf5b24e3fa2741562be id_402 { fun401(drec_snd_62) };
        ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 let_res_403;
        {
          ::dessser::gen::replay::tafdf48d85e3efdf5b24e3fa2741562be drec_63 { id_402 };
          ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_404;
          {
            auto drec_fst_64 { std::get<0>(drec_63) };
            auto drec_snd_65 { std::get<1>(drec_63) };
            uint32_t id_405 { 0U };
            Vec<1, uint32_t> id_406 {  id_405  };
            ::dessser::gen::replay::t12fb9c475959b52bf7b17b155a955ffa let_res_407;
            {
              Vec<1, uint32_t> leb_ref_66 { id_406 };
              uint8_t id_408 { 0 };
              Vec<1, uint8_t> id_409 {  id_408  };
              ::dessser::gen::replay::t12fb9c475959b52bf7b17b155a955ffa let_res_410;
              {
                Vec<1, uint8_t> shft_ref_67 { id_409 };
                Vec<1, Pointer> id_411 {  drec_snd_65  };
                ::dessser::gen::replay::t12fb9c475959b52bf7b17b155a955ffa let_res_412;
                {
                  Vec<1, Pointer> p_ref_68 { id_411 };
                  bool while_flag_413 { true };
                  do {
                    uint8_t id_414 { 0 };
                    Pointer id_415 { p_ref_68[id_414] };
                    ::dessser::gen::replay::t1a5d74abf838df33f185a72a8912f5c9 id_416 { id_415.readU8() };
                    bool let_res_417;
                    {
                      ::dessser::gen::replay::t1a5d74abf838df33f185a72a8912f5c9 leb128_69 { id_416 };
                      bool letpair_res_418;
                      {
                        auto leb128_fst_70 { std::get<0>(leb128_69) };
                        auto leb128_snd_71 { std::get<1>(leb128_69) };
                        uint8_t id_419 { 0 };
                        Void id_420 { ((void)(p_ref_68[id_419] = leb128_snd_71), ::dessser::Void()) };
                        (void)id_420;
                        uint8_t id_421 { 0 };
                        uint8_t id_422 { 127 };
                        uint8_t id_423 { uint8_t(leb128_fst_70 & id_422) };
                        uint32_t id_424 { uint32_t(id_423) };
                        uint8_t id_425 { 0 };
                        uint8_t id_426 { shft_ref_67[id_425] };
                        uint32_t id_427 { uint32_t(id_424 << id_426) };
                        uint8_t id_428 { 0 };
                        uint32_t id_429 { leb_ref_66[id_428] };
                        uint32_t id_430 { uint32_t(id_427 | id_429) };
                        Void id_431 { ((void)(leb_ref_66[id_421] = id_430), ::dessser::Void()) };
                        (void)id_431;
                        uint8_t id_432 { 0 };
                        uint8_t id_433 { 0 };
                        uint8_t id_434 { shft_ref_67[id_433] };
                        uint8_t id_435 { 7 };
                        uint8_t id_436 { uint8_t(id_434 + id_435) };
                        Void id_437 { ((void)(shft_ref_67[id_432] = id_436), ::dessser::Void()) };
                        (void)id_437;
                        uint8_t id_438 { 128 };
                        bool id_439 { bool(leb128_fst_70 >= id_438) };
                        letpair_res_418 = id_439;
                      }
                      let_res_417 = letpair_res_418;
                    }
                    while_flag_413 = let_res_417;
                    if (while_flag_413) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_413);
                  (void)::dessser::Void();
                  uint8_t id_440 { 0 };
                  uint32_t id_441 { leb_ref_66[id_440] };
                  Size id_442 { Size(id_441) };
                  uint8_t id_443 { 0 };
                  Pointer id_444 { p_ref_68[id_443] };
                  ::dessser::gen::replay::t12fb9c475959b52bf7b17b155a955ffa id_445 { id_442, id_444 };
                  let_res_412 = id_445;
                }
                let_res_410 = let_res_412;
              }
              let_res_407 = let_res_410;
            }
            ::dessser::gen::replay::t13a07ee37ab40962540da8534858dc07 let_res_446;
            {
              ::dessser::gen::replay::t12fb9c475959b52bf7b17b155a955ffa dstring1_72 { let_res_407 };
              ::dessser::gen::replay::t13a07ee37ab40962540da8534858dc07 letpair_res_447;
              {
                auto dstring1_fst_73 { std::get<0>(dstring1_72) };
                auto dstring1_snd_74 { std::get<1>(dstring1_72) };
                ::dessser::gen::replay::t9ef6882174ae71a34a3c5ef6b29242fb id_448 { dstring1_snd_74.readBytes(dstring1_fst_73) };
                ::dessser::gen::replay::t13a07ee37ab40962540da8534858dc07 letpair_res_449;
                {
                  auto dstring2_fst_76 { std::get<0>(id_448) };
                  auto dstring2_snd_77 { std::get<1>(id_448) };
                  std::string id_450 { dstring2_fst_76.toString() };
                  ::dessser::gen::replay::t13a07ee37ab40962540da8534858dc07 id_451 { id_450, dstring2_snd_77 };
                  letpair_res_449 = id_451;
                }
                letpair_res_447 = letpair_res_449;
              }
              let_res_446 = letpair_res_447;
            }
            ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 let_res_452;
            {
              ::dessser::gen::replay::t13a07ee37ab40962540da8534858dc07 drec_78 { let_res_446 };
              ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_453;
              {
                auto drec_fst_79 { std::get<0>(drec_78) };
                auto drec_snd_80 { std::get<1>(drec_78) };
                ::dessser::gen::replay::td2cd337bb3c8bc04d5603393d084985b id_454 { drec_snd_80.readU64Le() };
                ::dessser::gen::replay::t9a758baeff17224a77e1a522010b4168 letpair_res_455;
                {
                  auto dfloat_fst_82 { std::get<0>(id_454) };
                  auto dfloat_snd_83 { std::get<1>(id_454) };
                  double id_456 { float_of_qword(dfloat_fst_82) };
                  ::dessser::gen::replay::t9a758baeff17224a77e1a522010b4168 id_457 { id_456, dfloat_snd_83 };
                  letpair_res_455 = id_457;
                }
                ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 let_res_458;
                {
                  ::dessser::gen::replay::t9a758baeff17224a77e1a522010b4168 drec_84 { letpair_res_455 };
                  ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_459;
                  {
                    auto drec_fst_85 { std::get<0>(drec_84) };
                    auto drec_snd_86 { std::get<1>(drec_84) };
                    ::dessser::gen::replay::td2cd337bb3c8bc04d5603393d084985b id_460 { drec_snd_86.readU64Le() };
                    ::dessser::gen::replay::t9a758baeff17224a77e1a522010b4168 letpair_res_461;
                    {
                      auto dfloat_fst_88 { std::get<0>(id_460) };
                      auto dfloat_snd_89 { std::get<1>(id_460) };
                      double id_462 { float_of_qword(dfloat_fst_88) };
                      ::dessser::gen::replay::t9a758baeff17224a77e1a522010b4168 id_463 { id_462, dfloat_snd_89 };
                      letpair_res_461 = id_463;
                    }
                    ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 let_res_464;
                    {
                      ::dessser::gen::replay::t9a758baeff17224a77e1a522010b4168 drec_90 { letpair_res_461 };
                      ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_465;
                      {
                        auto drec_fst_91 { std::get<0>(drec_90) };
                        auto drec_snd_92 { std::get<1>(drec_90) };
                        ::dessser::gen::replay::ta97bb48ed75bbda6173555873826c8c6 id_466 { drec_snd_92.readU16Le() };
                        ::dessser::gen::replay::ta97bb48ed75bbda6173555873826c8c6 letpair_res_467;
                        {
                          auto du16_fst_94 { std::get<0>(id_466) };
                          auto du16_snd_95 { std::get<1>(id_466) };
                          ::dessser::gen::replay::ta97bb48ed75bbda6173555873826c8c6 id_468 { du16_fst_94, du16_snd_95 };
                          letpair_res_467 = id_468;
                        }
                        ::dessser::gen::replay::tf543a140d814d9a786a48bce0505c389 let_res_469;
                        {
                          ::dessser::gen::replay::ta97bb48ed75bbda6173555873826c8c6 dsum1_99 { letpair_res_467 };
                          ::dessser::gen::replay::tf543a140d814d9a786a48bce0505c389 letpair_res_470;
                          {
                            auto dsum1_fst_100 { std::get<0>(dsum1_99) };
                            auto dsum1_snd_101 { std::get<1>(dsum1_99) };
                            uint16_t id_471 { 0 };
                            bool id_472 { bool(id_471 == dsum1_fst_100) };
                            ::dessser::gen::replay::tf543a140d814d9a786a48bce0505c389 choose_res_473;
                            if (id_472) {
                              auto fun474 { dessser::gen::file_path::of_row_binary };
                              ::dessser::gen::replay::td0a4a9551c4a7c5b58d84275e2a098f7 id_475 { fun474(dsum1_snd_101) };
                              ::dessser::gen::replay::tf543a140d814d9a786a48bce0505c389 letpair_res_476;
                              {
                                auto dsum2_fst_106 { std::get<0>(id_475) };
                                auto dsum2_snd_107 { std::get<1>(id_475) };
                                ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_477 { std::in_place_index<0>, dsum2_fst_106 };
                                ::dessser::gen::replay::tf543a140d814d9a786a48bce0505c389 id_478 { id_477, dsum2_snd_107 };
                                letpair_res_476 = id_478;
                              }
                              choose_res_473 = letpair_res_476;
                            } else {
                              uint16_t id_479 { 1 };
                              bool id_480 { bool(dsum1_fst_100 == id_479) };
                              Void id_481 { ((void)(assert(id_480)), ::dessser::Void()) };
                              (void)id_481;
                              auto fun482 { dessser::gen::sync_key::of_row_binary };
                              ::dessser::gen::replay::t0e7f6ba9e1ceef343afe44456f9067ec id_483 { fun482(dsum1_snd_101) };
                              ::dessser::gen::replay::tf543a140d814d9a786a48bce0505c389 letpair_res_484;
                              {
                                auto dsum2_fst_103 { std::get<0>(id_483) };
                                auto dsum2_snd_104 { std::get<1>(id_483) };
                                ::dessser::gen::replay::td2e775685fdb218732b8145a467405fe id_485 { std::in_place_index<1>, dsum2_fst_103 };
                                ::dessser::gen::replay::tf543a140d814d9a786a48bce0505c389 id_486 { id_485, dsum2_snd_104 };
                                letpair_res_484 = id_486;
                              }
                              choose_res_473 = letpair_res_484;
                            }
                            letpair_res_470 = choose_res_473;
                          }
                          let_res_469 = letpair_res_470;
                        }
                        ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 let_res_487;
                        {
                          ::dessser::gen::replay::tf543a140d814d9a786a48bce0505c389 drec_108 { let_res_469 };
                          ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_488;
                          {
                            auto drec_fst_109 { std::get<0>(drec_108) };
                            auto drec_snd_110 { std::get<1>(drec_108) };
                            uint32_t id_489 { 0U };
                            Vec<1, uint32_t> id_490 {  id_489  };
                            ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 let_res_491;
                            {
                              Vec<1, uint32_t> leb_ref_111 { id_490 };
                              uint8_t id_492 { 0 };
                              Vec<1, uint8_t> id_493 {  id_492  };
                              ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 let_res_494;
                              {
                                Vec<1, uint8_t> shft_ref_112 { id_493 };
                                Vec<1, Pointer> id_495 {  drec_snd_110  };
                                ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 let_res_496;
                                {
                                  Vec<1, Pointer> p_ref_113 { id_495 };
                                  bool while_flag_497 { true };
                                  do {
                                    uint8_t id_498 { 0 };
                                    Pointer id_499 { p_ref_113[id_498] };
                                    ::dessser::gen::replay::t1a5d74abf838df33f185a72a8912f5c9 id_500 { id_499.readU8() };
                                    bool let_res_501;
                                    {
                                      ::dessser::gen::replay::t1a5d74abf838df33f185a72a8912f5c9 leb128_114 { id_500 };
                                      bool letpair_res_502;
                                      {
                                        auto leb128_fst_115 { std::get<0>(leb128_114) };
                                        auto leb128_snd_116 { std::get<1>(leb128_114) };
                                        uint8_t id_503 { 0 };
                                        Void id_504 { ((void)(p_ref_113[id_503] = leb128_snd_116), ::dessser::Void()) };
                                        (void)id_504;
                                        uint8_t id_505 { 0 };
                                        uint8_t id_506 { 127 };
                                        uint8_t id_507 { uint8_t(leb128_fst_115 & id_506) };
                                        uint32_t id_508 { uint32_t(id_507) };
                                        uint8_t id_509 { 0 };
                                        uint8_t id_510 { shft_ref_112[id_509] };
                                        uint32_t id_511 { uint32_t(id_508 << id_510) };
                                        uint8_t id_512 { 0 };
                                        uint32_t id_513 { leb_ref_111[id_512] };
                                        uint32_t id_514 { uint32_t(id_511 | id_513) };
                                        Void id_515 { ((void)(leb_ref_111[id_505] = id_514), ::dessser::Void()) };
                                        (void)id_515;
                                        uint8_t id_516 { 0 };
                                        uint8_t id_517 { 0 };
                                        uint8_t id_518 { shft_ref_112[id_517] };
                                        uint8_t id_519 { 7 };
                                        uint8_t id_520 { uint8_t(id_518 + id_519) };
                                        Void id_521 { ((void)(shft_ref_112[id_516] = id_520), ::dessser::Void()) };
                                        (void)id_521;
                                        uint8_t id_522 { 128 };
                                        bool id_523 { bool(leb128_fst_115 >= id_522) };
                                        letpair_res_502 = id_523;
                                      }
                                      let_res_501 = letpair_res_502;
                                    }
                                    while_flag_497 = let_res_501;
                                    if (while_flag_497) {
                                      (void)::dessser::Void();
                                    }
                                  } while (while_flag_497);
                                  (void)::dessser::Void();
                                  uint8_t id_524 { 0 };
                                  uint32_t id_525 { leb_ref_111[id_524] };
                                  uint8_t id_526 { 0 };
                                  Pointer id_527 { p_ref_113[id_526] };
                                  ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 id_528 { id_525, id_527 };
                                  let_res_496 = id_528;
                                }
                                let_res_494 = let_res_496;
                              }
                              let_res_491 = let_res_494;
                            }
                            ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f let_res_529;
                            {
                              ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 dlist1_120 { let_res_491 };
                              ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f letpair_res_530;
                              {
                                auto dlist1_fst_121 { std::get<0>(dlist1_120) };
                                auto dlist1_snd_122 { std::get<1>(dlist1_120) };
                                Lst<dessser::gen::fq_function_name::t_ext> endoflist_531;
                                ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f id_532 { endoflist_531, dlist1_snd_122 };
                                Vec<1, ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f> id_533 {  id_532  };
                                ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f let_res_534;
                                {
                                  Vec<1, ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f> inits_src_ref_123 { id_533 };
                                  int32_t id_535 { 0L };
                                  Vec<1, int32_t> id_536 {  id_535  };
                                  {
                                    Vec<1, int32_t> repeat_n_124 { id_536 };
                                    bool while_flag_537 { true };
                                    do {
                                      int32_t id_538 { int32_t(dlist1_fst_121) };
                                      uint8_t id_539 { 0 };
                                      int32_t id_540 { repeat_n_124[id_539] };
                                      bool id_541 { bool(id_538 > id_540) };
                                      while_flag_537 = id_541;
                                      if (while_flag_537) {
                                        uint8_t id_542 { 0 };
                                        ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f id_543 { inits_src_ref_123[id_542] };
                                        {
                                          ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f dlist2_125 { id_543 };
                                          {
                                            auto dlist2_fst_126 { std::get<0>(dlist2_125) };
                                            auto dlist2_snd_127 { std::get<1>(dlist2_125) };
                                            uint8_t id_544 { 0 };
                                            auto fun545 { dessser::gen::fq_function_name::of_row_binary };
                                            ::dessser::gen::replay::tafdf48d85e3efdf5b24e3fa2741562be id_546 { fun545(dlist2_snd_127) };
                                            ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f letpair_res_547;
                                            {
                                              auto dlist3_fst_129 { std::get<0>(id_546) };
                                              auto dlist3_snd_130 { std::get<1>(id_546) };
                                              Lst<dessser::gen::fq_function_name::t_ext> id_548 { dlist3_fst_129, dlist2_fst_126 };
                                              ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f id_549 { id_548, dlist3_snd_130 };
                                              letpair_res_547 = id_549;
                                            }
                                            Void id_550 { ((void)(inits_src_ref_123[id_544] = letpair_res_547), ::dessser::Void()) };
                                            (void)id_550;
                                          }
                                          (void)::dessser::Void();
                                        }
                                        (void)::dessser::Void();
                                        uint8_t id_551 { 0 };
                                        uint8_t id_552 { 0 };
                                        int32_t id_553 { repeat_n_124[id_552] };
                                        int32_t id_554 { 1L };
                                        int32_t id_555 { int32_t(id_553 + id_554) };
                                        Void id_556 { ((void)(repeat_n_124[id_551] = id_555), ::dessser::Void()) };
                                        (void)id_556;
                                        (void)id_556;
                                      }
                                    } while (while_flag_537);
                                    (void)::dessser::Void();
                                  }
                                  (void)::dessser::Void();
                                  uint8_t id_557 { 0 };
                                  ::dessser::gen::replay::t753363e387f81b7c224164f5dc43347f id_558 { inits_src_ref_123[id_557] };
                                  let_res_534 = id_558;
                                }
                                letpair_res_530 = let_res_534;
                              }
                              let_res_529 = letpair_res_530;
                            }
                            ::dessser::gen::replay::t7e337a83829e34e4f1a2127dcf8e964a letpair_res_559;
                            {
                              auto dlist4_fst_132 { std::get<0>(let_res_529) };
                              auto dlist4_snd_133 { std::get<1>(let_res_529) };
                              Arr<dessser::gen::fq_function_name::t_ext> id_560 { dlist4_fst_132.toArrRev() };
                              ::dessser::gen::replay::t7e337a83829e34e4f1a2127dcf8e964a id_561 { id_560, dlist4_snd_133 };
                              letpair_res_559 = id_561;
                            }
                            ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 let_res_562;
                            {
                              ::dessser::gen::replay::t7e337a83829e34e4f1a2127dcf8e964a drec_134 { letpair_res_559 };
                              ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_563;
                              {
                                auto drec_fst_135 { std::get<0>(drec_134) };
                                auto drec_snd_136 { std::get<1>(drec_134) };
                                uint32_t id_564 { 0U };
                                Vec<1, uint32_t> id_565 {  id_564  };
                                ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 let_res_566;
                                {
                                  Vec<1, uint32_t> leb_ref_137 { id_565 };
                                  uint8_t id_567 { 0 };
                                  Vec<1, uint8_t> id_568 {  id_567  };
                                  ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 let_res_569;
                                  {
                                    Vec<1, uint8_t> shft_ref_138 { id_568 };
                                    Vec<1, Pointer> id_570 {  drec_snd_136  };
                                    ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 let_res_571;
                                    {
                                      Vec<1, Pointer> p_ref_139 { id_570 };
                                      bool while_flag_572 { true };
                                      do {
                                        uint8_t id_573 { 0 };
                                        Pointer id_574 { p_ref_139[id_573] };
                                        ::dessser::gen::replay::t1a5d74abf838df33f185a72a8912f5c9 id_575 { id_574.readU8() };
                                        bool let_res_576;
                                        {
                                          ::dessser::gen::replay::t1a5d74abf838df33f185a72a8912f5c9 leb128_140 { id_575 };
                                          bool letpair_res_577;
                                          {
                                            auto leb128_fst_141 { std::get<0>(leb128_140) };
                                            auto leb128_snd_142 { std::get<1>(leb128_140) };
                                            uint8_t id_578 { 0 };
                                            Void id_579 { ((void)(p_ref_139[id_578] = leb128_snd_142), ::dessser::Void()) };
                                            (void)id_579;
                                            uint8_t id_580 { 0 };
                                            uint8_t id_581 { 127 };
                                            uint8_t id_582 { uint8_t(leb128_fst_141 & id_581) };
                                            uint32_t id_583 { uint32_t(id_582) };
                                            uint8_t id_584 { 0 };
                                            uint8_t id_585 { shft_ref_138[id_584] };
                                            uint32_t id_586 { uint32_t(id_583 << id_585) };
                                            uint8_t id_587 { 0 };
                                            uint32_t id_588 { leb_ref_137[id_587] };
                                            uint32_t id_589 { uint32_t(id_586 | id_588) };
                                            Void id_590 { ((void)(leb_ref_137[id_580] = id_589), ::dessser::Void()) };
                                            (void)id_590;
                                            uint8_t id_591 { 0 };
                                            uint8_t id_592 { 0 };
                                            uint8_t id_593 { shft_ref_138[id_592] };
                                            uint8_t id_594 { 7 };
                                            uint8_t id_595 { uint8_t(id_593 + id_594) };
                                            Void id_596 { ((void)(shft_ref_138[id_591] = id_595), ::dessser::Void()) };
                                            (void)id_596;
                                            uint8_t id_597 { 128 };
                                            bool id_598 { bool(leb128_fst_141 >= id_597) };
                                            letpair_res_577 = id_598;
                                          }
                                          let_res_576 = letpair_res_577;
                                        }
                                        while_flag_572 = let_res_576;
                                        if (while_flag_572) {
                                          (void)::dessser::Void();
                                        }
                                      } while (while_flag_572);
                                      (void)::dessser::Void();
                                      uint8_t id_599 { 0 };
                                      uint32_t id_600 { leb_ref_137[id_599] };
                                      uint8_t id_601 { 0 };
                                      Pointer id_602 { p_ref_139[id_601] };
                                      ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 id_603 { id_600, id_602 };
                                      let_res_571 = id_603;
                                    }
                                    let_res_569 = let_res_571;
                                  }
                                  let_res_566 = let_res_569;
                                }
                                ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d let_res_604;
                                {
                                  ::dessser::gen::replay::t491c44439106a32f896827242e8e76a1 dlist1_146 { let_res_566 };
                                  ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d letpair_res_605;
                                  {
                                    auto dlist1_fst_147 { std::get<0>(dlist1_146) };
                                    auto dlist1_snd_148 { std::get<1>(dlist1_146) };
                                    Lst<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> endoflist_606;
                                    ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d id_607 { endoflist_606, dlist1_snd_148 };
                                    Vec<1, ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d> id_608 {  id_607  };
                                    ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d let_res_609;
                                    {
                                      Vec<1, ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d> inits_src_ref_149 { id_608 };
                                      int32_t id_610 { 0L };
                                      Vec<1, int32_t> id_611 {  id_610  };
                                      {
                                        Vec<1, int32_t> repeat_n_150 { id_611 };
                                        bool while_flag_612 { true };
                                        do {
                                          int32_t id_613 { int32_t(dlist1_fst_147) };
                                          uint8_t id_614 { 0 };
                                          int32_t id_615 { repeat_n_150[id_614] };
                                          bool id_616 { bool(id_613 > id_615) };
                                          while_flag_612 = id_616;
                                          if (while_flag_612) {
                                            uint8_t id_617 { 0 };
                                            ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d id_618 { inits_src_ref_149[id_617] };
                                            {
                                              ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d dlist2_151 { id_618 };
                                              {
                                                auto dlist2_fst_152 { std::get<0>(dlist2_151) };
                                                auto dlist2_snd_153 { std::get<1>(dlist2_151) };
                                                uint8_t id_619 { 0 };
                                                auto fun620 { dessser::gen::fq_function_name::of_row_binary };
                                                ::dessser::gen::replay::tafdf48d85e3efdf5b24e3fa2741562be id_621 { fun620(dlist2_snd_153) };
                                                ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d let_res_622;
                                                {
                                                  ::dessser::gen::replay::tafdf48d85e3efdf5b24e3fa2741562be dtup_154 { id_621 };
                                                  ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d letpair_res_623;
                                                  {
                                                    auto dtup_fst_155 { std::get<0>(dtup_154) };
                                                    auto dtup_snd_156 { std::get<1>(dtup_154) };
                                                    auto fun624 { dessser::gen::fq_function_name::of_row_binary };
                                                    ::dessser::gen::replay::tafdf48d85e3efdf5b24e3fa2741562be id_625 { fun624(dtup_snd_156) };
                                                    ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d letpair_res_626;
                                                    {
                                                      auto dtup_fst_158 { std::get<0>(id_625) };
                                                      auto dtup_snd_159 { std::get<1>(id_625) };
                                                      ::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40 id_627 { dtup_fst_155, dtup_fst_158 };
                                                      Lst<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> id_628 { id_627, dlist2_fst_152 };
                                                      ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d id_629 { id_628, dtup_snd_159 };
                                                      letpair_res_626 = id_629;
                                                    }
                                                    letpair_res_623 = letpair_res_626;
                                                  }
                                                  let_res_622 = letpair_res_623;
                                                }
                                                Void id_630 { ((void)(inits_src_ref_149[id_619] = let_res_622), ::dessser::Void()) };
                                                (void)id_630;
                                              }
                                              (void)::dessser::Void();
                                            }
                                            (void)::dessser::Void();
                                            uint8_t id_631 { 0 };
                                            uint8_t id_632 { 0 };
                                            int32_t id_633 { repeat_n_150[id_632] };
                                            int32_t id_634 { 1L };
                                            int32_t id_635 { int32_t(id_633 + id_634) };
                                            Void id_636 { ((void)(repeat_n_150[id_631] = id_635), ::dessser::Void()) };
                                            (void)id_636;
                                            (void)id_636;
                                          }
                                        } while (while_flag_612);
                                        (void)::dessser::Void();
                                      }
                                      (void)::dessser::Void();
                                      uint8_t id_637 { 0 };
                                      ::dessser::gen::replay::t423627277da8559e8b54a2ca90fab66d id_638 { inits_src_ref_149[id_637] };
                                      let_res_609 = id_638;
                                    }
                                    letpair_res_605 = let_res_609;
                                  }
                                  let_res_604 = letpair_res_605;
                                }
                                ::dessser::gen::replay::t28a2aa1152147e15b39aa4954f238c94 letpair_res_639;
                                {
                                  auto dlist4_fst_164 { std::get<0>(let_res_604) };
                                  auto dlist4_snd_165 { std::get<1>(let_res_604) };
                                  Arr<::dessser::gen::replay::te5110d98acb3927362000c58e13a1d40> id_640 { dlist4_fst_164.toArrRev() };
                                  ::dessser::gen::replay::t28a2aa1152147e15b39aa4954f238c94 id_641 { id_640, dlist4_snd_165 };
                                  letpair_res_639 = id_641;
                                }
                                ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 let_res_642;
                                {
                                  ::dessser::gen::replay::t28a2aa1152147e15b39aa4954f238c94 drec_166 { letpair_res_639 };
                                  ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_643;
                                  {
                                    auto drec_fst_167 { std::get<0>(drec_166) };
                                    auto drec_snd_168 { std::get<1>(drec_166) };
                                    ::dessser::gen::replay::td2cd337bb3c8bc04d5603393d084985b id_644 { drec_snd_168.readU64Le() };
                                    ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_645;
                                    {
                                      auto dfloat_fst_170 { std::get<0>(id_644) };
                                      auto dfloat_snd_171 { std::get<1>(id_644) };
                                      double id_646 { float_of_qword(dfloat_fst_170) };
                                      ::dessser::gen::replay::t id_647 { drec_fst_61, drec_fst_64, drec_fst_79, drec_fst_85, drec_fst_91, drec_fst_109, drec_fst_135, drec_fst_167, id_646 };
                                      ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 id_648 { id_647, dfloat_snd_171 };
                                      letpair_res_645 = id_648;
                                    }
                                    letpair_res_643 = letpair_res_645;
                                  }
                                  let_res_642 = letpair_res_643;
                                }
                                letpair_res_563 = let_res_642;
                              }
                              let_res_562 = letpair_res_563;
                            }
                            letpair_res_488 = let_res_562;
                          }
                          let_res_487 = letpair_res_488;
                        }
                        letpair_res_465 = let_res_487;
                      }
                      let_res_464 = letpair_res_465;
                    }
                    letpair_res_459 = let_res_464;
                  }
                  let_res_458 = letpair_res_459;
                }
                letpair_res_453 = let_res_458;
              }
              let_res_452 = letpair_res_453;
            }
            letpair_res_404 = let_res_452;
          }
          let_res_403 = letpair_res_404;
        }
        letpair_res_400 = let_res_403;
      }
      let_res_399 = letpair_res_400;
    }
    return let_res_399;
  }
   };
  return fun395;
}
std::function<::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_176" "make_snd_177" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_176") (identifier "make_snd_177"))))
 */
static std::function<::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864(Pointer &)> fun649 { [&](Pointer p_0) {
    ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 id_650 { of_row_binary(p_0) };
    ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 letpair_res_651;
    {
      auto make_fst_176 { std::get<0>(id_650) };
      auto make_snd_177 { std::get<1>(id_650) };
      ::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864 id_652 { make_fst_176, make_snd_177 };
      letpair_res_651 = id_652;
    }
    return letpair_res_651;
  }
   };
  return fun649;
}
std::function<::dessser::gen::replay::tc3ad1a607bcf0cc959516ffbd1438864(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{channel: U16; target: $fq_function_name; target_fieldmask: STRING; since: FLOAT; until: FLOAT; recipient: [RingBuf $file_path | SyncKey $sync_key]; sources: $fq_function_name[]; links: ($fq_function_name; $fq_function_name)[]; timeout_date: FLOAT}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::replay::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::replay::t &,Pointer &)> fun653 { [&](::dessser::gen::replay::t p_0, Pointer p_1) {
    Pointer id_654 { to_row_binary(p_0, p_1) };
    return id_654;
  }
   };
  return fun653;
}
std::function<Pointer(::dessser::gen::replay::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
