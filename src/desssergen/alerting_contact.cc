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

namespace dessser::gen::alerting_contact {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t2295780c8d3630e8bc9d277e6fa82e3b {
  std::string file;
  std::string insert;
  std::string create;
  t2295780c8d3630e8bc9d277e6fa82e3b(std::string file_, std::string insert_, std::string create_) : file(file_), insert(insert_), create(create_) {}
  t2295780c8d3630e8bc9d277e6fa82e3b() = default;
};
inline bool operator==(t2295780c8d3630e8bc9d277e6fa82e3b const &a, t2295780c8d3630e8bc9d277e6fa82e3b const &b) {
  return a.file == b.file && a.insert == b.insert && a.create == b.create;
}

inline bool operator!=(t2295780c8d3630e8bc9d277e6fa82e3b const &a, t2295780c8d3630e8bc9d277e6fa82e3b const &b) {
  return !operator==(a, b);
}
struct t720047405469e43c41ae902df9d2c463 : public std::tuple<
  std::string,
  std::string
> {
  using tuple::tuple;
};
inline bool operator==(t720047405469e43c41ae902df9d2c463 const &a, t720047405469e43c41ae902df9d2c463 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t720047405469e43c41ae902df9d2c463 const &a, t720047405469e43c41ae902df9d2c463 const &b) {
  return !operator==(a, b);
}
struct t5a8393235cc21d52708273e644b80be6 {
  Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> options;
  std::string topic;
  uint16_t partition;
  std::string text;
  t5a8393235cc21d52708273e644b80be6(Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> options_, std::string topic_, uint16_t partition_, std::string text_) : options(options_), topic(topic_), partition(partition_), text(text_) {}
  t5a8393235cc21d52708273e644b80be6() = default;
};
inline bool operator==(t5a8393235cc21d52708273e644b80be6 const &a, t5a8393235cc21d52708273e644b80be6 const &b) {
  return a.options == b.options && a.topic == b.topic && a.partition == b.partition && a.text == b.text;
}

inline bool operator!=(t5a8393235cc21d52708273e644b80be6 const &a, t5a8393235cc21d52708273e644b80be6 const &b) {
  return !operator==(a, b);
}
struct via : public std::variant<
  Void, // Ignore
  std::string, // Exec
  std::string, // SysLog
  ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b, // Sqlite
  ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 // Kafka
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 5 };
};

inline bool operator==(via const &a, via const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Ignore
    case 1: return std::get<1>(a) == std::get<1>(b); // Exec
    case 2: return std::get<2>(a) == std::get<2>(b); // SysLog
    case 3: return std::get<3>(a) == std::get<3>(b); // Sqlite
    case 4: return std::get<4>(a) == std::get<4>(b); // Kafka
  };
  return false;
}
inline bool operator!=(via const &a, via const &b) {
  return !operator==(a, b);
}
struct t {
  std::shared_ptr<::dessser::gen::alerting_contact::via>  via;
  double timeout;
  t(std::shared_ptr<::dessser::gen::alerting_contact::via>  via_, double timeout_) : via(via_), timeout(timeout_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return (*a.via) == (*b.via) && a.timeout == b.timeout;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t4f2037d06e9b8c11be7f16b6ac8dd523 : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_contact::via> ,
  Pointer
> {
  using tuple::tuple;
  t4f2037d06e9b8c11be7f16b6ac8dd523(std::tuple<std::shared_ptr<::dessser::gen::alerting_contact::via> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_contact::via> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4f2037d06e9b8c11be7f16b6ac8dd523 const &a, t4f2037d06e9b8c11be7f16b6ac8dd523 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4f2037d06e9b8c11be7f16b6ac8dd523 const &a, t4f2037d06e9b8c11be7f16b6ac8dd523 const &b) {
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
struct t0ec843672514be25b144f299b8cb3149 : public std::tuple<
  Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463>,
  Pointer
> {
  using tuple::tuple;
  t0ec843672514be25b144f299b8cb3149(std::tuple<Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0ec843672514be25b144f299b8cb3149 const &a, t0ec843672514be25b144f299b8cb3149 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0ec843672514be25b144f299b8cb3149 const &a, t0ec843672514be25b144f299b8cb3149 const &b) {
  return !operator==(a, b);
}
struct tf575ebd2244aa6b126ef4291c9e6f8ae : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_contact::t> ,
  Pointer
> {
  using tuple::tuple;
  tf575ebd2244aa6b126ef4291c9e6f8ae(std::tuple<std::shared_ptr<::dessser::gen::alerting_contact::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_contact::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf575ebd2244aa6b126ef4291c9e6f8ae const &a, tf575ebd2244aa6b126ef4291c9e6f8ae const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf575ebd2244aa6b126ef4291c9e6f8ae const &a, tf575ebd2244aa6b126ef4291c9e6f8ae const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" "Ptr")
      (let "ssum_dst_298" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_298")
          (if (eq (u16 1) (label-of (param 0)))
            (write-bytes
              (let "leb128_sz_327" (make-vec (string-length (get-alt "Exec" (param 0))))
                (let "leb128_ptr_328" (make-vec (identifier "ssum_dst_298"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_328")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_328"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_327"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_327"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_327"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_327") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_327")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_327")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_328"))))) 
              (bytes-of-string (get-alt "Exec" (param 0))))
            (if (eq (u16 2) (label-of (param 0)))
              (write-bytes
                (let "leb128_sz_325" (make-vec (string-length (get-alt "SysLog" (param 0))))
                  (let "leb128_ptr_326" (make-vec (identifier "ssum_dst_298"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_326")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_326"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_325"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_325"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_325"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_325") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_325")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_325")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_326"))))) 
                (bytes-of-string (get-alt "SysLog" (param 0))))
              (if (eq (u16 3) (label-of (param 0)))
                (let "srec_dst_322"
                  (let "srec_dst_319"
                    (write-bytes
                      (let "leb128_sz_317" (make-vec (string-length (get-field "file" (get-alt "Sqlite" (param 0)))))
                        (let "leb128_ptr_318" (make-vec (identifier "ssum_dst_298"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_318")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_318"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_317"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_317"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_317"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_317") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_317")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_317")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_318"))))) 
                      (bytes-of-string (get-field "file" (get-alt "Sqlite" (param 0)))))
                    (write-bytes
                      (let "leb128_sz_320" (make-vec (string-length (get-field "insert" (get-alt "Sqlite" (param 0)))))
                        (let "leb128_ptr_321" (make-vec (identifier "srec_dst_319"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_321")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_321"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_320"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_320"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_320"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_320") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_320")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_320")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_321"))))) 
                      (bytes-of-string (get-field "insert" (get-alt "Sqlite" (param 0))))))
                  (write-bytes
                    (let "leb128_sz_323" (make-vec (string-length (get-field "create" (get-alt "Sqlite" (param 0)))))
                      (let "leb128_ptr_324" (make-vec (identifier "srec_dst_322"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_324")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_324"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_323"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_323"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_323"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_323") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_323")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_323")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_324"))))) 
                    (bytes-of-string (get-field "create" (get-alt "Sqlite" (param 0))))))
                (seq (assert (eq (label-of (param 0)) (u16 4)))
                  (let "srec_dst_314"
                    (let "srec_dst_313"
                      (let "srec_dst_310"
                        (let "dst_ref_301"
                          (make-vec
                            (let "leb128_sz_299" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (param 0)))))
                              (let "leb128_ptr_300" (make-vec (identifier "ssum_dst_298"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_300")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_300"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_299"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_299"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_299"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_299") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_299")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_299")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_300"))))))
                          (let "n_ref_302" (make-vec (i32 0))
                            (seq
                              (for-each "x_303" (get-field "options" (get-alt "Kafka" (param 0)))
                                (seq
                                  (set-vec (u8 0) (identifier "dst_ref_301")
                                    (let "stup_dst_307"
                                      (let "stup_dst_304" (unsafe-nth (u8 0) (identifier "dst_ref_301"))
                                        (write-bytes
                                          (let "leb128_sz_305" (make-vec (string-length (get-item 0 (identifier "x_303"))))
                                            (let "leb128_ptr_306" (make-vec (identifier "stup_dst_304"))
                                              (seq
                                                (while
                                                  (seq
                                                    (set-vec (u8 0) (identifier "leb128_ptr_306")
                                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_306"))
                                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_305"))) 
                                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_305"))) 
                                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_305"))) (u8 128)))))
                                                    (set-vec (u8 0) (identifier "leb128_sz_305") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_305")) (u8 7)))
                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_305")) (u32 0))) 
                                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_306"))))) 
                                          (bytes-of-string (get-item 0 (identifier "x_303")))))
                                      (write-bytes
                                        (let "leb128_sz_308" (make-vec (string-length (get-item 1 (identifier "x_303"))))
                                          (let "leb128_ptr_309" (make-vec (identifier "stup_dst_307"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_309")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_309"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_308"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_308"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_308"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_308") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_308")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_308")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_309"))))) 
                                        (bytes-of-string (get-item 1 (identifier "x_303")))))) 
                                  (set-vec (u8 0) (identifier "n_ref_302") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_302")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_301")))))
                        (write-bytes
                          (let "leb128_sz_311" (make-vec (string-length (get-field "topic" (get-alt "Kafka" (param 0)))))
                            (let "leb128_ptr_312" (make-vec (identifier "srec_dst_310"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_312")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_312"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_311"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_311"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_311"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_311") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_311")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_311")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_312"))))) 
                          (bytes-of-string (get-field "topic" (get-alt "Kafka" (param 0)))))) 
                      (write-u16 little-endian (identifier "srec_dst_313") (get-field "partition" (get-alt "Kafka" (param 0)))))
                    (write-bytes
                      (let "leb128_sz_315" (make-vec (string-length (get-field "text" (get-alt "Kafka" (param 0)))))
                        (let "leb128_ptr_316" (make-vec (identifier "srec_dst_314"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_316")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_316"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_315"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_315"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_315"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_315") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_315")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_315")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_316"))))) 
                      (bytes-of-string (get-field "text" (get-alt "Kafka" (param 0)))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::via> ,Pointer)> via_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::via> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::alerting_contact::via>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_298 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_298;
      } else {
        uint16_t id_8 { 1 };
        uint16_t id_9 { uint16_t((*p_0).index()) };
        bool id_10 { bool(id_8 == id_9) };
        Pointer choose_res_11;
        if (id_10) {
          std::string id_12 { std::get<1 /* Exec */>((*p_0)) };
          uint32_t id_13 { (uint32_t)id_12.size() };
          Vec<1, uint32_t> id_14 {  id_13  };
          Pointer let_res_15;
          {
            Vec<1, uint32_t> leb128_sz_327 { id_14 };
            Vec<1, Pointer> id_16 {  ssum_dst_298  };
            Pointer let_res_17;
            {
              Vec<1, Pointer> leb128_ptr_328 { id_16 };
              bool while_flag_18 { true };
              do {
                uint8_t id_19 { 0 };
                uint8_t id_20 { 0 };
                Pointer id_21 { leb128_ptr_328[id_20] };
                uint32_t id_22 { 128U };
                uint8_t id_23 { 0 };
                uint32_t id_24 { leb128_sz_327[id_23] };
                bool id_25 { bool(id_22 > id_24) };
                uint8_t choose_res_26;
                if (id_25) {
                  uint8_t id_27 { 0 };
                  uint32_t id_28 { leb128_sz_327[id_27] };
                  uint8_t id_29 { uint8_t(id_28) };
                  choose_res_26 = id_29;
                } else {
                  uint8_t id_30 { 0 };
                  uint32_t id_31 { leb128_sz_327[id_30] };
                  uint8_t id_32 { uint8_t(id_31) };
                  uint8_t id_33 { 128 };
                  uint8_t id_34 { uint8_t(id_32 | id_33) };
                  choose_res_26 = id_34;
                }
                Pointer id_35 { id_21.writeU8(choose_res_26) };
                Void id_36 { ((void)(leb128_ptr_328[id_19] = id_35), ::dessser::Void()) };
                (void)id_36;
                uint8_t id_37 { 0 };
                uint8_t id_38 { 0 };
                uint32_t id_39 { leb128_sz_327[id_38] };
                uint8_t id_40 { 7 };
                uint32_t id_41 { uint32_t(id_39 >> id_40) };
                Void id_42 { ((void)(leb128_sz_327[id_37] = id_41), ::dessser::Void()) };
                (void)id_42;
                uint8_t id_43 { 0 };
                uint32_t id_44 { leb128_sz_327[id_43] };
                uint32_t id_45 { 0U };
                bool id_46 { bool(id_44 > id_45) };
                while_flag_18 = id_46;
                if (while_flag_18) {
                  (void)::dessser::Void();
                }
              } while (while_flag_18);
              (void)::dessser::Void();
              uint8_t id_47 { 0 };
              Pointer id_48 { leb128_ptr_328[id_47] };
              let_res_17 = id_48;
            }
            let_res_15 = let_res_17;
          }
          std::string id_49 { std::get<1 /* Exec */>((*p_0)) };
          Bytes id_50 { id_49 };
          Pointer id_51 { let_res_15.writeBytes(id_50) };
          choose_res_11 = id_51;
        } else {
          uint16_t id_52 { 2 };
          uint16_t id_53 { uint16_t((*p_0).index()) };
          bool id_54 { bool(id_52 == id_53) };
          Pointer choose_res_55;
          if (id_54) {
            std::string id_56 { std::get<2 /* SysLog */>((*p_0)) };
            uint32_t id_57 { (uint32_t)id_56.size() };
            Vec<1, uint32_t> id_58 {  id_57  };
            Pointer let_res_59;
            {
              Vec<1, uint32_t> leb128_sz_325 { id_58 };
              Vec<1, Pointer> id_60 {  ssum_dst_298  };
              Pointer let_res_61;
              {
                Vec<1, Pointer> leb128_ptr_326 { id_60 };
                bool while_flag_62 { true };
                do {
                  uint8_t id_63 { 0 };
                  uint8_t id_64 { 0 };
                  Pointer id_65 { leb128_ptr_326[id_64] };
                  uint32_t id_66 { 128U };
                  uint8_t id_67 { 0 };
                  uint32_t id_68 { leb128_sz_325[id_67] };
                  bool id_69 { bool(id_66 > id_68) };
                  uint8_t choose_res_70;
                  if (id_69) {
                    uint8_t id_71 { 0 };
                    uint32_t id_72 { leb128_sz_325[id_71] };
                    uint8_t id_73 { uint8_t(id_72) };
                    choose_res_70 = id_73;
                  } else {
                    uint8_t id_74 { 0 };
                    uint32_t id_75 { leb128_sz_325[id_74] };
                    uint8_t id_76 { uint8_t(id_75) };
                    uint8_t id_77 { 128 };
                    uint8_t id_78 { uint8_t(id_76 | id_77) };
                    choose_res_70 = id_78;
                  }
                  Pointer id_79 { id_65.writeU8(choose_res_70) };
                  Void id_80 { ((void)(leb128_ptr_326[id_63] = id_79), ::dessser::Void()) };
                  (void)id_80;
                  uint8_t id_81 { 0 };
                  uint8_t id_82 { 0 };
                  uint32_t id_83 { leb128_sz_325[id_82] };
                  uint8_t id_84 { 7 };
                  uint32_t id_85 { uint32_t(id_83 >> id_84) };
                  Void id_86 { ((void)(leb128_sz_325[id_81] = id_85), ::dessser::Void()) };
                  (void)id_86;
                  uint8_t id_87 { 0 };
                  uint32_t id_88 { leb128_sz_325[id_87] };
                  uint32_t id_89 { 0U };
                  bool id_90 { bool(id_88 > id_89) };
                  while_flag_62 = id_90;
                  if (while_flag_62) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_62);
                (void)::dessser::Void();
                uint8_t id_91 { 0 };
                Pointer id_92 { leb128_ptr_326[id_91] };
                let_res_61 = id_92;
              }
              let_res_59 = let_res_61;
            }
            std::string id_93 { std::get<2 /* SysLog */>((*p_0)) };
            Bytes id_94 { id_93 };
            Pointer id_95 { let_res_59.writeBytes(id_94) };
            choose_res_55 = id_95;
          } else {
            uint16_t id_96 { 3 };
            uint16_t id_97 { uint16_t((*p_0).index()) };
            bool id_98 { bool(id_96 == id_97) };
            Pointer choose_res_99;
            if (id_98) {
              ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_100 { std::get<3 /* Sqlite */>((*p_0)) };
              std::string id_101 { id_100.file };
              uint32_t id_102 { (uint32_t)id_101.size() };
              Vec<1, uint32_t> id_103 {  id_102  };
              Pointer let_res_104;
              {
                Vec<1, uint32_t> leb128_sz_317 { id_103 };
                Vec<1, Pointer> id_105 {  ssum_dst_298  };
                Pointer let_res_106;
                {
                  Vec<1, Pointer> leb128_ptr_318 { id_105 };
                  bool while_flag_107 { true };
                  do {
                    uint8_t id_108 { 0 };
                    uint8_t id_109 { 0 };
                    Pointer id_110 { leb128_ptr_318[id_109] };
                    uint32_t id_111 { 128U };
                    uint8_t id_112 { 0 };
                    uint32_t id_113 { leb128_sz_317[id_112] };
                    bool id_114 { bool(id_111 > id_113) };
                    uint8_t choose_res_115;
                    if (id_114) {
                      uint8_t id_116 { 0 };
                      uint32_t id_117 { leb128_sz_317[id_116] };
                      uint8_t id_118 { uint8_t(id_117) };
                      choose_res_115 = id_118;
                    } else {
                      uint8_t id_119 { 0 };
                      uint32_t id_120 { leb128_sz_317[id_119] };
                      uint8_t id_121 { uint8_t(id_120) };
                      uint8_t id_122 { 128 };
                      uint8_t id_123 { uint8_t(id_121 | id_122) };
                      choose_res_115 = id_123;
                    }
                    Pointer id_124 { id_110.writeU8(choose_res_115) };
                    Void id_125 { ((void)(leb128_ptr_318[id_108] = id_124), ::dessser::Void()) };
                    (void)id_125;
                    uint8_t id_126 { 0 };
                    uint8_t id_127 { 0 };
                    uint32_t id_128 { leb128_sz_317[id_127] };
                    uint8_t id_129 { 7 };
                    uint32_t id_130 { uint32_t(id_128 >> id_129) };
                    Void id_131 { ((void)(leb128_sz_317[id_126] = id_130), ::dessser::Void()) };
                    (void)id_131;
                    uint8_t id_132 { 0 };
                    uint32_t id_133 { leb128_sz_317[id_132] };
                    uint32_t id_134 { 0U };
                    bool id_135 { bool(id_133 > id_134) };
                    while_flag_107 = id_135;
                    if (while_flag_107) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_107);
                  (void)::dessser::Void();
                  uint8_t id_136 { 0 };
                  Pointer id_137 { leb128_ptr_318[id_136] };
                  let_res_106 = id_137;
                }
                let_res_104 = let_res_106;
              }
              ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_138 { std::get<3 /* Sqlite */>((*p_0)) };
              std::string id_139 { id_138.file };
              Bytes id_140 { id_139 };
              Pointer id_141 { let_res_104.writeBytes(id_140) };
              Pointer let_res_142;
              {
                Pointer srec_dst_319 { id_141 };
                ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_143 { std::get<3 /* Sqlite */>((*p_0)) };
                std::string id_144 { id_143.insert };
                uint32_t id_145 { (uint32_t)id_144.size() };
                Vec<1, uint32_t> id_146 {  id_145  };
                Pointer let_res_147;
                {
                  Vec<1, uint32_t> leb128_sz_320 { id_146 };
                  Vec<1, Pointer> id_148 {  srec_dst_319  };
                  Pointer let_res_149;
                  {
                    Vec<1, Pointer> leb128_ptr_321 { id_148 };
                    bool while_flag_150 { true };
                    do {
                      uint8_t id_151 { 0 };
                      uint8_t id_152 { 0 };
                      Pointer id_153 { leb128_ptr_321[id_152] };
                      uint32_t id_154 { 128U };
                      uint8_t id_155 { 0 };
                      uint32_t id_156 { leb128_sz_320[id_155] };
                      bool id_157 { bool(id_154 > id_156) };
                      uint8_t choose_res_158;
                      if (id_157) {
                        uint8_t id_159 { 0 };
                        uint32_t id_160 { leb128_sz_320[id_159] };
                        uint8_t id_161 { uint8_t(id_160) };
                        choose_res_158 = id_161;
                      } else {
                        uint8_t id_162 { 0 };
                        uint32_t id_163 { leb128_sz_320[id_162] };
                        uint8_t id_164 { uint8_t(id_163) };
                        uint8_t id_165 { 128 };
                        uint8_t id_166 { uint8_t(id_164 | id_165) };
                        choose_res_158 = id_166;
                      }
                      Pointer id_167 { id_153.writeU8(choose_res_158) };
                      Void id_168 { ((void)(leb128_ptr_321[id_151] = id_167), ::dessser::Void()) };
                      (void)id_168;
                      uint8_t id_169 { 0 };
                      uint8_t id_170 { 0 };
                      uint32_t id_171 { leb128_sz_320[id_170] };
                      uint8_t id_172 { 7 };
                      uint32_t id_173 { uint32_t(id_171 >> id_172) };
                      Void id_174 { ((void)(leb128_sz_320[id_169] = id_173), ::dessser::Void()) };
                      (void)id_174;
                      uint8_t id_175 { 0 };
                      uint32_t id_176 { leb128_sz_320[id_175] };
                      uint32_t id_177 { 0U };
                      bool id_178 { bool(id_176 > id_177) };
                      while_flag_150 = id_178;
                      if (while_flag_150) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_150);
                    (void)::dessser::Void();
                    uint8_t id_179 { 0 };
                    Pointer id_180 { leb128_ptr_321[id_179] };
                    let_res_149 = id_180;
                  }
                  let_res_147 = let_res_149;
                }
                ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_181 { std::get<3 /* Sqlite */>((*p_0)) };
                std::string id_182 { id_181.insert };
                Bytes id_183 { id_182 };
                Pointer id_184 { let_res_147.writeBytes(id_183) };
                let_res_142 = id_184;
              }
              Pointer let_res_185;
              {
                Pointer srec_dst_322 { let_res_142 };
                ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_186 { std::get<3 /* Sqlite */>((*p_0)) };
                std::string id_187 { id_186.create };
                uint32_t id_188 { (uint32_t)id_187.size() };
                Vec<1, uint32_t> id_189 {  id_188  };
                Pointer let_res_190;
                {
                  Vec<1, uint32_t> leb128_sz_323 { id_189 };
                  Vec<1, Pointer> id_191 {  srec_dst_322  };
                  Pointer let_res_192;
                  {
                    Vec<1, Pointer> leb128_ptr_324 { id_191 };
                    bool while_flag_193 { true };
                    do {
                      uint8_t id_194 { 0 };
                      uint8_t id_195 { 0 };
                      Pointer id_196 { leb128_ptr_324[id_195] };
                      uint32_t id_197 { 128U };
                      uint8_t id_198 { 0 };
                      uint32_t id_199 { leb128_sz_323[id_198] };
                      bool id_200 { bool(id_197 > id_199) };
                      uint8_t choose_res_201;
                      if (id_200) {
                        uint8_t id_202 { 0 };
                        uint32_t id_203 { leb128_sz_323[id_202] };
                        uint8_t id_204 { uint8_t(id_203) };
                        choose_res_201 = id_204;
                      } else {
                        uint8_t id_205 { 0 };
                        uint32_t id_206 { leb128_sz_323[id_205] };
                        uint8_t id_207 { uint8_t(id_206) };
                        uint8_t id_208 { 128 };
                        uint8_t id_209 { uint8_t(id_207 | id_208) };
                        choose_res_201 = id_209;
                      }
                      Pointer id_210 { id_196.writeU8(choose_res_201) };
                      Void id_211 { ((void)(leb128_ptr_324[id_194] = id_210), ::dessser::Void()) };
                      (void)id_211;
                      uint8_t id_212 { 0 };
                      uint8_t id_213 { 0 };
                      uint32_t id_214 { leb128_sz_323[id_213] };
                      uint8_t id_215 { 7 };
                      uint32_t id_216 { uint32_t(id_214 >> id_215) };
                      Void id_217 { ((void)(leb128_sz_323[id_212] = id_216), ::dessser::Void()) };
                      (void)id_217;
                      uint8_t id_218 { 0 };
                      uint32_t id_219 { leb128_sz_323[id_218] };
                      uint32_t id_220 { 0U };
                      bool id_221 { bool(id_219 > id_220) };
                      while_flag_193 = id_221;
                      if (while_flag_193) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_193);
                    (void)::dessser::Void();
                    uint8_t id_222 { 0 };
                    Pointer id_223 { leb128_ptr_324[id_222] };
                    let_res_192 = id_223;
                  }
                  let_res_190 = let_res_192;
                }
                ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_224 { std::get<3 /* Sqlite */>((*p_0)) };
                std::string id_225 { id_224.create };
                Bytes id_226 { id_225 };
                Pointer id_227 { let_res_190.writeBytes(id_226) };
                let_res_185 = id_227;
              }
              choose_res_99 = let_res_185;
            } else {
              uint16_t id_228 { uint16_t((*p_0).index()) };
              uint16_t id_229 { 4 };
              bool id_230 { bool(id_228 == id_229) };
              Void id_231 { ((void)(assert(id_230)), ::dessser::Void()) };
              (void)id_231;
              ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_232 { std::get<4 /* Kafka */>((*p_0)) };
              Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> id_233 { id_232.options };
              uint32_t id_234 { id_233.size() };
              Vec<1, uint32_t> id_235 {  id_234  };
              Pointer let_res_236;
              {
                Vec<1, uint32_t> leb128_sz_299 { id_235 };
                Vec<1, Pointer> id_237 {  ssum_dst_298  };
                Pointer let_res_238;
                {
                  Vec<1, Pointer> leb128_ptr_300 { id_237 };
                  bool while_flag_239 { true };
                  do {
                    uint8_t id_240 { 0 };
                    uint8_t id_241 { 0 };
                    Pointer id_242 { leb128_ptr_300[id_241] };
                    uint32_t id_243 { 128U };
                    uint8_t id_244 { 0 };
                    uint32_t id_245 { leb128_sz_299[id_244] };
                    bool id_246 { bool(id_243 > id_245) };
                    uint8_t choose_res_247;
                    if (id_246) {
                      uint8_t id_248 { 0 };
                      uint32_t id_249 { leb128_sz_299[id_248] };
                      uint8_t id_250 { uint8_t(id_249) };
                      choose_res_247 = id_250;
                    } else {
                      uint8_t id_251 { 0 };
                      uint32_t id_252 { leb128_sz_299[id_251] };
                      uint8_t id_253 { uint8_t(id_252) };
                      uint8_t id_254 { 128 };
                      uint8_t id_255 { uint8_t(id_253 | id_254) };
                      choose_res_247 = id_255;
                    }
                    Pointer id_256 { id_242.writeU8(choose_res_247) };
                    Void id_257 { ((void)(leb128_ptr_300[id_240] = id_256), ::dessser::Void()) };
                    (void)id_257;
                    uint8_t id_258 { 0 };
                    uint8_t id_259 { 0 };
                    uint32_t id_260 { leb128_sz_299[id_259] };
                    uint8_t id_261 { 7 };
                    uint32_t id_262 { uint32_t(id_260 >> id_261) };
                    Void id_263 { ((void)(leb128_sz_299[id_258] = id_262), ::dessser::Void()) };
                    (void)id_263;
                    uint8_t id_264 { 0 };
                    uint32_t id_265 { leb128_sz_299[id_264] };
                    uint32_t id_266 { 0U };
                    bool id_267 { bool(id_265 > id_266) };
                    while_flag_239 = id_267;
                    if (while_flag_239) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_239);
                  (void)::dessser::Void();
                  uint8_t id_268 { 0 };
                  Pointer id_269 { leb128_ptr_300[id_268] };
                  let_res_238 = id_269;
                }
                let_res_236 = let_res_238;
              }
              Vec<1, Pointer> id_270 {  let_res_236  };
              Pointer let_res_271;
              {
                Vec<1, Pointer> dst_ref_301 { id_270 };
                int32_t id_272 { 0L };
                Vec<1, int32_t> id_273 {  id_272  };
                Pointer let_res_274;
                {
                  Vec<1, int32_t> n_ref_302 { id_273 };
                  ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_275 { std::get<4 /* Kafka */>((*p_0)) };
                  Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> id_276 { id_275.options };
                  for (::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463 const &x_303 : id_276) {
                    uint8_t id_277 { 0 };
                    uint8_t id_278 { 0 };
                    Pointer id_279 { dst_ref_301[id_278] };
                    Pointer let_res_280;
                    {
                      Pointer stup_dst_304 { id_279 };
                      std::string id_281 { std::get<0>(x_303) };
                      uint32_t id_282 { (uint32_t)id_281.size() };
                      Vec<1, uint32_t> id_283 {  id_282  };
                      Pointer let_res_284;
                      {
                        Vec<1, uint32_t> leb128_sz_305 { id_283 };
                        Vec<1, Pointer> id_285 {  stup_dst_304  };
                        Pointer let_res_286;
                        {
                          Vec<1, Pointer> leb128_ptr_306 { id_285 };
                          bool while_flag_287 { true };
                          do {
                            uint8_t id_288 { 0 };
                            uint8_t id_289 { 0 };
                            Pointer id_290 { leb128_ptr_306[id_289] };
                            uint32_t id_291 { 128U };
                            uint8_t id_292 { 0 };
                            uint32_t id_293 { leb128_sz_305[id_292] };
                            bool id_294 { bool(id_291 > id_293) };
                            uint8_t choose_res_295;
                            if (id_294) {
                              uint8_t id_296 { 0 };
                              uint32_t id_297 { leb128_sz_305[id_296] };
                              uint8_t id_298 { uint8_t(id_297) };
                              choose_res_295 = id_298;
                            } else {
                              uint8_t id_299 { 0 };
                              uint32_t id_300 { leb128_sz_305[id_299] };
                              uint8_t id_301 { uint8_t(id_300) };
                              uint8_t id_302 { 128 };
                              uint8_t id_303 { uint8_t(id_301 | id_302) };
                              choose_res_295 = id_303;
                            }
                            Pointer id_304 { id_290.writeU8(choose_res_295) };
                            Void id_305 { ((void)(leb128_ptr_306[id_288] = id_304), ::dessser::Void()) };
                            (void)id_305;
                            uint8_t id_306 { 0 };
                            uint8_t id_307 { 0 };
                            uint32_t id_308 { leb128_sz_305[id_307] };
                            uint8_t id_309 { 7 };
                            uint32_t id_310 { uint32_t(id_308 >> id_309) };
                            Void id_311 { ((void)(leb128_sz_305[id_306] = id_310), ::dessser::Void()) };
                            (void)id_311;
                            uint8_t id_312 { 0 };
                            uint32_t id_313 { leb128_sz_305[id_312] };
                            uint32_t id_314 { 0U };
                            bool id_315 { bool(id_313 > id_314) };
                            while_flag_287 = id_315;
                            if (while_flag_287) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_287);
                          (void)::dessser::Void();
                          uint8_t id_316 { 0 };
                          Pointer id_317 { leb128_ptr_306[id_316] };
                          let_res_286 = id_317;
                        }
                        let_res_284 = let_res_286;
                      }
                      std::string id_318 { std::get<0>(x_303) };
                      Bytes id_319 { id_318 };
                      Pointer id_320 { let_res_284.writeBytes(id_319) };
                      let_res_280 = id_320;
                    }
                    Pointer let_res_321;
                    {
                      Pointer stup_dst_307 { let_res_280 };
                      std::string id_322 { std::get<1>(x_303) };
                      uint32_t id_323 { (uint32_t)id_322.size() };
                      Vec<1, uint32_t> id_324 {  id_323  };
                      Pointer let_res_325;
                      {
                        Vec<1, uint32_t> leb128_sz_308 { id_324 };
                        Vec<1, Pointer> id_326 {  stup_dst_307  };
                        Pointer let_res_327;
                        {
                          Vec<1, Pointer> leb128_ptr_309 { id_326 };
                          bool while_flag_328 { true };
                          do {
                            uint8_t id_329 { 0 };
                            uint8_t id_330 { 0 };
                            Pointer id_331 { leb128_ptr_309[id_330] };
                            uint32_t id_332 { 128U };
                            uint8_t id_333 { 0 };
                            uint32_t id_334 { leb128_sz_308[id_333] };
                            bool id_335 { bool(id_332 > id_334) };
                            uint8_t choose_res_336;
                            if (id_335) {
                              uint8_t id_337 { 0 };
                              uint32_t id_338 { leb128_sz_308[id_337] };
                              uint8_t id_339 { uint8_t(id_338) };
                              choose_res_336 = id_339;
                            } else {
                              uint8_t id_340 { 0 };
                              uint32_t id_341 { leb128_sz_308[id_340] };
                              uint8_t id_342 { uint8_t(id_341) };
                              uint8_t id_343 { 128 };
                              uint8_t id_344 { uint8_t(id_342 | id_343) };
                              choose_res_336 = id_344;
                            }
                            Pointer id_345 { id_331.writeU8(choose_res_336) };
                            Void id_346 { ((void)(leb128_ptr_309[id_329] = id_345), ::dessser::Void()) };
                            (void)id_346;
                            uint8_t id_347 { 0 };
                            uint8_t id_348 { 0 };
                            uint32_t id_349 { leb128_sz_308[id_348] };
                            uint8_t id_350 { 7 };
                            uint32_t id_351 { uint32_t(id_349 >> id_350) };
                            Void id_352 { ((void)(leb128_sz_308[id_347] = id_351), ::dessser::Void()) };
                            (void)id_352;
                            uint8_t id_353 { 0 };
                            uint32_t id_354 { leb128_sz_308[id_353] };
                            uint32_t id_355 { 0U };
                            bool id_356 { bool(id_354 > id_355) };
                            while_flag_328 = id_356;
                            if (while_flag_328) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_328);
                          (void)::dessser::Void();
                          uint8_t id_357 { 0 };
                          Pointer id_358 { leb128_ptr_309[id_357] };
                          let_res_327 = id_358;
                        }
                        let_res_325 = let_res_327;
                      }
                      std::string id_359 { std::get<1>(x_303) };
                      Bytes id_360 { id_359 };
                      Pointer id_361 { let_res_325.writeBytes(id_360) };
                      let_res_321 = id_361;
                    }
                    Void id_362 { ((void)(dst_ref_301[id_277] = let_res_321), ::dessser::Void()) };
                    (void)id_362;
                    uint8_t id_363 { 0 };
                    int32_t id_364 { 1L };
                    uint8_t id_365 { 0 };
                    int32_t id_366 { n_ref_302[id_365] };
                    int32_t id_367 { int32_t(id_364 + id_366) };
                    Void id_368 { ((void)(n_ref_302[id_363] = id_367), ::dessser::Void()) };
                    (void)id_368;
                    (void)id_368;
                  }
                  (void)::dessser::Void();
                  uint8_t id_369 { 0 };
                  Pointer id_370 { dst_ref_301[id_369] };
                  let_res_274 = id_370;
                }
                let_res_271 = let_res_274;
              }
              Pointer let_res_371;
              {
                Pointer srec_dst_310 { let_res_271 };
                ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_372 { std::get<4 /* Kafka */>((*p_0)) };
                std::string id_373 { id_372.topic };
                uint32_t id_374 { (uint32_t)id_373.size() };
                Vec<1, uint32_t> id_375 {  id_374  };
                Pointer let_res_376;
                {
                  Vec<1, uint32_t> leb128_sz_311 { id_375 };
                  Vec<1, Pointer> id_377 {  srec_dst_310  };
                  Pointer let_res_378;
                  {
                    Vec<1, Pointer> leb128_ptr_312 { id_377 };
                    bool while_flag_379 { true };
                    do {
                      uint8_t id_380 { 0 };
                      uint8_t id_381 { 0 };
                      Pointer id_382 { leb128_ptr_312[id_381] };
                      uint32_t id_383 { 128U };
                      uint8_t id_384 { 0 };
                      uint32_t id_385 { leb128_sz_311[id_384] };
                      bool id_386 { bool(id_383 > id_385) };
                      uint8_t choose_res_387;
                      if (id_386) {
                        uint8_t id_388 { 0 };
                        uint32_t id_389 { leb128_sz_311[id_388] };
                        uint8_t id_390 { uint8_t(id_389) };
                        choose_res_387 = id_390;
                      } else {
                        uint8_t id_391 { 0 };
                        uint32_t id_392 { leb128_sz_311[id_391] };
                        uint8_t id_393 { uint8_t(id_392) };
                        uint8_t id_394 { 128 };
                        uint8_t id_395 { uint8_t(id_393 | id_394) };
                        choose_res_387 = id_395;
                      }
                      Pointer id_396 { id_382.writeU8(choose_res_387) };
                      Void id_397 { ((void)(leb128_ptr_312[id_380] = id_396), ::dessser::Void()) };
                      (void)id_397;
                      uint8_t id_398 { 0 };
                      uint8_t id_399 { 0 };
                      uint32_t id_400 { leb128_sz_311[id_399] };
                      uint8_t id_401 { 7 };
                      uint32_t id_402 { uint32_t(id_400 >> id_401) };
                      Void id_403 { ((void)(leb128_sz_311[id_398] = id_402), ::dessser::Void()) };
                      (void)id_403;
                      uint8_t id_404 { 0 };
                      uint32_t id_405 { leb128_sz_311[id_404] };
                      uint32_t id_406 { 0U };
                      bool id_407 { bool(id_405 > id_406) };
                      while_flag_379 = id_407;
                      if (while_flag_379) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_379);
                    (void)::dessser::Void();
                    uint8_t id_408 { 0 };
                    Pointer id_409 { leb128_ptr_312[id_408] };
                    let_res_378 = id_409;
                  }
                  let_res_376 = let_res_378;
                }
                ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_410 { std::get<4 /* Kafka */>((*p_0)) };
                std::string id_411 { id_410.topic };
                Bytes id_412 { id_411 };
                Pointer id_413 { let_res_376.writeBytes(id_412) };
                let_res_371 = id_413;
              }
              Pointer let_res_414;
              {
                Pointer srec_dst_313 { let_res_371 };
                ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_415 { std::get<4 /* Kafka */>((*p_0)) };
                uint16_t id_416 { id_415.partition };
                Pointer id_417 { srec_dst_313.writeU16Le(id_416) };
                let_res_414 = id_417;
              }
              Pointer let_res_418;
              {
                Pointer srec_dst_314 { let_res_414 };
                ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_419 { std::get<4 /* Kafka */>((*p_0)) };
                std::string id_420 { id_419.text };
                uint32_t id_421 { (uint32_t)id_420.size() };
                Vec<1, uint32_t> id_422 {  id_421  };
                Pointer let_res_423;
                {
                  Vec<1, uint32_t> leb128_sz_315 { id_422 };
                  Vec<1, Pointer> id_424 {  srec_dst_314  };
                  Pointer let_res_425;
                  {
                    Vec<1, Pointer> leb128_ptr_316 { id_424 };
                    bool while_flag_426 { true };
                    do {
                      uint8_t id_427 { 0 };
                      uint8_t id_428 { 0 };
                      Pointer id_429 { leb128_ptr_316[id_428] };
                      uint32_t id_430 { 128U };
                      uint8_t id_431 { 0 };
                      uint32_t id_432 { leb128_sz_315[id_431] };
                      bool id_433 { bool(id_430 > id_432) };
                      uint8_t choose_res_434;
                      if (id_433) {
                        uint8_t id_435 { 0 };
                        uint32_t id_436 { leb128_sz_315[id_435] };
                        uint8_t id_437 { uint8_t(id_436) };
                        choose_res_434 = id_437;
                      } else {
                        uint8_t id_438 { 0 };
                        uint32_t id_439 { leb128_sz_315[id_438] };
                        uint8_t id_440 { uint8_t(id_439) };
                        uint8_t id_441 { 128 };
                        uint8_t id_442 { uint8_t(id_440 | id_441) };
                        choose_res_434 = id_442;
                      }
                      Pointer id_443 { id_429.writeU8(choose_res_434) };
                      Void id_444 { ((void)(leb128_ptr_316[id_427] = id_443), ::dessser::Void()) };
                      (void)id_444;
                      uint8_t id_445 { 0 };
                      uint8_t id_446 { 0 };
                      uint32_t id_447 { leb128_sz_315[id_446] };
                      uint8_t id_448 { 7 };
                      uint32_t id_449 { uint32_t(id_447 >> id_448) };
                      Void id_450 { ((void)(leb128_sz_315[id_445] = id_449), ::dessser::Void()) };
                      (void)id_450;
                      uint8_t id_451 { 0 };
                      uint32_t id_452 { leb128_sz_315[id_451] };
                      uint32_t id_453 { 0U };
                      bool id_454 { bool(id_452 > id_453) };
                      while_flag_426 = id_454;
                      if (while_flag_426) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_426);
                    (void)::dessser::Void();
                    uint8_t id_455 { 0 };
                    Pointer id_456 { leb128_ptr_316[id_455] };
                    let_res_425 = id_456;
                  }
                  let_res_423 = let_res_425;
                }
                ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_457 { std::get<4 /* Kafka */>((*p_0)) };
                std::string id_458 { id_457.text };
                Bytes id_459 { id_458 };
                Pointer id_460 { let_res_423.writeBytes(id_459) };
                let_res_418 = id_460;
              }
              choose_res_99 = let_res_418;
            }
            choose_res_55 = choose_res_99;
          }
          choose_res_11 = choose_res_55;
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
std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::via> ,Pointer)> via_to_row_binary(via_to_row_binary_init());

/* 
    (fun ("{via: (via AS [Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]); timeout: FLOAT}" "Ptr")
      (let "srec_dst_329" (apply (identifier "via-to-row-binary") (get-field "via" (param 0)) (param 1)) (write-u64 little-endian (identifier "srec_dst_329") (u64-of-float (get-field "timeout" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::t> ,Pointer)> fun461 { [&](std::shared_ptr<::dessser::gen::alerting_contact::t>  p_0, Pointer p_1) {
    std::shared_ptr<::dessser::gen::alerting_contact::via>  id_462 { (*p_0).via };
    Pointer id_463 { via_to_row_binary(id_462, p_1) };
    Pointer let_res_464;
    {
      Pointer srec_dst_329 { id_463 };
      double id_465 { (*p_0).timeout };
      uint64_t id_466 { qword_of_float(id_465) };
      Pointer id_467 { srec_dst_329.writeU64Le(id_466) };
      let_res_464 = id_467;
    }
    return let_res_464;
  }
   };
  return fun461;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0)))
          (add (size 2)
            (add
              (let "n_ref_293" (make-vec (string-length (get-alt "Exec" (param 0))))
                (let "lebsz_ref_294" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_293")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_294")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_294") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_294")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_294")))))) 
              (size-of-u32 (string-length (get-alt "Exec" (param 0))))))
          (if (eq (u16 2) (label-of (param 0)))
            (add (size 2)
              (add
                (let "n_ref_290" (make-vec (string-length (get-alt "SysLog" (param 0))))
                  (let "lebsz_ref_291" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_290")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_291")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_291") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_291")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_291")))))) 
                (size-of-u32 (string-length (get-alt "SysLog" (param 0))))))
            (if (eq (u16 3) (label-of (param 0)))
              (let "sz_285"
                (let "sz_281"
                  (add (size 2)
                    (add
                      (let "n_ref_279" (make-vec (string-length (get-field "file" (get-alt "Sqlite" (param 0)))))
                        (let "lebsz_ref_280" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_279")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_280")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_280") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_280")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_280")))))) 
                      (size-of-u32 (string-length (get-field "file" (get-alt "Sqlite" (param 0)))))))
                  (add (identifier "sz_281")
                    (add
                      (let "n_ref_283" (make-vec (string-length (get-field "insert" (get-alt "Sqlite" (param 0)))))
                        (let "lebsz_ref_284" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_283")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_284")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_284") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_284")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_284")))))) 
                      (size-of-u32 (string-length (get-field "insert" (get-alt "Sqlite" (param 0))))))))
                (add (identifier "sz_285")
                  (add
                    (let "n_ref_287" (make-vec (string-length (get-field "create" (get-alt "Sqlite" (param 0)))))
                      (let "lebsz_ref_288" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_287")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_288")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_288") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_288")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_288")))))) 
                    (size-of-u32 (string-length (get-field "create" (get-alt "Sqlite" (param 0))))))))
              (seq (assert (eq (label-of (param 0)) (u16 4)))
                (let "sz_273"
                  (add
                    (let "sz_268"
                      (let "sz_ref_258"
                        (make-vec
                          (add (size 2)
                            (let "n_ref_256" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (param 0)))))
                              (let "lebsz_ref_257" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_256")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_257")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_257") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_257")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_257"))))))))
                        (seq
                          (let "repeat_n_259" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-field "options" (get-alt "Kafka" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_259")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_258")
                                  (let "sz_264"
                                    (let "sz_260" (unsafe-nth (u8 0) (identifier "sz_ref_258"))
                                      (add (identifier "sz_260")
                                        (let "wlen_261" (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_259")) (get-field "options" (get-alt "Kafka" (param 0))))))
                                          (add
                                            (let "n_ref_262" (make-vec (identifier "wlen_261"))
                                              (let "lebsz_ref_263" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_262")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_263")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_263") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_263")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_263")))))) 
                                            (size-of-u32 (identifier "wlen_261"))))))
                                    (add (identifier "sz_264")
                                      (let "wlen_265" (string-length (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_259")) (get-field "options" (get-alt "Kafka" (param 0))))))
                                        (add
                                          (let "n_ref_266" (make-vec (identifier "wlen_265"))
                                            (let "lebsz_ref_267" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_266")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_267")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_267") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_267")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_267")))))) 
                                          (size-of-u32 (identifier "wlen_265"))))))) 
                                (set-vec (u8 0) (identifier "repeat_n_259") (add (unsafe-nth (u8 0) (identifier "repeat_n_259")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_258"))))
                      (add (identifier "sz_268")
                        (add
                          (let "n_ref_270" (make-vec (string-length (get-field "topic" (get-alt "Kafka" (param 0)))))
                            (let "lebsz_ref_271" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_270")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_271")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_271") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_271")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_271")))))) 
                          (size-of-u32 (string-length (get-field "topic" (get-alt "Kafka" (param 0)))))))) 
                    (size 2))
                  (add (identifier "sz_273")
                    (add
                      (let "n_ref_275" (make-vec (string-length (get-field "text" (get-alt "Kafka" (param 0)))))
                        (let "lebsz_ref_276" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_275")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_276")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_276") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_276")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_276")))))) 
                      (size-of-u32 (string-length (get-field "text" (get-alt "Kafka" (param 0))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alerting_contact::via> )> via_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alerting_contact::via> )> fun468 { [&](std::shared_ptr<::dessser::gen::alerting_contact::via>  p_0) {
    uint16_t id_469 { 0 };
    uint16_t id_470 { uint16_t((*p_0).index()) };
    bool id_471 { bool(id_469 == id_470) };
    Size choose_res_472;
    if (id_471) {
      Size id_473 { 2UL };
      choose_res_472 = id_473;
    } else {
      uint16_t id_474 { 1 };
      uint16_t id_475 { uint16_t((*p_0).index()) };
      bool id_476 { bool(id_474 == id_475) };
      Size choose_res_477;
      if (id_476) {
        Size id_478 { 2UL };
        std::string id_479 { std::get<1 /* Exec */>((*p_0)) };
        uint32_t id_480 { (uint32_t)id_479.size() };
        Vec<1, uint32_t> id_481 {  id_480  };
        Size let_res_482;
        {
          Vec<1, uint32_t> n_ref_293 { id_481 };
          uint32_t id_483 { 1U };
          Vec<1, uint32_t> id_484 {  id_483  };
          Size let_res_485;
          {
            Vec<1, uint32_t> lebsz_ref_294 { id_484 };
            bool while_flag_486 { true };
            do {
              uint8_t id_487 { 0 };
              uint32_t id_488 { n_ref_293[id_487] };
              uint8_t id_489 { 0 };
              uint32_t id_490 { lebsz_ref_294[id_489] };
              uint8_t id_491 { 7 };
              uint32_t id_492 { uint32_t(id_490 << id_491) };
              bool id_493 { bool(id_488 >= id_492) };
              while_flag_486 = id_493;
              if (while_flag_486) {
                uint8_t id_494 { 0 };
                uint8_t id_495 { 0 };
                uint32_t id_496 { lebsz_ref_294[id_495] };
                uint32_t id_497 { 1U };
                uint32_t id_498 { uint32_t(id_496 + id_497) };
                Void id_499 { ((void)(lebsz_ref_294[id_494] = id_498), ::dessser::Void()) };
                (void)id_499;
              }
            } while (while_flag_486);
            (void)::dessser::Void();
            uint8_t id_500 { 0 };
            uint32_t id_501 { lebsz_ref_294[id_500] };
            Size id_502 { Size(id_501) };
            let_res_485 = id_502;
          }
          let_res_482 = let_res_485;
        }
        std::string id_503 { std::get<1 /* Exec */>((*p_0)) };
        uint32_t id_504 { (uint32_t)id_503.size() };
        Size id_505 { Size(id_504) };
        Size id_506 { Size(let_res_482 + id_505) };
        Size id_507 { Size(id_478 + id_506) };
        choose_res_477 = id_507;
      } else {
        uint16_t id_508 { 2 };
        uint16_t id_509 { uint16_t((*p_0).index()) };
        bool id_510 { bool(id_508 == id_509) };
        Size choose_res_511;
        if (id_510) {
          Size id_512 { 2UL };
          std::string id_513 { std::get<2 /* SysLog */>((*p_0)) };
          uint32_t id_514 { (uint32_t)id_513.size() };
          Vec<1, uint32_t> id_515 {  id_514  };
          Size let_res_516;
          {
            Vec<1, uint32_t> n_ref_290 { id_515 };
            uint32_t id_517 { 1U };
            Vec<1, uint32_t> id_518 {  id_517  };
            Size let_res_519;
            {
              Vec<1, uint32_t> lebsz_ref_291 { id_518 };
              bool while_flag_520 { true };
              do {
                uint8_t id_521 { 0 };
                uint32_t id_522 { n_ref_290[id_521] };
                uint8_t id_523 { 0 };
                uint32_t id_524 { lebsz_ref_291[id_523] };
                uint8_t id_525 { 7 };
                uint32_t id_526 { uint32_t(id_524 << id_525) };
                bool id_527 { bool(id_522 >= id_526) };
                while_flag_520 = id_527;
                if (while_flag_520) {
                  uint8_t id_528 { 0 };
                  uint8_t id_529 { 0 };
                  uint32_t id_530 { lebsz_ref_291[id_529] };
                  uint32_t id_531 { 1U };
                  uint32_t id_532 { uint32_t(id_530 + id_531) };
                  Void id_533 { ((void)(lebsz_ref_291[id_528] = id_532), ::dessser::Void()) };
                  (void)id_533;
                }
              } while (while_flag_520);
              (void)::dessser::Void();
              uint8_t id_534 { 0 };
              uint32_t id_535 { lebsz_ref_291[id_534] };
              Size id_536 { Size(id_535) };
              let_res_519 = id_536;
            }
            let_res_516 = let_res_519;
          }
          std::string id_537 { std::get<2 /* SysLog */>((*p_0)) };
          uint32_t id_538 { (uint32_t)id_537.size() };
          Size id_539 { Size(id_538) };
          Size id_540 { Size(let_res_516 + id_539) };
          Size id_541 { Size(id_512 + id_540) };
          choose_res_511 = id_541;
        } else {
          uint16_t id_542 { 3 };
          uint16_t id_543 { uint16_t((*p_0).index()) };
          bool id_544 { bool(id_542 == id_543) };
          Size choose_res_545;
          if (id_544) {
            Size id_546 { 2UL };
            ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_547 { std::get<3 /* Sqlite */>((*p_0)) };
            std::string id_548 { id_547.file };
            uint32_t id_549 { (uint32_t)id_548.size() };
            Vec<1, uint32_t> id_550 {  id_549  };
            Size let_res_551;
            {
              Vec<1, uint32_t> n_ref_279 { id_550 };
              uint32_t id_552 { 1U };
              Vec<1, uint32_t> id_553 {  id_552  };
              Size let_res_554;
              {
                Vec<1, uint32_t> lebsz_ref_280 { id_553 };
                bool while_flag_555 { true };
                do {
                  uint8_t id_556 { 0 };
                  uint32_t id_557 { n_ref_279[id_556] };
                  uint8_t id_558 { 0 };
                  uint32_t id_559 { lebsz_ref_280[id_558] };
                  uint8_t id_560 { 7 };
                  uint32_t id_561 { uint32_t(id_559 << id_560) };
                  bool id_562 { bool(id_557 >= id_561) };
                  while_flag_555 = id_562;
                  if (while_flag_555) {
                    uint8_t id_563 { 0 };
                    uint8_t id_564 { 0 };
                    uint32_t id_565 { lebsz_ref_280[id_564] };
                    uint32_t id_566 { 1U };
                    uint32_t id_567 { uint32_t(id_565 + id_566) };
                    Void id_568 { ((void)(lebsz_ref_280[id_563] = id_567), ::dessser::Void()) };
                    (void)id_568;
                  }
                } while (while_flag_555);
                (void)::dessser::Void();
                uint8_t id_569 { 0 };
                uint32_t id_570 { lebsz_ref_280[id_569] };
                Size id_571 { Size(id_570) };
                let_res_554 = id_571;
              }
              let_res_551 = let_res_554;
            }
            ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_572 { std::get<3 /* Sqlite */>((*p_0)) };
            std::string id_573 { id_572.file };
            uint32_t id_574 { (uint32_t)id_573.size() };
            Size id_575 { Size(id_574) };
            Size id_576 { Size(let_res_551 + id_575) };
            Size id_577 { Size(id_546 + id_576) };
            Size let_res_578;
            {
              Size sz_281 { id_577 };
              ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_579 { std::get<3 /* Sqlite */>((*p_0)) };
              std::string id_580 { id_579.insert };
              uint32_t id_581 { (uint32_t)id_580.size() };
              Vec<1, uint32_t> id_582 {  id_581  };
              Size let_res_583;
              {
                Vec<1, uint32_t> n_ref_283 { id_582 };
                uint32_t id_584 { 1U };
                Vec<1, uint32_t> id_585 {  id_584  };
                Size let_res_586;
                {
                  Vec<1, uint32_t> lebsz_ref_284 { id_585 };
                  bool while_flag_587 { true };
                  do {
                    uint8_t id_588 { 0 };
                    uint32_t id_589 { n_ref_283[id_588] };
                    uint8_t id_590 { 0 };
                    uint32_t id_591 { lebsz_ref_284[id_590] };
                    uint8_t id_592 { 7 };
                    uint32_t id_593 { uint32_t(id_591 << id_592) };
                    bool id_594 { bool(id_589 >= id_593) };
                    while_flag_587 = id_594;
                    if (while_flag_587) {
                      uint8_t id_595 { 0 };
                      uint8_t id_596 { 0 };
                      uint32_t id_597 { lebsz_ref_284[id_596] };
                      uint32_t id_598 { 1U };
                      uint32_t id_599 { uint32_t(id_597 + id_598) };
                      Void id_600 { ((void)(lebsz_ref_284[id_595] = id_599), ::dessser::Void()) };
                      (void)id_600;
                    }
                  } while (while_flag_587);
                  (void)::dessser::Void();
                  uint8_t id_601 { 0 };
                  uint32_t id_602 { lebsz_ref_284[id_601] };
                  Size id_603 { Size(id_602) };
                  let_res_586 = id_603;
                }
                let_res_583 = let_res_586;
              }
              ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_604 { std::get<3 /* Sqlite */>((*p_0)) };
              std::string id_605 { id_604.insert };
              uint32_t id_606 { (uint32_t)id_605.size() };
              Size id_607 { Size(id_606) };
              Size id_608 { Size(let_res_583 + id_607) };
              Size id_609 { Size(sz_281 + id_608) };
              let_res_578 = id_609;
            }
            Size let_res_610;
            {
              Size sz_285 { let_res_578 };
              ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_611 { std::get<3 /* Sqlite */>((*p_0)) };
              std::string id_612 { id_611.create };
              uint32_t id_613 { (uint32_t)id_612.size() };
              Vec<1, uint32_t> id_614 {  id_613  };
              Size let_res_615;
              {
                Vec<1, uint32_t> n_ref_287 { id_614 };
                uint32_t id_616 { 1U };
                Vec<1, uint32_t> id_617 {  id_616  };
                Size let_res_618;
                {
                  Vec<1, uint32_t> lebsz_ref_288 { id_617 };
                  bool while_flag_619 { true };
                  do {
                    uint8_t id_620 { 0 };
                    uint32_t id_621 { n_ref_287[id_620] };
                    uint8_t id_622 { 0 };
                    uint32_t id_623 { lebsz_ref_288[id_622] };
                    uint8_t id_624 { 7 };
                    uint32_t id_625 { uint32_t(id_623 << id_624) };
                    bool id_626 { bool(id_621 >= id_625) };
                    while_flag_619 = id_626;
                    if (while_flag_619) {
                      uint8_t id_627 { 0 };
                      uint8_t id_628 { 0 };
                      uint32_t id_629 { lebsz_ref_288[id_628] };
                      uint32_t id_630 { 1U };
                      uint32_t id_631 { uint32_t(id_629 + id_630) };
                      Void id_632 { ((void)(lebsz_ref_288[id_627] = id_631), ::dessser::Void()) };
                      (void)id_632;
                    }
                  } while (while_flag_619);
                  (void)::dessser::Void();
                  uint8_t id_633 { 0 };
                  uint32_t id_634 { lebsz_ref_288[id_633] };
                  Size id_635 { Size(id_634) };
                  let_res_618 = id_635;
                }
                let_res_615 = let_res_618;
              }
              ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_636 { std::get<3 /* Sqlite */>((*p_0)) };
              std::string id_637 { id_636.create };
              uint32_t id_638 { (uint32_t)id_637.size() };
              Size id_639 { Size(id_638) };
              Size id_640 { Size(let_res_615 + id_639) };
              Size id_641 { Size(sz_285 + id_640) };
              let_res_610 = id_641;
            }
            choose_res_545 = let_res_610;
          } else {
            uint16_t id_642 { uint16_t((*p_0).index()) };
            uint16_t id_643 { 4 };
            bool id_644 { bool(id_642 == id_643) };
            Void id_645 { ((void)(assert(id_644)), ::dessser::Void()) };
            (void)id_645;
            Size id_646 { 2UL };
            ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_647 { std::get<4 /* Kafka */>((*p_0)) };
            Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> id_648 { id_647.options };
            uint32_t id_649 { id_648.size() };
            Vec<1, uint32_t> id_650 {  id_649  };
            Size let_res_651;
            {
              Vec<1, uint32_t> n_ref_256 { id_650 };
              uint32_t id_652 { 1U };
              Vec<1, uint32_t> id_653 {  id_652  };
              Size let_res_654;
              {
                Vec<1, uint32_t> lebsz_ref_257 { id_653 };
                bool while_flag_655 { true };
                do {
                  uint8_t id_656 { 0 };
                  uint32_t id_657 { n_ref_256[id_656] };
                  uint8_t id_658 { 0 };
                  uint32_t id_659 { lebsz_ref_257[id_658] };
                  uint8_t id_660 { 7 };
                  uint32_t id_661 { uint32_t(id_659 << id_660) };
                  bool id_662 { bool(id_657 >= id_661) };
                  while_flag_655 = id_662;
                  if (while_flag_655) {
                    uint8_t id_663 { 0 };
                    uint8_t id_664 { 0 };
                    uint32_t id_665 { lebsz_ref_257[id_664] };
                    uint32_t id_666 { 1U };
                    uint32_t id_667 { uint32_t(id_665 + id_666) };
                    Void id_668 { ((void)(lebsz_ref_257[id_663] = id_667), ::dessser::Void()) };
                    (void)id_668;
                  }
                } while (while_flag_655);
                (void)::dessser::Void();
                uint8_t id_669 { 0 };
                uint32_t id_670 { lebsz_ref_257[id_669] };
                Size id_671 { Size(id_670) };
                let_res_654 = id_671;
              }
              let_res_651 = let_res_654;
            }
            Size id_672 { Size(id_646 + let_res_651) };
            Vec<1, Size> id_673 {  id_672  };
            Size let_res_674;
            {
              Vec<1, Size> sz_ref_258 { id_673 };
              int32_t id_675 { 0L };
              Vec<1, int32_t> id_676 {  id_675  };
              {
                Vec<1, int32_t> repeat_n_259 { id_676 };
                bool while_flag_677 { true };
                do {
                  ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_678 { std::get<4 /* Kafka */>((*p_0)) };
                  Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> id_679 { id_678.options };
                  uint32_t id_680 { id_679.size() };
                  int32_t id_681 { int32_t(id_680) };
                  uint8_t id_682 { 0 };
                  int32_t id_683 { repeat_n_259[id_682] };
                  bool id_684 { bool(id_681 > id_683) };
                  while_flag_677 = id_684;
                  if (while_flag_677) {
                    uint8_t id_685 { 0 };
                    uint8_t id_686 { 0 };
                    Size id_687 { sz_ref_258[id_686] };
                    Size let_res_688;
                    {
                      Size sz_260 { id_687 };
                      uint8_t id_689 { 0 };
                      int32_t id_690 { repeat_n_259[id_689] };
                      ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_691 { std::get<4 /* Kafka */>((*p_0)) };
                      Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> id_692 { id_691.options };
                      ::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463 id_693 { id_692[id_690] };
                      std::string id_694 { std::get<0>(id_693) };
                      uint32_t id_695 { (uint32_t)id_694.size() };
                      Size let_res_696;
                      {
                        uint32_t wlen_261 { id_695 };
                        Vec<1, uint32_t> id_697 {  wlen_261  };
                        Size let_res_698;
                        {
                          Vec<1, uint32_t> n_ref_262 { id_697 };
                          uint32_t id_699 { 1U };
                          Vec<1, uint32_t> id_700 {  id_699  };
                          Size let_res_701;
                          {
                            Vec<1, uint32_t> lebsz_ref_263 { id_700 };
                            bool while_flag_702 { true };
                            do {
                              uint8_t id_703 { 0 };
                              uint32_t id_704 { n_ref_262[id_703] };
                              uint8_t id_705 { 0 };
                              uint32_t id_706 { lebsz_ref_263[id_705] };
                              uint8_t id_707 { 7 };
                              uint32_t id_708 { uint32_t(id_706 << id_707) };
                              bool id_709 { bool(id_704 >= id_708) };
                              while_flag_702 = id_709;
                              if (while_flag_702) {
                                uint8_t id_710 { 0 };
                                uint8_t id_711 { 0 };
                                uint32_t id_712 { lebsz_ref_263[id_711] };
                                uint32_t id_713 { 1U };
                                uint32_t id_714 { uint32_t(id_712 + id_713) };
                                Void id_715 { ((void)(lebsz_ref_263[id_710] = id_714), ::dessser::Void()) };
                                (void)id_715;
                              }
                            } while (while_flag_702);
                            (void)::dessser::Void();
                            uint8_t id_716 { 0 };
                            uint32_t id_717 { lebsz_ref_263[id_716] };
                            Size id_718 { Size(id_717) };
                            let_res_701 = id_718;
                          }
                          let_res_698 = let_res_701;
                        }
                        Size id_719 { Size(wlen_261) };
                        Size id_720 { Size(let_res_698 + id_719) };
                        let_res_696 = id_720;
                      }
                      Size id_721 { Size(sz_260 + let_res_696) };
                      let_res_688 = id_721;
                    }
                    Size let_res_722;
                    {
                      Size sz_264 { let_res_688 };
                      uint8_t id_723 { 0 };
                      int32_t id_724 { repeat_n_259[id_723] };
                      ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_725 { std::get<4 /* Kafka */>((*p_0)) };
                      Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> id_726 { id_725.options };
                      ::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463 id_727 { id_726[id_724] };
                      std::string id_728 { std::get<1>(id_727) };
                      uint32_t id_729 { (uint32_t)id_728.size() };
                      Size let_res_730;
                      {
                        uint32_t wlen_265 { id_729 };
                        Vec<1, uint32_t> id_731 {  wlen_265  };
                        Size let_res_732;
                        {
                          Vec<1, uint32_t> n_ref_266 { id_731 };
                          uint32_t id_733 { 1U };
                          Vec<1, uint32_t> id_734 {  id_733  };
                          Size let_res_735;
                          {
                            Vec<1, uint32_t> lebsz_ref_267 { id_734 };
                            bool while_flag_736 { true };
                            do {
                              uint8_t id_737 { 0 };
                              uint32_t id_738 { n_ref_266[id_737] };
                              uint8_t id_739 { 0 };
                              uint32_t id_740 { lebsz_ref_267[id_739] };
                              uint8_t id_741 { 7 };
                              uint32_t id_742 { uint32_t(id_740 << id_741) };
                              bool id_743 { bool(id_738 >= id_742) };
                              while_flag_736 = id_743;
                              if (while_flag_736) {
                                uint8_t id_744 { 0 };
                                uint8_t id_745 { 0 };
                                uint32_t id_746 { lebsz_ref_267[id_745] };
                                uint32_t id_747 { 1U };
                                uint32_t id_748 { uint32_t(id_746 + id_747) };
                                Void id_749 { ((void)(lebsz_ref_267[id_744] = id_748), ::dessser::Void()) };
                                (void)id_749;
                              }
                            } while (while_flag_736);
                            (void)::dessser::Void();
                            uint8_t id_750 { 0 };
                            uint32_t id_751 { lebsz_ref_267[id_750] };
                            Size id_752 { Size(id_751) };
                            let_res_735 = id_752;
                          }
                          let_res_732 = let_res_735;
                        }
                        Size id_753 { Size(wlen_265) };
                        Size id_754 { Size(let_res_732 + id_753) };
                        let_res_730 = id_754;
                      }
                      Size id_755 { Size(sz_264 + let_res_730) };
                      let_res_722 = id_755;
                    }
                    Void id_756 { ((void)(sz_ref_258[id_685] = let_res_722), ::dessser::Void()) };
                    (void)id_756;
                    uint8_t id_757 { 0 };
                    uint8_t id_758 { 0 };
                    int32_t id_759 { repeat_n_259[id_758] };
                    int32_t id_760 { 1L };
                    int32_t id_761 { int32_t(id_759 + id_760) };
                    Void id_762 { ((void)(repeat_n_259[id_757] = id_761), ::dessser::Void()) };
                    (void)id_762;
                    (void)id_762;
                  }
                } while (while_flag_677);
                (void)::dessser::Void();
              }
              (void)::dessser::Void();
              uint8_t id_763 { 0 };
              Size id_764 { sz_ref_258[id_763] };
              let_res_674 = id_764;
            }
            Size let_res_765;
            {
              Size sz_268 { let_res_674 };
              ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_766 { std::get<4 /* Kafka */>((*p_0)) };
              std::string id_767 { id_766.topic };
              uint32_t id_768 { (uint32_t)id_767.size() };
              Vec<1, uint32_t> id_769 {  id_768  };
              Size let_res_770;
              {
                Vec<1, uint32_t> n_ref_270 { id_769 };
                uint32_t id_771 { 1U };
                Vec<1, uint32_t> id_772 {  id_771  };
                Size let_res_773;
                {
                  Vec<1, uint32_t> lebsz_ref_271 { id_772 };
                  bool while_flag_774 { true };
                  do {
                    uint8_t id_775 { 0 };
                    uint32_t id_776 { n_ref_270[id_775] };
                    uint8_t id_777 { 0 };
                    uint32_t id_778 { lebsz_ref_271[id_777] };
                    uint8_t id_779 { 7 };
                    uint32_t id_780 { uint32_t(id_778 << id_779) };
                    bool id_781 { bool(id_776 >= id_780) };
                    while_flag_774 = id_781;
                    if (while_flag_774) {
                      uint8_t id_782 { 0 };
                      uint8_t id_783 { 0 };
                      uint32_t id_784 { lebsz_ref_271[id_783] };
                      uint32_t id_785 { 1U };
                      uint32_t id_786 { uint32_t(id_784 + id_785) };
                      Void id_787 { ((void)(lebsz_ref_271[id_782] = id_786), ::dessser::Void()) };
                      (void)id_787;
                    }
                  } while (while_flag_774);
                  (void)::dessser::Void();
                  uint8_t id_788 { 0 };
                  uint32_t id_789 { lebsz_ref_271[id_788] };
                  Size id_790 { Size(id_789) };
                  let_res_773 = id_790;
                }
                let_res_770 = let_res_773;
              }
              ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_791 { std::get<4 /* Kafka */>((*p_0)) };
              std::string id_792 { id_791.topic };
              uint32_t id_793 { (uint32_t)id_792.size() };
              Size id_794 { Size(id_793) };
              Size id_795 { Size(let_res_770 + id_794) };
              Size id_796 { Size(sz_268 + id_795) };
              let_res_765 = id_796;
            }
            Size id_797 { 2UL };
            Size id_798 { Size(let_res_765 + id_797) };
            Size let_res_799;
            {
              Size sz_273 { id_798 };
              ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_800 { std::get<4 /* Kafka */>((*p_0)) };
              std::string id_801 { id_800.text };
              uint32_t id_802 { (uint32_t)id_801.size() };
              Vec<1, uint32_t> id_803 {  id_802  };
              Size let_res_804;
              {
                Vec<1, uint32_t> n_ref_275 { id_803 };
                uint32_t id_805 { 1U };
                Vec<1, uint32_t> id_806 {  id_805  };
                Size let_res_807;
                {
                  Vec<1, uint32_t> lebsz_ref_276 { id_806 };
                  bool while_flag_808 { true };
                  do {
                    uint8_t id_809 { 0 };
                    uint32_t id_810 { n_ref_275[id_809] };
                    uint8_t id_811 { 0 };
                    uint32_t id_812 { lebsz_ref_276[id_811] };
                    uint8_t id_813 { 7 };
                    uint32_t id_814 { uint32_t(id_812 << id_813) };
                    bool id_815 { bool(id_810 >= id_814) };
                    while_flag_808 = id_815;
                    if (while_flag_808) {
                      uint8_t id_816 { 0 };
                      uint8_t id_817 { 0 };
                      uint32_t id_818 { lebsz_ref_276[id_817] };
                      uint32_t id_819 { 1U };
                      uint32_t id_820 { uint32_t(id_818 + id_819) };
                      Void id_821 { ((void)(lebsz_ref_276[id_816] = id_820), ::dessser::Void()) };
                      (void)id_821;
                    }
                  } while (while_flag_808);
                  (void)::dessser::Void();
                  uint8_t id_822 { 0 };
                  uint32_t id_823 { lebsz_ref_276[id_822] };
                  Size id_824 { Size(id_823) };
                  let_res_807 = id_824;
                }
                let_res_804 = let_res_807;
              }
              ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_825 { std::get<4 /* Kafka */>((*p_0)) };
              std::string id_826 { id_825.text };
              uint32_t id_827 { (uint32_t)id_826.size() };
              Size id_828 { Size(id_827) };
              Size id_829 { Size(let_res_804 + id_828) };
              Size id_830 { Size(sz_273 + id_829) };
              let_res_799 = id_830;
            }
            choose_res_545 = let_res_799;
          }
          choose_res_511 = choose_res_545;
        }
        choose_res_477 = choose_res_511;
      }
      choose_res_472 = choose_res_477;
    }
    return choose_res_472;
  }
   };
  return fun468;
}
std::function<Size(std::shared_ptr<::dessser::gen::alerting_contact::via> )> via_sersize_of_row_binary(via_sersize_of_row_binary_init());

/* 
    (fun ("{via: (via AS [Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]); timeout: FLOAT}")
      (add (apply (identifier "via-sersize-of-row-binary") (get-field "via" (param 0))) (size 8)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alerting_contact::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alerting_contact::t> )> fun831 { [&](std::shared_ptr<::dessser::gen::alerting_contact::t>  p_0) {
    std::shared_ptr<::dessser::gen::alerting_contact::via>  id_832 { (*p_0).via };
    Size id_833 { via_sersize_of_row_binary(id_832) };
    Size id_834 { 8UL };
    Size id_835 { Size(id_833 + id_834) };
    return id_835;
  }
   };
  return fun831;
}
std::function<Size(std::shared_ptr<::dessser::gen::alerting_contact::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (make-tup (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 0 (nop))
              (identifier "dsum1_snd_65"))
            (if (eq (u16 1) (identifier "dsum1_fst_64"))
              (let "dstring1_230"
                (let "leb_ref_224" (make-vec (u32 0))
                  (let "shft_ref_225" (make-vec (u8 0))
                    (let "p_ref_226" (make-vec (identifier "dsum1_snd_65"))
                      (seq
                        (while
                          (let "leb128_227" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_226")))
                            (let-pair "leb128_fst_228" "leb128_snd_229" 
                              (identifier "leb128_227")
                              (seq (set-vec (u8 0) (identifier "p_ref_226") (identifier "leb128_snd_229"))
                                (set-vec (u8 0) (identifier "leb_ref_224")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_228") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_225"))) (unsafe-nth (u8 0) (identifier "leb_ref_224"))))
                                (set-vec (u8 0) (identifier "shft_ref_225") (add (unsafe-nth (u8 0) (identifier "shft_ref_225")) (u8 7))) 
                                (ge (identifier "leb128_fst_228") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_224"))) (unsafe-nth (u8 0) (identifier "p_ref_226")))))))
                (let-pair "dstring1_fst_231" "dstring1_snd_232" (identifier "dstring1_230")
                  (let-pair "dstring2_fst_234" "dstring2_snd_235" (read-bytes (identifier "dstring1_snd_232") (identifier "dstring1_fst_231"))
                    (make-tup
                      (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 1
                        (string-of-bytes (identifier "dstring2_fst_234"))) 
                      (identifier "dstring2_snd_235")))))
              (if (eq (u16 2) (identifier "dsum1_fst_64"))
                (let "dstring1_215"
                  (let "leb_ref_209" (make-vec (u32 0))
                    (let "shft_ref_210" (make-vec (u8 0))
                      (let "p_ref_211" (make-vec (identifier "dsum1_snd_65"))
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
                        (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 2
                          (string-of-bytes (identifier "dstring2_fst_219"))) 
                        (identifier "dstring2_snd_220")))))
                (if (eq (u16 3) (identifier "dsum1_fst_64"))
                  (let "drec_173"
                    (let "dstring1_167"
                      (let "leb_ref_161" (make-vec (u32 0))
                        (let "shft_ref_162" (make-vec (u8 0))
                          (let "p_ref_163" (make-vec (identifier "dsum1_snd_65"))
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
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_161"))) (unsafe-nth (u8 0) (identifier "p_ref_163")))))))
                      (let-pair "dstring1_fst_168" "dstring1_snd_169" 
                        (identifier "dstring1_167")
                        (let-pair "dstring2_fst_171" "dstring2_snd_172" 
                          (read-bytes (identifier "dstring1_snd_169") (identifier "dstring1_fst_168")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_171")) (identifier "dstring2_snd_172")))))
                    (let-pair "drec_fst_174" "drec_snd_175" (identifier "drec_173")
                      (let "drec_188"
                        (let "dstring1_182"
                          (let "leb_ref_176" (make-vec (u32 0))
                            (let "shft_ref_177" (make-vec (u8 0))
                              (let "p_ref_178" (make-vec (identifier "drec_snd_175"))
                                (seq
                                  (while
                                    (let "leb128_179" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_178")))
                                      (let-pair "leb128_fst_180" "leb128_snd_181" 
                                        (identifier "leb128_179")
                                        (seq (set-vec (u8 0) (identifier "p_ref_178") (identifier "leb128_snd_181"))
                                          (set-vec (u8 0) (identifier "leb_ref_176")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_180") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_177"))) (unsafe-nth (u8 0) (identifier "leb_ref_176"))))
                                          (set-vec (u8 0) (identifier "shft_ref_177") (add (unsafe-nth (u8 0) (identifier "shft_ref_177")) (u8 7))) 
                                          (ge (identifier "leb128_fst_180") (u8 128))))) 
                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_176"))) (unsafe-nth (u8 0) (identifier "p_ref_178")))))))
                          (let-pair "dstring1_fst_183" "dstring1_snd_184" 
                            (identifier "dstring1_182")
                            (let-pair "dstring2_fst_186" "dstring2_snd_187" 
                              (read-bytes (identifier "dstring1_snd_184") (identifier "dstring1_fst_183")) 
                              (make-tup (string-of-bytes (identifier "dstring2_fst_186")) (identifier "dstring2_snd_187")))))
                        (let-pair "drec_fst_189" "drec_snd_190" (identifier "drec_188")
                          (let "dstring1_197"
                            (let "leb_ref_191" (make-vec (u32 0))
                              (let "shft_ref_192" (make-vec (u8 0))
                                (let "p_ref_193" (make-vec (identifier "drec_snd_190"))
                                  (seq
                                    (while
                                      (let "leb128_194" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_193")))
                                        (let-pair "leb128_fst_195" "leb128_snd_196" 
                                          (identifier "leb128_194")
                                          (seq (set-vec (u8 0) (identifier "p_ref_193") (identifier "leb128_snd_196"))
                                            (set-vec (u8 0) (identifier "leb_ref_191")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_195") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_192"))) (unsafe-nth (u8 0) (identifier "leb_ref_191"))))
                                            (set-vec (u8 0) (identifier "shft_ref_192") (add (unsafe-nth (u8 0) (identifier "shft_ref_192")) (u8 7))) 
                                            (ge (identifier "leb128_fst_195") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_191"))) (unsafe-nth (u8 0) (identifier "p_ref_193")))))))
                            (let-pair "dstring1_fst_198" "dstring1_snd_199" 
                              (identifier "dstring1_197")
                              (let-pair "dstring2_fst_201" "dstring2_snd_202" 
                                (read-bytes (identifier "dstring1_snd_199") (identifier "dstring1_fst_198"))
                                (make-tup
                                  (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 3
                                    (make-rec (string "create") (string-of-bytes (identifier "dstring2_fst_201")) (string "insert") (identifier "drec_fst_189") (string "file") (identifier "drec_fst_174")))
                                  (identifier "dstring2_snd_202")))))))))
                  (seq (assert (eq (identifier "dsum1_fst_64") (u16 4)))
                    (let "drec_119"
                      (let-pair "dlist4_fst_117" "dlist4_snd_118"
                        (let "dlist1_75"
                          (let "leb_ref_66" (make-vec (u32 0))
                            (let "shft_ref_67" (make-vec (u8 0))
                              (let "p_ref_68" (make-vec (identifier "dsum1_snd_65"))
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
                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_66")) (unsafe-nth (u8 0) (identifier "p_ref_68")))))))
                          (let-pair "dlist1_fst_76" "dlist1_snd_77" (identifier "dlist1_75")
                            (let "inits_src_ref_78" (make-vec (make-tup (end-of-list "(STRING; STRING)") (identifier "dlist1_snd_77")))
                              (seq
                                (let "repeat_n_79" (make-vec (i32 0))
                                  (while (gt (to-i32 (identifier "dlist1_fst_76")) (unsafe-nth (u8 0) (identifier "repeat_n_79")))
                                    (seq
                                      (let "dlist2_80" (unsafe-nth (u8 0) (identifier "inits_src_ref_78"))
                                        (let-pair "dlist2_fst_81" "dlist2_snd_82" 
                                          (identifier "dlist2_80")
                                          (set-vec (u8 0) (identifier "inits_src_ref_78")
                                            (let "dtup_95"
                                              (let "dstring1_89"
                                                (let "leb_ref_83" (make-vec (u32 0))
                                                  (let "shft_ref_84" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_85" (make-vec (identifier "dlist2_snd_82"))
                                                      (seq
                                                        (while
                                                          (let "leb128_86" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_85")))
                                                            (let-pair "leb128_fst_87" "leb128_snd_88" 
                                                              (identifier "leb128_86")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_85") (identifier "leb128_snd_88"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_83")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_87") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_84")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_83")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_84") (add (unsafe-nth (u8 0) (identifier "shft_ref_84")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_87") (u8 128))))) 
                                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_83"))) (unsafe-nth (u8 0) (identifier "p_ref_85")))))))
                                                (let-pair "dstring1_fst_90" "dstring1_snd_91" 
                                                  (identifier "dstring1_89")
                                                  (let-pair "dstring2_fst_93" "dstring2_snd_94" 
                                                    (read-bytes (identifier "dstring1_snd_91") (identifier "dstring1_fst_90")) 
                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_93")) (identifier "dstring2_snd_94")))))
                                              (let-pair "dtup_fst_96" "dtup_snd_97" 
                                                (identifier "dtup_95")
                                                (let "dstring1_104"
                                                  (let "leb_ref_98" (make-vec (u32 0))
                                                    (let "shft_ref_99" 
                                                      (make-vec (u8 0))
                                                      (let "p_ref_100" 
                                                        (make-vec (identifier "dtup_snd_97"))
                                                        (seq
                                                          (while
                                                            (let "leb128_101" 
                                                              (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_100")))
                                                              (let-pair "leb128_fst_102" "leb128_snd_103" 
                                                                (identifier "leb128_101")
                                                                (seq 
                                                                  (set-vec (u8 0) (identifier "p_ref_100") (identifier "leb128_snd_103"))
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_98")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_102") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_99")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_98")))) 
                                                                  (set-vec (u8 0) (identifier "shft_ref_99") (add (unsafe-nth (u8 0) (identifier "shft_ref_99")) (u8 7))) 
                                                                  (ge (identifier "leb128_fst_102") (u8 128))))) 
                                                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_98"))) (unsafe-nth (u8 0) (identifier "p_ref_100")))))))
                                                  (let-pair "dstring1_fst_105" "dstring1_snd_106" 
                                                    (identifier "dstring1_104")
                                                    (let-pair "dstring2_fst_108" "dstring2_snd_109" 
                                                      (read-bytes (identifier "dstring1_snd_106") (identifier "dstring1_fst_105"))
                                                      (make-tup (cons (make-tup (identifier "dtup_fst_96") (string-of-bytes (identifier "dstring2_fst_108"))) (identifier "dlist2_fst_81")) (identifier "dstring2_snd_109"))))))))))
                                      (set-vec (u8 0) (identifier "repeat_n_79") (add (unsafe-nth (u8 0) (identifier "repeat_n_79")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "inits_src_ref_78")))))) 
                        (make-tup (identity (identifier "dlist4_fst_117")) (identifier "dlist4_snd_118")))
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
                            (let "drec_140" (let-pair "du16_fst_138" "du16_snd_139" (read-u16 little-endian (identifier "drec_snd_136")) (make-tup (identifier "du16_fst_138") (identifier "du16_snd_139")))
                              (let-pair "drec_fst_141" "drec_snd_142" 
                                (identifier "drec_140")
                                (let "dstring1_149"
                                  (let "leb_ref_143" (make-vec (u32 0))
                                    (let "shft_ref_144" (make-vec (u8 0))
                                      (let "p_ref_145" (make-vec (identifier "drec_snd_142"))
                                        (seq
                                          (while
                                            (let "leb128_146" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_145")))
                                              (let-pair "leb128_fst_147" "leb128_snd_148" 
                                                (identifier "leb128_146")
                                                (seq (set-vec (u8 0) (identifier "p_ref_145") (identifier "leb128_snd_148"))
                                                  (set-vec (u8 0) (identifier "leb_ref_143")
                                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_147") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_144"))) (unsafe-nth (u8 0) (identifier "leb_ref_143"))))
                                                  (set-vec (u8 0) (identifier "shft_ref_144") (add (unsafe-nth (u8 0) (identifier "shft_ref_144")) (u8 7))) 
                                                  (ge (identifier "leb128_fst_147") (u8 128))))) 
                                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_143"))) (unsafe-nth (u8 0) (identifier "p_ref_145")))))))
                                  (let-pair "dstring1_fst_150" "dstring1_snd_151" 
                                    (identifier "dstring1_149")
                                    (let-pair "dstring2_fst_153" "dstring2_snd_154" 
                                      (read-bytes (identifier "dstring1_snd_151") (identifier "dstring1_fst_150"))
                                      (make-tup
                                        (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 4
                                          (make-rec (string "text") (string-of-bytes (identifier "dstring2_fst_153")) 
                                            (string "partition") (identifier "drec_fst_141") 
                                            (string "topic") (identifier "drec_fst_135") 
                                            (string "options") (identifier "drec_fst_120"))) 
                                        (identifier "dstring2_snd_154")))))))))))))))))))
 */
static std::function<::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523(Pointer)> via_of_row_binary_init()
{
  std::function<::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523(Pointer)> fun836 { [&](Pointer p_0) {
    ::dessser::gen::alerting_contact::ta97bb48ed75bbda6173555873826c8c6 id_837 { p_0.readU16Le() };
    ::dessser::gen::alerting_contact::ta97bb48ed75bbda6173555873826c8c6 letpair_res_838;
    {
      auto du16_fst_58 { std::get<0>(id_837) };
      auto du16_snd_59 { std::get<1>(id_837) };
      ::dessser::gen::alerting_contact::ta97bb48ed75bbda6173555873826c8c6 id_839 { du16_fst_58, du16_snd_59 };
      letpair_res_838 = id_839;
    }
    ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_840;
    {
      ::dessser::gen::alerting_contact::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_838 };
      ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_841;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_842 { 0 };
        bool id_843 { bool(id_842 == dsum1_fst_64) };
        ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 choose_res_844;
        if (id_843) {
          (void)::dessser::Void();
          std::shared_ptr<::dessser::gen::alerting_contact::via>  id_845 { std::make_shared<::dessser::gen::alerting_contact::via>(std::in_place_index<0>, ::dessser::Void()) };
          ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 id_846 { id_845, dsum1_snd_65 };
          choose_res_844 = id_846;
        } else {
          uint16_t id_847 { 1 };
          bool id_848 { bool(id_847 == dsum1_fst_64) };
          ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 choose_res_849;
          if (id_848) {
            uint32_t id_850 { 0U };
            Vec<1, uint32_t> id_851 {  id_850  };
            ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_852;
            {
              Vec<1, uint32_t> leb_ref_224 { id_851 };
              uint8_t id_853 { 0 };
              Vec<1, uint8_t> id_854 {  id_853  };
              ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_855;
              {
                Vec<1, uint8_t> shft_ref_225 { id_854 };
                Vec<1, Pointer> id_856 {  dsum1_snd_65  };
                ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_857;
                {
                  Vec<1, Pointer> p_ref_226 { id_856 };
                  bool while_flag_858 { true };
                  do {
                    uint8_t id_859 { 0 };
                    Pointer id_860 { p_ref_226[id_859] };
                    ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_861 { id_860.readU8() };
                    bool let_res_862;
                    {
                      ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_227 { id_861 };
                      bool letpair_res_863;
                      {
                        auto leb128_fst_228 { std::get<0>(leb128_227) };
                        auto leb128_snd_229 { std::get<1>(leb128_227) };
                        uint8_t id_864 { 0 };
                        Void id_865 { ((void)(p_ref_226[id_864] = leb128_snd_229), ::dessser::Void()) };
                        (void)id_865;
                        uint8_t id_866 { 0 };
                        uint8_t id_867 { 127 };
                        uint8_t id_868 { uint8_t(leb128_fst_228 & id_867) };
                        uint32_t id_869 { uint32_t(id_868) };
                        uint8_t id_870 { 0 };
                        uint8_t id_871 { shft_ref_225[id_870] };
                        uint32_t id_872 { uint32_t(id_869 << id_871) };
                        uint8_t id_873 { 0 };
                        uint32_t id_874 { leb_ref_224[id_873] };
                        uint32_t id_875 { uint32_t(id_872 | id_874) };
                        Void id_876 { ((void)(leb_ref_224[id_866] = id_875), ::dessser::Void()) };
                        (void)id_876;
                        uint8_t id_877 { 0 };
                        uint8_t id_878 { 0 };
                        uint8_t id_879 { shft_ref_225[id_878] };
                        uint8_t id_880 { 7 };
                        uint8_t id_881 { uint8_t(id_879 + id_880) };
                        Void id_882 { ((void)(shft_ref_225[id_877] = id_881), ::dessser::Void()) };
                        (void)id_882;
                        uint8_t id_883 { 128 };
                        bool id_884 { bool(leb128_fst_228 >= id_883) };
                        letpair_res_863 = id_884;
                      }
                      let_res_862 = letpair_res_863;
                    }
                    while_flag_858 = let_res_862;
                    if (while_flag_858) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_858);
                  (void)::dessser::Void();
                  uint8_t id_885 { 0 };
                  uint32_t id_886 { leb_ref_224[id_885] };
                  Size id_887 { Size(id_886) };
                  uint8_t id_888 { 0 };
                  Pointer id_889 { p_ref_226[id_888] };
                  ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa id_890 { id_887, id_889 };
                  let_res_857 = id_890;
                }
                let_res_855 = let_res_857;
              }
              let_res_852 = let_res_855;
            }
            ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_891;
            {
              ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa dstring1_230 { let_res_852 };
              ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_892;
              {
                auto dstring1_fst_231 { std::get<0>(dstring1_230) };
                auto dstring1_snd_232 { std::get<1>(dstring1_230) };
                ::dessser::gen::alerting_contact::t9ef6882174ae71a34a3c5ef6b29242fb id_893 { dstring1_snd_232.readBytes(dstring1_fst_231) };
                ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_894;
                {
                  auto dstring2_fst_234 { std::get<0>(id_893) };
                  auto dstring2_snd_235 { std::get<1>(id_893) };
                  std::string id_895 { dstring2_fst_234.toString() };
                  std::shared_ptr<::dessser::gen::alerting_contact::via>  id_896 { std::make_shared<::dessser::gen::alerting_contact::via>(std::in_place_index<1>, id_895) };
                  ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 id_897 { id_896, dstring2_snd_235 };
                  letpair_res_894 = id_897;
                }
                letpair_res_892 = letpair_res_894;
              }
              let_res_891 = letpair_res_892;
            }
            choose_res_849 = let_res_891;
          } else {
            uint16_t id_898 { 2 };
            bool id_899 { bool(id_898 == dsum1_fst_64) };
            ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 choose_res_900;
            if (id_899) {
              uint32_t id_901 { 0U };
              Vec<1, uint32_t> id_902 {  id_901  };
              ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_903;
              {
                Vec<1, uint32_t> leb_ref_209 { id_902 };
                uint8_t id_904 { 0 };
                Vec<1, uint8_t> id_905 {  id_904  };
                ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_906;
                {
                  Vec<1, uint8_t> shft_ref_210 { id_905 };
                  Vec<1, Pointer> id_907 {  dsum1_snd_65  };
                  ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_908;
                  {
                    Vec<1, Pointer> p_ref_211 { id_907 };
                    bool while_flag_909 { true };
                    do {
                      uint8_t id_910 { 0 };
                      Pointer id_911 { p_ref_211[id_910] };
                      ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_912 { id_911.readU8() };
                      bool let_res_913;
                      {
                        ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_212 { id_912 };
                        bool letpair_res_914;
                        {
                          auto leb128_fst_213 { std::get<0>(leb128_212) };
                          auto leb128_snd_214 { std::get<1>(leb128_212) };
                          uint8_t id_915 { 0 };
                          Void id_916 { ((void)(p_ref_211[id_915] = leb128_snd_214), ::dessser::Void()) };
                          (void)id_916;
                          uint8_t id_917 { 0 };
                          uint8_t id_918 { 127 };
                          uint8_t id_919 { uint8_t(leb128_fst_213 & id_918) };
                          uint32_t id_920 { uint32_t(id_919) };
                          uint8_t id_921 { 0 };
                          uint8_t id_922 { shft_ref_210[id_921] };
                          uint32_t id_923 { uint32_t(id_920 << id_922) };
                          uint8_t id_924 { 0 };
                          uint32_t id_925 { leb_ref_209[id_924] };
                          uint32_t id_926 { uint32_t(id_923 | id_925) };
                          Void id_927 { ((void)(leb_ref_209[id_917] = id_926), ::dessser::Void()) };
                          (void)id_927;
                          uint8_t id_928 { 0 };
                          uint8_t id_929 { 0 };
                          uint8_t id_930 { shft_ref_210[id_929] };
                          uint8_t id_931 { 7 };
                          uint8_t id_932 { uint8_t(id_930 + id_931) };
                          Void id_933 { ((void)(shft_ref_210[id_928] = id_932), ::dessser::Void()) };
                          (void)id_933;
                          uint8_t id_934 { 128 };
                          bool id_935 { bool(leb128_fst_213 >= id_934) };
                          letpair_res_914 = id_935;
                        }
                        let_res_913 = letpair_res_914;
                      }
                      while_flag_909 = let_res_913;
                      if (while_flag_909) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_909);
                    (void)::dessser::Void();
                    uint8_t id_936 { 0 };
                    uint32_t id_937 { leb_ref_209[id_936] };
                    Size id_938 { Size(id_937) };
                    uint8_t id_939 { 0 };
                    Pointer id_940 { p_ref_211[id_939] };
                    ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa id_941 { id_938, id_940 };
                    let_res_908 = id_941;
                  }
                  let_res_906 = let_res_908;
                }
                let_res_903 = let_res_906;
              }
              ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_942;
              {
                ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa dstring1_215 { let_res_903 };
                ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_943;
                {
                  auto dstring1_fst_216 { std::get<0>(dstring1_215) };
                  auto dstring1_snd_217 { std::get<1>(dstring1_215) };
                  ::dessser::gen::alerting_contact::t9ef6882174ae71a34a3c5ef6b29242fb id_944 { dstring1_snd_217.readBytes(dstring1_fst_216) };
                  ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_945;
                  {
                    auto dstring2_fst_219 { std::get<0>(id_944) };
                    auto dstring2_snd_220 { std::get<1>(id_944) };
                    std::string id_946 { dstring2_fst_219.toString() };
                    std::shared_ptr<::dessser::gen::alerting_contact::via>  id_947 { std::make_shared<::dessser::gen::alerting_contact::via>(std::in_place_index<2>, id_946) };
                    ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 id_948 { id_947, dstring2_snd_220 };
                    letpair_res_945 = id_948;
                  }
                  letpair_res_943 = letpair_res_945;
                }
                let_res_942 = letpair_res_943;
              }
              choose_res_900 = let_res_942;
            } else {
              uint16_t id_949 { 3 };
              bool id_950 { bool(id_949 == dsum1_fst_64) };
              ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 choose_res_951;
              if (id_950) {
                uint32_t id_952 { 0U };
                Vec<1, uint32_t> id_953 {  id_952  };
                ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_954;
                {
                  Vec<1, uint32_t> leb_ref_161 { id_953 };
                  uint8_t id_955 { 0 };
                  Vec<1, uint8_t> id_956 {  id_955  };
                  ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_957;
                  {
                    Vec<1, uint8_t> shft_ref_162 { id_956 };
                    Vec<1, Pointer> id_958 {  dsum1_snd_65  };
                    ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_959;
                    {
                      Vec<1, Pointer> p_ref_163 { id_958 };
                      bool while_flag_960 { true };
                      do {
                        uint8_t id_961 { 0 };
                        Pointer id_962 { p_ref_163[id_961] };
                        ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_963 { id_962.readU8() };
                        bool let_res_964;
                        {
                          ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_164 { id_963 };
                          bool letpair_res_965;
                          {
                            auto leb128_fst_165 { std::get<0>(leb128_164) };
                            auto leb128_snd_166 { std::get<1>(leb128_164) };
                            uint8_t id_966 { 0 };
                            Void id_967 { ((void)(p_ref_163[id_966] = leb128_snd_166), ::dessser::Void()) };
                            (void)id_967;
                            uint8_t id_968 { 0 };
                            uint8_t id_969 { 127 };
                            uint8_t id_970 { uint8_t(leb128_fst_165 & id_969) };
                            uint32_t id_971 { uint32_t(id_970) };
                            uint8_t id_972 { 0 };
                            uint8_t id_973 { shft_ref_162[id_972] };
                            uint32_t id_974 { uint32_t(id_971 << id_973) };
                            uint8_t id_975 { 0 };
                            uint32_t id_976 { leb_ref_161[id_975] };
                            uint32_t id_977 { uint32_t(id_974 | id_976) };
                            Void id_978 { ((void)(leb_ref_161[id_968] = id_977), ::dessser::Void()) };
                            (void)id_978;
                            uint8_t id_979 { 0 };
                            uint8_t id_980 { 0 };
                            uint8_t id_981 { shft_ref_162[id_980] };
                            uint8_t id_982 { 7 };
                            uint8_t id_983 { uint8_t(id_981 + id_982) };
                            Void id_984 { ((void)(shft_ref_162[id_979] = id_983), ::dessser::Void()) };
                            (void)id_984;
                            uint8_t id_985 { 128 };
                            bool id_986 { bool(leb128_fst_165 >= id_985) };
                            letpair_res_965 = id_986;
                          }
                          let_res_964 = letpair_res_965;
                        }
                        while_flag_960 = let_res_964;
                        if (while_flag_960) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_960);
                      (void)::dessser::Void();
                      uint8_t id_987 { 0 };
                      uint32_t id_988 { leb_ref_161[id_987] };
                      Size id_989 { Size(id_988) };
                      uint8_t id_990 { 0 };
                      Pointer id_991 { p_ref_163[id_990] };
                      ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa id_992 { id_989, id_991 };
                      let_res_959 = id_992;
                    }
                    let_res_957 = let_res_959;
                  }
                  let_res_954 = let_res_957;
                }
                ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 let_res_993;
                {
                  ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa dstring1_167 { let_res_954 };
                  ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 letpair_res_994;
                  {
                    auto dstring1_fst_168 { std::get<0>(dstring1_167) };
                    auto dstring1_snd_169 { std::get<1>(dstring1_167) };
                    ::dessser::gen::alerting_contact::t9ef6882174ae71a34a3c5ef6b29242fb id_995 { dstring1_snd_169.readBytes(dstring1_fst_168) };
                    ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 letpair_res_996;
                    {
                      auto dstring2_fst_171 { std::get<0>(id_995) };
                      auto dstring2_snd_172 { std::get<1>(id_995) };
                      std::string id_997 { dstring2_fst_171.toString() };
                      ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 id_998 { id_997, dstring2_snd_172 };
                      letpair_res_996 = id_998;
                    }
                    letpair_res_994 = letpair_res_996;
                  }
                  let_res_993 = letpair_res_994;
                }
                ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_999;
                {
                  ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 drec_173 { let_res_993 };
                  ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_1000;
                  {
                    auto drec_fst_174 { std::get<0>(drec_173) };
                    auto drec_snd_175 { std::get<1>(drec_173) };
                    uint32_t id_1001 { 0U };
                    Vec<1, uint32_t> id_1002 {  id_1001  };
                    ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1003;
                    {
                      Vec<1, uint32_t> leb_ref_176 { id_1002 };
                      uint8_t id_1004 { 0 };
                      Vec<1, uint8_t> id_1005 {  id_1004  };
                      ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1006;
                      {
                        Vec<1, uint8_t> shft_ref_177 { id_1005 };
                        Vec<1, Pointer> id_1007 {  drec_snd_175  };
                        ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1008;
                        {
                          Vec<1, Pointer> p_ref_178 { id_1007 };
                          bool while_flag_1009 { true };
                          do {
                            uint8_t id_1010 { 0 };
                            Pointer id_1011 { p_ref_178[id_1010] };
                            ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_1012 { id_1011.readU8() };
                            bool let_res_1013;
                            {
                              ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_179 { id_1012 };
                              bool letpair_res_1014;
                              {
                                auto leb128_fst_180 { std::get<0>(leb128_179) };
                                auto leb128_snd_181 { std::get<1>(leb128_179) };
                                uint8_t id_1015 { 0 };
                                Void id_1016 { ((void)(p_ref_178[id_1015] = leb128_snd_181), ::dessser::Void()) };
                                (void)id_1016;
                                uint8_t id_1017 { 0 };
                                uint8_t id_1018 { 127 };
                                uint8_t id_1019 { uint8_t(leb128_fst_180 & id_1018) };
                                uint32_t id_1020 { uint32_t(id_1019) };
                                uint8_t id_1021 { 0 };
                                uint8_t id_1022 { shft_ref_177[id_1021] };
                                uint32_t id_1023 { uint32_t(id_1020 << id_1022) };
                                uint8_t id_1024 { 0 };
                                uint32_t id_1025 { leb_ref_176[id_1024] };
                                uint32_t id_1026 { uint32_t(id_1023 | id_1025) };
                                Void id_1027 { ((void)(leb_ref_176[id_1017] = id_1026), ::dessser::Void()) };
                                (void)id_1027;
                                uint8_t id_1028 { 0 };
                                uint8_t id_1029 { 0 };
                                uint8_t id_1030 { shft_ref_177[id_1029] };
                                uint8_t id_1031 { 7 };
                                uint8_t id_1032 { uint8_t(id_1030 + id_1031) };
                                Void id_1033 { ((void)(shft_ref_177[id_1028] = id_1032), ::dessser::Void()) };
                                (void)id_1033;
                                uint8_t id_1034 { 128 };
                                bool id_1035 { bool(leb128_fst_180 >= id_1034) };
                                letpair_res_1014 = id_1035;
                              }
                              let_res_1013 = letpair_res_1014;
                            }
                            while_flag_1009 = let_res_1013;
                            if (while_flag_1009) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_1009);
                          (void)::dessser::Void();
                          uint8_t id_1036 { 0 };
                          uint32_t id_1037 { leb_ref_176[id_1036] };
                          Size id_1038 { Size(id_1037) };
                          uint8_t id_1039 { 0 };
                          Pointer id_1040 { p_ref_178[id_1039] };
                          ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa id_1041 { id_1038, id_1040 };
                          let_res_1008 = id_1041;
                        }
                        let_res_1006 = let_res_1008;
                      }
                      let_res_1003 = let_res_1006;
                    }
                    ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 let_res_1042;
                    {
                      ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa dstring1_182 { let_res_1003 };
                      ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 letpair_res_1043;
                      {
                        auto dstring1_fst_183 { std::get<0>(dstring1_182) };
                        auto dstring1_snd_184 { std::get<1>(dstring1_182) };
                        ::dessser::gen::alerting_contact::t9ef6882174ae71a34a3c5ef6b29242fb id_1044 { dstring1_snd_184.readBytes(dstring1_fst_183) };
                        ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 letpair_res_1045;
                        {
                          auto dstring2_fst_186 { std::get<0>(id_1044) };
                          auto dstring2_snd_187 { std::get<1>(id_1044) };
                          std::string id_1046 { dstring2_fst_186.toString() };
                          ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 id_1047 { id_1046, dstring2_snd_187 };
                          letpair_res_1045 = id_1047;
                        }
                        letpair_res_1043 = letpair_res_1045;
                      }
                      let_res_1042 = letpair_res_1043;
                    }
                    ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_1048;
                    {
                      ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 drec_188 { let_res_1042 };
                      ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_1049;
                      {
                        auto drec_fst_189 { std::get<0>(drec_188) };
                        auto drec_snd_190 { std::get<1>(drec_188) };
                        uint32_t id_1050 { 0U };
                        Vec<1, uint32_t> id_1051 {  id_1050  };
                        ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1052;
                        {
                          Vec<1, uint32_t> leb_ref_191 { id_1051 };
                          uint8_t id_1053 { 0 };
                          Vec<1, uint8_t> id_1054 {  id_1053  };
                          ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1055;
                          {
                            Vec<1, uint8_t> shft_ref_192 { id_1054 };
                            Vec<1, Pointer> id_1056 {  drec_snd_190  };
                            ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1057;
                            {
                              Vec<1, Pointer> p_ref_193 { id_1056 };
                              bool while_flag_1058 { true };
                              do {
                                uint8_t id_1059 { 0 };
                                Pointer id_1060 { p_ref_193[id_1059] };
                                ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_1061 { id_1060.readU8() };
                                bool let_res_1062;
                                {
                                  ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_194 { id_1061 };
                                  bool letpair_res_1063;
                                  {
                                    auto leb128_fst_195 { std::get<0>(leb128_194) };
                                    auto leb128_snd_196 { std::get<1>(leb128_194) };
                                    uint8_t id_1064 { 0 };
                                    Void id_1065 { ((void)(p_ref_193[id_1064] = leb128_snd_196), ::dessser::Void()) };
                                    (void)id_1065;
                                    uint8_t id_1066 { 0 };
                                    uint8_t id_1067 { 127 };
                                    uint8_t id_1068 { uint8_t(leb128_fst_195 & id_1067) };
                                    uint32_t id_1069 { uint32_t(id_1068) };
                                    uint8_t id_1070 { 0 };
                                    uint8_t id_1071 { shft_ref_192[id_1070] };
                                    uint32_t id_1072 { uint32_t(id_1069 << id_1071) };
                                    uint8_t id_1073 { 0 };
                                    uint32_t id_1074 { leb_ref_191[id_1073] };
                                    uint32_t id_1075 { uint32_t(id_1072 | id_1074) };
                                    Void id_1076 { ((void)(leb_ref_191[id_1066] = id_1075), ::dessser::Void()) };
                                    (void)id_1076;
                                    uint8_t id_1077 { 0 };
                                    uint8_t id_1078 { 0 };
                                    uint8_t id_1079 { shft_ref_192[id_1078] };
                                    uint8_t id_1080 { 7 };
                                    uint8_t id_1081 { uint8_t(id_1079 + id_1080) };
                                    Void id_1082 { ((void)(shft_ref_192[id_1077] = id_1081), ::dessser::Void()) };
                                    (void)id_1082;
                                    uint8_t id_1083 { 128 };
                                    bool id_1084 { bool(leb128_fst_195 >= id_1083) };
                                    letpair_res_1063 = id_1084;
                                  }
                                  let_res_1062 = letpair_res_1063;
                                }
                                while_flag_1058 = let_res_1062;
                                if (while_flag_1058) {
                                  (void)::dessser::Void();
                                }
                              } while (while_flag_1058);
                              (void)::dessser::Void();
                              uint8_t id_1085 { 0 };
                              uint32_t id_1086 { leb_ref_191[id_1085] };
                              Size id_1087 { Size(id_1086) };
                              uint8_t id_1088 { 0 };
                              Pointer id_1089 { p_ref_193[id_1088] };
                              ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa id_1090 { id_1087, id_1089 };
                              let_res_1057 = id_1090;
                            }
                            let_res_1055 = let_res_1057;
                          }
                          let_res_1052 = let_res_1055;
                        }
                        ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_1091;
                        {
                          ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa dstring1_197 { let_res_1052 };
                          ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_1092;
                          {
                            auto dstring1_fst_198 { std::get<0>(dstring1_197) };
                            auto dstring1_snd_199 { std::get<1>(dstring1_197) };
                            ::dessser::gen::alerting_contact::t9ef6882174ae71a34a3c5ef6b29242fb id_1093 { dstring1_snd_199.readBytes(dstring1_fst_198) };
                            ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_1094;
                            {
                              auto dstring2_fst_201 { std::get<0>(id_1093) };
                              auto dstring2_snd_202 { std::get<1>(id_1093) };
                              std::string id_1095 { dstring2_fst_201.toString() };
                              ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b id_1096 { drec_fst_174, drec_fst_189, id_1095 };
                              std::shared_ptr<::dessser::gen::alerting_contact::via>  id_1097 { std::make_shared<::dessser::gen::alerting_contact::via>(std::in_place_index<3>, id_1096) };
                              ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 id_1098 { id_1097, dstring2_snd_202 };
                              letpair_res_1094 = id_1098;
                            }
                            letpair_res_1092 = letpair_res_1094;
                          }
                          let_res_1091 = letpair_res_1092;
                        }
                        letpair_res_1049 = let_res_1091;
                      }
                      let_res_1048 = letpair_res_1049;
                    }
                    letpair_res_1000 = let_res_1048;
                  }
                  let_res_999 = letpair_res_1000;
                }
                choose_res_951 = let_res_999;
              } else {
                uint16_t id_1099 { 4 };
                bool id_1100 { bool(dsum1_fst_64 == id_1099) };
                Void id_1101 { ((void)(assert(id_1100)), ::dessser::Void()) };
                (void)id_1101;
                uint32_t id_1102 { 0U };
                Vec<1, uint32_t> id_1103 {  id_1102  };
                ::dessser::gen::alerting_contact::t491c44439106a32f896827242e8e76a1 let_res_1104;
                {
                  Vec<1, uint32_t> leb_ref_66 { id_1103 };
                  uint8_t id_1105 { 0 };
                  Vec<1, uint8_t> id_1106 {  id_1105  };
                  ::dessser::gen::alerting_contact::t491c44439106a32f896827242e8e76a1 let_res_1107;
                  {
                    Vec<1, uint8_t> shft_ref_67 { id_1106 };
                    Vec<1, Pointer> id_1108 {  dsum1_snd_65  };
                    ::dessser::gen::alerting_contact::t491c44439106a32f896827242e8e76a1 let_res_1109;
                    {
                      Vec<1, Pointer> p_ref_68 { id_1108 };
                      bool while_flag_1110 { true };
                      do {
                        uint8_t id_1111 { 0 };
                        Pointer id_1112 { p_ref_68[id_1111] };
                        ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_1113 { id_1112.readU8() };
                        bool let_res_1114;
                        {
                          ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_69 { id_1113 };
                          bool letpair_res_1115;
                          {
                            auto leb128_fst_70 { std::get<0>(leb128_69) };
                            auto leb128_snd_71 { std::get<1>(leb128_69) };
                            uint8_t id_1116 { 0 };
                            Void id_1117 { ((void)(p_ref_68[id_1116] = leb128_snd_71), ::dessser::Void()) };
                            (void)id_1117;
                            uint8_t id_1118 { 0 };
                            uint8_t id_1119 { 127 };
                            uint8_t id_1120 { uint8_t(leb128_fst_70 & id_1119) };
                            uint32_t id_1121 { uint32_t(id_1120) };
                            uint8_t id_1122 { 0 };
                            uint8_t id_1123 { shft_ref_67[id_1122] };
                            uint32_t id_1124 { uint32_t(id_1121 << id_1123) };
                            uint8_t id_1125 { 0 };
                            uint32_t id_1126 { leb_ref_66[id_1125] };
                            uint32_t id_1127 { uint32_t(id_1124 | id_1126) };
                            Void id_1128 { ((void)(leb_ref_66[id_1118] = id_1127), ::dessser::Void()) };
                            (void)id_1128;
                            uint8_t id_1129 { 0 };
                            uint8_t id_1130 { 0 };
                            uint8_t id_1131 { shft_ref_67[id_1130] };
                            uint8_t id_1132 { 7 };
                            uint8_t id_1133 { uint8_t(id_1131 + id_1132) };
                            Void id_1134 { ((void)(shft_ref_67[id_1129] = id_1133), ::dessser::Void()) };
                            (void)id_1134;
                            uint8_t id_1135 { 128 };
                            bool id_1136 { bool(leb128_fst_70 >= id_1135) };
                            letpair_res_1115 = id_1136;
                          }
                          let_res_1114 = letpair_res_1115;
                        }
                        while_flag_1110 = let_res_1114;
                        if (while_flag_1110) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_1110);
                      (void)::dessser::Void();
                      uint8_t id_1137 { 0 };
                      uint32_t id_1138 { leb_ref_66[id_1137] };
                      uint8_t id_1139 { 0 };
                      Pointer id_1140 { p_ref_68[id_1139] };
                      ::dessser::gen::alerting_contact::t491c44439106a32f896827242e8e76a1 id_1141 { id_1138, id_1140 };
                      let_res_1109 = id_1141;
                    }
                    let_res_1107 = let_res_1109;
                  }
                  let_res_1104 = let_res_1107;
                }
                ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 let_res_1142;
                {
                  ::dessser::gen::alerting_contact::t491c44439106a32f896827242e8e76a1 dlist1_75 { let_res_1104 };
                  ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 letpair_res_1143;
                  {
                    auto dlist1_fst_76 { std::get<0>(dlist1_75) };
                    auto dlist1_snd_77 { std::get<1>(dlist1_75) };
                    Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> endoflist_1144;
                    ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 id_1145 { endoflist_1144, dlist1_snd_77 };
                    Vec<1, ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149> id_1146 {  id_1145  };
                    ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 let_res_1147;
                    {
                      Vec<1, ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149> inits_src_ref_78 { id_1146 };
                      int32_t id_1148 { 0L };
                      Vec<1, int32_t> id_1149 {  id_1148  };
                      {
                        Vec<1, int32_t> repeat_n_79 { id_1149 };
                        bool while_flag_1150 { true };
                        do {
                          int32_t id_1151 { int32_t(dlist1_fst_76) };
                          uint8_t id_1152 { 0 };
                          int32_t id_1153 { repeat_n_79[id_1152] };
                          bool id_1154 { bool(id_1151 > id_1153) };
                          while_flag_1150 = id_1154;
                          if (while_flag_1150) {
                            uint8_t id_1155 { 0 };
                            ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 id_1156 { inits_src_ref_78[id_1155] };
                            {
                              ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 dlist2_80 { id_1156 };
                              {
                                auto dlist2_fst_81 { std::get<0>(dlist2_80) };
                                auto dlist2_snd_82 { std::get<1>(dlist2_80) };
                                uint8_t id_1157 { 0 };
                                uint32_t id_1158 { 0U };
                                Vec<1, uint32_t> id_1159 {  id_1158  };
                                ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1160;
                                {
                                  Vec<1, uint32_t> leb_ref_83 { id_1159 };
                                  uint8_t id_1161 { 0 };
                                  Vec<1, uint8_t> id_1162 {  id_1161  };
                                  ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1163;
                                  {
                                    Vec<1, uint8_t> shft_ref_84 { id_1162 };
                                    Vec<1, Pointer> id_1164 {  dlist2_snd_82  };
                                    ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1165;
                                    {
                                      Vec<1, Pointer> p_ref_85 { id_1164 };
                                      bool while_flag_1166 { true };
                                      do {
                                        uint8_t id_1167 { 0 };
                                        Pointer id_1168 { p_ref_85[id_1167] };
                                        ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_1169 { id_1168.readU8() };
                                        bool let_res_1170;
                                        {
                                          ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_86 { id_1169 };
                                          bool letpair_res_1171;
                                          {
                                            auto leb128_fst_87 { std::get<0>(leb128_86) };
                                            auto leb128_snd_88 { std::get<1>(leb128_86) };
                                            uint8_t id_1172 { 0 };
                                            Void id_1173 { ((void)(p_ref_85[id_1172] = leb128_snd_88), ::dessser::Void()) };
                                            (void)id_1173;
                                            uint8_t id_1174 { 0 };
                                            uint8_t id_1175 { 127 };
                                            uint8_t id_1176 { uint8_t(leb128_fst_87 & id_1175) };
                                            uint32_t id_1177 { uint32_t(id_1176) };
                                            uint8_t id_1178 { 0 };
                                            uint8_t id_1179 { shft_ref_84[id_1178] };
                                            uint32_t id_1180 { uint32_t(id_1177 << id_1179) };
                                            uint8_t id_1181 { 0 };
                                            uint32_t id_1182 { leb_ref_83[id_1181] };
                                            uint32_t id_1183 { uint32_t(id_1180 | id_1182) };
                                            Void id_1184 { ((void)(leb_ref_83[id_1174] = id_1183), ::dessser::Void()) };
                                            (void)id_1184;
                                            uint8_t id_1185 { 0 };
                                            uint8_t id_1186 { 0 };
                                            uint8_t id_1187 { shft_ref_84[id_1186] };
                                            uint8_t id_1188 { 7 };
                                            uint8_t id_1189 { uint8_t(id_1187 + id_1188) };
                                            Void id_1190 { ((void)(shft_ref_84[id_1185] = id_1189), ::dessser::Void()) };
                                            (void)id_1190;
                                            uint8_t id_1191 { 128 };
                                            bool id_1192 { bool(leb128_fst_87 >= id_1191) };
                                            letpair_res_1171 = id_1192;
                                          }
                                          let_res_1170 = letpair_res_1171;
                                        }
                                        while_flag_1166 = let_res_1170;
                                        if (while_flag_1166) {
                                          (void)::dessser::Void();
                                        }
                                      } while (while_flag_1166);
                                      (void)::dessser::Void();
                                      uint8_t id_1193 { 0 };
                                      uint32_t id_1194 { leb_ref_83[id_1193] };
                                      Size id_1195 { Size(id_1194) };
                                      uint8_t id_1196 { 0 };
                                      Pointer id_1197 { p_ref_85[id_1196] };
                                      ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa id_1198 { id_1195, id_1197 };
                                      let_res_1165 = id_1198;
                                    }
                                    let_res_1163 = let_res_1165;
                                  }
                                  let_res_1160 = let_res_1163;
                                }
                                ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 let_res_1199;
                                {
                                  ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa dstring1_89 { let_res_1160 };
                                  ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 letpair_res_1200;
                                  {
                                    auto dstring1_fst_90 { std::get<0>(dstring1_89) };
                                    auto dstring1_snd_91 { std::get<1>(dstring1_89) };
                                    ::dessser::gen::alerting_contact::t9ef6882174ae71a34a3c5ef6b29242fb id_1201 { dstring1_snd_91.readBytes(dstring1_fst_90) };
                                    ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 letpair_res_1202;
                                    {
                                      auto dstring2_fst_93 { std::get<0>(id_1201) };
                                      auto dstring2_snd_94 { std::get<1>(id_1201) };
                                      std::string id_1203 { dstring2_fst_93.toString() };
                                      ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 id_1204 { id_1203, dstring2_snd_94 };
                                      letpair_res_1202 = id_1204;
                                    }
                                    letpair_res_1200 = letpair_res_1202;
                                  }
                                  let_res_1199 = letpair_res_1200;
                                }
                                ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 let_res_1205;
                                {
                                  ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 dtup_95 { let_res_1199 };
                                  ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 letpair_res_1206;
                                  {
                                    auto dtup_fst_96 { std::get<0>(dtup_95) };
                                    auto dtup_snd_97 { std::get<1>(dtup_95) };
                                    uint32_t id_1207 { 0U };
                                    Vec<1, uint32_t> id_1208 {  id_1207  };
                                    ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1209;
                                    {
                                      Vec<1, uint32_t> leb_ref_98 { id_1208 };
                                      uint8_t id_1210 { 0 };
                                      Vec<1, uint8_t> id_1211 {  id_1210  };
                                      ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1212;
                                      {
                                        Vec<1, uint8_t> shft_ref_99 { id_1211 };
                                        Vec<1, Pointer> id_1213 {  dtup_snd_97  };
                                        ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1214;
                                        {
                                          Vec<1, Pointer> p_ref_100 { id_1213 };
                                          bool while_flag_1215 { true };
                                          do {
                                            uint8_t id_1216 { 0 };
                                            Pointer id_1217 { p_ref_100[id_1216] };
                                            ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_1218 { id_1217.readU8() };
                                            bool let_res_1219;
                                            {
                                              ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_101 { id_1218 };
                                              bool letpair_res_1220;
                                              {
                                                auto leb128_fst_102 { std::get<0>(leb128_101) };
                                                auto leb128_snd_103 { std::get<1>(leb128_101) };
                                                uint8_t id_1221 { 0 };
                                                Void id_1222 { ((void)(p_ref_100[id_1221] = leb128_snd_103), ::dessser::Void()) };
                                                (void)id_1222;
                                                uint8_t id_1223 { 0 };
                                                uint8_t id_1224 { 127 };
                                                uint8_t id_1225 { uint8_t(leb128_fst_102 & id_1224) };
                                                uint32_t id_1226 { uint32_t(id_1225) };
                                                uint8_t id_1227 { 0 };
                                                uint8_t id_1228 { shft_ref_99[id_1227] };
                                                uint32_t id_1229 { uint32_t(id_1226 << id_1228) };
                                                uint8_t id_1230 { 0 };
                                                uint32_t id_1231 { leb_ref_98[id_1230] };
                                                uint32_t id_1232 { uint32_t(id_1229 | id_1231) };
                                                Void id_1233 { ((void)(leb_ref_98[id_1223] = id_1232), ::dessser::Void()) };
                                                (void)id_1233;
                                                uint8_t id_1234 { 0 };
                                                uint8_t id_1235 { 0 };
                                                uint8_t id_1236 { shft_ref_99[id_1235] };
                                                uint8_t id_1237 { 7 };
                                                uint8_t id_1238 { uint8_t(id_1236 + id_1237) };
                                                Void id_1239 { ((void)(shft_ref_99[id_1234] = id_1238), ::dessser::Void()) };
                                                (void)id_1239;
                                                uint8_t id_1240 { 128 };
                                                bool id_1241 { bool(leb128_fst_102 >= id_1240) };
                                                letpair_res_1220 = id_1241;
                                              }
                                              let_res_1219 = letpair_res_1220;
                                            }
                                            while_flag_1215 = let_res_1219;
                                            if (while_flag_1215) {
                                              (void)::dessser::Void();
                                            }
                                          } while (while_flag_1215);
                                          (void)::dessser::Void();
                                          uint8_t id_1242 { 0 };
                                          uint32_t id_1243 { leb_ref_98[id_1242] };
                                          Size id_1244 { Size(id_1243) };
                                          uint8_t id_1245 { 0 };
                                          Pointer id_1246 { p_ref_100[id_1245] };
                                          ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa id_1247 { id_1244, id_1246 };
                                          let_res_1214 = id_1247;
                                        }
                                        let_res_1212 = let_res_1214;
                                      }
                                      let_res_1209 = let_res_1212;
                                    }
                                    ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 let_res_1248;
                                    {
                                      ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa dstring1_104 { let_res_1209 };
                                      ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 letpair_res_1249;
                                      {
                                        auto dstring1_fst_105 { std::get<0>(dstring1_104) };
                                        auto dstring1_snd_106 { std::get<1>(dstring1_104) };
                                        ::dessser::gen::alerting_contact::t9ef6882174ae71a34a3c5ef6b29242fb id_1250 { dstring1_snd_106.readBytes(dstring1_fst_105) };
                                        ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 letpair_res_1251;
                                        {
                                          auto dstring2_fst_108 { std::get<0>(id_1250) };
                                          auto dstring2_snd_109 { std::get<1>(id_1250) };
                                          std::string id_1252 { dstring2_fst_108.toString() };
                                          ::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463 id_1253 { dtup_fst_96, id_1252 };
                                          Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> id_1254 { id_1253, dlist2_fst_81 };
                                          ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 id_1255 { id_1254, dstring2_snd_109 };
                                          letpair_res_1251 = id_1255;
                                        }
                                        letpair_res_1249 = letpair_res_1251;
                                      }
                                      let_res_1248 = letpair_res_1249;
                                    }
                                    letpair_res_1206 = let_res_1248;
                                  }
                                  let_res_1205 = letpair_res_1206;
                                }
                                Void id_1256 { ((void)(inits_src_ref_78[id_1157] = let_res_1205), ::dessser::Void()) };
                                (void)id_1256;
                              }
                              (void)::dessser::Void();
                            }
                            (void)::dessser::Void();
                            uint8_t id_1257 { 0 };
                            uint8_t id_1258 { 0 };
                            int32_t id_1259 { repeat_n_79[id_1258] };
                            int32_t id_1260 { 1L };
                            int32_t id_1261 { int32_t(id_1259 + id_1260) };
                            Void id_1262 { ((void)(repeat_n_79[id_1257] = id_1261), ::dessser::Void()) };
                            (void)id_1262;
                            (void)id_1262;
                          }
                        } while (while_flag_1150);
                        (void)::dessser::Void();
                      }
                      (void)::dessser::Void();
                      uint8_t id_1263 { 0 };
                      ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 id_1264 { inits_src_ref_78[id_1263] };
                      let_res_1147 = id_1264;
                    }
                    letpair_res_1143 = let_res_1147;
                  }
                  let_res_1142 = letpair_res_1143;
                }
                ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 letpair_res_1265;
                {
                  auto dlist4_fst_117 { std::get<0>(let_res_1142) };
                  auto dlist4_snd_118 { std::get<1>(let_res_1142) };
                  ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 id_1266 { dlist4_fst_117, dlist4_snd_118 };
                  letpair_res_1265 = id_1266;
                }
                ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_1267;
                {
                  ::dessser::gen::alerting_contact::t0ec843672514be25b144f299b8cb3149 drec_119 { letpair_res_1265 };
                  ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_1268;
                  {
                    auto drec_fst_120 { std::get<0>(drec_119) };
                    auto drec_snd_121 { std::get<1>(drec_119) };
                    uint32_t id_1269 { 0U };
                    Vec<1, uint32_t> id_1270 {  id_1269  };
                    ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1271;
                    {
                      Vec<1, uint32_t> leb_ref_122 { id_1270 };
                      uint8_t id_1272 { 0 };
                      Vec<1, uint8_t> id_1273 {  id_1272  };
                      ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1274;
                      {
                        Vec<1, uint8_t> shft_ref_123 { id_1273 };
                        Vec<1, Pointer> id_1275 {  drec_snd_121  };
                        ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1276;
                        {
                          Vec<1, Pointer> p_ref_124 { id_1275 };
                          bool while_flag_1277 { true };
                          do {
                            uint8_t id_1278 { 0 };
                            Pointer id_1279 { p_ref_124[id_1278] };
                            ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_1280 { id_1279.readU8() };
                            bool let_res_1281;
                            {
                              ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_125 { id_1280 };
                              bool letpair_res_1282;
                              {
                                auto leb128_fst_126 { std::get<0>(leb128_125) };
                                auto leb128_snd_127 { std::get<1>(leb128_125) };
                                uint8_t id_1283 { 0 };
                                Void id_1284 { ((void)(p_ref_124[id_1283] = leb128_snd_127), ::dessser::Void()) };
                                (void)id_1284;
                                uint8_t id_1285 { 0 };
                                uint8_t id_1286 { 127 };
                                uint8_t id_1287 { uint8_t(leb128_fst_126 & id_1286) };
                                uint32_t id_1288 { uint32_t(id_1287) };
                                uint8_t id_1289 { 0 };
                                uint8_t id_1290 { shft_ref_123[id_1289] };
                                uint32_t id_1291 { uint32_t(id_1288 << id_1290) };
                                uint8_t id_1292 { 0 };
                                uint32_t id_1293 { leb_ref_122[id_1292] };
                                uint32_t id_1294 { uint32_t(id_1291 | id_1293) };
                                Void id_1295 { ((void)(leb_ref_122[id_1285] = id_1294), ::dessser::Void()) };
                                (void)id_1295;
                                uint8_t id_1296 { 0 };
                                uint8_t id_1297 { 0 };
                                uint8_t id_1298 { shft_ref_123[id_1297] };
                                uint8_t id_1299 { 7 };
                                uint8_t id_1300 { uint8_t(id_1298 + id_1299) };
                                Void id_1301 { ((void)(shft_ref_123[id_1296] = id_1300), ::dessser::Void()) };
                                (void)id_1301;
                                uint8_t id_1302 { 128 };
                                bool id_1303 { bool(leb128_fst_126 >= id_1302) };
                                letpair_res_1282 = id_1303;
                              }
                              let_res_1281 = letpair_res_1282;
                            }
                            while_flag_1277 = let_res_1281;
                            if (while_flag_1277) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_1277);
                          (void)::dessser::Void();
                          uint8_t id_1304 { 0 };
                          uint32_t id_1305 { leb_ref_122[id_1304] };
                          Size id_1306 { Size(id_1305) };
                          uint8_t id_1307 { 0 };
                          Pointer id_1308 { p_ref_124[id_1307] };
                          ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa id_1309 { id_1306, id_1308 };
                          let_res_1276 = id_1309;
                        }
                        let_res_1274 = let_res_1276;
                      }
                      let_res_1271 = let_res_1274;
                    }
                    ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 let_res_1310;
                    {
                      ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa dstring1_128 { let_res_1271 };
                      ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 letpair_res_1311;
                      {
                        auto dstring1_fst_129 { std::get<0>(dstring1_128) };
                        auto dstring1_snd_130 { std::get<1>(dstring1_128) };
                        ::dessser::gen::alerting_contact::t9ef6882174ae71a34a3c5ef6b29242fb id_1312 { dstring1_snd_130.readBytes(dstring1_fst_129) };
                        ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 letpair_res_1313;
                        {
                          auto dstring2_fst_132 { std::get<0>(id_1312) };
                          auto dstring2_snd_133 { std::get<1>(id_1312) };
                          std::string id_1314 { dstring2_fst_132.toString() };
                          ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 id_1315 { id_1314, dstring2_snd_133 };
                          letpair_res_1313 = id_1315;
                        }
                        letpair_res_1311 = letpair_res_1313;
                      }
                      let_res_1310 = letpair_res_1311;
                    }
                    ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_1316;
                    {
                      ::dessser::gen::alerting_contact::t13a07ee37ab40962540da8534858dc07 drec_134 { let_res_1310 };
                      ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_1317;
                      {
                        auto drec_fst_135 { std::get<0>(drec_134) };
                        auto drec_snd_136 { std::get<1>(drec_134) };
                        ::dessser::gen::alerting_contact::ta97bb48ed75bbda6173555873826c8c6 id_1318 { drec_snd_136.readU16Le() };
                        ::dessser::gen::alerting_contact::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1319;
                        {
                          auto du16_fst_138 { std::get<0>(id_1318) };
                          auto du16_snd_139 { std::get<1>(id_1318) };
                          ::dessser::gen::alerting_contact::ta97bb48ed75bbda6173555873826c8c6 id_1320 { du16_fst_138, du16_snd_139 };
                          letpair_res_1319 = id_1320;
                        }
                        ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_1321;
                        {
                          ::dessser::gen::alerting_contact::ta97bb48ed75bbda6173555873826c8c6 drec_140 { letpair_res_1319 };
                          ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_1322;
                          {
                            auto drec_fst_141 { std::get<0>(drec_140) };
                            auto drec_snd_142 { std::get<1>(drec_140) };
                            uint32_t id_1323 { 0U };
                            Vec<1, uint32_t> id_1324 {  id_1323  };
                            ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1325;
                            {
                              Vec<1, uint32_t> leb_ref_143 { id_1324 };
                              uint8_t id_1326 { 0 };
                              Vec<1, uint8_t> id_1327 {  id_1326  };
                              ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1328;
                              {
                                Vec<1, uint8_t> shft_ref_144 { id_1327 };
                                Vec<1, Pointer> id_1329 {  drec_snd_142  };
                                ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa let_res_1330;
                                {
                                  Vec<1, Pointer> p_ref_145 { id_1329 };
                                  bool while_flag_1331 { true };
                                  do {
                                    uint8_t id_1332 { 0 };
                                    Pointer id_1333 { p_ref_145[id_1332] };
                                    ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 id_1334 { id_1333.readU8() };
                                    bool let_res_1335;
                                    {
                                      ::dessser::gen::alerting_contact::t1a5d74abf838df33f185a72a8912f5c9 leb128_146 { id_1334 };
                                      bool letpair_res_1336;
                                      {
                                        auto leb128_fst_147 { std::get<0>(leb128_146) };
                                        auto leb128_snd_148 { std::get<1>(leb128_146) };
                                        uint8_t id_1337 { 0 };
                                        Void id_1338 { ((void)(p_ref_145[id_1337] = leb128_snd_148), ::dessser::Void()) };
                                        (void)id_1338;
                                        uint8_t id_1339 { 0 };
                                        uint8_t id_1340 { 127 };
                                        uint8_t id_1341 { uint8_t(leb128_fst_147 & id_1340) };
                                        uint32_t id_1342 { uint32_t(id_1341) };
                                        uint8_t id_1343 { 0 };
                                        uint8_t id_1344 { shft_ref_144[id_1343] };
                                        uint32_t id_1345 { uint32_t(id_1342 << id_1344) };
                                        uint8_t id_1346 { 0 };
                                        uint32_t id_1347 { leb_ref_143[id_1346] };
                                        uint32_t id_1348 { uint32_t(id_1345 | id_1347) };
                                        Void id_1349 { ((void)(leb_ref_143[id_1339] = id_1348), ::dessser::Void()) };
                                        (void)id_1349;
                                        uint8_t id_1350 { 0 };
                                        uint8_t id_1351 { 0 };
                                        uint8_t id_1352 { shft_ref_144[id_1351] };
                                        uint8_t id_1353 { 7 };
                                        uint8_t id_1354 { uint8_t(id_1352 + id_1353) };
                                        Void id_1355 { ((void)(shft_ref_144[id_1350] = id_1354), ::dessser::Void()) };
                                        (void)id_1355;
                                        uint8_t id_1356 { 128 };
                                        bool id_1357 { bool(leb128_fst_147 >= id_1356) };
                                        letpair_res_1336 = id_1357;
                                      }
                                      let_res_1335 = letpair_res_1336;
                                    }
                                    while_flag_1331 = let_res_1335;
                                    if (while_flag_1331) {
                                      (void)::dessser::Void();
                                    }
                                  } while (while_flag_1331);
                                  (void)::dessser::Void();
                                  uint8_t id_1358 { 0 };
                                  uint32_t id_1359 { leb_ref_143[id_1358] };
                                  Size id_1360 { Size(id_1359) };
                                  uint8_t id_1361 { 0 };
                                  Pointer id_1362 { p_ref_145[id_1361] };
                                  ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa id_1363 { id_1360, id_1362 };
                                  let_res_1330 = id_1363;
                                }
                                let_res_1328 = let_res_1330;
                              }
                              let_res_1325 = let_res_1328;
                            }
                            ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 let_res_1364;
                            {
                              ::dessser::gen::alerting_contact::t12fb9c475959b52bf7b17b155a955ffa dstring1_149 { let_res_1325 };
                              ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_1365;
                              {
                                auto dstring1_fst_150 { std::get<0>(dstring1_149) };
                                auto dstring1_snd_151 { std::get<1>(dstring1_149) };
                                ::dessser::gen::alerting_contact::t9ef6882174ae71a34a3c5ef6b29242fb id_1366 { dstring1_snd_151.readBytes(dstring1_fst_150) };
                                ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 letpair_res_1367;
                                {
                                  auto dstring2_fst_153 { std::get<0>(id_1366) };
                                  auto dstring2_snd_154 { std::get<1>(id_1366) };
                                  std::string id_1368 { dstring2_fst_153.toString() };
                                  ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 id_1369 { drec_fst_120, drec_fst_135, drec_fst_141, id_1368 };
                                  std::shared_ptr<::dessser::gen::alerting_contact::via>  id_1370 { std::make_shared<::dessser::gen::alerting_contact::via>(std::in_place_index<4>, id_1369) };
                                  ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 id_1371 { id_1370, dstring2_snd_154 };
                                  letpair_res_1367 = id_1371;
                                }
                                letpair_res_1365 = letpair_res_1367;
                              }
                              let_res_1364 = letpair_res_1365;
                            }
                            letpair_res_1322 = let_res_1364;
                          }
                          let_res_1321 = letpair_res_1322;
                        }
                        letpair_res_1317 = let_res_1321;
                      }
                      let_res_1316 = letpair_res_1317;
                    }
                    letpair_res_1268 = let_res_1316;
                  }
                  let_res_1267 = letpair_res_1268;
                }
                choose_res_951 = let_res_1267;
              }
              choose_res_900 = choose_res_951;
            }
            choose_res_849 = choose_res_900;
          }
          choose_res_844 = choose_res_849;
        }
        letpair_res_841 = choose_res_844;
      }
      let_res_840 = letpair_res_841;
    }
    return let_res_840;
  }
   };
  return fun836;
}
std::function<::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523(Pointer)> via_of_row_binary(via_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_242" (apply (identifier "via-of-row-binary") (param 0))
        (let-pair "drec_fst_243" "drec_snd_244" (identifier "drec_242")
          (let-pair "dfloat_fst_246" "dfloat_snd_247" (read-u64 little-endian (identifier "drec_snd_244"))
            (make-tup (make-rec (string "timeout") (float-of-u64 (identifier "dfloat_fst_246")) (string "via") (identifier "drec_fst_243")) (identifier "dfloat_snd_247"))))))
 */
static std::function<::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae(Pointer)> fun1372 { [&](Pointer p_0) {
    ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 id_1373 { via_of_row_binary(p_0) };
    ::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae let_res_1374;
    {
      ::dessser::gen::alerting_contact::t4f2037d06e9b8c11be7f16b6ac8dd523 drec_242 { id_1373 };
      ::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae letpair_res_1375;
      {
        auto drec_fst_243 { std::get<0>(drec_242) };
        auto drec_snd_244 { std::get<1>(drec_242) };
        ::dessser::gen::alerting_contact::td2cd337bb3c8bc04d5603393d084985b id_1376 { drec_snd_244.readU64Le() };
        ::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae letpair_res_1377;
        {
          auto dfloat_fst_246 { std::get<0>(id_1376) };
          auto dfloat_snd_247 { std::get<1>(id_1376) };
          double id_1378 { float_of_qword(dfloat_fst_246) };
          std::shared_ptr<::dessser::gen::alerting_contact::t>  id_1379 { std::make_shared<::dessser::gen::alerting_contact::t>(drec_fst_243, id_1378) };
          ::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae id_1380 { id_1379, dfloat_snd_247 };
          letpair_res_1377 = id_1380;
        }
        letpair_res_1375 = letpair_res_1377;
      }
      let_res_1374 = letpair_res_1375;
    }
    return let_res_1374;
  }
   };
  return fun1372;
}
std::function<::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_252" "make_snd_253" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_252") (identifier "make_snd_253"))))
 */
static std::function<::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae(Pointer)> fun1381 { [&](Pointer p_0) {
    ::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae id_1382 { of_row_binary(p_0) };
    ::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae letpair_res_1383;
    {
      auto make_fst_252 { std::get<0>(id_1382) };
      auto make_snd_253 { std::get<1>(id_1382) };
      ::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae id_1384 { make_fst_252, make_snd_253 };
      letpair_res_1383 = id_1384;
    }
    return letpair_res_1383;
  }
   };
  return fun1381;
}
std::function<::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{via: (via AS [Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]); timeout: FLOAT}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::t> ,Pointer)> fun1385 { [&](std::shared_ptr<::dessser::gen::alerting_contact::t>  p_0, Pointer p_1) {
    Pointer id_1386 { to_row_binary(p_0, p_1) };
    return id_1386;
  }
   };
  return fun1385;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
