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
#include "desssergen/sync_key.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_socket.h"

namespace dessser::gen::sync_server_msg {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t3f973b24e2e9a1d94d78f692da2d8ddd {
  dessser::gen::sync_key::t_ext SetKey_k;
  double SetKey_mtime;
  std::string SetKey_uid;
  dessser::gen::sync_value::t_ext SetKey_v;
  t3f973b24e2e9a1d94d78f692da2d8ddd(dessser::gen::sync_key::t_ext SetKey_k_, double SetKey_mtime_, std::string SetKey_uid_, dessser::gen::sync_value::t_ext SetKey_v_) : SetKey_k(SetKey_k_), SetKey_mtime(SetKey_mtime_), SetKey_uid(SetKey_uid_), SetKey_v(SetKey_v_) {}
  t3f973b24e2e9a1d94d78f692da2d8ddd() = default;
};
inline bool operator==(t3f973b24e2e9a1d94d78f692da2d8ddd const &a, t3f973b24e2e9a1d94d78f692da2d8ddd const &b) {
  return ::dessser::gen::sync_key::Deref(a.SetKey_k) == ::dessser::gen::sync_key::Deref(b.SetKey_k) && a.SetKey_mtime == b.SetKey_mtime && a.SetKey_uid == b.SetKey_uid && ::dessser::gen::sync_value::Deref(a.SetKey_v) == ::dessser::gen::sync_value::Deref(b.SetKey_v);
}

inline bool operator!=(t3f973b24e2e9a1d94d78f692da2d8ddd const &a, t3f973b24e2e9a1d94d78f692da2d8ddd const &b) {
  return !operator==(a, b);
}
struct td4227ac047ed98f74e1d279b847d611e {
  bool can_del;
  bool can_write;
  double NewKey_expiry;
  dessser::gen::sync_key::t_ext NewKey_k;
  double mtime;
  std::string NewKey_owner;
  std::string NewKey_uid;
  dessser::gen::sync_value::t_ext v;
  td4227ac047ed98f74e1d279b847d611e(bool can_del_, bool can_write_, double NewKey_expiry_, dessser::gen::sync_key::t_ext NewKey_k_, double mtime_, std::string NewKey_owner_, std::string NewKey_uid_, dessser::gen::sync_value::t_ext v_) : can_del(can_del_), can_write(can_write_), NewKey_expiry(NewKey_expiry_), NewKey_k(NewKey_k_), mtime(mtime_), NewKey_owner(NewKey_owner_), NewKey_uid(NewKey_uid_), v(v_) {}
  td4227ac047ed98f74e1d279b847d611e() = default;
};
inline bool operator==(td4227ac047ed98f74e1d279b847d611e const &a, td4227ac047ed98f74e1d279b847d611e const &b) {
  return a.can_del == b.can_del && a.can_write == b.can_write && a.NewKey_expiry == b.NewKey_expiry && ::dessser::gen::sync_key::Deref(a.NewKey_k) == ::dessser::gen::sync_key::Deref(b.NewKey_k) && a.mtime == b.mtime && a.NewKey_owner == b.NewKey_owner && a.NewKey_uid == b.NewKey_uid && ::dessser::gen::sync_value::Deref(a.v) == ::dessser::gen::sync_value::Deref(b.v);
}

inline bool operator!=(td4227ac047ed98f74e1d279b847d611e const &a, td4227ac047ed98f74e1d279b847d611e const &b) {
  return !operator==(a, b);
}
struct t08b27b0be3a89631db1d9e270c1e83bc {
  dessser::gen::sync_key::t_ext DelKey_k;
  std::string uid;
  t08b27b0be3a89631db1d9e270c1e83bc(dessser::gen::sync_key::t_ext DelKey_k_, std::string uid_) : DelKey_k(DelKey_k_), uid(uid_) {}
  t08b27b0be3a89631db1d9e270c1e83bc() = default;
};
inline bool operator==(t08b27b0be3a89631db1d9e270c1e83bc const &a, t08b27b0be3a89631db1d9e270c1e83bc const &b) {
  return ::dessser::gen::sync_key::Deref(a.DelKey_k) == ::dessser::gen::sync_key::Deref(b.DelKey_k) && a.uid == b.uid;
}

inline bool operator!=(t08b27b0be3a89631db1d9e270c1e83bc const &a, t08b27b0be3a89631db1d9e270c1e83bc const &b) {
  return !operator==(a, b);
}
struct t675a4fdd830ddedd7d9ba746180c033f {
  double expiry;
  dessser::gen::sync_key::t_ext k;
  std::string owner;
  t675a4fdd830ddedd7d9ba746180c033f(double expiry_, dessser::gen::sync_key::t_ext k_, std::string owner_) : expiry(expiry_), k(k_), owner(owner_) {}
  t675a4fdd830ddedd7d9ba746180c033f() = default;
};
inline bool operator==(t675a4fdd830ddedd7d9ba746180c033f const &a, t675a4fdd830ddedd7d9ba746180c033f const &b) {
  return a.expiry == b.expiry && ::dessser::gen::sync_key::Deref(a.k) == ::dessser::gen::sync_key::Deref(b.k) && a.owner == b.owner;
}

inline bool operator!=(t675a4fdd830ddedd7d9ba746180c033f const &a, t675a4fdd830ddedd7d9ba746180c033f const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  dessser::gen::sync_socket::t_ext, // AuthOk
  std::string, // AuthErr
  ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd, // SetKey
  ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e, // NewKey
  ::dessser::gen::sync_server_msg::t08b27b0be3a89631db1d9e270c1e83bc, // DelKey
  ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f, // LockKey
  dessser::gen::sync_key::t_ext // UnlockKey
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 7 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)); // AuthOk
    case 1: return std::get<1>(a) == std::get<1>(b); // AuthErr
    case 2: return std::get<2>(a) == std::get<2>(b); // SetKey
    case 3: return std::get<3>(a) == std::get<3>(b); // NewKey
    case 4: return std::get<4>(a) == std::get<4>(b); // DelKey
    case 5: return std::get<5>(a) == std::get<5>(b); // LockKey
    case 6: return ::dessser::gen::sync_key::Deref(std::get<6>(a)) == ::dessser::gen::sync_key::Deref(std::get<6>(b)); // UnlockKey
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t74e78fed6c064ccc52152cfa38842dd1 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_server_msg::t> ,
  Pointer
> {
  using tuple::tuple;
  t74e78fed6c064ccc52152cfa38842dd1(std::tuple<std::shared_ptr<::dessser::gen::sync_server_msg::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_server_msg::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t74e78fed6c064ccc52152cfa38842dd1 const &a, t74e78fed6c064ccc52152cfa38842dd1 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t74e78fed6c064ccc52152cfa38842dd1 const &a, t74e78fed6c064ccc52152cfa38842dd1 const &b) {
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
struct tc3c0b466d06f5b0f1ffeebd3dab58a35 : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  Pointer
> {
  using tuple::tuple;
  tc3c0b466d06f5b0f1ffeebd3dab58a35(std::tuple<dessser::gen::sync_socket::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_socket::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc3c0b466d06f5b0f1ffeebd3dab58a35 const &a, tc3c0b466d06f5b0f1ffeebd3dab58a35 const &b) {
  return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc3c0b466d06f5b0f1ffeebd3dab58a35 const &a, tc3c0b466d06f5b0f1ffeebd3dab58a35 const &b) {
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
struct td4515cd8d0eb18a7a966d81bd2888d81 : public std::tuple<
  dessser::gen::sync_value::t_ext,
  Pointer
> {
  using tuple::tuple;
  td4515cd8d0eb18a7a966d81bd2888d81(std::tuple<dessser::gen::sync_value::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_value::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td4515cd8d0eb18a7a966d81bd2888d81 const &a, td4515cd8d0eb18a7a966d81bd2888d81 const &b) {
  return ::dessser::gen::sync_value::Deref(std::get<0>(a)) == ::dessser::gen::sync_value::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td4515cd8d0eb18a7a966d81bd2888d81 const &a, td4515cd8d0eb18a7a966d81bd2888d81 const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" "Ptr")
      (let "ssum_dst_267" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (apply (ext-identifier sync_socket to-row-binary) (get-alt "AuthOk" (param 0)) (identifier "ssum_dst_267"))
          (if (eq (u16 1) (label-of (param 0)))
            (write-bytes
              (let "leb128_sz_291" (make-vec (string-length (get-alt "AuthErr" (param 0))))
                (let "leb128_ptr_292" (make-vec (identifier "ssum_dst_267"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_292")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_292"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_291"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_291"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_291"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_291") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_291")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_291")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_292"))))) 
              (bytes-of-string (get-alt "AuthErr" (param 0))))
            (if (eq (u16 2) (label-of (param 0)))
              (let "srec_dst_290"
                (let "srec_dst_287"
                  (let "srec_dst_286" (apply (ext-identifier sync_key to-row-binary) (get-field "k" (get-alt "SetKey" (param 0))) (identifier "ssum_dst_267"))
                    (apply (ext-identifier sync_value to-row-binary) (get-field "v" (get-alt "SetKey" (param 0))) (identifier "srec_dst_286")))
                  (write-bytes
                    (let "leb128_sz_288" (make-vec (string-length (get-field "uid" (get-alt "SetKey" (param 0)))))
                      (let "leb128_ptr_289" (make-vec (identifier "srec_dst_287"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_289")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_289"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_288"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_288"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_288"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_288") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_288")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_288")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_289"))))) 
                    (bytes-of-string (get-field "uid" (get-alt "SetKey" (param 0)))))) 
                (write-u64 little-endian (identifier "srec_dst_290") (u64-of-float (get-field "mtime" (get-alt "SetKey" (param 0))))))
              (if (eq (u16 3) (label-of (param 0)))
                (let "srec_dst_285"
                  (let "srec_dst_282"
                    (let "srec_dst_281"
                      (let "srec_dst_280"
                        (let "srec_dst_279"
                          (let "srec_dst_276"
                            (let "srec_dst_275" (apply (ext-identifier sync_key to-row-binary) (get-field "k" (get-alt "NewKey" (param 0))) (identifier "ssum_dst_267"))
                              (apply (ext-identifier sync_value to-row-binary) (get-field "v" (get-alt "NewKey" (param 0))) (identifier "srec_dst_275")))
                            (write-bytes
                              (let "leb128_sz_277" (make-vec (string-length (get-field "uid" (get-alt "NewKey" (param 0)))))
                                (let "leb128_ptr_278" (make-vec (identifier "srec_dst_276"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_278")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_278"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_277"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_277"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_277"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_277") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_277")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_277")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_278"))))) 
                              (bytes-of-string (get-field "uid" (get-alt "NewKey" (param 0)))))) 
                          (write-u64 little-endian (identifier "srec_dst_279") (u64-of-float (get-field "mtime" (get-alt "NewKey" (param 0))))))
                        (write-u8 (identifier "srec_dst_280") (u8-of-bool (get-field "can_write" (get-alt "NewKey" (param 0))))))
                      (write-u8 (identifier "srec_dst_281") (u8-of-bool (get-field "can_del" (get-alt "NewKey" (param 0))))))
                    (write-bytes
                      (let "leb128_sz_283" (make-vec (string-length (get-field "owner" (get-alt "NewKey" (param 0)))))
                        (let "leb128_ptr_284" (make-vec (identifier "srec_dst_282"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_284")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_284"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_283"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_283"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_283"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_283") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_283")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_283")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_284"))))) 
                      (bytes-of-string (get-field "owner" (get-alt "NewKey" (param 0)))))) 
                  (write-u64 little-endian (identifier "srec_dst_285") (u64-of-float (get-field "expiry" (get-alt "NewKey" (param 0))))))
                (if (eq (u16 4) (label-of (param 0)))
                  (let "srec_dst_272" (apply (ext-identifier sync_key to-row-binary) (get-field "k" (get-alt "DelKey" (param 0))) (identifier "ssum_dst_267"))
                    (write-bytes
                      (let "leb128_sz_273" (make-vec (string-length (get-field "uid" (get-alt "DelKey" (param 0)))))
                        (let "leb128_ptr_274" (make-vec (identifier "srec_dst_272"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_274")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_274"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_273"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_273"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_273"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_273") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_273")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_273")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_274"))))) 
                      (bytes-of-string (get-field "uid" (get-alt "DelKey" (param 0))))))
                  (if (eq (u16 5) (label-of (param 0)))
                    (let "srec_dst_271"
                      (let "srec_dst_268" (apply (ext-identifier sync_key to-row-binary) (get-field "k" (get-alt "LockKey" (param 0))) (identifier "ssum_dst_267"))
                        (write-bytes
                          (let "leb128_sz_269" (make-vec (string-length (get-field "owner" (get-alt "LockKey" (param 0)))))
                            (let "leb128_ptr_270" (make-vec (identifier "srec_dst_268"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_270")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_270"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_269"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_269"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_269"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_269") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_269")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_269")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_270"))))) 
                          (bytes-of-string (get-field "owner" (get-alt "LockKey" (param 0)))))) 
                      (write-u64 little-endian (identifier "srec_dst_271") (u64-of-float (get-field "expiry" (get-alt "LockKey" (param 0))))))
                    (seq (assert (eq (label-of (param 0)) (u16 6))) (apply (ext-identifier sync_key to-row-binary) (get-alt "UnlockKey" (param 0)) (identifier "ssum_dst_267")))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_server_msg::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_server_msg::t> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::sync_server_msg::t>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_267 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        auto fun8 { dessser::gen::sync_socket::to_row_binary };
        dessser::gen::sync_socket::t_ext id_9 { std::get<0 /* AuthOk */>((*p_0)) };
        Pointer id_10 { fun8(id_9, ssum_dst_267) };
        choose_res_7 = id_10;
      } else {
        uint16_t id_11 { 1 };
        uint16_t id_12 { uint16_t((*p_0).index()) };
        bool id_13 { bool(id_11 == id_12) };
        Pointer choose_res_14;
        if (id_13) {
          std::string id_15 { std::get<1 /* AuthErr */>((*p_0)) };
          uint32_t id_16 { (uint32_t)id_15.size() };
          Vec<1, uint32_t> id_17 {  id_16  };
          Pointer let_res_18;
          {
            Vec<1, uint32_t> leb128_sz_291 { id_17 };
            Vec<1, Pointer> id_19 {  ssum_dst_267  };
            Pointer let_res_20;
            {
              Vec<1, Pointer> leb128_ptr_292 { id_19 };
              bool while_flag_21 { true };
              do {
                uint8_t id_22 { 0 };
                uint8_t id_23 { 0 };
                Pointer id_24 { leb128_ptr_292[id_23] };
                uint32_t id_25 { 128U };
                uint8_t id_26 { 0 };
                uint32_t id_27 { leb128_sz_291[id_26] };
                bool id_28 { bool(id_25 > id_27) };
                uint8_t choose_res_29;
                if (id_28) {
                  uint8_t id_30 { 0 };
                  uint32_t id_31 { leb128_sz_291[id_30] };
                  uint8_t id_32 { uint8_t(id_31) };
                  choose_res_29 = id_32;
                } else {
                  uint8_t id_33 { 0 };
                  uint32_t id_34 { leb128_sz_291[id_33] };
                  uint8_t id_35 { uint8_t(id_34) };
                  uint8_t id_36 { 128 };
                  uint8_t id_37 { uint8_t(id_35 | id_36) };
                  choose_res_29 = id_37;
                }
                Pointer id_38 { id_24.writeU8(choose_res_29) };
                Void id_39 { ((void)(leb128_ptr_292[id_22] = id_38), ::dessser::VOID) };
                (void)id_39;
                uint8_t id_40 { 0 };
                uint8_t id_41 { 0 };
                uint32_t id_42 { leb128_sz_291[id_41] };
                uint8_t id_43 { 7 };
                uint32_t id_44 { uint32_t(id_42 >> id_43) };
                Void id_45 { ((void)(leb128_sz_291[id_40] = id_44), ::dessser::VOID) };
                (void)id_45;
                uint8_t id_46 { 0 };
                uint32_t id_47 { leb128_sz_291[id_46] };
                uint32_t id_48 { 0U };
                bool id_49 { bool(id_47 > id_48) };
                while_flag_21 = id_49;
                if (while_flag_21) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_21);
              (void)::dessser::VOID;
              uint8_t id_50 { 0 };
              Pointer id_51 { leb128_ptr_292[id_50] };
              let_res_20 = id_51;
            }
            let_res_18 = let_res_20;
          }
          std::string id_52 { std::get<1 /* AuthErr */>((*p_0)) };
          Bytes id_53 { id_52 };
          Pointer id_54 { let_res_18.writeBytes(id_53) };
          choose_res_14 = id_54;
        } else {
          uint16_t id_55 { 2 };
          uint16_t id_56 { uint16_t((*p_0).index()) };
          bool id_57 { bool(id_55 == id_56) };
          Pointer choose_res_58;
          if (id_57) {
            auto fun59 { dessser::gen::sync_key::to_row_binary };
            ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_60 { std::get<2 /* SetKey */>((*p_0)) };
            dessser::gen::sync_key::t_ext id_61 { id_60.SetKey_k };
            Pointer id_62 { fun59(id_61, ssum_dst_267) };
            Pointer let_res_63;
            {
              Pointer srec_dst_286 { id_62 };
              auto fun64 { dessser::gen::sync_value::to_row_binary };
              ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_65 { std::get<2 /* SetKey */>((*p_0)) };
              dessser::gen::sync_value::t_ext id_66 { id_65.SetKey_v };
              Pointer id_67 { fun64(id_66, srec_dst_286) };
              let_res_63 = id_67;
            }
            Pointer let_res_68;
            {
              Pointer srec_dst_287 { let_res_63 };
              ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_69 { std::get<2 /* SetKey */>((*p_0)) };
              std::string id_70 { id_69.SetKey_uid };
              uint32_t id_71 { (uint32_t)id_70.size() };
              Vec<1, uint32_t> id_72 {  id_71  };
              Pointer let_res_73;
              {
                Vec<1, uint32_t> leb128_sz_288 { id_72 };
                Vec<1, Pointer> id_74 {  srec_dst_287  };
                Pointer let_res_75;
                {
                  Vec<1, Pointer> leb128_ptr_289 { id_74 };
                  bool while_flag_76 { true };
                  do {
                    uint8_t id_77 { 0 };
                    uint8_t id_78 { 0 };
                    Pointer id_79 { leb128_ptr_289[id_78] };
                    uint32_t id_80 { 128U };
                    uint8_t id_81 { 0 };
                    uint32_t id_82 { leb128_sz_288[id_81] };
                    bool id_83 { bool(id_80 > id_82) };
                    uint8_t choose_res_84;
                    if (id_83) {
                      uint8_t id_85 { 0 };
                      uint32_t id_86 { leb128_sz_288[id_85] };
                      uint8_t id_87 { uint8_t(id_86) };
                      choose_res_84 = id_87;
                    } else {
                      uint8_t id_88 { 0 };
                      uint32_t id_89 { leb128_sz_288[id_88] };
                      uint8_t id_90 { uint8_t(id_89) };
                      uint8_t id_91 { 128 };
                      uint8_t id_92 { uint8_t(id_90 | id_91) };
                      choose_res_84 = id_92;
                    }
                    Pointer id_93 { id_79.writeU8(choose_res_84) };
                    Void id_94 { ((void)(leb128_ptr_289[id_77] = id_93), ::dessser::VOID) };
                    (void)id_94;
                    uint8_t id_95 { 0 };
                    uint8_t id_96 { 0 };
                    uint32_t id_97 { leb128_sz_288[id_96] };
                    uint8_t id_98 { 7 };
                    uint32_t id_99 { uint32_t(id_97 >> id_98) };
                    Void id_100 { ((void)(leb128_sz_288[id_95] = id_99), ::dessser::VOID) };
                    (void)id_100;
                    uint8_t id_101 { 0 };
                    uint32_t id_102 { leb128_sz_288[id_101] };
                    uint32_t id_103 { 0U };
                    bool id_104 { bool(id_102 > id_103) };
                    while_flag_76 = id_104;
                    if (while_flag_76) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_76);
                  (void)::dessser::VOID;
                  uint8_t id_105 { 0 };
                  Pointer id_106 { leb128_ptr_289[id_105] };
                  let_res_75 = id_106;
                }
                let_res_73 = let_res_75;
              }
              ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_107 { std::get<2 /* SetKey */>((*p_0)) };
              std::string id_108 { id_107.SetKey_uid };
              Bytes id_109 { id_108 };
              Pointer id_110 { let_res_73.writeBytes(id_109) };
              let_res_68 = id_110;
            }
            Pointer let_res_111;
            {
              Pointer srec_dst_290 { let_res_68 };
              ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_112 { std::get<2 /* SetKey */>((*p_0)) };
              double id_113 { id_112.SetKey_mtime };
              uint64_t id_114 { qword_of_float(id_113) };
              Pointer id_115 { srec_dst_290.writeU64Le(id_114) };
              let_res_111 = id_115;
            }
            choose_res_58 = let_res_111;
          } else {
            uint16_t id_116 { 3 };
            uint16_t id_117 { uint16_t((*p_0).index()) };
            bool id_118 { bool(id_116 == id_117) };
            Pointer choose_res_119;
            if (id_118) {
              auto fun120 { dessser::gen::sync_key::to_row_binary };
              ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_121 { std::get<3 /* NewKey */>((*p_0)) };
              dessser::gen::sync_key::t_ext id_122 { id_121.NewKey_k };
              Pointer id_123 { fun120(id_122, ssum_dst_267) };
              Pointer let_res_124;
              {
                Pointer srec_dst_275 { id_123 };
                auto fun125 { dessser::gen::sync_value::to_row_binary };
                ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_126 { std::get<3 /* NewKey */>((*p_0)) };
                dessser::gen::sync_value::t_ext id_127 { id_126.v };
                Pointer id_128 { fun125(id_127, srec_dst_275) };
                let_res_124 = id_128;
              }
              Pointer let_res_129;
              {
                Pointer srec_dst_276 { let_res_124 };
                ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_130 { std::get<3 /* NewKey */>((*p_0)) };
                std::string id_131 { id_130.NewKey_uid };
                uint32_t id_132 { (uint32_t)id_131.size() };
                Vec<1, uint32_t> id_133 {  id_132  };
                Pointer let_res_134;
                {
                  Vec<1, uint32_t> leb128_sz_277 { id_133 };
                  Vec<1, Pointer> id_135 {  srec_dst_276  };
                  Pointer let_res_136;
                  {
                    Vec<1, Pointer> leb128_ptr_278 { id_135 };
                    bool while_flag_137 { true };
                    do {
                      uint8_t id_138 { 0 };
                      uint8_t id_139 { 0 };
                      Pointer id_140 { leb128_ptr_278[id_139] };
                      uint32_t id_141 { 128U };
                      uint8_t id_142 { 0 };
                      uint32_t id_143 { leb128_sz_277[id_142] };
                      bool id_144 { bool(id_141 > id_143) };
                      uint8_t choose_res_145;
                      if (id_144) {
                        uint8_t id_146 { 0 };
                        uint32_t id_147 { leb128_sz_277[id_146] };
                        uint8_t id_148 { uint8_t(id_147) };
                        choose_res_145 = id_148;
                      } else {
                        uint8_t id_149 { 0 };
                        uint32_t id_150 { leb128_sz_277[id_149] };
                        uint8_t id_151 { uint8_t(id_150) };
                        uint8_t id_152 { 128 };
                        uint8_t id_153 { uint8_t(id_151 | id_152) };
                        choose_res_145 = id_153;
                      }
                      Pointer id_154 { id_140.writeU8(choose_res_145) };
                      Void id_155 { ((void)(leb128_ptr_278[id_138] = id_154), ::dessser::VOID) };
                      (void)id_155;
                      uint8_t id_156 { 0 };
                      uint8_t id_157 { 0 };
                      uint32_t id_158 { leb128_sz_277[id_157] };
                      uint8_t id_159 { 7 };
                      uint32_t id_160 { uint32_t(id_158 >> id_159) };
                      Void id_161 { ((void)(leb128_sz_277[id_156] = id_160), ::dessser::VOID) };
                      (void)id_161;
                      uint8_t id_162 { 0 };
                      uint32_t id_163 { leb128_sz_277[id_162] };
                      uint32_t id_164 { 0U };
                      bool id_165 { bool(id_163 > id_164) };
                      while_flag_137 = id_165;
                      if (while_flag_137) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_137);
                    (void)::dessser::VOID;
                    uint8_t id_166 { 0 };
                    Pointer id_167 { leb128_ptr_278[id_166] };
                    let_res_136 = id_167;
                  }
                  let_res_134 = let_res_136;
                }
                ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_168 { std::get<3 /* NewKey */>((*p_0)) };
                std::string id_169 { id_168.NewKey_uid };
                Bytes id_170 { id_169 };
                Pointer id_171 { let_res_134.writeBytes(id_170) };
                let_res_129 = id_171;
              }
              Pointer let_res_172;
              {
                Pointer srec_dst_279 { let_res_129 };
                ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_173 { std::get<3 /* NewKey */>((*p_0)) };
                double id_174 { id_173.mtime };
                uint64_t id_175 { qword_of_float(id_174) };
                Pointer id_176 { srec_dst_279.writeU64Le(id_175) };
                let_res_172 = id_176;
              }
              Pointer let_res_177;
              {
                Pointer srec_dst_280 { let_res_172 };
                ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_178 { std::get<3 /* NewKey */>((*p_0)) };
                bool id_179 { id_178.can_write };
                uint8_t id_180 { uint8_t(id_179) };
                Pointer id_181 { srec_dst_280.writeU8(id_180) };
                let_res_177 = id_181;
              }
              Pointer let_res_182;
              {
                Pointer srec_dst_281 { let_res_177 };
                ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_183 { std::get<3 /* NewKey */>((*p_0)) };
                bool id_184 { id_183.can_del };
                uint8_t id_185 { uint8_t(id_184) };
                Pointer id_186 { srec_dst_281.writeU8(id_185) };
                let_res_182 = id_186;
              }
              Pointer let_res_187;
              {
                Pointer srec_dst_282 { let_res_182 };
                ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_188 { std::get<3 /* NewKey */>((*p_0)) };
                std::string id_189 { id_188.NewKey_owner };
                uint32_t id_190 { (uint32_t)id_189.size() };
                Vec<1, uint32_t> id_191 {  id_190  };
                Pointer let_res_192;
                {
                  Vec<1, uint32_t> leb128_sz_283 { id_191 };
                  Vec<1, Pointer> id_193 {  srec_dst_282  };
                  Pointer let_res_194;
                  {
                    Vec<1, Pointer> leb128_ptr_284 { id_193 };
                    bool while_flag_195 { true };
                    do {
                      uint8_t id_196 { 0 };
                      uint8_t id_197 { 0 };
                      Pointer id_198 { leb128_ptr_284[id_197] };
                      uint32_t id_199 { 128U };
                      uint8_t id_200 { 0 };
                      uint32_t id_201 { leb128_sz_283[id_200] };
                      bool id_202 { bool(id_199 > id_201) };
                      uint8_t choose_res_203;
                      if (id_202) {
                        uint8_t id_204 { 0 };
                        uint32_t id_205 { leb128_sz_283[id_204] };
                        uint8_t id_206 { uint8_t(id_205) };
                        choose_res_203 = id_206;
                      } else {
                        uint8_t id_207 { 0 };
                        uint32_t id_208 { leb128_sz_283[id_207] };
                        uint8_t id_209 { uint8_t(id_208) };
                        uint8_t id_210 { 128 };
                        uint8_t id_211 { uint8_t(id_209 | id_210) };
                        choose_res_203 = id_211;
                      }
                      Pointer id_212 { id_198.writeU8(choose_res_203) };
                      Void id_213 { ((void)(leb128_ptr_284[id_196] = id_212), ::dessser::VOID) };
                      (void)id_213;
                      uint8_t id_214 { 0 };
                      uint8_t id_215 { 0 };
                      uint32_t id_216 { leb128_sz_283[id_215] };
                      uint8_t id_217 { 7 };
                      uint32_t id_218 { uint32_t(id_216 >> id_217) };
                      Void id_219 { ((void)(leb128_sz_283[id_214] = id_218), ::dessser::VOID) };
                      (void)id_219;
                      uint8_t id_220 { 0 };
                      uint32_t id_221 { leb128_sz_283[id_220] };
                      uint32_t id_222 { 0U };
                      bool id_223 { bool(id_221 > id_222) };
                      while_flag_195 = id_223;
                      if (while_flag_195) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_195);
                    (void)::dessser::VOID;
                    uint8_t id_224 { 0 };
                    Pointer id_225 { leb128_ptr_284[id_224] };
                    let_res_194 = id_225;
                  }
                  let_res_192 = let_res_194;
                }
                ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_226 { std::get<3 /* NewKey */>((*p_0)) };
                std::string id_227 { id_226.NewKey_owner };
                Bytes id_228 { id_227 };
                Pointer id_229 { let_res_192.writeBytes(id_228) };
                let_res_187 = id_229;
              }
              Pointer let_res_230;
              {
                Pointer srec_dst_285 { let_res_187 };
                ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_231 { std::get<3 /* NewKey */>((*p_0)) };
                double id_232 { id_231.NewKey_expiry };
                uint64_t id_233 { qword_of_float(id_232) };
                Pointer id_234 { srec_dst_285.writeU64Le(id_233) };
                let_res_230 = id_234;
              }
              choose_res_119 = let_res_230;
            } else {
              uint16_t id_235 { 4 };
              uint16_t id_236 { uint16_t((*p_0).index()) };
              bool id_237 { bool(id_235 == id_236) };
              Pointer choose_res_238;
              if (id_237) {
                auto fun239 { dessser::gen::sync_key::to_row_binary };
                ::dessser::gen::sync_server_msg::t08b27b0be3a89631db1d9e270c1e83bc id_240 { std::get<4 /* DelKey */>((*p_0)) };
                dessser::gen::sync_key::t_ext id_241 { id_240.DelKey_k };
                Pointer id_242 { fun239(id_241, ssum_dst_267) };
                Pointer let_res_243;
                {
                  Pointer srec_dst_272 { id_242 };
                  ::dessser::gen::sync_server_msg::t08b27b0be3a89631db1d9e270c1e83bc id_244 { std::get<4 /* DelKey */>((*p_0)) };
                  std::string id_245 { id_244.uid };
                  uint32_t id_246 { (uint32_t)id_245.size() };
                  Vec<1, uint32_t> id_247 {  id_246  };
                  Pointer let_res_248;
                  {
                    Vec<1, uint32_t> leb128_sz_273 { id_247 };
                    Vec<1, Pointer> id_249 {  srec_dst_272  };
                    Pointer let_res_250;
                    {
                      Vec<1, Pointer> leb128_ptr_274 { id_249 };
                      bool while_flag_251 { true };
                      do {
                        uint8_t id_252 { 0 };
                        uint8_t id_253 { 0 };
                        Pointer id_254 { leb128_ptr_274[id_253] };
                        uint32_t id_255 { 128U };
                        uint8_t id_256 { 0 };
                        uint32_t id_257 { leb128_sz_273[id_256] };
                        bool id_258 { bool(id_255 > id_257) };
                        uint8_t choose_res_259;
                        if (id_258) {
                          uint8_t id_260 { 0 };
                          uint32_t id_261 { leb128_sz_273[id_260] };
                          uint8_t id_262 { uint8_t(id_261) };
                          choose_res_259 = id_262;
                        } else {
                          uint8_t id_263 { 0 };
                          uint32_t id_264 { leb128_sz_273[id_263] };
                          uint8_t id_265 { uint8_t(id_264) };
                          uint8_t id_266 { 128 };
                          uint8_t id_267 { uint8_t(id_265 | id_266) };
                          choose_res_259 = id_267;
                        }
                        Pointer id_268 { id_254.writeU8(choose_res_259) };
                        Void id_269 { ((void)(leb128_ptr_274[id_252] = id_268), ::dessser::VOID) };
                        (void)id_269;
                        uint8_t id_270 { 0 };
                        uint8_t id_271 { 0 };
                        uint32_t id_272 { leb128_sz_273[id_271] };
                        uint8_t id_273 { 7 };
                        uint32_t id_274 { uint32_t(id_272 >> id_273) };
                        Void id_275 { ((void)(leb128_sz_273[id_270] = id_274), ::dessser::VOID) };
                        (void)id_275;
                        uint8_t id_276 { 0 };
                        uint32_t id_277 { leb128_sz_273[id_276] };
                        uint32_t id_278 { 0U };
                        bool id_279 { bool(id_277 > id_278) };
                        while_flag_251 = id_279;
                        if (while_flag_251) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_251);
                      (void)::dessser::VOID;
                      uint8_t id_280 { 0 };
                      Pointer id_281 { leb128_ptr_274[id_280] };
                      let_res_250 = id_281;
                    }
                    let_res_248 = let_res_250;
                  }
                  ::dessser::gen::sync_server_msg::t08b27b0be3a89631db1d9e270c1e83bc id_282 { std::get<4 /* DelKey */>((*p_0)) };
                  std::string id_283 { id_282.uid };
                  Bytes id_284 { id_283 };
                  Pointer id_285 { let_res_248.writeBytes(id_284) };
                  let_res_243 = id_285;
                }
                choose_res_238 = let_res_243;
              } else {
                uint16_t id_286 { 5 };
                uint16_t id_287 { uint16_t((*p_0).index()) };
                bool id_288 { bool(id_286 == id_287) };
                Pointer choose_res_289;
                if (id_288) {
                  auto fun290 { dessser::gen::sync_key::to_row_binary };
                  ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f id_291 { std::get<5 /* LockKey */>((*p_0)) };
                  dessser::gen::sync_key::t_ext id_292 { id_291.k };
                  Pointer id_293 { fun290(id_292, ssum_dst_267) };
                  Pointer let_res_294;
                  {
                    Pointer srec_dst_268 { id_293 };
                    ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f id_295 { std::get<5 /* LockKey */>((*p_0)) };
                    std::string id_296 { id_295.owner };
                    uint32_t id_297 { (uint32_t)id_296.size() };
                    Vec<1, uint32_t> id_298 {  id_297  };
                    Pointer let_res_299;
                    {
                      Vec<1, uint32_t> leb128_sz_269 { id_298 };
                      Vec<1, Pointer> id_300 {  srec_dst_268  };
                      Pointer let_res_301;
                      {
                        Vec<1, Pointer> leb128_ptr_270 { id_300 };
                        bool while_flag_302 { true };
                        do {
                          uint8_t id_303 { 0 };
                          uint8_t id_304 { 0 };
                          Pointer id_305 { leb128_ptr_270[id_304] };
                          uint32_t id_306 { 128U };
                          uint8_t id_307 { 0 };
                          uint32_t id_308 { leb128_sz_269[id_307] };
                          bool id_309 { bool(id_306 > id_308) };
                          uint8_t choose_res_310;
                          if (id_309) {
                            uint8_t id_311 { 0 };
                            uint32_t id_312 { leb128_sz_269[id_311] };
                            uint8_t id_313 { uint8_t(id_312) };
                            choose_res_310 = id_313;
                          } else {
                            uint8_t id_314 { 0 };
                            uint32_t id_315 { leb128_sz_269[id_314] };
                            uint8_t id_316 { uint8_t(id_315) };
                            uint8_t id_317 { 128 };
                            uint8_t id_318 { uint8_t(id_316 | id_317) };
                            choose_res_310 = id_318;
                          }
                          Pointer id_319 { id_305.writeU8(choose_res_310) };
                          Void id_320 { ((void)(leb128_ptr_270[id_303] = id_319), ::dessser::VOID) };
                          (void)id_320;
                          uint8_t id_321 { 0 };
                          uint8_t id_322 { 0 };
                          uint32_t id_323 { leb128_sz_269[id_322] };
                          uint8_t id_324 { 7 };
                          uint32_t id_325 { uint32_t(id_323 >> id_324) };
                          Void id_326 { ((void)(leb128_sz_269[id_321] = id_325), ::dessser::VOID) };
                          (void)id_326;
                          uint8_t id_327 { 0 };
                          uint32_t id_328 { leb128_sz_269[id_327] };
                          uint32_t id_329 { 0U };
                          bool id_330 { bool(id_328 > id_329) };
                          while_flag_302 = id_330;
                          if (while_flag_302) {
                            (void)::dessser::VOID;
                          }
                        } while (while_flag_302);
                        (void)::dessser::VOID;
                        uint8_t id_331 { 0 };
                        Pointer id_332 { leb128_ptr_270[id_331] };
                        let_res_301 = id_332;
                      }
                      let_res_299 = let_res_301;
                    }
                    ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f id_333 { std::get<5 /* LockKey */>((*p_0)) };
                    std::string id_334 { id_333.owner };
                    Bytes id_335 { id_334 };
                    Pointer id_336 { let_res_299.writeBytes(id_335) };
                    let_res_294 = id_336;
                  }
                  Pointer let_res_337;
                  {
                    Pointer srec_dst_271 { let_res_294 };
                    ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f id_338 { std::get<5 /* LockKey */>((*p_0)) };
                    double id_339 { id_338.expiry };
                    uint64_t id_340 { qword_of_float(id_339) };
                    Pointer id_341 { srec_dst_271.writeU64Le(id_340) };
                    let_res_337 = id_341;
                  }
                  choose_res_289 = let_res_337;
                } else {
                  uint16_t id_342 { uint16_t((*p_0).index()) };
                  uint16_t id_343 { 6 };
                  bool id_344 { bool(id_342 == id_343) };
                  Void id_345 { ((void)(assert(id_344)), ::dessser::VOID) };
                  (void)id_345;
                  auto fun346 { dessser::gen::sync_key::to_row_binary };
                  dessser::gen::sync_key::t_ext id_347 { std::get<6 /* UnlockKey */>((*p_0)) };
                  Pointer id_348 { fun346(id_347, ssum_dst_267) };
                  choose_res_289 = id_348;
                }
                choose_res_238 = choose_res_289;
              }
              choose_res_119 = choose_res_238;
            }
            choose_res_58 = choose_res_119;
          }
          choose_res_14 = choose_res_58;
        }
        choose_res_7 = choose_res_14;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_server_msg::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]")
      (if (eq (u16 0) (label-of (param 0))) (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (get-alt "AuthOk" (param 0))))
        (if (eq (u16 1) (label-of (param 0)))
          (add (size 2)
            (add
              (let "n_ref_264" (make-vec (string-length (get-alt "AuthErr" (param 0))))
                (let "lebsz_ref_265" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_264")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_265")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_265") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_265")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_265")))))) 
              (size-of-u32 (string-length (get-alt "AuthErr" (param 0))))))
          (if (eq (u16 2) (label-of (param 0)))
            (add
              (let "sz_258"
                (let "sz_257" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-field "k" (get-alt "SetKey" (param 0)))))
                  (add (identifier "sz_257") (apply (ext-identifier sync_value sersize-of-row-binary) (get-field "v" (get-alt "SetKey" (param 0))))))
                (add (identifier "sz_258")
                  (add
                    (let "n_ref_260" (make-vec (string-length (get-field "uid" (get-alt "SetKey" (param 0)))))
                      (let "lebsz_ref_261" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_260")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_261")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_261") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_261")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_261")))))) 
                    (size-of-u32 (string-length (get-field "uid" (get-alt "SetKey" (param 0)))))))) 
              (size 8))
            (if (eq (u16 3) (label-of (param 0)))
              (add
                (let "sz_251"
                  (add
                    (add
                      (add
                        (let "sz_244"
                          (let "sz_243" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-field "k" (get-alt "NewKey" (param 0)))))
                            (add (identifier "sz_243") (apply (ext-identifier sync_value sersize-of-row-binary) (get-field "v" (get-alt "NewKey" (param 0))))))
                          (add (identifier "sz_244")
                            (add
                              (let "n_ref_246" (make-vec (string-length (get-field "uid" (get-alt "NewKey" (param 0)))))
                                (let "lebsz_ref_247" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_246")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_247")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_247") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_247")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_247")))))) 
                              (size-of-u32 (string-length (get-field "uid" (get-alt "NewKey" (param 0)))))))) 
                        (size 8)) (size 1)) (size 1))
                  (add (identifier "sz_251")
                    (add
                      (let "n_ref_253" (make-vec (string-length (get-field "owner" (get-alt "NewKey" (param 0)))))
                        (let "lebsz_ref_254" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_253")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_254")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_254") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_254")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_254")))))) 
                      (size-of-u32 (string-length (get-field "owner" (get-alt "NewKey" (param 0)))))))) 
                (size 8))
              (if (eq (u16 4) (label-of (param 0)))
                (let "sz_238" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-field "k" (get-alt "DelKey" (param 0)))))
                  (add (identifier "sz_238")
                    (add
                      (let "n_ref_240" (make-vec (string-length (get-field "uid" (get-alt "DelKey" (param 0)))))
                        (let "lebsz_ref_241" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_240")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_241")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_241") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_241")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_241")))))) 
                      (size-of-u32 (string-length (get-field "uid" (get-alt "DelKey" (param 0))))))))
                (if (eq (u16 5) (label-of (param 0)))
                  (add
                    (let "sz_232" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-field "k" (get-alt "LockKey" (param 0)))))
                      (add (identifier "sz_232")
                        (add
                          (let "n_ref_234" (make-vec (string-length (get-field "owner" (get-alt "LockKey" (param 0)))))
                            (let "lebsz_ref_235" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_234")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_235")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_235") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_235")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_235")))))) 
                          (size-of-u32 (string-length (get-field "owner" (get-alt "LockKey" (param 0)))))))) 
                    (size 8)) (seq (assert (eq (label-of (param 0)) (u16 6))) (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-alt "UnlockKey" (param 0))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_server_msg::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_server_msg::t> )> fun349 { [&fun349](std::shared_ptr<::dessser::gen::sync_server_msg::t>  p_0) {
    uint16_t id_350 { 0 };
    uint16_t id_351 { uint16_t((*p_0).index()) };
    bool id_352 { bool(id_350 == id_351) };
    Size choose_res_353;
    if (id_352) {
      Size id_354 { 2UL };
      auto fun355 { dessser::gen::sync_socket::sersize_of_row_binary };
      dessser::gen::sync_socket::t_ext id_356 { std::get<0 /* AuthOk */>((*p_0)) };
      Size id_357 { fun355(id_356) };
      Size id_358 { Size(id_354 + id_357) };
      choose_res_353 = id_358;
    } else {
      uint16_t id_359 { 1 };
      uint16_t id_360 { uint16_t((*p_0).index()) };
      bool id_361 { bool(id_359 == id_360) };
      Size choose_res_362;
      if (id_361) {
        Size id_363 { 2UL };
        std::string id_364 { std::get<1 /* AuthErr */>((*p_0)) };
        uint32_t id_365 { (uint32_t)id_364.size() };
        Vec<1, uint32_t> id_366 {  id_365  };
        Size let_res_367;
        {
          Vec<1, uint32_t> n_ref_264 { id_366 };
          uint32_t id_368 { 1U };
          Vec<1, uint32_t> id_369 {  id_368  };
          Size let_res_370;
          {
            Vec<1, uint32_t> lebsz_ref_265 { id_369 };
            bool while_flag_371 { true };
            do {
              uint8_t id_372 { 0 };
              uint32_t id_373 { n_ref_264[id_372] };
              uint8_t id_374 { 0 };
              uint32_t id_375 { lebsz_ref_265[id_374] };
              uint8_t id_376 { 7 };
              uint32_t id_377 { uint32_t(id_375 << id_376) };
              bool id_378 { bool(id_373 >= id_377) };
              while_flag_371 = id_378;
              if (while_flag_371) {
                uint8_t id_379 { 0 };
                uint8_t id_380 { 0 };
                uint32_t id_381 { lebsz_ref_265[id_380] };
                uint32_t id_382 { 1U };
                uint32_t id_383 { uint32_t(id_381 + id_382) };
                Void id_384 { ((void)(lebsz_ref_265[id_379] = id_383), ::dessser::VOID) };
                (void)id_384;
              }
            } while (while_flag_371);
            (void)::dessser::VOID;
            uint8_t id_385 { 0 };
            uint32_t id_386 { lebsz_ref_265[id_385] };
            Size id_387 { Size(id_386) };
            let_res_370 = id_387;
          }
          let_res_367 = let_res_370;
        }
        std::string id_388 { std::get<1 /* AuthErr */>((*p_0)) };
        uint32_t id_389 { (uint32_t)id_388.size() };
        Size id_390 { Size(id_389) };
        Size id_391 { Size(let_res_367 + id_390) };
        Size id_392 { Size(id_363 + id_391) };
        choose_res_362 = id_392;
      } else {
        uint16_t id_393 { 2 };
        uint16_t id_394 { uint16_t((*p_0).index()) };
        bool id_395 { bool(id_393 == id_394) };
        Size choose_res_396;
        if (id_395) {
          Size id_397 { 2UL };
          auto fun398 { dessser::gen::sync_key::sersize_of_row_binary };
          ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_399 { std::get<2 /* SetKey */>((*p_0)) };
          dessser::gen::sync_key::t_ext id_400 { id_399.SetKey_k };
          Size id_401 { fun398(id_400) };
          Size id_402 { Size(id_397 + id_401) };
          Size let_res_403;
          {
            Size sz_257 { id_402 };
            auto fun404 { dessser::gen::sync_value::sersize_of_row_binary };
            ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_405 { std::get<2 /* SetKey */>((*p_0)) };
            dessser::gen::sync_value::t_ext id_406 { id_405.SetKey_v };
            Size id_407 { fun404(id_406) };
            Size id_408 { Size(sz_257 + id_407) };
            let_res_403 = id_408;
          }
          Size let_res_409;
          {
            Size sz_258 { let_res_403 };
            ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_410 { std::get<2 /* SetKey */>((*p_0)) };
            std::string id_411 { id_410.SetKey_uid };
            uint32_t id_412 { (uint32_t)id_411.size() };
            Vec<1, uint32_t> id_413 {  id_412  };
            Size let_res_414;
            {
              Vec<1, uint32_t> n_ref_260 { id_413 };
              uint32_t id_415 { 1U };
              Vec<1, uint32_t> id_416 {  id_415  };
              Size let_res_417;
              {
                Vec<1, uint32_t> lebsz_ref_261 { id_416 };
                bool while_flag_418 { true };
                do {
                  uint8_t id_419 { 0 };
                  uint32_t id_420 { n_ref_260[id_419] };
                  uint8_t id_421 { 0 };
                  uint32_t id_422 { lebsz_ref_261[id_421] };
                  uint8_t id_423 { 7 };
                  uint32_t id_424 { uint32_t(id_422 << id_423) };
                  bool id_425 { bool(id_420 >= id_424) };
                  while_flag_418 = id_425;
                  if (while_flag_418) {
                    uint8_t id_426 { 0 };
                    uint8_t id_427 { 0 };
                    uint32_t id_428 { lebsz_ref_261[id_427] };
                    uint32_t id_429 { 1U };
                    uint32_t id_430 { uint32_t(id_428 + id_429) };
                    Void id_431 { ((void)(lebsz_ref_261[id_426] = id_430), ::dessser::VOID) };
                    (void)id_431;
                  }
                } while (while_flag_418);
                (void)::dessser::VOID;
                uint8_t id_432 { 0 };
                uint32_t id_433 { lebsz_ref_261[id_432] };
                Size id_434 { Size(id_433) };
                let_res_417 = id_434;
              }
              let_res_414 = let_res_417;
            }
            ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_435 { std::get<2 /* SetKey */>((*p_0)) };
            std::string id_436 { id_435.SetKey_uid };
            uint32_t id_437 { (uint32_t)id_436.size() };
            Size id_438 { Size(id_437) };
            Size id_439 { Size(let_res_414 + id_438) };
            Size id_440 { Size(sz_258 + id_439) };
            let_res_409 = id_440;
          }
          Size id_441 { 8UL };
          Size id_442 { Size(let_res_409 + id_441) };
          choose_res_396 = id_442;
        } else {
          uint16_t id_443 { 3 };
          uint16_t id_444 { uint16_t((*p_0).index()) };
          bool id_445 { bool(id_443 == id_444) };
          Size choose_res_446;
          if (id_445) {
            Size id_447 { 2UL };
            auto fun448 { dessser::gen::sync_key::sersize_of_row_binary };
            ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_449 { std::get<3 /* NewKey */>((*p_0)) };
            dessser::gen::sync_key::t_ext id_450 { id_449.NewKey_k };
            Size id_451 { fun448(id_450) };
            Size id_452 { Size(id_447 + id_451) };
            Size let_res_453;
            {
              Size sz_243 { id_452 };
              auto fun454 { dessser::gen::sync_value::sersize_of_row_binary };
              ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_455 { std::get<3 /* NewKey */>((*p_0)) };
              dessser::gen::sync_value::t_ext id_456 { id_455.v };
              Size id_457 { fun454(id_456) };
              Size id_458 { Size(sz_243 + id_457) };
              let_res_453 = id_458;
            }
            Size let_res_459;
            {
              Size sz_244 { let_res_453 };
              ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_460 { std::get<3 /* NewKey */>((*p_0)) };
              std::string id_461 { id_460.NewKey_uid };
              uint32_t id_462 { (uint32_t)id_461.size() };
              Vec<1, uint32_t> id_463 {  id_462  };
              Size let_res_464;
              {
                Vec<1, uint32_t> n_ref_246 { id_463 };
                uint32_t id_465 { 1U };
                Vec<1, uint32_t> id_466 {  id_465  };
                Size let_res_467;
                {
                  Vec<1, uint32_t> lebsz_ref_247 { id_466 };
                  bool while_flag_468 { true };
                  do {
                    uint8_t id_469 { 0 };
                    uint32_t id_470 { n_ref_246[id_469] };
                    uint8_t id_471 { 0 };
                    uint32_t id_472 { lebsz_ref_247[id_471] };
                    uint8_t id_473 { 7 };
                    uint32_t id_474 { uint32_t(id_472 << id_473) };
                    bool id_475 { bool(id_470 >= id_474) };
                    while_flag_468 = id_475;
                    if (while_flag_468) {
                      uint8_t id_476 { 0 };
                      uint8_t id_477 { 0 };
                      uint32_t id_478 { lebsz_ref_247[id_477] };
                      uint32_t id_479 { 1U };
                      uint32_t id_480 { uint32_t(id_478 + id_479) };
                      Void id_481 { ((void)(lebsz_ref_247[id_476] = id_480), ::dessser::VOID) };
                      (void)id_481;
                    }
                  } while (while_flag_468);
                  (void)::dessser::VOID;
                  uint8_t id_482 { 0 };
                  uint32_t id_483 { lebsz_ref_247[id_482] };
                  Size id_484 { Size(id_483) };
                  let_res_467 = id_484;
                }
                let_res_464 = let_res_467;
              }
              ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_485 { std::get<3 /* NewKey */>((*p_0)) };
              std::string id_486 { id_485.NewKey_uid };
              uint32_t id_487 { (uint32_t)id_486.size() };
              Size id_488 { Size(id_487) };
              Size id_489 { Size(let_res_464 + id_488) };
              Size id_490 { Size(sz_244 + id_489) };
              let_res_459 = id_490;
            }
            Size id_491 { 8UL };
            Size id_492 { Size(let_res_459 + id_491) };
            Size id_493 { 1UL };
            Size id_494 { Size(id_492 + id_493) };
            Size id_495 { 1UL };
            Size id_496 { Size(id_494 + id_495) };
            Size let_res_497;
            {
              Size sz_251 { id_496 };
              ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_498 { std::get<3 /* NewKey */>((*p_0)) };
              std::string id_499 { id_498.NewKey_owner };
              uint32_t id_500 { (uint32_t)id_499.size() };
              Vec<1, uint32_t> id_501 {  id_500  };
              Size let_res_502;
              {
                Vec<1, uint32_t> n_ref_253 { id_501 };
                uint32_t id_503 { 1U };
                Vec<1, uint32_t> id_504 {  id_503  };
                Size let_res_505;
                {
                  Vec<1, uint32_t> lebsz_ref_254 { id_504 };
                  bool while_flag_506 { true };
                  do {
                    uint8_t id_507 { 0 };
                    uint32_t id_508 { n_ref_253[id_507] };
                    uint8_t id_509 { 0 };
                    uint32_t id_510 { lebsz_ref_254[id_509] };
                    uint8_t id_511 { 7 };
                    uint32_t id_512 { uint32_t(id_510 << id_511) };
                    bool id_513 { bool(id_508 >= id_512) };
                    while_flag_506 = id_513;
                    if (while_flag_506) {
                      uint8_t id_514 { 0 };
                      uint8_t id_515 { 0 };
                      uint32_t id_516 { lebsz_ref_254[id_515] };
                      uint32_t id_517 { 1U };
                      uint32_t id_518 { uint32_t(id_516 + id_517) };
                      Void id_519 { ((void)(lebsz_ref_254[id_514] = id_518), ::dessser::VOID) };
                      (void)id_519;
                    }
                  } while (while_flag_506);
                  (void)::dessser::VOID;
                  uint8_t id_520 { 0 };
                  uint32_t id_521 { lebsz_ref_254[id_520] };
                  Size id_522 { Size(id_521) };
                  let_res_505 = id_522;
                }
                let_res_502 = let_res_505;
              }
              ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_523 { std::get<3 /* NewKey */>((*p_0)) };
              std::string id_524 { id_523.NewKey_owner };
              uint32_t id_525 { (uint32_t)id_524.size() };
              Size id_526 { Size(id_525) };
              Size id_527 { Size(let_res_502 + id_526) };
              Size id_528 { Size(sz_251 + id_527) };
              let_res_497 = id_528;
            }
            Size id_529 { 8UL };
            Size id_530 { Size(let_res_497 + id_529) };
            choose_res_446 = id_530;
          } else {
            uint16_t id_531 { 4 };
            uint16_t id_532 { uint16_t((*p_0).index()) };
            bool id_533 { bool(id_531 == id_532) };
            Size choose_res_534;
            if (id_533) {
              Size id_535 { 2UL };
              auto fun536 { dessser::gen::sync_key::sersize_of_row_binary };
              ::dessser::gen::sync_server_msg::t08b27b0be3a89631db1d9e270c1e83bc id_537 { std::get<4 /* DelKey */>((*p_0)) };
              dessser::gen::sync_key::t_ext id_538 { id_537.DelKey_k };
              Size id_539 { fun536(id_538) };
              Size id_540 { Size(id_535 + id_539) };
              Size let_res_541;
              {
                Size sz_238 { id_540 };
                ::dessser::gen::sync_server_msg::t08b27b0be3a89631db1d9e270c1e83bc id_542 { std::get<4 /* DelKey */>((*p_0)) };
                std::string id_543 { id_542.uid };
                uint32_t id_544 { (uint32_t)id_543.size() };
                Vec<1, uint32_t> id_545 {  id_544  };
                Size let_res_546;
                {
                  Vec<1, uint32_t> n_ref_240 { id_545 };
                  uint32_t id_547 { 1U };
                  Vec<1, uint32_t> id_548 {  id_547  };
                  Size let_res_549;
                  {
                    Vec<1, uint32_t> lebsz_ref_241 { id_548 };
                    bool while_flag_550 { true };
                    do {
                      uint8_t id_551 { 0 };
                      uint32_t id_552 { n_ref_240[id_551] };
                      uint8_t id_553 { 0 };
                      uint32_t id_554 { lebsz_ref_241[id_553] };
                      uint8_t id_555 { 7 };
                      uint32_t id_556 { uint32_t(id_554 << id_555) };
                      bool id_557 { bool(id_552 >= id_556) };
                      while_flag_550 = id_557;
                      if (while_flag_550) {
                        uint8_t id_558 { 0 };
                        uint8_t id_559 { 0 };
                        uint32_t id_560 { lebsz_ref_241[id_559] };
                        uint32_t id_561 { 1U };
                        uint32_t id_562 { uint32_t(id_560 + id_561) };
                        Void id_563 { ((void)(lebsz_ref_241[id_558] = id_562), ::dessser::VOID) };
                        (void)id_563;
                      }
                    } while (while_flag_550);
                    (void)::dessser::VOID;
                    uint8_t id_564 { 0 };
                    uint32_t id_565 { lebsz_ref_241[id_564] };
                    Size id_566 { Size(id_565) };
                    let_res_549 = id_566;
                  }
                  let_res_546 = let_res_549;
                }
                ::dessser::gen::sync_server_msg::t08b27b0be3a89631db1d9e270c1e83bc id_567 { std::get<4 /* DelKey */>((*p_0)) };
                std::string id_568 { id_567.uid };
                uint32_t id_569 { (uint32_t)id_568.size() };
                Size id_570 { Size(id_569) };
                Size id_571 { Size(let_res_546 + id_570) };
                Size id_572 { Size(sz_238 + id_571) };
                let_res_541 = id_572;
              }
              choose_res_534 = let_res_541;
            } else {
              uint16_t id_573 { 5 };
              uint16_t id_574 { uint16_t((*p_0).index()) };
              bool id_575 { bool(id_573 == id_574) };
              Size choose_res_576;
              if (id_575) {
                Size id_577 { 2UL };
                auto fun578 { dessser::gen::sync_key::sersize_of_row_binary };
                ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f id_579 { std::get<5 /* LockKey */>((*p_0)) };
                dessser::gen::sync_key::t_ext id_580 { id_579.k };
                Size id_581 { fun578(id_580) };
                Size id_582 { Size(id_577 + id_581) };
                Size let_res_583;
                {
                  Size sz_232 { id_582 };
                  ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f id_584 { std::get<5 /* LockKey */>((*p_0)) };
                  std::string id_585 { id_584.owner };
                  uint32_t id_586 { (uint32_t)id_585.size() };
                  Vec<1, uint32_t> id_587 {  id_586  };
                  Size let_res_588;
                  {
                    Vec<1, uint32_t> n_ref_234 { id_587 };
                    uint32_t id_589 { 1U };
                    Vec<1, uint32_t> id_590 {  id_589  };
                    Size let_res_591;
                    {
                      Vec<1, uint32_t> lebsz_ref_235 { id_590 };
                      bool while_flag_592 { true };
                      do {
                        uint8_t id_593 { 0 };
                        uint32_t id_594 { n_ref_234[id_593] };
                        uint8_t id_595 { 0 };
                        uint32_t id_596 { lebsz_ref_235[id_595] };
                        uint8_t id_597 { 7 };
                        uint32_t id_598 { uint32_t(id_596 << id_597) };
                        bool id_599 { bool(id_594 >= id_598) };
                        while_flag_592 = id_599;
                        if (while_flag_592) {
                          uint8_t id_600 { 0 };
                          uint8_t id_601 { 0 };
                          uint32_t id_602 { lebsz_ref_235[id_601] };
                          uint32_t id_603 { 1U };
                          uint32_t id_604 { uint32_t(id_602 + id_603) };
                          Void id_605 { ((void)(lebsz_ref_235[id_600] = id_604), ::dessser::VOID) };
                          (void)id_605;
                        }
                      } while (while_flag_592);
                      (void)::dessser::VOID;
                      uint8_t id_606 { 0 };
                      uint32_t id_607 { lebsz_ref_235[id_606] };
                      Size id_608 { Size(id_607) };
                      let_res_591 = id_608;
                    }
                    let_res_588 = let_res_591;
                  }
                  ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f id_609 { std::get<5 /* LockKey */>((*p_0)) };
                  std::string id_610 { id_609.owner };
                  uint32_t id_611 { (uint32_t)id_610.size() };
                  Size id_612 { Size(id_611) };
                  Size id_613 { Size(let_res_588 + id_612) };
                  Size id_614 { Size(sz_232 + id_613) };
                  let_res_583 = id_614;
                }
                Size id_615 { 8UL };
                Size id_616 { Size(let_res_583 + id_615) };
                choose_res_576 = id_616;
              } else {
                uint16_t id_617 { uint16_t((*p_0).index()) };
                uint16_t id_618 { 6 };
                bool id_619 { bool(id_617 == id_618) };
                Void id_620 { ((void)(assert(id_619)), ::dessser::VOID) };
                (void)id_620;
                Size id_621 { 2UL };
                auto fun622 { dessser::gen::sync_key::sersize_of_row_binary };
                dessser::gen::sync_key::t_ext id_623 { std::get<6 /* UnlockKey */>((*p_0)) };
                Size id_624 { fun622(id_623) };
                Size id_625 { Size(id_621 + id_624) };
                choose_res_576 = id_625;
              }
              choose_res_534 = choose_res_576;
            }
            choose_res_446 = choose_res_534;
          }
          choose_res_396 = choose_res_446;
        }
        choose_res_362 = choose_res_396;
      }
      choose_res_353 = choose_res_362;
    }
    return choose_res_353;
  }
   };
  return fun349;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_server_msg::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
          (if (eq (u16 0) (identifier "dsum1_fst_63"))
            (let-pair "dsum2_fst_225" "dsum2_snd_226" (apply (ext-identifier sync_socket of-row-binary) (identifier "dsum1_snd_64"))
              (make-tup
                (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 0
                  (identifier "dsum2_fst_225")) (identifier "dsum2_snd_226")))
            (if (eq (u16 1) (identifier "dsum1_fst_63"))
              (let "dstring1_215"
                (let "leb_ref_209" (make-vec (u32 0))
                  (let "shft_ref_210" (make-vec (u8 0))
                    (let "p_ref_211" (make-vec (identifier "dsum1_snd_64"))
                      (seq
                        (while
                          (let "leb128_212" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_211")))
                            (let-pair "leb128_fst_213" "leb128_snd_214" 
                              (identifier "leb128_212")
                              (seq (set-vec (u8 0) (identifier "p_ref_211") (identifier "leb128_snd_214"))
                                (set-vec (u8 0) (identifier "leb_ref_209")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_213") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_210"))) (unsafe-nth (u8 0) (identifier "leb_ref_209"))))
                                (set-vec (u8 0) (identifier "shft_ref_210") (add (unsafe-nth (u8 0) (identifier "shft_ref_210")) (u8 7))) 
                                (ge (identifier "leb128_fst_213") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_209"))) (unsafe-nth (u8 0) (identifier "p_ref_211")))))))
                (let-pair "dstring1_fst_216" "dstring1_snd_217" (identifier "dstring1_215")
                  (let-pair "dstring2_fst_219" "dstring2_snd_220" (read-bytes (identifier "dstring1_snd_217") (identifier "dstring1_fst_216"))
                    (make-tup
                      (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 1
                        (string-of-bytes (identifier "dstring2_fst_219"))) 
                      (identifier "dstring2_snd_220")))))
              (if (eq (u16 2) (identifier "dsum1_fst_63"))
                (let "drec_179" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                  (let-pair "drec_fst_180" "drec_snd_181" (identifier "drec_179")
                    (let "drec_182" (apply (ext-identifier sync_value of-row-binary) (identifier "drec_snd_181"))
                      (let-pair "drec_fst_183" "drec_snd_184" (identifier "drec_182")
                        (let "drec_197"
                          (let "dstring1_191"
                            (let "leb_ref_185" (make-vec (u32 0))
                              (let "shft_ref_186" (make-vec (u8 0))
                                (let "p_ref_187" (make-vec (identifier "drec_snd_184"))
                                  (seq
                                    (while
                                      (let "leb128_188" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_187")))
                                        (let-pair "leb128_fst_189" "leb128_snd_190" 
                                          (identifier "leb128_188")
                                          (seq (set-vec (u8 0) (identifier "p_ref_187") (identifier "leb128_snd_190"))
                                            (set-vec (u8 0) (identifier "leb_ref_185")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_189") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_186"))) (unsafe-nth (u8 0) (identifier "leb_ref_185"))))
                                            (set-vec (u8 0) (identifier "shft_ref_186") (add (unsafe-nth (u8 0) (identifier "shft_ref_186")) (u8 7))) 
                                            (ge (identifier "leb128_fst_189") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_185"))) (unsafe-nth (u8 0) (identifier "p_ref_187")))))))
                            (let-pair "dstring1_fst_192" "dstring1_snd_193" 
                              (identifier "dstring1_191")
                              (let-pair "dstring2_fst_195" "dstring2_snd_196" 
                                (read-bytes (identifier "dstring1_snd_193") (identifier "dstring1_fst_192")) 
                                (make-tup (string-of-bytes (identifier "dstring2_fst_195")) (identifier "dstring2_snd_196")))))
                          (let-pair "drec_fst_198" "drec_snd_199" (identifier "drec_197")
                            (let-pair "dfloat_fst_201" "dfloat_snd_202" 
                              (read-u64 little-endian (identifier "drec_snd_199"))
                              (make-tup
                                (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 2
                                  (make-rec (string "mtime") (float-of-u64 (identifier "dfloat_fst_201")) 
                                    (string "uid") (identifier "drec_fst_198") 
                                    (string "v") (identifier "drec_fst_183") 
                                    (string "k") (identifier "drec_fst_180"))) 
                                (identifier "dfloat_snd_202")))))))))
                (if (eq (u16 3) (identifier "dsum1_fst_63"))
                  (let "drec_116" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                    (let-pair "drec_fst_117" "drec_snd_118" (identifier "drec_116")
                      (let "drec_119" (apply (ext-identifier sync_value of-row-binary) (identifier "drec_snd_118"))
                        (let-pair "drec_fst_120" "drec_snd_121" (identifier "drec_119")
                          (let "drec_134"
                            (let "dstring1_128"
                              (let "leb_ref_122" (make-vec (u32 0))
                                (let "shft_ref_123" (make-vec (u8 0))
                                  (let "p_ref_124" (make-vec (identifier "drec_snd_121"))
                                    (seq
                                      (while
                                        (let "leb128_125" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_124")))
                                          (let-pair "leb128_fst_126" "leb128_snd_127" 
                                            (identifier "leb128_125")
                                            (seq (set-vec (u8 0) (identifier "p_ref_124") (identifier "leb128_snd_127"))
                                              (set-vec (u8 0) (identifier "leb_ref_122")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_126") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_123"))) (unsafe-nth (u8 0) (identifier "leb_ref_122"))))
                                              (set-vec (u8 0) (identifier "shft_ref_123") (add (unsafe-nth (u8 0) (identifier "shft_ref_123")) (u8 7))) 
                                              (ge (identifier "leb128_fst_126") (u8 128))))) 
                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_122"))) (unsafe-nth (u8 0) (identifier "p_ref_124")))))))
                              (let-pair "dstring1_fst_129" "dstring1_snd_130" 
                                (identifier "dstring1_128")
                                (let-pair "dstring2_fst_132" "dstring2_snd_133" 
                                  (read-bytes (identifier "dstring1_snd_130") (identifier "dstring1_fst_129")) 
                                  (make-tup (string-of-bytes (identifier "dstring2_fst_132")) (identifier "dstring2_snd_133")))))
                            (let-pair "drec_fst_135" "drec_snd_136" (identifier "drec_134")
                              (let "drec_140" (let-pair "dfloat_fst_138" "dfloat_snd_139" (read-u64 little-endian (identifier "drec_snd_136")) (make-tup (float-of-u64 (identifier "dfloat_fst_138")) (identifier "dfloat_snd_139")))
                                (let-pair "drec_fst_141" "drec_snd_142" 
                                  (identifier "drec_140")
                                  (let "drec_146" (let-pair "dbool_fst_144" "dbool_snd_145" (read-u8 (identifier "drec_snd_142")) (make-tup (not (eq (identifier "dbool_fst_144") (u8 0))) (identifier "dbool_snd_145")))
                                    (let-pair "drec_fst_147" "drec_snd_148" 
                                      (identifier "drec_146")
                                      (let "drec_152" (let-pair "dbool_fst_150" "dbool_snd_151" (read-u8 (identifier "drec_snd_148")) (make-tup (not (eq (identifier "dbool_fst_150") (u8 0))) (identifier "dbool_snd_151")))
                                        (let-pair "drec_fst_153" "drec_snd_154" 
                                          (identifier "drec_152")
                                          (let "drec_167"
                                            (let "dstring1_161"
                                              (let "leb_ref_155" (make-vec (u32 0))
                                                (let "shft_ref_156" (make-vec (u8 0))
                                                  (let "p_ref_157" (make-vec (identifier "drec_snd_154"))
                                                    (seq
                                                      (while
                                                        (let "leb128_158" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_157")))
                                                          (let-pair "leb128_fst_159" "leb128_snd_160" 
                                                            (identifier "leb128_158")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_157") (identifier "leb128_snd_160"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_155")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_159") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_156")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_155")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_156") (add (unsafe-nth (u8 0) (identifier "shft_ref_156")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_159") (u8 128))))) 
                                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_155"))) (unsafe-nth (u8 0) (identifier "p_ref_157")))))))
                                              (let-pair "dstring1_fst_162" "dstring1_snd_163" 
                                                (identifier "dstring1_161")
                                                (let-pair "dstring2_fst_165" "dstring2_snd_166" 
                                                  (read-bytes (identifier "dstring1_snd_163") (identifier "dstring1_fst_162")) 
                                                  (make-tup (string-of-bytes (identifier "dstring2_fst_165")) (identifier "dstring2_snd_166")))))
                                            (let-pair "drec_fst_168" "drec_snd_169" 
                                              (identifier "drec_167")
                                              (let-pair "dfloat_fst_171" "dfloat_snd_172" 
                                                (read-u64 little-endian (identifier "drec_snd_169"))
                                                (make-tup
                                                  (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 3
                                                    (make-rec (string "expiry") 
                                                      (float-of-u64 (identifier "dfloat_fst_171")) 
                                                      (string "owner") 
                                                      (identifier "drec_fst_168") 
                                                      (string "can_del") 
                                                      (identifier "drec_fst_153") 
                                                      (string "can_write") 
                                                      (identifier "drec_fst_147") 
                                                      (string "mtime") 
                                                      (identifier "drec_fst_141") 
                                                      (string "uid") 
                                                      (identifier "drec_fst_135") 
                                                      (string "v") (identifier "drec_fst_120") 
                                                      (string "k") (identifier "drec_fst_117"))) 
                                                  (identifier "dfloat_snd_172")))))))))))))))))
                  (if (eq (u16 4) (identifier "dsum1_fst_63"))
                    (let "drec_95" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                      (let-pair "drec_fst_96" "drec_snd_97" (identifier "drec_95")
                        (let "dstring1_104"
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
                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_98"))) (unsafe-nth (u8 0) (identifier "p_ref_100")))))))
                          (let-pair "dstring1_fst_105" "dstring1_snd_106" 
                            (identifier "dstring1_104")
                            (let-pair "dstring2_fst_108" "dstring2_snd_109" 
                              (read-bytes (identifier "dstring1_snd_106") (identifier "dstring1_fst_105"))
                              (make-tup
                                (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 4
                                  (make-rec (string "uid") (string-of-bytes (identifier "dstring2_fst_108")) (string "k") (identifier "drec_fst_96"))) 
                                (identifier "dstring2_snd_109")))))))
                    (if (eq (u16 5) (identifier "dsum1_fst_63"))
                      (let "drec_68" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                        (let-pair "drec_fst_69" "drec_snd_70" (identifier "drec_68")
                          (let "drec_83"
                            (let "dstring1_77"
                              (let "leb_ref_71" (make-vec (u32 0))
                                (let "shft_ref_72" (make-vec (u8 0))
                                  (let "p_ref_73" (make-vec (identifier "drec_snd_70"))
                                    (seq
                                      (while
                                        (let "leb128_74" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_73")))
                                          (let-pair "leb128_fst_75" "leb128_snd_76" 
                                            (identifier "leb128_74")
                                            (seq (set-vec (u8 0) (identifier "p_ref_73") (identifier "leb128_snd_76"))
                                              (set-vec (u8 0) (identifier "leb_ref_71")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_75") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_72"))) (unsafe-nth (u8 0) (identifier "leb_ref_71"))))
                                              (set-vec (u8 0) (identifier "shft_ref_72") (add (unsafe-nth (u8 0) (identifier "shft_ref_72")) (u8 7))) 
                                              (ge (identifier "leb128_fst_75") (u8 128))))) 
                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_71"))) (unsafe-nth (u8 0) (identifier "p_ref_73")))))))
                              (let-pair "dstring1_fst_78" "dstring1_snd_79" 
                                (identifier "dstring1_77")
                                (let-pair "dstring2_fst_81" "dstring2_snd_82" 
                                  (read-bytes (identifier "dstring1_snd_79") (identifier "dstring1_fst_78")) 
                                  (make-tup (string-of-bytes (identifier "dstring2_fst_81")) (identifier "dstring2_snd_82")))))
                            (let-pair "drec_fst_84" "drec_snd_85" (identifier "drec_83")
                              (let-pair "dfloat_fst_87" "dfloat_snd_88" 
                                (read-u64 little-endian (identifier "drec_snd_85"))
                                (make-tup
                                  (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 5
                                    (make-rec (string "expiry") (float-of-u64 (identifier "dfloat_fst_87")) (string "owner") (identifier "drec_fst_84") (string "k") (identifier "drec_fst_69"))) 
                                  (identifier "dfloat_snd_88")))))))
                      (seq (assert (eq (identifier "dsum1_fst_63") (u16 6)))
                        (let-pair "dsum2_fst_66" "dsum2_snd_67" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_64"))
                          (make-tup
                            (construct "[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" 6
                              (identifier "dsum2_fst_66")) (identifier "dsum2_snd_67")))))))))))))
 */
static std::function<::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1(Pointer)> fun626 { [&fun626](Pointer p_0) {
    ::dessser::gen::sync_server_msg::ta97bb48ed75bbda6173555873826c8c6 id_627 { p_0.readU16Le() };
    ::dessser::gen::sync_server_msg::ta97bb48ed75bbda6173555873826c8c6 letpair_res_628;
    {
      auto du16_fst_57 { std::get<0>(id_627) };
      auto du16_snd_58 { std::get<1>(id_627) };
      ::dessser::gen::sync_server_msg::ta97bb48ed75bbda6173555873826c8c6 id_629 { du16_fst_57, du16_snd_58 };
      letpair_res_628 = id_629;
    }
    ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_630;
    {
      ::dessser::gen::sync_server_msg::ta97bb48ed75bbda6173555873826c8c6 dsum1_62 { letpair_res_628 };
      ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_631;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_632 { 0 };
        bool id_633 { bool(id_632 == dsum1_fst_63) };
        ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 choose_res_634;
        if (id_633) {
          auto fun635 { dessser::gen::sync_socket::of_row_binary };
          ::dessser::gen::sync_server_msg::tc3c0b466d06f5b0f1ffeebd3dab58a35 id_636 { fun635(dsum1_snd_64) };
          ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_637;
          {
            auto dsum2_fst_225 { std::get<0>(id_636) };
            auto dsum2_snd_226 { std::get<1>(id_636) };
            std::shared_ptr<::dessser::gen::sync_server_msg::t>  id_638 { std::make_shared<::dessser::gen::sync_server_msg::t>(std::in_place_index<0>, dsum2_fst_225) };
            ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 id_639 { id_638, dsum2_snd_226 };
            letpair_res_637 = id_639;
          }
          choose_res_634 = letpair_res_637;
        } else {
          uint16_t id_640 { 1 };
          bool id_641 { bool(id_640 == dsum1_fst_63) };
          ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 choose_res_642;
          if (id_641) {
            uint32_t id_643 { 0U };
            Vec<1, uint32_t> id_644 {  id_643  };
            ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_645;
            {
              Vec<1, uint32_t> leb_ref_209 { id_644 };
              uint8_t id_646 { 0 };
              Vec<1, uint8_t> id_647 {  id_646  };
              ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_648;
              {
                Vec<1, uint8_t> shft_ref_210 { id_647 };
                Vec<1, Pointer> id_649 {  dsum1_snd_64  };
                ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_650;
                {
                  Vec<1, Pointer> p_ref_211 { id_649 };
                  bool while_flag_651 { true };
                  do {
                    uint8_t id_652 { 0 };
                    Pointer id_653 { p_ref_211[id_652] };
                    ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 id_654 { id_653.readU8() };
                    bool let_res_655;
                    {
                      ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_212 { id_654 };
                      bool letpair_res_656;
                      {
                        auto leb128_fst_213 { std::get<0>(leb128_212) };
                        auto leb128_snd_214 { std::get<1>(leb128_212) };
                        uint8_t id_657 { 0 };
                        Void id_658 { ((void)(p_ref_211[id_657] = leb128_snd_214), ::dessser::VOID) };
                        (void)id_658;
                        uint8_t id_659 { 0 };
                        uint8_t id_660 { 127 };
                        uint8_t id_661 { uint8_t(leb128_fst_213 & id_660) };
                        uint32_t id_662 { uint32_t(id_661) };
                        uint8_t id_663 { 0 };
                        uint8_t id_664 { shft_ref_210[id_663] };
                        uint32_t id_665 { uint32_t(id_662 << id_664) };
                        uint8_t id_666 { 0 };
                        uint32_t id_667 { leb_ref_209[id_666] };
                        uint32_t id_668 { uint32_t(id_665 | id_667) };
                        Void id_669 { ((void)(leb_ref_209[id_659] = id_668), ::dessser::VOID) };
                        (void)id_669;
                        uint8_t id_670 { 0 };
                        uint8_t id_671 { 0 };
                        uint8_t id_672 { shft_ref_210[id_671] };
                        uint8_t id_673 { 7 };
                        uint8_t id_674 { uint8_t(id_672 + id_673) };
                        Void id_675 { ((void)(shft_ref_210[id_670] = id_674), ::dessser::VOID) };
                        (void)id_675;
                        uint8_t id_676 { 128 };
                        bool id_677 { bool(leb128_fst_213 >= id_676) };
                        letpair_res_656 = id_677;
                      }
                      let_res_655 = letpair_res_656;
                    }
                    while_flag_651 = let_res_655;
                    if (while_flag_651) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_651);
                  (void)::dessser::VOID;
                  uint8_t id_678 { 0 };
                  uint32_t id_679 { leb_ref_209[id_678] };
                  Size id_680 { Size(id_679) };
                  uint8_t id_681 { 0 };
                  Pointer id_682 { p_ref_211[id_681] };
                  ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa id_683 { id_680, id_682 };
                  let_res_650 = id_683;
                }
                let_res_648 = let_res_650;
              }
              let_res_645 = let_res_648;
            }
            ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_684;
            {
              ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa dstring1_215 { let_res_645 };
              ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_685;
              {
                auto dstring1_fst_216 { std::get<0>(dstring1_215) };
                auto dstring1_snd_217 { std::get<1>(dstring1_215) };
                ::dessser::gen::sync_server_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_686 { dstring1_snd_217.readBytes(dstring1_fst_216) };
                ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_687;
                {
                  auto dstring2_fst_219 { std::get<0>(id_686) };
                  auto dstring2_snd_220 { std::get<1>(id_686) };
                  std::string id_688 { dstring2_fst_219.toString() };
                  std::shared_ptr<::dessser::gen::sync_server_msg::t>  id_689 { std::make_shared<::dessser::gen::sync_server_msg::t>(std::in_place_index<1>, id_688) };
                  ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 id_690 { id_689, dstring2_snd_220 };
                  letpair_res_687 = id_690;
                }
                letpair_res_685 = letpair_res_687;
              }
              let_res_684 = letpair_res_685;
            }
            choose_res_642 = let_res_684;
          } else {
            uint16_t id_691 { 2 };
            bool id_692 { bool(id_691 == dsum1_fst_63) };
            ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 choose_res_693;
            if (id_692) {
              auto fun694 { dessser::gen::sync_key::of_row_binary };
              ::dessser::gen::sync_server_msg::t0e7f6ba9e1ceef343afe44456f9067ec id_695 { fun694(dsum1_snd_64) };
              ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_696;
              {
                ::dessser::gen::sync_server_msg::t0e7f6ba9e1ceef343afe44456f9067ec drec_179 { id_695 };
                ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_697;
                {
                  auto drec_fst_180 { std::get<0>(drec_179) };
                  auto drec_snd_181 { std::get<1>(drec_179) };
                  auto fun698 { dessser::gen::sync_value::of_row_binary };
                  ::dessser::gen::sync_server_msg::td4515cd8d0eb18a7a966d81bd2888d81 id_699 { fun698(drec_snd_181) };
                  ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_700;
                  {
                    ::dessser::gen::sync_server_msg::td4515cd8d0eb18a7a966d81bd2888d81 drec_182 { id_699 };
                    ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_701;
                    {
                      auto drec_fst_183 { std::get<0>(drec_182) };
                      auto drec_snd_184 { std::get<1>(drec_182) };
                      uint32_t id_702 { 0U };
                      Vec<1, uint32_t> id_703 {  id_702  };
                      ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_704;
                      {
                        Vec<1, uint32_t> leb_ref_185 { id_703 };
                        uint8_t id_705 { 0 };
                        Vec<1, uint8_t> id_706 {  id_705  };
                        ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_707;
                        {
                          Vec<1, uint8_t> shft_ref_186 { id_706 };
                          Vec<1, Pointer> id_708 {  drec_snd_184  };
                          ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_709;
                          {
                            Vec<1, Pointer> p_ref_187 { id_708 };
                            bool while_flag_710 { true };
                            do {
                              uint8_t id_711 { 0 };
                              Pointer id_712 { p_ref_187[id_711] };
                              ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 id_713 { id_712.readU8() };
                              bool let_res_714;
                              {
                                ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_188 { id_713 };
                                bool letpair_res_715;
                                {
                                  auto leb128_fst_189 { std::get<0>(leb128_188) };
                                  auto leb128_snd_190 { std::get<1>(leb128_188) };
                                  uint8_t id_716 { 0 };
                                  Void id_717 { ((void)(p_ref_187[id_716] = leb128_snd_190), ::dessser::VOID) };
                                  (void)id_717;
                                  uint8_t id_718 { 0 };
                                  uint8_t id_719 { 127 };
                                  uint8_t id_720 { uint8_t(leb128_fst_189 & id_719) };
                                  uint32_t id_721 { uint32_t(id_720) };
                                  uint8_t id_722 { 0 };
                                  uint8_t id_723 { shft_ref_186[id_722] };
                                  uint32_t id_724 { uint32_t(id_721 << id_723) };
                                  uint8_t id_725 { 0 };
                                  uint32_t id_726 { leb_ref_185[id_725] };
                                  uint32_t id_727 { uint32_t(id_724 | id_726) };
                                  Void id_728 { ((void)(leb_ref_185[id_718] = id_727), ::dessser::VOID) };
                                  (void)id_728;
                                  uint8_t id_729 { 0 };
                                  uint8_t id_730 { 0 };
                                  uint8_t id_731 { shft_ref_186[id_730] };
                                  uint8_t id_732 { 7 };
                                  uint8_t id_733 { uint8_t(id_731 + id_732) };
                                  Void id_734 { ((void)(shft_ref_186[id_729] = id_733), ::dessser::VOID) };
                                  (void)id_734;
                                  uint8_t id_735 { 128 };
                                  bool id_736 { bool(leb128_fst_189 >= id_735) };
                                  letpair_res_715 = id_736;
                                }
                                let_res_714 = letpair_res_715;
                              }
                              while_flag_710 = let_res_714;
                              if (while_flag_710) {
                                (void)::dessser::VOID;
                              }
                            } while (while_flag_710);
                            (void)::dessser::VOID;
                            uint8_t id_737 { 0 };
                            uint32_t id_738 { leb_ref_185[id_737] };
                            Size id_739 { Size(id_738) };
                            uint8_t id_740 { 0 };
                            Pointer id_741 { p_ref_187[id_740] };
                            ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa id_742 { id_739, id_741 };
                            let_res_709 = id_742;
                          }
                          let_res_707 = let_res_709;
                        }
                        let_res_704 = let_res_707;
                      }
                      ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 let_res_743;
                      {
                        ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa dstring1_191 { let_res_704 };
                        ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 letpair_res_744;
                        {
                          auto dstring1_fst_192 { std::get<0>(dstring1_191) };
                          auto dstring1_snd_193 { std::get<1>(dstring1_191) };
                          ::dessser::gen::sync_server_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_745 { dstring1_snd_193.readBytes(dstring1_fst_192) };
                          ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 letpair_res_746;
                          {
                            auto dstring2_fst_195 { std::get<0>(id_745) };
                            auto dstring2_snd_196 { std::get<1>(id_745) };
                            std::string id_747 { dstring2_fst_195.toString() };
                            ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 id_748 { id_747, dstring2_snd_196 };
                            letpair_res_746 = id_748;
                          }
                          letpair_res_744 = letpair_res_746;
                        }
                        let_res_743 = letpair_res_744;
                      }
                      ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_749;
                      {
                        ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 drec_197 { let_res_743 };
                        ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_750;
                        {
                          auto drec_fst_198 { std::get<0>(drec_197) };
                          auto drec_snd_199 { std::get<1>(drec_197) };
                          ::dessser::gen::sync_server_msg::td2cd337bb3c8bc04d5603393d084985b id_751 { drec_snd_199.readU64Le() };
                          ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_752;
                          {
                            auto dfloat_fst_201 { std::get<0>(id_751) };
                            auto dfloat_snd_202 { std::get<1>(id_751) };
                            double id_753 { float_of_qword(dfloat_fst_201) };
                            ::dessser::gen::sync_server_msg::t3f973b24e2e9a1d94d78f692da2d8ddd id_754 { drec_fst_180, id_753, drec_fst_198, drec_fst_183 };
                            std::shared_ptr<::dessser::gen::sync_server_msg::t>  id_755 { std::make_shared<::dessser::gen::sync_server_msg::t>(std::in_place_index<2>, id_754) };
                            ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 id_756 { id_755, dfloat_snd_202 };
                            letpair_res_752 = id_756;
                          }
                          letpair_res_750 = letpair_res_752;
                        }
                        let_res_749 = letpair_res_750;
                      }
                      letpair_res_701 = let_res_749;
                    }
                    let_res_700 = letpair_res_701;
                  }
                  letpair_res_697 = let_res_700;
                }
                let_res_696 = letpair_res_697;
              }
              choose_res_693 = let_res_696;
            } else {
              uint16_t id_757 { 3 };
              bool id_758 { bool(id_757 == dsum1_fst_63) };
              ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 choose_res_759;
              if (id_758) {
                auto fun760 { dessser::gen::sync_key::of_row_binary };
                ::dessser::gen::sync_server_msg::t0e7f6ba9e1ceef343afe44456f9067ec id_761 { fun760(dsum1_snd_64) };
                ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_762;
                {
                  ::dessser::gen::sync_server_msg::t0e7f6ba9e1ceef343afe44456f9067ec drec_116 { id_761 };
                  ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_763;
                  {
                    auto drec_fst_117 { std::get<0>(drec_116) };
                    auto drec_snd_118 { std::get<1>(drec_116) };
                    auto fun764 { dessser::gen::sync_value::of_row_binary };
                    ::dessser::gen::sync_server_msg::td4515cd8d0eb18a7a966d81bd2888d81 id_765 { fun764(drec_snd_118) };
                    ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_766;
                    {
                      ::dessser::gen::sync_server_msg::td4515cd8d0eb18a7a966d81bd2888d81 drec_119 { id_765 };
                      ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_767;
                      {
                        auto drec_fst_120 { std::get<0>(drec_119) };
                        auto drec_snd_121 { std::get<1>(drec_119) };
                        uint32_t id_768 { 0U };
                        Vec<1, uint32_t> id_769 {  id_768  };
                        ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_770;
                        {
                          Vec<1, uint32_t> leb_ref_122 { id_769 };
                          uint8_t id_771 { 0 };
                          Vec<1, uint8_t> id_772 {  id_771  };
                          ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_773;
                          {
                            Vec<1, uint8_t> shft_ref_123 { id_772 };
                            Vec<1, Pointer> id_774 {  drec_snd_121  };
                            ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_775;
                            {
                              Vec<1, Pointer> p_ref_124 { id_774 };
                              bool while_flag_776 { true };
                              do {
                                uint8_t id_777 { 0 };
                                Pointer id_778 { p_ref_124[id_777] };
                                ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 id_779 { id_778.readU8() };
                                bool let_res_780;
                                {
                                  ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_125 { id_779 };
                                  bool letpair_res_781;
                                  {
                                    auto leb128_fst_126 { std::get<0>(leb128_125) };
                                    auto leb128_snd_127 { std::get<1>(leb128_125) };
                                    uint8_t id_782 { 0 };
                                    Void id_783 { ((void)(p_ref_124[id_782] = leb128_snd_127), ::dessser::VOID) };
                                    (void)id_783;
                                    uint8_t id_784 { 0 };
                                    uint8_t id_785 { 127 };
                                    uint8_t id_786 { uint8_t(leb128_fst_126 & id_785) };
                                    uint32_t id_787 { uint32_t(id_786) };
                                    uint8_t id_788 { 0 };
                                    uint8_t id_789 { shft_ref_123[id_788] };
                                    uint32_t id_790 { uint32_t(id_787 << id_789) };
                                    uint8_t id_791 { 0 };
                                    uint32_t id_792 { leb_ref_122[id_791] };
                                    uint32_t id_793 { uint32_t(id_790 | id_792) };
                                    Void id_794 { ((void)(leb_ref_122[id_784] = id_793), ::dessser::VOID) };
                                    (void)id_794;
                                    uint8_t id_795 { 0 };
                                    uint8_t id_796 { 0 };
                                    uint8_t id_797 { shft_ref_123[id_796] };
                                    uint8_t id_798 { 7 };
                                    uint8_t id_799 { uint8_t(id_797 + id_798) };
                                    Void id_800 { ((void)(shft_ref_123[id_795] = id_799), ::dessser::VOID) };
                                    (void)id_800;
                                    uint8_t id_801 { 128 };
                                    bool id_802 { bool(leb128_fst_126 >= id_801) };
                                    letpair_res_781 = id_802;
                                  }
                                  let_res_780 = letpair_res_781;
                                }
                                while_flag_776 = let_res_780;
                                if (while_flag_776) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_776);
                              (void)::dessser::VOID;
                              uint8_t id_803 { 0 };
                              uint32_t id_804 { leb_ref_122[id_803] };
                              Size id_805 { Size(id_804) };
                              uint8_t id_806 { 0 };
                              Pointer id_807 { p_ref_124[id_806] };
                              ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa id_808 { id_805, id_807 };
                              let_res_775 = id_808;
                            }
                            let_res_773 = let_res_775;
                          }
                          let_res_770 = let_res_773;
                        }
                        ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 let_res_809;
                        {
                          ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa dstring1_128 { let_res_770 };
                          ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 letpair_res_810;
                          {
                            auto dstring1_fst_129 { std::get<0>(dstring1_128) };
                            auto dstring1_snd_130 { std::get<1>(dstring1_128) };
                            ::dessser::gen::sync_server_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_811 { dstring1_snd_130.readBytes(dstring1_fst_129) };
                            ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 letpair_res_812;
                            {
                              auto dstring2_fst_132 { std::get<0>(id_811) };
                              auto dstring2_snd_133 { std::get<1>(id_811) };
                              std::string id_813 { dstring2_fst_132.toString() };
                              ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 id_814 { id_813, dstring2_snd_133 };
                              letpair_res_812 = id_814;
                            }
                            letpair_res_810 = letpair_res_812;
                          }
                          let_res_809 = letpair_res_810;
                        }
                        ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_815;
                        {
                          ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 drec_134 { let_res_809 };
                          ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_816;
                          {
                            auto drec_fst_135 { std::get<0>(drec_134) };
                            auto drec_snd_136 { std::get<1>(drec_134) };
                            ::dessser::gen::sync_server_msg::td2cd337bb3c8bc04d5603393d084985b id_817 { drec_snd_136.readU64Le() };
                            ::dessser::gen::sync_server_msg::t9a758baeff17224a77e1a522010b4168 letpair_res_818;
                            {
                              auto dfloat_fst_138 { std::get<0>(id_817) };
                              auto dfloat_snd_139 { std::get<1>(id_817) };
                              double id_819 { float_of_qword(dfloat_fst_138) };
                              ::dessser::gen::sync_server_msg::t9a758baeff17224a77e1a522010b4168 id_820 { id_819, dfloat_snd_139 };
                              letpair_res_818 = id_820;
                            }
                            ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_821;
                            {
                              ::dessser::gen::sync_server_msg::t9a758baeff17224a77e1a522010b4168 drec_140 { letpair_res_818 };
                              ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_822;
                              {
                                auto drec_fst_141 { std::get<0>(drec_140) };
                                auto drec_snd_142 { std::get<1>(drec_140) };
                                ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 id_823 { drec_snd_142.readU8() };
                                ::dessser::gen::sync_server_msg::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_824;
                                {
                                  auto dbool_fst_144 { std::get<0>(id_823) };
                                  auto dbool_snd_145 { std::get<1>(id_823) };
                                  uint8_t id_825 { 0 };
                                  bool id_826 { bool(dbool_fst_144 == id_825) };
                                  bool id_827 { ! id_826 };
                                  ::dessser::gen::sync_server_msg::tf9a0a3fefc87c9e10a93d3a172850c26 id_828 { id_827, dbool_snd_145 };
                                  letpair_res_824 = id_828;
                                }
                                ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_829;
                                {
                                  ::dessser::gen::sync_server_msg::tf9a0a3fefc87c9e10a93d3a172850c26 drec_146 { letpair_res_824 };
                                  ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_830;
                                  {
                                    auto drec_fst_147 { std::get<0>(drec_146) };
                                    auto drec_snd_148 { std::get<1>(drec_146) };
                                    ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 id_831 { drec_snd_148.readU8() };
                                    ::dessser::gen::sync_server_msg::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_832;
                                    {
                                      auto dbool_fst_150 { std::get<0>(id_831) };
                                      auto dbool_snd_151 { std::get<1>(id_831) };
                                      uint8_t id_833 { 0 };
                                      bool id_834 { bool(dbool_fst_150 == id_833) };
                                      bool id_835 { ! id_834 };
                                      ::dessser::gen::sync_server_msg::tf9a0a3fefc87c9e10a93d3a172850c26 id_836 { id_835, dbool_snd_151 };
                                      letpair_res_832 = id_836;
                                    }
                                    ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_837;
                                    {
                                      ::dessser::gen::sync_server_msg::tf9a0a3fefc87c9e10a93d3a172850c26 drec_152 { letpair_res_832 };
                                      ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_838;
                                      {
                                        auto drec_fst_153 { std::get<0>(drec_152) };
                                        auto drec_snd_154 { std::get<1>(drec_152) };
                                        uint32_t id_839 { 0U };
                                        Vec<1, uint32_t> id_840 {  id_839  };
                                        ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_841;
                                        {
                                          Vec<1, uint32_t> leb_ref_155 { id_840 };
                                          uint8_t id_842 { 0 };
                                          Vec<1, uint8_t> id_843 {  id_842  };
                                          ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_844;
                                          {
                                            Vec<1, uint8_t> shft_ref_156 { id_843 };
                                            Vec<1, Pointer> id_845 {  drec_snd_154  };
                                            ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_846;
                                            {
                                              Vec<1, Pointer> p_ref_157 { id_845 };
                                              bool while_flag_847 { true };
                                              do {
                                                uint8_t id_848 { 0 };
                                                Pointer id_849 { p_ref_157[id_848] };
                                                ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 id_850 { id_849.readU8() };
                                                bool let_res_851;
                                                {
                                                  ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_158 { id_850 };
                                                  bool letpair_res_852;
                                                  {
                                                    auto leb128_fst_159 { std::get<0>(leb128_158) };
                                                    auto leb128_snd_160 { std::get<1>(leb128_158) };
                                                    uint8_t id_853 { 0 };
                                                    Void id_854 { ((void)(p_ref_157[id_853] = leb128_snd_160), ::dessser::VOID) };
                                                    (void)id_854;
                                                    uint8_t id_855 { 0 };
                                                    uint8_t id_856 { 127 };
                                                    uint8_t id_857 { uint8_t(leb128_fst_159 & id_856) };
                                                    uint32_t id_858 { uint32_t(id_857) };
                                                    uint8_t id_859 { 0 };
                                                    uint8_t id_860 { shft_ref_156[id_859] };
                                                    uint32_t id_861 { uint32_t(id_858 << id_860) };
                                                    uint8_t id_862 { 0 };
                                                    uint32_t id_863 { leb_ref_155[id_862] };
                                                    uint32_t id_864 { uint32_t(id_861 | id_863) };
                                                    Void id_865 { ((void)(leb_ref_155[id_855] = id_864), ::dessser::VOID) };
                                                    (void)id_865;
                                                    uint8_t id_866 { 0 };
                                                    uint8_t id_867 { 0 };
                                                    uint8_t id_868 { shft_ref_156[id_867] };
                                                    uint8_t id_869 { 7 };
                                                    uint8_t id_870 { uint8_t(id_868 + id_869) };
                                                    Void id_871 { ((void)(shft_ref_156[id_866] = id_870), ::dessser::VOID) };
                                                    (void)id_871;
                                                    uint8_t id_872 { 128 };
                                                    bool id_873 { bool(leb128_fst_159 >= id_872) };
                                                    letpair_res_852 = id_873;
                                                  }
                                                  let_res_851 = letpair_res_852;
                                                }
                                                while_flag_847 = let_res_851;
                                                if (while_flag_847) {
                                                  (void)::dessser::VOID;
                                                }
                                              } while (while_flag_847);
                                              (void)::dessser::VOID;
                                              uint8_t id_874 { 0 };
                                              uint32_t id_875 { leb_ref_155[id_874] };
                                              Size id_876 { Size(id_875) };
                                              uint8_t id_877 { 0 };
                                              Pointer id_878 { p_ref_157[id_877] };
                                              ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa id_879 { id_876, id_878 };
                                              let_res_846 = id_879;
                                            }
                                            let_res_844 = let_res_846;
                                          }
                                          let_res_841 = let_res_844;
                                        }
                                        ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 let_res_880;
                                        {
                                          ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa dstring1_161 { let_res_841 };
                                          ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 letpair_res_881;
                                          {
                                            auto dstring1_fst_162 { std::get<0>(dstring1_161) };
                                            auto dstring1_snd_163 { std::get<1>(dstring1_161) };
                                            ::dessser::gen::sync_server_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_882 { dstring1_snd_163.readBytes(dstring1_fst_162) };
                                            ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 letpair_res_883;
                                            {
                                              auto dstring2_fst_165 { std::get<0>(id_882) };
                                              auto dstring2_snd_166 { std::get<1>(id_882) };
                                              std::string id_884 { dstring2_fst_165.toString() };
                                              ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 id_885 { id_884, dstring2_snd_166 };
                                              letpair_res_883 = id_885;
                                            }
                                            letpair_res_881 = letpair_res_883;
                                          }
                                          let_res_880 = letpair_res_881;
                                        }
                                        ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_886;
                                        {
                                          ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 drec_167 { let_res_880 };
                                          ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_887;
                                          {
                                            auto drec_fst_168 { std::get<0>(drec_167) };
                                            auto drec_snd_169 { std::get<1>(drec_167) };
                                            ::dessser::gen::sync_server_msg::td2cd337bb3c8bc04d5603393d084985b id_888 { drec_snd_169.readU64Le() };
                                            ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_889;
                                            {
                                              auto dfloat_fst_171 { std::get<0>(id_888) };
                                              auto dfloat_snd_172 { std::get<1>(id_888) };
                                              double id_890 { float_of_qword(dfloat_fst_171) };
                                              ::dessser::gen::sync_server_msg::td4227ac047ed98f74e1d279b847d611e id_891 { drec_fst_153, drec_fst_147, id_890, drec_fst_117, drec_fst_141, drec_fst_168, drec_fst_135, drec_fst_120 };
                                              std::shared_ptr<::dessser::gen::sync_server_msg::t>  id_892 { std::make_shared<::dessser::gen::sync_server_msg::t>(std::in_place_index<3>, id_891) };
                                              ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 id_893 { id_892, dfloat_snd_172 };
                                              letpair_res_889 = id_893;
                                            }
                                            letpair_res_887 = letpair_res_889;
                                          }
                                          let_res_886 = letpair_res_887;
                                        }
                                        letpair_res_838 = let_res_886;
                                      }
                                      let_res_837 = letpair_res_838;
                                    }
                                    letpair_res_830 = let_res_837;
                                  }
                                  let_res_829 = letpair_res_830;
                                }
                                letpair_res_822 = let_res_829;
                              }
                              let_res_821 = letpair_res_822;
                            }
                            letpair_res_816 = let_res_821;
                          }
                          let_res_815 = letpair_res_816;
                        }
                        letpair_res_767 = let_res_815;
                      }
                      let_res_766 = letpair_res_767;
                    }
                    letpair_res_763 = let_res_766;
                  }
                  let_res_762 = letpair_res_763;
                }
                choose_res_759 = let_res_762;
              } else {
                uint16_t id_894 { 4 };
                bool id_895 { bool(id_894 == dsum1_fst_63) };
                ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 choose_res_896;
                if (id_895) {
                  auto fun897 { dessser::gen::sync_key::of_row_binary };
                  ::dessser::gen::sync_server_msg::t0e7f6ba9e1ceef343afe44456f9067ec id_898 { fun897(dsum1_snd_64) };
                  ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_899;
                  {
                    ::dessser::gen::sync_server_msg::t0e7f6ba9e1ceef343afe44456f9067ec drec_95 { id_898 };
                    ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_900;
                    {
                      auto drec_fst_96 { std::get<0>(drec_95) };
                      auto drec_snd_97 { std::get<1>(drec_95) };
                      uint32_t id_901 { 0U };
                      Vec<1, uint32_t> id_902 {  id_901  };
                      ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_903;
                      {
                        Vec<1, uint32_t> leb_ref_98 { id_902 };
                        uint8_t id_904 { 0 };
                        Vec<1, uint8_t> id_905 {  id_904  };
                        ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_906;
                        {
                          Vec<1, uint8_t> shft_ref_99 { id_905 };
                          Vec<1, Pointer> id_907 {  drec_snd_97  };
                          ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_908;
                          {
                            Vec<1, Pointer> p_ref_100 { id_907 };
                            bool while_flag_909 { true };
                            do {
                              uint8_t id_910 { 0 };
                              Pointer id_911 { p_ref_100[id_910] };
                              ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 id_912 { id_911.readU8() };
                              bool let_res_913;
                              {
                                ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_101 { id_912 };
                                bool letpair_res_914;
                                {
                                  auto leb128_fst_102 { std::get<0>(leb128_101) };
                                  auto leb128_snd_103 { std::get<1>(leb128_101) };
                                  uint8_t id_915 { 0 };
                                  Void id_916 { ((void)(p_ref_100[id_915] = leb128_snd_103), ::dessser::VOID) };
                                  (void)id_916;
                                  uint8_t id_917 { 0 };
                                  uint8_t id_918 { 127 };
                                  uint8_t id_919 { uint8_t(leb128_fst_102 & id_918) };
                                  uint32_t id_920 { uint32_t(id_919) };
                                  uint8_t id_921 { 0 };
                                  uint8_t id_922 { shft_ref_99[id_921] };
                                  uint32_t id_923 { uint32_t(id_920 << id_922) };
                                  uint8_t id_924 { 0 };
                                  uint32_t id_925 { leb_ref_98[id_924] };
                                  uint32_t id_926 { uint32_t(id_923 | id_925) };
                                  Void id_927 { ((void)(leb_ref_98[id_917] = id_926), ::dessser::VOID) };
                                  (void)id_927;
                                  uint8_t id_928 { 0 };
                                  uint8_t id_929 { 0 };
                                  uint8_t id_930 { shft_ref_99[id_929] };
                                  uint8_t id_931 { 7 };
                                  uint8_t id_932 { uint8_t(id_930 + id_931) };
                                  Void id_933 { ((void)(shft_ref_99[id_928] = id_932), ::dessser::VOID) };
                                  (void)id_933;
                                  uint8_t id_934 { 128 };
                                  bool id_935 { bool(leb128_fst_102 >= id_934) };
                                  letpair_res_914 = id_935;
                                }
                                let_res_913 = letpair_res_914;
                              }
                              while_flag_909 = let_res_913;
                              if (while_flag_909) {
                                (void)::dessser::VOID;
                              }
                            } while (while_flag_909);
                            (void)::dessser::VOID;
                            uint8_t id_936 { 0 };
                            uint32_t id_937 { leb_ref_98[id_936] };
                            Size id_938 { Size(id_937) };
                            uint8_t id_939 { 0 };
                            Pointer id_940 { p_ref_100[id_939] };
                            ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa id_941 { id_938, id_940 };
                            let_res_908 = id_941;
                          }
                          let_res_906 = let_res_908;
                        }
                        let_res_903 = let_res_906;
                      }
                      ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_942;
                      {
                        ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa dstring1_104 { let_res_903 };
                        ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_943;
                        {
                          auto dstring1_fst_105 { std::get<0>(dstring1_104) };
                          auto dstring1_snd_106 { std::get<1>(dstring1_104) };
                          ::dessser::gen::sync_server_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_944 { dstring1_snd_106.readBytes(dstring1_fst_105) };
                          ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_945;
                          {
                            auto dstring2_fst_108 { std::get<0>(id_944) };
                            auto dstring2_snd_109 { std::get<1>(id_944) };
                            std::string id_946 { dstring2_fst_108.toString() };
                            ::dessser::gen::sync_server_msg::t08b27b0be3a89631db1d9e270c1e83bc id_947 { drec_fst_96, id_946 };
                            std::shared_ptr<::dessser::gen::sync_server_msg::t>  id_948 { std::make_shared<::dessser::gen::sync_server_msg::t>(std::in_place_index<4>, id_947) };
                            ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 id_949 { id_948, dstring2_snd_109 };
                            letpair_res_945 = id_949;
                          }
                          letpair_res_943 = letpair_res_945;
                        }
                        let_res_942 = letpair_res_943;
                      }
                      letpair_res_900 = let_res_942;
                    }
                    let_res_899 = letpair_res_900;
                  }
                  choose_res_896 = let_res_899;
                } else {
                  uint16_t id_950 { 5 };
                  bool id_951 { bool(id_950 == dsum1_fst_63) };
                  ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 choose_res_952;
                  if (id_951) {
                    auto fun953 { dessser::gen::sync_key::of_row_binary };
                    ::dessser::gen::sync_server_msg::t0e7f6ba9e1ceef343afe44456f9067ec id_954 { fun953(dsum1_snd_64) };
                    ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_955;
                    {
                      ::dessser::gen::sync_server_msg::t0e7f6ba9e1ceef343afe44456f9067ec drec_68 { id_954 };
                      ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_956;
                      {
                        auto drec_fst_69 { std::get<0>(drec_68) };
                        auto drec_snd_70 { std::get<1>(drec_68) };
                        uint32_t id_957 { 0U };
                        Vec<1, uint32_t> id_958 {  id_957  };
                        ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_959;
                        {
                          Vec<1, uint32_t> leb_ref_71 { id_958 };
                          uint8_t id_960 { 0 };
                          Vec<1, uint8_t> id_961 {  id_960  };
                          ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_962;
                          {
                            Vec<1, uint8_t> shft_ref_72 { id_961 };
                            Vec<1, Pointer> id_963 {  drec_snd_70  };
                            ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa let_res_964;
                            {
                              Vec<1, Pointer> p_ref_73 { id_963 };
                              bool while_flag_965 { true };
                              do {
                                uint8_t id_966 { 0 };
                                Pointer id_967 { p_ref_73[id_966] };
                                ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 id_968 { id_967.readU8() };
                                bool let_res_969;
                                {
                                  ::dessser::gen::sync_server_msg::t1a5d74abf838df33f185a72a8912f5c9 leb128_74 { id_968 };
                                  bool letpair_res_970;
                                  {
                                    auto leb128_fst_75 { std::get<0>(leb128_74) };
                                    auto leb128_snd_76 { std::get<1>(leb128_74) };
                                    uint8_t id_971 { 0 };
                                    Void id_972 { ((void)(p_ref_73[id_971] = leb128_snd_76), ::dessser::VOID) };
                                    (void)id_972;
                                    uint8_t id_973 { 0 };
                                    uint8_t id_974 { 127 };
                                    uint8_t id_975 { uint8_t(leb128_fst_75 & id_974) };
                                    uint32_t id_976 { uint32_t(id_975) };
                                    uint8_t id_977 { 0 };
                                    uint8_t id_978 { shft_ref_72[id_977] };
                                    uint32_t id_979 { uint32_t(id_976 << id_978) };
                                    uint8_t id_980 { 0 };
                                    uint32_t id_981 { leb_ref_71[id_980] };
                                    uint32_t id_982 { uint32_t(id_979 | id_981) };
                                    Void id_983 { ((void)(leb_ref_71[id_973] = id_982), ::dessser::VOID) };
                                    (void)id_983;
                                    uint8_t id_984 { 0 };
                                    uint8_t id_985 { 0 };
                                    uint8_t id_986 { shft_ref_72[id_985] };
                                    uint8_t id_987 { 7 };
                                    uint8_t id_988 { uint8_t(id_986 + id_987) };
                                    Void id_989 { ((void)(shft_ref_72[id_984] = id_988), ::dessser::VOID) };
                                    (void)id_989;
                                    uint8_t id_990 { 128 };
                                    bool id_991 { bool(leb128_fst_75 >= id_990) };
                                    letpair_res_970 = id_991;
                                  }
                                  let_res_969 = letpair_res_970;
                                }
                                while_flag_965 = let_res_969;
                                if (while_flag_965) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_965);
                              (void)::dessser::VOID;
                              uint8_t id_992 { 0 };
                              uint32_t id_993 { leb_ref_71[id_992] };
                              Size id_994 { Size(id_993) };
                              uint8_t id_995 { 0 };
                              Pointer id_996 { p_ref_73[id_995] };
                              ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa id_997 { id_994, id_996 };
                              let_res_964 = id_997;
                            }
                            let_res_962 = let_res_964;
                          }
                          let_res_959 = let_res_962;
                        }
                        ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 let_res_998;
                        {
                          ::dessser::gen::sync_server_msg::t12fb9c475959b52bf7b17b155a955ffa dstring1_77 { let_res_959 };
                          ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 letpair_res_999;
                          {
                            auto dstring1_fst_78 { std::get<0>(dstring1_77) };
                            auto dstring1_snd_79 { std::get<1>(dstring1_77) };
                            ::dessser::gen::sync_server_msg::t9ef6882174ae71a34a3c5ef6b29242fb id_1000 { dstring1_snd_79.readBytes(dstring1_fst_78) };
                            ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 letpair_res_1001;
                            {
                              auto dstring2_fst_81 { std::get<0>(id_1000) };
                              auto dstring2_snd_82 { std::get<1>(id_1000) };
                              std::string id_1002 { dstring2_fst_81.toString() };
                              ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 id_1003 { id_1002, dstring2_snd_82 };
                              letpair_res_1001 = id_1003;
                            }
                            letpair_res_999 = letpair_res_1001;
                          }
                          let_res_998 = letpair_res_999;
                        }
                        ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 let_res_1004;
                        {
                          ::dessser::gen::sync_server_msg::t13a07ee37ab40962540da8534858dc07 drec_83 { let_res_998 };
                          ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_1005;
                          {
                            auto drec_fst_84 { std::get<0>(drec_83) };
                            auto drec_snd_85 { std::get<1>(drec_83) };
                            ::dessser::gen::sync_server_msg::td2cd337bb3c8bc04d5603393d084985b id_1006 { drec_snd_85.readU64Le() };
                            ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_1007;
                            {
                              auto dfloat_fst_87 { std::get<0>(id_1006) };
                              auto dfloat_snd_88 { std::get<1>(id_1006) };
                              double id_1008 { float_of_qword(dfloat_fst_87) };
                              ::dessser::gen::sync_server_msg::t675a4fdd830ddedd7d9ba746180c033f id_1009 { id_1008, drec_fst_69, drec_fst_84 };
                              std::shared_ptr<::dessser::gen::sync_server_msg::t>  id_1010 { std::make_shared<::dessser::gen::sync_server_msg::t>(std::in_place_index<5>, id_1009) };
                              ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 id_1011 { id_1010, dfloat_snd_88 };
                              letpair_res_1007 = id_1011;
                            }
                            letpair_res_1005 = letpair_res_1007;
                          }
                          let_res_1004 = letpair_res_1005;
                        }
                        letpair_res_956 = let_res_1004;
                      }
                      let_res_955 = letpair_res_956;
                    }
                    choose_res_952 = let_res_955;
                  } else {
                    uint16_t id_1012 { 6 };
                    bool id_1013 { bool(dsum1_fst_63 == id_1012) };
                    Void id_1014 { ((void)(assert(id_1013)), ::dessser::VOID) };
                    (void)id_1014;
                    auto fun1015 { dessser::gen::sync_key::of_row_binary };
                    ::dessser::gen::sync_server_msg::t0e7f6ba9e1ceef343afe44456f9067ec id_1016 { fun1015(dsum1_snd_64) };
                    ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_1017;
                    {
                      auto dsum2_fst_66 { std::get<0>(id_1016) };
                      auto dsum2_snd_67 { std::get<1>(id_1016) };
                      std::shared_ptr<::dessser::gen::sync_server_msg::t>  id_1018 { std::make_shared<::dessser::gen::sync_server_msg::t>(std::in_place_index<6>, dsum2_fst_66) };
                      ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 id_1019 { id_1018, dsum2_snd_67 };
                      letpair_res_1017 = id_1019;
                    }
                    choose_res_952 = letpair_res_1017;
                  }
                  choose_res_896 = choose_res_952;
                }
                choose_res_759 = choose_res_896;
              }
              choose_res_693 = choose_res_759;
            }
            choose_res_642 = choose_res_693;
          }
          choose_res_634 = choose_res_642;
        }
        letpair_res_631 = choose_res_634;
      }
      let_res_630 = letpair_res_631;
    }
    return let_res_630;
  }
   };
  return fun626;
}
std::function<::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_228" "make_snd_229" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_228") (identifier "make_snd_229"))))
 */
static std::function<::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1(Pointer)> fun1020 { [&fun1020](Pointer p_0) {
    ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 id_1021 { of_row_binary(p_0) };
    ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 letpair_res_1022;
    {
      auto make_fst_228 { std::get<0>(id_1021) };
      auto make_snd_229 { std::get<1>(id_1021) };
      ::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1 id_1023 { make_fst_228, make_snd_229 };
      letpair_res_1022 = id_1023;
    }
    return letpair_res_1022;
  }
   };
  return fun1020;
}
std::function<::dessser::gen::sync_server_msg::t74e78fed6c064ccc52152cfa38842dd1(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[AuthOk $sync_socket | AuthErr STRING | SetKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT} | NewKey {k: $sync_key; v: $sync_value; uid: STRING; mtime: FLOAT; can_write: BOOL; can_del: BOOL; owner: STRING; expiry: FLOAT} | DelKey {k: $sync_key; uid: STRING} | LockKey {k: $sync_key; owner: STRING; expiry: FLOAT} | UnlockKey $sync_key]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_server_msg::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_server_msg::t> ,Pointer)> fun1024 { [&fun1024](std::shared_ptr<::dessser::gen::sync_server_msg::t>  p_0, Pointer p_1) {
    Pointer id_1025 { to_row_binary(p_0, p_1) };
    return id_1025;
  }
   };
  return fun1024;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_server_msg::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
