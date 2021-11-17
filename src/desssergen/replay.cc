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
struct t8b5761d72d0b8fde816fcaa9bfc21290 : public std::tuple<
  dessser::gen::fq_function_name::t_ext,
  dessser::gen::fq_function_name::t_ext
> {
  using tuple::tuple;
  t8b5761d72d0b8fde816fcaa9bfc21290(std::tuple<dessser::gen::fq_function_name::t_ext, dessser::gen::fq_function_name::t_ext> p)
    : std::tuple<dessser::gen::fq_function_name::t_ext, dessser::gen::fq_function_name::t_ext>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8b5761d72d0b8fde816fcaa9bfc21290 const &a, t8b5761d72d0b8fde816fcaa9bfc21290 const &b) {
  return ::dessser::gen::fq_function_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<0>(b)) && ::dessser::gen::fq_function_name::Deref(std::get<1>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<1>(b));
}
inline bool operator!=(t8b5761d72d0b8fde816fcaa9bfc21290 const &a, t8b5761d72d0b8fde816fcaa9bfc21290 const &b) {
  return !operator==(a, b);
}
struct t249796f29bea1f0bea9516f4b3a8f909 : public std::variant<
  dessser::gen::file_path::t_ext, // RingBuf
  dessser::gen::sync_key::t_ext // SyncKey
> { using variant::variant; };

inline bool operator==(t249796f29bea1f0bea9516f4b3a8f909 const &a, t249796f29bea1f0bea9516f4b3a8f909 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)); // RingBuf
    case 1: return ::dessser::gen::sync_key::Deref(std::get<1>(a)) == ::dessser::gen::sync_key::Deref(std::get<1>(b)); // SyncKey
  };
  return false;
}
inline bool operator!=(t249796f29bea1f0bea9516f4b3a8f909 const &a, t249796f29bea1f0bea9516f4b3a8f909 const &b) {
  return !operator==(a, b);
}
struct t {
  uint16_t channel;
  Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> links;
  ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 recipient;
  double since;
  Arr<dessser::gen::fq_function_name::t_ext> sources;
  dessser::gen::fq_function_name::t_ext target;
  std::string target_fieldmask;
  double timeout_date;
  double until;
  t(uint16_t channel_, Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> links_, ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 recipient_, double since_, Arr<dessser::gen::fq_function_name::t_ext> sources_, dessser::gen::fq_function_name::t_ext target_, std::string target_fieldmask_, double timeout_date_, double until_) : channel(channel_), links(links_), recipient(recipient_), since(since_), sources(sources_), target(target_), target_fieldmask(target_fieldmask_), timeout_date(timeout_date_), until(until_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.channel == b.channel && a.links == b.links && a.recipient == b.recipient && a.since == b.since && a.sources == b.sources && ::dessser::gen::fq_function_name::Deref(a.target) == ::dessser::gen::fq_function_name::Deref(b.target) && a.target_fieldmask == b.target_fieldmask && a.timeout_date == b.timeout_date && a.until == b.until;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t0e599894aecab3395c467833ad77eb85 : public std::tuple<
  std::shared_ptr<::dessser::gen::replay::t> ,
  Pointer
> {
  using tuple::tuple;
  t0e599894aecab3395c467833ad77eb85(std::tuple<std::shared_ptr<::dessser::gen::replay::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::replay::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0e599894aecab3395c467833ad77eb85 const &a, t0e599894aecab3395c467833ad77eb85 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0e599894aecab3395c467833ad77eb85 const &a, t0e599894aecab3395c467833ad77eb85 const &b) {
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
struct tc67a116b5bcd191e2624b1f2b2b1794a : public std::tuple<
  dessser::gen::fq_function_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tc67a116b5bcd191e2624b1f2b2b1794a(std::tuple<dessser::gen::fq_function_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_function_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc67a116b5bcd191e2624b1f2b2b1794a const &a, tc67a116b5bcd191e2624b1f2b2b1794a const &b) {
  return ::dessser::gen::fq_function_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc67a116b5bcd191e2624b1f2b2b1794a const &a, tc67a116b5bcd191e2624b1f2b2b1794a const &b) {
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
struct t3fd8221434e489b54b5c4356ebff5005 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t3fd8221434e489b54b5c4356ebff5005(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3fd8221434e489b54b5c4356ebff5005 const &a, t3fd8221434e489b54b5c4356ebff5005 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3fd8221434e489b54b5c4356ebff5005 const &a, t3fd8221434e489b54b5c4356ebff5005 const &b) {
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
struct tf8bffbf00e9517eec4d771eb352fa990 : public std::tuple<
  ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909,
  Pointer
> {
  using tuple::tuple;
  tf8bffbf00e9517eec4d771eb352fa990(std::tuple<::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909, Pointer> p)
    : std::tuple<::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf8bffbf00e9517eec4d771eb352fa990 const &a, tf8bffbf00e9517eec4d771eb352fa990 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf8bffbf00e9517eec4d771eb352fa990 const &a, tf8bffbf00e9517eec4d771eb352fa990 const &b) {
  return !operator==(a, b);
}
struct tb06ffbf6da2300d8f0de21eea734e5f2 : public std::tuple<
  dessser::gen::file_path::t_ext,
  Pointer
> {
  using tuple::tuple;
  tb06ffbf6da2300d8f0de21eea734e5f2(std::tuple<dessser::gen::file_path::t_ext, Pointer> p)
    : std::tuple<dessser::gen::file_path::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb06ffbf6da2300d8f0de21eea734e5f2 const &a, tb06ffbf6da2300d8f0de21eea734e5f2 const &b) {
  return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb06ffbf6da2300d8f0de21eea734e5f2 const &a, tb06ffbf6da2300d8f0de21eea734e5f2 const &b) {
  return !operator==(a, b);
}
struct t9bda35a83af38220b883fe5d84e6ed9f : public std::tuple<
  dessser::gen::sync_key::t_ext,
  Pointer
> {
  using tuple::tuple;
  t9bda35a83af38220b883fe5d84e6ed9f(std::tuple<dessser::gen::sync_key::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_key::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9bda35a83af38220b883fe5d84e6ed9f const &a, t9bda35a83af38220b883fe5d84e6ed9f const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9bda35a83af38220b883fe5d84e6ed9f const &a, t9bda35a83af38220b883fe5d84e6ed9f const &b) {
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
struct t224e407810f4c01679f3bd319cbc6314 : public std::tuple<
  Lst<dessser::gen::fq_function_name::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t224e407810f4c01679f3bd319cbc6314(std::tuple<Lst<dessser::gen::fq_function_name::t_ext>, Pointer> p)
    : std::tuple<Lst<dessser::gen::fq_function_name::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t224e407810f4c01679f3bd319cbc6314 const &a, t224e407810f4c01679f3bd319cbc6314 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t224e407810f4c01679f3bd319cbc6314 const &a, t224e407810f4c01679f3bd319cbc6314 const &b) {
  return !operator==(a, b);
}
struct t5b49e5a21d5a9df016dd7fe81e264a61 : public std::tuple<
  Arr<dessser::gen::fq_function_name::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t5b49e5a21d5a9df016dd7fe81e264a61(std::tuple<Arr<dessser::gen::fq_function_name::t_ext>, Pointer> p)
    : std::tuple<Arr<dessser::gen::fq_function_name::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5b49e5a21d5a9df016dd7fe81e264a61 const &a, t5b49e5a21d5a9df016dd7fe81e264a61 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5b49e5a21d5a9df016dd7fe81e264a61 const &a, t5b49e5a21d5a9df016dd7fe81e264a61 const &b) {
  return !operator==(a, b);
}
struct t9955e139d945579b7b0b7f578d074e18 : public std::tuple<
  Lst<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290>,
  Pointer
> {
  using tuple::tuple;
  t9955e139d945579b7b0b7f578d074e18(std::tuple<Lst<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9955e139d945579b7b0b7f578d074e18 const &a, t9955e139d945579b7b0b7f578d074e18 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9955e139d945579b7b0b7f578d074e18 const &a, t9955e139d945579b7b0b7f578d074e18 const &b) {
  return !operator==(a, b);
}
struct tc0f47151efbaf2e403a11655e44057c9 : public std::tuple<
  Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290>,
  Pointer
> {
  using tuple::tuple;
  tc0f47151efbaf2e403a11655e44057c9(std::tuple<Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290>, Pointer> p)
    : std::tuple<Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc0f47151efbaf2e403a11655e44057c9 const &a, tc0f47151efbaf2e403a11655e44057c9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc0f47151efbaf2e403a11655e44057c9 const &a, tc0f47151efbaf2e403a11655e44057c9 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{channel: U16; target: $fq_function_name; target_fieldmask: STRING; since: FLOAT; until: FLOAT; recipient: [RingBuf $file_path | SyncKey $sync_key]; sources: $fq_function_name[]; links: ($fq_function_name; $fq_function_name)[]; timeout_date: FLOAT}" "Ptr")
      (let "srec_dst_223"
        (let "srec_dst_215"
          (let "srec_dst_209"
            (let "srec_dst_206"
              (let "srec_dst_205"
                (let "srec_dst_204"
                  (let "srec_dst_201"
                    (let "srec_dst_200" (write-u16 little-endian (param 1) (get-field "channel" (param 0))) (apply (ext-identifier fq_function_name to-row-binary) (get-field "target" (param 0)) (identifier "srec_dst_200")))
                    (write-bytes
                      (let "leb128_sz_202" (make-vec (string-length (get-field "target_fieldmask" (param 0))))
                        (let "leb128_ptr_203" (make-vec (identifier "srec_dst_201"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_203")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_203"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_202"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_202"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_202"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_202") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_202")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_202")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_203"))))) 
                      (bytes-of-string (get-field "target_fieldmask" (param 0))))) 
                  (write-u64 little-endian (identifier "srec_dst_204") (u64-of-float (get-field "since" (param 0))))) 
                (write-u64 little-endian (identifier "srec_dst_205") (u64-of-float (get-field "until" (param 0)))))
              (let "ssum_dst_208" (write-u16 little-endian (identifier "srec_dst_206") (label-of (get-field "recipient" (param 0))))
                (if (eq (u16 0) (label-of (get-field "recipient" (param 0)))) 
                  (apply (ext-identifier file_path to-row-binary) (get-alt "RingBuf" (get-field "recipient" (param 0))) (identifier "ssum_dst_208"))
                  (seq (assert (eq (label-of (get-field "recipient" (param 0))) (u16 1))) (apply (ext-identifier sync_key to-row-binary) (get-alt "SyncKey" (get-field "recipient" (param 0))) (identifier "ssum_dst_208"))))))
            (let "dst_ref_212"
              (make-vec
                (let "leb128_sz_210" (make-vec (cardinality (get-field "sources" (param 0))))
                  (let "leb128_ptr_211" (make-vec (identifier "srec_dst_209"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_211")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_211"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_210"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_210"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_210"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_210") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_210")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_210")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_211"))))))
              (let "n_ref_213" (make-vec (i32 0))
                (seq
                  (for-each "x_214" (get-field "sources" (param 0))
                    (seq (set-vec (u8 0) (identifier "dst_ref_212") (apply (ext-identifier fq_function_name to-row-binary) (identifier "x_214") (unsafe-nth (u8 0) (identifier "dst_ref_212"))))
                      (set-vec (u8 0) (identifier "n_ref_213") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_213")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_212"))))))
          (let "dst_ref_218"
            (make-vec
              (let "leb128_sz_216" (make-vec (cardinality (get-field "links" (param 0))))
                (let "leb128_ptr_217" (make-vec (identifier "srec_dst_215"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_217")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_217"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_216"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_216"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_216"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_216") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_216")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_216")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_217"))))))
            (let "n_ref_219" (make-vec (i32 0))
              (seq
                (for-each "x_220" (get-field "links" (param 0))
                  (seq
                    (set-vec (u8 0) (identifier "dst_ref_218")
                      (let "stup_dst_222" (let "stup_dst_221" (unsafe-nth (u8 0) (identifier "dst_ref_218")) (apply (ext-identifier fq_function_name to-row-binary) (get-item 0 (identifier "x_220")) (identifier "stup_dst_221")))
                        (apply (ext-identifier fq_function_name to-row-binary) (get-item 1 (identifier "x_220")) (identifier "stup_dst_222"))))
                    (set-vec (u8 0) (identifier "n_ref_219") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_219")))))) 
                (unsafe-nth (u8 0) (identifier "dst_ref_218")))))) (write-u64 little-endian (identifier "srec_dst_223") (u64-of-float (get-field "timeout_date" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::replay::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::replay::t> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::replay::t>  p_0, Pointer p_1) {
    uint16_t id_1 { (*p_0).channel };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_200 { id_2 };
      auto fun4 { dessser::gen::fq_function_name::to_row_binary };
      dessser::gen::fq_function_name::t_ext id_5 { (*p_0).target };
      Pointer id_6 { fun4(id_5, srec_dst_200) };
      let_res_3 = id_6;
    }
    Pointer let_res_7;
    {
      Pointer srec_dst_201 { let_res_3 };
      std::string id_8 { (*p_0).target_fieldmask };
      uint32_t id_9 { (uint32_t)id_8.size() };
      Vec<1, uint32_t> id_10 {  id_9  };
      Pointer let_res_11;
      {
        Vec<1, uint32_t> leb128_sz_202 { id_10 };
        Vec<1, Pointer> id_12 {  srec_dst_201  };
        Pointer let_res_13;
        {
          Vec<1, Pointer> leb128_ptr_203 { id_12 };
          bool while_flag_14 { true };
          do {
            uint8_t id_15 { 0 };
            uint8_t id_16 { 0 };
            Pointer id_17 { leb128_ptr_203[id_16] };
            uint32_t id_18 { 128U };
            uint8_t id_19 { 0 };
            uint32_t id_20 { leb128_sz_202[id_19] };
            bool id_21 { bool(id_18 > id_20) };
            uint8_t choose_res_22;
            if (id_21) {
              uint8_t id_23 { 0 };
              uint32_t id_24 { leb128_sz_202[id_23] };
              uint8_t id_25 { uint8_t(id_24) };
              choose_res_22 = id_25;
            } else {
              uint8_t id_26 { 0 };
              uint32_t id_27 { leb128_sz_202[id_26] };
              uint8_t id_28 { uint8_t(id_27) };
              uint8_t id_29 { 128 };
              uint8_t id_30 { uint8_t(id_28 | id_29) };
              choose_res_22 = id_30;
            }
            Pointer id_31 { id_17.writeU8(choose_res_22) };
            Void id_32 { ((void)(leb128_ptr_203[id_15] = id_31), VOID) };
            (void)id_32;
            uint8_t id_33 { 0 };
            uint8_t id_34 { 0 };
            uint32_t id_35 { leb128_sz_202[id_34] };
            uint8_t id_36 { 7 };
            uint32_t id_37 { uint32_t(id_35 >> id_36) };
            Void id_38 { ((void)(leb128_sz_202[id_33] = id_37), VOID) };
            (void)id_38;
            uint8_t id_39 { 0 };
            uint32_t id_40 { leb128_sz_202[id_39] };
            uint32_t id_41 { 0U };
            bool id_42 { bool(id_40 > id_41) };
            while_flag_14 = id_42;
            if (while_flag_14) {
              (void)VOID;
            }
          } while (while_flag_14);
          (void)VOID;
          uint8_t id_43 { 0 };
          Pointer id_44 { leb128_ptr_203[id_43] };
          let_res_13 = id_44;
        }
        let_res_11 = let_res_13;
      }
      std::string id_45 { (*p_0).target_fieldmask };
      Bytes id_46 { id_45 };
      Pointer id_47 { let_res_11.writeBytes(id_46) };
      let_res_7 = id_47;
    }
    Pointer let_res_48;
    {
      Pointer srec_dst_204 { let_res_7 };
      double id_49 { (*p_0).since };
      uint64_t id_50 { qword_of_float(id_49) };
      Pointer id_51 { srec_dst_204.writeU64Le(id_50) };
      let_res_48 = id_51;
    }
    Pointer let_res_52;
    {
      Pointer srec_dst_205 { let_res_48 };
      double id_53 { (*p_0).until };
      uint64_t id_54 { qword_of_float(id_53) };
      Pointer id_55 { srec_dst_205.writeU64Le(id_54) };
      let_res_52 = id_55;
    }
    Pointer let_res_56;
    {
      Pointer srec_dst_206 { let_res_52 };
      ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_57 { (*p_0).recipient };
      uint16_t id_58 { uint16_t(id_57.index()) };
      Pointer id_59 { srec_dst_206.writeU16Le(id_58) };
      Pointer let_res_60;
      {
        Pointer ssum_dst_208 { id_59 };
        uint16_t id_61 { 0 };
        ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_62 { (*p_0).recipient };
        uint16_t id_63 { uint16_t(id_62.index()) };
        bool id_64 { bool(id_61 == id_63) };
        Pointer choose_res_65;
        if (id_64) {
          auto fun66 { dessser::gen::file_path::to_row_binary };
          ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_67 { (*p_0).recipient };
          dessser::gen::file_path::t_ext id_68 { std::get<0 /* RingBuf */>(id_67) };
          Pointer id_69 { fun66(id_68, ssum_dst_208) };
          choose_res_65 = id_69;
        } else {
          ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_70 { (*p_0).recipient };
          uint16_t id_71 { uint16_t(id_70.index()) };
          uint16_t id_72 { 1 };
          bool id_73 { bool(id_71 == id_72) };
          Void id_74 { ((void)(assert(id_73)), VOID) };
          (void)id_74;
          auto fun75 { dessser::gen::sync_key::to_row_binary };
          ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_76 { (*p_0).recipient };
          dessser::gen::sync_key::t_ext id_77 { std::get<1 /* SyncKey */>(id_76) };
          Pointer id_78 { fun75(id_77, ssum_dst_208) };
          choose_res_65 = id_78;
        }
        let_res_60 = choose_res_65;
      }
      let_res_56 = let_res_60;
    }
    Pointer let_res_79;
    {
      Pointer srec_dst_209 { let_res_56 };
      Arr<dessser::gen::fq_function_name::t_ext> id_80 { (*p_0).sources };
      uint32_t id_81 { id_80.size() };
      Vec<1, uint32_t> id_82 {  id_81  };
      Pointer let_res_83;
      {
        Vec<1, uint32_t> leb128_sz_210 { id_82 };
        Vec<1, Pointer> id_84 {  srec_dst_209  };
        Pointer let_res_85;
        {
          Vec<1, Pointer> leb128_ptr_211 { id_84 };
          bool while_flag_86 { true };
          do {
            uint8_t id_87 { 0 };
            uint8_t id_88 { 0 };
            Pointer id_89 { leb128_ptr_211[id_88] };
            uint32_t id_90 { 128U };
            uint8_t id_91 { 0 };
            uint32_t id_92 { leb128_sz_210[id_91] };
            bool id_93 { bool(id_90 > id_92) };
            uint8_t choose_res_94;
            if (id_93) {
              uint8_t id_95 { 0 };
              uint32_t id_96 { leb128_sz_210[id_95] };
              uint8_t id_97 { uint8_t(id_96) };
              choose_res_94 = id_97;
            } else {
              uint8_t id_98 { 0 };
              uint32_t id_99 { leb128_sz_210[id_98] };
              uint8_t id_100 { uint8_t(id_99) };
              uint8_t id_101 { 128 };
              uint8_t id_102 { uint8_t(id_100 | id_101) };
              choose_res_94 = id_102;
            }
            Pointer id_103 { id_89.writeU8(choose_res_94) };
            Void id_104 { ((void)(leb128_ptr_211[id_87] = id_103), VOID) };
            (void)id_104;
            uint8_t id_105 { 0 };
            uint8_t id_106 { 0 };
            uint32_t id_107 { leb128_sz_210[id_106] };
            uint8_t id_108 { 7 };
            uint32_t id_109 { uint32_t(id_107 >> id_108) };
            Void id_110 { ((void)(leb128_sz_210[id_105] = id_109), VOID) };
            (void)id_110;
            uint8_t id_111 { 0 };
            uint32_t id_112 { leb128_sz_210[id_111] };
            uint32_t id_113 { 0U };
            bool id_114 { bool(id_112 > id_113) };
            while_flag_86 = id_114;
            if (while_flag_86) {
              (void)VOID;
            }
          } while (while_flag_86);
          (void)VOID;
          uint8_t id_115 { 0 };
          Pointer id_116 { leb128_ptr_211[id_115] };
          let_res_85 = id_116;
        }
        let_res_83 = let_res_85;
      }
      Vec<1, Pointer> id_117 {  let_res_83  };
      Pointer let_res_118;
      {
        Vec<1, Pointer> dst_ref_212 { id_117 };
        int32_t id_119 { 0L };
        Vec<1, int32_t> id_120 {  id_119  };
        Pointer let_res_121;
        {
          Vec<1, int32_t> n_ref_213 { id_120 };
          Arr<dessser::gen::fq_function_name::t_ext> id_122 { (*p_0).sources };
          for (dessser::gen::fq_function_name::t_ext x_214 : id_122) {
            uint8_t id_123 { 0 };
            auto fun124 { dessser::gen::fq_function_name::to_row_binary };
            uint8_t id_125 { 0 };
            Pointer id_126 { dst_ref_212[id_125] };
            Pointer id_127 { fun124(x_214, id_126) };
            Void id_128 { ((void)(dst_ref_212[id_123] = id_127), VOID) };
            (void)id_128;
            uint8_t id_129 { 0 };
            int32_t id_130 { 1L };
            uint8_t id_131 { 0 };
            int32_t id_132 { n_ref_213[id_131] };
            int32_t id_133 { int32_t(id_130 + id_132) };
            Void id_134 { ((void)(n_ref_213[id_129] = id_133), VOID) };
            (void)id_134;
            (void)id_134;
          }
          (void)VOID;
          uint8_t id_135 { 0 };
          Pointer id_136 { dst_ref_212[id_135] };
          let_res_121 = id_136;
        }
        let_res_118 = let_res_121;
      }
      let_res_79 = let_res_118;
    }
    Pointer let_res_137;
    {
      Pointer srec_dst_215 { let_res_79 };
      Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> id_138 { (*p_0).links };
      uint32_t id_139 { id_138.size() };
      Vec<1, uint32_t> id_140 {  id_139  };
      Pointer let_res_141;
      {
        Vec<1, uint32_t> leb128_sz_216 { id_140 };
        Vec<1, Pointer> id_142 {  srec_dst_215  };
        Pointer let_res_143;
        {
          Vec<1, Pointer> leb128_ptr_217 { id_142 };
          bool while_flag_144 { true };
          do {
            uint8_t id_145 { 0 };
            uint8_t id_146 { 0 };
            Pointer id_147 { leb128_ptr_217[id_146] };
            uint32_t id_148 { 128U };
            uint8_t id_149 { 0 };
            uint32_t id_150 { leb128_sz_216[id_149] };
            bool id_151 { bool(id_148 > id_150) };
            uint8_t choose_res_152;
            if (id_151) {
              uint8_t id_153 { 0 };
              uint32_t id_154 { leb128_sz_216[id_153] };
              uint8_t id_155 { uint8_t(id_154) };
              choose_res_152 = id_155;
            } else {
              uint8_t id_156 { 0 };
              uint32_t id_157 { leb128_sz_216[id_156] };
              uint8_t id_158 { uint8_t(id_157) };
              uint8_t id_159 { 128 };
              uint8_t id_160 { uint8_t(id_158 | id_159) };
              choose_res_152 = id_160;
            }
            Pointer id_161 { id_147.writeU8(choose_res_152) };
            Void id_162 { ((void)(leb128_ptr_217[id_145] = id_161), VOID) };
            (void)id_162;
            uint8_t id_163 { 0 };
            uint8_t id_164 { 0 };
            uint32_t id_165 { leb128_sz_216[id_164] };
            uint8_t id_166 { 7 };
            uint32_t id_167 { uint32_t(id_165 >> id_166) };
            Void id_168 { ((void)(leb128_sz_216[id_163] = id_167), VOID) };
            (void)id_168;
            uint8_t id_169 { 0 };
            uint32_t id_170 { leb128_sz_216[id_169] };
            uint32_t id_171 { 0U };
            bool id_172 { bool(id_170 > id_171) };
            while_flag_144 = id_172;
            if (while_flag_144) {
              (void)VOID;
            }
          } while (while_flag_144);
          (void)VOID;
          uint8_t id_173 { 0 };
          Pointer id_174 { leb128_ptr_217[id_173] };
          let_res_143 = id_174;
        }
        let_res_141 = let_res_143;
      }
      Vec<1, Pointer> id_175 {  let_res_141  };
      Pointer let_res_176;
      {
        Vec<1, Pointer> dst_ref_218 { id_175 };
        int32_t id_177 { 0L };
        Vec<1, int32_t> id_178 {  id_177  };
        Pointer let_res_179;
        {
          Vec<1, int32_t> n_ref_219 { id_178 };
          Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> id_180 { (*p_0).links };
          for (::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290 x_220 : id_180) {
            uint8_t id_181 { 0 };
            uint8_t id_182 { 0 };
            Pointer id_183 { dst_ref_218[id_182] };
            Pointer let_res_184;
            {
              Pointer stup_dst_221 { id_183 };
              auto fun185 { dessser::gen::fq_function_name::to_row_binary };
              dessser::gen::fq_function_name::t_ext id_186 { std::get<0>(x_220) };
              Pointer id_187 { fun185(id_186, stup_dst_221) };
              let_res_184 = id_187;
            }
            Pointer let_res_188;
            {
              Pointer stup_dst_222 { let_res_184 };
              auto fun189 { dessser::gen::fq_function_name::to_row_binary };
              dessser::gen::fq_function_name::t_ext id_190 { std::get<1>(x_220) };
              Pointer id_191 { fun189(id_190, stup_dst_222) };
              let_res_188 = id_191;
            }
            Void id_192 { ((void)(dst_ref_218[id_181] = let_res_188), VOID) };
            (void)id_192;
            uint8_t id_193 { 0 };
            int32_t id_194 { 1L };
            uint8_t id_195 { 0 };
            int32_t id_196 { n_ref_219[id_195] };
            int32_t id_197 { int32_t(id_194 + id_196) };
            Void id_198 { ((void)(n_ref_219[id_193] = id_197), VOID) };
            (void)id_198;
            (void)id_198;
          }
          (void)VOID;
          uint8_t id_199 { 0 };
          Pointer id_200 { dst_ref_218[id_199] };
          let_res_179 = id_200;
        }
        let_res_176 = let_res_179;
      }
      let_res_137 = let_res_176;
    }
    Pointer let_res_201;
    {
      Pointer srec_dst_223 { let_res_137 };
      double id_202 { (*p_0).timeout_date };
      uint64_t id_203 { qword_of_float(id_202) };
      Pointer id_204 { srec_dst_223.writeU64Le(id_203) };
      let_res_201 = id_204;
    }
    return let_res_201;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::replay::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{channel: U16; target: $fq_function_name; target_fieldmask: STRING; since: FLOAT; until: FLOAT; recipient: [RingBuf $file_path | SyncKey $sync_key]; sources: $fq_function_name[]; links: ($fq_function_name; $fq_function_name)[]; timeout_date: FLOAT}")
      (add
        (let "sz_192"
          (let "sz_187"
            (let "sz_185"
              (add
                (add
                  (let "sz_179" (add (size 2) (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-field "target" (param 0))))
                    (add (identifier "sz_179")
                      (add
                        (let "n_ref_181" (make-vec (string-length (get-field "target_fieldmask" (param 0))))
                          (let "lebsz_ref_182" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_181")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_182")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_182") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_182")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_182")))))) 
                        (size-of-u32 (string-length (get-field "target_fieldmask" (param 0))))))) 
                  (size 8)) (size 8))
              (if (eq (u16 0) (label-of (get-field "recipient" (param 0)))) 
                (add (add (identifier "sz_185") (size 2)) (apply (ext-identifier file_path sersize-of-row-binary) (get-alt "RingBuf" (get-field "recipient" (param 0)))))
                (seq (assert (eq (label-of (get-field "recipient" (param 0))) (u16 1)))
                  (add (add (identifier "sz_185") (size 2)) (apply (ext-identifier sync_key sersize-of-row-binary) (get-alt "SyncKey" (get-field "recipient" (param 0))))))))
            (let "sz_ref_190"
              (make-vec
                (add (identifier "sz_187")
                  (let "n_ref_188" (make-vec (cardinality (get-field "sources" (param 0))))
                    (let "lebsz_ref_189" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_188")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_189")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_189") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_189")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_189"))))))))
              (seq
                (let "repeat_n_191" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "sources" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_191")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_190")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_190"))
                          (apply (ext-identifier fq_function_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_191")) (get-field "sources" (param 0))))))
                      (set-vec (u8 0) (identifier "repeat_n_191") (add (unsafe-nth (u8 0) (identifier "repeat_n_191")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_190")))))
          (let "sz_ref_195"
            (make-vec
              (add (identifier "sz_192")
                (let "n_ref_193" (make-vec (cardinality (get-field "links" (param 0))))
                  (let "lebsz_ref_194" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_193")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_194")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_194") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_194")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_194"))))))))
            (seq
              (let "repeat_n_196" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "links" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_196")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_195")
                      (let "sz_198"
                        (let "sz_197" (unsafe-nth (u8 0) (identifier "sz_ref_195"))
                          (add (identifier "sz_197") (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_196")) (get-field "links" (param 0)))))))
                        (add (identifier "sz_198") (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_196")) (get-field "links" (param 0))))))))
                    (set-vec (u8 0) (identifier "repeat_n_196") (add (unsafe-nth (u8 0) (identifier "repeat_n_196")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_195"))))) (size 8)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::replay::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::replay::t> )> fun205 { [&fun205](std::shared_ptr<::dessser::gen::replay::t>  p_0) {
    Size id_206 { 2UL };
    auto fun207 { dessser::gen::fq_function_name::sersize_of_row_binary };
    dessser::gen::fq_function_name::t_ext id_208 { (*p_0).target };
    Size id_209 { fun207(id_208) };
    Size id_210 { Size(id_206 + id_209) };
    Size let_res_211;
    {
      Size sz_179 { id_210 };
      std::string id_212 { (*p_0).target_fieldmask };
      uint32_t id_213 { (uint32_t)id_212.size() };
      Vec<1, uint32_t> id_214 {  id_213  };
      Size let_res_215;
      {
        Vec<1, uint32_t> n_ref_181 { id_214 };
        uint32_t id_216 { 1U };
        Vec<1, uint32_t> id_217 {  id_216  };
        Size let_res_218;
        {
          Vec<1, uint32_t> lebsz_ref_182 { id_217 };
          bool while_flag_219 { true };
          do {
            uint8_t id_220 { 0 };
            uint32_t id_221 { n_ref_181[id_220] };
            uint8_t id_222 { 0 };
            uint32_t id_223 { lebsz_ref_182[id_222] };
            uint8_t id_224 { 7 };
            uint32_t id_225 { uint32_t(id_223 << id_224) };
            bool id_226 { bool(id_221 >= id_225) };
            while_flag_219 = id_226;
            if (while_flag_219) {
              uint8_t id_227 { 0 };
              uint8_t id_228 { 0 };
              uint32_t id_229 { lebsz_ref_182[id_228] };
              uint32_t id_230 { 1U };
              uint32_t id_231 { uint32_t(id_229 + id_230) };
              Void id_232 { ((void)(lebsz_ref_182[id_227] = id_231), VOID) };
              (void)id_232;
            }
          } while (while_flag_219);
          (void)VOID;
          uint8_t id_233 { 0 };
          uint32_t id_234 { lebsz_ref_182[id_233] };
          Size id_235 { Size(id_234) };
          let_res_218 = id_235;
        }
        let_res_215 = let_res_218;
      }
      std::string id_236 { (*p_0).target_fieldmask };
      uint32_t id_237 { (uint32_t)id_236.size() };
      Size id_238 { Size(id_237) };
      Size id_239 { Size(let_res_215 + id_238) };
      Size id_240 { Size(sz_179 + id_239) };
      let_res_211 = id_240;
    }
    Size id_241 { 8UL };
    Size id_242 { Size(let_res_211 + id_241) };
    Size id_243 { 8UL };
    Size id_244 { Size(id_242 + id_243) };
    Size let_res_245;
    {
      Size sz_185 { id_244 };
      uint16_t id_246 { 0 };
      ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_247 { (*p_0).recipient };
      uint16_t id_248 { uint16_t(id_247.index()) };
      bool id_249 { bool(id_246 == id_248) };
      Size choose_res_250;
      if (id_249) {
        Size id_251 { 2UL };
        Size id_252 { Size(sz_185 + id_251) };
        auto fun253 { dessser::gen::file_path::sersize_of_row_binary };
        ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_254 { (*p_0).recipient };
        dessser::gen::file_path::t_ext id_255 { std::get<0 /* RingBuf */>(id_254) };
        Size id_256 { fun253(id_255) };
        Size id_257 { Size(id_252 + id_256) };
        choose_res_250 = id_257;
      } else {
        ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_258 { (*p_0).recipient };
        uint16_t id_259 { uint16_t(id_258.index()) };
        uint16_t id_260 { 1 };
        bool id_261 { bool(id_259 == id_260) };
        Void id_262 { ((void)(assert(id_261)), VOID) };
        (void)id_262;
        Size id_263 { 2UL };
        Size id_264 { Size(sz_185 + id_263) };
        auto fun265 { dessser::gen::sync_key::sersize_of_row_binary };
        ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_266 { (*p_0).recipient };
        dessser::gen::sync_key::t_ext id_267 { std::get<1 /* SyncKey */>(id_266) };
        Size id_268 { fun265(id_267) };
        Size id_269 { Size(id_264 + id_268) };
        choose_res_250 = id_269;
      }
      let_res_245 = choose_res_250;
    }
    Size let_res_270;
    {
      Size sz_187 { let_res_245 };
      Arr<dessser::gen::fq_function_name::t_ext> id_271 { (*p_0).sources };
      uint32_t id_272 { id_271.size() };
      Vec<1, uint32_t> id_273 {  id_272  };
      Size let_res_274;
      {
        Vec<1, uint32_t> n_ref_188 { id_273 };
        uint32_t id_275 { 1U };
        Vec<1, uint32_t> id_276 {  id_275  };
        Size let_res_277;
        {
          Vec<1, uint32_t> lebsz_ref_189 { id_276 };
          bool while_flag_278 { true };
          do {
            uint8_t id_279 { 0 };
            uint32_t id_280 { n_ref_188[id_279] };
            uint8_t id_281 { 0 };
            uint32_t id_282 { lebsz_ref_189[id_281] };
            uint8_t id_283 { 7 };
            uint32_t id_284 { uint32_t(id_282 << id_283) };
            bool id_285 { bool(id_280 >= id_284) };
            while_flag_278 = id_285;
            if (while_flag_278) {
              uint8_t id_286 { 0 };
              uint8_t id_287 { 0 };
              uint32_t id_288 { lebsz_ref_189[id_287] };
              uint32_t id_289 { 1U };
              uint32_t id_290 { uint32_t(id_288 + id_289) };
              Void id_291 { ((void)(lebsz_ref_189[id_286] = id_290), VOID) };
              (void)id_291;
            }
          } while (while_flag_278);
          (void)VOID;
          uint8_t id_292 { 0 };
          uint32_t id_293 { lebsz_ref_189[id_292] };
          Size id_294 { Size(id_293) };
          let_res_277 = id_294;
        }
        let_res_274 = let_res_277;
      }
      Size id_295 { Size(sz_187 + let_res_274) };
      Vec<1, Size> id_296 {  id_295  };
      Size let_res_297;
      {
        Vec<1, Size> sz_ref_190 { id_296 };
        int32_t id_298 { 0L };
        Vec<1, int32_t> id_299 {  id_298  };
        {
          Vec<1, int32_t> repeat_n_191 { id_299 };
          bool while_flag_300 { true };
          do {
            Arr<dessser::gen::fq_function_name::t_ext> id_301 { (*p_0).sources };
            uint32_t id_302 { id_301.size() };
            int32_t id_303 { int32_t(id_302) };
            uint8_t id_304 { 0 };
            int32_t id_305 { repeat_n_191[id_304] };
            bool id_306 { bool(id_303 > id_305) };
            while_flag_300 = id_306;
            if (while_flag_300) {
              uint8_t id_307 { 0 };
              uint8_t id_308 { 0 };
              Size id_309 { sz_ref_190[id_308] };
              auto fun310 { dessser::gen::fq_function_name::sersize_of_row_binary };
              uint8_t id_311 { 0 };
              int32_t id_312 { repeat_n_191[id_311] };
              Arr<dessser::gen::fq_function_name::t_ext> id_313 { (*p_0).sources };
              dessser::gen::fq_function_name::t_ext id_314 { id_313[id_312] };
              Size id_315 { fun310(id_314) };
              Size id_316 { Size(id_309 + id_315) };
              Void id_317 { ((void)(sz_ref_190[id_307] = id_316), VOID) };
              (void)id_317;
              uint8_t id_318 { 0 };
              uint8_t id_319 { 0 };
              int32_t id_320 { repeat_n_191[id_319] };
              int32_t id_321 { 1L };
              int32_t id_322 { int32_t(id_320 + id_321) };
              Void id_323 { ((void)(repeat_n_191[id_318] = id_322), VOID) };
              (void)id_323;
              (void)id_323;
            }
          } while (while_flag_300);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_324 { 0 };
        Size id_325 { sz_ref_190[id_324] };
        let_res_297 = id_325;
      }
      let_res_270 = let_res_297;
    }
    Size let_res_326;
    {
      Size sz_192 { let_res_270 };
      Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> id_327 { (*p_0).links };
      uint32_t id_328 { id_327.size() };
      Vec<1, uint32_t> id_329 {  id_328  };
      Size let_res_330;
      {
        Vec<1, uint32_t> n_ref_193 { id_329 };
        uint32_t id_331 { 1U };
        Vec<1, uint32_t> id_332 {  id_331  };
        Size let_res_333;
        {
          Vec<1, uint32_t> lebsz_ref_194 { id_332 };
          bool while_flag_334 { true };
          do {
            uint8_t id_335 { 0 };
            uint32_t id_336 { n_ref_193[id_335] };
            uint8_t id_337 { 0 };
            uint32_t id_338 { lebsz_ref_194[id_337] };
            uint8_t id_339 { 7 };
            uint32_t id_340 { uint32_t(id_338 << id_339) };
            bool id_341 { bool(id_336 >= id_340) };
            while_flag_334 = id_341;
            if (while_flag_334) {
              uint8_t id_342 { 0 };
              uint8_t id_343 { 0 };
              uint32_t id_344 { lebsz_ref_194[id_343] };
              uint32_t id_345 { 1U };
              uint32_t id_346 { uint32_t(id_344 + id_345) };
              Void id_347 { ((void)(lebsz_ref_194[id_342] = id_346), VOID) };
              (void)id_347;
            }
          } while (while_flag_334);
          (void)VOID;
          uint8_t id_348 { 0 };
          uint32_t id_349 { lebsz_ref_194[id_348] };
          Size id_350 { Size(id_349) };
          let_res_333 = id_350;
        }
        let_res_330 = let_res_333;
      }
      Size id_351 { Size(sz_192 + let_res_330) };
      Vec<1, Size> id_352 {  id_351  };
      Size let_res_353;
      {
        Vec<1, Size> sz_ref_195 { id_352 };
        int32_t id_354 { 0L };
        Vec<1, int32_t> id_355 {  id_354  };
        {
          Vec<1, int32_t> repeat_n_196 { id_355 };
          bool while_flag_356 { true };
          do {
            Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> id_357 { (*p_0).links };
            uint32_t id_358 { id_357.size() };
            int32_t id_359 { int32_t(id_358) };
            uint8_t id_360 { 0 };
            int32_t id_361 { repeat_n_196[id_360] };
            bool id_362 { bool(id_359 > id_361) };
            while_flag_356 = id_362;
            if (while_flag_356) {
              uint8_t id_363 { 0 };
              uint8_t id_364 { 0 };
              Size id_365 { sz_ref_195[id_364] };
              Size let_res_366;
              {
                Size sz_197 { id_365 };
                auto fun367 { dessser::gen::fq_function_name::sersize_of_row_binary };
                uint8_t id_368 { 0 };
                int32_t id_369 { repeat_n_196[id_368] };
                Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> id_370 { (*p_0).links };
                ::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290 id_371 { id_370[id_369] };
                dessser::gen::fq_function_name::t_ext id_372 { std::get<0>(id_371) };
                Size id_373 { fun367(id_372) };
                Size id_374 { Size(sz_197 + id_373) };
                let_res_366 = id_374;
              }
              Size let_res_375;
              {
                Size sz_198 { let_res_366 };
                auto fun376 { dessser::gen::fq_function_name::sersize_of_row_binary };
                uint8_t id_377 { 0 };
                int32_t id_378 { repeat_n_196[id_377] };
                Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> id_379 { (*p_0).links };
                ::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290 id_380 { id_379[id_378] };
                dessser::gen::fq_function_name::t_ext id_381 { std::get<1>(id_380) };
                Size id_382 { fun376(id_381) };
                Size id_383 { Size(sz_198 + id_382) };
                let_res_375 = id_383;
              }
              Void id_384 { ((void)(sz_ref_195[id_363] = let_res_375), VOID) };
              (void)id_384;
              uint8_t id_385 { 0 };
              uint8_t id_386 { 0 };
              int32_t id_387 { repeat_n_196[id_386] };
              int32_t id_388 { 1L };
              int32_t id_389 { int32_t(id_387 + id_388) };
              Void id_390 { ((void)(repeat_n_196[id_385] = id_389), VOID) };
              (void)id_390;
              (void)id_390;
            }
          } while (while_flag_356);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_391 { 0 };
        Size id_392 { sz_ref_195[id_391] };
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
std::function<Size(std::shared_ptr<::dessser::gen::replay::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_59" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
          (let "drec_62" (apply (ext-identifier fq_function_name of-row-binary) (identifier "drec_snd_61"))
            (let-pair "drec_fst_63" "drec_snd_64" (identifier "drec_62")
              (let "drec_77"
                (let "dstring1_71"
                  (let "leb_ref_65" (make-vec (u32 0))
                    (let "shft_ref_66" (make-vec (u8 0))
                      (let "p_ref_67" (make-vec (identifier "drec_snd_64"))
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
                  (let "drec_83" (let-pair "dfloat_fst_81" "dfloat_snd_82" (read-u64 little-endian (identifier "drec_snd_79")) (make-tup (float-of-u64 (identifier "dfloat_fst_81")) (identifier "dfloat_snd_82")))
                    (let-pair "drec_fst_84" "drec_snd_85" (identifier "drec_83")
                      (let "drec_89" (let-pair "dfloat_fst_87" "dfloat_snd_88" (read-u64 little-endian (identifier "drec_snd_85")) (make-tup (float-of-u64 (identifier "dfloat_fst_87")) (identifier "dfloat_snd_88")))
                        (let-pair "drec_fst_90" "drec_snd_91" (identifier "drec_89")
                          (let "drec_107"
                            (let "dsum1_98" (let-pair "du16_fst_93" "du16_snd_94" (read-u16 little-endian (identifier "drec_snd_91")) (make-tup (identifier "du16_fst_93") (identifier "du16_snd_94")))
                              (let-pair "dsum1_fst_99" "dsum1_snd_100" 
                                (identifier "dsum1_98")
                                (if (eq (u16 0) (identifier "dsum1_fst_99"))
                                  (let-pair "dsum2_fst_105" "dsum2_snd_106" 
                                    (apply (ext-identifier file_path of-row-binary) (identifier "dsum1_snd_100"))
                                    (make-tup (construct "[RingBuf $file_path | SyncKey $sync_key]" 0 (identifier "dsum2_fst_105")) (identifier "dsum2_snd_106")))
                                  (seq (assert (eq (identifier "dsum1_fst_99") (u16 1)))
                                    (let-pair "dsum2_fst_102" "dsum2_snd_103" 
                                      (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_100"))
                                      (make-tup (construct "[RingBuf $file_path | SyncKey $sync_key]" 1 (identifier "dsum2_fst_102")) (identifier "dsum2_snd_103")))))))
                            (let-pair "drec_fst_108" "drec_snd_109" (identifier "drec_107")
                              (let "drec_133"
                                (let-pair "dlist4_fst_131" "dlist4_snd_132"
                                  (let "dlist1_119"
                                    (let "leb_ref_110" (make-vec (u32 0))
                                      (let "shft_ref_111" (make-vec (u8 0))
                                        (let "p_ref_112" (make-vec (identifier "drec_snd_109"))
                                          (seq
                                            (while
                                              (let "leb128_113" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_112")))
                                                (let-pair "leb128_fst_114" "leb128_snd_115" 
                                                  (identifier "leb128_113")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_112") (identifier "leb128_snd_115"))
                                                    (set-vec (u8 0) (identifier "leb_ref_110")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_114") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_111"))) (unsafe-nth (u8 0) (identifier "leb_ref_110"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_111") (add (unsafe-nth (u8 0) (identifier "shft_ref_111")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_114") (u8 128))))) 
                                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_110")) (unsafe-nth (u8 0) (identifier "p_ref_112")))))))
                                    (let-pair "dlist1_fst_120" "dlist1_snd_121" 
                                      (identifier "dlist1_119")
                                      (let "inits_src_ref_122" (make-vec (make-tup (end-of-list "$fq_function_name") (identifier "dlist1_snd_121")))
                                        (seq
                                          (let "repeat_n_123" (make-vec (i32 0))
                                            (while (gt (to-i32 (identifier "dlist1_fst_120")) (unsafe-nth (u8 0) (identifier "repeat_n_123")))
                                              (seq
                                                (let "dlist2_124" (unsafe-nth (u8 0) (identifier "inits_src_ref_122"))
                                                  (let-pair "dlist2_fst_125" "dlist2_snd_126" 
                                                    (identifier "dlist2_124")
                                                    (set-vec (u8 0) (identifier "inits_src_ref_122")
                                                      (let-pair "dlist3_fst_128" "dlist3_snd_129" 
                                                        (apply (ext-identifier fq_function_name of-row-binary) (identifier "dlist2_snd_126"))
                                                        (make-tup (cons (identifier "dlist3_fst_128") (identifier "dlist2_fst_125")) (identifier "dlist3_snd_129"))))))
                                                (set-vec (u8 0) (identifier "repeat_n_123") (add (unsafe-nth (u8 0) (identifier "repeat_n_123")) (i32 1)))))) 
                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_122")))))) 
                                  (make-tup (arr-of-lst-rev (identifier "dlist4_fst_131")) (identifier "dlist4_snd_132")))
                                (let-pair "drec_fst_134" "drec_snd_135" 
                                  (identifier "drec_133")
                                  (let "drec_165"
                                    (let-pair "dlist4_fst_163" "dlist4_snd_164"
                                      (let "dlist1_145"
                                        (let "leb_ref_136" (make-vec (u32 0))
                                          (let "shft_ref_137" (make-vec (u8 0))
                                            (let "p_ref_138" (make-vec (identifier "drec_snd_135"))
                                              (seq
                                                (while
                                                  (let "leb128_139" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_138")))
                                                    (let-pair "leb128_fst_140" "leb128_snd_141" 
                                                      (identifier "leb128_139")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_138") (identifier "leb128_snd_141"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_136")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_140") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_137")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_136")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_137") (add (unsafe-nth (u8 0) (identifier "shft_ref_137")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_140") (u8 128))))) 
                                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_136")) (unsafe-nth (u8 0) (identifier "p_ref_138")))))))
                                        (let-pair "dlist1_fst_146" "dlist1_snd_147" 
                                          (identifier "dlist1_145")
                                          (let "inits_src_ref_148" (make-vec (make-tup (end-of-list "($fq_function_name; $fq_function_name)") (identifier "dlist1_snd_147")))
                                            (seq
                                              (let "repeat_n_149" (make-vec (i32 0))
                                                (while (gt (to-i32 (identifier "dlist1_fst_146")) (unsafe-nth (u8 0) (identifier "repeat_n_149")))
                                                  (seq
                                                    (let "dlist2_150" 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_148"))
                                                      (let-pair "dlist2_fst_151" "dlist2_snd_152" 
                                                        (identifier "dlist2_150")
                                                        (set-vec (u8 0) 
                                                          (identifier "inits_src_ref_148")
                                                          (let "dtup_153" 
                                                            (apply (ext-identifier fq_function_name of-row-binary) (identifier "dlist2_snd_152"))
                                                            (let-pair "dtup_fst_154" "dtup_snd_155" 
                                                              (identifier "dtup_153")
                                                              (let-pair "dtup_fst_157" "dtup_snd_158" 
                                                                (apply (ext-identifier fq_function_name of-row-binary) (identifier "dtup_snd_155"))
                                                                (make-tup (cons (make-tup (identifier "dtup_fst_154") (identifier "dtup_fst_157")) (identifier "dlist2_fst_151")) (identifier "dtup_snd_158"))))))))
                                                    (set-vec (u8 0) (identifier "repeat_n_149") (add (unsafe-nth (u8 0) (identifier "repeat_n_149")) (i32 1)))))) 
                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_148")))))) 
                                      (make-tup (arr-of-lst-rev (identifier "dlist4_fst_163")) (identifier "dlist4_snd_164")))
                                    (let-pair "drec_fst_166" "drec_snd_167" 
                                      (identifier "drec_165")
                                      (let-pair "dfloat_fst_169" "dfloat_snd_170" 
                                        (read-u64 little-endian (identifier "drec_snd_167"))
                                        (make-tup
                                          (make-rec (string "timeout_date") 
                                            (float-of-u64 (identifier "dfloat_fst_169")) 
                                            (string "links") (identifier "drec_fst_166") 
                                            (string "sources") (identifier "drec_fst_134") 
                                            (string "recipient") (identifier "drec_fst_108") 
                                            (string "until") (identifier "drec_fst_90") 
                                            (string "since") (identifier "drec_fst_84") 
                                            (string "target_fieldmask") 
                                            (identifier "drec_fst_78") 
                                            (string "target") (identifier "drec_fst_63") 
                                            (string "channel") (identifier "drec_fst_60")) 
                                          (identifier "dfloat_snd_170"))))))))))))))))))))
 */
static std::function<::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85(Pointer)> fun395 { [&fun395](Pointer p_0) {
    ::dessser::gen::replay::t7609d344c1ba69d0f80fec236d4c216b id_396 { p_0.readU16Le() };
    ::dessser::gen::replay::t7609d344c1ba69d0f80fec236d4c216b letpair_res_397;
    {
      auto du16_fst_57 { std::get<0>(id_396) };
      auto du16_snd_58 { std::get<1>(id_396) };
      ::dessser::gen::replay::t7609d344c1ba69d0f80fec236d4c216b id_398 { du16_fst_57, du16_snd_58 };
      letpair_res_397 = id_398;
    }
    ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 let_res_399;
    {
      ::dessser::gen::replay::t7609d344c1ba69d0f80fec236d4c216b drec_59 { letpair_res_397 };
      ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 letpair_res_400;
      {
        auto drec_fst_60 { std::get<0>(drec_59) };
        auto drec_snd_61 { std::get<1>(drec_59) };
        auto fun401 { dessser::gen::fq_function_name::of_row_binary };
        ::dessser::gen::replay::tc67a116b5bcd191e2624b1f2b2b1794a id_402 { fun401(drec_snd_61) };
        ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 let_res_403;
        {
          ::dessser::gen::replay::tc67a116b5bcd191e2624b1f2b2b1794a drec_62 { id_402 };
          ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 letpair_res_404;
          {
            auto drec_fst_63 { std::get<0>(drec_62) };
            auto drec_snd_64 { std::get<1>(drec_62) };
            uint32_t id_405 { 0U };
            Vec<1, uint32_t> id_406 {  id_405  };
            ::dessser::gen::replay::t044960e524fd6ec1bfc06410ce526709 let_res_407;
            {
              Vec<1, uint32_t> leb_ref_65 { id_406 };
              uint8_t id_408 { 0 };
              Vec<1, uint8_t> id_409 {  id_408  };
              ::dessser::gen::replay::t044960e524fd6ec1bfc06410ce526709 let_res_410;
              {
                Vec<1, uint8_t> shft_ref_66 { id_409 };
                Vec<1, Pointer> id_411 {  drec_snd_64  };
                ::dessser::gen::replay::t044960e524fd6ec1bfc06410ce526709 let_res_412;
                {
                  Vec<1, Pointer> p_ref_67 { id_411 };
                  bool while_flag_413 { true };
                  do {
                    uint8_t id_414 { 0 };
                    Pointer id_415 { p_ref_67[id_414] };
                    ::dessser::gen::replay::t1566bd611d8a2b90669c241f5e8d6ff1 id_416 { id_415.readU8() };
                    bool let_res_417;
                    {
                      ::dessser::gen::replay::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_68 { id_416 };
                      bool letpair_res_418;
                      {
                        auto leb128_fst_69 { std::get<0>(leb128_68) };
                        auto leb128_snd_70 { std::get<1>(leb128_68) };
                        uint8_t id_419 { 0 };
                        Void id_420 { ((void)(p_ref_67[id_419] = leb128_snd_70), VOID) };
                        (void)id_420;
                        uint8_t id_421 { 0 };
                        uint8_t id_422 { 127 };
                        uint8_t id_423 { uint8_t(leb128_fst_69 & id_422) };
                        uint32_t id_424 { uint32_t(id_423) };
                        uint8_t id_425 { 0 };
                        uint8_t id_426 { shft_ref_66[id_425] };
                        uint32_t id_427 { uint32_t(id_424 << id_426) };
                        uint8_t id_428 { 0 };
                        uint32_t id_429 { leb_ref_65[id_428] };
                        uint32_t id_430 { uint32_t(id_427 | id_429) };
                        Void id_431 { ((void)(leb_ref_65[id_421] = id_430), VOID) };
                        (void)id_431;
                        uint8_t id_432 { 0 };
                        uint8_t id_433 { 0 };
                        uint8_t id_434 { shft_ref_66[id_433] };
                        uint8_t id_435 { 7 };
                        uint8_t id_436 { uint8_t(id_434 + id_435) };
                        Void id_437 { ((void)(shft_ref_66[id_432] = id_436), VOID) };
                        (void)id_437;
                        uint8_t id_438 { 128 };
                        bool id_439 { bool(leb128_fst_69 >= id_438) };
                        letpair_res_418 = id_439;
                      }
                      let_res_417 = letpair_res_418;
                    }
                    while_flag_413 = let_res_417;
                    if (while_flag_413) {
                      (void)VOID;
                    }
                  } while (while_flag_413);
                  (void)VOID;
                  uint8_t id_440 { 0 };
                  uint32_t id_441 { leb_ref_65[id_440] };
                  Size id_442 { Size(id_441) };
                  uint8_t id_443 { 0 };
                  Pointer id_444 { p_ref_67[id_443] };
                  ::dessser::gen::replay::t044960e524fd6ec1bfc06410ce526709 id_445 { id_442, id_444 };
                  let_res_412 = id_445;
                }
                let_res_410 = let_res_412;
              }
              let_res_407 = let_res_410;
            }
            ::dessser::gen::replay::t3fd8221434e489b54b5c4356ebff5005 let_res_446;
            {
              ::dessser::gen::replay::t044960e524fd6ec1bfc06410ce526709 dstring1_71 { let_res_407 };
              ::dessser::gen::replay::t3fd8221434e489b54b5c4356ebff5005 letpair_res_447;
              {
                auto dstring1_fst_72 { std::get<0>(dstring1_71) };
                auto dstring1_snd_73 { std::get<1>(dstring1_71) };
                ::dessser::gen::replay::t5887709cc43c8c8e24d28211e8c970a2 id_448 { dstring1_snd_73.readBytes(dstring1_fst_72) };
                ::dessser::gen::replay::t3fd8221434e489b54b5c4356ebff5005 letpair_res_449;
                {
                  auto dstring2_fst_75 { std::get<0>(id_448) };
                  auto dstring2_snd_76 { std::get<1>(id_448) };
                  std::string id_450 { dstring2_fst_75.toString() };
                  ::dessser::gen::replay::t3fd8221434e489b54b5c4356ebff5005 id_451 { id_450, dstring2_snd_76 };
                  letpair_res_449 = id_451;
                }
                letpair_res_447 = letpair_res_449;
              }
              let_res_446 = letpair_res_447;
            }
            ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 let_res_452;
            {
              ::dessser::gen::replay::t3fd8221434e489b54b5c4356ebff5005 drec_77 { let_res_446 };
              ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 letpair_res_453;
              {
                auto drec_fst_78 { std::get<0>(drec_77) };
                auto drec_snd_79 { std::get<1>(drec_77) };
                ::dessser::gen::replay::tf568409f41c9c0a265f7302110fc9084 id_454 { drec_snd_79.readU64Le() };
                ::dessser::gen::replay::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_455;
                {
                  auto dfloat_fst_81 { std::get<0>(id_454) };
                  auto dfloat_snd_82 { std::get<1>(id_454) };
                  double id_456 { float_of_qword(dfloat_fst_81) };
                  ::dessser::gen::replay::t5375de390f9cb5ae2ee5880ea1674828 id_457 { id_456, dfloat_snd_82 };
                  letpair_res_455 = id_457;
                }
                ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 let_res_458;
                {
                  ::dessser::gen::replay::t5375de390f9cb5ae2ee5880ea1674828 drec_83 { letpair_res_455 };
                  ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 letpair_res_459;
                  {
                    auto drec_fst_84 { std::get<0>(drec_83) };
                    auto drec_snd_85 { std::get<1>(drec_83) };
                    ::dessser::gen::replay::tf568409f41c9c0a265f7302110fc9084 id_460 { drec_snd_85.readU64Le() };
                    ::dessser::gen::replay::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_461;
                    {
                      auto dfloat_fst_87 { std::get<0>(id_460) };
                      auto dfloat_snd_88 { std::get<1>(id_460) };
                      double id_462 { float_of_qword(dfloat_fst_87) };
                      ::dessser::gen::replay::t5375de390f9cb5ae2ee5880ea1674828 id_463 { id_462, dfloat_snd_88 };
                      letpair_res_461 = id_463;
                    }
                    ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 let_res_464;
                    {
                      ::dessser::gen::replay::t5375de390f9cb5ae2ee5880ea1674828 drec_89 { letpair_res_461 };
                      ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 letpair_res_465;
                      {
                        auto drec_fst_90 { std::get<0>(drec_89) };
                        auto drec_snd_91 { std::get<1>(drec_89) };
                        ::dessser::gen::replay::t7609d344c1ba69d0f80fec236d4c216b id_466 { drec_snd_91.readU16Le() };
                        ::dessser::gen::replay::t7609d344c1ba69d0f80fec236d4c216b letpair_res_467;
                        {
                          auto du16_fst_93 { std::get<0>(id_466) };
                          auto du16_snd_94 { std::get<1>(id_466) };
                          ::dessser::gen::replay::t7609d344c1ba69d0f80fec236d4c216b id_468 { du16_fst_93, du16_snd_94 };
                          letpair_res_467 = id_468;
                        }
                        ::dessser::gen::replay::tf8bffbf00e9517eec4d771eb352fa990 let_res_469;
                        {
                          ::dessser::gen::replay::t7609d344c1ba69d0f80fec236d4c216b dsum1_98 { letpair_res_467 };
                          ::dessser::gen::replay::tf8bffbf00e9517eec4d771eb352fa990 letpair_res_470;
                          {
                            auto dsum1_fst_99 { std::get<0>(dsum1_98) };
                            auto dsum1_snd_100 { std::get<1>(dsum1_98) };
                            uint16_t id_471 { 0 };
                            bool id_472 { bool(id_471 == dsum1_fst_99) };
                            ::dessser::gen::replay::tf8bffbf00e9517eec4d771eb352fa990 choose_res_473;
                            if (id_472) {
                              auto fun474 { dessser::gen::file_path::of_row_binary };
                              ::dessser::gen::replay::tb06ffbf6da2300d8f0de21eea734e5f2 id_475 { fun474(dsum1_snd_100) };
                              ::dessser::gen::replay::tf8bffbf00e9517eec4d771eb352fa990 letpair_res_476;
                              {
                                auto dsum2_fst_105 { std::get<0>(id_475) };
                                auto dsum2_snd_106 { std::get<1>(id_475) };
                                ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_477 { std::in_place_index<0>, dsum2_fst_105 };
                                ::dessser::gen::replay::tf8bffbf00e9517eec4d771eb352fa990 id_478 { id_477, dsum2_snd_106 };
                                letpair_res_476 = id_478;
                              }
                              choose_res_473 = letpair_res_476;
                            } else {
                              uint16_t id_479 { 1 };
                              bool id_480 { bool(dsum1_fst_99 == id_479) };
                              Void id_481 { ((void)(assert(id_480)), VOID) };
                              (void)id_481;
                              auto fun482 { dessser::gen::sync_key::of_row_binary };
                              ::dessser::gen::replay::t9bda35a83af38220b883fe5d84e6ed9f id_483 { fun482(dsum1_snd_100) };
                              ::dessser::gen::replay::tf8bffbf00e9517eec4d771eb352fa990 letpair_res_484;
                              {
                                auto dsum2_fst_102 { std::get<0>(id_483) };
                                auto dsum2_snd_103 { std::get<1>(id_483) };
                                ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 id_485 { std::in_place_index<1>, dsum2_fst_102 };
                                ::dessser::gen::replay::tf8bffbf00e9517eec4d771eb352fa990 id_486 { id_485, dsum2_snd_103 };
                                letpair_res_484 = id_486;
                              }
                              choose_res_473 = letpair_res_484;
                            }
                            letpair_res_470 = choose_res_473;
                          }
                          let_res_469 = letpair_res_470;
                        }
                        ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 let_res_487;
                        {
                          ::dessser::gen::replay::tf8bffbf00e9517eec4d771eb352fa990 drec_107 { let_res_469 };
                          ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 letpair_res_488;
                          {
                            auto drec_fst_108 { std::get<0>(drec_107) };
                            auto drec_snd_109 { std::get<1>(drec_107) };
                            uint32_t id_489 { 0U };
                            Vec<1, uint32_t> id_490 {  id_489  };
                            ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 let_res_491;
                            {
                              Vec<1, uint32_t> leb_ref_110 { id_490 };
                              uint8_t id_492 { 0 };
                              Vec<1, uint8_t> id_493 {  id_492  };
                              ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 let_res_494;
                              {
                                Vec<1, uint8_t> shft_ref_111 { id_493 };
                                Vec<1, Pointer> id_495 {  drec_snd_109  };
                                ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 let_res_496;
                                {
                                  Vec<1, Pointer> p_ref_112 { id_495 };
                                  bool while_flag_497 { true };
                                  do {
                                    uint8_t id_498 { 0 };
                                    Pointer id_499 { p_ref_112[id_498] };
                                    ::dessser::gen::replay::t1566bd611d8a2b90669c241f5e8d6ff1 id_500 { id_499.readU8() };
                                    bool let_res_501;
                                    {
                                      ::dessser::gen::replay::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_113 { id_500 };
                                      bool letpair_res_502;
                                      {
                                        auto leb128_fst_114 { std::get<0>(leb128_113) };
                                        auto leb128_snd_115 { std::get<1>(leb128_113) };
                                        uint8_t id_503 { 0 };
                                        Void id_504 { ((void)(p_ref_112[id_503] = leb128_snd_115), VOID) };
                                        (void)id_504;
                                        uint8_t id_505 { 0 };
                                        uint8_t id_506 { 127 };
                                        uint8_t id_507 { uint8_t(leb128_fst_114 & id_506) };
                                        uint32_t id_508 { uint32_t(id_507) };
                                        uint8_t id_509 { 0 };
                                        uint8_t id_510 { shft_ref_111[id_509] };
                                        uint32_t id_511 { uint32_t(id_508 << id_510) };
                                        uint8_t id_512 { 0 };
                                        uint32_t id_513 { leb_ref_110[id_512] };
                                        uint32_t id_514 { uint32_t(id_511 | id_513) };
                                        Void id_515 { ((void)(leb_ref_110[id_505] = id_514), VOID) };
                                        (void)id_515;
                                        uint8_t id_516 { 0 };
                                        uint8_t id_517 { 0 };
                                        uint8_t id_518 { shft_ref_111[id_517] };
                                        uint8_t id_519 { 7 };
                                        uint8_t id_520 { uint8_t(id_518 + id_519) };
                                        Void id_521 { ((void)(shft_ref_111[id_516] = id_520), VOID) };
                                        (void)id_521;
                                        uint8_t id_522 { 128 };
                                        bool id_523 { bool(leb128_fst_114 >= id_522) };
                                        letpair_res_502 = id_523;
                                      }
                                      let_res_501 = letpair_res_502;
                                    }
                                    while_flag_497 = let_res_501;
                                    if (while_flag_497) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_497);
                                  (void)VOID;
                                  uint8_t id_524 { 0 };
                                  uint32_t id_525 { leb_ref_110[id_524] };
                                  uint8_t id_526 { 0 };
                                  Pointer id_527 { p_ref_112[id_526] };
                                  ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 id_528 { id_525, id_527 };
                                  let_res_496 = id_528;
                                }
                                let_res_494 = let_res_496;
                              }
                              let_res_491 = let_res_494;
                            }
                            ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314 let_res_529;
                            {
                              ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 dlist1_119 { let_res_491 };
                              ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314 letpair_res_530;
                              {
                                auto dlist1_fst_120 { std::get<0>(dlist1_119) };
                                auto dlist1_snd_121 { std::get<1>(dlist1_119) };
                                Lst<dessser::gen::fq_function_name::t_ext> endoflist_531;
                                ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314 id_532 { endoflist_531, dlist1_snd_121 };
                                Vec<1, ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314> id_533 {  id_532  };
                                ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314 let_res_534;
                                {
                                  Vec<1, ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314> inits_src_ref_122 { id_533 };
                                  int32_t id_535 { 0L };
                                  Vec<1, int32_t> id_536 {  id_535  };
                                  {
                                    Vec<1, int32_t> repeat_n_123 { id_536 };
                                    bool while_flag_537 { true };
                                    do {
                                      int32_t id_538 { int32_t(dlist1_fst_120) };
                                      uint8_t id_539 { 0 };
                                      int32_t id_540 { repeat_n_123[id_539] };
                                      bool id_541 { bool(id_538 > id_540) };
                                      while_flag_537 = id_541;
                                      if (while_flag_537) {
                                        uint8_t id_542 { 0 };
                                        ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314 id_543 { inits_src_ref_122[id_542] };
                                        {
                                          ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314 dlist2_124 { id_543 };
                                          {
                                            auto dlist2_fst_125 { std::get<0>(dlist2_124) };
                                            auto dlist2_snd_126 { std::get<1>(dlist2_124) };
                                            uint8_t id_544 { 0 };
                                            auto fun545 { dessser::gen::fq_function_name::of_row_binary };
                                            ::dessser::gen::replay::tc67a116b5bcd191e2624b1f2b2b1794a id_546 { fun545(dlist2_snd_126) };
                                            ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314 letpair_res_547;
                                            {
                                              auto dlist3_fst_128 { std::get<0>(id_546) };
                                              auto dlist3_snd_129 { std::get<1>(id_546) };
                                              Lst<dessser::gen::fq_function_name::t_ext> id_548 { dlist3_fst_128, dlist2_fst_125 };
                                              ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314 id_549 { id_548, dlist3_snd_129 };
                                              letpair_res_547 = id_549;
                                            }
                                            Void id_550 { ((void)(inits_src_ref_122[id_544] = letpair_res_547), VOID) };
                                            (void)id_550;
                                          }
                                          (void)VOID;
                                        }
                                        (void)VOID;
                                        uint8_t id_551 { 0 };
                                        uint8_t id_552 { 0 };
                                        int32_t id_553 { repeat_n_123[id_552] };
                                        int32_t id_554 { 1L };
                                        int32_t id_555 { int32_t(id_553 + id_554) };
                                        Void id_556 { ((void)(repeat_n_123[id_551] = id_555), VOID) };
                                        (void)id_556;
                                        (void)id_556;
                                      }
                                    } while (while_flag_537);
                                    (void)VOID;
                                  }
                                  (void)VOID;
                                  uint8_t id_557 { 0 };
                                  ::dessser::gen::replay::t224e407810f4c01679f3bd319cbc6314 id_558 { inits_src_ref_122[id_557] };
                                  let_res_534 = id_558;
                                }
                                letpair_res_530 = let_res_534;
                              }
                              let_res_529 = letpair_res_530;
                            }
                            ::dessser::gen::replay::t5b49e5a21d5a9df016dd7fe81e264a61 letpair_res_559;
                            {
                              auto dlist4_fst_131 { std::get<0>(let_res_529) };
                              auto dlist4_snd_132 { std::get<1>(let_res_529) };
                              Arr<dessser::gen::fq_function_name::t_ext> id_560 { dlist4_fst_131.toListRev() };
                              ::dessser::gen::replay::t5b49e5a21d5a9df016dd7fe81e264a61 id_561 { id_560, dlist4_snd_132 };
                              letpair_res_559 = id_561;
                            }
                            ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 let_res_562;
                            {
                              ::dessser::gen::replay::t5b49e5a21d5a9df016dd7fe81e264a61 drec_133 { letpair_res_559 };
                              ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 letpair_res_563;
                              {
                                auto drec_fst_134 { std::get<0>(drec_133) };
                                auto drec_snd_135 { std::get<1>(drec_133) };
                                uint32_t id_564 { 0U };
                                Vec<1, uint32_t> id_565 {  id_564  };
                                ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 let_res_566;
                                {
                                  Vec<1, uint32_t> leb_ref_136 { id_565 };
                                  uint8_t id_567 { 0 };
                                  Vec<1, uint8_t> id_568 {  id_567  };
                                  ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 let_res_569;
                                  {
                                    Vec<1, uint8_t> shft_ref_137 { id_568 };
                                    Vec<1, Pointer> id_570 {  drec_snd_135  };
                                    ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 let_res_571;
                                    {
                                      Vec<1, Pointer> p_ref_138 { id_570 };
                                      bool while_flag_572 { true };
                                      do {
                                        uint8_t id_573 { 0 };
                                        Pointer id_574 { p_ref_138[id_573] };
                                        ::dessser::gen::replay::t1566bd611d8a2b90669c241f5e8d6ff1 id_575 { id_574.readU8() };
                                        bool let_res_576;
                                        {
                                          ::dessser::gen::replay::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_139 { id_575 };
                                          bool letpair_res_577;
                                          {
                                            auto leb128_fst_140 { std::get<0>(leb128_139) };
                                            auto leb128_snd_141 { std::get<1>(leb128_139) };
                                            uint8_t id_578 { 0 };
                                            Void id_579 { ((void)(p_ref_138[id_578] = leb128_snd_141), VOID) };
                                            (void)id_579;
                                            uint8_t id_580 { 0 };
                                            uint8_t id_581 { 127 };
                                            uint8_t id_582 { uint8_t(leb128_fst_140 & id_581) };
                                            uint32_t id_583 { uint32_t(id_582) };
                                            uint8_t id_584 { 0 };
                                            uint8_t id_585 { shft_ref_137[id_584] };
                                            uint32_t id_586 { uint32_t(id_583 << id_585) };
                                            uint8_t id_587 { 0 };
                                            uint32_t id_588 { leb_ref_136[id_587] };
                                            uint32_t id_589 { uint32_t(id_586 | id_588) };
                                            Void id_590 { ((void)(leb_ref_136[id_580] = id_589), VOID) };
                                            (void)id_590;
                                            uint8_t id_591 { 0 };
                                            uint8_t id_592 { 0 };
                                            uint8_t id_593 { shft_ref_137[id_592] };
                                            uint8_t id_594 { 7 };
                                            uint8_t id_595 { uint8_t(id_593 + id_594) };
                                            Void id_596 { ((void)(shft_ref_137[id_591] = id_595), VOID) };
                                            (void)id_596;
                                            uint8_t id_597 { 128 };
                                            bool id_598 { bool(leb128_fst_140 >= id_597) };
                                            letpair_res_577 = id_598;
                                          }
                                          let_res_576 = letpair_res_577;
                                        }
                                        while_flag_572 = let_res_576;
                                        if (while_flag_572) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_572);
                                      (void)VOID;
                                      uint8_t id_599 { 0 };
                                      uint32_t id_600 { leb_ref_136[id_599] };
                                      uint8_t id_601 { 0 };
                                      Pointer id_602 { p_ref_138[id_601] };
                                      ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 id_603 { id_600, id_602 };
                                      let_res_571 = id_603;
                                    }
                                    let_res_569 = let_res_571;
                                  }
                                  let_res_566 = let_res_569;
                                }
                                ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 let_res_604;
                                {
                                  ::dessser::gen::replay::t883c6ffea47c0d7b950fe35881e3d737 dlist1_145 { let_res_566 };
                                  ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 letpair_res_605;
                                  {
                                    auto dlist1_fst_146 { std::get<0>(dlist1_145) };
                                    auto dlist1_snd_147 { std::get<1>(dlist1_145) };
                                    Lst<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> endoflist_606;
                                    ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 id_607 { endoflist_606, dlist1_snd_147 };
                                    Vec<1, ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18> id_608 {  id_607  };
                                    ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 let_res_609;
                                    {
                                      Vec<1, ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18> inits_src_ref_148 { id_608 };
                                      int32_t id_610 { 0L };
                                      Vec<1, int32_t> id_611 {  id_610  };
                                      {
                                        Vec<1, int32_t> repeat_n_149 { id_611 };
                                        bool while_flag_612 { true };
                                        do {
                                          int32_t id_613 { int32_t(dlist1_fst_146) };
                                          uint8_t id_614 { 0 };
                                          int32_t id_615 { repeat_n_149[id_614] };
                                          bool id_616 { bool(id_613 > id_615) };
                                          while_flag_612 = id_616;
                                          if (while_flag_612) {
                                            uint8_t id_617 { 0 };
                                            ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 id_618 { inits_src_ref_148[id_617] };
                                            {
                                              ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 dlist2_150 { id_618 };
                                              {
                                                auto dlist2_fst_151 { std::get<0>(dlist2_150) };
                                                auto dlist2_snd_152 { std::get<1>(dlist2_150) };
                                                uint8_t id_619 { 0 };
                                                auto fun620 { dessser::gen::fq_function_name::of_row_binary };
                                                ::dessser::gen::replay::tc67a116b5bcd191e2624b1f2b2b1794a id_621 { fun620(dlist2_snd_152) };
                                                ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 let_res_622;
                                                {
                                                  ::dessser::gen::replay::tc67a116b5bcd191e2624b1f2b2b1794a dtup_153 { id_621 };
                                                  ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 letpair_res_623;
                                                  {
                                                    auto dtup_fst_154 { std::get<0>(dtup_153) };
                                                    auto dtup_snd_155 { std::get<1>(dtup_153) };
                                                    auto fun624 { dessser::gen::fq_function_name::of_row_binary };
                                                    ::dessser::gen::replay::tc67a116b5bcd191e2624b1f2b2b1794a id_625 { fun624(dtup_snd_155) };
                                                    ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 letpair_res_626;
                                                    {
                                                      auto dtup_fst_157 { std::get<0>(id_625) };
                                                      auto dtup_snd_158 { std::get<1>(id_625) };
                                                      ::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290 id_627 { dtup_fst_154, dtup_fst_157 };
                                                      Lst<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> id_628 { id_627, dlist2_fst_151 };
                                                      ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 id_629 { id_628, dtup_snd_158 };
                                                      letpair_res_626 = id_629;
                                                    }
                                                    letpair_res_623 = letpair_res_626;
                                                  }
                                                  let_res_622 = letpair_res_623;
                                                }
                                                Void id_630 { ((void)(inits_src_ref_148[id_619] = let_res_622), VOID) };
                                                (void)id_630;
                                              }
                                              (void)VOID;
                                            }
                                            (void)VOID;
                                            uint8_t id_631 { 0 };
                                            uint8_t id_632 { 0 };
                                            int32_t id_633 { repeat_n_149[id_632] };
                                            int32_t id_634 { 1L };
                                            int32_t id_635 { int32_t(id_633 + id_634) };
                                            Void id_636 { ((void)(repeat_n_149[id_631] = id_635), VOID) };
                                            (void)id_636;
                                            (void)id_636;
                                          }
                                        } while (while_flag_612);
                                        (void)VOID;
                                      }
                                      (void)VOID;
                                      uint8_t id_637 { 0 };
                                      ::dessser::gen::replay::t9955e139d945579b7b0b7f578d074e18 id_638 { inits_src_ref_148[id_637] };
                                      let_res_609 = id_638;
                                    }
                                    letpair_res_605 = let_res_609;
                                  }
                                  let_res_604 = letpair_res_605;
                                }
                                ::dessser::gen::replay::tc0f47151efbaf2e403a11655e44057c9 letpair_res_639;
                                {
                                  auto dlist4_fst_163 { std::get<0>(let_res_604) };
                                  auto dlist4_snd_164 { std::get<1>(let_res_604) };
                                  Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> id_640 { dlist4_fst_163.toListRev() };
                                  ::dessser::gen::replay::tc0f47151efbaf2e403a11655e44057c9 id_641 { id_640, dlist4_snd_164 };
                                  letpair_res_639 = id_641;
                                }
                                ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 let_res_642;
                                {
                                  ::dessser::gen::replay::tc0f47151efbaf2e403a11655e44057c9 drec_165 { letpair_res_639 };
                                  ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 letpair_res_643;
                                  {
                                    auto drec_fst_166 { std::get<0>(drec_165) };
                                    auto drec_snd_167 { std::get<1>(drec_165) };
                                    ::dessser::gen::replay::tf568409f41c9c0a265f7302110fc9084 id_644 { drec_snd_167.readU64Le() };
                                    ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 letpair_res_645;
                                    {
                                      auto dfloat_fst_169 { std::get<0>(id_644) };
                                      auto dfloat_snd_170 { std::get<1>(id_644) };
                                      double id_646 { float_of_qword(dfloat_fst_169) };
                                      std::shared_ptr<::dessser::gen::replay::t>  id_647 { std::make_shared<::dessser::gen::replay::t>(drec_fst_60, drec_fst_166, drec_fst_108, drec_fst_84, drec_fst_134, drec_fst_63, drec_fst_78, id_646, drec_fst_90) };
                                      ::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85 id_648 { id_647, dfloat_snd_170 };
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
std::function<::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85(Pointer)> of_row_binary(of_row_binary_init());

typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
